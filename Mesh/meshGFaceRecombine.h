// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Amaury Johnen (a.johnen@ulg.ac.be)
//

#ifndef _MESH_GFACE_RECOMBINE_H_
#define _MESH_GFACE_RECOMBINE_H_

#define REC2D_RECO_BLOS
#define REC2D_NUMB_SONS 20

#ifdef REC2D_ONLY_RECO
  #define REC2D_VERT_ONLY
  #define REC2D_COEF_ANGL 1.
  #define REC2D_COEF_DEGR .0
  #define REC2D_COEF_ANDE .0
  #define REC2D_COEF_ORIE .5
  #define REC2D_COEF_LENG .5
  #define REC2D_COEF_ORLE .0
#else
  #define REC2D_VERT_ONLY
  #define REC2D_COEF_ANGL .0
  #define REC2D_COEF_DEGR .5
  #define REC2D_COEF_ANDE (1. - REC2D_COEF_ANGL - REC2D_COEF_DEGR)
  #define REC2D_COEF_ORIE .0
  #define REC2D_COEF_LENG .5
  #define REC2D_COEF_ORLE .5 //(1. - REC2D_COEF_ORIE - REC2D_COEF_LENG)
#endif

#define REC2D_BIG_NUMB 1e10

#include "GFace.h"
#include "BackgroundMesh.h"
//#include "GModel.h"
//#include "MEdge.h"
//#include "MQuadrangle.h"
#ifdef REC2D_RECO_BLOS
  #include "meshGFaceOptimize.h"
#endif
#include <fstream>
#include <vector>


class Rec2DNode;
class Rec2DVertex;
class Rec2DEdge;
class Rec2DElement;
class Rec2DAction;
class Rec2DTwoTri2Quad;
class Rec2DCollapse;
class Rec2DData;
class Rec2DDataChange;

template<typename T>
class Rec2DContainer {
private:
  std::vector<T> _vec;
  std::set<T> _set;

public:
  int add(T);
  int rmv(T);
  T getRandom();
};

namespace Rec2DAlgo {
  bool setParam(int horizon, int code);
  void clear();
  namespace func {
    Rec2DAction* getBestNAction();
    Rec2DAction* getRandomNAction();
    Rec2DAction* getBestOAction();
    Rec2DAction* getRandomOAction();
  }
  class Node;
}

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

enum Rec2DQualCrit {
  NoCrit = -2,
  ChoosedCrit = -1,
  BlossomQuality = 0,
  VertQuality = 1,
  VertEdgeQuality = 2
};

//
class Recombine2D {
  private :
    GFace *_gf;
    Rec2DData *_data;
    backgroundMesh *_bgm;
    static Recombine2D *_cur;
    int _numChange;
    double _lastRunTime;
    Rec2DNode *_curNode;

    // Parameter :
    const bool _collapses;
    int _strategy, _horizon;
    Rec2DQualCrit _qualCriterion;

    bool _checkIfNotAllQuad; // Check if action implies triangle isolation
    bool _avoidIfNotAllQuad; // Don't apply action if it implies triangle isolation
    bool _revertIfNotAllQuad; // Be all quad at any price (can it be not totally unefficient ?)
    bool _oneActionHavePriority; // Tracks and prioritises elements with 1 action
    bool _noProblemIfObsolete; // For recombineSameAsHeuristic

    int _weightEdgeBase;
    int _weightEdgeQuad;
    int _weightAngleTri;
    int _weightAngleQuad;
    float _coefAngleQual;
    float _coefDegreeQual;
    float _coefLengthQual;
    float _coefOrientQual;

#ifdef REC2D_RECO_BLOS
    bool _recombineWithBlossom;
    int _blossomTime;
    bool _saveBlossomMesh;
    int *elist;
    std::map<MElement*, int> t2n;
#endif

  public :

    static double t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;

    Recombine2D(GFace*, bool collapses);
    ~Recombine2D();

    // Construct data
    bool construct();

    // Recombination methods
    bool recombine();
    bool recombineNewAlgo(int horiz = -1, int code = -1);
    bool recombineSimpleAlgo(int horiz = -1);
    bool recombineComplete(int horiz = -1);
    double recombine(int depth);
    void recombineSameAsBlossom(); // just to check blossomQual
    void recombineSameAsHeuristic();
    void recombineGreedy(bool constrained = false);
    //bool developTree();
    static void nextTreeActions(std::vector<Rec2DAction*>&,
                                const std::vector<Rec2DElement*> &neighbours,
                                const Rec2DNode *node = NULL);

    // Revert recombinations
    void clearChanges();

    // Save mesh & stats
    void updateMesh();
    void saveMesh(std::string);
    void saveStats(std::fstream*);

    // Get/Set methods
    inline void setParamNewAlgo(int horiz, int code) {
      Rec2DAlgo::setParam(horiz, code);
    }
    inline void setHorizon(int h) {_horizon = h;} //1
    inline void setStrategy(int s) {_strategy = s;} //0->6
    inline void setQualCriterion(Rec2DQualCrit c) {_qualCriterion = c;}
    inline void setQualCriterion(int a) {_qualCriterion = (Rec2DQualCrit)a;} //0
    static inline GFace const *const getGFace() {return _cur->_gf;}
    static inline backgroundMesh const *const bgm() {return _cur->_bgm;}
    static inline int getNumChange() {return _cur->_numChange;}
    static inline void incNumChange() {++_cur->_numChange;}
    static inline Rec2DQualCrit getQualCrit() {return _cur->_qualCriterion;}
    static inline void setNewTreeNode(Rec2DNode *rn) {_cur->_curNode = rn;}
    static inline double getTimeLastRun() {return _cur->_lastRunTime;}
    static inline double getTimeBlossom() {return _cur->_blossomTime;}

