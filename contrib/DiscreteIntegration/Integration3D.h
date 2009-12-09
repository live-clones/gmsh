#ifndef _INTEGRATION3D_H_
#define _INTEGRATION3D_H_

#include <list>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include "DILevelset.h"

// Element type
#define DI_LIN  1
#define DI_TRI  2
#define DI_QUA  3
#define DI_TET  4
#define DI_HEX  5

class DI_Point;
class DI_IntegrationPoint;
class DI_CuttingPoint;
class DI_PointLessThan;
class DI_Element;
class DI_Line;              // : public DI_Element
class DI_Triangle;          // : public DI_Element
class DI_Quad;              // : public DI_Element
class DI_Tetra;             // : public DI_Element
class DI_Hexa;              // : public DI_Element
class DI_QualError;

// --------------------------------------------------------------------------------------------------
class DI_Point
{
 protected :
  // coordinates of the point
  double x_, y_, z_;
  // vector containing the levelset values of the point
  std::vector<double> Ls;
 public :
  // constructors
  DI_Point () : x_(0), y_(0), z_(0) {}
  DI_Point (double x, double y, double z) : x_(x), y_(y), z_(z) {}
  DI_Point (double x, double y, double z, gLevelset *ls);
  DI_Point (double x, double y, double z, const double ls) : x_(x), y_(y), z_(z) {addLs(ls);}
  DI_Point (double x, double y, double z, const DI_Element *e,
            const std::vector<const gLevelset *> &RPNi) : x_(x), y_(y), z_(z) {computeLs(e, RPNi);}
  DI_Point(const DI_Point &p) : x_(p.x()), y_(p.y()), z_(p.z()) {Ls.clear(); Ls = p.Ls;}
  // assignment
  DI_Point & operator=(const DI_Point & rhs);
  // destructor
  virtual ~DI_Point () {}
  // add a levelset value (adjusted to 0 if ls<ZERO_LS_TOL) into the vector Ls
  void addLs (const double ls);
  // add a levelset value evaluated into the element e
  void addLs (const DI_Element *e);
  // choose the value of the levelset among the last two levelset values of Ls,
  // delete the last two values and add the chosen one
  void chooseLs (const gLevelset *Lsi);
  // clear Ls and add the levelset values computed with RPNi
  void computeLs (const DI_Element *e, const std::vector<const gLevelset *> &RPNi);
  // clear Ls and add the levelset value computed with ls
  void computeLs (const gLevelset *ls);
  // remove the last value in Ls and add ls
  inline void changeLs (const double ls) {Ls.pop_back(); addLs(ls);}
  // change the coordinates
  inline void move (double x, double y, double z) {x_ = x; y_ = y; z_ = z;}
  // return true if the coordinates of this and p are equal (with a tolerance)
  bool equal(const DI_Point *p) const;
  // return the coordinates
  inline double x () const {return x_;}
  inline double y () const {return y_;}
  inline double z () const {return z_;}
  // return the last value of Ls
  inline double ls() const {return Ls.back();}
  // return the ith value of Ls
  inline double ls(int i) const {return Ls[i];}
  // return the size of the vector of ls values
  inline int sizeLs() const {return Ls.size();}
  // clear the values in Ls
  inline void clearLs() {Ls.clear();}
  // return the position of the point with respect to the domain depending on the last value in Ls
  inline bool isInsideDomain  () const {return Ls.back() < 0.;}
  inline bool isOutsideDomain () const {return Ls.back() > 0.;}
  inline bool isOnBorder      () const {return Ls.back() == 0.;}
  inline int lsTag() const {
    if(isInsideDomain()) return 1;
    if(isOutsideDomain()) return -1;
    return 0;
  }
  // print the coordiantes
  virtual void print() const {printf("Point (%g,%g,%g)\n", x_, y_, z_);}
  virtual void printls() const {
    printf("Point (%g,%g,%g) ls=(", x_, y_, z_);
    for(int i = 0; i < (int)Ls.size(); i++) printf("%g,", Ls[i]);
    printf(")\n");
  }
  typedef std::set<DI_Point*,DI_PointLessThan> Container;
};
// --------------------------------------------------------------------------------------------------
class DI_IntegrationPoint
{
  // coordinates
  double x_, y_, z_;
  // local coordinates
  double xl_, yl_, zl_;
  // weight and levelset (computed inside the sub-elements)
  double weight_, ls_;
 public:
  // constructor
  DI_IntegrationPoint (double x, double y, double z, double weight)
    : x_(x), y_(y), z_(z), xl_(0), yl_(0), zl_(0), weight_(weight) {}
  // add local coordinates
  inline void addLocC (double xl, double yl, double zl) {xl_ = xl; yl_ = yl; zl_ = zl;}
  // change the coordinates
  inline void move (double x, double y, double z) {x_ = x; y_ = y; z_ = z;}
  // change the value of ls_
  inline void setLs (double lsT) {ls_ = lsT;}
  // clear Ls and add the levelset values computed with RPNi
  void computeLs (const DI_Element *e, const std::vector<const gLevelset *> &RPNi);
  // change the value of weight_
  inline void setWeight (double w) {weight_ = w;}
  // return the coordinates
  inline double x () const {return x_;}
  inline double y () const {return y_;}
  inline double z () const {return z_;}
  // return the levelset value
  inline double ls() const {return ls_;}
  // return the local coordinates
  inline double xl() const {return xl_;}
  inline double yl() const {return yl_;}
  inline double zl() const {return zl_;}
  // return the position of the point with respect to the domain depending on ls_
  bool isInsideDomain  () const {return ls_ < 0.;}
  bool isOutsideDomain () const {return ls_ > 0.;}
  bool isOnBorder () const {return ls_ == 0.;}
  // return the weight
  inline double weight () const {return weight_;}
  // print the coordinates, the local coordinates, the weight and the levelset value
  void print() const {
    printf("IP : x=(%g,%g,%g) xl=(%g,%g,%g) w=%g ls=%g\n", x_, y_, z_, xl_, yl_, zl_, weight_, ls_); }
};

