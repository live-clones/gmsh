// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Mesh.ValenceRepair2D: rework the triangle mesh of a planar surface toward
// valence 6 inside (and on the boundary the valence its angle calls for) and
// toward equilateral triangles.
//
// Energy E = sum over the nodes of (v - v*)^2, v* = 6 inside and 1 +
// round(angle / 60 degrees) on the boundary. Three local operations change it
// by a known amount (flip, collapse, insertion); they are chosen greedily
// (type 1), then by gliding the 5-7 dislocations of the mesh toward each
// other (type 2: a glide flip moves a 5-7 pair by one lattice step
// perpendicular to its bond), and every change is checked geometrically after
// a local smoothing, and undone exactly when refused. An ODT smoothing
// follows; the triangles of quality gamma below Mesh.ValenceRepairThreshold2D
// are then remeshed locally, worst first, and a last ODT smoothing ends.
// Nodes on curves and points never disappear; the edges of the curves are
// never flipped nor split; nodes on curves may slide along their curve
// (Mesh.BoundaryNodeSliding2D, see meshGFacePlanar.h).

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <optional>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <functional>
#include <string>
#include "meshGFaceValence.h"
#include "meshGFacePlanar.h"
#include "GFace.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"

namespace {

using namespace planar;

// ---------------------------------------------------------------------------
// mesh with local topological operations and exact undos

struct FlipRec {
  int a = -1, b = 0, c = 0, d = 0, t1 = 0, t2 = 0;
  bool ok() const { return a >= 0; }
};

struct CollapseRec {
  int a = -1, b = 0, c = 0, d = 0;
  V2 xb = {0, 0};
  std::vector<std::pair<int, std::array<int, 3>>> tris;
  std::array<std::vector<int>, 4> vt;
  std::array<int, 4> val = {0, 0, 0, 0};
  bool ok() const { return a >= 0; }
};

struct SplitRec {
  int n = -1, a = 0, b = 0, c = 0, d = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0;
  bool ok() const { return n >= 0; }
};

struct Quad {
  int t1, t2, c, d;
};

struct TopoMesh : planar::Mesh {
  std::vector<int> vstar, val;
  std::set<std::pair<int, int>> constrained;
  bool isConstrained(int a, int b) const
  {
    // the edges of the curves join two nodes on curves
    if(!onBnd[a] || !onBnd[b] || constrained.empty()) return false;
    return constrained.count({std::min(a, b), std::max(a, b)});
  }
  // scratch marks for rings
  std::vector<int> markV, markT;
  int stamp = 0, ringStamp = 0;

  // onCurve: nodes on curves or points (never removed, fixed unless they
  // slide); constrainedEdges: edges of curves (never flipped nor split)
  TopoMesh(const std::vector<V2> &x0, const std::vector<std::array<int, 3>> &t0,
           const std::vector<char> &onCurve,
           const std::vector<std::pair<int, int>> &constrainedEdges)
    : planar::Mesh(x0, t0, onCurve)
  {
    for(auto &e : constrainedEdges)
      constrained.insert({std::min(e.first, e.second),
                          std::max(e.first, e.second)});
    // interior angle at each node of the boundary, ideal valence, valence
    std::vector<double> angle(nv, 0.);
    for(auto &t : tri)
      for(int k = 0; k < 3; k++) {
        if(!openFan[t[k]]) continue;
        V2 p = x[t[k]], q = x[t[(k + 1) % 3]], r = x[t[(k + 2) % 3]];
        V2 u = q - p, w = r - p;
        double c = dot(u, w) / (norm(u) * norm(w));
        angle[t[k]] += std::acos(std::max(-1., std::min(1., c))) * 180 / M_PI;
      }
    vstar.assign(nv, 6);
    val.assign(nv, 0);
    std::vector<int> nb;
    for(int v = 0; v < nv; v++) {
      if(openFan[v])
        vstar[v] = std::max(1, (int)std::nearbyint(angle[v] / 60.)) + 1;
      neighbors(v, nb);
      val[v] = (int)nb.size();
    }
    markV.assign(nv, 0);
    markT.assign(tri.size(), 0);
  }

  // -- connectivity ---------------------------------------------------------
  bool adjacent(int a, int b) const
  {
    for(int t : vt[a])
      for(int w : tri[t])
        if(w == b) return true;
    return false;
  }
  static void vtAdd(std::vector<int> &s, int t)
  {
    if(std::find(s.begin(), s.end(), t) == s.end()) s.push_back(t);
  }
  static void vtDel(std::vector<int> &s, int t)
  {
    auto it = std::find(s.begin(), s.end(), t);
    if(it != s.end()) {
      *it = s.back();
      s.pop_back();
    }
  }
  int dev2(int v, int dv = 0) const
  {
    int d = val[v] + dv - vstar[v];
    return d * d;
  }
  int sdev(int v) const { return val[v] - vstar[v]; }
  bool isDefect(int v) const
  {
    return aliveV[v] && !frozen(v) && val[v] != vstar[v];
  }

  int opposite(int t, int a, int b) const
  {
    for(int v : tri[t])
      if(v != a && v != b) return v;
    return -1;
  }
  // t1 = (a, b, c) and t2 = (b, a, d) counterclockwise
  std::optional<Quad> edgeQuad(int a, int b) const
  {
    int ts[2], n = 0;
    for(int t : vt[a]) {
      const auto &T = tri[t];
      if(T[0] == b || T[1] == b || T[2] == b) {
        if(n == 2) return std::nullopt;
        ts[n++] = t;
      }
    }
    if(n != 2) return std::nullopt;
    int t1 = ts[0], t2 = ts[1];
    const auto &T1 = tri[t1];
    int i = T1[0] == a ? 0 : T1[1] == a ? 1 : 2;
    if(T1[(i + 1) % 3] != b) std::swap(t1, t2);
    return Quad{t1, t2, opposite(t1, a, b), opposite(t2, a, b)};
  }

