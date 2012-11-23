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

  stream << "Vertex Based:" << endl;
  for(int i = 0; i < nVertex; i++)
    stream << " f(" << i << ") = "
	   << (*node)[i]->toString() << endl;

  stream << "Edge Based:" << endl;
  for(int i = 0; i < nEdge; i++)
    for(int j = 0; j < nEdgeClosure; j++)
      stream << " f_" << j << "(" << i << ") = " 
	     << (*(*edge)[j])[i]->toString() << endl;

  stream << "Face Based:" << endl;
  for(int i = 0; i < nFace; i++)
    for(int j = 0; j < nFaceClosure; j++)
      stream << " f_" << j << "(" << i << ") = " 
	     << (*(*face)[j])[i]->toString() << endl;

  stream << "Cell Based:" << endl;
  for(int i = 0; i < nCell; i++)
    stream << " f(" << i << ") = " 
	   << (*cell)[i]->toString() << endl;

  return stream.str();
}
