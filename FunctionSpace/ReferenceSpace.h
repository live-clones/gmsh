#ifndef _REFERENCESPACE_H_
#define _REFERENCESPACE_H_

#include <vector>
#include <list>
#include <string>

#include "MElement.h"
#include "fullMatrix.h"
#include "PermutationTree.h"

/**
   @interface ReferenceSpace
   @brief Base interface for all ReferenceSpace%s

   This class represents the notion of Reference Space.@n
   A Reference Space is the set of all the @em permutations
   of the @em reference @em element of a @em particular
   @em geometrical entity.@n
 */

class ReferenceSpace{
 private:
  typedef struct{
    bool                first;
    std::vector<size_t> second;
    std::vector<size_t> third;
  } triple;

 protected:
  // Element Definition //
  size_t nVertex;
  std::vector<std::vector<size_t> > refEdgeNodeIdx;
  std::vector<std::vector<size_t> > refFaceNodeIdx;

  // Permutation Tree //
  PermutationTree* pTree;

  // Reference Spaces Node Ids //
  std::vector<std::vector<size_t> > refSpaceNodeId;

  // ABC space to UVW space shape function index mapping //
  std::vector<std::vector<size_t> > ABCtoUVWIndex;

  // UVW space to ABC space shape function index mapping //
  std::vector<std::vector<size_t> > UVWtoABCIndex;

  // Ordered Edge & Face Node Index //
  std::vector<std::vector<std::vector<size_t> > > orderedEdgeNodeIdx;
  std::vector<std::vector<std::vector<size_t> > > orderedFaceNodeIdx;

 public:
  virtual ~ReferenceSpace(void);

  size_t getNReferenceSpace(void) const;
  size_t getReferenceSpace(const MElement& element) const;

  const std::vector<std::vector<std::vector<size_t> > >&
    getEdgeNodeIndex(void) const;

  const std::vector<std::vector<std::vector<size_t> > >&
    getFaceNodeIndex(void) const;

  const std::vector<size_t>&
    getNodeIndexFromABCtoUVW(const MElement& element) const;

  void mapFromABCtoUVW(const MElement& element,
                       double a, double b, double c,
                       double uvw[3]) const;

  void mapFromABCtoXYZ(const MElement& element,
                       double a, double b, double c,
                       double xyz[3]) const;

  void mapFromUVWtoABC(const MElement& element,
                       double u, double v, double w,
                       double abc[3]) const;

  void mapFromXYZtoABC(const MElement& element,
                       double x, double y, double z,
                       double abc[3]) const;

  double getJacobian(const MElement& element,
                     double a, double b, double c,
                     fullMatrix<double>& jac) const;

  virtual std::string toString(void) const;
  virtual std::string toLatex(void) const;

 protected:
  ReferenceSpace(void);

  void init(void);

 private:
  void getOrderedEdge(void);
  void getOrderedFace(void);

  void findCyclicPermutation
    (std::list<size_t>&               listOfTrueReferenceSpace,
     std::list<std::vector<size_t> >& listOfRefNodeIndexPermutation,
     std::list<std::vector<size_t> >& listOfReverseNodeIndexPermutation);

  triple isCyclicPermutation(std::vector<size_t>& pTest,
                             std::vector<size_t>& pRef);

  size_t findCorrespondingFace(std::vector<size_t>& face,
                               std::vector<size_t>& node);

  static bool isFacePermutation(std::vector<size_t>& refNode,
                                std::vector<size_t>& testNode);

  std::vector<size_t> getRefIndexPermutation(std::vector<size_t>& ref,
                                             std::vector<size_t>& test);

  std::vector<size_t> getReverseIndexPermutation(std::vector<size_t>& ref,
                                                 std::vector<size_t>& test);

  static bool haveSameNode(std::vector<size_t>& face0,
                           std::vector<size_t>& face1);

  size_t getPermutationIdx(const MElement& element) const;

  static void
    orderRefEntityForGivenRefSpace(std::vector<size_t>& refEntityNodeIdx,
                                   std::vector<size_t>& refSpaceNodeId,
                                   std::vector<size_t>& orderedEntityNodeIdx);

  static void
    correctQuadFaceNodeIdx(std::vector<size_t>& correctedQuadFaceNodeIdx);

  static bool sortPredicate(const std::pair<size_t, size_t>& a,
                            const std::pair<size_t, size_t>& b);

  static void regularize(size_t dim, fullMatrix<double>& jac);
};


/**
   @internal
   @fn ReferenceSpace::ReferenceSpace
   Instatiate a new ReferenceSpace
   @endinternal
   **

   @fn ReferenceSpace::~ReferenceSpace
   Deletes this ReferenceSpace
   **

   @fn ReferenceSpace::getNReferenceSpace
   @returns Returns the number of permutation of this
   ReferenceSpace
   **

   @fn ReferenceSpace::getReferenceSpace
   @param element A MElement
   @returns Returns the a natural number defining
   the permutation of the given element

   @note If no permutation is found (e.g. the given
   element does not belong the @em same @em geometrical
   entity as this ReferenceSpace) an Exception is thrown
   **

   @fn ReferenceSpace::getAllEdge
   @return Returns every Edge permutation of this ReferenceSpace

   @note
   @li The fisrt vector represents a particular permutation
   (see ReferenceSpace::getReferenceSpace())
   @li The second vector represents a particular edge
   (for a given permutation)
   @li The last vector represents the Vertex @c IDs of
   the given edge (in the @em geometrical reference space)
   **

   @fn ReferenceSpace::getAllFace
   @return Returns every Face permutation of this ReferenceSpace

   @note
   @li The fisrt vector represents a particular permutation
   (see ReferenceSpace::getReferenceSpace())
   @li The second vector represents a particular face
   (for a given permutation)
   @li The last vector represents the Vertex @c IDs of
   the given face (in the @em geometrical reference space)
   **

   @fn ReferenceSpace::toString
   @return Returns a string describing this ReferenceSpace
   **

   @fn ReferenceSpace::toLatex
   @return Returns a string (of a Latex file)
   describing this ReferenceSpace
 */

//////////////////////
// Inline Functions //
//////////////////////

inline size_t ReferenceSpace::getNReferenceSpace(void) const{
  return refSpaceNodeId.size();
}

inline
const std::vector<std::vector<std::vector<size_t> > >&
ReferenceSpace::getEdgeNodeIndex(void) const{
  return orderedEdgeNodeIdx;
}

inline
const std::vector<std::vector<std::vector<size_t> > >&
ReferenceSpace::getFaceNodeIndex(void) const{
  return orderedFaceNodeIdx;
}

inline
const std::vector<size_t>&
ReferenceSpace::getNodeIndexFromABCtoUVW(const MElement& element) const{
  return ABCtoUVWIndex[getPermutationIdx(element)];
}

inline
size_t ReferenceSpace::getReferenceSpace(const MElement& element) const{
  return pTree->getTagFromPermutation(getPermutationIdx(element));
}

inline
bool
ReferenceSpace::sortPredicate(const std::pair<size_t, size_t>& a,
                              const std::pair<size_t, size_t>& b){
  return a.second < b.second;
}

#endif
