#include <gmsh.h>
#include "mesh.hxx"
#include <set>
#include <ctime>
#include "tools.hxx"
#include "timer.hxx"
#include <queue>
// #include "visualization.hxx"

namespace IFF{
  
  Mesh::Mesh(): m_hmin(0.0), m_hmax(0.0){

  }

  Mesh::Mesh(bool unused){
    loadMesh();
  }
  Mesh::Mesh(const std::string & meshFileName){
    gmsh::open(meshFileName);
    loadMesh();
  }
  
  void Mesh::loadMesh(){
    // gmsh::open(meshFileName);
    // gmsh::model::mesh::rebuildNodeCache();
    // gmsh::vectorpair dimTags;
    // gmsh::model::getEntities(dimTags);
    // retreive vertices
    std::vector<size_t> nodeTags;
    std::vector<double> coordNodes;
    std::vector<double> parametricCoord;
    gmsh::model::mesh::getNodes(nodeTags, coordNodes, parametricCoord, -1, -1, false, false);
    m_vertices.reserve(nodeTags.size());
    m_maxVertexTag = 0;
    for(size_t k=0; k<nodeTags.size(); k++){
      m_vertices.push_back(Vertex(coordNodes.begin() + 3*k, nodeTags[k]));
      m_tagToVertices[nodeTags[k]] = m_vertices.size() - 1;
      if(nodeTags[k] > m_maxVertexTag)
	m_maxVertexTag = nodeTags[k];
    }
  
    // retreive triangles
    std::vector<int> elementTypes;
    std::vector<std::vector<std::size_t> > elementTags;
    std::vector<std::vector<std::size_t> > elementsNodeTags;
    gmsh::model::mesh::getElements(elementTypes, elementTags, elementsNodeTags);
  
    // Purge vertices from the one not belonging to triangles
    std::vector<Vertex> purgedVertices;
    std::map<size_t, size_t> purgedTagToVertices;
    for(Vertex &v: m_vertices)
      v.setIndex(0);
    for(size_t k=0; k<elementTags.size(); k++)
      if(elementTypes[k]==2){
	std::vector<std::size_t> vt = elementsNodeTags[k];
	for(std::size_t &t: vt)
	  m_vertices[m_tagToVertices[t]].setIndex(1);
      }
    m_maxVertexTag = 0;
    for(Vertex &v: m_vertices)
      if(v.getIndex() > 0){
	purgedVertices.push_back(Vertex(v.getCoord().begin(), v.getTag()));
	purgedTagToVertices[v.getTag()] = purgedVertices.size() - 1;
	if(v.getTag() > m_maxVertexTag)
	  m_maxVertexTag = v.getTag();
      }

    // std::cout << "size v: " << m_vertices.size() << std::endl;
    m_vertices = purgedVertices;
    // std::cout << "size tv: " << m_tagToVertices.size() << std::endl;
    m_tagToVertices = purgedTagToVertices;
    // std::cout << "size purged v: " << m_vertices.size() << std::endl;
    // std::cout << "size ourged tv: " << m_tagToVertices.size() << std::endl;
    //Build triangles
    for(size_t k=0; k<elementTypes.size(); k++){
      // std::cout << "element type: " << elementTypes[k] << " / n elements: " << elementTags[k].size() << std::endl;
      // if(elementTypes[k]==1){
      //   for(size_t iT=0; iT<elementTags[k].size(); iT++){
      // 	m_lines.push_back(Line(elementsNodeTags[k].begin() + 2*iT, this, elementTags[k][iT]));
      //   }
      // }
      if(elementTypes[k]==2){
	for(size_t iT=0; iT<elementTags[k].size(); iT++){
	  m_triangles.push_back(Triangle(elementsNodeTags[k].begin() + 3*iT, this, elementTags[k][iT]));
	}
      }
    }

    // build edges. TODO: add lines
    std::clock_t c_start = std::clock();
    // gmsh::logger::write("MESH: building edges", "info");
    std::vector<std::pair<Edge, Triangle *>> edges;
    edges.reserve(3*m_triangles.size());
    //Create set of edges
    for(size_t k=0; k<m_triangles.size(); k++){
      for(size_t l=0; l<3; l++){
	Edge edgTriK(m_triangles[k].getVertex(l), m_triangles[k].getVertex((l+1)%3));
	edges.push_back(std::make_pair(edgTriK, &(m_triangles[k])));
      }
      std::vector<double> v0{0.0, 0.0, 0.0};
      std::vector<double> v1{0.0, 0.0, 0.0};
      std::vector<double> coord0 = m_triangles[k].getVertex(0)->getCoord();
      std::vector<double> coord1 = m_triangles[k].getVertex(1)->getCoord();
      std::vector<double> coord2 = m_triangles[k].getVertex(2)->getCoord();
      for(size_t l=0; l<3; l++){
	v0[l] = coord1[l] - coord0[l];
	v1[l] = coord2[l] - coord0[l];
      }
      m_triangles[k].m_normal = tools::crossprod(v0, v1);
      tools::normalize(m_triangles[k].m_normal);
    }
    std::sort(edges.begin(), edges.end(), [&](std::pair<Edge, Triangle *> i1, std::pair<Edge, Triangle *> i2){return i1.first < i2.first;});
  
    m_edges.reserve(edges.size());
    Edge *edg_prec = NULL;
    for(size_t k=0; k<edges.size(); k++){
      bool isSame = false;
      Edge &edgK = edges[k].first;
      Triangle *tri = edges[k].second;
      if(edg_prec)
	if(*edg_prec == edgK)
	  isSame = true;
      if(!isSame){
	m_edges.push_back(edgK);
      }
      m_edges[m_edges.size()-1].addpTriangle(tri);
      tri->add_pedge(&(m_edges[m_edges.size()-1]));
      edg_prec = &(m_edges[m_edges.size()-1]);
    }

    //Order tri->m_edges
    for(Triangle &tri: m_triangles){
      for(size_t k=0; k<2; k++){
	Edge e(tri.getVertex(k), tri.getVertex((k+1)%3));
	size_t index = -1;
	for(size_t l=0; l<3; l++){
	  if(*(tri.m_edges[l]) == e){
	    index = l;
	    break;
	  }
	}
	if(index != k){
	  std::swap(tri.m_edges[k], tri.m_edges[index]);
	}
      }
    }
  
    std::clock_t c_end = std::clock();
    double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
    // gmsh::logger::write("MESH: Edge building time: " + std::to_string(time_elapsed_ms) + " ms", "info");

    _buildVertNeighbours();
  
    // retreive boundary edges and vertices
    // Create normals at boundaryVertices
    // gmsh::logger::write("MESH: define boundary", "info");
    std::vector<bool> isVertBoundary(m_vertices.size(), false);
    m_hmin = std::numeric_limits<double>::max();
    m_hmax = -1.0;
    for(auto &edg: m_edges){
      double length = tools::distance(edg.m_vertices[0]->getCoord(), edg.m_vertices[1]->getCoord());
      if(length > m_hmax)
	m_hmax = length;
      if(length < m_hmin)
	m_hmin = length;
      if(edg.m_triangles.size()<2){
	m_pBoundaryEdges.push_back(&edg);
	isVertBoundary[m_tagToVertices[edg.m_vertices[0]->getNum()]] = true;
	isVertBoundary[m_tagToVertices[edg.m_vertices[1]->getNum()]] = true;

	Triangle *tri = edg.m_triangles[0];
	int iEdg = -1;
	for(size_t k=0; k<3; k++){
	  Edge e = Edge(tri->getVertex(k), tri->getVertex((k+1)%3));
	  if(e == edg)
	    iEdg = k;
	}
	std::vector<double> v0 = tri->getVertex(iEdg)->getCoord();
	std::vector<double> v1 = tri->getVertex((iEdg+1)%3)->getCoord();
	std::vector<double> normEdgVect{0.0, 0.0, 0.0};
	for(size_t k=0; k<3; k++)
	  normEdgVect[k] = v1[k] - v0[k];
	tools::normalize(normEdgVect);
	edg.m_geodesicNormal = tools::crossprod(normEdgVect, tri->m_normal);
	for(size_t l=0; l<2; l++){
	  if(tools::norm(edg.m_vertices[l]->m_geodesicNormal) < 1e-12)
	    for(size_t k=0; k<3; k++)
	      edg.m_vertices[l]->m_geodesicNormal[k] = edg.m_geodesicNormal[k];
	  else{
	    tools::normalize(edg.m_vertices[l]->m_geodesicNormal);
	    if(fabs(tools::dotprod(edg.m_geodesicNormal, edg.m_vertices[l]->m_geodesicNormal)) >= sqrt(2.0)/2.0)
	      for(size_t k=0; k<3; k++)
		edg.m_vertices[l]->m_geodesicNormal[k] += edg.m_geodesicNormal[k];
	    else{
	      for(size_t k=0; k<3; k++)
		edg.m_vertices[l]->m_geodesicNormal[k] += edg.m_geodesicNormal[k];
	      tools::normalize(edg.m_vertices[l]->m_geodesicNormal);
	      std::vector<double> rotatedNormal{0.0, 0.0, 0.0};
	      rotatedNormal[0] = edg.m_vertices[l]->m_geodesicNormal[0]*sqrt(2.0)/2.0 + edg.m_vertices[l]->m_geodesicNormal[1]*sqrt(2.0)/2.0;
	      rotatedNormal[1] = edg.m_vertices[l]->m_geodesicNormal[0]*sqrt(2.0)/2.0 - edg.m_vertices[l]->m_geodesicNormal[1]*sqrt(2.0)/2.0;
	      edg.m_vertices[l]->m_geodesicNormal = rotatedNormal;
	    }
	  }
	}
      }
    }
    for(Edge *e: m_pBoundaryEdges)
      e->isBoundary = true;
  
    for(size_t k=0; k<isVertBoundary.size(); k++)
      if(isVertBoundary[k]){
	m_pBoundaryVertices.push_back(&(m_vertices[k]));
	tools::normalize(m_vertices[k].m_geodesicNormal);
      }
    
    // Create pointer vectors
    m_pVertices.reserve(m_vertices.size());
    for(size_t k=0; k<m_vertices.size(); k++)
      m_pVertices.push_back(&(m_vertices[k]));
    m_pLines.reserve(m_lines.size());
    for(size_t k=0; k<m_lines.size(); k++)
      m_pLines.push_back(&(m_lines[k]));
    m_pTriangles.reserve(m_triangles.size());
    for(size_t k=0; k<m_triangles.size(); k++)
      m_pTriangles.push_back(&(m_triangles[k]));
    m_pEdges.reserve(m_edges.size());
    for(size_t k=0; k<m_edges.size(); k++)
      m_pEdges.push_back(&(m_edges[k]));

    //Create ordered vertToTri
    _buildVertTri(); //Needs m_pBoundaryVertices and m_pBoundaryEdges to exists
  
    // gmsh::logger::write("n_edges: " + std::to_string(m_edges.size()), "info");
    // gmsh::logger::write("n_vertices: " + std::to_string(m_vertices.size()), "info");
    // gmsh::logger::write("n_lines: " + std::to_string(m_lines.size()), "info");
    // gmsh::logger::write("n_triangles: " + std::to_string(m_triangles.size()), "info");
  }

