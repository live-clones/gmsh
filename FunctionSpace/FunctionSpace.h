#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <vector>

#include "Basis.h"
#include "Dof.h"

#include "Mesh.h"
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
  const Mesh*           mesh;
  const GroupOfElement* goe;
  const Basis*          basis;

  unsigned int fPerVertex;
  unsigned int fPerEdge;
  unsigned int fPerFace;
  unsigned int fPerCell;
  unsigned int type;

 public:
  virtual ~FunctionSpace(void);

  const GroupOfElement& getSupport(void) const;
  int                   getType(void) const;

  unsigned int getNFunctionPerVertex(const MElement& element) const;
  unsigned int getNFunctionPerEdge(const MElement& element) const;
  unsigned int getNFunctionPerFace(const MElement& element) const;
  unsigned int getNFunctionPerCell(const MElement& element) const;

  std::vector<Dof> getKeys(const MElement& element) const;
  std::vector<Dof> getKeys(const MVertex& element) const;
  std::vector<Dof> getKeys(const MEdge& element) const;
  std::vector<Dof> getKeys(const MFace& element) const;

  int getElementType(const Dof& dof) const;
  int getElementGlobalId(const Dof& dof) const;

 protected:
  FunctionSpace();

  void build(const GroupOfElement& goe,
	     int basisType, int order);
};

//////////////////////
// Inline Functions //
//////////////////////

inline const GroupOfElement& FunctionSpace::getSupport(void) const{
  return *goe;
}

inline int FunctionSpace::getType(void) const{
  return type;
}

inline unsigned int FunctionSpace::getNFunctionPerVertex(const MElement& element) const{
  return fPerVertex;
}

inline unsigned int FunctionSpace::getNFunctionPerEdge(const MElement& element) const{
  return fPerEdge;
}

inline unsigned int FunctionSpace::getNFunctionPerFace(const MElement& element) const{
  return fPerFace;
}

inline unsigned int FunctionSpace::getNFunctionPerCell(const MElement& element) const{
  return fPerCell;
}

#endif
