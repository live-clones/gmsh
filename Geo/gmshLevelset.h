// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Gaetan Bricteux

#ifndef GMSH_LEVELSET_H
#define GMSH_LEVELSET_H

#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h> // for abs()
#include <vector>
#include "GmshMessage.h"
#include "fullMatrix.h"
#include "GModel.h"
#include "MVertex.h"
#include "GmshConfig.h"
#include "cartesian.h"
#include "simpleFunction.h"

#if defined(HAVE_ANN)
class ANNkd_tree;
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "OctreePost.h"
#endif

class mathEvaluator;

// PRIMITIVE LEVELSET
#define UNKNOWN 0
#define SPHERE 1
#define PLANE 2
#define GENCYLINDER 3
#define ELLIPS 4
#define CONE 5
#define QUADRIC 6
#define BOX 7
#define CYLINDER 8
#define CONROD 9
#define LSMESH 10
#define LSPOINTS 11 // don't define 'POINTS' as it's reserved by win32

// TOOLS
#define CUT 12
#define UNION 13
#define INTER 14
#define CRACK 15
#define DISK 16

class gLevelset;

class gLevelsetLessThan {
public:
  bool operator()(const gLevelset *l1, const gLevelset *l2) const;
};

class gLevelset : public simpleFunction<double> {
protected:
  // negative values of the levelset are inside the domain.
  static const short insideDomain = -1;
  // unique levelset id, must be greater than 0
  int tag_;
  // max tag in all levelsets
  static int maxTag_;
  // all levelsets
  static std::set<gLevelset *, gLevelsetLessThan> all_;

public:
  gLevelset(int tag = 0)
  {
    if(tag <= 0)
      tag_ = gLevelset::maxTag_++;
    else
      tag_ = tag;
  }
  gLevelset(const gLevelset &);
  virtual ~gLevelset() {}
  static gLevelset *find(int tag);
  static void add(gLevelset *l);
  virtual gLevelset *clone() const { return nullptr; }
  virtual double operator()(double x, double y, double z) const { return 0.; }
  bool isInsideDomain(const double &x, const double &y, const double &z) const
  {
    return this->operator()(x, y, z) * insideDomain > 0.;
  }
  bool isOutsideDomain(const double &x, const double &y, const double &z) const
  {
    return this->operator()(x, y, z) * insideDomain < 0.;
  }
  bool isOnBorder(const double &x, const double &y, const double &z) const
  {
    return this->operator()(x, y, z) == 0.;
  }
  virtual std::vector<gLevelset *> getChildren() const
  {
    return std::vector<gLevelset *>();
  }
  virtual double choose(double d1, double d2) const { return 0.; }
  virtual int type() const { return 0; }
  virtual bool isPrimitive() const { return false; }
  void setTag(int t) { tag_ = t; }
  virtual int getTag() const { return tag_; }
  void getPrimitives(std::vector<gLevelset *> &primitives);
  void getPrimitivesPO(std::vector<gLevelset *> &primitives);
  void getRPN(std::vector<gLevelset *> &gLsRPN);
  double H(const double &x, const double &y, const double &z) const
  {
    if(isInsideDomain(x, y, z) || isOnBorder(x, y, z)) return 1.0;
    return 0.0;
  }
  void print() const
  {
    printf("LS : ");
    switch(type()) {
    case SPHERE: printf("SPHERE"); break;
    case PLANE: printf("PLANE"); break;
    case GENCYLINDER: printf("GENCYLINDER"); break;
    case ELLIPS: printf("ELLIPS"); break;
    case CONE: printf("CONE"); break;
    case QUADRIC: printf("QUADRIC"); break;
    case BOX: printf("BOX"); break;
    case CYLINDER: printf("CYLINDER"); break;
    case CONROD: printf("CONROD"); break;
    case CUT: printf("CUT"); break;
    case UNION: printf("UNION"); break;
    case INTER: printf("INTER"); break;
    case LSMESH: printf("LSMESH"); break;
    case LSPOINTS: printf("LSPOINTS"); break;
    }
    printf(" Tag=%d\n", getTag());
  }
};

// PRIMITIVES

