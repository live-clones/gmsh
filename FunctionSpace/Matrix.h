#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <string>
#include "Vector.h"

/**
   @class Matrix
   @brief Handles matrices
   
   This class represents a @c n by @c m matrix.

   @todo
   Other than Matrix of double
 */

class Solver;

class Matrix{
 private:
  int nRow;
  int nCol;
  int nElem;
  double *matrix;
  friend class Solver;

 public:
   Matrix(const int n, const int m);
  ~Matrix(void);

  int row(void) const;
  int col(void) const;

  void   set(const int i, const int j, const double v);
  void   allToZero(void);
  double get(const int i, const int j) const;
  
  double& operator()(const int i, const int j);
  double  operator()(const int i, const int j) const;
  
  Vector<double> mult(const Vector<double>& v) const;

  std::string toString(void) const;
  std::string toStringMatlab(void) const;
};

/**
   @fn Matrix::Matrix
   @param n The number of @em rows of the future Matrix
   @param m The number of @em columns of the future Matrix
   @return Returns a new @c n by @c m Matrix

   @fn Matrix::~Matrix
   @return Deletes this Matrix

   @fn Matrix::row
   @return Returns the number of @c rows of this Matrix
   
   @fn Matrix::col
   @return Returns the number of @c columns of this Matrix

   @fn Matrix::set
   @param i A @em row index
   @param j A @em column index
   @param v A value
   @returns Sets the given value at the position (@c i, @c j)
   in this Matrix

   @fn Matrix::allToZero
   @returns Sets all the Matrix elements to @em @c 0
 
   @fn Matrix::get
   @param i A @em row index
   @param j A @em column index
   @returns Retuns the value at the position (@c i, @c j)
   in this Matrix
   
   @fn double& Matrix::operator()(const int, const int)
   @param i A @em row index
   @param j A @em column index
   @return Returns a @em reference to the element
   at position (@c i, @c j) in this Matrix

   @fn double Matrix::operator()(const int, const int) const
   @param i A @em row index
   @param j A @em column index
   @return Returns the @em value of the element
   at position (@c i, @c j) in this Matrix

   @fn Matrix::mult
   @param v A Vector of size @c m (for a @c n by @c m Matrix)
   @return Returns the Vector (of size @c n) resulting 
   of the product of @em this Matrix with the @em given Vector

   @fn Matrix::toString
   @return Retuns a string correspondig to this Matrix

   @fn Matrix::toStringMatlab
   @return Same as Matrix::toString, but the string is in 
   Matlab / Octave format
*/

//////////////////////
// Inline Functions //
//////////////////////

inline int Matrix::row(void) const{
  return nRow;
}

inline int Matrix::col(void) const{
  return nCol;
}

inline void Matrix::set(const int i, const int j, const double v){
  matrix[j + i * nCol] = v;
}

inline double Matrix::get(const int i, const int j) const{
  return matrix[j + i * nCol];
}

inline double& Matrix::operator()(const int i, const int j){
  return matrix[j + i * nCol];
}

inline double Matrix::operator()(const int i, const int j) const{
  return matrix[j + i * nCol];
}

#endif
