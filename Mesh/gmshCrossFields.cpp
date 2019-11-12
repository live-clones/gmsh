// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <stack>
#include <queue>
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

#if defined(_OPENMP)
#include <omp.h>
#endif

#if defined(HAVE_SOLVER)
#include "dofManager.h"
#include "laplaceTerm.h"
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
  bool rotation;
  //  int cutGraphPart;
  size_t counter;
  SVector3 o_i; // orientation vector
  SVector3 _nrml, _tgt, _tgt2; // local system of coordinates
  std::vector<MEdge> _neighbors;
  std::vector<cross2d *> _cneighbors;
  double da[4];
  double _C[4], _S[4];
  // euler angles
  double _a, _b, _c;
  double _atemp, _btemp, _ctemp;
  std::vector<MTriangle *> _t;
  cross2d(MEdge &e, MTriangle *r, MEdge &e1, MEdge &e2)
    : _e(e), inCutGraph(false), inBoundary(false), _a(0), _b(0), _c(0)
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
      if(!inBoundary) {
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
        _C[i] = cos(4 * da[i]);
        _S[i] = sin(4 * da[i]);
      }
    }
  }

  void finish(std::map<MEdge, cross2d, Less_Edge> &C)
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
        if(dot(xx, yy) < .5) inBoundary = 1;
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

    for(size_t i = 0; i < _neighbors.size(); i++) {
      std::map<MEdge, cross2d, Less_Edge>::iterator it = C.find(_neighbors[i]);
      if(it == C.end())
        Msg::Error("impossible situation");
      else
        _cneighbors.push_back(&(it->second));
    }
    if(_cneighbors.size() != 4) {
      inBoundary = true;
      _a = 0;
      _atemp = _a;
    }
    _neighbors.clear();
    _b = _btemp = sin(4 * _a);
    _c = _ctemp = cos(4 * _a);
  }
  double average_init()
  {
    if(!inBoundary) {
      _btemp = 0;
      _ctemp = 0;
      for(int i = 0; i < 4; i++) {
        _ctemp += (_cneighbors[i]->_c * _C[i] - _cneighbors[i]->_b * _S[i]);
        _btemp += (_cneighbors[i]->_c * _S[i] + _cneighbors[i]->_b * _C[i]);
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
    if(!inBoundary) {
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
                           std::set<MEdge, Less_Edge> &cutG,
                           std::set<MVertex *> &sing, std::set<MVertex *> &bnd)
{
  // store in _atemp the branch of the neighbor
  std::set<MVertex *> cg;
  {
    std::set<MEdge, Less_Edge>::iterator it = cutG.begin();
    for(; it != cutG.end(); ++it) {
      cg.insert(it->getVertex(0));
      cg.insert(it->getVertex(1));
    }
  }
  std::stack<cross2d *> _s;
  _s.push(first);
  first->_atemp = first->_a + branch * M_PI / 2.0;
  first->_btemp = 10000.;
  while(!_s.empty()) {
    cross2d *c = _s.top();
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
          if(((s0 && c1) || (s0 && b1)) || ((s1 && c0) || (s1 && b0))) {
            printf("BLOCKED \n");
          }

          if((!s0 && !s1)) _s.push(n);
          n->_atemp = a2;
        }
      }
    }
  }
}

struct groupOfCross2d {
  int groupId;
  bool rot;
  double sign0, sign1;
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

#if 0
static void duplicateNodesInCutGraph2(
  std::vector<GFace *> &f, std::map<MEdge, cross2d, Less_Edge> &C,
  std::map<MVertex *, MVertex *> &new2old,
  std::map<MVertex *, MVertex *> &old2new,
  std::map<MEdge, MEdge, Less_Edge> &duplicateEdges, std::set<MVertex *> &sing,
  v2t_cont &adj, std::vector<groupOfCross2d> &G)
{
  for(size_t i = 0; i < G.size(); i++) {
    printf("GROUP %d ROTATES %d\n", G[i].groupId, G[i].rot);
    for(size_t j = 0; j < G[i].vertices.size(); j++) {
      MVertex *v = G[i].vertices[j];
      MVertex *vnew = new MVertex(v->x(), v->y(), v->z(), f[0]);
      new2old[vnew] = v;
      old2new[v] = vnew;
      f[0]->mesh_vertices.push_back(vnew);
    }
    for(size_t k = 0; k < G[i].side.size(); k++) {
      for(size_t j = 0; j < 3; j++) {
        MEdge e = G[i].side[k]->getEdge(j);
        std::map<MVertex *, MVertex *>::iterator it0 =
          old2new.find(e.getVertex(0));
        std::map<MVertex *, MVertex *>::iterator it1 =
          old2new.find(e.getVertex(1));
        if(it0 != old2new.end() && it1 != old2new.end())
          duplicateEdges[e] = MEdge(it0->second, it1->second);
        else if(it0 == old2new.end() && it1 != old2new.end())
          duplicateEdges[e] = MEdge(e.getVertex(0), it1->second);
        else if(it0 != old2new.end() && it1 == old2new.end())
          duplicateEdges[e] = MEdge(it0->second, e.getVertex(1));
      }
      for(size_t j = 0; j < 3; j++) {
        std::map<MVertex *, MVertex *>::iterator it =
          old2new.find(G[i].side[k]->getVertex(j));
        if(it != old2new.end()) G[i].side[k]->setVertex(j, it->second);
      }
    }
  }
}
#endif

static void duplicateNodesInCutGraph(
  std::vector<GFace *> &f, std::map<MEdge, cross2d, Less_Edge> &C,
  std::map<MVertex *, MVertex *> &new2old,
  std::map<MVertex *, MVertex *> &old2new,
  std::map<MEdge, MEdge, Less_Edge> &duplicateEdges, std::set<MVertex *> &sing,
  v2t_cont &adj, std::vector<groupOfCross2d> &G)
{
  FILE *_f = fopen("nodes.pos", "w");
  fprintf(_f, "View \" nodes \"{\n");

  v2t_cont::iterator it = adj.begin();
  std::set<MElement *> touched;
  std::set<MVertex *> vtouched;

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
          std::map<MEdge, cross2d, Less_Edge>::iterator it0 = C.find(e0);
          if(!it0->second.inCutGraph) {
            for(size_t j = 0; j < it0->second._t.size(); j++) {
              std::vector<MElement *>::iterator ite =
                std::find(els.begin(), els.end(), it0->second._t[j]);
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
        //	if (it->first->getNum() != 268){
        MVertex *v =
          new MVertex(it->first->x(), it->first->y(), it->first->z(), f[0]);
        new2old[v] = it->first;
        old2new[it->first] = v;
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
        //      printf("found vertex with %d on one side\n",els.size());
        //	}
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
    e->setVertex(j, v);
  }
}

static void print_H_and_Cross(GModel *gm, std::vector<GFace *> &f,
                              std::map<MEdge, cross2d, Less_Edge> &C,
                              dofManager<double> &dof,
                              std::set<MVertex *> &singularities)
{
  std::string ss = gm->getName();
  std::string fn = ss + ".out";

  FILE *_f = fopen(fn.c_str(), "w");

  std::set<MVertex *, MVertexLessThanNum> vs;
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      for(size_t k = 0; k < 3; k++) { vs.insert(t->getVertex(k)); }
    }
  }
  fprintf(_f, "%lu", vs.size());
  for(std::set<MVertex *, MVertexLessThanNum>::iterator it = vs.begin();
      it != vs.end(); ++it) {
    double a;
    dof.getDofValue(*it, 0, 1, a);
    fprintf(_f, "%lu %12.5E\n", (*it)->getNum(), a);
  }
  fprintf(_f, "%lu", singularities.size());
  for(std::set<MVertex *>::iterator it = singularities.begin();
      it != singularities.end(); ++it) {
    fprintf(_f, "%lu\n", (*it)->getNum());
  }
  fprintf(_f, "%lu", C.size());
  for(std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
      it != C.end(); ++it) {
    fprintf(_f, "%lu %lu %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E\n",
            it->first.getVertex(0)->getNum(), it->first.getVertex(1)->getNum(),
            it->second._nrml.x(), it->second._nrml.y(), it->second._nrml.z(),
            it->second.o_i.x(), it->second.o_i.y(), it->second.o_i.z());
  }
  fclose(_f);
}

