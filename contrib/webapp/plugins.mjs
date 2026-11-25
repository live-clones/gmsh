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

// The Plugins tab: the plugins of src/plugin (gmshWebPlugins in webApp.cpp),
// as the plugin window of the FLTK graphical user interface shows them
// (src/fltk/pluginWindow.cpp): the list, searched by name and description;
// the options of the plugin chosen, as sliders when it gives their range for
// the first view chosen, its preview drawn in the scene while they change (a
// cutting plane...); the views it runs on; and Run, which runs it on each of
// them (PluginManager::runOnViews)

import {$, gmsh, setStatus} from './app.mjs';
import {web} from './gmshweb.mjs';
import {showTab} from './options.mjs';
import {draw} from './scene.mjs';
import {firstView, showViews, viewTags} from './views.mjs';

let plugins = [], chosen = null;
const chosenViews = new Set(); // their tags
const fmt = (v) => String(Number(Number(v).toPrecision(6)));
const viewName = (i) => gmsh.option.getString(`View[${i}].Name`);
// the View option of a plugin of the views is the views chosen
const shown = (p, o) => !(p.post && o.name === 'View');

// the plugins and the values of their options read again (a script may have
// set them), the views chosen kept if they are still there
export function readPlugins() {
  const name = chosen && chosen.name;
  plugins = web.plugins();
  chosen = plugins.find((p) => p.name === name) || null;
  const tags = viewTags();
  for(const t of [...chosenViews])
    if(!tags.includes(t)) chosenViews.delete(t);
  if(!chosenViews.size && tags.length) chosenViews.add(firstView());
  showList();
  showForm();
}

// the tab shown, with the given view chosen (its tag; none: those chosen)
export function showPlugins(tag) {
  if(tag !== undefined) {
    chosenViews.clear();
    chosenViews.add(tag);
  }
  showTab('plugTab');
}

function showList() {
  const words = $('plugFilter').value.toLowerCase().split(/\s+/).filter((w) => w);
  const list = $('plugList');
  list.textContent = '';
  for(const p of plugins) {
    const text = (p.name + ' ' + p.short).toLowerCase();
    if(!words.every((w) => text.includes(w))) continue;
    const row = document.createElement('button');
    row.className = 'plugin' + (p === chosen ? ' on' : '');
    const name = document.createElement('span');
    name.textContent = p.name;
    const help = document.createElement('small');
    help.textContent = p.short;
    row.append(name, help);
    row.addEventListener('click', () => choose(p));
    list.append(row);
  }
}

function choose(p) {
  // (the preview of the plugin chosen before goes)
  if(p !== chosen && web.pluginPreview('', -1)) draw();
  chosen = p;
  showList();
  showForm();
}

function row(text, field) {
  const r = document.createElement('label');
  r.className = 'row';
  const label = document.createElement('span');
  label.textContent = text;
  r.append(label, field);
  return r;
}

// the index of the first view chosen, whose values give the sliders their
// range; -1 if none
function firstChosen() {
  const tags = viewTags();
  return tags.findIndex((t) => chosenViews.has(t));
}

function showForm() {
  const form = $('plugForm');
  form.textContent = '';
  const p = chosen;
  if(!p) return;
  const title = document.createElement('div');
  title.className = 'plugTitle';
  title.textContent = p.name;
  const help = document.createElement('details');
  const summary = document.createElement('summary');
  summary.textContent = p.short;
  const text = document.createElement('div');
  text.className = 'note plugHelp';
  text.textContent = p.help + '\n\nAuthor(s): ' + p.author;
  help.append(summary, text);
  form.append(title, help);

  const options = document.createElement('div');
  if(p.post) {
    const head = document.createElement('div');
    head.className = 'note';
    const tags = viewTags();
    head.textContent = tags.length ? 'Run on the views' : 'No views to run on';
    form.append(head);
    tags.forEach((t, i) => {
      const cb = document.createElement('input');
      cb.type = 'checkbox';
      cb.checked = chosenViews.has(t);
      cb.addEventListener('change', () => {
        if(cb.checked) chosenViews.add(t);
        else chosenViews.delete(t);
        showOptions(options);
      });
      form.append(row(`[${i}] ${viewName(i)}`, cb));
    });
  }
  form.append(options);
  showOptions(options);
  const buttons = document.createElement('div');
  buttons.className = 'buttons';
  const run = document.createElement('button');
  run.textContent = 'Run';
  run.addEventListener('click', runChosen);
  buttons.append(run);
  form.append(buttons);
}

function showOptions(box) {
  const p = chosen;
  box.textContent = '';
  const ranges = web.pluginRanges(p.name, firstChosen());
  p.num.forEach((o, i) => {
    if(!shown(p, o)) return;
    const preview = () => { if(web.pluginPreview(p.name, i, o.value)) draw(); };
    const number = document.createElement('input');
    number.type = 'number';
    number.step = 'any';
    number.value = fmt(o.value);
    if(!ranges[i]) {
      number.addEventListener('change', () => {
        if(number.value === '') return;
        o.value = Number(number.value);
        preview();
      });
      box.append(row(o.name, number));
      return;
    }
    const [step, min, max] = ranges[i];
    const range = document.createElement('input');
    range.type = 'range';
    Object.assign(range, {min, max, step: step > 0 ? step : 'any'});
    range.value = o.value;
    range.addEventListener('input', () => {
      o.value = Number(range.value);
      number.value = fmt(o.value);
      preview();
    });
    number.addEventListener('change', () => {
      if(number.value === '') return;
      o.value = Number(number.value);
      range.value = o.value;
      preview();
    });
    const slider = document.createElement('span');
    slider.className = 'slider';
    slider.append(range, number);
    box.append(row(o.name, slider));
  });
  p.str.forEach((o, i) => {
    const input = document.createElement('input');
    input.type = 'text';
    input.spellcheck = false;
    input.value = o.value;
    input.addEventListener('change', () => {
      o.value = input.value;
      if(web.pluginPreview(p.name, i, 0, o.value)) draw();
    });
    box.append(row(o.name, input));
  });
}

function runChosen() {
  const p = chosen;
  for(const o of p.num)
    if(shown(p, o)) gmsh.plugin.setNumber(p.name, o.name, o.value);
  for(const o of p.str) gmsh.plugin.setString(p.name, o.name, o.value);
  const tags = viewTags();
  const views = p.post ? tags.map((t, i) => chosenViews.has(t) ? i : -1)
    .filter((i) => i >= 0) : [];
  setStatus(`Running Plugin(${p.name})...`);
  web.pluginRun(p.name, views);
  setStatus(`Done running Plugin(${p.name})`);
  showViews();
  readPlugins();
  draw();
}

export function build() {
  $('plugFilter').addEventListener('input', showList);
}
