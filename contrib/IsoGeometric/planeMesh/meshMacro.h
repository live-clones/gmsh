#include <gmsh/meshPolyMesh.h>
#include <gmsh/meshGFaceGeodesic.h>

#include <gmsh/winslowUntangler.h>
#define WINSLOW 0

void fillEdgeTag2TriangleMap(std::map<std::pair<size_t,size_t>, std::vector<size_t>> & edgeTag2Triangle,
			     std::vector<size_t> & elementNodeTags,
			     size_t i)
{
	for (int j = 0; j < 3; ++j) {
    size_t t0 = elementNodeTags[3*i+j];
    size_t t1 = elementNodeTags[3*i+(j+1)%3];
    if (t0 > t1)
      std::swap(t0,t1);
    edgeTag2Triangle[{t0,t1}].push_back(i);	
  }

}

void meshModif(std::map<std::pair<size_t,size_t>, std::vector<size_t>> entity2Tags)
{
  // Lines
  std::vector<std::size_t> lineElementTags;
  std::vector<std::size_t> lineElementNodeTags;
  gmsh::model::mesh::getElementsByType(MSH_LIN_2, lineElementTags, lineElementNodeTags);

  // Triangles
  std::vector<std::size_t> triangleElementTags;
  std::vector<std::size_t> triangleElementNodeTags;
  gmsh::model::mesh::getElementsByType(MSH_TRI_3, triangleElementTags, triangleElementNodeTags);

  std::vector<std::size_t> nodeTags;
  std::map<size_t, size_t> tag2Index;
  std::vector<double> coord;
  std::vector<double> parametricCoord;
  gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, -1, true, false);
  for (size_t i = 0; i < nodeTags.size(); ++i)
    tag2Index[nodeTags[i]] = i;

  std::cout << nodeTags.size() << std::endl;


  //
  // Split triangles linking two boundaries
  //
  std::size_t newNodeTag;
  gmsh::model::mesh::getMaxNodeTag(newNodeTag);
  std::size_t newElementTag;
  gmsh::model::mesh::getMaxElementTag(newElementTag);

  // Nodes
  std::vector<std::size_t> nodeTags0D;
  std::vector<double> coord0D;
  std::map<size_t, size_t> tag0D2Index;
  gmsh::model::mesh::getNodes(nodeTags0D, coord0D, parametricCoord, 0);
  // remove points not on the surface
  for (size_t i = 0; i < nodeTags0D.size(); ++i) {
    if (std::find(nodeTags.begin(), nodeTags.end(), nodeTags0D[i]) == nodeTags.end()) {
      nodeTags0D.erase(nodeTags0D.begin() + i);
      coord0D.erase(coord0D.begin() + 3*i, coord0D.begin() + 3*(i+1));
      --i;
    }
  }
  for (size_t i = 0; i < nodeTags0D.size(); ++i)
    tag0D2Index[nodeTags0D[i]] = i;

  std::vector<std::size_t> nodeTags1D;
  std::vector<double> coord1D;
  std::map<size_t, size_t> tag1D2Index;
  gmsh::model::mesh::getNodes(nodeTags1D, coord1D, parametricCoord, 1);
  for (size_t i = 0; i < nodeTags1D.size(); ++i)
    tag1D2Index[nodeTags1D[i]] = i;

  std::vector<std::size_t> nodeTags2D;
  std::vector<double> coord2D;
  std::map<size_t, size_t> tag2D2Index;
  //  gmsh::model::mesh::getNodes(nodeTags2D, coord2D, parametricCoord, 2);
  for (size_t i = 0; i < triangleElementNodeTags.size(); ++i) {
    size_t t = triangleElementNodeTags[i];
    if (tag2D2Index.find(t) != tag2D2Index.end()) continue;
    if (tag1D2Index.find(t) != tag1D2Index.end()) continue;
    if (tag0D2Index.find(t) != tag0D2Index.end()) continue;
    tag2D2Index[t] = tag2D2Index.size();
  }
  nodeTags2D.resize(tag2D2Index.size());
  coord2D.resize(3*tag2D2Index.size());
  for (auto it = tag2D2Index.begin(); it != tag2D2Index.end(); ++it) {
    nodeTags2D[it->second] = it->first;
    for (int j = 0; j < 3; ++j)
      coord2D[3*it->second + j] = coord[3*tag2Index[it->first]+j];
  }


  std::cout << nodeTags0D.size() << std::endl;
  std::cout << nodeTags1D.size() << std::endl;
  std::cout << nodeTags2D.size() << std::endl;

  std::map<size_t, bool> nodeIsBoundary;
  for (size_t i = 0; i < nodeTags0D.size(); ++i)
    nodeIsBoundary[nodeTags0D[i]] = true;
  for (size_t i = 0; i < nodeTags1D.size(); ++i)
    nodeIsBoundary[nodeTags1D[i]] = true;
  for (size_t i = 0; i < nodeTags2D.size(); ++i)
    nodeIsBoundary[nodeTags2D[i]] = false;



  std::map<std::pair<size_t, size_t>, std::vector<size_t>> edgeTag2Triangle;
  for (size_t i = 0; i < triangleElementTags.size(); ++i) {
    fillEdgeTag2TriangleMap(edgeTag2Triangle, triangleElementNodeTags, i);
  }

  for (size_t i = 0; i < triangleElementTags.size(); ++i) {
    for (int j = 0; j < 3; ++j) {
      size_t t0 = triangleElementNodeTags[3*i+j];
      size_t t1 = triangleElementNodeTags[3*i+(j+1)%3];
      if (!nodeIsBoundary[t0] || !nodeIsBoundary[t1])
        continue;

      std::pair<size_t,size_t> edge = {t0,t1};
      if (t0 > t1)
        edge = {t1,t0};
      if (edgeTag2Triangle[edge].size() == 1)
        continue;

      size_t iOpp = edgeTag2Triangle[edge][0];
      if (i == iOpp)
        iOpp = edgeTag2Triangle[edge][1];
      size_t jOpp = 0;
      for (int jj = 0; jj < 3; ++jj) {
        if (t0 == triangleElementNodeTags[3*iOpp+(jj+1)%3] &&
            t1 == triangleElementNodeTags[3*iOpp+jj]) {
          jOpp = jj;
          break;
        }
      }

      // New node
      nodeTags.push_back(++newNodeTag);
      nodeTags2D.push_back(newNodeTag);
      for (int jj = 0; jj < 3; ++jj) {
        double tmp = (coord[3*tag2Index[t1]+jj] + coord[3*tag2Index[t0]+jj]) / 2;
        coord.push_back(tmp);
        coord2D.push_back(tmp);
      }
      nodeIsBoundary[newNodeTag] = false;
      tag2Index[newNodeTag] = nodeTags.size()-1;

      // New triangles
      // erase edge map
      for (auto it = edgeTag2Triangle.begin(); it != edgeTag2Triangle.end(); ++it) {
        auto & vs = it->second;
        for (size_t k = 0; k < vs.size(); ++k) {
          if (vs[k] == i || vs[k] == iOpp) {
            vs.erase(vs.begin() + k);
          }
        }
      }

      // original
      triangleElementTags.push_back(++newElementTag);
      triangleElementNodeTags.push_back(triangleElementNodeTags[3*i+j]);
      triangleElementNodeTags.push_back(newNodeTag);
      triangleElementNodeTags.push_back(triangleElementNodeTags[3*i+(j+2)%3]);
      fillEdgeTag2TriangleMap(edgeTag2Triangle, triangleElementNodeTags, triangleElementTags.size()-1);
      
      triangleElementNodeTags[3*i+j] = newNodeTag;
      fillEdgeTag2TriangleMap(edgeTag2Triangle, triangleElementNodeTags, i);

      // opposite
      triangleElementTags.push_back(++newElementTag);
      triangleElementNodeTags.push_back(triangleElementNodeTags[3*iOpp+jOpp]);
      triangleElementNodeTags.push_back(newNodeTag);
      triangleElementNodeTags.push_back(triangleElementNodeTags[3*iOpp+(jOpp+2)%3]);
      fillEdgeTag2TriangleMap(edgeTag2Triangle, triangleElementNodeTags, triangleElementTags.size()-1);
      
      triangleElementNodeTags[3*iOpp+jOpp] = newNodeTag;
      fillEdgeTag2TriangleMap(edgeTag2Triangle, triangleElementNodeTags, iOpp);
    
      --j;
    }
  }


  gmsh::model::mesh::clear();

  // gmsh::model::add("Unstructured surface");
  gmsh::model::addDiscreteEntity(0,0);
  gmsh::model::addDiscreteEntity(1,0,{0});
  gmsh::model::addDiscreteEntity(2,0,{0});

  gmsh::model::mesh::addNodes(0, 0, nodeTags0D, coord0D);
  gmsh::model::mesh::addNodes(1, 0, nodeTags1D, coord1D);
  gmsh::model::mesh::addNodes(2, 0, nodeTags2D, coord2D);
  gmsh::model::mesh::rebuildNodeCache();

  gmsh::model::mesh::addElements(1, 0, {MSH_LIN_2}, {lineElementTags}, {lineElementNodeTags});
  gmsh::model::mesh::addElements(2, 0, {MSH_TRI_3}, {triangleElementTags}, {triangleElementNodeTags});
  gmsh::model::mesh::rebuildElementCache();

  
  //
  // Save Entities
  //
  gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, -1, true, false);
  for (size_t i = 0; i < nodeTags.size(); ++i)
    tag2Index[nodeTags[i]] = i;
  
  std::ofstream outputEntities("entities.csv");
  outputEntities << "entityDim,entityTag,vertexTag1,vertexTag2,vertexTag3\n";
  for (auto entity2Tag: entity2Tags) {
    auto dim = entity2Tag.first.first;
    auto tag = entity2Tag.first.second;
    auto vTags = entity2Tag.second;
    if (dim == 0) {
      for (auto vTag: vTags) {
        if (tag2Index.find(vTag) == tag2Index.end())
          continue;
        outputEntities << dim << "," << tag << "," << tag2Index[vTag] << "\n";
      }
    }
    else if (dim == 1) {
      for (size_t i = 0; i < vTags.size()/2; ++i) {
        outputEntities << dim << "," << tag << "," << tag2Index[vTags[2*i]]
                                            << "," << tag2Index[vTags[2*i+1]] << "\n";
      }
    }
    else if (dim == 2) {
      for (size_t i = 0; i < vTags.size()/3; ++i) {
        outputEntities << dim << "," << tag << "," << tag2Index[vTags[3*i]]
                                            << "," << tag2Index[vTags[3*i+1]]
                                            << "," << tag2Index[vTags[3*i+2]] << "\n";
      }
    }
  }
  outputEntities.close();

}



