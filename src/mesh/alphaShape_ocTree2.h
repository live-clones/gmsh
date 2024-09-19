#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <limits>
#include <ostream>
#include <unordered_map>
#include <vector>
#include "gmsh.h"

template<int dim>
using Coord = std::array<double, dim>;

template<int dim>
struct BBox {
  Coord<dim> min, max;
  BBox() {
    for (int i = 0; i < dim; i++) {
      min[i] = std::numeric_limits<double>::max();
      max[i] = std::numeric_limits<double>::lowest();
    }
  }
  void extends(const Coord<dim> point) {
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
    double center[2] = {(min[0]+max[0])*.5, (min[1]+max[1])*.5};
    min[0] -= center[0];
    min[1] -= center[1];
    max[0] -= center[0];
    max[1] -= center[1];
    min[0] *= scale;
    min[1] *= scale;
    max[0] *= scale;
    max[1] *= scale;
    min[0] += center[0];
    min[1] += center[1];
    max[0] += center[0];
    max[1] += center[1];
  }
};

template<int dim, int binsize, typename Object>
class OctreeNode {

  struct Leaf {
    Object objects[binsize];
    BBox<dim> bboxes[binsize];
    int n;
    Leaf(): n(0) {};
    void search(const BBox<dim> bbox, std::vector<Object> &result) {
      for (int i = 0; i < n; ++i) {
        if (bboxes[i].intersects(bbox)) {
          result.push_back(objects[i]);
          auto it = std::lower_bound(result.begin(), result.end(), objects[i]);
          if (it == result.end() || *it != objects[i]) {
            result.insert(it, objects[i]);
          }
        }
      }
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

  void add(Object obj, const BBox<dim> &bbox) {
    if (!bbox.intersects(bbox_)) {
      return;
    }
    if (leaf_) {
      if (leaf_->n < binsize) {
        leaf_->objects[leaf_->n] = obj;
        leaf_->bboxes[leaf_->n++] = bbox;
        return;
      }
      else { // split
        Coord<dim> mid;
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
          for (int j = 0; j < leaf_->n; j++) {
            children_[i].add(leaf_->objects[j], leaf_->bboxes[j]);
          }
        }
        delete leaf_;
        leaf_ = nullptr;
      }
    }
    for (int i = 0; i < 1<<dim; i++) {
      children_[i].add(obj, bbox);
    }
  }
};