class gLevelsetPrimitive : public gLevelset {
public:
  gLevelsetPrimitive() : gLevelset() {}
  gLevelsetPrimitive(const gLevelsetPrimitive &lv) : gLevelset(lv) {}
  gLevelsetPrimitive(int tag) : gLevelset(tag) {}
  virtual double operator()(double x, double y, double z) const = 0;
  std::vector<gLevelset *> getChildren() const
  {
    std::vector<gLevelset *> p;
    return p;
  }
  double choose(double d1, double d2) const
  {
    Msg::Error("Cannot use function \"choose\" with a primitive!\n");
    return d1;
  }
  virtual int type() const = 0;
  virtual bool isPrimitive() const { return true; }
};

class gLevelsetSphere : public gLevelsetPrimitive {
protected:
  double xc, yc, zc, r;

public:
  gLevelsetSphere(const double &x, const double &y, const double &z,
                  const double &R, int tag = 0);
  virtual double operator()(double x, double y, double z) const
  {
    if(r >= 0.)
      return sqrt((xc - x) * (xc - x) + (yc - y) * (yc - y) +
                  (zc - z) * (zc - z)) -
             r;
    return (-r - sqrt((xc - x) * (xc - x) + (yc - y) * (yc - y) +
                      (zc - z) * (zc - z)));
  }
  void gradient(double x, double y, double z, double &dfdx, double &dfdy,
                double &dfdz) const;
  void hessian(double x, double y, double z, double &dfdxx, double &dfdxy,
               double &dfdxz, double &dfdyx, double &dfdyy, double &dfdyz,
               double &dfdzx, double &dfdzy, double &dfdzz) const;
  int type() const { return SPHERE; }
};

class gLevelsetPlane : public gLevelsetPrimitive {
protected:
  double a, b, c, d;

public:
  // define the plane _a*x+_b*y+_c*z+_d, with outward normal (a,b,c)
  gLevelsetPlane(const double _a, const double _b, const double _c,
                 const double _d, int tag = 0)
    : gLevelsetPrimitive(tag), a(_a), b(_b), c(_c), d(_d)
  {
  }
  // define the plane passing through the point pt and with outward normal norm
  gLevelsetPlane(const std::vector<double> &pt, const std::vector<double> &norm,
                 int tag = 0);
  gLevelsetPlane(const double *pt, const double *norm, int tag = 0);
  // define the plane passing through the 3 points pt1,pt2,pt3 and with outward
  // normal (pt1,pt2)x(pt1,pt3)
  gLevelsetPlane(const double *pt1, const double *pt2, const double *pt3,
                 int tag = 0);
  // copy constructor
  gLevelsetPlane(const gLevelsetPlane &lv);
  virtual gLevelset *clone() const { return new gLevelsetPlane(*this); }
  // return negative value inward and positive value outward
  virtual double operator()(double x, double y, double z) const
  {
    return a * x + b * y + c * z + d;
  }
  int type() const { return PLANE; }
};

class gLevelsetPoints : public gLevelsetPrimitive {
protected:
  fullMatrix<double> points;
  fullMatrix<double> surf;
  fullMatrix<double> matAInv;
  double delta;
  std::map<SPoint3, double> mapP;
  fullMatrix<double> generateRbfMat(int p, int index,
                                    const fullMatrix<double> &nodes1,
                                    const fullMatrix<double> &nodes2) const;
  void RbfOp(int p, int index, const fullMatrix<double> &cntrs,
             const fullMatrix<double> &nodes, fullMatrix<double> &D,
             bool isLocal = false) const;
  void evalRbfDer(int p, int index, const fullMatrix<double> &cntrs,
                  const fullMatrix<double> &nodes,
                  const fullMatrix<double> &fValues,
                  fullMatrix<double> &fApprox, bool isLocal = false) const;
  void setup_level_set(const fullMatrix<double> &cntrs,
                       fullMatrix<double> &level_set_nodes,
                       fullMatrix<double> &level_set_funvals);

public:
  // define the data points
  gLevelsetPoints(fullMatrix<double> &_centers, int tag = 0);
  // copy constructor
  gLevelsetPoints(const gLevelsetPoints &lv);
  virtual gLevelset *clone() const { return new gLevelsetPoints(*this); }
  // return negative value inward and positive value outward
  virtual double operator()(double x, double y, double z) const;
  void computeLS(std::vector<MVertex *> &vert);
  int type() const { return LSPOINTS; }
};

