// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GREGION_H_
#define _GREGION_H_

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include "GEntity.h"

class MElement;
class MTetrahedron;
class MHexahedron;
class MPrism;
class MPyramid;
class MPolyhedron;
class ExtrudeParams;
class bindings;

// A model region.
class GRegion : public GEntity {
 protected:
  std::list<GFace*> l_faces;
  std::list<int> l_dirs;

  // replace faces (for gluing) for specific modelers, we have to
  // re-create internal data ...
  virtual void replaceFacesInternal (std::list<GFace*> &) {}

 public:
  GRegion(GModel *model, int tag);
  virtual ~GRegion();

  // delete mesh data
  virtual void deleteMesh();

  // get the dimension of the region (3)
  virtual int dim() const { return 3; }

  // set the visibility flag
  virtual void setVisibility(char val, bool recursive=false);

  // get/set faces that bound the region
  virtual std::list<GFace*> faces() const{ return l_faces; }
  virtual std::list<int> faceOrientations() const{ return l_dirs; }
  inline void set(const std::list<GFace*> f) { l_faces = f; }

  // edges that bound the region
  virtual std::list<GEdge*> edges() const;

  // get the bounding box
  virtual SBoundingBox3d bounds() const;

  // get the oriented bounding box
  virtual SOrientedBoundingBox getOBB();

  // check if the region is connected to another region by an edge
  bool edgeConnected(GRegion *r) const;

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString();

  // export in GEO format
  virtual void writeGEO(FILE *fp);

  // number of types of elements
  int getNumElementTypes() const { return 5; }

  // get total/by-type number of elements in the mesh
  unsigned int getNumMeshElements();
  void getNumMeshElements(unsigned *const c) const;

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const;

  // get the element at the given index
  MElement *getMeshElement(unsigned int index);

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  struct {
    // is this surface meshed using a transfinite interpolation
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
  std::vector<MPolyhedron*> polyhedra;

  void addPrism(MPrism *p);

  // replace edges (gor gluing)
  void replaceFaces (std::list<GFace*> &);

  static void registerBindings(binding *b);
};

#endif
