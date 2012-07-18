#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <map>
#include "MElement.h"
#include "Jacobian.h"
#include "Basis.h"

/** 
    @class FunctionSpace
    @brief A Function Space

    This class represents a Function Space

    @todo Add interpolation @n
    --> inheritance: FunctionSpaceScalar & FunctionSapceVector @n
    "double or fullVector" interpolate(Element, pyhsical coordinate, coef) @n
    "double or fullVector" interpolate(Element, ref coordinate     , coef) @n
    "double or fullVector" interpolate(physical coordinate, coef) --> use octree?? @n    
*/

class FunctionSpace{
 private:
  
  class ElementComparator{
  public:
    bool operator()(const MElement* a, const MElement* b) const;
  };
  
  std::map<MElement*, Basis*, ElementComparator>* ebLookUp; // Element to Basis Lookup

 public:
   FunctionSpace(void);
  ~FunctionSpace(void);

  void associate(MElement& element, Basis& basis);
  void associate(int physical, Basis& basis);
  
  Basis& getBasis(MElement& element) const;
};

//////////////////////
// Inline Functions //
//////////////////////

inline void FunctionSpace::associate(MElement& element, Basis& basis){
  ebLookUp->insert(std::pair<MElement*, Basis*>(&element, &basis));
}

inline Basis& FunctionSpace::getBasis(MElement& element) const{
  return *(ebLookUp->find(&element)->second);
}

inline bool FunctionSpace::ElementComparator::operator()
(const MElement* a, const MElement* b) const{
  return a->getNum() < b->getNum();
}

#endif
