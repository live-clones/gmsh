// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <stack>
#include <queue>
#include <random>
#include "OS.h"
#include "GmshConfig.h"
#include "gmshCrossFields.h"
#include "GModel.h"
#include "GFace.h"
#include "MEdge.h"
#include "MLine.h"
#include "MTriangle.h"
#include "GmshMessage.h"
#include "Context.h"
#include "meshGFaceOptimize.h"
#include "discreteEdge.h"
#include "Numeric.h"
#include "GModelParametrize.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataGModel.h"
#endif

#if defined(HAVE_SOLVER) && defined(HAVE_POST)

#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemGmm.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#include "linearSystemPETSc.h"

static inline double lifting(double a, double _a)
{
  double D = M_PI * .5;
  if(fabs(_a - a) < fabs(_a - (a + D)) && fabs(_a - a) < fabs(_a - (a - D))) {
    return a;
  }
  else if(fabs(_a - (a + D)) < fabs(_a - a) &&
          fabs(_a - (a + D)) < fabs(_a - (a - D))) {
    return a + D;
  }
  else {
    return a - D;
  }
}

static inline double compat_orientation_extrinsic(const double *o0,
                                                  const double *n0,
                                                  const double *o1,
                                                  const double *n1, double *a1,
                                                  double *b1)
{
  double t0[3] = {n0[1] * o0[2] - n0[2] * o0[1], n0[2] * o0[0] - n0[0] * o0[2],
                  n0[0] * o0[1] - n0[1] * o0[0]};
  double t1[3] = {n1[1] * o1[2] - n1[2] * o1[1], n1[2] * o1[0] - n1[0] * o1[2],
                  n1[0] * o1[1] - n1[1] * o1[0]};

  const size_t permuts[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0},
                                {0, 1}, {1, 1}, {2, 1}, {3, 1}};
  const double A[4][3] = {{o0[0], o0[1], o0[2]},
                          {t0[0], t0[1], t0[2]},
                          {-o0[0], -o0[1], -o0[2]},
                          {-t0[0], -t0[1], -t0[2]}};
  const double B[2][3] = {{o1[0], o1[1], o1[2]}, {t1[0], t1[1], t1[2]}};

  double maxx = -1;
  int index = 0;
  for(size_t i = 0; i < 8; i++) {
    const size_t II = permuts[i][0];
    const size_t JJ = permuts[i][1];
    const double xx =
      A[II][0] * B[JJ][0] + A[II][1] * B[JJ][1] + A[II][2] * B[JJ][2];
    if(xx > maxx) {
      index = i;
      maxx = xx;
    }
  }
  a1[0] = A[permuts[index][0]][0];
  a1[1] = A[permuts[index][0]][1];
  a1[2] = A[permuts[index][0]][2];
  b1[0] = B[permuts[index][1]][0];
  b1[1] = B[permuts[index][1]][1];
  b1[2] = B[permuts[index][1]][2];
  //  b1 = B[permuts[index][1]];
  return maxx;
}

static inline double compat_orientation_extrinsic(const SVector3 &o0,
                                                  const SVector3 &n0,
                                                  const SVector3 &o1,
                                                  const SVector3 &n1,
                                                  SVector3 &a1, SVector3 &b1)
{
  SVector3 t0 = crossprod(n0, o0);
  SVector3 t1 = crossprod(n1, o1);

  const size_t permuts[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0},
                                {0, 1}, {1, 1}, {2, 1}, {3, 1}};
  SVector3 A[4]{o0, t0, -o0, -t0};
  SVector3 B[2]{o1, t1};

  double maxx = -1;
  int index = 0;
  for(size_t i = 0; i < 8; i++) {
    const double xx = dot(A[permuts[i][0]], B[permuts[i][1]]);
    if(xx > maxx) {
      index = i;
      maxx = xx;
    }
  }
  a1 = A[permuts[index][0]];
  b1 = B[permuts[index][1]];
  return maxx;
}

class cross2d {
public:
  MEdge _e;
  bool inCutGraph;
  bool inBoundary;
  bool inInternalBoundary;
  bool rotation;
  //  int cutGraphPart;
  size_t counter;
  SVector3 o_i; // orientation vector
  SVector3 _nrml, _tgt, _tgt2; // local system of coordinates
  std::vector<MEdge> _neighbors;
  std::vector<cross2d *> _cneighbors;
  double da[4];
  double _cc[4], _ss[4];
  // euler angles
  double _a, _b, _c;
  double _atemp, _btemp, _ctemp;
  std::vector<MTriangle *> _t;
  cross2d(MEdge &e, MTriangle *r, MEdge &e1, MEdge &e2)
    : _e(e), inCutGraph(false), inBoundary(false), inInternalBoundary(false),
      _a(0), _b(0), _c(0)
  {
    _t.push_back(r);
    _neighbors.push_back(e1);
    _neighbors.push_back(e2);
  }
  void normalize(double &a)
  {
    double D = M_PI * .5;
    if(a < 0)
      while(a < 0) a += D;
    if(a >= D)
      while(a >= D) a -= D;
  }
  void finish2()
  {
    if(_cneighbors.size() == 4) {
      SVector3 x(0, 1, 0);
      _a = _atemp = atan2(dot(_tgt2, x), dot(_tgt, x));
      if(!inBoundary && !inInternalBoundary) {
        _b = _btemp = sin(4 * _a);
        _c = _ctemp = cos(4 * _a);
      }
      else {
        _b = _btemp = 0;
        _c = _ctemp = 1;
      }
      for(size_t i = 0; i < 4; i++) {
        da[i] = atan2(dot(_tgt2, _cneighbors[i]->_tgt),
                      dot(_tgt, _cneighbors[i]->_tgt));
        _cc[i] = cos(4 * da[i]);
        _ss[i] = sin(4 * da[i]);
      }
    }
  }

  void finish(std::map<MEdge, cross2d, MEdgeLessThan> &C)
  {
    _tgt = SVector3(1, 0, 0);
    _tgt2 = SVector3(0, 1, 0);
    if(_t.size() <= 2) {
      SVector3 v10(_t[0]->getVertex(1)->x() - _t[0]->getVertex(0)->x(),
                   _t[0]->getVertex(1)->y() - _t[0]->getVertex(0)->y(),
                   _t[0]->getVertex(1)->z() - _t[0]->getVertex(0)->z());
      SVector3 v20(_t[0]->getVertex(2)->x() - _t[0]->getVertex(0)->x(),
                   _t[0]->getVertex(2)->y() - _t[0]->getVertex(0)->y(),
                   _t[0]->getVertex(2)->z() - _t[0]->getVertex(0)->z());
      SVector3 xx = crossprod(v20, v10);
      xx.normalize();
      SVector3 yy = xx;
      if(_t.size() == 2) {
        SVector3 v10b(_t[1]->getVertex(1)->x() - _t[1]->getVertex(0)->x(),
                      _t[1]->getVertex(1)->y() - _t[1]->getVertex(0)->y(),
                      _t[1]->getVertex(1)->z() - _t[1]->getVertex(0)->z());
        SVector3 v20b(_t[1]->getVertex(2)->x() - _t[1]->getVertex(0)->x(),
                      _t[1]->getVertex(2)->y() - _t[1]->getVertex(0)->y(),
                      _t[1]->getVertex(2)->z() - _t[1]->getVertex(0)->z());
        yy = crossprod(v20b, v10b);
        yy.normalize();
        //        if(dot(xx, yy) < .5) inInternalBoundary = 1;
      }
      _nrml = xx + yy;
      _nrml.normalize();
      SVector3 vt(_e.getVertex(1)->x() - _e.getVertex(0)->x(),
                  _e.getVertex(1)->y() - _e.getVertex(0)->y(),
                  _e.getVertex(1)->z() - _e.getVertex(0)->z());
      _tgt = vt;
      _tgt.normalize();
      _tgt2 = crossprod(_nrml, _tgt);
    }

    if(_t.size() == 1) { inBoundary = true; }
    else if(_t.size() >= 2) {
      if(inBoundary) {
        inBoundary = false;
        inInternalBoundary = true;
      }
    }

    for(size_t i = 0; i < _neighbors.size(); i++) {
      auto it = C.find(_neighbors[i]);
      if(it == C.end())
        Msg::Error("impossible situation");
      else
        _cneighbors.push_back(&(it->second));
    }
    if(_cneighbors.size() != 4) {
      _a = 0;
      _atemp = _a;
    }
    _neighbors.clear();
    _b = _btemp = sin(4 * _a);
    _c = _ctemp = cos(4 * _a);
  }
  double average_init()
  {
    if(!inBoundary && !inInternalBoundary) {
      _btemp = 0;
      _ctemp = 0;
      for(int i = 0; i < 4; i++) {
        _ctemp += (_cneighbors[i]->_c * _cc[i] - _cneighbors[i]->_b * _ss[i]);
        _btemp += (_cneighbors[i]->_c * _ss[i] + _cneighbors[i]->_b * _cc[i]);
      }
      _btemp *= 0.25;
      _ctemp *= 0.25;
      _b = _btemp;
      _c = _ctemp;
    }
    return 1;
  }

  double grad()
  {
    if(!inBoundary && !inInternalBoundary) {
      double D = M_PI * .5;
      double a[4] = {_cneighbors[0]->_a, _cneighbors[1]->_a, _cneighbors[2]->_a,
                     _cneighbors[3]->_a};
      for(int i = 0; i < 4; i++) {
        a[i] += da[i];
        normalize(a[i]);
      }

      double b[4];
      for(int i = 0; i < 4; i++) {
        if(fabs(_a - a[i]) < fabs(_a - (a[i] + D)) &&
           fabs(_a - a[i]) < fabs(_a - (a[i] - D))) {
          b[i] = a[i];
        }
        else if(fabs(_a - (a[i] + D)) < fabs(_a - (a[i])) &&
                fabs(_a - (a[i] + D)) < fabs(_a - (a[i] - D))) {
          b[i] = a[i] + D;
        }
        else {
          b[i] = a[i] - D;
        }
      }
      return fabs(_a - b[0]) + fabs(_a - b[1]) + fabs(_a - b[2]) +
             fabs(_a - b[3]);
    }
    return 0;
  }

  double lifting(double a)
  {
    double D = M_PI * .5;
    if(fabs(_a - a) < fabs(_a - (a + D)) && fabs(_a - a) < fabs(_a - (a - D))) {
      return a;
    }
    else if(fabs(_a - (a + D)) < fabs(_a - a) &&
            fabs(_a - (a + D)) < fabs(_a - (a - D))) {
      return a + D;
    }
    else {
      return a - D;
    }
  }

  void computeVector()
  {
    _a = _atemp = 0.25 * atan2(_btemp, _ctemp);
    normalize(_atemp);
    o_i = _tgt * cos(_atemp) + _tgt2 * sin(_atemp);
  }

  void computeAngle()
  {
    if(_cneighbors.size() != 4) return;
    double _anew = atan2(dot(_tgt2, o_i), dot(_tgt, o_i));
    normalize(_anew);
    _a = _atemp = _anew;
  }

  double average2()
  {
    // TEMPORARY VERSION, slow but correct
    // Instant field-aligned meshes
    if(_cneighbors.size() != 4) return 0;
    double weight = 0.0;
    SVector3 o_i_old = o_i;
    SVector3 n_i = _nrml;
    for(int i = 0; i < 4; i++) {
      SVector3 o_j = _cneighbors[i]->o_i;
      SVector3 n_j = _cneighbors[i]->_nrml;
      SVector3 x, y;
      compat_orientation_extrinsic(o_i, n_i, o_j, n_j, x, y);
      o_i = x * weight + y;
      o_i -= n_i * dot(o_i, n_i);
      o_i.normalize();
      weight += 1.0;
    }
    return std::min(1. - fabs(dot(o_i, o_i_old)), fabs(dot(o_i, o_i_old)));
  }

  double average()
  {
    if(_cneighbors.size() == 4) {
      double D = M_PI * .5;
      double a[4] = {_cneighbors[0]->_a, _cneighbors[1]->_a, _cneighbors[2]->_a,
                     _cneighbors[3]->_a};
      for(int i = 0; i < 4; i++) {
        a[i] += da[i];
        normalize(a[i]);
      }

      double b[4];
      double avg = 0.0;
      for(int i = 0; i < 4; i++) {
        if(fabs(_a - a[i]) < fabs(_a - (a[i] + D)) &&
           fabs(_a - a[i]) < fabs(_a - (a[i] - D))) {
          b[i] = a[i];
        }
        else if(fabs(_a - (a[i] + D)) < fabs(_a - (a[i])) &&
                fabs(_a - (a[i] + D)) < fabs(_a - (a[i] - D))) {
          b[i] = a[i] + D;
        }
        else {
          b[i] = a[i] - D;
        }
      }
      avg = 0.25 * (b[0] + b[1] + b[2] + b[3]);

      normalize(avg);

      double d = fabs(_a - avg);
      _a = _atemp = avg;

      return d;
    }
    return 0;
  }
};

struct cross2dPtrLessThan {
  MEdgeLessThan l;
  bool operator()(const cross2d *v1, const cross2d *v2) const
  {
    return l(v1->_e, v2->_e);
  }
};

// ---------------------------------------------
// TODO : MAKE IT PARALLEL AND SUPERFAST
//        DO IT ON SURFACES
// ---------------------------------------------

static void closest(const cross2d &c1, const cross2d &c2, double &a2,
                    double &diff)
{
  SVector3 d = c1._tgt * cos(c1._atemp) + c1._tgt2 * sin(c1._atemp);

  double P = M_PI / 2;

  SVector3 d1 = c2._tgt * cos(c2._atemp) + c2._tgt2 * sin(c2._atemp);
  SVector3 d2 = c2._tgt * cos(c2._atemp + P) + c2._tgt2 * sin(c2._atemp + P);
  SVector3 d3 =
    c2._tgt * cos(c2._atemp + 2 * P) + c2._tgt2 * sin(c2._atemp + 2 * P);
  SVector3 d4 =
    c2._tgt * cos(c2._atemp + 3 * P) + c2._tgt2 * sin(c2._atemp + 3 * P);

  double D1 = dot(d, d1);
  double D2 = dot(d, d2);
  double D3 = dot(d, d3);
  double D4 = dot(d, d4);
  diff = acos(D1);
  if(D1 > D2 && D1 > D3 && D1 > D4) { a2 = c2._atemp; }
  else if(D2 > D1 && D2 > D3 && D2 > D4) {
    a2 = c2._atemp + P;
  }
  else if(D3 > D1 && D3 > D2 && D3 > D4) {
    a2 = c2._atemp + 2 * P;
  }
  else {
    a2 = c2._atemp + 3 * P;
  }
}

static void computeLifting(cross2d *first, int branch,
                           std::set<MEdge, MEdgeLessThan> &cutG,
                           std::set<MVertex *, MVertexPtrLessThan> &sing,
                           std::set<MVertex *, MVertexPtrLessThan> &bnd,
                           std::set<cross2d *> &visited)
{
  // store in _atemp the branch of the neighbor
  std::set<MVertex *, MVertexPtrLessThan> cg;
  {
    auto it = cutG.begin();
    for(; it != cutG.end(); ++it) {
      cg.insert(it->getVertex(0));
      cg.insert(it->getVertex(1));
    }
  }

  FILE *_f = fopen("visited.pos", "w");
  fprintf(_f, "View\"\"{\n");

  std::queue<cross2d *> _s;
  _s.push(first);
  first->_atemp = first->_a + branch * M_PI / 2.0;
  first->_btemp = 10000.;
  visited.insert(first);
  while(!_s.empty()) {
    cross2d *c = _s.front();
    _s.pop();
    if(cutG.find(c->_e) == cutG.end()) {
      for(size_t i = 0; i < c->_cneighbors.size(); i++) {
        double a2, diff;
        cross2d *n = c->_cneighbors[i];
        closest(*c, *n, a2, diff);
        if(n->_btemp < 1000) {
          n->_btemp = 10000;

          bool s0 = sing.find(n->_e.getVertex(0)) != sing.end();
          bool s1 = sing.find(n->_e.getVertex(1)) != sing.end();
          bool c0 = cg.find(n->_e.getVertex(0)) != cg.end();
          bool c1 = cg.find(n->_e.getVertex(1)) != cg.end();
          bool b0 = bnd.find(n->_e.getVertex(0)) != bnd.end();
          bool b1 = bnd.find(n->_e.getVertex(1)) != bnd.end();

          s0 = s1 = false;
          // b0 = b1 = false;
          if(((s0 && c1) || (s0 && b1)) || ((s1 && c0) || (s1 && b0))) {
            printf("BLOCKED \n");
          }

          if((!s0 && !s1)) _s.push(n);
          // printf("%12.5E %12.5E %12.5E\n",n->a,n->_atemp,c->_atemp);
          n->_atemp = a2;
          visited.insert(n);
          SVector3 d = n->_tgt * cos(n->_atemp) + n->_tgt2 * sin(n->_atemp);
          fprintf(_f, "VL(%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g};\n",
                  n->_e.getVertex(0)->x(), n->_e.getVertex(0)->y(),
                  n->_e.getVertex(0)->z(), n->_e.getVertex(1)->x(),
                  n->_e.getVertex(1)->y(), n->_e.getVertex(1)->z(), d.x(),
                  d.y(), d.z(), d.x(), d.y(), d.z());
        }
      }
    }
  }
  fprintf(_f, "};\n");
  fclose(_f);
}

struct groupOfCross2d {
  int groupId;
  bool rot;
  double mat[2][2];
  std::vector<MVertex *> vertices;
  std::vector<MVertex *> singularities;
  std::vector<MVertex *> left;
  std::vector<MVertex *> right;
  std::vector<cross2d *> crosses;
  std::vector<MTriangle *> side;
  void print(FILE *f)
  {
    for(size_t i = 0; i < crosses.size(); i++) {
      fprintf(
        f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", crosses[i]->_e.getVertex(0)->x(),
        crosses[i]->_e.getVertex(0)->y(), crosses[i]->_e.getVertex(0)->z(),
        crosses[i]->_e.getVertex(1)->x(), crosses[i]->_e.getVertex(1)->y(),
        crosses[i]->_e.getVertex(1)->z(), groupId, groupId);
    }
    for(size_t i = 0; i < side.size(); i++) {
      fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
              side[i]->getVertex(0)->x(), side[i]->getVertex(0)->y(),
              side[i]->getVertex(0)->z(), side[i]->getVertex(1)->x(),
              side[i]->getVertex(1)->y(), side[i]->getVertex(1)->z(),
              side[i]->getVertex(2)->x(), side[i]->getVertex(2)->y(),
              side[i]->getVertex(2)->z(), groupId, groupId, groupId);
    }
  };
  groupOfCross2d(int id) : groupId(id) {}
};

static void unDuplicateNodesInCutGraph(
  std::vector<GFace *> &f,
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> &new2old)
{
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      for(size_t k = 0; k < 3; k++) {
        auto it = new2old.find(t->getVertex(k));
        if(it != new2old.end()) t->setVertex(k, it->second);
      }
    }
  }
}

