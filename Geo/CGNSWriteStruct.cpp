// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include <math.h>
#include <sstream>
#include "GModel.h"
#include "Context.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"

// The structured CGNS writer follows ICEM-like conventions (significantly
// different from those used in our unstructured CGNS writer):
// - structured 3D (resp. 2D) meshes contain one zone per volume (resp.
//   surface); no zones are created for lower dimensional entities
// - interfaces between zones are 1-to-1, with point ranges (not point
//   lists)
// - physical groups for the highest dimensional entities are directly
//   encoded at the begning of the zone name (no families are created)
// - boundary conditions are created for physical groups of lower
//   dimensions

#if defined(HAVE_LIBCGNS)

static std::string dimName(int dim)
{
  if(dim == 3) return "Volume";
  else if(dim == 2) return "Surface";
  else if(dim == 1) return "Curve";
  else return "Point";
}

static std::string getZoneName(GEntity *ge)
{
  std::ostringstream sstream;
  for(auto t: ge->physicals) {
    std::string n = ge->model()->getPhysicalName(ge->dim(), t);
    if(n.empty())
      sstream << "Physical" << dimName(ge->dim()) << t << "_";
    else
      sstream << n << "_";
  }
  sstream << dimName(ge->dim()) << ge->tag();
  return sstream.str();
}

static std::string getInterfaceName(GEntity *ge1, GEntity *ge2)
{
  std::ostringstream sstream;
  sstream << "Interface_" << dimName(ge1->dim()) << ge1->tag()
          << "_" << dimName(ge2->dim()) << ge2->tag();
  return sstream.str();
}

static void computeTransform(const std::vector<cgsize_t> &pointRange,
                             const std::vector<cgsize_t> &pointDonorRange,
                             int transform[2])
{
  // This routine was written with the financial aid of of Indian Institute of
  // Technology Hyderabad - BRNS sponsored project in 2018, under the guidance
  // of Prof. Vinayak Eswaran <eswar@iith.ac.in>

  if(pointRange.size() != 4 || pointDonorRange.size() != 4) {
    Msg::Error("Invalid point ranges to compute tranform - using default");
    transform[0] = 1;
    transform[1] = 2;
    return;
  }

  int a1 = pointDonorRange[2] - pointDonorRange[0];
  int a2 = pointDonorRange[3] - pointDonorRange[1];
  int b1 = pointRange[2] - pointRange[0];
  int b2 = pointRange[3] - pointRange[1];

  // In the interface face, if one index is varying, the other should remain
  // constant and hence one of a1, a2, b1, b2 should be zero (in 2D): (Index2 -
  // Begin2) = T.(Index1 - Begin1); (Index1 - Begin1) = Transpose[T].(Index2 -
  // Begin2)
  int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  if(b2 == 0) {
    x1 = a1 / b1;
    y1 = a2 / b1;
    if(x1 == 0) {
      y2 = 0;
      if(y1 < 0) x2 = 1;
      else x2 = -1;
    }
    else if(y1 == 0) {
      x2 = 0;
      if(x1 > 0) y2 = 1;
      else y2 = -1;
    }
  }
  else if(b1 == 0) {
    x2 = a1 / b2;
    y2 = a2 / b2;
    if(x2 == 0) {
      y1 = 0;
      if(y2 > 0) x1 = 1;
      else x1 = -1;
    }
    else if(y2 == 0) {
      x1 = 0;
      if(x2 < 0) y1 = 1;
      else y1 = -1;
    }
  }
  else {
    Msg::Warning("Could not find transform matrix for zone - using default");
    transform[0] = 1;
    transform[1] = 2;
    return;
  }

  if(x1 == 1) transform[0] = 1;
  else if(x1 == -1) transform[0] = -1;
  if(x2 == 1) transform[1] = 1;
  else if(x2 == -1) transform[1] = -1;

  if(y1 == 1) transform[0] = 2;
  else if(y1 == -1) transform[0] = -2;
  if(y2 == 1) transform[1] = 2;
  else if(y2 == -1) transform[1] = -2;
}

