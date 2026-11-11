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

// The page's table of actions, pageActions in actions.mjs, against the action
// registry of the module (src/common/Actions.cpp, as gmshWebActions() gives
// it): every name of the table is an action of the registry that Gmsh does not
// do itself, every icon of the status bar has strokes, every button of the
// status bar has an icon or a label; the actions the page does not have are
// listed. The counterpart of benchmarks/gui/registry.cpp for the FLTK
// graphical user interface.
//
// Usage: node test/registry_test.mjs (with the node of emsdk, for example)

import fs from 'fs';
import createGmsh from '../build/gmsh.mjs';

const gmsh = await createGmsh({print: () => {}, printErr: () => {}});
gmsh.initialize();
// the two functions of webApp.cpp used, called as gmshweb.mjs calls them (the
// page's modules need a browser)
const call = (name, ret, types, args) => gmsh.lib.ccall('gmshWeb' + name, ret, types, args);
const web = {
  actions: () => call('Actions', 'string', [], []),
  icon: (name) => call('Icon', 'string', ['string'], [name]),
};
gmsh.option.setNumber('General.Terminal', 0);

let fails = 0, items = 0;
const fail = (what) => { console.log('FAIL ' + what); fails++; };

// the names of the table, read from the source: one entry per line, 'name': {
const source = fs.readFileSync(new URL('../actions.mjs', import.meta.url), 'utf8');
const table = source.slice(source.indexOf('const pageActions = {'));
const pageActions = new Set([...table.slice(0, table.indexOf('\n};')).matchAll(/^\s*'([a-z0-9_]+)':/gm)]
  .map((m) => m[1]));

const registry = JSON.parse(web.actions());
const actions = new Map(); // name -> gmsh does it
function walk(item, menu) {
  for(const i of item.items) {
    if(i.kind === 'menu') { walk(i, menu + '/' + i.label); continue; }
    items++;
    if(i.kind === 'action') {
      actions.set(i.name, i.gmsh);
      if(i.gmsh && pageActions.has(i.name))
        fail(i.name + ': done by Gmsh, also in pageActions');
      if(!i.gmsh && !pageActions.has(i.name))
        console.log('     ' + i.name.padEnd(28) + ' not in the web page (' + menu + ')');
    }
    if(i.icon && !web.icon(i.icon)) fail(i.name + ': no strokes for icon ' + i.icon);
    if(menu === 'Status bar' && !i.icon && !i.label)
      fail(i.name + ': a status bar button without icon or label');
  }
}
for(const [menu, root] of Object.entries(registry)) walk(root, menu);
for(const name of pageActions)
  if(!actions.has(name)) fail(name + ': in pageActions, not an action of the registry');

console.log(`${items} items, ${pageActions.size} page actions, ${fails} failures`);
gmsh.finalize();
process.exit(fails ? 1 : 0);
