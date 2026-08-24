// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include <stdio.h>
#include "GFace.h"
#include "GEdge.h"
#include "OS.h"
#include "robustPredicates.h"
#include "meshGFaceParamBoundary.h"

bool pointInsideParametricDomain(std::vector<SPoint2> &bnd, SPoint2 &p,
                                 SPoint2 &out, int &N)
{
  int count = 0;
  for(size_t i = 0; i < bnd.size(); i += 2) {
    SPoint2 p1 = bnd[i];
    SPoint2 p2 = bnd[i + 1];
    double a = robustPredicates::orient2d(p1, p2, p);
    double b = robustPredicates::orient2d(p1, p2, out);
    if(a * b < 0) {
      a = robustPredicates::orient2d(p, out, p1);
      b = robustPredicates::orient2d(p, out, p2);
      if(a * b < 0) count++;
    }
  }
  N = count;
  if(count % 2 == 0) return false;
  return true;
}

void trueBoundary(GFace *gf, std::vector<SPoint2> &bnd, int debug)
{
  FILE *view_t = nullptr;
  if(debug) {
    char name[245];
    sprintf(name, "trueBoundary%d.pos", gf->tag());
    view_t = Fopen(name, "w");
    if(view_t) fprintf(view_t, "View \"True Boundary\"{\n");
  }
  std::vector<GEdge *> edg = gf->edges();
  std::set<GEdge *> edges(edg.begin(), edg.end());

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    GEdge *ge = *it;
    Range<double> r = ge->parBoundsOnFace(gf);
    SPoint2 p[300];
    int NITER = ge->isSeam(gf) ? 2 : 1;
    for(int i = 0; i < NITER; i++) {
      int count = NITER == 2 ? 300 : 300;
      for(int k = 0; k < count; k++) {
        double t = (double)k / (count - 1);
        double xi = r.low() + (r.high() - r.low()) * t;
        p[k] = ge->reparamOnFace(gf, xi, i);
        if(k > 0) {
          if(view_t) {
            fprintf(view_t, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", p[k - 1].x(),
                    p[k - 1].y(), 0.0, p[k].x(), p[k].y(), 0.0, ge->tag(),
                    ge->tag());
          }
          bnd.push_back(p[k - 1]);
          bnd.push_back(p[k]);
        }
      }
    }
  }
  if(view_t) {
    fprintf(view_t, "};\n");
    fclose(view_t);
  }
}
