// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Anthony Royer.

#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <limits>
#include <stack>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "ElementType.h"

struct OriGEntityPtrFullLessThan {
  bool operator()(const std::pair<int, GEntity *> &p1,
                  const std::pair<int, GEntity *> &p2) const
  {
    if(p1.first != p2.first) return p1.first < p2.first;
    if(p1.second->dim() != p2.second->dim())
      return p1.second->dim() < p2.second->dim();
    return p1.second->tag() < p2.second->tag();
  }
};

typedef std::set<std::pair<int, GEntity *>, OriGEntityPtrFullLessThan>
  setorientity;

#define hashmap std::unordered_map
#define hashmapentity                                                          \
  std::unordered_map<GEntity *, setorientity, GEntityPtrFullHash,              \
                     GEntityPtrFullEqual>
#define hashmapelement                                                         \
  std::unordered_map<MElement *, GEntity *, MElementPtrHash, MElementPtrEqual>
#define hashmapelementpart                                                     \
  std::unordered_map<MElement *, int, MElementPtrHash, MElementPtrEqual>
#define hashmapface                                                            \
  std::unordered_map<MFace,                                                    \
                     std::vector<std::pair<MElement *, std::vector<int> > >,   \
                     MFaceHash, MFaceEqual>
#define hashmapedge                                                            \
  std::unordered_map<MEdge,                                                    \
                     std::vector<std::pair<MElement *, std::vector<int> > >,   \
                     MEdgeHash, MEdgeEqual>
#define hashmapvertex                                                          \
  std::unordered_map<MVertex *,                                                \
                     std::vector<std::pair<MElement *, std::vector<int> > >,   \
                     MVertexPtrHash, MVertexPtrEqual>

#if defined(HAVE_METIS)

#include "OS.h"
#include "Context.h"
#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"
#include "ghostRegion.h"
#include "ghostFace.h"
#include "ghostEdge.h"
#include "MFaceHash.h"
#include "MEdgeHash.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MElementCut.h"
#include "MPoint.h"

extern "C" {
#include <metis.h>
}

// Graph of the mesh for partitioning purposes.
class Graph {
private:
  // The GModel
  GModel *_model;
  // The number of partitions
  std::size_t _nparts;
  // The number of elements
  std::size_t _ne;
  // The number of nodes
  std::size_t _nn;
  // The dimension of the mesh
  int _dim;
  // The list of nodes belonging to the ith element of the mesh are stored in
  // consecutive locations of eind starting at position eptr[i] up to (but not
  // including) position eptr[i+1]. The size of the eind array is of size equal
  // to the sum of the number of nodes in all the elements of the mesh.
  std::vector<idx_t> _eind;
  // The size of the eptr array is n + 1, where n is the number of elements in
  // the mesh.
  std::vector<idx_t> _eptr;
  // The metis graph structure
  idx_t *_xadj, *_adjncy;
  // The weight associated to each elements of eptr
  idx_t *_vwgt;
  // Element corresponding to each graph element in eptr
  std::vector<MElement *> _element;
  // Vertex corresponding to each graph vertex in eptr
  std::vector<idx_t> _vertex;
  // The partitions output from the partitioner, in an integer type independent
  // from METIS
  std::vector<int> _partition;

public:
  Graph(GModel *model)
    : _model(model), _nparts(0), _ne(0), _nn(0), _dim(0), _xadj(nullptr),
      _adjncy(nullptr), _vwgt(nullptr)
  {
  }
  ~Graph() { clear(); }
  std::size_t nparts() const { return _nparts; };
  std::size_t ne() const { return _ne; };
  std::size_t nn() const { return _nn; };
  int dim() const { return _dim; };
  std::size_t eind(std::size_t i) const { return _eind[i]; };
  std::size_t eptr(std::size_t i) const { return _eptr[i]; };
  idx_t xadj(std::size_t i) const { return _xadj[i]; };
  idx_t *xadj() const { return _xadj; };
  idx_t adjncy(std::size_t i) const { return _adjncy[i]; };
  idx_t *adjncy() const { return _adjncy; };
  idx_t *vwgt() const { return _vwgt; };
  MElement *element(std::size_t i) const { return _element[i]; };
  idx_t vertex(std::size_t i) const { return _vertex[i]; };
  int partition(std::size_t i) const { return _partition[i]; };
  std::size_t numNodes() const { return _ne; };
  std::size_t numEdges() const { return _xadj[_ne] / 2; };
  void nparts(std::size_t nparts) { _nparts = nparts; };
  void ne(std::size_t ne) { _ne = ne; };
  void nn(std::size_t nn) { _nn = nn; };
  void dim(int dim) { _dim = dim; };
  void eindResize(std::size_t size)
  {
    _eind.clear();
    _eind.resize(size, 0);
  }
  void eind(std::size_t i, idx_t eind) { _eind[i] = eind; };
  void eptrResize(std::size_t size)
  {
    _eptr.clear();
    _eptr.resize(size, 0);
  }
  void eptr(std::size_t i, idx_t eptr) { _eptr[i] = eptr; };
  void elementResize(std::size_t size)
  {
    _element.clear();
    _element.resize(size, nullptr);
  }
  void element(std::size_t i, MElement *element) { _element[i] = element; };
  void vertexResize(std::size_t size)
  {
    _vertex.clear();
    _vertex.resize(size, -1);
  }
  void adjncy(std::size_t i, idx_t adjncy) { _adjncy[i] = adjncy; };
  void vertex(std::size_t i, idx_t vertex) { _vertex[i] = vertex; };
  void partition(const std::vector<idx_t> &epart)
  {
    // converts into METIS-independent integer type
    _partition.resize(epart.size());
    for(std::size_t i = 0; i < epart.size(); i++) _partition[i] = epart[i];
  };
  void clear()
  {
    if(_xadj) {
      delete[] _xadj;
      _xadj = nullptr;
    }
    if(_adjncy) {
      delete[] _adjncy;
      _adjncy = nullptr;
    }
    if(_vwgt) {
      delete[] _vwgt;
      _vwgt = nullptr;
    }
  }
  void clearDualGraph()
  {
    if(_xadj) {
      delete[] _xadj;
      _xadj = nullptr;
    }
    if(_adjncy) {
      delete[] _adjncy;
      _adjncy = nullptr;
    }
  }
  void eraseVertex()
  {
    for(std::size_t i = 0; i < _vertex.size(); i++) _vertex[i] = -1;
  }
  std::vector<std::set<MElement *, MElementPtrLessThan> >
  getBoundaryElements(idx_t size = 0)
  {
    std::vector<std::set<MElement *, MElementPtrLessThan> > elements(
      (size ? size : _nparts), std::set<MElement *, MElementPtrLessThan>());
    for(std::size_t i = 0; i < _ne; i++) {
      for(idx_t j = _xadj[i]; j < _xadj[i + 1]; j++) {
        if(_partition[i] != _partition[_adjncy[j]]) {
          if(_element[i]->getDim() == _dim) {
            elements[_partition[i]].insert(_element[i]);
          }
        }
      }
    }

    return elements;
  }
  void assignGhostCells()
  {
    std::vector<GEntity *> ghostEntities(_nparts, (GEntity *)nullptr);
    int elementaryNumber = _model->getMaxElementaryNumber(_dim);
    for(std::size_t i = 1; i <= _nparts; i++) {
      switch(_dim) {
      case 1:
        ghostEntities[i - 1] = new ghostEdge(_model, ++elementaryNumber, i);
        _model->add(static_cast<ghostEdge *>(ghostEntities[i - 1]));
        break;
      case 2:
        ghostEntities[i - 1] = new ghostFace(_model, ++elementaryNumber, i);
        _model->add(static_cast<ghostFace *>(ghostEntities[i - 1]));
        break;
      case 3:
        ghostEntities[i - 1] = new ghostRegion(_model, ++elementaryNumber, i);
        _model->add(static_cast<ghostRegion *>(ghostEntities[i - 1]));
        break;
      default: break;
      }
    }
    for(std::size_t i = 0; i < _ne; i++) {
      std::set<int> ghostCellsPartition;
      for(idx_t j = _xadj[i]; j < _xadj[i + 1]; j++) {
        if(_partition[i] != _partition[_adjncy[j]] &&
           ghostCellsPartition.find(_partition[_adjncy[j]]) ==
             ghostCellsPartition.end()) {
          if(_element[i]->getDim() == _dim) {
            switch(_dim) {
            case 1:
              static_cast<ghostEdge *>(ghostEntities[_partition[_adjncy[j]]])
                ->addElement(_element[i]->getType(), _element[i],
                             _partition[i] + 1);
              break;
            case 2:
              static_cast<ghostFace *>(ghostEntities[_partition[_adjncy[j]]])
                ->addElement(_element[i]->getType(), _element[i],
                             _partition[i] + 1);
              break;
            case 3:
              static_cast<ghostRegion *>(ghostEntities[_partition[_adjncy[j]]])
                ->addElement(_element[i]->getType(), _element[i],
                             _partition[i] + 1);
              break;
            default: break;
            }
            ghostCellsPartition.insert(_partition[_adjncy[j]]);
          }
        }
      }
    }
  }
  void createDualGraph(bool connectedAll)
  {
    std::vector<idx_t> nptr(_nn + 1, 0);
    std::vector<idx_t> nind(_eptr[_ne], 0);

    for(std::size_t i = 0; i < _ne; i++) {
      for(idx_t j = _eptr[i]; j < _eptr[i + 1]; j++) { nptr[_eind[j]]++; }
    }

    for(std::size_t i = 1; i < _nn; i++) nptr[i] += nptr[i - 1];
    for(std::size_t i = _nn; i > 0; i--) nptr[i] = nptr[i - 1];
    nptr[0] = 0;

    for(std::size_t i = 0; i < _ne; i++) {
      for(idx_t j = _eptr[i]; j < _eptr[i + 1]; j++) {
        nind[nptr[_eind[j]]++] = i;
      }
    }

    for(std::size_t i = _nn; i > 0; i--) nptr[i] = nptr[i - 1];
    nptr[0] = 0;

    _xadj = new idx_t[_ne + 1];
    for(std::size_t i = 0; i < _ne + 1; i++) _xadj[i] = 0;

    std::vector<idx_t> nbrs(_ne, 0);
    std::vector<idx_t> marker(_ne, 0);
    for(std::size_t i = 0; i < _ne; i++) {
      std::size_t l = 0;
      for(idx_t j = _eptr[i]; j < _eptr[i + 1]; j++) {
        for(idx_t k = nptr[_eind[j]]; k < nptr[_eind[j] + 1]; k++) {
          if(nind[k] != (idx_t)i) {
            if(marker[nind[k]] == 0) nbrs[l++] = nind[k];
            marker[nind[k]]++;
          }
        }
      }

      std::size_t nbrsNeighbors = 0;
      for(std::size_t j = 0; j < l; j++) {
        if(marker[nbrs[j]] >=
           (connectedAll ?
              1 :
              _element[i]->numCommonNodesInDualGraph(_element[nbrs[j]])))
          nbrsNeighbors++;
        marker[nbrs[j]] = 0;
        nbrs[j] = 0;
      }

      _xadj[i] = nbrsNeighbors;
    }

    for(std::size_t i = 1; i < _ne; i++) _xadj[i] = _xadj[i] + _xadj[i - 1];
    for(std::size_t i = _ne; i > 0; i--) _xadj[i] = _xadj[i - 1];
    _xadj[0] = 0;

    _adjncy = new idx_t[_xadj[_ne]];
    for(idx_t i = 0; i < _xadj[_ne]; i++) _adjncy[i] = 0;

    for(std::size_t i = 0; i < _ne; i++) {
      std::size_t l = 0;
      for(idx_t j = _eptr[i]; j < _eptr[i + 1]; j++) {
        for(idx_t k = nptr[_eind[j]]; k < nptr[_eind[j] + 1]; k++) {
          if(nind[k] != (idx_t)i) {
            if(marker[nind[k]] == 0) nbrs[l++] = nind[k];
            marker[nind[k]]++;
          }
        }
      }

      for(std::size_t j = 0; j < l; j++) {
        if(marker[nbrs[j]] >=
           (connectedAll ?
              1 :
              _element[i]->numCommonNodesInDualGraph(_element[nbrs[j]]))) {
          _adjncy[_xadj[i]] = nbrs[j];
          _xadj[i] = _xadj[i] + 1;
        }
        marker[nbrs[j]] = 0;
        nbrs[j] = 0;
      }
    }
    for(std::size_t i = _ne; i > 0; i--) _xadj[i] = _xadj[i - 1];
    _xadj[0] = 0;
  }
  void fillDefaultWeights()
  {
    if(CTX::instance()->mesh.partitionLinWeight == 1 &&
       CTX::instance()->mesh.partitionTriWeight == 1 &&
       CTX::instance()->mesh.partitionQuaWeight == 1 &&
       CTX::instance()->mesh.partitionTetWeight == 1 &&
       CTX::instance()->mesh.partitionPyrWeight == 1 &&
       CTX::instance()->mesh.partitionPriWeight == 1 &&
       CTX::instance()->mesh.partitionHexWeight == 1)
      return;

    _vwgt = new idx_t[_ne];
    if(CTX::instance()->mesh.partitionLinWeight == -1 ||
       CTX::instance()->mesh.partitionTriWeight == -1 ||
       CTX::instance()->mesh.partitionQuaWeight == -1 ||
       CTX::instance()->mesh.partitionTetWeight == -1 ||
       CTX::instance()->mesh.partitionPyrWeight == -1 ||
       CTX::instance()->mesh.partitionPriWeight == -1 ||
       CTX::instance()->mesh.partitionHexWeight == -1) {
      for(std::size_t i = 0; i < _ne; i++) {
        if(!_element[i]) { _vwgt[i] = 1; }
        else {
          _vwgt[i] = (_element[i]->getDim() == _dim ? 1 : 0);
        }
      }
    }
    else {
      for(std::size_t i = 0; i < _ne; i++) {
        if(!_element[i]) { _vwgt[i] = 1; }
        else {
          switch(_element[i]->getType()) {
          case TYPE_LIN:
            _vwgt[i] = CTX::instance()->mesh.partitionLinWeight;
            break;
          case TYPE_TRI:
            _vwgt[i] = CTX::instance()->mesh.partitionTriWeight;
            break;
          case TYPE_QUA:
            _vwgt[i] = CTX::instance()->mesh.partitionQuaWeight;
            break;
          case TYPE_TET:
            _vwgt[i] = CTX::instance()->mesh.partitionTetWeight;
            break;
          case TYPE_PYR:
            _vwgt[i] = CTX::instance()->mesh.partitionPyrWeight;
            break;
          case TYPE_PRI:
            _vwgt[i] = CTX::instance()->mesh.partitionPriWeight;
            break;
          case TYPE_HEX:
            _vwgt[i] = CTX::instance()->mesh.partitionHexWeight;
            break;
          default: _vwgt[i] = 1; break;
          }
        }
      }
    }
  }
};

