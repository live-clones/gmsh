// Author : Gaetan Bricteux

#ifndef INTEGRATION3D_CC
#define INTEGRATION3D_CC

#include "Integration3D.h"
#include "recurCut.h"
#include "GaussIntegration.h"
#include "polynomialBasis.h"
#include "GmshDefines.h" 

#define ZERO_LS_TOL  1.e-3
#define EQUALITY_TOL 1.e-15

// cross product
inline void cross(const double *v1, const double *v2, double *v) {
  v[0] = v1[1] * v2[2] - v2[1] * v1[2];
  v[1] = v2[0] * v1[2] - v1[0] * v2[2];
  v[2] = v1[0] * v2[1] - v2[0] * v1[1];
}
// dot product
inline double dot(const double *v1, const double *v2) {
  return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}
// norm
inline double norm(const double *v) {
  return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
// substract
inline void vec (const double *x1, const double *x2, double *v) {
  v[0] = x2[0] - x1[0]; v[1] = x2[1] - x1[1]; v[2] = x2[2] - x1[2];
}
inline void vec (const DI_Point *p1, const DI_Point *p2, double *v) {
  v[0] = p2->x() - p1->x(); v[1] = p2->y() - p1->y(); v[2] = p2->z() - p1->z();
}
inline double sq2 (const double a) {return a * a;}

// determinant
inline double det3(double d11, double d12, double d13,
                   double d21, double d22, double d23,
                   double d31, double d32, double d33) {
  return d11 * (d22 * d33 - d23 * d32) - d21 * (d12 * d33 - d13 * d32) + d31 * (d12 * d23 - d13 * d22);
}
inline double det4 (double d11, double d12, double d13, double d14,
                    double d21, double d22, double d23, double d24,
                    double d31, double d32, double d33, double d34,
                    double d41, double d42, double d43, double d44) {
  return d11 * det3(d22, d23, d24, d32, d33, d34, d42, d43, d44)
       - d21 * det3(d12, d13, d14, d32, d33, d34, d42, d43, d44)
       + d31 * det3(d12, d13, d14, d22, d23, d24, d42, d43, d44)
       - d41 * det3(d12, d13, d14, d22, d23, d24, d32, d33, d34);
}

// distance
inline double distance(const DI_Point *p1, const DI_Point *p2) {
  return sqrt((p1->x() - p2->x()) * (p1->x() - p2->x())
            + (p1->y() - p2->y()) * (p1->y() - p2->y())
            + (p1->z() - p2->z()) * (p1->z() - p2->z()));
}
inline double distance(const DI_CuttingPoint *p1, const DI_CuttingPoint *p2) {
  return sqrt((p1->x() - p2->x()) * (p1->x() - p2->x())
            + (p1->y() - p2->y()) * (p1->y() - p2->y())
            + (p1->z() - p2->z()) * (p1->z() - p2->z()));
}

// middle of 2 points
inline DI_Point* middle (const DI_Point *p1, const DI_Point *p2) {
  return new DI_Point ((p1->x() + p2->x()) / 2, (p1->y() + p2->y()) / 2, (p1->z() + p2->z()) / 2);
}
inline DI_Point* middle (const DI_Point *p1, const DI_Point *p2,
                        const DI_Element *e, const std::vector<gLevelset *> &RPNi) {
  return new DI_Point ((p1->x() + p2->x()) / 2, (p1->y() + p2->y()) / 2, (p1->z() + p2->z()) / 2, e, RPNi);
}

// barycentre
inline DI_Point* barycenter (const DI_Element *el,
                             const DI_Element *e, const std::vector<gLevelset *> &RPN) {
  double x[3] = {0., 0., 0.};
  int n;
  for (n = 0; n < el->nbVert(); n++) {
    x[0] += el->x(n);
    x[1] += el->y(n);
    x[2] += el->z(n);
  }
  return new DI_Point(x[0] / n, x[1] / n, x[2] / n, e, RPN);
}

// swap two integers
inline void swap(int &a, int &b) {
  int t = a;
  a = b; b = t;
}
// swap two doubles
inline void swap(double &a, double &b) {
  double t = a;
  a = b; b = t;
}
// swap two points
inline void swap (DI_Point **p1, DI_Point **p2) {
  DI_Point *pt = *p1;
  *p1 = *p2; *p2 = pt;
}

// return true if the 4 points are planar
inline bool isPlanar (const DI_Point *p1, const DI_Point *p2, const DI_Point *p3, const DI_Point *p4) {
  double v12[3]; vec(p1, p2, v12);
  double v13[3]; vec(p1, p3, v13);
  double v14[3]; vec(p1, p4, v14);
  double c1[3]; cross(v12, v13, c1);
  double c2[3]; cross(v12, v14, c2);
  double c[3];  cross(c1, c2, c);
  return (c[0] == 0. && c[1] == 0. && c[2] == 0.);
}
// return true if the 3 points are linear
inline bool isLinear (const DI_Point *p1, const DI_Point *p2, const DI_Point *p3) {
  double v12[3]; vec(p1, p2, v12);
  double v13[3]; vec(p1, p3, v13);
  double c[3]; cross(v12, v13, c);
  return (c[0] == 0. && c[1] == 0. && c[2] == 0.);
}
// return true if the 4 points form a quad in good ordering
inline bool ordered4Nodes (const DI_Point *p1, const DI_Point *p2, const DI_Point *p3, const DI_Point *p4) {
  double v21[3]; vec(p2, p1, v21);
  double v23[3]; vec(p2, p3, v23);
  double v24[3]; vec(p2, p4, v24);
  double norm21 = norm(v21);
  double norm23 = norm(v23);
  double norm24 = norm(v24);
  double dot213 = dot(v21, v23);
  double dot214 = dot(v21, v24);
  double theta213 = acos(dot213 / (norm21 * norm23));
  double theta214 = acos(dot214 / (norm21 * norm24));
  if(theta214 > theta213) return false;
  return true;
}

bool isInQE (const DI_Triangle *t, const DI_QualError *QE) {
  int b = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++)
      if (t->pt(i)->equal(QE->pt(j))) {b++; break;}
  }
  return (b == 3);
}
bool belongsTo (const DI_Element *e, const DI_Element *E) {
  int b = 0;
  for(int k = 0; k < E->nbVert(); k++) {
    for(int l = 0; l < e->nbVert(); l++)
      if((e->pt(l))->equal(E->pt(k))) {b++; break;}
    if(b == e->nbVert()) return true;
  }
  return false;
}
bool isLastLnInV (const std::vector<DI_Line *> &v, const int i1 = 0) {
  int b;
  for (int i = i1; i < (int)v.size() - 1; i++) {
    b = 0;
    for (int k = 0; k < 2; k++)
      for(int l = 0; l < 2; l++)
        if(v[i]->pt(k)->equal(v[v.size() - 1]->pt(l))) {b++; break;}
    if(b == 2) return true;
  }
  return false;
}
bool isLastTrInV (const std::vector<DI_Triangle *> &v, const int i1 = 0) {
  int b;
  for (int i = i1; i < (int)v.size() - 1; i++) {
    b = 0;
    for (int k = 0; k < 3; k++)
      for(int l = 0; l < 3; l++)
        if(v[i]->pt(k)->equal(v[v.size() - 1]->pt(l))) {b++; break;}
    if(b == 3) return true;
  }
  return false;
}
bool isLastQInV (const std::vector<DI_Quad *> &v, const int i1 = 0) {
  int b;
  for (int i = i1; i < (int)v.size() - 1; i++) {
    b = 0;
    for(int k = 0; k < 4; k++)
      for(int l = 0; l < 4; l++)
        if(v[i]->pt(k)->equal(v[v.size() - 1]->pt(l))) {b++; break;}
    if(b == 4) return true;
  }
  return false;
}

// return common vertex of 2 edges (s11,s12) and (s21,s22)  // s11 != s12 and s21 != s22
int commonV (int &s11, int &s12, int &s21, int &s22) {
  if(s11 == s21 || s11 == s22) return s11;
  if(s12 == s21 || s12 == s22) return s12;
  printf("no common summit, %d,%d,%d,%d\n", s11, s12, s21, s22);
  return 0;
}

inline double adjustLs (double ls) {
  return (fabs(ls) < ZERO_LS_TOL) ? 0. : ls;
}
inline bool isCrossed (const DI_Point *p1, const DI_Point *p2) {
  double ls1 = p1->ls(), ls2 = p2->ls();
  return (ls1 * ls2 < 0.);
}

// return the index of the point with minimum x,y and z
int minimum(double *x, double *y, double *z, const int num) {
  double xm = x[0];
  for(int i = 1; i < num; i++) if(x[i] < xm) xm = x[i];
  std::vector<int> INDx(num); int countx = 0;
  for(int i = 0; i < num; i++) if(x[i] == xm) INDx[countx++] = i;
  if(countx == 1) return INDx[0];

  double ym = y[INDx[0]];
  for(int i = 1; i < countx; i++) if(y[INDx[i]] < ym) ym = y[INDx[i]];
  std::vector<int> INDy(countx); int county = 0;
  for(int i = 0; i < countx; i++) if(y[INDx[i]] == ym) INDy[county++] = INDx[i];
  if(county == 1) return INDy[0];

  double zm = z[INDy[0]];
  for(int i = 1; i < county; i++) if(z[INDy[i]] < zm) zm = z[INDy[i]];
  std::vector<int> INDz(county); int countz = 0;
  for(int i = 0; i < county; i++) if(z[INDy[i]] == zm) INDz[countz++] = INDy[i];
  return INDz[0];
}

// Return the quality of a triangle
double qualityTri(const DI_Point *p0, const DI_Point *p1, const DI_Point *p2) {
  double a = distance(p0, p1);
  double b = distance(p0, p2);
  double c = distance(p1, p2);

  double rhoO = a * b * c / sqrt((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c));
  double rhoI = a * b * c / (2 * (a + b + c) * rhoO);
  return 2 * rhoI / rhoO;
}

// Return the best quality for a quad cut into 2 triangles
int bestQuality(const DI_Point *p1, const DI_Point *p2, const DI_Point *p3, const DI_Point *p4,
                DI_Triangle **t1, DI_Triangle **t2) {
  int cut = 0;
  double qual11 = qualityTri(p1, p2, p3);
  double qual12 = qualityTri(p1, p3, p4);
  double qual21 = qualityTri(p1, p2, p4);
  double qual22 = qualityTri(p2, p3, p4);
  double worst1 = std::min(qual11, qual12);
  double worst2 = std::min(qual21, qual22);
  if(worst1 - worst2 > EQUALITY_TOL)
    cut = 1;
  else if(worst2 - worst1 > EQUALITY_TOL)
    cut = 2;
  else {
    worst1 = std::max(qual11, qual12);
    worst2 = std::max(qual21, qual22);
    if(worst1 - worst2 > EQUALITY_TOL)
      cut = 1;
    else if(worst2 - worst1 > EQUALITY_TOL)
      cut = 2;
    else { // same min and max qualities
      double x[4] = {p1->x(), p2->x(), p3->x(), p4->x()};
      double y[4] = {p1->y(), p2->y(), p3->y(), p4->y()};
      double z[4] = {p1->z(), p2->z(), p3->z(), p4->z()};
      int IND = minimum(x, y, z, 4);
      if(IND == 0 || IND == 2) cut = 1;
      else cut = 2;
    }
  }
  if(cut == 1) {
    *t1 = new DI_Triangle(p1, p2, p3);
    *t2 = new DI_Triangle(p1, p3, p4);
    return 1;
  }
  else {
    *t1 = new DI_Triangle(p1, p2, p4);
    *t2 = new DI_Triangle(p2, p3, p4);
    return 2;
  }
}

// Return the quality of a tetrahedron
inline double qualityTet (double x1, double y1, double z1, double x2, double y2, double z2,
                          double x3, double y3, double z3, double x4, double y4, double z4){
  double Dx =  det4(x1 * x1 + y1 * y1 + z1 * z1, y1, z1, 1., x2 * x2 + y2 * y2 + z2 * z2, y2, z2, 1.,
                    x3 * x3 + y3 * y3 + z3 * z3, y3, z3, 1., x4 * x4 + y4 * y4 + z4 * z4, y4, z4, 1.);
  double Dy = -det4(x1 * x1 + y1 * y1 + z1 * z1, x1, z1, 1., x2 * x2 + y2 * y2 + z2 * z2, x2, z2, 1.,
                    x3 * x3 + y3 * y3 + z3 * z3, x3, z3, 1., x4 * x4 + y4 * y4 + z4 * z4, x4, z4, 1.);
  double Dz =  det4(x1 * x1 + y1 * y1 + z1 * z1, x1, y1, 1., x2 * x2 + y2 * y2 + z2 * z2, x2, y2, 1.,
                    x3 * x3 + y3 * y3 + z3 * z3, x3, y3, 1., x4 * x4 + y4 * y4 + z4 * z4, x4, y4, 1.);
  double a  =  det4(x1, y1, z1, 1., x2, y2, z2, 1., x3, y3, z3, 1., x4, y4, z4, 1.);
  double c  =  det4(x1 * x1 + y1 * y1 + z1 * z1, x1, y1, z1, x2 * x2 + y2 * y2 + z2 * z2, x2, y2, z2,
                    x3 * x3 + y3 * y3 + z3 * z3, x3, y3, z3, x4 * x4 + y4 * y4 + z4 * z4, x4, y4, z4);
  double rhoO = sqrt(Dx * Dx + Dy * Dy + Dz * Dz - 4. * a * c) / (2. * fabs(a));

  double res[4][3];
  double v12[3] = {x2 - x1, y2 - y1, z2 - z1};
  double v13[3] = {x3 - x1, y3 - y1, z3 - z1};
  double v14[3] = {x4 - x1, y4 - y1, z4 - z1};
  double v32[3] = {x2 - x3, y2 - y3, z2 - z3};
  double v43[3] = {x3 - x4, y3 - y4, z3 - z4};
  double v34[3] = {x4 - x3, y4 - y3, z4 - z3};
  cross(v12, v13, res[0]);
  cross(v13, v14, res[1]);
  cross(v14, v12, res[2]);
  cross(v32, v43, res[3]);
  double V = dot(res[0], v34) / 6.;
  double SA = norm(res[0]) / 2. + norm(res[1]) / 2.
            + norm(res[2]) / 2. + norm(res[3]) / 2.;
  double rhoI = 3 * V / SA;
  return 3 * rhoI / rhoO;
}

// Return the cutting of a pyramid cut into 2 tetras with the best quality faces
// (x1,x2,x3,x4 form the base in ccw and x5 is the summit)
int bestQuality(const DI_Point *p1, const DI_Point *p2, const DI_Point *p3,
                const DI_Point *p4, const DI_Point *p5, DI_Tetra **t1, DI_Tetra **t2) {
  int cut = 0;
  double qual11 = qualityTri(p1, p2, p3);
  double qual12 = qualityTri(p1, p3, p4);
  double qual21 = qualityTri(p1, p2, p4);
  double qual22 = qualityTri(p2, p3, p4);

  double worst1 = std::min(qual11, qual12);
  double worst2 = std::min(qual21, qual22);
  if(worst1 - worst2 > EQUALITY_TOL)
    cut = 1;
  else if(worst2 - worst1 > EQUALITY_TOL)
    cut = 2;
  else {
    worst1 = std::max(qual11, qual12);
    worst2 = std::max(qual21, qual22);
    if(worst1 - worst2 > EQUALITY_TOL)
      cut = 1;
    else if(worst2 - worst1 > EQUALITY_TOL)
      cut = 2;
    else { // same min and max qualities
      double x[4] = {p1->x(), p2->x(), p3->x(), p4->x()};
      double y[4] = {p1->y(), p2->y(), p3->y(), p4->y()};
      double z[4] = {p1->z(), p2->z(), p3->z(), p4->z()};
      int IND = minimum(x, y, z, 4);
      if(IND == 0 || IND == 2) cut = 1;
      else cut = 2;
    }
  }
  if(cut == 1) {
    *t1 = new DI_Tetra(p1, p2, p3, p5);
    *t2 = new DI_Tetra(p1, p3, p4, p5);
    return 1;
  }
  else {
    *t1 = new DI_Tetra(p1, p2, p4, p5);
    *t2 = new DI_Tetra(p2, p3, p4, p5);
    return 2;
  }
}

