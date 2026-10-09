// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Anthony Royer.

#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#include "EntityTraits.h"

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
#define hashmapelementpart                                                     \
  std::unordered_map<MElement *, int, MElementPtrHash, MElementPtrEqual>
// The second member indexes a table of distinct partition lists rather than
// holding a list of its own: the lists repeat heavily (in 3D there is one per
// partition), and a one-element std::vector<int> per (element, facet) pair was
// a heap allocation for every facet of every boundary element.
typedef std::vector<std::pair<MElement *, int>> elementPartitionList;
#define hashmapvertex                                                          \
  std::unordered_map<MVertex *, elementPartitionList, MVertexPtrHash,          \
                     MVertexPtrEqual>

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
#include "MPoint.h"

extern "C" {
#include <metis.h>
}

#if defined(HAVE_MTMETIS)
#include <mtmetis.h>
#endif

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
  // The metis graph structure, in CSR form
  std::vector<idx_t> _xadj, _adjncy;
  // The weight associated to each elements of eptr
  idx_t *_vwgt;
  // Element corresponding to each graph element in eptr
  std::vector<MElement *> _element;
  // Vertex corresponding to each graph vertex in eptr
  std::vector<idx_t> _vertex;
  // When _trackVertex is set, the entries of _vertex that get used are
  // recorded, so that eraseVertex() can reset just those instead of sweeping
  // the whole (mesh-sized) array. divideNonConnectedEntities() resets between
  // every partition entity, which otherwise costs O(#entities x #nodes).
  bool _trackVertex;
  std::vector<idx_t> _usedVertex;
  // The partitions output from the partitioner, in an integer type independent
  // from METIS
  std::vector<int> _partition;
  // The model entities whose elements were added to the graph, with the index
  // of their first element: the elements of an entity are contiguous
  std::vector<std::pair<GEntity *, std::size_t>> _entityBegin;

public:
  Graph(GModel *model)
    : _model(model), _nparts(0), _ne(0), _nn(0), _dim(0), _vwgt(nullptr),
      _trackVertex(false)
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
  idx_t *xadj() { return _xadj.data(); };
  bool hasDualGraph() const { return _ne && _xadj.size() == _ne + 1; }
  idx_t adjncy(std::size_t i) const { return _adjncy[i]; };
  idx_t *adjncy() { return _adjncy.data(); };
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
  void vertex(std::size_t i, idx_t vertex)
  {
    _vertex[i] = vertex;
    if(_trackVertex) _usedVertex.push_back((idx_t)i);
  };
  void trackVertex(bool track) { _trackVertex = track; };
  void entityBegin(GEntity *entity, std::size_t i)
  { _entityBegin.push_back(std::make_pair(entity, i)); }
  const std::vector<std::pair<GEntity *, std::size_t>> &entityBegin() const
  { return _entityBegin; }
  void partition(const std::vector<idx_t> &epart)
  {
    // converts into METIS-independent integer type
    _partition.resize(epart.size());
    for(std::size_t i = 0; i < epart.size(); i++) _partition[i] = epart[i];
  };
  void clear()
  {
    clearDualGraph();
    if(_vwgt) {
      delete[] _vwgt;
      _vwgt = nullptr;
    }
  }
  void clearDualGraph()
  {
    std::vector<idx_t>().swap(_xadj);
    std::vector<idx_t>().swap(_adjncy);
  }
  void eraseVertex()
  {
    if(_trackVertex) {
      for(std::size_t i = 0; i < _usedVertex.size(); i++)
        _vertex[_usedVertex[i]] = -1;
      _usedVertex.clear();
    }
    else {
      for(std::size_t i = 0; i < _vertex.size(); i++) _vertex[i] = -1;
    }
  }
  // sorted by element number, as the std::set this used to build was; a
  // vector plus one sort avoids a tree node per boundary element
  std::vector<std::vector<MElement *> > getBoundaryElements(idx_t size = 0)
  {
    std::vector<std::vector<MElement *> > elements(size ? size : _nparts);
    for(std::size_t i = 0; i < _ne; i++) {
      if(_element[i]->getDim() != _dim) continue;
      for(idx_t j = _xadj[i]; j < _xadj[i + 1]; j++) {
        if(_partition[i] != _partition[_adjncy[j]]) {
          elements[_partition[i]].push_back(_element[i]);
          break;
        }
      }
    }
    for(std::size_t i = 0; i < elements.size(); i++)
      std::sort(elements[i].begin(), elements[i].end(), MElementPtrLessThan());

    return elements;
  }
  std::vector<GEntity *> createGhostEntities()
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
    return ghostEntities;
  }
  void assignGhostCells()
  {
    std::vector<GEntity *> ghostEntities = createGhostEntities();
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
                ->addElement(_element[i], _partition[i] + 1);
              break;
            case 2:
              static_cast<ghostFace *>(ghostEntities[_partition[_adjncy[j]]])
                ->addElement(_element[i], _partition[i] + 1);
              break;
            case 3:
              static_cast<ghostRegion *>(ghostEntities[_partition[_adjncy[j]]])
                ->addElement(_element[i], _partition[i] + 1);
              break;
            default: break;
            }
            ghostCellsPartition.insert(_partition[_adjncy[j]]);
          }
        }
      }
    }
  }
  // Builds the element-element (dual) graph in CSR form. The neighbor search
  // is done in a single pass: the previous version probed the node-element
  // adjacency twice, once to size _xadj and once to fill _adjncy.
  void createDualGraph(bool connectedAll)
  {
    // invert the element-node map into a node-element map
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

    // numCommonNodesInDualGraph() is a pure function of the pair of element
    // types, so resolve it once per type pair here instead of doing virtual
    // calls per candidate neighbor in the loop below
    std::vector<unsigned char> etype(_ne, 0);
    std::vector<MElement *> rep(TYPE_MAX_NUM + 1, nullptr);
    for(std::size_t i = 0; i < _ne; i++) {
      if(!_element[i]) continue;
      const int t = _element[i]->getType();
      etype[i] = (unsigned char)t;
      rep[t] = _element[i];
    }
    int threshold[TYPE_MAX_NUM + 1][TYPE_MAX_NUM + 1];
    for(int a = 0; a <= TYPE_MAX_NUM; a++) {
      for(int b = 0; b <= TYPE_MAX_NUM; b++) {
        threshold[a][b] = (connectedAll || !rep[a] || !rep[b]) ?
                            1 :
                            rep[a]->numCommonNodesInDualGraph(rep[b]);
      }
    }

    // The neighbors of each element are found in parallel, by chunks of
    // elements whose neighbors are stored in a buffer per chunk, and copied
    // into _adjncy at the end. The node-element map is freed before _adjncy is
    // allocated, so that the buffers do not add to the memory peak. The
    // neighbors are stored in the order in which they are first met, as when
    // this was serial.
    const int nthreads = CTX::instance()->numThreadsFor(_ne, 10000);
    const std::size_t chunkSize = 4096;
    const std::size_t numChunks = (_ne + chunkSize - 1) / chunkSize;
    std::vector<std::vector<idx_t>> chunks(numChunks);
    _xadj.assign(_ne + 1, 0);
    std::vector<idx_t>().swap(_adjncy);
#pragma omp parallel num_threads(nthreads)
    {
      // counts how many nodes each candidate neighbor shares with the element
      // being processed: a small hash table (open addressing), reset after
      // each element, instead of a mesh-sized array per thread
      struct entry {
        idx_t key;
        int count;
      };
      int bits = 10;
      std::vector<entry> table(std::size_t(1) << bits, entry{-1, 0});
      std::vector<std::size_t> slots; // in the order of the first meeting
#pragma omp for schedule(dynamic, 1)
      for(std::size_t c = 0; c < numChunks; c++) {
        std::vector<idx_t> &out = chunks[c];
        const std::size_t end = std::min(_ne, (c + 1) * chunkSize);
        for(std::size_t i = c * chunkSize; i < end; i++) {
          // a table at least twice as large as the number of candidates
          // (rarely more than a few hundred)
          std::size_t m = 0;
          for(idx_t j = _eptr[i]; j < _eptr[i + 1]; j++)
            m += nptr[_eind[j] + 1] - nptr[_eind[j]];
          if(2 * m > table.size()) {
            while((std::size_t(1) << bits) < 2 * m) bits++;
            table.assign(std::size_t(1) << bits, entry{-1, 0});
          }
          const std::size_t mask = table.size() - 1;
          slots.clear();
          for(idx_t j = _eptr[i]; j < _eptr[i + 1]; j++) {
            for(idx_t k = nptr[_eind[j]]; k < nptr[_eind[j] + 1]; k++) {
              const idx_t n = nind[k];
              if(n == (idx_t)i) continue;
              std::size_t h =
                (std::size_t)(((uint64_t)n * 0x9E3779B97F4A7C15ULL) >>
                              (64 - bits));
              while(table[h].key != -1 && table[h].key != n) h = (h + 1) & mask;
              if(table[h].key == -1) {
                table[h].key = n;
                table[h].count = 0;
                slots.push_back(h);
              }
              table[h].count++;
            }
          }
          const int *row = threshold[etype[i]];
          const std::size_t before = out.size();
          for(std::size_t j = 0; j < slots.size(); j++) {
            entry &t = table[slots[j]];
            if(t.count >= row[etype[t.key]]) out.push_back(t.key);
            t.key = -1;
          }
          _xadj[i + 1] = (idx_t)(out.size() - before);
        }
      }
    }
    std::vector<idx_t>().swap(nind);
    std::vector<idx_t>().swap(nptr);
    for(std::size_t i = 0; i < _ne; i++) _xadj[i + 1] += _xadj[i];
    _adjncy.resize(_xadj[_ne]);
#pragma omp parallel for schedule(dynamic, 1) num_threads(nthreads)
    for(std::size_t c = 0; c < numChunks; c++) {
      std::copy(chunks[c].begin(), chunks[c].end(),
                _adjncy.begin() + _xadj[c * chunkSize]);
      std::vector<idx_t>().swap(chunks[c]);
    }
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

    for(std::size_t i = 0; i < entities.size(); i++) {
      if(entities[i]->dim() == selectDim) {
        switch(entities[i]->dim()) {
        case 3: tmp->add(static_cast<GRegion *>(entities[i])); break;
        case 2: tmp->add(static_cast<GFace *>(entities[i])); break;
        case 1: tmp->add(static_cast<GEdge *>(entities[i])); break;
        case 0: tmp->add(static_cast<GVertex *>(entities[i])); break;
        default: break;
        }
      }
    }

    graph.ne(tmp->getNumMeshElements());
    graph.dim(tmp->getMeshDim());
    graph.elementResize(graph.ne());
    graph.vertexResize(model->getMaxVertexNumber());
    graph.eptrResize(graph.ne() + 1);
    graph.eptr(0, 0);
    eindSize = getSizeOfEind(tmp);
    graph.eindResize(eindSize);
    // upper bound, only used for the emptiness check below (the model's
    // mesh_vertices have been cleared by this point, so they cannot be
    // counted); the exact value is set once the elements have been walked
    graph.nn(eindSize);

    tmp->remove();
    delete tmp;
  }

  idx_t eptrIndex = 0;
  idx_t eindIndex = 0;
  idx_t numVertex = 0;

  if(graph.nn() == 0) {
    Msg::Warning("No mesh nodes were found");
    return 1;
  }
  if(graph.ne() == 0) {
    Msg::Warning("No mesh elements were found");
    return 1;
  }
  if(graph.dim() == 0) {
    Msg::Warning("Cannot partition a point");
    return 1;
  }

  // Loop over volumes
  if(selectDim < 0 || selectDim == 3) {
    for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
      GRegion *r = *it;
      graph.entityBegin(r, eptrIndex);
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
      graph.entityBegin(f, eptrIndex);
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
      graph.entityBegin(e, eptrIndex);
      fillElementsToNodesMap(graph, e, eptrIndex, eindIndex, numVertex,
                             e->lines.begin(), e->lines.end());
    }
  }

  // Loop over points
  if(selectDim < 0 || selectDim == 0) {
    for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
      GVertex *v = *it;
      graph.entityBegin(v, eptrIndex);
      fillElementsToNodesMap(graph, v, eptrIndex, eindIndex, numVertex,
                             v->points.begin(), v->points.end());
    }
  }

  // the counts above were upper bounds on the number of distinct nodes: only
  // primary vertices end up in the graph, so on a high-order mesh they
  // overestimate badly. Use the exact count, which is what sizes the
  // node-element adjacency in createDualGraph().
  graph.nn(numVertex);

  return 0;
}

