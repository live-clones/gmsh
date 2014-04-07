// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "Gmsh.h"
#include "GModel.h"
#include "GmshMessage.h"

#include "polynomialBasis.h"
#include "AnalyseCurvedMesh.h"
#include "Context.h"
#include <queue>
#include <cmath>
#include<fstream>
#include "OS.h"
#include "PView.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif
#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

namespace {

class BezierJacobian;
struct lessMinB {
  bool operator()(BezierJacobian*, BezierJacobian*) const;
};
struct lessMaxB {
  bool operator()(BezierJacobian*, BezierJacobian*) const;
};

class BezierJacobian
{
private:
  fullVector<double> _jacBez;
  double _minJ, _maxJ, _minB, _maxB; //Extremum of Jac at corners and of bezier values
  int _depthSub;
  const JacobianBasis *_jfs;

public:
  BezierJacobian(fullVector<double> &, const JacobianBasis *, int depth);
  void subDivisions(fullVector<double> &vect) const
    {_jfs->subdivideBezierCoeff(_jacBez, vect);}

  inline int depth() const {return _depthSub;}
  inline double minJ() const {return _minJ;}
  inline double maxJ() const {return _maxJ;}
  inline double minB() const {return _minB;}
  inline double maxB() const {return _maxB;}
};

} // namespace

//#define UNDEF_JAC_TAG -999
//#define _ANALYSECURVEDMESH_BLAS_

