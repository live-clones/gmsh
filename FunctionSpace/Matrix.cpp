#include <sstream>
#include "Matrix.h"
#include "Exception.h"

extern "C"{
#include <cblas.h>
}

Matrix::Matrix(const int n, const int m){
  if(!(n || m))
    throw Exception("Matrix can't be of dimension (0, 0)");
    
  nRow = n;
  nCol = m;
  nElem = nRow * nCol;
  matrix = new double[nElem];
}

Matrix::~Matrix(void){
  if(matrix)
    delete[] matrix;
}

void Matrix::allToZero(void){
  for(int i = 0; i < nElem; i++)
    matrix[i] = 0.0;
}

Vector<double> Matrix::mult(const Vector<double>& v) const{
  Vector<double> s(v.N);
  
  cblas_dgemv(CblasRowMajor, CblasNoTrans, 
	      nRow, nCol, 
	      1.0, matrix, nCol,
	      v.v, 1,
	      0.0, s.v, 1);

  return s;
}

std::string Matrix::toString(void) const{
  std::stringstream s;
  
  for(int i = 0; i < nRow; i++){
    for(int j = 0; j < nCol; j++){
      s << std::scientific << std::showpos << get(i, j) << "\t";
    }
    s << std::endl;
  }

  return s.str();
}

std::string Matrix::toStringMatlab(void) const{
  std::stringstream s;
  
  s << "[";
  for(int i = 0; i < nRow; i++){
    for(int j = 0; j < nCol; j++){
      s << std::scientific << std::showpos << get(j, i) << " ";
    }
    s << ";";
  }
  s << "]";
  
  return s.str();
}
