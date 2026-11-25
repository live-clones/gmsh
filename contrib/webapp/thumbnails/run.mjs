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

// The first half of a thumbnail of the landing page (see make.sh): a model run
// with the web app's module under node, as onelab.html runs it (open, "check",
// "compute"), and what it shows at the end saved in a directory, for render.py
// to draw: its mesh (name.msh), its views (name_1.pos, ...) and its options
// (name.opt), with the file it opened, relative to the model's directory
// (name.open). Usage:
//
//   node run.mjs <output directory> <name> <model directory> [<file to open>]
//                [<parameters>]
//
// with parameters the ONELAB numbers set before the run, as name=value;...
// (e.g. a shorter time for a model that runs long).

import {execFileSync} from 'child_process';
import fs from 'fs';
import path from 'path';
import createGmsh from '../build/gmsh.mjs';
import {findModel, writeFile} from '../files.mjs';

const [out, name, dir, open, parameters] = process.argv.slice(2);
if(!dir) {
  console.log('Usage: node run.mjs <output directory> <name> <model directory> [<file>]');
  process.exit(1);
}
const verbose = !!process.env.VERBOSE;
const errors = [];
const gmsh = await createGmsh({
  print: (t) => { if(verbose) console.log(t); },
  printErr: (t) => { if(verbose) console.log(t); if(/Error/.test(t)) errors.push(t); },
});
const Module = gmsh.lib;
const FS = Module.FS;
gmsh.initialize([], false);

// the files of the model, without what earlier runs left (as deploy.sh packs
// them: those it tracks for a git checkout of its own)
const skip = /\.(msh|pre|res|pos|db|db\.json|png|jpg|jpeg|gif|mp4|out)$/i;
function copy(src, dst) {
  for(const f of fs.readdirSync(src)) {
    const s = path.join(src, f);
    if(fs.statSync(s).isDirectory()) copy(s, dst + '/' + f);
    else if(!skip.test(f)) writeFile(FS, dst + '/' + f, fs.readFileSync(s));
  }
}
const work = '/model';
if(fs.existsSync(path.join(dir, '.git'))) {
  for(const f of execFileSync('git', ['ls-files'], {cwd: dir}).toString().split('\n'))
    if(f && !skip.test(f))
      writeFile(FS, work + '/' + f, fs.readFileSync(path.join(dir, f)));
}
else
  copy(dir, work);
const file = open ? work + '/' + open : findModel(FS, work);
FS.chdir(file.slice(0, file.lastIndexOf('/')));
gmsh.option.setNumber('General.Terminal', 1);
gmsh.option.setNumber('General.NoPopup', 1);
const run = (action) =>
  Module.ccall('gmshWebOnelab', 'number', ['string'], [action]);
const t0 = performance.now();
gmsh.open(file);
if(gmsh.model.getFileName() === file) gmsh.onelab.setChanged('Gmsh', 0);
// (set before the model defines them, which keeps the values it finds)
for(const p of (parameters || '').split(';').filter((s) => s.trim())) {
  const i = p.lastIndexOf('=');
  gmsh.onelab.setNumber(p.slice(0, i).trim(), [Number(p.slice(i + 1))]);
}
let n = run('check');
n += run('compute');
const t = ((performance.now() - t0) / 1000).toFixed(1);

// what it shows: all the mesh (whatever the physical groups), each view, and
// the options (with those of the views, in the same order)
fs.mkdirSync(out, {recursive: true});
gmsh.option.setNumber('Mesh.SaveAll', 1);
gmsh.option.setNumber('Mesh.Binary', 0);
const save = (f) => fs.writeFileSync(path.join(out, f), FS.readFile('/' + f));
gmsh.write('/' + name + '.msh');
save(name + '.msh');
const tags = gmsh.view.getTags();
tags.forEach((tag, i) => {
  const f = `${name}_${i + 1}.pos`;
  try {
    gmsh.view.write(tag, '/' + f);
  } catch(e) {
    // (a view on several meshes in a step, e.g. a moving part, cannot be
    // saved as .pos)
    console.log(`    view ${i + 1}: ${e.message}`);
  }
  // a view with a mesh per time step (e.g. a rotating machine) is saved in a
  // file per step: the step shown is kept
  if(!FS.analyzePath('/' + f).exists) {
    const step = gmsh.option.getNumber(`View[${i}].TimeStep`);
    const s = `/${name}_${i + 1}_${String(step).padStart(4, '0')}.pos`;
    if(!FS.analyzePath(s).exists) return;
    FS.rename(s, '/' + f);
  }
  save(f);
});
gmsh.write('/' + name + '.opt');
save(name + '.opt');
fs.writeFileSync(path.join(out, name + '.open'), file.slice(work.length + 1));
console.log(`${name}: ${n || errors.length ? 'ERRORS' : 'ok'}, ${tags.length} views, ${t} s`);
for(const e of errors.slice(0, 5)) console.log('    ' + e);
process.exit(0);
