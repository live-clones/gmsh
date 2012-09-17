#include <sstream>
#include "BasisScalar.h"

using namespace std;

BasisScalar::BasisScalar(void){
  scalar = true;
}

BasisScalar::~BasisScalar(void){
}

string BasisScalar::toString(void) const{
  stringstream stream;

  for(int i = 0; i < size; i++)
    stream << (*basis)[i]->toString() << endl;

  return stream.str();
}
