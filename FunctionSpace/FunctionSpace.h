#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <map>
#include <vector>

#include "BasisLocal.h"

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

    This is the @em common @em interface of
    all Function Spaces.@n

    A FunctionSpace is defined on a @em support,
    which is a collection of MElement%s (GroupOfElement).@n

    Those MElement%s @em must belong to the @em same Mesh.

    A FunctionSpace is also responsible for the generation of all
    the Dof%s and GroupOfDof%s related to its geometrical @em Support.

    @todo
    Allow Hybrid Mesh
*/

class FunctionSpace{
 protected:
  // Geometry //
  const Mesh*           mesh;
  const GroupOfElement* goe;

  // Basis //
  const BasisLocal* localBasis;
  unsigned int      fPerVertex;
  unsigned int      fPerEdge;
  unsigned int      fPerFace;
  unsigned int      fPerCell;
  unsigned int      type;

  // Dofs //
  std::set<const Dof*, DofComparator>*     dof;
  std::vector<GroupOfDof*>*                group;
  std::map<
    const MElement*,
    const GroupOfDof*, ElementComparator>* eToGod;

 public:
  virtual ~FunctionSpace(void);

  const GroupOfElement& getSupport(void) const;
  unsigned int          getOrder(void) const;
  unsigned int          getType(void) const;
  bool                  isScalar(void) const;

  unsigned int getNFunctionPerVertex(const MElement& element) const;
  unsigned int getNFunctionPerEdge(const MElement& element) const;
  unsigned int getNFunctionPerFace(const MElement& element) const;
  unsigned int getNFunctionPerCell(const MElement& element) const;

  std::vector<Dof> getKeys(const MElement& element) const;
  std::vector<Dof> getKeys(const MVertex& vertex) const;
  std::vector<Dof> getKeys(const MEdge& edge) const;
  std::vector<Dof> getKeys(const MFace& face) const;

  const std::vector<const Dof*>   getAllDofs(void) const;
  const std::vector<GroupOfDof*>& getAllGroups(void) const;

  const GroupOfDof& getGoDFromElement(const MElement& element) const;

  unsigned int getNOrientation(void) const;
  unsigned int getOrientation(const MElement& element) const;

  unsigned int dofNumber(void) const;
  unsigned int groupNumber(void) const;

 protected:
  // Init
  FunctionSpace(void);

  void build(const GroupOfElement& goe,
	     int basisType, int order);

  // Dof
  void buildDof(void);
  void insertDof(Dof& d, GroupOfDof* god);
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

   @fn FunctionSpace::getOrder
   @return Return the @em order
   of this FunctionSpace
   **

   @fn FunctionSpace::getType
   @return Return the @em type of
   the Basis functions composing
   this Function Space.
   @see Basis::getType()
   **

   @fn FunctionSpace::isScalar
   @return Returns:
   @li @c true, if this FunstionSpace is scalar
   @li @c flase, otherwise
   @see Basis::isScalar()
   **

   @fn FunctionSpace::getNFunctionPerVertex
   @param element A MElement of the support
   @return Returns the number of @em Vertex Based
   Basis Functions, defined on the given element
   **

   @fn FunctionSpace::getNFunctionPerEdge
   @param element A MElement of the support
   @return Returns the number of @em Edge Based
   Basis Functions, defined on the given element
   **

   @fn FunctionSpace::getNFunctionPerFace
   @param element A MElement of the support
   @return Returns the number of @em Face Based
   Basis Functions, defined on the given element
   **

   @fn FunctionSpace::getNFunctionPerCell
   @param element A MElement of the support
   @return Returns the number of @em Cell Based
   Basis Functions, defined on the given element
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
   @return Returns all the @em Dof%s associated to every Element%s
   of this FunctionSpace @em support
   **

   @fn FunctionSpace::getAllGroups
   @return Returns all the @em GroupOfDof%s associated to every Element%s
   of this FunctionSpace @em support
   **

   @fn FunctionSpace::getGoDFromElement
   @param element An Element of the FunctionSpace Support
   @return Returns the @em GroupOfDof%s associated to
   the given @em Element
   @note
   If the given Element is not in the FunctionSpace Support,
   an Exception is thrown
   **

   @fn FunctionSpace::getNOrientation
   @return Returns the number of
   @em orientations of the
   FunctionSpace reference space
   @todo Multiple basis
   **

   @fn FunctionSpace::getOrientation
   @param element A MElement
   @return Returns a number charaterizing
   the @em orientation of the given element
   @todo Multiple basis
   **

   @fn FunctionSpace::dofNumber
   @return Returns the number of Dof%s
   given by FunctionSpace::getAllDofs()
   **

   @fn FunctionSpace::groupNumber
   @return Returns the number of GroupOfDof%s
   given by FunctionSpace::getAllGroups()
   **
*/


//////////////////////
// Inline Functions //
//////////////////////

inline const GroupOfElement& FunctionSpace::getSupport(void) const{
  return *goe;
}

inline unsigned int FunctionSpace::getOrder(void) const{
  return (unsigned int)(localBasis->getOrder());
}

inline unsigned int FunctionSpace::getType(void) const{
  return type;
}

inline bool FunctionSpace::isScalar(void) const{
  return localBasis->isScalar();
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

inline unsigned int FunctionSpace::getNOrientation(void) const{
  return localBasis->getNOrientation();
}

inline unsigned int FunctionSpace::getOrientation(const MElement& element) const{
  return localBasis->getOrientation(element);
}

inline unsigned int FunctionSpace::dofNumber(void) const{
  return dof->size();
}

inline unsigned int FunctionSpace::groupNumber(void) const{
  return group->size();
}

inline const std::vector<const Dof*> FunctionSpace::getAllDofs(void) const{
  return std::vector<const Dof*>(dof->begin(), dof->end());
}

inline const std::vector<GroupOfDof*>& FunctionSpace::getAllGroups(void) const{
  return *group;
}

#endif
