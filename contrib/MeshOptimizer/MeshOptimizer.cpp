// Copyright (C) 2013 ULg-UCL
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
// Please report all bugs and problems to the public mailing list
// <gmsh@geuz.org>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include <stdio.h>
#include <sstream>
#include <iterator>
#include <string.h>
#include <stack>
#include "GmshConfig.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MLine.h"
#include "OS.h"
#include "MeshOpt.h"
#include "MeshOptCommon.h"
#include "MeshOptimizer.h"

#if defined(HAVE_BFGS)


static std::set<MVertex *> getAllBndVertices
  (std::set<MElement*> &elements,
   const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{
  std::set<MVertex*> bnd;
  for (std::set<MElement*>::iterator itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const std::vector<MElement*> &neighbours = vertex2elements.find
        ((*itE)->getVertex(i))->second;
      for (size_t k = 0; k < neighbours.size(); ++k) {
        if (elements.find(neighbours[k]) == elements.end()) {
          for (int j = 0; j < neighbours[k]->getNumVertices(); ++j) {
            bnd.insert(neighbours[k]->getVertex(j));
          }
        }
      }
    }
  }
  return bnd;
}


// Approximate test of intersection element with circle/sphere by sampling
static bool testElInDist(const SPoint3 p, double limDist, MElement *el)
{
  const double sampleLen = 0.5*limDist;                                   // Distance between sample points

  if (el->getDim() == 2) {                                                // 2D?
    for (int iEd = 0; iEd < el->getNumEdges(); iEd++) {                   // Loop over edges of element
      MEdge ed = el->getEdge(iEd);
      const int nPts = int(ed.length()/sampleLen)+2;                      // Nb of sample points based on edge length
      for (int iPt = 0; iPt < nPts; iPt++) {                              // Loop over sample points
        const SPoint3 pt = ed.interpolate(iPt/float(nPts-1));
        if (p.distance(pt) < limDist) return true;
      }
    }
  }
  else {                                                                  // 3D
    for (int iFace = 0; iFace < el->getNumFaces(); iFace++) {             // Loop over faces of element
      MFace face = el->getFace(iFace);
      double lMax = 0.;                                                   // Max. edge length in face
      const int nVert = face.getNumVertices();
      for (int iEd = 0; iEd < nVert; iEd++)
        lMax = std::max(lMax, face.getEdge(iEd).length());
      const int nPts = int(lMax/sampleLen)+2;                             // Nb of sample points based on max. edge length in face
      for (int iPt0 = 0; iPt0 < nPts; iPt0++) {
        const double u = iPt0/float(nPts-1);
        for (int iPt1 = 0; iPt1 < nPts; iPt1++) {                         // Loop over sample points
          const double vMax = (nVert == 3) ? 1.-u : 1.;
          const SPoint3 pt = face.interpolate(u, vMax*iPt1/float(nPts-1));
          if (p.distance(pt) < limDist) return true;
        }
      }
    }
  }

  return false;
}


static std::set<MElement*> getSurroundingPatch(MElement *el, int minLayers,
                            int maxLayers, double limDist,
                            const std::map<MVertex*, std::vector<MElement*> > &vertex2elements)
{

  const SPoint3 pnt = el->barycenter(true);

  std::set<MElement*> patch;
  std::list<MElement*> currentLayer, lastLayer;

  patch.insert(el);
  lastLayer.push_back(el);
  for (int d = 0; d < maxLayers; ++d) {
    currentLayer.clear();
    for (std::list<MElement*>::iterator it = lastLayer.begin();
         it != lastLayer.end(); ++it) {
      for (int i = 0; i < (*it)->getNumPrimaryVertices(); ++i) {
        const std::vector<MElement*> &neighbours = vertex2elements.find
          ((*it)->getVertex(i))->second;
        for (std::vector<MElement*>::const_iterator itN = neighbours.begin();
             itN != neighbours.end(); ++itN){
          if ((d < minLayers) || testElInDist(pnt, limDist, *itN))
            if (patch.insert(*itN).second) currentLayer.push_back(*itN);  // Assume that if an el is too far, its neighbours are too far as well
        }
      }
    }
    lastLayer = currentLayer;
  }

  return patch;
}


