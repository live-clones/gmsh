#ifndef _REFERENCESPACE_H_
#define _REFERENCESPACE_H_

#include <vector>
#include <list>
#include <stack>
#include <string>

#include "MElement.h"
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
  // Permutation Tree //
  PermutationTree* pTree;

  //////////////////////////////////////////////////////////////////////////
  // !!! CHANGE VARIABLES NAME !!!                                        //
  //                                                                      //
  // perm              = nodeReducedGlobalId                              //
  // refEntity         = entityNodeIndex                                  //
  // entity            = orientedEntityNodeIndex                          //
  //                                                                      //
  // !!! I'm Working on *BOTH* indexes and global IDs !!!                 //
  //                                                                      //
  // 16 +                                                                 //
  //    |\        ---> NodeIndex       = [v0 v1 v2]                       //
  //    | \       ---> GlobalID        = [17 42 16]                       //
  //    |  \      ---> ReducedGlobalId = [1  2  0 ] ---> Permutation = 3  //
  // 17 +---+ 42                                                          //
  //                                                                      //
  // *  refEdge[e][i] = ith INDEX of edge[e]                              //
  //    For example refEdge[1] = [1 2] because edge[1]                    //
  //                              - -                                     //
  //                                           is made of nodes v1 and v2 //
  //                                                             -      - //
  //                                                                      //
  // *  edge[p][e][i] = ith INDEX of edge[e] in orientation[p]            //
  //          such that GlobalID[edge[p][e][0]] > GlobalId[edge[p][e][0]] //
  //    For example edge[3][1] = [2 1] because edge[1] goes from v2 to v1 //
  //                              - -                             -     - //
  //////////////////////////////////////////////////////////////////////////

  // Number of Vertices //
  size_t nVertex;

  // Edge Permutation //
  size_t    nEdge;
  size_t**  refEdge;
  //unsigned int*** permutedRefEdge;
  std::vector<const std::vector<const std::vector<unsigned int>*>*>* edge;

  // Face Permutation //
  size_t    nFace;
  size_t*   nNodeInFace;
  size_t**  refFace;
  //unsigned int*** permutedRefFace;
  std::vector<const std::vector<const std::vector<unsigned int>*>*>* face;

 public:
  virtual ~ReferenceSpace(void);

  size_t getNReferenceSpace(void) const;

  size_t getReferenceSpace(const MElement& element) const;
  /*
  std::vector<std::vector<size_t> > getEdgeIndex(size_t referenceSpaceId) const;
  std::vector<std::vector<size_t> > getFaceIndex(size_t referenceSpaceId) const;
  */
  const std::vector<const std::vector<const std::vector<unsigned int>*>*>&
    getAllEdge(void) const;

  const std::vector<const std::vector<const std::vector<unsigned int>*>*>&
    getAllFace(void) const;

  virtual std::string toString(void) const;

  virtual std::string toLatex(void) const;

 protected:
  ReferenceSpace(void);

  void init(void);

  void getEdge(void);
  void getFace(void);

  void   findCyclicPermutation(void);
  triple isCyclicPermutation(std::vector<size_t>& pTest,
                             std::vector<size_t>& pRef);

  size_t findCorrespondingFace(std::vector<size_t>& face,
                               std::vector<size_t>& node);

  /*
  void getPermutedRefEntity(unsigned int**** permutedRefEntity,
                            unsigned int**   refEntity,
                            unsigned int*    nNodeInEntity,
                            unsigned int     nEntity);
  */
  const std::vector<unsigned int>* getOrderedEdge(unsigned int permutation,
                                                  unsigned int edge);

  const std::vector<unsigned int>* getOrderedTriFace(unsigned int permutation,
                                                     unsigned int face);

  const std::vector<unsigned int>* getOrderedQuadFace(unsigned int permutation,
                                                      unsigned int face);

  static void
    orderRefEntityForGivenPermutation(size_t* refEntity,
                                      std::vector<size_t>& permutation,
                                      std::vector<unsigned int>& orderedEntity);

  static bool sortPredicate(const std::pair<unsigned int, unsigned int>& a,
                            const std::pair<unsigned int, unsigned int>& b);
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
  return pTree->getNPermutation();
}

inline
const std::vector<const std::vector<const std::vector<unsigned int>*>*>&
ReferenceSpace::getAllEdge(void) const{
  return *edge;
}

inline
const std::vector<const std::vector<const std::vector<unsigned int>*>*>&
ReferenceSpace::getAllFace(void) const{
  return *face;
}


inline
bool
ReferenceSpace::sortPredicate(const std::pair<unsigned int, unsigned int>& a,
                              const std::pair<unsigned int, unsigned int>& b){
  return a.second < b.second;
}

#endif
