// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
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
class GVolume;
class GPoint;
class GSurface;
class GCurve;
class MTriangle;
class MQuadrangle;
class MNode;
class MElement;
class SurfaceProjector;

std::vector<GSurface*> model_faces(const GModel* gm);
std::vector<GCurve*> face_edges(const GSurface* gf);
std::vector<GCurve*> model_edges(const GModel* gm);

bool haveNiceParametrization(GSurface* gf);

bool buildVertexToVertexMap(
    const std::vector<MTriangle*>& triangles,
    std::unordered_map<MNode*,std::vector<MNode*> >& v2v);

bool buildVertexToVertexMap(
    const std::vector<MElement*>& elements,
    std::unordered_map<MNode*,std::vector<MNode*> >& v2v);


struct GFaceMeshPatch {
  /* Warning: simple container for pointers, memory not managed by this struct.
   * The GFaceMeshDiff wrapper is doing some memory management for the content. */
  GSurface* gf = nullptr;
  /* bdrVertices are the ordered boundary loops, there is only one
   * if patch is a topological disk */
  std::vector<std::vector<MNode*> > bdrVertices;
  std::vector<MNode*> intVertices; /* interior free vertices */
  std::vector<MNode*> embVertices; /* fixed vertices inside patch */
  std::vector<MElement*> elements;
};


bool buildBoundary (const std::vector<MElement*>& elements, std::vector<MNode*>& bnd);
bool buildBoundaries(const std::vector<MElement*>& elements, std::vector<std::vector<MNode*> >& loops);
bool patchFromElements(GSurface* gf, const std::vector<MElement*>& elements, GFaceMeshPatch& patch, bool forceEvenIfBadBoundary = false);
bool patchFromQuads(GSurface* gf, const std::vector<MQuadrangle*>& quads, GFaceMeshPatch& patch, bool forceEvenIfBadBoundary = false);


void sicnQuality(const GFaceMeshPatch& patch, double& sicnMin, double& sicnAvg);

bool patchIsTopologicallyValid(const GFaceMeshPatch& patch);

bool getConnectedComponents(const std::vector<MElement*>& elements,
    std::vector<std::vector<MElement*> >& components);

bool setVertexGFaceUV(GSurface* gf, MNode* v, double uv[2]);

MNode* centerOfElements(const std::vector<MElement*>& elements);

bool orientElementsAccordingToBoundarySegment(MNode* a, MNode* b, std::vector<MElement*>& elements);

bool reparamMeshVertexOnFaceWithRef(GSurface* gf, MNode* v, const SPoint2& ref, SPoint2& param);

std::vector<SPoint2> paramOnElement(GSurface* gf, MElement* e);

/* warning: triangles are allocated, should be delete by the caller */
std::vector<MTriangle*> trianglesFromQuads(const std::vector<MQuadrangle*>& quads);

/* Find a way to get triangles associated to GSurface (will look into current mesh, can split quads,
 * will check in background mesh)
 * If new triangles are allocated (e.g. by splitting quads), they are added to requireDelete
 * If copyExisting: existing triangles are copied into new ones (added to requireDelete) */
bool getGFaceTriangles(GSurface* gf, std::vector<MTriangle*>& triangles, std::vector<MTriangle*>& requireDelete,
    bool copyExisting = false);

bool fillSurfaceProjector(GSurface* gf, SurfaceProjector* sp);

int surfaceEulerCharacteristicDiscrete(const std::vector<MTriangle*>& triangles);

struct GFaceInfo {
  GSurface* gf = NULL;
  int chi = 0;
  std::set<GPoint*> cornerIsNonManifold;
  std::array<std::set<GPoint*>,5> bdrValVertices;
  int intSumVal3mVal5 = 0;
};

bool fillGFaceInfo(GSurface* gf, GFaceInfo& info, const std::vector<MTriangle*>& triangles);
bool fillGFaceInfo(GSurface* gf, GFaceInfo& info);

bool isTopologicalDisk(const GFaceInfo& info);
bool haveConcaveCorners(const GFaceInfo& info);

bool faceOrderedSideLoops(GSurface* gf, const GFaceInfo& info,
    std::vector<std::vector<std::vector<std::pair<GCurve*,bool> > > >& loopSideEdgesAndInv);

bool appendCADStatistics(GModel* gm, std::unordered_map<std::string,double>& stats, const std::string& prefix = "CAD_");
bool appendQuadMeshStatistics(GModel* gm, std::unordered_map<std::string,double>& stats, const std::string& prefix = "Mesh_");
void printStatistics(const std::unordered_map<std::string,double>& stats, const std::string& title = "Statistics:");
void writeStatistics(const std::unordered_map<std::string,double>& stats, const std::string& path); /* json format */

void computeSICNquality(const std::vector<MElement*>& elements, double& sicnMin, double& sicnAvg);
void computeSICNquality(GSurface* gf, double& sicnMin, double& sicnAvg);
void computeSICNquality(GVolume* gr, double& sicnMin, double& sicnAvg);

void errorAndAbortIfNegativeElement(GSurface* gf, const std::vector<MElement*>& elts, const std::string& msg = "");
void errorAndAbortIfInvalidVertexInElements(const std::vector<MElement*>& elts, const std::string& msg = "");
void errorAndAbortIfInvalidVertexInModel(GModel* gm, const std::string& msg = "");
void errorAndAbortIfInvalidSurfaceMesh(GSurface* gf, const std::string& msg = "");

std::string randomIdentifier();

struct GFaceMeshDiff {
  GSurface* gf = nullptr;
  GFaceMeshPatch before;
  GFaceMeshPatch after;
  bool done = false;

  /**
   * @brief Update the GSurface with the new vertices/elements
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
  std::vector<MNode*> vertices;
  std::vector<SPoint2> UVs;
  std::vector<SPoint3> positions;
  std::unordered_map<MNode*,std::pair<SPoint2,SPoint3> > old;

  PatchGeometryBackup(GFaceMeshPatch& p, bool includeBoundary = false);
  bool restore();
};
