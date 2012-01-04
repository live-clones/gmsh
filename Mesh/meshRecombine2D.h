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
class list_actions;
class Recombine2D;
//class list_actions;
//class list_actions::iterator;
struct lessRecombTri {
  bool operator()(RecombTriangle *rt1, RecombTriangle *rt2) const;
};
struct lessTriUnion {
  bool operator()(TrianglesUnion *, TrianglesUnion *) const;
};
struct lessTriUnionInv {
  bool operator()(TrianglesUnion *, TrianglesUnion *) const;
};
typedef std::set<RecombTriangle*,lessRecombTri> Set_Recomb;
typedef std::map<MElement*,std::set<RecombTriangle*> > Map_Tri_Recomb;
typedef std::map<MElement*,Recomb2D_Node*> Map_Tri_Node;
typedef std::map<MTriangle*, std::set<TrianglesUnion*> > mapTriUnion;
typedef std::set<TrianglesUnion*, lessTriUnionInv> setTriUnion;
typedef std::vector<setTriUnion> vectSetTriUnion;

class list_actions {
  private :
    vectSetTriUnion _cont;
    
  public :
    list_actions(int h) {_cont.reserve(h);}
    
    class iterator {
      private :
        int pos;
        list_actions *la;
        setTriUnion::iterator it;
      
      public :
        void print() {
          Msg::Info("iterator(pos %d, la %d, tu %d)", pos, la, *it);
        }
        iterator(list_actions *l, int i, setTriUnion::iterator t) {
          pos = i;
          la = l;
          it = t;
        }
        iterator() {
          pos = -1;
        }
        bool operator==(iterator a) const {
          if (pos != a.pos)
            return false;
          if (pos < 0)
            return true;
          return it == a.it;
        }
        bool operator!=(iterator a) const {
          if (pos != a.pos)
            return true;
          if (pos < 0)
            return false;
          return it != a.it;
        }
        iterator& operator=(const iterator &a) {
          if (this != &a) {
            pos = a.pos;
            la = a.la;
            it = a.it;
          }
          return *this;
        }
        TrianglesUnion* operator*() const {
          //Msg::Info("pos %d", pos);
          //Msg::Info(" ");
          if (pos < 0)
            return NULL;
          return *it;
        }
        iterator& operator++() {
          int p = pos;
          ++it;
          while (it == la->_end(p) && ++p != la->_size()) {
            ++pos;
            it = la->_begin(pos);
          }
          return *this;
        }
        iterator& operator--() {
          int p = pos;
          while (it == la->_begin(p) && --p > -1) {
            --pos;
            it = la->_end(pos);
          }
          if (p > -1)
            --it;
          return *this;
        }
        iterator operator++(int n) {
          iterator t = *this;
          int p = pos;
          ++it;
          while (it == la->_end(p) && ++p != la->_size()) {  
            ++pos;
            it = la->_begin(pos);
          }
          return t;
        }
        inline int getPos() {return pos;}
    };
    
    int add(setTriUnion &s) {
      setTriUnion::iterator it = s.begin();
      while (it != s.end()) {
        if (find(*it) != end())
          s.erase(it++);
        else
          ++it;
      }
      _cont.push_back(s);
      return _cont.size() - 1;
    }
    void remove(int a) {
      for (; a < _cont.size(); a++)
        _cont.pop_back();
    }
    iterator find(TrianglesUnion* tu) {
      if (_cont.empty())
        return end();
      for (int i = 0; i < _cont.size(); ++i) {
        setTriUnion::iterator it = _cont[i].find(tu);
        if (it != _cont[i].end())
          return iterator(this, i, it);
      }
      return end();
    }
    iterator begin() {
      if (_cont.empty())
        return iterator(this, -1, _begin());
      return iterator(this, 0, _begin());
    }
    iterator end() {
      return iterator(this, _cont.size() - 1, _end()); 
    }
    void pop_back() {
      _cont.pop_back(); 
    }
    
    void sizes(){
      switch (_cont.size()) {
        case 3 :
          Msg::Info("--Actions : %d + %d + %d", _cont[0].size(), _cont[1].size(), _cont[2].size());
          break;
        case 2 :
          Msg::Info("--Actions : %d + %d", _cont[0].size(), _cont[1].size());
          break;
        case 1 :
          Msg::Info("--Actions : %d", _cont[0].size());
          break;
        default :
          break;
      }
      //Msg::Info("%d sets", _cont.size());
      //for (int i = 0; i < _cont.size(); ++i)
      //  Msg::Info("[%d] %d", i+1, _cont[i].size());
    }
  
