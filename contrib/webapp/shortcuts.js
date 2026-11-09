// The keyboard shortcuts of Gmsh's graphical interface in a web page: the same
// table (src/common/Shortcuts.cpp, through gmshWebShortcuts()), the actions
// that change the scene run by the module as in the interface (see
// RunSceneShortcut()), the others by the page, or ignored when the page has
// nothing for them. A browser keeps some keys for itself (Cmd+W, Cmd+N,
// Cmd+T, Cmd+Q, and Cmd+H and Cmd+M on macOS): their actions are only reached
// from the page.

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

// installs the shortcuts: run(action, mods) is the page's, returning true when
// it handled the action; draw(action) draws the scene again after an action
// of the module (the page may show what it changed). Returns the table,
// with the label of each key as the platform names it
export function installShortcuts(Module, run, draw) {
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
      let st = Module.ccall('gmshWebShortcut', 'number', ['string', 'number'],
                            [s.action, mods]);
      if(!st && run(s.action, mods)) st = 1;
      if(!st) continue;
      e.preventDefault();
      if(st === 2) draw(s.action);
      return;
    }
  });
  return table;
}

// a list of the shortcuts, for a help box: each key and what it does, keys
// that do the same joined with "or", the actions of the module (those that
// change the scene) and those available(action) says the page has
export function shortcutsHelp(table, available) {
  const rows = [];
  for(const s of table) {
    if(!s.scene && !available(s.action)) continue;
    const last = rows[rows.length - 1];
    if(last && last.action === s.action && last.help === s.help)
      last.label += ' or ' + s.label;
    else
      rows.push({action: s.action, label: s.label, help: s.help});
  }
  return rows;
}
