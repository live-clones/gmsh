#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <map>

#include "Dof.h"
#include "GroupOfDof.h"

#include "Basis.h"
#include "GroupOfElement.h"
#include "MElement.h"

/** 
    @class FunctionSpace
    @brief A Function Space
    
    This class represents a Function Space

    @todo 
    Hybrid Mesh@n
*/

class ElementComparator;

class FunctionSpace{
 private:
  friend class DofManager;

  const Basis* basis;
  const GroupOfElement* goe;

  std::map<const MElement*, const GroupOfDof*, ElementComparator>* eToGoD;

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

 private:
  void associate(const MElement& element, const GroupOfDof& god);
};

class ElementComparator{
 public:
  bool operator()(const MElement* a, const MElement* b) const;
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

inline void FunctionSpace::associate(const MElement& element, const GroupOfDof& god){
  //return fPerCell;
}

inline bool ElementComparator::operator()(const MElement* a, const MElement* b) const{
  return a->getNum() < b->getNum();
}

#endif
