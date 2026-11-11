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

// The keyboard shortcuts of Gmsh's FLTK graphical user interface in a web
// page: the same keys (declared on the items of src/common/Actions.cpp, read
// through gmshWebShortcuts()), a key running the item of its action, as a
// click on it does (see runItem() in the page), or ignored when the page has
// none. A browser keeps some keys for itself
// (Cmd+W, Cmd+N, Cmd+T, Cmd+Q, and Cmd+H and Cmd+M on macOS): their actions
// are only reached from the page.

const mac = /Mac|iPhone|iPad/.test(navigator.platform);
// the modifiers of the shortcut table (src/common/Shortcuts.h), and for the
// mouse Control and Meta apart, which the scene tells apart (see
// gmshWebMouse())
export const ModCommand = 1, ModShift = 2, ModAlt = 4, AnyModifiers = 8,
             ModControl = 16, ModMeta = 32;
// the modifiers of an event: of a key, Command (Control, or Command on
// macOS), Shift and Alt; of the mouse, Control and Meta instead of Command
export function modifiers(e, mouse = false) {
  const command = mouse ? (e.ctrlKey ? ModControl : 0) | (e.metaKey ? ModMeta : 0) :
                          ((mac ? e.metaKey : e.ctrlKey) ? ModCommand : 0);
  return command | (e.shiftKey ? ModShift : 0) | (e.altKey ? ModAlt : 0);
}

// the key a shortcut names: the character of the key on the keyboard layout
// in use, which Alt changes on macOS (Alt+p is "π"), so that the character of
// a key without Alt is remembered, from the layout map where the browser has
// one, or from the keys typed
const layout = new Map();
if(navigator.keyboard && navigator.keyboard.getLayoutMap)
  navigator.keyboard.getLayoutMap().then((m) => {
    for(const [code, key] of m) if(!layout.has(code)) layout.set(code, key);
  }).catch(() => {});
function keyOf(e) {
  if(e.key.length !== 1) return e.key; // F1, Escape, ArrowLeft, PageUp...
  if(!e.altKey && !e.ctrlKey && !e.metaKey) {
    layout.set(e.code, e.key.toLowerCase());
    return e.key.toLowerCase();
  }
  if(layout.has(e.code)) return layout.get(e.code);
  if(e.code.startsWith('Key')) return e.code.slice(3).toLowerCase();
  if(e.code.startsWith('Digit')) return e.code.slice(5);
  return e.key.toLowerCase();
}

// installs the shortcuts: run(action, mods) runs the item of the action,
// returning true when the page has it. Returns the table, with the label of
// each key as the platform names it
export function installShortcuts(Module, run) {
  const table = JSON.parse(Module.ccall('gmshWebShortcuts', 'string', ['string'],
                                        [mac ? 'Cmd+' : 'Ctrl+']));
  window.addEventListener('keydown', (e) => {
    // not while typing in a field
    const t = e.target;
    if(t.isContentEditable || t.tagName === 'TEXTAREA' || t.tagName === 'SELECT' ||
       (t.tagName === 'INPUT' && !['checkbox', 'radio', 'range', 'button']
         .includes(t.type)))
      return;
    const key = keyOf(e);
    const mods = modifiers(e);
    // the keys as the layout gives them: a digit may need Shift
    const digit = /^[0-9]$/.test(key);
    const matches = (s, m) => s.key === key &&
      ((s.mods & AnyModifiers) || (s.mods & ~AnyModifiers) === m);
    let found = table.filter((s) => matches(s, mods));
    if(!found.length && digit && (mods & ModShift))
      found = table.filter((s) => matches(s, mods & ~ModShift));
    for(const s of found) {
      if(!run(s.action, mods)) continue;
      e.preventDefault();
      return;
    }
  });
  return table;
}

// a list of the shortcuts, for a help box: each key and what it does, keys
// that do the same joined with "or", those available(action) says the page
// has
export function shortcutsHelp(table, available) {
  const rows = [];
  for(const s of table) {
    if(!available(s.action)) continue;
    const last = rows[rows.length - 1];
    if(last && last.action === s.action && last.help === s.help)
      last.label += ' or ' + s.label;
    else
      rows.push({action: s.action, label: s.label, help: s.help});
  }
  return rows;
}
