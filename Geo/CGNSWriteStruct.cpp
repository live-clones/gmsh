// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include <math.h>
#include "GModel.h"
#include "Context.h"
#include "CGNSCommon.h"

// Structured CGNS file output is based on intial work financed by the Indian
// Institute of Technology Hyderabad - BRNS sponsored project in 2018 Under the
// guidance of Prof. Vinayak Eswaran <eswar@iith.ac.in>

static int sameVertex(GVertex *v1, MVertex *v2)
{
  if(v1->xyz().distance(v2->point()) < CTX::instance()->geom.tolerance)
    return 1;
  return 0;
}

static int sameVertex(MVertex *v1, MVertex *v2)
{
  if(v1->distance(v2) < CTX::instance()->geom.tolerance) return 1;
  return 0;
}

static int sameFace(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
                    MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8)
{
  // Checks whether Face formed by vertices v1, v2, v3, v4 is same as the face
  // formed by vertices v5, v6, v7, v8
  if((sameVertex(v1, v5) || sameVertex(v1, v6) || sameVertex(v1, v7) ||
      sameVertex(v1, v8)) &&
     (sameVertex(v2, v5) || sameVertex(v2, v6) || sameVertex(v2, v7) ||
      sameVertex(v2, v8)) &&
     (sameVertex(v3, v5) || sameVertex(v3, v6) || sameVertex(v3, v7) ||
      sameVertex(v3, v8)) &&
     (sameVertex(v4, v5) || sameVertex(v4, v6) || sameVertex(v4, v7) ||
      sameVertex(v4, v8))) {
    return 1;
  }
  else {
    return 0;
  }
}

static void faceOrientationTransfinite(GFace *f, double n[3])
{
  // This subroutine returns i,j,k components of unit normal of the given face f
  MVertex *v0 = f->transfinite_vertices[0][0];
  MVertex *v1 = f->transfinite_vertices[1][0];
  MVertex *v2 = f->transfinite_vertices[0][1];

  SPoint3 v0_xyz = v0->point();
  SPoint3 v1_xyz = v1->point();
  SPoint3 v2_xyz = v2->point();

  double vec1x = v1_xyz[0] - v0_xyz[0];
  double vec1y = v1_xyz[1] - v0_xyz[1];
  double vec1z = v1_xyz[2] - v0_xyz[2];

  double vec2x = v2_xyz[0] - v0_xyz[0];
  double vec2y = v2_xyz[1] - v0_xyz[1];
  double vec2z = v2_xyz[2] - v0_xyz[2];

  n[0] = vec1y * vec2z - vec1z * vec2y;
  n[1] = vec1z * vec2x - vec1x * vec2z;
  n[2] = vec1x * vec2y - vec1y * vec2x;

  double detVecOri = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
  n[0] = n[0] / detVecOri;
  n[1] = n[1] / detVecOri;
  n[2] = n[2] / detVecOri;
}

static int volumeOrientationTransfinite(GRegion *gr)
{
  // If the volume mesh is in Right-Hand orientation this function returns 1
  // otherwise -1
  MVertex *v0 = gr->transfinite_vertices[0][0][0];
  MVertex *v1 = gr->transfinite_vertices[1][0][0];
  MVertex *v2 = gr->transfinite_vertices[0][1][0];
  MVertex *v3 = gr->transfinite_vertices[0][0][1];

  SPoint3 v0_xyz = v0->point();
  SPoint3 v1_xyz = v1->point();
  SPoint3 v2_xyz = v2->point();
  SPoint3 v3_xyz = v3->point();

  double vec1x = v1_xyz[0] - v0_xyz[0];
  double vec1y = v1_xyz[1] - v0_xyz[1];
  double vec1z = v1_xyz[2] - v0_xyz[2];

  double vec2x = v2_xyz[0] - v0_xyz[0];
  double vec2y = v2_xyz[1] - v0_xyz[1];
  double vec2z = v2_xyz[2] - v0_xyz[2];

  double vec3x = v3_xyz[0] - v0_xyz[0];
  double vec3y = v3_xyz[1] - v0_xyz[1];
  double vec3z = v3_xyz[2] - v0_xyz[2];

  double detVec3 = sqrt(vec3x * vec3x + vec3y * vec3y + vec3z * vec3z);
  vec3x = vec3x / detVec3;
  vec3y = vec3y / detVec3;
  vec3z = vec3z / detVec3;

  double vecRHrulex = vec1y * vec2z - vec1z * vec2y;
  double vecRHruley = vec1z * vec2x - vec1x * vec2z;
  double vecRHrulez = vec1x * vec2y - vec1y * vec2x;

  double detVecRHrule = sqrt(vecRHrulex * vecRHrulex + vecRHruley * vecRHruley +
                             vecRHrulez * vecRHrulez);
  vecRHrulex = vecRHrulex / detVecRHrule;
  vecRHruley = vecRHruley / detVecRHrule;
  vecRHrulez = vecRHrulez / detVecRHrule;

  double vecOrix = vec3x - vecRHrulex;
  double vecOriy = vec3y - vecRHruley;
  double vecOriz = vec3z - vecRHrulez;

  double vecOri =
    sqrt(vecOrix * vecOrix + vecOriy * vecOriy + vecOriz * vecOriz);

  if(vecOri < 0.05) { return 1; }
  else {
    return -1;
  }
}

static int isInterfaceFace(std::vector<GRegion *> &regions, MVertex *v0,
                           MVertex *v1, MVertex *v2, MVertex *v3)
{
  // This function determines whether a face formed by four corner vertices
  // v0,v1,v2,v3 is an interface-face between two regions or not. This function
  // makes use of a fact that a face is an interior face if it is shared by two
  // volumes
  int countFace = 0;

  for(std::size_t iRegion = 0; iRegion < regions.size(); iRegion++) {
    GRegion *gr = regions[iRegion];
    std::vector<GFace *> faces = gr->faces();
    if(faces.size() != 6) {
      Msg::Warning("Volume %d has %d bounding surfaces", gr->tag(),
                   faces.size());
    }

    for(std::size_t iFace = 0; iFace < faces.size(); iFace++) {
      std::vector<GVertex *> vf = faces[iFace]->vertices();
      if(vf.size() != 4) {
        Msg::Warning("Surface %d in volume %d has %d (!=4) bounding points",
                     faces[iFace]->tag(), gr->tag(), vf.size());
      }
      if((sameVertex(vf[0], v0) || sameVertex(vf[0], v1) ||
          sameVertex(vf[0], v2) || sameVertex(vf[0], v3)) &&
         (sameVertex(vf[1], v0) || sameVertex(vf[1], v1) ||
          sameVertex(vf[1], v2) || sameVertex(vf[1], v3)) &&
         (sameVertex(vf[2], v0) || sameVertex(vf[2], v1) ||
          sameVertex(vf[2], v2) || sameVertex(vf[2], v3)) &&
         (sameVertex(vf[3], v0) || sameVertex(vf[3], v1) ||
          sameVertex(vf[3], v2) || sameVertex(vf[3], v3)))
        countFace += 1;
    }
  }
  if(countFace == 2) { return 1; }
  else {
    return 0;
  }
}

