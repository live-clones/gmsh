#include "FM_Info.h"

PatchInfo::PatchInfo() : tag(-1) 
{
  uMin = vMin = 0.;
  uMax = vMax = 1.;
  derivative = 3;
  recompute = 1;
}

OverlapInfo::OverlapInfo()
{
  doesIntersect = 0;
  xMin = xMax = 0.;
  yMin = yMax = 0.;
  zMin = zMax = 0.;
}

IntersectionInfo::IntersectionInfo() : tag(-1) 
{
  edgeInfo.edgeType = -1;
  edgeInfo.constValue = 0.;
  edgeInfo.startValue = 0.;
  edgeInfo.endValue = 0.;
  edgeInfo.acrossDiscontinuity = false;
}
