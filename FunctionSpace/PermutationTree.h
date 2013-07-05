#ifndef _PERMUTATIONTREE_H_
#define _PERMUTATIONTREE_H_

#include <cstdlib>
#include <vector>
#include <list>
#include <string>

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

  std::string toString(void) const;

 private:
  static void populate(node_t* node,
                       std::list<node_t*>& listOfLeaf);

  static void destroy(node_t* node);

  static node_t* getLeaf(node_t* root,
                         const std::vector<size_t>& sequence,
                         size_t offset);
};

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
