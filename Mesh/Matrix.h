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
  double _val[9];
  public:
  Matrix(){
    /* m11 = 1.0; */
    /* m21 = 0.0; */
    /* m31 = 0.0; */
    /* m12 = 0.0; */
    /* m22 = 1.0; */
    /* m32 = 0.0; */
    /* m13 = 0.0; */
    /* m23 = 0.0; */
    /* m33 = 1.0; */
    _val[0] = _val[4] = _val[8] = 1.0;
    _val[1] = _val[2] = _val[3] = 0.0;
    _val[5] = _val[6] = _val[7] = 0.0;
  }
  ~Matrix(){}
  void set_m11(double x){  _val[0] = x; }
  void set_m21(double x){  _val[1] = x; }
  void set_m31(double x){  _val[2] = x; }
  void set_m12(double x){  _val[3] = x; }
  void set_m22(double x){  _val[4] = x; }
  void set_m32(double x){  _val[5] = x; }
  void set_m13(double x){  _val[6] = x; }
  void set_m23(double x){  _val[7] = x; }
  void set_m33(double x){  _val[8] = x; }
  double get_m11(){ return _val[0]; }
  double get_m21(){ return _val[1]; }
  double get_m31(){ return _val[2]; }
  double get_m12(){ return _val[3]; }
  double get_m22(){ return _val[4]; }
  double get_m32(){ return _val[5]; }
  double get_m13(){ return _val[6]; }
  double get_m23(){ return _val[7]; }
  double get_m33(){ return _val[8]; }
};

#endif
