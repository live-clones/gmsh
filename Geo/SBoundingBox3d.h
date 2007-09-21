#ifndef _SBOUNDING_BOX_3D_H_
#define _SBOUNDING_BOX_3D_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <float.h>
#include "SPoint3.h"

#if defined(WIN32)
#undef min
#undef max
#endif

// A bounding box class - add points and it grows to be the bounding
// box of the point set
class SBoundingBox3d {
 public:
  SBoundingBox3d() 
    : MinPt(DBL_MAX,DBL_MAX,DBL_MAX), MaxPt(-DBL_MAX,-DBL_MAX,-DBL_MAX) {}
  SBoundingBox3d(const SPoint3 &pt)
    : MinPt(pt), MaxPt(pt) {}
  bool empty()
  {
    if(MinPt.x() == DBL_MAX || MinPt.y() == DBL_MAX || MinPt.z() == DBL_MAX ||
       MaxPt.x() == -DBL_MAX || MaxPt.y() == -DBL_MAX || MaxPt.z() == -DBL_MAX) 
      return true;
    return false;
  }
  void reset()
  {
    MinPt = SPoint3(DBL_MAX,DBL_MAX,DBL_MAX);
    MaxPt = SPoint3(-DBL_MAX,-DBL_MAX,-DBL_MAX);
  }
  void operator+=(const SPoint3 &pt)
  {
    // note: it is possible for pt[i] to be both > MaxPt[i] and < MinPt[i]
    // the first point always will be both
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
  void operator+=(const SBoundingBox3d &box)
  {
    (*this) += box.MinPt;
    (*this) += box.MaxPt;
  }
  void operator*=(double scale)
  {
    SPoint3 center = (MinPt + MaxPt) * .5;
    MaxPt -= center;
    MinPt -= center;
    MaxPt *= scale;
    MinPt *= scale;
    MaxPt += center;
    MinPt += center;
  }
  void scale(double sx, double sy, double sz)
  {
    SPoint3 center = (MinPt + MaxPt) * .5;
    MaxPt -= center;
    MinPt -= center;
    MaxPt[0] *= sx; MaxPt[1] *= sy; MaxPt[2] *= sz;
    MinPt[0] *= sx; MinPt[1] *= sy; MinPt[2] *= sz;
    MaxPt += center;
    MinPt += center;
  }
  SPoint3 min() const { return MinPt; }
  SPoint3 max() const { return MaxPt; }
  SPoint3 center() const { return (MinPt + MaxPt) * .5; }
  void makeCube()
  {
    SPoint3 len = MaxPt - MinPt;
    double scales[3];
    double max = -1.0;
    for(int i = 0; i < 3; i++)
      max = len[i] > max ? len[i] : max;
    for(int j = 0; j < 3; j++)
      scales[j] = max/len[j];
    scale(scales[0],scales[1],scales[2]);
  }
 private:
  SPoint3 MinPt, MaxPt;
};

#endif
