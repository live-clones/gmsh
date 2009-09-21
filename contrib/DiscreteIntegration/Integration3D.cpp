#ifndef INTEGRATION3D_CC
#define INTEGRATION3D_CC

#include "Integration3D.h"
#include "recurCut.h"
#include "../../Numeric/Gauss.h"

#define ZERO_LS_TOL  1.e-7
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
inline void vec (const DI_Point &p1, const DI_Point &p2, double *v) {
  v[0] = p2.x() - p1.x(); v[1] = p2.y() - p1.y(); v[2] = p2.z() - p1.z();
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
inline double distance(const DI_Point &p1, const DI_Point &p2) {
  return sqrt((p1.x() - p2.x()) * (p1.x() - p2.x())
            + (p1.y() - p2.y()) * (p1.y() - p2.y())
            + (p1.z() - p2.z()) * (p1.z() - p2.z()));
}
inline double distance(const DI_CuttingPoint &p1, const DI_CuttingPoint &p2) {
  return sqrt((p1.x() - p2.x()) * (p1.x() - p2.x())
            + (p1.y() - p2.y()) * (p1.y() - p2.y())
            + (p1.z() - p2.z()) * (p1.z() - p2.z()));
}

// middle of 2 points
inline DI_Point middle (const DI_Point &p1, const DI_Point &p2) {
  return DI_Point ((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2, (p1.z() + p2.z()) / 2);
}
inline DI_Point middle (const DI_Point &p1, const DI_Point &p2, const DI_Element *e, const std::vector<const gLevelset *> RPNi) {
  return DI_Point ((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2, (p1.z() + p2.z()) / 2, e, RPNi);
}

// barycentre
inline DI_Point barycenter (const DI_Element *el, const DI_Element *e, const std::vector<const gLevelset *> RPN) {
  double x[3] = {0., 0., 0.};
  int n;
  for (n = 0; n < el->nbVert(); n++) {
    x[0] += el->x(n);
    x[1] += el->y(n);
    x[2] += el->z(n);
  }
  return DI_Point(x[0] / n,x[1] / n,x[2] / n, e, RPN);
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
inline void swap (DI_Point &p1, DI_Point &p2) {
  DI_Point pt = p1;
  p1 = p2; p2 = pt;
}

// return true if the 4 points are planar
inline bool isPlanar (const DI_Point &p1, const DI_Point &p2, const DI_Point &p3, const DI_Point &p4) {
  double v12[3]; vec(p1, p2, v12);
  double v13[3]; vec(p1, p3, v13);
  double v14[3]; vec(p1, p4, v14);
  double c1[3]; cross(v12, v13, c1);
  double c2[3]; cross(v12, v14, c2);
  double c[3];  cross(c1, c2, c);
  return (c[0] == 0. && c[1] == 0. && c[2] == 0.);
}
// return true if the 3 points are linear
inline bool isLinear (const DI_Point &p1, const DI_Point &p2, const DI_Point &p3) {
  double v12[3]; vec(p1, p2, v12);
  double v13[3]; vec(p1, p3, v13);
  double c[3]; cross(v12, v13, c);
  return (c[0] == 0. && c[1] == 0. && c[2] == 0.);
}
// return true if the 4 points form a quad in good ordering
inline bool ordered4Nodes (const DI_Point &p1, const DI_Point &p2, const DI_Point &p3, const DI_Point &p4) {
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

bool isInQE (const DI_Triangle &t, const DI_QualError &QE) {
  int b = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++)
      if (t.pt(i).equal(QE.pt(j))) {b++; break;}
  }
  return (b == 3);
}
bool belongsTo (const DI_Element &e, const DI_Element &E) {
  int b = 0;
  for(int k = 0; k < E.nbVert(); k++) {
    for(int l = 0; l < e.nbVert(); l++)
      if((e.pt(l)).equal(E.pt(k))) {b++; break;}
    if(b == e.nbVert()) return true;
  }
  return false;
}
bool isLastLnInV (const std::vector<DI_Line> &v, const int i1 = 0) {
  int b;
  for (int i = i1; i < (int)v.size() - 1; i++) {
    b = 0;
    for (int k = 0; k < 2; k++)
      for(int l = 0; l < 2; l++)
        if(v[i].pt(k).equal(v[v.size() - 1].pt(l))) {b++; break;}
    if(b == 2) return true;
  }
  return false;
}
bool isLastTrInV (const std::vector<DI_Triangle> &v, const int i1 = 0) {
  int b;
  for (int i = i1; i < (int)v.size() - 1; i++) {
    b = 0;
    for (int k = 0; k < 3; k++)
      for(int l = 0; l < 3; l++)
        if(v[i].pt(k).equal(v[v.size() - 1].pt(l))) {b++; break;}
    if(b == 3) return true;
  }
  return false;
}
bool isLastQInV (const std::vector<DI_Quad> &v, const int i1 = 0) {
  int b;
  for (int i = i1; i < (int)v.size() - 1; i++) {
    b = 0;
    for(int k = 0; k < 4; k++)
      for(int l = 0; l < 4; l++)
        if(v[i].pt(k).equal(v[v.size() - 1].pt(l))) {b++; break;}
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

double adjustLs (double ls) {
  return fabs(ls) < ZERO_LS_TOL ? 0. : ls;
}
bool isCrossed (double ls1, double ls2) {
  if(ls1 * ls2 >= 0.) return false;
  if (fabs(ls1) < ZERO_LS_TOL || fabs(ls2) < ZERO_LS_TOL) return false;
  return true;
}
bool isCrossed (const DI_Point &p1, const DI_Point &p2) {
  double v1 = p1.ls(), v2 = p2.ls();
  return isCrossed (v1, v2);
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
double qualityTri(const DI_Point &p0, const DI_Point p1, const DI_Point &p2) {
  double a = distance(p0, p1);
  double b = distance(p0, p2);
  double c = distance(p1, p2);

  double rhoO = a * b * c / sqrt((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c));
  double rhoI = a * b * c / (2 * (a + b + c) * rhoO);
  return 2 * rhoI / rhoO;
}

// Return the best quality for a quad cut into 2 triangles
int bestQuality(const DI_Point &p1, const DI_Point &p2, const DI_Point &p3, const DI_Point &p4, DI_Triangle &t1, DI_Triangle &t2) {
  int cut = 0;
  double qual11 = qualityTri(p1, p2, p3);
  double qual12 = qualityTri(p1, p3, p4);
  double qual21 = qualityTri(p1, p2, p4);
  double qual22 = qualityTri(p2, p3, p4);
  //printf("quad, q11=%.18f,q12=%.18f,q21=%.18f,q22=%.18f\n",qual11,qual12,qual21,qual22);
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
      double x[4] = {p1.x(), p2.x(), p3.x(), p4.x()};
      double y[4] = {p1.y(), p2.y(), p3.y(), p4.y()};
      double z[4] = {p1.z(), p2.z(), p3.z(), p4.z()};
      int IND = minimum(x, y, z, 4);
      if(IND == 0 || IND == 2) cut = 1;
      else cut = 2;
    }
  }
  if(cut == 1) {
    t1 = DI_Triangle(p1, p2, p3);
    t2 = DI_Triangle(p1, p3, p4);
    return 1;
  }
  else {
    t1 = DI_Triangle(p1, p2, p4);
    t2 = DI_Triangle(p2, p3, p4);
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
int bestQuality(const DI_Point &p1, const DI_Point &p2, const DI_Point &p3,
                const DI_Point &p4, const DI_Point &p5, DI_Tetra &t1, DI_Tetra &t2) {
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
      double x[4] = {p1.x(), p2.x(), p3.x(), p4.x()};
      double y[4] = {p1.y(), p2.y(), p3.y(), p4.y()};
      double z[4] = {p1.z(), p2.z(), p3.z(), p4.z()};
      int IND = minimum(x, y, z, 4);
      if(IND == 0 || IND == 2) cut = 1;
      else cut = 2;
    }
  }
  if(cut == 1) {
    t1 = DI_Tetra(p1, p2, p3, p5);
    t2 = DI_Tetra(p1, p3, p4, p5);
    return 1;
  }
  else {
    t1 = DI_Tetra(p1, p2, p4, p5);
    t2 = DI_Tetra(p2, p3, p4, p5);
    return 2;
  }
}

// Return the cutting of a prism into 3 tetras with the best quality faces
int bestQuality (const DI_Point &p0, const DI_Point &p1, const DI_Point &p2,
                 const DI_Point &p3, const DI_Point &p4, const DI_Point &p5,
                 DI_Tetra &t1, DI_Tetra &t2, DI_Tetra &t3, std::vector<DI_QualError> &QError) {
  int cut3[3] = {0, 0, 0}; int cut = -1;
  int fa[3][4] = {{0, 3, 4, 1}, {0, 2, 5, 3}, {1, 4, 5, 2}}; //faces
  DI_Point pt[6] = {p0, p1, p2, p3, p4, p5};
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
        double xc[4] = {pt[i1].x(), pt[i2].x(), pt[i3].x(), pt[i4].x()};
        double yc[4] = {pt[i1].y(), pt[i2].y(), pt[i3].y(), pt[i4].y()};
        double zc[4] = {pt[i1].z(), pt[i2].z(), pt[i3].z(), pt[i4].z()};
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
      if(cut3[2] == 1) QError.push_back(DI_QualError(p1, p5, p2, p4));
      cut = 3;
    }
  }
  else {
    if(cut3[1] == 1){
      if(cut3[2] == 2) QError.push_back(DI_QualError(p1, p5, p2, p4));
      cut = 0;
    }
    else{
      if(cut3[2] == 1) cut = 5;
      else cut = 4;
    }
  }

  if(cut == 0) {
    t1 = DI_Tetra(p0, p1, p2, p5);
    t2 = DI_Tetra(p0, p1, p5, p3);
    t3 = DI_Tetra(p1, p5, p3, p4);
    return 1;
  }
  else if(cut == 1) {
    t1 = DI_Tetra(p0, p1, p2, p5);
    t2 = DI_Tetra(p0, p1, p5, p4);
    t3 = DI_Tetra(p0, p4, p5, p3);
    return 2;
  }
  else if(cut == 2) {
    t1 = DI_Tetra(p0, p1, p2, p4);
    t2 = DI_Tetra(p0, p4, p2, p5);
    t3 = DI_Tetra(p0, p4, p5, p3);
    return 3;
  }
  else if(cut == 3) {
    t1 = DI_Tetra(p0, p1, p2, p4);
    t2 = DI_Tetra(p0, p4, p2, p3);
    t3 = DI_Tetra(p2, p3, p4, p5);
    return 4;
  }
  else if(cut == 4) {
    t1 = DI_Tetra(p0, p1, p2, p3);
    t2 = DI_Tetra(p1, p2, p3, p4);
    t3 = DI_Tetra(p2, p3, p4, p5);
    return 5;
  }
  else if(cut == 5) {
    t1 = DI_Tetra(p0, p1, p2, p3);
    t2 = DI_Tetra(p1, p2, p3, p5);
    t3 = DI_Tetra(p1, p5, p3, p4);
    return 6;
  }
}

// computes the intersection between a level set and a linear edge
DI_Point Newton(const DI_Point &p1, const DI_Point &p2, const DI_Element *e, const std::vector<const gLevelset *> RPNi) {
  double eps = -p1.ls() / (p2.ls() - p1.ls());
  DI_Point p(p1.x() + eps * (p2.x() - p1.x()), p1.y() + eps * (p2.y() - p1.y()), p1.z() + eps * (p2.z() - p1.z()));
  double pls = e->evalLs(p.x(), p.y(), p.z());
  // Newton iteration to find the intersection between the level set and the edge
  while(fabs(pls) > EQUALITY_TOL){
    if(pls * p1.ls() < 0.) {
      eps = -pls / (p1.ls() - pls);
      p.move(p.x() + eps * (p1.x() - p.x()), p.y() + eps * (p1.y() - p.y()), p.z() + eps * (p1.z() - p.z()));
    }
    else {
      eps = -pls / (p2.ls() - pls);
      p.move(p.x() + eps * (p2.x() - p.x()), p.y() + eps * (p2.y() - p.y()), p.z() + eps * (p2.z() - p.z()));
    }
    pls = e->evalLs(p.x(), p.y(), p.z());
  }
  p.computeLs(e, RPNi);
  return p;
}

// compute the position of the middle of a quadratic edge (intersection between the bisector of the linear edge and the levelset)
DI_Point quadMidNode(const DI_Point &p1, const DI_Point &p2, const DI_Point &pf, const DI_Element *e, const std::vector<const gLevelset *> RPNi) {
  // middle of the edge between the 2 cutting points
  DI_Point midEN((p1.x() + p2.x()) / 2., (p1.y() + p2.y()) / 2., (p1.z() + p2.z()) / 2.);
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
  return Newton(midEN, pt, e, RPNi);
}

// --------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------

// DI_Point methods ----------------------------------------------------------------------------------------------
DI_Point::DI_Point (double x, double y, double z, gLevelset &ls) : x_(x), y_(y), z_(z) {
  addLs(ls(x, y, z));
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
  Ls.push_back(ls);
}
void DI_Point::computeLs (const DI_Element *e, const std::vector<const gLevelset*> RPNi) {
  int prim = 0; Ls.clear();
  if(e->sizeLs() == 0) return;
  for(int l = 0; l < (int)RPNi.size(); l++) {
    if (RPNi[l]->isPrimitive())
      Ls.push_back(e->evalLs(x_, y_, z_, prim++));
    else
      chooseLs(RPNi[l]);
  }
}
void DI_Point::computeLs (const gLevelset &ls) {
  Ls.clear();
  addLs(ls(x_, y_, z_));
}
bool DI_Point::equal(const DI_Point &p) const {
  return (fabs(x() - p.x()) < EQUALITY_TOL && fabs(y() - p.y()) < EQUALITY_TOL && fabs(z() - p.z()) < EQUALITY_TOL);
}

// DI_IntegrationPoint methods -----------------------------------------------------------------------------------------------------
void DI_IntegrationPoint::computeLs (const DI_Element *e, const std::vector<const gLevelset*> RPN) {
  int prim = 0; std::vector<double> Ls;
  for(int l = 0; l < (int)RPN.size(); l++) {
    if(RPN[l]->isPrimitive())
      Ls.push_back(e->evalLs(x_, y_, z_, prim++));
    else {
      double ls1 = Ls[Ls.size() - 2], ls2 = Ls[Ls.size() - 1];
      double ls = RPN[l]->choose(ls1, ls2);
      Ls.pop_back(); Ls.pop_back();
      Ls.push_back(ls);
    }
  }
  setLs(Ls.back());
}

// DI_CuttingPoint methods -----------------------------------------------------------------------------------------------------
void DI_CuttingPoint::chooseLs (const gLevelset *Lsi) {
  if(Ls.size() < 2) return;
  double ls1 = Ls[Ls.size() - 2], ls2 = Ls[Ls.size() - 1];
  double ls = Lsi->choose(ls1, ls2);
  Ls.pop_back(); Ls.pop_back();
  Ls.push_back(ls);
}
bool DI_CuttingPoint::equal (const DI_CuttingPoint &p) const {
  return (fabs(x() - p.x()) < EQUALITY_TOL && fabs(y() - p.y()) < EQUALITY_TOL && fabs(z() - p.z()) < EQUALITY_TOL);
}

// DI_Element methods ------------------------------------------------------------------------------------------------
DI_Element::DI_Element(const DI_Element &cp) : lsTag_(cp.lsTag()), polOrder_(cp.getPolynomialOrder()), integral_(cp.integral()) {
  //printf("constructeur de copie d'element %d : ",cp.type()); cout << &cp << "->" << this << endl;
  pts_ = new DI_Point* [cp.nbVert()];
  for(int i = 0; i < cp.nbVert(); i++)
    pts_[i] = new DI_Point(cp.pt(i));
  if(cp.getPolynomialOrder() > 1) {
    mid_ = new DI_Point* [cp.nbMid()];
    for(int i = 0; i < cp.nbMid(); i++)
      mid_[i] = new DI_Point(cp.mid(i));
  }
  else
    mid_ = NULL;
}
/*DI_Element::~DI_Element() {
  //printf("destructeur d'element %d : ",type()); cout << this << endl;
  for(int i=0;i<nbVert();i++) //if(pts_[i])
    delete pts_[i];
  if(pts_) delete pts_;
  for(int i=0;i<nbMid();i++)  //if(mid_[i])
    delete mid_[i];
  if(mid_) delete mid_;
}*/
DI_Element & DI_Element::operator= (const DI_Element &rhs){
  if(type() != rhs.type()) {
    printf("Error : try to assign element of different type!\n");
    return *this;
  }
  if(this != &rhs) {
    for(int i = 0; i < nbVert(); i++) {
      delete pts_[i];
      pts_[i] = new DI_Point(rhs.pt(i));
    }
    for(int i = 0; i < nbMid(); i++) {
      delete mid_[i];
      //mid_[i] = NULL;
    }
    if(rhs.nbMid() > 0) {
      delete mid_;
      mid_ = new DI_Point*[rhs.nbMid()];
    }
    for(int i = 0; i < rhs.nbMid(); i++)
      mid_[i] = new DI_Point(rhs.mid(i));
    polOrder_ = rhs.getPolynomialOrder();
    integral_ = rhs.integral();
    lsTag_ = rhs.lsTag();
  }
  return *this;
}
void DI_Element::setPolynomialOrder (int o) {
  polOrder_ = o;
  switch (o) {
  case 1 :
    return;
  case 2 :
    mid_ = new DI_Point*[nbMid()];
    for(int i = 0; i < nbMid(); i++) {
      std::vector<int> s(nbVert()); int n;
      midV(i, &s[0], n);
      double xc = 0, yc = 0, zc = 0;
      for(int j = 0; j < n; j++){
        xc += x(s[j]); yc += y(s[j]); zc += z(s[j]); }
      mid_[i] = new DI_Point(xc/n, yc/n, zc/n);
    }
    return;
  default :
    printf("Order %d line function space not implemented ", o); print();
  }
}
void DI_Element::setPolynomialOrder (int o, const DI_Element *e, const std::vector<const gLevelset *> RPNi) {
  for(int i = 0; i < nbMid(); i++)
    delete mid_[i];
  polOrder_ = o;
  switch (o) {
  case 1 :
    return;
  case 2 :
    mid_ = new DI_Point*[nbMid()];
    for(int i = 0; i < nbMid(); i++) {
      std::vector<int> s(nbVert()); int n;
      midV(i, &s[0], n);
      double xc = 0, yc = 0, zc = 0;
      for(int j = 0; j < n; j++){
        xc += x(s[j]); yc += y(s[j]); zc += z(s[j]); }
      mid_[i] = new DI_Point(xc/n, yc/n, zc/n, e, RPNi);
    }
    return;
  default :
    printf("Order %d line function space not implemented ", o); print();
  }
}
void DI_Element::addLs (const double *ls) {
  for(int i = 0; i < nbVert(); i++)
    pts_[i]->addLs(ls[i]);
  for(int i = 0; i < nbMid(); i++)
    mid_[i]->addLs(ls[nbVert()+i]);
}
void DI_Element::addLs (int primTag, std::map<int, double> nodeLs[8]) {
  for(int i = 0; i < nbVert(); i++)
    pts_[i]->addLs(nodeLs[i][primTag]);
}
void DI_Element::addLs (const DI_Element *e) {
  if(e->sizeLs() < 1) return;
  for(int i = 0; i < nbVert(); i++)
    pts_[i]->addLs(e);
  for(int i = 0; i < nbMid(); i++)
    mid_[i]->addLs(e);
}
void DI_Element::addLs (const DI_Element *e, const gLevelset &Ls) {
  if(type() != e->type()) {
    printf("Error : addLs with element of different type\n");
  }
  for(int j = 0; j < nbVert(); ++j) {
    double ls = Ls(e->x(j), e->y(j), e->z(j));
    pts_[j]->addLs(ls);
  }
  for(int j = 0; j < nbMid(); ++j) {
    std::vector<int> s(nbVert()); int n;
    e->midV(j, &s[0], n);
    double xc = 0, yc = 0, zc = 0;
    for(int k = 0; k < n; k++){
      xc += e->x(s[k]); yc += e->y(s[k]); zc += e->z(s[k]); }
    double ls = Ls(xc/n, yc/n, zc/n);
    mid_[j]->addLs(ls);
  }
}
void DI_Element::chooseLs (const gLevelset *Lsi) {
  if(sizeLs() < 2)
    printf("chooseLs with element ls size < 2 : typeEl=%d\n", type());
  for(int i = 0; i < nbVert(); i++)
    pts_[i]->chooseLs(Lsi);
  for(int i = 0; i < nbMid(); i++)
    mid_[i]->chooseLs(Lsi);
}
void DI_Element::clearLs() {
  for(int i = 0; i < nbVert(); i++)
    (pts_[i]->Ls).clear();
  for(int i = 0; i < nbMid(); i++)
    (mid_[i]->Ls).clear();
}
bool DI_Element::addQuadEdge (int edge, DI_Point *xm, const DI_Element *e, const std::vector<const gLevelset *> RPNi) {
  /*if(edge >= nbEdg()) {printf("wrong number (%d) for quadratic edge for a ", edge); print(); return false;}
  int s1, s2; vert(edge, s1, s2);
  bool quad0 = isQuad();
  if(!quad0) quad(e, RPNi);
  double dist = distance(mid(edge), *xm);
  double sideLength = distance(pt(s1), pt(s2));
  if (dist / sideLength < 1.e-5) {
    if(!quad0) lin(); printf("dist=%.20f, sideLength=%g, d/sL=%g => do not add quad edge\n", dist, sideLength, dist/sideLength);
    return true; // do not add the quadratic edge if xm is very close from the middle of the edge
  }
  DI_Point *p0 = mid_[edge];
  mid_[edge]->move(xm->x(), xm->y(), xm->z());//mid_[edge] = xm;
  // check if the quadratic edge will produce a twist in the element (detJ<0)
  if(!testDetJ()){
    // reinitialize quad edges if the element was not quad at the begining
    if(!quad0) lin();
    else mid_[edge]->move(p0->x(), p0->y(), p0->z());//mid_[edge] = p0;
    printf("detJ<0 when trying to add a quadratic edge in "); print();
    return false;
  }
  computeIntegral();*/
  return true;
}
bool DI_Element::contain (const DI_Point &p) const {
  for(int i = 0; i < nbVert(); i++){
    if(p.equal(pt(i)))
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
DI_Point DI_Element::mappingP (DI_Point &pt) const {
  double e[3]; evalC(pt.x(), pt.y(), pt.z(), e);
  pt.move(e[0], e[1], e[2]);
  return pt;
}
DI_IntegrationPoint DI_Element::mappingIP (DI_IntegrationPoint &in) const {
  double e[3]; evalC(in.x(), in.y(), in.z(), e);
  double w = in.weight() * integral() / refIntegral();
  in.move(e[0], e[1], e[2]);
  in.setWeight(w);
  return in;
}
DI_CuttingPoint DI_Element::mappingCP (DI_CuttingPoint &cp) const {
  double e[3]; evalC(cp.x(), cp.y(), cp.z(), e);
  cp.move(e[0], e[1], e[2]);
  return cp;
}
void DI_Element::mappingEl (DI_Element *el) const {
  double s[3];
  for (int i = 0; i < el->nbVert(); i++) {
    evalC(el->x(i), el->y(i), el->z(i), s);
    el->pts_[i]->move(s[0], s[1], s[2]);
  }
  for(int i = el->nbVert(); i < el->nbVert() + el->nbMid(); i++) {
    evalC(el->x(i), el->y(i), el->z(i), s);
    el->mid_[i - el->nbVert()]->move(s[0], s[1], s[2]);
  }
  el->computeIntegral();
}
void DI_Element::integrationPoints (const int polynomialOrder, const DI_Element *loc, const DI_Element *e,
                                 const std::vector<const gLevelset *> RPN, std::vector<DI_IntegrationPoint> &ip) const {
  std::vector<DI_IntegrationPoint> ip_ref;
  getRefIntegrationPoints(polynomialOrder, ip_ref);
  for (int j = 0; j < (int)ip_ref.size(); j++) {
    DI_IntegrationPoint IPloc = ip_ref[j];
    loc->mappingIP(IPloc);
    mappingIP(ip_ref[j]);
    ip_ref[j].addLocC(IPloc.x(), IPloc.y(), IPloc.z());
    DI_IntegrationPoint pp = IPloc; pp.computeLs(e, RPN);
    //ip_ref[j].setLs(loc->evalLs(IPloc.x(), IPloc.y(), IPloc.z()));//levelset computed in the subelement FIXME check sign!
    //ip_ref[j].setLs(evalLs(ip_ref[j].x(), ip_ref[j].y(), ip_ref[j].z()));
    ip_ref[j].setLs(pp.ls());
    //printf("pt loc : "); IPloc.print(); printf("pt reel : "); ip_ref[j].print();
    //printf("el loc : "); loc->printls(); printf("el reel : "); printls(); printf("el e : "); e->printls();
    //printf("ls_loc=%g ls_reel=%g ls_e=%g\n\n", loc->evalLs(IPloc.x(), IPloc.y(), IPloc.z()), evalLs(ip_ref[j].x(), ip_ref[j].y(), ip_ref[j].z()), pp.ls());
    ip.push_back(ip_ref[j]);
  }
}
void DI_Element::getCuttingPoints (const DI_Element *e, const std::vector<const gLevelset *> RPNi, std::vector<DI_CuttingPoint> &cp) const {
  int s1, s2;
  for(int i = 0; i < nbEdg(); i++){
    vert(i, s1, s2);
    if (isCrossed(pt(s1), pt(s2))) {
      DI_Point p = Newton(pt(s1), pt(s2), e, RPNi);
      cp.push_back(DI_CuttingPoint(p));
    }
    if(ls(s1) == 0.)
      cp.push_back(DI_CuttingPoint(pt(s1)));
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
  if(iLs == -1) iLs = sizeLs() - 1; //last ls value
  double vls = 0;
  std::vector<double> s(nbVert() + nbMid());
  getShapeFunctions (u, v, w, &s[0], order);
  for(int i = 0; i < nbVert() + nbMid(); i++)
    vls += ls(i, iLs) * s[i];
  return adjustLs(vls);
}
bool DI_Element::testDetJ() const {
  double detJ0 = detJ(x(0), y(0), z(0));
  for(int i = 1; i < nbVert(); i++)
    if(detJ0 * detJ(x(i), y(i), z(i)) < 0.) return false;
  for(int i = nbVert(); i < nbVert() + nbMid(); i++)
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
  d3 *s=new d3[nbVert()+ nbMid()];
  getGradShapeFunctions(u, v, w, s);
  switch(getDim()){
  case 3 :
    for(int i = 0; i < nbVert() + nbMid(); i++) {
      J[0][0] += x(i) * s[i][0]; J[0][1] += y(i) * s[i][0]; J[0][2] += z(i) * s[i][0];
      J[1][0] += x(i) * s[i][1]; J[1][1] += y(i) * s[i][1]; J[1][2] += z(i) * s[i][1];
      J[2][0] += x(i) * s[i][2]; J[2][1] += y(i) * s[i][2]; J[2][2] += z(i) * s[i][2];
//      delete [] s[i];
    }
	delete [] s;
    return det3(J[0][0], J[0][1], J[0][2], J[1][0], J[1][1], J[1][2], J[2][0], J[2][1], J[2][2]);
  case 2 :
    for(int i = 0; i < nbVert() + nbMid(); i++) {
      J[0][0] += x(i) * s[i][0]; J[0][1] += y(i) * s[i][0]; J[0][2] += z(i) * s[i][0];
      J[1][0] += x(i) * s[i][1]; J[1][1] += y(i) * s[i][1]; J[1][2] += z(i) * s[i][1];
//      delete [] s[i];
    }
    delete [] s;
    return sqrt(sq2(J[0][0] * J[1][1] - J[0][1] * J[1][0]) +
                sq2(J[0][2] * J[1][0] - J[0][0] * J[1][2]) +
                sq2(J[0][1] * J[1][2] - J[0][2] * J[1][1])); // allways > 0 => does'nt allow to check if twist !!!!
  case 1 :
    for(int i = 0; i < nbVert() + nbMid(); i++) {
      J[0][0] += x(i) * s[i][0]; J[0][1] += y(i) * s[i][0]; J[0][2] += z(i) * s[i][0];
//      delete [] s[i];
    }
    delete [] s;
    return sqrt(sq2(J[0][0]) + sq2(J[0][1]) + sq2(J[0][2])); // allways > 0 !!!!
  default :
    return 1.;
  }
}
// set the lsTag to +1 if the element is inside the domain (lsTag is -1 by default)
void DI_Element::computeLsTagDom(const DI_Element *e, const std::vector<const gLevelset *> RPN) {
  for(int i = 0; i < nbVert(); i++) {
    if(pt(i).isOutsideDomain())
      return;
    if(pt(i).isInsideDomain())
      {setLsTag(1); return;}
  }
  DI_Point bar = barycenter(this, e, RPN);
  if(bar.isOutsideDomain())
    return;
  if(bar.isInsideDomain())
    {setLsTag(1); return;}
  for(int i = 0; i < nbVert(); i++) {
    DI_Point mid = middle (pt(i), bar, e, RPN);
    if(mid.isOutsideDomain())
      return;
    if(mid.isInsideDomain())
      {setLsTag(1); return;}
  }
  printf("Error : Unable to determine the sign of the element : \n");
  printf("Parent element : "); e->printls();
  printf("Element : "); printls();
  return;
}
// set the lsTag to -1 if the element is not on the border of the domain
void DI_Element::computeLsTagBound(std::vector<DI_Hexa> &hexas, std::vector<DI_Tetra> &tetras){
  for(int i = 0; i < nbVert(); i++) {
    if(!pt(i).isOnBorder()) {
      setLsTag(-1);
      return;
    }
  }

  /*DI_Element *e1 = NULL, *e2 = NULL;
  for(int i = 0; i < (int)tetras.size(); i++){
    if(belongsTo(*this, tetras[i])) {
      if(!e1) e1 = &tetras[i];
      else {e2 = &tetras[i]; break;}
    }
  }
  if(e1 && e2) {
    if(e1->lsTag() * e2->lsTag() > 0.) setLsTag(-1);
    return;
  }
  for(int i = 0; i < (int)hexas.size(); i++){
    if(belongsTo(*this, hexas[i])) {
      if(!e1) e1 = &hexas[i];
      else {e2 = &hexas[i]; break;}
    }
  }
  if(e1 && e2 && e1->lsTag() * e2->lsTag() > 0.) setLsTag(-1);*/
}
void DI_Element::computeLsTagBound(std::vector<DI_Quad> &quads, std::vector<DI_Triangle> &triangles){
  for(int i = 0; i < nbVert(); i++) {
    if(ls(i) != 0.) {
      setLsTag(-1);
      return;
    }
  }

  /*DI_Element *e1 = NULL, *e2 = NULL, *et = NULL;
  int NT = triangles.size(), NQ = quads.size();
  for(int i = 0; i < NT + NQ; i++){
    if((i < NT  && belongsTo(*this, triangles[i])) ||
       (i >= NT && belongsTo(*this, quads[i-NT]))) {
      if(i < NT) et = &triangles[i];
      else et = &quads[i-NT];
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

// DI_Line methods -----------------------------------------------------------------------------------------------------------
void DI_Line::computeIntegral() {
  switch (getPolynomialOrder()) {
  case 1 :
    integral_ = LineLength(pt(0), pt(1));
    break;
  case 2 :
    integral_ = LineLength(pt(0), mid(0)) + LineLength(mid(0), pt(1));
    break;
  default :
    printf("Order %d line function space not implemented ", getPolynomialOrder()); print();
  }
}
void DI_Line::getShapeFunctions (double u, double v, double w, double s[], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  double valm = (fabs(1. - u) < 1.e-16) ? 0. : (1. - u);
  double valp = (fabs(1. + u) < 1.e-16) ? 0. : (1. + u);
  switch (order) {
  case 1 :
    s[0] = valm / 2.;
    s[1] = valp / 2.;
    break;
  case 2 :
    s[0] = -u * valm / 2.;
    s[1] = u * valp / 2.;
    s[2] = valm * valp;
    break;
  default : printf("Order %d line function space not implemented ", order); print();
  }
}
void DI_Line::getGradShapeFunctions (const double u, const double v, const double w, double s[][3], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0][0] = -0.5; s[0][1] = 0.; s[0][2] = 0.;
    s[1][0] =  0.5; s[1][1] = 0.; s[1][2] = 0.;
    break;
  case 2 :
    s[0][0] = u - 0.5; s[0][1] = 0.; s[0][2] = 0.;
    s[1][0] = u + 0.5; s[1][1] = 0.; s[1][2] = 0.;
    s[2][0] = -2. * u; s[2][1] = 0.; s[2][2] = 0.;
    break;
  default :
    printf("Order %d line function space not implemented ", order); print();
  }
}
/*double ln_detJ1 (const double &x, const double &x0, const double &x1) {
  return (-x0 + x1) / 2.; // detJ is constant in a linear line
}
double ln_detJ2 (const double &x, const double &x0, const double &x1, const double &x2) {
  return x0 * (2. * x - 1.) / 2. + x1 * (2. * x + 1.) / 2. + x2 * (-2. * x);
}
double DI_Line::detJ (const double &xP, const double &yP, const double &zP) const {
  assert(yP == 0 && zP == 0 && y(0) == 0 && y(1) == 0 && y2(0) == 0 && z(0) == 0 && z(1) == 0 && z2(0) == 0);
  if(!isQuad()) return ln_detJ1(xP, x(0), x(1));
  return ln_detJ2(xP, x(0), x(1), x2(0));
}*/

// DI_Triangle methods -----------------------------------------------------------------------------------------------------------
void DI_Triangle::computeIntegral() {
  switch (getPolynomialOrder()) {
  case 1 :
    integral_ = TriSurf(pt(0), pt(1), pt(2));
    break;
  case 2 :
    integral_ = TriSurf(pt(0), mid(0), mid(2)) + TriSurf(pt(1), mid(0), mid(1))
              + TriSurf(pt(2), mid(1), mid(2)) + TriSurf(mid(0), mid(1), mid(2));
    break;
  default :
    printf("Order %d triangle function space not implemented ", getPolynomialOrder()); print();
  }
}
void DI_Triangle::getShapeFunctions (double u, double v, double w, double s[], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  double val1 = (fabs(1. - u - v) < 1.e-16) ? 0. : (1. - u - v);
  switch (order) {
  case 1 :
    s[0] = val1;
    s[1] = u;
    s[2] = v;
    break;
  case 2 :
    s[0] = val1 * (1. - 2. * u - 2. * v);
    s[1] = u * (2. * u - 1.);
    s[2] = v * (2. * v - 1.);
    s[3] = 4. * u * val1;
    s[4] = 4. * u * v;
    s[5] = 4. * v * val1;
    break;
  default :
    printf("Order %d triangle function space not implemented ", order); print();
  }
}
void DI_Triangle::getGradShapeFunctions (const double u, const double v, const double w, double s[][3], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0][0] = -1.; s[0][1] = -1.; s[0][2] = 0.;
    s[1][0] =  1.; s[1][1] =  0.; s[1][2] = 0.;
    s[2][0] =  0.; s[2][1] =  1.; s[2][2] = 0.;
    break;
  case 2 :
    s[0][0] = 4. * u + 4. * v - 3.;
    s[0][1] = 4. * u + 4. * v - 3.;
    s[0][2] = 0.;
    s[1][0] = 4. * u -1.;
    s[1][1] = 0.;
    s[1][2] = 0.;
    s[2][0] = 0.;
    s[2][1] = 4. * v - 1.;
    s[2][2] = 0.;
    s[3][0] = -8. * u - 4. * v + 4.;
    s[3][1] = -4. * u;
    s[3][2] = 0.;
    s[4][0] = 4. * v;
    s[4][1] = 4. * u;
    s[4][2] = 0.;
    s[5][0] = -4. * v;
    s[5][1] = -4. * u - 8. * v + 4.;
    s[5][2] = 0.;
    break;
  default :
    printf("Order %d triangle function space not implemented ", order); print();
  }
}
double DI_Triangle::quality() const {
  return qualityTri(pt(0), pt(1), pt(2));
}
/*double tr_detJ1 (const double &x, const double &y,
                 const double &x0, const double &y0, const double &x1, const double &y1, const double &x2, const double &y2) {
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0); // detJ is constant in a linear triangle
}
double tr_detJ2 (const double &x, const double &y,
                 const double &x0, const double &y0, const double &x1, const double &y1, const double &x2, const double &y2,
                 const double &x3, const double &y3, const double &x4, const double &y4, const double &x5, const double &y5) {
  return (x0*(-3.+4.*x+4.*y)+x1*(4.*x-1.)+x3*4.*(1.-2.*x-y)+x4*4.*y-x5*4.*y) * (y0*(-3.+4.*x+4.*y)+y2*(4.*y-1.)-y3*4.*x+y4*4.*x+y5*4.*(1.-x-2.*y))
        -(x0*(-3.+4.*x+4.*y)+x2*(4.*y-1.)-x3*4.*x+x4*4.*x+x5*4.*(1.-x-2.*y)) * (y0*(-3.+4.*x+4.*y)+y1*(4.*x-1.)+y3*4.*(1.-2.*x-y)+y4*4.*y-y5*4.*y);
}
double DI_Triangle::detJ (const double &xP, const double &yP, const double &zP) const {
  if(!(z(0) == 0 && z(1) == 0 && z(2) == 0 && z2(0) == 0 && z2(1) == 0 && z2(2) == 0)) print();
  assert(zP == 0 && z(0) == 0 && z(1) == 0 && z(2) == 0 && z2(0) == 0 && z2(1) == 0 && z2(2) == 0);
  if(!isQuad()) return tr_detJ1(xP, yP, x(0), y(0), x(1), y(1), x(2), y(2));
  return tr_detJ2(xP, yP, x(0), y(0), x(1), y(1), x(2), y(2), x2(0), y2(0), x2(1), y2(1), x2(2), y2(2));
}*/

// DI_Quad methods -------------------------------------------------------------------------------------------------------------------
void DI_Quad::computeIntegral() {
  switch (getPolynomialOrder()) {
  case 1 :
    integral_ = TriSurf(pt(0), pt(1), pt(2)) + TriSurf(pt(0), pt(2), pt(3));
    break;
  case 2 :
    integral_ = TriSurf(pt(0), mid(0), mid(4)) + TriSurf(pt(0), mid(4), mid(3))
              + TriSurf(pt(1), mid(1), mid(4)) + TriSurf(pt(1), mid(4), mid(0))
              + TriSurf(pt(2), mid(2), mid(4)) + TriSurf(pt(2), mid(4), mid(1))
              + TriSurf(pt(3), mid(3), mid(4)) + TriSurf(pt(3), mid(4), mid(2));
    break;
  default :
    printf("Order %d quadrangle function space not implemented ", getPolynomialOrder()); print();
  }
}
void DI_Quad::getShapeFunctions (double u, double v, double w, double s[], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0] = (1. - u) * (1. - v) / 4.;
    s[1] = (1. + u) * (1. - v) / 4.;
    s[2] = (1. + u) * (1. + v) / 4.;
    s[3] = (1. - u) * (1. + v) / 4.;
    break;
  case 2 :
    s[0] =  u * v * (1. - u) * (1. - v) / 4.;
    s[1] = -u * v * (1. + u) * (1. - v) / 4.;
    s[2] =  u * v * (1. + u) * (1. + v) / 4.;
    s[3] = -u * v * (1. - u) * (1. + v) / 4.;
    s[4] = -v * (1. - u) * (1. + u) * (1. - v) / 2.;
    s[5] =  u * (1. + u) * (1. - v) * (1. + v) / 2.;
    s[6] =  v * (1. - u) * (1. + u) * (1. + v) / 2.;
    s[7] = -u * (1. - u) * (1. - v) * (1. + v) / 2.;
    s[8] =  (1. - u) * (1. + u) * (1. - v) * (1. + v);
    break;
  default :
    printf("Order %d quadrangle function space not implemented ", order); print();
  }
}
void DI_Quad::getGradShapeFunctions (const double u, const double v, const double w, double s[][3], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0][0] = -0.25 * (1. - v); s[0][1] = -0.25 * (1. - u); s[0][2] = 0.;
    s[1][0] =  0.25 * (1. - v); s[1][1] = -0.25 * (1. + u); s[1][2] = 0.;
    s[2][0] =  0.25 * (1. + v); s[2][1] =  0.25 * (1. + u); s[2][2] = 0.;
    s[3][0] = -0.25 * (1. + v); s[3][1] =  0.25 * (1. - u); s[3][2] = 0.;
    break;
  case 2 :
    s[0][0] = v * (1. - v) * (1. - 2. * u) / 4.;
    s[0][1] = u * (1. - u) * (1. - 2.* v ) / 4.;
    s[0][2] = 0.;
    s[1][0] = -v * (1. - v) * (1. + 2. * u) / 4.;
    s[1][1] = -u * (1. + u) * (1. - 2. * v) / 4.;
    s[1][2] = 0.;
    s[2][0] = v * (1. + v) * (1. + 2. * u) / 4.;
    s[2][1] = u * (1. + u) * (1. + 2. * v) / 4.;
    s[2][2] = 0.;
    s[3][0] = -v * (1. + v) * (1. - 2. * u) / 4.;
    s[3][1] = -u * (1. - u) * (1. + 2. * v) / 4.;
    s[3][2] = 0.;
    s[4][0] = v * (1. - v) * u;
    s[4][1] = -(1. - u * u) * (1. - 2. * v) / 2.;
    s[4][2] = 0.;
    s[5][0] = (1. - v * v) * (1. + 2. * u) / 2.;
    s[5][1] = -u * (1. + u) * v;
    s[5][2] = 0.;
    s[6][0] = -v * (1. + v) * u;
    s[6][1] = (1. - u * u) * (1. + 2. * v) / 2.;
    s[6][2] = 0.;
    s[7][0] = -(1. - v * v) * (1. - 2. * u) / 2.;
    s[7][1] = u * (1. - u) * v;
    s[7][2] = 0.;
    s[8][0] = -(1. - v * v) * u * 2.;
    s[8][1] = -(1. - u * u) * v * 2.;
    s[8][2] = 0.;
    break;
  default :
    printf("Order %d quadrangle function space not implemented ", order); print();
  }
}
/*double q_detJ1 (const double &x, const double &y,
                const double &x0, const double &y0, const double &x1, const double &y1,
                const double &x2, const double &y2, const double &x3, const double &y3) {
  return (x0*(-1.+y)+x1*(1.-y)+x2*(1.+y)+x3*(-1.-y))*(y0*(x-1.)+y1*(-1.-x)+y2*(1.+x)+y3*(1.-x))/16.
        -(x0*(x-1.)+x1*(-1.-x)+x2*(1.+x)+x3*(1.-x))*(y0*(-1.+y)+y1*(1.-y)+y2*(1.+y)+y3*(-1.-y))/16.;
}
double q_detJ2 (const double &x, const double &y,
                const double &x0, const double &y0, const double &x1, const double &y1, const double &x2, const double &y2,
                const double &x3, const double &y3, const double &x4, const double &y4, const double &x5, const double &y5,
                const double &x6, const double &y6, const double &x7, const double &y7, const double &x8, const double &y8) {
  return (x0*y*(1-y)*(1-2*x)-x1*y*(1-y)*(1+2*x)+x2*y*(1+y)*(1+2*x)-x3*y*(1+y)*(1-2*x)+
          x4*4*y*(1-y)*x+x5*2*(1-y)*(1+y)*(1+2*x)-x6*4*y*(1+y)*x-x7*2*(1-y)*(1+y)*(1-2*x)-x8*8*(1-y)*(1+y)*x)
        *(y0*x*(1-x)*(1-2*y)-y1*x*(1+x)*(1-2*y)+y2*x*(1+x)*(1+2*y)-y3*x*(1-x)*(1+2*y)-
          y4*2*(1-x)*(1+x)*(1-2*y)-y5*4*x*(1+x)*y+y6*2*(1-x)*(1+x)*(1+2*y)+y7*4*x*(1-x)*y-y8*8*(1-x)*(1+x)*y)/16.
        -(x0*x*(1-x)*(1-2*y)-x1*x*(1+x)*(1-2*y)+x2*x*(1+x)*(1+2*y)-x3*x*(1-x)*(1+2*y)-
          x4*2*(1-x)*(1+x)*(1-2*y)-x5*4*x*(1+x)*y+x6*2*(1-x)*(1+x)*(1+2*y)+x7*4*x*(1-x)*y-x8*8*(1-x)*(1+x)*y)
        *(y0*y*(1-y)*(1-2*x)-y1*y*(1-y)*(1+2*x)+y2*y*(1+y)*(1+2*x)-y3*y*(1+y)*(1-2*x)+
          y4*4*y*(1-y)*x+y5*2*(1-y)*(1+y)*(1+2*x)-y6*4*y*(1+y)*x-y7*2*(1-y)*(1+y)*(1-2*x)-y8*8*(1-y)*(1+y)*x)/16.;
}
double DI_Quad::detJ (const double &xP, const double &yP, const double &zP) const {
  assert (zP == 0 && z(0) == 0 && z(1) == 0 && z(2) == 0 && z(3) == 0 && z2(0) == 0 && z2(1) == 0 && z2(2) == 0 && z2(3) == 0 && z2(4) == 0);
  if(!isQuad()) return q_detJ1(xP, yP, x(0), y(0), x(1), y(1), x(2), y(2), x(3), y(3));
  return q_detJ2(xP, yP, x(0), y(0), x(1), y(1), x(2), y(2), x(3), y(3), x2(0), y2(0), x2(1), y2(1), x2(2), y2(2), x2(3), y2(3), x2(4), y2(4));
}*/

