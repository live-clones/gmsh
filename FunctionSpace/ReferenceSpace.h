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

   This class represents the notion of Reference Space.
   A Reference Space is the set of all the permutations
   of the reference element of a particular geometrical entity.

   @todo End ReferenceSpace DOC !!!
 */

class ReferenceSpace{
 private:
  class EdgeComparator{
  public:
    bool operator()(const std::vector<size_t>& a,
                    const std::vector<size_t>& b);
  };

 private:
  typedef struct{
    bool                first;
    std::vector<size_t> second;
    std::vector<size_t> third;
  } triplet;

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
  ReferenceSpace(const std::string& path);
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

  std::pair<size_t, char*> serialize(void) const;
  void                     serialize(const std::string& path) const;

 protected:
  ReferenceSpace(void);

  void init(void);
  void init(const char* stream);
  void init(const std::string& path);

 private:
  void getOrderedEdge(void);
  void getOrderedFace(void);

  void findCyclicPermutation
    (std::list<size_t>&               listOfTrueReferenceSpace,
     std::list<std::vector<size_t> >& listOfRefNodeIndexPermutation,
     std::list<std::vector<size_t> >& listOfReverseNodeIndexPermutation);

  triplet isCyclicPermutation(const std::vector<size_t>& pTest,
                              const std::vector<size_t>& pRef) const;

  size_t findCorrespondingFace(const std::vector<size_t>& face,
                               const std::vector<size_t>& node) const;

  static bool haveSameNode(const std::vector<size_t>& face0,
                           const std::vector<size_t>& face1);

  static bool isFacePermutation(const std::vector<size_t>& refNode,
                                const std::vector<size_t>& testNode);

  bool isSameEdge(const std::vector<size_t>& pTest,
                  const std::vector<size_t>& pRef) const;

  static bool edgeComparator(const std::vector<size_t>& a,
                             const std::vector<size_t>& b);

  std::vector<size_t>
    getRefIndexPermutation(const std::vector<size_t>& ref,
                           const std::vector<size_t>& test) const;

  std::vector<size_t>
    getReverseIndexPermutation(const std::vector<size_t>& ref,
                               const std::vector<size_t>& test) const;

  size_t getPermutationIdx(const MElement& element) const;

  static void
    orderRefEntityForGivenRefSpace(std::vector<size_t>& refEntityNodeIdx,
                                   std::vector<size_t>& refSpaceNodeId,
                                   std::vector<size_t>& orderedEntityNodeIdx);

  void correctQuadFaceNodeIdx(size_t faceId,
                              std::vector<size_t>& correctedQuadFaceNodeIdx);

  static bool sortPredicate(const std::pair<size_t, size_t>& a,
                            const std::pair<size_t, size_t>& b);

  static void regularize(size_t dim, fullMatrix<double>& jac);

  static std::pair<size_t, char*>
    serialize(const std::vector<std::vector<size_t> >& source);

  static std::pair<size_t, char*>
    serialize(const std::vector<std::vector<std::vector<size_t> > >& source);

  static size_t
    unserialize(const char* stream,
                std::vector<std::vector<size_t> >& dest);

  static size_t
    unserialize(const char* stream,
                std::vector<std::vector<std::vector<size_t> > >& dest);
};


/**
   @internal
   @fn ReferenceSpace::ReferenceSpace(void)
   Instatiate a new ReferenceSpace
   @endinternal
   **

   @fn ReferenceSpace::ReferenceSpace(const std::string&)
   @param path A file path

   Instanciates a new ReferenceSpace by loading the file in the given path
   **

   @fn ReferenceSpace::~ReferenceSpace
   Deletes this ReferenceSpace
   **

   @fn ReferenceSpace::getNReferenceSpace
   @returns Returns the number of permutation of this ReferenceSpace
   **

   @fn ReferenceSpace::getReferenceSpace
   @param element A MElement
   @returns Returns the a natural number defining
   the permutation of the given element

   If no permutation is found (e.g. the given
   element does not belong the same geometrical
   entity as this ReferenceSpace) an Exception is thrown
   **

   @fn ReferenceSpace::getEdgeNodeIndex
   @return Returns every Edge Node Index permutation of this ReferenceSpace

   @li The fisrt vector represents a particular permutation
   (see ReferenceSpace::getReferenceSpace())
   @li The second vector represents a particular edge (for a given permutation)
   @li The last vector represents the Vertex IDs of
   the given edge (in the geometrical reference space)
   **

   @fn ReferenceSpace::getFaceNodeIndex
   @return Returns every Face Node Index permutation of this ReferenceSpace

   @li The fisrt vector represents a particular permutation
   (see ReferenceSpace::getReferenceSpace())
   @li The second vector represents a particular face (for a given permutation)
   @li The last vector represents the Vertex IDs of
   the given face (in the geometrical reference space)
   **

   @fn ReferenceSpace::toString
   @return Returns a string describing this ReferenceSpace
   **

   @fn ReferenceSpace::toLatex
   @return Returns a string (of a Latex file) describing this ReferenceSpace
   **

   @fn ReferenceSpace::serialize(void) const

   Serialize this ReferenceSpace into a byte stream

   @return Returns a pair such that:
   @li The first entry is the byte stream size
   @li The second entry is a pointer the allocated byte stream
   **

   @fn ReferenceSpace::serialize(const std::string&) const
   @param path A file path

   Serialize this ReferenceSpace into the given file
   **
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
