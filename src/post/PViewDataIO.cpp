// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string.h>
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Numeric.h"
#include "PViewData.h"
#include "MPolygon.h"
#include "MPolyhedron.h"
#include "adaptiveData.h"
#include "OS.h"

bool PViewData::writeSTL(const std::string &fileName)
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  if(!getNumTriangles() && !getNumQuadrangles()) {
    Msg::Error("No surface elements to save");
    fclose(fp);
    return false;
  }

  int step = getFirstNonEmptyTimeStep();

  fprintf(fp, "solid Created by Gmsh\n");
  for(int ent = 0; ent < getNumEntities(step); ent++) {
    for(int ele = 0; ele < getNumElements(step, ent); ele++) {
      if(getDimension(step, ent, ele) != 2) continue;
      if(skipElement(step, ent, ele)) continue;
      int N = getNumNodes(step, ent, ele);
      if(N != 3 && N != 4) continue;
      double x[4], y[4], z[4], n[3];
      for(int i = 0; i < N; i++) getNode(step, ent, ele, i, x[i], y[i], z[i]);
      normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
      if(N == 3) {
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[1], y[1], z[1]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
      }
      else {
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[1], y[1], z[1]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
        fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
        fprintf(fp, "  outer loop\n");
        fprintf(fp, "    vertex %g %g %g\n", x[0], y[0], z[0]);
        fprintf(fp, "    vertex %g %g %g\n", x[2], y[2], z[2]);
        fprintf(fp, "    vertex %g %g %g\n", x[3], y[3], z[3]);
        fprintf(fp, "  endloop\n");
        fprintf(fp, "endfacet\n");
      }
    }
  }
  fprintf(fp, "endsolid Created by Gmsh\n");

  fclose(fp);
  return true;
}

bool PViewData::writeTXT(const std::string &fileName)
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  for(int step = 0; step < getNumTimeSteps(); step++) {
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double x, y, z;
          getNode(step, ent, ele, nod, x, y, z);
          fprintf(fp, "%d %.16g %d %d %.16g %.16g %.16g ", step, getTime(step),
                  ent, ele, x, y, z);
          for(int comp = 0; comp < getNumComponents(step, ent, ele); comp++) {
            double val;
            getValue(step, ent, ele, nod, comp, val);
            fprintf(fp, "%.16g ", val);
          }
        }
        fprintf(fp, "\n");
      }
    }
  }

  fclose(fp);
  return true;
}

