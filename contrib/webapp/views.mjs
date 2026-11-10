// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The Post-processing module: the views, each shown or hidden by its box,
// with the menu of its button, and its options under it, kept by the name of
// the view for the views a solver makes again

import {$, download, gmsh, setStatus} from './app.mjs';
import {web} from './gmshweb.mjs';
import {menuItems, registry} from './actions.mjs';
import {getViewOption, optionField, optionRow, setField, setViewOption, showTab, views} from './options.mjs';
import {groupOpen} from './parameters.mjs';
import {draw} from './scene.mjs';
import {popupMenu, showAnimation} from './statusbar.mjs';

// The modules of the graphical interface's tree. Post-processing: the views
// (in the branches their Group option names), each shown or hidden by its box,
// with the menu of its button (its options, its export, the visibility and
// the removal of views). The options of a view are set under it, and only
// there; the page keeps them by the name of the view, so that the views a
// solver makes again at each run get them back, and those applied to all the
// views also go to the views to come (see settleViews())
export const viewSettings = new Map(); // view name -> {View.X: value}
export const allViewSettings = {}; // View.X -> value, for every view
export const settledViews = new Set(); // the views (tags) given their settings
export const viewOptionsOpen = new Set(); // the views whose options are shown
// The options of the views shown, by name: [kind, label, range if not
// Gmsh's] (the choices and ranges from Gmsh); those of one view, under it,
// and those of the Options tab, set for all the views
const viewOptions = {
  IntervalsType: ['choice', 'Intervals'],
  NbIso: ['number', 'Number of intervals'],
  RangeType: ['choice', 'Range'],
  CustomMin: ['number', 'Minimum'],
  CustomMax: ['number', 'Maximum'],
  TimeStep: ['number', 'Time step'],
  ScaleType: ['choice', 'Scale'],
  NormalRaise: ['range', 'Normal raise', {min: -0.5, max: 0.5, step: 0.01}],
  ShowScale: ['check', 'Color scale'],
  ShowElement: ['check', 'Element outlines'],
  Opacity: ['range', 'Opacity'],
  // (for the views with vectors, or tensors)
  VectorType: ['choice', 'Vector display'],
  ArrowSizeMax: ['number', 'Arrow size (pixels)'],
  DisplacementFactor: ['number', 'Displacement factor'],
  GlyphLocation: ['choice', 'Glyph location'],
  TensorType: ['choice', 'Tensor display']};
// those shown under a view, in this order, when they apply to it
const perViewOptions = ['IntervalsType', 'NbIso', 'RangeType', 'CustomMin',
  'CustomMax', 'ScaleType', 'TimeStep', 'VectorType', 'ArrowSizeMax',
  'DisplacementFactor', 'GlyphLocation', 'TensorType', 'NormalRaise',
  'ShowScale', 'ShowElement', 'Opacity'];
