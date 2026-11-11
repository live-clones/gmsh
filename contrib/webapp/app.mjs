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

// What every part of the page shares: Gmsh (the module made by main.mjs, its
// API and file system), the state the parts read and set, the status bar and
// the messages, the progress bar, and the download of a file. It imports
// nothing of the page, so that it is ready before every other part



// the Gmsh API (api/gmsh.mjs), the Emscripten module and its file system, set
// once the module is loaded (see main.mjs)
export let gmsh = null, Module = null, FS = null;
export function setGmsh(g) {
  gmsh = g;
  Module = g.lib;
  FS = Module.FS;
}

// the state shared by the parts of the page
export const app = {
  // while a model is checked or computed (see run() in solverClient.mjs)
  busy: false,
  // the last error printed, which the status shows after an action
  lastError: '',
  // while a model is checked or computed, its last message in the status, as
  // the FLTK graphical user interface shows it
  busyLabel: '',
  busyLine: '',
  // what the status said before a tool took it (see toolStatus())
  statusBefore: null,
  // what is likely missing when the model fails, said with its errors
  hint: '',
  // the model's directory in the in-memory file system, and its file
  modelDir: '',
  modelFile: '',
  // a small screen: the panel is over the scene (see statusbar.mjs)
  narrow: matchMedia('(max-width: 700px), (max-height: 500px)'),
};

export const $ = (id) => document.getElementById(id);
export const canvas = $('canvas'), status = $('status'), logText = $('logText');
// the message of the status bar, in red for an error
export function setStatus(text, error = false) {
  status.textContent = text;
  status.classList.toggle('error', error);
}
// the messages of Gmsh and GetDP; the last error kept (app.lastError) for the
// status after an action
export const lines = [];
export function log(t) {
  // without the colours of the terminal
  t = t.replace(/\x1b\[[0-9;]*m/g, '');
  const kind = /^Error|^\*\*\*/.test(t) ? 'error' : /^Warning/.test(t) ? 'warning' : '';
  if(kind === 'error') app.lastError = t;
  else if(app.busyLabel) app.busyLine = t.replace(/^Info *: */, '');
  lines.push([t, kind]);
  if(lines.length > 2000) lines.shift();
  scheduleLog();
}
let logPending = false;
function scheduleLog() {
  if(logPending) return;
  logPending = true;
  requestAnimationFrame(() => {
    logPending = false;
    if(app.busyLabel && app.busyLine && !app.statusBefore)
      setStatus(`${app.busyLabel}: ${app.busyLine}`);
    app.busyLine = '';
    logText.textContent = '';
    for(const [t, kind] of lines.slice(-500)) {
      const d = document.createElement('div');
      d.textContent = t;
      if(kind) d.className = kind;
      logText.appendChild(d);
    }
    logText.scrollTop = logText.scrollHeight;
  });
}
// The progress bar: a fraction, true for a task of unknown length, or
// false when there is none
export function progress(p) {
  const bar = $('progress');
  bar.hidden = p === false;
  bar.classList.toggle('busy', p === true);
  bar.firstElementChild.style.width = typeof p === 'number' ? (100 * p) + '%' : '';
}
// a file of the in-memory filesystem, downloaded, then removed unless kept
export function download(path, keep = false) {
  const a = document.createElement('a');
  a.href = URL.createObjectURL(new Blob([FS.readFile(path)]));
  a.download = path.slice(path.lastIndexOf('/') + 1);
  a.click();
  URL.revokeObjectURL(a.href);
  if(!keep) FS.unlink(path);
}