template <class ITERATOR>
static void fillElementsToNodesMap(Graph &graph, GEntity *entity,
                                   idx_t &eptrIndex, idx_t &eindIndex,
                                   idx_t &numVertex, ITERATOR it_beg,
                                   ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    const std::size_t numVertices = (*it)->getNumPrimaryVertices();
    graph.element(eptrIndex++, *it);
    graph.eptr(eptrIndex, graph.eptr(eptrIndex - 1) + numVertices);
    for(std::size_t i = 0; i < numVertices; i++) {
      if(graph.vertex((*it)->getVertex(i)->getNum() - 1) == -1) {
        graph.vertex((*it)->getVertex(i)->getNum() - 1, numVertex++);
      }
      graph.eind(eindIndex, graph.vertex((*it)->getVertex(i)->getNum() - 1));
      eindIndex++;
    }
  }
}

static std::size_t getSizeOfEind(GModel *model)
{
  std::size_t size = 0;
  // Loop over volumes
  for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    size += 4 * (*it)->tetrahedra.size();
    size += 8 * (*it)->hexahedra.size();
    size += 6 * (*it)->prisms.size();
    size += 5 * (*it)->pyramids.size();
    size += 4 * (*it)->trihedra.size();
  }

  // Loop over surfaces
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    size += 3 * (*it)->triangles.size();
    size += 4 * (*it)->quadrangles.size();
  }

  // Loop over curves
  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    size += 2 * (*it)->lines.size();
  }

  // Loop over points
  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    size += 1 * (*it)->points.size();
  }

  return size;
}

// Creates a mesh data structure used by Metis routines. Returns: 0 = success, 1
// = no elements found, 2 = error.
static int makeGraph(GModel *model, Graph &graph, int selectDim)
{
  std::size_t eindSize = 0;
  if(selectDim < 0) {
    graph.ne(model->getNumMeshElements());
    graph.nn(model->getNumMeshVertices());
    graph.dim(model->getMeshDim());
    graph.elementResize(graph.ne());
    graph.vertexResize(model->getMaxVertexNumber());
    graph.eptrResize(graph.ne() + 1);
    graph.eptr(0, 0);
    eindSize = getSizeOfEind(model);
    graph.eindResize(eindSize);
  }
  else {
    GModel *tmp = new GModel();
    std::vector<GEntity *> entities;
    model->getEntities(entities);

    std::set<MVertex *> vertices;
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(entities[i]->dim() == selectDim) {
        switch(entities[i]->dim()) {
        case 3: tmp->add(static_cast<GRegion *>(entities[i])); break;
        case 2: tmp->add(static_cast<GFace *>(entities[i])); break;
        case 1: tmp->add(static_cast<GEdge *>(entities[i])); break;
        case 0: tmp->add(static_cast<GVertex *>(entities[i])); break;
        default: break;
        }
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          for(std::size_t k = 0;
              k < entities[i]->getMeshElement(j)->getNumVertices(); k++) {
            vertices.insert(entities[i]->getMeshElement(j)->getVertex(k));
          }
        }
      }
    }

    graph.ne(tmp->getNumMeshElements());
    graph.nn(vertices.size());
    graph.dim(tmp->getMeshDim());
    graph.elementResize(graph.ne());
    graph.vertexResize(model->getMaxVertexNumber());
    graph.eptrResize(graph.ne() + 1);
    graph.eptr(0, 0);
    eindSize = getSizeOfEind(tmp);
    graph.eindResize(eindSize);

    tmp->remove();
    delete tmp;
  }

  idx_t eptrIndex = 0;
  idx_t eindIndex = 0;
  idx_t numVertex = 0;

  if(graph.ne() == 0) {
    Msg::Error("No mesh elements were found");
    return 1;
  }
  if(graph.dim() == 0) {
    Msg::Error("Cannot partition a point");
    return 1;
  }

  // Loop over volumes
  if(selectDim < 0 || selectDim == 3) {
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      GRegion *r = *it;
      fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex,
                             r->tetrahedra.begin(), r->tetrahedra.end());
      fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex,
                             r->hexahedra.begin(), r->hexahedra.end());
      fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex,
                             r->prisms.begin(), r->prisms.end());
      fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex,
                             r->pyramids.begin(), r->pyramids.end());
      fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex,
                             r->trihedra.begin(), r->trihedra.end());
    }
  }

  // Loop over surfaces
  if(selectDim < 0 || selectDim == 2) {
    for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
      GFace *f = *it;
      fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex,
                             f->triangles.begin(), f->triangles.end());
      fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex,
                             f->quadrangles.begin(), f->quadrangles.end());
    }
  }

  // Loop over curves
  if(selectDim < 0 || selectDim == 1) {
    for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
      GEdge *e = *it;
      fillElementsToNodesMap(graph, e, eptrIndex, eindIndex, numVertex,
                             e->lines.begin(), e->lines.end());
    }
  }

  // Loop over points
  if(selectDim < 0 || selectDim == 0) {
    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      GVertex *v = *it;
      fillElementsToNodesMap(graph, v, eptrIndex, eindIndex, numVertex,
                             v->points.begin(), v->points.end());
    }
  }

  return 0;
}

