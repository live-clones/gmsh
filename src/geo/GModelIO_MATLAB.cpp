// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <utility>

#include "GModel.h"
#include "OS.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "StringUtils.h"

std::string getMATLABName(int type);

void writeElementsMATLAB(FILE *fp, const GEntity *entity, int filetype,
                         bool binary, int physical)
{
  if(filetype != 0) return;
  for(std::size_t j = 0; j < entity->getNumMeshElements(); j++) {
    if(entity->getMeshElement(j)->getTypeForMSH())
      entity->getMeshElement(j)->writeMATLAB(fp, filetype, entity->tag(),
                                             physical, binary);
  }
  return;
}

void storePairMATLAB(
  const GEntity *entity, int physical,
  std::vector<std::vector<std::pair<MElement *, int> > > &elems)
{
  for(std::size_t j = 0; j < entity->getNumMeshElements(); j++) {
    int elemtype = entity->getMeshElement(j)->getTypeForMSH();
    if(elemtype)
      elems[elemtype - 1].push_back(
        std::make_pair(entity->getMeshElement(j), physical));
  }
  return;
}

int GModel::writeMATLAB(const std::string &name, bool binary, bool saveAll,
                        double scalingFactor, int filetype)
{
  // File type
  int SIMPLE = 0; // very simple with only triangles
  int LOAD_GMSH2 = 1; // structure same as utils/converters/matlab/load_gmsh2.m

  // Hardcoded...
  filetype = LOAD_GMSH2;

  if(binary) {
    // TODO
    Msg::Warning(
      "Binary format not available for Matlab, saving into ASCII format");
    binary = false;
  }

  FILE *fp = Fopen(name.c_str(), binary ? "wb" : "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // get the number of vertices and index the vertices in a continuous
  // sequence
  int numVertices = indexMeshVertices(saveAll);

  fprintf(fp, "%%%% Matlab mesh\n");
  fprintf(fp, "%%%% %s, Created by Gmsh\n", getName().c_str());
  if(binary)
    fprintf(fp, "%%%% BINARY\n");
  else
    fprintf(fp, "%%%% ASCII\n");

  // get all the entities in the model
  std::vector<GEntity *> entities;
  getEntities(entities);

  // Print mesh vertices
  if(filetype == SIMPLE) {
    fprintf(fp, "gVertices = %d;\n", numVertices);
    fprintf(fp, "gXYZ = [\n");
    for(std::size_t i = 0; i < entities.size(); i++)
      for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
        entities[i]->mesh_vertices[j]->writeMATLAB(fp, filetype, binary,
                                                   scalingFactor);
    fprintf(fp, "];\n");
    // triangles
    fprintf(fp, "%%%%\n");
    fprintf(fp, "gTri=[\n");
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(saveAll)
        writeElementsMATLAB(fp, entities[i], filetype, binary, 0);
      else if(entities[i]->getPhysicalEntities().size()) {
        for(std::size_t k = 0; k < entities[i]->getPhysicalEntities().size();
            k++) {
          int physical = entities[i]->getPhysicalEntities()[k];
          writeElementsMATLAB(fp, entities[i], filetype, binary, physical);
        }
      }
    }
    fprintf(fp, "];\n");
    fprintf(fp, "nTri=size(gTri,1);\n");
  }

  //  int nelemtype = 0; //number of element type
  if(filetype == LOAD_GMSH2) {
    fprintf(fp, "clear msh;\n");
    fprintf(fp, "msh.nbNod = %d;\n", numVertices);
    fprintf(fp, "msh.POS = [\n");
    for(std::size_t i = 0; i < entities.size(); i++)
      for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++)
        entities[i]->mesh_vertices[j]->writeMATLAB(fp, filetype, binary,
                                                   scalingFactor);
    fprintf(fp, "];\n");
    fprintf(fp, "msh.MAX = max(msh.POS);\n");
    fprintf(fp, "msh.MIN = min(msh.POS);\n");
    // We have to store every element in an array and then store them in the
    // file.
    std::vector<std::vector<std::pair<MElement *, int> > > elems(MSH_MAX_NUM);
    // loop on each element and fill the vectors of connectivity
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(saveAll)
        storePairMATLAB(entities[i], 0, elems);
      else {
        for(std::size_t iphys = 0;
            iphys < entities[i]->getPhysicalEntities().size(); iphys++) {
          int physical = entities[i]->getPhysicalEntities()[iphys];
          storePairMATLAB(entities[i], physical, elems);
        }
      }
    }
    // Store in Matlab structure
    for(int elemtype = 1; elemtype < MSH_MAX_NUM + 1; elemtype++) {
      if(elems[elemtype - 1].empty()) continue;
      fprintf(fp, "msh.%s =[\n", getMATLABName(elemtype).c_str());
      // writes
      for(std::size_t i = 0; i < elems[elemtype - 1].size(); i++) {
        elems[elemtype - 1][i].first->writeMATLAB(
          fp, filetype, elems[elemtype - 1][i].second, binary);
      }
      fprintf(fp, "];\n");
    }
  }

  fclose(fp);
  return 1;
}

