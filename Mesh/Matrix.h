#ifndef _MATRIX_H_
#define _MATRIX_H_

#define _TAILLE_ 2

template <class T> class Matrix2x2{
  T mat[_TAILLE_][_TAILLE_];
  T zero;

public:

  Matrix2x2 (const T& init){
    zero = init;
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	mat[i][j] = zero;
  }

  Matrix2x2 (const T& init, T z[3][3]){
    zero = init;
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	mat[i][j] = z[i][j];
  }

  Matrix2x2<T>& operator = (const Matrix2x2<T> &autre){
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	mat[i][j] = autre.mat[i][j];
    return *this;
  }

  Matrix2x2<T> operator + (const Matrix2x2<T> &autre){
    Matrix2x2<T> m(0.);
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	m.mat[i][j] = mat[i][j] + autre.mat[i][j];
    return m;
  }

  Matrix2x2<T> operator - (const Matrix2x2<T> &autre){
    Matrix2x2<T> m(0.);
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	m.mat[i][j] = mat[i][j] - autre.mat[i][j];
    return m;
  }

  T* operator [] (int i){
    return mat[i];
  }

  Matrix2x2 Identity(T id){
    for(int i=0;i<_TAILLE_;i++)
      mat[i][i] = id;
  }

  Matrix2x2 copy(T m[3][3]){
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	m[i][j] = mat[i][j];
  }
  
  Matrix2x2 operator * (const Matrix2x2<T> &autre){
    Matrix2x2 m(0.);
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++){
	m.mat[i][j] = zero;
	for(int k=0;k<_TAILLE_;k++)
	  m.mat[i][j] += mat[i][k] * autre.mat[k][j];
      }
    return m;
  }
  
  bool invert (){
    T det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    if(det == zero)return false;
    mat[0][0] = mat[1][1] / det;
    mat[1][1] = mat[0][0] / det;
    mat[1][0] = -mat[1][0] / det;
    mat[0][1] = -mat[0][1] / det;
  }

  void transpose(){
    T temp;
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++){
	if(i!=j){
	  temp = mat[i][j];
	  mat[i][j] = mat[j][i];
	  mat[j][i] = temp;
	}
      }
  }
};

#undef _TAILLE_
#define _TAILLE_ 3

template <class T> class Matrix3x3{
  T mat[_TAILLE_][_TAILLE_];
  T zero;

public:

  Matrix3x3 (const T& init){
    zero = init;
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	mat[i][j] = zero;
  }

  Matrix3x3 (const T& init, T z[3][3]){
    zero = init;
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	mat[i][j] = z[i][j];
  }

  Matrix3x3<T>& operator = (const Matrix3x3<T> &autre){
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	mat[i][j] = autre.mat[i][j];
    return *this;
  }

  Matrix3x3<T> operator + (const Matrix3x3<T> &autre){
    Matrix3x3<T> m(0.);
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	m.mat[i][j] = mat[i][j] + autre.mat[i][j];
    return m;
  }

  Matrix3x3<T> operator - (const Matrix3x3<T> &autre){
    Matrix2x2<T> m(0.);
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	m.mat[i][j] = mat[i][j] - autre.mat[i][j];
    return m;
  }

  T* operator [] (int i){
    return mat[i];
  }

  void Identity(T id){
    for(int i=0;i<_TAILLE_;i++)
      mat[i][i] = id;
  }

  void copy(T m[3][3]){
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++)
	m[i][j] = mat[i][j];
  }
  
  Matrix3x3 operator * (const Matrix3x3<T> &autre){
    Matrix3x3 m(0.);
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<_TAILLE_;j++){
	m.mat[i][j] = zero;
	for(int k=0;k<_TAILLE_;k++)
	  m.mat[i][j] += mat[i][k] * autre.mat[k][j];
      }
    return m;
  }

  /*
    bool invert (){
      T det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
      if(det == zero)return false;
      mat[0][0] = mat[1][1] / det;
      mat[1][1] = mat[0][0] / det;
      mat[1][0] = -mat[1][0] / det;
      mat[0][1] = -mat[0][1] / det;
    }
  */

  void transpose(){
    T temp;
    for(int i=0;i<_TAILLE_;i++)
      for(int j=0;j<i;j++){
	if(i!=j){
	  temp = mat[i][j];
	  mat[i][j] = mat[j][i];
	  mat[j][i] = temp;
	}
      }
  }
};

#undef _TAILLE_

#endif
