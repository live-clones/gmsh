#include "MatPipeline.h"
#include "MatExtensionInternal.h"
#include "DiscreteCADArrangement.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
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

double triangleArea(const Mesh &m, std::size_t f)
{
  double a[3], b[3], n[3];
  for(int k = 0; k < 3; k++) {
    a[k] = m.xyz[3 * m.triangles[3 * f + 1] + k] -
           m.xyz[3 * m.triangles[3 * f] + k];
    b[k] = m.xyz[3 * m.triangles[3 * f + 2] + k] -
           m.xyz[3 * m.triangles[3 * f] + k];
  }
  for(int k = 0; k < 3; k++)
    n[k] = a[(k + 1) % 3] * b[(k + 2) % 3] -
           a[(k + 2) % 3] * b[(k + 1) % 3];
  return .5 * std::sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
}

Mesh refine(const Mesh &input, const char *name,
            std::vector<int> *vertexMap = nullptr,
            const std::vector<int> *cutTarget = nullptr)
{
  const auto coordinates = input.xyz;
  const auto connectivity = input.triangles;
  Mesh result;
  std::string error;
  if(!meshCoRefine(input.xyz, input.triangles, result.xyz, result.triangles,
                   result.parent, error, vertexMap, cutTarget))
    throw std::runtime_error(std::string(name) + ": " + error);
  if(input.xyz != coordinates || input.triangles != connectivity)
    throw std::runtime_error("Co-refinement modified its input");
  if(result.triangles.size() != 3 * result.parent.size())
    throw std::runtime_error("Co-refinement lost triangle provenance");
  std::vector<double> coverage(input.triangles.size() / 3, 0.);
  for(std::size_t f = 0; f < result.parent.size(); f++) {
    const int p = result.parent[f];
    if(p < 0 || std::size_t(p) >= coverage.size())
      throw std::runtime_error("Co-refinement returned invalid provenance");
    const double area = triangleArea(result, f);
    if(!(area > 0.))
      throw std::runtime_error("Co-refinement returned a degenerate face");
    coverage[p] += area;
  }
  for(std::size_t f = 0; f < coverage.size(); f++) {
    const double expected = cutTarget && (*cutTarget)[f] >= 0 ?
                              0. : triangleArea(input, f);
    if(std::abs(coverage[f] - expected) >
       1.e-12 * std::max(1., expected))
      throw std::runtime_error(std::string(name) + ": parent area changed");
  }
  if(vertexMap) {
    if(vertexMap->size() != input.xyz.size() / 3)
      throw std::runtime_error("Co-refinement lost input vertex mapping");
    for(std::size_t v = 0; v < vertexMap->size(); v++) {
      const int w = (*vertexMap)[v];
      if(w < 0 || std::size_t(w) >= result.xyz.size() / 3)
        throw std::runtime_error("Co-refinement returned invalid vertex mapping");
      for(int k = 0; k < 3; k++)
        if(input.xyz[3 * v + k] != result.xyz[3 * w + k])
          throw std::runtime_error("Co-refinement moved an original vertex");
    }
  }
  // Coplanar overlaps deliberately carry a copy for every source. Audit the
  // underlying unique geometry, while coverage above checks every source copy.
  Mesh unique;
  unique.xyz = result.xyz;
  std::set<std::array<int, 3> > seen;
  for(std::size_t f = 0; f < result.parent.size(); f++) {
    std::array<int, 3> key = {{result.triangles[3 * f],
                             result.triangles[3 * f + 1],
                             result.triangles[3 * f + 2]}};
    std::sort(key.begin(), key.end());
    if(seen.insert(key).second) {
      for(int k = 0; k < 3; k++)
        unique.triangles.push_back(result.triangles[3 * f + k]);
      unique.branch.push_back(0);
      unique.parent.push_back(result.parent[f]);
    }
  }
  expect(unique, true, name);
  return result;
}

void expectContact(const Mesh &result, int incidence0, int incidence1,
                   const char *name)
{
  std::map<std::pair<int, int>, std::vector<int> > edges;
  for(std::size_t f = 0; f < result.parent.size(); f++)
    for(int k = 0; k < 3; k++)
      edges[std::minmax(result.triangles[3 * f + k],
                        result.triangles[3 * f + (k + 1) % 3])]
        .push_back(result.parent[f]);
  double length = 0.;
  for(const auto &e : edges) {
    const int n0 = std::count(e.second.begin(), e.second.end(), 0);
    const int n1 = std::count(e.second.begin(), e.second.end(), 1);
    if(!n0 || !n1) continue;
    if(n0 != incidence0 || n1 != incidence1)
      throw std::runtime_error(std::string(name) + ": wrong contact incidence");
    const int a = e.first.first, b = e.first.second;
    for(int v : {a, b})
      if(result.xyz[3 * v] != 0. || result.xyz[3 * v + 2] != 0. ||
         std::abs(result.xyz[3 * v + 1]) > .5)
        throw std::runtime_error(std::string(name) + ": spurious contact");
    length += std::abs(result.xyz[3 * a + 1] - result.xyz[3 * b + 1]);
  }
  if(std::abs(length - 1.) > 1.e-12)
    throw std::runtime_error(std::string(name) + ": contact has a gap");
}