class CGNSNameStr {
private:
  char name[33];

public:
  // Constructors
  CGNSNameStr() { name[0] = '\0'; }
  CGNSNameStr(const char *const cstr)
  {
    std::strncpy(name, cstr, 32);
    name[32] = '\0';
  }
  CGNSNameStr(std::string &s)
  {
    std::strncpy(name, s.c_str(), 32);
    name[32] = '\0';
  }
  CGNSNameStr(const int d, const char *const fmt = "%d")
  {
    std::sprintf(name, fmt, d);
  }
  CGNSNameStr(const CGNSNameStr &cgs) { std::strcpy(name, cgs.name); }
  // Assignment
  CGNSNameStr &operator=(const CGNSNameStr &cgs)
  {
    if(&cgs != this) { std::strcpy(name, cgs.name); }
    return *this;
  }
  CGNSNameStr &operator=(const char *const cstr)
  {
    std::strncpy(name, cstr, 32);
    name[32] = '\0';
    return *this;
  }
  // Return the C string
  char *c_str() { return name; }
  const char *c_str() const { return name; }
};

// Expands variables in a string 's' that are supported by the CGNS I/O.  's'
// is overwritten with the expanded string.
//
// - &I[0][%width]% expands into 'index'.  Normally 'index' is assumed to have
//   C numbering and therefore 1 is added to it.  Option [0] prevents the
//   addition of the one.  Option [%width] sets the width of the index to
//   'width' and pads with leading zeros.
// - &N& expands to 'name'.

static void expandName(std::string &s, const int index, const char *const name)
{
  std::string::size_type r1 = s.find('&');
  // Look for and replace "&-&" sub-strings
  while(r1 != std::string::npos) {
    const std::string::size_type r2 = s.find('&', r1 + 1);
    if(r2 == std::string::npos) { s.replace(r1, s.length() - r1, ""); }
    else {
      const int rn = r2 - r1 + 1;
      switch(s[r1 + 1]) {
      case 'I':
        // &I[0][%width]&
        {
          int iplus = 1;
          if(s[r1 + 2] == '0') iplus = 0;
          char fmt[6] = "%d";
          const std::string::size_type f = s.find('%', r1 + 1);
          if(f != std::string::npos && f < r2) {
            int w = std::atoi(s.substr(f + 1, r2 - f - 1).c_str());
            if(w > 0 && w < 33) std::sprintf(fmt, "%%0%dd", w);
          }
          s.replace(r1, rn, CGNSNameStr(index + iplus, fmt).c_str());
          break;
        }
      case 'N':
        // &N&
        s.replace(r1, rn, name);
        break;
      default: s.replace(r1, rn, "");
      }
    }
    if(s.length() > 1024) s = ""; // idiot/recursive check
    r1 = s.find('&');
  }
}

