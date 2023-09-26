#ifndef CFMB_MESH_H
#define CFMB_MESH_H

#include <iostream>
#include <map>
#include <vector>
#include "gmsh.h"
#include "tools.hxx"

namespace IFF{
  
  class Line;
  class Triangle;
  class Vertex;
  class Edge;

  class Mesh
  {
  public:
    Mesh();
    Mesh(bool unused);
    Mesh(const std::string & meshFileName);
    ~Mesh(){}

    void loadMesh();
    void splitMeshOnEdges(std::vector<Edge *> edgSplit, Mesh &meshSplitted);
    Vertex* getVertexByTag(size_t tagVertex){return &(m_vertices[m_tagToVertices[tagVertex]]);}
    std::map<size_t, size_t> m_tagToVertices;
    void createCutGraph();
  
    double getHmax(){return m_hmax;}
    double getHmax(std::vector<Triangle *> &tri);
    double getHmin(){return m_hmin;}
    double getHmin(std::vector<Triangle *> &tri);

    void _buildVertTri();
    void _buildVertNeighbours();
    void _buildEdges();
  
    std::vector<Vertex *> m_pVertices;
    std::vector<Line *> m_pLines;
    std::vector<Triangle *> m_pTriangles;
    std::vector<Edge *> m_pEdges;
    std::vector<Edge *> m_pBoundaryEdges;
    std::vector<Vertex *> m_pBoundaryVertices;
    std::vector<Vertex *> m_pSingularities;
    std::vector<Edge *> m_cutGraph;
    std::map<Vertex *, std::vector<Vertex *>> m_verticesNeighbours;
    std::map<Vertex *, std::vector<Triangle *>> m_verticesToTriangles;
    size_t m_maxVertexTag;

    void printInfos(){
      gmsh::logger::write("MESH: n_vertices: " + std::to_string(m_pVertices.size()), "info");
      gmsh::logger::write("MESH: n_lines: " + std::to_string(m_pLines.size()), "info");
      gmsh::logger::write("MESH: n_triangles: " + std::to_string(m_pTriangles.size()), "info");
      gmsh::logger::write("MESH: n_edges: " + std::to_string(m_pEdges.size()), "info");
      gmsh::logger::write("MESH: n_boundaryEdges: " + std::to_string(m_pBoundaryEdges.size()), "info");
      gmsh::logger::write("MESH: n_boundaryVertices: " + std::to_string(m_pBoundaryVertices.size()), "info");
      gmsh::logger::write("MESH: hmin: " + std::to_string(m_hmin), "info");
      gmsh::logger::write("MESH: hmax: " + std::to_string(m_hmax), "info");
    }

    void _computeDistancesToBndAndSing();
    std::vector<bool> _createEdgeTree();

    // CAREFULL!! Probably stupid design to be changed, but if these vector are reallocated then we have to update all pointers... TO BE CHANGED
    std::vector<Vertex> m_vertices;
    std::vector<Line> m_lines;
    std::vector<Triangle> m_triangles;
    std::vector<Edge> m_edges;
    std::vector<double> m_distanceToBndAndSing;
    double m_hmin;
    double m_hmax;
  private:
  };

  class Vertex
  {
  public:
    Vertex(std::vector<double>::const_iterator coord, size_t tag){
      m_coord.resize(3, 0);
      for(int k=0; k<3; k++)
	m_coord[k] = coord[k];
      m_tag = tag;
      m_index = -1;
      m_geodesicNormal.resize(3, 0.0);
    }
    ~Vertex(){}
    double x(){return m_coord[0];}
    double y(){return m_coord[1];}
    double z(){return m_coord[2];}
    const std::vector<double> *coord(){return &m_coord;}
    size_t getNum() const {return m_tag;}
    bool operator==(const Vertex &v2) const
    {
      return (getNum() == v2.getNum());
    }
    bool operator<(const Vertex &v2) const
    {
      return (getNum() < v2.getNum());
    }
    size_t getIndex(){return m_index;}
    void setIndex(size_t i){m_index = i;}
    size_t getTag(){return m_tag;}
    double getCoord(size_t k){return m_coord[k];}
    // void addpEdge(Edge *e){m_edges.push_back(e);}
    std::vector<double> getCoord(){return m_coord;}
    // std::vector<Edge *> m_edges;
    std::vector<double> m_geodesicNormal;
  
  private:
    size_t m_tag; //Global tag
    size_t m_index; //tag for computations. Can be modified at will
    std::vector<double> m_coord;

  };