  void Mesh::_buildVertTri(){
    m_verticesToTriangles.clear();
    for(Triangle &tri: m_triangles){
      for(Vertex *v: tri.m_vertices)
	m_verticesToTriangles[v].push_back(&tri);
    }
    std::vector<bool> isVertBoundary(m_vertices.size(), false);
    for(Edge *e: m_pBoundaryEdges){
      double test = e->m_vertices[0]->x();
      isVertBoundary[m_tagToVertices[e->m_vertices[0]->getNum()]] = true;
      isVertBoundary[m_tagToVertices[e->m_vertices[1]->getNum()]] = true;
    }
    for(auto &kv: m_verticesToTriangles){
      //Pick first triangle
      if(isVertBoundary[m_tagToVertices[kv.first->getNum()]]){
	size_t indexFirstTri = -1;
	for(size_t k=0; k<kv.second.size(); k++){
	  // size_t indexEdge = -1;
	  // int nBndEdges = 0;
	  // for(size_t l=0; l<kv.second[k]->m_edges.size(); l++){
	  //   Edge *e = kv.second[k]->m_edges[l];
	  //   if(e->m_triangles.size() < 2){
	  //     indexEdge = l;
	  //     nBndEdges++;
	  //   }
	  // }
	  // if(indexEdge != -1 && nBndEdges == 1){
	  //   size_t indexVert = -1;
	  //   for(size_t l=0; l<kv.second[k]->m_vertices.size(); l++){
	  //     Vertex *v = kv.second[k]->m_vertices[l];
	  //     if((*v) == (*kv.first)){
	  //       indexVert = l;
	  //       break;
	  //     }
	  //   }
	  //   if(indexVert == indexEdge){
	  //     indexFirstTri = k;
	  //     break;
	  //   }
	  // }
	  // if(nBndEdges > 1){
	  //   indexFirstTri = k;
	  //   break;
	  // }
	  for(size_t l=0; l<kv.second[k]->m_edges.size(); l++){
	    Edge *e = kv.second[k]->m_edges[l];
	    if(e->m_triangles.size() < 2 && kv.second[k]->getLocalIndexVert(kv.first) == l){
	      // indexEdge = l;
	      indexFirstTri = k;
	      break;
	    }
	  }
	}

	if(indexFirstTri == -1){
	  std::cout << "Error in finding first element in Mesh::_buildVertTri" << std::endl;
	}
      
	std::swap(kv.second[0], kv.second[indexFirstTri]);
      }
      for(size_t k=0; k<kv.second.size()-1; k++){
	size_t indV = kv.second[k]->getLocalIndexVert(kv.first);
	Edge *e = kv.second[k]->m_edges[(indV+2)%3];
	Triangle *nextTri;
	if(e->m_triangles.size() == 2){
	  if(*(e->m_triangles[0]) == *(kv.second[k]))
	    nextTri = e->m_triangles[1];
	  else
	    nextTri = e->m_triangles[0];
	}
      
	size_t indexNextTri = -1;
	for(size_t l=k+1; l<kv.second.size(); l++)
	  if(*(kv.second[l]) == *nextTri)
	    indexNextTri = l;
	if(indexNextTri == -1){
	  std::cout << "Error in ordering triangles in Mesh::_buildVertTri" << std::endl;
	  std::cout << "vertex: " << kv.first->getTag() << std::endl;
	  std::cout << "current triangle: " << kv.second[k]->getTag() << std::endl;
	  std::cout << "index vertToTri: " << k << std::endl;
	  std::cout << "n vertToTri: " << kv.second.size() << std::endl;
	  for(auto &t: kv.second)
	    std::cout << "tri: " << t->getTag() << std::endl;
	}
	if(k+1 != indexNextTri){
	  std::swap(kv.second[k+1], kv.second[indexNextTri]);
	}
      }
    }
  }

