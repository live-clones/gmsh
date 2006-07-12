#ifndef H_GVertex
#define H_GVertex

#include "GEntity.h"
#include "GPoint.h"

/** A model vertex. */
class GVertex  : public GEntity 
{
public:
  GVertex(GModel *m, int tag) : GEntity (m,tag) {}
  virtual ~GVertex() {}
  virtual GPoint point() const = 0;
  virtual double x() const = 0;
  virtual double y() const = 0;
  virtual double z() const = 0;
  void addEdge ( GEdge *e );
  void delEdge ( GEdge *e );
  virtual int dim() const {return 0;}
  virtual GeomType geomType() const {return Point;}
  virtual double prescribedMeshSizeAtVertex() const {return 0;}

protected:
  std::list<GEdge*> l_edges;
};

#endif

