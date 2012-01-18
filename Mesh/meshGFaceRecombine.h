// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#ifndef _MESH_GFACE_RECOMBINE_H_
#define _MESH_GFACE_RECOMBINE_H_

#include "GFace.h"
#include "GModel.h"
#include "MEdge.h"
#include "BackgroundMesh.h"

class Rec2DVertex;
class Rec2DEdge;
class Rec2DElement;
class Rec2DAction;

typedef std::list<Rec2DAction*> setofRec2DAction;
typedef std::map<MVertex*, Rec2DVertex*> mapofVertices;
typedef std::map<MEdge, Rec2DEdge*, Less_Edge> mapofEdges;
typedef std::map<MElement*, Rec2DElement*> mapofElements;
typedef std::map<MElement*, std::set<Rec2DAction*> > mapofElementActions;
typedef std::map<MQuadrangle*, std::set<MElement*> > mapofAdjacencies;

struct lessRec2DAction {
  bool operator()(Rec2DAction*, Rec2DAction*) const;
};

class Recombine2D {
  private :
    int _numEdge, _numVert, _numChange;
    double _valEdge, _valVert;
    GFace *_gf;
    backgroundMesh *_bgm;
    mapofVertices _vertices;
    mapofEdges _edges;
    mapofElements _elements;
    setofRec2DAction _actions;
    mapofElementActions _mea;
    mapofAdjacencies _ma;
    std::map<int, std::set<Rec2DVertex*> > _parities;
    std::vector<Rec2DAction*> _obsoleteAction;
    static Recombine2D *_current;
    
      std::vector<MTriangle*> _tri;
      std::vector<MQuadrangle*> _quad;
      std::vector<Rec2DVertex*> _checkAllQuad;
    
  public :
    static bool bo;
    
    Recombine2D(GFace*);
    Recombine2D(GModel*);
    ~Recombine2D();
    
    bool recombine();
    void apply(bool){return;}
    
    static int getNumVertAllQuad() {return _current->_checkAllQuad.size();}
    static Rec2DVertex* getVertAllQuad(int i) {return _current->_checkAllQuad[i];}
    static void removeVertAllQuad(Rec2DVertex *rv) {
      std::vector<Rec2DVertex*>::iterator it = _current->_checkAllQuad.begin();
      while (it != _current->_checkAllQuad.end()) {
        if (*it == rv)
          it = _current->_checkAllQuad.erase(it);
        else
          ++it;
      }
    }
    static void addVertAllQuad(Rec2DVertex *rv) {
      _current->_checkAllQuad.push_back(rv);
    }
    
    //static inline double edgeReward(double adimLength, double alignment)
    //  {return adimLength * ((1-REC2D_ALIGNMENT) + REC2D_ALIGNMENT * alignment);}
    static inline int getNumChange() {return _current->_numChange;}
    static inline backgroundMesh* bgm() {return _current->_bgm;}
    static double getGlobalValue(int numEdge, double valEdge,
                                 int numVert, double valVert );
    //static Rec2DVertex* getRVertex(MVertex*);
    static Rec2DEdge* getREdge(MEdge);
    static Rec2DElement* getRElement(MElement*);
    static void remove(MEdge);
    static void remove(MVertex*);
    static inline GFace* getGFace() {return _current->_gf;}
    static inline void addObsleteAction(Rec2DAction *a) {
      _current->_obsoleteAction.push_back(a);
    } // correct ?
    static inline void addNumEdge(int a) {_current->_numEdge += a;}
    static inline void addNumVert(int a) {_current->_numVert += a;}
    static inline void addValEdge(double a) {_current->_valEdge += a;}
    static inline void addValVert(double a) {_current->_valVert += a;}
    
    static void remove(Rec2DElement*);
    static void remove(Rec2DAction*);
    static void add(MQuadrangle*);
    
    static inline void addVert2Par(Rec2DVertex *rv, int a)
      {_current->_parities[a].insert(rv);}
    static void associateParity(int pOld, int pNew);
    static inline int highPar() {
      std::map<int, std::set<Rec2DVertex*> >::iterator it;
      it = _current->_parities.end();
      --it;
      return it->first + 1;
    }
    