    // What is asked ?
    static inline bool dynamicTree() {return _cur->_strategy == 6;}
    static inline bool blossomRec() {return _cur->_recombineWithBlossom;}
    static inline bool blossomQual() {return _cur->_qualCriterion == 0;}
    static inline bool verticesQual() {return _cur->_qualCriterion == 1;}
    static inline bool vertAndEdgesQual() {return _cur->_qualCriterion == 2;}
    static inline bool onlyRecombinations() {return !_cur->_collapses;}
    static inline bool checkIfNotAllQuad() {return _cur->_checkIfNotAllQuad;}
    static inline bool avoidIfNotAllQuad() {return _cur->_avoidIfNotAllQuad;}
    static inline bool revertIfNotAllQuad() {return _cur->_revertIfNotAllQuad;}
    static inline bool priorityOfOneAction() {return _cur->_oneActionHavePriority;}
    static inline bool canIsolateTriangle() {return _cur->_noProblemIfObsolete;}

    // Get/Set Weights
    static inline int getWeightEdgeBase() {return _cur->_weightEdgeBase;}
    static inline int getWeightEdgeQuad() {return _cur->_weightEdgeQuad;}
    static inline int getWeightAngleTri() {return _cur->_weightAngleTri;}
    static inline int getWeightAngleQuad() {return _cur->_weightAngleQuad;}
    static inline void setWeightEdgeBase(int a) {_cur->_weightEdgeBase = a;}
    static inline void setWeightEdgeQuad(int a) {_cur->_weightEdgeQuad = a;}
    static inline void setWeightAngleTri(int a) {_cur->_weightAngleTri = a;}
    static inline void setWeightAngleQuad(int a) {_cur->_weightAngleQuad = a;}

    // Get/Set Coefficients
    static inline float getCoefAngleQual() {return _cur->_coefAngleQual;}
    static inline float getCoefDegreeQual() {return _cur->_coefDegreeQual;}
    static inline float getCoefAnglDegQual() {
      return 1. - _cur->_coefAngleQual - _cur->_coefDegreeQual;
    }
    static inline float getCoefLengthQual() {return _cur->_coefLengthQual;}
    static inline float getCoefOrientQual() {return _cur->_coefOrientQual;}
    static inline float getCoefLengOrientQual() {
      return 1. - _cur->_coefLengthQual - _cur->_coefOrientQual;
    }
    static inline void setCoefAngleQual(float f) {_cur->_coefAngleQual = f;}
    static inline void setCoefDegreeQual(float f) {_cur->_coefDegreeQual = f;}
    static inline void setCoefLengthQual(float f) {_cur->_coefLengthQual = f;}
    static inline void setCoefOrientQual(float f) {_cur->_coefOrientQual = f;}

    // Miscellaneous
    void compareWithBlossom();
    int computeQualBlossom() const;
    inline int getNumElemBlossom() const {return elist[0];}
    static void add(MQuadrangle *q);
    static void add(MTriangle *t);
    static void colorFromBlossom(const Rec2DElement *tri1,
                                 const Rec2DElement *tri2,
                                 const Rec2DElement *quad );
    static void colorFromBlossom(const Rec2DElement *tri1,
                                 const Rec2DElement *tri2,
                                 const MElement *quad     );
    //
    static inline double angle2qual(double ang) {
      return std::max(1. - fabs(ang*2./M_PI - 1.), .0);
    }

    // Debug
    void printState() const;
    void drawState(double shiftx, double shifty, bool color = false) const;
    static void drawStateCur(double dx, double dy) {_cur->drawState(dx, dy);}
    static void drawStateOrigin();

  private :
    double _geomAngle(const MVertex*,
                      const std::vector<GEdge*>&,
                      const std::vector<MElement*>&) const;
    bool _iamCurrent() const {return this == Recombine2D::_cur;}
};

//
class Rec2DData {
  public :
    class Action {
      public :
        const Rec2DAction *action;
        unsigned int position;
        Action(const Rec2DAction *ra, unsigned int pos)
          : action(ra), position(pos) {
          static int a = 0;
          if (++a == 1) Msg::Warning("FIXME: position is supefluous in this case (iterators are sufficient)");
        }
        void update();
    };
    //template<class T> friend void std::swap(T&, T&);
    struct gterAction {
      bool operator()(const Action*, const Action*) const;
    };
    struct lessAction {
      bool operator()(const Action*, const Action*) const;
    };

  private :
    static Rec2DData *_cur;

    long double _1valVert, _2valEdge, _2valVert;
    int _numVert, _numEdge;
#ifdef REC2D_RECO_BLOS
    int _0blossomQuality;
#endif

    // Store entities
    std::vector<Rec2DEdge*> _edges;
    std::vector<Rec2DVertex*> _vertices;
    std::vector<Rec2DElement*> _elements;
    std::vector<Action*> _actions;

    // Addition for new algo
    std::set<Rec2DAction*, gterRec2DAction> _sortedActions; // if blossom !
    friend class Rec2DAlgo::Node;
    friend void Rec2DAlgo::clear();
    friend Rec2DAction* Rec2DAlgo::func::getBestNAction();
    friend Rec2DAction* Rec2DAlgo::func::getRandomNAction();
    // TODO: presently managed by Rec2DAlgo... should be managed by Rec2DAction::apply()
    std::vector<Rec2DAction*> _NActions;
    std::set<Rec2DAction*, gterRec2DAction> _sortedNActions; // if blossom !
    friend Rec2DAction* Rec2DAlgo::func::getBestOAction();
    friend Rec2DAction* Rec2DAlgo::func::getRandomOAction();
    std::vector<Rec2DAction*> _OActions;
    std::set<Rec2DAction*, gterRec2DAction> _sortedOActions; // if blossom !

    // Addition for simple algo
    Rec2DContainer<Rec2DElement*> _el_1Actions;
    Rec2DContainer<Rec2DElement*> _el_2Actions;
    Rec2DContainer<Rec2DElement*> _el_3Actions;

    // Store changes (so can revert)
    std::vector<Rec2DDataChange*> _changes;

    // Store parities
    std::map<int, std::vector<Rec2DVertex*> > _parities;
    std::map<Rec2DVertex*, int> _oldParity;

