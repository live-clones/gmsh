#ifndef _GREGION_H_
#define _GREGION_H_

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

#include "GEntity.h"

class MElement;
class MTetrahedron;
class MHexahedron;
class MPrism;
class MPyramid;
class ExtrudeParams;

// A model region.
class GRegion : public GEntity {
 protected:
  std::list<GFace*> l_faces;
  std::list<int> l_dirs;

 public:
  GRegion(GModel *model, int tag);
  virtual ~GRegion();

  // get the dimension of the region (3)
  virtual int dim() const { return 3; }

  // set the visibility flag
  virtual void setVisibility(char val, bool recursive=false);

  // get/set faces that bound the region
  virtual std::list<GFace*> faces() const{ return l_faces; }
  void set(std::list<GFace*> &f) { l_faces= f; }

  // edges that bound the region
  virtual std::list<GEdge*> edges() const;

  // get the bounding box
  virtual SBoundingBox3d bounds() const;

  // check if the region is connected to another region by an edge
  bool edgeConnected(GRegion *r) const;

  // recompute the mesh partitions defined on this region
  void recomputeMeshPartitions();

  // delete the mesh partitions defined on this region
  void deleteMeshPartitions();

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  // get number of elements in the mesh and get element by index
  unsigned int getNumMeshElements();
  MElement *getMeshElement(unsigned int index);

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  struct {
    char Method;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
    // corners of the transfinite interpolation
    std::vector<GVertex*> corners;
  } meshAttributes ;

  // a array for accessing the transfinite vertices using a triplet of
  // indices
  std::vector<std::vector<std::vector<MVertex*> > > transfinite_vertices;

  std::vector<MTetrahedron*> tetrahedra;
  std::vector<MHexahedron*> hexahedra;
  std::vector<MPrism*> prisms;
  std::vector<MPyramid*> pyramids;
};

#endif
