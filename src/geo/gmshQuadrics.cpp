// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <stack>
#include <set>
#include <cmath>
#include <numeric>

#include "gmshQuadrics.h"
#include "GModel.h"
#include "GFace.h"
#include "MTriangle.h"
#include "robustPredicates.h"

#if defined(HAVE_ALGLIB)
#include <stdafx.h>
#include <optimization.h>
#endif

static double _tetcircumcenter(double a[3], double b[3], double c[3],
                               double d[3], double circumcenter[3])
{
  double xba, yba, zba, xca, yca, zca, xda, yda, zda;
  double balength, calength, dalength;
  double xcrosscd, ycrosscd, zcrosscd;
  double xcrossdb, ycrossdb, zcrossdb;
  double xcrossbc, ycrossbc, zcrossbc;
  double denominator;
  double xcirca, ycirca, zcirca;

  /* Use coordinates relative to point `a' of the tetrahedron. */
  xba = b[0] - a[0];
  yba = b[1] - a[1];
  zba = b[2] - a[2];
  xca = c[0] - a[0];
  yca = c[1] - a[1];
  zca = c[2] - a[2];
  xda = d[0] - a[0];
  yda = d[1] - a[1];
  zda = d[2] - a[2];
  /* Squares of lengths of the edges incident to `a'. */
  balength = xba * xba + yba * yba + zba * zba;
  calength = xca * xca + yca * yca + zca * zca;
  dalength = xda * xda + yda * yda + zda * zda;
  /* Cross products of these edges. */
  xcrosscd = yca * zda - yda * zca;
  ycrosscd = zca * xda - zda * xca;
  zcrosscd = xca * yda - xda * yca;
  xcrossdb = yda * zba - yba * zda;
  ycrossdb = zda * xba - zba * xda;
  zcrossdb = xda * yba - xba * yda;
  xcrossbc = yba * zca - yca * zba;
  ycrossbc = zba * xca - zca * xba;
  zcrossbc = xba * yca - xca * yba;

  /* Calculate the denominator of the formulae. */
  /* Use orient3d() from http://www.cs.cmu.edu/~quake/robust.html     */
  /*   to ensure a correctly signed (and reasonably accurate) result, */
  /*   avoiding any possibility of division by zero.                  */
  const double xxx = robustPredicates::orient3d(b, c, d, a);
  denominator = 0.5 / xxx;

  /* Calculate offset (from `a') of circumcenter. */
  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
           denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
           denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
           denominator;
  circumcenter[0] = xcirca + a[0];
  circumcenter[1] = ycirca + a[1];
  circumcenter[2] = zcirca + a[2];

  return xxx;
}

// Calcule la norme d'un vecteur 3D
double norm(double x, double y, double z)
{
  return std::sqrt(x * x + y * y + z * z);
}
// Calcule la distance d'un point P à une droite définie par A et la direction
// unitaire u
double distanceToLine(const SPoint3 &P, const SPoint3 &A, const SPoint3 &u)
{
  // Vecteur AP
  double APx = P.x() - A.x();
  double APy = P.y() - A.y();
  double APz = P.z() - A.z();
  // Projection de AP sur u
  double proj = APx * u.x() + APy * u.y() + APz * u.z();
  // Composante perpendiculaire
  double perpX = APx - proj * u.x();
  double perpY = APy - proj * u.y();
  double perpZ = APz - proj * u.z();
  return norm(perpX, perpY, perpZ);
}
// Évalue la fonction coût (somme des carrés des résidus) pour les paramètres
// donnés params : [Ax, Ay, Az, theta, phi, r]

double costFunction(const std::vector<SPoint3> &points, const double params[6])
{
  // Extraction des paramètres
  double Ax = params[0], Ay = params[1], Az = params[2];
  double theta = params[3], phi = params[4], r = params[5];
  // Calcul de la direction u à partir de theta et phi
  SPoint3 u(std::sin(theta) * std::cos(phi), std::sin(theta) * std::sin(phi),
            std::cos(theta));
  SPoint3 A = {Ax, Ay, Az};
  double cost = 0.0;
  for(const auto &P : points) {
    double d = distanceToLine(P, A, u);
    double res = d - r;
    cost += res * res;
  }
  return cost;
}

