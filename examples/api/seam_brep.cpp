// Preserve every signed use of a boundary entity: the seam of a cylinder is
// used twice by its lateral surface, and an internal surface can be used twice
// by a volume. Check the MSH3 tag setters and MSH4 pointer setters in both file
// encodings. With --partition, also check the signed partition topology of an
// imported cylinder (requires METIS).

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#include <gmsh.h>

using Entity = std::pair<int, int>;
using Boundaries = std::map<Entity, gmsh::vectorpair>;

static void require(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

static gmsh::vectorpair boundary(const Entity &entity)
{
  gmsh::vectorpair out;
  gmsh::model::getBoundary({entity}, out, false, true, false);
  return out;
}

static Boundaries boundaries()
{
  Boundaries out;
  for(int dim : {2, 3}) {
    gmsh::vectorpair entities;
    gmsh::model::getEntities(entities, dim);
    for(const auto &entity : entities) {
      auto b = boundary(entity);
      std::sort(b.begin(), b.end());
      out[entity] = b;
    }
  }
  return out;
}

static bool hasOppositeUses(const gmsh::vectorpair &b)
{
  std::set<Entity> uses(b.begin(), b.end());
  for(const auto &use : b)
    if(uses.count({use.first, -use.second})) return true;
  return false;
}

static bool hasSurfaceSeam()
{
  const auto all = boundaries();
  for(const auto &entry : all)
    if(entry.first.first == 2 && hasOppositeUses(entry.second)) return true;
  return false;
}

struct MeshFile {
  std::string name;
  explicit MeshFile(const std::string &name) : name(name) {}
  ~MeshFile() { std::remove(name.c_str()); }
};

static void roundTrip(const std::string &name, double version, bool binary)
{
  const Boundaries expected = boundaries();
  MeshFile file(name);
  gmsh::option::setNumber("Mesh.MshFileVersion", version);
  gmsh::option::setNumber("Mesh.Binary", binary);
  gmsh::write(file.name);
  gmsh::clear();
  gmsh::open(file.name);
  const Boundaries actual = boundaries();
  if(actual != expected) {
    for(const auto &entry : expected) {
      const auto found = actual.find(entry.first);
      if(found != actual.end() && found->second == entry.second) continue;
      std::cerr << file.name << ": changed signed boundary of entity ("
                << entry.first.first << ", " << entry.first.second << ")\n";
      std::cerr << "  expected:";
      for(const auto &b : entry.second) std::cerr << " " << b.second;
      std::cerr << "\n  actual:";
      if(found != actual.end())
        for(const auto &b : found->second) std::cerr << " " << b.second;
      std::cerr << "\n";
    }
    throw std::runtime_error(file.name + ": signed boundary changed");
  }
}

static void cylinder(int meshDimension)
{
  gmsh::clear();
  gmsh::model::add("cylinder_seam");
  gmsh::model::occ::addCylinder(0, 0, 0, 0, 0, 1, 0.5);
  gmsh::model::occ::synchronize();
  gmsh::model::mesh::generate(meshDimension);
  require(hasSurfaceSeam(), "Cylinder must have a surface using a seam twice");
}

static void repeatedSurface()
{
  gmsh::clear();
  gmsh::model::add("repeated_surface");
  gmsh::model::addDiscreteEntity(2, 1);
  gmsh::model::mesh::addNodes(2, 1, {1, 2, 3},
                              {0, 0, 0, 1, 0, 0, 0, 1, 0});
  gmsh::model::mesh::addElementsByType(1, 2, {1}, {1, 2, 3});
  gmsh::model::addDiscreteEntity(3, 1, {1, -1});
  require(hasOppositeUses(boundary({3, 1})),
          "Volume must retain both signed uses of its internal surface");
}

static void checkImports()
{
  for(int kind = 0; kind < 2; kind++) {
    int format = 0;
    for(double version : {3.0, 4.1, 4.2}) {
      for(int binary = 0; binary < 2; binary++) {
        // Every encoding starts from the source model, so a broken earlier
        // round trip cannot become the reference for a later one.
        if(kind == 0)
          cylinder(2);
        else
          repeatedSurface();
        roundTrip("seam_brep_import_" + std::to_string(kind) + "_" +
                    std::to_string(format) + "_" + std::to_string(binary) +
                    ".msh",
                  version, binary);
      }
      format++;
    }
  }
}

// A signed boundary must itself have zero boundary. Curve boundaries returned
// by the API list the begin and end vertices without signs, in that order.
static void checkClosedBoundary(const Entity &entity)
{
  const auto b = boundary(entity);
  require(!b.empty(), "Partition entity has no boundary");
  std::map<int, int> coefficients;
  for(const auto &use : b) {
    require(use.second != 0, "Boundary contains a zero entity tag");
    const int sign = use.second > 0 ? 1 : -1;
    const auto bb = boundary({use.first, std::abs(use.second)});
    if(entity.first == 2) {
      // A closed curve may have no endpoints at all, or the same vertex as
      // both endpoints. Either representation has zero boundary.
      require(bb.empty() || bb.size() == 2,
              "Partition curve must have either zero or two endpoints");
      if(bb.size() == 2) {
        coefficients[std::abs(bb[0].second)] -= sign;
        coefficients[std::abs(bb[1].second)] += sign;
      }
    }
    else {
      for(const auto &edge : bb) {
        require(edge.second != 0, "Boundary contains a zero curve tag");
        coefficients[std::abs(edge.second)] +=
          sign * (edge.second > 0 ? 1 : -1);
      }
    }
  }
  for(const auto &entry : coefficients)
    if(entry.second) {
      throw std::runtime_error(
        "Nonzero boundary of boundary for entity (" +
        std::to_string(entity.first) + ", " + std::to_string(entity.second) +
        ") at tag " + std::to_string(entry.first) + ": " +
        std::to_string(entry.second));
    }
}

static void checkPartitions()
{
  cylinder(3);
  // Exercise reconstruction after import, where every seam is discrete. One
  // partition isolates this from duplicate entities along partition interfaces.
  roundTrip("seam_brep_partition_source.msh", 4.2, true);
  gmsh::model::mesh::partition(1);
  bool volume = false, seam = false;
  for(int dim : {2, 3}) {
    gmsh::vectorpair entities;
    gmsh::model::getEntities(entities, dim);
    for(const auto &entity : entities) {
      std::vector<int> partitions;
      gmsh::model::getPartitions(dim, entity.second, partitions);
      if(partitions.empty()) continue;
      require(partitions == std::vector<int>{1},
              "Expected every partition entity to belong to partition 1");
      checkClosedBoundary(entity);
      if(dim == 2 && hasOppositeUses(boundary(entity))) seam = true;
      if(dim == 3) volume = true;
    }
  }
  require(volume, "Expected a partition volume entity");
  require(seam, "One-partition cylinder lost the two signed seam uses");
  // Partition-entity B-Reps must also survive the MSH4 serialization path.
  roundTrip("seam_brep_partition.msh", 4.2, false);
}

int main(int argc, char **argv)
{
  bool partition = false;
  for(int i = 1; i < argc; i++)
    if(std::string(argv[i]) == "--partition") partition = true;

  // Do not inherit user settings that change mesh types or disable topology.
  gmsh::initialize(0, nullptr, false);
  gmsh::option::setNumber("General.Verbosity", 1);
  gmsh::option::setNumber("General.NumThreads", 1);
  gmsh::option::setNumber("Mesh.MeshSizeMin", 0.3);
  gmsh::option::setNumber("Mesh.MeshSizeMax", 0.3);
  gmsh::option::setNumber("Mesh.SaveAll", 1);
  gmsh::option::setNumber("Mesh.PartitionCreateTopology", 1);
  int result = EXIT_SUCCESS;
  try {
    if(partition)
      checkPartitions();
    else
      checkImports();
  }
  catch(const std::exception &e) {
    std::cerr << "seam_brep: " << e.what() << "\n";
    result = EXIT_FAILURE;
  }
  gmsh::finalize();
  return result;
}