StringXNumber JacobianOptions_Number[] = {
  {GMSH_FULLRC, "Dim", NULL, -1},
  {GMSH_FULLRC, "Analysis", NULL, 2},
  {GMSH_FULLRC, "Effect (1)", NULL, 6},
  {GMSH_FULLRC, "JacBreak (1)", NULL, .0},
  {GMSH_FULLRC, "BezBreak (1)", NULL, .0},
  {GMSH_FULLRC, "MaxDepth (1,2)", NULL, 20},
  {GMSH_FULLRC, "Tolerance (2)", NULL, 1e-3}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin()
  {
    return new GMSH_AnalyseCurvedMeshPlugin();
  }
}
int GMSH_AnalyseCurvedMeshPlugin::getNbOptions() const
{
  return sizeof(JacobianOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_AnalyseCurvedMeshPlugin::getOption(int iopt)
{
  return &JacobianOptions_Number[iopt];
}

std::string GMSH_AnalyseCurvedMeshPlugin::getHelp() const
{
  return "Plugin(AnalyseCurvedMesh) check the jacobian of all elements of dimension 'Dim' or "
    "the greater model dimension if 'Dim' is either <0 or >3.\n\n "
    "Analysis : 0 do nothing\n"
    "          +1 find invalid elements (*)\n"
    "          +2 compute J_min and J_max of all elements and print some statistics\n\n"
    "Effect (for *) : 0 do nothing\n"
    "                +1 print a list of invalid elements\n"
    "                +2 print some statistics\n"
    "                +4 hide valid elements (for GUI)\n\n"
    "MaxDepth = 0,1,...\n"
    "         0 : only sample the jacobian\n"
    "         1 : compute Bezier coefficients\n"
    "        2+ : execute a maximum of 1+ subdivision(s)\n\n"
    "JacBreak = [0,1[ : if a value of the jacobian <= 'JacBreak' is found, "
    "the element is said to be invalid\n\n"
    "BezBreak = [0,JacBreak[ : if all Bezier coefficients are > 'BezBreak', "
    "the element is said to be valid\n\n"
    "Tolerance = R+ , << 1 : tolerance (relatively to J_min and J_max) used during the computation of J_min and J_max";
}

// Execution
PView *GMSH_AnalyseCurvedMeshPlugin::execute(PView *v)
{
  _m = GModel::current();
  _dim = (int) JacobianOptions_Number[0].def;
  if (_dim < 0 || _dim > 3)
    _dim = _m->getDim();
  int analysis = (int) JacobianOptions_Number[1].def % 4;
  int toDo = (int) JacobianOptions_Number[2].def % 8;
  _maxDepth = (int) JacobianOptions_Number[5].def;
  _jacBreak = (double) JacobianOptions_Number[3].def;
  _bezBreak = (double) JacobianOptions_Number[4].def;
  _tol = (double) JacobianOptions_Number[6].def;

  if (analysis % 2) {
    double t = Cpu();
    Msg::Info("Starting validity check...");
    checkValidity(toDo);
    Msg::Info("Done validity check (%fs)", Cpu()-t);
  }
  if (analysis / 2) {
    double t = Cpu();
    Msg::Info("Starting computation J_min, J_max...");
    std::map<int, std::vector<double> > data;
    computeMinMax(&data);
    new PView("Jmin", "ElementData", _m, data);
    Msg::Info("Done computation J_min, J_max (%fs)", Cpu()-t);
  }
  return 0;
}

void GMSH_AnalyseCurvedMeshPlugin::checkValidity(int toDo)
{
  std::vector<MElement*> invalids;
  _numAnalysedEl = 0;
  _numInvalid = 0;
  _numValid = 0;
  _numUncertain = 0;

  switch (_dim) {
    case 3 :
      for(GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
        GRegion *r = *it;
        unsigned int numType[5] = {0, 0, 0, 0, 0};
        r->getNumMeshElements(numType);

        for(int type = 0; type < 5; type++) {
          MElement *const *el = r->getStartElementType(type);
          checkValidity(el, numType[type], invalids);
          _numAnalysedEl += numType[type];
        }
      }
      break;

    case 2 :
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;

        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);

        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          for (unsigned int jo = 0; jo < numType[type]; jo++)
            el[jo]->setVolumePositive();
        }
      }
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;
        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);
        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          checkValidity(el, numType[type], invalids);
          _numAnalysedEl += numType[type];
        }
      }
      break;

    case 1 :
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
        GEdge *e = *it;
        unsigned int numElement = e->getNumMeshElements();
        MElement *const *el = e->getStartElementType(0);
        checkValidity(el, numElement, invalids);
        _numAnalysedEl += numElement;
      }
      break;

    default :
      Msg::Error("I can't analyse any element.");
  }

  if (toDo % 2) {
    Msg::Info("Invalids elements :");
    Msg::Info("-------------------");
    for (unsigned int i = 0; i < invalids.size(); ++i) {
      Msg::Info(" %d", invalids[i]->getNum());
    }
  }
  if (toDo / 2 % 2) {
    Msg::Info("Found %d invalid elements and %d valid", _numInvalid, _numValid);
    if (_numUncertain) {
      Msg::Info("%d uncertain elements.", _numUncertain);
      if (_jacBreak < _bezBreak) {
        Msg::Info("'JacBreak' is smaller than 'BezBreak'. Change values in order to decrease the number of uncertain elements.");
      }
      else {
        Msg::Info("Increase MaxDepth in order to decrease the number of uncertain elements.");
      }
    }
    Msg::Info("%d elements analysed", _numAnalysedEl);
  }
  if (toDo / 4 % 2) {
    Msg::Info("Note: Valid elements are hidden. Change 'Effect' to disable this functionality.");
    Msg::Info("(To revert visibility : Tools > Visibility > Interactive > Show All)");
    hideValid_ShowInvalid(invalids);
    CTX::instance()->mesh.changed = (ENT_ALL);
#if defined(HAVE_FLTK)
    FlGui::instance()->check();
#endif
#if defined(HAVE_OPENGL)
    drawContext::global()->draw();
#endif
  }
}

void GMSH_AnalyseCurvedMeshPlugin::checkValidity(MElement *const*el,
                                                 int numEl,
                                                 std::vector<MElement*> &invalids)
{
  if (numEl < 1)
    return;

  const JacobianBasis *jfs = el[0]->getJacobianFuncSpace();
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el[0]->getNum());
    return;
  }
  const int numSamplingPt = jfs->getNumJacNodes();
  const int numMapNodes = jfs->getNumMapNodes();