// Partition a graph created by makeGraph using Metis library. Returns: 0 =
// success, 1 = error, 2 = exception thrown.
static int partitionGraph(Graph &graph, bool verbose)
{
#ifdef HAVE_METIS
  std::stringstream opt;
  try {
    idx_t metisOptions[METIS_NOPTIONS];
    METIS_SetDefaultOptions(metisOptions);

    opt << 8 * sizeof(idx_t) << " bit indices";

    opt << ", ptype:";
    switch(CTX::instance()->mesh.metisAlgorithm) {
    case 1: // Recursive
      metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_RB;
      opt << "rb";
      break;
    case 2: // K-way
      metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_KWAY;
      opt << "kway";
      break;
    default: opt << "default"; break;
    }

    opt << ", ufactor:";
    if(CTX::instance()->mesh.metisMaxLoadImbalance >= 0) {
      metisOptions[METIS_OPTION_UFACTOR] =
        CTX::instance()->mesh.metisMaxLoadImbalance;
      opt << CTX::instance()->mesh.metisMaxLoadImbalance;
    }
    else {
      opt << "default";
    }

    opt << ", ctype:";
    switch(CTX::instance()->mesh.metisEdgeMatching) {
    case 1: // Random matching
      metisOptions[METIS_OPTION_CTYPE] = METIS_CTYPE_RM;
      opt << "rm";
      break;
    case 2: // Sorted heavy-edge matching
      metisOptions[METIS_OPTION_CTYPE] = METIS_CTYPE_SHEM;
      opt << "shem";
      break;
    default: opt << "default"; break;
    }

    opt << ", rtype:";
    switch(CTX::instance()->mesh.metisRefinementAlgorithm) {
    case 1: // FM-based cut refinement
      metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_FM;
      opt << "fm";
      break;
    case 2: // Greedy boundary refinement
      metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_GREEDY;
      opt << "greedy";
      break;
    case 3: // Two-sided node FM refinement
      metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_SEP2SIDED;
      opt << "sep2sided";
      break;
    case 4: // One-sided node FM refinement
      metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_SEP1SIDED;
      opt << "sep1sided";
      break;
    default: opt << "default"; break;
    }

    opt << ", objtype:";
    switch(CTX::instance()->mesh.metisObjective) {
    case 1: // Min. cut
      metisOptions[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_CUT;
      opt << "cut";
      break;
    case 2: // Min. communication volume (slower)
      metisOptions[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_VOL;
      opt << "vol";
      break;
    default: opt << "default"; break;
    }

    opt << ", minconn:";
    switch(CTX::instance()->mesh.metisMinConn) {
    case 0:
      metisOptions[METIS_OPTION_MINCONN] = 0;
      opt << 0;
      break;
    case 1:
      metisOptions[METIS_OPTION_MINCONN] = 1;
      opt << 1;
      break;
    default: opt << "default"; break;
    }

    if(verbose) Msg::Info("Running METIS with %s", opt.str().c_str());

    // C numbering
    metisOptions[METIS_OPTION_NUMBERING] = 0;

    idx_t objval;
    std::vector<idx_t> epart(graph.ne());
    idx_t ne = graph.ne();
    idx_t numPart = graph.nparts();
    idx_t ncon = 1;
    graph.fillDefaultWeights();

    int metisError = 0;
    graph.createDualGraph(false);

    if(metisOptions[METIS_OPTION_PTYPE] == METIS_PTYPE_KWAY) {
      metisError = METIS_PartGraphKway(
        &ne, &ncon, graph.xadj(), graph.adjncy(), graph.vwgt(), nullptr,
        nullptr, &numPart, nullptr, nullptr, metisOptions, &objval, &epart[0]);
    }
    else {
      metisError = METIS_PartGraphRecursive(
        &ne, &ncon, graph.xadj(), graph.adjncy(), graph.vwgt(), nullptr,
        nullptr, &numPart, nullptr, nullptr, metisOptions, &objval, &epart[0]);
    }

    switch(metisError) {
    case METIS_OK: break;
    case METIS_ERROR_INPUT: Msg::Error("METIS input error"); return 1;
    case METIS_ERROR_MEMORY: Msg::Error("METIS memory error"); return 1;
    case METIS_ERROR:
    default: Msg::Error("METIS error"); return 1;
    }

    // Check and correct the topology
    for(int i = 1; i < 4; i++) {
      for(std::size_t j = 0; j < graph.ne(); j++) {
        if(graph.element(j)->getDim() == graph.dim()) continue;

        for(idx_t k = graph.xadj(j); k < graph.xadj(j + 1); k++) {
          if(graph.element(j)->getDim() ==
             graph.element(graph.adjncy(k))->getDim() - i) {
            if(epart[j] != epart[graph.adjncy(k)]) {
              epart[j] = epart[graph.adjncy(k)];
              break;
            }
          }
        }
      }
    }
    graph.partition(epart);
    if(verbose) Msg::Info("%d partitions, %d total edge-cuts", numPart, objval);
  } catch(...) {
    Msg::Error("METIS exception");
    return 2;
  }
#endif

  return 0;
}

template <class ENTITY, class ITERATOR>
static void
assignElementsToEntities(GModel *model, hashmapelementpart &elmToPartition,
                         std::vector<ENTITY *> &newEntities, ITERATOR it_beg,
                         ITERATOR it_end, int &elementaryNumber)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    int partition = elmToPartition[(*it)] - 1;

    if(!newEntities[partition]) {
      std::vector<int> partitions;
      partitions.push_back(partition + 1);
      ENTITY *de = new ENTITY(model, ++elementaryNumber, partitions);
      model->add(de);
      newEntities[partition] = de;
    }

    newEntities[partition]->addElement((*it)->getType(), *it);
  }
}

template <class ITERATOR>
static void setVerticesToEntity(GEntity *entity, ITERATOR it_beg,
                                ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      if(!(*it)->getVertex(i)->onWhat()) {
        (*it)->getVertex(i)->setEntity(entity);
        entity->addMeshVertex((*it)->getVertex(i));
      }
    }
  }
}

template <class ITERATOR>
static void removeVerticesEntity(ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0; j < (*it)->getMeshElement(i)->getNumVertices();
          j++) {
        (*it)->getMeshElement(i)->getVertex(j)->setEntity(nullptr);
      }
    }
    (*it)->mesh_vertices.clear();
  }
}

// Assign the vertices to its corresponding entity
static void assignMeshVertices(GModel *model)
{
  removeVerticesEntity(model->firstVertex(), model->lastVertex());
  removeVerticesEntity(model->firstEdge(), model->lastEdge());
  removeVerticesEntity(model->firstFace(), model->lastFace());
  removeVerticesEntity(model->firstRegion(), model->lastRegion());

  // Loop over points
  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    setVerticesToEntity(*it, (*it)->points.begin(), (*it)->points.end());
  }

  // Loop over curves
  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    setVerticesToEntity(*it, (*it)->lines.begin(), (*it)->lines.end());
  }

  // Loop over surfaces
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    setVerticesToEntity(*it, (*it)->triangles.begin(), (*it)->triangles.end());
    setVerticesToEntity(*it, (*it)->quadrangles.begin(),
                        (*it)->quadrangles.end());
  }

  // Loop over volumes
  for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    setVerticesToEntity(*it, (*it)->tetrahedra.begin(),
                        (*it)->tetrahedra.end());
    setVerticesToEntity(*it, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
    setVerticesToEntity(*it, (*it)->prisms.begin(), (*it)->prisms.end());
    setVerticesToEntity(*it, (*it)->pyramids.begin(), (*it)->pyramids.end());
    setVerticesToEntity(*it, (*it)->trihedra.begin(), (*it)->trihedra.end());
  }
}

static void fillConnectedElements(
  std::vector<std::set<MElement *, MElementPtrLessThan> > &connectedElements,
  Graph &graph)
{
  std::stack<idx_t> elementStack;
  std::set<MElement *, MElementPtrLessThan> elements;
  idx_t startElement = 0;
  bool stop = true;
  std::size_t size = 0;
  idx_t isolatedElements = 0;

  do {
    // Inititalization
    elementStack.push(startElement);
    elements.insert(graph.element(startElement));

    while(elementStack.size() != 0) {
      idx_t top = elementStack.top();
      elementStack.pop();
      elements.insert(graph.element(top));

      for(idx_t i = graph.xadj(top); i < graph.xadj(top + 1); i++) {
        if(graph.adjncy(i) != 0) {
          elementStack.push(graph.adjncy(i));
          graph.adjncy(i, 0);
        }
      }
    }
    connectedElements.push_back(elements);
    size += elements.size();
    elements.clear();

    stop = (size == graph.ne() ? true : false);

    startElement = 0;
    if(!stop) {
      for(std::size_t i = 0; i < graph.ne(); i++) {
        for(idx_t j = graph.xadj(i); j < graph.xadj(i + 1); j++) {
          if(graph.adjncy(j) != 0) {
            startElement = i;
            i = graph.ne();
            break;
          }
        }
      }
      if(startElement == 0) {
        idx_t skipIsolatedElements = 0;
        for(std::size_t i = 1; i < graph.ne(); i++) {
          if(graph.xadj(i) == graph.xadj(i + 1)) {
            if(skipIsolatedElements == isolatedElements) {
              startElement = i;
              isolatedElements++;
              break;
            }
            skipIsolatedElements++;
          }
        }
      }
    }
  } while(!stop);
}

