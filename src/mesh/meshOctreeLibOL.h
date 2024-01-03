// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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

/**
 * @brief Class to project 3D points on a triangulated surface.
 *        If a parametrization is available, the UV are interpolated
 *        at the triangle projection.
 *        Not associated to the mesh elements of a GEntity, so it can be
 *        used on mesh sub-patches or on background mesh.
 */
class SurfaceProjector {
public:
  SurfaceProjector() : gf(NULL), OctIdx(0) {}
  SurfaceProjector(GFace *gf); /* read triangles and quads from GFace */
  SurfaceProjector(SurfaceProjector const &) = delete;
  SurfaceProjector &operator=(SurfaceProjector const &) = delete;
  ~SurfaceProjector();

  /**
   * @brief Fill the triangles and uvs from the triangles, then build the
   * octree. Overwrite existing triangulation/octree if there is one.
   *
   * @param gf The CAD face containing the triangles
   * @param triangles The triangles used to build the triangulated geometry
   * support
   * @param useCADStl If true, build and use the STL of the CAD face
   *
   * @return true if success
   */
  bool initialize(GFace *gf, const std::vector<MTriangle *> &triangles, bool useCADStl = false);

  /**
   * @brief Clear the triangulation and delete the octree
   */
  void clear();

  /**
   * @brief The SurfaceProjector can project with an analytical formula instead
   * of a triangulation and a octree Supported shapes: Sphere
   *
   * @param gf The face containing the analytical parameters
   *
   * @return true if success
   */
  bool setAnalyticalProjection(GFace *gf);

  /**
   * @brief Get the query closest point on the triangulated surface.
   *
   * @param query[3] 3D coordinates of the query point
   * @param evalOnCAD If param available, evaluate the face CAD mapping at the
   * interpolated UV
   * @param projectOnCAD If param available, call closestPoint from the CAD
   * geometry engine, with the interpolated UV as initial guess
   *
   * @return the projection, check GPoint::succeeded() for projection success /
   * failure
   */
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
