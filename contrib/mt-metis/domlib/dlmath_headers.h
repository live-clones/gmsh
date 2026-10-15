/**
 * @file dlmath_headers.h
 * @brief Mathematical function prototypes
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */




#ifndef DLMATH_STATIC



/******************************************************************************
* FUNCTION PROTOTYPES *********************************************************
******************************************************************************/


/* prefixing ugliness */
#define DLMATH_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLMATH_PRE1(prefix,suffix) DLMATH_PRE2(prefix,suffix)
#define DLMATH_PUB(name) DLMATH_PRE1(DLMATH_PREFIX,name)
#define DLMATH_PRI(name) DLMATH_PRE1(_,DLMATH_PRE1(DLMATH_PREFIX,name))


/**
 * @brief Take the absolute different between two numbers. 
 *
 * @param a The first number.
 * @param b The second number.
 *
 * @return The difference.
 */
DLMATH_TYPE_T DLMATH_PUB(abs_diff)(
    DLMATH_TYPE_T a,
    DLMATH_TYPE_T b);

/**
 * @brief Sum the values in an array. For floating point types, an effort is
 * made to make this more numerically stable, for doing a block summation for
 * each page (4096 bytes) of data.
 *
 * @param ptr The pointer to the values to be summed.
 * @param n The number of values to be summed.
 *
 * @return The sum of the values stored in ptr.
 */
DLMATH_TYPE_T DLMATH_PUB(sum)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


/**
 * @brief Product of the values in an array. 
 *
 * @param ptr The pointer to the values to be product'ed.
 * @param n The number of values to be product'ed.
 *
 * @return The product of the values.
 */
DLMATH_TYPE_T DLMATH_PUB(product)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


/**
 * @brief Find the difference between each pair of elements in an array.
 * If A = [0, 12, 37, 38, 38, 100], then 
 * differentiate(A) = [12, 25, 3, 0, 62, 0]
 *
 * @param ptr The pointer to the elements to differentiate.
 * @param n The number of elements to differentiate.
 */
void DLMATH_PUB(differentiate)(
    DLMATH_TYPE_T * ptr, 
    size_t n);


/**
 * @brief Perform an inclusive prefix sum/scan on an array.
 *
 * @param ptr The point to the elements to be summed/scanned.
 * @param n The number of elements to be summed/scanned.
 */
void DLMATH_PUB(prefixsum_inc)(
    DLMATH_TYPE_T * ptr, 
    size_t n);


/**
 * @brief Perform an exclusive prefix sum/scan on an array.
 *
 * @param ptr The pointer to the elements to be summed/scanned.
 * @param n The number of elements to be summed/scanned.
 *
 * @return The sum total of all the elements.
 */

DLMATH_TYPE_T DLMATH_PUB(prefixsum_exc)(
    DLMATH_TYPE_T * ptr, 
    size_t n);


/**
 * @brief Shift all of the elements in the array one index back and insert zero 
 * at the beginning. 
 *
 * @param ptr The pointer to the elements to be shifted.
 * @param n The number of elements to be shifted.
 *
 * @return The last element in the array that is removed by the shift. 
 */
DLMATH_TYPE_T DLMATH_PUB(prefixshift)(
    DLMATH_TYPE_T * ptr, 
    size_t n);


/**
 * @brief Add a scalar to each element in the array.
 *
 * @param ptr The pointer to the elements to which to add. 
 * @param a The value to add to each element.
 * @param n The number of elements to which to add.
 */
void DLMATH_PUB(add)(
    DLMATH_TYPE_T * ptr, 
    DLMATH_TYPE_T a, 
    size_t n);


/**
 * @brief Scale each element in the array.
 *
 * @param ptr The pointer to the elements to which to scale. 
 * @param a The value to scale to each element be.
 * @param n The number of elements to which to scale.
 */
void DLMATH_PUB(scale)(
    DLMATH_TYPE_T * ptr, 
    DLMATH_TYPE_T a, 
    size_t n);




/**
 * @brief Find the index of the maximum value in an array.
 *
 * @param ptr The pointer to the array of values.
 * @param n The number of values in the array.
 *
 * @return The index of the maximum value.
 */
size_t DLMATH_PUB(max_index)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


/**
 * @brief Find the maximum value in an array.
 *
 * @param ptr The pointer to the array of values.
 * @param n The number of values in the array.
 *
 * @return The maximum value. 
 */
DLMATH_TYPE_T DLMATH_PUB(max_value)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


/**
 * @brief Offset the values of an array such that the max is a desired value.
 * This means either added a constant to each value, subtracting a constant
 * from each value, or nothing if the max is equal to the desired value.
 *
 * @param ptr The array of values. 
 * @param max The desired maximum.
 * @param n The number of values.
 *
 * @return The old maximum value. 
 */
DLMATH_TYPE_T DLMATH_PUB(set_max)(
    DLMATH_TYPE_T * ptr, 
    DLMATH_TYPE_T max, 
    size_t n);


