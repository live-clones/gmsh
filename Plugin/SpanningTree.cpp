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
  {GMSH_FULLRC, "PhysicalGroup", NULL, -1},
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
  return "Plugin(SpanningTree) builds a tree spanning every vertex of a mesh.";
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
  double start = Cpu();
  int physical = (int)SpanningTreeOptions_Number[0].def;

  // Get model
  GModel *model = GModel::current();

  // Get all elements in physical
  ElementSet element;
  getAllMElement(*model, physical, element);

  // Check if we have something
  if(element.empty()){
    Msg::Warning("No elements found in physcial %d: abording!", physical);
    return;
  }

  // Get all edges from elements
  EdgeSet edge;
  getAllMEdge(element, edge);

  // Build spanning tree and save into the model
  list<pair<int, int> > tree;
  spanningTree(edge, model->getNumMeshVertices(), tree);
  addToModel(*model, tree);

  // Done
  double stop = Cpu();
  Msg::Info("Spanning tree built! (%g s)", stop - start);
}

void GMSH_SpanningTreePlugin::spanningTree(EdgeSet& edge, size_t nv,
                                           list<pair<int, int> >& tree){
  // Kruskal's algorithm, without edge sorting, since we don't weight them //
  ///////////////////////////////////////////////////////////////////////////

  // Initiate forest with each vertex being a tree
  DSU set(nv);

  // Iterate on edges
  EdgeSet::iterator end = edge.end();
  EdgeSet::iterator  it = edge.begin();

  for(; it != end; it++){
    if(set.find(it->first) != set.find(it->second)){ // If this edge connects
      tree.push_back(*it);                           // two disjoint tree,
      set.join(it->first, it->second);               // use it and joint :)!
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

void GMSH_SpanningTreePlugin::addToModel(GModel& model,
                                         list<pair<int, int> >& tree){
  // Transform Tree into MLines //
  ////////////////////////////////
  // Future MElements
  vector<MElement*> line(tree.size());

  // Populate
  list<pair<int, int> >::iterator end = tree.end();
  list<pair<int, int> >::iterator  it = tree.begin();

  for(int i = 0; it != end; i++, it++)
    line[i] = new MLine(model.getMeshVertexByTag(it->first  + 1),
                        model.getMeshVertexByTag(it->second + 1));

  // Add Elements as a Chain in GModel (see Chain::addToModel in Geo/Chain.h) //
  //////////////////////////////////////////////////////////////////////////////
  // Get entity number, physcial number and name
  string name = "";
  int    max[4];
  for(int i = 0; i < 4; i++)
    max[i] = model.getMaxElementaryNumber(i);
  int entityNum = *std::max_element(max, max + 4) + 1;

  for(int i = 0; i < 4; i++)
    max[i] = model.getMaxPhysicalNumber(i);
  int physicalNum = *std::max_element(max, max + 4) + 1;

  map<int, vector<MElement *> > entityMap;
  entityMap[entityNum] = line;

  map<int, string> physicalInfo;
  physicalInfo[physicalNum] = name;

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
