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

// The scene: the canvas drawn by Gmsh (webApp.cpp, see gmshweb.mjs), the
// mouse and the touches on it, which go to the same interaction as in the
// FLTK graphical user interface (src/graphics/sceneView.cpp), the handles
// that size the panel and the messages, and the notes the tools pin on it

import {$, canvas, status} from './app.mjs';
import {web} from './gmshweb.mjs';
import {modifiers} from './shortcuts.js';
import {openQuickMenu, showSide, sideOver} from './statusbar.mjs';
import {showNotes, tool, toolStatus} from './tools.mjs';

// Tests of the speed of the drawing, given in the address of the page:
// ?scale=1.5 draws at most that many pixels a CSS pixel (the screens of
// phones have up to 3.5), ?pdb=0 does not keep the canvas after each frame
// (see main.mjs), and ?fps=1, or either of the others, shows the size of the
// canvas, the graphics processor, the time of the frames as they are drawn,
// and a button that draws for a few seconds without a pause
const speedTest = new URLSearchParams(location.search);
const maxScale = Number(speedTest.get('scale')) || Infinity;
const showSpeed = ['pdb', 'scale', 'fps'].some((k) => speedTest.has(k));
let speedBox = null, speedFrames = [], gpu = '';
function speedFrame(cpu, dpr) {
  if(!speedBox) {
    speedBox = document.createElement('div');
    speedBox.id = 'speed';
    document.body.append(speedBox);
    const gl = canvas.getContext('webgl2');
    const info = gl && gl.getExtension('WEBGL_debug_renderer_info');
    gpu = !gl ? 'no WebGL 2' :
      gl.getParameter(info ? info.UNMASKED_RENDERER_WEBGL : gl.RENDERER) +
      (gl.getContextAttributes().preserveDrawingBuffer ? ', canvas kept' :
       ', canvas not kept');
  }
  // the last frames, those drawn one after the other (a pause of the view
  // is not a slow frame)
  const now = performance.now();
  speedFrames.push([now, cpu]);
  if(speedFrames.length > 30) speedFrames.shift();
  let gaps = 0, n = 0, cpus = 0;
  for(let i = 0; i < speedFrames.length; i++) {
    cpus += speedFrames[i][1];
    const gap = i ? speedFrames[i][0] - speedFrames[i - 1][0] : 1e9;
    if(gap < 500) { gaps += gap; n++; }
  }
  const at = canvas.getBoundingClientRect();
  speedBox.style.left = (at.left + 6) + 'px';
  speedBox.style.top = (at.top + 6) + 'px';
  speedBox.textContent =
    `${canvas.width} x ${canvas.height} pixels, ${dpr.toFixed(2)} a CSS ` +
    `pixel (screen ${window.devicePixelRatio})\n${gpu}\n` +
    `draw ${(cpus / speedFrames.length).toFixed(1)} ms of the processor` +
    (n ? `, ${(gaps / n).toFixed(1)} ms a frame (${(1000 * n / gaps)
          .toFixed(0)} a second)` : '') + '\n';
  const bench = document.createElement('button');
  bench.textContent = 'Draw for 3 s';
  bench.onclick = () => {
    const start = performance.now();
    let count = 0;
    const next = () => {
      const t = performance.now();
      if(t - start < 3000) {
        drawNow();
        count++;
        requestAnimationFrame(next);
      }
      else
        speedBox.append(`${count} frames in 3 s: ` +
                        `${(3000 / count).toFixed(1)} ms a frame`);
    };
    requestAnimationFrame(next);
  };
  speedBox.append(bench);
}