  void Mesh::_buildVertNeighbours(){
    m_verticesNeighbours.clear();
    for(Vertex *v: m_pVertices)
      m_verticesNeighbours[v].reserve(5);
    for(Edge *e: m_pEdges){
      m_verticesNeighbours[e->getMinVertex()].push_back(e->getMaxVertex());
      m_verticesNeighbours[e->getMaxVertex()].push_back(e->getMinVertex());
    }
  }

  void Mesh::_buildEdges(){
    std::vector<std::pair<Edge, Triangle *>> edges;
    edges.reserve(3*m_triangles.size());
    //Create set of edges
    for(size_t k=0; k<m_triangles.size(); k++){
      for(size_t l=0; l<3; l++){
	Edge edgTriK(m_triangles[k].getVertex(l), m_triangles[k].getVertex((l+1)%3));
	edges.push_back(std::make_pair(edgTriK, &(m_triangles[k])));
      }
      std::vector<double> v0{0.0, 0.0, 0.0};
      std::vector<double> v1{0.0, 0.0, 0.0};
      std::vector<double> coord0 = m_triangles[k].getVertex(0)->getCoord();
      std::vector<double> coord1 = m_triangles[k].getVertex(1)->getCoord();
      std::vector<double> coord2 = m_triangles[k].getVertex(2)->getCoord();
      for(size_t l=0; l<3; l++){
	v0[l] = coord1[l] - coord0[l];
	v1[l] = coord2[l] - coord0[l];
      }
      m_triangles[k].m_normal = tools::crossprod(v0, v1);
      tools::normalize(m_triangles[k].m_normal);
    }
    std::sort(edges.begin(), edges.end(), [&](std::pair<Edge, Triangle *> i1, std::pair<Edge, Triangle *> i2){return i1.first < i2.first;});
  
    m_edges.clear();
    m_edges.reserve(edges.size());
    Edge *edg_prec = NULL;
    for(size_t k=0; k<edges.size(); k++){
      bool isSame = false;
      Edge &edgK = edges[k].first;
      Triangle *tri = edges[k].second;
      if(edg_prec)
	if(*edg_prec == edgK)
	  isSame = true;
      if(!isSame){
	m_edges.push_back(edgK);
      }
      m_edges[m_edges.size()-1].addpTriangle(tri);
      tri->add_pedge(&(m_edges[m_edges.size()-1]));
      edg_prec = &(m_edges[m_edges.size()-1]);
    }

    //Order tri->m_edges
    for(Triangle &tri: m_triangles){
      for(size_t k=0; k<2; k++){
	Edge e(tri.getVertex(k), tri.getVertex((k+1)%3));
	size_t index = -1;
	for(size_t l=0; l<3; l++){
	  if(*(tri.m_edges[l]) == e){
	    index = l;
	    break;
	  }
	}
	if(index != k){
	  std::swap(tri.m_edges[k], tri.m_edges[index]);
	}
      }
    }
  }