static void duplicateNodesInCutGraph(
  std::vector<GFace *> &f, std::map<MEdge, cross2d, MEdgeLessThan> &C,
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> &new2old,
  std::multimap<MVertex *, MVertex *, MVertexPtrLessThan> &old2new,
  std::map<MEdge, MEdge, MEdgeLessThan> &duplicateEdges,
  std::set<MVertex *, MVertexPtrLessThan> &sing, v2t_cont &adj,
  std::vector<groupOfCross2d> &G)
{
  FILE *_f = fopen("nodes.pos", "w");
  fprintf(_f, "View \" nodes \"{\n");

  auto it = adj.begin();
  std::set<MElement *> touched;
  std::set<MVertex *, MVertexPtrLessThan> vtouched;

  std::vector<std::pair<MElement *, std::pair<int, MVertex *> > > replacements;

  while(it != adj.end()) {
    std::vector<MElement *> els = it->second;
    int ITER = 0;
    while(!els.empty()) {
      std::vector<MElement *> _side;
      std::stack<MElement *> _s;
      _s.push(els[0]);
      _side.push_back(els[0]);
      els.erase(els.begin());
      while(!_s.empty()) {
        MElement *t = _s.top();
        _s.pop();
        for(int i = 0; i < 3; i++) {
          MEdge e0 = t->getEdge(i);
          auto it0 = C.find(e0);
          if(!it0->second.inCutGraph) {
            for(size_t j = 0; j < it0->second._t.size(); j++) {
              auto ite = std::find(els.begin(), els.end(), it0->second._t[j]);
              if(ite != els.end()) {
                els.erase(ite);
                _side.push_back(it0->second._t[j]);
                _s.push(it0->second._t[j]);
              }
            }
          }
        }
      }

      if(ITER) {
        MVertex *v =
          new MVertex(it->first->x(), it->first->y(), it->first->z(), f[0]);
        std::pair<MVertex *, MVertex *> p = std::make_pair(it->first, v);
        old2new.insert(p);
        f[0]->mesh_vertices.push_back(v);
        for(size_t i = 0; i < _side.size(); i++) {
          for(size_t j = 0; j < 3; j++) {
            if(_side[i]->getVertex(j) == it->first) {
              std::pair<int, MVertex *> r = std::make_pair(j, v);
              std::pair<MElement *, std::pair<int, MVertex *> > r2 =
                std::make_pair(_side[i], r);
              replacements.push_back(r2);
            }
          }
        }
        fprintf(_f, "SP(%g,%g,%g){%d};\n", it->first->x(), it->first->y(),
                it->first->z(), (int)els.size());
        // printf("found vertex with %d on one side\n",els.size());
      }
      ++ITER;
    }
    //    if (ITER > 1)printf("ITER = %d\n",ITER);
    ++it;
  }
  fprintf(_f, "};\n");
  fclose(_f);

  for(size_t i = 0; i < replacements.size(); i++) {
    MElement *e = replacements[i].first;
    int j = replacements[i].second.first;
    MVertex *v = replacements[i].second.second;
    MVertex *old = e->getVertex(j);
    for(int j = 0; j < e->getNumEdges(); j++) {
      MEdge ed = e->getEdge(j);
      if(ed.getVertex(0) == old) {
        duplicateEdges[ed] = MEdge(v, ed.getVertex(1));
      }
      else if(ed.getVertex(1) == old) {
        duplicateEdges[ed] = MEdge(ed.getVertex(0), v);
      }
    }
    new2old[v] = old;
    e->setVertex(j, v);
  }
}

static void
computeUniqueVectorPerTriangle(GModel *gm, std::vector<GFace *> &f,
                               std::map<MEdge, cross2d, MEdgeLessThan> &C,
                               int dir, std::map<MTriangle *, SVector3> &d)
{
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      SVector3 a0(0, 0, 0);
      int n = 0;
      for(int k = 0; k < 3; k++) {
        MEdge e = t->getEdge(k);
        auto it = C.find(e);
        if(it != C.end()) {
          if(!it->second.inCutGraph) {
            n++;
            double C =
              (dir == 1) ? cos(it->second._atemp) : sin(it->second._atemp);
            double S =
              (dir == 1) ? sin(it->second._atemp) : -cos(it->second._atemp);
            SVector3 aa = it->second._tgt * C + it->second._tgt2 * S;
            a0 += aa;
          }
        }
        else {
          printf("ERROR\n");
        }
      }
      if(n) a0.normalize();
      d[t] = a0;
    }
  }
}

int ZERO_ = -8;

static void createLagrangeMultipliers(dofManager<double> &myAssembler,
                                      groupOfCross2d &g)
{
  // return;
  //  if (g.crosses[0]->inInternalBoundary)return;

  if(g.singularities.size() == 1) {
    //    printf("group id %d singularity %lu (%lu)\n", g.groupId,
    //           g.singularities[0]->getNum(), g.singularities.size());
    myAssembler.numberVertex(g.singularities[0], 0, 33);
    myAssembler.numberVertex(g.singularities[0], 0, 34);
  }
  else {
    //    printf("group id %d %lu singularities \n", g.groupId,
    //           g.singularities.size());
  }

  if(g.groupId == ZERO_) {
    myAssembler.numberVertex(g.left[0], 0, 3 + 10000 * g.groupId);
  }

  for(size_t K = 1; K < g.left.size(); K++) {
    myAssembler.numberVertex(g.left[K], 0, 3 + 100 * g.groupId);
    myAssembler.numberVertex(g.left[K], 0, 4 + 100 * g.groupId);
  }
}

static void LagrangeMultipliers3(dofManager<double> &myAssembler,
                                 groupOfCross2d &g,
                                 std::map<MTriangle *, SVector3> &d0,
                                 bool assemble)
{
  return;
  if(g.crosses[0]->inInternalBoundary) {
    if(!assemble) {
      //      printf("group %d is internal\n",g.groupId);
      for(size_t K = 1; K < g.left.size(); K++) {
        myAssembler.numberVertex(g.left[K], 0, 12 + 100 * g.groupId);
        myAssembler.numberVertex(g.left[K], 0, 13 + 100 * g.groupId);
      }
      return;
    }

    MTriangle *t0 = g.crosses[0]->_t[0];
    MTriangle *t1 = g.crosses[0]->_t[1];
    SVector3 dir0 = d0[t0];
    SVector3 dir1 = d0[t1];

    if(std::find(g.side.begin(), g.side.end(), t1) != g.side.end()) {
      dir0 = d0[t1];
      dir1 = d0[t0];
    }

    printf("%12.5E %12.5E\n", fabs(dot(g.crosses[0]->_tgt, dir0)),
           fabs(dot(g.crosses[0]->_tgt, dir1)));

    Dof U1R(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
    Dof U2R(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
    Dof V1R(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));
    Dof V2R(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));
    for(size_t K = 1; K < g.left.size(); K++) {
      Dof E1(g.left[K]->getNum(),
             Dof::createTypeWithTwoInts(0, 12 + 100 * g.groupId));
      Dof E2(g.left[K]->getNum(),
             Dof::createTypeWithTwoInts(0, 13 + 100 * g.groupId));
      Dof U1(g.left[K]->getNum(), Dof::createTypeWithTwoInts(0, 1));
      Dof U2(g.right[K]->getNum(), Dof::createTypeWithTwoInts(0, 1));
      Dof V1(g.left[K]->getNum(), Dof::createTypeWithTwoInts(0, 2));
      Dof V2(g.right[K]->getNum(), Dof::createTypeWithTwoInts(0, 2));

      if(fabs(dot(g.crosses[0]->_tgt, dir0)) > .5) {
        myAssembler.assemble(E1, U1, 1.0);
        myAssembler.assemble(U1, E1, 1.0);
        myAssembler.assemble(E1, U1R, -1.0);
        myAssembler.assemble(U1R, E1, -1.0);
      }
      else {
        myAssembler.assemble(E1, V1, 1.0);
        myAssembler.assemble(V1, E1, 1.0);
        myAssembler.assemble(E1, V1R, -1.0);
        myAssembler.assemble(V1R, E1, -1.0);
      }

      if(fabs(dot(g.crosses[0]->_tgt, dir1)) > .5) {
        //	printf("HAHAHA %d\n",g.groupId);
        myAssembler.assemble(E2, U2, 1.0);
        myAssembler.assemble(U2, E2, 1.0);
        myAssembler.assemble(E2, U2R, -1.0);
        myAssembler.assemble(U2R, E2, -1.0);
      }
      else {
        //	printf("HAHAHO %d\n",g.groupId);
        myAssembler.assemble(E2, V2, 1.0);
        myAssembler.assemble(V2, E2, 1.0);
        myAssembler.assemble(E2, V2R, -1.0);
        myAssembler.assemble(V2R, E2, -1.0);
      }
    }
  }
}

static void assembleLagrangeMultipliers(dofManager<double> &myAssembler,
                                        groupOfCross2d &g)
{
  Dof U1R(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
  Dof V1R(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));
  Dof U2R(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
  Dof V2R(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));

  //  if (g.groupId == 1){
  //    g.mat[0][0]=-1;
  //    g.mat[1][1]=-1;
  //  }

  //    printf("GROUP %d\n",g.groupId);
  //    printf("LEFT --- RIGHT\n");
  //    printf("%3lu %3lu\n",g.left[0]->getNum(),g.right[0]->getNum());

  if(g.singularities.size() == 1) {
    Dof E1(g.singularities[0]->getNum(), Dof::createTypeWithTwoInts(0, 33));
    Dof E2(g.singularities[0]->getNum(), Dof::createTypeWithTwoInts(0, 34));
    Dof U(g.singularities[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
    Dof V(g.singularities[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));

    myAssembler.assemble(E1, U, 1.0);
    myAssembler.assemble(E1, U1R, -1.0);

    myAssembler.assemble(E1, U, -g.mat[0][0]);
    myAssembler.assemble(E1, V, -g.mat[0][1]);
    myAssembler.assemble(E1, U2R, g.mat[0][0]);
    myAssembler.assemble(E1, V2R, g.mat[0][1]);

    myAssembler.assemble(E2, V, 1.0);
    myAssembler.assemble(E2, V1R, -1.0);

    myAssembler.assemble(E2, U, -g.mat[1][0]);
    myAssembler.assemble(E2, V, -g.mat[1][1]);
    myAssembler.assemble(E2, U2R, g.mat[1][0]);
    myAssembler.assemble(E2, V2R, g.mat[1][1]);

    // sym

    myAssembler.assemble(U, E1, 1.0);
    myAssembler.assemble(U1R, E1, -1.0);

    myAssembler.assemble(U, E1, -g.mat[0][0]);
    myAssembler.assemble(V, E1, -g.mat[0][1]);
    myAssembler.assemble(U2R, E1, g.mat[0][0]);
    myAssembler.assemble(V2R, E1, g.mat[0][1]);

    myAssembler.assemble(V, E2, 1.0);
    myAssembler.assemble(V1R, E2, -1.0);

    myAssembler.assemble(U, E2, -g.mat[1][0]);
    myAssembler.assemble(V, E2, -g.mat[1][1]);
    myAssembler.assemble(U2R, E2, g.mat[1][0]);
    myAssembler.assemble(V2R, E2, g.mat[1][1]);
  }

  // TEST NO JUMP ON U for group 3 ...
  if(g.groupId == ZERO_) {
    Dof E1(g.left[0]->getNum(),
           Dof::createTypeWithTwoInts(0, 3 + 10000 * g.groupId));
    Dof U1(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));
    Dof U2(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
  }

  for(size_t K = 1; K < g.left.size(); K++) {
    //     printf("%3lu %3lu\n",g.left[K]->getNum(),g.right[K]->getNum());
    // EQUATION IDS (Lagrange multipliers)
    Dof E1(g.left[K]->getNum(),
           Dof::createTypeWithTwoInts(0, 3 + 100 * g.groupId));
    Dof E2(g.left[K]->getNum(),
           Dof::createTypeWithTwoInts(0, 4 + 100 * g.groupId));

    // DOF IDS
    Dof U1(g.left[K]->getNum(), Dof::createTypeWithTwoInts(0, 1));
    Dof V1(g.left[K]->getNum(), Dof::createTypeWithTwoInts(0, 2));
    Dof U2(g.right[K]->getNum(), Dof::createTypeWithTwoInts(0, 1));
    Dof V2(g.right[K]->getNum(), Dof::createTypeWithTwoInts(0, 2));

    myAssembler.assemble(E1, U1, 1.0);
    myAssembler.assemble(E1, U1R, -1.0);

    myAssembler.assemble(E1, U2, -g.mat[0][0]);
    myAssembler.assemble(E1, V2, -g.mat[0][1]);
    myAssembler.assemble(E1, U2R, g.mat[0][0]);
    myAssembler.assemble(E1, V2R, g.mat[0][1]);

    myAssembler.assemble(E2, V1, 1.0);
    myAssembler.assemble(E2, V1R, -1.0);

    myAssembler.assemble(E2, U2, -g.mat[1][0]);
    myAssembler.assemble(E2, V2, -g.mat[1][1]);
    myAssembler.assemble(E2, U2R, g.mat[1][0]);
    myAssembler.assemble(E2, V2R, g.mat[1][1]);

    // sym

    myAssembler.assemble(U1, E1, 1.0);
    myAssembler.assemble(U1R, E1, -1.0);
    myAssembler.assemble(U2, E1, -g.mat[0][0]);
    myAssembler.assemble(V2, E1, -g.mat[0][1]);
    myAssembler.assemble(U2R, E1, g.mat[0][0]);
    myAssembler.assemble(V2R, E1, g.mat[0][1]);

    myAssembler.assemble(V1, E2, 1.0);
    myAssembler.assemble(V1R, E2, -1.0);
    myAssembler.assemble(U2, E2, -g.mat[1][0]);
    myAssembler.assemble(V2, E2, -g.mat[1][1]);
    myAssembler.assemble(U2R, E2, g.mat[1][0]);
    myAssembler.assemble(V2R, E2, g.mat[1][1]);
  }
}

static void
LagrangeMultipliers2(dofManager<double> &myAssembler, int NUMDOF,
                     std::map<MEdge, cross2d, MEdgeLessThan> &C,
                     std::vector<std::vector<cross2d *> > &groups,
                     std::map<MEdge, MEdge, MEdgeLessThan> &duplicateEdges,
                     bool assemble, std::map<MTriangle *, SVector3> &lift)
{
  for(size_t i = 0; i < groups.size(); i++) {
    size_t N = groups[i].size();
    MEdge ed = groups[i][0]->_e;
    auto ite = duplicateEdges.find(ed);
    if(ite != duplicateEdges.end()) ed = ite->second;
    MVertex *v = ed.getVertex(0);
    auto it = C.find(groups[i][0]->_e);
    SVector3 aaa = lift[it->second._t[0]];

    double S = fabs(dot(it->second._tgt, aaa));

    //    printf("DIR %d S = %12.5E\n",NUMDOF, S);

    if(S < .2 /*sqrt(2)/2.0*/) {
      for(size_t j = 0; j < N; j++) {
        ed = groups[i][j]->_e;
        ite = duplicateEdges.find(ed);
        if(ite != duplicateEdges.end()) ed = ite->second;
        for(int k = 0; k < 2; k++) {
          MVertex *vk = ed.getVertex(k);
          if(vk != v) {
            if(!assemble) { myAssembler.numberVertex(vk, 0, 5 + 100 * i); }
            else {
              Dof Eref(vk->getNum(),
                       Dof::createTypeWithTwoInts(0, 5 + 100 * i));
              Dof Uref(vk->getNum(), Dof::createTypeWithTwoInts(0, NUMDOF));
              Dof U(v->getNum(), Dof::createTypeWithTwoInts(0, NUMDOF));
              myAssembler.assemble(Eref, Uref, 1.0);
              myAssembler.assemble(Eref, U, -1.0);
              myAssembler.assemble(Uref, Eref, 1.0);
              myAssembler.assemble(U, Eref, -1.0);
            }
          }
        }
      }
    }
  }
}

struct cutGraphPassage {
  int _id;
  int _uv;
  SPoint3 _p;
  cutGraphPassage(int id, int uv, const SPoint3 &p) : _id(id), _uv(uv), _p(p) {}
};

static void createDofs(dofManager<double> &myAssembler, int NUMDOF,
                       std::set<MVertex *, MVertexPtrLessThan> &vs)
{
  for(auto it = vs.begin(); it != vs.end(); ++it)
    myAssembler.numberVertex(*it, 0, NUMDOF);
}

void createExtraConnexions(dofManager<double> &myAssembler,
                           std::vector<groupOfCross2d> &G,
                           std::vector<cutGraphPassage> &passages)
{
  return;
  // give a number to the equation ...
  myAssembler.numberVertex(G[0].left[0], 0, 10201020);
}

void assembleExtraConnexions(dofManager<double> &myAssembler,
                             std::vector<groupOfCross2d> &G,
                             std::vector<cutGraphPassage> &passages)
{
  int nConn = 2;
  int groups[2][2] = {{14, 1}, {13, 2}};

  if(G.size() < 2) {
    Msg::Debug("Less than 2 groupOfCross2d in assembleExtraConnexions");
    return;
  }

  Dof E(G[0].left[0]->getNum(), Dof::createTypeWithTwoInts(0, 10201020));

  for(int i = 0; i < nConn; i++) {
    groupOfCross2d &g = G[groups[i][0]];
    int index = groups[i][1];
    Dof U1(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, index));
    Dof U2(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
    Dof V2(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));
    myAssembler.assemble(E, U1, 1.0);
    myAssembler.assemble(E, U2, -g.mat[index - 1][0]);
    myAssembler.assemble(E, V2, -g.mat[index - 1][1]);
    myAssembler.assemble(U1, E, 1.0);
    myAssembler.assemble(U2, E, -g.mat[index - 1][0]);
    myAssembler.assemble(V2, E, -g.mat[index - 1][1]);
  }
}

static void computePotential(
  GModel *gm, std::vector<GFace *> &f, dofManager<double> &dof,
  std::map<MEdge, cross2d, MEdgeLessThan> &C,
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> &new2old,
  std::vector<std::vector<cross2d *> > &groups,
  std::map<MEdge, MEdge, MEdgeLessThan> &duplicateEdges,
  std::map<MTriangle *, SVector3> &lift, std::map<MTriangle *, SVector3> &lift2,
  std::vector<groupOfCross2d> &G, std::map<MVertex *, double> &res,
  std::map<MVertex *, double> &res2, std::vector<cutGraphPassage> &passages)
{
  double a[3];
  std::set<MVertex *, MVertexPtrLessThan> vs;
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      for(size_t k = 0; k < 3; k++) { vs.insert(t->getVertex(k)); }
    }
  }