  // -- energy change of an operation, without doing it ---------------------
  std::optional<int> flipGain(int a, int b) const
  {
    if(isConstrained(a, b)) return std::nullopt;
    auto q = edgeQuad(a, b);
    if(!q) return std::nullopt;
    int c = q->c, d = q->d;
    return dev2(a, -1) - dev2(a) + dev2(b, -1) - dev2(b) + dev2(c, 1) -
           dev2(c) + dev2(d, 1) - dev2(d);
  }
  std::optional<int> collapseGain(int a, int b) const
  {
    if(onBnd[a]) return std::nullopt;
    auto q = edgeQuad(a, b);
    if(!q) return std::nullopt;
    int c = q->c, d = q->d;
    int vb = val[a] + val[b] - 4;
    return (vb - vstar[b]) * (vb - vstar[b]) - dev2(a) - dev2(b) +
           dev2(c, -1) - dev2(c) + dev2(d, -1) - dev2(d);
  }

  // -- operations -------------------------------------------------------------
  // check: refuse if cd exists; convex: also refuse a non convex quad
  FlipRec flip(int a, int b, bool check = true, bool convex = true)
  {
    FlipRec r;
    if(isConstrained(a, b)) return r;
    auto q = edgeQuad(a, b);
    if(!q) return r;
    int t1 = q->t1, t2 = q->t2, c = q->c, d = q->d;
    if(check) {
      if(c == d || adjacent(c, d)) return r;
      if(convex && (orient(x[a], x[d], x[c]) <= 0 ||
                    orient(x[d], x[b], x[c]) <= 0))
        return r;
    }
    vtDel(vt[a], t2);
    vtDel(vt[b], t1);
    tri[t1] = {a, d, c};
    tri[t2] = {d, b, c};
    vtAdd(vt[c], t2);
    vtAdd(vt[d], t1);
    val[a]--;
    val[b]--;
    val[c]++;
    val[d]++;
    r.a = a;
    r.b = b;
    r.c = c;
    r.d = d;
    r.t1 = t1;
    r.t2 = t2;
    return r;
  }
  void unflip(const FlipRec &r)
  {
    tri[r.t1] = {r.a, r.b, r.c};
    tri[r.t2] = {r.b, r.a, r.d};
    vtAdd(vt[r.a], r.t2);
    vtAdd(vt[r.b], r.t1);
    vtDel(vt[r.c], r.t2);
    vtDel(vt[r.d], r.t1);
    val[r.a]++;
    val[r.b]++;
    val[r.c]--;
    val[r.d]--;
  }

  // remove node a by merging it into b (b moves to the midpoint unless it is
  // on the boundary)
  CollapseRec collapse(int a, int b)
  {
    CollapseRec u;
    if(onBnd[a]) return u;
    auto q = edgeQuad(a, b);
    if(!q) return u;
    int t1 = q->t1, t2 = q->t2, c = q->c, d = q->d;
    // link condition: the common neighbors of a and b are c and d only
    auto na = neighbors(a);
    int common = 0;
    for(int w : na)
      if(w != b && adjacent(w, b)) {
        if(w != c && w != d) return u;
        common++;
      }
    if(common != 2) return u;
    u.a = a;
    u.b = b;
    u.c = c;
    u.d = d;
    u.xb = x[b];
    for(int t : vt[a]) u.tris.push_back({t, tri[t]});
    int nodes[4] = {a, b, c, d};
    for(int k = 0; k < 4; k++) {
      u.vt[k] = vt[nodes[k]];
      u.val[k] = val[nodes[k]];
    }
    if(!onBnd[b]) move(b, 0.5 * (x[a] + x[b]));
    std::vector<int> ta = vt[a];
    for(int t : ta) {
      if(t == t1 || t == t2) {
        aliveT[t] = 0;
        for(int v : tri[t]) vtDel(vt[v], t);
      }
      else {
        for(int &v : tri[t])
          if(v == a) v = b;
        vtAdd(vt[b], t);
      }
    }
    vt[a].clear();
    aliveV[a] = 0;
    val[b] = u.val[0] + u.val[1] - 4;
    val[c]--;
    val[d]--;
    for(int t : vt[b])
      if(orient(x[tri[t][0]], x[tri[t][1]], x[tri[t][2]]) <= 0) {
        uncollapse(u);
        return CollapseRec();
      }
    return u;
  }
  void uncollapse(const CollapseRec &u)
  {
    x[u.b] = u.xb;
    for(auto &p : u.tris) {
      tri[p.first] = p.second;
      aliveT[p.first] = 1;
    }
    int nodes[4] = {u.a, u.b, u.c, u.d};
    for(int k = 0; k < 4; k++) {
      vt[nodes[k]] = u.vt[k];
      val[nodes[k]] = u.val[k];
    }
    aliveV[u.a] = 1;
  }

  int addNode(V2 pos, int own)
  {
    int n = nv++;
    if((int)nodeOwner.size() <= n) nodeOwner.resize(n + 1, -1);
    nodeOwner[n] = own;
    if(n == (int)x.size()) {
      x.push_back(pos);
      aliveV.push_back(1);
      onBnd.push_back(0);
      vstar.push_back(6);
      val.push_back(0);
      vt.push_back({});
      markV.push_back(0);
      h0.push_back(0.);
    }
    else {
      x[n] = pos;
      aliveV[n] = 1;
      onBnd[n] = 0;
      vstar[n] = 6;
      val[n] = 0;
      vt[n].clear();
    }
    return n;
  }
  int addTriangle(std::array<int, 3> T, int own)
  {
    tri.push_back(T);
    owner.push_back(own);
    aliveT.push_back(1);
    markT.push_back(0);
    return (int)tri.size() - 1;
  }