// Return the cutting of a prism into 3 tetras with the best quality faces
int bestQuality (DI_Point *p0, DI_Point *p1, DI_Point *p2,
                 DI_Point *p3, DI_Point *p4, DI_Point *p5,
                 DI_Tetra **t1, DI_Tetra **t2, DI_Tetra **t3, std::vector<DI_QualError *> &QError) {
  int cut3[3] = {0, 0, 0}; int cut = -1;
  int fa[3][4] = {{0, 3, 4, 1}, {0, 2, 5, 3}, {1, 4, 5, 2}}; //faces
  DI_Point* pt[6] = {p0, p1, p2, p3, p4, p5};
  for(int f = 0; f < 3; f++){
    int i1 = fa[f][0], i2 = fa[f][1], i3 = fa[f][2], i4 = fa[f][3];
    double qual11 = qualityTri(pt[i1], pt[i2], pt[i3]);
    double qual12 = qualityTri(pt[i1], pt[i3], pt[i4]);
    double qual21 = qualityTri(pt[i1], pt[i2], pt[i4]);
    double qual22 = qualityTri(pt[i2], pt[i3], pt[i4]);
    //printf("face%d, q11=%.18f,q12=%.18f,q21=%.18f,q22=%.18f\n",f,qual11,qual12,qual21,qual22);
    double worst1 = std::min(qual11, qual12);
    double worst2 = std::min(qual21, qual22);
    if(worst1 - worst2 > EQUALITY_TOL)
      cut3[f] = 1;
    else if(worst2 - worst1 > EQUALITY_TOL)
      cut3[f] = 2;
    else {
      worst1 = std::max(qual11, qual12);
      worst2 = std::max(qual21, qual22);
      if(worst1 - worst2 > EQUALITY_TOL)
        cut3[f] = 1;
      else if(worst2 - worst1 > EQUALITY_TOL)
        cut3[f] = 2;
      else { // same min and max qualities
        double xc[4] = {pt[i1]->x(), pt[i2]->x(), pt[i3]->x(), pt[i4]->x()};
        double yc[4] = {pt[i1]->y(), pt[i2]->y(), pt[i3]->y(), pt[i4]->y()};
        double zc[4] = {pt[i1]->z(), pt[i2]->z(), pt[i3]->z(), pt[i4]->z()};
        int IND = minimum(xc, yc, zc, 4);
        if(IND == 0 || IND == 2) cut3[f] = 1;
        else cut3[f] = 2;
      }
    }
  }

  if(cut3[0] == 1){
    if(cut3[1] == 1){
      if(cut3[2] == 1) cut = 1;
      else cut = 2;
    }
    else{
      if(cut3[2] == 1) QError.push_back(new DI_QualError(p1, p5, p2, p4));
      cut = 3;
    }
  }
  else {
    if(cut3[1] == 1){
      if(cut3[2] == 2) QError.push_back(new DI_QualError(p1, p5, p2, p4));
      cut = 0;
    }
    else{
      if(cut3[2] == 1) cut = 5;
      else cut = 4;
    }
  }

  if(cut == 0) {
    *t1 = new DI_Tetra(p0, p1, p2, p5);
    *t2 = new DI_Tetra(p0, p1, p5, p3);
    *t3 = new DI_Tetra(p1, p5, p3, p4);
    return 1;
  }
  else if(cut == 1) {
    *t1 = new DI_Tetra(p0, p1, p2, p5);
    *t2 = new DI_Tetra(p0, p1, p5, p4);
    *t3 = new DI_Tetra(p0, p4, p5, p3);
    return 2;
  }
  else if(cut == 2) {
    *t1 = new DI_Tetra(p0, p1, p2, p4);
    *t2 = new DI_Tetra(p0, p4, p2, p5);
    *t3 = new DI_Tetra(p0, p4, p5, p3);
    return 3;
  }
  else if(cut == 3) {
    *t1 = new DI_Tetra(p0, p1, p2, p4);
    *t2 = new DI_Tetra(p0, p4, p2, p3);
    *t3 = new DI_Tetra(p2, p3, p4, p5);
    return 4;
  }
  else if(cut == 4) {
    *t1 = new DI_Tetra(p0, p1, p2, p3);
    *t2 = new DI_Tetra(p1, p2, p3, p4);
    *t3 = new DI_Tetra(p2, p3, p4, p5);
    return 5;
  }
  else if(cut == 5) {
    *t1 = new DI_Tetra(p0, p1, p2, p3);
    *t2 = new DI_Tetra(p1, p2, p3, p5);
    *t3 = new DI_Tetra(p1, p5, p3, p4);
    return 6;
  }
  return 0;
}

// computes the intersection between a level set and a linear edge
DI_Point* Newton(const DI_Point *p1, const DI_Point *p2,
                const DI_Element *e, const std::vector<gLevelset *> &RPNi) {
  double eps = -p1->ls() / (p2->ls() - p1->ls());
  DI_Point* p = new DI_Point(p1->x() + eps * (p2->x() - p1->x()), p1->y() + eps * (p2->y() - p1->y()),
                             p1->z() + eps * (p2->z() - p1->z()));
  double pls = e->evalLs(p->x(), p->y(), p->z());
  // Newton iteration to find the intersection between the level set and the edge
  while(fabs(pls) > EQUALITY_TOL){
    if(pls * p1->ls() < 0.) {
      eps = -pls / (p1->ls() - pls);
      p->move(p->x() + eps * (p1->x() - p->x()), p->y() + eps * (p1->y() - p->y()), p->z() + eps * (p1->z() - p->z()));
    }
    else {
      eps = -pls / (p2->ls() - pls);
      p->move(p->x() + eps * (p2->x() - p->x()), p->y() + eps * (p2->y() - p->y()), p->z() + eps * (p2->z() - p->z()));
    }
    pls = e->evalLs(p->x(), p->y(), p->z());
  }
  p->computeLs(e, RPNi);
  return p;
}

// compute the position of the middle of a quadratic edge
//(intersection between the bisector of the linear edge and the levelset)
DI_Point* quadMidNode(const DI_Point *p1, const DI_Point *p2, const DI_Point *pf,
                      const DI_Element *e, const std::vector<gLevelset *> &RPNi) {
  // middle of the edge between the 2 cutting points
  DI_Point midEN((p1->x() + p2->x()) / 2., (p1->y() + p2->y()) / 2., (p1->z() + p2->z()) / 2.);
  midEN.addLs(e);
  // the bisector is computed in the plane of the face of the tetra [(x1,x2)x(x1,xf)]x(x1,x2)
  double v12[3]; vec(p1, p2, v12);
  double v1f[3]; vec(p1, pf, v1f);
  double nf[3]; cross(v12, v1f, nf);
  double bisector[3]; cross(nf, v12, bisector);
  double normB = norm(bisector);
  if(normB) {
    for (int i = 0; i < 3; i++)
      bisector[i] = bisector[i] / normB;
  }
  // raise the length of bisector if needed .........
  DI_Point pt(midEN.x() + bisector[0], midEN.y() + bisector[1], midEN.z() + bisector[2]);
  pt.addLs(e);
  if (pt.ls() * midEN.ls() > 0.) {
    pt.move(midEN.x() - bisector[0], midEN.y() - bisector[1], midEN.z() - bisector[2]);
    pt.changeLs(e->evalLs(pt.x(), pt.y(), pt.z()));
  }
  DI_Point* qmn = Newton(&midEN, &pt, e, RPNi);
  return qmn;
}

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------

// DI_Point methods -------------------------------------------------------------------------------
DI_Point::DI_Point (double x, double y, double z, gLevelset *ls) : x_(x), y_(y), z_(z) {
  addLs((*ls)(x, y, z));
}
DI_Point & DI_Point::operator= (const DI_Point &rhs) {
  if(this != &rhs){
    x_ = rhs.x(); y_ = rhs.y(); z_ = rhs.z(); Ls = rhs.Ls;
  }
  return *this;
}
void DI_Point::addLs (const double ls) {
  Ls.push_back(adjustLs(ls));
}
void DI_Point::addLs (const DI_Element *e) {
  addLs(e->evalLs(x_, y_, z_));
}
void DI_Point::chooseLs (const gLevelset *Lsi) {
  if(Ls.size() < 2) return;
  double ls1 = Ls[Ls.size() - 2], ls2 = Ls[Ls.size() - 1];
  double ls = Lsi->choose(ls1, ls2);
  Ls.pop_back(); Ls.pop_back();
  addLs(ls);
}
void DI_Point::computeLs (const DI_Element *e, const std::vector<gLevelset*> &RPNi) {
  int prim = 0; Ls.clear();
  if(e->sizeLs() == 0) return;
  for(int l = 0; l < (int)RPNi.size(); l++) {
    if (RPNi[l]->isPrimitive())
      addLs(e->evalLs(x_, y_, z_, prim++));
    else
      chooseLs(RPNi[l]);
  }
}
void DI_Point::computeLs (const gLevelset *ls) {
  Ls.clear();
  addLs((*ls)(x_, y_, z_));
}
bool DI_Point::equal(const DI_Point *p) const {
  return (fabs(x() - p->x()) < EQUALITY_TOL && fabs(y() - p->y()) < EQUALITY_TOL && fabs(z() - p->z()) < EQUALITY_TOL);
}

// DI_IntegrationPoint methods --------------------------------------------------------------------
void DI_IntegrationPoint::computeLs (const DI_Element *e, const std::vector<gLevelset*> &RPN) {
  int prim = 0; std::vector<double> Ls;
  for(int l = 0; l < (int)RPN.size(); l++) {
    if(RPN[l]->isPrimitive())
      Ls.push_back(adjustLs(e->evalLs(x_, y_, z_, prim++)));
    else {
      double ls1 = Ls[Ls.size() - 2], ls2 = Ls[Ls.size() - 1];
      double ls = RPN[l]->choose(ls1, ls2);
      Ls.pop_back(); Ls.pop_back();
      Ls.push_back(adjustLs(ls));
    }
  }
  setLs(Ls.back());
}

// DI_CuttingPoint methods ------------------------------------------------------------------------
DI_CuttingPoint::DI_CuttingPoint(const DI_Point *pt) : DI_Point(pt->x(), pt->y(), pt->z()),
                                                       xl_(pt->x()), yl_(pt->y()), zl_(pt->z()) {
  for(int i = 0; i < pt->sizeLs(); i++)
    addLs(pt->ls(i));
}

// DI_PointLessThan methods -----------------------------------------------------------------------
double DI_PointLessThan::tolerance = 1.e-6;
bool DI_PointLessThan::operator()(const DI_Point *p1, const DI_Point *p2) const
{
  if(p1->x() - p2->x() >  tolerance) return true;
  if(p1->x() - p2->x() < -tolerance) return false;
  if(p1->y() - p2->y() >  tolerance) return true;
  if(p1->y() - p2->y() < -tolerance) return false;
  if(p1->z() - p2->z() >  tolerance) return true;
  return false;
}

// DI_Element methods -----------------------------------------------------------------------------
DI_Element::DI_Element(const DI_Element &cp) : lsTag_(cp.lsTag()), polOrder_(cp.getPolynomialOrder()),
                                               integral_(cp.integral()) {
  pts_ = new DI_Point [cp.nbVert()];
  for(int i = 0; i < cp.nbVert(); i++)
    pts_[i] = DI_Point(*cp.pt(i));
  if(cp.nbMid()) {
    mid_ = new DI_Point [cp.nbMid()];
    for(int i = 0; i < cp.nbMid(); i++)
      mid_[i] = DI_Point(*cp.mid(i));
  }
  else
    mid_ = NULL;
}
DI_Element & DI_Element::operator= (const DI_Element &rhs){
  if(type() != rhs.type()) {
    printf("Error : try to assign element of different type!\n");
    return *this;
  }
  if(this != &rhs) {
    delete [] pts_;
    pts_ = new DI_Point[rhs.nbVert()];
    for(int i = 0; i < nbVert(); i++) {
      pts_[i] = DI_Point(*rhs.pt(i));
    }
    if(rhs.nbMid()) {
      if(mid_) delete [] mid_;
      mid_ = new DI_Point[rhs.nbMid()];
      for(int i = 0; i < rhs.nbMid(); i++)
        mid_[i] = DI_Point(*(rhs.mid(i)));
    }
    else mid_ = NULL;
    polOrder_ = rhs.getPolynomialOrder();
    integral_ = rhs.integral();
    lsTag_ = rhs.lsTag();
  }
  return *this;
}
void DI_Element::getShapeFunctions(double u, double v, double w, double s[], int o) const
{
  //printf("type elem =%d  order =%d\n", type(), o);
  const polynomialBasis* fs = getFunctionSpace(o);
  if(fs) fs->f(u, v, w, s);
  else Msg::Error("Function space not implemented for this type of element");
}