  private :
    bool _isAllQuad(Rec2DAction *action);
    void _choose(Rec2DAction*);
    void _removeIncompatible(Rec2DAction*);
    void _removeReference(Rec2DAction*);
    void _getNeighbours(Rec2DAction*, std::set<Rec2DAction*>&);
    void _getElemToLook(int par, std::set<Rec2DElement*>&);
};

class Rec2DAction {
  private :
    int _position;
    
  protected :
    int _lastUpdate; // + _lastCheck
    double _globValIfExecuted;
    
  public :
    virtual ~Rec2DAction() {Recombine2D::remove(this);}
    bool operator<(Rec2DAction&);
    inline int getVectPosition() const {return _position;}
    inline void setVectPosition(int p) {_position = p;}
    
    virtual int getNum() = 0;
    virtual double getReward() {
      if (_lastUpdate < Recombine2D::getNumChange())
        _computeGlobVal();
      return _globValIfExecuted - Recombine2D::getGlobalValue(0, .0, 0, .0);
    }
    virtual bool isObsolete() = 0;
    virtual void getRTriangles(std::set<Rec2DElement*>&) = 0;
    virtual Rec2DElement* getRTriangle(int) = 0;
    virtual void apply() = 0;
    virtual void getParities(int*) = 0;
    virtual Rec2DVertex* getRVertex(int) = 0;
    virtual void color(int, int, int) = 0;
    virtual bool whatImply(Rec2DVertex**, int*,
                           std::map<Rec2DVertex*, std::vector<int> >&) = 0;
  
  protected :
    MQuadrangle* _createQuad(std::vector<Rec2DEdge*>&) const;
  
  private :
    virtual void _computeGlobVal() = 0;
};

class Rec2DTwoTri2Quad : public Rec2DAction {
  private :
    Rec2DElement *_rtriangles[2];
    Rec2DEdge *_edges[5]; // 1 embedded, 4 boundary
    Rec2DVertex *_vertices[4]; // 4 boundary (2 on embedded edge + 2)
    
  public :
    Rec2DTwoTri2Quad(Rec2DEdge*, std::vector<MTriangle*>&);
    ~Rec2DTwoTri2Quad();
    bool isObsolete();
    void getRTriangles(std::set<Rec2DElement*> &tri) {
      tri.insert(_rtriangles[0]);
      tri.insert(_rtriangles[1]);
    }
    Rec2DElement* getRTriangle(int a) {
      return _rtriangles[a];
    }
    void apply();
    void getParities(int*);
    Rec2DVertex* getRVertex(int i) {return _vertices[i];}
    void color(int, int, int);
    virtual bool whatImply(Rec2DVertex**, int*,
                           std::map<Rec2DVertex*, std::vector<int> >&);
    static bool isObsolete(int*);
    
    int getNum() {return 1;}
  private :
    void _computeGlobVal();
};

