// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Anthony Royer.

// FIXME: The partitioning code should be updated to
// - make it deterministic!
// - use int for partition tags (to match the type for other entities in Gmsh)
// - use size_t for element/node tags, and thus the graph

#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <limits>
#include <stack>
#include <cstdlib>
#include <map>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "ElementType.h"

// TODO C++11 remove this nasty stuff
#if __cplusplus >= 201103L
#include <unordered_map>
#define hashmap std::unordered_map
#define hashmapface                                                            \
  std::unordered_map<                                                          \
    MFace, std::vector<std::pair<MElement *, std::vector<unsigned int> > >,    \
    Hash_Face, Equal_Face>
#define hashmapedge                                                            \
  std::unordered_map<                                                          \
    MEdge, std::vector<std::pair<MElement *, std::vector<unsigned int> > >,    \
    Hash_Edge, Equal_Edge>
#define hashmapvertex                                                          \
  std::unordered_map<                                                          \
    MVertex *,                                                                 \
    std::vector<std::pair<MElement *, std::vector<unsigned int> > > >
#else
#define hashmap std::map
#define hashmapface                                                            \
  std::map<MFace,                                                              \
           std::vector<std::pair<MElement *, std::vector<unsigned int> > >,    \
           Less_Face>
#define hashmapedge                                                            \
  std::map<MEdge,                                                              \
           std::vector<std::pair<MElement *, std::vector<unsigned int> > >,    \
           Less_Edge>
#define hashmapvertex                                                          \
  std::map<MVertex *,                                                          \
           std::vector<std::pair<MElement *, std::vector<unsigned int> > > >
#endif

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
  unsigned int _nparts;
  // The number of elements
  unsigned int _ne;
  // The number of nodes
  unsigned int _nn;
  // The dimension of the mesh
  unsigned int _dim;
  // The list of nodes belonging to the ith element of the mesh are stored in
  // consecutive locations of eind starting at position eptr[i] up to (but not
  // including) position eptr[i+1]. The size of the eind array is of size equal
  // to the sum of the number of nodes in all the elements of the mesh.
  unsigned int *_eind;
  // The size of the eptr array is n + 1, where n is the number of elements in
  // the mesh.
  unsigned int *_eptr;
  // The metis graph structure
  unsigned int *_xadj, *_adjncy;
  // Elements corresponding to each graph elements in eptr
  MElement **_element;
  // Vertices corresponding to each graph vertices in eptr
  int *_vertex;
  int _vertexSize;
  // The width associated to each elements of eptr
  unsigned int *_vwgt;
  // The partitions output from the partitioner
  unsigned int *_partition;