void DI_Element::getGradShapeFunctions(double u, double v, double w, double s[][3],
                                     int o) const
{
  const polynomialBasis* fs = getFunctionSpace(o);
  if(fs) fs->df(u, v, w, s);
  else Msg::Error("Function space not implemented for this type of element");
}
void DI_Element::setPolynomialOrder (int o) {
  if(polOrder_ == o) return;
  if (mid_){
    delete [] mid_;
    mid_ = NULL;
  }
  polOrder_ = o;

  if(o == 1) return;

  const polynomialBasis *fs = getFunctionSpace(o);
  if(!fs) Msg::Error("Function space not implemented for this type of element");

  mid_ = new DI_Point[nbMid()];
  int j = nbVert();
  int dim = getDim();
  double u, v, w;
  double xyz[3];
  for(int i = 0; i < nbMid(); i++, j++) {
    u = fs->points(j,0);
    v = (dim > 1) ? fs->points(j,1) : 0.;
    w = (dim > 2) ? fs->points(j,2) : 0.;
    evalC(u, v, w, xyz, 1);
    mid_[i] = DI_Point(xyz[0], xyz[1], xyz[2]);
  }
}
void DI_Element::setPolynomialOrder (int o, const DI_Element *e, const std::vector<gLevelset *> &RPNi) {
  if(polOrder_ == o) return;
  if (mid_){
    delete [] mid_;
    mid_ = NULL;
  }
  polOrder_ = o;

  if(o == 1) return;

  const polynomialBasis *fs = getFunctionSpace(o);
  if(!fs) Msg::Error("Function space not implemented for this type of element");

  mid_ = new DI_Point[nbMid()];
  int j = nbVert();
  int dim = getDim();
  double u, v, w;
  double xyz[3];
  for(int i = 0; i < nbMid(); i++, j++) {
    u = fs->points(j,0);
    v = (dim > 1) ? fs->points(j,1) : 0.;
    w = (dim > 2) ? fs->points(j,2) : 0.;
    evalC(u, v, w, xyz, 1);
    mid_[i] = DI_Point(xyz[0], xyz[1], xyz[2], e, RPNi);
  }
}
void DI_Element::addLs (const double *ls) {
  for(int i = 0; i < nbVert() + nbMid(); i++)
    pt(i)->addLs(ls[i]);
}
void DI_Element::addLs (const DI_Element *e) {
  if(e->sizeLs() < 1) return;
  for(int i = 0; i < nbVert() + nbMid(); i++)
    pt(i)->addLs(e);
}
void DI_Element::addLs (const DI_Element *e, const gLevelset *Ls) {
  if(type() != e->type()) {
    printf("Error : addLs with element of different type\n");
  }
  for(int i = 0; i < nbVert() + nbMid(); ++i) {
    double ls = (*Ls)(e->x(i), e->y(i), e->z(i));
    pt(i)->addLs(ls);
  }
}
void DI_Element::addLs (const DI_Element *e, const gLevelset *Ls, int iLs, double **nodeLs) {
  if(!nodeLs || !nodeLs[0][iLs]) {
    addLs(e, Ls);
    return;
  }
  for(int i = 0; i < nbVert() + nbMid(); i++)
    pt(i)->addLs(nodeLs[i][iLs]);
}
void DI_Element::chooseLs (const gLevelset *Lsi) {
  if(sizeLs() < 2)
    printf("chooseLs with element ls size < 2 : typeEl=%d\n", type());
  for(int i = 0; i < nbVert() + nbMid(); i++)
    pt(i)->chooseLs(Lsi);
}
void DI_Element::clearLs() {
  for(int i = 0; i < nbVert() + nbMid(); i++)
    pt(i)->clearLs();
}
bool DI_Element::addQuadEdge (int edge, DI_Point *xm,
                              const DI_Element *e, const std::vector<gLevelset *> &RPNi) {
  if(edge >= nbEdg()) {printf("wrong number (%d) for quadratic edge for a ", edge); print(); return false;}
  int s1, s2; vert(edge, s1, s2);
  int order0 = getPolynomialOrder();
  if(order0 == 1) setPolynomialOrder(2, e, RPNi);
  double dist = distance(mid(edge), xm);
  double sideLength = distance(pt(s1), pt(s2));
  if (dist / sideLength < 1.e-5) {
    if(order0 == 1) setPolynomialOrder(1);
    printf("dist=%.20f, sideLength=%g, d/sL=%g => do not add quadratic edge\n", dist, sideLength, dist/sideLength);
    return true; // do not add the quadratic edge if xm is very close from the middle of the edge
  }
  DI_Point *p0 = &mid_[edge];
  mid_[edge].move(xm->x(), xm->y(), xm->z());//mid_[edge] = xm;
  // check if the quadratic edge will produce a twist in the element (detJ<0)
  if(!testDetJ()){
    // reinitialize quad edges if the element was not quad at the begining
    if(order0 == 1) setPolynomialOrder(1);
    else mid_[edge].move(p0->x(), p0->y(), p0->z());//mid_[edge] = p0;
    printf("detJ<0 when trying to add a quadratic edge in "); print();
    return false;
  }
  printf("in add quad edge \n");
  computeIntegral();
  return true;
}
bool DI_Element::contain (const DI_Point *p) const {
  for(int i = 0; i < nbVert(); i++){
    if(p->equal(pt(i)))
      return true;
  }
  switch(getDim()){
  case 1 :
    if(!isLinear(pt(0), pt(1), p)) return false;
    if(distance(p, pt(0)) > integral() || distance(p, pt(1)) > integral()) return false;
    return true;
  case 2 :
    if(!isPlanar(pt(0), pt(1), pt(2), p)) return false;
    for(int i = 0; i < nbVert(); i++){
      double v1[3]; vec(pt(i), pt((i + 1) % nbVert()), v1);
      double v2[3]; vec(pt(i), pt((i + 2) % nbVert()), v2);
      double vp[3]; vec(pt(i), p, vp);
      double c1[3]; cross(v1, v2, c1);
      double c2[3]; cross(v1, vp, c2);
      if(dot(c1, c2) < 0.) return false; // assert pt is on the same side of (pt(i),pt(i+1)) than pt(i+2)
    }
    return true;
  case 3 :
    for(int i = 0; i < nbVert(); i++){
      double v1[3]; vec(pt(i), pt((i + 1) % nbVert()), v1);
      double v2[3]; vec(pt(i), pt((i + 2) % nbVert()), v2);
      double v3[3]; vec(pt(i), pt((i + 3) % nbVert()), v3);
      double vp[3]; vec(pt(i), p, vp);
      double v1v2[3]; cross(v1, v2, v1v2);
      double c1 = dot(v1v2, v3);
      double c2 = dot(v1v2, vp);
      if(c1 * c2 < 0.) return false; // assert pt is on the same side of (pt(i),pt(i+1),pt(i+2)) than pt(i+3)
    }
    return true;
  default :
    return false;
  }
}
bool DI_Element::contain (const DI_Element *e) const {
  for(int p = 0; p < e->nbVert(); p++)
    if(!contain(e->pt(p))) return false;
  return true;
}
void DI_Element::mappingP (DI_Point *pt) const {
  double e[3]; evalC(pt->x(), pt->y(), pt->z(), e);
  pt->move(e[0], e[1], e[2]);
}
void DI_Element::mappingIP (DI_IntegrationPoint *in) const {
  double e[3]; evalC(in->x(), in->y(), in->z(), e);
  double w = in->weight() * integral() / refIntegral();
  in->move(e[0], e[1], e[2]);
  in->setWeight(w);
}
void DI_Element::mappingCP (DI_CuttingPoint *cp) const {
  double e[3]; evalC(cp->x(), cp->y(), cp->z(), e);
  cp->move(e[0], e[1], e[2]);
}
void DI_Element::mappingEl (DI_Element *el) const {
  double s[3];
  for (int i = 0; i < el->nbVert() + el->nbMid(); i++) {
    evalC(el->x(i), el->y(i), el->z(i), s);
    el->pt(i)->move(s[0], s[1], s[2]);
  }
  el->computeIntegral();
}
void DI_Element::integrationPoints (const int polynomialOrder, const DI_Element *loc,
                                    const DI_Element *e, const std::vector<gLevelset *> &RPN,
                                    std::vector<DI_IntegrationPoint *> &ip) const {
  std::vector<DI_IntegrationPoint *> ip_ref;
  getRefIntegrationPoints(polynomialOrder, ip_ref);
  for (int j = 0; j < (int)ip_ref.size(); j++) {
    DI_IntegrationPoint IPloc (*ip_ref[j]);
    loc->mappingIP(&IPloc);
    mappingIP(ip_ref[j]);
    ip_ref[j]->addLocC(IPloc.x(), IPloc.y(), IPloc.z());
    DI_IntegrationPoint pp(IPloc); pp.computeLs(e, RPN);
    //ip_ref[j]->setLs(loc->evalLs(IPloc.x(), IPloc.y(), IPloc.z()));//levelset computed in the subelement FIXME check sign!
    //ip_ref[j]->setLs(evalLs(ip_ref[j]->x(), ip_ref[j]->y(), ip_ref[j]->z()));
    ip_ref[j]->setLs(pp.ls());
    /*printf("pt loc : "); IPloc.print(); printf("pt reel : "); ip_ref[j]->print();
    printf("el loc : "); loc->printls(); printf("el reel : "); printls(); printf("el e : "); e->printls();
    printf("ls_loc=%g ls_reel=%g ls_e=%g\n\n", loc->evalLs(IPloc.x(), IPloc.y(), IPloc.z()),
                                               evalLs(ip_ref[j]->x(), ip_ref[j]->y(), ip_ref[j]->z()), pp.ls());*/
    ip.push_back(ip_ref[j]);
  }
}
void DI_Element::getCuttingPoints (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                                   std::vector<DI_CuttingPoint *> &cp) const {
  int s1, s2;
  for(int i = 0; i < nbEdg(); i++){
    vert(i, s1, s2);
    if (isCrossed(pt(s1), pt(s2))) {
      DI_Point* p = Newton(pt(s1), pt(s2), e, RPNi);
      cp.push_back(new DI_CuttingPoint(p));
      delete p;
    }
  }
  for(int i = 0; i < nbVert(); i++){
    if(ls(i) == 0.)
      cp.push_back(new DI_CuttingPoint(pt(i)));
  }
}
void DI_Element::evalC (const double u, const double v, const double w, double *ev, int order) const {
  int nbV = nbVert() + nbMid();
  std::vector<double> s(nbV);
  ev[0] = 0; ev[1] = 0; ev[2] = 0;
  getShapeFunctions (u, v, w, &s[0], order);
  for(int i = 0; i < nbV; i++){
    ev[0] += x(i) * s[i];
    ev[1] += y(i) * s[i];
    ev[2] += z(i) * s[i];
  }
}
double DI_Element::evalLs (const double u, const double v, const double w, int iLs, int order) const{
  int nbV = nbVert() + nbMid();
  if(iLs == -1) iLs = sizeLs() - 1; //last ls value
  double vls = 0;
  std::vector<double> s(nbV);
  getShapeFunctions (u, v, w, &s[0], order);
  for(int i = 0; i < nbV; i++)
    vls += ls(i, iLs) * s[i];
  return adjustLs(vls);
}
bool DI_Element::testDetJ() const {
  double detJ0 = detJ(x(0), y(0), z(0));
  for(int i = 1; i < nbVert() + nbMid(); i++)
    if(detJ0 * detJ(x(i), y(i), z(i)) < 0.) return false;
  return true;
}
double DI_Element::detJ (const double u, const double v, const double w) const {
  double J[3][3];
  J[0][0] = J[0][1] = J[0][2] = 0.;
  J[1][0] = J[1][1] = J[1][2] = 0.;
  J[2][0] = J[2][1] = J[2][2] = 0.;
  /*double **s=new double*[nbVert()+ nbMid()];
  for(int i = 0; i < nbVert()+ nbMid(); ++i){
      s[i] = new double[3];//s[i] = new double[getDim()];
  }*/
  typedef double d3[3];
  int nbV = nbVert() + nbMid();
  d3 *s = new d3[nbV];
  getGradShapeFunctions(u, v, w, s);
  switch(getDim()){
  case 3 :
    for(int i = 0; i < nbV; i++) {
      J[0][0] += x(i) * s[i][0]; J[0][1] += y(i) * s[i][0]; J[0][2] += z(i) * s[i][0];
      J[1][0] += x(i) * s[i][1]; J[1][1] += y(i) * s[i][1]; J[1][2] += z(i) * s[i][1];
      J[2][0] += x(i) * s[i][2]; J[2][1] += y(i) * s[i][2]; J[2][2] += z(i) * s[i][2];
//      delete [] s[i];
    }
    delete [] s;
    return det3(J[0][0], J[0][1], J[0][2], J[1][0], J[1][1], J[1][2], J[2][0], J[2][1], J[2][2]);
  case 2 :
    for(int i = 0; i < nbV; i++) {
      J[0][0] += x(i) * s[i][0]; J[0][1] += y(i) * s[i][0]; J[0][2] += z(i) * s[i][0];
      J[1][0] += x(i) * s[i][1]; J[1][1] += y(i) * s[i][1]; J[1][2] += z(i) * s[i][1];
//      delete [] s[i];
    }
    delete [] s;
    return sqrt(sq2(J[0][0] * J[1][1] - J[0][1] * J[1][0]) +
                sq2(J[0][2] * J[1][0] - J[0][0] * J[1][2]) +
                sq2(J[0][1] * J[1][2] - J[0][2] * J[1][1])); // allways > 0 => does'nt allow to check if twist !!!!
  case 1 :
    for(int i = 0; i < nbV; i++) {
      J[0][0] += x(i) * s[i][0]; J[0][1] += y(i) * s[i][0]; J[0][2] += z(i) * s[i][0];
//      delete [] s[i];
    }
    delete [] s;
    return sqrt(sq2(J[0][0]) + sq2(J[0][1]) + sq2(J[0][2])); // allways > 0 !!!!
  default :
    delete [] s;
    return 1.;
  }
}
// set the lsTag to +1 if the element is inside the domain (lsTag is -1 by default)
void DI_Element::computeLsTagDom(const DI_Element *e, const std::vector<gLevelset *> &RPN) {
  for(int i = 0; i < nbVert(); i++) {
    if(pt(i)->isOutsideDomain())
      return;
    if(pt(i)->isInsideDomain())
      {setLsTag(1); return;}
  }
  DI_Point* bar = barycenter(this, e, RPN);
  if(bar->isOutsideDomain())
    {delete bar; return;}
  if(bar->isInsideDomain())
    {setLsTag(1); delete bar; return;}
  for(int i = 0; i < nbVert(); i++) {
    DI_Point* mid = middle (pt(i), bar, e, RPN);
    if(mid->isOutsideDomain())
      {delete mid; delete bar; return;}
    if(mid->isInsideDomain())
      {setLsTag(1); delete mid; delete bar; return;}
    delete mid;
  }
  delete bar;
  printf("Error : Unable to determine the sign of the element : \n");
  printf(" - Parent element : "); e->printls();
  printf(" - Element : "); printls();
}
// set the lsTag to -1 if the element is not on the border of the domain
void DI_Element::computeLsTagBound(std::vector<DI_Hexa *> &hexas, std::vector<DI_Tetra *> &tetras){
  for(int i = 0; i < nbVert(); i++) {
    if(!pt(i)->isOnBorder()) {
      setLsTag(-1);
      return;
    }
  }

  /*DI_Element *e1 = NULL, *e2 = NULL;
  for(int i = 0; i < (int)tetras.size(); i++){
    if(belongsTo(this, tetras[i])) {
      if(!e1) e1 = tetras[i];
      else {e2 = tetras[i]; break;}
    }
  }
  if(e1 && e2) {
    if(e1->lsTag() * e2->lsTag() > 0.) setLsTag(-1);
    return;
  }
  for(int i = 0; i < (int)hexas.size(); i++){
    if(belongsTo(this, hexas[i])) {
      if(!e1) e1 = hexas[i];
      else {e2 = hexas[i]; break;}
    }
  }
  if(e1 && e2 && e1->lsTag() * e2->lsTag() > 0.) setLsTag(-1);*/
}
void DI_Element::computeLsTagBound(std::vector<DI_Quad *> &quads, std::vector<DI_Triangle *> &triangles){
  for(int i = 0; i < nbVert(); i++) {
    if(ls(i) != 0.) {
      setLsTag(-1);
      return;
    }
  }

  /*DI_Element *e1 = NULL, *e2 = NULL, *et = NULL;
  int NT = triangles.size(), NQ = quads.size();
  for(int i = 0; i < NT + NQ; i++){
    if((i < NT  && belongsTo(this, triangles[i])) ||
       (i >= NT && belongsTo(this, quads[i-NT]))) {
      if(i < NT) et = triangles[i];
      else et = quads[i-NT];
      if(!e1) e1 = et;
      else {e2 = et; break;}
    }
  }
  if(e1 && e2 && e1->lsTag() * e2->lsTag() > 0.) setLsTag(-1);*/
}

void DI_Element::print() const {
  switch(type()) {
  case DI_LIN : printf("Line"); break;
  case DI_TRI : printf("Triangle"); break;
  case DI_QUA : printf("Quad"); break;
  case DI_TET : printf("Tetra"); break;
  case DI_HEX : printf("Hexa"); break;
  default : printf("Element");
  }
  printf("%d ", getPolynomialOrder());
  for(int i = 0; i < nbVert() + nbMid(); i++)
    printf("(%g,%g,%g) ", x(i), y(i), z(i));
  printf("tag=%d\n", lsTag());
}
void DI_Element::printls() const {
  switch(type()) {
  case DI_LIN : printf("Line"); break;
  case DI_TRI : printf("Triangle"); break;
  case DI_QUA : printf("Quad"); break;
  case DI_TET : printf("Tetra"); break;
  case DI_HEX : printf("Hexa"); break;
  default : printf("Element");
  }
  printf("%d ", getPolynomialOrder());
  for(int i = 0; i < nbVert() + nbMid(); i++) {
    printf("(%g,%g,%g) ls=(", x(i), y(i), z(i));
    for(int j = 0; j < sizeLs(); j++) printf("%g,", ls(i,j));
    printf("); ");
  }
  printf("tag=%d\n", lsTag());
}

