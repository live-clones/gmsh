// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdint>
#include "Octree.h"
#include "Context.h"
#include "GmshMessage.h"

namespace {

  struct Box {
    double min[3], max[3];
    // does the box, enlarged by d on each side, contain p?
    bool contains(const double *p, double d) const
    {
      return p[0] >= min[0] - d && p[0] <= max[0] + d && p[1] >= min[1] - d &&
             p[1] <= max[1] + d && p[2] >= min[2] - d && p[2] <= max[2] + d;
    }
    void add(const Box &b)
    {
      for(int k = 0; k < 3; k++) {
        min[k] = std::min(min[k], b.min[k]);
        max[k] = std::max(max[k], b.max[k]);
      }
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

  // the position of an element's box along a Z-order curve, and the element
  struct Item {
    uint64_t code;
    uint32_t id;
  };

  const int maxLeafSize = 4;
  const int maxDepth = 64;

} // namespace

class Octree {
public:
  void (*bbFunction)(void *, double *, double *);
  // elements, their boxes and their insertion index, in leaf order once the
  // tree is built
  std::vector<void *> elements;
  std::vector<Box> boxes;
  std::vector<uint32_t> order;
  std::vector<Node> nodes;
  bool built = false;
  void build();
  uint32_t buildNode(uint32_t first, uint32_t count);
  void searchAll(const double *p, double d, double a,
                 std::vector<void *> *out) const;
};

// Build a node over the items [first, first + count), which are sorted along a
// Z-order curve: its halves are two runs of the curve, which are compact. Its
// box is made afterwards, from the leaves up. Returns its index.
uint32_t Octree::buildNode(uint32_t first, uint32_t count)
{
  uint32_t idx = nodes.size();
  nodes.push_back(Node());
  if(count <= (uint32_t)maxLeafSize) {
    nodes[idx].first = first;
    nodes[idx].count = count;
    return idx;
  }
  uint32_t half = count / 2;
  buildNode(first, half); // the left child, just after the node
  uint32_t right = buildNode(first + half, count - half);
  nodes[idx].first = right;
  nodes[idx].count = 0;
  return idx;
}

// The bits of x spread to every third bit (21 bits in, 63 out).
static uint64_t spreadBits(uint64_t x)
{
  x &= 0x1fffff;
  x = (x | x << 32) & 0x1f00000000ffffULL;
  x = (x | x << 16) & 0x1f0000ff0000ffULL;
  x = (x | x << 8) & 0x100f00f00f00f00fULL;
  x = (x | x << 4) & 0x10c30c30c30c30c3ULL;
  x = (x | x << 2) & 0x1249249249249249ULL;
  return x;
}

void Octree::build()
{
  built = true;
  nodes.clear();
  std::size_t num = elements.size();
  if(!num) return;
  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();

  // the boxes of the elements inserted since the last build, all at once
  std::size_t done = boxes.size();
  boxes.resize(num);
#pragma omp parallel for num_threads(nthreads)
  for(std::size_t i = done; i < num; i++)
    bbFunction(elements[i], boxes[i].min, boxes[i].max);

  // The elements sorted along a Z-order curve through the centers of their
  // boxes, on a grid of 2^21 cells along the largest extent of the whole
  // (a shorter extent spans fewer cells, so that the first splits are along
  // the longest one), by a radix sort, which is stable: elements in the same
  // cell keep their order.
  double bmin[3], bmax[3];
  for(int k = 0; k < 3; k++) {
    bmin[k] = boxes[0].min[k];
    bmax[k] = boxes[0].max[k];
  }
  for(std::size_t i = 1; i < num; i++)
    for(int k = 0; k < 3; k++) {
      bmin[k] = std::min(bmin[k], boxes[i].min[k]);
      bmax[k] = std::max(bmax[k], boxes[i].max[k]);
    }
  double extent = std::max(std::max(bmax[0] - bmin[0], bmax[1] - bmin[1]),
                           bmax[2] - bmin[2]);
  double scale = (extent > 0.) ? (double)((1 << 21) - 1) / extent : 0.;
  std::vector<Item> items(num), tmp(num);
#pragma omp parallel for num_threads(nthreads)
  for(std::size_t i = 0; i < num; i++) {
    uint64_t code = 0;
    for(int k = 0; k < 3; k++) {
      double c = 0.5 * (boxes[i].min[k] + boxes[i].max[k]);
      code |= spreadBits((uint64_t)((c - bmin[k]) * scale)) << k;
    }
    items[i].code = code;
    items[i].id = (uint32_t)i;
  }
  uint64_t all = 0;
  for(std::size_t i = 0; i < num; i++) all |= items[i].code;
  for(int shift = 0; shift < 64; shift += 8) {
    if(!((all >> shift) & 0xff)) continue; // (no element has these bits)
    std::size_t count[257] = {0};
    for(std::size_t i = 0; i < num; i++)
      count[((items[i].code >> shift) & 0xff) + 1]++;
    for(int j = 0; j < 256; j++) count[j + 1] += count[j];
    for(std::size_t i = 0; i < num; i++)
      tmp[count[(items[i].code >> shift) & 0xff]++] = items[i];
    items.swap(tmp);
  }
  std::vector<Item>().swap(tmp);

  nodes.reserve(num / 2 + 1);
  buildNode(0, num);

  // store the elements in leaf order
  {
    std::vector<void *> e(num);
    std::vector<Box> b(num);
    std::vector<uint32_t> o(num);
#pragma omp parallel for num_threads(nthreads)
    for(std::size_t i = 0; i < num; i++) {
      e[i] = elements[items[i].id];
      b[i] = boxes[items[i].id];
      o[i] = order[items[i].id];
    }
    elements.swap(e);
    boxes.swap(b);
    order.swap(o);
  }

  // the boxes of the nodes, children (which come after their parent) first
  for(std::size_t i = nodes.size(); i-- > 0;) {
    Node &n = nodes[i];
    if(n.count) {
      n.box = boxes[n.first];
      n.maxSize = 0.;
      for(uint32_t j = n.first; j < n.first + n.count; j++) {
        n.box.add(boxes[j]);
        n.maxSize = std::max(n.maxSize, boxes[j].size());
      }
    }
    else {
      const Node &l = nodes[i + 1], &r = nodes[n.first];
      n.box = l.box;
      n.box.add(r.box);
      n.maxSize = std::max(l.maxSize, r.maxSize);
    }
  }
}

// Append the elements whose box, enlarged by d times the element size plus a,
// contains p, in insertion order.
void Octree::searchAll(const double *p, double d, double a,
                       std::vector<void *> *out) const
{
  if(nodes.empty()) return;
  std::vector<uint32_t> found;
  uint32_t stack[maxDepth];
  int n = 0;
  stack[n++] = 0;
  while(n) {
    const Node &node = nodes[stack[--n]];
    if(!node.box.contains(p, d * node.maxSize + a)) continue;
    if(node.count) {
      for(uint32_t i = node.first; i < node.first + node.count; i++) {
        if(boxes[i].contains(p, d * boxes[i].size() + a)) found.push_back(i);
      }
    }
    else {
      // the median split keeps the depth below log2(#elements) + 1
      stack[n++] = node.first;
      stack[n++] = &node - &nodes[0] + 1;
    }
  }
  std::sort(found.begin(), found.end(),
            [&](uint32_t a, uint32_t b) { return order[a] < order[b]; });
  for(auto i : found) out->push_back(elements[i]);
}

Octree *Octree_Create(void (*BB)(void *, double *, double *))
{
  Octree *o = new Octree;
  o->bbFunction = BB;
  return o;
}

void Octree_Delete(Octree *o) { delete o; }

void Octree_Insert(void *element, Octree *o)
{
  if(!o) return;
  // (its box is computed with the others by the build)
  o->order.push_back(o->elements.size());
  o->elements.push_back(element);
  o->built = false;
}

void Octree_Arrange(Octree *o)
{
  if(o && !o->built) o->build();
}

void Octree_SearchAllNear(double *p, Octree *o, double relTol, double d,
                          std::vector<void *> *out)
{
  if(!o) return;
  Octree_Arrange(o);
  o->searchAll(p, relTol, d, out);
}
