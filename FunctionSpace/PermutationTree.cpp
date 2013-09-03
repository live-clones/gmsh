#include <map>

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
  nextNodeId = 0;
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
  // Node Id //
  node->nodeId = nextNodeId;
  nextNodeId++;

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

void PermutationTree::compressTag(void){
  // Populate Tag map
  const size_t nLeaf = leaf.size();
  multimap<size_t, node_t*> tag;

  for(size_t i = 0; i < nLeaf; i++)
    tag.insert(pair<size_t, node_t*>(leaf[i]->tag, leaf[i]));

  // Compress Tag
  const multimap<size_t, node_t*>::iterator end = tag.end();
  multimap<size_t, node_t*>::iterator it = tag.begin();

  size_t currentTag = it->first;
  size_t nextTag = 0;

  for(; it != end; it++){
    // If new old tag --> increase new tag by one
    if(it->first != currentTag){
      currentTag = it->first;
      nextTag++;
    }

    // Apply same new tag
    it->second->tag = nextTag;
  }
}

std::vector<std::pair<size_t, size_t> >
PermutationTree::getAllTagsCount(void) const{
  // Init Temp map
  map<size_t, size_t> counter;

  // Loop on leafs and populate map
  const size_t nLeaf = leaf.size();
  pair<map<size_t, size_t>::iterator, bool> inserted;

  for(size_t i = 0; i < nLeaf; i++){
    // Try insert new tag with counter to one
    inserted = counter.insert(std::pair<size_t, size_t>(leaf[i]->tag, 1));

    if(!inserted.second)
      // If known tag -- add one to mapped value
      inserted.first->second++;
  }

  // Serialize this map and return
  std::vector<std::pair<size_t, size_t> > ret(counter.begin(), counter.end());
  return ret;
}

string PermutationTree::toString(void) const{
  stringstream stream;

  // Number of Node //
  stream << "nNode " << nextNodeId
         << endl;

  // Nodes (depth first travel) //
  serial_t* tmp = new serial_t;
  appendString(stream, root, tmp);
  delete tmp;

  return stream.str();

  /*
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
  */
}

void PermutationTree::toSerial(node_t* node, serial_t* serial){
  serial->myChoice   = node->myChoice;
  serial->nNxtChoice = node->nxtChoice.size();
  serial->nxtChoice.resize(serial->nNxtChoice);

  for(size_t i = 0; i < serial->nNxtChoice; i++)
    serial->nxtChoice[i] = node->nxtChoice[i];

  if(!node->father)
    serial->fatherId = (size_t)(-1);
  else
    serial->fatherId = node->father->nodeId;

  serial->nSon = node->son.size();
  serial->sonId.resize(serial->nSon);

  for(size_t i = 0; i < serial->nSon; i++)
    serial->sonId[i] = node->son[i]->nodeId;

  serial->nodeId = node->nodeId;
  serial->leafId = node->leafId;
  serial->tag    = node->tag;
}

void PermutationTree::appendString(stringstream& stream,
                                   node_t* node,
                                   serial_t* tmp){
  // Write this node //
  toSerial(node, tmp);
  stream << toString(tmp) << endl;

  // Write Son //
  const size_t nSon = node->son.size();

  for(size_t i = 0; i < nSon; i++)
    appendString(stream, node->son[i], tmp);
}

string PermutationTree::toString(serial_t* serial){
  stringstream stream;

  stream << "Node " << serial->nodeId
         << " - "   << serial->leafId
         << " - "   << serial->tag
         << endl

         << "MyChoice "  << serial->myChoice
         << endl
         << "NxtChoice " << serial->nNxtChoice;

  for(size_t i = 0; i < serial->nNxtChoice; i++)
    stream << " - " << serial->nxtChoice[i];

  stream << endl
         << "FatherId " << serial->fatherId
         << endl
         << "SonId " << serial->nSon;

  for(size_t i = 0; i < serial->nNxtChoice; i++)
    stream << " - " << serial->sonId[i];

  return stream.str();
}