  // insert a node n in the middle of the interior edge ab: (a, b, c) and
  // (b, a, d) become (a, n, c), (n, b, c), (b, n, d) and (n, a, d)
  SplitRec split(int a, int b)
  {
    SplitRec u;
    if(isConstrained(a, b)) return u;
    auto q = edgeQuad(a, b);
    if(!q) return u;
    int t1 = q->t1, t2 = q->t2, c = q->c, d = q->d;
    int n = addNode(0.5 * (x[a] + x[b]), owner[t1]);
    h0[n] = 0.5 * (h0[a] + h0[b]);
    tri[t1] = {a, n, c};
    tri[t2] = {b, n, d};
    int t3 = addTriangle({n, b, c}, owner[t1]);
    int t4 = addTriangle({n, a, d}, owner[t2]);
    vtDel(vt[a], t2);
    vtAdd(vt[a], t4);
    vtDel(vt[b], t1);
    vtAdd(vt[b], t3);
    vtAdd(vt[c], t3);
    vtAdd(vt[d], t4);
    vt[n] = {t1, t2, t3, t4};
    val[n] = 4;
    val[c]++;
    val[d]++;
    u.n = n;
    u.a = a;
    u.b = b;
    u.c = c;
    u.d = d;
    u.t1 = t1;
    u.t2 = t2;
    u.t3 = t3;
    u.t4 = t4;
    return u;
  }
  void unsplit(const SplitRec &u)
  {
    if(u.n != nv - 1) {
      std::fprintf(stderr, "splits must be undone last first\n");
      std::abort();
    }
    tri[u.t1] = {u.a, u.b, u.c};
    tri[u.t2] = {u.b, u.a, u.d};
    aliveT[u.t3] = aliveT[u.t4] = 0;
    vtDel(vt[u.a], u.t4);
    vtAdd(vt[u.a], u.t2);
    vtDel(vt[u.b], u.t3);
    vtAdd(vt[u.b], u.t1);
    vtDel(vt[u.c], u.t3);
    vtDel(vt[u.d], u.t4);
    val[u.c]--;
    val[u.d]--;
    vt[u.n].clear();
    aliveV[u.n] = 0;
    nv--;
  }

  std::vector<int> ring(const std::vector<int> &nodes, int k)
  {
    int s = ringStamp = ++stamp;
    std::vector<int> out, front;
    for(int v : nodes)
      if(markV[v] != s) {
        markV[v] = s;
        out.push_back(v);
        front.push_back(v);
      }
    for(int i = 0; i < k; i++) {
      std::vector<int> nxt;
      for(int v : front)
        for(int t : vt[v])
          for(int w : tri[t])
            if(markV[w] != s) {
              markV[w] = s;
              out.push_back(w);
              nxt.push_back(w);
            }
      front.swap(nxt);
    }
    return out;
  }
  // the worst of the triangles that have no node of the last ring()
  double minGammaAway(const std::vector<int> &tris) const
  {
    double g = 1.;
    for(int t : tris) {
      if(!aliveT[t]) continue;
      bool away = true;
      for(int v : tri[t])
        if(markV[v] == ringStamp) away = false;
      if(away) g = std::min(g, triGamma(t));
    }
    return g;
  }
  std::vector<int> regionTris(const std::vector<int> &nodes)
  {
    int s = ++stamp;
    std::vector<int> out;
    for(int v : nodes)
      for(int t : vt[v])
        if(markT[t] != s) {
          markT[t] = s;
          out.push_back(t);
        }
    return out;
  }

};

// ---------------------------------------------------------------------------

struct Cand {
  int g, kind, a, b;  // kind 0: flip ab, 1: collapse a into b, 2: insert
  bool operator<(const Cand &o) const
  {
    return std::tie(g, kind, a, b) < std::tie(o.g, o.kind, o.a, o.b);
  }
  bool operator>(const Cand &o) const { return o < *this; }
  bool operator==(const Cand &o) const
  {
    return g == o.g && kind == o.kind && a == o.a && b == o.b;
  }
};

struct Insertion {
  int gain;
  std::vector<std::pair<int, int>> flips;
};

struct Repair {
  TopoMesh &m;
  int rings = 2;
  double gammaMin = 0.9;
  double radius = 0;  // dipole partners searched within radius * h
  int partners = 4, maxSteps = 15;
  struct Stats {
    int flip = 0, collapse = 0, insertion = 0, dipole = 0, compaction = 0,
        quality = 0, rejected = 0;
  } stats;
  std::vector<double> star;  // worst gamma of each star, before the change
  // after the first pass, only what changed since the previous one is
  // examined again: the pass in which each node last changed (in the zone of
  // an accepted change), and where each accepted change was, with its pass
  int pass = 0;
  std::vector<int> changedIn;
  std::vector<std::pair<V2, int>> changes;
  bool dirty(int v) const
  {
    return pass == 0 || (v < (int)changedIn.size() && changedIn[v] >= pass - 1);
  }

  explicit Repair(TopoMesh &mesh) : m(mesh)
  {
    star.assign(m.x.size(), INF);
    for(size_t t = 0; t < m.tri.size(); t++) {
      double g = m.triGamma((int)t);
      for(int v : m.tri[t]) star[v] = std::min(star[v], g);
    }
  }

  void refreshStars()
  {
    star.assign(m.x.size(), INF);
    for(size_t t = 0; t < m.tri.size(); t++) {
      if(!m.aliveT[t]) continue;
      double g = m.triGamma((int)t);
      for(int v : m.tri[t]) star[v] = std::min(star[v], g);
    }
  }

  void accepted(const std::vector<int> &touched)
  {
    if(star.size() < m.x.size()) star.resize(m.x.size(), INF);
    if(changedIn.size() < m.x.size()) changedIn.resize(m.x.size(), -1);
    changes.push_back({m.x[touched[0]], pass});
    for(int v : m.ring(touched, rings + 1)) {
      if(m.aliveV[v]) star[v] = m.starGamma(v);
      changedIn[v] = pass;
    }
  }
  double star0(int v) const { return v < (int)star.size() ? star[v] : 1.; }

  std::vector<int> defects() const
  {
    std::vector<int> out;
    for(int v = 0; v < m.nv; v++)
      if(m.isDefect(v)) out.push_back(v);
    return out;
  }