    // for Recombine2D::developTree(..)
    std::vector<Rec2DNode*> _endNodes;

    // Useless Rec2DTwoTri2Quad are not deleted because Rec2DCollapse need them
    std::vector<Rec2DAction*> _hiddenActions;

    // Track elements with one or zero actions
    std::set<Rec2DElement*> _elementWithOneAction;
    std::set<Rec2DElement*> _elementWithZeroAction;

#ifdef REC2D_RECO_BLOS
    std::map<MElement*, Rec2DElement*> _mel2rel;
#endif

  public :
#if 1//def REC2D_DRAW
    std::vector<MTriangle*> _tri;
    std::vector<MQuadrangle*> _quad;
#endif

  public :
    Rec2DData();
    ~Rec2DData();
    static inline bool hasInstance() {return _cur;}

    // Get/Set methods
    //static inline int getNumVert() {return _cur->_numVert;}
    //static inline int getNumEdge() {return _cur->_numEdge;}
    //static inline double getValVert() {return static_cast<double>(_cur->_2valVert);}
    static inline double getSumVert() {return static_cast<double>(_cur->_1valVert);}
    //static inline double getValEdge() {return static_cast<double>(_cur->_2valEdge);}
    static double getValVert(Rec2DQualCrit c = ChoosedCrit);
#ifdef REC2D_RECO_BLOS
    static inline int getBlosQual() {return _cur->_0blossomQuality;}
#endif
    static inline unsigned int getNumElements() {return _cur->_elements.size();}
    static void elementChgAction(Rec2DElement*, int from, int to);

    // Add/Remove Entities
    static void add(const Rec2DEdge*);
    static void add(const Rec2DVertex*);
    static void add(const Rec2DElement*);
    static void rmv(const Rec2DEdge*);
    static void rmv(const Rec2DVertex*);
    static void rmv(const Rec2DElement*);

    // Entities iterators
    typedef std::vector<Rec2DEdge*>::iterator iter_re;
    typedef std::vector<Rec2DVertex*>::iterator iter_rv;
    typedef std::vector<Rec2DElement*>::iterator iter_rel;
    static inline iter_re firstEdge() {return _cur->_edges.begin();}
    static inline iter_rv firstVertex() {return _cur->_vertices.begin();}
    static inline iter_rel firstElement() {return _cur->_elements.begin();}
    static inline iter_re lastEdge() {return _cur->_edges.end();}
    static inline iter_rv lastVertex() {return _cur->_vertices.end();}
    static inline iter_rel lastElement() {return _cur->_elements.end();}

    // Operators on Actions
    static void add(const Rec2DAction*);
    static void rmv(const Rec2DAction*);
    static bool has(const Rec2DAction*);
    static inline void addHidden(const Rec2DAction *ra) {
      _cur->_hiddenActions.push_back((Rec2DAction*)ra);
    }
    static inline bool hasAction() {return _cur->_actions.size();}
    static inline int getNumAction() {return _cur->_actions.size();}
    static inline Rec2DAction* getAction(int i) {
      return const_cast<Rec2DAction*>(_cur->_actions[i]->action);
    }
    //
    static Rec2DAction* getBestAction();
    static Rec2DAction* getRandomAction();
    //inline void sortActions() {sort(_actions.begin(), _actions.end(), gterAction());}
    //
    static void checkObsolete();

    // Operators on Elements
    static Rec2DElement* getBestLessAction();
    static Rec2DElement* getRandomLessAction();

    // Operators on One & Zero Actions
    static void addHasZeroAction(const Rec2DElement*);
    static void rmvHasZeroAction(const Rec2DElement*);
    static bool hasHasZeroAction(const Rec2DElement*);
    static int getNumZeroAction();
    static void addHasOneAction(const Rec2DElement*, Rec2DAction*);
    static void rmvHasOneAction(const Rec2DElement*, Rec2DAction*);
    static bool hasHasOneAction(const Rec2DElement*);
    static int getNumOneAction();
    static void getElementsOneAction(std::vector<Rec2DElement*> &vec);
    static Rec2DAction* getOneAction();
    static void getUniqueOneActions(std::vector<Rec2DAction*>&);

    // Process parities
    static int getNewParity();
    static void removeParity(const Rec2DVertex*, int);
    static inline void addParity(const Rec2DVertex *rv, int p) {
      _cur->_parities[p].push_back((Rec2DVertex*)rv);
    }
    static void associateParity(int pOld, int pNew, Rec2DDataChange *rdc = NULL);

    // Process DataChange objects
    static Rec2DDataChange* getNewDataChange();
    static bool revertDataChange(Rec2DDataChange*);
    static void clearChanges();
    static inline int getNumChanges() {return _cur->_changes.size();}

    // Quality
    static double getGlobalQuality(Rec2DQualCrit c = ChoosedCrit);
    static double getGlobalQuality(int numVert, double valVert,
                                   int numEdge = 0, double valEdge = .0,
                                   Rec2DQualCrit c = ChoosedCrit);
    static void updateVertQual(double, Rec2DQualCrit);
    static void updateEdgeQual(double d, int a = 0) {
      _cur->_2valEdge += d;
      _cur->_numEdge += a;
    }
#ifdef REC2D_RECO_BLOS
    static inline void addBlosQual(int val) {_cur->_0blossomQuality += val;}
#endif

    // Check errors
    static bool checkEntities();
    void checkQuality() const;

    // Print state / Draw actions
    void printState() const;
    void printActions() const;
    static void printAction() {_cur->printAction();}

    // Draw methods
    void drawTriangles(double shiftx, double shifty) const;
    void drawElements(double shiftx, double shifty) const;
    void drawChanges(double shiftx, double shifty, bool color) const;

    // Operators on End Nodes
    static void addEndNode(const Rec2DNode*);
    static void sortEndNode();
    static inline void drawEndNode(int num);
    static inline int getNumEndNode() {return _cur->_endNodes.size();}
    static inline int getNumElement() {return _cur->_elements.size();}