void expectMalformed(std::vector<double> xyz, std::vector<int> tri,
                     const std::vector<int> *cutTarget = nullptr)
{
  const std::vector<double> initialXYZ = {7., 8., 9.};
  const std::vector<int> initial = {42};
  std::vector<double> output = initialXYZ;
  std::vector<int> triangles = initial, birth = initial, mapping = initial;
  std::string error;
  if(meshCoRefine(xyz, tri, output, triangles, birth, error, &mapping,
                  cutTarget) ||
     error.empty())
    throw std::runtime_error("Malformed co-refinement input was accepted");
  if(output != initialXYZ || triangles != initial || birth != initial ||
     mapping != initial)
    throw std::runtime_error("Failed co-refinement modified output arrays");
}

Mesh containmentSkin()
{
  return mesh({-2,-2,-1, 2,-2,-1, 2,2,-1, -2,2,-1,
               -2,-2,1, 2,-2,1, 2,2,1, -2,2,1},
              {0,2,1,0,3,2, 4,5,6,4,6,7,
               0,1,5,0,5,4, 1,2,6,1,6,5,
               2,3,7,2,7,6, 3,0,4,3,4,7});
}

void translate(Mesh &m, const std::array<double,3> &offset)
{
  for(std::size_t v = 0; v < m.xyz.size()/3; v++)
    for(int k = 0; k < 3; k++) m.xyz[3*v+k] += offset[k];
}

Mesh subdivideSkin(Mesh m, int levels)
{
  for(int level = 0; level < levels; level++) {
    Mesh next;
    next.xyz = m.xyz;
    std::map<std::pair<int,int>,int> midpoint;
    auto middle = [&](int a, int b) {
      const auto edge = std::minmax(a,b);
      auto found = midpoint.find(edge);
      if(found != midpoint.end()) return found->second;
      const int v = int(next.xyz.size()/3);
      for(int k = 0; k < 3; k++)
        next.xyz.push_back(.5*(m.xyz[3*a+k]+m.xyz[3*b+k]));
      midpoint[edge] = v;
      return v;
    };
    for(std::size_t f = 0; f < m.triangles.size()/3; f++) {
      const int a = m.triangles[3*f], b = m.triangles[3*f+1],
                c = m.triangles[3*f+2];
      const int ab = middle(a,b), bc = middle(b,c), ca = middle(c,a);
      next.triangles.insert(next.triangles.end(),
        {a,ab,ca, ab,b,bc, ca,bc,c, ab,bc,ca});
    }
    next.branch.assign(next.triangles.size()/3,0);
    next.parent.assign(next.branch.size(),0);
    m = std::move(next);
  }
  return m;
}

void expectExtensionContainment(const Mesh &input, const Mesh &skin,
                                bool valid, const char *name,
                                bool requirePositiveRoundoffArea = false)
{
  const Mesh savedInput = input, savedSkin = skin;
  std::string error;
  double outsideArea = -1.;
  const bool actual = validateExtensionContainment(input,skin,error,&outsideArea);
  if(actual != valid)
    throw std::runtime_error(std::string(name) + ": " +
                            (actual ? "outside area was accepted" : error));
  if(!actual && error.empty())
    throw std::runtime_error(std::string(name) + ": rejection has no reason");
  if(actual && (!std::isfinite(outsideArea) || outsideArea < 0.))
    throw std::runtime_error(std::string(name) + ": invalid outside-area report");
  if(actual && requirePositiveRoundoffArea && !(outsideArea > 0.))
    throw std::runtime_error(std::string(name) + ": fixture lost its nonzero sliver");
  if(input.xyz != savedInput.xyz || input.triangles != savedInput.triangles ||
     input.branch != savedInput.branch || input.parent != savedInput.parent ||
     skin.xyz != savedSkin.xyz || skin.triangles != savedSkin.triangles ||
     skin.branch != savedSkin.branch || skin.parent != savedSkin.parent)
    throw std::runtime_error("Extension containment check modified an input");
}

