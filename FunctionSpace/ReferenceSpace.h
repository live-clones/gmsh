#ifndef _REFERENCESPACE_H_
#define _REFERENCESPACE_H_

#include <vector>
#include <list>
#include <string>
#include "MElement.h"

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
  // Permuation Tree Structure //
  struct node_s{
    unsigned int  depth;    // Depth
    unsigned int* last;     // Last           Choises
    unsigned int  number;   // Number of Next Choise
    unsigned int* possible; // Possible  Next Choise
    node_s*       next;     // Next           Choise
  
    unsigned int  leafId;   // If leaf: this leaf number
                            //     (from 0 to nLeaf - 1)
                            // Else: no meaning
  };

  typedef node_s node;

 protected:
  // Permutation (Tree + Leaf) //
  unsigned int   nextLeafId;
  unsigned int   nVertex;
  unsigned int   nPerm;
  unsigned int** perm;
  node pTreeRoot;

  mutable std::list<unsigned int*>* lPerm;

  // Edge Permutation //
  unsigned int    nEdge;
  unsigned int**  refEdge;
  std::vector<const std::vector<const std::vector<unsigned int>*>*>* edge;

  // Face Permutation //
  unsigned int    nFace;
  unsigned int**  refFace;
  std::vector<const std::vector<const std::vector<unsigned int>*>*>* face;

 public:
  virtual ~ReferenceSpace(void);

  unsigned int getNPermutation(void) const;
  
  unsigned int getPermutation(const MElement& element) const;

  std::vector<const std::vector<const std::vector<unsigned int>*>*>&
    getAllEdge(void) const;
  
  std::vector<const std::vector<const std::vector<unsigned int>*>*>&
    getAllFace(void) const ;

  std::string toString(void) const;

  virtual std::string toLatex(void) const = 0;

 protected:
  ReferenceSpace(void);

  void init(void);
  void populate(node* pTreeRoot);
  void destroy(node* node);
  
  void getEdge(void);
  void getFace(void);

  const std::vector<unsigned int>* inOrder(unsigned int permutation, 
					   unsigned int a, 
					   unsigned int b);

  const std::vector<unsigned int>* inOrder(unsigned int permutation, 
					   unsigned int a, 
					   unsigned int b,
					   unsigned int c);

  static bool sortPredicate(const std::pair<unsigned int, MVertex*>& a, 
			    const std::pair<unsigned int, MVertex*>& b);

  static unsigned int treeLookup(const node* root,
				 std::vector<std::pair<unsigned int, MVertex*> >& 
				 sortedArray);

  std::string toString(const node* node) const;
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
   
   @fn ReferenceSpace::getNPermutation
   @returns Returns the number of permutation of this
   ReferenceSpace
   **

   @fn ReferenceSpace::getPermutation
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
   (see ReferenceSpace::getPermutation())
   @li The second vector represents a particular edge 
   (for a given permutation) 
   @li The last vector represents the Vertex @c IDs of 
   the given edge (in the @em geometrical reference space)
   **

   @fn ReferenceSpace::getAllFace
   @return Returns every Face permutation of this ReferenceSpace
   
   @note
   @li The fisrt vector represents a particular permutation 
   (see ReferenceSpace::getPermutation())
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

inline 
unsigned int 
ReferenceSpace::getNPermutation(void) const{
  return nPerm;
}
  
inline 
std::vector<const std::vector<const std::vector<unsigned int>*>*>&
ReferenceSpace::getAllEdge(void) const{
  return *edge;
}

inline
std::vector<const std::vector<const std::vector<unsigned int>*>*>&
ReferenceSpace::getAllFace(void) const{
  return *face;
}

inline 
bool 
ReferenceSpace::sortPredicate(const std::pair<unsigned int, MVertex*>& a, 
			      const std::pair<unsigned int, MVertex*>& b){
  return a.second->getNum() < b.second->getNum();
}

#endif
