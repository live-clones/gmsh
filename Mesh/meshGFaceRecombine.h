// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#ifndef _MESH_GFACE_RECOMBINE_H_
#define _MESH_GFACE_RECOMBINE_H_

#define REC2D_EDGE_BASE 2
#define REC2D_EDGE_QUAD 1
#define REC2D_ALIGNMENT .5

#include "GFace.h"
#include "BackgroundMesh.h"
//#include "GModel.h"
//#include "MEdge.h"
#include "MQuadrangle.h"

class Rec2DNode;
class Rec2DVertex;
class Rec2DEdge;
class Rec2DElement;
class Rec2DAction;
class Rec2DData;
struct lessRec2DNode {
  bool operator()(Rec2DNode*, Rec2DNode*) const;
};
struct greaterRec2DNode {
  bool operator()(Rec2DNode*, Rec2DNode*) const;
};
struct moreRec2DNode {
  bool operator()(Rec2DNode*, Rec2DNode*) const;
};

//typedef std::list<Rec2DAction*> setofRec2DAction;
//typedef std::map<MVertex*, Rec2DVertex*> mapofVertices;
//typedef std::map<MEdge, Rec2DEdge*, Less_Edge> mapofEdges;
//typedef std::map<MElement*, Rec2DElement*> mapofElements;
//typedef std::map<MElement*, std::set<Rec2DAction*> > mapofElementActions;
//typedef std::map<MQuadrangle*, std::set<MElement*> > mapofAdjacencies;

class Recombine2D {
  private :
    GFace *_gf;
    backgroundMesh *_bgm;
    Rec2DData *_data;
    static Recombine2D *_current;
    
    int _numChange;
    
  public :
    Recombine2D(GFace*);
    ~Recombine2D();
    
    bool recombine();
    bool developTree();
    static void nextTreeActions(Rec2DAction*, std::vector<Rec2DAction*>&);
    
    static inline GFace* getGFace() {return _current->_gf;}
    static inline int getNumChange() {return _current->_numChange;}
    static inline backgroundMesh* bgm() {return _current->_bgm;}
    static void add(MQuadrangle *q) {_current->_gf->quadrangles.push_back(q);}
    
  private :
    double _geomAngle(MVertex*,
                      std::vector<GEdge*>&,
                      std::vector<MElement*>&);
    bool _remainAllQuad(Rec2DAction *action);
    bool _remainAllQuad(std::set<Rec2DElement*>&);
};

class Rec2DData {
  private :
    int _numEdge, _numVert;
    long double _valEdge, _valVert;
    static Rec2DData *_current;
    
    std::set<Rec2DEdge*> _edges;
    std::set<Rec2DVertex*> _vertices;
    std::set<Rec2DElement*> _elements, _hiddenElements;
    
    std::list<Rec2DAction*> _actions;
    std::vector<Rec2DNode*> _endNodes;
    
    std::map<int, std::vector<Rec2DVertex*> > _parities;
    std::map<int, std::vector<Rec2DVertex*> > _assumedParities;
    std::map<Rec2DVertex*, int> _oldParity;
    
  public :
    Rec2DData();
    ~Rec2DData();
    
    void printState();
#ifdef REC2D_DRAW
    std::vector<MTriangle*> _tri;
    std::vector<MQuadrangle*> _quad;
#endif
    
    static int getNumEndNode() {return _current->_endNodes.size();}
    static int getNumElement() {return _current->_elements.size();}
    
    static double getGlobalValue();
    static double getGlobalValue(int numEdge, double valEdge,
                                 int numVert, double valVert );
    static inline void addVert(int num, double val) {
      _current->_numVert += num;
      _current->_valVert += (long double)val;
    }
    static inline void addValVert(double val) {
      _current->_valVert += (long double)val;
    }
    static inline void addEdge(int num, double val) {
      _current->_numEdge += num;
      _current->_valEdge += (long double)val;
    }
    
    static Rec2DAction* getBestAction();
    static Rec2DAction* getBestNonHiddenAction();
    
    typedef std::set<Rec2DEdge*>::iterator iter_re;
    typedef std::set<Rec2DVertex*>::iterator iter_rv;
    typedef std::set<Rec2DElement*>::iterator iter_rel;
    static inline iter_re firstEdge() {return _current->_edges.begin();}
    static inline iter_rv firstVertex() {return _current->_vertices.begin();}
    static inline iter_rel firstElement() {return _current->_elements.begin();}
    static inline iter_re lastEdge() {return _current->_edges.end();}
    static inline iter_rv lastVertex() {return _current->_vertices.end();}
    static inline iter_rel lastElement() {return _current->_elements.end();}
    
    static inline void add(Rec2DEdge *re) {_current->_edges.insert(re);}
    static inline void add(Rec2DVertex *rv) {_current->_vertices.insert(rv);}
#ifndef REC2D_DRAW
    static inline void add(Rec2DElement *rel) {_current->_elements.insert(rel);}
#else
    static void add(Rec2DElement *rel);
#endif
    static inline void add(Rec2DAction *ra) {_current->_actions.push_back(ra);}
    static void remove(Rec2DEdge*);
    static void remove(Rec2DVertex*);
    static void remove(Rec2DElement*);
    static void remove(Rec2DAction*);
    
