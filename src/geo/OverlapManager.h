// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Boris Martin

#ifndef OVERLAP_MANAGER_H
#define OVERLAP_MANAGER_H

#include <tuple>
#include <unordered_map>
#include <vector>

class overlapFace;
class overlapRegion;
class partitionEdge;
class partitionFace;
class GFace;
class GRegion;
class GEdge;

class OverlapManager {
private:
  int _tag;
  int _layers;

  std::tuple<std::vector<overlapFace *>, std::vector<overlapRegion *>>
    _overlaps;

  std::unordered_map<GFace *, std::vector<partitionEdge *>>
    _overlapInnerBoundaries2D;
  std::unordered_map<GRegion *, std::vector<partitionFace *>>
    _overlapInnerBoundaries3D;
  std::unordered_map<GEdge *, std::vector<partitionEdge *>>
    _overlapOfBoundaries2D;
  std::unordered_map<GFace *, std::vector<partitionFace *>>
    _overlapOfBoundaries3D;
  std::tuple<std::unordered_map<partitionEdge *, GFace *>,
             std::unordered_map<partitionFace *, GRegion *>>
    _boundaryOfOverlapCreators;

public:
  OverlapManager(int tag, int layers) : _tag(tag), _layers(layers) {}

  int tag() const { return _tag; }
  int layers() const { return _layers; }

  int overlapDim() const
  {
    if(std::get<1>(_overlaps).size() > 0) { return 3; }
    else if(std::get<0>(_overlaps).size() > 0) {
      return 2;
    }
    return 0;
  }

  void addOverlap(overlapFace *of) { std::get<0>(_overlaps).push_back(of); }
  void addOverlap(overlapRegion *or_) { std::get<1>(_overlaps).push_back(or_); }

  const std::tuple<std::vector<overlapFace *>, std::vector<overlapRegion *>> &
  getAllOverlaps() const
  {
    return _overlaps;
  }

  void addInnerBoundary(GFace *f, partitionEdge *e)
  {
    _overlapInnerBoundaries2D[f].push_back(e);
  }
  void addInnerBoundary(GRegion *r, partitionFace *f)
  {
    _overlapInnerBoundaries3D[r].push_back(f);
  }

  void addOverlapOfBoundary(GEdge *e, partitionEdge *pe, GFace *parent)
  {
    _overlapOfBoundaries2D[e].push_back(pe);
    std::get<0>(_boundaryOfOverlapCreators)[pe] = parent;
  }
  void addOverlapOfBoundary(GFace *f, partitionFace *pf, GRegion *parent)
  {
    _overlapOfBoundaries3D[f].push_back(pf);
    std::get<1>(_boundaryOfOverlapCreators)[pf] = parent;
  }

  const auto &getOverlapInnerBoundaries2D() const
  {
    return _overlapInnerBoundaries2D;
  }
  const auto &getOverlapInnerBoundaries3D() const
  {
    return _overlapInnerBoundaries3D;
  }
  const auto &getOverlapOfBoundaries2D() const
  {
    return _overlapOfBoundaries2D;
  }
  const auto &getOverlapOfBoundaries3D() const
  {
    return _overlapOfBoundaries3D;
  }
  const auto &getBoundaryOfOverlapCreators() const
  {
    return _boundaryOfOverlapCreators;
  }

  void clear()
  {
    std::get<0>(_overlaps).clear();
    std::get<1>(_overlaps).clear();
    _overlapInnerBoundaries2D.clear();
    _overlapInnerBoundaries3D.clear();
    _overlapOfBoundaries2D.clear();
    _overlapOfBoundaries3D.clear();
    std::get<0>(_boundaryOfOverlapCreators).clear();
    std::get<1>(_boundaryOfOverlapCreators).clear();
  }
};

#endif