static bool
divideNonConnectedEntities(GModel *model, int dim,
                           std::set<GRegion *, GEntityPtrLessThan> &regions,
                           std::set<GFace *, GEntityPtrLessThan> &faces,
                           std::set<GEdge *, GEntityPtrLessThan> &edges,
                           std::set<GVertex *, GEntityPtrLessThan> &vertices)
{
  bool ret = false;
  // Loop over points
  if(dim < 0 || dim == 0) {
    int elementaryNumber = model->getMaxElementaryNumber(0);

    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionPoint) {
        partitionVertex *vertex = static_cast<partitionVertex *>(*it);

        if(vertex->getNumMeshElements() > 1) {
          ret = true;
          for(std::size_t i = 0; i < vertex->getNumMeshElements(); i++) {
            // Create the new partitionVertex
            partitionVertex *pvertex = new partitionVertex(
              model, ++elementaryNumber, vertex->getPartitions());
            // Assign parent entity
            pvertex->setParentEntity(vertex->getParentEntity());
            // Add to model
            model->add(pvertex);
            // Add elements
            pvertex->addElement(vertex->getMeshElement(i)->getType(),
                                vertex->getMeshElement(i));
            // Move B-Rep
            std::vector<GEdge *> BRepEdges = vertex->edges();
            if(!BRepEdges.empty()) {
              for(auto itBRep = BRepEdges.begin(); itBRep != BRepEdges.end();
                  ++itBRep) {
                if(vertex == (*itBRep)->getBeginVertex()) {
                  (*itBRep)->setVertex(pvertex, 1);
                  pvertex->addEdge(*itBRep);
                }
                if(vertex == (*itBRep)->getEndVertex()) {
                  (*itBRep)->setVertex(pvertex, -1);
                  pvertex->addEdge(*itBRep);
                }
              }
            }
          }

          model->remove(vertex);
          vertex->points.clear();
          vertex->mesh_vertices.clear();
          delete vertex;
        }
      }
    }
  }

  // Loop over curves
  if(dim < 0 || dim == 1) {
    // We build a graph
    Graph graph(model);
    graph.ne(model->getNumMeshElements(1));
    graph.nn(model->getNumMeshVertices(1));
    graph.dim(model->getMeshDim());
    graph.elementResize(graph.ne());
    graph.vertexResize(model->getMaxVertexNumber());
    graph.eptrResize(graph.ne() + 1);
    graph.eptr(0, 0);
    std::size_t eindSize = getSizeOfEind(model);
    graph.eindResize(eindSize);

    int elementaryNumber = model->getMaxElementaryNumber(1);

    for(auto it = edges.begin(); it != edges.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionCurve) {
        partitionEdge *edge = static_cast<partitionEdge *>(*it);

        graph.ne(edge->getNumMeshElements());
        graph.dim(1);
        graph.eptr(0, 0);
        graph.clearDualGraph();
        graph.eraseVertex();

        idx_t eptrIndex = 0;
        idx_t eindIndex = 0;
        idx_t numVertex = 0;

        fillElementsToNodesMap(graph, edge, eptrIndex, eindIndex, numVertex,
                               edge->lines.begin(), edge->lines.end());
        graph.nn(numVertex);
        graph.createDualGraph(false);

        // if a graph contains more than ((n-1)*(n-2))/2 edges (where n is the
        // number of nodes), then it is connected.
        if(((graph.numNodes() - 1) * (graph.numNodes() - 2)) / 2 <
           graph.numEdges()) {
          continue;
        }

        std::vector<std::set<MElement *, MElementPtrLessThan> >
          connectedElements;
        fillConnectedElements(connectedElements, graph);

        if(connectedElements.size() > 1) {
          ret = true;
          std::vector<GFace *> BRepFaces = edge->faces();

          std::vector<int> oldOrientations;
          oldOrientations.reserve(BRepFaces.size());

          if(!BRepFaces.empty()) {
            for(auto itBRep = BRepFaces.begin(); itBRep != BRepFaces.end();
                ++itBRep) {
              oldOrientations.push_back((*itBRep)->delEdge(edge));
            }
          }

          for(std::size_t i = 0; i < connectedElements.size(); i++) {
            // Create the new partitionEdge
            partitionEdge *pedge =
              new partitionEdge(model, ++elementaryNumber, nullptr, nullptr,
                                edge->getPartitions());
            // Assign parent entity
            pedge->setParentEntity(edge->getParentEntity());
            // Add to model
            model->add(pedge);
            for(auto itSet = connectedElements[i].begin();
                itSet != connectedElements[i].end(); ++itSet) {
              // Add elements
              pedge->addElement((*itSet)->getType(), (*itSet));
            }
            // Move B-Rep
            if(BRepFaces.size() > 0) {
              std::size_t i = 0;
              for(auto itBRep = BRepFaces.begin(); itBRep != BRepFaces.end();
                  ++itBRep) {
                (*itBRep)->setEdge(pedge, oldOrientations[i]);
                pedge->addFace(*itBRep);
                i++;
              }
            }
          }

          model->remove(edge);
          edge->lines.clear();
          edge->mesh_vertices.clear();
          delete edge;
        }

        connectedElements.clear();
      }
    }
  }

  // Loop over surfaces
  if(dim < 0 || dim == 2) {
    // We build a graph
    Graph graph(model);
    graph.ne(model->getNumMeshElements(2));
    graph.nn(model->getNumMeshVertices(2));
    graph.dim(model->getMeshDim());
    graph.elementResize(graph.ne());
    graph.vertexResize(model->getMaxVertexNumber());
    graph.eptrResize(graph.ne() + 1);
    graph.eptr(0, 0);
    std::size_t eindSize = getSizeOfEind(model);
    graph.eindResize(eindSize);

    int elementaryNumber = model->getMaxElementaryNumber(2);

    for(auto it = faces.begin(); it != faces.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionSurface) {
        partitionFace *face = static_cast<partitionFace *>(*it);

        graph.ne(face->getNumMeshElements());
        graph.dim(2);
        graph.eptr(0, 0);
        graph.clearDualGraph();
        graph.eraseVertex();

        idx_t eptrIndex = 0;
        idx_t eindIndex = 0;
        idx_t numVertex = 0;

        fillElementsToNodesMap(graph, face, eptrIndex, eindIndex, numVertex,
                               face->triangles.begin(), face->triangles.end());
        fillElementsToNodesMap(graph, face, eptrIndex, eindIndex, numVertex,
                               face->quadrangles.begin(),
                               face->quadrangles.end());
        graph.nn(numVertex);
        graph.createDualGraph(false);

        // if a graph contains more than ((n-1)*(n-2))/2 edges
        // (where n is the number of nodes), then it is connected.
        if(((graph.numNodes() - 1) * (graph.numNodes() - 2)) / 2 <
           graph.numEdges()) {
          continue;
        }

        std::vector<std::set<MElement *, MElementPtrLessThan> >
          connectedElements;
        fillConnectedElements(connectedElements, graph);

        if(connectedElements.size() > 1) {
          ret = true;
          std::list<GRegion *> BRepRegions = face->regions();
          std::vector<int> oldOrientations;
          if(BRepRegions.size() > 0) {
            for(auto itBRep = BRepRegions.begin(); itBRep != BRepRegions.end();
                ++itBRep) {
              oldOrientations.push_back((*itBRep)->delFace(face));
            }
          }

          for(std::size_t i = 0; i < connectedElements.size(); i++) {
            // Create the new partitionFace
            partitionFace *pface = new partitionFace(model, ++elementaryNumber,
                                                     face->getPartitions());
            // Assign parent entity
            pface->setParentEntity(face->getParentEntity());
            // Add to model
            model->add(pface);
            for(auto itSet = connectedElements[i].begin();
                itSet != connectedElements[i].end(); ++itSet) {
              // Add elements
              pface->addElement((*itSet)->getType(), (*itSet));
            }
            // Move B-Rep
            if(BRepRegions.size() > 0) {
              std::size_t i = 0;
              for(auto itBRep = BRepRegions.begin();
                  itBRep != BRepRegions.end(); ++itBRep) {
                (*itBRep)->setFace(pface, oldOrientations[i]);
                pface->addRegion(*itBRep);
                i++;
              }
            }
          }

          model->remove(face);
          face->triangles.clear();
          face->quadrangles.clear();
          face->mesh_vertices.clear();
          delete face;
        }

        connectedElements.clear();
      }
    }
  }

  // Loop over volumes
  if(dim < 0 || dim == 3) {
    // We build a graph
    Graph graph(model);
    graph.ne(model->getNumMeshElements(3));
    graph.nn(model->getNumMeshVertices(3));
    graph.dim(model->getMeshDim());
    graph.elementResize(graph.ne());
    graph.vertexResize(model->getMaxVertexNumber());
    graph.eptrResize(graph.ne() + 1);
    graph.eptr(0, 0);
    std::size_t eindSize = getSizeOfEind(model);
    graph.eindResize(eindSize);

    int elementaryNumber = model->getMaxElementaryNumber(3);

    for(auto it = regions.begin(); it != regions.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume) {
        partitionRegion *region = static_cast<partitionRegion *>(*it);

        graph.ne(region->getNumMeshElements());
        graph.dim(3);
        graph.eptr(0, 0);
        graph.clearDualGraph();
        graph.eraseVertex();

        idx_t eptrIndex = 0;
        idx_t eindIndex = 0;
        idx_t numVertex = 0;

        fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex,
                               region->tetrahedra.begin(),
                               region->tetrahedra.end());
        fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex,
                               region->hexahedra.begin(),
                               region->hexahedra.end());
        fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex,
                               region->prisms.begin(), region->prisms.end());
        fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex,
                               region->pyramids.begin(),
                               region->pyramids.end());
        fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex,
                               region->trihedra.begin(),
                               region->trihedra.end());
        graph.nn(numVertex);
        graph.createDualGraph(false);

        // if a graph contains more than ((n-1)*(n-2))/2 edges (where n is the
        // number of nodes), then it is connected.
        if(((graph.numNodes() - 1) * (graph.numNodes() - 2)) / 2 <
           graph.numEdges()) {
          continue;
        }

        std::vector<std::set<MElement *, MElementPtrLessThan> >
          connectedElements;
        fillConnectedElements(connectedElements, graph);

        if(connectedElements.size() > 1) {
          ret = true;
          for(std::size_t i = 0; i < connectedElements.size(); i++) {
            // Create the new partitionRegion
            partitionRegion *pregion = new partitionRegion(
              model, ++elementaryNumber, region->getPartitions());
            // Assign  d parent entity
            pregion->setParentEntity(region->getParentEntity());
            // Add to model
            model->add(pregion);
            for(auto itSet = connectedElements[i].begin();
                itSet != connectedElements[i].end(); ++itSet) {
              // Add elements
              pregion->addElement((*itSet)->getType(), (*itSet));
            }
          }

          model->remove(region);
          region->tetrahedra.clear();
          region->hexahedra.clear();
          region->prisms.clear();
          region->pyramids.clear();
          region->trihedra.clear();
          region->mesh_vertices.clear();
          delete region;
        }

        connectedElements.clear();
      }
    }
  }

  return ret;
}

// Create the new volume entities (omega)
static void createNewEntities(GModel *model, hashmapelementpart &elmToPartition)
{
  std::set<GRegion *, GEntityPtrLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityPtrLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityPtrLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityPtrLessThan> vertices = model->getVertices();

  int elementaryNumber = model->getMaxElementaryNumber(0);
  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    std::vector<partitionVertex *> newVertices(model->getNumPartitions(),
                                               nullptr);

    assignElementsToEntities(model, elmToPartition, newVertices,
                             (*it)->points.begin(), (*it)->points.end(),
                             elementaryNumber);

    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newVertices[i]) {
        static_cast<partitionVertex *>(newVertices[i])->setParentEntity((*it));
      }
    }

    (*it)->mesh_vertices.clear();

    (*it)->points.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(1);
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    std::vector<partitionEdge *> newEdges(model->getNumPartitions(), nullptr);

    assignElementsToEntities(model, elmToPartition, newEdges,
                             (*it)->lines.begin(), (*it)->lines.end(),
                             elementaryNumber);

    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newEdges[i]) {
        static_cast<partitionEdge *>(newEdges[i])->setParentEntity(*it);
      }
    }

    (*it)->mesh_vertices.clear();

    (*it)->lines.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(2);
  for(auto it = faces.begin(); it != faces.end(); ++it) {
    std::vector<partitionFace *> newFaces(model->getNumPartitions(), nullptr);

    assignElementsToEntities(model, elmToPartition, newFaces,
                             (*it)->triangles.begin(), (*it)->triangles.end(),
                             elementaryNumber);
    assignElementsToEntities(model, elmToPartition, newFaces,
                             (*it)->quadrangles.begin(),
                             (*it)->quadrangles.end(), elementaryNumber);

    std::list<GRegion *> BRepRegions = (*it)->regions();
    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newFaces[i]) {
        static_cast<partitionFace *>(newFaces[i])->setParentEntity(*it);
      }
    }

    (*it)->mesh_vertices.clear();

    (*it)->triangles.clear();
    (*it)->quadrangles.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(3);
  for(auto it = regions.begin(); it != regions.end(); ++it) {
    std::vector<partitionRegion *> newRegions(model->getNumPartitions(),
                                              nullptr);

    assignElementsToEntities(model, elmToPartition, newRegions,
                             (*it)->tetrahedra.begin(), (*it)->tetrahedra.end(),
                             elementaryNumber);
    assignElementsToEntities(model, elmToPartition, newRegions,
                             (*it)->hexahedra.begin(), (*it)->hexahedra.end(),
                             elementaryNumber);
    assignElementsToEntities(model, elmToPartition, newRegions,
                             (*it)->prisms.begin(), (*it)->prisms.end(),
                             elementaryNumber);
    assignElementsToEntities(model, elmToPartition, newRegions,
                             (*it)->pyramids.begin(), (*it)->pyramids.end(),
                             elementaryNumber);
    assignElementsToEntities(model, elmToPartition, newRegions,
                             (*it)->trihedra.begin(), (*it)->trihedra.end(),
                             elementaryNumber);

    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newRegions[i]) {
        static_cast<partitionRegion *>(newRegions[i])->setParentEntity(*it);
      }
    }

    (*it)->mesh_vertices.clear();

    (*it)->tetrahedra.clear();
    (*it)->hexahedra.clear();
    (*it)->prisms.clear();
    (*it)->pyramids.clear();
    (*it)->trihedra.clear();
  }

  // If we don't create the partition topology let's just assume that the user
  // does not care about multiply connected partitions or partition boundaries.
  if(!CTX::instance()->mesh.partitionCreateTopology) return;
  regions = model->getRegions();
  faces = model->getFaces();
  edges = model->getEdges();
  vertices = model->getVertices();
  divideNonConnectedEntities(model, -1, regions, faces, edges, vertices);
}

