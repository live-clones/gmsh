// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.

#include "quadFinalRepair.h"
#include "GFace.h"
#include "GEdge.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "Field.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <limits>
#include <map>
#include <set>

namespace QuadOptimizer {
  static void updateBoundaryLayerColumnsAfterQuadSplits(
    GFace *gf,
    const std::map<MElement *, std::pair<MElement *, MElement *>> &change)
  {
    BoundaryLayerColumns *columns = gf->getColumns();
    if(!columns || change.empty()) return;

    // The historical column representation accepts both children in place of
    // the quad. It does not encode which one actually touches the wall, so keep
    // the first child as the column key, consistently with quadsToTriangles().
    blElemColumns newElemColumns;
    for(auto it = columns->_elemColumns.begin();
        it != columns->_elemColumns.end(); ++it) {
      MElement *firstElement = it->first;
      auto replacement = change.find(firstElement);
      if(replacement != change.end()) firstElement = replacement->second.first;

      std::vector<MElement *> &newColumn = newElemColumns[firstElement];
      for(MElement *oldElement : it->second) {
        replacement = change.find(oldElement);
        if(replacement == change.end()) {
          newColumn.push_back(oldElement);
          columns->_toFirst[oldElement] = firstElement;
        }
        else {
          newColumn.push_back(replacement->second.first);
          newColumn.push_back(replacement->second.second);
          columns->_toFirst.erase(oldElement);
          columns->_toFirst[replacement->second.first] = firstElement;
          columns->_toFirst[replacement->second.second] = firstElement;
        }
      }
    }
    columns->_elemColumns = std::move(newElemColumns);
  }