#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  // linearSystemFull<double> *_lsys = new linearSystemFull<double>;
  linearSystemGmm<double> *_lsys = new linearSystemGmm<double>;
  ///  _lsys->setPrec(2.e-7);
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

  dofManager<double> myAssembler(_lsys);

  //  int NUMDOF = dir+1;

  createDofs(myAssembler, 1, vs);
  createDofs(myAssembler, 2, vs);
  LagrangeMultipliers2(myAssembler, 1, C, groups, duplicateEdges, false, lift);
  LagrangeMultipliers2(myAssembler, 2, C, groups, duplicateEdges, false, lift2);

  createExtraConnexions(myAssembler, G, passages);

  for(size_t i = 0; i < G.size(); i++) {
    createLagrangeMultipliers(myAssembler, G[i]);
    LagrangeMultipliers3(myAssembler, G[i], lift, false);
  }

  LagrangeMultipliers2(myAssembler, 1, C, groups, duplicateEdges, true, lift);
  LagrangeMultipliers2(myAssembler, 2, C, groups, duplicateEdges, true, lift2);
  for(size_t i = 0; i < G.size(); i++) {
    assembleLagrangeMultipliers(myAssembler, G[i]);
    LagrangeMultipliers3(myAssembler, G[i], lift, true);
  }

  assembleExtraConnexions(myAssembler, G, passages);

  simpleFunction<double> ONE(1.0);
  laplaceTerm l(nullptr, 1, &ONE);
  laplaceTerm l2(nullptr, 2, &ONE);

  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      SElement se(t);
      l.addToMatrix(myAssembler, &se);
      l2.addToMatrix(myAssembler, &se);
      SVector3 a0 = lift[t];
      SVector3 a1 = lift2[t];
      double va, vb, vc;
      auto itx = new2old.find(t->getVertex(0));
      dof.getDofValue(itx == new2old.end() ? t->getVertex(0) : itx->second, 0,
                      1, va);
      itx = new2old.find(t->getVertex(1));
      dof.getDofValue(itx == new2old.end() ? t->getVertex(1) : itx->second, 0,
                      1, vb);
      itx = new2old.find(t->getVertex(2));
      dof.getDofValue(itx == new2old.end() ? t->getVertex(2) : itx->second, 0,
                      1, vc);

      double F = (exp(va) + exp(vb) + exp(vc)) / 3.0;

      a0 *= F;
      a1 *= F;

      SPoint3 pp = t->barycenter();
      double G1[3] = {a0.x(), a0.y(), a0.z()};
      double G2[3] = {a0.x(), a0.y(), a0.z()};
      double G3[3] = {a0.x(), a0.y(), a0.z()};
      double G11[3] = {a1.x(), a1.y(), a1.z()};
      double G21[3] = {a1.x(), a1.y(), a1.z()};
      double G31[3] = {a1.x(), a1.y(), a1.z()};
      double g1[3];
      a[0] = 1;
      a[1] = 0;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g1);
      double RHS1 = g1[0] * G1[0] + g1[1] * G1[1] + g1[2] * G1[2];
      double RHS11 = g1[0] * G11[0] + g1[1] * G11[1] + g1[2] * G11[2];
      a[0] = 0;
      a[1] = 1;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g1);
      double RHS2 = g1[0] * G2[0] + g1[1] * G2[1] + g1[2] * G2[2];
      double RHS21 = g1[0] * G21[0] + g1[1] * G21[1] + g1[2] * G21[2];
      a[0] = 0;
      a[1] = 0;
      a[2] = 1;
      t->interpolateGrad(a, 0, 0, 0, g1);
      double RHS3 = g1[0] * G3[0] + g1[1] * G3[1] + g1[2] * G3[2];
      double RHS31 = g1[0] * G31[0] + g1[1] * G31[1] + g1[2] * G31[2];
      int num1 = myAssembler.getDofNumber(l.getLocalDofR(&se, 0));
      int num2 = myAssembler.getDofNumber(l.getLocalDofR(&se, 1));
      int num3 = myAssembler.getDofNumber(l.getLocalDofR(&se, 2));
      int num11 = myAssembler.getDofNumber(l2.getLocalDofR(&se, 0));
      int num21 = myAssembler.getDofNumber(l2.getLocalDofR(&se, 1));
      int num31 = myAssembler.getDofNumber(l2.getLocalDofR(&se, 2));

      double V = t->getVolume();
      _lsys->addToRightHandSide(num1, RHS1 * V);
      _lsys->addToRightHandSide(num2, RHS2 * V);
      _lsys->addToRightHandSide(num3, RHS3 * V);
      _lsys->addToRightHandSide(num11, RHS11 * V);
      _lsys->addToRightHandSide(num21, RHS21 * V);
      _lsys->addToRightHandSide(num31, RHS31 * V);
    }
  }
  double A = TimeOfDay();
  _lsys->systemSolve();
  double B = TimeOfDay();
  Msg::Info("Computing potentials (%d unknowns) in %3lf seconds",
            myAssembler.sizeOfR(), B - A);

  FILE *F = fopen("map.pos", "w");
  FILE *F2 = fopen("mapstr.pos", "w");
  fprintf(F, "View \"MAP\"{\n");
  fprintf(F2, "View \"MAPSTR\"{\n");
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      double a, b, c;
      double a1, b1, c1;
      myAssembler.getDofValue(t->getVertex(0), 0, 1, a);
      myAssembler.getDofValue(t->getVertex(1), 0, 1, b);
      myAssembler.getDofValue(t->getVertex(2), 0, 1, c);
      myAssembler.getDofValue(t->getVertex(0), 0, 2, a1);
      myAssembler.getDofValue(t->getVertex(1), 0, 2, b1);
      myAssembler.getDofValue(t->getVertex(2), 0, 2, c1);
      fprintf(F, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g};\n", a, a1,
              0., b, b1, 0., c, c1, 0., a, b, c, a1, b1, c1);
      fprintf(F2, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g};\n",
              .2 * a + t->getVertex(0)->x(), -.2 * a1 + t->getVertex(0)->y(),
              0., .2 * b + t->getVertex(1)->x(),
              -.2 * b1 + t->getVertex(1)->y(), 0.,
              .2 * c + t->getVertex(2)->x(), -.2 * c1 + t->getVertex(2)->y(),
              0., a, b, c, a1, b1, c1);

      res[t->getVertex(0)] = a;
      res[t->getVertex(1)] = b;
      res[t->getVertex(2)] = c;
      res2[t->getVertex(0)] = a1;
      res2[t->getVertex(1)] = b1;
      res2[t->getVertex(2)] = c1;
    }
  }
  fprintf(F, "};\n");
  fclose(F);
  fprintf(F2, "};\n");
  fclose(F2);
}

static double distance(MTriangle *t,
                       std::set<MVertex *, MVertexPtrLessThan> &boundaries)
{
  //  return drand48();
  SPoint3 p = t->barycenter();
  double dmin = 1.e22;
  for(auto it = boundaries.begin(); it != boundaries.end(); ++it) {
    SPoint3 pp((*it)->x(), (*it)->y(), (*it)->z());
    double d = p.distance(pp);
    if(d < dmin) { dmin = d; }
  }
  return -dmin;
}

struct temp_comp {
  cross2d *cr;
  double a;
  temp_comp(MVertex *v, cross2d *c, cross2d *ref, SVector3 &n) : cr(c)
  {
    MVertex *tref =
      ref->_e.getVertex(0) == v ? ref->_e.getVertex(1) : ref->_e.getVertex(0);
    MVertex *tc =
      c->_e.getVertex(0) == v ? c->_e.getVertex(1) : c->_e.getVertex(0);

    SVector3 t1(tref->x() - v->x(), tref->y() - v->y(), tref->z() - v->z());
    SVector3 t2(tc->x() - v->x(), tc->y() - v->y(), tc->z() - v->z());
    t1.normalize();
    t2.normalize();

    double cosTheta = dot(t1, t2);
    double sinTheta;
    SVector3 cc = crossprod(t1, t2);
    if(dot(cc, n) > 0)
      sinTheta = norm(crossprod(t1, t2));
    else
      sinTheta = -norm(crossprod(t1, t2));
    a = atan2(sinTheta, cosTheta);
  }
  bool operator<(const temp_comp &other) const { return a < other.a; }
};

static bool isSingular(MVertex *v, std::vector<cross2d *> &adj, double &MAX)
{
  const std::size_t TEST = 0;
  if(v->getNum() == TEST) printf("VERTEX %lu\n", v->getNum());
  SVector3 n(0, 0, 0);
  for(size_t i = 0; i < adj.size(); i++) {
    if(adj[i]->inBoundary || adj[i]->inInternalBoundary) return false;
    n += adj[i]->_nrml;
  }
  n.normalize();

  std::vector<temp_comp> cc;
  for(size_t i = 0; i < adj.size(); i++) {
    cc.push_back(temp_comp(v, adj[i], adj[0], n));
  }
  std::sort(cc.begin(), cc.end());
  SVector3 ref = cc[0].cr->_tgt * cos(cc[0].cr->_atemp) +
                 cc[0].cr->_tgt2 * sin(cc[0].cr->_atemp);
  SVector3 ref0 = ref;
  for(size_t i = 1; i < cc.size() + 1; i++) {
    cross2d &c2 = *(cc[i % cc.size()].cr);
    double P = M_PI / 2;
    SVector3 d1 = c2._tgt * cos(c2._atemp) + c2._tgt2 * sin(c2._atemp);
    SVector3 d2 = c2._tgt * cos(c2._atemp + P) + c2._tgt2 * sin(c2._atemp + P);
    SVector3 d3 =
      c2._tgt * cos(c2._atemp + 2 * P) + c2._tgt2 * sin(c2._atemp + 2 * P);
    SVector3 d4 =
      c2._tgt * cos(c2._atemp + 3 * P) + c2._tgt2 * sin(c2._atemp + 3 * P);
    double D1 = dot(ref, d1);
    double D2 = dot(ref, d2);
    double D3 = dot(ref, d3);
    double D4 = dot(ref, d4);
    if(D1 > D2 && D1 > D3 && D1 > D4)
      ref = d1;
    else if(D2 > D1 && D2 > D3 && D2 > D4)
      ref = d2;
    else if(D3 > D1 && D3 > D2 && D3 > D4)
      ref = d3;
    else
      ref = d4;
  }

  if(v->getNum() == TEST)
    printf("VERTEX %lu %12.5E %12.5E %12.5E\n", v->getNum(), n.x(), n.y(),
           n.z());
  SVector3 t0, b0;
  std::vector<double> angles;
  for(size_t i = 0; i < adj.size(); i++) {
    if(i == 0) {
      SVector3 t =
        (adj[i]->_e.getVertex(0) == v) ? -adj[i]->_tgt : adj[i]->_tgt;
      t -= n * (dot(t, n));
      t.normalize();
      SVector3 b = crossprod(n, t);
      b0 = b;
      t0 = t;
    }

    SVector3 repr = adj[i]->o_i - n * dot(adj[i]->o_i, n);
    repr.normalize();
    // t * dot (,adj[i]->_tgt) +
    //      b * dot (adj[i]->o_i,adj[i]->_tgt2) ;
    double angle = atan2(dot(repr, t0), dot(repr, b0));
    adj[i]->normalize(angle);
    angles.push_back(angle);
    if(v->getNum() == TEST) {
      printf("EDGE %lu %lu\n", adj[i]->_e.getVertex(0)->getNum(),
             adj[i]->_e.getVertex(1)->getNum());
      printf("o %12.5E %12.5E %12.5E\n", adj[i]->o_i.x(), adj[i]->o_i.y(),
             adj[i]->o_i.z());
      printf("ANGLE = %12.5E %12.5E\n", angle * 180 / M_PI,
             lifting(angles[0], angles[i]) * 180 / M_PI);
    }
  }

  MAX = 0;
  for(size_t i = 0; i < angles.size(); i++) {
    if(v->getNum() == TEST) printf("%12.5E ", angles[i]);
    for(size_t j = 0; j < i; j++) {
      MAX = std::max(MAX, fabs(angles[i] - lifting(angles[j], angles[i])));
    }
  }
  if(v->getNum() == TEST) printf("\n");
  if(v->getNum() == TEST)
    printf("vertex %lu %lu edges %12.5E\n", v->getNum(), adj.size(), MAX);
  //  if (MAX > .5)printf("vertex %lu %lu edges %12.5E -- new method %12.5E\n",
  //  v->getNum(), adj.size(), MAX,dot(ref,ref0));
  return MAX > .5;
}

void isMinMax(MVertex *v, std::vector<cross2d *> adj, dofManager<double> *dof,
              bool &isMin, bool &isMax)
{
  double aa;
  isMin = isMax = true;
  dof->getDofValue(v, 0, 1, aa);
  for(size_t i = 0; i < adj.size(); i++) {
    double a;
    dof->getDofValue(adj[i]->_e.getVertex(0) == v ? adj[i]->_e.getVertex(1) :
                                                    adj[i]->_e.getVertex(0),
                     0, 1, a);
    if(a < aa) isMin = false;
    if(a > aa) isMax = false;
  }
}

static void
computeSingularities(std::map<MEdge, cross2d, MEdgeLessThan> &C,
                     std::set<MVertex *, MVertexPtrLessThan> &singularities,
                     std::map<MVertex *, int> &indices, dofManager<double> *dof)
{
  FILE *f_ = fopen("sing.pos", "w");
  fprintf(f_, "View \"S\"{\n");
  std::multimap<MVertex *, cross2d *, MVertexPtrLessThan> conn;
  for(auto it = C.begin(); it != C.end(); ++it) {
    std::pair<MVertex *, cross2d *> p =
      std::make_pair(it->first.getVertex(0), &it->second);
    conn.insert(p);
    p = std::make_pair(it->first.getVertex(1), &it->second);
    conn.insert(p);
  }
  MVertex *v = nullptr;
  std::vector<cross2d *> adj;
  for(auto it = conn.begin(); it != conn.end(); ++it) {
    if(it->first == v) { adj.push_back(it->second); }
    else {
      double MAX;
      if(v && isSingular(v, adj, MAX)) {
        singularities.insert(v);
        bool isMin, isMax;
        isMinMax(v, adj, dof, isMin, isMax);
        if(isMax)
          indices[v] = 1;
        else if(isMin)
          indices[v] = -1;
        else
          printf("ERROR -- \n");
        fprintf(f_, "SP(%g,%g,%g){%d};\n", v->x(), v->y(), v->z(), indices[v]);
      }
      adj.clear();
      v = it->first;
      adj.push_back(it->second);
    }
  }
  fprintf(f_, "};\n");
  fclose(f_);
}

static void cutGraph(std::map<MEdge, cross2d, MEdgeLessThan> &C,
                     std::set<MEdge, MEdgeLessThan> &cutG,
                     std::set<MVertex *, MVertexPtrLessThan> &singularities,
                     std::set<MVertex *, MVertexPtrLessThan> &boundaries)
{
  std::set<MTriangle *, MElementPtrLessThan> touched;
  std::vector<cross2d *> tree;
  std::vector<MEdge> cotree;
  std::set<std::pair<double, MTriangle *> > _distances;
  {
    auto it = C.begin();
    for(; it != C.end(); ++it) {
      if(it->second._t.size() == 1) {
        boundaries.insert(it->first.getVertex(0));
        boundaries.insert(it->first.getVertex(1));
      }
    }
  }
  std::set<MVertex *, MVertexPtrLessThan> _all = boundaries;
  _all.insert(singularities.begin(), singularities.end());

  FILE *fff2 = fopen("tree.pos", "w");
  fprintf(fff2, "View \"sides\"{\n");

  MTriangle *t = (C.begin())->second._t[0];
  std::pair<double, MTriangle *> pp = std::make_pair(distance(t, _all), t);
  _distances.insert(pp);
  touched.insert(t);
  while(!_distances.empty()) {
    t = (_distances.begin()->second);
    _distances.erase(_distances.begin());

    for(int i = 0; i < 3; i++) {
      MEdge e = t->getEdge(i);
      auto it = C.find(e);
      for(size_t j = 0; j < it->second._t.size(); j++) {
        MTriangle *tt = it->second._t[j];
        if(touched.find(tt) == touched.end()) {
          std::pair<double, MTriangle *> pp =
            std::make_pair(distance(t, _all), tt);
          _distances.insert(pp);
          touched.insert(tt);
          tree.push_back(&it->second);
        }
      }
    }
  }

  std::sort(tree.begin(), tree.end());
  auto it = C.begin();
  std::map<MVertex *, std::vector<MEdge>, MVertexPtrLessThan> _graph;
  for(; it != C.end(); ++it) {
    if(!std::binary_search(tree.begin(), tree.end(), &it->second)) {
      for(int i = 0; i < 2; i++) {
        auto it0 = _graph.find(it->first.getVertex(i));
        if(it0 == _graph.end()) {
          std::vector<MEdge> ee;
          ee.push_back(it->first);
          _graph[it->first.getVertex(i)] = ee;
        }
        else
          it0->second.push_back(it->first);
      }
      cotree.push_back(it->first);
      fprintf(fff2, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n",
              it->first.getVertex(0)->x(), it->first.getVertex(0)->y(),
              it->first.getVertex(0)->z(), it->first.getVertex(1)->x(),
              it->first.getVertex(1)->y(), it->first.getVertex(1)->z(), 1, 1);
    }
  }

  fprintf(fff2, "};\n");
  fclose(fff2);

  //  {
  //    for(auto it = boundaries.begin(); it != boundaries.end(); ++it) {
  //      auto it2 = singularities.find(*it); if(it2 != singularities.end())
  //      singularities.erase(it2);
  //    }
  //  }

  while(1) {
    bool somethingDone = false;
    auto it = _graph.begin();
    for(; it != _graph.end(); ++it) {
      if(it->second.size() == 1) {
        MVertex *v1 = it->second[0].getVertex(0);
        MVertex *v2 = it->second[0].getVertex(1);
        if(boundaries.find(it->first) == boundaries.end() &&
           singularities.find(it->first) == singularities.end()) {
          somethingDone = true;
          auto it2 = _graph.find(v1 == it->first ? v2 : v1);
          auto position =
            std::find(it2->second.begin(), it2->second.end(), it->second[0]);
          it2->second.erase(position);
          it->second.clear();
        }
      }
    }
    if(!somethingDone) break;
  }

  FILE *fff = fopen("cotree.pos", "w");
  fprintf(fff, "View \"sides\"{\n");
  {
    auto it = _graph.begin();
    for(; it != _graph.end(); ++it) {
      for(size_t i = 0; i < it->second.size(); i++) {
        MEdge e = it->second[i];
        if(boundaries.find(e.getVertex(0)) == boundaries.end() ||
           boundaries.find(e.getVertex(1)) == boundaries.end()) {
          cutG.insert(e);
        }
      }
    }
  }

  // Add internal boundaries to the cut graph
  {
    auto it = C.begin();
    for(; it != C.end(); ++it) {
      if(it->second._t.size() > 1 && it->second.inInternalBoundary) {
        cutG.insert(it->second._e);
      }
    }
  }

  {
    auto it = cutG.begin();
    for(; it != cutG.end(); ++it) {
      MEdge e = *it;
      fprintf(fff, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", e.getVertex(0)->x(),
              e.getVertex(0)->y(), e.getVertex(0)->z(), e.getVertex(1)->x(),
              e.getVertex(1)->y(), e.getVertex(1)->z(), 1, 1);
    }
  }
  fprintf(fff, "};\n");
  fclose(fff);
}

int analyzeCorner(std::multimap<MVertex *, cross2d *> &conn, MVertex *v)
{
  // compute if this is an external (1) or internal (-1) corner.
  return 1;
}