// DI_Tetra methods ----------------------------------------------------------------------------------------------------------------------
void DI_Tetra::computeIntegral() {
    integral_ = TetraVol(pt(0), pt(1), pt(2), pt(3));
}
void DI_Tetra::getShapeFunctions (double u, double v, double w, double s[], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0] = 1. - u - v - w;
    s[1] = u;
    s[2] = v;
    s[3] = w;
    break;
  case 2 :
    s[0] = (1. - u - v - w) * (1. - 2. * u - 2. * v - 2. * w);
    s[1] = u * (2. * u - 1.);
    s[2] = v * (2. * v - 1.);
    s[3] = w * (2. * w - 1.);
    s[4] = 4. * u * (1. - u - v - w);
    s[5] = 4. * v * (1. - u - v - w);
    s[6] = 4. * w * (1. - u - v - w);
    s[7] = 4. * u * v;
    s[8] = 4. * v * w;
    s[9] = 4. * u * w;
    break;
  default :
    printf("Order %d tetrahedron function space not implemented ", order); print();
  }
}
void DI_Tetra::getGradShapeFunctions (const double u, const double v, const double w, double s[][3], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0][0] = -1.; s[0][1] = -1.; s[0][2] = -1.;
    s[1][0] =  1.; s[1][1] =  0.; s[1][2] =  0.;
    s[2][0] =  0.; s[2][1] =  1.; s[2][2] =  0.;
    s[3][0] =  0.; s[3][1] =  0.; s[3][2] =  1.;
    break;
  case 2 :
    s[0][0] = -3. + 4. * u + 4. * v + 4. * w;
    s[0][1] = -3. + 4. * u + 4. * v + 4. * w;
    s[0][2] = -3. + 4. * u + 4. * v + 4. * w;
    s[1][0] = 4. * u - 1.;
    s[1][1] = 0.;
    s[1][2] = 0.;
    s[2][0] = 0.;
    s[2][1] = 4. * v - 1.;
    s[2][2] = 0.;
    s[3][0] = 0.;
    s[3][1] = 0.;
    s[3][2] = 4. * w - 1.;
    s[4][0] = 4. * (1. - 2. * u - v - w);
    s[4][1] = -4. * u;
    s[4][2] = -4. * u;
    s[5][0] = -4. * v;
    s[5][1] = 4. * (1. - u - 2. * v - w);
    s[5][2] = -4. * v;
    s[6][0] = -4. * w;
    s[6][1] = -4. * w;
    s[6][2] = 4. * (1. - u - v - 2. * w);
    s[7][0] = 4. * v;
    s[7][1] = 4. * u;
    s[7][2] = 0.;
    s[8][0] = 0.;
    s[8][1] = 4. * w;
    s[8][2] = 4. * v;
    s[9][0] = 4. * w;
    s[9][1] = 0.;
    s[9][2] = 4. * u;
    break;
  default :
    printf("Order %d tetrahedron function space not implemented ", order); print();
  }
}
double DI_Tetra::quality() const {
  return qualityTet(x(0), y(0), z(0), x(1), y(1), z(1), x(2), y(2), z(2), x(3), y(3), z(3));
}