public:
  Graph(GModel *const model)
    : _model(model), _nparts(0), _ne(0), _nn(0), _dim(0), _eind(0), _eptr(0),
      _xadj(0), _adjncy(0), _element(0), _vertex(0), _vertexSize(0), _vwgt(0),
      _partition(0)
  {
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

    _vwgt = new unsigned int[_ne];
    if(CTX::instance()->mesh.partitionLinWeight == -1 ||
       CTX::instance()->mesh.partitionTriWeight == -1 ||
       CTX::instance()->mesh.partitionQuaWeight == -1 ||
       CTX::instance()->mesh.partitionTetWeight == -1 ||
       CTX::instance()->mesh.partitionPyrWeight == -1 ||
       CTX::instance()->mesh.partitionPriWeight == -1 ||
       CTX::instance()->mesh.partitionHexWeight == -1) {
      for(unsigned int i = 0; i < _ne; i++) {
        if(!_element[i]) { _vwgt[i] = 1; }
        else {
          _vwgt[i] = (_element[i]->getDim() == (int)_dim ? 1 : 0);
        }
      }
    }
    else {
      for(unsigned int i = 0; i < _ne; i++) {
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
  ~Graph() { clear(); }
  unsigned int nparts() const { return _nparts; };
  unsigned int ne() const { return _ne; };
  unsigned int nn() const { return _nn; };
  unsigned int dim() const { return _dim; };
  unsigned int eind(unsigned int i) const { return _eind[i]; };
  unsigned int *eind() const { return _eind; };
  unsigned int eptr(unsigned int i) const { return _eptr[i]; };
  unsigned int *eptr() const { return _eptr; };
  unsigned int xadj(unsigned int i) const { return _xadj[i]; };
  unsigned int *xadj() const { return _xadj; };
  unsigned int adjncy(unsigned int i) const { return _adjncy[i]; };
  unsigned int *adjncy() const { return _adjncy; };
  MElement *element(unsigned int i) const { return _element[i]; };
  int vertex(unsigned int i) const { return _vertex[i]; };
  unsigned int *vwgt() const { return _vwgt; };
  unsigned int partition(unsigned int i) const { return _partition[i]; };
  unsigned int *partition() const { return _partition; };
  unsigned int numNodes() const { return _ne; };
  unsigned int numEdges() const { return _xadj[_ne] / 2; };
  void nparts(unsigned int nparts) { _nparts = nparts; };
  void ne(unsigned int ne) { _ne = ne; };
  void nn(unsigned int nn) { _nn = nn; };
  void dim(unsigned int dim) { _dim = dim; };
  void eindResize(unsigned int size)
  {
    _eind = new unsigned int[size];
    for(unsigned int i = 0; i < size; i++) _eind[i] = 0;
  }
  void eind(unsigned int i, unsigned int eind) { _eind[i] = eind; };
  void eptrResize(unsigned int size)
  {
    _eptr = new unsigned int[size];
    for(unsigned int i = 0; i < size; i++) _eptr[i] = 0;
  }
  void eptr(unsigned int i, unsigned int eptr) { _eptr[i] = eptr; };
  void elementResize(unsigned int size)
  {
    _element = new MElement *[size];
    for(unsigned int i = 0; i < size; i++) _element[i] = 0;
  }
  void element(unsigned int i, MElement *element) { _element[i] = element; };
  void vertexResize(unsigned int size)
  {
    _vertexSize = size;
    _vertex = new int[size];
    for(unsigned int i = 0; i < size; i++) _vertex[i] = -1;
  }
  void adjncy(unsigned int i, unsigned int adjncy) { _adjncy[i] = adjncy; };
  void vertex(unsigned int i, int vertex) { _vertex[i] = vertex; };
  void vwgt(unsigned int *vwgt) { _vwgt = vwgt; };
  void partition(unsigned int *partition) { _partition = partition; };
  void clear()
  {
    if(_eind) {
      delete[] _eind;
      _eind = 0;
    }
    if(_eptr) {
      delete[] _eptr;
      _eptr = 0;
    }
    if(_xadj) {
      delete[] _xadj;
      _xadj = 0;
    }
    if(_adjncy) {
      delete[] _adjncy;
      _adjncy = 0;
    }
    if(_element) {
      delete[] _element;
      _element = 0;
    }
    if(_vertex) {
      delete[] _vertex;
      _vertex = 0;
    }
    _vertexSize = 0;
    if(_vwgt) {
      delete[] _vwgt;
      _vwgt = 0;
    }
    if(_partition) {
      delete[] _partition;
      _partition = 0;
    }
  }
  void clearDualGraph()
  {
    if(_xadj) {
      delete[] _xadj;
      _xadj = 0;
    }
    if(_adjncy) {
      delete[] _adjncy;
      _adjncy = 0;
    }
  }
  void eraseVertex()
  {
    if(_vertex) {
      for(int i = 0; i < _vertexSize; i++) _vertex[i] = -1;
    }
  }

  std::vector<std::set<MElement *> > getBoundaryElements(int size = 0)
  {
    std::vector<std::set<MElement *> > elements((size ? size : _nparts),
                                                std::set<MElement *>());
    for(unsigned int i = 0; i < _ne; i++) {
      for(unsigned int j = _xadj[i]; j < _xadj[i + 1]; j++) {
        if(_partition[i] != _partition[_adjncy[j]]) {
          if(_element[i]->getDim() == (int)_dim) {
            elements[_partition[i]].insert(_element[i]);
          }
        }
      }
    }

    return elements;
  }

  void assignGhostCells()
  {
    std::vector<GEntity *> ghostEntities(_nparts, (GEntity *)NULL);
    int elementaryNumber = _model->getMaxElementaryNumber(_dim);

    for(unsigned int i = 1; i <= _nparts; i++) {
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

    for(unsigned int i = 0; i < _ne; i++) {
      std::set<short> ghostCellsPartition;
      for(unsigned int j = _xadj[i]; j < _xadj[i + 1]; j++) {
        if(_partition[i] != _partition[_adjncy[j]] &&
           ghostCellsPartition.find(_partition[_adjncy[j]]) ==
             ghostCellsPartition.end()) {
          if(_element[i]->getDim() == (int)_dim) {
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
    int *nptr = new int[_nn + 1];
    for(unsigned int i = 0; i < _nn + 1; i++) nptr[i] = 0;
    int *nind = new int[_eptr[_ne]];
    for(unsigned int i = 0; i < _eptr[_ne]; i++) nind[i] = 0;

    for(unsigned int i = 0; i < _ne; i++) {
      for(unsigned int j = _eptr[i]; j < _eptr[i + 1]; j++) {
        nptr[_eind[j]]++;
      }
    }

    for(unsigned int i = 1; i < _nn; i++) nptr[i] += nptr[i - 1];
    for(unsigned int i = _nn; i > 0; i--) nptr[i] = nptr[i - 1];
    nptr[0] = 0;

    for(unsigned int i = 0; i < _ne; i++) {
      for(unsigned int j = _eptr[i]; j < _eptr[i + 1]; j++) {
        nind[nptr[_eind[j]]++] = i;
      }
    }

    for(unsigned int i = _nn; i > 0; i--) nptr[i] = nptr[i - 1];
    nptr[0] = 0;

    _xadj = new unsigned int[_ne + 1];
    for(unsigned int i = 0; i < _ne + 1; i++) _xadj[i] = 0;
    int *nbrs = new int[_ne];
    int *marker = new int[_ne];
    for(unsigned int i = 0; i < _ne; i++) {
      nbrs[i] = 0;
      marker[i] = 0;
    }

    for(unsigned int i = 0; i < _ne; i++) {
      unsigned int l = 0;
      for(unsigned int j = _eptr[i]; j < _eptr[i + 1]; j++) {
        for(int k = nptr[_eind[j]]; k < nptr[_eind[j] + 1]; k++) {
          if(nind[k] != (int)i) {
            if(marker[nind[k]] == 0) nbrs[l++] = nind[k];
            marker[nind[k]]++;
          }
        }
      }

      unsigned int nbrsNeighbors = 0;
      for(unsigned int j = 0; j < l; j++) {
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

    for(unsigned int i = 1; i < _ne; i++) _xadj[i] = _xadj[i] + _xadj[i - 1];
    for(unsigned int i = _ne; i > 0; i--) _xadj[i] = _xadj[i - 1];
    _xadj[0] = 0;

    _adjncy = new unsigned int[_xadj[_ne]];
    for(unsigned int i = 0; i < _xadj[_ne]; i++) _adjncy[i] = 0;

    for(unsigned int i = 0; i < _ne; i++) {
      unsigned int l = 0;
      for(unsigned int j = _eptr[i]; j < _eptr[i + 1]; j++) {
        for(int k = nptr[_eind[j]]; k < nptr[_eind[j] + 1]; k++) {
          if(nind[k] != (int)i) {
            if(marker[nind[k]] == 0) nbrs[l++] = nind[k];
            marker[nind[k]]++;
          }
        }
      }

      for(unsigned int j = 0; j < l; j++) {
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
    delete[] nbrs;
    delete[] marker;

    for(unsigned int i = _ne; i > 0; i--) _xadj[i] = _xadj[i - 1];
    _xadj[0] = 0;

    delete[] nptr;
    delete[] nind;
  }
};

template <class ITERATOR>
static void fillElementsToNodesMap(Graph &graph, const GEntity *const entity,
                                   int &eptrIndex, int &eindIndex,
                                   int &numVertex, ITERATOR it_beg,
                                   ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    const int numVertices = (*it)->getNumPrimaryVertices();
    graph.element(eptrIndex++, *it);
    graph.eptr(eptrIndex, graph.eptr(eptrIndex - 1) + numVertices);
    for(int i = 0; i < numVertices; i++) {
      if(graph.vertex((*it)->getVertex(i)->getNum() - 1) == -1) {
        graph.vertex((*it)->getVertex(i)->getNum() - 1, numVertex++);
      }
      graph.eind(eindIndex, graph.vertex((*it)->getVertex(i)->getNum() - 1));
      eindIndex++;
    }
  }
}

static int getSizeOfEind(const GModel *const model)
{
  int size = 0;
  // Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion();
      ++it) {
    size += 4 * (*it)->tetrahedra.size();
    size += 8 * (*it)->hexahedra.size();
    size += 6 * (*it)->prisms.size();
    size += 5 * (*it)->pyramids.size();
    size += 4 * (*it)->trihedra.size();
  }

  // Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
      ++it) {
    size += 3 * (*it)->triangles.size();
    size += 4 * (*it)->quadrangles.size();
  }

  // Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
      ++it) {
    size += 2 * (*it)->lines.size();
  }

  // Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex();
      ++it) {
    size += 1 * (*it)->points.size();
  }

  return size;
}

// Creates a mesh data structure used by Metis routines. Returns: 0 = success, 1
// = no elements found, 2 = error.
static int MakeGraph(GModel *const model, Graph &graph, int selectDim)
{
  int eindSize = 0;
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

  int eptrIndex = 0;
  int eindIndex = 0;
  int numVertex = 0;

  if(graph.ne() == 0) {
    Msg::Error("No mesh elements were found");
    return 1;
  }
  if(graph.dim() == 0) {
    Msg::Error("Cannot partition a point");
    return 1;
  }

  // Loop over regions
  if(selectDim < 0 || selectDim == 3) {
    for(GModel::const_riter it = model->firstRegion();
        it != model->lastRegion(); ++it) {
      const GRegion *r = *it;
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

  // Loop over faces
  if(selectDim < 0 || selectDim == 2) {
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
        ++it) {
      const GFace *f = *it;

      fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex,
                             f->triangles.begin(), f->triangles.end());
      fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex,
                             f->quadrangles.begin(), f->quadrangles.end());
    }
  }

  // Loop over edges
  if(selectDim < 0 || selectDim == 1) {
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
        ++it) {
      const GEdge *e = *it;
      fillElementsToNodesMap(graph, e, eptrIndex, eindIndex, numVertex,
                             e->lines.begin(), e->lines.end());
    }
  }

  // Loop over vertices
  if(selectDim < 0 || selectDim == 0) {
    for(GModel::const_viter it = model->firstVertex();
        it != model->lastVertex(); ++it) {
      GVertex *v = *it;

      fillElementsToNodesMap(graph, v, eptrIndex, eindIndex, numVertex,
                             v->points.begin(), v->points.end());
    }
  }

  return 0;
}

// Partition a graph created by MakeGraph using Metis library. Returns: 0 =
// success, 1 = error, 2 = exception thrown.
static int PartitionGraph(Graph &graph, bool verbose)
{
#ifdef HAVE_METIS
  std::stringstream opt;
  try {
    int metisOptions[METIS_NOPTIONS];
    METIS_SetDefaultOptions((idx_t *)metisOptions);

    opt << "ptype:";
    switch(CTX::instance()->mesh.metisAlgorithm) {
    case 1: // Recursive
      metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_RB;
      opt << "rb";
      break;
    case 2: // K-way
      metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_KWAY;
      opt << "kway";
      break;
    default:
      opt << "default";
      break;
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
    default:
      opt << "default";
      break;
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
    default:
      opt << "default";
      break;
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
    default:
      opt << "default";
      break;
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
    default:
      opt << "default";
      break;
    }

    if(verbose)
      Msg::Info("Running METIS with %s", opt.str().c_str());

    // C numbering
    metisOptions[METIS_OPTION_NUMBERING] = 0;

    int objval;
    unsigned int *epart = new unsigned int[graph.ne()];
    const unsigned int ne = graph.ne();
    const int numPart = graph.nparts();
    int ncon = 1;
    graph.fillDefaultWeights();

    int metisError = 0;
    graph.createDualGraph(false);

    if(metisOptions[METIS_OPTION_PTYPE] == METIS_PTYPE_KWAY) {
      metisError = METIS_PartGraphKway(
        (idx_t *)&ne, (idx_t *)&ncon, (idx_t *)graph.xadj(),
        (idx_t *)graph.adjncy(), (idx_t *)graph.vwgt(), (idx_t *)0, 0,
        (idx_t *)&numPart, 0, 0, (idx_t *)metisOptions, (idx_t *)&objval,
        (idx_t *)epart);
    }
    else {
      metisError = METIS_PartGraphRecursive(
        (idx_t *)&ne, (idx_t *)&ncon, (idx_t *)graph.xadj(),
        (idx_t *)graph.adjncy(), (idx_t *)graph.vwgt(), (idx_t *)0, 0,
        (idx_t *)&numPart, 0, 0, (idx_t *)metisOptions, (idx_t *)&objval,
        (idx_t *)epart);
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
      for(unsigned int j = 0; j < graph.ne(); j++) {
        if(graph.element(j)->getDim() == (int)graph.dim()) continue;

        for(unsigned int k = graph.xadj(j); k < graph.xadj(j + 1); k++) {
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
    if(verbose)
      Msg::Info("%d partitions, %d total edge-cuts", numPart, objval);
  } catch(...) {
    Msg::Error("METIS exception");
    return 2;
  }
#endif

  return 0;
}

template <class ENTITY, class ITERATOR>
static void
assignElementsToEntities(GModel *const model,
                         hashmap<MElement *, unsigned int> &elmToPartition,
                         std::vector<ENTITY *> &newEntities, ITERATOR it_beg,
                         ITERATOR it_end, int &elementaryNumber)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    const unsigned int partition = elmToPartition[(*it)] - 1;

    if(!newEntities[partition]) {
      std::vector<unsigned int> partitions;
      partitions.push_back(partition + 1);
      ENTITY *de = new ENTITY(model, ++elementaryNumber, partitions);
      model->add(de);
      newEntities[partition] = de;
    }

    newEntities[partition]->addElement((*it)->getType(), *it);
  }
}

template <class ITERATOR>
void setVerticesToEntity(GEntity *const entity, ITERATOR it_beg,
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
void removeVerticesEntity(ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); i++) {
      for(std::size_t j = 0; j < (*it)->getMeshElement(i)->getNumVertices();
          j++) {
        (*it)->getMeshElement(i)->getVertex(j)->setEntity(0);
      }
    }
    (*it)->mesh_vertices.clear();
  }
}

// Assign the vertices to its corresponding entity
static void AssignMeshVertices(GModel *model)
{
  removeVerticesEntity(model->firstVertex(), model->lastVertex());
  removeVerticesEntity(model->firstEdge(), model->lastEdge());
  removeVerticesEntity(model->firstFace(), model->lastFace());
  removeVerticesEntity(model->firstRegion(), model->lastRegion());

  // Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex();
      ++it) {
    setVerticesToEntity(*it, (*it)->points.begin(), (*it)->points.end());
  }

  // Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
      ++it) {
    setVerticesToEntity(*it, (*it)->lines.begin(), (*it)->lines.end());
  }

  // Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
      ++it) {
    setVerticesToEntity(*it, (*it)->triangles.begin(), (*it)->triangles.end());
    setVerticesToEntity(*it, (*it)->quadrangles.begin(),
                        (*it)->quadrangles.end());
  }

  // Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion();
      ++it) {
    setVerticesToEntity(*it, (*it)->tetrahedra.begin(),
                        (*it)->tetrahedra.end());
    setVerticesToEntity(*it, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
    setVerticesToEntity(*it, (*it)->prisms.begin(), (*it)->prisms.end());
    setVerticesToEntity(*it, (*it)->pyramids.begin(), (*it)->pyramids.end());
    setVerticesToEntity(*it, (*it)->trihedra.begin(), (*it)->trihedra.end());
  }
}