static void addPatchChaintoGroup(std::set<int> &group,
                                const std::vector<std::set<int> > &groupConnect,
                                std::vector<bool> &todoPB, int iB)
{
  if (todoPB[iB]) {
    todoPB[iB] = false;
    group.insert(iB);
    const std::set<int> &connect = groupConnect[iB];
    for (std::set<int>::const_iterator itBC = connect.begin(); itBC != connect.end(); ++itBC)
      addPatchChaintoGroup(group, groupConnect, todoPB, *itBC);
  }
}


static void calcVertex2Elements(int dim, GEntity *entity,
                                std::map<MVertex*, std::vector<MElement *> > &vertex2elements)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    if (element->getDim() == dim)
      for (int j = 0; j < element->getNumPrimaryVertices(); ++j)
        vertex2elements[element->getVertex(j)].push_back(element);
  }
}


static void calcElement2Entity(GEntity *entity, std::map<MElement*,GEntity*> &element2entity)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    element2entity.insert(std::pair<MElement*,GEntity*>(element,entity));
  }
}


static std::vector<std::pair<std::set<MElement*>, std::set<MVertex*> > > getConnectedPatches
  (const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
   const std::set<MElement*> &badElements, const MeshOptParameters &par)
{

  Msg::Info("Starting patch generation from %i bad elements...", badElements.size());

  // Contruct primary patches
  Msg::Info("Constructing %i primary patches", badElements.size());
  std::vector<std::set<MElement*> > primPatches;
  primPatches.reserve(badElements.size());
  for (std::set<MElement*>::const_iterator it = badElements.begin(); it != badElements.end(); ++it) {
    const double limDist = par.patchDef->maxDistance(*it);
    primPatches.push_back(getSurroundingPatch(*it, par.patchDef->minLayers,
                            par.patchDef->maxLayers, limDist, vertex2elements));
  }

  // Compute patch connectivity
  Msg::Info("Computing patch connectivity...");
  std::map<MElement*, std::set<int> > tags;
  std::vector<std::set<int> > patchConnect(primPatches.size());
  for (int iB = 0; iB < primPatches.size(); ++iB) {
    std::set<MElement*> &patch = primPatches[iB];
    for(std::set<MElement*>::iterator itEl = patch.begin(); itEl != patch.end(); ++itEl) {
      std::set<int> &patchInd = tags[*itEl];
      if (!patchInd.empty() && (badElements.find(*itEl) != badElements.end() ||
                               !par.patchDef->weakMerge)) {
        for (std::set<int>::iterator itBS = patchInd.begin();
             itBS != patchInd.end(); ++itBS) patchConnect[*itBS].insert(iB);
        patchConnect[iB].insert(patchInd.begin(), patchInd.end());
      }
      patchInd.insert(iB);
    }
  }

  // Identify groups of connected patches
  Msg::Info("Identifying groups of primary patches...");
  std::list<std::set<int> > groups;
  std::vector<bool> todoPB(primPatches.size(), true);
  for (int iB = 0; iB < primPatches.size(); ++iB)
    if (todoPB[iB]) {
      std::set<int> group;
      addPatchChaintoGroup(group, patchConnect, todoPB, iB);
      groups.push_back(group);
    }

  // Merge primary patches according to groups
  Msg::Info("Merging primary patches into %i patches...", groups.size());
  std::list<std::set<MElement*> > patches;
  for (std::list<std::set<int> >::iterator itG = groups.begin();
       itG != groups.end(); ++itG) {
    patches.push_back(std::set<MElement*>());
    for (std::set<int>::iterator itB = itG->begin(); itB != itG->end(); ++itB) {
      std::set<MElement*> primPatch = primPatches[*itB];
      patches.back().insert(primPatch.begin(), primPatch.end());
    }
  }

  // Store and compute patch boundaries
  Msg::Info("Computing boundaries for %i patches...", patches.size());
  std::vector<std::pair<std::set<MElement *>, std::set<MVertex*> > > result;
  for (std::list<std::set<MElement*> >::iterator itB = patches.begin();
       itB != patches.end(); ++itB)
    result.push_back(std::pair<std::set<MElement*>, std::set<MVertex*> >
                     (*itB, getAllBndVertices(*itB, vertex2elements)));

  Msg::Info("Generated %i patches", patches.size());

  return result;
}


