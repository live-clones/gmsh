// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include <math.h>
#include <sstream>
#include <iomanip>
#include "GModel.h"
#include "Context.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"

// The structured CGNS writer follows ICEM-like conventions, which are
// significantly different from those used in the unstructured CGNS writer:
//
// - structured 3D (resp. 2D) meshes contain one zone per volume (resp.
//   surface) and no zones are created for lower dimensional entities; the
//   unstructured writer creates a single zone per mesh partition (i.e. a single
//   zone for non-partitioned meshes)
//
// - all structured volumes (3D) or surfaces (2D) are saved; if physical groups
//   are defined, the unstructured writer only saves entities belonging to
//   physical groups, unless Mesh.SaveAll is set
//
// - interfaces between structured zones are 1-to-1, with point ranges; the
//   unstructured writer creates interfaces (between partitions) defined by
//   point lists
//
// - elementary entity tags are encoded in the zone name; the unstructured
//   writer writes elementary entity information as boundary conditions and
//   family names
//
// - physical groups for the highest dimensional entities are directly encoded
//   at the begining of the zone name; the unstructured writer saves physical
//   names in families
//
// - boundary conditions are created for all zone boundaries, and if physical
//   groups are defined on boundaries they are also saved as families

#if defined(HAVE_LIBCGNS)

static bool isTransfinite(GFace *gf)
{
  return gf->transfinite_vertices.size() && gf->transfinite_vertices[0].size();
}

static bool isTransfinite(GRegion *gr)
{
  return gr->transfinite_vertices.size() &&
         gr->transfinite_vertices[0].size() &&
         gr->transfinite_vertices[0][0].size();
}

static std::string getDimName(int dim)
{
  switch(dim) {
  case 0: return "P"; break;
  case 1: return "C"; break;
  case 2: return "S"; break;
  case 3: return "V"; break;
  }
  return "";
}

static std::string getZoneName(GEntity *ge, bool withPhysical = true,
                               bool withElementary = true)
{
  std::ostringstream sstream;

  if(withPhysical) {
    for(std::size_t i = 0; i < ge->physicals.size(); i++) {
      if(i) sstream << " ";
      int t = std::abs(ge->physicals[i]);
      std::string n = ge->model()->getPhysicalName(ge->dim(), t);
      if(n.empty()) { sstream << "P" << getDimName(ge->dim()) << t; }
      else {
        sstream << n;
      }
    }
    if(withElementary) sstream << " ";
  }
  if(withElementary) {
    sstream << getDimName(ge->dim());
    // 5 digits with 0 padding
    if((ge->dim() == 0 && ge->model()->getNumVertices() < 10000) ||
       (ge->dim() == 1 && ge->model()->getNumEdges() < 10000) ||
       (ge->dim() == 2 && ge->model()->getNumFaces() < 10000) ||
       (ge->dim() == 3 && ge->model()->getNumRegions() < 10000))
      sstream << std::setfill('0') << std::setw(5);
    sstream << ge->tag();
  }
  return sstream.str().substr(0, 32);
}

static std::string getInterfaceName(GEntity *ge, GEntity *ge1, GEntity *ge2)
{
  std::ostringstream sstream;
  sstream << getZoneName(ge, false) << " (" << getZoneName(ge1, false) << " & "
          << getZoneName(ge2, false) << ")";
  return sstream.str().substr(0, 32);
}

static void computeTransform2D(const std::vector<cgsize_t> &pointRange,
                               const std::vector<cgsize_t> &pointDonorRange,
                               int transform[2])
{
  if(pointRange.size() != 4 || pointDonorRange.size() != 4) {
    Msg::Error("Invalid point ranges to compute transform - using default");
    transform[0] = 1;
    transform[1] = 2;
    return;
  }

  int r[2], d[2];
  for(int i = 0; i < 2; i++) {
    r[i] = pointRange[i + 2] - pointRange[i];
    d[i] = pointDonorRange[i + 2] - pointDonorRange[i];
  }
  for(int i = 0; i < 2; i++) {
    transform[i] = 0;
    for(int j = 0; j < 2; j++) {
      if(std::abs(r[i]) == std::abs(d[j])) { // == 0 on the interface
        transform[i] = (j + 1) * (r[i] * d[j] < 0 ? -1 : 1);
      }
    }
    if(!transform[i]) Msg::Warning("Could not identify transform[%d]", i);
  }
}