double DI_ElementLessThan::tolerance = 1.e-6;
bool DI_ElementLessThan::operator()(const DI_Element *e1, const DI_Element *e2) const
{
  for(int i = 0; i < e1->nbVert(); i++) {
    if(e1->x(i) - e2->x(i) >  tolerance) return true;
    if(e1->x(i) - e2->x(i) < -tolerance) return false;
    if(e1->y(i) - e2->y(i) >  tolerance) return true;
    if(e1->y(i) - e2->y(i) < -tolerance) return false;
    if(e1->z(i) - e2->z(i) >  tolerance) return true;
  }
  return false;
}

// DI_Line methods --------------------------------------------------------------------------------
const polynomialBasis* DI_Line::getFunctionSpace(int o) const{
  int order = (o == -1) ? getPolynomialOrder() : o;
  int tag = polynomialBasis::getTag(TYPE_LIN, order);
  return polynomialBases::find(tag);
}

void DI_Line::computeIntegral() {
  integral_ = LineLength(pt(0), pt(1));
  // switch (getPolynomialOrder()) {
  // case 1 :
  //   integral_ = LineLength(pt(0), pt(1));
  //   break;
  // case 2 :
  //   integral_ = LineLength(pt(0), mid(0)) + LineLength(mid(0), pt(1));
  //   break;
  // default :
  //   printf("Order %d line function space not implemented ", getPolynomialOrder()); print();
  // }
}
// DI_Triangle methods ----------------------------------------------------------------------------
const polynomialBasis* DI_Triangle::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;
  int tag = polynomialBasis::getTag(TYPE_TRI, order);
  return polynomialBases::find(tag);
}
void DI_Triangle::computeIntegral() {
  integral_ = TriSurf(pt(0), pt(1), pt(2));
  // switch (getPolynomialOrder()) {
  // case 1 :
  //   integral_ = TriSurf(pt(0), pt(1), pt(2));
  //   break;
  // case 2 :
  //   integral_ = TriSurf(pt(0), mid(0), mid(2)) + TriSurf(pt(1), mid(0), mid(1))
  //             + TriSurf(pt(2), mid(1), mid(2)) + TriSurf(mid(0), mid(1), mid(2));
  //   break;
  // default :
  //   printf("Order %d triangle function space not implemented ", getPolynomialOrder()); print();
  // }
}
double DI_Triangle::quality() const {
  return qualityTri(pt(0), pt(1), pt(2));
}

// DI_Quad methods --------------------------------------------------------------------------------
const polynomialBasis* DI_Quad::getFunctionSpace(int o) const{
 int order = (o == -1) ? getPolynomialOrder() : o;
  int tag = polynomialBasis::getTag(TYPE_QUA, order);
  return polynomialBases::find(tag);
}

void DI_Quad::computeIntegral() {
  integral_ = TriSurf(pt(0), pt(1), pt(2)) + TriSurf(pt(0), pt(2), pt(3));
  // switch (getPolynomialOrder()) {
  // case 1 :
  //   integral_ = TriSurf(pt(0), pt(1), pt(2)) + TriSurf(pt(0), pt(2), pt(3));
  //   break;
  // case 2 :
  //   integral_ = TriSurf(pt(0), mid(0), mid(4)) + TriSurf(pt(0), mid(4), mid(3))
  //             + TriSurf(pt(1), mid(1), mid(4)) + TriSurf(pt(1), mid(4), mid(0))
  //             + TriSurf(pt(2), mid(2), mid(4)) + TriSurf(pt(2), mid(4), mid(1))
  //             + TriSurf(pt(3), mid(3), mid(4)) + TriSurf(pt(3), mid(4), mid(2));
  //   break;
  // default :
  //   printf("Order %d quadrangle function space not implemented ", getPolynomialOrder()); print();
  // }
}

// DI_Tetra methods -------------------------------------------------------------------------------
const polynomialBasis* DI_Tetra::getFunctionSpace(int o) const{
 int order = (o == -1) ? getPolynomialOrder() : o;
  int tag = polynomialBasis::getTag(TYPE_TET, order);
  return polynomialBases::find(tag);
}

void DI_Tetra::computeIntegral() {
    integral_ = TetraVol(pt(0), pt(1), pt(2), pt(3));
}
double DI_Tetra::quality() const {
  return qualityTet(x(0), y(0), z(0), x(1), y(1), z(1), x(2), y(2), z(2), x(3), y(3), z(3));
}


// Hexahedron methods -----------------------------------------------------------------------------
const polynomialBasis* DI_Hexa::getFunctionSpace(int o) const{
  int order = (o == -1) ? getPolynomialOrder() : o;
  int tag = polynomialBasis::getTag(TYPE_HEX, order);
  return polynomialBases::find(tag);
}
void DI_Hexa::computeIntegral() {
    integral_ = TetraVol(pt(0), pt(1), pt(3), pt(4)) + TetraVol(pt(1), pt(4), pt(5), pt(7))
              + TetraVol(pt(1), pt(3), pt(4), pt(7)) + TetraVol(pt(2), pt(5), pt(6), pt(7))
              + TetraVol(pt(1), pt(2), pt(3), pt(7)) + TetraVol(pt(1), pt(5), pt(2), pt(7));
}

// ----------------------------------------------------------------------------
// -------------------------- SPLITTING ---------------------------------------
// ----------------------------------------------------------------------------

// Split a reference line cut by a level set into sublines
void DI_Line::selfSplit (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                          std::vector<DI_Line *> &subLines, std::vector<DI_CuttingPoint *> &cuttingPoints) const
{
  if (!isCrossed(pt(0), pt(1))) {
    subLines.push_back(new DI_Line(*this));
    return;
  }

  // compute the intersection between the line and the level set
  DI_Point *U = Newton(pt(0), pt(1), e, RPNi);
  cuttingPoints.push_back(new DI_CuttingPoint(U));

  // line cut => split into 2 sublines
  subLines.push_back(new DI_Line(pt(0), U, lsTag()));
  subLines.push_back(new DI_Line(U, pt(1), lsTag()));
  delete U;
}

// Split a triangle into 4 sub-triangles
void DI_Triangle::splitIntoSubTriangles (std::vector<DI_Triangle *> &subTriangles) const {
  DI_Point *p01 = middle(pt(0), pt(1));
  DI_Point *p02 = middle(pt(0), pt(2));
  DI_Point *p12 = middle(pt(1), pt(2));

  subTriangles.push_back(new DI_Triangle(p01, p02, p12));   // 01-02-12
  subTriangles.push_back(new DI_Triangle(pt(0), p01, p02)); // 0-01-02
  subTriangles.push_back(new DI_Triangle(pt(1), p01, p12)); // 1-01-12
  subTriangles.push_back(new DI_Triangle(pt(2), p02, p12)); // 2-02-12
  delete p01; delete p02; delete p12;
}
// Split a reference triangle cut by a level set into subtriangles
void DI_Triangle::selfSplit (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                             std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
                             std::vector<DI_Line *> &surfLines, std::vector<DI_CuttingPoint *> &cuttingPoints) const
{
  //bool quadT = (e->getPolynomialOrder() == 2) ? true : false; // if true, use quadratic sub triangles
  bool quadT = false;
  int LStag = RPNi.back()->getTag();

  int nbZe = 0, ze[3];
  for(int i = 0; i < 3; i++)
    if(pt(i)->isOnBorder())
      ze[nbZe++] = i;
  for(int i = 0; i < nbZe; i++)
    cuttingPoints.push_back(new DI_CuttingPoint(pt(ze[i])));
    // !! we add these points several times => remove later

  if (!isCrossed(pt(0), pt(1)) && !isCrossed(pt(0), pt(2)) && !isCrossed(pt(1), pt(2))) {
    subTriangles.push_back(new DI_Triangle(*this));
    if(nbZe == 2)
      surfLines.push_back(new DI_Line(pt(ze[0]), pt(ze[1]), LStag));
      // !! we add these lines twice => remove the second later
    return;
  }

  DI_Point *U[2];              // cutting points (max2)
  int IND[2];                  // ids of edges cut
  int COUNT = 0;               // number of edges cut

  // compute the intersections between the edges of the triangle and the level set
  for(int i = 0; i < 3; i++){
    int n1 = i, n2 = (i + 1) % 3;
    if (isCrossed(pt(n1), pt(n2))) {
      U[COUNT] = Newton(pt(n1), pt(n2), e, RPNi);
      IND[COUNT++] = i;
    }
  }

  for(int i = 0; i < COUNT; i++)
    cuttingPoints.push_back(new DI_CuttingPoint(U[i]));

  // Adjust the indices of the nodes in order to have the same pattern for each case with the same number of edges cut;
  // compute the position of the middle nodes on the quadratic edges of the sub triangles;
  // and create the sub triangles
  switch (COUNT) {
    case 1 : {// 1 edge cut => split into 2 triangles
      int s1 = IND[0];
      int s2 = (s1 + 1) % 3;
      int s3 = (s2 + 1) % 3;

      DI_Triangle *t1 = new DI_Triangle(pt(s3), pt(s1), U[0], lsTag());
      DI_Triangle *t2 = new DI_Triangle(pt(s2), pt(s3), U[0], lsTag());
      DI_Line *ln = new DI_Line(U[0], pt(s3), LStag);

      if(quadT){
        DI_Point *midEN2 = quadMidNode(U[0], pt(s3), pt(s1), e, RPNi); // intersection between ls and the bissector between the cutting points
        cuttingPoints.push_back(new DI_CuttingPoint(midEN2));
        t1->addQuadEdge (2, midEN2, e, RPNi);
        t2->addQuadEdge (1, midEN2, e, RPNi);
        ln->addQuadEdge (0, midEN2, e, RPNi);
        delete midEN2;
      }
      subTriangles.push_back(t1);
      subTriangles.push_back(t2);
      surfLines.push_back(ln);
      delete U[0];
      break;
    }
    case 2: {// 2 edges cut => 1 triangle + 1 quad => split into 3 triangles
      int s1 = 2 * IND[0] - IND[1] + 2; // arbitrary formulation to find the good vertex !!!
      int s2 = (s1 + 1) % 3;
      int s3 = (s1 + 2) % 3;
      if(s1 == 0) { // (0,2) => swap U[0] and U[1]
        swap(&U[0], &U[1]);
      }

      bool useQuads = false; // if true, split the triangle into 1 triangle and 1 quad

      DI_Triangle *t1 = new DI_Triangle(U[0], pt(s1), U[1], lsTag());
      DI_Line *ln = new DI_Line(U[0], U[1], LStag);
      DI_Quad *q1; DI_Triangle *t2, *t3;
      if(useQuads) q1 = new DI_Quad(U[0], U[1], pt(s2), pt(s3), lsTag());
      else bestQuality(U[0], U[1], pt(s2), pt(s3), &t2, &t3);
      t2->setLsTag(lsTag()); t3->setLsTag(lsTag());

      if(quadT){
        DI_Point *midEN2 = quadMidNode(U[0], U[1], pt(s2), e, RPNi); // intersection between ls and the bissector between the cutting points
        cuttingPoints.push_back(new DI_CuttingPoint(midEN2));
        //midEN2.printls();
        t1->addQuadEdge(2, midEN2, e, RPNi); //t1.printls();
        ln->addQuadEdge(0, midEN2, e, RPNi); //ln.printls();
        if(useQuads) q1->addQuadEdge(0, midEN2, e, RPNi);
        else t2->addQuadEdge(0, midEN2, e, RPNi); //t2.printls();
        delete midEN2;
      }
      subTriangles.push_back(t1);
      surfLines.push_back(ln);
      if(useQuads) subQuads.push_back(q1);
      else {
        subTriangles.push_back(t2);
        subTriangles.push_back(t3);
      }
      delete U[0]; delete U[1];
      break;
    }
    default:
      printf("Error : %d edge(s) cut in the triangle (ls : %g %g %g)\n",
             COUNT, ls(0), ls(1), ls(2));
  }
}

// Split a reference Quadrangle into 2 triangles
void DI_Quad::splitIntoTriangles(std::vector<DI_Triangle *> &triangles) const
{
  triangles.push_back(new DI_Triangle(pt(0), pt(1), pt(3), lsTag())); // 013
  triangles.push_back(new DI_Triangle(pt(1), pt(2), pt(3), lsTag())); // 123
}

