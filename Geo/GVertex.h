// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GVERTEX_H_
#define _GVERTEX_H_

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include "GEntity.h"
#include "GPoint.h"
#include "SPoint2.h"

#define MAX_LC 1.e22

class MElement;
class MPoint;

// A model vertex.
class GVertex : public GEntity 
{
 protected:
  std::list<GEdge*> l_edges;
  double meshSize;
 public:
  GVertex(GModel *m, int tag, double ms=MAX_LC);
  virtual ~GVertex();

  // delete mesh data
  virtual void deleteMesh();

  // get/set the coordinates of the vertex
  virtual GPoint point() const = 0;
  virtual double x() const = 0;
  virtual double y() const = 0;
  virtual double z() const = 0;
  virtual void setPosition(GPoint &p);

  // add/delete an edge bounded by this vertex
  void addEdge(GEdge *e);
  void delEdge(GEdge *e);

  // get the edges that this vertex bounds
  virtual std::list<GEdge*> edges() const{ return l_edges; }

  // get the dimension of the vertex (0)
  virtual int dim() const { return 0; }

  // get the geometric type of the vertex
  virtual GeomType geomType() const { return Point; }

  // get/set the prescribed mesh size at the vertex
  inline double prescribedMeshSizeAtVertex() const { return meshSize; }
  virtual void setPrescribedMeshSizeAtVertex(double l) { meshSize = l; }

  // get the bounding box
  virtual SBoundingBox3d bounds() const { return SBoundingBox3d(SPoint3(x(), y(), z())); }

  // reparmaterize the point onto the given face
  virtual SPoint2 reparamOnFace(const GFace *gf, int) const;

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  // export in GEO format
  virtual void writeGEO(FILE *fp);

  // get number of elements in the mesh
  unsigned int getNumMeshElements();

  // get the element at the given index
  MElement *getMeshElement(unsigned int index);

  // return true if this vertex is on a seam of the given face
  bool isOnSeam(const GFace *gf) const;

  std::vector<MPoint*> points;
  
};

#endif