  // smooth around the touched nodes; true if no triangle of the zone is
  // worse than min(gammaMin, g0)
  bool checked(const std::vector<int> &touched, double g0)
  {
    auto zone = m.ring(touched, rings);
    m.smoothNodes(zone);
    return m.minGamma(m.regionTris(zone)) >= std::min(gammaMin, g0);
  }
  struct Snapshot {
    std::vector<std::pair<int, V2>> pos;
    std::vector<double> tp;
    double g0;
  };
  Snapshot snapshot(const std::vector<int> &nodes)
  {
    Snapshot s;
    auto zone = m.ring(nodes, rings + 1);
    for(int v : zone) {
      s.pos.push_back({v, m.x[v]});
      s.tp.push_back(m.tparOf(v));
    }
    s.g0 = m.minGamma(m.regionTris(zone));
    return s;
  }
  void restore(const Snapshot &s)
  {
    for(size_t i = 0; i < s.pos.size(); i++) {
      m.x[s.pos[i].first] = s.pos[i].second;
      if(s.pos[i].first < (int)m.tpar.size()) m.tpar[s.pos[i].first] = s.tp[i];
    }
  }

  // best insertion on edge ab, evaluated by doing it and undoing it
  std::optional<Insertion> insertion(int a, int b)
  {
    if(!(m.val[a] > m.vstar[a] && m.val[b] > m.vstar[b])) return std::nullopt;
    auto q = m.edgeQuad(a, b);
    if(!q) return std::nullopt;
    int c = q->c, d = q->d;
    auto around = m.ring({a, b}, 2);
    int e0 = 0;
    for(int v : around) e0 += m.dev2(v);
    SplitRec u = m.split(a, b);
    if(!u.ok()) return std::nullopt;
    std::pair<int, int> E[4] = {{a, c}, {c, b}, {b, d}, {d, a}};
    std::vector<std::vector<std::pair<int, int>>> choices = {{}};
    for(int i = 0; i < 4; i++) choices.push_back({E[i]});
    for(int i = 0; i < 4; i++)
      for(int j = i + 1; j < 4; j++) choices.push_back({E[i], E[j]});
    std::optional<Insertion> best;
    for(auto &fl : choices) {
      std::vector<FlipRec> done;
      for(auto &e : fl) {
        FlipRec r = m.flip(e.first, e.second, true, false);
        if(!r.ok()) break;
        done.push_back(r);
      }
      if(done.size() == fl.size()) {
        int g = m.dev2(u.n);
        for(int v : around) g += m.dev2(v);
        g -= e0;
        if(!best || g < best->gain) best = Insertion{g, fl};
      }
      for(auto it = done.rbegin(); it != done.rend(); ++it) m.unflip(*it);
    }
    m.unsplit(u);
    return best;
  }

  std::vector<Cand> candidates(int v)
  {
    std::vector<Cand> out;
    if(!m.aliveV[v]) return out;
    for(int w : m.neighbors(v)) {
      auto g = m.flipGain(v, w);
      if(g && *g < 0) out.push_back({*g, 0, v, w});
      int ab[2][2] = {{v, w}, {w, v}};
      for(auto &p : ab) {
        auto gc = m.collapseGain(p[0], p[1]);
        if(gc && *gc < 0) out.push_back({*gc, 1, p[0], p[1]});
      }
      if(v < w) {
        auto r = insertion(v, w);
        if(r && r->gain < 0) out.push_back({r->gain, 2, v, w});
      }
    }
    return out;
  }

  // an applied operation, with its undo
  struct Applied {
    int kind = -1;
    FlipRec flip;
    CollapseRec col;
    SplitRec split;
    std::vector<FlipRec> splitFlips;
    std::vector<int> touched;
    bool ok() const { return kind >= 0; }
  };
  Applied doOp(int kind, int a, int b, const Insertion *ins = nullptr)
  {
    Applied r;
    if(kind == 0) {
      r.flip = m.flip(a, b);
      if(!r.flip.ok()) return r;
      r.touched = {a, b, r.flip.c, r.flip.d};
    }
    else if(kind == 1) {
      r.col = m.collapse(a, b);
      if(!r.col.ok()) return r;
      r.touched = m.neighbors(b);
      r.touched.push_back(b);
    }
    else {
      std::optional<Insertion> own;
      if(!ins) {
        own = insertion(a, b);
        if(!own) return r;
        ins = &*own;
      }
      r.split = m.split(a, b);
      if(!r.split.ok()) return r;
      for(auto &e : ins->flips) {
        FlipRec f = m.flip(e.first, e.second, true, false);
        if(!f.ok()) {
          for(auto it = r.splitFlips.rbegin(); it != r.splitFlips.rend(); ++it)
            m.unflip(*it);
          m.unsplit(r.split);
          return Applied();
        }
        r.splitFlips.push_back(f);
      }
      r.touched = {r.split.n, a, b, r.split.c, r.split.d};
      for(auto &f : r.splitFlips) {
        r.touched.push_back(f.c);
        r.touched.push_back(f.d);
      }
    }
    r.kind = kind;
    return r;
  }
  void undoOp(const Applied &r)
  {
    if(r.kind == 0)
      m.unflip(r.flip);
    else if(r.kind == 1)
      m.uncollapse(r.col);
    else if(r.kind == 2) {
      for(auto it = r.splitFlips.rbegin(); it != r.splitFlips.rend(); ++it)
        m.unflip(*it);
      m.unsplit(r.split);
    }
  }

  // apply, check, keep or undo: the touched nodes, or nothing
  std::optional<std::vector<int>> applyOp(int kind, int a, int b,
                                          const Insertion *ins = nullptr)
  {
    Snapshot s = snapshot({a, b});
    Applied r = doOp(kind, a, b, ins);
    if(!r.ok()) return std::nullopt;
    if(checked(r.touched, s.g0)) {
      (kind == 0 ? stats.flip : kind == 1 ? stats.collapse : stats.insertion)++;
      accepted(r.touched);
      return r.touched;
    }
    undoOp(r);
    restore(s);
    stats.rejected++;
    return std::nullopt;
  }

