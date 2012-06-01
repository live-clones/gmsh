#include <sstream>
#include "Vector.h"

using namespace std;

template<>
void Vector<double>::allToZero(void){
  for(int i = 0; i < N; i++)
    v[i] = 0.0;
}

template<>
void Vector<double>::add(const Vector<double>& b){
  if(this->N != b.N)
    throw Exception("Vectors must be with of the same size");

  for(int i = 0; i < N; i++)
    v[i] += b.v[i];  
}

template<>
void Vector<double>::sub(const Vector<double>& b){
  if(this->N != b.N)
    throw Exception("Vectors must be with of the same size");

  for(int i = 0; i < N; i++)
    v[i] -= b.v[i];  
}

template<>
void Vector<double>::mul(const double& alpha){
  for(int i = 0; i < N; i++)
    v[i] *= alpha;  
}

template<>
string Vector<double>::toString(void) const{
  stringstream s;
  
  for(int i = 0; i < N; i++)
    s << scientific << showpos << v[i] << endl;

  return s.str();
}
