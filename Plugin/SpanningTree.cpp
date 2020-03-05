// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
// Contributed by Nicolas Marsic.

using namespace std;

#include "SpanningTree.h"
#include "GModel.h"
#include "MLine.h"
#include "OS.h"

StringXNumber SpanningTreeOptions_Number[] = {
  {GMSH_FULLRC, "PhysicalGroup",  NULL, -1},
  {GMSH_FULLRC, "StartingOn",     NULL, -1},
  {GMSH_FULLRC, "OutputPhysical", NULL, -1},
};

extern "C"{
  GMSH_Plugin *GMSH_RegisterSpanningTreePlugin(void){
    return new GMSH_SpanningTreePlugin();
  }
}

GMSH_SpanningTreePlugin::GMSH_SpanningTreePlugin(void){
}

string GMSH_SpanningTreePlugin::getName(void) const{
  return "SpanningTree";
}

string GMSH_SpanningTreePlugin::getShortHelp(void) const{
  return "Builds a tree spanning every vertex of a mesh";
}

string GMSH_SpanningTreePlugin::getHelp(void) const{
  return
    "Plugin(SpanningTree) builds a tree spanning every vertex of a mesh.\n"
    "Optionally, this tree can be built by starting on a specific part.\n"
    "The generated tree is stored directly in the model.\n"
    "\n"
    "Parameters\n"
    "- PhysicalGroup: physical group upon which the tree must be built "
    "(-1 means the whole mesh).\n"
    "- StartingOn: physical group used to start the tree construction "
    "(-1 deactivates this feature).\n"
    "- OutputPhysical: physical tag of the generated tree "
    "(-1 will select a new tag automatically).\n"
    "\n"
    "Remark - This plugin does not overwrite a physical group."
    "Therefore, if an existing physical tag is used in OutputPhysical, "
    "the edges of the tree will be /added/ to the specified group.\n"
    "Limitation - Unknown behaviour with curved meshes.";
}

string GMSH_SpanningTreePlugin::getAuthor(void) const{
  return "N. Marsic";
}