  // flips, collapses (and insertions) that lower the energy, best first
  int greedy()
  {
    std::priority_queue<Cand, std::vector<Cand>, std::greater<Cand>> heap;
    for(int v : defects())
      if(dirty(v))
        for(auto &c : candidates(v)) heap.push(c);
    int changed = 0;
    while(!heap.empty()) {
      Cand c = heap.top();
      heap.pop();
      if(!(m.aliveV[c.a] && m.aliveV[c.b]) || !m.adjacent(c.a, c.b)) continue;
      std::optional<int> g1;
      std::optional<Insertion> ins;
      if(c.kind == 0)
        g1 = m.flipGain(c.a, c.b);
      else if(c.kind == 1)
        g1 = m.collapseGain(c.a, c.b);
      else {
        ins = insertion(c.a, c.b);
        if(ins) g1 = ins->gain;
      }
      if(!g1 || *g1 >= 0) continue;
      if(*g1 > c.g) {  // outdated: queue it again with its current gain
        heap.push({*g1, c.kind, c.a, c.b});
        continue;
      }
      auto touched = applyOp(c.kind, c.a, c.b, ins ? &*ins : nullptr);
      if(!touched) continue;
      changed++;
      for(int v : m.ring(*touched, 1))
        if(m.isDefect(v))
          for(auto &cc : candidates(v)) heap.push(cc);
    }
    return changed;
  }

  // -- dipoles ----------------------------------------------------------------
  // pairs (p, q) of neighbors, p interior with a valence deficit, q with an
  // excess (5-7, and also 4-7, 5-8...: a 4 is the 5 end of two dipoles, an
  // 8 the 7 end of two), each node in one pair at most, largest deviations
  // first
  std::vector<std::pair<int, int>> dipoles()
  {
    std::vector<std::tuple<int, int, int>> pairs;
    for(int p : defects()) {
      if(m.onBnd[p] || m.sdev(p) >= 0) continue;
      for(int q : m.neighbors(p))
        if(m.sdev(q) > 0) pairs.push_back({m.sdev(p) - m.sdev(q), p, q});
    }
    std::sort(pairs.begin(), pairs.end());
    std::vector<char> used(m.x.size(), 0);
    std::vector<std::pair<int, int>> out;
    for(auto &t : pairs) {
      int p = std::get<1>(t), q = std::get<2>(t);
      if(!used[p] && !used[q]) {
        used[p] = used[q] = 1;
        out.push_back({p, q});
      }
    }
    return out;
  }
  bool isDipole(int p, int q) const
  {
    return m.aliveV[p] && m.aliveV[q] && m.sdev(p) < 0 && m.sdev(q) > 0 &&
           m.adjacent(p, q);
  }
  bool lone(int v) const
  {
    int d = m.sdev(v);
    if(d == 0 || !m.aliveV[v]) return false;
    for(int t : m.vt[v])
      for(int w : m.tri[t])
        if(m.sdev(w) * d < 0) return false;
    return true;
  }

  // the two flips that make the dipole (deficit at p, excess at q) glide:
  // flip qr, r one of the two nodes opposite to pq; the dipole moves to
  // (r, t), t opposite to qr on the other side of p
  std::vector<std::pair<int, int>> glideMoves(int p, int q) const
  {
    std::vector<std::pair<int, int>> out;
    auto quad = m.edgeQuad(p, q);
    if(!quad) return out;
    for(int r : {quad->c, quad->d}) {
      if(m.onBnd[r]) continue;
      auto qr = m.edgeQuad(q, r);
      if(!qr || (qr->c != p && qr->d != p)) continue;
      out.push_back({r, qr->c == p ? qr->d : qr->c});
    }
    return out;
  }

  // p and q, lone defects of opposite signs two edges apart, are a local
  // minimum of E: every single flip raises it. Search two flips, the first
  // raising E by 2 at most and the total not raising it, after which there
  // are fewer lone defects around (p and q have become an adjacent dipole)
  std::optional<std::vector<std::pair<int, int>>> compactSearch(int p, int q)
  {
    auto np = m.neighbors(p);
    std::vector<int> core = {p, q};
    for(int w : np)
      if(m.adjacent(w, q)) core.push_back(w);
    auto around = m.ring(core, 2);
    int lone0 = 0;
    for(int v : around) lone0 += lone(v);
    std::vector<int> nb;
    auto edgesOf = [&](const std::vector<int> &nodes) {
      std::vector<std::pair<int, int>> e;
      for(int a : nodes) {
        m.neighbors(a, nb);
        for(int b : nb) e.push_back({std::min(a, b), std::max(a, b)});
      }
      std::sort(e.begin(), e.end());
      e.erase(std::unique(e.begin(), e.end()), e.end());
      return e;
    };
    std::optional<std::pair<std::pair<int, int>,
                            std::vector<std::pair<int, int>>>> best;
    for(auto e1 : edgesOf(core)) {
      auto g1 = m.flipGain(e1.first, e1.second);
      if(!g1 || *g1 > 2) continue;
      FlipRec f1 = m.flip(e1.first, e1.second, true, false);
      if(!f1.ok()) continue;
      auto n2 = core;
      for(int v : {e1.first, e1.second, f1.c, f1.d}) n2.push_back(v);
      for(auto e2 : edgesOf(n2)) {
        if((e2.first == f1.c && e2.second == f1.d) ||
           (e2.first == f1.d && e2.second == f1.c))
          continue;
        auto g2 = m.flipGain(e2.first, e2.second);
        if(!g2 || *g1 + *g2 > 0) continue;
        FlipRec f2 = m.flip(e2.first, e2.second, true, false);
        if(!f2.ok()) continue;
        int lone1 = 0;
        for(int v : around) lone1 += lone(v);
        if(lone1 < lone0) {
          std::pair<int, int> key = {*g1 + *g2, lone1};
          if(!best || key < best->first) best = {{key}, {e1, e2}};
        }
        m.unflip(f2);
      }
      m.unflip(f1);
    }
    if(!best) return std::nullopt;
    return best->second;
  }

