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

// The ONELAB parameters: the tree of the Model tab as the FLTK graphical
// user interface shows it, each row a field, a check box or a menu, with the
// range, the loop and the X-Y graphs of a number, in the colours a model asks

import {$, app, gmsh} from './app.mjs';
import {web} from './gmshweb.mjs';
import {editFile} from './editor.mjs';
import {draw} from './scene.mjs';
import {graphEdits, run, showSolverProgress, valueEdits} from './solverClient.mjs';
import {placePopup} from './statusbar.mjs';

// the parameters, in the JSON of the ONELAB database
export function getParameters() {
  const json = gmsh.onelab.get();
  return json ? JSON.parse(json).onelab.parameters : [];
}
// a changed parameter, with what the graphical interface does besides (the
// Gmsh option it stands for, the actions on other parameters it asks for):
// returns 1 if the model is to be checked
export function setParameter(p) {
  return web.onelabSet(JSON.stringify(p));
}
// the parameter tree, as the graphical interface shows it: a branch for
// each part of the names' paths, the branches and the parameters of a branch
// sorted by their names as they are (byte order: the leading spaces, digits
// and braces that sort them come before the letters), and shown without
// these (as onelab::parameter::getShortName() does); the branches a
// parameter asks to be closed ("Closed" attribute) closed, until opened
const shortName = (s) => s.replace(/^ +/, '').replace(/^[{}]+/, '').replace(/^\d+/, '');
const byName = (a, b) => (a < b ? -1 : a > b ? 1 : 0);
export const groupOpen = {};
let choiceLists = 0;
// The tree is made again only when what it shows changes (parameters, their
// kind, labels, colours, choices of a field): new values alone are written in
// the rows as they are, so that a row being clicked or typed in while a
// solver runs (and refreshes the tree several times a second) stays
let treeKey = '';
const rowUpdates = new Map();
function rowKey(p) {
  const a = p.attributes || {};
  return [p.name, p.type, p.readOnly, p.label, p.help, a.Units, a.Highlight,
          a.Closed, a.Loop, a.ReadOnlyRange, p.valueLabels,
          p.readOnly ? '' : [p.choices, p.min, p.max, p.step]];
}
// the tree made again, its colours being those of the page (light or dark)
export function recolorParameters() {
  treeKey = '';
  showParameters();
}
export function showParameters() {
  const shown = getParameters().filter(
    (p) => p.visible && !p.name.includes('ONELAB Context/'));
  const key = JSON.stringify(shown.map(rowKey));
  if(key === treeKey) {
    for(const p of shown) rowUpdates.get(p.name)(p);
    return;
  }
  treeKey = key;
  rowUpdates.clear();
  const root = {children: new Map()};
  const closed = new Set();
  for(const p of shown) {
    const parts = p.name.split('/');
    let node = root;
    for(const part of parts.slice(0, -1)) {
      if(!node.children.has(part)) node.children.set(part, {children: new Map()});
      node = node.children.get(part);
    }
    node.children.set(parts[parts.length - 1], {parameter: p});
    if(p.attributes && p.attributes.Closed === '1')
      closed.add(parts.slice(0, -1).join('/'));
  }
  const params = $('params');
  params.textContent = '';
  const add = (node, path, parent) => {
    for(const key of [...node.children.keys()].sort(byName)) {
      const child = node.children.get(key);
      if(child.parameter) {
        parent.appendChild(parameterRow(child.parameter, shortName(key)));
        continue;
      }
      const branch = path ? path + '/' + key : key;
      const d = document.createElement('details');
      const sum = document.createElement('summary');
      sum.textContent = shortName(key);
      d.appendChild(sum);
      d.open = groupOpen[branch] !== undefined ? groupOpen[branch] : !closed.has(branch);
      d.addEventListener('toggle', () => { groupOpen[branch] = d.open; });
      add(child, branch, d);
      parent.appendChild(d);
    }
  };
  add(root, '', params);
}
function parameterRow(p, name) {
  const row = document.createElement('label');
  row.className = 'row';
  const label = document.createElement('span');
  const units = p.attributes && p.attributes.Units;
  label.textContent = (p.label || name) + (units ? ` [${units}]` : '');
  if(p.help) row.title = p.help;
  row.appendChild(label);
  const value = p.values ? p.values[0] : '';
  const choices = p.choices || [];
  const labels = {};
  for(const [k, v] of Object.entries(p.valueLabels || {})) labels[v] = k;
  const shownValue = (v) => (p.type === 'number' && labels[v] !== undefined) ?
    labels[v] : (typeof v === 'number' ? Number(v.toPrecision(6)) : v);
  // where the colour the model asks for shows: as the fill of the field, of
  // the label of a check box, or as the text of a menu
  let el, tint;
  // a string the model made a button of (as the FLTK interface does): a
  // script parsed, a file merged or an action for a custom interface
  const macro = p.type === 'string' && p.attributes &&
    ['Gmsh', 'GmshMergeFile', 'GmshParseString', 'Action'].includes(p.attributes.Macro);
  if(macro) {
    el = document.createElement('button');
    el.textContent = label.textContent;
    label.textContent = '';
    el.addEventListener('click', (e) => {
      e.preventDefault();
      // (a script or a file changes the model: not during a run)
      if(app.busy && p.attributes.Macro !== 'Action') return;
      if(web.onelabMacro(p.name) & 1)
        run('check');
      else {
        showParameters();
        draw();
      }
    });
    row.appendChild(el);
    // (no value to show again: its label is in the key of the tree)
    rowUpdates.set(p.name, () => {});
    return row;
  }
  if(p.readOnly) {
    el = document.createElement('span');
    el.className = 'out';
    el.textContent = shownValue(value);
    tint = 'field';
  }
  else if(p.type === 'number' && choices.length === 2 && choices[0] === 0 &&
          choices[1] === 1 && !Object.keys(labels).length) {
    el = document.createElement('input');
    el.type = 'checkbox';
    el.checked = !!value;
    tint = 'label';
  }
  else if(choices.length && p.type === 'number') {
    el = document.createElement('select');
    for(const c of choices) {
      const o = document.createElement('option');
      o.value = c;
      o.textContent = labels[c] !== undefined ? labels[c] : c;
      if(c === value) o.selected = true;
      el.appendChild(o);
    }
    tint = 'text';
  }
  else if(choices.length) {
    // a string with choices: a field that also takes other values, its
    // choices offered (Fl_Input_Choice in the graphical interface)
    el = document.createElement('input');
    el.value = value;
    const list = document.createElement('datalist');
    list.id = 'choices-' + (++choiceLists);
    for(const c of choices) {
      const o = document.createElement('option');
      o.value = c;
      list.appendChild(o);
    }
    row.appendChild(list);
    el.setAttribute('list', list.id);
    tint = 'field';
  }
  else {
    el = document.createElement('input');
    if(p.type === 'number') {
      el.type = 'number';
      if(p.step && p.step < 1e200) el.step = p.step;
      if(p.min > -1e200) el.min = p.min;
      if(p.max < 1e200) el.max = p.max;
    }
    el.value = value;
    tint = 'field';
  }
  // the colour the model asks for, where the graphical interface shows it
  const rgb = highlightColor(p.attributes && p.attributes.Highlight);
  if(rgb !== null) {
    if(tint === 'text')
      el.style.color = css(readableColor(rgb, Readable.Text));
    else {
      const target = tint === 'label' ? label : el;
      target.classList.add('highlight');
      target.style.background = css(readableColor(rgb, Readable.Fill));
      target.style.color = css(readableColor(rgb, Readable.OnFill));
    }
  }
  // the row given new values, but where it is being typed in; its range and
  // loop not changed while a solver runs (whose database would replace them)
  const field = el;
  let button = null, rangeButton = null, loopButton = null;
  const update = (q) => {
    const v = q.values ? q.values[0] : '';
    if(q.readOnly) field.textContent = shownValue(v);
    else if(field !== document.activeElement) {
      if(field.type === 'checkbox') field.checked = !!v;
      else field.value = v;
    }
    if(button) {
      button.classList.toggle('on', /[^0]/.test(graphValue(q)));
      button.disabled = !q.readOnly && !hasRange(q);
    }
    if(rangeButton) rangeButton.disabled = app.busy;
    if(loopButton) loopButton.disabled = app.busy || !hasRange(q);
  };
  rowUpdates.set(p.name, update);
  // a number to set: its range or choices, the loop over them and the X-Y
  // graphs it is drawn on, as the graphical interface's inputRange (but a
  // menu of named values); an output: its graphs
  const ranged = p.type === 'number' && !p.readOnly && tint !== 'label' &&
    !Object.keys(labels).length;
  if(p.type === 'number' && (p.readOnly || ranged)) {
    const pair = document.createElement('span');
    pair.className = 'withGraph';
    pair.appendChild(el);
    if(ranged) {
      rangeButton = rangeButtonFor(p);
      loopButton = loopButtonFor(p);
      pair.append(rangeButton, loopButton);
    }
    button = graphButton(p);
    pair.appendChild(button);
    el = pair;
    update(p);
  }
  // a file (the input files of a solver, ...): edited, the one chosen if it
  // is one of a list
  if(p.type === 'string' && p.kind === 'file') {
    let file = el;
    if(p.readOnly && choices.length > 1) {
      file = document.createElement('select');
      for(const c of choices) file.add(new Option(c.slice(c.lastIndexOf('/') + 1), c));
      file.value = value;
      file.title = 'The file to edit';
    }
    const edit = document.createElement('button');
    edit.type = 'button';
    edit.textContent = 'Edit';
    edit.title = 'Edit the file';
    edit.addEventListener('click', (e) => {
      e.preventDefault();
      editFile(file.value || file.textContent);
    });
    const pair = document.createElement('span');
    pair.className = 'withGraph';
    pair.append(file, edit);
    el = pair;
  }
  if(!p.readOnly) {
    el.addEventListener('change', (e) => {
      if(e.target.closest('#graphMenu')) return;
      let v = e.target.type === 'checkbox' ? (e.target.checked ? 1 : 0) : e.target.value;
      if(p.type === 'number') v = Number(v);
      // the parameter as it is now (the row may have been given new values)
      p = getParameters().find((q) => q.name === p.name) || p;
      p.values = [v];
      // (kept over the database the solver running sends back)
      if(app.busy) valueEdits.set(p.name, p.values);
      if(setParameter(p) & 1)
        run('check');
      else {
        showParameters();
        draw();
      }
    });
  }
  row.appendChild(el);
  return row;
}
// The X-Y graphs, as the graph button of the graphical interface sets them: a
// number drawn as X, Y, X' or Y' of the graphs at 9 places, in its "Graph"
// attribute (36 characters, 2 for each of 18 graphs, the primed ones the odd
// graphs: '0' not drawn, else how, '3' by default); the graphs are views
// made from the values of the numbers (onelabUtils::updateGraphs())
const graphPlaces = ['Top left', 'Top right', 'Bottom left', 'Bottom right',
                     'Top', 'Bottom', 'Left', 'Right', 'Full'];
