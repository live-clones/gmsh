// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "SizeOctree.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <set>

#include "GmshMessage.h"

namespace {

inline int axisOf(int dir) { return dir / 2; }
inline int signOf(int dir) { return (dir % 2 == 0) ? -1 : 1; }
inline int opposite(int dir) { return dir ^ 1; }

inline uint64_t getCoord(const SizeOctant *o, int axis)
{
  return axis == 0 ? o->ix : (axis == 1 ? o->iy : o->iz);
}

void collectLeavesRec(SizeOctant *node, std::vector<SizeOctant *> &out)
{
  if(node->isLeaf()) {
    out.push_back(node);
    return;
  }
  for(int c = 0; c < 8; ++c) collectLeavesRec(node->children[c], out);
}

} // namespace

SizeOctree::SizeOctree(const SBoundingBox3d &domain, int maxLevel)
  : _root(nullptr), _maxLevel(maxLevel)
{
  SPoint3 c = domain.center();
  double dx = domain.max().x() - domain.min().x();
  double dy = domain.max().y() - domain.min().y();
  double dz = domain.max().z() - domain.min().z();
  double halfEdge = 0.5 * std::max(dx, std::max(dy, dz));
  if(halfEdge <= 0.) halfEdge = 1.; // degenerate/empty domain guard

  _rootWidth = 2. * halfEdge;
  _origin = SPoint3(c.x() - halfEdge, c.y() - halfEdge, c.z() - halfEdge);
  _rootUnits = (uint64_t(1) << _maxLevel);

  _root = new SizeOctant();
  _root->ix = _root->iy = _root->iz = 0;
  _root->level = 0;
  _root->halfWidth = halfEdge;
  _root->parent = nullptr;
}

SizeOctree::~SizeOctree()
{
  for(SizeOctant *blk : _blocks) delete[] blk;
  delete _root;
}

SPoint3 SizeOctree::corner(const SizeOctant *o) const
{
  double x = _origin.x() + _rootWidth * (double)o->ix / (double)_rootUnits;
  double y = _origin.y() + _rootWidth * (double)o->iy / (double)_rootUnits;
  double z = _origin.z() + _rootWidth * (double)o->iz / (double)_rootUnits;
  return SPoint3(x, y, z);
}

SPoint3 SizeOctree::center(const SizeOctant *o) const
{
  SPoint3 c0 = corner(o);
  return SPoint3(c0.x() + o->halfWidth, c0.y() + o->halfWidth,
                 c0.z() + o->halfWidth);
}

SBoundingBox3d SizeOctree::bbox(const SizeOctant *o) const
{
  SPoint3 c0 = corner(o);
  double s = 2. * o->halfWidth;
  return SBoundingBox3d(c0.x(), c0.y(), c0.z(), c0.x() + s, c0.y() + s,
                         c0.z() + s);
}

void SizeOctree::toInt(const SPoint3 &p, uint64_t out[3]) const
{
  double coords[3] = {p.x(), p.y(), p.z()};
  double o[3] = {_origin.x(), _origin.y(), _origin.z()};
  for(int a = 0; a < 3; ++a) {
    double t = (coords[a] - o[a]) / _rootWidth;
    if(t < 0.) t = 0.;
    if(t > 1.) t = 1.;
    uint64_t u = (uint64_t)(t * (double)_rootUnits);
    if(u >= _rootUnits) u = _rootUnits - 1;
    out[a] = u;
  }
}

bool SizeOctree::containsPoint(const SizeOctant *node,
                                const uint64_t p[3]) const
{
  uint64_t w = widthUnits(node->level);
  return p[0] >= node->ix && p[0] < node->ix + w && p[1] >= node->iy &&
         p[1] < node->iy + w && p[2] >= node->iz && p[2] < node->iz + w;
}

int SizeOctree::childIndexFor(const SizeOctant *node,
                               const uint64_t p[3]) const
{
  uint64_t half = widthUnits(node->level + 1);
  int idx = 0;
  if(p[0] >= node->ix + half) idx |= 1;
  if(p[1] >= node->iy + half) idx |= 2;
  if(p[2] >= node->iz + half) idx |= 4;
  return idx;
}

SizeOctant *SizeOctree::findLeaf(const SPoint3 &p) const
{
  uint64_t t[3];
  toInt(p, t);
  SizeOctant *cur = _root;
  while(!cur->isLeaf()) {
    int idx = childIndexFor(cur, t);
    cur = cur->children[idx];
  }
  return cur;
}

