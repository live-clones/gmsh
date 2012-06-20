#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <map>
#include "Element.h"
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
    bool operator()(const Element* a, const Element* b) const;
  };

  std::map<Element*, Basis*, ElementComparator>* ebLookUp; // Element to Basis Lookup

 public:
   FunctionSpace(void);
  ~FunctionSpace(void);

  void associate(Element& element, Basis& basis);
  void associate(int physical, Basis& basis);
  
  Basis& getBasis(Element& element) const;
};

//////////////////////
// Inline Functions //
//////////////////////

inline void FunctionSpace::associate(Element& element, Basis& basis){
  ebLookUp->insert(std::pair<Element*, Basis*>(&element, &basis));
}

inline Basis& FunctionSpace::getBasis(Element& element) const{
  return *(ebLookUp->find(&element)->second);
}

inline bool FunctionSpace::ElementComparator::operator()
(const Element* a, const Element* b) const{
  return a->getId() < b->getId();
}

#endif