  int compactPass()
  {
    int changed = 0;
    for(int p : defects()) {
      if(m.onBnd[p] || !lone(p)) continue;
      auto r1 = m.neighbors(p);
      std::vector<int> r2;
      for(int w : r1)
        for(int z : m.neighbors(w))
          if(z != p && std::find(r1.begin(), r1.end(), z) == r1.end() &&
             std::find(r2.begin(), r2.end(), z) == r2.end())
            r2.push_back(z);
      for(int q : r2) {
        if(m.onBnd[q] || m.sdev(q) * m.sdev(p) >= 0 || !lone(q)) continue;
        if(!dirty(p) && !dirty(q)) continue;
        auto seq = compactSearch(p, q);
        if(!seq) continue;
        std::vector<int> nodes;
        for(auto &e : *seq) {
          nodes.push_back(e.first);
          nodes.push_back(e.second);
        }
        Snapshot s = snapshot(nodes);
        std::vector<FlipRec> done;
        std::vector<int> touched;
        for(auto &e : *seq) {
          FlipRec f = m.flip(e.first, e.second, true, false);
          if(!f.ok()) break;
          done.push_back(f);
          for(int v : {e.first, e.second, f.c, f.d}) touched.push_back(v);
        }
        if(done.size() == seq->size() && checked(touched, s.g0)) {
          accepted(touched);
          stats.compaction++;
          changed++;
          break;
        }
        for(auto it = done.rbegin(); it != done.rend(); ++it) m.unflip(*it);
        restore(s);
      }
    }
    return changed;
  }

  // glide dipole dip toward partner, one flip at a time, as long as it gets
  // closer and the energy does not rise; succeed if the energy drops on the
  // way (annihilation or merge) or with one last single operation around
  // the two dipoles
  bool glideTo(std::pair<int, int> dip, std::pair<int, int> partner)
  {
    int p = dip.first, q = dip.second;
    V2 target = 0.5 * (m.x[partner.first] + m.x[partner.second]);
    double dist = norm(0.5 * (m.x[p] + m.x[q]) - target);
    m.openJournal();
    std::vector<FlipRec> flips;
    int gain = 0;
    std::vector<int> touched;
    Applied last;
    for(int step = 0; step < maxSteps; step++) {
      double bd = INF;
      int br = -1, bt = -1;
      for(auto &rt : glideMoves(p, q)) {
        double d = norm(0.5 * (m.x[rt.first] + m.x[rt.second]) - target);
        if(d < bd) {
          bd = d;
          br = rt.first;
          bt = rt.second;
        }
      }
      if(br < 0 || bd >= dist - 1e-6 * m.h) break;
      dist = bd;
      auto g = m.flipGain(q, br);
      if(!g || *g > 0) break;  // never raise the energy: finish from here
      FlipRec f = m.flip(q, br);
      if(!f.ok()) break;
      flips.push_back(f);
      gain += *g;
      for(int v : {q, br, f.c, f.d}) touched.push_back(v);
      if(gain < 0 || !isDipole(br, bt)) break;
      p = br;
      q = bt;
    }
    if(gain >= 0 && !flips.empty()) {
      std::vector<Cand> cands;
      for(int v : m.ring({p, q, partner.first, partner.second}, 1))
        if(m.isDefect(v)) {
          auto c = candidates(v);
          cands.insert(cands.end(), c.begin(), c.end());
        }
      std::sort(cands.begin(), cands.end());
      cands.erase(std::unique(cands.begin(), cands.end()), cands.end());
      for(auto &c : cands) {
        if(gain + c.g >= 0) break;
        int g = c.g;
        std::optional<Insertion> ins;
        if(c.kind == 2) {  // re-evaluate: the mesh moved since
          ins = insertion(c.a, c.b);
          if(!ins || gain + ins->gain >= 0) continue;
          g = ins->gain;
        }
        Applied r = doOp(c.kind, c.a, c.b, ins ? &*ins : nullptr);
        if(!r.ok()) continue;
        last = r;
        touched.insert(touched.end(), r.touched.begin(), r.touched.end());
        gain += g;
        break;
      }
    }
    bool ok = false;
    if(gain < 0) {
      double g0 = INF;
      for(int v : m.ring(touched, rings))
        if(m.aliveV[v]) g0 = std::min(g0, star0(v));
      ok = checked(touched, g0);
    }
    if(!ok) {
      if(last.ok()) undoOp(last);
      for(auto it = flips.rbegin(); it != flips.rend(); ++it) m.unflip(*it);
    }
    m.closeJournal(!ok);
    if(ok) accepted(touched);
    return ok;
  }

