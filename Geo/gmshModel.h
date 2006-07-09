#ifndef _H_GMSH_MODEL_
#define _H_GMSH_MODEL_

#include <list>
#include "Mesh.h"
#include "Range.h"
#include "Pair.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "SBoundingBox3d.h"
#include "gmshVertex.h"
#include "gmshFace.h"
#include "gmshEdge.h"
#include "gmshRegion.h"
#include "GModel.h"


class gmshModel : public GModel {
public:
  gmshModel(char *geofile = 0); 
  virtual ~gmshModel() {};
  virtual void setGeomTolerance(double) {};
  virtual double tolerance() const {return 1.e-14;}

  //  virtual SBoundingBox3d bounds() const;
  /** Find the region with the given tag. */
  // virtual GRegion * regionByTag(int n) const;  
  /** Find the face with the given tag. */
  virtual GFace * faceByTag(int n) const;
  /** Find the edge with the given tag. */
  virtual GEdge * edgeByTag(int n) const;
  /** Find the vertex with the given tag. */
  virtual GVertex * vertexByTag(int n) const;
  /** Same, but with ids */
  //  virtual GRegion * regionByID(int n) const;
  virtual GFace * faceByID(int n) const {return faceByTag(n);}
  virtual GEdge * edgeByID(int n) const {return edgeByTag(n);}
  virtual GVertex * vertexByID(int n) const {return vertexByTag(n);}
  virtual GVertex *createVertex(std::istream &in){throw;}
  virtual GEdge *createEdge(std::istream &in){throw;}
  virtual GFace *createFace(std::istream &in){throw;}
  virtual GRegion *createRegion(std::istream &in){throw;}
#ifdef _HAVE_SGMODEL_
  virtual SString modeler() const {throw;}
  virtual SBoundingBox3d bounds() const {throw;}
#endif
protected: 
private:
  std::list<GFace*> faces;
  std::list<GEdge*> edges;
  std::list<GVertex*> vertices;
  std::list<GRegion*> regions;
};

#endif
