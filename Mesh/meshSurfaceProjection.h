// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_SURFACE_PROJECTION
#define MESH_SURFACE_PROJECTION

#include <vector>
#include <array>
#include <string>
#include "GPoint.h"

class GFace;
class MTriangle;

class SurfaceProjector {
  public:
    SurfaceProjector(): gf(NULL),tree(NULL),pc(NULL),pca(NULL) {}
    SurfaceProjector(GFace* gf); /* triangles read from GFace */
    ~SurfaceProjector();

    bool initialize(GFace* gf, const std::vector<MTriangle*>& triangles);

    GPoint closestPoint(const double query[3], size_t& cache, bool evalOnCAD = false, bool projectOnCAD = false) const;

    void show(const std::string& viewName);

  public:
    GFace* gf;
  protected:
    std::vector<std::array<std::array<double,3>,3 > >  triangles;
    std::vector<std::array<std::array<double,2>,3 > >  uvs;

    std::vector<std::vector<size_t> >                  idx2t;
    std::vector<std::array<size_t,3> >                 triangles_idx;

    void* tree;
    void* pc;
    void* pca;
};


class SVector3;

double projectPointOnTriangle(
    const SVector3& query,
    const SVector3& p1,
    const SVector3& p2,
    const SVector3& p3,
    SVector3& proj,
    double lambda[3]);

#endif