    // Miscellaneous
    static void copyElements(std::vector<Rec2DElement*> &v) {
      v = _cur->_elements;
    }
    static void copyActions(std::vector<Rec2DAction*> &v) {
      v.resize(_cur->_actions.size());
      for (unsigned int i = 0; i < v.size(); ++i) {
        v[i] = const_cast<Rec2DAction*>(_cur->_actions[i]->action);
      }
    }
    static int getNumNActions() {return _cur->_sortedNActions.size();}

#ifdef REC2D_RECO_BLOS
    static Rec2DElement* getRElement(MElement*);
#endif
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
    Rec2DChange() {Msg::Fatal("[Rec2DChange] I should not be created in this manner");}
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

    void getHiddenActions(std::set<Rec2DAction*>&);

    void revert();
};

class Rec2DDataChange {
  private :
    std::vector<Rec2DChange*> _changes;
    Rec2DAction *_ra;

  public :
    ~Rec2DDataChange();

    inline void add(int a) {_changes.push_back(new Rec2DChange(a));}

    inline void hide(Rec2DEdge *re) {_changes.push_back(new Rec2DChange(re, 1));}
    inline void hide(Rec2DVertex *rv) {_changes.push_back(new Rec2DChange(rv, 1));}
    inline void hide(Rec2DElement *rel) {_changes.push_back(new Rec2DChange(rel, 1));}
    std::vector<Rec2DAction*> hiddenActions;
    inline void hide(Rec2DAction *ra) {
      _changes.push_back(new Rec2DChange(ra, 1));
      hiddenActions.push_back(ra);
    }
    inline void hide(std::vector<Rec2DAction*> &vect) {
      _changes.push_back(new Rec2DChange(vect, 1));
      hiddenActions.insert(hiddenActions.end(), vect.begin(), vect.end());
    }

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

    void getHiddenActions(std::set<Rec2DAction*>&);

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
    friend bool Rec2DData::has(const Rec2DAction *ra);
    friend void Rec2DData::Action::update();

  public :
    Rec2DAction();
    virtual ~Rec2DAction() {}
    virtual void hide() = 0;
    virtual void reveal() = 0;

    // Get methods
    virtual bool isRecomb() const = 0;

    // Quality
    double getReward() const;
    double getRealReward() const;
    bool operator<(const Rec2DAction&) const;

    // Application
    virtual bool isObsolete() const = 0;
    virtual void apply(std::vector<Rec2DVertex*> &newPar) = 0;
    virtual void apply(Rec2DDataChange*, std::vector<Rec2DAction*>*&,
                       bool color = false) const = 0;

    // Swap
    virtual void swap(Rec2DVertex*, Rec2DVertex*) = 0;
    virtual void swap(Rec2DEdge*, Rec2DEdge*) = 0;

    // Pointing
    inline void addPointing() {++_numPointing;}
    inline void rmvPointing() {--_numPointing;}

    // Get Element methods
    virtual bool has(const Rec2DElement*) const = 0;
    virtual bool haveElem() const = 0;
    virtual int getNumElement() const = 0;
    virtual Rec2DElement* getElement(int) const = 0;
    virtual Rec2DElement* getRandomElement() const = 0;
    virtual void getElements(std::vector<Rec2DElement*>&) const = 0;
    virtual void getNeighbourElements(std::vector<Rec2DElement*>&) const = 0;
    virtual void getNeighbElemWithActions(std::vector<Rec2DElement*>&) const = 0;
    virtual void getTouchedActions(std::vector<Rec2DAction*>&) const = 0;

    // Get Vertex methods
    virtual Rec2DVertex* getVertex(int) const = 0;

    // Check errors
    virtual bool checkCoherence(const Rec2DAction *ra = NULL) const = 0;
    inline void *getDataAction() const {return _dataAction;}

    // Debug
    virtual void printAdress() = 0;
    virtual void printReward() const = 0;
    virtual void printTypeRew() const = 0;
    virtual void printVertices() const = 0;
    virtual void printIdentity() const = 0;

    // Miscellaneous
    virtual Rec2DAction* getBase() const = 0;
    virtual Rec2DAction* getInfant() const = 0;
    virtual MElement* createMElement(double shiftx, double shifty) = 0;
    virtual void color(int, int, int) const = 0;
    virtual void getIncompatible(std::vector<Rec2DAction*>&) = 0;
    //
    static void removeDuplicate(std::vector<Rec2DAction*>&);

  private :
    virtual void _computeGlobQual() = 0;
    virtual void _computeReward() = 0;
};

class Rec2DTwoTri2Quad : public Rec2DAction {
  private :
    Rec2DElement *_triangles[2];
    Rec2DEdge *_edges[5]; // 4 boundary, 1 embedded
    Rec2DVertex *_vertices[4]; // 4 boundary (2 on embedded edge + 2)
    Rec2DCollapse *_col;
    double _valVert;

#ifdef REC2D_RECO_BLOS
    RecombineTriangle *_rt;
#endif

    friend class Rec2DCollapse;

  public :
    Rec2DTwoTri2Quad(Rec2DElement*, Rec2DElement*);
    ~Rec2DTwoTri2Quad() {}
    void operator delete(void*);
    virtual void hide();
    virtual void reveal();

    // Get methods
    inline bool isRecomb() const {return true;}

    // Application
    virtual bool isObsolete() const;
    virtual void apply(std::vector<Rec2DVertex*> &newPar);
    virtual void apply(Rec2DDataChange*, std::vector<Rec2DAction*>*&,
                       bool color = false) const;

    // Swap
    virtual void swap(Rec2DVertex*, Rec2DVertex*);
    virtual void swap(Rec2DEdge*, Rec2DEdge*);