static void optimizeConnectedPatches
  (const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
   const std::map<MElement*,GEntity*> &element2entity,
   std::set<MElement*> &badasses, MeshOptParameters &par)
{
  par.success = 1;

  std::vector<std::pair<std::set<MElement*>, std::set<MVertex*> > > toOptimize =
                              getConnectedPatches(vertex2elements, badasses, par);

  for (int iPatch = 0; iPatch < toOptimize.size(); ++iPatch) {

    // Initialize optimization and output if asked
    if (par.verbose > 1)
      Msg::Info("Optimizing patch %i/%i composed of %i elements", iPatch,
                      toOptimize.size()-1, toOptimize[iPatch].first.size());
    MeshOpt opt(element2entity, toOptimize[iPatch].first,
                            toOptimize[iPatch].second, par);
    if (par.verbose > 3) {
      std::ostringstream ossI1;
      ossI1 << "initial_patch-" << iPatch << ".msh";
      opt.patch.writeMSH(ossI1.str().c_str());
    }

    // Optimize patch
    int success = -1;
    if (opt.patch.nPC() > 0)
      success = opt.optimize(par);
    else
      if (par.verbose > 1) Msg::Info("Patch %i has no degree of freedom, skipping", iPatch);

    if (par.verbose > 3) {
      std::ostringstream ossI2;
      ossI2 << "final_patch-" << iPatch << ".msh";
      opt.patch.writeMSH(ossI2.str().c_str());
    }

    // Evaluate mesh and update it if (partial) success
    opt.updateResults();
    if (success >= 0) opt.patch.updateGEntityPositions();

    //#pragma omp critical
    par.success = std::min(par.success, success);
  }

}


static MElement *getWorstElement(std::set<MElement*> &badElts, const MeshOptParameters &par)
{
  double worst = 1.e300;
  MElement *worstEl = 0;

  for (std::set<MElement*>::iterator it=badElts.begin(); it!=badElts.end(); it++) {
    const double val = par.patchDef->elBadness(*it);
    if (val < worst) {
      worst = val;
      worstEl = *it;
    }
  }

  return worstEl;
}


static void optimizeOneByOne
  (const std::map<MVertex*, std::vector<MElement *> > &vertex2elements,
   const std::map<MElement*,GEntity*> &element2entity,
   std::set<MElement*> badElts, MeshOptParameters &par)
{
  par.success = 1;

  const int initNumBadElts = badElts.size();
  if (par.verbose > 0) Msg::Info("%d bad elements, starting to iterate...", initNumBadElts);

  // Loop over bad elements
  for (int iBadEl=0; iBadEl<initNumBadElts; iBadEl++) {

    if (badElts.empty()) break;

    // Create patch around worst element and remove it from badElts
    MElement *worstEl = getWorstElement(badElts, par);
    badElts.erase(worstEl);

    // Initialize patch size to be adapted
    int maxLayers = par.patchDef->maxLayers;
    double distanceFactor = 1.;
    int success;

    // Patch adaptation loop
    for (int iAdapt=0; iAdapt<par.patchDef->maxAdaptPatch; iAdapt++) {

      // Set up patch
      const double limDist = par.patchDef->maxDistance(worstEl);
      std::set<MElement*> toOptimizePrim = getSurroundingPatch(worstEl, par.patchDef->minLayers,
                                                          maxLayers, limDist, vertex2elements);
      std::set<MVertex*> toFix = getAllBndVertices(toOptimizePrim, vertex2elements);
      std::set<MElement*> toOptimize;
      std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),
                          badElts.begin(),badElts.end(),
                          std::inserter(toOptimize, toOptimize.end()));

      // Initialize optimization and output if asked
      if (par.verbose > 1)
        Msg::Info("Optimizing patch %i (max. %i remaining) composed of %4d elements",
                                            iBadEl, badElts.size(), toOptimize.size());
      MeshOpt opt(element2entity, toOptimize, toFix, par);
      if (par.verbose > 3) {
        std::ostringstream ossI1;
        ossI1 << "initial_patch-" << iBadEl << ".msh";
        opt.patch.writeMSH(ossI1.str().c_str());
      }

      // Optimize patch
      if (opt.patch.nPC() == 0) {
        success = -1;
        Msg::Info("Patch %i (adapt #%i) has no degree of freedom, skipping", iBadEl, iAdapt);
      }
      else
        success = opt.optimize(par);

      // Output if asked
      if (par.verbose > 3) {
        std::ostringstream ossI2;
        ossI2 << "final_patch-" << iBadEl << "_adapt-" << iAdapt <<".msh";
        opt.patch.writeMSH(ossI2.str().c_str());
      }

      // If (partial) success, update mesh and break adaptation loop, otherwise adapt
      if ((success > 0) || (iAdapt == par.patchDef->maxAdaptPatch-1)) {
        opt.updateResults();
        if (success >= 0) {
          opt.patch.updateGEntityPositions();
          break;
        }
        else {
          distanceFactor *= par.patchDef->distanceAdaptFact;
          maxLayers *= par.patchDef->maxLayersAdaptFact;
          if (par.verbose > 1)
            Msg::Info("Patch %i failed (adapt #%i), adapting with increased size", iBadEl, iAdapt);
        }
      }

    }                                                                       // End of adaptation loop

    if (par.verbose > 1)
      switch (success) {
        case 1: Msg::Info("Patch %i succeeded", iBadEl); break;
        case 0:
          Msg::Info("Patch %i partially failed (measure "
                    "above critical value but below target)", iBadEl);
          break;
        case -1: Msg::Info("Patch %i failed", iBadEl); break;
      }

    par.success = std::min(par.success, success);

  }
}