int GMSH_SpanningTreePlugin::getNbOptions(void) const{
  return sizeof(SpanningTreeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SpanningTreePlugin::getOption(int iopt){
  return &SpanningTreeOptions_Number[iopt];
}

void GMSH_SpanningTreePlugin::run(void){
  // Get data
  double time  = Cpu();
  int physical = (int)SpanningTreeOptions_Number[0].def;
  int startOn  = (int)SpanningTreeOptions_Number[1].def;
  int output   = (int)SpanningTreeOptions_Number[2].def;

  // Get model
  GModel *model = GModel::current();

  // Get all elements in physical
  ElementSet element;
  getAllMElement(*model, physical, element);

  // Get all elements in startOn (if defined)
  ElementSet elementStartOn;
  if(startOn >= 0)
    getAllMElement(*model, startOn, elementStartOn);

  // Check if we have something
  if(element.empty() && elementStartOn.empty()){
    Msg::Warning("No elements found in physcial %d: abording!", physical);
    return;
  }

  // Get all edges from elements
  EdgeSet edge;
  getAllMEdge(element, edge);

  // Get all edges from startOn (if defined)
  EdgeSet edgeStartOn;
  if(startOn >= 0)
    getAllMEdge(elementStartOn, edgeStartOn);

  // Build spanning tree and save into the model (begin with startOn if defined)
  DSU  vertex(model->getNumMeshVertices());
  Tree tree;
  if(startOn >= 0)
    spanningTree(edgeStartOn, vertex, tree);

  spanningTree(edge, vertex, tree);
  addToModel(*model, tree, output);

  // Done
  Msg::Info("Spanning tree built! (%g s)", Cpu() - time);
}

void GMSH_SpanningTreePlugin::spanningTree(EdgeSet& edge,
                                           DSU& vertex, Tree& tree){
  // Kruskal's algorithm, without edge sorting, since we don't weight them //
  ///////////////////////////////////////////////////////////////////////////

  // Iterate on edges
  EdgeSet::iterator end = edge.end();
  EdgeSet::iterator  it = edge.begin();

  for(; it != end; it++){                                  // Loop on edges:
    if(vertex.find(it->first) != vertex.find(it->second)){ // if the current
      tree.push_back(*it);                                 // edge connects two
      vertex.join(it->first, it->second);                  // disjoint trees,
                                                           // use it and joint!
    }
  }
}

void GMSH_SpanningTreePlugin::getAllMElement(GModel& model,
                                             int physical, ElementSet& element){
  vector<GEntity *> entities;

  if(physical == -1){
    model.getEntities(entities, -1);
  }
  else{
    map<int, vector<GEntity *> > groups;
    model.getPhysicalGroups(-1, groups);
    entities = groups[physical];
  }

  for(size_t i = 0; i < entities.size(); i++)
    for(size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
      element.insert(entities[i]->getMeshElement(j));
}

void GMSH_SpanningTreePlugin::getAllMEdge(ElementSet& element, EdgeSet& edge){
  ElementSet::iterator end = element.end();
  ElementSet::iterator  it = element.begin();

  for(; it != end; it++)
    for(int i = 0; i < (*it)->getNumEdges(); i++)
      edge.insert(pair<int, int>((*it)->getEdge(i).getVertex(0)->getNum() - 1,
                                 (*it)->getEdge(i).getVertex(1)->getNum() - 1));
}

void GMSH_SpanningTreePlugin::addToModel(GModel& model, Tree& tree, int tag){
  // Transform Tree into MLines //
  ////////////////////////////////
  // Future MElements
  vector<MElement*> line(tree.size());

  // Populate
  Tree::iterator end = tree.end();
  Tree::iterator  it = tree.begin();

  for(int i = 0; it != end; i++, it++)
    line[i] = new MLine(model.getMeshVertexByTag(it->first  + 1),
                        model.getMeshVertexByTag(it->second + 1));

  // Add Elements as a Chain in GModel (see Chain::addToModel in Geo/Chain.h) //
  //////////////////////////////////////////////////////////////////////////////
  string      name = "";
  int    entityNum;
  int  physicalNum;
  int        max[4];

  // Get entity number
  for(int i = 0; i < 4; i++)
    max[i] = model.getMaxElementaryNumber(i);
  entityNum = *std::max_element(max, max + 4) + 1;

  // Get physcial number if not specified
  if(tag < 0){
    for(int i = 0; i < 4; i++)
      max[i] = model.getMaxPhysicalNumber(i);
    physicalNum = *std::max_element(max, max + 4) + 1;
  }
  else{
    physicalNum = tag;
  }

  // Add MLines to new entity
  map<int, vector<MElement *> > entityMap;
  entityMap[entityNum] = line;

  // Name new physical
  map<int, string> physicalInfo;
  physicalInfo[physicalNum] = name;

  // Add new physical to new entity
  map<int, map<int, string> > physicalMap;
  physicalMap[entityNum] = physicalInfo;

  // Add in GModel
  model.storeChain(1, entityMap, physicalMap);
  model.setPhysicalName(name, 1, physicalNum);
}

pair<int, int> GMSH_SpanningTreePlugin::minmax(const pair<int, int>& p){
  if(p.first < p.second)
    return pair<int, int>(p.first, p.second);
  else
    return pair<int, int>(p.second, p.first);
}

GMSH_SpanningTreePlugin::DSU::DSU(size_t n){
  // All elements are disjoint
  parent.resize(n);
  rank.resize(n, 0);

  for(size_t i = 0; i < n; i++)
    parent[i] = i;
}

GMSH_SpanningTreePlugin::DSU::~DSU(void){
  parent.clear();
  rank.clear();
}

int GMSH_SpanningTreePlugin::DSU::find(int a){
  // Path compression
  if(parent[a] != a)
    parent[a] = find(parent[a]);

  return parent[a];
}

void GMSH_SpanningTreePlugin::DSU::join(int a, int b){
  // Union by rank //
  ///////////////////

  // Get roots
  int aRoot = find(a);
  int bRoot = find(b);

  // If not in same set -> unite! Otherwise, nothing to do...
  if(aRoot != bRoot){
    if(rank[aRoot] < rank[bRoot])  // If aRoot is a smaller set
      swap(aRoot, bRoot);          // -> Swap: bRoot is always the smaller set
                                   //
    parent[bRoot] = aRoot;         // Attach smaller set (B) to bigger set (A)
                                   //
    if(rank[aRoot] == rank[bRoot]) // If both sets had the same rank
      rank[aRoot]++;               // -> Increase rank of bigger set (A)
  }
}

bool GMSH_SpanningTreePlugin::Sort::operator()(const pair<int, int>& a,
                                               const pair<int, int>& b) const{
  pair<int, int> as = minmax(a);
  pair<int, int> bs = minmax(b);

  return as < bs;
}
