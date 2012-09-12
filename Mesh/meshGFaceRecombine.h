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

#define REC2D_ONLY_RECO
#define REC2D_RECO_BLOS

#define REC2D_ALIGNMENT .5
#define REC2D_EDGE_BASE 2
#define REC2D_EDGE_QUAD 1
#define REC2D_VERT_TRIA 1
#define REC2D_VERT_QUAD 2

#ifdef REC2D_ONLY_RECO
  #define REC2D_NUMB_SONS 20
  #define REC2D_VERT_ONLY
  #define REC2D_COEF_ANGL 1.
  #define REC2D_COEF_DEGR .0
  #define REC2D_COEF_ANDE .0
  #define REC2D_COEF_ORIE .0
  #define REC2D_COEF_LENG .0
  #define REC2D_COEF_ORLE .0
#else
  #define REC2D_NUMB_SONS 6
  #define REC2D_VERT_ONLY
  #define REC2D_COEF_ANGL .0
  #define REC2D_COEF_DEGR .5
  #define REC2D_COEF_ANDE (1. - REC2D_COEF_ANGL - REC2D_COEF_DEGR)
  #define REC2D_COEF_ORIE .0
  #define REC2D_COEF_LENG .5
  #define REC2D_COEF_ORLE .5 //(1. - REC2D_COEF_ORIE - REC2D_COEF_LENG)
#endif

#include "GFace.h"
#include "BackgroundMesh.h"
//#include "GModel.h"
//#include "MEdge.h"
//#include "MQuadrangle.h"
  #include "meshGFaceOptimize.h"

class Rec2DNode;
class Rec2DVertex;
class Rec2DEdge;
class Rec2DElement;
class Rec2DAction;
class Rec2DData;
class Rec2DDataChange;
class Rec2DCollapse;
struct lessRec2DAction {
  bool operator()(const Rec2DAction*, const Rec2DAction*) const;
};
struct gterRec2DAction {
  bool operator()(const Rec2DAction*, const Rec2DAction*) const;
};

struct lessRec2DNode {
  bool operator()(Rec2DNode*, Rec2DNode*) const;
};
struct gterRec2DNode {
  bool operator()(Rec2DNode*, Rec2DNode*) const;
};
struct moreRec2DNode {
  bool operator()(Rec2DNode*, Rec2DNode*) const;
};

//

class Recombine2D {
  private :
    GFace *_gf;
    backgroundMesh *_bgm;
    Rec2DData *_data;
    static Recombine2D *_cur;
    
    int _strategy, _numChange;
#ifdef REC2D_RECO_BLOS
    int *elist;
    std::map<MElement*,int> t2n;
#endif
    
  public :
    Recombine2D(GFace*);
    ~Recombine2D();
    
    bool recombine();
    double recombine(int depth);
    void compareWithBlossom();
    bool developTree();
    int getNumTri() const;
    static void nextTreeActions(std::vector<Rec2DAction*>&,
                                const std::vector<Rec2DElement*> &neighbours,
                                const Rec2DNode *node = NULL);
    
    inline void setStrategy(int s) {_strategy = s;}
    void drawState(double shiftx, double shifty) const;
    static void drawStateCur(double dx, double dy) {_cur->drawState(dx, dy);}
    void printState() const;
    static void drawStateOrigin();
    
    static inline GFace* getGFace() {return _cur->_gf;}
    static inline int getNumChange() {return _cur->_numChange;}
    static inline void incNumChange() {++_cur->_numChange;}
    static inline backgroundMesh* bgm() {return _cur->_bgm;}
    static void add(MQuadrangle *q);
    static void add(MTriangle *t);
    
    static void clearChanges();
    static void colorFromBlossom(const Rec2DElement *tri1,
                                 const Rec2DElement *tri2,
                                 const Rec2DElement *quad );
    
  private :
    double _geomAngle(const MVertex*,
                      const std::vector<GEdge*>&,
                      const std::vector<MElement*>&) const;
};

//
class Rec2DData {
  private :
    class Action {
      public :
        const Rec2DAction *action;
        int position;
        Action(const Rec2DAction *ra, unsigned int pos)
          : action((Rec2DAction*)ra), position((int)pos) {}
    };
    template<class T> friend void std::swap(T&, T&);
    struct gterAction {
      bool operator()(const Action*, const Action*) const;
    };
    struct lessAction {
      bool operator()(const Action*, const Action*) const;
    };
    
