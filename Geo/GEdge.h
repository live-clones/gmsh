#ifndef H_GEdge
#define H_GEdge

#include "GEntity.h"
#include "GVertex.h"

/** A model edge. */

class GEdge : public GEntity {
public:
  GEdge(GModel *model, 
	int tag, 
	GVertex *_v0, 
	GVertex *_v1)
    : GEntity (model,tag),v0(_v0),v1(_v1) 
    {
      v0->add_edge (this);
      v1->add_edge (this);
    }
  virtual ~GEdge() 
    {
      v0->del_edge (this);
      v1->del_edge (this);
    }

  virtual int dim() const {return 1;}

  virtual std::list<GRegion*> regions() const;
  virtual std::list<GFace*> faces() const;
  virtual std::list<GEdge*> edges() const;
  virtual std::list<GVertex*> vertices() const;

  virtual bool periodic(int dim=0) const = 0;
  virtual bool continuous(int dim=0) const = 0;

  virtual int inClosure(GEntity *ent) const; // if ent is in closure of this edge

  // Geometric ops
  /** Get parameter on edge for given point. */
  virtual double param(const GPoint &pt);

  /** Get the parameter location for a point in space on the edge. */
  virtual double parFromPoint(const SPoint3 &) const = 0;

  /** Get the point for the given parameter location. */
  virtual GEPoint point(double p) const = 0;  

  /** Get the closest point on the edge to the given point. */
  virtual GEPoint closestPoint(const SPoint3 & queryPoint);

  /** True if the edge contains the given parameter. */
  virtual int containsParam(double pt) const = 0;

  /** Get first derivative of edge at the given parameter. */
  virtual SVector3 firstDer(double par) const = 0;

  /** Get nth derivative at the given paramater. */
  virtual void nthDerivative(double param, int n, double *array) const=0;

  /** reparmaterize the point onto the given face. */
  virtual SPoint2 reparamOnFace(GFace *face, double epar,int dir) const = 0;			  

  void addFace ( GFace *f ){ l_faces.push_back (f);  }
  void delFace ( GFace *f ){ l_faces.erase(std::find(l_faces.begin(),l_faces.end(),f));  }


protected:

  GVertex v0,v1;
  std::list<GFace *> l_faces;

};


#endif
