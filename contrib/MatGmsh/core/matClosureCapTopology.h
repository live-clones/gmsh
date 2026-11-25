#pragma once

#include <array>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace matClosureCapTopology {
using Point = std::array<double, 3>;
using Edge = std::pair<int, int>;

struct Polygon {
  std::vector<int> vertices;
  Point center{};
};

struct DiskContacts {
  std::set<Edge> edges;
  std::set<int> vertices;
  std::set<int> boundaryVertices;
};

// Certificates against one retained snapshot are not independent when two
// disks share an edge or touch through either disk's interior. Reject every
// member of such a conflict before committing any restoration.
std::set<int> conflictingDisks(const std::map<int, DiskContacts> &disks);

// The patch consists of existing MAT polygons, without moving any vertex.
// Every boundary edge must have exactly one retained neighbor across it;
// interior edges and vertices must not touch another retained sheet.
// Also require an orientable disk with manifold vertex links and at most
// 60 degrees of local bending across every patch/neighbor edge.
bool isSewnDisk(
    const std::vector<Polygon> &polygons,
    const std::map<int, Point> &points,
    const std::map<Edge, std::vector<Point>> &retainedCentersByEdge,
    const std::set<int> &retainedVertices,
    std::vector<int> *boundaryVertices = nullptr);
}