  private :
    int _numEdge, _numVert;
    long double _valEdge, _valVert;
    static Rec2DData *_cur;
    int _remainingTri;
#ifdef REC2D_RECO_BLOS
    int _valQuad;
#endif
    
    std::vector<Rec2DEdge*> _edges;
    std::vector<Rec2DVertex*> _vertices;
    std::vector<Rec2DElement*> _elements;
    
    std::vector<Action*> _actions;
    std::vector<Rec2DAction*> _hiddenActions;
#ifdef REC2D_ONLY_RECO
    std::set<Rec2DElement*> _elementWithOneAction;
    std::set<Rec2DElement*> _elementWithZeroAction;
#endif
    std::vector<Rec2DNode*> _endNodes;
    std::vector<Rec2DDataChange*> _changes;
    
    std::map<int, std::vector<Rec2DVertex*> > _parities;
    std::map<Rec2DVertex*, int> _oldParity;
    
  public :
    Rec2DData();
    ~Rec2DData();
    
    static bool checkEntities();
    
    void printState() const;
    void printActions() const;
    static void printAction() {_cur->printActions();}
    //void sortActions() {sort(_actions.begin(), _actions.end(), gterAction());}
    void drawTriangles(double shiftx, double shifty) const;
    void drawElements(double shiftx, double shifty) const;
    void drawChanges(double shiftx, double shifty) const;
#ifdef REC2D_DRAW
    std::vector<MTriangle*> _tri;
    std::vector<MQuadrangle*> _quad;
#endif
    static inline int getNumTri() {return _cur->_remainingTri;}
    
    static inline int getNumEndNode() {return _cur->_endNodes.size();}
    static inline int getNumElement() {return _cur->_elements.size();}
    static Rec2DDataChange* getNewDataChange();
//#ifdef REC2D_ONLY_RECO
//    //static Rec2DDataChange* getCurrentDataChange() {return _cur->_changes.back();}
//#endif
    static bool revertDataChange(Rec2DDataChange*);
    static void clearChanges();
    static int getNumChanges() {return _cur->_changes.size();}
    void checkQuality() const;
    
    static double getGlobalQuality();
    static double getSumVert() {return _cur->_valVert;}
    static double getGlobalQuality(int numVert, double valVert,
                                   int numEdge = 0, double valEdge = .0);
    static inline void addVertQual(double val, int num = 0) {
      _cur->_numVert += num;
      _cur->_valVert += (long double)val;
    }
    static inline void addEdgeQual(double val, int num = 0) {
      _cur->_numEdge += num;
      _cur->_valEdge += (long double)val;
    }
#ifdef REC2D_RECO_BLOS    
    static inline void addQuadQual(int val) {
      _cur->_valQuad += val;
    }
#endif
    static inline int getNumEdge() {return _cur->_numEdge;}
    static inline double getValEdge() {return (double)_cur->_valEdge;}
    static inline int getNumVert() {return _cur->_numVert;}
    static inline double getValVert() {return (double)_cur->_valVert;}
    static Rec2DAction* getBestAction();
    static Rec2DAction* getRandomAction();
    static inline bool hasAction() {return _cur->_actions.size();}
    static void checkObsolete();
    
    typedef std::vector<Rec2DEdge*>::iterator iter_re;
    typedef std::vector<Rec2DVertex*>::iterator iter_rv;
    typedef std::vector<Rec2DElement*>::iterator iter_rel;
    static inline iter_re firstEdge() {return _cur->_edges.begin();}
    static inline iter_rv firstVertex() {return _cur->_vertices.begin();}
    static inline iter_rel firstElement() {return _cur->_elements.begin();}
    static inline iter_re lastEdge() {return _cur->_edges.end();}
    static inline iter_rv lastVertex() {return _cur->_vertices.end();}
    static inline iter_rel lastElement() {return _cur->_elements.end();}
    
    static void add(const Rec2DEdge*);
    static void add(const Rec2DVertex*);
    static void add(const Rec2DElement*);
    static void add(const Rec2DAction*);
    static inline void addHidden(const Rec2DAction *ra) {
      _cur->_hiddenActions.push_back((Rec2DAction*)ra);
    }
    static void rmv(const Rec2DEdge*);
    static void rmv(const Rec2DVertex*);
    static void rmv(const Rec2DElement*);
    static void rmv(const Rec2DAction*);
    static bool has(const Rec2DAction*);
#ifdef REC2D_ONLY_RECO
    static void addHasZeroAction(const Rec2DElement*);
    static void rmvHasZeroAction(const Rec2DElement*);
    static bool hasHasZeroAction(const Rec2DElement*);
    static int getNumZeroAction();
    static void addHasOneAction(const Rec2DElement*);
    static void rmvHasOneAction(const Rec2DElement*);
    static bool hasHasOneAction(const Rec2DElement*);
    static int getNumOneAction();
    static Rec2DAction* getOneAction();
    static void getUniqueOneActions(std::vector<Rec2DAction*>&);
#endif
    