static void fillElementToEntity(GModel *model, hashmapelement &elmToEntity,
                                int dim)
{
  // Loop over volumes
  if(dim < 0 || dim == 3) {
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      for(auto itElm = (*it)->tetrahedra.begin();
          itElm != (*it)->tetrahedra.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(auto itElm = (*it)->hexahedra.begin();
          itElm != (*it)->hexahedra.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(auto itElm = (*it)->prisms.begin(); itElm != (*it)->prisms.end();
          ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(auto itElm = (*it)->pyramids.begin(); itElm != (*it)->pyramids.end();
          ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(auto itElm = (*it)->trihedra.begin(); itElm != (*it)->trihedra.end();
          ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }

  // Loop over surfaces
  if(dim < 0 || dim == 2) {
    for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
      for(auto itElm = (*it)->triangles.begin();
          itElm != (*it)->triangles.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(auto itElm = (*it)->quadrangles.begin();
          itElm != (*it)->quadrangles.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }

  // Loop over curves
  if(dim < 0 || dim == 1) {
    for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
      for(auto itElm = (*it)->lines.begin(); itElm != (*it)->lines.end();
          ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }

  // Loop over points
  if(dim < 0 || dim == 0) {
    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      for(auto itElm = (*it)->points.begin(); itElm != (*it)->points.end();
          ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }
}

static MElement *getReferenceElement(
  const std::vector<std::pair<MElement *, std::vector<int> > > &elementPairs)
{
  int min = std::numeric_limits<int>::max();
  std::vector<std::pair<MElement *, std::vector<int> > > minSizeElementPairs;
  std::vector<std::pair<MElement *, std::vector<int> > > minSizeElementPairsTmp;

  // Take only the elements having the less partition in commun. For exemple we
  // take (1,2) and (3,8) but not (2,5,9) or (1,4,5,7)
  for(std::size_t i = 0; i < elementPairs.size(); i++) {
    if(min > (int)elementPairs[i].second.size()) {
      minSizeElementPairs.clear();
      min = elementPairs[i].second.size();
      minSizeElementPairs.push_back(elementPairs[i]);
    }
    else if(min == (int)elementPairs[i].second.size()) {
      minSizeElementPairs.push_back(elementPairs[i]);
    }
  }

  // Check if the element separated different partitions
  if(minSizeElementPairs.size() == elementPairs.size()) {
    bool isEqual = true;
    for(std::size_t i = 1; i < minSizeElementPairs.size(); i++) {
      if(minSizeElementPairs[i].second != minSizeElementPairs[0].second) {
        isEqual = false;
        break;
      }
    }
    if(isEqual) return nullptr;
  }

  while(minSizeElementPairs.size() > 1) {
    min = std::numeric_limits<int>::max();
    for(std::size_t i = 0; i < minSizeElementPairs.size(); i++) {
      // The partition vector is sorted thus we can check only the first element
      if(minSizeElementPairs[i].second.size() == 0)
        return minSizeElementPairs[0].first;
      if(min > minSizeElementPairs[i].second[0]) {
        min = minSizeElementPairs[i].second[0];
      }
    }

    for(std::size_t i = 0; i < minSizeElementPairs.size(); i++) {
      if(min == minSizeElementPairs[i].second[0]) {
        minSizeElementPairs[i].second.erase(
          minSizeElementPairs[i].second.begin());
        minSizeElementPairsTmp.push_back(minSizeElementPairs[i]);
      }
    }
    minSizeElementPairs.clear();
    minSizeElementPairs = std::move(minSizeElementPairsTmp);
    minSizeElementPairsTmp.clear();
  }

  return minSizeElementPairs[0].first;
}

static void getPartitionInVector(
  std::vector<int> &partitions,
  const std::vector<std::pair<MElement *, std::vector<int> > > &boundaryPair)
{
  for(std::size_t i = 0; i < boundaryPair.size(); i++) {
    for(std::size_t j = 0; j < boundaryPair[i].second.size(); j++) {
      if(std::find(partitions.begin(), partitions.end(),
                   boundaryPair[i].second[j]) == partitions.end()) {
        partitions.push_back(boundaryPair[i].second[j]);
      }
    }
  }

  std::sort(partitions.begin(), partitions.end());
}

template <class PART_ENTITY, class LESS_PART_ENTITY>
static PART_ENTITY *createPartitionEntity(
  std::pair<typename std::multimap<PART_ENTITY *, GEntity *,
                                   LESS_PART_ENTITY>::iterator,
            typename std::multimap<PART_ENTITY *, GEntity *,
                                   LESS_PART_ENTITY>::iterator> &ret,
  GModel *model, int &numEntity, const std::vector<int> &partitions,
  GEntity *referenceEntity, PART_ENTITY **newEntity,
  typename std::multimap<PART_ENTITY *, GEntity *, LESS_PART_ENTITY> &pentities)
{
  PART_ENTITY *ppe = nullptr;
  // Create the new partition entity for the mesh
  if(ret.first == ret.second) {
    // Create new entity and add them to the model
    ppe = new PART_ENTITY(model, ++numEntity, partitions);
    ppe->setParentEntity(referenceEntity->getParentEntity());
    pentities.insert(std::pair<PART_ENTITY *, GEntity *>(ppe, referenceEntity));
    model->add(ppe);
    *newEntity = ppe;
  }
  else {
    for(auto it = ret.first; it != ret.second; ++it) {
      if(referenceEntity == it->second) { ppe = it->first; }
    }
    if(!ppe) {
      // Create new entity and add them to the model
      ppe = new PART_ENTITY(model, ++numEntity, partitions);
      ppe->setParentEntity(referenceEntity->getParentEntity());
      pentities.insert(
        std::pair<PART_ENTITY *, GEntity *>(ppe, referenceEntity));
      model->add(ppe);
      *newEntity = ppe;
    }
  }

  return ppe;
}

static partitionFace *assignPartitionBoundary(
  GModel *model, MFace &me, MElement *reference,
  const std::vector<int> &partitions,
  std::multimap<partitionFace *, GEntity *, partitionFacePtrLessThan> &pfaces,
  hashmapelement &elementToEntity, int &numEntity)
{
  partitionFace *newEntity = nullptr;
  partitionFace pf(model, partitions);
  std::pair<std::multimap<partitionFace *, GEntity *,
                          partitionFacePtrLessThan>::iterator,
            std::multimap<partitionFace *, GEntity *,
                          partitionFacePtrLessThan>::iterator>
    ret = pfaces.equal_range(&pf);

  partitionFace *ppf =
    createPartitionEntity(ret, model, numEntity, partitions,
                          elementToEntity[reference], &newEntity, pfaces);
  int numFace = 0;
  for(int i = 0; i < reference->getNumFaces(); i++) {
    if(reference->getFace(i) == me) {
      numFace = i;
      break;
    }
  }

  if(me.getNumVertices() == 3) {
    std::vector<MVertex *> verts;
    reference->getFaceVertices(numFace, verts);

    if(verts.size() == 3) {
      MTriangle *element = new MTriangle(verts);
      ppf->addTriangle(element);
    }
    else if(verts.size() == 6) {
      MTriangle6 *element = new MTriangle6(verts);
      ppf->addTriangle(element);
    }
    else {
      MTriangleN *element =
        new MTriangleN(verts, verts.back()->getPolynomialOrder());
      ppf->addTriangle(element);
    }
  }
  else if(me.getNumVertices() == 4) {
    std::vector<MVertex *> verts;
    reference->getFaceVertices(numFace, verts);

    if(verts.size() == 4) {
      MQuadrangle *element = new MQuadrangle(verts);
      ppf->addQuadrangle(element);
    }
    else if(verts.size() == 8) {
      MQuadrangle8 *element = new MQuadrangle8(verts);
      ppf->addQuadrangle(element);
    }
    else if(verts.size() == 9) {
      MQuadrangle9 *element = new MQuadrangle9(verts);
      ppf->addQuadrangle(element);
    }
    else {
      MQuadrangleN *element =
        new MQuadrangleN(verts, verts.back()->getPolynomialOrder());
      ppf->addQuadrangle(element);
    }
  }

  return newEntity;
}

static partitionEdge *assignPartitionBoundary(
  GModel *model, MEdge &me, MElement *reference,
  const std::vector<int> &partitions,
  std::multimap<partitionEdge *, GEntity *, partitionEdgePtrLessThan> &pedges,
  hashmapelement &elementToEntity, int &numEntity)
{
  partitionEdge *newEntity = nullptr;
  partitionEdge pe(model, partitions);
  std::pair<std::multimap<partitionEdge *, GEntity *,
                          partitionEdgePtrLessThan>::iterator,
            std::multimap<partitionEdge *, GEntity *,
                          partitionEdgePtrLessThan>::iterator>
    ret = pedges.equal_range(&pe);

  partitionEdge *ppe =
    createPartitionEntity(ret, model, numEntity, partitions,
                          elementToEntity[reference], &newEntity, pedges);

  int numEdge = 0;
  for(int i = 0; i < reference->getNumEdges(); i++) {
    if(reference->getEdge(i) == me) {
      numEdge = i;
      break;
    }
  }

  if(me.getNumVertices() == 2) {
    std::vector<MVertex *> verts;
    reference->getEdgeVertices(numEdge, verts);

    if(verts.size() == 2) {
      MLine *element = new MLine(verts);
      ppe->addLine(element);
    }
    else if(verts.size() == 3) {
      MLine3 *element = new MLine3(verts);
      ppe->addLine(element);
    }
    else {
      MLineN *element = new MLineN(verts);
      ppe->addLine(element);
    }
  }

  return newEntity;
}

static partitionVertex *assignPartitionBoundary(
  GModel *model, MVertex *ve, MElement *reference,
  const std::vector<int> &partitions,
  std::multimap<partitionVertex *, GEntity *, partitionVertexPtrLessThan>
    &pvertices,
  hashmapelement &elementToEntity, int &numEntity)
{
  partitionVertex *newEntity = nullptr;
  partitionVertex pv(model, partitions);
  std::pair<std::multimap<partitionVertex *, GEntity *,
                          partitionVertexPtrLessThan>::iterator,
            std::multimap<partitionVertex *, GEntity *,
                          partitionVertexPtrLessThan>::iterator>
    ret = pvertices.equal_range(&pv);

  partitionVertex *ppv =
    createPartitionEntity(ret, model, numEntity, partitions,
                          elementToEntity[reference], &newEntity, pvertices);

  ppv->addPoint(new MPoint(ve));

  return newEntity;
}

static int computeOrientation(MElement *reference, MElement *element)
{
  if(element->getDim() == 2) {
    std::vector<MVertex *> vertices;
    element->getVertices(vertices);
    MFace face = element->getFace(0);
    for(int i = 0; i < reference->getNumFaces(); i++) {
      if(reference->getFace(i) == face) {
        std::vector<MVertex *> referenceVertices;
        reference->getFaceVertices(i, referenceVertices);

        if(referenceVertices == vertices)
          return 1;
        else
          return -1;
      }
    }
  }
  else if(element->getDim() == 1) {
    std::vector<MVertex *> vertices;
    element->getVertices(vertices);
    MEdge face = element->getEdge(0);
    for(int i = 0; i < reference->getNumEdges(); i++) {
      if(reference->getEdge(i) == face) {
        std::vector<MVertex *> referenceVertices;
        reference->getEdgeVertices(i, referenceVertices);

        if(referenceVertices == vertices)
          return 1;
        else
          return -1;
      }
    }
  }
  else if(element->getDim() == 0) {
    std::vector<MVertex *> vertices;
    element->getVertices(vertices);

    std::vector<MVertex *> referenceVertices;
    reference->getVertices(referenceVertices);

    if(referenceVertices[0] == vertices[0]) return 1;
    if(referenceVertices[1] == vertices[0]) return -1;
  }

  return 0;
}

static void assignBrep(GModel *model,
                       std::map<GEntity *, MElement *, GEntityPtrFullLessThan>
                         &boundaryEntityAndRefElement,
                       GEntity *e)
{
  if(e->dim() == 2) {
    partitionFace *entity = static_cast<partitionFace *>(e);

    for(auto it = boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      static_cast<GRegion *>(it->first)->setFace(
        entity, computeOrientation(it->second, entity->getMeshElement(0)));
      entity->addRegion(static_cast<GRegion *>(it->first));
    }
  }
  else if(e->dim() == 1) {
    partitionEdge *entity = static_cast<partitionEdge *>(e);

    for(auto it = boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      static_cast<GFace *>(it->first)->setEdge(
        entity, computeOrientation(it->second, entity->getMeshElement(0)));
      entity->addFace(static_cast<GFace *>(it->first));
    }
  }
  else if(e->dim() == 0) {
    partitionVertex *entity = static_cast<partitionVertex *>(e);

    for(auto it = boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      static_cast<GEdge *>(it->first)->setVertex(
        entity, computeOrientation(it->second, entity->getMeshElement(0)));
      entity->addEdge(static_cast<GEdge *>(it->first));
    }
  }
}

static void assignNewEntityBRep(Graph &graph, hashmapelement &elementToEntity)
{
  std::set<std::pair<GEntity *, GEntity *> > brepWithoutOri;
  hashmapentity brep;
  for(std::size_t i = 0; i < graph.ne(); i++) {
    MElement *current = graph.element(i);
    for(idx_t j = graph.xadj(i); j < graph.xadj(i + 1); j++) {
      if(current->getDim() == graph.element(graph.adjncy(j))->getDim() + 1) {
        GEntity *g1 = elementToEntity[current];
        GEntity *g2 = elementToEntity[graph.element(graph.adjncy(j))];
        if(brepWithoutOri.find(std::pair<GEntity *, GEntity *>(g1, g2)) ==
           brepWithoutOri.end()) {
          const int ori =
            computeOrientation(current, graph.element(graph.adjncy(j)));
          brepWithoutOri.insert(std::pair<GEntity *, GEntity *>(g1, g2));
          brep[g1].insert(std::pair<int, GEntity *>(ori, g2));
        }
      }
    }
  }

  for(auto it = brep.begin(); it != brep.end(); ++it) {
    switch(it->first->dim()) {
    case 3:
      for(auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet) {
        static_cast<GRegion *>(it->first)->setFace(
          static_cast<GFace *>(itSet->second), itSet->first);
        static_cast<GFace *>(itSet->second)
          ->addRegion(static_cast<GRegion *>(it->first));
      }
      break;
    case 2:
      for(auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet) {
        static_cast<GFace *>(it->first)->setEdge(
          static_cast<GEdge *>(itSet->second), itSet->first);
        static_cast<GEdge *>(itSet->second)
          ->addFace(static_cast<GFace *>(it->first));
      }
      break;
    case 1:
      for(auto itSet = it->second.begin(); itSet != it->second.end(); ++itSet) {
        static_cast<GEdge *>(it->first)->setVertex(
          static_cast<GVertex *>(itSet->second), itSet->first);
        static_cast<GVertex *>(itSet->second)
          ->addEdge(static_cast<GEdge *>(it->first));
      }
      break;
    default: break;
    }
  }
}

// Create the new entities between each partitions (sigma and bndSigma).
static void createPartitionTopology(
  GModel *model,
  const std::vector<std::set<MElement *, MElementPtrLessThan> >
    &boundaryElements,
  Graph &meshGraph)
{
  int meshDim = model->getMeshDim();
  hashmapelement elementToEntity;
  fillElementToEntity(model, elementToEntity, -1);
  assignNewEntityBRep(meshGraph, elementToEntity);

  std::multimap<partitionFace *, GEntity *, partitionFacePtrLessThan> pfaces;
  std::multimap<partitionEdge *, GEntity *, partitionEdgePtrLessThan> pedges;
  std::multimap<partitionVertex *, GEntity *, partitionVertexPtrLessThan>
    pvertices;

  hashmapface faceToElement;
  hashmapedge edgeToElement;
  hashmapvertex vertexToElement;

  std::set<GRegion *, GEntityPtrLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityPtrLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityPtrLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityPtrLessThan> vertices = model->getVertices();

  if(meshDim >= 3) {
    Msg::Info(" - Creating partition surfaces");

    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      for(auto it = boundaryElements[i].begin();
          it != boundaryElements[i].end(); ++it) {
        for(int j = 0; j < (*it)->getNumFaces(); j++) {
          faceToElement[(*it)->getFace(j)].push_back(
            std::pair<MElement *, std::vector<int> >(
              *it, std::vector<int>(1, i + 1)));
        }
      }
    }
    int numFaceEntity = model->getMaxElementaryNumber(2);
    for(auto it = faceToElement.begin(); it != faceToElement.end(); ++it) {
      MFace f = it->first;

      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;

      MElement *reference = getReferenceElement(it->second);
      if(!reference) continue;

      partitionFace *pf =
        assignPartitionBoundary(model, f, reference, partitions, pfaces,
                                elementToEntity, numFaceEntity);
      if(pf) {
        std::map<GEntity *, MElement *, GEntityPtrFullLessThan>
          boundaryEntityAndRefElement;
        for(std::size_t i = 0; i < it->second.size(); i++)
          boundaryEntityAndRefElement.insert(std::pair<GEntity *, MElement *>(
            elementToEntity[it->second[i].first], it->second[i].first));

        assignBrep(model, boundaryEntityAndRefElement, pf);
      }
    }
    faceToElement.clear();

    faces = model->getFaces();
    divideNonConnectedEntities(model, 2, regions, faces, edges, vertices);
    elementToEntity.clear();
    fillElementToEntity(model, elementToEntity, 2);
  }

  if(meshDim >= 2) {
    Msg::Info(" - Creating partition curves");

    if(meshDim == 2) {
      for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
        for(auto it = boundaryElements[i].begin();
            it != boundaryElements[i].end(); ++it) {
          for(int j = 0; j < (*it)->getNumEdges(); j++) {
            edgeToElement[(*it)->getEdge(j)].push_back(
              std::pair<MElement *, std::vector<int> >(
                *it, std::vector<int>(1, i + 1)));
          }
        }
      }
    }
    else {
      Graph subGraph(model);
      makeGraph(model, subGraph, 2);
      subGraph.createDualGraph(false);
      std::vector<idx_t> part(subGraph.ne());
      int partIndex = 0;

      std::map<idx_t, std::vector<int> > mapOfPartitions;
      idx_t mapOfPartitionsTag = 0;
      for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
        if((*it)->geomType() == GEntity::PartitionSurface) {
          std::vector<int> partitions =
            static_cast<partitionFace *>(*it)->getPartitions();
          mapOfPartitions.insert(std::pair<idx_t, std::vector<int> >(
            mapOfPartitionsTag, partitions));
          // Must absolutely be in the same order as in the makeGraph function
          for(auto itElm = (*it)->triangles.begin();
              itElm != (*it)->triangles.end(); ++itElm)
            part[partIndex++] = mapOfPartitionsTag;
          for(auto itElm = (*it)->quadrangles.begin();
              itElm != (*it)->quadrangles.end(); ++itElm)
            part[partIndex++] = mapOfPartitionsTag;
          mapOfPartitionsTag++;
        }
      }
      subGraph.partition(part);

      std::vector<std::set<MElement *, MElementPtrLessThan> >
        subBoundaryElements = subGraph.getBoundaryElements(mapOfPartitionsTag);

      for(idx_t i = 0; i < mapOfPartitionsTag; i++) {
        for(auto it = subBoundaryElements[i].begin();
            it != subBoundaryElements[i].end(); ++it) {
          for(int j = 0; j < (*it)->getNumEdges(); j++) {
            edgeToElement[(*it)->getEdge(j)].push_back(
              std::pair<MElement *, std::vector<int> >(*it,
                                                       mapOfPartitions[i]));
          }
        }
      }
    }

    int numEdgeEntity = model->getMaxElementaryNumber(1);
    for(auto it = edgeToElement.begin(); it != edgeToElement.end(); ++it) {
      MEdge e = it->first;

      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;

      MElement *reference = getReferenceElement(it->second);
      if(!reference) continue;

      partitionEdge *pe =
        assignPartitionBoundary(model, e, reference, partitions, pedges,
                                elementToEntity, numEdgeEntity);
      if(pe) {
        std::map<GEntity *, MElement *, GEntityPtrFullLessThan>
          boundaryEntityAndRefElement;
        for(std::size_t i = 0; i < it->second.size(); i++) {
          boundaryEntityAndRefElement.insert(std::pair<GEntity *, MElement *>(
            elementToEntity[it->second[i].first], it->second[i].first));
        }

        assignBrep(model, boundaryEntityAndRefElement, pe);
      }
    }
    edgeToElement.clear();

    edges = model->getEdges();
    divideNonConnectedEntities(model, 1, regions, faces, edges, vertices);
    elementToEntity.clear();
    fillElementToEntity(model, elementToEntity, 1);
  }

  if(meshDim >= 1) {
    Msg::Info(" - Creating partition points");
    if(meshDim == 1) {
      for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
        for(auto it = boundaryElements[i].begin();
            it != boundaryElements[i].end(); ++it) {
          for(std::size_t j = 0; j < (*it)->getNumPrimaryVertices(); j++) {
            vertexToElement[(*it)->getVertex(j)].push_back(
              std::pair<MElement *, std::vector<int> >(
                *it, std::vector<int>(1, i + 1)));
          }
        }
      }
    }
    else {
      Graph subGraph(model);
      makeGraph(model, subGraph, 1);
      subGraph.createDualGraph(false);
      std::vector<idx_t> part(subGraph.ne());
      int partIndex = 0;

      std::map<idx_t, std::vector<int> > mapOfPartitions;
      idx_t mapOfPartitionsTag = 0;
      for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
        if((*it)->geomType() == GEntity::PartitionCurve) {
          std::vector<int> partitions =
            static_cast<partitionEdge *>(*it)->getPartitions();
          mapOfPartitions.insert(std::pair<idx_t, std::vector<int> >(
            mapOfPartitionsTag, partitions));
          // Must absolutely be in the same order as in the makeGraph function
          for(auto itElm = (*it)->lines.begin(); itElm != (*it)->lines.end();
              ++itElm)
            part[partIndex++] = mapOfPartitionsTag;
          mapOfPartitionsTag++;
        }
      }
      subGraph.partition(part);

      std::vector<std::set<MElement *, MElementPtrLessThan> >
        subBoundaryElements = subGraph.getBoundaryElements(mapOfPartitionsTag);

      for(idx_t i = 0; i < mapOfPartitionsTag; i++) {
        for(auto it = subBoundaryElements[i].begin();
            it != subBoundaryElements[i].end(); ++it) {
          for(std::size_t j = 0; j < (*it)->getNumPrimaryVertices(); j++) {
            vertexToElement[(*it)->getVertex(j)].push_back(
              std::pair<MElement *, std::vector<int> >(*it,
                                                       mapOfPartitions[i]));
          }
        }
      }
    }
    int numVertexEntity = model->getMaxElementaryNumber(0);
    for(auto it = vertexToElement.begin(); it != vertexToElement.end(); ++it) {
      MVertex *v = it->first;

      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;

      MElement *reference = getReferenceElement(it->second);
      if(!reference) continue;

      partitionVertex *pv =
        assignPartitionBoundary(model, v, reference, partitions, pvertices,
                                elementToEntity, numVertexEntity);
      if(pv) {
        std::map<GEntity *, MElement *, GEntityPtrFullLessThan>
          boundaryEntityAndRefElement;
        for(std::size_t i = 0; i < it->second.size(); i++)
          boundaryEntityAndRefElement.insert(std::pair<GEntity *, MElement *>(
            elementToEntity[it->second[i].first], it->second[i].first));

        assignBrep(model, boundaryEntityAndRefElement, pv);
      }
    }
    vertexToElement.clear();

    vertices = model->getVertices();
    divideNonConnectedEntities(model, 0, regions, faces, edges, vertices);
  }
}

static void addPhysical(GModel *model, GEntity *entity,
                        hashmap<std::string, int> &nameToNumber,
                        std::vector<GModel::piter> &iterators, int &numPhysical)
{
  GEntity *parent = entity->getParentEntity();
  if(parent == nullptr) return;

  if(!CTX::instance()->mesh.partitionCreatePhysicals ||
     CTX::instance()->mesh.partitionOldStyleMsh2) {
    // reuse physicals from parent entity
    entity->physicals = parent->physicals;
    return;
  }

  std::size_t numPartitions = 0;
  if(entity->dim() == 3) {
    numPartitions = static_cast<partitionRegion *>(entity)->numPartitions();
  }
  else if(entity->dim() == 2) {
    numPartitions = static_cast<partitionFace *>(entity)->numPartitions();
  }
  else if(entity->dim() == 1) {
    numPartitions = static_cast<partitionEdge *>(entity)->numPartitions();
  }
  else if(entity->dim() == 0) {
    numPartitions = static_cast<partitionVertex *>(entity)->numPartitions();
  }

  std::vector<int> physical = parent->getPhysicalEntities();
  int dim = entity->dim();
  for(size_t phys = 0; phys < physical.size(); ++phys) {
    std::string name = "_part{";

    for(std::size_t i = 0; i < numPartitions; i++) {
      if(i > 0) name += ",";
      int partition = 0;
      if(entity->dim() == 3) {
        partition = static_cast<partitionRegion *>(entity)->getPartition(i);
      }
      else if(entity->dim() == 2) {
        partition = static_cast<partitionFace *>(entity)->getPartition(i);
      }
      else if(entity->dim() == 1) {
        partition = static_cast<partitionEdge *>(entity)->getPartition(i);
      }
      else if(entity->dim() == 0) {
        partition = static_cast<partitionVertex *>(entity)->getPartition(i);
      }
      name += std::to_string(partition);
    }
    name += "}_physical{";
    name +=
      std::to_string(physical[phys]) + "}_dim{" + std::to_string(dim) + "}";

    int number = 0;
    auto it = nameToNumber.find(name);
    if(it == nameToNumber.end()) {
      number = ++numPhysical;
      iterators[entity->dim()] = model->setPhysicalName(
        iterators[entity->dim()], name, entity->dim(), number);
      nameToNumber.insert(std::pair<std::string, int>(name, number));
    }
    else {
      number = it->second;
    }
    entity->addPhysicalEntity(number);
  }

  if(physical.size() == 0) {
    std::string name = "_part{";

    for(std::size_t i = 0; i < numPartitions; i++) {
      if(i > 0) name += ",";
      int partition = 0;
      if(entity->dim() == 3) {
        partition = static_cast<partitionRegion *>(entity)->getPartition(i);
      }
      else if(entity->dim() == 2) {
        partition = static_cast<partitionFace *>(entity)->getPartition(i);
      }
      else if(entity->dim() == 1) {
        partition = static_cast<partitionEdge *>(entity)->getPartition(i);
      }
      else if(entity->dim() == 0) {
        partition = static_cast<partitionVertex *>(entity)->getPartition(i);
      }
      name += std::to_string(partition);
    }
    name += "}_";
    name += "physical{0}_dim{" + std::to_string(dim) + "}";

    int number = 0;
    auto it = nameToNumber.find(name);
    if(it == nameToNumber.end()) {
      number = ++numPhysical;
      iterators[entity->dim()] = model->setPhysicalName(
        iterators[entity->dim()], name, entity->dim(), number);
      nameToNumber.insert(std::pair<std::string, int>(name, number));
    }
    else {
      number = it->second;
    }
    entity->addPhysicalEntity(number);
  }
}

// Assign physical group information
static void assignPhysicals(GModel *model)
{
  hashmap<std::string, int> nameToNumber;
  std::vector<GModel::piter> iterators;
  model->getInnerPhysicalNamesIterators(iterators);
  int numPhysical = model->getMaxPhysicalNumber(-1);
  // Loop over volumes
  for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    if((*it)->geomType() == GEntity::PartitionVolume) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }

  // Loop over surfaces
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    if((*it)->geomType() == GEntity::PartitionSurface) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }

  // Loop over curves
  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    if((*it)->geomType() == GEntity::PartitionCurve) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }

  // Loop over points
  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    if((*it)->geomType() == GEntity::PartitionPoint) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }
}