    // Get Element methods
    virtual bool has(const Rec2DElement*) const;
    virtual inline bool haveElem() const {return true;}
    virtual inline int getNumElement() const {return 2;}
    virtual inline Rec2DElement* getElement(int i) const {return _triangles[i];}
    virtual Rec2DElement* getRandomElement() const;
    virtual void getElements(std::vector<Rec2DElement*>&) const;
    virtual void getNeighbourElements(std::vector<Rec2DElement*>&) const;
    virtual void getNeighbElemWithActions(std::vector<Rec2DElement*>&) const;
    virtual void getTouchedActions(std::vector<Rec2DAction*>&) const;

    // Get Vertex methods
    virtual inline Rec2DVertex* getVertex(int i) const {return _vertices[i];} //-

    // Check errors
    virtual bool checkCoherence(const Rec2DAction *ra = NULL) const;

    // Debug
    virtual inline void printAdress() {Msg::Info(" %d", this);}
    virtual void printReward() const;
    virtual inline void printTypeRew() const {Msg::Info("Recombine %g", _globQualIfExecuted);}
    virtual void printVertices() const;
    virtual void printIdentity() const;

    // Miscellaneous
    virtual inline Rec2DAction* getBase() const {return NULL;}
    virtual inline Rec2DAction* getInfant() const {return (Rec2DAction*)_col;}
    virtual MElement* createMElement(double shiftx, double shifty);
    virtual void color(int, int, int) const;
    virtual void getIncompatible(std::vector<Rec2DAction*>&);

  private :
    virtual void _computeGlobQual();
    virtual void _computeReward();
    void _doWhatYouHaveToDoWithParity(Rec2DDataChange*) const;
};

class Rec2DCollapse : public Rec2DAction {
  private :
    Rec2DTwoTri2Quad *_rec;

  public :
    Rec2DCollapse(Rec2DTwoTri2Quad*);
    ~Rec2DCollapse() {}
    void operator delete(void*);
    virtual void hide();
    virtual void reveal();

    // Get methods
    inline bool isRecomb() const {return false;}

    // Application
    virtual bool isObsolete() const;
    virtual void apply(std::vector<Rec2DVertex*> &newPar);
    virtual void apply(Rec2DDataChange*, std::vector<Rec2DAction*>*&,
                       bool color = false) const;

    // Swap
    virtual inline void swap(Rec2DVertex *rv0, Rec2DVertex *rv1) {_rec->swap(rv0, rv1);}
    virtual inline void swap(Rec2DEdge *re0, Rec2DEdge *re1) {_rec->swap(re0, re1);}

    // Get Element methods
    virtual inline bool has(const Rec2DElement *rel) const {return _rec->has(rel);}
    virtual inline bool haveElem() const {return false;}
    virtual inline int getNumElement() const {return 2;}
    virtual inline Rec2DElement* getElement(int i) const {return _rec->_triangles[i];}
    virtual inline Rec2DElement* getRandomElement() const {
      return _rec->getRandomElement();
    }
    virtual inline void getElements(std::vector<Rec2DElement*> &vec) const {
      _rec->getElements(vec);
    }
    virtual void getNeighbourElements(std::vector<Rec2DElement*> &) const;
    virtual void getNeighbElemWithActions(std::vector<Rec2DElement*> &) const;
    virtual void getTouchedActions(std::vector<Rec2DAction*>&) const {}

    // Get Vertex methods
    virtual inline Rec2DVertex* getVertex(int i) const {
      return _rec->getVertex(i);
    }

    // Check errors
    virtual inline bool checkCoherence(const Rec2DAction *ra = NULL) const {
      return _rec->checkCoherence(this);
    }

    // Debug
    virtual inline void printAdress() {_rec->printAdress();}
    virtual void printReward() const;
    virtual inline void printTypeRew() const {Msg::Info("Collapse %g", _globQualIfExecuted);}
    virtual inline void printVertices() const {_rec->printVertices();}
    virtual void printIdentity() const;

    // Miscellaneous
    virtual inline Rec2DAction* getBase() const {return _rec;}
    virtual inline Rec2DAction* getInfant() const {return NULL;}
    virtual inline MElement* createMElement(double shiftx, double shifty) {return NULL;}
    virtual inline void color(int c1, int c2, int c3) const {_rec->color(c1, c2, c3);}
    virtual void getIncompatible(std::vector<Rec2DAction*>&) {Msg::Fatal("not implemented");};

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
    int _weight;
    int _lastUpdate;

    int _pos; // For quick add and remove in Rec2DData
    friend void Rec2DData::add(const Rec2DEdge*);
    friend void Rec2DData::rmv(const Rec2DEdge*);

  public :
    Rec2DEdge(Rec2DVertex*, Rec2DVertex*);
    ~Rec2DEdge() {if (_pos > -1) hide();}
    void hide();
    void reveal();

    // Get Vertex methods
    inline bool has(const Rec2DVertex *v) const {return v == _rv0 || v == _rv1;}
    inline Rec2DVertex* getVertex(int i) const {if (i) return _rv1; return _rv0;}
    Rec2DVertex* getOtherVertex(const Rec2DVertex*) const;

    // Get Element methods
    static Rec2DElement* getTheOnlyElement(const Rec2DEdge*);
    static void getElements(const Rec2DEdge*, Rec2DElement**);

    // Get Action methods
    //void getUniqueActions(std::vector<Rec2DAction*>&) const;

    // Quality
    inline double getQual() const {return _qual;}
    inline int getWeight() const {return _weight;}
    inline double getWeightedQual() const {return _weight * _qual;}
    void updateQual();

    // Miscellaneous
    inline bool isOnBoundary() const;
    inline void addHasTri() {_addWeight(-Recombine2D::getWeightEdgeQuad());}
    inline void remHasTri() {_addWeight(Recombine2D::getWeightEdgeQuad());}
    void swap(Rec2DVertex *oldRV, Rec2DVertex *newRV, bool upVert = true);

    // Check errors
    bool checkCoherence() const;

    // Debug
    void print() const;

  private :
    void _computeQual();
    void _addWeight(int);
    double _straightAdimLength() const;
    double _straightAlignment() const;
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

