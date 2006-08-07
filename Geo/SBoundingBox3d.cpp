#include "SBoundingBox3d.h"
#include <float.h>

SBoundingBox3d::SBoundingBox3d()
: MinPt(DBL_MAX,DBL_MAX,DBL_MAX), MaxPt(-DBL_MAX,-DBL_MAX,-DBL_MAX)
{}

SBoundingBox3d::SBoundingBox3d(const SPoint3 & pt)
: MinPt(pt), MaxPt(pt)
{}

bool SBoundingBox3d::empty()
{
  if(MinPt.x() == DBL_MAX || MinPt.y() == DBL_MAX || MinPt.z() == DBL_MAX ||
     MaxPt.x() == -DBL_MAX || MaxPt.y() == -DBL_MAX || MaxPt.z() == -DBL_MAX) 
    return true;
  return false;
}

void SBoundingBox3d::operator+=(const SPoint3 &pt)
// note: it is possible for pt[i] to be both > MaxPt[i] and < MinPt[i]
// the first point always will be both
{
  if(pt[0] < MinPt[0])
    MinPt[0] = pt[0];
  if (pt[0] > MaxPt[0])
    MaxPt[0] = pt[0];

  if(pt[1] < MinPt[1])
    MinPt[1] = pt[1];
  if (pt[1] > MaxPt[1])
    MaxPt[1] = pt[1];

  if(pt[2] < MinPt[2])
    MinPt[2] = pt[2];
  if (pt[2] > MaxPt[2])
    MaxPt[2] = pt[2];
}

void SBoundingBox3d::operator+=(const SBoundingBox3d &box)
{
  (*this)+=box.MinPt;
  (*this)+=box.MaxPt;
}

SPoint3 SBoundingBox3d::min() const
{ return MinPt; }

SPoint3 SBoundingBox3d::max() const
{ return MaxPt; }

SPoint3 SBoundingBox3d::center() const
{ return (MinPt+MaxPt)*.5; }

void SBoundingBox3d::operator*=(double scale)
{
  SPoint3 center = (MinPt + MaxPt)*.5;
  MaxPt -= center;
  MinPt -= center;
  MaxPt *= scale;
  MinPt *= scale;
  MaxPt += center;
  MinPt += center;
}

void SBoundingBox3d::scale(double sx, double sy, double sz)
{
  SPoint3 center = (MinPt + MaxPt)*.5;
  MaxPt -= center;
  MinPt -= center;
  MaxPt[0] *= sx;   MaxPt[1] *= sy; MaxPt[2] *= sz;
  MinPt[0] *= sx;   MinPt[1] *= sy; MinPt[2] *= sz;
  MaxPt += center;
  MinPt += center;
}

void SBoundingBox3d::makeCube()
{
  SPoint3 len = MaxPt-MinPt;
  double scales[3];
  double max=-1.0;

  for(int i = 0; i < 3; i++)
    max = len[i] > max ? len[i] : max;

  for(int j = 0; j < 3; j++)
    scales[j] = max/len[j];

  scale(scales[0],scales[1],scales[2]);
}