void extensionContainmentChecks()
{
  const Mesh skin = containmentSkin();
  expectExtensionContainment(
    mesh({-1,-1,0, 1,-1,0, 1,1,0, -1,1,0},{0,1,2,0,2,3}),
    skin,true,"extension wholly inside material");

  Mesh hollow = skin;
  const int offset = int(hollow.xyz.size()/3);
  for(std::size_t v = 0; v < skin.xyz.size()/3; v++) {
    hollow.xyz.push_back(.25*skin.xyz[3*v]);
    hollow.xyz.push_back(.25*skin.xyz[3*v+1]);
    hollow.xyz.push_back(.5*skin.xyz[3*v+2]);
  }
  for(std::size_t f = 0; f < skin.triangles.size()/3; f++)
    hollow.triangles.insert(hollow.triangles.end(),
      {offset+skin.triangles[3*f],offset+skin.triangles[3*f+2],
       offset+skin.triangles[3*f+1]});
  hollow.branch.assign(hollow.triangles.size()/3,0);
  hollow.parent.assign(hollow.branch.size(),0);
  expectExtensionContainment(
    mesh({-1,-1,0, 1,-1,0, 0,1,0},{0,1,2}),hollow,false,
    "extension triangle crossing enclosed cavity");

  const double next = std::nextafter(2.,std::numeric_limits<double>::infinity());
  const double ulp = next-2.;
  const double above = 2.+64.*ulp;
  expectExtensionContainment(
    mesh({-.5,above,-.5, .5,above,-.5, 0,above,.5},{0,1,2}),
    skin,false,"outside face beyond coordinate-roundoff radius");

  // Only the tip protrudes one representable coordinate step. Its tiny
  // descendant has positive area, and all its vertices lie in the roundoff
  // neighborhood of a single convex skin triangle.
  const Mesh sliver = mesh({-.5,1,0, .5,1,0, 0,next,0},{0,1,2});
  expectExtensionContainment(sliver,skin,true,
                             "one-ulp boundary sliver",true);
  Mesh larger = sliver;
  larger.xyz[7] = 2.+1.e-4;
  expectExtensionContainment(larger,skin,false,
                             "finite boundary protrusion is not roundoff");

  const std::array<double,3> shift = {{1.e6,-2.e6,3.e6}};
  Mesh movedSkin = skin, movedSliver = sliver;
  translate(movedSkin,shift); translate(movedSliver,shift);
  // Recreate the ulp after translation: translating the original tiny offset
  // would round it away and turn this into a vacuous acceptance test.
  const double plane = 2.+shift[1];
  const double movedNext = std::nextafter(plane,std::numeric_limits<double>::infinity());
  movedSliver.xyz[7] = movedNext;
  expectExtensionContainment(movedSliver,movedSkin,true,
                             "translated one-ulp boundary sliver",true);
  Mesh movedOutside = mesh({-.5,2.,-.5, .5,2.,-.5, 0,2.,.5},{0,1,2});
  translate(movedOutside,shift);
  for(std::size_t v = 0; v < movedOutside.xyz.size()/3; v++)
    movedOutside.xyz[3*v+1] = movedNext;
  expectExtensionContainment(movedOutside,movedSkin,false,
                             "translated finite-area face one ulp outside");

  // Every vertex is within the coordinate radius, but a finite fraction of
  // the triangle lies outside. Radius checks alone must not authorize it.
  // Refining the skin must not multiply the per-source area allowance.
  const Mesh nearPlane = mesh(
    {-.5,2.-ulp,-.5, .5,next,-.5, 0,next,.5},{0,1,2});
  expectExtensionContainment(nearPlane,skin,false,
                             "near-plane face exceeds source area allowance");
  expectExtensionContainment(nearPlane,subdivideSkin(skin,3),false,
                             "skin subdivision cannot multiply area allowance");
}
}

