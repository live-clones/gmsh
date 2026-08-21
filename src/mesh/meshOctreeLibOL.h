// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_OCTREE_LIB_OL
#define MESH_OCTREE_LIB_OL

#include <vector>
#include <array>
#include <string>
#include "GPoint.h"
#include "GFace.h"

class MTriangle;

// Project 3D points on a triangulated surface. If a parametrization is
// available, the UV are interpolated at the triangle projection. Not
// associated to the mesh elements of a GEntity, so it can be used on mesh
// sub-patches or on a background mesh.
class SurfaceProjector {
public:
  SurfaceProjector() : gf(NULL), OctIdx(0) {}
  SurfaceProjector(GFace *gf); /* read triangles and quads from GFace */
  SurfaceProjector(SurfaceProjector const &) = delete;
  SurfaceProjector &operator=(SurfaceProjector const &) = delete;
  ~SurfaceProjector();

  // Fill the triangles and uvs from the triangles, then build the octree,
  // overwriting the existing triangulation and octree if there is one. gf is
  // the CAD face containing the triangles; with useCADStl, build and use the
  // STL of that face instead. Returns true on success.
  bool initialize(GFace *gf, const std::vector<MTriangle *> &triangles, bool useCADStl = false);

  // Clear the triangulation and delete the octree.
  void clear();

  // Project with an analytical formula instead of a triangulation and an
  // octree, taking the parameters from gf. Supported shapes: sphere. Returns
  // true on success.
  bool setAnalyticalProjection(GFace *gf);

  // Get the point of the triangulated surface closest to query, given as 3D
  // coordinates. Check GPoint::succeeded() on the result to tell success from
  // failure.
  //
  // evalOnCAD: if a parametrization is available, evaluate the CAD mapping of
  //   the face at the interpolated UV
  // projectOnCAD: if a parametrization is available, call closestPoint from
  //   the CAD engine, with the interpolated UV as initial guess
  GPoint closestPoint(const double query[3], bool evalOnCAD = false,
                      bool projectOnCAD = false) const;

public:
  GFace *gf;

protected:
  std::vector<std::array<double, 3> > points;
  std::vector<std::array<int32_t, 3> > triangles;
  std::vector<std::array<std::array<double, 2>, 3> > triangle_uvs;
  std::vector<bool> triangle_no_uv_eval; /* no eval. at param. singularity */
  int64_t OctIdx; /* pointer to libOL octree (C structure) */

  /* For simple CAD shapes, we have analytical formula for projection */
  bool useAnalyticalFormula = false;
  GFace::GeomType analyticalShape = GFace::GeomType::Unknown;
  std::array<double, 10> analyticalParameters;
};



enum class libOLTypTag {  LolTypVer=1, LolTypEdg, LolTypTri, LolTypQad,
               LolTypTet,   LolTypPyr, LolTypPri, LolTypHex, LolNmbTyp };

class libOLwrapper {

  public:
    libOLwrapper(
        const std::vector<std::array<double,3> >& points,
        const std::vector<std::array<int32_t,2> >& edges,
        const std::vector<std::array<int32_t,3> >& triangles,
        const std::vector<std::array<int32_t,4> >& quads,
        const std::vector<std::array<int32_t,4> >& tetrahedra,
        const std::vector<std::array<int32_t,5> >& pyramids,
        const std::vector<std::array<int32_t,6> >& prisms,
        const std::vector<std::array<int32_t,8> >& hexahedra);

    ~libOLwrapper();

    int elementsInsideBoundingBox(libOLTypTag elementType,
        double* bboxMin, double* bboxMax,
        std::vector<int32_t>& elements);

  protected:
    std::vector<std::array<double,3> > points;
    std::vector<std::array<int32_t,2> > edges;
    std::vector<std::array<int32_t,3> > triangles;
    std::vector<std::array<int32_t,4> > quads;
    std::vector<std::array<int32_t,4> > tetrahedra;
    std::vector<std::array<int32_t,5> > pyramids;
    std::vector<std::array<int32_t,6> > prisms;
    std::vector<std::array<int32_t,8> > hexahedra;
    int64_t OctIdx; /* pointer to libOL octree (C structure) */

};

#endif
