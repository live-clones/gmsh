// The solver of the ONELAB web app, in a web worker: GetDP runs here, in a
// module of its own (the same WebAssembly code as the page's, compiled once),
// as the graphical interface runs it in a process of its own, while the page
// stays free to draw what it is sent and to answer its user. The messages
// play the part of the ONELAB socket:
//
//   page -> worker: {type: 'init', module}, a compiled libgmsh.wasm
//                   {type: 'forget', dir}: a model's directory, to remove
//                   {type: 'run', dir, cwd, files, db, args}: the files of the
//                   model changed since they were last sent ([path, bytes]),
//                   the ONELAB database (JSON), and the solver's arguments
//   worker -> page: {type: 'ready'}
//                   {type: 'log', text}: a line of output
//                   {type: 'merge', name, data, db}: a file to show, written
//                   by the solver, with the database as it is then
//                   {type: 'db', db}: the database, when the solver asks for
//                   a refresh (e.g. a value added to an output on a graph)
//                   {type: 'done', errors, db, files}: the database, and the
//                   files of the model the solver wrote

import createGmsh from './build/gmsh.mjs';

let gmsh, FS;
const post = (message, transfer = []) => postMessage(message, transfer);
// the files of the run already sent to be shown, with their time of change
const shown = new Map();

// the files under a directory, with their time of change
function listFiles(dir, out = new Map()) {
  for(const f of FS.readdir(dir)) {
    if(f === '.' || f === '..') continue;
    const path = dir + '/' + f;
    const st = FS.stat(path);
    if(FS.isDir(st.mode)) listFiles(path, out);
    else out.set(path, st.mtime.getTime());
  }
  return out;
}
function writeFile(path, data) {
  let dir = '';
  for(const part of path.split('/').slice(1, -1)) {
    dir += '/' + part;
    if(!FS.analyzePath(dir).exists) FS.mkdir(dir);
  }
  FS.writeFile(path, data);
}

self.onmessage = async (e) => {
  const m = e.data;
  if(m.type === 'init') {
    gmsh = await createGmsh({
      instantiateWasm: (imports, done) => {
        WebAssembly.instantiate(m.module, imports).then((i) => done(i, m.module));
        return {};
      },
      print: (text) => post({type: 'log', text}),
      printErr: (text) => post({type: 'log', text}),
    });
    FS = gmsh.lib.FS;
    gmsh.initialize([], false);
    gmsh.option.setNumber('General.Terminal', 1);
    // what the solver asks to show (see gmshWebSolve()), sent as it is written
    globalThis.gmshSolverMerge = (name) => {
      const file = FS.analyzePath(name);
      if(!file.exists) return;
      shown.set(file.path, FS.stat(file.path).mtime.getTime());
      const data = FS.readFile(name);
      post({type: 'merge', name, data, db: gmsh.onelab.get()}, [data.buffer]);
    };
    // the database, when the solver asks for a refresh (graphs)
    globalThis.gmshSolverRefresh = () => post({type: 'db', db: gmsh.onelab.get()});
    post({type: 'ready'});
  }
  else if(m.type === 'forget') {
    // the files of a model no longer open
    const remove = (dir) => {
      for(const f of FS.readdir(dir)) {
        if(f === '.' || f === '..') continue;
        const path = dir + '/' + f;
        if(FS.isDir(FS.stat(path).mode)) remove(path);
        else FS.unlink(path);
      }
      FS.rmdir(dir);
    };
    if(FS.analyzePath(m.dir).exists) remove(m.dir);
  }
  else if(m.type === 'run') {
    for(const [path, data] of m.files) writeFile(path, data);
    FS.chdir(m.cwd);
    gmsh.onelab.clear();
    gmsh.onelab.set(m.db);
    const before = listFiles(m.dir);
    shown.clear();
    let errors = 0;
    try {
      errors = gmsh.lib.ccall('gmshWebSolve', 'number', ['string'],
                              [m.args.join('\n')]);
    } catch(err) {
      post({type: 'log', text: 'Error   : ' + err});
      errors = 1;
    }
    // what the solver wrote, back to the page, but what it has already been
    // sent and the solver's own data (results, preprocessing), of no use there
    const files = [], transfer = [];
    for(const [path, time] of listFiles(m.dir)) {
      if(before.get(path) === time || shown.get(path) === time ||
         /\.(res|pre)$/.test(path))
        continue;
      const data = FS.readFile(path);
      files.push([path, data]);
      transfer.push(data.buffer);
    }
    post({type: 'done', errors, db: gmsh.onelab.get(), files}, transfer);
  }
};