  int dipolePass()
  {
    int changed = compactPass();
    auto dips = dipoles();
    if(dips.size() < 2) return changed;
    // uniform grid on the dipole midpoints
    double cell = radius * m.h;
    std::vector<V2> mid, vec;
    for(auto &pq : dips) {
      mid.push_back(0.5 * (m.x[pq.first] + m.x[pq.second]));
      vec.push_back(m.x[pq.second] - m.x[pq.first]);
    }
    std::unordered_map<int64_t, std::vector<int>> grid;
    auto key = [&](int64_t i, int64_t j) { return i * 1000003LL + j; };
    for(size_t i = 0; i < mid.size(); i++)
      grid[key((int64_t)std::floor(mid[i].x / cell),
               (int64_t)std::floor(mid[i].y / cell))]
        .push_back((int)i);
    // the dipoles with a change within the search radius since the previous
    // pass: a glide can succeed once its path has changed
    std::vector<char> nearChange(dips.size(), pass == 0);
    if(pass > 0) {
      std::unordered_map<int64_t, std::vector<V2>> recent;
      for(auto &c : changes)
        if(c.second >= pass - 1)
          recent[key((int64_t)std::floor(c.first.x / cell),
                     (int64_t)std::floor(c.first.y / cell))]
            .push_back(c.first);
      for(size_t i = 0; i < mid.size() && !recent.empty(); i++) {
        int64_t ci = (int64_t)std::floor(mid[i].x / cell),
                cj = (int64_t)std::floor(mid[i].y / cell);
        for(int64_t di = -1; di <= 1 && !nearChange[i]; di++)
          for(int64_t dj = -1; dj <= 1 && !nearChange[i]; dj++) {
            auto it = recent.find(key(ci + di, cj + dj));
            if(it == recent.end()) continue;
            for(V2 c : it->second)
              if(norm(c - mid[i]) <= cell) {
                nearChange[i] = 1;
                break;
              }
          }
      }
    }
    for(size_t i = 0; i < dips.size(); i++) {
      int p = dips[i].first, q = dips[i].second;
      if(!isDipole(p, q)) continue;
      int64_t ci = (int64_t)std::floor(mid[i].x / cell),
              cj = (int64_t)std::floor(mid[i].y / cell);
      std::vector<std::tuple<bool, double, int>> near;
      for(int64_t di = -1; di <= 1; di++)
        for(int64_t dj = -1; dj <= 1; dj++) {
          auto it = grid.find(key(ci + di, cj + dj));
          if(it == grid.end()) continue;
          for(int j : it->second) {
            if(j == (int)i) continue;
            double d = norm(mid[j] - mid[i]);
            if(d > cell) continue;
            // opposite orientation first (they can annihilate)
            near.push_back({dot(vec[i], vec[j]) > 0, d, j});
          }
        }
      std::sort(near.begin(), near.end());
      int tried = 0;
      for(auto &nj : near) {
        if(tried++ >= partners) break;
        auto pj = dips[std::get<2>(nj)];
        if(!isDipole(pj.first, pj.second)) continue;
        if(!nearChange[i] && !nearChange[std::get<2>(nj)]) continue;
        if(glideTo({p, q}, pj)) {
          stats.dipole++;
          changed++;
          break;
        }
        stats.rejected++;
      }
    }
    return changed;
  }

  // -- quality pass -----------------------------------------------------------
  // For the worst triangles (gamma < thr), worst first: evaluate a local
  // smoothing alone, the flip of each of its edges, the collapse of each edge
  // both ways and the split of each edge, each followed by the local
  // smoothing; keep the one that raises the worst gamma of the zone the most,
  // provided the energy E does not rise by more than dEmax.
  struct QCand {
    int kind, a, b;  // -1: smoothing only; 0 flip; 1 collapse a into b;
                     // 3: plain split of ab
  };
  bool doQ(const QCand &c, Applied &r, SplitRec &sp, std::vector<int> &touched,
           const std::vector<int> &tnodes)
  {
    touched.clear();
    if(c.kind == -1) {
      touched = tnodes;
      return true;
    }
    if(c.kind == 3) {
      sp = m.split(c.a, c.b);
      if(!sp.ok()) return false;
      touched = {sp.n, c.a, c.b, sp.c, sp.d};
      return true;
    }
    if(c.kind == 0) {
      r.flip = m.flip(c.a, c.b, true, false);
      if(!r.flip.ok()) return false;
      r.kind = 0;
      touched = {c.a, c.b, r.flip.c, r.flip.d};
      return true;
    }
    r.col = m.collapse(c.a, c.b);
    if(!r.col.ok()) return false;
    r.kind = 1;
    touched = m.neighbors(c.b);
    touched.push_back(c.b);
    return true;
  }
  double hard = 0.8;
  int qualityPass(double thr, int dEmax)
  {
    using Item = std::pair<double, int>;
    std::priority_queue<Item, std::vector<Item>, std::greater<Item>> heap;
    for(size_t t = 0; t < m.tri.size(); t++)
      if(m.aliveT[t] && m.owner[t] >= 0) {
        double g = m.triGamma((int)t);
        if(g < thr) heap.push({g, (int)t});
      }
    int changed = 0;
    while(!heap.empty()) {
      auto [g, t] = heap.top();
      heap.pop();
      if(!m.aliveT[t] || m.triGamma(t) != g) continue;
      std::vector<int> tn(m.tri[t].begin(), m.tri[t].end());
      auto zone = m.ring(tn, rings + 2);
      double gBefore = m.minGamma(m.regionTris(zone));
      int eBefore = 0;
      for(int v : zone) eBefore += m.dev2(v);
      std::vector<QCand> cands = {{-1, 0, 0}};
      // the edges of the triangle; for the very worst ones (gamma < hard),
      // every edge of the stars of its nodes, with a larger energy budget
      bool wide = g < hard;
      std::vector<std::pair<int, int>> edges;
      for(int k = 0; k < 3; k++) edges.push_back({tn[k], tn[(k + 1) % 3]});
      if(wide)
        for(int v : tn)
          for(int w : m.neighbors(v)) edges.push_back({v, w});
      for(auto &e : edges) {
        auto k = std::make_pair(std::min(e.first, e.second),
                                std::max(e.first, e.second));
        bool seen = false;
        for(auto &c : cands)
          if(c.kind == 0 && std::make_pair(std::min(c.a, c.b),
                                           std::max(c.a, c.b)) == k)
            seen = true;
        if(seen) continue;
        cands.push_back({0, e.first, e.second});
        cands.push_back({1, e.first, e.second});
        cands.push_back({1, e.second, e.first});
        cands.push_back({3, e.first, e.second});
      }
      const int budget = wide ? dEmax + 2 : dEmax;
      double bestG = gBefore + 1e-4;
      int bestDE = 0, best = -1;
      for(size_t i = 0; i < cands.size(); i++) {
        m.openJournal();
        Applied r;
        SplitRec sp;
        std::vector<int> touched;
        bool ok = doQ(cands[i], r, sp, touched, tn);
        if(ok) {
          auto z2 = zone;
          if(sp.ok()) z2.push_back(sp.n);
          std::vector<int> alive;
          for(int v : z2)
            if(m.aliveV[v]) alive.push_back(v);
          int eA = 0;
          for(int v : alive) eA += m.dev2(v);
          const int dE = eA - eBefore;
          // the change is only smoothed if it can win: the valences do not
          // depend on the positions, and the triangles of the zone that the
          // smoothing does not move keep their quality
          if(dE <= budget) {
            const auto moving = m.ring(touched, rings);
            const auto tris = m.regionTris(alive);
            if(m.minGammaAway(tris) >= bestG - 1e-9) {
              m.smoothNodes(moving);
              const double gA = m.minGamma(tris);
              if(gA > bestG + 1e-9 ||
                 (best >= 0 && std::fabs(gA - bestG) < 1e-9 &&
                  dE < bestDE)) {
                bestG = gA;
                bestDE = dE;
                best = (int)i;
              }
            }
          }
          if(sp.ok()) m.unsplit(sp);
          else if(r.kind == 0) m.unflip(r.flip);
          else if(r.kind == 1) m.uncollapse(r.col);
        }
        m.closeJournal(true);
      }
      if(best < 0) continue;
      // apply the best one for real
      Applied r;
      SplitRec sp;
      std::vector<int> touched;
      if(!doQ(cands[best], r, sp, touched, tn)) continue;
      m.smoothNodes(m.ring(touched, rings));
      accepted(touched);
      stats.quality++;
      changed++;
      for(int tt : m.regionTris(m.ring(touched, rings + 1))) {
        double gg = m.triGamma(tt);
        if(m.aliveT[tt] && m.owner[tt] >= 0 && gg < thr) heap.push({gg, tt});
      }
    }
    return changed;
  }

