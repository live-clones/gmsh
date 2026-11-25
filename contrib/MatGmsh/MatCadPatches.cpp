#include "cadSurfacePatchAnalyzer.h"

#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "Range.h"
#include "SPoint2.h"
#include "SVector3.h"
#include <gmsh.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <limits>
#include <queue>
#include <set>
#include <stdexcept>
#include <unordered_map>

namespace {
double transverseNormalCurvature(const SVector3 &edgeTangent,
                                 const SVector3 &normal,
                                 const SVector3 &dirMax,
                                 const SVector3 &dirMin,
                                 double curvatureMax,
                                 double curvatureMin)
{
  SVector3 transverse = crossprod(normal, edgeTangent);
  const double norm = transverse.norm();
  if(norm <= 1.e-30) return 0.;
  transverse *= 1. / norm;
  const double maxProjection = dot(transverse, dirMax);
  const double minProjection = dot(transverse, dirMin);
  return curvatureMax * maxProjection * maxProjection +
         curvatureMin * minProjection * minProjection;
}

double relativeCurvatureJump(double a, double b, double noiseFloor)
{
  const double scale = std::max({std::abs(a), std::abs(b), noiseFloor});
  return std::abs(a - b) / scale;
}
}

CadSurfacePatchAnalyzer::CadSurfacePatchAnalyzer()
  : CadSurfacePatchAnalyzer(Options{})
{
}

CadSurfacePatchAnalyzer::CadSurfacePatchAnalyzer(Options optionsIn)
  : options(optionsIn)
{
  if(options.samplesPerEdge < 2) {
    throw std::runtime_error("CAD patch analysis requires at least two edge samples");
  }
  if(!std::isfinite(options.minAbsNormalDot) ||
     options.minAbsNormalDot < 0.0 || options.minAbsNormalDot > 1.0) {
    throw std::runtime_error("CAD patch normal threshold must be in [0, 1]");
  }
  if(!std::isfinite(options.supportPatchMinAbsNormalDot) ||
     options.supportPatchMinAbsNormalDot < 0.0 ||
     options.supportPatchMinAbsNormalDot > 1.0) {
    throw std::runtime_error(
        "CAD support patch normal threshold must be in [0, 1]");
  }
  if(!std::isfinite(options.maxRelativeTransverseCurvatureJump) ||
     options.maxRelativeTransverseCurvatureJump < 0.) {
    throw std::runtime_error("CAD patch curvature threshold must be non-negative");
  }
}

double CadSurfacePatchAnalyzer::edgeNormalCompatibility(
    GEdge *edge, GFace *a, GFace *b) const
{
  const Range<double> bounds = edge->parBounds(0);
  if(!std::isfinite(bounds.low()) || !std::isfinite(bounds.high()) ||
     bounds.high() <= bounds.low()) {
    return 0.0;
  }

  double minimum = 1.0;
  // Avoid the vertices: normals and parametrizations are often singular there.
  for(int sample = 0; sample < options.samplesPerEdge; ++sample) {
    const double alpha =
        (static_cast<double>(sample) + 0.5) /
        static_cast<double>(options.samplesPerEdge);
    const double parameter =
        (1.0 - alpha) * bounds.low() + alpha * bounds.high();
    const SPoint2 uvA = edge->reparamOnFace(a, parameter, 1);
    const SPoint2 uvB = edge->reparamOnFace(b, parameter, 1);
    const SVector3 normalA = a->normal(uvA);
    const SVector3 normalB = b->normal(uvB);
    const double normA = normalA.norm();
    const double normB = normalB.norm();
    if(normA <= 1e-30 || normB <= 1e-30) {
      return 0.0;
    }
    minimum = std::min(minimum,
                       std::abs(dot(normalA, normalB) / (normA * normB)));
  }
  return minimum;
}

