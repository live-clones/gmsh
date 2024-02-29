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

double height(size_t n0, size_t n1, size_t n2, std::vector<double> & coord, SVector3 & h) {
  SVector3 d0(coord[3*n1] - coord[3*n0],
	      coord[3*n1+1] - coord[3*n0+1],
	      coord[3*n1+2] - coord[3*n0+2]);
  SVector3 d1(coord[3*n2] - coord[3*n1],
	      coord[3*n2+1] - coord[3*n1+1],
	      coord[3*n2+2] - coord[3*n1+2]);

  d0 = crossprod(d0,d1);
  double normd0 = norm(d0);
  double normd1 = norm(d1);
  double height = normd0/normd1;

  if (h != NULL) {
    d0 *= 1./normd0;
    d1 *= 1./normd1;
    d0 = crossprod(d0,d1);
    h = -height*d0;
  }

  return height;
}

void triangleSwap(std::vector<size_t> & triangleNodeTags,
		  std::map<size_t, size_t> tag2Index,
		  size_t triangle1,
		  size_t triangle2,
		  std::vector<std::size_t> & lines,
		  std::vector<double> & lineLengths,
		  std::map<std::pair<size_t,size_t>, size_t> & line2Index) {
  size_t index1 = std::numeric_limits<size_t>::max(),
         index2 = std::numeric_limits<size_t>::max();
  for (int j1 = 0; j1 < 3; ++j1) {
    int j2 = 0;
    for (; j2 < 3; ++j2) {
      // std::cout << triangleNodeTags[3*triangle1+j1] << " " << triangleNodeTags[3*triangle2+j2] << std::endl;
      if (triangleNodeTags[3*triangle1+j1] == triangleNodeTags[3*triangle2+j2])
	break;
    }
    if (j2 == 3) {
      index1 = triangleNodeTags[3*triangle1+j1];
      break;
    }
  }
  for (int j2 = 0; j2 < 3; ++j2) {
    int j1 = 0;
    for (; j1 < 3; ++j1) {
      if (triangleNodeTags[3*triangle1+j1] == triangleNodeTags[3*triangle2+j2])
	break;
    }
    if (j1 == 3) {
      index2 = triangleNodeTags[3*triangle2+j2];
      break;
    }
  }

  // std::cout << "-> " << index1 << " " << index2 << std::endl;
  if (index1 == std::numeric_limits<size_t>::max() ||
      index2 == std::numeric_limits<size_t>::max()) {
    std::cerr << "Error: cannot swap triangles" << std::endl;
    return;
  }

  size_t n1 = triangleNodeTags[3*triangle1];
  size_t n2 = triangleNodeTags[3*triangle1+1];
  std::cout << index1 << " " << index2 << " " << n1 << " " << n2 << std::endl;
  if (n1 == index1) {
    n1 = triangleNodeTags[3*triangle1+1];
    n2 = triangleNodeTags[3*triangle1+2];
  }
  std::cout << index1 << " " << index2 << " " << n1 << " " << n2 << std::endl;
  if (n2 == index1)
    n2 = triangleNodeTags[3*triangle1+2];
  std::cout << index1 << " " << index2 << " " << n1 << " " << n2 << std::endl;
  n1 = tag2Index[n1];
  n2 = tag2Index[n2];
  if (n1 > n2)
    std::swap(n1, n2);
  

  for (int j1 = 0; j1 < 3; ++j1) {
    if (triangleNodeTags[3*triangle1+j1] != index1)
      continue;

    triangleNodeTags[3*triangle1+(j1+1)%3] = index2;
    break;
  }
  for (int j2 = 0; j2 < 3; ++j2) {
    if (triangleNodeTags[3*triangle2+j2] != index2)
      continue;

    triangleNodeTags[3*triangle2+(j2+1)%3] = index1;
    break;
  }

  index1 = tag2Index[index1];
  index2 = tag2Index[index2];
  if (index1 > index2)
    std::swap(index1, index2);

  
  size_t l = line2Index[{n1,n2}];
  lines[2*l] = index1;
  lines[2*l+1] = index2;
  line2Index.erase({n1,n2});
  line2Index[{index1,index2}] = l;

 
  
  double diagLength = lineLengths[l];
  double sideLength1, sideLength2, sideLength3, sideLength4;
  if (n1 < index1) {
    sideLength1 = lineLengths[line2Index[{n1, index1}]];
    // std::cout << n1 << " " << index1 << std::endl;
  } else {
    sideLength1 = lineLengths[line2Index[{index1, n1}]];
    // std::cout << index1 << " " << n1 << std::endl;
  }
  if (n1 < index2) {
    sideLength2 = lineLengths[line2Index[{n1, index2}]];
    // std::cout << n1 << " " << index2 << std::endl;
  } else {
    sideLength2 = lineLengths[line2Index[{index2, n1}]];
    // std::cout << index2 << " " << n1 << std::endl;
  }
  if (n2 < index1) {
    sideLength3 = lineLengths[line2Index[{n2, index1}]];
    // std::cout << n2 << " " << index1 << std::endl;
  } else {
    sideLength3 = lineLengths[line2Index[{index1, n2}]];
    // std::cout << index1 << " " << n2 << std::endl;
  }
  if (n2 < index2) {
    sideLength4 = lineLengths[line2Index[{n2, index2}]];
    // std::cout << n2 << " " << index2 << std::endl;
  } else {
    sideLength4 = lineLengths[line2Index[{index2, n2}]];
    // std::cout << index2 << " " << n2 << std::endl;
  }
    
  lineLengths[l] = acos((diagLength*diagLength + sideLength1*sideLength1 - sideLength2*sideLength2)
			/ (2 * diagLength * sideLength1));
  lineLengths[l] += acos((diagLength*diagLength + sideLength3*sideLength3 - sideLength4*sideLength4)
			 / (2 * diagLength * sideLength3));
  lineLengths[l] = sqrt(sideLength2*sideLength2 + sideLength4*sideLength4
			- 2 * sideLength2 * sideLength4 * cos(lineLengths[l]));
  std::cout << diagLength << " " << sideLength1 << " " << sideLength2 << " "
	    << sideLength3 << " " << sideLength4 << " -> " << lineLengths[l] << std::endl;



}


