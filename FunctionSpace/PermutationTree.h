#ifndef _PERMUTATIONTREE_H_
#define _PERMUTATIONTREE_H_

#include <cstdlib>
#include <vector>
#include <list>
#include <string>

/**
   @class PermutationTree
   @brief A Permutation Tree

   This class represents a permutation tree.
   That is, given a sequence of length N,
   this tree will hold all the possible permutations
   of the N elements of the given sequence.

   Every permuted sequence can be associated an ID and a tag.
   By default all sequences are assigned the tag 0.
 */

class PermutationTree{
 private:
  // Tree node //
  typedef struct node_s{
    size_t               myChoice;
    std::vector<size_t>  nxtChoice;

    node_s*              father;
    std::vector<node_s*> son;

    size_t               leafId;
    size_t               tag;
  } node_t;

 private:
  // Sequence size //
  size_t sequenceSize;

  // Root //
  node_t* root;

  // Leaf //
  std::vector<node_t*> leaf;

 public:
   PermutationTree(const std::vector<size_t>& refSequence);
  ~PermutationTree(void);

  size_t getSequenceSize(void) const;

  size_t getNPermutation(void) const;
  size_t getPermutationId(const std::vector<size_t>& sequence) const;

  void fillWithPermutation(size_t permutationId,
                           std::vector<size_t>& vectorToFill) const;

  void   addTagToPermutation(size_t permutationId, size_t tag);
  size_t getTagFromPermutation(size_t permutationId);

  std::vector<std::pair<size_t, size_t> > getAllTagsCount(void) const;

  std::string toString(void) const;

 private:
  static void populate(node_t* node,
                       std::list<node_t*>& listOfLeaf);

  static void destroy(node_t* node);

  static node_t* getLeaf(node_t* root,
                         const std::vector<size_t>& sequence,
                         size_t offset);
};

/**
   @fn PermutationTree::PermutationTree
   @param refSequence A vector of integers

   Instanciates a new PermutationTree build on the given vector
   **

   @fn PermutationTree::~PermutationTree

   Deletes this PermutationTree
   **

   @fn PermutationTree::getSequenceSize
   @return Returns the size of the sequences
   **

   @fn PermutationTree::getNPermutation
   @return Returns the number of permutation of the original sequence
   (including the original sequence)
   **

   @fn PermutationTree::getPermutationId
   @param sequence A sequence
   @return Returns the ID of the given sequence
   **

   @fn PermutationTree::fillWithPermutation
   @param permutationId A permuted sequence ID
   @param vectorToFill An allocated vector of size
   PermutationTree::getSequenceSize()

   Populates the given vector with the permuted sequence of
   the given ID
   **

   @fn PermutationTree::addTagToPermutation
   @param permutationId A permuted sequence ID
   @param tag An integer

   Associates the given permutation with the given tag
   **

   @fn PermutationTree::getTagFromPermutation
   @param permutationId A permuted sequence ID
   @return Returns the tag of the given sequence
   **

   @fn PermutationTree::getAllTagsCount
   @return Returns a vector of pair such that:
   @li The first entry is a tag
   @li The second entry is the number of node having this tag

   The returned vector has en entry for each possible tag
   **

   @fn PermutationTree::toString
   @return Returns a string describing this PermutationTree
 */

//////////////////////
// Inline Functions //
//////////////////////

inline size_t PermutationTree::getSequenceSize(void) const{
  return sequenceSize;
}

inline size_t PermutationTree::getNPermutation(void) const{
  return leaf.size();
}

inline void PermutationTree::
addTagToPermutation(size_t permutationId, size_t tag){
  leaf[permutationId]->tag = tag;
}

inline size_t PermutationTree::
getTagFromPermutation(size_t permutationId){
  return leaf[permutationId]->tag;
}

#endif
