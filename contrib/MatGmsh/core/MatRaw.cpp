// Extracted from MatGmsh for the native Gmsh MAT pipeline.
// See SOURCE_PROVENANCE.txt for the extraction boundary.
#include "matGmsh.h"
#include <gmsh.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <Eigen/Geometry>
#include "matCircumcenter.h"
#include "matSkinSites.h"
#include "matVoronoiVertexMerge.h"
#include "DiscreteCADWinding.h"
#include "GmshMessage.h"
void matGmsh::orientSurfaceTriangles()
{
  ScopedTimer timer(*this, "orientSurfaceTriangles");
  const int nt = del.triangles.size() / 3;

  if(nt == 0) {
    return;
  }
  if(del.tetrahedra.empty()) {
    throw std::runtime_error("orientSurfaceTriangles requires tetrahedra");
  }

  auto getTri = [&](int t){
    return std::array<int,3>{
      int(del.triangles[3*t+0]),
      int(del.triangles[3*t+1]),
      int(del.triangles[3*t+2])
    };
  };

  auto setTri = [&](int t, const std::array<int,3>& v){
    del.triangles[3*t+0] = v[0];
    del.triangles[3*t+1] = v[1];
    del.triangles[3*t+2] = v[2];
  };

  auto sortedTri = [&](const std::array<int,3> &v) {
    std::array<int,3> key = v;
    std::sort(key.begin(), key.end());
    return key;
  };

  auto orientTetPositive = [&](std::array<int,4> &tet) {
    const Eigen::Vector3d a(del.seeds[3*tet[0]+0], del.seeds[3*tet[0]+1], del.seeds[3*tet[0]+2]);
    const Eigen::Vector3d b(del.seeds[3*tet[1]+0], del.seeds[3*tet[1]+1], del.seeds[3*tet[1]+2]);
    const Eigen::Vector3d c(del.seeds[3*tet[2]+0], del.seeds[3*tet[2]+1], del.seeds[3*tet[2]+2]);
    const Eigen::Vector3d d(del.seeds[3*tet[3]+0], del.seeds[3*tet[3]+1], del.seeds[3*tet[3]+2]);
    const double vol6 = (b - a).cross(c - a).dot(d - a);
    if(vol6 < 0.0) std::swap(tet[0], tet[1]);
  };

  const std::size_t nv = del.seeds.size() / 3;
  for(int t = 0; t < nt; ++t)
    for(int k = 0; k < 3; ++k)
      if(del.triangles[3*t+k] >= nv)
        throw std::runtime_error("A skin triangle has an unknown vertex");

  // The triangles of each edge, in increasing order (a triangle that has the
  // edge twice is there twice): listed at the smaller vertex of the edge,
  // with the other one.
  std::vector<std::size_t> edgeStart(nv + 1, 0);
  for(int t = 0; t < nt; ++t) {
    const auto v = getTri(t);
    for(int k = 0; k < 3; ++k) ++edgeStart[std::min(v[k], v[(k+1)%3]) + 1];
  }
  for(std::size_t v = 0; v < nv; ++v) edgeStart[v + 1] += edgeStart[v];
  std::vector<std::pair<int,int>> edgeTriangles(edgeStart[nv]); // (other vertex, triangle)
  {
    std::vector<std::size_t> fill(edgeStart.begin(), edgeStart.end() - 1);
    for(int t = 0; t < nt; ++t) {
      const auto v = getTri(t);
      for(int k = 0; k < 3; ++k) {
        const int a = std::min(v[k], v[(k+1)%3]), b = std::max(v[k], v[(k+1)%3]);
        edgeTriangles[fill[a]++] = {b, t};
      }
    }
  }
  auto forTrianglesOf = [&](const matGmshEdge &e, const std::function<void(int)> &visit) {
    for(std::size_t i = edgeStart[e.a]; i < edgeStart[e.a + 1]; ++i)
      if(edgeTriangles[i].first == e.b) visit(edgeTriangles[i].second);
  };

  // The orientation of a skin triangle as the face of a positive
  // tetrahedron, the last one that has it: the triangles listed at their
  // smallest vertex, the faces of the tetrahedra looked for there.
  std::vector<std::size_t> faceStart(nv + 1, 0);
  for(int t = 0; t < nt; ++t) ++faceStart[sortedTri(getTri(t))[0] + 1];
  for(std::size_t v = 0; v < nv; ++v) faceStart[v + 1] += faceStart[v];
  std::vector<std::array<int,3>> skinFaces(faceStart[nv]); // (second, third, triangle)
  {
    std::vector<std::size_t> fill(faceStart.begin(), faceStart.end() - 1);
    for(int t = 0; t < nt; ++t) {
      const auto key = sortedTri(getTri(t));
      skinFaces[fill[key[0]]++] = {key[1], key[2], t};
    }
  }
  std::vector<std::array<int,3>> faceOrientation(nt);
  std::vector<unsigned char> isFace(nt, 0);
  const int nTet = static_cast<int>(del.tetrahedra.size() / 4);
  for(int t = 0; t < nTet; ++t) {
    std::array<int,4> tet = {
      int(del.tetrahedra[4*t+0]-1),
      int(del.tetrahedra[4*t+1]-1),
      int(del.tetrahedra[4*t+2]-1),
      int(del.tetrahedra[4*t+3]-1)
    };
    for(int k = 0; k < 4; ++k)
      if(tet[k] < 0 || std::size_t(tet[k]) >= nv)
        throw std::runtime_error("A tetrahedron has an unknown vertex");
    orientTetPositive(tet);

    const std::array<std::array<int,3>,4> faces = {{
      {tet[1], tet[2], tet[3]},
      {tet[0], tet[3], tet[2]},
      {tet[0], tet[1], tet[3]},
      {tet[0], tet[2], tet[1]}
    }};
    for(const auto &f : faces) {
      const auto key = sortedTri(f);
      for(std::size_t i = faceStart[key[0]]; i < faceStart[key[0] + 1]; ++i)
        if(skinFaces[i][0] == key[1] && skinFaces[i][1] == key[2]) {
          faceOrientation[skinFaces[i][2]] = f;
          isFace[skinFaces[i][2]] = 1;
        }
    }
  }

  std::vector<int> visited(nt,0);
  std::queue<int> Q;

  auto runBfsFromSeed = [&](int seed) {
    visited[seed] = 1;
    Q.push(seed);
    while(!Q.empty()){
      int t = Q.front(); Q.pop();
      auto v = getTri(t);

      std::array<matGmshEdge,3> edges = {
        matGmshEdge(v[0],v[1]),
        matGmshEdge(v[1],v[2]),
        matGmshEdge(v[2],v[0])
      };

      for(int e=0;e<3;++e){

        forTrianglesOf(edges[e], [&](int t2){

          if(t2 == t) return;
          if(visited[t2]) return;

          auto v2 = getTri(t2);

          int a = edges[e].a;
          int b = edges[e].b;

          int dir_t = 0;
          for(int i=0;i<3;++i){
            if(v[i]==a && v[(i+1)%3]==b) dir_t = +1;
            if(v[i]==b && v[(i+1)%3]==a) dir_t = -1;
          }

          int dir_t2 = 0;
          for(int i=0;i<3;++i){
            if(v2[i]==a && v2[(i+1)%3]==b) dir_t2 = +1;
            if(v2[i]==b && v2[(i+1)%3]==a) dir_t2 = -1;
          }

          if(dir_t == dir_t2){
            std::swap(v2[1], v2[2]);
            setTri(t2, v2);
          }

          visited[t2] = 1;
          Q.push(t2);
        });
      }
    }
  };

  // (a second pass would find nothing more: a triangle not visited here is
  // the face of no tetrahedron)
  for(int seed = 0; seed < nt; ++seed) {
    if(visited[seed]) continue;
    if(!isFace[seed]) continue;
    setTri(seed, faceOrientation[seed]);
    runBfsFromSeed(seed);
  }

  for(int t = 0; t < nt; ++t) {
    if(!visited[t]) {
      throw std::runtime_error("Could not orient all surface triangles from tetrahedra");
    }
  }
}

