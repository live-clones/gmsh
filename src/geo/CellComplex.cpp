// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Matti Pellikka <matti.pellikka@gmail.com>.

#include <array>
#include <unordered_map>
#include "CellComplex.h"
#include "Context.h"
#include "MElement.h"
#include "OS.h"

double CellComplex::_patience = 10;

// sort with OpenMP when threads and enough work are available: the chunks
// are sorted in parallel and then merged pairwise. The comparators used
// here are strict total orders on distinct entries, so the result is
// identical to a serial sort regardless of the number of threads.
template <class T, class Compare>
static void parallelSort(std::vector<T> &v, Compare comp)
{
#if defined(_OPENMP)
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  if(nthreads > 1 && v.size() > 65536) {
    std::size_t n = v.size();
    int nc = nthreads;
    std::vector<std::size_t> bounds(nc + 1);
    for(int i = 0; i <= nc; i++) bounds[i] = n * i / nc;
#pragma omp parallel for num_threads(nthreads)
    for(int i = 0; i < nc; i++)
      std::sort(v.begin() + bounds[i], v.begin() + bounds[i + 1], comp);
    for(int width = 1; width < nc; width *= 2) {
      int step = 2 * width;
#pragma omp parallel for num_threads(nthreads)
      for(int i = 0; i < nc; i += step) {
        int mid = i + width < nc ? i + width : nc;
        int hi = i + step < nc ? i + step : nc;
        if(mid < hi)
          std::inplace_merge(v.begin() + bounds[i], v.begin() + bounds[mid],
                             v.begin() + bounds[hi], comp);
      }
    }
    return;
  }
#endif
  std::sort(v.begin(), v.end(), comp);
}

template <std::size_t N> struct CellVertexKeyHash {
  std::size_t operator()(const std::array<std::size_t, N> &key) const
  {
    std::size_t h = 0;
    for(std::size_t i = 0; i < N; i++)
      h = h * 0x9e3779b97f4a7c15ul ^ key[i];
    return h;
  }
};

// Construction-time index from the sorted mesh vertex numbers of a cell to
// the unique cell with those vertices. Looking up a candidate boundary cell
// here costs one hash instead of the tree descent with vertex-list
// comparisons that a find in the _cells sets costs, and requires no
// speculatively allocated Cell for candidates that are duplicates (which is
// the common case: an interior facet is a duplicate for all its parents but
// the first).
//
// The maps are split into a fixed number of shards by hash, so that the
// parallel construction pipeline can deduplicate the shards concurrently
// (a cell always lands in the same shard, and a shard is only ever touched
// by one thread at a time). The results do not depend on the shard count.
class CellConstructionIndex {
public:
  static int numShards() { return 16; }

private:
  template <std::size_t N>
  using KeyMap = std::unordered_map<std::array<std::size_t, N>, Cell *,
                                    CellVertexKeyHash<N> >;
  // sized by the maximum number of vertices of a cell of each dimension
  // (hexahedron: 8, quadrangle: 4, line: 2, point: 1)
  KeyMap<1> _i0[16];
  KeyMap<2> _i1[16];
  KeyMap<4> _i2[16];
  KeyMap<8> _i3[16];

  // the keys are zero-padded; since the numbers are sorted and a cell has
  // no duplicate vertices, padding cannot alias another cell
  template <std::size_t N>
  static std::array<std::size_t, N> _key(const std::size_t *nums, int n)
  {
    std::array<std::size_t, N> key = {};
    for(int i = 0; i < n; i++) key[i] = nums[i];
    return key;
  }

  template <std::size_t N>
  static int _shard(const std::array<std::size_t, N> &key)
  {
    // top bits of the multiplicative hash
    return (int)(CellVertexKeyHash<N>()(key) >> 60);
  }

  // insert a slot for the cell with the given sorted vertex numbers:
  // returns the address of the (stable) Cell* slot and whether the key was
  // absent
  template <std::size_t N>
  static std::pair<Cell **, bool> _insertKey(KeyMap<N> *maps,
                                             const std::size_t *nums, int n,
                                             int shard)
  {
    std::array<std::size_t, N> key = _key<N>(nums, n);
    if(shard < 0) shard = _shard(key);
    auto ins = maps[shard].insert(std::make_pair(key, (Cell *)nullptr));
    return std::make_pair(&ins.first->second, ins.second);
  }

public:
  // shard that the cell with the given sorted vertex numbers belongs to
  int shardOf(int dim, const std::size_t *nums, int n) const
  {
    switch(dim) {
    case 0: return _shard(_key<1>(nums, n));
    case 1: return _shard(_key<2>(nums, n));
    case 2: return _shard(_key<4>(nums, n));
    default: return _shard(_key<8>(nums, n));
    }
  }

  std::pair<Cell **, bool> insertKey(int dim, const std::size_t *nums, int n,
                                     int shard = -1)
  {
    switch(dim) {
    case 0: return _insertKey(_i0, nums, n, shard);
    case 1: return _insertKey(_i1, nums, n, shard);
    case 2: return _insertKey(_i2, nums, n, shard);
    default: return _insertKey(_i3, nums, n, shard);
    }
  }

  std::size_t size(int dim) const
  {
    std::size_t size = 0;
    for(int s = 0; s < numShards(); s++) {
      switch(dim) {
      case 0: size += _i0[s].size(); break;
      case 1: size += _i1[s].size(); break;
      case 2: size += _i2[s].size(); break;
      default: size += _i3[s].size(); break;
      }
    }
    return size;
  }

  void reserve(int dim, std::size_t n)
  {
    std::size_t ns = n / numShards() + 1;
    for(int s = 0; s < numShards(); s++) {
      switch(dim) {
      case 0: _i0[s].reserve(ns); break;
      case 1: _i1[s].reserve(ns); break;
      case 2: _i2[s].reserve(ns); break;
      default: _i3[s].reserve(ns); break;
      }
    }
  }

  // get the cells of a dimension ordered as CellPtrLessThan orders
  // unnumbered cells (by vertex count, then by sorted vertex numbers):
  // sorting the flat keys stored in the index avoids the two dependent
  // pointer loads per vertex that comparing Cell objects costs
  void getSortedCells(int dim, std::vector<Cell *> &cells) const
  {
    switch(dim) {
    case 0: _getSortedCells(_i0, cells); break;
    case 1: _getSortedCells(_i1, cells); break;
    case 2: _getSortedCells(_i2, cells); break;
    default: _getSortedCells(_i3, cells); break;
    }
  }

private:
  template <std::size_t N>
  static void _getSortedCells(const KeyMap<N> *maps, std::vector<Cell *> &cells)
  {
    struct Entry {
      std::array<std::size_t, N> key;
      int n;
      Cell *cell;
    };
    std::size_t offsets[17];
    offsets[0] = 0;
    for(int s = 0; s < numShards(); s++)
      offsets[s + 1] = offsets[s] + maps[s].size();
    std::vector<Entry> entries(offsets[numShards()]);
    // fill the shard segments in parallel: walking the hash map nodes is
    // latency-bound and each shard writes a disjoint range
#if defined(_OPENMP)
    int nthreads = CTX::instance()->numThreads;
    if(!nthreads) nthreads = Msg::GetMaxThreads();
#pragma omp parallel for num_threads(nthreads) schedule(dynamic) \
  if(nthreads > 1 && entries.size() > 65536)
#endif
    for(int s = 0; s < numShards(); s++) {
      std::size_t o = offsets[s];
      for(auto &kv : maps[s])
        entries[o++] =
          Entry{kv.first, kv.second->getNumSortedVertices(), kv.second};
    }
    parallelSort(entries, [](const Entry &a, const Entry &b) {
      if(a.n != b.n) return a.n < b.n;
      return a.key < b.key;
    });
    cells.clear();
    cells.reserve(entries.size());
    for(auto &e : entries) cells.push_back(e.cell);
  }
};