  void Mesh::splitMeshOnEdges(std::vector<Edge *> edgSplit, Mesh &ms){
    std::vector<int> multVert;
    multVert.resize(m_vertices.size(), 0);
    for(Edge *e: edgSplit){
      if(e->m_triangles.size() == 2){
	multVert[m_tagToVertices[e->getMinVertex()->getTag()]]++;
	multVert[m_tagToVertices[e->getMaxVertex()->getTag()]]++;
      }
    }
    for(Vertex *v: m_pBoundaryVertices)
      multVert[m_tagToVertices[v->getTag()]]++;

    size_t totalNewVertices = 0;
    for(int &m: multVert)
      if(m >= 2)
	totalNewVertices += m-1;
    ms.m_vertices.clear();
    ms.m_vertices.reserve(m_vertices.size() + totalNewVertices);
    for(Vertex &v: m_vertices)
      ms.m_vertices.push_back(v);
  
    ms.m_vertices = m_vertices;
    ms.m_tagToVertices = m_tagToVertices;
    ms.m_triangles.reserve(m_triangles.size());
    for(Triangle &t: m_triangles){
      std::vector<size_t> triNodes{t.getVertex(0)->getTag(), t.getVertex(1)->getTag(), t.getVertex(2)->getTag()};
      ms.m_triangles.push_back(Triangle(triNodes.begin(), &ms, t.getTag()));
    }

    //flag edges to split on
    for(Edge &e: m_edges){
      e.setIndex(0);
    }
    for(Edge *e: edgSplit)
      e->setIndex(1);
    for(Edge *e: m_pBoundaryEdges)
      e->setIndex(1);
    //set triangles indices for further used
    size_t cpt = 0;
    for(Triangle &t: m_triangles){
      t.setIndex(cpt);
      cpt++;
    }
    //loop on all vertices, create new vert and assign to appropriate triangles if mult>2
    size_t currentTag = m_maxVertexTag;
    for(auto &kv: m_verticesToTriangles){
      if(multVert[m_tagToVertices[kv.first->getTag()]] > 1){
	int nNewVert = 0;
	//find first triangle on which to loop
	size_t indFirstTri = -1;
	for(size_t k=0; k<kv.second.size(); k++){
	  Triangle *t = kv.second[k];
	  for(size_t l=0; l<3; l++){
	    if(t->getVertex(l) == kv.first && t->getEdge(l)->getIndex() > 0)
	      indFirstTri = k;
	  }
	  if(indFirstTri != -1)
	    break;
	}

	size_t indTri = indFirstTri;
	while(nNewVert < multVert[m_tagToVertices[kv.first->getTag()]] - 1){
	  Triangle *t = kv.second[indTri];
	  size_t locIndVert = -1;
	  for(size_t l=0; l<3; l++){
	    if(t->getVertex(l) == kv.first){
	      locIndVert = l;
	      break;
	    }
	  }
	  currentTag++;
	  Vertex newV(t->getVertex(locIndVert)->getCoord().begin(), currentTag);
	  if(t->getVertex(locIndVert)->m_geodesicNormal.size() > 0)
	    newV.m_geodesicNormal = t->getVertex(locIndVert)->m_geodesicNormal;
	
	  nNewVert++;
	  ms.m_vertices.push_back(newV);
	  ms.m_tagToVertices[currentTag] = ms.m_vertices.size() - 1;
	  ms.m_triangles[t->getIndex()].setVertex(locIndVert, &(ms.m_vertices[ms.m_vertices.size() -1]));
	  Edge *nextEdge = t->getEdge((locIndVert+2)%3);
	  while(nextEdge->getIndex() == 0){
	    indTri = (indTri + 1)%kv.second.size();
	    t = kv.second[indTri];
	    locIndVert = -1;
	    for(size_t l=0; l<3; l++){
	      if(t->getVertex(l) == kv.first){
		locIndVert = l;
		break;
	      }
	    }
	    ms.m_triangles[t->getIndex()].setVertex(locIndVert, &(ms.m_vertices[ms.m_vertices.size() -1]));
	    nextEdge = t->getEdge((locIndVert+2)%3);
	  }
	  indTri = (indTri + 1)%kv.second.size();
	}
      }
    }
    ms.m_maxVertexTag = currentTag;
  
    ms._buildEdges();

    // Create pointer vectors
    ms.m_pVertices.clear();
    ms.m_pVertices.reserve(ms.m_vertices.size());
    for(size_t k=0; k<ms.m_vertices.size(); k++)
      ms.m_pVertices.push_back(&(ms.m_vertices[k]));
    ms.m_pTriangles.clear();
    ms.m_pTriangles.reserve(ms.m_triangles.size());
    for(size_t k=0; k<ms.m_triangles.size(); k++)
      ms.m_pTriangles.push_back(&(ms.m_triangles[k]));
    ms.m_pEdges.clear();
    ms.m_pEdges.reserve(ms.m_edges.size());
    for(size_t k=0; k<ms.m_edges.size(); k++)
      ms.m_pEdges.push_back(&(ms.m_edges[k]));
  
    ms._buildVertNeighbours();

    //build boundary edges and vertices
    for(Vertex *v: ms.m_pVertices)
      v->setIndex(0);
    for(Edge *e: ms.m_pEdges)
      e->setIndex(0);
    for(Vertex *v: m_pVertices)
      v->setIndex(0);
    for(Edge *e: m_pEdges)
      e->setIndex(0);
    for(Vertex *v: m_pBoundaryVertices)
      v->setIndex(1);
    for(Edge *e: m_pBoundaryEdges)
      e->setIndex(1);
    for(size_t k=0; k<m_pTriangles.size(); k++){
      Triangle *t = m_pTriangles[k];
      Triangle *tCut = ms.m_pTriangles[k];
      for(size_t l=0; l<3; l++){
	if(t->getEdge(l)->getIndex() > 0)
	  tCut->getEdge(l)->setIndex(1);
	if(t->getVertex(l)->getIndex() > 0)
	  tCut->getVertex(l)->setIndex(1);
      }
    }
    for(Vertex *v: ms.m_pVertices)
      if(v->getIndex() > 0)
	ms.m_pBoundaryVertices.push_back(v);
    for(Edge *e: ms.m_pEdges)
      if(e->getIndex() > 0)
	ms.m_pBoundaryEdges.push_back(e);
    // ms.printInfos();
  }

