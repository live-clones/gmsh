#ifndef _GMSH_FACE_H_
#define _GMSH_FACE_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include "Geo.h"
#include "GFace.h"

class gmshFace : public GFace {
 protected:
  Surface *s;
  bool isSphere;
  SPoint3 center;
  double radius;
 public:
  gmshFace(GModel *m, Surface *face);
  virtual ~gmshFace(){}
  Range<double> parBounds(int i) const; 
  void setModelEdges(std::list<GEdge*>&);
  virtual SPoint2 geodesic(const SPoint2 &pt1, const SPoint2 &pt2, double t);
  virtual GPoint point(double par1, double par2) const; 
  virtual GPoint closestPoint(const SPoint3 & queryPoint, const double initialGuess[2]) const; 
  virtual bool containsPoint(const SPoint3 &pt) const;  
  virtual double getMetricEigenvalue(const SPoint2 &);  
  virtual SVector3 normal(const SPoint2 &param) const; 
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const; 
  virtual GEntity::GeomType geomType() const; 
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return s; }
  virtual SPoint2 parFromPoint(const SPoint3 &) const;
  virtual void resetMeshAttributes();
};

#endif