static int writeZonesStruct2D(int cgIndexFile, int cgIndexBase,
                              std::vector<GFace *> &faces,
                              int numInterfaceEdges, double scalingFactor)
{
  int cgIndexZone = 0;
  cgsize_t cgZoneSize[9] = {0};
  int patchIndex = -1;
  int interfaceIndex = -1;

  for(std::size_t iFace = 0; iFace < faces.size(); iFace++) {
    GFace *gf = faces[iFace];
    std::vector<GEdge *> const &edges = gf->edges();
    if(edges.size() != 4) {
      Msg::Warning("Surface %d has %lu (!=4) bounding curves", gf->tag(),
                   edges.size());
    }

    cgZoneSize[0] = gf->transfinite_vertices.size(); // imax, Number of vertices
    cgZoneSize[1] = gf->transfinite_vertices[0].size(); // jmax
    cgZoneSize[2] = cgZoneSize[0] - 1; // Number of elements
    cgZoneSize[3] = cgZoneSize[1] - 1;
    cgZoneSize[4] = 0;
    cgZoneSize[5] = 0;

    int imax = cgZoneSize[0];
    int jmax = cgZoneSize[1];
    MVertex *v0 = gf->transfinite_vertices[0][0];
    MVertex *v1 = gf->transfinite_vertices[imax - 1][0];
    MVertex *v2 = gf->transfinite_vertices[imax - 1][jmax - 1];
    MVertex *v3 = gf->transfinite_vertices[0][jmax - 1];

    std::vector<double> dBuffer;
    std::string zoneName = "Zone_&I%4&";
    expandName(zoneName, iFace, "Zone");

    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     Structured, &cgIndexZone) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // Write the grid node
    int cgIndexGrid = 0;
    if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone, "GridCoordinates",
                     &cgIndexGrid) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // Write the grid coordinates
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

    for(std::size_t k = 0; k < gf->transfinite_vertices[0].size(); k++) {
      for(std::size_t j = 0; j < gf->transfinite_vertices.size(); j++) {
        MVertex *v = gf->transfinite_vertices[j][k];
        dBuffer[cgZoneSize[0] * k + j] = v->z() * scalingFactor;
      }
    }

    if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                      "CoordinateZ", &dBuffer[0], &cgIndexCoord) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // Writing Boundary Conditions
    BCType_t BCType(BCWallViscous); // Writes all boundary to BCWallViscous
    PointSetType_t ptsettype(PointRange);
    int numBCVert = 2;
    int cgIndexBoco = 0;
    int cgIndexConn = 0;
    int interfaceEdge = 0;
    int interfaceWritten = 0;
    cgsize_t *Point_Range = NULL;
    cgsize_t *Point_Donor_Range = NULL;
    int *Transform = NULL;
    Point_Range = new cgsize_t[4];
    Point_Donor_Range = new cgsize_t[4];
    Transform = new int[2];

    for(std::size_t iBc = 0; iBc < 4; ++iBc) {
      interfaceEdge = 0;
      interfaceWritten = 0;

      patchIndex += 1;
      std::string patchName = "Patch_&I%4&";
      expandName(patchName, patchIndex, "Patch");

      interfaceIndex += 1;
      std::string interfaceName = "Interface_&I%4&";
      expandName(interfaceName, interfaceIndex, "Interface");

      std::string adjoiningZoneName = "Zone_&I%4&";

      std::vector<int> physical_num; // Family number
      std::string physical_name; // Family name
      MVertex *v1Tmp = NULL;
      MVertex *v2Tmp = NULL;
      if(iBc == 0) { // Edge between v0-v1
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = imax;
        *(Point_Range + 3) = 1;
        physical_num = gf->transfinite_vertices[static_cast<int>(imax / 2)][0]
                         ->onWhat()
                         ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gf->model()->getPhysicalName(1, physical_num[0]);
        }
        v1Tmp = v0;
        v2Tmp = v1;
      }
      else if(iBc == 1) { // Edge between v1-v2
        *(Point_Range + 0) = imax;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = imax;
        *(Point_Range + 3) = jmax;
        physical_num =
          gf->transfinite_vertices[imax - 1][static_cast<int>(jmax / 2)]
            ->onWhat()
            ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gf->model()->getPhysicalName(1, physical_num[0]);
        }
        v1Tmp = v1;
        v2Tmp = v2;
      }
      else if(iBc == 2) { // Edge between v3-v2
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = jmax;
        *(Point_Range + 2) = imax;
        *(Point_Range + 3) = jmax;
        physical_num =
          gf->transfinite_vertices[static_cast<int>(imax / 2)][jmax - 1]
            ->onWhat()
            ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gf->model()->getPhysicalName(1, physical_num[0]);
        }
        v1Tmp = v3;
        v2Tmp = v2;
      }
      else { // Edge between v0-v3
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = 1;
        *(Point_Range + 3) = jmax;
        physical_num = gf->transfinite_vertices[0][static_cast<int>(jmax / 2)]
                         ->onWhat()
                         ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gf->model()->getPhysicalName(1, physical_num[0]);
        }
        v1Tmp = v0;
        v2Tmp = v3;
      }

      if(numInterfaceEdges > 0) {
        // Note: an edge can have interface with only one more edge
        for(std::size_t jFace = 0; jFace < faces.size(); jFace++) {
          if(jFace != iFace) {
            interfaceEdge = 0;
            GFace *gf2 = faces[jFace];
            adjoiningZoneName = "Zone_&I%4&";
            expandName(adjoiningZoneName, jFace, "Zone");

            int imax_jFace =
              gf2->transfinite_vertices.size(); // imax Number of vertices
            int jmax_jFace = gf2->transfinite_vertices[0].size(); // jmax

            MVertex *v0f2 = gf2->transfinite_vertices[0][0];
            MVertex *v1f2 = gf2->transfinite_vertices[imax_jFace - 1][0];
            MVertex *v2f2 =
              gf2->transfinite_vertices[imax_jFace - 1][jmax_jFace - 1];
            MVertex *v3f2 = gf2->transfinite_vertices[0][jmax_jFace - 1];

            if(sameVertex(v1Tmp, v0f2) &&
               sameVertex(v2Tmp, v1f2)) { // Edge v0-v1
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = 1;
              *(Point_Donor_Range + 1) = 1;
              *(Point_Donor_Range + 2) = imax_jFace;
              *(Point_Donor_Range + 3) = 1;
            }
            if(sameVertex(v1Tmp, v1f2) && sameVertex(v2Tmp, v0f2)) {
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = imax_jFace;
              *(Point_Donor_Range + 1) = 1;
              *(Point_Donor_Range + 2) = 1;
              *(Point_Donor_Range + 3) = 1;
            }
            if(sameVertex(v1Tmp, v1f2) &&
               sameVertex(v2Tmp, v2f2)) { // Edge v1-v2
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = imax_jFace;
              *(Point_Donor_Range + 1) = 1;
              *(Point_Donor_Range + 2) = imax_jFace;
              *(Point_Donor_Range + 3) = jmax_jFace;
            }
            if(sameVertex(v1Tmp, v2f2) && sameVertex(v2Tmp, v1f2)) {
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = imax_jFace;
              *(Point_Donor_Range + 1) = jmax_jFace;
              *(Point_Donor_Range + 2) = imax_jFace;
              *(Point_Donor_Range + 3) = 1;
            }
            if(sameVertex(v1Tmp, v3f2) &&
               sameVertex(v2Tmp, v2f2)) { // Edge v3-v2
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = 1;
              *(Point_Donor_Range + 1) = jmax_jFace;
              *(Point_Donor_Range + 2) = imax_jFace;
              *(Point_Donor_Range + 3) = jmax_jFace;
            }
            if(sameVertex(v1Tmp, v2f2) && sameVertex(v2Tmp, v3f2)) {
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = imax_jFace;
              *(Point_Donor_Range + 1) = jmax_jFace;
              *(Point_Donor_Range + 2) = 1;
              *(Point_Donor_Range + 3) = jmax_jFace;
            }
            if(sameVertex(v1Tmp, v0f2) &&
               sameVertex(v2Tmp, v3f2)) { // Edge v0-v3
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = 1;
              *(Point_Donor_Range + 1) = 1;
              *(Point_Donor_Range + 2) = 1;
              *(Point_Donor_Range + 3) = jmax_jFace;
            }
            if(sameVertex(v1Tmp, v3f2) && sameVertex(v2Tmp, v0f2)) {
              interfaceEdge = 1;
              *(Point_Donor_Range + 0) = 1;
              *(Point_Donor_Range + 1) = jmax_jFace;
              *(Point_Donor_Range + 2) = 1;
              *(Point_Donor_Range + 3) = 1;
            }

            // Grid Connectivity - Compute 'Transform Matrix'
            if(interfaceEdge == 1) {
              interfaceWritten = 1;

              int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
              a1 = (*(Point_Donor_Range + 2)) - (*Point_Donor_Range);
              a2 = (*(Point_Donor_Range + 3)) - (*(Point_Donor_Range + 1));
              b1 = (*(Point_Range + 2)) - (*Point_Range);
              b2 = (*(Point_Range + 3)) - (*(Point_Range + 1));

              // In the interface Face, if one index is varying, other
              // should remain constant and hence one of a1, a2, b1, b2
              // should be zero (for 2D) (Index2 - Begin2) = T.(Index1 -
              // Begin1)
              //       (Index1 - Begin1) = Transpose[T].(Index2 - Begin2)
              int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
              if(b2 == 0) {
                x1 = a1 / b1;
                y1 = a2 / b1;
                if(x1 == 0) {
                  y2 = 0;
                  if(y1 < 0) { x2 = 1; }
                  else {
                    x2 = -1;
                  };
                }
                else if(y1 == 0) {
                  x2 = 0;
                  if(x1 > 0) { y2 = 1; }
                  else {
                    y2 = -1;
                  };
                }
              }
              else if(b1 == 0) {
                x2 = a1 / b2;
                y2 = a2 / b2;
                if(x2 == 0) {
                  y1 = 0;
                  if(y2 > 0) { x1 = 1; }
                  else {
                    x1 = -1;
                  };
                }
                else if(y2 == 0) {
                  x1 = 0;
                  if(x2 < 0) { y1 = 1; }
                  else {
                    y1 = -1;
                  };
                }
              }
              else {
                Msg::Warning("Could not find transformation matrix for zone "
                             "interface - using default values [1 2] ");
                *Transform = 1;
                *(Transform + 1) = 2;
              }

              if(x1 == 1) { *Transform = 1; }
              if(x1 == -1) { *Transform = -1; }
              if(x2 == 1) { *(Transform + 1) = 1; }
              if(x2 == -1) { *(Transform + 1) = -1; }

              if(y1 == 1) { *Transform = 2; }
              if(y1 == -1) { *Transform = -2; }
              if(y2 == 1) { *(Transform + 1) = 2; }
              if(y2 == -1) { *(Transform + 1) = -2; }

              if(cg_1to1_write(cgIndexFile, cgIndexBase, cgIndexZone,
                               interfaceName.c_str(), adjoiningZoneName.c_str(),
                               Point_Range, Point_Donor_Range, Transform,
                               &cgIndexConn) != CG_OK)
                return cgnsError(__FILE__, __LINE__, cgIndexFile);
            } // End interfaceEdge == 1
          }
        }
      } // End numInterfaceEdges>0

      if((interfaceEdge == 0) && (interfaceWritten == 0)) {
        if(cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                         patchName.c_str(), BCType, ptsettype, numBCVert,
                         Point_Range, &cgIndexBoco) != CG_OK)
          return cgnsError(__FILE__, __LINE__, cgIndexFile);

        if(physical_name != "") {
          if(cg_goto(cgIndexFile, cgIndexBase, zoneName.c_str(), 0, "ZoneBC_t",
                     1, patchName.c_str(), 0, "end") != CG_OK)
            return cgnsError(__FILE__, __LINE__, cgIndexFile);
          if(cg_famname_write(physical_name.c_str()) != CG_OK)
            return cgnsError(__FILE__, __LINE__, cgIndexFile);
        }
      }

    } // End writing boco & interface for 2D mesh
  }
  return 1;
}

