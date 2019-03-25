// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   S. Guzik
//   B. Gorissen
//   K. Hillewart

// The first part of this file (before #include "CGNSUtils.h") reads CGNS data.
//
// The second part of this file (after #include "CGNSUtils.h") writes CGNS
// data. This second part is copyright 2008 S. Guzik, C. Geuzaine and
// J.-F. Remacle. It will be rewritten (or removed) in a future release. In
// particular, CGNSUtils.h will be removed.

#include <string>
#include "GmshConfig.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "CGNSOptions.h"

#if defined(HAVE_LIBCGNS)

#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "Context.h"
#include "Options.h"
#include "affineTransformation.h"
#include "BasisFactory.h"
#include "SVector3.h"
#include "fullMatrix.h"
#include "GmshDefines.h"

#if defined(HAVE_FLTK)
#include "extraDialogs.h"
#include "FlGui.h"
#endif

namespace CGNS {
#include <cgnslib.h>
}

using namespace CGNS;

#define maxLenCGNS 32

static int parentFromCGNSType(ElementType_t cgnsType)
{
  switch(cgnsType) {
  case NODE: return TYPE_PNT;
  case BAR_2:
  case BAR_3:
  case BAR_4:
  case BAR_5: return TYPE_LIN;
  case TRI_3:
  case TRI_6:
  case TRI_9:
  case TRI_10:
  case TRI_12:
  case TRI_15: return TYPE_TRI;
  case QUAD_4:
  case QUAD_9:
  case QUAD_16:
  case QUAD_25:
  case QUAD_8:
  case QUAD_12:
  case QUAD_P4_16: return TYPE_QUA;
  case TETRA_4:
  case TETRA_10:
  case TETRA_20:
  case TETRA_35:
  case TETRA_16:
  case TETRA_22:
  case TETRA_34: return TYPE_TET;
  case PYRA_5:
  case PYRA_14:
  case PYRA_30:
  case PYRA_55:
  case PYRA_13:
  case PYRA_21:
  case PYRA_P4_29:
  case PYRA_29:
  case PYRA_50: return TYPE_PYR;
  case PENTA_6:
  case PENTA_18:
  case PENTA_40:
  case PENTA_75:
  case PENTA_15:
  case PENTA_24:
  case PENTA_33:
  case PENTA_38:
  case PENTA_66: return TYPE_PRI;
  case HEXA_8:
  case HEXA_27:
  case HEXA_64:
  case HEXA_125:
  case HEXA_20:
  case HEXA_32:
  case HEXA_44:
  case HEXA_56:
  case HEXA_98: return TYPE_HEX;
  case MIXED:
  case NGON_n:
  case NFACE_n:
  case ElementTypeUserDefined:
  case ElementTypeNull:
    Msg::Warning("Finding parent type for unsupported CGNS element type %i",
                 cgnsType);
    return -1;
  }
  return -1;
}

static int orderFromCGNSType(ElementType_t cgnsType)
{
  switch(cgnsType) {
  case NODE: return 0;
  case BAR_2:
  case TRI_3:
  case QUAD_4:
  case TETRA_4:
  case PYRA_5:
  case PENTA_6:
  case HEXA_8: return 1;
  case BAR_3:
  case TRI_6:
  case QUAD_9:
  case TETRA_10:
  case PYRA_14:
  case PENTA_18:
  case HEXA_27:
  case QUAD_8:
  case PYRA_13:
  case PENTA_15:
  case HEXA_20: return 2;
  case BAR_4:
  case TRI_10:
  case QUAD_16:
  case TETRA_20:
  case PYRA_30:
  case PENTA_40:
  case HEXA_64:
  case TRI_9:
  case QUAD_12:
  case TETRA_16:
  case PYRA_21:
  case PENTA_24:
  case HEXA_32:
  case PYRA_29:
  case PENTA_38:
  case HEXA_56: return 3;
  case BAR_5:
  case TRI_15:
  case QUAD_25:
  case TETRA_35:
  case PYRA_55:
  case PENTA_75:
  case HEXA_125:
  case TRI_12:
  case QUAD_P4_16:
  case TETRA_22:
  case PYRA_P4_29:
  case PENTA_33:
  case HEXA_44:
  case TETRA_34:
  case PYRA_50:
  case PENTA_66:
  case HEXA_98: return 4;
  case MIXED:
  case NGON_n:
  case NFACE_n:
  case ElementTypeUserDefined:
  case ElementTypeNull:
    Msg::Warning("Finding order for unsupported CGNS element type %i",
                 cgnsType);
    return -1;
  }
  return -1;
}

static bool completeCGNSType(ElementType_t cgnsType)
{
  switch(cgnsType) {
    // complete elements
  case NODE:
  case BAR_2:
  case TRI_3:
  case QUAD_4:
  case TETRA_4:
  case PYRA_5:
  case PENTA_6:
  case HEXA_8:
  case BAR_3:
  case TRI_6:
  case QUAD_9:
  case TETRA_10:
  case PYRA_14:
  case PENTA_18:
  case HEXA_27:
  case BAR_4:
  case TRI_10:
  case QUAD_16:
  case TETRA_20:
  case PYRA_30:
  case PENTA_40:
  case HEXA_64:
  case BAR_5:
  case TRI_15:
  case QUAD_25:
  case TETRA_35:
  case PYRA_55:
  case PENTA_75:
  case HEXA_125:
    return true;
    // serendipity edge elements
  case QUAD_8:
  case PYRA_13:
  case PENTA_15:
  case HEXA_20:
  case QUAD_12:
  case TETRA_16:
  case PYRA_21:
  case PENTA_24:
  case HEXA_32:
  case TRI_12:
  case QUAD_P4_16:
  case TETRA_22:
  case PYRA_P4_29:
  case PENTA_33:
  case HEXA_44:
    return false;
    // serendipity elements
  case PYRA_29:
  case PENTA_38:
  case HEXA_56:
  case TETRA_34:
  case PYRA_50:
  case PENTA_66:
  case HEXA_98:
  default: return false;
  }
  return false;
}

static int tagFromCGNSType(ElementType_t cgnsType)
{
  return ElementType::getType(parentFromCGNSType(cgnsType),
                              orderFromCGNSType(cgnsType),
                              !completeCGNSType(cgnsType));
}

static std::vector<SVector3> generatePointsCGNS(int, int, bool, bool);

static void addEdgePointsCGNS(const SVector3 p0, const SVector3 p1, int order,
                       std::vector<SVector3> &points)
{
  double ds = 1. / order;
  for(int i = 1; i < order; i++) {
    double f = ds * i;
    points.push_back(p0 * (1. - f) + p1 * f);
  }
}

static void addTriPointsCGNS(const SVector3 p0, const SVector3 p1,
                             const SVector3 p2,
                             int order, bool equidistant,
                             std::vector<SVector3> &points)
{
  std::vector<SVector3> triPoints =
    generatePointsCGNS(TYPE_TRI, order - 3, true, true);

  double scale = double(order - 3) / double(order);
  SVector3 offset(1. / order, 1. / order, 0);

  for(size_t i = 0; i < triPoints.size(); i++) {
    SVector3 ip = triPoints[i];
    double u = ip[0] * scale + 1. / order;
    double v = ip[1] * scale + 1. / order;

    SVector3 pt = (1. - u - v) * p0 + u * p1 + v * p2;

    points.push_back(pt);
  }
}

static void addQuaPointsCGNS(int order, std::vector<SVector3> &points)
{
  if(order > 2) {
    double scale = double(order - 2) / double(order);

    SVector3 corner[4] = {SVector3(-1, -1, 0), SVector3(1, -1, 0),
                          SVector3(1, 1, 0), SVector3(-1, 1, 0)};

    for(int i = 0; i < 4; i++) {
      SVector3 c1 = corner[i];
      SVector3 c2 = corner[(i + 1) % 4];
      double ds = 1. / (order - 2);
      for(int i = 0; i < order - 2; i++)
        points.push_back((c1 * (1. - i * ds) + c2 * (i * ds)) * scale);
    }
  }
  if(order == 2 || order == 4) points.push_back(SVector3(0, 0, 0));
}

static void addQuaPointsCGNS(const SVector3 p0, const SVector3 p1,
                             const SVector3 p2, const SVector3 p3,
                             int order, std::vector<SVector3> &points)
{
  std::vector<SVector3> quaPoints;

  addQuaPointsCGNS(order, quaPoints);

  for(size_t i = 0; i < quaPoints.size(); i++) {
    SVector3 ip = quaPoints[i];
    double u = ip[0];
    double v = ip[1];
    SVector3 pt = ((1. - u) * (1. - v) * p0 + (1. + u) * (1. - v) * p1 +
                   (1. + u) * (1. + v) * p2 + (1. - u) * (1. + v) * p3) *
                  0.25;
    points.push_back(pt);
  }
}

static std::vector<SVector3> generatePointsCGNS(int parentType, int order,
                                                bool complete, bool equidistant)
{
  std::vector<SVector3> pp;

  if(order == 0) pp.push_back(SVector3(0, 0, 0));
  if(order > 0) {
    switch(parentType) {
    case TYPE_LIN: {
      // principal vertices
      pp.push_back(SVector3(-1, 0, 0));
      pp.push_back(SVector3(1, 0, 0));

      // internal points
      addEdgePointsCGNS(pp[0], pp[1], order, pp);

      break;
    }
    case TYPE_TRI: {
      // principal vertices
      pp.push_back(SVector3(0, 0, 0));
      pp.push_back(SVector3(1, 0, 0));
      pp.push_back(SVector3(0, 1, 0));

      // internal points of edges
      for(int i = 0; i < 3; i++)
        addEdgePointsCGNS(pp[i], pp[(i + 1) % 3], order, pp);

      // internal points
      if(complete && order > 2) {
        addTriPointsCGNS(pp[0], pp[1], pp[2], order, equidistant, pp);
      }

      break;
    }
    case TYPE_QUA: {
      // principal vertices
      pp.push_back(SVector3(-1, -1, 0));
      pp.push_back(SVector3(1, -1, 0));
      pp.push_back(SVector3(1, 1, 0));
      pp.push_back(SVector3(-1, 1, 0));

      // internal points of edges
      for(int i = 0; i < 4; i++) {
        addEdgePointsCGNS(pp[i], pp[(i + 1) % 4], order, pp);
      }

      // internal points
      if(complete && order > 1) {
        addQuaPointsCGNS(pp[0], pp[1], pp[2], pp[3], order, pp);
      }
      break;
    }
    case TYPE_TET: {
      // principal vertices
      pp.push_back(SVector3(0, 0, 0));
      pp.push_back(SVector3(1, 0, 0));
      pp.push_back(SVector3(0, 1, 0));
      pp.push_back(SVector3(0, 0, 1));

      // internal points in edges of base triangle
      for(int i = 0; i < 3; i++)
        addEdgePointsCGNS(pp[i], pp[(i + 1) % 3], order, pp);

      // internal points in upstanding edges
      for(int i = 0; i < 3; i++) addEdgePointsCGNS(pp[i], pp[3], order, pp);

      if(complete && order > 2) {
        // internal points of base triangle
        addTriPointsCGNS(pp[0], pp[1], pp[2], order, equidistant, pp);

        // internal points of upstanding triangles
        for(int i = 0; i < 3; i++) {
          addTriPointsCGNS(pp[i], pp[(i + 1) % 3], pp[3], order, equidistant,
                           pp);
        }

        // internal points as a tet of order p-3
        if(order > 3) {
          std::vector<SVector3> tetPp =
            generatePointsCGNS(TYPE_TET, order - 4, true, true);

          double scale = (order - 4) / order;
          SVector3 offset(1. / order, 1. / order, 1. / order);
          for(size_t i = 0; i < tetPp.size(); i++) {
            SVector3 volumePoint = tetPp[i];
            volumePoint *= scale;
            volumePoint += offset;
            pp.push_back(volumePoint);
          }
        }
      }

      break;
    }
    case TYPE_HEX: {
      // principal vertices
      pp.push_back(SVector3(-1, -1, -1));
      pp.push_back(SVector3(1, -1, -1));
      pp.push_back(SVector3(1, 1, -1));
      pp.push_back(SVector3(-1, 1, -1));
      pp.push_back(SVector3(-1, -1, 1));
      pp.push_back(SVector3(1, -1, 1));
      pp.push_back(SVector3(1, 1, 1));
      pp.push_back(SVector3(-1, 1, 1));

      // internal points of base quadrangle edges
      for(int i = 0; i < 4; i++)
        addEdgePointsCGNS(pp[i], pp[(i + 1) % 4], order, pp);

      std::vector<SVector3> up[4];
      // internal points of mounting edges
      for(int i = 0; i < 4; i++) {
        addEdgePointsCGNS(pp[i], pp[i + 4], order, up[i]);
        pp.insert(pp.end(), up[i].begin(), up[i].end());
      }

      // internal points of top quadrangle edges
      for(int i = 0; i < 4; i++)
        addEdgePointsCGNS(pp[i + 4], pp[(i + 1) % 4 + 4], order, pp);

      if(complete && order > 1) {
        // internal points of base quadrangle
        addQuaPointsCGNS(pp[0], pp[1], pp[2], pp[3], order, pp);

        // internal points of upstanding faces
        for(int i = 0; i < 4; i++) {
          addQuaPointsCGNS(pp[i], pp[(i + 1) % 4], pp[(i + 1) % 4 + 4],
                           pp[i + 4], order, pp);
        }

        // internal points of top quadrangle
        addQuaPointsCGNS(pp[4], pp[5], pp[6], pp[7], order, pp);

        // internal volume points as a succession of internal planes
        for(int i = 0; i <= order - 2; i++) {
          addQuaPointsCGNS(up[0][i], up[1][i], up[2][i], up[3][i], order, pp);
        }
      }

      break;
    }
    case TYPE_PRI: {
      // principal vertices
      pp.push_back(SVector3(0, 0, -1));
      pp.push_back(SVector3(1, 0, -1));
      pp.push_back(SVector3(0, 1, -1));
      pp.push_back(SVector3(0, 0, 1));
      pp.push_back(SVector3(1, 0, 1));
      pp.push_back(SVector3(0, 1, 1));

      // internal points in edges of base triangle
      for(int i = 0; i < 3; i++)
        addEdgePointsCGNS(pp[i], pp[(i + 1) % 3], order, pp);

      // internal points in upstanding edges
      std::vector<SVector3> edge[3]; // keep for definition of volume pp
      for(int i = 0; i < 3; i++) {
        addEdgePointsCGNS(pp[i], pp[i + 3], order, edge[i]);
        pp.insert(pp.end(), edge[i].begin(), edge[i].end());
      }

      // internal points in edges of top triangle
      for(int i = 0; i < 3; i++)
        addEdgePointsCGNS(pp[i + 3], pp[(i + 1) % 3 + 3], order, pp);

      if(complete) {
        // internal vertices for base triangle
        addTriPointsCGNS(pp[0], pp[1], pp[2], order, true, pp);

        // internal vertices for upstanding quadrilaterals
        for(int i = 0; i < 3; i++) {
          addQuaPointsCGNS(pp[i], pp[(i + 1) % 3], pp[(i + 1) % 3 + 3],
                           pp[i + 3], order, pp);
        }

        // internal points for top triangle
        addTriPointsCGNS(pp[3], pp[4], pp[5], order, true, pp);

        // internal points in the volume as a succession of "triangles"
        for(int o = 0; o < order - 1; o++) {
          addTriPointsCGNS(edge[0][o], edge[1][o], edge[2][o], order, true, pp);
        }
      }
      break;
    }
    case TYPE_PYR: {
      // principal vertices
      pp.push_back(SVector3(-1, -1, 0));
      pp.push_back(SVector3(1, -1, 0));
      pp.push_back(SVector3(1, 1, 0));
      pp.push_back(SVector3(-1, 1, 0));
      pp.push_back(SVector3(0, 0, 1));

      // internal points in edges of base quadrilateral
      for(int i = 0; i < 4; i++)
        addEdgePointsCGNS(pp[i], pp[(i + 1) % 4], order, pp);

      // internal points in upstanding edges
      for(int i = 0; i < 4; i++) addEdgePointsCGNS(pp[i], pp[4], order, pp);

      // internal points in base quadrilateral
      addQuaPointsCGNS(pp[0], pp[1], pp[2], pp[3], order, pp);

      // internal points in upstanding triangles
      for(int i = 0; i < 4; i++)
        addTriPointsCGNS(pp[i], pp[(i + 1) % 4], pp[4], order, true, pp);

      // internal points as an internal pyramid of order p-3
      std::vector<SVector3> pyr =
        generatePointsCGNS(TYPE_PYR, order - 3, true, true);

      SVector3 offset(0, 0, 1. / order);
      double scale = double(order - 3) / double(order);

      for(size_t i = 0; i < pyr.size(); ++i)
        pp.push_back((pyr[i] * scale) + offset);

      break;
    }
    default:
      Msg::Error(
        "%s (%i) : Error CGNS element %i of order %i not yet implemented",
        __FILE__, __LINE__, ElementType::nameOfParentType(parentType).c_str(),
        order);
    }
  }

  return pp;
}