// Calcule numériquement le gradient de la fonction coût par rapport aux 6
// paramètres
void computeGradient(const std::vector<SPoint3> &points, const double params[6],
                     double grad[6])
{
  double epsilon = 1e-12;
  double paramsPerturbed[6];
  double cost_plus, cost_minus;

  for(int i = 0; i < 6; ++i) {
    // Copie des paramètres
    for(int j = 0; j < 6; ++j) { paramsPerturbed[j] = params[j]; }
    paramsPerturbed[i] += epsilon;
    cost_plus = costFunction(points, paramsPerturbed);

    for(int j = 0; j < 6; ++j) { paramsPerturbed[j] = params[j]; }
    paramsPerturbed[i] -= epsilon;
    cost_minus = costFunction(points, paramsPerturbed);

    grad[i] = (cost_plus - cost_minus) / (2 * epsilon);
  }
}

#if defined(HAVE_ALGLIB)

static void bfgs_callback_cyl(const alglib::real_1d_array &x, double &func,
                              alglib::real_1d_array &grad, void *ptr)
{
  std::vector<SPoint3> *points = (std::vector<SPoint3> *)ptr;
  double p[6] = {x[0], x[1], x[2], x[3], x[4], x[5]};
  func = costFunction(*points, p);
  double g[6];
  computeGradient(*points, p, g);
  for(int i = 0; i < 6; i++) grad[i] = g[i];
}

#endif

void fitCylinder(std::vector<SPoint3> &points, double params[6])
{
#if defined(HAVE_ALGLIB)
  alglib::ae_int_t dim = 6;
  alglib::ae_int_t corr = 2; // Num of corrections in the scheme in [3,7]
  alglib::minlbfgsstate state;
  alglib::real_1d_array x;
  const double initialCond[6] = {0, 0, 0, 0, 0, 1};
  x.setcontent(dim, initialCond);
  minlbfgscreate(6, corr, x, state);
  // Set stopping criteria
  const double epsg = 1.e-12;
  const double epsf = 0.;
  const double epsx = 0.;
  const alglib::ae_int_t maxits = 500;
  minlbfgssetcond(state, epsg, epsf, epsx, maxits);

  // Solve problem
  minlbfgsoptimize(state, bfgs_callback_cyl, nullptr, &points);

  // Get results
  alglib::minlbfgsreport rep;
  minlbfgsresults(state, x, rep);
  for(int i = 0; i < 6; i++) params[i] = x[i];
#else
  Msg::Error("fitCylinder requires ALGLIB");
#endif
}

void gmshQuadricSphere::compute(std::vector<SPoint3> &p)
{
  R = _tetcircumcenter(p[0], p[1], p[2], p[3], P);
}

double gmshQuadricSphere::distance(const SPoint3 &p)
{
  return fabs(p.distance(P) - R);
}

void gmshQuadricPlane::compute(std::vector<SPoint3> &p)
{
  computeMeanPlaneSimple(p, meanPlane);
}

double gmshQuadricPlane::distance(const SPoint3 &p)
{
  double norm = sqrt(meanPlane.a * meanPlane.a + meanPlane.b * meanPlane.b +
                     meanPlane.c * meanPlane.c);
  double dist = fabs(meanPlane.a * p.x() + meanPlane.b * p.y() +
                     meanPlane.c * p.z() - meanPlane.d) /
                norm;
  return dist;
}

void gmshQuadricCylinder::compute(std::vector<SPoint3> &points)
{
  double p[6];
  fitCylinder(points, p);
  P = {p[0], p[1], p[2]};
  double theta = p[3], phi = p[4];
  D = {std::sin(theta) * std::cos(phi), std::sin(theta) * std::sin(phi),
       std::cos(theta)};
  R = p[5];
}

double gmshQuadricCylinder::distance(const SPoint3 &p)
{
  return fabs(crossprod(D, (p - P)).norm() - R);
}

