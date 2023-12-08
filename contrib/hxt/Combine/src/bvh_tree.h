#ifndef HXT_COMBINE_BVH_TREE_H_
#define HXT_COMBINE_BVH_TREE_H_

#include <hxt_bbox.h>
#include <basic_types.h>
#include <algorithm>
#include <vector>

/**
* \author Kilian Verhetsel
*/


class BVHTree {
  typedef unsigned int CellIndex;

  struct BVHNode {
    CellIndex id;
    BVHNode *left, *right;
    HXTBbox aabb;
  };

  std::vector<BVHNode> nodes;

  static constexpr int NUM_BINS = 16;

public:
  /**
   * Build a bounding volume hierarchy from an array of bounding boxes.
   */
  BVHTree(const std::vector<HXTBbox> &boxes): nodes(2*boxes.size() - 1) {
    HXTBbox aabb;
    hxtBboxInit(&aabb);
    for (const HXTBbox &box : boxes)
      mergeBbox(aabb, box);
    std::vector<CellIndex> ids(boxes.size());
    for (CellIndex i = 0; i < ids.size(); i++) ids[i] = i;

    build(&nodes[0], aabb, boxes.data(), &nodes[1], ids.data(), boxes.size());
  }

  /**
   * Calls a function f with the index of each primitive that intersects with
   * the given bounding box.
   */
  template<typename Function>
  void forEachIntersection(const HXTBbox &box, Function f) const {
    visit(&nodes[0], box, f);
  }

private:
  /**
   * Recursively builds a tree.
   *
   * \param node The root node of the sub-tree that will be built.
   * \param aabb AABB of the primitives contained in the node.
   * \param boxes AABB of all primitives.
   * \param nodes Array of nodes to used to allocate the children of this node.
   * \param ids Indices of the primitives to be sorted.
   * \param n Number of nodes in the
   */
  void build(BVHNode *node, const HXTBbox &aabb, const HXTBbox *boxes,
             BVHNode *nodes, CellIndex *ids, CellIndex n) {
    node->aabb = aabb;

    if (n == 1) {
      node->id = ids[0];
      node->left = node->right = nullptr;
      return;
    }

    node->left = &nodes[0];
    node->right = &nodes[1];

    int axisI = splitAxis(aabb);
    double h = (aabb.max[axisI] - aabb.min[axisI]) / NUM_BINS;

    HXTBbox bins[NUM_BINS];
    CellIndex numEntries[NUM_BINS];
    computeBins(bins, numEntries, axisI, h, aabb, boxes, ids, n);

    int bestI;
    HXTBbox bestBoxL, bestBoxR;
    CellIndex bestNLeft;
    findBestSplit(bestI, bestBoxL, bestBoxR, bestNLeft,
                  bins, numEntries, n);

    if (bestNLeft == 0 || bestNLeft == n)
      arbitrarySplit(bestNLeft, bestBoxL, bestBoxR, boxes, ids, n);
    else
      split(axisI, h, bestI, aabb, boxes, ids, n);

    build(node->left, bestBoxL, boxes, &nodes[2], ids, bestNLeft);
    build(node->right, bestBoxR, boxes, &nodes[2] + 2*bestNLeft - 2,
          ids + bestNLeft, n - bestNLeft);
  }

  /**
   * Recursively visits a node and calls f for all leaves which intersect with a
   * given bounding box.
   */
  template<typename Function>
  void visit(const BVHNode *node, const HXTBbox &box, Function f) const {
    const HXTBbox &nodeBox = node->aabb;
    if (intervalOverlap(nodeBox.min[0], nodeBox.max[0], box.min[0], box.max[0]) &&
        intervalOverlap(nodeBox.min[1], nodeBox.max[1], box.min[1], box.max[1]) &&
        intervalOverlap(nodeBox.min[2], nodeBox.max[2], box.min[2], box.max[2])) {
      if (node->left) {
        visit(node->left, box, f);
        visit(node->right, box, f);
      }
      else
        f(node->id);
    }
  }

  /**
   * Returns the index of the longest axis in the bounding box.
   */
  int splitAxis(const HXTBbox &box) const {
    double dx = box.max[0] - box.min[0];
    double dy = box.max[1] - box.min[1];
    double dz = box.max[2] - box.min[2];

    int i = 0;
    if (dy > dx) i = 1;
    if (dz > dx && dz > dy) i = 2;

    return i;
  }

  /**
   * Split a set of bounding boxes into bins based on splitting planes.
   *
   * \param[out] bins Bounding boxes of each bin
   * \param[out] numEntries number of primitives in each bin
   * \param axisI Index of the axis along which the split should occur.
   * \param h Distance between the splitting planes.
   * \param aabb Bounding box of the entire set of the entire set of primitives
   *   that should be sorted.
   * \param boxes Bounding boxes of all the primitives used by the algorithm.
   * \param ids Pointer to the indices of the primitives which are to be sorted.
   * \param n Number of primitives to sort.
   */
  void computeBins(HXTBbox *bins, CellIndex *numEntries,
                   int axisI, double h,
                   const HXTBbox &aabb, const HXTBbox *boxes,
                   const CellIndex *ids, CellIndex n) {
    for (int i = 0; i < NUM_BINS; i++) {
      hxtBboxInit(&bins[i]);
      numEntries[i] = 0;
    }

    double invH = 1.0 / h;

    for (CellIndex i = 0; i < n; i++) {
      const HXTBbox &box = boxes[ids[i]];
      double c = 0.5*(box.min[axisI] + box.max[axisI]);
      int id = invH*(c - aabb.min[axisI]);
      if (id < 0) id = 0;
      if (id >= NUM_BINS) id = NUM_BINS - 1;

      numEntries[id]++;
      mergeBbox(bins[id], box);
    }
  }

