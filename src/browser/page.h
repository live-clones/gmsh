// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BROWSER_PAGE_H
#define BROWSER_PAGE_H

#include "GmshConfig.h"

#if defined(HAVE_BROWSER)

// The page. It asks for the state, draws it, and posts back what was done.
//
// It is as plain as it can be on purpose: what is being tried out is whether
// the descriptions of src/gui survive being written down and sent, not whether
// a web page can be made to look like Gmsh.

static const char *const browserPage = R"PAGE(<!doctype html>
<meta charset="utf-8">
<title>Gmsh</title>
<style>
 html,body{height:100%;margin:0}
 body{font:13px system-ui,sans-serif;background:#f4f4f4;color:#111;
      display:flex;flex-direction:column}
 #bar{background:#e3e3e3;border-bottom:1px solid #bbb;padding:2px 6px;
      display:flex;gap:2px;flex:none}
 .top{padding:3px 9px;cursor:default;position:relative}
 .top:hover{background:#cfd8ff}
 .drop{display:none;position:absolute;left:0;top:100%;background:#fff;
       border:1px solid #bbb;box-shadow:0 2px 8px #0003;min-width:230px;z-index:9}
 .top:hover>.drop,.item:hover>.drop{display:block}
 .item{padding:3px 10px;white-space:nowrap;display:flex;justify-content:space-between;
       gap:24px;position:relative}
 .item:hover{background:#cfd8ff}
 .item.off{color:#999}
 .key{color:#777}
 .sub>.drop{left:100%;top:0}
 .hr{border-top:1px solid #ddd;margin:3px 0}
 #middle{flex:1;display:flex;min-height:0;position:relative}
 #tree{width:290px;flex:none;overflow:auto;background:#fff;
       border-right:1px solid #ccc;padding:4px 0}
 .node{display:flex;align-items:center;gap:4px;padding:1px 6px;white-space:nowrap}
 .node:hover{background:#eef1ff}
 .arrow{width:12px;text-align:center;cursor:default;color:#555;flex:none}
 .leaf{cursor:default}
 .leaf:hover{text-decoration:underline}
 .picked{accent-color:#356}
 #scene{flex:1;min-width:260px;background:#222;position:relative;overflow:hidden}
 #view{display:block;width:100%;height:100%;object-fit:contain;cursor:crosshair;
       user-select:none;-webkit-user-drag:none}
 /* The windows float over everything, inside the page: the desk is the
    layer they live on, and lets the pointer through wherever none of them is.
    Docking moves one out of that layer and into the column on the right,
    which takes its width from the scene rather than covering it. */
 #desk{position:absolute;inset:0;pointer-events:none;z-index:5}
 #dock{flex:none;width:330px;overflow:auto;background:#efefef;
       border-left:1px solid #ccc;padding:8px;display:flex;
       flex-direction:column;gap:10px;align-items:stretch}
 #dock:empty{display:none}
 .form{position:absolute;pointer-events:auto;background:#fff;
       border:1px solid #999;box-shadow:0 6px 20px #0004;min-width:300px;
       max-width:calc(100% - 16px);max-height:calc(100% - 16px);
       display:flex;flex-direction:column}
 #dock .form{position:static;box-shadow:none;border-color:#ccc;
             max-height:none;min-width:0}
 .form h2{font-size:13px;margin:0;padding:5px 8px;background:#ececec;
          border-bottom:1px solid #ccc;display:flex;gap:10px;
          align-items:center;cursor:move;user-select:none}
 .form h2 .name{flex:1;overflow:hidden;text-overflow:ellipsis;
                white-space:nowrap}
 .form h2 button{font:12px system-ui;line-height:1;padding:1px 5px;
                 border:1px solid #bbb;background:#f7f7f7;cursor:default}
 #dock .form h2{cursor:default}
 .form .body{display:flex;align-items:stretch;min-height:0;overflow:hidden}
 .form .main{flex:1;min-width:0;overflow:auto;padding-bottom:5px}
 .form .aside{flex:none;width:150px;overflow:auto;border-right:1px solid #ddd;
              padding:3px 0}
 .list{border:1px solid #ccc;background:#fff;overflow:auto;max-height:240px;
       flex:1;min-width:0}
 .aside .list{border:none;max-height:none}
 .pick{padding:1px 8px;white-space:nowrap;cursor:default}
 .pick:hover{background:#eef1ff}
 .pick.on{background:#cfd8ff}
 .tabs{display:flex;gap:2px;padding:4px 6px 0;border-bottom:1px solid #ccc;
       flex-wrap:wrap}
 .tab{padding:3px 9px;border:1px solid #ccc;border-bottom:none;background:#eee;
      cursor:default}
 .tab.on{background:#fff;font-weight:600}
 .row{display:flex;align-items:center;gap:8px;padding:3px 8px}
 .row label{flex:1;order:2}
 .row input,.row select{order:1;width:135px}
 .row.act{justify-content:flex-start}
 #console{flex:none;height:150px;overflow:auto;margin:0;padding:6px 8px;
          background:#fff;border-top:1px solid #ccc;
          font:11px ui-monospace,monospace;white-space:pre-wrap}
 #foot{flex:none;background:#e3e3e3;border-top:1px solid #bbb;padding:2px 6px;
       display:flex;align-items:center;gap:4px}
 #foot button{font:11px system-ui;padding:1px 6px}
 #foot button.on{background:#cfd8ff}
 #status{margin-left:8px;font-size:12px;color:#333}
 .note{padding:10px;color:#666}
</style>
<div id="bar"></div>
<div id="middle"><div id="tree"></div><div id="scene"><img id="view"></div>
 <div id="dock"></div><div id="desk"></div></div>
<pre id="console"></pre>
<div id="foot"><span id="buttons"></span><span id="status"></span></div>
<script>
// The page draws what Gmsh says it is showing, and posts back what was done.
//
// The one thing it must not do is redraw something that is being used: the
// hover a menu is held open by, and the field one is typing in, both live in
// the DOM. So every part of the page is drawn again only when that part has
// changed, and each part remembers what it was last given. A chrome that was
// pushed to would be told what changed; this one has to work it out, which is
// the price of asking rather than being told.
let busy = false, overBar = false;
const was = {};                       // what each part was last drawn from
function fresh(part, said) {          // has this part changed since last time?
  const key = JSON.stringify(said);
  if(was[part] === key) return false;
  was[part] = key;
  return true;
}
function typing() {
  const on = document.activeElement;
  return on && (on.tagName === 'INPUT' || on.tagName === 'SELECT');
}
async function post(where, what) {
  // Nothing is drawn again while a change is in flight, or the page would
  // draw what Gmsh has not done yet. But a tool that picks does not answer
  // until the user has clicked something in the scene, so the wait is let go
  // of after a moment: the interface has to stay alive under the tool, which
  // is the only way left to give it up.
  busy = true;
  const letGo = setTimeout(() => { busy = false; refresh(); }, 300);
  try { await fetch(where, {method:'POST', body:what}); } catch(e) {}
  clearTimeout(letGo);
  busy = false;
  refresh();                          // what was done changed something
}

// --- the menu bar
function menu(items) {
  const box = document.createElement('div');
  box.className = 'drop';
  for(const it of items) {
    const row = document.createElement('div');
    row.className = 'item' + (it.enabled ? '' : ' off') +
                    (it.children ? ' sub' : '');
    const name = document.createElement('span');
    name.textContent = (it.checked ? '✓ ' : '') + it.label;
    row.appendChild(name);
    if(it.key) {
      const k = document.createElement('span');
      k.className = 'key'; k.textContent = it.key; row.appendChild(k);
    }
    if(it.children) row.appendChild(menu(it.children));
    else if(it.enabled && it.id >= 0)
      row.onclick = () => post('/do', 'id=' + it.id);
    box.appendChild(row);
    if(it.divider) {
      const hr = document.createElement('div'); hr.className = 'hr';
      box.appendChild(hr);
    }
  }
  return box;
}
function drawMenus(menus) {
  const bar = document.getElementById('bar');
  bar.textContent = '';
  for(const top of menus) {
    const t = document.createElement('div');
    t.className = 'top'; t.textContent = top.label;
    if(top.children) t.appendChild(menu(top.children));
    bar.appendChild(t);
  }
}

// --- one field of a form, or of a line of the tree
function field(f) {
  if(f.kind === 'action') {
    const b = document.createElement('button');
    b.textContent = f.label;
    b.onclick = () => post('/do', 'id=' + f.id);
    return b;
  }
  if(f.kind === 'list') {
    const box = document.createElement('div');
    box.className = 'list';
    (f.items || []).forEach((label, i) => {
      const line = document.createElement('div');
      line.className = 'pick' + ((f.on || []).indexOf(i) >= 0 ? ' on' : '');
      line.textContent = label;
      line.onclick = () => post('/choose', 'id=' + f.id + '&i=' + i + '&v=1');
      box.appendChild(line);
    });
    return box;
  }
  let input;
  if(f.kind === 'check') {
    input = document.createElement('input');
    input.type = 'checkbox'; input.checked = f.value === '1';
    input.style.width = 'auto';
    input.onchange = () => post('/set', 'id=' + f.id + '&v=' +
                                 (input.checked ? 1 : 0));
  }
  else if(f.kind === 'choice' && f.choices) {
    input = document.createElement('select');
    for(const c of f.choices) {
      const o = document.createElement('option');
      o.textContent = c; input.appendChild(o);
    }
    input.value = f.value;
    input.onchange = () => post('/set', 'id=' + f.id + '&v=' +
                                 encodeURIComponent(input.value));
  }
  else {
    input = document.createElement('input');
    input.value = f.value;
    if(f.kind === 'output') input.disabled = true;
    input.onchange = () => post('/set', 'id=' + f.id + '&v=' +
                                 encodeURIComponent(input.value));
  }
  return input;
}
function row(f) {
  const box = document.createElement('div');
  box.className = 'row' + (f.kind === 'action' ? ' act' : '');
  if(f.kind === 'label') {
    const s = document.createElement('div');
    s.textContent = f.label; s.style.order = 1; box.appendChild(s);
    return box;
  }
  if(f.kind === 'list') {
    box.style.flexWrap = 'wrap';
    if(f.label) {
      const say = document.createElement('label');
      say.textContent = f.label; say.style.flex = '0 0 100%';
      box.appendChild(say);
    }
    box.appendChild(field(f));
    return box;
  }
  box.appendChild(field(f));
  if(f.kind !== 'action') {
    const say = document.createElement('label');
    say.textContent = f.label; box.appendChild(say);
  }
  return box;
}

// --- the tree down the left side
function drawTree(lines) {
  const box = document.getElementById('tree');
  box.textContent = '';
  for(const n of lines) {
    const line = document.createElement('div');
    line.className = 'node';
    line.style.paddingLeft = (6 + n.depth * 13) + 'px';
    if(n.help) line.title = n.help;
    const arrow = document.createElement('span');
    arrow.className = 'arrow';
    arrow.textContent = n.branch ? (n.open ? '▾' : '▸') : '';
    if(n.branch)
      arrow.onclick = () => post('/open', 'path=' +
                                 encodeURIComponent(n.path) + '&v=' +
                                 (n.open ? 0 : 1));
    line.appendChild(arrow);
    if(n.picked !== undefined) {
      const tick = document.createElement('input');
      tick.type = 'checkbox'; tick.className = 'picked';
      tick.checked = n.picked;
      tick.onchange = () => post('/pick', 'path=' +
                                 encodeURIComponent(n.path) + '&v=' +
                                 (tick.checked ? 1 : 0));
      line.appendChild(tick);
    }
    if(n.field) line.appendChild(field(n.field));
    const name = document.createElement('span');
    // a line that carries a widget takes its name from it
    name.textContent = n.field ? n.field.label : n.label;
    if(n.id >= 0) {
      name.className = 'leaf';
      name.onclick = () => post('/do', 'id=' + n.id);
    }
    else if(n.branch) {
      name.style.cursor = 'default';
      name.onclick = () => post('/open', 'path=' +
                               encodeURIComponent(n.path) + '&v=' +
                               (n.open ? 0 : 1));
    }
    line.appendChild(name);
    box.appendChild(line);
  }
}

// --- the forms that are up
//
// A form is a window of its own, floating over the page and dragged by its
// title, or docked into the column on the right. Where each one sits is the
// page's own business -- Gmsh says what a form holds, not where it is -- so
// it is kept here, by the number of the form, and survives the redraws.
const placed = {};
let dragging = null, highest = 10;
function place(id) {
  if(!placed[id]) {
    const n = Object.keys(placed).length;
    placed[id] = {x: 70 + 28 * (n % 7), y: 30 + 28 * (n % 7),
                  docked: false, z: ++highest};
  }
  return placed[id];
}
function deskRect() {
  return document.getElementById('desk').getBoundingClientRect();
}
function grab(e, card, at) {
  if(e.target.tagName === 'BUTTON') return;
  const r = deskRect();
  dragging = {at: at, card: card,
              dx: e.clientX - r.left - at.x, dy: e.clientY - r.top - at.y};
  card.style.zIndex = at.z = ++highest;
  e.preventDefault();
}
window.addEventListener('mousemove', e => {
  if(!dragging) return;
  const r = deskRect(), at = dragging.at;
  // it stays inside the page: a window one cannot reach is a window lost
  at.x = Math.max(0, Math.min(e.clientX - r.left - dragging.dx, r.width - 80));
  at.y = Math.max(0, Math.min(e.clientY - r.top - dragging.dy, r.height - 26));
  dragging.card.style.left = at.x + 'px';
  dragging.card.style.top = at.y + 'px';
});
window.addEventListener('mouseup', () => { dragging = null; });

let showing = [];                     // the forms as they were last drawn
function drawForms(forms) {
  showing = forms;
  const desk = document.getElementById('desk');
  const dock = document.getElementById('dock');
  desk.textContent = ''; dock.textContent = '';
  const up = {};
  for(const form of forms) {
    up[form.id] = true;
    const at = place(form.id);
    const card = document.createElement('div');
    card.className = 'form';
    const h = document.createElement('h2');
    const name = document.createElement('span');
    name.className = 'name'; name.textContent = form.title;
    h.appendChild(name);
    const side = document.createElement('button');
    side.textContent = at.docked ? '❐' : '▤';
    side.title = at.docked ? 'let it float' : 'dock it to the side';
    side.onclick = () => { at.docked = !at.docked; drawForms(showing); };
    h.appendChild(side);
    const shut = document.createElement('button');
    shut.textContent = '×'; shut.title = 'close';
    shut.onclick = () => post('/close', 'form=' + form.id);
    h.appendChild(shut);
    if(!at.docked) h.onmousedown = e => grab(e, card, at);
    card.appendChild(h);
    if(form.tabs && form.tabs.length > 1) {
      const tabs = document.createElement('div'); tabs.className = 'tabs';
      form.tabs.forEach((label, i) => {
        const tab = document.createElement('div');
        tab.className = 'tab' + (i === form.pane ? ' on' : '');
        tab.textContent = label || '\u00b7';
        tab.onclick = () => post('/pane', 'form=' + form.id + '&i=' + i);
        tabs.appendChild(tab);
      });
      card.appendChild(tabs);
    }
    const body = document.createElement('div'); body.className = 'body';
    if(form.side && form.side.length) {
      // the column down the left: what the panes act upon, which for the
      // option window is the category it is showing
      const aside = document.createElement('div'); aside.className = 'aside';
      for(const f of form.side)
        aside.appendChild(f.kind === 'list' ? field(f) : row(f));
      body.appendChild(aside);
    }
    const main = document.createElement('div'); main.className = 'main';
    for(const f of form.fields) main.appendChild(row(f));
    body.appendChild(main);
    card.appendChild(body);
    if(at.docked) { dock.appendChild(card); }
    else {
      card.style.left = at.x + 'px';
      card.style.top = at.y + 'px';
      card.style.zIndex = at.z;
      card.onmousedown = () => { card.style.zIndex = at.z = ++highest; };
      desk.appendChild(card);
    }
  }
  // a window that is gone forgets where it was
  for(const id in placed) if(!up[id]) delete placed[id];
}

// --- the row of little buttons along the bottom
function drawButtons(buttons) {
  const box = document.getElementById('buttons');
  box.textContent = '';
  for(const b of buttons) {
    const button = document.createElement('button');
    button.textContent = b.label;
    if(b.help) button.title = b.help;
    if(b.on) button.className = 'on';
    button.disabled = !b.enabled;
    if(b.id >= 0) button.onclick = () => post('/do', 'id=' + b.id);
    box.appendChild(button);
  }
}

function draw(state) {
  // a menu is held open by the pointer being on it: leave it alone
  if(!overBar && fresh('menus', state.menus)) drawMenus(state.menus);
  if(fresh('tree', state.tree)) drawTree(state.tree);
  if(fresh('bar', state.bar)) drawButtons(state.bar);
  if(!typing() && !dragging && fresh('forms', state.forms))
    drawForms(state.forms);
  if(fresh('log', state.messages)) {
    const log = document.getElementById('console');
    const atEnd = log.scrollTop + log.clientHeight >= log.scrollHeight - 4;
    log.textContent = state.messages.join('\n');
    if(atEnd) log.scrollTop = log.scrollHeight;
  }
  if(fresh('status', state.status))
    document.getElementById('status').textContent = state.status;
}

// --- the 3D scene, as a picture
//
// A page cannot be handed an OpenGL context, so what arrives is a frame and
// what goes back is what the pointer did over it. It is a remote view and it
// costs what one costs: a frame crosses on every move. Whether that is
// tolerable is a thing worth knowing, which is why it is here.
const view = document.getElementById('view');
let sceneBusy = false, sceneAgain = false, sceneSize = '';
async function frame() {
  if(sceneBusy) { sceneAgain = true; return; }
  sceneBusy = true;
  try {
    const box = document.getElementById('scene').getBoundingClientRect();
    const want = Math.round(box.width) + 'x' + Math.round(box.height);
    if(want !== sceneSize && box.width > 32) {
      sceneSize = want;
      await fetch('/size', {method:'POST', body:'w=' + Math.round(box.width) +
                                                '&h=' + Math.round(box.height)});
    }
    const r = await fetch('/scene?' + Date.now());
    const blob = await r.blob();
    if(blob.size) {
      const old = view.src;
      view.src = URL.createObjectURL(blob);
      if(old.startsWith('blob:')) URL.revokeObjectURL(old);
    }
  } catch(e) {}
  sceneBusy = false;
  if(sceneAgain) { sceneAgain = false; frame(); }
}
function where(e) {
  const box = view.getBoundingClientRect();
  return 'x=' + Math.round(e.clientX - box.left) +
         '&y=' + Math.round(e.clientY - box.top) +
         '&b=' + (e.button === 1 ? 2 : e.button === 2 ? 1 : 0) +
         '&s=' + (e.shiftKey ? 1 : 0) + '&c=' + (e.ctrlKey ? 1 : 0) +
         '&a=' + (e.altKey ? 1 : 0);
}
async function pointer(e, what, wheel) {
  await fetch('/pointer', {method:'POST',
                           body: where(e) + '&w=' + what + '&d=' + (wheel || 0)});
  frame();
}
view.oncontextmenu = e => e.preventDefault();
view.onmousedown = e => { e.preventDefault(); pointer(e, 1); };
view.onmouseup = e => pointer(e, 2);
view.onmousemove = e => { if(e.buttons) pointer(e, 0); };
view.onwheel = e => { e.preventDefault(); pointer(e, 3, e.deltaY > 0 ? -1 : 1); };

async function refresh() {
  if(busy) return;
  try {
    draw(await (await fetch('/state')).json());
  } catch(e) {
    document.getElementById('status').textContent = 'Gmsh has gone away.';
  }
}
// A picking listens for a key: 'e' ends it, 'u' undoes the last one, 'q'
// gives it up. The status bar says which, as the window this reproduces does.
window.addEventListener('keydown', e => {
  if(typing() || e.ctrlKey || e.altKey || e.metaKey) return;
  if(e.key.length !== 1) return;
  fetch('/key', {method:'POST', body:'k=' + encodeURIComponent(e.key)});
});
document.getElementById('bar').onmouseenter = () => { overBar = true; };
document.getElementById('bar').onmouseleave = () => { overBar = false; };
refresh();
frame();
setInterval(refresh, 120);
// the model may be redrawn by something other than the pointer -- a mesh
// finishing, an option changing -- so the picture is asked for as well
setInterval(frame, 400);
</script>
)PAGE";

#endif

#endif
