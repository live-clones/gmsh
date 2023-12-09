#include <iostream>
#include <memory>
#include <algorithm>
#include <chrono>

#include <gmsh.h>
#include <gmsh/MTriangle.h>
#include <gmsh/GModel.h>
#include <gmsh/GModelParametrize.h>
#include <gmsh/winslowUntangler.h>

#include <gmsh/geodesic/src/geodesic_mesh.h>
#include <gmsh/geodesic/src/geodesic_algorithm_exact.h>


#include "laplacianSmoothing.h"

#include <gmshfem/GmshFem.h>
#include <gmshfem/Formulation.h>
using namespace gmshfem::common;
using namespace gmshfem::domain;
using namespace gmshfem::post;
using namespace gmshfem::equation;
using namespace gmshfem::problem;
using namespace gmshfem::field;



#define EPS 1e-6
#define LARGE_EPS 5e-2
#define OPT 1
#define WINSLOW 1

static void filterPath(std::vector<geodesic::SurfacePoint> &path, double eps)
{
  std::vector<geodesic::SurfacePoint> filtered_path;
  filtered_path.push_back(path[0]);
  for(size_t i = 1; i < path.size(); i++) {
    SVector3 dx(filtered_path[filtered_path.size() - 1].x() - path[i].x(),
                filtered_path[filtered_path.size() - 1].y() - path[i].y(),
                filtered_path[filtered_path.size() - 1].z() - path[i].z());
    if(dx.norm() > eps) { filtered_path.push_back(path[i]); }
    else {
      if(filtered_path[filtered_path.size() - 1].type() > path[i].type()) {
        printf("filtering %22.15E %22.15E %22.15E %d %22.15E %22.15E %22.15E "
               "%d %lu/%lu\n",
               filtered_path[filtered_path.size() - 1].x(),
               filtered_path[filtered_path.size() - 1].y(),
               filtered_path[filtered_path.size() - 1].z(),
               filtered_path[filtered_path.size() - 1].type(), path[i].x(),
               path[i].y(), path[i].z(), path[i].type(), i, path.size());
        //  filtered_path[filtered_path.size() - 1] = path[i];
      }
    }
  }

  filtered_path[filtered_path.size() - 1] = path[path.size() - 1];

  path = filtered_path;
}

void periodicBoundaryConditions(const std::vector<MVertex *> & loop,
                                const std::vector<size_t> & indices,
                                const std::vector<double> & lengthFromFirst,
                                std::vector<bool> & bc,
                                std::vector<double> & u,
                                const int nodePerWavelength = 10,
                                const double l0 = 0)
{
  size_t i = 1;
  double currentLength, currentAngle, edgeLength, edgeAngle;
  for(size_t k = 0; k < indices.size(); k++) {
    edgeLength = lengthFromFirst[k];
    int nbrNodes = indices[k];
    if (k > 0) {
      edgeLength -= lengthFromFirst[k-1];
      nbrNodes -= indices[k-1];
    }
    if (l0 == 0) {
      edgeAngle = floor(nbrNodes / nodePerWavelength);
      if (edgeAngle == 0) edgeAngle = 1;
    }
    else if (l0 > 0) {
      edgeAngle = floor(edgeLength / l0);
      if (edgeAngle == 0) edgeAngle = 1;
    }
    else if (l0 == -1) {
      edgeAngle = 0;
    }
    //edgeAngle *= 2 * M_PI;
    edgeAngle *= M_PI;

    currentLength = 0;
    if (k%2) currentLength = edgeLength;
    for(; i <= indices[k]; i++) {
      currentLength += loop[i]->point().distance(loop[i - 1]->point());
      currentAngle = currentLength/edgeLength * edgeAngle;
      int index = loop[i]->getIndex();
      bc[index] = true;
      //u[index] = sin(currentAngle);
      u[index] = sin(currentAngle) * edgeLength * .2;
    }
  }
}

