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
class TrianglesUnion;
class Rec2d_vertex;
struct lessRecombTri {
  bool operator()(RecombTriangle *rt1, RecombTriangle *rt2) const;
};
struct lessTriUnion {
  bool operator()(TrianglesUnion *, TrianglesUnion *) const;
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
    int apply(bool);
    inline double getBenef() const {return _benef;}
    inline int numTriangle() const {return _isolated.size();}
    
  private :
    //std::set<TrianglesUnion*, lessTriUnion> _setQuads;
    std::list<TrianglesUnion*> _setQuads;
    void _removeImpossible(std::list<TrianglesUnion*>::iterator);
    void _recombine(bool);
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
    
    inline void triangles(std::vector<MElement *> &v) const {v = _t;}
    inline int numTriangles() const {return (int) _t.size();}
    MElement *triangle(int i) const {
      if (i >= 0 && i < _t.size())
        return _t[i];
      return NULL;
    }
    inline bool isQuad() const {return _formingQuad;}
    inline double getBenef() const {return _benefit;}
    
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
    inline bool isBetter() {return _blocking.size() < 2;}
    inline Set_Recomb::iterator getItRecomb() {return _recomb;}
    inline double getTotBenef() {return _totBenef;}
    inline int getnSkip() {return _nskip;}
    inline double getBound() {return _totBenef + _benef * _depth;}
};


class Rec2d_vertex {
  private :
    // _onWhat={-1:corner,0:edge,1:face,(2:volume)}
    int _onWhat, _numEl;
    double _angle;
    // GEdge : virtual SVector3 firstDer(double par) const = 0;
    // GEntity : virtual Range<double> parBounds(int i)
    static double **_Vvalues;
    static double **_Vbenefs;
    
    void _initStaticTable();
    double _computeAngle(MVertex *, std::list<MTriangle*> &, std::set<GEdge*> &);
  
  public :
    Rec2d_vertex(MVertex *, std::list<MTriangle*> &,
                 std::map<MVertex*, std::set<GEdge*> > &);
    
    inline void changeNumEl(int c) {_numEl += c;}
    double getReward();
    double getReward(int);
};

class TrianglesUnion {
  private :
    int _numEmbEdge, _numEmbVert, _numBoundVert, _numTri, _computation;
    double _embEdgeValue, _embVertValue, _globValIfExecuted;
    Rec2d_vertex **_vertices;
    MTriangle **_triangles;
    static int _RECOMPUTE; //incremented when a recombination is executed
    public:
    static int _NumEdge, _NumVert;
    static double _ValEdge, _ValVert;
    private:
    
    double _computeEdgeLength(GFace *, MVertex **, double *u, double *v,
                              int numIntermedPoint= 1);
    double _computeAlignment(MEdge &, std::list<MTriangle*> &);
    void _update();
    
  public :
    TrianglesUnion(GFace *, std::list<MTriangle*> &, std::list<MEdge> &,
                   std::list<Rec2d_vertex*> &, std::map<MVertex*,double> &);
    
    bool operator<(TrianglesUnion &other);
    inline double getEdgeValue() {return _embEdgeValue;}
    inline double getNumTriangles() {return _numTri;}
    inline MTriangle *getTriangle(int num) {return _triangles[num];}
    void select() {
      _ValEdge -= _embEdgeValue;
      _NumEdge -= _numEmbEdge;
      _ValVert -= _embVertValue;
      _NumVert -= _numEmbVert;
      for (int i = 0; i < _numBoundVert; i++) {
        _ValVert += _vertices[i]->getReward(-1);
      }
      _RECOMPUTE++;
    }
    MQuadrangle *createQuad() const;
};
#endif