  void Mesh::_computeDistancesToBndAndSing(){
    for(size_t k=0; k<m_pVertices.size(); k++)
      m_pVertices[k]->setIndex(k);
    m_distanceToBndAndSing.clear();
    m_distanceToBndAndSing.resize(m_pVertices.size());
    typedef std::pair<double, Vertex*> weightedVertex;
    std::vector<std::vector<weightedVertex>> weightedConnectivity;
    weightedConnectivity.resize(m_pVertices.size());
    for(size_t k=0; k<weightedConnectivity.size(); k++)
      weightedConnectivity[k].reserve(6);
  
    for(const Edge &e: m_edges){
      double length=e.length();
      weightedConnectivity[e.getVertex(0)->getIndex()].push_back(weightedVertex(length,e.getVertex(1)));
      weightedConnectivity[e.getVertex(1)->getIndex()].push_back(weightedVertex(length,e.getVertex(0)));
      m_distanceToBndAndSing[e.getVertex(0)->getIndex()]=std::numeric_limits<double>::max();
      m_distanceToBndAndSing[e.getVertex(1)->getIndex()]=std::numeric_limits<double>::max();
    }
    std::priority_queue<weightedVertex,std::vector<weightedVertex>, std::greater<weightedVertex>> priorityQueue;
    for(Vertex *v: m_pBoundaryVertices){
      m_distanceToBndAndSing[v->getIndex()]=0.0;
      priorityQueue.push(weightedVertex(0.0,v));
    }
    for(Vertex *v: m_pSingularities){
      m_distanceToBndAndSing[v->getIndex()]=0.0;
      priorityQueue.push(weightedVertex(0.0,v));
    }
    while(!priorityQueue.empty()){
      Vertex *v=priorityQueue.top().second;
      double distV=m_distanceToBndAndSing[v->getIndex()];
      priorityQueue.pop();
      for(const weightedVertex &wV: weightedConnectivity[v->getIndex()]){
	double dist=m_distanceToBndAndSing[wV.second->getIndex()];
	if(dist>distV+wV.first){
	  m_distanceToBndAndSing[wV.second->getIndex()]=distV+wV.first;
	  priorityQueue.push(weightedVertex(m_distanceToBndAndSing[wV.second->getIndex()],wV.second));
	}
      }
    }
  }

