// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The models: opened from files, a folder, a zip archive or a URL into a
// directory of their own in the in-memory file system, switched within a
// folder, cleared; what a model leaves behind when another starts

import {$, FS, app, gmsh, log, progress, setStatus} from './app.mjs';
import {web} from './gmshweb.mjs';
import {showPanel} from './actions.mjs';
import {findModel, removeDirectory, writeFile} from './files.mjs';
import {applyColorScheme} from './options.mjs';
import {getParameters} from './parameters.mjs';
import {graphEdits, run, sent, showAll, worker, workerReady} from './solverClient.mjs';
import {popupMenu, showSide} from './statusbar.mjs';
import {Tool, setTool, tool} from './tools.mjs';
import {allViewSettings, settledViews, viewOptionsOpen, viewSettings} from './views.mjs';

// a model is opened from a directory of its own in the in-memory filesystem
let modelCount = 0;
function newModelDirectory() {
  const dir = `/model${++modelCount}`;
  FS.mkdir(dir);
  return dir;
}
// What a model leaves when another starts, or none (Clear): the tool or the
// operation under way, its files here and in the worker (unless another
// model of its folder starts, keepFiles), the parameters, the solvers, the
// models and the views, and what the page keeps per view (gmsh.clear()
// starts the view tags again)
function forgetModel(keepFiles = false) {
  if(tool) setTool(Tool.None);
  showPanel(null);
  FS.chdir('/');
  if(app.modelDir && !keepFiles) {
    const old = app.modelDir;
    if(FS.analyzePath(old).exists) removeDirectory(FS, old);
    workerReady.then((ok) => { if(ok) worker.postMessage({type: 'forget', dir: old}); });
    sent.clear();
  }
  viewSettings.clear();
  for(const k of Object.keys(allViewSettings)) delete allViewSettings[k];
  settledViews.clear();
  viewOptionsOpen.clear();
  graphEdits.clear();
  if(!keepFiles) app.modelDir = '';
  app.modelFile = app.hint = '';
  gmsh.onelab.clear();
  web.onelabForgetSolvers();
  gmsh.clear();
}
export async function openFiles(entries, open = '') {
  // entries: [path, Uint8Array]
  if(app.busy) return;
  forgetModel();
  const dir = newModelDirectory();
  app.modelDir = dir;
  for(const [path, data] of entries) {
    if(path.endsWith('.zip')) {
      writeFile(FS, dir + '/' + path, data);
      web.unzip(dir + '/' + path, dir);
      FS.unlink(dir + '/' + path);
    }
    else
      writeFile(FS, dir + '/' + path, data);
  }
  // the file asked for (a zip may hold several models), or the one found
  const file = (open && FS.analyzePath(dir + '/' + open).exists) ?
    dir + '/' + open : findModel(FS, dir);
  if(!file) {
    setStatus('No model found');
    return;
  }
  await openModel(file);
}
// a file of the model's directory opened as the model
async function openModel(file) {
  FS.chdir(file.slice(0, file.lastIndexOf('/')));
  app.modelFile = file;
  $('clearModel').hidden = false;
  const base = file.slice(file.lastIndexOf('/') + 1);
  $('model').textContent = base;
  // a .pro alone: the page has only the files it is given, not the ones
  // next to them on the disk
  const geo = file.replace(/\.pro$/, '.geo');
  app.hint = (geo !== file && !FS.analyzePath(geo).exists) ?
    `No ${geo.slice(geo.lastIndexOf('/') + 1)} next to ${base}: open the ` +
    `model's folder instead (Open model > Its folder)` : '';
  // a model starts from the default options, as the options a model sets
  // (e.g. Mesh.ElementOrder) stay otherwise
  gmsh.option.restoreDefaults();
  gmsh.option.setNumber('General.Terminal', 1);
  gmsh.option.setNumber('General.NoPopup', 1);
  applyColorScheme();
  try {
    gmsh.open(file);
  } catch(e) {
    log('*** ' + e.message);
  }
  // (just read, unless it is a solver's file whose geometry the check reads:
  // the check does not read it again, which would merge the views of a .pos
  // a second time)
  if(gmsh.model.getFileName() === file) gmsh.onelab.setChanged('Gmsh', 0);
  web.resetView();
  await run('check');
  if(app.narrow.matches && getParameters().some((p) => p.visible && !p.name.includes('ONELAB Context/'))) showSide(true);
}
// The files of the folder of the model that Gmsh opens as a model, in the
// menu of its name: the one picked opened instead, with the files of the
// folder kept
const modelExtensions = ['pro', 'geo', 'msh', 'step', 'stp', 'brep', 'iges', 'igs',
                         'stl', 'vtk', 'vtu', 'med', 'cgns', 'unv', 'mesh', 'inp',
                         'bdf', 'nas', 'obj', 'ply'];
