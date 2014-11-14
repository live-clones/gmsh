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


typedef std::vector<MElement*> elVec;
typedef elVec::const_iterator elVecConstIter;
typedef std::set<MElement*> elSet;
typedef elSet::iterator elSetIter;
typedef std::set<MVertex*> vertSet;
typedef std::map<MElement*, GEntity*> elEntMap;

typedef std::map<MVertex*, elVec> vertElVecMap;
typedef std::map<MElement*, elSet> elElSetMap;
typedef std::pair<elSet, vertSet> elSetVertSetPair;


namespace {


vertSet getAllBndVertices(elSet &elements, const vertElVecMap &vertex2elements)
{
  vertSet bnd;
  for (elSetIter itE = elements.begin(); itE != elements.end(); ++itE) {
    for (int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
      const elVec &neighbours = vertex2elements.find
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


// Get neighbours of element (computes and store them only if needed)
void getElementNeighbours(MElement *el, const vertElVecMap &v2e,
                          elElSetMap &e2e, elSet &neighbours)
{
  elElSetMap::iterator it = e2e.find(el);
  if (it == e2e.end()) {                                                          // If not in e2e, compute and store
    neighbours.clear();
    for (int i = 0; i < el->getNumPrimaryVertices(); ++i) {
      const elVec &adjEl = v2e.find(el->getVertex(i))->second;
      for(elVecConstIter itA = adjEl.begin(); itA != adjEl.end(); itA++)
        if (*itA != el) neighbours.insert(*itA);
    }
    e2e.insert(std::pair<MElement*, elSet>(el, neighbours));
  }
  else neighbours = it->second;
}


elSet getSurroundingPatch(MElement *el, const MeshOptPatchDef *patchDef,
                          double limDist, int maxLayers,
                          const vertElVecMap &vertex2elements,
                          elElSetMap &element2elements,
                          const elEntMap &element2entity)
{
  const SPoint3 pnt = el->barycenter(true);

  elSet patch, currentLayer, lastLayer, excluded;

  patch.insert(el);
  lastLayer.insert(el);
  for (int d = 0; d < maxLayers; ++d) {
    currentLayer.clear();
    for (elSetIter it = lastLayer.begin(); it != lastLayer.end(); ++it) {             // Loop over elements in last layer
      elSet neighbours;
      getElementNeighbours(*it, vertex2elements, element2elements, neighbours);
      for (elSetIter itN = neighbours.begin(); itN != neighbours.end(); ++itN) {      // Loop over neighbours
        if ((lastLayer.find(*itN) == lastLayer.end()) &&                              // If neighbour already in last layer...
            (excluded.find(*itN) == excluded.end())) {                                // ... or marked as excluded, skip
          GEntity *gEnt = 0;
          if (!element2entity.empty()) {
            elEntMap::const_iterator itEl2Ent = element2entity.find(el);
            if (itEl2Ent != element2entity.end()) gEnt = itEl2Ent->second;
          }
          const int elIn = patchDef->inPatch(pnt, limDist, *itN, gEnt);               // Test if element in patch according to user-defined criteria
          if ((elIn > 0) || ((d < patchDef->minLayers) && (elIn == 0))) {
            if (patch.insert(*itN).second) currentLayer.insert(*itN);                 // If element in, insert in patch and in current layer...
          }
          else excluded.insert(*itN);                                                 // ... otherwise, mark as excluded
        }
      }
    }
    lastLayer = currentLayer;
  }

  return patch;
}


void addPatchChaintoGroup(std::set<int> &group,
                          const std::vector<std::set<int> > &groupConnect,
                          std::vector<bool> &todoPB, int iB)
{
  if (todoPB[iB]) {
    todoPB[iB] = false;
    group.insert(iB);
    const std::set<int> &connect = groupConnect[iB];
    for (std::set<int>::const_iterator itBC = connect.begin();
         itBC != connect.end(); ++itBC)
      addPatchChaintoGroup(group, groupConnect, todoPB, *itBC);
  }
}


void calcVertex2Elements(int dim, GEntity *entity,
                         vertElVecMap &vertex2elements)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    if (element->getDim() == dim)
      for (int j = 0; j < element->getNumPrimaryVertices(); ++j)
        vertex2elements[element->getVertex(j)].push_back(element);
  }
}


void calcElement2Entity(GEntity *entity, elEntMap &element2entity)
{
  for (size_t i = 0; i < entity->getNumMeshElements(); ++i) {
    MElement *element = entity->getMeshElement(i);
    element2entity.insert(std::pair<MElement*,GEntity*>(element,entity));
  }
}


std::vector<elSetVertSetPair> getConnectedPatches(const vertElVecMap &vertex2elements,
                                                  const elEntMap &element2entity,
                                                  const elSet &badElements,
                                                  const MeshOptParameters &par)
{
  Msg::Info("Starting patch generation from %i bad elements...", badElements.size());

  elElSetMap element2elements;                                                            // Element to element connectivity, built progressively

  // Contruct primary patches
  Msg::Info("Constructing %i primary patches", badElements.size());
  std::vector<elSet > primPatches;
  primPatches.reserve(badElements.size());
  for (elSet::const_iterator it = badElements.begin(); it != badElements.end(); ++it) {
    const double limDist = par.patchDef->maxDistance(*it);
    primPatches.push_back(getSurroundingPatch(*it, par.patchDef, limDist,
                                              par.patchDef->maxLayers,
                                              vertex2elements, element2elements,
                                              element2entity));
  }

  // Compute patch connectivity
  Msg::Info("Computing patch connectivity...");
  std::map<MElement*, std::set<int> > tags;
  std::vector<std::set<int> > patchConnect(primPatches.size());
  for (int iB = 0; iB < primPatches.size(); ++iB) {
    elSet &patch = primPatches[iB];
    for(elSetIter itEl = patch.begin(); itEl != patch.end(); ++itEl) {
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
  std::list<elSet > patches;
  for (std::list<std::set<int> >::iterator itG = groups.begin();
       itG != groups.end(); ++itG) {
    patches.push_back(elSet());
    for (std::set<int>::iterator itB = itG->begin(); itB != itG->end(); ++itB) {
      elSet primPatch = primPatches[*itB];
      patches.back().insert(primPatch.begin(), primPatch.end());
    }
  }

  // Store and compute patch boundaries
  Msg::Info("Computing boundaries for %i patches...", patches.size());
  std::vector<elSetVertSetPair > result;
  for (std::list<elSet >::iterator itB = patches.begin();
       itB != patches.end(); ++itB)
    result.push_back(elSetVertSetPair(*itB, getAllBndVertices(*itB, vertex2elements)));

  Msg::Info("Generated %i patches", patches.size());

  return result;
}


void optimizeConnectedPatches(const vertElVecMap &vertex2elements,
                              const elEntMap &element2entity,
                              elSet &badasses, MeshOptParameters &par)
{
  par.success = 1;

  const elEntMap &e2ePatch = par.useGeomForPatches ? element2entity : elEntMap();
  const elEntMap &e2eOpt = par.useGeomForOpt ? element2entity : elEntMap();

  std::vector<elSetVertSetPair> toOptimize = getConnectedPatches(vertex2elements,
                                                                 e2ePatch, badasses, par);

  for (int iPatch = 0; iPatch < toOptimize.size(); ++iPatch) {

    // Initialize optimization and output if asked
    if (par.verbose > 1)
      Msg::Info("Optimizing patch %i/%i composed of %i elements", iPatch,
                      toOptimize.size()-1, toOptimize[iPatch].first.size());
    MeshOpt opt(e2eOpt, toOptimize[iPatch].first, toOptimize[iPatch].second, par);
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


MElement *getWorstElement(elSet &badElts,
                          const elEntMap &element2entity,
                          const MeshOptParameters &par)
{
  double worst = 1.e300;
  MElement *worstEl = 0;

  for (elSetIter it=badElts.begin(); it!=badElts.end(); it++) {
    GEntity *gEnt = 0;
    if (!element2entity.empty()) {
      elEntMap::const_iterator itEl2Ent = element2entity.find(*it);
      if (itEl2Ent != element2entity.end()) gEnt = itEl2Ent->second;
    }
    const double val = par.patchDef->elBadness(*it, gEnt);
    if (val < worst) {
      worst = val;
      worstEl = *it;
    }
  }

  return worstEl;
}


void optimizeOneByOne(const vertElVecMap &vertex2elements,
                      const elEntMap &element2entity,
                      elSet badElts, MeshOptParameters &par)
{
  par.success = 1;

  const elEntMap &e2ePatch = par.useGeomForPatches ? element2entity : elEntMap();
  const elEntMap &e2eOpt = par.useGeomForOpt ? element2entity : elEntMap();

  const int initNumBadElts = badElts.size();
  if (par.verbose > 0) Msg::Info("%d bad elements, starting to iterate...", initNumBadElts);

  elElSetMap element2elements;                                                                // Element to element connectivity, built progressively

  // Loop over bad elements
  for (int iBadEl=0; iBadEl<initNumBadElts; iBadEl++) {

    if (badElts.empty()) break;

    // Create patch around worst element and remove it from badElts
    MElement *worstEl = getWorstElement(badElts, e2ePatch, par);
    badElts.erase(worstEl);

    // Initialize patch size to be adapted
    int maxLayers = par.patchDef->maxLayers;
    double distanceFactor = 1.;
    int success;

    // Patch adaptation loop
    for (int iAdapt=0; iAdapt<par.patchDef->maxAdaptPatch; iAdapt++) {

      // Set up patch
      const double limDist = par.patchDef->maxDistance(worstEl);
      elSet toOptimizePrim = getSurroundingPatch(worstEl, par.patchDef, limDist,
                                                 maxLayers, vertex2elements,
                                                 element2elements, e2ePatch);
      vertSet toFix = getAllBndVertices(toOptimizePrim, vertex2elements);
      elSet toOptimize;
      std::set_difference(toOptimizePrim.begin(),toOptimizePrim.end(),
                          badElts.begin(),badElts.end(),
                          std::inserter(toOptimize, toOptimize.end()));

      // Initialize optimization and output if asked
      if (par.verbose > 1)
        Msg::Info("Optimizing patch %i (max. %i remaining) composed of %4d elements",
                                            iBadEl, badElts.size(), toOptimize.size());
      MeshOpt opt(e2eOpt, toOptimize, toFix, par);
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


}


#endif


void meshOptimizer(GModel *gm, MeshOptParameters &par)
{
#if defined(HAVE_BFGS)

  double startTime = Cpu();
  if (par.verbose > 0) Msg::StatusBar(true, "Optimizing mesh...");

  std::vector<GEntity*> entities;
  gm->getEntities(entities);

  vertElVecMap vertex2elements;
  elEntMap element2entity;
  elSet badElts;
  for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity* &entity = entities[iEnt];
    if (entity->dim() != par.dim ||
        (par.onlyVisible && !entity->getVisibility())) continue;
    Msg::Info("Computing connectivity and bad elements for entity %d...",
              entity->tag());
    calcVertex2Elements(par.dim, entity, vertex2elements);
    if ((par.useGeomForPatches) || (par.useGeomForOpt))
      calcElement2Entity(entity, element2entity);
    for (int iEl = 0; iEl < entity->getNumMeshElements();iEl++) {                               // Detect bad elements
      double jmin, jmax;
      MElement *el = entity->getMeshElement(iEl);
      if ((el->getDim() == par.dim) && (par.patchDef->elBadness(el, entity) < 0.))
        badElts.insert(el);
    }
  }

  if (par.patchDef->strategy == MeshOptPatchDef::STRAT_CONNECTED)
    optimizeConnectedPatches(vertex2elements, element2entity, badElts, par);
  else if (par.patchDef->strategy == MeshOptPatchDef::STRAT_ONEBYONE)
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
