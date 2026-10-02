// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <gmsh.h>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#if defined(MESH_CORE_EXTEND_FIELD_TEST)
void testCoreExtendField();
#endif

static void require(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

static void close(const std::vector<double> &actual,
                  const std::vector<double> &expected,
                  const std::string &message)
{
  require(actual.size() == expected.size(), message + ": wrong output size");
  for(std::size_t i = 0; i < actual.size(); ++i) {
    require(std::isfinite(actual[i]) &&
              std::abs(actual[i] - expected[i]) < 1.e-8,
            message + " at index " + std::to_string(i) + ": got " +
              std::to_string(actual[i]) + ", expected " +
              std::to_string(expected[i]));
  }
}

static void checkNode(std::size_t node, const std::vector<double> &expected)
{
  std::vector<double> coord, param;
  int dim, tag;
  gmsh::model::mesh::getNode(node, coord, param, dim, tag);
  close(coord, expected, "node lookup after adding elements");
  require(dim == 3 && tag == 1, "node classification changed");
}

static void checkTet(std::size_t element, double x,
                     const std::vector<std::size_t> &expectedNodes)
{
  std::vector<std::size_t> nodes;
  int type, dim, tag;
  gmsh::model::mesh::getElement(element, type, nodes, dim, tag);
  require(type == 4 && dim == 3 && tag == 1 && nodes == expectedNodes,
          "element lookup after adding elements");

  std::size_t found;
  double u, v, w;
  gmsh::model::mesh::getElementByCoordinates(x + 0.1, 0.1, 0.1, found, type,
                                            nodes, u, v, w, 3, true);
  require(found == element && type == 4 && nodes == expectedNodes,
          "spatial lookup after adding elements");
  close({u, v, w}, {0.1, 0.1, 0.1}, "tetrahedron local coordinates");
}

static void meshCaches()
{
  gmsh::model::add("mesh caches");
  gmsh::model::addDiscreteEntity(3, 1);
  gmsh::model::mesh::addNodes(
    3, 1, {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
     3, 0, 0, 4, 0, 0, 3, 1, 0, 3, 0, 1,
     6, 0, 0, 7, 0, 0, 6, 1, 0, 6, 0, 1});

  // Populate the node cache before either addition API is used.
  checkNode(10, {0, 0, 0});
  checkNode(120, {6, 0, 1});
  gmsh::model::mesh::addElements(3, 1, {4}, {{101}}, {{10, 20, 30, 40}});
  checkTet(101, 0, {10, 20, 30, 40});

  // Both the element lookup and spatial index now exist. Each addition must
  // invalidate them while preserving correct lookup of the existing nodes.
  gmsh::model::mesh::addElementsByType(1, 4, {102}, {50, 60, 70, 80});
  checkNode(50, {3, 0, 0});
  checkTet(102, 3, {50, 60, 70, 80});
  checkTet(101, 0, {10, 20, 30, 40});

  gmsh::model::mesh::addElements(3, 1, {4}, {{103}}, {{90, 100, 110, 120}});
  checkNode(10, {0, 0, 0});
  checkNode(120, {6, 0, 1});
  checkTet(103, 6, {90, 100, 110, 120});
  checkTet(102, 3, {50, 60, 70, 80});
}

static void checkInside(int dim, int tag, const std::vector<double> &points,
                        const std::vector<int> &expected, bool parametric)
{
  std::vector<double> coord = points;
  if(parametric) gmsh::model::getParametrization(dim, tag, points, coord);
  const std::size_t stride = parametric ? dim : 3;
  require(coord.size() == stride * expected.size(), "classification input size");
  int count = 0;
  for(std::size_t i = 0; i < expected.size(); ++i) {
    std::vector<double> point(coord.begin() + stride * i,
                              coord.begin() + stride * (i + 1));
    require(gmsh::model::isInside(dim, tag, point, parametric) == expected[i],
            "single point classification at index " + std::to_string(i));
    count += expected[i];
  }
  // Repeat the batch to exercise reuse after both scalar and batch queries.
  for(int i = 0; i < 2; ++i)
    require(gmsh::model::isInside(dim, tag, coord, parametric) == count,
            "batch classification disagrees with individual points");
}

static void occClassification()
{
  gmsh::model::add("OCC classification");
  int box = gmsh::model::occ::addBox(0, 0, 0, 1, 1, 1);
  int other = gmsh::model::occ::addBox(3, 0, 0, 1, 1, 1);
  int outer = gmsh::model::occ::addRectangle(0, 3, 0, 2, 2);
  int hole = gmsh::model::occ::addRectangle(0.75, 3.75, 0, 0.5, 0.5);
  gmsh::vectorpair faces;
  std::vector<gmsh::vectorpair> map;
  gmsh::model::occ::cut({{2, outer}}, {{2, hole}}, faces, map);
  require(faces.size() == 1 && faces[0].first == 2, "rectangle with hole");
  const int face = faces[0].second;
  gmsh::model::occ::synchronize();

  const std::vector<double> points = {
    0.5, 0.5, 0.5, 0, 0.5, 0.5, 1.2, 0.5, 0.5, 3.5, 0.5, 0.5};
  checkInside(3, box, points, {1, 1, 0, 0}, false);
  checkInside(3, other, points, {0, 0, 0, 1}, false);
  checkInside(2, face,
              {0.2, 3.2, 0, 1, 4, 0, 0, 4, 0, 0.75, 4, 0},
              {1, 0, 1, 1}, true);

  // Synchronization must not retain the classifier for the previous shape.
  gmsh::model::occ::translate({{3, box}}, 10, 0, 0);
  gmsh::model::occ::dilate({{2, face}}, 0, 3, 0, 2, 2, 2);
  gmsh::model::occ::synchronize();
  checkInside(3, box, points, {0, 0, 0, 0}, false);
  checkInside(3, box,
              {10.5, 0.5, 0.5, 10, 0.5, 0.5, 11.2, 0.5, 0.5},
              {1, 1, 0}, false);
  checkInside(3, other, points, {0, 0, 0, 1}, false);
  checkInside(2, face,
              {0.4, 3.4, 0, 2, 5, 0, 0, 5, 0, 1.5, 5, 0},
              {1, 0, 1, 1}, true);
}

static void discreteProjection()
{
  gmsh::model::add("folded discrete surface");
  gmsh::model::addDiscreteEntity(2, 1);
  // Two squares sharing an edge: the first has normal +z, the second -x.
  gmsh::model::mesh::addNodes(2, 1, {1, 2, 3, 4, 5, 6},
                             {0, 0, 0, 1, 0, 0, 1, 0, 1,
                              0, 1, 0, 1, 1, 0, 1, 1, 1});
  gmsh::model::mesh::addElementsByType(1, 2, {1, 2, 3, 4},
                                      {1, 2, 4, 2, 5, 4, 2, 3, 5, 3, 6, 5});
  gmsh::model::mesh::createGeometry({{2, 1}});

  // Distant queries must still find the exact closest point. Include points
  // whose closest feature is a triangle interior, boundary edge or corner.
  const std::vector<double> queries = {
    0.25, 0.25, -10, 10, 0.25, 0.25, 1.2, 0.5, -0.2,
    -2, 0.4, -1, -2, -3, -1};
  const std::vector<double> expected = {
    0.25, 0.25, 0, 1, 0.25, 0.25, 1, 0.5, 0,
    0, 0.4, 0, 0, 0, 0};
  for(int i = 0; i < 2; ++i) {
    std::vector<double> closest, uv, reconstructed, normals;
    gmsh::model::getClosestPoint(2, 1, queries, closest, uv);
    close(closest, expected, "projection on folded discrete surface");
    gmsh::model::getValue(2, 1, uv, reconstructed);
    close(reconstructed, expected, "projection UV round trip");
    require(uv.size() >= 4, "missing projection parameters");
    gmsh::model::getNormal(1, {uv[0], uv[1], uv[2], uv[3]}, normals);
    close(normals, {0, 0, 1, -1, 0, 0}, "normal orientation across fold");
  }
}

int main(int argc, char **argv)
{
  try {
    require(argc == 2, "expected a regression case name");
    gmsh::initialize(0, nullptr, false);
    const std::string test = argv[1];
    if(test == "mesh_caches") meshCaches();
    else if(test == "occ_classification") occClassification();
    else if(test == "discrete_projection") discreteProjection();
#if defined(MESH_CORE_EXTEND_FIELD_TEST)
    else if(test == "extend_field_first_evaluation") testCoreExtendField();
#endif
    else throw std::runtime_error("unknown regression case: " + test);
    gmsh::finalize();
    return 0;
  } catch(const std::exception &error) {
    std::cerr << error.what() << '\n';
  } catch(const std::string &error) {
    std::cerr << error << '\n';
  } catch(...) {
    std::cerr << "Unexpected Gmsh API error\n";
  }
  if(gmsh::isInitialized()) gmsh::finalize();
  return 1;
}
