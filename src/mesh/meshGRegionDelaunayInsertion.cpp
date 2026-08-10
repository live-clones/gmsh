// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <array>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "OS.h"
#include "meshGRegion.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "Numeric.h"
#include "Context.h"
#include "delaunay3d.h"
#include "MEdge.h"
#include "MLine.h"
#include "ExtrudeParams.h"

int MTet4::radiusNorm = 2;

MTet4Factory::MTet4Factory() : extend(Extend2dMeshIn3dVolumes()) {}

MTetrahedron *MTet4Factory::createTet(MVertex *v0, MVertex *v1, MVertex *v2,
                                      MVertex *v3)
{
  if(!freeTet.empty()) {
    MTetrahedron *t = freeTet.back();
    freeTet.pop_back();
    t->setVertex(0, v0);
    t->setVertex(1, v1);
    t->setVertex(2, v2);
    t->setVertex(3, v3);
    t->forceNum(GModel::current()->incrementAndGetMaxElementNumber());
    return t;
  }
  return new MTetrahedron(v0, v1, v2, v3);
}

#ifdef DEBUG_BOUNDARY_RECOVERY

static void testIfBoundaryIsRecovered(GRegion *gr)
{
  std::vector<GEdge *> const &e = gr->edges();
  std::vector<GFace *> f = gr->faces();

  std::map<MEdge, GEdge *, MEdgeLessThan> edges;
  std::map<MFace, GFace *, MFaceLessThan> faces;

  auto it = e.begin();
  auto itf = f.begin();
  for(; it != e.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); ++i) {
      if(distance((*it)->lines[i]->getVertex(0),
                  (*it)->lines[i]->getVertex(1)) > 1.e-12)
        edges.insert(std::make_pair(
          MEdge((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1)),
          *it));
    }
  }
  for(; itf != f.end(); ++itf) {
    for(std::size_t i = 0; i < (*itf)->triangles.size(); ++i) {
      faces.insert(std::make_pair(MFace((*itf)->triangles[i]->getVertex(0),
                                        (*itf)->triangles[i]->getVertex(1),
                                        (*itf)->triangles[i]->getVertex(2)),
                                  *itf));
    }
  }
  Msg::Info("Searching for %d mesh edges and %d mesh faces among %d elements "
            "in region %d",
            edges.size(), faces.size(), gr->getNumMeshElements(), gr->tag());
  for(std::size_t k = 0; k < gr->getNumMeshElements(); k++) {
    for(int j = 0; j < gr->getMeshElement(k)->getNumEdges(); j++) {
      edges.erase(gr->getMeshElement(k)->getEdge(j));
    }
    for(int j = 0; j < gr->getMeshElement(k)->getNumFaces(); j++) {
      faces.erase(gr->getMeshElement(k)->getFace(j));
    }
  }
  if(edges.empty() && faces.empty()) {
    Msg::Info("All edges and faces are present in the initial mesh");
  }
  else {
    Msg::Error("All edges and faces are not present in the initial mesh");
  }
}

#endif

struct edgeContainerB {
  std::vector<std::vector<MEdge> > _hash;
  std::size_t _size, _size_obj;

  edgeContainerB(std::size_t N = 1000000)
    : _hash(N > 0 ? N : 1), _size(0), _size_obj(sizeof(MEdge))
  {
  }

  std::size_t H(const MEdge &e) const
  {
    const std::size_t h = ((std::size_t)e.getSortedVertex(0));
    return (h / _size_obj) % _hash.size();
  }

  bool find(const MEdge &e) const
  {
    const std::vector<MEdge> &v = _hash[H(e)];
    return std::find(v.begin(), v.end(), e) != v.end();
  }

  bool empty() const { return _size == 0; }

  bool addNewEdge(const MEdge &e)
  {
    std::vector<MEdge> &v = _hash[H(e)];

    if(std::find(v.begin(), v.end(), e) != v.end()) return false;

    v.push_back(e);
    _size++;

    return true;
  }
};

static void
createAllEmbeddedEdges(GRegion *gr,
                       std::set<MEdge, MEdgeLessThan> &allEmbeddedEdges)
{
  std::vector<GEdge *> const &e = gr->embeddedEdges();
  for(auto it = e.begin(); it != e.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      allEmbeddedEdges.insert(
        MEdge((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1)));
    }
  }
}

static void createAllEmbeddedEdges(GRegion *gr, edgeContainerB &embedded)
{
  std::vector<GEdge *> const &e = gr->embeddedEdges();
  for(auto it = e.begin(); it != e.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      embedded.addNewEdge(
        MEdge((*it)->lines[i]->getVertex(0), (*it)->lines[i]->getVertex(1)));
    }
  }
}

static void
createAllEmbeddedFaces(GRegion *gr,
                       std::set<MFace, MFaceLessThan> &allEmbeddedFaces)
{
  std::vector<GFace *> const &f = gr->embeddedFaces();
  for(auto it = f.begin(); it != f.end(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      allEmbeddedFaces.insert((*it)->triangles[i]->getFace(0));
    }
  }
}

int MTet4::inCircumSphere(const double *p) const
{
  // filtered test on the circumsphere cached by setup(): decide with a
  // simple distance comparison when it lies outside the roundoff bound, and
  // fall back to the exact predicates otherwise
  const double dx = p[0] - cc[0], dy = p[1] - cc[1], dz = p[2] - cc[2];
  const double d2 = dx * dx + dy * dy + dz * dz;
  const double diff = d2 - r2;
  const double s = d2 + r2;
  const double bound = sphTol * std::sqrt(s) + 1.e-12 * s;
  if(std::abs(diff) > bound) return (diff < 0) ? 1 : 0;

  double pa[3] = {base->getVertex(0)->x(), base->getVertex(0)->y(),
                  base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(), base->getVertex(1)->y(),
                  base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(), base->getVertex(2)->y(),
                  base->getVertex(2)->z()};
  double pd[3] = {base->getVertex(3)->x(), base->getVertex(3)->y(),
                  base->getVertex(3)->z()};
  double orient = orientSgn ? (double)orientSgn :
                              robustPredicates::orient3d(pa, pb, pc, pd);
  double result = robustPredicates::insphere(pa, pb, pc, pd, (double *)p) *
                  orient;
  return (result > 0) ? 1 : 0;
}

static int faces[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 3, 1}, {1, 3, 2}};

struct vertex_comparator {
  bool operator()(MVertex *const a, MVertex *const b) const
  {
    return a->getNum() < b->getNum();
  }
};

struct faceXtet {
  MVertex *v[3], *unsorted[3];
  MTet4 *t1;
  int i1;

  faceXtet(MTet4 *_t = nullptr, int iFac = 0) : t1(_t), i1(iFac)
  {
    unsorted[0] = v[0] = t1->tet()->getVertex(faces[iFac][0]);
    unsorted[1] = v[1] = t1->tet()->getVertex(faces[iFac][1]);
    unsorted[2] = v[2] = t1->tet()->getVertex(faces[iFac][2]);

    std::sort(v, v + 3, vertex_comparator());
  }

  MVertex *getVertex(int i) const { return unsorted[i]; }

  bool operator<(const faceXtet &other) const
  {
    if(v[0]->getNum() < other.v[0]->getNum()) return true;
    if(v[0]->getNum() > other.v[0]->getNum()) return false;
    if(v[1]->getNum() < other.v[1]->getNum()) return true;
    if(v[1]->getNum() > other.v[1]->getNum()) return false;
    if(v[2]->getNum() < other.v[2]->getNum()) return true;
    return false;
  }

  bool operator==(const faceXtet &other) const
  {
    return (v[0]->getNum() == other.v[0]->getNum() &&
            v[1]->getNum() == other.v[1]->getNum() &&
            v[2]->getNum() == other.v[2]->getNum());
  }

  bool visible(MVertex *v)
  {
    MVertex const *const v0 = t1->tet()->getVertex(faces[i1][0]);
    MVertex const *const v1 = t1->tet()->getVertex(faces[i1][1]);
    MVertex const *const v2 = t1->tet()->getVertex(faces[i1][2]);

    double a[3] = {v0->x(), v0->y(), v0->z()};
    double b[3] = {v1->x(), v1->y(), v1->z()};
    double c[3] = {v2->x(), v2->y(), v2->z()};
    double d[3] = {v->x(), v->y(), v->z()};

    return robustPredicates::orient3d(a, b, c, d) < 0.0;
  }
};

// Connect the tets by matching their faces, keyed on the sorted vertex
// numbers of each face so that nothing chases the vertex pointers twice.
// The faces are bucketed on their smallest vertex with a counting sort,
// which is linear and writes each face once, and only the (small) buckets
// are sorted, on the two remaining vertices: a pair of matching faces is
// then always adjacent inside one bucket. KEY is the smallest unsigned
// integer type that can hold the vertex numbers.
template <class KEY, class ITER>
void connectTetsFastT(ITER beg, ITER end)
{
  struct tetFace {
    KEY v1, v2; // the two largest vertices of the face
    KEY tet; // index of the tet in [beg, end)
    KEY i; // face of that tet
    bool operator<(const tetFace &o) const
    {
      if(v1 != o.v1) return v1 < o.v1;
      return v2 < o.v2;
    }
  };

  // the smallest vertex of a face, which is what it is bucketed on
  auto minVertex = [](const KEY n[4], int j) {
    KEY a = n[faces[j][0]];
    a = std::min(a, n[faces[j][1]]);
    return std::min(a, n[faces[j][2]]);
  };
  auto tetNums = [](MTet4 *t, KEY n[4]) {
    for(int k = 0; k < 4; k++) n[k] = (KEY)t->tet()->getVertex(k)->getNum();
  };

  // count the faces of each bucket
  std::vector<KEY> start(
    (std::size_t)GModel::current()->getMaxVertexNumber() + 2, 0);
  for(ITER IT = beg; IT != end; ++IT) {
    if((*IT)->isDeleted()) continue;
    KEY n[4];
    tetNums(*IT, n);
    for(int j = 0; j < 4; j++) start[minVertex(n, j) + 1]++;
  }
  for(std::size_t v = 1; v < start.size(); v++) start[v] += start[v - 1];
  const std::size_t nFaces = start.back();
  if(!nFaces) return;

  // scatter the faces into their bucket
  std::vector<tetFace> sorted(nFaces);
  {
    std::vector<KEY> cursor(start.begin(), start.end() - 1);
    KEY idx = 0;
    for(ITER IT = beg; IT != end; ++IT, ++idx) {
      if((*IT)->isDeleted()) continue;
      KEY n[4];
      tetNums(*IT, n);
      for(int j = 0; j < 4; j++) {
        KEY a = n[faces[j][0]], b = n[faces[j][1]], c = n[faces[j][2]];
        if(a > b) std::swap(a, b);
        if(b > c) std::swap(b, c);
        if(a > b) std::swap(a, b);
        tetFace &f = sorted[cursor[a]++];
        f.v1 = b;
        f.v2 = c;
        f.tet = idx;
        f.i = (KEY)j;
      }
    }
  }

  // inside a bucket, matching faces end up next to each other
  for(std::size_t v = 0; v + 1 < start.size(); v++) {
    const std::size_t b = start[v], e = start[v + 1];
    if(e - b < 2) continue;
    std::sort(sorted.begin() + b, sorted.begin() + e);
    for(std::size_t k = b; k + 1 < e; k++) {
      const tetFace &f1 = sorted[k];
      const tetFace &f2 = sorted[k + 1];
      if(f1.v1 == f2.v1 && f1.v2 == f2.v2) {
        MTet4 *t1 = *(beg + f1.tet);
        MTet4 *t2 = *(beg + f2.tet);
        if(t1 != t2) {
          t1->setNeigh(f1.i, t2);
          t2->setNeigh(f2.i, t1);
          ++k;
        }
      }
    }
  }
}

template <class ITER>
void connectTetsFast(ITER beg, ITER end)
{
  if(GModel::current()->getMaxVertexNumber() <= 0xffffffffull)
    connectTetsFastT<std::uint32_t>(beg, end);
  else
    connectTetsFastT<std::size_t>(beg, end);
}

template <class ITER>
void connectTets(
  ITER beg, ITER end,
  const std::set<MFace, MFaceLessThan> *allEmbeddedFaces = nullptr)
{
  std::set<faceXtet> conn;
  while(beg != end) {
    if(!(*beg)->isDeleted()) {
      for(int i = 0; i < 4; i++) {
        faceXtet fxt(*beg, i);
        // if a face is embedded, do not connect tets on both sides!
        if(!allEmbeddedFaces ||
           allEmbeddedFaces->find(MFace(fxt.v[0], fxt.v[1], fxt.v[2])) ==
             allEmbeddedFaces->end()) {
          auto found = conn.find(fxt);
          if(found == conn.end())
            conn.insert(fxt);
          else if(found->t1 != *beg) {
            found->t1->setNeigh(found->i1, *beg);
            (*beg)->setNeigh(i, found->t1);
          }
        }
      }
    }
    ++beg;
  }
}

void connectTets(std::list<MTet4 *> &l,
                 const std::set<MFace, MFaceLessThan> *embeddedFaces)
{
  connectTets(l.begin(), l.end(), embeddedFaces);
}

void connectTets(std::vector<MTet4 *> &l,
                 const std::set<MFace, MFaceLessThan> *embeddedFaces)
{
  connectTets(l.begin(), l.end(), embeddedFaces);
}

// Ensure the star-shapeness of the delaunay cavity
// We use the visibility criterion : the vertex should be visible
// by all the facets of the cavity

static void removeFromCavity(std::vector<faceXtet> &shell,
                             std::vector<MTet4 *> &cavity, faceXtet &toRemove)
{
  toRemove.t1->setDeleted(false);
  cavity.erase(
    std::remove_if(cavity.begin(), cavity.end(),
                   [toRemove](MTet4 *ptr){ return ptr == toRemove.t1; }));

  for(int i = 0; i < 4; i++) {
    faceXtet fxt2(toRemove.t1, i);
    auto it = std::find(shell.begin(), shell.end(), fxt2);
    if(it == shell.end()) {
      MTet4 *opposite = toRemove.t1->getNeigh(toRemove.i1);
      if(opposite) {
        for(int j = 0; j < 4; j++) {
          faceXtet fxt3(opposite, j);
          if(fxt3 == fxt2) { shell.push_back(fxt3); }
        }
      }
    }
    else
      shell.erase(it);
  }
}

