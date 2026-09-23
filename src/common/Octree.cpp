// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdint>
#include "Octree.h"

namespace {

  struct Box {
    double min[3], max[3];
    // does the box, enlarged by d on each side, contain p?
    bool contains(const double *p, double d) const
    {
      return p[0] >= min[0] - d && p[0] <= max[0] + d && p[1] >= min[1] - d &&
             p[1] <= max[1] + d && p[2] >= min[2] - d && p[2] <= max[2] + d;
    }
    double size() const
    {
      return std::max(std::max(max[0] - min[0], max[1] - min[1]),
                      max[2] - min[2]);
    }
  };

  // A leaf holds the elements [first, first + count); an internal node
  // (count == 0) has its left child just after it and its right child at
  // index first.
  struct Node {
    Box box;
    double maxSize; // largest element size below, for Octree_SearchAllNear
    uint32_t first, count;
  };

  const int maxLeafSize = 4;
  const int maxDepth = 64;

} // namespace

class Octree {
public:
  void (*bbFunction)(void *, double *, double *);
  int (*inEleFunction)(void *, double *);
  // elements, their boxes and their insertion index, in leaf order once the
  // tree is built
  std::vector<void *> elements;
  std::vector<Box> boxes;
  std::vector<uint32_t> order;
  std::vector<Node> nodes;
  bool built = false;
  void build();
  uint32_t buildNode(uint32_t first, uint32_t count,
                     std::vector<uint32_t> &perm,
                     const std::vector<double> &centers);
  template <class F>
  void visit(const double *p, double d, double a, F f) const;
  void searchAll(double *p, double relTol, double margin, bool test,
                 std::vector<void *> *out) const;
};

uint32_t Octree::buildNode(uint32_t first, uint32_t count,
                           std::vector<uint32_t> &perm,
                           const std::vector<double> &centers)
{
  uint32_t idx = nodes.size();
  nodes.push_back(Node());
  Node n;
  n.box = boxes[perm[first]];
  n.maxSize = 0.;
  double cmin[3], cmax[3];
  for(int k = 0; k < 3; k++) cmin[k] = cmax[k] = centers[3 * perm[first] + k];
  for(uint32_t i = first; i < first + count; i++) {
    const Box &b = boxes[perm[i]];
    const double *c = &centers[3 * perm[i]];
    for(int k = 0; k < 3; k++) {
      n.box.min[k] = std::min(n.box.min[k], b.min[k]);
      n.box.max[k] = std::max(n.box.max[k], b.max[k]);
      cmin[k] = std::min(cmin[k], c[k]);
      cmax[k] = std::max(cmax[k], c[k]);
    }
    n.maxSize = std::max(n.maxSize, b.size());
  }
  if(count <= maxLeafSize) {
    n.first = first;
    n.count = count;
    nodes[idx] = n;
    return idx;
  }

  // split at the median of the centers along their largest extent (ties
  // broken by insertion index, so that the tree does not depend on the
  // implementation of nth_element)
  int axis = 0;
  for(int k = 1; k < 3; k++)
    if(cmax[k] - cmin[k] > cmax[axis] - cmin[axis]) axis = k;
  uint32_t half = count / 2;
  std::nth_element(perm.begin() + first, perm.begin() + first + half,
                   perm.begin() + first + count, [&](uint32_t a, uint32_t b) {
                     double ca = centers[3 * a + axis],
                            cb = centers[3 * b + axis];
                     return ca < cb || (ca == cb && a < b);
                   });
  n.count = 0;
  buildNode(first, half, perm, centers);
  n.first = buildNode(first + half, count - half, perm, centers);
  nodes[idx] = n;
  return idx;
}

