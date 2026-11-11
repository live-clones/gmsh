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

// What the page calls in Gmsh besides its API: the functions of webApp.cpp
// (gmshWeb*, see the comments there), each as a function of web
import {Module} from './app.mjs';

const call = (name, ret, types, args) => Module.ccall('gmshWeb' + name, ret, types, args);
const N = 'number', S = 'string';
// a function of webApp.cpp that writes doubles in a buffer: the values, or
// null if it returned 0
function doubles(name, count) {
  const xy = Module._malloc(8 * count);
  const ok = call(name, N, [N], [xy]);
  const v = ok ? Array.from(Module.HEAPF64.subarray(xy / 8, xy / 8 + count)) : null;
  Module._free(xy);
  return v;
}

export const web = {
  // the scene (see scene.mjs)
  draw: (w, h, dpr) => call('Draw', N, [N, N, N], [w, h, dpr]),
  drawStudio: (w, h, dpr, budget) => call('DrawStudio', N, [N, N, N, N], [w, h, dpr, budget]),
  mouse: (kind, x, y, w, h, button, wheel, mods) =>
    call('Mouse', N, [N, N, N, N, N, N, N, N], [kind, x, y, w, h, button, wheel, mods]),
  pinch: (kind, x, y, d) => call('Pinch', N, [N, N, N, N], [kind, x, y, d]),
  mouseLeft: () => call('MouseLeft', null, [], []),
  // what the pointer is over, and where the box hangs: [text, x, y]
  hoverText: () => {
    const xy = Module._malloc(2 * 8);
    const text = call('HoverText', S, [N], [xy]);
    const a = Module.HEAPF64.subarray(xy / 8, xy / 8 + 2);
    const r = [text, a[0], a[1]];
    Module._free(xy);
    return r;
  },
  crossCursor: () => call('CrossCursor', N, [], []),
  // the lasso being drawn: [x0, y0, x1, y1], or null
  lasso: () => doubles('Lasso', 4),
  stopLasso: () => call('StopLasso', N, [], []),
  rotate: (shift) => call('Rotate', N, [N], [shift]),
  resetView: () => call('ResetView', null, [], []),
  view: (action, mods) => call('View', N, [S, N], [action, mods]),
  colorScheme: (dark) => call('ColorScheme', N, [N], [dark]),
  // the tools and the operations (see tools.mjs)
  tool: (t) => call('Tool', N, [N], [t]),
  measuring: () => call('Measuring', N, [], []),
  notes: () => call('Notes', S, [], []),
  operation: (name) => call('Operation', S, [S], [name]),
  operationValue: (name, value) => call('OperationValue', null, [S, S], [name, value]),
  operationKey: (key) => call('OperationKey', null, [N], [key]),
  operationState: () => call('OperationState', S, [], []),
  // the action registry, the shapes and the script (see actions.mjs, editor.mjs)
  actions: () => call('Actions', S, [], []),
  action: (id, view) => call('Action', N, [N, N], [id, view]),
  actionCheck: (id) => call('ActionCheck', N, [N], [id]),
  shapes: () => call('Shapes', S, [], []),
  addShape: (shape, values) => call('AddShape', N, [S, S], [shape, values]),
  scriptProgram: (name) => call('ScriptProgram', S, [S], [name]),
  scriptStyles: (file, text) => call('ScriptStyles', S, [S, S], [file, text]),
  // the options, the views and the colours (see options.mjs, views.mjs,
  // parameters.mjs)
  optionChoices: (option) => call('OptionChoices', S, [S], [option]),
  optionRange: (option) => call('OptionRange', S, [S], [option]),
  viewContent: (i) => call('ViewContent', N, [N], [i]),
  color: (name) => call('Color', N, [S], [name]),
  readableColor: (rgb, bg, fg, dark, what) =>
    call('ReadableColor', N, [N, N, N, N, N], [rgb, bg, fg, dark, what]),
  // the ONELAB loop (see solverClient.mjs)
  onelabSet: (json) => call('OnelabSet', N, [S], [json]),
  onelabStart: (action) => call('OnelabStart', null, [S], [action]),
  onelabGmsh: (pass) => call('OnelabGmsh', S, [S], [pass]),
  onelabNext: (pass) => call('OnelabNext', N, [S], [pass]),
  onelabMerge: (name) => call('OnelabMerge', null, [S], [name]),
  onelabUpdateGraphs: () => call('OnelabUpdateGraphs', null, [], []),
  onelabForgetSolvers: () => call('OnelabForgetSolvers', null, [], []),
  errorCount: () => call('ErrorCount', N, [], []),
  // the strokes of an icon (see IconStrokes.h), for the status bar
  icon: (name) => call('Icon', S, [S], [name]),
  // the files (see models.mjs)
  unzip: (zip, dir) => call('Unzip', null, [S, S], [zip, dir]),
};