static void extendCavity(std::vector<faceXtet> &shell,
                         std::vector<MTet4 *> &cavity, faceXtet &toExtend)
{
  MTet4 *t = toExtend.t1;
  MTet4 *opposite = t->getNeigh(toExtend.i1);
  for(int i = 0; i < 4; i++) {
    faceXtet fxt(opposite, i);
    auto it = std::find(shell.begin(), shell.end(), fxt);
    if(it == shell.end())
      shell.push_back(fxt);
    else
      shell.erase(it);
  }
  cavity.push_back(opposite);
  opposite->setDeleted(true);
}

// if all faces of the tet that are not in the shell see v, then it is ok
// either to add or to remove t from the shell
static bool verifyShell(MVertex *v, MTet4 *t, std::vector<faceXtet> &shell)
{
  if(!t) return false;
  return 1;
  int NBAD_BEFORE = 0, NBAD_AFTER = 0;
  for(int i = 0; i < 4; i++) {
    faceXtet fxt(t, i);
    bool starShaped = fxt.visible(v);
    if(!starShaped) {
      auto its = std::find(shell.begin(), shell.end(), fxt);
      if(its == shell.end())
        NBAD_AFTER++;
      else
        NBAD_BEFORE++;
    }
  }
  return 1;
  return (NBAD_AFTER < NBAD_BEFORE);
}

int makeCavityStarShaped(std::vector<faceXtet> &shell,
                         std::vector<MTet4 *> &cavity, MVertex *v)
{
  std::vector<faceXtet> wrong;
  for(auto it = shell.begin(); it != shell.end(); ++it) {
    faceXtet &fxt = *it;
    bool starShaped = fxt.visible(v);
    if(!starShaped) { wrong.push_back(fxt); }
  }
  if(wrong.empty()) return 0;
  // printf("cavity %p (shell size %d cavity size %d)is not star shaped "
  //        "(%d faces not visible), correcting it\n",
  //         v, shell.size(), cavity.size(), wrong.size());
  while(!wrong.empty()) {
    faceXtet &fxt = *(wrong.begin());
    if(std::find(shell.begin(), shell.end(), fxt) != shell.end()) {
      if(fxt.t1->getNeigh(fxt.i1) &&
         fxt.t1->getNeigh(fxt.i1)->onWhat() == fxt.t1->onWhat() &&
         verifyShell(v, fxt.t1->getNeigh(fxt.i1), shell)) {
        extendCavity(shell, cavity, fxt);
      }
      else if(verifyShell(v, fxt.t1, shell)) {
        return -1;
        removeFromCavity(shell, cavity, fxt);
      }
      else {
        return -1;
      }
    }
    wrong.erase(wrong.begin());
  }
  // printf("after : shell size %d cavity size %d\n", shell.size(),
  // cavity.size());
  return 1;
}

void findCavity(std::vector<faceXtet> &shell, std::vector<MTet4 *> &cavity,
                MVertex *v, MTet4 *t)
{
  t->setDeleted(true);
  cavity.push_back(t);

  // breadth-first traversal: the cavity vector itself acts as the queue,
  // since each tet is appended to it exactly once
  for(std::size_t idx = 0; idx < cavity.size(); idx++) {
    MTet4 *const current = cavity[idx];
    for(int i = 0; i < 4; i++) {
      MTet4 *const neighbour = current->getNeigh(i);
      if(!neighbour) { shell.push_back(faceXtet(current, i)); }
      else if(!neighbour->isDeleted()) {
        if(neighbour->inCircumSphere(v) &&
           (neighbour->onWhat() == current->onWhat())) {
          neighbour->setDeleted(true);
          cavity.push_back(neighbour);
        }
        else {
          shell.push_back(faceXtet(current, i));
        }
      }
    }
  }
}

#ifdef PRINT_TETS

static void printTets(const char *fn, std::list<MTet4 *> &cavity,
                      bool force = false)
{
  FILE *f = Fopen(fn, "w");
  if(f) {
    fprintf(f, "View \"\"{\n");
    auto ittet = cavity.begin();
    auto ittete = cavity.end();
    while(ittet != ittete) {
      MTet4 *tet = *ittet;
      if(force || !tet->isDeleted()) {
        MTetrahedron *t = tet->tet();
        t->writePOS(f, false, false, false, false, true, false);
      }
      ittet++;
    }
    fprintf(f, "};\n");
    fclose(f);
  }
}

#endif

// Priority queue of tets ordered like compareTet4Ptr (largest circumradius
// first, ties broken on the smaller element number). The keys are stored
// inline in a 4-ary heap so that comparisons do not chase MTet4 pointers,
// which made the former std::set-based container dominate the run time.
// Entries are pushed once, when the tet is created; the caller never
// re-pushes a tet, so an entry is stale only if its tet was deleted in the
// meantime. Tets whose radius is already below the refinement target can
// never be refined: they bypass the heap and sit in an unordered side list,
// which is swept periodically to release the ones that got deleted.
class tetRadiusQueue {
  struct entry {
    double radius;
    std::size_t num;
    MTet4 *t;
  };
  static bool entryLess(const entry &a, const entry &b)
  {
    if(a.radius != b.radius) return a.radius < b.radius;
    return a.num > b.num;
  }
  MTet4Factory &_factory;
  double _threshold;
  std::vector<entry> _h;
  std::vector<MTet4 *> _small;
  std::size_t _smallAlive;

public:
  tetRadiusQueue(MTet4Factory &factory, double threshold)
    : _factory(factory), _threshold(threshold), _smallAlive(0)
  {
  }
  bool empty() const { return _h.empty(); }
  std::size_t totalSize() const { return _h.size() + _small.size(); }
  void push(MTet4 *t)
  {
    if(t->getRadius() < _threshold) {
      _small.push_back(t);
      if(_small.size() > 2 * _smallAlive + 1024) sweepSmall();
      return;
    }
    _h.push_back({t->getRadius(), t->tet()->getNum(), t});
    std::size_t i = _h.size() - 1;
    while(i) {
      std::size_t p = (i - 1) >> 2;
      if(entryLess(_h[p], _h[i]))
        std::swap(_h[p], _h[i]);
      else
        break;
      i = p;
    }
  }
  MTet4 *top() const { return _h.front().t; }
  void pop()
  {
    entry last = _h.back();
    _h.pop_back();
    const std::size_t n = _h.size();
    if(!n) return;
    std::size_t i = 0;
    while(true) {
      std::size_t c = 4 * i + 1;
      if(c >= n) break;
      std::size_t best = c;
      std::size_t end = std::min(c + 4, n);
      for(std::size_t j = c + 1; j < end; j++)
        if(entryLess(_h[best], _h[j])) best = j;
      if(entryLess(last, _h[best])) {
        _h[i] = _h[best];
        i = best;
      }
      else
        break;
    }
    _h[i] = last;
  }
  void sweepSmall()
  {
    std::size_t kept = 0;
    for(std::size_t i = 0; i < _small.size(); i++) {
      if(_small[i]->isDeleted())
        _factory.Free(_small[i]);
      else
        _small[kept++] = _small[i];
    }
    _small.resize(kept);
    _smallAlive = kept;
  }
  // Free the deleted tets and return the remaining ones ordered as
  // compareTet4Ptr would order them; "extra" contains alive tets whose entry
  // was already popped (failed insertions, with their radius forced to 0)
  void drainSorted(std::vector<MTet4 *> &extra, std::vector<MTet4 *> &sorted)
  {
    for(auto &e : _h) {
      if(e.t->isDeleted()) {
        _factory.Free(e.t);
        e.t = nullptr;
      }
    }
    sweepSmall();
    for(auto t : _small)
      _h.push_back({t->getRadius(), t->tet()->getNum(), t});
    _small.clear();
    for(auto t : extra) {
      if(t->isDeleted())
        _factory.Free(t);
      else
        _h.push_back({t->getRadius(), t->tet()->getNum(), t});
    }
    std::sort(_h.begin(), _h.end(), [](const entry &a, const entry &b) {
      if(a.radius != b.radius) return a.radius > b.radius;
      return a.num < b.num;
    });
    sorted.clear();
    sorted.reserve(_h.size());
    for(auto &e : _h) {
      if(e.t) sorted.push_back(e.t);
    }
    _h.clear();
  }
};

bool insertVertexB(std::vector<faceXtet> &shell, std::vector<MTet4 *> &cavity,
                   MVertex *v, double lc1, double lc2,
                   std::vector<double> &vSizes, std::vector<double> &vSizesBGM,
                   MTet4 *t, MTet4Factory &myFactory,
                   tetRadiusQueue &allTets,
                   const std::set<MFace, MFaceLessThan> &allEmbeddedFaces)
{
  const bool hasEmbedded = !allEmbeddedFaces.empty();

  std::vector<MTet4 *> new_cavity;
  if(hasEmbedded) new_cavity.reserve(2 * shell.size());

  std::vector<MTet4 *> new_tets;
  new_tets.reserve(shell.size());

  auto it = shell.begin();

  double const lc = Extend2dMeshIn3dVolumes() ? std::min(lc1, lc2) : lc2;
  double const lcSq = (lc * .05) * (lc * .05);
  auto tooClose = [&](MVertex *w) {
    double dx = w->x() - v->x(), dy = w->y() - v->y(), dz = w->z() - v->z();
    return dx * dx + dy * dy + dz * dz < lcSq;
  };

  bool onePointIsTooClose = false;
  while(it != shell.end()) {
    MTetrahedron *tr = myFactory.createTet(it->getVertex(0), it->getVertex(1),
                                           it->getVertex(2), v);
    MTet4 *t4 = myFactory.Create(tr, vSizes, vSizesBGM, lc1, lc2);
    t4->setOnWhat(t->onWhat());

    if(tooClose(it->v[0]) || tooClose(it->v[1]) || tooClose(it->v[2]))
      onePointIsTooClose = true;

    new_tets.push_back(t4);

    if(hasEmbedded) {
      new_cavity.push_back(t4);
      MTet4 *otherSide = it->t1->getNeigh(it->i1);
      if(otherSide) new_cavity.push_back(otherSide);
    }
    ++it;
  }
  if(!onePointIsTooClose) {
    if(!hasEmbedded) {
      // connect the new tets directly, without sorting all their faces: the
      // new tet built on shell face k is (v0, v1, v2, v), so its face 0 is
      // the shell face itself, whose neighbor is the tet outside the cavity;
      // its faces 1, 2 and 3 contain the new vertex plus one shell face edge
      // each, and match the face of the new tet built on the shell face
      // sharing that edge
      struct shellEdge {
        MVertex *a, *b;
        int tetFace;
      };
      std::vector<shellEdge> edges;
      edges.reserve(3 * shell.size());
      for(std::size_t k = 0; k < shell.size(); k++) {
        MVertex *f0 = shell[k].getVertex(0);
        MVertex *f1 = shell[k].getVertex(1);
        MVertex *f2 = shell[k].getVertex(2);
        edges.push_back({std::min(f0, f2), std::max(f0, f2), (int)(4 * k + 1)});
        edges.push_back({std::min(f0, f1), std::max(f0, f1), (int)(4 * k + 2)});
        edges.push_back({std::min(f1, f2), std::max(f1, f2), (int)(4 * k + 3)});
      }
      std::sort(edges.begin(), edges.end(),
                [](const shellEdge &e1, const shellEdge &e2) {
                  if(e1.a != e2.a) return e1.a < e2.a;
                  return e1.b < e2.b;
                });
      for(std::size_t i = 0; i + 1 < edges.size(); i++) {
        const shellEdge &e1 = edges[i];
        const shellEdge &e2 = edges[i + 1];
        if(e1.a == e2.a && e1.b == e2.b) {
          MTet4 *t1 = new_tets[e1.tetFace >> 2];
          MTet4 *t2 = new_tets[e2.tetFace >> 2];
          t1->setNeigh(e1.tetFace & 3, t2);
          t2->setNeigh(e2.tetFace & 3, t1);
          ++i;
        }
      }
      for(std::size_t k = 0; k < shell.size(); k++) {
        MTet4 *otherSide = shell[k].t1->getNeigh(shell[k].i1);
        if(!otherSide) continue;
        new_tets[k]->setNeigh(0, otherSide);
        for(int j = 0; j < 4; j++) {
          if(otherSide->getNeigh(j) == shell[k].t1) {
            otherSide->setNeigh(j, new_tets[k]);
            break;
          }
        }
      }
    }
    else {
      connectTets(new_cavity.begin(), new_cavity.end(), &allEmbeddedFaces);
    }

    for(std::size_t i = 0; i < new_tets.size(); i++) allTets.push(new_tets[i]);

    return true;
  }
  else /* one point is too close */ {
    for(std::size_t i = 0; i < shell.size(); i++) myFactory.Free(new_tets[i]);
    auto ittet = cavity.begin();
    auto ittete = cavity.end();
    while(ittet != ittete) {
      (*ittet)->setDeleted(false);
      ++ittet;
    }
    return false;
  }
}

static void setLcs(MElement *t,
                   std::unordered_map<MVertex *, double> &vSizes,
                   std::unordered_set<MVertex *> &bndVertices)
{
  auto setLc = [&](MVertex *vi, MVertex *vj) {
    bndVertices.insert(vi);
    bndVertices.insert(vj);
    double dx = vi->x() - vj->x();
    double dy = vi->y() - vj->y();
    double dz = vi->z() - vj->z();
    double l = std::sqrt(dx * dx + dy * dy + dz * dz);
    auto iti = vSizes.find(vi);
    auto itj = vSizes.find(vj);
    if(CTX::instance()->mesh.lcExtendFromBoundary == 2) {
      // use smallest edge length
      if(iti == vSizes.end() || iti->second > l) vSizes[vi] = l;
      if(itj == vSizes.end() || itj->second > l) vSizes[vj] = l;
    }
    else {
      // use largest edge length
      if(iti == vSizes.end() || iti->second < l) vSizes[vi] = l;
      if(itj == vSizes.end() || itj->second < l) vSizes[vj] = l;
    }
  };

  for(int i = 0; i < t->getNumEdges(); i++) {
    MEdge e = t->getEdge(i);
    setLc(e.getVertex(0), e.getVertex(1));
  }

  // use average edge length
  /*
  double l = 0;
  for(int i = 0; i < 3; i++){
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    double dx = vi->x()-vj->x();
    double dy = vi->y()-vj->y();
    double dz = vi->z()-vj->z();
    l += sqrt(dx * dx + dy * dy + dz * dz);
  }
  l /= 3;
  for(int i = 0; i < 3; i++){
    bndVertices.insert(t->getVertex(i));
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    auto iti = vSizes.find(vi);
    auto itj = vSizes.find(vj);
    // use largest edge length
    if (iti == vSizes.end() || iti->second > l) vSizes[vi] = l;
    if (itj == vSizes.end() || itj->second > l) vSizes[vj] = l;
  }
  */
}