  std::vector<bool> Mesh::_createEdgeTree(){
    for(size_t k=0; k<m_pTriangles.size(); k++)
      m_pTriangles[k]->setIndex(k);
    for(size_t k=0; k<m_pEdges.size(); k++)
      m_pEdges[k]->setIndex(k);
    typedef std::pair<double,Triangle *> weightedTri;
    std::vector<bool> trianglePassed;
    trianglePassed.resize(m_pTriangles.size(), false);
    std::vector<double> triangleWeight;
    triangleWeight.resize(m_pTriangles.size(), 0.0);
    std::priority_queue<weightedTri,std::vector<weightedTri>, std::less<weightedTri>> pQueue;
    std::vector<bool> edgeTree;
    edgeTree.resize(m_pEdges.size(), true);

    for(Triangle *t: m_pTriangles){
      for(int k=0;k<3;k++){
	Vertex *v=t->getVertex(k);
	triangleWeight[t->getIndex()] += m_distanceToBndAndSing[v->getIndex()];
      }
      triangleWeight[t->getIndex()]/=3.0;
    }

    //Put random triangle as passed (or well chosen one
    Triangle *triangleLeft=m_pTriangles[0];
    trianglePassed[triangleLeft->getIndex()]=true;
    while(triangleLeft){
      for(Edge *e: triangleLeft->m_edges){
	if(!e->isBoundary){
	  for(Triangle *t: e->m_triangles){
	    if(!trianglePassed[t->getIndex()]){
	      pQueue.push(weightedTri(triangleWeight[t->getIndex()],t));
	      trianglePassed[t->getIndex()]=true;
	      edgeTree[e->getIndex()] = false;
	    }
	  }
	}
      }
      if(!pQueue.empty()){
	triangleLeft = pQueue.top().second;
	pQueue.pop();
      }
      else{
	triangleLeft=NULL;
	for(Triangle *t: m_pTriangles){
	  if(!trianglePassed[t->getIndex()]){
	    triangleLeft=t;
	    trianglePassed[triangleLeft->getIndex()]=true;
	    break;
	  }
	}
      }
    }
    return edgeTree;
  }