/*double tet_detJ1 (const double &x, const double &y, const double &z,
                  const double &x0, const double &y0, const double &z0, const double &x1, const double &y1, const double &z1,
                  const double &x2, const double &y2, const double &z2, const double &x3, const double &y3, const double &z3) {
  return det3(x1-x0, x2-x0, x3-x0, y1-y0, y2-y0, y3-y0, z1-z0, z2-z0, z3-z0); // detJ is constant in a linear tetrahedron
}
double tet_detJ2 (const double &x, const double &y, const double &z,
                  const double &x0, const double &y0, const double &z0, const double &x1, const double &y1, const double &z1,
                  const double &x2, const double &y2, const double &z2, const double &x3, const double &y3, const double &z3,
                  const double &x4, const double &y4, const double &z4, const double &x5, const double &y5, const double &z5,
                  const double &x6, const double &y6, const double &z6, const double &x7, const double &y7, const double &z7,
                  const double &x8, const double &y8, const double &z8, const double &x9, const double &y9, const double &z9) {
  return det3(x0*(-3+4*x+4*y+4*z)+x1*(4*x-1)+x4*4*(1-2*x-y-z)-x5*4*y-x6*4*z+x7*4*y+x9*4*z,
              x0*(-3+4*x+4*y+4*z)+x2*(4*y-1)-x4*4*x+x5*4*(1-x-2*y-z)-x6*4*z+x7*4*x+x8*4*z,
              x0*(-3+4*x+4*y+4*z)+x3*(4*z-1)-x4*4*x-x5*4*y+x6*4*(1-x-y-2*z)+x8*4*y+x9*4*x,
              y0*(-3+4*x+4*y+4*z)+y1*(4*x-1)+y4*4*(1-2*x-y-z)-y5*4*y-y6*4*z+y7*4*y+y9*4*z,
              y0*(-3+4*x+4*y+4*z)+y2*(4*y-1)-y4*4*x+y5*4*(1-x-2*y-z)-y6*4*z+y7*4*x+y8*4*z,
              y0*(-3+4*x+4*y+4*z)+y3*(4*z-1)-y4*4*x-y5*4*y+y6*4*(1-x-y-2*z)+y8*4*y+y9*4*x,
              z0*(-3+4*x+4*y+4*z)+z1*(4*x-1)+z4*4*(1-2*x-y-z)-z5*4*y-z6*4*z+z7*4*y+z9*4*z,
              z0*(-3+4*x+4*y+4*z)+z2*(4*y-1)-z4*4*x+z5*4*(1-x-2*y-z)-z6*4*z+z7*4*x+z8*4*z,
              z0*(-3+4*x+4*y+4*z)+z3*(4*z-1)-z4*4*x-z5*4*y+z6*4*(1-x-y-2*z)+z8*4*y+z9*4*x);
}
double DI_Tetra::detJ (const double &xP, const double &yP, const double &zP) const {
  if(!isQuad())  return tet_detJ1(xP, yP, zP, x(0), y(0), z(0), x(1), y(1), z(1), x(2), y(2), z(2), x(3), y(3), z(3));
  return tet_detJ2(xP, yP, zP, x(0), y(0), z(0), x(1), y(1), z(1), x(2), y(2), z(2), x(3), y(3), z(3),
                   x2(0), y2(0), z2(0), x2(1), y2(1), z2(1), x2(2), y2(2), z2(2), x2(3), y2(3), z2(3), x2(4), y2(4), z2(4), x2(5), y2(5), z2(5));
}*/
/*void DI_Tetra::quad(const DI_Element *e, const std::vector<const gLevelset *> RPNi) {
  mid_ = new DI_Point*[6];
  mid_[0] = new DI_Point((x(0)+x(1))/2., (y(0)+y(1))/2., (z(0)+z(1))/2., e, RPNi);
  mid_[1] = new DI_Point((x(0)+x(2))/2., (y(0)+y(2))/2., (z(0)+z(2))/2., e, RPNi);
  mid_[2] = new DI_Point((x(0)+x(3))/2., (y(0)+y(3))/2., (z(0)+z(3))/2., e, RPNi);
  mid_[3] = new DI_Point((x(1)+x(2))/2., (y(1)+y(2))/2., (z(1)+z(2))/2., e, RPNi);
  mid_[4] = new DI_Point((x(2)+x(3))/2., (y(2)+y(3))/2., (z(2)+z(3))/2., e, RPNi);
  mid_[5] = new DI_Point((x(3)+x(1))/2., (y(3)+y(1))/2., (z(3)+z(1))/2., e, RPNi);
  quad_ = true;
}*/

