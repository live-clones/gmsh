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
  unsigned int i = 0;

  stream << "Vertex Based:" << endl;
  for(; i < nVertex; i++)
    stream << "f("   << i + 1                              << ") = " << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[2].toString() << " ]"   << endl;

  stream << "Edge Based:"   << endl;
  for(; i < nVertex + nEdge; i++)
    stream << " f("  << i + 1                              << ") = " << endl 
	   << "\t[ " << (*(*(*basis)[0])[i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[2].toString() << " ]"   << endl;

  stream << "Face Based:"   << endl;
  for(; i < nVertex + nEdge + nFace; i++)
    stream << " f("  << i + 1                              << ") = " << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[2].toString() << " ]"   << endl;
  
  stream << "Cell Based:"   << endl;
  for(; i < nVertex + nEdge + nFace + nCell; i++)
    stream << " f("  << i + 1                              << ") = " << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*(*(*basis)[0])[i])[2].toString() << " ]"   << endl;

  return stream.str();
}
