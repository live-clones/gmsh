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

  for(int i = 0; i < nVertex; i++)
    stream << "f(" << i << ") = " << endl
	   << "[ " <<(*(*node)[i])[0].toString() << " ]" << endl
	   << "[ " <<(*(*node)[i])[1].toString() << " ]" << endl
	   << "[ " <<(*(*node)[i])[2].toString() << " ]" << endl;

  for(int i = 0; i < nEdge; i++)
    stream << "f(" << i + nVertex << ") = " << endl 
	   << "[ " << (*(*(*edge)[0])[i])[0].toString() << " ]" << endl
	   << "[ " << (*(*(*edge)[0])[i])[1].toString() << " ]" << endl
	   << "[ " << (*(*(*edge)[0])[i])[2].toString() << " ]" << endl;

  for(int i = 0; i < nFace; i++)
    stream << "f(" << i + nVertex + nEdge << ") = " << endl 
	   << "[ " << (*(*(*face)[0])[i])[0].toString() << " ]" << endl
	   << "[ " << (*(*(*face)[0])[i])[1].toString() << " ]" << endl
	   << "[ " << (*(*(*face)[0])[i])[2].toString() << " ]" << endl;

  for(int i = 0; i < nCell; i++)
    stream << "f(" << i + nVertex + nEdge + nFace << ") = " 
	   << "[ " << (*(*cell)[i])[0].toString() << " ]" << endl
	   << "[ " << (*(*cell)[i])[1].toString() << " ]" << endl
	   << "[ " << (*(*cell)[i])[2].toString() << " ]" << endl;

  return stream.str();
}
