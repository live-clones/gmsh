// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#ifndef _MATRIX_TCB_H_
#define _MATRIX_TCB_H_

class Matrix{
 private:
  double m11,m21,m31,m12,m22,m32,m13,m23,m33;
 public:
  Matrix(){
    m11 = 1.0;
    m21 = 0.0;
    m31 = 0.0;
    m12 = 0.0;
    m22 = 1.0;
    m32 = 0.0;
    m13 = 0.0;
    m23 = 0.0;
    m33 = 1.0;
  }
  ~Matrix(){}
  void set_m11(double x){ m11 = x; }
  void set_m21(double x){ m21 = x; }
  void set_m31(double x){ m31 = x; }
  void set_m12(double x){ m12 = x; }
  void set_m22(double x){ m22 = x; }
  void set_m32(double x){ m32 = x; }
  void set_m13(double x){ m13 = x; }
  void set_m23(double x){ m23 = x; }
  void set_m33(double x){ m33 = x; }
  double get_m11(){ return m11; }
  double get_m21(){ return m21; }
  double get_m31(){ return m31; }
  double get_m12(){ return m12; }
  double get_m22(){ return m22; }
  double get_m32(){ return m32; }
  double get_m13(){ return m13; }
  double get_m23(){ return m23; }
  double get_m33(){ return m33; }
};

/*
double Matrix::get_m11(){ return m11; }
double Matrix::get_m21(){ return m21; }
double Matrix::get_m31(){ return m31; }
double Matrix::get_m12(){ return m12; }
double Matrix::get_m22(){ return m22; }
double Matrix::get_m32(){ return m32; }
double Matrix::get_m13(){ return m13; }
double Matrix::get_m23(){ return m23; }
double Matrix::get_m33(){ return m33; }


Matrix::Matrix(){
  m11 = 1.0;
  m21 = 0.0;
  m31 = 0.0;
  m12 = 0.0;
  m22 = 1.0;
  m32 = 0.0;
  m13 = 0.0;
  m23 = 0.0;
  m33 = 1.0;
}
Matrix::~Matrix(){}

void Matrix::set_m11(double new_m11){ m11 = new_m11; }
void Matrix::set_m21(double new_m21){ m21 = new_m21; }
void Matrix::set_m31(double new_m31){ m31 = new_m31; }
void Matrix::set_m12(double new_m12){ m12 = new_m12; }
void Matrix::set_m22(double new_m22){ m22 = new_m22; }
void Matrix::set_m32(double new_m32){ m32 = new_m32; }
void Matrix::set_m13(double new_m13){ m13 = new_m13; }
void Matrix::set_m23(double new_m23){ m23 = new_m23; }
void Matrix::set_m33(double new_m33){ m33 = new_m33; }
*/


#endif