/*class Rec2DFourTri2Quad : public Rec2DAction {
  private :
    Rec2DElement *_rtriangles[4];
    Rec2DEdge *_edges[8]; // 4 embedded, 4 boundary
    Rec2DVertex *_vertices[5]; // 4 boundary (2 non adjacent + 2), 1 embedded
    
  public :
    Rec2DFourTri2Quad(Rec2DVertex*, std::vector<MTriangle*>&);
    ~Rec2DFourTri2Quad();
    bool isObsolete();
    void getRTriangles(std::set<Rec2DElement*> &tri) {
      tri.insert(_rtriangles[0]);
      tri.insert(_rtriangles[1]);
      tri.insert(_rtriangles[2]);
      tri.insert(_rtriangles[3]);
    }
    Rec2DElement* getRTriangle(int a) {
      return _rtriangles[a];
    }
    void apply();
    void getParities(int*);
    Rec2DVertex* getRVertex(int i) {return _vertices[i];}
    void color(int, int, int);
    virtual void whatImply(Rec2DVertex**, int*,
                           std::map<Rec2DVertex*, std::vector<int> >&)
    {return;}
    
    int getNum() {return 2;}
  private :
    void _computeGlobVal();
};

class Rec2DCollapseTri : public Rec2DAction {
  private :
    Rec2DElement *_rtriangles[4]; // either 2 or 4 triangles
    Rec2DEdge *_edge; // 1 embedded or NULL
    Rec2DVertex *_vertices[5]; // 4 boundary (2 on embedded edge + 2), 1 embedded or NULL
    double _globValIfExecuted2;
    
  public :
    Rec2DCollapseTri(Rec2DVertex*, std::vector<MTriangle*>&);
    Rec2DCollapseTri(Rec2DEdge*, std::vector<MTriangle*>&);
    ~Rec2DCollapseTri();
    double getReward() {
      return std::max(_globValIfExecuted, _globValIfExecuted2)
                    - Recombine2D::getGlobalValue(0, .0, 0, .0);
    }
    bool isObsolete();
    void getRTriangles(std::set<Rec2DElement*> &tri) {
      tri.insert(_rtriangles[0]);
      tri.insert(_rtriangles[1]);
      if (_rtriangles[2]) {
        tri.insert(_rtriangles[2]);
        tri.insert(_rtriangles[3]);
      }
    }
    Rec2DElement* getRTriangle(int a) {
      return _rtriangles[a];
    }
    void apply();
    void getParities(int*);
    Rec2DVertex* getRVertex(int i) {return _vertices[i];}
    void color(int, int, int);
    virtual void whatImply(Rec2DVertex**, int*,
                           std::map<Rec2DVertex*, std::vector<int> >&)
    {return;}
    
    int getNum() {return 3;}
  private :
    void _computeGlobVal();
    void _qualCavity(double &valVert, double &valEdge, int &numEdge,
                     std::map<Rec2DVertex*, int> &vertices,
                     Rec2DVertex *imposedVert = NULL                );
};*/
//

class Rec2DListAction {
  private :
    
    
  public :
    
};

class Rec2DVertex {
  private :
    MVertex *_v;
    std::vector<Rec2DEdge*> _edges;
    std::vector<Rec2DElement*> _elements;
    int _onWhat, _numEl, _parity, _lastChange; //lastMove
    // _onWhat={-1:corner,0:edge,1:face,(2:volume)}
    double _angle, _qual;
    SPoint2 _param;
    
    static double **_qualVSnum;
    static double **_gains;
    
  public :
    Rec2DVertex(MVertex*, std::vector<MTriangle*>, int onWhat,
                std::map<MVertex*, std::set<GEdge*> >);
    Rec2DVertex(double u, double v);
    
    bool hasTriangle();
    inline void add(Rec2DEdge *re) {_edges.push_back(re);}
    void remove(Rec2DEdge*);
    inline void setOnBoundary() {if (_onWhat > 0) _onWhat = 0;
      static bool a=1; if(a){Msg::Warning("FIXME boundary");a=0;}}
    inline bool getIsOnBoundary() {return _onWhat < 1;}
    double getQual(int numEdge = -1);
    inline int getParity() {return _parity;}
    inline void setParity(int p) {
      _parity = p;
      Recombine2D::addVert2Par(this, p);
    }
    inline MVertex* getMVertex() {return _v;}
    void getxyz(double *xyz) {
      xyz[0] = _v->x(); xyz[1] = _v->y(); xyz[2] = _v->z();}
    inline double u() {return _param[0];}
    inline double v() {return _param[1];}
    inline void deleteMVertex() {delete _v;}
    
    double getGain(int);
    void getNeighbours(std::map<Rec2DVertex*, int>&, std::set<Rec2DEdge*>&);
    void getNeighbourEdges(std::set<Rec2DEdge*>&);
    void getElements(std::set<Rec2DElement*>&);
    
