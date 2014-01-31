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
*/

class Mesh;
class GroupOfElement;

class FunctionSpace{
 protected:
  // Number of possible geomtrical topologies //
  static const size_t nGeoType;
  static bool once;

 protected:
  // Geometry //
  const Mesh*     mesh;
  const GroupOfElement* goe;

  // Basis //
  std::vector<const Basis*> basis;

  size_t fPerVertex;
  size_t fPerEdge;
  size_t fPerFace;
  size_t fPerCell;

  // Differential From & Order //
  bool   scalar;
  size_t form;
  size_t order;

  // Dofs //
  std::set<Dof>                  dof;
  std::vector<std::vector<Dof> > group;

 public:
  virtual ~FunctionSpace(void);

  const Basis& getBasis(const MElement& element) const;
  const Basis& getBasis(size_t i) const;

  const GroupOfElement& getSupport(void) const;

  bool   isScalar(void) const;
  size_t getForm(void)  const;
  size_t getOrder(void) const;

  std::vector<Dof> getUnorderedKeys(const MElement& element) const;
  std::vector<Dof> getKeys(const MElement& element) const;

  void getKeys(const GroupOfElement& goe, std::set<Dof>& dof) const;

  const std::set<Dof>&                  getAllDofs(void)   const;
  const std::vector<std::vector<Dof> >& getAllGroups(void) const;

 protected:
  FunctionSpace(void);

  void build(const GroupOfElement& goe, std::string family);
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

inline const Basis& FunctionSpace::getBasis(const MElement& element) const{
  return *basis[element.getType()];
}

inline const Basis& FunctionSpace::getBasis(size_t i) const{
  return *basis[i];
}

inline const GroupOfElement& FunctionSpace::getSupport(void) const{
  return *goe;
}

inline bool FunctionSpace::isScalar(void) const{
  return scalar;
}

inline size_t FunctionSpace::getForm(void) const{
  return form;
}

inline size_t FunctionSpace::getOrder(void) const{
  return order;
}

inline const std::set<Dof>& FunctionSpace::getAllDofs(void) const{
  return dof;
}

inline const std::vector<std::vector<Dof> >&
FunctionSpace::getAllGroups(void) const{
  return group;
}

#endif