  void run(int passes)
  {
    int ePrev = energy();
    for(pass = 0; pass < passes; pass++) {
      int n1 = greedy();
      int n3 = radius > 0 ? dipolePass() : 0;
      const int e = energy();
      Msg::Debug("Valence optimization pass %d: %d single changes, %d "
                 "dislocation moves, energy %d",
                 pass, n1, n3, e);
      // stop when the dislocations no longer move, or when the moves no
      // longer lower the energy (compactions alone just reshuffle lone
      // defects)
      if(n3 == 0 || e >= ePrev) break;
      ePrev = e;
    }
  }
  int energy() const
  {
    int e = 0;
    for(int v = 0; v < m.nv; v++)
      if(m.aliveV[v] && !m.frozen(v)) e += m.dev2(v);
    return e;
  }

};

} // namespace

namespace {

// repair the surfaces together, the triangles of the surfaces for which frozen
// is true loaded frozen; false if they are not in a plane
bool repairValence2D(const std::vector<GFace *> &faces, int type,
                     const std::function<bool(GFace *)> &frozen)
{
  const double t0 = TimeOfDay();
  planar::Face face(faces, frozen);
  if(face.empty()) return false;
  TopoMesh m(face.x, face.tri, face.onCurve, face.constrainedEdges);
  face.init(m);
  const int nSlide = CTX::instance()->mesh.boundaryNodeSliding2D ?
                       face.setupSliding(m) :
                       0;

  Repair r(m);
  const std::size_t def0 = r.defects().size();
  std::vector<int> all;
  for(std::size_t t = 0; t < m.tri.size(); t++)
    if(m.owner[t] >= 0) all.push_back((int)t);
  const double g0 = m.minGamma(all);

  r.gammaMin = 0.9;
  // type 2: dipole partners searched within 20 h (10 h leaves 11 % more
  // defects, 30 h does no better)
  r.radius = type >= 2 ? 20. : 0.;
  r.run(10);
  const int nSmooth = 10;
  smoothODT(m, nSmooth);
  r.refreshStars();
  const double thr = CTX::instance()->mesh.valenceRepairThreshold2D;
  if(thr > 0.) {
    r.hard = thr;
    for(int q = 0; q < 5; q++)
      if(!r.qualityPass(thr, 2)) break;
    smoothODT(m, nSmooth);
  }
  std::string tags;
  for(GFace *gf : faces)
    tags += (tags.empty() ? "" : ", ") + std::to_string(gf->tag());
  Msg::Debug("Valence repair of surface(s) %s: %d flips, %d collapses, %d "
             "insertions, %d dipole glides, %d compactions, %d changes below "
             "the threshold, %d refused",
             tags.c_str(), r.stats.flip, r.stats.collapse, r.stats.insertion,
             r.stats.dipole, r.stats.compaction, r.stats.quality,
             r.stats.rejected);
  face.write(m, true);

  std::vector<int> alive;
  for(std::size_t t = 0; t < m.tri.size(); t++)
    if(m.aliveT[t] && m.owner[t] >= 0) alive.push_back((int)t);
  Msg::Info("Valence repair of surface%s %s: %zu -> %zu valence defects, "
            "worst gamma %.3f -> %.3f, %d sliding boundary nodes, %zu frozen "
            "neighbor triangles (%g s)",
            faces.size() > 1 ? "s" : "", tags.c_str(), def0,
            r.defects().size(), g0, m.minGamma(alive), nSlide,
            face.numFrozen(), TimeOfDay() - t0);
  return true;
}

} // namespace

void repairValence2D(GFace *gf)
{
  const int type = CTX::instance()->mesh.valenceRepair2D;
  if(type <= 0) return;
  repairValence2D({gf}, type, planar::frozenWhileMeshing);
}

void repairValence2D(const std::vector<GFace *> &faces)
{
  // the surfaces in a plane are repaired together, the triangles of the
  // other surfaces that touch them frozen; one by one otherwise
  const int type = CTX::instance()->mesh.valenceRepair2D > 0 ?
                     CTX::instance()->mesh.valenceRepair2D :
                     2;
  std::set<GFace *> set(faces.begin(), faces.end());
  auto others = [&set](GFace *g) { return !set.count(g); };
  std::vector<GFace *> planar;
  for(GFace *gf : faces)
    if(!gf->triangles.empty()) planar.push_back(gf);
  if(planar.empty()) return;
  if(repairValence2D(planar, type, others)) return;
  for(GFace *gf : planar) {
    if(!repairValence2D({gf}, type,
                        [gf](GFace *g) { return g != gf; }))
      Msg::Warning("Surface %d is not planar: no valence repair", gf->tag());
  }
}
