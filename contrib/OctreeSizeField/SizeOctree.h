// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Recursive, pointer-based, dynamically refinable octree used to store an
// isotropic mesh size field, following the octree design of
// Bawin, Henrotte, Remacle, "Automatic feature-preserving size field for
// three-dimensional mesh generation", IJNME 2021 (Sections 2.3-2.5).
//
// This module has no dependency on p4est (or any other external library):
// it replaces the p4est-based tree that used to back
// src/mesh/automaticMeshSizeField.cpp. It knows nothing about curvature,
// feature size, RTrees or CAD models -- that logic lives in
// OctreeSizeField.{h,cpp}, which uses this class purely as a container for
// an adaptive scalar field h(x).

#ifndef SIZE_OCTREE_H
#define SIZE_OCTREE_H

#include <cstdint>
#include <functional>
#include <string>
#include <vector>

#include "SPoint3.h"
#include "SBoundingBox3d.h"

// Face directions used by SizeOctree::faceNeighbors(): axis = dir/2 (0=x,
// 1=y, 2=z), sign = -1 for an even dir, +1 for an odd dir.
enum SizeOctreeDir {
  DIR_XM = 0,
  DIR_XP = 1,
  DIR_YM = 2,
  DIR_YP = 3,
  DIR_ZM = 4,
  DIR_ZP = 5
};

// One node ("octant") of a SizeOctree: a cube-shaped cell that is either a
// leaf carrying a mesh-size value, or has exactly 8 children (never a
// partial set).
struct SizeOctant {
  // Min-corner coordinates, expressed in integer units at the tree's finest
  // representable level (exact arithmetic, no floating-point epsilons in
  // neighbor searches).
  uint64_t ix = 0, iy = 0, iz = 0;
  int level = 0; // 0 = root
  double halfWidth = 0.; // physical half-edge-length, cached

  SizeOctant *parent = nullptr;
  SizeOctant *children[8] = {nullptr, nullptr, nullptr, nullptr,
                              nullptr, nullptr, nullptr, nullptr};

  double h = 0.; // mesh size value assigned to this octant (the paper's h)
  double grad[3] = {0., 0., 0.}; // finite-difference gradient of h at center
  bool hasIntersection = false; // cached: does this octant intersect the
                                 // input surface mesh? (set by the caller)
  uint32_t generation = 0; // bumped whenever the local structure changes

  bool isLeaf() const { return children[0] == nullptr; }
};

// A recursive, pointer-based, dynamically refinable octree.
//
// The tree always covers a cubic root domain (computed from the supplied
// bounding box) and is kept 2:1-balanced -- face-adjacent leaves never
// differ by more than one refinement level -- between any two public calls:
// refine()/refineAt() restore that invariant locally before returning, so
// the tree can be grown incrementally at any time, not just built once and
// frozen (unlike the p4est "forest" it replaces).
//
// Memory: children are always allocated 8 at a time (one per split); a
// coarsen() detaches a node's children without freeing them (kept alive
// until the tree itself is destroyed) to avoid dangling pointers for
// callers that may still be holding a reference to them -- a deliberate
// simplification, acceptable since coarsen() is only used once, early, in
// the size-field construction pipeline, well before the tree becomes large.
class SizeOctree {
public:
  // domain is expanded internally to the smallest cube containing it,
  // centered on its center. maxLevel bounds the refinement depth (an
  // octant at maxLevel can no longer be split).
  explicit SizeOctree(const SBoundingBox3d &domain, int maxLevel = 24);
  ~SizeOctree();

  SizeOctree(const SizeOctree &) = delete;
  SizeOctree &operator=(const SizeOctree &) = delete;

  SizeOctant *root() const { return _root; }
  int maxLevel() const { return _maxLevel; }
  const SPoint3 &origin() const { return _origin; }
  double rootWidth() const { return _rootWidth; }

  // Geometry helpers.
  SPoint3 center(const SizeOctant *o) const;
  SBoundingBox3d bbox(const SizeOctant *o) const;

  // Point location: returns the leaf containing p (p is clamped to the
  // root domain if it lies outside).
  SizeOctant *findLeaf(const SPoint3 &p) const;

  // Splits a leaf into 8 children, then locally restores the 2:1 balance
  // invariant (may recursively split some neighbors too). No-op (returns
  // leaf unchanged) if leaf is already internal or at maxLevel().
  SizeOctant *refine(SizeOctant *leaf);