// Split a reference tetrahedron cut by a level set (defined in a hex) into sub tetrahedra
// and create triangles on the surface of the level set
void DI_Tetra::selfSplit (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                       std::vector<DI_Tetra *> &subTetras, std::vector<DI_Triangle *> &surfTriangles,
                       std::vector<DI_CuttingPoint *> &cuttingPoints, std::vector<DI_QualError *> &QError) const
{
  //bool quadT = (e->getPolynomialOrder() == 2) ? true : false; // use of quadratic surf triangles and quadratic sub tetrahedra
  bool quadT = false;
  int tag = RPNi.back()->getTag();

  int nbZe = 0, ze[4];
  for(int i = 0; i < 4; i++)
    if(pt(i)->isOnBorder())
      ze[nbZe++] = i;
  for(int i = 0; i < nbZe; i++)
    cuttingPoints.push_back(new DI_CuttingPoint(pt(ze[i]))); // !! we add these points several times => remove later

  // case 0 : the tetrahedron is not cut by the level set
  if (!isCrossed(pt(0), pt(1)) && !isCrossed(pt(0), pt(2)) && !isCrossed(pt(1), pt(2)) &&
      !isCrossed(pt(0), pt(3)) && !isCrossed(pt(1), pt(3)) && !isCrossed(pt(2), pt(3))) {
    subTetras.push_back(new DI_Tetra(*this));
    if(nbZe == 3)
      surfTriangles.push_back(new DI_Triangle(pt(ze[0]), pt(ze[1]), pt(ze[2]), tag));
      // !! we add these triangles twice => remove the second later
    return;
  }

  DI_Point *U[4];    // cutting points
  int COUNT = 0;     // number of edges cut
  int IND[4];        // ids of edges cut

  // edges nodes and opposite edges nodes
  int tab [6][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {1, 2, 0, 3}, {2, 3, 0, 1}, {3, 1, 0, 2}};

  // compute the intersections between the edges of the tetra and the level set.
  for(int i = 0; i < 6; i++){
    int n1 = tab[i][0], n2 = tab[i][1];
    if (isCrossed(pt(n1), pt(n2))) {
      U[COUNT] = Newton(pt(n1), pt(n2), e, RPNi);
      IND[COUNT++] = i;
    }
  }
  for(int i = 0; i < COUNT; i++)
    cuttingPoints.push_back(new DI_CuttingPoint(U[i]));

  // Adjust the indices of the nodes in order to have the same pattern for each case with the same number of edges cut;
  // compute the position of the middle nodes on the quadratic edges of the sub tetras;
  // and create the sub tetras and sub triangles on the level set surface
  switch (COUNT) {
    case 1 : {// 1 edge cut => split into 2 tetras
      int i1 = IND[0];  //printf("case 1 : ind : %d\n",i1);

      int s1 = tab[i1][0];
      int s2 = tab[i1][1];
      int s3 = tab[i1][2];
      int s4 = tab[i1][3];

      DI_Tetra *t1 = new DI_Tetra(U[0], pt(s4), pt(s3), pt(s1));
      DI_Tetra *t2 = new DI_Tetra(pt(s4), U[0], pt(s3), pt(s2));
      DI_Triangle *tr = new DI_Triangle(pt(s4), U[0], pt(s3), tag);

      if(quadT){
        DI_Point *midEN2[2]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[0], pt(s4), pt(s1), e, RPNi);
        midEN2[1] = quadMidNode(U[0], pt(s3), pt(s1), e, RPNi);
        tr->addQuadEdge (0, midEN2[0], e, RPNi);
        t1->addQuadEdge (0, midEN2[0], e, RPNi);
        t2->addQuadEdge (0, midEN2[0], e, RPNi);
        tr->addQuadEdge (1, midEN2[1], e, RPNi);
        t1->addQuadEdge (1, midEN2[1], e, RPNi);
        t2->addQuadEdge (3, midEN2[1], e, RPNi);
        delete midEN2[0]; delete midEN2[1];
      }
      subTetras.push_back(t1);
      subTetras.push_back(t2);
      surfTriangles.push_back(tr);
      delete U[0];
      break;
    }
    case 2 : {// 2 edges cut => 1 tetra + 1 pyramid => split into 3 tetras
      int i1 = IND[0], i2 = IND[1];

      if((i1 == 0 && (i2 == 2 ||i2 == 3)) || (i1 == 1 && i2 == 4) || ((i1 == 2 || i1 == 3) && i2 == 5)) {
        swap(&U[0], &U[1]); swap(i1, i2);
      }
      //printf("case 2 : ind : %d,%d\n",i1,i2);

      int s1 = commonV(tab[i1][2], tab[i1][3], tab[i2][2], tab[i2][3]);
      int s2 = commonV(tab[i1][0], tab[i1][1], tab[i2][0], tab[i2][1]);
      int s3 = commonV(tab[i1][2], tab[i1][3], tab[i2][0], tab[i2][1]);
      int s4 = commonV(tab[i1][0], tab[i1][1], tab[i2][2], tab[i2][3]);

      DI_Tetra *t1 = new DI_Tetra(U[0], U[1], pt(s2), pt(s1));
      DI_Triangle *tr = new DI_Triangle(U[0], U[1], pt(s1), tag);
      DI_Tetra *t2, *t3;
      int qual = bestQuality(U[1], U[0], pt(s4), pt(s3), pt(s1), &t2, &t3);

      if(quadT){
        DI_Point *midEN2[3]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[1], pt(s1), pt(s2), e, RPNi);
        midEN2[1] = quadMidNode(U[0], pt(s1), pt(s2), e, RPNi);
        midEN2[2] = quadMidNode(U[1], U[0], pt(s4), e, RPNi);
        tr->addQuadEdge(1, midEN2[0], e, RPNi);
        t1->addQuadEdge(5, midEN2[0], e, RPNi);
        t2->addQuadEdge(2, midEN2[0], e, RPNi);
        t3->addQuadEdge(2, midEN2[0], e, RPNi);

        tr->addQuadEdge(2, midEN2[1], e, RPNi);
        t1->addQuadEdge(2, midEN2[1], e, RPNi);
        t2->addQuadEdge(5, midEN2[1], e, RPNi);

        tr->addQuadEdge(0, midEN2[2], e, RPNi);
        if(t2->addQuadEdge(0, midEN2[2], e, RPNi)) {
          t1->addQuadEdge(0, midEN2[2], e, RPNi);
        }
        else {
          DI_Point* mid = middle(pt(s3), pt(s4), e, RPNi);
          DI_Point* quad = middle(mid, midEN2[2], e, RPNi);
          if(qual == 1){
            t2->addQuadEdge(1, quad, e, RPNi);
            t3->addQuadEdge(0, quad, e, RPNi);
          }
          else {
            t2->addQuadEdge(3, quad, e, RPNi);
            t3->addQuadEdge(1, quad, e, RPNi);
          }
          if(t2->addQuadEdge(0, midEN2[2], e, RPNi)) {
            t1->addQuadEdge(0, midEN2[2], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U1 to the subtetrahedra cas 2.\n");
          delete mid; delete quad;
        }
        delete midEN2[0]; delete midEN2[1]; delete midEN2[2];
      }

      subTetras.push_back(t1);
      subTetras.push_back(t2);
      subTetras.push_back(t3);
      surfTriangles.push_back(tr);
      delete U[0]; delete U[1];
      break;
    }
    case 3 : {// 3 edges cut => 1 tetra + 1 prism => split into 4 tetras
      int i1 = IND[0], i2 = IND[1], i3 = IND[2];

      if(i1 == 0 && i2 == 3) {
        swap(&U[1], &U[2]); swap(i2, i3);
      }
      //printf("case 3 : ind : %d,%d,%d\n",i1,i2,i3);

      int s1 = commonV(tab[i1][0], tab[i1][1], tab[i2][0], tab[i2][1]);
      int s2 = commonV(tab[i2][2], tab[i2][3], tab[i3][2], tab[i3][3]);
      int s3 = commonV(tab[i1][2], tab[i1][3], tab[i3][2], tab[i3][3]);
      int s4 = commonV(tab[i1][2], tab[i1][3], tab[i2][2], tab[i2][3]);

      DI_Tetra *t1 = new DI_Tetra(pt(s1), U[0], U[1], U[2]);
      DI_Triangle *tr = new DI_Triangle(U[0], U[1], U[2], tag);
      DI_Tetra *t2, *t3, *t4;
      bestQuality(U[0], U[1], U[2], pt(s2), pt(s3), pt(s4), &t2, &t3, &t4, QError);
      /*t2 = DI_Tetra(U[0],V[0],W[0], x(s2),y(s2),z(s2), U[1],V[1],W[1], U[2],V[2],W[2]);
      t3 = DI_Tetra(U[2],V[2],W[2], U[1],V[1],W[1], x(s3),y(s3),z(s3), x(s2),y(s2),z(s2));
      t4 = DI_Tetra(U[2],V[2],W[2], x(s3),y(s3),z(s3), x(s4),y(s4),z(s4), x(s2),y(s2),z(s2));*/
      if(quadT){
        DI_Point *midEN2[3]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[2], U[1], pt(s3), e, RPNi);
        midEN2[1] = quadMidNode(U[1], U[0], pt(s2), e, RPNi);
        midEN2[2] = quadMidNode(U[2], U[0], pt(s2), e, RPNi);
        tr->addQuadEdge(1, midEN2[0], e, RPNi);
        if(t3->addQuadEdge(0, midEN2[0], e, RPNi)) {
          t1->addQuadEdge(5, midEN2[0], e, RPNi);
          t2->addQuadEdge(4, midEN2[0], e, RPNi);
        }
        else {
          DI_Point *mid = middle(pt(s3), pt(s4), e, RPNi);
          DI_Point *quad = middle(mid, midEN2[0], e, RPNi);
          t3->addQuadEdge(1, quad, e, RPNi);
          t4->addQuadEdge(0, quad, e, RPNi);
          if(t3->addQuadEdge(0, midEN2[0], e, RPNi)) {
            t1->addQuadEdge(5, midEN2[0], e, RPNi);
            t2->addQuadEdge(4, midEN2[0], e, RPNi);
          }
          else printf("unable to add quadratic edge U1U2 to the subtetrahedra cas 3.\n");
          delete mid; delete quad;
        }

        tr->addQuadEdge(0, midEN2[1], e, RPNi);
        if(t2->addQuadEdge(1, midEN2[1], e, RPNi)) {
          t1->addQuadEdge(0, midEN2[1], e, RPNi);
        }
        else {
          DI_Point *mid = middle(pt(s2), pt(s3), e, RPNi);
          DI_Point *quad = middle(mid, midEN2[1], e, RPNi);
          t2->addQuadEdge(3, quad, e, RPNi);
          t3->addQuadEdge(5, quad, e, RPNi);
          if(t2->addQuadEdge(1, midEN2[1], e, RPNi)) {
            t1->addQuadEdge(0, midEN2[1], e, RPNi);
          }
          else printf("unable to add quadratic edge U1U2 to the subtetrahedra cas 3.\n");
          delete mid; delete quad;
        }

        tr->addQuadEdge(2, midEN2[2], e, RPNi);
        if(t2->addQuadEdge(2, midEN2[2], e, RPNi)) {
          t1->addQuadEdge(2, midEN2[2], e, RPNi);
        }
        else {
          DI_Point *mid = middle(pt(s2), pt(s4), e, RPNi);
          DI_Point *quad = middle(mid, midEN2[2], e, RPNi);
          t2->addQuadEdge(5, quad, e, RPNi);
          t3->addQuadEdge(2, quad, e, RPNi);
          t4->addQuadEdge(2, quad, e, RPNi);
          if(t2->addQuadEdge(2, midEN2[2], e, RPNi)) {
            t1->addQuadEdge(2, midEN2[2], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U2 to the subtetrahedra cas 3.\n");
          delete mid; delete quad;
        }
        delete midEN2[0]; delete midEN2[1]; delete midEN2[2];
      }

      subTetras.push_back(t1);
      subTetras.push_back(t2);
      subTetras.push_back(t3);
      subTetras.push_back(t4);
      surfTriangles.push_back(tr);
      delete U[0]; delete U[1]; delete U[2];
      break;
    }
    case 4 : {// 4 edges cut => 2 prisms => split into 6 tetras
      int i1 = IND[0], i2 = IND[1], i3 = IND[2], i4 = IND[3];

      if(i1 == 0 && i2 == 2) {
        swap(&U[0], &U[1]); swap(i1, i2);
      }
      else if(i1 == 1 && i2 == 2) {
        swap(&U[2], &U[3]); swap(i3, i4);
      }

      int s1 = commonV(tab[i1][0], tab[i1][1], tab[i2][0], tab[i2][1]);
      int s2 = commonV(tab[i1][0], tab[i1][1], tab[i2][2], tab[i2][3]);
      int s3 = commonV(tab[i1][2], tab[i1][3], tab[i2][0], tab[i2][1]);
      int s4 = commonV(tab[i1][2], tab[i1][3], tab[i2][2], tab[i2][3]);

      DI_Tetra *t1, *t2, *t3, *t4, *t5, *t6;
      DI_Triangle *tr1, *tr2;
      bestQuality(U[0], U[1], U[2], U[3], &tr1, &tr2);
      tr1->setLsTag(tag); tr2->setLsTag(tag);
      bestQuality(pt(s1), U[0], U[1], pt(s4), U[3], U[2], &t1, &t2, &t3, QError);
      bestQuality(pt(s2), U[0], U[3], pt(s3), U[1], U[2], &t4, &t5, &t6, QError);
      /*t1 = DI_Tetra(U[0],V[0],W[0], x(s2),y(s2),z(s2), U[1],V[1],W[1],    U[3],V[3],W[3]);
      t2 = DI_Tetra(U[1],V[1],W[1], U[3],V[3],W[3],    x(s2),y(s2),z(s2), U[2],V[2],W[2]);
      t3 = DI_Tetra(U[1],V[1],W[1], x(s2),y(s2),z(s2), x(s3),y(s3),z(s3), U[2],V[2],W[2]);
      t4 = DI_Tetra(U[0],V[0],W[0], U[1],V[1],W[1],    x(s1),y(s1),z(s1), x(s4),y(s4),z(s4));
      t5 = DI_Tetra(U[0],V[0],W[0], U[1],V[1],W[1],    x(s4),y(s4),z(s4), U[3],V[3],W[3]);
      t6 = DI_Tetra(U[3],V[3],W[3], U[1],V[1],W[1],    x(s4),y(s4),z(s4), U[2],V[2],W[2]);
      tr1 = DI_Triangle(U[0],V[0],W[0], U[1],V[1],W[1], U[3],V[3],W[3]);
      tr2 = DI_Triangle(U[1],V[1],W[1], U[2],V[2],W[2], U[3],V[3],W[3]);*/

      if(quadT){
        DI_Point *midEN2[5]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[1], U[2], pt(s4), e, RPNi);
        midEN2[1] = quadMidNode(U[1], U[0], pt(s2), e, RPNi);
        midEN2[2] = quadMidNode(U[0], U[3], pt(s4), e, RPNi);
        midEN2[3] = quadMidNode(U[2], U[3], pt(s2), e, RPNi);
        midEN2[4] = quadMidNode(U[1], U[3], pt(s2), e, RPNi);
        //quadMidNode(U[1], U[3], (pt(s2)+pt(s3))/2, (pt(s4)+pt(s1))/2, e, RPNi);
        tr2->addQuadEdge(0, midEN2[0], e, RPNi);
        if(t6->addQuadEdge(5, midEN2[0], e, RPNi)) {
          t2->addQuadEdge(2, midEN2[0], e, RPNi);
          t3->addQuadEdge(2, midEN2[0], e, RPNi);
        }
        else {
          DI_Point *mid = middle(pt(s1), pt(s4), e, RPNi);
          DI_Point *quad = middle(mid, midEN2[0], e, RPNi);
          t4->addQuadEdge(5, quad, e, RPNi);
          t5->addQuadEdge(3, quad, e, RPNi);
          t6->addQuadEdge(3, quad, e, RPNi);
          if(t6->addQuadEdge(5, midEN2[0], e, RPNi)) {
            t2->addQuadEdge(2, midEN2[0], e, RPNi);
            t3->addQuadEdge(2, midEN2[0], e, RPNi);
          }
          else printf("unable to add quadratic edge U1U2 to the subtetrahedra cas 4.\n");
          delete mid; delete quad;
        }

        tr1->addQuadEdge(0, midEN2[1], e, RPNi);
        if(t1->addQuadEdge(1, midEN2[1], e, RPNi)) {
          t4->addQuadEdge(0, midEN2[1], e, RPNi);
          t5->addQuadEdge(0, midEN2[1], e, RPNi);
        }
        else {
          DI_Point *mid = middle(pt(s2), pt(s3), e, RPNi);
          DI_Point *quad = middle(mid, midEN2[1], e, RPNi);
          t1->addQuadEdge(3, quad, e, RPNi);
          t2->addQuadEdge(1, quad, e, RPNi);
          t3->addQuadEdge(0, quad, e, RPNi);
          if(t1->addQuadEdge(1, midEN2[1], e, RPNi)) {
            t4->addQuadEdge(0, midEN2[1], e, RPNi);
            t5->addQuadEdge(0, midEN2[1], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U1 to the subtetrahedra cas 4.\n");
          delete mid; delete quad;
        }

        tr1->addQuadEdge(2, midEN2[2], e, RPNi);
        if(t5->addQuadEdge(2, midEN2[2], e, RPNi)) {
          t1->addQuadEdge(2, midEN2[2], e, RPNi);
        }
        else {
          DI_Point *mid = middle(pt(s1), pt(s4), e, RPNi);
          DI_Point *quad = middle(mid, midEN2[2], e, RPNi);
          t4->addQuadEdge(2, quad, e, RPNi);
          t5->addQuadEdge(1, quad, e, RPNi);
          if(t5->addQuadEdge(2, midEN2[2], e, RPNi)) {
            t1->addQuadEdge(2, midEN2[2], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U3 to the subtetrahedra cas 4.\n");
          delete mid; delete quad;
        }

        tr2->addQuadEdge(1, midEN2[3], e, RPNi);
        if(t2->addQuadEdge(5, midEN2[3], e, RPNi)) {
          t6->addQuadEdge(2, midEN2[3], e, RPNi);
        }
        else {
          DI_Point *mid = middle(pt(s2), pt(s3), e, RPNi);
          DI_Point *quad = middle(mid, midEN2[3], e, RPNi);
          t2->addQuadEdge(4, quad, e, RPNi);
          t3->addQuadEdge(5, quad, e, RPNi);
          if(t2->addQuadEdge(5, midEN2[3], e, RPNi)) {
            t6->addQuadEdge(2, midEN2[3], e, RPNi);
          }
          else printf("unable to add quadratic edge U2U3 to the subtetrahedra cas 4.\n");
          delete mid; delete quad;
        }

        tr1->addQuadEdge(1, midEN2[4], e, RPNi);
        tr2->addQuadEdge(2, midEN2[4], e, RPNi);
        t1->addQuadEdge(4, midEN2[4], e, RPNi);
        t2->addQuadEdge(0, midEN2[4], e, RPNi);
        t5->addQuadEdge(5, midEN2[4], e, RPNi);
        t6->addQuadEdge(0, midEN2[4], e, RPNi);
        for(int i = 0; i < 5; i++) delete midEN2[i];
      }

      subTetras.push_back(t1);
      subTetras.push_back(t2);
      subTetras.push_back(t3);
      subTetras.push_back(t4);
      subTetras.push_back(t5);
      subTetras.push_back(t6);
      surfTriangles.push_back(tr1);
      surfTriangles.push_back(tr2);
      for(int i = 0; i < 4; i++) delete U[i];
      break;
    }
    default:
      printf("Error : %d edge(s) cut in the tetrahedron (ls : %g %g %g %g)\n",
             COUNT, ls(0), ls(1), ls(2), ls(3));
  }
}

// Split a reference Hexahedron into 6 tetrahedra
void DI_Hexa::splitIntoTetras(std::vector<DI_Tetra *> &tetras) const
{
  tetras.push_back(new DI_Tetra(pt(0), pt(1), pt(3), pt(4))); // 0134
  tetras.push_back(new DI_Tetra(pt(1), pt(4), pt(5), pt(7))); // 1457
  tetras.push_back(new DI_Tetra(pt(1), pt(3), pt(4), pt(7))); // 1347
  tetras.push_back(new DI_Tetra(pt(2), pt(5), pt(6), pt(7))); // 2567
  tetras.push_back(new DI_Tetra(pt(1), pt(2), pt(3), pt(7))); // 1237
  tetras.push_back(new DI_Tetra(pt(1), pt(5), pt(2), pt(7))); // 1527
}

// -----------------------------------------------------------------------------
// -------------------INTEGRATION POINTS --------------------------------------
// -----------------------------------------------------------------------------

// return the integration points in the reference line
void DI_Line::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint *> &ip) const {
  int N = getNGQLPts(polynomialOrder);
  IntPt* intpt (getGQLPts(polynomialOrder));
  for (int i = 0; i < N; ++i){
    ip.push_back(new DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference triangle
void DI_Triangle::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint *> &ip) const {
  int pO = polynomialOrder;
  if(pO == 11 || pO == 16 || pO == 18 || pO == 20) pO++;
  if(pO == 15) pO = 17;
  int N = getNGQTPts(pO);
  IntPt* intpt (getGQTPts(pO));
  for (int i = 0; i < N; ++i){
    ip.push_back(new DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference triangle
void DI_Quad::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint *> &ip) const {
  int N = getNGQQPts(polynomialOrder);
  IntPt* intpt (getGQQPts(polynomialOrder));
  for (int i = 0; i < N; ++i){
    ip.push_back(new DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference tetra
void DI_Tetra::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint *> &ip) const {
  int pO = polynomialOrder;
  if(pO == 9) pO++;
  int N = getNGQTetPts(pO);
  IntPt* intpt (getGQTetPts(pO));
  for (int i = 0; i < N; ++i){
    ip.push_back(new DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference Cube
void DI_Hexa::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint *> &ip) const {
  int N = getNGQHPts(polynomialOrder);
  IntPt* intpt (getGQHPts(polynomialOrder));
  for (int i = 0; i < N; ++i){
    ip.push_back(new DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// -----------------------------------------------------------------------------
// ----------------------------- CUTTING  --------------------------------------
// -----------------------------------------------------------------------------

// cut a line into sublines along the levelset curve
bool DI_Line::cut (std::vector<gLevelset *> &RPN, std::vector<DI_IntegrationPoint *> &ip,
                   DI_Point::Container &cp, const int polynomialOrder,
                   std::vector<DI_Line *> &lines, int recurLevel, double **nodeLs) const
{
  std::vector<gLevelset *> RPNi; RPNi.reserve(RPN.size());

  DI_Line *ll = new DI_Line(-1, 0, 0, 1, 0, 0, 2.); //reference line
  ll->setPolynomialOrder(getPolynomialOrder());
  std::vector<DI_Line *> ll_subLines;
  std::vector<DI_CuttingPoint *> ll_cp;

  RecurElement *re = new RecurElement(ll);
  bool signChange = re->cut(recurLevel, this, RPN, -1., nodeLs);
  pushSubElements(re, ll_subLines);
  delete re;

  int iPrim = 0;
  if(signChange){
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        ll->addLs(this, Lsi, iPrim++, nodeLs);
        int nbSubLn = ll_subLines.size();
        int nbCP = ll_cp.size();
        for(int i = 0; i < nbSubLn; i++) ll_subLines[i]->addLs(ll);
        for(int i = 0; i < nbCP; i++) ll_cp[i]->addLs(ll);

        for(int ln = 0; ln < nbSubLn; ln++){
          DI_Line *lnt = ll_subLines[0];
          ll_subLines.erase(ll_subLines.begin());
          bool c = lnt->cut(ll, RPNi, ll_subLines, ll_cp);
          if(c) delete lnt;
        }
      }
      else {
        for(int l = 0; l < (int)ll_subLines.size(); l++)
          ll_subLines[l]->chooseLs(Lsi);
        for(int p = 0; p < (int)ll_cp.size(); p++)
          ll_cp[p]->chooseLs(Lsi);
      }
    }
  }
  else{
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      if(Lsi->isPrimitive()) {
        ll->addLs(this, Lsi, iPrim++, nodeLs);
      }
    }
    if(iPrim == 1) iPrim--;
    ll_subLines[0]->addLs(this, RPN.back(), iPrim, nodeLs);
  }

  for(int l = 0; l < (int)ll_subLines.size(); l++) {
    ll_subLines[l]->computeLsTagDom(ll, RPN);
    DI_Line *ll_subLn = new DI_Line(*ll_subLines[l]);
    mappingEl(ll_subLines[l]);
    ll_subLines[l]->integrationPoints(polynomialOrder, ll_subLn, ll, RPN, ip);
    lines.push_back(ll_subLines[l]);
    delete ll_subLn;
  }
  for(int p = 0; p < (int)ll_cp.size(); p++) {
    if(ll_cp[p]->ls() != 0) {delete ll_cp[p]; continue;}
    mappingCP(ll_cp[p]);
    std::pair<DI_Point::Container::iterator,bool> isIn = cp.insert(ll_cp[p]);
    if(!isIn.second) delete ll_cp[p];
  }
  delete ll;
  return signChange;
}

// cut a line into sublines along one levelset primitive and return true if it is cut
bool DI_Line::cut(const DI_Element *e, const std::vector<gLevelset *> &RPNi,
           std::vector<DI_Line *> &subLines, std::vector<DI_CuttingPoint *> &cp)
{
  // check if the line is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[2];
  for (int i = 0; i < 2; i++){
    if(pt(i)->isOnBorder()) ze[on++] = i;
    else if (ls(i) > 0.) pos++;
    else neg++;
  }
  if(pos && neg)
    selfSplit(e, RPNi, subLines, cp);
  else {
    for(int i = 0; i < on; i++)
      cp.push_back(new DI_CuttingPoint(pt(ze[i])));
    subLines.push_back(this);
  }
  return (pos && neg);
}

// cut a triangle into subtriangles along the levelset curve
bool DI_Triangle::cut (std::vector<gLevelset *> &RPN, std::vector<DI_IntegrationPoint *> &ip,
                       std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
                       const int polynomialOrderQ, const int polynomialOrderTr, const int polynomialOrderL,
                       std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
                       std::vector<DI_Line *> &surfLines, int recurLevel, double **nodeLs) const
{
  std::vector<gLevelset *> RPNi; RPNi.reserve(RPN.size());

  DI_Triangle *tt = new DI_Triangle(0, 0, 0, 1, 0, 0, 0, 1, 0, 0.5); //reference triangle
  tt->setPolynomialOrder(getPolynomialOrder());
  std::vector<DI_Quad *> tt_subQuads;
  std::vector<DI_Triangle *> tt_subTriangles;
  std::vector<DI_Line *> tt_surfLines;
  std::vector<DI_CuttingPoint *> tt_cp;

  RecurElement *re = new RecurElement(tt);
  bool signChange = re->cut(recurLevel, this, RPN, -1., nodeLs);
  pushSubElements(re, tt_subTriangles);
  delete re;

  int iPrim = 0;
  if(signChange){
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        tt->addLs(this, Lsi, iPrim++, nodeLs);
        int nbSubQ = tt_subQuads.size(), nbSubQ1 = nbSubQ;
        int nbSubTr = tt_subTriangles.size(), nbSubTr1 = nbSubTr;
        int nbSurfLn = tt_surfLines.size(), nbSurfLn1 = nbSurfLn;
        int nbCP = tt_cp.size();
        for(int i = 0; i < nbSubQ; i++) tt_subQuads[i]->addLs(tt);
        for(int i = 0; i < nbSubTr; i++) tt_subTriangles[i]->addLs(tt);
        for(int i = 0; i < nbSurfLn; i++) tt_surfLines[i]->addLs(tt);
        for(int i = 0; i < nbCP; i++) tt_cp[i]->addLs(tt);
        int ze[3], cz = 0;
        for (int i = 0; i < 3; i++) if(tt->pt(i)->isOnBorder()) ze[cz++] = i;

        for(int q = 0; q < nbSubQ; q++) {
          nbSubQ1 = tt_subQuads.size();
          nbSurfLn1 = tt_surfLines.size();
          DI_Quad *qt = tt_subQuads[0];
          tt_subQuads.erase(tt_subQuads.begin());
          bool c = qt->cut(tt, RPNi, tt_subQuads, tt_subTriangles, tt_surfLines, tt_cp);
          if(c) delete qt;
          if((int)tt_surfLines.size() - nbSurfLn1 == 1 && (int)tt_subQuads.size() == nbSubQ1){ // 1 line created on boundary of the quad
            if (cz == 2) { // 1 line created on boundary of the big triangle => check among surfLines
              DI_Line lf (pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if (lf.contain(surfLines[i])){ // line allready created on another surface => pop the new one
                  delete tt_surfLines.back(); tt_surfLines.pop_back(); break;
                }
              }
            }
            else { // 1 line created inside the big triangle => check among tt_surfLines
              if(isLastLnInV(tt_surfLines)) {
                delete tt_surfLines.back(); tt_surfLines.pop_back();
              }
            }
          }
        }
        for(int t = 0; t < nbSubTr; t++){
          nbSubTr1 = tt_subTriangles.size();
          nbSurfLn1 = tt_surfLines.size();
          DI_Triangle *trt = tt_subTriangles[0];
          tt_subTriangles.erase(tt_subTriangles.begin());
          bool c = trt->cut(tt, RPNi, tt_subQuads, tt_subTriangles, tt_surfLines, tt_cp);
          if(c) delete trt;
          if((int)tt_surfLines.size() - nbSurfLn1 == 1  && (int)tt_subTriangles.size() == nbSubTr1) { // 1 line created on boundary of the triangle
            if(cz == 2) { // 1 line created on boundary of the big triangle => check among surfLines
              DI_Line lf(pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if(lf.contain(surfLines[i])) {
                  delete tt_surfLines.back(); tt_surfLines.pop_back(); break;
                }
              }
            }
            else{ // 1 line created inside the big triangle => check among tt_surfLines
              if(isLastLnInV(tt_surfLines)) {
                delete tt_surfLines.back(); tt_surfLines.pop_back();
              }
            }
          }
        }
        for(int ln = 0; ln < nbSurfLn; ln++){
          DI_Line* lnt = tt_surfLines[0];
          tt_surfLines.erase(tt_surfLines.begin());
          bool c = lnt->cut(tt, RPNi, tt_surfLines, tt_cp);
          if(c) delete lnt;
        }
      }
      else {
        for(int q = 0; q < (int)tt_subQuads.size(); q++)
          tt_subQuads[q]->chooseLs(Lsi);
        for(int t = 0; t < (int)tt_subTriangles.size(); t++)
          tt_subTriangles[t]->chooseLs(Lsi);
        for(int l = 0; l < (int)tt_surfLines.size(); l++)
          tt_surfLines[l]->chooseLs(Lsi);
        for(int p = 0; p < (int)tt_cp.size(); p++)
          tt_cp[p]->chooseLs(Lsi);
      }
    }
  }
  else{
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      if(Lsi->isPrimitive()) {
        tt->addLs(this, Lsi, iPrim++, nodeLs);
      }
    }
    if(iPrim == 1) iPrim--;
    tt_subTriangles[0]->addLs(this, RPN.back(), iPrim, nodeLs);
  }

  for(int q = 0; q < (int)tt_subQuads.size(); q++) {
    tt_subQuads[q]->computeLsTagDom(tt, RPN);
    DI_Quad *tt_subQ = new DI_Quad(*tt_subQuads[q]);
    mappingEl(tt_subQuads[q]);
    tt_subQuads[q]->integrationPoints(polynomialOrderQ, tt_subQ, tt, RPN, ip);
    subQuads.push_back(tt_subQuads[q]);
    delete tt_subQ;
  }
  for(int t = 0; t < (int)tt_subTriangles.size(); t++) {
    tt_subTriangles[t]->computeLsTagDom(tt, RPN);
    DI_Triangle *tt_subTr = new DI_Triangle(*tt_subTriangles[t]);
    mappingEl(tt_subTriangles[t]);
    tt_subTriangles[t]->integrationPoints(polynomialOrderTr, tt_subTr, tt, RPN, ip);
    subTriangles.push_back(tt_subTriangles[t]);
    delete tt_subTr;
  }
  for(int l = 0; l < (int)tt_surfLines.size(); l++) {
    tt_surfLines[l]->computeLsTagBound(tt_subQuads, tt_subTriangles);
    if(tt_surfLines[l]->lsTag() == -1) {delete tt_surfLines[l]; continue;}
    DI_Line *tt_surfLn = new DI_Line(*tt_surfLines[l]);
    mappingEl(tt_surfLines[l]);
    tt_surfLines[l]->integrationPoints(polynomialOrderL, tt_surfLn, tt, RPN, ipS);
    surfLines.push_back(tt_surfLines[l]);
    delete tt_surfLn;
  }
  for(int p = 0; p < (int)tt_cp.size(); p++) {
    if(tt_cp[p]->ls() != 0) {delete tt_cp[p]; continue;}
    mappingCP(tt_cp[p]);
    std::pair<DI_Point::Container::iterator,bool> isIn = cp.insert(tt_cp[p]);
    if(!isIn.second) delete tt_cp[p];
  }
  delete tt;
  return signChange;
}

// cut a triangle into subtriangles along one levelset primitive
bool DI_Triangle::cut (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                    std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
                    std::vector<DI_Line *> &surfLines, std::vector<DI_CuttingPoint *> &cp)
{
  // check if the triangle is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[3];
  for (int i = 0; i < 3; i++){
    if(pt(i)->isOnBorder()) ze[on++] = i;
    else if (pt(i)->ls() > 0.) pos++;
    else neg++;
  }
  if(pos && neg)
    selfSplit(e, RPNi, subQuads, subTriangles, surfLines, cp);
  else {
    if(on == 2){ // the level set is zero on an edge of the triangle
      surfLines.push_back(new DI_Line(pt(ze[0]), pt(ze[1]), RPNi.back()->getTag()));
      // add the line twice if the edge belongs to 2 triangles => remove it later!
    }
    if(on == 3)
      printf("Warning : triangle with zero levelset on every vertex.\n");
    for(int i = 0; i < on; i++)
      cp.push_back(new DI_CuttingPoint(pt(ze[i])));
    subTriangles.push_back(this);
  }
  return (pos && neg);
}

// cut a quadrangle into subtriangles along the levelset curve
bool DI_Quad::cut (std::vector<gLevelset *> &RPN, std::vector<DI_IntegrationPoint *> &ip,
                   std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
                   const int polynomialOrderQ, const int polynomialOrderTr, const int polynomialOrderL,
                   std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
                   std::vector<DI_Line *> &surfLines, int recurLevel, double **nodeLs) const
{
  std::vector<gLevelset *> RPNi; RPNi.reserve(RPN.size());

  DI_Quad *qq = new DI_Quad(-1, -1, 0, 1, -1, 0, 1, 1, 0, -1, 1, 0, 4.); // reference quad
  qq->setPolynomialOrder(getPolynomialOrder());
  std::vector<DI_Quad *> qq_subQuads;
  std::vector<DI_Triangle *> qq_subTriangles;
  std::vector<DI_Line *> qq_surfLines;
  std::vector<DI_CuttingPoint *> qq_cp;

  RecurElement *re =  new RecurElement(qq);
  bool signChange = re->cut(recurLevel, this, RPN, -1., nodeLs);
  pushSubElements(re, qq_subQuads);
  delete re;

  int iPrim = 0;
  if(signChange) {
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        qq->addLs(this, Lsi, iPrim++, nodeLs);
        int nbSubQ = qq_subQuads.size(), nbSubQ1 = nbSubQ;
        int nbSubTr = qq_subTriangles.size(), nbSubTr1 = nbSubTr;
        int nbSurfLn = qq_surfLines.size(), nbSurfLn1 = nbSurfLn;
        int nbCP = qq_cp.size();
        for(int i = 0; i < nbSubQ; i++) qq_subQuads[i]->addLs(qq);
        for(int i = 0; i < nbSubTr; i++) qq_subTriangles[i]->addLs(qq);
        for(int i = 0; i < nbSurfLn; i++) qq_surfLines[i]->addLs(qq);
        for(int i = 0; i < nbCP; i++) qq_cp[i]->addLs(qq);
        int pos = 0, neg = 0, ze[4], cz = 0;
        for (int i = 0; i < 4; i++){
          if(qq->pt(i)->isOnBorder()) ze[cz++] = i;
          else if (qq->ls(i) > 0.) pos++;
          else neg++;
        }

        for(int q = 0; q < nbSubQ; q++) {
          nbSubQ1 = qq_subQuads.size();
          nbSurfLn1 = qq_surfLines.size();
          DI_Quad *qt = qq_subQuads[0];
          qq_subQuads.erase(qq_subQuads.begin());
          bool c = qt->cut(qq, RPNi, qq_subQuads, qq_subTriangles, qq_surfLines, qq_cp);
          if(c) delete qt;
          if((int)qq_surfLines.size() - nbSurfLn1 == 1 && (int)qq_subQuads.size() == nbSubQ1){ // 1 line created on boundary of the quad
            if (cz == 2 && !(pos && neg)) { // 1 line created on boundary of the big quad => check among surfLines
              DI_Line lf (pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if (lf.contain(surfLines[i])){ // line allready created on another surface => pop the new one
                  delete qq_surfLines.back(); qq_surfLines.pop_back(); break;
                }
              }
            }
            else { // 1 line created inside the big quad => check among qq_surfLines
              if(isLastLnInV(qq_surfLines)) {
                delete qq_surfLines.back(); qq_surfLines.pop_back();
              }
            }
          }
        }
        for(int t = 0; t < nbSubTr; t++){
          nbSubTr1 = qq_subTriangles.size();
          nbSurfLn1 = qq_surfLines.size();
          DI_Triangle *trt = qq_subTriangles[0];
          qq_subTriangles.erase(qq_subTriangles.begin());
          bool c = trt->cut(qq, RPNi, qq_subQuads, qq_subTriangles, qq_surfLines, qq_cp);
          if(c) delete trt;
          if((int)qq_surfLines.size() - nbSurfLn1 == 1  && (int)qq_subTriangles.size() == nbSubTr1) { // 1 line created on boundary of the triangle
            if(cz == 2 && !(pos && neg)) { // 1 line created on boundary of the big quad => check among surfLines
              DI_Line lf(pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if(lf.contain(surfLines[i])) {
                  delete qq_surfLines.back(); qq_surfLines.pop_back(); break;
                }
              }
            }
            else{ // 1 line created inside the big quad => check among qq_surfLines
              if(isLastLnInV(qq_surfLines)) {
                delete qq_surfLines.back(); qq_surfLines.pop_back();
              }
            }
          }
        }
        for(int ln = 0; ln < nbSurfLn; ln++){
          DI_Line *lnt = qq_surfLines[0];
          qq_surfLines.erase(qq_surfLines.begin());
          bool c = lnt->cut(qq, RPNi, qq_surfLines, qq_cp);
          if(c) delete lnt;
        }
      }
      else {
        for(int q = 0; q < (int)qq_subQuads.size(); q++)
          qq_subQuads[q]->chooseLs(Lsi);
        for(int t = 0; t < (int)qq_subTriangles.size(); t++)
          qq_subTriangles[t]->chooseLs(Lsi);
        for(int l = 0; l < (int)qq_surfLines.size(); l++)
          qq_surfLines[l]->chooseLs(Lsi);
        for(int p = 0; p < (int)qq_cp.size(); p++)
          qq_cp[p]->chooseLs(Lsi);
      }
    }
  }
  else {
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      if(Lsi->isPrimitive()) {
        qq->addLs(this, Lsi, iPrim++, nodeLs);
      }
    }
    if(iPrim == 1) iPrim--;
    qq_subQuads[0]->addLs(this, RPN.back(), iPrim, nodeLs);
  }

  for(int q = 0; q < (int)qq_subQuads.size(); q++) {
    qq_subQuads[q]->computeLsTagDom(qq, RPN);
    DI_Quad *qq_subQ = new DI_Quad(*qq_subQuads[q]);
    mappingEl(qq_subQuads[q]);
    qq_subQuads[q]->integrationPoints(polynomialOrderQ, qq_subQ, qq, RPN, ip);
    subQuads.push_back(qq_subQuads[q]);
    delete qq_subQ;
  }
  for(int t = 0; t < (int)qq_subTriangles.size(); t++) {
    qq_subTriangles[t]->computeLsTagDom(qq, RPN);
    DI_Triangle *qq_subTr = new DI_Triangle(*qq_subTriangles[t]);
    mappingEl(qq_subTriangles[t]);
    qq_subTriangles[t]->integrationPoints(polynomialOrderTr, qq_subTr, qq, RPN, ip);
    subTriangles.push_back(qq_subTriangles[t]);
    delete qq_subTr;
  }
  for(int l = 0; l < (int)qq_surfLines.size(); l++) {
    qq_surfLines[l]->computeLsTagBound(qq_subQuads, qq_subTriangles);
    if(qq_surfLines[l]->lsTag() == -1) {delete qq_surfLines[l]; continue;}  //FIXME
    DI_Line *qq_surfLn = new DI_Line(*qq_surfLines[l]);
    mappingEl(qq_surfLines[l]);
    qq_surfLines[l]->integrationPoints(polynomialOrderL, qq_surfLn, qq, RPN, ipS);
    surfLines.push_back(qq_surfLines[l]);
    delete qq_surfLn;
  }
  for(int p = 0; p < (int)qq_cp.size(); p++) {
    if(qq_cp[p]->ls() != 0) {delete qq_cp[p]; continue;}
    mappingCP(qq_cp[p]);
    std::pair<DI_Point::Container::iterator,bool> isIn = cp.insert(qq_cp[p]);
    if(!isIn.second) delete qq_cp[p];
  }
  delete qq;
  return signChange;
}

// cut a quadrangle into subtriangles along the levelset curve
bool DI_Quad::cut (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                std::vector<DI_Quad *> &subQuads, std::vector<DI_Triangle *> &subTriangles,
                std::vector<DI_Line *> &surfLines, std::vector<DI_CuttingPoint *> &cp)
{
  // check if the quadrangle is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[4];
  for (int i = 0; i < 4; i++){
    if(pt(i)->isOnBorder()) ze[on++] = i;
    else if (pt(i)->ls() > 0.) pos++;
    else neg++;
  }
  if (pos && neg) {
    std::vector<DI_Triangle *> triangles;
    splitIntoTriangles (triangles); // Split the quad into 2 sub triangles
    int nl0 = surfLines.size(), nt1, nl1, nt2, nl2;
    for (int t = 0; t < (int)triangles.size(); t++) {
      nt1 = subTriangles.size(); nl1 = surfLines.size();
      triangles[t]->selfSplit(e, RPNi, subQuads, subTriangles, surfLines, cp);
      nt2 = subTriangles.size(); nl2 = surfLines.size();
      if((nt2 - nt1) == 1 && (nl2 - nl1) == 1){ // only 1 line created on an edge of a triangle => check if it was not yet created
        if(isLastLnInV(surfLines, nl0)) {delete surfLines.back(); surfLines.pop_back(); nl2--;}
      }
    }
  }
  else {
    if(on == 2){ // the level set is zero on an edge of the quad
      surfLines.push_back(new DI_Line(pt(ze[0]), pt(ze[1]), RPNi.back()->getTag()));
      // we add the line twice if the edge belongs to 2 quads => remove it later!
    }
    if(on == 4)
      printf("Warning : quadrangle with zero levelset on every vertex.\n");
    for(int i = 0; i < on; i++)
      cp.push_back(new DI_CuttingPoint(pt(ze[i])));
    subQuads.push_back(this);
  }
  return (pos && neg);
}

// cut a tetrahedron into subtetrahedra along the levelset surface
bool DI_Tetra::cut (std::vector<gLevelset *> &RPN, std::vector<DI_IntegrationPoint *> &ip,
                    std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
                    const int polynomialOrderT, const int polynomialOrderQ, const int polynomialOrderTr,
                    std::vector<DI_Tetra *> &subTetras, std::vector<DI_Quad *> &surfQuads,
                    std::vector<DI_Triangle *> &surfTriangles, int recurLevel, double **nodeLs) const
{
  std::vector<gLevelset *> RPNi; RPNi.reserve(RPN.size());

  DI_Tetra *tt = new DI_Tetra(0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1./6.); // reference tetra
  tt->setPolynomialOrder(getPolynomialOrder());
  std::vector<DI_Hexa *> tt_subHexas;
  std::vector<DI_Tetra *> tt_subTetras;
  std::vector<DI_Quad *> tt_surfQuads;
  std::vector<DI_Triangle *> tt_surfTriangles;
  std::vector<DI_Line *> tt_surfLines;  // not used ...
  std::vector<DI_CuttingPoint *> tt_cp;
  std::vector<DI_QualError *> QError;

  RecurElement *re = new RecurElement(tt);
  bool signChange = re->cut(recurLevel, this, RPN, -1., nodeLs);
  pushSubElements(re, tt_subTetras);
  delete re;

  int iPrim = 0;
  if(signChange) {
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        tt->addLs(this, Lsi, iPrim++, nodeLs);
        int nbSubT = tt_subTetras.size(), nbSubT1 = nbSubT;
        int nbSurfQ = tt_surfQuads.size();
        int nbSurfTr = tt_surfTriangles.size(), nbSurfTr1 = nbSurfTr;
        int nbCP = tt_cp.size();
        for(int i = 0; i < nbSubT; i++) tt_subTetras[i]->addLs(tt);
        for(int i = 0; i < nbSurfQ; i++) tt_surfQuads[i]->addLs(tt);
        for(int i = 0; i < nbSurfTr; i++) tt_surfTriangles[i]->addLs(tt);
        for(int i = 0; i < nbCP; i++) tt_cp[i]->addLs(tt);
        int ze[4], cz = 0;
        for (int i = 0; i < 4; i++) if(tt->pt(i)->isOnBorder()) ze[cz++] = i;

        for(int t = 0; t < nbSubT; t++) {
          nbSurfTr1 = tt_surfTriangles.size();
          nbSubT1 = tt_subTetras.size();
          DI_Tetra *tet = tt_subTetras[0];
          tt_subTetras.erase(tt_subTetras.begin());
          bool c = tet->cut(tt, RPNi, tt_subTetras, tt_surfQuads, tt_surfTriangles, tt_cp, QError);
          if(c) delete tet;
          if((int)tt_surfTriangles.size() - nbSurfTr1 == 1 && (int)tt_subTetras.size() == nbSubT1) { // 1 triangle created on surface of the subtetra
            // check among the tt_surfTriangles
            if(isLastTrInV(tt_surfTriangles)) {
              delete tt_surfTriangles.back(); tt_surfTriangles.pop_back();
            }
            else if(cz == 3) { // 1 triangle created on surface of the reference tet => check among surfTriangles
              DI_Triangle tf(pt(ze[0]), pt(ze[1]), pt(ze[2]));
              for(int i = (int)surfTriangles.size() - 1; i >= 0; i--){
                if(tf.contain(surfTriangles[i])) {
                  delete tt_surfTriangles.back(); tt_surfTriangles.pop_back(); break;
                }
              }
            }
          }
        }
        for(int q = 0; q < nbSurfQ; q++) {
          DI_Quad *qt = tt_surfQuads[0];
          tt_surfQuads.erase(tt_surfQuads.begin());
          bool c = qt->cut(tt, RPNi, tt_surfQuads, tt_surfTriangles, tt_surfLines, tt_cp);
          if(c) delete qt;
        }
        for(int t = 0; t < nbSurfTr; t++){
          DI_Triangle *trt = tt_surfTriangles[0];
          tt_surfTriangles.erase(tt_surfTriangles.begin());
          bool c = trt->cut(tt, RPNi, tt_surfQuads, tt_surfTriangles, tt_surfLines, tt_cp);
          if(c) delete trt;
        }
      }
      else {
        for(int t = 0; t < (int)tt_subTetras.size(); t++)
          tt_subTetras[t]->chooseLs(Lsi);
        for(int q = 0; q < (int)tt_surfQuads.size(); q++)
          tt_surfQuads[q]->chooseLs(Lsi);
        for(int t = 0; t < (int)tt_surfTriangles.size(); t++)
          tt_surfTriangles[t]->chooseLs(Lsi);
        for(int p = 0; p < (int)tt_cp.size(); p++)
          tt_cp[p]->chooseLs(Lsi);
      }
    }
  }
  else {
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      if(Lsi->isPrimitive()) {
        tt->addLs(this, Lsi, iPrim++, nodeLs);
      }
    }
    if(iPrim == 1) iPrim--;
    tt_subTetras[0]->addLs(this, RPN.back(), iPrim, nodeLs);
  }

  for(int i = 0; i < (int)QError.size(); i++) {
    QError[i]->print(this);
    delete QError[i];
  }

  for(int t = 0; t < (int)tt_subTetras.size(); t++) {
    tt_subTetras[t]->computeLsTagDom(tt, RPN);
    DI_Tetra *tt_subT = new DI_Tetra(*tt_subTetras[t]);
    mappingEl(tt_subTetras[t]);
    tt_subTetras[t]->integrationPoints(polynomialOrderT, tt_subT, tt, RPN, ip);
    subTetras.push_back(tt_subTetras[t]);
    delete tt_subT;
  }
  for(int q = 0; q < (int)tt_surfQuads.size(); q++) {
    tt_surfQuads[q]->computeLsTagBound(tt_subHexas, tt_subTetras);
    if(tt_surfQuads[q]->lsTag() == -1) {delete tt_surfQuads[q]; continue;}
    DI_Quad *tt_surfQ = new DI_Quad(*tt_surfQuads[q]);
    mappingEl(tt_surfQuads[q]);
    tt_surfQuads[q]->integrationPoints(polynomialOrderQ, tt_surfQ, tt, RPN, ipS);
    surfQuads.push_back(tt_surfQuads[q]);
    delete tt_surfQ;
  }
  for(int t = 0; t < (int)tt_surfTriangles.size(); t++) {
    tt_surfTriangles[t]->computeLsTagBound(tt_subHexas, tt_subTetras);
    if(tt_surfTriangles[t]->lsTag() == -1) {delete tt_surfTriangles[t]; continue;}
    DI_Triangle *tt_surfTr = new DI_Triangle(*tt_surfTriangles[t]);
    mappingEl(tt_surfTriangles[t]);
    tt_surfTriangles[t]->integrationPoints(polynomialOrderTr, tt_surfTr, tt, RPN, ipS);
    surfTriangles.push_back(tt_surfTriangles[t]);
    delete tt_surfTr;
  }
  for(int p = 0; p < (int)tt_cp.size(); p++) {
    if(tt_cp[p]->ls() != 0) {delete tt_cp[p]; continue;}
    mappingCP(tt_cp[p]);
    std::pair<DI_Point::Container::iterator,bool> isIn = cp.insert(tt_cp[p]);
    if(!isIn.second) delete tt_cp[p];
  }
  delete tt;
  return signChange;
}

// cut a tetrahedron into subtetrahedra along the levelset surface
bool DI_Tetra::cut (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                 std::vector<DI_Tetra *> &subTetras, std::vector<DI_Quad *> &surfQuads,
                 std::vector<DI_Triangle *> &surfTriangles, std::vector<DI_CuttingPoint *> &cp,
                 std::vector<DI_QualError *> &QError)
{
  // check if the tetra is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[4];
  for (int i = 0; i < 4; i++){
    if(pt(i)->isOnBorder()) ze[on++] = i;
    else if (pt(i)->ls() > 0.) pos++;
    else neg++;
  }
  if (pos && neg)
    selfSplit(e, RPNi, subTetras, surfTriangles, cp, QError);
  else{
    if(on == 3){ // the level set is zero on a face of the tetra
      surfTriangles.push_back(new DI_Triangle(pt(ze[0]), pt(ze[1]), pt(ze[2]), RPNi.back()->getTag()));
      // add the triangle twice if the face belongs to 2 tetras => remove it later!
    }
    if(on == 4)
      printf("Warning : tetrahedron with zero levelset on every vertex.\n");
    for(int i = 0; i < on; i++)
      cp.push_back(new DI_CuttingPoint(pt(ze[i])));
    subTetras.push_back(this); // add the tetra to subTetras if it is not cut
  }
  return (pos && neg);
}

// cut a hex into subtetras along the levelset surface
bool DI_Hexa::cut (std::vector<gLevelset *> &RPN, std::vector<DI_IntegrationPoint *> &ip,
                   std::vector<DI_IntegrationPoint *> &ipS, DI_Point::Container &cp,
                   const int polynomialOrderH, const int polynomialOrderT,
                   const int polynomialOrderQ, const int polynomialOrderTr,
                   std::vector<DI_Hexa *> &subHexas, std::vector<DI_Tetra *> &subTetras,
                   std::vector<DI_Quad *> &surfQuads, std::vector<DI_Triangle *> &surfTriangles,
                   std::vector<DI_Line *> &frontLines, int recurLevel, double **nodeLs) const
{
  std::vector<gLevelset *> RPNi; RPNi.reserve(RPN.size());

 // reference hexa
  DI_Hexa *hh = new DI_Hexa(-1, -1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, 8.);
  hh->setPolynomialOrder(getPolynomialOrder());
  std::vector<DI_Hexa *> hh_subHexas;
  std::vector<DI_Tetra *> hh_subTetras;
  std::vector<DI_Quad *> hh_surfQuads;
  std::vector<DI_Triangle *> hh_surfTriangles;
  std::vector<DI_Line *> hh_frontLines;
  std::vector<DI_CuttingPoint *> hh_cp;
  std::vector<DI_QualError *> QError;

  RecurElement *re = new RecurElement(hh);
  bool signChange = re->cut(recurLevel, this, RPN, -1., nodeLs);
  pushSubElements(re, hh_subHexas);
  delete re;

  int iPrim = 0;
  if(signChange){
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        hh->addLs(this, Lsi, iPrim++, nodeLs);
        int nbSubH = hh_subHexas.size();
        int nbSubT = hh_subTetras.size(), nbSubT1 = nbSubT;
        int nbSurfQ = hh_surfQuads.size(), nbSurfQ1 = nbSurfQ;
        int nbSurfTr = hh_surfTriangles.size(), nbSurfTr1 = nbSurfTr;
        int nbFrontLn = hh_frontLines.size();
        int nbCP = hh_cp.size();
        for(int i = 0; i < nbSubH; i++) hh_subHexas[i]->addLs(hh);
        for(int i = 0; i < nbSubT; i++) hh_subTetras[i]->addLs(hh);
        for(int i = 0; i < nbSurfQ; i++) hh_surfQuads[i]->addLs(hh);
        for(int i = 0; i < nbSurfTr; i++) hh_surfTriangles[i]->addLs(hh);
        for(int i = 0; i < nbFrontLn; i++) hh_frontLines[i]->addLs(hh);
        for(int i = 0; i < nbCP; i++) hh_cp[i]->addLs(hh);
        int pos = 0, neg = 0, ze[8], cz = 0;
        for (int i = 0; i < 8; i++){
          if(hh->pt(i)->isOnBorder()) ze[cz++] = i;
          else if (hh->ls(i) > 0.) pos++;
          else neg++;
        }

        for(int h = 0; h < nbSubH; h++) {
          nbSurfQ1 = hh_surfQuads.size();
          DI_Hexa *ht = hh_subHexas[0];
          hh_subHexas.erase(hh_subHexas.begin());
          bool c = ht->cut(hh, RPNi, hh_subHexas, hh_subTetras, hh_surfQuads, hh_surfTriangles, hh_cp, QError);
          if(c) delete ht;
          if((int)hh_surfQuads.size() > nbSurfQ1){ // 1 quad created on surface of the subHexa
            if(isLastQInV(hh_surfQuads)) {
              delete hh_surfQuads.back(); hh_surfQuads.pop_back();
            }
            else if (cz == 4) {
              if(!ordered4Nodes(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3])))
                swap(ze[2], ze[3]);
              DI_Quad qf(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]));
              for(int i = (int)surfQuads.size() - 1; i >= 0; i--){
                if (qf.contain(surfQuads[i])){
                  delete hh_surfQuads.back(); hh_surfQuads.pop_back(); break;
                }
              }
              for(int i = (int)surfTriangles.size() - 1; i >= 0; i--){
                if (qf.contain(surfTriangles[i])) {
                  delete hh_surfQuads.back(); hh_surfQuads.pop_back(); break;
                }
              }
            }
          }
        }
        for(int t = 0; t < nbSubT; t++) {
          nbSurfTr1 = hh_surfTriangles.size();
          nbSubT1 = hh_subTetras.size();
          DI_Tetra *tet = hh_subTetras[0];
          hh_subTetras.erase(hh_subTetras.begin());
          bool c = tet->cut(hh, RPNi, hh_subTetras, hh_surfQuads, hh_surfTriangles, hh_cp, QError);
          if(c) delete tet;
          if((int)hh_surfTriangles.size() - nbSurfTr1 == 1 && (int)hh_subTetras.size() == nbSubT1) { // 1 triangle created on surface of the subtetra
            // check among hh_surfTriangles
            if(isLastTrInV(hh_surfTriangles)) {
              delete hh_surfTriangles.back(); hh_surfTriangles.pop_back();
            }
            else if (cz == 4 && !(pos && neg)){ // 1 triangle created on surface of the hex => check among surfTriangles
              if(!ordered4Nodes(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3])))
                swap(ze[2], ze[3]);
              DI_Quad qt(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]));
              for(int i = (int)surfTriangles.size() - 1; i >= 0; i--){
                if(qt.contain(surfTriangles[i])) {
                  delete hh_surfTriangles.back(); hh_surfTriangles.pop_back(); break;
                }
              }
            }
            else { // 1 triangle created inside the hex and not in hh_surfTriangles
              // check among the quads with quality error
              for(int i = 0; i < (int)QError.size(); i++){
                if(isInQE(hh_surfTriangles[nbSurfTr1], QError[i])) {
                  delete hh_surfTriangles.back(); hh_surfTriangles.pop_back();
                  break;
                }
              }
            }
          }
        }
        for(int q = 0; q < nbSurfQ; q++) {
          DI_Quad *qt = hh_surfQuads[0];
          hh_surfQuads.erase(hh_surfQuads.begin());
          bool c = qt->cut(hh, RPNi, hh_surfQuads, hh_surfTriangles, hh_frontLines, hh_cp);
          if(c) delete qt;
        }
        for(int t = 0; t < nbSurfTr; t++){
          DI_Triangle *trt = hh_surfTriangles[0];
          hh_surfTriangles.erase(hh_surfTriangles.begin());
          bool c = trt->cut(hh, RPNi, hh_surfQuads, hh_surfTriangles, hh_frontLines, hh_cp);
          if(c) delete trt;
        }
        for(int l = 0; l < nbFrontLn; l++){
          DI_Line *lnt = hh_frontLines[0];
          hh_frontLines.erase(hh_frontLines.begin());
          bool c = lnt->cut(hh, RPNi, hh_frontLines, hh_cp);
          if(c) delete lnt;
        }
      }
      else {
        for(int h = 0; h < (int)hh_subHexas.size(); h++)
          hh_subHexas[h]->chooseLs(Lsi);
        for(int t = 0; t < (int)hh_subTetras.size(); t++)
          hh_subTetras[t]->chooseLs(Lsi);
        for(int q = 0; q < (int)hh_surfQuads.size(); q++)
          hh_surfQuads[q]->chooseLs(Lsi);
        for(int t = 0; t < (int)hh_surfTriangles.size(); t++)
          hh_surfTriangles[t]->chooseLs(Lsi);
        for(int l = 0; l < (int)hh_frontLines.size(); l++)
          hh_frontLines[l]->chooseLs(Lsi);
        for(int p = 0; p < (int)hh_cp.size(); p++)
          hh_cp[p]->chooseLs(Lsi);
      }
    }
  }
  else {
    for(int l = 0; l < (int)RPN.size(); l++) {
      gLevelset *Lsi = RPN[l];
      if(Lsi->isPrimitive()) {
        hh->addLs(this, Lsi, iPrim++, nodeLs);
      }
    }
    if(iPrim == 1) iPrim--;
    hh_subHexas[0]->addLs(this, RPN.back(), iPrim, nodeLs);
  }

  for(int i = 0; i < (int)QError.size(); i++) {
    QError[i]->print(this);
    delete QError[i];
  }

  for(int h = 0; h < (int)hh_subHexas.size(); h++) {
    hh_subHexas[h]->computeLsTagDom(hh, RPN);
    DI_Hexa *hh_subH = new DI_Hexa(*hh_subHexas[h]);
    mappingEl(hh_subHexas[h]);
    hh_subHexas[h]->integrationPoints(polynomialOrderH, hh_subH, hh, RPN, ip);
    subHexas.push_back(hh_subHexas[h]);
    delete hh_subH;
  }
  for(int t = 0; t < (int)hh_subTetras.size(); t++) {
    hh_subTetras[t]->computeLsTagDom(hh, RPN);
    DI_Tetra *hh_subT = new DI_Tetra(*hh_subTetras[t]);
    mappingEl(hh_subTetras[t]);
    hh_subTetras[t]->integrationPoints(polynomialOrderT, hh_subT, hh, RPN, ip);
    subTetras.push_back(hh_subTetras[t]);
    delete hh_subT;
  }
  for(int q = 0; q < (int)hh_surfQuads.size(); q++) {
    hh_surfQuads[q]->computeLsTagBound(hh_subHexas, hh_subTetras);
    if(hh_surfQuads[q]->lsTag() == -1) {delete hh_surfQuads[q]; continue;}
    DI_Quad *hh_surfQ = new DI_Quad(*hh_surfQuads[q]);
    mappingEl(hh_surfQuads[q]);
    hh_surfQuads[q]->integrationPoints(polynomialOrderQ, hh_surfQ, hh, RPN, ipS);
    surfQuads.push_back(hh_surfQuads[q]);
    delete hh_surfQ;
  }
  for(int t = 0; t < (int)hh_surfTriangles.size(); t++) {
    hh_surfTriangles[t]->computeLsTagBound(hh_subHexas, hh_subTetras);
    if(hh_surfTriangles[t]->lsTag() == -1) {delete hh_surfTriangles[t]; continue;}
    DI_Triangle *hh_surfTr = new DI_Triangle(*hh_surfTriangles[t]);
    mappingEl(hh_surfTriangles[t]);
    hh_surfTriangles[t]->integrationPoints(polynomialOrderTr, hh_surfTr, hh, RPN, ipS);
    surfTriangles.push_back(hh_surfTriangles[t]);
    delete hh_surfTr;
  }
  for(int l = 0; l < (int)hh_frontLines.size(); l++) {
    hh_frontLines[l]->computeLsTagBound(hh_surfQuads, hh_surfTriangles);
    if(hh_frontLines[l]->lsTag() == -1) {delete hh_frontLines[l]; continue;}
    DI_Line *hh_frontLn = new DI_Line(*hh_frontLines[l]);
    mappingEl(hh_frontLines[l]);
    //hh_frontLines[l]->integrationPoints(polynomialOrderL, tt_surfLn, tt, RPN, ipS);
    frontLines.push_back(hh_frontLines[l]);
    delete hh_frontLn;
  }
  for(int p = 0; p < (int)hh_cp.size(); p++) {
    if(hh_cp[p]->ls() != 0) {delete hh_cp[p]; continue;} // returns only the cutting points with ls==0
    mappingCP(hh_cp[p]);
    std::pair<DI_Point::Container::iterator,bool> isIn = cp.insert(hh_cp[p]);
    if(!isIn.second) delete hh_cp[p];
  }
  delete hh;
  return signChange;
}