// Make lower-dim elements follow the bulk they bound, adopting a higher-dim
// neighbor's partition; sweeps codim 1..3, so the highest-dimensional one wins.
static void correctTopology(const Graph &graph, std::vector<idx_t> &epart)
{
  for(int codim : {1, 2, 3}) {
    for(std::size_t j = 0; j < graph.ne(); j++) {
      const int dim = graph.element(j)->getDim();
      if(dim == graph.dim()) continue;

      for(idx_t k = graph.xadj(j); k < graph.xadj(j + 1); k++) {
        const idx_t nbr = graph.adjncy(k);
        if(graph.element(nbr)->getDim() == dim + codim &&
           epart[j] != epart[nbr]) {
          epart[j] = epart[nbr];
          break;
        }
      }
    }
  }
}

#if defined(HAVE_MTMETIS)

// Partition the dual graph with the multithreaded k-way algorithm of mt-metis,
// translating the METIS options it supports. Returns a METIS error code.
static int partitionGraphMtMetis(Graph &graph, const idx_t *metisOptions,
                                 std::vector<idx_t> &epart, idx_t &objval)
{
  const std::size_t ne = graph.ne();
  if(ne > std::numeric_limits<mtmetis_vtx_type>::max()) {
    Msg::Error("Graph too large for mt-metis (32-bit vertex indices)");
    return METIS_ERROR_INPUT;
  }
  int64_t totalWeight = ne;
  if(graph.vwgt())
    totalWeight = std::accumulate(graph.vwgt(), graph.vwgt() + ne, int64_t(0));
  if(totalWeight > std::numeric_limits<mtmetis_wgt_type>::max()) {
    Msg::Error("Total element weight too large for mt-metis (32-bit weights)");
    return METIS_ERROR_INPUT;
  }

  std::vector<double> options(MTMETIS_NOPTIONS, MTMETIS_VAL_OFF);
  options[MTMETIS_OPTION_NTHREADS] =
    CTX::instance()->numThreadsFor(ne, 10000);
  // the default seed is the time of day: fix it, as METIS does
  options[MTMETIS_OPTION_SEED] = 0;
  if(metisOptions[METIS_OPTION_UFACTOR] >= 0)
    options[MTMETIS_OPTION_UBFACTOR] =
      1. + metisOptions[METIS_OPTION_UFACTOR] / 1000.;
  if(metisOptions[METIS_OPTION_CTYPE] == METIS_CTYPE_RM)
    options[MTMETIS_OPTION_CTYPE] = MTMETIS_CTYPE_RM;
  else if(metisOptions[METIS_OPTION_CTYPE] == METIS_CTYPE_SHEM)
    options[MTMETIS_OPTION_CTYPE] = MTMETIS_CTYPE_SHEM;
  if(metisOptions[METIS_OPTION_RTYPE] == METIS_RTYPE_FM)
    options[MTMETIS_OPTION_RTYPE] = MTMETIS_RTYPE_FM;
  else if(metisOptions[METIS_OPTION_RTYPE] == METIS_RTYPE_GREEDY)
    options[MTMETIS_OPTION_RTYPE] = MTMETIS_RTYPE_GREEDY;
  else if(metisOptions[METIS_OPTION_RTYPE] != -1)
    Msg::Warning("mt-metis ignores the node FM refinement algorithms");
  if(metisOptions[METIS_OPTION_OBJTYPE] == METIS_OBJTYPE_VOL)
    Msg::Warning("mt-metis ignores the communication volume objective");
  if(metisOptions[METIS_OPTION_MINCONN] == 1)
    Msg::Warning("mt-metis ignores the 'minconn' option");

  // mt-metis takes 64-bit edge offsets (used in place when idx_t is 64-bit),
  // and 32-bit vertex indices and weights
  std::vector<mtmetis_adj_type> xadjCopy;
  const mtmetis_adj_type *xadj =
    reinterpret_cast<const mtmetis_adj_type *>(graph.xadj());
  if(sizeof(idx_t) != sizeof(mtmetis_adj_type)) {
    xadjCopy.assign(graph.xadj(), graph.xadj() + ne + 1);
    xadj = xadjCopy.data();
  }
  std::vector<mtmetis_vtx_type> adjncy(graph.adjncy(),
                                       graph.adjncy() + graph.xadj(ne));
  std::vector<mtmetis_wgt_type> vwgt;
  if(graph.vwgt()) vwgt.assign(graph.vwgt(), graph.vwgt() + ne);
  std::vector<mtmetis_pid_type> where(ne);
  mtmetis_vtx_type nvtxs = ne, ncon = 1;
  mtmetis_pid_type nparts = graph.nparts();
  mtmetis_wgt_type edgecut = 0;

  int err = MTMETIS_PartGraphKway(
    &nvtxs, &ncon, xadj, adjncy.data(), vwgt.empty() ? nullptr : vwgt.data(),
    nullptr, nullptr, &nparts, nullptr, nullptr, options.data(), &edgecut,
    where.data());

  switch(err) {
  case MTMETIS_SUCCESS: break;
  case MTMETIS_ERROR_INVALIDINPUT: return METIS_ERROR_INPUT;
  case MTMETIS_ERROR_NOTENOUGHMEMORY: return METIS_ERROR_MEMORY;
  default: return METIS_ERROR;
  }
  for(std::size_t i = 0; i < ne; i++) epart[i] = where[i];
  objval = edgecut;
  return METIS_OK;
}

#endif

