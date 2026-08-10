// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The AdaptMesh command: improve a 3D mesh by collapsing nodes, swapping
// faces and edges and relocating nodes, on the MTet4 objects.

#include <list>
#include <set>
#include <vector>
#include "meshGRegion.h"
#include "meshGRegionTet4.h"
#include "meshGRegionLocalMeshMod.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MVertex.h"
#include "Context.h"
#include "OS.h"

void adaptMeshGRegion::operator()(GRegion *gr)
{
  const qmTetrahedron::Measures qm = qmTetrahedron::QMTET_GAMMA;

  typedef std::list<MTet4 *> CONTAINER;
  CONTAINER allTets;
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    allTets.push_back(new MTet4(gr->tetrahedra[i], qm));
  }
  gr->tetrahedra.clear();

  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  createAllEmbeddedFaces(gr, allEmbeddedFaces);
  std::set<MEdge, MEdgeLessThan> allEmbeddedEdges;
  createAllEmbeddedEdges(gr, allEmbeddedEdges);

  connectTets(allTets.begin(), allTets.end(), &allEmbeddedFaces);

  double t1 = Cpu(), w1 = TimeOfDay();
  std::vector<MTet4 *> illegals;
  const int nbRanges = 10;
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
    Msg::Info("Adaptation starts (volume = %g) with worst = %g / average = %g:",
              totalVolumeb, worst, avg / count);
    for(int i = 0; i < nbRanges; i++) {
      double low = (double)i / nbRanges;
      double high = (double)(i + 1) / nbRanges;
      Msg::Info("%3.2f < quality < %3.2f: %9d elements ", low, high,
                quality_ranges[i]);
    }
  }

  double qMin = 0.5;
  double sliverLimit = 0.2;

  int nbESwap = 0, nbFSwap = 0, nbReloc = 0, nbCollapse = 0;

  while(1) {
    std::vector<MTet4 *> newTets;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        for(int i = 0; i < 4; i++) {
          for(int j = 0; j < 4; j++) {
            if(collapseVertex(newTets, *it, i, j, qmTetrahedron::QMTET_GAMMA)) {
              nbCollapse++;
              i = j = 10;
            }
          }
        }
      }
    }

    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin) {
          for(int i = 0; i < 4; i++) {
            if(faceSwap(newTets, *it, i, qm, allEmbeddedFaces)) {
              nbFSwap++;
              break;
            }
          }
        }
      }
    }

    illegals.clear();
    for(int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;

    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin)
          for(int i = 0; i < 6; i++) {
            MEdge ed = (*it)->tet()->getEdge(i);
            if(allEmbeddedEdges.find(ed) == allEmbeddedEdges.end()) {
              if(edgeSwap(newTets, *it, i, qm, allEmbeddedFaces)) {
                nbESwap++;
                break;
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

    if(!newTets.size()) break;

    // add all the new tets in the container
    for(std::size_t i = 0; i < newTets.size(); i++) {
      if(!newTets[i]->isDeleted()) { allTets.push_back(newTets[i]); }
      else {
        delete newTets[i]->tet();
        delete newTets[i];
      }
    }

    // relocate vertices
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin)
          for(int i = 0; i < 4; i++) {
            if(smoothVertex(*it, i, qm)) nbReloc++;
          }
      }
    }

    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
      }
    }
    double t2 = Cpu(), w2 = TimeOfDay();
    Msg::Info("%d edge swaps, %d face swaps, %d node collapse, %d node "
              "relocations (volume = %g): worst = %g / average = %g "
              "(Wall %gs, CPU %gs)",
              nbESwap, nbFSwap, nbCollapse, nbReloc, totalVolumeb, worst,
              avg / count, w2 - w1, t2 - t1);
    break;
  }

  int nbSlivers = 0;
  for(std::size_t i = 0; i < illegals.size(); i++)
    if(!(illegals[i]->isDeleted())) nbSlivers++;

  if(nbSlivers) {
    Msg::Info("%d illegal tets are still in the mesh, trying to remove them",
              nbSlivers);
  }
  else {
    Msg::Info("No illegal tets in the mesh :-)", nbSlivers);
  }

  for(int i = 0; i < nbRanges; i++) {
    double low = (double)i / nbRanges;
    double high = (double)(i + 1) / nbRanges;
    Msg::Info("%3.2f < quality < %3.2f: %9d elements", low, high,
              quality_ranges[i]);
  }

  for(auto it = allTets.begin(); it != allTets.end(); ++it) {
    if(!(*it)->isDeleted()) {
      gr->tetrahedra.push_back((*it)->tet());
      delete *it;
    }
    else {
      delete(*it)->tet();
      delete *it;
    }
  }
}

