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

// The Post-processing module: the views, each shown or hidden by its box,
// with the menu of its button, and its options under it, kept by the name of
// the view for the views a solver makes again

import {$, download, gmsh, setStatus} from './app.mjs';
import {web} from './gmshweb.mjs';
import {menuItems, registry} from './actions.mjs';
import {getViewOption, optionInput, sectionBlock, setInput, setViewOption, showTab, viewPage, views} from './options.mjs';
import {groupOpen} from './parameters.mjs';
import {draw} from './scene.mjs';
import {popupMenu, showAnimation} from './statusbar.mjs';

// The modules of the graphical interface's tree. Post-processing: the views
// (in the branches their Group option names), each shown or hidden by its box,
// with the menu of its button (its options, its export, the visibility and
// the removal of views). The options of a view are set under it, and only
// there: the sections of the View page of the option window (see
// options.mjs), folded but the first; the page keeps them by the name of the
// view, so that the views a solver makes again at each run get them back, and
// those applied to all the views also go to the views to come (see
// settleViews())
export const viewSettings = new Map(); // view name -> {View.X: value}
export const allViewSettings = {}; // View.X -> value, for every view
export const settledViews = new Set(); // the views (tags) given their settings
export const viewOptionsOpen = new Set(); // the views whose options are shown
// the options shown as sliders, the raise as a fraction of the size of the
// view (see raiseUnit() in options.mjs)
const sliders = {'View.Opacity': null,
                 'View.NormalRaise': {min: -0.5, max: 0.5, step: 0.01}};
// the options a view's name or data makes its own: not given to all the views
const ownOptions = ['View.Name', 'View.Type', 'View.TimeStep', 'View.CustomMin',
  'View.CustomMax', 'View.AxesLabelX', 'View.AxesLabelY', 'View.AxesLabelZ'];
// what the view of index i holds: 1 scalars, 2 vectors, 4 tensors (or-ed)
const viewContent = (i) => web.viewContent(i);
export const viewTags = () => [...gmsh.view.getTags()];
export const viewNum = (i, n) => gmsh.option.getNumber(`View[${i}].${n}`);
// The list is made again only when what it shows changes (the views, their
// names, groups, whether they have several time steps, range and vector type,
// the options shown), not as a run adds time steps: otherwise the values are
// written in its inputs as they are, so that an input being typed in, or a
// row being clicked, while a solver runs (and shows new views several times a
// second) stays where it is
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
    t, name(i), group(i), viewNum(i, 'NbTimeStep') > 1, viewNum(i, 'RangeType'),
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
// the options of a view, under it: the sections of the View page, with the
// rows that apply to what the view holds, and a button that gives them to all
// the views
function viewOptionRows(tag, i) {
  const box = document.createElement('div');
  box.className = 'viewOptions';
  const steps = viewNum(i, 'NbTimeStep');
  const content = viewContent(i), vectors = content & 2, tensors = content & 4;
  // the options that apply to some views only
  const custom = viewNum(i, 'RangeType') === 2;
  const applies = {
    'View.TimeStep': steps > 1, 'View.CustomMin': custom, 'View.CustomMax': custom,
    'View.VectorType': vectors, 'View.ArrowSizeMin': vectors, 'View.ArrowSizeMax': vectors,
    'View.GlyphLocation': vectors, 'View.CenterGlyphs': vectors,
    'View.DisplacementFactor': vectors && viewNum(i, 'VectorType') === 5,
    'View.TensorType': tensors};
  const shown = [];
  for(const sec of viewPage().sections) {
    const sd = sectionBlock(sec, (f) => {
      const option = f.option;
      if(applies[option] === false || applies[option] === 0) return null;
      const kind = option in sliders ? 'range' : f.kind;
      const el = optionInput(kind, option, (v) => setViewOptionOf(tag, option, v),
                             sliders[option]);
      el.title = option.replace('View.', `View[${i}].`);
      if(option === 'View.TimeStep') Object.assign(el, {min: 0, max: steps - 1, step: 1});
      shown.push(option);
      viewUpdates.push((ts) => {
        const k = ts.indexOf(tag);
        if(k < 0) return;
        // the time steps a run adds
        if(option === 'View.TimeStep') el.max = viewNum(k, 'NbTimeStep') - 1;
        if(el !== document.activeElement) setInput(el, kind, getViewOption(option, k));
      });
      return el;
    });
    if(sd) box.appendChild(sd);
  }
  const all = document.createElement('button');
  all.textContent = 'Apply to all views';
  all.title = 'Give these options to all the views, and to the views to come ' +
    '(the name, the plot type, the time step, a custom range and the axes ' +
    'labels stay those of each view)';
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
    if(ownOptions.includes(option)) continue;
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