// gather the vertex numbers of the given vertices in ascending order;
// returns -1 if there are duplicate vertices (degenerate cell)
static int sortedVertexNums(const std::vector<MVertex *> &v,
                            std::size_t *nums)
{
  int n = (int)v.size();
  for(int i = 0; i < n; i++) {
    std::size_t num = v[i]->getNum();
    int j = i;
    while(j > 0 && nums[j - 1] > num) {
      nums[j] = nums[j - 1];
      j--;
    }
    nums[j] = num;
  }
  for(int i = 1; i < n; i++)
    if(nums[i] == nums[i - 1]) return -1;
  return n;
}

CellComplex::CellComplex(GModel *model, std::vector<MElement *> &domainElements,
                         std::vector<MElement *> &subdomainElements,
                         std::vector<MElement *> &nondomainElements,
                         std::vector<MElement *> &nonsubdomainElements,
                         std::vector<MElement *> &immuneElements,
                         bool saveOriginalComplex)
  : _model(model), _dim(0), _simplicial(true), _saveorig(saveOriginalComplex),
    _relative(false)
{
  _smallestCell.second = -1.;
  _biggestCell.second = -1.;
  _deleteCount = 0;
  _createCount = 0;
  _cellPool.resize(CellConstructionIndex::numShards());
  CellConstructionIndex index;
  _insertCells(subdomainElements, 1, index);
  if(getSize(0) > 0) _relative = true;
  for(int i = 0; i < 4; i++) _numSubdomainCells[i] = getSize(i);

  _insertCells(domainElements, 0, index);
  for(int i = 0; i < 4; i++)
    _numRelativeCells[i] = getSize(i) - _numSubdomainCells[i];

  _removeCells(nonsubdomainElements, 1);
  _removeCells(nondomainElements, 0);
  _immunizeCells(immuneElements);
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  int num = 0;
  for(int dim = 0; dim < 4; dim++) {
    if(getSize(dim) != 0) _dim = dim;
    // drop the tombstones of the cells that _removeCells took out, so that
    // the containers hold live cells only at the start
    _compact(dim);
    if(_saveorig) _ocells[dim] = _cells[dim];
    for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
      Cell *cell = *cit;
      cell->setNum(++num);
      cell->increaseGlobalNum();
    }
    // saving the original boundary orientations only touches the cell's
    // own lists
#if defined(_OPENMP)
#pragma omp parallel for num_threads(nthreads) schedule(static) \
  if(nthreads > 1 && _cells[dim].size() > 65536)
#endif
    for(std::size_t i = 0; i < _cells[dim].size(); i++)
      _cells[dim][i]->saveCellBoundary();
  }

  _reduced = false;

  Msg::Debug("Cells in domain:");
  Msg::Debug(" %d volumes, %d faces, %d edges, and %d vertices",
             getNumCells(3, 1), getNumCells(2, 1), getNumCells(1, 1),
             getNumCells(0, 1));
  Msg::Debug("Cells in subdomain:");
  Msg::Debug(" %d volumes, %d faces, %d edges, and %d vertices",
             getNumCells(3, 2), getNumCells(2, 2), getNumCells(1, 2),
             getNumCells(0, 2));
  Msg::Debug("Cells in relative domain:");
  Msg::Debug(" %d volumes, %d faces, %d edges, and %d vertices",
             getNumCells(3, 0), getNumCells(2, 0), getNumCells(1, 0),
             getNumCells(0, 0));
}

bool CellComplex::_insertCells(std::vector<MElement *> &elements, int domain,
                               CellConstructionIndex &index)
{
  std::pair<Cell *, double> smallestElement[4];
  std::pair<Cell *, double> biggestElement[4];
  for(int i = 0; i < 4; i++) {
    smallestElement[i].second = -1.;
    biggestElement[i].second = -1.;
  }
  _dim = 0;

  double t1 = Cpu();

  std::size_t nums[8];
  std::vector<MVertex *> vertices;

  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();

  if(nthreads > 1 && elements.size() > 65536) {
    _insertElementCells(elements, domain, index, nthreads, smallestElement,
                        biggestElement);
  }
  else {
    for(std::size_t i = 0; i < elements.size(); i++) {
      MElement *element = elements.at(i);
      int dim = element->getDim();
      int type = element->getType();
      if(type == TYPE_POLYG || type == TYPE_POLYH) {
        Msg::Error("Mesh element type %d not implemented in homology solver",
                   type);
      }
      if(type == TYPE_QUA || type == TYPE_HEX || type == TYPE_PYR ||
         type == TYPE_PRI)
        _simplicial = false;
      std::pair<Cell *, bool> maybeCell =
        Cell::createCell(element, domain, _cellPool[0]);
      if(!maybeCell.second) {
        _cellPool[0].pop_back();
        continue;
      }

      if(_dim < dim) _dim = dim;
      Cell *cell = maybeCell.first;
      maybeCell.first->getMeshVertices(vertices);
      int n = sortedVertexNums(vertices, nums);
      std::pair<Cell **, bool> insert = index.insertKey(dim, nums, n);
      if(!insert.second) {
        _cellPool[0].pop_back();
        cell = *insert.first;
        if(domain) cell->setDomain(domain);
      }
      else {
        *insert.first = cell;
        _createCount++;
      }

      if(domain == 0) {
        double size = fabs(element->getVolume());
        if(smallestElement[dim].second < 0. ||
           smallestElement[dim].second > size)
          smallestElement[dim] = std::make_pair(cell, size);
        if(biggestElement[dim].second < 0. ||
           biggestElement[dim].second < size)
          biggestElement[dim] = std::make_pair(cell, size);
      }
    }
  }
  _smallestCell = smallestElement[_dim];
  _biggestCell = biggestElement[_dim];

  // cells of each dimension in CellPtrLessThan order: cells of dimension
  // dim are complete once the boundary cells of dimension dim+1 have been
  // created, so each dimension needs to be sorted only once
  std::vector<Cell *> sortedCells[4];
  for(int dim = 3; dim > 0; dim--) {
    double t2 = Cpu();
    if(t2 - t1 > CellComplex::_patience && dim > 1) {
      if(domain == 0)
        Msg::Info(" - Creating domain %d-cells", dim);
      else if(domain == 1)
        Msg::Info(" - Creating subdomain %d-cells", dim);
    }

    // iterate the cells in the same sorted order as the previous
    // std::set-based implementation, so the constructed complex (and hence
    // the cell numbering) is identical
    index.getSortedCells(dim, sortedCells[dim]);
    std::vector<Cell *> &cells = sortedCells[dim];
    if(!cells.empty())
      index.reserve(dim - 1, index.size(dim - 1) +
                               cells.size() * cells[0]->getNumBdElements() / 2);

    if(nthreads > 1 && cells.size() > 65536) {
      _insertBoundaryCells(cells, dim, domain, index, nthreads);
      continue;
    }

    for(std::size_t ic = 0; ic < cells.size(); ic++) {
      Cell *cell = cells[ic];
      for(int i = 0; i < cell->getNumBdElements(); i++) {
        cell->findBdElement(i, vertices);
        int n = sortedVertexNums(vertices, nums);
        if(n < 0) {
          Msg::Warning("The input mesh has degenerate elements, ignored");
          continue;
        }
        std::pair<Cell **, bool> insert = index.insertKey(dim - 1, nums, n);
        Cell *newCell;
        if(!insert.second) {
          newCell = *insert.first;
          if(domain) newCell->setDomain(domain);
        }
        else {
          newCell = Cell::createCell(cell, vertices, _cellPool[0]);
          *insert.first = newCell;
          _createCount++;
        }
        if(domain == 0) {
          int ori = cell->findBdCellOrientation(newCell, i);
          cell->addBoundaryCell(ori, newCell, true);
          if(_smallestCell.first == cell)
            _smallestCell = std::make_pair(newCell, _smallestCell.second);
          if(_biggestCell.first == cell)
            _biggestCell = std::make_pair(newCell, _biggestCell.second);
        }
      }
    }
  }
  index.getSortedCells(0, sortedCells[0]);

  // the sorted vectors are the cell containers
  for(int dim = 0; dim < 4; dim++) {
    _cells[dim] = std::move(sortedCells[dim]);
#if defined(_OPENMP)
#pragma omp parallel for num_threads(nthreads) schedule(static) \
  if(nthreads > 1 && _cells[dim].size() > 65536)
#endif
    for(std::size_t i = 0; i < _cells[dim].size(); i++)
      _cells[dim][i]->setInComplex(true);
    _numLiveCells[dim] = _cells[dim].size();
  }
  return true;
}

