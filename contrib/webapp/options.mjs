// Gmsh web app - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// The Options tab: the pages of the option window of the FLTK graphical user
// interface (src/common/OptionPages.cpp), their entries bound to their options
// by name, the colour scheme of the page, and the tabs of the panel

import {$, gmsh} from './app.mjs';
import {web} from './gmshweb.mjs';
import {readClipping} from './clipping.mjs';
import {readPlugins} from './plugins.mjs';
import {recolorParameters} from './parameters.mjs';
import {draw} from './scene.mjs';
import {keepViewOption, settleViews, updateViews, viewNum, viewTags} from './views.mjs';
import {readVisibility} from './visibility.mjs';

// the pages of the option window (see gmshWebOptionPages() in webApp.cpp):
// the Options tab shows all but the one of the views, whose options are set
// under each view in the Post-processing module (see views.mjs); the options
// that change the mesh, those of the first two sections of the Mesh page: the
// next run meshes again; the options that are strings
let pages = [];
export const viewPage = () => pages.find((p) => p.name === 'View');
const meshing = new Set();
export const textOptions = new Set();
const optionEntries = []; // [option, kind, input]
export const views = () => gmsh.option.getNumber('PostProcessing.NbViews');
// The normal raise of a view is in model units per unit of its values: the
// slider gives it as a fraction of the size of the view for its largest
// value, which raises all the views alike, whatever their size and values
function raiseUnit(i) {
  const num = (n) => gmsh.option.getNumber(`View[${i}].${n}`);
  const size = Math.hypot(num('MaxX') - num('MinX'), num('MaxY') - num('MinY'),
                          num('MaxZ') - num('MinZ'));
  const vmax = Math.max(Math.abs(num('Min')), Math.abs(num('Max')));
  // (none for a view without values or without bounds)
  return vmax > 0 && isFinite(size) ? size / vmax : 0;
}
export function setViewOption(name, i, v) {
  if(name === 'View.NormalRaise') v *= raiseUnit(i);
  const option = name.replace('View.', `View[${i}].`);
  if(textOptions.has(name)) gmsh.option.setString(option, v);
  else gmsh.option.setNumber(option, v);
}
export function getViewOption(name, i) {
  const option = name.replace('View.', `View[${i}].`);
  if(textOptions.has(name)) return gmsh.option.getString(option);
  const v = gmsh.option.getNumber(option);
  if(name !== 'View.NormalRaise') return v;
  const u = raiseUnit(i);
  return u ? v / u : 0;
}
export function setOption(name, v) {
  if(typeof v === 'string') gmsh.option.setString(name, v);
  else gmsh.option.setNumber(name, v);
  keepOption(name, v);
  draw();
}
// What follows an option set (here, or by an item of a menu in Gmsh): the
// mesh made again by the next run if it changes it, the page's colours
function keepOption(name, v) {
  if(meshing.has(name)) gmsh.onelab.setChanged('Gmsh', 2);
  if(name === 'General.ColorScheme') setColorScheme(v);
}
// an option as Gmsh has it now, after an item or a key changed it: kept as
// keepOption() does, or for an option of the views, kept by the name of the
// view of index view (see keepViewOption()), or of all the visible views
export function keepOptionOf(name, view = -1) {
  if(!name.startsWith('View.')) {
    keepOption(name, gmsh.option.getNumber(name));
    return;
  }
  viewTags().forEach((t, i) => {
    if(view >= 0 ? i === view : viewNum(i, 'Visible')) keepViewOption(i, name);
  });
}
// the colour scheme: the page light or dark as the scene, which follows the
// browser when it is 3 (As the browser); kept for the next models (which
// start from the default options) and the next visits
export let colorScheme = 3;
export function setColorScheme(v) {
  colorScheme = v;
  try { localStorage.setItem('colorScheme', v); } catch(e) {}
  applyColorScheme();
}
export function applyColorScheme() {
  if(gmsh.option.getNumber('General.ColorScheme') !== colorScheme)
    gmsh.option.setNumber('General.ColorScheme', colorScheme);
  pageTheme(colorScheme);
  barColor();
  recolorParameters();
}
// the bars of a phone's browser (or of the app on its home screen) in the
// colour of the page
function barColor() {
  document.querySelector('meta[name=theme-color]').content =
    getComputedStyle(document.body).backgroundColor;
}
// the values an option takes, with their labels, and its range, as Gmsh
// lists them for its interfaces (src/common/DefaultOptions.h)
const optionChoices = (option) =>
  JSON.parse(web.optionChoices(option));
const optionRange = (option) =>
  JSON.parse(web.optionRange(option));
// the input of an option of a kind (check, number, range, choice or text),
// which gives change() its new value; its choices, or the range of a slider,
// from Gmsh unless given
export function optionInput(kind, option, change, range) {
  let el;
  if(kind === 'choice') {
    el = document.createElement('select');
    for(const [v, t] of optionChoices(option)) {
      const o = document.createElement('option');
      o.value = v;
      o.textContent = t;
      el.appendChild(o);
    }
  }
  else {
    el = document.createElement('input');
    el.type = {check: 'checkbox', number: 'number', range: 'range', text: 'text'}[kind];
    const r = range || optionRange(option);
    if(kind === 'range') Object.assign(el, r || {min: 0, max: 1, step: 0.05});
    if(kind === 'number') {
      el.step = 'any';
      if(r) Object.assign(el, {min: r.min, max: r.max});
    }
  }
  el.addEventListener(kind === 'range' ? 'input' : 'change', () => {
    // (an emptied number field is no value, not 0)
    if(kind === 'number' && el.value.trim() === '') return;
    change(kind === 'check' ? (el.checked ? 1 : 0) :
           kind === 'text' ? el.value : Number(el.value));
  });
  return el;
}
export function setInput(el, kind, v) {
  if(kind === 'check') el.checked = !!v;
  else el.value = String(v);
}
// the value of an option as its input shows it
const optionValue = (option, kind) =>
  kind === 'text' ? gmsh.option.getString(option) : gmsh.option.getNumber(option);