static bool findRange2D(GFace *gf, GEdge *ge, int &ibeg, int &jbeg, int &iend,
                        int &jend)
{
  GVertex *gv1 = ge->getBeginVertex(), *gv2 = ge->getEndVertex();
  if(!gv1 || !gv1->getNumMeshVertices() || !gv2 || !gv2->getNumMeshVertices())
    return false;
  MVertex *v1 = gv1->getMeshVertex(0), *v2 = gv2->getMeshVertex(0);
  std::vector<std::vector<MVertex *> > &v = gf->transfinite_vertices;
  int imax = v.size(), jmax = v[0].size();
  ibeg = iend = jbeg = jend = -1;
  for(int i = 0; i < imax; i++) {
    for(int j = 0; j < jmax; j++) {
      if(i == 0 || j == 0 || i == imax - 1 || j == jmax - 1) {
        if(v[i][j] == v1) {
          ibeg = i + 1;
          jbeg = j + 1;
        }
        else if(v[i][j] == v2) {
          iend = i + 1;
          jend = j + 1;
        }
      }
    }
  }
  if(ibeg > 0 && iend > 0 && jbeg > 0 && jend > 0) return true;
  return false;
}

static int writeInterface2D(int cgIndexFile, int cgIndexBase, int cgIndexZone,
                            GFace *gf, GEdge *ge, GFace *gf2)
{
  std::vector<cgsize_t> pointRange, pointDonorRange;
  int ibeg, iend, jbeg, jend;
  if(findRange2D(gf, ge, ibeg, jbeg, iend, jend))
    pointRange = {ibeg, jbeg, iend, jend};
  if(findRange2D(gf2, ge, ibeg, jbeg, iend, jend))
    pointDonorRange = {ibeg, jbeg, iend, jend};
  if(pointRange.size() && pointDonorRange.size()) {
    int transform[2];
    computeTransform2D(pointRange, pointDonorRange, transform);
    int cgIndexConn;
    if(cg_1to1_write(cgIndexFile, cgIndexBase, cgIndexZone,
                     getInterfaceName(ge, gf, gf2).c_str(),
                     getZoneName(gf2).c_str(), &pointRange[0],
                     &pointDonorRange[0], transform, &cgIndexConn) != CG_OK) {
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
  }
  else {
    Msg::Warning("Could not identify interface between surfaces %d and %d, "
                 "on curve %d",
                 gf->tag(), gf2->tag(), ge->tag());
  }
  return 1;
}

static int writeBC2D(int cgIndexFile, int cgIndexBase, int cgIndexZone,
                     GFace *gf, GEdge *ge)
{
  int ibeg, iend, jbeg, jend;
  if(findRange2D(gf, ge, ibeg, jbeg, iend, jend)) {
    std::vector<cgsize_t> pointRange = {ibeg, jbeg, iend, jend};
    int cgIndexBoco = 0;
    if(cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                     getZoneName(ge).c_str(), CGNS_ENUMV(BCTypeNull),
                     CGNS_ENUMV(PointRange), 2, &pointRange[0],
                     &cgIndexBoco) != CG_OK) {
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
    // if the curve is part of a physical group, also write a family
    if(ge->physicals.size()) {
      if(cg_goto(cgIndexFile, cgIndexBase, "Zone_t", cgIndexZone, "ZoneBC_t", 1,
                 "BC_t", cgIndexBoco, "end") != CG_OK)
        return cgnsError(__FILE__, __LINE__, cgIndexFile);
      if(cg_famname_write(getZoneName(ge, true, false).c_str()) != CG_OK)
        return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
  }
  else {
    Msg::Warning("Could not identify boundary condition on curve %d in "
                 "surface %d",
                 ge->tag(), gf->tag());
  }
  return 1;
}

static int writeZonesStruct2D(int cgIndexFile, int cgIndexBase,
                              std::vector<GFace *> &faces, double scalingFactor)
{
  for(auto gf : faces) {
    cgsize_t imax = gf->transfinite_vertices.size();
    cgsize_t jmax = gf->transfinite_vertices[0].size();

    // write zone
    int cgIndexZone = 0;
    cgsize_t cgZoneSize[6] = {imax, jmax, imax - 1, jmax - 1, 0, 0};
    std::string zoneName = cgnsString(getZoneName(gf));
    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     CGNS_ENUMV(Structured), &cgIndexZone) != CG_OK)
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
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                      CGNS_ENUMV(RealDouble), "CoordinateX", &data[0],
                      &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write y coordinates
    for(cgsize_t j = 0; j < jmax; j++) {
      for(cgsize_t i = 0; i < imax; i++) {
        MVertex *v = gf->transfinite_vertices[i][j];
        data[cgZoneSize[0] * j + i] = v->y() * scalingFactor;
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                      CGNS_ENUMV(RealDouble), "CoordinateY", &data[0],
                      &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write z coordinates
    for(cgsize_t j = 0; j < jmax; j++) {
      for(cgsize_t i = 0; i < imax; i++) {
        MVertex *v = gf->transfinite_vertices[i][j];
        data[cgZoneSize[0] * j + i] = v->z() * scalingFactor;
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                      CGNS_ENUMV(RealDouble), "CoordinateZ", &data[0],
                      &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    for(auto ge : gf->edges()) {
      // write interface data
      for(auto gf2 : ge->faces()) {
        if(gf2 != gf && isTransfinite(gf2))
          writeInterface2D(cgIndexFile, cgIndexBase, cgIndexZone, gf, ge, gf2);
      }
      // write boundary condition for each curve (even those that don't belong
      // to a physical group, to match ICEM)
      writeBC2D(cgIndexFile, cgIndexBase, cgIndexZone, gf, ge);
    }
  }
  return 1;
}

static void computeTransform3D(const std::vector<cgsize_t> &pointRange,
                               const std::vector<cgsize_t> &pointDonorRange,
                               int transform[3])
{
  if(pointRange.size() != 6 || pointDonorRange.size() != 6) {
    Msg::Error("Invalid point ranges to compute transform - using default");
    transform[0] = 1;
    transform[1] = 2;
    transform[2] = 3;
    return;
  }
  // This will choose one of the 2 possible orientations if we have the same
  // number of nodes on all the sides of the interface; not sure if this is an
  // issue, as the transfinite points ordering is not linked with the geometry
  // anyway?
  int r[3], d[3];
  for(int i = 0; i < 3; i++) {
    r[i] = pointRange[i + 3] - pointRange[i];
    d[i] = pointDonorRange[i + 3] - pointDonorRange[i];
  }
  for(int i = 0; i < 3; i++) {
    transform[i] = 0;
    for(int j = 0; j < 3; j++) {
      if(std::abs(r[i]) == std::abs(d[j])) { // == 0 on the interface
        transform[i] = (j + 1) * (r[i] * d[j] < 0 ? -1 : 1);
      }
    }
    if(!transform[i]) Msg::Warning("Could not identify transform[%d]", i);
  }
}

static bool findRange3D(GRegion *gr, GFace *gf, int &ibeg, int &jbeg, int &kbeg,
                        int &iend, int &jend, int &kend)
{
  if(gf->transfinite_vertices.empty() || gf->transfinite_vertices[0].empty())
    return false;
  MVertex *v1 = gf->transfinite_vertices.front().front();
  MVertex *v2 = gf->transfinite_vertices.back().back();

  std::vector<std::vector<std::vector<MVertex *> > > &v =
    gr->transfinite_vertices;
  int imax = v.size(), jmax = v[0].size(), kmax = v[0][0].size();
  ibeg = iend = jbeg = jend = kbeg = kend = -1;
  for(int i = 0; i < imax; i++) {
    for(int j = 0; j < jmax; j++) {
      for(int k = 0; k < kmax; k++) {
        if(i == 0 || j == 0 || k == 0 || i == imax - 1 || j == jmax - 1 ||
           k == kmax - 1) {
          if(v[i][j][k] == v1) {
            ibeg = i + 1;
            jbeg = j + 1;
            kbeg = k + 1;
          }
          else if(v[i][j][k] == v2) {
            iend = i + 1;
            jend = j + 1;
            kend = k + 1;
          }
        }
      }
    }
  }
  if(ibeg > 0 && iend > 0 && jbeg > 0 && jend > 0 && kbeg > 0 && kend > 0)
    return true;
  return false;
}

static int writeInterface3D(int cgIndexFile, int cgIndexBase, int cgIndexZone,
                            GRegion *gr, GFace *gf, GRegion *gr2)
{
  std::vector<cgsize_t> pointRange, pointDonorRange;
  int ibeg, iend, jbeg, jend, kbeg, kend;
  if(findRange3D(gr, gf, ibeg, jbeg, kbeg, iend, jend, kend))
    pointRange = {ibeg, jbeg, kbeg, iend, jend, kend};
  if(findRange3D(gr2, gf, ibeg, jbeg, kbeg, iend, jend, kend))
    pointDonorRange = {ibeg, jbeg, kbeg, iend, jend, kend};
  if(pointRange.size() && pointDonorRange.size()) {
    int transform[3];
    computeTransform3D(pointRange, pointDonorRange, transform);
    int cgIndexConn;
    if(cg_1to1_write(cgIndexFile, cgIndexBase, cgIndexZone,
                     getInterfaceName(gf, gr, gr2).c_str(),
                     getZoneName(gr2).c_str(), &pointRange[0],
                     &pointDonorRange[0], transform, &cgIndexConn) != CG_OK) {
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
  }
  else {
    Msg::Warning("Could not identify interface between volumes %d and %d, "
                 "on surface %d",
                 gr->tag(), gr2->tag(), gf->tag());
  }
  return 1;
}

static int writeBC3D(int cgIndexFile, int cgIndexBase, int cgIndexZone,
                     GRegion *gr, GFace *gf)
{
  int ibeg, iend, jbeg, jend, kbeg, kend;
  if(findRange3D(gr, gf, ibeg, jbeg, kbeg, iend, jend, kend)) {
    std::vector<cgsize_t> pointRange = {ibeg, jbeg, kbeg, iend, jend, kend};
    int cgIndexBoco = 0;
    if(cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                     getZoneName(gf).c_str(), CGNS_ENUMV(BCTypeNull),
                     CGNS_ENUMV(PointRange), 2, &pointRange[0],
                     &cgIndexBoco) != CG_OK) {
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
    // if the surface is part of a physical group, also write a family
    if(gf->physicals.size()) {
      if(cg_goto(cgIndexFile, cgIndexBase, "Zone_t", cgIndexZone, "ZoneBC_t", 1,
                 "BC_t", cgIndexBoco, "end") != CG_OK)
        return cgnsError(__FILE__, __LINE__, cgIndexFile);
      if(cg_famname_write(getZoneName(gf, true, false).c_str()) != CG_OK)
        return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
  }
  else {
    Msg::Warning("Could not identify boundary condition on surface %d in "
                 "volume %d",
                 gf->tag(), gr->tag());
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
    cgsize_t cgZoneSize[9] = {imax,     jmax, kmax, imax - 1, jmax - 1,
                              kmax - 1, 0,    0,    0};
    std::string zoneName = cgnsString(getZoneName(gr));
    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     CGNS_ENUMV(Structured), &cgIndexZone) != CG_OK)
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
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                      CGNS_ENUMV(RealDouble), "CoordinateX", &data[0],
                      &cgIndexCoord) != CG_OK)
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
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                      CGNS_ENUMV(RealDouble), "CoordinateY", &data[0],
                      &cgIndexCoord) != CG_OK)
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
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                      CGNS_ENUMV(RealDouble), "CoordinateZ", &data[0],
                      &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    for(auto gf : gr->faces()) {
      // write interface data
      for(auto gr2 : gf->regions()) {
        if(gr2 != gr && isTransfinite(gr2))
          writeInterface3D(cgIndexFile, cgIndexBase, cgIndexZone, gr, gf, gr2);
      }
      // write boundary condition for each surface (even those that don't belong
      // to a physical group, to match ICEM)
      writeBC3D(cgIndexFile, cgIndexBase, cgIndexZone, gr, gf);
    }
  }
  return 1;
}

int writeZonesStruct(GModel *model, double scalingFactor, int cgIndexFile,
                     int cgIndexBase)
{
  int meshDim = -1;

  std::vector<GFace *> faces;
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    if(isTransfinite(*it)) {
      meshDim = 2;
      faces.push_back(*it);
    }
  }

  std::vector<GRegion *> regions;
  for(auto it = model->firstRegion(); it != model->lastRegion(); ++it) {
    if(isTransfinite(*it)) {
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