static void
groupBoundaries(GModel *gm, std::map<MEdge, cross2d, MEdgeLessThan> &C,
                std::vector<std::vector<cross2d *> > &groups,
                std::set<MVertex *, MVertexPtrLessThan> singularities,
                std::set<MVertex *, MVertexPtrLessThan> &corners,
                bool cutGraph = false)
{
  std::set<MVertex *, MVertexPtrLessThan> cutgraph;
  std::set<MVertex *, MVertexPtrLessThan> boundaries;
  for(auto it = C.begin(); it != C.end(); ++it) {
    MVertex *v0 = it->first.getVertex(0);
    MVertex *v1 = it->first.getVertex(1);
    if(it->second.inBoundary) {
      boundaries.insert(v0);
      boundaries.insert(v1);
    }
    else if(it->second.inCutGraph) {
      cutgraph.insert(v0);
      cutgraph.insert(v1);
    }
  }

  std::set<cross2d *> _all;

  std::multimap<MVertex *, cross2d *> conn;
  for(auto it = C.begin(); it != C.end(); ++it) {
    std::pair<MVertex *, cross2d *> p =
      std::make_pair(it->first.getVertex(0), &it->second);
    conn.insert(p);
    p = std::make_pair(it->first.getVertex(1), &it->second);
    conn.insert(p);
  }

  for(auto it = boundaries.begin(); it != boundaries.end(); ++it) {
    MVertex *v = *it;
    std::vector<cross2d *> bnd;
    int countCutGraph = 0;
    for(auto it2 = conn.lower_bound(v); it2 != conn.upper_bound(v); ++it2) {
      if(it2->second->inBoundary) { bnd.push_back(it2->second); }
      if(it2->second->inCutGraph) { countCutGraph++; }
    }
    if(bnd.size() == 2) {
      if(fabs(dot(bnd[0]->o_i, bnd[1]->o_i)) < .25) {
        corners.insert(v);
        cutgraph.insert(v);
      }
      if(countCutGraph == 1) { singularities.insert(v); }
    }
    if(bnd.size() > 2) { cutgraph.insert(v); }
  }

  std::string ss = gm->getName();
  std::string fn = cutGraph ? ss + "_groups_cg.pos" : ss + "_groups_bnd.pos";

  FILE *f = fopen(fn.c_str(), "w");

  fprintf(f, "View \" \"{\n");

  std::set<MVertex *, MVertexPtrLessThan> endPoints = singularities;
  {
    for(auto it = conn.begin(); it != conn.end(); ++it) {
      int count = 0;
      for(auto it2 = conn.lower_bound(it->first);
          it2 != conn.upper_bound(it->first); ++it2) {
        if(it2->second->inCutGraph) { count++; }
      }
      if(count > 2) endPoints.insert(it->first);
    }
  }

  for(int AA = 0; AA < 4; AA++) {
    if(cutGraph) {
      for(auto it = endPoints.begin(); it != endPoints.end(); ++it) {
        MVertex *v = *it;
        std::vector<cross2d *> group;
        do {
          MVertex *vnew = nullptr;
          for(auto it2 = conn.lower_bound(v); it2 != conn.upper_bound(v);
              ++it2) {
            if((_all.find(it2->second) == _all.end()) &&
               (group.empty() || group[group.size() - 1] != it2->second) &&
               it2->second->inCutGraph) {
              group.push_back(it2->second);
              vnew = (it2->second->_e.getVertex(0) == v) ?
                       it2->second->_e.getVertex(1) :
                       it2->second->_e.getVertex(0);
              fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%lu,%lu};\n",
                      it2->second->_e.getVertex(0)->x(),
                      it2->second->_e.getVertex(0)->y(),
                      it2->second->_e.getVertex(0)->z(),
                      it2->second->_e.getVertex(1)->x(),
                      it2->second->_e.getVertex(1)->y(),
                      it2->second->_e.getVertex(1)->z(), groups.size(),
                      groups.size());
              break;
            }
          }
          if(vnew == nullptr) break;
          v = vnew;
        } while((boundaries.find(v) == boundaries.end()) &&
                (endPoints.find(v) == endPoints.end()));
        if(group.size()) {
          groups.push_back(group);
          _all.insert(group.begin(), group.end());
        }
      }
    }
    else {
      for(auto it = boundaries.begin(); it != boundaries.end(); ++it) {
        MVertex *v = *it;
        if(cutgraph.find(v) != cutgraph.end() ||
           singularities.find(v) != singularities.end()) {
          //	  printf("START POINT %lu %d %d\n",v->getNum(),cutgraph.find(v)
          //!= cutgraph.end() , 		  singularities.find(v) !=
          //! singularities.end());
          std::vector<cross2d *> group;
          do {
            MVertex *vnew = nullptr;
            for(auto it2 = conn.lower_bound(v); it2 != conn.upper_bound(v);
                ++it2) {
              if((_all.find(it2->second) == _all.end()) &&
                 (group.empty() || group[group.size() - 1] != it2->second) &&
                 (it2->second->inBoundary)) {
                group.push_back(it2->second);
                vnew = (it2->second->_e.getVertex(0) == v) ?
                         it2->second->_e.getVertex(1) :
                         it2->second->_e.getVertex(0);
                //		printf("EDGE %lu %lu (%d)\n",
                //		       it2->second->_e.getVertex(0)->getNum(),it2->second->_e.getVertex(1)->getNum(),
                //		       singularities.find(v) == singularities.end());
                //	    printf("v %lu EDGE %lu
                //%lu\n",v->getNum(),it2->second->_e.getVertex(0)->getNum(),it2->second->_e.getVertex(1)->getNum());
                fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%lu,%lu};\n",
                        it2->second->_e.getVertex(0)->x(),
                        it2->second->_e.getVertex(0)->y(),
                        it2->second->_e.getVertex(0)->z(),
                        it2->second->_e.getVertex(1)->x(),
                        it2->second->_e.getVertex(1)->y(),
                        it2->second->_e.getVertex(1)->z(), groups.size(),
                        groups.size());
                break;
              }
            }
            if(vnew == nullptr) break;
            v = vnew;
            //	    printf("NEXT POINT %lu %d
            //%lu\n",v->getNum(),singularities.find(v) == singularities.end(),
            //		   singularities.size());
          } while(cutgraph.find(v) == cutgraph.end() &&
                  singularities.find(v) == singularities.end());
          if(group.size() && _all.find(group[0]) == _all.end()) {
            groups.push_back(group);
            _all.insert(group.begin(), group.end());
          }
        }
      }
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

static void
fastImplementationExtrinsic(std::map<MEdge, cross2d, MEdgeLessThan> &C,
                            double tol = 1.e-10)
{
  double *data = new double[C.size() * 6];
  size_t *graph = new size_t[C.size() * 4];
  auto it = C.begin();
  int counter = 0;

  for(; it != C.end(); ++it) {
    data[6 * counter + 0] = it->second.o_i.x();
    data[6 * counter + 1] = it->second.o_i.y();
    data[6 * counter + 2] = it->second.o_i.z();
    data[6 * counter + 3] = it->second._nrml.x();
    data[6 * counter + 4] = it->second._nrml.y();
    data[6 * counter + 5] = it->second._nrml.z();
    it->second.counter = counter;
    ++counter;
  }

  it = C.begin();
  counter = 0;
  for(; it != C.end(); ++it) {
    graph[4 * counter + 0] = graph[4 * counter + 1] = graph[4 * counter + 2] =
      graph[4 * counter + 3] = it->second.counter;
    for(size_t i = 0; i < it->second._cneighbors.size(); i++) {
      graph[4 * counter + i] = it->second._cneighbors[i]->counter;
    }
    if(it->second.inBoundary || it->second.inInternalBoundary) {
      graph[4 * counter + 2] = graph[4 * counter + 3] = it->second.counter;
    }

    counter++;
  }

  size_t N = C.size();
  int MAXITER = 10000;
  int ITER = -1;
  while(ITER++ < MAXITER) {
    double x[3], y[3];
    double RES = 0;
    for(size_t i = 0; i < N; i++) {
      double *r = &data[6 * i + 0];
      double *n = &data[6 * i + 3];
      SVector3 ro(r[0], r[1], r[2]);
      size_t *neigh = &graph[4 * i];
      double weight = 0;
      if(neigh[2] != neigh[3]) {
        for(int j = 0; j < 4; j++) {
          size_t k = neigh[j];
          const double *r2 = &data[6 * k + 0];
          const double *n2 = &data[6 * k + 3];
          compat_orientation_extrinsic(r, n, r2, n2, x, y);
          r[0] = x[0] * weight + y[0];
          r[1] = x[1] * weight + y[1];
          r[2] = x[2] * weight + y[2];
          const double dd = r[0] * n[0] + r[1] * n[1] + r[2] * n[2];
          r[0] -= n[0] * dd;
          r[1] -= n[1] * dd;
          r[2] -= n[2] * dd;
          double NRM = sqrt(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);
          if(NRM != 0.0) {
            r[0] /= NRM;
            r[1] /= NRM;
            r[2] /= NRM;
          }
          weight += 1;
        }
        double dp = r[0] * ro[0] + r[1] * ro[1] + r[2] * ro[2];
        RES += std::min(1. - fabs(dp), fabs(dp));
      }
      //      data[6*i+0]=r[0];
      //      data[6*i+1]=r[1];
      //      data[6*i+2]=r[2];
    }
    if(ITER % 1000 == 0)
      Msg::Info("NL smooth : iter %6d RES = %12.5E", ITER, RES);
    if(RES < tol) break;
  }

  it = C.begin();
  for(; it != C.end(); ++it) {
    counter = it->second.counter;
    it->second.o_i[0] = data[6 * counter + 0];
    it->second.o_i[1] = data[6 * counter + 1];
    it->second.o_i[2] = data[6 * counter + 2];
  }
  delete[] data;
  delete[] graph;
}

static dofManager<double> *computeH(GModel *gm, std::vector<GFace *> &f,
                                    std::set<MVertex *, MVertexPtrLessThan> &vs,
                                    std::map<MEdge, cross2d, MEdgeLessThan> &C)
{
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  // MUMPS !!!
  linearSystemGmm<double> *_lsys = new linearSystemGmm<double>;
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

  dofManager<double> *myAssembler = new dofManager<double>(_lsys);

  //  myAssembler.fixVertex(*vs.begin(), 0, 1, 0);
  for(auto it = vs.begin(); it != vs.end(); ++it)
    myAssembler->numberVertex(*it, 0, 1);

  std::string ss = gm->getName();
  std::string fn = ss + "_grad.pos";

  FILE *_f = fopen(fn.c_str(), "w");
  fprintf(_f, "View \"grad\"{\n");

  simpleFunction<double> ONE(1.0);
  laplaceTerm l(nullptr, 1, &ONE);

  std::map<MTriangle *, SVector3> gradients_of_theta;

  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];

      SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
                   t->getVertex(1)->y() - t->getVertex(0)->y(),
                   t->getVertex(1)->z() - t->getVertex(0)->z());
      SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
                   t->getVertex(2)->y() - t->getVertex(0)->y(),
                   t->getVertex(2)->z() - t->getVertex(0)->z());
      SVector3 xx = crossprod(v20, v10);
      xx.normalize();

      SElement se(t);
      l.addToMatrix(*myAssembler, &se);
      MEdge e0 = t->getEdge(0);
      MEdge e1 = t->getEdge(1);
      MEdge e2 = t->getEdge(2);
      auto it0 = C.find(e0);
      auto it1 = C.find(e1);
      auto it2 = C.find(e2);

      //      printf("%g %ag %g\n",a0,a1,a2);

      double a0 = it0->second._a;
      double A1 =
        it1->second._a + atan2(dot(it0->second._tgt2, it1->second._tgt),
                               dot(it0->second._tgt, it1->second._tgt));
      it0->second.normalize(A1);
      double a1 = it0->second.lifting(A1);
      double A2 =
        it2->second._a + atan2(dot(it0->second._tgt2, it2->second._tgt),
                               dot(it0->second._tgt, it2->second._tgt));
      it0->second.normalize(A2);
      double a2 = it0->second.lifting(A2);

      SVector3 x0, x1, x2, x3;
      SVector3 t_i = crossprod(xx, it0->second._tgt);
      t_i -= xx * dot(xx, t_i);
      t_i.normalize();
      SVector3 o_i = it0->second.o_i;
      o_i -= xx * dot(xx, o_i);
      o_i.normalize();
      SVector3 o_1 = it1->second.o_i;
      o_1 -= xx * dot(xx, o_1);
      o_1.normalize();
      SVector3 o_2 = it2->second.o_i;
      o_2 -= xx * dot(xx, o_2);
      o_2.normalize();
      compat_orientation_extrinsic(o_i, xx, o_1, xx, x0, x1);
      compat_orientation_extrinsic(o_i, xx, o_2, xx, x2, x3);

      //      compat_orientation_extrinsic
      //      (it0->second.o_i,it0->second._nrml,it1->second.o_i,it1->second._nrml,x0,x1);
      //      compat_orientation_extrinsic
      //      (it0->second.o_i,it0->second._nrml,it2->second.o_i,it2->second._nrml,x2,x3);
      //      a0 = atan2(dot(it0->second._tgt2,it0->second.o_i),
      //		 dot(it0->second._tgt,it0->second.o_i));
      a0 = atan2(dot(t_i, o_i), dot(it0->second._tgt, o_i));

      x0 -= xx * dot(xx, x0);
      x0.normalize();
      x1 -= xx * dot(xx, x1);
      x1.normalize();
      x2 -= xx * dot(xx, x2);
      x2.normalize();
      x3 -= xx * dot(xx, x3);
      x3.normalize();

      it0->second.normalize(a0);
      it0->second._a = a0;
      //      A1 = atan2(dot(it0->second._tgt2,x1),
      //		 dot(it0->second._tgt,x1));
      //      A2 = atan2(dot(it0->second._tgt2,x3),
      //		 dot(it0->second._tgt,x3));
      A1 = atan2(dot(t_i, x1), dot(it0->second._tgt, x1));
      A2 = atan2(dot(t_i, x3), dot(it0->second._tgt, x3));
      it0->second.normalize(A1);
      a1 = it0->second.lifting(A1);
      it0->second.normalize(A2);
      a2 = it0->second.lifting(A2);
      //      it0->second.normalize(a1);
      //      it0->second.normalize(a2);
      //      it0->second._a = a0 = 0;
      //      a1 = it0->second.lifting(A1);
      //      a2 = it0->second.lifting(A2);

      double a[3] = {a0 + a2 - a1, a0 + a1 - a2, a1 + a2 - a0};
      double g[3] = {0, 0, 0};
      t->interpolateGrad(a, 0, 0, 0, g);
      gradients_of_theta[t] = SVector3(g[0], g[1], g[2]);
      SPoint3 pp = t->barycenter();

      //      fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",pp.x(),pp.y(),pp.z(),
      //	      x0.x(),x0.y(),x0.z());
      //      fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",pp.x(),pp.y(),pp.z(),
      //	      x1.x(),x1.y(),x1.z());
      //      fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",pp.x(),pp.y(),pp.z(),
      //	      x2.x(),x2.y(),x2.z());
      //      fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",pp.x(),pp.y(),pp.z(),
      //	      x3.x(),x3.y(),x3.z());

      fprintf(_f, "VP(%g,%g,%g){%g,%g,%g};\n", pp.x(), pp.y(), pp.z(), g[0],
              g[1], g[2]);
      //      fprintf(_f, "VP(%g,%g,%g){%g,%g,%g};\n", pp.x(), pp.y(), pp.z(),
      //      -g[1],
      //	      g[0], g[2]);
      //      printf("A %g vs %g\n",sqrt(
      //      g[1]*g[1]+g[0]*g[0]), 1./(sqrt((pp.x())*(pp.x())+(pp.y())*(pp.y()))));

      SVector3 G(g[0], g[1], g[2]);
      SVector3 GT = crossprod(G, xx);

      double g1[3];
      a[0] = 1;
      a[1] = 0;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g1);
      double RHS1 = g1[0] * GT.x() + g1[1] * GT.y() + g1[2] * GT.z();
      // double RHS1 = g1[0]*g[0]+g1[1]*g[1]+g1[2]*g[2];
      a[0] = 0;
      a[1] = 1;
      a[2] = 0;
      t->interpolateGrad(a, 0, 0, 0, g1);
      double RHS2 = g1[0] * GT.x() + g1[1] * GT.y() + g1[2] * GT.z();
      // double RHS2 = g1[0]*g[0]+g1[1]*g[1]+g1[2]*g[2];
      a[0] = 0;
      a[1] = 0;
      a[2] = 1;
      t->interpolateGrad(a, 0, 0, 0, g1);
      double RHS3 = g1[0] * GT.x() + g1[1] * GT.y() + g1[2] * GT.z();
      // double RHS3 = g1[0]*g[0]+g1[1]*g[1]+g1[2]*g[2];
      int num1 = myAssembler->getDofNumber(l.getLocalDofR(&se, 0));
      int num2 = myAssembler->getDofNumber(l.getLocalDofR(&se, 1));
      int num3 = myAssembler->getDofNumber(l.getLocalDofR(&se, 2));
      double V = -t->getVolume();
      _lsys->addToRightHandSide(num1, RHS1 * V);
      _lsys->addToRightHandSide(num2, RHS2 * V);
      _lsys->addToRightHandSide(num3, RHS3 * V);
    }
  }
  fprintf(_f, "};\n");
  fclose(_f);
  _lsys->systemSolve();

  return myAssembler;
}

/*
  1) find u_i and v_i of all singularities
  2) compute [MAX,MIN] max of u's and v's
  3) Divide this interval into

*/

static double coord1d(double a0, double a1, double a)
{
  if(a1 == a0) return 0.0;
  return (a - a0) / (a1 - a0);
}

struct edgeCuts {
  std::vector<SPoint3> ps;
  std::vector<MVertex *> vs;
  std::vector<int> indexOfCuts;
  std::vector<int> idsOfCuts;
  bool add(const SPoint3 &p, int ind, int id)
  {
    for(size_t i = 0; i < ps.size(); i++) {
      SVector3 v(ps[i], p);
      if(v.norm() < 1.e-10) { return false; }
    }
    ps.push_back(p);
    indexOfCuts.push_back(ind);
    idsOfCuts.push_back(id);
    return true;
  }
  void finish(GModel *gm, FILE *f = nullptr)
  {
    for(size_t i = 0; i < ps.size(); i++) {
      GEdge *ge = gm->getEdgeByTag(indexOfCuts[i]);
      if(!ge) {
        ge = new discreteEdge(gm, indexOfCuts[i]);
        gm->add(ge);
      }
      MEdgeVertex *v =
        new MEdgeVertex(ps[i].x(), ps[i].y(), ps[i].z(), ge, 0.0);
      if(f)
        fprintf(f, "SP(%g,%g,%g){%d};\n", ps[i].x(), ps[i].y(), ps[i].z(),
                ge->tag());
      vs.push_back(v);
      ge->mesh_vertices.push_back(v);
    }
  }
  edgeCuts() {}
};

static bool addCut(const SPoint3 &p, const MEdge &e, int COUNT, int ID,
                   std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts)
{
  auto itc = cuts.find(e);
  if(itc != cuts.end()) {
    if(!itc->second.add(p, COUNT, ID)) return false;
    return true;
  }
  else {
    edgeCuts cc;
    if(!cc.add(p, COUNT, ID)) return false;
    cuts[e] = cc;
    return true;
  }
}

