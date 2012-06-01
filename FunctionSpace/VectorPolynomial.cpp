#include <sstream>
#include "Vector.h"
#include "Polynomial.h"

using namespace std;

template<>
Vector<double> Vector<Polynomial>::at(const double x, 
				      const double y, 
				      const double z) const{
  Vector<double> val(N);
  
  for(int i = 0; i < N; i++)
    val(i) = v[i].at(x, y, z);

  return val;
}

template<>
void Vector<Polynomial>::add(const Vector<Polynomial>& other){
  for(int i = 0; i < N; i++)
    v[i].add(other.v[i]);    
}

template<>
void Vector<Polynomial>::sub(const Vector<Polynomial>& other){
  for(int i = 0; i < N; i++)
    v[i].sub(other.v[i]);    
}

template<>
void Vector<Polynomial>::mul(const Polynomial& other){
  for(int i = 0; i < N; i++)
    v[i].mul(other);    
}
/*
template<>
void Vector<Polynomial>::mul(const double alpha){
  for(int i = 0; i < N; i++)
    v[i].mul(alpha);  
}
*/
template<>
string Vector<Polynomial>::toString(void) const{
  stringstream s; 

  s << endl;

  for(int i = 0; i < N; i++)
    s << "[" << v[i].toString() << "]" << endl;

  return s.str();
}