// Hexahedron methods ------------------------------------------------------------------------------------------------------------
void DI_Hexa::computeIntegral() {
    integral_ = TetraVol(pt(0), pt(1), pt(3), pt(4)) + TetraVol(pt(1), pt(4), pt(5), pt(7))
              + TetraVol(pt(1), pt(3), pt(4), pt(7)) + TetraVol(pt(2), pt(5), pt(6), pt(7))
              + TetraVol(pt(1), pt(2), pt(3), pt(7)) + TetraVol(pt(1), pt(5), pt(2), pt(7));
}
void DI_Hexa::getShapeFunctions (double u, double v, double w, double s[], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0] = (1. - u) * (1. - v) * (1. - w) / 8.;
    s[1] = (1. + u) * (1. - v) * (1. - w) / 8.;
    s[2] = (1. + u) * (1. + v) * (1. - w) / 8.;
    s[3] = (1. - u) * (1. + v) * (1. - w) / 8.;
    s[4] = (1. - u) * (1. - v) * (1. + w) / 8.;
    s[5] = (1. + u) * (1. - v) * (1. + w) / 8.;
    s[6] = (1. + u) * (1. + v) * (1. + w) / 8.;
    s[7] = (1. - u) * (1. + v) * (1. + w) / 8.;
    break;
  case 2 :
    s[0] = -u * v * w * (1. - u) * (1. - v) * (1. - w) / 8.;
    s[1] =  u * v * w * (1. + u) * (1. - v) * (1. - w) / 8.;
    s[2] = -u * v * w * (1. + u) * (1. + v) * (1. - w) / 8.;
    s[3] =  u * v * w * (1. - u) * (1. + v) * (1. - w) / 8.;
    s[4] =  u * v * w * (1. - u) * (1. - v) * (1. + w) / 8.;
    s[5] = -u * v * w * (1. + u) * (1. - v) * (1. + w) / 8.;
    s[6] =  u * v * w * (1. + u) * (1. + v) * (1. + w) / 8.;
    s[7] = -u * v * w * (1. - u) * (1. + v) * (1. + w) / 8.;
    s[8] =  v * w * (1. - u) * (1. + u) * (1. - v) * (1. - w) / 4.;
    s[9] = -u * w * (1. - v) * (1. + v) * (1. + u) * (1. - w) / 4.;
    s[10] = -v * w * (1. - u) * (1. + u) * (1. + v) * (1. - w) / 4.;
    s[11] =  u * w * (1. - v) * (1. + v) * (1. - u) * (1. - w) / 4.;
    s[12] =  u * v * (1. - w) * (1. + w) * (1. - u) * (1. - v) / 4.;
    s[13] = -u * v * (1. - w) * (1. + w) * (1. + u) * (1. - v) / 4.;
    s[14] =  u * v * (1. - w) * (1. + w) * (1. + u) * (1. + v) / 4.;
    s[15] = -u * v * (1. - w) * (1. + w) * (1. - u) * (1. + v) / 4.;
    s[16] = -v * w * (1. - u) * (1. + u) * (1. - v) * (1. + w) / 4.;
    s[17] =  u * w * (1. - v) * (1. + v) * (1. + u) * (1. + w) / 4.;
    s[18] =  v * w * (1. - u) * (1. + u) * (1. + v) * (1. + w) / 4.;
    s[19] = -u * w * (1. - v) * (1. + v) * (1. - u) * (1. + w) / 4.;
    s[20] = -w * (1. - w) * (1. + u) * (1. - u) * (1. + v) * (1. - v) / 2.;
    s[21] = -v * (1. - v) * (1. + u) * (1. - u) * (1. + w) * (1. - w) / 2.;
    s[22] =  u * (1. + u) * (1. + v) * (1. - v) * (1. + w) * (1. - w) / 2.;
    s[23] =  v * (1. + v) * (1. + u) * (1. - u) * (1. + w) * (1. - w) / 2.;
    s[24] = -u * (1. - u) * (1. + v) * (1. - v) * (1. + w) * (1. - w) / 2.;
    s[25] =  w * (1. + w) * (1. + u) * (1. - u) * (1. + v) * (1. - v) / 2.;
    s[26] =  (1. + u) * (1. - u) * (1. + v) * (1. - v) * (1. + w) * (1. - w);
    break;
  default :
    printf("Order %d hexahedron function space not implemented ", order); print();
  }
}
void DI_Hexa::getGradShapeFunctions (const double u, const double v, const double w, double s[][3], int ord) const {
  int order = (ord == -1) ? getPolynomialOrder() : ord;
  switch (order) {
  case 1 :
    s[0][0] = -0.125 * (1. - v) * (1. - w);
    s[0][1] = -0.125 * (1. - u) * (1. - w);
    s[0][2] = -0.125 * (1. - u) * (1. - v);
    s[1][0] =  0.125 * (1. - v) * (1. - w);
    s[1][1] = -0.125 * (1. + u) * (1. - w);
    s[1][2] = -0.125 * (1. + u) * (1. - v);
    s[2][0] =  0.125 * (1. + v) * (1. - w);
    s[2][1] =  0.125 * (1. + u) * (1. - w);
    s[2][2] = -0.125 * (1. + u) * (1. + v);
    s[3][0] = -0.125 * (1. + v) * (1. - w);
    s[3][1] =  0.125 * (1. - u) * (1. - w);
    s[3][2] = -0.125 * (1. - u) * (1. + v);
    s[4][0] = -0.125 * (1. - v) * (1. + w);
    s[4][1] = -0.125 * (1. - u) * (1. + w);
    s[4][2] =  0.125 * (1. - u) * (1. - v);
    s[5][0] =  0.125 * (1. - v) * (1. + w);
    s[5][1] = -0.125 * (1. + u) * (1. + w);
    s[5][2] =  0.125 * (1. + u) * (1. - v);
    s[6][0] =  0.125 * (1. + v) * (1. + w);
    s[6][1] =  0.125 * (1. + u) * (1. + w);
    s[6][2] =  0.125 * (1. + u) * (1. + v);
    s[7][0] = -0.125 * (1. + v) * (1. + w);
    s[7][1] =  0.125 * (1. - u) * (1. + w);
    s[7][2] =  0.125 * (1. - u) * (1. + v);
    break;
  default :
    printf("Order %d hexahedron function space not implemented ", order); print();
  }
}
/*void DI_Hexa::quad(const DI_Element *e, const std::vector<const gLevelset *> RPNi) {
  mid_ = new DI_Point*[19];
  mid_[0] = new DI_Point((x(0)+x(1))/2., (y(0)+y(1))/2., (z(0)+z(1))/2., e, RPNi);
  mid_[1] = new DI_Point((x(1)+x(2))/2., (y(1)+y(2))/2., (z(1)+z(2))/2., e, RPNi);
  mid_[2] = new DI_Point((x(2)+x(3))/2., (y(2)+y(3))/2., (z(2)+z(3))/2., e, RPNi);
  mid_[3] = new DI_Point((x(3)+x(0))/2., (y(3)+y(0))/2., (z(3)+z(0))/2., e, RPNi);
  mid_[4] = new DI_Point((x(0)+x(4))/2., (y(0)+y(4))/2., (z(0)+z(4))/2., e, RPNi);
  mid_[5] = new DI_Point((x(1)+x(5))/2., (y(1)+y(5))/2., (z(1)+z(5))/2., e, RPNi);
  mid_[6] = new DI_Point((x(2)+x(6))/2., (y(2)+y(6))/2., (z(2)+z(6))/2., e, RPNi);
  mid_[7] = new DI_Point((x(3)+x(7))/2., (y(3)+y(7))/2., (z(3)+z(7))/2., e, RPNi);
  mid_[8] = new DI_Point((x(4)+x(5))/2., (y(4)+y(5))/2., (z(4)+z(5))/2., e, RPNi);
  mid_[9] = new DI_Point((x(5)+x(6))/2., (y(5)+y(6))/2., (z(5)+z(6))/2., e, RPNi);
  mid_[10] = new DI_Point((x(6)+x(7))/2., (y(6)+y(7))/2., (z(6)+z(7))/2., e, RPNi);
  mid_[11] = new DI_Point((x(7)+x(4))/2., (y(7)+y(4))/2., (z(7)+z(4))/2., e, RPNi);
  mid_[12] = new DI_Point((x(0)+x(1)+x(2)+x(3))/4., (y(0)+y(1)+y(2)+y(3))/4., (z(0)+z(1)+z(2)+z(3))/4., e, RPNi);
  mid_[13] = new DI_Point((x(0)+x(1)+x(4)+x(5))/4., (y(0)+y(1)+y(4)+y(5))/4., (z(0)+z(1)+z(4)+z(5))/4., e, RPNi);
  mid_[14] = new DI_Point((x(1)+x(2)+x(5)+x(6))/4., (y(1)+y(2)+y(5)+y(6))/4., (z(1)+z(2)+z(5)+z(6))/4., e, RPNi);
  mid_[15] = new DI_Point((x(2)+x(3)+x(6)+x(7))/4., (y(2)+y(3)+y(6)+y(7))/4., (z(2)+z(3)+z(6)+z(7))/4., e, RPNi);
  mid_[16] = new DI_Point((x(0)+x(3)+x(4)+x(7))/4., (y(0)+y(3)+y(4)+y(7))/4., (z(0)+z(3)+z(4)+z(7))/4., e, RPNi);
  mid_[17] = new DI_Point((x(4)+x(5)+x(6)+x(7))/4., (y(4)+y(5)+y(6)+y(7))/4., (z(4)+z(5)+z(6)+z(7))/4., e, RPNi);
  mid_[18] = new DI_Point((x(0)+x(1)+x(2)+x(3)+x(4)+x(5)+x(6)+x(7))/8., (y(0)+y(1)+y(2)+y(3)+y(4)+y(5)+y(6)+y(7))/8.,
                       (z(0)+z(1)+z(2)+z(3)+z(4)+z(5)+z(6)+z(7))/8., e, RPNi);
  quad_ = true;
}*/

// ----------------------------------------------------------------------------
// -------------------------- SPLITTING ---------------------------------------
// ----------------------------------------------------------------------------

// Split a reference line cut by a level set into sublines
void DI_Line::selfSplit (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                          std::vector<DI_Line> &subLines, std::vector<DI_CuttingPoint> &cuttingPoints) const
{
  if (!isCrossed(pt(0), pt(1))) {
    subLines.push_back(*this);
    return;
  }

  // compute the intersection between the line and the level set
  DI_Point U = Newton(pt(0), pt(1), e, RPNi);
  cuttingPoints.push_back(DI_CuttingPoint(U));

  // line cut => split into 2 sublines
  subLines.push_back(DI_Line(pt(0), U, lsTag()));
  subLines.push_back(DI_Line(U, pt(1), lsTag()));
}

// Split a triangle into 4 sub-triangles
void DI_Triangle::splitIntoSubTriangles (std::vector<DI_Triangle> &subTriangles) const {
  DI_Point p01 = middle(pt(0), pt(1));
  DI_Point p02 = middle(pt(0), pt(2));
  DI_Point p12 = middle(pt(1), pt(2));

  subTriangles.push_back(DI_Triangle(p01, p02, p12));   // 01-02-12
  subTriangles.push_back(DI_Triangle(pt(0), p01, p02)); // 0-01-02
  subTriangles.push_back(DI_Triangle(pt(1), p01, p12)); // 1-01-12
  subTriangles.push_back(DI_Triangle(pt(2), p02, p12)); // 2-02-12
}
// Split a reference triangle cut by a level set into subtriangles
void DI_Triangle::selfSplit (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                             std::vector<DI_Quad> &subQuads, std::vector<DI_Triangle> &subTriangles,
                             std::vector<DI_Line> &surfLines, std::vector<DI_CuttingPoint> &cuttingPoints) const
{
  bool quadT = false; // if true, use quadratic sub triangles
  int LStag = RPNi.back()->getTag();

  int nbZe = 0, ze[2];
  for(int i = 0; i < 3; i++)
    if(fabs(pt(i).ls()) < ZERO_LS_TOL)
      ze[nbZe++] = i;
  for(int i = 0; i < nbZe; i++)
    cuttingPoints.push_back(DI_CuttingPoint(pt(ze[i])));
    // !! we add these points several times => remove later

  if (!isCrossed(pt(0), pt(1)) && !isCrossed(pt(0), pt(2)) && !isCrossed(pt(1), pt(2))) {
    subTriangles.push_back(*this);
    if(nbZe == 2)
      surfLines.push_back(DI_Line(pt(ze[0]), pt(ze[1]), LStag));
      // !! we add these lines twice => remove the second later
    return;
  }

  DI_Point U[2];              // cutting points (max2)
  int IND[2];                 // ids of edges cut
  int COUNT = 0;                // number of edges cut

  // compute the intersections between the edges of the triangle and the level set
  for(int i = 0; i < 3; i++){
    int n1 = i, n2 = (i + 1) % 3;
    if (isCrossed(pt(n1), pt(n2))) {
      U[COUNT] = Newton(pt(n1), pt(n2), e, RPNi);
      IND[COUNT++] = i;
    }
  }

  for(int i = 0; i < COUNT; i++)
    cuttingPoints.push_back(DI_CuttingPoint(U[i]));

  // Adjust the indices of the nodes in order to have the same pattern for each case with the same number of edges cut;
  // compute the position of the middle nodes on the quadratic edges of the sub triangles;
  // and create the sub triangles
  switch (COUNT) {
    case 1 : {// 1 edge cut => split into 2 triangles
      int s1 = IND[0];
      int s2 = (s1 + 1) % 3;
      int s3 = (s2 + 1) % 3;

      DI_Triangle t1 = DI_Triangle(pt(s3), pt(s1), U[0], lsTag()); //t1.print();
      DI_Triangle t2 = DI_Triangle(pt(s2), pt(s3), U[0], lsTag()); //t2.print();
      DI_Line ln = DI_Line(U[0], pt(s3), LStag); //ln.print();

      if(quadT){
        DI_Point midEN2 = quadMidNode(U[0], pt(s3), pt(s1), e, RPNi); // intersection between ls and the bissector between the cutting points
        cuttingPoints.push_back(DI_CuttingPoint(midEN2));
        //midEN2.printls();
        t1.addQuadEdge (2, &midEN2, e, RPNi); //t1.printls();
        t2.addQuadEdge (1, &midEN2, e, RPNi); //t2.printls();
        ln.addQuadEdge (0, &midEN2, e, RPNi); //ln.printls();
      }
      subTriangles.push_back(t1);
      subTriangles.push_back(t2);
      surfLines.push_back(ln);
      break;
    }
    case 2: {// 2 edges cut => 1 triangle + 1 quad => split into 3 triangles
      int s1 = 2 * IND[0] - IND[1] + 2; // arbitrary formulation to find the good vertex !!!
      int s2 = (s1 + 1) % 3;
      int s3 = (s1 + 2) % 3;
      if(s1 == 0) { // (0,2) => swap U[0] and U[1]
        swap(U[0], U[1]);
      }

      bool useQuads = false; // if true, split the triangle into 1 triangle and 1 quad

      DI_Triangle t1 = DI_Triangle(U[0], pt(s1), U[1], lsTag());
      DI_Line ln = DI_Line(U[0], U[1], LStag);
      DI_Quad q1; DI_Triangle t2, t3;
      if(useQuads) q1 = DI_Quad(U[0], U[1], pt(s2), pt(s3), lsTag());
      else bestQuality(U[0], U[1], pt(s2), pt(s3), t2, t3);
      t2.setLsTag(lsTag()); t3.setLsTag(lsTag());

      if(quadT){
        DI_Point midEN2 = quadMidNode(U[0], U[1], pt(s2), e, RPNi); // intersection between ls and the bissector between the cutting points
        cuttingPoints.push_back(DI_CuttingPoint(midEN2));
        //midEN2.printls();
        t1.addQuadEdge(2, &midEN2, e, RPNi); //t1.printls();
        ln.addQuadEdge(0, &midEN2, e, RPNi); //ln.printls();
        if(useQuads) q1.addQuadEdge(0, &midEN2, e, RPNi);
        else t2.addQuadEdge(0, &midEN2, e, RPNi); //t2.printls();
      }
      subTriangles.push_back(t1);
      surfLines.push_back(ln);
      if(useQuads) subQuads.push_back(q1);
      else {
        subTriangles.push_back(t2);
        subTriangles.push_back(t3);
      }
      break;
    }
    default:
      printf("Error : %d edge(s) cut in the triangle (ls : %g %g %g)\n",
             COUNT, pt(0).ls(), pt(1).ls(), pt(2).ls());
  }
}