    static inline void addEndNode(Rec2DNode *rn) {
      _current->_endNodes.push_back(rn);
    }
    static void sortEndNode();
    static inline void drawEndNode(int num);
    static inline void addHidden(Rec2DElement *rel) {
      _current->_hiddenElements.insert(rel);
    }
    static inline void remHidden(Rec2DElement *rel) {
      _current->_hiddenElements.erase(rel);
    }
    static bool isOutOfDate(Rec2DAction*);
    
    static int getNewParity();
    static void removeParity(Rec2DVertex*, int);
    static inline void addParity(Rec2DVertex *rv, int p) {
      _current->_parities[p].push_back(rv);
    }
    static void associateParity(int pOld, int pNew);
    static void removeAssumedParity(Rec2DVertex*, int);
    static inline void addAssumedParity(Rec2DVertex *rv, int p) {
      _current->_assumedParities[p].push_back(rv);
    }
    static void saveAssumedParity(Rec2DVertex*, int);
    static void associateAssumedParity(int pOld, int pNew,
                                       std::vector<Rec2DVertex*>&);
    static inline void clearAssumedParities() {_current->_oldParity.clear();}
    static void revertAssumedParities();
};

struct lessRec2DAction {
  bool operator()(Rec2DAction*, Rec2DAction*) const;
};

class Rec2DAction {
  protected :
    double _globValIfExecuted;
    int _lastUpdate;
    
  public :
    virtual inline ~Rec2DAction() {Rec2DData::remove(this);}
    
    bool operator<(Rec2DAction&);
    virtual double getReward();
    virtual void color(int, int, int) = 0;
    virtual void apply(std::vector<Rec2DVertex*> &newPar) = 0;
    virtual bool isObsolete() = 0;
    virtual bool isAssumedObsolete() = 0;
    virtual void getAssumedParities(int*) = 0;
    virtual bool whatWouldYouDo(std::map<Rec2DVertex*, std::vector<int> >&) = 0;
    virtual Rec2DVertex* getVertex(int) = 0;
    virtual void choose(Rec2DElement*&) = 0;
    virtual void unChoose(Rec2DElement*) = 0;
    virtual inline int getNumElement() = 0;
    virtual void getElements(std::vector<Rec2DElement*>&) = 0;
    virtual int getNum() = 0;
    
  private :
    virtual void _computeGlobVal() = 0;
};

class Rec2DTwoTri2Quad : public Rec2DAction {
  private :
    Rec2DElement *_triangles[2];
    Rec2DEdge *_edges[5]; // 4 boundary, 1 embedded
    Rec2DVertex *_vertices[4]; // 4 boundary (2 on embedded edge + 2)
    
  public :
    Rec2DTwoTri2Quad(Rec2DElement*, Rec2DElement*);
    ~Rec2DTwoTri2Quad();
    
    virtual void color(int, int, int);
    virtual void apply(std::vector<Rec2DVertex*> &newPar);
    virtual bool isObsolete();
    virtual bool isAssumedObsolete();
    static bool isObsolete(int*);
    virtual void getAssumedParities(int*);
    virtual bool whatWouldYouDo(std::map<Rec2DVertex*, std::vector<int> >&);
    virtual inline Rec2DVertex* getVertex(int i) {return _vertices[i];} //-
    virtual void choose(Rec2DElement*&);
    virtual void unChoose(Rec2DElement*);
    virtual inline int getNumElement() {return 2;}
    virtual void getElements(std::vector<Rec2DElement*>&);
    virtual int getNum();
    
  private :
    virtual void _computeGlobVal();
};

class Rec2DEdge {
  private :
    Rec2DVertex *_rv0, *_rv1;
    double _qual;
    int _lastUpdate, _weight;
    int _boundary; // pourrait faire sans !
    
  public :
    Rec2DEdge(Rec2DVertex*, Rec2DVertex*);
    ~Rec2DEdge();
    void hide();
    void reveal();
    
    double getQual();
    
    inline double addHasTri() {_addWeight(-REC2D_EDGE_QUAD); ++_boundary;}
    inline double remHasTri() {_addWeight(REC2D_EDGE_QUAD); --_boundary;}
    inline double addHasQuad() {++_boundary;}
    inline double remHasQuad() {--_boundary;}
    inline bool isOnBoundary() const {return !_boundary;}
    
    inline Rec2DVertex* getVertex(int i) const {if (i) return _rv1; return _rv0;}
    Rec2DVertex* getOtherVertex(Rec2DVertex*) const;
    static Rec2DElement* getSingleElement(Rec2DEdge*);
    
    void swap(Rec2DVertex *oldRV, Rec2DVertex *newRV);
    
  private :
    void _computeQual();
    double _straightAdimLength() const;
    double _straightAlignment() const;
    void _addWeight(double);
};

struct AngleData {
  std::vector<GEdge*> _gEdges;
  std::vector<MElement*> _mElements;
  Rec2DVertex *_rv;
  