namespace {
std::map<matGmshEdge, std::vector<size_t > > buildEdgeToTet(
    const std::vector<size_t>& tets)
{
    std::map<matGmshEdge, std::vector<size_t > >edgeToTet;
    size_t nt = tets.size() / 4;

    for(size_t t = 0; t < nt; ++t) {

        int v[4] = {
            int(tets[4*t+0] - 1),
            int(tets[4*t+1] - 1),
            int(tets[4*t+2] - 1),
            int(tets[4*t+3] - 1)
        };

        int edges[6][2] = {
            {v[0], v[1]},
            {v[0], v[2]},
            {v[0], v[3]},
            {v[1], v[2]},
            {v[1], v[3]},
            {v[2], v[3]}
        };

        for(int k = 0; k < 6; ++k) {

            matGmshEdge e(edges[k][0], edges[k][1]);

	    edgeToTet[e].push_back(t);
        }
    }

    return edgeToTet;
}


struct EdgeHash {
    std::size_t operator()(const matGmshEdge& e) const {
        return std::hash<int>()(e.a) ^ (std::hash<int>()(e.b) << 1);
    }
};

// ------------------------------------------------------------

std::vector<int> orderTetsAroundEdge(
    int i, int j,
    const std::vector<size_t>& tets,
    const std::vector<size_t>& tetIds)
{
    std::unordered_map<int, std::vector<int>> adj;
    std::unordered_map<matGmshEdge, int, EdgeHash> edge2tet;

    // --- construire le graphe ---
    for(auto t : tetIds) {

        int v[4] = {
            int(tets[4*t+0]-1),
            int(tets[4*t+1]-1),
            int(tets[4*t+2]-1),
            int(tets[4*t+3]-1)
        };

        int a=-1, b=-1;
        for(int k=0;k<4;++k){
            if(v[k]!=i && v[k]!=j){
                if(a==-1) a=v[k];
                else b=v[k];
            }
        }

        adj[a].push_back(b);
        adj[b].push_back(a);

        edge2tet[matGmshEdge(a,b)] = (int)t;
    }

    // --- analyser les degrés ---
    int n_deg1 = 0;
    int start = -1;

    for(auto& [v, neigh] : adj) {
        if(neigh.size() == 1) {
            n_deg1++;
            start = v; // bon point de départ pour chaîne
        }
        else if(neigh.size() != 2) {
            throw std::runtime_error("Non-manifold edge");
        }
    }
    if(n_deg1 != 0 && n_deg1 != 2) {
        throw std::runtime_error(
            "Invalid tetrahedron link around Delaunay edge");
    }

    bool isClosed = (n_deg1 == 0);

    if(start == -1)
        start = adj.begin()->first; // cycle

    // --- parcours ---
    std::vector<int> ordered;
    int prev = -1;
    int curr = start;

    while(true) {

        auto& neigh = adj[curr];

        int next = -1;
        for(int n : neigh)
            if(n != prev)
                next = n;

        if(next == -1) break;

        matGmshEdge e(curr, next);

        auto it = edge2tet.find(e);
        if(it == edge2tet.end())
            throw std::runtime_error("Edge not found");

        ordered.push_back(it->second);

        prev = curr;
        curr = next;

        if(curr == start) break; // cycle
    }
    if(ordered.size() != tetIds.size()) {
        throw std::runtime_error(
            "Disconnected tetrahedron link around Delaunay edge");
    }

    // --- ajouter -1 si ouvert ---
    if(!isClosed) {
        std::vector<int> out;
        out.reserve(ordered.size() + 2);

        out.push_back(-1);
        out.insert(out.end(), ordered.begin(), ordered.end());
        out.push_back(-1);

        return out;
    }

    return ordered;
}

static void canonicalizeTetrahedra(std::vector<size_t> &tetrahedra)
{
  static const std::vector<std::array<int, 4>> evenPermutations = [] {
    std::vector<std::array<int, 4>> result;
    std::array<int, 4> p = {0, 1, 2, 3};
    do {
      int inversions = 0;
      for(int i = 0; i < 4; ++i)
        for(int j = i + 1; j < 4; ++j)
          if(p[i] > p[j]) ++inversions;
      if(inversions % 2 == 0) result.push_back(p);
    } while(std::next_permutation(p.begin(), p.end()));
    return result;
  }();
  const std::size_t count = tetrahedra.size() / 4;
  std::vector<std::array<size_t, 4>> tets(count);
  for(std::size_t t = 0; t < count; ++t) {
    const size_t *v = &tetrahedra[4 * t];
    std::array<size_t, 4> best = {v[0], v[1], v[2], v[3]};
    for(const auto &p : evenPermutations) {
      const std::array<size_t, 4> candidate = {v[p[0]], v[p[1]], v[p[2]],
                                               v[p[3]]};
      if(candidate < best) best = candidate;
    }
    tets[t] = best;
  }
  std::sort(tets.begin(), tets.end());
  for(std::size_t t = 0; t < count; ++t)
    for(int i = 0; i < 4; ++i) tetrahedra[4 * t + i] = tets[t][i];
}
}
void matGmsh::computeVoronoiVertices(const std::vector<unsigned char> *only)
{
    ScopedTimer timer(*this, "computeVoronoiVertices");
    vor.vertices.clear();

    const std::vector<double> &pts = del.seeds;
    const std::vector<size_t> &tets = del.tetrahedra;

    size_t nt = tets.size() / 4;
    if(only && only->size() != nt)
      throw std::runtime_error("One flag per tetrahedron is expected for the circumcentres");

    vor.vertices.reserve(3 * nt);
    std::size_t negativeDeterminants = 0;
    std::size_t smallAbsoluteDeterminants = 0;
    std::size_t barycenterFallbacks = 0;
    std::size_t exactCircumcenters = 0;
    std::size_t computed = 0;

    for(size_t t = 0; t < nt; ++t) {
        if(only && !(*only)[t]) {
          const double none = std::numeric_limits<double>::quiet_NaN();
          vor.vertices.insert(vor.vertices.end(), {none, none, none});
          continue;
        }
        ++computed;

        int i0 = tets[4*t + 0] - 1;
        int i1 = tets[4*t + 1] - 1;
        int i2 = tets[4*t + 2] - 1;
        int i3 = tets[4*t + 3] - 1;

        const double *a = &pts[3*i0];
        const double *b = &pts[3*i1];
        const double *c = &pts[3*i2];
        const double *d = &pts[3*i3];

        matgmsh::circumcenter::Result center;
        try {
          center = matgmsh::circumcenter::compute(a, b, c, d);
        }
        catch(const std::exception &error) {
          throw std::runtime_error("Tetrahedron " + std::to_string(t) +
                                   ": " + error.what());
        }
        const auto &cc = center.center;
        const double determinant = center.determinant;
        if(center.status == matgmsh::circumcenter::Status::Degenerate)
          ++barycenterFallbacks;
        else if(center.status == matgmsh::circumcenter::Status::Exact)
          ++exactCircumcenters;
        if(determinant < 0.0) ++negativeDeterminants;
        if(std::abs(determinant) < 1.e-12)
          ++smallAbsoluteDeterminants;

        vor.vertices.push_back(cc[0]);
        vor.vertices.push_back(cc[1]);
        vor.vertices.push_back(cc[2]);
    }
    Msg::Info("Circumcenter diagnostics: tetrahedra=%zu computed=%zu negativeDeterminants=%zu "
              "smallAbsoluteDeterminants=%zu exactFallbacks=%zu "
              "certifiedDouble=%zu barycenterFallbacks=%zu",
              nt, computed, negativeDeterminants, smallAbsoluteDeterminants,
              exactCircumcenters, computed - exactCircumcenters - barycenterFallbacks,
              barycenterFallbacks);
}

