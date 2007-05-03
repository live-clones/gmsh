#ifndef _FM_READER_H_
#define _FM_READER_H_

#include <vector>
#include <complex>
#include "Curve.h"
#include "ExactPatch.h"
#include "ContinuationPatch.h"
#include "FM_Info.h"
#include "FM_Face.h"

class FM_Reader {
 private:
  int _nFaces;
  int _nPatches;
  int _nIntersections;
  std::vector<PatchInfo*> _patchList;
  std::vector<IntersectionInfo*> _intersectionList;
  std::vector<FM_Face*> _face;
  std::vector<Patch*> _patch;
  std::vector<Curve*> _intersection;
 public:
  FM_Reader(const char* fn);
  virtual ~FM_Reader() {}

  inline int GetNumFaces() { return _nFaces; }
  inline int GetNumPatches() { return _nPatches; }
  inline int GetNumIntersections() { return _nIntersections; }
  inline std::vector<PatchInfo*> GetPatchList() { return _patchList; }
  inline std::vector<IntersectionInfo*> GetIntersectionList()
    { return _intersectionList; }
  inline FM_Face* GetFace(int i) { return _face[i]; }

  Patch* GetPatch(int tag);
  Curve* GetIntersection(int tag);
};

#endif
