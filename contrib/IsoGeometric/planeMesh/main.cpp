#include <iostream>
#include <memory>
#include <algorithm>

#include <gmsh.h>
#include <gmsh/MTriangle.h>
#include <gmsh/GModel.h>
#include <gmsh/GModelParametrize.h>

#include <gmsh/geodesic/src/geodesic_mesh.h>
#include <gmsh/geodesic/src/geodesic_algorithm_exact.h>

#if defined(HAVE_SOLVER)
#include <gmsh/linearSystemPETSc.h>
#include <gmsh/linearSystemCSR.h>
#include <gmsh/linearSystemFull.h>
#endif


#define EPS 1e-6
#define CREATEGEO false

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
      edgeAngle = 1;
    }
    edgeAngle *= 2 * M_PI;

    currentLength = 0;
    for(; i <= indices[k]; i++) {
      currentLength += loop[i]->point().distance(loop[i - 1]->point());
      currentAngle = currentLength/edgeLength * edgeAngle;
      int index = loop[i]->getIndex();
      bc[index] = true;
      u[index] = sin(currentAngle);
    }
  }
}

void laplacianSmoothing(const std::vector<MVertex *> & nodes,
                        const std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> & edges,
                        const std::vector<std::vector<MVertex *> > & loops,
                        const std::vector<bool> & bc,
                        std::vector<double> & u)
{
  // assemble matrix
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
  std::string options = "-ksp_type preonly -pc_type lu ";
#if defined(PETSC_HAVE_MUMPS)
  options += "-pc_factor_mat_solver_type mumps";
#elif defined(PETSC_HAVE_MKL_PARDISO)
  options += "-pc_factor_mat_solver_type mkl_pardiso";
#elif defined(PETSC_HAVE_UMFPACK) || defined(PETSC_HAVE_SUITESPARSE)
  options += "-pc_factor_mat_solver_type umfpack";
#endif
  lsys->setParameter("petsc_solver_options", options);
  lsys->setParameter("matrix_reuse", "same_matrix");
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif

  lsys->allocate(nodes.size());

#if defined(HAVE_PETSC)
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        lsys->insertInSparsityPattern(it->first.getVertex(i)->getIndex(),
                                      it->first.getVertex(j)->getIndex());
      }
    }
  }
#endif

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    for(int ij = 0; ij < 2; ij++) {
      MVertex *v0 = it->first.getVertex(ij);
      int index0 = v0->getIndex();
      if(bc[index0]) continue; // boundary condition
      MVertex *v1 = it->first.getVertex(1 - ij);
      int index1 = v1->getIndex();
      MTriangle *tLeft = it->second[0];
      MVertex *vLeft = tLeft->getVertex(0);
      if(vLeft == v0 || vLeft == v1) vLeft = tLeft->getVertex(1);
      if(vLeft == v0 || vLeft == v1) vLeft = tLeft->getVertex(2);
      double e[3] = {v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z()};
      double ne = sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
      double a[3] = {vLeft->x() - v0->x(), vLeft->y() - v0->y(),
                     vLeft->z() - v0->z()};
      double na = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
      double thetaL =
        acos((a[0] * e[0] + a[1] * e[1] + a[2] * e[2]) / (na * ne));
      double thetaR = 0.;
      if(it->second.size() == 2) {
        MTriangle *tRight = it->second[1];
        MVertex *vRight = tRight->getVertex(0);
        if(vRight == v0 || vRight == v1) vRight = tRight->getVertex(1);
        if(vRight == v0 || vRight == v1) vRight = tRight->getVertex(2);
        double b[3] = {vRight->x() - v0->x(), vRight->y() - v0->y(),
                       vRight->z() - v0->z()};
        double nb = sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
        thetaR = acos((b[0] * e[0] + b[1] * e[1] + b[2] * e[2]) / (nb * ne));
      }
      double c = (tan(.5 * thetaL) + tan(.5 * thetaR)) / ne;
      lsys->addToMatrix(index0, index1, -c);
      lsys->addToMatrix(index0, index0, c);
    }
  }
  for(std::size_t j = 0; j < loops.size(); j++) {
    auto loop = loops[j];
    for(std::size_t i = 0; i < loop.size() - 1; i++) {
      int row = loop[i]->getIndex();
      lsys->addToMatrix(row, row, 1);
    }
  }

  lsys->zeroRightHandSide();
  for(std::size_t j = 0; j < loops.size(); j++) {
    auto loop = loops[j];
    for(std::size_t i = 0; i < loop.size() - 1; i++) {
      int row = loop[i]->getIndex();
      lsys->addToRightHandSide(row, u[row]);
    }
  }
  lsys->systemSolve();
  for(std::size_t i = 0; i < nodes.size(); i++) lsys->getFromSolution(i, u[i]);

  delete lsys;