// --------------------------------------------------------------------------------------------------
class DI_CuttingPoint : public DI_Point
{
  double xl_, yl_, zl_;
 public:
  DI_CuttingPoint (const DI_Point *pt);
  inline void addLocC (double xl, double yl, double zl) {xl_ = xl; yl_ = yl; zl_ = zl;}
  inline double xl() const {return xl_;}
  inline double yl() const {return yl_;}
  inline double zl() const {return zl_;}
  void print() const {
    printf("CP : x=(%g,%g,%g) xl=(%g,%g,%g)\n", x_, y_, z_, xl_, yl_, zl_);
  }
  void printls() const {
    printf("CP : x=(%g,%g,%g) xl=(%g,%g,%g) ls=(", x_, y_, z_, xl_, yl_, zl_);
    for(int i = 0; i < (int)Ls.size(); i++) printf("%g,", Ls[i]);
    printf(")\n");
  }
};

// --------------------------------------------------------------------------------------------------
class DI_PointLessThan
{
 public:
  static double tolerance;
  bool operator()(const DI_Point *p1, const DI_Point *p2) const;
};

// --------------------------------------------------------------------------------------------------
// compute the length of a line
static inline double LineLength(double x1, double y1, double z1, double x2, double y2, double z2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}
static inline double LineLength (const DI_Point *p1, const DI_Point *p2)
{
  return LineLength(p1->x(), p1->y(), p1->z(), p2->x(), p2->y(), p2->z());
}
// compute the surface of a triangle
static inline double TriSurf(double x1, double y1, double z1, double x2, double y2, double z2,
                             double x3, double y3, double z3)
{
  return 0.5 * sqrt((x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2)) *
                    (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2))
                  + (y1 * (z2 - z3) - y2 * (z1 - z3) + y3 * (z1 - z2)) *
                    (y1 * (z2 - z3) - y2 * (z1 - z3) + y3 * (z1 - z2))
                  + (z1 * (x2 - x3) - z2 * (x1 - x3) + z3 * (x1 - x2)) *
                    (z1 * (x2 - x3) - z2 * (x1 - x3) + z3 * (x1 - x2)));
}
static inline double TriSurf (const DI_Point *p1, const DI_Point *p2, const DI_Point *p3)
{
  return TriSurf(p1->x(), p1->y(), p1->z(), p2->x(), p2->y(), p2->z(), p3->x(), p3->y(), p3->z());
}

// compute the volume of a tetrahedron (base in ccw order to have positive volume)
static inline double TetraVol(double x1, double y1, double z1, double x2, double y2, double z2,
                              double x3, double y3, double z3, double x4, double y4, double z4)
{
  double vol = ((x2 - x1) * ((y3 - y1) * (z4 - z1) - (y4 - y1) * (z3 - z1))
              - (x3 - x1) * ((y2 - y1) * (z4 - z1) - (y4 - y1) * (z2 - z1))
              + (x4 - x1) * ((y2 - y1) * (z3 - z1) - (y3 - y1) * (z2 - z1))) / 6.;
  if(vol < 0) {printf("TET HAS NEGATIVE VOLUME = %g\n", vol);}
  return vol;
}
static inline double TetraVol(const DI_Point *p1, const DI_Point *p2,
                              const DI_Point *p3, const DI_Point *p4)
{
  return TetraVol (p1->x(), p1->y(), p1->z(), p2->x(), p2->y(), p2->z(),
                   p3->x(), p3->y(), p3->z(), p4->x(), p4->y(), p4->z());
}