  void Mesh::createCutGraph(){
    // compute distances for ordering priority queue to get nice looking cutgraph
    _computeDistancesToBndAndSing();
    std::vector<bool> isEdgeCG = _createEdgeTree();
    // Trimming cut graph
    for(size_t k=0; k<m_edges.size(); k++)
      m_edges[k].setIndex(k);
    for(size_t k=0; k<m_vertices.size(); k++)
      m_vertices[k].setIndex(k);
    std::vector<int> multVert;
    multVert.resize(m_vertices.size(), 0);
    std::vector<std::vector<size_t>> vertToEdg;
    vertToEdg.resize(m_vertices.size());
    for(size_t k=0; k<m_pEdges.size(); k++){
      if(isEdgeCG[k]){
	Edge *e = m_pEdges[k];
	multVert[m_tagToVertices[e->getMinVertex()->getTag()]]++;
	multVert[m_tagToVertices[e->getMaxVertex()->getTag()]]++;
	vertToEdg[m_tagToVertices[e->getMinVertex()->getTag()]].push_back(e->getIndex());
	vertToEdg[m_tagToVertices[e->getMaxVertex()->getTag()]].push_back(e->getIndex());
      }
    }
    for(Vertex *v: m_pSingularities)
      multVert[m_tagToVertices[v->getTag()]]++;
    bool keepCleaning = true;
    while(keepCleaning){
      size_t indexLeaf = -1;
      for(size_t k=0; k<multVert.size(); k++){
	if(multVert[k] == 1){
	  indexLeaf = k;
	  break;
	}
      }
      if(indexLeaf != -1){
	while(indexLeaf != -1){
	  Edge *e;
	  for(size_t indE: vertToEdg[indexLeaf]){
	    if(isEdgeCG[indE]){
	      e = &(m_edges[indE]);
	      break;
	    }
	  }
	  Vertex *v;
	  if(*(e->getMinVertex()) == m_vertices[indexLeaf])
	    v = e->getMaxVertex();
	  else
	    v = e->getMinVertex();
	  isEdgeCG[e->getIndex()] = false;
	  multVert[e->getMinVertex()->getIndex()] -= 1;
	  multVert[e->getMaxVertex()->getIndex()] -= 1;
	  if(multVert[v->getIndex()] == 1)
	    indexLeaf = v->getIndex();
	  else
	    indexLeaf = -1;
	}
      }
      else
	keepCleaning = false;
    }
    //
    m_cutGraph.clear();
    for(size_t k=0; k<m_pEdges.size(); k++){
      if(isEdgeCG[k])
	m_cutGraph.push_back(m_pEdges[k]);
    }
  }


  double Mesh::getHmin(std::vector<Triangle *> &tri){
    double hmin = std::numeric_limits<double>::max();
    for(Triangle *t: tri){
      for(Edge *e: t->m_edges){
	double l = e->length();
	if(l < hmin)
	  hmin = l;
      }
    }
    return hmin;
  }

  double Mesh::getHmax(std::vector<Triangle *> &tri){
    double hmax = -1.0;
    for(Triangle *t: tri){
      for(Edge * e: t->m_edges){
	double l = e->length();
	if(l > hmax)
	  hmax = l;
      }
    }
    return hmax;
  }

  // -------------------------- Triangle -------------------------- //

  std::vector<double> Triangle::getShapeFunctions(const std::vector<double> &coordParam){
    // GlobalTimer::tic("TRI_GETSF");
    std::vector<double> sf;
    sf.resize(3, 0.0);
    sf[0] = 1 - coordParam[0] - coordParam[1];
    sf[1] = coordParam[0];
    sf[2] = coordParam[1];
    // GlobalTimer::toc();
    return sf;
  }

  std::vector<std::vector<double>>* Triangle::getGradShapeFunctions(const std::vector<double> &coordParam, double &det){
    // GlobalTimer::tic("TRI_GETGSF");

    if(m_gsf.size() == 0){
      std::vector<std::vector<double>> dxdxi;
      std::vector<std::vector<double>> dxidx;
      m_gsf.resize(3);
      dxdxi.resize(3);
      dxidx.resize(3);
      for(size_t k=0; k<3; k++){
	m_gsf[k].resize(3, 0.0);
	dxdxi[k].resize(3, 0.0);
	dxidx[k].resize(3, 0.0);
      }
      for (int i = 0; i < 2; ++i)//attention !! il faut faire quelque chose de spécial pour gérer les manifolds
	for (int j = 0; j < 3; ++j){
	  dxdxi[j][i] = m_vertices[i+1]->getCoord(j)-m_vertices[0]->getCoord(j);
	}
      dxdxi[2][2] = 1.0; // to fix
  
      m_det = dxdxi[0][0]*dxdxi[1][1]*dxdxi[2][2]+dxdxi[0][1]*dxdxi[1][2]*dxdxi[2][0]+dxdxi[0][2]*dxdxi[1][0]*dxdxi[2][1]-dxdxi[0][2]*dxdxi[1][1]*dxdxi[2][0]-dxdxi[0][1]*dxdxi[1][0]*dxdxi[2][2]-dxdxi[0][0]*dxdxi[1][2]*dxdxi[2][1];

      dxidx[0][0] = (dxdxi[1][1]*dxdxi[2][2]-dxdxi[1][2]*dxdxi[2][1])/(m_det);
      dxidx[1][0] = (dxdxi[1][2]*dxdxi[2][0]-dxdxi[1][0]*dxdxi[2][2])/(m_det);
      dxidx[2][0] = (dxdxi[1][0]*dxdxi[2][1]-dxdxi[1][1]*dxdxi[2][0])/(m_det);
    
      dxidx[0][1] = (dxdxi[0][2]*dxdxi[2][1]-dxdxi[0][1]*dxdxi[2][2])/(m_det);
      dxidx[1][1] = (dxdxi[0][0]*dxdxi[2][2]-dxdxi[0][2]*dxdxi[2][0])/(m_det);
      dxidx[2][1] = (dxdxi[0][1]*dxdxi[2][0]-dxdxi[0][0]*dxdxi[2][1])/(m_det);
    
      dxidx[0][2] = (dxdxi[0][1]*dxdxi[1][2]-dxdxi[0][2]*dxdxi[1][1])/(m_det);
      dxidx[1][2] = (dxdxi[0][2]*dxdxi[1][0]-dxdxi[0][0]*dxdxi[1][2])/(m_det);
      dxidx[2][2] = (dxdxi[0][0]*dxdxi[1][1]-dxdxi[0][1]*dxdxi[1][0])/(m_det);

      for(int j=0; j<3; j++){
	m_gsf[0][j] = 0;
	for(int i=0; i<2; ++i){
	  m_gsf[0][j] -= dxidx[i][j];
	  m_gsf[i+1][j] = dxidx[i][j];
	}
      }
    }
    // GlobalTimer::toc();
    det = m_det;
    return &m_gsf;
  }