  /**
   * Compute the bounding box of the nodes on the right side of a partition.
   *
   * \param[out] boxesR Array containing the bounding box of the right side of
   *   the partition when splitting at each plane.
   * \param bins Bounding box of the primitives contained within each bin.
   */
  void computeRightBoundingBox(HXTBbox *boxesR, const HXTBbox *bins) {
    boxesR[NUM_BINS-2] = bins[NUM_BINS-1];
    for (int i = 1; i < NUM_BINS-1; i++) {
      boxesR[NUM_BINS-2-i] = boxesR[NUM_BINS-1-i];
      mergeBbox(boxesR[NUM_BINS-2-i], bins[NUM_BINS-i-1]);
    }
  }

  /**
   * Compute the index of the splitting plane yielding the least costly
   * partiton.
   *
   * \param[out] bestI Index of the best splitting plane
   * \param[out] bestBoxL Bounding box of the primitives on the left side of that
   *   spliting plane.
   * \param[out] bestBoxR Bounding box of the primitives on the right side of that
   *   spliting plane.
   * \param[out] bestNLeft Number of primitives on the left side of the splitting
   *   plane.
   * \param bins Bounding box of the contents between each plane
   * \param numEntries Number of primitives in each bin.
   * \param n Number of primitives to be sorted.
   */
  void findBestSplit(int &bestI, HXTBbox &bestBoxL, HXTBbox &bestBoxR,
                     CellIndex &bestNLeft,
                     const HXTBbox *bins, const CellIndex *numEntries,
                     CellIndex n) {
    HXTBbox boxesR[NUM_BINS-1];
    computeRightBoundingBox(boxesR, bins);

    bestI = 0;
    double bestCost = DBL_MAX;
    bestNLeft = 0;

    CellIndex nLeft = 0;
    HXTBbox boxL;
    hxtBboxInit(&boxL);
    for (int i = 0; i < NUM_BINS-1; i++) {
      if (numEntries[i] == 0) continue;

      mergeBbox(boxL, bins[i]);
      HXTBbox boxR = boxesR[i];

      nLeft += numEntries[i];

      double cost = nLeft*surfaceArea(boxL) + (n-nLeft)*surfaceArea(boxR);
      if (cost < bestCost) {
        bestI = i;
        bestCost = cost;
        bestBoxL = boxL;
        bestBoxR = boxR;
        bestNLeft = nLeft;
      }
    }
  }

  /**
   * Splits the point in an arbitrary partition. This is used when splitting the
   * point along a splitting plane turns out to be unsuccessful.
   *
   * \param[out] nLeft Number of primitives on the left side of the partition.
   * \param[out] boxL bounding box of the nodes on the left side of the
   *   partiton.
   * \param[out] boxR bounding box of the nodes on the right side of the
   *   partiton.
   */
  void arbitrarySplit(CellIndex &nLeft, HXTBbox &boxL, HXTBbox &boxR,
                      const HXTBbox *boxes,
                      CellIndex *ids, CellIndex n) {
    nLeft = n / 2;

    hxtBboxInit(&boxL);
    hxtBboxInit(&boxR);
    for (CellIndex i = 0; i < nLeft; i++)
      mergeBbox(boxL, boxes[ids[i]]);
    for (CellIndex i = nLeft; i < n; i++)
      mergeBbox(boxR, boxes[ids[i]]);
  }

  /**
   * Splits the set of primitives along a plane.
   *
   * \param axisI Axis along which the plane should split.
   * \param h Distance between ecah splitting plane
   * \param splitId ID of the plane where the split should occur.
   * \param aabb Bounding box of the entire set of primitive to split.
   * \param boxes Bounding boxes of all the primitives used by the algorithm.
   * \param ids Pointer to the indices of the primitives which are to be split.
   * \param n Number of primitives to split.
   *
   * \return Number of primitives on the left side of the split.
   */
  CellIndex split(int axisI, double h, int splitId, const HXTBbox &aabb,
                  const HXTBbox *boxes, CellIndex *ids, CellIndex n) {
    CellIndex iRight = n;

    double invH = 1.0 / h;

    CellIndex i = 0;
    while (i < iRight) {
      const HXTBbox &box = boxes[ids[i]];
      double c = 0.5*(box.min[axisI] + box.max[axisI]);
      int id = invH*(c - aabb.min[axisI]);
      if (id < 0) id = 0;
      if (id >= NUM_BINS) id = NUM_BINS - 1;

      if (id > splitId)
        std::swap(ids[--iRight], ids[i]);
      else
        i++;
    }

    return i;
  }

  /**
   * Merges two bounding boxes.
   */
  void mergeBbox(HXTBbox &dst, const HXTBbox &box) {
    for (int i = 0; i < 3; i++) dst.min[i] = std::min(dst.min[i], box.min[i]);
    for (int i = 0; i < 3; i++) dst.max[i] = std::max(dst.max[i], box.max[i]);
  }

  double surfaceArea(const HXTBbox &box) const {
    double dx = box.max[0] - box.min[0];
    double dy = box.max[1] - box.min[1];
    double dz = box.max[2] - box.min[2];

    return dx*dy + dy*dz + dx*dz;
  }

  bool intervalOverlap(double min1, double max1, double min2, double max2) const {
    return max1 >= min2 && max2 >= min1;
  }
};

#endif
