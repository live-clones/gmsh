// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#pragma once

#include <MVertex.h>
#include <MElement.h>
#include <MLine.h>
#include <vector>

namespace IFF{
  namespace tools{
    void normalize(std::vector<double> &v);
    void scale(std::vector<double> &v, double scaling);
    std::vector<double> getNormalizedVector(const std::vector<double> &v);
    std::vector<double> crossprod(const std::vector<double> &v0, const std::vector<double> &v1);
    double dotprod(const std::vector<double> &v0, const std::vector<double> &v1);
    double cosAngle(const std::vector<double> &v0, const std::vector<double> &v1);
    std::vector<double> diff(const std::vector<double> &v0, const std::vector<double> &v1);
    std::vector<double> sum(const std::vector<double> &v0, const std::vector<double> &v1);
    double norm(const std::vector<double> &v);
    double norm2(const std::vector<double> &v); // squared norm
    double norm(const double *v, const size_t &size);
    double distance(const std::vector<double> &v0, const std::vector<double> &v1);
    std::vector<double> rotateAlongDirection(const std::vector<double> &vectAxis, const double &theta, const std::vector<double> &v);
    double getAngleRotationAlongDirection(const std::vector<double> &vectAxis, const std::vector<double> &vInit, const std::vector<double> &vRotated);
    std::vector<double> getProjectionOnDirection(const std::vector<double> &dirProj, const std::vector<double> &v);
    std::vector<double> getProjectionOnHyperPlan(const std::vector<double> &normalHyperPlan, const std::vector<double> &v);
    void projectOnHyperPlan(const std::vector<double> &normalHyperPlan, std::vector<double> &v);
    std::vector<double> getVectInNewBase(const std::vector<double> &u, const std::vector<double> &v, const std::vector<double> &w, const std::vector<double> &vect);
    std::vector<double> getClosestVect(const std::vector<std::vector<double>> &listVects, const std::vector<double> &dirRef);
    int getIndexClosestVect(const std::vector<std::vector<double>> &listVects, const std::vector<double> &dirRef);
  }

  class Vertex;
  class Edge;
  class Element;
  class Mesh;
  
  namespace manifoldTools{//Tools for 2D discrete manifolds. Need all mesh classes
    std::vector<double> transportToNeighbourElement(Element *eRef, Element *eTarget, const std::vector<double> &vectToTransport);
  }
  
  class Element{
    friend class Mesh;
    friend class MeshRefiner;
    
    static std::vector<Element*> elementCollector;
    static std::vector<double> integrationWeights;
    static std::vector<std::vector<double>> integrationPoints;
  public:
    static Element* create(Mesh *m, MElement* el){Element *newE = new Element(m, el); elementCollector.push_back(newE); return newE;}
    Element(Mesh *m, MElement* el);
    ~Element(){}

    size_t getIndex(){return m_index;}
    size_t getGmshTag(){return m_e->getNum();}
    size_t getNumEdges(){return m_edges.size();}
    std::vector<Vertex*> getVertices(){return m_vertices;}
    Vertex* getVertex(int k){return m_vertices[k];}

    std::vector<Element*> getNeighboursElements(){return m_neighbourElements;}
    
    std::vector<double> getNormal();
    std::vector<double> getDirEdg(int iEdg);

    Edge* getEdge(int k){return m_edges[k];}
    std::vector<Edge*> getEdges(){return m_edges;}
    Edge* getCommonEdge(Element* otherEl);

    std::vector<Element*> getChildren(){return m_childElem;}
    
    double getArea();
    std::vector<double> getDet(int pOrder);
    std::vector<std::vector<double>> getIntegrationPoints(int pOrder);
    std::vector<double> getIntegrationWeights(int pOrder);
    std::vector<std::vector<double>> getCRSF(int pOrder);
    std::vector<std::vector<std::vector<double>>> getCRGradSF(int pOrder);
    std::vector<double> interpolateCR(double u, double v, const std::vector<std::vector<double>> &solTri);
    
    MElement *m_e;

    std::vector<std::vector<double>> getEdgesParamCoordInParentElem();
    
    //For solver interaction
    void setNumUnknown(int n){m_nUnknown = n;}
    int getNumUnknown(){return m_nUnknown;}

  private:
    std::vector<Vertex*> m_vertices;
    std::vector<Edge*> m_edges;
    std::vector<Element*> m_neighbourElements;

    size_t m_index;
    
