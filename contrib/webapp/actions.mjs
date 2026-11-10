// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The action registry (src/common/Actions.cpp): the buttons of the Geometry
// and Mesh modules and the items of the menus, and what the page does for
// them (pageActions, the counterpart of the table of src/fltk/fltkActions.cpp);
// the forms under the modules (shapes, partitions), the script and the mesh
// of the model; the keyboard shortcuts, which run the items

import {$, FS, Module, app, download, gmsh, progress, setStatus} from './app.mjs';
import {web} from './gmshweb.mjs';
import {readClipping} from './clipping.mjs';
import {editFile, editScript} from './editor.mjs';
import {openFiles, openMenu} from './models.mjs';
import {colorScheme, keepOptionOf, optionRow, readOptions, setColorScheme, showOptions, showTab} from './options.mjs';
import {draw} from './scene.mjs';
import {ModShift, installShortcuts, shortcutsHelp} from './shortcuts.js';
import {run, showAll} from './solverClient.mjs';
import {fullscreenElement, fullscreenEnabled, installApp, openQuickMenu, playing, popupMenu,
        rewindAnimation, sceneAction, setPlaying, toggleFullscreen, toggleMouseSelection,
        toggleSide} from './statusbar.mjs';
import {Tool, escape, operationKey, setTool, startOperation, stopOperation, toggleTool, tool} from './tools.mjs';
import {exportView, firstView, showViewOptions, viewOptionsOpen} from './views.mjs';

