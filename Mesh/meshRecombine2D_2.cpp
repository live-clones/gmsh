// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (amjohnen@gmail.com) adapted from meshGFaceOptimize
//

#include "meshRecombine2D.h"
#include "GFace.h"
#include <cmath>
#include <FL/Fl.H>
#include "drawContext.h"
#include "FlGui.h"
#include "Context.h"
#include "OpenFile.h"//pas propre

static int HORIZ = 20;

Recombine2D::Recombine2D(GFace *gf)
: _horizon(0), _gf(gf), _benef(.0), _applied(true)
{
  std::map<MEdge, Rec2d_edge*, Less_Edge> mapEdge;
  std::map<MVertex*, Rec2d_node*> mapNode;
  
  for (unsigned int i = 0; i < gf->triangles.size(); i++) {
    Rec2d_cycle *rc = new Rec2d_cycle();
    _cycles.insert(rc);
    MTriangle *t = gf->triangles[i];
    
    for (int j = 0; j < 3; j++) {
      MVertex *v = t->getVertex(j);
      std::map<MVertex*, Rec2d_node*>::iterator itn = mapNode.find(v);
      if (itn == mapNode.end()) {
        Rec2d_node *rn = new Rec2d_node();
        mapNode[v] = rn;
        _nodes.insert(rn);
        rn->addCycle(rc, 3);
      }
      else
        (*itn).second->addCycle(rc, 3);
    }
    
    for (int j = 0; j < 3; j++) {
      MEdge e = t->getEdge(j);
      std::map<MEdge, Rec2d_edge*>::iterator ite = mapEdge.find(e);
      if (ite == mapEdge.end()) {
        Rec2d_node *n0 = mapNode[e.getVertex(0)];
        Rec2d_node *n1 = mapNode[e.getVertex(1)];
        Rec2d_edge *re = new Rec2d_edge(n0, n1);
        n0->addEdge(re);
        n1->addEdge(re);
        mapEdge[e] = re;
        _edges.insert(re);
        rc->addEdge(re);
        re->addCycle(rc);
      }
      else {
        rc->addEdge((*ite).second);
        (*ite).second->addCycle(rc);
      }
    }
  }
  }ZzZ
}

void Rec2d_node::addCycle(Rec2d_cycle *c, int n)
{
  if (n == 3) {
    _cycle3.insert(c);
    return;
  }
  if (n == 4) {
    _cycle4.insert(c);
    return;
  }
  if (c->size() == 3) {
    _cycle3.insert(c);
    return;
  }
  if (c->size() == 4) {
    _cycle4.insert(c);
    return;
  }
  Msg::Error("[Recombine2D] Can't tell if it's a cycle3 or a cycle4");
}
void Rec2d_node::addEdge(Rec2d_edge *e)
{
  _freeEdges.insert(e); //que faire ?
}
void Rec2d_node::print()
{
  Msg::Info("Node : %d cycle3, %d cycle4, %d edges", _cycle3.size(), _cycle4.size(), _freeEdges.size());
}

Rec2d_edge::Rec2d_edge(Rec2d_node *n0, Rec2d_node *n1)
{
  _nodes[0] = n0;
  _nodes[1] = n1;
}
void Rec2d_edge::addCycle(Rec2d_cycle *c)
{
  _cycles.insert(c);
}
void Rec2d_edge::print()
{
  Msg::Info("Edge : %d cycles", _cycles.size());
}

void Rec2d_cycle::addEdge(Rec2d_edge *e)
{
  _edges.insert(e);
}
void Rec2d_cycle::print()
{
  Msg::Info("Cycle : %d edges", _edges.size());
}