    static void addEndNode(const Rec2DNode*);
    static void sortEndNode();
    static inline void drawEndNode(int num);
    
    static int getNewParity();
    static void removeParity(const Rec2DVertex*, int);
    static inline void addParity(const Rec2DVertex *rv, int p) {
      _cur->_parities[p].push_back((Rec2DVertex*)rv);
    }
    static void associateParity(int pOld, int pNew, Rec2DDataChange *rdc = NULL);
};

enum Rec2DChangeType {
  HideEdge, HideVertex, HideElement, //0-2
  CreatedEdge, CreatedVertex, CreatedElement, //3-5
  HideAction, HideActions, //6-7
  CreatedAction, CreatedActions, //8-9
  SwapVertInAction, SwapVertInEdge, //10-11
  SwapEdgeInAction, SwapEdgeInElem, //12-13
  RemoveElem, AddElem, Relocate, ChangePar, SavePar, //14-18
  SwapMVertInElement, ValQuad,
  Error, Reverted
};

class Rec2DChange {
  private : 
    Rec2DChangeType _type;
    void *_entity;
    void *_info;
  
  public :
    Rec2DChange() {Msg::Error("[Rec2DChange] I should not be created in this manner");}
    Rec2DChange(int);
    Rec2DChange(Rec2DEdge*, bool toHide = false);
    Rec2DChange(Rec2DVertex*, bool toHide = false);
    Rec2DChange(Rec2DElement*, bool toHide = false);
    Rec2DChange(Rec2DAction*, bool toHide = false);
    Rec2DChange(const std::vector<Rec2DAction*>&, bool toHide = false);
    Rec2DChange(Rec2DVertex*, int newParity, Rec2DChangeType);
    Rec2DChange(Rec2DVertex*, SPoint2 newCoord);
    Rec2DChange(const std::vector<Rec2DVertex*>&, Rec2DChangeType); // save Parity
    Rec2DChange(Rec2DVertex*, const std::vector<Rec2DElement*>&,
                Rec2DChangeType                                 ); // add or remove element in vertex
    Rec2DChange(Rec2DVertex*, Rec2DVertex*,
                const std::vector<Rec2DEdge*>&,
                Rec2DChangeType                ); // swap vertex1 to vertex2 (edge)
    Rec2DChange(Rec2DVertex*, Rec2DVertex*,
                const std::vector<Rec2DAction*>&,
                Rec2DChangeType                  ); // swap vertex1 to vertex2 (action)
    Rec2DChange(Rec2DVertex*, Rec2DVertex*,
                const std::vector<Rec2DElement*>&,
                Rec2DChangeType                  ); // swap mvertex1 to mvertex2 (element)
    Rec2DChange(Rec2DEdge*, Rec2DEdge*, Rec2DChangeType); // swap edge1 to edge2 (element)
    Rec2DChange(Rec2DEdge*, Rec2DEdge*,
                const std::vector<Rec2DAction*>&,
                Rec2DChangeType                  ); // swap edge1 to edge2 (action)
    
    void revert();
};

class Rec2DDataChange {
  private :
    std::vector<Rec2DChange*> _changes;
    Rec2DAction *_ra;
    
  public :
    ~Rec2DDataChange();
    
    inline void add(double d) {_changes.push_back(new Rec2DChange(d));}
    
    inline void hide(Rec2DEdge *re) {_changes.push_back(new Rec2DChange(re, 1));}
    inline void hide(Rec2DVertex *rv) {_changes.push_back(new Rec2DChange(rv, 1));} 
    inline void hide(Rec2DElement *rel) {_changes.push_back(new Rec2DChange(rel, 1));}
    inline void hide(Rec2DAction *ra) {_changes.push_back(new Rec2DChange(ra, 1));}
    inline void hide(std::vector<Rec2DAction*> &vect) {_changes.push_back(new Rec2DChange(vect, 1));}
    
    inline void append(Rec2DElement *rel) {_changes.push_back(new Rec2DChange(rel));}
    inline void append(Rec2DAction *ra) {_changes.push_back(new Rec2DChange(ra));}
    