static int writeInterface(int cgIndexFile, int cgIndexBase, int cgIndexZone,
                          GFace *gf, GFace *gf2)
{
  std::vector<std::vector<MVertex *> > &v = gf->transfinite_vertices;
  cgsize_t imax = v.size(), jmax = v[0].size();
  std::vector<std::vector<MVertex *> > &v2 = gf2->transfinite_vertices;
  cgsize_t imax2 = v2.size(), jmax2 = v2[0].size();

  // 4 "logical" edges for each patch
  int e[][4] = {{0, 0, imax - 1, 0},
                {imax - 1, 0, imax - 1, jmax - 1},
                {imax - 1, jmax - 1, 0, jmax - 1},
                {0, jmax - 1, 0, 0}};
  int e2[][4] = {{0, 0, imax2 - 1, 0},
                 {imax2 - 1, 0, imax2 - 1, jmax2 - 1},
                 {imax2 - 1, jmax2 - 1, 0, jmax2 - 1},
                 {0, jmax2 - 1, 0, 0}};

  std::vector<cgsize_t> pointRange, pointDonorRange;
  bool found = false;

  // first, perform a fast search by just trying to match the 4 "logical"
  // bounding edges of the 2 patches
  for(int l = 0; l < 4; l++) {
    for(int l2 = 0; l2 < 4; l2++) {
      if(v[e[l][0]][e[l][1]] == v2[e2[l2][0]][e2[l2][1]] &&
         v[e[l][2]][e[l][3]] == v2[e2[l2][2]][e2[l2][3]]) {
        pointRange = {e[l][0] + 1, e[l][1] + 1,
                      e[l][2] + 1, e[l][3] + 1};
        pointDonorRange = {e2[l2][0] + 1, e2[l2][1] + 1,
                           e2[l2][2] + 1, e2[l2][3] + 1};
        found = true;
        break;
      }
      else if(v[e[l][0]][e[l][1]] == v2[e2[l2][2]][e2[l2][3]] &&
              v[e[l][2]][e[l][3]] == v2[e2[l2][0]][e2[l2][1]]) {
        pointRange = {e[l][0] + 1, e[l][1] + 1,
                      e[l][2] + 1, e[l][3] + 1};
        pointDonorRange = {e2[l2][2] + 1, e2[l2][3] + 1,
                           e2[l2][0] + 1, e2[l2][1] + 1};
        found = true;
        break;
      }
    }
    if(found) break;
  }

  // if not found, search for partial matches (this can happen in 2D, as Gmsh
  // allows to generate structured meshes for surfaces with more than 4 bounding
  // curves)
  if(!found) {
    // TODO
    /*
    for(int l2 = 0; l2 < 4; l2++) {
      // begin/end node of potential donnor edge
      MVertex *v1 = v2[e2[l2][0]][e2[l2][1]], *v2[e2[l2][2]][e2[l2][3]];
      int found1 = -1, found2 = -1;
      // for each edge of the patch...
      for(int l = 0; l < 4; l++) {
        // ...loop over all nodes and see if we find v1 and v2
        //for(k = 0; e[i]
      }
    }
    */
  }


  if(found) {
    int transform[2];
    computeTransform(pointRange, pointDonorRange, transform);
    int cgIndexConn;
    if(cg_1to1_write(cgIndexFile, cgIndexBase, cgIndexZone,
                     getInterfaceName(gf, gf2).c_str(),
                     getZoneName(gf2).c_str(), &pointRange[0],
                     &pointDonorRange[0], transform, &cgIndexConn)) {
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
  }
  else {
    Msg::Warning("Could not identify interface between surfaces %d and %d",
                 gf->tag(), gf2->tag());
  }
  return 1;
}

static int writeBC(int cgIndexFile, int cgIndexBase, int cgIndexZone,
                   GFace *gf, GEdge *ge)
{
  std::vector<std::vector<MVertex *> > &v = gf->transfinite_vertices;
  cgsize_t imax = v.size(), jmax = v[0].size();

  GVertex *gv1 = ge->getBeginVertex(), *gv2 = ge->getEndVertex();
  if(!gv1 || !gv2) return 0;
  if(!gv1->getNumMeshVertices() || !gv2->getNumMeshVertices()) return 0;
  MVertex *v1 = gv1->getMeshVertex(0), *v2 = gv2->getMeshVertex(0);

  int e[][4] = {{0, 0, imax - 1, 0},
                {imax - 1, 0, imax - 1, jmax - 1},
                {imax - 1, jmax - 1, 0, jmax - 1},
                {0, jmax - 1, 0, 0}};
  std::vector<cgsize_t> pointRange;
  bool found = false;

  // first, perform a fast search by just trying to match the 4 "logical"
  // bounding edges
  for(int l = 0; l < 4; l++) {
    if((v[e[l][0]][e[l][1]] == v1 && v[e[l][2]][e[l][3]] == v2) ||
       (v[e[l][0]][e[l][1]] == v2 && v[e[l][2]][e[l][3]] == v1)) {
      pointRange = {e[l][0] + 1, e[l][1] + 1,
                    e[l][2] + 1, e[l][3] + 1};
      found = true;
    }
  }

  // if not found, search for partial match
  if(!found) {
    // TODO
  }

  if(found) {
    int cgIndexBoco = 0;
    if(cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                     getZoneName(ge).c_str(), BCWallViscous, PointRange,
                     2, &pointRange[0], &cgIndexBoco)) {
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
  }
  else{
    Msg::Warning("Could not identify boundary condition on curve %d in "
                 "surface %d", ge->tag(), gf->tag());
  }
  return 1;
}

static int writeZonesStruct2D(int cgIndexFile, int cgIndexBase,
                              std::vector<GFace *> &faces,
                              double scalingFactor)
{
  for(auto gf : faces) {
    cgsize_t imax = gf->transfinite_vertices.size();
    cgsize_t jmax = gf->transfinite_vertices[0].size();

    // write zone
    int cgIndexZone = 0;
    cgsize_t cgZoneSize[6] = {imax, jmax, imax - 1, jmax - 1, 0, 0};
    std::string zoneName = cgnsString(getZoneName(gf));
    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     Structured, &cgIndexZone) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write grid
    int cgIndexGrid = 0;
    if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone, "GridCoordinates",
                     &cgIndexGrid) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write x coordinates
    int cgIndexCoord = 0;
    std::vector<double> data(cgZoneSize[0] * cgZoneSize[1]);
    for(cgsize_t j = 0; j < jmax; j++) {
      for(cgsize_t i = 0; i < imax; i++) {
        MVertex *v = gf->transfinite_vertices[i][j];
        data[cgZoneSize[0] * j + i] = v->x() * scalingFactor;
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateX", &data[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write y coordinates
    for(cgsize_t j = 0; j < jmax; j++) {
      for(cgsize_t i = 0; i < imax; i++) {
        MVertex *v = gf->transfinite_vertices[i][j];
        data[cgZoneSize[0] * j + i] = v->y() * scalingFactor;
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateY", &data[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write z coordinates
    for(cgsize_t j = 0; j < jmax; j++) {
      for(cgsize_t i = 0; i < imax; i++) {
        MVertex *v = gf->transfinite_vertices[i][j];
        data[cgZoneSize[0] * j + i] = v->z() * scalingFactor;
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateZ", &data[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    for(auto ge: gf->edges()) {
      // write interface data
      for(auto gf2: ge->faces()) {
        if(gf2 != gf)
          writeInterface(cgIndexFile, cgIndexBase, cgIndexZone, gf, gf2);
      }
      // write boundary conditions
      if(!ge->physicals.empty())
        writeBC(cgIndexFile, cgIndexBase, cgIndexZone, gf, ge);
    }
  }
  return 1;
}

static int writeZonesStruct3D(int cgIndexFile, int cgIndexBase,
                              std::vector<GRegion *> &regions,
                              double scalingFactor)
{
  for(auto gr : regions) {
    cgsize_t imax = gr->transfinite_vertices.size();
    cgsize_t jmax = gr->transfinite_vertices[0].size();
    cgsize_t kmax = gr->transfinite_vertices[0][0].size();

    // write zone
    int cgIndexZone = 0;
    cgsize_t cgZoneSize[9] = {imax, jmax, kmax, imax - 1, jmax - 1, kmax - 1,
                              0, 0, 0};
    std::string zoneName = cgnsString("Volume_" + std::to_string(gr->tag()));
    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     Structured, &cgIndexZone) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write grid
    int cgIndexGrid = 0;
    if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone, "GridCoordinates",
                     &cgIndexGrid) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write x coordinates
    int cgIndexCoord = 0;
    std::vector<double> data(imax * jmax * kmax);
    for(cgsize_t k = 0; k < kmax; k++) {
      for(cgsize_t j = 0; j < jmax; j++) {
        for(cgsize_t i = 0; i < imax; i++) {
          MVertex *v = gr->transfinite_vertices[i][j][k];
          data[imax * jmax * k + imax * j + i] = v->x() * scalingFactor;
        }
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateX", &data[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write y coordinates
    for(cgsize_t k = 0; k < kmax; k++) {
      for(cgsize_t j = 0; j < jmax; j++) {
        for(cgsize_t i = 0; i < imax; i++) {
          MVertex *v = gr->transfinite_vertices[i][j][k];
          data[imax * jmax * k + imax * j + i] = v->y() * scalingFactor;
        }
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateY", &data[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write z coordinates
    for(cgsize_t k = 0; k < kmax; k++) {
      for(cgsize_t j = 0; j < jmax; j++) {
        for(cgsize_t i = 0; i < imax; i++) {
          MVertex *v = gr->transfinite_vertices[i][j][k];
          data[imax * jmax * k + imax * j + i] = v->z() * scalingFactor;
        }
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateZ", &data[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
  }
  return 1;
}

int writeZonesStruct(GModel *model, double scalingFactor, int cgIndexFile,
                     int cgIndexBase)
{
  int meshDim = -1;

  std::vector<GFace *> faces;
  for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it) {
    if((*it)->transfinite_vertices.size() &&
       (*it)->transfinite_vertices[0].size()) {
      meshDim = 2;
      faces.push_back(*it);
    }
  }

  std::vector<GRegion *> regions;
  for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
      ++it) {
    if((*it)->transfinite_vertices.size() &&
       (*it)->transfinite_vertices[0].size() &&
       (*it)->transfinite_vertices[0][0].size()) {
      meshDim = 3;
      regions.push_back(*it);
    }
  }

  if(meshDim < 0 || (faces.empty() && regions.empty())) {
    Msg::Warning("No structured meshes to save");
    return 0;
  }

  if(meshDim == 2) {
    if(writeZonesStruct2D(cgIndexFile, cgIndexBase, faces, scalingFactor))
      return 1;
  }
  else if(meshDim == 3) {
    if(writeZonesStruct3D(cgIndexFile, cgIndexBase, regions, scalingFactor))
      return 1;
  }

  return 0;
}

#endif // HAVE_LIBCGNS
