#include <iostream>
#include <memory>
#include <algorithm>
#include <chrono>

#include <gmsh.h>
#include <gmsh/MTriangle.h>
#include <gmsh/GModel.h>
#include <gmsh/GModelParametrize.h>

#include <gmsh/geodesic_mesh.h>
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
  double ratio = .5;
  double clscale = 50; // 64
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

  // untangle(nodeTags, nodeCoord, nodes, loops, triangles, tags);

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
  // M E T R I C
  //
  double lambda = 1.;
  std::vector<double> u(nodes.size(), 0.);
  std::vector<bool> bc(nodes.size(), false);
  double min = 0.;
  for (size_t j = 0; j < loops.size(); ++j) {
    std::vector<MVertex *>& loop = loops[j];
    std::vector<size_t>& indices = loopIndices[j];
    std::vector<double>& lengths = loopLengthFromFirst[j];
    size_t k = 0;
    while (k < indices.size()) {
      double total = 0., len = 0.;

      size_t i = 1;
      if (k > 0)
	i = indices[k-1] + 1;
      double length = lengths[k];
      if (k > 0)
	length -= lengths[k-1];
      auto v0 = loop[i-1]->point();
      auto v1 = loop[indices[k]]->point();
      SVector3 d(v1.x() - v0.x(),
		 v1.y() - v0.y(),
		 v1.z() - v0.z());
      double l = norm(d);
      double currentLength = 0;

      for (; i < indices[k]; ++i) {
	auto vM1 = loop[i-1];
	auto v = loop[i];
	auto vP1 = loop[i+1];

	auto pM1 = vM1->point();
	auto p = v->point();
	auto pP1 = vP1->point();
	SVector3 d0(p.x() - pM1.x(),
		    p.y() - pM1.y(),
		    p.z() - pM1.z());
	SVector3 d1(pP1.x() - p.x(),
		    pP1.y() - p.y(),
		    pP1.z() - p.z());
	double a = norm(d0);
	double b = norm(d1);
	currentLength += a;
	double t = currentLength/length;

	// // Crossprod curvature
	// d0.normalize();
	// d1.normalize();
	// auto d2 = crossprod(d0,d1);
	// double R = dot(d2, SVector3(0,0,-1));

	// Heron's formula curvature
	double c = norm(d0 + d1);
	double R = sqrt(abs((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c))) / (a*b*c);
	auto d2 = crossprod(d0,d1);
	double sign = dot(d2, SVector3(0,0,-1));
	if (sign)
	  sign /= abs(dot(d2, SVector3(0,0,-1)));
	R *= sign;

	// // Straight line crossprod
	// d.normalize();
	// d *= t;
	// SVector3 s(p.x() - v0.x(), p.y() - v0.y(), p.z() - v0.z());
	// s = s - d;
	// d.normalize();
	// // s.normalize();
	// auto c = crossprod(d,s);
	// double R = dot(c, SVector3(0.,0.,1.));
	// // R *= length/l;

	size_t index = v->getIndex();
	bc[index] = true;
	u[index] = lambda * R * ratio;
	total += R * ratio * (a+b)/2;
	len += (a+b)/2;

	// if (u[index] < min)
	//   min = u[index];
       }

      total /= len;
      i = 1;
      if (k > 0)
	i = indices[k-1] + 1;
      for (; i < indices[k]; ++i) {
	auto v = loop[i];
	size_t index = v->getIndex();
	u[index] += (1-lambda) * total;
	if (u[index] < min)
	  min = u[index];
     }
      ++k;
    }
  }


  size_t cMax= 1e3;
  for (size_t c = 0; c < cMax; ++c) {
    for(size_t i = 0; i < triangleTags.size(); ++i) {
      double mean = 0.;
      double max = 0.;
      for (int j = 0; j < 3; ++j) {
	mean += u[nodeTag2Index[triangleNodeTags[3*i+j]]];
	if (abs(max) < abs(u[nodeTag2Index[triangleNodeTags[3*i+j]]]))
	  max = u[nodeTag2Index[triangleNodeTags[3*i+j]]];
      }
      mean /= 3;
      for (int j = 0; j < 3; ++j) {
	if (!bc[nodeTag2Index[triangleNodeTags[3*i+j]]]) {
	  u[nodeTag2Index[triangleNodeTags[3*i+j]]] += .01 * (mean - u[nodeTag2Index[triangleNodeTags[3*i+j]]]);
	  // u[nodeTag2Index[triangleNodeTags[3*i+j]]] = .9 * max;

	}
      }
      
    }
  }

  // laplacianSmoothing(nodes, edge2Triangles, loops, bc, u);

  for (size_t i = 0; i < u.size(); ++i) {
    u[i] -= min;
  }

  std::vector<double> indices(u.size());
  for (size_t i = 0; i < u.size(); ++i) {
     // if (tags[i] == 35 || tags[i] == 66)
      // std::cout << "tag=" << tags[i] << " index=" << i << std::endl;
     indices[i] = i;
  }  
  std::vector<double> m(triangles.size());
  for (size_t i = 0; i < triangles.size(); ++i) {
    double mean = 0.;
    double max = 0.;
    for (int j = 0; j < 3; ++j) {
      size_t index = triangles[i]->getVertex(j)->getIndex();
      mean += u[index];
      if (u[index] > max)
	max = u[index];
    }
    mean /= 3;
    m[i] = mean;
    // m[i] = max;

  }  


  std::string currentModel;
  gmsh::model::getCurrent(currentModel);

  gmsh::view::add("Metric", 1);
  gmsh::view::addHomogeneousModelData(1, 0, currentModel, "ElementData", triangleTags, m);

  gmsh::view::add("Indices", 2);
  gmsh::view::addHomogeneousModelData(2, 0, currentModel, "NodeData", nodeTags, indices);

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
    }
    geodesic::GeodesicAlgorithmExact algorithm(&mesh,&u);
    // geodesic::GeodesicAlgorithmDijkstra algorithm(&mesh, u);
    std::vector<geodesic::SurfacePoint> path;
    algorithm.propagate(pts_start, 0, &pts_end);
    for (size_t j = 0; j < pts_end.size(); j++) {
      algorithm.trace_back(pts_end[j], path);

      if (path.size() == 0) {
	std::cerr << "No paths !" << std::endl;
	return 0;
      }
      filterPath(path, EPS); // fixme use relative error
      
      // Add path
      std::vector<int> pathTags(path.size());
      std::vector<int> pathLines(path.size()-1);
      for (size_t i = 0; i < path.size(); ++i) {
        pathTags[i] = gmsh::model::geo::addPoint(path[i].x(), path[i].y(), path[i].z());
	// std::cout << path[i].x()  << " " <<  path[i].y() << " " << path[i].z() << std::endl;
      }
      // std::cout << std::endl;
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

