#include <IffTools.hxx>
#include <iostream>

namespace IFF{
  namespace tools{
    void normalize(std::vector<double> &v){
      double norm = 0.0;
      for(size_t k=0; k<v.size(); k++)
        norm += v[k]*v[k];
      norm = sqrt(norm);
      if(norm > 1e-12){
        for(size_t k=0; k<v.size(); k++)
          v[k] /= norm;
      }
    }

    void scale(std::vector<double> &v, double scaling){
      for(size_t k=0; k<v.size(); k++)
        v[k] *= scaling;
    }
  
    std::vector<double> getNormalizedVector(const std::vector<double> &v){
      std::vector<double> vCopy = v;
      normalize(vCopy);
      return vCopy;
    }

    std::vector<double> crossprod(const std::vector<double> &v0, const std::vector<double> &v1){
      std::vector<double> res{0.0, 0.0, 0.0};
      if(v0.size() == 3 && v1.size() == 3){
        res[0] = v0[1]*v1[2] - v0[2]*v1[1];
        res[1] = v0[2]*v1[0] - v0[0]*v1[2];
        res[2] = v0[0]*v1[1] - v0[1]*v1[0];
      }
      else{
        std::cout << "TOOLS: Wrong use of crossprod" << std::endl;
        exit(0);
      }
      return res;
    }

    double dotprod(const std::vector<double> &v0, const std::vector<double> &v1){
      double val = 0.0;
      for(size_t k=0; k<v0.size(); k++)
        val += v1[k]*v0[k];
      return val;
    }

    double cosAngle(const std::vector<double> &v0, const std::vector<double> &v1){
      return dotprod(v0, v1) / norm(v0) / norm(v1);
    }

    double norm(const std::vector<double> &v){
      double norm = 0.0;
      for(size_t k=0; k<v.size(); k++)
        norm += v[k]*v[k];
      norm = sqrt(norm);
      return norm;
    }

    double norm2(const std::vector<double> &v) {
      double norm = 0.0;
      for(size_t k=0; k<v.size(); k++)
        norm += v[k]*v[k];
      return norm;
    }

    double norm(const double *v, const size_t &size){
      double norm = 0.0;
      for(size_t k=0; k<size; k++)
        norm += v[k]*v[k];
      norm = sqrt(norm);
      return norm;
    }

    double distance(const std::vector<double> &v0, const std::vector<double> &v1){
      std::vector<double> diff;
      diff.resize(v0.size(), 0.0);
      for(size_t k=0; k<v0.size(); k++)
        diff[k] = v1[k] - v0[k];
      return norm(diff);
    }
  }

  std::vector<Vertex*> Vertex::vertexCollector;
  std::vector<Element*> Element::elementCollector;
  std::vector<Edge*> Edge::edgeCollector;