class gLevelsetQuadric : public gLevelsetPrimitive {
protected:
  double A[3][3], B[3], C;
  void translate(const double transl[3]);
  void rotate(const double rotate[3][3]);
  void computeRotationMatrix(const double dir[3], double t[3][3]);
  void computeRotationMatrix(const double dir1[3], const double dir2[3],
                             double t[3][3]);
  void Ax(const double x[3], double res[3], double fact = 1.0);
  void xAx(const double x[3], double &res, double fact = 1.0);
  void init();

public:
  gLevelsetQuadric(int tag = 0) : gLevelsetPrimitive(tag) { init(); }
  gLevelsetQuadric(const gLevelsetQuadric &);
  virtual ~gLevelsetQuadric() {}
  double operator()(double x, double y, double z) const;
  virtual int type() const = 0;
};

class gLevelsetGenCylinder : public gLevelsetQuadric {
public:
  gLevelsetGenCylinder(const double *pt, const double *dir, const double &R,
                       int tag = 0);
  gLevelsetGenCylinder(const gLevelsetGenCylinder &);
  virtual gLevelset *clone() const { return new gLevelsetGenCylinder(*this); }
  int type() const { return GENCYLINDER; }
};

class gLevelsetEllipsoid : public gLevelsetQuadric {
public:
  gLevelsetEllipsoid(const double *pt, const double *dir, const double &a,
                     const double &b, const double &c, int tag = 0);
  gLevelsetEllipsoid(const gLevelsetEllipsoid &);
  virtual gLevelset *clone() const { return new gLevelsetEllipsoid(*this); }
  int type() const { return ELLIPS; }
};

class gLevelsetCone : public gLevelsetQuadric {
public:
  gLevelsetCone(const double *pt, const double *dir, const double &angle,
                int tag = 0);
  gLevelsetCone(const gLevelsetCone &);
  virtual gLevelset *clone() const { return new gLevelsetCone(*this); }
  int type() const { return CONE; }
};

class gLevelsetGeneralQuadric : public gLevelsetQuadric {
public:
  gLevelsetGeneralQuadric(const double *pt, const double *dir, const double &x2,
                          const double &y2, const double &z2, const double &z,
                          const double &c, int tag = 0);
  gLevelsetGeneralQuadric(const gLevelsetGeneralQuadric &);
  virtual gLevelset *clone() const
  {
    return new gLevelsetGeneralQuadric(*this);
  }
  int type() const { return QUADRIC; }
};

class gLevelsetPopcorn : public gLevelsetPrimitive {
  double A;
  double sigma;
  double r0;
  double xc, yc, zc;

public:
  gLevelsetPopcorn(double xc, double yc, double zc, double r0, double A,
                   double sigma, int tag = 0);
  ~gLevelsetPopcorn() {}
  double operator()(double x, double y, double z) const;
  int type() const { return UNKNOWN; }
};

// creates the 2D (-approximate- signed distance !) level set corresponding to
// the "shamrock-like" iso-zero from Dobrzynski and Frey, "Anisotropic delaunay
// mesh adaptation for unsteady simulations", 17th International Meshing
// Rountable (2008)(177–194)
class gLevelsetShamrock : public gLevelsetPrimitive {
  double xmid, a, b;
  int c;
  std::vector<double> iso_x, iso_y;

public:
  gLevelsetShamrock(double xmid, double ymid, double zmid, double a, double b,
                    int c = 3, int tag = 0);
  ~gLevelsetShamrock() {}
  double operator()(double x, double y, double z) const;
  int type() const { return UNKNOWN; }
};

class gLevelsetMathEval : public gLevelsetPrimitive {
  mathEvaluator *_expr;

public:
  gLevelsetMathEval(const std::string &f, int tag = 0);
  ~gLevelsetMathEval();
  double operator()(double x, double y, double z) const;
  int type() const { return UNKNOWN; }
};

class gLevelsetMathEvalAll : public gLevelsetPrimitive {
  mathEvaluator *_expr;

public:
  gLevelsetMathEvalAll(std::vector<std::string> f, int tag = 0);
  ~gLevelsetMathEvalAll();
  double operator()(double x, double y, double z) const;
  void gradient(double x, double y, double z, double &dfdx, double &dfdy,
                double &dfdz) const;
  void hessian(double x, double y, double z, double &dfdxx, double &dfdxy,
               double &dfdxz, double &dfdyx, double &dfdyy, double &dfdyz,
               double &dfdzx, double &dfdzy, double &dfdzz) const;
  int type() const { return UNKNOWN; }
};