/**
 * @brief Find the index of the minimum value in an array.
 *
 * @param ptr The pointer to the array of values.
 * @param n The number of values.
 *
 * @return The index of the minimum value.
 */
size_t DLMATH_PUB(min_index)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


/**
 * @brief Find the minimum value in an array.
 *
 * @param ptr The pointer to the array of values. 
 * @param n The number of values.
 *
 * @return The minimum value.
 */
DLMATH_TYPE_T DLMATH_PUB(min_value)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


/**
 * @brief Offset the values of an array such that the max is a desired value.
 * This means either added a constant to each value, subtracting a constant
 * from each value, or nothing if the max is equal to the desired value.
 *
 * @param ptr The array of values. 
 * @param max The desired minimum.
 * @param n The number of values.
 *
 * @return The old minimum value. 
 */
DLMATH_TYPE_T DLMATH_PUB(set_min)(
    DLMATH_TYPE_T * ptr, 
    DLMATH_TYPE_T min, 
    size_t n);


/**
 * @brief Set the values of an array to increment (or decrementing) from a
 * starting value by specified step. 
 *
 * @param ptr The array of which to set the values.
 * @param start The starting value (i.e., ptr[0]).
 * @param inc The step size (i.e., ptr[1] = ptr[0] + inc)
 * @param n The number of values.
 */
void DLMATH_PUB(incset)(
    DLMATH_TYPE_T * ptr, 
    DLMATH_TYPE_T start, 
    DLMATH_TYPE_T inc, 
    size_t n);


/**
 * @brief Set the values of an array to be a cyclic permutation vector.
 * If called with cyclicperm(A,3,10), then A = [0, 3, 6, 9, 1, 4, 7, 2, 5, 8]   
 *
 * @param ptr The array of which to set the values. 
 * @param cyclesize The size of each cycle.
 * @param n The size of the array.
 */
void DLMATH_PUB(cyclicperm)(
    DLMATH_TYPE_T * ptr, 
    size_t cyclesize, 
    size_t n);


/**
 * @brief Set the values of an array to be a blockcyclic permutation vector. 
 * If called with blockcyclicperm(A,3,2,10), then 
 * A = [0, 1, 6, 7, 2, 3, 8, 9, 4, 5]
 *
 * @param ptr The array of whcih to set the values.
 * @param cyclesize The size of each cycle.
 * @param blocksize The size of each block.
 * @param n The size of the array.
 */
void DLMATH_PUB(blockcyclicperm)(
    DLMATH_TYPE_T * ptr, 
    size_t cyclesize, 
    size_t blocksize, 
    size_t n);


/**
 * @brief Merge the values of two arrays by always choosing maximum value at
 * each index.
 *
 * @param dst The first of the two arrays to be merged and where the output is
 * stored.
 * @param src The second of the two arrays to be merged, and is unmodified.
 * @param n The number of elements in each array.
 * @param empty_value The value to be considered as empty or invalid (i.e.,
 * empty values are never chosen as the maximum).
 */
void DLMATH_PUB(max_merge)(
    DLMATH_TYPE_T * dst, 
    DLMATH_TYPE_T const * src, 
    size_t n, 
    DLMATH_TYPE_T empty_value);


/**
 * @brief Merge the values of two arrays by always choosing minimum value at
 * each index.
 *
 * @param dst The first of the two arrays to be merged and where the output is
 * stored.
 * @param src The second of the two arrays to be merged, and is unmodified.
 * @param n The number of elements in each array.
 * @param empty_value The value to be considered as empty or invalid (i.e.,
 * empty values are never chosen as the minimum).
 */
void DLMATH_PUB(min_merge)(
    DLMATH_TYPE_T * dst, 
    DLMATH_TYPE_T const * src, 
    size_t n, 
    DLMATH_TYPE_T empty_value);

/**
 * @brief Merge the values of two arrays by taking the average of each pair
 * elements (i.e., dst[i] = ((dst[i] + src[i]) / 2). However, if either value
 * in dst or src is the empty value, then the other value is taken without
 * modification.
 *
 * @param dst The first of the two arrays to be merged and where the output is
 * stored.
 * @param src The second of the two arrays to be merged, and is unmodified.
 * @param n The number of elements in each array.
 * @param empty_value The value to be considered as empty or invalid (i.e.,
 * empty values are not taken into account for the average).
 */
void DLMATH_PUB(avg_merge)(
    DLMATH_TYPE_T * dst, 
    DLMATH_TYPE_T const * src, 
    size_t n, 
    DLMATH_TYPE_T empty_value);


/**
 * @brief Find the number of common elements between two arrays that are sorted
 * in ascending order.
 *
 * @param a The pointer to the first array of values. This must be sorted in
 * ascending order.
 * @param n The length of the first array.
 * @param b The pointer to the second array of values. This must be sorted in
 * ascending order.
 * @param m The length of the second array.
 *
 * @return The number of elements in common for both arrays. 
 */