SizeOctant *SizeOctree::splitLeaf(SizeOctant *leaf)
{
  if(!leaf->isLeaf()) return leaf;
  if(leaf->level >= _maxLevel) {
    Msg::Warning("SizeOctree: cannot refine octant beyond maxLevel (%d)",
                 _maxLevel);
    return leaf;
  }

  SizeOctant *block = new SizeOctant[8];
  _blocks.push_back(block);

  uint64_t cw = widthUnits(leaf->level + 1);
  double childHalf = leaf->halfWidth * 0.5;

  for(int c = 0; c < 8; ++c) {
    SizeOctant &child = block[c];
    child.ix = leaf->ix + ((c & 1) ? cw : 0);
    child.iy = leaf->iy + ((c & 2) ? cw : 0);
    child.iz = leaf->iz + ((c & 4) ? cw : 0);
    child.level = leaf->level + 1;
    child.halfWidth = childHalf;
    child.parent = leaf;
    child.h = leaf->h;
    child.grad[0] = leaf->grad[0];
    child.grad[1] = leaf->grad[1];
    child.grad[2] = leaf->grad[2];
    child.hasIntersection = leaf->hasIntersection;
    child.generation = leaf->generation + 1;
    leaf->children[c] = &child;
  }
  return leaf;
}

SizeOctant *SizeOctree::refine(SizeOctant *leaf)
{
  if(!leaf->isLeaf()) return leaf;
  if(leaf->level >= _maxLevel) return leaf;
  splitLeaf(leaf);
  std::vector<SizeOctant *> seed(leaf->children, leaf->children + 8);
  balanceFrom(seed);
  return leaf;
}

SizeOctant *SizeOctree::refineAt(const SPoint3 &p, int targetLevel)
{
  int target = std::min(targetLevel, _maxLevel);
  SizeOctant *leaf = findLeaf(p);
  while(leaf->level < target) {
    refine(leaf);
    leaf = findLeaf(p);
  }
  return leaf;
}

bool SizeOctree::coarsen(SizeOctant *node)
{
  if(node->isLeaf()) return false;
  for(int c = 0; c < 8; ++c)
    if(!node->children[c]->isLeaf()) return false;
  // Children are not freed here (see class comment): the tree only frees
  // memory in bulk, in the destructor.
  for(int c = 0; c < 8; ++c) node->children[c] = nullptr;
  node->generation++;
  return true;
}

void SizeOctree::collectFaceLeaves(SizeOctant *node, int faceDir,
                                    std::vector<SizeOctant *> &out) const
{
  if(node->isLeaf()) {
    out.push_back(node);
    return;
  }
  int axis = axisOf(faceDir);
  int wantBit = (signOf(faceDir) < 0) ? 0 : 1;
  for(int c = 0; c < 8; ++c) {
    int bit = (c >> axis) & 1;
    if(bit == wantBit) collectFaceLeaves(node->children[c], faceDir, out);
  }
}

std::vector<SizeOctant *> SizeOctree::faceNeighbors(SizeOctant *leaf,
                                                      int dir) const
{
  std::vector<SizeOctant *> result;
  int axis = axisOf(dir);
  uint64_t w = widthUnits(leaf->level);
  uint64_t half = w / 2;

  uint64_t t[3] = {leaf->ix, leaf->iy, leaf->iz};
  for(int a = 0; a < 3; ++a)
    if(a != axis) t[a] += half;

  uint64_t leafCoord = getCoord(leaf, axis);
  if(signOf(dir) < 0) {
    if(leafCoord == 0) return result; // domain boundary
    t[axis] = leafCoord - 1;
  }
  else {
    uint64_t beyond = leafCoord + w;
    if(beyond >= _rootUnits) return result; // domain boundary
    t[axis] = beyond;
  }

  // Search up: find the smallest ancestor of leaf containing target point t.
  SizeOctant *anc = leaf;
  while(anc->parent && !containsPoint(anc, t)) anc = anc->parent;
  if(!containsPoint(anc, t)) return result; // should not happen

  // Search down: stop at the first leaf, or at a node already at leaf's
  // level (meaning the neighbor region is refined beyond leaf).
  SizeOctant *cur = anc;
  while(!cur->isLeaf() && cur->level < leaf->level) {
    int idx = childIndexFor(cur, t);
    cur = cur->children[idx];
  }

  if(cur->isLeaf()) { result.push_back(cur); }
  else {
    collectFaceLeaves(cur, opposite(dir), result);
  }
  return result;
}