void expandCoord(std::vector<double> & coord,
                std::vector<MTriangle*> & triangles,
                std::map<MVertex *, int> & nbrTriangles,
                std::vector<double> & u)
{
  for (size_t i = 0; i < triangles.size(); i++) {
    auto t = triangles[i];
    auto v0 = t->getVertex(0)->point();
    auto v1 = t->getVertex(1)->point();
    auto v2 = t->getVertex(2)->point();
    auto d0 = v1 - v0;
    auto d1 = v2 - v0;
    double dx = d0.y() * d1.z() - d0.z() * d1.y();
    double dy = d0.z() * d1.x() - d0.x() * d1.z();
    double dz = d0.x() * d1.y() - d0.y() * d1.x();
    double norm = sqrt(dx*dx + dy*dy + dz*dz);
    dx /= norm;
    dy /= norm;
    dz /= norm;
    for (size_t j = 0; j < 3; j++) {
      auto v = t->getVertex(j);
      int index = v->getIndex();
      coord[3*index+0] += dx*u[index]/nbrTriangles[v];
      coord[3*index+1] += dy*u[index]/nbrTriangles[v];
      coord[3*index+2] += dz*u[index]/nbrTriangles[v];
    }
  }
}





void femSmoothing(const int physicalSurface,
                  const int physicalBoundary,
                  const int physicalPoints,
                  const double gravity,
                  const double ratio,
                  const std::vector<MVertex*> & nodes,
                  std::vector<double> & u)
{
  std::string gauss = "Gauss4";
  //const std::complex< double > im(0., 1.);

  Domain domain;
  if (physicalSurface != 0)
    domain |= Domain(2, physicalSurface);
  Domain boundary;
  if (physicalBoundary != 0)
    boundary |= Domain(1, physicalBoundary);
  Domain points;
  if (physicalPoints != 0)
    points |= Domain(0, physicalPoints);

  Formulation<double> gravityFormulation("Gravity_Formulation");

  Field<double, Form::Form0> gField("g", domain | boundary | points, FunctionSpaceTypeForm0::Lagrange);

  gravityFormulation.integral(grad(dof(gField)), grad(tf(gField)), domain, gauss);
  gravityFormulation.integral(gravity, tf(gField), domain, gauss);

  gField.addConstraint(boundary, 0.);

  gravityFormulation.pre();
  gravityFormulation.assemble();
  gravityFormulation.solve();


  save(gField);
  double minG = 0;
  auto gfunc = gField.getEvaluableFunction();
  for (size_t i = 0; i < nodes.size(); i++) {
    auto n = nodes[i];
    double tmpG = evaluate(gfunc, n->x(), n->y(), n->z());
    if (tmpG < minG) minG = tmpG;
  }



  Formulation<double> formulation("Surface_Expansion");

  Field<double, Form::Form0> uField("u", domain | boundary | points, FunctionSpaceTypeForm0::Lagrange);

  formulation.integral(grad(dof(uField)), grad(tf(uField)), domain, gauss);
  formulation.integral(-minG, tf(uField), domain, gauss);
  formulation.integral(gField, tf(uField), domain, gauss);

  formulation.integral(ratio, tf(uField), boundary, gauss);
  //formulation.integral(dof(uField), tf(uField), boundary, gauss);

  uField.addConstraint(boundary, 0.);

  formulation.pre();
  formulation.assemble();
  formulation.solve();

  save(uField);

  auto func = uField.getEvaluableFunction();
  u.resize(nodes.size());
  for (size_t i = 0; i < nodes.size(); i++) {
    auto n = nodes[i];
    int index = n->getIndex();
    u[index] = evaluate(func, n->x(), n->y(), n->z());
  }

}