static void computeOneIsoRecur(
  MVertex *vsing, v2t_cont &adj, double VAL, MVertex *v0, MVertex *v1,
  SPoint3 &p, std::map<MVertex *, double> &pot,
  std::map<MEdge, int, MEdgeLessThan> &visited,
  std::map<MEdge, std::pair<std::map<MVertex *, double> *, double>,
           MEdgeLessThan> &cutGraphEnds,
  std::map<MEdge, MEdge, MEdgeLessThan> &d1, std::vector<groupOfCross2d> &G,
  FILE *f, int COUNT, std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts, int &NB,
  int &circular)
{
  MEdge e(v0, v1);

  MVertex vvv(p.x(), p.y(), p.z());

  if(distance(&vvv, vsing) < 1.e-10) {
    circular++;
    return;
  }

  bool added = addCut(p, e, COUNT, NB, cuts);
  if(!added) return;

  NB++;

  //  visited[e] = NB;

  if(d1.find(e) != d1.end()) {
    std::pair<std::map<MVertex *, double> *, double> aa =
      std::make_pair(&pot, VAL);
    std::pair<MEdge, std::pair<std::map<MVertex *, double> *, double> > p =
      std::make_pair(e, aa);
    cutGraphEnds.insert(p);
  }
  std::vector<MElement *> lst = adj[v0];

  MVertex *vs[2] = {nullptr, nullptr};
  int count = 0;
  for(size_t i = 0; i < lst.size(); i++) {
    if((lst[i]->getVertex(0) == v0 && lst[i]->getVertex(1) == v1) ||
       (lst[i]->getVertex(0) == v1 && lst[i]->getVertex(1) == v0)) {
      vs[count++] = lst[i]->getVertex(2);
    }
    if((lst[i]->getVertex(0) == v0 && lst[i]->getVertex(2) == v1) ||
       (lst[i]->getVertex(0) == v1 && lst[i]->getVertex(2) == v0)) {
      vs[count++] = lst[i]->getVertex(1);
    }
    if((lst[i]->getVertex(1) == v0 && lst[i]->getVertex(2) == v1) ||
       (lst[i]->getVertex(1) == v1 && lst[i]->getVertex(2) == v0)) {
      vs[count++] = lst[i]->getVertex(0);
    }
  }

  double U[2] = {pot[v0], pot[v1]};
  SPoint3 p0(v0->x(), v0->y(), v0->z());
  SPoint3 p1(v1->x(), v1->y(), v1->z());
  for(int i = 0; i < 2; i++) {
    if(vs[i]) {
      double U2 = pot[vs[i]];
      SPoint3 ppp(vs[i]->x(), vs[i]->y(), vs[i]->z());
      if((U[0] - VAL) * (U2 - VAL) <= 0) {
        double xi = coord1d(U[0], U2, VAL);
        SPoint3 pp = p0 * (1. - xi) + ppp * xi;
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", p.x(), p.y(), p.z(),
                pp.x(), pp.y(), pp.z(), COUNT, COUNT);
        computeOneIsoRecur(vsing, adj, VAL, v0, vs[i], pp, pot, visited,
                           cutGraphEnds, d1, G, f, COUNT, cuts, NB, circular);
      }
      else if((U[1] - VAL) * (U2 - VAL) <= 0) {
        double xi = coord1d(U[1], U2, VAL);
        SPoint3 pp = p1 * (1. - xi) + ppp * xi;
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", p.x(), p.y(), p.z(),
                pp.x(), pp.y(), pp.z(), COUNT, COUNT);
        computeOneIsoRecur(vsing, adj, VAL, v1, vs[i], pp, pot, visited,
                           cutGraphEnds, d1, G, f, COUNT, cuts, NB, circular);
      }
      else {
        printf("strange\n");
      }
    }
  }
  return;
}

static int computeOneIso(MVertex *vsing, v2t_cont &adj, double VAL, MVertex *v0,
                         MVertex *v1, SPoint3 &p,
                         std::map<MVertex *, double> *potU,
                         std::map<MVertex *, double> *potV,
                         std::map<MEdge, MEdge, MEdgeLessThan> &d1,
                         std::vector<groupOfCross2d> &G, FILE *f, int COUNT,
                         std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts,
                         std::vector<cutGraphPassage> &passages)
{
  std::map<MEdge, int, MEdgeLessThan> visited;
  std::map<MEdge, std::pair<std::map<MVertex *, double> *, double>,
           MEdgeLessThan>
    cutGraphEnds;
  int NB = 0;
  int circular = 0;

  computeOneIsoRecur(vsing, adj, VAL, v0, v1, p, *potU, visited, cutGraphEnds,
                     d1, G, f, COUNT, cuts, NB, circular);

  int XX = 1;
  passages.clear();
  while(!cutGraphEnds.empty()) {
    MEdge e = (*cutGraphEnds.begin()).first;
    std::map<MVertex *, double> *POT = (*cutGraphEnds.begin()).second.first;
    VAL = (*cutGraphEnds.begin()).second.second;
    double xi = coord1d((*POT)[e.getVertex(0)], (*POT)[e.getVertex(1)], VAL);
    MEdge o = d1[e];
    p[0] = (1. - xi) * e.getVertex(0)->x() + xi * e.getVertex(1)->x();
    p[1] = (1. - xi) * e.getVertex(0)->y() + xi * e.getVertex(1)->y();
    p[2] = (1. - xi) * e.getVertex(0)->z() + xi * e.getVertex(1)->z();
    //    printf("cutgaphends %lu
    //    %lu\n",o.getVertex(0)->getNum(),o.getVertex(1)->getNum()); printf("%lu
    //    ends to the cutgraph\n",cutGraphEnds.size());
    cutGraphEnds.erase(cutGraphEnds.begin());
    // visited.clear();

    int ROT = 0;
    int maxCount = 0;
    int cutGraphId = -1;
    for(size_t i = 0; i < G.size(); i++) {
      int count = 0;
      count += (std::find(G[i].left.begin(), G[i].left.end(), o.getVertex(0)) !=
                    G[i].left.end() ?
                  1 :
                  0);
      count += (std::find(G[i].left.begin(), G[i].left.end(), o.getVertex(1)) !=
                    G[i].left.end() ?
                  1 :
                  0);
      count += (std::find(G[i].right.begin(), G[i].right.end(),
                          e.getVertex(0)) != G[i].right.end() ?
                  1 :
                  0);
      count += (std::find(G[i].right.begin(), G[i].right.end(),
                          e.getVertex(1)) != G[i].right.end() ?
                  1 :
                  0);
      count += (std::find(G[i].left.begin(), G[i].left.end(), e.getVertex(0)) !=
                    G[i].left.end() ?
                  1 :
                  0);
      count += (std::find(G[i].left.begin(), G[i].left.end(), e.getVertex(1)) !=
                    G[i].left.end() ?
                  1 :
                  0);
      count += (std::find(G[i].right.begin(), G[i].right.end(),
                          o.getVertex(0)) != G[i].right.end() ?
                  1 :
                  0);
      count += (std::find(G[i].right.begin(), G[i].right.end(),
                          o.getVertex(1)) != G[i].right.end() ?
                  1 :
                  0);
      if(count > maxCount) {
        maxCount = count;
        ROT = fabs(G[i].mat[0][0]) > .6 ? 0 : 1;
        cutGraphId = i;
      }
    }
    if(maxCount == 0) printf("IMPOSSIBLE\n");

    int pot = POT == potU ? 0 : 1;
    //    printf(" --> cutting cut graph %5d %5d\n",cutGraphId,
    //    pot,passages.size());
    int count = 0;
    for(std::size_t k = 0; k < passages.size(); k++) {
      if(pot == passages[k]._uv && cutGraphId == passages[k]._id) count++;
    }

    if(count > 20) {
      printf("CYCLE DETECTED for SING %lu : ", vsing->getNum());
      for(size_t k = 0; k < passages.size(); k++)
        printf("(%d,%d) ", passages[k]._id, passages[k]._uv);
      printf("\n");
      return -1;
    }

    if(passages.empty() || passages[passages.size() - 1]._uv != pot ||
       passages[passages.size() - 1]._id != cutGraphId) {
      passages.push_back(cutGraphPassage(cutGraphId, pot, p));
    }

    if(ROT) { POT = (POT == potU ? potV : potU); }
    else {
    }
    XX += ROT;
    // printf("XX = %d ROT = %d %lu\n",XX,ROT,cutGraphEnds.size());
    if(distance(e.getVertex(0), o.getVertex(0)) < 1.e-12)
      VAL = (1. - xi) * (*POT)[o.getVertex(0)] + xi * (*POT)[o.getVertex(1)];
    else
      VAL = (1. - xi) * (*POT)[o.getVertex(1)] + xi * (*POT)[o.getVertex(0)];
    computeOneIsoRecur(vsing, adj, VAL, o.getVertex(0), o.getVertex(1), p, *POT,
                       visited, cutGraphEnds, d1, G, f, COUNT, cuts, NB,
                       circular);
    if(XX > 1200) break;
  }
  return circular;
}

static bool computeIso(MVertex *vsing, v2t_cont &adj, double u,
                       std::map<MVertex *, double> &potU,
                       std::map<MVertex *, double> &potV, FILE *f,
                       std::map<MEdge, MEdge, MEdgeLessThan> &d1,
                       std::vector<groupOfCross2d> &G, int DIR,
                       std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts,
                       std::vector<cutGraphPassage> &passages)
{
  int COUNT = 100 * vsing->getNum() + 10 * DIR;
  std::vector<MElement *> faces = adj[vsing];
  for(size_t i = 0; i < faces.size(); i++) {
    MVertex *v0 = faces[i]->getVertex(0);
    MVertex *v1 = faces[i]->getVertex(1);
    MVertex *v2 = faces[i]->getVertex(2);
    double U0 = potU[v0];
    double U1 = potU[v1];
    double U2 = potU[v2];
    SPoint3 p0(v0->x(), v0->y(), v0->z());
    SPoint3 p1(v1->x(), v1->y(), v1->z());
    SPoint3 p2(v2->x(), v2->y(), v2->z());
    int circular = 0;
    if(v2 == vsing && (U0 - u) * (U1 - u) <= 0) {
      double xi = coord1d(U0, U1, u);
      SPoint3 pp = p0 * (1 - xi) + p1 * xi;
      circular = computeOneIso(vsing, adj, u, v0, v1, pp, &potU, &potV, d1, G,
                               f, COUNT++, cuts, passages);
    }
    else if(v1 == vsing && (U0 - u) * (U2 - u) <= 0) {
      double xi = coord1d(U0, U2, u);
      SPoint3 pp = p0 * (1 - xi) + p2 * xi;
      circular = computeOneIso(vsing, adj, u, v0, v2, pp, &potU, &potV, d1, G,
                               f, COUNT++, cuts, passages);
    }
    else if(v0 == vsing && (U1 - u) * (U2 - u) <= 0) {
      double xi = coord1d(U1, U2, u);
      SPoint3 pp = p1 * (1 - xi) + p2 * xi;
      circular = computeOneIso(vsing, adj, u, v1, v2, pp, &potU, &potV, d1, G,
                               f, COUNT++, cuts, passages);
    }
    if(circular == 2) printf("ISO %d is circular %d\n", COUNT - 1, circular);
    if(circular == -1) {
      printf("ISO %d is CYCLIC\n", COUNT - 1);
      return false;
    }
  }
  return true;
}

static bool computeIsos(
  GModel *gm, std::vector<GFace *> &faces,
  std::set<MVertex *, MVertexPtrLessThan> singularities,
  std::map<MEdge, cross2d, MEdgeLessThan> &C,
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> &new2old,
  std::map<MEdge, MEdge, MEdgeLessThan> &duplicateEdges,
  std::vector<std::vector<cross2d *> > &groups,
  std::vector<std::vector<cross2d *> > &groups_cg,
  std::map<MVertex *, double> &potU, std::map<MVertex *, double> &potV,
  std::set<MEdge, MEdgeLessThan> &cutG, std::vector<groupOfCross2d> &G,
  std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts,
  std::vector<cutGraphPassage> &passages)
{
  v2t_cont adj;
  for(size_t i = 0; i < faces.size(); i++) {
    buildVertexToElement(faces[i]->triangles, adj);
  }

  {
    auto it = new2old.begin();
    for(; it != new2old.end(); ++it) {
      if(singularities.find(it->second) != singularities.end()) {
        singularities.insert(it->first);
      }
    }
  }

  std::map<MVertex *, MVertex *, MVertexPtrLessThan> duplicates;
  {
    auto it = new2old.begin();
    for(; it != new2old.end(); ++it) {
      duplicates[it->first] = it->second;
      duplicates[it->second] = it->first;
    }
  }

  std::map<MEdge, MEdge, MEdgeLessThan> d1;
  {
    for(size_t i = 0; i < G.size(); i++) {
      for(size_t j = 0; j < G[i].side.size(); j++) {
        for(size_t k = 0; k < 3; k++) {
          MVertex *v0 = G[i].side[j]->getVertex(k);
          MVertex *v1 = G[i].side[j]->getVertex((k + 1) % 3);
          int J = -1, I = -1;
          for(size_t l = 0; l < G[i].left.size(); l++) {
            if(G[i].left[l] == v0) { I = l; }
            if(G[i].left[l] == v1) { J = l; }
          }
          if(I >= 0 && J >= 0) {
            MEdge l(G[i].left[I], G[i].left[J]);
            MEdge r(G[i].right[I], G[i].right[J]);
            d1[l] = r;
            d1[r] = l;
          }
        }
      }
      if(G[i].singularities.size() == 1) {
        MEdge l(G[i].singularities[0], G[i].left[G[i].left.size() - 1]);
        MEdge r(G[i].singularities[0], G[i].right[G[i].right.size() - 1]);
        d1[l] = r;
        d1[r] = l;
      }
    }
  }
  std::string fn = gm->getName() + "_QLayoutResults.pos";
  FILE *f = fopen(fn.c_str(), "w");
  fprintf(f, "View\"Big Cut\"{\n");

  auto it = singularities.begin();
  for(; it != singularities.end(); ++it) {
    GEntity *ge = (*it)->onWhat();
    if(ge->dim() == 2 || ge->edges().size() == 0) {
      printf("%lu %d %d %lu %22.15E %22.15E\n", ge->edges().size(), ge->tag(),
             ge->dim(), singularities.size(), potU[*it], potV[*it]);
      bool success = computeIso(*it, adj, potU[*it], potU, potV, f, d1, G, 0,
                                cuts, passages);
      if(!success) {
        printf("CYCLIC STUFF\n");
        //	return false;
      }
      success = computeIso(*it, adj, potV[*it], potV, potU, f, d1, G, 1, cuts,
                           passages);
      if(!success) {
        printf("CYCLIC STUFF\n");
        //	return false;
      }
    }
  }
  fprintf(f, "};\n");
  fclose(f);
  return true;
}

void getAllConnectedTriangles(
  cross2d *start, std::vector<cross2d *> &group,
  std::set<MVertex *, MVertexPtrLessThan> &isolated_singularities,
  std::set<MVertex *, MVertexPtrLessThan> &all, std::set<MTriangle *> &t,
  std::set<MTriangle *> &allTrianglesConsidered)
{
  std::set<cross2d *> touched;

  //  printf("group %lu isolated singularities\n",
  //  isolated_singularities.size());

  for(size_t i = 0; i < group.size(); i++) {
    if(isolated_singularities.find(group[i]->_e.getVertex(0)) ==
       isolated_singularities.end())
      all.insert(group[i]->_e.getVertex(0));
    if(isolated_singularities.find(group[i]->_e.getVertex(1)) ==
       isolated_singularities.end())
      all.insert(group[i]->_e.getVertex(1));
  }

  if(allTrianglesConsidered.find(start->_t[0]) !=
     allTrianglesConsidered.end()) {
    if(!start->_cneighbors[0]->inCutGraph)
      start = start->_cneighbors[0];
    else if(!start->_cneighbors[1]->inCutGraph)
      start = start->_cneighbors[1];
    else
      printf("error\n");
  }
  else if(start->_cneighbors.size() == 4 &&
          allTrianglesConsidered.find(start->_t[1]) !=
            allTrianglesConsidered.end()) {
    if(start->_cneighbors.size() == 4 && !start->_cneighbors[2]->inCutGraph)
      start = start->_cneighbors[2];
    else if(start->_cneighbors.size() == 4 &&
            !start->_cneighbors[3]->inCutGraph)
      start = start->_cneighbors[3];
    else
      printf("error\n");
  }
  else {
    if(!start->_cneighbors[0]->inCutGraph)
      start = start->_cneighbors[0];
    else if(!start->_cneighbors[1]->inCutGraph)
      start = start->_cneighbors[1];
    else if(start->_cneighbors.size() == 4 &&
            !start->_cneighbors[2]->inCutGraph)
      start = start->_cneighbors[2];
    else if(start->_cneighbors.size() == 4 &&
            !start->_cneighbors[3]->inCutGraph)
      start = start->_cneighbors[3];
    else
      printf("error\n");
  }

  std::stack<cross2d *> _s;
  _s.push(start);

  while(!_s.empty()) {
    start = _s.top();
    touched.insert(start);
    _s.pop();
    for(size_t i = 0; i < start->_t.size(); i++) {
      t.insert(start->_t[i]);
      allTrianglesConsidered.insert(start->_t[i]);
    }

    for(size_t i = 0; i < start->_cneighbors.size(); i++) {
      cross2d *c = start->_cneighbors[i];
      if(!c->inCutGraph && touched.find(c) == touched.end()) {
        if(all.find(c->_e.getVertex(0)) != all.end() ||
           all.find(c->_e.getVertex(1)) != all.end()) {
          _s.push(c);
        }
      }
    }
  }
}

static bool computeLeftRight(groupOfCross2d &g, MVertex **left, MVertex **right)
{
  for(size_t i = 0; i < g.side.size(); i++) {
    if(g.side[i]->getVertex(0) == *right || g.side[i]->getVertex(1) == *right ||
       g.side[i]->getVertex(2) == *right) {
      MVertex *temp = *left;
      *left = *right;
      *right = temp;
      return true;
    }
    if(g.side[i]->getVertex(0) == *left || g.side[i]->getVertex(1) == *left ||
       g.side[i]->getVertex(2) == *left) {
      return true;
    }
  }
  return false;
}