    void swapFor(Rec2DEdge*, Rec2DEdge*);
    void swapFor(Rec2DVertex*, Rec2DVertex*);
    
    inline void relocate(Rec2DVertex *rv, const SPoint2 &p) {
      _changes.push_back(new Rec2DChange(rv, p));
    }
    inline void changeParity(Rec2DVertex *rv, int p) {
      _changes.push_back(new Rec2DChange(rv, p, ChangePar));
    }
    inline void saveParity(const std::vector<Rec2DVertex*> &verts) {
      _changes.push_back(new Rec2DChange(verts, SavePar));
    }
    void checkObsoleteActions(Rec2DVertex*const*, int size);
    
    void revert();
    
    void setAction(const Rec2DAction *action) {_ra = (Rec2DAction*)action;}
    Rec2DAction* getAction() const {return _ra;}
};

//
class Rec2DAction {
  protected :
    double _globQualIfExecuted, _reward;
    int _lastUpdate, _numPointing;
    
    void *_dataAction; // Rec2DData::Action*
    friend void Rec2DData::add(const Rec2DAction*);
    friend void Rec2DData::rmv(const Rec2DAction*);
    template<class T> friend void std::swap(T&, T&);
    
  public :
    Rec2DAction();
    virtual ~Rec2DAction() {}
    virtual void hide() = 0;
    static void hide(Rec2DAction*);
    virtual void reveal() = 0;
    virtual bool checkCoherence(const Rec2DAction *ra = NULL) const = 0;
    
    bool operator<(const Rec2DAction&) const;
    double getReward() const;
    double getRealReward() const;
    inline void *getDataAction() const {return _dataAction;}
    virtual void color(int, int, int) const = 0;
    virtual void apply(std::vector<Rec2DVertex*> &newPar) = 0;
    virtual void apply(Rec2DDataChange*, std::vector<Rec2DAction*>*&,
                       bool color = false) const = 0;
    virtual bool isObsolete() const = 0;
    virtual Rec2DVertex* getVertex(int) const = 0;
    virtual int getNumElement() = 0;
    virtual void getElements(std::vector<Rec2DElement*>&) const = 0;
    virtual void getNeighbourElements(std::vector<Rec2DElement*>&) const = 0;
    virtual void getNeighbElemWithActions(std::vector<Rec2DElement*>&) const = 0;
    virtual int getNum(double shiftx, double shifty) = 0;
    virtual Rec2DElement* getRandomElement() const = 0;
    virtual bool has(const Rec2DElement*) const = 0;
    //virtual void print() = 0;
    virtual bool haveElem() = 0;
    virtual Rec2DAction* getBase() const = 0;
    virtual Rec2DAction* getInfant() const = 0;
    static void removeDuplicate(std::vector<Rec2DAction*>&);
    virtual void swap(Rec2DVertex*, Rec2DVertex*) = 0;
    virtual void swap(Rec2DEdge*, Rec2DEdge*) = 0;
    virtual void printAdress() = 0;
    virtual void printReward() const = 0;
    virtual void printTypeRew() const = 0;
    virtual void printVertices() const = 0;
    inline void addPointing() {++_numPointing;}
    inline void rmvPointing() {--_numPointing;}
    //inline bool getPointing() {return _numPointing;}
    virtual void printIdentity() const = 0;
    
  private :
    virtual void _computeGlobQual() = 0;
    virtual void _computeReward() = 0;
};

class Rec2DTwoTri2Quad : public Rec2DAction {
  private :
    Rec2DElement *_triangles[2];
    Rec2DEdge *_edges[5]; // 4 boundary, 1 embedded
    Rec2DVertex *_vertices[4]; // 4 boundary (2 on embedded edge + 2)
    friend class Rec2DCollapse;
    Rec2DCollapse *_col;
    double _valVert;
#ifdef REC2D_RECO_BLOS
    RecombineTriangle *_rt;
#endif
    
  public :
    Rec2DTwoTri2Quad(Rec2DElement*, Rec2DElement*);
    ~Rec2DTwoTri2Quad() {}
    void operator delete(void*);
    virtual void hide();
    virtual void reveal();
    virtual bool checkCoherence(const Rec2DAction *ra = NULL) const;
    
    virtual void color(int, int, int) const;
    virtual void apply(std::vector<Rec2DVertex*> &newPar);
    virtual void apply(Rec2DDataChange*, std::vector<Rec2DAction*>*&,
                       bool color = false) const;
    
    virtual bool isObsolete() const;
    
