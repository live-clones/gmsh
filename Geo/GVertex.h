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
  void addEdge ( GEdge *e );
  void delEdge ( GEdge *e );
protected:
  std::list<GEdge*> l_edges;
};

#endif

