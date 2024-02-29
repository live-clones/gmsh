#include <iostream>
#include <memory>
#include <algorithm>
#include <chrono>

#include <gmsh.h>
#include <gmsh/MTriangle.h>
#include <gmsh/GModel.h>
#include <gmsh/GModelParametrize.h>

#include <gmsh/geodesic_mesh.h>
#include <gmsh/geodesic_algorithm_dijkstra.h>
#include <gmsh/geodesic_algorithm_exact.h>

#include "meshMacro.h"

#define EPS 1e-6

int main(int argc, char* argv[]) {
  gmsh::initialize();

  std::string filename = "../0.geo"; // X, C, S, 0, 8, c3, uk
  double coeff = .2;
  int div = 10;
  int opt = 0;
  int smoothing = 0;
  double gravity = 0.1;
  double ratio = 1.;
  double clscale = 50; //64;
  double clrefine = 1.;
  int refineOption = 0;
  
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) == "-f" && i + 1 < argc) {
      filename = argv[++i];
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
    } else if (std::string(argv[i]) == "-clscale" && i + 1 < argc) {
      clscale = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-clrefine" && i + 1 < argc) {
      clrefine = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-refineOption" && i + 1 < argc) {
      refineOption = std::stoi(argv[++i]);
      continue;
    }
  }


  //
  // L O A D S
  //
  std::vector<std::size_t> macroElementNodeTags;
  std::vector<size_t> vertexTags;
  int physicalSurface, physicalBoundary, physicalPoints;
  macroMesh(filename, clscale, clrefine, vertexTags,macroElementNodeTags, refineOption);

  std::vector<MVertex*> nodes;
  std::vector<size_t> nodeTags;
  std::vector<double> nodeCoord;
  std::map<size_t,size_t> nodeTag2Index;
  std::map<MVertex *, bool> nodeIsVertex;
  constructNodes(vertexTags, nodes, nodeTags, nodeCoord, nodeTag2Index, nodeIsVertex);
  
  std::vector<MTriangle*> triangles;
  std::vector<size_t> triangleTags;
  std::vector<size_t> triangleNodeTags;
  std::map<size_t,size_t> triangleTag2Index;
  std::map<MVertex *, std::vector<MTriangle *>> node2Triangles;
  std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> edge2Triangles;
  constructTriangles(nodes, nodeTag2Index, triangles, triangleTags,
		     triangleNodeTags, triangleTag2Index, node2Triangles, edge2Triangles);

  std::vector<std::vector<MVertex *>> loops;
  std::vector<std::vector<size_t>> loopIndices;
  std::vector<std::vector<double>> loopLengthFromFirst;
  constructLoops(edge2Triangles, triangles, nodeIsVertex, loops, loopIndices, loopLengthFromFirst);

  
  // Dimentional coeffs
  double lMax = 0, lMin = std::numeric_limits<double>::max();
  for (size_t i = 0; i < triangles.size(); ++i) {
    for (int j =0; j < 3; ++j) {
      auto index0 = 3*triangleNodeTags[3*i+j];
      auto index1 = 3*triangleNodeTags[3*i+(j+1)%3];
      double dx = nodeCoord[index0+0] - nodeCoord[index1+0];
      double dy = nodeCoord[index0+1] - nodeCoord[index1+1];
      double dz = nodeCoord[index0+2] - nodeCoord[index1+2];
      double l = sqrt(dx*dx + dy*dy + dz*dz);
      if (l > lMax)
        lMax = l;
      if (l < lMin)
        lMin = l;
    }
  }
  coeff *= lMax;
  // std::cout << "lMax: " << lMax << std::endl;
  // std::cout << "lMin: " << lMin << std::endl;
  // std::cout << "coeff: " << coeff << std::endl;

  // untangle(nodeTags, nodeCoord, nodes, loops, triangles, nodeTags);

  std::map<int, std::vector<int>> startEnds;
  for (size_t i = 0; i < macroElementNodeTags.size()/3; ++i) {
    for (int j = 0; j < 3; ++j) {
      size_t i0 = macroElementNodeTags[3*i+j];
      size_t i1 = macroElementNodeTags[3*i+(j+1)%3];
      if (std::find(startEnds[i0].begin(), startEnds[i0].end(), i1) == startEnds[i0].end())
	startEnds[i0].push_back(i1);
      if (std::find(startEnds[i1].begin(), startEnds[i1].end(), i0) == startEnds[i1].end())
	startEnds[i1].push_back(i0);
    }
  }


 
  //
  // C O N S T R U C T I O N
  //
  std::map<MVertex *, bool> constrained;
  std::map<MVertex *, bool> locked;
  std::map<MTriangle *, bool> done;
  std::vector<double> newCoord(nodeCoord.size());
  for (auto n: nodes) {
    constrained[n] = false;
    locked[n] = false;
  }
  for (auto t: triangles) {
    done[t] = false;
  }
  for (size_t i = 0; i < nodeCoord.size(); ++i) {
    newCoord[i] = nodeCoord[i];
  }

  std::map<MEdge, double, MEdgeLessThan> metric;
  for (auto edge2Triangle: edge2Triangles) {
    auto edge = edge2Triangle.first;
    auto v0 = edge.getVertex(0);
    auto v1 = edge.getVertex(1);
    double m = (v0->x() + v1->x()) / 50 + 1;
    metric[edge] = m;

  }

  std::map<MEdge, double, MEdgeLessThan> edgeLength;
  for (auto edge2Triangle: edge2Triangles) {
    auto edge = edge2Triangle.first;
    edgeLength[edge] = edge.length();
    edgeLength[edge] *= metric[edge];
  }

  
  // First triangle
  auto firstT = triangles[0];
  auto v0 = firstT->getVertex(0);
  auto v1 = firstT->getVertex(1);
  auto v2 = firstT->getVertex(2);
  auto n0 = v0->getIndex();
  auto n1 = v1->getIndex();
  auto n2 = v2->getIndex();
  auto p0 = v0->point();
  auto p1 = v1->point() - p0;
  auto p2 = v2->point() - p0;
  auto m0 = sqrt(p1.x()*p1.x() + p1.y()*p1.y() + p1.z()*p1.z());
  auto ptmp = p2-p1;
  auto m1 = sqrt(ptmp.x()*ptmp.x() + ptmp.y()*ptmp.y() + ptmp.z()*ptmp.z());
  auto m2 = sqrt(p2.x()*p2.x() + p2.y()*p2.y() + p2.z()*p2.z());

  
  // std::cout << nodeTags[n0] << " " << nodeTags[n1] << " " << nodeTags[n2] << std::endl;

  p1 *= 1/m0;
  p2 = p2 - dot(p1,p2) * p1;
  double tmp = sqrt(p2.x()*p2.x() + p2.y()*p2.y() + p2.z()*p2.z());
  p2 *= 1/tmp;

  
  m0 = edgeLength[firstT->getEdge(0)];
  m1 = edgeLength[firstT->getEdge(1)];
  m2 = edgeLength[firstT->getEdge(2)];

  newCoord[3*n0+2] = 1.;
  locked[v0] = true;

  newCoord[3*n1+0] = newCoord[3*n0+0] + m0 * p1.x();
  newCoord[3*n1+1] = newCoord[3*n0+1] + m0 * p1.y();
  newCoord[3*n1+2] = newCoord[3*n0+2] + m0 * p1.z();
  locked[v1] = true;

  double theta = acos(- (m1*m1 - m0*m0 - m2*m2) /(2*m0*m2));
  // std::cout << "--- " << theta << std::endl;
  double x = cos(theta) * m2;
  double y = sin(theta) * m2;
  // std::cout << "---x " << x << std::endl;
  // std::cout << "---y " << y << std::endl;
  
  newCoord[3*n2+0] = newCoord[3*n0+0] + x * p1.x() + y * p2.x();
  newCoord[3*n2+1] = newCoord[3*n0+1] + x * p1.y() + y * p2.y();
  newCoord[3*n2+2] = newCoord[3*n0+2] + x * p1.z() + y * p2.z();
  locked[v2] = true;

  done[firstT] = true;

  
  // Other triangles
  std::list<MTriangle *> triangleList;
  std::vector<double> centerCoord(nodeCoord.size());
  for (int j = 0; j < 3; ++j) {
    auto ts = edge2Triangles[firstT->getEdge(j)];
    for (auto t: ts) {
      if (!done[t])
	triangleList.push_back(t);
    }
  }

  size_t triangleCount = 0;
  while (triangleList.size() > 0) {
    auto t = triangleList.front();
    triangleList.pop_front();
    
    int j = 0;
    MVertex *v2;
    for (; j < 3; ++j) {
      v2 = t->getVertex((j+2)%3);
      if (!locked[v2]) {
	break;
      }
    }
    if (j == 3)
      std::cout << "ERROR TRIANGLE DONE !" << std::endl;


    auto v0 = t->getVertex((j+0)%3);
    auto v1 = t->getVertex((j+1)%3);
    m0 = edgeLength[t->getEdge((j+0)%3)];
    m1 = edgeLength[t->getEdge((j+1)%3)];
    m2 = edgeLength[t->getEdge((j+2)%3)];
    auto n0 = v0->getIndex();
    auto n1 = v1->getIndex();
    auto n2 = v2->getIndex();
    // std::cout << nodeTags[n0] << " " << nodeTags[n1] << " " << nodeTags[n2] << std::endl;
    auto p1 = v1->point() - v0->point();
    double tmp = sqrt(p1.x()*p1.x() + p1.y()*p1.y() + p1.z()*p1.z());
    p1 *= 1/tmp;
    auto p2 = crossprod(SVector3(0,0,1), p1);
    tmp = sqrt(p2.x()*p2.x() + p2.y()*p2.y() + p2.z()*p2.z());
    p2 *= 1/tmp;

    if (locked[v0] && locked[v1]) {
      double theta = acos(- (m1*m1 - m0*m0 - m2*m2) / (2*m0*m2));
      // std::cout << "--- " << theta << std::endl;
      double x = cos(theta) * m2;
      double y = sin(theta) * m2;
      // std::cout << "---x " << x << std::endl;
      // std::cout << "---y " << y << std::endl;
  
      newCoord[3*n2+0] = newCoord[3*n0+0] + x * p1.x() + y * p2.x();
      newCoord[3*n2+1] = newCoord[3*n0+1] + x * p1.y() + y * p2.y();
      newCoord[3*n2+2] = newCoord[3*n0+2] + x * p1.z() + y * p2.z();

      centerCoord[3*n2+0] = newCoord[3*n0+0] + x * p1.x();
      centerCoord[3*n2+1] = newCoord[3*n0+1] + x * p1.y();
      centerCoord[3*n2+2] = newCoord[3*n0+2] + x * p1.z();

      constrained[v2] = true;
      done[t] = true;

      for (int j = 0; j < 3; ++j) {
	auto ts = edge2Triangles[t->getEdge(j)];
	for (auto t: ts) {
	  if (!done[t])
	    triangleList.push_back(t);
	}
      }

      triangleCount = 0;
      
    }
    else if (triangleCount > triangleList.size()) {
      // std::cout << "BREAK"<< std::endl;

      MVertex *v;
      for (int j = 0; j < 3; ++j) {
	v = t->getVertex(j);
	if (!locked[v] && constrained[v]) {
	  break;
	}
      }
      if (j == 3) {
	std::cout << "ERROR Triangle Done" << std::endl;
      }
      
      locked[v] = true;
      triangleList.push_front(t);
      triangleCount = 0;

    }
    else {
      // std::cout << "Nothing" << std::endl;
      ++triangleCount;
      triangleList.push_back(t);
    }

    
    
  }
  
  

  
  for (size_t i = 0; i < nodeCoord.size(); ++i) {
    nodeCoord[i] = newCoord[i];
  }

  
  // gmsh::view::add("MetricMap", 1);
  // std::string currentModel;
  // gmsh::model::getCurrent(currentModel);
  // gmsh::view::addHomogeneousModelData(1, 0, currentModel, "NodeData", nodeTags, u);

  // Move nodes in the representation
  for (size_t i = 0; i < nodes.size(); i++) {
    gmsh::model::mesh::setNode(nodeTags[i], {newCoord[3*i], newCoord[3*i+1], newCoord[3*i+2]}, {});
  }
  std::cout << "Expanded"<< std::endl;

  
  // gmsh::fltk::run();

  // Compute geodesic
  geodesic::Mesh mesh;
  std::vector<size_t> _faces(triangleNodeTags.size());
  for (size_t i = 0; i < triangleNodeTags.size(); ++i) {
    _faces[i] = (long) nodeTag2Index[triangleNodeTags[i]];
  }
  mesh.initialize_mesh_data(nodeCoord, _faces);

  std::vector<geodesic::SurfacePoint> points(nodeTags.size());
  for (size_t i = 0; i < nodeTags.size(); ++i) {
    points[i] = geodesic::SurfacePoint(&mesh.vertices()[i],
                nodeCoord[3*i], nodeCoord[3*i+1], nodeCoord[3*i+2], geodesic::VERTEX);
  }

  int count = 0;
  for (auto startEnd: startEnds) {
    std::vector<geodesic::SurfacePoint> pts_start = {points[nodeTag2Index[startEnd.first]]};
    std::vector<geodesic::SurfacePoint> pts_end;
    for (auto end: startEnd.second) {
      pts_end.push_back(points[nodeTag2Index[end]]);
      // std::cout << startEnd.first << " -> " << end << " (" << nodeTag2Index[end] << ")" << std::endl;
    }
    geodesic::GeodesicAlgorithmExact algorithm(&mesh);
    // geodesic::GeodesicAlgorithmDijkstra algorithm(&mesh, u);
    std::vector<geodesic::SurfacePoint> path;
    algorithm.propagate(pts_start, 0, &pts_end);
    for (size_t j = 0; j < pts_end.size(); j++) {
      algorithm.trace_back(pts_end[j], path);
      // std::cout << startEnd.first << " -> " << pts_end[j].base_element()->id() << std::endl;

      if (path.size() == 0) {
	std::cerr << "No paths !" << std::endl;
	return 0;
      }
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
        outputFile << i << "," << nodeCoord[3*i] << "," << nodeCoord[3*i+1] << "," << nodeCoord[3*i+2] << "\n";
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