static void createJumpyPairs(
  groupOfCross2d &g, std::set<MVertex *, MVertexPtrLessThan> &singularities,
  std::set<MVertex *, MVertexPtrLessThan> &boundaries,
  std::multimap<MVertex *, MVertex *, MVertexPtrLessThan> &old2new)
{
  std::set<MVertex *, MVertexPtrLessThan> touched;

  //  printf("GROUP %d \n",g.groupId);
  for(size_t i = 0; i < g.crosses.size(); ++i) {
    cross2d *c = g.crosses[i];
    for(size_t j = 0; j < 2; j++) {
      MVertex *vv = c->_e.getVertex(j);
      if(touched.find(vv) == touched.end()) {
        touched.insert(vv);
        MTriangle *t1 = c->_t[0];
        MTriangle *t2 = c->_t[1];
        MVertex *v0 = nullptr;
        MVertex *v1 = nullptr;
        if(t1->getVertex(0) == vv || t1->getVertex(1) == vv ||
           t1->getVertex(2) == vv) {
          if(v0 == nullptr)
            v0 = vv;
          else if(v1 == nullptr)
            v1 = vv;
          else
            Msg::Error("error in JumpyPairs 1");
        }
        if(t2->getVertex(0) == vv || t2->getVertex(1) == vv ||
           t2->getVertex(2) == vv) {
          if(v0 == nullptr)
            v0 = vv;
          else if(v1 == nullptr)
            v1 = vv;
          else
            Msg::Error("error in JumpyPairs 1");
        }
        for(auto it = old2new.lower_bound(vv); it != old2new.upper_bound(vv);
            ++it) {
          MVertex *vvv = it->second;
          if(t1->getVertex(0) == vvv || t1->getVertex(1) == vvv ||
             t1->getVertex(2) == vvv) {
            if(v0 == nullptr)
              v0 = vvv;
            else if(v1 == nullptr)
              v1 = vvv;
            else
              Msg::Error("error in JumpyPairs 1");
          }
          if(t2->getVertex(0) == vvv || t2->getVertex(1) == vvv ||
             t2->getVertex(2) == vvv) {
            if(v0 == nullptr)
              v0 = vvv;
            else if(v1 == nullptr)
              v1 = vvv;
            else
              Msg::Error("error in JumpyPairs 2");
          }
        }
        if(!v1 || !v0) Msg::Error("error in JumpyPairs 3");
        if(computeLeftRight(g, &v0, &v1)) {
          if(boundaries.find(vv) != boundaries.end()) {
            g.left.insert(g.left.begin(), v0);
            g.right.insert(g.right.begin(), v1);
          }
          else {
            g.left.push_back(v0);
            g.right.push_back(v1);
          }
        }
        else
          Msg::Error("error in jumpy pairs %lu \n", vv->getNum());
      }
      else if(singularities.find(vv) != singularities.end()) {
        g.singularities.push_back(vv);
      }
      //	else if (singularities.find(vv) == singularities.end()){
      //	  printf("ERROR --> no counterpart vertex in the cut graph\n");
      //	}
    }
  }
  //    printf("GRoup %d mat [%g,%g] [%g,%g] %lu nodes on each side \n"
  //  	 ,g.groupId,g.mat[0][0],g.mat[0][1],g.mat[1][0],g.mat[1][1],
  //    	 g.left.size());
}

static void
analyzeGroup(std::vector<cross2d *> &group, groupOfCross2d &g,
             std::map<MTriangle *, SVector3> &d,
             std::map<MTriangle *, SVector3> &d2, v2t_cont &adj,
             std::set<MVertex *, MVertexPtrLessThan> &isolated_singularities,
             std::set<MVertex *, MVertexPtrLessThan> &boundaries,
             std::set<MTriangle *> &allTrianglesConsidered)
{
  g.crosses = group;
  double MAX = 0.0;
  for(size_t i = 0; i < g.crosses.size(); ++i) {
    cross2d *c = g.crosses[i];
    if(c->_t.size() == 2) {
      SVector3 t1 = d[c->_t[0]];
      SVector3 t2 = d[c->_t[1]];
      MAX = std::max(dot(t1, t2), MAX);
    }
  }
  if(MAX > .8)
    g.rot = false;
  else
    g.rot = true;
  for(size_t i = 0; i < g.crosses.size(); ++i) {
    cross2d *c = g.crosses[i];
    c->rotation = g.rot;
  }

  std::set<MTriangle *> t;
  std::set<MVertex *, MVertexPtrLessThan> all;
  getAllConnectedTriangles(group[0], group, isolated_singularities, all, t,
                           allTrianglesConsidered);
  g.side.insert(g.side.begin(), t.begin(), t.end());
  g.vertices.insert(g.vertices.begin(), all.begin(), all.end());

  // compute which rotation ...
  for(size_t i = 0; i < g.crosses.size(); ++i) {
    cross2d *c = g.crosses[i];
    if(c->_t.size() == 2) {
      if(t.find(c->_t[0]) != t.end()) {
        g.mat[0][0] = dot(d[c->_t[0]], d[c->_t[1]]);
        g.mat[0][1] = dot(d[c->_t[0]], d2[c->_t[1]]);
        g.mat[1][0] = dot(d2[c->_t[0]], d[c->_t[1]]);
        g.mat[1][1] = dot(d2[c->_t[0]], d2[c->_t[1]]);
      }
      else if(t.find(c->_t[1]) != t.end()) {
        g.mat[0][0] = dot(d[c->_t[0]], d[c->_t[1]]);
        g.mat[1][0] = dot(d[c->_t[0]], d2[c->_t[1]]);
        g.mat[0][1] = dot(d2[c->_t[0]], d[c->_t[1]]);
        g.mat[1][1] = dot(d2[c->_t[0]], d2[c->_t[1]]);
      }
    }
  }
  for(int j = 0; j < 2; j++) {
    for(int k = 0; k < 2; k++) {
      if(g.mat[j][k] > .7)
        g.mat[j][k] = 1;
      else if(g.mat[j][k] < -.7)
        g.mat[j][k] = -1;
      else
        g.mat[j][k] = 0;
    }
  }
}

///--- class containing the data
class quadLayoutData {
public:
  GModel *gm;
  std::vector<GFace *> f;
  std::map<MEdge, cross2d, MEdgeLessThan> C;
  dofManager<double> *myAssembler;
  std::set<MVertex *, MVertexPtrLessThan> vs;
  std::set<MEdge, MEdgeLessThan> cutG;
  std::set<MVertex *, MVertexPtrLessThan> singularities;
  std::map<MVertex *, int> indices;
  std::map<MVertex *, double> gaussianCurvatures;
  std::set<MVertex *, MVertexPtrLessThan> boundaries;
  std::set<MVertex *, MVertexPtrLessThan> corners;
  std::vector<std::vector<cross2d *> > groups;
  std::vector<std::vector<cross2d *> > groups_cg;
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> new2old;
  std::string modelName;
  std::map<MTriangle *, SVector3> d0, d1;
  std::vector<groupOfCross2d> G;

