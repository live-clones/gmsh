// Check the boundary relations of the partition topology on a multi-domain
// model.
//
// A square made of two layers is meshed and partitioned for several mesh sizes
// and numbers of partitions. For every partition curve that has mesh elements,
// the surfaces that list it in their boundary must be exactly those whose
// elements have an edge on it. Only the built-in geometry kernel is used.
//
// The program prints the mismatches and returns 1 if there are any.

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <gmsh.h>

using Facet = std::vector<std::size_t>; // sorted corner node tags

// Two rectangles sharing the line y = 0.5
static void twoLayerSquare()
{
  namespace geo = gmsh::model::geo;
  const double xy[6][2] = {{0, 0}, {1, 0}, {1, 0.5}, {0, 0.5}, {1, 1}, {0, 1}};
  std::vector<int> p;
  for(auto &c : xy) p.push_back(geo::addPoint(c[0], c[1], 0));
  int l0 = geo::addLine(p[0], p[1]), l1 = geo::addLine(p[1], p[2]);
  int l2 = geo::addLine(p[2], p[3]), l3 = geo::addLine(p[3], p[0]);
  int l4 = geo::addLine(p[2], p[4]), l5 = geo::addLine(p[4], p[5]);
  int l6 = geo::addLine(p[5], p[3]);
  geo::addPlaneSurface({geo::addCurveLoop({l0, l1, l2, l3})});
  geo::addPlaneSurface({geo::addCurveLoop({-l2, l4, l5, l6})});
  geo::synchronize();
}

// The elements of an entity, as sorted corner node tags
static std::vector<Facet> elements(int dim, int tag)
{
  std::vector<int> types;
  std::vector<std::vector<std::size_t> > elementTags, nodeTags;
  gmsh::model::mesh::getElements(types, elementTags, nodeTags, dim, tag);
  std::vector<Facet> out;
  for(std::size_t i = 0; i < types.size(); i++) {
    std::string name;
    int d, order, numNodes, numPrimary;
    std::vector<double> localCoord;
    gmsh::model::mesh::getElementProperties(types[i], name, d, order, numNodes,
                                            localCoord, numPrimary);
    for(std::size_t k = 0; k < nodeTags[i].size(); k += numNodes) {
      Facet f(nodeTags[i].begin() + k, nodeTags[i].begin() + k + numPrimary);
      std::sort(f.begin(), f.end());
      out.push_back(f);
    }
  }
  return out;
}

// The edges of the triangles of a surface
static std::set<Facet> facets(int tag)
{
  std::set<Facet> out;
  for(auto &e : elements(2, tag)) {
    for(std::size_t skip = 0; skip < e.size(); skip++) {
      Facet f;
      for(std::size_t j = 0; j < e.size(); j++)
        if(j != skip) f.push_back(e[j]);
      out.insert(f);
    }
  }
  return out;
}

// Returns the number of wrong relations for one model
static int check(double lc, int numPartitions)
{
  gmsh::model::add("partition_brep");
  twoLayerSquare();
  gmsh::option::setNumber("Mesh.MeshSizeMin", lc);
  gmsh::option::setNumber("Mesh.MeshSizeMax", lc);
  gmsh::model::mesh::generate(2);
  gmsh::model::mesh::partition(numPartitions);

  std::map<int, std::set<Facet> > bulk; // partition surface -> its edges
  std::map<int, std::set<int> > listing; // curve -> who lists it
  gmsh::vectorpair entities;
  gmsh::model::getEntities(entities, 2);
  for(auto &e : entities) {
    std::vector<int> partitions;
    gmsh::model::getPartitions(e.first, e.second, partitions);
    if(partitions.size() != 1) continue;
    bulk[e.second] = facets(e.second);
    gmsh::vectorpair boundary;
    gmsh::model::getBoundary({e}, boundary, false, false, false);
    for(auto &b : boundary) listing[std::abs(b.second)].insert(e.second);
  }

  int wrong = 0;
  gmsh::model::getEntities(entities, 1);
  for(auto &e : entities) {
    std::vector<int> partitions;
    gmsh::model::getPartitions(e.first, e.second, partitions);
    if(partitions.empty()) continue;
    std::vector<Facet> own = elements(1, e.second);
    if(own.empty()) continue;
    std::set<int> touching;
    for(auto &b : bulk)
      for(auto &f : own)
        if(b.second.count(f)) {
          touching.insert(b.first);
          break;
        }
    const std::set<int> &lists = listing[e.second];
    for(int t : touching)
      if(!lists.count(t)) {
        std::cout << "lc=" << lc << " nPart=" << numPartitions << ": curve "
                  << e.second << " is bounded by surface " << t
                  << " but not in its boundary\n";
        wrong++;
      }
    for(int t : lists)
      if(!touching.count(t)) {
        std::cout << "lc=" << lc << " nPart=" << numPartitions << ": curve "
                  << e.second << " is in the boundary of surface " << t
                  << " without touching it\n";
        wrong++;
      }
  }
  gmsh::model::remove();
  return wrong;
}

int main(int argc, char **argv)
{
  gmsh::initialize(argc, argv);
  gmsh::option::setNumber("General.Verbosity", 1);
  int wrong = 0;
  for(double lc : {0.15, 0.1, 0.07, 0.05})
    for(int n = 3; n <= 16; n++) wrong += check(lc, n);
  gmsh::finalize();
  std::cout << wrong << " wrong boundary relation(s)\n";
  return wrong ? 1 : 0;
}
