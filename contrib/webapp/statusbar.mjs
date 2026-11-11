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

// The status bar, as the FLTK graphical user interface's: the points of
// view, the mouse selection, the panel, the quick access menu and the other
// popups of the page, the tools and the animation of the views

import {$, app, gmsh, log} from './app.mjs';
import {web} from './gmshweb.mjs';
import {canRunItem, keyLabels, menuItems, registry, runItem} from './actions.mjs';
import {openMenu} from './models.mjs';
import {readOptions, views} from './options.mjs';
import {draw} from './scene.mjs';
import {modifiers} from './shortcuts.js';
import {operationKey} from './tools.mjs';
import {showViews} from './views.mjs';

// The popups over the page: the menu of a model (Open model), of the graphs
// and of the range of a parameter, and the menus of popupMenu() (quick access,
// the module buttons, a view, the models of a folder), all in #quickMenu; each
// closed by a click elsewhere but on the buttons that open it (its
// selector), or by Escape (closePopup()). A popup is placed in the window.
const popups = [
  ['openMenu', '#open', () => openMenu(false)],
  ['graphMenu', '#graphMenu, .graphButton'],
  ['rangeMenu', '#rangeMenu, .rangeButton'],
  ['quickMenu', '#quickMenu, [data-act=quick_access], .menuButton, #model']];
// the first popup open closed: false if none is open
export function closePopup(target = null) {
  for(const [id, keep, close] of popups) {
    if($(id).hidden || (target && target.closest(keep))) continue;
    if(close) close(); else $(id).hidden = true;
    if(!target) return true;
  }
  return false;
}
export function placePopup(menu, x, y) {
  menu.style.left = Math.max(8, Math.min(x, innerWidth - menu.offsetWidth - 8)) + 'px';
  menu.style.top = Math.max(8, Math.min(y, innerHeight - menu.offsetHeight - 8)) + 'px';
}
// The status bar of the graphical interface's window: the views along the
// axes, isometric, turned, fitted (Shift: the other side, the box around
// what is visible), the mouse selection, the panel, the quick access menu,
// and the animation of the views with time steps
export function sceneAction(action, mods = 0) {
  if(web.view(action, mods)) {
    readOptions();
    draw();
  }
}
export function showSide(show) {
  document.body.classList.toggle('noSide', !show);
  draw();
}
export function toggleSide() {
  showSide(document.body.classList.contains('noSide'));
}
export const sideOver = () => app.narrow.matches && !document.body.classList.contains('noSide');
// the selection button red while the mouse selects nothing (hover, picking)
export function showSelection() {
  const on = !!gmsh.option.getNumber('General.MouseSelection');
  const b = $('statusbar').querySelector('[data-act=mouse_selection]');
  if(b) b.classList.toggle('off', !on);
}
// the animation: a step every PostProcessing.AnimationDelay seconds
let playTimer = 0;
export const playing = () => !!playTimer;
export function setPlaying(on) {
  clearInterval(playTimer);
  playTimer = 0;
  if(on) {
    const delay = 1000 * gmsh.option.getNumber('PostProcessing.AnimationDelay');
    playTimer = setInterval(() => sceneAction('time_step_next'), Math.max(20, delay));
  }
  const b = $('statusbar').querySelector('[data-act=anim_play]');
  if(b) b.innerHTML = icon(on ? 'pause' : 'play');
}
// the time steps of the views back to the first
export function rewindAnimation() {
  for(let i = 0; i < views(); i++) gmsh.option.setNumber(`View[${i}].TimeStep`, 0);
  readOptions();
  draw();
}
// the buttons of the animation, for views with several time steps
export function showAnimation() {
  let steps = !!gmsh.option.getNumber('PostProcessing.AnimationCycle');
  for(let i = 0; i < views() && !steps; i++)
    if(gmsh.option.getNumber(`View[${i}].NbTimeStep`) > 1) steps = true;
  for(const a of ['anim_rewind', 'time_step_prev', 'anim_play', 'time_step_next']) {
    const b = $('statusbar').querySelector(`[data-act=${a}]`);
    if(b) b.disabled = !steps;
  }
  if(!steps && playTimer) setPlaying(false);
}
// an icon, as the FLTK interface draws it (see IconStrokes.h), in the colour
// of the text
const icon = (name) => `<svg viewBox="0 0 24 24" fill="none" stroke="currentColor" ` +
  `stroke-width="2" stroke-linecap="round" stroke-linejoin="round">${web.icon(name)}</svg>`;
