#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <string>

extern "C"{
#include <cblas.h>
}

#include "Exception.h"

/**
   @class Vector
   @brief Handles vectors

   This class represents a vector of type < T >
   and of dimention @c n.   

   @todo
   Use Inheritance instead of template@n
   |@n
   |@n
   ---> We have methods that changes between types 
   (e.g: at(...), 3D automatic allocation, scalar mult)
 */

class Solver;

template<class T>
class Vector{
 private:
  int N;
  T* v;

  friend class Solver;
  friend class Matrix;
  
 public:
   Vector(const int a);
   Vector(void);
  ~Vector(void);

  int dim(void) const;

  T&   operator()(const int i);
  T    operator()(const int i) const;
  void operator=(const Vector<T>& other);

  T    get(const int i) const;
  void set(const int i, const T a);

  Vector<double> at(const double x, const double y, const double z) const;

  Vector<T> operator+(const Vector<T>& other);
  Vector<T> operator-(const Vector<T>& other);
  Vector<T> operator*(const T& other);
  //Vector<T> operator*(const double alpha);

  void   add(const Vector<T>& b);
  void   sub(const Vector<T>& b);
  void   mul(const T& other);
  //void   mul(const double alpha);
  double dot(const Vector<T>& v) const;

  void allToZero(void);

  std::string toString(void) const;
};


/**
   @fn Vector::Vector(int)
   @param a Size of the futur Vector
   @return Returns a new Vector of size @c a

   @fn Vector::Vector(void)
   @return Returns a new Vector of size @em @c 3

   @fn Vector::~Vector
   @return Deletes this Vector

   @fn Vector::dim
   @return Returns the @em dimention of this vector

   @fn T& Vector::operator()(const int)
   @param i An index of this Vector
   @return Returns a @em reference to
   the element at position @c i
 
   @fn T Vector::operator()(const int) const
   @param i An index of this Vector
   @return Returns the @em value of
   the element at position @c i

   @fn Vector::get
   @param i An index in this Vector
   @return Returns the @em value of the element
   at position @c i

   @fn Vector::set
   @param i An index in this Vector
   @param a A value
   @return Sets the given value at position @c i
   in this Vector

   @fn Vector::at
   @param x The @em first dimesion of a @c 3D Polynomial
   @param y The @em second dimesion of a @c 3D Polynomial
   @param z The @em third dimesion of a @c 3D Polynomial
   @return Retuns the @c 3D Vector resulting of the @em evaluation
   of this @em @c 3D Vector @em of @em Polynomial%s

   @warning
   This works only for @em @c 3D Vector @em of @em Polynomial%s

   @fn Vector<T> Vector::operator+(const Vector<T>&)
   @param other An other Vector
   @return Returns the Vector containing
   the @em sum of this Vector with the other

   @fn Vector<T> Vector::operator-(const Vector<T>&)
   @param other An other Vector
   @return Returns the Vector containing
   the @em substraction of this Vector with the other

   @fn Vector<T> Vector::operator*(const T&)
   @param other A value
   @return Returns the Vector containing
   the @em product (@em element @em by @em element) 
   of this Vector with the given value

   @fn Vector::add
   @param b An other Vector
   @return Adds the given Vector with this one
   @note
   The result is stored in this Vector

   @fn Vector::sub
   @param b An other Vector
   @return Substracts the given Vector with this one
   @note
   The result is stored in this Vector

   @fn Vector::mul
   @param other A value
   @return Multiplies all the elements of this Vector 
   with the given value
   @note
   The result is stored in this Vector

   @fn Vector::dot
   @param v An Vector
   @return Returns the @em dot @em product of this
   Vector with the given one

   @fn Vector::allToZero
   @return Sets all the elements of this Vector
   to the @em zero @em element

   @fn Vector::toString
   @return Returns a string representing this Vector
*/

//////////////////////////////////////////////////////////////////////
// Templated Implementations                                        //
//////////////////////////////////////////////////////////////////////

template<class T>
Vector<T>::Vector(const int a){
  if(!a)
    throw Exception("Vector must by of dimension bigger than 0");
  
  N = a;
  v = new T[N];
}

template<class T>
Vector<T>::Vector(void){
  N = 3;
  v = new T[N];
}

template<class T>
Vector<T>::~Vector(void){
  delete[] v;
}

//////////////////////////////////////////////////////////////////////
// Inline Templated Implementations                                 //
//////////////////////////////////////////////////////////////////////

template<class T>
inline int Vector<T>::dim(void) const{
  return N;
}

template<class T>
inline T& Vector<T>::operator()(const int i){
  return v[i];
}

template<class T>
inline T Vector<T>::operator()(const int i) const{
  return v[i];
}

template<class T>
void Vector<T>::operator=(const Vector<T>& other){
  if(N != other.N)
    throw Exception("Vectors must be of the same dimension");

  for(int i = 0; i < N; i++)
    v[i] = other.v[i];
}

template<class T>
inline T Vector<T>::get(const int i) const{
  return v[i];
}

template<class T>
inline void Vector<T>::set(const int i, const T a){
  v[i] = a;
}

//////////////////////////////////////////////////////////////////////
// Inline Vector<double> Implementations                            //
//////////////////////////////////////////////////////////////////////

template<>
inline double Vector<double>::dot(const Vector<double>& v) const{ 
  return cblas_ddot(N, (*this).v, 1, v.v, 1);
}

#endif
