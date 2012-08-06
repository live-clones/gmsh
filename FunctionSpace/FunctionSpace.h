#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <vector>

#include "Basis.h"
#include "GroupOfElement.h"
#include "MElement.h"
#include "Dof.h"
#include "DofManager.h"

/** 
    @class FunctionSpace
    @brief A Function Space
    
    This class represents a Function Space

    @todo 
    Hybrid Mesh@n
*/

class ElementComparator;
class DofManager;

class FunctionSpace{
 protected:
  const Basis*          basis;
  const GroupOfElement* goe;
  const DofManager*     dofM;

  int fPerVertex;
  int fPerEdge;
  int fPerFace;
  int fPerCell;

  int type;

 public:
  FunctionSpace(const GroupOfElement& goe, 
		int basisType, int order);

  virtual ~FunctionSpace(void);

  const GroupOfElement& getSupport(void) const;
  const Basis&          getBasis(const MElement& element) const;
  int                   getType(void) const;

  void                    associate(const DofManager& dofM);
  const std::vector<Dof*> getKeys(const MElement& element) const;

  int getNFunctionPerVertex(const MElement& element) const;
  int getNFunctionPerEdge(const MElement& element) const;
  int getNFunctionPerFace(const MElement& element) const;
  int getNFunctionPerCell(const MElement& element) const;

  /*
  void interpolateAtNodes(const MElement& element, 
			  const std::vector<double>& coef,
			  std::vector<double>& nodeValue) const;
  */
};

//////////////////////
// Inline Functions //
//////////////////////

inline const GroupOfElement& FunctionSpace::getSupport(void) const{
  return *goe;
}

inline const Basis& FunctionSpace::getBasis(const MElement& element) const{
  return *basis;
}

inline int FunctionSpace::getType(void) const{
  return type;
}

inline void FunctionSpace::associate(const DofManager& dofM){
  this->dofM = &dofM;
}

inline int FunctionSpace::getNFunctionPerVertex(const MElement& element) const{
  return fPerVertex;
}

inline int FunctionSpace::getNFunctionPerEdge(const MElement& element) const{
  return fPerEdge;
}

inline int FunctionSpace::getNFunctionPerFace(const MElement& element) const{
  return fPerFace;
}

inline int FunctionSpace::getNFunctionPerCell(const MElement& element) const{
  return fPerCell;
}

#endif
