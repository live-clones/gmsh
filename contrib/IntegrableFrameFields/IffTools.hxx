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
    double norm(const std::vector<double> &v);
    double norm2(const std::vector<double> &v); // squared norm
    double norm(const double *v, const size_t &size);
    double distance(const std::vector<double> &v0, const std::vector<double> &v1);
  }

  class Vertex;
  class Edge;
  class Mesh;
  
  class Element{
    friend class Mesh;
    static std::vector<Element*> elementCollector;
  public:
    static Element* create(Mesh *m, MElement* el){Element *newE = new Element(m, el); elementCollector.push_back(newE); return newE;}
    Element(Mesh *m, MElement* el){
      m_e = el;
      std::vector<MVertex *> vert;
      el->getVertices(vert);
      m_vertices.reserve(vert.size());
      for(MVertex *v: vert)
        m_vertices.push_back(m_vertices[v->getIndex()]);
    }
    ~Element(){}
    
  private:
    MElement *m_e;
    std::vector<Vertex *> m_vertices;
    std::vector<Edge *> m_edges;
  };
  
  class Vertex{
    friend class Mesh;
    static std::vector<Vertex*> vertexCollector;
  public:
    static Vertex* create(MVertex *v){Vertex *newV = new Vertex(v); vertexCollector.push_back(newV); return newV;}
    Vertex(MVertex *v){m_v = v; vertexCollector.push_back(this);}
    ~Vertex(){}

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

  private:
    std::array<Vertex*, 2> m_vertices;
    std::vector<Element*> m_elements;
    std::vector<Element*> m_lines;

    bool m_isOnCutGraph;
  };

  class Mesh{
    friend class Vertex;
    friend class Edge;
    friend class Element;
  public:
    Mesh(std::vector<MElement*> &elts, std::vector<MLine*> &bndLines);
    ~Mesh();

  private:
    std::vector<Element*> m_elements;
    std::vector<Element*> m_lines;
    std::vector<Edge*> m_edges;
    std::vector<Vertex*> m_vertices;
  };
}