void CellComplex::_insertElementCells(
  std::vector<MElement *> &elements, int domain, CellConstructionIndex &index,
  int nthreads, std::pair<Cell *, double> *smallestElement,
  std::pair<Cell *, double> *biggestElement)
{
  // Parallel version of the element-cell creation of _insertCells, with
  // results identical to the serial loop: a pass over the elements computes
  // the sorted vertex keys and index shards in parallel, and a pass over
  // the shards deduplicates them and creates the cells (see
  // _insertBoundaryCells for why this is race-free and deterministic).
  const int nshards = CellConstructionIndex::numShards();
  const std::size_t blockSize = 1 << 21;

  std::size_t buf = std::min(blockSize, elements.size());
  std::vector<std::array<std::size_t, 8> > keys(buf);
  std::vector<signed char> keyLen(buf);
  std::vector<unsigned char> shard(buf);
  long long created = 0;
  int maxDim = _dim;
  bool nonSimplicial = false;

  // per-dimension smallest/biggest element, tracked as (volume, element
  // index): ties are broken by the element index, matching the strict
  // comparisons of the serial loop where the first minimum/maximum wins
  std::pair<double, std::size_t> smallest[4], biggest[4];
  for(int i = 0; i < 4; i++) {
    smallest[i] = std::make_pair(-1., (std::size_t)0);
    biggest[i] = std::make_pair(-1., (std::size_t)0);
  }

  for(std::size_t e0 = 0; e0 < elements.size(); e0 += blockSize) {
    const std::size_t ne = std::min(elements.size(), e0 + blockSize) - e0;

    // pass A: element keys, shards, type flags, volume extrema
#pragma omp parallel num_threads(nthreads)
    {
      std::size_t nums[8];
      int tMaxDim = 0;
      bool tNonSimplicial = false;
      std::pair<double, std::size_t> tSmallest[4], tBiggest[4];
      for(int i = 0; i < 4; i++) {
        tSmallest[i] = std::make_pair(-1., (std::size_t)0);
        tBiggest[i] = std::make_pair(-1., (std::size_t)0);
      }
#pragma omp for schedule(static)
      for(std::size_t ie = 0; ie < ne; ie++) {
        MElement *element = elements[e0 + ie];
        int dim = element->getDim();
        int type = element->getType();
        if(type == TYPE_POLYG || type == TYPE_POLYH) {
          keyLen[ie] = -3; // unsupported, Msg::Error emitted below
          continue;
        }
        if(type == TYPE_QUA || type == TYPE_HEX || type == TYPE_PYR ||
           type == TYPE_PRI)
          tNonSimplicial = true;
        std::size_t nv = element->getNumPrimaryVertices();
        if(nv > 8) {
          keyLen[ie] = -2; // treated like a degenerate cell
          continue;
        }
        for(std::size_t j = 0; j < nv; j++)
          nums[j] = element->getVertex(j)->getNum();
        // sort the numbers in place (insertion sort like sortedVertexNums)
        for(std::size_t j = 1; j < nv; j++) {
          std::size_t num = nums[j];
          std::size_t k = j;
          while(k > 0 && nums[k - 1] > num) {
            nums[k] = nums[k - 1];
            k--;
          }
          nums[k] = num;
        }
        bool degenerate = false;
        for(std::size_t j = 1; j < nv; j++)
          if(nums[j] == nums[j - 1]) degenerate = true;
        if(degenerate) {
          keyLen[ie] = -2;
          continue;
        }
        keyLen[ie] = (signed char)nv;
        for(std::size_t j = 0; j < nv; j++) keys[ie][j] = nums[j];
        for(std::size_t j = nv; j < 8; j++) keys[ie][j] = 0;
        shard[ie] = index.shardOf(dim, nums, (int)nv);
        if(tMaxDim < dim) tMaxDim = dim;

        if(domain == 0) {
          double size = fabs(element->getVolume());
          std::size_t idx = e0 + ie;
          if(tSmallest[dim].first < 0. || tSmallest[dim].first > size ||
             (tSmallest[dim].first == size && tSmallest[dim].second > idx))
            tSmallest[dim] = std::make_pair(size, idx);
          if(tBiggest[dim].first < 0. || tBiggest[dim].first < size ||
             (tBiggest[dim].first == size && tBiggest[dim].second > idx))
            tBiggest[dim] = std::make_pair(size, idx);
        }
      }
#pragma omp critical
      {
        if(tMaxDim > maxDim) maxDim = tMaxDim;
        if(tNonSimplicial) nonSimplicial = true;
        for(int i = 0; i < 4; i++) {
          if(tSmallest[i].first >= 0. &&
             (smallest[i].first < 0. || smallest[i].first > tSmallest[i].first ||
              (smallest[i].first == tSmallest[i].first &&
               smallest[i].second > tSmallest[i].second)))
            smallest[i] = tSmallest[i];
          if(tBiggest[i].first >= 0. &&
             (biggest[i].first < 0. || biggest[i].first < tBiggest[i].first ||
              (biggest[i].first == tBiggest[i].first &&
               biggest[i].second > tBiggest[i].second)))
            biggest[i] = tBiggest[i];
        }
      }
    }

    // report the skipped elements like the serial loop does
    for(std::size_t ie = 0; ie < ne; ie++) {
      if(keyLen[ie] == -3)
        Msg::Error("Mesh element type %d not implemented in homology solver",
                   elements[e0 + ie]->getType());
      else if(keyLen[ie] == -2)
        Msg::Warning("The input mesh has degenerate elements, ignored");
    }

    // pass B: deduplicate and create the element cells
#pragma omp parallel for num_threads(nthreads) schedule(dynamic) \
  reduction(+ : created)
    for(int s = 0; s < nshards; s++) {
      for(std::size_t ie = 0; ie < ne; ie++) {
        if(keyLen[ie] < 0 || shard[ie] != s) continue;
        MElement *element = elements[e0 + ie];
        std::pair<Cell **, bool> insert =
          index.insertKey(element->getDim(), keys[ie].data(), keyLen[ie], s);
        if(!insert.second) {
          if(domain) (*insert.first)->setDomain(domain);
        }
        else {
          std::pair<Cell *, bool> maybeCell =
            Cell::createCell(element, domain, _cellPool[s]);
          *insert.first = maybeCell.first;
          created++;
        }
      }
    }
  }

  _createCount += (int)created;
  _dim = maxDim;
  if(nonSimplicial) _simplicial = false;

  // resolve the smallest/biggest elements to their (deduplicated) cells
  if(domain == 0) {
    std::size_t nums[8];
    for(int dim = 0; dim < 4; dim++) {
      for(int m = 0; m < 2; m++) {
        std::pair<double, std::size_t> &best = m ? biggest[dim] : smallest[dim];
        if(best.first < 0.) continue;
        MElement *element = elements[best.second];
        std::size_t nv = element->getNumPrimaryVertices();
        for(std::size_t j = 0; j < nv; j++)
          nums[j] = element->getVertex(j)->getNum();
        std::sort(nums, nums + nv);
        std::pair<Cell **, bool> slot =
          index.insertKey(element->getDim(), nums, (int)nv);
        if(m)
          biggestElement[dim] = std::make_pair(*slot.first, best.first);
        else
          smallestElement[dim] = std::make_pair(*slot.first, best.first);
      }
    }
  }
}

