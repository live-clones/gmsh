#ifndef _BLEND_OPERATOR_H_
#define _BLEND_OPERATOR_H_

#include <vector>
#include "FM_Info.h"
#include "Patch.h"
#include "ProjectionSurface.h"

namespace FM {

class BlendOperator {
 private:
  std::vector<Patch*> patch_;
  std::vector<ProjectionSurface*> ps_;
  std::vector<std::vector<OverlapInfo*> > overlapChart_;
  
  bool GetPointOnPatch_
    (int i, double u, double v, int j, double &x, double &y, double &z);
  
 protected:

 public:
  BlendOperator
    (std::vector<Patch*> patch,std::vector<ProjectionSurface*> ps,
     std::vector<std::vector<OverlapInfo*> > overlapChart) :
      patch_(patch), ps_(ps), overlapChart_(overlapChart) {}

  ~BlendOperator() {}

  int GetNumPatches
    ();

  Patch* GetPatch
    (int tag);

  ProjectionSurface* GetProjectionSurface
    (int tag);

  bool DoPatchesOverlap
    (int patchTag1, int patchTag2);

  int GetProjectionSurfaceTagForOverlap
    (int patchTag1, int patchTag2);

  bool IsPointInIntersectionBoundingBox
    (int patchTag1, int patchTag2, double x, double y, double z);

  bool E
    (int i, int j, double u, double v, double &x, double &y, double &z);

  double GetBlendingPou
    (int patchTag, double u, double v);

  bool GetPointOnPatch
    (int patchTag, double d[3], double &x, double &y, double &z);
};

}

#endif
