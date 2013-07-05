#include <sstream>

#include "Exception.h"
#include "PermutationTree.h"

using namespace std;

PermutationTree::PermutationTree(const vector<size_t>& refSequence){
  // Sequence size //
  sequenceSize = refSequence.size();

  // List of leaf //
  list<node_s*> listOfLeaf;

  // Root //
  root = new node_t;

  root->myChoice  = -1;
  root->nxtChoice = refSequence;
  root->father    = NULL;

  root->leafId = -1;
  root->tag    = -1;

  // Tree //
  populate(root, listOfLeaf);

  // Leaf //
  const size_t nLeaf = listOfLeaf.size();
  leaf.assign(listOfLeaf.begin(), listOfLeaf.end());

  for(size_t i = 0; i < nLeaf; i++)
    leaf[i]->leafId = i;
}

PermutationTree::~PermutationTree(void){
  destroy(root);
}

void PermutationTree::populate(node_t* node,
                               list<node_t*>& listOfLeaf){
  // Number of son //
  const size_t nSon = node->nxtChoice.size();

  // Alloc space for son //
  node->son.resize(nSon);

  // Init each son //
  for(size_t i = 0; i < nSon; i++){
    // Alloc Son
    node->son[i] = new node_t;

    // Take father ith choice
    node->son[i]->myChoice = node->nxtChoice[i];

    // Next choices are all but ith
    node->son[i]->nxtChoice.resize(nSon - 1);
    for(size_t j = 0, k = 0; j < nSon; j++){
      if(j != i){
        node->son[i]->nxtChoice[k] = node->nxtChoice[j];
        k++;
      }

      else{
      }
    }

    // Dummy Stuff
    node->son[i]->leafId = -1;
    node->son[i]->tag    = -1;

    // Father
    node->son[i]->father = node;

    // Add Son
    populate(node->son[i], listOfLeaf);
  }

  // If I am a leaf, add me to listOfLeaf
  if(!nSon)
    listOfLeaf.push_back(node);
}

void PermutationTree::destroy(node_t* node){
  // Delete Son
  const size_t nSon = node->son.size();

  for(size_t i = 0; i < nSon; i++)
    destroy(node->son[i]);

  // Delete me
  delete node;
}


size_t PermutationTree::getPermutationId(const vector<size_t>& sequence) const{
  return getLeaf(root, sequence, 0)->leafId;
}

PermutationTree::node_t*
PermutationTree::getLeaf(node_t* root,
                         const vector<size_t>& sequence,
                         size_t offset){
  // Number of son
  const size_t nSon = root->son.size();

  // If a leaf return root
  if(!nSon)
    return root;

  // Else, lookup
  else{
    // Find next son
    size_t i = 0;
    for(i = 0; i < nSon && root->nxtChoice[i] != sequence[offset]; i++)
      ;

    // If no math found, throw an Exception
    if(i == nSon)
      throw Exception("PermutationTree: cannot find given sequence");

    // Get son leaf
    return getLeaf(root->son[i], sequence, offset + 1);
  }
}

void PermutationTree::fillWithPermutation(size_t permutationId,
                                          vector<size_t>& vectorToFill) const{
  // Go from ith leaf to root                //
  // And fill vectorToFill from end to start //

  const size_t max = -1;

  node_t* node = leaf[permutationId];
  size_t     i = sequenceSize - 1;

  while(i != max && node){
    vectorToFill[i] = node->myChoice;
    i--;
    node = node->father;
  }
}

string PermutationTree::toString(void) const{
  // Number of Permutation //
  const size_t max_t = -1;
  const size_t nPerm = leaf.size();

  // Temporary //
  stringstream   stream;
  vector<size_t> permutation(sequenceSize);

  // Build String //
  for(size_t i = 0; i < nPerm; i++){
    fillWithPermutation(i, permutation);

    stream << "Permutation #" << i << ":" << endl
           << "  -- " << permutation[0];

    for(size_t j = 1; j < sequenceSize; j++)
      stream << " " << permutation[j];

    stream << endl << "  -- Tag (";

    if(leaf[i]-> tag != max_t)
      stream << leaf[i]->tag;

    stream << ")" << endl
           << endl;
  }

  // Return //
  return stream.str();
}