// This should be updated whenever a new element is available in GMSH; see
// src/common/GmshDefines.h
std::string getMATLABName(int type)
{
  switch(type) {
  case MSH_LIN_2: return "LINES";
  case MSH_TRI_3: return "TRIANGLES";
  case MSH_QUA_4: return "QUADS";
  case MSH_TET_4: return "TETS";
  case MSH_HEX_8: return "HEXAS";
  case MSH_PRI_6: return "PRISMS";
  case MSH_PYR_5: return "PYRAMIDS";
  case MSH_LIN_3: return "LINES3";
  case MSH_TRI_6: return "TRIANGLES6";
  case MSH_QUA_9: return "QUADS9";
  case MSH_TET_10: return "TETS10";
  case MSH_HEX_27: return "HEXAS27";
  case MSH_PRI_18: return "PRISMS18";
  case MSH_PYR_14: return "PYRAMIDS14";
  case MSH_PNT: return "PNT";
  case MSH_QUA_8: return "QUADS8";
  case MSH_HEX_20: return "HEXAS20";
  case MSH_PRI_15: return "PRISMS15";
  case MSH_PYR_13: return "PYRAMIDS13";
  case MSH_TRI_9: return "TRIANGLES9";
  case MSH_TRI_10: return "TRIANGLES10";
  case MSH_TRI_12: return "TRIANGLES12";
  case MSH_TRI_15: return "TRIANGLES15";
  case MSH_TRI_15I: return "TRIANGLES15I";
  case MSH_TRI_21: return "TRIANGLES21";
  case MSH_LIN_4: return "LINES4";
  case MSH_LIN_5: return "LINES5";
  case MSH_LIN_6: return "LINES6";
  case MSH_TET_20: return "TETS20";
  case MSH_TET_35: return "TETS35";
  case MSH_TET_56: return "TETS56";
  case MSH_TET_22: return "TETS22";
  case MSH_TET_28: return "TETS28";
  case MSH_POLYG_: return "POLYG_";
  case MSH_POLYH_: return "POLYH_";
  case MSH_QUA_16: return "QUADS16";
  case MSH_QUA_25: return "QUADS25";
  case MSH_QUA_36: return "QUADS36";
  case MSH_QUA_12: return "QUADS12";
  case MSH_QUA_16I: return "QUADS16I";
  case MSH_QUA_20: return "QUADS20";
  case MSH_TRI_28: return "TRIANGLES28";
  case MSH_TRI_36: return "TRIANGLES36";
  case MSH_TRI_45: return "TRIANGLES45";
  case MSH_TRI_55: return "TRIANGLES55";
  case MSH_TRI_66: return "TRIANGLES66";
  case MSH_QUA_49: return "QUADS49";
  case MSH_QUA_64: return "QUADS64";
  case MSH_QUA_81: return "QUADS81";
  case MSH_QUA_100: return "QUADS100";
  case MSH_QUA_121: return "QUADS121";
  case MSH_TRI_18: return "TRIANGLES18";
  case MSH_TRI_21I: return "TRIANGLES21I";
  case MSH_TRI_24: return "TRIANGLES24";
  case MSH_TRI_27: return "TRIANGLES27";
  case MSH_TRI_30: return "TRIANGLES30";
  case MSH_QUA_24: return "QUADS24";
  case MSH_QUA_28: return "QUADS28";
  case MSH_QUA_32: return "QUADS32";
  case MSH_QUA_36I: return "QUADS36I";
  case MSH_QUA_40: return "QUADS40";
  case MSH_LIN_7: return "LINES7";
  case MSH_LIN_8: return "LINES8";
  case MSH_LIN_9: return "LINES9";
  case MSH_LIN_10: return "LINES10";
  case MSH_LIN_11: return "LINES11";
  case MSH_LIN_B: return "LINESB";
  case MSH_TRI_B: return "TRIANGLESB";
  case MSH_POLYG_B: return "POLYG_B";
  case MSH_LIN_C: return "LINESC";
  case MSH_TET_84: return "TETS84";
  case MSH_TET_120: return "TETS120";
  case MSH_TET_165: return "TETS165";
  case MSH_TET_220: return "TETS220";
  case MSH_TET_286: return "TETS286";
  case MSH_TET_34: return "TETS34";
  case MSH_TET_40: return "TETS40";
  case MSH_TET_46: return "TETS46";
  case MSH_TET_52: return "TETS52";
  case MSH_TET_58: return "TETS58";
  case MSH_LIN_1: return "LINES1";
  case MSH_TRI_1: return "TRIANGLES1";
  case MSH_QUA_1: return "QUADS1";
  case MSH_TET_1: return "TETS1";
  case MSH_HEX_1: return "HEXAS1";
  case MSH_PRI_1: return "PRISMS1";
  case MSH_PRI_40: return "PRISMS40";
  case MSH_PRI_75: return "PRISMS75";
  case MSH_HEX_64: return "HEXAS64";
  case MSH_HEX_125: return "HEXAS125";
  case MSH_HEX_216: return "HEXAS216";
  case MSH_HEX_343: return "HEXAS343";
  case MSH_HEX_512: return "HEXAS512";
  case MSH_HEX_729: return "HEXAS729";
  case MSH_HEX_1000: return "HEXAS1000";
  case MSH_HEX_32: return "HEXAS32";
  case MSH_HEX_44: return "HEXAS44";
  case MSH_HEX_56: return "HEXAS56";
  case MSH_HEX_68: return "HEXAS68";
  case MSH_HEX_80: return "HEXAS80";
  case MSH_HEX_92: return "HEXAS92";
  case MSH_HEX_104: return "HEXAS104";
  case MSH_PRI_126: return "PRISMS126";
  case MSH_PRI_196: return "PRISMS196";
  case MSH_PRI_288: return "PRISMS288";
  case MSH_PRI_405: return "PRISMS405";
  case MSH_PRI_550: return "PRISMS550";
  case MSH_PRI_24: return "PRISMS24";
  case MSH_PRI_33: return "PRISMS33";
  case MSH_PRI_42: return "PRISMS42";
  case MSH_PRI_51: return "PRISMS51";
  case MSH_PRI_60: return "PRISMS60";
  case MSH_PRI_69: return "PRISMS69";
  case MSH_PRI_78: return "PRISMS78";
  case MSH_PYR_30: return "PYRAMIDS30";
  case MSH_PYR_55: return "PYRAMIDS55";
  case MSH_PYR_91: return "PYRAMIDS91";
  case MSH_PYR_140: return "PYRAMIDS140";
  case MSH_PYR_204: return "PYRAMIDS204";
  case MSH_PYR_285: return "PYRAMIDS285";
  case MSH_PYR_385: return "PYRAMIDS385";
  case MSH_PYR_21: return "PYRAMIDS21";
  case MSH_PYR_29: return "PYRAMIDS29";
  case MSH_PYR_37: return "PYRAMIDS37";
  case MSH_PYR_45: return "PYRAMIDS45";
  case MSH_PYR_53: return "PYRAMIDS53";
  case MSH_PYR_61: return "PYRAMIDS61";
  case MSH_PYR_69: return "PYRAMIDS69";
  case MSH_PYR_1: return "PYRAMIDS1";
  case MSH_PNT_SUB: return "PNT_SUB";
  case MSH_LIN_SUB: return "LINESSUB";
  case MSH_TRI_SUB: return "TRIANGLESSUB";
  case MSH_TET_SUB: return "TETSSUB";
  case MSH_TET_16: return "TETS16";
  case MSH_TRI_MINI: return "TRIANGLESMINI";
  case MSH_TET_MINI: return "TETSMINI";
  case MSH_TRIH_4: return "TRIH_4";
  }
  return "";
}