// --------------------------------------------------------------------------------------------------
class DI_Element
{
 protected:
  int lsTag_;       // tag to specify the belonging to a levelset (default : -1)
                    // domain elements : -1 = outside / +1 = inside
                    // interface elements : tag of the levelset that created the element
                    //                      -1 = out of the domain border
  DI_Point *pts_;  // vertices
  DI_Point *mid_;  // middle vertices
  int polOrder_;    // polynomial order of the shape functions
  double integral_; // surface for 2D elements, volume for 3D elements
 public:
  // constructor
  DI_Element () : lsTag_(-1), polOrder_(1), integral_(0.) {pts_ = NULL; mid_ = NULL;}
  DI_Element (const DI_Element &cp); // copy constructor
  // assignment
  DI_Element & operator= (const DI_Element &rhs);
  // destructor
  virtual ~DI_Element(){
    if(pts_) delete [] pts_;
    if(mid_) delete [] mid_;
  }
  // return type
  virtual int type() const = 0;
  // return the dimension of the element
  virtual int getDim() const = 0;
  // return number of vertices
  virtual int nbVert() const = 0;
  // return the number of middle points
  virtual int nbMid() const = 0;
  // return number of edges
  virtual int nbEdg() const = 0;
  // return the indices of the 2 points of the eth edge
  virtual void vert(const int e, int &s1, int &s2) const = 0;
  // return the indices of eth middle node and the number of indices n
  virtual void midV(const int e, int *s, int &n) const = 0;
  // return the polynomial order of the shape functions
  int getPolynomialOrder() const {return polOrder_;}
  // set the polynomial order of the shape functions
  void setPolynomialOrder(int o);
  void setPolynomialOrder(int o, const DI_Element *e, const std::vector<const gLevelset *> &RPNi);
  // return tag
  int lsTag() const {return lsTag_;}
  // return the position of the point with respect to the domain depending on ls_
  bool isInsideDomain  () const {return lsTag_ > 0.;}
  bool isOutsideDomain () const {return lsTag_ < 0.;}
  bool isOnBorder () const {return lsTag_ > 0.;}
  // set tag
  void setLsTag(const int tag) {lsTag_ = tag;}
  // return the integral (surface for 2D elements, volume for 3D elements)
  double integral() const {return integral_;}
  // compute the integral (surface for 2D elements, volume for 3D elements)
  virtual void computeIntegral() = 0;
  // return the integral (surface for 2D elements, volume for 3D elements) of the reference element
  virtual double refIntegral() const = 0;
  // add a levelset value to each point
  void addLs (const double *ls);
  // evaluate the levelset value at each point and add it to each point
  void addLs (const DI_Element *e);
  // compute the level set at each vertex of the real element e (same type as this)
  // or take i from the map if exist
  // and add it to the vertices
  void addLs (const DI_Element *e, const gLevelset *Ls);
  void addLs (const DI_Element *e, const gLevelset *Ls, int iLs, double **nodeLs);
  // clear the levelset of the vertices
  void clearLs();
  // compute the levelset values at the mid edge points and add a quadratic edge,
  // defined with a mid-edge node at xm on the edgeth edge.
  // if xm is too close from the middle of the edgeth edge, do not add the quadratic edge
  // if the new quadratic edge create a negative detJ, do not add the quadratic edge and return false
  bool addQuadEdge (int edge, DI_Point *xm, const DI_Element *e,
                    const std::vector<const gLevelset *> &RPNi);
  // return true if the point pt is inside the element
  bool contain (const DI_Point *pt) const;
  // return true if the element e is inside the element
  // (works only for triangles and quadrangles for the moment)
  bool contain (const DI_Element *e) const;
  // choose the levelset for each point
  void chooseLs (const gLevelset *Lsi);
  // map the point pt with local coordinates from the reference element into the element
  void mappingP (DI_Point *pt) const;
  // map the DI_IntegrationPoint in with local coordinates from the reference element into the element
  void mappingIP (DI_IntegrationPoint *in) const;
  // map the DI_CuttingPoint cp with local coordinates from the reference element into the element
  void mappingCP (DI_CuttingPoint *cp) const;
  // map the DI_Element el with local coordinates from the reference element into the element
  void mappingEl (DI_Element *el) const;
  // push into ip the reference integration points to integrate exactly a polynom of order polOrder
  virtual void getRefIntegrationPoints (const int polOrder,
                                        std::vector<DI_IntegrationPoint *> &ip) const = 0;
  // push into ip the integration points to integrate exactly a polynom of order polOrder
  // over the element
  // the local coordinates of the integration points are computed with loc
  // the levelset value at the integration points is computed with e and RPN
  void integrationPoints (const int polyOrder, const DI_Element *loc, const DI_Element *e,
                          const std::vector<const gLevelset *> &RPN,
                          std::vector<DI_IntegrationPoint *> &ip) const;
  // compute the cutting points on the edges with the last ls in the element
  void getCuttingPoints (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                         std::vector<DI_CuttingPoint*> &cp) const;
  // return the ith point
  virtual DI_Point* pt (int i) const = 0;
  // return the ith middle point
  inline DI_Point* mid (int i) const {return &mid_[i];}
  // return the coordinates of the ith point
  virtual double x (int i) const = 0;
  virtual double y (int i) const = 0;
  virtual double z (int i) const = 0;
  // return the last levelset value of the ith point
  virtual double ls (int i) const = 0;
  // return the jth levelset value of the ith point
  virtual double ls (int i, int j) const = 0;
  // return the number of levelset values of the points
  inline int sizeLs() const {return pts_[0].sizeLs();}
  // return the interpolating nodal shape functions evaluated at point (u,v,w)
  // in parametric coordinates (if order = -1, use the polynomial order of the element)
  virtual void getShapeFunctions (double u, double v, double w, double s[], int order = -1) const = 0;
  // compute the coordinates in the element from the local coordinates (x,y,z)
  void evalC (const double x, const double y, const double z, double *ev, int order = -1) const;
  // evaluate the levelset at the local coordinates
  // with the ith levelset value in the vector Ls of the points
  // if i=-1, use the last value in Ls
  double evalLs (const double x, const double y, const double z, int iLs = -1, int order = -1) const;
  // return the gradient of the shape functions evaluated at point (u,v,w) in the reference element
  virtual void getGradShapeFunctions (const double u, const double v, const double w,
                                      double s[][3], int order = -1) const = 0;
  // compute the determinant of the jacobian at the point (u,v,w) in the reference element
  double detJ (const double u, const double v, const double w) const;
  // compute DetJ at each point, return false if 2 values have opposite sign
  bool testDetJ() const;
  // set the lsTag to +1 if the element is inside the domain (compute in the reference element)
  void computeLsTagDom(const DI_Element *e, const std::vector<const gLevelset *> &RPN);
  // set the lsTag to -1 if the element is not on the boundary of the final levelset
  // (compute in the reference element)
  void computeLsTagBound(std::vector<DI_Hexa *> &hexas, std::vector<DI_Tetra *> &tetras);
  void computeLsTagBound(std::vector<DI_Quad *> &quads, std::vector<DI_Triangle *> &triangles);
  // print the coordinates of the points of the element
  void print () const;
  // print the coordinates and the levelset values of the points of the element
  void printls () const;
};

