// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "miniBasis.h"
#include "BasisFactory.h"

miniBasisTri::miniBasisTri()
{
  type = MSH_TRI_MINI;
  parentType = TYPE_TRI;
  order = 3;
  dimension = 2;
  numFaces = 3;
  serendip = false;
  const nodalBasis &p1 = *BasisFactory::getNodalBasis(MSH_TRI_3);
  closures = p1.closures;
  fullClosures = p1.fullClosures;
  for(size_t i = 0; i < fullClosures.size(); ++i) {
    fullClosures[i].push_back(3);
  }
  closureRef = p1.closureRef;
  points = p1.points;
  points.resize(4, 2);
  points(0, 0) = 0.;
  points(0, 1) = 0.;
  points(1, 0) = 1.;
  points(1, 1) = 0.;
  points(2, 0) = 0.;
  points(2, 1) = 1.;
  points(3, 0) = 1. / 3;
  points(3, 1) = 1. / 3;
  /*
  monomials :
    0 : 1
    1 : x
    2 : y
    3 : xy
    4 : x²y
    5 : xy²
  fs :
    0 : 1 -1 -1  0  0  0 : 1 - x - y
    1 : 1  0  0  0  0  0 : x
    2 : 0  1  0  0  0  0 : y
    3 : 0  0  0  1 -1 -1 : xy - x²y - xy² = (1 - x - y) x y
  */
  monomials.resize(6, 2);
  monomials(0, 0) = 0.;
  monomials(0, 1) = 0.;
  monomials(1, 0) = 1.;
  monomials(1, 1) = 0.;
  monomials(2, 0) = 0.;
  monomials(2, 1) = 1.;
  monomials(3, 0) = 1.;
  monomials(3, 1) = 1.;
  monomials(4, 0) = 2.;
  monomials(4, 1) = 1.;
  monomials(5, 0) = 1.;
  monomials(5, 1) = 2.;
  coefficients.resize(4, 6);
  coefficients.setAll(0.);
  coefficients(0, 0) = 1.;
  coefficients(0, 1) = -1.;
  coefficients(0, 2) = -1.;
  coefficients(1, 1) = 1.;
  coefficients(2, 2) = 1.;
  coefficients(3, 3) = 1.;
  coefficients(3, 4) = -1.;
  coefficients(3, 5) = -1.;
}

miniBasisTet::miniBasisTet()
{
  type = MSH_TET_MINI;
  parentType = TYPE_TET;
  order = 3;
  dimension = 3;
  numFaces = 4;
  serendip = false;
  const nodalBasis &p1 = *BasisFactory::getNodalBasis(MSH_TET_4);
  closures = p1.closures;
  fullClosures = p1.fullClosures;
  for(size_t i = 0; i < fullClosures.size(); ++i) {
    fullClosures[i].push_back(4);
  }
  closureRef = p1.closureRef;
  points.resize(5, 3);
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 3; ++j) points(i, j) = p1.points(i, j);
  points(4, 0) = points(4, 1) = points(4, 2) = 1. / 4;

  /*
  monomials :
    0 : 1
    1 : x
    2 : y
    3 : z
    4 : xyz
    5 : x²yz
    6 : xy²z
    7 : xyz²
  sf :
    0 : 1 -1 -1 -1  0  0  0  0 : 1 - x - y - z
    1 : 0  1  0  0  0  0  0  0 : x
    2 : 0  0  1  0  0  0  0  0 : y
    3 : 0  0  0  1  0  0  0  0 : z
    4 : 0  0  0  0  1 -1 -1 -1 : xyz - x²yz - xy²z - xyz² = (1 - x - y - z) x y
  z
  */
  monomials.resize(8, 3);
  monomials(0, 0) = 0.;
  monomials(0, 1) = 0.;
  monomials(0, 2) = 0.;
  monomials(1, 0) = 1.;
  monomials(1, 1) = 0.;
  monomials(1, 2) = 0.;
  monomials(2, 0) = 0.;
  monomials(2, 1) = 1.;
  monomials(2, 2) = 0.;
  monomials(3, 0) = 0.;
  monomials(3, 1) = 0.;
  monomials(3, 2) = 1.;
  monomials(4, 0) = 1.;
  monomials(4, 1) = 1.;
  monomials(4, 2) = 1.;
  monomials(5, 0) = 2.;
  monomials(5, 1) = 1.;
  monomials(5, 2) = 1.;
  monomials(6, 0) = 1.;
  monomials(6, 1) = 2.;
  monomials(6, 2) = 1.;
  monomials(7, 0) = 1.;
  monomials(7, 1) = 1.;
  monomials(7, 2) = 2.;
  coefficients.resize(5, 8);
  coefficients.setAll(0.);
  coefficients(0, 0) = 1.;
  coefficients(0, 1) = -1.;
  coefficients(0, 2) = -1.;
  coefficients(0, 3) = -1.;
  coefficients(1, 1) = 1.;
  coefficients(2, 2) = 1.;
  coefficients(3, 3) = 1.;
  coefficients(4, 4) = 1.;
  coefficients(4, 5) = -1.;
  coefficients(4, 6) = -1.;
  coefficients(4, 7) = -1.;
}
