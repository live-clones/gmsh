// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GENERIC_EDGE_H
#define _GENERIC_EDGE_H

#include "GmshConfig.h"
#include "GEdge.h"
#include "GModel.h"
#include "GenericVertex.h"
#include "Range.h"
#include <vector>

using namespace std;

class GenericFace;

/*The set of Generic Entities is a generic interface to any other modeler.
  Callbacks (function pointers) are given, sending requests, enquiries, to the native modeler. */

class GenericEdge : public GEdge {
  protected:
    double s0, s1;
    int id;
  public:
    // callbacks typedef
    typedef bool (*ptrfunction_int_double_refvector)(int, double, vector<double>&);
    typedef bool (*ptrfunction_int_refdouble_refdouble)(int, double&, double&);
    typedef bool (*ptrfunction_int_double_refdouble)(int, double, double&);
    typedef bool (*ptrfunction_int_refstring)(int, string&);
    typedef bool (*ptrfunction_int_refbool)(int, bool&);
    typedef bool (*ptrfunction_int_refvector_refdouble_refvector_refbool)(int, const vector<double> &, double &, vector<double>&, bool &);
    typedef bool (*ptrfunction_int_int_double_int_refvector)(int, int, double, int, vector<double> &);

    GenericEdge(GModel *model, int num,int _native_id, GVertex *v1, GVertex *v2);
    virtual ~GenericEdge();

    virtual Range<double> parBounds(int i) const;
    virtual GeomType geomType() const;
    virtual bool degenerate(int) const;
    virtual GPoint point(double p) const;
    virtual SVector3 firstDer(double par) const;
    virtual double curvature (double par) const;
    virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;
    virtual GPoint closestPoint(const SPoint3 &queryPoint, double &param) const;

    ModelType getNativeType() const { return GenericModel; }
    virtual int getNativeInt()const{return id;};

    bool is3D() const;
    bool isSeam(const GFace *) const;

    // sets the callbacks, to be given by the user
    static void setEdgeEvalXYZFromT(ptrfunction_int_double_refvector fct){EdgeEvalXYZFromT = fct;};
    static void setEdgeEvalParBounds(ptrfunction_int_refdouble_refdouble fct){EdgeEvalParBounds = fct;};
    static void setEdgeGeomType(ptrfunction_int_refstring fct){EdgeGeomType = fct;};
    static void setEdgeDegenerated(ptrfunction_int_refbool fct){EdgeDegenerated = fct;};
    static void setEdgeEvalFirstDer(ptrfunction_int_double_refvector fct){EdgeEvalFirstDer = fct;};
    static void setEdgeEvalCurvature(ptrfunction_int_double_refdouble fct){EdgeEvalCurvature = fct;};
    static void setEdgeClosestPoint(ptrfunction_int_refvector_refdouble_refvector_refbool fct){EdgeClosestPoint = fct;};
    static void setEdgeIs3D(ptrfunction_int_refbool fct){EdgeIs3D = fct;};
    static void setEdgeReparamOnFace(ptrfunction_int_int_double_int_refvector fct){EdgeReparamOnFace = fct;};

  private:
    // the callbacks:
    // --------------
    static ptrfunction_int_double_refvector EdgeEvalXYZFromT;
    static ptrfunction_int_refdouble_refdouble EdgeEvalParBounds;
    static ptrfunction_int_refstring EdgeGeomType;
    static ptrfunction_int_refbool EdgeDegenerated;
    static ptrfunction_int_double_refvector EdgeEvalFirstDer;
    static ptrfunction_int_double_refdouble EdgeEvalCurvature;
    // the first vector is a query point xyz, fills the second vector with closest point 
    // on edge using orthogonal projection.  Fills double param with parametric coordinate of end point projection.
    static ptrfunction_int_refvector_refdouble_refvector_refbool EdgeClosestPoint;
    static ptrfunction_int_refbool EdgeIs3D;
    static ptrfunction_int_int_double_int_refvector EdgeReparamOnFace;


};


#endif