class DI_ElementLessThan
{
 public:
  static double tolerance;
  bool operator()(const DI_Element *v1, const DI_Element *v2) const;
};

// --------------------------------------------------------------------------------------------------
//    0---1      //
//                                                                                                             //
class DI_Line : public DI_Element
{
 public:
  DI_Line () {
    pts_ = new DI_Point[2];
  }
  DI_Line (double x0, double y0, double z0, double x1, double y1, double z1)
  {
    pts_ = new DI_Point[2];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    integral_ = LineLength(x0, y0, z0, x1, y1, z1);
  }
  DI_Line (double x0, double y0, double z0, double x1, double y1, double z1, double length)
  {
    pts_ = new DI_Point[2];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    integral_ = length;
  }
  DI_Line (const DI_Point *pt0, const DI_Point *pt1, const int tag = -1)
  {
    lsTag_ = tag;
    pts_ = new DI_Point[2];
    pts_[0] = DI_Point(*pt0);
    pts_[1] = DI_Point(*pt1);
    integral_ = LineLength(pt0, pt1);
  }
  inline int type() const {return DI_LIN;}
  inline int getDim() const {return 1;}
  inline int nbVert() const {return 2;}
  inline int nbMid() const {
    switch(polOrder_) {
    case 1 : return 0;
    case 2 : return 1;
    default : return 0;
    }
  }
  inline int nbEdg() const {return 1;}
  void computeIntegral();
  inline double refIntegral() const {return 2.;}
  inline DI_Point* pt (int i) const {return i < 2 ? &pts_[i] : &mid_[i - 2];}
  inline double x (int i) const {return i < 2 ? pts_[i].x() : mid_[i - 2].x();}
  inline double y (int i) const {return i < 2 ? pts_[i].y() : mid_[i - 2].y();}
  inline double z (int i) const {return i < 2 ? pts_[i].z() : mid_[i - 2].z();}
  inline double ls (int i) const {return i < 2 ? pts_[i].ls() : mid_[i - 2].ls();}
  inline double ls (int i, int j) const {return i < 2 ? pts_[i].ls(j) : mid_[i - 2].ls(j);}
  void getRefIntegrationPoints (const int polynomialOrder,
                                std::vector<DI_IntegrationPoint *> &ipS) const;
  inline void vert(const int edge, int &s1, int &s2) const {
    s1 = 0; s2 = 1;}
  void midV (const int e, int *s, int &n) const {
    s[0] = 0; s[1] = 1; n = 2;
  }
  void getShapeFunctions (double u, double v, double w, double s[], int order = -1) const;
  void getGradShapeFunctions (const double u, const double v, const double w,
                              double s[][3], int order = -1) const;
  double detJ (const double &xP, const double &yP, const double &zP) const;
  bool cut (std::vector<const gLevelset *> &LsRPN, std::vector<DI_IntegrationPoint *> &ip,
            DI_Point::Container &cp, const int polynomialOrderL,
            std::vector<DI_Line *> &subLines, int recurLevel = 0, double **nodeLs = NULL) const;
  bool cut(const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
           std::vector<DI_Line *> &subLines, std::vector<DI_CuttingPoint*> &cp);
  void selfSplit (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                  std::vector<DI_Line *> &subLines, std::vector<DI_CuttingPoint*> &cuttingPoints) const;
  inline double length() const {return integral_;}
};