CadSurfacePatchAnalyzer::Result
CadSurfacePatchAnalyzer::analyze(GModel *model) const
{
  if(!model) {
    throw std::runtime_error("CAD patch analysis requires a GModel");
  }

  Result result;
  std::map<int, GFace *> faces;
  std::map<int, std::vector<int>> adjacency;

  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    GFace *face = *it;
    faces[face->tag()] = face;
  }

  for(const auto &entry : faces) {
    GFace *face = entry.second;
    for(GEdge *edge : face->edges()) {
      const std::vector<GFace *> incident = edge->faces();
      if(incident.empty() || incident.front() != face) continue;

      Transition transition;
      transition.edgeTag = edge->tag();
      transition.incidentFaceCount = static_cast<int>(incident.size());
      if(incident.size() == 2) {
        transition.faceA = incident[0]->tag();
        transition.faceB = incident[1]->tag();
        transition.minAbsNormalDot =
            edgeNormalCompatibility(edge, incident[0], incident[1]);
        const Range<double> bounds = edge->parBounds(0);
        for(int sample = 0; sample < options.samplesPerEdge; ++sample) {
          const double alpha = (sample + 0.5) / options.samplesPerEdge;
          const double t = (1. - alpha) * bounds.low() + alpha * bounds.high();
          const SPoint2 uvA = edge->reparamOnFace(incident[0], t, 1);
          const SPoint2 uvB = edge->reparamOnFace(incident[1], t, 1);
          const SVector3 nA = incident[0]->normal(uvA);
          const SVector3 nB = incident[1]->normal(uvB);
          SVector3 dMaxA, dMinA, dMaxB, dMinB;
          double kMaxA = 0., kMinA = 0., kMaxB = 0., kMinB = 0.;
          incident[0]->curvatures(uvA, dMaxA, dMinA, kMaxA, kMinA);
          incident[1]->curvatures(uvB, dMaxB, dMinB, kMaxB, kMinB);
          const SVector3 tangent = edge->firstDer(t);
          const double kA = transverseNormalCurvature(
              tangent, nA, dMaxA, dMinA, kMaxA, kMinA);
          double kB = transverseNormalCurvature(
              tangent, nB, dMaxB, dMinB, kMaxB, kMinB);
          if(dot(nA, nB) < 0.) kB = -kB;
          transition.maxRelativeTransverseCurvatureJump = std::max(
              transition.maxRelativeTransverseCurvatureJump,
              relativeCurvatureJump(kA, kB, options.curvatureNoiseFloor));
        }
        transition.accepted = transition.minAbsNormalDot >= options.minAbsNormalDot &&
          (!options.useCurvatureCompatibility ||
           transition.maxRelativeTransverseCurvatureJump <=
             options.maxRelativeTransverseCurvatureJump);
        if(transition.accepted) {
          adjacency[transition.faceA].push_back(transition.faceB);
          adjacency[transition.faceB].push_back(transition.faceA);
        }
      }
      result.transitions.push_back(transition);
    }
  }

  int nextPatch = 0;
  std::queue<int> pending;
  for(const auto &entry : faces) {
    const int seed = entry.first;
    if(result.patchByFaceTag.count(seed) != 0) continue;
    result.faceTagsByPatch.emplace_back();
    result.patchByFaceTag[seed] = nextPatch;
    pending.push(seed);
    while(!pending.empty()) {
      const int face = pending.front();
      pending.pop();
      result.faceTagsByPatch.back().push_back(face);
      for(int neighbor : adjacency[face]) {
        if(result.patchByFaceTag.emplace(neighbor, nextPatch).second) {
          pending.push(neighbor);
        }
      }
    }
    std::sort(result.faceTagsByPatch.back().begin(),
              result.faceTagsByPatch.back().end());
    ++nextPatch;
  }

  for(const auto &entry : result.patchByFaceTag)
    result.patchesByFaceTag[entry.first].insert(entry.second);

  return result;
}

