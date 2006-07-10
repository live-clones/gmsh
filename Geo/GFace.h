#ifndef H_GFace
#define H_GFace

class GRegion;
#include "GPoint.h"
#include "GEntity.h"
#include "GEdgeLoop.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "Pair.h"

/** A model face. 
 */
class GFace : public GEntity 
{
protected: 
  std::list<GEdgeLoop *> l_edgeLoops;
  std::list<GEdge *>     l_edges;
  std::list<int>         l_dirs;
  GRegion *r1, *r2;
public:
  GFace(GModel *model, int tag) : GEntity (model,tag),r1(0),r2(0){}
  virtual ~GFace();

  void addRegion ( GRegion *r ){ r1?r2=r:r1=r;  }
  void delRegion ( GRegion *r ){ if(r1==r)r1=r2;r2=0;  }

  virtual int dim() const {return 2;}

  /** Get the location of any parametric degeneracies on the face in the
    given parametric direction. */
  virtual int paramDegeneracies(int dir, double *par) = 0;

  /** Return the point on the face corresponding to the given parameter. */
  virtual GPoint point(double par1, double par2) const = 0;
  virtual GPoint point(const SPoint2 &pt) const = 0;

  /** Return the parmater location on the face given a point in space that
    is on the face. */
  virtual SPoint2 parFromPoint(const SPoint3 &) const = 0;

  /** True if the parameter value is interior to the face. */
  virtual int containsParam(const SPoint2 &pt) const = 0;

  /** Period of the face in the given direction. */
  virtual double period(int dir) const;

  /** Return the point on the face closest to the given point. */
  virtual GPoint closestPoint(const SPoint3 & queryPoint);

  /** Return the normal to the face at the given parameter location. */
  virtual SVector3 normal(const SPoint2 &param) const = 0;

  /** Return the first derivate of the face at the parameter location. */
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const = 0;
  
  /** Return the nth derivate of the face at the parametric location. */
  virtual double * nthDerivative(const SPoint2 &param, int n, 
				 double *array) const;
  /* true if the surface underlying the face is periodic and we
     need to worry about that. */
  virtual bool surfPeriodic(int dim) const = 0;
  virtual int inClosure(GEntity *ent) const {throw;}
protected:
  void buildEdgeLoops ();
};


#endif