static void
fillConnectedElements(std::vector<std::set<MElement *> > &connectedElements,
                      Graph &graph)
{
  std::stack<unsigned int> elementStack;
  std::set<MElement *> elements;
  unsigned int startElement = 0;
  bool stop = true;
  unsigned int size = 0;
  int isolatedElements = 0;

  do {
    // Inititalization
    elementStack.push(startElement);
    elements.insert(graph.element(startElement));

    while(elementStack.size() != 0) {
      unsigned int top = elementStack.top();
      elementStack.pop();
      elements.insert(graph.element(top));

      for(unsigned int i = graph.xadj(top); i < graph.xadj(top + 1); i++) {
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
      for(unsigned int i = 0; i < graph.ne(); i++) {
        for(unsigned int j = graph.xadj(i); j < graph.xadj(i + 1); j++) {
          if(graph.adjncy(j) != 0) {
            startElement = i;
            i = graph.ne();
            break;
          }
        }
      }
      if(startElement == 0) {
        int skipIsolatedElements = 0;
        for(unsigned int i = 1; i < graph.ne(); i++) {
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
dividedNonConnectedEntities(GModel *const model, int dim,
                            std::set<GRegion *, GEntityLessThan> &regions,
                            std::set<GFace *, GEntityLessThan> &faces,
                            std::set<GEdge *, GEntityLessThan> &edges,
                            std::set<GVertex *, GEntityLessThan> &vertices)
{
  bool ret = false;
  // Loop over vertices
  if(dim < 0 || dim == 0) {
    int elementaryNumber = model->getMaxElementaryNumber(0);

    for(GModel::const_viter it = vertices.begin(); it != vertices.end(); ++it) {
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
              for(std::vector<GEdge *>::iterator itBRep = BRepEdges.begin();
                  itBRep != BRepEdges.end(); ++itBRep) {
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

  // Loop over edges
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
    const int eindSize = getSizeOfEind(model);
    graph.eindResize(eindSize);

    int elementaryNumber = model->getMaxElementaryNumber(1);

    for(GModel::const_eiter it = edges.begin(); it != edges.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionCurve) {
        partitionEdge *edge = static_cast<partitionEdge *>(*it);

        graph.ne(edge->getNumMeshElements());
        graph.dim(1);
        graph.eptr(0, 0);
        graph.clearDualGraph();
        graph.eraseVertex();

        int eptrIndex = 0;
        int eindIndex = 0;
        int numVertex = 0;

        fillElementsToNodesMap(graph, edge, eptrIndex, eindIndex, numVertex,
                               edge->lines.begin(), edge->lines.end());
        graph.nn(numVertex);
        graph.createDualGraph(false);

        // if a graph contains more than ((n-1)*(n-2))/2 edges
        // (where n is the number of nodes), then it is connected.
        if(((graph.numNodes() - 1) * (graph.numNodes() - 2)) / 2 <
           graph.numEdges()) {
          continue;
        }

        std::vector<std::set<MElement *> > connectedElements;
        fillConnectedElements(connectedElements, graph);

        if(connectedElements.size() > 1) {
          ret = true;
          std::vector<GFace *> BRepFaces = edge->faces();

          std::vector<int> oldOrientations;
          oldOrientations.reserve(BRepFaces.size());

          if(!BRepFaces.empty()) {
            for(std::vector<GFace *>::iterator itBRep = BRepFaces.begin();
                itBRep != BRepFaces.end(); ++itBRep) {
              oldOrientations.push_back((*itBRep)->delEdge(edge));
            }
          }

          for(std::size_t i = 0; i < connectedElements.size(); i++) {
            // Create the new partitionEdge
            partitionEdge *pedge = new partitionEdge(
              model, ++elementaryNumber, 0, 0, edge->getPartitions());
            // Assign parent entity
            pedge->setParentEntity(edge->getParentEntity());
            // Add to model
            model->add(pedge);
            for(std::set<MElement *>::iterator itSet =
                  connectedElements[i].begin();
                itSet != connectedElements[i].end(); ++itSet) {
              // Add elements
              pedge->addElement((*itSet)->getType(), (*itSet));
            }
            // Move B-Rep
            if(BRepFaces.size() > 0) {
              int i = 0;
              for(std::vector<GFace *>::iterator itBRep = BRepFaces.begin();
                  itBRep != BRepFaces.end(); ++itBRep) {
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

  // Loop over faces
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
    const int eindSize = getSizeOfEind(model);
    graph.eindResize(eindSize);

    int elementaryNumber = model->getMaxElementaryNumber(2);

    for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionSurface) {
        partitionFace *face = static_cast<partitionFace *>(*it);

        graph.ne(face->getNumMeshElements());
        graph.dim(2);
        graph.eptr(0, 0);
        graph.clearDualGraph();
        graph.eraseVertex();

        int eptrIndex = 0;
        int eindIndex = 0;
        int numVertex = 0;

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

        std::vector<std::set<MElement *> > connectedElements;
        fillConnectedElements(connectedElements, graph);

        if(connectedElements.size() > 1) {
          ret = true;
          std::list<GRegion *> BRepRegions = face->regions();
          std::vector<int> oldOrientations;
          if(BRepRegions.size() > 0) {
            for(std::list<GRegion *>::iterator itBRep = BRepRegions.begin();
                itBRep != BRepRegions.end(); ++itBRep) {
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
            for(std::set<MElement *>::iterator itSet =
                  connectedElements[i].begin();
                itSet != connectedElements[i].end(); ++itSet) {
              // Add elements
              pface->addElement((*itSet)->getType(), (*itSet));
            }
            // Move B-Rep
            if(BRepRegions.size() > 0) {
              int i = 0;
              for(std::list<GRegion *>::iterator itBRep = BRepRegions.begin();
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

  // Loop over regions
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
    const int eindSize = getSizeOfEind(model);
    graph.eindResize(eindSize);

    int elementaryNumber = model->getMaxElementaryNumber(3);

    for(GModel::const_riter it = regions.begin(); it != regions.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume) {
        partitionRegion *region = static_cast<partitionRegion *>(*it);

        graph.ne(region->getNumMeshElements());
        graph.dim(3);
        graph.eptr(0, 0);
        graph.clearDualGraph();
        graph.eraseVertex();

        int eptrIndex = 0;
        int eindIndex = 0;
        int numVertex = 0;

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

        // if a graph contains more than ((n-1)*(n-2))/2 edges
        // (where n is the number of nodes), then it is connected.
        if(((graph.numNodes() - 1) * (graph.numNodes() - 2)) / 2 <
           graph.numEdges()) {
          continue;
        }

        std::vector<std::set<MElement *> > connectedElements;
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
            for(std::set<MElement *>::iterator itSet =
                  connectedElements[i].begin();
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
static void CreateNewEntities(GModel *const model,
                              hashmap<MElement *, unsigned int> &elmToPartition)
{
  std::set<GRegion *, GEntityLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityLessThan> vertices = model->getVertices();

  int elementaryNumber = model->getMaxElementaryNumber(0);
  for(GModel::const_viter it = vertices.begin(); it != vertices.end(); ++it) {
    std::vector<partitionVertex *> newVertices(model->getNumPartitions(), 0);

    assignElementsToEntities(model, elmToPartition, newVertices,
                             (*it)->points.begin(), (*it)->points.end(),
                             elementaryNumber);

    for(unsigned int i = 0; i < model->getNumPartitions(); i++) {
      if(newVertices[i]) {
        static_cast<partitionVertex *>(newVertices[i])->setParentEntity((*it));
      }
    }

    (*it)->mesh_vertices.clear();

    (*it)->points.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(1);
  for(GModel::const_eiter it = edges.begin(); it != edges.end(); ++it) {
    std::vector<partitionEdge *> newEdges(model->getNumPartitions(), 0);

    assignElementsToEntities(model, elmToPartition, newEdges,
                             (*it)->lines.begin(), (*it)->lines.end(),
                             elementaryNumber);

    for(unsigned int i = 0; i < model->getNumPartitions(); i++) {
      if(newEdges[i]) {
        static_cast<partitionEdge *>(newEdges[i])->setParentEntity(*it);
      }
    }

    (*it)->mesh_vertices.clear();

    (*it)->lines.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(2);
  for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it) {
    std::vector<partitionFace *> newFaces(model->getNumPartitions(), 0);

    assignElementsToEntities(model, elmToPartition, newFaces,
                             (*it)->triangles.begin(), (*it)->triangles.end(),
                             elementaryNumber);
    assignElementsToEntities(model, elmToPartition, newFaces,
                             (*it)->quadrangles.begin(),
                             (*it)->quadrangles.end(), elementaryNumber);

    std::list<GRegion *> BRepRegions = (*it)->regions();
    for(unsigned int i = 0; i < model->getNumPartitions(); i++) {
      if(newFaces[i]) {
        static_cast<partitionFace *>(newFaces[i])->setParentEntity(*it);
      }
    }

    (*it)->mesh_vertices.clear();

    (*it)->triangles.clear();
    (*it)->quadrangles.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(3);
  for(GModel::const_riter it = regions.begin(); it != regions.end(); ++it) {
    std::vector<partitionRegion *> newRegions(model->getNumPartitions(), 0);

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

    for(unsigned int i = 0; i < model->getNumPartitions(); i++) {
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
  // does not care about multi-connected partitions or partition boundaries.
  if(!CTX::instance()->mesh.partitionCreateTopology) return;
  regions = model->getRegions();
  faces = model->getFaces();
  edges = model->getEdges();
  vertices = model->getVertices();
  dividedNonConnectedEntities(model, -1, regions, faces, edges, vertices);
}

static void fillElementToEntity(GModel *const model,
                                hashmap<MElement *, GEntity *> &elmToEntity,
                                int dim)
{
  // Loop over regions
  if(dim < 0 || dim == 3) {
    for(GModel::const_riter it = model->firstRegion();
        it != model->lastRegion(); ++it) {
      for(std::vector<MTetrahedron *>::iterator itElm =
            (*it)->tetrahedra.begin();
          itElm != (*it)->tetrahedra.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(std::vector<MHexahedron *>::iterator itElm = (*it)->hexahedra.begin();
          itElm != (*it)->hexahedra.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(std::vector<MPrism *>::iterator itElm = (*it)->prisms.begin();
          itElm != (*it)->prisms.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(std::vector<MPyramid *>::iterator itElm = (*it)->pyramids.begin();
          itElm != (*it)->pyramids.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(std::vector<MTrihedron *>::iterator itElm = (*it)->trihedra.begin();
          itElm != (*it)->trihedra.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }

  // Loop over faces
  if(dim < 0 || dim == 2) {
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
        ++it) {
      for(std::vector<MTriangle *>::iterator itElm = (*it)->triangles.begin();
          itElm != (*it)->triangles.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
      for(std::vector<MQuadrangle *>::iterator itElm =
            (*it)->quadrangles.begin();
          itElm != (*it)->quadrangles.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }

  // Loop over edges
  if(dim < 0 || dim == 1) {
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
        ++it) {
      for(std::vector<MLine *>::iterator itElm = (*it)->lines.begin();
          itElm != (*it)->lines.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }

  // Loop over vertices
  if(dim < 0 || dim == 0) {
    for(GModel::const_viter it = model->firstVertex();
        it != model->lastVertex(); ++it) {
      for(std::vector<MPoint *>::iterator itElm = (*it)->points.begin();
          itElm != (*it)->points.end(); ++itElm)
        elmToEntity.insert(std::pair<MElement *, GEntity *>(*itElm, *it));
    }
  }
}

static MElement *getReferenceElement(
  const std::vector<std::pair<MElement *, std::vector<unsigned int> > >
    &elementPairs)
{
  unsigned int min = std::numeric_limits<unsigned int>::max();
  std::vector<std::pair<MElement *, std::vector<unsigned int> > >
    minSizeElementPairs;
  std::vector<std::pair<MElement *, std::vector<unsigned int> > >
    minSizeElementPairsTmp;

  // Take only the elements having the less partition in commun. For exemple we
  // take (1,2) and (3,8) but not (2,5,9) or (1,4,5,7)
  for(std::size_t i = 0; i < elementPairs.size(); i++) {
    if(min > elementPairs[i].second.size()) {
      minSizeElementPairs.clear();
      min = elementPairs[i].second.size();
      minSizeElementPairs.push_back(elementPairs[i]);
    }
    else if(min == elementPairs[i].second.size()) {
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
    if(isEqual) return 0;
  }

  while(minSizeElementPairs.size() > 1) {
    min = std::numeric_limits<unsigned int>::max();
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
#if __cplusplus >= 201103L
    minSizeElementPairs = std::move(minSizeElementPairsTmp);
#else
    minSizeElementPairs = minSizeElementPairsTmp;
#endif
    minSizeElementPairsTmp.clear();
  }

  return minSizeElementPairs[0].first;
}

static void getPartitionInVector(
  std::vector<unsigned int> &partitions,
  const std::vector<std::pair<MElement *, std::vector<unsigned int> > >
    &boundaryPair)
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
  GModel *const model, int &numEntity,
  const std::vector<unsigned int> &partitions, GEntity *referenceEntity,
  PART_ENTITY **newEntity,
  typename std::multimap<PART_ENTITY *, GEntity *, LESS_PART_ENTITY> &pentities)
{
  PART_ENTITY *ppe = 0;
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
    for(typename std::multimap<PART_ENTITY *, GEntity *,
                               LESS_PART_ENTITY>::iterator it = ret.first;
        it != ret.second; ++it) {
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
  GModel *const model, MFace &me, MElement *reference,
  const std::vector<unsigned int> &partitions,
  std::multimap<partitionFace *, GEntity *, Less_partitionFace> &pfaces,
  hashmap<MElement *, GEntity *> &elementToEntity, int &numEntity)
{
  partitionFace *newEntity = 0;
  partitionFace pf(model, 1, partitions);
  std::pair<
    std::multimap<partitionFace *, GEntity *, Less_partitionFace>::iterator,
    std::multimap<partitionFace *, GEntity *, Less_partitionFace>::iterator>
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
  GModel *const model, MEdge &me, MElement *reference,
  const std::vector<unsigned int> &partitions,
  std::multimap<partitionEdge *, GEntity *, Less_partitionEdge> &pedges,
  hashmap<MElement *, GEntity *> &elementToEntity, int &numEntity)
{
  partitionEdge *newEntity = 0;
  partitionEdge pe(model, 1, 0, 0, partitions);
  std::pair<
    std::multimap<partitionEdge *, GEntity *, Less_partitionEdge>::iterator,
    std::multimap<partitionEdge *, GEntity *, Less_partitionEdge>::iterator>
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
  GModel *const model, MVertex *ve, MElement *reference,
  const std::vector<unsigned int> &partitions,
  std::multimap<partitionVertex *, GEntity *, Less_partitionVertex> &pvertices,
  hashmap<MElement *, GEntity *> &elementToEntity, int &numEntity)
{
  partitionVertex *newEntity = 0;
  partitionVertex pv(model, 1, partitions);
  std::pair<
    std::multimap<partitionVertex *, GEntity *, Less_partitionVertex>::iterator,
    std::multimap<partitionVertex *, GEntity *, Less_partitionVertex>::iterator>
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

static void
assignBrep(GModel *const model,
           std::map<GEntity *, MElement *> &boundaryEntityAndRefElement,
           GEntity *e)
{
  if(e->dim() == 2) {
    partitionFace *entity = static_cast<partitionFace *>(e);

    for(std::map<GEntity *, MElement *>::iterator it =
          boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      static_cast<GRegion *>(it->first)->setFace(
        entity, computeOrientation(it->second, entity->getMeshElement(0)));
      entity->addRegion(static_cast<GRegion *>(it->first));
    }
  }
  else if(e->dim() == 1) {
    partitionEdge *entity = static_cast<partitionEdge *>(e);

    for(std::map<GEntity *, MElement *>::iterator it =
          boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      static_cast<GFace *>(it->first)->setEdge(
        entity, computeOrientation(it->second, entity->getMeshElement(0)));
      entity->addFace(static_cast<GFace *>(it->first));
    }
  }
  else if(e->dim() == 0) {
    partitionVertex *entity = static_cast<partitionVertex *>(e);

    for(std::map<GEntity *, MElement *>::iterator it =
          boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      static_cast<GEdge *>(it->first)->setVertex(
        entity, computeOrientation(it->second, entity->getMeshElement(0)));
      entity->addEdge(static_cast<GEdge *>(it->first));
    }
  }
}

void assignNewEntityBRep(Graph &graph,
                         hashmap<MElement *, GEntity *> &elementToEntity)
{
  std::set<std::pair<GEntity *, GEntity *> > brepWithoutOri;
  hashmap<GEntity *, std::set<std::pair<int, GEntity *> > > brep;
  for(unsigned int i = 0; i < graph.ne(); i++) {
    MElement *current = graph.element(i);
    for(unsigned int j = graph.xadj(i); j < graph.xadj(i + 1); j++) {
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

  for(hashmap<GEntity *, std::set<std::pair<int, GEntity *> > >::iterator it =
        brep.begin();
      it != brep.end(); ++it) {
    switch(it->first->dim()) {
    case 3:
      for(std::set<std::pair<int, GEntity *> >::iterator itSet =
            it->second.begin();
          itSet != it->second.end(); ++itSet) {
        static_cast<GRegion *>(it->first)->setFace(
          static_cast<GFace *>(itSet->second), itSet->first);
        static_cast<GFace *>(itSet->second)
          ->addRegion(static_cast<GRegion *>(it->first));
      }
      break;
    case 2:
      for(std::set<std::pair<int, GEntity *> >::iterator itSet =
            it->second.begin();
          itSet != it->second.end(); ++itSet) {
        static_cast<GFace *>(it->first)->setEdge(
          static_cast<GEdge *>(itSet->second), itSet->first);
        static_cast<GEdge *>(itSet->second)
          ->addFace(static_cast<GFace *>(it->first));
      }
      break;
    case 1:
      for(std::set<std::pair<int, GEntity *> >::iterator itSet =
            it->second.begin();
          itSet != it->second.end(); ++itSet) {
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
static void CreatePartitionTopology(
  GModel *const model,
  const std::vector<std::set<MElement *> > &boundaryElements, Graph &meshGraph)
{
  const int meshDim = model->getMeshDim();
  hashmap<MElement *, GEntity *> elementToEntity;
  fillElementToEntity(model, elementToEntity, -1);
  assignNewEntityBRep(meshGraph, elementToEntity);

  std::multimap<partitionFace *, GEntity *, Less_partitionFace> pfaces;
  std::multimap<partitionEdge *, GEntity *, Less_partitionEdge> pedges;
  std::multimap<partitionVertex *, GEntity *, Less_partitionVertex> pvertices;

  hashmapface faceToElement;
  hashmapedge edgeToElement;
  hashmapvertex vertexToElement;

  std::set<GRegion *, GEntityLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityLessThan> vertices = model->getVertices();

  if(meshDim >= 3) {
    Msg::Info(" - Creating partition surfaces");

    for(unsigned int i = 0; i < model->getNumPartitions(); i++) {
      for(std::set<MElement *>::iterator it = boundaryElements[i].begin();
          it != boundaryElements[i].end(); ++it) {
        for(int j = 0; j < (*it)->getNumFaces(); j++) {
          faceToElement[(*it)->getFace(j)].push_back(
            std::pair<MElement *, std::vector<unsigned int> >(
              *it, std::vector<unsigned int>(1, i + 1)));
        }
      }
    }
    int numFaceEntity = model->getMaxElementaryNumber(2);
    for(hashmapface::const_iterator it = faceToElement.begin();
        it != faceToElement.end(); ++it) {
      MFace f = it->first;

      std::vector<unsigned int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;

      MElement *reference = getReferenceElement(it->second);
      if(!reference) continue;

      partitionFace *pf =
        assignPartitionBoundary(model, f, reference, partitions, pfaces,
                                elementToEntity, numFaceEntity);
      if(pf) {
        std::map<GEntity *, MElement *> boundaryEntityAndRefElement;
        for(std::size_t i = 0; i < it->second.size(); i++)
          boundaryEntityAndRefElement.insert(std::pair<GEntity *, MElement *>(
            elementToEntity[it->second[i].first], it->second[i].first));

        assignBrep(model, boundaryEntityAndRefElement, pf);
      }
    }
    faceToElement.clear();

    faces = model->getFaces();
    dividedNonConnectedEntities(model, 2, regions, faces, edges, vertices);
    elementToEntity.clear();
    fillElementToEntity(model, elementToEntity, 2);
  }

  if(meshDim >= 2) {
    Msg::Info(" - Creating partition curves");

    if(meshDim == 2) {
      for(unsigned int i = 0; i < model->getNumPartitions(); i++) {
        for(std::set<MElement *>::iterator it = boundaryElements[i].begin();
            it != boundaryElements[i].end(); ++it) {
          for(int j = 0; j < (*it)->getNumEdges(); j++) {
            edgeToElement[(*it)->getEdge(j)].push_back(
              std::pair<MElement *, std::vector<unsigned int> >(
                *it, std::vector<unsigned int>(1, i + 1)));
          }
        }
      }
    }
    else {
      Graph subGraph(model);
      MakeGraph(model, subGraph, 2);
      subGraph.createDualGraph(false);
      unsigned int *part = new unsigned int[subGraph.ne()];
      int partIndex = 0;

      std::map<unsigned int, std::vector<unsigned int> > mapOfPartitions;
      unsigned int mapOfPartitionsTag = 0;
      for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
          ++it) {
        if((*it)->geomType() == GEntity::PartitionSurface) {
          std::vector<unsigned int> partitions =
            static_cast<partitionFace *>(*it)->getPartitions();
          mapOfPartitions.insert(
            std::pair<unsigned int, std::vector<unsigned int> >(
              mapOfPartitionsTag, partitions));
          // Must absolutely be in the same order as in the MakeGraph function
          for(std::vector<MTriangle *>::iterator itElm =
                (*it)->triangles.begin();
              itElm != (*it)->triangles.end(); ++itElm)
            part[partIndex++] = mapOfPartitionsTag;
          for(std::vector<MQuadrangle *>::iterator itElm =
                (*it)->quadrangles.begin();
              itElm != (*it)->quadrangles.end(); ++itElm)
            part[partIndex++] = mapOfPartitionsTag;
          mapOfPartitionsTag++;
        }
      }
      subGraph.partition(part);

      std::vector<std::set<MElement *> > subBoundaryElements =
        subGraph.getBoundaryElements(mapOfPartitionsTag);

      for(unsigned int i = 0; i < mapOfPartitionsTag; i++) {
        for(std::set<MElement *>::iterator it = subBoundaryElements[i].begin();
            it != subBoundaryElements[i].end(); ++it) {
          for(int j = 0; j < (*it)->getNumEdges(); j++) {
            edgeToElement[(*it)->getEdge(j)].push_back(
              std::pair<MElement *, std::vector<unsigned int> >(
                *it, mapOfPartitions[i]));
          }
        }
      }
    }

    int numEdgeEntity = model->getMaxElementaryNumber(1);
    for(hashmapedge::const_iterator it = edgeToElement.begin();
        it != edgeToElement.end(); ++it) {
      MEdge e = it->first;

      std::vector<unsigned int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;

      MElement *reference = getReferenceElement(it->second);
      if(!reference) continue;

      partitionEdge *pe =
        assignPartitionBoundary(model, e, reference, partitions, pedges,
                                elementToEntity, numEdgeEntity);
      if(pe) {
        std::map<GEntity *, MElement *> boundaryEntityAndRefElement;
        for(std::size_t i = 0; i < it->second.size(); i++) {
          boundaryEntityAndRefElement.insert(std::pair<GEntity *, MElement *>(
            elementToEntity[it->second[i].first], it->second[i].first));
        }

        assignBrep(model, boundaryEntityAndRefElement, pe);
      }
    }
    edgeToElement.clear();

    edges = model->getEdges();
    dividedNonConnectedEntities(model, 1, regions, faces, edges, vertices);
    elementToEntity.clear();
    fillElementToEntity(model, elementToEntity, 1);
  }

  if(meshDim >= 1) {
    Msg::Info(" - Creating partition points");
    if(meshDim == 1) {
      for(unsigned int i = 0; i < model->getNumPartitions(); i++) {
        for(std::set<MElement *>::iterator it = boundaryElements[i].begin();
            it != boundaryElements[i].end(); ++it) {
          for(int j = 0; j < (*it)->getNumPrimaryVertices(); j++) {
            vertexToElement[(*it)->getVertex(j)].push_back(
              std::pair<MElement *, std::vector<unsigned int> >(
                *it, std::vector<unsigned int>(1, i + 1)));
          }
        }
      }
    }
    else {
      Graph subGraph(model);
      MakeGraph(model, subGraph, 1);
      subGraph.createDualGraph(false);
      unsigned int *part = new unsigned int[subGraph.ne()];
      int partIndex = 0;

      std::map<unsigned int, std::vector<unsigned int> > mapOfPartitions;
      unsigned int mapOfPartitionsTag = 0;
      for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
          ++it) {
        if((*it)->geomType() == GEntity::PartitionCurve) {
          std::vector<unsigned int> partitions =
            static_cast<partitionEdge *>(*it)->getPartitions();
          mapOfPartitions.insert(
            std::pair<unsigned int, std::vector<unsigned int> >(
              mapOfPartitionsTag, partitions));
          // Must absolutely be in the same order as in the MakeGraph function
          for(std::vector<MLine *>::iterator itElm = (*it)->lines.begin();
              itElm != (*it)->lines.end(); ++itElm)
            part[partIndex++] = mapOfPartitionsTag;
          mapOfPartitionsTag++;
        }
      }
      subGraph.partition(part);

      std::vector<std::set<MElement *> > subBoundaryElements =
        subGraph.getBoundaryElements(mapOfPartitionsTag);

      for(unsigned int i = 0; i < mapOfPartitionsTag; i++) {
        for(std::set<MElement *>::iterator it = subBoundaryElements[i].begin();
            it != subBoundaryElements[i].end(); ++it) {
          for(int j = 0; j < (*it)->getNumPrimaryVertices(); j++) {
            vertexToElement[(*it)->getVertex(j)].push_back(
              std::pair<MElement *, std::vector<unsigned int> >(
                *it, mapOfPartitions[i]));
          }
        }
      }
    }
    int numVertexEntity = model->getMaxElementaryNumber(0);
    for(hashmapvertex::const_iterator it = vertexToElement.begin();
        it != vertexToElement.end(); ++it) {
      MVertex *v = it->first;

      std::vector<unsigned int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;

      MElement *reference = getReferenceElement(it->second);
      if(!reference) continue;

      partitionVertex *pv =
        assignPartitionBoundary(model, v, reference, partitions, pvertices,
                                elementToEntity, numVertexEntity);
      if(pv) {
        std::map<GEntity *, MElement *> boundaryEntityAndRefElement;
        for(std::size_t i = 0; i < it->second.size(); i++)
          boundaryEntityAndRefElement.insert(std::pair<GEntity *, MElement *>(
            elementToEntity[it->second[i].first], it->second[i].first));

        assignBrep(model, boundaryEntityAndRefElement, pv);
      }
    }
    vertexToElement.clear();

    vertices = model->getVertices();
    dividedNonConnectedEntities(model, 0, regions, faces, edges, vertices);
  }
}

static void addPhysical(GModel *const model, GEntity *entity,
                        hashmap<std::string, int> &nameToNumber,
                        std::vector<GModel::piter> &iterators, int &numPhysical)
{
  GEntity *parent = entity->getParentEntity();
  if(parent == 0) return;

  if(!CTX::instance()->mesh.partitionCreatePhysicals ||
     CTX::instance()->mesh.partitionOldStyleMsh2) {
    // reuse physicals from parent entity
    entity->physicals = parent->physicals;
    return;
  }

  unsigned int numPartitions = 0;
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

#if __cplusplus < 201103L
  char intToChar[20];
#endif
  std::vector<int> physical = parent->getPhysicalEntities();
  int dim = entity->dim();
  for(size_t phys = 0; phys < physical.size(); ++phys) {
    std::string name = "_part{";

    for(unsigned int i = 0; i < numPartitions; i++) {
      if(i > 0) name += ",";
      unsigned int partition = 0;
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
#if __cplusplus >= 201103L
      name += std::to_string(partition);
#else
      sprintf(intToChar, "%d", partition);
      name += intToChar;
#endif
    }
    name += "}_physical{";
#if __cplusplus >= 201103L
    name +=
      std::to_string(physical[phys]) + "}_dim{" + std::to_string(dim) + "}";
#else
    sprintf(intToChar, "%d}_dim{%d}", physical[phys], dim);
    name += intToChar;
#endif

    int number = 0;
    hashmap<std::string, int>::iterator it = nameToNumber.find(name);
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

    for(unsigned int i = 0; i < numPartitions; i++) {
      if(i > 0) name += ",";
      unsigned int partition = 0;
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
#if __cplusplus >= 201103L
      name += std::to_string(partition);
#else
      sprintf(intToChar, "%d", partition);
      name += intToChar;
#endif
    }
    name += "}_";
#if __cplusplus >= 201103L
    name += "physical{0}_dim{" + std::to_string(dim) + "}";
#else
    sprintf(intToChar, "physical{0}_dim{%d}", dim);
    name += intToChar;
#endif

    int number = 0;
    hashmap<std::string, int>::iterator it = nameToNumber.find(name);
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

// AssignPhysicalName
static void AssignPhysicalName(GModel *model)
{
  hashmap<std::string, int> nameToNumber;
  std::vector<GModel::piter> iterators;
  model->getInnerPhysicalNamesIterators(iterators);
  int numPhysical = model->getMaxPhysicalNumber(-1);
  // Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion();
      ++it) {
    if((*it)->geomType() == GEntity::PartitionVolume) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }

  // Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace();
      ++it) {
    if((*it)->geomType() == GEntity::PartitionSurface) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }

  // Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge();
      ++it) {
    if((*it)->geomType() == GEntity::PartitionCurve) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }

  // Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex();
      ++it) {
    if((*it)->geomType() == GEntity::PartitionPoint) {
      addPhysical(model, *it, nameToNumber, iterators, numPhysical);
    }
  }
}

int PartitionFace(GFace *gf, int np, int *p)
{
  GModel m;
  m.add(gf);
  for(size_t i = 0; i < gf->triangles.size(); ++i) {
    for(size_t j = 0; j < 3; ++j) {
      int n = gf->triangles[i]->getVertex(j)->getNum();
      if(n > (int)m.getMaxVertexNumber()) m.setMaxVertexNumber(n);
    }
  }
  Graph graph(&m);
  if(MakeGraph(&m, graph, -1)) return 1;
  graph.nparts(np);
  if(PartitionGraph(graph, false)) return 1;
  m.remove(gf);
  //  for (size_t i=0;i<graph.ne();++i)p[i]=graph.partition(i);
  for(unsigned int i = 0; i < graph.ne(); i++)
    graph.element(i)->setPartition(graph.partition(i));

  return 0;
}

// Partition a mesh into n parts. Returns: 0 = success, 1 = error

int PartitionMesh(GModel *const model)
{
  if(CTX::instance()->mesh.numPartitions <= 0) return 0;

  Msg::StatusBar(true, "Partitioning mesh...");
  double t1 = Cpu();

  Graph graph(model);
  if(MakeGraph(model, graph, -1)) return 1;
  graph.nparts(CTX::instance()->mesh.numPartitions);
  if(PartitionGraph(graph, true)) return 1;

  std::vector<int> elmCount[TYPE_MAX_NUM + 1];
  for(int i = 0; i < TYPE_MAX_NUM + 1; i++) {
    elmCount[i].resize(CTX::instance()->mesh.numPartitions, 0);
  }

  // Assign partitions to elements
  hashmap<MElement *, unsigned int> elmToPartition;
  for(unsigned int i = 0; i < graph.ne(); i++) {
    if(graph.element(i)) {
      if(graph.nparts() > 1) {
        elmToPartition.insert(std::pair<MElement *, unsigned int>(
          graph.element(i), graph.partition(i) + 1));
        elmCount[graph.element(i)->getType()][graph.partition(i)]++;
        // Should be removed
        graph.element(i)->setPartition(graph.partition(i) + 1);
      }
      else {
        elmToPartition.insert(
          std::pair<MElement *, unsigned int>(graph.element(i), 1));
        // Should be removed
        graph.element(i)->setPartition(1);
      }
    }
  }
  model->setNumPartitions(graph.nparts());

  CreateNewEntities(model, elmToPartition);
  elmToPartition.clear();

  double t2 = Cpu();
  Msg::StatusBar(true, "Done partitioning mesh (%g s)", t2 - t1);

  for(std::size_t i = 0; i < TYPE_MAX_NUM + 1; i++) {
    std::vector<int> &count = elmCount[i];
    int minCount = std::numeric_limits<int>::max();
    int maxCount = 0;
    int totCount = 0;
    for(std::size_t j = 0; j < count.size(); j++) {
      minCount = std::min(count[j], minCount);
      maxCount = std::max(count[j], maxCount);
      totCount += count[j];
    }
    if(totCount > 0) {
      Msg::Info(" - Repartition of %d %s: %d(min) %d(max) %g(avg)",
                totCount, ElementType::nameOfParentType(i, totCount > 1).c_str(),
                minCount, maxCount,
                totCount / (double)CTX::instance()->mesh.numPartitions);
    }
  }

  if(CTX::instance()->mesh.partitionCreateTopology) {
    Msg::StatusBar(true, "Creating partition topology...");
    std::vector<std::set<MElement *> > boundaryElements =
      graph.getBoundaryElements();
    CreatePartitionTopology(model, boundaryElements, graph);
    boundaryElements.clear();
    AssignPhysicalName(model);

    double t3 = Cpu();
    Msg::StatusBar(true, "Done creating partition topology (%g s)", t3 - t2);
  }

  AssignMeshVertices(model);

  if(CTX::instance()->mesh.partitionCreateGhostCells) {
    double t4 = Cpu();
    Msg::StatusBar(true, "Creating ghost cells...");
    graph.clearDualGraph();
    graph.createDualGraph(true);
    graph.assignGhostCells();
    double t5 = Cpu();
    Msg::StatusBar(true, "Done creating ghost cells (%g s)", t5 - t4);
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
int UnpartitionMesh(GModel *const model)
{
  // make a copy so we can iterate safely (we will remove some entities)
  std::set<GRegion *, GEntityLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityLessThan> vertices = model->getVertices();

  std::set<MVertex *> verts;

  // Loop over vertices
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it) {
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

  // Loop over edges
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it) {
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
      pedge->setBeginVertex(0);
      pedge->setEndVertex(0);

      model->remove(pedge);
      delete pedge;
    }
    else if(edge->geomType() == GEntity::GhostCurve) {
      model->remove(edge);
      delete edge;
    }
  }

  // Loop over faces
  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it) {
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

  // Loop over regions
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it) {
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
  for(GModel::piter it = physicalNames.begin(); it != physicalNames.end();
      ++it) {
    std::size_t found = it->second.find("_");
    if(found != std::string::npos) {
      model->removePhysicalGroup(it->first.first, it->first.second);
    }
  }

  return 0;
}

// Create the partition according to the element split given by elmToPartition
// Returns: 0 = success, 1 = no elements found.
int PartitionUsingThisSplit(GModel *const model, unsigned int npart,
                            hashmap<MElement *, unsigned int> &elmToPartition)
{
  Graph graph(model);
  if(MakeGraph(model, graph, -1)) return 1;
  graph.createDualGraph(false);
  graph.nparts(npart);

  if(elmToPartition.size() != graph.ne()) {
    Msg::Error("All elements are not partitioned.");
    return 1;
  }

  unsigned int *part = new unsigned int[graph.ne()];
  for(unsigned int i = 0; i < graph.ne(); i++) {
    if(graph.element(i)) { part[i] = elmToPartition[graph.element(i)] - 1; }
  }

  // Check and correct the topology
  for(int i = 1; i < 4; i++) {
    for(unsigned int j = 0; j < graph.ne(); j++) {
      if(graph.element(j)->getDim() == (int)graph.dim()) continue;

      for(unsigned int k = graph.xadj(j); k < graph.xadj(j + 1); k++) {
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

  CreateNewEntities(model, elmToPartition);
  elmToPartition.clear();

  if(CTX::instance()->mesh.partitionCreateTopology) {
    Msg::StatusBar(true, "Creating partition topology...");
    std::vector<std::set<MElement *> > boundaryElements =
      graph.getBoundaryElements();
    CreatePartitionTopology(model, boundaryElements, graph);
    boundaryElements.clear();
    AssignPhysicalName(model);
    Msg::StatusBar(true, "Done creating partition topology");
  }

  AssignMeshVertices(model);

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
int ConvertOldPartitioningToNewOne(GModel *const model)
{
  Msg::StatusBar(true, "Converting old partitioning...");

  hashmap<MElement *, unsigned int> elmToPartition;
  std::set<unsigned int> partitions;
  std::vector<GEntity *> entities;
  model->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
      MElement *e = entities[i]->getMeshElement(i);
      elmToPartition.insert(
        std::pair<MElement *, unsigned int>(e, e->getPartition()));
      partitions.insert(e->getPartition());
    }
  }

  return PartitionUsingThisSplit(model, partitions.size(), elmToPartition);
}

#else

int PartitionMesh(GModel *const model)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}

int UnpartitionMesh(GModel *const model) { return 0; }

int ConvertOldPartitioningToNewOne(GModel *const model) { return 0; }

int PartitionUsingThisSplit(GModel *const model, unsigned int npart,
                            hashmap<MElement *, unsigned int> &elmToPartition)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}

int PartitionFace(GFace *gf, int np, int *p)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}

#endif
