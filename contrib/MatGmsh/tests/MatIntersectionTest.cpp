#include "MatPipeline.h"
#include <iostream>
#include <stdexcept>

using namespace matgmsh_native;

namespace {
Mesh mesh(std::vector<double> xyz, std::vector<int> triangles)
{
  Mesh result;
  result.xyz = std::move(xyz);
  result.triangles = std::move(triangles);
  result.branch.assign(result.triangles.size() / 3, 0);
  result.parent.assign(result.branch.size(), 0);
  return result;
}

void expect(const Mesh &input, bool valid, const char *name)
{
  const auto coordinates = input.xyz;
  const auto triangles = input.triangles;
  std::string error;
  const bool actual = validateNoSelfIntersections(input, error);
  if(actual != valid)
    throw std::runtime_error(std::string(name) + ": " +
                             (actual ? "intersection missed" : error));
  if(input.xyz != coordinates || input.triangles != triangles)
    throw std::runtime_error("Intersection check modified its input");
}

Mesh box(double lo, double hi)
{
  return mesh({lo,lo,lo, hi,lo,lo, hi,hi,lo, lo,hi,lo,
               lo,lo,hi, hi,lo,hi, hi,hi,hi, lo,hi,hi},
              {0,2,1, 0,3,2, 4,5,6, 4,6,7,
               0,1,5, 0,5,4, 1,2,6, 1,6,5,
               2,3,7, 2,7,6, 3,0,4, 3,4,7});
}

void expectContained(const Mesh &input, const Mesh &skin, bool valid,
                     const char *name)
{
  const auto coordinates = input.xyz;
  const auto connectivity = input.triangles;
  std::string error;
  const bool actual = validateContainedInSkin(input, skin, error);
  if(actual != valid)
    throw std::runtime_error(std::string(name) + ": " +
                             (actual ? "skin crossing missed" : error));
  if(input.xyz != coordinates || input.triangles != connectivity)
    throw std::runtime_error("Containment check modified its input");
}
}

int main()
{
  gmsh::initialize();
  try {
    expect(mesh({0,0,0, 2,0,0, 0,2,0, .5,.5,-1, .5,.5,1, 1.5,.5,0},
                {0,1,2, 3,4,5}), false, "interior crossing");
    expect(mesh({0,0,0, 2,0,0, 0,2,0, 0,0,1, 2,0,1, 0,2,1},
                {0,1,2, 3,4,5}), true, "parallel sheets");
    expect(mesh({0,0,0, 2,0,0, 0,2,0, 0,0,2},
                {0,1,2, 1,0,3}), true, "shared folded edge");
    expect(mesh({0,0,0, 2,0,0, 0,2,0, -2,0,0, 0,-2,0},
                {0,1,2, 0,3,4}), true, "shared vertex");
    expect(mesh({0,0,0, 2,0,0, 0,2,0, .5,.5,-1, .5,.5,1},
                {0,1,2, 0,3,4}), false, "crossing beyond shared vertex");
    expect(mesh({0,0,0, 2,0,0, 0,2,0, .25,.25,0, 1,.25,0, .25,1,0},
                {0,1,2, 3,4,5}), false, "coplanar containment");
    expect(mesh({0,0,0, 2,0,0, 0,2,0, .5,.5,0},
                {0,1,2, 0,1,3}), false, "coplanar overlap sharing edge");
    expect(mesh({0,0,0, 2,0,0, 0,2,0, 0,-2,0, 0,0,2},
                {0,1,2, 1,0,3, 0,1,4}), true, "three-sheet junction");
    expect(mesh({0,0,0, 2,0,0, 0,2,0},
                {0,1,2, 2,1,0}), false, "duplicate triangle");
    expect(mesh({0,0,0, 1,0,0, 2,0,0}, {0,1,2}), false, "degenerate triangle");
    const Mesh skin = box(-1., 1.);
    expectContained(mesh({-.8,-.8,0, .8,-.8,0, 0,.8,0}, {0,1,2}),
                    skin, true, "inside triangle");
    expectContained(mesh({-.8,-.8,0, .8,-.8,0, 0,1.,0}, {0,1,2}),
                    skin, true, "triangle touching skin");
    expectContained(mesh({-.8,-.8,0, .8,-.8,0, 0,1.2,0}, {0,1,2}),
                    skin, false, "outside vertex with inside centroid");
    Mesh hollow = box(-2., 2.);
    const Mesh cavity = box(-.25, .25);
    hollow.xyz.insert(hollow.xyz.end(), cavity.xyz.begin(), cavity.xyz.end());
    for(std::size_t f = 0; f < cavity.triangles.size(); f += 3) {
      hollow.triangles.insert(hollow.triangles.end(),
                             {cavity.triangles[f] + 8, cavity.triangles[f + 2] + 8,
                              cavity.triangles[f + 1] + 8});
      hollow.branch.push_back(0); hollow.parent.push_back(0);
    }
    // All three vertices and the original centroid belong to material;
    // only co-refinement reveals the triangle portion crossing the cavity.
    expectContained(mesh({-1,-1,0, 1,-1,0, 0,1,0}, {0,1,2}),
                    hollow, false, "cavity crossing with inside vertices and centroid");
    std::cout << "Native intersection and containment checks passed (14 fixtures)\n";
  }
  catch(const std::exception &error) {
    std::cerr << error.what() << '\n';
    gmsh::finalize();
    return 1;
  }
  gmsh::finalize();
  return 0;
}
