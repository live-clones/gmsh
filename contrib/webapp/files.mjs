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

// The files of a model in the in-memory filesystem of the module (FS), as the
// page (onelab.html), the solver's worker (solver.js) and the tests
// (run_models.mjs) handle them.

// the files under a directory, with their time of change, but those of a
// macOS archive (__MACOSX)
export function listFiles(FS, dir, out = new Map()) {
  for(const f of FS.readdir(dir)) {
    if(f === '.' || f === '..' || f.startsWith('__MACOSX')) continue;
    const path = dir + '/' + f;
    const st = FS.stat(path);
    if(FS.isDir(st.mode)) listFiles(FS, path, out);
    else out.set(path, st.mtime.getTime());
  }
  return out;
}

// a file written, its directories made
export function writeFile(FS, path, data) {
  const parts = path.split('/').filter((s) => s);
  let dir = '';
  for(const p of parts.slice(0, -1)) {
    dir += '/' + p;
    if(!FS.analyzePath(dir).exists) FS.mkdir(dir);
  }
  FS.writeFile(dir + '/' + parts[parts.length - 1], data);
}

// a directory removed, with its files
export function removeDirectory(FS, dir) {
  for(const f of FS.readdir(dir)) {
    if(f === '.' || f === '..') continue;
    const path = dir + '/' + f;
    if(FS.isDir(FS.stat(path).mode)) removeDirectory(FS, path);
    else FS.unlink(path);
  }
  FS.rmdir(dir);
}

// the file to open in a directory: a .pro with a .geo of the same name, or
// else a .pro, or else a .geo, or else any file; the nearest to the
// directory first (a model may have others in subdirectories)
export function findModel(FS, dir) {
  const depth = (f) => f.split('/').length;
  const files = [...listFiles(FS, dir).keys()].sort((a, b) => depth(a) - depth(b));
  const pro = files.filter((f) => f.endsWith('.pro'));
  const geo = files.filter((f) => f.endsWith('.geo'));
  return pro.find((f) => geo.includes(f.replace(/\.pro$/, '.geo'))) ||
    pro[0] || geo[0] || files[0];
}