    virtual inline Rec2DVertex* getVertex(int i) const {return _vertices[i];} //-
    virtual inline int getNumElement() {return 2;}
    virtual void getElements(std::vector<Rec2DElement*>&) const;
    virtual void getNeighbourElements(std::vector<Rec2DElement*>&) const;
    virtual void getNeighbElemWithActions(std::vector<Rec2DElement*>&) const;
    virtual int getNum(double shiftx, double shifty);
    virtual Rec2DElement* getRandomElement() const;
    virtual bool has(const Rec2DElement*) const;
    //virtual void print();
    virtual bool haveElem() {return true;}
    inline virtual Rec2DAction* getBase() const {return NULL;}
    inline virtual Rec2DAction* getInfant() const {return (Rec2DAction*)_col;}
    virtual void swap(Rec2DVertex*, Rec2DVertex*);
    virtual void swap(Rec2DEdge*, Rec2DEdge*);
    virtual void printAdress() {Msg::Info(" %d", this);}
    virtual void printReward() const;
    virtual void printTypeRew() const {Msg::Info("Recombine %g", _globQualIfExecuted);}
    virtual void printVertices() const;
    virtual void printIdentity() const;
    
  private :
    virtual void _computeGlobQual();
    virtual void _computeReward();
    void _doWhatYouHaveToDoWithParity(Rec2DDataChange*) const;
};

class Rec2DCollapse : public Rec2DAction {
  private :
    Rec2DTwoTri2Quad *_rec;
    //Rec2DElement **const&_triangles;
    //Rec2DEdge **const&_edges;
    //Rec2DVertex **const&_vertices;
    
  public :
    Rec2DCollapse(Rec2DTwoTri2Quad*);
    ~Rec2DCollapse() {}
    void operator delete(void*);
    virtual void hide();
    virtual void reveal();
    virtual bool checkCoherence(const Rec2DAction *ra = NULL) const {
      return _rec->checkCoherence(this);
    }
    
    virtual void color(int c1, int c2, int c3) const {_rec->color(c1, c2, c3);}
    virtual void apply(std::vector<Rec2DVertex*> &newPar);
    virtual void apply(Rec2DDataChange*, std::vector<Rec2DAction*>*&,
                       bool color = false) const;
    
    virtual bool isObsolete() const;
    
    virtual inline Rec2DVertex* getVertex(int i) const {
      return _rec->getVertex(i);
    }
    virtual inline int getNumElement() {return 2;}
    virtual void getElements(std::vector<Rec2DElement*> &vec) const {
      _rec->getElements(vec);
    }
    virtual void getNeighbourElements(std::vector<Rec2DElement*> &) const;
    virtual void getNeighbElemWithActions(std::vector<Rec2DElement*> &) const;
    virtual int getNum(double shiftx, double shifty) {return -1;}
    virtual inline Rec2DElement* getRandomElement() const {
      return _rec->getRandomElement();
    }
    virtual bool has(const Rec2DElement *rel) const {return _rec->has(rel);}
    //virtual void print();
    virtual bool haveElem() {return false;}
    inline virtual Rec2DAction* getBase() const {return _rec;}
    inline virtual Rec2DAction* getInfant() const {return NULL;}
    inline virtual void swap(Rec2DVertex *rv0, Rec2DVertex *rv1) {_rec->swap(rv0, rv1);}
    inline virtual void swap(Rec2DEdge *re0, Rec2DEdge *re1) {_rec->swap(re0, re1);}
    virtual void printAdress() {_rec->printAdress();}
    virtual void printReward() const;
    virtual void printTypeRew() const {Msg::Info("Collapse %g", _globQualIfExecuted);}
    virtual void printVertices() const {_rec->printVertices();}
    virtual void printIdentity() const;
    
  private :
    virtual void _computeGlobQual();
    virtual void _computeReward();
    bool _hasIdenticalElement() const;
};

//
class Rec2DEdge {
  private :
    Rec2DVertex *_rv0, *_rv1;
    double _qual;
    int _lastUpdate, _weight;
    
    int _pos;
    friend void Rec2DData::add(const Rec2DEdge*);
    friend void Rec2DData::rmv(const Rec2DEdge*);
    
  public :
    Rec2DEdge(Rec2DVertex*, Rec2DVertex*);
    ~Rec2DEdge() {if (_pos > -1) hide();}
    void hide();
    void reveal();
    bool checkCoherence() const;
    inline bool has(const Rec2DVertex *v) const {return v == _rv0 || v == _rv1;}
    