    void remove(Rec2DElement *rel) {
      std::vector<Rec2DElement*>::iterator it = _elements.begin();
      while (it != _elements.end()) {
        if (*it == rel)
          it = _elements.erase(it);
        else
          ++it;
      }
    }
    
    static void initStaticTable();
    
  private :
    void _computeQual();
    double _computeAngle(MVertex*, std::vector<MTriangle*>&, std::set<GEdge*>&);
};

class Rec2DEdge {
  private :
    Rec2DVertex *_rv1, *_rv2;
    double _qual;
    int _lastChange, _weight; //lastUpdate
    
  public :
    Rec2DEdge(MEdge, mapofVertices&, std::vector<MTriangle*>&);
    Rec2DEdge(Rec2DVertex*, Rec2DVertex*);
    
    double getQual();
    inline MEdge getMEdge() {return MEdge(_rv1->getMVertex(), _rv2->getMVertex());}
    inline Rec2DVertex* getRVertex(int i) {if (i) return _rv2; return _rv1;}
    int getWeight() {return _weight;}
    double getWeightedQual() {return _weight * _qual;}
    
  private :
    void _computeQual();
    double _straightAdimLength();
    double _straightAlignment();
};

class Rec2DElement {
  private :
    Rec2DEdge *_redges[4]; // if triangle, _redges[3] == NULL
    Rec2DElement *_relements[4]; // NULL if no neighbour
    MElement *_mEl; // can be NULL
    std::vector<Rec2DAction*> _actions;
    
  public :
    Rec2DElement(MTriangle *t) : _mEl((MElement *)t) {
      for (int i = 0; i < 4; ++i) {
        _redges[i] = NULL;
      }
    }
    
    void add(Rec2DEdge*);
    void add(Rec2DEdge*, Rec2DElement*);
    inline MElement* getMElement() {return _mEl;}
    inline MTriangle* getMTriangle()
      {if (_redges[3])return NULL; return (MTriangle*) _mEl;}
    inline bool isQuad() {return _redges[3];}
    inline void add(Rec2DAction *ra) {_actions.push_back(ra);}
    void remove(Rec2DAction *ra) {
      std::vector<Rec2DAction*>::iterator it = _actions.begin();
      while (it != _actions.end()) {
        if (*it == ra) it = _actions.erase(it);
        else ++it;
      }
    }
    inline int getNum() {return _mEl->getNum();}
    inline int getNumActions() {return _actions.size();}
    inline Rec2DAction* getAction(int i) {return _actions[i];}
    void getVertices(Rec2DVertex **v) {
      v[0] = _redges[0]->getRVertex(0);
      v[1] = _redges[0]->getRVertex(1);
      if (_redges[1]->getRVertex(0) == v[0] ||
          _redges[1]->getRVertex(0) == v[1]   )
        v[2] = _redges[1]->getRVertex(1);
      else
        v[2] = _redges[1]->getRVertex(0);
    }
    void getActions(std::set<Rec2DAction*> &actions) {
      for (unsigned int i = 0; i < _actions.size(); ++i)
        actions.insert(_actions[i]);
    }
    void getNeighbours(std::set<Rec2DElement*> &elem) {
      for (int i = 0; i < 4; ++i) {
        if (_relements[i])
          elem.insert(_relements[i]);
      }
    }
    Rec2DVertex* getOtherVertex(Rec2DVertex *rv1, Rec2DVertex *rv2) {
      if (_redges[3]) {
        Msg::Error("[Rec2DElement] I'm not a triangle");
        return NULL;
      }
      std::set<Rec2DVertex*> vert;
      for (int i = 0; i < 3; ++i) {
        vert.insert(_redges[i]->getRVertex(0));
        vert.insert(_redges[i]->getRVertex(1));
      }
      std::set<Rec2DVertex*>::iterator it = vert.begin();
      for (; it != vert.end(); ++it) {
        if (*it != rv1 && *it != rv2)
          return *it;
      }
      Msg::Error("[Rec2DElement] I should not be here... Why this happen to me ?");
      return NULL;
    }
};

#endif