    double _sumWQualAngle, _sumWQualEdge;
    int _sumWeightAngle, _sumWeightEdge;

    std::vector<Rec2DEdge*> _edges;
    std::vector<Rec2DElement*> _elements;
    SPoint2 _param;

    int _pos; // For quick add and remove in Rec2DData
    friend void Rec2DData::add(const Rec2DVertex*);
    friend void Rec2DData::rmv(const Rec2DVertex*);

    static double **_qualVSnum;
    static double **_gains;

  public :
    Rec2DVertex(MVertex*);
    Rec2DVertex(Rec2DVertex*, double angle);
    ~Rec2DVertex() {if (_pos > -1) hide();}
    void hide(bool check = true);
    void reveal();

    // Initialize topo qual table
    static void initStaticTable();

    // Get methods
    inline double u() const {return _param[0];}
    inline double v() const {return _param[1];}
    inline void getParam(SPoint2 *p) {*p = _param;}
    inline void getxyz(double *xyz) const {
      xyz[0] = _v->x();
      xyz[1] = _v->y();
      xyz[2] = _v->z();
    }
    inline double getGeomAngle() const {return _angle;}
    inline int getLastUpdate() const {return _lastUpdate;}
    inline MVertex* getMVertex() const {return _v;}

    // Add/Remove Edges
    void add(const Rec2DEdge*);
    bool has(const Rec2DEdge*) const;
    void rmv(const Rec2DEdge*);

    // Add/Remove Elements
    void add(const Rec2DElement*);
    bool has(const Rec2DElement*) const;
    void rmv(const Rec2DElement*);

    // Get Edge methods
    inline void getEdges(std::vector<Rec2DEdge*> &v) const {v = _edges;}
    void getMoreUniqueEdges(std::vector<Rec2DEdge*>&) const;
    static Rec2DEdge* getCommonEdge(const Rec2DVertex*, const Rec2DVertex*);

    // Get Vertex methods
    void getMoreNeighbourVertices(std::vector<Rec2DVertex*>&) const;

    // Get Element methods
    inline int getNumElements() const {return _elements.size();}
    inline void getElements(std::vector<Rec2DElement*> &v) const {v = _elements;}
    static void getCommonElements(const Rec2DVertex*, const Rec2DVertex*,
                                  std::vector<Rec2DElement*>&            );

    // Get Action methods
    void getMoreUniqueActions(std::vector<Rec2DAction*>&) const;

    // Get/Set on boundary
    inline void setOnBoundary();
    inline bool getOnBoundary() const {return _onWhat < 1;}

    // Get/Set parity
    inline int getParity() const {return _parity;}
    void setParity(int, bool tree = false);
    void setParityWD(int pOld, int pNew);
    bool setBoundaryParity(int p0, int p1);

    // Quality
    double getQualDegree(int numEl = -1) const;
    double getGainDegree(int) const;
#ifndef REC2D_VERT_ONLY
    inline double getQualAngle() const {return _sumQualAngle/_elements.size();}
#endif
#ifdef REC2D_VERT_ONLY
    /*double vertQual_getGainQuad(const Rec2DElement*,
                       const Rec2DEdge*, const Rec2DEdge*) const;
    double vertQual_getGainTriLess(const Rec2DEdge*) const;
    void vertQual_addEdgeQual(double val, int num = 0);
    double vertQual_getGainMerge(const Rec2DVertex*, const Rec2DEdge*const*, int) const;
    double vertEdgeQual_getGainOneElemLess() const;
    double vertEdgeQual_getGainMerge(const Rec2DVertex*) const;
    */
    double getGainQuad(const Rec2DElement*,
                       const Rec2DEdge*, const Rec2DEdge*) const;
    double getGainTriLess(const Rec2DEdge*) const;
    void addEdgeQual(double val, int num = 0);
    double getGainMerge(const Rec2DVertex*, const Rec2DEdge*const*, int) const;
    double getGainOneElemLess() const;
    double getGainMerge(const Rec2DVertex*) const;

    double getQual(Rec2DQualCrit crit = ChoosedCrit) const;
    double getQual(double waQualAngles, double waQualEdges, int numElem,
                   Rec2DQualCrit c = ChoosedCrit) const;
    double getGainRecomb(/*Rec2DQualCrit c,*/
                         const Rec2DElement *rel1, const Rec2DElement *rel2,
                         const Rec2DEdge *common = NULL,
                         const Rec2DEdge *adjacent1 = NULL,
                         const Rec2DEdge *adjacent2 = NULL) const;
#endif
    void updateWAQualEdges(double d, int a = 0);

    // Miscellaneous
    void relocate(SPoint2 p);
    inline int getNum() const {return _v->getNum();}

    // Check errors
    bool checkCoherence() const;
    bool checkQuality() const;

    // Debug
    void printElem() const;
    void printQual() const;

  private :
    //inline double _getQualAngle() const {return _sumQualAngle/_elements.size();}
    bool _recursiveBoundParity(const Rec2DVertex *prev, int p0, int p1);
    void _updateQualAngle();
    //inline double _angle2Qual(double ang) const {
    //  return std::max(1. - fabs(ang*2./M_PI - 1.), .0);
    // }
    double _qualDegree(int numEl = -1) const;
    inline double _WAQualAngles() const {return _sumWQualAngle / _sumWeightAngle;}
    inline double _WAQualEdges() const {return _sumWQualEdge / _sumWeightEdge;}
    inline double _vertQual() const {
      double vertQual = _qualDegree();
      vertQual = (Recombine2D::getCoefAnglDegQual() * vertQual
                  + Recombine2D::getCoefAngleQual()           ) * _WAQualAngles()
                 + Recombine2D::getCoefDegreeQual() * vertQual;
      return vertQual;
    }
    inline double _vertQual(double qualDegree, double qualAngle) const {
      double vertQual = qualDegree;
      vertQual = (Recombine2D::getCoefAnglDegQual() * vertQual
                  + Recombine2D::getCoefAngleQual()           ) * qualAngle
                 + Recombine2D::getCoefDegreeQual() * vertQual;
      return vertQual;
    }
};

