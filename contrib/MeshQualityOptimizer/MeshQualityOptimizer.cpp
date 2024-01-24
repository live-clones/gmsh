// MeshQualityOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#include "GEntity.h"
#include "GFace.h"
#include "GRegion.h"
#include "GModel.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "qualityMeasures.h"
#include "MeshOptimizer.h"
#include "MeshQualityOptimizer.h"
#include "MeshOptCommon.h"
#include "ObjContribFunc.h"
#include "ObjContrib.h"
#include "ObjContribScaledNodeDispSq.h"
#include "ObjContribIdealJac.h"
#include "ObjContribInvCond.h"

struct QualPatchDefParameters : public MeshOptPatchDef {
  QualPatchDefParameters(const MeshQualOptParameters &p);
  virtual ~QualPatchDefParameters() {}
  virtual double elBadness(MElement *el, GEntity *gEnt) const;
  virtual double bndElBadness(MElement *el, GEntity *gEnt) const { return 1.; }
  virtual double maxDistance(MElement *el) const;
  virtual int inPatch(const SPoint3 &badBary, double limDist, MElement *el,
                      GEntity *gEnt) const;

private:
  bool _onlyValidity;
  bool _excludeQuad, _excludeHex, _excludePrism, _excludeBL;
  double _idealJacMin, _invCondNumMin;
  double _distanceFactor;
};

QualPatchDefParameters::QualPatchDefParameters(const MeshQualOptParameters &p)
{
  _onlyValidity = p.onlyValidity;
  _excludeQuad = p.excludeQuad;
  _excludeHex = p.excludeHex;
  _excludePrism = p.excludePrism;
  _excludeBL = p.excludeBL;
  _idealJacMin = p.minTargetIdealJac;
  _invCondNumMin = p.minTargetInvCondNum;
  strategy = (p.strategy == 1) ? MeshOptPatchDef::STRAT_ONEBYONE :
                                 MeshOptPatchDef::STRAT_DISJOINT;
  minLayers = (p.dim == 3) ? 1 : 0;
  maxLayers = p.nbLayers;
  _distanceFactor = p.distanceFactor;
  if(strategy == MeshOptPatchDef::STRAT_DISJOINT)
    weakMerge = (p.strategy == 2);
  else {
    maxPatchAdapt = p.maxPatchAdapt;
    maxLayersAdaptFact = p.maxLayersAdaptFact;
    distanceAdaptFact = p.distanceAdaptFact;
  }
}

double QualPatchDefParameters::elBadness(MElement *el, GEntity *gEnt) const
{
  const int typ = el->getType();
  if(_excludeQuad && (typ == TYPE_QUA)) return 1.;
  if(_excludeHex && (typ == TYPE_HEX)) return 1.;
  if(_excludePrism && (typ == TYPE_PRI)) return 1.;
  if(_excludeBL) {
    BoundaryLayerColumns *blc = nullptr;
    if(gEnt->dim() == 2)
      blc = static_cast<GFace *>(gEnt)->getColumns();
    else if(gEnt->dim() == 3)
      blc = static_cast<GRegion *>(gEnt)->getColumns();
    if(blc) {
      auto itBLEl = blc->_toFirst.find(el);
      if(itBLEl != blc->_toFirst.end()) return 1.;
    }
  }
  if(_onlyValidity) {
    double jMin, jMax;
    el->idealJacRange(jMin, jMax);
    return jMin - _idealJacMin;
  }
  else {
    double iCNMin, iCNMax;
    el->signedInvCondNumRange(iCNMin, iCNMax);
    return iCNMin - _invCondNumMin;
  }
}

double QualPatchDefParameters::maxDistance(MElement *el) const
{
  return _distanceFactor * el->maxEdge();
}

int QualPatchDefParameters::inPatch(const SPoint3 &badBary, double limDist,
                                    MElement *el, GEntity *gEnt) const
{
  const int typ = el->getType();
  if(_excludeQuad && (typ == TYPE_QUA)) return -1;
  if(_excludeHex && (typ == TYPE_HEX)) return -1;
  if(_excludePrism && (typ == TYPE_PRI)) return -1;
  if(_excludeBL) {
    BoundaryLayerColumns *blc = nullptr;
    if(gEnt->dim() == 2)
      blc = static_cast<GFace *>(gEnt)->getColumns();
    else if(gEnt->dim() == 3)
      blc = static_cast<GRegion *>(gEnt)->getColumns();
    if(blc) {
      auto itBLEl = blc->_toFirst.find(el);
      if(itBLEl != blc->_toFirst.end()) return -1;
    }
  }
  return testElInDist(badBary, limDist, el) ? 1 : 0;
}

void MeshQualityOptimizer(std::vector<GEntity *> &entities,
                          MeshQualOptParameters &p)
{
  Msg::StatusBar(true, "Optimizing mesh quality...");

  MeshOptParameters par;
  par.dim = p.dim;
  par.onlyVisible = p.onlyVisible;
  par.fixBndNodes = p.fixBndNodes;
  par.useGeomForPatches = p.excludeBL;
  par.useGeomForOpt = false;
  par.useBoundaries = false;
  QualPatchDefParameters patchDef(p);
  par.patchDef = &patchDef;
  par.displayInterv = 20;
  par.verbose = 3;
  par.nCurses = p.nCurses;
  par.logFileName = p.logFileName;

  ObjContribScaledNodeDispSq<ObjContribFuncSimple> nodeDistFunc(
    p.weight, Patch::LS_MINEDGELENGTH);
  ObjContribIdealJac<ObjContribFuncBarrierMovMin> minIdealJacBarFunc(1.);
  minIdealJacBarFunc.setTarget(p.minTargetIdealJac, 1.);
  ObjContribInvCondNum<ObjContribFuncBarrierMovMin> minInvCondNumBarFunc(1.);
  minInvCondNumBarFunc.setTarget(p.minTargetInvCondNum, 1.);

  MeshOptPass minJacPass;
  MeshOptPass minInvCondNumPass;
  if(p.onlyValidity) {
    minJacPass.maxParamUpdates = p.maxBarrierUpdates;
    minJacPass.maxOptIter = p.maxOptIter;
    minJacPass.contrib.push_back(&nodeDistFunc);
    minJacPass.contrib.push_back(&minIdealJacBarFunc);
    par.pass.push_back(minJacPass);
  }
  else {
    minInvCondNumPass.maxParamUpdates = p.maxBarrierUpdates;
    minInvCondNumPass.maxOptIter = p.maxOptIter;
    minInvCondNumPass.contrib.push_back(&nodeDistFunc);
    minInvCondNumPass.contrib.push_back(&minInvCondNumBarFunc);
    par.pass.push_back(minInvCondNumPass);
  }

  MeshOptimizer(entities, par);

  p.CPU = par.CPU;
  if(p.onlyValidity) {
    p.minIdealJac = minIdealJacBarFunc.getMin();
    p.maxIdealJac = minIdealJacBarFunc.getMax();
  }
  else {
    p.minInvCondNum = minInvCondNumBarFunc.getMin();
    p.maxInvCondNum = minInvCondNumBarFunc.getMax();
  }
}

void MeshQualityOptimizer(GModel *gm, MeshQualOptParameters &p)
{
  std::vector<GEntity *> entities;
  gm->getEntities(entities);
  MeshQualityOptimizer(entities, p);
}