// Partition a graph created by makeGraph using Metis library. Returns: 0 =
// success, 1 = error, 2 = exception thrown.
static int partitionGraph(Graph &graph, bool verbose)
{
#ifdef HAVE_METIS
  std::stringstream opt;
  try {
    idx_t metisOptions[METIS_NOPTIONS];
    METIS_SetDefaultOptions(metisOptions);

    opt << "npart:" << graph.nparts();

    opt << ", sizeof(idx_t):" << 8 * sizeof(idx_t);

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
#if defined(HAVE_MTMETIS)
    case 3: // Multithreaded k-way (mt-metis)
      metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_KWAY;
      opt << "kway (mt-metis)";
      break;
#else
    case 3:
      Msg::Warning("Gmsh was not compiled with mt-metis: using METIS K-way");
      metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_KWAY;
      opt << "kway";
      break;
#endif
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

    double t1 = TimeOfDay();
#if defined(HAVE_MTMETIS)
    if(CTX::instance()->mesh.metisAlgorithm == 3) {
      metisError = partitionGraphMtMetis(graph, metisOptions, epart, objval);
    }
    else
#endif
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
    if(verbose)
      Msg::Info("Partitioned graph of %lu vertices in %g s", graph.ne(),
                TimeOfDay() - t1);

    switch(metisError) {
    case METIS_OK: break;
    case METIS_ERROR_INPUT: Msg::Error("METIS input error"); return 1;
    case METIS_ERROR_MEMORY: Msg::Error("METIS memory error"); return 1;
    case METIS_ERROR:
    default: Msg::Error("METIS error"); return 1;
    }

    // Check that all partitions have at least one element
    std::vector<int> emptyPartitions;
    std::vector<int> partitionCount(numPart, 0);
    for(std::size_t i = 0; i < epart.size(); i++) { partitionCount[epart[i]]++; }
    for(std::size_t i = 0; i < partitionCount.size(); i++) {
      if(partitionCount[i] == 0) emptyPartitions.push_back(i + 1);
    }

    if(!emptyPartitions.empty()) {
      std::string list;
      for(std::size_t i = 0; i < emptyPartitions.size(); i++) {
        list += " " + std::to_string(emptyPartitions[i]);
      }
      Msg::Warning("METIS produced %d empty partitions:%s",
                   (int)emptyPartitions.size(), list.c_str());
    }

    // Check and correct the topology
    correctTopology(graph, epart);
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
assignElementsToEntities(GModel *model, std::vector<ENTITY *> &newEntities,
                         ITERATOR it_beg, ITERATOR it_end,
                         int &elementaryNumber)
{
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    // MElement::_partition was set when the partitions were assigned; it is an
    // int, so this is exact for any number of partitions
    int partition = (*it)->getPartition() - 1;

    if(!newEntities[partition]) {
      std::vector<int> partitions;
      partitions.push_back(partition + 1);
      ENTITY *de = new ENTITY(model, ++elementaryNumber, partitions);
      model->add(de);
      newEntities[partition] = de;
    }

    newEntities[partition]->addElement(*it);
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

// Splits the graph into connected components. The previous implementation
// accumulated each component into a std::set<MElement *> and then deep-copied
// it into the output, and it consumed _adjncy as it went (writing 0 over the
// entries it had followed), which forced an O(#components x ne) rescan to find
// the next seed. This keeps a visited flag instead and leaves the graph
// intact.
//
// The seed order is preserved exactly, quirks included: index 0 doubles as
// both a valid element and the "no edge" marker in _adjncy, so an element is
// only ever seeded from if it has an adjacency entry that is not 0, and
// elements with no edges at all are picked up afterwards, in index order,
// starting at index 1.
static void fillConnectedElements(
  std::vector<std::vector<MElement *> > &connectedElements, Graph &graph)
{
  if(graph.ne() < 2) return;

  std::vector<char> visited(graph.ne(), 0);
  std::vector<idx_t> stack;
  std::vector<MElement *> elements;

  idx_t startElement = 0;
  std::size_t cursor = 0;
  idx_t isolatedElements = 0;
  std::size_t covered = 0;

  while(true) {
    stack.push_back(startElement);
    visited[startElement] = 1;
    elements.push_back(graph.element(startElement));

    while(!stack.empty()) {
      const idx_t top = stack.back();
      stack.pop_back();
      for(idx_t i = graph.xadj(top); i < graph.xadj(top + 1); i++) {
        const idx_t n = graph.adjncy(i);
        if(n == 0 || visited[n]) continue;
        visited[n] = 1;
        elements.push_back(graph.element(n));
        stack.push_back(n);
      }
    }

    std::sort(elements.begin(), elements.end(), MElementPtrLessThan());
    covered += elements.size();
    connectedElements.push_back(std::vector<MElement *>());
    connectedElements.back().swap(elements);

    if(covered >= graph.ne()) break;

    // next seed: the first element not yet reached that has at least one
    // adjacency entry different from 0. Eligibility only ever goes away, so a
    // moving cursor visits each element at most once overall.
    startElement = 0;
    while(cursor < graph.ne()) {
      if(!visited[cursor]) {
        bool hasEdge = false;
        for(idx_t j = graph.xadj(cursor); j < graph.xadj(cursor + 1); j++) {
          if(graph.adjncy(j) != 0) {
            hasEdge = true;
            break;
          }
        }
        if(hasEdge) break;
      }
      cursor++;
    }
    if(cursor < graph.ne()) { startElement = (idx_t)cursor; }
    else {
      // only elements without any edge are left
      idx_t skipIsolatedElements = 0;
      for(std::size_t i = 1; i < graph.ne(); i++) {
        if(graph.xadj(i) == graph.xadj(i + 1)) {
          if(skipIsolatedElements == isolatedElements) {
            startElement = (idx_t)i;
            isolatedElements++;
            break;
          }
          skipIsolatedElements++;
        }
      }
    }
    // nothing left to seed from: the remaining elements, if any, are
    // unreachable (the previous implementation looped forever here)
    if(startElement == 0) break;
  }
}

// The connected components of the partition entities that are not connected
typedef std::unordered_map<GEntity *, std::vector<std::vector<MElement *>>>
  componentMap;

// Finds the partition entities created by createNewEntities() that are not
// connected, in a single pass over the dual graph of the whole mesh, instead
// of building a graph for every partition entity: the partition entity of
// model entity e in partition p holds the elements of e in p, so its
// components are those of the subgraph made of these elements. The components
// and their elements are listed in the order of fillConnectedElements() on
// the graph of the partition entity: first the component of its first
// element, then the other components by first element, then the isolated
// elements, each component being sorted. partitionEntities gives, for each
// model entity, its partition entity in each partition. Without it, the
// entities of the graph are themselves the partition entities, whose
// components are found.
static void findPartitionComponents(
  Graph &graph,
  const std::map<GEntity *, std::vector<GEntity *>> *partitionEntities,
  componentMap &components)
{
  const std::vector<std::pair<GEntity *, std::size_t>> &begin =
    graph.entityBegin();
  // component of each element, numbered from 0 in each model entity
  std::vector<int> comp(graph.ne(), -1);
  std::vector<idx_t> stack;

  for(std::size_t r = 0; r < begin.size(); r++) {
    // points are divided element by element anyway
    if(begin[r].first->dim() == 0) continue;
    const std::vector<GEntity *> *inPartition = nullptr;
    if(partitionEntities) {
      auto itp = partitionEntities->find(begin[r].first);
      if(itp == partitionEntities->end()) continue;
      inPartition = &itp->second;
    }
    const std::size_t first = begin[r].second;
    const std::size_t last =
      (r + 1 < begin.size()) ? begin[r + 1].second : graph.ne();

    // label the components of the model entity, partition by partition: a
    // depth-first search from each element not yet reached, through the
    // neighbors of the same entity in the same partition
    std::vector<std::size_t> size;
    std::map<int, std::vector<int>> compOfPartition;
    for(std::size_t i = first; i < last; i++) {
      if(!graph.element(i) || comp[i] >= 0) continue;
      const int part = inPartition ? graph.element(i)->getPartition() : 0;
      const int c = (int)size.size();
      size.push_back(0);
      compOfPartition[part].push_back(c);
      comp[i] = c;
      stack.push_back(i);
      while(!stack.empty()) {
        const idx_t top = stack.back();
        stack.pop_back();
        size[c]++;
        for(idx_t j = graph.xadj(top); j < graph.xadj(top + 1); j++) {
          const idx_t n = graph.adjncy(j);
          if((std::size_t)n < first || (std::size_t)n >= last || comp[n] >= 0 ||
             !graph.element(n) ||
             (inPartition && graph.element(n)->getPartition() != part))
            continue;
          comp[n] = c;
          stack.push_back(n);
        }
      }
    }

    // the partitions where the model entity is not connected: the position
    // of each of their components in the list of the partition entity
    std::vector<int> slot(size.size(), -1);
    std::vector<std::vector<MElement *> *> target(size.size(), nullptr);
    for(auto it = compOfPartition.begin(); it != compOfPartition.end(); ++it) {
      const std::vector<int> &c = it->second;
      if(c.size() < 2) continue;
      GEntity *pe =
        inPartition ? (*inPartition)[it->first - 1] : begin[r].first;
      std::vector<std::vector<MElement *>> &list = components[pe];
      list.resize(c.size());
      // isolated elements (components of size 1) come last, except the first
      int k = 0;
      for(std::size_t j = 0; j < c.size(); j++)
        if(j == 0 || size[c[j]] > 1) slot[c[j]] = k++;
      for(std::size_t j = 1; j < c.size(); j++)
        if(size[c[j]] == 1) slot[c[j]] = k++;
      for(std::size_t j = 0; j < c.size(); j++) {
        list[slot[c[j]]].reserve(size[c[j]]);
        target[c[j]] = &list[slot[c[j]]];
      }
    }
    for(std::size_t i = first; i < last; i++) {
      if(graph.element(i) && target[comp[i]])
        target[comp[i]]->push_back(graph.element(i));
    }
    for(std::size_t c = 0; c < target.size(); c++) {
      if(target[c])
        std::sort(target[c]->begin(), target[c]->end(), MElementPtrLessThan());
    }
  }
}

// When a partition entity turns out to be non-connected and is split into
// several components, the BRep of the original entity must not simply be
// copied to every component: a component only bounds a neighboring entity if
// its own mesh actually touches that neighbor. This records, for every
// component, the neighbors it was found to touch, so that the BRep can be
// distributed among the components instead of duplicated onto all of them.
// The components claim their boundary keys (faces for surfaces, edges for
// curves), then the candidate neighbors are probed in a single pass.
// The facets (faces in 3D, edges in 2D) of an element
static int getNumFacets(MElement *e, MFace *) { return e->getNumFaces(); }
static int getNumFacets(MElement *e, MEdge *) { return e->getNumEdges(); }
static MFace getFacet(MElement *e, int i, MFace *) { return e->getFace(i); }
static MEdge getFacet(MElement *e, int i, MEdge *) { return e->getEdge(i); }

template <class KEY, class HASH, class EQUAL> class BRepDistributor {
private:
  std::unordered_map<KEY, std::size_t, HASH, EQUAL> _owner;
  std::vector<std::set<GEntity *, GEntityPtrFullLessThan> > _bounds;

public:
  std::size_t newComponent()
  {
    _bounds.resize(_bounds.size() + 1);
    return _bounds.size() - 1;
  }
  void claim(const KEY &key, std::size_t component)
  {
    _owner.insert(std::make_pair(key, component));
  }
  // Probes the facets of all the elements of the candidate neighbors, in
  // parallel: the owners are only read, the hits are merged at the end
  template <class SET> void probeAll(const SET &candidates)
  {
    std::vector<GEntity *> cand(candidates.begin(), candidates.end());
    std::vector<std::size_t> offset(cand.size() + 1, 0);
    for(std::size_t i = 0; i < cand.size(); i++)
      offset[i + 1] = offset[i] + cand[i]->getNumMeshElements();
    const std::size_t chunkSize = 4096;
    const std::size_t numChunks = (offset.back() + chunkSize - 1) / chunkSize;
    std::set<std::pair<std::size_t, std::size_t>> hits; // component, cand.
    const int nthreads = CTX::instance()->numThreadsFor(offset.back(), 10000);
#pragma omp parallel num_threads(nthreads)
    {
      std::set<std::pair<std::size_t, std::size_t>> myHits;
#pragma omp for schedule(dynamic, 1)
      for(std::size_t c = 0; c < numChunks; c++) {
        const std::size_t end = std::min(offset.back(), (c + 1) * chunkSize);
        std::size_t k =
          std::upper_bound(offset.begin(), offset.end(), c * chunkSize) -
          offset.begin() - 1;
        for(std::size_t i = c * chunkSize; i < end; i++) {
          while(i >= offset[k + 1]) k++;
          MElement *e = cand[k]->getMeshElement(i - offset[k]);
          for(int j = 0; j < getNumFacets(e, (KEY *)nullptr); j++) {
            auto it = _owner.find(getFacet(e, j, (KEY *)nullptr));
            if(it != _owner.end()) myHits.insert(std::make_pair(it->second, k));
          }
        }
      }
#pragma omp critical
      hits.insert(myHits.begin(), myHits.end());
    }
    for(auto it = hits.begin(); it != hits.end(); ++it)
      _bounds[it->first].insert(cand[it->second]);
  }
  bool touches(std::size_t component, GEntity *neighbor) const
  {
    return _bounds[component].find(neighbor) != _bounds[component].end();
  }
  bool empty() const { return _owner.empty(); }
};

// The per-entity graphs below are reused from one partition entity to the
// next, so they only need to be as large as the largest single entity, not as
// large as the whole mesh: sizing them from the model made every dimension
// allocate and zero a mesh-sized eind array.
template <class ENTITY, class ITERATOR>
static void maxEntitySize(ITERATOR it_beg, ITERATOR it_end, int geomType,
                          std::size_t &maxElements, std::size_t &maxEind)
{
  maxElements = 0;
  maxEind = 0;
  for(ITERATOR it = it_beg; it != it_end; ++it) {
    if((*it)->geomType() != geomType) continue;
    std::size_t ne = (*it)->getNumMeshElements(), eind = 0;
    for(std::size_t i = 0; i < ne; i++)
      eind += (*it)->getMeshElement(i)->getNumPrimaryVertices();
    maxElements = std::max(maxElements, ne);
    maxEind = std::max(maxEind, eind);
  }
}

// Divides the partition entities of dimension dim (all if dim < 0) that are
// not connected. Their components are found on a graph built for each entity,
// unless they are given in components (see findPartitionComponents()), in
// which case the entities not listed there are connected.
static bool
divideNonConnectedEntities(GModel *model, int dim,
                           std::set<GRegion *, GEntityPtrLessThan> &regions,
                           std::set<GFace *, GEntityPtrLessThan> &faces,
                           std::set<GEdge *, GEntityPtrLessThan> &edges,
                           std::set<GVertex *, GEntityPtrLessThan> &vertices,
                           componentMap *components = nullptr)
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
          // Capture the B-Rep before any of it gets rewired below
          std::vector<GEdge *> BRepEdges = vertex->edges();
          std::vector<GEdge *> beginOf, endOf;
          for(auto itBRep = BRepEdges.begin(); itBRep != BRepEdges.end();
              ++itBRep) {
            if(vertex == (*itBRep)->getBeginVertex()) beginOf.push_back(*itBRep);
            if(vertex == (*itBRep)->getEndVertex()) endOf.push_back(*itBRep);
          }
          // A component only bounds a curve if its node is an extremity of
          // that curve's mesh: nodes interior to the chain do not bound it
          std::map<GEdge *, std::set<MVertex *> > extremities;
          for(auto itBRep = BRepEdges.begin(); itBRep != BRepEdges.end();
              ++itBRep) {
            if(extremities.find(*itBRep) != extremities.end()) continue;
            std::map<MVertex *, int> count;
            for(std::size_t j = 0; j < (*itBRep)->lines.size(); j++) {
              count[(*itBRep)->lines[j]->getVertex(0)]++;
              count[(*itBRep)->lines[j]->getVertex(1)]++;
            }
            // a node bounds the chain unless it is interior to it, i.e.
            // unless exactly two lines meet there (non-manifold junctions,
            // where three or more lines meet, do bound it)
            std::set<MVertex *> &ext = extremities[*itBRep];
            for(auto itC = count.begin(); itC != count.end(); ++itC)
              if(itC->second != 2) ext.insert(itC->first);
          }
          std::vector<partitionVertex *> created;
          std::vector<MVertex *> createdNodes;

          for(std::size_t i = 0; i < vertex->getNumMeshElements(); i++) {
            // Create the new partitionVertex
            partitionVertex *pvertex = new partitionVertex(
              model, ++elementaryNumber, vertex->getPartitions());
            // Assign parent entity
            pvertex->setParentEntity(vertex->getParentEntity());
            // Add to model
            model->add(pvertex);
            // Add elements
            MElement *point = vertex->getMeshElement(i);
            pvertex->addElement(point);
            created.push_back(pvertex);
            createdNodes.push_back(point->getVertex(0));
          }

          // Move B-Rep: hand each curve to the component that actually
          // terminates it, instead of to all of them. If no component does
          // (the original B-Rep was already questionable), fall back to the
          // previous behaviour and give it to the first one.
          for(int slot = 0; slot < 2; slot++) {
            std::vector<GEdge *> &brep = slot ? endOf : beginOf;
            for(auto itBRep = brep.begin(); itBRep != brep.end(); ++itBRep) {
              const std::set<MVertex *> &ext = extremities[*itBRep];
              std::size_t pick = created.size();
              for(std::size_t i = 0; i < created.size(); i++) {
                if(ext.find(createdNodes[i]) != ext.end()) {
                  pick = i;
                  break;
                }
              }
              if(pick == created.size()) pick = 0;
              (*itBRep)->setVertex(created[pick], slot ? -1 : 1);
              created[pick]->addEdge(*itBRep);
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
    // We build a graph, unless the components are given
    Graph graph(model);
    if(!components) {
      std::size_t maxElements = 0, maxEind = 0;
      maxEntitySize<GEdge>(edges.begin(), edges.end(), GEntity::PartitionCurve,
                           maxElements, maxEind);
      graph.ne(maxElements);
      graph.nn(model->getNumMeshVertices(1));
      graph.dim(model->getMeshDim());
      graph.elementResize(maxElements);
      graph.vertexResize(model->getMaxVertexNumber());
      graph.eptrResize(maxElements + 1);
      graph.eptr(0, 0);
      graph.eindResize(maxEind);
      // reset only the entries actually used by each entity
      graph.trackVertex(true);
    }

    int elementaryNumber = model->getMaxElementaryNumber(1);

    // The split entities are created in a second pass, so that the B-Rep of
    // the originals can be distributed among the components rather than
    // copied to each of them
    struct PendingEdgeSplit {
      partitionEdge *edge;
      std::vector<GFace *> brep;
      std::vector<int> orientations;
      std::vector<std::size_t> components;
      std::vector<std::vector<MElement *> > elements;
    };
    std::vector<PendingEdgeSplit> pending;
    BRepDistributor<MEdge, MEdgeHash, MEdgeEqual> distributor;

    for(auto it = edges.begin(); it != edges.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionCurve) {
        partitionEdge *edge = static_cast<partitionEdge *>(*it);

        std::vector<std::vector<MElement *>> connectedElements;
        if(components) {
          auto itc = components->find(edge);
          if(itc == components->end()) continue;
          connectedElements.swap(itc->second);
        }
        else {
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

          fillConnectedElements(connectedElements, graph);
        }

        if(connectedElements.size() > 1) {
          ret = true;
          PendingEdgeSplit split;
          split.edge = edge;
          split.brep = edge->faces();
          split.orientations.reserve(split.brep.size());
          for(auto itBRep = split.brep.begin(); itBRep != split.brep.end();
              ++itBRep) {
            split.orientations.push_back((*itBRep)->delEdge(edge));
          }
          for(std::size_t i = 0; i < connectedElements.size(); i++) {
            std::size_t comp = distributor.newComponent();
            split.components.push_back(comp);
            for(std::size_t j = 0; j < connectedElements[i].size(); j++)
              distributor.claim(connectedElements[i][j]->getEdge(0), comp);
            split.elements.push_back(std::vector<MElement *>());
            split.elements.back().swap(connectedElements[i]);
          }
          pending.push_back(split);
        }

        connectedElements.clear();
      }
    }

    // Probe the candidate surfaces once, to find out which component each of
    // them is actually bounded by
    if(!pending.empty()) {
      std::set<GFace *, GEntityPtrFullLessThan> candidates;
      for(std::size_t i = 0; i < pending.size(); i++)
        candidates.insert(pending[i].brep.begin(), pending[i].brep.end());
      distributor.probeAll(candidates);
    }

    for(std::size_t p = 0; p < pending.size(); p++) {
      PendingEdgeSplit &split = pending[p];
      for(std::size_t i = 0; i < split.components.size(); i++) {
        // Create the new partitionEdge
        partitionEdge *pedge =
          new partitionEdge(model, ++elementaryNumber, nullptr, nullptr,
                            split.edge->getPartitions());
        // Assign parent entity
        pedge->setParentEntity(split.edge->getParentEntity());
        // Add to model
        model->add(pedge);
        // Add elements
        for(std::size_t j = 0; j < split.elements[i].size(); j++)
          pedge->addElement(split.elements[i][j]);
        // Move B-Rep: only to the surfaces this component really bounds
        for(std::size_t j = 0; j < split.brep.size(); j++) {
          if(!distributor.touches(split.components[i], split.brep[j])) continue;
          split.brep[j]->setEdge(pedge, split.orientations[j]);
          pedge->addFace(split.brep[j]);
        }
      }

      model->remove(split.edge);
      split.edge->lines.clear();
      split.edge->mesh_vertices.clear();
      delete split.edge;
    }
  }

  // Loop over surfaces
  if(dim < 0 || dim == 2) {
    // We build a graph, unless the components are given
    Graph graph(model);
    if(!components) {
      std::size_t maxElements = 0, maxEind = 0;
      maxEntitySize<GFace>(faces.begin(), faces.end(),
                           GEntity::PartitionSurface, maxElements, maxEind);
      graph.ne(maxElements);
      graph.nn(model->getNumMeshVertices(2));
      graph.dim(model->getMeshDim());
      graph.elementResize(maxElements);
      graph.vertexResize(model->getMaxVertexNumber());
      graph.eptrResize(maxElements + 1);
      graph.eptr(0, 0);
      graph.eindResize(maxEind);
      // reset only the entries actually used by each entity
      graph.trackVertex(true);
    }

    int elementaryNumber = model->getMaxElementaryNumber(2);

    // The split entities are created in a second pass, so that the B-Rep of
    // the originals can be distributed among the components rather than
    // copied to each of them
    struct PendingFaceSplit {
      partitionFace *face;
      std::vector<GRegion *> brep;
      std::vector<int> orientations;
      std::vector<std::size_t> components;
      std::vector<std::vector<MElement *> > elements;
    };
    std::vector<PendingFaceSplit> pending;
    BRepDistributor<MFace, MFaceHash, MFaceEqual> distributor;

    for(auto it = faces.begin(); it != faces.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionSurface) {
        partitionFace *face = static_cast<partitionFace *>(*it);

        std::vector<std::vector<MElement *>> connectedElements;
        if(components) {
          auto itc = components->find(face);
          if(itc == components->end()) continue;
          connectedElements.swap(itc->second);
        }
        else {
          graph.ne(face->getNumMeshElements());
          graph.dim(2);
          graph.eptr(0, 0);
          graph.clearDualGraph();
          graph.eraseVertex();

          idx_t eptrIndex = 0;
          idx_t eindIndex = 0;
          idx_t numVertex = 0;

          fillElementsToNodesMap(graph, face, eptrIndex, eindIndex, numVertex,
                                 face->triangles.begin(),
                                 face->triangles.end());
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

          fillConnectedElements(connectedElements, graph);
        }

        if(connectedElements.size() > 1) {
          ret = true;
          PendingFaceSplit split;
          split.face = face;
          std::list<GRegion *> BRepRegions = face->regions();
          split.brep.assign(BRepRegions.begin(), BRepRegions.end());
          split.orientations.reserve(split.brep.size());
          for(std::size_t j = 0; j < split.brep.size(); j++) {
            split.orientations.push_back(split.brep[j]->delFace(face));
          }
          for(std::size_t i = 0; i < connectedElements.size(); i++) {
            std::size_t comp = distributor.newComponent();
            split.components.push_back(comp);
            for(std::size_t j = 0; j < connectedElements[i].size(); j++)
              distributor.claim(connectedElements[i][j]->getFace(0), comp);
            split.elements.push_back(std::vector<MElement *>());
            split.elements.back().swap(connectedElements[i]);
          }
          pending.push_back(split);
        }

        connectedElements.clear();
      }
    }

    // Probe the candidate volumes once, to find out which component each of
    // them is actually bounded by
    if(!pending.empty()) {
      std::set<GRegion *, GEntityPtrFullLessThan> candidates;
      for(std::size_t i = 0; i < pending.size(); i++)
        candidates.insert(pending[i].brep.begin(), pending[i].brep.end());
      distributor.probeAll(candidates);
    }

    for(std::size_t p = 0; p < pending.size(); p++) {
      PendingFaceSplit &split = pending[p];
      for(std::size_t i = 0; i < split.components.size(); i++) {
        // Create the new partitionFace
        partitionFace *pface = new partitionFace(model, ++elementaryNumber,
                                                 split.face->getPartitions());
        // Assign parent entity
        pface->setParentEntity(split.face->getParentEntity());
        // Add to model
        model->add(pface);
        // Add elements
        for(std::size_t j = 0; j < split.elements[i].size(); j++)
          pface->addElement(split.elements[i][j]);
        // Move B-Rep: only to the volumes this component really bounds
        for(std::size_t j = 0; j < split.brep.size(); j++) {
          if(!distributor.touches(split.components[i], split.brep[j])) continue;
          split.brep[j]->setFace(pface, split.orientations[j]);
          pface->addRegion(split.brep[j]);
        }
      }

      model->remove(split.face);
      split.face->triangles.clear();
      split.face->quadrangles.clear();
      split.face->mesh_vertices.clear();
      delete split.face;
    }
  }

  // Loop over volumes
  if(dim < 0 || dim == 3) {
    // We build a graph, unless the components are given
    Graph graph(model);
    if(!components) {
      std::size_t maxElements = 0, maxEind = 0;
      maxEntitySize<GRegion>(regions.begin(), regions.end(),
                             GEntity::PartitionVolume, maxElements, maxEind);
      graph.ne(maxElements);
      graph.nn(model->getNumMeshVertices(3));
      graph.dim(model->getMeshDim());
      graph.elementResize(maxElements);
      graph.vertexResize(model->getMaxVertexNumber());
      graph.eptrResize(maxElements + 1);
      graph.eptr(0, 0);
      graph.eindResize(maxEind);
      // reset only the entries actually used by each entity
      graph.trackVertex(true);
    }

    int elementaryNumber = model->getMaxElementaryNumber(3);

    for(auto it = regions.begin(); it != regions.end(); ++it) {
      if((*it)->geomType() == GEntity::PartitionVolume) {
        partitionRegion *region = static_cast<partitionRegion *>(*it);

        std::vector<std::vector<MElement *>> connectedElements;
        if(components) {
          auto itc = components->find(region);
          if(itc == components->end()) continue;
          connectedElements.swap(itc->second);
        }
        else {
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

          fillConnectedElements(connectedElements, graph);
        }

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
              pregion->addElement((*itSet));
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

// Create the new volume entities (omega). If the dual graph of the whole mesh
// is given, the partition entities that are not connected are found on it.
static void createNewEntities(GModel *model, Graph *graph = nullptr)
{
  // the partition entities of each model entity, in each partition
  std::map<GEntity *, std::vector<GEntity *>> partitionEntities;

  std::set<GRegion *, GEntityPtrLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityPtrLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityPtrLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityPtrLessThan> vertices = model->getVertices();

  int elementaryNumber = model->getMaxElementaryNumber(0);
  for(auto it = vertices.begin(); it != vertices.end(); ++it) {
    std::vector<partitionVertex *> newVertices(model->getNumPartitions(),
                                               nullptr);

    assignElementsToEntities(model, newVertices,
                             (*it)->points.begin(), (*it)->points.end(),
                             elementaryNumber);

    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newVertices[i]) {
        static_cast<partitionVertex *>(newVertices[i])->setParentEntity((*it));
      }
    }
    partitionEntities[*it].assign(newVertices.begin(), newVertices.end());

    (*it)->mesh_vertices.clear();

    (*it)->points.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(1);
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    std::vector<partitionEdge *> newEdges(model->getNumPartitions(), nullptr);

    assignElementsToEntities(model, newEdges,
                             (*it)->lines.begin(), (*it)->lines.end(),
                             elementaryNumber);

    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newEdges[i]) {
        static_cast<partitionEdge *>(newEdges[i])->setParentEntity(*it);
      }
    }
    partitionEntities[*it].assign(newEdges.begin(), newEdges.end());

    (*it)->mesh_vertices.clear();

    (*it)->lines.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(2);
  for(auto it = faces.begin(); it != faces.end(); ++it) {
    std::vector<partitionFace *> newFaces(model->getNumPartitions(), nullptr);

    assignElementsToEntities(model, newFaces,
                             (*it)->triangles.begin(), (*it)->triangles.end(),
                             elementaryNumber);
    assignElementsToEntities(model, newFaces,
                             (*it)->quadrangles.begin(),
                             (*it)->quadrangles.end(), elementaryNumber);

    std::list<GRegion *> BRepRegions = (*it)->regions();
    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newFaces[i]) {
        static_cast<partitionFace *>(newFaces[i])->setParentEntity(*it);
      }
    }
    partitionEntities[*it].assign(newFaces.begin(), newFaces.end());

    (*it)->mesh_vertices.clear();

    (*it)->triangles.clear();
    (*it)->quadrangles.clear();
  }

  elementaryNumber = model->getMaxElementaryNumber(3);
  for(auto it = regions.begin(); it != regions.end(); ++it) {
    std::vector<partitionRegion *> newRegions(model->getNumPartitions(),
                                              nullptr);

    assignElementsToEntities(model, newRegions,
                             (*it)->tetrahedra.begin(), (*it)->tetrahedra.end(),
                             elementaryNumber);
    assignElementsToEntities(model, newRegions,
                             (*it)->hexahedra.begin(), (*it)->hexahedra.end(),
                             elementaryNumber);
    assignElementsToEntities(model, newRegions,
                             (*it)->prisms.begin(), (*it)->prisms.end(),
                             elementaryNumber);
    assignElementsToEntities(model, newRegions,
                             (*it)->pyramids.begin(), (*it)->pyramids.end(),
                             elementaryNumber);
    assignElementsToEntities(model, newRegions,
                             (*it)->trihedra.begin(), (*it)->trihedra.end(),
                             elementaryNumber);

    for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
      if(newRegions[i]) {
        static_cast<partitionRegion *>(newRegions[i])->setParentEntity(*it);
      }
    }
    partitionEntities[*it].assign(newRegions.begin(), newRegions.end());

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
  if(graph && graph->hasDualGraph()) {
    componentMap components;
    findPartitionComponents(*graph, &partitionEntities, components);
    divideNonConnectedEntities(model, -1, regions, faces, edges, vertices,
                               &components);
  }
  else {
    divideNonConnectedEntities(model, -1, regions, faces, edges, vertices);
  }
}