static int *getRenumberingToGmsh(ElementType_t cgnsType)
{
  int parent = parentFromCGNSType(cgnsType);
  int order = orderFromCGNSType(cgnsType);
  bool complete = completeCGNSType(cgnsType);
  int gmshType = tagFromCGNSType(cgnsType);

  std::vector<SVector3> points =
    generatePointsCGNS(parent, order, complete, true);
  fullMatrix<double> cgnsPoints(points.size(), 3);

  for(size_t i = 0; i < points.size(); i++) {
    for(size_t d = 0; d < 3; d++) cgnsPoints(i, d) = points[i][d];
  }

  // cgnsPoints.print("Point location in renumberings","%.1f");

  const nodalBasis *nb = BasisFactory::getNodalBasis(gmshType);

  int *renum = new int[points.size()];
  nb->forwardRenumbering(cgnsPoints, renum);

  // std::ostringstream filename;
  // filename << ElementType::nameOfParentType(parent) << "_p" << order <<
  // ".dat"; std::ofstream checkFile(filename.str().c_str());

  // checkFile << "CGNS Control points in a " <<
  // ElementType::nameOfParentType(parent)
  //           << " of order " << order << std::endl;
  // for (size_t i=0;i<points.size();i++) {
  //   checkFile << std::setw(2) << i+1
  //             << " -> "  << std::setw(2) << renum[i]
  //             << " - "
  //             << "(" << std::setw(4) << points[i][0]
  //             << "," << std::setw(4) << points[i][1]
  //             << "," << std::setw(4) << points[i][2] << ")" << std::endl;
  // }
  // checkFile.close();

  return renum;
}

static int cgnsErr(const int cgIndexFile = -1)
{
  Msg::Error("Error detected by CGNS library");
  Msg::Error(cg_get_error());
  if(cgIndexFile != -1)
    if(cg_close(cgIndexFile)) Msg::Error("Unable to close CGNS file");
  return 0;
}

static double readCGNSScale()
{
  double scale = 1;
  MassUnits_t mass;
  LengthUnits_t length;
  TimeUnits_t time;
  TemperatureUnits_t temperature;
  AngleUnits_t angle;

  cg_units_read(&mass, &length, &time, &temperature, &angle);

  switch(length) {
  case Centimeter:
    Msg::Info("Length unit in CGNS file is cm, rescaling");
    scale = 0.01;
    break;
  case Millimeter:
    Msg::Info("Length unit in CGNS file is mm, rescaling");
    scale = 0.001;
    break;
  case Foot:
    Msg::Info("Length unit in CGNS file is feet, rescaling");
    scale = 0.3048;
    break;
  case Inch:
    Msg::Info("Length unit in CGNS file is inch, rescaling");
    scale = 0.0254;
    break;
  case Meter:
    Msg::Info("Length unit in CGNS file is meter, not rescaling");
    break;
  case CG_Null:
  case CG_UserDefined:
  default:
    Msg::Info("Length unit in CGNS file not defined, therefore not rescaling");
    break;
  }

  return scale;
}

static MElement *
createElementMSH(GModel *m, int num, int typeMSH, int reg, int part,
                 std::vector<MVertex *> &v,
                 std::map<int, std::vector<MElement *> > elements[10])
{
  MElementFactory factory;
  MElement *e = factory.create(typeMSH, v, num, part, false, 0, 0, 0);

  if(!e) {
    Msg::Error("Unknown type of element %d", typeMSH);
    return NULL;
  }

  switch(e->getType()) {
  case TYPE_PNT: elements[0][reg].push_back(e); break;
  case TYPE_LIN: elements[1][reg].push_back(e); break;
  case TYPE_TRI: elements[2][reg].push_back(e); break;
  case TYPE_QUA: elements[3][reg].push_back(e); break;
  case TYPE_TET: elements[4][reg].push_back(e); break;
  case TYPE_HEX: elements[5][reg].push_back(e); break;
  case TYPE_PRI: elements[6][reg].push_back(e); break;
  case TYPE_PYR: elements[7][reg].push_back(e); break;
  case TYPE_POLYG: elements[8][reg].push_back(e); break;
  case TYPE_POLYH: elements[9][reg].push_back(e); break;
  default: Msg::Error("Wrong type of element"); return NULL;
  }

  return e;
}

static int to1D(int i, int j, int k, int max_i, int max_j, int max_k)
{
  return k * max_i * max_j + j * max_i + i;
}

static int getIndicesQuad(int i1, int i2, int i3, int i4, int j1, int j2,
                          int j3, int j4, int k1, int k2, int k3, int k4,
                          std::vector<int> &ind_i, std::vector<int> &ind_j,
                          std::vector<int> &ind_k, int order, int f)
{
  static const int offset[6][4][3] = {
    {{1, 1, 0}, {1, -1, 0}, {-1, -1, 0}, {-1, 1, 0}},
    {{1, 1, 0}, {-1, 1, 0}, {-1, -1, 0}, {1, -1, 0}},
    {{1, 0, 1}, {-1, 0, 1}, {-1, 0, -1}, {1, 0, -1}},
    {{1, 0, 1}, {1, 0, -1}, {-1, 0, -1}, {-1, 0, 1}},
    {{0, 1, 1}, {0, 1, -1}, {0, -1, -1}, {0, -1, 1}},
    {{0, 1, 1}, {0, -1, 1}, {0, -1, -1}, {0, 1, -1}}};

  int added = 0;

  if(order == 0) {
    ind_i.push_back(i1);
    ind_j.push_back(j1);
    ind_k.push_back(k1);
    return 1;
  }

  // corners
  ind_i.push_back(i1); ind_j.push_back(j1); ind_k.push_back(k1);
  ind_i.push_back(i2); ind_j.push_back(j2); ind_k.push_back(k2);
  ind_i.push_back(i3); ind_j.push_back(j3); ind_k.push_back(k3);
  ind_i.push_back(i4); ind_j.push_back(j4); ind_k.push_back(k4);

  added += 4;

  // edge points
  if(order > 1) {
    // edge 1
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i1 + v * (i2 - i1) / order);
      ind_j.push_back(j1 + v * (j2 - j1) / order);
      ind_k.push_back(k1 + v * (k2 - k1) / order);
      added++;
    }

    // edge 2
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i2 + v * (i3 - i2) / order);
      ind_j.push_back(j2 + v * (j3 - j2) / order);
      ind_k.push_back(k2 + v * (k3 - k2) / order);
      added++;
    }

    // edge 3
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i3 + v * (i4 - i3) / order);
      ind_j.push_back(j3 + v * (j4 - j3) / order);
      ind_k.push_back(k3 + v * (k4 - k3) / order);
      added++;
    }

    // edge 4
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i4 + v * (i1 - i4) / order);
      ind_j.push_back(j4 + v * (j1 - j4) / order);
      ind_k.push_back(k4 + v * (k1 - k4) / order);
      added++;
    }

    added += getIndicesQuad(
      i1 + offset[f][0][0], i2 + offset[f][1][0], i3 + offset[f][2][0],
      i4 + offset[f][3][0], j1 + offset[f][0][1], j2 + offset[f][1][1],
      j3 + offset[f][2][1], j4 + offset[f][3][1], k1 + offset[f][0][2],
      k2 + offset[f][1][2], k3 + offset[f][2][2], k4 + offset[f][3][2],
      ind_i, ind_j, ind_k, order - 2, f);
  }
  return added;
}

// get ijk indices for a high order face defined by principal vertices 1-4

static int getIndicesFace(int i1, int i2, int i3, int i4, int j1, int j2,
                          int j3, int j4, int k1, int k2, int k3, int k4,
                          std::vector<int> &ind_i, std::vector<int> &ind_j,
                          std::vector<int> &ind_k, int order, int f)
{
  static const int offset[6][4][3] = {
    {{1, 1, 0}, {1, -1, 0}, {-1, -1, 0}, {-1, 1, 0}},
    {{1, 0, 1}, {-1, 0, 1}, {-1, 0, -1}, {1, 0, -1}},
    {{0, 1, 1}, {0, 1, -1}, {0, -1, -1}, {0, -1, 1}},
    {{0, 1, 1}, {0, -1, 1}, {0, -1, -1}, {0, 1, -1}},
    {{-1, 0, 1}, {1, 0, 1}, {1, 0, -1}, {-1, 0, -1}},
    {{1, 1, 0}, {-1, 1, 0}, {-1, -1, 0}, {1, -1, 0}}};

  int added = 0;

  if(order == 0) {
    ind_i.push_back(i1);
    ind_j.push_back(j1);
    ind_k.push_back(k1);
    return 1;
  }

  // corners
  ind_i.push_back(i1);
  ind_j.push_back(j1);
  ind_k.push_back(k1);
  ind_i.push_back(i2);
  ind_j.push_back(j2);
  ind_k.push_back(k2);
  ind_i.push_back(i3);
  ind_j.push_back(j3);
  ind_k.push_back(k3);
  ind_i.push_back(i4);
  ind_j.push_back(j4);
  ind_k.push_back(k4);

  added += 4;

  // edge points
  if(order > 1) {
    // edge 1
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i1 + (i2 - i1) / order);
      ind_j.push_back(j1 + (j2 - j1) / order);
      ind_k.push_back(k1 + (k2 - k1) / order);
      added++;
    }

    // edge 2
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i2 + (i3 - i2) / order);
      ind_j.push_back(j2 + (j3 - j2) / order);
      ind_k.push_back(k2 + (k3 - k2) / order);
      added++;
    }

    // edge 3
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i3 + (i4 - i3) / order);
      ind_j.push_back(j3 + (j4 - j3) / order);
      ind_k.push_back(k3 + (k4 - k3) / order);
      added++;
    }

    // edge 4
    for(int v = 1; v < order; v++) {
      ind_i.push_back(i4 + (i1 - i4) / order);
      ind_j.push_back(j4 + (j1 - j4) / order);
      ind_k.push_back(k4 + (k1 - k4) / order);
      added++;
    }
  }
  added += getIndicesFace(
    i1 + offset[f][0][0], i2 - offset[f][1][0], i3 - offset[f][2][0],
    i4 + offset[f][3][0], j1 + offset[f][0][1], j2 - offset[f][1][1],
    j3 - offset[f][2][1], j4 + offset[f][3][1], k1 + offset[f][0][2],
    k2 - offset[f][1][2], k3 - offset[f][2][2], k4 + offset[f][3][2], ind_i,
    ind_j, ind_k, order - 2, f);
  return added;
}

// get ijk indices for a high order hexahedral element