    inline double getQual() const {return _qual;}
    inline int getWeight() const {return _weight;}
    inline double getWeightedQual() const {return _weight * _qual;}
    void updateQual();
    void print() const;
    
    inline void addHasTri() {_addWeight(-REC2D_EDGE_QUAD);}
    inline void remHasTri() {_addWeight(REC2D_EDGE_QUAD);}
    //inline void addHasQuad() {}
    //inline void remHasQuad() {}
    inline bool isOnBoundary() const;
    
    inline Rec2DVertex* getVertex(int i) const {if (i) return _rv1; return _rv0;}
    Rec2DVertex* getOtherVertex(const Rec2DVertex*) const;
    static Rec2DElement* getTheOnlyElement(const Rec2DEdge*);
    static void getElements(const Rec2DEdge*, Rec2DElement**);
    //void getUniqueActions(std::vector<Rec2DAction*>&) const;
    
    void swap(Rec2DVertex *oldRV, Rec2DVertex *newRV, bool upVert = true);
    
  private :
    void _computeQual();
    double _straightAdimLength() const;
    double _straightAlignment() const;
    void _addWeight(int);
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
    int _onWhat; // _onWhat={-1:corner,0:edge,1:face}
    int _parity, _lastUpdate;
    double _sumQualAngle;
    std::vector<Rec2DEdge*> _edges;
    std::vector<Rec2DElement*> _elements;
    SPoint2 _param;
    int _pos;
#ifdef REC2D_VERT_ONLY
    double _sumQualEdge;
    int _sumEdge, _sumAngle;
#endif
    friend void Rec2DData::add(const Rec2DVertex*);
    friend void Rec2DData::rmv(const Rec2DVertex*);
    
    static double **_qualVSnum;
    static double **_gains;
    
  public :
    Rec2DVertex(MVertex*);
    Rec2DVertex(Rec2DVertex*, double angle);
    ~Rec2DVertex() {if (_pos > -1) hide();}
    void hide();
    void reveal();
    bool checkCoherence() const;
    
    inline int getNum() const {return _v->getNum();}
    inline double getGeomAngle() const {return _angle;}
#ifndef REC2D_VERT_ONLY
    inline double getQualAngle() const {return _sumQualAngle/_elements.size();}
#endif
    double getQualDegree(int numEl = -1) const;
    double getGainDegree(int) const;
#ifdef REC2D_VERT_ONLY
    double getQual() const;
    void printQual() const;
    double getQual(int numAngl, double valAngl,
                   int numEdge, double valEdge, int numElem) const;
    double getGainQuad(const Rec2DElement*,
                       const Rec2DEdge*, const Rec2DEdge*) const;
    double getGainTriLess(const Rec2DEdge*) const;
    double getGainRecomb(const Rec2DElement*, const Rec2DElement*,
                         const Rec2DEdge*, const Rec2DEdge*,
                         const Rec2DEdge*                         ) const;
    void addEdgeQual(double val, int num = 0);
    double getGainMerge(const Rec2DVertex*, const Rec2DEdge*const*, int) const;
#else
    inline double getQual() const {return getQualDegree() + getQualAngle();}
    double getGainOneElemLess() const;
    double getGainRecomb(const Rec2DElement*, const Rec2DElement*) const;
    double getGainMerge(const Rec2DVertex*) const;
#endif
    
    inline void setOnBoundary();
    inline bool getOnBoundary() const {return _onWhat < 1;}
    bool setBoundaryParity(int p0, int p1);
    
    inline int getParity() const {return _parity;}
    void setParity(int, bool tree = false);
    void setParityWD(int pOld, int pNew);
    
    inline int getNumElements() const {return _elements.size();}
    inline void getEdges(std::vector<Rec2DEdge*> &v) const {v = _edges;}
    void getMoreUniqueEdges(std::vector<Rec2DEdge*>&) const;
    void getMoreNeighbourVertices(std::vector<Rec2DVertex*>&) const;
    //void getMoreTriangles(std::set<Rec2DElement*>&) const;
    inline void getElements(std::vector<Rec2DElement*> &v) const {v = _elements;}
    inline MVertex* getMVertex() const {return _v;}
    
    inline int getLastUpdate() const {return _lastUpdate;}
    inline void getxyz(double *xyz) const {
      xyz[0] = _v->x();
      xyz[1] = _v->y();
      xyz[2] = _v->z();
    }
    inline double u() const {return _param[0];}
    inline double v() const {return _param[1];}
    void relocate(SPoint2 p);
    //inline SPoint2 getParam() {return _param;}
    inline void getParam(SPoint2 *p) {*p = _param;}
    
