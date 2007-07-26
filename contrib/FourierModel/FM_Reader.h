#ifndef _FM_READER_H_
#define _FM_READER_H_

#include <vector>
#include <string>
#include <complex>
#include "Curve.h"
#include "ExactPatch.h"
#include "ContinuationPatch.h"
#include "CylindricalProjectionSurface.h"
#include "RevolvedParabolaProjectionSurface.h"
#include "FM_Info.h"
#include "FM_Face.h"
#include "BlendOperator.h"
#include "BlendedPatch.h"

class FM_Reader {
 private:
  int _nVertices;
  int _nEdges;
  int _nFaces;
  int _nPatches;
  int _nPS;
  int _nIntersections;
  std::vector<PatchInfo*> _patchList;
  std::vector<IntersectionInfo*> _intersectionList;
  std::vector<std::vector<OverlapInfo*> > _overlapChart;
  std::vector<FM_Vertex*> _vertex;
  std::vector<FM_Edge*> _edge;
  std::vector<FM_Face*> _face;
  std::vector<Patch*> _patch;
  std::vector<Curve*> _intersection;
  std::vector<ProjectionSurface*> _ps;

  BlendOperator* _blendOperator;
  std::vector<BlendedPatch*> _blendedPatch;

 public:
  FM_Reader(const char* fn);

  virtual ~FM_Reader() {}

  inline int GetNumVertices
    () { return _nVertices; }

  inline int GetNumEdges
    () { return _nEdges; }

  inline int GetNumFaces
    () { return _nFaces; }

  inline int GetNumPatches
    () { return _nPatches; }

  inline int GetNumIntersections
    () { return _nIntersections; }

  inline std::vector<PatchInfo*> GetPatchList
    () { return _patchList; }

  inline std::vector<IntersectionInfo*> GetIntersectionList
    () { return _intersectionList; }

  inline FM_Vertex* GetVertex
    (int i) { return _vertex[i]; }

  inline FM_Edge* GetEdge
    (int i) { return _edge[i]; }

  inline FM_Face* GetFace
    (int i) { return _face[i]; }

  inline bool GetOverlapInfo
    (int i, int j) 
    { if (_overlapChart[i][j]->doesIntersect) return true; else return false; }

  inline BlendOperator* GetBlendOperator
    () { return _blendOperator; }

  Patch* GetPatch
    (int tag);

  BlendedPatch* GetBlendedPatch
    (int tag);

  Curve* GetIntersection
    (int tag);

  ProjectionSurface* GetProjectionSurface
    (int tag);
};

#endif
