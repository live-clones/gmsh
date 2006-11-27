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

#include "SPoint3.h"

// A bounding box class - add points and it grows to be the bounding
// box of the point set
class SBoundingBox3d {
 public:
  SBoundingBox3d();
  SBoundingBox3d(const SPoint3 &);
  bool empty();
  void operator+=(const SPoint3 &pt);
  void operator+=(const SBoundingBox3d &pt);
  void operator*=(double scale);
  void scale(double, double, double);
  SPoint3 min() const;
  SPoint3 max() const;
  SPoint3 center() const;
  void makeCube();
 private:
  SPoint3 MinPt,MaxPt;
};

#endif
