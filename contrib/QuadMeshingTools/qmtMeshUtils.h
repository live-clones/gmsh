// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <set>
#include <vector>
#include <string>
#include <unordered_map>
#include "SPoint2.h"
#include "SPoint3.h"


class GModel;
class GVertex;
class GFace;
class GEdge;
class MTriangle;
class MQuadrangle;
class MVertex;
class MElement;
class SurfaceProjector;

std::vector<GFace*> model_faces(const GModel* gm);
std::vector<GEdge*> face_edges(const GFace* gf);
std::vector<GEdge*> model_edges(const GModel* gm);

bool haveNiceParametrization(GFace* gf);

bool buildVertexToVertexMap(
    const std::vector<MTriangle*>& triangles,
    std::unordered_map<MVertex*,std::vector<MVertex*> >& v2v);


struct GFaceMeshPatch {
  /* Warning: simple container for pointers, memory not managed by this struct.
   * The GFaceMeshDiff wrapper is doing some memory management for the content. */
  GFace* gf = nullptr;
  /* bdrVertices are the ordered boundary loops, there is only one
   * if patch is a topological disk */
  std::vector<std::vector<MVertex*> > bdrVertices; 
  std::vector<MVertex*> intVertices;
  std::vector<MElement*> elements;
};


bool buildBoundary (const std::vector<MElement*>& elements, std::vector<MVertex*>& bnd);
bool buildBoundaries(const std::vector<MElement*>& elements, std::vector<std::vector<MVertex*> >& loops);
bool patchFromElements(GFace* gf, const std::vector<MElement*>& elements, GFaceMeshPatch& patch, bool forceEvenIfBadBoundary = false);
bool patchFromQuads(GFace* gf, const std::vector<MQuadrangle*>& quads, GFaceMeshPatch& patch, bool forceEvenIfBadBoundary = false);


void sicnQuality(const GFaceMeshPatch& patch, double& sicnMin, double& sicnAvg);

bool patchIsTopologicallyValid(const GFaceMeshPatch& patch);

bool getConnectedComponents(const std::vector<MElement*>& elements, 
    std::vector<std::vector<MElement*> >& components);

bool setVertexGFaceUV(GFace* gf, MVertex* v, double uv[2]);

MVertex* centerOfElements(const std::vector<MElement*>& elements);

bool orientElementsAccordingToBoundarySegment(MVertex* a, MVertex* b, std::vector<MElement*>& elements);

bool reparamMeshVertexOnFaceWithRef(GFace* gf, MVertex* v, const SPoint2& ref, SPoint2& param);

std::vector<SPoint2> paramOnElement(GFace* gf, MElement* e);

/* warning: triangles are allocated, should be delete by the caller */
std::vector<MTriangle*> trianglesFromQuads(const std::vector<MQuadrangle*>& quads);

bool getGFaceTriangles(GFace* gf, std::vector<MTriangle*>& triangles, bool& requireDelete);


bool fillSurfaceProjector(GFace* gf, SurfaceProjector* sp);

int surfaceEulerCharacteristicDiscrete(const std::vector<MTriangle*>& triangles);

struct GFaceInfo {
  GFace* gf = NULL;
  int chi = 0;
  std::set<GVertex*> cornerIsNonManifold;
  std::array<std::set<GVertex*>,5> bdrValVertices;
  int intSumVal3mVal5 = 0;
};

bool fillGFaceInfo(GFace* gf, GFaceInfo& info, const std::vector<MTriangle*>& triangles);
bool fillGFaceInfo(GFace* gf, GFaceInfo& info);

bool isTopologicalDisk(const GFaceInfo& info);
bool haveConcaveCorners(const GFaceInfo& info);

bool faceOrderedSideLoops(GFace* gf, const GFaceInfo& info, 
    std::vector<std::vector<std::vector<std::pair<GEdge*,bool> > > >& loopSideEdgesAndInv);

bool appendCADStatistics(GModel* gm, std::unordered_map<std::string,double>& stats, const std::string& prefix = "CAD_");
bool appendQuadMeshStatistics(GModel* gm, std::unordered_map<std::string,double>& stats, const std::string& prefix = "Mesh_");
void printStatistics(const std::unordered_map<std::string,double>& stats, const std::string& title = "Statistics:");
void writeStatistics(const std::unordered_map<std::string,double>& stats, const std::string& path); /* json format */

void errorAndAbortIfNegativeElement(GFace* gf, const std::vector<MElement*>& elts, const std::string& msg = "");
void errorAndAbortIfInvalidVertexInElements(const std::vector<MElement*>& elts, const std::string& msg = "");
void errorAndAbortIfInvalidVertexInModel(GModel* gm, const std::string& msg = "");

std::string randomIdentifier();

struct GFaceMeshDiff {
  GFace* gf = nullptr;
  GFaceMeshPatch before;
  GFaceMeshPatch after;
  bool done = false;
  
  /**
   * @brief Update the GFace with the new vertices/elements
   *        and remove/delete the old ones.
   *
   * @param[in] verifyPatchTopology Check if the patch after is manifold
   *
   * @return true if success
   */
  bool execute(bool verifyPatchTopology = false);

  /**
   * @brief Destructor, delete/remove the new or old components
   *        depending on the value of the variable done.
   */
  ~GFaceMeshDiff(); 
};


/**
 * @brief Store the geometry (uv + 3D) of a GFaceMeshPatch.
 *        Useful to restore the initial geometry after trying
 *        various smoothing operations that were not successful.
 */
struct PatchGeometryBackup {
  std::vector<MVertex*> vertices;
  std::vector<SPoint2> UVs;
  std::vector<SPoint3> positions;
  std::unordered_map<MVertex*,std::pair<SPoint2,SPoint3> > old;

  PatchGeometryBackup(GFaceMeshPatch& p, bool includeBoundary = false);
  bool restore();
};