class Rec2DElement {
  private :
    MElement *_mEl; // can be NULL
    int _numEdge;
    Rec2DEdge *_edges[4];
    Rec2DElement *_elements[4]; // NULL if no neighbour
    std::vector<Rec2DAction*> _actions;

    int _pos; // For quick add and remove in Rec2DData
    friend void Rec2DData::add(const Rec2DElement*);
    friend void Rec2DData::rmv(const Rec2DElement*);

  public :
    Rec2DElement(MTriangle*, const Rec2DEdge**, Rec2DVertex **rv = NULL);
    Rec2DElement(MQuadrangle*, const Rec2DEdge**, Rec2DVertex **rv = NULL);
    ~Rec2DElement() {if (_pos > -1) hide();}
    void hide();
    void reveal(Rec2DVertex **rv = NULL);

    // Add/Remove Edges
    void add(Rec2DEdge*);
    bool has(const Rec2DEdge*) const;

    // Has Vertex/Element
    bool has(const Rec2DVertex*) const;
    bool has(const Rec2DElement*) const;

    // Add/Remove neighbour Elements
    void addNeighbour(const Rec2DEdge*, const Rec2DElement*);
    void rmvNeighbour(const Rec2DEdge*, const Rec2DElement*);
    bool isNeighbour(const Rec2DEdge*, const Rec2DElement*) const;

    // Add/Remove Actions
    void add(const Rec2DAction*);
    void rmv(const Rec2DAction*);
    bool has(const Rec2DAction*) const;

    // Get Edge methods
    inline void getMoreEdges(std::vector<Rec2DEdge*> &v) const {
      v.insert(v.end(), _edges, _edges + _numEdge);
    }
    static Rec2DEdge* getCommonEdge(const Rec2DElement*, const Rec2DElement*);

    // Get Vertex methods
    void getVertices(std::vector<Rec2DVertex*>&) const;
    Rec2DVertex* getOtherVertex(const Rec2DVertex*, const Rec2DVertex*) const;

    // Get Element methods
    void getMoreNeighbours(std::vector<Rec2DElement*>&) const;
    //static void getElements(const Rec2DEdge*, Rec2DElement**);

    // Get Action methods
    inline int getNumActions() const {return _actions.size();}
    inline Rec2DAction* getAction(int i) const {return _actions[i];}
    inline void getActions(std::vector<Rec2DAction*> &v) const {v = _actions;};
    void getMoreUniqueActions(std::vector<Rec2DAction*>&) const;
    void getMoreUniqueActions(std::set<Rec2DAction*, gterRec2DAction>&) const;

    // Swap
    void swap(Rec2DEdge*, Rec2DEdge*);
    void swapMVertex(Rec2DVertex*, Rec2DVertex*);

    // Quality
    inline int getAngleWeight() const {
      return _numEdge > 3 ? Recombine2D::getWeightAngleQuad() : Recombine2D::getWeightAngleTri();
    }
    double getAngle(const Rec2DVertex*) const;
    inline double getAngleQual(const Rec2DVertex *v) const {
      return Recombine2D::angle2qual(getAngle(v));
    }
    inline double getWeightedAngleQual(const Rec2DVertex *v) const {
      return getAngleWeight() * getAngleQual(v);
    }

    // Miscellaneous
    inline int getNum() const {return _mEl->getNum();}
    inline bool isTri() const {return _numEdge == 3;}
    inline bool isQuad() const {return _numEdge == 4;}
    inline MElement* getMElement() const {return _mEl;}
    bool hasIdenticalNeighbour() const;
#if 1//def REC2D_DRAW
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

    // Check errors
    bool checkCoherence() const;

    // Debug
    void print() const;
    void createElement(double shiftx, double shifty) const;

  private :
    MQuadrangle* _createQuad() const;
};

//
namespace Rec2DAlgo {
  class Node;

  bool paramOK();
  bool paramOKSimpleAlgo();
  bool setParam(int horizon, int code);
  void getParam(int &horizon, int &code);
  void computeAllParam(std::vector<int> &, bool restricted = true);
  void execute(bool complete = false);
  void clear();

  namespace data {
    extern int horizon;
    extern int codeParam;

    extern bool root_tree_srch;
    extern bool root_one_srch;
    extern bool root_take_best;
    extern int root_std_srch;
    /* 1 : all-search
     * 2 : qall-search
     * 3 : qfirst-search
     * 4 : qlast-search
     */

    extern bool plus_tree_srch;
    extern bool plus_one_srch;
    extern bool plus_take_best;
    extern int plus_std_srch;
    /* 1 : all-search
     * 2 : qall-search
     * 3 : qfirst-search
     * 4 : tall-search
     * 5 : tfirst-search
     * 6 : tlast-search
     */

    extern Node *initial;
    extern Node *current;
    extern Node *quadOk;
    extern std::vector<Node*> sequence;

    extern bool try_clique;
  }

  namespace func {
    bool lookAhead(bool complete); // false if no lookahead tree
    void chooseBestSequence();

    // functions search
    void searchForOne(std::vector<Rec2DElement*>&, bool takeBest);
    void searchForRootStd(std::vector<Rec2DElement*>&);
    void searchForPlusStd(std::vector<Rec2DElement*>&, int depth);
    void searchForAll(std::vector<Rec2DElement*>&, bool takeBest);
    void searchForQAll(std::vector<Rec2DElement*>&, bool takeBest);
    void searchForQFirst(std::vector<Rec2DElement*>&);
    void searchForQLast(std::vector<Rec2DElement*>&);
    void searchForTAll(std::vector<Rec2DElement*>&);
    void searchForTFirst(std::vector<Rec2DElement*>&);
    void searchForTLast(std::vector<Rec2DElement*>&);

    void searchForLessAction(std::vector<Rec2DElement*>&);
    void searchForTreeLessAction(std::vector<Rec2DElement*>&);

