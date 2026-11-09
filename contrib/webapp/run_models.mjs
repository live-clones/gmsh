// Run ONELAB models with the web app's module (built with GetDP) under node,
// as onelab.html does: open the .pro file (or the .geo), "check", then
// "compute"; e.g.
//
//   node run_models.mjs ~/src/getdp/tutorials/*/
//
// Each directory is copied in the in-memory filesystem, without the files
// earlier runs left (meshes, results, databases), so that the models are
// meshed and solved from scratch; a line per model gives the errors, the
// views made, and the times.

import fs from 'fs';
import path from 'path';
import createGmsh from './build/gmsh.mjs';
import {findModel} from './files.mjs';

const dirs = process.argv.slice(2);
if(!dirs.length) {
  console.log('Usage: node run_models.mjs <model directory> ...');
  process.exit(1);
}
const verbose = !!process.env.VERBOSE;
let messages = [];
const gmsh = await createGmsh({
  print: (t) => { messages.push(t); if(verbose) console.log(t); },
  printErr: (t) => { messages.push(t); if(verbose) console.log(t); },
});
const Module = gmsh.lib;
const FS = Module.FS;
gmsh.initialize([], false);
gmsh.option.setNumber('General.Terminal', 1);

const skip = /\.(msh|pre|res|pos|db|db\.json|png|jpg|jpeg|gif|mp4)$/i;
function copy(src, dst) {
  FS.mkdir(dst);
  for(const f of fs.readdirSync(src)) {
    const s = path.join(src, f);
    if(fs.statSync(s).isDirectory()) copy(s, dst + '/' + f);
    else if(!skip.test(f)) FS.writeFile(dst + '/' + f, fs.readFileSync(s));
  }
}
const run = (action) =>
  Module.ccall('gmshWebOnelab', 'number', ['string'], [action]);

let failed = 0, n = 0;
for(const dir of dirs) {
  const name = path.basename(path.resolve(dir));
  const work = `/run${++n}`;
  copy(dir, work);
  // as onelab.html
  const file = findModel(FS, work);
  if(!/\.(pro|geo)$/.test(file || '')) {
    console.log(`${name}: no model`);
    continue;
  }
  FS.chdir(work);
  messages = [];
  gmsh.onelab.clear();
  gmsh.clear();
  gmsh.option.restoreDefaults();
  gmsh.option.setNumber('General.Terminal', 1);
  const t0 = performance.now();
  let errors = 0;
  try {
    gmsh.open(file);
    errors += run('check');
    const t1 = performance.now();
    errors += run('compute');
    const t2 = performance.now();
    const views = gmsh.option.getNumber('PostProcessing.NbViews');
    const nodes = gmsh.option.getNumber('Mesh.NbNodes');
    console.log(`${name} (${file.slice(work.length + 1)}): ${errors ? errors + ' error(s)' : 'ok'}, ` +
                `${nodes} nodes, ${views} views, open+check ` +
                `${((t1 - t0) / 1000).toFixed(2)} s, compute ` +
                `${((t2 - t1) / 1000).toFixed(2)} s`);
  } catch(e) {
    errors++;
    console.log(`${name} (${file.slice(work.length + 1)}): exception ${e.message || e}`);
  }
  if(errors) {
    failed++;
    for(const m of messages.filter((m) => /Error|\*\*\*/.test(m)).slice(0, 5))
      console.log('    ' + m);
  }
}
console.log(`${dirs.length - failed} of ${dirs.length} models ran without error`);
process.exit(failed ? 1 : 0);
