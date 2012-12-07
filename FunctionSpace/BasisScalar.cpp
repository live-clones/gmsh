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
    stream << " # " << i + 1         << "\t"
	   << "f("  << i + 1         << ") = "
	   << (*node)[i]->toString() << endl;

  stream << "Edge Based:" << endl;
  for(int i = 0; i < nEdge; i++)
    for(int j = 0; j < nEdgeClosure; j++)
      stream << " # " << i + 1 + nVertex     << "\t"
	     << "f_"  << j << "(" << i + 1   << ") = " 
	     << (*(*edge)[j])[i]->toString() << endl;

  stream << "Face Based:" << endl;
  for(int i = 0; i < nFace; i++)
    for(int j = 0; j < nFaceClosure; j++)
      stream << " # " << i + 1 + nVertex + nEdge << "\t"
	     << "f_"  << j << "(" << i + 1       << ") = " 
	     << (*(*face)[j])[i]->toString()     << endl;

  stream << "Cell Based:" << endl;
  for(int i = 0; i < nCell; i++)
    stream << " # " << i + 1 + nVertex + nEdge + nFace << "\t"
	   << "f("  << i + 1                           << ") = " 
	   << (*cell)[i]->toString()                   << endl;

  return stream.str();
}
