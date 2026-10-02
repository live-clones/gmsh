#include "halfEdgeMesh.h"
#include "halfEdgeRewriteCatalog.h"
#include "quadGeometryGuard.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace {
  using namespace QuadOptimizer::HalfEdgeRewrite;

  bool require(bool condition, const char *message)
  {
    if(condition) return true;
    std::cerr << "half-edge rewrite catalog: " << message << '\n';
    return false;
  }

  bool testSharedGeometryGuard()
  {
    using QuadOptimizer::GeometryGuard::UV;
    using QuadOptimizer::GeometryGuard::Point;
    using QuadOptimizer::GeometryGuard::indexedPatchFollowsNormals;
    using Triangles = std::vector<std::array<std::size_t, 3> >;
    using Quads = std::vector<std::array<std::size_t, 4> >;
    const Triangles triangles;
    const Quads quad = {{{0, 1, 2, 3}}};
    const std::vector<UV> squareUv = {{{0., 0.}}, {{1., 0.}},
                                      {{1., 1.}}, {{0., 1.}}};
    const std::vector<Point> squareXyz = {{{0., 0., 0.}}, {{1., 0., 0.}},
                                         {{1., 1., 0.}}, {{0., 1., 0.}}};
    bool ok = true;
    std::vector<UV> sampled;
    const auto positive = [&](const UV &uv, const Point &, double, double) {
      sampled.push_back(uv);
      return 1;
    };
    ok = require(indexedPatchFollowsNormals(positive, squareUv, squareXyz,
                                            triangles, quad) &&
                   sampled.size() == 8,
                 "shared guard did not sample a quad at all eight locations") && ok;
    const auto opposedAtTwoCorners = [](const UV &uv, const Point &, double, double) {
      return uv[1] > .99 ? -1 : 1;
    };
    const auto opposedCount = std::count_if(sampled.begin(), sampled.end(),
      [](const UV &uv) { return uv[1] > .99; });
    ok = require(opposedCount == 2 &&
                   !indexedPatchFollowsNormals(opposedAtTwoCorners, squareUv,
                     squareXyz, triangles, quad),
                 "six favorable quad samples hid two opposed corner samples") && ok;

    const auto partiallyUnavailable = [](const UV &uv, const Point &, double, double) {
      return uv[0] > .99 && uv[1] > .99 ? 1 : 0;
    };
    const auto unavailable = [](const UV &, const Point &, double, double) { return 0; };
    const auto opposedAmongUnavailable = [](const UV &uv, const Point &, double, double) {
      return uv[0] > .99 && uv[1] > .99 ? -1 : 0;
    };
    ok = require(indexedPatchFollowsNormals(partiallyUnavailable, squareUv,
                   squareXyz, triangles, quad),
                 "unavailable normals did not abstain beside a reliable sample") && ok;
    ok = require(!indexedPatchFollowsNormals(unavailable, squareUv, squareXyz,
                   triangles, quad),
                 "a quad with no reliable normal was accepted by the strict guard") && ok;
    ok = require(indexedPatchFollowsNormals(unavailable, squareUv, squareXyz,
                   triangles, quad, 1, true),
                 "explicitly allowed unevaluable samples did not abstain") && ok;
    for(bool allowUnavailable : {false, true})
      ok = require(!indexedPatchFollowsNormals(opposedAmongUnavailable, squareUv,
                     squareXyz, triangles, quad, 1, allowUnavailable),
                   "an opposed reliable sample was hidden by unavailable normals") && ok;

    // This concave quad has a positive center Jacobian and an opposed
    // corner. A center/Newell-only test would therefore miss the fold.
    std::vector<Point> foldedXyz = squareXyz;
    foldedXyz[2] = {{.25, .25, 0.}};
    const auto zNormal = [](const UV &, const Point &jacobian,
                             double norm, double scale2) {
      if(!std::isfinite(norm) || norm <= 1.e-12 * scale2) return 0;
      return jacobian[2] > 1.e-10 * norm ? 1 : -1;
    };
    ok = require(!indexedPatchFollowsNormals(zNormal, squareUv, foldedXyz,
                   triangles, quad),
                 "shared guard accepted a physically folded bilinear quad") && ok;
    const Triangles triangle = {{{0, 1, 2}}};
    const Quads noQuads;
    ok = require(indexedPatchFollowsNormals(zNormal, squareUv, squareXyz,
                   triangle, noQuads),
                 "shared guard rejected a positively oriented triangle") && ok;
    const Triangles reversed = {{{0, 2, 1}}};
    ok = require(!indexedPatchFollowsNormals(zNormal, squareUv, squareXyz,
                   reversed, noQuads),
                 "shared guard accepted an opposed triangle") && ok;

    // Physical and parameter coordinates have independent origins and units.
    // Keep the same classifications over twelve orders of length scale.
    for(const double physicalScale : {1.e-6, 1., 1.e6}) {
      for(const double parameterScale : {1.e-6, 1., 1.e6}) {
        for(const double translation : {0., 1024.}) {
          std::vector<UV> transformedUv = squareUv;
          auto transformedXyz = squareXyz;
          auto transformedFold = foldedXyz;
          for(std::size_t i = 0; i < squareUv.size(); ++i) {
            for(std::size_t coordinate = 0; coordinate < 2; ++coordinate)
              transformedUv[i][coordinate] = parameterScale *
                (squareUv[i][coordinate] + (coordinate ? -translation : translation));
            for(std::size_t coordinate = 0; coordinate < 3; ++coordinate) {
              const double offset = (static_cast<double>(coordinate) - 1.) * translation;
              transformedXyz[i][coordinate] = physicalScale *
                (squareXyz[i][coordinate] + offset);
              transformedFold[i][coordinate] = physicalScale *
                (foldedXyz[i][coordinate] + offset);
            }
          }
          ok = require(indexedPatchFollowsNormals(zNormal, transformedUv,
                         transformedXyz, triangles, quad) &&
                         !indexedPatchFollowsNormals(zNormal, transformedUv,
                           transformedFold, triangles, quad) &&
                         indexedPatchFollowsNormals(zNormal, transformedUv,
                           transformedXyz, triangle, noQuads) &&
                         !indexedPatchFollowsNormals(zNormal, transformedUv,
                           transformedXyz, reversed, noQuads),
                       "orientation classification changed with origins or units") && ok;
        }
      }
    }
    return ok;
  }

  bool testNumericHalfEdgeMesh()
  {
    using QuadOptimizer::HalfEdgeMesh::Index;
    using QuadOptimizer::HalfEdgeMesh::Mesh;
    using QuadOptimizer::HalfEdgeMesh::canonicalEdge;
    bool ok = true;

    Mesh mesh;
    std::vector<Index> vertices;
    for(int i = 0; i < 4; ++i)
      vertices.push_back(mesh.addVertex(
        {{static_cast<double>(i & 1),
          static_cast<double>((i >> 1) & 1), 0.}}));
    const Index first = mesh.addFace({vertices[0], vertices[1], vertices[2]});
    const Index second = mesh.addFace({vertices[0], vertices[2], vertices[3]});
    ok = require(first >= 0 && second >= 0 && mesh.manifold(),
                 "numeric TT disk is not manifold") && ok;
    ok = require(mesh.faceCount(3) == 2 && mesh.faceCount(4) == 0,
                 "numeric face counts are incorrect") && ok;
    ok = require(mesh.incidentFaces(
                   canonicalEdge(vertices[0], vertices[2])).size() == 2,
                 "numeric twin edge is missing an incidence") && ok;
    ok = require(mesh.validReplacement(
                   {first, second},
                   {{vertices[0], vertices[1], vertices[2], vertices[3]}}),
                 "numeric TT-to-Q preflight was rejected") && ok;
    std::vector<Index> inserted;
    ok = require(mesh.replace(
                   {first, second},
                   {{vertices[0], vertices[1], vertices[2], vertices[3]}},
                   &inserted) && inserted.size() == 1,
                 "numeric TT-to-Q transaction failed") && ok;
    ok = require(mesh.faceCount(3) == 0 && mesh.faceCount(4) == 1 &&
                   mesh.manifold(),
                 "numeric TT-to-Q transaction corrupted the mesh") && ok;
    ok = require(mesh.setVertexPosition(vertices[0], {{.25, .5, .75}}) &&
                   mesh.vertexPosition(vertices[0]) &&
                   (*mesh.vertexPosition(vertices[0]))[2] == .75,
                 "numeric vertex coordinates are not persistent") && ok;

    Mesh sameDirection;
    const Index a = sameDirection.addVertex({{0., 0., 0.}});
    const Index b = sameDirection.addVertex({{1., 0., 0.}});
    const Index c = sameDirection.addVertex({{0., 1., 0.}});
    const Index d = sameDirection.addVertex({{1., 1., 0.}});
    sameDirection.addFace({a, b, c});
    sameDirection.addFace({a, b, d});
    ok = require(!sameDirection.manifold(),
                 "same-direction twins were accepted") && ok;

    Mesh doubleSharedEdge;
    const Index e = doubleSharedEdge.addVertex({{0., 0., 0.}});
    const Index f = doubleSharedEdge.addVertex({{1., 0., 0.}});
    const Index g = doubleSharedEdge.addVertex({{0., 1., 0.}});
    doubleSharedEdge.addFace({e, f, g});
    doubleSharedEdge.addFace({f, e, g});
    ok = require(!doubleSharedEdge.manifold(),
                 "two cells sharing several edges were accepted") && ok;
    return ok;
  }

  bool testNumericTriangleQuadStripRails()
  {
    using QuadOptimizer::HalfEdgeMesh::Index;
    using QuadOptimizer::HalfEdgeMesh::Mesh;
    bool ok = true;

    for(std::size_t quadrangleCount = 0; quadrangleCount <= 4;
        ++quadrangleCount) {
      Mesh mesh;
      const Index firstApex = mesh.addVertex({{0., .5, 0.}});
      std::vector<Index> firstSide(quadrangleCount + 1);
      std::vector<Index> secondSide(quadrangleCount + 1);
      for(std::size_t i = 0; i < firstSide.size(); ++i)
        firstSide[i] = mesh.addVertex(
          {{static_cast<double>(i + 1), 0., 0.}});
      for(std::size_t i = 0; i < secondSide.size(); ++i)
        secondSide[i] = mesh.addVertex(
          {{static_cast<double>(i + 1), 1., 0.}});
      const Index lastApex = mesh.addVertex(
        {{static_cast<double>(quadrangleCount + 2), .5, 0.}});

      std::vector<Index> orderedFaces;
      orderedFaces.push_back(mesh.addFace(
        {firstApex, firstSide.front(), secondSide.front()}));
      for(std::size_t i = 0; i < quadrangleCount; ++i)
        orderedFaces.push_back(mesh.addFace(
          {secondSide[i], firstSide[i], firstSide[i + 1],
           secondSide[i + 1]}));
      orderedFaces.push_back(mesh.addFace(
        {secondSide.back(), firstSide.back(), lastApex}));

      std::vector<Index> expectedFirst = {firstApex};
      expectedFirst.insert(expectedFirst.end(), firstSide.begin(),
                           firstSide.end());
      expectedFirst.push_back(lastApex);
      std::vector<Index> expectedSecond = {firstApex};
      expectedSecond.insert(expectedSecond.end(), secondSide.begin(),
                            secondSide.end());
      expectedSecond.push_back(lastApex);

      std::vector<Index> firstRail, secondRail;
      ok = require(mesh.manifold() &&
                     mesh.triangleQuadStripRails(
                       orderedFaces, firstRail, secondRail),
                   "a numeric T-Q^k-T strip did not expose its rails") && ok;
      ok = require(firstRail == expectedFirst &&
                     secondRail == expectedSecond,
                   "numeric strip rails have a non-deterministic side") && ok;

      std::reverse(orderedFaces.begin(), orderedFaces.end());
      std::reverse(expectedFirst.begin(), expectedFirst.end());
      std::reverse(expectedSecond.begin(), expectedSecond.end());
      ok = require(mesh.triangleQuadStripRails(
                     orderedFaces, firstRail, secondRail) &&
                     firstRail == expectedFirst &&
                     secondRail == expectedSecond,
                   "reversing a numeric strip did not reverse its rails") && ok;

      if(quadrangleCount == 1) {
        std::vector<Index> invalidFirst = {firstApex};
        std::vector<Index> invalidSecond = {lastApex};
        const std::vector<Index> duplicated =
          {orderedFaces.back(), orderedFaces[1], orderedFaces[1],
           orderedFaces.front()};
        ok = require(!mesh.triangleQuadStripRails(
                       duplicated, invalidFirst, invalidSecond) &&
                       invalidFirst.empty() && invalidSecond.empty(),
                     "a strip with a repeated face exposed rails") && ok;
        ok = require(!mesh.triangleQuadStripRails(
                       {orderedFaces.back(), orderedFaces[1]},
                       invalidFirst, invalidSecond),
                     "a strip with a quadrangle endpoint exposed rails") && ok;
      }
    }

    // The two passage edges of this otherwise manifold T-Q-T disk are
    // adjacent: all three cells form a fan around u, not a two-rail strip.
    Mesh fan;
    const Index s = fan.addVertex({{0., 0., 0.}});
    const Index u = fan.addVertex({{1., 0., 0.}});
    const Index v = fan.addVertex({{0., 1., 0.}});
    const Index w = fan.addVertex({{2., 0., 0.}});
    const Index x = fan.addVertex({{1., 1., 0.}});
    const Index t = fan.addVertex({{3., 0., 0.}});
    const Index firstTriangle = fan.addFace({s, u, v});
    const Index fanQuadrangle = fan.addFace({v, u, w, x});
    const Index lastTriangle = fan.addFace({w, u, t});
    std::vector<Index> firstRail, secondRail;
    ok = require(fan.manifold() &&
                   !fan.triangleQuadStripRails(
                     {firstTriangle, fanQuadrangle, lastTriangle},
                     firstRail, secondRail),
                 "a T-Q-T fan was accepted as a two-rail strip") && ok;
    ok = require(
           fan.triangleQuadBoundaryFanCenter(
             {firstTriangle, fanQuadrangle, lastTriangle}) == u,
           "a boundary T-Q-T fan was not recognized numerically") && ok;

    Mesh disconnected;
    std::vector<Index> isolatedVertices;
    for(std::size_t i = 0; i < 6; ++i)
      isolatedVertices.push_back(disconnected.addVertex(
        {{static_cast<double>(i), 0., 0.}}));
    const Index firstIsolated = disconnected.addFace(
      {isolatedVertices[0], isolatedVertices[1], isolatedVertices[2]});
    const Index secondIsolated = disconnected.addFace(
      {isolatedVertices[3], isolatedVertices[4], isolatedVertices[5]});
    ok = require(disconnected.manifold() &&
                   !disconnected.triangleQuadStripRails(
                     {firstIsolated, secondIsolated},
                     firstRail, secondRail),
                 "disconnected triangles were accepted as a strip") && ok;
    ok = require(
           disconnected.triangleQuadBoundaryFanCenter(
             {firstIsolated, secondIsolated}) ==
             QuadOptimizer::HalfEdgeMesh::invalid,
           "a disconnected path was accepted as a boundary fan") && ok;
    return ok;
  }

  bool testAtomicReplacement()
  {
    using QuadOptimizer::HalfEdgeMesh::Index;
    using QuadOptimizer::HalfEdgeMesh::Mesh;
    using QuadOptimizer::HalfEdgeMesh::canonicalEdge;
    bool ok = true;

    Mesh mesh;
    const Index a = mesh.addVertex({{0., 0., 0.}});
    const Index b = mesh.addVertex({{1., 0., 0.}});
    const Index c = mesh.addVertex({{1., 1., 0.}});
    const Index d = mesh.addVertex({{0., 1., 0.}});
    const Index retired = mesh.addVertex({{2., 2., 0.}});
    const Index first = mesh.addFace({a, b, c});
    const Index second = mesh.addFace({a, c, d});
    ok = require(mesh.retireIsolatedVertex(retired),
                 "could not prepare a retired vertex identifier") && ok;

    const std::vector<Index> originalFaces = mesh.faces();
    const std::vector<Index> originalFirst = mesh.faceVertices(first);
    const std::vector<Index> originalSecond = mesh.faceVertices(second);
    const std::vector<Index> originalShared =
      mesh.incidentFaces(canonicalEdge(a, c));
    const std::size_t originalVertexStorage = mesh.vertexStorageSize();
    const std::size_t originalFaceStorage = mesh.faceStorageSize();
    const std::size_t originalHalfEdgeStorage = mesh.halfEdgeStorageSize();
    const auto unchanged = [&]() {
      return mesh.manifold() && mesh.faces() == originalFaces &&
             mesh.faceVertices(first) == originalFirst &&
             mesh.faceVertices(second) == originalSecond &&
             mesh.incidentFaces(canonicalEdge(a, c)) == originalShared &&
             mesh.faceCount(3) == 2 && mesh.faceCount(4) == 0 &&
             mesh.vertexStorageSize() == originalVertexStorage &&
             mesh.faceStorageSize() == originalFaceStorage &&
             mesh.halfEdgeStorageSize() == originalHalfEdgeStorage;
    };

    // Adapter-side preflight is allowed to name vertices that it will create
    // immediately before commit. The commit itself must reject the same
    // rewrite until those identifiers have actually been materialized.
    const Index virtualVertex =
      static_cast<Index>(mesh.vertexStorageSize());
    const std::vector<std::vector<Index> > virtualQuad =
      {{a, b, c, virtualVertex}};
    ok = require(mesh.validReplacement({first, second}, virtualQuad),
                 "virtual vertex was rejected during preflight") && ok;
    std::vector<Index> insertedFaces = {first};
    ok = require(!mesh.replace(
                   {first, second}, virtualQuad, &insertedFaces),
                 "commit accepted a non-materialized virtual vertex") && ok;
    ok = require(insertedFaces.empty(),
                 "failed commit returned inserted face identifiers") && ok;
    ok = require(unchanged(),
                 "virtual-vertex failure partially mutated the mesh") && ok;

    // A tombstone is neither an active vertex nor a virtual future id.
    const std::vector<std::vector<Index> > retiredQuad =
      {{a, b, c, retired}};
    ok = require(!mesh.validReplacement({first, second}, retiredQuad),
                 "preflight accepted a retired vertex identifier") && ok;
    insertedFaces = {second};
    ok = require(!mesh.replace(
                   {first, second}, retiredQuad, &insertedFaces),
                 "commit accepted a retired vertex identifier") && ok;
    ok = require(insertedFaces.empty() && unchanged(),
                 "retired-vertex failure partially mutated the mesh") && ok;

    insertedFaces = {first, second};
    ok = require(!mesh.replace(
                   {first, second}, {{a, b, b, d}}, &insertedFaces),
                 "commit accepted duplicate quad corners") && ok;
    ok = require(insertedFaces.empty() && unchanged(),
                 "invalid-connectivity failure partially mutated the mesh") &&
         ok;

    insertedFaces = {second};
    ok = require(!mesh.replace(
                   {first, second}, {{a, b, c}, {a, b, d}}, &insertedFaces),
                 "commit accepted equally oriented twins") && ok;
    ok = require(insertedFaces.empty() && unchanged(),
                 "non-manifold failure partially mutated the mesh") && ok;

    insertedFaces = {first};
    ok = require(!mesh.replace(
                   {first, first}, {{a, b, c, d}}, &insertedFaces),
                 "commit accepted a duplicate removed face") && ok;
    ok = require(insertedFaces.empty() && unchanged(),
                 "duplicate-removal failure partially mutated the mesh") &&
         ok;

    // Rejected transactions must not consume stable face/half-edge ids: the
    // original valid rewrite still commits in the next append-only slots.
    ok = require(mesh.replace(
                   {first, second}, {{a, b, c, d}}, &insertedFaces) &&
                   insertedFaces.size() == 1,
                 "valid transaction failed after rejected transactions") &&
         ok;
    ok = require(insertedFaces.front() ==
                   static_cast<Index>(originalFaceStorage) &&
                   mesh.faceStorageSize() == originalFaceStorage + 1 &&
                   mesh.halfEdgeStorageSize() == originalHalfEdgeStorage + 4 &&
                   mesh.faceCount(3) == 0 && mesh.faceCount(4) == 1 &&
                   mesh.manifold(),
                 "rejected transaction consumed ids or damaged topology") &&
         ok;
    return ok;
  }

  bool testPreparedReplacement()
  {
    using QuadOptimizer::HalfEdgeMesh::Index;
    using QuadOptimizer::HalfEdgeMesh::Mesh;
    using QuadOptimizer::HalfEdgeMesh::Cavity;
    using QuadOptimizer::HalfEdgeMesh::canonicalEdge;
    bool ok = true;
    Mesh mesh;
    const Index a = mesh.addVertex({{0., 0., 0.}});
    const Index b = mesh.addVertex({{1., 0., 0.}});
    const Index c = mesh.addVertex({{1., 1., 0.}});
    const Index d = mesh.addVertex({{0., 1., 0.}});
    const Index e = mesh.addVertex({{2., .5, 0.}});
    std::vector<Index> patch = {mesh.addFace({a, b, c}),
                                mesh.addFace({a, c, d})};
    const Index outside = mesh.addFace({b, e, c});
    const std::vector<std::vector<Index> > quad = {{a, b, c, d}};
    Mesh::PreparedReplacement prepared, stale;
    ok = require(mesh.prepareReplacement(patch, quad, prepared) &&
                   mesh.prepareReplacement(patch, quad, stale),
                 "could not prepare parallel replacement proofs") && ok;
    Mesh::PreparedReplacement moved(std::move(prepared));
    const auto original = mesh.faces();
    ok = require(!mesh.replace(prepared) && mesh.faces() == original,
                 "a moved-from proof remained usable") && ok;
    Mesh foreign;
    ok = require(!foreign.replace(moved),
                 "a proof was accepted by a different mesh") && ok;
    ok = require(mesh.replace(moved, &patch) && patch.size() == 1,
                 "the moved replacement proof did not commit") && ok;
    const auto installed = mesh.faces();
    ok = require(!mesh.replace(stale) && mesh.faces() == installed &&
                   !mesh.replace(moved),
                 "stale or consumed proof mutated the mesh") && ok;

    // Repeated changes exercise local twin updates against an untouched
    // neighbor and active-index iteration after many retired face ids.
    for(int iteration = 0; iteration < 128; ++iteration) {
      const std::vector<std::vector<Index> > filling = patch.size() == 1 ?
        std::vector<std::vector<Index> >{{a, b, c}, {a, c, d}} : quad;
      Mesh::PreparedReplacement next;
      if(!require(mesh.prepareReplacement(patch, filling, next) &&
                    mesh.replace(next, &patch),
                  "repeated prepared replacement failed")) return false;
      Cavity cavity;
      ok = require(mesh.manifold() && mesh.diskCavity(patch, cavity) &&
                     cavity.boundaryVertices == std::vector<Index>({a, b, c, d}) &&
                     mesh.faces().size() == patch.size() + 1 &&
                     mesh.vertices() == std::vector<Index>({a, b, c, d, e}) &&
                     mesh.faceVertices(outside) == std::vector<Index>({b, e, c}) &&
                     mesh.incidentFaces(canonicalEdge(b, c)).size() == 2 &&
                     mesh.neighbors(outside).size() == 1,
                   "local commits damaged an outside twin or active ids") && ok;
    }

    if(patch.size() != 1) {
      const auto removed = patch;
      if(!mesh.replace(removed, quad, &patch)) return false;
    }
    const Index center = static_cast<Index>(mesh.vertexStorageSize());
    const std::vector<std::vector<Index> > fan = {
      {a, b, center}, {b, c, center}, {c, d, center}, {d, a, center}};
    Mesh::PreparedReplacement virtualProof;
    ok = require(mesh.prepareReplacement(patch, fan, virtualProof) &&
                   !mesh.replace(virtualProof),
                 "virtual proof committed before vertex materialization") && ok;
    ok = require(mesh.addVertex({{.5, .5, 0.}}) == center &&
                   mesh.replace(virtualProof, &patch) &&
                   mesh.incidentFaces(center).size() == 4,
                 "materialization invalidated a valid topology proof") && ok;
    ok = require(!mesh.discardIsolatedVertexTail(static_cast<std::size_t>(center)),
                 "vertex-tail rollback removed a committed vertex") && ok;
    const auto removed = patch;
    ok = require(mesh.replace(removed, quad, &patch) &&
                   mesh.retireIsolatedVertex(center) &&
                   mesh.vertices() == std::vector<Index>({a, b, c, d, e}),
                 "retired interior vertex remained in the active index") && ok;
    const std::size_t tail = mesh.vertexStorageSize();
    mesh.addVertex({{.25, .25, 0.}});
    ok = require(mesh.discardIsolatedVertexTail(tail) &&
                   mesh.vertexStorageSize() == tail && mesh.manifold(),
                 "uncommitted vertex-tail rollback failed") && ok;
    Mesh::PreparedReplacement invalidated;
    const std::vector<std::vector<Index> > triangles = {{a, b, c}, {a, c, d}};
    ok = require(mesh.prepareReplacement(patch, triangles, invalidated),
                 "could not prepare the invalidation fixture") && ok;
    const auto beforeInvalidInput = mesh.faces();
    mesh.addFace({a, a, b});
    ok = require(!mesh.replace(invalidated) &&
                   mesh.faces() == beforeInvalidInput,
                 "a proof committed after the mesh became invalid") && ok;
    return ok;
  }

  bool testNumericCavities()
  {
    using QuadOptimizer::HalfEdgeMesh::Cavity;
    using QuadOptimizer::HalfEdgeMesh::CavityAnchor;
    using QuadOptimizer::HalfEdgeMesh::Index;
    using QuadOptimizer::HalfEdgeMesh::Mesh;
    using QuadOptimizer::HalfEdgeMesh::canonicalEdge;
    bool ok = true;

    Mesh triangleDisk;
    const Index a = triangleDisk.addVertex({{0., 0., 0.}});
    const Index b = triangleDisk.addVertex({{1., 0., 0.}});
    const Index c = triangleDisk.addVertex({{1., 1., 0.}});
    const Index d = triangleDisk.addVertex({{0., 1., 0.}});
    const Index first = triangleDisk.addFace({a, b, c});
    const Index second = triangleDisk.addFace({a, c, d});
    Cavity cavity;
    ok = require(triangleDisk.isInternalEdge(canonicalEdge(a, c)) &&
                   !triangleDisk.isInternalEdge(canonicalEdge(a, b)) &&
                   triangleDisk.edgeCavity(canonicalEdge(a, c), cavity) &&
                   cavity.anchor == CavityAnchor::Edge &&
                   cavity.anchorOnBoundary == 0 &&
                   cavity.anchorFaces ==
                     std::vector<Index>({first, second}) &&
                   cavity.faces == std::vector<Index>({first, second}) &&
                   cavity.boundaryVertices ==
                     std::vector<Index>({a, b, c, d}) &&
                   cavity.interiorVertices.empty(),
                 "the numeric internal-edge cavity is incorrect") && ok;
    Cavity reversedEdge;
    ok = require(triangleDisk.edgeCavity({c, a}, reversedEdge) &&
                   reversedEdge.faces == cavity.faces &&
                   reversedEdge.boundaryVertices == cavity.boundaryVertices,
                 "edge cavity depends on endpoint order") && ok;
    ok = require(!triangleDisk.edgeCavity(canonicalEdge(a, b), cavity) &&
                   cavity.faces.empty(),
                 "a boundary edge was accepted as an edge cavity") && ok;

    Cavity boundaryVertex;
    ok = require(triangleDisk.vertexCavity(b, boundaryVertex) &&
                   boundaryVertex.anchor == CavityAnchor::Vertex &&
                   boundaryVertex.anchorOnBoundary == 1,
                 "a boundary vertex cavity was not classified") && ok;

    Mesh star;
    const Index center = star.addVertex({{0., 0., 0.}});
    std::array<Index, 4> ring = {{
      star.addVertex({{-1., -1., 0.}}),
      star.addVertex({{1., -1., 0.}}),
      star.addVertex({{1., 1., 0.}}),
      star.addVertex({{-1., 1., 0.}})}};
    for(std::size_t i = 0; i < ring.size(); ++i)
      star.addFace({center, ring[i], ring[(i + 1) % ring.size()]});
    Cavity centerStar;
    ok = require(star.vertexCavity(center, centerStar) &&
                   centerStar.anchorOnBoundary == 0 &&
                   centerStar.anchorFaces.size() == 4 &&
                   star.anchorFacePattern(centerStar) ==
                     std::vector<Index>({3, 3, 3, 3}) &&
                   centerStar.boundaryVertices ==
                     std::vector<Index>(ring.begin(), ring.end()) &&
                   centerStar.interiorVertices ==
                     std::vector<Index>({center}),
                 "the numeric interior vertex star is incorrect") && ok;
    const std::vector<Index> centerRing = star.incidentFaceRing(center);
    ok = require(centerRing.size() == 4 &&
                   std::all_of(centerRing.begin(), centerRing.end(),
                               [&](Index face) {
                                 return star.faceCornerCount(face) == 3;
                               }),
                 "the numeric cyclic face ring is incorrect") && ok;
    const std::vector<Index> boundaryRing =
      star.incidentFaceRing(ring.front());
    ok = require(boundaryRing.size() == 2 &&
                   star.isBoundaryVertex(ring.front()),
                 "the numeric boundary face chain is incorrect") && ok;

    Mesh mixedStar;
    const Index mixedCenter = mixedStar.addVertex({{0., 0., 0.}});
    const std::array<std::array<double, 2>, 6> ringCoordinates = {{
      {{1., 0.}}, {{.5, .866}}, {{-.5, .866}}, {{-1., 0.}},
      {{-.5, -.866}}, {{.5, -.866}}
    }};
    std::array<Index, 6> mixedRing;
    for(std::size_t i = 0; i < mixedRing.size(); ++i)
      mixedRing[i] = mixedStar.addVertex(
        {{ringCoordinates[i][0], ringCoordinates[i][1], 0.}});
    for(std::size_t i = 0; i < mixedRing.size(); ++i) {
      const Index next = mixedRing[(i + 1) % mixedRing.size()];
      if(i == 0 || i == 3) {
        mixedStar.addFace({mixedCenter, mixedRing[i], next});
      }
      else {
        const Index outer = mixedStar.addVertex({{
          1.2 * (ringCoordinates[i][0] +
                 ringCoordinates[(i + 1) % mixedRing.size()][0]),
          1.2 * (ringCoordinates[i][1] +
                 ringCoordinates[(i + 1) % mixedRing.size()][1]),
          0.}});
        mixedStar.addFace({mixedCenter, mixedRing[i], outer, next});
      }
    }
    Cavity mixedCenterStar;
    ok = require(mixedStar.manifold() &&
                   mixedStar.vertexCavity(mixedCenter, mixedCenterStar) &&
                   !mixedCenterStar.anchorOnBoundary &&
                   mixedStar.anchorFacePattern(mixedCenterStar) ==
                     std::vector<Index>({3, 4, 4, 3, 4, 4}),
                 "the numeric T-Q-Q-T-Q-Q vertex pattern is incorrect") &&
         ok;
    ok = require(matchesCyclicFacePattern(
                   mixedStar.anchorFacePattern(mixedCenterStar),
                   {4, 3, 4, 4, 3, 4}) &&
                   !matchesCyclicFacePattern(
                     mixedStar.anchorFacePattern(mixedCenterStar),
                     {3, 4, 3, 4, 4, 4}) &&
                   matchesBoundaryFacePattern({3, 4, 4, 3},
                                              {3, 4, 4, 3}) &&
                   matchesBoundaryFacePattern({3, 4, 4}, {4, 4, 3}) &&
                   !matchesBoundaryFacePattern({3, 4, 3}, {3, 3, 4}),
                 "face-pattern symmetry matching is incorrect") && ok;

    Mesh grid;
    std::array<Index, 16> gridVertices;
    for(std::size_t y = 0; y < 4; ++y)
      for(std::size_t x = 0; x < 4; ++x)
        gridVertices[4 * y + x] = grid.addVertex(
          {{static_cast<double>(x), static_cast<double>(y), 0.}});
    std::array<Index, 9> gridFaces;
    for(std::size_t y = 0; y < 3; ++y)
      for(std::size_t x = 0; x < 3; ++x) {
        const Index lowerLeft = gridVertices[4 * y + x];
        const Index lowerRight = gridVertices[4 * y + x + 1];
        const Index upperRight = gridVertices[4 * (y + 1) + x + 1];
        const Index upperLeft = gridVertices[4 * (y + 1) + x];
        gridFaces[3 * y + x] = grid.addFace(
          {lowerLeft, lowerRight, upperRight, upperLeft});
      }
    const Index centralFace = gridFaces[4];
    Cavity single;
    ok = require(grid.singleQuadCavity(centralFace, single) &&
                   single.anchor == CavityAnchor::SingleQuadrangle &&
                   single.anchorFaces == std::vector<Index>({centralFace}) &&
                   grid.anchorFacePattern(single) ==
                     std::vector<Index>({4}) &&
                   single.coreFaces.size() == 1 && single.faces.size() == 1 &&
                   single.boundaryVertices.size() == 4 &&
                   single.interiorVertices.empty(),
                 "a single-quadrangle cavity is incorrect") && ok;

    const std::vector<Index> centralVertices =
      grid.faceVertices(centralFace);
    Cavity extended;
    ok = require(grid.extendByVertexStars(
                   single, centralVertices, extended) &&
                   extended.anchor == single.anchor &&
                   extended.anchorFirst == single.anchorFirst &&
                   extended.anchorVertices == single.anchorVertices &&
                   extended.anchorFaces == single.anchorFaces &&
                   extended.coreFaces == single.coreFaces &&
                   extended.faces.size() == 9 &&
                   extended.boundaryVertices.size() == 12 &&
                   std::set<Index>(extended.interiorVertices.begin(),
                                   extended.interiorVertices.end()) ==
                     std::set<Index>(centralVertices.begin(),
                                     centralVertices.end()),
                 "C+C' does not contain the four central vertex stars") && ok;
    Cavity directStars;
    ok = require(grid.vertexStarsCavity(
                   centralVertices, directStars) &&
                   directStars.faces == extended.faces &&
                   directStars.boundaryVertices ==
                     extended.boundaryVertices,
                 "vertex-star and C+C' constructions disagree") && ok;

    std::vector<Index> annulus(gridFaces.begin(), gridFaces.end());
    annulus.erase(annulus.begin() + 4);
    ok = require(!grid.diskCavity(annulus, cavity) && cavity.faces.empty(),
                 "a cavity with a hole was accepted") && ok;
    ok = require(!grid.diskCavity(
                   {gridFaces.front(), gridFaces.back()}, cavity) &&
                   cavity.faces.empty(),
                 "an edge-disconnected cavity was accepted") && ok;

    std::vector<Index> replacement;
    ok = require(triangleDisk.replace(
                   {first, second}, {{a, b, c, d}}, &replacement) &&
                   replacement.size() == 1,
                 "TT-to-Q replacement failed during cavity testing") && ok;
    ok = require(!triangleDisk.diskCavity({first, second}, cavity) &&
                   triangleDisk.singleQuadCavity(replacement.front(), cavity),
                 "cavity identifiers were not updated after replacement") && ok;
    return ok;
  }

  bool testExecutableAnchorContract()
  {
    using QuadOptimizer::HalfEdgeMesh::Cavity;
    using QuadOptimizer::HalfEdgeMesh::Index;
    using QuadOptimizer::HalfEdgeMesh::Mesh;
    using QuadOptimizer::HalfEdgeMesh::canonicalEdge;
    bool ok = true;

    Mesh mesh;
    const Index a = mesh.addVertex({{0., 0., 0.}});
    const Index b = mesh.addVertex({{1., 0., 0.}});
    const Index c = mesh.addVertex({{1., 1., 0.}});
    const Index d = mesh.addVertex({{0., 1., 0.}});
    mesh.addFace({a, b, c});
    mesh.addFace({a, c, d});
    Cavity edge, vertex, vertexSet;
    ok = require(mesh.edgeCavity(canonicalEdge(a, c), edge) &&
                   mesh.vertexCavity(b, vertex) &&
                   mesh.vertexStarsCavity({a, c}, vertexSet),
                 "could not build anchor-contract fixtures") && ok;

    Mesh quadMesh;
    const Index q0 = quadMesh.addVertex({{0., 0., 0.}});
    const Index q1 = quadMesh.addVertex({{1., 0., 0.}});
    const Index q2 = quadMesh.addVertex({{1., 1., 0.}});
    const Index q3 = quadMesh.addVertex({{0., 1., 0.}});
    const Index quadrangle = quadMesh.addFace({q0, q1, q2, q3});
    Cavity singleQuadrangle;
    ok = require(quadMesh.singleQuadCavity(
                   quadrangle, singleQuadrangle),
                 "could not build a single-quad anchor fixture") && ok;

    const auto &rules = catalog();
    const auto vertexRule = std::find_if(
      rules.begin(), rules.end(), [](const Descriptor &rule) {
        return rule.kind == Kind::InteriorQQTQQTReduction;
      });
    const auto edgeRule = std::find_if(
      rules.begin(), rules.end(), [](const Descriptor &rule) {
        return rule.kind == Kind::TriangleTriangleSwap;
      });
    const auto vertexSetRule = std::find_if(
      rules.begin(), rules.end(), [](const Descriptor &rule) {
        return rule.kind == Kind::ThreeVertexDisk;
      });
    const auto quadrangleRule = std::find_if(
      rules.begin(), rules.end(), [](const Descriptor &rule) {
        return rule.kind == Kind::DiamondCollapse;
      });
    const auto loopRule = std::find_if(
      rules.begin(), rules.end(), [](const Descriptor &rule) {
        return rule.kind == Kind::PillowHole;
      });
    ok = require(vertexRule != rules.end() && edgeRule != rules.end() &&
                   vertexSetRule != rules.end() &&
                   quadrangleRule != rules.end() &&
                   loopRule != rules.end(),
                 "anchor-contract descriptors are missing") && ok;
    if(vertexRule == rules.end() || edgeRule == rules.end() ||
       vertexSetRule == rules.end() || quadrangleRule == rules.end() ||
       loopRule == rules.end())
      return false;

    AnchorContract contract;
    ok = require(contract.begin(*vertexRule) && !contract.finish(true),
                 "an accepted rewrite could omit its anchor check") && ok;
    ok = require(contract.begin(*vertexRule) && contract.accepts(vertex) &&
                   contract.checked() && !contract.violated() &&
                   contract.finish(true),
                 "a vertex rule rejected a vertex cavity") && ok;
    ok = require(contract.begin(*edgeRule) && contract.accepts(edge) &&
                   contract.checked() && !contract.violated() &&
                   contract.finish(true),
                 "an edge rule rejected an edge cavity") && ok;
    ok = require(contract.begin(*vertexSetRule) &&
                   contract.accepts(vertexSet) && contract.finish(true),
                 "a vertex-set rule rejected a vertex-set cavity") && ok;
    ok = require(contract.begin(*quadrangleRule) &&
                   contract.accepts(singleQuadrangle) &&
                   contract.finish(true),
                 "a single-quad rule rejected its cavity") && ok;
    ok = require(contract.begin(*edgeRule) && !contract.accepts(vertex) &&
                   contract.checked() && contract.violated() &&
                   !contract.finish(),
                 "an edge rule accepted a vertex cavity") && ok;
    ok = require(contract.begin(*loopRule) &&
                   contract.acceptsBoundaryLoop(4) &&
                   contract.finish(true),
                 "a boundary-loop rule rejected a valid loop") && ok;
    ok = require(contract.begin(*loopRule) && !contract.accepts(edge) &&
                   !contract.finish(),
                 "a boundary-loop rule accepted a face disk") && ok;
    return ok;
  }
}

