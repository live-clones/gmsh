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

// The Options tab: the main Gmsh options as in the option window of the FLTK
// graphical user interface, bound to their options by name, the colour scheme
// of the page, and the tabs of the panel

import {$, gmsh} from './app.mjs';
import {web} from './gmshweb.mjs';
import {readClipping} from './clipping.mjs';
import {recolorParameters} from './parameters.mjs';
import {draw} from './scene.mjs';
import {keepViewOption, settleViews, updateViews, viewNum, viewTags} from './views.mjs';
import {readVisibility} from './visibility.mjs';

// the main Gmsh options, as in the option window of the FLTK interface:
// [option, kind, label, range if not Gmsh's]; the options of the views are set
// under each view in the Post-processing module (see views.mjs)
const optionGroups = [
  ['General', [
    ['General.Axes', 'choice', 'Axes'],
    ['General.SmallAxes', 'check', 'Small axes'],
    ['General.Orthographic', 'choice', 'Projection'],
    ['General.Shading', 'choice', 'Shading'],
    ['General.ColorScheme', 'choice', 'Colors']]],
  ['Geometry', [
    ['Geometry.Points', 'check', 'Points'],
    ['Geometry.Curves', 'check', 'Curves'],
    ['Geometry.Surfaces', 'check', 'Surfaces'],
    ['Geometry.Volumes', 'check', 'Volumes'],
    ['Geometry.Opacity', 'range', 'Opacity']]],
  ['Mesh', [
    ['Mesh.Algorithm', 'choice', '2D algorithm'],
    ['Mesh.Algorithm3D', 'choice', '3D algorithm'],
    ['Mesh.MeshSizeFactor', 'number', 'Element size factor'],
    ['Mesh.ElementOrder', 'number', 'Element order'],
    ['Mesh.RecombineAll', 'check', 'Recombine all triangles'],
    ['Mesh.Nodes', 'check', 'Nodes'],
    ['Mesh.Lines', 'check', '1D elements'],
    ['Mesh.SurfaceEdges', 'check', '2D element edges'],
    ['Mesh.SurfaceFaces', 'check', '2D element faces'],
    ['Mesh.VolumeEdges', 'check', '3D element edges'],
    ['Mesh.VolumeFaces', 'check', '3D element faces'],
    ['Mesh.Opacity', 'range', 'Opacity']]],
];
// the options that change the mesh: the next run meshes again
const meshing = new Set(['Mesh.Algorithm', 'Mesh.Algorithm3D',
  'Mesh.MeshSizeFactor', 'Mesh.ElementOrder', 'Mesh.RecombineAll']);
const optionFields = [];
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
  gmsh.option.setNumber(name.replace('View.', `View[${i}].`), v);
}
export function getViewOption(name, i) {
  const v = gmsh.option.getNumber(name.replace('View.', `View[${i}].`));
  if(name !== 'View.NormalRaise') return v;
  const u = raiseUnit(i);
  return u ? v / u : 0;
}
export function setOption(name, v) {
  gmsh.option.setNumber(name, v);
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
// the field of an option of a kind (check, number, range or choice), which
// gives change() its new value; its choices, or the range of a slider, from
// Gmsh unless given
export function optionField(kind, option, change, range) {
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
    el.type = {check: 'checkbox', number: 'number', range: 'range'}[kind];
    const r = range || optionRange(option);
    if(kind === 'range') Object.assign(el, r || {min: 0, max: 1, step: 0.05});
    if(kind === 'number') {
      el.step = 'any';
      if(r) Object.assign(el, {min: r.min, max: r.max});
    }
  }
  el.addEventListener(kind === 'range' ? 'input' : 'change', () =>
    change(kind === 'check' ? (el.checked ? 1 : 0) : Number(el.value)));
  return el;
}
export function setField(el, kind, v) {
  if(kind === 'check') el.checked = !!v;
  else el.value = String(v);
}
// a field with its label before it
export function optionRow(text, el) {
  const row = document.createElement('label');
  row.className = 'row';
  const label = document.createElement('span');
  label.textContent = text;
  row.append(label, el);
  return row;
}
function buildOptions() {
  const tab = $('optionsTab');
  for(const [group, options] of optionGroups) {
    const d = document.createElement('details');
    d.open = true;
    d.id = 'options' + group;
    const sum = document.createElement('summary');
    sum.textContent = group;
    d.appendChild(sum);
    for(const [name, kind, text, range] of options) {
      const el = optionField(kind, name, (v) => setOption(name, v), range);
      el.title = name;
      d.appendChild(optionRow(text, el));
      optionFields.push([name, kind, el]);
    }
    if(group === 'Mesh') {
      const note = document.createElement('div');
      note.className = 'note';
      note.textContent = 'Run meshes again after a change of the first five';
      d.appendChild(note);
    }
    tab.appendChild(d);
  }
}
// the options as Gmsh has them (a model sets some, its views their own), the
// views not seen yet given what the page kept for them (see settleViews())
export function readOptions() {
  settleViews();
  for(const [name, kind, el] of optionFields)
    setField(el, kind, gmsh.option.getNumber(name));
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
}
// the Options tab, at the options of a group
export function showOptions(group) {
  showTab('optionsTab');
  if(group) {
    $('options' + group).open = true;
    $('options' + group).scrollIntoView({block: 'start'});
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
