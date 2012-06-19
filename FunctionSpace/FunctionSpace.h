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
    "double or fullVector" interpolate(physical coordinate, coef) --> use octree @n
    
*/

class FunctionSpace{
 private:
  class ElementComparator{
    bool operator()(const Element* a, const Element* b) const;
  };

  std::map<Element*, Basis*, ElementComparator>* ETBL; // Element To Basis Lookup

 public:
  
  void associate(Element& element, Basis& basis);
  void associate(int physical, Basis& basis);
  
  Basis& getBasis(Element& element) const;
};

#endif
