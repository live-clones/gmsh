// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Frederic Duboeuf

#ifndef MSUBELEMENT_H
#define MSUBELEMENT_H

#include "GmshMessage.h"
#include "MElement.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MPoint.h"

// A sub tetrahedron, contained in another element
class MSubTetrahedron : public MTetrahedron {
  friend class MElementFactory;
  friend class GModel;

protected:
  bool _owner;
  union {
    MElement *_orig; // pointer to parent
    int _orig_N; // element number of parent  (only used while reading file...)
  };
  std::vector<MElement *> _parents; // not used in msh 3 file format
  mutable MElement *_base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

  MSubTetrahedron(const std::vector<MVertex *> &v, int num, int part,
                  bool owner, int orig)
    : MTetrahedron(v, num, part), _owner(owner), _orig_N(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  virtual void updateParent(
    GModel *gm); // NEVER ever use this ! (except for reading msh files !)

public:
  MSubTetrahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3,
                  int num = 0, int part = 0, bool owner = false,
                  MElement *orig = nullptr)
    : MTetrahedron(v0, v1, v2, v3, num, part), _owner(owner), _orig(orig),
      _base(nullptr), _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubTetrahedron(const std::vector<MVertex *> &v, int num = 0, int part = 0,
                  bool owner = false, MElement *orig = nullptr)
    : MTetrahedron(v, num, part), _owner(owner), _orig(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubTetrahedron(const MTetrahedron &tet, bool owner = false,
                  MElement *orig = nullptr)
    : MTetrahedron(tet), _owner(owner), _orig(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  ~MSubTetrahedron();

  virtual int getTypeForMSH() const { return MSH_TET_SUB; }
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const;
  virtual const JacobianBasis *getJacobianFuncSpace(int order = -1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int order = -1) const;
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int order = -1) const;
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int order = -1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                double s[][3][3][3],
                                                int order = -1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(double u, double v, double w,
                             double jac[3][3]) const;
  virtual double getPrimaryJacobian(double u, double v, double w,
                                    double jac[3][3]) const;
  virtual std::size_t getNumShapeFunctions() const;
  virtual std::size_t getNumPrimaryShapeFunctions() const;
  virtual const MVertex *getShapeFunctionNode(int i) const;
  virtual MVertex *getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                      double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                      double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false)
  {
    _orig = p;
    _owner = owner;
  }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement *> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement *> &parents,
                              bool owner = false)
  {
    _parents = parents;
    _orig = _parents[0];
    _owner = owner;
  }
  virtual const MElement *getBaseElement() const
  {
    if(!_base) _base = new MTetrahedron(*this);
    return _base;
  }
  virtual MElement *getBaseElement()
  {
    if(!_base) _base = new MTetrahedron(*this);
    return _base;
  }
};

// A sub triangle, contained in another element
class MSubTriangle : public MTriangle {
  friend class MElementFactory;
  friend class GModel;

protected:
  bool _owner;
  union {
    MElement *_orig; // pointer to parent
    int _orig_N; // element number of parent  (only used while reading file...)
  };
  std::vector<MElement *> _parents; // not used in msh 3 file format
  mutable MElement *_base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

  MSubTriangle(const std::vector<MVertex *> &v, int num, int part, bool owner,
               int orig)
    : MTriangle(v, num, part), _owner(owner), _orig_N(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  virtual void updateParent(
    GModel *gm); // NEVER ever use this ! (except for reading msh files !)
public:
  MSubTriangle(MVertex *v0, MVertex *v1, MVertex *v2, int num = 0, int part = 0,
               bool owner = false, MElement *orig = nullptr)
    : MTriangle(v0, v1, v2, num, part), _owner(owner), _orig(orig),
      _base(nullptr), _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubTriangle(const std::vector<MVertex *> &v, int num = 0, int part = 0,
               bool owner = false, MElement *orig = nullptr)
    : MTriangle(v, num, part), _owner(owner), _orig(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubTriangle(const MTriangle &tri, bool owner = false,
               MElement *orig = nullptr)
    : MTriangle(tri), _owner(owner), _orig(orig), _base(nullptr), _pOrder(-1),
      _npts(0), _pts(nullptr)
  {
  }
  ~MSubTriangle();

  virtual int getTypeForMSH() const { return MSH_TRI_SUB; }
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const;
  virtual const JacobianBasis *getJacobianFuncSpace(int order = -1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int order = -1) const;
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int order = -1) const;
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int order = -1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                double s[][3][3][3],
                                                int order = -1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(double u, double v, double w,
                             double jac[3][3]) const;
  virtual double getPrimaryJacobian(double u, double v, double w,
                                    double jac[3][3]) const;
  virtual std::size_t getNumShapeFunctions() const;
  virtual std::size_t getNumPrimaryShapeFunctions() const;
  virtual const MVertex *getShapeFunctionNode(int i) const;
  virtual MVertex *getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                      double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                      double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false)
  {
    _orig = p;
    _owner = owner;
  }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement *> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement *> &parents,
                              bool owner = false)
  {
    _parents = parents;
    _orig = _parents[0];
    _owner = owner;
  }
  virtual const MElement *getBaseElement() const
  {
    if(!_base) _base = new MTriangle(*this);
    return _base;
  }
  virtual MElement *getBaseElement()
  {
    if(!_base) _base = new MTriangle(*this);
    return _base;
  }
};