void macroMsh(const std::string & filename,
              const double clmax,
              std::vector<size_t> & vertexTags,
              std::vector<std::size_t> & macroElementNodeTags,
              const int opt = 0)
{
  gmsh::open(filename);

  std::vector<size_t> nodeTags;
  std::vector<double> coord;
  std::vector<double> parametricCoord;
  gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, -1, true, false);
  std::vector<size_t> elementTags;
  std::vector<size_t> elementNodeTags;
  gmsh::model::mesh::getElementsByType(MSH_TRI_3, elementTags, elementNodeTags);

  std::map<size_t, size_t> tag2Index;
  std::vector<size_t> tris(elementNodeTags.size());
  for (size_t i = 0; i < tris.size(); ++i) {
    if (tag2Index.find(elementNodeTags[i]) == tag2Index.end())
      tag2Index[elementNodeTags[i]] = tag2Index.size();
    tris[i] = tag2Index[elementNodeTags[i]];
  }
  std::vector<double> tags(tag2Index.size());
  std::vector<double> pos(3*tag2Index.size());
  for (size_t i = 0; i < nodeTags.size(); ++i) {
    if (tag2Index.find(nodeTags[i]) == tag2Index.end())
      continue;
    tags[tag2Index[nodeTags[i]]] = nodeTags[i];
    pos[3*tag2Index[nodeTags[i]]] = coord[3*i];
    pos[3*tag2Index[nodeTags[i]]+1] = coord[3*i+1];
    pos[3*tag2Index[nodeTags[i]]+2] = coord[3*i+2];
  }

  PolyMesh *pm = createPolyMesh(pos, tris);
  std::map<PolyMesh::Vertex *, double> noth;
  for (size_t i = 0; i < pm->vertices.size(); ++i)
    noth[pm->vertices[i]] = tags[pm->vertices[i]->data/3];
  print__("pm.pos", pm, noth);

  // Decimate
  PolyMesh decimated(*pm);
  //    decimated.computeNormalsAndCentersOfGravity(cogs,nrms);
  while(decimated.decimate(clmax) > 0) {};
  std::map<PolyMesh::Vertex *, double> nothing;
  for (size_t i = 0; i < decimated.vertices.size(); ++i)
    nothing[decimated.vertices[i]] = tags[decimated.vertices[i]->data/3];
  print__("decimated.pos", &decimated, nothing);
  for(auto v : decimated.vertices)
    vertexTags.push_back(tags[v->data/3]);
  for(auto f : decimated.faces) {
    macroElementNodeTags.push_back(tags[f->he->v->data/3]);
    macroElementNodeTags.push_back(tags[f->he->next->v->data/3]);
    macroElementNodeTags.push_back(tags[f->he->next->next->v->data/3]);
  }

  //
  // Classify on Entities
  //
  gmsh::vectorpair dimTags;
  gmsh::model::getEntities(dimTags);

  std::map<std::pair<size_t,size_t>, std::vector<size_t>> entity2Tags;
  for (auto dimTag: dimTags) {
    if (dimTag.first == 0) {
      std::vector<std::size_t> nodeTags;
      std::vector<double> coord;
      std::vector<double> parametricCoord;
      gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, dimTag.first, dimTag.second, false, false);
      for (auto n: nodeTags) {
        entity2Tags[dimTag].push_back(n);
      }
    }
    else if (dimTag.first == 1) {
      std::vector<std::size_t> eTags;
      std::vector<std::size_t> nTags;
      gmsh::model::mesh::getElementsByType(MSH_LIN_2, eTags, nTags, dimTag.second);
      for (auto n: nTags)
        entity2Tags[dimTag].push_back(n);
    }
    else if (dimTag.first == 2) {
      std::vector<std::size_t> eTags;
      std::vector<std::size_t> nTags;
      gmsh::model::mesh::getElementsByType(MSH_TRI_3, eTags, nTags, dimTag.second);
      for (auto n: nTags)
        entity2Tags[dimTag].push_back(n);
    }
  }

  meshModif(entity2Tags);
}


