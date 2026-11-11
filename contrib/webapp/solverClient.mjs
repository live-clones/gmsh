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

// The ONELAB loop (check, compute, reset) as the FLTK graphical user
// interface runs it: Gmsh here, then the solvers in the worker of solver.js,
// whose results are merged as they come; and the Run and Reset buttons

import {$, FS, app, gmsh, log, progress, setStatus} from './app.mjs';
import {web} from './gmshweb.mjs';
import {readClipping} from './clipping.mjs';
import {listFiles, writeFile} from './files.mjs';
import {readOptions} from './options.mjs';
import {getParameters, setParameter, showParameters} from './parameters.mjs';
import {draw} from './scene.mjs';
import {showSide} from './statusbar.mjs';
import {showViews} from './views.mjs';
import {readVisibility} from './visibility.mjs';

// The solver's worker (solver.js): GetDP runs there, while the page merges
// what it is sent as it comes and stays free, as the graphical interface does
// with a solver's process. Stopping the solver ends the worker, a new one
// taking its place.
export let worker = null, workerReady = null;
export let sent = new Map();
// what ends the solver's run under way
let solverDone = null;
// whether the worker failed (to start, or in a run, which may leave its
// module broken): the next run starts a new one
let workerFailed = false;
function startWorker() {
  worker = new Worker(new URL('./solver.js', import.meta.url), {type: 'module'});
  sent = new Map();
  workerFailed = false;
  // true once it is ready, false if it failed to start
  let started;
  workerReady = new Promise((r) => { started = r; });
  worker.onmessage = (e) => {
    const m = e.data;
    if(m.type === 'ready') started(true);
    else if(m.type === 'log') log(m.text);
    else if(m.type === 'merge') solverMerge(m);
    else if(m.type === 'db') solverRefresh(m);
    else if(m.type === 'done') solverEnd(m);
    else if(m.type === 'failed') failed(m.text);
  };
  const failed = (text) => {
    log('Error   : the solver stopped: ' + text);
    workerFailed = true;
    started(false);
    solverEnd({errors: 1});
  };
  worker.onerror = (e) => failed(e.message);
  worker.postMessage({type: 'init', module: wasm});
}
// a file the solver wrote, written here too, not to be sent back
function fromSolver(path, data) {
  if(!path.startsWith('/')) path = FS.cwd() + '/' + path;
  writeFile(FS, path, data);
  sent.set(path, FS.stat(path).mtime.getTime());
}
// the files of the model the worker does not have as they are
function changedFiles() {
  const files = [], transfer = [];
  for(const [path, time] of listFiles(FS, app.modelDir)) {
    if(sent.get(path) === time) continue;
    const data = FS.readFile(path);
    files.push([path, data]);
    transfer.push(data.buffer);
    sent.set(path, time);
  }
  return {files, transfer};
}
// the database the worker sent, with the graphs asked for here since it was
// given the page's (see setGraph())
export const graphEdits = new Map();
function setDatabase(db) {
  // (one that cannot be read leaves the parameters as they are)
  try {
    JSON.parse(db);
  } catch(e) {
    log('Error   : could not read the database of the solver: ' + e.message);
    return;
  }
  gmsh.onelab.clear();
  gmsh.onelab.set(db);
  if(!graphEdits.size) return;
  for(const p of getParameters()) {
    if(!graphEdits.has(p.name)) continue;
    p.attributes = Object.assign({}, p.attributes, {Graph: graphEdits.get(p.name)});
    setParameter(p);
  }
}
// a solver, with the arguments gmshWebOnelabGmsh() gives: its errors
function solve(solver) {
  if(workerFailed) {
    worker.terminate();
    startWorker();
  }
  return new Promise((done) => {
    // (set before the worker is ready, for the Stop button to end the wait)
    solverDone = done;
    workerReady.then((ok) => {
      if(solverDone !== done) return; // stopped meanwhile
      if(!ok) return; // (solverEnd() has been called)
      const {files, transfer} = changedFiles();
      worker.postMessage({type: 'run', dir: app.modelDir, cwd: FS.cwd(), files,
                          db: gmsh.onelab.get(), args: solver.args}, transfer);
      // the worker has the graphs asked for now
      graphEdits.clear();
    });
  });
}
// What the solver asks to show, with the database as it is then, and the
// database when it asks for a refresh (e.g. a value added to an output drawn
// on a graph). They are taken in turns, the latest of each file only: a
// solver writes a file again with all it had (e.g. the time steps so far),
// faster than it is read here as it grows, and the page would fall behind
// (the graphical interface is held back by the socket instead)
const pendingFiles = new Map();
let pendingDb = null, pendingTimer = 0;
function solverMerge(m) {
  pendingFiles.set(m.name, m.data);
  solverRefresh(m);
}
function solverRefresh(m) {
  pendingDb = m.db;
  if(!pendingTimer) pendingTimer = setTimeout(showPending, 0);
}
function showPending() {
  pendingTimer = 0;
  const files = [...pendingFiles];
  pendingFiles.clear();
  for(const [name, data] of files) fromSolver(name, data);
  if(pendingDb) setDatabase(pendingDb);
  pendingDb = null;
  for(const [name] of files)
    web.onelabMerge(name);
  showSolverProgress();
}
// what the solver changed: the graphs made again from the parameters, as the
// graphical interface does on a refresh
export function showSolverProgress() {
  web.onelabUpdateGraphs();
  showParameters();
  showViews();
  readOptions();
  draw();
}
function solverEnd(m) {
  // what is still to show first, before the final database
  if(pendingTimer) {
    clearTimeout(pendingTimer);
    showPending();
  }
  for(const [path, data] of m.files || []) fromSolver(path, data);
  if(m.db) setDatabase(m.db);
  if(m.failed) workerFailed = true;
  const done = solverDone;
  solverDone = null;
  if(done) done(m.errors);
}
let stopping = false;
function stopSolver() {
  stopping = true;
  if(!solverDone) return;
  worker.terminate();
  log('Info    : Stopped the solver');
  solverEnd({errors: 0});
  startWorker();
}
// (a timer, not an animation frame, which a page in the background never gets)
const nextFrame = () => new Promise((r) => setTimeout(r, 20));
export function showAll() {
  showParameters();
  showViews();
  readOptions();
  readClipping();
  readVisibility();
  draw();
}
export async function run(action) {
  if(app.busy) return;
  app.busy = true;
  stopping = false;
  $('reset').disabled = true;
  $('run').textContent = 'Stop';
  app.busyLabel = action === 'compute' ? 'Computing' : 'Checking';
  setStatus(app.busyLabel + '...');
  progress(true);
  app.lastError = '';
  // the status shown before Gmsh's part, which the page waits for
  await nextFrame();
  const t0 = performance.now();
  const pass = action === 'reset' ? 'check' : action;
  let errors = 0;
  try {
    web.onelabStart(action);
    do {
      const solvers = JSON.parse(
        web.onelabGmsh(pass));
      showAll();
      for(const s of solvers) {
        if(stopping) break;
        errors += await solve(s);
      }
    } while(!stopping &&
            web.onelabNext(pass));
    errors += web.errorCount();
  } catch(e) {
    // (an error of the file system is not an Error, but has a name)
    log('*** ' + (e.message || e.name || e));
    errors++;
  }
  const ms = (performance.now() - t0).toFixed(0);
  app.busy = false;
  app.busyLabel = '';
  progress(false);
  $('reset').disabled = false;
  $('run').textContent = 'Run';
  showAll();
  // an error in the status bar, in full in the messages
  const error = app.lastError.replace(/^Error *: */, '') || `${errors} error(s)`;
  const text = stopping ? 'Stopped' :
    errors ? (app.hint ? app.hint + ' (' + error + ')' : error) :
    `${action === 'compute' ? 'Computed' : 'Checked'} in ${ms} ms`;
  setStatus(text, !!errors && !stopping);
  if(errors && !stopping) $('log').open = true;
}

// the page built, once Gmsh is loaded (see main.mjs): the worker started
// with the compiled code
let wasm;
export function build(code) {
  wasm = code;
  startWorker();
  $('run').addEventListener('click', () => {
    if(app.busy) {
      stopSolver();
      return;
    }
    if(app.narrow.matches) showSide(false);
    run('compute');
  });
  $('reset').addEventListener('click', () => run('reset'));
}
