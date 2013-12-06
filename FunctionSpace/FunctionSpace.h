#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <map>
#include <vector>

#include "Basis.h"

#include "Comparators.h"
#include "Dof.h"
#include "GroupOfDof.h"

#include "Mesh.h"
#include "GroupOfElement.h"

#include "MElement.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MFace.h"

/**
    @interface FunctionSpace
    @brief Common Interface of all Function Spaces

    This is the common interface of all Function Spaces.

    A FunctionSpace is defined on a support,
    which is a collection of MElement%s (GroupOfElement).

    Those MElement%s must belong to the same Mesh.

    A FunctionSpace is also responsible for the generation of all
    the Dof%s and GroupOfDof%s related to its geometrical Support.

    @todo
    Allow Hybrid Mesh
    Remove call to GroupOfElement::orientAllElements()
*/

class Mesh;
class GroupOfElement;

class FunctionSpace{
 protected:
  // Geometry //
  const Mesh*     mesh;
  GroupOfElement* goe;

  // Basis //
  std::vector<const Basis*>* basis;
  size_t nBasis;
  size_t fPerVertex;
  size_t fPerEdge;
  size_t fPerFace;
  size_t fPerCell;

  // Scalar Field ? //
  bool scalar;

  // Dofs //
  std::set<Dof>*            dof;
  std::vector<GroupOfDof*>* group;
  std::map<
    const MElement*,
    const GroupOfDof*, ElementComparator>* eToGod;

 public:
  virtual ~FunctionSpace(void);

  const Basis& getBasis(const MElement& element) const;
  const Basis& getBasis(size_t i) const;

  GroupOfElement& getSupport(void) const;
  bool            isScalar(void) const;

  std::vector<Dof> getKeys(const MElement& element) const;
  std::vector<Dof> getKeys(const MVertex& vertex) const;
  std::vector<Dof> getKeys(const MEdge& edge) const;
  std::vector<Dof> getKeys(const MFace& face) const;

  const std::vector<Dof>          getAllDofs(void) const;
  const std::vector<GroupOfDof*>& getAllGroups(void) const;

  const GroupOfDof& getGoDFromElement(const MElement& element) const;

  size_t dofNumber(void) const;
  size_t groupNumber(void) const;

 protected:
  // Init
  FunctionSpace(void);

  void build(GroupOfElement& goe,
             const Basis& basis);

  // Dof
  void buildDof(void);
  void insertDof(Dof& d,
                 std::vector<const Dof*>& trueDof,
                 size_t index);
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

   @fn FunctionSpace::getBasis
   @param element A MElement
   @return Returns the Basis associated to the given MElement

   @fn FunctionSpace::getSupport
   @return Returns the support of this FunctionSpace
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
   @return Returns all the GroupOfDof%s associated to every Element%s
   of this FunctionSpace support
   **

   @fn FunctionSpace::getGoDFromElement
   @param element An Element of the FunctionSpace Support
   @return Returns the GroupOfDof%s associated to the given Element

   If the given Element is not in the FunctionSpace Support,
   an Exception is thrown
   **

   @fn FunctionSpace::dofNumber
   @return Returns the number of Dof%s given by FunctionSpace::getAllDofs()
   **

   @fn FunctionSpace::groupNumber
   @return Returns the number of GroupOfDof%s
   given by FunctionSpace::getAllGroups()
   **
*/

#endif