#ifdef _ANALYSECURVEDMESH_BLAS_
  fullMatrix<double> jacobianB(numSamplingPt, numEl);
  fullMatrix<double> jacBezB(numSamplingPt, numEl);
  fullVector<double> jacBez, jacobian;

  fullMatrix<double> nodesX(numMapNodes, numEl), nodesY(numMapNodes, numEl), nodesZ(numMapNodes, numEl);
  for (int k = 0; k < numEl; ++k)
    for (int i = 0; i < numMapNodes; ++i)
    {
      MVertex *v = (el[k])->getShapeFunctionNode(i);
      nodesX(i,k) = v->x();
      nodesY(i,k) = v->y();
      nodesZ(i,k) = v->z();
    }

  jfs->getScaledJacobian(nodesX, nodesY, nodesZ, jacobianB);
  jfs->lag2Bez(jacobianB, jacBezB);
#else
  fullVector<double> jacobian(numSamplingPt);
  fullVector<double> jacBez(numSamplingPt);
#endif

  for (int k = 0; k < numEl; ++k) {

#ifdef _ANALYSECURVEDMESH_BLAS_
    jacBez.setAsProxy(jacBezB, k);
    jacobian.setAsProxy(jacobianB, k);
#else
    fullMatrix<double> nodesXYZ(numMapNodes,3);
    el[k]->getNodesCoord(nodesXYZ);
    jfs->getScaledJacobian(nodesXYZ,jacobian);
#endif

    int i;
    for (i = 0; i < numSamplingPt && jacobian(i) > _jacBreak; ++i);
    if (i < numSamplingPt) {
      invalids.push_back(el[k]);
      ++_numInvalid;
      continue;
    }

    if (_maxDepth < 1) {
      invalids.push_back(el[k]);
      ++_numUncertain;
      continue;
    }

#ifndef _ANALYSECURVEDMESH_BLAS_
    jfs->lag2Bez(jacobian, jacBez);
#endif

    for (i = 0; i < jacBez.size() && jacBez(i) > _bezBreak; ++i);
    if (i >= jacBez.size()) {
      ++_numValid;
      continue;
    }

    if (_maxDepth < 2) {
      invalids.push_back(el[k]);
      ++_numUncertain;
      continue;
    }
    else {
      int result = subDivision(jfs, jacBez, _maxDepth-1);
      if (result < 0) {
        invalids.push_back(el[k]);
        ++_numInvalid;
        continue;
      }
      if (result > 0) {
        ++_numValid;
        continue;
      }
      invalids.push_back(el[k]);
      ++_numUncertain;
      continue;
    }
  }
}

int GMSH_AnalyseCurvedMeshPlugin::subDivision(const JacobianBasis *jb,
                                              const fullVector<double> &jacobian,
                                              int depth)
{
  fullVector<double> newJacobian(jb->getNumSubNodes());
  jb->subdivideBezierCoeff(jacobian, newJacobian);

  for (int i = 0; i < jb->getNumDivisions(); i++)
  for (int j = 0; j < jb->getNumLagCoeff(); j++)
  if (newJacobian(i * jb->getNumJacNodes() + j) <= _jacBreak)
    return -1;

  int i = 0;
  while (i < newJacobian.size() && newJacobian(i) > _bezBreak)
    ++i;
  if (i >= newJacobian.size()) return 1;

  if (depth <= 1) {
    return 0;
  }
  else{
    fullVector<double> subJacobian;
    std::vector<int> negTag, posTag;
    bool zeroTag = false;

    for (int i = 0; i < jb->getNumDivisions(); i++) {
      subJacobian.setAsProxy(newJacobian, i * jacobian.size(), jacobian.size());
      int tag = subDivision(jb, subJacobian, depth-1);

      if (tag < 0)
        negTag.push_back(tag);
      else if (tag > 0)
        posTag.push_back(tag);
      else
        zeroTag = true;
    }

    if (negTag.size() > 0)
      return *std::min_element(negTag.begin(), negTag.end()) - 1;

    if (zeroTag) return 0;

    return *std::max_element(posTag.begin(), posTag.end()) + 1;
  }
}


