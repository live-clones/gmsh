#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include "Basis.h"
#include "GroupOfElement.h"
#include "MElement.h"

/** 
    @class FunctionSpace
    @brief A Function Space
    
    This class represents a Function Space

    @todo Hybrid Mesh
*/

class FunctionSpace{
 private:
  const Basis* basis;
  const GroupOfElement* goe;

  int fPerVertex;
  int fPerEdge;
  int fPerFace;
  int fPerCell;

 public:
   FunctionSpace(const GroupOfElement& goe, 
		 int basisType, int order);

  ~FunctionSpace(void);

  const GroupOfElement& getSupport(void) const;
  const Basis&          getBasis(MElement& element) const;

  int getNFunctionPerVertex(MElement& element) const;
  int getNFunctionPerEdge(MElement& element) const;
  int getNFunctionPerFace(MElement& element) const;
  int getNFunctionPerCell(MElement& element) const;
};

//////////////////////
// Inline Functions //
//////////////////////

inline const GroupOfElement& FunctionSpace::getSupport(void) const{
  return *goe;
}

inline const Basis& FunctionSpace::getBasis(MElement& element) const{
  return *basis;
}

inline int FunctionSpace::getNFunctionPerVertex(MElement& element) const{
  return fPerVertex;
}

inline int FunctionSpace::getNFunctionPerEdge(MElement& element) const{
  return fPerEdge;
}

inline int FunctionSpace::getNFunctionPerFace(MElement& element) const{
  return fPerFace;
}

inline int FunctionSpace::getNFunctionPerCell(MElement& element) const{
  return fPerCell;
}

#endif
