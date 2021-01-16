// MeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
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

#include <stdio.h>
#include <sstream>
#include <iterator>
#include <limits>
#include <string.h>
#include <stack>
#include "Context.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "OS.h"
#include "MeshOpt.h"
#include "MeshOptCommon.h"
#include "MeshOptimizer.h"

typedef std::vector<MElement *> elVec;
typedef elVec::const_iterator elVecConstIter;
typedef std::set<MElement *> elSet;
typedef elSet::iterator elSetIter;
typedef std::set<MVertex *> vertSet;
typedef std::map<MElement *, GEntity *> elEntMap;
typedef std::map<MElement *, MElement *> elElMap;

typedef std::map<MVertex *, elVec> vertElVecMap;
typedef std::map<MElement *, elSet> elElSetMap;
typedef std::pair<elSet, vertSet> elSetVertSetPair;

namespace {

  vertSet getAllBndVertices(elSet &elements,
                            const vertElVecMap &vertex2elements)
  {
    vertSet bnd;
    for(auto itE = elements.begin(); itE != elements.end(); ++itE) {
      for(int i = 0; i < (*itE)->getNumPrimaryVertices(); ++i) {
        const elVec &neighbours =
          vertex2elements.find((*itE)->getVertex(i))->second;
        for(size_t k = 0; k < neighbours.size(); ++k) {
          if(elements.find(neighbours[k]) == elements.end()) {
            for(int j = 0; j < neighbours[k]->getNumVertices(); ++j) {
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
    auto it = e2e.find(el);
    if(it == e2e.end()) { // If not in e2e, compute and store
      neighbours.clear();
      for(int i = 0; i < el->getNumPrimaryVertices(); ++i) {
        const elVec &adjEl = v2e.find(el->getVertex(i))->second;
        for(auto itA = adjEl.begin(); itA != adjEl.end(); itA++)
          if(*itA != el) neighbours.insert(*itA);
      }
      e2e.insert(std::pair<MElement *, elSet>(el, neighbours));
    }
    else
      neighbours = it->second;
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
    for(int d = 0; d < maxLayers; ++d) {
      currentLayer.clear();
      for(auto it = lastLayer.begin(); it != lastLayer.end();
          ++it) { // Loop over elements in last layer
        elSet neighbours;
        getElementNeighbours(*it, vertex2elements, element2elements,
                             neighbours);
        for(auto itN = neighbours.begin(); itN != neighbours.end();
            ++itN) { // Loop over neighbours
          if((lastLayer.find(*itN) ==
              lastLayer.end()) && // If neighbour already in last layer...
             (excluded.find(*itN) ==
              excluded.end())) { // ... or marked as excluded, skip
            GEntity *gEnt = nullptr;
            if(!element2entity.empty()) {
              auto itEl2Ent = element2entity.find(el);
              if(itEl2Ent != element2entity.end()) gEnt = itEl2Ent->second;
            }
            const int elIn = patchDef->inPatch(
              pnt, limDist, *itN, gEnt); // Test if element in patch according
                                         // to user-defined criteria
            if((elIn > 0) || ((d < patchDef->minLayers) && (elIn == 0))) {
              if(patch.insert(*itN).second)
                currentLayer.insert(*itN); // If element in, insert in patch and
                                           // in current layer...
            }
            else
              excluded.insert(*itN); // ... otherwise, mark as excluded
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
    if(todoPB[iB]) {
      todoPB[iB] = false;
      group.insert(iB);
      const std::set<int> &connect = groupConnect[iB];
      for(auto itBC = connect.begin(); itBC != connect.end(); ++itBC)
        addPatchChaintoGroup(group, groupConnect, todoPB, *itBC);
    }
  }

  void calcVertex2Elements(int dim, GEntity *entity,
                           vertElVecMap &vertex2elements)
  {
    for(size_t i = 0; i < entity->getNumMeshElements(); ++i) {
      MElement *element = entity->getMeshElement(i);
      if(element->getDim() == dim)
        for(int j = 0; j < element->getNumPrimaryVertices(); ++j)
          vertex2elements[element->getVertex(j)].push_back(element);
    }
  }

  void calcElement2Entity(GEntity *entity, elEntMap &element2entity)
  {
    for(size_t i = 0; i < entity->getNumMeshElements(); ++i) {
      MElement *element = entity->getMeshElement(i);
      element2entity.insert(std::pair<MElement *, GEntity *>(element, entity));
    }
  }

  MElement *getFaceInBndElements(const MFace &f,
                                 std::vector<GFace *> const &gFaces)
  {
    for(auto itGF = gFaces.begin(); itGF != gFaces.end(); itGF++) {
      if(f.getNumVertices() == 3) {
        std::vector<MTriangle *> &tris = (*itGF)->triangles;
        for(int iEl = 0; iEl < tris.size(); iEl++)
          if(tris[iEl]->getFace(0) == f) return tris[iEl];
      }
      else {
        std::vector<MQuadrangle *> &quads = (*itGF)->quadrangles;
        for(int iEl = 0; iEl < quads.size(); iEl++)
          if(quads[iEl]->getFace(0) == f) return quads[iEl];
      }
    }
    return nullptr;
  }

  MElement *getEdgeInBndElements(const MEdge &e,
                                 std::vector<GEdge *> const &gEdges)
  {
    for(auto itGE = gEdges.begin(); itGE != gEdges.end(); itGE++) {
      std::vector<MLine *> &lines = (*itGE)->lines;
      for(int iEl = 0; iEl < lines.size(); iEl++)
        if(lines[iEl]->getEdge(0) == e) return lines[iEl];
    }
    return nullptr;
  }

  void calcBndInfo(GEntity *entity, elElMap &el2BndEl, elEntMap &bndEl2Ent)
  {
    typedef std::vector<GFace *> GFaceList;
    typedef std::vector<GEdge *> GEdgeList;

    if(entity->dim() == 3) { // 3D

      // Fill boundary element -> GEntity connectivity
      GFaceList gFaces = entity->faces();
      for(auto itGF = gFaces.begin(); itGF != gFaces.end(); itGF++) {
        std::vector<MTriangle *> &tris = (*itGF)->triangles;
        for(int i = 0; i < tris.size(); i++)
          bndEl2Ent.insert(std::pair<MElement *, GEntity *>(tris[i], *itGF));
        std::vector<MQuadrangle *> &quads = (*itGF)->quadrangles;
        for(int i = 0; i < quads.size(); i++)
          bndEl2Ent.insert(std::pair<MElement *, GEntity *>(quads[i], *itGF));
      }

      // Fill element -> boundary element connectivity
      for(int iEl = 0; iEl < entity->getNumMeshElements(); iEl++) {
        MElement *el = entity->getMeshElement(iEl);
        int nBndVert = 0; // Compute nb. of bnd. vertices in element
        for(int iV = 0; iV < el->getNumPrimaryVertices(); iV++)
          if(el->getVertex(iV)->onWhat() != entity) nBndVert++;
        if(nBndVert >=
           3) // If more than 3 primary vert. on bnd., look for bnd. face(s)
          for(int iF = 0; iF < el->getNumFaces(); iF++) {
            MElement *bndEl = getFaceInBndElements(el->getFace(iF), gFaces);
            if(bndEl != nullptr)
              el2BndEl.insert(std::pair<MElement *, MElement *>(el, bndEl));
          }
      }
    }
    else { // 2D

      // Fill boundary element -> GEntity connectivity
      GEdgeList gEdges = entity->edges();
      for(auto itGE = gEdges.begin(); itGE != gEdges.end(); itGE++) {
        std::vector<MLine *> &lines = (*itGE)->lines;
        for(int i = 0; i < lines.size(); i++)
          bndEl2Ent.insert(std::pair<MElement *, GEntity *>(lines[i], *itGE));
      }

      // Fill element -> boundary element connectivity
      for(int iEl = 0; iEl < entity->getNumMeshElements(); iEl++) {
        MElement *el = entity->getMeshElement(iEl);
        int nBndVert = 0; // Compute nb. of bnd. vertices in element
        for(int iV = 0; iV < el->getNumPrimaryVertices(); iV++)
          if(el->getVertex(iV)->onWhat() != entity) nBndVert++;
        if(nBndVert >=
           2) // If more than 2 primary vert. on bnd., look for bnd. edge(s)
          for(int iE = 0; iE < el->getNumEdges(); iE++) {
            MElement *bndEl = getEdgeInBndElements(el->getEdge(iE), gEdges);
            if(bndEl != nullptr)
              el2BndEl.insert(std::pair<MElement *, MElement *>(el, bndEl));
          }
      }
    }
  }

  std::vector<elSetVertSetPair>
  getDisjointPatches(const vertElVecMap &vertex2elements,
                     const elEntMap &element2entity, const elSet &badElements,
                     const MeshOptParameters &par)
  {
    if(par.nCurses) {
      mvprintCenter(16, "Starting patch generation from %5i bad elements...",
                    badElements.size());
    }
    Msg::Info("Starting patch generation from %i bad elements...",
              badElements.size());

    elElSetMap
      element2elements; // Element to element connectivity, built progressively

    // Contruct primary patches
    Msg::Info("Constructing %i primary patches", badElements.size());
    std::vector<elSet> primPatches;
    primPatches.reserve(badElements.size());
    for(auto it = badElements.begin(); it != badElements.end(); ++it) {
      const double limDist = par.patchDef->maxDistance(*it);
      primPatches.push_back(
        getSurroundingPatch(*it, par.patchDef, limDist, par.patchDef->maxLayers,
                            vertex2elements, element2elements, element2entity));
    }

    // Compute patch connectivity
    Msg::Info("Computing patch connectivity...");
    std::map<MElement *, std::set<int> > tags;
    std::vector<std::set<int> > patchConnect(primPatches.size());
    for(int iB = 0; iB < primPatches.size(); ++iB) {
      elSet &patch = primPatches[iB];
      for(auto itEl = patch.begin(); itEl != patch.end(); ++itEl) {
        std::set<int> &patchInd = tags[*itEl];
        if(!patchInd.empty() && (badElements.find(*itEl) != badElements.end() ||
                                 !par.patchDef->weakMerge)) {
          for(auto itBS = patchInd.begin(); itBS != patchInd.end(); ++itBS)
            patchConnect[*itBS].insert(iB);
          patchConnect[iB].insert(patchInd.begin(), patchInd.end());
        }
        patchInd.insert(iB);
      }
    }

    // Identify groups of connected patches
    Msg::Info("Identifying groups of primary patches...");
    std::list<std::set<int> > groups;
    std::vector<bool> todoPB(primPatches.size(), true);
    for(int iB = 0; iB < primPatches.size(); ++iB)
      if(todoPB[iB]) {
        std::set<int> group;
        addPatchChaintoGroup(group, patchConnect, todoPB, iB);
        groups.push_back(group);
      }

    // Merge primary patches according to groups
    Msg::Info("Merging primary patches into %i patches...", groups.size());
    std::list<elSet> patches;
    for(auto itG = groups.begin(); itG != groups.end(); ++itG) {
      patches.push_back(elSet());
      for(auto itB = itG->begin(); itB != itG->end(); ++itB) {
        elSet primPatch = primPatches[*itB];
        patches.back().insert(primPatch.begin(), primPatch.end());
      }
    }

    // Store and compute patch boundaries
    Msg::Info("Computing boundaries for %i patches...", patches.size());
    std::vector<elSetVertSetPair> result;
    for(auto itB = patches.begin(); itB != patches.end(); ++itB)
      result.push_back(
        elSetVertSetPair(*itB, getAllBndVertices(*itB, vertex2elements)));

    Msg::Info("Generated %i patches", patches.size());

    return result;
  }

  // Get (bad) boundary elements adjacent to patch
  void getAdjacentBndElts(const elElMap &el2BndEl, const elEntMap &bndEl2Ent,
                          const elSet &elts, elSet &bndElts,
                          MeshOptParameters &par)
  {
    for(auto itEl = elts.begin(); itEl != elts.end(); itEl++) {
      auto itBndEl = el2BndEl.find(*itEl);
      if(itBndEl != el2BndEl.end()) {
        MElement *bndEl = itBndEl->second;
        auto itEnt = bndEl2Ent.find(bndEl);
        if(par.patchDef->bndElBadness(bndEl, itEnt->second) < 0.)
          bndElts.insert(bndEl);
      }
    }
  }

  void
  displayMinMaxVal(int nbPatchSuccess[3],
                   std::vector<std::string> &objFunctionNames,
                   std::vector<std::pair<double, double> > newObjFunctionRange)
  {
    for(int i = 0; i < objFunctionNames.size(); i++) {
      if(nbPatchSuccess[0] > 0)
        mvcolor(6, true);
      else if(nbPatchSuccess[1] > 0)
        mvcolor(8, true);
      else
        mvcolor(7, true);
      mvprintRight(28 + i, "%s on optimized patches: min %+.6e max %+.6e",
                   objFunctionNames[i].c_str(), newObjFunctionRange[i].first,
                   newObjFunctionRange[i].second);
      if(nbPatchSuccess[0] > 0)
        mvcolor(6, false);
      else if(nbPatchSuccess[1] > 0)
        mvcolor(8, false);
      else
        mvcolor(7, false);
    }
  }

  void displayResultTable(int nbPatchSuccess[3], int nbPatch)
  {
    mvcolor(1, true);
    mvprintLeft(28, " TOTAL PATCHES : %4i ", nbPatch);
    mvcolor(1, false);
    mvcolor(3, true);
    mvprintLeft(29, " Fail          : %4i ", nbPatchSuccess[0]);
    mvcolor(3, false);
    mvcolor(5, true);
    mvprintLeft(30, " Partial fail  : %4i ", nbPatchSuccess[1]);
    mvcolor(5, false);
    mvcolor(4, true);
    mvprintLeft(31, " Success       : %4i ", nbPatchSuccess[2]);
    mvcolor(4, false);
    mvcolor(1, true);
    mvprintLeft(32, " REMAINING     : %4i ",
                nbPatch - nbPatchSuccess[0] - nbPatchSuccess[1] -
                  nbPatchSuccess[2]);
    mvcolor(1, false);
  }

  void updateDisplayPatchHistory(std::list<char *> &_patchHistory,
                                 const std::string &objFunctionStr, int iPatch,
                                 int iAdapt)
  {
    if(_patchHistory.size() < 8) { _patchHistory.push_front(new char[1000]); }
    else {
      _patchHistory.push_front(_patchHistory.back());
      _patchHistory.pop_back();
    }
    if(iAdapt < 0)
      sprintf(_patchHistory.front(), "Patch %i", iPatch);
    else
      sprintf(_patchHistory.front(), "Patch %i - Adaptation step %i", iPatch,
              iAdapt);
    if(_patchHistory.size() < 8) { _patchHistory.push_front(new char[1000]); }
    else {
      _patchHistory.push_front(_patchHistory.back());
      _patchHistory.pop_back();
    }
    sprintf(_patchHistory.front(), "%s", objFunctionStr.c_str());
    mvprintList(9, -8, _patchHistory, 2);
  }

  void optimizeDisjointPatches(const vertElVecMap &vertex2elements,
                               const elEntMap &element2entity,
                               const elElMap &el2BndEl,
                               const elEntMap &bndEl2Ent, elSet &badasses,
                               MeshOptParameters &par)
  {
    int nbPatchSuccess[3] = {0, 0, 0}; // 0: fail, 1: partial fail, 2: success
    std::list<char *> _patchHistory;
    std::vector<std::pair<double, double> > newObjFunctionRange;
    std::vector<std::string> objFunctionNames;

    par.success = 1;

    const elEntMap &e2ePatch =
      par.useGeomForPatches ? element2entity : elEntMap();
    const elEntMap &e2eOpt = par.useGeomForOpt ? element2entity : elEntMap();

    // Get patches
    std::vector<elSetVertSetPair> toOptimize =
      getDisjointPatches(vertex2elements, e2ePatch, badasses, par);

    // Get boundary elements adjacent to patch if required
    std::vector<elSet> bndElts;
    bndElts.resize(toOptimize.size());
    if(!el2BndEl.empty()) {
      for(int iPatch = 0; iPatch < toOptimize.size(); ++iPatch)
        getAdjacentBndElts(el2BndEl, bndEl2Ent, toOptimize[iPatch].first,
                           bndElts[iPatch], par);
    }
    if(par.nCurses) displayResultTable(nbPatchSuccess, toOptimize.size());

#if defined(_OPENMP)
//#pragma omp parallel for schedule(dynamic)
#endif
    for(int iPatch = 0; iPatch < toOptimize.size(); ++iPatch) {
      // Initialize optimization and output if asked
      if(par.nCurses) {
        mvbold(true);
        mvprintCenter(10, " PATCH %5i ", iPatch);
        mvbold(false);
      }
      if(par.verbose > 1)
        Msg::Info("Optimizing patch %i/%i composed of %i elements, "
                  "%i boundary elements",
                  iPatch, toOptimize.size() - 1,
                  toOptimize[iPatch].first.size(), bndElts[iPatch].size());
      MeshOpt opt(e2eOpt, bndEl2Ent, toOptimize[iPatch].first,
                  toOptimize[iPatch].second, bndElts[iPatch], par);
      if(par.verbose > 3) {
        std::ostringstream ossI1;
        ossI1 << "initial_patch-" << iPatch << ".msh";
        opt.patch.writeMSH(ossI1.str().c_str());
      }

      // Optimize patch
      int success = -1;
      if(opt.patch.nPC() > 0)
        success = opt.optimize(par);
      else if(par.verbose > 1)
        Msg::Info("Patch %i has no degree of freedom, skipping", iPatch);

      if(par.verbose > 3) {
        std::ostringstream ossI2;
        ossI2 << "final_patch-" << iPatch << ".msh";
        opt.patch.writeMSH(ossI2.str().c_str());
      }

      // Evaluate mesh and update it if (partial) success
      opt.updateResults();

#if defined(_OPENMP)
//#pragma omp critical
#endif
      {
        if(newObjFunctionRange.size() == 0) {
          newObjFunctionRange = opt.objFunction()->minMax();
          objFunctionNames = opt.objFunction()->names();
        }
        else {
          for(int i = 0; i < newObjFunctionRange.size(); i++) {
            newObjFunctionRange[i].first =
              std::min(newObjFunctionRange[i].first,
                       opt.objFunction()->minMax()[i].first);
            newObjFunctionRange[i].second =
              std::max(newObjFunctionRange[i].second,
                       opt.objFunction()->minMax()[i].second);
          }
        }
      }

      if(success >= 0) opt.patch.updateGEntityPositions();

#if defined(_OPENMP)
//#pragma omp critical
#endif
      {
        par.success = std::min(par.success, success);
        nbPatchSuccess[success + 1]++;
      }

      if(par.nCurses) {
        displayMinMaxVal(nbPatchSuccess, objFunctionNames, newObjFunctionRange);
        displayResultTable(nbPatchSuccess, toOptimize.size());
        updateDisplayPatchHistory(_patchHistory, opt.objFunction()->minMaxStr(),
                                  iPatch, -1);
      }
    }

    while(_patchHistory.size() > 0) {
      delete[] _patchHistory.back();
      _patchHistory.pop_back();
    }
  }

  MElement *getWorstElement(elSet &badElts, const elEntMap &element2entity,
                            const MeshOptParameters &par)
  {
    double worst = 1.e300;
    MElement *worstEl = nullptr;

    for(auto it = badElts.begin(); it != badElts.end(); it++) {
      GEntity *gEnt = nullptr;
      if(!element2entity.empty()) {
        auto itEl2Ent = element2entity.find(*it);
        if(itEl2Ent != element2entity.end()) gEnt = itEl2Ent->second;
      }
      const double val = par.patchDef->elBadness(*it, gEnt);
      if(val < worst) {
        worst = val;
        worstEl = *it;
      }
    }

    return worstEl;
  }

  void optimizeOneByOne(const vertElVecMap &vertex2elements,
                        const elEntMap &element2entity, const elElMap &el2BndEl,
                        const elEntMap &bndEl2Ent, elSet badElts,
                        MeshOptParameters &par)
  {
    int nbPatchSuccess[3] = {0, 0, 0}; // 0: fail, 1: partial fail, 2: success
    std::list<char *> _patchHistory;
    std::vector<std::pair<double, double> > newObjFunctionRange;
    std::vector<std::string> objFunctionNames;

    par.success = 1;

    const elEntMap &e2ePatch =
      par.useGeomForPatches ? element2entity : elEntMap();
    const elEntMap &e2eOpt = par.useGeomForOpt ? element2entity : elEntMap();

    const int initNumBadElts = badElts.size();
    if(par.nCurses) displayResultTable(nbPatchSuccess, initNumBadElts);
    if(par.verbose > 0)
      Msg::Info("%d bad elements, starting to iterate...", initNumBadElts);

    elElSetMap
      element2elements; // Element to element connectivity, built progressively

    // Loop over bad elements
    for(int iBadEl = 0; iBadEl < initNumBadElts; iBadEl++) {
      int success;
      if(badElts.empty()) break;

      // Create patch around worst element and remove it from badElts
      MElement *worstEl = getWorstElement(badElts, e2ePatch, par);
      badElts.erase(worstEl);

      // Initialize patch size to be adapted
      int maxLayers = par.patchDef->maxLayers;
      double distanceFactor = 1.;

      // Patch adaptation loop
      for(int iAdapt = 0; iAdapt < par.patchDef->maxPatchAdapt; iAdapt++) {
        // Set up patch
        const double limDist = par.patchDef->maxDistance(worstEl);
        elSet toOptimizePrim =
          getSurroundingPatch(worstEl, par.patchDef, limDist, maxLayers,
                              vertex2elements, element2elements, e2ePatch);
        vertSet toFix = getAllBndVertices(toOptimizePrim, vertex2elements);
        elSet toOptimize;
        std::set_difference(toOptimizePrim.begin(), toOptimizePrim.end(),
                            badElts.begin(), badElts.end(),
                            std::inserter(toOptimize, toOptimize.end()));

        // Get boundary elements adjacent to patch if required
        elSet bndElts;
        if(!el2BndEl.empty()) {
          getAdjacentBndElts(el2BndEl, bndEl2Ent, toOptimize, bndElts, par);
        }

        // Initialize optimization and output if asked
        if(par.nCurses) {
          mvbold(true);
          mvprintCenter(10, " PATCH %5i - ADAPTATION STEP %i ", iBadEl, iAdapt);
          mvbold(false);
        }
        if(par.verbose > 1)
          Msg::Info(
            "Optimizing patch %i (max. %i remaining) composed of %4d elements",
            iBadEl, badElts.size(), toOptimize.size());
        MeshOpt opt(e2eOpt, bndEl2Ent, toOptimize, toFix, bndElts, par);
        if(par.verbose > 3) {
          std::ostringstream ossI1;
          ossI1 << "initial_patch-" << iBadEl << ".msh";
          opt.patch.writeMSH(ossI1.str().c_str());
        }

        // Optimize patch
        if(opt.patch.nPC() == 0) {
          success = -1;
          Msg::Info("Patch %i (adapt #%i) has no degree of freedom, skipping",
                    iBadEl, iAdapt);
        }
        else
          success = opt.optimize(par);

        // Output if asked
        if(par.verbose > 3) {
          std::ostringstream ossI2;
          ossI2 << "final_patch-" << iBadEl << "_adapt-" << iAdapt << ".msh";
          opt.patch.writeMSH(ossI2.str().c_str());
        }

        if(par.nCurses)
          updateDisplayPatchHistory(
            _patchHistory, opt.objFunction()->minMaxStr(), iBadEl, iAdapt);

        // If (partial) success, update mesh and break adaptation loop,
        // otherwise adapt
        if((success > 0) || (iAdapt == par.patchDef->maxPatchAdapt - 1)) {
          opt.updateResults();
          if(newObjFunctionRange.size() == 0) {
            newObjFunctionRange = opt.objFunction()->minMax();
            objFunctionNames = opt.objFunction()->names();
          }
          else {
            for(int i = 0; i < newObjFunctionRange.size(); i++) {
              newObjFunctionRange[i].first =
                std::min(newObjFunctionRange[i].first,
                         opt.objFunction()->minMax()[i].first);
              newObjFunctionRange[i].second =
                std::max(newObjFunctionRange[i].second,
                         opt.objFunction()->minMax()[i].second);
            }
          }
          if(success >= 0) {
            opt.patch.updateGEntityPositions();
            break;
          }
          else {
            distanceFactor *= par.patchDef->distanceAdaptFact;
            maxLayers *= par.patchDef->maxLayersAdaptFact;
            if(par.verbose > 1)
              Msg::Info(
                "Patch %i failed (adapt #%i), adapting with increased size",
                iBadEl, iAdapt);
          }
        }

      } // End of adaptation loop

      nbPatchSuccess[success + 1]++;
      if(par.nCurses) {
        displayMinMaxVal(nbPatchSuccess, objFunctionNames, newObjFunctionRange);
        displayResultTable(nbPatchSuccess, initNumBadElts);
      }
      if(par.verbose > 1) switch(success) {
        case 1: Msg::Info("Patch %i succeeded", iBadEl); break;
        case 0:
          Msg::Info("Patch %i partially failed (measure "
                    "above critical value but below target)",
                    iBadEl);
          break;
        case -1: Msg::Info("Patch %i failed", iBadEl); break;
        }

      par.success = std::min(par.success, success);
    }

    while(_patchHistory.size() > 0) {
      delete[] _patchHistory.back();
      _patchHistory.pop_back();
    }
  }

} // namespace

void MeshOptimizer(std::vector<GEntity *> &entities, MeshOptParameters &par)
{
  if(par.nCurses) mvinit();
  redirectMessage _logWriter(par.logFileName, !par.nCurses);
  if(par.logFileName.compare("") != 0 || par.nCurses)
    Msg::SetCallback(&_logWriter);

  double startTime = Cpu();
  if(par.nCurses) {
    mvbold(true);
    mvprintCenter(0, "OPTIMIZING MESH");
    mvfillRow(1, '-');
    mvfillRow(10, '-');
    mvfillRow(20, '-');
    mvfillRow(27, '-');
    mvbold(false);
  }
  if(par.verbose > 0) Msg::StatusBar(true, "Optimizing mesh...");

  vertElVecMap vertex2elements;
  elEntMap element2entity, bndEl2Ent;
  elElMap el2BndEl;
  elSet badElts;
  for(int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity *&entity = entities[iEnt];
    if(entity->dim() != par.dim ||
       (par.onlyVisible && !entity->getVisibility()))
      continue;
    if(par.nCurses) {
      mvprintCenter(15,
                    "Computing connectivity and bad elements for entity %3d...",
                    entity->tag());
    }
    Msg::Info("Computing connectivity and bad elements for entity %d...",
              entity->tag());
    calcVertex2Elements(par.dim, entity, vertex2elements);
    if((par.useGeomForPatches) || (par.useGeomForOpt))
      calcElement2Entity(entity, element2entity);
    if(par.useBoundaries) calcBndInfo(entity, el2BndEl, bndEl2Ent);
    for(int iEl = 0; iEl < entity->getNumMeshElements();
        iEl++) { // Detect bad elements
      MElement *el = entity->getMeshElement(iEl);
      if(el->getDim() == par.dim) {
        if(par.patchDef->elBadness(el, entity) < 0.)
          badElts.insert(el);
        else if(par.useBoundaries) {
          auto bndElIt = el2BndEl.find(el);
          if(bndElIt != el2BndEl.end()) {
            MElement *&bndEl = bndElIt->second;
            if(par.patchDef->bndElBadness(bndEl, bndEl2Ent[bndEl]) < 0.)
              badElts.insert(el);
          }
        }
      }
    }
  }

  if(par.patchDef->strategy == MeshOptPatchDef::STRAT_DISJOINT)
    optimizeDisjointPatches(vertex2elements, element2entity, el2BndEl,
                            bndEl2Ent, badElts, par);
  else if(par.patchDef->strategy == MeshOptPatchDef::STRAT_ONEBYONE)
    optimizeOneByOne(vertex2elements, element2entity, el2BndEl, bndEl2Ent,
                     badElts, par);
  else {
    if(par.nCurses) {
      mvcolor(2, true);
      mvbold(true);
      mvprintCenter(-2, " ERROR: Unknown strategy %d for mesh optimization ",
                    par.patchDef->strategy);
      mvcolor(2, false);
      mvbold(false);
    }
    else
      Msg::Error("Unknown strategy %d for mesh optimization",
                 par.patchDef->strategy);
  }

  if(par.verbose > 0) {
    if(par.success == 1) {
      if(par.nCurses) {
        mvcolor(4, true);
        mvbold(true);
        mvprintCenter(-2, " Optimization succeeded ");
        mvcolor(4, false);
        mvbold(false);
      }
      else
        Msg::Info("Optimization succeeded");
    }
    else if(par.success == 0) {
      if(par.nCurses) {
        mvcolor(5, true);
        mvbold(true);
        mvprintCenter(-2, " Optimization partially failed (all measures above "
                          "critical value, but some below target) ");
        mvcolor(5, false);
        mvbold(false);
      }
      else
        Msg::Warning(
          "Optimization partially failed (all measures above critical "
          "value, but some below target)");
    }
    else if(par.success == -1) {
      if(par.nCurses) {
        mvcolor(3, true);
        mvbold(true);
        mvprintCenter(-2, "Optimization Failed");
        mvcolor(3, false);
        mvbold(false);
      }
      else
        Msg::Error("Optimization failed (some measures below critical value)");
    }
    par.CPU = Cpu() - startTime;
    Msg::StatusBar(true, "Done optimizing mesh (%g s)", par.CPU);
  }
  if(par.nCurses) {
    mvpause();
    mvterminate();
  }
  if(par.logFileName.compare("") != 0 || par.nCurses) Msg::SetCallback(nullptr);
}