static void getIndices(int i, int j, int k, std::vector<int> &ind_i,
                       std::vector<int> &ind_j, std::vector<int> &ind_k,
                       int order, int startpoint = 0)
{
  static const int edges[12][2] = {{0, 1}, {0, 3}, {0, 4}, {1, 2},
                                   {1, 5}, {2, 3}, {2, 6}, {3, 7},
                                   {4, 5}, {4, 7}, {5, 6}, {6, 7}};
  static const int faces[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
                                  {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};

  static const int offset[6][4][3] = {
    {{1, 1, 0}, {1, -1, 0}, {-1, -1, 0}, {-1, 1, 0}},
    {{1, 0, 1}, {-1, 0, 1}, {-1, 0, -1}, {1, 0, -1}},
    {{0, 1, 1}, {0, 1, -1}, {0, -1, -1}, {0, -1, 1}},
    {{0, 1, 1}, {0, -1, 1}, {0, -1, -1}, {0, 1, -1}},
    {{-1, 0, 1}, {1, 0, 1}, {1, 0, -1}, {-1, 0, -1}},
    {{1, 1, 0}, {-1, 1, 0}, {-1, -1, 0}, {1, -1, 0}}};

  if(order == 0) {
    ind_i.push_back(i);
    ind_j.push_back(j);
    ind_k.push_back(k);
    return;
  }

  // 8 principal points
  ind_i.push_back(i); ind_j.push_back(j); ind_k.push_back(k);
  ind_i.push_back(i + order); ind_j.push_back(j); ind_k.push_back(k);
  ind_i.push_back(i + order); ind_j.push_back(j + order); ind_k.push_back(k);
  ind_i.push_back(i); ind_j.push_back(j + order); ind_k.push_back(k);
  ind_i.push_back(i); ind_j.push_back(j); ind_k.push_back(k + order);
  ind_i.push_back(i + order); ind_j.push_back(j); ind_k.push_back(k + order);
  ind_i.push_back(i + order); ind_j.push_back(j + order); ind_k.push_back(k + order);
  ind_i.push_back(i); ind_j.push_back(j + order); ind_k.push_back(k + order);

  int initial_point = startpoint + 8;

  if(order > 1) {
    // edges
    for(int e = 0; e < 12; e++) {
      int p0_i = ind_i[startpoint + edges[e][0]];
      int p0_j = ind_j[startpoint + edges[e][0]];
      int p0_k = ind_k[startpoint + edges[e][0]];
      int p1_i = ind_i[startpoint + edges[e][1]];
      int p1_j = ind_j[startpoint + edges[e][1]];
      int p1_k = ind_k[startpoint + edges[e][1]];

      for(int v = 1; v < order; v++) {
        ind_i.push_back(p0_i + v * ((p1_i - p0_i) / order));
        ind_j.push_back(p0_j + v * ((p1_j - p0_j) / order));
        ind_k.push_back(p0_k + v * ((p1_k - p0_k) / order));
        initial_point++;
      }
    }

    // faces
    for(int f = 0; f < 6; f++) {
      int i1 = ind_i[startpoint + faces[f][0]] + offset[f][0][0];
      int i2 = ind_i[startpoint + faces[f][1]] + offset[f][1][0];
      int i3 = ind_i[startpoint + faces[f][2]] + offset[f][2][0];
      int i4 = ind_i[startpoint + faces[f][3]] + offset[f][3][0];

      int j1 = ind_j[startpoint + faces[f][0]] + offset[f][0][1];
      int j2 = ind_j[startpoint + faces[f][1]] + offset[f][1][1];
      int j3 = ind_j[startpoint + faces[f][2]] + offset[f][2][1];
      int j4 = ind_j[startpoint + faces[f][3]] + offset[f][3][1];

      int k1 = ind_k[startpoint + faces[f][0]] + offset[f][0][2];
      int k2 = ind_k[startpoint + faces[f][1]] + offset[f][1][2];
      int k3 = ind_k[startpoint + faces[f][2]] + offset[f][2][2];
      int k4 = ind_k[startpoint + faces[f][3]] + offset[f][3][2];
      initial_point +=
        getIndicesFace(i1, i2, i3, i4, j1, j2, j3, j4, k1, k2, k3, k4, ind_i,
                       ind_j, ind_k, order - 2, f);
    }

    // interior
    getIndices(i + 1, j + 1, k + 1, ind_i, ind_j, ind_k, order - 2,
               initial_point);
  }
}

// compute the face index in the block from the index range

static int computeCGNSFace(const cgsize_t *range)
{
  int face = -1;

  if(range[0] == range[3]) {
    if(range[0] == 1)
      face = 4;
    else
      face = 5;
  }
  else if(range[1] == range[4]) {
    if(range[1] == 1)
      face = 2;
    else
      face = 3;
  }
  else if(range[2] == range[5]) {
    if(range[2] == 1)
      face = 0;
    else
      face = 1;
  }
  return face;
}

// structure for storing periodic connections

struct CGNSStruPeriodic {
  // the data that are modified on the fly by looping on the CGNSStruPeriodic
  // set
  //
  // - should not affect the ordering in CGNSStruPeriodicLess
  // - should be modified with a const operation (STL only returns const data)
  // - should hence be mutable
  //
  // Currently this data includes the vectors of source and target vertices
  //
  // All ordering data should only be modified in constructor-like operations

  friend class CGNSStruPeriodicLess;

public:
  struct IJK {
    IJK()
    {
      for(int k = 0; k < 3; k++) ijk[k] = -1;
    }
    IJK(int i, int j, int k)
    {
      ijk[0] = i;
      ijk[1] = j;
      ijk[2] = k;
    }
    IJK(const IJK &other) { std::memcpy(ijk, other.ijk, 3 * sizeof(int)); }

    int &operator[](int k) { return ijk[k]; }
    int operator[](int k) const { return ijk[k]; }

    int ijk[3];

    std::string print() const
    {
      std::ostringstream printout;
      printout << "(" << ijk[0] << "," << ijk[1] << "," << ijk[2] << ")";
      return printout.str();
    }
  };

  std::string tgtZone; // cgns name of the block
  int tgtFace; // index of the face in the block
  mutable int tgtFaceId; // elementary tag corresponding to the face
  mutable std::vector<MVertex *> tgtVertices; // ordered vertices in the tgt
  std::vector<IJK> tgtIJK; // ijk indices of the face points in the block

  std::string srcName; // cgns name of the block
  int srcFace; // index of the face in the block
  mutable int srcFaceId; // elementary tag corresponding to the face
  mutable std::vector<MVertex *> srcVertices; // ordered vertices in the src
  std::vector<IJK> srcIJK; // ijk indices in the source face, ordered following tgt

  std::vector<double> tfo; // transformation

public:
  void print(std::ostream &out) const
  {
    out << "Connection of face " << tgtFace << " (" << tgtFaceId << ")"
        << " of domain " << tgtZone << " to " << srcFace << " (" << srcFaceId
        << ")"
        << " of " << srcName << std::endl;
  }

public:
  CGNSStruPeriodic() { setUnitAffineTransformation(tfo); }
  CGNSStruPeriodic(const char *tn, const cgsize_t *tr, const char *sn,
                   const cgsize_t *sr, const int *iTfo, int o, int tfid,
                   const float *rotationCenter, const float *rotationAngle,
                   const float *translation)
    : tgtZone(tn), tgtFace(computeCGNSFace(tr)), tgtFaceId(tfid), srcName(sn),
      srcFace(computeCGNSFace(sr)), srcFaceId(-1)
  {
    // compute the structured grid indices

    int dIJKTgt[3] = {(tr[3] > tr[0] ? o : -o), (tr[4] > tr[1] ? o : -o),
                      (tr[5] > tr[2] ? o : -o)};

    int dIJKSrc[3] = {(sr[3] > sr[0] ? o : -o), (sr[4] > sr[1] ? o : -o),
                      (sr[5] > sr[2] ? o : -o)};

    int idx[3] = {abs(iTfo[0]) - 1, abs(iTfo[1]) - 1, abs(iTfo[2]) - 1};

    int nbPoints = 1;
    IJK nbIJK;
    for(int k = 0; k < 3; k++)
      nbIJK[k] = (tr[k] == tr[k + 3]) ? 1 : ((abs(tr[k] - tr[k + 3])) / o + 1);
    for(int k = 0; k < 3; k++) nbPoints *= nbIJK[k];

    tgtIJK.reserve(nbPoints);
    srcIJK.reserve(nbPoints);

    tgtVertices.resize(nbPoints, NULL);
    srcVertices.resize(nbPoints, NULL);

    IJK src(sr[idx[0]], sr[idx[1]], sr[idx[2]]);
    IJK tgt(tr[0], tr[1], tr[2]);

    for(int i = 0; i < nbIJK[0]; i++) {
      tgt[1] = tr[1];
      src[1] = sr[idx[1]];

      for(int j = 0; j < nbIJK[1]; j++) {
        tgt[2] = tr[2];
        src[2] = sr[idx[2]];

        for(int k = 0; k < nbIJK[2]; k++) {
          tgtIJK.push_back(tgt);
          srcIJK.push_back(src);

          tgt[2] += dIJKTgt[2];
          src[idx[2]] += dIJKSrc[idx[2]];
        }
        tgt[1] += dIJKTgt[1];
        src[idx[1]] += dIJKSrc[idx[1]];
      }
      tgt[0] += dIJKTgt[0];
      src[idx[0]] += dIJKSrc[idx[0]];
    }

    // now compute the transformation
    computeAffineTransformation(rotationCenter, rotationAngle, translation,
                                tfo);
  }

  CGNSStruPeriodic(const CGNSStruPeriodic &old)
  {
    tgtVertices.resize(old.getNbPoints(), NULL);
    srcVertices.resize(old.getNbPoints(), NULL);

    tgtZone = old.tgtZone;
    tgtFace = old.tgtFace;
    tgtFaceId = old.tgtFaceId;
    tgtIJK = old.tgtIJK;
    tgtVertices = old.tgtVertices;

    srcName = old.srcName;
    srcFace = old.srcFace;
    srcFaceId = old.srcFaceId;
    srcIJK = old.srcIJK;
    srcVertices = old.srcVertices;

    tfo = old.tfo;
  }

  CGNSStruPeriodic getInverse() const
  {
    CGNSStruPeriodic inv;

    inv.tgtVertices.resize(getNbPoints(), NULL);
    inv.srcVertices.resize(getNbPoints(), NULL);

    inv.tgtZone = srcName;
    inv.tgtFace = srcFace;
    inv.tgtFaceId = srcFaceId;
    inv.tgtIJK = srcIJK;
    inv.tgtVertices = srcVertices;

    inv.srcName = tgtZone;
    inv.srcFace = tgtFace;
    inv.srcFaceId = tgtFaceId;
    inv.srcIJK = tgtIJK;
    inv.srcVertices = tgtVertices;

    inv.tfo = tfo;
    invertAffineTransformation(tfo, inv.tfo);

    return inv;
  }

  size_t getNbPoints() const { return tgtIJK.size(); }

  bool getTgtIJK(size_t ip, int &i, int &j, int &k) const
  {
    if(ip > tgtIJK.size()) return false;
    i = tgtIJK[ip][0] - 1;
    j = tgtIJK[ip][1] - 1;
    k = tgtIJK[ip][2] - 1;
    return true;
  }

  bool getSrcIJK(size_t ip, int &i, int &j, int &k) const
  {
    if(ip > srcIJK.size()) return false;
    i = srcIJK[ip][0] - 1;
    j = srcIJK[ip][1] - 1;
    k = srcIJK[ip][2] - 1;
    return true;
  }

  bool insertTgtVertex(size_t ip, MVertex *v) const
  {
    if(ip > tgtVertices.size()) return false;
    tgtVertices[ip] = v;
    return true;
  }

  bool insertSrcVertex(size_t ip, MVertex *v) const
  {
    if(ip > srcVertices.size()) return false;
    srcVertices[ip] = v;
    return true;
  }
};

class CGNSStruPeriodicLess {
public:
  bool operator()(const CGNSStruPeriodic &f, const CGNSStruPeriodic &d) const
  {
    int s = f.srcName.compare(d.srcName);
    if(s != 0) return (s < 0);
    return (f.srcFace < d.srcFace);
  }
};

class CGNSUnstPeriodic {
  // the data that are modified on the fly by looping on the CGNSUnstPeriodic
  // set
  //
  // - should not affect the ordering in CGNSUnstPeriodicLess
  // - should be modified with a const operation (STL only returns const data)
  // - should hence be mutable
  //
  // Currently this data includes the vectors of source and tgt vertices
  //
  // All ordering data should only be modified in constructor-like operations

  friend class CGNSUnstPeriodicLess;

public:
  std::string name; // cgns name of the connection

  std::string tgtZone; // cgns name of the unstructured zone
  std::string srcZone; // cgns name of the unstructured zone

  std::map<int, int> srcToTgtPts;
  std::map<int, int> tgtToSrcPts;

  std::vector<double> tfo; // transformation

  std::map<std::set<int>, GEntity *> tgtEnts[3];
  std::map<std::set<int>, GEntity *> srcEnts[3];

  std::map<GEntity *, GEntity *> tgtToSrcEnts[3];

protected:
  void addPoints(PointSetType_t setType, cgsize_t size, const cgsize_t *ptsList,
                 std::vector<int> &pts)
  {
    switch(setType) {
    case PointRange:
    case PointRangeDonor:
      for(int i = ptsList[0]; i <= ptsList[1]; i++) pts.push_back(i - 1);
      break;
    case PointList:
    case PointListDonor:
      for(int i = 0; i < size; i++) pts.push_back(ptsList[i] - 1);
      break;
    default: break;
    }
  }

public:
  CGNSUnstPeriodic() { setUnitAffineTransformation(tfo); }
  CGNSUnstPeriodic(const char *n, const char *tn, const cgsize_t *tPts,
                   PointSetType_t tType, cgsize_t tSize, const char *sn,
                   const cgsize_t *sPts, PointSetType_t sType, cgsize_t sSize,
                   const float *rotationCenter, const float *rotationAngle,
                   const float *translation)
    : name(n), tgtZone(tn), srcZone(sn)
  {
    // compute the structured grid indices
    computeAffineTransformation(rotationCenter, rotationAngle, translation,
                                tfo);
    std::vector<int> srcPts;
    addPoints(sType, sSize, sPts, srcPts);

    std::vector<int> tgtPts;
    addPoints(tType, tSize, tPts, tgtPts);

    if(tgtPts.size() == srcPts.size()) {
      for(unsigned i = 0; i < tgtPts.size(); i++) {
        tgtToSrcPts[tgtPts[i]] = srcPts[i];
        srcToTgtPts[srcPts[i]] = tgtPts[i];
      }
    }
  }
  size_t nbPoints() const { return tgtToSrcPts.size(); }
};

class CGNSUnstPeriodicLess {
public:
  bool operator()(const CGNSUnstPeriodic &f, const CGNSUnstPeriodic &d) const
  {
    if(f.nbPoints() == d.nbPoints()) {
      if(f.tgtZone == d.tgtZone) {
        if(f.srcZone == d.srcZone) return f.tgtToSrcPts < d.tgtToSrcPts;
        return (f.srcZone.compare(d.srcZone) < 0);
      }
      if(f.tgtZone == d.srcZone) {
        if(f.srcZone == d.tgtZone) return f.tgtToSrcPts < d.srcToTgtPts;
        return (f.srcZone.compare(d.tgtZone) < 0);
      }
      return (f.srcZone.compare(d.srcZone) < 0);
    }
    return (f.nbPoints() < d.nbPoints());
  }
};

static int openCGNSFile(const std::string &fileName, int &fileIndex,
                        int &nbBasis, double &scale)
{
  if(cg_open(fileName.c_str(), CG_MODE_READ, &fileIndex)) {
    Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__, __LINE__,
               fileName.c_str(), cg_get_error());
    return 0;
  }
  scale = readCGNSScale();
  cg_nbases(fileIndex, &nbBasis);
  return 1;
}

static bool readCGNSBoundaryConditions(int fileIndex, int baseIndex,
                                       int zoneIndex, int classIndex,
                                       int meshDim,
                                       std::map<int, int> &eltToClass,
                                       std::map<int, std::string> &classToName)
{
  int nbBoCos;

  if(cg_nbocos(fileIndex, baseIndex, zoneIndex, &nbBoCos) != CG_OK)
    return false;

  for(int boCoIndex = 1; boCoIndex <= nbBoCos; boCoIndex++, classIndex++) {
    PointSetType_t ptSetType;
    int normalIndex;
    cgsize_t normalSize;
    DataType_t normalType;
    int nbDataSet;

    char bcName[maxLenCGNS];
    BCType_t bcType;
    cgsize_t nbElts;
    int ierr;

    ierr = cg_boco_info(fileIndex, baseIndex, zoneIndex, boCoIndex, bcName,
                        &bcType, &ptSetType, &nbElts, &normalIndex, &normalSize,
                        &normalType, &nbDataSet);
    if(ierr != CG_OK) {
      Msg::Error("%s (%i) : %s", __FILE__, __LINE__, cg_get_error());
      return false;
    }

    GridLocation_t location;
    ierr = cg_boco_gridlocation_read(fileIndex, baseIndex, zoneIndex, boCoIndex,
                                     &location);
    if(ierr != CG_OK) {
      Msg::Error("%s (%i) : %s", __FILE__, __LINE__, cg_get_error());
      return false;
    }

    Msg::Info("Boundary conditions %s specified on %s and set type %s", bcName,
              cg_GridLocationName(location), cg_PointSetTypeName(ptSetType));

    if(meshDim == 2 && location != CGNS::EdgeCenter &&
       location != CGNS::Vertex) {
      Msg::Error("Boundary condition %s should be specified on edges "
                 "for 2D zone and not on %s",
                 bcName, cg_GridLocationName(location));
      return false;
    }

    if(meshDim == 3 && location != CGNS::FaceCenter &&
       location != CGNS::Vertex) {
      Msg::Error("Boundary condition %s should be specified on faces "
                 "for 3D zones and not on %s",
                 bcName, cg_GridLocationName(location));
      return false;
    }

    cgsize_t *elt = new cgsize_t[nbElts];

    ierr = cg_boco_read(fileIndex, baseIndex, zoneIndex, boCoIndex, elt, NULL);
    if(ierr != CG_OK) {
      Msg::Error("%s (%i) : %s", __FILE__, __LINE__, cg_get_error());
      return false;
    }

    ierr = cg_goto(fileIndex, baseIndex, "Zone_t", zoneIndex, "ZoneBC_t", 1,
                   "BC_t", boCoIndex, "end");

    if(ierr != CG_OK) {
      Msg::Error("%s (%i) : %s", __FILE__, __LINE__, cg_get_error());
      return false;
    }

    char family[maxLenCGNS];
    ierr = cg_famname_read(family);

    if(ierr == CG_ERROR) {
      Msg::Error("%s (%i) : %s", __FILE__, __LINE__, cg_get_error());
      return false;
    }
    if(ierr == CG_OK) {
      Msg::Info("Boundary condition is linked to family %s", family);
    }

    classToName[classIndex] = bcName;

    switch(ptSetType) {
    case ElementRange:
    case PointRange:
    case PointRangeDonor:
      Msg::Info("Boundary condition %s is defined on %i %s", bcName,
                elt[1] - elt[0] + 1, cg_GridLocationName(location));
      for(cgsize_t i = elt[0]; i <= elt[1]; i++) eltToClass[i] = classIndex;
      break;
    case ElementList:
    case PointList:
    case PointListDonor:
      Msg::Info("Boundary condition %s is defined on %i %s", bcName, nbElts,
                cg_GridLocationName(location));
      for(cgsize_t i = 0; i < nbElts; i++) eltToClass[elt[i]] = classIndex;
      break;
    default:
      Msg::Error("Point set type %s is currently not supported "
                 "for boundary conditions",
                 cg_PointSetTypeName(ptSetType));
      break;
    }
  }
  return true;
}

static bool readCGNSPeriodicConnections(
  int fileIndex, int baseIndex, int zoneIndex, char *zoneName,
  ZoneType_t zoneType,
  std::set<CGNSUnstPeriodic, CGNSUnstPeriodicLess> &connections)
{
  int nbConn(0);
  cg_nconns(fileIndex, baseIndex, zoneIndex, &nbConn);

  for(int connIndex = 0; connIndex < nbConn; connIndex++) {
    GridLocation_t tgtLocation;

    GridConnectivityType_t connType;
    PointSetType_t tgtSetType;
    PointSetType_t srcSetType;
    ZoneType_t srcZoneType;
    DataType_t srcDataType;

    cgsize_t tgtSize;
    cgsize_t srcSize;

    char connName[maxLenCGNS];
    char tgtName[maxLenCGNS];
    std::memcpy(tgtName, zoneName, maxLenCGNS * sizeof(char));
    char srcName[maxLenCGNS];

    cg_conn_info(fileIndex, baseIndex, zoneIndex, connIndex, connName,
                 &tgtLocation, &connType, &tgtSetType, &tgtSize, srcName,
                 &srcZoneType, &srcSetType, &srcDataType, &srcSize);

    if(connType != Abutting1to1) {
      Msg::Error("Non-conformal connection not supported");
      return false;
    }

    cgsize_t *tgtPts = new cgsize_t[tgtSize];
    cgsize_t *srcPts = new cgsize_t[srcSize];

    cg_conn_read(fileIndex, baseIndex, zoneIndex, connIndex, tgtPts,
                 srcDataType, srcPts);

    if(srcZoneType == Structured) break;

    float center[3] = {0, 0, 0};
    float angle[3] = {0, 0, 0};
    float disp[3] = {0, 0, 0};

    cg_conn_periodic_read(fileIndex, baseIndex, zoneIndex, connIndex, center,
                          angle, disp);

    connections.insert(CGNSUnstPeriodic(connName, srcName, srcPts, srcSetType,
                                        srcSize, tgtName, tgtPts, tgtSetType,
                                        tgtSize, center, angle, disp));

    delete[] tgtPts;
    delete[] srcPts;
  }
  return true;
}

static int addCGNSPoints(const std::string &fileName, int fileIndex, int baseIndex,
                         int zoneIndex, cgsize_t nbPoints, int dim, double scale,
                         GEntity *entity, int &index, std::vector<MVertex *> &vertices)
{
  int nbDim;
  if(cg_ncoords(fileIndex, baseIndex, zoneIndex, &nbDim) != CG_OK) {
    Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__, __LINE__,
               fileName.c_str(), cg_get_error());
    return 0;
  }

  if(nbDim != dim) {
    Msg::Error(
      "%s (%i) : Error reading CGNS file %s: incoherent coordinate count",
      __FILE__, __LINE__, fileName.c_str());
    return 0;
  }

  double *xyz = new double[nbPoints * 3];
  for(int i = 0; i < 3 * nbPoints; i++) xyz[i] = 0;

  for(int iCoord = 0; iCoord < dim; iCoord++) {
    char coordName[maxLenCGNS];
    cgsize_t indBeg(1);

    DataType_t dataType;
    if(cg_coord_info(fileIndex, baseIndex, zoneIndex, iCoord + 1, &dataType,
                     coordName) != CG_OK) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      delete[] xyz;
      return 0;
    }

    if(cg_coord_read(fileIndex, baseIndex, zoneIndex, coordName, RealDouble,
                     &indBeg, &nbPoints, xyz + iCoord * nbPoints) != CG_OK) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      delete[] xyz;
      return 0;
    }
  }

  const double *x = xyz;
  const double *y = xyz + nbPoints;
  const double *z = xyz + nbPoints * 2;

  for(int i = 0; i < nbPoints; i++) {
    vertices.push_back(
      new MVertex(x[i] * scale, y[i] * scale, z[i] * scale, entity, index));
    index++;
  }
  delete[] xyz;
  return 1;
}