  void splitLowQualityQuads(GFace *gf, double minqual,
                            double minimumDiagonalLength,
                            double maximumDiagonalLength)
  {
    std::vector<MQuadrangle *> qds;
    std::map<MElement *, std::pair<MElement *, MElement *>> change;
    auto diagonalAllowed = [&](MVertex *a, MVertex *b) {
      const double dx = a->x() - b->x();
      const double dy = a->y() - b->y();
      const double dz = a->z() - b->z();
      const double length = std::sqrt(dx * dx + dy * dy + dz * dz);
      double scale = std::max({1., length, minimumDiagonalLength});
      if(maximumDiagonalLength > 0.)
        scale = std::max(scale, maximumDiagonalLength);
      const double tolerance = 1.e-10 * scale;
      return std::isfinite(length) && length > 0. &&
             (minimumDiagonalLength <= 0. ||
              length >= minimumDiagonalLength - tolerance) &&
             (maximumDiagonalLength <= 0. ||
              length <= maximumDiagonalLength + tolerance);
    };
    for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
      MQuadrangle *q = gf->quadrangles[i];
      if(q->etaShapeMeasure() < minqual + 1e-12) {
        const bool diagonal1Allowed =
          diagonalAllowed(q->getVertex(0), q->getVertex(2));
        const bool diagonal2Allowed =
          diagonalAllowed(q->getVertex(1), q->getVertex(3));
        if(!diagonal1Allowed && !diagonal2Allowed) {
          qds.push_back(q);
          continue;
        }
        MTriangle *t11 =
          new MTriangle(q->getVertex(0), q->getVertex(1), q->getVertex(2));
        MTriangle *t12 =
          new MTriangle(q->getVertex(2), q->getVertex(3), q->getVertex(0));
        MTriangle *t21 =
          new MTriangle(q->getVertex(1), q->getVertex(2), q->getVertex(3));
        MTriangle *t22 =
          new MTriangle(q->getVertex(3), q->getVertex(0), q->getVertex(1));
        double qual1 =
          std::min(t11->gammaShapeMeasure(), t12->gammaShapeMeasure());
        double qual2 =
          std::min(t21->gammaShapeMeasure(), t22->gammaShapeMeasure());
        double ori2 = dot(t21->getFace(0).normal(), t22->getFace(0).normal());
        // choose (t11, t12) if it leads to the best quality OR if choosing
        // (t21, t22) would revert the orientation (which can happen if q is not
        // convex)
        if(diagonal1Allowed &&
           (!diagonal2Allowed || qual1 > qual2 || ori2 < 0)) {
          gf->triangles.push_back(t11);
          gf->triangles.push_back(t12);
          change[q] = std::make_pair(t11, t12);
          delete t21;
          delete t22;
        }
        else if(diagonal2Allowed && ori2 >= 0.) {
          gf->triangles.push_back(t21);
          gf->triangles.push_back(t22);
          change[q] = std::make_pair(t21, t22);
          delete t11;
          delete t12;
        }
        else {
          qds.push_back(q);
          delete t11;
          delete t12;
          delete t21;
          delete t22;
          continue;
        }
        delete q;
      }
      else {
        qds.push_back(q);
      }
    }
    gf->quadrangles = qds;
    updateBoundaryLayerColumnsAfterQuadSplits(gf, change);
  }

  namespace {
    struct TrianglePairPlanarity {
      double angleDegrees = std::numeric_limits<double>::infinity();
      double minimumGamma = -std::numeric_limits<double>::infinity();
      bool valid = false;
    };

    using QuadrangleVertices = std::array<MVertex *, 4>;
    using QuadrangleParameters = std::array<SPoint2, 4>;
    using TriangleCorners = std::array<std::size_t, 3>;

    SVector3 cornerTriangleNormal(MVertex *a, MVertex *b, MVertex *c)
    {
      const SVector3 ab(b->x() - a->x(), b->y() - a->y(), b->z() - a->z());
      const SVector3 ac(c->x() - a->x(), c->y() - a->y(), c->z() - a->z());
      return crossprod(ab, ac);
    }

    double squaredDistance(MVertex *a, MVertex *b)
    {
      const double dx = a->x() - b->x();
      const double dy = a->y() - b->y();
      const double dz = a->z() - b->z();
      return dx * dx + dy * dy + dz * dz;
    }

    double orientation2d(const SPoint2 &a, const SPoint2 &b, const SPoint2 &c)
    {
      return (b.x() - a.x()) * (c.y() - a.y()) -
             (b.y() - a.y()) * (c.x() - a.x());
    }

    double parametricAreaTolerance(const QuadrangleParameters &parameters)
    {
      double minimum[2] = {parameters[0].x(), parameters[0].y()};
      double maximum[2] = {parameters[0].x(), parameters[0].y()};
      for(const SPoint2 &parameter : parameters) {
        minimum[0] = std::min(minimum[0], parameter.x());
        minimum[1] = std::min(minimum[1], parameter.y());
        maximum[0] = std::max(maximum[0], parameter.x());
        maximum[1] = std::max(maximum[1], parameter.y());
      }
      const double scale2 = std::pow(maximum[0] - minimum[0], 2) +
                            std::pow(maximum[1] - minimum[1], 2);
      return 1.e-12 * std::max(scale2, std::numeric_limits<double>::min());
    }

    bool quadrangleParameters(GFace *face, const QuadrangleVertices &vertices,
                              QuadrangleParameters &parameters)
    {
      if(!face) return false;
      for(std::size_t i = 0; i < vertices.size(); ++i) {
        if(!vertices[i] ||
           !reparamMeshVertexOnFace(vertices[i], face, parameters[i], true,
                                    false) ||
           !std::isfinite(parameters[i].x()) ||
           !std::isfinite(parameters[i].y()))
          return false;
      }

      // Keep a small quadrangle contiguous when it straddles a periodic seam.
      // reparamMeshVertexOnFace() can return either equivalent branch when seam
      // failure is disabled; choose the branch closest to the preceding corner.
      for(int direction = 0; direction < 2; ++direction) {
        if(!face->periodic(direction)) continue;
        const double period = std::abs(face->period(direction));
        if(!std::isfinite(period) || !(period > 0.)) return false;
        for(std::size_t i = 1; i < parameters.size(); ++i) {
          const double previous = parameters[i - 1][direction];
          double &current = parameters[i][direction];
          current += std::round((previous - current) / period) * period;
        }
      }
      return true;
    }

    bool parametricallyStrictlyConvex(const QuadrangleParameters &parameters)
    {
      const double tolerance = parametricAreaTolerance(parameters);
      double referenceTurn = 0.;
      for(std::size_t i = 0; i < parameters.size(); ++i) {
        const double turn =
          orientation2d(parameters[i], parameters[(i + 1) % parameters.size()],
                        parameters[(i + 2) % parameters.size()]);
        if(!std::isfinite(turn) || std::abs(turn) <= tolerance) return false;
        if(referenceTurn == 0.)
          referenceTurn = turn;
        else if((referenceTurn > 0.) != (turn > 0.))
          return false;
      }
      return true;
    }

    double trianglePairNormalAngle(const QuadrangleVertices &vertices,
                                   const TriangleCorners &firstCorners,
                                   const TriangleCorners &secondCorners)
    {
      const SVector3 first = cornerTriangleNormal(vertices[firstCorners[0]],
                                                  vertices[firstCorners[1]],
                                                  vertices[firstCorners[2]]);
      const SVector3 second = cornerTriangleNormal(vertices[secondCorners[0]],
                                                   vertices[secondCorners[1]],
                                                   vertices[secondCorners[2]]);
      const double firstNorm = first.norm();
      const double secondNorm = second.norm();
      if(!std::isfinite(firstNorm) || !std::isfinite(secondNorm) ||
         !(firstNorm > 0.) || !(secondNorm > 0.))
        return std::numeric_limits<double>::infinity();
      const double normalAngle = angle(first, second) * 180. / M_PI;
      return std::isfinite(normalAngle) ?
               normalAngle :
               std::numeric_limits<double>::infinity();
    }

    TrianglePairPlanarity
    trianglePairPlanarity(GFace *face, const QuadrangleVertices &vertices,
                          const QuadrangleParameters &parameters,
                          const TriangleCorners &firstCorners,
                          const TriangleCorners &secondCorners,
                          bool requireFaceNormal)
    {
      const double parameterTolerance = parametricAreaTolerance(parameters);
      const double firstArea =
        orientation2d(parameters[firstCorners[0]], parameters[firstCorners[1]],
                      parameters[firstCorners[2]]);
      const double secondArea = orientation2d(parameters[secondCorners[0]],
                                              parameters[secondCorners[1]],
                                              parameters[secondCorners[2]]);
      const bool parametricallyValid =
        std::isfinite(firstArea) && std::isfinite(secondArea) &&
        ((firstArea > parameterTolerance && secondArea > parameterTolerance) ||
         (firstArea < -parameterTolerance && secondArea < -parameterTolerance));
      if(!parametricallyValid) return {};

      const SVector3 first = cornerTriangleNormal(vertices[firstCorners[0]],
                                                  vertices[firstCorners[1]],
                                                  vertices[firstCorners[2]]);
      const SVector3 second = cornerTriangleNormal(vertices[secondCorners[0]],
                                                   vertices[secondCorners[1]],
                                                   vertices[secondCorners[2]]);
      const double firstNorm = first.norm();
      const double secondNorm = second.norm();
      double physicalScale2 = 0.;
      for(std::size_t i = 0; i < vertices.size(); ++i)
        for(std::size_t j = i + 1; j < vertices.size(); ++j)
          physicalScale2 =
            std::max(physicalScale2, squaredDistance(vertices[i], vertices[j]));
      const double normalTolerance =
        1.e-12 * std::max(physicalScale2, std::numeric_limits<double>::min());
      if(!std::isfinite(firstNorm) || !std::isfinite(secondNorm) ||
         !(firstNorm > normalTolerance) || !(secondNorm > normalTolerance))
        return {};

      // The signed areas preserve the intrinsic face orientation; the physical
      // normals and gamma checks reject degenerate diagonal triangles. A caller
      // can additionally require sampled agreement with the geometric normal.
      if(requireFaceNormal) {
        const auto agreesWithCadNormal = [face, &parameters](
                                           const TriangleCorners &corners,
                                           const SVector3 &physicalNormal,
                                           double physicalNormalNorm) {
          static const double weights[4][3] = {{1. / 3., 1. / 3., 1. / 3.},
                                               {.98, .01, .01},
                                               {.01, .98, .01},
                                               {.01, .01, .98}};
          bool foundPositiveSample = false;
          for(const auto &weight : weights) {
            SPoint2 sample;
            sample[0] = 0.;
            sample[1] = 0.;
            for(std::size_t i = 0; i < 3; ++i) {
              sample[0] += weight[i] * parameters[corners[i]].x();
              sample[1] += weight[i] * parameters[corners[i]].y();
            }
            if(!std::isfinite(sample.x()) || !std::isfinite(sample.y()) ||
               !face->containsParam(sample))
              continue;
            SVector3 cadNormal;
            try {
              cadNormal = face->normal(sample);
            } catch(...) {
              // Splitting is planned transactionally. A geometry-query
              // failure makes this sample abstain without emitting a fatal
              // mesh error or modifying the face.
              continue;
            }
            const double cadNormalNorm = cadNormal.norm();
            if(!std::isfinite(cadNormal.x()) || !std::isfinite(cadNormal.y()) ||
               !std::isfinite(cadNormal.z()) || !std::isfinite(cadNormalNorm) ||
               !(cadNormalNorm > 0.))
              continue;
            const double scalarProduct = dot(physicalNormal, cadNormal);
            const double tolerance =
              1.e-10 * physicalNormalNorm * cadNormalNorm;
            if(!std::isfinite(scalarProduct)) continue;
            if(scalarProduct <= tolerance) return false;
            foundPositiveSample = true;
          }
          return foundPositiveSample;
        };
        if(!agreesWithCadNormal(firstCorners, first, firstNorm) ||
           !agreesWithCadNormal(secondCorners, second, secondNorm))
          return {};
      }

      const double normalAngle = angle(first, second) * 180. / M_PI;
      if(!std::isfinite(normalAngle)) return {};

      MTriangle firstTriangle(vertices[firstCorners[0]],
                              vertices[firstCorners[1]],
                              vertices[firstCorners[2]]);
      MTriangle secondTriangle(vertices[secondCorners[0]],
                               vertices[secondCorners[1]],
                               vertices[secondCorners[2]]);
      const double firstGamma = firstTriangle.gammaShapeMeasure();
      const double secondGamma = secondTriangle.gammaShapeMeasure();
      if(!std::isfinite(firstGamma) || !std::isfinite(secondGamma) ||
         !(firstGamma > 0.) || !(secondGamma > 0.))
        return {};
      return {normalAngle, std::min(firstGamma, secondGamma), true};
    }

    void addPrimaryEdges(MElement *element,
                         std::set<MEdge, MEdgeLessThan> &edges)
    {
      if(!element) return;
      const std::size_t count = element->getNumPrimaryVertices();
      for(std::size_t i = 0; i < count; ++i)
        edges.insert(
          MEdge(element->getVertex(static_cast<int>(i)),
                element->getVertex(static_cast<int>((i + 1) % count))));
    }
  } // namespace

  WarpedQuadrangleSplitResult splitExcessivelyWarpedQuadrangles(
    GFace *gf, double maximumWarpingDegrees,
    const QuadrangleDiagonalAdmissibility &diagonalAdmissible,
    const QuadrangleSplitTransactionAdmissibility &transactionAdmissible,
    const QuadrangleSplitSelection &selection,
    const QuadrangleSplitRequirement &additionalRequirement,
    const QuadrangleSplitGeometryAdmissibility &geometryAdmissible,
    bool requireFaceNormal,
    const QuadrangleSplitTransactionCommit &transactionCommit)
  {
    WarpedQuadrangleSplitResult result;
    if(!gf || !std::isfinite(maximumWarpingDegrees) ||
       !(maximumWarpingDegrees > 0.))
      return result;

    std::set<MEdge, MEdgeLessThan> existingEdges;
    for(MTriangle *triangle : gf->triangles)
      addPrimaryEdges(triangle, existingEdges);
    for(MQuadrangle *quad : gf->quadrangles)
      addPrimaryEdges(quad, existingEdges);

    struct PlannedQuadrangleSplit {
      MQuadrangle *quadrangle = nullptr;
      MTriangle *first = nullptr;
      MTriangle *second = nullptr;
    };
    std::vector<PlannedQuadrangleSplit> plans;
    for(MQuadrangle *quad : gf->quadrangles) {
      if(selection && !selection(gf, quad)) continue;
      if(!quad || quad->getNumPrimaryVertices() != 4) {
        ++result.rejectedInvalid;
        continue;
      }
      std::set<MVertex *> primaryVertices;
      bool validPrimaryVertices = true;
      for(int i = 0; i < 4; ++i) {
        MVertex *vertex = quad->getVertex(i);
        if(!vertex || !primaryVertices.insert(vertex).second) {
          validPrimaryVertices = false;
          break;
        }
      }
      if(!validPrimaryVertices) {
        ++result.rejectedInvalid;
        continue;
      }
      const QuadrangleVertices vertices = {
        quad->getVertex(0), quad->getVertex(1), quad->getVertex(2),
        quad->getVertex(3)};
      MVertex *v0 = vertices[0];
      MVertex *v1 = vertices[1];
      MVertex *v2 = vertices[2];
      MVertex *v3 = vertices[3];
      QuadrangleParameters parameters;
      const bool parametrized = quadrangleParameters(gf, vertices, parameters);
      TrianglePairPlanarity diagonal02, diagonal13;
      if(parametrized) {
        diagonal02 = trianglePairPlanarity(gf, vertices, parameters, {0, 1, 2},
                                           {2, 3, 0}, requireFaceNormal);
        diagonal13 = trianglePairPlanarity(gf, vertices, parameters, {1, 2, 3},
                                           {3, 0, 1}, requireFaceNormal);
      }
      const double warping =
        std::max(trianglePairNormalAngle(vertices, {0, 1, 2}, {2, 3, 0}),
                 trianglePairNormalAngle(vertices, {1, 2, 3}, {3, 0, 1}));
      const bool excessiveWarping = !(warping < maximumWarpingDegrees);
      if(excessiveWarping) ++result.excessiveWarping;
      const double eta = quad->etaShapeMeasure();
      const bool nonConvexOrInvalid =
        !parametrized || !parametricallyStrictlyConvex(parameters) ||
        !std::isfinite(eta) || !(eta > 0.);
      if(nonConvexOrInvalid) ++result.nonConvexOrInvalid;
      const bool additionallyRequired =
        additionalRequirement && additionalRequirement(gf, quad);
      if(additionallyRequired) ++result.selectedByRequirement;
      if(!excessiveWarping && !nonConvexOrInvalid && !additionallyRequired)
        continue;

      if(quad->getNumVertices() != 4) {
        ++result.rejectedUnsupportedOrder;
        continue;
      }

      const bool geometry02 =
        diagonal02.valid &&
        existingEdges.find(MEdge(v0, v2)) == existingEdges.end();
      const bool geometry13 =
        diagonal13.valid &&
        existingEdges.find(MEdge(v1, v3)) == existingEdges.end();
      if(!geometry02 && !geometry13) {
        ++result.rejectedInvalid;
        continue;
      }

      const bool admissible02 =
        geometry02 && (!diagonalAdmissible || diagonalAdmissible(gf, v0, v2));
      const bool admissible13 =
        geometry13 && (!diagonalAdmissible || diagonalAdmissible(gf, v1, v3));
      if(!admissible02 && !admissible13) {
        ++result.rejectedBySize;
        continue;
      }

      auto geometryAccepts = [&](bool useDiagonal02) {
        if(!geometryAdmissible) return true;
        if(useDiagonal02) {
          MTriangle first(v0, v1, v2);
          MTriangle second(v2, v3, v0);
          first.setPartition(quad->getPartition());
          second.setPartition(quad->getPartition());
          first.setVisibility(quad->getVisibility());
          second.setVisibility(quad->getVisibility());
          return geometryAdmissible(gf, quad, &first, &second);
        }
        MTriangle first(v1, v2, v3);
        MTriangle second(v3, v0, v1);
        first.setPartition(quad->getPartition());
        second.setPartition(quad->getPartition());
        first.setVisibility(quad->getVisibility());
        second.setVisibility(quad->getVisibility());
        return geometryAdmissible(gf, quad, &first, &second);
      };
      const bool cadAdmissible02 = admissible02 && geometryAccepts(true);
      const bool cadAdmissible13 = admissible13 && geometryAccepts(false);
      if(!cadAdmissible02 && !cadAdmissible13) {
        ++result.rejectedByGeometry;
        continue;
      }

      bool useDiagonal02 = cadAdmissible02 && !cadAdmissible13;
      if(cadAdmissible02 && cadAdmissible13) {
        const double angleTolerance =
          1.e-12 *
          std::max({1., diagonal02.angleDegrees, diagonal13.angleDegrees});
        if(diagonal02.angleDegrees < diagonal13.angleDegrees - angleTolerance)
          useDiagonal02 = true;
        else if(diagonal13.angleDegrees <
                diagonal02.angleDegrees - angleTolerance)
          useDiagonal02 = false;
        else
          useDiagonal02 = diagonal02.minimumGamma >= diagonal13.minimumGamma;
      }

      MTriangle *first =
        useDiagonal02 ? new MTriangle(v0, v1, v2) : new MTriangle(v1, v2, v3);
      MTriangle *second =
        useDiagonal02 ? new MTriangle(v2, v3, v0) : new MTriangle(v3, v0, v1);
      first->setPartition(quad->getPartition());
      second->setPartition(quad->getPartition());
      first->setVisibility(quad->getVisibility());
      second->setVisibility(quad->getVisibility());
      plans.push_back({quad, first, second});
      existingEdges.insert(useDiagonal02 ? MEdge(v0, v2) : MEdge(v1, v3));
    }

    // Rejected quadrangles remain untouched. The admissible subset is still a
    // single mesh-topology transaction, so a caller can validate and optionally
    // commit every safe split before this routine mutates public face storage.
    std::vector<MElement *> removed;
    std::vector<MElement *> inserted;
    removed.reserve(plans.size());
    inserted.reserve(2 * plans.size());
    for(const PlannedQuadrangleSplit &plan : plans) {
      removed.push_back(plan.quadrangle);
      inserted.push_back(plan.first);
      inserted.push_back(plan.second);
    }
    if(transactionAdmissible && !plans.empty()) {
      if(!transactionAdmissible(gf, removed, inserted)) {
        for(const PlannedQuadrangleSplit &plan : plans) {
          delete plan.first;
          delete plan.second;
        }
        // The public result has no separate topological-transaction bucket;
        // report this as an invalid replacement while preserving atomicity.
        ++result.rejectedInvalid;
        return result;
      }
    }

    std::map<MElement *, std::pair<MElement *, MElement *>> change;
    for(const PlannedQuadrangleSplit &plan : plans)
      change[plan.quadrangle] = {plan.first, plan.second};
    if(transactionCommit && !plans.empty()) {
      if(!transactionCommit(gf, removed, inserted)) {
        for(const PlannedQuadrangleSplit &plan : plans) {
          delete plan.first;
          delete plan.second;
        }
        ++result.rejectedInvalid;
        return result;
      }
      result.split = plans.size();
      updateBoundaryLayerColumnsAfterQuadSplits(gf, change);
      return result;
    }

    std::vector<MQuadrangle *> retained;
    retained.reserve(gf->quadrangles.size() - plans.size());
    std::map<MQuadrangle *, std::size_t, std::less<MQuadrangle *>> planIndex;
    for(std::size_t i = 0; i < plans.size(); ++i)
      planIndex[plans[i].quadrangle] = i;
    for(MQuadrangle *quad : gf->quadrangles) {
      const auto found = planIndex.find(quad);
      if(found == planIndex.end()) {
        retained.push_back(quad);
        continue;
      }
      PlannedQuadrangleSplit &plan = plans[found->second];
      gf->triangles.push_back(plan.first);
      gf->triangles.push_back(plan.second);
      delete quad;
    }
    result.split = plans.size();
    gf->quadrangles = std::move(retained);
    updateBoundaryLayerColumnsAfterQuadSplits(gf, change);
    return result;
  }

} // namespace QuadOptimizer
