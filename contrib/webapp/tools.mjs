// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The tools that take the clicks on the scene until stopped: the query and
// the measurement (as the buttons of the status bar of the FLTK graphical
// user interface), and the operations on the entities picked (selectionDriver,
// through webApp.cpp), with their form, keys and status

import {$, app, canvas, setStatus, status} from './app.mjs';
import {web} from './gmshweb.mjs';
import {moduleOf, showModelName, showPanel} from './actions.mjs';
import {draw, lasso} from './scene.mjs';
import {run, showAll} from './solverClient.mjs';
import {closePopup, showSelection, showSide} from './statusbar.mjs';

// The operations on entities picked in the scene, as the graphical interface
// does them (src/graphics/selectionDriver.cpp, through webApp.cpp): started
// from the menus of the modules, with their fields in the form, what to pick
// in the status bar, and its buttons to end the selection, take back the last
// pick and stop (e, u and q, as in the graphical interface)
let operationChanges = 0, operationName = '';
export function startOperation(item) {
  const name = item.name;
  if(app.busy) return;
  if(!app.modelDir) {
    setStatus('Open a model, or make a new one (Geometry > New)');
    return;
  }
  const json = web.operation(name);
  if(!json) return;
  tool = Tool.Operation;
  operationName = name;
  for(const a of ['query', 'measure'])
    $('statusbar').querySelector(`[data-act=${a}]`).classList.remove('on');
  const fields = JSON.parse(json);
  // (titled by its path in the module: "Boolean › Union")
  showPanel($('module' + moduleOf(item)), item.path.split(' › ').slice(1).join(' › '), fields,
            (n, v) => {
              web.operationValue(n, v);
              toolStatus();
            }, null, [['Stop', 'Stop the operation (q)', stopOperation]]);
  showOperationKeys(true);
  toolStatus();
  draw();
  // nothing to fill in: the scene, on a small screen
  if(app.narrow.matches && !fields.length) showSide(false);
}
export function stopOperation() {
  web.operation('');
  toolStatus();
  draw();
}
export function operationKey(key) {
  web.operationKey(key.charCodeAt(0));
  toolStatus();
  draw();
}
function showOperationKeys(on) {
  for(const k of ['e', 'u', 'q'])
    $('statusbar').querySelector(`[data-act=op_${k}]`).hidden = !on;
}
// what an operation changed: the model's script or its mesh
function operationDone(name) {
  showModelName();
  showAll();
  // the clients told of a new physical group, as the graphical interface does
  if(name.startsWith('physical_')) run('check').then(toolStatus);
}
// The query and the measurement, as the buttons of the status bar of the
// graphical interface: they take over the clicks of the scene (webApp.cpp,
// with the code of the interface in sceneView), until they are clicked again,
// or Escape (or q); what they find is printed in the messages, and pinned to
// the model in boxes the page draws (showNotes())
// (the numbers of gmshWebTool(), and the operation)
export const Tool = {None: 0, Query: 1, Measure: 2, Operation: 3};
export let tool = Tool.None;
// a tool started, or stopped if it is under way
export const toggleTool = (t) => setTool(tool === t ? Tool.None : t);
export function setTool(t) {
  // (the operation under way stops, see gmshWebTool())
  if(tool === Tool.Operation) {
    showPanel(null);
    showOperationKeys(false);
  }
  tool = t;
  web.tool(t);
  for(const [a, n] of [['query', Tool.Query], ['measure', Tool.Measure]])
    $('statusbar').querySelector(`[data-act=${a}]`).classList.toggle('on', tool === n);
  showSelection();
  toolStatus();
  draw();
}
export function toolStatus() {
  // an operation: what it waits for, and what it did
  let text = '';
  if(tool === Tool.Operation) {
    const s = JSON.parse(web.operationState());
    if(s.changes !== operationChanges) {
      operationChanges = s.changes;
      operationDone(operationName);
    }
    // (on a small screen, without the keys, which are buttons there)
    if(s.name) text = app.narrow.matches ? s.status.split('\n')[0] : s.status.replace('\n', ' ');
    else {
      tool = Tool.None;
      showPanel(null);
      showOperationKeys(false);
    }
  }
  if(!tool) {
    if(app.statusBefore && status.textContent === app.statusBefore.tool)
      setStatus(app.statusBefore.text, app.statusBefore.error);
    app.statusBefore = null;
    return;
  }
  if(!app.statusBefore)
    app.statusBefore = {text: status.textContent, error: status.classList.contains('error')};
  app.statusBefore.tool = text || (tool === Tool.Query ?
    'Click to query the model, Ctrl+click to add a query (Escape to stop)' :
    web.measuring() ?
    'Click the second point (Escape to stop)' :
    'Click the first point (Escape to stop)');
  setStatus(app.statusBefore.tool);
}
export function showNotes() {
  const box = $('notes');
  box.textContent = '';
  const n = JSON.parse(web.notes());
  if(!n.notes.length && !n.length) return;
  const at = canvas.getBoundingClientRect();
  const note = (text) => {
    const d = document.createElement('div');
    d.className = 'note';
    d.textContent = text;
    d.style.background = n.tint;
    d.style.color = n.dark ? '#eee' : '#111';
    box.appendChild(d);
    return d;
  };
  // a box below and to the right of its point, or on the other side of it
  // when it would leave the canvas; the length over the middle of its line
  for(const p of n.notes) {
    if(p.x < 0 || p.y < 0 || p.x > at.width || p.y > at.height) continue;
    const d = note(p.text);
    let x = p.x + 10, y = p.y + 10;
    if(x + d.offsetWidth > at.width) x = p.x - 10 - d.offsetWidth;
    if(y + d.offsetHeight > at.height) y = p.y - 10 - d.offsetHeight;
    d.style.left = (at.left + Math.max(0, x)) + 'px';
    d.style.top = (at.top + Math.max(0, y)) + 'px';
  }
  if(n.length) {
    const d = note(n.length.text);
    d.style.left = (at.left + n.length.x - d.offsetWidth / 2) + 'px';
    d.style.top = (at.top + n.length.y - d.offsetHeight - 8) + 'px';
  }
}
// Escape: the lasso, then a popup, then the selection or the tool under way
export function escape() {
  if(web.stopLasso()) {
    lasso.style.display = 'none';
    draw();
  }
  else if(closePopup()) {}
  else if(tool === Tool.Operation) operationKey('q');
  else if(tool) setTool(Tool.None);
}