static int writeZonesStruct3D(int cgIndexFile, int cgIndexBase,
                              std::vector<GRegion *> &regions,
                              int numInterfaceFaces, double scalingFactor)
{
  int cgIndexZone = 0;
  cgsize_t cgZoneSize[9] = {0};
  int patchIndex = -1;
  int interfaceIndex = -1;

  for(std::size_t iRegion = 0; iRegion < regions.size(); iRegion++) {
    GRegion *gr = regions[iRegion];
    std::vector<GFace *> faces = gr->faces();
    if(faces.size() != 6) {
      Msg::Warning("Volume %d has %lu (!=6) bounding surfaces", gr->tag(),
                   faces.size());
    }

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

    MVertex *v0 = gr->transfinite_vertices[0][0][0];
    MVertex *v1 = gr->transfinite_vertices[imax - 1][0][0];
    MVertex *v2 = gr->transfinite_vertices[imax - 1][jmax - 1][0];
    MVertex *v3 = gr->transfinite_vertices[0][jmax - 1][0];
    MVertex *v4 = gr->transfinite_vertices[0][0][kmax - 1];
    MVertex *v5 = gr->transfinite_vertices[imax - 1][0][kmax - 1];
    MVertex *v6 = gr->transfinite_vertices[imax - 1][jmax - 1][kmax - 1];
    MVertex *v7 = gr->transfinite_vertices[0][jmax - 1][kmax - 1];

    std::vector<double> dBuffer;
    std::string zoneName = "Zone_&I%4&";
    expandName(zoneName, iRegion, "Zone");

    if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                     Structured, &cgIndexZone) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // Write the grid node
    int cgIndexGrid = 0;
    if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone, "GridCoordinates",
                     &cgIndexGrid) != CG_OK)
      return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // Write the grid coordinates
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

    // Writing Boundary Conditions
    BCType_t BCType(BCWallViscous); // Writes all boundary to BCWallViscous
    PointSetType_t ptsettype(PointRange);
    int numBCVert = 2;
    int cgIndexBoco = 0;
    int cgIndexConn = 0;
    int interfaceFace = 0;
    int interfaceFaceWritten = 0;
    cgsize_t *Point_Range = NULL;
    cgsize_t *Point_Donor_Range = NULL;
    int *Transform = NULL;
    Point_Range = new cgsize_t[6];
    Point_Donor_Range = new cgsize_t[6];
    Transform = new int[3];

    for(std::size_t iBc = 0; iBc < 6; ++iBc) {
      interfaceFace = 0;
      interfaceFaceWritten = 0;

      patchIndex += 1;
      std::string patchName = "Patch_&I%4&";
      expandName(patchName, patchIndex, "Patch");

      interfaceIndex += 1;
      std::string interfaceName = "Interface_&I%4&";
      expandName(interfaceName, interfaceIndex, "Interface");

      std::string adjoiningZoneName = "Zone_&I%4&";

      MVertex *v0Tmp = NULL;
      MVertex *v1Tmp = NULL;
      MVertex *v2Tmp = NULL;
      MVertex *v3Tmp = NULL;

      std::vector<int> physical_num; // Family number
      std::string physical_name; // Family name
      if(iBc == 0) { // i = imin face
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = 1;
        *(Point_Range + 3) = 1;
        *(Point_Range + 4) = jmax;
        *(Point_Range + 5) = kmax;
        physical_num = gr->transfinite_vertices[0][static_cast<int>(jmax / 2)]
                                               [static_cast<int>(kmax / 2)]
                                                 ->onWhat()
                                                 ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gr->model()->getPhysicalName(2, physical_num[0]);
        }
        v0Tmp = v0;
        v1Tmp = v3;
        v2Tmp = v7;
        v3Tmp = v4;
      }
      else if(iBc == 1) { // i = imax face
        *(Point_Range + 0) = imax;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = 1;
        *(Point_Range + 3) = imax;
        *(Point_Range + 4) = jmax;
        *(Point_Range + 5) = kmax;
        physical_num =
          gr->transfinite_vertices[imax - 1][static_cast<int>(jmax / 2)]
                                  [static_cast<int>(kmax / 2)]
                                    ->onWhat()
                                    ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gr->model()->getPhysicalName(2, physical_num[0]);
        }
        v0Tmp = v1;
        v1Tmp = v2;
        v2Tmp = v6;
        v3Tmp = v5;
      }
      else if(iBc == 2) { // j = jmin face
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = 1;
        *(Point_Range + 3) = imax;
        *(Point_Range + 4) = 1;
        *(Point_Range + 5) = kmax;
        physical_num = gr->transfinite_vertices[static_cast<int>(imax / 2)][0]
                                               [static_cast<int>(kmax / 2)]
                                                 ->onWhat()
                                                 ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gr->model()->getPhysicalName(2, physical_num[0]);
        }
        v0Tmp = v0;
        v1Tmp = v1;
        v2Tmp = v5;
        v3Tmp = v4;
      }
      else if(iBc == 3) { // j = jmax face
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = jmax;
        *(Point_Range + 2) = 1;
        *(Point_Range + 3) = imax;
        *(Point_Range + 4) = jmax;
        *(Point_Range + 5) = kmax;
        physical_num =
          gr->transfinite_vertices[static_cast<int>(imax / 2)][jmax - 1]
                                  [static_cast<int>(kmax / 2)]
                                    ->onWhat()
                                    ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gr->model()->getPhysicalName(2, physical_num[0]);
        }
        v0Tmp = v3;
        v1Tmp = v2;
        v2Tmp = v6;
        v3Tmp = v7;
      }
      else if(iBc == 4) { // k = kmin face
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = 1;
        *(Point_Range + 3) = imax;
        *(Point_Range + 4) = jmax;
        *(Point_Range + 5) = 1;
        physical_num = gr->transfinite_vertices[static_cast<int>(imax / 2)]
                                               [static_cast<int>(jmax / 2)][0]
                                                 ->onWhat()
                                                 ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gr->model()->getPhysicalName(2, physical_num[0]);
        }
        v0Tmp = v0;
        v1Tmp = v1;
        v2Tmp = v2;
        v3Tmp = v3;
      }
      else { // k = kmax face
        *(Point_Range + 0) = 1;
        *(Point_Range + 1) = 1;
        *(Point_Range + 2) = kmax;
        *(Point_Range + 3) = imax;
        *(Point_Range + 4) = jmax;
        *(Point_Range + 5) = kmax;
        physical_num =
          gr->transfinite_vertices[static_cast<int>(imax / 2)]
                                  [static_cast<int>(jmax / 2)][kmax - 1]
                                    ->onWhat()
                                    ->physicals;
        if(physical_num.size() > 0) {
          physical_name = gr->model()->getPhysicalName(2, physical_num[0]);
        }
        v0Tmp = v4;
        v1Tmp = v5;
        v2Tmp = v6;
        v3Tmp = v7;
      }

      if(numInterfaceFaces >
         0) { // Note: An Face can have interface with only one ore Face
        if(isInterfaceFace(regions, v0Tmp, v1Tmp, v2Tmp, v3Tmp)) {
          for(std::size_t jRegion = 0; jRegion < regions.size(); jRegion++) {
            if(jRegion != iRegion) {
              interfaceFace = 0;
              adjoiningZoneName = "Zone_&I%4&";
              expandName(adjoiningZoneName, jRegion, "Zone");

              GRegion *gr2 = regions[jRegion];

              int imax_Region2 = gr2->transfinite_vertices.size();
              int jmax_Region2 = gr2->transfinite_vertices[0].size();
              int kmax_Region2 = gr2->transfinite_vertices[0][0].size();

              MVertex *v0R2 = gr2->transfinite_vertices[0][0][0];
              MVertex *v1R2 = gr2->transfinite_vertices[imax_Region2 - 1][0][0];
              MVertex *v2R2 =
                gr2
                  ->transfinite_vertices[imax_Region2 - 1][jmax_Region2 - 1][0];
              MVertex *v3R2 = gr2->transfinite_vertices[0][jmax_Region2 - 1][0];
              MVertex *v4R2 = gr2->transfinite_vertices[0][0][kmax_Region2 - 1];
              MVertex *v5R2 =
                gr2
                  ->transfinite_vertices[imax_Region2 - 1][0][kmax_Region2 - 1];
              MVertex *v6R2 =
                gr2->transfinite_vertices[imax_Region2 - 1][jmax_Region2 - 1]
                                         [kmax_Region2 - 1];
              MVertex *v7R2 =
                gr2
                  ->transfinite_vertices[0][jmax_Region2 - 1][kmax_Region2 - 1];

              if(isInterfaceFace(regions, v0R2, v3R2, v7R2,
                                 v4R2)) { // i = imin face
                if(sameFace(v0Tmp, v1Tmp, v2Tmp, v3Tmp, v0R2, v3R2, v7R2,
                            v4R2)) {
                  interfaceFace = 1;
                  *(Point_Donor_Range + 0) = 1;
                  *(Point_Donor_Range + 1) = 1;
                  *(Point_Donor_Range + 2) = 1;
                  *(Point_Donor_Range + 3) = 1;
                  *(Point_Donor_Range + 4) = jmax_Region2;
                  *(Point_Donor_Range + 5) = kmax_Region2;
                }
              }
              if(isInterfaceFace(regions, v1R2, v2R2, v6R2,
                                 v5R2)) { // i = imax face
                if(sameFace(v0Tmp, v1Tmp, v2Tmp, v3Tmp, v1R2, v2R2, v6R2,
                            v5R2)) {
                  interfaceFace = 1;
                  *(Point_Donor_Range + 0) = imax_Region2;
                  *(Point_Donor_Range + 1) = 1;
                  *(Point_Donor_Range + 2) = 1;
                  *(Point_Donor_Range + 3) = imax_Region2;
                  *(Point_Donor_Range + 4) = jmax_Region2;
                  *(Point_Donor_Range + 5) = kmax_Region2;
                }
              }
              if(isInterfaceFace(regions, v0R2, v1R2, v5R2,
                                 v4R2)) { // j = jmin face
                if(sameFace(v0Tmp, v1Tmp, v2Tmp, v3Tmp, v0R2, v1R2, v5R2,
                            v4R2)) {
                  interfaceFace = 1;
                  *(Point_Donor_Range + 0) = 1;
                  *(Point_Donor_Range + 1) = 1;
                  *(Point_Donor_Range + 2) = 1;
                  *(Point_Donor_Range + 3) = imax_Region2;
                  *(Point_Donor_Range + 4) = 1;
                  *(Point_Donor_Range + 5) = kmax_Region2;
                }
              }
              if(isInterfaceFace(regions, v3R2, v2R2, v6R2,
                                 v7R2)) { // j = jmax face
                if(sameFace(v0Tmp, v1Tmp, v2Tmp, v3Tmp, v3R2, v2R2, v6R2,
                            v7R2)) {
                  interfaceFace = 1;
                  *(Point_Donor_Range + 0) = 1;
                  *(Point_Donor_Range + 1) = jmax_Region2;
                  *(Point_Donor_Range + 2) = 1;
                  *(Point_Donor_Range + 3) = imax_Region2;
                  *(Point_Donor_Range + 4) = jmax_Region2;
                  *(Point_Donor_Range + 5) = kmax_Region2;
                }
              }
              if(isInterfaceFace(regions, v0R2, v1R2, v2R2,
                                 v3R2)) { // k = kmin face
                if(sameFace(v0Tmp, v1Tmp, v2Tmp, v3Tmp, v0R2, v1R2, v2R2,
                            v3R2)) {
                  interfaceFace = 1;
                  *(Point_Donor_Range + 0) = 1;
                  *(Point_Donor_Range + 1) = 1;
                  *(Point_Donor_Range + 2) = 1;
                  *(Point_Donor_Range + 3) = imax_Region2;
                  *(Point_Donor_Range + 4) = jmax_Region2;
                  *(Point_Donor_Range + 5) = 1;
                }
              }
              if(isInterfaceFace(regions, v4R2, v5R2, v6R2,
                                 v7R2)) { // k = kmax face
                if(sameFace(v0Tmp, v1Tmp, v2Tmp, v3Tmp, v4R2, v5R2, v6R2,
                            v7R2)) {
                  interfaceFace = 1;
                  *(Point_Donor_Range + 0) = 1;
                  *(Point_Donor_Range + 1) = 1;
                  *(Point_Donor_Range + 2) = kmax_Region2;
                  *(Point_Donor_Range + 3) = imax_Region2;
                  *(Point_Donor_Range + 4) = jmax_Region2;
                  *(Point_Donor_Range + 5) = kmax_Region2;
                }
              }

              // Grid Connectivity
              if(interfaceFace == 1) {
                interfaceFaceWritten = 1;

                int a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
                a1 = (*(Point_Donor_Range + 3)) - (*(Point_Donor_Range + 0));
                a2 = (*(Point_Donor_Range + 4)) - (*(Point_Donor_Range + 1));
                a3 = (*(Point_Donor_Range + 5)) - (*(Point_Donor_Range + 2));
                b1 = (*(Point_Range + 3)) - (*(Point_Range + 0));
                b2 = (*(Point_Range + 4)) - (*(Point_Range + 1));
                b3 = (*(Point_Range + 5)) - (*(Point_Range + 2));

                // In the interface Face, if one index is varying, other
                // should remain constant and hence one of a1, a2, b1, b2
                // should be zero (for 2D) (Index2 - Begin2) = T.(Index1 -
                // Begin1) (Index1 - Begin1) = Transpose[T].(Index2 -
                // Begin2)

                int x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0, x3 = 0,
                    y3 = 0, z3 = 0;
                if((b1 == a1) && (b1 != 0)) { x1 = 1; }
                if((b1 == -a1) && (b1 != 0)) { x1 = -1; }
                if((b1 == a2) && (b1 != 0)) { x2 = 1; }
                if((b1 == -a2) && (b1 != 0)) { x2 = -1; }
                if((b1 == a3) && (b1 != 0)) { x3 = 1; }
                if((b1 == -a3) && (b1 != 0)) { x3 = -1; }

                if((b2 == a1) && (b2 != 0)) { y1 = 1; }
                if((b2 == -a1) && (b2 != 0)) { y1 = -1; }
                if((b2 == a2) && (b2 != 0)) { y2 = 1; }
                if((b2 == -a2) && (b2 != 0)) { y2 = -1; }
                if((b2 == a3) && (b2 != 0)) { y3 = 1; }
                if((b2 == -a3) && (b2 != 0)) { y3 = -1; }

                if((b3 == a1) && (b3 != 0)) { z1 = 1; }
                if((b3 == -a1) && (b3 != 0)) { z1 = -1; }
                if((b3 == a2) && (b3 != 0)) { z2 = 1; }
                if((b3 == -a2) && (b3 != 0)) { z2 = -1; }
                if((b3 == a3) && (b3 != 0)) { z3 = 1; }
                if((b3 == -a3) && (b3 != 0)) { z3 = -1; }

                if((b1 == a2) && (b1 == a3) && (a1 == 0)) {
                  if(b2 == b1) {
                    x2 = 0;
                    x3 = 1;
                    y2 = 1;
                    y3 = 0;
                  }
                  if(b3 == b1) {
                    x2 = 1;
                    x3 = 0;
                    z2 = 0;
                    z3 = 1;
                  }
                }
                if((b1 == a3) && (b1 == a1) && (a2 == 0)) {
                  if(b2 == b1) {
                    x1 = 1;
                    x3 = 0;
                    y1 = 0;
                    y3 = 1;
                  }
                  if(b3 == b1) {
                    x1 = 1;
                    x3 = 0;
                    z1 = 0;
                    z3 = 1;
                  }
                }
                if((b1 == a1) && (b1 == a2) && (a3 == 0)) {
                  if(b2 == b1) {
                    x1 = 1;
                    x2 = 0;
                    y1 = 0;
                    y2 = 1;
                  }
                  if(b3 == b1) {
                    x1 = 1;
                    x2 = 0;
                    z1 = 0;
                    z2 = 1;
                  }
                }
                if((b1 == -a2) && (b1 == -a3) && (a1 == 0)) {
                  if(b2 == b1) {
                    x2 = 0;
                    x3 = -1;
                    y2 = -1;
                    y3 = 0;
                  }
                  if(b3 == b1) {
                    x2 = -1;
                    x3 = 0;
                    z2 = 0;
                    z3 = -1;
                  }
                }
                if((b1 == -a3) && (b1 == -a1) && (a2 == 0)) {
                  if(b2 == b1) {
                    x1 = -1;
                    x3 = 0;
                    y1 = 0;
                    y3 = -1;
                  }
                  if(b3 == b1) {
                    x1 = -1;
                    x3 = 0;
                    z1 = 0;
                    z3 = -1;
                  }
                }
                if((b1 == -a1) && (b1 == -a2) && (a3 == 0)) {
                  if(b2 == b1) {
                    x1 = -1;
                    x2 = 0;
                    y1 = 0;
                    y2 = -1;
                  }
                  if(b3 == b1) {
                    x1 = -1;
                    x2 = 0;
                    z1 = 0;
                    z2 = -1;
                  }
                }

                if((b2 == a2) && (b2 == a3) && (a1 == 0)) {
                  if(b1 == b2) {
                    x2 = 1;
                    x3 = 0;
                    y2 = 0;
                    y3 = 1;
                  }
                  if(b3 == b2) {
                    y2 = 1;
                    y3 = 0;
                    z2 = 0;
                    z3 = 1;
                  }
                }
                if((b2 == a3) && (b2 == a1) && (a2 == 0)) {
                  if(b1 == b2) {
                    x1 = 1;
                    x3 = 0;
                    y1 = 0;
                    y3 = 1;
                  }
                  if(b3 == b2) {
                    y1 = 1;
                    y3 = 0;
                    z1 = 0;
                    z3 = 1;
                  }
                }
                if((b2 == a1) && (b2 == a2) && (a3 == 0)) {
                  if(b1 == b2) {
                    x1 = 1;
                    x2 = 0;
                    y1 = 0;
                    y2 = 1;
                  }
                  if(b3 == b2) {
                    y1 = 1;
                    y2 = 0;
                    z1 = 0;
                    z2 = 1;
                  }
                }
                if((b2 == -a2) && (b2 == -a3) && (a1 == 0)) {
                  if(b1 == b2) {
                    x2 = -1;
                    x3 = 0;
                    y2 = 0;
                    y3 = -1;
                  }
                  if(b3 == b2) {
                    y2 = -1;
                    y3 = 0;
                    z2 = 0;
                    z3 = -1;
                  }
                }
                if((b2 == -a3) && (b2 == -a1) && (a2 == 0)) {
                  if(b1 == b2) {
                    x1 = -1;
                    x3 = 0;
                    y1 = 0;
                    y3 = -1;
                  }
                  if(b3 == b2) {
                    y1 = -1;
                    y3 = 0;
                    z1 = 0;
                    z3 = -1;
                  }
                }
                if((b2 == -a1) && (b2 == -a2) && (a3 == 0)) {
                  if(b1 == b2) {
                    x1 = -1;
                    x2 = 0;
                    y1 = 0;
                    y2 = -1;
                  }
                  if(b3 == b2) {
                    y1 = -1;
                    y2 = 0;
                    z1 = 0;
                    z2 = -1;
                  }
                }

                if((b3 == a2) && (b3 == a3) && (a1 == 0)) {
                  if(b1 == b3) {
                    x2 = 1;
                    x3 = 0;
                    z2 = 0;
                    z3 = 1;
                  }
                  if(b2 == b3) {
                    y2 = 1;
                    y3 = 0;
                    z2 = 0;
                    z3 = 1;
                  }
                }
                if((b3 == a3) && (b3 == a1) && (a2 == 0)) {
                  if(b1 == b3) {
                    x1 = 1;
                    x3 = 0;
                    z1 = 0;
                    z3 = 1;
                  }
                  if(b2 == b3) {
                    y1 = 1;
                    y3 = 0;
                    z1 = 0;
                    z3 = 1;
                  }
                }
                if((b3 == a1) && (b3 == a2) && (a3 == 0)) {
                  if(b1 == b3) {
                    x1 = 1;
                    x2 = 0;
                    z1 = 0;
                    z2 = 1;
                  }
                  if(b2 == b3) {
                    y1 = 1;
                    y2 = 0;
                    z1 = 0;
                    z2 = 1;
                  }
                }

                if((b1 == 0) && (a1 == 0)) {
                  x1 = 1;
                  if(((*(Point_Range + 0) == 1) &&
                      (*(Point_Donor_Range + 0) == 1)) ||
                     ((*(Point_Range + 0) != 1) &&
                      (*(Point_Donor_Range + 0) != 1)))
                    x1 = -1;
                }
                if((b1 == 0) && (a2 == 0)) {
                  x2 = 1;
                  if(((*(Point_Range + 0) == 1) &&
                      (*(Point_Donor_Range + 1) == 1)) ||
                     ((*(Point_Range + 0) != 1) &&
                      (*(Point_Donor_Range + 1) != 1)))
                    x2 = -1;
                }
                if((b1 == 0) && (a3 == 0)) {
                  x3 = 1;
                  if(((*(Point_Range + 0) == 1) &&
                      (*(Point_Donor_Range + 2) == 1)) ||
                     ((*(Point_Range + 0) != 1) &&
                      (*(Point_Donor_Range + 2) != 1)))
                    x3 = -1;
                }
                if((b2 == 0) && (a1 == 0)) {
                  y1 = 1;
                  if(((*(Point_Range + 1) == 1) &&
                      (*(Point_Donor_Range + 0) == 1)) ||
                     ((*(Point_Range + 1) != 1) &&
                      (*(Point_Donor_Range + 0) != 1)))
                    y1 = -1;
                }
                if((b2 == 0) && (a2 == 0)) {
                  y2 = 1;
                  if(((*(Point_Range + 1) == 1) &&
                      (*(Point_Donor_Range + 1) == 1)) ||
                     ((*(Point_Range + 1) != 1) &&
                      (*(Point_Donor_Range + 1) != 1)))
                    y2 = -1;
                }
                if((b2 == 0) && (a3 == 0)) {
                  y3 = 1;
                  if(((*(Point_Range + 1) == 1) &&
                      (*(Point_Donor_Range + 2) == 1)) ||
                     ((*(Point_Range + 1) != 1) &&
                      (*(Point_Donor_Range + 2) != 1)))
                    y3 = -1;
                }
                if((b3 == 0) && (a1 == 0)) {
                  z1 = 1;
                  if(((*(Point_Range + 2) == 1) &&
                      (*(Point_Donor_Range + 0) == 1)) ||
                     ((*(Point_Range + 2) != 1) &&
                      (*(Point_Donor_Range + 0) != 1)))
                    z1 = -1;
                }
                if((b3 == 0) && (a2 == 0)) {
                  z2 = 1;
                  if(((*(Point_Range + 2) == 1) &&
                      (*(Point_Donor_Range + 1) == 1)) ||
                     ((*(Point_Range + 2) != 1) &&
                      (*(Point_Donor_Range + 1) != 1)))
                    z2 = -1;
                }
                if((b3 == 0) && (a3 == 0)) {
                  z3 = 1;
                  if(((*(Point_Range + 2) == 1) &&
                      (*(Point_Donor_Range + 2) == 1)) ||
                     ((*(Point_Range + 2) != 1) &&
                      (*(Point_Donor_Range + 2) != 1)))
                    z3 = -1;
                }

                int det_A = x1 * y2 * z3 + x2 * y3 * z1 + x3 * y1 * z2 -
                            x1 * y3 * z2 - x2 * y1 * z3 - x3 * y2 * z1;
                if(!((det_A == 1) || (det_A == -1))) {
                  Msg::Warning("Could not find transforation matrix: "
                               "determinant != +/-1  (= %i)",
                               det_A);
                }

                if((x1 == 1) && (x2 == 0) && (x3 == 0)) {
                  *(Transform + 0) = 1;
                }
                if((x1 == -1) && (x2 == 0) && (x3 == 0)) {
                  *(Transform + 0) = -1;
                }
                if((x1 == 0) && (x2 == 1) && (x3 == 0)) {
                  *(Transform + 0) = 2;
                }
                if((x1 == 0) && (x2 == -1) && (x3 == 0)) {
                  *(Transform + 0) = -2;
                }
                if((x1 == 0) && (x2 == 0) && (x3 == 1)) {
                  *(Transform + 0) = 3;
                }
                if((x1 == 0) && (x2 == 0) && (x3 == -1)) {
                  *(Transform + 0) = -3;
                }

                if((y1 == 1) && (y2 == 0) && (y3 == 0)) {
                  *(Transform + 1) = 1;
                }
                if((y1 == -1) && (y2 == 0) && (y3 == 0)) {
                  *(Transform + 1) = -1;
                }
                if((y1 == 0) && (y2 == 1) && (y3 == 0)) {
                  *(Transform + 1) = 2;
                }
                if((y1 == 0) && (y2 == -1) && (y3 == 0)) {
                  *(Transform + 1) = -2;
                }
                if((y1 == 0) && (y2 == 0) && (y3 == 1)) {
                  *(Transform + 1) = 3;
                }
                if((y1 == 0) && (y2 == 0) && (y3 == -1)) {
                  *(Transform + 1) = -3;
                }

                if((z1 == 1) && (z2 == 0) && (z3 == 0)) {
                  *(Transform + 2) = 1;
                }
                if((z1 == -1) && (z2 == 0) && (z3 == 0)) {
                  *(Transform + 2) = -1;
                }
                if((z1 == 0) && (z2 == 1) && (z3 == 0)) {
                  *(Transform + 2) = 2;
                }
                if((z1 == 0) && (z2 == -1) && (z3 == 0)) {
                  *(Transform + 2) = -2;
                }
                if((z1 == 0) && (z2 == 0) && (z3 == 1)) {
                  *(Transform + 2) = 3;
                }
                if((z1 == 0) && (z2 == 0) && (z3 == -1)) {
                  *(Transform + 2) = -3;
                }

                if(cg_1to1_write(cgIndexFile, cgIndexBase, cgIndexZone,
                                 interfaceName.c_str(),
                                 adjoiningZoneName.c_str(), Point_Range,
                                 Point_Donor_Range, Transform,
                                 &cgIndexConn) != CG_OK)
                  return cgnsError(__FILE__, __LINE__, cgIndexFile);
              } // End interfaceFace == 1
            }
          }
        }
      } // End numInterfaceFaces>0

      if((interfaceFace == 0) && (interfaceFaceWritten == 0)) {
        if(cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                         patchName.c_str(), BCType, ptsettype, numBCVert,
                         Point_Range, &cgIndexBoco) != CG_OK)
          return cgnsError(__FILE__, __LINE__, cgIndexFile);
        if(physical_name != "") {
          if(cg_goto(cgIndexFile, cgIndexBase, zoneName.c_str(), 0, "ZoneBC_t",
                     1, patchName.c_str(), 0, "end") != CG_OK)
            return cgnsError(__FILE__, __LINE__, cgIndexFile);
          if(cg_famname_write(physical_name.c_str()) != CG_OK)
            return cgnsError(__FILE__, __LINE__, cgIndexFile);
        }
      }

    } // End writing boco & interface for 3D mesh
  }
  return 1;
}

