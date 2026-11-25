// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
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
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include "DiscreteCADWindingPlugin.h"
#include "DiscreteCADWinding.h"
#include "GModel.h"
#include "GFace.h"
#include "MTriangle.h"
#include "PViewOptions.h"

GMSH_WindingNumberPlugin::GMSH_WindingNumberPlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "Surface", nullptr, -1, ""},
                     {GMSH_FULLRC, "Piece", nullptr, -1, ""},
                     {GMSH_FULLRC, "Axis", nullptr, -1, ""},
                     {GMSH_FULLRC, "Position", nullptr, 0.5, ""},
                     {GMSH_FULLRC, "Resolution", nullptr, 300, ""},
                     {GMSH_FULLRC, "IsoSurface", nullptr, 1, ""},
                     {GMSH_FULLRC, "IsoResolution", nullptr, 100, ""},
                     {GMSH_FULLRC, "Beta", nullptr, 2., ""}})
{
}

std::string GMSH_WindingNumberPlugin::getHelp() const
{
  return "Plugin(WindingNumber) shows the inside and the outside of the "
         "triangles of the surfaces of the model, a soup with holes, gaps and "
         "overlaps (a STL file merged, or the mesh of surfaces, or else their "
         "triangulations), through their generalized winding number: the sum "
         "of the solid angles of the triangles seen from a point, over 4 Pi "
         "(1 inside a closed surface oriented outwards, 0 outside, 2 where "
         "two closed surfaces overlap, in between near holes and gaps; inside "
         "where it is above 1/2). It is computed fast, as Barill et al. "
         "(2018): the triangles far from a point through the moments of their "
         "boxes, `Beta' times the radius of a box away (more is more "
         "accurate).\n\n"
         "The triangles are those of the surface `Surface', or of all the "
         "surfaces if it is negative; of their connected piece `Piece' (0 "
         "for the largest, 1 for the next one... the pieces are listed in the "
         "messages), or of all of them if it is negative.\n\n"
         "Plugin(WindingNumber) creates list-based views: the winding number "
         "on the plane normal to the axis `Axis' (0, 1 or 2 for x, y or z; "
         "the three planes if it is negative) at `Position' (0 to 1) across "
         "the box of the triangles, with `Resolution' cells along the longest "
         "side of the plane; and, if `IsoSurface' is set, the surface where "
         "it is 1/2 (the closed surface the triangles bound), on a grid of "
         "`IsoResolution' cells along the longest side of the box.";
}