void Octree::build()
{
  built = true;
  nodes.clear();
  std::size_t num = elements.size();
  if(!num) return;
  std::vector<double> centers(3 * num);
  for(std::size_t i = 0; i < num; i++)
    for(int k = 0; k < 3; k++)
      centers[3 * i + k] = 0.5 * (boxes[i].min[k] + boxes[i].max[k]);
  std::vector<uint32_t> perm(num);
  for(std::size_t i = 0; i < num; i++) perm[i] = i;
  nodes.reserve(2 * num / maxLeafSize + 1);
  buildNode(0, num, perm, centers);
  // store the elements in leaf order
  std::vector<void *> e(num);
  std::vector<Box> b(num);
  std::vector<uint32_t> o(num);
  for(std::size_t i = 0; i < num; i++) {
    e[i] = elements[perm[i]];
    b[i] = boxes[perm[i]];
    o[i] = order[perm[i]];
  }
  elements.swap(e);
  boxes.swap(b);
  order.swap(o);
}

// Call f(i) for each element i whose box, enlarged by d times the element
// size plus a, contains p, until f returns true.
template <class F>
void Octree::visit(const double *p, double d, double a, F f) const
{
  if(nodes.empty()) return;
  uint32_t stack[maxDepth];
  int n = 0;
  stack[n++] = 0;
  while(n) {
    const Node &node = nodes[stack[--n]];
    if(!node.box.contains(p, d * node.maxSize + a)) continue;
    if(node.count) {
      for(uint32_t i = node.first; i < node.first + node.count; i++) {
        if(boxes[i].contains(p, d * boxes[i].size() + a) && f(i)) return;
      }
    }
    else {
      // the median split keeps the depth below log2(#elements) + 1
      stack[n++] = node.first;
      stack[n++] = &node - &nodes[0] + 1;
    }
  }
}

void Octree::searchAll(double *p, double relTol, double margin, bool test,
                       std::vector<void *> *out) const
{
  std::vector<uint32_t> found;
  visit(p, relTol, margin, [&](uint32_t i) {
    if(!test || inEleFunction(elements[i], p)) found.push_back(i);
    return false;
  });
  std::sort(found.begin(), found.end(),
            [&](uint32_t a, uint32_t b) { return order[a] < order[b]; });
  for(auto i : found) out->push_back(elements[i]);
}

Octree *Octree_Create(void (*BB)(void *, double *, double *),
                      int (*InEle)(void *, double *))
{
  Octree *o = new Octree;
  o->bbFunction = BB;
  o->inEleFunction = InEle;
  return o;
}

void Octree_Delete(Octree *o) { delete o; }

void Octree_Insert(void *element, Octree *o)
{
  if(!o) return;
  double min[3], max[3];
  o->bbFunction(element, min, max);
  Box b;
  for(int k = 0; k < 3; k++) {
    b.min[k] = min[k];
    b.max[k] = max[k];
  }
  o->order.push_back(o->elements.size());
  o->elements.push_back(element);
  o->boxes.push_back(b);
  o->built = false;
}

void Octree_Arrange(Octree *o)
{
  if(o && !o->built) o->build();
}

void *Octree_Search(double *p, Octree *o)
{
  if(!o) return nullptr;
  Octree_Arrange(o);
  // the first inserted element containing the point, so that the result does
  // not depend on the structure of the tree
  uint32_t best = UINT32_MAX;
  o->visit(p, 0., 0., [&](uint32_t i) {
    if(best != UINT32_MAX && o->order[i] > o->order[best]) return false;
    if(o->inEleFunction(o->elements[i], p)) best = i;
    return false;
  });
  return (best == UINT32_MAX) ? nullptr : o->elements[best];
}

void Octree_SearchAll(double *p, Octree *o, std::vector<void *> *out)
{
  if(!o) return;
  Octree_Arrange(o);
  o->searchAll(p, 0., 0., true, out);
}

void Octree_SearchAllNear(double *p, Octree *o, double relTol,
                          std::vector<void *> *out)
{
  if(!o) return;
  Octree_Arrange(o);
  o->searchAll(p, relTol, 0., false, out);
}

void Octree_SearchAllWithin(double *p, Octree *o, double d,
                            std::vector<void *> *out)
{
  if(!o) return;
  Octree_Arrange(o);
  o->searchAll(p, 0., d, false, out);
}
