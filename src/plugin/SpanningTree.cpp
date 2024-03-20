// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
// Contributed by Nicolas Marsic.

#include <sstream>
#include <algorithm>

#include "SpanningTree.h"
#include "GModel.h"
#include "MLine.h"
#include "OS.h"

using namespace std;

StringXNumber SpanningTreeOptions_Number[] = {
  {GMSH_FULLRC, "OutputPhysical", nullptr, -1},
};

StringXString SpanningTreeOptions_String[] = {
  {GMSH_FULLRC, "PhysicalVolumes", nullptr, ""},
  {GMSH_FULLRC, "PhysicalSurfaces", nullptr, ""},
  {GMSH_FULLRC, "PhysicalCurves", nullptr, ""},
};

extern "C" {
GMSH_Plugin *GMSH_RegisterSpanningTreePlugin()
{
  return new GMSH_SpanningTreePlugin();
}
}

GMSH_SpanningTreePlugin::GMSH_SpanningTreePlugin() {}

string GMSH_SpanningTreePlugin::getName() const { return "SpanningTree"; }

string GMSH_SpanningTreePlugin::getShortHelp() const
{
  return "Builds a tree spanning every vertex of a mesh";
}

string GMSH_SpanningTreePlugin::getHelp() const
{
  return "Plugin(SpanningTree) builds a tree spanning every vertex of a mesh "
         "and stores it directly in the model.\n"
         "The tree is constructed by starting first on the curves, "
         "then on the surfaces and finally on the volumes.\n"
         "\n"
         "Parameters\n"
         "- PhysicalVolumes: list of the physical volumes "
         "upon which the tree must be built.\n"
         "- PhysicalSurfaces: list of the physical surfaces "
         "upon which the tree must be built.\n"
         "- PhysicalCurves: list of the physical curves "
         "upon which the tree must be built.\n"
         "- OutputPhysical: physical tag of the generated tree "
         "(-1 will select a new tag automatically).\n"
         "\n"
         "Note - Lists must be comma separated integers "
         "and spaces are ignored.\n"
         "Remark - This plugin does not overwrite a physical group."
         "Therefore, if an existing physical tag is used in OutputPhysical, "
         "the edges of the tree will be /added/ to the specified group.";
}

string GMSH_SpanningTreePlugin::getAuthor() const { return "N. Marsic"; }

