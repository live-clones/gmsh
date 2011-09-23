// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (amjohnen@gmail.com)
//

#ifndef _MESH_RECOMBINE_2D_H_
#define _MESH_RECOMBINE_2D_H_

#include <map>
#include <set>
#include <vector>
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshGFaceOptimize.h"

class RecombTriangle;
class Recomb2D_Node;
class Rec2d_node;
class Rec2d_edge;
class Rec2d_cycle;
struct lessRecombTri {
  bool operator()(RecombTriangle *rt1, RecombTriangle *rt2) const;
};

typedef std::set<RecombTriangle*,lessRecombTri> Set_Recomb;
typedef std::map<MElement*,std::set<RecombTriangle*> > Map_Tri_Recomb;
typedef std::map<MElement*,Recomb2D_Node*> Map_Tri_Node;

class Recombine2D {
  private :
    GFace *_gf;
    int _horizon;
    double _benef;
    bool _haveParam, _applied;
    Set_Recomb _pairs, _lastRecomb;
    Map_Tri_Recomb _possibleRecomb;
    std::set<MElement*> _isolated;
    std::vector<MQuadrangle*> _quads;
    
    template <class E>
    void _buildEdgeToElement(std::vector<E*> &, e2t_cont &);
    void _recombine();
    Set_Recomb::iterator _bestNextRecombination();
    void _removeImpossible(Set_Recomb::iterator);
    void _rmRT(RecombTriangle *, MElement *e = NULL);
    
  public :
    Recombine2D(GFace*, int horizon);
    Recombine2D(GFace*);
    ~Recombine2D();
    
    int apply();
    double getBenef() const {return _benef;}
    int numTriangle() const {return _isolated.size();}
    
  private :
    std::set<Rec2d_node*> _nodes;
    std::set<Rec2d_edge*> _edges;
    std::set<Rec2d_cycle*> _cycles;
};

class RecombTriangle {
  private :
    std::vector<MElement *> _t;
    MVertex *_n1, *_n2, *_n3, *_n4;
    double _angle;
    double _benefit;
    bool _formingQuad;
    int _sign;
    
  public :
    RecombTriangle(const MEdge &, MElement *, MElement *);
    RecombTriangle(MElement *, double);
    
    double touch();
    
    MQuadrangle *createQuad() const;
    bool operator<(const RecombTriangle &other) const;
    
    void triangles(std::vector<MElement *> &v) const {v = _t;}
    int numTriangles() const {return (int) _t.size();}
    MElement *triangle(int i) const {
      if (i >= 0 && i < _t.size())
	return _t[i];
      return NULL;
    }
    bool isQuad() const {return _formingQuad;}
    double getBenef() const {return _benefit;}
    
    double compute_alignment(const MEdge&, MElement*, MElement*);
};

class Recomb2D_Node {
  private :  
    double _benef, _totBenef;
    int _nskip, _depth;
    Set_Recomb::iterator _recomb;
    Map_Tri_Node *_touch;
    std::vector<Map_Tri_Node::iterator> _vit;
    std::set<int> _blocking;
  
  public :
    //Node(){}
    //Recomb2D_Node(Set_Recomb::iterator, Map_Tri_Node &, int, double ben = .0);
    
    Recomb2D_Node(Set_Recomb::iterator, int nskip, int depth, Map_Tri_Node &);
    Recomb2D_Node(Set_Recomb::iterator, int nskip, Recomb2D_Node *);
    ~Recomb2D_Node();
    
    void erase();
    void blocking(const Map_Tri_Node::iterator &);
    bool isBetter() {return _blocking.size() < 2;}
    Set_Recomb::iterator getItRecomb() {return _recomb;}
    double getTotBenef() {return _totBenef;}
    int getnSkip() {return _nskip;}
    double getBound() {return _totBenef + _benef * _depth;}
};


class Rec2d_node {
  private :
    std::set<Rec2d_edge*> _freeEdges;
    std::set<Rec2d_cycle*> _cycle3;
    std::set<Rec2d_cycle*> _cycle4;
  
  public :
    Rec2d_node(){}
    
    void addCycle(Rec2d_cycle*, int n = 0);
    void addEdge(Rec2d_edge*);
    
    void print();
};
class Rec2d_edge {
  private :
    Rec2d_node *_nodes[2];
    std::set<Rec2d_cycle*> _cycles;
  
  public :
    Rec2d_edge(Rec2d_node*, Rec2d_node*);
    
    void addCycle(Rec2d_cycle*);
    
    void print();
};
class Rec2d_cycle {
  private :
    std::set<Rec2d_edge*> _edges;
  
  public :
    Rec2d_cycle(){}
    void addEdge(Rec2d_edge*);
    int size() {return _edges.size();}
    
    void print();
};


#endif
