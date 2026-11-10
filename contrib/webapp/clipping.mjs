// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The Clipping tab, as the clipping window of the FLTK graphical user
// interface: six planes or a box, what they clip and how volumes are cut

import {$, gmsh} from './app.mjs';
import {views} from './options.mjs';
import {draw} from './scene.mjs';

// the clipping, as the clipping window of the graphical interface: one of six
// planes (A X + B Y + C Z + D = 0, what is on the positive side kept) or a
// box (the six planes around a center), what it clips (the geometry, the
// mesh, each view: a bit for each plane in Geometry.Clip, Mesh.Clip and
// View.Clip), and how volumes are cut. While a slider moves, OpenGL alone
// clips (whole elements and capping walk every element), the bounding box
// shown
const getNum = (n) => gmsh.option.getNumber(n);
const setNum = (n, v) => gmsh.option.setNumber(n, v);
const fmt = (v) => String(Number(Number(v).toPrecision(6)));
let clipBoxMode = false;
const clipIndex = () => Number($('clipNum').value);
const coef = (i, j) => `General.Clip${i}${'ABCD'[j]}`;
// the model's box, as the scene has it
function sceneBox() {
  const min = ['X', 'Y', 'Z'].map((c) => getNum('General.Min' + c));
  const max = ['X', 'Y', 'Z'].map((c) => getNum('General.Max' + c));
  return {min, max, center: min.map((m, i) => (m + max[i]) / 2),
          size: min.map((m, i) => max[i] - m)};
}
// a value with a slider over its range: input(v, adjusting) while it moves,
// adjusting false when it is let go or typed
function slider(text, input) {
  const row = document.createElement('label');
  row.className = 'row wide';
  const label = document.createElement('span');
  label.textContent = text;
  const wrap = document.createElement('span');
  wrap.className = 'slider';
  const range = document.createElement('input');
  range.type = 'range';
  const number = document.createElement('input');
  number.type = 'number';
  number.step = 'any';
  range.addEventListener('input', () => { number.value = fmt(range.value); input(true); });
  range.addEventListener('change', () => input(false));
  number.addEventListener('change', () => { range.value = number.value; input(false); });
  wrap.append(range, number);
  row.append(label, wrap);
  return {row, get value() { return Number(number.value); },
          set(v) { number.value = fmt(v); range.value = v; },
          range(min, max) {
            if(!(max > min)) { min -= 1; max += 1; }
            Object.assign(range, {min, max, step: (max - min) / 400});
          }};
}
function check(parent, text, title, change) {
  const row = document.createElement('label');
  row.className = 'row';
  const label = document.createElement('span');
  label.textContent = text;
  const cb = document.createElement('input');
  cb.type = 'checkbox';
  cb.title = title;
  cb.addEventListener('change', change);
  row.append(label, cb);
  parent.appendChild(row);
  return cb;
}
let planeSliders;
let boxSliders;
let clipModes;
let clipTargets = [];
// the range of D: the plane anywhere across the model, as its normal is
function offsetRange([a, b, c]) {
  const {min, max} = sceneBox();
  let lo = Infinity, hi = -Infinity;
  for(let k = 0; k < 8; k++) {
    const p = [0, 1, 2].map((j) => ((k >> j) & 1 ? max : min)[j]);
    const d = -(a * p[0] + b * p[1] + c * p[2]);
    lo = Math.min(lo, d);
    hi = Math.max(hi, d);
  }
  const m = 0.02 * (hi - lo);
  planeSliders[3].range(lo - m, hi + m);
}
// the page as the options are
export function readClipping() {
  const i = clipIndex();
  const n = views();
  const names = ['Geometry', 'Mesh'];
  for(let v = 0; v < n; v++) names.push(gmsh.option.getString(`View[${v}].Name`));
  const masks = [getNum('Geometry.Clip'), getNum('Mesh.Clip')];
  for(let v = 0; v < n; v++) masks.push(getNum(`View[${v}].Clip`));
  $('clipTargets').textContent = '';
  clipTargets = names.map((t, k) =>
    check($('clipTargets'), t, k < 2 ? t + '.Clip' : `View[${k - 2}].Clip`,
          () => applyClip(false)));
  // the box clips with all six planes
  clipTargets.forEach((cb, k) => {
    cb.checked = clipBoxMode ? (masks[k] & 63) === 63 : !!(masks[k] & (1 << i));
  });
  const p = [0, 1, 2, 3].map((j) => getNum(coef(i, j)));
  for(let j = 0; j < 3; j++) planeSliders[j].range(-1, 1);
  offsetRange(p);
  p.forEach((v, j) => planeSliders[j].set(v));
  // the box of the planes 0 to 5, as the graphical interface reads it
  const d = (k) => getNum(coef(k, 3));
  const {min, max, size} = sceneBox();
  for(let j = 0; j < 3; j++) {
    const m = 0.5 * Math.max(...size);
    boxSliders[j].range(min[j] - m, max[j] + m);
    boxSliders[j + 3].range(0, 2 * Math.max(...size));
    boxSliders[j].set((-d(j) + d(j + 3)) / 2);
    boxSliders[j + 3].set(d(j) + d(j + 3));
  }
  clipModes.forEach((cb, k) => { cb.checked = !!getNum(cb.title); });
  clipStates();
}
// the modes that apply, and what the plane or the box clips
function clipStates() {
  const [cap, whole, layer, only] = clipModes;
  whole.disabled = cap.checked;
  layer.disabled = only.disabled = cap.checked || !whole.checked;
  const n = clipTargets.filter((cb) => cb.checked).length;
  $('clipCount').textContent = (clipBoxMode ? 'The box clips ' :
    `Plane ${clipIndex()} clips `) + `${n} of ${clipTargets.length}`;
}
// the options as the page is: a plane, or the box
function applyClip(adjusting) {
  const i = clipIndex();
  const targets = ['Geometry.Clip', 'Mesh.Clip'];
  for(let v = 0; v < views(); v++) targets.push(`View[${v}].Clip`);
  targets.forEach((name, k) => {
    if(k >= clipTargets.length) return;
    let mask = getNum(name);
    if(clipBoxMode) mask = clipTargets[k].checked ? 63 : 0;
    else mask = clipTargets[k].checked ? (mask | (1 << i)) : (mask & ~(1 << i));
    setNum(name, mask);
  });
  if(clipBoxMode) {
    const c = [0, 1, 2].map((j) => boxSliders[j].value);
    const s = [0, 1, 2].map((j) => boxSliders[j + 3].value);
    // left, top, near, right, bottom, far
    for(let j = 0; j < 3; j++) {
      const n = [0, 0, 0];
      n[j] = 1;
      [0, 1, 2].forEach((k) => setNum(coef(j, k), n[k]));
      setNum(coef(j, 3), -c[j] + s[j] / 2);
      [0, 1, 2].forEach((k) => setNum(coef(j + 3, k), -n[k]));
      setNum(coef(j + 3, 3), c[j] + s[j] / 2);
    }
  }
  else {
    const p = planeSliders.map((s) => s.value);
    p.forEach((v, j) => setNum(coef(i, j), v));
    offsetRange(p);
  }
  // what is asked for, but OpenGL alone while a value is chosen
  const [cap, whole, layer, only] = clipModes.map((cb) => cb.checked ? 1 : 0);
  setNum('General.ClipCapping', adjusting ? 0 : cap);
  setNum('General.ClipWholeElements', adjusting || cap ? 0 : whole);
  setNum('General.ClipOnlyDrawIntersectingVolume', layer);
  setNum('General.ClipOnlyVolume', only);
  setNum('General.DrawBoundingBoxes', adjusting ? 1 : 0);
  clipStates();
  draw();
}
function clipMode(box) {
  clipBoxMode = box;
  $('clipPlanes').classList.toggle('on', !box);
  $('clipBox').classList.toggle('on', box);
  $('clipPlaneGroup').hidden = box;
  $('clipBoxGroup').hidden = !box;
  readClipping();
  // a box not in use yet starts around the model, clipping all, so that
  // nothing is cut before a side is moved
  if(box && !clipTargets.some((cb) => cb.checked)) {
    const {center, size} = sceneBox();
    for(let j = 0; j < 3; j++) {
      boxSliders[j].set(center[j]);
      boxSliders[j + 3].set(1.02 * size[j] || 1e-6);
    }
    clipTargets.forEach((cb) => { cb.checked = true; });
    applyClip(false);
  }
}

