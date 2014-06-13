#include <map>
#include <fstream>
#include <cstring>

#include "Exception.h"
#include "PermutationTree.h"

using namespace std;

PermutationTree::PermutationTree(const std::vector<size_t>& refSequence){
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

PermutationTree::PermutationTree(const char* stream){
  // Populate from stream
  populateFromStream(stream);
}

PermutationTree::PermutationTree(const std::string& path){
  // Read file //
  // Open Stream
  ifstream input;
  input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  input.open(path.c_str(), std::ifstream::binary);

  // Get size of stream (go to stream end)
  input.seekg(0, std::ifstream::end);
  const size_t size = input.tellg();

  // Reset stream possition
  input.seekg(0, std::ifstream::beg);

  // Alloc byte stream & Read file
  char* stream = new char[size];
  input.read(stream, size);

  // Populate from stream
  populateFromStream(stream);

  // Free stream
  delete[] stream;
}

void PermutationTree::populate(node_t* node,
                               std::list<node_t*>& listOfLeaf){
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

void PermutationTree::populateFromStream(const char* stream){
  // Header Size
  const size_t hSize = headerSize();

  // Read header
  size_t uSize; // Unlink struct size

  memcpy(&uSize,        stream + 0 * sizeof(size_t), sizeof(size_t));
  memcpy(&nextNodeId,   stream + 1 * sizeof(size_t), sizeof(size_t));
  memcpy(&sequenceSize, stream + 2 * sizeof(size_t), sizeof(size_t));

  // Unserialize unlink struct
  vector<unlink_t> unlink(nextNodeId);
  for(size_t i = 0; i < nextNodeId; i++)
    unserialize(stream + hSize + (i * uSize), &unlink[i]);

  // Regenerate Tree //
  rebuild(unlink);
}

void PermutationTree::unserialize(const char* stream, unlink_t* unlink){
  // Some padding data //
  const size_t nxtChoiceStart = 2 * sizeof(size_t);
  const size_t fatherIdStart  = nxtChoiceStart + sequenceSize * sizeof(size_t);
  const size_t sonStart       = fatherIdStart + 2 * sizeof(size_t);
  const size_t otherIdStart   = sonStart + sequenceSize * sizeof(size_t);

  // Next Choice //
  memcpy(&unlink->myChoice,   stream + 0 * sizeof(size_t), sizeof(size_t));
  memcpy(&unlink->nNxtChoice, stream + 1 * sizeof(size_t), sizeof(size_t));

  unlink->nxtChoice.resize(unlink->nNxtChoice);
  for(size_t i = 0; i < unlink->nNxtChoice; i++)
    memcpy(&unlink->nxtChoice[i],
           stream + nxtChoiceStart + i * sizeof(size_t), sizeof(size_t));

  // Father and Son //
  memcpy(&unlink->fatherId,
         stream + fatherIdStart + 0 * sizeof(size_t), sizeof(size_t));

  memcpy(&unlink->nSon,
         stream + fatherIdStart + 1 * sizeof(size_t), sizeof(size_t));

  unlink->sonId.resize(unlink->nSon);
  for(size_t i = 0; i < unlink->nSon; i++)
    memcpy(&unlink->sonId[i],
           stream + sonStart + i * sizeof(size_t), sizeof(size_t));

  // Node Id //
  memcpy(&unlink->nodeId,
         stream + otherIdStart + 0 * sizeof(size_t), sizeof(size_t));

  // Leaf Id //
  memcpy(&unlink->leafId,
         stream + otherIdStart + 1 * sizeof(size_t), sizeof(size_t));

  // Tag //
  memcpy(&unlink->tag,
         stream + otherIdStart + 2 * sizeof(size_t), sizeof(size_t));
}

void PermutationTree::rebuild(std::vector<unlink_t>& unlink){
  // Almost linked nodes (node of node_t type but without connected nodes) //
  vector<node_t*> node(nextNodeId);
  for(size_t i = 0; i < nextNodeId; i++)
    node[i] = copy(&unlink[i]);

  // Root //
  root = node[0];
  for(size_t j = 0; j < root->son.size(); j++)
    root->son[j] = node[unlink[0].sonId[j]];

  // Link all other nodes & Gather leafs //
  list<node_t*> listOfLeaf;

  for(size_t i = 1; i < nextNodeId; i++){
    // Father
    node[i]->father = node[unlink[i].fatherId];

    // Son
    for(size_t j = 0; j < node[i]->son.size(); j++)
      node[i]->son[j] = node[unlink[i].sonId[j]];

    // Leaf (if it is actualy a leaf)
    if(node[i]->leafId != (size_t)(-1))
      listOfLeaf.push_back(node[i]);
  }

  // Get Leafs //
  leaf.assign(listOfLeaf.begin(), listOfLeaf.end());
}

PermutationTree::node_t* PermutationTree::copy(unlink_t* unlink){
  node_t* node = new node_t;

  node->myChoice = unlink->myChoice;
  node->nxtChoice.resize(unlink->nNxtChoice);

  for(size_t i = 0; i < unlink->nNxtChoice; i++)
    node->nxtChoice[i] = unlink->nxtChoice[i];

  node->father = NULL;
  node->son.resize(unlink->nSon);

  node->nodeId = unlink->nodeId;
  node->leafId = unlink->leafId;
  node->tag    = unlink->tag;

  return node;
}

PermutationTree::~PermutationTree(void){
  destroy(root);
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
                         const std::vector<size_t>& sequence,
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

void
PermutationTree::fillWithPermutation(size_t permutationId,
                                     std::vector<size_t>& vectorToFill) const{
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

string PermutationTree::toLatex(void) const{
  stringstream stream;

  // Small FEM //
  stream << "%%% Automaticaly generated by SmallFem" << endl;

  // Header //
  stream << "\\documentclass[11pt]{article}" << endl << endl

         << "\\usepackage{tikz}" << endl
         << endl
         << "\\usetikzlibrary{arrows}" << endl
         << "\\tikzstyle{vertex} = [circle, fill = black!25, inner sep = 2pt,"
         << endl
         << "                                              minimum size = 15pt]"
         << endl
         << "\\tikzstyle{circ}   = [draw, circle, minimum size = 15pt]"
         << endl
         << "\\tikzstyle{line}   = [thick, black]" << endl
         << "\\tikzstyle{box}    = [draw, rectangle, minimum width=20pt,"
         << endl
         << "                                      minimum height=10pt]"
         << endl
         << "\\tikzstyle{arrow}  = [-stealth']" << endl << endl
         << "\\begin{document}" << endl
         << "\\begin{tikzpicture}";

  // Options //
  stream << "["
         << "grow = right,"
         << "edge from parent/.style={draw, line},"
         << "level 1/.style={sibling distance=12em},"
         << "level 2/.style={sibling distance=4em},"
         << "level 3/.style={sibling distance=2em},"
         << "level 5/.style={level distance=5em},"
         << "]" << endl;

  // Tree //
  // Root
  stream << "\\node[vertex] (root) {\\phantom{$0$}}" << endl;

  // Travel from root in deepFirst and add childs to stream
  deepFirstStream(root, stream);

  // Final ;
  stream << ";" << endl << endl;

  // Reference Element
  for(size_t i = 0; i < leaf.size(); i++)
    if(leaf[i]->tag == leaf[i]->leafId)
      stream << "\\node[right, xshift = 0.6em] at(l" << leaf[i]->tag
             << ") {(\\textit{Reference})};"       << endl;

  stream << endl;

  // Legend
  stream << "\\node[box,    xshift = -10em, yshift =  1.5em] at(root) (box)  "
         << "{};"                << endl
         << "\\node[right,  xshift =   0.7em]                at(box)         "
         << "{Leaf Tag};"        << endl
         << "\\node[vertex, yshift =   3em]                  at(box)  (vert) "
         << "{};"                << endl
         << "\\node[right,  xshift =   0.7em]                at(vert)        "
         << "{Vertex number};"   << endl
         << "\\node[        xshift = -10em, yshift = -1.5em] at(root) (ori)  "
         << "{$[\\dots]$};"      << endl
         << "\\node[right,  xshift =   0.7em]                at(ori)         "
         << "{Permutation};"     << endl
         << "\\node[circ,   yshift =  -3em]                  at(ori)  (circ) "
         << "{};"                << endl
         << "\\node[right,  xshift =   0.7em]                at(circ)        "
         << "{Orientation tag};" << endl;

  // Footer //
  stream << "\\end{tikzpicture}" << endl
         << "\\end{document}"    << endl;

  return stream.str();

}

void PermutationTree::deepFirstStream(node_t* node, stringstream& stream) const{
  vector<size_t> permutation(getSequenceSize());

  // If node is root, don't add to stream: just loop on its childs
  if(node->myChoice == (size_t)(-1))
    for(size_t i = 0; i < node->son.size(); i++)
      deepFirstStream(node->son[i], stream);

  // Else, insert node in stream as child //
  else{
    stream << "child{node[vertex]";

    // If node, name it
    // if(node->son.size() == 0)
    //   stream << "(l" << node->leafId << ")";

    stream << "{" << node->myChoice << "}" << endl;

    for(size_t i = 0; i < node->son.size(); i++)
      deepFirstStream(node->son[i], stream);

    // If leaf, child is tag and permutation //
    if(node->son.size() == 0){
      // Leaf Id
      stream << "child{node[box, anchor=west]{$" << node->leafId << "$} "
             << "edge from parent[arrow]" << endl;

      // Permutation
      fillWithPermutation(node->leafId, permutation);

      stream << "child[anchor=west]{node{$[";

      for(size_t j = 0; j < permutation.size() - 1; j++)
        stream << permutation[j] << ", ";

      stream << permutation[permutation.size() - 1] << "]$}"
             << " edge from parent[arrow]" << endl;

      // Tag
      stream << "child{node[circ, anchor=west]";

      // Is true orientation ?
      if(node->tag == node->leafId)
        stream << " (l" << node->tag << ") ";

      stream << "{" << node->tag << "} edge from parent[arrow]" << endl;

      // Done
      stream << "}}}";
    }

    stream << "}" << endl;
  }

  // If leaf, return //
  if(node->son.size() == 0)
    return;
}

std::pair<size_t, char*> PermutationTree::serialize(void) const{
  // Enumerate Nodes //
  list<node_t*> node;
  enumerate(root, node);

  // Serialize all nodes //
  // Unlink root to get (fixed) size of unlink type
  unlink_t tmp;
  unlink(root, &tmp, sequenceSize);

  // Get Sizes
  const size_t hSize = headerSize();     // Header size
  const size_t uSize = unlinkSize(&tmp); // Unlink struct size
  const size_t nNode = node.size();      // Number of node/unlink struct
  const size_t nSize = uSize * nNode;    // Total size for unlink struct
  const size_t sSize = hSize + nSize;    // Stream size

  // Alloc byte Stream
  char* stream = new char[sSize];
  for(size_t i = 0; i < sSize; i++)
    stream[i] = 0;

  // Write header in Stream
  memcpy(stream + 0 * sizeof(size_t), &uSize,        sizeof(size_t));
  memcpy(stream + 1 * sizeof(size_t), &nNode,        sizeof(size_t));
  memcpy(stream + 2 * sizeof(size_t), &sequenceSize, sizeof(size_t));

  // Write unlinked node in Stream
  list<node_t*>::iterator it = node.begin();

  for(size_t i = 0; i < nNode; i++, it++){
    unlink(*it, &tmp, sequenceSize);
    serialize(stream + hSize + (i * uSize), &tmp);
  }

  // Return Stream & its size
  return pair<size_t, char*>(sSize, stream);
}

void PermutationTree::serialize(const std::string& path) const{
  // Serialize into byte Stream
  std::pair<size_t, char*> stream  = serialize();

  // Write byte stream
  ofstream output;
  output.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  output.open(path.c_str(), std::ofstream::binary);
  output.write(stream.second, stream.first);
  output.close();

  // Free
  delete[] stream.second;
}

void PermutationTree::enumerate(node_t* node, std::list<node_t*>& listOfNode){
  // Add this node
  listOfNode.push_back(node);

  // Add son
  const size_t nSon = node->son.size();
  for(size_t i = 0; i < nSon; i++)
    enumerate(node->son[i], listOfNode);
}

void PermutationTree::unlink(node_t* node, unlink_t* unlink, size_t maxSize){
  unlink->myChoice   = node->myChoice;
  unlink->nNxtChoice = node->nxtChoice.size();
  unlink->nxtChoice.resize(maxSize); // Use fixed size -- easyer serialization

  for(size_t i = 0; i < unlink->nNxtChoice; i++)
    unlink->nxtChoice[i] = node->nxtChoice[i];

  if(!node->father)
    unlink->fatherId = (size_t)(-1);
  else
    unlink->fatherId = node->father->nodeId;

  unlink->nSon = node->son.size();
  unlink->sonId.resize(maxSize); // Use fixed size -- easyer serialization

  for(size_t i = 0; i < unlink->nSon; i++)
    unlink->sonId[i] = node->son[i]->nodeId;

  unlink->nodeId = node->nodeId;
  unlink->leafId = node->leafId;
  unlink->tag    = node->tag;
}

void
PermutationTree::serialize(char* stream, unlink_t* unlink) const{
  // Some padding data //
  const size_t nxtChoiceStart = 2 * sizeof(size_t);
  const size_t fatherIdStart  = nxtChoiceStart + sequenceSize * sizeof(size_t);
  const size_t sonStart       = fatherIdStart + 2 * sizeof(size_t);
  const size_t otherIdStart   = sonStart + sequenceSize * sizeof(size_t);

  // Next Choice //
  memcpy(stream + 0 * sizeof(size_t), &unlink->myChoice,   sizeof(size_t));
  memcpy(stream + 1 * sizeof(size_t), &unlink->nNxtChoice, sizeof(size_t));

  for(size_t i = 0; i < unlink->nNxtChoice; i++)
    memcpy(stream + nxtChoiceStart + i * sizeof(size_t),
           &unlink->nxtChoice[i], sizeof(size_t));

  // Father and Son //
  memcpy(stream + fatherIdStart + 0 * sizeof(size_t),
         &unlink->fatherId, sizeof(size_t));

  memcpy(stream + fatherIdStart + 1 * sizeof(size_t),
         &unlink->nSon, sizeof(size_t));

  for(size_t i = 0; i < unlink->nSon; i++)
    memcpy(stream + sonStart + i * sizeof(size_t),
           &unlink->sonId[i], sizeof(size_t));

  // Node Id //
  memcpy(stream + otherIdStart + 0 * sizeof(size_t),
         &unlink->nodeId, sizeof(size_t));

  // Leaf Id //
  memcpy(stream + otherIdStart + 1 * sizeof(size_t),
         &unlink->leafId, sizeof(size_t));

  // Tag //
  memcpy(stream + otherIdStart + 2 * sizeof(size_t),
         &unlink->tag, sizeof(size_t));
}