void GMSH_AnalyseCurvedMeshPlugin::computeMinMax(std::map<int, std::vector<double> > *data)
{
  _numAnalysedEl = 0;
  _numInvalid = 0;
  _numValid = 0;
  _numUncertain = 0;
  _min_pJmin = .0, _avg_pJmin = .0;
  _min_ratioJ = .0, _avg_ratioJ = .0;

  switch (_dim) {
    case 3 :
      for(GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
        GRegion *r = *it;
        unsigned int numType[5] = {0, 0, 0, 0, 0};
        r->getNumMeshElements(numType);

        for(int type = 0; type < 5; type++) {
          MElement *const *el = r->getStartElementType(type);
          computeMinMax(el, numType[type], data);
          _numAnalysedEl += numType[type];
        }
      }
      break;

    case 2 :
      for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
        GFace *f = *it;
        unsigned int numType[3] = {0, 0, 0};
        f->getNumMeshElements(numType);

        for (int type = 0; type < 3; type++) {
          MElement *const *el = f->getStartElementType(type);
          computeMinMax(el, numType[type], data);
          _numAnalysedEl += numType[type];
        }
      }
      break;

    case 1 :
      for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
        GEdge *e = *it;
        unsigned int numElement = e->getNumMeshElements();
        MElement *const *el = e->getStartElementType(0);
        computeMinMax(el, numElement, data);
        _numAnalysedEl += numElement;
      }
      break;

    default :
      Msg::Error("I can't analyse any element.");
      return;
  }
  Msg::Info("Minimum of min(~distortion) : %g", _min_pJmin);
  Msg::Info("Average of min(~distortion) : %g", _avg_pJmin / _numAnalysedEl);
  Msg::Info("Minimum of min(J) / max(J) : %g", _min_ratioJ);
  Msg::Info("Average of min(J) / max(J) : %g", _avg_ratioJ / _numAnalysedEl);
}

void GMSH_AnalyseCurvedMeshPlugin::computeMinMax(MElement *const*el, int numEl, std::map<int, std::vector<double> > *data)
{
  if (numEl < 1)
    return;

  const JacobianBasis *jfs = el[0]->getJacobianFuncSpace();
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el[0]->getNum());
    return;
  }

  const int numSamplingPt = jfs->getNumJacNodes();
  const int numMapNodes = jfs->getNumMapNodes();

#ifdef _ANALYSECURVEDMESH_BLAS_
  fullMatrix<double> jacobianB(numSamplingPt, numEl);
  fullMatrix<double> jacBezB(numSamplingPt, numEl);
  fullVector<double> jacBez, jacobian, jac1;

  fullMatrix<double> nodesX(numMapNodes, numEl), nodesY(numMapNodes, numEl), nodesZ(numMapNodes, numEl);
  for (int k = 0; k < numEl; ++k)
    for (int i = 0; i < numMapNodes; ++i)
    {
      MVertex *v = (el[k])->getShapeFunctionNode(i);
      nodesX(i,k) = v->x();
      nodesY(i,k) = v->y();
      nodesZ(i,k) = v->z();
    }

  jfs->getScaledJacobian(nodesX, nodesY, nodesZ, jacobianB);
  jfs->lag2Bez(jacobianB, jacBezB);
#else
  fullVector<double> jacobian(numSamplingPt);
  fullVector<double> jacBez(numSamplingPt);