void CellComplex::_insertBoundaryCells(std::vector<Cell *> &cells, int dim,
                                       int domain,
                                       CellConstructionIndex &index,
                                       int nthreads)
{
  // Parallel version of the boundary-cell creation of _insertCells, with
  // results identical to the serial loop. The parent cells are processed in
  // blocks; for each block:
  //  - pass A computes the sorted vertex keys of all candidate boundary
  //    cells and their index shards, in parallel over the parents;
  //  - pass B deduplicates the candidates and creates the new cells, in
  //    parallel over the index shards (a cell always belongs to exactly one
  //    shard, so no two threads ever touch the same hash map, and the cells
  //    are created in per-shard pools);
  //  - pass C computes the boundary orientations and adds the parent-side
  //    boundary links, in parallel over the parents (a parent is only
  //    touched by its own thread, and the boundary cells are only read);
  //  - pass D adds the facet-side coboundary links, in parallel over the
  //    shards (a boundary cell is only touched by its shard's thread).
  // All final containers are sorted and each (parent, facet) pair
  // contributes exactly one link, so the outcome does not depend on the
  // thread count or scheduling.
  const int nshards = CellConstructionIndex::numShards();
  const int stride = (dim == 3) ? 6 : (dim == 2) ? 4 : 2;
  const std::size_t blockParents =
    std::max((std::size_t)1, (std::size_t)(1 << 21) / stride);

  // the cells whose facets have to replace the reduction heuristic markers
  // (the serial loop updates the marker for each facet: the last one wins)
  std::size_t smallestIdx = cells.size(), biggestIdx = cells.size();
  if(domain == 0) {
    for(std::size_t ic = 0; ic < cells.size(); ic++) {
      if(cells[ic] == _smallestCell.first) smallestIdx = ic;
      if(cells[ic] == _biggestCell.first) biggestIdx = ic;
    }
  }

  const std::size_t bufCand = std::min(blockParents, cells.size()) * stride;
  std::vector<std::array<std::size_t, 4> > keys(bufCand);
  std::vector<signed char> keyLen(bufCand);
  std::vector<unsigned char> shard(bufCand);
  std::vector<Cell *> facet(bufCand);
  std::vector<signed char> ori(domain == 0 ? bufCand : 0);
  long long created = 0;

  for(std::size_t p0 = 0; p0 < cells.size(); p0 += blockParents) {
    const std::size_t nb = std::min(cells.size(), p0 + blockParents) - p0;
    const std::size_t ncand = nb * stride;

    // pass A: candidate keys and shards
#pragma omp parallel num_threads(nthreads)
    {
      std::vector<MVertex *> vertices;
      std::size_t nums[8];
#pragma omp for schedule(static)
      for(std::size_t ip = 0; ip < nb; ip++) {
        Cell *cell = cells[p0 + ip];
        int nbd = cell->getNumBdElements();
        for(int i = 0; i < stride; i++) {
          std::size_t c = ip * stride + i;
          if(i >= nbd) {
            keyLen[c] = -1;
            continue;
          }
          cell->findBdElement(i, vertices);
          int n = sortedVertexNums(vertices, nums);
          if(n < 0) {
            keyLen[c] = -2; // degenerate
            continue;
          }
          keyLen[c] = n;
          for(int j = 0; j < n; j++) keys[c][j] = nums[j];
          for(int j = n; j < 4; j++) keys[c][j] = 0;
          shard[c] = index.shardOf(dim - 1, nums, n);
        }
      }
    }

    // degenerate cells are ignored, like in the serial loop
    for(std::size_t c = 0; c < ncand; c++) {
      if(keyLen[c] == -2)
        Msg::Warning("The input mesh has degenerate elements, ignored");
    }

    // pass B: deduplicate and create the boundary cells
#pragma omp parallel num_threads(nthreads) reduction(+ : created)
    {
      std::vector<MVertex *> vertices;
#pragma omp for schedule(dynamic)
      for(int s = 0; s < nshards; s++) {
        for(std::size_t c = 0; c < ncand; c++) {
          if(keyLen[c] < 0 || shard[c] != s) continue;
          std::pair<Cell **, bool> insert =
            index.insertKey(dim - 1, keys[c].data(), keyLen[c], s);
          if(!insert.second) {
            Cell *fc = *insert.first;
            if(domain) fc->setDomain(domain);
            facet[c] = fc;
          }
          else {
            Cell *cell = cells[p0 + c / stride];
            cell->findBdElement((int)(c % stride), vertices);
            Cell *newCell = Cell::createCell(cell, vertices, _cellPool[s]);
            *insert.first = newCell;
            facet[c] = newCell;
            created++;
          }
        }
      }
    }

    if(domain == 0) {
      // pass C: boundary orientations and parent-side boundary links
#pragma omp parallel for num_threads(nthreads) schedule(static)
      for(std::size_t ip = 0; ip < nb; ip++) {
        Cell *cell = cells[p0 + ip];
        int nbd = cell->getNumBdElements();
        for(int i = 0; i < nbd; i++) {
          std::size_t c = ip * stride + i;
          if(keyLen[c] < 0) continue;
          int o = cell->findBdCellOrientation(facet[c], i);
          ori[c] = (signed char)o;
          cell->addBoundaryCell(o, facet[c], false);
        }
      }

      // pass D: facet-side coboundary links
#pragma omp parallel num_threads(nthreads)
      {
#pragma omp for schedule(dynamic)
        for(int s = 0; s < nshards; s++) {
          for(std::size_t c = 0; c < ncand; c++) {
            if(keyLen[c] < 0 || shard[c] != s) continue;
            facet[c]->addCoboundaryCell(ori[c], cells[p0 + c / stride],
                                        false);
          }
        }
      }

      // heuristic marker cells: like in the serial loop, the last valid
      // facet of the marker parent replaces the marker
      for(int m = 0; m < 2; m++) {
        std::size_t idx = m ? biggestIdx : smallestIdx;
        if(idx < p0 || idx >= p0 + nb) continue;
        for(int i = stride - 1; i >= 0; i--) {
          std::size_t c = (idx - p0) * stride + i;
          if(keyLen[c] < 0) continue;
          if(m)
            _biggestCell = std::make_pair(facet[c], _biggestCell.second);
          else
            _smallestCell = std::make_pair(facet[c], _smallestCell.second);
          break;
        }
      }
    }
  }
  _createCount += (int)created;
}

bool CellComplex::_removeCells(std::vector<MElement *> &elements, int domain)
{
  if(elements.empty()) return true;
  Msg::Debug("Removing %d elements and their subcells from the cell complex.",
             (int)elements.size());
  std::set<Cell *, CellPtrLessThan> removed[4];

  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *element = elements.at(i);
    int type = element->getType();
    if(type == TYPE_PYR || type == TYPE_PRI || type == TYPE_POLYG ||
       type == TYPE_POLYH) {
      Msg::Error("Mesh element type %d not implemented in homology solver",
                 type);
      return false;
    }
    Cell *cell = new Cell(element, domain);
    int dim = cell->getDim();
    auto cit = _findCell(_cells[dim], cell);
    if(cit != _cells[dim].end() && (*cit)->inComplex()) {
      removeCell(*cit);
      removed[dim].insert(cell);
    }
    else
      delete cell;
  }

  for(int dim = 3; dim > 0; dim--) {
    for(auto cit = removed[dim].begin(); cit != removed[dim].end(); cit++) {
      Cell *cell = *cit;
      for(int i = 0; i < cell->getNumBdElements(); i++) {
        Cell *newCell = new Cell(cell, i);

        auto cit2 = _findCell(_cells[dim - 1], newCell);
        if(cit2 != _cells[dim - 1].end() && (*cit2)->inComplex()) {
          removeCell(*cit2);
          removed[dim - 1].insert(newCell);
        }
        else
          delete newCell;
      }
    }
  }
  for(int dim = 3; dim >= 0; dim--) {
    for(auto cit = removed[dim].begin(); cit != removed[dim].end(); cit++) {
      delete *cit;
    }
  }
  Msg::Debug("Removed %d volumes, %d faces, %d edges, and %d vertices from the "
             "cell complex",
             (int)removed[3].size(), (int)removed[2].size(),
             (int)removed[1].size(), (int)removed[0].size());
  return true;
}

bool CellComplex::_immunizeCells(std::vector<MElement *> &elements)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *element = elements.at(i);
    Cell *cell = new Cell(element, 0);
    int dim = cell->getDim();
    auto cit = _findCell(_cells[dim], cell);
    if(cit != _cells[dim].end() && (*cit)->inComplex())
      (*cit)->setImmune(true);
    delete cell;
  }
  return true;
}

