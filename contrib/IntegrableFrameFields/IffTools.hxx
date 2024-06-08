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
    std::vector<double> getProjectionOnDirection(const std::vector<double> &dirProj, const std::vector<double> &v);
    std::vector<double> getProjectionOnHyperPlan(const std::vector<double> &normalHyperPlan, const std::vector<double> &v);
  }

  class Vertex;
  class Edge;
  class Mesh;
  
  class Element{
    friend class Mesh;
    static std::vector<Element*> elementCollector;
    static std::vector<double> integrationWeights;
    static std::vector<std::vector<double>> integrationPoints;
  public:
    static Element* create(Mesh *m, MElement* el){Element *newE = new Element(m, el); elementCollector.push_back(newE); return newE;}
    Element(Mesh *m, MElement* el);
    ~Element(){}

    size_t getNumEdges(){return m_edges.size();}
    std::vector<double> getNormal();
    std::vector<double> getDirEdg(int iEdg);

    Edge* getEdge(int k){return m_edges[k];}
    std::vector<Edge*> getEdges(){return m_edges;}
    
    std::vector<double> getDet(int pOrder);
    std::vector<std::vector<double>> getIntegrationPoints(int pOrder);
    std::vector<double> getIntegrationWeights(int pOrder);
    std::vector<std::vector<double>> getCRSF(int pOrder);
    std::vector<std::vector<std::vector<double>>> getCRGradSF(int pOrder);
    std::vector<double> interpolateCR(double u, double v, const std::vector<std::vector<double>> &solTri);

    MElement *m_e;

    //For solver interaction
    void setNumUnknown(int n){m_nUnknown = n;}
    int getNumUnknown(){return m_nUnknown;}


  private:
    std::vector<Vertex *> m_vertices;
    std::vector<Edge *> m_edges;

    std::vector<double> m_normal;

    std::vector<double> m_det;
    std::vector<std::vector<double>> m_CRsf;
    std::vector<std::vector<std::vector<double>>> m_CRgsf;

    void _computeNormal();
    std::vector<double> _computeCRSF(double u, double v);

    //For solver interaction
    int m_nUnknown;
  };
  
  class Vertex{
    friend class Mesh;
    static std::vector<Vertex*> vertexCollector;
  public:
    static Vertex* create(MVertex *v){Vertex *newV = new Vertex(v); vertexCollector.push_back(newV); return newV;}
    Vertex(MVertex *v){m_v = v; vertexCollector.push_back(this);}
    ~Vertex(){}

    std::vector<double> getCoord(){std::vector<double> coord{m_v->x(), m_v->y(), m_v->z()}; return coord;};
  private:
    MVertex *m_v;
    std::vector<Edge*> m_edges;
    std::vector<Vertex*> m_neighbourVertices;
    size_t m_index;
  };
    
  class Edge{
    friend class Mesh;
    static std::vector<Edge*> edgeCollector;
  public:
    static Edge* create(Vertex* v0, Vertex* v1){Edge *newE = new Edge(v0, v1); edgeCollector.push_back(newE); return newE;}
    Edge(Vertex* v0, Vertex* v1):m_isOnCutGraph(false){m_vertices[0] = v0; m_vertices[1] = v1;}
    ~Edge(){}

    double getLength();
    size_t getIndex(){return m_index;}
    std::vector<double> getDir(){
      std::vector<double> v = tools::diff(m_vertices[0]->getCoord(), m_vertices[1]->getCoord());
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

  class Mesh{
    friend class Vertex;
    friend class Edge;
    friend class Element;
  public:
    Mesh(std::vector<MElement*> &elts, std::vector<MLine*> &bndLines);
    ~Mesh();

    Element* getElement(size_t iElem){return m_elements[iElem];}
    std::vector<Element*> getElements(){return m_elements;}
    std::vector<Vertex*> getVertices(){return m_vertices;}
    std::vector<Edge*> getEdges(){return m_edges;}
    std::vector<Element*> getLines(){return m_lines;}
    
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

    double m_minEdgeLenght;
    double m_maxEdgeLenght;
  };
}