  class Edge
  {
  public:
    Edge(Vertex* v0, Vertex* v1){
      m_vertices.resize(2);
      if(*v0 == *v1){
	std::cout << "Wrong edge creation" << std::endl;
	exit(0);
      }
      if(v0->getNum() < v1->getNum()){
	m_vertices[0] = v0;
	m_vertices[1] = v1;
      }
      if(v0->getNum() > v1->getNum()){
	m_vertices[0] = v1;
	m_vertices[1] = v0;
      }
      m_index = -1;
      m_triangles.reserve(2);
      isBoundary = false;
    }
    ~Edge(){}
    Vertex* getMinVertex() const {return m_vertices[0];}
    Vertex* getMaxVertex() const {return m_vertices[1];}
    Vertex* getVertex(size_t k) const {return m_vertices[k];}
    size_t getIndex() const{return m_index;}
    void setIndex(size_t i){m_index = i;}
    double length() const {return tools::distance(m_vertices[0]->getCoord(), m_vertices[1]->getCoord());}
    void addpTriangle(Triangle *tri){m_triangles.push_back(tri);}
    void addpLine(Line *line){m_plines.push_back(line);}
  
    bool operator==(const Edge &e2) const
    {
      return (getMinVertex()->getNum() == e2.getMinVertex()->getNum() &&
	      getMaxVertex()->getNum() == e2.getMaxVertex()->getNum());
    }

    bool operator<(const Edge &e2) const
    {
      if(getMinVertex()->getNum() != e2.getMinVertex()->getNum())
	return getMinVertex()->getNum() < e2.getMinVertex()->getNum();
      else
	return getMaxVertex()->getNum() < e2.getMaxVertex()->getNum();
    }
  
    size_t m_index;
    std::vector<Vertex*> m_vertices;
    std::vector<Triangle* > m_triangles;
    std::vector<Line* > m_plines;
    std::vector<double> m_geodesicNormal;
    bool isBoundary;
  private:
  };

  class Triangle
  {
  public:
    Triangle(std::vector<std::size_t>::const_iterator triNodes, Mesh* mesh, size_t tag){
      m_vertices.reserve(3);
      m_edges.reserve(3);
      for(int k=0; k<3; k++){
	m_vertices.push_back(mesh->getVertexByTag(triNodes[k]));
      }
      m_tag = tag;
      m_index = -1;
    }
    ~Triangle(){}
  
    Vertex* getVertex(int k){return m_vertices[k];}
    void setVertex(int k, Vertex *v){m_vertices[k] = v;}
    Edge* getEdge(int k){return m_edges[k];}
    void add_pedge(Edge *e){m_edges.push_back(e);}
    size_t getTag() const {return m_tag;}
    size_t getLocalIndexVert(Vertex *vert){
      size_t locInd = -1;
      for(size_t k=0; k<m_vertices.size(); k++){
	Vertex *v = m_vertices[k];
	if((*v) == (*vert)){
	  locInd = k;
	  break;
	}
      }
      return locInd;
    }
    size_t getLocalIndexEdge(Edge *edg){
      size_t locInd = -1;
      for(size_t k=0; k<m_edges.size(); k++){
	Edge *e = m_edges[k];
	if((*e) == (*edg)){
	  locInd = k;
	  break;
	}
      }
      return locInd;
    }
    size_t getIndex() const {return m_index;}
    void setIndex(size_t i){m_index = i;}
    std::vector<double> getShapeFunctions(const std::vector<double> &coordParam);
    std::vector<std::vector<double>>* getGradShapeFunctions(const std::vector<double> &coordParam, double &det);
    std::vector<std::vector<double>>* getGradShapeFunctions(double &det);
    std::vector<double> interpolate(const std::vector<double> &xi, const std::vector<std::vector<double>> &nodeFunc);
    std::vector<double> computePhysicalCoord(const std::vector<double> &xi);
  
    size_t m_tag;
    size_t m_index;
    std::vector<Vertex*> m_vertices;
    std::vector<Edge*> m_edges;
    std::vector<double> m_normal;
    double m_det;
    std::vector<std::vector<double>> m_gsf;

    bool operator==(const Triangle &t2) const
    {
      return (getTag() == t2.getTag());
    }

    bool operator<(const Triangle &t2) const
    {
      return (getTag() < t2.getTag());
    }
  
  private:
  };


  class Line
  {
  public:
    Line(std::vector<std::size_t>::const_iterator lineNodes, Mesh* mesh, size_t tag){
      m_vertices.reserve(2);
      m_edges.reserve(1);
      for(int k=0; k<2; k++){
	m_vertices.push_back(mesh->getVertexByTag(lineNodes[k]));
      }
      m_tag = tag;
    }
    ~Line(){}
    Vertex* getVertex(int k){return m_vertices[k];}

    void add_pedge(Edge *e){m_edges.push_back(e);}

    size_t m_tag;
    std::vector<Vertex*> m_vertices;
    std::vector<Edge*> m_edges;
  private:  
  };

}
#endif