void matGmsh::createVoronoiSeeds() {
  ScopedTimer timer(*this, "createVoronoiSeeds");
  del.nodeTags.clear();
  del.seeds.clear();
  del.onWhat.clear();
  del.seedFaces.clear();
  del.triangles.clear();
  del.tetrahedra.clear();

  if(!voronoiSurfaceMeshInput.empty()) {
    std::ifstream input(voronoiSurfaceMeshInput);
    if(!input)
      throw std::runtime_error(
          "Could not open external Voronoi surface mesh " +
          voronoiSurfaceMeshInput);
    std::map<std::size_t, unsigned int> tagToIndex;
    std::string token;
    while(input >> token) {
      if(token == "$Nodes") {
        std::size_t nodeCount = 0;
        input >> nodeCount;
        del.nodeTags.reserve(nodeCount);
        del.seeds.reserve(3 * nodeCount);
        for(std::size_t i = 0; i < nodeCount; ++i) {
          std::size_t tag = 0;
          double x = 0.0, y = 0.0, z = 0.0;
          input >> tag >> x >> y >> z;
          tagToIndex[tag] = static_cast<unsigned int>(del.nodeTags.size());
          del.nodeTags.push_back(tag);
          del.seeds.insert(del.seeds.end(), {x, y, z});
        }
      }
      else if(token == "$Elements") {
        std::size_t elementCount = 0;
        input >> elementCount;
        std::string line;
        std::getline(input, line);
        for(std::size_t i = 0; i < elementCount; ++i) {
          std::getline(input, line);
          std::istringstream element(line);
          std::size_t elementTag = 0;
          int elementType = 0, numberOfTags = 0;
          element >> elementTag >> elementType >> numberOfTags;
          for(int tag = 0; tag < numberOfTags; ++tag) {
            int ignored = 0;
            element >> ignored;
          }
          if(elementType != 2) continue;
          std::size_t a = 0, b = 0, c = 0;
          element >> a >> b >> c;
          const auto ia = tagToIndex.find(a);
          const auto ib = tagToIndex.find(b);
          const auto ic = tagToIndex.find(c);
          if(ia == tagToIndex.end() || ib == tagToIndex.end() ||
             ic == tagToIndex.end())
            throw std::runtime_error(
                "External Voronoi surface mesh contains an unknown node tag");
          del.triangles.push_back(ia->second);
          del.triangles.push_back(ib->second);
          del.triangles.push_back(ic->second);
        }
      }
    }
    if(del.nodeTags.empty() || del.triangles.empty())
      throw std::runtime_error(
          "External Voronoi surface mesh has no nodes or triangles");
    del.seedFaces.resize(del.nodeTags.size());
    Msg::Info("External Voronoi surface mesh: nodes=%zu triangles=%zu file=%s",
              del.nodeTags.size(), del.triangles.size() / 3,
              voronoiSurfaceMeshInput.c_str());
    return;
  }

  // --- récupérer les noeuds ---
  std::vector<std::size_t> nodeTags;
  std::vector<double> coords, parametric;

  gmsh::model::mesh::getNodes(nodeTags, coords, parametric);

  std::map<std::size_t, unsigned int> tagToIndex;

  for(size_t i = 0; i < nodeTags.size(); ++i) {
    tagToIndex[nodeTags[i]] = static_cast<unsigned int>(i);
    del.nodeTags.push_back(nodeTags[i]);
    del.seeds.push_back(coords[3*i + 0]);
    del.seeds.push_back(coords[3*i + 1]);
    del.seeds.push_back(coords[3*i + 2]);
  }

  del.seedFaces.resize(nodeTags.size());
  auto collectAdjacentFaces = [&](int dim, int tag) {
    std::set<int> faces;
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited;
    q.push({dim, tag});
    visited.insert({dim, tag});

    while(!q.empty()) {
      const auto current = q.front();
      q.pop();

      if(current.first == 2) {
        faces.insert(current.second);
        continue;
      }

      std::vector<int> upward, downward;
      gmsh::model::getAdjacencies(current.first, current.second, upward, downward);

      for(int upTag : upward) {
        const std::pair<int, int> upEntity{current.first + 1, upTag};
        if(visited.insert(upEntity).second) {
          q.push(upEntity);
        }
      }
    }

    return std::vector<int>(faces.begin(), faces.end());
  };

  for(size_t i = 0; i < nodeTags.size(); ++i) {
    std::vector<double> nodeCoord, nodeParametric;
    int entityDim = -1, entityTag = -1;
    gmsh::model::mesh::getNode(
        nodeTags[i], nodeCoord, nodeParametric, entityDim, entityTag);

    if(entityDim >= 0 && entityTag >= 0) {
      del.seedFaces[i] = collectAdjacentFaces(entityDim, entityTag);
    }
    del.onWhat.push_back({entityDim, entityTag});
  }

  // --- récupérer les éléments ---
  std::vector<int> elemTypes;
  std::vector<std::vector<std::size_t>> elemTags, elemNodeTags;
  gmsh::model::mesh::getElements(elemTypes, elemTags, elemNodeTags);

  for(size_t t = 0; t < elemTypes.size(); ++t) {
    int type = elemTypes[t];
    if(type == 2) {
      const auto &conn = elemNodeTags[t];
      for(size_t i = 0; i < conn.size(); ++i) {
        // operator[] would silently map an unknown tag to the first site.
        const auto index = tagToIndex.find(conn[i]);
        if(index == tagToIndex.end())
          throw std::runtime_error(
              "A skin triangle uses node " + std::to_string(conn[i]) +
              ", which is not a node of the model");
        del.triangles.push_back(index->second);
      }
    }
  }
}
bool matGmsh::voronoiVertexIsInterior(
    std::size_t vertex, double windingThreshold) const
{
  return vertex < vor.winding.size() &&
         std::abs(vor.winding[vertex]) >= windingThreshold;
}
void matGmsh::colorVoronoiFaces(double threshold)
{
  ScopedTimer timer(*this, "colorVoronoiFaces");
  const int nf = vor.faces.size();

  vor.faceColors.assign(nf, -1);

  // =========================
  // 1. filtrage faces internes
  // =========================
  std::vector<char> isInternal(nf, 1);

  for(int f = 0; f < nf; ++f) {
    const auto& face = vor.faces[f];
    if(face.verts.empty()) {
      isInternal[f] = 0;
      continue;
    }

    for(int v : face.verts) {
      if(v < 0 ||
         !voronoiVertexIsInterior(
             static_cast<std::size_t>(v), threshold)) {
        isInternal[f] = 0;
        break;
      }
    }
  }

  colorSelectedVoronoiFaces(isInternal);
}