  std::vector<std::vector<double>>* Triangle::getGradShapeFunctions(double &det){
    // GlobalTimer::tic("TRI_GETGSF");

    if(m_gsf.size() == 0){
      std::vector<std::vector<double>> dxdxi;
      std::vector<std::vector<double>> dxidx;
      m_gsf.resize(3);
      dxdxi.resize(3);
      dxidx.resize(3);
      for(size_t k=0; k<3; k++){
	m_gsf[k].resize(3, 0.0);
	dxdxi[k].resize(3, 0.0);
	dxidx[k].resize(3, 0.0);
      }
      for (int i = 0; i < 2; ++i)//attention !! il faut faire quelque chose de spécial pour gérer les manifolds
	for (int j = 0; j < 3; ++j){
	  dxdxi[j][i] = m_vertices[i+1]->getCoord(j)-m_vertices[0]->getCoord(j);
	}
      dxdxi[2][2] = 1.0; // to fix
  
      m_det = dxdxi[0][0]*dxdxi[1][1]*dxdxi[2][2]+dxdxi[0][1]*dxdxi[1][2]*dxdxi[2][0]+dxdxi[0][2]*dxdxi[1][0]*dxdxi[2][1]-dxdxi[0][2]*dxdxi[1][1]*dxdxi[2][0]-dxdxi[0][1]*dxdxi[1][0]*dxdxi[2][2]-dxdxi[0][0]*dxdxi[1][2]*dxdxi[2][1];

      dxidx[0][0] = (dxdxi[1][1]*dxdxi[2][2]-dxdxi[1][2]*dxdxi[2][1])/(m_det);
      dxidx[1][0] = (dxdxi[1][2]*dxdxi[2][0]-dxdxi[1][0]*dxdxi[2][2])/(m_det);
      dxidx[2][0] = (dxdxi[1][0]*dxdxi[2][1]-dxdxi[1][1]*dxdxi[2][0])/(m_det);
    
      dxidx[0][1] = (dxdxi[0][2]*dxdxi[2][1]-dxdxi[0][1]*dxdxi[2][2])/(m_det);
      dxidx[1][1] = (dxdxi[0][0]*dxdxi[2][2]-dxdxi[0][2]*dxdxi[2][0])/(m_det);
      dxidx[2][1] = (dxdxi[0][1]*dxdxi[2][0]-dxdxi[0][0]*dxdxi[2][1])/(m_det);
    
      dxidx[0][2] = (dxdxi[0][1]*dxdxi[1][2]-dxdxi[0][2]*dxdxi[1][1])/(m_det);
      dxidx[1][2] = (dxdxi[0][2]*dxdxi[1][0]-dxdxi[0][0]*dxdxi[1][2])/(m_det);
      dxidx[2][2] = (dxdxi[0][0]*dxdxi[1][1]-dxdxi[0][1]*dxdxi[1][0])/(m_det);

      for(int j=0; j<3; j++){
	m_gsf[0][j] = 0;
	for(int i=0; i<2; ++i){
	  m_gsf[0][j] -= dxidx[i][j];
	  m_gsf[i+1][j] = dxidx[i][j];
	}
      }
    }
    // GlobalTimer::toc();
    det = m_det;
    return &m_gsf;
  }

  std::vector<double> Triangle::interpolate(const std::vector<double> &xi, const std::vector<std::vector<double>> &nodeFunc){
    std::vector<double> sf = getShapeFunctions(xi);
    size_t nFields = nodeFunc[0].size();
    std::vector<double> interpolation(nFields, 0.0);
    for(size_t m=0; m<nFields; m++)
      for(size_t k=0; k<sf.size(); k++){
	interpolation[m] += sf[k]*nodeFunc[k][m];
      }
    return interpolation;
  }

  std::vector<double> Triangle::computePhysicalCoord(const std::vector<double> &xi){
    std::vector<std::vector<double>> coordNodes; //[N0, N1, N2][x, y, z]
    coordNodes.resize(3);
    for(size_t k=0; k<3; k++)
      coordNodes[k].resize(3, 0.0);
    for(size_t k=0; k<3; k++)
      for(size_t l=0; l<3; l++)
	coordNodes[k][l] = getVertex(k)->getCoord(l);

    std::vector<double> physicalCoord = interpolate(xi, coordNodes);

    return physicalCoord;
  }

}