// The actions of the modules: buttons, and menus as the tree of the graphical
// interface has them
// a row of buttons [label, title, action, opens a menu], after a label
function buttonRow(parent, items, label = '') {
  const row = document.createElement('div');
  row.className = 'buttons fill';
  if(label) {
    const s = document.createElement('span');
    s.textContent = label;
    row.appendChild(s);
  }
  for(const [text, title, act, menu] of items) {
    const b = document.createElement('button');
    b.textContent = text;
    b.title = title;
    if(menu) b.className = 'menuButton';
    b.addEventListener('click', act);
    row.appendChild(b);
  }
  parent.appendChild(row);
  return row;
}
// a button of a row that opens a menu of items(): [label, action] or the
// heading of a section (see popupMenu())
const menuButton = (text, title, items) => [text + ' ▾', title, (e) => {
  const r = e.currentTarget.getBoundingClientRect();
  popupMenu(items, r.left, r.bottom + 2, {owner: e.currentTarget});
}, true];
// The form under the buttons of a module: the fields of a shape to add, or
// those of the operation under way, each given to change(name, value) ("1"
// or "0" for a check box), Enter in one doing enter(); then its buttons
export function showPanel(module, title, fields = [], change, enter, buttons = []) {
  const panel = $('panel');
  panel.textContent = '';
  panel.hidden = !module;
  if(!module) return;
  module.appendChild(panel);
  module.open = true;
  const name = document.createElement('div');
  name.className = 'name';
  name.textContent = title;
  panel.appendChild(name);
  const inputs = [];
  for(const f of fields) {
    let el;
    if(f.kind === 'check' || f.kind === 'text' || f.kind === 'range') {
      el = document.createElement('input');
      el.type = f.kind === 'check' ? 'checkbox' : f.kind;
      el.spellcheck = false;
      if(f.kind === 'range') Object.assign(el, {min: f.min, max: f.max, step: f.step});
      if(f.kind === 'check') el.checked = f.value === '1';
      else el.value = f.value;
    }
    else {
      el = document.createElement('select');
      for(const c of f.kind.split('|')) el.add(new Option(c, c));
      el.value = f.value;
    }
    const value = () => el.type === 'checkbox' ? (el.checked ? '1' : '0') : el.value;
    el.addEventListener(f.kind === 'range' ? 'input' : 'change', () => change(f.name, value()));
    if(enter) el.addEventListener('keydown', (e) => { if(e.key === 'Enter') enter(); });
    panel.appendChild(optionRow(f.name, el));
    inputs.push(el);
  }
  buttonRow(panel, buttons);
  // (not on a phone, whose keyboard would cover the form)
  if(inputs.length && !app.narrow.matches) inputs[0].focus({preventScroll: true});
}
// Mesh: what the graphical interface does without a selection, through the
// API, and the operations on selected entities
// an operation on the mesh: what is being done in the status, then how long
// it took and the size of the mesh, or the error
function meshAction(doing, done, act) {
  if(app.busy) return;
  setStatus(doing + '...');
  progress(true);
  setTimeout(() => {
    const t0 = performance.now();
    app.lastError = '';
    try {
      act();
    } catch(e) {
      app.lastError = app.lastError || e.message;
    }
    // (with errors: in the messages, opened, which end with a summary)
    const text = `${done} in ${(performance.now() - t0).toFixed(0)} ms, ` +
      `${gmsh.option.getNumber('Mesh.NbNodes')} nodes` +
      (app.lastError ? ', with errors (see the messages)' : '');
    setStatus(text, !!app.lastError);
    if(app.lastError) $('log').open = true;
    progress(false);
    draw();
  }, 20);
}
// the mesh, as a .msh file named after the model
function saveMesh() {
  const path = '/tmp/' + ($('model').textContent || 'untitled').replace(/\.[^.]*$/, '') + '.msh';
  try {
    gmsh.write(path);
    download(path);
  } catch(e) {
    setStatus(e.message, true);
  }
}
// Geometry: a new model, the script edited, reloaded and saved, the shapes
// added to it as the dialog of the graphical interface adds them, with its
// fields and their defaults (see gmshWebShapes() in webApp.cpp), and the
// operations on selected entities. The fields of a shape, as the dialog's,
// keep what was typed in them
let shapes;
// the script of the model: its .geo file, if it is one
export function scriptFile() {
  const f = gmsh.model.getFileName();
  return /\.geo$/i.test(f) && FS.analyzePath(f).exists ? f : '';
}
// an empty .geo file, with the OpenCASCADE kernel, as a new model
async function newModel() {
  const geo = `// Gmsh project created on ${new Date().toString()}\n` +
    'SetFactory("OpenCASCADE");\n';
  await openFiles([['untitled.geo', new TextEncoder().encode(geo)]]);
  $('moduleGeometry').open = true;
}
// the view fitted to a model that was empty (a new one), or kept
const isEmpty = () => !gmsh.model.getEntities().length;
function fitIfWasEmpty(wasEmpty) {
  if(!wasEmpty || isEmpty()) return;
  web.resetView();
  draw();
}
// the script read again, with what the solvers check
export async function reloadScript() {
  const wasEmpty = isEmpty();
  gmsh.onelab.setChanged('Gmsh', 3);
  await run('check');
  fitIfWasEmpty(wasEmpty);
}
function saveScript() {
  const f = scriptFile();
  if(f) download(f, true);
  else setStatus('No script to save: open a .geo model, or make a new one');
}
// the form of a shape
function startShape(shape) {
  if(tool === Tool.Operation) stopOperation();
  const {label, fields} = shapes[shape];
  showPanel($('moduleGeometry'), label,
            fields.map(([name, value]) => ({name, kind: 'text', value})),
            (name, value) => { fields.find((f) => f[0] === name)[1] = value; },
            () => addShape(shape),
            [['Add', `Add the ${label.toLowerCase()} to the script`, () => addShape(shape)],
             ['Close', 'Close the form', () => showPanel(null)]]);
}
// the model's name, which changes when a model that is not a .geo file is
// given one by the first command added to it
export function showModelName() {
  const f = gmsh.model.getFileName();
  $('model').textContent = f.slice(f.lastIndexOf('/') + 1);
}
// a shape added to the script of the model, a new one if there is none
async function addShape(shape) {
  if(app.busy) return;
  for(const el of $('panel').querySelectorAll('input')) el.dispatchEvent(new Event('change'));
  if(!app.modelDir) await newModel();
  const wasEmpty = isEmpty();
  app.lastError = '';
  const errors = web.addShape(shape, shapes[shape].fields.map((f) => f[1]).join('\n'));
  showModelName();
  showAll();
  fitIfWasEmpty(wasEmpty);
  const text = errors ? `Not added: ${app.lastError.replace(/^Error *: */, '')}` :
    `Added a ${shapes[shape].label.toLowerCase()} to ${$('model').textContent}`;
  setStatus(text, !!errors);
}
// the mesh partitioned, into the number of parts the form of the module asks
let partitions = '4';
function partitionForm() {
  const go = () => {
    for(const el of $('panel').querySelectorAll('input')) el.dispatchEvent(new Event('change'));
    showPanel(null);
    meshAction('Partition mesh', 'Partition mesh',
               () => gmsh.model.mesh.partition(Number(partitions)));
  };
  showPanel($('moduleMesh'), 'Partition',
            [{name: 'Number of partitions', kind: 'text', value: partitions}],
            (name, value) => { partitions = value; }, go,
            [['Partition', 'Partition the mesh', go],
             ['Close', 'Close the form', () => showPanel(null)]]);
}
// The action registry (src/common/Actions.cpp): the menus of the page and
// of the graphical interface, the buttons of the modules included, and what
// their items do (see gmshWebActions() in webApp.cpp)
export let registry;
// The actions the page does, by name, in the order of the menus of
// Actions.cpp (an item whose name is not here is not shown; the table of the
// FLTK graphical user interface is at the top of src/fltk/fltkActions.cpp): what each
// does (view: the index of the view of a menu of a view, tag its tag, mods
// the modifiers of the key), its check mark, and whether the page has it now
// (always if not said)
const pageActions = {
  // Geometry: the script
  'model_new': {run: newModel},
  'script_reload': {run: reloadScript},
  'script_edit': {run: editScript},
  'script_save': {run: saveScript},
  // Mesh
  'mesh_save': {run: saveMesh},
  'mesh_partition': {run: partitionForm},
  // Quick access: the scene
  'query': {run: () => toggleTool(Tool.Query), check: () => tool === Tool.Query},
  'measure': {run: () => toggleTool(Tool.Measure), check: () => tool === Tool.Measure},
  'window_full_screen': {run: toggleFullscreen, check: () => !!fullscreenElement(),
                         available: () => !!fullscreenEnabled},
  'app_install': {run: installApp, available: () => !!window.installPrompt},
  'options_general': {run: () => showOptions('General')},
  'options_geometry': {run: () => showOptions('Geometry')},
  'options_mesh': {run: () => showOptions('Mesh')},
  'options_views': {run: () => showViewOptions(firstView())},
  // View: the menu of a view
  'view_options': {run: (view, tag) => { if(!viewOptionsOpen.delete(tag)) viewOptionsOpen.add(tag); },
                   check: (view, tag) => viewOptionsOpen.has(tag)},
  'view_export_pos': {run: (view, tag) => exportView(tag, 'pos')},
  'view_export_msh': {run: (view, tag) => exportView(tag, 'msh')},
  // Status bar (the buttons are made from the registry, see statusbar.mjs)
  'quick_access': {run: (view, tag, mods, el) => {
    const r = el ? el.getBoundingClientRect() : {left: 20, top: innerHeight - 20};
    openQuickMenu(r.left, r.top, true);
  }},
  'view_x': {run: (view, tag, mods) => sceneAction('view_x', mods)},
  'view_y': {run: (view, tag, mods) => sceneAction('view_y', mods)},
  'view_z': {run: (view, tag, mods) => sceneAction('view_z', mods)},
  'view_3d': {run: (view, tag, mods) => sceneAction('view_3d', mods)},
  'view_rotate': {run: (view, tag, mods) => { if(web.rotate(mods & ModShift ? 1 : 0)) draw(); }},
  'view_1_1': {run: (view, tag, mods) => sceneAction('view_1_1', mods)},
  'mouse_selection': {run: () => toggleMouseSelection()},
  'anim_rewind': {run: rewindAnimation},
  'time_step_prev': {run: () => sceneAction('time_step_prev')},
  'anim_play': {run: () => setPlaying(!playing()), check: () => playing()},
  'time_step_next': {run: () => sceneAction('time_step_next')},
  // Menu bar: File
  'file_new': {run: () => newModel()},
  'file_open': {run: () => openMenu(true)},
  // Tools
  'options': {run: () => showOptions()},
  'visibility': {run: () => showTab('visTab')},
  'clipping': {run: () => showTab('clipTab')},
  // Window
  'menu_show_hide': {run: () => toggleSide()},
  // Help
  'help_keys': {run: () => $('keysDialog').showModal()},
  // Keys: the keys in no menu
  'project_reload': {run: () => run('check')},
  'solver_run': {run: () => run('compute')},
  'selection_end': {run: () => operationKey('e'), available: () => tool === Tool.Operation},
  'selection_undo': {run: () => operationKey('u'), available: () => tool === Tool.Operation},
  'selection_quit': {run: () => tool === Tool.Operation ? operationKey('q') : setTool(Tool.None),
                     available: () => !!tool},
  'escape': {run: () => escape()},
  'options_solver': {run: () => showTab('modelTab')},
  'options_post': {run: () => showViewOptions(firstView())},
  'view_prev': {run: () => sceneAction('view_prev')},
  'view_next': {run: () => sceneAction('view_next')}
};
// the programs written next to the script (the items script_edit_py... of
// the Geometry module), in the editor
function editProgram(name) {
  editFile(web.scriptProgram(name));
}
// the check mark of an item in Gmsh: -1 for none, 0 or 1, -2 if it does not
// apply now
const itemCheck = (item) => web.actionCheck(item.id);
// whether the page has an item now
export const canRunItem = (item) => (item.kind !== 'action' || !!item.run) && item.available();
// whether a menu has an item the page has now
const canRunAnyItem = (menu) =>
  menu.items.some((it) => it.kind === 'menu' ? canRunAnyItem(it) : canRunItem(it));