CadSurfacePatchAnalyzer::Result
CadSurfacePatchAnalyzer::analyzeCurrentModel() const
{
  Result result;
  gmsh::vectorpair faceEntities;
  gmsh::vectorpair edgeEntities;
  gmsh::model::getEntities(faceEntities, 2);
  gmsh::model::getEntities(edgeEntities, 1);
  std::map<int, std::vector<int>> adjacency;

  for(const auto &entity : edgeEntities) {
    const int edgeTag = entity.second;
    std::vector<int> incidentFaces, vertices;
    gmsh::model::getAdjacencies(1, edgeTag, incidentFaces, vertices);
    Transition transition;
    transition.edgeTag = edgeTag;
    transition.incidentFaceCount = static_cast<int>(incidentFaces.size());
    if(incidentFaces.size() == 2 && incidentFaces[0] != incidentFaces[1]) {
      transition.faceA = incidentFaces[0];
      transition.faceB = incidentFaces[1];
      std::vector<double> lower, upper;
      gmsh::model::getParametrizationBounds(1, edgeTag, lower, upper);
      transition.minAbsNormalDot = 1.0;
      if(lower.empty() || upper.empty() || !std::isfinite(lower[0]) ||
         !std::isfinite(upper[0]) || upper[0] <= lower[0]) {
        transition.minAbsNormalDot = 0.0;
      }
      else {
        for(int sample = 0; sample < options.samplesPerEdge; ++sample) {
          const double alpha = (sample + 0.5) / options.samplesPerEdge;
          const double t = (1.0 - alpha) * lower[0] + alpha * upper[0];
          std::vector<double> uvA, uvB, nA, nB, tangent;
          // The shared CAD edge already has a parametrization on each face.
          // Use it directly: inverting its 3D points can fail on thin or
          // tolerance-imperfect faces even when their boundary pcurves exist.
          // Select the forward pcurve, as in analyze(GModel *).
          gmsh::model::reparametrizeOnSurface(
              1, edgeTag, {t}, transition.faceA, uvA, 1);
          gmsh::model::reparametrizeOnSurface(
              1, edgeTag, {t}, transition.faceB, uvB, 1);
          if(uvA.size() != 2 || uvB.size() != 2 ||
             !std::isfinite(uvA[0]) || !std::isfinite(uvA[1]) ||
             !std::isfinite(uvB[0]) || !std::isfinite(uvB[1])) {
            transition.minAbsNormalDot = 0.0;
            break;
          }
          gmsh::model::getNormal(transition.faceA, uvA, nA);
          gmsh::model::getNormal(transition.faceB, uvB, nB);
          gmsh::model::getDerivative(1, edgeTag, {t}, tangent);
          if(nA.size() < 3 || nB.size() < 3) {
            transition.minAbsNormalDot = 0.0;
            break;
          }
          const double normA = std::sqrt(nA[0]*nA[0]+nA[1]*nA[1]+nA[2]*nA[2]);
          const double normB = std::sqrt(nB[0]*nB[0]+nB[1]*nB[1]+nB[2]*nB[2]);
          if(!std::isfinite(normA) || !std::isfinite(normB) ||
             normA <= 1e-30 || normB <= 1e-30) {
            transition.minAbsNormalDot = 0.0;
            break;
          }
          const double cosine = std::abs(
              (nA[0]*nB[0]+nA[1]*nB[1]+nA[2]*nB[2]) / (normA*normB));
          transition.minAbsNormalDot =
              std::min(transition.minAbsNormalDot, cosine);
          std::vector<double> kMaxA, kMinA, dMaxA, dMinA;
          std::vector<double> kMaxB, kMinB, dMaxB, dMinB;
          gmsh::model::getPrincipalCurvatures(
              transition.faceA, uvA, kMaxA, kMinA, dMaxA, dMinA);
          gmsh::model::getPrincipalCurvatures(
              transition.faceB, uvB, kMaxB, kMinB, dMaxB, dMinB);
          if(tangent.size() < 3 || kMaxA.empty() || kMinA.empty() ||
             kMaxB.empty() || kMinB.empty() || dMaxA.size() < 3 ||
             dMinA.size() < 3 || dMaxB.size() < 3 || dMinB.size() < 3) {
            transition.maxRelativeTransverseCurvatureJump =
                std::numeric_limits<double>::infinity();
            break;
          }
          const SVector3 edgeTangent(tangent[0], tangent[1], tangent[2]);
          const SVector3 normalA(nA[0], nA[1], nA[2]);
          const SVector3 normalB(nB[0], nB[1], nB[2]);
          const double curvatureA = transverseNormalCurvature(
              edgeTangent, normalA,
              SVector3(dMaxA[0], dMaxA[1], dMaxA[2]),
              SVector3(dMinA[0], dMinA[1], dMinA[2]),
              kMaxA[0], kMinA[0]);
          double curvatureB = transverseNormalCurvature(
              edgeTangent, normalB,
              SVector3(dMaxB[0], dMaxB[1], dMaxB[2]),
              SVector3(dMinB[0], dMinB[1], dMinB[2]),
              kMaxB[0], kMinB[0]);
          if(nA[0]*nB[0] + nA[1]*nB[1] + nA[2]*nB[2] < 0.)
            curvatureB = -curvatureB;
          transition.maxRelativeTransverseCurvatureJump = std::max(
              transition.maxRelativeTransverseCurvatureJump,
              relativeCurvatureJump(curvatureA, curvatureB,
                                    options.curvatureNoiseFloor));
        }
      }
      transition.accepted = transition.minAbsNormalDot >= options.minAbsNormalDot &&
        (!options.useCurvatureCompatibility ||
         transition.maxRelativeTransverseCurvatureJump <=
           options.maxRelativeTransverseCurvatureJump);
      if(transition.accepted) {
        adjacency[transition.faceA].push_back(transition.faceB);
        adjacency[transition.faceB].push_back(transition.faceA);
      }
    }
    result.transitions.push_back(transition);
  }

  // Preserve the legacy curvature-aware partition for all existing filters.
  // The overlapping mechanical support cover built below is consumed only by
  // the mixed-branch segmentation.
  int nextLegacyPatch = 0;
  std::queue<int> pending;
  for(const auto &entity : faceEntities) {
    const int seed = entity.second;
    if(result.patchByFaceTag.count(seed)) continue;
    result.patchByFaceTag[seed] = nextLegacyPatch;
    pending.push(seed);
    while(!pending.empty()) {
      const int face = pending.front();
      pending.pop();
      for(int neighbor : adjacency[face]) {
        if(result.patchByFaceTag.emplace(neighbor, nextLegacyPatch).second)
          pending.push(neighbor);
      }
    }
    ++nextLegacyPatch;
  }

  // Mechanical support patches are not a partition of the CAD faces. A
  // fillet is part of every support that it connects. Detect analytic fillet
  // components first, remove them while assembling the supports, then attach
  // them back to all adjacent supports. In particular, never connect two
  // support components through a fillet.
  adjacency.clear();
  for(const Transition &transition : result.transitions) {
    if(transition.incidentFaceCount != 2 || transition.faceA < 0 ||
       transition.faceB < 0 ||
       transition.minAbsNormalDot < options.supportPatchMinAbsNormalDot)
      continue;
    adjacency[transition.faceA].push_back(transition.faceB);
    adjacency[transition.faceB].push_back(transition.faceA);
  }

  std::set<int> analyticFaces;
  for(const auto &entity : faceEntities) {
    std::string type;
    gmsh::model::getType(2, entity.second, type);
    if(type == "Cylinder" || type == "Torus" || type == "Sphere")
      analyticFaces.insert(entity.second);
  }

  std::set<int> visitedAnalyticFaces;
  for(int seed : analyticFaces) {
    if(!visitedAnalyticFaces.insert(seed).second) continue;
    std::vector<int> component;
    std::set<int> outsideFaces;
    pending.push(seed);
    while(!pending.empty()) {
      const int face = pending.front();
      pending.pop();
      component.push_back(face);
      for(int neighbor : adjacency[face]) {
        if(analyticFaces.count(neighbor)) {
          if(visitedAnalyticFaces.insert(neighbor).second)
            pending.push(neighbor);
        }
        else {
          outsideFaces.insert(neighbor);
        }
      }
    }
    // A usual cylindrical/toroidal/spherical support has sharp boundaries.
    // A fillet has at least two distinct tangent rails leading to supports.
    if(outsideFaces.size() < 2) continue;
    std::sort(component.begin(), component.end());
    result.filletFaceTagsByComponent.push_back(component);
    result.filletFaceTags.insert(component.begin(), component.end());
  }

  // Connected components of tangent non-fillet faces are the base supports.
  int nextPatch = 0;
  std::set<int> assignedSupportFaces;
  std::map<int, int> supportPatchByFaceTag;
  for(const auto &entity : faceEntities) {
    const int seed = entity.second;
    if(result.filletFaceTags.count(seed) ||
       !assignedSupportFaces.insert(seed).second)
      continue;
    result.faceTagsByPatch.emplace_back();
    supportPatchByFaceTag[seed] = nextPatch;
    result.patchesByFaceTag[seed].insert(nextPatch);
    pending.push(seed);
    while(!pending.empty()) {
      const int face = pending.front();
      pending.pop();
      result.faceTagsByPatch.back().push_back(face);
      for(int neighbor : adjacency[face]) {
        if(result.filletFaceTags.count(neighbor)) continue;
        if(assignedSupportFaces.insert(neighbor).second) {
          supportPatchByFaceTag[neighbor] = nextPatch;
          result.patchesByFaceTag[neighbor].insert(nextPatch);
          pending.push(neighbor);
        }
      }
    }
    ++nextPatch;
  }

  // Attach each fillet component to all of its tangent support patches. The
  // same CAD face can therefore legally occur in several faceTagsByPatch
  // vectors and carry several patch identifiers.
  for(const std::vector<int> &component : result.filletFaceTagsByComponent) {
    std::set<int> supportPatches;
    for(int face : component) {
      for(int neighbor : adjacency[face]) {
        if(result.filletFaceTags.count(neighbor)) continue;
        const auto patch = supportPatchByFaceTag.find(neighbor);
        if(patch != supportPatchByFaceTag.end())
          supportPatches.insert(patch->second);
      }
    }
    // Defensive fallback for a degenerate closed analytic component.
    if(supportPatches.empty()) {
      supportPatches.insert(nextPatch++);
      result.faceTagsByPatch.emplace_back();
    }
    for(int face : component) {
      result.patchesByFaceTag[face] = supportPatches;
      supportPatchByFaceTag[face] = *supportPatches.begin();
      for(int patch : supportPatches) {
        if(patch >= static_cast<int>(result.faceTagsByPatch.size()))
          result.faceTagsByPatch.resize(patch + 1);
        result.faceTagsByPatch[patch].push_back(face);
      }
    }
  }

  for(std::vector<int> &patchFaces : result.faceTagsByPatch) {
    std::sort(patchFaces.begin(), patchFaces.end());
    patchFaces.erase(std::unique(patchFaces.begin(), patchFaces.end()),
                     patchFaces.end());
  }
  return result;
}