    void add(const Rec2DEdge*);
    bool has(const Rec2DEdge*) const;
    void rmv(const Rec2DEdge*);
    
    void add(const Rec2DElement*);
    bool has(const Rec2DElement*) const;
    void rmv(const Rec2DElement*);
    
    void printElem() const;
    
    void getMoreUniqueActions(std::vector<Rec2DAction*>&) const;
    
    static void initStaticTable();
    static Rec2DEdge* getCommonEdge(const Rec2DVertex*, const Rec2DVertex*);
    static void getCommonElements(const Rec2DVertex*, const Rec2DVertex*,
                                  std::vector<Rec2DElement*>&            );
    
  private :
    //inline double _getQualAngle() const {return _sumQualAngle/_elements.size();}
    bool _recursiveBoundParity(const Rec2DVertex *prev, int p0, int p1);
    void _updateQualAngle();
    inline double _angle2Qual(double ang) const {
      return std::max(1. - fabs(ang*2./M_PI - 1.), .0); 
    }
};

class Rec2DElement {
  private :
    MElement *_mEl;       // can be NULL
    int _numEdge;
    Rec2DEdge *_edges[4];
    Rec2DElement *_elements[4];  // NULL if no neighbour
    std::vector<Rec2DAction*> _actions;
    
    int _pos;
    friend void Rec2DData::add(const Rec2DElement*);
    friend void Rec2DData::rmv(const Rec2DElement*);
    
  public :
    Rec2DElement(MTriangle*, const Rec2DEdge**, Rec2DVertex **rv = NULL);
    Rec2DElement(MQuadrangle*, const Rec2DEdge**, Rec2DVertex **rv = NULL);
    ~Rec2DElement() {if (_pos > -1) hide();}
    void hide();
    void reveal(Rec2DVertex **rv = NULL);
    bool checkCoherence() const;
    bool has(const Rec2DVertex*) const;
    bool has(const Rec2DElement*) const;
    void print() const;
    
    inline bool isTri() const {return _numEdge == 3;}
    inline bool isQuad() const {return _numEdge == 4;}
    
    void add(Rec2DEdge*);
    bool has(const Rec2DEdge*) const;
    void add(const Rec2DAction*);
    bool has(const Rec2DAction*) const;
    void rmv(const Rec2DAction*);
    void addNeighbour(const Rec2DEdge*, const Rec2DElement*);
    void rmvNeighbour(const Rec2DEdge*, const Rec2DElement*);
    bool isNeighbour(const Rec2DEdge*, const Rec2DElement*) const;
    
    void swap(Rec2DEdge*, Rec2DEdge*);
    void swapMVertex(Rec2DVertex*, Rec2DVertex*);
    
    inline MElement* getMElement() const {return _mEl;}
#ifdef REC2D_DRAW
    MTriangle* getMTriangle() const {
      if (_numEdge == 3) {
        if (_mEl)
          return (MTriangle*) _mEl;
        else
          Msg::Error("[Rec2DElement] Do you thing I'll create a triangle for you ?");
      }
      return NULL;
    }
    MQuadrangle* getMQuadrangle() const {
      if (_numEdge == 4) {
        if (!_mEl)
          ((Rec2DElement*)this)->_mEl = (MElement*) _createQuad();
        return (MQuadrangle*) _mEl;
      }
      return NULL;
    }
#endif
    void createElement(double shiftx, double shifty) const;
    
    double getAngle(const Rec2DVertex*) const;
#ifdef REC2D_VERT_ONLY
    int getAngleNb() const {
      return _numEdge > 3 ? REC2D_VERT_QUAD : REC2D_VERT_TRIA;
    }
#endif
    
    inline int getNumActions() const {return _actions.size();}
    inline Rec2DAction* getAction(int i) const {return _actions[i];}
    inline void getActions(std::vector<Rec2DAction*> &v) const {v = _actions;};
    void getMoreUniqueActions(std::vector<Rec2DAction*>&) const;
    inline void getMoreEdges(std::vector<Rec2DEdge*> &v) const {
      v.insert(v.end(), _edges, _edges + _numEdge);
    }
    void getVertices(std::vector<Rec2DVertex*>&) const;
    void getMoreNeighbours(std::vector<Rec2DElement*>&) const;
    Rec2DVertex* getOtherVertex(const Rec2DVertex*, const Rec2DVertex*) const;
    static Rec2DEdge* getCommonEdge(const Rec2DElement*, const Rec2DElement*);
    static void getElements(const Rec2DEdge*, Rec2DElement**);
    bool hasIdenticalNeighbour() const;
    