// The entity of each element. Element numbers are usually dense, so the
// entities are stored in an array indexed by element number, which is filled
// in parallel and uses less memory than a hash map; a hash map is only used
// if the numbering is sparse.
class elementEntityMap {
private:
  std::vector<GEntity *> _byNum;
  std::unordered_map<MElement *, GEntity *, MElementPtrHash, MElementPtrEqual>
    _map;

public:
  GEntity *get(MElement *e) const
  {
    if(!_byNum.empty())
      return e->getNum() < _byNum.size() ? _byNum[e->getNum()] : nullptr;
    auto it = _map.find(e);
    return it == _map.end() ? nullptr : it->second;
  }
  void clear()
  {
    std::vector<GEntity *>().swap(_byNum);
    _map.clear();
  }
  // fills the map with the elements of the entities of dimension dim (all if
  // dim < 0)
  void fill(GModel *model, int dim)
  {
    clear();
    std::vector<GEntity *> entities;
    model->getEntities(entities, dim);
    std::vector<std::size_t> offset(entities.size() + 1, 0);
    for(std::size_t i = 0; i < entities.size(); i++)
      offset[i + 1] = offset[i] + entities[i]->getNumMeshElements();
    const std::size_t num = offset.back();
    const std::size_t maxNum = model->getMaxElementNumber();
    if(maxNum > 2 * num + 1000000) {
      _map.reserve(num);
      for(std::size_t i = 0; i < entities.size(); i++)
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
          _map.insert(
            std::make_pair(entities[i]->getMeshElement(j), entities[i]));
      return;
    }
    _byNum.assign(maxNum + 1, nullptr);
    const std::size_t chunkSize = 4096;
    const std::size_t numChunks = (num + chunkSize - 1) / chunkSize;
    const int nthreads = CTX::instance()->numThreadsFor(num, 100000);
#pragma omp parallel for schedule(dynamic, 1) num_threads(nthreads)
    for(std::size_t c = 0; c < numChunks; c++) {
      const std::size_t end = std::min(num, (c + 1) * chunkSize);
      std::size_t k =
        std::upper_bound(offset.begin(), offset.end(), c * chunkSize) -
        offset.begin() - 1;
      for(std::size_t i = c * chunkSize; i < end; i++) {
        while(i >= offset[k + 1]) k++;
        MElement *e = entities[k]->getMeshElement(i - offset[k]);
        if(e->getNum() < _byNum.size()) _byNum[e->getNum()] = entities[k];
      }
    }
  }
};