static void
computeUniqueVectorPerTriangle(GModel *gm, std::vector<GFace *> &f,
                               std::map<MEdge, cross2d, Less_Edge> &C, int dir,
                               std::map<MTriangle *, SVector3> &d)
{
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      SVector3 a0(0, 0, 0);
      int n = 0;
      for(int k = 0; k < 3; k++) {
        MEdge e = t->getEdge(k);
        std::map<MEdge, cross2d, Less_Edge>::iterator it = C.find(e);
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

static void createLagrangeMultipliers(dofManager<double> &myAssembler,
                                      groupOfCross2d &g)
{
  if(g.singularities.size() == 1) {
    printf("group id %d singularity %lu (%lu)\n", g.groupId,
           g.singularities[0]->getNum(), g.singularities.size());
    myAssembler.numberVertex(g.singularities[0], 0, 33);
    myAssembler.numberVertex(g.singularities[0], 0, 34);
  }
  else {
    printf("group id %d %lu singularities \n", g.groupId,
           g.singularities.size());
  }
  for(size_t K = 1; K < g.left.size(); K++) {
    myAssembler.numberVertex(g.left[K], 0, 3);
    myAssembler.numberVertex(g.left[K], 0, 4);
  }
}

static void assembleLagrangeMultipliers(dofManager<double> &myAssembler,
                                        groupOfCross2d &g)
{
  Dof U1R(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
  Dof V1R(g.left[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));
  Dof U2R(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 1));
  Dof V2R(g.right[0]->getNum(), Dof::createTypeWithTwoInts(0, 2));

  //  printf("GROUP %d\n",g.groupId);
  //  printf("LEFT --- RIGHT\n");
  //  printf("%3lu %3lu\n",g.left[0]->getNum(),g.right[0]->getNum());

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

  for(size_t K = 1; K < g.left.size(); K++) {
    // printf("%3lu %3lu\n",g.left[K]->getNum(),g.right[K]->getNum());
    // EQUATION IDS (Lagrange multipliers)
    Dof E1(g.left[K]->getNum(), Dof::createTypeWithTwoInts(0, 3));
    Dof E2(g.left[K]->getNum(), Dof::createTypeWithTwoInts(0, 4));

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
                     std::map<MEdge, cross2d, Less_Edge> &C,
                     std::vector<std::vector<cross2d *> > &groups,
                     std::map<MEdge, MEdge, Less_Edge> &duplicateEdges,
                     bool assemble)
{
  for(size_t i = 0; i < groups.size(); i++) {
    size_t N = groups[i].size();
    MEdge ed = groups[i][0]->_e;
    std::map<MEdge, MEdge, Less_Edge>::iterator ite = duplicateEdges.find(ed);
    if(ite != duplicateEdges.end()) ed = ite->second;
    MVertex *v = ed.getVertex(0);
    std::map<MEdge, cross2d, Less_Edge>::iterator it = C.find(groups[i][0]->_e);
    double S = (NUMDOF == 2) ? sin(it->second._atemp) : cos(it->second._atemp);
    if(fabs(S) > .8) {
      for(size_t j = 0; j < N; j++) {
        ed = groups[i][j]->_e;
        ite = duplicateEdges.find(ed);
        if(ite != duplicateEdges.end()) ed = ite->second;
        for(int k = 0; k < 2; k++) {
          MVertex *vk = ed.getVertex(k);
          if(vk != v) {
            if(!assemble) { myAssembler.numberVertex(vk, 0, 5); }
            else {
              Dof Eref(vk->getNum(), Dof::createTypeWithTwoInts(0, 5));
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

static void createDofs(dofManager<double> &myAssembler, int NUMDOF,
                       std::set<MVertex *> &vs)
{
  for(std::set<MVertex *>::iterator it = vs.begin(); it != vs.end(); ++it)
    myAssembler.numberVertex(*it, 0, NUMDOF);
}

static void computePotential(GModel *gm, std::vector<GFace *> &f,
                             const char *outputName, const char *outputName2,
                             dofManager<double> &dof,
                             std::map<MEdge, cross2d, Less_Edge> &C,
                             std::map<MVertex *, MVertex *> &new2old,
                             std::vector<std::vector<cross2d *> > &groups,
                             std::map<MEdge, MEdge, Less_Edge> &duplicateEdges,
                             std::map<MTriangle *, SVector3> &lift,
                             std::map<MTriangle *, SVector3> &lift2,
                             std::vector<groupOfCross2d> &G,
                             std::map<MVertex *, double> &res,
                             std::map<MVertex *, double> &res2)
{
  double a[3];
  std::set<MVertex *> vs;
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      for(size_t k = 0; k < 3; k++) { vs.insert(t->getVertex(k)); }
    }
  }

#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *_lsys = new linearSystemCSRGmm<double>;
  //  _lsys->setGmres(0);
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif

  dofManager<double> myAssembler(_lsys);

  //  int NUMDOF = dir+1;

  createDofs(myAssembler, 1, vs);
  createDofs(myAssembler, 2, vs);
  LagrangeMultipliers2(myAssembler, 1, C, groups, duplicateEdges, false);
  LagrangeMultipliers2(myAssembler, 2, C, groups, duplicateEdges, false);

  for(size_t i = 0; i < G.size(); i++)
    createLagrangeMultipliers(myAssembler, G[i]);

  LagrangeMultipliers2(myAssembler, 1, C, groups, duplicateEdges, true);
  LagrangeMultipliers2(myAssembler, 2, C, groups, duplicateEdges, true);
  for(size_t i = 0; i < G.size(); i++)
    assembleLagrangeMultipliers(myAssembler, G[i]);

  simpleFunction<double> ONE(1.0);
  laplaceTerm l(NULL, 1, &ONE);
  laplaceTerm l2(NULL, 2, &ONE);

  //  char name[234];
  //  sprintf(name,"vperelem%d.pos",dir);
  //  FILE *__f = fopen(name,"w");
  //  fprintf(__f,"View \"\"{\n");

  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      SElement se(t);
      l.addToMatrix(myAssembler, &se);
      l2.addToMatrix(myAssembler, &se);
      SVector3 a0 = lift[t];
      SVector3 a1 = lift2[t];
      double va, vb, vc;
      std::map<MVertex *, MVertex *>::iterator itx =
        new2old.find(t->getVertex(0));
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
  //  fprintf(__f,"};\n");
  //  fclose(__f);
  printf("%d unknowns\n", myAssembler.sizeOfR());
  _lsys->systemSolve();

  FILE *_f = fopen(outputName, "w");
  fprintf(_f, "View \"V\"{\n");
  FILE *_f1 = fopen(outputName2, "w");
  fprintf(_f1, "View \"V\"{\n");

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
      res[t->getVertex(0)] = a;
      res[t->getVertex(1)] = b;
      res[t->getVertex(2)] = c;
      res2[t->getVertex(0)] = a1;
      res2[t->getVertex(1)] = b1;
      res2[t->getVertex(2)] = c1;

      fprintf(_f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
              t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
              t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              a, b, c);
      fprintf(_f1, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
              t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
              t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              a1, b1, c1);
    }
  }
  fprintf(_f, "};\n");
  fclose(_f);
  fprintf(_f1, "};\n");
  fclose(_f1);
  /*
  for (size_t i=0;i<G.size();i++){
    printf("group %d sign %12.5E %12.5E\n",G[i].groupId,G[i].sign0,G[i].sign1);
    for (size_t j=0;j<G[i].left.size();j++){
      double a, b;
      myAssembler.getDofValue(G[i].left[j], 0, 1, a);
      myAssembler.getDofValue(G[i].right[j], 0, 2, b);
      printf("JUMP %12.5E - %12.5E = %12.5E ",a,b,a-b);
      myAssembler.getDofValue(G[i].left[j], 0, 2, a);
      myAssembler.getDofValue(G[i].right[j], 0, 1, b);
      printf("---- %12.5E - %12.5E = %12.5E\n",a,b,a-b);
    }
  }
  */
}

static double distance(MTriangle *t, std::set<MVertex *> &boundaries)
{
  //  return drand48();
  SPoint3 p = t->barycenter();
  double dmin = 1.e22;
  for(std::set<MVertex *>::iterator it = boundaries.begin();
      it != boundaries.end(); ++it) {
    SPoint3 pp((*it)->x(), (*it)->y(), (*it)->z());
    double d = p.distance(pp);
    if(d < dmin) { dmin = d; }
  }
  return -dmin;
}

static bool isSingular(MVertex *v, std::vector<cross2d *> &adj, double &MAX)
{
  const std::size_t TEST = 0;
  if(v->getNum() == TEST) printf("VERTEX %lu\n", v->getNum());
  SVector3 n(0, 0, 0);
  for(size_t i = 0; i < adj.size(); i++) { n += adj[i]->_nrml; }
  n.normalize();
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
  return MAX > .5;
}

static void computeSingularities(std::map<MEdge, cross2d, Less_Edge> &C,
                                 std::set<MVertex *> &singularities)
{
  FILE *f_ = fopen("sing.pos", "w");
  fprintf(f_, "View \"S\"{\n");
  std::multimap<MVertex *, cross2d *> conn;
  for(std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
      it != C.end(); ++it) {
    std::pair<MVertex *, cross2d *> p =
      std::make_pair(it->first.getVertex(0), &it->second);
    conn.insert(p);
    p = std::make_pair(it->first.getVertex(1), &it->second);
    conn.insert(p);
  }
  MVertex *v = NULL;
  std::vector<cross2d *> adj;
  for(std::multimap<MVertex *, cross2d *>::iterator it = conn.begin();
      it != conn.end(); ++it) {
    if(it->first == v) { adj.push_back(it->second); }
    else {
      double MAX;
      if(v && isSingular(v, adj, MAX)) {
        singularities.insert(v);
        fprintf(f_, "SP(%g,%g,%g){%12.5E};\n", v->x(), v->y(), v->z(), MAX);
      }
      adj.clear();
      v = it->first;
      adj.push_back(it->second);
    }
  }
  fprintf(f_, "};\n");
  fclose(f_);
}

static void cutGraph(std::map<MEdge, cross2d, Less_Edge> &C,
                     dofManager<double> &dof, std::set<MEdge, Less_Edge> &cutG,
                     std::set<MVertex *> &singularities,
                     std::set<MVertex *> &boundaries)
{
  std::set<MTriangle *> touched;
  std::vector<cross2d *> tree;
  std::vector<MEdge> cotree;
  std::set<std::pair<double, MTriangle *> > _distances;
  {
    std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
    for(; it != C.end(); ++it) {
      if(it->second._t.size() == 1) {
        boundaries.insert(it->first.getVertex(0));
        boundaries.insert(it->first.getVertex(1));
      }
    }
  }
  std::set<MVertex *> _all = boundaries;
  _all.insert(singularities.begin(), singularities.end());

  MTriangle *t = (C.begin())->second._t[0];
  std::pair<double, MTriangle *> pp = std::make_pair(distance(t, _all), t);
  _distances.insert(pp);
  touched.insert(t);
  while(!_distances.empty()) {
    t = (_distances.begin()->second);
    _distances.erase(_distances.begin());

    for(int i = 0; i < 3; i++) {
      MEdge e = t->getEdge(i);
      std::map<MEdge, cross2d, Less_Edge>::iterator it = C.find(e);
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
  std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
  std::map<MVertex *, std::vector<MEdge> > _graph;
  std::map<MVertex *, std::vector<MEdge> > _all_graph;
  for(; it != C.end(); ++it) {
    for(int i = 0; i < 2; i++) {
      std::map<MVertex *, std::vector<MEdge> >::iterator it0 =
        _all_graph.find(it->first.getVertex(i));
      if(it0 == _all_graph.end()) {
        std::vector<MEdge> ee;
        ee.push_back(it->first);
        _all_graph[it->first.getVertex(i)] = ee;
      }
      else
        it0->second.push_back(it->first);
    }
    if(!std::binary_search(tree.begin(), tree.end(), &it->second)) {
      for(int i = 0; i < 2; i++) {
        std::map<MVertex *, std::vector<MEdge> >::iterator it0 =
          _graph.find(it->first.getVertex(i));
        if(it0 == _graph.end()) {
          std::vector<MEdge> ee;
          ee.push_back(it->first);
          _graph[it->first.getVertex(i)] = ee;
        }
        else
          it0->second.push_back(it->first);
      }
      cotree.push_back(it->first);
    }
  }
  /*
{
  //    FILE *f_ = fopen ("sing.pos","w");
  //    fprintf(f_, "View \"S\"{\n");
  //   compute singularities
  std::map<MVertex*,std::vector<MEdge> >::iterator it = _all_graph.begin();
  for (; it != _all_graph.end(); ++it){
  MVertex *v = it->first;
  double hV;
  dof.getDofValue(v, 0, 1, hV);
  bool isMin = true;
  bool isMax = true;
  double GRR = 0;
  for (size_t i=0;i<it->second.size();i++){

  std::map<MEdge,cross2d,Less_Edge >::iterator itee = C.find(it->second[i]);
  GRR = std::max(GRR,itee->second.grad());

  MVertex *o = it->second[i].getVertex(0) == v ? it->second[i].getVertex(1) :
it->second[i].getVertex(0); double hI; dof.getDofValue(o, 0, 1, hI); if (hI >
hV)isMax = false; if (hI < hV)isMin = false;
  }
    if ((isMax || isMin)){
    //	fprintf(f_,"SP(%g,%g,%g){%d};\n",v->x(),v->y(),v->z(),isMax ? 1:-1);
  //	singularities.insert(v);
  }
    else {
    //	singularities.erase(v);
  }
  }
  //    fprintf(f_, "};\n");
  //    fclose(f_);
  }
  */
  {
    std::set<MVertex *>::iterator it = boundaries.begin();
    for(; it != boundaries.end(); ++it) {
      std::set<MVertex *>::iterator it2 = singularities.find(*it);
      if(it2 != singularities.end()) singularities.erase(it2);
    }
  }

  while(1) {
    bool somethingDone = false;
    std::map<MVertex *, std::vector<MEdge> >::iterator it = _graph.begin();
    for(; it != _graph.end(); ++it) {
      if(it->second.size() == 1) {
        MVertex *v1 = it->second[0].getVertex(0);
        MVertex *v2 = it->second[0].getVertex(1);
        if(boundaries.find(it->first) == boundaries.end() &&
           singularities.find(it->first) == singularities.end()) {
          somethingDone = true;
          std::map<MVertex *, std::vector<MEdge> >::iterator it2 =
            _graph.find(v1 == it->first ? v2 : v1);
          std::vector<MEdge>::iterator position =
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
    std::map<MVertex *, std::vector<MEdge> >::iterator it = _graph.begin();
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

  {
    std::set<MEdge, Less_Edge>::iterator it = cutG.begin();
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

static void groupBoundaries(GModel *gm, std::map<MEdge, cross2d, Less_Edge> &C,
                            std::vector<std::vector<cross2d *> > &groups,
                            std::set<MVertex *> singularities,
                            bool cutGraph = false)
{
  std::set<MVertex *> cutgraph;
  std::set<MVertex *> boundaries;
  for(std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
      it != C.end(); ++it) {
    MVertex *v0 = it->first.getVertex(0);
    MVertex *v1 = it->first.getVertex(1);
    if(it->second.inBoundary) {
      boundaries.insert(v0);
      boundaries.insert(v1);
    }
    if(it->second.inCutGraph) {
      cutgraph.insert(v0);
      cutgraph.insert(v1);
    }
  }

  std::set<cross2d *> _all;

  std::multimap<MVertex *, cross2d *> conn;
  for(std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
      it != C.end(); ++it) {
    std::pair<MVertex *, cross2d *> p =
      std::make_pair(it->first.getVertex(0), &it->second);
    conn.insert(p);
    p = std::make_pair(it->first.getVertex(1), &it->second);
    conn.insert(p);
  }

  //  singularities.clear();

  for(std::set<MVertex *>::iterator it = boundaries.begin();
      it != boundaries.end(); ++it) {
    MVertex *v = *it;
    std::vector<cross2d *> bnd;
    int countCutGraph = 0;
    for(std::multimap<MVertex *, cross2d *>::iterator it2 = conn.lower_bound(v);
        it2 != conn.upper_bound(v); ++it2) {
      if(it2->second->inBoundary) { bnd.push_back(it2->second); }
      if(it2->second->inCutGraph) { countCutGraph++; }
    }
    if(bnd.size() == 2) {
      if(fabs(cos(bnd[0]->_atemp) - cos(bnd[1]->_atemp)) > .25) {
        cutgraph.insert(v);
      }
      if(countCutGraph == 1) singularities.insert(v);
    }
  }

  std::string ss = gm->getName();
  std::string fn = cutGraph ? ss + "_groups_cg.pos" : ss + "_groups_bnd.pos";

  FILE *f = fopen(fn.c_str(), "w");

  fprintf(f, "View \" \"{\n");

  for(int AA = 0; AA < 4; AA++) {
    if(cutGraph) {
      for(std::set<MVertex *>::iterator it = singularities.begin();
          it != singularities.end(); ++it) {
        MVertex *v = *it;
        std::vector<cross2d *> group;
        do {
          MVertex *vnew = NULL;
          for(std::multimap<MVertex *, cross2d *>::iterator it2 =
                conn.lower_bound(v);
              it2 != conn.upper_bound(v); ++it2) {
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
          if(vnew == NULL) break;
          v = vnew;
        } while((boundaries.find(v) == boundaries.end()) &&
                (singularities.find(v) == singularities.end()));
        if(group.size()) {
          groups.push_back(group);
          _all.insert(group.begin(), group.end());
        }
      }
    }
    else {
      for(std::set<MVertex *>::iterator it = boundaries.begin();
          it != boundaries.end(); ++it) {
        MVertex *v = *it;
        if(cutgraph.find(v) != cutgraph.end()) {
          //      printf("START POINT %lu\n",v->getNum());
          std::vector<cross2d *> group;
          do {
            MVertex *vnew = NULL;
            for(std::multimap<MVertex *, cross2d *>::iterator it2 =
                  conn.lower_bound(v);
                it2 != conn.upper_bound(v); ++it2) {
              if((_all.find(it2->second) == _all.end()) &&
                 (group.empty() || group[group.size() - 1] != it2->second) &&
                 it2->second->inBoundary) {
                //	    printf("EDGE %lu
                //%lu\n",it2->second->_e.getVertex(0)->getNum(),it2->second->_e.getVertex(1)->getNum());
                group.push_back(it2->second);
                vnew = (it2->second->_e.getVertex(0) == v) ?
                         it2->second->_e.getVertex(1) :
                         it2->second->_e.getVertex(0);
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
            if(vnew == NULL) break;
            v = vnew;
            //	printf("NEXT POINT %lu %d\n",v->getNum(),cutgraph.find(v) ==
            //cutgraph.end());
          } while(cutgraph.find(v) == cutgraph.end());
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

static void fastImplementationExtrinsic(std::map<MEdge, cross2d, Less_Edge> &C)
{
  double *data = new double[C.size() * 6];
  size_t *graph = new size_t[C.size() * 4];
  std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
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
    if(it->second.inBoundary) {
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
    if(ITER % 1000 == 0) printf("IT %6d RES = %12.5E\n", ITER, RES);
    if(RES < 1.e-8) break;
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
                                    std::set<MVertex *> &vs,
                                    std::map<MEdge, cross2d, Less_Edge> &C)
{
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *_lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *_lsys = new linearSystemCSRGmm<double>;
  //  _lsys->setGmres(0);
#else
  linearSystemFull<double> *_lsys = new linearSystemFull<double>;
#endif
#endif

  dofManager<double> *myAssembler = new dofManager<double>(_lsys);

  //  myAssembler.fixVertex(*vs.begin(), 0, 1, 0);
  for(std::set<MVertex *>::iterator it = vs.begin(); it != vs.end(); ++it)
    myAssembler->numberVertex(*it, 0, 1);

  std::string ss = gm->getName();
  std::string fn = ss + "_grad.pos";

  FILE *_f = fopen(fn.c_str(), "w");
  fprintf(_f, "View \"grad\"{\n");

  simpleFunction<double> ONE(1.0);
  laplaceTerm l(0, 1, &ONE);

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
      std::map<MEdge, cross2d, Less_Edge>::iterator it0 = C.find(e0);
      std::map<MEdge, cross2d, Less_Edge>::iterator it1 = C.find(e1);
      std::map<MEdge, cross2d, Less_Edge>::iterator it2 = C.find(e2);

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

  fn = ss + "_H.pos";

  _f = fopen(fn.c_str(), "w");
  fprintf(_f, "View \"H\"{\n");

  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      double a, b, c;
      myAssembler->getDofValue(t->getVertex(0), 0, 1, a);
      myAssembler->getDofValue(t->getVertex(1), 0, 1, b);
      myAssembler->getDofValue(t->getVertex(2), 0, 1, c);
      fprintf(_f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
              t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
              t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
              t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              a, b, c);
    }
  }
  fprintf(_f, "};\n");
  fclose(_f);
  return myAssembler;
}

/*
  1) find u_i and v_i of all singularities
  2) compute [MAX,MIN] max of u's and v's
  3) Divide this interval into

*/

static double coord1d(double a0, double a1, double a)
{
  return (a - a0) / (a1 - a0);
}

static void computeIso(
  MVertex *vsing, v2t_cont &adj, double VAL, MVertex *v0, MVertex *v1,
  SPoint3 &p, std::map<MVertex *, double> &pot,
  std::set<MEdge, Less_Edge> &visited,
  std::map<MEdge, std::pair<std::map<MVertex *, double> *, double>, Less_Edge>
    &cutGraphEnds,
  std::map<MEdge, MEdge, Less_Edge> &d1, std::vector<groupOfCross2d> &G,
  FILE *f, int COUNT)
{
  if(v0 == vsing || v1 == vsing) return;
  MEdge e(v0, v1);

  if(visited.find(e) != visited.end()) {
    //  printf("EDGE %lu %lu has been visited\n",v0->getNum(),v1->getNum());
    return;
  }
  //  printf("EDGE %lu %lu\n",v0->getNum(),v1->getNum());
  visited.insert(e);
  if(d1.find(e) != d1.end()) {
    //    printf("STREAMLINE %d coming through cutgraph %lu
    //    %lu\n",COUNT,v0->getNum(),v1->getNum());
    std::pair<std::map<MVertex *, double> *, double> aa =
      std::make_pair(&pot, VAL);
    std::pair<MEdge, std::pair<std::map<MVertex *, double> *, double> > p =
      std::make_pair(e, aa);
    cutGraphEnds.insert(p);
  }
  std::vector<MElement *> lst = adj[v0];

  MVertex *vs[2] = {NULL, NULL};
  int count = 0;
  for(size_t i = 0; i < lst.size(); i++) {
    if((lst[i]->getVertex(0) == v0 && lst[i]->getVertex(1) == v1) ||
       (lst[i]->getVertex(0) == v1 && lst[i]->getVertex(1) == v0))
      vs[count++] = lst[i]->getVertex(2);
    if((lst[i]->getVertex(0) == v0 && lst[i]->getVertex(2) == v1) ||
       (lst[i]->getVertex(0) == v1 && lst[i]->getVertex(2) == v0))
      vs[count++] = lst[i]->getVertex(1);
    if((lst[i]->getVertex(1) == v0 && lst[i]->getVertex(2) == v1) ||
       (lst[i]->getVertex(1) == v1 && lst[i]->getVertex(2) == v0))
      vs[count++] = lst[i]->getVertex(0);
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
        computeIso(vsing, adj, VAL, v0, vs[i], pp, pot, visited, cutGraphEnds,
                   d1, G, f, COUNT);
      }
      else if((U[1] - VAL) * (U2 - VAL) <= 0) {
        double xi = coord1d(U[1], U2, VAL);
        SPoint3 pp = p1 * (1. - xi) + ppp * xi;
        fprintf(f, "SL(%g,%g,%g,%g,%g,%g){%d,%d};\n", p.x(), p.y(), p.z(),
                pp.x(), pp.y(), pp.z(), COUNT, COUNT);
        computeIso(vsing, adj, VAL, v1, vs[i], pp, pot, visited, cutGraphEnds,
                   d1, G, f, COUNT);
      }
    }
  }
}

static void computeIso(MVertex *vsing, v2t_cont &adj, double VAL, MVertex *v0,
                       MVertex *v1, SPoint3 &p,
                       std::map<MVertex *, double> *potU,
                       std::map<MVertex *, double> *potV,
                       std::map<MEdge, MEdge, Less_Edge> &d1,
                       std::vector<groupOfCross2d> &G, FILE *f, int COUNT)
{
  //  printf("computing startiung at %lu %lu val
  //  %12.5E\n",v0->getNum(),v1->getNum(),VAL);

  std::set<MEdge, Less_Edge> visited;
  std::map<MEdge, std::pair<std::map<MVertex *, double> *, double>, Less_Edge>
    cutGraphEnds;
  computeIso(vsing, adj, VAL, v0, v1, p, *potU, visited, cutGraphEnds, d1, G, f,
             COUNT);
  //  return;
  int XX = 1;
  while(!cutGraphEnds.empty()) {
    MEdge e = (*cutGraphEnds.begin()).first;
    std::map<MVertex *, double> *POT = (*cutGraphEnds.begin()).second.first;
    VAL = (*cutGraphEnds.begin()).second.second;
    double xi = coord1d((*POT)[e.getVertex(0)], (*POT)[e.getVertex(1)], VAL);
    MEdge o = d1[e];
    p[0] = (1. - xi) * e.getVertex(0)->x() + xi * e.getVertex(1)->x();
    p[1] = (1. - xi) * e.getVertex(0)->y() + xi * e.getVertex(1)->y();
    p[2] = (1. - xi) * e.getVertex(0)->z() + xi * e.getVertex(1)->z();
    //  printf("cutgaphends %lu xi %12.5E p %12.5E
    //  %12.5E\n",cutGraphEnds.size(),xi,p[0],p[1]); printf("cutgaphends %lu
    //  %lu\n",o.getVertex(0)->getNum(),o.getVertex(1)->getNum());

    //    printf("%lu ends to the cutgraph\n",cutGraphEnds.size());
    cutGraphEnds.erase(cutGraphEnds.begin());
    // visited.clear();

    int ROT = 0;
    bool found = false;
    for(size_t i = 0; i < G.size(); i++) {
      if(std::find(G[i].left.begin(), G[i].left.end(), o.getVertex(0)) !=
           G[i].left.end() ||
         std::find(G[i].left.begin(), G[i].left.end(), o.getVertex(1)) !=
           G[i].left.end()) {
        //	printf("coucouc %12.5E\n",G[i].mat[0][0]);
        found = true;
        ROT += fabs(G[i].mat[0][0]) > .6 ? 0 : 1;
      }
      else if(std::find(G[i].left.begin(), G[i].left.end(), e.getVertex(0)) !=
                G[i].left.end() ||
              std::find(G[i].left.begin(), G[i].left.end(), e.getVertex(1)) !=
                G[i].left.end()) {
        //	printf("coucouc -- %12.5E\n",G[i].mat[0][0]);
        found = true;
        ROT += fabs(G[i].mat[0][0]) > .6 ? 0 : 1;
      }
    }
    if(!found) { printf("IMPOSSIBLE \n"); }
    if(ROT || !found) { POT = (POT == potU ? potV : potU); }
    else {
    }
    XX += ROT;
    // printf("XX = %d ROT = %d %lu\n",XX,ROT,cutGraphEnds.size());
    if(distance(e.getVertex(0), o.getVertex(0)) < 1.e-12)
      VAL = (1. - xi) * (*POT)[o.getVertex(0)] + xi * (*POT)[o.getVertex(1)];
    else
      VAL = (1. - xi) * (*POT)[o.getVertex(1)] + xi * (*POT)[o.getVertex(0)];
    computeIso(vsing, adj, VAL, o.getVertex(0), o.getVertex(1), p, *POT,
               visited, cutGraphEnds, d1, G, f, COUNT);
    if(XX > 1200) break;
  }
}

static void computeIso(MVertex *vsing, v2t_cont &adj, double u,
                       std::map<MVertex *, double> &potU,
                       std::map<MVertex *, double> &potV, FILE *f,
                       std::map<MEdge, MEdge, Less_Edge> &d1,
                       std::vector<groupOfCross2d> &G, int COUNT)
{
  //  printf("computing an ISO for %lu\n",vsing->getNum());
  std::vector<MElement *> faces = adj[vsing];
  for(size_t i = 0; i < faces.size(); i++) {
    //    for (size_t j=0;j<3;j++){
    MVertex *v0 = faces[i]->getVertex(0);
    MVertex *v1 = faces[i]->getVertex(1);
    MVertex *v2 = faces[i]->getVertex(2);
    double U0 = potU[v0];
    double U1 = potU[v1];
    double U2 = potU[v2];
    SPoint3 p0(v0->x(), v0->y(), v0->z());
    SPoint3 p1(v1->x(), v1->y(), v1->z());
    SPoint3 p2(v2->x(), v2->y(), v2->z());
    //      std::set<MEdge,Less_Edge> visited;
    //      std::set<MEdge,Less_Edge> cutGraphEnds;
    if(v2 == vsing && (U0 - u) * (U1 - u) <= 0) {
      double xi = coord1d(U0, U1, u);
      SPoint3 pp = p0 * (1 - xi) + p1 * xi;
      //	double VV = potV[v0] *(1-xi) + potV[v1] * xi;
      // computeIso
      // (adj,VV,v0,v1,pp,potV,potU,visited,f,duplicateEdges,duplicateEdges_back);
      computeIso(vsing, adj, u, v0, v1, pp, &potU, &potV, d1, G, f, COUNT);
      //	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",pp.x(),
      //		pp.y(),pp.z(),p2.x(),p2.y(),p2.z(),u,u);
    }
    else if(v1 == vsing && (U0 - u) * (U2 - u) <= 0) {
      double xi = coord1d(U0, U2, u);
      SPoint3 pp = p0 * (1 - xi) + p2 * xi;
      //	double VV = potV[v0] *(1-xi) + potV[v2] * xi;
      // computeIso
      // (adj,VV,v0,v2,pp,potV,potU,visited,f,duplicateEdges,duplicateEdges_back);
      computeIso(vsing, adj, u, v0, v2, pp, &potU, &potV, d1, G, f, COUNT);
      //	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",pp.x(),
      //		pp.y(),pp.z(),p1.x(),p1.y(),p1.z(),u,u);
    }
    else if(v0 == vsing && (U1 - u) * (U2 - u) <= 0) {
      double xi = coord1d(U1, U2, u);
      SPoint3 pp = p1 * (1 - xi) + p2 * xi;
      //	double VV = potV[v1] *(1-xi) + potV[v2] * xi;
      // computeIso
      // (adj,VV,v1,v2,pp,potV,potU,visited,f,duplicateEdges,duplicateEdges_back);
      computeIso(vsing, adj, u, v1, v2, pp, &potU, &potV, d1, G, f, COUNT);
      //	fprintf(f,"SL(%g,%g,%g,%g,%g,%g){%g,%g};\n",pp.x(),
      //		pp.y(),pp.z(),p0.x(),p0.y(),p0.z(),u,u);
    }
    //    }
  }
}

static void computeIsos(GModel *gm, std::vector<GFace *> &faces,
                        std::set<MVertex *> &singularities,
                        std::map<MEdge, cross2d, Less_Edge> &C,
                        std::map<MVertex *, MVertex *> &new2old,
                        std::map<MEdge, MEdge, Less_Edge> &duplicateEdges,
                        std::vector<std::vector<cross2d *> > &groups,
                        std::vector<std::vector<cross2d *> > &groups_cg,
                        std::map<MVertex *, double> &potU,
                        std::map<MVertex *, double> &potV,
                        std::set<MEdge, Less_Edge> &cutG,
                        std::vector<groupOfCross2d> &G)
{
  v2t_cont adj;
  for(size_t i = 0; i < faces.size(); i++) {
    buildVertexToElement(faces[i]->triangles, adj);
  }

  {
    std::map<MVertex *, MVertex *>::iterator it = new2old.begin();
    for(; it != new2old.end(); ++it) {
      if(singularities.find(it->second) != singularities.end()) {
        singularities.insert(it->first);
      }
    }
  }

  std::map<MVertex *, MVertex *> duplicates;
  {
    std::map<MVertex *, MVertex *>::iterator it = new2old.begin();
    for(; it != new2old.end(); ++it) {
      duplicates[it->first] = it->second;
      duplicates[it->second] = it->first;
    }
  }

  std::map<MEdge, MEdge, Less_Edge> d1;
  {
    for(size_t i = 0; i < G.size(); i++) {
      for(size_t j = 1; j < G[i].left.size(); j++) {
        MEdge l(G[i].left[j - 1], G[i].left[j]);
        MEdge r(G[i].right[j - 1], G[i].right[j]);
        d1[l] = r;
        d1[r] = l;
      }
      if(G[i].singularities.size() == 1) {
        MEdge l(G[i].singularities[0], G[i].left[G[i].left.size() - 1]);
        MEdge r(G[i].singularities[0], G[i].right[G[i].right.size() - 1]);
        d1[l] = r;
        d1[r] = l;
      }
    }
  }

#if 0
  for(size_t i = 0; i < faces.size(); i++) {
    for(size_t j = 0; j < faces[i]->triangles.size(); j++) {
      for(size_t k = 0; k < 3; k++) {
	MEdge e = faces[i]->triangles[j]->getEdge(k);
	std::map<MVertex *, MVertex *>::iterator it1 = duplicates.find(e.getVertex(0));
	std::map<MVertex *, MVertex *>::iterator it2 = duplicates.find(e.getVertex(1));
	std::set<MVertex *>::iterator it1b = singularities.find(e.getVertex(0));
	std::set<MVertex *>::iterator it2b = singularities.find(e.getVertex(1));
	if (it1 != duplicates.end() && it2b != singularities.end()){
	  MEdge ee1 (it1->second,*it2b);
	  MEdge ee2 (it1->first,*it2b);
	  if (cutG.find(ee1) != cutG.end() || cutG.find(ee2) != cutG.end())
	    d1[e] = ee1;
	}
	else if (it2 != duplicates.end() && it1b != singularities.end()){
	  MEdge ee1 (it2->second,*it1b);
	  MEdge ee2 (it2->first,*it1b);
	  if (cutG.find(ee1) != cutG.end() || cutG.find(ee2) != cutG.end())
	    d1[e] = ee1;
	}
	else if (it1 != duplicates.end() && it2 != duplicates.end()){
	  MEdge ee1 (it1->second,it2->second);
	  MEdge ee2 (it1->first,it2->second);
	  MEdge ee3 (it1->second,it2->first);
	  MEdge ee4 (it1->first,it2->first);
	  if (cutG.find(ee1) != cutG.end() || cutG.find(ee2) != cutG.end() ||
	      cutG.find(ee3) != cutG.end() || cutG.find(ee4) != cutG.end() ){
	    MEdge e1 (it1->second,it2->second);
	    d1[e] = e1;
	  }
	}
      }
    }
  }
#endif
  //  printf("%lu %lu %lu\n",d1.size(),duplicateEdges.size(),new2old.size());
  if(1) {
    FILE *f = fopen("myiso.pos", "w");
    fprintf(f, "View\"\"{\n");
    std::map<MVertex *, MVertex *>::iterator it = new2old.begin();
    for(; it != new2old.end(); ++it) {
      computeIso(it->second, adj, potU[it->second], potU, potV, f, d1, G,
                 it->second->getNum());
      computeIso(it->second, adj, potV[it->second], potV, potU, f, d1, G,
                 it->second->getNum());
      computeIso(it->first, adj, potU[it->first], potU, potV, f, d1, G,
                 it->second->getNum());
      computeIso(it->first, adj, potV[it->first], potV, potU, f, d1, G,
                 it->second->getNum());
    }
    fprintf(f, "};\n");
    fclose(f);
  }

  FILE *f = fopen("isos.pos", "w");
  fprintf(f, "View\"\"{\n");

  std::set<MVertex *>::iterator it = singularities.begin();
  std::vector<double> Using, Vsing;
  //int COUNT = 1;
  for(; it != singularities.end(); ++it) {
    Using.push_back(potU[*it]);
    Vsing.push_back(potV[*it]);

    //    printf("SINGULARITY %3lu COORD %12.5E %12.5E %3d\n",
    //	   (*it)->getNum(),potU[*it],potV[*it],(*it)->getNum());
    //    if ((*it)->getNum() == 845){
    computeIso(*it, adj, potU[*it], potU, potV, f, d1, G, (*it)->getNum());
    //    printf("SINGULARITY %3lu COORD %12.5E %12.5E %3d\n",
    //	   (*it)->getNum(),potU[*it],potV[*it],COUNT);
    computeIso(*it, adj, potV[*it], potV, potU, f, d1, G, (*it)->getNum());
    //    }
    //    break;
  }
  std::sort(Using.begin(), Using.end());
  std::sort(Vsing.begin(), Vsing.end());

  fprintf(f, "};\n");
  fclose(f);
}

void getAllConnectedTriangles(cross2d *start, std::vector<cross2d *> &group,
                              std::set<MVertex *> &isolated_singularities,
                              std::set<MVertex *> &all,
                              std::set<MTriangle *> &t,
                              std::set<MTriangle *> &allTrianglesConsidered)
{
  std::set<cross2d *> touched;

  printf("group %lu isolated singularities\n", isolated_singularities.size());

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

static void computeLeftRight(groupOfCross2d &g, MVertex **left, MVertex **right)
{
  for(size_t i = 0; i < g.side.size(); i++) {
    if(g.side[i]->getVertex(0) == *right || g.side[i]->getVertex(1) == *right ||
       g.side[i]->getVertex(2) == *right) {
      MVertex *temp = *left;
      *left = *right;
      *right = temp;
      return;
    }
    if(g.side[i]->getVertex(0) == *left || g.side[i]->getVertex(1) == *left ||
       g.side[i]->getVertex(2) == *left) {
      return;
    }
  }
  printf("ERROR, not able to determine the side of the cut graph %lu %lu\n",
         (*left)->getNum(), (*right)->getNum());
}

static void createJumpyPairs(groupOfCross2d &g,
                             std::set<MVertex *> &singularities,
                             std::set<MVertex *> &boundaries,
                             std::map<MVertex *, MVertex *> &old2new)
{
  std::set<MVertex *> touched;

  //  printf("GROUP %d \n",g.groupId);
  for(size_t i = 0; i < g.crosses.size(); ++i) {
    cross2d *c = g.crosses[i];
    for(size_t j = 0; j < 2; j++) {
      MVertex *vv = c->_e.getVertex(j);
      if(touched.find(vv) == touched.end()) {
        touched.insert(vv);
        std::map<MVertex *, MVertex *>::iterator it = old2new.find(vv);
        if(it != old2new.end()) {
          MVertex *v0 = it->first;
          MVertex *v1 = it->second;
          computeLeftRight(g, &v0, &v1);
          //	  printf("GROUP %d (%lu/%lu) v %lu
          //%lu\n",g.groupId,i,g.crosses.size(),v0->getNum(),v1->getNum());
          if(boundaries.find(vv) != boundaries.end()) {
            //	    printf("boundary found\n");
            g.left.insert(g.left.begin(), v0);
            g.right.insert(g.right.begin(), v1);
          }
          else {
            g.left.push_back(v0);
            g.right.push_back(v1);
          }
        }
        else if(singularities.find(vv) != singularities.end()) {
          g.singularities.push_back(vv);
        }
        //	else if (singularities.find(vv) == singularities.end()){
        //	  printf("ERROR --> no counterpart vertex in the cut graph\n");
        //	}
      }
    }
  }
}

static void analyzeGroup(std::vector<cross2d *> &group, groupOfCross2d &g,
                         std::map<MTriangle *, SVector3> &d,
                         std::map<MTriangle *, SVector3> &d2, v2t_cont &adj,
                         std::set<MVertex *> &isolated_singularities,
                         std::set<MVertex *> &boundaries,
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
  std::set<MVertex *> all;
  getAllConnectedTriangles(group[0], group, isolated_singularities, all, t,
                           allTrianglesConsidered);
  g.side.insert(g.side.begin(), t.begin(), t.end());
  g.vertices.insert(g.vertices.begin(), all.begin(), all.end());

  // compute which rotation ...
  for(size_t i = 0; i < g.crosses.size(); ++i) {
    cross2d *c = g.crosses[i];
    if(c->_t.size() == 2) {
      double dd0 = dot(d[c->_t[0]], d2[c->_t[1]]);
      double dd1 = dot(d[c->_t[1]], d2[c->_t[0]]);
      g.sign0 = dd0 > 0 ? 1.0 : -1.0;
      g.sign1 = dd1 > 0 ? 1.0 : -1.0;
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

static int computeCrossField2dTheta(GModel *gm, std::vector<GFace *> &f,
                                    const char *outputName)
{
  Msg::SetNumThreads(Msg::GetMaxThreads());

  std::map<MEdge, cross2d, Less_Edge> C;
  std::set<MVertex *> vs;
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      for(size_t k = 0; k < 3; k++) {
        vs.insert(t->getVertex(k));
        MEdge e = t->getEdge(k);
        MEdge e1 = t->getEdge((k + 1) % 3);
        MEdge e2 = t->getEdge((k + 2) % 3);
        cross2d c(e, t, e1, e2);
        std::map<MEdge, cross2d, Less_Edge>::iterator it = C.find(e);
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

  bool _BDRY = true;
  if(_BDRY) {
    for(size_t i = 0; i < f.size(); i++) {
      std::vector<GEdge *> e = f[i]->edges();
      for(size_t j = 0; j < e.size(); j++) {
        for(size_t k = 0; k < e[j]->lines.size(); k++) {
          MLine *l = e[j]->lines[k];
          MEdge e = l->getEdge(0);
          std::map<MEdge, cross2d, Less_Edge>::iterator it = C.find(e);
          if(it != C.end()) { it->second.inBoundary = true; }
        }
      }
    }
  }

  std::map<MEdge, cross2d, Less_Edge>::iterator it = C.begin();
  for(; it != C.end(); ++it) it->second.finish(C);
  it = C.begin();
  for(; it != C.end(); ++it) it->second.finish2();

  std::vector<cross2d *> pc;
  for(it = C.begin(); it != C.end(); ++it) pc.push_back(&(it->second));

  int ITER = 0;
  while(ITER++ < 1999) {
    if(ITER % 200 == 0) std::random_shuffle(pc.begin(), pc.end());
    for(size_t i = 0; i < pc.size(); i++) pc[i]->average_init();
    if(ITER % 1000 == 0) printf("SIMPLE LAPLACE IT %6d\n", ITER);
  }

  for(size_t i = 0; i < pc.size(); i++) pc[i]->computeVector();

  fastImplementationExtrinsic(C);

  for(size_t i = 0; i < pc.size(); i++) pc[i]->computeAngle();

  std::string ss = gm->getName();
  std::string fn = ss + "_cross.pos";
  FILE *of = fopen(fn.c_str(), "w");
  fprintf(of, "View \"Direction fields\"{\n");
  for(it = C.begin(); it != C.end(); ++it) {
    double a = it->second.grad();
    double a0 = it->second._a;
    MEdge e0 = it->second._e;

    double fact = 1. - a;
    if(fact < .001) fact = .001;

    //    fact = 1;
    SVector3 d1 =
      (it->second._tgt * cos(a0) + it->second._tgt2 * sin(a0)) * fact;
    SVector3 d2 =
      (it->second._tgt * (-sin(a0)) + it->second._tgt2 * cos(a0)) * fact;
    SVector3 d3 =
      (it->second._tgt * (-cos(a0)) - it->second._tgt2 * sin(a0)) * fact;
    SVector3 d4 =
      (it->second._tgt * sin(a0) - it->second._tgt2 * cos(a0)) * fact;

    for(size_t I = 0; I < it->second._t.size(); I++) {
      fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
              0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
              0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
              0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d1.x(),
              d1.y(), d1.z());
      //              cos(a0) * fact, sin(a0) * fact, 0.0);
      fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
              0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
              0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
              0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d2.x(),
              d2.y(), d2.z());
      //              -sin(a0) * fact, cos(a0) * fact, 0.0);
      fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
              0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
              0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
              0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d3.x(),
              d3.y(), d3.z());
      //              -cos(a0) * fact, -sin(a0) * fact, 0.0);
      fprintf(of, "VP(%g,%g,%g){%g,%g,%g};\n",
              0.5 * (e0.getVertex(0)->x() + e0.getVertex(1)->x()),
              0.5 * (e0.getVertex(0)->y() + e0.getVertex(1)->y()),
              0.5 * (e0.getVertex(0)->z() + e0.getVertex(1)->z()), d4.x(),
              d4.y(), d4.z());
      //              sin(a0) * fact, -cos(a0) * fact, 0.0);
    }
    /*
        fprintf(of,"SP(%g,%g,%g){%g};",
            0.5*(e0.getVertex(0)->x()+e0.getVertex(1)->x()),
            0.5*(e0.getVertex(0)->y()+e0.getVertex(1)->y()),
            0.5*(e0.getVertex(0)->z()+e0.getVertex(1)->z()), a);
    */
  }
  fprintf(of, "};\n");
  fclose(of);

  dofManager<double> *myAssembler = computeH(gm, f, vs, C);

  std::set<MEdge, Less_Edge> cutG;
  std::set<MVertex *> singularities;
  std::set<MVertex *> boundaries;

  computeSingularities(C, singularities);

  print_H_and_Cross(gm, f, C, *myAssembler, singularities);

  cutGraph(C, *myAssembler, cutG, singularities, boundaries);
  for(it = C.begin(); it != C.end(); ++it) {
    if(cutG.find(it->second._e) == cutG.end()) {
      computeLifting(&(it->second), 0, cutG, singularities, boundaries);
      break;
    }
  }
  int count = 0;
  for(it = C.begin(); it != C.end(); ++it) {
    if(it->second._btemp < 1000) count++;
  }
  if(count) { printf("lifting failed %d\n", count); }

  // COMPUTING CUT GRAPH
  for(it = C.begin(); it != C.end(); ++it) {
    MEdge e0 = it->second._e;
    if(cutG.find(e0) != cutG.end()) it->second.inCutGraph = true;
  }

  std::vector<std::vector<cross2d *> > groups;
  std::vector<std::vector<cross2d *> > groups_cg;

  groupBoundaries(gm, C, groups, singularities, false);
  groupBoundaries(gm, C, groups_cg, singularities, true);

  printf("%lu %lu groups\n", groups.size(), groups_cg.size());

  v2t_cont adj;
  for(size_t i = 0; i < f.size(); i++) {
    buildVertexToElement(f[i]->triangles, adj);
  }
  std::map<MTriangle *, SVector3> d0, d1;
  computeUniqueVectorPerTriangle(gm, f, C, 0, d0);
  computeUniqueVectorPerTriangle(gm, f, C, 1, d1);
  std::vector<groupOfCross2d> G;
  fn = ss + "_groups_analyzed.pos";
  FILE *_f = fopen(fn.c_str(), "w");
  fprintf(_f, "View \"groups\"{\n");

  std::set<MTriangle *> allTrianglesConsidered;
  std::set<MVertex *> isolated_singularities;

  {
    for(std::set<MVertex *>::iterator it = singularities.begin();
        it != singularities.end(); ++it) {
      int count = 0;
      for(size_t i = 0; i < groups_cg.size(); i++) {
        for(size_t k = 0; k < groups_cg[i].size(); k++) {
          for(size_t j = 0; j < 2; j++) {
            MVertex *v = groups_cg[i][k]->_e.getVertex(j);
            if(v == *it) count++;
          }
        }
      }
      if(count == 1) {
        printf("singularity %lu is isolated\n", (*it)->getNum());
        isolated_singularities.insert(*it);
      }
      else {
        printf("singularity %lu is connected to %d cut graph parts\n",
               (*it)->getNum(), count);
        isolated_singularities.insert(*it);
      }
    }
  }

  for(size_t i = 0; i < groups_cg.size(); i++) {
    groupOfCross2d g(i);
    analyzeGroup(groups_cg[i], g, d0, d1, adj, isolated_singularities,
                 boundaries, allTrianglesConsidered);
    g.print(_f);
    G.push_back(g);
  }
  fprintf(_f, "};\n");
  fclose(_f);

  std::map<MEdge, MEdge, Less_Edge> duplicateEdges;
  std::map<MVertex *, MVertex *> new2old;
  std::map<MVertex *, MVertex *> old2new;
  duplicateNodesInCutGraph(f, C, new2old, old2new, duplicateEdges,
                           singularities, adj, G);

  for(size_t i = 0; i < groups_cg.size(); i++) {
    createJumpyPairs(G[i], singularities, boundaries, old2new);
    printf("group %d %lu irregular vertices %lu discontinuities\n",
           G[i].groupId, G[i].left.size(), G[i].singularities.size());
  }

  fn = ss + "_lifting.pos";
  _f = fopen(fn.c_str(), "w");
  fprintf(_f, "View \"lifting\"{\n");

  // COMPUTING CUT GRAPH
  for(size_t i = 0; i < f.size(); i++) {
    for(size_t j = 0; j < f[i]->triangles.size(); j++) {
      MTriangle *t = f[i]->triangles[j];
      SVector3 a = d0[t];
      SVector3 b = d1[t];
      fprintf(_f,
              "VT(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,"
              "%g,%g,%g,%g,%g,%g,%g};\n",
              t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z(),
              t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z(),
              t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z(),
              a.x(), a.y(), a.z(), a.x(), a.y(), a.z(), a.x(), a.y(), a.z(),
              b.x(), b.y(), b.z(), b.x(), b.y(), b.z(), b.x(), b.y(), b.z());
    }
  }
  fprintf(_f, "};\n");
  fclose(_f);

  std::map<MVertex *, double> potU, potV;
  fn = ss + "_potX.pos";
  std::string fn2 = ss + "_potY.pos";
  computePotential(gm, f, fn.c_str(), fn2.c_str(), *myAssembler, C, new2old,
                   groups, duplicateEdges, d0, d1, G, potU, potV);

  computeIsos(gm, f, singularities, C, new2old, duplicateEdges, groups,
              groups_cg, potU, potV, cutG, G);

  return 0;
}

#endif

int computeCrossField(GModel *gm)
{
  std::vector<GFace *> f;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    GFace *gf = *it;
    f.push_back(gf);
  }
  //  if (!strcmp(method,"theta"))
  return computeCrossField2dTheta(gm, f, "toto");
  //  else
  //    Msg::Error("Unknown Cross Field Computation Method %s",method);
}