int main(int argc, char* argv[]) {
  gmsh::initialize();

  std::string filename = "../0.geo"; // X, C, S, 0, 8, c3, uk
  double coeff = .2;
  int div = 10;
  int opt = 0;
  int smoothing = 0;
  double gravity = 0.1;
  double ratio = 1.;
  double clscale = 50;
  double clrefine = 1.;
  int refineOption = 0;
  
  int cMax = 300;
  size_t nodeTag = 100000000000;
  double p = cMax;       // cMax
  double dt = .02;       // .02
  double momentum = .95; // .95
  double limit = .4;     // .4
  double mm = 1.;        // .1
  double ks = 1.;        // 1.
  double kd = 0.;        // 0.
  double ka = 1.5;       // 1.5
  bool HIDE = false;


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
    } else if (std::string(argv[i]) == "-dt" && i + 1 < argc) {
      dt = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-m" && i + 1 < argc) {
      momentum = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-limit" && i + 1 < argc) {
      limit = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-mm" && i + 1 < argc) {
      mm = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-ks" && i + 1 < argc) {
      ks = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-kd" && i + 1 < argc) {
      kd = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-ka" && i + 1 < argc) {
      ka = std::stod(argv[++i]);
      continue;
    } else if (std::string(argv[i]) == "-hide") {
      HIDE = !HIDE;
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
  // D E F O R M A T I O N
  //
  gmsh::view::add("Force", 1);
  gmsh::view::add("Velocity", 2);
  std::string currentName;
  gmsh::model::getCurrent(currentName);

  // Lines
  std::vector<std::size_t> lines;
  std::map<std::pair<size_t,size_t>, size_t> line2Index;
  std::vector<double> lineLength;
  for (size_t i = 0; i < triangleTags.size(); ++i) {
    for (int j = 0; j < 3; ++j) {
      // size_t n0 = triangles[i]->getVertex(j)->getIndex();
      // size_t n1 = triangles[i]->getVertex((j+1)%3)->getIndex();
      size_t n0 = nodeTag2Index[triangleNodeTags[3*i+j]];
      size_t n1 = nodeTag2Index[triangleNodeTags[3*i+(j+1)%3]];
      if (n0 > n1)
	std::swap(n0,n1);
      // std::cout << n0 << " " << n1 << std::endl;

      size_t k = 0;
      for (; k < lines.size()/2; ++k) {
	if (lines[2*k] == n0 && lines[2*k+1] == n1)
	  break;
      }
      if (k == lines.size()/2) {
	line2Index[{n0,n1}] = lines.size()/2;
	lines.push_back(n0);
	lines.push_back(n1);

	double dx = nodeCoord[3*n1] - nodeCoord[3*n0]; 
	double dy = nodeCoord[3*n1+1] - nodeCoord[3*n0+1]; 
	double dz = nodeCoord[3*n1+2] - nodeCoord[3*n0+2];
	lineLength.push_back(sqrt(dx*dx + dy*dy + dz*dz));
      }
    }
  }
  
  // Boundary
  std::vector<bool> boundaryNode(nodes.size(), false);
  std::vector<double> boundaryAvgLength(nodes.size(), false);
  std::vector<bool> boundaryLine(lines.size()/2, false);
  std::vector<double> boundaryStretch(lines.size()/2, 1);
  std::vector<double> boundaryTarget(nodeCoord.size(), 0);
  for (size_t j = 0; j < loops.size(); ++j) {
    std::vector<MVertex *>& loop = loops[j];
    for (size_t k = 0; k < loopIndices[j].size(); ++k) {
      double curveLength = loopLengthFromFirst[j][k];
      size_t first = 0;
      size_t last = loopIndices[j][k];
      if (k>0) {
	curveLength -= loopLengthFromFirst[j][k-1];
	first = loopIndices[j][k-1];
      }
      
      auto pos =  loop[last]->point() - loop[first]->point();
      double straightLength = sqrt(pos.x()*pos.x() + pos.y()*pos.y() + pos.z()*pos.z());
      // std::cout << "stretch " << straightLength/curveLength << std::endl;
      double currentLength = 0.;
      for (size_t i = first; i < last; ++i) {
	size_t n0 = loop[i]->getIndex();
	size_t n1 = loop[i+1]->getIndex();
	currentLength += loop[i]->distance(loop[i+1]);
	boundaryTarget[3*n1] = (1-currentLength/curveLength) * nodeCoord[3*loop[first]->getIndex()]
                          	+ currentLength/curveLength * nodeCoord[3*loop[last]->getIndex()];
	boundaryTarget[3*n1+1] = (1-currentLength/curveLength) * nodeCoord[3*loop[first]->getIndex()+1]
                          	+ currentLength/curveLength * nodeCoord[3*loop[last]->getIndex()+1];
	boundaryTarget[3*n1+2] = (1-currentLength/curveLength) * nodeCoord[3*loop[first]->getIndex()+2]
                          	+ currentLength/curveLength * nodeCoord[3*loop[last]->getIndex()+2];
	// std::cout << (1-currentLength/curveLength) << " ";

	if (n0 > n1)
	  std::swap(n0,n1);
	boundaryNode[n0] = true;
	boundaryNode[n1] = true;
	boundaryLine[line2Index[{n0,n1}]] = true;
	
	double power = 1.;
	// std::cout << loopLengthFromFirst[j][k] << " " << length << ": "
	// 	     << straightLength/curveLength << " "
	//           << std::pow(straightLength/curveLength, power) << std::endl;
	// lineLength[line2Index[{n0,n1}]] *= std::pow(straightLength/curveLength, power);
	boundaryStretch[line2Index[{n0,n1}]] = 1. * std::pow(straightLength/curveLength, power);
      }
      // std::cout << std::endl;
    }
  }
  
  // Heights
  std::vector<double> heights(triangleNodeTags.size());
  for (size_t i = 0; i < triangleTags.size(); ++i) {
    std::vector<SPoint3> ns;
    for (int j = 0; j < 3; ++j) {
      size_t n0 = nodeTag2Index[triangleNodeTags[3*i+j]];
      size_t n1 = nodeTag2Index[triangleNodeTags[3*i+(j+1)%3]];
      size_t n2 = nodeTag2Index[triangleNodeTags[3*i+(j+2)%3]];
      SVector3 h;
      heights[3*i+j] = height(n0,n1,n2,nodeCoord, h);
    }
  }
  // Angles
  std::vector<double> angles(triangleNodeTags.size());
  for (size_t i = 0; i < triangleTags.size(); ++i) {
    std::vector<SPoint3> ns;
    for (int j = 0; j < 3; ++j) {
      size_t n0 = nodeTag2Index[triangleNodeTags[3*i+j]];
      size_t n1 = nodeTag2Index[triangleNodeTags[3*i+(j+1)%3]];
      size_t n2 = nodeTag2Index[triangleNodeTags[3*i+(j+2)%3]];
      SVector3 d0(nodeCoord[3*n1]-nodeCoord[3*n0],
		  nodeCoord[3*n1+1]-nodeCoord[3*n0+1],
		  nodeCoord[3*n1+2]-nodeCoord[3*n0+2]);
      SVector3 d1(nodeCoord[3*n2]-nodeCoord[3*n0],
		  nodeCoord[3*n2+1]-nodeCoord[3*n0+1],
		  nodeCoord[3*n2+2]-nodeCoord[3*n0+2]);
      angles[3*i+j] = acos(dot(d0,d1) / (d0.norm() * d1.norm()));
      // std::cout << angles[3*i+j] << std::endl;
    }
  }
  
  // force on boundary
  // double prop = .2;
  // for (size_t i = 0; i < lineLength.size(); ++i) {
  //   if (!boundaryLine[i])
  //     continue;
  //   lineLength[i] *= 1 - prop;
  // }
  
  // Vertex
  std::vector<bool> vertexNode(nodes.size(), false);
  // std::cout << "Vertex: ";
  for (auto t: vertexTags) {
    // std::cout << nodeTags[i] << " ";
    vertexNode[nodeTag2Index[t]] = true;
  }
  // std::cout << std::endl << std::endl;

  std::vector<double> oldCoord(nodeCoord);
  std::vector<double> prevCoord(nodeCoord);
  std::vector<double> force(nodeCoord.size(), 0);
  std::vector<double> velocity(nodeCoord.size(), 0);
  std::vector<double> shift(nodeCoord.size(), 0);
  std::vector<double> minDist(nodes.size());
  std::vector<double> tensions(nodes.size());
  std::vector<double> lineFactors(lines.size()/2);
  

  
  for (size_t i = 0; i < boundaryStretch.size(); ++i) {
    boundaryStretch[i] = std::pow(boundaryStretch[i], p/cMax);
  }
  
  for (size_t i = 0; i < velocity.size(); ++i) {
    velocity[i] = 0;
  }
  for (int c = 0; c < cMax; ++c) {
    for (size_t i = 0; i < shift.size(); ++i) {
      force[i] = 0;
      shift[i] = 0;
    }
    for (size_t i = 0; i < tensions.size(); ++i) {
      tensions[i] = 0;
    }
    for (size_t i = 0; i < boundaryAvgLength.size(); ++i) {
      boundaryAvgLength[i] = 0;
    }
    // if (p*c < cMax) {
    //   for (size_t i = 0; i < boundaryLine.size(); ++i) {
    // 	// std::cout << boundaryStretch[i] << std::endl;
    // 	lineLength[i] *= boundaryStretch[i];
    //   }
    // }


    // Boundary tension
    for (size_t i = 0; i < lines.size()/2; ++i) {
      if (!boundaryLine[i])
	continue;

      size_t n0 = lines[2*i];
      size_t n1 = lines[2*i+1];
      double dx = nodeCoord[3*n1] - nodeCoord[3*n0]; 
      double dy = nodeCoord[3*n1+1] - nodeCoord[3*n0+1]; 
      double dz = nodeCoord[3*n1+2] - nodeCoord[3*n0+2];
      // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
      
      double dl = sqrt(dx*dx + dy*dy + dz*dz);
      

      if (dl < 1e-12)
	continue;
      dx /= dl;
      dy /= dl;
      dz /= dl;

      // if (boundaryLine[i])
      // 	lineFactors[i] = 0;
      // else
      // 	lineFactors[i] = (1. - length / dl) / 2;
      // // std::cout << "f=" << lineFactors[i] << std::endl;

      boundaryAvgLength[n0] += dl/2;
      boundaryAvgLength[n1] += dl/2;
      
      double length = lineLength[i];
      lineFactors[i] = dl/length;
      length *= std::pow(boundaryStretch[i], std::min(c+1., cMax/p));
      // std::cout << std::pow(boundaryStretch[i], std::min(c+1., cMax/p)) << std::endl;
      
            
      // dl = log(dl/length) / dt;
      dl = (dl - length) * ks + (dx*(velocity[3*n1] - velocity[3*n0]) +
				 dy*(velocity[3*n1+1] - velocity[3*n0+1]) +
				 dz*(velocity[3*n1+2] - velocity[3*n0+2])) * kd;

      if (nodeTags[n0] == nodeTag || nodeTags[n1]==nodeTag)
	std::cout << "dl=" << dl << std::endl;

      // if (vertexNode[n0] || vertexNode[n1])
      // 	dl *= 2;
      
      // if (!vertexNode[n0] && (!boundaryNode[n0] || boundaryLine[i])) {
      if (!vertexNode[n0]) {
	// shift[3*n0] += dx * dl;
	// shift[3*n0+1] += dy * dl;
	// shift[3*n0+2] += dz * dl;
	force[3*n0] += dx * dl;
	force[3*n0+1] += dy * dl;
	force[3*n0+2] += dz * dl;
	
	// nodeCoord[3*n0] += dx * dl;
	// nodeCoord[3*n0+1] += dy * dl;
	// nodeCoord[3*n0+2] += dz * dl;
	
	// tensions[n0] += abs(dl);
	// std::cout << "0 ";
	if (nodeTags[n0] == nodeTag)
	  std::cout << " " << dl << " " << dx << " " << dx*dl << std::endl;
      }
      // if (!vertexNode[n1] && (!boundaryNode[n1] || boundaryLine[i])) {
      if (!vertexNode[n1]) {
	// shift[3*n1] -= dx * dl;
	// shift[3*n1+1] -= dy * dl;
	// shift[3*n1+2] -= dz * dl;	
	force[3*n1] -= dx * dl;
	force[3*n1+1] -= dy * dl;
	force[3*n1+2] -= dz * dl;	
	
	// nodeCoord[3*n1] -= dx * dl;
	// nodeCoord[3*n1+1] -= dy * dl;
	// nodeCoord[3*n1+2] -= dz * dl;

	// tensions[n1] += abs(dl);
	// std::cout << "1 ";
	if (nodeTags[n1] == nodeTag)
	  std::cout << " " << dl << " " << dx << " " << -dx*dl << std::endl;
      }
      // std::cout << std::endl;
    }
    // std::cout << std::endl;
    // for (size_t i = 0; i < nodes.size(); ++i) {
    //   for (int j = 0; j < 3; ++j) {
    // 	shift[3*i+j] *= boundaryAvgLength[i];
    //   }
    // }
    

    // Boundary to target
    for (size_t i = 0; i < lines.size()/2; ++i) {
      size_t n0 = lines[2*i];
      size_t n1 = lines[2*i+1];

      if (!boundaryLine[i])
	continue;

      double m = 0;
      m = 3*(c+1.)/(2*cMax);
      m = std::min(m,(double) cMax);
      // if (2*c > cMax)
      // 	m = 1;
      // m = m*m;
      m *= mm;
      SVector3 dir(boundaryTarget[3*n0], boundaryTarget[3*n0+1], boundaryTarget[3*n0+2]);
      dir -= SVector3(nodeCoord[3*n0], nodeCoord[3*n0+1], nodeCoord[3*n0+2]);
      // dir.normalize();
      dir *= m;
      // std::cout << dir.x() << " " << dir.y() << " " << dir.z() << std::endl;
      if (!vertexNode[n0]) {
	// shift[3*n0] += dir.x();
	// shift[3*n0+1] += dir.y();
	// shift[3*n0+2] += dir.z();
	force[3*n0] += dir.x();
	force[3*n0+1] += dir.y();
	force[3*n0+2] += dir.z();
      }
      dir = SVector3(boundaryTarget[3*n1], boundaryTarget[3*n1+1], boundaryTarget[3*n1+2]);
      dir -= SVector3(nodeCoord[3*n1], nodeCoord[3*n1+1], nodeCoord[3*n1+2]);
      dir *= m;
      if (!vertexNode[n1]) {
	// shift[3*n1] += dir.x();
	// shift[3*n1+1] += dir.y();
	// shift[3*n1+2] += dir.z();
	force[3*n1] += dir.x();
	force[3*n1+1] += dir.y();
	force[3*n1+2] += dir.z();	
      }
    }

    
    // // Bulk line factor
    // for (size_t i = 0; i < triangleTags.size(); ++i) {
    //   std::vector<size_t> ns;
    //   for (int j = 0; j < 3; ++j) {
    // 	// ns.push_back(triangles[i]->getVertex(j)->getIndex());
    // 	ns.push_back(nodeTag2Index[triangleNodeTags[3*i+j]]);
    //   }
    //   std::sort(ns.begin(), ns.end());

    //   std::vector<size_t> ls;
    //   for (int j = 0; j < 3; ++j) {
    // 	for (int jj = j+1; jj < 3; ++jj) {
    // 	  ls.push_back(line2Index[{ns[j], ns[jj]}]);
    // 	}      
    //   }
    
    //   double meanFactor = 0;
    //   for (int j = 0; j < 3; ++j)
    // 	meanFactor += lineLength[ls[j]];
    //   meanFactor /= 3;

    //   for (int j = 0; j < 3; ++j) {
    // 	for (int jj = j+1; jj < 3; ++jj) {
    // 	  size_t n0 = ns[j];
    // 	  size_t n1 = ns[jj];
    // 	  size_t l = line2Index[{ns[j], ns[jj]}];
    // 	  double length = lineLength[l];
    // 	  double dx = nodeCoord[3*n1] - nodeCoord[3*n0]; 
    // 	  double dy = nodeCoord[3*n1+1] - nodeCoord[3*n0+1]; 
    // 	  double dz = nodeCoord[3*n1+2] - nodeCoord[3*n0+2];
    // 	  double dl = sqrt(dx*dx + dy*dy + dz*dz);
    // 	  if (dl > 0) {
    // 	    dx /= dl;
    // 	    dy /= dl;
    // 	    dz /= dl;
    // 	  }
    
    // 	  // dl = log(lineFactors[l] / meanFactor) / dt2 / 10;
    // 	  // dl = (len - lineFactors[l]) / dt2;

    // 	  dl = (dl - meanFactor) * ks + (dx*(velocity[3*n1] - velocity[3*n0]) +
    // 					 dy*(velocity[3*n1+1] - velocity[3*n0+1]) +
    // 					 dz*(velocity[3*n1+2] - velocity[3*n0+2])) * kd;

    // 	  // std::cout << lineFactors[l] << std::endl;
	  
    // 	  // if (!vertexNode[n0] && (!boundaryNode[n0] || boundaryLine[l])) {
    // 	  if (!boundaryNode[n0]) {
    // 	    // shift[3*n0] += dx * dl;
    // 	    // shift[3*n0+1] += dy * dl;
    // 	    // shift[3*n0+2] += dz * dl;
    // 	    force[3*n0] += dx * dl;
    // 	    force[3*n0+1] += dy * dl;
    // 	    force[3*n0+2] += dz * dl;
    // 	    // std::cout << "0 ";
    // 	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
    // 	    // std::cout << " " << dl << " " << dx << " " << dx*dl << std::endl;
    // 	  }
    // 	  // if (!vertexNode[n1] && (!boundaryNode[n1] || boundaryLine[l])) {
    // 	  if (!boundaryNode[n1]) {
    // 	    // shift[3*n1] -= dx * dl;
    // 	    // shift[3*n1+1] -= dy * dl;
    // 	    // shift[3*n1+2] -= dz * dl;	
    // 	    force[3*n1] -= dx * dl;
    // 	    force[3*n1+1] -= dy * dl;
    // 	    force[3*n1+2] -= dz * dl;	
    // 	    // std::cout << "1 ";
    // 	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
    // 	    // std::cout << " " << dl << " " << dx << " " << -dx*dl << std::endl;
    // 	  }
    // 	  // std::cout << std::endl;
    // 	}
    //   }
    //   // std::cout << std::endl;
    // }

    
    // // Bulk height factor
    // for (size_t i = 0; i < triangleTags.size(); ++i) {
    //   std::vector<size_t> ns;
    //   std::vector<SVector3> vs;
    //   for (int j = 0; j < 3; ++j) {
    // 	// ns.push_back(triangles[i]->getVertex(j)->getIndex());
    // 	ns.push_back(nodeTag2Index[triangleNodeTags[3*i+j]]);
    // 	vs.push_back(SVector3(nodeCoord[3*ns.back()], nodeCoord[3*ns.back()+1], nodeCoord[3*ns.back()+2]));
    //   }
    //   SVector3 normal = crossprod(vs[1]-vs[0], vs[2]-vs[0]);
    //   normal.normalize();

    //   double mean = 1;
    //   double l = 0;
    //   std::vector<double> hs(3);
    //   for (int j = 0; j < 3; ++j) {
    // SVector3 h;
    // 	hs[j] = height(ns[j], ns[(j+1)%3], ns[(j+2)%3], nodeCoord, h);
    // 	mean *= hs[j] / heights[3*i+j];
    // 	l += norm(vs[(j+1)%3] - vs[j]);
    //   }
    //   mean = std::pow(mean,1./3);
    //   l /= 3;
      
      
    //   for (int j = 0; j < 3; ++j) {
    // 	double dl = (hs[j]/heights[3*i+j] - mean ) / dt2 * 10;
    // 	// std::cout << "h="<<h << " height=" << heights[3*i+j] << std::endl;

    // 	SVector3 dir = crossprod(vs[(j+2)%3]-vs[(j+1)%3], normal);
    // 	dir.normalize();

	
	
    // 	// std::cout << dl << " ";
	
    // 	if (!boundaryNode[ns[j]]) {
    // 	  shift[3*ns[j]] += dir.x() * dl * l;
    // 	  shift[3*ns[j]+1] += dir.y() * dl * l;
    // 	  shift[3*ns[j]+2] += dir.z() * dl * l;
    // 	  // std::cout << "0 ";
    // 	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
    // 	  // std::cout << " " << dl << " " << dx << " " << dx*dl << std::endl;
    // 	}

    // 	// dl /= 2;

    // 	if (!boundaryNode[ns[(j+1)%3]]) {
    // 	  shift[3*ns[(j+1)%3]] -= dir.x() * dl * l;
    // 	  shift[3*ns[(j+1)%3]+1] -= dir.y() * dl * l;
    // 	  shift[3*ns[(j+1)%3]+2] -= dir.z() * dl * l;	
    // 	  // std::cout << "1 ";
    // 	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
    // 	  // std::cout << " " << dl << " " << dx << " " << -dx*dl << std::endl;
    // 	}
    // 	if (!boundaryNode[ns[(j+2)%3]]) {
    // 	  shift[3*ns[(j+2)%3]] -= dir.x() * dl * l;
    // 	  shift[3*ns[(j+2)%3]+1] -= dir.y() * dl * l;
    // 	  shift[3*ns[(j+2)%3]+2] -= dir.z() * dl * l;	
    // 	  // std::cout << "1 ";
    // 	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
    // 	  // std::cout << " " << dl << " " << dx << " " << -dx*dl << std::endl;
    // 	}
    // 	// std::cout << std::endl;
    //   }
    // }
    // // std::cout << std::endl;



    // Bulk Angle factor
    for (size_t i = 0; i < triangleTags.size(); ++i) {
      std::vector<size_t> ns;
      std::vector<SVector3> vs;
      for (int j = 0; j < 3; ++j) {
	// ns.push_back(triangles[i]->getVertex(j)->getIndex());
	ns.push_back(nodeTag2Index[triangleNodeTags[3*i+j]]);
	vs.push_back(SVector3(nodeCoord[3*ns.back()], nodeCoord[3*ns.back()+1], nodeCoord[3*ns.back()+2]));
      }
      SVector3 normal = crossprod(vs[1]-vs[0], vs[2]-vs[0]);
      normal.normalize();

      double mean = 1;
      double l = 0;
      std::vector<double> as(3);
      for (int j = 0; j < 3; ++j) {
	SVector3 d0(nodeCoord[3*ns[(j+1)%3]]-nodeCoord[3*ns[j]],
		    nodeCoord[3*ns[(j+1)%3]+1]-nodeCoord[3*ns[j]+1],
		    nodeCoord[3*ns[(j+1)%3]+2]-nodeCoord[3*ns[j]+2]);
	SVector3 d1(nodeCoord[3*ns[(j+2)%3]]-nodeCoord[3*ns[j]],
		    nodeCoord[3*ns[(j+2)%3]+1]-nodeCoord[3*ns[j]+1],
		    nodeCoord[3*ns[(j+2)%3]+2]-nodeCoord[3*ns[j]+2]);
	as[j] = acos(dot(d0,d1) / (d0.norm() * d1.norm()));
	// std::cout << as[j] << std::endl;
	mean *= as[j] / angles[3*i+j];

	l += d0.norm();
      }
      mean = std::pow(mean,1./3);
      l /= 3;
      
      for (int j = 0; j < 3; ++j) {
	double dl = log( as[j] / angles[3*i+j] ) * ka;
	// double dl = (as[j] - angles[3*i+j]) * ka;
	// double dl;
	// if (as[j] < angles[3*i+j])
	//   dl = (1 - angles[3*i+j] / as[j]) / dt2;
	// else
	//   dl = ((2*M_PI - angles[3*i+j]) / (2*M_PI - as[j]) - 1) / dt2;
	  
	// double dl = (as[j] - angles[3*i+j]) / dt2;
	// std::cout << "dl="<<dl << std::endl;

	SVector3 dir = vs[(j+1)%3]-vs[j] + vs[(j+2)%3]-vs[j];
	dir.normalize();
	dir *= +1;
	l = 1;
	if (!boundaryNode[ns[j]]) {
	  // shift[3*ns[j]] -= dir.x() * dl * l;
	  // shift[3*ns[j]+1] -= dir.y() * dl * l;
	  // shift[3*ns[j]+2] -= dir.z() * dl * l;	
	  force[3*ns[j]] -= dir.x() * dl * l;
	  force[3*ns[j]+1] -= dir.y() * dl * l;
	  force[3*ns[j]+2] -= dir.z() * dl * l;	
	  // std::cout << "1 ";
	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
	  // std::cout << " " << dl << " " << dx << " " << -dx*dl << std::endl;
	}

	dir = crossprod(normal, vs[(j+1)%3]-vs[j]);
	dir.normalize();	
	if (!boundaryNode[ns[(j+1)%3]]) {
	  // shift[3*ns[(j+1)%3]] += dir.x() * dl * l;
	  // shift[3*ns[(j+1)%3]+1] += dir.y() * dl * l;
	  // shift[3*ns[(j+1)%3]+2] += dir.z() * dl * l;	
	  force[3*ns[(j+1)%3]] += dir.x() * dl * l;
	  force[3*ns[(j+1)%3]+1] += dir.y() * dl * l;
	  force[3*ns[(j+1)%3]+2] += dir.z() * dl * l;	
	  // std::cout << "1 ";
	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
	  // std::cout << " " << dl << " " << dx << " " << -dx*dl << std::endl;
	}

	dir = crossprod(normal, vs[(j+2)%3]-vs[j]);
	dir.normalize();	
	if (!boundaryNode[ns[(j+2)%3]]) {
	  shift[3*ns[(j+2)%3]] -= dir.x() * dl * l;
	  shift[3*ns[(j+2)%3]+1] -= dir.y() * dl * l;
	  shift[3*ns[(j+2)%3]+2] -= dir.z() * dl * l;	
	  // std::cout << "1 ";
	  // std::cout << "dx=" << dx << " dy=" << dy << " dz=" << dz << std::endl;
	  // std::cout << " " << dl << " " << dx << " " << -dx*dl << std::endl;
	}
	// std::cout << std::endl;
      }
    }
    // std::cout << std::endl;

    
    
    

    
    
    // // MinDist
    // for (size_t i = 0; i < minDist.size(); ++i) {
    //   minDist[i] = std::numeric_limits<double>::max();
    // }
    // for (size_t i = 0; i < triangleTags.size(); ++i) {
    //   double min = std::numeric_limits<float>::max();
    //   for (int j = 0; j < 3; ++j) {
    // 	// size_t n0 = triangles[i]->getVertex(j)->getIndex();
    // 	// size_t n1 = triangles[i]->getVertex((j+1)%3)->getIndex();
    // 	// size_t n2 = triangles[i]->getVertex((j+2)%3)->getIndex();
    // 	size_t n0 = nodeTag2Index[triangleNodeTags[3*i]];
    // 	size_t n1 = nodeTag2Index[triangleNodeTags[3*i+1]];
    // 	size_t n2 = nodeTag2Index[triangleNodeTags[3*i+2]];

    // SVector3 h;
    // 	double dist = height(n0,n1,n2,nodeCoord, h);

    // 	if (nodeTags[n0] == nodeTag)
    // 	  std::cout << "dist=" << dist << std::endl;

    // 	// if (dist < minDist[n0])
    // 	//   minDist[n0] = dist;
      
    // 	if (dist < min)
    // 	  min = dist;
    //   }
    //   // std::cout << "min=" << min << std::endl;
    //   for (int j = 0; j < 3; ++j) {
    // 	// size_t n = triangles[i]->getVertex(j)->getIndex();
    // 	size_t n = nodeTag2Index[triangleNodeTags[3*i+j]];
    // 	if (min < minDist[n])
    // 	  minDist[n] = min;
    //   }
    // }

    // Momentum
    // for (size_t i = 0; i < nodeCoord.size()/3; ++i) {
    //   for (int j = 0; j < 3; ++j) {
    // 	// std::cout << tensions[i] << std::endl;
    // 	// if (tensions[i] > 1e-12)
    // 	//   shift[3*i+j] /= tensions[i]*tensions[i];
    // 	// if ( (nodeCoord[3*i+0] - prevCoord[3*i+0])*shift[3*i+0]
    // 	//     +(nodeCoord[3*i+1] - prevCoord[3*i+1])*shift[3*i+1]
    // 	//     +(nodeCoord[3*i+2] - prevCoord[3*i+2])*shift[3*i+2] > 0)
    // 	shift[3*i+j] += (nodeCoord[3*i+j] - prevCoord[3*i+j]) * momentum;
    // 	prevCoord[3*i+j] = nodeCoord[3*i+j];
    //   }
    // }

    // Save View
    int gap = 1;
    if (c % gap == 0) {
      gmsh::view::addHomogeneousModelData(1, c/gap, currentName, "NodeData", nodeTags, force, 0, -1);
      gmsh::view::addHomogeneousModelData(2, c/gap, currentName, "NodeData", nodeTags, velocity, 0, -1);
    }
    
    if (c == cMax-1)
      continue;


    // // Limit
    // for (size_t ii = 0; ii < nodeTags.size(); ++ii) {
    // for (size_t i = 0; i < triangleTags.size(); ++i) {      
    //   for (int j = 0; j < 3; ++j) {
    // 	if (nodeTag2Index[triangleNodeTags[3*i+j]] != ii)
    // 	  continue;

    // 	std::vector<size_t> ns;
    // 	std::vector<SVector3> vs; 
    // 	for (int jj = 0; jj < 3; ++jj) {
    // 	  ns.push_back(nodeTag2Index[triangleNodeTags[3*i+(j+jj)%3]]);
    // 	  vs.push_back(SVector3(nodeCoord[3*ns.back()], nodeCoord[3*ns.back()+1], nodeCoord[3*ns.back()+2]));
    // 	}
    // 	SVector3 s(shift[3*ns[0]], shift[3*ns[0]+1], shift[3*ns[0]+2]);
    // 	SVector3 v1 = vs[1]-vs[0];
    // 	SVector3 v2 = vs[2]-vs[0];
	
    // 	double sDotv1 = dot(s, v1);
    // 	double sDotv2 = dot(s, v2);
    // 	double v1Dotv2 = dot(v1, v2);
    // 	double normv1 = v1.norm();
    // 	double normv2 = v2.norm();
    // 	double norms = s.norm();

    // 	// double c1 = (normv2*normv2*sDotv1 - v1Dotv2*sDotv2)
    // 	//           / (normv1*normv1*normv2*normv2 - v1Dotv2*v1Dotv2);	
    // 	// double c2 = (normv1*normv1*sDotv2 - v1Dotv2*sDotv1)
    // 	//           / (normv1*normv1*normv2*normv2 - v1Dotv2*v1Dotv2);

    // 	// if (nodeTags[ns[0]] == nodeTag)
    // 	//   std::cout << i << " " << c1 << " " << c2 << std::endl;
    // 	// if (c1 < 0 || c2 < 0)
    // 	//   continue;
    // 	// if (c1 < limit && c2 < limit)
    // 	//   continue;

    // 	// std::cout << "limit" << std::endl;
    // 	// // std::cout << i << "-> " << c1 << " " << c2 << std::endl;
    // 	// if (c1 > limit)
    // 	//   c1 = limit;
    // 	// if (c2 > limit)
    // 	//   c2 = limit;
    // 	// s = c1*(vs[1]-vs[0]) + c2*(vs[2]-vs[0]);
    // 	// shift[3*ns[0]] = s.x();
    // 	// shift[3*ns[0]+1] = s.y();
    // 	// shift[3*ns[0]+2] = s.z();
    // 	// // nodeCoord[3*ns[0]] += s.x();
    // 	// // nodeCoord[3*ns[0]+1] += s.y();
    // 	// // nodeCoord[3*ns[0]+2] += s.z();
    // 	// // shift[3*ns[0]] = 0.;
    // 	// // shift[3*ns[0]+1] = 0.;
    // 	// // shift[3*ns[0]+2] = 0.;



    // 	// if (norms < 1e-6)
    // 	//   continue;
	
    // 	// double c1 = sDotv1 / normv1 / normv1;
    // 	// double c2 = sDotv2 / normv2 / normv2;
    // 	// // std::cout << c1 << " " << c2 << std::endl;
    // 	// if (c1 < limit && c2 < limit)
    // 	// // if (c1 < limit)
    // 	//   continue;

    // 	// std::cout << "limit " << nodeTags[ns[0]] << std::endl;
    // 	// if (c1 > limit) {
    // 	//   c1 -= limit;
    // 	//   v1 *= c1;
    // 	//   shift[3*ns[0]] -= v1.x();
    // 	//   shift[3*ns[0]+1] -= v1.y();
    // 	//   shift[3*ns[0]+2] -= v1.z();	  
    // 	// }
    // 	// if (c2 > limit) {
    // 	//   c2 -= limit;
    // 	//   std::cout << c2 << std::endl;
    // 	//   v2 *= c2;
    // 	//   shift[3*ns[0]] -= v2.x();
    // 	//   shift[3*ns[0]+1] -= v2.y();
    // 	//   shift[3*ns[0]+2] -= v2.z();	  
    // 	// }



    // 	SVector3 h;
    // 	double hei = height(ns[0], ns[1], ns[2], nodeCoord, h);
    // 	double c = dot(s,h)/(hei*hei);
    // 	if (c < limit)
    // 	  continue;
	
    // 	std::cout << "limit" << nodeTags[ns[0]] << std::endl;

    // 	if (nodeTags[ns[0]] == nodeTag) {
    // 	  std::cout << "limit=" << limit << " c=" << c << " hei=" << hei << std::endl;
    // 	  std::cout << "hx=" << h.x() << " hy=" << h.y() << " hz=" << h.z() << std::endl;
    // 	  std::cout << "sx=" << s.x() << " sy=" << s.y() << " sz=" << s.z() << std::endl;
    // 	}
    // 	c -= limit;
    // 	shift[3*ns[0]] -= c*h.x();
    // 	shift[3*ns[0]+1] -= c*h.y();
    // 	shift[3*ns[0]+2] -= c*h.z();
    // 	if (nodeTags[ns[0]] == nodeTag) {
    // 	  std::cout << "limit=" << limit << " c=" << c << " hei=" << hei << std::endl;
    // 	  std::cout << "p hx=" << -c*h.x() << " hy=" << -c*h.y() << " hz=" << -c*h.z() << std::endl;
    // 	  s = s - c*h;
    // 	  std::cout << "p sx=" << s.x() << " sy=" << s.y() << " sz=" << s.z() << std::endl;
    // 	  std::cout << dot(s,h)/(hei*hei) << std::endl;
    // 	}


	
	
    //   }
    // }
    // nodeCoord[3*ii] += shift[3*ii];
    // nodeCoord[3*ii+1] += shift[3*ii+1];
    // nodeCoord[3*ii+2] += shift[3*ii+2];
    // }

    // Apply shift
    // for (size_t i = 0; i < nodeCoord.size()/3; ++i) {
    //   double l = sqrt(shift[3*i]*shift[3*i]+
    // 		      shift[3*i+1]*shift[3*i+1] +
    // 		      shift[3*i+2]*shift[3*i+2]);
    //   if (l < 1e-12)
    // 	continue;

    //   // // std::cout << "l=" << l;

    //   // double s = l;
    //   // // if (boundaryNode[i]) {
    //   // // 	s *= std::pow(tensions[i], 10);
    //   // // }
    //   // // std::cout << " s=" << s;
      
    //   // if (s > .4*minDist[i])
    //   // 	std::cout << "limit" << std::endl;
      
    //   // if (s > 1e-12)
    //   // 	s = std::min(s, .4*minDist[i]);
    //   // if (nodeTags[i] == nodeTag)
    //   // 	std::cout << "s=" << s << std::endl;

    //   // l = s/l;
    //   // if (nodeTags[i] == nodeTag)
    //   // 	std::cout << "s/l=" << l << std::endl;

    //   l = 1;
      
    //   for (int j = 0; j < 3; ++j) {
    // 	nodeCoord[3*i+j] += shift[3*i+j] * l;
    // 	// std::cout << " s=" << shift[3*i+j] * l;
    // 	// std::cout << shift[3*i+j] << " " << l << " " << shift[3*i+j]*l << std::endl;
    //   }
    //   // std::cout << std::endl;
    //   if (nodeTags[i] == nodeTag)
    // 	std::cout << "shiftY=" << shift[3*i+1] << " shift*l=" << shift[3*i+1]*l << std::endl;


    // }
    // // std::cout << std::endl;

    for(size_t i = 0; i < nodeCoord.size()/3; ++i) {
      for (int j = 0; j < 3; ++j) {
	velocity[3*i+j] = momentum * velocity[3*i+j] + dt * force[3*i+j];
      }

      double l = sqrt(velocity[3*i]*velocity[3*i]+
		      velocity[3*i+1]*velocity[3*i+1] +
		      velocity[3*i+2]*velocity[3*i+2]);
      l *= dt;
      if (l < 1e-6)
	continue;

      double s = l;
      // if (s > limit*minDist[i]) {
      // 	std::cout << "limit" << std::endl;
      // 	s = limit*minDist[i];
      // }
      l = s/l;
      // std::cout << l << " "<< s << " " << minDist[i] << std::endl;

      for (int j = 0; j < 3; ++j) {
	nodeCoord[3*i+j] += dt * velocity[3*i+j] * l;
      }
    }

    // for(size_t i = 0; i < nodeCoord.size()/3; ++i) {
    //   for (int j = 0; j < 3; ++j) {
    // 	velocity[3*i+j] = momentum * velocity[3*i+j] + dt * force[3*i+j];
    // 	nodeCoord[3*i+j] += dt * velocity[3*i+j];
    //   }
    // }


    // // Check Swapping
    // if ((c+1) % 1 == 0) {
    //   std::cout << "Check Swapping" << std::endl;
    //   for (size_t i = 0; i < triangleTags.size(); ++i) {
    // 	for (int j = 0; j < 3; ++j) {
    // 	  size_t n0 = nodeTag2Index[triangleNodeTags[3*i+j]];
    // 	  size_t n1 = nodeTag2Index[triangleNodeTags[3*i+(j+1)%3]];
    // 	  size_t n2 = nodeTag2Index[triangleNodeTags[3*i+(j+2)%3]];
    // 	  double a = sqrt((nodeCoord[3*n1] - nodeCoord[3*n0])*(nodeCoord[3*n1] - nodeCoord[3*n0]) +
    // 			  (nodeCoord[3*n1+1] - nodeCoord[3*n0+1])*(nodeCoord[3*n1+1] - nodeCoord[3*n0+1]) +
    // 			  (nodeCoord[3*n1+2] - nodeCoord[3*n0+2])*(nodeCoord[3*n1+2] - nodeCoord[3*n0+2]));
    // 	  double b = sqrt((nodeCoord[3*n2] - nodeCoord[3*n0])*(nodeCoord[3*n2] - nodeCoord[3*n0]) +
    // 			  (nodeCoord[3*n2+1] - nodeCoord[3*n0+1])*(nodeCoord[3*n2+1] - nodeCoord[3*n0+1]) +
    // 			  (nodeCoord[3*n2+2] - nodeCoord[3*n0+2])*(nodeCoord[3*n2+2] - nodeCoord[3*n0+2]));
    // 	  double c = sqrt((nodeCoord[3*n2] - nodeCoord[3*n1])*(nodeCoord[3*n2] - nodeCoord[3*n1]) +
    // 			  (nodeCoord[3*n2+1] - nodeCoord[3*n1+1])*(nodeCoord[3*n2+1] - nodeCoord[3*n1+1]) +
    // 			  (nodeCoord[3*n2+2] - nodeCoord[3*n1+2])*(nodeCoord[3*n2+2] - nodeCoord[3*n1+2]));
    // 	  double angle = acos((a*a + b*b - c*c) / (2 * a * b));
    // 	  if (angle < 2*M_PI/3)
    // 	    continue;
      
    // 	  size_t ii = 0;
    // 	  for (; ii < triangleTags.size(); ++ii) {
    // 	    if (ii != i &&
    // 		(triangleNodeTags[3*ii] == nodeTags[n1] ||
    // 		 triangleNodeTags[3*ii+1] == nodeTags[n1] ||
    // 		 triangleNodeTags[3*ii+2] == nodeTags[n1]) &&
    // 		(triangleNodeTags[3*ii] == nodeTags[n2] ||
    // 		 triangleNodeTags[3*ii+1] == nodeTags[n2] ||
    // 		 triangleNodeTags[3*ii+2] == nodeTags[n2]))
    // 	      break;
    // 	  }
    // 	  if (ii == triangleTags.size()) {
    // 	    std::cerr << "Triangle for swap not found" << std::endl;
    // 	    continue;
    // 	  }

    // 	  triangleSwap(triangleNodeTags, nodeTag2Index, i, ii, lines, lineLength, line2Index);
    // 	}
    //   }  

    // }



  }


  
  if (!HIDE) {
    for (size_t i = 0; i < nodeCoord.size()/3; ++i) {
      gmsh::model::mesh::setNode(nodeTags[i], {nodeCoord[3*i], nodeCoord[3*i+1], nodeCoord[3*i+2]}, {});
    }
  }
  
  // gmsh::model::mesh::clear();
  // gmsh::model::mesh::addNodes(2, 1, nodeTags, nodeCoord);
  // gmsh::model::mesh::addElements(2, 1, {MSH_TRI_3}, {triangleTags}, {triangleNodeTags});
  
  
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
    geodesic::GeodesicAlgorithmExact algorithm(&mesh);
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

      // Move path
      if (HIDE) {
	for (size_t i = 0; i < path.size(); ++i) {
	  // std::cout << path[i].type() << std::endl;
	  if (path[i].type() == geodesic::VERTEX) {
	    auto vertex = path[i].base_element();
	    size_t n = vertex->id();
	    path[i].set(oldCoord[3*n], oldCoord[3*n+1], oldCoord[3*n+2]);
	  }
	  else if (path[i].type() == geodesic::EDGE) {
	    auto vertices = path[i].base_element()->adjacent_vertices();
	    size_t n0 = vertices[0]->id();
	    size_t n1 = vertices[1]->id();
	    if (n0 > n1)
	      std::swap(n0,n1);

	    double dx = path[i].x() - nodeCoord[3*n0];
	    double dy = path[i].y() - nodeCoord[3*n0+1];
	    double dz = path[i].z() - nodeCoord[3*n0+2];
	    double Dx = nodeCoord[3*n1] - nodeCoord[3*n0];
	    double Dy = nodeCoord[3*n1+1] - nodeCoord[3*n0+1];
	    double Dz = nodeCoord[3*n1+2] - nodeCoord[3*n0+2];
	    double t = (dx*Dx + dy*Dy + dz*Dz) / (Dx*Dx + Dy*Dy + Dz*Dz);
	    // std::cout << nodeTags[n0] << " " << nodeTags[n1] << ": " << t << std::endl;
 
	    double newX = (1-t) * oldCoord[3*n0] + t * oldCoord[3*n1];
	    double newY = (1-t) * oldCoord[3*n0+1] + t * oldCoord[3*n1+1];
	    double newZ = (1-t) * oldCoord[3*n0+2] + t * oldCoord[3*n1+2];
	  
	    path[i].set(newX, newY ,newZ);
	  }
	}
	// std::cout << std::endl;
      }
      
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

