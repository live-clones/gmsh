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

  stream << "Vertex Based:" << endl;
  for(int i = 0; i < nVertex; i++)
    stream << " f("  << i << ") = " << endl
	   << "  [ " <<(*(*node)[i])[0].toString() << " ]" << endl
	   << "  [ " <<(*(*node)[i])[1].toString() << " ]" << endl
	   << "  [ " <<(*(*node)[i])[2].toString() << " ]" << endl;

  stream << "Edge Based:" << endl;
  for(int i = 0; i < nEdge; i++)
    for(int j = 0; j < nEdgeClosure; j++)
      stream << " f_"  << j << "(" << i << ") = " << endl 
	     << "  [ " << (*(*(*edge)[j])[i])[0].toString() << " ]" << endl
	     << "  [ " << (*(*(*edge)[j])[i])[1].toString() << " ]" << endl
	     << "  [ " << (*(*(*edge)[j])[i])[2].toString() << " ]" << endl;

  stream << "Face Based:" << endl;
  for(int i = 0; i < nFace; i++)
    for(int j = 0; j < nFaceClosure; j++)
      stream << " f_"  << j << "(" << i << ") = " << endl
	     << "  [ " << (*(*(*face)[j])[i])[0].toString() << " ]" << endl
	     << "  [ " << (*(*(*face)[j])[i])[1].toString() << " ]" << endl
	     << "  [ " << (*(*(*face)[j])[i])[2].toString() << " ]" << endl;
  
  stream << "Cell Based:" << endl;
  for(int i = 0; i < nCell; i++)
    stream << " f("  << i << ") = " 
	   << "  [ " << (*(*cell)[i])[0].toString() << " ]" << endl
	   << "  [ " << (*(*cell)[i])[1].toString() << " ]" << endl
	   << "  [ " << (*(*cell)[i])[2].toString() << " ]" << endl;

  return stream.str();
}