int main()
{
  gmsh::initialize();
  try {
    const Mesh crossing = refine(
      mesh({-2,-2,0, 2,-2,0, 0,2,0, 0,-1,-1, 0,1,-1, 0,0,1},
           {0,1,2, 3,4,5}), "open transverse co-refinement");
    expectContact(crossing, 2, 2, "open transverse co-refinement");
    // The exact intersection belongs to y=3. Dividing separately rounded
    // homogeneous numerator/denominator gives 2.9999999999999996 for one of
    // these points. Such drift becomes a real skin crossing in the next call.
    const Mesh planeContact = refine(
      mesh({0,3,0, 5.2,3,0, 0,3,6.7,
            1,2.712,1.2, 1,3.432,1.2, 2,3.432,1.2},
           {0,1,2, 3,4,5}), "exact representable plane contact");
    bool newContact = false;
    for(std::size_t f = 0; f < planeContact.parent.size(); f++)
      for(int k = 0; k < 3; k++) {
        const int v = planeContact.triangles[3 * f + k];
        if(planeContact.parent[f] == 0 && planeContact.xyz[3 * v + 1] != 3.)
          throw std::runtime_error("Intersection export moved off y=3");
        if(planeContact.parent[f] == 1 && planeContact.xyz[3 * v + 2] != 1.2)
          throw std::runtime_error("Intersection export moved off z=1.2");
        newContact |= planeContact.xyz[3 * v + 1] == 3. &&
                      planeContact.xyz[3 * v + 2] == 1.2;
      }
    if(!newContact)
      throw std::runtime_error("Representable plane fixture has no contact");
    // The contact ends strictly inside the large triangle at both ends: its
    // endpoints and segment must split that triangle, not merely the T stem.
    const Mesh finiteT = refine(
      mesh({-2,-2,0, 2,-2,0, 0,2,0, 0,-.5,0, 0,.5,0, 0,0,1},
           {0,1,2, 3,4,5}), "finite interior T co-refinement");
    expectContact(finiteT, 2, 1, "finite interior T co-refinement");
    std::vector<int> vertexMap;
    const Mesh duplicateVertices = refine(
      mesh({0,0,0, 1,0,0, 0,1,0, 0,0,0, 0,1,0, -1,0,0},
           {0,1,2, 3,4,5}), "duplicate vertex co-refinement", &vertexMap);
    if(vertexMap[0] != vertexMap[3] || vertexMap[2] != vertexMap[4] ||
       duplicateVertices.xyz.size() != 12)
      throw std::runtime_error("Equal input vertices do not share one identity");
    const Mesh overlap = refine(
      mesh({0,0,0, 2,0,0, 0,2,0, .25,.25,0, 1,.25,0, .25,1,0},
           {0,1,2, 3,4,5}), "coplanar co-refinement lineage");
    std::map<std::array<int, 3>, std::set<int> > sources;
    for(std::size_t f = 0; f < overlap.parent.size(); f++) {
      std::array<int, 3> key = {{overlap.triangles[3 * f],
                               overlap.triangles[3 * f + 1],
                               overlap.triangles[3 * f + 2]}};
      std::sort(key.begin(), key.end());
      sources[key].insert(overlap.parent[f]);
    }
    bool sharedCopy = false;
    for(const auto &s : sources) sharedCopy |= s.second.size() == 2;
    if(!sharedCopy)
      throw std::runtime_error("Coplanar overlap lost source multiplicity");
    // The cutter also crosses the adjacent triangle and the nearby parallel
    // sheet geometrically, but is allowed to cut only source triangle 1. The
    // adjacent triangle still needs the shared diagonal split. A degenerate
    // source preceding the target verifies that target IDs survive compaction.
    const Mesh selectiveInput = mesh(
      {0,0,0, 2,0,0, 2,2,0, 0,2,0,
       0,0,.25, 2,0,.25, 2,2,.25,
       1,-1,-1, 1,3,-1, 1,3,1, 1,-1,1},
      {0,0,0, 0,1,2, 0,2,3, 4,5,6, 7,8,9, 7,9,10});
    const std::vector<int> cutTarget = {-1,-1,-1,-1,1,1};
    const Mesh selective = refine(selectiveInput, "selective shadow cutter",
                                   nullptr, &cutTarget);
    if(std::count(selective.parent.begin(), selective.parent.end(), 1) < 2 ||
       std::count(selective.parent.begin(), selective.parent.end(), 2) != 2 ||
       std::count(selective.parent.begin(), selective.parent.end(), 3) != 1)
      throw std::runtime_error("Selective cutter reached an unrelated triangle");
    int midpoint = -1;
    for(std::size_t v = 0; v < selective.xyz.size() / 3; v++)
      if(selective.xyz[3 * v] == 1. && selective.xyz[3 * v + 1] == 1. &&
         selective.xyz[3 * v + 2] == 0.)
        midpoint = int(v);
    if(midpoint < 0)
      throw std::runtime_error("Selective cutter lost the shared edge split");
    std::set<int> midpointSources;
    for(std::size_t f = 0; f < selective.parent.size(); f++)
      for(int k = 0; k < 3; k++)
        if(selective.triangles[3 * f + k] == midpoint)
          midpointSources.insert(selective.parent[f]);
    if(midpointSources != std::set<int>({1, 2}))
      throw std::runtime_error("Selective cutter created a nonconforming split");
    expectMalformed({0.,0.}, {});
    expectMalformed({0.,0.,0.}, {0,0});
    expectMalformed({0.,0.,0.}, {-1,0,0});
    expectMalformed({0.,0.,0.}, {0,1,0});
    expectMalformed({0.,0.,std::numeric_limits<double>::quiet_NaN()}, {});
    for(const std::vector<int> &invalid :
        std::vector<std::vector<int> >{{}, {-2}, {1}, {0}})
      expectMalformed({0.,0.,0.}, {0,0,0}, &invalid);
    extensionContainmentChecks();
    std::cout << "Native open co-refinement checks passed (24 fixtures)\n";
  }
  catch(const std::exception &error) {
    std::cerr << error.what() << '\n';
    gmsh::finalize();
    return 1;
  }
  gmsh::finalize();
  return 0;
}