    std::vector<double> m_normal;

    std::vector<double> m_det;
    std::vector<std::vector<double>> m_CRsf;
    std::vector<std::vector<std::vector<double>>> m_CRgsf;

    void _computeNormal();
    std::vector<double> _computeCRSF(double u, double v);

    //For solver interaction
    int m_nUnknown;

    //Refinement tools
    enum class CHILDTYPE{HALF0, HALF1, HALF2, FRACTAL};
    Element *m_parentElem;
    std::vector<Element*> m_childElem;
    CHILDTYPE m_childType;
    int m_childID;
  };
  
  class Vertex{
    friend class Mesh;
    friend class MeshRefiner;
    
    static std::vector<Vertex*> vertexCollector;
  public:
    static Vertex* create(MVertex *v){Vertex *newV = new Vertex(v); vertexCollector.push_back(newV); return newV;}
    Vertex(MVertex *v): m_isGeometryBoundary(false), m_isGeoNode(false){m_v = v; vertexCollector.push_back(this);}
    ~Vertex(){}

    std::vector<double> getCoord(){std::vector<double> coord{m_v->x(), m_v->y(), m_v->z()}; return coord;};
    std::vector<Edge*> getEdges(){
      if(m_edges.size() != 0)
        return m_edges;
      else{
        std::cout << "edges empty" << std::endl;
        exit(0);
      }
    }
    std::vector<Edge*> getOrientedEdges(){
      if(m_sortedEdges.size() != 0)
        return m_sortedEdges;
      else{
        std::cout << "sortedEdges empty" << std::endl;
        exit(0);
      }
    }

    std::vector<Element*> getElements(){
      if(m_elements.size() != 0)
        return m_elements;
      else{
        std::cout << "elements empty" << std::endl;
        exit(0);
      }
    }
    
    std::vector<Element*> getOrientedElements(){
      if(m_sortedElements.size() != 0)
        return m_sortedElements;
      else{
        std::cout << "sortedElements empty" << std::endl;
        exit(0);
      }
    }

    size_t getIndex(){return m_index;}
    size_t getGmshTag(){return m_v->getNum();}

    bool isGeometryBoundary(){return m_isGeometryBoundary;}
    bool isGeoNode(){return m_isGeoNode;}

    int getLocIndexInElem(Element *e){
      int locIndex = -1;
      std::vector<Vertex*> verts = e->getVertices();
      for(int k=0; k<verts.size(); k++)
        if(verts[k]->getIndex() == getIndex())
          return k;
      std::cout << "Vertex not found in element" << std::endl;
      exit(0);
      return locIndex;
    }
    
  private:
    MVertex *m_v;
    std::vector<Edge*> m_edges;
    std::vector<Element*> m_elements;
    std::vector<Element*> m_lines;
    std::vector<Edge*> m_sortedEdges;
    std::vector<Element*> m_sortedElements;
    std::vector<Vertex*> m_neighbourVertices;
    size_t m_index;
    bool m_isGeometryBoundary;
    bool m_isGeoNode;
    //Cutgraph tools
    Vertex *m_parentVert;
  };
    
  class Edge{
    friend class Mesh;
    friend class MeshRefiner;
    
    static std::vector<Edge*> edgeCollector;
  public:
    static Edge* create(Vertex* v0, Vertex* v1){Edge *newE = new Edge(v0, v1); edgeCollector.push_back(newE); return newE;}
    Edge(Vertex* v0, Vertex* v1):m_isOnCutGraph(false){m_vertices[0] = v0; m_vertices[1] = v1;}
    ~Edge(){}

    double getLength();
    size_t getIndex(){return m_index;}
    Vertex *getVertex(int indV){return m_vertices[indV];}
    std::array<Vertex*, 2> getVertices(){return m_vertices;}
    std::vector<Element*> getElements(){return m_elements;}
    size_t getNumLines(){return m_lines.size();}
    std::vector<Element*> getLines(){return m_lines;}

    int getLocIndexInElem(Element *e){
      int locIndex = -1;
      std::vector<Edge*> edges = e->getEdges();
      for(int k=0; k<edges.size(); k++)
        if(edges[k]->getIndex() == getIndex())
          return k;
      // std::cout << "Edge not found in element" << std::endl;
      // exit(0);
      return locIndex;
    }
    
    std::vector<double> getDir(){
      std::vector<double> v = tools::diff(m_vertices[1]->getCoord(), m_vertices[0]->getCoord());
      tools::normalize(v);
      return v;
    }
    