function folderModels() {
  const dir = FS.cwd();
  return FS.readdir(dir).filter((f) => {
    const ext = f.slice(f.lastIndexOf('.') + 1).toLowerCase();
    return f.includes('.') && modelExtensions.includes(ext) &&
      !FS.isDir(FS.stat(dir + '/' + f).mode);
  }).sort().map((f) => dir + '/' + f);
}
async function switchModel(file) {
  if(app.busy || file === app.modelFile) return;
  forgetModel(true);
  await openModel(file);
}
function clearModel() {
  if(app.busy) return;
  forgetModel();
  $('model').textContent = '';
  $('clearModel').hidden = true;
  showAll();
  setStatus('Open a model, or drop its files here');
}
const readFile = async (f) => new Uint8Array(await f.arrayBuffer());
// one button for a model, which asks for its folder or for files: a browser
// has no dialog that offers both
export function openMenu(show) {
  $('openMenu').hidden = !show;
  $('openButton').setAttribute('aria-expanded', show);
}
export async function fetchFile(url) {
  setStatus(`Loading ${url.split('/').pop()}...`);
  progress(true);
  const r = await fetch(url);
  if(!r.ok) throw new Error(`${url}: ${r.status}`);
  return new Uint8Array(await r.arrayBuffer());
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  $('model').addEventListener('click', (e) => {
    if(!app.modelDir) return;
    const r = e.currentTarget.getBoundingClientRect();
    // (checked: the one named, as a .pro is named for its .geo)
    const name = (f) => f.slice(f.lastIndexOf('/') + 1);
    popupMenu(() => folderModels().map((f) => [name(f), () => switchModel(f),
                                                name(f) === $('model').textContent]),
              r.left, r.bottom + 2, {owner: e.currentTarget});
  });
  $('openButton').addEventListener('click', () => openMenu($('openMenu').hidden));
  $('openFolder').addEventListener('click', () => { openMenu(false); $('folder').click(); });
  $('openFiles').addEventListener('click', () => { openMenu(false); $('files').click(); });
  $('clearModel').addEventListener('click', () => { openMenu(false); clearModel(); });
  for(const id of ['files', 'folder']) {
    $(id).addEventListener('change', async (e) => {
      const entries = [];
      for(const f of e.target.files) {
        // a folder's files keep their path below it
        const path = f.webkitRelativePath ?
          f.webkitRelativePath.split('/').slice(1).join('/') : f.name;
        entries.push([path, await readFile(f)]);
      }
      e.target.value = '';
      openFiles(entries);
    });
  }
  window.addEventListener('dragover', (e) => {
    e.preventDefault();
    $('drop').style.display = 'grid';
  });
  window.addEventListener('dragleave', (e) => {
    if(!e.relatedTarget) $('drop').style.display = 'none';
  });
  window.addEventListener('drop', async (e) => {
    e.preventDefault();
    $('drop').style.display = 'none';
    const entries = [];
    for(const f of e.dataTransfer.files) entries.push([f.name, await readFile(f)]);
    openFiles(entries);
  });
}