    inline int getNum() const {return _mEl->getNum();}
    
  private :
    MQuadrangle* _createQuad() const;
};

//
static void _small_crash() {
  Msg::Info(" ");
  Recombine2D::drawStateOrigin();
  int a[2];
  int e = 0;
  for (int i = 0; i < 10000000; ++i) e+=a[i];
  Msg::Info("%d",e);
}

class Rec2DNode {
  private :
    Rec2DNode *_father;
    Rec2DNode *_son[REC2D_NUMB_SONS];
    Rec2DAction *_ra;
    Rec2DDataChange *_dataChange;
    int _d, _remainingTri;
    // seq = from son to end of horizon
    double _reward, _globalQuality, _bestSeqReward, _expectedSeqReward;
    std::vector<Rec2DAction*> *_createdActions;
#ifdef REC2D_ONLY_RECO
    bool _notAllQuad;
#endif
    
  public :
    Rec2DNode(Rec2DNode *father, Rec2DAction*, int depth = -1);
    ~Rec2DNode();
    bool canBeDeleted() const;
    
    Rec2DNode* selectBestNode();
    void recoverSequence();
    void lookahead(int depth);
    inline bool hasSon() const {return _son[0];}
    void rmvFather(Rec2DNode *n);
    bool rmvSon(Rec2DNode *n);
    bool hasSon(Rec2DNode *n) {
      if (!n) return false;
      int i = -1;
      while (++i < REC2D_NUMB_SONS && _son[i] != n);
      return i < REC2D_NUMB_SONS;
    }
    bool makeChanges();
    bool revertChanges();
    void printSequence() const;
    inline bool isInSequence() const {return _father && _father->_d != _d;}
#ifdef REC2D_ONLY_RECO
    inline bool isNotAllQuad() const {return _notAllQuad;}
#endif
    inline double getExpectedSeqReward() {return _reward + _expectedSeqReward;}
    inline double getBestSequenceReward() {return _reward + _bestSeqReward;}
    
    bool operator<(Rec2DNode&);
    inline Rec2DNode* getFather() const {return _father;}
    inline Rec2DAction* getAction() const {return _ra;}
    inline double getGlobQual() const {return _globalQuality + _reward;}
    inline double getReward() const {return _reward;}
    inline int getNumTri() const {return _remainingTri;}
    
    void checkLinks() {
      if (!_father->hasSon(this)) _small_crash();
      for (int i = 0; i < REC2D_NUMB_SONS; ++i) {
        if (_son[i]) {
          if (_son[i]->getFather() != this) _small_crash();
        }
      }
    }
    
    void draw(double dx, double dy) {
      if (_father)
        _father->_mkChgSinceBeginning();
      if (_dataChange) Msg::Error("_Ber_");
      _dataChange = Rec2DData::getNewDataChange();
      _ra->apply(_dataChange, _createdActions);
      _dataChange = NULL;
      Recombine2D::drawStateCur(dx, dy);
    }
    
  private :
    void _mkChgSinceBeginning() {
      if (_father)
        _father->_mkChgSinceBeginning();
      else if (!_ra) return;
      if (_dataChange) Msg::Error("_Ber_");
      _dataChange = Rec2DData::getNewDataChange();
      _ra->apply(_dataChange, _createdActions);
      _dataChange = NULL;
      static int a = -1;
      if (++a < 1) Msg::Warning("FIXME pas propre du tout");
    }
    void _makeDevelopments(int depth);
    void _createSons(const std::vector<Rec2DAction*>&, int depth);
    void _develop(int depth);
};

class NODES {
  private :
    std::set<Rec2DNode*> nodes;
    static NODES *c;
    
  public :
    NODES() {}
    static void add(Rec2DNode *n) {
      std::pair<std::set<Rec2DNode*>::iterator, bool> rep;
      rep = c->nodes.insert(n);
      if (!rep.second) _small_crash();
    }
    static void rmv(Rec2DNode *n) {
      int rep;
      rep = c->nodes.erase(n);
      if (!rep) _small_crash();
      //Msg::Info("%d", c->nodes.size());
    }
    static void check() {
      std::set<Rec2DNode*>::iterator it = c->nodes.begin();
      while (it != c->nodes.end()) {
        (*it)->checkLinks();
      }
    }
    static void newNODES() {
      if (c) _small_crash();
      c = new NODES();
    }
};
#endif




















