class gLevelsetSimpleFunction : public gLevelsetPrimitive {
  simpleFunction<double> *_f;

public:
  gLevelsetSimpleFunction(simpleFunction<double> *f, int tag = 0) { _f = f; }
  ~gLevelsetSimpleFunction() {}
  double operator()(double x, double y, double z) const
  {
    return (*_f)(x, y, z);
  }
  int type() const { return UNKNOWN; }
};

#if defined(HAVE_ANN)
class gLevelsetDistMesh : public gLevelsetPrimitive {
  const int _nbClose;
  std::vector<GEntity *> _entities;
  std::vector<MVertex *> _vertices;
  std::multimap<MVertex *, MElement *> _v2e;
  ANNkd_tree *_kdtree;

public:
  gLevelsetDistMesh(GModel *gm, const std::string &physical, int nbClose = 5,
                    int tag = 0);
  double operator()(double x, double y, double z) const;
  ~gLevelsetDistMesh();
  int type() const { return LSMESH; }
};
#endif

#if defined(HAVE_POST)
class gLevelsetPostView : public gLevelsetPrimitive {
  int _viewIndex;
  OctreePost *_octree;

public:
  gLevelsetPostView(int index, int tag = 0);
  ~gLevelsetPostView()
  {
    if(_octree) delete _octree;
  }
  double operator()(double x, double y, double z) const;
  int type() const { return UNKNOWN; }
};
#endif

class gLevelsetNACA00 : public gLevelsetPrimitive {
  double _x0, _y0, _c, _t;

public:
  gLevelsetNACA00(double x0, double y0, double c, double t);
  ~gLevelsetNACA00() {}
  double operator()(double x, double y, double z) const;
  void gradient(double x, double y, double z, double &dfdx, double &dfdy,
                double &dfdz) const;
  void hessian(double x, double y, double z, double &dfdxx, double &dfdxy,
               double &dfdxz, double &dfdyx, double &dfdyy, double &dfdyz,
               double &dfdzx, double &dfdzy, double &dfdzz) const;
  int type() const { return UNKNOWN; }

private:
  void getClosestBndPoint(const double x, const double y, const double z,
                          double &xb, double &yb, double &curvRad,
                          bool &in) const;
};

class gLevelsetYarn : public gLevelsetPrimitive {
  // double minorAxis, majorAxis;
  // int typeLs;
  std::vector<GEntity *> entities;

public:
  gLevelsetYarn(int dim, int phys, double minA, double majA, int type,
                int tag = 0);
  ~gLevelsetYarn() {}
  double operator()(double x, double y, double z) const;
  int type() const { return UNKNOWN; }
};

// TOOLS

class gLevelsetTools : public gLevelset {
protected:
  std::vector<gLevelset *> children;
  bool _delChildren; // flag to delete only if called from gmsh Parser
public:
  gLevelsetTools(int tag = 0) : gLevelset(tag) {}
  gLevelsetTools(const std::vector<gLevelset *> &p, bool delC = false,
                 int tag = 0)
    : gLevelset(tag)
  {
    children = p;
    _delChildren = delC;
  }
  gLevelsetTools(const gLevelsetTools &);
  virtual ~gLevelsetTools()
  {
    if(_delChildren) {
      for(int i = 0; i < (int)children.size(); i++) delete children[i];
    }
  }
  double operator()(double x, double y, double z) const
  {
    double d = (*children[0])(x, y, z);
    for(int i = 1; i < (int)children.size(); i++) {
      double dt = (*children[i])(x, y, z);
      d = choose(d, dt);
    }
    return d;
  }
  std::vector<gLevelset *> getChildren() const
  {
    if(children.size() != 1) return children;
    return children[0]->getChildren();
  }
  virtual double choose(double d1, double d2) const = 0;
  virtual int type2() const = 0;
  virtual int type() const
  {
    if(children.size() != 1) return type2();
    return children[0]->type();
  }
  virtual bool isPrimitive() const
  {
    if(children.size() != 1) return false;
    return children[0]->isPrimitive();
  }
  int getTag() const
  {
    if(children.size() != 1) return tag_;
    return children[0]->getTag();
  }
};

class gLevelsetReverse : public gLevelset {
protected:
  gLevelset *ls;

public:
  gLevelsetReverse(gLevelset *p, int tag = 0) : gLevelset(tag), ls(p) {}
  double operator()(double x, double y, double z) const
  {
    return -(*ls)(x, y, z);
  }
  std::vector<gLevelset *> getChildren() const { return ls->getChildren(); }
  virtual bool isPrimitive() const { return ls->isPrimitive(); }
  virtual double choose(double d1, double d2) const
  {
    return -ls->choose(d1, d2);
  }
  virtual int type() const { return ls->type(); }
  int getTag() const { return ls->getTag(); }
};