CellComplex::~CellComplex()
{
  // the elementary cells are freed wholesale with the pool: only the
  // individually allocated combined cells need to be deleted (live ones
  // here, removed ones through _removedcells)
  for(int i = 0; i < 4; i++) {
    for(std::size_t j = 0; j < _cells[i].size(); j++) {
      Cell *cell = _cells[i][j];
      if(cell->inComplex() && cell->isCombined()) {
        delete cell;
        _deleteCount++;
      }
    }
  }

  for(std::size_t i = 0; i < _removedcells.size(); i++) {
    if(_removedcells.at(i)->isCombined()) {
      delete _removedcells.at(i);
      _deleteCount++;
    }
  }
  for(std::size_t i = 0; i < _cellPool.size(); i++)
    _deleteCount += (int)_cellPool[i].size();

  Msg::Debug("Total number of cells created: %d", _createCount);
  Msg::Debug("Total number of cells deleted: %d", _deleteCount);
}

std::vector<Cell *>::const_iterator
CellComplex::_findCell(const std::vector<Cell *> &cells, Cell *cell)
{
  CellPtrLessThan lt;
  auto it = std::lower_bound(cells.begin(), cells.end(), cell, lt);
  if(it != cells.end() && !lt(cell, *it)) return it;
  return cells.end();
}

void CellComplex::_compact(int dim)
{
  if((int)_cells[dim].size() == _numLiveCells[dim]) return;
  std::vector<Cell *> live;
  live.reserve(_numLiveCells[dim]);
  for(std::size_t i = 0; i < _cells[dim].size(); i++)
    if(_cells[dim][i]->inComplex()) live.push_back(_cells[dim][i]);
  _cells[dim] = std::move(live);
}

void CellComplex::_compactIfNeeded(int dim)
{
  if((int)_cells[dim].size() > 2 * _numLiveCells[dim] + 1024) _compact(dim);
}

void CellComplex::insertCell(Cell *cell)
{
  // only combined cells are inserted after construction; their numbers are
  // strictly increasing, so appending keeps the container sorted
  _cells[cell->getDim()].push_back(cell);
  cell->setInComplex(true);
  _numLiveCells[cell->getDim()] += 1;
}

void CellComplex::removeCell(Cell *cell, bool other)
{
  if(!cell->inComplex()) {
    Msg::Debug("Tried to remove a cell from the cell complex \n");
    return;
  }

  // collect the live neighbors before detaching, since detaching modifies
  // the (co)boundary containers
  std::vector<Cell *> neighbors;
  for(auto it = cell->firstCoboundary(); it != cell->lastCoboundary(); it++)
    if(it->second.get() != 0) neighbors.push_back(it->first);
  for(std::size_t i = 0; i < neighbors.size(); i++)
    neighbors[i]->removeBoundaryCell(cell, other);

  neighbors.clear();
  for(auto it = cell->firstBoundary(); it != cell->lastBoundary(); it++)
    if(it->second.get() != 0) neighbors.push_back(it->first);
  for(std::size_t i = 0; i < neighbors.size(); i++)
    neighbors[i]->removeCoboundaryCell(cell, other);

  // leave a tombstone in _cells[dim]: erasing the entry would cost a search
  // and a shift, clearing the flag is constant time
  cell->setInComplex(false);
  int dim = cell->getDim();
  _numLiveCells[dim] -= 1;
  if(relative()) {
    if(cell->inSubdomain())
      _numSubdomainCells[dim] -= 1;
    else
      _numRelativeCells[dim] -= 1;
  }
  _removedcells.push_back(cell);
}

void CellComplex::enqueueBoundaryCells(Cell *cell, std::queue<Cell *> &Q)
{
  for(auto it = cell->firstBoundary(); it != cell->lastBoundary(); it++) {
    if(it->second.get() == 0) continue;
    Cell *c = it->first;
    if(!c->getQueued()) {
      c->setQueued(true);
      Q.push(c);
    }
  }
}

void CellComplex::enqueueCoboundaryCells(Cell *cell, std::queue<Cell *> &Q)
{
  for(auto it = cell->firstCoboundary(); it != cell->lastCoboundary(); it++) {
    if(it->second.get() == 0) continue;
    Cell *c = it->first;
    if(!c->getQueued()) {
      c->setQueued(true);
      Q.push(c);
    }
  }
}

int CellComplex::coreduction(Cell *startCell, int omit,
                             std::vector<Cell *> &omittedCells)
{
  int coreductions = 0;

  std::queue<Cell *> Q;

  Q.push(startCell);
  startCell->setQueued(true);

  Cell *s;
  while(!Q.empty()) {
    s = Q.front();
    Q.pop();
    s->setQueued(false);
    if(s->getBoundarySize() == 1 &&
       inSameDomain(s, s->firstBoundary()->first) && !s->getImmune() &&
       !s->firstBoundary()->first->getImmune() &&
       abs(s->firstBoundary()->second.get()) < 2) {
      Cell *partner = s->firstBoundary()->first;
      removeCell(s);
      enqueueCoboundaryCells(partner, Q);
      removeCell(partner);
      if(partner->getDim() == omit) { omittedCells.push_back(partner); }
      coreductions++;
    }
    else if(s->getBoundarySize() == 0) {
      enqueueCoboundaryCells(s, Q);
    }
  }
  _reduced = true;
  return coreductions;
}

