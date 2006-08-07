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
  virtual SBoundingBox3d bounds(){ return SBoundingBox3d(SPoint3(x(), y(), z())); }
  virtual std::string getAdditionalInfoString()
  {
    char str[256];
    sprintf(str, "{%g,%g,%g", x(), y(), z());
    double lc = prescribedMeshSizeAtVertex();
    if(lc > 0.){
      char str2[256];
      sprintf(str2, ",%g", lc);
      strcat(str, str2);
    }
    strcat(str, "}");
    return std::string(str);
  }

 protected:
  std::list<GEdge*> l_edges;
};

#endif