void SizeOctree::refineWhile(
  const std::function<bool(const SizeOctant *)> &shouldRefine)
{
  std::vector<SizeOctant *> worklist = leaves();
  size_t head = 0;
  while(head < worklist.size()) {
    SizeOctant *o = worklist[head++];
    if(!o->isLeaf()) continue;
    if(o->level >= _maxLevel) continue;
    if(shouldRefine(o)) {
      splitLeaf(o);
      for(int c = 0; c < 8; ++c) worklist.push_back(o->children[c]);
    }
  }
}

void SizeOctree::coarsenWhile(
  const std::function<bool(const SizeOctant *)> &canCoarsen)
{
  bool changed = true;
  while(changed) {
    changed = false;
    std::set<SizeOctant *> seenParents;
    std::vector<SizeOctant *> candidates;
    for(SizeOctant *leaf : leaves()) {
      SizeOctant *p = leaf->parent;
      if(!p || !seenParents.insert(p).second) continue;
      bool allLeaves = true;
      for(int c = 0; c < 8; ++c)
        if(!p->children[c]->isLeaf()) {
          allLeaves = false;
          break;
        }
      if(allLeaves) candidates.push_back(p);
    }
    for(SizeOctant *cand : candidates) {
      if(canCoarsen(cand) && coarsen(cand)) changed = true;
    }
  }
}

void SizeOctree::balance() { balanceFrom(leaves()); }

void SizeOctree::balanceFrom(std::vector<SizeOctant *> worklist)
{
  size_t head = 0;
  while(head < worklist.size()) {
    SizeOctant *L = worklist[head++];
    if(!L->isLeaf()) continue; // stale entry: was split meanwhile

    bool selfWasSplit = false;
    for(int d = 0; d < 6 && !selfWasSplit; ++d) {
      std::vector<SizeOctant *> nbrs = faceNeighbors(L, d);
      for(SizeOctant *N : nbrs) {
        int diff = N->level - L->level;
        if(diff > 1) {
          if(L->level >= _maxLevel) continue;
          splitLeaf(L);
          for(int c = 0; c < 8; ++c) worklist.push_back(L->children[c]);
          selfWasSplit = true;
          break;
        }
        else if(diff < -1) {
          if(N->level >= _maxLevel) continue;
          splitLeaf(N);
          for(int c = 0; c < 8; ++c) worklist.push_back(N->children[c]);
        }
      }
    }
  }
}

std::vector<SizeOctant *> SizeOctree::leaves() const
{
  std::vector<SizeOctant *> out;
  collectLeavesRec(_root, out);
  return out;
}

size_t SizeOctree::numLeaves() const { return leaves().size(); }

size_t SizeOctree::numNodes() const { return 1 + 8 * _blocks.size(); }

void SizeOctree::assignSizes(
  const std::function<double(const SizeOctant *)> &assignSize)
{
  for(SizeOctant *leaf : leaves()) leaf->h = assignSize(leaf);
}

void SizeOctree::computeGradientOn(const std::vector<SizeOctant *> &region)
{
  for(SizeOctant *o : region) o->grad[0] = o->grad[1] = o->grad[2] = 0.;
  for(SizeOctant *l : region) {
    for(int d = 0; d < 6; ++d) {
      std::vector<SizeOctant *> nbrs = faceNeighbors(l, d);
      if(nbrs.empty()) continue; // domain boundary: zero flux
      double hAvg = 0.;
      for(SizeOctant *n : nbrs) hAvg += n->h;
      hAvg /= (double)nbrs.size();
      double dist = l->halfWidth + nbrs[0]->halfWidth;
      l->grad[axisOf(d)] += signOf(d) * 0.5 * (hAvg - l->h) / dist;
    }
  }
}

void SizeOctree::computeGradient() { computeGradientOn(leaves()); }

double SizeOctree::maxGradientNorm() const
{
  double m = 0.;
  for(SizeOctant *l : leaves())
    for(int k = 0; k < 3; ++k) m = std::max(m, std::fabs(l->grad[k]));
  return m;
}