// the studio shading (General.Shading) converges while the view is still: a
// few of its frames at each animation frame after a frame is drawn, until
// the next one (each run its own number, the older ones then stop)
let pending = false, studio = 0, drawn = null;
function studioFrames() {
  const run = ++studio;
  const more = () => {
    if(run !== studio || pending || !drawn) return;
    if(web.drawStudio(...drawn, 0.03))
      requestAnimationFrame(more);
  };
  requestAnimationFrame(more);
}
export function draw() {
  if(pending) return;
  pending = true;
  studio++;
  requestAnimationFrame(() => {
    pending = false;
    drawNow();
  });
}
function drawNow() {
  const dpr = Math.min(window.devicePixelRatio || 1, maxScale);
  const w = Math.round(canvas.clientWidth * dpr);
  const h = Math.round(canvas.clientHeight * dpr);
  if(canvas.width !== w || canvas.height !== h) {
    canvas.width = w;
    canvas.height = h;
  }
  const start = showSpeed ? performance.now() : 0;
  // (2: the scene gives off phlogiston, less over the next frames)
  if(web.draw(w, h, dpr) === 2) setTimeout(draw, 30);
  if(showSpeed) speedFrame(performance.now() - start, dpr);
  drawn = [w, h, dpr];
  studioFrames();
  showNotes();
}
// the mouse: the events of the canvas go to the same interaction as in the
// graphical interface (src/graphics/sceneView.cpp, through webApp.cpp):
// left drag rotates, right drag pans, middle or shift drag zooms, the wheel
// zooms at the cursor, Ctrl+click starts a lasso to zoom on, Ctrl+right click
// resets the view; what is under the cursor is named in a box by it
export const lasso = $('lasso'), hover = $('hover');
// what shows the shape being placed again after an event of the scene (a
// click puts it), if one is being placed: its form
export let placementChanged = null;
export function setPlacementChanged(f) { placementChanged = f; }
function mouse(kind, e, wheel = 0) {
  const mods = modifiers(e, true);
  // the page numbers the buttons 0 left, 1 middle, 2 right; the scene 0
  // left, 1 right, 2 middle
  const button = e.button === 2 ? 1 : e.button === 1 ? 2 : 0;
  const at = canvas.getBoundingClientRect();
  const redraw = web.mouse(kind, e.clientX - at.left, e.clientY - at.top,
                           canvas.clientWidth, canvas.clientHeight, button, wheel, mods);
  if(placementChanged) placementChanged();
  // the boxes over the canvas, placed in the window
  // the box hangs from the point the view keeps, so it follows the pointer
  // only once it has strayed, as in the graphical interface
  const [text, hx, hy] = web.hoverText();
  if(text) {
    hover.textContent = text;
    hover.style.display = 'block';
    // below and to the right of the point, or on the other side of it when
    // the box would leave the canvas
    let x = hx + 12, y = hy + 16;
    if(x + hover.offsetWidth > canvas.clientWidth) x = hx - 12 - hover.offsetWidth;
    if(y + hover.offsetHeight > canvas.clientHeight) y = hy - 16 - hover.offsetHeight;
    hover.style.left = (at.left + Math.max(0, x)) + 'px';
    hover.style.top = (at.top + Math.max(0, y)) + 'px';
  }
  else
    hover.style.display = 'none';
  canvas.style.cursor = web.crossCursor() ? 'crosshair' : 'default';
  // the lasso rectangle, drawn by the page over the canvas
  const r = web.lasso();
  if(r) {
    lasso.style.left = (at.left + Math.min(r[0], r[2])) + 'px';
    lasso.style.top = (at.top + Math.min(r[1], r[3])) + 'px';
    lasso.style.width = Math.abs(r[2] - r[0]) + 'px';
    lasso.style.height = Math.abs(r[3] - r[1]) + 'px';
    lasso.style.display = 'block';
  }
  else
    lasso.style.display = 'none';
  // (the notes of a query or a measurement too: an event that picked drew
  // the frame itself)
  if(tool) {
    toolStatus();
    showNotes();
  }
  // (a frame drawn by the event itself, after picking, starts the studio
  // frames again; they stop at once if there are none to add)
  if(redraw) draw();
  else studioFrames();
}
// the notches the wheel turned, as the graphical interface counts them (one
// an event): a mouse wheel reports about a hundred pixels or three lines a
// notch, a trackpad a few pixels at a time, and a pinch on a trackpad comes
// as a wheel with Ctrl, in still smaller steps
function wheelNotches(e) {
  if(e.deltaMode === 1) return e.deltaY / 3;
  if(e.deltaMode === 2) return 3 * Math.sign(e.deltaY);
  const n = e.deltaY / (e.ctrlKey ? 2 : 10);
  return Math.max(-5, Math.min(5, n));
}
// A touch screen: one finger is the left button (it rotates, picks, queries),
// two pinch to zoom and move together to pan, about the point between them,
// until both are lifted; a double tap opens the quick access menu, as a
// double-click
let pressed = false, pinching = false;
const touches = new Map();
let lastTap = {t: 0, x: 0, y: 0}, touchDown = null;
const inCanvas = (e) => {
  const at = canvas.getBoundingClientRect();
  return {x: e.clientX - at.left, y: e.clientY - at.top};
};
function pinch(kind) {
  // (the end of a pinch needs no position: one finger is gone)
  const [a, b = a] = [...touches.values()];
  if(web.pinch(kind, (a.x + b.x) / 2, (a.y + b.y) / 2, Math.hypot(a.x - b.x, a.y - b.y))) draw();
}
function pointerUp(e) {
  if(touches.delete(e.pointerId) && pinching) {
    if(touches.size === 1) pinch(2);
    if(!touches.size) pinching = false;
    return;
  }
  if(!pressed) return;
  pressed = false;
  mouse(2, e);
  // a tap, a second one soon after and near it opening the quick menu
  if(e.pointerType === 'touch' && touchDown) {
    const t = e.timeStamp, x = e.clientX, y = e.clientY;
    if(t - lastTap.t < 350 && Math.hypot(x - lastTap.x, y - lastTap.y) < 30) {
      lastTap.t = 0;
      openQuickMenu(x, y);
    }
    else
      lastTap = {t, x, y};
  }
  touchDown = null;
}
// A size dragged on a handle (the variable of the page's CSS), kept for the
// next visits (under key): given by the pointer through size(), within its
// bounds; a double-click gives back the default
function sizeHandle(handle, variable, key, size, bounds) {
  const set = (v) => {
    if(v) {
      v = Math.max(bounds[0], Math.min(v, bounds[1]()));
      document.body.style.setProperty(variable, v + 'px');
    }
    else
      document.body.style.removeProperty(variable);
    try {
      if(v) localStorage.setItem(key, v); else localStorage.removeItem(key);
    } catch(e) {}
    draw();
  };
  try { const v = Number(localStorage.getItem(key)); if(v) set(v); } catch(e) {}
  handle.addEventListener('pointerdown', (e) => {
    handle.setPointerCapture(e.pointerId);
    handle.classList.add('on');
  });
  handle.addEventListener('pointermove', (e) => {
    if(handle.hasPointerCapture(e.pointerId)) set(size(e));
  });
  handle.addEventListener('pointerup', () => handle.classList.remove('on'));
  handle.addEventListener('dblclick', () => set(0));
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  canvas.addEventListener('pointerdown', (e) => {
    // a touch of the scene closes the panel over it (small screens)
    if(sideOver()) {
      showSide(false);
      return;
    }
    // (not for a pointer the browser has let go of already)
    try { canvas.setPointerCapture(e.pointerId); } catch(err) {}
    if(e.pointerType === 'touch') {
      touches.set(e.pointerId, inCanvas(e));
      if(touches.size === 2 && !pinching) {
        // the first finger's drag ends where it is
        if(pressed) {
          pressed = false;
          const [a] = touches.values();
          const at = canvas.getBoundingClientRect();
          mouse(2, {clientX: at.left + a.x, clientY: at.top + a.y, button: 0});
        }
        pinching = true;
        pinch(0);
      }
      if(pinching) return;
      touchDown = {t: e.timeStamp, x: e.clientX, y: e.clientY};
    }
    pressed = true;
    mouse(1, e);
  });
  canvas.addEventListener('pointermove', (e) => {
    if(touches.has(e.pointerId)) {
      touches.set(e.pointerId, inCanvas(e));
      if(pinching) {
        if(touches.size >= 2) pinch(1);
        return;
      }
      if(touchDown && Math.hypot(e.clientX - touchDown.x, e.clientY - touchDown.y) > 10)
        touchDown = null;
    }
    mouse(pressed ? 3 : 0, e);
  });
  canvas.addEventListener('pointerup', pointerUp);
  canvas.addEventListener('pointercancel', pointerUp);
  canvas.addEventListener('pointerleave', (e) => {
    if(pressed || e.pointerType === 'touch') return;
    web.mouseLeft();
    hover.style.display = 'none';
    canvas.style.cursor = 'default';
    draw();
  });
  canvas.addEventListener('contextmenu', (e) => e.preventDefault());
  // no zoom of the page itself on a touch screen (Safari's double tap and
  // pinch), which left it scaled up: the touches of the scene are its own
  // (pointer events, which this does not stop), and the page is not zoomed
  document.addEventListener('gesturestart', (e) => e.preventDefault());
  canvas.addEventListener('touchstart', (e) => e.preventDefault(), {passive: false});
  canvas.addEventListener('wheel', (e) => {
    e.preventDefault();
    mouse(4, e, wheelNotches(e));
  }, {passive: false});
  // a double-click opens the quick access menu where it is, as in the
  // graphical interface (see the status bar)
  canvas.addEventListener('dblclick', (e) => {
    if(e.pointerType !== 'touch' && !touches.size) openQuickMenu(e.clientX, e.clientY);
  });
  window.addEventListener('resize', draw);
  // the width of the panel, on the handle beside it: the canvas keeps at least
  // half the window
  sizeHandle($('split'), '--side-width', 'sideWidth', (e) => e.clientX,
             [200, () => window.innerWidth / 2]);
  // the height of the messages, on the handle above them, from the pointer to
  // their bottom but their title: the canvas keeps at least a third of the
  // window
  sizeHandle($('logSplit'), '--log-height', 'logHeight',
             (e) => $('logText').getBoundingClientRect().bottom - e.clientY -
                    $('log').querySelector('summary').offsetHeight,
             [40, () => window.innerHeight * 2 / 3]);
  // the messages shown or hidden by a click on the status, as in the graphical
  // interface
  status.addEventListener('click', () => { $('log').open = !$('log').open; });
  // the canvas resized as the messages are shown or hidden
  $('log').addEventListener('toggle', draw);
}