// --------------------------------------------------------------------------------------------------
//    2                                                                                           //
//    | \                                                                                         //
//    0---1                                                                                       //
// edge0=(0,1), edge1=(1,2), edge2=(2,0)                                                          //
class DI_Triangle : public DI_Element
{
 public:
  DI_Triangle () {
    pts_ = new DI_Point[3];
  }
  DI_Triangle (double x0, double y0, double z0, double x1, double y1, double z1,
               double x2, double y2, double z2)
  {
    pts_ = new DI_Point[3];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2);
    integral_ = TriSurf(x0, y0, z0, x1, y1, z1, x2, y2, z2);
  }
  DI_Triangle (double x0, double y0, double z0, double x1, double y1, double z1,
               double x2, double y2, double z2, double surface)
  {
    pts_ = new DI_Point[3];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2);
    integral_ = surface;
  }
  DI_Triangle (const DI_Point *pt0, const DI_Point *pt1, const DI_Point *pt2, const int tag = -1)
  {
    lsTag_ = tag;
    pts_ = new DI_Point[3];
    pts_[0] = DI_Point(*pt0);
    pts_[1] = DI_Point(*pt1);
    pts_[2] = DI_Point(*pt2);
    integral_ = TriSurf(pt0,pt1,pt2);
  }
  inline int type() const {return DI_TRI;}
  inline int getDim() const {return 2;}
  inline int nbVert() const {return 3;}
  inline int nbMid() const {
    switch(polOrder_) {
    case 1 : return 0;
    case 2 : return 3;
    default : return 0;
    }
  }
  inline int nbEdg() const {return 3;}
  void computeIntegral();
  inline double refIntegral() const {return 0.5;}
  inline DI_Point* pt (int i) const {return i < 3 ? &pts_[i] : &mid_[i - 3];}
  inline double x (int i) const {return i < 3 ? pts_[i].x() : mid_[i - 3].x();}
  inline double y (int i) const {return i < 3 ? pts_[i].y() : mid_[i - 3].y();}
  inline double z (int i) const {return i < 3 ? pts_[i].z() : mid_[i - 3].z();}
  inline double ls (int i) const {return i < 3 ? pts_[i].ls() : mid_[i - 3].ls();}
  inline double ls (int i, int j) const {return i < 3 ? pts_[i].ls(j) : mid_[i - 3].ls(j);}
  void getRefIntegrationPoints (const int polynomialOrder,
                                std::vector<DI_IntegrationPoint *> &ipS) const;
  inline void vert(const int edge, int &s1, int &s2) const {
    int v[3][2] = {{0, 1}, {1, 2}, {2, 0}};
    s1 = v[edge][0]; s2 = v[edge][1];
  }
  void midV (const int e, int *s, int &n) const {
    switch(e) {
    case 0 : s[0] = 0; s[1] = 1; n = 2; return;
    case 1 : s[0] = 1; s[1] = 2; n = 2; return;
    case 2 : s[0] = 2; s[1] = 0; n = 2; return;
    default : n = 0; return;
    }
  }
  void getShapeFunctions (double u, double v, double w, double s[], int order = -1) const;
  void getGradShapeFunctions (const double u, const double v, const double w,
                              double s[][3], int order = -1) const;
  double detJ (const double &xP, const double &yP, const double &zP) const;
  bool cut (std::vector<const gLevelset *> &LsRPN, std::vector<DI_IntegrationPoint *> &ip,
            std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
            const int polynomialOrderQ, const int polynomialOrderTr, const int polynomialOrderL,
            std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
            std::vector<DI_Line *> &surfLines, int recurLevel = 0, double **nodeLs = NULL) const;
  bool cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
            std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
            std::vector<DI_Line *> &surfLines, std::vector<DI_CuttingPoint*> &cp);
  void splitIntoSubTriangles (std::vector<DI_Triangle *> &triangles) const;
  void selfSplit (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                  std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
                  std::vector<DI_Line *> &surfLines, std::vector<DI_CuttingPoint*> &cuttingPoints) const;
  double quality () const;
  inline double surface() const {return integral_;}
};

// --------------------------------------------------------------------------------------------------
//    3---2                                                                                        //
//    |   |                                                                                        //
//    0---1                                                                                        //
// edge0=(0,1), edge1=(1,2), edge2=(2,3), edge3=(3,0)                                              //
class DI_Quad : public DI_Element
{
 public:
  DI_Quad () {
    pts_ = new DI_Point[4];
  }
  DI_Quad (double x0, double y0, double z0, double x1, double y1, double z1,
           double x2, double y2, double z2, double x3, double y3, double z3)
  {
    pts_ = new DI_Point[4];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2);
    pts_[3] = DI_Point(x3, y3, z3);
    integral_ = TriSurf(x0, y0, z0, x1, y1, z1, x2, y2, z2) +
                TriSurf(x0, y0, z0, x2, y2, z2, x3, y3, z3);
  }
  DI_Quad (double x0, double y0, double z0, double x1, double y1, double z1,
           double x2, double y2, double z2, double x3, double y3, double z3, double surf)
  {
    pts_ = new DI_Point[4];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2);
    pts_[3] = DI_Point(x3, y3, z3);
    integral_ = surf;
  }
  DI_Quad (const DI_Point *pt0, const DI_Point *pt1, const DI_Point *pt2, const DI_Point *pt3,
           const int tag = -1)
  {
    lsTag_ = tag;
    pts_ = new DI_Point[4];
    pts_[0] = DI_Point(*pt0);
    pts_[1] = DI_Point(*pt1);
    pts_[2] = DI_Point(*pt2);
    pts_[3] = DI_Point(*pt3);
    integral_ = TriSurf(pt0, pt1, pt2) + TriSurf(pt0, pt2, pt3);
  }
  inline int type() const {return DI_QUA;}
  inline int getDim() const {return 2;}
  inline int nbVert() const {return 4;}
  inline int nbMid() const {
    switch(polOrder_) {
    case 1 : return 0;
    case 2 : return 5;
    default : return 0;
    }
  }
  inline int nbEdg() const {return 4;}
  void computeIntegral();
  inline double refIntegral() const {return 4.;}
  inline DI_Point* pt (int i) const {return i < 4 ? &pts_[i] : &mid_[i - 4];}
  inline double x (int i) const {return i < 4 ? pts_[i].x() : mid_[i - 4].x();}
  inline double y (int i) const {return i < 4 ? pts_[i].y() : mid_[i - 4].y();}
  inline double z (int i) const {return i < 4 ? pts_[i].z() : mid_[i - 4].z();}
  inline double ls (int i) const {return i < 4 ? pts_[i].ls() : mid_[i - 4].ls();}
  inline double ls (int i, int j) const {return i < 4 ? pts_[i].ls(j) : mid_[i - 4].ls(j);}
  void getRefIntegrationPoints (const int polynomialOrder,
                                        std::vector<DI_IntegrationPoint *> &ipS) const;
  inline void vert(const int edge, int &s1, int &s2) const{
    int v[4][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    s1 = v[edge][0]; s2 = v[edge][1];
  }
  void midV (const int e, int *s, int &n) const {
    switch(e) {
    case 0 : s[0] = 0; s[1] = 1; n = 2; return;
    case 1 : s[0] = 1; s[1] = 2; n = 2; return;
    case 2 : s[0] = 2; s[1] = 3; n = 2; return;
    case 3 : s[0] = 3; s[1] = 0; n = 2; return;
    case 4 : s[0] = 0; s[1] = 1; s[2] = 2; s[3] = 3; n = 4; return;
    default : n = 0; return;
    }
  }
  void getShapeFunctions (double u, double v, double w, double s[], int order = -1) const;
  void getGradShapeFunctions (const double u, const double v, const double w,
                              double s[][3], int order = -1) const;
  double detJ (const double &xP, const double &yP, const double &zP) const;
  bool cut (std::vector<const gLevelset *> &LsRPN, std::vector<DI_IntegrationPoint *> &ip,
            std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
            const int polynomialOrderQ, const int polynomialOrderTr, const int polynomialOrderL,
            std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
            std::vector<DI_Line *> &surfLines, int recurLevel = 0, double **nodeLs = NULL) const;
  bool cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
            std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
            std::vector<DI_Line *> &surfLines, std::vector<DI_CuttingPoint*> &cp);
  void splitIntoTriangles (std::vector<DI_Triangle *> &triangles) const;
  inline double surface() const {return integral_;}
};