PView *GMSH_WindingNumberPlugin::execute(PView *v)
{
  const int surface = (int)option(0), piece = (int)option(1);
  const int axis = (int)option(2);
  const double position = std::min(1., std::max(0., option(3)));
  const int resolution = std::max(2, (int)option(4));
  const bool iso = option(5) != 0.;
  const int isoResolution = std::max(2, (int)option(6));
  const double beta = std::max(1., option(7));

  // the triangles of the surfaces: their mesh, or else their triangulations
  // (their nodes merged by coordinates)
  std::vector<std::array<double, 3> > x;
  std::vector<std::array<int, 3> > t;
  std::map<std::array<double, 3>, int> nodeOf;
  auto node = [&](double a, double b, double c) {
    const std::array<double, 3> p = {{a, b, c}};
    auto it = nodeOf.insert({p, (int)x.size()});
    if(it.second) x.push_back(p);
    return it.first->second;
  };
  for(GFace *f : GModel::current()->getFaces()) {
    if(surface >= 0 && f->tag() != surface) continue;
    if(f->triangles.size()) {
      for(MTriangle *tr : f->triangles) {
        std::array<int, 3> n;
        for(int k = 0; k < 3; k++) {
          MVertex *mv = tr->getVertex(k);
          n[k] = node(mv->x(), mv->y(), mv->z());
        }
        t.push_back(n);
      }
      continue;
    }
    if(f->stl_triangles.empty()) f->buildSTLTriangulation();
    for(std::size_t i = 0; i + 2 < f->stl_triangles.size(); i += 3) {
      std::array<int, 3> n;
      for(int k = 0; k < 3; k++) {
        const SPoint3 &p = f->stl_vertices_xyz[f->stl_triangles[i + k]];
        n[k] = node(p.x(), p.y(), p.z());
      }
      t.push_back(n);
    }
  }
  if(t.empty()) {
    Msg::Error("Plugin(WindingNumber) needs triangles: merge a STL file, or "
               "mesh the surfaces");
    return v;
  }

  // the connected pieces (through their nodes), by decreasing size, and
  // whether they are closed (each edge of two triangles)
  std::vector<int> parent(x.size());
  std::iota(parent.begin(), parent.end(), 0);
  auto find = [&](int i) {
    while(parent[i] != i) i = parent[i] = parent[parent[i]];
    return i;
  };
  for(auto &tr : t) {
    parent[find(tr[1])] = find(tr[0]);
    parent[find(tr[2])] = find(tr[0]);
  }
  std::map<int, std::vector<std::size_t> > pieceOf;
  for(std::size_t i = 0; i < t.size(); i++) pieceOf[find(t[i][0])].push_back(i);
  std::vector<std::vector<std::size_t> > pieces;
  for(auto &p : pieceOf) pieces.push_back(p.second);
  std::sort(pieces.begin(), pieces.end(),
            [](const std::vector<std::size_t> &a,
               const std::vector<std::size_t> &b) { return a.size() > b.size(); });
  std::map<std::pair<int, int>, int> edges;
  for(auto &tr : t)
    for(int k = 0; k < 3; k++) edges[std::minmax(tr[k], tr[(k + 1) % 3])]++;
  Msg::Info("Plugin(WindingNumber): %lu triangles, %lu pieces", t.size(),
            pieces.size());
  for(std::size_t p = 0; p < pieces.size() && p < 20; p++) {
    int open = 0, other = 0;
    for(std::size_t i : pieces[p])
      for(int k = 0; k < 3; k++) {
        const int n = edges[std::minmax(t[i][k], t[i][(k + 1) % 3])];
        open += n == 1;
        other += n > 2;
      }
    Msg::Info("  piece %lu: %lu triangles, %s (%d boundary edges, %d "
              "non-manifold)", p, pieces[p].size(),
              open || other ? "open" : "closed", open, other / 3);
  }
  if(pieces.size() > 20) Msg::Info("  ...");
  if(piece >= (int)pieces.size()) {
    Msg::Error("Plugin(WindingNumber): no piece %d (%lu pieces)", piece,
               pieces.size());
    return v;
  }

  // the winding number of the triangles chosen
  std::vector<std::array<int, 3> > chosen;
  if(piece < 0)
    chosen = t;
  else
    for(std::size_t i : pieces[piece]) chosen.push_back(t[i]);
  DiscreteCADWinding w(x, chosen, beta);
  double lo[3] = {1e300, 1e300, 1e300}, hi[3] = {-1e300, -1e300, -1e300};
  for(auto &tr : chosen)
    for(int n : tr)
      for(int k = 0; k < 3; k++) {
        lo[k] = std::min(lo[k], x[n][k]);
        hi[k] = std::max(hi[k], x[n][k]);
      }
  double size = 0.;
  for(int k = 0; k < 3; k++) size = std::max(size, hi[k] - lo[k]);
  for(int k = 0; k < 3; k++) {
    lo[k] -= 0.05 * size;
    hi[k] += 0.05 * size;
  }
  const std::string what =
    piece < 0 ? "all pieces" : "piece " + std::to_string(piece);
  const char *names[3] = {"x", "y", "z"};

  // the maps on the planes
  PView *last = v;
  for(int a = 0; a < 3; a++) {
    if(axis >= 0 && a != axis) continue;
    const int u = (a + 1) % 3, vv = (a + 2) % 3;
    const double ext = std::max(hi[u] - lo[u], hi[vv] - lo[vv]);
    const double h = ext / resolution;
    const int nu = std::max(1, (int)std::ceil((hi[u] - lo[u]) / h));
    const int nv = std::max(1, (int)std::ceil((hi[vv] - lo[vv]) / h));
    const double c = lo[a] + position * (hi[a] - lo[a]);
    std::vector<std::array<double, 3> > q((nu + 1) * (nv + 1));
    for(int j = 0; j <= nv; j++)
      for(int i = 0; i <= nu; i++) {
        std::array<double, 3> &p = q[j * (nu + 1) + i];
        p[a] = c;
        p[u] = lo[u] + (hi[u] - lo[u]) * i / nu;
        p[vv] = lo[vv] + (hi[vv] - lo[vv]) * j / nv;
      }
    std::vector<double> val;
    w.evaluate(q, val);
    PView *view = new PView();
    PViewDataList *data = getDataList(view);
    for(int j = 0; j < nv; j++)
      for(int i = 0; i < nu; i++) {
        const int id[4] = {j * (nu + 1) + i, j * (nu + 1) + i + 1,
                           (j + 1) * (nu + 1) + i + 1, (j + 1) * (nu + 1) + i};
        std::vector<double> *l = data->incrementList(1, TYPE_QUA);
        for(int k = 0; k < 3; k++)
          for(int m = 0; m < 4; m++) l->push_back(q[id[m]][k]);
        for(int m = 0; m < 4; m++) l->push_back(val[id[m]]);
      }
    const std::string name = "Winding number of " + what + ", " + names[a] +
                             " = " + std::to_string(c);
    data->setName(name);
    data->setFileName("WindingNumber.pos");
    data->finalize();
    view->getOptions()->rangeType = PViewOptions::Custom;
    view->getOptions()->customMin = -0.5;
    view->getOptions()->customMax = 1.5;
    Msg::Info("Plugin(WindingNumber): %s (%d x %d points)", name.c_str(),
              nu + 1, nv + 1);
    last = view;
  }

  // the surface where it is 1/2: marching tetrahedra in the cubes of a grid
  // (six around the diagonal of each)
  if(iso) {
    const double h = size * 1.1 / isoResolution;
    int n[3];
    for(int k = 0; k < 3; k++)
      n[k] = std::max(1, (int)std::ceil((hi[k] - lo[k]) / h));
    auto at = [&](int i, int j, int k) {
      return ((std::size_t)k * (n[1] + 1) + j) * (n[0] + 1) + i;
    };
    std::vector<std::array<double, 3> > q((std::size_t)(n[0] + 1) *
                                          (n[1] + 1) * (n[2] + 1));
    for(int k = 0; k <= n[2]; k++)
      for(int j = 0; j <= n[1]; j++)
        for(int i = 0; i <= n[0]; i++)
          q[at(i, j, k)] = {{lo[0] + (hi[0] - lo[0]) * i / n[0],
                             lo[1] + (hi[1] - lo[1]) * j / n[1],
                             lo[2] + (hi[2] - lo[2]) * k / n[2]}};
    std::vector<double> val;
    w.evaluate(q, val);
    static const int tets[6][4] = {{0, 1, 3, 7}, {0, 3, 2, 7}, {0, 2, 6, 7},
                                   {0, 6, 4, 7}, {0, 4, 5, 7}, {0, 5, 1, 7}};
    auto corners = [&](int i, int j, int k, std::size_t corner[8]) {
      for(int c = 0; c < 8; c++)
        corner[c] = at(i + (c & 1), j + ((c >> 1) & 1), k + (c >> 2));
    };
    // (the edges of the tetrahedra the surface crosses, and where: the
    // winding number jumps across the triangles, so that the point between
    // the values at their ends would be in the middle of the edge; it is
    // found by bisection, for all of them at once)
    std::map<std::pair<std::size_t, std::size_t>, std::size_t> cutOf;
    std::vector<std::array<std::size_t, 2> > cuts;
    for(int k = 0; k < n[2]; k++)
      for(int j = 0; j < n[1]; j++)
        for(int i = 0; i < n[0]; i++) {
          std::size_t corner[8];
          corners(i, j, k, corner);
          for(auto &tt : tets)
            for(int a = 0; a < 4; a++)
              for(int b = a + 1; b < 4; b++) {
                const std::size_t pa = corner[tt[a]], pb = corner[tt[b]];
                if((val[pa] > 0.5) == (val[pb] > 0.5)) continue;
                // (from the inside end to the outside one)
                std::pair<std::size_t, std::size_t> e =
                  val[pa] > 0.5 ? std::make_pair(pa, pb) : std::make_pair(pb, pa);
                if(cutOf.insert({e, cuts.size()}).second)
                  cuts.push_back({{e.first, e.second}});
              }
        }
    std::vector<double> s0(cuts.size(), 0.), s1(cuts.size(), 1.);
    std::vector<std::array<double, 3> > mid(cuts.size());
    for(int it = 0; it < 8; it++) {
      for(std::size_t c = 0; c < cuts.size(); c++) {
        const double s = 0.5 * (s0[c] + s1[c]);
        for(int m = 0; m < 3; m++)
          mid[c][m] = q[cuts[c][0]][m] + s * (q[cuts[c][1]][m] - q[cuts[c][0]][m]);
      }
      std::vector<double> wm;
      w.evaluate(mid, wm);
      for(std::size_t c = 0; c < cuts.size(); c++)
        (wm[c] > 0.5 ? s0[c] : s1[c]) = 0.5 * (s0[c] + s1[c]);
    }
    PView *view = new PView();
    PViewDataList *data = getDataList(view);
    std::size_t count = 0;
    for(int k = 0; k < n[2]; k++)
      for(int j = 0; j < n[1]; j++)
        for(int i = 0; i < n[0]; i++) {
          std::size_t corner[8];
          corners(i, j, k, corner);
          for(auto &tt : tets) {
            std::size_t p[4];
            for(int m = 0; m < 4; m++) p[m] = corner[tt[m]];
            std::vector<int> in, out;
            for(int m = 0; m < 4; m++)
              (val[p[m]] > 0.5 ? in : out).push_back(m);
            if(in.empty() || out.empty()) continue;
            auto cut = [&](int a, int b) {
              // (a inside, b outside)
              const std::size_t c = cutOf[{p[a], p[b]}];
              const double s = 0.5 * (s0[c] + s1[c]);
              std::array<double, 3> r;
              for(int m = 0; m < 3; m++)
                r[m] = q[p[a]][m] + s * (q[p[b]][m] - q[p[a]][m]);
              return r;
            };
            auto add = [&](const std::array<double, 3> &a,
                           const std::array<double, 3> &b,
                           const std::array<double, 3> &c) {
              std::vector<double> *l = data->incrementList(1, TYPE_TRI);
              for(int m = 0; m < 3; m++) l->insert(l->end(), {a[m], b[m], c[m]});
              l->insert(l->end(), {0.5, 0.5, 0.5});
              count++;
            };
            if(in.size() == 1)
              add(cut(in[0], out[0]), cut(in[0], out[1]), cut(in[0], out[2]));
            else if(out.size() == 1)
              add(cut(in[0], out[0]), cut(in[1], out[0]), cut(in[2], out[0]));
            else {
              // (two on each side: a quadrangle)
              const std::array<double, 3> a = cut(in[0], out[0]),
                                          b = cut(in[0], out[1]),
                                          c = cut(in[1], out[1]),
                                          d = cut(in[1], out[0]);
              add(a, b, c);
              add(a, c, d);
            }
          }
        }
    const std::string name = "Winding number of " + what + " = 1/2";
    data->setName(name);
    data->setFileName("WindingNumber.pos");
    data->finalize();
    Msg::Info("Plugin(WindingNumber): %s, %lu triangles (grid %d x %d x %d)",
              name.c_str(), count, n[0], n[1], n[2]);
    last = view;
  }
  return last;
}