int GModel::_readCGNSUnstructured(const std::string &fileName)
{
  // global containers and indices for points and elements

  std::map<int, std::vector<MElement *> > eltMap[10];
  std::vector<MVertex *> newVertices;

  // keep connectivity information

  std::set<CGNSUnstPeriodic, CGNSUnstPeriodicLess> periodic;

  // open file and read generic information

  int fileIndex(-1);
  int nbBases(0);
  double scale;

  if(!openCGNSFile(fileName, fileIndex, nbBases, scale)) return 0;

  int baseIndex = 1;
  int topoDim(0);
  int meshDim(0);
  char baseName[maxLenCGNS];

  if(cg_base_read(fileIndex, baseIndex, baseName, &topoDim, &meshDim) !=
     CG_OK) {
    Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__, __LINE__,
               fileName.c_str(), cg_get_error());
    return 0;
  }

  // read boundary conditions to retain name for physical classification

  int nbFamilies(0);
  if(cg_nfamilies(fileIndex, baseIndex, &nbFamilies) != CG_OK) {
    Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__, __LINE__,
               fileName.c_str(), cg_get_error());
    return 0;
  }

  std::map<std::string, int> family;

  for(int familyIndex = 1; familyIndex <= nbFamilies; familyIndex++) {
    char familyName[maxLenCGNS];
    int nbBC;
    int nbGeo;
    int ierr = cg_family_read(fileIndex, baseIndex, familyIndex, familyName,
                              &nbBC, &nbGeo);
    if(ierr != CG_OK) {
      Msg::Error("%s (%i) : Error reading family %i in CGNS file %s : %s",
                 __FILE__, __LINE__, familyIndex, fileName.c_str(),
                 cg_get_error());
      return 0;
    }
    Msg::Info("Read family %s with index %i", familyName, familyIndex);

    family[familyName] = familyIndex;
  }

  // read the zones containing the elements

  // keep renumbering table once generated
  std::map<ElementType_t, int *> renumbering;

  // read mesh zones

  int nbZones(0);
  if(cg_nzones(fileIndex, baseIndex, &nbZones) != CG_OK) {
    Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__, __LINE__,
               fileName.c_str(), cg_get_error());
    return 0;
  }

  // node and element numbering is implicit in the zone, therefore offset
  // required

  // provide a global numbering

  int vtxIndex(1);

  // classify zones following their index, and start new numbering beyond

  std::map<int, std::string> classNames;

  // retain global zone information

  std::map<std::string, int> zoneIndices;
  std::map<std::string, int> zoneOffsets;

  // retain boundary conditions

  std::map<int, std::string> bcToName;
  std::map<int, std::string> zoneToName;

  int classIndex = nbZones + 1;

  for(int zoneIndex = 1; zoneIndex <= nbZones; zoneIndex++) {
    // using an offset to translate zone local numbering to global numbering

    int vtxOffset = newVertices.size();

    // check that this is an unstructured zone we can later add ijk here to
    // allow for mixed meshes

    ZoneType_t zoneType;
    if(cg_zone_type(fileIndex, baseIndex, zoneIndex, &zoneType) != CG_OK) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      return 0;
    }

    if(zoneType != Unstructured) return 0;

    // get element counts

    cgsize_t sizes[3];

    char zoneName[maxLenCGNS];
    if(cg_zone_read(fileIndex, baseIndex, zoneIndex, zoneName, sizes) !=
       CG_OK) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      return 0;
    }

    zoneToName[zoneIndex] = zoneName;
    zoneIndices[zoneName] = zoneIndex;
    zoneOffsets[zoneName] = vtxOffset;

    Msg::Info("Reading unstructured zone %s", zoneName);

    cgsize_t nbPoints = sizes[0];

    // read the family attached to the zone

    if(cg_goto(fileIndex, baseIndex, "Zone_t", zoneIndex, "end") != CG_OK) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      return 0;
    }

    char zoneFamilyName[maxLenCGNS];
    // int zoneFamilyIndex;

    int ierr = cg_famname_read(zoneFamilyName);

    if(ierr == CG_ERROR) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      return 0;
    }

    if(ierr == CG_OK) {
      Msg::Info("Zone %i has family name %s", zoneIndex, zoneFamilyName);
      std::map<std::string, int>::iterator fIter = family.find(zoneFamilyName);
      // if(fIter != family.end()) zoneFamilyIndex = fIter->second;
      if(fIter == family.end())
        Msg::Error("%s (%i) : Error reading CGNS file %s : "
                   "cannot find CGNS family in available list",
                   __FILE__, __LINE__, fileName.c_str());
    }

    // read coordinates and create vertices

    addCGNSPoints(fileName, fileIndex, baseIndex, zoneIndex, nbPoints, meshDim,
                  scale, NULL, vtxIndex, newVertices);

    Msg::Info("Read %i points", nbPoints);

    // provide a finer classification based on boundary conditions

    std::map<int, int> eltToBC;

    bool topologyDefined = readCGNSBoundaryConditions(
      fileIndex, baseIndex, zoneIndex, classIndex, meshDim, eltToBC, bcToName);

    // create element using the sections

    int nbSections;

    if(cg_nsections(fileIndex, baseIndex, zoneIndex, &nbSections) != CG_OK) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      return 0;
    }

    size_t eltIndex = 1;
    for(int sectIndex = 1; sectIndex <= nbSections; sectIndex++) {
      char sectName[maxLenCGNS];
      ElementType_t cgnsType;
      cgsize_t eltBeg;
      cgsize_t eltEnd;
      int nbBound;
      int parentFlag;

      std::map<ElementType_t, int> elementCount;

      // read connection block size

      if(cg_section_read(fileIndex, baseIndex, zoneIndex, sectIndex, sectName,
                         &cgnsType, &eltBeg, &eltEnd, &nbBound,
                         &parentFlag) != CG_OK) {
        Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                   __LINE__, fileName.c_str(), cg_get_error());
        return 0;
      }

      int nbElt = eltEnd - eltBeg + 1;

      // read connections

      cgsize_t sectSize;
      if(cg_ElementDataSize(fileIndex, baseIndex, zoneIndex, sectIndex,
                            &sectSize) != CG_OK) {
        Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                   __LINE__, fileName.c_str(), cg_get_error());
        return 0;
      }

      // read elements

      cgsize_t *elts = new cgsize_t[sectSize];

      if(cg_elements_read(fileIndex, baseIndex, zoneIndex, sectIndex, elts,
                          NULL) != CG_OK) {
        Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                   __LINE__, fileName.c_str(), cg_get_error());
        return 0;
      }

      // create elements

      cgsize_t *pElt = elts;
      for(int iElt = 0; iElt < nbElt; iElt++, eltIndex++) {
        std::vector<MVertex *> vtcs;

        ElementType_t myType = cgnsType;
        if(cgnsType == MIXED) myType = (ElementType_t)*pElt++;

        if(elementCount.find(myType) == elementCount.end())
          elementCount[myType] = 0;
        elementCount[myType]++;

        int eltType = tagFromCGNSType(myType);
        int eltSize = ElementType::getNumVertices(eltType);

        int *renum = NULL;

        std::map<ElementType_t, int *>::iterator rIter =
          renumbering.find(myType);
        if(rIter == renumbering.end()) {
          renum = getRenumberingToGmsh(myType);
          renumbering[myType] = renum;
        }
        else
          renum = rIter->second;

        for(int iVtx = 0; iVtx < eltSize; iVtx++) {
          int num = vtxOffset + pElt[renum[iVtx]] - 1;
          vtcs.push_back(newVertices[num]);
        }

        int topoIndex = zoneIndex;
        std::map<int, int>::iterator tIter = eltToBC.find(eltIndex);
        if(tIter != eltToBC.end() && topologyDefined) topoIndex = tIter->second;

        pElt += eltSize;
        int partition(0);
        createElementMSH(this, eltIndex, eltType, topoIndex, partition, vtcs,
                         eltMap);
      }

      std::ostringstream elementList;
      std::map<ElementType_t, int>::iterator ecIter = elementCount.begin();
      for(; ecIter != elementCount.end(); ++ecIter) {
        elementList << ecIter->second << " "
                    << ElementType::nameOfParentType(
                         parentFromCGNSType(ecIter->first))
                    << "s ";
      }

      Msg::Info("Section %i of zone %i has %s", sectIndex, zoneIndex,
                elementList.str().c_str());

      delete[] elts;
    }

    // readCGNSPeriodicConnections(fileIndex, baseIndex, zoneIndex, zoneName,
    //                             zoneType, periodic);
  }

  for(std::map<ElementType_t, int *>::iterator rIter = renumbering.begin();
      rIter != renumbering.end(); ++rIter)
    delete[] rIter->second;

  removeDuplicateMeshVertices(1e-8);

  for(int i = 0; i < 10; i++) _storeElementsInEntities(eltMap[i]);

  if(CTX::instance()->mesh.cgnsConstructTopology) createTopologyFromMeshNew();

  for(int zoneIndex = 1; zoneIndex <= nbZones; zoneIndex++) {
    cgsize_t sizes[3];
    char zoneName[maxLenCGNS];
    if(cg_zone_read(fileIndex, baseIndex, zoneIndex, zoneName, sizes) !=
       CG_OK) {
      Msg::Error("%s (%i) : Error reading CGNS file %s : %s", __FILE__,
                 __LINE__, fileName.c_str(), cg_get_error());
      return 0;
    }
    readCGNSPeriodicConnections(fileIndex, baseIndex, zoneIndex, zoneName,
                                Unstructured, periodic);
  }

  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(newVertices);

  // add physical entities corresponding to the bc and zones

  std::map<int, std::map<int, std::string> > physicalSurfaces;

  std::map<int, std::string>::iterator bIter = bcToName.begin();
  for(; bIter != bcToName.end(); bIter++) {
    int tag = bIter->first;
    std::string name = bIter->second;
    physicalSurfaces[tag][tag] = name;
    _physicalNames[std::make_pair(meshDim - 1, tag)] = name;
  }

  _storePhysicalTagsInEntities(meshDim - 1, physicalSurfaces);

  std::map<int, std::map<int, std::string> > physicalZones;

  std::map<int, std::string>::iterator zIter = zoneToName.begin();
  for(; zIter != zoneToName.end(); zIter++) {
    int tag = zIter->first;
    std::string name = zIter->second;
    physicalZones[tag][tag] = name;
    _physicalNames[std::make_pair(meshDim, tag)] = name;
  }

  _storePhysicalTagsInEntities(meshDim, physicalZones);

  return 1;
}

