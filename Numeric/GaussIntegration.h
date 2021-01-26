// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GAUSS_INTEGRATION_H
#define GAUSS_INTEGRATION_H

template <class scalar> class fullVector;
template <class scalar> class fullMatrix;

struct IntPt {
  double pt[3];
  double weight;
};

int GaussLegendreTri(int n1, int n2, IntPt *pts);
int GaussLegendreTet(int n1, int n2, int n3, IntPt *pts);

int getNGQLPts(int order);
IntPt *getGQLPts(int order);

int getNGQTPts(int order);
IntPt *getGQTPts(int order);

int getNGQQPts(int order);
IntPt *getGQQPts(int order);

int getNGQTetPts(int order);
IntPt *getGQTetPts(int order);

int getNGQPriPts(int order);
IntPt *getGQPriPts(int order);

int getNGQPyrPts(int order);
IntPt *getGQPyrPts(int order);

int getNGQHPts(int order);
IntPt *getGQHPts(int order);

class gaussIntegration {
public:
  static void get(int elementType, int order, fullMatrix<double> &pts,
                  fullVector<double> &weights);
  static void getTriangle(int order, fullMatrix<double> &pts,
                          fullVector<double> &weights);
  static void getLine(int order, fullMatrix<double> &pts,
                      fullVector<double> &weights);
  static void getQuad(int order, fullMatrix<double> &pts,
                      fullVector<double> &weights);
  static void getTetrahedron(int order, fullMatrix<double> &pts,
                             fullVector<double> &weights);
  static void getHexahedron(int order, fullMatrix<double> &pts,
                            fullVector<double> &weights);
  static void getPrism(int order, fullMatrix<double> &pts,
                       fullVector<double> &weights);
  static void getPyramid(int order, fullMatrix<double> &pts,
                         fullVector<double> &weights);
};

#endif