// Split a reference Quadrangle into 2 triangles
void DI_Quad::splitIntoTriangles(std::vector<DI_Triangle> &triangles) const
{
  triangles.push_back(DI_Triangle(pt(0), pt(1), pt(3), lsTag())); // 013
  triangles.push_back(DI_Triangle(pt(1), pt(2), pt(3), lsTag())); // 123
}

// Split a reference tetrahedron cut by a level set (defined in a hex) into sub tetrahedra and create triangles on the surface of the level set
void DI_Tetra::selfSplit (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                       std::vector<DI_Tetra> &subTetras, std::vector<DI_Triangle> &surfTriangles,
                       std::vector<DI_CuttingPoint> &cuttingPoints, std::vector<DI_QualError> &QError) const
{
  bool quadT = false; // use of quadratic surf triangles and quadratic sub tetrahedra
  int tag = RPNi.back()->getTag();

  int nbZe = 0, ze[3];
  for(int i = 0; i < 4; i++)
    if(fabs(pt(i).ls()) < ZERO_LS_TOL)
      ze[nbZe++] = i;
  for(int i = 0; i < nbZe; i++)
    cuttingPoints.push_back(DI_CuttingPoint(pt(ze[i]))); // !! we add these points several times => remove later

  // case 0 : the tetrahedron is not cut by the level set
  if (!isCrossed(pt(0), pt(1)) && !isCrossed(pt(0), pt(2)) && !isCrossed(pt(1), pt(2)) &&
      !isCrossed(pt(0), pt(3)) && !isCrossed(pt(1), pt(3)) && !isCrossed(pt(2), pt(3))) {
    subTetras.push_back(*this);
    if(nbZe == 3)
      surfTriangles.push_back(DI_Triangle(pt(ze[0]), pt(ze[1]), pt(ze[2]), tag));
      // !! we add these triangles twice => remove the second later
    return;
  }

  DI_Point U[4];        // cutting points
  int COUNT = 0;       // number of edges cut
  int IND[4];        // ids of edges cut

  int tab [6][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {1, 2, 0, 3}, {2, 3, 0, 1}, {3, 1, 0, 2}}; // edges nodes and opposite edges nodes

  // compute the intersections between the edges of the tetra and the level set.
  for(int i = 0; i < 6; i++){
    int n1 = tab[i][0], n2 = tab[i][1];
    if (isCrossed(pt(n1), pt(n2))) {
      //printf("edge %d%d cut vls:%g/%g (%g,%g,%g) (%g,%g,%g)\n",n1,n2,vls[n1],vls[n2],x(n1),y(n1),z(n1),x(n2),y(n2),z(n2));
      U[COUNT] = Newton(pt(n1), pt(n2), e, RPNi);
      IND[COUNT++] = i;
    }
  }
  for(int i = 0; i < COUNT; i++)
    cuttingPoints.push_back(DI_CuttingPoint(U[i]));

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

      DI_Tetra t1 = DI_Tetra(U[0], pt(s4), pt(s3), pt(s1));
      DI_Tetra t2 = DI_Tetra(pt(s4), U[0], pt(s3), pt(s2));
      DI_Triangle tr = DI_Triangle(pt(s4), U[0], pt(s3), tag);

      if(quadT){
        DI_Point midEN2[2]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[0], pt(s4), pt(s1), e, RPNi);
        midEN2[1] = quadMidNode(U[0], pt(s3), pt(s1), e, RPNi);
        tr.addQuadEdge (0, &midEN2[0], e, RPNi);
        t1.addQuadEdge (0, &midEN2[0], e, RPNi);
        t2.addQuadEdge (0, &midEN2[0], e, RPNi);
        tr.addQuadEdge (1, &midEN2[1], e, RPNi);
        t1.addQuadEdge (1, &midEN2[1], e, RPNi);
        t2.addQuadEdge (3, &midEN2[1], e, RPNi);
      }
      subTetras.push_back(t1);
      subTetras.push_back(t2);
      surfTriangles.push_back(tr);
      break;
    }
    case 2 : {// 2 edges cut => 1 tetra + 1 pyramid => split into 3 tetras
      int i1 = IND[0], i2 = IND[1];

      if((i1 == 0 && (i2 == 2 ||i2 == 3)) || (i1 == 1 && i2 == 4) || ((i1 == 2 || i1 == 3) && i2 == 5)) {
        swap(U[0], U[1]); swap(i1, i2);
      }
      //printf("case 2 : ind : %d,%d\n",i1,i2);

      int s1 = commonV(tab[i1][2], tab[i1][3], tab[i2][2], tab[i2][3]);
      int s2 = commonV(tab[i1][0], tab[i1][1], tab[i2][0], tab[i2][1]);
      int s3 = commonV(tab[i1][2], tab[i1][3], tab[i2][0], tab[i2][1]);
      int s4 = commonV(tab[i1][0], tab[i1][1], tab[i2][2], tab[i2][3]);

      DI_Tetra t1 = DI_Tetra(U[0], U[1], pt(s2), pt(s1));
      DI_Triangle tr = DI_Triangle(U[0], U[1], pt(s1), tag);
      DI_Tetra t2, t3;
      int qual = bestQuality(U[1], U[0], pt(s4), pt(s3), pt(s1), t2, t3);

      if(quadT){
        DI_Point midEN2[3]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[1], pt(s1), pt(s2), e, RPNi);
        midEN2[1] = quadMidNode(U[0], pt(s1), pt(s2), e, RPNi);
        midEN2[2] = quadMidNode(U[1], U[0], pt(s4), e, RPNi);
        tr.addQuadEdge(1, &midEN2[0], e, RPNi);
        t1.addQuadEdge(5, &midEN2[0], e, RPNi);
        t2.addQuadEdge(2, &midEN2[0], e, RPNi);
        t3.addQuadEdge(2, &midEN2[0], e, RPNi);

        tr.addQuadEdge(2, &midEN2[1], e, RPNi);
        t1.addQuadEdge(2, &midEN2[1], e, RPNi);
        t2.addQuadEdge(5, &midEN2[1], e, RPNi);

        tr.addQuadEdge(0, &midEN2[2], e, RPNi);
        if(t2.addQuadEdge(0, &midEN2[2], e, RPNi)) {
          t1.addQuadEdge(0, &midEN2[2], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s3), pt(s4), e, RPNi);
          DI_Point quad = middle(mid, midEN2[2], e, RPNi);
          if(qual == 1){
            t2.addQuadEdge(1, &quad, e, RPNi);
            t3.addQuadEdge(0, &quad, e, RPNi);
          }
          else {
            t2.addQuadEdge(3, &quad, e, RPNi);
            t3.addQuadEdge(1, &quad, e, RPNi);
          }
          if(t2.addQuadEdge(0, &midEN2[2], e, RPNi)) {
            t1.addQuadEdge(0, &midEN2[2], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U1 to the subtetrahedra cas 2.\n");
        }
      }

      subTetras.push_back(t1);
      subTetras.push_back(t2);
      subTetras.push_back(t3);
      surfTriangles.push_back(tr);
      break;
    }
    case 3 : {// 3 edges cut => 1 tetra + 1 prism => split into 4 tetras
      int i1 = IND[0], i2 = IND[1], i3 = IND[2];

      if(i1 == 0 && i2 == 3) {
        swap(U[1], U[2]); swap(i2, i3);
      }
      //printf("case 3 : ind : %d,%d,%d\n",i1,i2,i3);

      int s1 = commonV(tab[i1][0], tab[i1][1], tab[i2][0], tab[i2][1]);
      int s2 = commonV(tab[i2][2], tab[i2][3], tab[i3][2], tab[i3][3]);
      int s3 = commonV(tab[i1][2], tab[i1][3], tab[i3][2], tab[i3][3]);
      int s4 = commonV(tab[i1][2], tab[i1][3], tab[i2][2], tab[i2][3]);   //printf("s: %d %d %d %d\n",s1,s2,s3,s4);

      DI_Tetra t1 = DI_Tetra(pt(s1), U[0], U[1], U[2]);
      DI_Triangle tr = DI_Triangle(U[0], U[1], U[2], tag); //t1.print(); tr.print();
      DI_Tetra t2, t3, t4;
      bestQuality(U[0], U[1], U[2], pt(s2), pt(s3), pt(s4), t2, t3, t4, QError); //t2.print(); t3.print(); t4.print();
      /*t2 = DI_Tetra(U[0],V[0],W[0], x(s2),y(s2),z(s2), U[1],V[1],W[1], U[2],V[2],W[2]);
      t3 = DI_Tetra(U[2],V[2],W[2], U[1],V[1],W[1], x(s3),y(s3),z(s3), x(s2),y(s2),z(s2));
      t4 = DI_Tetra(U[2],V[2],W[2], x(s3),y(s3),z(s3), x(s4),y(s4),z(s4), x(s2),y(s2),z(s2));*/
      if(quadT){
        DI_Point midEN2[3]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[2], U[1], pt(s3), e, RPNi);
        midEN2[1] = quadMidNode(U[1], U[0], pt(s2), e, RPNi);
        midEN2[2] = quadMidNode(U[2], U[0], pt(s2), e, RPNi);
        tr.addQuadEdge(1, &midEN2[0], e, RPNi);
        if(t3.addQuadEdge(0, &midEN2[0], e, RPNi)) {
          t1.addQuadEdge(5, &midEN2[0], e, RPNi);
          t2.addQuadEdge(4, &midEN2[0], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s3), pt(s4), e, RPNi);
          DI_Point quad = middle(mid, midEN2[0], e, RPNi);
          t3.addQuadEdge(1, &quad, e, RPNi);
          t4.addQuadEdge(0, &quad, e, RPNi);
          if(t3.addQuadEdge(0, &midEN2[0], e, RPNi)) {
            t1.addQuadEdge(5, &midEN2[0], e, RPNi);
            t2.addQuadEdge(4, &midEN2[0], e, RPNi);
          }
          else printf("unable to add quadratic edge U1U2 to the subtetrahedra cas 3.\n");
        }

        tr.addQuadEdge(0, &midEN2[1], e, RPNi);
        if(t2.addQuadEdge(1, &midEN2[1], e, RPNi)) {
          t1.addQuadEdge(0, &midEN2[1], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s2), pt(s3), e, RPNi);
          DI_Point quad = middle(mid, midEN2[1], e, RPNi);
          t2.addQuadEdge(3, &quad, e, RPNi);
          t3.addQuadEdge(5, &quad, e, RPNi);
          if(t2.addQuadEdge(1, &midEN2[1], e, RPNi)) {
            t1.addQuadEdge(0, &midEN2[1], e, RPNi);
          }
          else printf("unable to add quadratic edge U1U2 to the subtetrahedra cas 3.\n");
        }

        tr.addQuadEdge(2, &midEN2[2], e, RPNi);
        if(t2.addQuadEdge(2, &midEN2[2], e, RPNi)) {
          t1.addQuadEdge(2, &midEN2[2], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s2), pt(s4), e, RPNi);
          DI_Point quad = middle(mid, midEN2[2], e, RPNi);
          t2.addQuadEdge(5, &quad, e, RPNi);
          t3.addQuadEdge(2, &quad, e, RPNi);
          t4.addQuadEdge(2, &quad, e, RPNi);
          if(t2.addQuadEdge(2, &midEN2[2], e, RPNi)) {
            t1.addQuadEdge(2, &midEN2[2], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U2 to the subtetrahedra cas 3.\n");
        }
      }

      subTetras.push_back(t1);
      subTetras.push_back(t2);
      subTetras.push_back(t3);
      subTetras.push_back(t4);
      surfTriangles.push_back(tr);
      break;
    }
    case 4 : {// 4 edges cut => 2 prisms => split into 6 tetras
      int i1 = IND[0], i2 = IND[1], i3 = IND[2], i4 = IND[3];

      if(i1 == 0 && i2 == 2) {
        swap(U[0], U[1]); swap(i1, i2);
      }
      else if(i1 == 1 && i2 == 2) {
        swap(U[2], U[3]); swap(i3, i4);
      }
      //printf("case 4 : ind : %d,%d,%d,%d\n",i1,i2,i3,i4);

      int s1 = commonV(tab[i1][0], tab[i1][1], tab[i2][0], tab[i2][1]);
      int s2 = commonV(tab[i1][0], tab[i1][1], tab[i2][2], tab[i2][3]);
      int s3 = commonV(tab[i1][2], tab[i1][3], tab[i2][0], tab[i2][1]);
      int s4 = commonV(tab[i1][2], tab[i1][3], tab[i2][2], tab[i2][3]);   //printf("s: %d %d %d %d\n",s1,s2,s3,s4);

      DI_Tetra t1, t2, t3, t4, t5, t6;
      DI_Triangle tr1, tr2;
      bestQuality(U[0], U[1], U[2], U[3], tr1, tr2);
      tr1.setLsTag(tag); tr2.setLsTag(tag);
      bestQuality(pt(s1), U[0], U[1], pt(s4), U[3], U[2], t1, t2, t3, QError);
      bestQuality(pt(s2), U[0], U[3], pt(s3), U[1], U[2], t4, t5, t6, QError);
      //tr1.print(); tr2.print(); t1.print(); t2.print(); t3.print(); t4.print(); t5.print(); t6.print();
      /*t1 = DI_Tetra(U[0],V[0],W[0], x(s2),y(s2),z(s2), U[1],V[1],W[1],    U[3],V[3],W[3]);
      t2 = DI_Tetra(U[1],V[1],W[1], U[3],V[3],W[3],    x(s2),y(s2),z(s2), U[2],V[2],W[2]);
      t3 = DI_Tetra(U[1],V[1],W[1], x(s2),y(s2),z(s2), x(s3),y(s3),z(s3), U[2],V[2],W[2]);
      t4 = DI_Tetra(U[0],V[0],W[0], U[1],V[1],W[1],    x(s1),y(s1),z(s1), x(s4),y(s4),z(s4));
      t5 = DI_Tetra(U[0],V[0],W[0], U[1],V[1],W[1],    x(s4),y(s4),z(s4), U[3],V[3],W[3]);
      t6 = DI_Tetra(U[3],V[3],W[3], U[1],V[1],W[1],    x(s4),y(s4),z(s4), U[2],V[2],W[2]);
      tr1 = DI_Triangle(U[0],V[0],W[0], U[1],V[1],W[1], U[3],V[3],W[3]);
      tr2 = DI_Triangle(U[1],V[1],W[1], U[2],V[2],W[2], U[3],V[3],W[3]);*/

      if(quadT){
        DI_Point midEN2[5]; // intersection between ls and the bissector between the cutting points
        midEN2[0] = quadMidNode(U[1], U[2], pt(s4), e, RPNi);
        midEN2[1] = quadMidNode(U[1], U[0], pt(s2), e, RPNi);
        midEN2[2] = quadMidNode(U[0], U[3], pt(s4), e, RPNi);
        midEN2[3] = quadMidNode(U[2], U[3], pt(s2), e, RPNi);
        midEN2[4] = quadMidNode(U[1], U[3], pt(s2), e, RPNi);
        //quadMidNode(U[1], U[3], (pt(s2)+pt(s3))/2, (pt(s4)+pt(s1))/2, e, RPNi);
        tr2.addQuadEdge(0, &midEN2[0], e, RPNi);
        if(t6.addQuadEdge(5, &midEN2[0], e, RPNi)) {
          t2.addQuadEdge(2, &midEN2[0], e, RPNi);
          t3.addQuadEdge(2, &midEN2[0], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s1), pt(s4), e, RPNi);
          DI_Point quad = middle(mid, midEN2[0], e, RPNi);
          t4.addQuadEdge(5, &quad, e, RPNi);
          t5.addQuadEdge(3, &quad, e, RPNi);
          t6.addQuadEdge(3, &quad, e, RPNi);
          if(t6.addQuadEdge(5, &midEN2[0], e, RPNi)) {
            t2.addQuadEdge(2, &midEN2[0], e, RPNi);
            t3.addQuadEdge(2, &midEN2[0], e, RPNi);
          }
          else printf("unable to add quadratic edge U1U2 to the subtetrahedra cas 4.\n");
        }

        tr1.addQuadEdge(0, &midEN2[1], e, RPNi);
        if(t1.addQuadEdge(1, &midEN2[1], e, RPNi)) {
          t4.addQuadEdge(0, &midEN2[1], e, RPNi);
          t5.addQuadEdge(0, &midEN2[1], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s2), pt(s3), e, RPNi);
          DI_Point quad = middle(mid, midEN2[1], e, RPNi);
          t1.addQuadEdge(3, &quad, e, RPNi);
          t2.addQuadEdge(1, &quad, e, RPNi);
          t3.addQuadEdge(0, &quad, e, RPNi);
          if(t1.addQuadEdge(1, &midEN2[1], e, RPNi)) {
            t4.addQuadEdge(0, &midEN2[1], e, RPNi);
            t5.addQuadEdge(0, &midEN2[1], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U1 to the subtetrahedra cas 4.\n");
        }

        tr1.addQuadEdge(2, &midEN2[2], e, RPNi);
        if(t5.addQuadEdge(2, &midEN2[2], e, RPNi)) {
          t1.addQuadEdge(2, &midEN2[2], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s1), pt(s4), e, RPNi);
          DI_Point quad = middle(mid, midEN2[2], e, RPNi);
          t4.addQuadEdge(2, &quad, e, RPNi);
          t5.addQuadEdge(1, &quad, e, RPNi);
          if(t5.addQuadEdge(2, &midEN2[2], e, RPNi)) {
            t1.addQuadEdge(2, &midEN2[2], e, RPNi);
          }
          else printf("unable to add quadratic edge U0U3 to the subtetrahedra cas 4.\n");
        }

        tr2.addQuadEdge(1, &midEN2[3], e, RPNi);
        if(t2.addQuadEdge(5, &midEN2[3], e, RPNi)) {
          t6.addQuadEdge(2, &midEN2[3], e, RPNi);
        }
        else {
          DI_Point mid = middle(pt(s2), pt(s3), e, RPNi);
          DI_Point quad = middle(mid, midEN2[3], e, RPNi);
          t2.addQuadEdge(4, &quad, e, RPNi);
          t3.addQuadEdge(5, &quad, e, RPNi);
          if(t2.addQuadEdge(5, &midEN2[3], e, RPNi)) {
            t6.addQuadEdge(2, &midEN2[3], e, RPNi);
          }
          else printf("unable to add quadratic edge U2U3 to the subtetrahedra cas 4.\n");
        }

        tr1.addQuadEdge(1, &midEN2[4], e, RPNi);
        tr2.addQuadEdge(2, &midEN2[4], e, RPNi);
        t1.addQuadEdge(4, &midEN2[4], e, RPNi);
        t2.addQuadEdge(0, &midEN2[4], e, RPNi);
        t5.addQuadEdge(5, &midEN2[4], e, RPNi);
        t6.addQuadEdge(0, &midEN2[4], e, RPNi);
      }

      subTetras.push_back(t1);
      subTetras.push_back(t2);
      subTetras.push_back(t3);
      subTetras.push_back(t4);
      subTetras.push_back(t5);
      subTetras.push_back(t6);
      surfTriangles.push_back(tr1);
      surfTriangles.push_back(tr2);
      break;
    }
    default:
      printf("Error : %d edge(s) cut in the tetrahedron (ls : %g %g %g %g)\n",
             COUNT, pt(0).ls(), pt(1).ls(), pt(2).ls(), pt(3).ls());
  }
}

