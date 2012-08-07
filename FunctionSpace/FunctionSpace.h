#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <vector>

#include "Basis.h"
#include "Dof.h"
#include "GroupOfElement.h"
#include "MElement.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MFace.h"

/** 
    @class FunctionSpace
    @brief A Function Space
    
    This class represents a Function Space

    @todo 
    Hybrid Mesh@n
*/

class FunctionSpace{
 protected:
  const Basis* basis;
  int fPerVertex;
  int fPerEdge;
  int fPerFace;
  int fPerCell;
  int type;

  const GroupOfElement* goe;
  int nTotVertex;

 public:
  FunctionSpace(const GroupOfElement& goe, 
		int basisType, int order);

  virtual ~FunctionSpace(void);

  const GroupOfElement& getSupport(void) const;
  const Basis&          getBasis(const MElement& element) const;
  int                   getType(void) const;

  int getNFunctionPerVertex(const MElement& element) const;
  int getNFunctionPerEdge(const MElement& element) const;
  int getNFunctionPerFace(const MElement& element) const;
  int getNFunctionPerCell(const MElement& element) const;

  std::vector<Dof> getKeys(const MElement& element) const;
  std::vector<Dof> getKeys(const MVertex& element) const;
  std::vector<Dof> getKeys(const MEdge& element) const;
  std::vector<Dof> getKeys(const MFace& element) const;

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