int CellComplex::reduction(int dim, int omit, std::vector<Cell *> &omittedCells)
{
  if(dim < 1 || dim > 3) return 0;

  _compactIfNeeded(dim);
  _compactIfNeeded(dim - 1);

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  int count = 0;

  // Reduce (cell, unique coboundary partner) pairs. A single forward sweep
  // over the existing sorted set of dim-1 cells finds most reductions
  // directly (no auxiliary structure needed, like the original algorithm).
  // Removing a partner can make other dim-1 cells on its boundary newly
  // reducible; those are pushed to a plain follow-up queue instead of
  // repeating the whole O(n) sweep until a pass finds nothing, which can
  // cost O(passes*n) for long chains of reductions. Since a cell can only
  // be pushed as a side effect of removing one of its (few) boundary
  // cells, the total number of pushes is bounded by O(n): no dedup set is
  // needed, a stale/duplicate entry is just an O(1) no-op when popped.
  std::queue<Cell *> Q;

  auto tryReduce = [&](Cell *cell) {
    if(cell->getCoboundarySize() != 1 ||
       !inSameDomain(cell, cell->firstCoboundary()->first) ||
       cell->getImmune() || cell->firstCoboundary()->first->getImmune() ||
       abs(cell->firstCoboundary()->second.get()) >= 2)
      return false;

    Cell *partner = cell->firstCoboundary()->first;
    if(dim == omit) omittedCells.push_back(partner);

    for(auto bit = partner->firstBoundary(); bit != partner->lastBoundary();
        bit++) {
      if(bit->second.get() != 0 && bit->first != cell) Q.push(bit->first);
    }

    removeCell(partner);
    removeCell(cell);
    count++;
    return true;
  };

  auto cit = firstCell(dim - 1);
  while(cit != lastCell(dim - 1)) {
    Cell *cell = *cit;
    cit++;
    tryReduce(cell);
    if(getSize(dim) == 0 || getSize(dim - 1) == 0) break;
  }

  while(!Q.empty()) {
    Cell *cell = Q.front();
    Q.pop();
    if(getSize(dim) == 0 || getSize(dim - 1) == 0) break;
    if(!cell->inComplex()) continue;
    tryReduce(cell);
  }

  _reduced = true;
  Msg::Debug("Cell complex %d-reduction removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  return count;
}

int CellComplex::coreduction(int dim, int omit,
                             std::vector<Cell *> &omittedCells)
{
  if(dim < 1 || dim > 3) return 0;

  _compactIfNeeded(dim);
  _compactIfNeeded(dim - 1);

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  int count = 0;

  // see reduction() above for the rationale: a single sweep over the
  // existing sorted set of dim cells finds most reductions, and a plain
  // (dedup-free) follow-up queue handles the cascades that a removal can
  // trigger, instead of repeating the whole sweep until a pass is empty.
  std::queue<Cell *> Q;

  auto tryReduce = [&](Cell *cell) {
    if(cell->getBoundarySize() != 1 ||
       !inSameDomain(cell, cell->firstBoundary()->first) ||
       cell->getImmune() || cell->firstBoundary()->first->getImmune() ||
       abs(cell->firstBoundary()->second.get()) >= 2)
      return false;

    Cell *partner = cell->firstBoundary()->first;
    if(dim - 1 == omit) omittedCells.push_back(partner);

    for(auto cbit = partner->firstCoboundary();
        cbit != partner->lastCoboundary(); cbit++) {
      if(cbit->second.get() != 0 && cbit->first != cell) Q.push(cbit->first);
    }

    removeCell(partner);
    removeCell(cell);
    count++;
    return true;
  };

  auto cit = firstCell(dim);
  while(cit != lastCell(dim)) {
    Cell *cell = *cit;
    cit++;
    tryReduce(cell);
    if(getSize(dim) == 0 || getSize(dim - 1) == 0) break;
  }

  while(!Q.empty()) {
    Cell *cell = Q.front();
    Q.pop();
    if(getSize(dim) == 0 || getSize(dim - 1) == 0) break;
    if(!cell->inComplex()) continue;
    tryReduce(cell);
  }

  _reduced = true;
  Msg::Debug("Cell complex %d-coreduction removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  return count;
}

int CellComplex::getSize(int dim, bool orig)
{
  if(dim == -1) {
    std::size_t size = 0;
    if(!orig)
      for(int i = 0; i < 4; i++) size += _numLiveCells[i];
    else
      for(int i = 0; i < 4; i++) size += _ocells[i].size();
    return size;
  }
  if(!orig)
    return _numLiveCells[dim];
  else
    return _ocells[dim].size();
}

int CellComplex::getDomain(Cell *cell, std::string &str)
{
  int domain = 0;
  if(cell->inSubdomain()) {
    str = "subdomain";
    domain = 2;
  }
  if(!cell->inSubdomain()) {
    if(relative()) {
      str = "relative domain";
      domain = 0;
    }
    else {
      str = "domain";
      domain = 1;
    }
  }
  return domain;
}

Cell *CellComplex::_omitCell(Cell *cell, bool dual)
{
  Msg::Debug("Omitting %d-cell from the cell complex", cell->getDim());
  removeCell(cell, false);
  std::vector<Cell *> omittedCells;
  omittedCells.push_back(cell);
  int count = 0;

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  if(!dual) {
    for(int j = 3; j > 0; j--)
      count += reduction(j, cell->getDim(), omittedCells);
  }
  else {
    count += coreduction(cell, cell->getDim(), omittedCells);
    for(int j = 1; j <= getDim(); j++)
      count += coreduction(j, cell->getDim(), omittedCells);
  }

  CombinedCell *newcell = new CombinedCell(omittedCells);
  _createCount++;

  std::string domainstr = "";
  int domain = getDomain(cell, domainstr);

  Msg::Debug("Cell complex %d-omit removed %dv, %df, %de, %dn (total %d)",
             cell->getDim(),
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0),
             count);
  Msg::Debug(" - number of %d-cells left in %s: %d", cell->getDim(),
             domainstr.c_str(), getNumCells(cell->getDim(), domain));

  return newcell;
}

int CellComplex::reduceComplex(int combine, bool omit, bool homseq)
{
  if(!getSize(0)) return 0;

  double t1 = Cpu();
  int count = 0;
  if(relative() && !homseq) removeSubdomain();
  std::vector<Cell *> empty;
  for(int i = 3; i > 0; i--) count = count + reduction(i, -1, empty);

  if(omit && !homseq) {
    std::vector<Cell *> newCells;

    while(getSize(getDim()) != 0) {
      auto cit = firstCell(getDim());
      Cell *cell = *cit;

      newCells.push_back(_omitCell(cell, false));
    }

    for(std::size_t i = 0; i < newCells.size(); i++) {
      insertCell(newCells.at(i));
    }
  }

  double t2 = Cpu();
  if(t2 - t1 > CellComplex::_patience) {
    Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices", getSize(3),
              getSize(2), getSize(1), getSize(0));
  }

  if(combine > 0) this->combine(3);

  if(combine > 2)
    for(int i = 3; i > 0; i--) reduction(i, -1, empty);
  else if(combine > 1)
    reduction(2, -1, empty);

  if(combine > 0) this->combine(2);

  if(combine > 2)
    for(int i = 3; i > 0; i--) reduction(i, -1, empty);
  else if(combine > 1)
    reduction(1, -1, empty);

  if(combine > 0) this->combine(1);

  if(combine > 2)
    for(int i = 3; i > 0; i--) reduction(i, -1, empty);
  else if(combine > 1)
    reduction(0, -1, empty);

  _reduced = true;
  return count;
}

void CellComplex::removeSubdomain()
{
  std::vector<Cell *> toRemove;
  for(int i = 0; i < 4; i++) {
    for(auto cit = firstCell(i); cit != lastCell(i); ++cit) {
      Cell *cell = *cit;
      if(cell->inSubdomain()) toRemove.push_back(cell);
    }
  }
  for(std::size_t i = 0; i < toRemove.size(); i++) removeCell(toRemove[i]);
  _reduced = true;
}

void CellComplex::removeCells(int dim)
{
  if(dim < 0 || dim > 3) return;
  std::vector<Cell *> toRemove;
  for(auto cit = firstCell(dim); cit != lastCell(dim); ++cit) {
    toRemove.push_back(*cit);
  }
  for(std::size_t i = 0; i < toRemove.size(); i++) removeCell(toRemove[i]);
  _reduced = true;
}

int CellComplex::coreduceComplex(int combine, bool omit, int heuristic)
{
  if(!getSize(0)) return 0;

  double t1 = Cpu();

  int count = 0;
  if(relative()) removeSubdomain();
  std::vector<Cell *> empty;
  for(int dim = 0; dim < 4; dim++) {
    auto cit = firstCell(dim);
    while(cit != lastCell(dim)) {
      Cell *cell = *cit;
      int count = +coreduction(cell, -1, empty);
      if(count != 0) break;
      cit++;
    }
  }

  for(int j = 1; j <= getDim(); j++) count += coreduction(j, -1, empty);

  if(omit) {
    std::vector<Cell *> newCells;
    while(getSize(0) != 0) {
      auto cit = firstCell(0);
      Cell *cell = *cit;

      if(heuristic == -1 && _smallestCell.second != 0. &&
         hasCell(_smallestCell.first)) {
        Msg::Debug("Omitted a cell in the smallest mesh element with volume %g",
                   _smallestCell.second);
        cell = _smallestCell.first;
      }
      else if(heuristic == 1 && _biggestCell.second != 0. &&
              hasCell(_biggestCell.first)) {
        Msg::Debug("Omitted a cell in the biggest mesh element with volume %g",
                   _biggestCell.second);
        cell = _biggestCell.first;
      }

      newCells.push_back(_omitCell(cell, true));
    }
    for(std::size_t i = 0; i < newCells.size(); i++) {
      insertCell(newCells.at(i));
    }
  }

  double t2 = Cpu();
  if(t2 - t1 > CellComplex::_patience) {
    Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices", getSize(3),
              getSize(2), getSize(1), getSize(0));
  }

  if(combine > 0) this->cocombine(0);

  if(combine > 2)
    for(int i = 1; i < 4; i++) coreduction(i, -1, empty);
  else if(combine > 1)
    coreduction(1, -1, empty);

  if(combine > 0) this->cocombine(1);

  if(combine > 2)
    for(int i = 1; i < 4; i++) coreduction(i, -1, empty);
  else if(combine > 1)
    coreduction(2, -1, empty);

  if(combine > 0) this->cocombine(2);

  if(combine > 2)
    for(int i = 1; i < 4; i++) coreduction(i, -1, empty);
  else if(combine > 1)
    coreduction(3, -1, empty);

  coherent();

  _reduced = true;
  return count;
}

void CellComplex::bettiReduceComplex()
{
  reduceComplex(3, true);
  for(int i = 1; i <= 3; i++) cocombine(i - 1);
  return;
}

