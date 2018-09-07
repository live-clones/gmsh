// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <limits>
#include "qualityMeasuresJacobian.h"
#include "MElement.h"
#include "BasisFactory.h"
#include "bezierBasis.h"
#include "JacobianBasis.h"
#include "Numeric.h"

// For debugging
#include <sstream>
#include <iomanip>
#include "pointsGenerators.h"
#include "OS.h"

static const double cTri = 2 / std::sqrt(3);
static const double cTet = std::sqrt(2);
static const double cPyr = 4 * std::sqrt(2);

static inline void _computeCoeffLengthVectors(const fullMatrix<double> &mat,
                                              fullMatrix<double> &coeff,
                                              int type, int numCoeff = -1)
{
  int sz1 = numCoeff > -1 ? numCoeff : mat.size1();

  switch(type) {
  case TYPE_QUA: coeff.resize(sz1, 2); break;
  case TYPE_TRI: coeff.resize(sz1, 3); break;
  case TYPE_HEX: coeff.resize(sz1, 3); break;
  case TYPE_PRI: coeff.resize(sz1, 4); break;
  case TYPE_TET: coeff.resize(sz1, 6); break;
  case TYPE_PYR: coeff.resize(sz1, 6); break;
  default:
    Msg::Error("Unkown type for IGE computation");
    coeff.resize(0, 0);
    return;
  }

  if(type != TYPE_PYR) {
    for(int i = 0; i < sz1; i++) {
      coeff(i, 0) = std::sqrt(pow_int(mat(i, 0), 2) + pow_int(mat(i, 1), 2) +
                              pow_int(mat(i, 2), 2));
      coeff(i, 1) = std::sqrt(pow_int(mat(i, 3), 2) + pow_int(mat(i, 4), 2) +
                              pow_int(mat(i, 5), 2));
    }
    if(type == TYPE_TRI) {
      for(int i = 0; i < sz1; i++) {
        coeff(i, 2) = std::sqrt(pow_int(mat(i, 3) - mat(i, 0), 2) +
                                pow_int(mat(i, 4) - mat(i, 1), 2) +
                                pow_int(mat(i, 5) - mat(i, 2), 2));
      }
    }
    else if(type != TYPE_QUA) { // if 3D
      for(int i = 0; i < sz1; i++) {
        coeff(i, 2) = std::sqrt(pow_int(mat(i, 6), 2) + pow_int(mat(i, 7), 2) +
                                pow_int(mat(i, 8), 2));
      }
    }
    if(type == TYPE_TET || type == TYPE_PRI) {
      for(int i = 0; i < sz1; i++) {
        coeff(i, 3) = std::sqrt(pow_int(mat(i, 3) - mat(i, 0), 2) +
                                pow_int(mat(i, 4) - mat(i, 1), 2) +
                                pow_int(mat(i, 5) - mat(i, 2), 2));
      }
    }
    if(type == TYPE_TET) {
      for(int i = 0; i < sz1; i++) {
        coeff(i, 4) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0), 2) +
                                pow_int(mat(i, 7) - mat(i, 1), 2) +
                                pow_int(mat(i, 8) - mat(i, 2), 2));
        coeff(i, 5) = std::sqrt(pow_int(mat(i, 6) - mat(i, 3), 2) +
                                pow_int(mat(i, 7) - mat(i, 4), 2) +
                                pow_int(mat(i, 8) - mat(i, 5), 2));
      }
    }
  }
  else {
    for(int i = 0; i < sz1; i++) {
      coeff(i, 0) =
        std::sqrt(pow_int(2 * mat(i, 0), 2) + pow_int(2 * mat(i, 1), 2) +
                  pow_int(2 * mat(i, 2), 2));
      coeff(i, 1) =
        std::sqrt(pow_int(2 * mat(i, 3), 2) + pow_int(2 * mat(i, 4), 2) +
                  pow_int(2 * mat(i, 5), 2));
      coeff(i, 2) = std::sqrt(pow_int(mat(i, 6) + mat(i, 0) + mat(i, 3), 2) +
                              pow_int(mat(i, 7) + mat(i, 1) + mat(i, 4), 2) +
                              pow_int(mat(i, 8) + mat(i, 2) + mat(i, 5), 2));
      coeff(i, 3) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0) + mat(i, 3), 2) +
                              pow_int(mat(i, 7) - mat(i, 1) + mat(i, 4), 2) +
                              pow_int(mat(i, 8) - mat(i, 2) + mat(i, 5), 2));
      coeff(i, 4) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0) - mat(i, 3), 2) +
                              pow_int(mat(i, 7) - mat(i, 1) - mat(i, 4), 2) +
                              pow_int(mat(i, 8) - mat(i, 2) - mat(i, 5), 2));
      coeff(i, 5) = std::sqrt(pow_int(mat(i, 6) + mat(i, 0) - mat(i, 3), 2) +
                              pow_int(mat(i, 7) + mat(i, 1) - mat(i, 4), 2) +
                              pow_int(mat(i, 8) + mat(i, 2) - mat(i, 5), 2));
    }
  }
}
static inline void computeCoeffLengthVectorsCorner_(const bezierCoeff &mat,
                                                    fullMatrix<double> &coeff,
                                                    int type, int numCorner)
{
  const int &sz1 = numCorner;

  switch(type) {
  case TYPE_QUA: coeff.resize(sz1, 2); break;
  case TYPE_TRI: coeff.resize(sz1, 3); break;
  case TYPE_HEX: coeff.resize(sz1, 3); break;
  case TYPE_PRI: coeff.resize(sz1, 4); break;
  case TYPE_TET: coeff.resize(sz1, 6); break;
  case TYPE_PYR: coeff.resize(sz1, 6); break;
  default:
    Msg::Error("Unkown type for IGE computation");
    coeff.resize(0, 0);
    return;
  }

  if(type != TYPE_PYR) {
    for(int i = 0; i < sz1; i++) {
      int k = mat.getIdxCornerCoeff(i);
      coeff(i, 0) = std::sqrt(pow_int(mat(k, 0), 2) + pow_int(mat(k, 1), 2) +
                              pow_int(mat(k, 2), 2));
      coeff(i, 1) = std::sqrt(pow_int(mat(k, 3), 2) + pow_int(mat(k, 4), 2) +
                              pow_int(mat(k, 5), 2));
    }
    if(type == TYPE_TRI) {
      for(int i = 0; i < sz1; i++) {
        int k = mat.getIdxCornerCoeff(i);
        coeff(i, 2) = std::sqrt(pow_int(mat(k, 3) - mat(k, 0), 2) +
                                pow_int(mat(k, 4) - mat(k, 1), 2) +
                                pow_int(mat(k, 5) - mat(k, 2), 2));
      }
    }
    else if(type != TYPE_QUA) { // if 3D
      for(int i = 0; i < sz1; i++) {
        int k = mat.getIdxCornerCoeff(i);
        coeff(i, 2) = std::sqrt(pow_int(mat(k, 6), 2) + pow_int(mat(k, 7), 2) +
                                pow_int(mat(k, 8), 2));
      }
    }
    if(type == TYPE_TET || type == TYPE_PRI) {
      for(int i = 0; i < sz1; i++) {
        int k = mat.getIdxCornerCoeff(i);
        coeff(i, 3) = std::sqrt(pow_int(mat(k, 3) - mat(k, 0), 2) +
                                pow_int(mat(k, 4) - mat(k, 1), 2) +
                                pow_int(mat(k, 5) - mat(k, 2), 2));
      }
    }
    if(type == TYPE_TET) {
      for(int i = 0; i < sz1; i++) {
        int k = mat.getIdxCornerCoeff(i);
        coeff(i, 4) = std::sqrt(pow_int(mat(k, 6) - mat(k, 0), 2) +
                                pow_int(mat(k, 7) - mat(k, 1), 2) +
                                pow_int(mat(k, 8) - mat(k, 2), 2));
        coeff(i, 5) = std::sqrt(pow_int(mat(k, 6) - mat(k, 3), 2) +
                                pow_int(mat(k, 7) - mat(k, 4), 2) +
                                pow_int(mat(k, 8) - mat(k, 5), 2));
      }
    }
  }
  else {
    for(int i = 0; i < sz1; i++) {
      int k = mat.getIdxCornerCoeff(i);
      coeff(i, 0) =
        std::sqrt(pow_int(2 * mat(k, 0), 2) + pow_int(2 * mat(k, 1), 2) +
                  pow_int(2 * mat(k, 2), 2));
      coeff(i, 1) =
        std::sqrt(pow_int(2 * mat(k, 3), 2) + pow_int(2 * mat(k, 4), 2) +
                  pow_int(2 * mat(k, 5), 2));
      coeff(i, 2) = std::sqrt(pow_int(mat(k, 6) + mat(k, 0) + mat(k, 3), 2) +
                              pow_int(mat(k, 7) + mat(k, 1) + mat(k, 4), 2) +
                              pow_int(mat(k, 8) + mat(k, 2) + mat(k, 5), 2));
      coeff(i, 3) = std::sqrt(pow_int(mat(k, 6) - mat(k, 0) + mat(k, 3), 2) +
                              pow_int(mat(k, 7) - mat(k, 1) + mat(k, 4), 2) +
                              pow_int(mat(k, 8) - mat(k, 2) + mat(k, 5), 2));
      coeff(i, 4) = std::sqrt(pow_int(mat(k, 6) - mat(k, 0) - mat(k, 3), 2) +
                              pow_int(mat(k, 7) - mat(k, 1) - mat(k, 4), 2) +
                              pow_int(mat(k, 8) - mat(k, 2) - mat(k, 5), 2));
      coeff(i, 5) = std::sqrt(pow_int(mat(k, 6) + mat(k, 0) - mat(k, 3), 2) +
                              pow_int(mat(k, 7) + mat(k, 1) - mat(k, 4), 2) +
                              pow_int(mat(k, 8) + mat(k, 2) - mat(k, 5), 2));
    }
  }
}

