#ifndef _GVERTEX_H_
#define _GVERTEX_H_

#include "GEntity.h"
#include "MVertex.h"
#include "GPoint.h"

// A model vertex
class GVertex  : public GEntity 
{
public:
  GVertex(GModel *m, int tag) : GEntity (m,tag) 
  {
  }
  virtual ~GVertex() 
  {
    if(mesh_vertices.size())
      delete mesh_vertices[0];
  }
  virtual GPoint point() const = 0;
  virtual double x() const = 0;
  virtual double y() const = 0;
  virtual double z() const = 0;
  void addEdge(GEdge *e);
  void delEdge(GEdge *e);
  virtual int dim() const {return 0;}
  virtual GeomType geomType() const {return Point;}
  virtual double prescribedMeshSizeAtVertex() const {return 0;}
  virtual std::string getInfoString()
  {
    char tmp[256];
    sprintf(tmp, "%s %d {%g,%g,%g}", getTypeString().c_str(), 
	    tag(), x(), y(), z());
    return std::string(tmp);
  }

 protected:
  std::list<GEdge*> l_edges;
};

#endif

