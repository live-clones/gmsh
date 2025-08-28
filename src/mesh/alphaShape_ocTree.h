#ifndef ALPHA_SHAPE_OCTREE_H
#define ALPHA_SHAPE_OCTREE_H

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <limits>
#include <ostream>
#include <unordered_map>
#include <vector>
// #include "gmsh.h"

template<int dim>
using _Coord = std::array<double, dim>;

template<int dim>
struct BBox {
  _Coord<dim> min, max;
  BBox() {
    for (int i = 0; i < dim; i++) {
      min[i] = std::numeric_limits<double>::max();
      max[i] = std::numeric_limits<double>::lowest();
    }
  }
  void extends(const _Coord<dim> point) {
    for (int i = 0; i < dim; i++) {
      min[i] = std::min(min[i], point[i]);
      max[i] = std::max(max[i], point[i]);
    }
  }
  bool intersects(const BBox &other) const {
    for (int i = 0; i < dim; i++) {
      if (min[i] > other.max[i] || max[i] < other.min[i]) {
        return false;
      }
    }
    return true;
  }

  void operator*=(double scale)
  {
    double center[dim];
    for (int i=0; i<dim; i++) center[i] = (min[i]+max[i])*.5;
    for (int i=0; i<dim; i++) {
      min[i] -= center[i];
      max[i] -= center[i];
      min[i] *= scale;
      max[i] *= scale;
      min[i] += center[i];
      max[i] += center[i];
    }
  }
};

template<int dim, int binsize, typename Object, int max_recursion_level=15>
class OctreeNode {

  struct Leaf {
    private:
    std::vector<std::pair<Object, BBox<dim>>> contents;
    public:
    Leaf() {contents.reserve(binsize);};

    void add(Object obj, const BBox<dim> &bbox) {
      contents.push_back(std::make_pair(obj, bbox));
    }

    void search(const BBox<dim> bbox_search, std::vector<Object> &result) {
      for (auto &it : contents) {
        auto obj = it.first;
        auto bbox = it.second;
        if (bbox.intersects(bbox_search)) {
          auto it = std::lower_bound(result.begin(), result.end(), obj);
          if (it == result.end() || *it != obj) {
            result.insert(it, obj);
          }
        }
      }
    }

    std::pair<Object, BBox<dim>> operator[](int i) const {
      return contents[i];
    }

    size_t n() const {
      return contents.size();
    }
  };


  Leaf *leaf_;
  OctreeNode *children_;


  public:
  BBox<dim> bbox_;
  void set_bbox(BBox<dim> bbox) {
    bbox_ = bbox;
  }
  OctreeNode(BBox<dim> bbox) : leaf_(new Leaf), children_(nullptr) { set_bbox(bbox);}
  OctreeNode() :leaf_(new Leaf), children_(nullptr) {}
  ~OctreeNode() {
    if (leaf_) delete leaf_;
    if (children_)delete[] children_;
  }
  void reset()
  {
    if (leaf_) delete leaf_;
    if (children_) delete[] children_;
  }

  void search(const BBox<dim> bbox, std::vector<Object> &result) {
    if (children_) {
      for (int i = 0; i < 1<<dim; i++) {
        if (bbox.intersects(children_[i].bbox_)) {
          children_[i].search(bbox, result);
        }
      }
    }
    else {
      leaf_->search(bbox, result);
    }
  }

  void add(Object obj, const BBox<dim> &bbox, int recursion = 0) {
    if (!bbox.intersects(bbox_)) {
      return;
    }
    if (leaf_) {
      if (leaf_->n() < binsize || recursion == max_recursion_level) {
        leaf_->add(obj, bbox);
        return;
      }
      else { // split
        _Coord<dim> mid;
        for (int i = 0; i < dim; i++) {
          mid[i] = (bbox_.min[i] + bbox_.max[i]) / 2;
        }
        children_ = new OctreeNode[1<<dim];
        for (int i = 0; i < 1<<dim; i++) {
          BBox<dim> bboxc;
          for (int j = 0; j < dim; j++) {
            bboxc.min[j] = (i & 1<<j) ? mid[j] : bbox_.min[j];
            bboxc.max[j] = (i & 1<<j) ? bbox_.max[j] : mid[j];
          }
          children_[i].set_bbox(bboxc);
          for (int j = 0; j < leaf_->n(); j++) {
            auto pair = (*leaf_)[j];
            children_[i].add(pair.first, pair.second, recursion+1);
          }
        }
        delete leaf_;
        leaf_ = nullptr;
      }
    }
    for (int i = 0; i < 1<<dim; i++) {
      children_[i].add(obj, bbox, recursion+1);
    }
  }
};

# endif // ALPHA_SHAPE_OCTREE_H