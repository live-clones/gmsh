#ifndef _GEDGE_H_
#define _GEDGE_H_

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

  virtual int dim() const {return 1;}

  virtual bool periodic(int dim=0) const = 0;
  virtual bool continuous(int dim=0) const = 0;

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

  // reparmaterize the point onto the given face.
  virtual SPoint2 reparamOnFace(GFace *face, double epar,int dir) const = 0;

  // recompute the mesh partitions defined on this edge.
  void recomputeMeshPartitions();

  void addFace(GFace *f);
  void delFace(GFace *f);

  GVertex *getBeginVertex () const { return v0; }
  GVertex *getEndVertex () const { return v1; }
  
  struct {
    char   Method;
    double coeffTransfinite;
    int    nbPointsTransfinite;
    int    typeTransfinite;
  } meshAttributes ;

  std::vector<MLine*> lines;

  virtual int minimumMeshSegments () const {return 1;}
  virtual int minimumDrawSegments () const {return 1;}

  virtual std::string getAdditionalInfoString()
  {
    char tmp[256];
    sprintf(tmp, "{%d,%d}", v0->tag(), v1->tag());
    return std::string(tmp);
  }
};

#endif