bool SizeOctree::limitGradientOn(const std::vector<SizeOctant *> &region,
                                  double alpha)
{
  const double tol = 1e-3;
  bool changed = false;
  for(SizeOctant *l : region) {
    for(int d = 0; d < 6; ++d) {
      int axis = axisOf(d);
      if(std::fabs(l->grad[axis]) <= alpha + tol) continue;
      for(SizeOctant *n : faceNeighbors(l, d)) {
        double dist = l->halfWidth + n->halfWidth;
        if(l->h > n->h) {
          double capped = n->h + alpha * dist;
          if(capped < l->h) {
            l->h = capped;
            changed = true;
          }
        }
        else {
          double capped = l->h + alpha * dist;
          if(capped < n->h) {
            n->h = capped;
            changed = true;
          }
        }
      }
    }
  }
  return changed;
}

bool SizeOctree::limitGradient(double alpha)
{
  return limitGradientOn(leaves(), alpha);
}

void SizeOctree::sizeSmoothing(double alpha, int maxIter)
{
  const double tol = 1e-3;
  double gradLinf = 1e22;
  int iter = 0;
  while(iter++ < maxIter && gradLinf > tol + alpha) {
    computeGradient();
    limitGradient(alpha);
    gradLinf = maxGradientNorm();
  }
  Msg::Info("SizeOctree: max size gradient after smoothing = %g "
            "(target <= %g, %d iteration(s))",
            gradLinf, alpha, iter - 1);
}

void SizeOctree::relimitAround(SizeOctant *seed, int rings, double alpha)
{
  std::set<SizeOctant *> visited = {seed};
  std::vector<SizeOctant *> frontier = {seed};
  for(int r = 0; r < rings; ++r) {
    std::vector<SizeOctant *> next;
    for(SizeOctant *o : frontier)
      for(int d = 0; d < 6; ++d)
        for(SizeOctant *n : faceNeighbors(o, d))
          if(visited.insert(n).second) next.push_back(n);
    frontier = next;
  }
  std::vector<SizeOctant *> region(visited.begin(), visited.end());

  const double tol = 1e-3;
  double gradLinf = 1e22;
  int iter = 0;
  while(iter++ < 20 && gradLinf > tol + alpha) {
    computeGradientOn(region);
    limitGradientOn(region, alpha);
    gradLinf = 0.;
    for(SizeOctant *o : region)
      for(int k = 0; k < 3; ++k)
        gradLinf = std::max(gradLinf, std::fabs(o->grad[k]));
  }
}

double SizeOctree::eval(const SPoint3 &p) const
{
  SizeOctant *leaf = findLeaf(p);
  SPoint3 c = center(leaf);
  return leaf->h + leaf->grad[0] * (p.x() - c.x()) +
         leaf->grad[1] * (p.y() - c.y()) + leaf->grad[2] * (p.z() - c.z());
}

double SizeOctree::estimateElementCount() const
{
  double total = 0.;
  for(SizeOctant *o : leaves()) {
    double octantVolume = std::pow(2. * o->halfWidth, 3);
    double tetVolume = o->h * o->h * o->h * std::sqrt(2.) / 12.;
    if(tetVolume > 0.) total += octantVolume / tetVolume;
  }
  return total;
}

void SizeOctree::exportPos(const std::string &fileName) const
{
  std::ofstream f(fileName.c_str());
  if(!f.is_open()) {
    Msg::Error("SizeOctree::exportPos: cannot open '%s'", fileName.c_str());
    return;
  }
  f << "View \"SizeOctree\" {\n";
  for(SizeOctant *o : leaves()) {
    SPoint3 c0 = corner(o);
    double s = 2. * o->halfWidth;
    double x[8] = {c0.x(),     c0.x() + s, c0.x() + s, c0.x(),
                   c0.x(),     c0.x() + s, c0.x() + s, c0.x()};
    double y[8] = {c0.y(),     c0.y(),     c0.y() + s, c0.y() + s,
                   c0.y(),     c0.y(),     c0.y() + s, c0.y() + s};
    double z[8] = {c0.z(),     c0.z(),     c0.z(),     c0.z(),
                   c0.z() + s, c0.z() + s, c0.z() + s, c0.z() + s};
    f << "SH(";
    for(int i = 0; i < 8; ++i) {
      if(i) f << ",";
      f << x[i] << "," << y[i] << "," << z[i];
    }
    f << "){";
    for(int i = 0; i < 8; ++i) {
      if(i) f << ",";
      f << o->h;
    }
    f << "};\n";
  }
  f << "};\n";
}