void matGmsh::colorSelectedVoronoiFaces(std::vector<char> &isInternal)
{
  const int nf = vor.faces.size();
  if(isInternal.size() != vor.faces.size())
    throw std::runtime_error("One selection flag per Voronoi face is expected");
  vor.faceColors.assign(nf, -1);

  // Distinct Delaunay tetrahedra can have numerically identical
  // circumcentres.  Merge only endpoints of actual edges of the interior MAT
  // polygons: a global coordinate weld could join unrelated sheets that
  // merely cross in space.  Classification above deliberately uses the
  // original tetrahedron ids; only the subsequent MAT connectivity changes.
  std::array<double, 3> minimum = {
      std::numeric_limits<double>::infinity(),
      std::numeric_limits<double>::infinity(),
      std::numeric_limits<double>::infinity()};
  std::array<double, 3> maximum = {
      -std::numeric_limits<double>::infinity(),
      -std::numeric_limits<double>::infinity(),
      -std::numeric_limits<double>::infinity()};
  for(std::size_t vertex = 0; vertex + 2 < del.seeds.size(); vertex += 3) {
    for(int coordinate = 0; coordinate < 3; ++coordinate) {
      minimum[coordinate] =
          std::min(minimum[coordinate], del.seeds[vertex + coordinate]);
      maximum[coordinate] =
          std::max(maximum[coordinate], del.seeds[vertex + coordinate]);
    }
  }
  double referenceLength = 0.0;
  if(!del.seeds.empty()) {
    const double dx = maximum[0] - minimum[0];
    const double dy = maximum[1] - minimum[1];
    const double dz = maximum[2] - minimum[2];
    referenceLength = std::sqrt(dx * dx + dy * dy + dz * dz);
  }
  matVoronoiVertexMerge::AdjacentVertexMerger merger(
      vor.vertices, referenceLength, 1.e-12);
  for(int f = 0; f < nf; ++f) {
    if(!isInternal[f]) continue;
    const std::vector<int> &vertices = vor.faces[f].verts;
    for(std::size_t i = 0; i < vertices.size(); ++i)
      merger.considerEdge(vertices[i], vertices[(i + 1) % vertices.size()]);
  }
  std::size_t removedFaceVertices = 0;
  std::size_t degenerateFaces = 0;
  for(int f = 0; f < nf; ++f) {
    if(!isInternal[f]) continue;
    removedFaceVertices += matVoronoiVertexMerge::canonicalizeClosedFace(
        vor.faces[f].verts, merger);
    if(vor.faces[f].verts.size() < 3) {
      isInternal[f] = 0;
      ++degenerateFaces;
    }
  }
  const auto &mergeStatistics = merger.statistics();
  Msg::Info("MAT Voronoi vertex merge: relativeTolerance=1e-12 "
            "referenceLength=%g absoluteTolerance=%g shortEdges=%zu "
            "mergedVertices=%zu removedFaceVertices=%zu degenerateFaces=%zu",
            referenceLength, mergeStatistics.absoluteTolerance,
            mergeStatistics.shortEdgeCount, mergeStatistics.mergedVertexCount,
            removedFaceVertices, degenerateFaces);

  // =========================
  // 2. the faces around each edge
  // =========================
  // Each side of a selected face is a slot. The slots are listed at the
  // smaller vertex of their edge, sorted by the other vertex and then by
  // slot: an edge is a run of slots there, its faces in increasing order, as
  // many as its valence (a face that has an edge twice counts twice).
  const std::size_t nv = vor.vertices.size() / 3;
  std::vector<std::size_t> firstSlot(nf + 1, 0);
  for(int f = 0; f < nf; ++f)
    firstSlot[f + 1] = firstSlot[f] + (isInternal[f] ? vor.faces[f].verts.size() : 0);
  const std::size_t slots = firstSlot[nf];
  std::vector<int> slotFace(slots, -1);
  std::vector<std::size_t> start(nv + 1, 0);
  const auto ends = [&](int f, std::size_t i, int &v0, int &v1) {
    const std::vector<int> &verts = vor.faces[f].verts;
    v0 = verts[i];
    v1 = verts[(i + 1) % verts.size()];
    if(v0 < 0 || v1 < 0) return false;
    if(std::size_t(v0) >= nv || std::size_t(v1) >= nv)
      throw std::runtime_error("A Voronoi face has an unknown vertex");
    if(v0 > v1) std::swap(v0, v1);
    return true;
  };
  for(int f = 0; f < nf; ++f) {
    if(!isInternal[f]) continue;
    for(std::size_t i = 0; i < vor.faces[f].verts.size(); ++i) {
      int v0, v1;
      slotFace[firstSlot[f] + i] = f;
      if(ends(f, i, v0, v1)) ++start[v0 + 1];
    }
  }
  for(std::size_t v = 0; v < nv; ++v) start[v + 1] += start[v];
  // (other vertex, slot) at the smaller vertex
  std::vector<std::pair<int, std::size_t>> around(start[nv]);
  {
    std::vector<std::size_t> fill(start.begin(), start.end() - 1);
    for(int f = 0; f < nf; ++f) {
      if(!isInternal[f]) continue;
      for(std::size_t i = 0; i < vor.faces[f].verts.size(); ++i) {
        int v0, v1;
        if(ends(f, i, v0, v1)) around[fill[v0]++] = {v1, firstSlot[f] + i};
      }
    }
  }
  // the run of its edge for each slot (none for a side without an end)
  std::vector<std::size_t> runOf(slots, std::numeric_limits<std::size_t>::max());
  std::vector<std::size_t> runStart(1, 0);
  for(std::size_t v = 0; v < nv; ++v) {
    std::sort(around.begin() + start[v], around.begin() + start[v + 1]);
    for(std::size_t i = start[v]; i < start[v + 1];) {
      std::size_t j = i;
      for(; j < start[v + 1] && around[j].first == around[i].first; ++j)
        runOf[around[j].second] = runStart.size() - 1;
      runStart.push_back(j);
      i = j;
    }
  }

  // =========================
  // 3. BFS sur les faces
  // =========================
  // across the edges of valence 2 only
  int currentColor = 0;

  for(int f0 = 0; f0 < nf; ++f0) {

    if(!isInternal[f0]) continue;
    if(vor.faceColors[f0] != -1) continue;

    std::queue<int> Q;
    Q.push(f0);
    vor.faceColors[f0] = currentColor;

    while(!Q.empty()) {
      int f = Q.front(); Q.pop();
      for(std::size_t s = firstSlot[f]; s < firstSlot[f + 1]; ++s) {
        const std::size_t run = runOf[s];
        if(run == std::numeric_limits<std::size_t>::max()) continue;
        if(runStart[run + 1] - runStart[run] != 2) continue;
        for(std::size_t k = runStart[run]; k < runStart[run + 1]; ++k) {
          const int f2 = slotFace[around[k].second];
          if(vor.faceColors[f2] == -1) {
            vor.faceColors[f2] = currentColor;
            Q.push(f2);
          }
        }
      }
    }
    currentColor++;
  }

}
void matGmsh::computeVoronoi(bool dualFaces, bool circumcentres)
{
  ScopedTimer timer(*this, "computeVoronoi");
  vor.vertices.clear();
  vor.faces.clear();
  vor.winding.clear();
  vor.windingAtCircumcenters = false;
  vor.faceColors.clear();

  createVoronoiSeeds();

  // Only the nodes of the skin triangles are sites (see matSkinSites.h).
  del.unreferencedNodeTags = matgmsh::skinSites::restrictToTriangles(
      del.seeds, del.nodeTags, del.onWhat, del.seedFaces, del.triangles);
  if(del.triangles.empty())
    throw std::runtime_error("The MAT needs a triangulated skin");
  if(!del.unreferencedNodeTags.empty())
    Msg::Info("MAT sites: ignored %zu nodes used by no skin triangle; sites=%zu",
              del.unreferencedNodeTags.size(), del.nodeTags.size());

  std::vector<double> steiner;
  gmsh::option::setNumber("Mesh.RandomFactor3D", 0.0);
  gmsh::algorithm::tetrahedralize(del.seeds, del.tetrahedra, steiner);
  if(!steiner.empty()) {
    throw std::runtime_error(
        "Gmsh tetrahedralize introduced Steiner points; the "
        "tetrahedron-to-surface-seed correspondence is no longer valid");
  }
  canonicalizeTetrahedra(del.tetrahedra);
  orientSurfaceTriangles();
  if(circumcentres) computeVoronoiVertices();
  if(!dualFaces) {
    Msg::Info("Gmsh Delaunay: points=%zu tetrahedra=%zu", del.seeds.size() / 3,
              del.tetrahedra.size() / 4);
    return;
  }
  const auto edgeToTetrahedra = buildEdgeToTet(del.tetrahedra);
  vor.faces.reserve(edgeToTetrahedra.size());
  std::size_t invalidDelaunayEdgeLinks = 0;
  for(const auto &entry : edgeToTetrahedra) {
    try {
      std::vector<int> ordered = orderTetsAroundEdge(
          entry.first.a, entry.first.b, del.tetrahedra, entry.second);
      vor.faces.emplace_back(entry.first, ordered);
    }
    catch(const std::runtime_error &) {
      // The unconstrained Gmsh DT can contain almost-degenerate tetrahedra
      // whose combinatorial link around an edge is not a single chain/cycle.
      // Such an edge has no well-defined dual Voronoi polygon.
      // Omit only that polygon instead of aborting the complete
      // MAT construction.
      ++invalidDelaunayEdgeLinks;
    }
  }
  Msg::Info("Gmsh Delaunay: points=%zu tetrahedra=%zu voronoiFaces=%zu "
            "skippedInvalidEdgeLinks=%zu",
            del.seeds.size() / 3, del.tetrahedra.size() / 4, vor.faces.size(),
            invalidDelaunayEdgeLinks);
}

