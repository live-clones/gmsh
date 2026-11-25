// Checks the face closures and the full closures of the nodal bases of the
// tetrahedra, hexahedra, prisms and pyramids of order 1 to 4:
// - every node of a face closure is at the image of its point of the face
//   basis by the (bi)linear map of the corners of the closure;
// - the corners are those of the same face whatever the sign and the rotation,
//   and the normal of the closures of positive sign points outwards;
// - a full closure is a permutation of the nodes that sends the reference
//   closure on the closure.
//
// It uses the internal headers of Gmsh, so it is built by hand against a
// shared library, e.g. from the build directory:
//
//   c++ -std=c++17 -I../api -I../src/numeric -I../src/common -I../src/geo
//     -Isrc/common ../benchmarks/misc/closures.cpp -L. -lgmsh -Wl,-rpath,.
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include "gmsh.h"
#include "BasisFactory.h"
#include "nodalBasis.h"
#include "ElementType.h"
#include "GmshDefines.h"
#include "fullMatrix.h"

static void faceShape(int nc, double u, double v, double f[4])
{
  if(nc == 3) { f[0] = 1 - u - v; f[1] = u; f[2] = v; }
  else {
    f[0] = (1 - u) * (1 - v) / 4; f[1] = (1 + u) * (1 - v) / 4;
    f[2] = (1 + u) * (1 + v) / 4; f[3] = (1 - u) * (1 + v) / 4;
  }
}

int main(int argc, char **argv)
{
  gmsh::initialize();
  int types[4] = {TYPE_TET, TYPE_HEX, TYPE_PRI, TYPE_PYR};
  const char *names[4] = {"tetrahedron", "hexahedron", "prism", "pyramid"};
  int bad = 0;
  for(int t = 0; t < 4; t++) {
    for(int order = 1; order <= 4; order++) {
      for(int serendip = 0; serendip < 2; serendip++) {
        if(serendip && order < 2) continue;
        int tag = ElementType::getType(types[t], order, serendip);
        if(tag <= 0) { continue; }
        const nodalBasis *fs = BasisFactory::getNodalBasis(tag);
        if(!fs) { printf("%s order %d: no basis\n", names[t], order); continue; }
        const fullMatrix<double> &P = fs->points;
        int n = P.size1(), nclosures = 0, wrongGeom = 0, wrongSet = 0, wrongSign = 0, notFace = 0;
        std::vector<std::set<int> > faceCorners(fs->numFaces);
        for(std::size_t id = 0; id < fs->closures.size(); id++) {
          const nodalBasis::closure &cl = fs->closures[id];
          if(cl.empty()) continue;
          nclosures++;
          int iFace, iSign, iRot; fs->breakClosureId(id, iFace, iSign, iRot);
          const nodalBasis *ff = BasisFactory::getNodalBasis(cl.type);
          int nc = (ff->parentType == TYPE_TRI) ? 3 : 4;
          if((int)cl.size() != ff->points.size1()) { wrongGeom++; continue; }
          // every node at the image of its face point by the map of the corners
          bool ok = true;
          for(std::size_t i = 0; i < cl.size(); i++) {
            if(cl[i] < 0 || cl[i] >= n) { ok = false; break; }
            double f[4]; faceShape(nc, ff->points(i, 0), ff->points(i, 1), f);
            for(int j = 0; j < 3; j++) {
              double x = 0;
              for(int k = 0; k < nc; k++) x += f[k] * P(cl[k], j);
              if(std::abs(x - P(cl[i], j)) > 1e-8) ok = false;
            }
          }
          if(!ok) wrongGeom++;
          // the corners are those of the same face whatever the sign and rotation
          std::set<int> c(cl.begin(), cl.begin() + nc);
          if((int)c.size() != nc) wrongSet++;
          if(faceCorners[iFace].empty()) faceCorners[iFace] = c;
          else if(faceCorners[iFace] != c) wrongSet++;
          // the normal of the positive closures points out of the element
          // (barycentre of the corners of the element at the origin side)
          double a[3], b[3], g[3] = {0, 0, 0}, m[3] = {0, 0, 0};
          int np = ElementType::getNumVertices(ElementType::getType(types[t], 1));
          for(int k = 0; k < np; k++) for(int j = 0; j < 3; j++) g[j] += P(k, j) / np;
          for(int k = 0; k < nc; k++) for(int j = 0; j < 3; j++) m[j] += P(cl[k], j) / nc;
          for(int j = 0; j < 3; j++) { a[j] = P(cl[1], j) - P(cl[0], j); b[j] = P(cl[2], j) - P(cl[0], j); }
          double nn[3] = {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};
          double out = nn[0]*(m[0]-g[0]) + nn[1]*(m[1]-g[1]) + nn[2]*(m[2]-g[2]);
          if(std::abs(out) < 1e-10) notFace++;
          else if((out > 0) != (iSign == 0)) wrongSign++;
        }
        // full closures: permutations sending the reference closure on this one
        int nfull = 0, wrongFull = 0;
        for(std::size_t id = 0; id < fs->fullClosures.size(); id++) {
          const nodalBasis::closure &fc = fs->fullClosures[id];
          if(fc.empty()) continue;
          nfull++;
          bool ok = ((int)fc.size() == n);
          std::set<int> s(fc.begin(), fc.end());
          if((int)s.size() != n) ok = false;
          if(ok && id < fs->closureRef.size() && id < fs->closures.size()) {
            const nodalBasis::closure &ref = fs->closures[fs->closureRef[id]];
            const nodalBasis::closure &cl = fs->closures[id];
            if(ref.size() != cl.size()) ok = false;
            for(std::size_t j = 0; ok && j < cl.size(); j++)
              if(fc[ref[j]] != cl[j]) ok = false;
          }
          if(!ok) wrongFull++;
        }
        int b = wrongGeom + wrongSet + wrongSign + notFace + wrongFull + (nfull ? 0 : 1);
        bad += b;
        printf("%-11s order %d%s: %3d nodes, %2d closures (%d misplaced nodes, %d wrong corners, %d wrong sign, %d degenerate), %2d full closures (%d wrong)%s\n",
               names[t], order, serendip ? " serendipity" : "", n, nclosures, wrongGeom, wrongSet, wrongSign, notFace, nfull, wrongFull, b ? "  <== FAILED" : "");
      }
    }
  }
  gmsh::finalize();
  return bad ? 1 : 0;
}