    std::vector<double> getBarycenter(){
      std::vector<double> res = tools::sum(m_vertices[0]->getCoord(), m_vertices[1]->getCoord());
      tools::scale(res, 0.5);
      return res;
    };
    
  private:
    std::array<Vertex*, 2> m_vertices;
    std::vector<Element*> m_elements;
    std::vector<Element*> m_lines;

    size_t m_index;

    bool m_isOnCutGraph;
  };

  class MeshRefiner;
  
  class Mesh{
    friend class Vertex;
    friend class Edge;
    friend class Element;
    friend class MeshRefiner;
    
  public:
    static std::vector<MVertex*> hangingGmshVerticesCollector;
    static std::vector<MElement*> hangingGmshElementsCollector;

    Mesh(){}
    Mesh(std::vector<MElement*> &elts, std::vector<MLine*> &bndLines, std::vector<MVertex*> &geoNodes);
    Mesh(Mesh &origMesh);
    ~Mesh();

    void minimalCopy(Mesh &origMesh);
    
    Element* getElement(size_t iElem){return m_elements[iElem];}
    std::vector<Element*> getElements(){return m_elements;}
    std::vector<Vertex*> getVertices(){return m_vertices;}
    std::vector<Edge*> getEdges(){return m_edges;}
    std::vector<Element*> getLines(){return m_lines;}
    std::vector<std::vector<Element*>> getLineGroups(){return m_lineGroups;}
    
    double getMinEdgeLength(){return m_minEdgeLenght;}
    double getMaxEdgeLength(){return m_maxEdgeLenght;}
    
    void printInfos(){
      std::cout << "--- --- MESH INFOS ---" << std::endl;
      std::cout << "--- nVertices: " << m_vertices.size() << std::endl;
      std::cout << "--- nLines: " << m_lines.size() << std::endl;
      std::cout << "--- nEdges: " << m_edges.size() << std::endl;
      std::cout << "--- nElements: " << m_elements.size() << std::endl;
      std::cout << "--- hmin: " << m_minEdgeLenght << std::endl;
      std::cout << "--- hmax: " << m_maxEdgeLenght << std::endl;
      std::cout << "--- ---" << std::endl;
    }

  private:
    std::vector<Element*> m_elements;
    std::vector<Element*> m_lines;
    std::vector<Edge*> m_edges;
    std::vector<Vertex*> m_vertices;

    std::vector<std::vector<Element*>> m_lineGroups;
    
    double m_minEdgeLenght;
    double m_maxEdgeLenght;

    void _buildStructure(size_t nMaxEdges);
    void _buildNeighbourElements();
    void _buildLineGroups();
    void _checkSanity();
  };

  class MeshRefiner{
  public:
    MeshRefiner(Mesh *origMesh, Mesh *refinedMesh): m_origMesh(origMesh), m_refinedMesh(refinedMesh){
      // *refinedMesh = *origMesh;
      refinedMesh->minimalCopy(*origMesh);
    }
    ~MeshRefiner(){}

    void refineMesh(const std::vector<size_t> &indicesElemToRefine);
    std::vector<Edge*> getFineCommonEdges(){return m_fineCommonEdges;}
    std::vector<Edge*> getEdgesCLMultiGrille(){return m_edgesElemRefinedUnmodifiedBar;}
    std::vector<Element*> getFineElemRefinedUnmodified(){return m_fineElemRefinedUnmodified;}
    
    Mesh *m_origMesh;
    Mesh *m_refinedMesh;

    std::vector<Element*> m_coarseElemNotRefined;
    std::vector<Element*> m_coarseElemRefined;
    std::vector<Edge*> m_coarseCommonEdges;
    std::vector<Edge*> m_fineCommonEdges;

    std::vector<Edge*> m_edgesElemRefinedUnmodifiedBar;
    std::vector<Edge*> m_edgesElemRefinedUnmodified;
    std::vector<Element*> m_fineElemRefinedUnmodified;
    std::vector<Element*> m_fineElemRefined;

  private:

  };
  
  // To print vectors easily
  template<class T> std::ostream &operator<<(std::ostream &os, std::vector<T> v) {
    os << "["; if (v.size() > 0) os << v[0];
    for(int i = 1; i < v.size(); i++) os << ", " << v[i];
    os << "]";
    return os;
  }
}
