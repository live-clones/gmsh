// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "OS.h"
#include "meshGRegion.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Context.h"
#include "delaunay3d.h"
#include "MEdge.h"
#include "MLine.h"
#include "ExtrudeParams.h"

int MTet4::radiusNorm = 2;

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
    : _hash(N), _size(0), _size_obj(sizeof(MEdge))
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
  double pa[3] = {base->getVertex(0)->x(), base->getVertex(0)->y(),
                  base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(), base->getVertex(1)->y(),
                  base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(), base->getVertex(2)->y(),
                  base->getVertex(2)->z()};
  double pd[3] = {base->getVertex(3)->x(), base->getVertex(3)->y(),
                  base->getVertex(3)->z()};
  double result = robustPredicates::insphere(pa, pb, pc, pd, (double *)p) *
                  robustPredicates::orient3d(pa, pb, pc, pd);
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

template <class ITER>
void connectTets_vector2_templ(std::size_t _size, ITER beg, ITER end,
                               std::vector<faceXtet> &conn)
{
  conn.clear();
  conn.reserve(4 * _size);
  for(ITER IT = beg; IT != end; ++IT) {
    MTet4 *t = *IT;
    if(!t->isDeleted()) {
      for(int j = 0; j < 4; j++) { conn.push_back(faceXtet(t, j)); }
    }
  }
  if(!conn.size()) return;

  std::sort(conn.begin(), conn.end());

  for(std::size_t i = 0; i < conn.size() - 1; i++) {
    faceXtet &f1 = conn[i];
    faceXtet &f2 = conn[i + 1];
    if(f1 == f2 && f1.t1 != f2.t1) {
      f1.t1->setNeigh(f1.i1, f2.t1);
      f2.t1->setNeigh(f2.i1, f1.t1);
      ++i;
    }
  }
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

void connectTets_vector2(std::list<MTet4 *> &l, std::vector<faceXtet> &conn)
{
  connectTets_vector2_templ(l.size(), l.begin(), l.end(), conn);
}

void connectTets_vector2(std::vector<MTet4 *> &l, std::vector<faceXtet> &conn)
{
  connectTets_vector2_templ(l.size(), l.begin(), l.end(), conn);
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
                   std::bind2nd(std::equal_to<MTet4 *>(), toRemove.t1)));

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

  std::queue<MTet4 *> cavity_queue;

  if(!cavity.empty()) { cavity_queue.push(cavity.back()); }

  while(!cavity_queue.empty()) {
    for(int i = 0; i < 4; i++) {
      MTet4 *const neighbour = cavity_queue.front()->getNeigh(i);
      if(!neighbour) { shell.push_back(faceXtet(cavity_queue.front(), i)); }
      else if(!neighbour->isDeleted()) {
        if(neighbour->inCircumSphere(v) &&
           (neighbour->onWhat() == cavity_queue.front()->onWhat())) {
          neighbour->setDeleted(true);

          cavity.push_back(neighbour);
          cavity_queue.push(neighbour);
        }
        else {
          shell.push_back(faceXtet(cavity_queue.front(), i));
        }
      }
    }
    cavity_queue.pop();
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

bool insertVertexB(std::vector<faceXtet> &shell, std::vector<MTet4 *> &cavity,
                   MVertex *v, double lc1, double lc2,
                   std::vector<double> &vSizes, std::vector<double> &vSizesBGM,
                   MTet4 *t, MTet4Factory &myFactory,
                   std::set<MTet4 *, compareTet4Ptr> &allTets,
                   const std::set<MFace, MFaceLessThan> &allEmbeddedFaces)
{
  std::vector<MTet4 *> new_cavity;
  new_cavity.reserve(shell.size());

  std::vector<MTet4 *> new_tets;
  new_tets.reserve(shell.size());

  auto it = shell.begin();

  bool onePointIsTooClose = false;
  while(it != shell.end()) {
    MTetrahedron *tr =
      new MTetrahedron(it->getVertex(0), it->getVertex(1), it->getVertex(2), v);
    MTet4 *t4 = myFactory.Create(tr, vSizes, vSizesBGM, lc1, lc2);
    t4->setOnWhat(t->onWhat());

    double const lc = Extend2dMeshIn3dVolumes() ? std::min(lc1, lc2) : lc2;
    if(distance(it->v[0], v) < lc * .05 || distance(it->v[1], v) < lc * .05 ||
       distance(it->v[2], v) < lc * .05)
      onePointIsTooClose = true;

    new_tets.push_back(t4);
    new_cavity.push_back(t4);

    MTet4 *otherSide = it->t1->getNeigh(it->i1);

    if(otherSide) new_cavity.push_back(otherSide);
    ++it;
  }
  if(!onePointIsTooClose) {
    if(allEmbeddedFaces.empty()) {
      std::vector<faceXtet> conn;
      connectTets_vector2(new_cavity, conn);
    }
    else {
      connectTets(new_cavity.begin(), new_cavity.end(), &allEmbeddedFaces);
    }

    allTets.insert(new_tets.begin(), new_tets.end());

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

static void setLcs(MTriangle *t,
                   std::map<MVertex *, double, MVertexPtrLessThan> &vSizes,
                   std::set<MVertex *, MVertexPtrLessThan> &bndVertices)
{
  for(int i = 0; i < 3; i++) {
    bndVertices.insert(t->getVertex(i));
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
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
                   std::map<MVertex *, double, MVertexPtrLessThan> &vSizes,
                   std::set<MVertex *, MVertexPtrLessThan> &bndVertices)
{
  for(int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 4; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);

      // smallest tet edge
      if(bndVertices.find(vi) == bndVertices.end()) {
        auto iti = vSizes.find(vi);

        double const length =
          hypotenuse(vi->x() - vj->x(), vi->y() - vj->y(), vi->z() - vj->z());

        if(iti == vSizes.end() || iti->second > length) { vSizes[vi] = length; }
      }

      if(bndVertices.find(vj) == bndVertices.end()) {
        auto itj = vSizes.find(vj);

        double const length =
          hypotenuse(vi->x() - vj->x(), vi->y() - vj->y(), vi->z() - vj->z());

        if(itj == vSizes.end() || itj->second > length) { vSizes[vj] = length; }
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
  CONTAINER allTets;
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    MTet4 *t = new MTet4(gr->tetrahedra[i], qm);
    t->setOnWhat(gr);
    allTets.push_back(t);
  }
  gr->tetrahedra.clear();

  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  createAllEmbeddedFaces(gr, allEmbeddedFaces);

  std::set<MEdge, MEdgeLessThan> allEmbeddedEdges;
  createAllEmbeddedEdges(gr, allEmbeddedEdges);

  if(allEmbeddedFaces.empty()) {
    std::vector<faceXtet> conn;
    connectTets_vector2(allTets, conn);
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
        delete newTets[i]->tet();
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
    Msg::Info("%d edge swaps, %d node relocations (volume = %g): "
              "worst = %g / average = %g (Wall %gs, CPU %gs)",
              nbESwap, nbReloc, totalVolumeb, worst, avg / count, w2 - w1,
              t2 - t1);
    if(worstA != 0.0 && worst - worstA < 1.e-6) break;
    worstA = worst;
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

static void memoryCleanup(MTet4Factory &myFactory,
                          std::set<MTet4 *, compareTet4Ptr> &allTets)
{
  // int n1 = allTets.size();
  auto itd = allTets.begin();
  while(itd != allTets.end()) {
    if((*itd)->isDeleted()) {
      myFactory.Free((*itd));
      allTets.erase(itd++);
    }
    else
      itd++;
  }
  // Msg::Info("Cleaning up memory %d -> %d", n1, allTets.size());
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

static void _deleteUnusedVertices(GRegion *gr)
{
  std::set<MVertex *, MVertexPtrLessThan> allverts;
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    for(int j = 0; j < 4; j++) {
      if(gr->tetrahedra[i]->getVertex(j)->onWhat() == gr)
        allverts.insert(gr->tetrahedra[i]->getVertex(j));
    }
  }
  for(std::size_t i = 0; i < gr->mesh_vertices.size(); i++) {
    // FIXME: investigate crash on exit (e.g. t16.geo)
    // if(allverts.find(gr->mesh_vertices[i]) == allverts.end())
    //   delete gr->mesh_vertices[i];
  }
  gr->mesh_vertices.clear();
  gr->mesh_vertices.insert(gr->mesh_vertices.end(), allverts.begin(),
                           allverts.end());
}

void insertVerticesInRegion(GRegion *gr, int maxIter,
                            double worstTetRadiusTarget, bool _classify,
                            splitQuadRecovery *sqr)
{
#ifdef DEBUG_BOUNDARY_RECOVERY
  testIfBoundaryIsRecovered(gr);
#endif

  std::vector<double> vSizes, vSizesBGM;
  MTet4Factory myFactory(1600000);
  std::set<MTet4 *, compareTet4Ptr> &allTets = myFactory.getAllTets();
  int NUM = 0;

  // leave this in a block so the map gets deallocated directly
  {
    std::map<MVertex *, double, MVertexPtrLessThan> vSizesMap;
    std::set<MVertex *, MVertexPtrLessThan> bndVertices;

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
    }
    for(std::size_t i = 0; i < gr->tetrahedra.size(); i++)
      setLcs(gr->tetrahedra[i], vSizesMap, bndVertices);

    for(auto it = vSizesMap.begin(); it != vSizesMap.end(); ++it) {
      it->first->setIndex(NUM++);
      vSizes.push_back(it->second);
      vSizesBGM.push_back(it->second);
    }
  }

  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    gr->tetrahedra[i]->setVolumePositive();
    allTets.insert(myFactory.Create(gr->tetrahedra[i], vSizes, vSizesBGM));
  }

  gr->tetrahedra.clear();

  // SLOW
  connectTets(allTets.begin(), allTets.end());

  // classify the tets on the right region

  if(_classify) {
    fs_cont search;
    buildFaceSearchStructure(gr->model(), search, true); // only triangles
    if(sqr) search.insert(sqr->getTri().begin(), sqr->getTri().end());

    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
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
    for(auto it = allTets.begin(); it != allTets.end(); ++it)
      (*it)->setOnWhat(gr);
  }

  for(auto it = allTets.begin(); it != allTets.end(); ++it) {
    (*it)->setNeigh(0, nullptr);
    (*it)->setNeigh(1, nullptr);
    (*it)->setNeigh(2, nullptr);
    (*it)->setNeigh(3, nullptr);
  }
  // store all embedded faces
  std::set<MFace, MFaceLessThan> allEmbeddedFaces;
  edgeContainerB allEmbeddedEdges;
  for(auto it = gr->model()->firstRegion(); it != gr->model()->lastRegion();
      ++it) {
    createAllEmbeddedFaces((*it), allEmbeddedFaces);
    createAllEmbeddedEdges((*it), allEmbeddedEdges);
  }
  connectTets(allTets.begin(), allTets.end(), &allEmbeddedFaces);
  Msg::Debug("All %d tets were connected", allTets.size());

  // here the classification should be done

  int ITER = 0, REALCOUNT = 0;
  int NB_CORRECTION_OF_CAVITY = 0;
  int COUNT_MISS_1 = 0;
  int COUNT_MISS_2 = 0;

  double t1 = TimeOfDay();

  // main loop in Delaunay inserstion starts here

  while(1) {
    if(maxIter > 0 && ITER >= maxIter) break;
    if(allTets.empty()) {
      Msg::Warning("No tetrahedra in region %d", gr->tag());
      break;
    }

    MTet4 *worst = *allTets.begin();

    if(worst->isDeleted()) {
      myFactory.Free(worst);
      allTets.erase(allTets.begin());
    }
    else {
      if(ITER++ % 500 == 0)
        Msg::Info("It. %d - %d nodes created - worst tet radius %g (nodes "
                  "removed %d %d)",
                  ITER - 1, REALCOUNT, worst->getRadius(), COUNT_MISS_1,
                  COUNT_MISS_2);
      if(worst->getRadius() < worstTetRadiusTarget) break;
      double center[3];
      double uvw[3];
      MTetrahedron *base = worst->tet();

      double pa[3] = {base->getVertex(0)->x(), base->getVertex(0)->y(),
                      base->getVertex(0)->z()};
      double pb[3] = {base->getVertex(1)->x(), base->getVertex(1)->y(),
                      base->getVertex(1)->z()};
      double pc[3] = {base->getVertex(2)->x(), base->getVertex(2)->y(),
                      base->getVertex(2)->z()};
      double pd[3] = {base->getVertex(3)->x(), base->getVertex(3)->y(),
                      base->getVertex(3)->z()};

      tetcircumcenter(pa, pb, pc, pd, center, nullptr, nullptr, nullptr);

      // A TEST !!!
      std::vector<faceXtet> shell;
      std::vector<MTet4 *> cavity;
      MVertex vv(center[0], center[1], center[2], worst->onWhat());
      findCavity(shell, cavity, &vv, worst);
      bool FOUND = false;
      for(auto itc = cavity.begin(); itc != cavity.end(); ++itc) {
        MTetrahedron *toto = (*itc)->tet();
        // (*itc)->setDeleted(false);
        toto->xyz2uvw(center, uvw);
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
          myFactory.changeTetRadius(allTets.begin(), 0.);
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
        myFactory.changeTetRadius(allTets.begin(), 0.0);
        COUNT_MISS_2++;
        for(auto itc = cavity.begin(); itc != cavity.end(); ++itc)
          (*itc)->setDeleted(false);
      }
    }

    // Normally, a tet mesh contains about 6 times more tets than vertices. This
    // allows to clean up the set of tets when lots of deleted ones are present
    // in the mesh
    if(allTets.size() > 7 * vSizes.size() && ITER > 1000) {
      memoryCleanup(myFactory, allTets);
    }
  }

  memoryCleanup(myFactory, allTets);
  double t2 = TimeOfDay();
  double dt = (t2 - t1);
  int COUNT_MISS = COUNT_MISS_1 + COUNT_MISS_2;
  Msg::Info("3D refinement terminated (%d nodes total):", (int)vSizes.size());
  Msg::Info(" - %d Delaunay cavities modified for star shapeness",
            NB_CORRECTION_OF_CAVITY);
  Msg::Info(" - %d nodes could not be inserted", COUNT_MISS);
  Msg::Info(" - %d tetrahedra created in %g sec. (%d tets/s)", allTets.size(),
            dt, (int)(allTets.size() / dt));

  // relocate vertices
  int nbReloc = 0;
  for(int SM = 0; SM < CTX::instance()->mesh.nbSmoothing; SM++) {
    for(auto it = allTets.begin(); it != allTets.end(); ++it) {
      if(!(*it)->isDeleted()) {
        double qq = (*it)->getQuality();
        if(qq < .4)
          for(int i = 0; i < 4; i++) {
            if(smoothVertex(*it, i, qmTetrahedron::QMTET_GAMMA)) nbReloc++;
          }
      }
    }
  }

  while(1) {
    if(allTets.begin() == allTets.end()) break;
    MTet4 *worst = *allTets.begin();
    if(!worst->isDeleted()) {
      worst->onWhat()->tetrahedra.push_back(worst->tet());
      worst->tet() = nullptr;
    }
    myFactory.Free(worst);
    allTets.erase(allTets.begin());
  }

  _deleteUnusedVertices(gr);
}

// do a 3D delaunay mesh assuming a set of vertices

void delaunayMeshIn3D(std::vector<MVertex *> &v,
                      std::vector<MTetrahedron *> &result, bool removeBox)
{
  Msg::Info("Tetrahedrizing %d nodes...", v.size());
  double t1 = Cpu(), w1 = TimeOfDay();
  delaunayTriangulation(1, 1, v, result, removeBox);
  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::Info("Done tetrahedrizing %d nodes (Wall %gs, CPU %gs)", v.size(),
            w2 - w1, t2 - t1);
}