static void setLcs(MTetrahedron *t,
                   std::unordered_map<MVertex *, double> &vSizes,
                   std::unordered_set<MVertex *> &bndVertices)
{
  for(int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 4; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);

      if(bndVertices.find(vi) == bndVertices.end()) {
        auto iti = vSizes.find(vi);
        double const length =
          hypotenuse(vi->x() - vj->x(), vi->y() - vj->y(), vi->z() - vj->z());
        if(CTX::instance()->mesh.lcExtendFromBoundary == 2) {
          // use smallest edge length
          if(iti == vSizes.end() || iti->second > length) { vSizes[vi] = length; }
        }
        else {
          if(iti == vSizes.end() || iti->second < length) { vSizes[vi] = length; }
        }
      }

      if(bndVertices.find(vj) == bndVertices.end()) {
        auto itj = vSizes.find(vj);
        double const length =
          hypotenuse(vi->x() - vj->x(), vi->y() - vj->y(), vi->z() - vj->z());
        if(CTX::instance()->mesh.lcExtendFromBoundary == 2) {
          // use smallest edge length
          if(itj == vSizes.end() || itj->second > length) { vSizes[vj] = length; }
        }
        else {
          if(itj == vSizes.end() || itj->second < length) { vSizes[vj] = length; }
        }
      }
    }
  }
}

static void completeTheSetOfFaces(GModel *model, std::set<GFace *> &faces_bound)
{
  std::set<GFace *> toAdd;
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    if(faces_bound.find(*it) != faces_bound.end()) {
      if((*it)->compound.size()) {
        for(std::size_t i = 0; i < (*it)->compound.size(); ++i) {
          GFace *gf = static_cast<GFace *>((*it)->compound[i]);
          if(gf) toAdd.insert(gf);
        }
      }
    }
  }
  faces_bound.insert(toAdd.begin(), toAdd.end());
}

GRegion *getRegionFromBoundingFaces(GModel *model,
                                    std::set<GFace *> &faces_bound)
{
  completeTheSetOfFaces(model, faces_bound);

  auto git = model->firstRegion();
  while(git != model->lastRegion()) {
    GRegion *gr = *git;
    ExtrudeParams *ep = gr->meshAttributes.extrude;
    if((ep && ep->mesh.ExtrudeMesh) ||
       gr->meshAttributes.method == MESH_TRANSFINITE) {
      // extruded meshes or transfinite should be considered as "void"
    }
    else {
      std::vector<GFace *> _faces = (*git)->faces();
      if(_faces.size() == faces_bound.size()) {
        bool ok = true;
        for(auto it = _faces.begin(); it != _faces.end(); ++it) {
          if(faces_bound.find(*it) == faces_bound.end()) ok = false;
        }
        if(ok) return *git;
      }
    }
    ++git;
  }
  return nullptr;
}

void non_recursive_classify(MTet4 *t, std::list<MTet4 *> &theRegion,
                            std::set<GFace *> &faces_bound, GRegion *bidon,
                            GModel *model, const fs_cont &search)
{
  std::stack<MTet4 *> _stackounette;
  _stackounette.push(t);

  bool touchesOutsideBox = false;

  while(!_stackounette.empty()) {
    t = _stackounette.top();
    _stackounette.pop();
    if(!t) {
      Msg::Warning("A tetrahedron is not connected to a boundary face");
      touchesOutsideBox = true;
    }
    else if(!t->onWhat()) {
      theRegion.push_back(t);
      t->setOnWhat(bidon);
      bool FF[4] = {0, 0, 0, 0};
      for(int i = 0; i < 4; i++) {
        GFace *gfound = findInFaceSearchStructure(
          t->tet()->getVertex(faces[i][0]), t->tet()->getVertex(faces[i][1]),
          t->tet()->getVertex(faces[i][2]), search);
        if(gfound) {
          FF[i] = true;
          if(faces_bound.find(gfound) == faces_bound.end())
            faces_bound.insert(gfound);
        }
      }
      for(int i = 0; i < 4; i++) {
        if(!FF[i]) _stackounette.push(t->getNeigh(i));
      }
    }
  }
  if(touchesOutsideBox) faces_bound.clear();
}

void adaptMeshGRegion::operator()(GRegion *gr)
{
  const qmTetrahedron::Measures qm = qmTetrahedron::QMTET_GAMMA;

  typedef std::list<MTet4 *> CONTAINER;
  CONTAINER allTets;
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    allTets.push_back(new MTet4(gr->tetrahedra[i], qm));
  }
  gr->tetrahedra.clear();

  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  createAllEmbeddedFaces(gr, allEmbeddedFaces);
  std::set<MEdge, MEdgeLessThan> allEmbeddedEdges;
  createAllEmbeddedEdges(gr, allEmbeddedEdges);

  connectTets(allTets.begin(), allTets.end(), &allEmbeddedFaces);

  double t1 = Cpu(), w1 = TimeOfDay();
  std::vector<MTet4 *> illegals;
  const int nbRanges = 10;
  int quality_ranges[nbRanges];
  {
    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for(int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
        for(int i = 0; i < nbRanges; i++) {
          double low = (double)i / nbRanges;
          double high = (double)(i + 1) / nbRanges;
          if(qual >= low && qual < high) quality_ranges[i]++;
        }
      }
    }
    Msg::Info("Adaptation starts (volume = %g) with worst = %g / average = %g:",
              totalVolumeb, worst, avg / count);
    for(int i = 0; i < nbRanges; i++) {
      double low = (double)i / nbRanges;
      double high = (double)(i + 1) / nbRanges;
      Msg::Info("%3.2f < quality < %3.2f: %9d elements ", low, high,
                quality_ranges[i]);
    }
  }

  double qMin = 0.5;
  double sliverLimit = 0.2;

  int nbESwap = 0, nbFSwap = 0, nbReloc = 0, nbCollapse = 0;

  while(1) {
    std::vector<MTet4 *> newTets;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        for(int i = 0; i < 4; i++) {
          for(int j = 0; j < 4; j++) {
            if(collapseVertex(newTets, *it, i, j, qmTetrahedron::QMTET_GAMMA)) {
              nbCollapse++;
              i = j = 10;
            }
          }
        }
      }
    }

    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin) {
          for(int i = 0; i < 4; i++) {
            if(faceSwap(newTets, *it, i, qm, allEmbeddedFaces)) {
              nbFSwap++;
              break;
            }
          }
        }
      }
    }

    illegals.clear();
    for(int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;

    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin)
          for(int i = 0; i < 6; i++) {
            MEdge ed = (*it)->tet()->getEdge(i);
            if(allEmbeddedEdges.find(ed) == allEmbeddedEdges.end()) {
              if(edgeSwap(newTets, *it, i, qm, allEmbeddedFaces)) {
                nbESwap++;
                break;
              }
            }
          }
        if(!(*it)->isDeleted()) {
          if(qq < sliverLimit) illegals.push_back(*it);
          for(int i = 0; i < nbRanges; i++) {
            double low = (double)i / nbRanges;
            double high = (double)(i + 1) / nbRanges;
            if(qq >= low && qq < high) quality_ranges[i]++;
          }
        }
      }
    }

    if(!newTets.size()) break;

    // add all the new tets in the container
    for(std::size_t i = 0; i < newTets.size(); i++) {
      if(!newTets[i]->isDeleted()) { allTets.push_back(newTets[i]); }
      else {
        delete newTets[i]->tet();
        delete newTets[i];
      }
    }

    // relocate vertices
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin)
          for(int i = 0; i < 4; i++) {
            if(smoothVertex(*it, i, qm)) nbReloc++;
          }
      }
    }

    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
      }
    }
    double t2 = Cpu(), w2 = TimeOfDay();
    Msg::Info("%d edge swaps, %d face swaps, %d node collapse, %d node "
              "relocations (volume = %g): worst = %g / average = %g "
              "(Wall %gs, CPU %gs)",
              nbESwap, nbFSwap, nbCollapse, nbReloc, totalVolumeb, worst,
              avg / count, w2 - w1, t2 - t1);
    break;
  }

  int nbSlivers = 0;
  for(std::size_t i = 0; i < illegals.size(); i++)
    if(!(illegals[i]->isDeleted())) nbSlivers++;

  if(nbSlivers) {
    Msg::Info("%d illegal tets are still in the mesh, trying to remove them",
              nbSlivers);
  }
  else {
    Msg::Info("No illegal tets in the mesh :-)", nbSlivers);
  }

  for(int i = 0; i < nbRanges; i++) {
    double low = (double)i / nbRanges;
    double high = (double)(i + 1) / nbRanges;
    Msg::Info("%3.2f < quality < %3.2f: %9d elements", low, high,
              quality_ranges[i]);
  }

  for(auto it = allTets.begin(); it != allTets.end(); ++it) {
    if(!(*it)->isDeleted()) {
      gr->tetrahedra.push_back((*it)->tet());
      delete *it;
    }
    else {
      delete(*it)->tet();
      delete *it;
    }
  }
}

void optimizeMesh(GRegion *gr, const qmTetrahedron::Measures &qm)
{
  double qMin = CTX::instance()->mesh.optimizeThreshold;

  if(qMin <= 0.0) return;

  if(gr->tetrahedra.empty()) return;

  typedef std::vector<MTet4 *> CONTAINER;
  // the initial MTet4s live in one contiguous block; the local mesh
  // modifications allocate the ones they create individually
  std::vector<MTet4> initialTets(gr->tetrahedra.size());
  auto inBlock = [&initialTets](MTet4 *t) {
    return t >= initialTets.data() &&
           t < initialTets.data() + initialTets.size();
  };
  CONTAINER allTets;
  allTets.reserve(gr->tetrahedra.size());
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    MTet4 *t = &initialTets[i];
    *t = MTet4(gr->tetrahedra[i], qm);
    t->setOnWhat(gr);
    allTets.push_back(t);
  }
  gr->tetrahedra.clear();

  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  createAllEmbeddedFaces(gr, allEmbeddedFaces);

  std::set<MEdge, MEdgeLessThan> allEmbeddedEdges;
  createAllEmbeddedEdges(gr, allEmbeddedEdges);

  if(allEmbeddedFaces.empty()) {
    connectTetsFast(allTets.begin(), allTets.end());
  }
  else {
    // daaaaaaamn slow !!!
    connectTets(allTets.begin(), allTets.end(), &allEmbeddedFaces);
  }

  double t1 = Cpu(), w1 = TimeOfDay();
  std::vector<MTet4 *> illegals;
  const int nbRanges = 10;
  int quality_ranges[nbRanges];
  {
    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for(int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
        for(int i = 0; i < nbRanges; i++) {
          double low = (double)i / nbRanges;
          double high = (double)(i + 1) / nbRanges;
          if(qual >= low && qual < high) quality_ranges[i]++;
        }
      }
    }
    Msg::Info(
      "Optimization starts (volume = %g) with worst = %g / average = %g:",
      totalVolumeb, worst, avg / count);
    for(int i = 0; i < nbRanges; i++) {
      double low = (double)i / nbRanges;
      double high = (double)(i + 1) / nbRanges;
      Msg::Info("%3.2f < quality < %3.2f : %9d elements", low, high,
                quality_ranges[i]);
    }
  }

  double sliverLimit = 0.001;
  int nbESwap = 0, nbReloc = 0;
  double worstA = 0.0;

  std::set<MTetrahedron*> to_delete;

  while(1) {
    std::vector<MTet4 *> newTets;

    illegals.clear();
    for(int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;

    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < qMin) {
          for(int i = 0; i < 6; i++) {
            MEdge ed = (*it)->tet()->getEdge(i);
            if(allEmbeddedEdges.find(ed) == allEmbeddedEdges.end()) {
              if(edgeSwap(newTets, *it, i, qm, allEmbeddedFaces)) {
                nbESwap++;
                break;
              }
            }
          }
        }
        if(!(*it)->isDeleted()) {
          if(qq < sliverLimit) illegals.push_back(*it);
          for(int i = 0; i < nbRanges; i++) {
            double low = (double)i / nbRanges;
            double high = (double)(i + 1) / nbRanges;
            if(qq >= low && qq < high) quality_ranges[i]++;
          }
        }
      }
    }

    if(!newTets.size()) { break; }

    // add all the new tets in the container
    for(std::size_t i = 0; i < newTets.size(); i++) {
      if(!newTets[i]->isDeleted()) { allTets.push_back(newTets[i]); }
      else {
        to_delete.insert(newTets[i]->tet());
        delete newTets[i];
      }
    }

    // relocate vertices
    if(gr->hexahedra.empty() && gr->prisms.empty() && gr->pyramids.empty()) {
      for(auto it = allTets.begin(); it != allTets.end(); ++it) {
        if(!(*it)->isDeleted()) {
          double qq = (*it)->getQuality();
          if(qq < qMin) {
            for(int i = 0; i < 4; i++) {
              if(smoothVertex(*it, i, qm)) nbReloc++;
            }
          }
        }
      }
    }

    // only the qualities are needed here: they are cached in the MTet4s,
    // while the volumes would each chase the four vertices of a tet (the
    // total volume is reported once, at the end)
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
      }
    }

    double t2 = Cpu(), w2 = TimeOfDay();
    Msg::Info("%d edge swaps, %d node relocations: "
              "worst = %g / average = %g (Wall %gs, CPU %gs)",
              nbESwap, nbReloc, worst, avg / count, w2 - w1, t2 - t1);
    if(worstA != 0.0 && worst - worstA < 1.e-6) break;
    worstA = worst;
  }

  for(auto t : to_delete) delete t;

  {
    double totalVolumeb = 0.0, worst = 1.0, avg = 0.;
    int count = 0;
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        totalVolumeb += fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
      }
    }
    Msg::Info("Optimization done (volume = %g) with worst = %g / average = %g:",
              totalVolumeb, worst, count ? avg / count : 0.);
  }

  if(illegals.size()) {
    Msg::Warning("%d ill-shaped tets are still in the mesh", illegals.size());
  }
  else {
    Msg::Info("No ill-shaped tets in the mesh :-)");
  }

  for(int i = 0; i < nbRanges; i++) {
    double low = (double)i / nbRanges;
    double high = (double)(i + 1) / nbRanges;
    Msg::Info("%3.2f < quality < %3.2f : %9d elements", low, high,
              quality_ranges[i]);
  }

  for(auto it = allTets.begin(); it != allTets.end(); ++it) {
    if(!(*it)->isDeleted()) { gr->tetrahedra.push_back((*it)->tet()); }
    else {
      delete(*it)->tet();
    }
    if(!inBlock(*it)) delete *it;
  }
}