// The buttons of the status bar, from the "Status bar" menu of the registry
// (see Actions.cpp), as in the FLTK interface: each with its icon or its
// label, and its item's help and keys as its title; the groups set apart (the
// first before the buttons of an operation, the others before the status)
function buildStatusBar() {
  const bar = $('statusbar');
  const registryBar = registry['Status bar'];
  registryBar.items.forEach((group, g) => {
    const before = g ? $('status') : bar.querySelector('[data-act=op_e]');
    if(g) bar.insertBefore(Object.assign(document.createElement('span'), {className: 'gap'}), before);
    for(const item of group.items) {
      if(!canRunItem(item)) continue;
      const b = document.createElement('button');
      b.dataset.act = item.name;
      const keys = keyLabels(item.name);
      b.title = item.help + (keys ? ` (${keys})` : '');
      if(item.icon) b.innerHTML = icon(item.icon);
      else b.textContent = item.label;
      b.addEventListener('click', (e) => runItem(item, {mods: modifiers(e), el: b}));
      bar.insertBefore(b, before);
    }
  });
}
// The quick access menu of the status bar, as the graphical interface's: what
// is shown of the geometry, the mesh and the views, the projection and the
// axes, and the options of each
function quickItems() {
  const num = (n) => gmsh.option.getNumber(n);
  const items = menuItems(registry['Quick access']);
  // the buttons of the status bar there is no room for on a small screen,
  // after the first entry
  if(app.narrow.matches) items.splice(1, 0,
    ['View along X', () => sceneAction('view_x')],
    ['View along Y', () => sceneAction('view_y')],
    ['View along Z', () => sceneAction('view_z')],
    ['Rotate by 90 degrees', () => {
      if(web.rotate(0)) draw();
    }],
    ['Mouse selection', () => toggleMouseSelection(), !!num('General.MouseSelection')]);
  return items;
}
// the page in full screen, where the browser lets it (not on an iPhone,
// where the app on the home screen has no bars instead)
export const fullscreenEnabled = document.fullscreenEnabled || document.webkitFullscreenEnabled;
export const fullscreenElement = () => document.fullscreenElement || document.webkitFullscreenElement;
export function toggleFullscreen() {
  const d = document.documentElement;
  const r = fullscreenElement() ?
    (document.exitFullscreen || document.webkitExitFullscreen).call(document) :
    (d.requestFullscreen || d.webkitRequestFullscreen).call(d);
  if(r && r.catch) r.catch((e) => log('*** ' + e.message));
}
// the page installed as an app (manifest.webmanifest), where the browser
// offers it (Chrome, Edge, Android; see also the landing page)
export async function installApp() {
  const p = window.installPrompt;
  if(!p) return;
  window.installPrompt = null;
  p.prompt();
  await p.userChoice;
}
export function openQuickMenu(x, y, above = false) {
  popupMenu(quickItems, x, y, {above});
}
// A menu of items(): [label, action, checked], the heading of a section, a
// separator ('') or a submenu ({label, items}, opened next to its entry) at
// (x, y) in the window or above it; the button that opened it (owner) closes
// it again
let menuOwner = null;
export function popupMenu(items, x, y, {above = false, owner = null} = {}) {
  const menu = $('quickMenu');
  if(owner && owner === menuOwner && !menu.hidden) {
    menu.hidden = true;
    return;
  }
  menuOwner = owner;
  menu.textContent = '';
  // (the submenu, in the menu so that a click in it is in the menu)
  const sub = document.createElement('div');
  sub.className = 'submenu';
  sub.hidden = true;
  let opened = null;
  const open = (b, item) => {
    if(opened === b) return;
    if(opened) opened.classList.remove('open');
    opened = b;
    b.classList.add('open');
    sub.textContent = '';
    fillMenu(sub, item.items);
    sub.hidden = false;
    const r = b.getBoundingClientRect();
    // (to the right of its entry, or to the left if there is no room)
    const x = r.right + sub.offsetWidth + 8 <= innerWidth ? r.right : r.left - sub.offsetWidth;
    placePopup(sub, x, r.top - 5);
  };
  const fillMenu = (m, list) => {
    for(const item of list) {
      if(item === '') {
        m.appendChild(document.createElement('hr'));
        continue;
      }
      if(typeof item === 'string') {
        const h = document.createElement('div');
        h.className = 'head';
        h.textContent = item;
        m.appendChild(h);
        continue;
      }
      const b = document.createElement('button');
      const mark = document.createElement('span');
      mark.className = 'mark';
      if(!Array.isArray(item)) {
        const arrow = document.createElement('span');
        arrow.className = 'arrow';
        arrow.textContent = '▸';
        b.append(mark, document.createTextNode(item.label), arrow);
        b.addEventListener('click', () => open(b, item));
        b.addEventListener('pointerenter', (e) => {
          if(e.pointerType === 'mouse') open(b, item);
        });
        m.appendChild(b);
        continue;
      }
      const [label, act, checked] = item;
      mark.textContent = checked ? '✓' : '';
      b.append(mark, document.createTextNode(label));
      b.addEventListener('click', () => {
        menu.hidden = true;
        act();
        showViews();
        readOptions();
        draw();
      });
      // (an entry of the menu closes the submenu)
      if(m === menu) b.addEventListener('pointerenter', (e) => {
        if(e.pointerType !== 'mouse' || !opened) return;
        opened.classList.remove('open');
        opened = null;
        sub.hidden = true;
      });
      m.appendChild(b);
    }
  };
  fillMenu(menu, items());
  menu.appendChild(sub);
  menu.hidden = false;
  placePopup(menu, x, above ? y - menu.offsetHeight - 2 : y);
}
// picking on or off (the S button, Shift+Escape): a selection under way goes
// on
export function toggleMouseSelection() {
  gmsh.option.setNumber('General.MouseSelection',
                        gmsh.option.getNumber('General.MouseSelection') ? 0 : 1);
  showSelection();
  draw();
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  document.addEventListener('pointerdown', (e) => closePopup(e.target));
  app.narrow.addEventListener('change', () => showSide(!app.narrow.matches));
  if(app.narrow.matches) document.body.classList.add('noSide');
  buildStatusBar();
  // the buttons of an operation under way: its keys e, u and q, which a
  // phone has not
  for(const k of ['e', 'u', 'q'])
    $('statusbar').querySelector(`[data-act=op_${k}]`)
      .addEventListener('click', () => operationKey(k));
  showSelection();
}
