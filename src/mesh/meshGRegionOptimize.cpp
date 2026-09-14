// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Improving the tetrahedra of a region by local mesh modifications. Two
// kernels do the same work: the original one, on the MTet4 objects, which is
// below, and the flat one, on index-based arrays, which is the default
// (Mesh.FlatOptimize3D), lives in meshGRegionOptimizeFlat.cpp, and is the one
// meant to remain.

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <set>
#include <vector>

#include "meshGRegionDelaunay.h"
#include "meshGRegionTet4.h"
#include "meshGRegionLocalMeshMod.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "GEntity.h"
#include "GmshMessage.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MVertex.h"
#include "Context.h"
#include "OS.h"
#include "meshGRegionOptimizeFlat.h"

// the quality histogram both kernels report. At namespace scope so that the
// lambdas below use it without capturing it: whether a constant needs to be
// captured is read differently by different compilers.
constexpr int nbRanges = 10;

void optimizeMesh(GRegion *gr, const qmTetrahedron::Measures &qm)
{
  double qMin = CTX::instance()->mesh.optimizeThreshold;

  if(qMin <= 0.0) return;

  if(gr->tetrahedra.empty()) return;

  if(CTX::instance()->mesh.flatOptimize3D && optimizeMeshFlat(gr, qm)) return;

  typedef std::vector<MTet4 *> CONTAINER;
  // the initial MTet4s live in one contiguous block; the local mesh
  // modifications allocate the ones they create individually
  std::vector<MTet4> initialTets(gr->tetrahedra.size());
  auto inBlock = [&initialTets](MTet4 *t) {
    return t >= initialTets.data() &&
           t < initialTets.data() + initialTets.size();
  };
  CONTAINER allTets;
  allTets.reserve(gr->tetrahedra.size());
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    MTet4 *t = &initialTets[i];
    *t = MTet4(gr->tetrahedra[i], qm);
    t->setOnWhat(gr);
    allTets.push_back(t);
  }
  gr->tetrahedra.clear();

  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  createAllEmbeddedFaces(gr, allEmbeddedFaces);

  std::set<MEdge, MEdgeLessThan> allEmbeddedEdges;
  createAllEmbeddedEdges(gr, allEmbeddedEdges);

  if(allEmbeddedFaces.empty()) {
    connectTetsFast(allTets.begin(), allTets.end());
  }
  else {
    // the embedded faces have to be left unconnected, which the bucketed
    // version above does not know how to do
    connectTets(allTets.begin(), allTets.end(), &allEmbeddedFaces);
  }

  double t1 = Cpu(), w1 = TimeOfDay();
  std::vector<MTet4 *> illegals;
  int quality_ranges[nbRanges];
  {
    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for(int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
        for(int i = 0; i < nbRanges; i++) {
          double low = (double)i / nbRanges;
          double high = (double)(i + 1) / nbRanges;
          if(qual >= low && qual < high) quality_ranges[i]++;
        }
      }
    }
    Msg::Info(
      "Optimization starts (volume = %g) with worst = %g / average = %g:",
      totalVolumeb, worst, avg / count);
    for(int i = 0; i < nbRanges; i++) {
      double low = (double)i / nbRanges;
      double high = (double)(i + 1) / nbRanges;
      Msg::Info("%3.2f < quality < %3.2f : %9d elements", low, high,
                quality_ranges[i]);
    }
  }

  double sliverLimit = 0.001;
  int nbESwap = 0, nbReloc = 0;
  double worstA = 0.0;

  std::set<MTetrahedron*> to_delete;

  while(1) {
    std::vector<MTet4 *> newTets;

    illegals.clear();
    for(int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;

    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin) {
          for(int i = 0; i < 6; i++) {
            MEdge ed = (*it)->tet()->getEdge(i);
            if(allEmbeddedEdges.find(ed) == allEmbeddedEdges.end()) {
              if(edgeSwap(newTets, *it, i, qm, allEmbeddedFaces)) {
                nbESwap++;
                break;
              }
            }
          }
        }
        if(!(*it)->isDeleted()) {
          if(qq < sliverLimit) illegals.push_back(*it);
          for(int i = 0; i < nbRanges; i++) {
            double low = (double)i / nbRanges;
            double high = (double)(i + 1) / nbRanges;
            if(qq >= low && qq < high) quality_ranges[i]++;
          }
        }
      }
    }

    if(!newTets.size()) { break; }

    // add all the new tets in the container
    for(std::size_t i = 0; i < newTets.size(); i++) {
      if(!newTets[i]->isDeleted()) { allTets.push_back(newTets[i]); }
      else {
        to_delete.insert(newTets[i]->tet());
        delete newTets[i];
      }
    }

    // relocate vertices
    if(gr->hexahedra.empty() && gr->prisms.empty() && gr->pyramids.empty()) {
      for(auto it = allTets.begin(); it != allTets.end(); ++it) {
        if(!(*it)->isDeleted()) {
          double qq = (*it)->getQuality();
          if(qq < qMin) {
            for(int i = 0; i < 4; i++) {
              if(smoothVertex(*it, i, qm)) nbReloc++;
            }
          }
        }
      }
    }

    // only the qualities are needed here: they are cached in the MTet4s,
    // while the volumes would each chase the four vertices of a tet (the
    // total volume is reported once, at the end)
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
      }
    }

    double t2 = Cpu(), w2 = TimeOfDay();
    Msg::Info("%d edge swaps, %d node relocations: "
              "worst = %g / average = %g (Wall %gs, CPU %gs)",
              nbESwap, nbReloc, worst, avg / count, w2 - w1, t2 - t1);
    if(worstA != 0.0 && worst - worstA < 1.e-6) break;
    worstA = worst;
  }

  for(auto t : to_delete) delete t;

  {
    double totalVolumeb = 0.0, worst = 1.0, avg = 0.;
    int count = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        totalVolumeb += fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
      }
    }
    Msg::Info("Optimization done (volume = %g) with worst = %g / average = %g:",
              totalVolumeb, worst, count ? avg / count : 0.);
  }

  if(illegals.size()) {
    Msg::Warning("%d ill-shaped tets are still in the mesh", illegals.size());
  }
  else {
    Msg::Info("No ill-shaped tets in the mesh :-)");
  }

  for(int i = 0; i < nbRanges; i++) {
    double low = (double)i / nbRanges;
    double high = (double)(i + 1) / nbRanges;
    Msg::Info("%3.2f < quality < %3.2f : %9d elements", low, high,
              quality_ranges[i]);
  }

  for(auto it = allTets.begin(); it != allTets.end(); ++it) {
    if(!(*it)->isDeleted()) { gr->tetrahedra.push_back((*it)->tet()); }
    else {
      delete(*it)->tet();
    }
    if(!inBlock(*it)) delete *it;
  }
}