  void printTheta(const char *name)
  {
    std::string fn = modelName + "_" + name + ".pos";
    FILE *of = fopen(fn.c_str(), "w");
    fprintf(of, "View \"Theta\"{\n");
    for(size_t i = 0; i < f.size(); i++) {
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        MTriangle *t = f[i]->triangles[j];
        auto it0 = C.find(t->getEdge(0));
        auto it1 = C.find(t->getEdge(1));
        auto it2 = C.find(t->getEdge(2));

        SVector3 d0 = it0->second.o_i;
        SVector3 d1 = it1->second.o_i;
        SVector3 d2 = it2->second.o_i;
        double a = atan2(d0.y(), d0.x());
        double b = atan2(d1.y(), d1.x());
        double c = atan2(d2.y(), d2.x());
        it0->second.normalize(a);
        it0->second.normalize(b);
        it0->second.normalize(c);
        double A = c + a - b;
        double B = a + b - c;
        double C = b + c - a;
        it0->second.normalize(A);
        it0->second.normalize(B);
        it0->second.normalize(C);
        fprintf(of, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
                t->getVertex(0)->x(), t->getVertex(0)->y(),
                t->getVertex(0)->z(), t->getVertex(1)->x(),
                t->getVertex(1)->y(), t->getVertex(1)->z(),
                t->getVertex(2)->x(), t->getVertex(2)->y(),
                t->getVertex(2)->z(), A, B, C);
      }
    }
    fprintf(of, "};\n");
    fclose(of);
  }

  void printCross(const char *name)
  {
    std::string fn = modelName + "_" + name + ".pos";
    FILE *of = fopen(fn.c_str(), "w");
    fprintf(of, "View \"Direction fields\"{\n");
    auto it = C.begin();
    for(it = C.begin(); it != C.end(); ++it) {
      double a0 = it->second._a;
      MEdge e0 = it->second._e;
      SVector3 d1 = (it->second._tgt * cos(a0) + it->second._tgt2 * sin(a0));
      SVector3 d2 = (it->second._tgt * (-sin(a0)) + it->second._tgt2 * cos(a0));
      SVector3 d3 = (it->second._tgt * (-cos(a0)) - it->second._tgt2 * sin(a0));
      SVector3 d4 = (it->second._tgt * sin(a0) - it->second._tgt2 * cos(a0));

      for(size_t I = 0; I < it->second._t.size(); I++) {
        fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
                0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
                0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
                0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d1.x(),
                d1.y(), d1.z());
        fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
                0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
                0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
                0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d2.x(),
                d2.y(), d2.z());
        fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
                0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
                0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
                0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d3.x(),
                d3.y(), d3.z());
        fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
                0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
                0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
                0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d4.x(),
                d4.y(), d4.z());
      }
    }
    fprintf(of, "};\n");
    fclose(of);
  }

  int computeCrossFieldExtrinsic(double tol, size_t nIterLaplace = 2000)
  {
    std::vector<cross2d *> pc;
    for(auto it = C.begin(); it != C.end(); ++it) pc.push_back(&(it->second));

    std::mt19937 generator;
    generator.seed(0); // zero for some determinism

    size_t ITER = 0;
    while(ITER++ < nIterLaplace) {
      if(ITER % 200 == 0) std::shuffle(pc.begin(), pc.end(), generator);
      for(size_t i = 0; i < pc.size(); i++) pc[i]->average_init();
      if(ITER % 1000 == 0) Msg::Info("Linear smooth : iter %6lu", ITER);
    }

    for(size_t i = 0; i < pc.size(); i++) pc[i]->computeVector();

    fastImplementationExtrinsic(C, tol);

    for(size_t i = 0; i < pc.size(); i++) pc[i]->computeAngle();

    return 0;
  }

  void printScalar(dofManager<double> *dof, char c)
  {
    std::string fn = modelName + "_" + c + ".pos";

    FILE *_f = fopen(fn.c_str(), "w");
    fprintf(_f, "View \"H\"{\n");

    for(size_t i = 0; i < f.size(); i++) {
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        MTriangle *t = f[i]->triangles[j];
        double a, b, c;
        dof->getDofValue(t->getVertex(0), 0, 1, a);
        dof->getDofValue(t->getVertex(1), 0, 1, b);
        dof->getDofValue(t->getVertex(2), 0, 1, c);
        fprintf(_f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
                t->getVertex(0)->x(), t->getVertex(0)->y(),
                t->getVertex(0)->z(), t->getVertex(1)->x(),
                t->getVertex(1)->y(), t->getVertex(1)->z(),
                t->getVertex(2)->x(), t->getVertex(2)->y(),
                t->getVertex(2)->z(), a, b, c);
      }
    }
    fprintf(_f, "};\n");
    fclose(_f);
  }

  int computeCrossFieldAndH()
  {
    computeCrossFieldExtrinsic(1.e-9);
    myAssembler = computeH(gm, f, vs, C);
    //    printScalar(myAssembler,'H');
    computeSingularities(C, singularities, indices, myAssembler);
    //    print_H_and_Cross(gm, f, C, *myAssembler, singularities);
    return 1;
  }

  dofManager<double> *computeHFromSingularities(std::map<MVertex *, int> &sing,
                                                int nbTurns)
  {
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
    linearSystemGmm<double> *_lsys = new linearSystemGmm<double>;
#else
    linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

    dofManager<double> *dof = new dofManager<double>(_lsys);

    auto it = C.begin();
    std::vector<MEdge> edges;
    for(; it != C.end(); ++it) {
      if(it->second.inBoundary) { edges.push_back(it->first); }
    }
    std::vector<std::vector<MVertex *> > vsorted;
    SortEdgeConsecutive(edges, vsorted);

    // AVERAGE
    dof->numberVertex(*vs.begin(), 1, 1);

    for(auto it = vs.begin(); it != vs.end(); ++it) {
      dof->numberVertex(*it, 0, 1);
    }

    simpleFunction<double> ONE(1.0);
    laplaceTerm l(nullptr, 1, &ONE);

    std::set<GEntity *> firsts;
    for(size_t i = 0; i < f.size(); i++) {
      std::vector<GEdge *> e = f[i]->edges();
      if(e.size()) firsts.insert(e[0]);
      //      printf("--> %lu\n",e[0]->tag());
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        MTriangle *t = f[i]->triangles[j];
        SElement se(t);
        l.addToMatrix(*dof, &se);
      }
    }

    for(size_t j = 0; j < vsorted.size(); ++j) {
      if(vsorted[j][0] == vsorted[j][vsorted[j].size() - 1]) {
        vsorted[j].erase(vsorted[j].begin());
      }

      std::vector<double> CURVATURE;
      CURVATURE.resize(vsorted[j].size());
      for(size_t i = 0; i < vsorted[j].size(); ++i) { CURVATURE[i] = 0.0; }

      for(size_t i = 0; i < vsorted[j].size(); ++i) {
        MVertex *vi = vsorted[j][i];
        MVertex *vip = vsorted[j][(i + 1) % vsorted[j].size()];
        MVertex *vim =
          vsorted[j][(i + vsorted[j].size() - 1) % vsorted[j].size()];
        SVector3 vv(vip->x() - vi->x(), vip->y() - vi->y(), vip->z() - vi->z());
        SVector3 ww(vi->x() - vim->x(), vi->y() - vim->y(), vi->z() - vim->z());
        vv.normalize();
        ww.normalize();
        SVector3 xx = crossprod(vv, ww);
        double ccos = dot(vv, ww);
        double ANGLE = atan2(xx.norm(), ccos);
        xx.normalize();

        MEdge edze(vi, vim);
        auto itip = C.find(edze);
        double sign = 1;
        if(itip != C.end()) {
          MTriangle *tt = itip->second._t[0];
          MVertex *vrv;
          if(tt->getVertex(0) != vi && tt->getVertex(0) != vim) {
            vrv = tt->getVertex(0);
          }
          else if(tt->getVertex(1) != vi && tt->getVertex(1) != vim) {
            vrv = tt->getVertex(1);
          }
          else
            vrv = tt->getVertex(2);
          SVector3 aa(vrv->x() - vim->x(), vrv->y() - vim->y(),
                      vrv->z() - vim->z());
          SVector3 zz = crossprod(aa, ww);
          zz.normalize();
          sign = -dot(zz, xx); // > 0 ? -1 : 1;
                               // sign = dot(zz, xx) > 0 ? -1 : 1;
        }
        else
          printf("ARGH\n");
        //	if (vsorted.size() == 1)sign = -1;
        CURVATURE[i] += ANGLE * sign;
        // printf("%12.5E\n",sign);
      }

      for(size_t i = 0; i < vsorted[j].size(); ++i) {
        Dof E(vsorted[j][i]->getNum(), Dof::createTypeWithTwoInts(0, 1));
        _lsys->addToRightHandSide(dof->getDofNumber(E), CURVATURE[i]);
      }
    }

    for(auto it = gaussianCurvatures.begin(); it != gaussianCurvatures.end();
        ++it) {
      Dof E(it->first->getNum(), Dof::createTypeWithTwoInts(0, 1));
      //_lsys->addToRightHandSide(dof->getDofNumber(E),-it->second);
    }

    for(auto it = sing.begin(); it != sing.end(); ++it) {
      Dof E(it->first->getNum(), Dof::createTypeWithTwoInts(0, 1));
      _lsys->addToRightHandSide(dof->getDofNumber(E),
                                2.0 * M_PI * (double)it->second / nbTurns);
    }

    // FIX DE LA MORT
    // AVERAGE
    Dof EAVG((*vs.begin())->getNum(), Dof::createTypeWithTwoInts(1, 1));

    for(auto it = vs.begin(); it != vs.end(); ++it) {
      Dof E((*it)->getNum(), Dof::createTypeWithTwoInts(0, 1));
      dof->assemble(EAVG, E, 1);
      dof->assemble(E, EAVG, 1);
    }

    _lsys->systemSolve();
    return dof;
  }

  int computeHFromSingularities(std::map<MVertex *, int> &s)
  {
    myAssembler = computeHFromSingularities(s, 4);
    for(auto it = s.begin(); it != s.end(); ++it) {
      singularities.insert(it->first);
    }
    //    printScalar(myAssembler, 'H');
    return 1;
  }

  //---------------------------------------------------------------------------

  void computeThetaUsingHCrouzeixRaviart(
    std::map<int, std::vector<double> > &dataTHETA)
  {
#if defined(HAVE_PETSC)
    linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
    linearSystemGmm<double> *_lsys = new linearSystemGmm<double>;
#else
    linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif
    dofManager<double> *theta = new dofManager<double>(_lsys);

    std::map<MEdge, size_t, MEdgeLessThan> aaa;
    size_t count = 0;
    for(size_t i = 0; i < f.size(); i++) {
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        for(size_t k = 0; k < 3; k++) {
          if(aaa.find(f[i]->triangles[j]->getEdge(k)) == aaa.end()) {
            Dof EdgeDof(count, Dof::createTypeWithTwoInts(0, 1));
            theta->numberDof(EdgeDof);
            aaa[f[i]->triangles[j]->getEdge(k)] = count++;
          }
        }
      }
    }

    for(size_t i = 0; i < f.size(); i++) {
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        MTriangle *t = f[i]->triangles[j];
        double V = t->getVolume();
        double g1[3], g2[3], g3[3];
        double a[3];
        a[0] = 1;
        a[1] = 0;
        a[2] = 0;
        t->interpolateGrad(a, 0, 0, 0, g1);
        a[0] = 0;
        a[1] = 1;
        a[2] = 0;
        t->interpolateGrad(a, 0, 0, 0, g2);
        a[0] = 0;
        a[1] = 0;
        a[2] = 1;
        t->interpolateGrad(a, 0, 0, 0, g3);
        SVector3 G[3];
        G[0] = SVector3(g1[0] + g2[0] - g3[0], g1[1] + g2[1] - g3[1],
                        g1[2] + g2[2] - g3[2]);
        G[1] = SVector3(g2[0] + g3[0] - g1[0], g2[1] + g3[1] - g1[1],
                        g2[2] + g3[2] - g1[2]);
        G[2] = SVector3(g1[0] + g3[0] - g2[0], g1[1] + g3[1] - g2[1],
                        g1[2] + g3[2] - g2[2]);
        SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
                     t->getVertex(1)->y() - t->getVertex(0)->y(),
                     t->getVertex(1)->z() - t->getVertex(0)->z());
        SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
                     t->getVertex(2)->y() - t->getVertex(0)->y(),
                     t->getVertex(2)->z() - t->getVertex(0)->z());
        SVector3 xx = crossprod(v20, v10);
        xx.normalize();

        double H[3];
        for(int k = 0; k < 3; k++) {
          auto itk = new2old.find(t->getVertex(k));
          if(itk == new2old.end())
            myAssembler->getDofValue(t->getVertex(k), 0, 1, H[k]);
          else
            myAssembler->getDofValue(itk->second, 0, 1, H[k]);
        }
        double gradH[3];
        t->interpolateGrad(H, 0, 0, 0, gradH);

        SVector3 temp(gradH[0], gradH[1], gradH[2]);
        SVector3 gradHOrtho = crossprod(temp, xx);

        double RHS[3] = {dot(gradHOrtho, G[0]), dot(gradHOrtho, G[1]),
                         dot(gradHOrtho, G[2])};

        for(size_t k = 0; k < 3; k++) {
          Dof Ek(aaa[t->getEdge(k)], Dof::createTypeWithTwoInts(0, 1));
          theta->assemble(Ek, RHS[k] * V);
          for(size_t l = 0; l < 3; l++) {
            Dof El(aaa[t->getEdge(l)], Dof::createTypeWithTwoInts(0, 1));
            theta->assemble(Ek, El, -dot(G[k], G[l]) * V);
          }
        }
      }
    }

    _lsys->systemSolve();

    double sum = 0;
    int count_ = 0;

    auto it = aaa.begin();
    for(; it != aaa.end(); ++it) {
      Dof d(it->second, Dof::createTypeWithTwoInts(0, 1));
      double t;
      theta->getDofValue(d, t);
      MVertex *v0, *v1;
      auto it0 = new2old.find(it->first.getVertex(0));
      if(it0 == new2old.end())
        v0 = it->first.getVertex(0);
      else
        v0 = it0->second;
      it0 = new2old.find(it->first.getVertex(1));
      if(it0 == new2old.end())
        v1 = it->first.getVertex(1);
      else
        v1 = it0->second;
      MEdge e(v0, v1);
      auto itc = C.find(e);
      // well... at first ...
      itc->second.o_i = SVector3(cos(t), sin(t), 0.0);
      // end well
      double aa = atan2(dot(itc->second._tgt2, itc->second.o_i),
                        dot(itc->second._tgt, itc->second.o_i));
      itc->second.normalize(aa);
      if(!itc->second.inBoundary) { itc->second._a = aa; }
      else {
        //	printf("%12.5E %lu %lu\n",aa,
        //	       itc->second._e.getVertex(0)->getNum(),
        //	       itc->second._e.getVertex(1)->getNum());
        itc->second._a = 0;
        count_++;
        sum += aa;
      }
    }

    sum /= count_;
    auto itc = C.begin();
    for(; itc != C.end(); ++itc) {
      if(!itc->second.inBoundary) {
        itc->second._a -= sum;
        itc->second._atemp = itc->second._a;
        itc->second.normalize(itc->second._a);
      }
    }

    //    printCross ("crossCR");
    {
      //      std::string fn = modelName + "_"+"thetaCR.pos";
      //      FILE *of = fopen(fn.c_str(), "w");
      //      fprintf(of, "View \"Theta - Crouzeix Raviart\"{\n");
      for(size_t i = 0; i < f.size(); i++) {
        for(size_t j = 0; j < f[i]->triangles.size(); j++) {
          MTriangle *t = f[i]->triangles[j];
          Dof d0(aaa[f[i]->triangles[j]->getEdge(0)],
                 Dof::createTypeWithTwoInts(0, 1));
          Dof d1(aaa[f[i]->triangles[j]->getEdge(1)],
                 Dof::createTypeWithTwoInts(0, 1));
          Dof d2(aaa[f[i]->triangles[j]->getEdge(2)],
                 Dof::createTypeWithTwoInts(0, 1));
          double a, b, c;
          theta->getDofValue(d0, a);
          theta->getDofValue(d1, b);
          theta->getDofValue(d2, c);
          double A = c + a - b;
          double B = a + b - c;
          double C = b + c - a;
          std::vector<double> ts;
          ts.push_back(A);
          ts.push_back(B);
          ts.push_back(C);
          dataTHETA[t->getNum()] = ts;
          /*	  fprintf(of, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
              t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
              t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              A,B,C);*/
        }
      }
      //      fprintf(of, "};\n");
      //      fclose(of);
    }
  }
  //---------------------------------------------------------------------------

  quadLayoutData(GModel *_gm, std::vector<GFace *> &_f, const std::string &name,
                 bool includeFeatureEdges = true)
    : gm(_gm), f(_f), myAssembler(nullptr)
  {
    modelName = name;
    for(size_t i = 0; i < f.size(); i++) {
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        MTriangle *t = f[i]->triangles[j];
        for(size_t k = 0; k < 3; k++) {
          vs.insert(t->getVertex(k));
          MEdge e = t->getEdge(k);
          MEdge e1 = t->getEdge((k + 1) % 3);
          MEdge e2 = t->getEdge((k + 2) % 3);

          // Gaussian Curvatures
          MVertex *vk = t->getVertex(k);
          MVertex *vk1 = t->getVertex((k + 1) % 3);
          MVertex *vk2 = t->getVertex((k + 2) % 3);
          SVector3 v1(vk1->x() - vk->x(), vk1->y() - vk->y(),
                      vk1->z() - vk->z());
          SVector3 v2(vk2->x() - vk->x(), vk2->y() - vk->y(),
                      vk2->z() - vk->z());
          double CURV = angle(v1, v2);
          auto itg = gaussianCurvatures.find(vk);
          if(itg == gaussianCurvatures.end())
            gaussianCurvatures[vk] = 2 * M_PI - CURV;
          else
            itg->second -= CURV;
          //---------------------------------------------------------------------

          cross2d c(e, t, e1, e2);
          auto it = C.find(e);
          if(it == C.end())
            C.insert(std::make_pair(e, c));
          else {
            it->second._t.push_back(t);
            it->second._neighbors.push_back(e1);
            it->second._neighbors.push_back(e2);
          }
        }
      }
    }
    if(includeFeatureEdges) {
      for(size_t i = 0; i < f.size(); i++) {
        std::vector<GEdge *> e = f[i]->edges();
        for(size_t j = 0; j < e.size(); j++) {
          for(size_t k = 0; k < e[j]->lines.size(); k++) {
            MLine *l = e[j]->lines[k];
            MEdge e = l->getEdge(0);
            auto it = C.find(e);
            if(it != C.end()) { it->second.inBoundary = true; }
          }
        }
      }
    }
    auto it = C.begin();
    for(; it != C.end(); ++it) it->second.finish(C);
    it = C.begin();
    for(; it != C.end(); ++it) it->second.finish2();
    FILE *F = fopen("gc.pos", "w");
    fprintf(F, "View\"\"{\n");
    double dd = 0;
    for(auto it = gaussianCurvatures.begin(); it != gaussianCurvatures.end();
        ++it) {
      fprintf(F, "SP(%g,%g,%g){%g};\n", it->first->x(), it->first->y(),
              it->first->z(), it->second);
      dd += it->second;
    }
    printf("%22.15E %22.15E\n", dd, dd - 4 * M_PI);
    fprintf(F, "};\n");
    fclose(F);
  }

  void restoreInitialMesh()
  {
    unDuplicateNodesInCutGraph(f, new2old);
    G.clear();
    groups.clear();
    groups_cg.clear();
    cutG.clear();
    new2old.clear();
    //    boundaries.clear();
    auto it = C.begin();
    for(; it != C.end(); ++it) {
      it->second.inCutGraph = false;
      it->second._btemp = 0;
    }
  }

  int computeUniqueVectorsPerTriangle()
  {
    // LIFTING
    std::set<cross2d *> visited;
    while(visited.size() != C.size()) {
      for(auto it = C.begin(); it != C.end(); ++it) {
        if(visited.find(&(it->second)) == visited.end() &&
           cutG.find(it->second._e) == cutG.end()) {
          computeLifting(&(it->second), 0, cutG, singularities, boundaries,
                         visited);
          break;
        }
      }
    }
    computeUniqueVectorPerTriangle(gm, f, C, 0, d0);
    computeUniqueVectorPerTriangle(gm, f, C, 1, d1);
    return 0;
  }

  int computeCutGraph(std::map<MEdge, MEdge, MEdgeLessThan> &duplicateEdges)
  {
    // COMPUTING CUT GRAPH
    cutGraph(C, cutG, singularities, boundaries);
    for(auto it = C.begin(); it != C.end(); ++it) {
      MEdge e0 = it->second._e;
      if(cutG.find(e0) != cutG.end()) it->second.inCutGraph = true;
    }

    groupBoundaries(gm, C, groups, singularities, corners, false);
    groupBoundaries(gm, C, groups_cg, singularities, corners, true);

    v2t_cont adj;
    for(size_t i = 0; i < f.size(); i++) {
      buildVertexToElement(f[i]->triangles, adj);
    }

    std::string fn = modelName + "_groups_analyzed.pos";
    FILE *_f = fopen(fn.c_str(), "w");
    fprintf(_f, "View \"groups\"{\n");

    std::set<MVertex *, MVertexPtrLessThan> isolated_singularities;
    {
      for(auto it = singularities.begin(); it != singularities.end(); ++it) {
        int count = 0;
        for(size_t i = 0; i < groups_cg.size(); i++) {
          for(size_t k = 0; k < groups_cg[i].size(); k++) {
            for(size_t j = 0; j < 2; j++) {
              MVertex *v = groups_cg[i][k]->_e.getVertex(j);
              if(v == *it) count++;
            }
          }
        }
        if(count == 1) { isolated_singularities.insert(*it); }
        else {
          isolated_singularities.insert(*it);
        }
      }
    }

    d0.clear();
    d1.clear();
    computeUniqueVectorsPerTriangle();

    // analyzing groups
    {
      std::set<MTriangle *> allTrianglesConsidered;
      for(size_t i = 0; i < groups_cg.size(); i++) {
        groupOfCross2d g(i);
        analyzeGroup(groups_cg[i], g, d0, d1, adj, isolated_singularities,
                     boundaries, allTrianglesConsidered);
        g.print(_f);
        G.push_back(g);
      }
    }
    fprintf(_f, "};\n");
    fclose(_f);

    std::multimap<MVertex *, MVertex *, MVertexPtrLessThan> old2new;
    duplicateNodesInCutGraph(f, C, new2old, old2new, duplicateEdges,
                             singularities, adj, G);

    for(size_t i = 0; i < groups_cg.size(); i++) {
      createJumpyPairs(G[i], singularities, boundaries, old2new);
    }
    return 0;
  }

  int computeCrossFieldAndH(std::map<MVertex *, int> *s,
                            std::map<int, std::vector<double> > &dataTHETA)
  {
    double a = TimeOfDay();
    computeHFromSingularities(*s);
    double b = TimeOfDay();
    Msg::Info("Real part H (nodal) has been computed in %4g sec", b - a);

    std::map<MEdge, MEdge, MEdgeLessThan> duplicateEdges;

    double c = TimeOfDay();
    computeCutGraph(duplicateEdges);
    Msg::Info("Cut Graph has been computed in %4g sec", c - b);

    double d = TimeOfDay();
    computeThetaUsingHCrouzeixRaviart(dataTHETA);
    Msg::Info("Imaginary part H (crouzeix raviart/multi-valued) has been "
              "computed in %4g sec",
              d - c);
    restoreInitialMesh();
    return 0;
  }

  MVertex *intersectEdgeEdge(MEdge &e, MVertex *v1, MVertex *v2, GFace *gf)
  {
    MVertex *e1 = e.getVertex(0);
    MVertex *e2 = e.getVertex(1);

    if(e1 == v2) return nullptr;
    if(e2 == v2) return nullptr;

    SVector3 e1e2(e2->x() - e1->x(), e2->y() - e1->y(), e2->z() - e1->z());
    SVector3 e1v1(v1->x() - e1->x(), v1->y() - e1->y(), v1->z() - e1->z());
    SVector3 e2v1(v1->x() - e2->x(), v1->y() - e2->y(), v1->z() - e2->z());

    SVector3 a = crossprod(e1e2, e1v1);
    double b = dot(e1v1, e2v1);
    if(a.norm() < 1.e-10 && b < 0) return v1;

    if(!v2) {
      //      Msg::Error("Error In CutMesh");
      return nullptr;
    }

    SVector3 e2v2(v2->x() - e2->x(), v2->y() - e2->y(), v2->z() - e2->z());
    SVector3 e1v2(v2->x() - e1->x(), v2->y() - e1->y(), v2->z() - e1->z());
    a = crossprod(e1e2, e1v2);
    b = dot(e1v2, e2v2);
    if(a.norm() < 1.e-10 && b < 0) return v2;

    double x[2];

    bool inters = intersection_segments(
      SPoint3(e.getVertex(0)->x(), e.getVertex(0)->y(), e.getVertex(0)->z()),
      SPoint3(e.getVertex(1)->x(), e.getVertex(1)->y(), e.getVertex(1)->z()),
      SPoint3(v1->x(), v1->y(), v1->z()), SPoint3(v2->x(), v2->y(), v2->z()),
      x);
    if(!inters) return nullptr;
    return new MEdgeVertex(v2->x() * x[1] + v1->x() * (1. - x[1]),
                           v2->y() * x[1] + v1->y() * (1. - x[1]),
                           v2->z() * x[1] + v1->z() * (1. - x[1]), nullptr, 0);
  }

  void cut_edge(std::map<MEdge, int, MEdgeLessThan> &ecuts, MVertex *v0,
                MVertex *v1, MVertex *mid)
  {
    MEdge e(v0, v1);
    auto it = ecuts.find(e);
    if(it != ecuts.end()) {
      int index = it->second;
      ecuts.erase(it);
      MEdge e1(v0, mid);
      MEdge e2(mid, v1);
      ecuts[e1] = index;
      ecuts[e2] = index;
    }
  }

  void cutTriangles(std::vector<MTriangle *> &ts, GFace *gf, MVertex *v1,
                    MVertex *v2, GEdge *ge,
                    std::map<MEdge, int, MEdgeLessThan> &ecuts, int index,
                    FILE *f)
  {
    std::map<MEdge, MVertex *, MEdgeLessThan> e_cut;
    std::vector<MTriangle *> newt;

    for(size_t i = 0; i < ts.size(); ++i) {
      MVertex *vs[3] = {nullptr, nullptr, nullptr};
      for(size_t j = 0; j < 3; ++j) {
        MEdge e = ts[i]->getEdge(j);
        if(e_cut.find(e) == e_cut.end()) {
          MVertex *v = intersectEdgeEdge(e, v1, v2, gf);
          if(v && v != v1 && v != v2) {
            gf->mesh_vertices.push_back(v);
            if(f)
              fprintf(f, "SP(%g,%g,%g){%d};\n", v->x(), v->y(), v->z(),
                      gf->tag());
          }
          e_cut[e] = v;
        }
        vs[j] = e_cut[e];
      }

      if(!vs[0] && !vs[1] && !vs[2])
        newt.push_back(ts[i]);
      else if(vs[0] && !vs[1] && !vs[2]) {
        //	printf("\n");
        newt.push_back(
          new MTriangle(ts[i]->getVertex(0), vs[0], ts[i]->getVertex(2)));
        newt.push_back(
          new MTriangle(vs[0], ts[i]->getVertex(1), ts[i]->getVertex(2)));
        cut_edge(ecuts, ts[i]->getVertex(0), ts[i]->getVertex(1), vs[0]);
        MEdge ed(ts[i]->getVertex(2), vs[0]);
        ecuts[ed] = index;
      }
      else if(!vs[0] && vs[1] && !vs[2]) {
        //	printf("coucouc\n");
        newt.push_back(
          new MTriangle(ts[i]->getVertex(0), ts[i]->getVertex(1), vs[1]));
        newt.push_back(
          new MTriangle(ts[i]->getVertex(0), vs[1], ts[i]->getVertex(2)));
        cut_edge(ecuts, ts[i]->getVertex(2), ts[i]->getVertex(1), vs[1]);
        MEdge ed(ts[i]->getVertex(0), vs[1]);
        ecuts[ed] = index;
      }
      else if(!vs[0] && !vs[1] && vs[2]) {
        //	printf("coucouc\n");
        newt.push_back(
          new MTriangle(ts[i]->getVertex(0), ts[i]->getVertex(1), vs[2]));
        newt.push_back(
          new MTriangle(vs[2], ts[i]->getVertex(1), ts[i]->getVertex(2)));
        cut_edge(ecuts, ts[i]->getVertex(2), ts[i]->getVertex(0), vs[2]);
        MEdge ed(ts[i]->getVertex(1), vs[2]);
        ecuts[ed] = index;
      }
      else if(vs[0] && vs[1] && !vs[2]) { // OK
        newt.push_back(new MTriangle(ts[i]->getVertex(0), vs[0], vs[1]));
        newt.push_back(new MTriangle(ts[i]->getVertex(1), vs[1], vs[0]));
        newt.push_back(
          new MTriangle(ts[i]->getVertex(0), vs[1], ts[i]->getVertex(2)));
        cut_edge(ecuts, ts[i]->getVertex(0), ts[i]->getVertex(1), vs[0]);
        cut_edge(ecuts, ts[i]->getVertex(2), ts[i]->getVertex(1), vs[1]);
        MEdge ed(vs[0], vs[1]);
        ecuts[ed] = index;
      }
      else if(vs[0] && !vs[1] && vs[2]) { // OK
        newt.push_back(new MTriangle(ts[i]->getVertex(0), vs[0], vs[2]));
        newt.push_back(new MTriangle(ts[i]->getVertex(2), vs[2], vs[0]));
        newt.push_back(
          new MTriangle(ts[i]->getVertex(2), vs[0], ts[i]->getVertex(1)));
        cut_edge(ecuts, ts[i]->getVertex(0), ts[i]->getVertex(1), vs[0]);
        cut_edge(ecuts, ts[i]->getVertex(2), ts[i]->getVertex(0), vs[2]);
        MEdge ed(vs[0], vs[2]);
        ecuts[ed] = index;
      }
      else if(!vs[0] && vs[1] && vs[2]) {
        newt.push_back(new MTriangle(ts[i]->getVertex(2), vs[2], vs[1]));
        newt.push_back(new MTriangle(ts[i]->getVertex(0), vs[1], vs[2]));
        newt.push_back(
          new MTriangle(ts[i]->getVertex(1), vs[1], ts[i]->getVertex(0)));
        cut_edge(ecuts, ts[i]->getVertex(1), ts[i]->getVertex(2), vs[1]);
        cut_edge(ecuts, ts[i]->getVertex(2), ts[i]->getVertex(0), vs[2]);
        MEdge ed(vs[1], vs[2]);
        ecuts[ed] = index;
      }
      else if(vs[0] && vs[1] && vs[2]) {
        newt.push_back(new MTriangle(vs[0], vs[1], vs[2]));
        newt.push_back(new MTriangle(ts[i]->getVertex(0), vs[0], vs[2]));
        newt.push_back(new MTriangle(ts[i]->getVertex(1), vs[1], vs[0]));
        newt.push_back(new MTriangle(ts[i]->getVertex(2), vs[2], vs[1]));
      }
      else {
        newt.push_back(ts[i]);
      }
    }
    //    printf("replcing %lu by %lu\n",ts.size(),newt.size());
    ts = newt;
  }

  void cutMesh(std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts)
  {
    auto it = cuts.begin();
    std::map<MEdge, int, MEdgeLessThan> ecuts;

    FILE *F = fopen("addedpoints.pos", "w");
    fprintf(F, "View \"\"{\n");
    for(; it != cuts.end(); ++it) { it->second.finish(gm, F); }

    for(size_t i = 0; i < f.size(); i++) {
      std::vector<MTriangle *> newT;
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        std::set<int> indices;
        std::multimap<int, std::pair<MVertex *, std::pair<int, int> > > tcuts;

        for(size_t k = 0; k < 3; k++) {
          MEdge e = f[i]->triangles[j]->getEdge(k);
          auto it = cuts.find(e);
          if(it != cuts.end()) {
            for(size_t l = 0; l < it->second.vs.size(); ++l) {
              std::pair<int, std::pair<MVertex *, std::pair<int, int> > > pp =
                std::make_pair(
                  it->second.indexOfCuts[l],
                  std::make_pair(it->second.vs[l],
                                 std::make_pair(k, it->second.idsOfCuts[l])));
              tcuts.insert(pp);
              indices.insert(it->second.indexOfCuts[l]);
            }
          }
        }

        auto iti = indices.begin();
        std::vector<MTriangle *> ttt;
        ttt.push_back(f[i]->triangles[j]);
        for(; iti != indices.end(); ++iti) {
          //	  if (*iti != 313310)continue;
          GEdge *ge = gm->getEdgeByTag(*iti);
          if(tcuts.count(*iti) == 1) {
            auto itt = tcuts.lower_bound(*iti);
            MVertex *v0 = itt->second.first;
            int k = itt->second.second.first;
            cutTriangles(ttt, f[i], v0,
                         f[i]->triangles[j]->getVertex((k + 2) % 3), ge, ecuts,
                         *iti, F);
          }
          else if(tcuts.count(*iti) == 2) {
            auto itt = tcuts.lower_bound(*iti);
            MVertex *v0 = itt->second.first;
            ++itt;
            MVertex *v1 = itt->second.first;
            cutTriangles(ttt, f[i], v0, v1, ge, ecuts, *iti, F);
          }
          else if(tcuts.count(*iti) == 3) {
            auto itt = tcuts.lower_bound(*iti);
            int k0 = itt->second.second.first;
            int id0 = itt->second.second.second;
            MVertex *v0 = itt->second.first;
            ++itt;
            int k1 = itt->second.second.first;
            int id1 = itt->second.second.second;
            MVertex *v1 = itt->second.first;
            ++itt;
            int k2 = itt->second.second.first;
            int id2 = itt->second.second.second;
            MVertex *v2 = itt->second.first;
            ;

            if(abs(id0 - id1) <= 2) {
              cutTriangles(ttt, f[i], v2,
                           f[i]->triangles[j]->getVertex((k2 + 2) % 3), ge,
                           ecuts, *iti, F);
              cutTriangles(ttt, f[i], v0, v1, ge, ecuts, *iti, F);
            }
            else if(abs(id0 - id2) <= 2) {
              cutTriangles(ttt, f[i], v1,
                           f[i]->triangles[j]->getVertex((k1 + 2) % 3), ge,
                           ecuts, *iti, F);
              cutTriangles(ttt, f[i], v0, v2, ge, ecuts, *iti, F);
            }
            else if(abs(id1 - id2) <= 2) {
              cutTriangles(ttt, f[i], v0,
                           f[i]->triangles[j]->getVertex((k0 + 2) % 3), ge,
                           ecuts, *iti, F);
              cutTriangles(ttt, f[i], v1, v2, ge, ecuts, *iti, F);
            }
            else {
              printf("BAD BEHAVIOR 3\n");
              printf("%lu %lu %lu \n", v0->getNum(), v1->getNum(),
                     v2->getNum());
              printf("%d %d %d\n", id0, id1, id2);
            }
          }
          else if(tcuts.count(*iti) == 4) {
            auto itt = tcuts.lower_bound(*iti);
            int id0 = itt->second.second.second;
            MVertex *v0 = itt->second.first;
            ++itt;
            int id1 = itt->second.second.second;
            MVertex *v1 = itt->second.first;
            ++itt;
            int id2 = itt->second.second.second;
            MVertex *v2 = itt->second.first;
            ++itt;
            int id3 = itt->second.second.second;
            MVertex *v3 = itt->second.first;
            if(abs(id0 - id1) <= 2 || abs(id2 - id3) <= 2) {
              cutTriangles(ttt, f[i], v0, v1, ge, ecuts, *iti, F);
              cutTriangles(ttt, f[i], v2, v3, ge, ecuts, *iti, F);
            }
            else if(abs(id0 - id2) <= 2 || abs(id1 - id3) <= 2) {
              cutTriangles(ttt, f[i], v0, v2, ge, ecuts, *iti, F);
              cutTriangles(ttt, f[i], v1, v3, ge, ecuts, *iti, F);
            }
            else if(abs(id0 - id3) <= 2 || abs(id1 - id2) <= 2) {
              cutTriangles(ttt, f[i], v0, v3, ge, ecuts, *iti, F);
              cutTriangles(ttt, f[i], v1, v2, ge, ecuts, *iti, F);
            }
            else {
              printf("%d %d %d %d\n", id0, id1, id2, id3);
            }
          }
          else if(tcuts.count(*iti) == 6) {
            auto itt = tcuts.lower_bound(*iti);
            std::pair<int, MVertex *> id[10];
            for(std::size_t kk = 0; kk < tcuts.count(*iti); kk++) {
              id[kk] =
                std::make_pair(itt->second.second.second, itt->second.first);
              ++itt;
            }
            std::sort(id, id + 6);
            cutTriangles(ttt, f[i], id[0].second, id[1].second, ge, ecuts, *iti,
                         F);
            cutTriangles(ttt, f[i], id[2].second, id[3].second, ge, ecuts, *iti,
                         F);
            cutTriangles(ttt, f[i], id[4].second, id[5].second, ge, ecuts, *iti,
                         F);
            printf("%d %d %d %d %d %d\n", id[0].first, id[1].first, id[2].first,
                   id[3].first, id[4].first, id[5].first);
          }
          else {
            Msg::Error("TODO %lu in CutMesh !!!!!!!", tcuts.count(*iti));
          }
        }
        newT.insert(newT.begin(), ttt.begin(), ttt.end());
      }
      f[i]->triangles = newT;
    }

    fprintf(F, "};\n");
    fclose(F);

    F = fopen("edges.pos", "w");
    fprintf(F, "View \"\"{\n");

    for(auto it = ecuts.begin(); it != ecuts.end(); ++it) {
      GEdge *ge = gm->getEdgeByTag(it->second);
      ge->lines.push_back(
        new MLine(it->first.getVertex(0), it->first.getVertex(1)));
      fprintf(F, "SL(%g,%g,%g,%g,%g,%g){1,1};\n", it->first.getVertex(0)->x(),
              it->first.getVertex(0)->y(), it->first.getVertex(0)->z(),
              it->first.getVertex(1)->x(), it->first.getVertex(1)->y(),
              it->first.getVertex(1)->z());
      for(int i = 0; i < 2; i++) {
        if(std::find(ge->mesh_vertices.begin(), ge->mesh_vertices.end(),
                     it->first.getVertex(i)) == ge->mesh_vertices.end()) {
          ge->mesh_vertices.push_back(it->first.getVertex(i));
          it->first.getVertex(i)->setEntity(ge);
        }
      }
    }
    fprintf(F, "};\n");
    fclose(F);
    CTX::instance()->mesh.changed = ENT_ALL;
  }

  int correctionOnCutGraph(
    std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts,
    std::map<MVertex *, MVertex *, MVertexPtrLessThan> &new2old)
  {
    std::map<MEdge, MEdge, MEdgeLessThan> duplicateEdges;

    for(auto it = cuts.begin(); it != cuts.end(); ++it) {
      MVertex *v0 = it->first.getVertex(0);
      MVertex *v1 = it->first.getVertex(1);
      MVertex *v2 = new2old.find(v0) == new2old.end() ? v0 : new2old[v0];
      MVertex *v3 = new2old.find(v1) == new2old.end() ? v1 : new2old[v1];
      MEdge e0(v0, v1);
      MEdge e1(v2, v3);
      duplicateEdges[e0] = e1;
    }

    for(auto it2 = duplicateEdges.begin(); it2 != duplicateEdges.end(); ++it2) {
      auto it3 = cuts.find(it2->first);
      auto it4 = cuts.find(it2->second);
      if(it3 != cuts.end() && it4 == cuts.end()) {
        cuts[it2->second] = it3->second;
      }
      else if(it4 != cuts.end() && it3 == cuts.end()) {
        cuts[it2->first] = it4->second;
      }
      else if(it4 != cuts.end() && it3 != cuts.end()) {
        it4->second.vs.insert(it4->second.vs.begin(), it3->second.vs.begin(),
                              it3->second.vs.end());
        it4->second.indexOfCuts.insert(it4->second.indexOfCuts.begin(),
                                       it3->second.indexOfCuts.begin(),
                                       it3->second.indexOfCuts.end());
        it3->second.vs.insert(it3->second.vs.begin(), it4->second.vs.begin(),
                              it4->second.vs.end());
        it3->second.indexOfCuts.insert(it3->second.indexOfCuts.begin(),
                                       it4->second.indexOfCuts.begin(),
                                       it4->second.indexOfCuts.end());
      }
    }
    return 0;
  }

  int computeQuadLayout(std::map<MVertex *, double> &potU,
                        std::map<MVertex *, double> &potV,
                        std::map<MEdge, MEdge, MEdgeLessThan> &duplicateEdges,
                        std::map<MEdge, edgeCuts, MEdgeLessThan> &cuts)
  {
    std::vector<cutGraphPassage> passages;
    while(1) {
      computePotential(gm, f, *myAssembler, C, new2old, groups, duplicateEdges,
                       d0, d1, G, potU, potV, passages);

      if(computeIsos(gm, f, singularities, C, new2old, duplicateEdges, groups,
                     groups_cg, potU, potV, cutG, G, cuts, passages) == true) {
        printf("COMPUTE ISOS DONE\n");
        break;
      }
      break;
    }

    correctionOnCutGraph(cuts, new2old);

    double MAXX = 0.;
    for(size_t i = 0; i < groups_cg.size(); i++) {
      double MAXD1 = -1.e22, MIND1 = 1.e22, MAXD2 = -1.e22, MIND2 = 1.e22;
      for(size_t j = 0; j < G[i].left.size(); j++) {
        double Ul = potU[G[i].left[j]];
        double Ur = potU[G[i].right[j]];
        double Vl = potV[G[i].left[j]];
        double Vr = potV[G[i].right[j]];
        double D1 = Ul - G[i].mat[0][0] * Ur - G[i].mat[0][1] * Vr;
        double D2 = Vl - G[i].mat[1][0] * Ur - G[i].mat[1][1] * Vr;
        MAXD1 = std::max(D1, MAXD1);
        MAXD2 = std::max(D2, MAXD2);
        MIND1 = std::min(D1, MIND1);
        MIND2 = std::min(D2, MIND2);
      }

      Msg::Debug("group %3d ROT (%12.5E %12.5E) (%12.5E %12.5E)", G[i].groupId,
                 G[i].mat[0][0], G[i].mat[0][1], G[i].mat[1][0],
                 G[i].mat[1][1]);

      Msg::Debug("group %3d DA(%12.5E %12.5E %12.5E) D2(%12.5E %12.5E %12.5E)",
                 G[i].groupId, MAXD1, MIND1, MAXD1 - MIND1, MAXD2, MIND2,
                 MAXD2 - MIND2);
      MAXX = std::max(MAXD2 - MIND2, MAXX);
    }
    if(MAXX < 1.e-09)
      Msg::Info("Success in computing potentials (all jumps are OK)");
    else
      Msg::Warning("Quad Layout Failure");
    return 0;
  }
};