int GModel::_readCGNSStructured(const std::string &name)
{
  // cgsize_t isize[9];
  // char basename[33],zonename[33];
  std::map<int, std::vector<MElement *> > elements[10];

  int index_file(-1);
  int nBases(0);
  double scale;

  if(!openCGNSFile(name, index_file, nBases, scale)) return 0;

  Msg::Debug("Found %i base(s).", nBases);
  if(nBases > 1) {
    Msg::Warning("Found %i bases in the file, "
                 "but only the first one will be used to build mesh.",
                 nBases);
  }
  int index_base = 1;

  // Get the number of zones
  int nZones;
  cg_nzones(index_file, index_base, &nZones);
  Msg::Debug("Found %i zone(s).", nZones);

  // Compute the maximum multigrid level
  int max_order = 8;

  // Creating MVertex
  std::map<int, MVertex *> vertexMap;
  int minVertex = 1;
  int maxVertex = 0;
  int vnum = 1;

  int *sizeIJK = new int[nZones * 3];

  for(int index_zone = 1; index_zone <= nZones; index_zone++) {
    Msg::Debug("Reading zone to compute MG level %i.", index_zone);

    ZoneType_t zoneType;
    cg_zone_type(index_file, index_base, index_zone, &zoneType);
    if(zoneType == Unstructured) {
      Msg::Info("Unstructured zone detected");
      return 0;
    }
    // cgsize_t irmin[3];
    cgsize_t irmax[3];
    cgsize_t zoneSizes[9];
    char zoneName[35];
    cg_zone_read(index_file, index_base, index_zone, zoneName, zoneSizes);
    Msg::Debug("Zone name : %s.", zoneName);

    // Index bounds
    // irmin[0] = 1;
    irmax[0] = zoneSizes[0];
    // irmin[1] = 1;
    irmax[1] = zoneSizes[1];
    // irmin[2] = 1;
    irmax[2] = zoneSizes[2];

    // Compute max multigrid level
    double ielem = irmax[0] - 1;
    double jelem = irmax[1] - 1;
    double kelem = irmax[2] - 1;

    int *ijk = sizeIJK + (index_zone - 1) * 3;

    ijk[0] = ielem;
    ijk[1] = jelem;
    ijk[2] = kelem;

    // printf("Elems %g %g %g\n", ielem, jelem, kelem);
    int order = 1;
    while(fmod(ielem / 2.0, 1.0) == 0.0 && fmod(jelem / 2.0, 1.0) == 0.0 &&
          fmod(kelem / 2.0, 1.0) == 0.0 and order < 5) {
      order *= 2;
      ielem = ielem / 2.0;
      jelem = jelem / 2.0;
      kelem = kelem / 2.0;
    }
    max_order = std::min(order, max_order);
  }

  opt_mesh_cgns_import_order(0, GMSH_SET, max_order);

  int order = CTX::instance()->mesh.cgnsImportOrder;
#if defined(HAVE_FLTK)
  if(CTX::instance()->batch == 0 && FlGui::instance()->available() &&
     CTX::instance()->expertMode) {
    order = cgnsImport();
    CTX::instance()->mesh.order = order;
  }
  else
    order = CTX::instance()->mesh.order;
#endif

  // check for the order

  bool checkAllDim = true;
  for(int index_zone = 1; index_zone <= nZones; index_zone++) {
    int *ijk = sizeIJK + (index_zone - 1) * 3;
    bool checkDim = true;
    for(int i = 0; i < 3; i++) checkDim = checkDim && (ijk[i] % order == 0);
    if(!checkDim) {
      Msg::Error("Zone %d in CGNS file has size %dx%dx%d"
                 "and can therefore not be coarsened to order %d",
                 index_zone, ijk[0], ijk[1], ijk[2], order);
    }
    checkAllDim = checkAllDim && checkDim;
  }

  if(checkAllDim) {
    // determine the element types
    int type_hex = ElementType::getType(TYPE_HEX, order);
    int type_quad = ElementType::getType(TYPE_QUA, order);

    // for entity numbering
    int elementary_region = getNumRegions();
    int elementary_face = getNumFaces();
    // int elementary_edge = getNumEdges();
    // int elementary_vertex = getNumVertices();

    std::set<CGNSStruPeriodic, CGNSStruPeriodicLess> periodicConnections;

    // Read the zones
    for(int index_zone = 1; index_zone <= nZones; index_zone++) {
      Msg::Debug("Reading zone %i.", index_zone);

      int offset = vnum;

      ZoneType_t zoneType;
      cg_zone_type(index_file, index_base, index_zone, &zoneType);
      if(zoneType == Unstructured) {
        Msg::Debug("Unstructured zone detected, skipping.");
        continue;
      }

      cgsize_t irmin[3];
      cgsize_t irmax[3];
      cgsize_t zoneSizes[9];
      char zoneName[35];
      cg_zone_read(index_file, index_base, index_zone, zoneName, zoneSizes);
      Msg::Debug("Zone name : %s.", zoneName);

      // Index bounds
      irmin[0] = 1;
      irmax[0] = zoneSizes[0];
      irmin[1] = 1;
      irmax[1] = zoneSizes[1];
      irmin[2] = 1;
      irmax[2] = zoneSizes[2];

      // Compute max multigrid level
      // double ielem = irmax[0] - 1;
      // double jelem = irmax[1] - 1;
      // double kelem = irmax[2] - 1;

      int nnodesZone;
      int nelements;
      int nBoundaryVertices;
      nnodesZone = zoneSizes[0] * zoneSizes[1] * zoneSizes[2];
      nelements = zoneSizes[3] * zoneSizes[4] * zoneSizes[5];
      nBoundaryVertices = zoneSizes[6] * zoneSizes[7] * zoneSizes[8];
      Msg::Debug("%i nodes, %i elements, and %i vertices on the zone boundary.",
                 nnodesZone, nelements, nBoundaryVertices);

      // Reading the coordinates
      int nCoords;
      cg_ncoords(index_file, index_base, index_zone, &nCoords);

      DataType_t dataType;
      char coordName[35];
      void *coord;
      double nodes[nnodesZone][nCoords];

      for(int iCoord = 0; iCoord < nCoords; iCoord++) {
        if(cg_coord_info(index_file, index_base, index_zone, iCoord + 1,
                         &dataType, coordName)) {
          Msg::Error("Could not read coordinate %i.", iCoord + 1);
          cg_close(index_file);
          return 0;
        }

        Msg::Debug("Reading coordinate %i : %s.", iCoord + 1, coordName);

        switch(dataType) {
        case RealSingle:
          Msg::Debug("        [Type is float]");
          coord = new float[nnodesZone];
          if(cg_coord_read(index_file, index_base, index_zone, coordName,
                           dataType, irmin, irmax, coord)) {
            Msg::Error("Could not read coordinate %i.", iCoord + 1);
            cg_close(index_file);
            return 0;
          }
          for(int iNode = 0; iNode < nnodesZone; iNode++) {
            nodes[iNode][iCoord] = (double)((float *)coord)[iNode] * scale;
          }
          delete[](float *) coord;
          break;
        case RealDouble:
          Msg::Debug("        [Type is double]");
          coord = new double[nnodesZone];
          if(cg_coord_read(index_file, index_base, index_zone, coordName,
                           dataType, irmin, irmax, coord)) {
            Msg::Error("Could not read coordinate %i.", iCoord + 1);
            cg_close(index_file);
            return 0;
          }
          for(int iNode = 0; iNode < nnodesZone; iNode++) {
            nodes[iNode][iCoord] = ((double *)coord)[iNode] * scale;
          }
          delete[](double *) coord;
          break;
        default:
          Msg::Error("Wrong data type for reading coordinates in CGNS file");
          break;
        }
      }

      for(int iNode = 0; iNode < nnodesZone; iNode++) {
        MVertex *mv = new MVertex(nodes[iNode][0], nodes[iNode][1],
                                  nodes[iNode][2], 0, vnum);
        minVertex = std::min(minVertex, vnum);
        maxVertex = std::max(maxVertex, vnum);
        vertexMap[vnum] = mv;
        vnum++;
      }

      int num = 1;
      int num_elements = 0;
      elementary_region++;
      int partition = 0;
      for(int i = 0; i < zoneSizes[3]; i += order) {
        for(int j = 0; j < zoneSizes[4]; j += order) {
          for(int k = 0; k < zoneSizes[5]; k += order) {
            std::vector<MVertex *> vertices;
            std::vector<int> ind_i, ind_j, ind_k;

            getIndices(i, j, k, ind_i, ind_j, ind_k, order);

            for(size_t v = 0; v < ind_i.size(); v++) {
              vertices.push_back(
                vertexMap[offset + to1D(ind_i[v], ind_j[v], ind_k[v], irmax[0],
                                        irmax[1], irmax[2])]);
            }
            createElementMSH(this, num, type_hex, elementary_region, partition,
                             vertices, elements);
            num_elements++;
            num++;
          }
        }
      }

      // Create surface mesh, remove internal connections and encode periodicity

      std::map<int, std::vector<int *> > forbidden;

      int nconnectivity;
      cg_n1to1(index_file, index_base, index_zone, &nconnectivity);
      Msg::Debug("Found %i connectivity zones.", nconnectivity);
      for(int index_section = 1; index_section <= nconnectivity;
          index_section++) {
        char ConnectionName[30];
        char DonorName[30];
        cgsize_t range[6];
        cgsize_t donor_range[6];
        int transform[3];
        cg_1to1_read(index_file, index_base, index_zone, index_section,
                     ConnectionName, DonorName, range, donor_range, transform);

        // face indices in the block and in the global geometry

        int face = computeCGNSFace(range);
        int faceIndex = elementary_face + face + 1;

        // encode periodic boundary transformation  / connection information

        float RotationCenter[3];
        float RotationAngle[3];
        float Translation[3];

        if(cg_1to1_periodic_read(index_file, index_base, index_zone,
                                 index_section, RotationCenter, RotationAngle,
                                 Translation) != CG_NODE_NOT_FOUND) {
          CGNSStruPeriodic pnew(zoneName, range, DonorName, donor_range,
                                transform, order, faceIndex, RotationCenter,
                                RotationAngle, Translation);

          CGNSStruPeriodic pinv(pnew.getInverse());
          std::set<CGNSStruPeriodic, CGNSStruPeriodicLess>::iterator pIter =
            periodicConnections.find(pinv);

          // create a new connection if inverse not found
          if(pIter == periodicConnections.end()) {
            for(size_t ip = 0; ip < pnew.getNbPoints(); ip++) {
              int i(0), j(0), k(0);
              pnew.getTgtIJK(ip, i, j, k);
              pnew.insertTgtVertex(
                ip, vertexMap[offset +
                              to1D(i, j, k, irmax[0], irmax[1], irmax[2])]);
            }
            periodicConnections.insert(pnew);
          }
          // if inverse is found, we need to complete
          else {
            pIter->srcFaceId = faceIndex;
            for(size_t ip = 0; ip < pIter->getNbPoints(); ip++) {
              int i(0), j(0), k(0);
              pIter->getSrcIJK(ip, i, j, k);
              pIter->insertSrcVertex(
                ip, vertexMap[offset +
                              to1D(i, j, k, irmax[0], irmax[1], irmax[2])]);
            }
          }
        }

        // ignore internal connections

        else {
          int *range_int = new int[6];
          for(int r = 0; r < 6; r++) range_int[r] = (int)range[r];
          forbidden[face].push_back(range_int);
        }
      }

      for(int face = 0; face < 6; face++) {
        int imin(0), imax(0), jmin(0), jmax(0), kmin(0), kmax(0);
        int igrow = order;
        int jgrow = order;
        int kgrow = order;
        int move[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        switch(face) {
        case 0:
          imin = 0; imax = zoneSizes[3];
          jmin = 0; jmax = zoneSizes[4];
          kmin = 0; kmax = 1;
          kgrow = 0;
          move[0][0] = 0; move[0][1] = 0;     move[0][2] = igrow; move[0][3] = igrow;
          move[1][0] = 0; move[1][1] = jgrow; move[1][2] = jgrow; move[1][3] = 0;
          move[2][0] = 0; move[2][1] = 0;     move[2][2] = 0;     move[2][3] = 0;
          break;
        case 1:
          imin = 0; imax = zoneSizes[3];
          jmin = 0; jmax = zoneSizes[4];
          kmin = zoneSizes[2] - 1; kmax = zoneSizes[2];
          kgrow = 0;
          move[0][0] = 0; move[0][1] = igrow; move[0][2] = igrow; move[0][3] = 0;
          move[1][0] = 0; move[1][1] = 0;     move[1][2] = jgrow; move[1][3] = jgrow;
          move[2][0] = 0; move[2][1] = 0;     move[2][2] = 0;     move[2][3] = 0;
          break;
        case 2:
          imin = 0; imax = zoneSizes[3];
          jmin = 0; jmax = 1;
          jgrow = 0;
          kmin = 0; kmax = zoneSizes[5];
          move[0][0] = 0; move[0][1] = igrow; move[0][2] = igrow; move[0][3] = 0;
          move[1][0] = 0; move[1][1] = 0;     move[1][2] = 0;     move[1][3] = 0;
          move[2][0] = 0; move[2][1] = 0;     move[2][2] = kgrow; move[2][3] = kgrow;
          break;
        case 3:
          imin = 0;                imax = zoneSizes[3];
          jmin = zoneSizes[1] - 1; jmax = zoneSizes[1];
          jgrow = 0;
          kmin = 0; kmax = zoneSizes[5];
          move[0][0] = 0; move[0][1] = 0;     move[0][2] = igrow; move[0][3] = igrow;
          move[1][0] = 0; move[1][1] = 0;     move[1][2] = 0;     move[1][3] = 0;
          move[2][0] = 0; move[2][1] = kgrow; move[2][2] = kgrow; move[2][3] = 0;
          break;
        case 4:
          imin = 0; imax = 1; igrow = 0;
          jmin = 0; jmax = zoneSizes[4];
          kmin = 0; kmax = zoneSizes[5];
          move[0][0] = 0; move[0][1] = 0;     move[0][2] = 0;     move[0][3] = 0;
          move[1][0] = 0; move[1][1] = 0;     move[1][2] = jgrow; move[1][3] = jgrow;
          move[2][0] = 0; move[2][1] = kgrow; move[2][2] = kgrow; move[2][3] = 0;
          break;
        case 5:
          imin = zoneSizes[0] - 1; imax = zoneSizes[0]; igrow = 0;
          jmin = 0;                jmax = zoneSizes[4];
          kmin = 0;                kmax = zoneSizes[5];
          move[0][0] = 0; move[0][1] = 0;     move[0][2] = 0;     move[0][3] = 0;
          move[1][0] = 0; move[1][1] = jgrow; move[1][2] = jgrow; move[1][3] = 0;
          move[2][0] = 0; move[2][1] = 0;     move[2][2] = kgrow; move[2][3] = kgrow;
          break;
        }

        GRegion *gr = getRegionByTag(elementary_region);
        elementary_face++;

        num = 1;
        for(int i = imin; i < imax; i += order) {
          for(int j = jmin; j < jmax; j += order) {
            for(int k = kmin; k < kmax; k += order) {
              bool ok = true;
              for(size_t ff = 0; ff < forbidden[face].size(); ff++) {
                int *lim = forbidden[face][ff];

                if((i >= fmin(lim[0], lim[3]) - 1 &&
                    i < fmax(lim[0], lim[3]) - 1) ||
                   (igrow == 0)) {
                  if((j >= fmin(lim[1], lim[4]) - 1 &&
                      j < fmax(lim[1], lim[4]) - 1) ||
                     (jgrow == 0)) {
                    if((k >= fmin(lim[2], lim[5]) - 1 &&
                        k < fmax(lim[2], lim[5]) - 1) ||
                       (kgrow == 0)) {
                      ok = false;
                    }
                  }
                }
                // if (!ok) continue;
              }
              if(!ok) continue;

              std::vector<MVertex *> vertices;
              std::vector<int> ind_i, ind_j, ind_k;

              getIndicesQuad(i + move[0][0], i + move[0][1], i + move[0][2],
                             i + move[0][3], j + move[1][0], j + move[1][1],
                             j + move[1][2], j + move[1][3], k + move[2][0],
                             k + move[2][1], k + move[2][2], k + move[2][3],
                             ind_i, ind_j, ind_k, order, face);

              for(size_t v = 0; v < ind_i.size(); v++) {
                vertices.push_back(
                  vertexMap[offset + to1D(ind_i[v], ind_j[v], ind_k[v],
                                          irmax[0], irmax[1], irmax[2])]);
              }

              createElementMSH(this, num, type_quad, elementary_face, partition,
                               vertices, elements);
              num_elements++;
              num++;
            }
          }
        }
        GFace *gf = getFaceByTag(elementary_face);
        if(gf) gf->addRegion(gr);

        for(size_t ff = 0; ff < forbidden[face].size(); ff++)
          delete[] forbidden[face][ff];
      }
    }

    // store the elements in their associated elementary entity. If the
    // entity does not exist, create a new (discrete) one.
    for(int i = 0; i < (int)(sizeof(elements) / sizeof(elements[0])); i++)
      _storeElementsInEntities(elements[i]);

    // associate the correct geometrical entity with each mesh vertex
    _associateEntityWithMeshVertices();
    // store the vertices in their associated geometrical entity
    _storeVerticesInEntities(vertexMap);

    // now encode the periodic boundaries

    std::set<CGNSStruPeriodic, CGNSStruPeriodicLess>::iterator pIter =
      periodicConnections.begin();

    for(; pIter != periodicConnections.end(); ++pIter) {
      GFace *tgt = getFaceByTag(pIter->tgtFaceId);
      GFace *src = getFaceByTag(pIter->srcFaceId);

      tgt->setMeshMaster(src, pIter->tfo);

      std::vector<MVertex *>::const_iterator tIter = pIter->tgtVertices.begin();
      std::vector<MVertex *>::const_iterator sIter = pIter->srcVertices.begin();

      for(; tIter != pIter->tgtVertices.end(); ++tIter, ++sIter) {
        tgt->correspondingVertices[*tIter] = *sIter;
      }
    }

    removeDuplicateMeshVertices(1e-8);

    if(cg_close(index_file)) {
      Msg::Error("Couldn't close the file !");
      return 0;
    }
    return 1;
  }
  return 0;
}

int GModel::readCGNS(const std::string &name)
{
  int structured = _readCGNSStructured(name);
  if(structured) return structured;
  return _readCGNSUnstructured(name);
}


// FIXME: all the code below this line will be rewritten or removed in a future
// release of Gmsh. In particular CGNSUtils.h will be removed.

#include "CGNSUtils.h"

#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_num_threads() 1
#define omp_get_thread_num() 0
#define omp_lock_t int
#define omp_init_lock(x)
#define omp_set_lock(x)
#define omp_unset_lock(x)
#define omp_destroy_lock(x)
#endif

// class to make C style CGNS name strings act like C++ types

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

// Provides a CGNS element type for a MSH element type and indicates the order
// in which the CGNS elements are to be written:
//    3D first-order elements
//    3D second-order elements
//    2D first-order elements
//    2D second-order elements
//    1D first-order elements
//    1D second-order elements
//    MSH_MAX_NUM+1 is used to place non-cgns elements last.
static const int msh2cgns[MSH_MAX_NUM][2] = {
  {BAR_2, 16},
  {TRI_3, 11},
  {QUAD_4, 12},
  {TETRA_4, 1},
  {HEXA_8, 4},
  {PENTA_6, 3},
  {PYRA_5, 2},
  {BAR_3, 17},
  {TRI_6, 13},
  {QUAD_9, 15},
  {TETRA_10, 5},
  {HEXA_27, 10},
  {PENTA_18, 8},
  {PYRA_14, 6},
  {-1, MSH_MAX_NUM + 1}, // MSH_PNT (NODE in CGNS but not used herein)
  {QUAD_8, 14},
  {HEXA_20, 9},
  {PENTA_15, 7},
  {-1, MSH_MAX_NUM + 1}, // MSH_PYR_13
  {-1, MSH_MAX_NUM + 1}, // MSH_TRI_9
  {-1, MSH_MAX_NUM + 1}, // MSH_TRI_10
  {-1, MSH_MAX_NUM + 1}, // MSH_TRI_12
  {-1, MSH_MAX_NUM + 1}, // MSH_TRI_15
  {-1, MSH_MAX_NUM + 1}, // MSH_TRI_15I
  {-1, MSH_MAX_NUM + 1}, // MSH_TRI_21
  {-1, MSH_MAX_NUM + 1}, // MSH_LIN_4
  {-1, MSH_MAX_NUM + 1}, // MSH_LIN_5
  {-1, MSH_MAX_NUM + 1}, // MSH_LIN_6
  {-1, MSH_MAX_NUM + 1}, // MSH_TET_20
  {-1, MSH_MAX_NUM + 1}, // MSH_TET_35
  {-1, MSH_MAX_NUM + 1}, // MSH_TET_56
  {-1, MSH_MAX_NUM + 1}, // MSH_TET_22
  {-1, MSH_MAX_NUM + 1} // MSH_TET_28
};

// This functor allows for sorting of the element types according to the
// "write-order" in array 'msh2cgns'

struct ElemSortCGNSType {
  bool operator()(const int t0, const int t1)
  {
    if(zoneElemConn[t0].numElem > 0 && zoneElemConn[t1].numElem > 0)
      return msh2cgns[t0][1] < msh2cgns[t1][1];
    else if(zoneElemConn[t0].numElem > 0)
      return true;
    else
      return false;
  }
  ElemSortCGNSType(const ElementConnectivity *const _zoneElemConn)
    : zoneElemConn(_zoneElemConn)
  {
  }

private:
  const ElementConnectivity *const zoneElemConn;
};

// type providing a vector of entities for a physical group index
typedef std::map<int, std::vector<GEntity *> > PhysGroupMap;

// Rewrites the mesh connectivity using CGNS node ordering
// zoneElemConn       - (I) connectivity for the zone using gmsh node ordering
//                         (see MElement.h)
//                    - (O) connectivity using CGNS node ordering

static void translateElementMSH2CGNS(ElementConnectivity *const zoneElemConn)
{
  const int maxVPE = 27;
  // Location to write a MSH_TET_10 vertex to get a CGNS TETRA_10
  static const int trTET10[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
  // Location to write a MSH_HEX_20 vertex to get a CGNS HEXA_20
  static const int trHEX20[20] = {0,  1, 2,  3,  4,  5,  6,  7,  8,  11,
                                  12, 9, 13, 10, 14, 15, 16, 19, 17, 18};
  // Location to write a MSH_HEX_27 vertex to get a CGNS HEXA_27
  static const int trHEX27[27] = {0,  1,  2,  3,  4,  5,  6,  7,  8,
                                  11, 12, 9,  13, 10, 14, 15, 16, 19,
                                  17, 18, 20, 21, 24, 22, 23, 25, 26};
  // Location to write a MSH_PRI_15 vertex to get a CGNS PENTA_15
  static const int trPRI15[15] = {0, 1, 2,  3,  4,  5,  6, 8,
                                  9, 7, 10, 11, 12, 14, 13};
  // Location to write a MSH_PRI_18 vertex to get a CGNS PENTA_18
  static const int trPRI18[18] = {0, 1,  2,  3,  4,  5,  6,  8,  9,
                                  7, 10, 11, 12, 14, 13, 15, 17, 16};
  // Location to write a MSH_PYR_13 vertex to get a CGNS PYRA_13
  // PYRA_13 are not in the CGNS standard but if ever added they would have the
  // same ordering as PYRA_14
  static const int trPYR13[13] = {0, 1, 2, 3, 4, 5, 8, 9, 6, 10, 7, 11, 12};
  // Location to write a MSH_PYR_14 vertex to get a CGNS PYRA_14
  static const int trPYR14[14] = {0, 1, 2, 3, 4, 5, 8, 9, 6, 10, 7, 11, 12, 13};

  int tmp[maxVPE];
  for(int iElemType = 0; iElemType != MSH_MAX_NUM; ++iElemType) {
    int numVPE;
    const int *tr;
    if(zoneElemConn[iElemType].numElem > 0) {
      switch(iElemType + 1) {
      case MSH_TET_10:
        numVPE = 10;
        tr = trTET10;
        break;
      case MSH_HEX_20:
        numVPE = 20;
        tr = trHEX20;
        break;
      case MSH_HEX_27:
        numVPE = 27;
        tr = trHEX27;
        break;
      case MSH_PRI_15:
        numVPE = 15;
        tr = trPRI15;
        break;
      case MSH_PRI_18:
        numVPE = 18;
        tr = trPRI18;
        break;
      case MSH_PYR_13: // Although not in the CGNS standard, I assume it would
                       // be the same as PYRA_14 if ever added
        numVPE = 13;
        tr = trPYR13;
        break;
      case MSH_PYR_14:
        numVPE = 14;
        tr = trPYR14;
        break;
      default:
        numVPE = 0;
        tr = 0;
        break;
      }
      if(numVPE > 0) {
        int *aConn = &zoneElemConn[iElemType].connectivity[0];
        for(int n = zoneElemConn[iElemType].numElem; n--;) {
          std::memcpy(tmp, aConn, numVPE * sizeof(int));
          for(int iV = 0; iV != numVPE; ++iV) aConn[tr[iV]] = tmp[iV];
          aConn += numVPE;
        }
      }
    }
  }
}

// Expands variables in a string 's' that are supported by the CGNS I/O.  's'
// is overwritten with the expanded string.
//
// - &I[0][%width]% expands into 'index'.  Normally 'index' is assumed to have
//   C numbering and therefore 1 is added to it.  Option [0] prevents the
//   addition of the one.  Option [%width] sets the width of the index to
//   'width' and pads with leading zeros.
// - &N& expands to 'name'.

void expand_name(std::string &s, const int index, const char *const name)
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


// Defines the next zone based on physicals or partitions and provides a name
// for the zone
//
//   model              - (I) gmsh model
//   zoneDefinition     - (I) how to define the zone (see enum in code)
//   numZone            - (I) Number of zones in the domain
//   options            - (I) options for CGNS I/O
//   meshDim            - (I) dimension of the mesh elements
//   group              - (I) the group of physicals used to define the mesh
//   globalZoneIndex    - (I/O)
//   globalPhysicalIt   - (I/O) a global scope iterator to the physicals
//   zoneIndex          - (O) index of the zone
//   partition          - (O) partition of the zone
//   physicalItBegin    - (O) begin physical for defining the zone
//   physicalItEnd      - (O) end physical for defining the zone
//   zoneName           - (O) name of the zone

int get_zone_definition(
  GModel &model, const int zoneDefinition, const int numZone,
  const CGNSOptions &options, const int meshDim, const PhysGroupMap &group,
  int &globalZoneIndex, PhysGroupMap::const_iterator &globalPhysicalIt,
  int &zoneIndex, int &partition, PhysGroupMap::const_iterator &physicalItBegin,
  PhysGroupMap::const_iterator &physicalItEnd, CGNSNameStr &zoneName)
{
  int status = 0;
  const char *_zoneName = "Partition";
  // NBN: pass name to expand_name(): Zone_&N& ==> Zone_Fluid
  std::string zn;

  //--Get indices for the zonex

  {
    if(globalZoneIndex >= numZone)
      status = 1;
    else {
      switch(zoneDefinition) {
      case 0: // Single zone
        partition = -1;
        physicalItBegin = group.begin();
        physicalItEnd = group.end();
        break;
      case 1: // Zone defined by partition
        partition = globalZoneIndex;
        physicalItBegin = group.begin();
        physicalItEnd = group.end();
        break;
      case 2: // Zone defined by physical
        partition = -1;
        //_zoneName = model.getPhysicalName(meshDim,
        // globalPhysicalIt->first).c_str();
        zn = model.getPhysicalName(meshDim, globalPhysicalIt->first); // NBN:
        _zoneName = zn.c_str(); // NBN:
        physicalItBegin = globalPhysicalIt++;
        physicalItEnd = globalPhysicalIt;
        break;
      }
      zoneIndex = globalZoneIndex++;
    }
  }
  // omp: end critical

  //--Set the name for the zone

  if(status == 0) {
    std::string s = options.zoneName;
    expand_name(s, zoneIndex, _zoneName);
    if(s.length() == 0) { // If empty
      s = "Zone_";
      s += CGNSNameStr(zoneIndex + 1).c_str();
    }
    zoneName = s.c_str();
  }

  return status;
}

// A task for a thread

template <unsigned DIM> struct ZoneTask {
  MZone<DIM> zone;
  CGNSNameStr zoneName;
  int zoneIndex;
  int status; // 0 - free
              // 1 - zone processed and waiting in
              //     queue to be written
              // 2 - zone defined and boundaries
              //     processed
  int indexInOwner;
  ZoneTask() : status(0), indexInOwner(0) {}
  void change_status(const int _status)
  {
    status = _status;
  }
};

// Information about a zone

struct ZoneInfo {
  CGNSNameStr name;
  int cgIndex;
  ZoneInfo() : cgIndex(-1) {}
};

// Writes the CGNS zones, splitting up the work between several processors if
// threads are enabled.
//
//   model              - (I)
//   zoneDefinition     - (I) how to define a zone
//   options            - (I) CGNS specific options
//   scalingFactor
//   vectorDim          - (I) Dimensions of a vector (must be 3 for a 3D mesh,
//                            may be 2 or 3 for a 2D mesh)
//   group              - (I) Group of physicals and associated entities
//   cgIndexFile        - (I) index of the CGNS file node
//   cgIndexBase        - (I) index of the CGNS base node

template <unsigned DIM>
int write_CGNS_zones(GModel &model, const int zoneDefinition, const int numZone,
                     const CGNSOptions &options, const double scalingFactor,
                     const int vectorDim, const PhysGroupMap &group,
                     const int cgIndexFile, const int cgIndexBase)
{
  // Shared data

  int threadsWorking = omp_get_num_threads();
  // Semaphore for working threads
#ifdef _OPENMP
  omp_lock_t threadWLock;
  omp_lock_t queueLock;
#endif

  std::queue<ZoneTask<DIM> *> zoneQueue; // Queue for zones that have been
                                         // defined and are ready to be written
  // Next two are locked by an omp critical
  int globalZoneIndex = 0;
  PhysGroupMap::const_iterator globalPhysicalIt = group.begin();

  // Initialize omp locks

  omp_init_lock(&threadWLock);
  omp_init_lock(&queueLock);

  // Spawn threads

  {
    // Master thread (primary task is to define boundary connections and perform
    // I/O but can also process a zone if idle)

    if(omp_get_thread_num() == 0) {
      ZoneTask<DIM> zoneTask;
      MZoneBoundary<DIM> mZoneBoundary;
      ZoneConnMap zoneConnMap; // Zone connectivity that is generated
                               // whenever a zone is added to
                               // mZoneBoundary
      std::vector<ZoneInfo> zoneInfo;
      zoneInfo.resize(16);
      std::vector<double> dBuffer; // Buffer for double-precision data
      std::vector<cgsize_t> iBuffer1, iBuffer2;
      // Buffers for integer data
      int interfaceIndex = 0; // Index for interfaces
      std::string zoneNameForBC = "";

      while(threadsWorking || zoneQueue.size()) {
        if(zoneQueue.size()) {
          // Write the zone in the queue

          ZoneTask<DIM> *const writeTask = zoneQueue.front();
          MZone<DIM> *const writeZone = &writeTask->zone;

          // Write the zone node
          int cgIndexZone = 0;
          cgsize_t cgZoneSize[3] = {0};
          cgZoneSize[0] = writeZone->zoneVertVec.size(); // Number of vertices
#ifdef CGNS_TEST1
          // Count all the sub-elements in a Triangle 10
          cgZoneSize[1] = 0;
          for(int iElemType = 0; iElemType != MSH_MAX_NUM; ++iElemType) {
            switch(iElemType) {
            case MSH_TRI_10 - 1:
              cgZoneSize[1] +=
                writeZone->zoneElemConn[MSH_TRI_10 - 1].numElem * 9;
              break;
            default:
              cgZoneSize[1] += writeZone->zoneElemConn[iElemType].numElem;
              break;
            }
          }
#else
          cgZoneSize[1] = writeZone->totalElements(); // Number of elements
#endif
          cgZoneSize[2] = writeZone->numBoVert; // Number of boundary vertices
          if(cg_zone_write(cgIndexFile, cgIndexBase,
                           writeTask->zoneName.c_str(), cgZoneSize,
                           Unstructured, &cgIndexZone)) {
            return cgnsErr();
          }
          zoneNameForBC = writeTask->zoneName.c_str();
          // Manually maintain the size of the 'zoneInfo vector'.  'push_back'
          // is not used because the elements are in order of 'zoneIndex'
          if(writeTask->zoneIndex >= static_cast<int>(zoneInfo.size())) {
            zoneInfo.resize(std::max(2 * static_cast<int>(zoneInfo.size()),
                                     writeTask->zoneIndex));
          }
          zoneInfo[writeTask->zoneIndex].name = writeTask->zoneName;
          zoneInfo[writeTask->zoneIndex].cgIndex = cgIndexZone;

          // Write the grid node
          int cgIndexGrid = 0;
          if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                           "GridCoordinates", &cgIndexGrid))
            return cgnsErr();

          // Write the grid coordinates
          int cgIndexCoord = 0;
          dBuffer.resize(cgZoneSize[0]);

          // x-coordinates for this zone
          for(int i = 0; i != cgZoneSize[0]; ++i) {
            dBuffer[i] = writeZone->zoneVertVec[i]->x() * scalingFactor;
          }
          if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                            "CoordinateX", &dBuffer[0], &cgIndexCoord))
            return cgnsErr();

          // y-coordinates for this zone
          for(int i = 0; i != cgZoneSize[0]; ++i) {
            dBuffer[i] = writeZone->zoneVertVec[i]->y() * scalingFactor;
          }
          if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                            "CoordinateY", &dBuffer[0], &cgIndexCoord))
            return cgnsErr();

          // z-coordinates for this zone
          if(vectorDim == 3) {
            for(int i = 0; i != cgZoneSize[0]; ++i) {
              dBuffer[i] = writeZone->zoneVertVec[i]->z() * scalingFactor;
            }
            if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                              "CoordinateZ", &dBuffer[0], &cgIndexCoord))
              return cgnsErr();
          }

          // Obtain indices sorted in the order the CGNS elements will be
          // written
          int indexElemType[MSH_MAX_NUM];
          for(int i = 0; i != MSH_MAX_NUM; ++i) indexElemType[i] = i;
          std::sort<int *, ElemSortCGNSType>(
            indexElemType, indexElemType + MSH_MAX_NUM,
            ElemSortCGNSType(writeZone->zoneElemConn));

          // Write the element connectivity
          const int numElemType = writeZone->numElementTypes();
          int iElemSection = 0;
          for(int iElemType = 0; iElemType != numElemType; ++iElemType) {
            const int typeMSHm1 = indexElemType[iElemType]; // typeMSH-1
            const int typeCGNS = msh2cgns[typeMSHm1][0];
            const char *elemName;
            MElement::getInfoMSH(typeMSHm1 + 1, &elemName);
#ifdef CGNS_TEST1
            if(typeMSHm1 == MSH_TRI_10 - 1) {
              const int nElem3o = writeZone->zoneElemConn[20].numElem;
              const int nElem1o = nElem3o * 9;
              std::vector<int> subConn(nElem1o * 3);
              int iV = 0;
              for(int iElem3o = 0; iElem3o != nElem3o; ++iElem3o) {
                int *elem3o =
                  &writeZone->zoneElemConn[20].connectivity[iElem3o * 10];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[8];
                subConn[iV++] = elem3o[3];
                subConn[iV++] = elem3o[5];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[4];
                subConn[iV++] = elem3o[6];
                subConn[iV++] = elem3o[7];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[3];
                subConn[iV++] = elem3o[4];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[5];
                subConn[iV++] = elem3o[6];
                subConn[iV++] = elem3o[8];
                subConn[iV++] = elem3o[9];
                subConn[iV++] = elem3o[7];
                subConn[iV++] = elem3o[0];
                subConn[iV++] = elem3o[3];
                subConn[iV++] = elem3o[8];
                subConn[iV++] = elem3o[4];
                subConn[iV++] = elem3o[1];
                subConn[iV++] = elem3o[5];
                subConn[iV++] = elem3o[7];
                subConn[iV++] = elem3o[6];
                subConn[iV++] = elem3o[2];
              }
              elemName = "Sub-Triangle 10";
              cgsize_t cgIndexSection;
              if(cg_section_write(
                   cgIndexFile, cgIndexBase, cgIndexZone, elemName, TRI_3,
                   iElemSection + 1, nElem1o + iElemSection,
                   writeZone->zoneElemConn[20].numBoElem * 9 + iElemSection,
                   &subConn[0], &cgIndexSection))
                return cgnsErr();
              ++iElemSection;
            }
            else
#endif
              if(typeCGNS == -1) {
              // This type is not supported in CGNS
              Msg::Warning("Element type %s is not supported in CGNS and "
                           "has not been written to the file",
                           elemName);
            }
            else {
              int cgIndexSection;
              if(cg_section_write(
                   cgIndexFile, cgIndexBase, cgIndexZone, elemName,
                   static_cast<ElementType_t>(typeCGNS), iElemSection + 1,
                   writeZone->zoneElemConn[typeMSHm1].numElem + iElemSection,
                   writeZone->zoneElemConn[typeMSHm1].numBoElem + iElemSection,
                   (cgsize_t *)&writeZone->zoneElemConn[typeMSHm1]
                     .connectivity[0],
                   &cgIndexSection)) {
                return cgnsErr();
              }
              ++iElemSection;
            }
          }

          //--Process interior connectivity

          mZoneBoundary.interiorBoundaryVertices(writeTask->zoneIndex,
                                                 *writeZone, zoneConnMap);
          // Write the connectivity for each zone pair
          const ZoneConnMap::const_iterator gCEnd = zoneConnMap.end();
          for(ZoneConnMap::const_iterator gCIt = zoneConnMap.begin();
              gCIt != gCEnd; ++gCIt) {
            const int nVert = gCIt->second.vertexPairVec.size();
            iBuffer1.resize(nVert);
            iBuffer2.resize(nVert);
            for(int iVert = 0; iVert != nVert; ++iVert) {
              const ZoneConnectivity::VertexPair &vp =
                gCIt->second.vertexPairVec[iVert];
              iBuffer1[iVert] = vp.vertexIndex1;
              iBuffer2[iVert] = vp.vertexIndex2;
            }
            int cgIndexInterface;
            std::string interfaceName = options.interfaceName;
            expand_name(interfaceName, interfaceIndex++, "Interface");
            if(interfaceName.length() == 0) {
              interfaceName = "Interface_";
              interfaceName += CGNSNameStr(interfaceIndex).c_str();
            }
            // In the first zone
            if(cg_conn_write(
                 cgIndexFile, cgIndexBase, zoneInfo[gCIt->first.zone1].cgIndex,
                 interfaceName.c_str(), CGNS::Vertex, Abutting1to1, PointList,
                 nVert, &iBuffer1[0], zoneInfo[gCIt->first.zone2].name.c_str(),
                 Unstructured, PointListDonor, Integer, nVert, &iBuffer2[0],
                 &cgIndexInterface)) {
              return cgnsErr();
            }
            // In the second zone
            if(cg_conn_write(
                 cgIndexFile, cgIndexBase, zoneInfo[gCIt->first.zone2].cgIndex,
                 interfaceName.c_str(), CGNS::Vertex, Abutting1to1, PointList,
                 nVert, &iBuffer2[0], zoneInfo[gCIt->first.zone1].name.c_str(),
                 Unstructured, PointListDonor, Integer, nVert, &iBuffer1[0],
                 &cgIndexInterface)) {
              return cgnsErr();
            }
          }

          //--Pop from the queue

          omp_set_lock(&queueLock);
          zoneQueue.pop();
          omp_unset_lock(&queueLock);

          //--Task finished

          writeTask->change_status(0);
        }

        // No zones waiting in the queue, process a zone

        else {
          PhysGroupMap::const_iterator physicalItBegin;
          PhysGroupMap::const_iterator physicalItEnd;
          // --- int zoneIndex;
          int partition;
          if(get_zone_definition(model, zoneDefinition, numZone, options, DIM,
                                 group, globalZoneIndex, globalPhysicalIt,
                                 zoneTask.zoneIndex, partition, physicalItBegin,
                                 physicalItEnd, zoneTask.zoneName)) {
            omp_set_lock(&threadWLock);
            --threadsWorking;
            omp_unset_lock(&threadWLock);
          }
          else {
            zoneTask.zone.clear();
            // Loop through all physical in the zone definition
            for(PhysGroupMap::const_iterator physicalIt = physicalItBegin;
                physicalIt != physicalItEnd; ++physicalIt) {
              // Add elements from all entities in the physical with defined
              // partition number
              if(partition == -1) {
                zoneTask.zone.template add_elements_in_entities<
                  typename std::vector<GEntity *>::const_iterator>(
                  physicalIt->second.begin(), physicalIt->second.end());
              }
              else {
                zoneTask.zone.template add_elements_in_entities<
                  typename std::vector<GEntity *>::const_iterator>(
                  physicalIt->second.begin() + partition,
                  physicalIt->second.begin() + (partition + 1));
              }
            }
            // Process the zone
            zoneTask.zone.zoneData();
            translateElementMSH2CGNS(zoneTask.zone.zoneElemConn);
            // Add to the queue to get written
            zoneTask.change_status(1);
            omp_set_lock(&queueLock);
            zoneQueue.push(&zoneTask);
            omp_unset_lock(&queueLock);
          }
        }
      } // End master thread loop

      // Write the remaining unconnected vertices as boundary conditions

      if(options.writeBC) {
        ZoneBoVec zoneBoVec; // from 'MZoneBoundary.h'
        if(mZoneBoundary.exteriorBoundaryVertices(options.normalSource,
                                                  zoneBoVec) == 0) {
          // Sort by zone index and then entity index
          const int numBoVert = zoneBoVec.size();
          if(numBoVert >= 1) {
            Msg::Info("writing BoVerts...");

            std::vector<int> iZBV(numBoVert - 1);
            for(int i = 0; i != numBoVert - 1; ++i) iZBV[i] = i;
            std::sort<int *, ZoneBoVecSort>(&iZBV[0], &iZBV[numBoVert - 1],
                                            ZoneBoVecSort(zoneBoVec));
            dBuffer.reserve(1024);
            iBuffer1.reserve(1024);

            int iVert = 0;
            while(iVert != numBoVert - 1) {
              dBuffer.clear();
              iBuffer1.clear();
              const int zoneIndex = zoneBoVec[iZBV[iVert]].zoneIndex;
              const int patchIndex = zoneBoVec[iZBV[iVert]].bcPatchIndex;
              const int iVertStart = iVert;
              std::vector<int> physical_num; // Family number
              std::string physical_name = ""; // Family name

              while(iVert != numBoVert - 1 &&
                    zoneBoVec[iZBV[iVert]].zoneIndex == zoneIndex &&
                    zoneBoVec[iZBV[iVert]].bcPatchIndex == patchIndex) {
                VertexBoundary &vertBo = zoneBoVec[iZBV[iVert]];
                dBuffer.push_back(vertBo.normal[0]);
                dBuffer.push_back(vertBo.normal[1]);
                if(vectorDim == 3) dBuffer.push_back(vertBo.normal[2]);
                iBuffer1.push_back(vertBo.vertexIndex);

                if(physical_num.size() == 0) {
                  physical_num = vertBo.vertex->onWhat()->physicals;
                }
                for(std::size_t ii = 0; ii < physical_num.size(); ++ii) {
                  if(physical_name == "") {
                    physical_name = model.getPhysicalName(model.getDim() - 1,
                                                          physical_num[ii]);
                  }
                }
                ++iVert;
              }
              const int numBCVert = iVert - iVertStart;

              int cgIndexBoco;
              std::string patchName = options.patchName;
              expand_name(patchName, patchIndex, "Patch");
              if(patchName.length() == 0) {
                patchName = "Patch_";
                patchName += CGNSNameStr(patchIndex + 1).c_str();
              }
              if(cg_boco_write(cgIndexFile, cgIndexBase,
                               zoneInfo[zoneIndex].cgIndex, patchName.c_str(),
                               BCTypeNull, PointList, numBCVert, &iBuffer1[0],
                               &cgIndexBoco)) {
                return cgnsErr();
              }

              if(options.normalSource) {
                int normalIndex;
                if(cg_boco_normal_write(
                     cgIndexFile, cgIndexBase, zoneInfo[zoneIndex].cgIndex,
                     cgIndexBoco, &normalIndex, 1, RealDouble, &dBuffer[0])) {
                  return cgnsErr();
                }
              }

              if(physical_name != "") {
                if(cg_goto(cgIndexFile, cgIndexBase, zoneNameForBC.c_str(), 0,
                           "ZoneBC_t", 1, patchName.c_str(), 0, "end"))
                  return cgnsErr();
                if(cg_famname_write(physical_name.c_str())) return cgnsErr();
              }
            }
          }
        }
      }

      // NBN: MZoneBoundary defines no destructor, so force
      // the deallocation of the new pointers with clear()
      mZoneBoundary.clear();
      Msg::Info("Leaving master thread"); // DBG

    } // End master thread instructions
  } // End omp parallel section

  // Destroy omp locks

  omp_destroy_lock(&threadWLock);
  omp_destroy_lock(&queueLock);

  return 0;
}