double tetcircumcenter(double a[3], double b[3], double c[3], double d[3],
                       double circumcenter[3], double *xi, double *eta,
                       double *zeta)
{
  double xba, yba, zba, xca, yca, zca, xda, yda, zda;
  double balength, calength, dalength;
  double xcrosscd, ycrosscd, zcrosscd;
  double xcrossdb, ycrossdb, zcrossdb;
  double xcrossbc, ycrossbc, zcrossbc;
  double denominator;
  double xcirca, ycirca, zcirca;

  /* Use coordinates relative to point `a' of the tetrahedron. */
  xba = b[0] - a[0];
  yba = b[1] - a[1];
  zba = b[2] - a[2];
  xca = c[0] - a[0];
  yca = c[1] - a[1];
  zca = c[2] - a[2];
  xda = d[0] - a[0];
  yda = d[1] - a[1];
  zda = d[2] - a[2];
  /* Squares of lengths of the edges incident to `a'. */
  balength = xba * xba + yba * yba + zba * zba;
  calength = xca * xca + yca * yca + zca * zca;
  dalength = xda * xda + yda * yda + zda * zda;
  /* Cross products of these edges. */
  xcrosscd = yca * zda - yda * zca;
  ycrosscd = zca * xda - zda * xca;
  zcrosscd = xca * yda - xda * yca;
  xcrossdb = yda * zba - yba * zda;
  ycrossdb = zda * xba - zba * xda;
  zcrossdb = xda * yba - xba * yda;
  xcrossbc = yba * zca - yca * zba;
  ycrossbc = zba * xca - zca * xba;
  zcrossbc = xba * yca - xca * yba;

  /* Calculate the denominator of the formulae. */
  /* Use orient3d() from http://www.cs.cmu.edu/~quake/robust.html     */
  /*   to ensure a correctly signed (and reasonably accurate) result, */
  /*   avoiding any possibility of division by zero.                  */
  const double xxx = robustPredicates::orient3d(b, c, d, a);
  denominator = 0.5 / xxx;

  /* Calculate offset (from `a') of circumcenter. */
  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
           denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
           denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
           denominator;
  circumcenter[0] = xcirca + a[0];
  circumcenter[1] = ycirca + a[1];
  circumcenter[2] = zcirca + a[2];

  if(xi != (double *)nullptr) {
    /* To interpolate a linear function at the circumcenter, define a    */
    /*   coordinate system with a xi-axis directed from `a' to `b',      */
    /*   an eta-axis directed from `a' to `c', and a zeta-axis directed  */
    /*   from `a' to `d'.  The values for xi, eta, and zeta are computed */
    /*   by Cramer's Rule for solving systems of linear equations.       */
    *xi = (xcirca * xcrosscd + ycirca * ycrosscd + zcirca * zcrosscd) *
          (2.0 * denominator);
    *eta = (xcirca * xcrossdb + ycirca * ycrossdb + zcirca * zcrossdb) *
           (2.0 * denominator);
    *zeta = (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
            (2.0 * denominator);
  }
  return xxx;
}

double tetcircumcenterBounded(double a[3], double b[3], double c[3],
                              double d[3], double circumcenter[3], double *err)
{
  // this function must perform exactly the same floating-point operations as
  // tetcircumcenter() so that the computed center is bit-identical; it only
  // accumulates in addition a conservative bound on the roundoff error of
  // the result
  double xba, yba, zba, xca, yca, zca, xda, yda, zda;
  double balength, calength, dalength;
  double xcrosscd, ycrosscd, zcrosscd;
  double xcrossdb, ycrossdb, zcrossdb;
  double xcrossbc, ycrossbc, zcrossbc;
  double denominator;
  double xcirca, ycirca, zcirca;

  xba = b[0] - a[0];
  yba = b[1] - a[1];
  zba = b[2] - a[2];
  xca = c[0] - a[0];
  yca = c[1] - a[1];
  zca = c[2] - a[2];
  xda = d[0] - a[0];
  yda = d[1] - a[1];
  zda = d[2] - a[2];
  balength = xba * xba + yba * yba + zba * zba;
  calength = xca * xca + yca * yca + zca * zca;
  dalength = xda * xda + yda * yda + zda * zda;
  xcrosscd = yca * zda - yda * zca;
  ycrosscd = zca * xda - zda * xca;
  zcrosscd = xca * yda - xda * yca;
  xcrossdb = yda * zba - yba * zda;
  ycrossdb = zda * xba - zba * xda;
  zcrossdb = xda * yba - xba * yda;
  xcrossbc = yba * zca - yca * zba;
  ycrossbc = zba * xca - zca * xba;
  zcrossbc = xba * yca - xca * yba;

  const double xxx = robustPredicates::orient3d(b, c, d, a);
  denominator = 0.5 / xxx;

  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
           denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
           denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
           denominator;
  circumcenter[0] = xcirca + a[0];
  circumcenter[1] = ycirca + a[1];
  circumcenter[2] = zcirca + a[2];

  // bound the roundoff on (xcirca, ycirca, zcirca): the dominant error terms
  // come from the cancellations in the cross products and in the numerator
  // sums, all bounded by the same expressions on absolute values; the
  // constant includes a generous safety margin on the ~10 ulp worst case
  const double axcross = fabs(yca * zda) + fabs(yda * zca) + fabs(yda * zba) +
                         fabs(yba * zda) + fabs(yba * zca) + fabs(yca * zba);
  const double aycross = fabs(zca * xda) + fabs(zda * xca) + fabs(zda * xba) +
                         fabs(zba * xda) + fabs(zba * xca) + fabs(zca * xba);
  const double azcross = fabs(xca * yda) + fabs(xda * yca) + fabs(xda * yba) +
                         fabs(xba * yda) + fabs(xba * yca) + fabs(xca * yba);
  const double maxlength = std::max(balength, std::max(calength, dalength));
  *err = 4096. * 2.220446049250313e-16 * maxlength *
         (axcross + aycross + azcross) * fabs(denominator);

  return xxx;
}

static int isCavityCompatibleWithEmbeddedEdges(std::vector<MTet4 *> &cavity,
                                               std::vector<faceXtet> &shell,
                                               edgeContainerB &allEmbeddedEdges)
{
  if(allEmbeddedEdges.empty()) return 1;
  std::vector<MEdge> ed;
  ed.reserve(shell.size() * 3);

  for(auto it = shell.begin(); it != shell.end(); it++) {
    ed.push_back(MEdge(it->v[0], it->v[1]));
    ed.push_back(MEdge(it->v[1], it->v[2]));
    ed.push_back(MEdge(it->v[2], it->v[0]));
  }

  for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
    for(int j = 0; j < 6; j++) {
      MEdge e = (*itc)->tet()->getEdge(j);
      if(std::find(ed.begin(), ed.end(), e) == ed.end() &&
         allEmbeddedEdges.find(e)) {
        return 0;
      }
    }
  }
  return 1;
}

static int isCavityCompatibleWithEmbeddedFace(
  const std::vector<MTet4 *> &cavity, const std::vector<faceXtet> &shell,
  const std::set<MFace, MFaceLessThan> &allEmbeddedFaces)
{
  if(allEmbeddedFaces.empty()) return 1;
  std::vector<MFace> shellFaces;
  shellFaces.reserve(shell.size());

  for(auto it = shell.begin(); it != shell.end(); it++) {
    const faceXtet &face = (*it);
    shellFaces.push_back(
      MFace(face.unsorted[0], face.unsorted[1], face.unsorted[2]));
  }

  for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
    for(int j = 0; j < 4; j++) {
      MFace f = (*itc)->tet()->getFace(j);
      if((std::find(shellFaces.begin(), shellFaces.end(), f) ==
          shellFaces.end()) &&
         (allEmbeddedFaces.count(f) > 0)) {
        return 0;
      }
    }
  }
  return 1;
}

static void refineRegionMTet4(GRegion *gr, int maxIter,
                              double worstTetRadiusTarget,
                              std::vector<MTet4 *> &tets0,
                              MTet4Factory &myFactory,
                              std::vector<double> &vSizes,
                              std::vector<double> &vSizesBGM, int &NUM,
                              const std::set<MFace, MFaceLessThan> &allEmbeddedFaces,
                              edgeContainerB &allEmbeddedEdges);

static void refineRegionFlat(GRegion *gr, int maxIter,
                             double worstTetRadiusTarget,
                             std::vector<MTet4 *> &tets0,
                             MTet4Factory &myFactory,
                             std::vector<double> &vSizes,
                             std::vector<double> &vSizesBGM, int &NUM,
                             const std::set<MFace, MFaceLessThan> &allEmbeddedFaces,
                             edgeContainerB &allEmbeddedEdges);

void insertVerticesInRegion(GRegion *gr, int maxIter,
                            double worstTetRadiusTarget, bool _classify,
                            splitQuadRecovery *sqr)
{
#ifdef DEBUG_BOUNDARY_RECOVERY
  testIfBoundaryIsRecovered(gr);
#endif

  std::vector<double> vSizes, vSizesBGM;
  MTet4Factory myFactory;
  // initial tets, ordered as the tetRadiusQueue (and the former std::set
  // container) would order them, so that the classification below - whose
  // iteration order can influence vertex and element ordering - is unchanged
  std::vector<MTet4 *> tets0;
  int NUM = 0;

  // leave this in a block so the map gets deallocated directly
  {
    std::unordered_map<MVertex *, double> vSizesMap;
    std::unordered_set<MVertex *> bndVertices;

    for(auto rit = gr->model()->firstRegion(); rit != gr->model()->lastRegion();
        ++rit) {
      std::vector<GEdge *> const &e = (*rit)->embeddedEdges();
      for(auto it = e.begin(); it != e.end(); ++it) {
        for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
          MVertex *vi = (*it)->lines[i]->getVertex(0);
          MVertex *vj = (*it)->lines[i]->getVertex(1);
          double dx = vi->x() - vj->x();
          double dy = vi->y() - vj->y();
          double dz = vi->z() - vj->z();
          double l = std::sqrt(dx * dx + dy * dy + dz * dz);

          auto iti = vSizesMap.find(vi);
          auto itj = vSizesMap.find(vj);

          // smallest tet edge
          if(iti == vSizesMap.end() || iti->second > l) vSizesMap[vi] = l;
          if(itj == vSizesMap.end() || itj->second > l) vSizesMap[vj] = l;
        }
      }
    }

    for(auto rit = gr->model()->firstRegion(); rit != gr->model()->lastRegion();
        ++rit) {
      std::vector<GVertex *> const &vertices = (*rit)->embeddedVertices();
      for(auto it = vertices.begin(); it != vertices.end(); ++it) {
        MVertex *v = (*it)->getMeshVertex(0);
        double l = (*it)->prescribedMeshSizeAtVertex();
        auto itv = vSizesMap.find(v);
        if(itv == vSizesMap.end() || itv->second > l) vSizesMap[v] = l;
      }
    }

    for(auto it = gr->model()->firstFace(); it != gr->model()->lastFace();
        ++it) {
      GFace *gf = *it;
      for(std::size_t i = 0; i < gf->triangles.size(); i++) {
        setLcs(gf->triangles[i], vSizesMap, bndVertices);
      }
      for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
        setLcs(gf->quadrangles[i], vSizesMap, bndVertices);
      }
    }
    //if(sqr) {
