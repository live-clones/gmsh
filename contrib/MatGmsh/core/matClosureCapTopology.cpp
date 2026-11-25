#include "matClosureCapTopology.h"

#include <algorithm>
#include <cmath>
#include <queue>

namespace matClosureCapTopology {
namespace {
Point subtract(const Point &a, const Point &b)
{ return {a[0]-b[0], a[1]-b[1], a[2]-b[2]}; }
Point cross(const Point &a, const Point &b)
{ return {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]}; }
double dot(const Point &a, const Point &b)
{ return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
bool finite(const Point &p)
{ return std::isfinite(p[0]) && std::isfinite(p[1]) && std::isfinite(p[2]); }
bool connected(const std::map<int, std::vector<int>> &graph)
{
  if(graph.empty()) return false;
  std::set<int> visited;
  std::vector<int> pending{graph.begin()->first};
  while(!pending.empty()) {
    const int v = pending.back();
    pending.pop_back();
    if(!visited.insert(v).second) continue;
    const auto neighbors = graph.find(v);
    if(neighbors == graph.end()) return false;
    pending.insert(pending.end(), neighbors->second.begin(), neighbors->second.end());
  }
  return visited.size() == graph.size();
}
}

std::set<int> conflictingDisks(const std::map<int, DiskContacts> &disks)
{
  std::set<int> conflicts;
  std::map<Edge, int> edgeOwner;
  std::map<int, std::vector<std::pair<int, bool>>> vertexOwners;
  for(const auto &disk : disks) {
    for(const Edge &edge : disk.second.edges) {
      const auto inserted = edgeOwner.emplace(edge, disk.first);
      if(!inserted.second) {
        conflicts.insert(inserted.first->second);
        conflicts.insert(disk.first);
      }
    }
    for(int vertex : disk.second.vertices) {
      const bool onBoundary = disk.second.boundaryVertices.count(vertex) != 0;
      auto &owners = vertexOwners[vertex];
      for(const auto &owner : owners)
        if(!onBoundary || !owner.second) {
          conflicts.insert(owner.first);
          conflicts.insert(disk.first);
        }
      owners.emplace_back(disk.first, onBoundary);
    }
  }
  return conflicts;
}

bool isSewnDisk(const std::vector<Polygon> &polygons,
               const std::map<int, Point> &points,
               const std::map<Edge, std::vector<Point>> &retainedCentersByEdge,
               const std::set<int> &retainedVertices,
               std::vector<int> *boundaryVertices)
{
  if(boundaryVertices) boundaryVertices->clear();
  if(polygons.empty()) return false;
  struct Use { std::size_t face; int direction; };
  std::map<Edge, std::vector<Use>> edges;
  std::set<int> vertices;
  std::map<int, std::map<int, std::vector<int>>> links;
  for(std::size_t f = 0; f < polygons.size(); ++f) {
    const auto &polygon = polygons[f];
    const auto &v = polygon.vertices;
    if(v.size() < 3 || !finite(polygon.center)) return false;
    std::set<int> unique;
    for(std::size_t i = 0; i < v.size(); ++i) {
      const int a = v[i], b = v[(i+1)%v.size()], previous = v[(i+v.size()-1)%v.size()];
      const auto p = points.find(a);
      if(p == points.end() || !finite(p->second) || !unique.insert(a).second)
        return false;
      vertices.insert(a);
      edges[std::minmax(a, b)].push_back({f, a < b ? 1 : -1});
      links[a][previous].push_back(b);
      links[a][b].push_back(previous);
    }
  }
  if(vertices.size() + polygons.size() != edges.size() + 1) return false;
  const auto oppositeSides = [&](const Edge &edge, const Point &a, const Point &b) {
    if(!finite(a) || !finite(b)) return false;
    const Point origin = points.at(edge.first);
    const Point direction = subtract(points.at(edge.second), origin);
    const Point first = cross(direction, subtract(a, origin));
    const Point second = cross(direction, subtract(b, origin));
    const double scale = std::sqrt(dot(first, first) * dot(second, second));
    return std::isfinite(scale) && scale > 0.0 && dot(first, second) <= -0.5 * scale;
  };
  std::map<int, std::vector<int>> boundary;
  std::vector<std::vector<std::pair<std::size_t, int>>> adjacency(polygons.size());
  for(const auto &entry : edges) {
    const auto retained = retainedCentersByEdge.find(entry.first);
    const std::size_t count = retained == retainedCentersByEdge.end() ? 0 : retained->second.size();
    const auto &uses = entry.second;
    if(uses.size() == 1) {
      if(count != 1 || !oppositeSides(entry.first, polygons[uses[0].face].center,
                                      retained->second.front())) return false;
      boundary[entry.first.first].push_back(entry.first.second);
      boundary[entry.first.second].push_back(entry.first.first);
    }
    else if(uses.size() == 2) {
      if(count != 0 || uses[0].face == uses[1].face ||
         !oppositeSides(entry.first, polygons[uses[0].face].center,
                        polygons[uses[1].face].center)) return false;
      const int orientation = -uses[0].direction * uses[1].direction;
      adjacency[uses[0].face].push_back({uses[1].face, orientation});
      adjacency[uses[1].face].push_back({uses[0].face, orientation});
    }
    else return false;
  }
  if(boundary.size() < 3 || !connected(boundary)) return false;
  for(const auto &vertex : boundary)
    if(vertex.second.size() != 2) return false;
  for(int vertex : vertices) {
    const bool onBoundary = boundary.count(vertex) != 0;
    if(!onBoundary && retainedVertices.count(vertex)) return false;
    const auto &link = links.at(vertex);
    if(!connected(link)) return false;
    int ends = 0;
    for(const auto &node : link) {
      if(node.second.size() == 1) ++ends;
      else if(node.second.size() != 2) return false;
    }
    if(ends != (onBoundary ? 2 : 0)) return false;
  }
  std::vector<int> orientation(polygons.size(), 0);
  orientation[0] = 1;
  std::vector<std::size_t> pending{0};
  std::size_t visited = 0;
  while(!pending.empty()) {
    const std::size_t face = pending.back();
    pending.pop_back();
    ++visited;
    for(const auto &neighbor : adjacency[face]) {
      const int expected = orientation[face] * neighbor.second;
      if(orientation[neighbor.first] != 0) {
        if(orientation[neighbor.first] != expected) return false;
      }
      else {
        orientation[neighbor.first] = expected;
        pending.push_back(neighbor.first);
      }
    }
  }
  if(visited != polygons.size()) return false;
  if(boundaryVertices)
    for(const auto &entry : boundary) boundaryVertices->push_back(entry.first);
  return true;
}
}