#endif
  fullVector<double> subJacBez(jfs->getNumSubNodes());

  _min_pJmin = 1.7e308;
  _min_ratioJ = 1.7e308;

  for (int k = 0; k < numEl; ++k) {
    if (el[k]->getType() == TYPE_PYR && el[k]->getPolynomialOrder() > 1) {
      static int i = 0;
      if (++i == 1) {
        Msg::Error("High-order pyramids skipped (subdivision not implemented).");
        Msg::Error("Subdivision will come soon :) (before may 2014)");
      }
      continue;
    }

#ifdef _ANALYSECURVEDMESH_BLAS_
    jacBez.setAsProxy(jacBezB, k);
    jacobian.setAsProxy(jacobianB, k);
#else
    fullMatrix<double> nodesXYZ(numMapNodes,3);
    el[k]->getNodesCoord(nodesXYZ);
    jfs->getScaledJacobian(nodesXYZ,jacobian);
    jfs->lag2Bez(jacobian, jacBez);
#endif

    double minJ, maxJ = minJ = jacobian(0);

    for (int i = 1; i < numSamplingPt; ++i) {
      if (jacobian(i) < minJ) minJ = jacobian(i);
      if (jacobian(i) > maxJ) maxJ = jacobian(i);
    }

    double minB, maxB = minB = jacBez(0);

    for (int i = 1; i < numSamplingPt; ++i) {
      if (jacBez(i) < minB) minB = jacBez(i);
      if (jacBez(i) > maxB) maxB = jacBez(i);
    }

    if (_maxDepth > 1 &&
        (minJ - minB > _tol * (std::abs(minJ) + std::abs(minB)) / 2 ||
         maxB - maxJ > _tol * (std::abs(maxJ) + std::abs(maxB)) / 2   )) {

      BezierJacobian *bj = new BezierJacobian(jacBez, jfs, 0);
      std::set<BezierJacobian*> setBJ;
      std::priority_queue<BezierJacobian*, std::vector<BezierJacobian*>, lessMinB> pqMin;
      std::priority_queue<BezierJacobian*, std::vector<BezierJacobian*>, lessMaxB> pqMax;
      setBJ.insert(bj);
      pqMin.push(bj);

      int currentDepth = 0;
      while(minJ - minB > _tol * (std::abs(minJ) + std::abs(minB)) / 2 &&
            pqMin.top()->depth() < _maxDepth-1) {
        bj = pqMin.top();
        bj->subDivisions(subJacBez);
        currentDepth = bj->depth() + 1;
        setBJ.erase(bj);
        pqMin.pop();
        delete bj;

        for (int i = 0; i < jfs->getNumDivisions(); i++) {
          jacBez.setAsProxy(subJacBez, i * numSamplingPt, numSamplingPt);
          bj = new BezierJacobian(jacBez, jfs, currentDepth);
          pqMin.push(bj);
          setBJ.insert(bj);
          minJ = std::min(minJ, bj->minJ());
          maxJ = std::max(maxJ, bj->maxJ());
        }

        minB = minJ;
        maxB = maxJ;
        std::set<BezierJacobian*>::iterator it;
        for (it = setBJ.begin(); it != setBJ.end(); ++it) {
          minB = std::min(minB, (*it)->minB());
          maxB = std::max(maxB, (*it)->maxB());
        }
      }

      while (pqMin.size() > 0) {
        bj = pqMin.top();
        pqMin.pop();
        pqMax.push(bj);
      }

      while(maxB - maxJ > _tol * (std::abs(maxJ) + std::abs(maxB)) / 2 &&
            pqMax.top()->depth() < _maxDepth-1) {
        bj = pqMax.top();
        bj->subDivisions(subJacBez);
        currentDepth = bj->depth() + 1;
        setBJ.erase(bj);
        pqMax.pop();
        delete bj;

        for (int i = 0; i < jfs->getNumDivisions(); i++) {
          jacBez.setAsProxy(subJacBez, i * numSamplingPt, numSamplingPt);
          bj = new BezierJacobian(jacBez, jfs, currentDepth);
          pqMax.push(bj);
          setBJ.insert(bj);
          minJ = std::min(minJ, bj->minJ());
          maxJ = std::max(maxJ, bj->maxJ());
        }

        minB = minJ;
        maxB = maxJ;
        std::set<BezierJacobian*>::iterator it;
        for (it = setBJ.begin(); it != setBJ.end(); ++it) {
          minB = std::min(minB, (*it)->minB());
          maxB = std::max(maxB, (*it)->maxB());
        }
      }

      while (pqMax.size() > 0) {
        bj = pqMax.top();
        pqMax.pop();
        delete bj;
      }
    }

    if (data){
      if (1-minB <= _tol * minJ && maxB-1 <= _tol * maxB)
        (*data)[el[k]->getNum()].push_back(1.);
      else if (1-minB <= 1e-8)
        (*data)[el[k]->getNum()].push_back(1.);
      else
        (*data)[el[k]->getNum()].push_back(minB);
    }
    _min_pJmin = std::min(_min_pJmin, minB);
    _avg_pJmin += minB;
    _min_ratioJ = std::min(_min_ratioJ, minB/maxB);
    _avg_ratioJ += minB/maxB;
  }
}