// what the view of index i holds: 1 scalars, 2 vectors, 4 tensors (or-ed)
const viewContent = (i) => web.viewContent(i);
export const viewTags = () => [...gmsh.view.getTags()];
export const viewNum = (i, n) => gmsh.option.getNumber(`View[${i}].${n}`);
// The list is made again only when what it shows changes (the views, their
// names, groups, time steps and range type, the options shown): otherwise the
// values are written in its fields as they are, so that a field being typed
// in while a solver runs (and shows new views several times a second) stays
let viewsKey = '';
const viewUpdates = [];
export function updateViews() {
  const tags = viewTags();
  for(const u of viewUpdates) u(tags);
}
export function showViews() {
  const tags = viewTags();
  const name = (i) => gmsh.option.getString(`View[${i}].Name`);
  const group = (i) => gmsh.option.getString(`View[${i}].Group`);
  $('modulePost').hidden = !tags.length;
  const key = JSON.stringify(tags.map((t, i) => [
    t, name(i), group(i), viewNum(i, 'NbTimeStep'), viewNum(i, 'RangeType'),
    viewNum(i, 'VectorType'), viewOptionsOpen.has(t)]));
  if(key !== viewsKey) {
    viewsKey = key;
    viewUpdates.length = 0;
    const list = $('viewList');
    list.textContent = '';
    const groups = new Map();
    const parentOf = (g) => {
      if(!g) return list;
      if(!groups.has(g)) {
        const d = document.createElement('details');
        const sum = document.createElement('summary');
        sum.textContent = g.slice(g.lastIndexOf('/') + 1);
        d.appendChild(sum);
        const branch = 'Post-processing/' + g;
        d.open = groupOpen[branch] ?? true;
        d.addEventListener('toggle', () => { groupOpen[branch] = d.open; });
        parentOf(g.slice(0, Math.max(0, g.lastIndexOf('/')))).appendChild(d);
        groups.set(g, d);
      }
      return groups.get(g);
    };
    tags.forEach((tag, i) => {
      const parent = parentOf(group(i));
      const row = document.createElement('div');
      row.className = 'view';
      const label = document.createElement('label');
      const cb = document.createElement('input');
      cb.type = 'checkbox';
      cb.addEventListener('change', () => {
        gmsh.option.setNumber(`View[${viewTags().indexOf(tag)}].Visible`, cb.checked ? 1 : 0);
        draw();
      });
      const text = document.createElement('span');
      text.textContent = text.title = name(i);
      label.append(cb, text);
      const menu = document.createElement('button');
      menu.className = 'graphButton menuButton';
      menu.textContent = '⋯';
      menu.title = 'Options, export, visibility and removal of the views';
      menu.addEventListener('click', () => {
        const r = menu.getBoundingClientRect();
        popupMenu(() => viewItems(tag), r.right - 220, r.bottom + 2, {owner: menu});
      });
      row.append(label, menu);
      parent.appendChild(row);
      viewUpdates.push((ts) => {
        const k = ts.indexOf(tag);
        if(k >= 0) cb.checked = !!viewNum(k, 'Visible');
      });
      if(viewOptionsOpen.has(tag)) parent.appendChild(viewOptionRows(tag, i));
    });
  }
  updateViews();
  showAnimation();
}
// the options of a view, under it: those that apply to what it holds, and a
// button that gives them to all the views
function viewOptionRows(tag, i) {
  const box = document.createElement('div');
  box.className = 'viewOptions';
  const steps = viewNum(i, 'NbTimeStep');
  const content = viewContent(i);
  const shown = [];
  for(const name of perViewOptions) {
    const [kind, text, range] = viewOptions[name];
    if(name === 'TimeStep' && steps < 2) continue;
    if(name.startsWith('Custom') && viewNum(i, 'RangeType') !== 2) continue;
    if(['VectorType', 'ArrowSizeMax', 'GlyphLocation'].includes(name) && !(content & 2))
      continue;
    if(name === 'DisplacementFactor' &&
       (!(content & 2) || viewNum(i, 'VectorType') !== 5))
      continue;
    if(name === 'TensorType' && !(content & 4)) continue;
    const option = 'View.' + name;
    const el = optionField(kind, option, (v) => setViewOptionOf(tag, option, v), range);
    el.title = `View[${i}].${name}`;
    if(name === 'TimeStep') Object.assign(el, {min: 0, max: steps - 1, step: 1});
    box.appendChild(optionRow(text, el));
    shown.push(option);
    viewUpdates.push((ts) => {
      const k = ts.indexOf(tag);
      if(k >= 0 && el !== document.activeElement)
        setField(el, kind, getViewOption(option, k));
    });
  }
  const all = document.createElement('button');
  all.textContent = 'Apply to all views';
  all.title = 'Give these options to all the views, and to the views to come ' +
    '(the time step and a custom range stay those of each view)';
  all.addEventListener('click', () => applyToAllViews(tag, shown));
  box.appendChild(all);
  return box;
}
// an option of a view set under it: kept for the views of its name
function setViewOptionOf(tag, option, v) {
  const i = viewTags().indexOf(tag);
  if(i < 0) return;
  setViewOption(option, i, v);
  customRangeOfValues(i);
  keepViewOption(i, option);
  showViews();
  draw();
}
// a custom range a view was not given yet (as when the range of another view
// becomes custom for all): that of its values, not an empty one that shows
// nothing
function customRangeOfValues(i) {
  if(viewNum(i, 'RangeType') !== 2 || viewNum(i, 'CustomMin') !== viewNum(i, 'CustomMax'))
    return;
  gmsh.option.setNumber(`View[${i}].CustomMin`, viewNum(i, 'Min'));
  gmsh.option.setNumber(`View[${i}].CustomMax`, viewNum(i, 'Max'));
}
// the options of a view given to all the views, and to the views to come
function applyToAllViews(tag, options) {
  const i = viewTags().indexOf(tag);
  if(i < 0) return;
  for(const option of options) {
    if(['View.TimeStep', 'View.CustomMin', 'View.CustomMax'].includes(option)) continue;
    const v = getViewOption(option, i);
    allViewSettings[option] = v;
    for(let k = 0; k < views(); k++) {
      setViewOption(option, k, v);
      keepViewOption(k, option);
    }
  }
  for(let k = 0; k < views(); k++) customRangeOfValues(k);
  showViews();
  draw();
}
// the value an option of the view of index i has now, kept for its name
export function keepViewOption(i, option) {
  const name = gmsh.option.getString(`View[${i}].Name`);
  if(!viewSettings.has(name)) viewSettings.set(name, {});
  viewSettings.get(name)[option] = getViewOption(option, i);
}
// the views not seen yet (made by a run, or opened) given what was kept: that
// for all views, then that of their name; once, so that what a model sets for
// a view, or a key changes, is not written over afterwards
export function settleViews() {
  viewTags().forEach((t, i) => {
    if(settledViews.has(t)) return;
    settledViews.add(t);
    const name = gmsh.option.getString(`View[${i}].Name`);
    const kept = {...allViewSettings, ...(viewSettings.get(name) || {})};
    for(const [option, v] of Object.entries(kept)) setViewOption(option, i, v);
    customRangeOfValues(i);
  });
}
// the first visible view (or the first one), for the items of all views
export function firstView() {
  const tags = viewTags();
  const i = tags.findIndex((t, k) => viewNum(k, 'Visible'));
  return tags[i >= 0 ? i : 0];
}
// the options of a view shown, under it in the Model tab
export function showViewOptions(tag) {
  if(tag === undefined) return;
  viewOptionsOpen.add(tag);
  showTab('modelTab');
  showViews();
  const list = $('viewList');
  const rows = list.querySelectorAll('.viewOptions');
  if(rows.length) rows[0].scrollIntoView({block: 'nearest'});
}
// the menu of a view's button, as the graphical interface's
function viewItems(tag) {
  return menuItems(registry.View, {view: viewTags().indexOf(tag), tag});
}
export function exportView(tag, ext) {
  const i = viewTags().indexOf(tag);
  const name = gmsh.option.getString(`View[${i}].Name`).replace(/[^\w.-]+/g, '_') ||
    `view${tag}`;
  try {
    gmsh.view.write(tag, `/tmp/${name}.${ext}`);
    download(`/tmp/${name}.${ext}`);
  } catch(e) {
    setStatus(e.message, true);
  }
}
