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

// The editor of a file of the model (its script, an input file of a solver),
// in the colours of its language, with Find and Go to line

import {$, FS, setStatus} from './app.mjs';
import {web} from './gmshweb.mjs';
import {reloadScript, scriptFile} from './actions.mjs';

// A file of the model edited (its script, or an input file of a solver), in
// the colors of its language (see GetScriptStyles() in ScriptStyles.cpp):
// saved, and a .geo script then read again
let editedFile = '';
export function editFile(path) {
  if(!path || !FS.analyzePath(path).exists) {
    setStatus(`No file '${path}' to edit`);
    return;
  }
  editedFile = path;
  $('scriptName').textContent = path.slice(path.lastIndexOf('/') + 1);
  // the model read again only from a .geo script, which is what the geometry
  // module reads (a .pro, or a program of the API, is only saved), as in the
  // graphical interface
  $('scriptSave').hidden = !/\.geo$/i.test(path);
  $('scriptText').value = FS.readFile(path, {encoding: 'utf8'});
  $('scriptLine').value = '';
  $('scriptFind').value = '';
  colorScript();
  $('scriptDialog').showModal();
  $('scriptText').scrollTo(0, 0);
}
export function editScript() {
  const f = scriptFile();
  if(f) editFile(f);
  else setStatus('No script to edit: open a .geo model, or make a new one');
}
// the text in its colors, under the text area
function colorScript() {
  const text = $('scriptText').value;
  const styles = web.scriptStyles(editedFile, text);
  const html = [];
  const escape = (t) => t.replace(/&/g, '&amp;').replace(/</g, '&lt;');
  for(let i = 0; i < text.length;) {
    let j = i + 1;
    while(j < text.length && styles[j] === styles[i]) j++;
    const t = escape(text.slice(i, j));
    html.push(styles[i] === 'A' ? t : `<span class="${styles[i]}">${t}</span>`);
    i = j;
  }
  // (a last line, for the height of the text area)
  $('scriptColors').innerHTML = html.join('') + '\n';
  scrollColors();
}
const scrollColors = () => {
  $('scriptColors').scrollTop = $('scriptText').scrollTop;
  $('scriptColors').scrollLeft = $('scriptText').scrollLeft;
};
// the text of the Find field, the first one from the match being extended as
// it is typed, the next one on Enter; from the start once the end is reached
function findInScript(again) {
  const ta = $('scriptText'), what = $('scriptFind').value.toLowerCase();
  if(!what) return;
  const text = ta.value.toLowerCase();
  let i = text.indexOf(what, again ? ta.selectionStart : ta.selectionEnd);
  if(i < 0) i = text.indexOf(what);
  if(i < 0) return;
  ta.setSelectionRange(i, i + what.length);
  const line = ta.value.slice(0, i).split('\n').length;
  ta.scrollTop = (line - 1) * parseFloat(getComputedStyle(ta).lineHeight) - ta.clientHeight / 3;
  scrollColors();
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  $('scriptText').addEventListener('input', colorScript);
  $('scriptText').addEventListener('scroll', scrollColors);
  // a line selected, scrolled to
  $('scriptLine').addEventListener('change', () => {
    const ta = $('scriptText'), lines = ta.value.split('\n');
    const n = Math.min(Math.max(1, Number($('scriptLine').value) || 1), lines.length);
    const start = lines.slice(0, n - 1).reduce((a, l) => a + l.length + 1, 0);
    ta.focus();
    ta.setSelectionRange(start, start + lines[n - 1].length);
    ta.scrollTop = (n - 1) * parseFloat(getComputedStyle(ta).lineHeight) - ta.clientHeight / 3;
    scrollColors();
  });
  $('scriptLine').addEventListener('keydown', (e) => {
    if(e.key === 'Enter') {
      e.preventDefault();
      $('scriptLine').dispatchEvent(new Event('change'));
    }
  });
  $('scriptFind').addEventListener('input', () => findInScript(true));
  $('scriptFind').addEventListener('keydown', (e) => {
    if(e.key !== 'Enter') return;
    e.preventDefault();
    findInScript(false);
  });
  // the keys of the buttons, as in the graphical interface: Ctrl+S (Cmd+S on
  // macOS) saves, Ctrl+R saves and reads the model again
  {
    const mod = /Mac/.test(navigator.platform) ? 'Cmd' : 'Ctrl';
    $('scriptWrite').title += ` (${mod}+S)`;
    $('scriptSave').title += ` (${mod}+R)`;
    $('scriptDialog').addEventListener('keydown', (e) => {
      if(!(mod === 'Cmd' ? e.metaKey : e.ctrlKey) || e.altKey) return;
      const b = {s: $('scriptWrite'), r: $('scriptSave')}[e.key.toLowerCase()];
      if(!b || b.hidden) return;
      e.preventDefault();
      b.click();
    });
  }
  // (on the submission of the form, which says the button at once: the close
  // event of the dialog comes later)
  $('scriptDialog').querySelector('form').addEventListener('submit', (e) => {
    const how = e.submitter && e.submitter.value;
    if((how !== 'save' && how !== 'write') || !editedFile) return;
    FS.writeFile(editedFile, $('scriptText').value);
    if(how === 'write') return;
    if(/\.geo$/i.test(editedFile)) reloadScript();
  });
}
