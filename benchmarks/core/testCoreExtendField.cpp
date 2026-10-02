// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <gmsh.h>
#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
void checkField(int field, std::size_t element, int numNodes, double expected)
{
  // Model data preserves the entity passed to the field. List data would
  // evaluate with a null entity, which Extend deliberately ignores.
  int view = gmsh::view::add("Extend field probe");
  gmsh::view::addModelData(view, 0, "extend", "ElementNodeData", {element},
                           {std::vector<double>(numNodes, 0.)}, 0., 1);
  gmsh::plugin::setNumber("MeshSizeFieldView", "MeshSizeField", field);
  gmsh::plugin::setNumber("MeshSizeFieldView", "View",
                          gmsh::view::getIndex(view));
  gmsh::plugin::run("MeshSizeFieldView");
  std::string type;
  std::vector<std::size_t> tags;
  std::vector<std::vector<double>> data;
  double time;
  int numComponents;
  gmsh::view::getModelData(view, 0, type, tags, data, time, numComponents);
  gmsh::view::remove(view);
  if(data.size() != 1 || data[0].size() != (std::size_t)numNodes)
    throw std::runtime_error("Unexpected Extend field probe data");
  for(double value : data[0]) {
    // A negative expected value denotes an entity outside the field's lists.
    bool valid = expected < 0 ? value > 1.e20 :
                               std::abs(value - expected) < 1.e-12;
    if(!std::isfinite(value) || !valid)
      throw std::runtime_error("Extend field on element " +
                               std::to_string(element) + ": got " +
                               std::to_string(value) + ", expected " +
                               std::to_string(expected));
  }
}
} // namespace

void testCoreExtendField()
{
  gmsh::model::add("extend");
  std::vector<double> coords{0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
                             0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
  const std::vector<std::vector<std::size_t>> edges{
    {1, 2}, {2, 3}, {3, 4}, {4, 1}, {5, 6}, {6, 7},
    {7, 8}, {8, 5}, {1, 5}, {2, 6}, {3, 7}, {4, 8}};
  const std::vector<std::vector<int>> boundaries{
    {1, 2, 3, 4}, {5, 6, 7, 8}, {1, 10, 5, 9},
    {2, 11, 6, 10}, {3, 12, 7, 11}, {4, 9, 8, 12}};
  const std::vector<std::vector<std::size_t>> quads{
    {1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 6, 5},
    {2, 3, 7, 6}, {3, 4, 8, 7}, {4, 1, 5, 8}};
  for(int i = 1; i <= 12; ++i) gmsh::model::addDiscreteEntity(1, i);
  for(int i = 1; i <= 6; ++i)
    gmsh::model::addDiscreteEntity(2, i, boundaries[i - 1]);
  gmsh::model::addDiscreteEntity(3, 1, {1, 2, 3, 4, 5, 6});
  gmsh::model::mesh::addNodes(3, 1, {1, 2, 3, 4, 5, 6, 7, 8}, coords);
  for(std::size_t i = 0; i < edges.size(); ++i)
    gmsh::model::mesh::addElementsByType(i + 1, 1, {i + 1}, edges[i]);
  for(std::size_t i = 0; i < quads.size(); ++i)
    gmsh::model::mesh::addElementsByType(i + 1, 3, {i + 21}, quads[i]);
  gmsh::model::mesh::addElementsByType(1, 5, {100}, {1, 2, 3, 4, 5, 6, 7, 8});

  int field = gmsh::model::mesh::field::add("Extend");
  gmsh::model::mesh::field::setNumber(field, "Ratio", 1.);
  gmsh::model::mesh::field::setNumbers(field, "SurfacesList", {1});
  gmsh::model::mesh::field::setNumbers(field, "VolumesList", {1});
  // Every boundary edge has length 1: Ratio=1 gives a constant field of 1.
  // Check the first surface evaluation, then both changes of mesh dimension.
  checkField(field, 21, 4, 1.);
  checkField(field, 100, 8, 1.);
  checkField(field, 21, 4, 1.);

  // Also exercise an invalidated field whose first evaluation is a volume.
  gmsh::model::mesh::field::setNumbers(field, "VolumesList", {1});
  checkField(field, 100, 8, 1.);
  checkField(field, 21, 4, 1.);

  // After changing the mesh and invalidating the field, an excluded entity
  // must not leave the old search trees available for the next valid query.
  for(std::size_t i = 0; i < 8; ++i)
    gmsh::model::mesh::setNode(i + 1,
                              {2 * coords[3 * i], 2 * coords[3 * i + 1],
                               2 * coords[3 * i + 2]}, {});
  gmsh::model::mesh::field::setNumbers(field, "SurfacesList", {1});
  checkField(field, 22, 4, -1.);
  checkField(field, 21, 4, 2.);
  checkField(field, 100, 8, 2.);
}