// an input with its label before it
export function optionRow(text, el) {
  const row = document.createElement('label');
  row.className = 'row';
  const label = document.createElement('span');
  label.textContent = text;
  row.append(label, el);
  return row;
}
// the name of an option as words ("Scale type" for View.ScaleType)
const optionWords = (option) => option.split('.')[1]
  .replace(/([a-z0-9])([A-Z])/g, '$1 $2').replace(/ ([A-Z])(?=[a-z])/g, (m, c) => ' ' + c.toLowerCase());
// a section of a page: a folding block with its name, open as in the window,
// and the rows of entries the table gives it, without the custom ones:
// input() makes the input of each (or none); the entries without label share
// the row of the next one with a label (X, Y, Z and "Axes ticks"), an entry
// left without one is named as its option, in words. Null if no input is made.
export function sectionBlock(sec, input) {
  const sd = document.createElement('details');
  sd.open = sec.open;
  const ss = document.createElement('summary');
  ss.textContent = sec.name;
  sd.appendChild(ss);
  let inputs = 0;
  for(const row of sec.rows) {
    if(row.length && row[0].kind === 'heading') {
      const h = document.createElement('div');
      h.className = 'heading';
      h.textContent = row[0].option;
      sd.appendChild(h);
      continue;
    }
    let group = [];
    const entries = row.filter((f) => f.kind !== 'custom');
    for(const f of entries) {
      const el = input(f);
      if(el) group.push(el);
      if(!f.label && f !== entries[entries.length - 1]) continue;
      if(group.length) {
        let one = group[0];
        if(group.length > 1) {
          one = document.createElement('div');
          one.className = 'entries';
          one.append(...group);
        }
        sd.appendChild(optionRow(f.label || optionWords(f.option), one));
        inputs += group.length;
      }
      group = [];
    }
  }
  return inputs ? sd : null;
}
// a page of the Options tab
function buildPage(page) {
  const d = document.createElement('details');
  d.open = ['General', 'Geometry', 'Mesh'].includes(page.name);
  d.id = 'options' + page.name;
  const sum = document.createElement('summary');
  sum.textContent = page.name;
  d.appendChild(sum);
  for(const sec of page.sections) {
    const sd = sectionBlock(sec, (f) => {
      const el = optionInput(f.kind, f.option, (v) => setOption(f.option, v));
      el.title = f.option;
      optionEntries.push([f.option, f.kind, el]);
      if(page.name === 'Mesh' && ['General', 'Advanced'].includes(sec.name))
        meshing.add(f.option);
      return el;
    });
    if(sd) d.appendChild(sd);
  }
  if(page.name === 'Mesh') {
    const note = document.createElement('div');
    note.className = 'note';
    note.textContent = 'Run meshes again after a change of the General or Advanced options';
    d.appendChild(note);
  }
  return d;
}
function buildOptions() {
  pages = JSON.parse(web.optionPages());
  for(const page of pages)
    for(const sec of page.sections)
      for(const row of sec.rows)
        for(const f of row)
          if(f.kind === 'text') textOptions.add(f.option);
  for(const page of pages)
    if(page.name !== 'View') $('optionsTab').appendChild(buildPage(page));
}
// the options as Gmsh has them (a model sets some, its views their own), the
// views not seen yet given what the page kept for them (see settleViews())
export function readOptions() {
  settleViews();
  // (not the input being typed in: this runs at each step of a run or an
  // animation)
  for(const [name, kind, el] of optionEntries)
    if(el !== document.activeElement) setInput(el, kind, optionValue(name, kind));
  updateViews();
}
export function showTab(id) {
  for(const o of document.querySelectorAll('#tabs button')) {
    o.classList.toggle('on', o.dataset.tab === id);
    $(o.dataset.tab).hidden = o.dataset.tab !== id;
  }
  // the model may have changed size
  if(id === 'clipTab') readClipping();
  if(id === 'visTab') readVisibility();
  if(id === 'plugTab') readPlugins();
}
// the Options tab, at the options of a page
export function showOptions(page) {
  showTab('optionsTab');
  if(page) {
    $('options' + page).open = true;
    $('options' + page).scrollIntoView({block: 'start'});
  }
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  try { colorScheme = Number(localStorage.getItem('colorScheme') ?? 3); } catch(e) {}
  matchMedia('(prefers-color-scheme: dark)').addEventListener('change', (e) => {
    if(colorScheme !== 3) return;
    pageTheme(colorScheme);
    barColor();
    web.colorScheme(e.matches ? 1 : 0);
    recolorParameters();
    draw();
  });
  applyColorScheme();
  buildOptions();
  readOptions();
  for(const b of document.querySelectorAll('#tabs button'))
    b.addEventListener('click', () => showTab(b.dataset.tab));
}