bool cmp_hedges(const std::pair<MEdge, size_t> &he0,
                const std::pair<MEdge, size_t> &he1)
{
  MEdgeLessThan cmp;
  return cmp(he0.first, he1.first);
}

int PartitionFaceMinEdgeLength(GFace *gf, int np, double tol)
{
  std::vector<std::pair<MEdge, size_t> > halfEdges;
  halfEdges.reserve(gf->triangles.size() * 3);
  for(size_t i = 0; i < gf->triangles.size(); ++i) {
    for(size_t j = 0; j < 3; ++j) {
      halfEdges.push_back(std::make_pair(gf->triangles[i]->getEdge(j), i));
    }
  }
  std::sort(halfEdges.begin(), halfEdges.end(), cmp_hedges);
  std::vector<idx_t> neighbors(gf->triangles.size() * 3, -1);
  std::vector<double> neighborsWeight(gf->triangles.size() * 3, -1);
  MEdgeEqual eq;
  double minEdgeLength = std::numeric_limits<double>::max();
  for(size_t i = 0; i + 1 < halfEdges.size(); ++i) {
    if(eq(halfEdges[i].first, halfEdges[i + 1].first)) {
      size_t t0 = halfEdges[i].second;
      size_t t1 = halfEdges[i + 1].second;
      double l = halfEdges[i].first.length();
      minEdgeLength = std::min(l, minEdgeLength);
      for(int j = 0; j < 3; ++j) {
        if(neighbors[t0 * 3 + j] == -1) {
          neighbors[t0 * 3 + j] = t1;
          neighborsWeight[t0 * 3 + j] = l;
          break;
        }
      }
      for(int j = 0; j < 3; ++j) {
        if(neighbors[t1 * 3 + j] == -1) {
          neighbors[t1 * 3 + j] = t0;
          neighborsWeight[t1 * 3 + j] = l;
          break;
        }
      }
      i++;
    }
  }
  std::vector<idx_t> adjncy;
  std::vector<idx_t> xadjncy;
  std::vector<idx_t> adjncyw;
  xadjncy.push_back(0);
  for(size_t i = 0; i < gf->triangles.size(); ++i) {
    for(size_t j = 0; j < 3; ++j) {
      if(neighbors[i * 3 + j] == -1) break;
      adjncy.push_back(neighbors[i * 3 + j]);
      adjncyw.push_back(
        (idx_t)(neighborsWeight[i * 3 + j] / minEdgeLength * 10));
    }
    xadjncy.push_back(adjncy.size());
  }
  idx_t nvtxs = gf->triangles.size(), ncon = 1, nparts = np, objval;
  std::vector<idx_t> epart(gf->triangles.size());
  real_t ubvec = tol;
  METIS_PartGraphKway(&nvtxs, &ncon, &xadjncy[0], &adjncy[0], nullptr, nullptr,
                      &adjncyw[0], &nparts, nullptr, &ubvec, nullptr, &objval,
                      &epart[0]);
  for(size_t i = 0; i < gf->triangles.size(); ++i) {
    gf->triangles[i]->setPartition(epart[i]);
  }
  return 0;
}

