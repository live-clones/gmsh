// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_DELAUNAY_H
#define MESH_GFACE_DELAUNAY_H

// Entry points of the 2D Delaunay surface meshers. The data structures the
// kernels themselves work on are internal (meshGFaceTri3.h for the classic
// ones, meshGFaceDelaunayFlat.cpp for the flat ones).

#include <map>
#include <vector>
#include "SPoint2.h"

class GFace;
class MVertex;
class MTriangle;
class MEdge;

void buildMetric(GFace *gf, double *uv, double *metric);
int inCircumCircleAniso(GFace *gf, double *p1, double *p2, double *p3,
                        double *p4, double *metric);
void bowyerWatson(
  GFace *gf, int MAXPNT = 1000000000,
  std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void bowyerWatsonFrontal(
  GFace *gf, std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr,
  std::vector<SPoint2> *true_boundary = nullptr);
void bowyerWatsonFrontalFlat(
  GFace *gf, std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr,
  std::vector<SPoint2> *true_boundary = nullptr);
void bowyerWatsonFlat(
  GFace *gf, int MAXPNT = 1000000000,
  std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void bowyerWatsonFrontalLayers(
  GFace *gf, bool quad, std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void bowyerWatsonParallelograms(
  GFace *gf, std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);
void buildBackgroundMesh(
  GFace *gf, bool crossFieldClosestPoint = false,
  std::map<MVertex *, MVertex *> *equivalence = nullptr,
  std::map<MVertex *, SPoint2> *parametricCoordinates = nullptr);

void delaunayMeshIn2D(std::vector<MVertex *> &, std::vector<MTriangle *> &,
                      bool removeBox = true,
                      std::vector<MEdge> *edgesToRecover = nullptr,
                      bool hilbertSort = true);

#endif