// Split a reference Hexahedron into 6 tetrahedra
void DI_Hexa::splitIntoTetras(std::vector<DI_Tetra> &tetras) const
{
  tetras.push_back(DI_Tetra(pt(0), pt(1), pt(3), pt(4))); // 0134
  tetras.push_back(DI_Tetra(pt(1), pt(4), pt(5), pt(7))); // 1457
  tetras.push_back(DI_Tetra(pt(1), pt(3), pt(4), pt(7))); // 1347
  tetras.push_back(DI_Tetra(pt(2), pt(5), pt(6), pt(7))); // 2567
  tetras.push_back(DI_Tetra(pt(1), pt(2), pt(3), pt(7))); // 1237
  tetras.push_back(DI_Tetra(pt(1), pt(5), pt(2), pt(7))); // 1527
}

// -----------------------------------------------------------------------------
// -------------------INTEGRATION POINTS --------------------------------------
// -----------------------------------------------------------------------------

// return the integration points in the reference line
void DI_Line::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint> &ip) const {
  int N = getNGQLPts(polynomialOrder);
  IntPt* intpt (getGQLPts(polynomialOrder));
  for (int i = 0; i < N; ++i){
    ip.push_back(DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference triangle
void DI_Triangle::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint> &ip) const {
  int pO = polynomialOrder;
  if(pO == 11 || pO == 16 || pO == 18 || pO == 20) pO++;
  if(pO == 15) pO = 17;
  int N = getNGQTPts(pO);
  IntPt* intpt (getGQTPts(pO));
  for (int i = 0; i < N; ++i){
    ip.push_back(DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference triangle
void DI_Quad::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint> &ip) const {
  int N = getNGQQPts(polynomialOrder);
  IntPt* intpt (getGQQPts(polynomialOrder));
  for (int i = 0; i < N; ++i){
    ip.push_back(DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference tetra
void DI_Tetra::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint> &ip) const {
  int pO = polynomialOrder;
  if(pO == 9) pO++;
  int N = getNGQTetPts(pO);
  IntPt* intpt (getGQTetPts(pO));
  for (int i = 0; i < N; ++i){
    ip.push_back(DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// return the integration points in the reference Cube
void DI_Hexa::getRefIntegrationPoints ( const int polynomialOrder , std::vector<DI_IntegrationPoint> &ip) const {
  int N = getNGQHPts(polynomialOrder);
  IntPt* intpt (getGQHPts(polynomialOrder));
  for (int i = 0; i < N; ++i){
    ip.push_back(DI_IntegrationPoint(intpt[i].pt[0], intpt[i].pt[1], intpt[i].pt[2], intpt[i].weight));
  }
}

// -----------------------------------------------------------------------------
// ----------------------------- CUTTING  --------------------------------------
// -----------------------------------------------------------------------------

// cut a line into sublines along the levelset curve
bool DI_Line::cut (const gLevelset &Ls, std::vector<DI_IntegrationPoint> &ip,
                   std::vector<DI_CuttingPoint> &cp, const int polynomialOrder,
                   std::vector<DI_Line> &lines, int recurLevel, std::map<int, double> nodeLs[2]) const
{
  //printf(" "); print();
  std::vector<const gLevelset *> RPN, RPNi;
  Ls.getRPN(RPN);

  DI_Line ll(-1, 0, 0, 1, 0, 0, 2.); //reference line
  //ll.setPolynomialOrder(2);
  std::vector<DI_Line> ll_subLines;
  std::vector<DI_CuttingPoint> ll_cp;

  RecurElement re(&ll);
  bool signChange = re.cut(recurLevel, this, Ls, -1., nodeLs);
  pushSubElements(&re, ll_subLines);

  if(signChange){
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) ll.addLs(Lsi->getTag(), nodeLs);
        else ll.addLs(this, *Lsi);
        int nbSubLn = ll_subLines.size();
        int nbCP = ll_cp.size();
        for(int i = 0; i < nbSubLn; i++) ll_subLines[i].addLs(&ll);
        for(int i = 0; i < nbCP; i++) ll_cp[i].addLs(&ll);

        for(int ln = 0; ln < nbSubLn; ln++){
          DI_Line lnt = ll_subLines[0];
          ll_subLines.erase(ll_subLines.begin());
          lnt.cut(&ll, RPNi, ll_subLines, ll_cp);
        }
      }
      else {
        for(int l = 0; l < (int)ll_subLines.size(); l++)
          ll_subLines[l].chooseLs(Lsi);
        for(int p = 0; p < (int)ll_cp.size(); p++)
          ll_cp[p].chooseLs(Lsi);
      }
    }
  }
  else{
    ll_subLines[0].addLs(this, Ls);
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) ll.addLs(Lsi->getTag(), nodeLs);
        else ll.addLs(this, *Lsi);
      }
    }
  }

  for(int l = 0; l < (int)ll_subLines.size(); l++) {
    ll_subLines[l].computeLsTagDom(&ll, RPN);
    DI_Line ll_subLn = ll_subLines[l];
    mappingEl(&ll_subLn);
    ll_subLn.integrationPoints(polynomialOrder, &ll_subLines[l], &ll, RPN, ip);
    lines.push_back(ll_subLn);
  }
  for(int p = 0; p < (int)ll_cp.size(); p++) {
    if(ll_cp[p].ls() != 0) continue;
    mappingCP(ll_cp[p]);
    bool isIn = false;
    for(int i = (int)cp.size() - 1; i>= 0; i--)
      if(cp[i].equal(ll_cp[p])) {isIn = true; break;}
    if(!isIn) cp.push_back(ll_cp[p]);
  }
  return signChange;
}

// cut a line into sublines along one levelset primitive
void DI_Line::cut(const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
           std::vector<DI_Line> &subLines, std::vector<DI_CuttingPoint> &cp) const
{
  // check if the line is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[2];
  for (int i = 0; i < 2; i++){
    if(fabs(pt(i).ls()) < ZERO_LS_TOL) ze[on++] = i;
    else if (pt(i).ls() > 0.) pos++;
    else neg++;
  }
  if(pos && neg)
    selfSplit(e, RPNi, subLines, cp);
  else {
    for(int i = 0; i < on; i++)
      cp.push_back(DI_CuttingPoint(pt(ze[i])));
    subLines.push_back(*this);
  }
}

// cut a triangle into subtriangles along the levelset curve
bool DI_Triangle::cut (const gLevelset &Ls, std::vector<DI_IntegrationPoint> &ip,
                       std::vector<DI_IntegrationPoint> &ipS, std::vector<DI_CuttingPoint> &cp,
                       const int polynomialOrderQ, const int polynomialOrderTr, const int polynomialOrderL,
                       std::vector<DI_Quad> &subQuads, std::vector<DI_Triangle> &subTriangles,
                       std::vector<DI_Line> &surfLines, int recurLevel, std::map<int, double> nodeLs[3]) const
{
  //printf(" ");print();
  std::vector<const gLevelset *> RPN, RPNi;
  Ls.getRPN(RPN);

  DI_Triangle tt(0, 0, 0, 1, 0, 0, 0, 1, 0, 0.5); //reference triangle
  //tt.setPolynomialOrder(2);
  std::vector<DI_Quad> tt_subQuads;
  std::vector<DI_Triangle> tt_subTriangles;
  std::vector<DI_Line> tt_surfLines;
  std::vector<DI_CuttingPoint> tt_cp;

  RecurElement re(&tt);
  bool signChange = re.cut(recurLevel, this, Ls, -1., nodeLs);
  pushSubElements(&re, tt_subTriangles);

  if(signChange){
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l]; //printf("LS(0,0)=%g LS(1,1)=%g\n",(*Lsi)(0,0,0),(*Lsi)(1,1,0));
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) tt.addLs(Lsi->getTag(), nodeLs);
        else tt.addLs(this, *Lsi);
        int nbSubQ = tt_subQuads.size(), nbSubQ1 = nbSubQ;
        int nbSubTr = tt_subTriangles.size(), nbSubTr1 = nbSubTr;
        int nbSurfLn = tt_surfLines.size(), nbSurfLn1 = nbSurfLn;
        int nbCP = tt_cp.size();
        for(int i = 0; i < nbSubQ; i++) tt_subQuads[i].addLs(&tt);
        for(int i = 0; i < nbSubTr; i++) tt_subTriangles[i].addLs(&tt);
        for(int i = 0; i < nbSurfLn; i++) tt_surfLines[i].addLs(&tt);
        for(int i = 0; i < nbCP; i++) tt_cp[i].addLs(&tt);
        int ze[3], cz = 0;
        for (int i = 0; i < 3; i++) if(fabs(tt.ls(i)) < ZERO_LS_TOL) ze[cz++] = i;

        for(int q = 0; q < nbSubQ; q++) {
          nbSubQ1 = tt_subQuads.size();
          nbSurfLn1 = tt_surfLines.size();
          DI_Quad qt = tt_subQuads[0];
          tt_subQuads.erase(tt_subQuads.begin());
          qt.cut(&tt, RPNi, tt_subQuads, tt_subTriangles, tt_surfLines, tt_cp);
          if((int)tt_surfLines.size() - nbSurfLn1 == 1 && (int)tt_subQuads.size() == nbSubQ1){ // 1 line created on boundary of the quad
            if (cz == 2) { // 1 line created on boundary of the big triangle => check among surfLines
              DI_Line lf (pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if (lf.contain(&surfLines[i])){ // line allready created on another surface => pop the new one
                  tt_surfLines.pop_back(); break;
                }
              }
            }
            else { // 1 line created inside the big triangle => check among tt_surfLines
              if(isLastLnInV(tt_surfLines))
                tt_surfLines.pop_back();
            }
          }
        }
        for(int t = 0; t < nbSubTr; t++){
          nbSubTr1 = tt_subTriangles.size();
          nbSurfLn1 = tt_surfLines.size();
          DI_Triangle trt = tt_subTriangles[0];
          tt_subTriangles.erase(tt_subTriangles.begin());
          trt.cut(&tt, RPNi, tt_subQuads, tt_subTriangles, tt_surfLines, tt_cp);
          if((int)tt_surfLines.size() - nbSurfLn1 == 1  && (int)tt_subTriangles.size() == nbSubTr1) { // 1 line created on boundary of the triangle
            if(cz == 2) { // 1 line created on boundary of the big triangle => check among surfLines
              DI_Line lf(pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if(lf.contain(&surfLines[i])) {
                  tt_surfLines.pop_back(); break;
                }
              }
            }
            else{ // 1 line created inside the big triangle => check among tt_surfLines
              if(isLastLnInV(tt_surfLines))
                tt_surfLines.pop_back();
            }
          }
        }
        for(int ln = 0; ln < nbSurfLn; ln++){
          DI_Line lnt = tt_surfLines[0];
          tt_surfLines.erase(tt_surfLines.begin());
          lnt.cut(&tt, RPNi, tt_surfLines, tt_cp);
        }
      }
      else {
        for(int q = 0; q < (int)tt_subQuads.size(); q++)
          tt_subQuads[q].chooseLs(Lsi);
        for(int t = 0; t < (int)tt_subTriangles.size(); t++)
          tt_subTriangles[t].chooseLs(Lsi);
        for(int l = 0; l < (int)tt_surfLines.size(); l++)
          tt_surfLines[l].chooseLs(Lsi);
        for(int p = 0; p < (int)tt_cp.size(); p++)
          tt_cp[p].chooseLs(Lsi);
      }
    }
  }
  else{
    tt_subTriangles[0].addLs(this, Ls);
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) tt.addLs(Lsi->getTag(), nodeLs);
        else tt.addLs(this, *Lsi);
      }
    }
  }

  //if !changeSign => no cut => clear vectors / triangles.push_back(tt)
  /*if(tt_cp.size() == 1) {
    tt_cp.clear();
  }
  if(tt_cp.size() > 1) {
    bool changeSign = false;
    double sign0 = tt_cp[0].ls();
    for(int i = 1; i < (int)tt_cp.size(); i++)
      if(sign0*tt_cp[i].ls() <= 0) {changeSign = true; break;}
    if(!changeSign) { //print();
      tt_subTriangles.clear();
      tt_subQuads.clear();
      tt_surfLines.clear();
      tt_cp.clear();
      DI_Point vP[3];
      for(int i = 0; i < 3; i++) {
        double ls = Ls(x(i), y(i), z(i));
        vP[i] = DI_Point(tt.x(i), tt.y(i), tt.z(i), ls);
      }
      DI_Triangle trt(vP[0], vP[1], vP[2]); // reference triangle
      tt_subTriangles.push_back(trt);
    }
  }*/

  for(int q = 0; q < (int)tt_subQuads.size(); q++) {
    tt_subQuads[q].computeLsTagDom(&tt, RPN);
    DI_Quad tt_subQ = tt_subQuads[q];
    mappingEl(&tt_subQ);
    tt_subQ.integrationPoints(polynomialOrderQ, &tt_subQuads[q], &tt, RPN, ip);
    subQuads.push_back(tt_subQ);
  }
  for(int t = 0; t < (int)tt_subTriangles.size(); t++) {
    tt_subTriangles[t].computeLsTagDom(&tt, RPN);
    DI_Triangle tt_subTr = tt_subTriangles[t];
    mappingEl(&tt_subTr);
    tt_subTr.integrationPoints(polynomialOrderTr, &tt_subTriangles[t], &tt, RPN, ip);
    subTriangles.push_back(tt_subTr);
  }
  for(int l = 0; l < (int)tt_surfLines.size(); l++) {
    tt_surfLines[l].computeLsTagBound(tt_subQuads, tt_subTriangles);
    if(tt_surfLines[l].lsTag() == -1) continue;
    DI_Line tt_surfLn = tt_surfLines[l];
    mappingEl(&tt_surfLn);
    tt_surfLn.integrationPoints(polynomialOrderL, &tt_surfLines[l], &tt, RPN, ipS);
    surfLines.push_back(tt_surfLn);
  }
  for(int p = 0; p < (int)tt_cp.size(); p++) {
    if(tt_cp[p].ls() != 0) continue;
    mappingCP(tt_cp[p]);
    bool isIn = false;
    for(int i = (int)cp.size() - 1; i>= 0; i--)
      if(cp[i].equal(tt_cp[p])) {isIn = true; break;}
    if(!isIn) cp.push_back(tt_cp[p]);
  }
  return signChange;
}

