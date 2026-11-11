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

// The Visibility tab, as the visibility window of the FLTK graphical user
// interface: the entities or the physical groups shown or hidden, by dimension

import {$, gmsh} from './app.mjs';
import {draw} from './scene.mjs';

// the visibility of the model, as the visibility window of the graphical
// interface: its elementary entities or its physical groups, by dimension,
// shown or hidden (with their boundaries, as asked); the mesh and the
// geometry of a hidden entity are not drawn
const typeNames = ['Point', 'Curve', 'Surface', 'Volume'];
const dimNames = ['Points', 'Curves', 'Surfaces', 'Volumes'];
let visGroups = false;
const visOpen = {2: true, 3: true};
// rows at most for a dimension: a filter shows the others
const visMax = 1000;
// what the list shows: [{dim, label, dimTags}]
function visItems() {
  const items = [];
  if(visGroups) {
    for(const [dim, tag] of gmsh.model.getPhysicalGroups()) {
      const name = gmsh.model.getPhysicalName(dim, tag);
      const tags = gmsh.model.getEntitiesForPhysicalGroup(dim, tag);
      items.push({dim, label: `Physical ${typeNames[dim]} ${tag}` + (name ? ': ' + name : ''),
                  dimTags: Array.from(tags, (t) => [dim, t])});
    }
  }
  else {
    for(const [dim, tag] of gmsh.model.getEntities()) {
      const name = gmsh.model.getEntityName(dim, tag);
      items.push({dim, label: `${typeNames[dim]} ${tag}` + (name ? ': ' + name : ''),
                  dimTags: [[dim, tag]]});
    }
  }
  const filter = $('visFilter').value.trim().toLowerCase();
  return filter ? items.filter((it) => it.label.toLowerCase().includes(filter)) : items;
}
const visible = (it) => it.dimTags.map(([d, t]) => gmsh.model.getVisibility(d, t));
function setVisible(dimTags, on) {
  if(dimTags.length) gmsh.model.setVisibility(dimTags, on ? 1 : 0, $('visRecursive').checked);
}
function visRows(d, items) {
  d.dataset.filled = '1';
  for(const it of items.slice(0, visMax)) {
    const row = document.createElement('label');
    row.className = 'row item';
    const label = document.createElement('span');
    label.textContent = it.label;
    const cb = document.createElement('input');
    cb.type = 'checkbox';
    const v = visible(it);
    cb.checked = v.every((x) => x);
    cb.indeterminate = !cb.checked && v.some((x) => x);
    cb.addEventListener('change', () => {
      setVisible(it.dimTags, cb.checked);
      readVisibility();
      draw();
    });
    row.append(cb, label);
    d.appendChild(row);
  }
  if(items.length > visMax) {
    const note = document.createElement('div');
    note.className = 'note';
    note.textContent = `${items.length - visMax} more: filter to see them`;
    d.appendChild(note);
  }
}
// the list, as the model is: only the dimensions open are filled
export function readVisibility() {
  if($('visTab').hidden) return;
  const list = $('visList');
  list.textContent = '';
  const items = visItems();
  if(!items.length) {
    list.innerHTML = '<div class="note">Nothing to show</div>';
    return;
  }
  for(let dim = 3; dim >= 0; dim--) {
    const its = items.filter((it) => it.dim === dim);
    if(!its.length) continue;
    const d = document.createElement('details');
    d.open = !!visOpen[dim];
    const sum = document.createElement('summary');
    sum.textContent = `${(visGroups ? 'Physical ' : '') + dimNames[dim]} (${its.length})`;
    d.appendChild(sum);
    d.addEventListener('toggle', () => {
      visOpen[dim] = d.open;
      if(d.open && !d.dataset.filled) visRows(d, its);
    });
    if(d.open) visRows(d, its);
    list.appendChild(d);
  }
}
function visMode(groups) {
  visGroups = groups;
  $('visEntities').classList.toggle('on', !groups);
  $('visGroups').classList.toggle('on', groups);
  readVisibility();
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  $('visEntities').addEventListener('click', () => visMode(false));
  $('visGroups').addEventListener('click', () => visMode(true));
  $('visFilter').addEventListener('input', readVisibility);
  // what the list shows (with the filter), all at once
  for(const [id, how] of [['visAll', 1], ['visNone', 0], ['visInvert', -1]])
    $(id).addEventListener('click', () => {
      const items = visItems();
      if(how < 0) {
        // what is shown hidden, then what was hidden shown, so that the
        // boundaries the two share end up shown
        const shown = items.filter((it) => visible(it).every((x) => x));
        const hidden = items.filter((it) => !shown.includes(it));
        setVisible(shown.flatMap((it) => it.dimTags), false);
        setVisible(hidden.flatMap((it) => it.dimTags), true);
      }
      else
        setVisible(items.flatMap((it) => it.dimTags), how);
      readVisibility();
      draw();
    });
}
