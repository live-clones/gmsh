#ifndef _FM_READER_H_
#define _FM_READER_H_

#include <vector>
#include <string>
#include <complex>
#include "Curve.h"
#include "IntersectionCurve.h"
#include "ExactPatch.h"
#include "ContinuationPatch.h"
#include "PlaneProjectionSurface.h"
#include "CylindricalProjectionSurface.h"
#include "ParaboloidProjectionSurface.h"
#include "RevolvedParabolaProjectionSurface.h"
#include "FM_Info.h"
#include "FM_Face.h"
#include "BlendOperator.h"
#include "BlendedPatch.h"

class FM_Reader {
 private:
  int _nPatches;
  std::vector<PatchInfo*> _patchList;
  std::vector<Patch*> _patch;
  std::vector<ProjectionSurface*> _ps;

 public:
  FM_Reader(const char* fn);

  virtual ~FM_Reader() {}

  inline int GetNumPatches
    () { return _nPatches; }

  inline std::vector<PatchInfo*> GetPatchList
    () { return _patchList; }

  Patch* GetPatch
    (int tag);

  ProjectionSurface* GetProjectionSurface
    (int tag);
};

#endif
