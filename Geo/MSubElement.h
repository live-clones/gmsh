// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   Frederic Duboeuf

#ifndef _MSUBELEMENT_H_
#define _MSUBELEMENT_H_

#include "GmshMessage.h"
#include "MElement.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MPoint.h"

// A sub tetrahedron, contained in another element
class MSubTetrahedron : public MTetrahedron
{
 protected:
  bool _owner;
  MElement* _orig;
  std::vector<MElement*> _parents;
  mutable MElement* _base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

 public:
  MSubTetrahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, int num=0, int part=0,
                  bool owner=false, MElement* orig=NULL)
    : MTetrahedron(v0, v1, v2, v3, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubTetrahedron(std::vector<MVertex*> v, int num=0, int part=0,
                  bool owner=false, MElement* orig=NULL)
    : MTetrahedron(v, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubTetrahedron(const MTetrahedron &tet, bool owner=false, MElement* orig=NULL)
    : MTetrahedron(tet), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  ~MSubTetrahedron();

  virtual int getTypeForMSH() const { return MSH_TET_SUB; }
  virtual const nodalBasis* getFunctionSpace(int order=-1) const;
  virtual const JacobianBasis* getJacobianFuncSpace(int order=-1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[], int order=-1) const;
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int order=-1) const;
  virtual void getHessShapeFunctions(double u, double v, double w, double s[][3][3], int order=-1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w, double s[][3][3][3], int order=-1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf, double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf, double jac[3][3])const;
  virtual double getJacobian(double u, double v, double w, double jac[3][3]) const;
  virtual double getPrimaryJacobian(double u, double v, double w, double jac[3][3]);
  virtual int getNumShapeFunctions() const;
  virtual int getNumPrimaryShapeFunctions();
  virtual const MVertex* getShapeFunctionNode(int i) const;
  virtual MVertex* getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v, double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v, double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false) { _orig = p; _owner = owner; }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement*> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement*> &parents, bool owner = false)
  {
    _parents = parents; _orig = _parents[0]; _owner = owner;
  }
  virtual const MElement *getBaseElement() const {if(!_base) _base=new MTetrahedron(*this); return _base;}
  virtual MElement *getBaseElement() {if(!_base) _base=new MTetrahedron(*this); return _base;}
};

// A sub triangle, contained in another element
class MSubTriangle : public MTriangle
{
 protected:
  bool _owner;
  MElement* _orig;
  std::vector<MElement*> _parents;
  mutable MElement* _base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

 public:
  MSubTriangle(MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0,
               bool owner=false, MElement* orig=NULL)
    : MTriangle(v0, v1, v2, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubTriangle(std::vector<MVertex*> v, int num=0, int part=0,
               bool owner=false, MElement* orig=NULL)
    : MTriangle(v, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubTriangle(const MTriangle &tri, bool owner=false, MElement* orig=NULL)
    : MTriangle(tri), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  ~MSubTriangle();

  virtual int getTypeForMSH() const { return MSH_TRI_SUB; }
  virtual const nodalBasis* getFunctionSpace(int order=-1) const;
  virtual const JacobianBasis* getJacobianFuncSpace(int order=-1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[], int order=-1) const;
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int order=-1) const;
  virtual void getHessShapeFunctions(double u, double v, double w, double s[][3][3], int order=-1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w, double s[][3][3][3], int order=-1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf, double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf, double jac[3][3])const;
  virtual double getJacobian(double u, double v, double w, double jac[3][3])const;
  virtual double getPrimaryJacobian(double u, double v, double w, double jac[3][3]);
  virtual int getNumShapeFunctions() const;
  virtual int getNumPrimaryShapeFunctions();
  virtual const MVertex* getShapeFunctionNode(int i) const;
  virtual MVertex* getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v, double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v, double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false) { _orig = p; _owner = owner; }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement*> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement*> &parents, bool owner = false)
  {
    _parents = parents; _orig = _parents[0]; _owner = owner;
  }
  virtual const MElement *getBaseElement() const {if(!_base) _base=new MTriangle(*this); return _base;}
  virtual MElement *getBaseElement() {if(!_base) _base=new MTriangle(*this); return _base;}
};

// A sub line, contained in another element
class MSubLine : public MLine
{
 protected:
  bool _owner;
  MElement* _orig;
  std::vector<MElement*> _parents;
  mutable MElement* _base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