// cut a hex into subtetras along the levelset surface
bool DI_Hexa::cut (const DI_Element *e, const std::vector<gLevelset *> &RPNi,
                   std::vector<DI_Hexa *> &Hexas, std::vector<DI_Tetra *> &subTetras,
                   std::vector<DI_Quad *> &surfQuads, std::vector<DI_Triangle *> &surfTriangles,
                   std::vector<DI_CuttingPoint *> &cp, std::vector<DI_QualError *> &QError)
{
  // check if the hex is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[8];
  for (int i = 0; i < 8; i++){
    if(pt(i)->isOnBorder()) ze[on++] = i;
    else if (pt(i)->ls() > 0.) pos++;
    else neg++;
  }
  if (pos && neg) {
    std::vector<DI_Tetra *> tetras; tetras.reserve(6);
    // Split the quad into sub tetras
    splitIntoTetras (tetras);
    // each of the sub tetras is split again into sub tetras with respect to the levelset
    int nt0 = surfTriangles.size(), nT1, nt1, nT2, nt2;
    for (int t = 0; t < (int)tetras.size(); t++) {
      nT1 = subTetras.size(); nt1 = surfTriangles.size();
      tetras[t]->selfSplit(e, RPNi, subTetras, surfTriangles, cp, QError);
      nT2 = subTetras.size(); nt2 = surfTriangles.size();
      if((nT2 - nT1) == 1 && (nt2 - nt1) == 1){ // only 1 triangle created on a face of a tetra => check if it was not yet created
        if(isLastTrInV(surfTriangles, nt0)) {delete surfTriangles.back(); surfTriangles.pop_back(); nt2--;}
      }
    }
  }

  else{
    if(on == 4){ // the level set is zero on a face of the hex
      // assert the nodes are in the same plane
      if(!isPlanar(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]))) {
        printf("Error : The 4 nodes with zero levelset are not planar!\n");}
      else {
        // order the 4 nodes
        if(!ordered4Nodes(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]))) swap(ze[2], ze[3]);
        // add the quad twice if the face belongs to 2 hexas => remove it later!
        if(ze[0] == 2) surfQuads.push_back(new DI_Quad(pt(ze[1]), pt(ze[2]), pt(ze[3]), pt(ze[0]), RPNi.back()->getTag()));
        // to assert that the quad will be split into triangles in the same manner as the hexa into tetras.
        else surfQuads.push_back(new DI_Quad(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]), RPNi.back()->getTag()));
      }
    }
    for(int i = 0; i < on; i++)
      cp.push_back(new DI_CuttingPoint(pt(ze[i])));
    Hexas.push_back(this);
  }
  return (pos && neg);
}

#endif
