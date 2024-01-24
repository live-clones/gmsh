// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include <sstream>
#include <iterator>
#include <stdio.h>
#include <string.h>

#include "GmshConfig.h"
#include "HighOrderMeshOptimizer.h"
#include "MeshOptimizer.h"
#include "GModel.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "CADDistances.h"
#include "OS.h"
#include "IntegralBoundaryDist.h"
#include "GEntity.h"
#include "CADDistances.h"
#include "MeshOptCommon.h"
#include "ObjContribFunc.h"
#include "ObjContrib.h"
#include "ObjContribScaledNodeDispSq.h"
#include "ObjContribScaledJac.h"
#include "ObjContribMetricMin.h"
#include "ObjContribCADDist.h"

void exportMeshToDassault(GModel *gm, const std::string &fn, int dim)
{
  FILE *f = fopen(fn.c_str(), "w");

  std::size_t numVertices = gm->indexMeshVertices(true);
  std::vector<GEntity *> entities;
  gm->getEntities(entities);
  fprintf(f, "%lu %d\n", numVertices, dim);
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      if(dim == 2)
        fprintf(f, "%ld %22.15E %22.15E\n", v->getIndex(), v->x(), v->y());
      else if(dim == 3)
        fprintf(f, "%ld %22.15E %22.15E %22.5E\n", v->getIndex(), v->x(),
                v->y(), v->z());
    }

  if(dim == 2) {
    int nt = 0;
    int order = 0;
    for(auto itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {
      std::vector<MTriangle *> &tris = (*itf)->triangles;
      nt += tris.size();
      if(tris.size()) order = tris[0]->getPolynomialOrder();
    }
    fprintf(f, "%d %d\n", nt, (order + 1) * (order + 2) / 2);
    int count = 1;
    for(auto itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {
      std::vector<MTriangle *> &tris = (*itf)->triangles;
      for(size_t i = 0; i < tris.size(); i++) {
        MTriangle *t = tris[i];
        fprintf(f, "%d ", count++);
        for(int j = 0; j < t->getNumVertices(); j++) {
          fprintf(f, "%ld ", t->getVertex(j)->getIndex());
        }
        fprintf(f, "\n");
      }
    }
    int ne = 0;
    for(auto ite = gm->firstEdge(); ite != gm->lastEdge(); ++ite) {
      std::vector<MLine *> &l = (*ite)->lines;
      ne += l.size();
    }
    fprintf(f, "%d %d\n", ne, (order + 1));
    count = 1;
    for(auto ite = gm->firstEdge(); ite != gm->lastEdge(); ++ite) {
      std::vector<MLine *> &l = (*ite)->lines;
      for(size_t i = 0; i < l.size(); i++) {
        MLine *t = l[i];
        fprintf(f, "%d ", count++);
        for(int j = 0; j < t->getNumVertices(); j++) {
          fprintf(f, "%ld ", t->getVertex(j)->getIndex());
        }
        fprintf(f, "%d \n", (*ite)->tag());
      }
    }
  }
  fclose(f);
}

// Test intersection between sphere and segment
static bool testSegSphereIntersect(const SPoint3 &A, const SPoint3 &B,
                                   const SPoint3 &P, double const rr)
{
  // Test if separating plane between sphere and segment vertices
  // For each vertex, separation if vertex is outside sphere and P on opposite
  // side to other seg. vertex w.r.t plane of normal (vertex-P) through vertex
  const SVector3 PA(P, A), PB(P, B);
  const double aa = dot(PA, PA), ab = dot(PA, PB);
  if((aa > rr) & (ab > aa)) return false;
  const double bb = dot(PB, PB);
  if((bb > rr) & (ab > bb)) return false;

  // Test if separating plane between sphere and line
  // For A, separation if projection Q of P on (AB) lies outside the sphere
  const SVector3 AB(A, B);
  const double d = ab - aa, e = dot(AB, AB);
  const SVector3 PQ = PA * e - d * AB;
  if(dot(PQ, PQ) > rr * e * e) return false;

  // Return true (intersection) if no separation at all
  return true;
}

// Test intersection between sphere and triangle
// Inspired by Christer Ericson,
// http://realtimecollisiondetection.net/blog/?p=103
static bool testTriSphereIntersect(const SPoint3 &A, const SPoint3 &B,
                                   const SPoint3 &C, const SPoint3 &P,
                                   const double rr)
{
  // Test if separating plane between sphere and triangle plane
  const SVector3 PA(P, A), AB(A, B), AC(A, C);
  const SVector3 V = crossprod(AB, AC); // Normal to triangle plane
  const double d = dot(PA, V); // Dist. from P to triangle plane times norm of V
  const double e = dot(V, V); // Norm of V
  if(d * d > rr * e)
    return false; // Test if separating plane between sphere and triangle plane

  // Test if separating plane between sphere and triangle vertices
  const SVector3 PB(P, B), PC(P, B);
  const double aa = dot(PA, PA), ab = dot(PA, PB), ac = dot(PA, PC);
  const double bb = dot(PB, PB), bc = dot(PB, PC), cc = dot(PC, PC);
  if((aa > rr) & (ab > aa) & (ac > aa))
    return false; // For each triangle vertex, separation if vertex is outside
                  // sphere
  if((bb > rr) & (ab > bb) & (bc > bb))
    return false; // and P on opposite side to other two triangle vertices w.r.t
  if((cc > rr) & (ac > cc) & (bc > cc))
    return false; // plane of normal (vertex-P) through vertex

  // Test if separating plane between sphere and triangle edges
  const SVector3 BC(B, C);
  const double d1 = ab - aa, d2 = bc - bb, d3 = ac - cc;
  const double e1 = dot(AB, AB), e2 = dot(BC, BC), e3 = dot(AC, AC);
  const SVector3 PQ1 = PA * e1 - d1 * AB; // Q1 projection of P on line (AB)
  const SVector3 PQ2 = PB * e2 - d2 * BC; // Q2 projection of P on line (BC)
  const SVector3 PQ3 = PC * e3 + d3 * AC; // Q3 projection of P on line (AC)
  const SVector3 PQC = PC * e1 - PQ1;
  const SVector3 PQA = PA * e2 - PQ2;
  const SVector3 PQB = PB * e3 - PQ3;
  if((dot(PQ1, PQ1) > rr * e1 * e1) & (dot(PQ1, PQC) > 0))
    return false; // For A, separation if Q lies outside the sphere and if P and
                  // C
  if((dot(PQ2, PQ2) > rr * e2 * e2) & (dot(PQ2, PQA) > 0))
    return false; // are on opposite sides of plane through AB with normal PQ
  if((dot(PQ3, PQ3) > rr * e3 * e3) & (dot(PQ3, PQB) > 0))
    return false; // Same for other two vertices

  // Return true (intersection) if no separation at all
  return true;
}

// Approximate test of intersection element with circle/sphere by sampling
static bool testElInDist(const SPoint3 &p, double limDist, MElement *el)
{
  const double limDistSq = limDist * limDist;

  if(el->getDim() == 2) { // 2D?
    for(int iEd = 0; iEd < el->getNumEdges();
        iEd++) { // Loop over edges of element
      std::vector<MVertex *> edgeVert;
      el->getEdgeVertices(iEd, edgeVert);
      const SPoint3 A = edgeVert[0]->point();
      const SPoint3 B = edgeVert[1]->point();
      if(testSegSphereIntersect(A, B, p, limDistSq)) return true;
    }
  }
  else { // 3D
    for(int iFace = 0; iFace < el->getNumFaces();
        iFace++) { // Loop over faces of element
      std::vector<MVertex *> faceVert;
      el->getFaceVertices(iFace, faceVert);
      const SPoint3 A = faceVert[0]->point();
      const SPoint3 B = faceVert[1]->point();
      const SPoint3 C = faceVert[2]->point();
      if(faceVert.size() == 3) {
        if(testTriSphereIntersect(A, B, C, p, limDistSq)) { return true; }
        else {
          const SPoint3 D = faceVert[3]->point();
          if(testTriSphereIntersect(A, B, C, p, limDistSq) ||
             testTriSphereIntersect(A, C, D, p, limDistSq))
            return true;
        }
      }
    }
  }

  return false;
}

struct HOPatchDefParameters : public MeshOptPatchDef {
  HOPatchDefParameters(const OptHomParameters &p);
  virtual ~HOPatchDefParameters() {}
  virtual double elBadness(MElement *el, GEntity *gEnt) const;
  virtual double bndElBadness(MElement *el, GEntity *gEnt) const;
  virtual double maxDistance(MElement *el) const;
  virtual int inPatch(const SPoint3 &badBary, double limDist, MElement *el,
                      GEntity *gEnt) const;

private:
  double jacMin, jacMax;
  double distanceFactor;
  bool optCAD, lockCurvedBLElts;
  double optCADDistMax, optCADWeight;
};

HOPatchDefParameters::HOPatchDefParameters(const OptHomParameters &p)
{
  jacMin = p.BARRIER_MIN;
  jacMax = (p.BARRIER_MAX > 0.) ? p.BARRIER_MAX : 1.e300;
  strategy = (p.strategy == 1) ? MeshOptPatchDef::STRAT_ONEBYONE :
                                 MeshOptPatchDef::STRAT_DISJOINT;
  minLayers = (p.dim == 3) ? 1 : 0;
  maxLayers = p.nbLayers;
  distanceFactor = p.distanceFactor;
  if(strategy == MeshOptPatchDef::STRAT_DISJOINT)
    weakMerge = (p.strategy == 2);
  else {
    maxPatchAdapt = p.maxAdaptBlob;
    maxLayersAdaptFact = p.adaptBlobLayerFact;
    distanceAdaptFact = p.adaptBlobDistFact;
  }
  optCAD = p.optCAD;
  optCADDistMax = p.optCADDistMax;
  optCADWeight = p.optCADWeight;
  lockCurvedBLElts = p.lockCurvedBLElts;
}

double HOPatchDefParameters::elBadness(MElement *el, GEntity *gEnt) const
{
  double jmin, jmax;
  el->scaledJacRange(jmin, jmax);
  double badness = std::min(jmin - jacMin, 0.) + std::min(jacMax - jmax, 0.);
  return badness;
}

double HOPatchDefParameters::bndElBadness(MElement *el, GEntity *gEnt) const
{
  if(optCAD) {
    if(el->getType() == TYPE_LIN) { // 2D
      // Straight geometric line -> no distance
      if(gEnt->geomType() != GEntity::Line)
        return optCADDistMax -
               taylorDistanceEdge(static_cast<MLine *>(el), gEnt->cast2Edge());
    }
    else { // 3D
      // Straight geometric plance -> no distance
      if(gEnt->geomType() != GEntity::Plane)
        return optCADDistMax - taylorDistanceFace(el, gEnt->cast2Face());
    }
  }
  return 1.;
}

double HOPatchDefParameters::maxDistance(MElement *el) const
{
  return distanceFactor * el->maxDistToStraight();
}

int HOPatchDefParameters::inPatch(const SPoint3 &badBary, double limDist,
                                  MElement *el, GEntity *gEnt) const
{
  if(lockCurvedBLElts && (gEnt != nullptr)) {
    const std::set<MElement *> &lockedElts = gEnt->curvedBLElements;
    if(lockedElts.find(el) != lockedElts.end()) return -1;
  }
  return testElInDist(badBary, limDist, el) ? 1 : 0;
}

void HighOrderMeshOptimizer(std::vector<GEntity *> &entities,
                            OptHomParameters &p)
{
  Msg::StatusBar(true, "Optimizing high-order mesh...");

  bool order1 = false;
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      if(entities[i]->dim() > 0 &&
         entities[i]->getMeshElement(j)->getPolynomialOrder() < 2) {
        order1 = true;
        break;
      }
    }
  }
  if(order1)
    Msg::Warning(
      "Applying high-order mesh optimizer to mesh with linear elements");

  MeshOptParameters par;
  par.dim = p.dim;
  par.onlyVisible = p.onlyVisible;
  par.fixBndNodes = p.fixBndNodes;
  par.useGeomForPatches = p.lockCurvedBLElts;
  par.useGeomForOpt = false;
  par.useBoundaries = p.optCAD;
  HOPatchDefParameters patchDef(p);
  par.patchDef = &patchDef;
  par.displayInterv = 10;
  par.verbose = 3;
  par.logFileName = "";
  par.nCurses = false;

  ObjContribScaledNodeDispSq<ObjContribFuncSimple> nodeDistFunc(
    p.weight, Patch::LS_MAXNODEDIST);
  ObjContribScaledJac<ObjContribFuncBarrierMovMin> minJacBarFunc(1.);
  minJacBarFunc.setTarget(p.BARRIER_MIN, 1.);
  ObjContribScaledJac<ObjContribFuncBarrierFixMinMovMax> minMaxJacBarFunc(1.);
  minMaxJacBarFunc.setTarget(p.BARRIER_MAX, 1.);
  // ObjContribCADDistSq<ObjContribFuncSimpleTargetMax>
  // CADDistFunc(p.optCADWeight, p.optCADDistMax); CADDistFunc.setTarget(0.);
  ObjContribCADDistSq<ObjContribFuncBarrierMovMax> CADDistFunc(p.optCADWeight,
                                                               p.optCADDistMax);
  CADDistFunc.setTarget(1., 0.);
  ObjContribScaledJac<ObjContribFuncBarrierFixMin> minJacFixBarFunc(1.);
  minJacFixBarFunc.setTarget(p.BARRIER_MIN, 1.);

  MeshOptPass minJacPass;
  minJacPass.maxParamUpdates = p.optPassMax;
  minJacPass.maxOptIter = p.itMax;
  minJacPass.contrib.push_back(&nodeDistFunc);
  minJacPass.contrib.push_back(&minJacBarFunc);
  // if (p.optCAD) minJacPass.contrib.push_back(&CADDistFunc);
  par.pass.push_back(minJacPass);

  if(p.BARRIER_MAX > 0.) {
    MeshOptPass minMaxJacPass;
    minMaxJacPass.maxParamUpdates = p.optPassMax;
    minMaxJacPass.maxOptIter = p.itMax;
    minMaxJacPass.contrib.push_back(&nodeDistFunc);
    minMaxJacPass.contrib.push_back(&minMaxJacBarFunc);
    // if (p.optCAD) minMaxJacPass.contrib.push_back(&CADDistFunc);
    par.pass.push_back(minMaxJacPass);
  }

  if(p.optCAD) {
    MeshOptPass maxCADDistPass;
    maxCADDistPass.maxParamUpdates = p.optPassMax;
    maxCADDistPass.maxOptIter = p.itMax;
    maxCADDistPass.contrib.push_back(&nodeDistFunc);
    maxCADDistPass.contrib.push_back(&minJacFixBarFunc);
    maxCADDistPass.contrib.push_back(&CADDistFunc);
    par.pass.push_back(maxCADDistPass);
  }

  MeshOptimizer(entities, par);

  p.CPU = par.CPU;
  p.minJac = minMaxJacBarFunc.getMin();
  p.maxJac = minMaxJacBarFunc.getMax();

  Msg::StatusBar(true, "Done optimizing high-order mesh (%g s)", p.CPU);
}

void HighOrderMeshOptimizer(GModel *gm, OptHomParameters &p)
{
  std::vector<GEntity *> entities;
  gm->getEntities(entities);
  HighOrderMeshOptimizer(entities, p);
}
