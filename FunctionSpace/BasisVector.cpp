#include <sstream>
#include "BasisVector.h"

using namespace std;

BasisVector::BasisVector(void){
  scalar = false;
}

BasisVector::~BasisVector(void){
}

string BasisVector::toString(void) const{
  stringstream stream;

  for(int i = 0; i < size; i++)
    stream << "[" << "]" << endl
	   << "[" << "]" << endl
	   << "[" << "]" << endl
	   << endl;

  return stream.str();
}
