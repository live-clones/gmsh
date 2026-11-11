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

// The ONELAB web app: Gmsh, through the Gmsh JavaScript API (gmsh.mjs) and
// the functions of webApp.cpp (gmshweb.mjs), with GetDP, linked in the same
// module but run in a web worker (solver.js), as the FLTK graphical user
// interface runs it in a process of its own. ("The graphical interface", in
// the comments of the page, is that interface, src/fltk, which the page
// follows.) A model is opened from files, a folder, a zip archive, or a URL
// (?zip=<url>, with &open=<file> for a zip of several models, or ?model=<url
// of the .pro>&files=<other files, next to it, separated by commas>).
//
// The page is in modules, one per panel, each with its functions and a
// build() that makes its part of the page once Gmsh is loaded, called below:
// - app.mjs: what they share (Gmsh, the state, the status and the messages);
// - gmshweb.mjs: the functions of webApp.cpp;
// - scene.mjs, statusbar.mjs, tools.mjs: the scene, the status bar, the tools
//   that take the clicks;
// - actions.mjs: the modules' buttons and the menus (src/common/Actions.cpp),
//   what the page does for them (pageActions) and the keyboard shortcuts;
// - parameters.mjs, views.mjs, solverClient.mjs: the ONELAB parameters, the
//   views and the loop that runs Gmsh and the solvers;
// - options.mjs, clipping.mjs, visibility.mjs: the other tabs of the panel;
// - editor.mjs, models.mjs: the editor of a file, the models opened.
// To add a panel: a module with its build(), listed here; a menu item or a
// module button: see Actions.h, then pageActions in actions.mjs.
import createGmsh from './build/gmsh.mjs';
import {app, setGmsh, setStatus, log, progress, $} from './app.mjs';
import * as scene from './scene.mjs';
import * as statusbar from './statusbar.mjs';
import * as parameters from './parameters.mjs';
import * as options from './options.mjs';
import * as clipping from './clipping.mjs';
import * as visibility from './visibility.mjs';
import * as actions from './actions.mjs';
import * as editor from './editor.mjs';
import * as views from './views.mjs';
import * as solverClient from './solverClient.mjs';
import * as models from './models.mjs';
import {openFiles, fetchFile} from './models.mjs';
import {draw} from './scene.mjs';

// the WebAssembly code, compiled once for the page and for the solver's
// worker as it is downloaded, with how much has come in the status: the size
// is the response's, or that of the file deploy.sh puts next to it when the
// server compresses the response (whose length is then the compressed one)
async function compileWasm(url) {
  const r = await fetch(url);
  let total = r.headers.get('Content-Encoding') ? 0 :
    Number(r.headers.get('Content-Length')) || 0;
  if(!total) {
    try { total = Number(await (await fetch(url + '.size')).text()) || 0; } catch(e) {}
  }
  let got = 0;
  progress(total ? 0 : true);
  const counted = r.body.pipeThrough(new TransformStream({
    transform(chunk, out) {
      got += chunk.length;
      setStatus(`Loading Gmsh and GetDP: ${(got / 1e6).toFixed(0)}` +
        (total ? ` of ${(total / 1e6).toFixed(0)} MB` : ' MB'));
      if(total) progress(Math.min(1, got / total));
      out.enqueue(chunk);
    }
  }));
  const body = new Response(counted, {headers: {'Content-Type': 'application/wasm'}});
  try {
    return await WebAssembly.compileStreaming(body);
  } catch(e) { // no streaming compilation: again, as a whole
    return WebAssembly.compile(await (await fetch(url)).arrayBuffer());
  }
}
// (a module that cannot be loaded, or started, said in the status)
const cannotLoad = (e) => {
  progress(false);
  setStatus('Could not load Gmsh: ' + (e.message || e), true);
  throw e;
};
const wasm = await compileWasm(new URL('./build/libgmsh.wasm', import.meta.url))
  .catch(cannotLoad);
setStatus('Starting...');
progress(true);
const gmsh = await createGmsh({
  canvas: $('canvas'), print: log, printErr: log,
  instantiateWasm: (imports, done) => {
    WebAssembly.instantiate(wasm, imports).then((i) => done(i, wasm))
      .catch((e) => { try { cannotLoad(e); } catch(x) {} });
    return {};
  },
}).catch(cannotLoad);
setGmsh(gmsh);
gmsh.initialize([], false);
gmsh.option.setNumber('General.Terminal', 1);
// (the questions Gmsh asks answered by default, not on the console, which a
// browser would ask with a prompt)
gmsh.option.setNumber('General.NoPopup', 1);

// the parts of the page, in an order where each finds what it needs built
for(const part of [scene, actions, statusbar, parameters, options, clipping,
                   visibility, editor, views, models])
  if(part.build) part.build();
solverClient.build(wasm);

$('run').disabled = $('reset').disabled = false;
setStatus('Open a model, or drop its files here');
progress(false);
const params = new URLSearchParams(location.search);
try {
  if(params.get('zip')) {
    const url = params.get('zip');
    await openFiles([[url.split('/').pop(), await fetchFile(url)]],
                    params.get('open') || '');
  }
  else if(params.get('model')) {
    const url = params.get('model');
    const base = url.slice(0, url.lastIndexOf('/') + 1);
    const names = [url.slice(base.length)].concat(
      (params.get('files') || '').split(',').filter((s) => s));
    const entries = [];
    for(const n of names) entries.push([n, await fetchFile(base + n)]);
    await openFiles(entries);
  }
} catch(e) {
  setStatus(e.message);
  progress(false);
}
draw();