bool PViewData::writePOS(const std::string &fileName, bool binary, bool parsed,
                         bool append)
{
  if(_adaptive) {
    Msg::Warning(
      "Writing adapted dataset (will only export current time step)");
    return _adaptive->getData()->writePOS(fileName, binary, parsed, append);
  }
  if(hasMultipleMeshes()) {
    Msg::Error("Cannot export multi-mesh datasets in .pos format");
    return false;
  }
  if(haveInterpolationMatrices())
    Msg::Warning(
      "Discarding interpolation matrices when saving in .pos format");
  if(binary || !parsed)
    Msg::Warning("Only parsed .pos files can be exported for this view type");

  FILE *fp = Fopen(fileName.c_str(), append ? "a" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  fprintf(fp, "View \"%s\" {\n", getName().c_str());

  int firstNonEmptyStep = getFirstNonEmptyTimeStep();
  for(int ent = 0; ent < getNumEntities(firstNonEmptyStep); ent++) {
    for(int ele = 0; ele < getNumElements(firstNonEmptyStep, ent); ele++) {
      if(skipElement(firstNonEmptyStep, ent, ele)) continue;
      int type = getType(firstNonEmptyStep, ent, ele);
      int numComp = getNumComponents(firstNonEmptyStep, ent, ele);
      const char *s = nullptr;
      // the data at Gauss points is written at points
      bool gauss = useGaussPoints();
      switch(gauss ? TYPE_PNT : type) {
      case TYPE_PNT:
        s = (numComp == 9) ? "TP" : (numComp == 3) ? "VP" : "SP";
        break;
      case TYPE_LIN:
        s = (numComp == 9) ? "TL" : (numComp == 3) ? "VL" : "SL";
        break;
      case TYPE_TRI:
        s = (numComp == 9) ? "TT" : (numComp == 3) ? "VT" : "ST";
        break;
      case TYPE_QUA:
        s = (numComp == 9) ? "TQ" : (numComp == 3) ? "VQ" : "SQ";
        break;
      case TYPE_TET:
        s = (numComp == 9) ? "TS" : (numComp == 3) ? "VS" : "SS";
        break;
      case TYPE_HEX:
        s = (numComp == 9) ? "TH" : (numComp == 3) ? "VH" : "SH";
        break;
      case TYPE_PRI:
        s = (numComp == 9) ? "TI" : (numComp == 3) ? "VI" : "SI";
        break;
      case TYPE_PYR:
        s = (numComp == 9) ? "TY" : (numComp == 3) ? "VY" : "SY";
        break;
      case TYPE_POLYG:
        s = (numComp == 9) ? "TT" : (numComp == 3) ? "VT" : "ST";
        break;
      case TYPE_POLYH:
        s = (numComp == 9) ? "TS" : (numComp == 3) ? "VS" : "SS";
        break;
      }
      if(!s) continue;
      // polytopes are written as their sub-simplices, on which the data is P1
      std::vector<std::vector<int>> simplices;
      if(gauss) {
        for(int nod = 0; nod < getNumNodes(firstNonEmptyStep, ent, ele); nod++)
          simplices.push_back({nod});
      }
      else if(type == TYPE_POLYG || type == TYPE_POLYH) {
        MElement *e = getElement(firstNonEmptyStep, ent, ele);
        if(!e) continue;
        if(type == TYPE_POLYG) {
          MPolygon *p = static_cast<MPolygon *>(e);
          for(int i = 0; i < p->getNumTriangles(); i++) {
            std::array<int, 3> is = p->getTriangleIndices(i);
            simplices.push_back({is[0], is[1], is[2]});
          }
        }
        else {
          MPolyhedron *p = static_cast<MPolyhedron *>(e);
          for(int i = 0; i < p->getNumTetrahedra(); i++) {
            std::array<int, 4> is = p->getTetrahedronIndices(i);
            simplices.push_back({is[0], is[1], is[2], is[3]});
          }
        }
      }
      else {
        simplices.push_back({});
        for(int nod = 0; nod < getNumNodes(firstNonEmptyStep, ent, ele); nod++)
          simplices.back().push_back(nod);
      }
      for(auto &nodes : simplices) {
        fprintf(fp, "%s(", s);
        int numNod = (int)nodes.size();
        for(int nod = 0; nod < numNod; nod++) {
          double x, y, z;
          getNode(firstNonEmptyStep, ent, ele, nodes[nod], x, y, z);
          fprintf(fp, "%.16g,%.16g,%.16g", x, y, z);
          if(nod != numNod - 1) fprintf(fp, ",");
        }
        bool first = true;
        for(int step = 0; step < getNumTimeSteps(); step++) {
          if(hasTimeStep(step)) {
            for(int nod = 0; nod < numNod; nod++) {
              for(int comp = 0; comp < numComp; comp++) {
                double val = 0.0;
                getValue(step, ent, ele, nodes[nod], comp, val);
                if(first) {
                  fprintf(fp, "){%.16g", val);
                  first = false;
                }
                else
                  fprintf(fp, ",%.16g", val);
              }
            }
          }
        }
        fprintf(fp, "};\n");
      }
    }
  }

  fprintf(fp, "};\n");
  fclose(fp);

  return true;
}

bool PViewData::writeMSH(const std::string &fileName, double version,
                         bool binary, bool saveMesh, bool multipleView,
                         int partitionNum, bool saveInterpolationMatrices,
                         bool forceNodeData, bool forceElementData)
{
  Msg::Error("MSH export not implemented for this view type");
  return false;
}

bool PViewData::writeMED(const std::string &fileName, bool saveMesh)
{
  Msg::Error("MED export only available for mesh-based post-processing views");
  return false;
}

bool PViewData::toVector(std::vector<std::vector<double> > &vec)
{
  vec.resize(getNumTimeSteps());
  for(int step = 0; step < getNumTimeSteps(); step++) {
    vec[step].clear();
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          for(int comp = 0; comp < getNumComponents(step, ent, ele); comp++) {
            double val;
            getValue(step, ent, ele, nod, comp, val);
            vec[step].push_back(val);
          }
        }
      }
    }
  }
  return true;
}

bool PViewData::fromVector(const std::vector<std::vector<double> > &vec)
{
  if(empty() || !getNumTimeSteps()) {
    Msg::Warning("Cannot import vector in an empty view; skipping");
    return false;
  }

  if((int)vec.size() != getNumTimeSteps()) {
    Msg::Error(
      "Incompatible number of steps in vector for view import (%d!=%d)",
      (int)vec.size(), getNumTimeSteps());
    return false;
  }

  for(int step = 0; step < getNumTimeSteps(); step++) {
    int i = 0;
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        if(skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++) {
          double x, y, z;
          getNode(step, ent, ele, nod, x, y, z);
          for(int comp = 0; comp < getNumComponents(step, ent, ele); comp++) {
            if(i < (int)vec[step].size()) {
              setValue(step, ent, ele, nod, comp, vec[step][i++]);
            }
            else {
              Msg::Error("Bad index (%d) in vector (%d) for view import", i,
                         (int)vec[step].size());
              return false;
            }
          }
        }
      }
    }
  }
  return true;
}

void PViewData::importLists(int N[24], std::vector<double> *V[24])
{
  Msg::Error("importLists not available for this view data type");
}

void PViewData::getListPointers(int N[24], std::vector<double> *V[24])
{
  Msg::Error("getListPointers not available for this view data type");
}

void PViewData::sendToServer(const std::string &name)
{
  // a single value
  std::vector<std::vector<double> > vec;
  if(!toVector(vec) || vec.size() != 1 || vec[0].size() != 1) {
    Msg::Error("Cannot send a view with more than one value to ONELAB");
    return;
  }
  Msg::SetOnelabNumber(name, vec[0][0]);
}