 public:
  MSubLine(MVertex *v0, MVertex *v1, int num=0, int part=0,
           bool owner=false, MElement* orig=NULL)
    : MLine(v0, v1, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubLine(std::vector<MVertex*> v, int num=0, int part=0,
           bool owner=false, MElement* orig=NULL)
    : MLine(v, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubLine(const MLine &lin, bool owner=false, MElement* orig=NULL)
    : MLine(lin), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  ~MSubLine();

  virtual int getTypeForMSH() const { return MSH_LIN_SUB; }
  virtual const nodalBasis* getFunctionSpace(int order=-1) const;
  virtual const JacobianBasis* getJacobianFuncSpace(int order=-1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[], int order=-1) const;
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int order=-1) const;
  virtual void getHessShapeFunctions(double u, double v, double w, double s[][3][3], int order=-1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w, double s[][3][3][3], int order=-1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf, double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf, double jac[3][3])const;
  virtual double getJacobian(double u, double v, double w, double jac[3][3]) const;
  virtual double getPrimaryJacobian(double u, double v, double w, double jac[3][3]);
  virtual int getNumShapeFunctions() const;
  virtual int getNumPrimaryShapeFunctions();
  virtual const MVertex* getShapeFunctionNode(int i) const;
  virtual MVertex* getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v, double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v, double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false) { _orig = p; _owner = owner; }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement*> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement*> &parents, bool owner = false)
  {
    _parents = parents; _orig = _parents[0]; _owner = owner;
  }
  virtual const MElement *getBaseElement() const {if(!_base) _base=new MLine(*this); return _base;}
  virtual MElement *getBaseElement() {if(!_base) _base=new MLine(*this); return _base;}
};

// A sub point, contained in another element
class MSubPoint : public MPoint
{
 protected:
  bool _owner;
  MElement* _orig;
  std::vector<MElement*> _parents;
  mutable MElement* _base;

  int _pOrder;
  int _npts;
  IntPt *_pts;

 public:
  MSubPoint(MVertex *v0, int num=0, int part=0,
            bool owner=false, MElement* orig=NULL)
    : MPoint(v0, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubPoint(std::vector<MVertex*> v, int num=0, int part=0,
            bool owner=false, MElement* orig=NULL)
    : MPoint(v, num, part), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  MSubPoint(const MPoint &pt, bool owner=false, MElement* orig=NULL)
    : MPoint(pt), _owner(owner), _orig(orig), _base(0), _pOrder(-1), _npts(0), _pts(0) {}
  ~MSubPoint();

  virtual int getTypeForMSH() const { return MSH_PNT_SUB; }
  virtual const nodalBasis* getFunctionSpace(int order=-1) const;
  virtual const JacobianBasis* getJacobianFuncSpace(int order=-1) const;
  // the parametric coordinates are the coordinates in the local parent element
  virtual void getShapeFunctions(double u, double v, double w, double s[], int order=-1) const;
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int order=-1) const;
  virtual void getHessShapeFunctions(double u, double v, double w, double s[][3][3], int order=-1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w, double s[][3][3][3], int order=-1) const;
  virtual double getJacobian(const fullMatrix<double> &gsf, double jac[3][3]) const;
  virtual double getJacobian(const std::vector<SVector3> &gsf, double jac[3][3])const;
  virtual double getJacobian(double u, double v, double w, double jac[3][3]) const;
  virtual double getPrimaryJacobian(double u, double v, double w, double jac[3][3]);
  virtual int getNumShapeFunctions() const;
  virtual int getNumPrimaryShapeFunctions();
  virtual const MVertex* getShapeFunctionNode(int i) const;
  virtual MVertex* getShapeFunctionNode(int i);
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v, double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v, double &w) const;
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);

  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false) { _orig = p; _owner = owner; }
  virtual bool ownsParent() const { return _owner; }
  virtual std::vector<MElement*> getMultiParents() const { return _parents; }
  virtual void setMultiParent(std::vector<MElement*> &parents, bool owner = false)
  {
    _parents = parents; _orig = _parents[0]; _owner = owner;
  }
  virtual const MElement *getBaseElement() const {if(!_base) _base=new MPoint(*this); return _base;}
  virtual MElement *getBaseElement() {if(!_base) _base=new MPoint(*this); return _base;}
};

#endif