static void findPhysicalGroupsForSingularities(GModel *gm,
                                               std::vector<GFace *> &f,
                                               std::map<MVertex *, int> &temp)
{
  std::map<int, std::vector<GEntity *> > groups[4];
  gm->getPhysicalGroups(groups);
  for(auto it = groups[0].begin(); it != groups[0].end(); ++it) {
    std::string name = gm->getPhysicalName(0, it->first);
    if(name == "SINGULARITY_OF_INDEX_THREE") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty())
          temp[it->second[j]->mesh_vertices[0]] = 1;
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_FIVE") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty())
          temp[it->second[j]->mesh_vertices[0]] = -1;
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_SIX") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty())
          temp[it->second[j]->mesh_vertices[0]] = -2;
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_EIGHT") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty())
          temp[it->second[j]->mesh_vertices[0]] = -4;
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_TWO") {
      for(size_t j = 0; j < it->second.size(); j++) {
        if(!it->second[j]->mesh_vertices.empty())
          temp[it->second[j]->mesh_vertices[0]] = 2;
      }
    }
  }
}

static int computeCrossFieldAndH(GModel *gm, std::vector<GFace *> &f,
                                 std::vector<int> &tags, bool layout = true)
{
  quadLayoutData qLayout(gm, f, gm->getName());
  std::map<MVertex *, int> temp;
  std::map<int, std::vector<double> > dataH;
  std::map<int, std::vector<double> > dataTHETA;
  std::map<int, std::vector<double> > dataDir;
  std::map<int, std::vector<double> > dataDirOrtho;
  std::map<int, std::vector<double> > dataU;
  std::map<int, std::vector<double> > dataV;
  std::map<MVertex *, double> potU, potV;
  findPhysicalGroupsForSingularities(gm, f, temp);
  std::map<MEdge, MEdge, MEdgeLessThan> duplicateEdges;
  std::map<MEdge, edgeCuts, MEdgeLessThan> cuts;
  if(temp.size()) {
    Msg::Info("Computing cross field from %d prescribed singularities",
              temp.size());
    qLayout.computeCrossFieldAndH(&temp, dataTHETA);
    qLayout.computeCutGraph(duplicateEdges);
  }
  else {
    Msg::Info("Computing a cross field");
    qLayout.computeCrossFieldAndH();
    qLayout.computeCutGraph(duplicateEdges);
    qLayout.computeThetaUsingHCrouzeixRaviart(dataTHETA);
  }
  if(layout) { qLayout.computeQuadLayout(potU, potV, duplicateEdges, cuts); }

  PViewDataGModel *d = new PViewDataGModel;
  PViewDataGModel *dt = new PViewDataGModel(PViewDataGModel::ElementNodeData);
  PViewDataGModel *dd = new PViewDataGModel(PViewDataGModel::ElementData);
  std::string name = gm->getName() + "_H";
  d->setName(name);
  d->setFileName(name + ".msh");
  name = gm->getName() + "_Theta";
  dt->setName(name);
  dt->setFileName(name + ".msh");
  name = gm->getName() + "_Directions";
  dd->setName(name);
  dd->setFileName(name + ".msh");
  PViewDataGModel *U = nullptr;
  PViewDataGModel *V = nullptr;
  if(layout) {
    U = new PViewDataGModel(PViewDataGModel::ElementNodeData);
    V = new PViewDataGModel(PViewDataGModel::ElementNodeData);
    name = gm->getName() + "_U";
    U->setName(name);
    U->setFileName(name + ".msh");
    name = gm->getName() + "_V";
    V->setName(name);
    V->setFileName(name + ".msh");

    for(size_t i = 0; i < f.size(); i++) {
      for(size_t j = 0; j < f[i]->triangles.size(); j++) {
        MTriangle *t = f[i]->triangles[j];
        double a = potU[f[i]->triangles[j]->getVertex(0)];
        double b = potU[f[i]->triangles[j]->getVertex(1)];
        double c = potU[f[i]->triangles[j]->getVertex(2)];
        std::vector<double> ts;
        ts.push_back(a);
        ts.push_back(b);
        ts.push_back(c);
        dataU[t->getNum()] = ts;
        a = potV[f[i]->triangles[j]->getVertex(0)];
        b = potV[f[i]->triangles[j]->getVertex(1)];
        c = potV[f[i]->triangles[j]->getVertex(2)];
        ts.clear();
        ts.push_back(a);
        ts.push_back(b);
        ts.push_back(c);
        dataV[t->getNum()] = ts;
      }
    }

    U->addData(gm, dataU, 0, 0.0, 1, 1);
    U->finalize();
    V->addData(gm, dataV, 0, 0.0, 1, 1);
    V->finalize();
  }
  for(auto it = qLayout.d0.begin(); it != qLayout.d0.end(); ++it) {
    std::vector<double> jj;
    jj.push_back(it->second.x());
    jj.push_back(it->second.y());
    jj.push_back(it->second.z());
    dataDir[it->first->getNum()] = jj;
  }
  for(auto it = qLayout.d1.begin(); it != qLayout.d1.end(); ++it) {
    std::vector<double> jj;
    jj.push_back(it->second.x());
    jj.push_back(it->second.y());
    jj.push_back(it->second.z());
    dataDirOrtho[it->first->getNum()] = jj;
  }
  for(auto it = qLayout.vs.begin(); it != qLayout.vs.end(); ++it) {
    double h;
    qLayout.myAssembler->getDofValue(*it, 0, 1, h);
    std::vector<double> jj;
    jj.push_back(h);
    //    printf("adding data for %lu\n",(*it)->getNum());
    dataH[(*it)->getNum()] = jj;
  }

  d->addData(gm, dataH, 0, 0.0, 1, 1);
  d->finalize();
  dt->addData(gm, dataTHETA, 0, 0.0, 1, 1);
  dt->finalize();
  dd->addData(gm, dataDir, 0, 0.0, 1, 3);
  dd->addData(gm, dataDirOrtho, 1, 0.0, 1, 3);
  dd->finalize();

  std::string posout = gm->getName() + "_QLayoutResults.pos";

  qLayout.restoreInitialMesh();
  dt->writePOS(posout, false, true, true);
  dd->writePOS(posout, false, true, true);
  d->writePOS(posout, false, true, true);
  if(layout) {
    U->writePOS(posout, false, true, true);
    V->writePOS(posout, false, true, true);
  }
  //  return 0;
  Msg::Info("Cutting the mesh");

  qLayout.cutMesh(cuts);

  Msg::Info("Classifying the model");
  discreteEdge *de = new discreteEdge(
    GModel::current(), GModel::current()->getMaxElementaryNumber(1) + 1,
    nullptr, nullptr);
  GModel::current()->add(de);
  computeNonManifoldEdges(GModel::current(), de->lines, true);
  classifyFaces(GModel::current(), M_PI / 4 * .999);
  GModel::current()->remove(de);
  //  delete de;
  GModel::current()->pruneMeshVertexAssociations();

  std::string mshout = gm->getName() + "_Cut.msh";
  gm->writeMSH(mshout, 4.0, false, true);

  int countError = 0;
  for(auto it = GModel::current()->firstFace();
      it != GModel::current()->lastFace(); it++) {
    if((*it)->edges().size() != 4) {
      Msg::Warning("quad layout failed : face %lu has %lu boundaries",
                   (*it)->tag(), (*it)->edges().size());
      countError++;
    }
  }
  if(!countError) {
    Msg::Info(
      "Quad layout success : the model is partitioned in %d master quads",
      GModel::current()->getNumFaces());
    Msg::Info("Partitioned mesh has been saved in %s", mshout.c_str());
    Msg::Info("Result of computations have been saved in %s", posout.c_str());
  }
  delete d;
  delete dd;
  delete dt;
  if(layout) {
    delete U;
    delete V;
  }

  return 0;
}

#endif

static void getFacesOfTheModel(GModel *gm, std::vector<GFace *> &f)
{
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    GFace *gf = *it;
    f.push_back(gf);
  }
}

int computeCrossFieldAndH(GModel *gm, std::vector<int> &tags)
{
  std::vector<GFace *> f;
  getFacesOfTheModel(gm, f);
#if defined(HAVE_SOLVER) && defined(HAVE_POST)
  return computeCrossFieldAndH(gm, f, tags);
#else
  Msg::Error("Cross field computation requires solver and post-pro module");
  return -1;
#endif
}

int computeQuadLayout(GModel *gm, std::vector<int> &tags)
{
  std::vector<GFace *> f;
  getFacesOfTheModel(gm, f);

#if defined(HAVE_SOLVER) && defined(HAVE_POST)
  return computeCrossFieldAndH(gm, f, tags, true);
#else
  Msg::Error("Cross field computation requires solver and post-pro module");
  return -1;
#endif
}

int computeCrossField(GModel *gm, std::vector<int> &tags)
{
  std::vector<GFace *> f;
  getFacesOfTheModel(gm, f);

#if defined(HAVE_SOLVER) && defined(HAVE_POST)
  return computeCrossFieldAndH(gm, f, tags, true);
  // return computeQuadLayout(gm, f);
#else
  Msg::Error("Cross field computation requires solver and post-pro module");
  return -1;
#endif
}
