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
    stream << " # "    << i + 1                              << "\t"
	   << "f("     << i + 1 << ") = "                    << endl
	   << "\t  [ " <<(*(*node)[i])[0].toString() << " ]" << endl
	   << "\t  [ " <<(*(*node)[i])[1].toString() << " ]" << endl
	   << "\t  [ " <<(*(*node)[i])[2].toString() << " ]" << endl;

  stream << "Edge Based:" << endl;
  for(int i = 0; i < nEdge; i++)
    for(int j = 0; j < nEdgeClosure; j++)
      stream << " # "    << i + 1 + nVertex                           << "\t"
	     << " f_"    << j << "(" << i + 1 << ") = "               << endl 
	     << "\t  [ " << (*(*(*edge)[j])[i])[0].toString() << " ]" << endl
	     << "\t  [ " << (*(*(*edge)[j])[i])[1].toString() << " ]" << endl
	     << "\t  [ " << (*(*(*edge)[j])[i])[2].toString() << " ]" << endl;

  stream << "Face Based:" << endl;
  for(int i = 0; i < nFace; i++)
    for(int j = 0; j < nFaceClosure; j++)
      stream << " # "    << i + 1 + nVertex + nEdge                   << "\t"
	     << " f_"    << j << "(" << i + 1 << ") = "               << endl
	     << "\t  [ " << (*(*(*face)[j])[i])[0].toString() << " ]" << endl
	     << "\t  [ " << (*(*(*face)[j])[i])[1].toString() << " ]" << endl
	     << "\t  [ " << (*(*(*face)[j])[i])[2].toString() << " ]" << endl;
  
  stream << "Cell Based:" << endl;
  for(int i = 0; i < nCell; i++)
    stream << " # "    << i + 1 + nVertex + nEdge             << "\t"
	   << " f("    << i + 1 << ") = "                     << endl
	   << "\t  [ " << (*(*cell)[i])[0].toString() << " ]" << endl
	   << "\t  [ " << (*(*cell)[i])[1].toString() << " ]" << endl
	   << "\t  [ " << (*(*cell)[i])[2].toString() << " ]" << endl;

  return stream.str();
}
