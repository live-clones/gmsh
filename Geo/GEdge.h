// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GEDGE_H_
#define _GEDGE_H_

#include <stdio.h>
#include "GEntity.h"
#include "GVertex.h"
#include "SVector3.h"
#include "SPoint3.h"
#include "SPoint2.h"

class MElement;
class MLine;
class ExtrudeParams;
class GEdgeCompound;

#include <set>

// A model edge.
class GEdge : public GEntity {
 private:
  double _length;
  bool _tooSmall;

 protected:
  GVertex *v0, *v1;
  GEdgeCompound *compound; // this model edge belongs to a compound 
  std::list<GFace *> l_faces;
  std::set<GFace *> bl_faces;

 public:
  GEdge(GModel *model, int tag, GVertex *_v0, GVertex *_v1);
  virtual ~GEdge();

  // delete mesh data
  virtual void deleteMesh();

  // get the start/end vertices of the edge
  GVertex *getBeginVertex() const { return v0; }
  GVertex *getEndVertex() const { return v1; }

  // add/delete a face bounded by this edge
  void addFace(GFace *f);
  void delFace(GFace *f);

  // get the dimension of the edge (1)
  virtual int dim() const { return 1; }

  // set the visibility flag
  virtual void setVisibility(char val, bool recursive=false);

  // true if the edge is a seam for the given face.
  virtual bool isSeam(const GFace *face) const { return false; }

  // get the bounding box
  virtual SBoundingBox3d bounds() const;

  // faces that this entity bounds
  virtual std::list<GFace*> faces() const { return l_faces; }

  // get the point for the given parameter location
  virtual GPoint point(double p) const = 0;
  
  // true if the edge contains the given parameter
  virtual bool containsParam(double pt) const;

  // get the position for the given parameter location
  virtual SVector3 position(double p) const
  {
    GPoint gp = point(p);
    return SVector3(gp.x(), gp.y(), gp.z());
  }
  
  // get first derivative of edge at the given parameter
  virtual SVector3 firstDer(double par) const = 0;

  // get second derivative of edge at the given parameter (default
  // implentation using central differences)
  virtual SVector3 secondDer(double par) const;

  // get the curvature
  virtual double curvature(double par) const;

  // reparmaterize the point onto the given face
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;

  // return the minimum number of segments used for meshing the edge
  virtual int minimumMeshSegments() const { return 1; }

  // return the minimum number of segments used for drawing the edge
  virtual int minimumDrawSegments() const { return 1; }

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  // export in GEO format
  virtual void writeGEO(FILE *fp);

  // tell if the edge is a 3D edge (in opposition with a trimmed curve on a surface)
  virtual bool is3D() const { return true; }

  // get/set/compute the length of the model edge
  inline double length() const { return _length; }
  inline void setLength(const double l) { _length = l; }
  double length(const double &u0, const double &u1, const int nbQuadPoints = 4);

  // get the prescribed mesh size on the edge
  virtual double prescribedMeshSizeAtVertex() const { return meshAttributes.meshSize; }

  // true if start == end and no more than 2 segments
  void setTooSmall(bool b) { _tooSmall = b; }
  bool isMeshDegenerated() const 
  { return _tooSmall || (v0 == v1 && mesh_vertices.size() < 2); }

  // number of types of elements
  int getNumElementTypes() const { return 1; }

  // get total/by-type number of elements in the mesh
  unsigned int getNumMeshElements();
  void getNumMeshElements(unsigned *const c) const;

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const;

  // get the element at the given index
  MElement *getMeshElement(unsigned int index);

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  // true if entity is periodic in the "dim" direction.
  virtual bool periodic(int dim) const { return v0 == v1; }

  // true if edge is used in hyperbolic layer on face gf
  virtual bool inHyperbolicLayer(GFace* gf)
  {
    return bl_faces.find(gf) != bl_faces.end();
  }

  virtual void flagInHyperbolicLayer(GFace* gf) {bl_faces.insert(gf);}

  // get bounds of parametric coordinate 
  virtual Range<double> parBounds(int i) const = 0;
  
  // return the point on the face closest to the given point
  virtual GPoint closestPoint(const SPoint3 & queryPoint,double& param) const;

  // try to reparametrise the point on the edge
  virtual double parFromPoint(const SVector3& Q) const;
  
  virtual bool XYZToU(const SVector3& Q,double& t,const double relax=0.5) const;

  // compound
  void setCompound (GEdgeCompound *gec) {compound = gec;}
  GEdgeCompound *getCompound () const {return compound;}

  struct {
    char Method;
    double coeffTransfinite;
    double meshSize;
    int nbPointsTransfinite;
    int typeTransfinite;
    int minimumMeshSegments;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
  } meshAttributes ;

  std::vector<MLine*> lines;
};

#endif