// This levelset takes the first levelset in the list as the object and the
// others as tools that cut it
class gLevelsetCut : public gLevelsetTools {
public:
  gLevelsetCut(const std::vector<gLevelset *> &p, bool delC = false,
               int tag = 0)
    : gLevelsetTools(p, delC, tag)
  {
  }
  double choose(double d1, double d2) const
  {
    return (d1 > -d2) ? d1 : -d2; // greater of d1 and -d2
  }
  gLevelsetCut(const gLevelsetCut &lv) : gLevelsetTools(lv) {}
  virtual gLevelset *clone() const { return new gLevelsetCut(*this); }
  int type2() const { return CUT; }
};

// This levelset takes the minimum
class gLevelsetUnion : public gLevelsetTools {
public:
  gLevelsetUnion(const std::vector<gLevelset *> &p, bool delC = false,
                 int tag = 0)
    : gLevelsetTools(p, delC, tag)
  {
  }
  gLevelsetUnion(const gLevelsetUnion &lv) : gLevelsetTools(lv) {}
  virtual gLevelset *clone() const { return new gLevelsetUnion(*this); }

  double choose(double d1, double d2) const
  {
    return (d1 < d2) ? d1 : d2; // lesser of d1 and d2
  }
  int type2() const { return UNION; }
};

// This levelset takes the maximum
class gLevelsetIntersection : public gLevelsetTools {
public:
  gLevelsetIntersection(const std::vector<gLevelset *> &p, bool delC = false,
                        int tag = 0)
    : gLevelsetTools(p, delC, tag)
  {
  }
  gLevelsetIntersection(const gLevelsetIntersection &lv) : gLevelsetTools(lv) {}
  virtual gLevelset *clone() const { return new gLevelsetIntersection(*this); }

  double choose(double d1, double d2) const
  {
    return (d1 > d2) ? d1 : d2; // greater of d1 and d2
  }
  int type2() const { return INTER; }
};

// Crack defined by a normal and a tangent levelset
class gLevelsetCrack : public gLevelsetTools {
public:
  gLevelsetCrack(std::vector<gLevelset *> p, bool delC = false, int tag = 0)
    : gLevelsetTools(tag)
  {
    if(p.size() != 2) printf("Error : gLevelsetCrack needs 2 levelsets\n");
    children.push_back(p[0]);
    children.push_back(new gLevelsetReverse(p[0]));
    if(p[1]) children.push_back(p[1]);
    _delChildren = delC;
  }
  double choose(double d1, double d2) const
  {
    return (d1 > d2) ? d1 : d2; // greater of d1 and d2
  }
  int type2() const { return CRACK; }
};

// IMPROVED LEVELSET

class gLevelsetImproved : public gLevelset {
protected:
  gLevelset *Ls;

public:
  gLevelsetImproved(int tag = 0) : gLevelset(tag) {}
  gLevelsetImproved(const gLevelsetImproved &lv);
  double operator()(double x, double y, double z) const
  {
    return (*Ls)(x, y, z);
  }
  std::vector<gLevelset *> getChildren() const { return Ls->getChildren(); }
  double choose(double d1, double d2) const { return Ls->choose(d1, d2); }
  virtual int type() const = 0;
  virtual bool isPrimitive() const { return Ls->isPrimitive(); }
};