int CellComplex::combine(int dim)
{
  if(dim < 1 || dim > 3) return 0;

  _compactIfNeeded(dim);
  _compactIfNeeded(dim - 1);

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  double t1 = Cpu();

  std::queue<Cell *> Q;
  int count = 0;

  auto cit = firstCell(dim);
  while(cit != lastCell(dim)) {
    double t2 = Cpu();
    if(t2 - t1 > CellComplex::_patience) {
      t1 = Cpu();
      Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices",
                getSize(3), getSize(2), getSize(1), getSize(0));
    }

    Cell *cell = *cit;
    enqueueBoundaryCells(cell, Q);

    while(Q.size() != 0) {
      Cell *s = Q.front();
      Q.pop();

      if(s->getCoboundarySize() == 2 && !s->getImmune()) {
        auto it = s->firstCoboundary();
        int or1 = it->second.get();
        Cell *c1 = it->first;
        it++;
        while(it->second.get() == 0) it++;
        int or2 = it->second.get();
        Cell *c2 = it->first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2) && inSameDomain(s, c1) &&
           inSameDomain(s, c2) && c1->getImmune() == c2->getImmune()) {
          removeCell(s);

          enqueueBoundaryCells(c1, Q);
          enqueueBoundaryCells(c2, Q);

          // don't process c1/c2 as the outer iteration cell: they are
          // merged into the new combined cell right below (removing them
          // only leaves tombstones, so the iterator stays valid)
          while(cit != lastCell(dim) && (*cit == c1 || *cit == c2)) cit++;

          CombinedCell *newCell = new CombinedCell(c1, c2, (or1 != or2));
          _createCount++;
          // removed combined cells are deleted when the complex is restored
          // or destroyed; deleting them here would leave dangling tombstones
          removeCell(c1);
          removeCell(c2);
          insertCell(newCell);

          count++;
        }
      }
      s->setQueued(false);
    }

    if(cit != lastCell(dim)) cit++;
  }

  Msg::Debug("Cell complex %d-combine removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  _reduced = true;
  return count;
}

int CellComplex::cocombine(int dim)
{
  if(dim < 0 || dim > 2) return 0;

  _compactIfNeeded(dim);
  _compactIfNeeded(dim + 1);

  int numCells[4];
  for(int i = 0; i < 4; i++) numCells[i] = getSize(i);

  double t1 = Cpu();

  std::queue<Cell *> Q;
  int count = 0;

  auto cit = firstCell(dim);
  while(cit != lastCell(dim)) {
    double t2 = Cpu();
    if(t2 - t1 > CellComplex::_patience) {
      t1 = Cpu();
      Msg::Info(" - %d volumes, %d faces, %d edges, and %d vertices",
                getSize(3), getSize(2), getSize(1), getSize(0));
    }

    Cell *cell = *cit;

    enqueueCoboundaryCells(cell, Q);

    while(Q.size() != 0) {
      Cell *s = Q.front();
      Q.pop();
      if(s->getBoundarySize() == 2) {
        auto it = s->firstBoundary();
        int or1 = it->second.get();
        Cell *c1 = it->first;
        it++;
        while(it->second.get() == 0) it++;
        int or2 = it->second.get();
        Cell *c2 = it->first;

        if(!(*c1 == *c2) && abs(or1) == abs(or2) && inSameDomain(s, c1) &&
           inSameDomain(s, c2) && c1->getImmune() == c2->getImmune()) {
          removeCell(s);

          enqueueCoboundaryCells(c1, Q);
          enqueueCoboundaryCells(c2, Q);

          // see combine() for the iterator fixup and the deferred deletion
          // of removed combined cells
          while(cit != lastCell(dim) && (*cit == c1 || *cit == c2)) cit++;

          CombinedCell *newCell = new CombinedCell(c1, c2, (or1 != or2), true);
          _createCount++;
          removeCell(c1);
          removeCell(c2);
          insertCell(newCell);

          count++;
        }
      }
      s->setQueued(false);
    }

    if(cit != lastCell(dim)) cit++;
  }

  Msg::Debug("Cell complex %d-cocombine removed %dv, %df, %de, %dn", dim,
             numCells[3] - getSize(3), numCells[2] - getSize(2),
             numCells[1] - getSize(1), numCells[0] - getSize(0));
  _reduced = true;
  return count;
}

bool CellComplex::coherent()
{
  bool coherent = true;
  for(int i = 0; i < 4; i++) {
    for(auto cit = firstCell(i); cit != lastCell(i); cit++) {
      Cell *cell = *cit;
      std::map<Cell *, short int, CellPtrLessThan> boundary;
      cell->getBoundary(boundary);
      for(auto it = boundary.begin(); it != boundary.end(); it++) {
        Cell *bdCell = (*it).first;
        int ori = (*it).second;
        if(!bdCell->inComplex()) {
          Msg::Debug("Boundary cell not in cell complex! Boundary removed");
          cell->removeBoundaryCell(bdCell, false);
          coherent = false;
        }
        if(!bdCell->hasCoboundary(cell)) {
          Msg::Debug("Incoherent boundary/coboundary pair! Fixed");
          bdCell->addCoboundaryCell(ori, cell, false);
          coherent = false;
        }
      }
      std::map<Cell *, short int, CellPtrLessThan> coboundary;
      cell->getCoboundary(coboundary);
      for(auto it = coboundary.begin(); it != coboundary.end(); it++) {
        Cell *cbdCell = (*it).first;
        int ori = (*it).second;
        if(!cbdCell->inComplex()) {
          Msg::Debug("Coboundary cell not in cell complex! Coboundary removed");
          cell->removeCoboundaryCell(cbdCell, false);
          coherent = false;
        }
        if(!cbdCell->hasBoundary(cell)) {
          Msg::Debug("Incoherent coboundary/boundary pair! Fixed");
          cbdCell->addBoundaryCell(ori, cell, false);
          coherent = false;
        }
      }
    }
  }
  return coherent;
}

bool CellComplex::hasCell(Cell *cell, bool orig)
{
  if(!orig) return cell->inComplex();
  return _findCell(_ocells[cell->getDim()], cell) !=
         _ocells[cell->getDim()].end();
}

void CellComplex::getCells(std::set<Cell *, CellPtrLessThan> &cells, int dim,
                           int domain)
{
  cells.clear();
  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    Cell *cell = *cit;
    if((domain == 0 && !cell->inSubdomain()) || domain == 1 ||
       (domain == 2 && cell->inSubdomain())) {
      cells.insert(cell);
    }
  }
}

int CellComplex::getNumCells(int dim, int domain)
{
  if(domain == 0)
    return _numRelativeCells[dim];
  else if(domain == 1)
    return getSize(dim);
  else if(domain == 2)
    return _numSubdomainCells[dim];
  return 0;
}

Cell *CellComplex::getACell(int dim, int domain)
{
  int num = getNumCells(dim, domain);
  if(num < 0) Msg::Debug("Domain cell counts not in sync.");

  if(num <= 0) {
    if(domain == 0)
      Msg::Warning("%d cells in relative domain", num);
    else if(domain == 1)
      Msg::Warning("%d cells in domain", num);
    else if(domain == 2)
      Msg::Warning("%d cells in subdomain", num);
    return nullptr;
  }

  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    Cell *cell = *cit;
    if((domain == 1) || (domain == 0 && !cell->inSubdomain()) ||
       (domain == 2 && cell->inSubdomain()))
      return cell;
  }
  Msg::Debug("Domain cell counts not in sync.");
  return nullptr;
}

bool CellComplex::restoreComplex()
{
  if(_saveorig) {
    for(std::size_t i = 0; i < _removedcells.size(); i++) {
      Cell *cell = _removedcells.at(i);
      if(cell->isCombined()) {
        delete cell;
        _deleteCount++;
      }
    }
    _removedcells.clear();

    for(int i = 0; i < 4; i++) {
      // removed cells were deleted or revived through _removedcells above;
      // only live combined cells remain to be deleted here
      for(std::size_t j = 0; j < _cells[i].size(); j++) {
        Cell *cell = _cells[i][j];
        if(cell->inComplex() && cell->isCombined()) {
          delete cell;
          _deleteCount++;
        }
      }

      // plain index loop: the skipping cell iterator cannot be used here,
      // since the revived cells only become live again inside this loop
      _cells[i] = _ocells[i];
      _numLiveCells[i] = _cells[i].size();
      for(std::size_t j = 0; j < _cells[i].size(); j++) {
        Cell *cell = _cells[i][j];
        cell->setInComplex(true);
        cell->restoreCellBoundary();
        if(relative()) {
          if(cell->inSubdomain())
            _numSubdomainCells[i] += 1;
          else
            _numRelativeCells[i] += 1;
        }
      }
    }

    Msg::Info("Restored Cell Complex:");
    Msg::Info("%d volumes, %d faces, %d edges, and %d vertices", getSize(3),
              getSize(2), getSize(1), getSize(0));
    _reduced = false;
    return true;
  }
  else {
    Msg::Error("Cannot restore cell complex");
    return false;
  }
}