const graphBoxes = [];
let graphParameter = '';
const graphValue = (p) => ((p.attributes && p.attributes.Graph) || '').padEnd(36, '0');
function graphButton(p) {
  const b = document.createElement('button');
  b.type = 'button';
  b.className = 'graphButton' + (/[^0]/.test(graphValue(p)) ? ' on' : '');
  b.title = 'Draw on the X-Y graphs';
  b.innerHTML = '<svg width="14" height="12" viewBox="0 0 14 12" fill="none" ' +
    'stroke="currentColor" stroke-width="1.4"><path d="M1 1v10h12"/>' +
    '<path d="M3 8l3-3 2 2 4-5"/></svg>';
  b.addEventListener('click', (e) => {
    e.preventDefault();
    openGraphMenu(p.name, b);
  });
  return b;
}
function openGraphMenu(name, button) {
  const p = getParameters().find((q) => q.name === name);
  if(!p) return;
  graphParameter = name;
  $('graphName').textContent = p.label || shortName(name.split('/').pop());
  const val = graphValue(p);
  graphBoxes.forEach((cb, i) => { cb.checked = val[i] !== '0'; });
  const menu = $('graphMenu');
  menu.hidden = false;
  const r = button.getBoundingClientRect();
  placePopup(menu, r.left, r.bottom + 2);
}
// the graphs the menu checks, kept as they were drawn where still checked
function setGraph() {
  const p = getParameters().find((q) => q.name === graphParameter);
  if(!p) return;
  const old = graphValue(p);
  const val = graphBoxes.map((cb, i) => cb.checked ? (old[i] !== '0' ? old[i] : '3') : '0');
  p.attributes = Object.assign({}, p.attributes, {Graph: val.join('')});
  setParameter(p);
  // kept while a solver runs, whose database does not have it
  if(app.busy) graphEdits.set(p.name, p.attributes.Graph);
  showSolverProgress();
}
// The range of a number, its loop over it, as the graphical interface's
// inputRange: "min : max", "min : max : step" or "val1, val2, ..." (its
// choices), edited in a box (only shown if the model says ReadOnlyRange); the
// loop button going through the levels 1, 2 and 3 (nested loops, 1 the
// outer, run by Run: onelabUtils::initializeLoops()) and none. A number loops
// or is drawn on a graph once it has a range with a step, or choices
const noRange = 1e200; // onelab::parameter::maxNumber()
const hasRange = (p) => (p.choices && p.choices.length > 0) || p.step > 0;
const fmtNumber = (v) => String(Number(Number(v).toPrecision(12)));
function rangeString(p) {
  if(p.choices && p.choices.length) return p.choices.map(fmtNumber).join(', ');
  if(p.min > -noRange && p.max < noRange)
    return fmtNumber(p.min) + ' : ' + fmtNumber(p.max) +
      (p.step ? ' : ' + fmtNumber(p.step) : '');
  return '';
}
// the parameter as the box asks, or the error in what it says
function parseRange(p, text) {
  const t = text.trim();
  const num = (s) => {
    const v = Number(s.trim());
    if(!s.trim() || !Number.isFinite(v)) throw new Error(`"${s.trim()}" is not a number`);
    return v;
  };
  if(t.includes(',')) {
    p.choices = t.split(',').map(num);
    p.step = 0;
  }
  else {
    const [min = '', max = '', step = ''] = t.split(':');
    if(t.split(':').length > 3) throw new Error('at most min : max : step');
    p.min = min.trim() ? num(min) : -noRange;
    p.max = max.trim() ? num(max) : noRange;
    p.step = step.trim() ? num(step) : 0;
    p.choices = [];
  }
  return p;
}
// a range or a loop changed, as the graphical interface does
// (onelab_number_input_range_cb)
function changeRange(p) {
  if(setParameter(p) & 1)
    run('check');
  else
    showSolverProgress();
}
const rowButton = (cls, title) => {
  const b = document.createElement('button');
  b.type = 'button';
  b.className = 'graphButton ' + cls;
  b.title = title;
  return b;
};
function rangeButtonFor(p) {
  const readOnly = p.attributes && p.attributes.ReadOnlyRange === '1';
  const b = rowButton('rangeButton',
                      readOnly ? 'Show the range or choices' : 'Edit the range or choices');
  b.textContent = ':';
  b.addEventListener('click', (e) => {
    e.preventDefault();
    openRangeMenu(p.name, b);
  });
  return b;
}
function loopButtonFor(p) {
  const level = (p.attributes && p.attributes.Loop) || '';
  const b = rowButton('loopButton',
                      'Loop over the range or choices (loop level 1, 2 or 3)');
  if(['1', '2', '3'].includes(level)) {
    b.textContent = level;
    b.classList.add('level' + level);
  }
  else
    // (a loop, as the repeat of a player: the icon of the graphical interface)
    b.innerHTML = '<svg width="13" height="13" viewBox="0 0 24 24" fill="none" ' +
      'stroke="currentColor" stroke-width="2.4" stroke-linecap="round" ' +
      'stroke-linejoin="round"><path d="M17 2l4 4-4 4"/>' +
      '<path d="M3 11V9a3 3 0 0 1 3-3h15"/><path d="M7 22l-4-4 4-4"/>' +
      '<path d="M21 13v2a3 3 0 0 1-3 3H3"/></svg>';
  b.addEventListener('click', (e) => {
    e.preventDefault();
    const q = getParameters().find((x) => x.name === p.name);
    if(!q) return;
    const cur = (q.attributes && q.attributes.Loop) || '';
    const next = {'1': '2', '2': '3', '3': '0'}[cur] || '1';
    q.attributes = Object.assign({}, q.attributes, {Loop: next});
    changeRange(q);
  });
  return b;
}
let rangeParameter = '';
function openRangeMenu(name, button) {
  const p = getParameters().find((q) => q.name === name);
  if(!p) return;
  rangeParameter = name;
  const readOnly = p.attributes && p.attributes.ReadOnlyRange === '1';
  $('rangeName').textContent = (readOnly ? 'Range or choices of ' : 'Range or choices: ') +
    (p.label || shortName(name.split('/').pop()));
  $('rangeText').value = rangeString(p);
  $('rangeText').readOnly = readOnly;
  $('rangeApply').hidden = readOnly;
  $('rangeNote').className = 'note';
  $('rangeNote').textContent = 'min : max, min : max : step, or val1, val2, ...';
  const menu = $('rangeMenu');
  menu.hidden = false;
  const r = button.getBoundingClientRect();
  placePopup(menu, r.right - menu.offsetWidth, r.bottom + 2);
  $('rangeText').focus();
  $('rangeText').select();
}
function applyRange() {
  const p = getParameters().find((q) => q.name === rangeParameter);
  if(!p || $('rangeText').readOnly) return;
  try {
    parseRange(p, $('rangeText').value);
  } catch(err) {
    $('rangeNote').className = 'error';
    $('rangeNote').textContent = err.message;
    return;
  }
  $('rangeMenu').hidden = true;
  changeRange(p);
}
// the colours of the parameters, as the graphical interface makes them (see
// src/common/ColorContrast.h): the colour of a name in Gmsh's table ("1" for
// yellow), as 0xrrggbb, or null
const colorCache = new Map();
function highlightColor(name) {
  if(!name) return null;
  if(name === '1') name = 'yellow';
  if(!colorCache.has(name)) {
    const c = web.color(name);
    colorCache.set(name, c < 0 ? null : c);
  }
  return colorCache.get(name);
}
const css = (c) => `rgb(${(c >> 16) & 255}, ${(c >> 8) & 255}, ${c & 255})`;
// the colour as a text (Readable.Text), as the background of a field
// (Readable.Fill) or as the text on that field (Readable.OnFill), on the
// background and with the text of the page, in its colour scheme
const Readable = {Text: 0, Fill: 1, OnFill: 2};
function readableColor(rgb, what) {
  const theme = (name) => getComputedStyle(document.documentElement)
    .getPropertyValue(name).trim().match(/\d+/g).slice(0, 3)
    .reduce((c, v) => (c << 8) | Number(v), 0);
  const dark = getComputedStyle(document.documentElement).colorScheme.trim() === 'dark';
  return web.readableColor(rgb, theme('--bg-rgb'), theme('--fg-rgb'), dark ? 1 : 0,
                           what);
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  {
    const head = $('graphTable').insertRow();
    for(const t of ['', 'X', 'Y', "X′", "Y′"]) {
      const th = document.createElement('th');
      th.textContent = t;
      head.appendChild(th);
    }
    for(const place of graphPlaces) {
      const tr = $('graphTable').insertRow();
      tr.insertCell().textContent = place;
      for(let a = 0; a < 4; a++) {
        const cb = document.createElement('input');
        cb.type = 'checkbox';
        cb.addEventListener('change', setGraph);
        tr.insertCell().appendChild(cb);
        graphBoxes.push(cb);
      }
    }
  }
  $('graphNone').addEventListener('click', () => {
    graphBoxes.forEach((cb) => { cb.checked = false; });
    setGraph();
  });
  $('rangeApply').addEventListener('click', applyRange);
  $('rangeCancel').addEventListener('click', () => { $('rangeMenu').hidden = true; });
  // (the shortcuts leave the keys of a field alone)
  $('rangeText').addEventListener('keydown', (e) => {
    if(e.key === 'Enter') applyRange();
    else if(e.key === 'Escape') $('rangeMenu').hidden = true;
  });
}