void discoverQuadric(GFace *gf, int typeOfQuadric,
                     std::map<MTriangle *, int> _classified, double eps,
                     std::size_t minn)
{
  std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> cont;
  printf("face %d -- %zu triangles\n", gf->tag(), gf->triangles.size());

  for(auto t : gf->triangles) {
    for(int i = 0; i < t->getNumEdges(); i++) {
      cont[t->getEdge(i)].push_back(t);
    }
  }

  printf("face %d -- %zu edges\n", gf->tag(), cont.size());

  int iter = 0;
  while(iter < (int)(gf->triangles.size() - _classified.size())) {
    gmshQuadric *gmshQ = nullptr;
    if(typeOfQuadric == 1)
      gmshQ = new gmshQuadricPlane;
    else if(typeOfQuadric == 2)
      gmshQ = new gmshQuadricCylinder;
    else if(typeOfQuadric == 3)
      gmshQ = new gmshQuadricSphere;
    else
      return;
    size_t i = rand() % gf->triangles.size();
    MTriangle *t = gf->triangles[i];
    if(_classified.find(t) != _classified.end()) continue;
    iter++;
    std::set<MTriangle *> _touched;
    std::stack<MTriangle *> _stack;
    std::vector<MTriangle *> _quadric;
    _stack.push(t);
    _touched.insert(t);
    for(size_t l = 0; l < 3; l++)
      gmshQ->addPointIfOk(SPoint3(t->getVertex(l)->x(), t->getVertex(l)->y(),
                                  t->getVertex(l)->z()),
                          1.e-22);

    while(!_stack.empty()) {
      auto t = _stack.top();
      _quadric.push_back(t);
      _stack.pop();
      for(int k = 0; k < 3; k++) {
        MEdge ed = t->getEdge(k);
        MVertex *v0 = ed.getVertex(0);
        MVertex *v1 = ed.getVertex(1);
        auto it = cont.find(ed);
        if(it != cont.end()) {
          auto ts = it->second;
          if(ts.size() == 2) {
            for(auto neigh : ts) {
              if(neigh != t && _touched.find(neigh) == _touched.end()) {
                _touched.insert(neigh);
                for(size_t l = 0; l < 3; l++) {
                  if(neigh->getVertex(l) != v0 && neigh->getVertex(l) != v1) {
                    SPoint3 pp(neigh->getVertex(l)->x(),
                               neigh->getVertex(l)->y(),
                               neigh->getVertex(l)->z());
                    if(gmshQ->addPointIfOk(pp, eps)) { _stack.push(neigh); }
                  }
                }
              }
            }
          }
        }
      }
    }
    if(_quadric.size() > minn || _quadric.size() == gf->triangles.size()) {
      printf("iter %d _quadric.size() = %zu\n", iter, _quadric.size());
      std::string fn = gmshQ->name() + std::to_string(iter) + ".pos";
      FILE *f = fopen(fn.c_str(), "w");
      fprintf(f, "View \"%s \"{\n", gmshQ->name().c_str());
      for(auto t : _quadric) {
        _classified[t] = iter;
        fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                t->getVertex(0)->x(), t->getVertex(0)->y(),
                t->getVertex(0)->z(), t->getVertex(1)->x(),
                t->getVertex(1)->y(), t->getVertex(1)->z(),
                t->getVertex(2)->x(), t->getVertex(2)->y(),
                t->getVertex(2)->z(), iter, iter, iter);
      }
      fprintf(f, "};\n");
      fclose(f);
      // break;
    }
    delete gmshQ;
  }
}

void discoverQuadrics(GModel *gm)
{
  std::map<MTriangle *, int> _classified;
  for(auto it = gm->firstFace(); it != gm->lastFace(); it++) {
    discoverQuadric(*it, 1, _classified, 1.e-7, 30);
    // discoverQuadric(*it,1,_classified);
    discoverQuadric(*it, 2, _classified, 1.e-7, 10);
    discoverQuadric(*it, 3, _classified, 1.e-7, 10);
    // discoverQuadric(*it,3,_classified);
  }
}