// compare cells by their sorted vertex numbers only, disregarding the cell
// numbers (like CellPtrLessThan does for unnumbered cells)
static bool vertexOrderLessThan(const Cell *c1, const Cell *c2)
{
  if(c1->getNumSortedVertices() != c2->getNumSortedVertices())
    return c1->getNumSortedVertices() < c2->getNumSortedVertices();
  for(int i = 0; i < c1->getNumSortedVertices(); i++) {
    if(c1->getSortedVertex(i) < c2->getSortedVertex(i)) return true;
    if(c1->getSortedVertex(i) > c2->getSortedVertex(i)) return false;
  }
  return false;
}

Cell *CellComplex::_findCellVertexOrder(Cell *cell) const
{
  const std::vector<Cell *> &cells = _cells[cell->getDim()];
  auto it = std::lower_bound(cells.begin(), cells.end(), cell,
                             vertexOrderLessThan);
  if(it != cells.end() && !vertexOrderLessThan(cell, *it)) return *it;
  return nullptr;
}

bool CellComplex::relabel(std::vector<MElement *> &subdomainElements,
                          std::vector<MElement *> &immuneElements)
{
  if(!_saveorig) return false;
  if(_reduced && !restoreComplex()) return false;

  // clear the domain and immunity markings (the reductions and the chain
  // smoothening leave the immunity flags dirty)
  for(int dim = 0; dim < 4; dim++) {
    for(std::size_t i = 0; i < _cells[dim].size(); i++) {
      _cells[dim][i]->setDomain(0);
      _cells[dim][i]->setImmune(false);
    }
  }

  // mark the closure of the subdomain elements, like the subdomain pass of
  // the constructor does: the boundary links of the restored complex
  // provide the descent to the subcells
  std::queue<Cell *> Q;
  for(std::size_t i = 0; i < subdomainElements.size(); i++) {
    Cell tmp(subdomainElements[i], 1);
    if(tmp.getNumSortedVertices() == 0) // degenerate, ignored when building
      continue;
    Cell *cell = _findCellVertexOrder(&tmp);
    if(!cell) return false;
    if(cell->getDomain() == 0) {
      cell->setDomain(1);
      Q.push(cell);
    }
  }
  while(!Q.empty()) {
    Cell *cell = Q.front();
    Q.pop();
    for(auto it = cell->firstBoundary(); it != cell->lastBoundary(); it++) {
      if(it->second.get() == 0) continue;
      Cell *bdCell = it->first;
      if(bdCell->getDomain() == 0) {
        bdCell->setDomain(1);
        Q.push(bdCell);
      }
    }
  }

  for(std::size_t i = 0; i < immuneElements.size(); i++) {
    Cell tmp(immuneElements[i], 0);
    if(tmp.getNumSortedVertices() == 0) continue;
    Cell *cell = _findCellVertexOrder(&tmp);
    if(!cell) return false;
    cell->setImmune(true);
  }

  // recompute the domain cell counts
  _relative = false;
  for(int dim = 0; dim < 4; dim++) {
    int sub = 0;
    for(std::size_t i = 0; i < _cells[dim].size(); i++)
      if(_cells[dim][i]->inSubdomain()) sub++;
    _numSubdomainCells[dim] = sub;
    _numRelativeCells[dim] = _cells[dim].size() - sub;
    if(sub > 0) _relative = true;
  }

  Msg::Debug("Relabeled the cell complex for a new subdomain");
  return true;
}

void CellComplex::printComplex(int dim)
{
  if(getSize(dim) == 0) Msg::Info("Cell complex dimension %d is empty", dim);
  for(auto cit = firstCell(dim); cit != lastCell(dim); cit++) {
    Cell *cell = *cit;
    cell->printCell();
    cell->printBoundary();
    cell->printCoboundary();
    printf("--- \n");
  }
}

int CellComplex::saveComplex(const std::string &filename)
{
  /*FILE *fp = Fopen (filename.c_str(), "w");
  if(!fp){
    printf("\nUnable to open file '%s' \n", filename.c_str());
    return 0;
  }
  printf("\nWriting file '%s'...\n", filename.c_str());

  fprintf(fp, "$Cells\n");
  fprintf(fp, "%d\n", getSize(0)+getSize(1)+getSize(2)+getSize(3));
  for(int dim = 0; dim < 4; dim++){
    for(citer cit = firstCell(dim); cit != lastCell(dim); cit++){
      Cell* cell = *cit;
      fprintf(fp, "%d %d %d %d %zu", cell->getNum(), cell->getType(),
          1, cell->getDomain(), cell->getNumVertices());
      for(std::size_t i = 0; i < cell->getNumVertices(); i++){
    fprintf(fp, " %d", cell->getVertex(i));
      }
      fprintf(fp, " %d", cell->getBoundarySize());
      for(Cell::biter bit = cell->firstBoundary();
      bit != cell->lastBoundary(); bit++){
    fprintf(fp, " %d %d", bit->first->getNum(), bit->second);
      }
      fprintf(fp, " %d", cell->getCoboundarySize());
      for(Cell::biter bit = cell->firstCoboundary();
      bit != cell->lastCoboundary(); bit++){
    fprintf(fp, " %d %d", bit->first->getNum(), bit->second);
      }
      fprintf(fp, "\n");
    }
  }

  fclose(fp);

  printf("Wrote %d cells to '%s' \n",
     getSize(0)+getSize(1)+getSize(2)+getSize(3), filename.c_str());
  */
  return 1;
}

int CellComplex::loadComplex(const std::string &filename)
{
  /*  FILE *fp = Fopen (filename.c_str(), "r");
  if(!fp){
    printf("\nUnable to open file '%s' \n", filename.c_str());
    return 0;
  }

  std::map<int, Cell*> numToCell;

  char str[256] = "XXX";
  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }

    if(feof(fp))
      break;

    if(!strncmp(&str[1], "Cells", 5)) {
      if(!fgets(str, sizeof(str), fp)) return 0;
      int numCells;
      sscanf(str, "%d", &numCells);
      for(int i = 0; i < numCells; i++) {
    int num, type, numTags;
    std::vector<int> domain;
    int tag;
    if(fscanf(fp, "%d %d %d", &num, &type, &numTags) != 3) return 0;
    for(int j = 0; j < numTags; j++){
      if(fscanf(fp, "%d", &tag) != 1) return 0;
      domain.push_back(tag);
    }

    std::vector<int> vertices;
    if(fscanf(fp, "%d", &numTags) != 1) return 0;
    for(int j = 0; j < numTags; j++){
      if(fscanf(fp, "%d", &tag) != 1) return 0;
      vertices.push_back(tag);
    }

    int dim = 0;
    if(type == 1){
      if(vertices.size() == 2) dim = 1;
      else if(vertices.size() == 3) dim = 2;
      else if(vertices.size() == 4) dim = 3;
    }

    Cell* cell = new Cell(num, dim, type, domain, vertices);
    numToCell[num] = cell;


    int numCell;
    if(fscanf(fp, "%d", &numTags) != 1) return 0;
    for(int j = 0; j < numTags; j++){
      if(fscanf(fp, "%d %d", &numCell, &tag) != 1) return 0;
    }
    if(fscanf(fp, "%d", &numTags) != 1) return 0;
    for(int j = 0; j < numTags; j++){
      if(fscanf(fp, "%d %d", &numCell, &tag) != 1) return 0;
    }

      }
    }

  }

  fclose(fp);
*/
  return 1;
}