// A sub line, contained in another element
class MSubLine : public MLine {
  friend class MElementFactory;
  friend class GModel;

protected:
  bool _owner;
  union {
    MElement *_orig; // pointer to parent
    int _orig_N; // element number of parent  (only used while reading file...)
  };
  std::vector<MElement *> _parents; // not used in msh 3 file format
  mutable MElement *_base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

  MSubLine(const std::vector<MVertex *> &v, int num, int part, bool owner,
           int orig)
    : MLine(v, num, part), _owner(owner), _orig_N(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  virtual void updateParent(
    GModel *gm); // NEVER ever use this ! (except for reading msh files !)
public:
  MSubLine(MVertex *v0, MVertex *v1, int num = 0, int part = 0,
           bool owner = false, MElement *orig = nullptr)
    : MLine(v0, v1, num, part), _owner(owner), _orig(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubLine(const std::vector<MVertex *> &v, int num = 0, int part = 0,
           bool owner = false, MElement *orig = nullptr)
    : MLine(v, num, part), _owner(owner), _orig(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubLine(const MLine &lin, bool owner = false, MElement *orig = nullptr)
    : MLine(lin), _owner(owner), _orig(orig), _base(nullptr), _pOrder(-1),
      _npts(0), _pts(nullptr)
  {
  }
  ~MSubLine();

  virtual int getTypeForMSH() const { return MSH_LIN_SUB; }
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const;
  virtual const JacobianBasis *getJacobianFuncSpace(int order = -1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int order = -1) const;
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int order = -1) const;
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int order = -1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                double s[][3][3][3],
                                                int order = -1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(double u, double v, double w,
                             double jac[3][3]) const;
  virtual double getPrimaryJacobian(double u, double v, double w,
                                    double jac[3][3]) const;
  virtual std::size_t getNumShapeFunctions() const;
  virtual std::size_t getNumPrimaryShapeFunctions() const;
  virtual const MVertex *getShapeFunctionNode(int i) const;
  virtual MVertex *getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                      double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                      double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false)
  {
    _orig = p;
    _owner = owner;
  }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement *> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement *> &parents,
                              bool owner = false)
  {
    _parents = parents;
    _orig = _parents[0];
    _owner = owner;
  }
  virtual const MElement *getBaseElement() const
  {
    if(!_base) _base = new MLine(*this);
    return _base;
  }
  virtual MElement *getBaseElement()
  {
    if(!_base) _base = new MLine(*this);
    return _base;
  }
};

// A sub point, contained in another element
class MSubPoint : public MPoint {
  friend class MElementFactory;
  friend class GModel;

protected:
  bool _owner;
  union {
    MElement *_orig; // pointer to parent
    int _orig_N; // element number of parent  (only used while reading file...)
  };
  std::vector<MElement *> _parents; // not used in msh 3 file format
  mutable MElement *_base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

  MSubPoint(const std::vector<MVertex *> &v, int num, int part, bool owner,
            int orig)
    : MPoint(v, num, part), _owner(owner), _orig_N(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  virtual void updateParent(
    GModel *gm); // NEVER ever use this ! (except for reading msh files !)
public:
  MSubPoint(MVertex *v0, int num = 0, int part = 0, bool owner = false,
            MElement *orig = nullptr)
    : MPoint(v0, num, part), _owner(owner), _orig(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubPoint(const std::vector<MVertex *> &v, int num = 0, int part = 0,
            bool owner = false, MElement *orig = nullptr)
    : MPoint(v, num, part), _owner(owner), _orig(orig), _base(nullptr),
      _pOrder(-1), _npts(0), _pts(nullptr)
  {
  }
  MSubPoint(const MPoint &pt, bool owner = false, MElement *orig = nullptr)
    : MPoint(pt), _owner(owner), _orig(orig), _base(nullptr), _pOrder(-1),
      _npts(0), _pts(nullptr)
  {
  }
  ~MSubPoint();

  virtual int getTypeForMSH() const { return MSH_PNT_SUB; }
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const;
  virtual const JacobianBasis *getJacobianFuncSpace(int order = -1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int order = -1) const;
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int order = -1) const;
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int order = -1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                double s[][3][3][3],
                                                int order = -1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf,
                             double jac[3][3]) const;
  virtual double getJacobian(double u, double v, double w,
                             double jac[3][3]) const;
  virtual double getPrimaryJacobian(double u, double v, double w,
                                    double jac[3][3]) const;
  virtual std::size_t getNumShapeFunctions() const;
  virtual std::size_t getNumPrimaryShapeFunctions() const;
  virtual const MVertex *getShapeFunctionNode(int i) const;
  virtual MVertex *getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                      double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                      double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false)
  {
    _orig = p;
    _owner = owner;
  }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement *> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement *> &parents,
                              bool owner = false)
  {
    _parents = parents;
    _orig = _parents[0];
    _owner = owner;
  }
  virtual const MElement *getBaseElement() const
  {
    if(!_base) _base = new MPoint(*this);
    return _base;
  }
  virtual MElement *getBaseElement()
  {
    if(!_base) _base = new MPoint(*this);
    return _base;
  }
};

#endif