// Partition a mesh into n parts. Returns: 0 = success, 1 = error

int PartitionMesh(GModel *model)
{
  if(CTX::instance()->mesh.numPartitions <= 0) return 0;

  Msg::StatusBar(true, "Partitioning mesh...");
  double t1 = Cpu(), w1 = TimeOfDay();

  Graph graph(model);
  if(makeGraph(model, graph, -1)) return 1;
  graph.nparts(CTX::instance()->mesh.numPartitions);
  if(partitionGraph(graph, true)) return 1;

  std::vector<std::size_t> elmCount[TYPE_MAX_NUM + 1];
  for(int i = 0; i < TYPE_MAX_NUM + 1; i++) {
    elmCount[i].resize(CTX::instance()->mesh.numPartitions, 0);
  }

  // Assign partitions to elements
  hashmapelementpart elmToPartition;
  for(std::size_t i = 0; i < graph.ne(); i++) {
    if(graph.element(i)) {
      if(graph.nparts() > 1) {
        elmToPartition.insert(std::pair<MElement *, idx_t>(
          graph.element(i), graph.partition(i) + 1));
        elmCount[graph.element(i)->getType()][graph.partition(i)]++;
        // Should be removed
        graph.element(i)->setPartition(graph.partition(i) + 1);
      }
      else {
        elmToPartition.insert(
          std::pair<MElement *, idx_t>(graph.element(i), 1));
        // Should be removed
        graph.element(i)->setPartition(1);
      }
    }
  }
  model->setNumPartitions(graph.nparts());

  createNewEntities(model, elmToPartition);
  elmToPartition.clear();

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done partitioning mesh (Wall %gs, CPU %gs)", w2 - w1,
                 t2 - t1);

  for(std::size_t i = 0; i < TYPE_MAX_NUM + 1; i++) {
    std::vector<std::size_t> &count = elmCount[i];
    std::size_t minCount = std::numeric_limits<std::size_t>::max();
    std::size_t maxCount = 0;
    std::size_t totCount = 0;
    for(std::size_t j = 0; j < count.size(); j++) {
      minCount = std::min(count[j], minCount);
      maxCount = std::max(count[j], maxCount);
      totCount += count[j];
    }
    if(totCount > 0) {
      Msg::Info(" - Repartition of %d %s: %lu(min) %lu(max) %g(avg)", totCount,
                ElementType::nameOfParentType(i, totCount > 1).c_str(),
                minCount, maxCount,
                totCount / (double)CTX::instance()->mesh.numPartitions);
    }
  }

  if(CTX::instance()->mesh.partitionCreateTopology) {
    Msg::StatusBar(true, "Creating partition topology...");
    std::vector<std::set<MElement *, MElementPtrLessThan> > boundaryElements =
      graph.getBoundaryElements();
    createPartitionTopology(model, boundaryElements, graph);
    boundaryElements.clear();
    double t3 = Cpu(), w3 = TimeOfDay();
    Msg::StatusBar(true, "Done creating partition topology (Wall %gs, CPU %gs)",
                   w3 - w2, t3 - t2);
  }

  assignPhysicals(model);
  assignMeshVertices(model);

  if(CTX::instance()->mesh.partitionCreateGhostCells) {
    double t4 = Cpu(), w4 = TimeOfDay();
    Msg::StatusBar(true, "Creating ghost cells...");
    graph.clearDualGraph();
    graph.createDualGraph(true);
    graph.assignGhostCells();
    double t5 = Cpu(), w5 = TimeOfDay();
    Msg::StatusBar(true, "Done creating ghost cells (Wall %gs, CPU %gs)",
                   w5 - w4, t5 - t4);
  }

  return 0;
}