#endif
}



int main(int argc, char* argv[]) {
  gmsh::initialize();
  
  std::string fn = "X"; // X, C, S, 0, 8, c3, uk
  double coeff = .1;
  int div = 10;
  int opt = 0;
  
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
    }
  }

  //
  // L O A D S
  //

  // Construct mesh
  std::string filename = fn;
  gmsh::open("../"+fn+".geo");
  gmsh::model::mesh::generate(2);

  // Load vertices and surface
  gmsh::vectorpair dimTags;
  gmsh::model::getPhysicalGroups(dimTags);

  std::vector<size_t> vertexTags;
  std::map<int, std::vector<int>> startEnds;
  size_t surface;
  for (auto dimTag: dimTags) {
    std::string name;
    gmsh::model::getPhysicalName(dimTag.first, dimTag.second, name);
    std::vector<int> geoTags;
    gmsh::model::getEntitiesForPhysicalGroup(dimTag.first, dimTag.second, geoTags);

    if (name.substr(0, 8) == "vertices") {
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
    }
    else if (name.substr(0, 7) == "surface") {
      surface = geoTags[0];
    }
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
  std::vector<size_t> vertexIndices(vertexTags.size());
  for (size_t i = 0; i < vertexTags.size(); ++i)
    vertexIndices[i] = tag2Index[vertexTags[i]];

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
  std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> edges;
  for (size_t i = 0; i < elementTags.size(); ++i) {
    auto t = new MTriangle(nodes[tag2Index[elementNodeTags[3*i]]],
                           nodes[tag2Index[elementNodeTags[3*i+1]]],
                           nodes[tag2Index[elementNodeTags[3*i+2]]]);
    triangles[i] = t;
    for (int j = 0; j < 3; ++j) {
      ++nbrTriangles[t->getVertex(j)];
      edges[t->getEdge(j)].push_back(t);
    }
  }


  //
  // L O O P S
  //

  // Find loops
  std::vector<MEdge> boundaries;
  for(auto it = edges.begin(); it != edges.end(); ++it) {
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

  std::vector<std::vector<MVertex *> > loops;
  if(!SortEdgeConsecutive(boundaries, loops)) {
    Msg::Error("Wrong topology of boundary mesh for parametrization");
    return false;
  }

  if (!loops.empty()) {
    Msg::Debug("Parametrisation of surface with %lu triangles, %lu edges and "
               "%lu holes",
               triangles.size(), edges.size(), loops.size() - 1);

    // Check orientation of the loop and reverse if necessary
    for (size_t j = 0; j < loops.size(); j++) {
      auto loop = loops[j];
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
      auto loop = loops[j];
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
      auto loop = loops[j];
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

    // Boundary conditions
    std::vector<double> u(nodes.size(), 0.);
    std::vector<bool> bc(nodes.size(), false);
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
    for(size_t i = 0; i < u.size(); i++)
      u[i] *= coeff;

    // Smoothing
    laplacianSmoothing(nodes, edges, loops, bc, u);

    // Move nodes perpendicularly to the surface
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
    for (size_t i = 0; i < nodes.size(); i++) {
      int index = nodes[i]->getIndex();
      gmsh::model::mesh::setNode(tags[index], {coord[3*index], coord[3*index+1], coord[3*index+2]}, {});
    }
  }

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

  gmsh::finalize();

  return 0;
}

