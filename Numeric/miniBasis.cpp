#include "miniBasis.h"
#include "BasisFactory.h"
miniBasis::miniBasis()
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
  points(0, 0) = 0.; points(0, 1) = 0.;
  points(1, 0) = 1.; points(1, 1) = 0.;
  points(2, 0) = 0.; points(2, 1) = 1.;
  points(3, 0) = 1./3; points(3, 1) = 1./3;
  monomials.resize(6, 2);
  monomials(0, 0) = 0.; monomials(0, 1) = 0.;
  monomials(1, 0) = 1.; monomials(1, 1) = 0.;
  monomials(2, 0) = 0.; monomials(2, 1) = 1.;
  monomials(3, 0) = 1.; monomials(3, 1) = 1.;
  monomials(4, 0) = 2.; monomials(4, 1) = 1.;
  monomials(5, 0) = 1.; monomials(5, 1) = 2.;
  coefficients.resize(4, 6);
  coefficients.setAll(0.);
  coefficients(0, 0) = 1.; coefficients(0, 1) = -1.; coefficients(0, 2) = -1.;
  coefficients(1, 1) = 1.;
  coefficients(2, 2) = 1.;
  coefficients(3, 3) = 1.; coefficients(3, 4) = -1.; coefficients(3, 5) = -1.; 
}
