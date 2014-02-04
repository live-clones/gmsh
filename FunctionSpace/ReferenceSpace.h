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

   A Reference Space is the space where all the mesh elements
   (of the same geomtrical family) will be mapped.

   A given geomtrical family may have mutltiple reference spaces,
   depending on how the egdes and faces are oriented.
   These orientations depend on the global number of the mesh element vertices,
   and the bigger/smaller relations that exist among them.

   This class can generate, and orient, all the reference spaces
   of a geomtrical family (see specialized classes).
   It can alse compute the jacobian matrices for the mapping between spaces.

   This class can handle three different types of reference spaces:
   @li The XYZ space, which is the space of the physical (mesh) elements
   @li The UVW space, which is the unoriented reference space of the mesh module
   @li The ABC spaces, which are the set oriented reference spaces

   Note that the UVW and ABC spaces are defined on the same domain.
   The only difference is how the vertices are indexed (and oriented).
   Actualy, the ABC spaces are constructed by orienting (that is reindexing)
   the edges and faces of the UVW space.

   Also note that a given mesh element can have only one orientation,
   so it can be mapped on only one of the ABC spaces.
   This class is able to find which ABC space corresponds to a mesh element.

   The edges (or faces) are represended by the index of their vertices.
   For a given edge (or face), this class is able to return these indexes,
   so that the bigger/smaller relations between the indexed vertices is valid.
   By valid, one need to understand: so that the bigger/smaller relations
   are the same for every edge (or face) of every mesh element.
   Or, one can say: such that the edges (or faces) are oriented.

   Since an ABC space corresponds to an orientation, an ABC space corresponds
   to a set of ordered edge (or face) node index. This class is able to give
   these node index relations for all its ABC spaces.
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

  size_t getNVertex(void) const;
  size_t getNEdge(void)   const;
  size_t getNFace(void)   const;

  size_t getNOrientation(void) const;
  size_t getOrientation(const MElement& element) const;

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
   @returns Returns the number of ABC reference spaces
   **

   @fn ReferenceSpace::getReferenceSpace
   @param element A MElement
   @returns Returns a natural number defining on which ABC space
   the given element can be mapped

   If no space is found (e.g. the given element does not belong
   the same geometrical entity as this ReferenceSpace) an Exception is thrown
   **

   @fn ReferenceSpace::getEdgeNodeIndex
   @return Returns every oriented edge node index of this ReferenceSpace

   @li The first vector represents a particular ABC space
   (see ReferenceSpace::getReferenceSpace())
   @li The second vector represents a particular edge (for the given ABC space)
   @li The last vector represents the vertex indexes of the given edge
   **

   @fn ReferenceSpace::getFaceNodeIndex
   @return Returns every oriented face node index of this ReferenceSpace

   @li The first vector represents a particular ABC space
   (see ReferenceSpace::getReferenceSpace())
   @li The second vector represents a particular face (for the given ABC space)
   @li The last vector represents the vertex indexes of the given face
   **

   @fn ReferenceSpace::getNodeIndexFromABCtoUVW
   @param element A MElement

   We call ABC[i] the ID of the ith node in the ABC space of the given element.
   We call UVW[i] the ID of the ith node in the UVW space of the given element.

   @return Returns a vector, called map, such that: ABC[i] = UVW[map[i]]

   Note that this is valid, since ABC spaces and UVW space are defined on the
   same domain. The only difference between those spaces is the node indexing.
   **

   @fn ReferenceSpace::mapFromABCtoUVW
   @param element A MElement
   @param a The 'A' coordinate of a point in the ABC space of the given element
   @param b The 'B' coordinate of a point in the ABC space of the given element
   @param c The 'C' coordinate of a point in the ABC space of the given element
   @param uvw A vector in the UVW space of the given element

   Fills the given vector with the coordinates of the
   (a, b, c) point in the UVW space
   **

   @fn ReferenceSpace::mapFromABCtoXYZ
   @param element A MElement
   @param a The 'A' coordinate of a point in the ABC space of the given element
   @param b The 'B' coordinate of a point in the ABC space of the given element
   @param c The 'C' coordinate of a point in the ABC space of the given element
   @param xyz A vector in the XYZ space of the given element

   Fills the given vector with the coordinates of the
   (a, b, c) point in the XYZ space
   **

   @fn ReferenceSpace::mapFromUVWtoABC
   @param element A MElement
   @param u The 'U' coordinate of a point in the UVW space of the given element
   @param v The 'V' coordinate of a point in the UVW space of the given element
   @param w The 'W' coordinate of a point in the UVW space of the given element
   @param abc A vector in the ABC space of the given element

   Fills the given vector with the coordinates of the
   (u, v, w) point in the ABC space
   **

   @fn ReferenceSpace::mapFromXYZtoABC
   @param element A MElement
   @param x The 'X' coordinate of a point in the XYZ space of the given element
   @param y The 'Y' coordinate of a point in the XYZ space of the given element
   @param z The 'Z' coordinate of a point in the XYZ space of the given element
   @param abc A vector in the ABC space of the given element

   Fills the given vector with the coordinates of the
   (x, y, z) point in the ABC space
   **

   @fn ReferenceSpace::getJacobian
   @param element A MElement
   @param a The 'A' coordinate of a point in the ABC space of the given element
   @param b The 'B' coordinate of a point in the ABC space of the given element
   @param c The 'C' coordinate of a point in the ABC space of the given element
   @param jac A 3 by 3 allocated fullMatrix

   Fills the given matrix with the jacobian, evaluated at (a, b, c),
   of the mapping between the ABC space and the XYZ space

   @return Returns the determinant of the jacobian matrix
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

inline size_t ReferenceSpace::getNVertex(void) const{
  return nVertex;
}

inline size_t ReferenceSpace::getNEdge(void) const{
  return refEdgeNodeIdx.size();
}

inline size_t ReferenceSpace::getNFace(void) const{
  return refFaceNodeIdx.size();
}

inline size_t ReferenceSpace::getNOrientation(void) const{
  return refSpaceNodeId.size();
}

inline
size_t ReferenceSpace::getOrientation(const MElement& element) const{
  return pTree->getTagFromPermutation(getPermutationIdx(element));
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
bool
ReferenceSpace::sortPredicate(const std::pair<size_t, size_t>& a,
                              const std::pair<size_t, size_t>& b){
  return a.second < b.second;
}

#endif