  // Repeatedly refines the leaf containing p until it reaches targetLevel
  // (clamped to maxLevel()). Returns the final leaf containing p.
  SizeOctant *refineAt(const SPoint3 &p, int targetLevel);

  // Merges the 8 children of node (which must all currently be leaves) back
  // into a single leaf; returns false and does nothing otherwise. Does NOT
  // re-check/restore the 2:1 invariant -- call balance() afterwards if
  // needed (this mirrors the construction pipeline in the paper, where
  // coarsening precedes the final balancing pass).
  bool coarsen(SizeOctant *node);

  // Returns the 1 to 4 leaves touching the face of `leaf` in direction dir;
  // empty if that face lies on the domain boundary. A single result means
  // a same-size-or-coarser ("full") neighbor; several results mean a finer
  // ("hanging") neighbor region.
  std::vector<SizeOctant *> faceNeighbors(SizeOctant *leaf, int dir) const;

  // Repeatedly splits every current leaf for which shouldRefine() holds,
  // including newly created children, until none qualify or maxLevel() is
  // reached. Purely structural: does not rebalance (call balance()
  // afterwards) and does not touch h/grad beyond the default inheritance
  // performed by the split itself.
  void refineWhile(const std::function<bool(const SizeOctant *)> &shouldRefine);

  // Applies canCoarsen() to every current group of 8 sibling leaves
  // (bottom-up, repeated until no candidate qualifies), coarsening those
  // for which it returns true.
  void coarsenWhile(const std::function<bool(const SizeOctant *)> &canCoarsen);

  // Restores the 2:1 balance invariant everywhere in the tree.
  void balance();

  std::vector<SizeOctant *> leaves() const;
  size_t numLeaves() const;
  size_t numNodes() const;

  // Sets every leaf's h using assignSize(leaf).
  void assignSizes(const std::function<double(const SizeOctant *)> &assignSize);

  // Gradient computation and limitation (paper eq. 18-22): iteratively
  // caps h so that ||grad h||_inf <= alpha everywhere (alpha = gradation-1).
  void computeGradient();
  double maxGradientNorm() const; // max |grad_k| over all leaves, all axes
  bool limitGradient(double alpha); // one pass; true if any h was reduced
  void sizeSmoothing(double alpha, int maxIter = 100);

  // Cheap local re-limitation restricted to the `rings`-neighborhood of
  // seed (BFS over face neighbors) -- meant to be called after an isolated
  // refine()/refineAt() call, as a lightweight alternative to a full
  // sizeSmoothing() pass over the whole tree.
  void relimitAround(SizeOctant *seed, int rings, double alpha);

  // First-order (Taylor) evaluation of h at an arbitrary point, from the
  // containing leaf's value and gradient (paper eq. 23). Always returns a
  // structurally valid value; may transiently violate the gradation bound
  // if called between a refine() and the next relimitAround()/
  // sizeSmoothing().
  double eval(const SPoint3 &p) const;

  double estimateElementCount() const;

  // Debug dump of the leaf octants (as scalar hexahedra colored by h) to a
  // Gmsh .pos file.
  void exportPos(const std::string &fileName) const;

private:
  SizeOctant *_root;
  SPoint3 _origin; // physical min corner of the root cube
  double _rootWidth; // physical edge length of the root cube
  int _maxLevel;
  uint64_t _rootUnits; // 1 << maxLevel: root width, in finest-level units
  std::vector<SizeOctant *> _blocks; // owns every allocated 8-block of children

  uint64_t widthUnits(int level) const { return _rootUnits >> level; }
  SPoint3 corner(const SizeOctant *o) const;
  void toInt(const SPoint3 &p, uint64_t out[3]) const;
  bool containsPoint(const SizeOctant *node, const uint64_t p[3]) const;
  int childIndexFor(const SizeOctant *node, const uint64_t p[3]) const;
  void collectFaceLeaves(SizeOctant *node, int faceDir,
                          std::vector<SizeOctant *> &out) const;

  SizeOctant *splitLeaf(SizeOctant *leaf);
  void balanceFrom(std::vector<SizeOctant *> worklist);
  void computeGradientOn(const std::vector<SizeOctant *> &region);
  bool limitGradientOn(const std::vector<SizeOctant *> &region, double alpha);
};

#endif
