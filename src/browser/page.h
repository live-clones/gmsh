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
 /* a check on a line of a tree is a check, not a field taking its share of
    the line */
 .node input[type=checkbox]{width:auto;flex:none}
 .node input,.node select{width:135px}
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
 .form .main.scrolls{max-height:26em}
 .form .aside{flex:none;overflow:hidden;border-right:1px solid #ddd;
              padding:3px 0;display:flex;flex-direction:column;
              max-height:26em}
 .form .aside .line{padding:2px 4px}
 .form .aside .cell{flex:1 1 auto}
 .list{border:1px solid #ccc;background:#fff;overflow:auto;flex:1 1 auto;
       min-width:0;min-height:8em;max-height:26em}
 .aside .list{max-height:none}
 .pick{padding:1px 8px;white-space:nowrap;cursor:default}
 .pick:hover{background:#eef1ff}
 .pick.on{background:#cfd8ff}
 .tabs{display:flex;gap:2px;padding:4px 6px 0;border-bottom:1px solid #ccc;
       flex-wrap:wrap}
 .tabs.family{border-bottom:none;padding-bottom:0}
 .tabs.family .tab{background:#e4e4e4}
 .tabs.family .tab.on{background:#eee;font-weight:600}
 .tab{padding:3px 9px;border:1px solid #ccc;border-bottom:none;background:#eee;
      cursor:default}
 .tab.on{background:#fff;font-weight:600}
 /* A line of a pane. What shares a line is what the description says shares
    one, which is most of the layout it carries: these windows are two and
    three columns wide in places. */
 .line{display:flex;align-items:center;gap:8px;padding:2px 8px;flex-wrap:wrap}
 .line.ruled{border-top:1px solid #ddd;margin-top:4px;padding-top:5px}
 /* A cell takes the width it needs and no more, its label running on as far
    as it must: a window is then as wide as its widest line, which is how the
    ones this reproduces are sized. Sharing the line evenly is what the grid
    of a pane laid out on columns is for. */
 .cell{display:flex;align-items:center;gap:6px;flex:0 1 auto;min-width:0}
 .cell.packed{flex:0 0 auto}
 .cell.packed label{flex:0 0 auto}
 /* a row of values with a button after them is not columns of equal width:
    the button goes to the end of the line, as these windows draw it */
 .line.packed .cell.act{margin-left:auto}
 .cell.gap{flex:1 1 auto;min-width:8px}
 /* What shares a line shares the width of one field, rather than each
    taking a whole one: two little numbers under one label are two halves of
    a value, not two values. It is the rule the windows this reproduces are
    laid out by. */
 /* Ten of the font's own size, which is how wide a field is in the windows
    this reproduces, divided by however many share the line. */
 .cell input,.cell select{width:calc(10em / var(--n, 1));min-width:0}
 /* the label runs on rather than wrapping: a window grows to hold what it
    says, as the ones this reproduces do */
 .cell label{flex:0 1 auto;min-width:0;white-space:nowrap}
 /* A button in the flow of the fields starts where its share of the line
    starts, so that two columns of them line up; one on a line of its own --
    what a window does rather than what it holds -- keeps to its own width
    and goes to the end. */
 .line:not(.act)>.cell.act{flex:1 1 0;justify-content:flex-start}
 .line.act>.cell.act{flex:0 0 auto}
 .cell.act{flex:0 0 auto}
 /* a label written before its field is right against it, and as wide as the
    widest of the ones it lines up with -- see square() */
 .cell.before>label{text-align:right;flex:0 0 auto}
 /* A list takes a line of its own. A line of text that runs on over several
    lines takes what is left of the one it is on -- the whole of it when it is
    alone there, half when it is the second of a pair, which is what the list
    of keyboard shortcuts is made of. And it wraps at something one can read
    rather than making the window as wide as its longest line. */
 .cell.whole{flex:1 1 100%}
 .cell.runs>div{white-space:pre-line;max-width:26em}
 .section{margin:6px 8px 2px;border-top:1px solid #ddd;padding-top:4px}
 .section h3{font-size:12px;margin:0 0 2px;color:#444;font-weight:600}
 .section .line{padding-left:0;padding-right:0}
 /* What a window says under its panes. Its lines are lines, one under
    another: three switches are three of them, not one long one. */
 .foot{border-top:1px solid #ccc;padding:3px 0;background:#f7f7f7}
 .foot .line{padding:2px 8px}
 .foot button{min-width:70px}
 .fold{cursor:default;user-select:none;color:#444}
 #console{flex:none;height:150px;overflow:auto;margin:0;padding:6px 8px;
          background:#fff;border-top:1px solid #ccc;
          font:11px ui-monospace,monospace;white-space:pre-wrap}
 #foot{flex:none;background:#e3e3e3;border-top:1px solid #bbb;padding:2px 6px;
       display:flex;align-items:center;gap:4px}
 #foot button{font:11px system-ui;padding:1px 6px}
 #foot button.on{background:#cfd8ff}
 #status{margin-left:8px;font-size:12px;color:#333}
 .note{padding:10px;color:#666}
 /* what the scene says is under the pointer, said where the pointer is */
 #tip{position:absolute;z-index:6;pointer-events:none;max-width:340px;
      background:#ffffe1;color:#111;border:1px solid #999;padding:2px 5px;
      font:11px system-ui;white-space:pre-line;box-shadow:0 2px 6px #0004}
 #tip:empty{display:none}
</style>
<div id="bar"></div>
<div id="middle"><div id="tree"></div><div id="scene"><img id="view"><div id="tip"></div></div>
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
// The word that came in the address. Everything asked of Gmsh carries it:
// without it, any page anyone happens to visit could drive this one.
const KEY = new URLSearchParams(location.search).get('k') || '';
function to(where) {
  return where + (where.indexOf('?') < 0 ? '?' : '&') + 'k=' +
         encodeURIComponent(KEY);
}
// What a number the page was given stands for, sent back with it: between
// being given one and using it, what it pointed at may have moved.
function which(x) { return 'id=' + x.id + '&h=' + x.h; }

function say(where, what) {
  return fetch(to(where), {method: 'POST',
                           body: what + '&k=' + encodeURIComponent(KEY)});
}

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
  try { await say(where, what); } catch(e) {}
  clearTimeout(letGo);
  busy = false;
  refresh();                          // what was done changed something
  frame(true);                        // and it may have changed the picture
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
      row.onclick = () => post('/do', which(it));
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
    b.onclick = () => post('/do', which(f));
    return b;
  }
  if(f.kind === 'hierarchy') {
    const box = document.createElement('div');
    box.className = 'list';
    box.style.height = (f.rows ? f.rows * 1.45 : 16) + 'em';
    treeLines(f.lines || [], box);
    return box;
  }
  if(f.kind === 'menu') {
    const pick = document.createElement('select');
    const head = document.createElement('option');
    head.textContent = f.label; head.value = '';
    pick.appendChild(head);
    for(const label of f.items || []) {
      const o = document.createElement('option');
      o.textContent = label; pick.appendChild(o);
    }
    pick.onchange = () => {
      const at = pick.selectedIndex - 1;
      pick.selectedIndex = 0;
      if(at >= 0) post('/choose', which(f) + '&i=' + at + '&v=1');
    };
    return pick;
  }
  if(f.kind === 'list') {
    const box = document.createElement('div');
    box.className = 'list';
    // as tall as it says: zero means as tall as the window will allow
    // As tall as it says. Nought means as tall as the window allows, which
    // is what is left of it rather than a height the window grows to.
    if(f.rows) box.style.height = (f.rows * 1.45) + 'em';
    (f.items || []).forEach((label, i) => {
      const line = document.createElement('div');
      line.className = 'pick' + ((f.on || []).indexOf(i) >= 0 ? ' on' : '');
      line.textContent = label;
      line.onclick = () => post('/choose', which(f) + '&i=' + i + '&v=1');
      box.appendChild(line);
    });
    return box;
  }
  let input;
  if(f.kind === 'check') {
    input = document.createElement('input');
    input.type = 'checkbox'; input.checked = f.value === '1';
    input.style.width = 'auto';
    input.onchange = () => post('/set', which(f) + '&v=' +
                                 (input.checked ? 1 : 0));
  }
  else if(f.kind === 'choice' && f.choices) {
    input = document.createElement('select');
    for(const c of f.choices) {
      const o = document.createElement('option');
      o.textContent = c; input.appendChild(o);
    }
    input.value = f.value;
    input.onchange = () => post('/set', which(f) + '&v=' +
                                 encodeURIComponent(input.value));
  }
  else {
    input = document.createElement('input');
    input.value = f.value;
    if(f.kind === 'output') input.disabled = true;
    input.onchange = () => post('/set', which(f) + '&v=' +
                                 encodeURIComponent(input.value));
  }
  return input;
}
// One field in its cell, with its label where the description puts it
function cell(f) {
  const box = document.createElement('div');
  box.className = 'cell' + (f.kind === 'action' ? ' act' : '') +
                  (f.packed ? ' packed' : '') +
                  (f.kind === 'list' || f.kind === 'hierarchy' ? ' whole' :
                     '') + (f.wraps ? ' runs' : '');
  if(f.help) box.title = f.help;
  if(f.kind === 'gap') { box.className = 'cell gap'; return box; }
  if(f.kind === 'label') {
    // What it says is worked out as the window is drawn -- the help of a
    // size field is a paragraph the field itself writes -- so it is the
    // value that is said, and the label only when there is no value.
    const say = document.createElement('div');
    say.textContent = f.value || f.label;
    box.appendChild(say);
    return box;
  }
  const say = document.createElement('label');
  say.textContent = f.label;
  const what = field(f);
  if(f.em) what.style.width = f.em + 'em';
  if(f.off) what.disabled = true;
  if(f.kind === 'action' || f.kind === 'menu') {
    box.appendChild(what);
    return box;
  }
  if(f.kind === 'list' || f.kind === 'hierarchy') {
    // a list takes the line it is on: what names it, if anything does, is
    // written beside it and takes only what it needs
    box.appendChild(what);
    if(f.label) { say.style.flex = '0 0 auto'; box.appendChild(say); }
    return box;
  }
  if(f.before) {
    // its label comes first, and those of a pane line up: what follows them
    // starts at the same place on every line, as it does in the windows this
    // reproduces
    box.classList.add('before');
    box.appendChild(say);
    box.appendChild(what);
  }
  else { box.appendChild(what); box.appendChild(say); }
  return box;
}

// A run of fields laid out in lines: a field starts a new line unless it says
// it shares the one before it.
function lines(fields, into, columns) {
  // what shares a line, worked out first: whether the line is laid out on
  // equal columns depends on what is in it
  const rows = [];
  for(const f of fields) {
    if(!rows.length || !f.sameRow) rows.push([]);
    rows[rows.length - 1].push(f);
  }
  for(const row of rows) {
    const line = document.createElement('div');
    const packed = row.some(f => f.packed);
    line.className = 'line' + (row[0].rule ? ' ruled' : '') +
                     (packed ? ' packed' : '');
    // A field that takes the width it needs follows the one before it; the
    // rest share the line in columns of equal width, which is how the option
    // window lines two rows up with one another.
    if(columns > 1 && !packed) {
      // The columns of two rows line up, which is the whole point of laying a
      // pane out on columns; but a column is only as wide as what is in it,
      // or a window with one long line in its first column would come out
      // that many times too wide.
      line.style.display = 'grid';
      line.style.gridTemplateColumns = 'repeat(' + columns + ',max-content)';
    }
    // how many of them hold a value, so that they may share the width of one
    const holds = row.filter(f => f.kind !== 'label' && f.kind !== 'gap' &&
                                  f.kind !== 'action' && f.kind !== 'list' &&
                                  f.kind !== 'hierarchy' && f.kind !== 'check' &&
                                  !f.em).length;
    if(holds > 1) line.style.setProperty('--n', holds);
    for(const f of row) line.appendChild(cell(f));
    into.appendChild(line);
  }
}

// the button a pane or a section carries, at the end of its own line
function does(label, what) {
  const b = document.createElement('button');
  b.textContent = label;
  b.onclick = () => post('/do', 'id=' + what.buttonId + '&h=' + what.buttonH);
  return b;
}

function paneBody(pane, into) {
  // a pane that says it scrolls is a pane the window does not grow for
  if(pane.scrolls) into.classList.add('scrolls');
  lines(pane.fields, into, pane.columns);
  for(const section of pane.sections) {
    const box = document.createElement('div');
    box.className = 'section';
    if(section.label) {
      const h = document.createElement('h3');
      h.textContent = section.label;
      box.appendChild(h);
    }
    lines(section.fields, box, section.columns);
    // a section acts as well as holds, and its button goes at the end of it
    if(section.button) {
      const row = document.createElement('div'); row.className = 'line act';
      const gap = document.createElement('div');
      gap.className = 'cell gap'; row.appendChild(gap);
      row.appendChild(does(section.button, section));
      box.appendChild(row);
    }
    into.appendChild(box);
  }
}

// --- the tree down the left side
function drawTree(lines) {
  const box = document.getElementById('tree');
  box.textContent = '';
  treeLines(lines, box);
}

// The lines of a tree, wherever it is drawn: down the left of the window, or
// inside a window that shows the model that way.
function treeLines(lines, box) {
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
      name.onclick = () => post('/do', which(n));
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
// Where the page has put things, said back to Gmsh. Nothing outside a page
// can know that: the bench that photographs the interfaces side by side has
// to be told which part of the picture is the window it came for.
function sayWhere(cards) {
  const parts = [];
  const put = (name, el) => {
    if(!el) return;
    const r = el.getBoundingClientRect();
    parts.push(name + '=' + Math.round(r.left) + ',' + Math.round(r.top) +
               ',' + Math.round(r.width) + ',' + Math.round(r.height));
  };
  put('page', document.body);
  put('bar', document.getElementById('bar'));
  put('tree', document.getElementById('tree'));
  put('scene', document.getElementById('scene'));
  put('console', document.getElementById('console'));
  for(const at of cards) put('form' + at[0], at[1]);
  say('/where', parts.join('&')).catch(() => {});
}

function drawForms(forms) {
  showing = forms;
  const desk = document.getElementById('desk');
  const dock = document.getElementById('dock');
  desk.textContent = ''; dock.textContent = '';
  const up = {}, told = [];
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
    // The tabs. A window with more panes than fit across one row wears two
    // rows of them: which family first, then which member of it -- the same
    // grouping the description gives the other interfaces.
    if(form.tabbed && form.tabs.length > 1) {
      const families = [];
      form.tabs.forEach((t, i) => {
        if(!t.on) return;
        const name = t.group || '';
        let f = families.find(q => q.name === name && name);
        if(!f) families.push(f = {name: name, panes: []});
        f.panes.push(i);
      });
      const grouped = families.some(f => f.name);
      const openFamily = families.find(f => f.panes.indexOf(form.pane) >= 0);
      if(grouped) {
        const row = document.createElement('div');
        row.className = 'tabs family';
        for(const f of families) {
          const tab = document.createElement('div');
          tab.className = 'tab' + (f === openFamily ? ' on' : '');
          tab.textContent = f.name || form.tabs[f.panes[0]].label;
          tab.onclick = () => post('/pane', 'form=' + form.id +
                                            '&i=' + f.panes[0]);
          row.appendChild(tab);
        }
        card.appendChild(row);
      }
      const shown = grouped && openFamily ? openFamily.panes
                                          : form.tabs.map((t, i) => i);
      // a pane that belongs to no family is named in the row above: a second
      // row saying the same word again is not what these windows wear
      if(!(grouped && openFamily && !openFamily.name)) {
      const row = document.createElement('div'); row.className = 'tabs';
      for(const i of shown) {
        if(!form.tabs[i].on) continue;
        const tab = document.createElement('div');
        tab.className = 'tab' + (i === form.pane ? ' on' : '');
        tab.textContent = form.tabs[i].label || '\u00b7';
        tab.onclick = () => post('/pane', 'form=' + form.id + '&i=' + i);
        row.appendChild(tab);
      }
      card.appendChild(row);
      }
    }
    const body = document.createElement('div'); body.className = 'body';
    if(form.side && form.side.length) {
      // the column down the left: what the panes act upon, which for the
      // option window is the category it is showing
      const aside = document.createElement('div'); aside.className = 'aside';
      aside.style.width = (form.sideEm || 8) + 'em';
      lines(form.side, aside, 0);
      body.appendChild(aside);
    }
    const main = document.createElement('div'); main.className = 'main';
    lines(form.header, main, 0);
    for(const pane of form.panes) {
      if(!form.tabbed && pane.label) {
        const h = document.createElement('h3');
        h.className = 'section'; h.textContent = pane.label;
        main.appendChild(h);
      }
      paneBody(pane, main);
    }
    body.appendChild(main);
    card.appendChild(body);
    // what the window says under its panes, and what it does: the fields on
    // the line of the button come before it, as the windows this reproduces
    // put them
    const pane = form.panes[form.panes.length - 1];
    const beside = pane ? pane.beside : [];
    if(beside.length || (pane && pane.button)) {
      const bar = document.createElement('div'); bar.className = 'foot';
      lines(beside, bar, 0);
      const row = document.createElement('div'); row.className = 'line act';
      const gap = document.createElement('div');
      gap.className = 'cell gap'; row.appendChild(gap);
      if(pane && pane.button) row.appendChild(does(pane.button, pane));
      bar.appendChild(row);
      card.appendChild(bar);
    }
    if(form.footer.length || form.buttons.length) {
      const bar = document.createElement('div'); bar.className = 'foot';
      // A line of the footer is a line, as everywhere else: three switches one
      // under another are three lines, not one long one.
      lines(form.footer, bar, 0);
      if(form.buttons.length) {
        const row = document.createElement('div'); row.className = 'line act';
        const gap = document.createElement('div');
        gap.className = 'cell gap'; row.appendChild(gap);
        for(const b of form.buttons) row.appendChild(does(b.label, b));
        bar.appendChild(row);
      }
      card.appendChild(bar);
    }
    told.push([form.id, card]);
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
  // now that they are in the page and have a width, the labels that come
  // before their fields are squared up
  for(const at of told) square(at[1]);
  sayWhere(told);
}

// Labels written before their field line up: the column is as wide as the
// widest of them, so that what follows starts at the same place on every
// line. Nothing but the page can work that out -- it is the width of a word
// once it is drawn -- so it is done here, once the window is in the page.
function square(card) {
  for(const body of card.querySelectorAll('.main, .aside, .foot')) {
    const labels = [...body.querySelectorAll('.cell.before>label')];
    if(labels.length < 2) continue;
    for(const l of labels) l.style.width = '';
    const widest = Math.max(...labels.map(l => l.offsetWidth));
    for(const l of labels) l.style.width = widest + 'px';
  }
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
    if(b.id >= 0) button.onclick = () => post('/do', which(b));
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
  // how big to draw, which is the application's setting and not the page's
  if(fresh('font', state.font))
    document.body.style.fontSize = state.font + 'px';
  if(fresh('status', state.status))
    document.getElementById('status').textContent = state.status;
  if(fresh('tip', state.tip)) {
    // it says what is under the pointer, which is how one knows a point five
    // pixels wide is about to be picked
    const tip = document.getElementById('tip');
    tip.textContent = state.tip || '';
    if(state.tip) {
      const box = document.getElementById('scene').getBoundingClientRect();
      let x = lastPointer[0] + 16, y = lastPointer[1] + 18;
      if(x + tip.offsetWidth > box.width) x = box.width - tip.offsetWidth - 4;
      if(y + tip.offsetHeight > box.height) y = lastPointer[1] - tip.offsetHeight - 6;
      tip.style.left = Math.max(0, x) + 'px';
      tip.style.top = Math.max(0, y) + 'px';
    }
  }
}

// --- the 3D scene, as a picture
//
// A page cannot be handed an OpenGL context, so what arrives is a frame and
// what goes back is what the pointer did over it. It is a remote view and it
// costs what one costs: a frame crosses on every move. Whether that is
// tolerable is a thing worth knowing, which is why it is here.
const view = document.getElementById('view');
let sceneBusy = false, sceneAgain = false, sceneSize = '';
let sceneW = 1, sceneH = 1;   // the size the scene was last asked at
async function frame(force) {
  if(sceneBusy) { sceneAgain = true; return; }
  sceneBusy = true;
  try {
    const box = document.getElementById('scene').getBoundingClientRect();
    const want = Math.round(box.width) + 'x' + Math.round(box.height);
    if(want !== sceneSize && box.width > 32) {
      sceneSize = want;
      sceneW = Math.round(box.width); sceneH = Math.round(box.height);
      await say('/size', 'w=' + Math.round(box.width) +
                         '&h=' + Math.round(box.height));
    }
    // Nothing comes back when the scene has not moved, and what is showing
    // stays. Asking for it whatever it thinks is for right after something
    // was done: what an action changed is not the scene's business.
    const r = await fetch(to('/scene?' + Date.now() + (force ? '&force' : '')));
    const blob = await r.blob();
    if(blob.size) {
      const old = view.src;
      view.src = URL.createObjectURL(blob);
      if(old.startsWith('blob:')) URL.revokeObjectURL(old);
    }
  } catch(e) {}
  sceneBusy = false;
  if(sceneAgain) { sceneAgain = false; frame(force); }
}
let lastPointer = [0, 0];   // where the pointer is over the scene
function where(e) {
  // The picture fits the box it is drawn in and may be a moment behind it, so
  // where the pointer is is worked out as a fraction of the picture and given
  // back in the size the scene was last asked at -- which is the size the
  // scene itself is working in.
  const box = view.getBoundingClientRect();
  // before the first picture has come there is nothing to measure against
  // but the size that was asked for, which is the shape it will have
  const nw = view.naturalWidth || sceneW, nh = view.naturalHeight || sceneH;
  const k = Math.min(box.width / nw, box.height / nh);
  const w = nw * k || 1, h = nh * k || 1;
  const fx = (e.clientX - box.left - (box.width - w) / 2) / w;
  const fy = (e.clientY - box.top - (box.height - h) / 2) / h;
  lastPointer = [e.clientX - box.left, e.clientY - box.top];
  return 'x=' + Math.round(fx * sceneW) +
         '&y=' + Math.round(fy * sceneH) +
         '&b=' + (e.button === 1 ? 2 : e.button === 2 ? 1 : 0) +
         '&s=' + (e.shiftKey ? 1 : 0) + '&c=' + (e.ctrlKey ? 1 : 0) +
         '&a=' + (e.altKey ? 1 : 0);
}
// A move may be dropped -- there is always another one coming -- but a press
// or a release may not: the modes that place an entity follow the pointer
// without any button held, so plain moves have to be reported too, and one at
// a time is enough to keep up.
let moving = false;
async function pointer(e, what, wheel) {
  if(what === 0) {
    if(moving) return;
    moving = true;
  }
  try {
    await say('/pointer', where(e) + '&w=' + what + '&d=' + (wheel || 0));
  } catch(err) {}
  if(what === 0) moving = false;
  frame();
}
view.oncontextmenu = e => e.preventDefault();
view.onmousedown = e => { e.preventDefault(); pointer(e, 1); };
view.onmouseup = e => pointer(e, 2);
view.onmousemove = e => pointer(e, 0);
view.onwheel = e => { e.preventDefault(); pointer(e, 3, e.deltaY > 0 ? -1 : 1); };

// What Gmsh is showing, drawn again only if it is not what is already drawn.
// The whole answer is compared as it arrived, before anything is made of it:
// an interface sitting still says exactly the same thing every time, and
// reading it is most of what a page costs while nobody is touching it.
let wasSaid = '';
async function refresh() {
  if(busy) return false;
  try {
    const said = await (await say('/state', '')).text();
    if(said === wasSaid) return false;
    wasSaid = said;
    draw(JSON.parse(said));
    return true;
  } catch(e) {
    document.getElementById('status').textContent = 'Gmsh has gone away.';
    wasSaid = '';
    return false;
  }
}
// A picking listens for a key: 'e' ends it, 'u' undoes the last one, 'q'
// gives it up. The status bar says which, as the window this reproduces does.
window.addEventListener('keydown', e => {
  if(typing() || e.ctrlKey || e.altKey || e.metaKey) return;
  if(e.key.length !== 1) return;
  say('/key', 'j=' + encodeURIComponent(e.key));
});
document.getElementById('bar').onmouseenter = () => { overBar = true; };
document.getElementById('bar').onmouseleave = () => { overBar = false; };
frame();
// --- being told, rather than asking
//
// One connection that is never answered and never closed: Gmsh writes a line
// into it whenever it has something new to say, and the browser hands that to
// us as events. Nothing is polled -- a page sitting there costs nothing at
// all -- and what the page does still goes up as plain requests.
//
// EventSource reconnects by itself when the connection drops, so a Gmsh that
// went away and came back is picked up again without anything here noticing.
function listen() {
  const news = new EventSource(to('/events'));
  news.addEventListener('state', e => {
    if(e.data === wasSaid) return;
    wasSaid = e.data;
    try { draw(JSON.parse(e.data)); } catch(err) {}
  });
  news.addEventListener('scene', () => frame(true));
  news.onopen = () => {
    document.getElementById('status').textContent = '';
    // A fresh connection may be a fresh Gmsh, which knows nothing of this
    // page -- not even how big to draw the scene. Everything it has to be
    // told again, it is told again.
    sceneSize = '';
    frame(true);
  };
  news.onerror = () => {
    document.getElementById('status').textContent = 'Gmsh has gone away.';
    wasSaid = '';
  };
}
listen();

// The picture is fetched when Gmsh says it has changed, and once more when a
// tab is looked at again -- what happened while it was hidden was drawn for
// no one.
document.addEventListener('visibilitychange', () => {
  if(document.visibilityState !== 'hidden') frame(true);
});
</script>
)PAGE";

#endif

#endif
