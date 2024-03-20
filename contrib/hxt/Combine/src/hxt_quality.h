#ifndef HXT_PROCESSING_QUALITY_H_
#define HXT_PROCESSING_QUALITY_H_

#include "hxt_message.h"
#include "math.h"

// Interface with the vector/point 
// class toto;
class point3d;

double hexSubdivisionBasedQuality(const point3d* pointCoordinates);

bool hexExactValidity(const point3d* pointCoordinates);
bool prismValidity(const point3d* pointCoordinates);
bool pyramidValidityNotImplemented(const point3d* pointCoordinates);



#ifdef __cplusplus
extern "C" {
#endif

/**
* \file API to evaluate the validity and quality of H1 finite element cells.
*
* \authors Amaury Johnen, Jeanne Pellerin, Kilian Verhetsel
*
* References:
*  - Johnen A, Weill J-C, Remacle J-F. Robust and efficient validation of the linear hexahedral element. Procedia Engineering. 2017;203:271–83. [arXiv:1706.01613]
*  - Johnen A, Remacle J-F, Geuzaine C. Geometrical validity of curvilinear finite elements. Journal of Computational Physics. 2013 Jan;233:359–72.
*  - Johnen A, Geuzaine C. Geometrical validity of curvilinear pyramidal finite elements. Journal of Computational Physics. 2015;299:124–129.
*  - Johnen A, Geuzaine C, Toulorge T, Remacle J-F. Efficient Computation of the Minimum of Shape Quality Measures on Curvilinear Finite Elements. Procedia Engineering. 2016;163:328–39.
*
*
* WARNING: Most of the code is not robust to floating point errors.
*          Only the computation of the validit of a hexahedron is.
*/

bool hxtValidityTetrahedron(
  const double* p0, const double* p1, const double* p2, const double* p3);

bool hxtValidityPyramid(
  const double* p0, const double* p1, const double* p2, const double* p3, const double* p4);

bool hxtValidityPrism(
  const double* p0, const double* p1, const double* p2,
  const double* p3, const double* p4, const double* p5);

bool hxtValidityHexahedron(
  const double* p0, const double* p1, const double* p2, const double* p3,
  const double* p4, const double* p5, const double* p6, const double* p7);


double hxtQualityTetrahedron(
  const double* p0, const double* p1, const double* p2, const double* p3);

double hxtQualityPyramid(
  const double* p0, const double* p1, const double* p2, const double* p3, const double* p4);

double hxtQualityPrism(
  const double* p0, const double* p1, const double* p2, 
  const double* p3, const double* p4, const double* p5);

/** Approximated quality of the hexahedron: minimum scaled Jacobian value at the corners */
double hxtQualityHexahedron(const double* p0, const double* p1, const double* p2, const double* p3,
							const double* p4, const double* p5, const double* p6, const double* p7);

/** The real quality of a hexahedron.
 * \returns Zero if the element is invalid otherwise returns the 
 *          minimal scaled Jacobian value over the hex.
 */
double hxtHexSubdivisionBasedQuality(
  const double* p0, const double* p1, const double* p2, const double* p3,
  const double* p4, const double* p5, const double* p6, const double* p7);


// I have the bad impression that the first #endif is close first
// on visual studio at least [Jeanne]
// Keep them close, and put nothing in between
#ifdef __cplusplus
}
#endif
#endif