void manualSmoothing(const double gravity,
                     const double ratio,
                     const std::vector<MTriangle*> & triangles,
                     const std::vector<MVertex*> & nodes,
                     const std::vector<std::vector<MVertex *>> & loops,
                     const std::vector<std::vector<size_t>> & loopIndices,
                     const std::vector<std::vector<double>> & loopLengths,
                     const std::vector<size_t> & vertexIndices,
                     std::vector<double> & u,
                     std::vector<bool> & bc,
                     const std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> & edge2Triangles)
{
  u.resize(nodes.size(),0);
  for (size_t i = 0; i < vertexIndices.size(); ++i) {
    int index = vertexIndices[i];
    u[index] = 0.;
    bc[index] = true;
  }

  size_t maxC = 1e3;
  for (size_t j = 0; j < loops.size(); ++j) {
    const std::vector<MVertex *>& loop = loops[j];
    const std::vector<size_t>& indices = loopIndices[j];
    const std::vector<double>& lengths = loopLengths[j];

    double mult = +1;
    double length = lengths[0];
    int n = indices[0];
    double density = length / n;
    size_t k = 0;

    for (size_t i = 0; i < loop.size(); ++i) {
      auto v0 = loop[i];
      auto i0 = v0->getIndex();
      if (bc[i0]) continue;

      if (i > indices[k]) {
        ++k;
        mult *= -1;
        length = lengths[k] - lengths[k-1];
        n = indices[k] - indices[k-1];
        density = length / n;
      }

      u[i0] = ratio * mult;
      //u[i0] = ratio * length * mult;
    }

    /*
    for (size_t c = 0; c < maxC; ++c) {
      mult = +1;
      length = lengths[0];
      n = indices[0];
      density = length / n;
      k = 0;
      for (size_t i = 0; i < loop.size(); ++i) {
        auto v0 = loop[i];
        auto i0 = v0->getIndex();
        if (bc[i0]) continue;

        if (i > indices[k]) {
          ++k;
          mult *= -1;
          length = lengths[k] - lengths[k-1];
          n = indices[k] - indices[k-1];
          density = length / n;
        }

        auto vm = loop[(i+loop.size()-1)%loop.size()];
        auto im = vm->getIndex();
        auto vp = loop[(i+1)%loop.size()];
        auto ip = vp->getIndex();
        //u[i0] = (u[im] + u[ip])/2 - gravity * (u[i0]-ratio * mult);
        u[i0] = (u[im] + u[ip])/2 - gravity * (u[i0] - 10 * density * mult);

      }
    }
    */

    for (size_t i = 0; i < loop.size(); ++i) {
      auto v0 = loop[i];
      auto i0 = v0->getIndex();
      bc[i0] = true;
    }
  }

  
  for (size_t c = 0; c < maxC; ++c) {
    for (size_t i = 0; i < triangles.size(); ++i) {
      auto t =  triangles[i];
      double mean = 0.;
      for (int j = 0; j < 3; ++j) {
        mean += u[t->getVertex(j)->getIndex()];
      }
      mean /= 3;
      for (int j = 0; j < 3; ++j) {
        size_t index = t->getVertex(j)->getIndex();
        if (bc[index]) continue;
        u[index] += .1 * ((mean - u[index]) - gravity * (u[index]));
        //u[index] += .1 * (mean - u[index]);
      }

    }
  }
  

  //laplacianSmoothing(nodes, edge2Triangles, loops, bc, u, 0.);

}