  AngleData() : _rv(NULL) {} 
};

class Rec2DVertex {
  private :
    MVertex *_v;
    const double _angle;
    std::vector<Rec2DEdge*> _edges;
    std::vector<Rec2DElement*> _elements;
    int _lastMove, _onWhat; // _onWhat={-1:corner,0:edge,1:face}
    int _parity, _assumedParity;
    SPoint2 _param;
    bool _isMesh;
    
    static double **_qualVSnum;
    static double **_gains;
    
  public :
    Rec2DVertex(MVertex*, bool toSave = true);
    Rec2DVertex(Rec2DVertex*, double angle);
    ~Rec2DVertex();
    
    double getQual(int numEl = -1) const;
    double getGain(int) const;
    
    inline void setOnBoundary();
    inline bool getOnBoundary() const {return _onWhat < 1;}
    bool setBoundaryParity(int p0, int p1);
    
    inline int getParity() const {return _parity;}
    void setParity(int, bool tree = false);
    void setParityWD(int pOld, int pNew);
    int getAssumedParity() const;
    bool setAssumedParity(int);
    void setAssumedParityWD(int pOld, int pNew);
    void revertAssumedParity(int);
    
    inline int getNumElements() const {return _elements.size();}
    void getTriangles(std::set<Rec2DElement*>&);
    inline MVertex* getMVertex() const {return _v;}
    
    inline int getLastMove() const {return _lastMove;}
    inline void getxyz(double *xyz) const {
      xyz[0] = _v->x();
      xyz[1] = _v->y();
      xyz[2] = _v->z();
    }
    inline double u() const {return _param[0];}
    inline double v() const {return _param[1];}
    
    void add(Rec2DEdge*);
    bool has(Rec2DEdge*) const;
    void remove(Rec2DEdge*);
    
    void add(Rec2DElement*);
    bool has(Rec2DElement*) const;
    void remove(Rec2DElement*);
    
    static void initStaticTable();
    static Rec2DEdge* getCommonEdge(Rec2DVertex*, Rec2DVertex*);
    static void getCommonElements(Rec2DVertex*, Rec2DVertex*,
                                  std::vector<Rec2DElement*>&);
    
  private :
    bool _recursiveBoundParity(Rec2DVertex *prev, int p0, int p1);
};

class Rec2DElement {
  private :
    int _numEdge;
    Rec2DEdge *_edges[4];
    Rec2DElement *_elements[4];  // NULL if no neighbour
    MElement *_mEl;       // can be NULL
    std::vector<Rec2DAction*> _actions;
    
  public :
    Rec2DElement(MTriangle*);
    Rec2DElement(MQuadrangle*);
    Rec2DElement(Rec2DEdge**, bool tree = false);
    ~Rec2DElement();
    void hide();
    void reveal();
    
    bool inline isTri() {return _numEdge == 3;}
    bool inline isQuad() {return _numEdge == 4;}
    
    void add(Rec2DEdge*);
    bool has(Rec2DEdge*) const;
    void add(Rec2DAction*);
    void remove(Rec2DAction*);
    void addNeighbour(Rec2DEdge*, Rec2DElement*);
    void removeNeighbour(Rec2DEdge*, Rec2DElement*);
    
    inline MElement* getMElement() const {return _mEl;}
#ifdef REC2D_DRAW
    MTriangle* getMTriangle() {
      if (_numEdge == 3) {
        if (_mEl)
          return (MTriangle*) _mEl;
        else
          Msg::Error("[Rec2DElement] Do you thing I'll create a triangle for you ?");
      }
      return NULL;
    }
    MQuadrangle* getMQuadrangle() {
      if (_numEdge == 4) {
        if (!_mEl)
          _mEl = (MElement*) _createQuad();
        return (MQuadrangle*) _mEl;
      }
      return NULL;
    }
#endif
    
    inline int getNumActions() const {return _actions.size();}
    inline Rec2DAction* getAction(int i) const {return _actions[i];}
    void getUniqueActions(std::vector<Rec2DAction*>&) const;
    void getAssumedParities(int*) const;
    void getMoreEdges(std::vector<Rec2DEdge*>&) const;
    void getVertices(std::vector<Rec2DVertex*>&) const;
    Rec2DVertex* getOtherVertex(Rec2DVertex*, Rec2DVertex*) const;
    static Rec2DEdge* getCommonEdge(Rec2DElement*, Rec2DElement*);
    
  private :
    MQuadrangle* _createQuad() const;
};


class Rec2DNode {
  private :
    Rec2DNode *_father;
    Rec2DNode *_son[3];
    Rec2DAction *_ra;
    double _globalValue, _bestEndGlobVal;
    int _remainingTri;
    
  public :
    Rec2DNode(Rec2DNode *father, Rec2DAction*, double &bestEndGlobVal);
    
    bool operator<(Rec2DNode&);
    inline Rec2DNode* getFather() {return _father;}
    inline int getNum() {return _ra->getNum();}
    inline Rec2DAction* getAction() {return _ra;}
    inline double getGlobVal() {return _globalValue;}
    inline int getNumTri() {return _remainingTri;}
};

#endif