    Rec2DElement* random(std::vector<Rec2DElement*> &v);
    Rec2DElement* best(std::vector<Rec2DElement*>&);

    /*void insertUnique(std::vector<Rec2DElement*> &from,
                      std::vector<Rec2DElement*> &to);
    void removeCommon(std::vector<Rec2DElement*> &from,
                      std::vector<Rec2DElement*> &to);*/

    Rec2DAction* getBestNAction();
    Rec2DAction* getRandomNAction();
    Rec2DAction* getBestOAction();
    Rec2DAction* getRandomOAction();

    // For cliques
    typedef std::pair< Rec2DAction*, std::vector<Rec2DAction*> > Ra2Incomp;
    class CompareIncomp
    {
      public:
      bool operator()(const Ra2Incomp *x, const Ra2Incomp *y) const
      {
        return x->second.size() > y->second.size();
        // action with less incompatible action on top of the heap
      }
    };
    void subsetIncompatibilities(const std::vector<Ra2Incomp*> &complete,
                                 const std::vector<Rec2DAction*> &subAction,
                                       std::vector<Ra2Incomp*> &subset);
    void removeLinkIncompatibilities(std::vector<Ra2Incomp*>&,
                                     const Rec2DAction*, const Rec2DAction*);
    void findMaximalClique(std::vector<Rec2DAction*>&);
    void findMaximumClique(std::vector<Ra2Incomp*>&);
    void relativeComplement(const std::vector<Rec2DAction*>&,
                                  std::vector<Rec2DAction*>&);
    void intersection(const std::vector<Rec2DAction*>&,
                            std::vector<Rec2DAction*>&);
  }

  class Node {
  private :
    int _quality;
    Rec2DAction *_ra;
    Rec2DDataChange *_dataChange;
    std::vector<Rec2DAction*> *_createdActions;
    std::vector<Node*> _children;

  public :
    Node();
    Node(Rec2DAction*);
    ~Node();

    Node* getChild() const {
      if (_children.size() != 1) {
        Msg::Fatal("Have %d child(ren), not exactly one", _children.size());
        return NULL;
      }
      return _children[0];
    }
    Rec2DAction* getAction() const {return _ra;}
    int numChildren() const {return _children.size();}
    Node* getNodeBestSequence();
    bool choose(Node*);
    void updateNActions(Node*);
    int getMaxLeafQual() const;
    inline int getQual() const {return _quality;} //ft
    inline int getReward() const {return _ra->getRealReward();} //ft

    bool makeChanges();
    void colourBestSequence(int depth);

    void branch_root();
    void branch(int depth);
    void branchComplete(int depth);
    void goAhead(int depth, bool complete = false);
  };
}

class Rec2DNode {
  private :
    Rec2DNode *_father;
    Rec2DNode *_son[REC2D_NUMB_SONS];
    Rec2DAction *_ra;
    Rec2DDataChange *_dataChange;
    int _depth;
    // seq = from son to end of horizon/tree
    double _reward, _globalQuality, _bestSeqReward, _expectedSeqReward;
    std::vector<Rec2DAction*> *_createdActions;

    bool _notAllQuad; // For only recombinations

  public :
    Rec2DNode(Rec2DNode *father, Rec2DAction*, int depth = -1);
    ~Rec2DNode();

    // Get methods
    inline double getReward() const {return _reward;}
    inline Rec2DAction* getAction() const {return _ra;}
    inline Rec2DNode* getFather() const {return _father;}

    // Process the tree
    void lookahead(int depth);
    static Rec2DNode* selectBestNode(Rec2DNode*);

    // Make/Revert changes
    bool makeChanges();
    bool revertChanges();

    // Miscellaneous
    bool operator<(Rec2DNode&);
    bool canBeDeleted() const;
    inline bool isInSequence() const {return _father && _father->_depth != _depth;}
    inline bool notInSubTree() const {return hasOneSon() && _son[0]->_depth == _depth;}
    inline bool hasOneSon() const {return _son[0] && !_son[1];}
    inline Rec2DNode* getSon() const {return _son[0];}

    // Debug
    void draw(double dx, double dy) {
      if (_father)
        _father->_mkChgSinceBeginning();
      if (_dataChange) Msg::Error("_Ber_");
      _dataChange = Rec2DData::getNewDataChange();
      _ra->apply(_dataChange, _createdActions);
      _dataChange = NULL;
      Recombine2D::drawStateCur(dx, dy);
    }
    void printIdentity() const;
    void printSequence() const;

  private:
    // Process the tree
    void _makeDevelopments(int depth);
    void _createSons(const std::vector<Rec2DAction*>&, int depth);
    void _develop(int depth);

    // Operators on Sons
    inline bool _hasSons() const {return _son[0];}
    /*bool _hasSon(Rec2DNode *n) {
      if (!n) return false;
      int i = -1;
      while (++i < REC2D_NUMB_SONS && _son[i] != n);
      return i < REC2D_NUMB_SONS;
    }*/
    inline int _getNumSon() const;
    void _delSons(bool alsoFirst);
    void _orderSons();
    bool _rmvSon(Rec2DNode *n);

    // Operators on Father
    void _rmvFather(Rec2DNode *n);

    // Reward
    inline double _getExpectedSeqReward() {return _reward + _expectedSeqReward;}
    inline double _getBestSequenceReward() {return _reward + _bestSeqReward;}
    inline double _getGlobQual() const {return _globalQuality + _reward;}

    // Miscellaneous
    void _mkChgSinceBeginning() {
      if (_father)
        _father->_mkChgSinceBeginning();
      else if (!_ra) return;
      if (_dataChange) Msg::Error("_Ber_");
      _dataChange = Rec2DData::getNewDataChange();
      _ra->apply(_dataChange, _createdActions);
      _dataChange = NULL;
      static int a = 0;
      if (++a == 1) Msg::Warning("FIXME pas propre du tout");
    }
    inline bool _isNotAllQuad() const {return _notAllQuad;}
};

#endif
