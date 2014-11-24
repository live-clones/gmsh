#ifndef _FUNCTIONSPACE_H_
#define _FUNCTIONSPACE_H_

#include <map>
#include <vector>

#include "Dof.h"
#include "Mesh.h"
#include "Basis.h"
#include "MElement.h"
#include "Exception.h"
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
  // Number of possible geomtrical topologies & Dof Type offset //
  static const size_t nGeoType;
  static       size_t nxtOffset;

 protected:
  // Offset //
  size_t offset;

  // Mesh //
  const Mesh* mesh;

  // Basis //
  std::vector<const Basis*> basis;

  std::vector<size_t> fPerVertex;
  std::vector<size_t> fPerEdge;
  std::vector<size_t> fPerFace;
  std::vector<size_t> fPerCell;

  // Differential From & Order //
  bool   scalar;
  size_t form;
  size_t order;

  // Rejected Dofs //
  std::set<Dof> rejected;

  // Dofs //
  std::map<size_t, std::vector<std::vector<Dof> > > dof;

 public:
  virtual ~FunctionSpace(void);

  bool   isScalar(void) const;
  size_t getForm(void)  const;
  size_t getOrder(void) const;

  const Basis& getBasis(const MElement& element) const;
  const Basis& getBasis(size_t eType)            const;

  void getKeys(const MElement& element, std::vector<Dof>& dof) const;
  void getKeys(const GroupOfElement& goe, std::set<Dof>& dof)  const;
  const std::vector<std::vector<Dof> >& getKeys(const GroupOfElement& goe)const;

 protected:
  FunctionSpace(void);
  void build(const std::vector<const GroupOfElement*>& goe,
             const std::vector<const GroupOfElement*>& exl,
             std::string family);

  void getBases(const GroupOfElement& goe, std::string family);
  void getMyDof(const GroupOfElement& goe);
  void getRejec(const GroupOfElement& goe);

  size_t findMaxType(void);

  void getUnorderedKeys(const MElement& element, std::vector<Dof>& dof) const;
  void markKeys(std::vector<Dof>& dof) const;
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

   @fn FunctionSpace::isScalar
   @return Returns:
   @li true, if this FunstionSpace is scalar
   @li flase, otherwise
   **

   @fn FunctionSpace::getForm
   @return Returns this FunctionSpace differential form (0, 1, 2 or 3)
   **

   @fn FunctionSpace::getOrder
   @return Returns this FunctionSpace order
   **

   @fn FunctionSpace::getBasis(const MElement& element) const
   @param element A MElement
   @return Returns the Basis associated to the given element
   **

   @fn FunctionSpace::getBasis(size_t eType) const
   @param eType A geomtrical element type tag
   @return Returns the Basis associated to the given geomtrical element type tag
   **

   @fn void FunctionSpace::getKeys(const MElement&,std::vector<Dof>&) const
   @param element A MElement
   @param dof A vector of Dof%s

   Populates the given vector with the Dof%s associated to the given MElement
   **

   @fn void FunctionSpace::getKeys(const GroupOfElement&, std::set<Dof>&) const
   @param goe A GroupOfElement
   @param dof A set of Dof%s

   Populates the given set with the Dof%s associated to the MElement%s
   of the given GroupOfElement
   **

   @fn const std::vector<std::vector<Dof> >& FunctionSpace::getKeys(const GroupOfElement&) const
   @param goe A GroupOfElement
   @return Returns a vector of vector of Dof such that:
   dof[i][j] is the jth Dof of the ith element of the given GroupOfElement
*/

//////////////////////
// Inline Functions //
//////////////////////

inline bool FunctionSpace::isScalar(void) const{
  return scalar;
}

inline size_t FunctionSpace::getForm(void) const{
  return form;
}

inline size_t FunctionSpace::getOrder(void) const{
  return order;
}

inline const Basis& FunctionSpace::getBasis(const MElement& element) const{
  return *basis[element.getType()];
}

inline const Basis& FunctionSpace::getBasis(size_t eType) const{
  if(eType >= basis.size())
    throw Exception("FunctionSpace::getBasis() -- unknown geometrical type %u",
                    eType);

  return *basis[eType];
}

#endif
