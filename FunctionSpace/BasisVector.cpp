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
    stream << "[" << (*basis)[i]->at(0).toString() << "]" << endl
	   << "[" << (*basis)[i]->at(1).toString() << "]" << endl
	   << "[" << (*basis)[i]->at(2).toString() << "]" << endl
	   << endl;

  return stream.str();
}