static MElement *getReferenceElement(
  const elementPartitionList &pairs,
  const std::vector<std::vector<int> > &partitionLists)
{
  std::vector<std::pair<MElement *, std::vector<int> > > elementPairs;
  elementPairs.reserve(pairs.size());
  for(std::size_t i = 0; i < pairs.size(); i++)
    elementPairs.push_back(
      std::make_pair(pairs[i].first, partitionLists[pairs[i].second]));

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

static void
getPartitionInVector(std::vector<int> &partitions,
                     const elementPartitionList &boundaryPair,
                     const std::vector<std::vector<int> > &partitionLists)
{
  for(std::size_t i = 0; i < boundaryPair.size(); i++) {
    const std::vector<int> &list = partitionLists[boundaryPair[i].second];
    for(std::size_t j = 0; j < list.size(); j++) {
      if(std::find(partitions.begin(), partitions.end(), list[j]) ==
         partitions.end()) {
        partitions.push_back(list[j]);
      }
    }
  }

  std::sort(partitions.begin(), partitions.end());
}

// Partition entities are looked up by their partition list. This used to be
// keyed on a heap-constructed PART_ENTITY used purely as a probe, which meant
// building and destroying a full GFace/GEdge/GVertex for every interface
// facet of the mesh. A partition entity is also distinguished by the entity
// of its reference element, and, if given, by the entity on the other side
// (a partition surface between two volumes can only bound two volumes).
template <class PART_ENTITY> struct partitionEntityEntry {
  GEntity *reference, *other;
  PART_ENTITY *entity;
};
template <class PART_ENTITY>
using partitionEntityMap =
  std::map<std::vector<int>, std::vector<partitionEntityEntry<PART_ENTITY>>>;

template <class PART_ENTITY>
static PART_ENTITY *createPartitionEntity(
  GModel *model, int &numEntity, const std::vector<int> &partitions,
  GEntity *referenceEntity, PART_ENTITY **newEntity,
  partitionEntityMap<PART_ENTITY> &pentities, GEntity *otherEntity = nullptr)
{
  std::vector<partitionEntityEntry<PART_ENTITY>> &same = pentities[partitions];
  for(std::size_t i = 0; i < same.size(); i++)
    if(same[i].reference == referenceEntity && same[i].other == otherEntity)
      return same[i].entity;

  // Create new entity and add it to the model
  PART_ENTITY *ppe = new PART_ENTITY(model, ++numEntity, partitions);
  ppe->setParentEntity(referenceEntity->getParentEntity());
  partitionEntityEntry<PART_ENTITY> entry = {referenceEntity, otherEntity, ppe};
  same.push_back(entry);
  model->add(ppe);
  *newEntity = ppe;

  return ppe;
}

static partitionVertex *
assignPartitionBoundary(GModel *model, MVertex *ve, MElement *reference,
                        const std::vector<int> &partitions,
                        partitionEntityMap<partitionVertex> &pvertices,
                        const elementEntityMap &elementToEntity, int &numEntity)
{
  partitionVertex *newEntity = nullptr;
  partitionVertex *ppv = createPartitionEntity(model, numEntity, partitions,
                                               elementToEntity.get(reference),
                                               &newEntity, pvertices);

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
  // a zero orientation means the entities are not incident, which cannot
  // happen on a conformal mesh (see assignNewEntityBRep)
  if(e->dim() == 2) {
    partitionFace *entity = static_cast<partitionFace *>(e);

    for(auto it = boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      const int ori = computeOrientation(it->second, entity->getMeshElement(0));
      if(!ori) continue;
      static_cast<GRegion *>(it->first)->setFace(entity, ori);
      entity->addRegion(static_cast<GRegion *>(it->first));
    }
  }
  else if(e->dim() == 1) {
    partitionEdge *entity = static_cast<partitionEdge *>(e);

    for(auto it = boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      const int ori = computeOrientation(it->second, entity->getMeshElement(0));
      if(!ori) continue;
      static_cast<GFace *>(it->first)->setEdge(entity, ori);
      entity->addFace(static_cast<GFace *>(it->first));
    }
  }
  else if(e->dim() == 0) {
    partitionVertex *entity = static_cast<partitionVertex *>(e);

    for(auto it = boundaryEntityAndRefElement.begin();
        it != boundaryEntityAndRefElement.end(); ++it) {
      const int ori = computeOrientation(it->second, entity->getMeshElement(0));
      if(!ori) continue;
      static_cast<GEdge *>(it->first)->setVertex(entity, ori);
      entity->addEdge(static_cast<GEdge *>(it->first));
    }
  }
}

// Whether the element has all the nodes of the facet, i.e. shares the facet
// (as MFace and MEdge compare their nodes), without building its facets
template <class FACET> static bool hasFacet(MElement *e, const FACET &f)
{
  const std::size_t n = e->getNumPrimaryVertices();
  for(std::size_t i = 0; i < f.getNumVertices(); i++) {
    MVertex *v = f.getVertex(i);
    std::size_t j = 0;
    while(j < n && e->getVertex(j) != v) j++;
    if(j == n) return false;
  }
  return true;
}

// Records that the partition entity pe (a face or an edge) bounds the entity
// of the mesh dimension b
static void addPartitionBoundary(GEntity *b, GEntity *pe, int ori)
{
  if(pe->dim() == 2) {
    static_cast<GRegion *>(b)->setFace(static_cast<partitionFace *>(pe), ori);
    static_cast<partitionFace *>(pe)->addRegion(static_cast<GRegion *>(b));
  }
  else if(pe->dim() == 1) {
    static_cast<GFace *>(b)->setEdge(static_cast<partitionEdge *>(pe), ori);
    static_cast<partitionEdge *>(pe)->addFace(static_cast<GFace *>(b));
  }
}

// Creates the element of the facet k of the reference element, numbered num
static MElement *createFacetElement(MElement *reference, int k, int num,
                                    MFace *)
{
  std::vector<MVertex *> verts;
  reference->getFaceVertices(k, verts);
  if(reference->getFace(k).getNumVertices() == 3) {
    if(verts.size() == 3) return new MTriangle(verts, num);
    if(verts.size() == 6) return new MTriangle6(verts, num);
    return new MTriangleN(verts, verts.back()->getPolynomialOrder(), num);
  }
  if(verts.size() == 4) return new MQuadrangle(verts, num);
  if(verts.size() == 8) return new MQuadrangle8(verts, num);
  if(verts.size() == 9) return new MQuadrangle9(verts, num);
  return new MQuadrangleN(verts, verts.back()->getPolynomialOrder(), num);
}
static MElement *createFacetElement(MElement *reference, int k, int num,
                                    MEdge *)
{
  std::vector<MVertex *> verts;
  reference->getEdgeVertices(k, verts);
  if(verts.size() == 2) return new MLine(verts, num);
  if(verts.size() == 3) return new MLine3(verts, num);
  return new MLineN(verts, num);
}
static void addFacetElement(partitionFace *pf, MElement *e)
{
  if(e->getType() == TYPE_TRI)
    pf->addTriangle(static_cast<MTriangle *>(e));
  else
    pf->addQuadrangle(static_cast<MQuadrangle *>(e));
}
static void addFacetElement(partitionEdge *pe, MElement *e)
{ pe->addLine(static_cast<MLine *>(e)); }

// Creates the partition entities bounding the parts of a mesh of dimension
// dim, made of the facets (faces in 3D, edges in 2D) of the elements of
// dimension dim shared by elements in different parts. The part of the
// element i of the graph is graph.partition(i), and lists gives the
// partitions of each part: a single partition when partitioning the mesh, or
// the partitions of a partition surface when creating the partition curves
// between the partition surfaces. The elements sharing a facet are neighbors
// in the dual graph, so the facets are found from it, in the order of the
// graph, instead of from a map of all the facets of the elements on the part
// boundaries. As before, a facet is skipped if all the elements sharing it
// have the same partitions, and is copied from its reference element: the
// element with the fewest, then the lowest, partitions, then the lowest part
// and number. Every facet records the entities it bounds, not only the first
// facet of each partition entity: a partition curve can bound several
// surfaces, through different facets. A partition surface of a 3D mesh is
// also distinguished by the volume on the other side, as a surface can only
// bound two volumes.
template <class FACET, class PART_ENTITY>
static void createPartitionBoundaries(
  Graph &graph, GModel *model, const std::vector<std::vector<int>> &lists,
  partitionEntityMap<PART_ENTITY> &pentities,
  const elementEntityMap &elementToEntity, int &numEntity)
{
  const int dim = graph.dim();
  // the order of the reference element
  auto before = [&graph, &lists](idx_t a, idx_t b) {
    const std::vector<int> &la = lists[graph.partition(a)];
    const std::vector<int> &lb = lists[graph.partition(b)];
    if(la.size() != lb.size()) return la.size() < lb.size();
    if(la != lb) return la < lb;
    if(graph.partition(a) != graph.partition(b))
      return graph.partition(a) < graph.partition(b);
    return graph.element(a)->getNum() < graph.element(b)->getNum();
  };

  // The facets are first found in parallel, by chunks of elements: each one
  // is recorded with the elements sharing it, the reference element first.
  // The partition entities are then created in the order of the graph.
  struct facetRecord {
    std::size_t element; // reference element in the graph
    int facet; // facet of the reference element
    std::size_t first, last; // elements sharing it, in sharingByChunk
  };
  const std::size_t chunkSize = 4096;
  const std::size_t numChunks = (graph.ne() + chunkSize - 1) / chunkSize;
  std::vector<std::vector<facetRecord>> records(numChunks);
  std::vector<std::vector<idx_t>> sharingByChunk(numChunks);
  const int nthreads = CTX::instance()->numThreadsFor(graph.ne(), 10000);
#pragma omp parallel num_threads(nthreads)
  {
    std::vector<idx_t> sharing;
    std::vector<int> partitions;
#pragma omp for schedule(dynamic, 1)
    for(std::size_t c = 0; c < numChunks; c++) {
      const std::size_t end = std::min(graph.ne(), (c + 1) * chunkSize);
      for(std::size_t i = c * chunkSize; i < end; i++) {
        MElement *e = graph.element(i);
        if(!e || e->getDim() != dim) continue;
        // only the elements with a neighbor in another part
        bool cut = false;
        for(idx_t j = graph.xadj(i); j < graph.xadj(i + 1) && !cut; j++) {
          const idx_t n = graph.adjncy(j);
          cut = graph.element(n) && graph.element(n)->getDim() == dim &&
                graph.partition(n) != graph.partition(i);
        }
        if(!cut) continue;

        for(int k = 0; k < getNumFacets(e, (FACET *)nullptr); k++) {
          FACET f = getFacet(e, k, (FACET *)nullptr);
          // the elements sharing the facet (more than 2 if non-manifold)
          sharing.assign(1, (idx_t)i);
          for(idx_t j = graph.xadj(i); j < graph.xadj(i + 1); j++) {
            const idx_t n = graph.adjncy(j);
            MElement *en = graph.element(n);
            if(en && en->getDim() == dim && hasFacet(en, f))
              sharing.push_back(n);
          }
          std::sort(sharing.begin(), sharing.end(), before);
          // handle the facet once, from its reference element, if the
          // elements sharing it do not all have the same partitions
          if(sharing[0] != (idx_t)i || lists[graph.partition(sharing.back())] ==
                                         lists[graph.partition(i)])
            continue;
          partitions.clear();
          for(std::size_t j = 0; j < sharing.size(); j++) {
            const std::vector<int> &l = lists[graph.partition(sharing[j])];
            partitions.insert(partitions.end(), l.begin(), l.end());
          }
          std::sort(partitions.begin(), partitions.end());
          if(partitions.front() == partitions.back()) continue;
          std::vector<idx_t> &buffer = sharingByChunk[c];
          facetRecord r = {i, k, buffer.size(), buffer.size() + sharing.size()};
          buffer.insert(buffer.end(), sharing.begin(), sharing.end());
          records[c].push_back(r);
        }
      }
    }
  }

  // Then, also in parallel, the element of each facet is created, numbered
  // as if they were created one after the other, and the entities and the
  // orientations of the elements sharing it are found
  std::vector<std::size_t> firstRecord(numChunks + 1, 0);
  for(std::size_t c = 0; c < numChunks; c++)
    firstRecord[c + 1] = firstRecord[c] + records[c].size();
  const std::size_t firstNum = model->getMaxElementNumber() + 1;
  std::vector<std::vector<MElement *>> facets(numChunks);
  std::vector<std::vector<GEntity *>> entities(numChunks);
  std::vector<std::vector<int>> orientations(numChunks);
  auto entityOf = [&elementToEntity](MElement *e) -> GEntity * {
    return elementToEntity.get(e);
  };
#pragma omp parallel for schedule(dynamic, 1) num_threads(nthreads)
  for(std::size_t c = 0; c < numChunks; c++) {
    facets[c].resize(records[c].size());
    entities[c].resize(sharingByChunk[c].size());
    orientations[c].resize(sharingByChunk[c].size());
    for(std::size_t r = 0; r < records[c].size(); r++) {
      const facetRecord &rec = records[c][r];
      MElement *facet = createFacetElement(
        graph.element(rec.element), rec.facet,
        (int)(firstNum + firstRecord[c] + r), (FACET *)nullptr);
      facets[c][r] = facet;
      for(std::size_t j = rec.first; j < rec.last; j++) {
        MElement *n = graph.element(sharingByChunk[c][j]);
        entities[c][j] = entityOf(n);
        orientations[c][j] = computeOrientation(n, facet);
      }
    }
  }
  if(firstRecord[numChunks])
    model->setMaxElementNumber(firstNum + firstRecord[numChunks] - 1);

  // Finally, the partition entities are created and the facets added to
  // them, in the order of the graph. Every facet records the entities it
  // bounds, unless already recorded; a zero orientation cannot happen on a
  // conformal mesh (see assignNewEntityBRep): the pair is left for another
  // facet. Consecutive facets mostly belong to the same partition entity, so
  // the last one and the entities it bounds are kept at hand.
  std::unordered_map<GEntity *, std::vector<GEntity *>> bounds;
  std::vector<int> partitions, lastPartitions;
  GEntity *lastReference = nullptr, *lastOther = nullptr;
  PART_ENTITY *pe = nullptr;
  std::vector<GEntity *> *peBounds = nullptr;
  for(std::size_t c = 0; c < numChunks; c++) {
    for(std::size_t r = 0; r < records[c].size(); r++) {
      const facetRecord &rec = records[c][r];
      partitions.clear();
      for(std::size_t j = rec.first; j < rec.last; j++) {
        const std::vector<int> &l =
          lists[graph.partition(sharingByChunk[c][j])];
        partitions.insert(partitions.end(), l.begin(), l.end());
      }
      std::sort(partitions.begin(), partitions.end());
      partitions.erase(std::unique(partitions.begin(), partitions.end()),
                       partitions.end());
      GEntity *reference = entities[c][rec.first];
      // in 3D, a partition surface bounds the volumes on both sides
      GEntity *other = (dim == 3 && rec.last - rec.first == 2) ?
                         entities[c][rec.first + 1] :
                         nullptr;
      if(!pe || reference != lastReference || other != lastOther ||
         partitions != lastPartitions) {
        PART_ENTITY *newEntity = nullptr;
        pe = createPartitionEntity(model, numEntity, partitions, reference,
                                   &newEntity, pentities, other);
        peBounds = &bounds[pe];
        lastReference = reference;
        lastOther = other;
        lastPartitions = partitions;
      }
      addFacetElement(pe, facets[c][r]);
      for(std::size_t j = rec.first; j < rec.last; j++) {
        GEntity *b = entities[c][j];
        if(!orientations[c][j] ||
           std::find(peBounds->begin(), peBounds->end(), b) != peBounds->end())
          continue;
        peBounds->push_back(b);
        addPartitionBoundary(b, pe, orientations[c][j]);
      }
    }
    std::vector<facetRecord>().swap(records[c]);
    std::vector<idx_t>().swap(sharingByChunk[c]);
    std::vector<MElement *>().swap(facets[c]);
    std::vector<GEntity *>().swap(entities[c]);
    std::vector<int>().swap(orientations[c]);
  }
}

static void assignNewEntityBRep(Graph &graph,
                                const elementEntityMap &elementToEntity)
{
  // The pairs of entities (of an element, of a neighbor of dimension one
  // less) are found in parallel, by chunks of elements, each chunk keeping
  // the first element pair of each entity pair, then merged in the order of
  // the chunks: the orientation of an entity pair is the one of its first
  // element pair in the graph, as when this was serial.
  struct entityPair {
    GEntity *g1, *g2;
    int ori;
  };
  const std::size_t chunkSize = 4096;
  const std::size_t numChunks = (graph.ne() + chunkSize - 1) / chunkSize;
  std::vector<std::vector<entityPair>> pairs(numChunks);
  auto entityOf = [&elementToEntity](MElement *e) -> GEntity * {
    return elementToEntity.get(e);
  };
  const int nthreads = CTX::instance()->numThreadsFor(graph.ne(), 10000);
#pragma omp parallel for schedule(dynamic, 1) num_threads(nthreads)
  for(std::size_t c = 0; c < numChunks; c++) {
    std::set<std::pair<GEntity *, GEntity *>> seen;
    const std::size_t end = std::min(graph.ne(), (c + 1) * chunkSize);
    for(std::size_t i = c * chunkSize; i < end; i++) {
      MElement *current = graph.element(i);
      for(idx_t j = graph.xadj(i); j < graph.xadj(i + 1); j++) {
        MElement *neighbor = graph.element(graph.adjncy(j));
        if(current->getDim() != neighbor->getDim() + 1) continue;
        GEntity *g1 = entityOf(current);
        GEntity *g2 = entityOf(neighbor);
        if(seen.count(std::make_pair(g1, g2))) continue;
        const int ori = computeOrientation(current, neighbor);
        // A zero orientation means the elements are neighbors in the
        // node-based dual graph without one being a facet of the other,
        // which cannot happen on a conformal mesh. Record nothing: MSH4
        // encodes the orientation as the sign of the tag, so a 0 would read
        // back as -1. Leave the pair unmarked, so another element pair can
        // still establish the relation with a real orientation.
        if(!ori) continue;
        seen.insert(std::make_pair(g1, g2));
        entityPair p = {g1, g2, ori};
        pairs[c].push_back(p);
      }
    }
  }

  std::set<std::pair<GEntity *, GEntity *> > brepWithoutOri;
  hashmapentity brep;
  for(std::size_t c = 0; c < numChunks; c++) {
    for(std::size_t k = 0; k < pairs[c].size(); k++) {
      const entityPair &p = pairs[c][k];
      if(brepWithoutOri.insert(std::make_pair(p.g1, p.g2)).second)
        brep[p.g1].insert(std::make_pair(p.ori, p.g2));
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

// A curve must be bounded by its extremities and nothing else. Where several
// partition curves meet, the one that runs *through* the junction is still a
// single connected chain, so divideNonConnectedEntities() leaves it whole and
// the partition point created at that junction ends up attached to the middle
// of it. Cut such curves at their junction nodes, so that every node shared
// between two partition curves is an extremity of both.
static bool splitPartitionCurvesAtJunctions(GModel *model)
{
  std::set<GEdge *, GEntityPtrLessThan> edges = model->getEdges();

  // nodes carried by more than one partition curve
  std::unordered_map<MVertex *, GEdge *, MVertexPtrHash, MVertexPtrEqual> owner;
  std::unordered_set<MVertex *, MVertexPtrHash, MVertexPtrEqual> junction;
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    if((*it)->geomType() != GEntity::PartitionCurve) continue;
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      for(int j = 0; j < 2; j++) {
        MVertex *v = (*it)->lines[i]->getVertex(j);
        auto res = owner.insert(std::make_pair(v, *it));
        if(!res.second && res.first->second != *it) junction.insert(v);
      }
    }
  }
  if(junction.empty()) return false;

  bool ret = false;
  int elementaryNumber = model->getMaxElementaryNumber(1);

  // as in divideNonConnectedEntities(), the new curves are created in a
  // second pass so that the B-Rep of the original can be distributed among
  // the pieces rather than copied to each of them
  struct PendingCurveSplit {
    partitionEdge *edge;
    std::vector<GFace *> brep;
    std::vector<int> orientations;
    std::vector<std::size_t> components;
    std::vector<std::vector<MElement *> > elements;
  };
  std::vector<PendingCurveSplit> pending;
  BRepDistributor<MEdge, MEdgeHash, MEdgeEqual> distributor;

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    if((*it)->geomType() != GEntity::PartitionCurve) continue;
    partitionEdge *edge = static_cast<partitionEdge *>(*it);
    const std::size_t n = edge->lines.size();
    if(n < 2) continue;

    std::unordered_map<MVertex *, std::vector<std::size_t>, MVertexPtrHash,
                       MVertexPtrEqual>
      nodeLines;
    for(std::size_t i = 0; i < n; i++) {
      nodeLines[edge->lines[i]->getVertex(0)].push_back(i);
      nodeLines[edge->lines[i]->getVertex(1)].push_back(i);
    }
    // cut where the chain runs through a node shared with another curve, and
    // where it runs through a node of its own more than twice
    std::unordered_set<MVertex *, MVertexPtrHash, MVertexPtrEqual> cut;
    for(auto itN = nodeLines.begin(); itN != nodeLines.end(); ++itN) {
      if(itN->second.size() < 2) continue;
      if(itN->second.size() > 2 ||
         junction.find(itN->first) != junction.end())
        cut.insert(itN->first);
    }
    if(cut.empty()) continue;

    // maximal sub-chains that do not run through a cut node
    std::vector<char> visited(n, 0);
    std::vector<std::vector<MElement *> > components;
    std::vector<std::size_t> stack;
    for(std::size_t seed = 0; seed < n; seed++) {
      if(visited[seed]) continue;
      std::vector<MElement *> comp;
      stack.push_back(seed);
      visited[seed] = 1;
      while(!stack.empty()) {
        const std::size_t l = stack.back();
        stack.pop_back();
        comp.push_back(edge->lines[l]);
        for(int j = 0; j < 2; j++) {
          MVertex *v = edge->lines[l]->getVertex(j);
          if(cut.find(v) != cut.end()) continue;
          const std::vector<std::size_t> &adj = nodeLines[v];
          for(std::size_t k = 0; k < adj.size(); k++) {
            if(visited[adj[k]]) continue;
            visited[adj[k]] = 1;
            stack.push_back(adj[k]);
          }
        }
      }
      std::sort(comp.begin(), comp.end(), MElementPtrLessThan());
      components.push_back(std::vector<MElement *>());
      components.back().swap(comp);
    }
    if(components.size() < 2) continue;

    ret = true;
    PendingCurveSplit split;
    split.edge = edge;
    split.brep = edge->faces();
    split.orientations.reserve(split.brep.size());
    for(std::size_t j = 0; j < split.brep.size(); j++)
      split.orientations.push_back(split.brep[j]->delEdge(edge));
    for(std::size_t i = 0; i < components.size(); i++) {
      std::size_t comp = distributor.newComponent();
      split.components.push_back(comp);
      for(std::size_t j = 0; j < components[i].size(); j++)
        distributor.claim(components[i][j]->getEdge(0), comp);
      split.elements.push_back(std::vector<MElement *>());
      split.elements.back().swap(components[i]);
    }
    pending.push_back(split);
  }

  if(pending.empty()) return ret;

  std::set<GFace *, GEntityPtrFullLessThan> candidates;
  for(std::size_t i = 0; i < pending.size(); i++)
    candidates.insert(pending[i].brep.begin(), pending[i].brep.end());
  distributor.probeAll(candidates);

  for(std::size_t p = 0; p < pending.size(); p++) {
    PendingCurveSplit &split = pending[p];
    for(std::size_t i = 0; i < split.components.size(); i++) {
      partitionEdge *pedge =
        new partitionEdge(model, ++elementaryNumber, nullptr, nullptr,
                          split.edge->getPartitions());
      pedge->setParentEntity(split.edge->getParentEntity());
      model->add(pedge);
      for(std::size_t j = 0; j < split.elements[i].size(); j++)
        pedge->addElement(split.elements[i][j]);
      for(std::size_t j = 0; j < split.brep.size(); j++) {
        if(!distributor.touches(split.components[i], split.brep[j])) continue;
        split.brep[j]->setEdge(pedge, split.orientations[j]);
        pedge->addFace(split.brep[j]);
      }
    }
    model->remove(split.edge);
    split.edge->lines.clear();
    split.edge->mesh_vertices.clear();
    delete split.edge;
  }

  return ret;
}

// Create the new entities between each partitions (sigma and bndSigma).
static void createPartitionTopology(
  GModel *model,
  const std::vector<std::vector<MElement *> > &boundaryElements,
  Graph &meshGraph)
{
  int meshDim = model->getMeshDim();
  elementEntityMap elementToEntity;
  elementToEntity.fill(model, -1);
  assignNewEntityBRep(meshGraph, elementToEntity);

  partitionEntityMap<partitionFace> pfaces;
  partitionEntityMap<partitionEdge> pedges;
  partitionEntityMap<partitionVertex> pvertices;

  hashmapvertex vertexToElement;
  // the distinct partition lists referenced by the maps above
  std::vector<std::vector<int> > partitionLists;

  std::set<GRegion *, GEntityPtrLessThan> regions = model->getRegions();
  std::set<GFace *, GEntityPtrLessThan> faces = model->getFaces();
  std::set<GEdge *, GEntityPtrLessThan> edges = model->getEdges();
  std::set<GVertex *, GEntityPtrLessThan> vertices = model->getVertices();

  // the part of each element of the mesh graph is its partition
  std::vector<std::vector<int>> singlePartitions(model->getNumPartitions());
  for(std::size_t i = 0; i < singlePartitions.size(); i++)
    singlePartitions[i].assign(1, (int)i + 1);

  if(meshDim >= 3) {
    Msg::Info(" - Creating partition surfaces");

    int numFaceEntity = model->getMaxElementaryNumber(2);
    createPartitionBoundaries<MFace>(meshGraph, model, singlePartitions, pfaces,
                                     elementToEntity, numFaceEntity);

    // the components of the partition surfaces, found on the dual graph of
    // all the surfaces
    faces = model->getFaces();
    {
      Graph surfaceGraph(model);
      componentMap components;
      if(!makeGraph(model, surfaceGraph, 2)) {
        surfaceGraph.createDualGraph(false);
        findPartitionComponents(surfaceGraph, nullptr, components);
        divideNonConnectedEntities(model, 2, regions, faces, edges, vertices,
                                   &components);
      }
    }

    elementToEntity.clear();
    elementToEntity.fill(model, 2);
  }

  if(meshDim >= 2) {
    Msg::Info(" - Creating partition curves");

    if(meshDim == 2) {
      int numEdgeEntity = model->getMaxElementaryNumber(1);
      createPartitionBoundaries<MEdge>(meshGraph, model, singlePartitions,
                                       pedges, elementToEntity, numEdgeEntity);
    }
    else {
      Graph subGraph(model);
      makeGraph(model, subGraph, 2);
      subGraph.createDualGraph(false);
      std::vector<idx_t> part(subGraph.ne());
      int partIndex = 0;

      idx_t mapOfPartitionsTag = 0;
      for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
        if((*it)->geomType() == GEntity::PartitionSurface) {
          std::vector<int> partitions =
            static_cast<partitionFace *>(*it)->getPartitions();
          partitionLists.push_back(partitions);
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

      // the partition curves are the edges between partition surfaces with
      // different partitions
      int numEdgeEntity = model->getMaxElementaryNumber(1);
      createPartitionBoundaries<MEdge>(subGraph, model, partitionLists, pedges,
                                       elementToEntity, numEdgeEntity);
    }

    partitionLists.clear();

    edges = model->getEdges();
    divideNonConnectedEntities(model, 1, regions, faces, edges, vertices);
    // a partition point will be created at every junction of partition
    // curves, so the curves running through those junctions have to be cut
    // there first, or the point ends up bounding the middle of a curve
    splitPartitionCurvesAtJunctions(model);
    elementToEntity.clear();
    elementToEntity.fill(model, 1);
  }

  if(meshDim >= 1) {
    Msg::Info(" - Creating partition points");
    if(meshDim == 1) {
      partitionLists.resize(model->getNumPartitions());
      for(std::size_t i = 0; i < model->getNumPartitions(); i++)
        partitionLists[i].assign(1, (int)i + 1);
      for(std::size_t i = 0; i < model->getNumPartitions(); i++) {
        for(auto it = boundaryElements[i].begin();
            it != boundaryElements[i].end(); ++it) {
          for(std::size_t j = 0; j < (*it)->getNumPrimaryVertices(); j++) {
            vertexToElement[(*it)->getVertex(j)].push_back(
              std::make_pair(*it, (int)i));
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

      idx_t mapOfPartitionsTag = 0;
      for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
        if((*it)->geomType() == GEntity::PartitionCurve) {
          std::vector<int> partitions =
            static_cast<partitionEdge *>(*it)->getPartitions();
          partitionLists.push_back(partitions);
          // Must absolutely be in the same order as in the makeGraph function
          for(auto itElm = (*it)->lines.begin(); itElm != (*it)->lines.end();
              ++itElm)
            part[partIndex++] = mapOfPartitionsTag;
          mapOfPartitionsTag++;
        }
      }
      subGraph.partition(part);

      std::vector<std::vector<MElement *> > subBoundaryElements =
        subGraph.getBoundaryElements(mapOfPartitionsTag);

      for(idx_t i = 0; i < mapOfPartitionsTag; i++) {
        for(auto it = subBoundaryElements[i].begin();
            it != subBoundaryElements[i].end(); ++it) {
          for(std::size_t j = 0; j < (*it)->getNumPrimaryVertices(); j++) {
            vertexToElement[(*it)->getVertex(j)].push_back(
              std::make_pair(*it, (int)i));
          }
        }
      }
    }
    int numVertexEntity = model->getMaxElementaryNumber(0);
    for(auto it = vertexToElement.begin(); it != vertexToElement.end(); ++it) {
      MVertex *v = it->first;

      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second, partitionLists);
      if(partitions.size() < 2) continue;

      MElement *reference = getReferenceElement(it->second, partitionLists);
      if(!reference) continue;

      partitionVertex *pv =
        assignPartitionBoundary(model, v, reference, partitions, pvertices,
                                elementToEntity, numVertexEntity);
      if(pv) {
        std::map<GEntity *, MElement *, GEntityPtrFullLessThan>
          boundaryEntityAndRefElement;
        for(std::size_t i = 0; i < it->second.size(); i++)
          boundaryEntityAndRefElement.insert(std::make_pair(
            elementToEntity.get(it->second[i].first), it->second[i].first));

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
    if(parent->dim() == entity->dim()) {
      // reuse physicals from parent entity
      entity->physicals = parent->physicals;
    }
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
      nameToNumber.insert(std::make_pair(name, number));
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
      nameToNumber.insert(std::make_pair(name, number));
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
  while(1){
    METIS_PartGraphKway(&nvtxs, &ncon, &xadjncy[0], &adjncy[0], nullptr, nullptr,
                        &adjncyw[0], &nparts, nullptr, &ubvec, nullptr, &objval,
                        &epart[0]);
    bool allTheSame = true;
    for(size_t i = 0; i < gf->triangles.size() - 1; ++i) {
      if(epart[i+1] != epart[i]) allTheSame = false;
    }
    if (!allTheSame) break;
    ubvec -= (1. - ubvec) * .5;
    Msg::Warning("Partitioning face %d with %zu triangles that all have the same"
                 " partition - changing tolerance to %g", gf->tag(),
                 gf->triangles.size(), ubvec);
    if(ubvec > CTX::instance()->lc) {
      Msg::Warning("Tolerance too large - aborting partitioning");
      break;
    }
  }
  for(size_t i = 0; i < gf->triangles.size(); ++i) {
    gf->triangles[i]->setPartition(epart[i]);
  }
  return 0;
}

static std::unordered_set<GVertex *> findAllEmbeddedVertices(GModel *model)
{
  std::unordered_set<GVertex *> embeddedVertices;
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    GFace *gf = *it;
    for(const auto &ev : gf->embeddedVertices()) embeddedVertices.insert(ev);
  }
  for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    GRegion *gr = *it;
    for(const auto &ev : gr->embeddedVertices()) embeddedVertices.insert(ev);
  }
  return embeddedVertices;
}

static std::vector<int> clearDuplicates(const std::vector<int> &partitions)
{
  std::unordered_set<int> uniquePartitions(partitions.begin(),
                                           partitions.end());
  return std::vector<int>(uniquePartitions.begin(), uniquePartitions.end());
}

template <int dim>
static void entityCheckForEmbedded(
  typename EntityTraits<dim>::Entity *entity,
  const std::unordered_map<MVertex *, partitionVertex *> &mvToPartitionVertex)
{
  auto *pe =
    dynamic_cast<typename EntityTraits<dim>::PartitionEntity *>(entity);
  if(!pe) return;
  auto partitionsOfEdge = pe->getPartitions();

  for(size_t e = 0; e < pe->getNumMeshElements(); e++) {
    MElement *me = pe->getMeshElement(e);
    for(size_t v = 0; v < me->getNumVertices(); v++) {
      MVertex *mv = me->getVertex(v);
      if(mv->onWhat()->dim() == 0) {
        auto it = mvToPartitionVertex.find(mv);
        if(it != mvToPartitionVertex.end()) {
          partitionVertex *pv = it->second;
          std::vector<int> partitions = pv->getPartitions();
          for(int p : partitionsOfEdge) { partitions.push_back(p); }
          pv->setPartitions(clearDuplicates(partitions));
        }
      }
    }
  }
}

static void fixEmbeddedVertices(GModel *model)
{
  Msg::Info("Fixing partition embedded vertices...");
  auto embeddedVertices = findAllEmbeddedVertices(model);
  std::unordered_map<MVertex *, partitionVertex *> mvToPartitionVertex;
  for(auto it = model->firstVertex(); it != model->lastVertex(); ++it) {
    GVertex *gv = *it;
    if(gv->geomType() == GEntity::PartitionPoint) {
      partitionVertex *pv = static_cast<partitionVertex *>(gv);
      GVertex *parent = dynamic_cast<GVertex *>(pv->getParentEntity());
      if(embeddedVertices.count(parent)) {
        mvToPartitionVertex.insert(std::make_pair(pv->getMeshVertex(0), pv));

        MVertex *mv = pv->getMeshVertex(0);
        if(mv->onWhat() != pv) {
          Msg::Warning("Mesh vertex %lu is not on partition vertex %d",
                       mv->getNum(), pv->tag());
        }
      }
    }
  }

  for(auto it = model->firstEdge(); it != model->lastEdge(); ++it) {
    entityCheckForEmbedded<1>(*it, mvToPartitionVertex);
  }
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    entityCheckForEmbedded<2>(*it, mvToPartitionVertex);
  }
}
// Partition a mesh into n parts. Returns: 0 = success, 1 = error

int PartitionMesh(GModel *model, int numPart)
{
  if(numPart <= 0) return 0;

  Msg::StatusBar(true, "Partitioning mesh...");
  double t1 = Cpu(), w1 = TimeOfDay();

  Graph graph(model);
  if(makeGraph(model, graph, -1)) return 1;
  graph.nparts(numPart);
  if(partitionGraph(graph, true)) return 1;

  std::vector<std::size_t> elmCount[TYPE_MAX_NUM + 1];
  for(int i = 0; i < TYPE_MAX_NUM + 1; i++) { elmCount[i].resize(numPart, 0); }

  // Assign partitions to elements. The element carries its own partition, so
  // there is no need for a parallel map of every element in the mesh.
  for(std::size_t i = 0; i < graph.ne(); i++) {
    if(graph.element(i)) {
      if(graph.nparts() > 1) {
        elmCount[graph.element(i)->getType()][graph.partition(i)]++;
        graph.element(i)->setPartition(graph.partition(i) + 1);
      }
      else {
        graph.element(i)->setPartition(1);
      }
    }
  }
  model->setNumPartitions(graph.nparts());

  createNewEntities(model, &graph);

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
      Msg::Info(" - Repartition of %d %s: %zu(min) %zu(max) %g(avg)", totCount,
                ElementType::nameOfParentType(i, totCount > 1).c_str(),
                minCount, maxCount, totCount / (double)numPart);
    }
  }

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done partitioning mesh (Wall %gs, CPU %gs)", w2 - w1,
                 t2 - t1);
  
  if(CTX::instance()->mesh.partitionCreateTopology) {
    Msg::StatusBar(true, "Creating partition topology...");
    std::vector<std::vector<MElement *> > boundaryElements =
      graph.getBoundaryElements();
    createPartitionTopology(model, boundaryElements, graph);
    boundaryElements.clear();
    double t3 = Cpu(), w3 = TimeOfDay();
    Msg::StatusBar(true, "Done creating partition topology (Wall %gs, CPU %gs)",
                   w3 - w2, t3 - t2);
  }

  assignPhysicals(model);
  assignMeshVertices(model);
  fixEmbeddedVertices(model);

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
    entity->getParentEntity()->addElement(*it);
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
    else if(face->geomType() == GEntity::OverlapSurface) {
      face->deleteMesh();
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
    else if(region->geomType() == GEntity::OverlapVolume) {
      region->deleteMesh();
      model->remove(region);
      delete region;
    }
  }

  model->setNumPartitions(0);
  model->clearOverlaps();

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
// Returns: 0 = success, 1 = no elements found/invalid data.
int PartitionUsingThisSplit(GModel *model,
                            std::vector<std::pair<MElement *, int> > &elmToPart)
{
  Graph graph(model);
  if(makeGraph(model, graph, -1)) return 1;

  int numPart = 0;
  hashmapelementpart elmToPartition;
  std::vector<std::pair<MElement*, int> > elmGhosts;
  for(auto item : elmToPart) {
    MElement *el = item.first;
    int part = item.second;
    if(part == 0) {
      Msg::Error("Partition tag cannot be 0");
      return 1;
    }
    if(part > 0) elmToPartition[el] = part;
    else elmGhosts.push_back(std::make_pair(el, -part));
    numPart = std::max(std::abs(part), numPart);
  }

  graph.createDualGraph(false);
  graph.nparts(numPart);

  if(elmToPartition.size() != graph.ne()) {
    Msg::Error("All elements are not partitioned");
    return 1;
  }

  std::vector<idx_t> part(graph.ne());
  for(std::size_t i = 0; i < graph.ne(); i++) {
    if(graph.element(i)) { part[i] = elmToPartition[graph.element(i)] - 1; }
  }

  // Check and correct the topology
  correctTopology(graph, part);

  // Assign the corrected partitions back to the elements
  for(std::size_t i = 0; i < graph.ne(); i++) {
    if(graph.element(i)) {
      elmToPartition[graph.element(i)] = part[i] + 1;
      graph.element(i)->setPartition(part[i] + 1);
    }
  }

  graph.partition(part);

  model->setNumPartitions(graph.nparts());

  createNewEntities(model, &graph);

  if(CTX::instance()->mesh.partitionCreateTopology) {
    Msg::StatusBar(true, "Creating partition topology...");
    std::vector<std::vector<MElement *> > boundaryElements =
      graph.getBoundaryElements();
    createPartitionTopology(model, boundaryElements, graph);
    boundaryElements.clear();
    Msg::StatusBar(true, "Done creating partition topology");
  }

  assignPhysicals(model);
  assignMeshVertices(model);
  fixEmbeddedVertices(model);

  if (!elmGhosts.empty()) {
    std::sort(elmGhosts.begin(), elmGhosts.end());
    auto last = std::unique(elmGhosts.begin(), elmGhosts.end());
    elmGhosts.erase(last, elmGhosts.end());
    std::vector<GEntity *> ghostEntities = graph.createGhostEntities();
    for (auto elmGhost : elmGhosts) {
      MElement *el = elmGhost.first;
      int part = elmGhost.second;
      if(el->getDim() == graph.dim()) {
        switch(graph.dim()) {
          case 1:
            static_cast<ghostEdge *>(ghostEntities[part - 1])
              ->addElement(el, elmToPartition[el]);
            break;
          case 2:
            static_cast<ghostFace *>(ghostEntities[part - 1])
              ->addElement(el, elmToPartition[el]);
            break;
          case 3:
            static_cast<ghostRegion *>(ghostEntities[part - 1])
              ->addElement(el, elmToPartition[el]);
            break;
          default: break;
        }
      }
    }
  }
  else if(CTX::instance()->mesh.partitionCreateGhostCells) {
    graph.clearDualGraph();
    graph.createDualGraph(true);
    graph.assignGhostCells();
  }
  elmToPartition.clear();

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
      elmToPartition.push_back(std::make_pair(e, part));
      partitions.insert(part);
    }
  }

  return PartitionUsingThisSplit(model, elmToPartition);
}

#else

int PartitionMesh(GModel *model, int numPart)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}

int UnpartitionMesh(GModel *model) { return 0; }

int ConvertOldPartitioningToNewOne(GModel *model) { return 0; }

int PartitionUsingThisSplit(
  GModel *model, std::vector<std::pair<MElement *, int> > &elmToPartition)
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
