#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <map>
#include <vector>

#include "Dof.h"
#include "Mesh.h"
#include "Basis.h"
#include "MElement.h"
#include "GroupOfElement.h"

/**
    @interface FunctionSpace
    @brief Common Interface of all Function Spaces

    This is the common interface of all Function Spaces.

    A FunctionSpace is defined on a support,
    which is a collection of MElement%s (GroupOfElement).

    Those MElement%s must belong to the same Mesh.

    A FunctionSpace is also responsible for the generation of all
    the Dof%s related to its geometrical Support.

    @todo
    Allow Hybrid Mesh
*/

class Mesh;
class GroupOfElement;

class FunctionSpace{
 protected:
  // Geometry //
  const Mesh*     mesh;
  GroupOfElement* goe;

  // Basis //
  std::vector<const Basis*> basis;
  std::vector<size_t>       fPerVertex;
  std::vector<size_t>       fPerEdge;
  std::vector<size_t>       fPerFace;
  std::vector<size_t>       fPerCell;

  // Scalar Field ? //
  bool scalar;

  // Dofs //
  std::set<Dof>                  dof;
  std::vector<std::vector<Dof> > group;

 public:
  virtual ~FunctionSpace(void);

  const std::vector<const Basis*>& getBasis(const MElement& element) const;
  const Basis&                     getBasis(size_t i) const;

  GroupOfElement& getSupport(void) const;
  bool            isScalar(void) const;

  std::vector<Dof> getUnorderedKeys(const MElement& element) const;
  std::vector<Dof> getKeys(const MElement& element) const;

  void getKeys(const GroupOfElement& goe, std::set<Dof>& dof) const;

  const std::set<Dof>&                  getAllDofs(void)   const;
  const std::vector<std::vector<Dof> >& getAllGroups(void) const;

 protected:
  FunctionSpace(void);

  void build(GroupOfElement& goe, const Basis& basis);
  void buildDof(void);
};


/**
   @internal
   @fn FunctionSpace::FunctionSpace
   Instatiate a new FunctionSpace
   @endinternal
   **

   @fn FunctionSpace::~FunctionSpace
   Deletes this FunctionSpace
   **

   @fn FunctionSpace::getSupport
   @return Returns the support of this
   FunctionSpace
   **

   @fn FunctionSpace::isScalar
   @return Returns:
   @li true, if this FunstionSpace is scalar
   @li flase, otherwise
   **

   @fn vector<Dof> FunctionSpace::getKeys(const MElement& element) const
   @param element A MElement
   @return Returns all the Dof%s associated to the given MElement
   **

   @fn vector<Dof> FunctionSpace::getKeys(const MVertex& vertex) const
   @param vertex A MVertex
   @return Returns all the Dof%s associated to the given MVertex
   **

   @fn vector<Dof> FunctionSpace::getKeys(const MEdge& edge) const
   @param edge A MEdge
   @return Returns all the Dof%s associated to the given MEdge
   **

   @fn vector<Dof> FunctionSpace::getKeys(const MFace& face) const
   @param face A MFace
   @return Returns all the Dof%s associated to the given MFace
   **

   @fn FunctionSpace::getAllDofs
   @return Returns all the Dof%s associated to every Element%s
   of this FunctionSpace support
   **

   @fn FunctionSpace::getAllGroups
   @return Returns all the Dof%s associated to every Element%s
   of this FunctionSpace support
*/


//////////////////////
// Inline Functions //
//////////////////////

inline const std::vector<const Basis*>&
FunctionSpace::getBasis(const MElement& element) const{
  return basis;
}

inline const Basis& FunctionSpace::getBasis(size_t i) const{
  return *basis[i];
}

inline GroupOfElement& FunctionSpace::getSupport(void) const{
  return *goe;
}

inline bool FunctionSpace::isScalar(void) const{
  return scalar;
}

inline const std::set<Dof>& FunctionSpace::getAllDofs(void) const{
  return dof;
}

inline const std::vector<std::vector<Dof> >&
FunctionSpace::getAllGroups(void) const{
  return group;
}

#endif