void GMSH_AnalyseCurvedMeshPlugin::hideValid_ShowInvalid(std::vector<MElement*> &invalids)
{
  unsigned int current = 0;
  invalids.push_back(NULL);

  switch (_dim) {
   case 3 :
    for(GModel::riter it = _m->firstRegion(); it != _m->lastRegion(); it++) {
      GRegion *r = *it;
      unsigned int numType[5] = {0, 0, 0, 0, 0};
      r->getNumMeshElements(numType);

      for(int type = 0; type < 5; type++) {
        MElement *const *el = r->getStartElementType(type);
        for (unsigned int i = 0; i < numType[type]; ++i) {
          if (el[i] == invalids[current]) {
            ++current;
            el[i]->setVisibility(1);
          }
          else
            el[i]->setVisibility(0);
        }
      }
    }
    break;

   case 2 :
    for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++) {
      GFace *f = *it;
      unsigned int numType[3] = {0, 0, 0};
      f->getNumMeshElements(numType);

      for (int type = 0; type < 3; type++) {
        MElement *const *el = f->getStartElementType(type);
        for (unsigned int i = 0; i < numType[type]; ++i) {
          if (el[i] == invalids[current]) {
            ++current;
            el[i]->setVisibility(1);
          }
          else
            el[i]->setVisibility(0);
        }
      }
    }
    break;

   case 1 :
    for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++) {
      GEdge *e = *it;
      unsigned int numElement = e->getNumMeshElements();
      MElement *const *el = e->getStartElementType(0);
      for (unsigned int i = 0; i < numElement; ++i) {
        if (el[i] == invalids[current]) {
          ++current;
          el[i]->setVisibility(1);
        }
        else
          el[i]->setVisibility(0);
      }
    }
    break;

   default :
    break;
  }

  invalids.pop_back();

  switch (_dim) {
   case 3 :
    for (GModel::fiter it = _m->firstFace(); it != _m->lastFace(); it++)
      (*it)->setVisibility(0);

   case 2 :
    for (GModel::eiter it = _m->firstEdge(); it != _m->lastEdge(); it++)
      (*it)->setVisibility(0);

   case 1 :
    for (GModel::viter it = _m->firstVertex(); it != _m->lastVertex(); it++)
      (*it)->setVisibility(0);

   default :
    break;
  }
}

BezierJacobian::BezierJacobian(fullVector<double> &v, const JacobianBasis *jfs, int depth)
{
  _jacBez = v;
  _depthSub = depth;
  _jfs = jfs;

  _minJ = _maxJ = v(0);
  int i = 1;
  for (; i < jfs->getNumLagCoeff(); i++) {
    if (_minJ > v(i)) _minJ = v(i);
    if (_maxJ < v(i)) _maxJ = v(i);
  }
  _minB = _minJ;
  _maxB = _maxJ;
  for (; i < v.size(); i++) {
    if (_minB > v(i)) _minB = v(i);
    if (_maxB < v(i)) _maxB = v(i);
  }
}

bool lessMinB::operator()(BezierJacobian *bj1, BezierJacobian *bj2) const
{
  return bj1->minB() > bj2->minB();
}

bool lessMaxB::operator()(BezierJacobian *bj1, BezierJacobian *bj2) const
{
  return bj1->maxB() < bj2->maxB();
}