int writeZonesStruct(GModel *model, double scalingFactor, int cgIndexFile,
                     int cgIndexBase)
{
  int meshDim = -1;

  std::vector<GEdge *> edges;
  for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it) {
    edges.push_back(*it);
  }

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

  // Interface Face would be counted by the both regions that they are part of
  // (3D). Sum up the number of faces for each region and subtract total number
  // of faces of the model to get the number of interface faces
  int numInterfaceFaces = 0;
  if(meshDim == 3) {
    int numTotFaces = 0;
    for(std::size_t i = 0; i < regions.size(); i++) {
      numTotFaces += regions[i]->faces().size();
    }
    numInterfaceFaces = numTotFaces - faces.size();
  }

  // Interface edge would be counted by the both faces that they are part of (
  // 2D). Sum up the number of edges for each face and subtract total number of
  // edges of the model to get the number of interface edges
  int numInterfaceEdges = 0;
  if(meshDim == 2) {
    int numTotEdges = 0;
    for(std::size_t i = 0; i < faces.size(); i++) {
      numTotEdges += faces[i]->edges().size();
    }
    numInterfaceEdges = numTotEdges - edges.size();
  }

  // Checking Orientation of the mesh
  if(meshDim == 2 && faces.size() > 1) {
    double n[3];
    faceOrientationTransfinite(faces[0], n);
    for(std::size_t iFace = 1; iFace < faces.size(); iFace++) {
      double n2[3];
      faceOrientationTransfinite(faces[iFace], n2);
      if(fabs(n[0] - n2[0]) > 1e-6 || fabs(n[1] - n2[1]) > 1e-6 ||
         fabs(n[2] - n2[2]) > 1e-6) {
        Msg::Warning("Transfinite meshes for surfaces %d and %d have different "
                     "orientation",
                     faces[0]->tag(), faces[iFace]->tag());
      }
    }
  }
  else if(meshDim == 3 && regions.size() > 1) {
    int o = volumeOrientationTransfinite(regions[0]);
    for(std::size_t iRegion = 0; iRegion < regions.size(); iRegion++) {
      if(volumeOrientationTransfinite(regions[iRegion]) != o) {
        Msg::Warning("Transfinite meshes for regions %d and %d have different "
                     "orientation",
                     regions[0]->tag(), regions[iRegion]->tag());
      }
    }
  }

  if(meshDim == 2) {
    if(writeZonesStruct2D(cgIndexFile, cgIndexBase, faces, numInterfaceEdges,
                          scalingFactor))
      return 1;
  }
  else if(meshDim == 3) {
    if(writeZonesStruct3D(cgIndexFile, cgIndexBase, regions, numInterfaceFaces,
                          scalingFactor))
      return 1;
  }

  return 0;
}
