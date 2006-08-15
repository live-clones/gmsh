#ifndef _MREP_H_
#define _MREP_H_

#include <set>
#include <algorithm>
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MElement.h"
#include "VertexArray.h"
#include "Message.h"

class MRep {
 public:
  MRep() : va_lines(0), va_triangles(0), va_quads(0) {}
  virtual ~MRep(){}
  virtual void generateEdges() = 0;
  std::set<MEdge, MEdgeLessThan> edges;
  VertexArray *va_lines, *va_triangles, *va_quads;
};

class MRepEdge : public MRep {
 private:
  GEdge *_e;

public:
  MRepEdge(GEdge *e) : _e(e) {}
  virtual ~MRepEdge(){}
  virtual void generateEdges()
  {
    if(edges.size()) return;
    for(unsigned int i = 0; i < _e->lines.size(); i++)
      for(int j = 0; j < _e->lines[i]->getNumEdgesRep(); j++)
	edges.insert(_e->lines[i]->getEdgeRep(j));
    Msg(DEBUG, "%d edges in line %d", (int)edges.size(), _e->tag());
  }
};

class MRepFace : public MRep {
 private:
  GFace *_f;

 public:
  MRepFace(GFace *f) : _f(f) {}
  virtual ~MRepFace(){}
  virtual void generateEdges()
  {
    if(edges.size()) return;
    for(unsigned int i = 0; i < _f->triangles.size(); i++)
      for(int j = 0; j < _f->triangles[i]->getNumEdgesRep(); j++)
	edges.insert(_f->triangles[i]->getEdgeRep(j));
    for(unsigned int i = 0; i < _f->quadrangles.size(); i++)
      for(int j = 0; j < _f->quadrangles[i]->getNumEdgesRep(); j++)
	edges.insert(_f->quadrangles[i]->getEdgeRep(j));
    Msg(DEBUG, "%d edges in surface %d", (int)edges.size(), _f->tag());
  }
};

class MRepRegion : public MRep {
 private:
  GRegion *_r;

 public:
  MRepRegion(GRegion *r) : _r(r) {}
  virtual ~MRepRegion(){}
  virtual void generateEdges()
  {
    if(edges.size()) return;
    for(unsigned int i = 0; i < _r->tetrahedra.size(); i++)
      for(int j = 0; j < _r->tetrahedra[i]->getNumEdgesRep(); j++)
	edges.insert(_r->tetrahedra[i]->getEdgeRep(j));
    for(unsigned int i = 0; i < _r->hexahedra.size(); i++)
      for(int j = 0; j < _r->hexahedra[i]->getNumEdgesRep(); j++)
	edges.insert(_r->hexahedra[i]->getEdgeRep(j));
    for(unsigned int i = 0; i < _r->prisms.size(); i++)
      for(int j = 0; j < _r->prisms[i]->getNumEdgesRep(); j++)
	edges.insert(_r->prisms[i]->getEdgeRep(j));
    for(unsigned int i = 0; i < _r->hexahedra.size(); i++)
      for(int j = 0; j < _r->hexahedra[i]->getNumEdgesRep(); j++)
	edges.insert(_r->hexahedra[i]->getEdgeRep(j));
    Msg(DEBUG, "%d edges in volume %d", (int)edges.size(), _r->tag());
  }
};

#endif