int main()
{
  using namespace QuadOptimizer::HalfEdgeRewrite;
  bool ok = testSharedGeometryGuard();
  ok = testNumericHalfEdgeMesh() && ok;
  ok = testNumericTriangleQuadStripRails() && ok;
  ok = testAtomicReplacement() && ok;
  ok = testPreparedReplacement() && ok;
  ok = testNumericCavities() && ok;
  ok = testExecutableAnchorContract() && ok;
  const auto &rules = catalog();
  ok = require(rules.size() == 25, "expected 25 rules") && ok;

  struct ExpectedRule {
    const char *id;
    Symmetry symmetry;
    Anchor anchor;
  };
  const std::array<ExpectedRule, 25> expected = {{
    {"interior_ttq_to_q", Symmetry::Dihedral, Anchor::Vertex},
    {"interior_tttt_to_q", Symmetry::Dihedral, Anchor::Vertex},
    {"interior_qtqt_to_2q", Symmetry::Dihedral, Anchor::Vertex},
    {"interior_qqtqqt_to_6q", Symmetry::Dihedral, Anchor::Vertex},
    {"triangle_triangle_swap", Symmetry::Dihedral, Anchor::Edge},
    {"triangle_quad_strip_reduce", Symmetry::Dihedral, Anchor::Edge},
    {"opposite_edge_tqt_mixed_swap", Symmetry::Dihedral, Anchor::Edge},
    {"opposite_edge_tqt_to_3q", Symmetry::Dihedral, Anchor::Edge},
    {"mixed_tq_swap", Symmetry::Dihedral, Anchor::Edge},
    {"quad_quad_swap", Symmetry::Dihedral, Anchor::Edge},
    {"valence6_split", Symmetry::Dihedral, Anchor::Vertex},
    {"disk_connectivity", Symmetry::Dihedral, Anchor::Vertex},
    {"one_vertex_disk", Symmetry::Dihedral, Anchor::Vertex},
    {"diamond_collapse", Symmetry::Dihedral, Anchor::SingleQuadrangle},
    {"disk_boundary", Symmetry::Dihedral, Anchor::Vertex},
    {"boundary_t_qn_t", Symmetry::Dihedral, Anchor::Vertex},
    {"three_vertex_disk", Symmetry::Dihedral, Anchor::VertexSet},
    {"four_vertex_disk", Symmetry::Dihedral, Anchor::VertexSet},
    {"disk_shape", Symmetry::Dihedral, Anchor::SingleQuadrangle},
    {"disk_size", Symmetry::Dihedral, Anchor::Edge},
    {"pillow_hole", Symmetry::BoundaryOriented, Anchor::BoundaryLoop},
    {"opposed_quad_star_smoothing", Symmetry::Dihedral,
     Anchor::SingleQuadrangle},
    {"invalid_quad_split", Symmetry::Dihedral,
     Anchor::SingleQuadrangle},
    {"terminal_triangle_pair_recombination", Symmetry::Dihedral,
     Anchor::Edge},
    {"catastrophic_angle_quad_split", Symmetry::Dihedral,
     Anchor::SingleQuadrangle}
  }};
  std::set<std::string> ids;
  std::set<int> kinds;
  std::array<std::size_t, 6> families = {{0, 0, 0, 0, 0, 0}};
  std::array<std::size_t, 4> schedules = {{0, 0, 0, 0}};
  std::array<std::size_t, 2> symmetries = {{0, 0}};
  for(std::size_t i = 0; i < rules.size(); ++i) {
    ok = require(rules[i].id &&
                   std::string(expected[i].id) == rules[i].id,
                 "rule order or identifier changed") && ok;
    ok = require(rules[i].symmetry == expected[i].symmetry,
                 "rule symmetry changed") && ok;
    ok = require(rules[i].anchor == expected[i].anchor,
                 "rule cavity anchor changed") && ok;
    ok = require(ids.insert(rules[i].id).second,
                 "duplicate rule identifier") && ok;
    ok = require(kinds.insert(static_cast<int>(rules[i].kind)).second,
                 "duplicate rule kind") && ok;
    ++families[static_cast<std::size_t>(rules[i].family)];
    ++schedules[static_cast<std::size_t>(rules[i].schedule)];
    ++symmetries[static_cast<std::size_t>(rules[i].symmetry)];
  }
  ok = require(families == std::array<std::size_t, 6>{{5, 3, 3, 1, 10, 3}},
               "unexpected family distribution") && ok;
  ok = require(schedules == std::array<std::size_t, 4>{{20, 1, 3, 1}},
               "unexpected schedule distribution") && ok;
  ok = require(symmetries == std::array<std::size_t, 2>{{24, 1}},
               "unexpected symmetry distribution") && ok;

  const auto &mixedRepresentatives =
    oppositeEdgeTriangleQuadSwapRepresentatives();
  const std::array<std::size_t, 3> expectedMixedOrbitSizes = {{6, 3, 12}};
  std::set<MixedConnectivity> allMixedFillings;
  for(std::size_t representative = 0;
      representative < mixedRepresentatives.size(); ++representative) {
    std::set<MixedConnectivity> orbit;
    for(std::size_t action = 0;
        action < actionCount(Symmetry::Dihedral, 6); ++action) {
      MixedConnectivity filling;
      for(const std::vector<std::size_t> &face :
          mixedRepresentatives[representative])
        filling.push_back(transformFace(
          Symmetry::Dihedral, 6, action, face));

      std::size_t triangles = 0, quadrangles = 0;
      std::map<std::pair<std::size_t, std::size_t>, std::size_t> edges;
      for(const std::vector<std::size_t> &face : filling) {
        triangles += face.size() == 3;
        quadrangles += face.size() == 4;
        for(std::size_t i = 0; i < face.size(); ++i) {
          std::size_t a = face[i], b = face[(i + 1) % face.size()];
          if(a > b) std::swap(a, b);
          ++edges[{a, b}];
        }
      }
      std::size_t interiorEdges = 0;
      bool manifoldDisk = edges.size() == 8;
      for(const auto &edge : edges) {
        manifoldDisk = manifoldDisk &&
          (edge.second == 1 || edge.second == 2);
        interiorEdges += edge.second == 2;
      }
      ok = require(triangles == 2 && quadrangles == 1,
                   "a mixed hexagon filling must contain 2T+1Q") && ok;
      ok = require(manifoldDisk && interiorEdges == 2,
                   "a mixed hexagon filling must be a B6/I0 disk") && ok;

      const MixedConnectivity key = canonicalConnectivity(filling);
      orbit.insert(key);
      allMixedFillings.insert(key);
    }
    ok = require(orbit.size() == expectedMixedOrbitSizes[representative],
                 "unexpected mixed hexagon D6 orbit size") && ok;
  }
  ok = require(allMixedFillings.size() == 21,
               "the opposite-edge T-Q-T catalog is not exhaustive") && ok;

  auto canonicalStripSet = [](const std::vector<QuadConnectivity> &patterns) {
    std::set<QuadConnectivity> result;
    for(const QuadConnectivity &pattern : patterns)
      result.insert(canonicalConnectivity(pattern));
    return result;
  };
  auto validAllQuadStripDisk = [](
    const QuadConnectivity &pattern, std::size_t boundaryCount,
    std::size_t quadrangleCount) {
    if(pattern.size() != quadrangleCount) return false;
    std::map<std::pair<std::size_t, std::size_t>, std::size_t> edges;
    for(const auto &quad : pattern) {
      const std::set<std::size_t> vertices(quad.begin(), quad.end());
      if(vertices.size() != 4) return false;
      for(std::size_t i = 0; i < quad.size(); ++i) {
        if(quad[i] >= boundaryCount) return false;
        std::size_t a = quad[i], b = quad[(i + 1) % quad.size()];
        if(a > b) std::swap(a, b);
        ++edges[{a, b}];
      }
    }
    std::size_t boundaryEdges = 0, interiorEdges = 0;
    for(const auto &edge : edges) {
      if(edge.second != 1 && edge.second != 2) return false;
      boundaryEdges += edge.second == 1;
      interiorEdges += edge.second == 2;
    }
    return boundaryEdges == boundaryCount &&
      interiorEdges + 1 == quadrangleCount &&
      boundaryCount + quadrangleCount == edges.size() + 1;
  };
  const std::array<std::size_t, 5> expectedStripReconnectCounts =
    {{1, 3, 12, 55, 273}};
  for(std::size_t stripLength = 0; stripLength <= 4; ++stripLength) {
    const std::size_t quadrangleCount = stripLength + 1;
    const std::size_t stripBoundary = 2 * stripLength + 4;
    std::vector<std::size_t> firstRail(quadrangleCount + 2);
    std::vector<std::size_t> secondRail(quadrangleCount + 2);
    for(std::size_t i = 0; i < firstRail.size(); ++i)
      firstRail[i] = i;
    secondRail.front() = firstRail.front();
    secondRail.back() = firstRail.back();
    for(std::size_t i = 1; i <= quadrangleCount; ++i)
      secondRail[i] = stripBoundary - i;

    const std::vector<QuadConnectivity> reconnections =
      triangleQuadStripReconnections(firstRail, secondRail);
    ok = require(reconnections.size() ==
                   expectedStripReconnectCounts[stripLength],
                 "a strip does not expose every polygon reconnection") && ok;
    ok = require(canonicalStripSet(reconnections).size() ==
                   reconnections.size(),
                 "a strip reconnection was generated more than once") && ok;
    for(const QuadConnectivity &pattern : reconnections) {
      ok = require(pattern.size() == quadrangleCount,
                   "a strip reconnection has the wrong quad count") && ok;
      std::map<std::pair<std::size_t, std::size_t>, std::size_t> edges;
      for(const auto &quad : pattern) {
        std::set<std::size_t> vertices(quad.begin(), quad.end());
        ok = require(vertices.size() == 4,
                     "a strip reconnection contains a degenerate quad") && ok;
        for(std::size_t i = 0; i < quad.size(); ++i) {
          ok = require(quad[i] < stripBoundary,
                       "a strip reconnection left its boundary") && ok;
          std::size_t a = quad[i], b = quad[(i + 1) % quad.size()];
          if(a > b) std::swap(a, b);
          ++edges[{a, b}];
        }
      }
      std::size_t boundaryEdges = 0, interiorEdges = 0;
      bool manifold = true;
      for(const auto &edge : edges) {
        boundaryEdges += edge.second == 1;
        interiorEdges += edge.second == 2;
        manifold = manifold && (edge.second == 1 || edge.second == 2);
      }
      ok = require(manifold && boundaryEdges == stripBoundary &&
                     interiorEdges + 1 == quadrangleCount,
                   "a strip reconnection is not the expected B/I=0 disk") && ok;
    }

    const std::set<QuadConnectivity> canonical =
      canonicalStripSet(reconnections);
    ok = require(canonical == canonicalStripSet(
                   triangleQuadStripReconnections(secondRail, firstRail)),
                 "exchanging strip rails changed the rewrite set") && ok;
    std::reverse(firstRail.begin(), firstRail.end());
    std::reverse(secondRail.begin(), secondRail.end());
    ok = require(canonical == canonicalStripSet(
                   triangleQuadStripReconnections(firstRail, secondRail)),
                 "reversing a strip path changed the rewrite set") && ok;
    std::reverse(firstRail.begin(), firstRail.end());
    std::reverse(secondRail.begin(), secondRail.end());

    for(std::size_t action = 0;
        action < actionCount(Symmetry::Dihedral, stripBoundary); ++action) {
      std::vector<std::size_t> transformedFirst(firstRail.size());
      std::vector<std::size_t> transformedSecond(secondRail.size());
      for(std::size_t i = 0; i < firstRail.size(); ++i) {
        transformedFirst[i] = transformBoundaryVertex(
          Symmetry::Dihedral, stripBoundary, action, firstRail[i]);
        transformedSecond[i] = transformBoundaryVertex(
          Symmetry::Dihedral, stripBoundary, action, secondRail[i]);
      }
      std::vector<QuadConnectivity> transformedPatterns;
      for(const QuadConnectivity &pattern : reconnections) {
        QuadConnectivity transformed;
        for(const auto &quad : pattern)
          transformed.push_back(transformFace(
            Symmetry::Dihedral, stripBoundary, action, quad));
        transformedPatterns.push_back(std::move(transformed));
      }
      ok = require(
             canonicalStripSet(transformedPatterns) ==
               canonicalStripSet(triangleQuadStripReconnections(
                 transformedFirst, transformedSecond)),
             "strip reconnections are not dihedrally complete") && ok;
    }

    const std::vector<QuadConnectivity> zippers =
      triangleQuadStripZipperReconnections(firstRail, secondRail);
    const std::size_t expectedZipperCount = stripLength ? 2 : 1;
    ok = require(zippers.size() == expectedZipperCount &&
                   canonicalStripSet(zippers).size() == expectedZipperCount,
                 "a strip does not expose exactly its bounded zippers") && ok;
    ok = require(zippers == triangleQuadStripZipperReconnections(
                            firstRail, secondRail),
                 "strip zipper generation is not deterministic") && ok;
    const std::set<QuadConnectivity> canonicalZippers =
      canonicalStripSet(zippers);
    for(const QuadConnectivity &zipper : zippers) {
      ok = require(validAllQuadStripDisk(
                     zipper, stripBoundary, quadrangleCount),
                   "a strip zipper is not the expected all-quad disk") && ok;
      ok = require(canonical.count(canonicalConnectivity(zipper)) == 1,
                   "a bounded zipper is not a valid exhaustive rewrite") && ok;
    }
    ok = require(
           canonicalZippers == canonicalStripSet(
             triangleQuadStripZipperReconnections(secondRail, firstRail)),
           "exchanging strip rails changed the zipper rewrite set") && ok;
    std::vector<std::size_t> reversedFirst = firstRail;
    std::vector<std::size_t> reversedSecond = secondRail;
    std::reverse(reversedFirst.begin(), reversedFirst.end());
    std::reverse(reversedSecond.begin(), reversedSecond.end());
    ok = require(
           canonicalZippers == canonicalStripSet(
             triangleQuadStripZipperReconnections(
               reversedFirst, reversedSecond)),
           "reversing a strip path changed the zipper rewrite set") && ok;
  }

  ok = require(
         triangleQuadStripZipperReconnections({0, 1}, {0, 1}).empty() &&
           triangleQuadStripZipperReconnections(
             {0, 1, 2}, {0, 3, 4, 2}).empty() &&
           triangleQuadStripZipperReconnections(
             {0, 1, 2}, {0, 3, 4}).empty() &&
           triangleQuadStripZipperReconnections(
             {0, 1, 1, 2}, {0, 3, 4, 2}).empty() &&
           triangleQuadStripZipperReconnections(
             {0, 1, 2, 3}, {0, 4, 1, 3}).empty(),
         "invalid or degenerate strip rails exposed zipper rewrites") && ok;

  constexpr std::size_t boundary = 8;
  ok = require(actionCount(Symmetry::Dihedral, boundary) == 16,
               "D8 must expose sixteen actions") && ok;
  ok = require(actionCount(Symmetry::BoundaryOriented, boundary) == 8,
               "an oriented boundary must expose eight cyclic roots") && ok;

  std::array<std::size_t, boundary> labels = {{0, 1, 2, 3, 4, 5, 6, 7}};
  std::set<std::array<std::size_t, boundary> > dihedralOrbit;
  for(std::size_t action = 0;
      action < actionCount(Symmetry::Dihedral, boundary); ++action) {
    std::array<std::size_t, boundary> image;
    for(std::size_t vertex = 0; vertex < boundary; ++vertex)
      image[vertex] = transformBoundaryVertex(
        Symmetry::Dihedral, boundary, action, labels[vertex]);
    dihedralOrbit.insert(image);
    ok = require(transformBoundaryVertex(
                   Symmetry::Dihedral, boundary, action, boundary + 3) ==
                   boundary + 3,
                 "an interior vertex was transformed") && ok;
  }
  ok = require(dihedralOrbit.size() == 16,
               "asymmetric D8 orbit is incomplete") && ok;

  for(std::size_t rotation = 0; rotation < boundary; ++rotation) {
    const std::size_t inverse = (boundary - rotation) % boundary;
    for(std::size_t vertex = 0; vertex < boundary; ++vertex) {
      const std::size_t rotated = transformBoundaryVertex(
        Symmetry::Dihedral, boundary, rotation, vertex);
      ok = require(transformBoundaryVertex(
                     Symmetry::Dihedral, boundary, inverse, rotated) ==
                     vertex,
                   "rotation inverse failed") && ok;
      const std::size_t reflection = boundary + rotation;
      const std::size_t mirrored = transformBoundaryVertex(
        Symmetry::Dihedral, boundary, reflection, vertex);
      ok = require(transformBoundaryVertex(
                     Symmetry::Dihedral, boundary, reflection, mirrored) ==
                     vertex,
                   "reflection is not an involution") && ok;
    }
  }

  const std::array<std::size_t, 4> face = {{0, 1, 8, 7}};
  const std::array<std::size_t, 4> mirrored = transformFace(
    Symmetry::Dihedral, boundary, boundary, face);
  ok = require(mirrored == std::array<std::size_t, 4>{{1, 8, 7, 0}},
               "reflection did not reverse the oriented face") && ok;

  // A single quadrangle filling a four-vertex disk is fixed by every D4
  // action once face roots and orientations are forgotten.  Ranking must see
  // one connectivity, not eight raw actions competing for the top-K budget.
  using TestFace = std::array<std::size_t, 4>;
  using TestConnectivity = std::vector<TestFace>;
  constexpr std::size_t squareBoundary = 4;
  const TestConnectivity square = {{{0, 1, 2, 3}}};
  std::set<TestConnectivity> squareOrbit;
  for(std::size_t action = 0;
      action < actionCount(Symmetry::Dihedral, squareBoundary); ++action) {
    TestConnectivity transformed;
    for(const TestFace &input : square)
      transformed.push_back(transformFace(
        Symmetry::Dihedral, squareBoundary, action, input));
    squareOrbit.insert(canonicalConnectivity(transformed));
  }
  ok = require(squareOrbit.size() == 1,
               "D4 stabilizer images were not deduplicated") && ok;

  const TestConnectivity labelledInterior = {
    {{0, 1, 4, 5}}, {{1, 2, 3, 4}}};
  const TestConnectivity swappedInterior = {
    {{0, 1, 5, 4}}, {{1, 2, 3, 5}}};
  ok = require(canonicalConnectivity(labelledInterior) !=
                 canonicalConnectivity(swappedInterior),
               "interior-label fixture is not discriminating") && ok;
  ok = require(
         canonicalConnectivityIgnoringInteriorLabels(
           labelledInterior, squareBoundary) ==
         canonicalConnectivityIgnoringInteriorLabels(
           swappedInterior, squareBoundary),
         "permuted interior labels were not canonicalized") && ok;

  return ok ? 0 : 1;
}
