#include "Exception.h"
#include "ReferenceSpaceManager.h"

using namespace std;

const size_t ReferenceSpaceManager::nSpace = 9;
vector<ReferenceSpace*> ReferenceSpaceManager::refSpace(nSpace, NULL);

ReferenceSpaceManager::ReferenceSpaceManager(void){
}

ReferenceSpaceManager::~ReferenceSpaceManager(void){
}

void ReferenceSpaceManager::init(int elementType){
  // Warning: no elementType == 0
  //  --> refSpace[0] will be alwys null --> not realy important

  switch(elementType){
  case 1: throw Exception("ReferenceSpace for Points not implemented");

  case 2: refSpace[elementType] = new LineReferenceSpace; break;
  case 3: refSpace[elementType] = new TriReferenceSpace;  break;
  case 4: refSpace[elementType] = new QuadReferenceSpace; break;
  case 5: refSpace[elementType] = new TetReferenceSpace;  break;
  case 6: refSpace[elementType] = new PyrReferenceSpace;  break;
  case 7: refSpace[elementType] = new PriReferenceSpace;  break;
  case 8: refSpace[elementType] = new HexReferenceSpace;  break;

  case 9:  throw Exception("ReferenceSpace for POLYG not implemented");
  case 10: throw Exception("ReferenceSpace for POLYH not implemented");
  case 11: throw Exception("ReferenceSpace for XFEM not implemented");
  }
}

void ReferenceSpaceManager::clear(void){
  for(size_t i = 0; i < nSpace; i++)
    if(refSpace[i])
      delete refSpace[i];

  for(size_t i = 0; i < nSpace; i++)
    refSpace[i] = NULL;
}
