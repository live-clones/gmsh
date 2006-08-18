#ifndef _GEDGE_H_
#define _GEDGE_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "GEntity.h"
#include "GVertex.h"
#include "SVector3.h"
#include "SPoint3.h"
#include "SPoint2.h"
#include "MElement.h"

// A model edge.

class GEdge : public GEntity {
 protected:
  GVertex *v0, *v1;
  std::list<GFace *> l_faces;

 public:
  GEdge(GModel *model, 
	int tag, 
	GVertex *_v0, 
	GVertex *_v1);
  virtual ~GEdge() ;

  GVertex *getBeginVertex () const { return v0; }
  GVertex *getEndVertex () const { return v1; }

  void addFace(GFace *f);
  void delFace(GFace *f);

  virtual int dim() const {return 1;}
  virtual bool periodic(int dim=0) const = 0;
  virtual bool continuous(int dim=0) const = 0;
  virtual void setVisibility(char val, bool recursive=false);

  // The bounding box
  SBoundingBox3d bounds() const;

  // Get the parameter location for a point in space on the edge.
  virtual double parFromPoint(const SPoint3 &) const = 0;

  // Get the point for the given parameter location.
  virtual GPoint point(double p) const = 0;

  // Get the closest point on the edge to the given point.
  virtual GPoint closestPoint(const SPoint3 & queryPoint) =0;

  // True if the edge contains the given parameter.
  virtual int containsParam(double pt) const = 0;

  // Get first derivative of edge at the given parameter.
  virtual SVector3 firstDer(double par) const = 0;

  // Reparmaterize the point onto the given face.
  virtual SPoint2 reparamOnFace(GFace *face, double epar,int dir) const = 0;

  // Recompute the mesh partitions defined on this edge.
  void recomputeMeshPartitions();

  // Delete the mesh partitions defined on this edge.
  void deleteMeshPartitions();

  // Returns the minimum number of segments used for meshing the edge
  virtual int minimumMeshSegments () const {return 1;}

  // Returns the minimum number of segments used for drawing the edge
  virtual int minimumDrawSegments () const {return 1;}

  // Returns a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  struct {
    char   Method;
    double coeffTransfinite;
    int    nbPointsTransfinite;
    int    typeTransfinite;
  } meshAttributes ;

  std::vector<MLine*> lines;
};

#endif