// ------------------------------------------------------------------------------------------------
//            3                                                                                  //
//            | \                                                                                //
//            0--2                                                                               //
//           /                                                                                   //
//          1                                                                                    //
//  edge0=(0,1) edge1=(0,2) edge2=(0,3) edge3=(1,2) edge4=(2,3) edge5=(3,1)                      //

class DI_Tetra : public DI_Element
{
 public:
  DI_Tetra () {
    pts_ = new DI_Point[4];
  }
  DI_Tetra (double x0, double y0, double z0, double x1, double y1, double z1,
            double x2, double y2, double z2, double x3, double y3, double z3)
  {
    pts_ = new DI_Point[4];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2);
    pts_[3] = DI_Point(x3, y3, z3);
    integral_ = TetraVol(x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3);
  }
  DI_Tetra (double x0, double y0, double z0, double x1, double y1, double z1,
            double x2, double y2, double z2, double x3, double y3, double z3, double vol)
  {
    pts_ = new DI_Point[4];
    pts_[0] = DI_Point(x0, y0, z0);
    pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2);
    pts_[3] = DI_Point(x3, y3, z3);
    integral_ = vol;
  }
  DI_Tetra (const DI_Point *pt0, const DI_Point *pt1, const DI_Point *pt2, const DI_Point *pt3)
  {
    pts_ = new DI_Point[4];
    pts_[0] = DI_Point(*pt0);
    pts_[1] = DI_Point(*pt1);
    pts_[2] = DI_Point(*pt2);
    pts_[3] = DI_Point(*pt3);
    integral_ = TetraVol(pt0, pt1, pt2, pt3);
  }
  inline int type() const {return DI_TET;}
  inline int getDim() const {return 3;}
  inline int nbVert() const {return 4;}
  inline int nbMid() const {
    switch(polOrder_) {
    case 1 : return 0;
    case 2 : return 6;
    default : return 0;
    }
  }
  inline int nbEdg() const {return 6;}
  void computeIntegral();
  inline double refIntegral() const {return 1. / 6.;}
  inline DI_Point* pt (int i) const {return i < 4 ? &pts_[i] : &mid_[i - 4];}
  inline double x (int i) const {return i < 4 ? pts_[i].x() : mid_[i - 4].x();}
  inline double y (int i) const {return i < 4 ? pts_[i].y() : mid_[i - 4].y();}
  inline double z (int i) const {return i < 4 ? pts_[i].z() : mid_[i - 4].z();}
  inline double ls (int i) const {return i < 4 ? pts_[i].ls() : mid_[i - 4].ls();}
  inline double ls (int i, int j) const {return i < 4 ? pts_[i].ls(j) : mid_[i - 4].ls(j);}
  inline void getRefIntegrationPoints (const int polynomialOrder,
                                        std::vector<DI_IntegrationPoint *> &ip) const;
  inline void vert(const int edge, int &s1, int &s2) const {
    int v[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {3, 1}};
    s1 = v[edge][0]; s2 = v[edge][1];
  }
  void midV (const int e, int *s, int &n) const {
    switch(e) {
    case 0 : s[0] = 0; s[1] = 1; n = 2; return;
    case 1 : s[0] = 0; s[1] = 2; n = 2; return;
    case 2 : s[0] = 0; s[1] = 3; n = 2; return;
    case 3 : s[0] = 1; s[1] = 2; n = 2; return;
    case 4 : s[0] = 2; s[1] = 3; n = 2; return;
    case 5 : s[0] = 3; s[1] = 1; n = 2; return;
    default : n = 0; return;
    }
  }
  void getShapeFunctions (double u, double v, double w, double s[], int order = -1) const;
  void getGradShapeFunctions (const double u, const double v, const double w,
                              double s[][3], int order = -1) const;
  double detJ (const double &xP, const double &yP, const double &zP) const;
  bool cut (std::vector<const gLevelset *> &LsRPN, std::vector<DI_IntegrationPoint *> &ip,
            std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
            const int polynomialOrderT, const int polynomialOrderQ, const int polynomialOrderTr,
            std::vector<DI_Tetra *> &subTetras, std::vector<DI_Quad *> &surfQuads,
            std::vector<DI_Triangle *> &surfTriangles, int recurLevel = 0, double **nodeLs = NULL) const;
  bool cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
            std::vector<DI_Tetra *> &subTetras, std::vector<DI_Quad *> &surfQuads,
            std::vector<DI_Triangle *> &surfTriangles, std::vector<DI_CuttingPoint*> &cp,
            std::vector<DI_QualError *> &QE);
  void selfSplit ( const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                   std::vector<DI_Tetra *> &subTetras, std::vector<DI_Triangle *> &surfTriangles,
                   std::vector<DI_CuttingPoint*> &cuttingPoints, std::vector<DI_QualError *> &QE) const;
  double quality () const;
  inline double volume() const {return integral_;}
};