//      for(auto it = sqr->getTri().begin(); it != sqr->getTri().end(); ++it)
  //      setLcs(it->first, vSizesMap, bndVertices);
    //}
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++)
      setLcs(gr->tetrahedra[i], vSizesMap, bndVertices);

    // assign the vertex indices in the same order (by vertex number) as the
    // former MVertexPtrLessThan-sorted map
    std::vector<std::pair<std::size_t, std::pair<MVertex *, double> > > bynum;
    bynum.reserve(vSizesMap.size());
    for(auto it = vSizesMap.begin(); it != vSizesMap.end(); ++it)
      bynum.push_back(
        std::make_pair(it->first->getNum(), std::make_pair(it->first,
                                                           it->second)));
    std::sort(bynum.begin(), bynum.end(),
              [](const std::pair<std::size_t, std::pair<MVertex *, double> > &a,
                 const std::pair<std::size_t, std::pair<MVertex *, double> > &b)
              { return a.first < b.first; });
    for(auto &p : bynum) {
      p.second.first->setIndex(NUM++);
      vSizes.push_back(p.second.second);
      vSizesBGM.push_back(p.second.second);
    }
  }

  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    gr->tetrahedra[i]->setVolumePositive();
    tets0.push_back(myFactory.Create(gr->tetrahedra[i], vSizes, vSizesBGM));
  }
  std::sort(tets0.begin(), tets0.end(), compareTet4Ptr());

  gr->tetrahedra.clear();

  connectTetsFast(tets0.begin(), tets0.end());

  // classify the tets on the right region

  if(_classify) {
    fs_cont search;
    buildFaceSearchStructure(gr->model(), search, true); // only triangles
    if(sqr) search.insert(sqr->getTri().begin(), sqr->getTri().end());

    for(auto it = tets0.begin(); it != tets0.end(); ++it) {
      if(!(*it)->onWhat()) {
        std::list<MTet4 *> theRegion;
        std::set<GFace *> faces_bound;
        GRegion *bidon = (GRegion *)123;
        double _t1 = Cpu(), _w1 = TimeOfDay();
        Msg::Debug("start with a non classified tet");
        non_recursive_classify(*it, theRegion, faces_bound, bidon, gr->model(),
                               search);
        double _t2 = Cpu(), _w2 = TimeOfDay();
        Msg::Debug("Found %d tets with %d faces (Wall %gs, CPU %gs)",
                   theRegion.size(), faces_bound.size(), _w2 - _w1, _t2 - _t1);
        GRegion *myGRegion =
          getRegionFromBoundingFaces(gr->model(), faces_bound);
        if(myGRegion && myGRegion->tetrahedra.empty()) {
          // a geometrical region (with no mesh) associated to the list of faces
          // has been found
          Msg::Info("Found volume %d", myGRegion->tag());
          for(auto it2 = theRegion.begin(); it2 != theRegion.end(); ++it2) {
            (*it2)->setOnWhat(myGRegion);

            // Make sure that Steiner points will end up in the right region
            std::vector<MVertex *> vertices;
            (*it2)->tet()->getVertices(vertices);
            for(auto itv = vertices.begin(); itv != vertices.end(); ++itv) {
              if((*itv)->onWhat() != nullptr && (*itv)->onWhat()->dim() == 3 &&
                 (*itv)->onWhat() != myGRegion) {
                myGRegion->addMeshVertex((*itv));
                (*itv)->setEntity(myGRegion);
              }
            }
          }
        }
        else {
          // the tets are in the void
          Msg::Info("Found void region");
          for(auto it2 = theRegion.begin(); it2 != theRegion.end(); ++it2)
            (*it2)->setDeleted(true);
        }
      }
    }
    search.clear();
  }
  else {
    // FIXME ... too simple
    for(auto it = tets0.begin(); it != tets0.end(); ++it)
      (*it)->setOnWhat(gr);
  }

  // store all embedded edges and faces
  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  std::size_t N = 0;
  for(auto it = gr->model()->firstRegion(); it != gr->model()->lastRegion();
      ++it) {
    for(auto e : (*it)->embeddedEdges())
      N += e->getNumMeshElements();
  }
  edgeContainerB allEmbeddedEdges(N);
  for(auto it = gr->model()->firstRegion(); it != gr->model()->lastRegion();
      ++it) {
    createAllEmbeddedFaces((*it), allEmbeddedFaces);
    createAllEmbeddedEdges((*it), allEmbeddedEdges);
  }
  if(allEmbeddedFaces.empty()) {
    // the neighbors computed before the classification are still valid: only
    // remove the links towards the tets that were deleted because they lie in
    // the void, exactly as reconnecting the alive tets from scratch would
    for(auto it = tets0.begin(); it != tets0.end(); ++it) {
      for(int i = 0; i < 4; i++) {
        MTet4 *n = (*it)->getNeigh(i);
        if(n && n->isDeleted()) (*it)->setNeigh(i, nullptr);
      }
    }
  }
  else {
    // rebuild the adjacencies without connecting tets across embedded faces
    for(auto it = tets0.begin(); it != tets0.end(); ++it) {
      (*it)->setNeigh(0, nullptr);
      (*it)->setNeigh(1, nullptr);
      (*it)->setNeigh(2, nullptr);
      (*it)->setNeigh(3, nullptr);
    }
    connectTets(tets0.begin(), tets0.end(), &allEmbeddedFaces);
  }
  Msg::Debug("All %d tets were connected", tets0.size());

  if(CTX::instance()->mesh.flatRefineDelaunay3D)
    refineRegionFlat(gr, maxIter, worstTetRadiusTarget, tets0, myFactory,
                     vSizes, vSizesBGM, NUM, allEmbeddedFaces,
                     allEmbeddedEdges);
  else
    refineRegionMTet4(gr, maxIter, worstTetRadiusTarget, tets0, myFactory,
                      vSizes, vSizesBGM, NUM, allEmbeddedFaces,
                      allEmbeddedEdges);
}

// Bowyer-Watson refinement kernel: consumes the classified and connected tets
// of tets0 (all MTet4 wrappers are freed), grows vSizes/vSizesBGM and the
// vertex index counter NUM as nodes are inserted, adds the new vertices and
// the final tets to their respective regions
static void refineRegionMTet4(GRegion *gr, int maxIter,
                              double worstTetRadiusTarget,
                              std::vector<MTet4 *> &tets0,
                              MTet4Factory &myFactory,
                              std::vector<double> &vSizes,
                              std::vector<double> &vSizesBGM, int &NUM,
                              const std::set<MFace, MFaceLessThan> &allEmbeddedFaces,
                              edgeContainerB &allEmbeddedEdges)
{
  tetRadiusQueue allTets(myFactory, worstTetRadiusTarget);

  for(auto t : tets0) allTets.push(t);
  tets0.clear();

  // alive tets whose queue entry was consumed by a failed insertion
  std::vector<MTet4 *> failedTets;

  int ITER = 0, REALCOUNT = 0;
  int NB_CORRECTION_OF_CAVITY = 0;
  int COUNT_MISS_1 = 0;
  int COUNT_MISS_2 = 0;

  double t1 = TimeOfDay();

  // scratch vectors reused across iterations
  std::vector<faceXtet> shell;
  std::vector<MTet4 *> cavity;

  // main loop in Delaunay inserstion starts here

  while(1) {
    if(maxIter > 0 && ITER >= maxIter) {
      Msg::Info("Max. number of iterations reached (%d) - stopping insertion",
                ITER);
      break;
    }
    if(allTets.empty()) {
      if(!allTets.totalSize())
        Msg::Warning("No tetrahedra in region %d", gr->tag());
      break;
    }

    MTet4 *worst = allTets.top();

    if(worst->isDeleted()) {
      allTets.pop();
      myFactory.Free(worst);
    }
    else {
      if(ITER++ % 500 == 0)
        Msg::Info("It. %d - %d nodes created - worst tet radius %g (nodes "
                  "removed %d %d)",
                  ITER - 1, REALCOUNT, worst->getRadius(), COUNT_MISS_1,
                  COUNT_MISS_2);
      if(worst->getRadius() < worstTetRadiusTarget) break;
      allTets.pop();
      MTet4 *popped = worst;

      double center[3];
      double uvw[3];
      // circumcenter cached at creation, computed with the exact same
      // floating-point operations as tetcircumcenter()
      worst->cachedCircumcenter(center);

      // A TEST !!!
      shell.clear();
      cavity.clear();
      MVertex vv(center[0], center[1], center[2], worst->onWhat());
      findCavity(shell, cavity, &vv, worst);
      bool FOUND = false;
      for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
        MTetrahedron *toto = (*itc)->tet();
        // (*itc)->setDeleted(false);
        toto->xyz2uvw(center, uvw);
        //f("uvw = %g %g %g\n", uvw[0], uvw[1], uvw[2]);
        if(toto->isInside(uvw[0], uvw[1], uvw[2])) {
          worst = (*itc);
          FOUND = true;
          break;
        }
      }
      // END TEST

      if(FOUND && (!allEmbeddedEdges.empty() || !allEmbeddedFaces.empty())) {
        FOUND =
          isCavityCompatibleWithEmbeddedEdges(cavity, shell,
                                              allEmbeddedEdges) &&
          isCavityCompatibleWithEmbeddedFace(cavity, shell, allEmbeddedFaces);
      }

      bool correctedCavityIncompatibleWithEmbeddedEntities = false;

      if(FOUND) {
        MVertex *v =
          new MVertex(center[0], center[1], center[2], worst->onWhat());
        v->setIndex(NUM++);
#ifdef PRINT_TETS
        printTets("before.pos", cavity, true);
#endif
        bool starShaped = true;
        bool correctCavity = false;
        while(1) {
          int k = makeCavityStarShaped(shell, cavity, v);
          if(k == -1) {
            starShaped = false;
            break;
          }
          else if(k == 0)
            break;
          else if(k == 1)
            correctCavity = true;
        }
        if(correctCavity && starShaped) {
          NB_CORRECTION_OF_CAVITY++;
          if(!isCavityCompatibleWithEmbeddedEdges(cavity, shell,
                                                  allEmbeddedEdges) ||
             !isCavityCompatibleWithEmbeddedFace(cavity, shell,
                                                 allEmbeddedFaces)) {
            correctedCavityIncompatibleWithEmbeddedEntities = true;
          }
        }
        double lc1 = (1 - uvw[0] - uvw[1] - uvw[2]) *
                       vSizes[worst->tet()->getVertex(0)->getIndex()] +
                     uvw[0] * vSizes[worst->tet()->getVertex(1)->getIndex()] +
                     uvw[1] * vSizes[worst->tet()->getVertex(2)->getIndex()] +
                     uvw[2] * vSizes[worst->tet()->getVertex(3)->getIndex()];
        double lc2 =
          BGM_MeshSize(worst->onWhat(), 0, 0, center[0], center[1], center[2]);

        if(correctedCavityIncompatibleWithEmbeddedEntities || !starShaped ||
           !insertVertexB(shell, cavity, v, lc1, lc2, vSizes, vSizesBGM, worst,
                          myFactory, allTets, allEmbeddedFaces)) {
          COUNT_MISS_1++;
          popped->forceRadius(0.);
          failedTets.push_back(popped);
          for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
            (*itc)->setDeleted(false);
          delete v;
          NUM--;
        }
        else {
          vSizes.push_back(lc1);
          vSizesBGM.push_back(lc2);
          REALCOUNT++;
          v->onWhat()->mesh_vertices.push_back(v);
        }
      }

      else {
        popped->forceRadius(0.);
        failedTets.push_back(popped);
        COUNT_MISS_2++;
        for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
          (*itc)->setDeleted(false);
      }
    }
  }

  // free the deleted tets and recover the remaining ones, ordered as the
  // former std::set container would order them
  std::vector<MTet4 *> aliveTets;
  allTets.drainSorted(failedTets, aliveTets);

  double t2 = TimeOfDay();
  double dt = (t2 - t1);
  int COUNT_MISS = COUNT_MISS_1 + COUNT_MISS_2;
  Msg::Info("3D refinement terminated (%d nodes total):", (int)vSizes.size());
  Msg::Info(" - %d Delaunay cavities modified for star shapeness",
            NB_CORRECTION_OF_CAVITY);
  Msg::Info(" - %d nodes could not be inserted", COUNT_MISS);
  Msg::Info(" - %d tetrahedra created in %g sec. (%d tets/s)", aliveTets.size(),
            dt, (int)(aliveTets.size() / dt));

  // relocate vertices
  int nbReloc = 0;
  for(int SM = 0; SM < CTX::instance()->mesh.nbSmoothing; SM++) {
    for(auto it = aliveTets.begin(); it != aliveTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < .4)
          for(int i = 0; i < 4; i++) {
            if(smoothVertex(*it, i, qmTetrahedron::QMTET_GAMMA)) nbReloc++;
          }
      }
    }
  }

  Msg::Info("%d node relocations", nbReloc);

  for(auto it = aliveTets.begin(); it != aliveTets.end(); ++it) {
    MTet4 *worst = *it;
    if(!worst->isDeleted()) {
      worst->onWhat()->tetrahedra.push_back(worst->tet());
      worst->tet() = nullptr;
    }
    myFactory.Free(worst);
  }
}

// ---------------------------------------------------------------------------
// Flat-array refinement kernel (selected with Mesh.FlatRefineDelaunay3D):
// the same
// algorithm and floating-point operations as refineRegionMTet4, but operating
// on index-based arrays instead of MTet4/MTetrahedron/MVertex objects, which
// are only materialized when the refinement is done. The meshes produced are
// bit-for-bit identical, including the node and element numbering.

namespace {

constexpr std::uint32_t FLAT_NONE = 0xffffffffu;

class flatKernel {
public:
  GRegion *gr;
  std::vector<double> &vSizes, &vSizesBGM;
  int &NUM;
  bool extend;
  bool hasEmbedded;

  // regions referenced by the tets (onWhat values)
  std::vector<GRegion *> regions;

  // vertices, indexed like MVertex::getIndex(); Steiner points are appended
  std::vector<double> vXYZ; // 3 per vertex
  std::vector<MVertex *> vPtr; // null for not-yet-materialized Steiner points

  // tets; slots of deleted tets are recycled through freeSlots
  std::vector<std::uint32_t> tetV; // 4 vertex indices per tet
  // hot per-tet block: a single 64-byte cache line holding everything the
  // cavity search needs (cached circumsphere, queue key, packed neighbors)
  struct alignas(64) tetHot {
    double cc[3], r2, sphTol;
    double radius; // normalized circumradius (queue key)
    std::uint32_t N[4]; // packed neighbors (4 * tet + face)
  };
  std::vector<tetHot> hot;
  std::vector<std::uint64_t> tetNum; // element number
  std::vector<std::uint16_t> tetRegion; // index into regions (0xffff: void)
  std::vector<std::int8_t> tetOrient;
  std::vector<std::uint8_t> tetDeleted;
  std::vector<MTetrahedron *> tetMT; // imported elements, null for new tets
  std::vector<std::uint32_t> freeSlots;

  // embedded entities as sorted vertex index pairs/triples
  std::vector<std::uint64_t> embEdges;
  std::vector<std::array<std::uint32_t, 3> > embFaces;

  // successful insertions, replayed at export to materialize the vertices
  struct newVertex {
    double x, y, z;
    std::size_t num;
    int index;
    std::uint16_t region;
  };
  std::vector<newVertex> newVertices;

  // Priority queue with the same total order as tetRadiusQueue (radius
  // descending, ties on the smaller element number), but organized in
  // disjoint radius segments, ordered on the raw bits of the radius (which,
  // for positive doubles, order like the values): entries are appended
  // unsorted to their segment, and only the highest nonempty segment is
  // sorted, once, and consumed through a cursor. Segments too large to be
  // sorted in one go are first split radix-style on the next bits of the
  // key, so the sorting pauses stay bounded on huge meshes. Entries pushed
  // at or above the active radius range go to a small overflow heap. Since
  // the segments partition the radius axis, popping the best of (cursor
  // head, overflow top) yields the exact global maximum, so the insertion
  // order - and thus the mesh - is unchanged.
  struct qEntry {
    double radius;
    std::uint32_t num; // element number relative to numBase (see qNum)
    std::uint32_t t;
  };
  struct qSegment {
    std::uint64_t minKey; // lower bound of the segment's key range
    std::vector<qEntry> v;
  };
  static std::uint64_t qKey(double r)
  {
    // radii are positive, so the IEEE bit patterns order like the values
    std::uint64_t k;
    memcpy(&k, &r, 8);
    return k;
  }
  static const std::size_t Q_SORT_LIMIT = 1 << 15;
  std::vector<qSegment> segs; // ascending minKey: back() = highest range
  std::vector<qEntry> active; // sorted descending, consumed via cursor
  std::size_t cursor;
  std::uint64_t activeMin; // lower key bound of the active range
  std::vector<qEntry> overflow; // 4-ary max-heap
  std::vector<std::uint32_t> smallList;
  std::size_t smallAlive;
  double threshold;
  std::uint64_t numBase; // smallest element number in play
  std::uint32_t qNum(std::uint32_t t) const
  {
    const std::uint64_t d = tetNum[t] - numBase;
    if(d > 0xfffffff0ull) {
      Msg::Error("Element number range too large for the refinement queue");
      return 0xfffffff0u;
    }
    return (std::uint32_t)d;
  }

