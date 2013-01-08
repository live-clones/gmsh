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
  unsigned int i = 0;
  const unsigned int refSpace = 0;

  stream << "Vertex Based:" << endl;
  for(; i < nVertex; i++)
    stream << "f("  << i + 1                       << ") = "
	   << (*(*basis)[refSpace])[i]->toString() << endl;

  stream << "Edge Based:"   << endl;
  for(; i < nVertex + nEdge; i++)
    stream << "f(" << i + 1                        << ") = " 
	   << (*(*basis)[refSpace])[i]->toString() << endl;

  stream << "Face Based:"   << endl;
  for(; i < nVertex + nEdge + nFace; i++)
    stream << "f(" << i + 1                        << ") = " 
	   << (*(*basis)[refSpace])[i]->toString() << endl;

  stream << "Cell Based:"   << endl;
  for(; i < nVertex + nEdge + nFace + nCell; i++)
    stream << "f("  << i + 1                       << ") = " 
	   << (*(*basis)[refSpace])[i]->toString() << endl;

  return stream.str();
}