size_t DLMATH_PUB(intersection_size)(
    DLMATH_TYPE_T const * a, 
    size_t n,
    DLMATH_TYPE_T const * b, 
    size_t m);


#if defined(DLMATH_DLTYPE) && DLMATH_DLTYPE == DLTYPE_FLOAT


/**
 * @brief Calcuate the sum of an array of elements using a (more) numerically 
 * stable method.
 *
 * @param ptr The array of elements to sum.
 * @param n The The number of elements in the array.
 *
 * @return The sum.
 */
DLMATH_TYPE_T DLMATH_PUB(stable_sum)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


/**
 * @brief Calcuate the sum of an array of elements using semi-numerically 
 * stable and return the result in a long double for high accuracy and
 * precision.
 *
 * @param ptr The pointer to the elements to be summed.
 * @param n The number of elements to be summed.
 *
 * @return The sum.
 */
long double DLMATH_PUB(fa_sum)(
    DLMATH_TYPE_T const * ptr, 
    size_t n);


#endif


#if defined(DLMATH_DLTYPE) && DLMATH_DLTYPE == DLTYPE_INTEGRAL


/**
 * @brief Sum the numbers in an array using a uint64_t to track the sum.
 *
 * @param a The array to sum.
 * @param n Size of array.
 *
 * @return The sum. 
 */
int64_t DLMATH_PUB(lsum)(
    DLMATH_TYPE_T const * a,
    size_t n);


/**
 * @brief Calculate the integer log_2(n) rounded up.
 *
 * @param n The number to calculate the logrithm of. 
 *
 * @return The ceil( log_2(n) )
 */
DLMATH_TYPE_T DLMATH_PUB(uplog2)(
    DLMATH_TYPE_T n); 

/**
 * @brief Calculate the integer log_2(n) rounded down.
 *
 * @param n The number to calculate the logrithm of. 
 *
 * @return The floor( log_2(n) )
 */
DLMATH_TYPE_T DLMATH_PUB(downlog2)(
    DLMATH_TYPE_T n);


/**
 * @brief Find the next close power of 2 that is greater than or equal to the
 * supplied number.
 *
 * @param n The number of which to find the closest power of 2.
 *
 * @return The closest power of 2.
 */
DLMATH_TYPE_T DLMATH_PUB(uppow2)(
    DLMATH_TYPE_T n);


/**
 * @brief Find the next close power of 2 that is less than or equal to the
 * supplied number.
 *
 * @param n The number of which to find the closest power of 2.
 *
 * @return The closest power of 2.
 */
DLMATH_TYPE_T DLMATH_PUB(downpow2)(
    DLMATH_TYPE_T n);



/**
 * @brief Return the result of a/b rounded up.
 *
 * @param a The numerator.
 * @param b The denominator.
 *
 * @return ceil (a/b).
 */
DLMATH_TYPE_T DLMATH_PUB(updiv)(
    DLMATH_TYPE_T a, 
    DLMATH_TYPE_T b);


/**
 * @brief Determine the size of the i'th chunk of array when split as evenly as
 * possible.
 *
 * @param i The number of the chunk.
 * @param n The total number of elements.
 * @param m The total number of chunks.
 *
 * @return The number of elements in the i'th chunk. 
 */
DLMATH_TYPE_T DLMATH_PUB(chunksize)(
    DLMATH_TYPE_T i, 
    DLMATH_TYPE_T n, 
    DLMATH_TYPE_T m);


/**
 * @brief Determine the starting element of the i'th chunk of an array when
 * split as evenly as possible. 
 *
 * @param i The number of the chunk. 
 * @param n The total number of elements.
 * @param m The total number of chunks.
 *
 * @return The starting element/index of the i'th chunk.
 */
DLMATH_TYPE_T DLMATH_PUB(chunkstart)(
    DLMATH_TYPE_T i, 
    DLMATH_TYPE_T n, 
    DLMATH_TYPE_T m);


/**
 * @brief Determine the chunk number of the g'th element.
 *
 * @param g The element index.
 * @param n The number of chunks.
 * @param m The number of elements.
 *
 * @return The chunk number. 
 */
DLMATH_TYPE_T DLMATH_PUB(chunkid)(
    DLMATH_TYPE_T g, 
    DLMATH_TYPE_T n, 
    DLMATH_TYPE_T m);


/**
 * @brief Reverse the bits in a number.
 *
 * @param n The number of which to reverse the bits.
 *
 * @return The number with the bits reversed. 
 */
DLMATH_TYPE_T DLMATH_PUB(reversebits)(
    DLMATH_TYPE_T n);




#endif




#undef DLMATH_PRE2
#undef DLMATH_PRE1
#undef DLMATH_PUB
#undef DLMATH_PRI




#else




#define DLMATH_VISIBILITY static
#include "dlmath_funcs.h"
#undef DLMATH_VISIBILITY




#endif