#endif


void meshOptimizer(GModel *gm, MeshOptParameters &par)
{
#if defined(HAVE_BFGS)

  double startTime = Cpu();
  if (par.verbose > 0) Msg::StatusBar(true, "Optimizing mesh...");

  std::vector<GEntity*> entities;
  gm->getEntities(entities);

  std::map<MVertex*, std::vector<MElement *> > vertex2elements;
  std::map<MElement*,GEntity*> element2entity;
  std::set<MElement*> badElts;
  for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity* &entity = entities[iEnt];
    if (entity->dim() != par.dim ||
        (par.onlyVisible && !entity->getVisibility())) continue;
    Msg::Info("Computing connectivity and bad elements for entity %d...",
              entity->tag());
    calcVertex2Elements(par.dim,entity,vertex2elements);
    for (int iEl = 0; iEl < entity->getNumMeshElements();iEl++) {       // Detect bad elements
      double jmin, jmax;
      MElement *el = entity->getMeshElement(iEl);
//      if (el->getDim() == par.dim) {
//        if (par.patchJac.test) {
//          el->scaledJacRange(jmin, jmax);
//          if (jmin < par.patchJac.min || jmax > par.patchJac.max) badElts.insert(el);
//        }
//      }
      if ((el->getDim() == par.dim) && (par.patchDef->elBadness(el) < 0.)) badElts.insert(el);
    }
  }

  if (par.patchDef->strategy == MeshOptParameters::STRAT_CONNECTED)
    optimizeConnectedPatches(vertex2elements, element2entity, badElts, par);
  else if (par.patchDef->strategy == MeshOptParameters::STRAT_ONEBYONE)
    optimizeOneByOne(vertex2elements, element2entity, badElts, par);
  else
    Msg::Error("Unknown strategy %d for mesh optimization", par.patchDef->strategy);

  if (par.verbose > 0) {
    if (par.success == 1)
      Msg::Info("Optimization succeeded");
    else if (par.success == 0)
      Msg::Warning("Optimization partially failed (all measures above critical "
                    "value, but some below target)");
    else if (par.success == -1)
      Msg::Error("Optimization failed (some measures below critical value)");
    par.CPU = Cpu()-startTime;
    Msg::StatusBar(true, "Done optimizing mesh (%g s)", par.CPU);
  }


#else
  Msg::Error("Mesh optimizer requires BFGS");
#endif

}