  flatKernel(GRegion *_gr, std::vector<double> &_vSizes,
             std::vector<double> &_vSizesBGM, int &_NUM, double _threshold)
    : gr(_gr), vSizes(_vSizes), vSizesBGM(_vSizesBGM), NUM(_NUM),
      extend(Extend2dMeshIn3dVolumes()), hasEmbedded(false), cursor(0),
      activeMin(0xffffffffffffffffull), // nothing active yet
      smallAlive(0), threshold(_threshold), numBase(0)
  {
    segs.push_back({0, {}});
  }
  ~flatKernel()
  {
    for(auto t : tetMT) {
      if(t) delete t;
    }
  }

  void freeSlot(std::uint32_t s)
  {
    if(tetMT[s]) {
      delete tetMT[s];
      tetMT[s] = nullptr;
    }
    freeSlots.push_back(s);
  }
  std::uint32_t allocSlot()
  {
    std::uint32_t s;
    if(!freeSlots.empty()) {
      s = freeSlots.back();
      freeSlots.pop_back();
    }
    else {
      s = (std::uint32_t)tetNum.size();
      tetV.resize(tetV.size() + 4);
      hot.resize(hot.size() + 1);
      tetNum.push_back(0);
      tetRegion.push_back(0xffff);
      tetOrient.push_back(0);
      tetDeleted.push_back(0);
      tetMT.push_back(nullptr);
    }
    tetDeleted[s] = 0;
    tetMT[s] = nullptr;
    for(int k = 0; k < 4; k++) hot[s].N[k] = FLAT_NONE;
    return s;
  }

  static bool qLess(const qEntry &a, const qEntry &b)
  {
    if(a.radius != b.radius) return a.radius < b.radius;
    return a.num > b.num;
  }
  static bool qGreater(const qEntry &a, const qEntry &b)
  {
    if(a.radius != b.radius) return a.radius > b.radius;
    return a.num < b.num;
  }
  void qPush(std::uint32_t t)
  {
    const double r = hot[t].radius;
    if(r < threshold) {
      smallList.push_back(t);
      if(smallList.size() > 2 * smallAlive + 1024) sweepSmall();
      return;
    }
    const std::uint64_t k = qKey(r);
    // everything at or above the active radius range goes to the overflow
    // heap: entries above the active range must not reactivate it, which
    // would sort its remains again and again on large meshes
    if(k >= activeMin) {
      overflow.push_back({r, qNum(t), t});
      std::size_t i = overflow.size() - 1;
      while(i) {
        std::size_t p = (i - 1) >> 2;
        if(qLess(overflow[p], overflow[i]))
          std::swap(overflow[p], overflow[i]);
        else
          break;
        i = p;
      }
    }
    else {
      // find the segment whose range contains the key (segments are ordered
      // by ascending minKey and the first one starts at 0)
      std::size_t lo = 0, hi = segs.size() - 1;
      while(lo < hi) {
        std::size_t mid = (lo + hi + 1) / 2;
        if(segs[mid].minKey <= k)
          lo = mid;
        else
          hi = mid - 1;
      }
      segs[lo].v.push_back({r, qNum(t), t});
    }
  }
  // make the next entry available; returns false if no entries remain
  bool qNormalize()
  {
    // once the segments have run dry (activeMin == 0) every push goes to the
    // overflow heap, which then degenerates into the whole queue: each push
    // sifts, and each insertion pops through a dozen dead entries; rebuild
    // the segments from the heap so pushes return to O(1) appends and dead
    // entries are consumed for free from the sorted runs
    if(cursor >= active.size() && segs.empty() && overflow.size() > 1024) {
      segs.push_back({0, std::move(overflow)});
      overflow.clear();
      activeMin = 0xffffffffffffffffull;
    }
    while(cursor >= active.size() && overflow.empty()) {
      while(!segs.empty() && segs.back().v.empty()) segs.pop_back();
      if(segs.empty()) {
        activeMin = 0; // everything now goes through the overflow heap
        return !overflow.empty();
      }
      std::vector<qEntry> top = std::move(segs.back().v);
      const std::uint64_t topMin = segs.back().minKey;
      segs.pop_back();
      if(top.size() > Q_SORT_LIMIT) {
        // split radix-style on the 8 bits below the highest bit in which
        // the keys of the segment differ
        std::uint64_t kmin = ~0ull, kmax = 0;
        for(auto &e : top) {
          const std::uint64_t k = qKey(e.radius);
          kmin = std::min(kmin, k);
          kmax = std::max(kmax, k);
        }
        if(kmin != kmax) {
          int hb = 63;
          while(!((kmax - kmin) >> hb)) hb--;
          int shift = hb - 7;
          if(shift < 0) shift = 0;
          const std::size_t nsub = (std::size_t)((kmax - kmin) >> shift) + 1;
          const std::size_t base = segs.size();
          for(std::size_t i = 0; i < nsub; i++)
            segs.push_back({i ? kmin + (i << shift) : topMin,
                            std::vector<qEntry>()});
          for(auto &e : top)
            segs[base + (std::size_t)((qKey(e.radius) - kmin) >> shift)]
              .v.push_back(e);
          continue;
        }
        // all keys are equal: fall through and sort (on the element numbers)
      }
      active = std::move(top);
      std::sort(active.begin(), active.end(),
                [](const qEntry &a, const qEntry &b) {
                  return qGreater(a, b);
                });
      cursor = 0;
      activeMin = topMin;
    }
    return true;
  }
  // qNormalize() must have returned true before calling qTop()/qPop()
  bool qTopIsCursor() const
  {
    if(cursor >= active.size()) return false;
    if(overflow.empty()) return true;
    return qLess(overflow.front(), active[cursor]);
  }
  const qEntry &qTop() const
  {
    return qTopIsCursor() ? active[cursor] : overflow.front();
  }
  void qPop()
  {
    if(qTopIsCursor()) {
      cursor++;
      return;
    }
    qEntry last = overflow.back();
    overflow.pop_back();
    const std::size_t n = overflow.size();
    if(!n) return;
    std::size_t i = 0;
    while(true) {
      std::size_t c = 4 * i + 1;
      if(c >= n) break;
      std::size_t best = c;
      std::size_t end = std::min(c + 4, n);
      for(std::size_t j = c + 1; j < end; j++)
        if(qLess(overflow[best], overflow[j])) best = j;
      if(qLess(last, overflow[best])) {
        overflow[i] = overflow[best];
        i = best;
      }
      else
        break;
    }
    overflow[i] = last;
  }
  void sweepSmall()
  {
    std::size_t kept = 0;
    for(std::size_t i = 0; i < smallList.size(); i++) {
      if(tetDeleted[smallList[i]])
        freeSlot(smallList[i]);
      else
        smallList[kept++] = smallList[i];
    }
    smallList.resize(kept);
    smallAlive = kept;
  }
  void drainSorted(std::vector<std::uint32_t> &extraTets,
                   std::vector<std::uint32_t> &sorted)
  {
    std::vector<qEntry> all;
    for(std::size_t i = cursor; i < active.size(); i++) all.push_back(active[i]);
    for(auto &e : overflow) all.push_back(e);
    for(auto &sg : segs)
      for(auto &e : sg.v) all.push_back(e);
    active.clear();
    overflow.clear();
    segs.clear();
    for(auto &e : all) {
      if(tetDeleted[e.t]) {
        freeSlot(e.t);
        e.t = FLAT_NONE;
      }
    }
    sweepSmall();
    for(auto t : smallList) all.push_back({hot[t].radius, qNum(t), t});
    smallList.clear();
    for(auto t : extraTets) {
      if(tetDeleted[t])
        freeSlot(t);
      else
        all.push_back({hot[t].radius, qNum(t), t});
    }
    std::sort(all.begin(), all.end(),
              [](const qEntry &a, const qEntry &b) { return qGreater(a, b); });
    sorted.clear();
    sorted.reserve(all.size());
    for(auto &e : all) {
      if(e.t != FLAT_NONE) sorted.push_back(e.t);
    }
  }

  // same geometry and operations as MTet4::setupGeom() + the lcA/lcB variant
  // of MTet4::setup()
  void setupCreatedTet(std::uint32_t s, double lcA, double lcB)
  {
    const std::uint32_t *v = &tetV[4 * s];
    double *A = &vXYZ[3 * v[0]], *B = &vXYZ[3 * v[1]], *C = &vXYZ[3 * v[2]],
           *D = &vXYZ[3 * v[3]];
    tetHot &sph = hot[s];
    double cerr;
    const double o = tetcircumcenterBounded(A, B, C, D, sph.cc, &cerr);
    tetOrient[s] = (o > 0) ? -1 : (o < 0) ? 1 : 0;
    const double dx = A[0] - sph.cc[0];
    const double dy = A[1] - sph.cc[1];
    const double dz = A[2] - sph.cc[2];
    sph.r2 = dx * dx + dy * dy + dz * dz;
    double circum_radius = std::sqrt(sph.r2);
    sph.sphTol = tetOrient[s] ? 3. * cerr : 1.e300;
    double lc1 = 0.25 * (vSizes[v[0]] + vSizes[v[1]] + vSizes[v[2]] + lcA);
    double lcBGM =
      0.25 * (vSizesBGM[v[0]] + vSizesBGM[v[1]] + vSizesBGM[v[2]] + lcB);
    double lc = extend ? std::min(lc1, lcBGM) : lcBGM;
    sph.radius = circum_radius / lc;
  }

  // same test and operations as MTet4::inCircumSphere()
  int inCircumSphereF(std::uint32_t t, const double *p) const
  {
    const tetHot &s = hot[t];
    const double dx = p[0] - s.cc[0], dy = p[1] - s.cc[1], dz = p[2] - s.cc[2];
    const double d2 = dx * dx + dy * dy + dz * dz;
    const double diff = d2 - s.r2;
    const double ss = d2 + s.r2;
    const double bound = s.sphTol * std::sqrt(ss) + 1.e-12 * ss;
    if(std::abs(diff) > bound) return (diff < 0) ? 1 : 0;
    const std::uint32_t *v = &tetV[4 * t];
    const double *pa = &vXYZ[3 * v[0]], *pb = &vXYZ[3 * v[1]],
                 *pc = &vXYZ[3 * v[2]], *pd = &vXYZ[3 * v[3]];
    double orient = tetOrient[t] ? (double)tetOrient[t] :
                                   robustPredicates::orient3d(pa, pb, pc, pd);
    double result = robustPredicates::insphere(pa, pb, pc, pd, p) * orient;
    return (result > 0) ? 1 : 0;
  }

  // same traversal as findCavity()
  void findCavityF(const double *p, std::uint32_t t,
                   std::vector<std::uint32_t> &cavity,
                   std::vector<std::uint32_t> &shell)
  {
    tetDeleted[t] = 1;
    cavity.push_back(t);
    for(std::size_t idx = 0; idx < cavity.size(); idx++) {
      const std::uint32_t current = cavity[idx];
      const std::uint16_t reg = tetRegion[current];
      for(int i = 0; i < 4; i++) {
        const std::uint32_t np = hot[current].N[i];
        if(np == FLAT_NONE) { shell.push_back(4 * current + i); }
        else {
          const std::uint32_t neighbour = np >> 2;
          if(!tetDeleted[neighbour]) {
            if(inCircumSphereF(neighbour, p) && tetRegion[neighbour] == reg) {
              tetDeleted[neighbour] = 1;
              cavity.push_back(neighbour);
            }
            else {
              shell.push_back(4 * current + i);
            }
          }
        }
      }
    }
  }

  void faceTriple(std::uint32_t e, std::uint32_t *tri) const
  {
    const std::uint32_t t = e >> 2, f = e & 3;
    std::uint32_t a = tetV[4 * t + faces[f][0]];
    std::uint32_t b = tetV[4 * t + faces[f][1]];
    std::uint32_t c = tetV[4 * t + faces[f][2]];
    if(a > b) std::swap(a, b);
    if(b > c) std::swap(b, c);
    if(a > b) std::swap(a, b);
    tri[0] = a;
    tri[1] = b;
    tri[2] = c;
  }
  int findShellFace(const std::vector<std::uint32_t> &shell,
                    std::uint32_t e) const
  {
    std::uint32_t tri[3], tri2[3];
    faceTriple(e, tri);
    for(std::size_t i = 0; i < shell.size(); i++) {
      faceTriple(shell[i], tri2);
      if(tri[0] == tri2[0] && tri[1] == tri2[1] && tri[2] == tri2[2])
        return (int)i;
    }
    return -1;
  }
  bool visibleF(std::uint32_t e, const double *p) const
  {
    const std::uint32_t t = e >> 2, f = e & 3;
    const double *a = &vXYZ[3 * tetV[4 * t + faces[f][0]]];
    const double *b = &vXYZ[3 * tetV[4 * t + faces[f][1]]];
    const double *c = &vXYZ[3 * tetV[4 * t + faces[f][2]]];
    return robustPredicates::orient3d(a, b, c, p) < 0.0;
  }

  // same effective logic as makeCavityStarShaped() (whose verifyShell()
  // always returns 1) and extendCavity()
  void extendCavityF(std::vector<std::uint32_t> &shell,
                     std::vector<std::uint32_t> &cavity, std::uint32_t fxt)
  {
    const std::uint32_t opp = hot[fxt >> 2].N[fxt & 3] >> 2;
    for(int i = 0; i < 4; i++) {
      const std::uint32_t e = 4 * opp + i;
      int pos = findShellFace(shell, e);
      if(pos < 0)
        shell.push_back(e);
      else
        shell.erase(shell.begin() + pos);
    }
    cavity.push_back(opp);
    tetDeleted[opp] = 1;
  }
  int makeCavityStarShapedF(std::vector<std::uint32_t> &shell,
                            std::vector<std::uint32_t> &cavity,
                            const double *p)
  {
    std::vector<std::uint32_t> wrong;
    for(auto e : shell) {
      if(!visibleF(e, p)) wrong.push_back(e);
    }
    if(wrong.empty()) return 0;
    while(!wrong.empty()) {
      const std::uint32_t fxt = wrong.front();
      if(findShellFace(shell, fxt) >= 0) {
        const std::uint32_t np = hot[fxt >> 2].N[fxt & 3];
        if(np != FLAT_NONE &&
           tetRegion[np >> 2] == tetRegion[fxt >> 2]) {
          extendCavityF(shell, cavity, fxt);
        }
        else {
          return -1;
        }
      }
      wrong.erase(wrong.begin());
    }
    return 1;
  }