class gLevelsetBox : public gLevelsetImproved {
public:
  // create a box with parallel faces :
  //    pt is a corner of the box,
  //    dir1 is the direction of the first edge starting from pt,
  //    dir2 is the direction of the second edge starting from pt,
  //    dir3 is the direction of the third edge starting from pt,
  //    a is the length of the first edge starting from pt,
  //    b is the length of the second edge starting from pt,
  //    c is the length of the third edge starting from pt.
  // tags of the faces are : face normal to dir3 and not including pt : tag+0
  //                         face normal to dir3 and     including pt : tag+1
  //                         face normal to dir2 and     including pt : tag+2
  //                         face normal to dir2 and not including pt : tag+3
  //                         face normal to dir1 and not including pt : tag+4
  //                         face normal to dir1 and     including pt : tag+5
  gLevelsetBox(const double *pt, const double *dir1, const double *dir2,
               const double *dir3, const double &a, const double &b,
               const double &c, int tag = 0);
  // create a box with the 8 vertices (pt1,...,pt8).
  // check if the faces are planar.
  // tags of the faces are : face(pt5,pt6,pt7,pt8) : tag+0
  //                         face(pt1,pt4,pt3,pt2) : tag+1
  //                         face(pt1,pt2,pt6,pt5) : tag+2
  //                         face(pt3,pt4,pt8,pt7) : tag+3
  //                         face(pt2,pt3,pt7,pt6) : tag+4
  //                         face(pt1,pt5,pt8,pt4) : tag+5
  gLevelsetBox(const double *pt1, const double *pt2, const double *pt3,
               const double *pt4, const double *pt5, const double *pt6,
               const double *pt7, const double *pt8, int tag = 0);
  gLevelsetBox(const gLevelsetBox &);
  virtual gLevelset *clone() const { return new gLevelsetBox(*this); }
  int type() const { return BOX; }
};

class gLevelsetCylinder : public gLevelsetImproved {
public:
  // create a cylinder : pt is the point in the middle of the cylinder base,
  //                     dir is the direction of the cylinder axis,
  //                     R is the outer radius of the cylinder,
  //                     H is the height of the cylinder.
  // tags of the faces are : exterior face :             tag+0
  //                         plane face including pt :   tag+1
  //                         plane face opposite to pt : tag+2
  gLevelsetCylinder(const std::vector<double> &pt,
                    const std::vector<double> &dir, const double &R,
                    const double &H, int tag = 0);
  gLevelsetCylinder(const double *pt, const double *dir, const double &R,
                    const double &H, int tag = 0);
  // create a cylinder : pt is the point in the middle of the cylinder base,
  //                     dir is the direction of the cylinder axis,
  //                     R is the outer radius of the cylinder,
  //                     r is the inner radius of the cylinder,
  //                     H is the height of the cylinder.
  // tags of the faces are : exterior face :             tag+0
  //                         plane face including pt :   tag+1
  //                         plane face opposite to pt : tag+2
  //                         interior face :             tag+3
  gLevelsetCylinder(const double *pt, const double *dir, const double &R,
                    const double &r, const double &H, int tag = 0);
  gLevelsetCylinder(const gLevelsetCylinder &);
  virtual gLevelset *clone() const { return new gLevelsetCylinder(*this); }
  int type() const { return CYLINDER; }
};

class gLevelsetConrod : public gLevelsetImproved {
public:
  // create a connecting rod :
  //    pt is the point in the middle of the first bore,
  //    dir1 is the direction of the rod,
  //    dir2 is the direction of the axis of the bore,
  //    H1 is height of the first cylinder,
  //    H2 is the height of the second cylinder,
  //    H3 is the height of the rod,
  //    R1 is the outer radius of the first cylinder,
  //    r1 is the inner radius of the first cylinder,
  //    R2 is the outer radius of the second cylinder,
  //    r2 is the inner radius of the second cylinder,
  //    L1 is the width of the rod in the plane passing through the middle
  //       of the first bore,
  //    L2 is the width of the rod in the plane passing through the middle
  //       of the second bore,
  //    E is the distance between the axis of the cylinders.
  // tags of the faces are : bottom face (+dir2) of the bore :      tag+2
  //                         top    face (-dir2) of the bore :      tag+3
  //                         rear   face (-dir1xdir2) of the bore : tag+4
  //                         front  face (+dir1xdir2) of the bore : tag+5
  //                         exterior face of the first cylinder :  tag+6
  //                         bottom   face of the first cylinder :  tag+7
  //                         top      face of the first cylinder :  tag+8
  //                         exterior face of the second cylinder : tag+9
  //                         bottom   face of the second cylinder : tag+10
  //                         top      face of the second cylinder : tag+11
  //                         interior face of the first  cylinder : tag+12
  //                         interior face of the second cylinder : tag+13
  gLevelsetConrod(const double *pt, const double *dir1, const double *dir2,
                  const double &H1, const double &H2, const double &H3,
                  const double &R1, const double &r1, const double &R2,
                  const double &r2, const double &L1, const double &L2,
                  const double &E, int tag = 0);
  gLevelsetConrod(const gLevelsetConrod &);
  virtual gLevelset *clone() const { return new gLevelsetConrod(*this); }
  int type() const { return CONROD; }
};

#endif
