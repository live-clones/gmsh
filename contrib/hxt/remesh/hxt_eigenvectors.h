#ifndef HXT_EIGENVECTORS_H_
#define HXT_EIGENVECTORS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_api.h"

/**
 * Computes the eigen vectors of a 6 by 6 symmetric matrix.
 *
 * @param matrix A 6 by 6 symmetric matrix stored in row major order.
 * @param values A vector of capacity at least 6, used to store the eigen values
 *   of the matrix.
 * @param vectors A vector of capacity at least 36. Each block of 6 element
 *   corresponds to an eigenvector.
 */
HXTStatus hxtEigenvectors6(double * __restrict__ matrix,
                           double * __restrict__  values,
                           double * __restrict__ vectors);

/**
 * Computes the eigen vectors of a 3 by 3 symmetric matrix.
 *
 * @see hxtEigenvectors6.
 */
HXTStatus hxtEigenvectors3(double * __restrict__ matrix,
                           double * __restrict__  values,
                           double * __restrict__ vectors);

#ifdef __cplusplus
}
#endif

#endif