  // same outcome as isCavityCompatibleWithEmbeddedEdges/Face()
  static std::uint64_t edgeKey(std::uint32_t a, std::uint32_t b)
  {
    if(a > b) std::swap(a, b);
    return ((std::uint64_t)a << 32) | b;
  }
  bool compatibleWithEmbedded(const std::vector<std::uint32_t> &cavity,
                              const std::vector<std::uint32_t> &shell) const
  {
    if(!embEdges.empty()) {
      std::vector<std::uint64_t> ed;
      ed.reserve(shell.size() * 3);
      std::uint32_t tri[3];
      for(auto e : shell) {
        faceTriple(e, tri);
        ed.push_back(edgeKey(tri[0], tri[1]));
        ed.push_back(edgeKey(tri[1], tri[2]));
        ed.push_back(edgeKey(tri[2], tri[0]));
      }
      static const int te[6][2] = {{0, 1}, {1, 2}, {2, 0},
                                   {3, 0}, {3, 2}, {3, 1}};
      for(auto t : cavity) {
        for(int j = 0; j < 6; j++) {
          std::uint64_t k =
            edgeKey(tetV[4 * t + te[j][0]], tetV[4 * t + te[j][1]]);
          if(std::find(ed.begin(), ed.end(), k) == ed.end() &&
             std::binary_search(embEdges.begin(), embEdges.end(), k))
            return false;
        }
      }
    }
    if(!embFaces.empty()) {
      std::vector<std::array<std::uint32_t, 3> > shellFaces;
      shellFaces.reserve(shell.size());
      std::uint32_t tri[3];
      for(auto e : shell) {
        faceTriple(e, tri);
        shellFaces.push_back({tri[0], tri[1], tri[2]});
      }
      for(auto t : cavity) {
        for(int j = 0; j < 4; j++) {
          faceTriple(4 * t + j, tri);
          std::array<std::uint32_t, 3> f = {tri[0], tri[1], tri[2]};
          if(std::find(shellFaces.begin(), shellFaces.end(), f) ==
               shellFaces.end() &&
             std::binary_search(embFaces.begin(), embFaces.end(), f))
            return false;
        }
      }
    }
    return true;
  }

  // same as insertVertexB()
  bool insertVertexF(std::vector<std::uint32_t> &shell,
                     std::vector<std::uint32_t> &cavity, int vIdx, double lc1,
                     double lc2, std::uint16_t reg,
                     std::vector<std::uint32_t> &newTets, GModel *model)
  {
    newTets.clear();

    const double *vx = &vXYZ[3 * vIdx];
    double const lc = extend ? std::min(lc1, lc2) : lc2;
    double const lcSq = (lc * .05) * (lc * .05);
    auto tooClose = [&](std::uint32_t w) {
      const double *ww = &vXYZ[3 * w];
      double dx = ww[0] - vx[0], dy = ww[1] - vx[1], dz = ww[2] - vx[2];
      return dx * dx + dy * dy + dz * dz < lcSq;
    };

    bool onePointIsTooClose = false;
    for(std::size_t k = 0; k < shell.size(); k++) {
      const std::uint32_t t = shell[k] >> 2, f = shell[k] & 3;
      const std::uint32_t f0 = tetV[4 * t + faces[f][0]];
      const std::uint32_t f1 = tetV[4 * t + faces[f][1]];
      const std::uint32_t f2 = tetV[4 * t + faces[f][2]];
      const std::uint64_t num = model->incrementAndGetMaxElementNumber();
      const std::uint32_t s = allocSlot();
      tetV[4 * s + 0] = f0;
      tetV[4 * s + 1] = f1;
      tetV[4 * s + 2] = f2;
      tetV[4 * s + 3] = (std::uint32_t)vIdx;
      tetNum[s] = num;
      tetRegion[s] = reg;
      setupCreatedTet(s, lc1, lc2);

      if(tooClose(f0) || tooClose(f1) || tooClose(f2))
        onePointIsTooClose = true;

      newTets.push_back(s);
    }
    if(!onePointIsTooClose) {
      // internal faces: same shell-edge matching as insertVertexB
      struct shellEdge {
        std::uint32_t a, b;
        std::uint32_t tetFace;
      };
      std::vector<shellEdge> edges;
      edges.reserve(3 * shell.size());
      for(std::size_t k = 0; k < shell.size(); k++) {
        const std::uint32_t s = newTets[k];
        const std::uint32_t f0 = tetV[4 * s + 0];
        const std::uint32_t f1 = tetV[4 * s + 1];
        const std::uint32_t f2 = tetV[4 * s + 2];
        edges.push_back({std::min(f0, f2), std::max(f0, f2),
                         (std::uint32_t)(4 * k + 1)});
        edges.push_back({std::min(f0, f1), std::max(f0, f1),
                         (std::uint32_t)(4 * k + 2)});
        edges.push_back({std::min(f1, f2), std::max(f1, f2),
                         (std::uint32_t)(4 * k + 3)});
      }
      std::sort(edges.begin(), edges.end(),
                [](const shellEdge &e1, const shellEdge &e2) {
                  if(e1.a != e2.a) return e1.a < e2.a;
                  return e1.b < e2.b;
                });
      for(std::size_t i = 0; i + 1 < edges.size(); i++) {
        const shellEdge &e1 = edges[i];
        const shellEdge &e2 = edges[i + 1];
        if(e1.a == e2.a && e1.b == e2.b) {
          const std::uint32_t t1 = newTets[e1.tetFace >> 2];
          const std::uint32_t t2 = newTets[e2.tetFace >> 2];
          hot[t1].N[e1.tetFace & 3] = 4 * t2 + (e2.tetFace & 3);
          hot[t2].N[e2.tetFace & 3] = 4 * t1 + (e1.tetFace & 3);
          ++i;
        }
      }
      // outward faces: the packed neighbor of the shell face gives both the
      // outside tet and its back face; as in the object kernel, do not
      // connect across an embedded face
      std::uint32_t tri[3];
      for(std::size_t k = 0; k < shell.size(); k++) {
        const std::uint32_t out = hot[shell[k] >> 2].N[shell[k] & 3];
        if(out == FLAT_NONE) continue;
        if(hasEmbedded && !embFaces.empty()) {
          faceTriple(shell[k], tri);
          std::array<std::uint32_t, 3> f = {tri[0], tri[1], tri[2]};
          if(std::binary_search(embFaces.begin(), embFaces.end(), f)) continue;
        }
        hot[newTets[k]].N[0] = out;
        hot[out >> 2].N[out & 3] = 4 * newTets[k] + 0;
      }

      for(std::size_t i = 0; i < newTets.size(); i++) qPush(newTets[i]);

      return true;
    }
    else /* one point is too close */ {
      for(std::size_t i = 0; i < newTets.size(); i++) {
        tetDeleted[newTets[i]] = 1;
        freeSlot(newTets[i]);
      }
      for(auto t : cavity) tetDeleted[t] = 0;
      return false;
    }
  }

  // flat port of smoothVertex() and buildVertexCavity_recur() from
  // meshGRegionLocalMeshMod.cpp, with the same logic and floating-point
  // operations; hot[].radius plays the role of the stored MTet4 quality,
  // and (as with the former MTet4 bridge) links to deleted tets are treated
  // as absent
  std::vector<std::uint32_t> smoothCavity;
  std::vector<double> smoothQuals;

  bool vertexCavityFlat(std::uint32_t t, std::uint32_t vIdx)
  {
    static const int vFac[4][3] = {{0, 1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2, 3}};
    int iV = -1;
    for(int i = 0; i < 4; i++) {
      if(tetV[4 * t + i] == vIdx) {
        iV = i;
        break;
      }
    }
    if(iV == -1) {
      Msg::Warning("Trying to build a cavity of tets for a node that does "
                   "not belong to this tet - skipping cavity");
      return false;
    }
    for(int i = 0; i < 3; i++) {
      const std::uint32_t np = hot[t].N[vFac[iV][i]];
      if(np != FLAT_NONE && !tetDeleted[np >> 2]) {
        const std::uint32_t neigh = np >> 2;
        bool found = false;
        for(std::size_t j = 0; j < smoothCavity.size(); j++) {
          if(smoothCavity[j] == neigh) {
            found = true;
            j = smoothCavity.size();
          }
        }
        if(!found) {
          smoothCavity.push_back(neigh);
          if(!vertexCavityFlat(neigh, vIdx)) return false;
        }
      }
    }
    return true;
  }

  bool smoothVertexFlat(std::uint32_t t, int iVertex,
                        const std::vector<std::uint8_t> &movable,
                        const qmTetrahedron::Measures &cr)
  {
    const std::uint32_t vIdx = tetV[4 * t + iVertex];
    if(!movable[vIdx]) return false;

    smoothCavity.clear();
    smoothCavity.push_back(t);
    if(!vertexCavityFlat(t, vIdx)) return false;

    double xcg = 0, ycg = 0, zcg = 0;
    double vTot = 0;
    double worst = 1.0;

    for(std::size_t i = 0; i < smoothCavity.size(); i++) {
      const std::uint32_t s = smoothCavity[i];
      const double *w0 = &vXYZ[3 * tetV[4 * s + 0]];
      const double *w1 = &vXYZ[3 * tetV[4 * s + 1]];
      const double *w2 = &vXYZ[3 * tetV[4 * s + 2]];
      const double *w3 = &vXYZ[3 * tetV[4 * s + 3]];
      // same as fabs(MTetrahedron::getVolume())
      double mat[3][3];
      mat[0][0] = w1[0] - w0[0];
      mat[0][1] = w2[0] - w0[0];
      mat[0][2] = w3[0] - w0[0];
      mat[1][0] = w1[1] - w0[1];
      mat[1][1] = w2[1] - w0[1];
      mat[1][2] = w3[1] - w0[1];
      mat[2][0] = w1[2] - w0[2];
      mat[2][1] = w2[2] - w0[2];
      mat[2][2] = w3[2] - w0[2];
      double volume = fabs(det3x3(mat) * 0.166666666666666666);
      double q = hot[s].radius;
      worst = std::min(worst, q);
      xcg += 0.25 * (w0[0] + w1[0] + w2[0] + w3[0]) * volume;
      ycg += 0.25 * (w0[1] + w1[1] + w2[1] + w3[1]) * volume;
      zcg += 0.25 * (w0[2] + w1[2] + w2[2] + w3[2]) * volume;
      vTot += volume;
    }
    xcg /= (vTot);
    ycg /= (vTot);
    zcg /= (vTot);
    double volumeAfter = 0.0;

    double *vc = &vXYZ[3 * vIdx];
    const double x = vc[0];
    const double y = vc[1];
    const double z = vc[2];
    vc[0] = xcg;
    vc[1] = ycg;
    vc[2] = zcg;
    double worstAfter = 1.0;
    smoothQuals.resize(smoothCavity.size());
    for(std::size_t i = 0; i < smoothCavity.size(); i++) {
      double volume;
      const std::uint32_t s = smoothCavity[i];
      const double *w0 = &vXYZ[3 * tetV[4 * s + 0]];
      const double *w1 = &vXYZ[3 * tetV[4 * s + 1]];
      const double *w2 = &vXYZ[3 * tetV[4 * s + 2]];
      const double *w3 = &vXYZ[3 * tetV[4 * s + 3]];
      smoothQuals[i] = qmTetrahedron::qm(w0[0], w0[1], w0[2], w1[0], w1[1],
                                         w1[2], w2[0], w2[1], w2[2], w3[0],
                                         w3[1], w3[2], cr, &volume);
      volumeAfter += volume;
      worstAfter = std::min(worstAfter, smoothQuals[i]);
    }

    if(fabs(volumeAfter - vTot) > 1.e-10 * vTot || worstAfter < worst) {
      vc[0] = x;
      vc[1] = y;
      vc[2] = z;
      return false;
    }
    else {
      // restore new quality
      for(std::size_t i = 0; i < smoothCavity.size(); i++) {
        hot[smoothCavity[i]].radius = smoothQuals[i];
      }
      return true;
    }
  }
};

} // namespace