static inline void computeIGE_(const fullVector<double> &det,
                               const fullMatrix<double> &v,
                               fullVector<double> &ige, int type)
{
  int sz = std::min(det.size(), v.size1());
  ige.resize(sz);

  switch(type) {
  case TYPE_QUA:
    for(int i = 0; i < sz; i++) {
      ige(i) = det(i) / v(i, 0) / v(i, 1);
    }
    break;
  case TYPE_HEX:
    for(int i = 0; i < sz; i++) {
      ige(i) = det(i) / v(i, 0) / v(i, 1) / v(i, 2);
    }
    break;
  case TYPE_TRI:
    for(int i = 0; i < sz; i++) {
      ige(i) = cTri * det(i) *
               (1 / v(i, 0) / v(i, 1) + 1 / v(i, 0) / v(i, 2) +
                1 / v(i, 1) / v(i, 2)) /
               3;
    }
    break;
  case TYPE_PRI:
    for(int i = 0; i < sz; i++) {
      ige(i) =
        cTri * det(i) *
        (1 / v(i, 0) / v(i, 1) / v(i, 2) + 1 / v(i, 0) / v(i, 3) / v(i, 2) +
         1 / v(i, 1) / v(i, 3) / v(i, 2)) /
        3;
    }
    break;
  case TYPE_TET:
    for(int i = 0; i < sz; i++) {
      ige(i) =
        cTet * det(i) *
        (1 / v(i, 0) / v(i, 5) / v(i, 1) + 1 / v(i, 0) / v(i, 5) / v(i, 2) +
         1 / v(i, 0) / v(i, 5) / v(i, 3) + 1 / v(i, 0) / v(i, 5) / v(i, 4) +
         1 / v(i, 1) / v(i, 4) / v(i, 0) + 1 / v(i, 1) / v(i, 4) / v(i, 2) +
         1 / v(i, 1) / v(i, 4) / v(i, 3) + 1 / v(i, 1) / v(i, 4) / v(i, 5) +
         1 / v(i, 2) / v(i, 3) / v(i, 0) + 1 / v(i, 2) / v(i, 3) / v(i, 1) +
         1 / v(i, 2) / v(i, 3) / v(i, 4) + 1 / v(i, 2) / v(i, 3) / v(i, 5)) /
        12;
    }
    break;
  case TYPE_PYR:
    for(int i = 0; i < sz; i++) {
      ige(i) =
        cPyr * det(i) *
        (1 / v(i, 0) / v(i, 1) / v(i, 2) + 1 / v(i, 0) / v(i, 1) / v(i, 3) +
         1 / v(i, 0) / v(i, 1) / v(i, 4) + 1 / v(i, 0) / v(i, 1) / v(i, 5) +
         1 / v(i, 2) / v(i, 3) / v(i, 4) + 1 / v(i, 2) / v(i, 3) / v(i, 5) +
         1 / v(i, 4) / v(i, 5) / v(i, 2) + 1 / v(i, 4) / v(i, 5) / v(i, 3)) /
        8;
    }
    break;
  }
}

namespace jacobianBasedQuality {

  void compare(fullVector<double> &detOld, bezierCoeff *detNew,
               fullMatrix<double> &matOld, bezierCoeff *matNew)
  {
    fullVector<double> detNewOrdered(detNew->getNumCoeff());
    const fullMatrix<double> &expDet = detNew->getBezierBasis()->_exponents;
    const int orderDet = detNew->getPolynomialOrder();
    int k = 0;
    for(int j = 0; j < orderDet + 1; ++j) {
      for(int i = 0; i < orderDet + 1; ++i) {
        int I = 0;
        while(I < expDet.size1() &&
              (expDet(I, 0) - .5 >= i || expDet(I, 0) + .5 <= i ||
               expDet(I, 1) - .5 >= j || expDet(I, 1) + .5 <= j))
          ++I;
        if(I == expDet.size1()) {
          Msg::Error("ARRAGRGRAG");
        }
        detNewOrdered(I) = (*detNew)(k);
        ++k;
      }
    }

    const int dim = matNew->getNumColumns();
    fullMatrix<double> matNewOrdered(matNew->getNumCoeff(), dim);
    const fullMatrix<double> &expMat = matNew->getBezierBasis()->_exponents;
    const int orderMat = matNew->getPolynomialOrder();
    k = 0;
    for(int j = 0; j < orderMat + 1; ++j) {
      for(int i = 0; i < orderMat + 1; ++i) {
        int I = 0;
        while(I < expMat.size1() &&
              (expMat(I, 0) - .5 >= i || expMat(I, 0) + .5 <= i ||
               expMat(I, 1) - .5 >= j || expMat(I, 1) + .5 <= j))
          ++I;
        if(I == expMat.size1()) {
          Msg::Error("ARRAGRGRAG");
        }
        for(int l = 0; l < dim; ++l) {
          matNewOrdered(I, l) = (*matNew)(k, l);
        }
        ++k;
      }
    }

    fullVector<double> detFromMatOld(4);
    for(int i = 0; i < 4; ++i) {
      SVector3 u(matOld(i, 0), matOld(i, 1), matOld(i, 2));
      SVector3 v(matOld(i, 3), matOld(i, 4), matOld(i, 5));
      detFromMatOld(i) = norm(crossprod(u, v));
    }

    fullVector<double> detFromMatNew(4);
    for(int i = 0; i < 4; ++i) {
      SVector3 u(matNewOrdered(i, 0), matNewOrdered(i, 1), matNewOrdered(i, 2));
      SVector3 v(matNewOrdered(i, 3), matNewOrdered(i, 4), matNewOrdered(i, 5));
      detFromMatNew(i) = norm(crossprod(u, v));
    }

    double sumAbsDiffDet = 0;
    double maxAbsDiffDet = 0;
    for(int i = 0; i < detOld.size(); ++i) {
      double d = std::abs(detOld(i) - detNewOrdered(i));
      sumAbsDiffDet += d;
      maxAbsDiffDet = std::max(maxAbsDiffDet, d);
    }

    double sumAbsDiffMat = 0;
    double maxAbsDiffMat = 0;
    for(int i = 0; i < matOld.size1(); ++i) {
      for(int j = 0; j < dim; ++j) {
        double d = std::abs(matOld(i, j) - matNewOrdered(i, j));
        sumAbsDiffMat += d;
        maxAbsDiffMat = std::max(maxAbsDiffMat, d);
      }
    }

    fullVector<double> diffDet(detOld);
    diffDet.axpy(detNewOrdered, -1);
    fullMatrix<double> diffMat(matOld);
    diffMat.axpy(matNewOrdered, -1);

    diffDet.print("diffDet");
    diffMat.print("diffMat");

    detFromMatOld.print("detFromMatOld");
    detFromMatNew.print("detFromMatNew");
    detOld.print("detOld");
    detNewOrdered.print("detNewOrdered");
    //    matOld.print("matOld");
    //    matNewOrdered.print("matNewOrdered");

    std::cout << "sum: " << sumAbsDiffDet << " " << sumAbsDiffMat
              << " max: " << maxAbsDiffDet << " " << maxAbsDiffMat << std::endl;
  }