// the item of a name (that of a key), in any menu
function findItem(name, menu = {items: Object.values(registry)}) {
  for(const it of menu.items) {
    const found = it.kind === 'menu' ? findItem(name, it) : it.name === name && it;
    if(found) return found;
  }
  return null;
}
// the module of an item ('Geometry', 'Mesh' or '')
export const moduleOf = (item) =>
  ['Geometry', 'Mesh'].find((m) => item.path.startsWith(m + ' ›')) || '';
// What an item does, clicked or by a key of its name: an operation, a shape,
// or an action (view: the index of the view of a menu of a view, tag its tag;
// mods: the modifiers of the key; el: the button clicked, for a menu to open
// at it)
export async function runItem(item, {view = -1, tag, mods = 0, el = null} = {}) {
  if(item.kind === 'operation') startOperation(item);
  else if(item.kind === 'shape') startShape(item.name);
  else await item.run(view, tag, mods, el);
}
// the keys of an item, as the platform names them ("Alt+x, Alt+Shift+x"), or ''
export function keyLabels(name) {
  return shortcuts.filter((s) => s.action === name).map((s) => s.label).join(', ');
}
// what an action does in Gmsh (see RunItem()): on the mesh, timed with the
// size of the mesh in the status; on the script, of a new model if there is
// none; an option, kept (see keepOption())
async function gmshAction(item, view) {
  if(app.busy) return;
  const module = moduleOf(item);
  const run = () => web.action(item.id, view);
  // (an option, named as it is: kept)
  if(item.name.includes('.')) {
    run();
    keepOptionOf(item.name.split('=')[0], view);
    return;
  }
  if(module === 'Mesh') {
    meshAction(item.path, item.path, run);
    return;
  }
  if(module === 'Geometry' && !app.modelDir) await newModel();
  app.lastError = '';
  run();
  if(!module) return;
  showModelName();
  showAll();
  const text = app.lastError ? app.lastError.replace(/^Error *: */, '') :
    `${item.path} in ${$('model').textContent}`;
  setStatus(text, !!app.lastError);
}
// the items of a menu as popupMenu() shows them: a submenu as {label, items}
// (one level, as in the graphical interface: a submenu in a submenu as a
// heading), a group set apart by a separator ('')
export function menuItems(menu, opts = {}, level = 0) {
  const items = [];
  const add = (m) => {
    for(const it of m.items) {
      if(it.kind === 'menu') {
        if(!canRunAnyItem(it)) continue;
        if(it.label && !level) items.push({label: it.label, items: menuItems(it, opts, 1)});
        else {
          items.push(it.label || '');
          add(it);
          items.push('');
        }
      }
      else if(canRunItem(it))
        items.push([it.label, () => runItem(it, opts), it.check(opts.view, opts.tag)]);
    }
  };
  add(menu);
  // (no separator at the ends, nor two in a row)
  return items.filter((x, i, a) => x !== '' || (i > 0 && i < a.length - 1 && a[i - 1] !== ''));
}
// the buttons of a module, by rows: a menu as a button that opens it
function moduleButtons(module) {
  const d = $('module' + module);
  for(const row of registry[module].items) {
    const buttons = [];
    for(const b of row.items) {
      if(b.kind !== 'menu') {
        if(canRunItem(b)) buttons.push([b.label, b.help, () => runItem(b)]);
      }
      else if(canRunAnyItem(b))
        buttons.push(menuButton(b.label, b.help, () => menuItems(b)));
    }
    // (on more lines if it must)
    if(buttons.length) buttonRow(d, buttons).classList.add('wrap');
  }
}
// a key runs the item of its action, as a click on it does (shortcuts.js),
// then what it changed is shown, the page following the scene's colour
// scheme
let shortcuts;

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  shapes = Object.fromEntries(
    JSON.parse(web.shapes()).map(
      (shape) => [shape.name, shape]));
  registry = JSON.parse(web.actions());
  // Each item given its path in its menu ("Mesh › 2D"), which says what it does
  // in the status and the forms (the names of the items are keys), and, for an
  // action, what it does (none if the page does not have it), when it applies
  // and its check mark: Gmsh's (see gmshAction()), or the page's
  for(const [menu, root] of Object.entries(registry)) {
    (function setItems(m, path) {
      for(const it of m.items) {
        const p = it.label ? [...path, it.label] : path;
        if(it.kind === 'menu') {
          setItems(it, p);
          continue;
        }
        it.path = p.join(' › ');
        if(it.kind === 'action' && !it.gmsh) {
          const a = pageActions[it.name] ||
            (/^script_edit_/.test(it.name) ? {run: () => editProgram(it.name)} : {});
          it.run = a.run;
          it.available = a.available || (() => true);
          it.check = a.check || (() => undefined);
        }
        else {
          if(it.kind === 'action') it.run = (view) => gmshAction(it, view);
          it.available = () => itemCheck(it) !== -2;
          it.check = () => {
            const c = itemCheck(it);
            return c >= 0 ? !!c : undefined;
          };
        }
      }
    })(root, [menu]);
  }
  moduleButtons('Geometry');
  moduleButtons('Mesh');
  shortcuts = installShortcuts(Module, (action, mods) => {
    const item = findItem(action);
    if(!item || !canRunItem(item)) return false;
    runItem(item, {mods}).then(() => {
      const c = gmsh.option.getNumber('General.ColorScheme');
      if(c !== colorScheme) setColorScheme(c);
      readOptions();
      readClipping();
      draw();
    });
    return true;
  });
  // the keys of the items the page has, in the list (whether they apply now or
  // not)
  for(const r of shortcutsHelp(shortcuts, (a) => {
    const item = findItem(a);
    return !!item && (item.kind !== 'action' || !!item.run);
  })) {
    const tr = $('keysTable').insertRow();
    tr.insertCell().textContent = r.label;
    tr.insertCell().textContent = r.help;
  }
  $('keys').addEventListener('click', () => $('keysDialog').showModal());
}