static int sameVertex(GVertex *v1, MVertex *v2)
{
  // This function determines whether given vertices v1 and v2 are at same
  // location or not
  SPoint3 v1_xyz = v1->xyz();
  SPoint3 v2_xyz = v2->point();

  double dx = abs(v1_xyz[0] - v2_xyz[0]);
  double dy = abs(v1_xyz[1] - v2_xyz[1]);
  double dz = abs(v1_xyz[2] - v2_xyz[2]);

  if((dx + dy + dz) < 0.00001) return 1;
  /* floating point error of 0.00001 is used here.
      if gmsh has any tolerance value change it to that */

  return 0;
}

static int sameVertex(MVertex *v1, MVertex *v2)
{
  // This function determines whether given vertices v1 and v2 are at same
  // location or not
  SPoint3 v1_xyz = v1->point();
  SPoint3 v2_xyz = v2->point();

  double dx = abs(v1_xyz[0] - v2_xyz[0]);
  double dy = abs(v1_xyz[1] - v2_xyz[1]);
  double dz = abs(v1_xyz[2] - v2_xyz[2]);

  if((dx + dy + dz) < 0.00001) return 1;
  // FIXME: floating point error of 0.00001 is used here.  if gmsh has any
  // tolerance value change it to that

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

static void faceOrientationTransfinite(GFace *f, double *Face_Orientation)
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

  *(Face_Orientation + 0) = vec1y * vec2z - vec1z * vec2y;
  *(Face_Orientation + 1) = vec1z * vec2x - vec1x * vec2z;
  *(Face_Orientation + 2) = vec1x * vec2y - vec1y * vec2x;

  double detVecOri =
    sqrt(((*(Face_Orientation + 0)) * (*(Face_Orientation + 0))) +
         ((*(Face_Orientation + 1)) * (*(Face_Orientation + 1))) +
         ((*(Face_Orientation + 2)) * (*(Face_Orientation + 2))));

  *(Face_Orientation + 0) = *(Face_Orientation + 0) / detVecOri;
  *(Face_Orientation + 1) = *(Face_Orientation + 1) / detVecOri;
  *(Face_Orientation + 2) = *(Face_Orientation + 2) / detVecOri;

  return;
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

static int isInterfaceFace(GModel *const model, MVertex *v0, MVertex *v1, MVertex *v2,
                           MVertex *v3)
{
  // This function determines whether a face formed by four corner vertices
  // v0,v1,v2,v3 is an interface-face between two regions or not This function
  // makes use of a fact that a face is an interrior face if it is shared by
  // two volumes
  int countFace(0);

  std::vector<GRegion *> regions;
  for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
    if((*it)->transfinite_vertices.size() &&
       (*it)->transfinite_vertices[0].size() &&
       (*it)->transfinite_vertices[0][0].size()) {
      regions.push_back(*it);
    }

  for(std::size_t iRegion = 0; iRegion < regions.size(); iRegion++) {
    GRegion *gr = regions[iRegion];
    std::vector<GFace *> faces = gr->faces();
    if(faces.size() != 6) {
      Msg::Warning("Error in Number of faces in Structured Mesh Region (!=6) ");
    }

    for(std::size_t iFace = 0; iFace < faces.size(); iFace++) {
      std::vector<GVertex *> vf = faces[iFace]->vertices();
      if(vf.size() != 4) {
        Msg::Warning(
          "Error in Number of vertices in Structured Mesh Face (!=4) ");
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

// class to gather elements that belong to a partition.  This class mimics a
// GEntity class.

class DummyPartitionEntity : public GEntity {
public:
  DummyPartitionEntity() : GEntity(0, 0) {}

  // number of types of elements
  int getNumElementTypes() const { return 1; }
  void getNumMeshElements(unsigned *const c) const { c[0] += elements.size(); }

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const { return &elements[0]; }

  std::vector<MElement *> elements;
};

// Writes out the mesh in CGNS format
//
// name               - (I) file name
// zoneDefinition     - (I) how to define a zone
// options            - (I) options specific to CGNS
// scalingFactor      - (I) scaling for coordinates

int GModel::writeCGNS(const std::string &name, int zoneDefinition,
                      const CGNSOptions &options, double scalingFactor)
{
  enum { vertex = 0, edge = 1, face = 2, region = 3 };

  PhysGroupMap groups[4]; // vector of entities that belong to
  // each physical group (in each
  // dimension)
  std::vector<DummyPartitionEntity> partitions;
  // Dummy entities that store the
  // elements in each partition
  int numZone(0);
  int meshDim(0);

  Msg::Warning("CGNS I/O is at an \"alpha\" software stage");

  // Start writing mesh if it is a Structured mesh
  if(options.structuredMesh == 1) {
    Msg::Info("Writing Structured Mesh...");
    /* This part (Structured CGNS file output) is written with the financial aid
    of Indian Institute of Technology Hyderabad - BRNS sponsored project in 2018
    Under the guidance of Prof. Vinayak Eswaran <eswar@iith.ac.in>
    This may not be complete for special cases - for eg. periodic mesh info, if
    any, are not written.  */

    std::set<GRegion *, GEntityLessThan> regions_set;
    std::set<GFace *, GEntityLessThan> faces_set;
    std::set<GEdge *, GEntityLessThan> edges_set;
    std::set<GVertex *, GEntityLessThan> vertices_set;

    for(GModel::viter it = this->firstVertex(); it != this->lastVertex(); ++it)
      vertices_set.insert(*it);
    for(GModel::eiter it = this->firstEdge(); it != this->lastEdge(); ++it)
      edges_set.insert(*it);
    for(GModel::fiter it = this->firstFace(); it != this->lastFace(); ++it)
      faces_set.insert(*it);
    for(GModel::riter it = this->firstRegion(); it != this->lastRegion(); ++it)
      regions_set.insert(*it);

    // int numTotalRegions  = regions_set.size();
    int numTotalFaces = faces_set.size();
    int numTotalEdges = edges_set.size();
    // int numTotalVertices = vertices_set.size();

    int numInterfaceFaces(0);
    int numInterfaceEdges(0);

    std::vector<GVertex *> vertices;
    for(viter it = firstVertex(); it != lastVertex(); ++it) {
      vertices.push_back(*it);
    }

    std::vector<GEdge *> edges;
    for(eiter it = firstEdge(); it != lastEdge(); ++it) {
      edges.push_back(*it);
    }

    std::vector<GFace *> faces;
    for(fiter it = firstFace(); it != lastFace(); ++it)
      if((*it)->transfinite_vertices.size() &&
         (*it)->transfinite_vertices[0].size()) {
        meshDim = 2;
        faces.push_back(*it);
      }

    std::vector<GRegion *> regions;
    for(GModel::riter it = this->firstRegion(); it != this->lastRegion(); ++it)
      if((*it)->transfinite_vertices.size() &&
         (*it)->transfinite_vertices[0].size() &&
         (*it)->transfinite_vertices[0][0].size()) {
        meshDim = 3;
        regions.push_back(*it);
      }

    if(faces.empty() && regions.empty()) {
      Msg::Warning("No structured grids to save");
      return 0;
    }

    /*
     * Interface Face would be counted by the both regions that they are part of
     * (3D). Sum up the number of faces for each region and subtract total
     * number of faces of the model to get the number of interface faces
     */
    if(meshDim == 3) {
      int numTotFaces(0);
      for(std::size_t i = 0; i < regions.size(); i++) {
        std::vector<GFace *> const &faces = regions[i]->faces();
        numTotFaces += faces.size();
      }
      numInterfaceFaces = numTotFaces - numTotalFaces;
    }
    /*
     * Interface Edge would be counted by the both faces that they are part of
     * (2D). Sum up the number of edges for each face and subtract total number
     * of edges of the model to get the number of interface edges
     */
    if(meshDim == 2) {
      int numTotEdges(0);
      for(std::size_t i = 0; i < faces.size(); i++) {
        std::vector<GEdge *> const &edges = faces[i]->edges();
        numTotEdges += edges.size();
      }
      numInterfaceEdges = numTotEdges - numTotalEdges;
    }

    // Checking Orientation of the mesh
    if((meshDim == 2) && (faces.size() > 1)) {
      Msg::Warning("Face Normals for the 2D mesh should be consistent - "
                   "otherwise the mesh may not work.");
      Msg::Warning("Face normals for all the faces are listed below - if Face "
                   "Normals are not consistent,");
      Msg::Warning("you may need to reverse the order of the vertices for "
                   "'Transfinite Surface' in your .geo file.");
      for(std::size_t iFace = 0; iFace < faces.size(); iFace++) {
        GFace *gf = faces[iFace];
        double *Face_Orientation = NULL;
        Face_Orientation = new double[3];
        faceOrientationTransfinite(gf, &(*Face_Orientation));
        Msg::Info("iFace=  %i \t Orientation=  %f  \t %f  \t %f  ", iFace,
                  *(Face_Orientation + 0), *(Face_Orientation + 1),
                  *(Face_Orientation + 2));
      }
      Msg::Info(" ");
    }
    if((meshDim == 3) && (regions.size() > 1)) {
      Msg::Warning("Volume mesh orientation for the 3D mesh should be "
                   "consistent - otherwise the mesh may not work.");
      Msg::Warning("Volume mesh orientation for all the regions are listed "
                   "below - if Volume mesh orientations are not consistent,");
      Msg::Warning("you may need to change the order of the vertices for "
                   "'Transfinite Volume' in your .geo file.");
      for(std::size_t iRegion = 0; iRegion < regions.size(); iRegion++) {
        GRegion *gr = regions[iRegion];
        int volOri = volumeOrientationTransfinite(gr);
        Msg::Info("iRegion= %i \t Orientation=   %i", iRegion, volOri);
      }
      Msg::Info(" ");
    }

    //--Open the file and get ready to write the zones

    // dimension of the mesh
    int vectorDim = 2;
    if(options.vectorDim == 3) vectorDim = options.vectorDim;
    if(vectorDim != 3) vectorDim = 2; // it can be only 2 or 3 for 2D

    // open the file
    int cgIndexFile = 0;
    if(cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile)) return cgnsErr();

    // write the base node
    int cgIndexBase = 0;
    if(cg_base_write(cgIndexFile, options.baseName.c_str(), meshDim, vectorDim,
                     &cgIndexBase))
      return cgnsErr();

    // write information about who generated the mesh
    if(cg_goto(cgIndexFile, cgIndexBase, "end")) return (cgnsErr());
    if(cg_descriptor_write("About", "Created by Gmsh")) return cgnsErr();

    // Write the zone node
    int cgIndexZone = 0;
    cgsize_t cgZoneSize[9] = {0};

    // for 2D Mesh
    if(meshDim == 2) {
      static int patchIndex(-1);
      static int interfaceIndex(-1);

      for(std::size_t iFace = 0; iFace < faces.size(); iFace++) {
        GFace *gf = faces[iFace];
        std::vector<GEdge *> const &edges = gf->edges();
        if(edges.size() != 4) {
          Msg::Warning(
            "Error in Number of Edges in Structured Mesh Face (!=4) = %i",
            iFace);
        }

        cgZoneSize[0] =
          gf->transfinite_vertices.size(); // imax     // Number of vertices
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
        expand_name(zoneName, iFace, "Zone");

        if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                         Structured, &cgIndexZone)) {
          return cgnsErr();
        }

        // Write the grid node
        int cgIndexGrid = 0;
        if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                         "GridCoordinates", &cgIndexGrid))
          return cgnsErr();

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
                          "CoordinateX", &dBuffer[0], &cgIndexCoord))
          return cgnsErr();

        // y-coordinates for this zone
        for(std::size_t k = 0; k < gf->transfinite_vertices[0].size(); k++) {
          for(std::size_t j = 0; j < gf->transfinite_vertices.size(); j++) {
            MVertex *v = gf->transfinite_vertices[j][k];
            dBuffer[cgZoneSize[0] * k + j] = v->y() * scalingFactor;
          }
        }

        if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                          "CoordinateY", &dBuffer[0], &cgIndexCoord))
          return cgnsErr();

        // z-coordinates for this zone - writes only Z=0 value (even if the mesh
        // is in different Z)
        if(vectorDim == 3) {
          for(std::size_t k = 0; k < gf->transfinite_vertices[0].size(); k++) {
            for(std::size_t j = 0; j < gf->transfinite_vertices.size(); j++) {
              // MVertex *v = gf->transfinite_vertices[j][k];
              // dBuffer[cgZoneSize[0]*k+j] = v->z() * scalingFactor ;
              dBuffer[cgZoneSize[0] * k + j] = 0;
            }
          }

          if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                            "CoordinateZ", &dBuffer[0], &cgIndexCoord))
            return cgnsErr();
        }

        // Writing Boundary Conditions
        BCType_t BCType(BCWallViscous); // Writes all boundary to BCWallViscous
        PointSetType_t ptsettype(PointRange);
        int numBCVert(2);
        int cgIndexBoco(0);
        int cgIndexConn(0);
        int interfaceEdge(0);
        int interfaceWritten(0);
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
          expand_name(patchName, patchIndex, "Patch");

          interfaceIndex += 1;
          std::string interfaceName = "Interface_&I%4&";
          expand_name(interfaceName, interfaceIndex, "Interface");

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
            physical_num =
              gf->transfinite_vertices[static_cast<int>(imax / 2)][0]
                ->onWhat()
                ->physicals;
            if(physical_num.size() > 0) {
              physical_name = this->getPhysicalName(1, physical_num[0]);
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
              physical_name = this->getPhysicalName(1, physical_num[0]);
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
              physical_name = this->getPhysicalName(1, physical_num[0]);
            }
            v1Tmp = v3;
            v2Tmp = v2;
          }
          else { // Edge between v0-v3
            *(Point_Range + 0) = 1;
            *(Point_Range + 1) = 1;
            *(Point_Range + 2) = 1;
            *(Point_Range + 3) = jmax;
            physical_num =
              gf->transfinite_vertices[0][static_cast<int>(jmax / 2)]
                ->onWhat()
                ->physicals;
            if(physical_num.size() > 0) {
              physical_name = this->getPhysicalName(1, physical_num[0]);
            }
            v1Tmp = v0;
            v2Tmp = v3;
          }

          if(numInterfaceEdges >
             0) { // Note: An Edge can have interface with only one more edge
            for(std::size_t jFace = 0; jFace < faces.size(); jFace++) {
              if(jFace != iFace) {
                interfaceEdge = 0;
                GFace *gf2 = faces[jFace];
                std::vector<GEdge *> const &edges_jface = gf2->edges();
                adjoiningZoneName = "Zone_&I%4&";
                expand_name(adjoiningZoneName, jFace, "Zone");

                if(edges_jface.size() != 4) {
                  Msg::Warning("Error in Number of Edges in Structured Mesh "
                               "Face (!=4) = %i",
                               jFace);
                }

                int imax_jFace = gf2->transfinite_vertices
                                   .size(); // imax     // Number of vertices
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

                  int a1(0), a2(0), b1(0), b2(0);
                  a1 = (*(Point_Donor_Range + 2)) - (*Point_Donor_Range);
                  a2 = (*(Point_Donor_Range + 3)) - (*(Point_Donor_Range + 1));
                  b1 = (*(Point_Range + 2)) - (*Point_Range);
                  b2 = (*(Point_Range + 3)) - (*(Point_Range + 1));

                  /* In the interface Face, if one index is varying, other
                   * should remain constant and hence one of a1, a2, b1, b2
                   * should be zero (for 2D) (Index2 - Begin2) = T.(Index1 -
                   * Begin1)
                   *       (Index1 - Begin1) = Transpose[T].(Index2 - Begin2) */
                  int x1(0), y1(0), x2(0), y2(0);
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
                    Msg::Warning("Error Finding Transform matrix for zone "
                                 "interface - Using default values [1 2] ");
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
                                   interfaceName.c_str(),
                                   adjoiningZoneName.c_str(), Point_Range,
                                   Point_Donor_Range, Transform,
                                   &cgIndexConn)) {
                    return cgnsErr();
                  }
                } // End interfaceEdge == 1
              }
            }
          } // End numInterfaceEdges>0

          if((interfaceEdge == 0) && (interfaceWritten == 0)) {
            if(cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                             patchName.c_str(), BCType, ptsettype, numBCVert,
                             Point_Range, &cgIndexBoco)) {
              return cgnsErr();
            }

            if(physical_name != "") {
              if(cg_goto(cgIndexFile, cgIndexBase, zoneName.c_str(), 0,
                         "ZoneBC_t", 1, patchName.c_str(), 0, "end"))
                return cgnsErr();
              if(cg_famname_write(physical_name.c_str())) return cgnsErr();
            }
          }

        } // End writing boco & interface for 2D mesh
      }
    } // End if meshDim == 2D

    // for 3D Mesh
    if(meshDim == 3) {
      vectorDim = 3;
      static int patchIndex(-1);
      static int interfaceIndex(-1);

      for(std::size_t iRegion = 0; iRegion < regions.size(); iRegion++) {
        GRegion *gr = regions[iRegion];
        std::vector<GFace *> faces = gr->faces();
        if(faces.size() != 6) {
          Msg::Warning("Error in Number of Faces in Structured Mesh (!=6) = %i",
                       iRegion);
        }

        cgZoneSize[0] =
          gr->transfinite_vertices.size(); // imax     // Number of vertices
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
        expand_name(zoneName, iRegion, "Zone");

        if(cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                         Structured, &cgIndexZone)) {
          return cgnsErr();
        }

        // Write the grid node
        int cgIndexGrid = 0;
        if(cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                         "GridCoordinates", &cgIndexGrid))
          return cgnsErr();

        // Write the grid coordinates
        int cgIndexCoord = 0;
        dBuffer.resize(imax * jmax * kmax);

        // x-coordinates for this zone
        for(std::size_t kk = 0; kk < gr->transfinite_vertices[0][0].size();
            kk++) {
          for(std::size_t jj = 0; jj < gr->transfinite_vertices[0].size();
              jj++) {
            for(std::size_t ii = 0; ii < gr->transfinite_vertices.size();
                ii++) {
              MVertex *v = gr->transfinite_vertices[ii][jj][kk];
              dBuffer[imax * jmax * kk + imax * jj + ii] =
                v->x() * scalingFactor;
            }
          }
        }
        if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                          "CoordinateX", &dBuffer[0], &cgIndexCoord))
          return cgnsErr();

        // y-coordinates for this zone
        for(std::size_t kk = 0; kk < gr->transfinite_vertices[0][0].size();
            kk++) {
          for(std::size_t jj = 0; jj < gr->transfinite_vertices[0].size();
              jj++) {
            for(std::size_t ii = 0; ii < gr->transfinite_vertices.size();
                ii++) {
              MVertex *v = gr->transfinite_vertices[ii][jj][kk];
              dBuffer[imax * jmax * kk + imax * jj + ii] =
                v->y() * scalingFactor;
            }
          }
        }
        if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                          "CoordinateY", &dBuffer[0], &cgIndexCoord))
          return cgnsErr();

        // z-coordinates for this zone
        for(std::size_t kk = 0; kk < gr->transfinite_vertices[0][0].size();
            kk++) {
          for(std::size_t jj = 0; jj < gr->transfinite_vertices[0].size();
              jj++) {
            for(std::size_t ii = 0; ii < gr->transfinite_vertices.size();
                ii++) {
              MVertex *v = gr->transfinite_vertices[ii][jj][kk];
              dBuffer[imax * jmax * kk + imax * jj + ii] =
                v->z() * scalingFactor;
            }
          }
        }
        if(cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone, RealDouble,
                          "CoordinateZ", &dBuffer[0], &cgIndexCoord))
          return cgnsErr();

        // Writing Boundary Conditions
        BCType_t BCType(BCWallViscous); // Writes all boundary to BCWallViscous
        PointSetType_t ptsettype(PointRange);
        int numBCVert(2);
        int cgIndexBoco(0);
        int cgIndexConn(0);
        int interfaceFace(0);
        int interfaceFaceWritten(0);
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
          expand_name(patchName, patchIndex, "Patch");

          interfaceIndex += 1;
          std::string interfaceName = "Interface_&I%4&";
          expand_name(interfaceName, interfaceIndex, "Interface");

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
            physical_num =
              gr->transfinite_vertices[0][static_cast<int>(jmax / 2)]
                                      [static_cast<int>(kmax / 2)]
                                        ->onWhat()
                                        ->physicals;
            if(physical_num.size() > 0) {
              physical_name = this->getPhysicalName(2, physical_num[0]);
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
              physical_name = this->getPhysicalName(2, physical_num[0]);
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
            physical_num =
              gr->transfinite_vertices[static_cast<int>(imax / 2)][0]
                                      [static_cast<int>(kmax / 2)]
                                        ->onWhat()
                                        ->physicals;
            if(physical_num.size() > 0) {
              physical_name = this->getPhysicalName(2, physical_num[0]);
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
              physical_name = this->getPhysicalName(2, physical_num[0]);
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
            physical_num =
              gr->transfinite_vertices[static_cast<int>(imax / 2)]
                                      [static_cast<int>(jmax / 2)][0]
                                        ->onWhat()
                                        ->physicals;
            if(physical_num.size() > 0) {
              physical_name = this->getPhysicalName(2, physical_num[0]);
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
              physical_name = this->getPhysicalName(2, physical_num[0]);
            }
            v0Tmp = v4;
            v1Tmp = v5;
            v2Tmp = v6;
            v3Tmp = v7;
          }

          if(numInterfaceFaces >
             0) { // Note: An Face can have interface with only one ore Face
            if(isInterfaceFace(this, v0Tmp, v1Tmp, v2Tmp, v3Tmp)) {
              for(std::size_t jRegion = 0; jRegion < regions.size();
                  jRegion++) {
                if(jRegion != iRegion) {
                  interfaceFace = 0;
                  adjoiningZoneName = "Zone_&I%4&";
                  expand_name(adjoiningZoneName, jRegion, "Zone");

                  GRegion *gr2 = regions[jRegion];
                  std::vector<GFace *> faces2 = gr2->faces();
                  if(faces2.size() != 6) {
                    Msg::Warning(
                      "Error in Number of Faces in Structured Mesh (!=6) = %i",
                      jRegion);
                  }

                  int imax_Region2 = gr2->transfinite_vertices.size();
                  int jmax_Region2 = gr2->transfinite_vertices[0].size();
                  int kmax_Region2 = gr2->transfinite_vertices[0][0].size();

                  MVertex *v0R2 = gr2->transfinite_vertices[0][0][0];
                  MVertex *v1R2 =
                    gr2->transfinite_vertices[imax_Region2 - 1][0][0];
                  MVertex *v2R2 =
                    gr2->transfinite_vertices[imax_Region2 - 1]
                                             [jmax_Region2 - 1][0];
                  MVertex *v3R2 =
                    gr2->transfinite_vertices[0][jmax_Region2 - 1][0];
                  MVertex *v4R2 =
                    gr2->transfinite_vertices[0][0][kmax_Region2 - 1];
                  MVertex *v5R2 = gr2->transfinite_vertices[imax_Region2 - 1][0]
                                                           [kmax_Region2 - 1];
                  MVertex *v6R2 =
                    gr2
                      ->transfinite_vertices[imax_Region2 - 1][jmax_Region2 - 1]
                                            [kmax_Region2 - 1];
                  MVertex *v7R2 = gr2->transfinite_vertices[0][jmax_Region2 - 1]
                                                           [kmax_Region2 - 1];

                  if(isInterfaceFace(this, v0R2, v3R2, v7R2,
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
                  if(isInterfaceFace(this, v1R2, v2R2, v6R2,
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
                  if(isInterfaceFace(this, v0R2, v1R2, v5R2,
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
                  if(isInterfaceFace(this, v3R2, v2R2, v6R2,
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
                  if(isInterfaceFace(this, v0R2, v1R2, v2R2,
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
                  if(isInterfaceFace(this, v4R2, v5R2, v6R2,
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

                    int a1(0), a2(0), a3(0), b1(0), b2(0), b3(0);
                    a1 =
                      (*(Point_Donor_Range + 3)) - (*(Point_Donor_Range + 0));
                    a2 =
                      (*(Point_Donor_Range + 4)) - (*(Point_Donor_Range + 1));
                    a3 =
                      (*(Point_Donor_Range + 5)) - (*(Point_Donor_Range + 2));
                    b1 = (*(Point_Range + 3)) - (*(Point_Range + 0));
                    b2 = (*(Point_Range + 4)) - (*(Point_Range + 1));
                    b3 = (*(Point_Range + 5)) - (*(Point_Range + 2));

                    /* In the interface Face, if one index is varying, other
                     * should remain constant and hence one of a1, a2, b1, b2
                     * should be zero (for 2D) (Index2 - Begin2) = T.(Index1 -
                     * Begin1) (Index1 - Begin1) = Transpose[T].(Index2 -
                     * Begin2)
                     */

                    int x1(0), y1(0), z1(0), x2(0), y2(0), z2(0), x3(0), y3(0),
                      z3(0);
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
                      Msg::Warning("Error in finding Transfor Matrix: "
                                   "Determinant != +/-1  (= %i)",
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
                                     &cgIndexConn)) {
                      return cgnsErr();
                    }
                  } // End interfaceFace == 1
                }
              }
            }
          } // End numInterfaceFaces>0

          if((interfaceFace == 0) && (interfaceFaceWritten == 0)) {
            if(cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                             patchName.c_str(), BCType, ptsettype, numBCVert,
                             Point_Range, &cgIndexBoco)) {
              return cgnsErr();
            }
            if(physical_name != "") {
              if(cg_goto(cgIndexFile, cgIndexBase, zoneName.c_str(), 0,
                         "ZoneBC_t", 1, patchName.c_str(), 0, "end"))
                return cgnsErr();
              if(cg_famname_write(physical_name.c_str())) return cgnsErr();
            }
          }

        } // End writing boco & interface for 3D mesh
      }
    } // End if meshDim == 3D

    return 0;
  } // End Writing Structured Mesh

  switch(zoneDefinition) {
  case 1: // By partition

    //--Group the elements of each partition into a dummy entity.  Pointers to
    // the
    //--entities are then made available in groups[DIM][0].

    {
      numZone = _numPartitions;
      if(numZone == 0)
        zoneDefinition = 0;
      else {
        partitions.resize(numZone);
        unsigned numElem[5];
        meshDim = getNumMeshElements(numElem);
        // Load the dummy entities with the elements in each partition
        switch(meshDim) {
        case 3:
          for(riter it = firstRegion(); it != lastRegion(); ++it) {
            numElem[0] = 0;
            numElem[1] = 0;
            numElem[2] = 0;
            numElem[3] = 0;
            numElem[4] = 0;
            (*it)->getNumMeshElements(numElem);
            const int nType = (*it)->getNumElementTypes();
            for(int iType = 0; iType != nType; ++iType) {
              MElement *const *element = (*it)->getStartElementType(iType);
              const int nElem = numElem[iType];
              for(int iElem = 0; iElem != nElem; ++iElem) {
                partitions[element[iElem]->getPartition() - 1]
                  .elements.push_back(element[iElem]);
              }
            }
          }
          break;
        case 2:
          for(fiter it = firstFace(); it != lastFace(); ++it) {
            numElem[0] = 0;
            numElem[1] = 0;
            numElem[2] = 0;
            numElem[3] = 0;
            numElem[4] = 0;
            (*it)->getNumMeshElements(numElem);
            const int nType = (*it)->getNumElementTypes();
            for(int iType = 0; iType != nType; ++iType) {
              MElement *const *element = (*it)->getStartElementType(iType);
              const int nElem = numElem[iType];
              for(int iElem = 0; iElem != nElem; ++iElem) {
                partitions[element[iElem]->getPartition() - 1]
                  .elements.push_back(element[iElem]);
              }
            }
          }
          break;
        default: Msg::Error("No mesh elements were found"); return 0;
        }
        // Place pointers to the entities in the 'groups' object
        std::vector<GEntity *> &ents = groups[meshDim][0];
        ents.resize(numZone);
        for(int iPart = 0; iPart != numZone; ++iPart)
          ents[iPart] = &partitions[iPart];
      }
    }
    break;
  case 2: // By physical

    //--Get a list of groups in each dimension and each of the entities in that
    //--group.

    getPhysicalGroups(groups);
    if(groups[region].size()) {
      numZone = groups[region].size();
      meshDim = 3;
    }
    else if(groups[face].size()) {
      numZone = groups[face].size();
      meshDim = 2;
    }
    else {
      zoneDefinition = 0; // Use single zone
    }
    break;
  }

  //--For a single zone, put all the entities for a dimension into
  // groups[DIM][0]

  if(zoneDefinition == 0) {
    numZone = 1;
    unsigned numElem[5];
    numElem[0] = 0;
    numElem[1] = 0;
    numElem[2] = 0;
    numElem[3] = 0;
    numElem[4] = 0;
    meshDim = getNumMeshElements(numElem);
    switch(meshDim) {
    case 3: {
      groups[region].clear();
      std::vector<GEntity *> &ents = groups[region][0];
      ents.resize(getNumRegions());
      int iEnt = 0;
      for(riter it = firstRegion(); it != lastRegion(); ++it)
        ents[iEnt++] = *it;
    } break;
    case 2: {
      groups[face].clear();
      std::vector<GEntity *> &ents = groups[face][0];
      ents.resize(getNumFaces());
      int iEnt = 0;
      for(fiter it = firstFace(); it != lastFace(); ++it) ents[iEnt++] = *it;
    } break;
    default: Msg::Error("No mesh elements were found"); return 0;
    }
  }

  /*--------------------------------------------------------------------*
   * Summary of three possibilities for the 'zoneDefinition':
   * 0) single zone: all the entities are placed in physical 0.  All the
   *    entities form the zone.
   * 1) defined by partitions:  all the entities are place in physical
   *    0.  Each entity is a zone.
   * 2) defined by physicals:  all the entities in a physical form a
   *    zone.
   *--------------------------------------------------------------------*/

  //--Open the file and get ready to write the zones

  // Get the dimension of a vector in the mesh
  int vectorDim = 3;
  if(meshDim == 2) vectorDim = options.vectorDim;

  // open the file
  int cgIndexFile = 0;
  if(cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile)) return cgnsErr();

  // write the base node
  int cgIndexBase = 0;
  if(cg_base_write(cgIndexFile, options.baseName.c_str(), meshDim, meshDim,
                   &cgIndexBase))
    return cgnsErr();

  // write information about who generated the mesh
  if(cg_goto(cgIndexFile, cgIndexBase, "end")) return (cgnsErr());
  if(cg_descriptor_write("About", "Created by Gmsh")) return cgnsErr();

  switch(meshDim) {
  case 2:
    MZone<2>::preInit();
    MZoneBoundary<2>::preInit();
    write_CGNS_zones<2>(*this, zoneDefinition, numZone, options, scalingFactor,
                        vectorDim, groups[face], cgIndexFile, cgIndexBase);
    MZone<2>::postDestroy();
    MZoneBoundary<2>::postDestroy();
    break;
  case 3:
    MZone<3>::preInit();
    MZoneBoundary<3>::preInit();
    write_CGNS_zones<3>(*this, zoneDefinition, numZone, options, scalingFactor,
                        vectorDim, groups[region], cgIndexFile, cgIndexBase);
    MZone<3>::postDestroy();
    MZoneBoundary<3>::postDestroy();
    break;
  }

  //--Close the file

  if(cg_close(cgIndexFile)) return cgnsErr();

  return 0;
}

#else

int GModel::_readCGNSUnstructured(const std::string &fileName) { return 0; }

int GModel::_readCGNSStructured(const std::string &name) { return 0; }

int GModel::readCGNS(const std::string &name)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

int GModel::writeCGNS(const std::string &name, int zoneDefinition,
                      const CGNSOptions &options, double scalingFactor)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

#endif
