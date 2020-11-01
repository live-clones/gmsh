// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include <math.h>
#include "GModel.h"
#include "Context.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"

#if defined(HAVE_LIBCGNS)

// Structured CGNS file output is based on intial work financed by the Indian
// Institute of Technology Hyderabad - BRNS sponsored project in 2018 Under the
// guidance of Prof. Vinayak Eswaran <eswar@iith.ac.in>

static int writeZonesStruct2D(int cgIndexFile, int cgIndexBase,
                              std::vector<GFace *> &faces,
                              double scalingFactor)
{
  for(std::size_t iFace = 0; iFace < faces.size(); iFace++) {
    GFace *gf = faces[iFace];

    int cgIndexZone = 0;
    cgsize_t cgZoneSize[9] = {0};

    cgZoneSize[0] = gf->transfinite_vertices.size(); // imax, Number of vertices
    cgZoneSize[1] = gf->transfinite_vertices[0].size(); // jmax
    cgZoneSize[2] = cgZoneSize[0] - 1; // Number of elements
    cgZoneSize[3] = cgZoneSize[1] - 1;
    cgZoneSize[4] = 0;
    cgZoneSize[5] = 0;

    std::vector<double> dBuffer;
    std::string zoneName = cgnsString("Surface_" + std::to_string(gf->tag()));

    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     Structured, &cgIndexZone) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write the grid node
    int cgIndexGrid = 0;
    if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone, "GridCoordinates",
                     &cgIndexGrid) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write the grid coordinates
    int cgIndexCoord = 0;
    dBuffer.resize(cgZoneSize[0] * cgZoneSize[1]);

    // x-coordinates for this zone
    for(std::size_t k = 0; k < gf->transfinite_vertices[0].size(); k++) {
      for(std::size_t j = 0; j < gf->transfinite_vertices.size(); j++) {
        MVertex *v = gf->transfinite_vertices[j][k];
        dBuffer[cgZoneSize[0] * k + j] = v->x() * scalingFactor;
      }
    }

    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateX", &dBuffer[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // y-coordinates for this zone
    for(std::size_t k = 0; k < gf->transfinite_vertices[0].size(); k++) {
      for(std::size_t j = 0; j < gf->transfinite_vertices.size(); j++) {
        MVertex *v = gf->transfinite_vertices[j][k];
        dBuffer[cgZoneSize[0] * k + j] = v->y() * scalingFactor;
      }
    }

    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateY", &dBuffer[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // z-coordinates for this zone
    for(std::size_t k = 0; k < gf->transfinite_vertices[0].size(); k++) {
      for(std::size_t j = 0; j < gf->transfinite_vertices.size(); j++) {
        MVertex *v = gf->transfinite_vertices[j][k];
        dBuffer[cgZoneSize[0] * k + j] = v->z() * scalingFactor;
      }
    }

    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateZ", &dBuffer[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);
  }
  return 1;
}

static int writeZonesStruct3D(int cgIndexFile, int cgIndexBase,
                              std::vector<GRegion *> &regions,
                              double scalingFactor)
{
  for(std::size_t iRegion = 0; iRegion < regions.size(); iRegion++) {
    GRegion *gr = regions[iRegion];

    int cgIndexZone = 0;
    cgsize_t cgZoneSize[9] = {0};

    cgZoneSize[0] = gr->transfinite_vertices.size(); // imax Number of vertices
    cgZoneSize[1] = gr->transfinite_vertices[0].size(); // jmax
    cgZoneSize[2] = gr->transfinite_vertices[0][0].size(); // kmax
    cgZoneSize[3] = cgZoneSize[0] - 1; // Number of elements
    cgZoneSize[4] = cgZoneSize[1] - 1;
    cgZoneSize[5] = cgZoneSize[2] - 1;
    cgZoneSize[6] = 0;
    cgZoneSize[7] = 0;
    cgZoneSize[8] = 0;

    int imax = cgZoneSize[0];
    int jmax = cgZoneSize[1];
    int kmax = cgZoneSize[2];

    std::vector<double> dBuffer;
    std::string zoneName = cgnsString("Volume_" + std::to_string(gr->tag()));

    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     Structured, &cgIndexZone) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write the grid node
    int cgIndexGrid = 0;
    if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone, "GridCoordinates",
                     &cgIndexGrid) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write the grid coordinates
    int cgIndexCoord = 0;
    dBuffer.resize(imax * jmax * kmax);

    // x-coordinates for this zone
    for(std::size_t kk = 0; kk < gr->transfinite_vertices[0][0].size(); kk++) {
      for(std::size_t jj = 0; jj < gr->transfinite_vertices[0].size(); jj++) {
        for(std::size_t ii = 0; ii < gr->transfinite_vertices.size(); ii++) {
          MVertex *v = gr->transfinite_vertices[ii][jj][kk];
          dBuffer[imax * jmax * kk + imax * jj + ii] = v->x() * scalingFactor;
        }
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateX", &dBuffer[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // y-coordinates for this zone
    for(std::size_t kk = 0; kk < gr->transfinite_vertices[0][0].size(); kk++) {
      for(std::size_t jj = 0; jj < gr->transfinite_vertices[0].size(); jj++) {
        for(std::size_t ii = 0; ii < gr->transfinite_vertices.size(); ii++) {
          MVertex *v = gr->transfinite_vertices[ii][jj][kk];
          dBuffer[imax * jmax * kk + imax * jj + ii] = v->y() * scalingFactor;
        }
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateY", &dBuffer[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // z-coordinates for this zone
    for(std::size_t kk = 0; kk < gr->transfinite_vertices[0][0].size(); kk++) {
      for(std::size_t jj = 0; jj < gr->transfinite_vertices[0].size(); jj++) {
        for(std::size_t ii = 0; ii < gr->transfinite_vertices.size(); ii++) {
          MVertex *v = gr->transfinite_vertices[ii][jj][kk];
          dBuffer[imax * jmax * kk + imax * jj + ii] = v->z() * scalingFactor;
        }
      }
    }
    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateZ", &dBuffer[0], &cgIndexCoord) != CG_OK)
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
