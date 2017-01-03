// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Paul-Emile Bernard

#ifndef _GENERIC_FACE_H_
#define _GENERIC_FACE_H_

#include "GmshConfig.h"
#include "GFace.h"
#include "GModel.h"
#include "GenericVertex.h"
#include "GenericEdge.h"
#include "Range.h"
#include <vector>

/* The set of Generic Entities is a generic interface to any other modeler.
   Callbacks (function pointers) are given, sending requests, enquiries, to the
   native modeler. */

class GenericFace : public GFace {
protected:
  int id;
  double umin, umax, vmin, vmax;// face uv bounds
  bool _periodic[2];// is periodic in u, v
  double _period[2];

public:
  // callbacks typedef
  typedef bool (*ptrfunction_int_refstring)(int, std::string&);
  typedef bool (*ptrfunction_int_refbool_refbool_refdouble_refdouble)(int, bool&, bool&, double&, double&);
  typedef bool (*ptrfunction_int_refvector_refvector)(const int , const std::vector<double> &, std::vector<double> &);
  typedef bool (*ptrfunction_int_refvector_refvector_refvector)(const int , const std::vector<double> &, std::vector<double> &, std::vector<double> &);
  typedef bool (*ptrfunction_int_refvector_refbool)(const int , const std::vector<double> &, bool &);
  typedef bool (*ptrfunction_int_int_refdouble_refdouble)(const int, const int, double &, double &);
  typedef bool (*ptrfunction_int_refvector_refvector_refvector_refdouble_refdouble)(const int, const std::vector<double> &, std::vector<double> &, std::vector<double> &, double &, double &);
  typedef bool (*ptrfunction_int_refvector_refvector_refvector_refvector)(const int , const std::vector<double> &, std::vector<double> &, std::vector<double> &, std::vector<double> &);

  GenericFace(GModel *m, int num, int _native_id);
  virtual ~GenericFace();

  Range<double> parBounds(int i) const;
  virtual GPoint point(double par1, double par2) const;
  virtual GPoint closestPoint(const SPoint3 & queryPoint,
                              const double initialGuess[2]) const;
  virtual bool containsPoint(const SPoint3 &pt) const;
  virtual SVector3 normal(const SPoint2 &param) const;
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &, SVector3 *, SVector3 *, SVector3 *) const;
  virtual GEntity::GeomType geomType() const;
  virtual SPoint2 parFromPoint(const SPoint3 &, bool onSurface=true) const;
  virtual double curvatureMax(const SPoint2 &param) const;
  virtual double curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                            double *curvMax, double *curvMin) const;
  virtual bool periodic(int dir) const { return false;}//_periodic[dir]; }// TODO ?
  virtual double period(int dir) const{ return _period[dir]; };

  ModelType getNativeType() const { return GenericModel; }
  virtual int getNativeInt()const{return id;};

  void addBndInfo(int loop, GEdge *ptr, int sign)
  {
    bnd.insert(std::make_pair(loop, std::make_pair(ptr,sign)));
    l_dirs.push_back(sign);
    l_edges.push_back(ptr);
    loopsnumber.insert(loop);
    ptr->addFace(this);
  };
  void createLoops();

  void computePeriodicity();

  // sets callbacks
  static void setFaceGeomType(ptrfunction_int_refstring fct){FaceGeomType = fct;};
  static void setFaceUVFromXYZ(ptrfunction_int_refvector_refvector fct){FaceUVFromXYZ = fct;};
  static void setFaceClosestPoint(ptrfunction_int_refvector_refvector_refvector fct){FaceClosestPoint = fct;};
  static void setFaceContainsPointFromXYZ(ptrfunction_int_refvector_refbool fct){FaceContainsPointFromXYZ = fct;};
  static void setFaceContainsPointFromUV(ptrfunction_int_refvector_refbool fct){FaceContainsPointFromUV = fct;};
  static void setFaceXYZFromUV(ptrfunction_int_refvector_refvector fct){FaceXYZFromUV = fct;};
  static void setFaceParBounds(ptrfunction_int_int_refdouble_refdouble fct){FaceParBounds = fct;};
  static void setFaceCurvatures(ptrfunction_int_refvector_refvector_refvector_refdouble_refdouble fct){FaceCurvatures = fct;};
  static void setFaceEvalNormal(ptrfunction_int_refvector_refvector fct){FaceEvalNormal = fct;};
  static void setFaceFirstDer(ptrfunction_int_refvector_refvector_refvector fct){FaceFirstDer = fct;};
  static void setFaceSecondDer(ptrfunction_int_refvector_refvector_refvector_refvector fct){FaceSecondDer = fct;};
  static void setFacePeriodicInfo(ptrfunction_int_refbool_refbool_refdouble_refdouble fct){FacePeriodicInfo = fct;};

private:
  std::multimap<int, std::pair<GEdge*,int> > bnd;
  std::set<int> loopsnumber;

  // the callbacks:
  static ptrfunction_int_refstring FaceGeomType;
  static ptrfunction_int_refvector_refvector FaceUVFromXYZ,FaceXYZFromUV,FaceEvalNormal;
  static ptrfunction_int_refvector_refvector_refvector FaceClosestPoint,FaceFirstDer;
  static ptrfunction_int_refvector_refbool FaceContainsPointFromXYZ,FaceContainsPointFromUV;
  static ptrfunction_int_int_refdouble_refdouble FaceParBounds;
  static ptrfunction_int_refvector_refvector_refvector_refdouble_refdouble FaceCurvatures;
  static ptrfunction_int_refvector_refvector_refvector_refvector FaceSecondDer;
  static ptrfunction_int_refbool_refbool_refdouble_refdouble FacePeriodicInfo;
};

#endif