// cut a triangle into subtriangles along one levelset primitive
void DI_Triangle::cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                    std::vector<DI_Quad> &subQuads, std::vector<DI_Triangle> &subTriangles,
                    std::vector<DI_Line> &surfLines, std::vector<DI_CuttingPoint> &cp) const
{
  // check if the triangle is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[3];
  for (int i = 0; i < 3; i++){
    if(fabs(pt(i).ls()) < ZERO_LS_TOL) ze[on++] = i;
    else if (pt(i).ls() > 0.) pos++;
    else neg++;
  }
  if(pos && neg)
    selfSplit(e, RPNi, subQuads, subTriangles, surfLines, cp);
  else {
    if(on == 2){ // the level set is zero on an edge of the triangle
      surfLines.push_back(DI_Line(pt(ze[0]), pt(ze[1]), RPNi.back()->getTag()));
      // add the line twice if the edge belongs to 2 triangles => remove it later!
    }
    for(int i = 0; i < on; i++)
      cp.push_back(DI_CuttingPoint(pt(ze[i])));
    subTriangles.push_back(*this);
  }
}

// cut a quadrangle into subtriangles along the levelset curve
bool DI_Quad::cut (const gLevelset &Ls, std::vector<DI_IntegrationPoint> &ip,
                   std::vector<DI_IntegrationPoint> &ipS, std::vector<DI_CuttingPoint> &cp,
                   const int polynomialOrderQ, const int polynomialOrderTr, const int polynomialOrderL,
                   std::vector<DI_Quad> &subQuads, std::vector<DI_Triangle> &subTriangles,
                   std::vector<DI_Line> &surfLines, int recurLevel, std::map<int, double> nodeLs[4]) const
{
  printf(" "); printls();
  std::vector<const gLevelset *> RPN, RPNi;
  Ls.getRPN(RPN);

  DI_Quad qq(-1, -1, 0, 1, -1, 0, 1, 1, 0, -1, 1, 0, 4.); // reference quad
  //qq.setPolynomialOrder(2);
  std::vector<DI_Quad> qq_subQuads;
  std::vector<DI_Triangle> qq_subTriangles;
  std::vector<DI_Line> qq_surfLines;
  std::vector<DI_CuttingPoint> qq_cp;

  RecurElement re(&qq);
  bool signChange = re.cut(recurLevel, this, Ls, -1., nodeLs);
  pushSubElements(&re, qq_subQuads);

  if(signChange) {
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) qq.addLs(Lsi->getTag(), nodeLs);
        else qq.addLs(this, *Lsi);
        int nbSubQ = qq_subQuads.size(), nbSubQ1 = nbSubQ;
        int nbSubTr = qq_subTriangles.size(), nbSubTr1 = nbSubTr;
        int nbSurfLn = qq_surfLines.size(), nbSurfLn1 = nbSurfLn;
        int nbCP = qq_cp.size();
        for(int i = 0; i < nbSubQ; i++) qq_subQuads[i].addLs(&qq);
        for(int i = 0; i < nbSubTr; i++) qq_subTriangles[i].addLs(&qq);
        for(int i = 0; i < nbSurfLn; i++) qq_surfLines[i].addLs(&qq);
        for(int i = 0; i < nbCP; i++) qq_cp[i].addLs(&qq);
        int pos = 0, neg = 0, ze[2], cz = 0;
        for (int i = 0; i < 4; i++){
          if(fabs(qq.ls(i)) < ZERO_LS_TOL) ze[cz++] = i;
          else if (qq.ls(i) > 0.) pos++;
          else neg++;
        }

        for(int q = 0; q < nbSubQ; q++) {
          nbSubQ1 = qq_subQuads.size();
          nbSurfLn1 = qq_surfLines.size();
          DI_Quad qt = qq_subQuads[0];
          qq_subQuads.erase(qq_subQuads.begin());
          qt.cut(&qq, RPNi, qq_subQuads, qq_subTriangles, qq_surfLines, qq_cp);
          if((int)qq_surfLines.size() - nbSurfLn1 == 1 && (int)qq_subQuads.size() == nbSubQ1){ // 1 line created on boundary of the quad
            if (cz == 2 && !(pos && neg)) { // 1 line created on boundary of the big quad => check among surfLines
              DI_Line lf (pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if (lf.contain(&surfLines[i])){ // line allready created on another surface => pop the new one
                  qq_surfLines.pop_back(); break;
                }
              }
            }
            else { // 1 line created inside the big quad => check among qq_surfLines
              if(isLastLnInV(qq_surfLines))
                qq_surfLines.pop_back();
            }
          }
        }
        for(int t = 0; t < nbSubTr; t++){
          nbSubTr1 = qq_subTriangles.size();
          nbSurfLn1 = qq_surfLines.size();
          DI_Triangle trt = qq_subTriangles[0];
          qq_subTriangles.erase(qq_subTriangles.begin());
          trt.cut(&qq, RPNi, qq_subQuads, qq_subTriangles, qq_surfLines, qq_cp);
          if((int)qq_surfLines.size() - nbSurfLn1 == 1  && (int)qq_subTriangles.size() == nbSubTr1) { // 1 line created on boundary of the triangle
            if(cz == 2 && !(pos && neg)) { // 1 line created on boundary of the big quad => check among surfLines
              DI_Line lf(pt(ze[0]), pt(ze[1]));
              for(int i = (int)surfLines.size() - 1; i >= 0; i--){
                if(lf.contain(&surfLines[i])) {
                  qq_surfLines.pop_back(); break;
                }
              }
            }
            else{ // 1 line created inside the big quad => check among qq_surfLines
              if(isLastLnInV(qq_surfLines))
                qq_surfLines.pop_back();
            }
          }
        }
        for(int ln = 0; ln < nbSurfLn; ln++){
          DI_Line lnt = qq_surfLines[0];
          qq_surfLines.erase(qq_surfLines.begin());
          lnt.cut(&qq, RPNi, qq_surfLines, qq_cp);
        }
      }
      else {
        for(int q = 0; q < (int)qq_subQuads.size(); q++)
          qq_subQuads[q].chooseLs(Lsi);
        for(int t = 0; t < (int)qq_subTriangles.size(); t++)
          qq_subTriangles[t].chooseLs(Lsi);
        for(int l = 0; l < (int)qq_surfLines.size(); l++)
          qq_surfLines[l].chooseLs(Lsi);
        for(int p = 0; p < (int)qq_cp.size(); p++)
          qq_cp[p].chooseLs(Lsi);
      }
    }
  }
  else {
    qq_subQuads[0].addLs(this, Ls);
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) qq.addLs(Lsi->getTag(), nodeLs);
        else qq.addLs(this, *Lsi);
      }
    }
  }

  /*//if !changeSign => clear vectors / quads.push_back(qq)
  if(qq_cp.size() > 1) {
    bool changeSign = false;
    double sign0 = qq_cp[0].ls();
    for(int i = 1; i < (int)qq_cp.size(); i++)
      if(sign0 * qq_cp[i].ls() <= 0) {changeSign = true; break;}
    if(!changeSign) {
      qq_subTriangles.clear();
      qq_subQuads.clear();
      qq_surfLines.clear();
      qq_cp.clear();
      DI_Point vP[4];
      for(int i = 0; i < 4; i++) {
        double ls = Ls(x(i), y(i), z(i));
        vP[i] = DI_Point(qq.x(i), qq.y(i), qq.z(i), ls);
      }
      DI_Quad qt(vP[0], vP[1], vP[2], vP[3]); // reference quad
      qq_subQuads.push_back(qt);
    }
  }*/

  for(int q = 0; q < (int)qq_subQuads.size(); q++) {
    qq_subQuads[q].computeLsTagDom(&qq, RPN);
    DI_Quad qq_subQ = qq_subQuads[q];
    mappingEl(&qq_subQ);
    qq_subQ.integrationPoints(polynomialOrderQ, &qq_subQuads[q], &qq, RPN, ip);
    subQuads.push_back(qq_subQ);
  }
  for(int t = 0; t < (int)qq_subTriangles.size(); t++) {
    qq_subTriangles[t].computeLsTagDom(&qq, RPN);
    DI_Triangle qq_subTr = qq_subTriangles[t];
    mappingEl(&qq_subTr);  //qq_subTr.printls();
    qq_subTr.integrationPoints(polynomialOrderTr, &qq_subTriangles[t], &qq, RPN, ip);
    subTriangles.push_back(qq_subTr);
  }
  for(int l = 0; l < (int)qq_surfLines.size(); l++) {
    qq_surfLines[l].computeLsTagBound(qq_subQuads, qq_subTriangles);
    if(qq_surfLines[l].lsTag() == -1) continue;  //FIXME
    DI_Line qq_surfLn = qq_surfLines[l];
    mappingEl(&qq_surfLn);
    qq_surfLn.integrationPoints(polynomialOrderL, &qq_surfLines[l], &qq, RPN, ipS);
    surfLines.push_back(qq_surfLn);
  }
  for(int p = 0; p < (int)qq_cp.size(); p++) {
    if(qq_cp[p].ls() != 0) continue;
    mappingCP(qq_cp[p]);
    bool isIn = false;
    for(int i = (int)cp.size() - 1; i >= 0; i--)
      if(cp[i].equal(qq_cp[p])) {isIn = true; break;}
    if(!isIn) cp.push_back(qq_cp[p]);
  }
  return signChange;
}

// cut a quadrangle into subtriangles along the levelset curve
void DI_Quad::cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                std::vector<DI_Quad> &subQuads, std::vector<DI_Triangle> &subTriangles,
                std::vector<DI_Line> &surfLines, std::vector<DI_CuttingPoint> &cp) const
{
  // check if the quadrangle is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[4];
  for (int i = 0; i < 4; i++){
    if(fabs(pt(i).ls()) < ZERO_LS_TOL) ze[on++] = i;
    else if (pt(i).ls() > 0.) pos++;
    else neg++;
  }
  if (pos && neg) {
    std::vector<DI_Triangle> triangles;
    splitIntoTriangles (triangles); // Split the quad into 2 sub triangles
    int nl0 = surfLines.size(), nt1, nl1, nt2, nl2;
    for (int t = 0; t < (int)triangles.size(); t++) {
      nt1 = subTriangles.size(); nl1 = surfLines.size();
      triangles[t].selfSplit(e, RPNi, subQuads, subTriangles, surfLines, cp);
      nt2 = subTriangles.size(); nl2 = surfLines.size();
      if((nt2 - nt1) == 1 && (nl2 - nl1) == 1){ // only 1 line created on an edge of a triangle => check if it was not yet created
        if(isLastLnInV(surfLines, nl0)) {surfLines.pop_back(); nl2--;}
      }
    }
  }
  else {
    if(on == 2){ // the level set is zero on an edge of the quad
      surfLines.push_back(DI_Line(pt(ze[0]), pt(ze[1]), RPNi.back()->getTag()));
      // we add the line twice if the edge belongs to 2 quads => remove it later!
    }
    for(int i = 0; i < on; i++)
      cp.push_back(DI_CuttingPoint(pt(ze[i])));
    subQuads.push_back(*this);
  }
}

// cut a tetrahedron into subtetrahedra along the levelset surface
bool DI_Tetra::cut (const gLevelset &Ls, std::vector<DI_IntegrationPoint> &ip,
                    std::vector<DI_IntegrationPoint> &ipS, std::vector<DI_CuttingPoint> &cp,
                    const int polynomialOrderT, const int polynomialOrderQ, const int polynomialOrderTr,
                    std::vector<DI_Tetra> &subTetras, std::vector<DI_Quad> &surfQuads,
                    std::vector<DI_Triangle> &surfTriangles, int recurLevel, std::map<int, double> nodeLs[4]) const
{
  //printf(" ");print();
  std::vector<const gLevelset *> RPN, RPNi;
  Ls.getRPN(RPN);

  DI_Tetra tt(0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1./6.); // reference tetra
  //tt.setPolynomialOrder(2);
  std::vector<DI_Hexa> tt_subHexas;
  std::vector<DI_Tetra> tt_subTetras;
  std::vector<DI_Quad> tt_surfQuads;
  std::vector<DI_Triangle> tt_surfTriangles;
  std::vector<DI_Line> tt_surfLines;  // not used ...
  std::vector<DI_CuttingPoint> tt_cp;
  std::vector<DI_QualError> QError;

  RecurElement re(&tt);
  bool signChange = re.cut(recurLevel, this, Ls, -1., nodeLs);
  pushSubElements(&re, tt_subTetras);

  if(signChange) {
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) tt.addLs(Lsi->getTag(), nodeLs);
        else tt.addLs(this, *Lsi);
        int nbSubT = tt_subTetras.size(), nbSubT1 = nbSubT;
        int nbSurfQ = tt_surfQuads.size();
        int nbSurfTr = tt_surfTriangles.size(), nbSurfTr1 = nbSurfTr;
        int nbCP = tt_cp.size();
        for(int i = 0; i < nbSubT; i++) tt_subTetras[i].addLs(&tt);
        for(int i = 0; i < nbSurfQ; i++) tt_surfQuads[i].addLs(&tt);
        for(int i = 0; i < nbSurfTr; i++) tt_surfTriangles[i].addLs(&tt);
        for(int i = 0; i < nbCP; i++) tt_cp[i].addLs(&tt);
        int ze[3], cz = 0;
        for (int i = 0; i < 4; i++) if(fabs(tt.ls(i)) < ZERO_LS_TOL) ze[cz++] = i;

        for(int t = 0; t < nbSubT; t++) {
          nbSurfTr1 = tt_surfTriangles.size();
          nbSubT1 = tt_subTetras.size();
          DI_Tetra tet = tt_subTetras[0];
          tt_subTetras.erase(tt_subTetras.begin());
          tet.cut(&tt, RPNi, tt_subTetras, tt_surfQuads, tt_surfTriangles, tt_cp, QError);
          if((int)tt_surfTriangles.size() - nbSurfTr1 == 1 && (int)tt_subTetras.size() == nbSubT1) { // 1 triangle created on surface of the subtetra
            // check among the tt_surfTriangles
            if(isLastTrInV(tt_surfTriangles))
              tt_surfTriangles.pop_back();
            else if(cz == 3) { // 1 triangle created on surface of the reference tet => check among surfTriangles
              DI_Triangle tf(pt(ze[0]), pt(ze[1]), pt(ze[2]));
              for(int i = (int)surfTriangles.size() - 1; i >= 0; i--){
                if(tf.contain(&surfTriangles[i])) {
                  tt_surfTriangles.pop_back(); break;
                }
              }
            }
          }
        }
        for(int q = 0; q < nbSurfQ; q++) {
          DI_Quad qt = tt_surfQuads[0];
          tt_surfQuads.erase(tt_surfQuads.begin());
          qt.cut(&tt, RPNi, tt_surfQuads, tt_surfTriangles, tt_surfLines, tt_cp);
        }
        for(int t = 0; t < nbSurfTr; t++){
          DI_Triangle trt = tt_surfTriangles[0];
          tt_surfTriangles.erase(tt_surfTriangles.begin());
          trt.cut(&tt, RPNi, tt_surfQuads, tt_surfTriangles, tt_surfLines, tt_cp);
        }
      }
      else {
        for(int t = 0; t < (int)tt_subTetras.size(); t++)
          tt_subTetras[t].chooseLs(Lsi);
        for(int q = 0; q < (int)tt_surfQuads.size(); q++)
          tt_surfQuads[q].chooseLs(Lsi);
        for(int t = 0; t < (int)tt_surfTriangles.size(); t++)
          tt_surfTriangles[t].chooseLs(Lsi);
        for(int p = 0; p < (int)tt_cp.size(); p++)
          tt_cp[p].chooseLs(Lsi);
      }
    }
  }
  else {
    tt_subTetras[0].addLs(this, Ls);
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) tt.addLs(Lsi->getTag(), nodeLs);
        else tt.addLs(this, *Lsi);
      }
    }
  }

  /*//if !changeSign => clear vectors / tetras.push_back(tt)
  if(tt_cp.size() > 1) {
    bool changeSign = false;
    double sign0 = tt_cp[0].ls();
    for(int i = 1; i < (int)tt_cp.size(); i++)
      if(sign0 * tt_cp[i].ls() <= 0) {changeSign = true; break;}
    if(!changeSign) {
      tt_subTetras.clear();
      tt_surfQuads.clear();
      tt_surfTriangles.clear();
      tt_cp.clear();
      QError.clear();
      DI_Point vP[4];
      for(int i = 0; i < 4; i++) {
        double ls = Ls(x(i), y(i), z(i));
        vP[i] = DI_Point(tt.x(i), tt.y(i), tt.z(i), ls);
      }
      DI_Tetra tet(vP[0], vP[1], vP[2], vP[3]); // reference tetra
      tt_subTetras.push_back(tet);
    }
  }*/

  for(int i = 0; i < (int)QError.size(); i++)
    QError[i].print(this);

  for(int t = 0; t < (int)tt_subTetras.size(); t++) {
    tt_subTetras[t].computeLsTagDom(&tt, RPN);
    DI_Tetra tt_subT = tt_subTetras[t];
    mappingEl(&tt_subT);
    tt_subT.integrationPoints(polynomialOrderT, &tt_subTetras[t], &tt, RPN, ip);
    subTetras.push_back(tt_subT);
  }
  for(int q = 0; q < (int)tt_surfQuads.size(); q++) {
    tt_surfQuads[q].computeLsTagBound(tt_subHexas, tt_subTetras);
    if(tt_surfQuads[q].lsTag() == -1) continue;
    DI_Quad tt_surfQ = tt_surfQuads[q];
    mappingEl(&tt_surfQ);
    tt_surfQ.integrationPoints(polynomialOrderQ, &tt_surfQuads[q], &tt, RPN, ipS);
    surfQuads.push_back(tt_surfQ);
  }
  for(int t = 0; t < (int)tt_surfTriangles.size(); t++) {
    tt_surfTriangles[t].computeLsTagBound(tt_subHexas, tt_subTetras);
    if(tt_surfTriangles[t].lsTag() == -1) continue;
    DI_Triangle tt_surfTr = tt_surfTriangles[t];
    mappingEl(&tt_surfTriangles[t]);
    tt_surfTriangles[t].integrationPoints(polynomialOrderTr, &tt_surfTr, &tt, RPN, ipS);
    surfTriangles.push_back(tt_surfTriangles[t]);
  }
  for(int p = 0; p < (int)tt_cp.size(); p++) {
    if(tt_cp[p].ls() != 0) continue;
    mappingCP(tt_cp[p]);
    bool isIn = false;
    for(int i = (int)cp.size() - 1; i >= 0; i--)
      if(cp[i].equal(tt_cp[p])) {isIn = true; break;}
    if(!isIn) cp.push_back(tt_cp[p]);
  }
  return signChange;
}