// ------------------------------------------------------------------------------------------------
//          4----7
//         /|   /|
//        5----6 |
//        | 0--|-3
//        |/   |/
//        1----2
// edge0=(0,1) edge1=(1,2) edge2=(2,3) edge3=(3,0)
// edge4=(0,4) edge5=(1,5) edge6=(2,6) edge7=(3,7)
// edge8=(4,5) edge9=(5,6) edge10=(6,7) edge11=(7,4)
// face0=(0,1,2,3) face1=(0,4,5,1) face2=(1,5,6,2) face3=(2,6,7,3) face4=(0,3,7,4) face5=(4,7,6,5)

class DI_Hexa : public DI_Element
{
 public:
  DI_Hexa () {
    pts_ = new DI_Point[8];
  }
  DI_Hexa (double x0, double y0, double z0, double x1, double y1, double z1,
           double x2, double y2, double z2, double x3, double y3, double z3,
           double x4, double y4, double z4, double x5, double y5, double z5,
           double x6, double y6, double z6, double x7, double y7, double z7)
  {
    pts_ = new DI_Point[8];
    pts_[0] = DI_Point(x0, y0, z0); pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2); pts_[3] = DI_Point(x3, y3, z3);
    pts_[4] = DI_Point(x4, y4, z4); pts_[5] = DI_Point(x5, y5, z5);
    pts_[6] = DI_Point(x6, y6, z6); pts_[7] = DI_Point(x7, y7, z7);
    integral_ = TetraVol(x0, y0, z0, x1, y1, z1, x3, y3, z3, x4, y4, z4) +
                TetraVol(x1, y1, z1, x4, y4, z4, x5, y5, z5, x7, y7, z7) +
                TetraVol(x1, y1, z1, x3, y3, z3, x4, y4, z4, x7, y7, z7) +
                TetraVol(x2, y2, z2, x5, y5, z5, x6, y6, z6, x7, y7, z7) +
                TetraVol(x1, y1, z1, x2, y2, z2, x3, y3, z3, x7, y7, z7) +
                TetraVol(x1, y1, z1, x5, y5, z5, x2, y2, z2, x7, y7, z7);
  }
  DI_Hexa (double x0, double y0, double z0, double x1, double y1, double z1,
           double x2, double y2, double z2, double x3, double y3, double z3,
           double x4, double y4, double z4, double x5, double y5, double z5,
           double x6, double y6, double z6, double x7, double y7, double z7, double vol)
  {
    pts_ = new DI_Point[8];
    pts_[0] = DI_Point(x0, y0, z0); pts_[1] = DI_Point(x1, y1, z1);
    pts_[2] = DI_Point(x2, y2, z2); pts_[3] = DI_Point(x3, y3, z3);
    pts_[4] = DI_Point(x4, y4, z4); pts_[5] = DI_Point(x5, y5, z5);
    pts_[6] = DI_Point(x6, y6, z6); pts_[7] = DI_Point(x7, y7, z7);
    integral_ = vol;
  }
  DI_Hexa (const DI_Point *pt0, const DI_Point *pt1, const DI_Point *pt2, const DI_Point *pt3,
           const DI_Point *pt4, const DI_Point *pt5, const DI_Point *pt6, const DI_Point *pt7) {
    pts_ = new DI_Point[8];
    pts_[0] = DI_Point(*pt0);    pts_[1] = DI_Point(*pt1);
    pts_[2] = DI_Point(*pt2);    pts_[3] = DI_Point(*pt3);
    pts_[4] = DI_Point(*pt4);    pts_[5] = DI_Point(*pt5);
    pts_[6] = DI_Point(*pt6);    pts_[7] = DI_Point(*pt7);
    integral_ = TetraVol(pt0, pt1, pt3, pt4) + TetraVol(pt1, pt4, pt5, pt7) +
                TetraVol(pt1, pt3, pt4, pt7) + TetraVol(pt2, pt5, pt6, pt7) +
                TetraVol(pt1, pt2, pt3, pt7) + TetraVol(pt1, pt5, pt2, pt7);
  }
  inline int type() const {return DI_HEX;}
  inline int getDim() const {return 3;}
  inline int nbVert() const {return 8;}
  inline int nbMid() const {
    switch(polOrder_) {
    case 1 : return 0;
    case 2 : return 19;
    default : return 0;
    }
  }
  inline int nbEdg() const {return 12;}
  void computeIntegral();
  inline double refIntegral() const {return 8.;}
  inline DI_Point* pt (int i) const {return i < 8 ? &pts_[i] : &mid_[i - 8];}
  inline double x (int i) const {return i < 8 ? pts_[i].x() : mid_[i - 8].x();}
  inline double y (int i) const {return i < 8 ? pts_[i].y() : mid_[i - 8].y();}
  inline double z (int i) const {return i < 8 ? pts_[i].z() : mid_[i - 8].z();}
  inline double ls (int i) const {return i < 8 ? pts_[i].ls() : mid_[i - 8].ls();}
  inline double ls (int i, int j) const {return i < 8 ? pts_[i].ls(j) : mid_[i - 8].ls(j);}
  void getRefIntegrationPoints (const int polynomialOrder,
                                std::vector<DI_IntegrationPoint *> &ip) const;
  inline void vert(const int edge, int &s1, int &s2) const {
    int v[12][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 4}, {1, 5},
                    {2, 6}, {3, 7}, {4, 5}, {5, 6}, {6, 7}, {7, 4}};
    s1 = v[edge][0]; s2 = v[edge][1];
  }
  void midV (const int e, int *s, int &n) const {
    switch(e) {
    case 0 : s[0] = 0; s[1] = 1; n = 2; return;
    case 1 : s[0] = 1; s[1] = 2; n = 2; return;
    case 2 : s[0] = 2; s[1] = 3; n = 2; return;
    case 3 : s[0] = 3; s[1] = 0; n = 2; return;
    case 4 : s[0] = 0; s[1] = 4; n = 2; return;
    case 5 : s[0] = 1; s[1] = 5; n = 2; return;
    case 6 : s[0] = 2; s[1] = 6; n = 2; return;
    case 7 : s[0] = 3; s[1] = 7; n = 2; return;
    case 8 : s[0] = 4; s[1] = 5; n = 2; return;
    case 9 : s[0] = 5; s[1] = 6; n = 2; return;
    case 10 : s[0] = 6; s[1] = 7; n = 2; return;
    case 11 : s[0] = 7; s[1] = 4; n = 2; return;
    case 12 : s[0] = 0; s[1] = 1; s[2] = 2; s[3] = 3; n = 4; return;
    case 13 : s[0] = 0; s[1] = 4; s[2] = 5; s[3] = 1; n = 4; return;
    case 14 : s[0] = 1; s[1] = 5; s[2] = 6; s[3] = 2; n = 4; return;
    case 15 : s[0] = 2; s[1] = 6; s[2] = 7; s[3] = 3; n = 4; return;
    case 16 : s[0] = 0; s[1] = 3; s[2] = 7; s[3] = 4; n = 4; return;
    case 17 : s[0] = 4; s[1] = 7; s[2] = 6; s[3] = 5; n = 4; return;
    case 18 : s[0] = 0; s[1] = 1; s[2] = 2; s[3] = 3; s[4] = 4; s[5] = 5; s[6] = 6; s[7] = 7;
              n = 8; return;
    default : n = 0; return;
    }
  }
  void getShapeFunctions (double u, double v, double w, double s[], int order = -1) const;
  void getGradShapeFunctions (const double u, const double v, const double w,
                              double s[][3], int order = -1) const;
  double detJ (const double &xP, const double &yP, const double &zP) const;
  bool cut (std::vector<const gLevelset *> &LsRPN, std::vector<DI_IntegrationPoint *> &ip,
            std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
            const int polynomialOrderH, const int polynomialOrderT,
            const int polynomialOrderQ, const int polynomialOrderTr,
            std::vector<DI_Hexa *> &notCutHexas, std::vector<DI_Tetra *> &subTetras,
            std::vector<DI_Quad *> &surfQuads, std::vector<DI_Triangle *> &surfTriangles,
            std::vector<DI_Line *> &frontLines, int recurLevel = 0, double **nodeLs = NULL) const;
  bool cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
            std::vector<DI_Hexa *> &unCutHexas, std::vector<DI_Tetra *> &subTetras,
            std::vector<DI_Quad *> &surfQuads, std::vector<DI_Triangle *> &surfTriangles,
            std::vector<DI_CuttingPoint*> &cp, std::vector<DI_QualError *> &QE);
  void splitIntoTetras(std::vector<DI_Tetra *> &tetras) const;
  inline double volume() const {return integral_;}
};