  private :
    setTriUnion::iterator _end(int pos = -1) {
      if (_cont.size() == 0) {
        setTriUnion::iterator it;
        return it; // Not clean !
      }
      if (pos < 0)
        return _cont.back().end();
      return _cont[pos].end();
    }
    setTriUnion::iterator _begin(int pos = -1) {
      if (_cont.size() == 0) {
        setTriUnion::iterator it;
        return it; // Not clean !
      }
      if (pos < 0)
        return _cont.front().begin();
      return _cont[pos].begin();
    }
    inline int _size() {return _cont.size();}
    
};



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
    static int ra;
    
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
    inline double getBenef() const {return _benef;}
    inline int numTriangle() const {return _isolated.size();}
    
  private :
    //std::set<TrianglesUnion*, lessTriUnion> _setQuads;
    std::list<TrianglesUnion*> _setQuads;
    std::list<TrianglesUnion*> _lastQuad;
    mapTriUnion _possibleActions;
    mapTriUnion _lessActions;
    void _removeImpossible(TrianglesUnion*);
    void _recombine(bool);
    
    void _lookAhead(std::list<TrianglesUnion*> &, int horiz);
    void _lookAhead2(std::list<TrianglesUnion*> &, int horiz);
    void _getIncompatibles(const TrianglesUnion*, setTriUnion &);
    void _getNeighbors(const TrianglesUnion*, setTriUnion &);
    void _addNeighbors(int horiz, std::vector<list_actions::iterator> &,
                       int current, list_actions*);
    void _removeNeighbors(int horiz, int current, list_actions*);
    int _checkIsolatedTri(const std::vector<list_actions::iterator> &,
                          int size, std::set<MTriangle*> &);
    double _realisticReturn(const int *num,
                            const double *val,
                            const std::map<Rec2d_vertex*, int> &,
                            const std::vector<list_actions::iterator> &,
                            int size,
                            const std::set<MTriangle*> &);

  public :
    int apply(bool);
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
  
  public :
    Rec2d_vertex(MVertex *, std::list<MTriangle*> &,
                 std::map<MVertex*, std::set<GEdge*> > &, bool);
    
    inline void changeNumEl(int c) {_numEl += c;}
    double getReward();
    double getReward(int);
    //int onwhat() {return _onWhat;}
    //int numel() {return _numEl;}
    
  private :
    void _initStaticTable();
    double _computeAngle(MVertex *, std::list<MTriangle*> &, std::set<GEdge*> &);
};

class TrianglesUnion {
  private :
    int _numEmbEdge, _numboundEdge, _numEmbVert, _numBoundVert, _numTri, _computation;
    double _embEdgeValue, _boundEdgeValue, _embVertValue, _globValIfExecuted;
    Rec2d_vertex **_vertices;
    MTriangle **_triangles;
    static int _RECOMPUTE; //incremented when a recombination is executed
    
    public:
    static int _NumEdge, _NumVert;
    static double _ValEdge, _ValVert;
    private:
    
  public :
    TrianglesUnion(GFace *, std::list<MTriangle*> &, std::list<MEdge> &,
                   std::list<Rec2d_vertex*> &, std::map<MVertex*,double> &,
                   std::map<MEdge, std::list<MTriangle*>, Less_Edge>&);
    
    bool operator<(TrianglesUnion &other);
    void addTri(std::set<MTriangle*>&) const;
    void removeTri(std::set<MTriangle*>&) const;
    bool isIn(std::set<MTriangle*>&) const;
    void addInfluence(int*, double*, std::map<Rec2d_vertex*, int>&) const;
    void removeInfluence(int*, double*, std::map<Rec2d_vertex*, int>&) const;
    static double computeReturn(const int*, const double*, const std::map<Rec2d_vertex*, int>&);
    inline double getEdgeValue() const {return _embEdgeValue;}
    inline double getVertValue() const {return _embVertValue;}
    inline int getNumVerts() const {return _numEmbVert;}
    inline int getNumEdges() const {return _numEmbEdge;}
    inline int getNumVertices() const {return _numBoundVert;}
    inline Rec2d_vertex* getVertex(int num) const {return _vertices[num];}
    inline int getNumTriangles() const {return _numTri;}
    inline MTriangle* getTriangle(int num) const {return _triangles[num];}
    void select() {
      _ValEdge -= _embEdgeValue;
      _NumEdge -= _numEmbEdge;
      _ValEdge += _boundEdgeValue;
      _NumEdge += _numboundEdge;
      _ValVert -= _embVertValue;
      _NumVert -= _numEmbVert;
      for (int i = 0; i < _numBoundVert; i++) {
        _ValVert += _vertices[i]->getReward(-1);
        _vertices[i]->changeNumEl(-1);
      }
      _RECOMPUTE++;
    }
    MQuadrangle* createQuad() const;
    void print() {
      Msg::Info("Printing TU (%d,%d,%d,%d)", _numEmbVert, _numBoundVert, _numEmbEdge, _numTri);
      for (int i = 0; i < _numTri; i++)
        Msg::Info("Triangle %d", _triangles[i]->getNum());
    }
    static inline void addRec() {_RECOMPUTE++;}
    inline double getReturn() {return _globValIfExecuted;}
    inline static double getActualReturn() {
      return _ValEdge/_NumEdge * _ValVert/_NumVert * _ValVert/_NumVert;
    }
  
    static void clear() {_NumEdge = 0; _NumVert = 0;
      _ValEdge = .0, _ValVert = .0;}

  private:  
    double _computeEdgeLength(GFace*, MVertex**, double *u, double *v,
                              int numIntermedPoint= 1);
    double _computeAlignment(const MEdge&, std::list<MTriangle*>&,
                             std::map<MEdge, std::list<MTriangle*>, Less_Edge>&);
    void _update();
};
#endif