void macroGeo(const std::string & filename,
              const double clscale,
              const double clrefine,
              std::vector<size_t> & vertexTags,
              std::vector<std::size_t> & macroElementNodeTags,
              const int opt = 0)
{
  //
  // Construct Macro Mesh
  //
  gmsh::open(filename);
  gmsh::option::setNumber("Mesh.MeshSizeFactor", clscale);
  gmsh::option::setNumber("Mesh.Algorithm", 3);
  gmsh::model::mesh::setOrder(1);
  gmsh::model::mesh::generate(2);

  gmsh::fltk::run();

  std::vector<double> vertexCoord;
  std::vector<double> vertexParametricCoord;
  gmsh::model::mesh::getNodes(vertexTags, vertexCoord, vertexParametricCoord, 2, -1, true);

  std::vector<std::size_t> elementTags;
  gmsh::model::mesh::getElementsByType(MSH_TRI_3, elementTags, macroElementNodeTags);

  std::cout << elementTags.size() << " macro triangles with "
            << vertexTags.size() << " vertices" << std::endl;


  //
  // Classify on Entities
  //
  gmsh::vectorpair dimTags;
  gmsh::model::getEntities(dimTags);

  std::map<std::pair<size_t,size_t>, std::vector<size_t>> entity2Tags;
  for (auto dimTag: dimTags) {
    if (dimTag.first == 0) {
      std::vector<std::size_t> nodeTags;
      std::vector<double> coord;
      std::vector<double> parametricCoord;
      gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, dimTag.first, dimTag.second, false, false);
      for (auto n: nodeTags) {
        entity2Tags[dimTag].push_back(n);
      }
    }
    else if (dimTag.first == 1) {
      std::vector<std::size_t> eTags;
      std::vector<std::size_t> nTags;
      gmsh::model::mesh::getElementsByType(MSH_LIN_2, eTags, nTags, dimTag.second);
      for (auto n: nTags)
        entity2Tags[dimTag].push_back(n);
    }
    else if (dimTag.first == 2) {
      std::vector<std::size_t> eTags;
      std::vector<std::size_t> nTags;
      gmsh::model::mesh::getElementsByType(MSH_TRI_3, eTags, nTags, dimTag.second);
      for (auto n: nTags)
        entity2Tags[dimTag].push_back(n);
    }
  }


  //
  // Construct Micro Mesh
  //
  int nbrRefine = int(log2(clscale/clrefine)) - 2;
  if (opt == 0) {
    gmsh::model::mesh::clear();
    gmsh::option::setNumber("Mesh.MeshSizeFactor", clrefine);
    gmsh::option::setNumber("Mesh.Algorithm", 6);
    gmsh::model::mesh::generate(2);
    // gmsh::clear();
    // gmsh::open(filename);
  }
  else if (opt == 1) {
    for (int i = 0; i < nbrRefine; ++i) {
      gmsh::model::mesh::refine();
    }
    gmsh::model::mesh::optimize("UntangleMeshGeometry");
  }
  else if (opt == 2) {
    gmsh::vectorpair dimTags;
    gmsh::model::getEntities(dimTags,2);
    gmsh::model::mesh::clear(dimTags);
    for (int i = 0; i < nbrRefine; ++i) {
      gmsh::model::mesh::refine();
    }
    gmsh::option::setNumber("Mesh.MeshSizeFactor", clrefine);
    gmsh::option::setNumber("Mesh.Algorithm", 6);
    gmsh::model::mesh::generate(2);
  }
  
  // gmsh::fltk::run();

  std::vector<std::size_t> nodeTags;
  std::vector<double> coord;
  std::vector<double> parametricCoord;
  // gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, -1, true, false);
  gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 1, -1, true, false);


  //
  // Recover Tags
  //
  std::map<size_t, size_t> tag2Index;
  for (size_t i = 0; i < nodeTags.size(); ++i) {
    tag2Index[nodeTags[i]] = i;
  }
  
  std::map<int, int> old2New;
  for (size_t iv = 0; iv < vertexTags.size(); ++iv) {
    size_t minTag = 0;
    double minDistance = std::numeric_limits<double>::max(), distance, tmp;
    for (size_t i = 0; i < nodeTags.size(); ++i) {
      distance = 0.;
      int j = 0;
      for (; j < 3; ++j) {
        tmp = coord[3*i+j] - vertexCoord[3*iv+j];
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
  for (size_t j = 0; j < macroElementNodeTags.size(); ++j) {
    macroElementNodeTags[j] = old2New[macroElementNodeTags[j]];
  }
  for (auto it =  entity2Tags.begin(); it != entity2Tags.end(); ++it) {
    for (size_t i = 0; i < it->second.size(); ++i)
      it->second[i] = old2New[it->second[i]];
  }

  meshModif(entity2Tags);
}



void constructNodes(const std::vector<size_t> vertexTags,
		    std::vector<MVertex*> & nodes,
		    std::vector<size_t> & tags,
		    std::vector<double> & coord,
		    std::vector<double> & parametricCoord,
		    std::map<size_t,size_t> & tag2Index,
		    std::map<MVertex *, bool> & nodeIsVertex) {
  // All nodes
  gmsh::model::mesh::getNodes(tags, coord, parametricCoord, 2, -1, true, true);

  nodes.resize(tags.size());
  tags.resize(tags.size());
  for (size_t i = 0; i < tags.size(); ++i) {
    auto v = new MVertex(coord[3*i], coord[3*i+1], coord[3*i+2]);
    v->setIndex(i);
    nodes[i] = v;
    tag2Index[tags[i]] = i;
    nodeIsVertex[v] = false;
  }

  for (auto t: vertexTags)
    nodeIsVertex[nodes[tag2Index[t]]] = true;

}


void constructTriangles(const std::vector<MVertex*> & nodes,
			const std::map<size_t,size_t> & nodeTag2Index,
			std::vector<MTriangle*> & triangles,
			std::vector<size_t> & triangleTags,
			std::vector<size_t> & triangleNodeTags,
			std::map<size_t,size_t> & triangleTag2Index,
			std::map<MVertex *, std::vector<MTriangle *>> & node2Triangles,
			std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> & edge2Triangles) {
  // All triangles
  gmsh::model::mesh::getElementsByType(MSH_TRI_3, triangleTags, triangleNodeTags);

  triangles.resize(triangleTags.size());
  for (size_t i = 0; i < triangleTags.size(); ++i) {
    auto i0 = nodeTag2Index.at(triangleNodeTags[3*i]);
    auto i1 = nodeTag2Index.at(triangleNodeTags[3*i+1]);
    auto i2 = nodeTag2Index.at(triangleNodeTags[3*i+2]);
    auto v0 = nodes[i0];
    auto v1 = nodes[i1];
    auto v2 = nodes[i2];

    auto t = new MTriangle(v0,v1,v2,i);
    triangles[i] = t;

    for (int j = 0; j < 3; ++j) {
      node2Triangles[t->getVertex(j)].push_back(t);
      edge2Triangles[t->getEdge(j)].push_back(t);
    }

    triangleTag2Index[triangleTags[i]] = i;
  }
}


void constructLoops(const std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> & edge2Triangles,
		    const std::vector<MTriangle*> & triangles,
		    const std::map<MVertex *, bool> nodeIsVertex,
		    std::vector<std::vector<MVertex *>> & loops,
		    std::vector<std::vector<size_t>> & loopIndices,
		    std::vector<std::vector<double>> & loopLengthFromFirst) {
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
      /* return 0; */
    }
  }

  if(!SortEdgeConsecutive(boundaries, loops)) {
    Msg::Error("Wrong topology of boundary mesh for parametrization");
    /* return 0; */
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
      if (nodeIsVertex.at(loop[i])) {
        std::rotate(loop.begin(), loop.begin()+i, loop.end()-1);
        loop[loop.size()-1] = loop[0];
        break;
      }
    }
  }

  // Get vertices positions
  loopIndices.resize(loops.size());
  loopLengthFromFirst.resize(loops.size());
  for(std::size_t j = 0; j < loops.size(); j++) {
    std::vector<MVertex *>& loop = loops[j];
    double l = 0.;
    for(std::size_t i = 1; i < loop.size(); i++) {
      l += loop[i]->point().distance(loop[i - 1]->point());
      if (nodeIsVertex.at(loop[i])
          || i == loop.size()-1) {
        loopIndices[j].push_back(i);
        loopLengthFromFirst[j].push_back(l);
      }
    }
  }

  //gmsh::fltk::run();
}


