#ifndef _GVERTEX_H_
#define _GVERTEX_H_

#include "GEntity.h"
#include "MVertex.h"
#include "GPoint.h"

// A model vertex
class GVertex  : public GEntity 
{
 protected:
  std::list<GEdge*> l_edges;

 public:
  GVertex(GModel *m, int tag) : GEntity (m, tag) {}
  virtual ~GVertex() ;
  virtual GPoint point() const = 0;
  virtual double x() const = 0;
  virtual double y() const = 0;
  virtual double z() const = 0;
  void addEdge(GEdge *e);
  void delEdge(GEdge *e);
  virtual int dim() const {return 0;}
  virtual GeomType geomType() const {return Point;}
  virtual double prescribedMeshSizeAtVertex() const {return 0;}
  virtual SBoundingBox3d bounds(){ return SBoundingBox3d(SPoint3(x(), y(), z())); }
  virtual std::string getAdditionalInfoString();
};

#endif

