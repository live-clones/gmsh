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

  for(int i = 0; i < nVertex; i++)
    stream << "f(" << i << ") = " 
	   << (*node)[i]->toString() << endl;

  for(int i = 0; i < nEdge; i++)
    stream << "f(" << i + nVertex << ") = " 
	   << (*(*edge)[0])[i]->toString() << endl;

  for(int i = 0; i < nFace; i++)
    stream << "f(" << i + nVertex + nEdge << ") = " 
	   << (*(*face)[0])[i]->toString() << endl;

  for(int i = 0; i < nCell; i++)
    stream << "f(" << i + nVertex + nEdge + nFace << ") = " 
	   << (*cell)[i]->toString() << endl;

  return stream.str();
}