  Mesh::Mesh(std::vector<MElement*> &elts, std::vector<MLine*> &bndLines){
    //Number vertices and Build vertices vector
    size_t nMaxVert = 0;
    size_t nMaxEdges = 0;
    for(MElement* e: elts){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      nMaxVert += verts.size();
      for(MVertex *v: verts)
        v->setIndex(-1);
      nMaxEdges += e->getNumEdges();
    }
    for(MLine* e: bndLines){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      nMaxVert += verts.size();
      for(MVertex *v: verts)
        v->setIndex(-1);
      nMaxEdges += e->getNumEdges();
    }
    
    m_vertices.reserve(nMaxVert);
    size_t cptVert=0;
    for(MElement* e: elts){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      for(MVertex *v: verts)
        if(v->getIndex() == -1){
          v->setIndex(cptVert);
          cptVert++;
          Vertex *myV = Vertex::create(v);
          m_vertices.push_back(myV);
          myV->m_index = v->getIndex();
        }
    }
    for(MLine* e: bndLines){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      for(MVertex *v: verts)
        if(v->getIndex() == -1){
          v->setIndex(cptVert);
          cptVert++;
          Vertex *myV = Vertex::create(v);
          m_vertices.push_back(myV);
          myV->m_index = v->getIndex();
        }
    }
    m_vertices.shrink_to_fit();
    //Build Elements vector
    m_elements.reserve(elts.size());
    for(MElement* e: elts){
      Element *myE = Element::create(this, e);
      m_elements.push_back(myE);
    }
    //Build Line vector
    m_lines.reserve(bndLines.size());
    for(MLine* l: bndLines){
      Element *myE = Element::create(this, l);
      m_lines.push_back(myE);
    }    
    //Build Edges vector
    std::vector<std::pair<std::array<size_t, 2>, Element*>> edgesList;
    edgesList.reserve(nMaxEdges);
    for(Element* e: m_elements){
      size_t nEdges = e->m_e->getNumEdges();
      for(size_t k=0; k<nEdges; k++){
        std::array<size_t, 2> vNum;
        if(e->m_vertices[k]->m_index < e->m_vertices[(k+1)%nEdges]->m_index){
          vNum[0] = e->m_vertices[k]->m_index;
          vNum[1] = e->m_vertices[(k+1)%nEdges]->m_index;
        }
        else{
          vNum[0] = e->m_vertices[(k+1)%nEdges]->m_index;
          vNum[1] = e->m_vertices[k]->m_index;
        }
        edgesList.push_back(std::make_pair(vNum, e));
      }
    }
    for(Element* e: m_lines){
      size_t nEdges = e->m_e->getNumEdges();
      for(size_t k=0; k<nEdges; k++){
        std::array<size_t, 2> vNum;
        if(e->m_vertices[k]->m_index < e->m_vertices[(k+1)%nEdges]->m_index){
          vNum[0] = e->m_vertices[k]->m_index;
          vNum[1] = e->m_vertices[(k+1)%nEdges]->m_index;
        }
        else{
          vNum[0] = e->m_vertices[(k+1)%nEdges]->m_index;
          vNum[1] = e->m_vertices[k]->m_index;
        }
        edgesList.push_back(std::make_pair(vNum, e));
      }
    }

    std::sort(edgesList.begin(), edgesList.end(), [&](std::pair<std::array<size_t, 2>, Element*> i1, std::pair<std::array<size_t, 2>, Element*> i2){
      if(i1.first[0] == i2.first[0])
        return i1.first[1] < i2.first[1];
      else
        return i1.first[0] < i2.first[0];});

    m_edges.reserve(nMaxEdges);
    std::array<size_t, 2> edgPrec;
    edgPrec[0] = -1;
    Edge *edgK = NULL;
    for(const std::pair<std::array<size_t, 2>, Element*> &pair: edgesList){
      if(edgPrec != pair.first){
        edgK = Edge::create(m_vertices[pair.first[0]], m_vertices[pair.first[1]]);
        m_edges.push_back(edgK);
        edgK->m_vertices[0] = m_vertices[pair.first[0]];
        edgK->m_vertices[1] = m_vertices[pair.first[1]];
        edgPrec = pair.first;
      }
      if(pair.second->m_e->getNumEdges() == 1)
        edgK->m_lines.push_back(pair.second);
      else
        edgK->m_elements.push_back(pair.second);
      pair.second->m_edges.push_back(edgK);
    }
    m_edges.shrink_to_fit();

    //Sort m_edges for elements
    for(Element *e: m_elements){
      std::vector<Edge *> sortedEdges;
      sortedEdges.reserve(e->m_edges.size());
      for(size_t k=0; k<e->m_edges.size(); k++){
        for(size_t l=0; l<e->m_edges.size(); l++){
          if((e->m_vertices[k]->m_index == e->m_edges[l]->m_vertices[0]->m_index) || (e->m_vertices[k]->m_index == e->m_edges[l]->m_vertices[1]->m_index))
            if((e->m_vertices[(k+1)%m_edges.size()]->m_index == e->m_edges[l]->m_vertices[0]->m_index) || (e->m_vertices[(k+1)%m_edges.size()]->m_index == e->m_edges[l]->m_vertices[1]->m_index)){
              sortedEdges[k] = e->m_edges[l];
              break;
            }
        }
      }
      e->m_edges = sortedEdges;
    }
  }
  Mesh::~Mesh(){

  }
}