template <class ITERATOR, class PART_ENTITY>
static void assignToParent(std::set<MVertex *> &verts, PART_ENTITY *entity,
                           ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    entity->getParentEntity()->addElement((*it)->getType(), *it);
    (*it)->setPartition(0);

    for(std::size_t i = 0; i < (*it)->getNumVertices(); i++) {
      if(verts.find((*it)->getVertex(i)) == verts.end()) {
        (*it)->getVertex(i)->setEntity(entity->getParentEntity());
        entity->getParentEntity()->addMeshVertex((*it)->getVertex(i));
        verts.insert((*it)->getVertex(i));
      }
    }
  }
}

// Un-partition a mesh and return to the initial mesh geomerty. Returns: 0 =
// success, 1 = error.
int UnpartitionMesh(GModel *model)
{
  // make a copy so we can iterate safely (we will remove some entities)
  std::set<GRegion *, GEntityPtrLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityPtrLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityPtrLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityPtrLessThan> vertices = model->getVertices();

  std::set<MVertex *> verts;

  // Loop over points
  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    GVertex *vertex = *it;

    if(vertex->geomType() == GEntity::PartitionPoint) {
      partitionVertex *pvertex = static_cast<partitionVertex *>(vertex);
      if(pvertex->getParentEntity() && pvertex->getParentEntity()->dim() == 0) {
        assignToParent(verts, pvertex, pvertex->points.begin(),
                       pvertex->points.end());
      }
      else {
        for(std::size_t j = 0; j < pvertex->points.size(); j++)
          delete pvertex->points[j];
      }
      pvertex->points.clear();
      pvertex->mesh_vertices.clear();

      model->remove(pvertex);
      delete pvertex;
    }
  }

  // Loop over curves
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    GEdge *edge = *it;
    if(edge->geomType() == GEntity::PartitionCurve) {
      partitionEdge *pedge = static_cast<partitionEdge *>(edge);
      if(pedge->getParentEntity() && pedge->getParentEntity()->dim() == 1) {
        assignToParent(verts, pedge, pedge->lines.begin(), pedge->lines.end());
      }
      else {
        for(std::size_t j = 0; j < pedge->lines.size(); j++)
          delete pedge->lines[j];
      }
      pedge->lines.clear();
      pedge->mesh_vertices.clear();
      pedge->setBeginVertex(nullptr);
      pedge->setEndVertex(nullptr);

      model->remove(pedge);
      delete pedge;
    }
    else if(edge->geomType() == GEntity::GhostCurve) {
      model->remove(edge);
      delete edge;
    }
  }

  // Loop over surfaces
  for(auto it = faces.begin(); it != faces.end(); ++it) {
    GFace *face = *it;

    if(face->geomType() == GEntity::PartitionSurface) {
      partitionFace *pface = static_cast<partitionFace *>(face);
      if(pface->getParentEntity() && pface->getParentEntity()->dim() == 2) {
        assignToParent(verts, pface, pface->triangles.begin(),
                       pface->triangles.end());
        assignToParent(verts, pface, pface->quadrangles.begin(),
                       pface->quadrangles.end());
      }
      else {
        for(std::size_t j = 0; j < pface->triangles.size(); j++)
          delete pface->triangles[j];
        for(std::size_t j = 0; j < pface->quadrangles.size(); j++)
          delete pface->quadrangles[j];
      }
      pface->triangles.clear();
      pface->quadrangles.clear();
      pface->mesh_vertices.clear();
      pface->set(std::vector<GEdge *>());
      pface->setOrientations(std::vector<int>());

      model->remove(pface);
      delete pface;
    }
    else if(face->geomType() == GEntity::GhostSurface) {
      model->remove(face);
      delete face;
    }
  }

  // Loop over volumes
  for(auto it = regions.begin(); it != regions.end(); ++it) {
    GRegion *region = *it;

    if(region->geomType() == GEntity::PartitionVolume) {
      partitionRegion *pregion = static_cast<partitionRegion *>(region);
      if(pregion->getParentEntity() && pregion->getParentEntity()->dim() == 3) {
        assignToParent(verts, pregion, pregion->tetrahedra.begin(),
                       pregion->tetrahedra.end());
        assignToParent(verts, pregion, pregion->hexahedra.begin(),
                       pregion->hexahedra.end());
        assignToParent(verts, pregion, pregion->prisms.begin(),
                       pregion->prisms.end());
        assignToParent(verts, pregion, pregion->pyramids.begin(),
                       pregion->pyramids.end());
        assignToParent(verts, pregion, pregion->trihedra.begin(),
                       pregion->trihedra.end());
      }
      else {
        for(std::size_t j = 0; j < pregion->tetrahedra.size(); j++)
          delete pregion->tetrahedra[j];
        for(std::size_t j = 0; j < pregion->hexahedra.size(); j++)
          delete pregion->hexahedra[j];
        for(std::size_t j = 0; j < pregion->prisms.size(); j++)
          delete pregion->prisms[j];
        for(std::size_t j = 0; j < pregion->pyramids.size(); j++)
          delete pregion->pyramids[j];
        for(std::size_t j = 0; j < pregion->trihedra.size(); j++)
          delete pregion->trihedra[j];
      }
      pregion->tetrahedra.clear();
      pregion->hexahedra.clear();
      pregion->prisms.clear();
      pregion->pyramids.clear();
      pregion->trihedra.clear();
      pregion->mesh_vertices.clear();
      pregion->set(std::vector<GFace *>());
      pregion->setOrientations(std::vector<int>());

      model->remove(pregion);
      delete pregion;
    }
    else if(region->geomType() == GEntity::GhostVolume) {
      model->remove(region);
      delete region;
    }
  }

  model->setNumPartitions(0);

  std::map<std::pair<int, int>, std::string> physicalNames =
    model->getPhysicalNames();
  for(auto it = physicalNames.begin(); it != physicalNames.end(); ++it) {
    std::size_t found = it->second.find("_");
    if(found != std::string::npos) {
      model->removePhysicalGroup(it->first.first, it->first.second);
    }
  }

  return 0;
}

// Create the partition according to the element split given by elmToPartition
// Returns: 0 = success, 1 = no elements found.
int PartitionUsingThisSplit(GModel *model, std::size_t npart,
                            std::vector<std::pair<MElement *, int> > &elmToPart)
{
  Graph graph(model);
  if(makeGraph(model, graph, -1)) return 1;
  graph.createDualGraph(false);
  graph.nparts(npart);

  hashmapelementpart elmToPartition;
  for(std::size_t i = 0; i < elmToPart.size(); i++)
    elmToPartition[elmToPart[i].first] = elmToPart[i].second;

  if(elmToPartition.size() != graph.ne()) {
    Msg::Error("All elements are not partitioned");
    return 1;
  }

  std::vector<idx_t> part(graph.ne());
  for(std::size_t i = 0; i < graph.ne(); i++) {
    if(graph.element(i)) { part[i] = elmToPartition[graph.element(i)] - 1; }
  }

  // Check and correct the topology
  for(int i = 1; i < 4; i++) {
    for(std::size_t j = 0; j < graph.ne(); j++) {
      if(graph.element(j)->getDim() == graph.dim()) continue;

      for(idx_t k = graph.xadj(j); k < graph.xadj(j + 1); k++) {
        if(graph.element(j)->getDim() ==
           graph.element(graph.adjncy(k))->getDim() - i) {
          if(part[j] != part[graph.adjncy(k)]) {
            part[j] = part[graph.adjncy(k)];
            break;
          }
        }
      }
    }
  }
  graph.partition(part);

  model->setNumPartitions(graph.nparts());

  createNewEntities(model, elmToPartition);
  elmToPartition.clear();

  if(CTX::instance()->mesh.partitionCreateTopology) {
    Msg::StatusBar(true, "Creating partition topology...");
    std::vector<std::set<MElement *, MElementPtrLessThan> > boundaryElements =
      graph.getBoundaryElements();
    createPartitionTopology(model, boundaryElements, graph);
    boundaryElements.clear();
    Msg::StatusBar(true, "Done creating partition topology");
  }

  assignPhysicals(model);
  assignMeshVertices(model);

  if(CTX::instance()->mesh.partitionCreateGhostCells) {
    graph.clearDualGraph();
    graph.createDualGraph(false);
    graph.assignGhostCells();
  }

  return 0;
}

// Import a mesh partitionned by a tag given to the element and create the
// topology (omega, sigma, bndSigma, ...). Returns: 0 = success, 1 = no elements
// found.
int ConvertOldPartitioningToNewOne(GModel *model)
{
  Msg::StatusBar(true, "Converting old partitioning...");

  std::vector<std::pair<MElement *, int> > elmToPartition;
  std::set<int> partitions;
  std::vector<GEntity *> entities;
  model->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      MElement *e = entities[i]->getMeshElement(j);
      idx_t part = e->getPartition();
      if(part < 0) part = -part;
      if(!part) part = 1;
      elmToPartition.push_back(std::pair<MElement *, idx_t>(e, part));
      partitions.insert(part);
    }
  }

  return PartitionUsingThisSplit(model, partitions.size(), elmToPartition);
}

#else

int PartitionMesh(GModel *model)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}

int UnpartitionMesh(GModel *model) { return 0; }

int ConvertOldPartitioningToNewOne(GModel *model) { return 0; }

int PartitionUsingThisSplit(
  GModel *model, std::size_t npart,
  std::vector<std::pair<MElement *, int> > &elmToPartition)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}

int PartitionFaceMinEdgeLength(GFace *gf, int np, double tol)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}

#endif