// -------------------------------------------------------------------------------------------------
// DI_QualError reports quality errors due to impossibility to assert best quality
// for the three quadrangular faces of the prisms
// -------------------------------------------------------------------------------------------------
class DI_QualError
{
  DI_Point *pts_;
public:
  DI_QualError (DI_Point *p11, DI_Point *p12, DI_Point *p21, DI_Point *p22) {
    pts_ = new DI_Point[4];
    pts_[0] = DI_Point(*p11);
    pts_[1] = DI_Point(*p12);
    pts_[2] = DI_Point(*p21);
    pts_[3] = DI_Point(*p22);
  }
  ~DI_QualError () {
    if(pts_) delete[] pts_;
  }
  inline DI_Point* pt (int i) const {
    if(i == 0) return &pts_[0];
    if(i == 1) return &pts_[1];
    if(i == 2) return &pts_[2];
    if(i == 3) return &pts_[3];
    printf("DI_QualError::pt only accept indices from 0 to 3!\n");
    DI_Point* p = NULL; return p;
  }
  void print(const DI_Element *e) const{
    DI_Point pt1(pts_[0]), pt2(pts_[1]), pt3(pts_[2]), pt4(pts_[3]);
    e->mappingP(&pt1); e->mappingP(&pt2); e->mappingP(&pt3); e->mappingP(&pt4);
    printf("Cannot assert best quality for the last face of the Prism \n");
    printf("=> edges (%g,%g,%g),(%g,%g,%g) and (%g,%g,%g),(%g,%g,%g) may cross in ",
    pt1.x(), pt1.y(), pt1.z(), pt2.x(), pt2.y(), pt2.z(),
    pt3.x(), pt3.y(), pt3.z(), pt4.x(), pt4.y(), pt4.z());
    e->print();
  }
};

#endif