int main(int argc, char* argv[]) {
  GmshFem gmshFem(argc, argv);
  //gmsh::initialize();

  std::string fn = "X"; // X, C, S, 0, 8, c3, uk
  double coeff = .2;
  int div = 10;
  int opt = 0;
  int smoothing = 0;
  double gravity = 0.;
  double ratio = 0.;
  
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-f" && i + 1 < argc) {
      fn = argv[++i];
      continue;
    } else if (std::string(argv[i]) == "-c" && i + 1 < argc) {
      coeff = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-d" && i + 1 < argc) {
      div = std::stoi(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-o" && i + 1 < argc) {
      opt = std::stoi(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-s" && i + 1 < argc) {
      smoothing = std::stoi(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-g" && i + 1 < argc) {
      gravity = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-r" && i + 1 < argc) {
      ratio = std::stod(argv[++i]);
      continue;
    }
  }

  //
  // L O A D S
  //

  // Construct mesh
  std::string filename = fn;
  gmsh::open("../"+fn+".geo");
  if (OPT == 0) 
    gmsh::model::mesh::generate(2);
  else {
    gmsh::option::setNumber("Mesh.MeshSizeFactor", 150);
    gmsh::option::setNumber("Mesh.Algorithm", 3);
    gmsh::model::mesh::generate(2);
  }

  int physicalSurface = 0, physicalBoundary = 0, physicalPoints = 0;
  int surface;
  std::vector<int> edges;
  std::vector<int> verticesGeoTags;
  std::vector<size_t> vertexTags;
  std::vector<double> vertexCoord;
  std::map<int, std::vector<int>> startEnds;
  std::map<int, std::vector<int>> vertexStartEnds;
if (OPT == 0) {

  // Load vertices and surface
  gmsh::vectorpair dimTags;
  gmsh::model::getPhysicalGroups(dimTags);

  for (auto dimTag: dimTags) {
    std::string name;
    gmsh::model::getPhysicalName(dimTag.first, dimTag.second, name);
    std::vector<int> geoTags;
    gmsh::model::getEntitiesForPhysicalGroup(dimTag.first, dimTag.second, geoTags);

    if (name.substr(0, 8) == "vertices") {
      verticesGeoTags.push_back(geoTags[0]);
      size_t i0 = vertexTags.size();
      for (size_t i = 0; i < geoTags.size(); ++i) {
        std::vector<std::size_t> vertexNodeTag;
        std::vector<double> vertexCoord;
        std::vector<double> vertexParametricCoord;
        gmsh::model::mesh::getNodes(vertexNodeTag, vertexCoord, vertexParametricCoord, 0, geoTags[i]);
        vertexTags.push_back(vertexNodeTag[0]);

        for (size_t j = 0; j < vertexTags.size()-1; ++j) {
          // don't connect adjacent vertices
          if (i > 0 && j == vertexTags.size()-2)
            continue;
          if (i == geoTags.size()-1 && j == i0)
            continue;
          startEnds[vertexTags.back()].push_back(vertexTags[j]);
        }
      }

      std::cout << "vertex tag: " << geoTags[0] << std::endl;
      physicalPoints = dimTag.second;
      for (auto t: geoTags)
        verticesGeoTags.push_back(t);
      continue;
    }

    if (name.substr(0, 7) == "surface") {
      std::cout << "surface tag: " << geoTags[0] << std::endl;
      physicalSurface = dimTag.second;
      surface = geoTags[0];
      continue;
    }
    if (name.substr(0, 4) == "edge") {
      std::cout << "edge tag: " << geoTags[0] << std::endl;
      physicalBoundary = dimTag.second;
      for (auto t: geoTags)
        edges.push_back(t);
      continue;
    }

  }

}
else {

  gmsh::vectorpair dimTags;
  gmsh::model::getPhysicalGroups(dimTags);
  for (auto dimTag: dimTags) {
    std::string name;
    gmsh::model::getPhysicalName(dimTag.first, dimTag.second, name);
    std::vector<int> geoTags;
    gmsh::model::getEntitiesForPhysicalGroup(dimTag.first, dimTag.second, geoTags);
    if (name.substr(0, 7) == "surface") {
      std::cout << "surface tag: " << geoTags[0] << std::endl;
      physicalSurface = dimTag.second;
      surface = geoTags[0];
      continue;
    }
    if (name.substr(0, 4) == "edge") {
      std::cout << "edge tag: " << geoTags[0] << std::endl;
      physicalBoundary = dimTag.second;
      for (auto t: geoTags)
        edges.push_back(t);
      continue;
    }
    if (name.substr(0, 8) == "vertices") {
      std::cout << "vertex tag: " << geoTags[0] << std::endl;
      physicalPoints = dimTag.second;
      for (auto t: geoTags)
        verticesGeoTags.push_back(t);
      continue;
    }
  }

  std::vector<double> vertexParametricCoord;
  gmsh::model::mesh::getNodes(vertexTags, vertexCoord, vertexParametricCoord, 2, surface, true);

  std::vector<std::size_t> elementTags;
  std::vector<std::size_t> elementNodeTags;
  gmsh::model::mesh::getElementsByType(MSH_TRI_3, elementTags, elementNodeTags, surface);
  for (size_t i = 0; i < elementTags.size(); ++i) {
    for (int j = 0; j < 3; ++j) {
      auto n0 = elementNodeTags[3*i+j];
      auto n1 = elementNodeTags[3*i+(j+1)%3];
      vertexStartEnds[n0].push_back(n1);
    }
  }

  //gmsh::fltk::run();

  if (OPT == 1) {
    gmsh::model::mesh::clear();
    gmsh::option::setNumber("Mesh.MeshSizeFactor", 1);
    gmsh::option::setNumber("Mesh.Algorithm", 6);
    gmsh::model::mesh::generate(2);
  }
  else if (OPT == 2) {
    int nbrRefine = 3;
    for (int i = 0; i < nbrRefine; ++i) {
      gmsh::model::mesh::refine();
    }
  }
  //gmsh::fltk::run();

}

  //
  // N O D E S
  //

  // All nodes
  std::vector<std::size_t> nodeTags;
  std::vector<double> coord;
  std::vector<double> parametricCoord;
  gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, surface, true);

  std::vector<MVertex*> nodes(nodeTags.size());
  std::vector<size_t> tags(nodeTags.size());
  std::map<size_t,size_t> tag2Index;
  std::map<MVertex *, int> nbrTriangles;
  for (size_t i = 0; i < nodeTags.size(); ++i) {
    auto v = new MVertex(coord[3*i], coord[3*i+1], coord[3*i+2]);
    v->setIndex(i);
    nodes[i] = v;
    tags[i] = nodeTags[i];
    tag2Index[nodeTags[i]] = i;
    nbrTriangles[v] = 0;
  }

  // Vertices
if (OPT) {
  std::map<int, int> old2New;
  for (size_t iv = 0; iv < vertexTags.size(); ++iv) {
    int minTag = -1;
    double minDistance = std::numeric_limits<double>::max(), distance, tmp;
    for (size_t i = 0; i < nodeTags.size(); ++i) {
      distance = 0.;
      int j = 0;
      for (; j < 3; ++j) {
        tmp = coord[3*i+j]-vertexCoord[3*iv+j];
        distance += tmp*tmp;
      }
      if (distance < minDistance) {
        minTag = nodeTags[i];
        minDistance = distance;
      }
       
    }
    old2New[vertexTags[iv]] = minTag;
    vertexTags[iv] = minTag;
  }

  for (auto vertexStartEnd: vertexStartEnds) {
    auto n0 = vertexStartEnd.first;
    for (auto n1: vertexStartEnd.second) {
      // don't connect adjacent vertices
      if (std::find(vertexStartEnds[n1].begin(), vertexStartEnds[n1].end(), n0) == vertexStartEnds[n1].end())
        continue;
      if (old2New[n0] > old2New[n1])
        continue;
      startEnds[old2New[n0]].push_back(old2New[n1]);
    }
  }
}

  std::vector<size_t> vertexIndices(vertexTags.size());
  for (size_t i = 0; i < vertexTags.size(); ++i) {
    vertexIndices[i] = tag2Index[vertexTags[i]];
  }

  // Dimentional coeffs
  double lMax = 0, lMin = std::numeric_limits<double>::max();
  for (auto startEnd: startEnds) {
    auto start = startEnd.first;
    auto index0 = 3*tag2Index[start];
    for (auto end: startEnd.second) {
      auto index1 = 3*tag2Index[end];
      double dx = coord[index0+0] - coord[index1+0];
      double dy = coord[index0+1] - coord[index1+1];
      double dz = coord[index0+2] - coord[index1+2];
      double l = sqrt(dx*dx + dy*dy + dz*dz);
      if (l > lMax)
        lMax = l;
      if (l < lMin)
        lMin = l;
    }
  }
  coeff *= lMax;
  /*
  std::cout << "lMax: " << lMax << std::endl;
  std::cout << "lMin: " << lMin << std::endl;
  std::cout << "coeff: " << coeff << std::endl;
  */


  //
  // T R I A N G L E S   A N D   E D G E S
  //
  std::vector<std::size_t> elementTags;
  std::vector<std::size_t> elementNodeTags;
  gmsh::model::mesh::getElementsByType(MSH_TRI_3, elementTags, elementNodeTags, surface);

  std::vector<MTriangle*> triangles(elementTags.size());
  std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> edge2Triangles;
  for (size_t i = 0; i < elementTags.size(); ++i) {
    auto t = new MTriangle(nodes[tag2Index[elementNodeTags[3*i]]],
                           nodes[tag2Index[elementNodeTags[3*i+1]]],
                           nodes[tag2Index[elementNodeTags[3*i+2]]]);
    triangles[i] = t;
    for (int j = 0; j < 3; ++j) {
      ++nbrTriangles[t->getVertex(j)];
      edge2Triangles[t->getEdge(j)].push_back(t);
    }
  }


  //
  // L O O P S
  //

  // Find loops
  std::vector<MEdge> boundaries;
  for(auto it = edge2Triangles.begin(); it != edge2Triangles.end(); ++it) {
    if(it->second.size() == 1) { // on boundary
      boundaries.push_back(it->first);
    }
    else if(it->second.size() == 2) { // inside
    }
    else { // non-manifold: not supported
      Msg::Error("Wrong topology of triangulation for parametrization: one "
                 "edge is incident to %d triangles",
                 it->second.size());
      return false;
    }
  }

  std::vector<std::vector<MVertex *>> loops;
  if(!SortEdgeConsecutive(boundaries, loops)) {
    Msg::Error("Wrong topology of boundary mesh for parametrization");
    return false;
  }

  if (loops.empty()) {
    std::cout << "No boundary found" << std::endl;
  }

  Msg::Debug("Parametrisation of surface with %lu triangles, %lu edges and "
             "%lu holes",
             triangles.size(), edge2Triangles.size(), loops.size() - 1);

  // Check orientation of the loop and reverse if necessary
  for (size_t j = 0; j < loops.size(); j++) {
    std::vector<MVertex *>& loop = loops[j];
    bool reverse = true;
    MEdge ref(loop[0], loop[1]);
    for(std::size_t i = 0; i < triangles.size(); i++) {
      MTriangle *t = triangles[i];
      for(int j = 0; j < 3; j++) {
        MEdge e = t->getEdge(j);
        if(e.getVertex(0) == ref.getVertex(0) &&
           e.getVertex(1) == ref.getVertex(1)) {
          reverse = false;
          break;
        }
      }
      if(!reverse) break;
    }
    if(reverse) { std::reverse(loop.begin(), loop.end()); }
  }

  // Get first vertex at the front
  for (size_t j = 0; j < loops.size(); j++) {
    std::vector<MVertex *>& loop = loops[j];
    for (size_t i = 0; i < loop.size(); i++) {
      if (std::find(vertexIndices.begin(), vertexIndices.end(), loop[i]->getIndex()) != vertexIndices.end()) {
        std::rotate(loop.begin(), loop.begin()+i, loop.end()-1);
        loop[loop.size()-1] = loop[0];
        break;
      }
    }
  }

  // Get vertices positions
  std::vector<std::vector<size_t>> loopIndices(loops.size());
  std::vector<std::vector<double>> loopLengthFromFirst(loops.size());
  for(std::size_t j = 0; j < loops.size(); j++) {
    std::vector<MVertex *>& loop = loops[j];
    double l = 0.;
    for(std::size_t i = 1; i < loop.size(); i++) {
      l += loop[i]->point().distance(loop[i - 1]->point());
      if (std::find(vertexIndices.begin(), vertexIndices.end(), loop[i]->getIndex()) != vertexIndices.end()
          || i == loop.size()-1) {
        loopIndices[j].push_back(i);
        loopLengthFromFirst[j].push_back(l);
      }
    }
  }


  //
  // U N T A N G L E
  //
if (OPT == 2) {
  auto untangleStart = std::chrono::high_resolution_clock::now();
  if (!WINSLOW) {
    gmsh::model::mesh::optimize("UntangleMeshGeometry");
    gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, surface, true);
  }
  else {
    std::vector<std::array<double, 2> > untanglePoints(2*nodes.size());
    for (size_t i = 0; i < nodes.size(); ++i) {
      untanglePoints[i][0] = coord[3*i];
      untanglePoints[i][1] = coord[3*i+1];
    }

    std::vector<bool> untangleLocked(nodes.size(), false);
    for (size_t j = 0; j < loops.size(); ++j) {
      std::vector<MVertex *>& loop = loops[j];
      for (size_t i = 0; i < loop.size(); ++i) {
        int index = loop[i]->getIndex();
        untangleLocked[index] = true;
      }
    }
    
    std::vector<std::array<uint32_t, 3> > untangleTriangles(3*triangles.size());
    for (size_t i = 0; i < triangles.size(); ++i) {
      for (int j = 0; j < 3; ++j) {
        int index = triangles[i]->getVertex(j)->getIndex();
        untangleTriangles[i][j] = index;
      }
    }

    std::vector<std::array<std::array<double, 2>, 3> > untangleTriIdealShapes = {};
    double lambda = 1.;
    
    untangle_triangles_2D(untanglePoints, untangleLocked, untangleTriangles, untangleTriIdealShapes, lambda);

    for (size_t i = 0; i < nodes.size(); ++i) {
      coord[3*i] = untanglePoints[i][0];
      coord[3*i+1] = untanglePoints[i][1];
    }

//
    for (size_t i = 0; i < nodes.size(); i++) {
      gmsh::model::mesh::setNode(tags[i], {coord[3*i], coord[3*i+1], coord[3*i+2]}, {});
    }
//
  }
  auto untangleStop = std::chrono::high_resolution_clock::now();
  auto untangleDuration = std::chrono::duration_cast<std::chrono::milliseconds>(untangleStop - untangleStart);
  std::cout << "Expanded in " << untangleDuration.count()/1e3 << "sec" << std::endl;
}


  //
  // E X P A N S I O N
  //
  std::vector<double> u(nodes.size(), 0.);
  std::vector<bool> bc(nodes.size(), false);
  if (smoothing == 0) {
    // Boundary conditions
    for (size_t j = 0; j < loops.size(); ++j) {
      if (opt == 0)
        periodicBoundaryConditions(loops[j], loopIndices[j], loopLengthFromFirst[j], bc, u, div);
      else if (opt == 1)
        periodicBoundaryConditions(loops[j], loopIndices[j], loopLengthFromFirst[j], bc, u, div, lMin);
      else if (opt == 2)
        periodicBoundaryConditions(loops[j], loopIndices[j], loopLengthFromFirst[j], bc, u, div, -1);
      else
        Msg::Error("Option not defined !");
    }
    /*
    for(size_t i = 0; i < u.size(); i++)
      u[i] *= coeff;
    */
    
    laplacianSmoothing(nodes, edge2Triangles, loops, bc, u, 0.);
  }
  else if (smoothing == 1) {
    femSmoothing(physicalSurface, physicalBoundary, physicalPoints, gravity, ratio, nodes, u);
  }
  else {
    manualSmoothing(gravity, ratio*lMax, triangles, nodes, loops, loopIndices, loopLengthFromFirst, vertexIndices, u, bc, edge2Triangles);
  }
  // Move nodes perpendicularly to the surface
  expandCoord(coord, triangles, nbrTriangles, u);
  std::cout << "Pre Expanded"<< std::endl;

  // Move nodes in the representation
  for (size_t i = 0; i < nodes.size(); i++) {
    gmsh::model::mesh::setNode(tags[i], {coord[3*i], coord[3*i+1], coord[3*i+2]}, {});
  }
  std::cout << "Expanded"<< std::endl;


  // Compute geodesic
  geodesic::Mesh mesh;
  std::vector<size_t> _faces(elementNodeTags.size());
  for (size_t i = 0; i < elementNodeTags.size(); ++i) {
    _faces[i] = (long) tag2Index[elementNodeTags[i]];
  }
  mesh.initialize_mesh_data(coord, _faces);

  std::vector<geodesic::SurfacePoint> points(nodeTags.size());
  for (size_t i = 0; i < nodeTags.size(); ++i) {
    points[i] = geodesic::SurfacePoint(&mesh.vertices()[i],
                coord[3*i], coord[3*i+1], coord[3*i+2], geodesic::VERTEX);
  }

  int count = 0;
  for (auto startEnd: startEnds) {
    std::vector<geodesic::SurfacePoint> pts_start = {points[tag2Index[startEnd.first]]};
    std::vector<geodesic::SurfacePoint> pts_end;
    for (auto end: startEnd.second) {
      pts_end.push_back(points[tag2Index[end]]);
    }
    geodesic::GeodesicAlgorithmExact algorithm(&mesh);
    std::vector<geodesic::SurfacePoint> path;
    algorithm.propagate(pts_start, 0, &pts_end);
    for (size_t j = 0; j < pts_end.size(); j++) {
      algorithm.trace_back(pts_end[j], path);
      filterPath(path, EPS); // fixme use relative error

      // Add path
      std::vector<int> pathTags(path.size());
      std::vector<int> pathLines(path.size()-1);
      for (size_t i = 0; i < path.size(); ++i)
        pathTags[i] = gmsh::model::geo::addPoint(path[i].x(), path[i].y(), path[i].z());
      for (size_t i = 0; i < path.size()-1; ++i)
        pathLines[i] = gmsh::model::geo::addLine(pathTags[i], pathTags[i+1]);
      gmsh::model::geo::synchronize();

      if (false) {
        // Write path
        std::ofstream outputFile3(filename + "Path"+ std::to_string(count) +".csv");
        if (outputFile3.is_open()) {
          outputFile3 << "id,x,y,z" << std::endl;
          for (size_t i = 0; i < path.size(); ++i) {
            int index = path[i].base_element()->id();
            outputFile3 << index << "," << path[i].x() << "," << path[i].y() << "," << path[i].z() << "\n";
          }

          outputFile3.close();
          std::cout << "Data saved to " << filename + "Path"+ std::to_string(count) +".csv" << std::endl;
        }
      }
      count++;
    }
  }


  //
  // W R I T I N G S
  //
  
  if (false) {
    // Write points
    std::ofstream outputFile(filename + "Coord.csv");
    if (outputFile.is_open()) {
      outputFile << "id,x,y,z" << std::endl;
      for (size_t i = 0; i < nodeTags.size(); ++i) {
        outputFile << i << "," << coord[3*i] << "," << coord[3*i+1] << "," << coord[3*i+2] << "\n";
      }

      outputFile.close();
      std::cout << "Data saved to " << filename + "Coord.csv" << std::endl;
    }
  }

  gmsh::write(filename+".msh");


  if (argc < 2 || std::string(argv[1]) != "-nopopup") {
    gmsh::fltk::run();
  }

  for (auto triangle: triangles) {
    delete triangle;
  }
  for (auto node: nodes) {
    delete node;
  }

  //gmsh::finalize();

  return 0;
}