// the page built, once Gmsh is loaded (see main.mjs)
export function build() {
  planeSliders = ['A (normal X)', 'B (normal Y)', 'C (normal Z)', 'D (offset)']
    .map((t) => { const s = slider(t, applyClip); $('clipCoefs').appendChild(s.row); return s; });
  boxSliders = ['Center X', 'Center Y', 'Center Z', 'Size X', 'Size Y', 'Size Z']
    .map((t) => { const s = slider(t, applyClip); $('clipBoxGroup').appendChild(s.row); return s; });
  clipModes = [
    ['Cap volumes', 'General.ClipCapping'],
    ['Keep whole elements', 'General.ClipWholeElements'],
    ['Only draw volume layer', 'General.ClipOnlyDrawIntersectingVolume'],
    ['Only clip volume elements', 'General.ClipOnlyVolume'],
  ].map(([t, o]) => check($('clipModes'), t, o, () => applyClip(false)));
  $('clipPlanes').addEventListener('click', () => clipMode(false));
  $('clipBox').addEventListener('click', () => clipMode(true));
  $('clipNum').addEventListener('change', readClipping);
  $('clipInvert').addEventListener('click', () => {
    planeSliders.forEach((s) => s.set(-s.value));
    applyClip(false);
  });
  // a plane across the middle of the model, its normal along an axis
  for(const b of document.querySelectorAll('#clipPlaneGroup [data-axis]'))
    b.addEventListener('click', () => {
      const j = Number(b.dataset.axis);
      [0, 1, 2].forEach((k) => planeSliders[k].set(k === j ? 1 : 0));
      planeSliders[3].set(-sceneBox().center[j]);
      if(!clipTargets.some((cb) => cb.checked)) clipTargets.forEach((cb) => { cb.checked = true; });
      applyClip(false);
    });
  for(const [id, on] of [['clipAll', true], ['clipNone', false]])
    $(id).addEventListener('click', () => {
      clipTargets.forEach((cb) => { cb.checked = on; });
      applyClip(false);
    });
  // nothing clipped, the planes back to their defaults
  $('clipReset').addEventListener('click', () => {
    setNum('Geometry.Clip', 0);
    setNum('Mesh.Clip', 0);
    for(let v = 0; v < views(); v++) setNum(`View[${v}].Clip`, 0);
    for(let i = 0; i < 6; i++)
      for(let j = 0; j < 4; j++)
        setNum(coef(i, j), (j === i % 3) ? (i < 3 ? 1 : -1) : (j === 3 && i >= 3) ? 1 : 0);
    readClipping();
    draw();
  });
  readClipping();
}