void matGmsh::computeVoronoiWindingNumbersAtCircumcenters(
    int order, float accuracyScale, bool useDoublePrecision)
{
  ScopedTimer timer(*this, "computeVoronoiWindingNumbersAtCircumcenters");
  if(order != 2) throw std::runtime_error("Native Gmsh winding currently uses order 2");
  if(!(accuracyScale > 0.f)) throw std::runtime_error("Invalid winding accuracy scale");
  if(del.seeds.empty() || del.seeds.size() % 3 || del.triangles.empty() ||
     del.triangles.size() % 3 || vor.vertices.size() % 3 ||
     del.tetrahedra.size() / 4 != vor.vertices.size() / 3)
    throw std::runtime_error("Invalid MAT winding input arrays");
  std::vector<std::array<double, 3>> xyz(del.seeds.size() / 3), queries(vor.vertices.size() / 3);
  std::vector<std::array<int, 3>> triangles(del.triangles.size() / 3);
  for(std::size_t i = 0; i < xyz.size(); ++i)
    for(int k = 0; k < 3; ++k) xyz[i][k] = del.seeds[3*i+k];
  for(std::size_t i = 0; i < queries.size(); ++i)
    for(int k = 0; k < 3; ++k) queries[i][k] = vor.vertices[3*i+k];
  for(std::size_t i = 0; i < triangles.size(); ++i)
    for(int k = 0; k < 3; ++k) triangles[i][k] = static_cast<int>(del.triangles[3*i+k]);
  DiscreteCADWinding winding(xyz, triangles, accuracyScale);
  vor.winding.resize(queries.size());
  if(useDoublePrecision) {
    for(std::size_t i = 0; i < queries.size(); ++i)
      vor.winding[i] = winding.exact(queries[i].data());
  }
  else {
    double configuredThreads = 0.;
    gmsh::option::getNumber("General.NumThreads", configuredThreads);
    const unsigned maxThreads = std::isfinite(configuredThreads) && configuredThreads >= 1. ?
      static_cast<unsigned>(std::min(configuredThreads,
        static_cast<double>(std::numeric_limits<unsigned>::max()))) : 0u;
    winding.evaluate(queries, vor.winding, maxThreads);
    // Ambiguous fast evaluations receive the full double solid-angle sum.
    // This is not an exact-arithmetic classification certificate.
    for(std::size_t i = 0; i < queries.size(); ++i)
      if(std::abs(std::abs(vor.winding[i]) - .5) < 1.e-3)
        vor.winding[i] = winding.exact(queries[i].data());
  }
  vor.windingAtCircumcenters = true;
}