int GMSH_SpanningTreePlugin::getNbOptions() const
{
  return sizeof(SpanningTreeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SpanningTreePlugin::getOption(int iopt)
{
  return &SpanningTreeOptions_Number[iopt];
}

int GMSH_SpanningTreePlugin::getNbOptionsStr() const
{
  return sizeof(SpanningTreeOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_SpanningTreePlugin::getOptionStr(int iopt)
{
  return &SpanningTreeOptions_String[iopt];
}

int GMSH_SpanningTreePlugin::run()
{
  // Get data
  double time = Cpu(), w = TimeOfDay();
  int output = (int)SpanningTreeOptions_Number[0].def;
  string volume = SpanningTreeOptions_String[0].def;
  string surface = SpanningTreeOptions_String[1].def;
  string curve = SpanningTreeOptions_String[2].def;

  // Parse physical tags
  vector<list<int> > physical(3);
  curve = parse(curve, physical[0]);
  surface = parse(surface, physical[1]);
  volume = parse(volume, physical[2]);

  // Dimensions
  int dim[3] = {1, 2, 3};

  // Get model
  GModel *model = GModel::current();

  // Get all elements in physicals for each dimension
  vector<ElementSet> element(3);
  for(int i = 0; i < 3; i++)
    for(auto j = physical[i].begin(); j != physical[i].end(); j++)
      getAllMElement(*model, *j, dim[i], element[i]);

  // Check if we have something
  if(element[0].empty() && element[1].empty() && element[2].empty()) {
    Msg::Warning("No elements found in the given physcials: abording!");
    return 0;
  }

  // Display physicals (as [poorly] parsed)
  Msg::Info("--> PhysicalVolumes:  %s", volume.c_str());
  Msg::Info("--> PhysicalSurfaces: %s", surface.c_str());
  Msg::Info("--> PhysicalCurves:   %s", curve.c_str());
  Msg::Info("--> OutputPhysical:   %d", output);

  // Get all edges from elements for each dimension
  vector<EdgeSet> edge(3);
  for(int i = 0; i < 3; i++) getAllMEdge(element[i], edge[i]);

  // Build spanning tree (in ascending dimension order) and save into the model
  DSU vertex(model->getNumMeshVertices());
  Tree tree;
  for(int i = 0; i < 3; i++) spanningTree(edge[i], vertex, tree);

  addToModel(*model, tree, output);

  // Done
  Msg::Info("Spanning tree built (Wall %gs, CPU %gs)", TimeOfDay() - w,
            Cpu() - time);
  return 0;
}

void GMSH_SpanningTreePlugin::spanningTree(EdgeSet &edge, DSU &vertex,
                                           Tree &tree)
{
  // Kruskal's algorithm, without edge sorting, since we don't weight them

  // Iterate on edges
  for(auto it = edge.begin(); it != edge.end(); it++) { // Loop on edges:
    if(vertex.find(it->first) != vertex.find(it->second)) { // if the current
      tree.push_back(*it); // edge connects two
      vertex.join(it->first, it->second); // disjoint trees,
                                          // use it and joint!
    }
  }
}

string GMSH_SpanningTreePlugin::parse(string str, list<int> &physical)
{
  // Remove spaces
  str.erase(remove(str.begin(), str.end(), ' '), str.end());

  // Replace commas by spaces
  replace(str.begin(), str.end(), ',', ' ');

  // Init string stream
  stringstream stream;
  stream << str;

  // Parse stream for integers
  int tag;
  string tmp;
  while(!stream.eof()) {
    stream >> tmp; // Take next 'word'
    if(sscanf(tmp.c_str(), "%d", &tag) > 0) physical.push_back(tag);
  }

  // Return modified string
  return str;
}

void GMSH_SpanningTreePlugin::getAllMElement(GModel &model, int physical,
                                             int dim, ElementSet &element)
{
  std::map<int, std::vector<GEntity *> > group;

  // Get groups
  model.getPhysicalGroups(dim, group);

  // Get entities, if any
  auto entity = group.find(physical);
  if(entity == group.end()) return;

  for(size_t i = 0; i < entity->second.size(); i++)
    for(size_t j = 0; j < entity->second[i]->getNumMeshElements(); j++)
      element.insert(entity->second[i]->getMeshElement(j));
}

void GMSH_SpanningTreePlugin::getAllMEdge(ElementSet &element, EdgeSet &edge)
{
  auto end = element.end();
  auto it = element.begin();

  for(; it != end; it++)
    for(int i = 0; i < (*it)->getNumEdges(); i++)
      edge.insert(
        std::pair<int, int>((*it)->getEdge(i).getVertex(0)->getNum() - 1,
                            (*it)->getEdge(i).getVertex(1)->getNum() - 1));
}

void GMSH_SpanningTreePlugin::addToModel(GModel &model, Tree &tree, int tag)
{
  // Transform Tree into MLines

  // Future MElements
  std::vector<MElement *> line(tree.size());

  // Populate
  auto end = tree.end();
  auto it = tree.begin();

  for(int i = 0; it != end; i++, it++)
    line[i] = new MLine(model.getMeshVertexByTag(it->first + 1),
                        model.getMeshVertexByTag(it->second + 1));

  // Add Elements as a Chain in GModel (see Chain::addToModel in src/geo/Chain.h)

  std::string name = "";
  int entityNum;
  int physicalNum;
  int max[4];

  // Get entity number
  for(int i = 0; i < 4; i++) max[i] = model.getMaxElementaryNumber(i);
  entityNum = *std::max_element(max, max + 4) + 1;

  // Get physcial number if not specified
  if(tag < 0) {
    for(int i = 0; i < 4; i++) max[i] = model.getMaxPhysicalNumber(i);
    physicalNum = *std::max_element(max, max + 4) + 1;
  }
  else {
    physicalNum = tag;
  }

  // Add MLines to new entity
  std::map<int, std::vector<MElement *> > entityMap;
  entityMap[entityNum] = line;

  // Name new physical
  std::map<int, std::string> physicalInfo;
  physicalInfo[physicalNum] = name;

  // Add new physical to new entity
  std::map<int, std::map<int, std::string> > physicalMap;
  physicalMap[entityNum] = physicalInfo;

  // Add in GModel
  model.storeChain(1, entityMap, physicalMap);
  model.setPhysicalName(name, 1, physicalNum);
}

std::pair<int, int>
GMSH_SpanningTreePlugin::minmax(const std::pair<int, int> &p)
{
  if(p.first < p.second)
    return std::pair<int, int>(p.first, p.second);
  else
    return std::pair<int, int>(p.second, p.first);
}

GMSH_SpanningTreePlugin::DSU::DSU(size_t n)
{
  // All elements are disjoint
  parent.resize(n);
  rank.resize(n, 0);

  for(size_t i = 0; i < n; i++) parent[i] = i;
}

GMSH_SpanningTreePlugin::DSU::~DSU()
{
  parent.clear();
  rank.clear();
}

int GMSH_SpanningTreePlugin::DSU::find(int a)
{
  // Path compression
  if(parent[a] != a) parent[a] = find(parent[a]);

  return parent[a];
}

void GMSH_SpanningTreePlugin::DSU::join(int a, int b)
{
  // Union by rank

  // Get roots
  int aRoot = find(a);
  int bRoot = find(b);

  // If not in same set -> unite! Otherwise, nothing to do...
  if(aRoot != bRoot) {
    if(rank[aRoot] < rank[bRoot]) // If aRoot is a smaller set
      std::swap(aRoot, bRoot); // -> Swap: bRoot is always the smaller set
    parent[bRoot] = aRoot; // Attach smaller set (B) to bigger set (A)
    if(rank[aRoot] == rank[bRoot]) // If both sets had the same rank
      rank[aRoot]++; // -> Increase rank of bigger set (A)
  }
}

string GMSH_SpanningTreePlugin::DSU::toString()
{
  // Show (node, parent) [using Gmsh's 1-base index]
  stringstream str;
  for(size_t i = 0; i < parent.size(); i++)
    str << "(" << i + 1 << ", " << parent[i] + 1 << ")" << endl;

  return str.str();
}

bool GMSH_SpanningTreePlugin::Sort::operator()(
  const std::pair<int, int> &a, const std::pair<int, int> &b) const
{
  std::pair<int, int> as = minmax(a);
  std::pair<int, int> bs = minmax(b);

  return as < bs;
}