  void minMaxJacobianDeterminant(MElement *el, double &min, double &max,
                                 const fullMatrix<double> *normals)
  {
    const JacobianBasis *jfs = el->getJacobianFuncSpace();
    if(!jfs) {
      Msg::Error(
        "Jacobian function space not implemented for type of element %d",
        el->getTypeForMSH());
      min = 99;
      max = -99;
      return;
    }

    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);

    fullVector<double> coeffLag(jfs->getNumJacNodes());
    fullVector<double> coeffBez(jfs->getNumJacNodes());
    jfs->getSignedJacobian(nodesXYZ, coeffLag, normals);
    jfs->lag2Bez(coeffLag, coeffBez);

    bezierCoeff::usePools(coeffLag.size(), 0);
    std::vector<_coefData *> domains;
    bezierCoeff *bez =
      new bezierCoeff(FuncSpaceData(el, jfs->getJacOrder()), coeffLag, 0);
    domains.push_back(new _coefDataJac(coeffBez, jfs->getBezier(), 0, bez));

    //  int N = 5e5;
    //  double time = Cpu();

    //  for (int i = 0; i < N; ++i) {
    //    fullVector<double> subCoeff;
    //    jfs->getBezier()->subdivideBezCoeff(coeffBez, subCoeff);
    //  }
    //  double tm1 = Cpu() - time;
    //  std::cout << "time old " << tm1 << " (" << tm1/N << ")" << std::endl;

    //  time = Cpu();
    //  bezierCoeff bez(FuncSpaceData(el, jfs->getJacOrder()), coeffLag, 0);
    //  for (int i = 0; i < N; ++i) {
    //    std::vector<bezierCoeff> vec;
    //    bez.subdivide(vec);
    //  }
    //  double tm2 = Cpu() - time;
    //  std::cout << "time new " << tm2 << " (" << tm2/N << ")" << std::endl;

    _subdivideDomains(domains);

