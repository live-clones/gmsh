// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-B-> Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "GmshMessage.h"
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"

std::map<int, nodalBasis*> BasisFactory::fs;

const nodalBasis* BasisFactory::create(int elementType) {

  // If the Basis has already been built, return it.
  std::map<int, nodalBasis*>::const_iterator it = fs.find(elementType);
  if (it != fs.end()) {
    return it->second;
  }
  // Get the parent type to see which kind of basis
  // we want to create
  int parentType = MElement::ParentTypeFromTag(elementType);
  nodalBasis* B = 0;

  switch(parentType) {
    case(TYPE_PNT):
    case(TYPE_LIN):
    case(TYPE_TRI):
    case(TYPE_QUA):
    case(TYPE_PRI):
    case(TYPE_TET):
    case(TYPE_HEX):
      B = new polynomialBasis();
      break;
    case(TYPE_PYR):
      B = new pyramidalBasis();
      break;
    default:
      Msg::Error("Unknown type of element.");
      return 0;
  }
  B->parentType = parentType;

  // There is currently only 1 type of basis for any
  // element type, hence we use the element type as the
  // basis type.
  B->type = elementType;
  switch(elementType) {
    case MSH_PNT     : B->order = 0; B->serendip = false; break;
    case MSH_LIN_1   : B->order = 0; B->serendip = false; break;
    case MSH_LIN_2   : B->order = 1; B->serendip = false; break;
    case MSH_LIN_3   : B->order = 2; B->serendip = false; break;
    case MSH_LIN_4   : B->order = 3; B->serendip = false; break;
    case MSH_LIN_5   : B->order = 4; B->serendip = false; break;
    case MSH_LIN_6   : B->order = 5; B->serendip = false; break;
    case MSH_LIN_7   : B->order = 6; B->serendip = false; break;
    case MSH_LIN_8   : B->order = 7; B->serendip = false; break;
    case MSH_LIN_9   : B->order = 8; B->serendip = false; break;
    case MSH_LIN_10  : B->order = 9; B->serendip = false; break;
    case MSH_LIN_11  : B->order = 10;B->serendip = false; break;
    case MSH_TRI_1   : B->order = 0; B->serendip = false; break;
    case MSH_TRI_3   : B->order = 1; B->serendip = false; break;
    case MSH_TRI_6   : B->order = 2; B->serendip = false; break;
    case MSH_TRI_10  : B->order = 3; B->serendip = false; break;
    case MSH_TRI_15  : B->order = 4; B->serendip = false; break;
    case MSH_TRI_21  : B->order = 5; B->serendip = false; break;
    case MSH_TRI_28  : B->order = 6; B->serendip = false; break;
    case MSH_TRI_36  : B->order = 7; B->serendip = false; break;
    case MSH_TRI_45  : B->order = 8; B->serendip = false; break;
    case MSH_TRI_55  : B->order = 9; B->serendip = false; break;
    case MSH_TRI_66  : B->order = 10;B->serendip = false; break;
    case MSH_TRI_9   : B->order = 3; B->serendip = true;  break;
    case MSH_TRI_12  : B->order = 4; B->serendip = true;  break;
    case MSH_TRI_15I : B->order = 5; B->serendip = true;  break;
    case MSH_TRI_18  : B->order = 6; B->serendip = true;  break;
    case MSH_TRI_21I : B->order = 7; B->serendip = true;  break;
    case MSH_TRI_24  : B->order = 8; B->serendip = true;  break;
    case MSH_TRI_27  : B->order = 9; B->serendip = true;  break;
    case MSH_TRI_30  : B->order = 10;B->serendip = true;  break;
    case MSH_TET_1   : B->order = 0; B->serendip = false; break;
    case MSH_TET_4   : B->order = 1; B->serendip = false; break;
    case MSH_TET_10  : B->order = 2; B->serendip = false; break;
    case MSH_TET_20  : B->order = 3; B->serendip = false; break;
    case MSH_TET_35  : B->order = 4; B->serendip = false; break;
    case MSH_TET_56  : B->order = 5; B->serendip = false; break;
    case MSH_TET_84  : B->order = 6; B->serendip = false; break;
    case MSH_TET_120 : B->order = 7; B->serendip = false; break;
    case MSH_TET_165 : B->order = 8; B->serendip = false; break;
    case MSH_TET_220 : B->order = 9; B->serendip = false; break;
    case MSH_TET_286 : B->order = 10;B->serendip = false; break;
    case MSH_TET_34  : B->order = 4; B->serendip = true;  break;
    case MSH_TET_52  : B->order = 5; B->serendip = true;  break;
    case MSH_TET_74  : B->order = 6; B->serendip = true;  break;
    case MSH_TET_100 : B->order = 7; B->serendip = true;  break;
    case MSH_TET_130 : B->order = 8; B->serendip = true;  break;
    case MSH_TET_164 : B->order = 9; B->serendip = true;  break;
    case MSH_TET_202 : B->order = 10;B->serendip = true;  break;
    case MSH_QUA_1   : B->order = 0; B->serendip = false; break;
    case MSH_QUA_4   : B->order = 1; B->serendip = false; break;
    case MSH_QUA_9   : B->order = 2; B->serendip = false; break;
    case MSH_QUA_16  : B->order = 3; B->serendip = false; break;
    case MSH_QUA_25  : B->order = 4; B->serendip = false; break;
    case MSH_QUA_36  : B->order = 5; B->serendip = false; break;
    case MSH_QUA_49  : B->order = 6; B->serendip = false; break;
    case MSH_QUA_64  : B->order = 7; B->serendip = false; break;
    case MSH_QUA_81  : B->order = 8; B->serendip = false; break;
    case MSH_QUA_100 : B->order = 9; B->serendip = false; break;
    case MSH_QUA_121 : B->order = 10;B->serendip = false; break;
    case MSH_QUA_8   : B->order = 2; B->serendip = true;  break;
    case MSH_QUA_12  : B->order = 3; B->serendip = true;  break;
    case MSH_QUA_16I : B->order = 4; B->serendip = true;  break;
    case MSH_QUA_20  : B->order = 5; B->serendip = true;  break;
    case MSH_QUA_24  : B->order = 6; B->serendip = true;  break;
    case MSH_QUA_28  : B->order = 7; B->serendip = true;  break;
    case MSH_QUA_32  : B->order = 8; B->serendip = true;  break;
    case MSH_QUA_36I : B->order = 9; B->serendip = true;  break;
    case MSH_QUA_40  : B->order = 10;B->serendip = true;  break;
    case MSH_PRI_1   : B->order = 0; B->serendip = false; break;
    case MSH_PRI_6   : B->order = 1; B->serendip = false; break;
    case MSH_PRI_18  : B->order = 2; B->serendip = false; break;
    case MSH_HEX_8   : B->order = 1; B->serendip = false; break;
    case MSH_HEX_27  : B->order = 2; B->serendip = false; break;
    case MSH_HEX_64  : B->order = 3; B->serendip = false; break;
    case MSH_HEX_125 : B->order = 4; B->serendip = false; break;
    case MSH_HEX_216 : B->order = 5; B->serendip = false; break;
    case MSH_HEX_343 : B->order = 6; B->serendip = false; break;
    case MSH_HEX_512 : B->order = 7; B->serendip = false; break;
    case MSH_HEX_729 : B->order = 8; B->serendip = false; break;
    case MSH_HEX_1000: B->order = 9; B->serendip = false; break;
    case MSH_HEX_20  : B->order = 2; B->serendip = false; break;
    case MSH_HEX_56  : B->order = 3; B->serendip = true;  break;
    case MSH_HEX_98  : B->order = 4; B->serendip = true;  break;
    case MSH_HEX_152 : B->order = 5; B->serendip = true;  break;
    case MSH_HEX_222 : B->order = 6; B->serendip = true;  break;
    case MSH_HEX_296 : B->order = 7; B->serendip = true;  break;
    case MSH_HEX_386 : B->order = 8; B->serendip = true;  break;
    case MSH_HEX_488 : B->order = 9; B->serendip = true;  break;
    case MSH_PYR_1   : B->order = 0; B->serendip = false; break;
    case MSH_PYR_5   : B->order = 1; B->serendip = false; break;
    case MSH_PYR_14  : B->order = 2; B->serendip = false; break;
    case MSH_PYR_30  : B->order = 3; B->serendip = false; break;
    case MSH_PYR_55  : B->order = 4; B->serendip = false; break;
    case MSH_PYR_91  : B->order = 5; B->serendip = false; break;
    case MSH_PYR_140 : B->order = 6; B->serendip = false; break;
    case MSH_PYR_204 : B->order = 7; B->serendip = false; break;
    case MSH_PYR_285 : B->order = 8; B->serendip = false; break;
    case MSH_PYR_385 : B->order = 9; B->serendip = false; break;
    case MSH_PYR_29  : B->order = 3; B->serendip = true; break;
    case MSH_PYR_50  : B->order = 4; B->serendip = true; break;
    case MSH_PYR_77  : B->order = 5; B->serendip = true; break;
    case MSH_PYR_110 : B->order = 6; B->serendip = true; break;
    case MSH_PYR_149 : B->order = 7; B->serendip = true; break;
    case MSH_PYR_194 : B->order = 8; B->serendip = true; break;
    case MSH_PYR_245 : B->order = 9; B->serendip = true; break;    

    default :
      Msg::Error("Unknown function space %d: reverting to TET_4", elementType);
      B->parentType = TYPE_TET; B->order = 1; B->serendip = false; break;
  }

  // Here is where we do create the basis. 
  switch (B->parentType) {
  case TYPE_PNT :
    B->numFaces = 1;
    B->dimension = 0;
    B->points = gmshGeneratePointsLine(0);
    break;
  case TYPE_LIN :
    B->numFaces = 2;
    B->dimension = 1;
    B->points = gmshGeneratePointsLine(B->order);
    break;
  case TYPE_TRI :
    B->numFaces = 3;
    B->dimension = 2;
    B->points = gmshGeneratePointsTriangle(B->order, B->serendip);
    break;
  case TYPE_QUA :
    B->numFaces = 4;
    B->dimension = 2;
    B->points = gmshGeneratePointsQuadrangle(B->order, B->serendip);
    break;
  case TYPE_TET :
    B->numFaces = 4;
    B->dimension = 3;
    B->points = gmshGeneratePointsTetrahedron(B->order, B->serendip);
    break;
  case TYPE_PRI :
    B->numFaces = 5;
    B->dimension = 3;
    B->points = gmshGeneratePointsPrism(B->order, B->serendip);
    break;
  case TYPE_HEX :
    B->numFaces = 6;
    B->dimension = 3;
    B->points = gmshGeneratePointsHexahedron(B->order, B->serendip);
    break;
  case TYPE_PYR :
    B->numFaces = 5;
    B->dimension = 3;
    B->points = gmshGeneratePointsPyramid(B->order, B->serendip);
    break;
  default:
    Msg::Error("Unknown element type!\n");
  }

  B->initialize();

  fs.insert(std::make_pair(elementType, B));

  return fs[elementType];

}