static void refineRegionFlat(GRegion *gr, int maxIter,
                             double worstTetRadiusTarget,
                             std::vector<MTet4 *> &tets0,
                             MTet4Factory &myFactory,
                             std::vector<double> &vSizes,
                             std::vector<double> &vSizesBGM, int &NUM,
                             const std::set<MFace, MFaceLessThan> &allEmbeddedFaces,
                             edgeContainerB &allEmbeddedEdges)
{
  flatKernel K(gr, vSizes, vSizesBGM, NUM, worstTetRadiusTarget);
  GModel *model = gr->model();

  // import the classified and connected tets
  {
    const std::size_t n = tets0.size();
    K.vXYZ.resize(3 * (std::size_t)NUM);
    K.vPtr.resize(NUM, nullptr);
    K.tetV.resize(4 * n);
    K.hot.resize(n);
    K.tetNum.resize(n);
    K.tetRegion.resize(n);
    K.tetOrient.resize(n);
    K.tetDeleted.resize(n);
    K.tetMT.resize(n);

    std::unordered_map<MTet4 *, std::uint32_t> idxOf;
    idxOf.reserve(n);
    for(std::size_t i = 0; i < n; i++) idxOf[tets0[i]] = (std::uint32_t)i;
    std::map<GRegion *, std::uint16_t> regIdx;
    for(std::size_t i = 0; i < n; i++) {
      MTet4 *t4 = tets0[i];
      for(int j = 0; j < 4; j++) {
        MVertex *mv = t4->tet()->getVertex(j);
        const std::uint32_t idx = (std::uint32_t)mv->getIndex();
        K.tetV[4 * i + j] = idx;
        K.vPtr[idx] = mv;
        K.vXYZ[3 * idx + 0] = mv->x();
        K.vXYZ[3 * idx + 1] = mv->y();
        K.vXYZ[3 * idx + 2] = mv->z();
      }
      GRegion *r = t4->onWhat();
      if(r) {
        auto it = regIdx.find(r);
        if(it == regIdx.end()) {
          it = regIdx.insert(std::make_pair(r, (std::uint16_t)K.regions.size()))
                 .first;
          K.regions.push_back(r);
        }
        K.tetRegion[i] = it->second;
      }
      else
        K.tetRegion[i] = 0xffff;
      K.tetNum[i] = t4->tet()->getNum();
      K.hot[i].radius = t4->getRadius();
      t4->cachedCircumcenter(K.hot[i].cc);
      K.hot[i].r2 = t4->cachedR2();
      K.hot[i].sphTol = t4->cachedSphTol();
      K.tetOrient[i] = (std::int8_t)t4->cachedOrientSgn();
      K.tetDeleted[i] = t4->isDeleted() ? 1 : 0;
      K.tetMT[i] = t4->tet();
    }
    for(std::size_t i = 0; i < n; i++) {
      MTet4 *t4 = tets0[i];
      if(t4->isDeleted()) {
        // tets deleted by the classification (lying in the void) still point
        // to their old neighbors, but their adjacencies are never used: they
        // only wait in the queue to be freed
        for(int k = 0; k < 4; k++) K.hot[i].N[k] = FLAT_NONE;
        continue;
      }
      for(int k = 0; k < 4; k++) {
        MTet4 *nb = t4->getNeigh(k);
        if(!nb || nb->isDeleted()) { K.hot[i].N[k] = FLAT_NONE; }
        else {
          const std::uint32_t j = idxOf[nb];
          int bf = -1;
          for(int m = 0; m < 4; m++) {
            if(nb->getNeigh(m) == t4) {
              bf = m;
              break;
            }
          }
          if(bf < 0) {
            Msg::Error("Non-mutual tet adjacency in flat kernel import");
            bf = 0;
          }
          K.hot[i].N[k] = 4 * j + bf;
        }
      }
    }
    // the MTetrahedra are kept (owned by the kernel until export); the MTet4
    // wrappers are released
    for(std::size_t i = 0; i < n; i++) {
      tets0[i]->tet() = nullptr;
      myFactory.Free(tets0[i]);
    }
    tets0.clear();

    // embedded entities as index pairs/triples
    for(auto &f : allEmbeddedFaces) {
      std::uint32_t a = (std::uint32_t)f.getVertex(0)->getIndex();
      std::uint32_t b = (std::uint32_t)f.getVertex(1)->getIndex();
      std::uint32_t c = (std::uint32_t)f.getVertex(2)->getIndex();
      if(a > b) std::swap(a, b);
      if(b > c) std::swap(b, c);
      if(a > b) std::swap(a, b);
      K.embFaces.push_back({a, b, c});
    }
    std::sort(K.embFaces.begin(), K.embFaces.end());
    for(auto &bucket : allEmbeddedEdges._hash) {
      for(auto &e : bucket) {
        K.embEdges.push_back(
          flatKernel::edgeKey((std::uint32_t)e.getVertex(0)->getIndex(),
                              (std::uint32_t)e.getVertex(1)->getIndex()));
      }
    }
    std::sort(K.embEdges.begin(), K.embEdges.end());
    K.hasEmbedded = !K.embEdges.empty() || !K.embFaces.empty();

    if(n) {
      K.numBase = K.tetNum[0];
      for(std::size_t i = 1; i < n; i++)
        if(K.tetNum[i] < K.numBase) K.numBase = K.tetNum[i];
    }
    for(std::uint32_t i = 0; i < (std::uint32_t)n; i++) K.qPush(i);
  }

  // main loop: same structure, decisions and messages as refineRegionMTet4
  std::vector<std::uint32_t> failedTets;
  int ITER = 0, REALCOUNT = 0;
  int NB_CORRECTION_OF_CAVITY = 0;
  int COUNT_MISS_1 = 0;
  int COUNT_MISS_2 = 0;

  double t1 = TimeOfDay();

  std::vector<std::uint32_t> shell, cavity, newTets;

  while(1) {
    if(maxIter > 0 && ITER >= maxIter) {
      Msg::Info("Max. number of iterations reached (%d) - stopping insertion",
                ITER);
      break;
    }
    if(!K.qNormalize()) {
      if(K.smallList.empty())
        Msg::Warning("No tetrahedra in region %d", gr->tag());
      break;
    }

    const std::uint32_t worst0 = K.qTop().t;

    if(K.tetDeleted[worst0]) {
      K.qPop();
      K.freeSlot(worst0);
    }
    else {
      if(ITER++ % 500 == 0)
        Msg::Info("It. %d - %d nodes created - worst tet radius %g (nodes "
                  "removed %d %d)",
                  ITER - 1, REALCOUNT, K.hot[worst0].radius, COUNT_MISS_1,
                  COUNT_MISS_2);
      if(K.hot[worst0].radius < worstTetRadiusTarget) break;
      K.qPop();
      const std::uint32_t popped = worst0;
      std::uint32_t worst = worst0;

      double center[3];
      double uvw[3];
      center[0] = K.hot[worst].cc[0];
      center[1] = K.hot[worst].cc[1];
      center[2] = K.hot[worst].cc[2];

      // replicates the vertex number consumed by the former stack MVertex
      model->incrementAndGetMaxVertexNumber();

      shell.clear();
      cavity.clear();
      K.findCavityF(center, worst, cavity, shell);
      bool FOUND = false;
      for(auto t : cavity) {
        // same as MTetrahedron::xyz2uvw() + isInside()
        const std::uint32_t *tv = &K.tetV[4 * t];
        const double *w0 = &K.vXYZ[3 * tv[0]], *w1 = &K.vXYZ[3 * tv[1]],
                     *w2 = &K.vXYZ[3 * tv[2]], *w3 = &K.vXYZ[3 * tv[3]];
        double mat[3][3], b[3];
        mat[0][0] = w1[0] - w0[0];
        mat[0][1] = w2[0] - w0[0];
        mat[0][2] = w3[0] - w0[0];
        mat[1][0] = w1[1] - w0[1];
        mat[1][1] = w2[1] - w0[1];
        mat[1][2] = w3[1] - w0[1];
        mat[2][0] = w1[2] - w0[2];
        mat[2][1] = w2[2] - w0[2];
        mat[2][2] = w3[2] - w0[2];
        b[0] = center[0] - w0[0];
        b[1] = center[1] - w0[1];
        b[2] = center[2] - w0[2];
        double det;
        sys3x3(mat, b, uvw, &det);
        double tol = CTX::instance()->mesh.toleranceReferenceElement;
        if(!(uvw[0] < (-tol) || uvw[1] < (-tol) || uvw[2] < (-tol) ||
             uvw[0] > ((1. + tol) - uvw[1] - uvw[2]))) {
          worst = t;
          FOUND = true;
          break;
        }
      }

      if(FOUND && K.hasEmbedded) {
        FOUND = K.compatibleWithEmbedded(cavity, shell);
      }

      bool correctedCavityIncompatibleWithEmbeddedEntities = false;

      if(FOUND) {
        const std::size_t vnum = model->incrementAndGetMaxVertexNumber();
        const int vIdx = NUM++;
        K.vXYZ.push_back(center[0]);
        K.vXYZ.push_back(center[1]);
        K.vXYZ.push_back(center[2]);
        K.vPtr.push_back(nullptr);

        bool starShaped = true;
        bool correctCavity = false;
        while(1) {
          int k = K.makeCavityStarShapedF(shell, cavity, center);
          if(k == -1) {
            starShaped = false;
            break;
          }
          else if(k == 0)
            break;
          else if(k == 1)
            correctCavity = true;
        }
        if(correctCavity && starShaped) {
          NB_CORRECTION_OF_CAVITY++;
          if(!K.compatibleWithEmbedded(cavity, shell)) {
            correctedCavityIncompatibleWithEmbeddedEntities = true;
          }
        }
        const std::uint32_t *wv = &K.tetV[4 * worst];
        double lc1 = (1 - uvw[0] - uvw[1] - uvw[2]) * vSizes[wv[0]] +
                     uvw[0] * vSizes[wv[1]] + uvw[1] * vSizes[wv[2]] +
                     uvw[2] * vSizes[wv[3]];
        double lc2 = BGM_MeshSize(K.regions[K.tetRegion[worst]], 0, 0,
                                  center[0], center[1], center[2]);

        if(correctedCavityIncompatibleWithEmbeddedEntities || !starShaped ||
           !K.insertVertexF(shell, cavity, vIdx, lc1, lc2,
                            K.tetRegion[worst], newTets, model)) {
          COUNT_MISS_1++;
          K.hot[popped].radius = 0.;
          failedTets.push_back(popped);
          for(auto t : cavity) K.tetDeleted[t] = 0;
          K.vXYZ.resize(3 * (std::size_t)vIdx);
          K.vPtr.pop_back();
          NUM--;
        }
        else {
          vSizes.push_back(lc1);
          vSizesBGM.push_back(lc2);
          REALCOUNT++;
          K.newVertices.push_back({center[0], center[1], center[2], vnum, vIdx,
                                   K.tetRegion[worst]});
        }
      }

      else {
        K.hot[popped].radius = 0.;
        failedTets.push_back(popped);
        COUNT_MISS_2++;
        for(auto t : cavity) K.tetDeleted[t] = 0;
      }
    }
  }

  // free the deleted tets and recover the remaining ones, ordered as
  // compareTet4Ptr would order them
  std::vector<std::uint32_t> aliveTets;
  K.drainSorted(failedTets, aliveTets);

  double t2 = TimeOfDay();
  double dt = (t2 - t1);
  int COUNT_MISS = COUNT_MISS_1 + COUNT_MISS_2;
  Msg::Info("3D refinement terminated (%d nodes total):", (int)vSizes.size());
  Msg::Info(" - %d Delaunay cavities modified for star shapeness",
            NB_CORRECTION_OF_CAVITY);
  Msg::Info(" - %d nodes could not be inserted", COUNT_MISS);
  Msg::Info(" - %d tetrahedra created in %g sec. (%d tets/s)", aliveTets.size(),
            dt, (int)(aliveTets.size() / dt));

  // release the queue containers, which the export does not need
  std::vector<flatKernel::qSegment>().swap(K.segs);
  std::vector<flatKernel::qEntry>().swap(K.active);
  std::vector<flatKernel::qEntry>().swap(K.overflow);
  std::vector<std::uint32_t>().swap(K.freeSlots);
  std::vector<std::uint32_t>().swap(K.smallList);
  std::vector<std::uint64_t>().swap(K.embEdges);
  std::vector<std::array<std::uint32_t, 3> >().swap(K.embFaces);
  std::vector<std::int8_t>().swap(K.tetOrient);

  // relocate vertices, on the flat arrays
  int nbReloc = 0;
  if(CTX::instance()->mesh.nbSmoothing > 0) {
    std::vector<std::uint8_t> movable(K.vPtr.size());
    for(std::size_t i = 0; i < K.vPtr.size(); i++) {
      // vertices created by the refinement are not materialized yet and are
      // all inside a volume, i.e. movable
      movable[i] = K.vPtr[i] ? (K.vPtr[i]->onWhat() &&
                                K.vPtr[i]->onWhat()->dim() == 3) :
                               1;
    }
    for(int SM = 0; SM < CTX::instance()->mesh.nbSmoothing; SM++) {
      for(auto s : aliveTets) {
        if(!K.tetDeleted[s]) {
          double qq = K.hot[s].radius;
          if(qq < .4)
            for(int i = 0; i < 4; i++) {
              if(K.smoothVertexFlat(s, i, movable, qmTetrahedron::QMTET_GAMMA))
                nbReloc++;
            }
        }
      }
    }
    // write the relocated coordinates back into the pre-existing vertices
    for(std::size_t i = 0; i < K.vPtr.size(); i++) {
      if(K.vPtr[i] && movable[i]) {
        K.vPtr[i]->x() = K.vXYZ[3 * i];
        K.vPtr[i]->y() = K.vXYZ[3 * i + 1];
        K.vPtr[i]->z() = K.vXYZ[3 * i + 2];
      }
    }
  }

  Msg::Info("%d node relocations", nbReloc);

  // materialize the new vertices in insertion order, with their (possibly
  // relocated) coordinates
  for(auto &nv : K.newVertices) {
    MVertex *v = new MVertex(K.vXYZ[3 * nv.index], K.vXYZ[3 * nv.index + 1],
                             K.vXYZ[3 * nv.index + 2], K.regions[nv.region],
                             nv.num);
    v->setIndex(nv.index);
    K.vPtr[nv.index] = v;
    K.regions[nv.region]->mesh_vertices.push_back(v);
  }
  std::vector<flatKernel::tetHot>().swap(K.hot);
  std::vector<std::uint8_t>().swap(K.tetDeleted);
  std::vector<double>().swap(K.vXYZ);

  // materialize the tets (reusing the imported MTetrahedra) and hand them to
  // their regions
  for(auto s : aliveTets) {
    MTetrahedron *mt = K.tetMT[s];
    if(!mt) {
      mt = new MTetrahedron(K.vPtr[K.tetV[4 * s + 0]],
                            K.vPtr[K.tetV[4 * s + 1]],
                            K.vPtr[K.tetV[4 * s + 2]],
                            K.vPtr[K.tetV[4 * s + 3]],
                            K.tetNum[s] <= 0x7fffffffull ? (int)K.tetNum[s] :
                                                           1);
      if(K.tetNum[s] > 0x7fffffffull) mt->forceNum(K.tetNum[s]);
    }
    K.tetMT[s] = nullptr;
    K.regions[K.tetRegion[s]]->tetrahedra.push_back(mt);
  }
}

// do a 3D delaunay mesh assuming a set of vertices

void delaunayMeshIn3D(std::vector<MVertex *> &v,
                      std::vector<MTetrahedron *> &result, bool removeBox,
                      std::vector<std::int64_t> *neighbors)
{
  Msg::Info("Tetrahedrizing %d nodes...", v.size());
  double t1 = Cpu(), w1 = TimeOfDay();
  delaunayTriangulation(v, result, removeBox, neighbors);
  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::Info("Done tetrahedrizing %d nodes (Wall %gs, CPU %gs)", v.size(),
            w2 - w1, t2 - t1);
}