// cut a tetrahedron into subtetrahedra along the levelset surface
void DI_Tetra::cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                 std::vector<DI_Tetra> &subTetras, std::vector<DI_Quad> &surfQuads,
                 std::vector<DI_Triangle> &surfTriangles, std::vector<DI_CuttingPoint> &cp,
                 std::vector<DI_QualError> &QError) const
{
  // check if the tetra is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[4];
  for (int i = 0; i < 4; i++){
    if(fabs(pt(i).ls()) < ZERO_LS_TOL) ze[on++] = i;
    else if (pt(i).ls() > 0.) pos++;
    else neg++;
  }
  if (pos && neg)
    selfSplit(e, RPNi, subTetras, surfTriangles, cp, QError);
  else{
    if(on == 3){ // the level set is zero on a face of the tetra
      surfTriangles.push_back(DI_Triangle(pt(ze[0]), pt(ze[1]), pt(ze[2]), RPNi.back()->getTag())); // add the triangle twice if the face belongs to 2 tetras => remove it later!
    }
    for(int i = 0; i < on; i++)
      cp.push_back(DI_CuttingPoint(pt(ze[i])));
    subTetras.push_back(*this); // add the tetra to subTetras if it is not cut
  }
}

// cut a hex into subtetras along the levelset surface
bool DI_Hexa::cut (const gLevelset &Ls, std::vector<DI_IntegrationPoint> &ip,
                   std::vector<DI_IntegrationPoint> &ipS, std::vector<DI_CuttingPoint> &cp,
                   const int polynomialOrderH, const int polynomialOrderT,
                   const int polynomialOrderQ, const int polynomialOrderTr,
                   std::vector<DI_Hexa> &subHexas, std::vector<DI_Tetra> &subTetras,
                   std::vector<DI_Quad> &surfQuads, std::vector<DI_Triangle> &surfTriangles,
                   std::vector<DI_Line> &frontLines, int recurLevel, std::map<int, double> nodeLs[8]) const
{
  printf(" "); print();

  std::vector<const gLevelset *> RPN, RPNi;
  Ls.getRPN(RPN);

  DI_Hexa hh(-1, -1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, 1, 8.); // reference hexa
  std::vector<DI_Hexa> hh_subHexas;
  std::vector<DI_Tetra> hh_subTetras;
  std::vector<DI_Quad> hh_surfQuads;
  std::vector<DI_Triangle> hh_surfTriangles;
  std::vector<DI_Line> hh_frontLines;
  std::vector<DI_CuttingPoint> hh_cp;
  std::vector<DI_QualError> QError;

  RecurElement re(&hh);
  bool signChange = re.cut(recurLevel, this, Ls, -1., nodeLs);
  pushSubElements(&re, hh_subHexas);

  if(signChange){
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) hh.addLs(Lsi->getTag(), nodeLs);
        else hh.addLs(this, *Lsi);
        int nbSubH = hh_subHexas.size();
        int nbSubT = hh_subTetras.size(), nbSubT1 = nbSubT;
        int nbSurfQ = hh_surfQuads.size(), nbSurfQ1 = nbSurfQ;
        int nbSurfTr = hh_surfTriangles.size(), nbSurfTr1 = nbSurfTr;
        int nbFrontLn = hh_frontLines.size();
        int nbCP = hh_cp.size();
        for(int i = 0; i < nbSubH; i++) hh_subHexas[i].addLs(&hh);
        for(int i = 0; i < nbSubT; i++) hh_subTetras[i].addLs(&hh);
        for(int i = 0; i < nbSurfQ; i++) hh_surfQuads[i].addLs(&hh);
        for(int i = 0; i < nbSurfTr; i++) hh_surfTriangles[i].addLs(&hh);
        for(int i = 0; i < nbFrontLn; i++) hh_frontLines[i].addLs(&hh);
        for(int i = 0; i < nbCP; i++) hh_cp[i].addLs(&hh);
        int pos = 0, neg = 0, ze[4], cz = 0;
        for (int i = 0; i < 8; i++){
          if(fabs(hh.ls(i)) < ZERO_LS_TOL) ze[cz++] = i;
          else if (hh.ls(i) > 0.) pos++;
          else neg++;
        }

        for(int h = 0; h < nbSubH; h++) {
          nbSurfQ1 = hh_surfQuads.size();
          DI_Hexa ht = hh_subHexas[0];
          hh_subHexas.erase(hh_subHexas.begin());
          ht.cut(&hh, RPNi, hh_subHexas, hh_subTetras, hh_surfQuads, hh_surfTriangles, hh_cp, QError);
          if((int)hh_surfQuads.size() > nbSurfQ1){ // 1 quad created on surface of the subHexa
            if(isLastQInV(hh_surfQuads))
              hh_surfQuads.pop_back();
            else if (cz == 4) {
              if(!ordered4Nodes(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3])))
                swap(ze[2], ze[3]);
              DI_Quad qf(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]));
              for(int i = (int)surfQuads.size() - 1; i >= 0; i--){
                if (qf.contain(&surfQuads[i])){
                  hh_surfQuads.pop_back(); break;
                }
              }
              for(int i = (int)surfTriangles.size() - 1; i >= 0; i--){
                if (qf.contain(&surfTriangles[i])) {
                  hh_surfQuads.pop_back(); break;
                }
              }
            }
          }
        }
        for(int t = 0; t < nbSubT; t++) {
          nbSurfTr1 = hh_surfTriangles.size();
          nbSubT1 = hh_subTetras.size();
          DI_Tetra tet = hh_subTetras[0];
          hh_subTetras.erase(hh_subTetras.begin());
          tet.cut(&hh, RPNi, hh_subTetras, hh_surfQuads, hh_surfTriangles, hh_cp, QError);
          if((int)hh_surfTriangles.size() - nbSurfTr1 == 1 && (int)hh_subTetras.size() == nbSubT1) { // 1 triangle created on surface of the subtetra
            // check among hh_surfTriangles
            if(isLastTrInV(hh_surfTriangles))
              hh_surfTriangles.pop_back();
            else if (cz == 4 && !(pos && neg)){ // 1 triangle created on surface of the hex => check among surfTriangles
              if(!ordered4Nodes(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3])))
                swap(ze[2], ze[3]);
              DI_Quad qt(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]));
              for(int i = (int)surfTriangles.size() - 1; i >= 0; i--){
                if(qt.contain(&surfTriangles[i])) {
                  hh_surfTriangles.pop_back(); break;
                }
              }
            }
            else { // 1 triangle created inside the hex and not in hh_surfTriangles
              // check among the quads with quality error
              for(int i = 0; i < (int)QError.size(); i++){
                if(isInQE(hh_surfTriangles[nbSurfTr1], QError[i])) {
                  hh_surfTriangles.pop_back();
                  break;
                }
              }
            }
          }
        }
        for(int q = 0; q < nbSurfQ; q++) {
          DI_Quad qt = hh_surfQuads[0];
          hh_surfQuads.erase(hh_surfQuads.begin());
          qt.cut(&hh, RPNi, hh_surfQuads, hh_surfTriangles, hh_frontLines, hh_cp);
        }
        for(int t = 0; t < nbSurfTr; t++){
          DI_Triangle trt = hh_surfTriangles[0];
          hh_surfTriangles.erase(hh_surfTriangles.begin());
          trt.cut(&hh, RPNi, hh_surfQuads, hh_surfTriangles, hh_frontLines, hh_cp);
        }
        for(int l = 0; l < nbFrontLn; l++){
          DI_Line lnt = hh_frontLines[0];
          hh_frontLines.erase(hh_frontLines.begin());
          lnt.cut(&hh, RPNi, hh_frontLines, hh_cp);
        }
      }
      else {
        for(int h = 0; h < (int)hh_subHexas.size(); h++)
          hh_subHexas[h].chooseLs(Lsi);
        for(int t = 0; t < (int)hh_subTetras.size(); t++)
          hh_subTetras[t].chooseLs(Lsi);
        for(int q = 0; q < (int)hh_surfQuads.size(); q++)
          hh_surfQuads[q].chooseLs(Lsi);
        for(int t = 0; t < (int)hh_surfTriangles.size(); t++)
          hh_surfTriangles[t].chooseLs(Lsi);
        for(int l = 0; l < (int)hh_frontLines.size(); l++)
          hh_frontLines[l].chooseLs(Lsi);
        for(int p = 0; p < (int)hh_cp.size(); p++)
          hh_cp[p].chooseLs(Lsi);
      }
    //printf("Lsi=%d sizeLs=%d nbH=%d nbT=%d nbQ=%d nbTr=%d sizeLs(hh_cp)=%d\n",Lsi->type(),(hh_subHexas.size()>0)?hh_subHexas[0].sizeLs():hh_subTetras[0].sizeLs(), hh_subHexas.size(),hh_subTetras.size(),hh_surfQuads.size(),hh_surfTriangles.size(),(hh_cp.size() > 0)?hh_cp[0].sizeLs():0);
    }
  }
  else {
    hh_subHexas[0].addLs(this, Ls);
    for(int l = 0; l < (int)RPN.size(); l++) {
      const gLevelset *Lsi = RPN[l];
      RPNi.push_back(Lsi);
      if(Lsi->isPrimitive()) {
        if(nodeLs && nodeLs[0].count(Lsi->getTag())) hh.addLs(Lsi->getTag(), nodeLs);
        else hh.addLs(this, *Lsi);
      }
    }
  }

  /*//if the sign does not change and !=0 in the hexa => returns only a hexa
  if(hh_cp.size() > 1) {
    bool changeSign = false;
    double sign0 = hh_cp[0].ls();
    for(int i = 1; i < (int)hh_cp.size(); i++)
      if(sign0*hh_cp[i].ls() <= 0)
        {changeSign = true; break;}
    if(!changeSign) {
      hh_subHexas.clear();
      hh_subTetras.clear();
      hh_surfQuads.clear();
      hh_surfTriangles.clear();
      hh_frontLines.clear();
      hh_cp.clear();
      QError.clear();
      DI_Point vP[8];
      for(int i = 0; i < 8; i++) {
        double ls = Ls(x(i), y(i), z(i));
        vP[i] = DI_Point(hh.x(i), hh.y(i), hh.z(i), ls);
      }
      DI_Hexa hex(vP[0], vP[1], vP[2], vP[3], vP[4], vP[5], vP[6], vP[7]); // reference hexa
      hh_subHexas.push_back(hex);
    }
  }*/

  for(int i = 0; i < (int)QError.size(); i++)
    QError[i].print(this);

  for(int h = 0; h < (int)hh_subHexas.size(); h++) {
    hh_subHexas[h].computeLsTagDom(&hh, RPN);
    DI_Hexa hh_subH = hh_subHexas[h];
    mappingEl(&hh_subH);
    hh_subH.integrationPoints(polynomialOrderH, &hh_subHexas[h], &hh, RPN, ip);
    subHexas.push_back(hh_subH);
  }
  for(int t = 0; t < (int)hh_subTetras.size(); t++) {
    hh_subTetras[t].computeLsTagDom(&hh, RPN);
    DI_Tetra hh_subT = hh_subTetras[t];
    mappingEl(&hh_subT);
    hh_subT.integrationPoints(polynomialOrderT, &hh_subTetras[t], &hh, RPN, ip);
    subTetras.push_back(hh_subT);
  }
  for(int q = 0; q < (int)hh_surfQuads.size(); q++) {
    hh_surfQuads[q].computeLsTagBound(hh_subHexas, hh_subTetras);
    if(hh_surfQuads[q].lsTag() == -1) continue;
    DI_Quad hh_surfQ = hh_surfQuads[q];
    mappingEl(&hh_surfQ);
    hh_surfQ.integrationPoints(polynomialOrderQ, &hh_surfQuads[q], &hh, RPN, ipS);
    surfQuads.push_back(hh_surfQ);
  }
  for(int t = 0; t < (int)hh_surfTriangles.size(); t++) {
    hh_surfTriangles[t].computeLsTagBound(hh_subHexas, hh_subTetras);
    if(hh_surfTriangles[t].lsTag() == -1) continue;
    DI_Triangle hh_surfTr = hh_surfTriangles[t];
    mappingEl(&hh_surfTr);
    hh_surfTr.integrationPoints(polynomialOrderTr, &hh_surfTriangles[t], &hh, RPN, ipS);
    surfTriangles.push_back(hh_surfTr);
  }
  for(int l = 0; l < (int)hh_frontLines.size(); l++) {
    hh_frontLines[l].computeLsTagBound(hh_surfQuads, hh_surfTriangles);
    if(hh_frontLines[l].lsTag() == -1) continue;
    DI_Line hh_frontLn = hh_frontLines[l];
    mappingEl(&hh_frontLn);                      //tt_surfLn.printls();
    //hh_frontLn.integrationPoints(polynomialOrderL, &tt_surfLines[l], &tt, RPN, ipS);
    frontLines.push_back(hh_frontLn);
  }
  for(int p = 0; p < (int)hh_cp.size(); p++) {
    if(hh_cp[p].ls() != 0) continue; // returns only the cutting points with ls==0
    mappingCP(hh_cp[p]);
    bool isIn = false;
    for(int i = (int)cp.size() - 1; i >= 0; i--)
      if(cp[i].equal(hh_cp[p])) {isIn = true; break;}
    if(!isIn) cp.push_back(hh_cp[p]);
  }
  return signChange;
}

// cut a hex into subtetras along the levelset surface
void DI_Hexa::cut (const DI_Element *e, const std::vector<const gLevelset *> &RPNi,
                   std::vector<DI_Hexa> &Hexas, std::vector<DI_Tetra> &subTetras,
                   std::vector<DI_Quad> &surfQuads, std::vector<DI_Triangle> &surfTriangles,
                   std::vector<DI_CuttingPoint> &cp, std::vector<DI_QualError> &QError) const
{
  // check if the hex is cut by the level set
  int on = 0, pos = 0, neg = 0, ze[8];
  for (int i = 0; i < 8; i++){
    if(fabs(pt(i).ls()) < ZERO_LS_TOL) ze[on++] = i;
    else if (pt(i).ls() > 0.) pos++;
    else neg++;
  }
  if (pos && neg) {
    std::vector<DI_Tetra> tetras;
    // Split the quad into sub tetras
    splitIntoTetras (tetras);
    // each of the sub tetras is split again into sub tetras with respect to the levelset
    int nt0 = surfTriangles.size(), nT1, nt1, nT2, nt2;
    for (int t = 0; t < (int)tetras.size(); t++) {
      nT1 = subTetras.size(); nt1 = surfTriangles.size();
      tetras[t].selfSplit(e, RPNi, subTetras, surfTriangles, cp, QError);
      nT2 = subTetras.size(); nt2 = surfTriangles.size();
      if((nT2 - nT1) == 1 && (nt2 - nt1) == 1){ // only 1 triangle created on a face of a tetra => check if it was not yet created
        if(isLastTrInV(surfTriangles, nt0)) {surfTriangles.pop_back(); nt2--;}
      }
    }
  }

  else{
    if(on == 4){ // the level set is zero on a face of the hex
      // assert the nodes are in the same plane
      if(!isPlanar(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]))) {
        printf("Error : The 4 nodes with zero levelset are not planar!\n"); return;}
      // order the 4 nodes
      if(!ordered4Nodes(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]))) swap(ze[2], ze[3]);
      // add the quad twice if the face belongs to 2 hexas => remove it later!
      if(ze[0] == 2) surfQuads.push_back(DI_Quad(pt(ze[1]), pt(ze[2]), pt(ze[3]), pt(ze[0]), RPNi.back()->getTag()));
      // to assert that the quad will be split into triangles in the same manner as the hexa into tetras.
      else surfQuads.push_back(DI_Quad(pt(ze[0]), pt(ze[1]), pt(ze[2]), pt(ze[3]), RPNi.back()->getTag()));
    }
    for(int i = 0; i < on; i++)
      cp.push_back(DI_CuttingPoint(pt(ze[i])));
    Hexas.push_back(*this);
  }
}

#endif