    double min2 = domains[0]->minB2();
    double max2 = domains[0]->maxB2();
    double minL2 = domains[0]->minL2();
    double maxL2 = domains[0]->maxL2();
    min = domains[0]->minB();
    max = domains[0]->maxB();
    domains[0]->deleteBezierCoeff();
    delete domains[0];
    for(std::size_t i = 1; i < domains.size(); ++i) {
      min = std::min(min, domains[i]->minB());
      max = std::max(max, domains[i]->maxB());
      min2 = std::min(min2, domains[i]->minB2());
      max2 = std::max(max2, domains[i]->maxB2());
      minL2 = std::min(minL2, domains[i]->minL2());
      maxL2 = std::max(maxL2, domains[i]->maxL2());
      domains[i]->deleteBezierCoeff();
      delete domains[i];
    }
    //  std::cout << "" << min << " [" << min2 << "," << minL2 << "] " << max <<
    //  " [" << maxL2 << "," << max2 << "] " << std::endl;
  }

  double minIGEMeasure(MElement *el, bool knownValid, bool reversedOk,
                       const fullMatrix<double> *normals)
  {
    //    int oorder = 2;
    //    FuncSpaceData jjacDetSpace;
    //    const bool sserendipFalse = false;
    //    jjacDetSpace = FuncSpaceData(el, oorder, &sserendipFalse);
    //    const bezierBasis *bezBasis =
    //    BasisFactory::getBezierBasis(jjacDetSpace); fullVector<double>
    //    coeffDetBez((oorder+1)*(oorder+1)); coeffDetBez(0) = 1;
    //    fullVector<double> coeffDetLag((oorder+1)*(oorder+1));
    //    bezBasis->matrixBez2Lag.mult(coeffDetBez, coeffDetLag);
    //    bezierCoeff *bezDet = new bezierCoeff(FuncSpaceData(el, oorder),
    //    coeffDetLag, 0);
    ////    for(int i = 0; i < bezDet->getNumCoeff(); ++i) {
    ////      for(int j = 0; j < bezDet->getNumCoeff(); ++j) {
    ////        (*bezDet)(i,j) = 0;
    ////      }
    ////    }
    ////    (*bezDet)(0,0) = 1;
    ////    (*bezDet)(oorder,0) = 1;
    ////    (*bezDet)(oorder*oorder+oorder,0) = 1;
    ////    (*bezDet)(oorder*oorder+2*oorder,0) = 1;
    //    std::vector<bezierCoeff*> v;
    //    bezDet->subdivide(v);
    //
    //    for(int i = 0; i < 4; ++i) {
    //      fullVector<double> a(v[i]->getDataPtr(), v[i]->getNumCoeff());
    //      a.print();
    //    }
    //    return 1;

    bool isReversed = false;
    if(!knownValid) {
      // Computation of the measure should never
      // be performed to invalid elements (for which the measure is 0).
      double jmin, jmax;
      minMaxJacobianDeterminant(el, jmin, jmax, normals);
      if(jmax < 0) {
        if(!reversedOk) return 0;
        isReversed = true;
      }
      else if(jmin <= 0)
        return 0;
    }

    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);

    const JacobianBasis *jacBasis;
    const GradientBasis *gradBasis;

    const int type = el->getType();
    const int order = el->getPolynomialOrder();
    const int jacOrder = order * el->getDim();
    const bool serendipFalse = false;

    FuncSpaceData jacMatSpace, jacDetSpace;

    switch(type) {
    case TYPE_TRI:
      jacMatSpace = FuncSpaceData(el, order - 1, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, jacOrder - 2, &serendipFalse);
      break;
    case TYPE_TET:
      jacMatSpace = FuncSpaceData(el, order - 1, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, jacOrder - 3, &serendipFalse);
      break;
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PRI:
      jacMatSpace = FuncSpaceData(el, order, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, jacOrder, &serendipFalse);
      break;
    case TYPE_PYR:
      jacMatSpace = FuncSpaceData(el, false, order, order - 1, &serendipFalse);
      jacDetSpace =
        FuncSpaceData(el, false, jacOrder, jacOrder - 3, &serendipFalse);
      break;
    default:
      Msg::Error("IGE measure not implemented for type of element %d",
                 el->getType());
      return -1;
    }
    gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

    fullVector<double> coeffDetBez;
    fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
    {
      jacBasis->getSignedJacobian(nodesXYZ, coeffDetLag, normals);
      if(isReversed) coeffDetLag.scale(-1);

      coeffDetBez.resize(jacBasis->getNumJacNodes());
      jacBasis->lag2Bez(coeffDetLag, coeffDetBez);
      //      jacBasis->getBezier()->matrixLag2Bez.print("matrixLag2Bez");
    }

    coeffDetLag.print("coeffDetLag");

    fullVector<double> coeffDetLagOld(jacBasis->getNumJacNodes());
    jacBasis->getBezier()->matrixBez2Lag.mult(coeffDetBez, coeffDetLagOld);

    fullVector<double> coeffDetBezNew(jacBasis->getNumJacNodes());
    fullVector<double> coeffDetLagNew(jacBasis->getNumJacNodes());
    jacBasis->getBezier()->matrixLag2Bez3.mult(coeffDetLag, coeffDetBezNew);
    jacBasis->getBezier()->matrixBez2Lag2.mult(coeffDetBezNew, coeffDetLagNew);

    fullVector<double> diffOld(coeffDetLag);
    fullVector<double> diffNew(coeffDetLag);
    diffOld.axpy(coeffDetLagOld, -1);
    diffNew.axpy(coeffDetLagNew, -1);
    //    diffOld.print("diffOld");
    //    diffNew.print("diffNew");
    fullMatrix<double> coeffMatBez;

    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    {
      int dim = el->getDim();
      gradBasis->getAllGradientsFromNodes(nodesXYZ, coeffMatLag);
      if(dim == 2) coeffMatLag.resize(coeffMatLag.size1(), 6, false);

      coeffMatBez.resize(gradBasis->getNumSamplingPoints(), dim == 2 ? 6 : 9);
      gradBasis->lag2Bez(coeffMatLag, coeffMatBez);
    }

    //    coeffDetLag.print("coeffDetLag");
    //    coeffMatLag.print("coeffMatLag");

    bezierCoeff::usePools(coeffDetLag.size(),
                          coeffMatLag.size1() * coeffMatLag.size2());
    std::vector<_coefData *> domains;
    bezierCoeff *bezDet = new bezierCoeff(
      FuncSpaceData(el, jacBasis->getJacOrder()), coeffDetLag, 0);
    bezierCoeff *bezMat = new bezierCoeff(
      FuncSpaceData(el, gradBasis->getPolynomialOrder()), coeffMatLag, 1);
    compare(coeffDetBez, bezDet, coeffMatBez, bezMat);
    domains.push_back(new _coefDataIGE(
      coeffDetBez, coeffMatBez, jacBasis->getBezier(), gradBasis->getBezier(),
      0, el->getType(), bezDet, bezMat));

    _subdivideDomains(domains);
    //  if (domains.size()/7 > 500) {//fordebug
    //    Msg::Info("S too much subdivision: %d (el %d, type %d, tag %d)",
    //        domains.size()/7, el->getNum(), el->getType(),
    //        el->getTypeForMSH());
    //  }

    return _getMinAndDeleteDomains(domains);
  }

  double minICNMeasure(MElement *el, bool knownValid, bool reversedOk,
                       const fullMatrix<double> *normals)
  {
    bool isReversed = false;
    if(!knownValid) {
      // Computation of the measure should never
      // be performed to invalid elements (for which the measure is 0).
      double jmin, jmax;
      minMaxJacobianDeterminant(el, jmin, jmax, normals);
      if(jmax < 0) {
        if(!reversedOk) return 0;
        isReversed = true;
      }
      else if(jmin <= 0)
        return 0;
    }

    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);

    const JacobianBasis *jacBasis;
    const GradientBasis *gradBasis;

    const int type = el->getType();
    const int order = el->getPolynomialOrder();
    const int jacOrder = order * el->getDim();
    const bool serendipFalse = false;

    FuncSpaceData jacMatSpace, jacDetSpace;

    switch(type) {
    case TYPE_TRI:
      jacMatSpace = FuncSpaceData(el, order - 1, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, jacOrder - 2, &serendipFalse);
      break;
    case TYPE_TET:
      jacMatSpace = FuncSpaceData(el, order - 1, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, jacOrder - 3, &serendipFalse);
      break;
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PRI:
      jacMatSpace = FuncSpaceData(el, order, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, jacOrder, &serendipFalse);
      break;
    case TYPE_PYR:
      jacMatSpace = FuncSpaceData(el, false, order, order - 1, &serendipFalse);
      jacDetSpace =
        FuncSpaceData(el, false, jacOrder, jacOrder - 3, &serendipFalse);
      break;
    default:
      Msg::Error("ICN not implemented for type of element %d", el->getType());
      return -1;
    }
    gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

    fullVector<double> coeffDetBez;
    {
      fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
      jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag, normals);

      coeffDetBez.resize(jacBasis->getNumJacNodes());
      jacBasis->lag2Bez(coeffDetLag, coeffDetBez);

      if(isReversed) coeffDetBez.scale(-1);
    }

    fullMatrix<double> coeffMatBez;
    {
      fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
      gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, coeffMatLag);

      coeffMatBez.resize(gradBasis->getNumSamplingPoints(), 9);
      gradBasis->lag2Bez(coeffMatLag, coeffMatBez);
      if(el->getDim() == 2) coeffMatBez.resize(coeffMatBez.size1(), 6, false);
    }

    std::vector<_coefData *> domains;
    domains.push_back(new _coefDataICN(coeffDetBez, coeffMatBez,
                                       jacBasis->getBezier(),
                                       gradBasis->getBezier(), 0));

    _subdivideDomains(domains);
    //  if (domains.size()/7 > 500) {//fordebug
    //    Msg::Info("I too much subdivision: %d (el %d, type %d, tag %d)",
    //               domains.size()/7, el->getNum(), el->getType(),
    //               el->getTypeForMSH());
    //  }

    return _getMinAndDeleteDomains(domains);
  }

  void sampleIGEMeasure(MElement *el, int deg, double &min, double &max)
  {
    fullVector<double> ige;
    sampleIGEMeasure(el, deg, ige);

    min = std::numeric_limits<double>::infinity();
    max = -min;
    for(int i = 0; i < ige.size(); ++i) {
      min = std::min(min, ige(i));
      max = std::max(max, ige(i));
    }
  }

  void sampleJacobian(MElement *el, int deg, fullVector<double> &jac,
                      const fullMatrix<double> *normals)
  {
    FuncSpaceData sampleSpace = FuncSpaceData(el, deg);
    const JacobianBasis *jacBasis = BasisFactory::getJacobianBasis(sampleSpace);

    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);

    jac.resize(jacBasis->getNumJacNodes());
    jacBasis->getSignedJacobian(nodesXYZ, jac, normals);
  }

  void sampleIGEMeasure(MElement *el, int deg, fullVector<double> &ige)
  {
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);

    const bool serendipFalse = false;
    FuncSpaceData jacMatSpace, jacDetSpace;

    const int type = el->getType();
    switch(type) {
    case TYPE_TRI:
    case TYPE_TET:
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PRI:
      jacMatSpace = FuncSpaceData(el, deg, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, deg, &serendipFalse);
      break;
    case TYPE_PYR:
      jacMatSpace = FuncSpaceData(el, true, deg - 1, 1, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, true, deg - 1, 1, &serendipFalse);
      break;
    default:
      Msg::Error("IGE not implemented for type of element %d", el->getType());
      return;
    }

    const GradientBasis *gradBasis =
      BasisFactory::getGradientBasis(jacMatSpace);
    const JacobianBasis *jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

    fullVector<double> coeffDeterminant(jacBasis->getNumJacNodes());
    jacBasis->getSignedJacobian(nodesXYZ, coeffDeterminant);

    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    gradBasis->getAllGradientsFromNodes(nodesXYZ, coeffMatLag);
    if(el->getDim() == 2) coeffMatLag.resize(coeffMatLag.size1(), 6, false);

    fullMatrix<double> v;
    _computeCoeffLengthVectors(coeffMatLag, v, type);

    computeIGE_(coeffDeterminant, v, ige, type);
  }

  double minSampledICNMeasure(MElement *el, int deg) // fordebug
  {
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);

    const JacobianBasis *jacBasis;
    const GradientBasis *gradBasis;

    const int type = el->getType();
    //  const int order = el->getPolynomialOrder();
    //  const int jacOrder = order * el->getDim();
    const bool serendipFalse = false;

    FuncSpaceData jacMatSpace, jacDetSpace;

    switch(type) {
    case TYPE_TRI:
    case TYPE_TET:
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PRI:
      jacMatSpace = FuncSpaceData(el, deg, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, deg, &serendipFalse);
      break;
    case TYPE_PYR:
      //    jacMatSpace = FuncSpaceData(el, false, order, order-1,
      //    &serendipFalse); jacDetSpace = FuncSpaceData(el, false, jacOrder,
      //    jacOrder-3, &serendipFalse);
      break;
    default:
      Msg::Error("ICN not implemented for type of element %d", el->getType());
      return -1;
    }
    gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

    fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
    jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag);

    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, coeffMatLag);

    double min = std::numeric_limits<double>::infinity();
    for(int i = 0; i < coeffDetLag.size(); ++i) {
      double frobNorm = 0;
      if(el->getDim() == 2) {
        for(int k = 0; k < 6; ++k)
          frobNorm += coeffMatLag(i, k) * coeffMatLag(i, k);
        min = std::min(min, 2 * coeffDetLag(i) / frobNorm);
      }
      else if(el->getDim() == 3) {
        for(int k = 0; k < 9; ++k)
          frobNorm += coeffMatLag(i, k) * coeffMatLag(i, k);
        min = std::min(min, 3 * std::pow(coeffDetLag(i), 2 / 3.) / frobNorm);
      }
    }

    return min;
  }

  double minSampledIGEMeasure(MElement *el, int deg) // fordebug
  {
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);

    const JacobianBasis *jacBasis;
    const GradientBasis *gradBasis;

    const int type = el->getType();
    //  const int order = el->getPolynomialOrder();
    //  const int jacOrder = order * el->getDim();
    const bool serendipFalse = false;

    FuncSpaceData jacMatSpace, jacDetSpace;

    switch(type) {
    case TYPE_TRI:
    case TYPE_TET:
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PRI:
      jacMatSpace = FuncSpaceData(el, deg, &serendipFalse);
      jacDetSpace = FuncSpaceData(el, deg, &serendipFalse);
      break;
    case TYPE_PYR:
      //    jacMatSpace = FuncSpaceData(el, false, order, order-1,
      //    &serendipFalse); jacDetSpace = FuncSpaceData(el, false, jacOrder,
      //    jacOrder-3, &serendipFalse);
      break;
    default:
      Msg::Error("ICN not implemented for type of element %d", el->getType());
      return -1;
    }
    gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

    fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
    jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag);

    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, coeffMatLag);

    double min = std::numeric_limits<double>::infinity();
    for(int i = 0; i < coeffDetLag.size(); ++i) {
      if(el->getDim() == 2) {
        double v[2] = {0, 0};
        for(int k = 0; k < 2; ++k) {
          for(int l = k * 3; l < k * 3 + 3; ++l)
            v[k] += coeffMatLag(i, l) * coeffMatLag(i, l);
        }
        min = std::min(min, coeffDetLag(i) / v[0] / v[1]);
      }
      else if(el->getDim() == 3) {
        double v[3] = {0, 0, 0};
        for(int k = 0; k < 3; ++k) {
          for(int l = k * 3; l < k * 3 + 3; ++l)
            v[k] += coeffMatLag(i, l) * coeffMatLag(i, l);
        }
        min = std::min(min, coeffDetLag(i) / std::sqrt(v[0] * v[1] * v[2]));
      }
    }

    return min;
  }

  // Virtual class _coefData
  bool _lessMinB::operator()(_coefData *cd1, _coefData *cd2) const
  {
    return cd1->minB() > cd2->minB();
  }

  bool _lessMaxB::operator()(_coefData *cd1, _coefData *cd2) const
  {
    return cd1->maxB() < cd2->maxB();
  }

  // Jacobian determinant (for validity of all elements)
  _coefDataJac::_coefDataJac(fullVector<double> &v, const bezierBasis *bfs,
                               int depth, const bezierCoeff *coeffs2)
    : _coefData(depth), _coeffs(v.getDataPtr(), v.size()), _bfs(bfs),
      _coeffs2(coeffs2)
  {
    if(!v.getOwnData()) {
      Msg::Fatal("Cannot create an instance of _coefDataJac from a "
                 "fullVector that does not own its data.");
      return;
    }
    // _coeffs reuses the data of v, this avoid to allocate a new array and to
    // copy data that are not used outside of this object.
    // It remains to swap ownership:
    v.setOwnData(false);
    const_cast<fullVector<double> &>(_coeffs).setOwnData(true);

    _minL = _maxL = v(0);
    int i = 1;
    for(; i < bfs->getNumLagCoeff(); i++) {
      _minL = std::min(_minL, v(i));
      _maxL = std::max(_maxL, v(i));
    }
    _minB = _minL;
    _maxB = _maxL;
    for(; i < v.size(); i++) {
      _minB = std::min(_minB, v(i));
      _maxB = std::max(_maxB, v(i));
    }
    _minL2 = _maxL2 = _coeffs2->getCornerCoeff(0);
    for(int i = 1; i < _coeffs2->getNumCornerCoeff(); i++) {
      _minL2 = std::min(_minL2, _coeffs2->getCornerCoeff(i));
      _maxL2 = std::max(_maxL2, _coeffs2->getCornerCoeff(i));
    }
    _minB2 = _maxB2 = (*_coeffs2)(0);
    for(; i < v.size(); i++) {
      _minB2 = std::min(_minB2, (*_coeffs2)(i));
      _maxB2 = std::max(_maxB2, (*_coeffs2)(i));
    }
  }

  bool _coefDataJac::boundsOk(double minL, double maxL) const
  {
    double tol = std::max(std::abs(minL), std::abs(maxL)) * 1e-3;
    return (minL <= 0 || _minB > 0) && minL - _minB < tol && _maxB - maxL < tol;
  }

  void _coefDataJac::getSubCoeff(std::vector<_coefData *> &v) const
  {
    v.clear();
    v.reserve(_bfs->getNumDivision());
    fullVector<double> subCoeff;
    _bfs->subdivideBezCoeff(_coeffs, subCoeff);

    std::vector<bezierCoeff *> sub;
    _coeffs2->subdivide(sub);

    int sz = _coeffs.size();
    for(int i = 0; i < _bfs->getNumDivision(); i++) {
      fullVector<double> coeff(sz);
      coeff.copy(subCoeff, i * sz, sz, 0);
      _coefDataJac *newData =
        new _coefDataJac(coeff, _bfs, _depth + 1, sub[i]);
      v.push_back(newData);
    }
  }

  // IGE measure (Inverse Gradient Error)
  _coefDataIGE::_coefDataIGE(fullVector<double> &det, fullMatrix<double> &mat,
                               const bezierBasis *bfsDet,
                               const bezierBasis *bfsMat, int depth, int type,
                               const bezierCoeff *det2, const bezierCoeff *mat2)
    : _coefData(depth), _coeffsJacDet(det.getDataPtr(), det.size()),
      _coeffsJacMat(mat.getDataPtr(), mat.size1(), mat.size2()),
      _bfsDet(bfsDet), _bfsMat(bfsMat), _type(type), _coeffDet2(det2),
      _coeffMat2(mat2)
  {
    if(!det.getOwnData() || !mat.getOwnData()) {
      Msg::Error("Cannot create an instance of _coefDataIGE from a "
                 "fullVector or a fullMatrix that does not own its data.");
      return;
    }
    // _coeffsJacDet and _coeffsJacMat reuse data, this avoid to allocate new
    // arrays and to copy data that are not used outside of this object.
    // It remains to swap ownerships:
    det.setOwnData(false);
    mat.setOwnData(false);
    const_cast<fullVector<double> &>(_coeffsJacDet).setOwnData(true);
    const_cast<fullMatrix<double> &>(_coeffsJacMat).setOwnData(true);

    _computeAtCorner(_minL, _maxL, _minL2, _maxL2);

    _minB = 0;
    if(boundsOk(_minL, _maxL))
      return;
    else {
      _minB = _computeLowerBound();
      _minB2 = _computeLowerBound2();
    }
    // computation of _maxB not implemented for now
  }

  bool _coefDataIGE::boundsOk(double minL, double maxL) const
  {
    static const double tolmin = 1e-3;
    static const double tolmax = 1e-2;
    const double tol = tolmin + (tolmax - tolmin) * std::max(_minB, .0);
    return minL - _minB < tol;
  }

  void _coefDataIGE::getSubCoeff(std::vector<_coefData *> &v) const
  {
    v.clear();
    v.reserve(_bfsDet->getNumDivision());
    fullVector<double> subCoeffD;
    fullMatrix<double> subCoeffM;
    _bfsDet->subdivideBezCoeff(_coeffsJacDet, subCoeffD);
    _bfsMat->subdivideBezCoeff(_coeffsJacMat, subCoeffM);

    std::vector<bezierCoeff *> subD;
    std::vector<bezierCoeff *> subM;
    _coeffDet2->subdivide(subD);
    _coeffMat2->subdivide(subM);

    int szD = _coeffsJacDet.size();
    int szM1 = _coeffsJacMat.size1();
    int szM2 = _coeffsJacMat.size2();
    for(int i = 0; i < _bfsDet->getNumDivision(); i++) {
      std::cout << "subdiv " << i << std::endl;
      fullVector<double> coeffD(szD);
      fullMatrix<double> coeffM(szM1, szM2);
      coeffD.copy(subCoeffD, i * szD, szD, 0);
      coeffM.copy(subCoeffM, i * szM1, szM1, 0, szM2, 0, 0);
      _coefDataIGE *newData;
      compare(coeffD, subD[i], coeffM, subM[i]);
      newData = new _coefDataIGE(coeffD, coeffM, _bfsDet, _bfsMat, _depth + 1,
                                  _type, subD[i], subM[i]);
      v.push_back(newData);
    }
  }

  void _coefDataIGE::_computeAtCorner(double &min, double &max, double &min2,
                                       double &max2) const
  {
    fullMatrix<double> v, m(_bfsDet->getNumLagCoeff(), _coeffsJacMat.size2());
    _computeCoeffLengthVectors(_coeffsJacMat, v, _type,
                               _bfsDet->getNumLagCoeff());

    fullVector<double> ige;
    computeIGE_(_coeffsJacDet, v, ige, _type);

    min = std::numeric_limits<double>::infinity();
    max = -min;
    fullVector<double> det(ige.size());
    for(int i = 0; i < ige.size(); ++i) {
      min = std::min(min, ige(i));
      max = std::max(max, ige(i));
      det(i) = _coeffsJacDet(i);
      for(int j = 0; j < _coeffsJacMat.size2(); ++j) {
        m(i, j) = _coeffsJacMat(i, j);
      }
    }
    //    _coeffsJacDet.print("_coeffsJacDet");
    //    m.print("m");
    //    det.print("det");
    //    v.print("v");
    ige.print("ige");

    fullMatrix<double> v2,
      m2(_coeffMat2->getNumCornerCoeff(), _coeffMat2->getNumColumns());
    computeCoeffLengthVectorsCorner_(*_coeffMat2, v2, _type,
                                     _bfsDet->getNumLagCoeff());
    fullVector<double> ige2;
    fullVector<double> d2(_coeffDet2->getNumCornerCoeff());
    for(int i = 0; i < _coeffDet2->getNumCornerCoeff(); ++i) {
      d2(i) = _coeffDet2->getCornerCoeff(i);
      for(int j = 0; j < _coeffMat2->getNumColumns(); ++j) {
        m2(i, j) = _coeffMat2->getCornerCoeff(i, j);
      }
    }
    computeIGE_(d2, v2, ige2, _type);

    fullVector<double> det2(_coeffDet2->getNumCoeff());
    for(int k = 0; k < det2.size(); ++k) {
      det2(k) = (*_coeffDet2)(k);
    }

    //    det2.print("_coeffDet2");
    //    m2.print("m2");
    //    d2.print("d2");
    //    v2.print("v2");
    ige2.print("ige2");
    std::cout << std::endl;

    min2 = std::numeric_limits<double>::infinity();
    max2 = -min2;
    for(int i = 0; i < ige2.size(); ++i) {
      min2 = std::min(min2, ige2(i));
      max2 = std::max(max2, ige2(i));
    }
  }

  double _coefDataIGE::_computeLowerBound() const
  {
    // Speedup: If one coeff _coeffsJacDet is negative, without bounding
    // J^2/(a^2+b^2), we would get with certainty a negative lower bound.
    // Returning 0.
    for(int i = 0; i < _coeffsJacDet.size(); ++i) {
      if(_coeffsJacDet(i) < 0) {
        return 0;
      }
    }

    fullMatrix<double> v;
    _computeCoeffLengthVectors(_coeffsJacMat, v, _type);

    fullVector<double> prox[6];
    for(int i = 0; i < v.size2(); ++i) {
      prox[i].setAsProxy(v, i);
    }

    bezierBasisRaiser *raiser = _bfsMat->getRaiser();
    fullVector<double> coeffDenominator;
    double result = 0;

    switch(_type) {
    case TYPE_QUA:
      raiser->computeCoeff(prox[0], prox[1], coeffDenominator);
      return _computeBoundRational(_coeffsJacDet, coeffDenominator, true);

    case TYPE_TRI:
      raiser->computeCoeff(prox[0], prox[1], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff(prox[0], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff(prox[1], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      return cTri * result / 3;

    case TYPE_HEX:
      raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
      return _computeBoundRational(_coeffsJacDet, coeffDenominator, true);

    case TYPE_PRI:
      raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff(prox[0], prox[3], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff(prox[1], prox[3], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      return cTri * result / 3;

    case TYPE_TET: {
      fullVector<double> thirdTerm, coeffNum1, tmp;
      thirdTerm = prox[1];
      thirdTerm.axpy(prox[2]);
      thirdTerm.axpy(prox[3]);
      thirdTerm.axpy(prox[4]);
      raiser->computeCoeff(prox[0], prox[5], thirdTerm, coeffNum1);
      thirdTerm = prox[0];
      thirdTerm.axpy(prox[2]);
      thirdTerm.axpy(prox[3]);
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff(prox[1], prox[4], thirdTerm, tmp);
      coeffNum1.axpy(tmp);
      thirdTerm = prox[0];
      thirdTerm.axpy(prox[1]);
      thirdTerm.axpy(prox[4]);
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff(prox[2], prox[3], thirdTerm, tmp);
      coeffNum1.axpy(tmp);

      fullVector<double> coeffDen1, coeffDen2;
      raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDen1);
      raiser->computeCoeff(prox[3], prox[4], prox[5], coeffDen2);

      fullVector<double> &coeffNumerator = tmp;
      bezierBasisRaiser *raiserBis = _bfsDet->getRaiser();
      raiserBis->computeCoeff(coeffNum1, _coeffsJacDet, coeffNumerator);
      raiserBis->computeCoeff(coeffDen1, coeffDen2, coeffDenominator);

      result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
      return cTet * result / 12;
    }

    case TYPE_PYR: {
      fullVector<double> thirdTerm, coeffNum1, tmp;
      thirdTerm = prox[2];
      thirdTerm.axpy(prox[3]);
      thirdTerm.axpy(prox[4]);
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff(prox[0], prox[1], thirdTerm, coeffNum1);
      thirdTerm = prox[4];
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff(prox[2], prox[3], thirdTerm, tmp);
      coeffNum1.axpy(tmp);
      thirdTerm = prox[2];
      thirdTerm.axpy(prox[3]);
      raiser->computeCoeff(prox[4], prox[5], thirdTerm, tmp);
      coeffNum1.axpy(tmp);

      fullVector<double> coeffDen1, coeffDen2;
      raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDen1);
      raiser->computeCoeff(prox[3], prox[4], prox[5], coeffDen2);

      fullVector<double> &coeffNumerator = tmp;
      bezierBasisRaiser *raiserBis = _bfsDet->getRaiser();
      raiserBis->computeCoeff(coeffNum1, _coeffsJacDet, coeffNumerator);
      raiserBis->computeCoeff(coeffDen1, coeffDen2, coeffDenominator);

      result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
      return cPyr * result / 8;
    }

    default: Msg::Info("Unknown type for IGE (%d)", _type); return -1;
    }
  }

  double _coefDataIGE::_computeLowerBound2() const
  {
    // Speedup: If one coeff _coeffsJacDet is negative, without bounding
    // J^2/(a^2+b^2), we would get with certainty a negative lower bound.
    // Returning 0.
    for(int i = 0; i < _coeffsJacDet.size(); ++i) {
      if(_coeffsJacDet(i) < 0) {
        return 0;
      }
    }

    fullMatrix<double> v;
    const fullMatrix<double> m(
      const_cast<bezierCoeff *>(_coeffMat2)->getDataPtr(),
      _coeffMat2->getNumCoeff(), _coeffMat2->getNumColumns());
    _computeCoeffLengthVectors(m, v, _type);

    fullVector<double> prox[6];
    for(int i = 0; i < v.size2(); ++i) {
      prox[i].setAsProxy(v, i);
    }

    bezierBasisRaiser *raiser = _bfsMat->getRaiser();
    fullVector<double> coeffDenominator;
    double result = 0;

    switch(_type) {
    case TYPE_QUA:
      raiser->computeCoeff2(prox[0], prox[1], coeffDenominator);
      return _computeBoundRational(_coeffsJacDet, coeffDenominator, true);

    case TYPE_TRI:
      raiser->computeCoeff2(prox[0], prox[1], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff2(prox[0], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff2(prox[1], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      return cTri * result / 3;

    case TYPE_HEX:
      raiser->computeCoeff2(prox[0], prox[1], prox[2], coeffDenominator);
      return _computeBoundRational(_coeffsJacDet, coeffDenominator, true);

    case TYPE_PRI:
      raiser->computeCoeff2(prox[0], prox[1], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff2(prox[0], prox[3], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      raiser->computeCoeff2(prox[1], prox[3], prox[2], coeffDenominator);
      result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
      return cTri * result / 3;

    case TYPE_TET: {
      fullVector<double> thirdTerm, coeffNum1, tmp;
      thirdTerm = prox[1];
      thirdTerm.axpy(prox[2]);
      thirdTerm.axpy(prox[3]);
      thirdTerm.axpy(prox[4]);
      raiser->computeCoeff2(prox[0], prox[5], thirdTerm, coeffNum1);
      thirdTerm = prox[0];
      thirdTerm.axpy(prox[2]);
      thirdTerm.axpy(prox[3]);
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff2(prox[1], prox[4], thirdTerm, tmp);
      coeffNum1.axpy(tmp);
      thirdTerm = prox[0];
      thirdTerm.axpy(prox[1]);
      thirdTerm.axpy(prox[4]);
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff2(prox[2], prox[3], thirdTerm, tmp);
      coeffNum1.axpy(tmp);

      fullVector<double> coeffDen1, coeffDen2;
      raiser->computeCoeff2(prox[0], prox[1], prox[2], coeffDen1);
      raiser->computeCoeff2(prox[3], prox[4], prox[5], coeffDen2);

      fullVector<double> &coeffNumerator = tmp;
      bezierBasisRaiser *raiserBis = _bfsDet->getRaiser();
      raiserBis->computeCoeff2(coeffNum1, _coeffsJacDet, coeffNumerator);
      raiserBis->computeCoeff2(coeffDen1, coeffDen2, coeffDenominator);

      result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
      return cTet * result / 12;
    }

    case TYPE_PYR: {
      fullVector<double> thirdTerm, coeffNum1, tmp;
      thirdTerm = prox[2];
      thirdTerm.axpy(prox[3]);
      thirdTerm.axpy(prox[4]);
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff2(prox[0], prox[1], thirdTerm, coeffNum1);
      thirdTerm = prox[4];
      thirdTerm.axpy(prox[5]);
      raiser->computeCoeff2(prox[2], prox[3], thirdTerm, tmp);
      coeffNum1.axpy(tmp);
      thirdTerm = prox[2];
      thirdTerm.axpy(prox[3]);
      raiser->computeCoeff2(prox[4], prox[5], thirdTerm, tmp);
      coeffNum1.axpy(tmp);

      fullVector<double> coeffDen1, coeffDen2;
      raiser->computeCoeff2(prox[0], prox[1], prox[2], coeffDen1);
      raiser->computeCoeff2(prox[3], prox[4], prox[5], coeffDen2);

      fullVector<double> &coeffNumerator = tmp;
      bezierBasisRaiser *raiserBis = _bfsDet->getRaiser();
      raiserBis->computeCoeff2(coeffNum1, _coeffsJacDet, coeffNumerator);
      raiserBis->computeCoeff2(coeffDen1, coeffDen2, coeffDenominator);

      result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
      return cPyr * result / 8;
    }

    default: Msg::Info("Unknown type for IGE (%d)", _type); return -1;
    }
  }

  // ICN measure (Inverse Condition Number)
  _coefDataICN::_coefDataICN(fullVector<double> &det, fullMatrix<double> &mat,
                               const bezierBasis *bfsDet,
                               const bezierBasis *bfsMat, int depth)
    : _coefData(depth), _coeffsJacDet(det.getDataPtr(), det.size()),
      _coeffsJacMat(mat.getDataPtr(), mat.size1(), mat.size2()),
      _bfsDet(bfsDet), _bfsMat(bfsMat)
  {
    if(!det.getOwnData() || !mat.getOwnData()) {
      Msg::Error("Cannot create an instance of _coefDataIGE from a "
                 "fullVector or a fullMatrix that does not own its data.");
      return;
    }
    // _coeffsJacDet and _coeffsMetric reuse data, this avoid to allocate new
    // arrays and to copy data that are not used outside of this object.
    // It remains to swap ownerships:
    det.setOwnData(false);
    mat.setOwnData(false);
    const_cast<fullVector<double> &>(_coeffsJacDet).setOwnData(true);
    const_cast<fullMatrix<double> &>(_coeffsJacMat).setOwnData(true);

    _computeAtCorner(_minL, _maxL);

    _minB = 0;
    if(boundsOk(_minL, _maxL))
      return;
    else
      _minB = _computeLowerBound();
    // _maxB not used for now
  }

  bool _coefDataICN::boundsOk(double minL, double maxL) const
  {
    static const double tolmin = 1e-3;
    static const double tolmax = 1e-2;
    const double tol = tolmin + (tolmax - tolmin) * std::max(_minB, .0);
    return minL - _minB < tol;
  }

  void _coefDataICN::getSubCoeff(std::vector<_coefData *> &v) const
  {
    v.clear();
    v.reserve(_bfsMat->getNumDivision());
    fullMatrix<double> subCoeffM;
    fullVector<double> subCoeffD;
    _bfsMat->subdivideBezCoeff(_coeffsJacMat, subCoeffM);
    _bfsDet->subdivideBezCoeff(_coeffsJacDet, subCoeffD);

    int szD = _coeffsJacDet.size();
    int szM1 = _coeffsJacMat.size1();
    int szM2 = _coeffsJacMat.size2();
    for(int i = 0; i < _bfsMat->getNumDivision(); i++) {
      fullVector<double> coeffD(szD);
      fullMatrix<double> coeffM(szM1, szM2);
      coeffD.copy(subCoeffD, i * szD, szD, 0);
      coeffM.copy(subCoeffM, i * szM1, szM1, 0, szM2, 0, 0);
      _coefDataICN *newData =
        new _coefDataICN(coeffD, coeffM, _bfsDet, _bfsMat, _depth + 1);
      v.push_back(newData);
    }
  }

  void _coefDataICN::_computeAtCorner(double &min, double &max) const
  {
    min = std::numeric_limits<double>::infinity();
    max = -min;

    for(int i = 0; i < _bfsMat->getNumLagCoeff(); i++) {
      double p = 0;
      for(int k = 0; k < _coeffsJacMat.size2(); ++k) {
        p += pow_int(_coeffsJacMat(i, k), 2);
      }
      double qual;
      if(_coeffsJacMat.size2() == 6) // if 2D
        qual = 2 * _coeffsJacDet(i) / p;
      else // 3D
        qual = 3 * std::pow(_coeffsJacDet(i), 2 / 3.) / p;
      min = std::min(min, qual);
      max = std::max(max, qual);
    }
  }

  double _coefDataICN::_computeLowerBound() const
  {
    // Speedup: If one coeff _coeffsJacDet is negative, we would get
    // a negative lower bound. For now, returning 0.
    for(int i = 0; i < _coeffsJacDet.size(); ++i) {
      if(_coeffsJacDet(i) < 0) {
        return 0;
      }
    }

    // 2D element
    if(_coeffsJacMat.size2() == 6) {
      fullVector<double> coeffDenominator;
      {
        bezierBasisRaiser *raiser = _bfsMat->getRaiser();
        fullVector<double> prox;
        for(int k = 0; k < _coeffsJacMat.size2(); ++k) {
          prox.setAsProxy(_coeffsJacMat, k);
          fullVector<double> tmp;
          raiser->computeCoeff(prox, prox, tmp);
          if(k == 0) coeffDenominator.resize(tmp.size());
          coeffDenominator.axpy(tmp, 1);
        }
      }
      return 2 * _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    }

    // 3D element NEW
    fullVector<double> coeffDenominator;
    {
      // P: coefficients of function that bound from above the Frobenius norm of
      // J element of P are automatically set to 0
      fullVector<double> P(_coeffsJacMat.size1());
      for(int i = 0; i < _coeffsJacMat.size1(); ++i) {
        for(int k = 0; k < _coeffsJacMat.size2(); ++k) {
          P(i) += _coeffsJacMat(i, k) * _coeffsJacMat(i, k);
        }
        P(i) = std::sqrt(P(i));
      }
      _bfsMat->getRaiser()->computeCoeff(P, P, P, coeffDenominator);
    }

    const double boundFraction =
      _computeBoundRational(_coeffsJacDet, coeffDenominator, true);

    return 3 * std::pow(boundFraction * boundFraction, 1. / 3);
  }

  // Miscellaneous
  template <typename Comp>
  void _subdivideDomainsMinOrMax(std::vector<_coefData *> &domains,
                                 double &minL, double &maxL)
  {
    std::vector<_coefData *> subs;
    make_heap(domains.begin(), domains.end(), Comp());
    int k = 0;
    const int max_subdivision = 1000;
    while(!domains[0]->boundsOk(minL, maxL) && k++ < max_subdivision) {
      _coefData *cd = domains[0];
      pop_heap(domains.begin(), domains.end(), Comp());
      domains.pop_back();
      cd->getSubCoeff(subs);
      cd->deleteBezierCoeff();
      delete cd;

      for(std::size_t i = 0; i < subs.size(); i++) {
        minL = std::min(minL, subs[i]->minL());
        maxL = std::max(maxL, subs[i]->maxL());
        domains.push_back(subs[i]);
        push_heap(domains.begin(), domains.end(), Comp());
      }
    }
    if(k > max_subdivision) {
      Msg::Error("Max subdivision (%d) (size %d)", max_subdivision,
                 domains.size());
    }
  }

  void _subdivideDomains(std::vector<_coefData *> &domains)
  {
    if(domains.empty()) {
      Msg::Warning("empty vector in Bezier subdivision, nothing to do");
      return;
    }
    double minL = domains[0]->minL();
    double maxL = domains[0]->maxL();
    for(std::size_t i = 1; i < domains.size(); ++i) {
      minL = std::min(minL, domains[i]->minL());
      maxL = std::max(maxL, domains[i]->maxL());
    }

    _subdivideDomainsMinOrMax<_lessMinB>(domains, minL, maxL);
    _subdivideDomainsMinOrMax<_lessMaxB>(domains, minL, maxL);
  }

  double _getMinAndDeleteDomains(std::vector<_coefData *> &domains)
  {
    double minB = domains[0]->minB();
    double minL = domains[0]->minL();
    double minB2 = domains[0]->minB2();
    double minL2 = domains[0]->minL2();
    std::cout << "minB2 " << minB << " " << minL2 << std::endl;
    domains[0]->deleteBezierCoeff();
    delete domains[0];
    for(std::size_t i = 1; i < domains.size(); ++i) {
      std::cout << "minB2 " << domains[i]->minB2() << " " << domains[i]->minL2()
                << std::endl;
      minB = std::min(minB, domains[i]->minB());
      minL = std::min(minL, domains[i]->minL());
      minB2 = std::min(minB2, domains[i]->minB2());
      minL2 = std::min(minL2, domains[i]->minL2());
      domains[i]->deleteBezierCoeff();
      delete domains[i];
    }
    std::cout << "minIGE: " << minB << " vs " << minB2 << " + " << minL
              << " vs " << minL2 << std::endl;
    double fact = .5 * (minB + minL);
    return fact * minL + (1 - fact) * minB;
  }

  double _computeBoundRational(const fullVector<double> &numerator,
                               const fullVector<double> &denominator,
                               bool lower, bool positiveDenom)
  {
    if(numerator.size() != denominator.size()) {
      Msg::Error("In order to compute a bound on a rational function, I need "
                 "vectors of the same size! (%d vs %d)",
                 numerator.size(), denominator.size());
      return 0;
    }

    // upper and lower bound of the desired bound:
    const double inf = std::numeric_limits<double>::infinity();
    double upperBound = inf;
    double lowerBound = -inf;

    if(!positiveDenom) lower = !lower;

    if(lower) {
      // if lower is true, we seek: bound * den <= num
      for(int i = 0; i < numerator.size(); ++i) {
        if(denominator(i) == 0) {
          if(numerator(i) < 0) return -inf;
        }
        else if(denominator(i) > 0) {
          upperBound = std::min(upperBound, numerator(i) / denominator(i));
        }
        else {
          lowerBound = std::max(lowerBound, numerator(i) / denominator(i));
        }
      }
      if(lowerBound > upperBound)
        return -inf;
      else
        return upperBound;
    }
    else {
      // otherwise, we seek: bound * den >= num
      for(int i = 0; i < numerator.size(); ++i) {
        if(denominator(i) == 0) {
          if(numerator(i) > 0) return inf;
        }
        else if(denominator(i) > 0) {
          lowerBound = std::max(lowerBound, numerator(i) / denominator(i));
        }
        else {
          upperBound = std::min(upperBound, numerator(i) / denominator(i));
        }
      }
      if(lowerBound > upperBound)
        return inf;
      else
        return lowerBound;
    }
  }

} // end namespace jacobianBasedQuality