void untangle(std::vector<std::size_t> & nodeTags,
	      std::vector<double> & coord,
	      std::vector<MVertex*> & nodes,
	      std::vector<std::vector<MVertex *>> & loops,
	      std::vector<MTriangle*> & triangles,
	      std::vector<size_t> & tags) {
  //
  // U N T A N G L E
  //
  auto untangleStart = std::chrono::high_resolution_clock::now();
  if (!WINSLOW) {
    gmsh::model::mesh::optimize("UntangleMeshGeometry");
    std::vector<double> parametricCoord;
    gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, -1, true);
  }
  else {
    std::vector<std::array<double, 2> > untanglePoints(nodes.size());
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
    // auto index = loops[0][0]->getIndex();
    
    std::vector<std::array<uint32_t, 3> > untangleTriangles(triangles.size());
    for (size_t i = 0; i < triangles.size(); ++i) {
      for (int j = 0; j < 3; ++j) {
        int index = triangles[i]->getVertex(j)->getIndex();
        untangleTriangles[i][j] = static_cast<uint32_t>(index);
      }
    }

    std::vector<std::array<std::array<double, 2>, 3> > untangleTriIdealShapes = {};
    double lambda = 1.;
    
    untangle_triangles_2D(untanglePoints, untangleLocked, untangleTriangles, untangleTriIdealShapes, lambda);

    for (size_t i = 0; i < nodes.size(); ++i) {
      coord[3*i] = untanglePoints[i][0];
      coord[3*i+1] = untanglePoints[i][1];
      auto n = nodes[i];
      n->x() = coord[3*i];
      n->y() = coord[3*i+1];
      //n->z() = coord[3*i+2];
      gmsh::model::mesh::setNode(tags[i], {coord[3*i], coord[3*i+1], coord[3*i+2]}, {});
    }

  }
  auto untangleStop = std::chrono::high_resolution_clock::now();
  auto untangleDuration = std::chrono::duration_cast<std::chrono::milliseconds>(untangleStop - untangleStart);
  std::cout << "Expanded in " << untangleDuration.count()/1e3 << "sec" << std::endl;

}



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

static void drawGeodesics(highOrderPolyMesh & hop, std::vector< std::vector<int> > & geodesicLines)
{
  for (size_t i = 0; i < hop.triangles.size()/3; i++) {
    for (int j = 0; j < 3; ++j) {
      size_t i0 = hop.triangles[3*i+j];
      size_t i1 = hop.triangles[3*i+(j+1)%3];
      // if (i0 > i1)
      //   std::swap(i0,i1);
      auto path = hop.geodesics[{i0,i1}];
      std::vector<size_t> geodesicPoints(path.size());
      for (size_t k = 0; k < path.size(); ++k) {
        geodesicPoints[k] = gmsh::model::geo::addPoint(path[k].x(), path[k].y(), path[k].z());
      }
      geodesicLines[3*i+j].resize(path.size()-1);
      for (size_t k = 0; k < path.size()-1; ++k)
        geodesicLines[3*i+j][k] = gmsh::model::geo::addLine(geodesicPoints[k], geodesicPoints[k+1]);
    }
  }
  gmsh::model::geo::synchronize();
}
