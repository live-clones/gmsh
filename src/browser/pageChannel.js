// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The page's side of pageChannel.cpp, loaded before the page itself when Gmsh
// runs inside it: the addresses the page fetches from Gmsh are put in a queue
// Gmsh takes its questions from, and the event stream it opens is fed by Gmsh
// directly. The page is otherwise the one the HTTP server serves.

(() => {
  let next = 0;
  const waiting = new Map();
  const page = {
    asks: [],
    streams: [],
    ask(path, body) {
      return new Promise(resolve => {
        const id = next++;
        waiting.set(id, resolve);
        page.asks.push({id, path, body});
      });
    },
    give(id, type, bytes) {
      const resolve = waiting.get(id);
      if(!resolve) return;
      waiting.delete(id);
      resolve(new Response(new Blob([bytes], {type}),
                           {headers: {'Content-Type': type}}));
    },
    open(id) {
      const resolve = waiting.get(id);
      if(!resolve) return;
      waiting.delete(id);
      resolve();
    },
    push(name, data) {
      for(const stream of page.streams) stream._tell(name, data);
    },
  };
  globalThis.gmshPage = page;

  // only what is Gmsh's goes to Gmsh: the addresses of the page's own origin
  const fetchElsewhere = globalThis.fetch;
  globalThis.fetch = (where, how) => {
    if(typeof where !== 'string' || !where.startsWith('/'))
      return fetchElsewhere(where, how);
    const body = how && typeof how.body === 'string' ? how.body : '';
    return page.ask(where, body);
  };

  class GmshEvents {
    constructor(where) {
      this._heard = {};
      this.onopen = null;
      this.onerror = null;
      page.ask(where, '').then(() => {
        page.streams.push(this);
        if(this.onopen) this.onopen();
      });
    }
    addEventListener(name, what) {
      (this._heard[name] = this._heard[name] || []).push(what);
    }
    _tell(name, data) {
      for(const what of this._heard[name] || []) what({data});
    }
    close() { page.streams = page.streams.filter(s => s !== this); }
  }
  globalThis.EventSource = GmshEvents;

  // the scene is drawn on a canvas nobody sees, and read back into the
  // pictures the page shows: its drawing must outlive the frame
  const canvas = document.createElement('canvas');
  const getContext = canvas.getContext.bind(canvas);
  canvas.getContext = (kind, how) =>
    getContext(kind, Object.assign({}, how, {preserveDrawingBuffer: true}));

  // what to open, from the address: gmsh.html?open=tutorials/t1.geo
  const open = new URLSearchParams(location.search).getAll('open');
  globalThis.Module = {
    arguments: open.concat(['-gui', 'browser']),
    canvas,
    print: text => console.log(text),
    printErr: text => console.warn(text),
  };
})();
