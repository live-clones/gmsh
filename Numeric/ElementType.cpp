// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "ElementType.h"
#include "GmshDefines.h"
#include "GmshMessage.h"

int ElementType::getParentType(int mshtype)
{
  switch(mshtype) {
  case(MSH_PNT): return TYPE_PNT;
  case(MSH_LIN_2):
  case(MSH_LIN_3):
  case(MSH_LIN_4):
  case(MSH_LIN_5):
  case(MSH_LIN_6):
  case(MSH_LIN_7):
  case(MSH_LIN_8):
  case(MSH_LIN_9):
  case(MSH_LIN_10):
  case(MSH_LIN_11):
  case(MSH_LIN_B):
  case(MSH_LIN_C):
  case(MSH_LIN_1): return TYPE_LIN;
  case(MSH_TRI_3):
  case(MSH_TRI_6):
  case(MSH_TRI_9):
  case(MSH_TRI_10):
  case(MSH_TRI_12):
  case(MSH_TRI_15):
  case(MSH_TRI_15I):
  case(MSH_TRI_21):
  case(MSH_TRI_28):
  case(MSH_TRI_36):
  case(MSH_TRI_45):
  case(MSH_TRI_55):
  case(MSH_TRI_66):
  case(MSH_TRI_18):
  case(MSH_TRI_21I):
  case(MSH_TRI_24):
  case(MSH_TRI_27):
  case(MSH_TRI_30):
  case(MSH_TRI_B):
  case(MSH_TRI_1): return TYPE_TRI;
  case(MSH_QUA_4):
  case(MSH_QUA_9):
  case(MSH_QUA_8):
  case(MSH_QUA_16):
  case(MSH_QUA_25):
  case(MSH_QUA_36):
  case(MSH_QUA_12):
  case(MSH_QUA_16I):
  case(MSH_QUA_20):
  case(MSH_QUA_49):
  case(MSH_QUA_64):
  case(MSH_QUA_81):
  case(MSH_QUA_100):
  case(MSH_QUA_121):
  case(MSH_QUA_24):
  case(MSH_QUA_28):
  case(MSH_QUA_32):
  case(MSH_QUA_36I):
  case(MSH_QUA_40):
  case(MSH_QUA_1): return TYPE_QUA;
  case(MSH_TET_4):
  case(MSH_TET_10):
  case(MSH_TET_20):
  case(MSH_TET_35):
  case(MSH_TET_56):
  case(MSH_TET_22):
  case(MSH_TET_28):
  case(MSH_TET_84):
  case(MSH_TET_120):
  case(MSH_TET_165):
  case(MSH_TET_220):
  case(MSH_TET_286):
  case(MSH_TET_34):
  case(MSH_TET_40):
  case(MSH_TET_46):
  case(MSH_TET_52):
  case(MSH_TET_58):
  case(MSH_TET_1):
  case(MSH_TET_16): return TYPE_TET;
  case(MSH_PYR_5):
  case(MSH_PYR_14):
  case(MSH_PYR_13):
  case(MSH_PYR_30):
  case(MSH_PYR_55):
  case(MSH_PYR_91):
  case(MSH_PYR_140):
  case(MSH_PYR_204):
  case(MSH_PYR_285):
  case(MSH_PYR_385):
  case(MSH_PYR_21):
  case(MSH_PYR_29):
  case(MSH_PYR_37):
  case(MSH_PYR_45):
  case(MSH_PYR_53):
  case(MSH_PYR_61):
  case(MSH_PYR_69):
  case(MSH_PYR_1): return TYPE_PYR;
  case(MSH_PRI_6):
  case(MSH_PRI_18):
  case(MSH_PRI_15):
  case(MSH_PRI_1):
  case(MSH_PRI_40):
  case(MSH_PRI_75):
  case(MSH_PRI_126):
  case(MSH_PRI_196):
  case(MSH_PRI_288):
  case(MSH_PRI_405):
  case(MSH_PRI_550):
  case(MSH_PRI_24):
  case(MSH_PRI_33):
  case(MSH_PRI_42):
  case(MSH_PRI_51):
  case(MSH_PRI_60):
  case(MSH_PRI_69):
  case(MSH_PRI_78): return TYPE_PRI;
  case(MSH_HEX_8):
  case(MSH_HEX_27):
  case(MSH_HEX_20):
  case(MSH_HEX_1):
  case(MSH_HEX_64):
  case(MSH_HEX_125):
  case(MSH_HEX_216):
  case(MSH_HEX_343):
  case(MSH_HEX_512):
  case(MSH_HEX_729):
  case(MSH_HEX_1000):
  case(MSH_HEX_32):
  case(MSH_HEX_44):
  case(MSH_HEX_56):
  case(MSH_HEX_68):
  case(MSH_HEX_80):
  case(MSH_HEX_92):
  case(MSH_HEX_104): return TYPE_HEX;
  case(MSH_POLYG_):
  case(MSH_POLYG_B): return TYPE_POLYG;
  case(MSH_POLYH_): return TYPE_POLYH;
  case(MSH_PNT_SUB):
  case(MSH_LIN_SUB):
  case(MSH_TRI_SUB):
  case(MSH_TET_SUB): return TYPE_XFEM;
  case(MSH_TRI_MINI):
  case(MSH_TET_MINI): return TYPE_MINI;
  case(MSH_TRIH_4): return TYPE_TRIH;

  default:
    Msg::Error("Unknown element MSH type %i for parent type, returning -1.",
               mshtype);
    return -1;
  }
}

int ElementType::getOrder(int mshtype)
{
  switch(mshtype) {
  case MSH_PNT: return 0;
  case MSH_LIN_1: return 0;
  case MSH_LIN_2: return 1;
  case MSH_LIN_3: return 2;
  case MSH_LIN_4: return 3;
  case MSH_LIN_5: return 4;
  case MSH_LIN_6: return 5;
  case MSH_LIN_7: return 6;
  case MSH_LIN_8: return 7;
  case MSH_LIN_9: return 8;
  case MSH_LIN_10: return 9;
  case MSH_LIN_11: return 10;
  case MSH_TRI_1: return 0;
  case MSH_TRI_3: return 1;
  case MSH_TRI_6: return 2;
  case MSH_TRI_10: return 3;
  case MSH_TRI_15: return 4;
  case MSH_TRI_21: return 5;
  case MSH_TRI_28: return 6;
  case MSH_TRI_36: return 7;
  case MSH_TRI_45: return 8;
  case MSH_TRI_55: return 9;
  case MSH_TRI_66: return 10;
  case MSH_TRI_9: return 3;
  case MSH_TRI_12: return 4;
  case MSH_TRI_15I: return 5;
  case MSH_TRI_18: return 6;
  case MSH_TRI_21I: return 7;
  case MSH_TRI_24: return 8;
  case MSH_TRI_27: return 9;
  case MSH_TRI_30: return 10;
  case MSH_TRI_MINI: return 1;
  case MSH_POLYG_: return 1;
  case MSH_POLYG_B: return 1;
  case MSH_TET_1: return 0;
  case MSH_TET_4: return 1;
  case MSH_TET_10: return 2;
  case MSH_TET_20: return 3;
  case MSH_TET_35: return 4;
  case MSH_TET_56: return 5;
  case MSH_TET_84: return 6;
  case MSH_TET_120: return 7;
  case MSH_TET_165: return 8;
  case MSH_TET_220: return 9;
  case MSH_TET_286: return 10;
  case MSH_TET_16: return 3;
  case MSH_TET_22: return 4;
  case MSH_TET_28: return 5;
  case MSH_TET_34: return 6;
  case MSH_TET_40: return 7;
  case MSH_TET_46: return 8;
  case MSH_TET_52: return 9;
  case MSH_TET_58: return 10;
  case MSH_TET_MINI: return 1;
  case MSH_QUA_1: return 0;
  case MSH_QUA_4: return 1;
  case MSH_QUA_9: return 2;
  case MSH_QUA_16: return 3;
  case MSH_QUA_25: return 4;
  case MSH_QUA_36: return 5;
  case MSH_QUA_49: return 6;
  case MSH_QUA_64: return 7;
  case MSH_QUA_81: return 8;
  case MSH_QUA_100: return 9;
  case MSH_QUA_121: return 10;
  case MSH_QUA_8: return 2;
  case MSH_QUA_12: return 3;
  case MSH_QUA_16I: return 4;
  case MSH_QUA_20: return 5;
  case MSH_QUA_24: return 6;
  case MSH_QUA_28: return 7;
  case MSH_QUA_32: return 8;
  case MSH_QUA_36I: return 9;
  case MSH_QUA_40: return 10;
  case MSH_PRI_1: return 0;
  case MSH_PRI_6: return 1;
  case MSH_PRI_18: return 2;
  case MSH_PRI_40: return 3;
  case MSH_PRI_75: return 4;
  case MSH_PRI_126: return 5;
  case MSH_PRI_196: return 6;
  case MSH_PRI_288: return 7;
  case MSH_PRI_405: return 8;
  case MSH_PRI_550: return 9;
  case MSH_PRI_15: return 2;
  case MSH_PRI_24: return 3;
  case MSH_PRI_33: return 4;
  case MSH_PRI_42: return 5;
  case MSH_PRI_51: return 6;
  case MSH_PRI_60: return 7;
  case MSH_PRI_69: return 8;
  case MSH_PRI_78: return 9;
  case MSH_HEX_1: return 0;
  case MSH_HEX_8: return 1;
  case MSH_HEX_27: return 2;
  case MSH_HEX_64: return 3;
  case MSH_HEX_125: return 4;
  case MSH_HEX_216: return 5;
  case MSH_HEX_343: return 6;
  case MSH_HEX_512: return 7;
  case MSH_HEX_729: return 8;
  case MSH_HEX_1000: return 9;
  case MSH_HEX_20: return 2;
  case MSH_HEX_32: return 3;
  case MSH_HEX_44: return 4;
  case MSH_HEX_56: return 5;
  case MSH_HEX_68: return 6;
  case MSH_HEX_80: return 7;
  case MSH_HEX_92: return 8;
  case MSH_HEX_104: return 9;
  case MSH_PYR_1: return 0;
  case MSH_PYR_5: return 1;
  case MSH_PYR_14: return 2;
  case MSH_PYR_30: return 3;
  case MSH_PYR_55: return 4;
  case MSH_PYR_91: return 5;
  case MSH_PYR_140: return 6;
  case MSH_PYR_204: return 7;
  case MSH_PYR_285: return 8;
  case MSH_PYR_385: return 9;
  case MSH_PYR_13: return 2;
  case MSH_PYR_21: return 3;
  case MSH_PYR_29: return 4;
  case MSH_PYR_37: return 5;
  case MSH_PYR_45: return 6;
  case MSH_PYR_53: return 7;
  case MSH_PYR_61: return 8;
  case MSH_PYR_69: return 9;
  case MSH_TRIH_4: return 1;
  case MSH_POLYH_: return 1;
  default:
    Msg::Warning("Unknown element MSH type %d, assuming order 1.", mshtype);
    return 1;
  }
}

int ElementType::getDimension(int mshtype)
{
  switch(mshtype) {
  case(MSH_PNT):
  case(MSH_PNT_SUB): return 0;

  case(MSH_LIN_2):
  case(MSH_LIN_3):
  case(MSH_LIN_4):
  case(MSH_LIN_5):
  case(MSH_LIN_6):
  case(MSH_LIN_7):
  case(MSH_LIN_8):
  case(MSH_LIN_9):
  case(MSH_LIN_10):
  case(MSH_LIN_11):
  case(MSH_LIN_B):
  case(MSH_LIN_C):
  case(MSH_LIN_1):
  case(MSH_LIN_SUB): return 1;

  case(MSH_TRI_3):
  case(MSH_TRI_6):
  case(MSH_TRI_9):
  case(MSH_TRI_10):
  case(MSH_TRI_12):
  case(MSH_TRI_15):
  case(MSH_TRI_15I):
  case(MSH_TRI_21):
  case(MSH_TRI_28):
  case(MSH_TRI_36):
  case(MSH_TRI_45):
  case(MSH_TRI_55):
  case(MSH_TRI_66):
  case(MSH_TRI_18):
  case(MSH_TRI_21I):
  case(MSH_TRI_24):
  case(MSH_TRI_27):
  case(MSH_TRI_30):
  case(MSH_TRI_B):
  case(MSH_TRI_1):
  case(MSH_TRI_SUB):
  case(MSH_TRI_MINI):

  case(MSH_QUA_4):
  case(MSH_QUA_9):
  case(MSH_QUA_8):
  case(MSH_QUA_16):
  case(MSH_QUA_25):
  case(MSH_QUA_36):
  case(MSH_QUA_12):
  case(MSH_QUA_16I):
  case(MSH_QUA_20):
  case(MSH_QUA_49):
  case(MSH_QUA_64):
  case(MSH_QUA_81):
  case(MSH_QUA_100):
  case(MSH_QUA_121):
  case(MSH_QUA_24):
  case(MSH_QUA_28):
  case(MSH_QUA_32):
  case(MSH_QUA_36I):
  case(MSH_QUA_40):
  case(MSH_QUA_1):

  case(MSH_POLYG_):
  case(MSH_POLYG_B): return 2;

  case(MSH_TET_4):
  case(MSH_TET_10):
  case(MSH_TET_20):
  case(MSH_TET_35):
  case(MSH_TET_56):
  case(MSH_TET_22):
  case(MSH_TET_28):
  case(MSH_TET_84):
  case(MSH_TET_120):
  case(MSH_TET_165):
  case(MSH_TET_220):
  case(MSH_TET_286):
  case(MSH_TET_34):
  case(MSH_TET_40):
  case(MSH_TET_46):
  case(MSH_TET_52):
  case(MSH_TET_58):
  case(MSH_TET_1):
  case(MSH_TET_16):
  case(MSH_TET_SUB):
  case(MSH_TET_MINI):

  case(MSH_PYR_5):
  case(MSH_PYR_14):
  case(MSH_PYR_13):
  case(MSH_PYR_30):
  case(MSH_PYR_55):
  case(MSH_PYR_91):
  case(MSH_PYR_140):
  case(MSH_PYR_204):
  case(MSH_PYR_285):
  case(MSH_PYR_385):
  case(MSH_PYR_21):
  case(MSH_PYR_29):
  case(MSH_PYR_37):
  case(MSH_PYR_45):
  case(MSH_PYR_53):
  case(MSH_PYR_61):
  case(MSH_PYR_69):
  case(MSH_PYR_1):

  case(MSH_PRI_6):
  case(MSH_PRI_18):
  case(MSH_PRI_15):
  case(MSH_PRI_1):
  case(MSH_PRI_40):
  case(MSH_PRI_75):
  case(MSH_PRI_126):
  case(MSH_PRI_196):
  case(MSH_PRI_288):
  case(MSH_PRI_405):
  case(MSH_PRI_550):
  case(MSH_PRI_24):
  case(MSH_PRI_33):
  case(MSH_PRI_42):
  case(MSH_PRI_51):
  case(MSH_PRI_60):
  case(MSH_PRI_69):
  case(MSH_PRI_78):

  case(MSH_HEX_8):
  case(MSH_HEX_27):
  case(MSH_HEX_20):
  case(MSH_HEX_1):
  case(MSH_HEX_64):
  case(MSH_HEX_125):
  case(MSH_HEX_216):
  case(MSH_HEX_343):
  case(MSH_HEX_512):
  case(MSH_HEX_729):
  case(MSH_HEX_1000):
  case(MSH_HEX_32):
  case(MSH_HEX_44):
  case(MSH_HEX_56):
  case(MSH_HEX_68):
  case(MSH_HEX_80):
  case(MSH_HEX_92):
  case(MSH_HEX_104):

  case(MSH_TRIH_4):

  case(MSH_POLYH_): return 3;

  default:
    Msg::Error("Unknown element MSH type %i for dimension, returning -1.",
               mshtype);
    return -1;
  }
}

// Give the number of node corresponding to a msh type.
int ElementType::getNumVertices(int mshtype)
{
  switch(mshtype) {
  case MSH_PNT: return 1;
  case MSH_LIN_1: return 1;
  case MSH_LIN_2: return 2;
  case MSH_LIN_3: return 3;
  case MSH_LIN_4: return 4;
  case MSH_LIN_5: return 5;
  case MSH_LIN_6: return 6;
  case MSH_LIN_7: return 7;
  case MSH_LIN_8: return 8;
  case MSH_LIN_9: return 9;
  case MSH_LIN_10: return 10;
  case MSH_LIN_11: return 11;
  case MSH_TRI_1: return 1;
  case MSH_TRI_3: return 3;
  case MSH_TRI_6: return 6;
  case MSH_TRI_10: return 10;
  case MSH_TRI_15: return 15;
  case MSH_TRI_21: return 21;
  case MSH_TRI_28: return 28;
  case MSH_TRI_36: return 36;
  case MSH_TRI_45: return 45;
  case MSH_TRI_55: return 55;
  case MSH_TRI_66: return 66;
  case MSH_TRI_9: return 9;
  case MSH_TRI_12: return 12;
  case MSH_TRI_15I: return 15;
  case MSH_TRI_18: return 18;
  case MSH_TRI_21I: return 21;
  case MSH_TRI_24: return 24;
  case MSH_TRI_27: return 27;
  case MSH_TRI_30: return 30;
  // case MSH_TRI_MINI  : return 0;
  // case MSH_POLYG_  : return 0;
  // case MSH_POLYG_B : return 0;
  case MSH_TET_1: return 1;
  case MSH_TET_4: return 4;
  case MSH_TET_10: return 10;
  case MSH_TET_20: return 20;
  case MSH_TET_35: return 35;
  case MSH_TET_56: return 56;
  case MSH_TET_84: return 84;
  case MSH_TET_120: return 120;
  case MSH_TET_165: return 165;
  case MSH_TET_220: return 220;
  case MSH_TET_286: return 286;
  case MSH_TET_16: return 16;
  case MSH_TET_22: return 22;
  case MSH_TET_28: return 28;
  case MSH_TET_34: return 34;
  case MSH_TET_40: return 40;
  case MSH_TET_46: return 46;
  case MSH_TET_52: return 52;
  case MSH_TET_58: return 58;
  // case MSH_TET_MINI  : return 0;
  case MSH_QUA_1: return 1;
  case MSH_QUA_4: return 4;
  case MSH_QUA_9: return 9;
  case MSH_QUA_16: return 16;
  case MSH_QUA_25: return 25;
  case MSH_QUA_36: return 36;
  case MSH_QUA_49: return 49;
  case MSH_QUA_64: return 64;
  case MSH_QUA_81: return 81;
  case MSH_QUA_100: return 100;
  case MSH_QUA_121: return 121;
  case MSH_QUA_8: return 8;
  case MSH_QUA_12: return 12;
  case MSH_QUA_16I: return 16;
  case MSH_QUA_20: return 20;
  case MSH_QUA_24: return 24;
  case MSH_QUA_28: return 28;
  case MSH_QUA_32: return 32;
  case MSH_QUA_36I: return 36;
  case MSH_QUA_40: return 40;
  case MSH_PRI_1: return 1;
  case MSH_PRI_6: return 6;
  case MSH_PRI_18: return 18;
  case MSH_PRI_40: return 40;
  case MSH_PRI_75: return 75;
  case MSH_PRI_126: return 126;
  case MSH_PRI_196: return 196;
  case MSH_PRI_288: return 288;
  case MSH_PRI_405: return 405;
  case MSH_PRI_550: return 550;
  case MSH_PRI_15: return 15;
  case MSH_PRI_24: return 24;
  case MSH_PRI_33: return 33;
  case MSH_PRI_42: return 42;
  case MSH_PRI_51: return 51;
  case MSH_PRI_60: return 60;
  case MSH_PRI_69: return 69;
  case MSH_PRI_78: return 78;
  case MSH_HEX_1: return 1;
  case MSH_HEX_8: return 8;
  case MSH_HEX_27: return 27;
  case MSH_HEX_64: return 64;
  case MSH_HEX_125: return 125;
  case MSH_HEX_216: return 216;
  case MSH_HEX_343: return 343;
  case MSH_HEX_512: return 512;
  case MSH_HEX_729: return 729;
  case MSH_HEX_1000: return 1000;
  case MSH_HEX_20: return 20;
  case MSH_HEX_32: return 32;
  case MSH_HEX_44: return 44;
  case MSH_HEX_56: return 56;
  case MSH_HEX_68: return 68;
  case MSH_HEX_80: return 80;
  case MSH_HEX_92: return 92;
  case MSH_HEX_104: return 104;
  case MSH_PYR_1: return 1;
  case MSH_PYR_5: return 5;
  case MSH_PYR_14: return 14;
  case MSH_PYR_30: return 30;
  case MSH_PYR_55: return 55;
  case MSH_PYR_91: return 91;
  case MSH_PYR_140: return 140;
  case MSH_PYR_204: return 204;
  case MSH_PYR_285: return 285;
  case MSH_PYR_385: return 385;
  case MSH_PYR_13: return 13;
  case MSH_PYR_21: return 21;
  case MSH_PYR_29: return 29;
  case MSH_PYR_37: return 37;
  case MSH_PYR_45: return 45;
  case MSH_PYR_53: return 53;
  case MSH_PYR_61: return 61;
  case MSH_PYR_69: return 69;
  case MSH_TRIH_4: return 4;
  // case MSH_POLYH_ : return 0;
  default: Msg::Warning("Unknown element MSH type %d", mshtype); return 0;
  }

  return 0;
}

// Gives > 0 if element tag is in Serendipity Family.
// Gives < 2 if element tag is in 'Normal' Family.
// 1 is for element that is either Serendipity or not !
int ElementType::getSerendipity(int mshtype)
{
  switch(mshtype) {
  case MSH_PNT:
  case MSH_LIN_1:
  case MSH_LIN_2:
  case MSH_LIN_3:
  case MSH_LIN_4:
  case MSH_LIN_5:
  case MSH_LIN_6:
  case MSH_LIN_7:
  case MSH_LIN_8:
  case MSH_LIN_9:
  case MSH_LIN_10:
  case MSH_LIN_11:

  case MSH_TRI_1:
  case MSH_TRI_3:
  case MSH_TRI_6:

  case MSH_QUA_1:
  case MSH_QUA_4:

  case MSH_TET_1:
  case MSH_TET_4:
  case MSH_TET_10:

  case MSH_PRI_1:
  case MSH_PRI_6:

  case MSH_HEX_1:
  case MSH_HEX_8:

  case MSH_PYR_1:
  case MSH_PYR_5:

  case MSH_POLYG_:
  case MSH_POLYG_B:
  case MSH_POLYH_: return 1; // Serendipity or not

  case MSH_TRI_10:
  case MSH_TRI_15:
  case MSH_TRI_21:
  case MSH_TRI_28:
  case MSH_TRI_36:
  case MSH_TRI_45:
  case MSH_TRI_55:
  case MSH_TRI_66:

  case MSH_QUA_9:
  case MSH_QUA_16:
  case MSH_QUA_25:
  case MSH_QUA_36:
  case MSH_QUA_49:
  case MSH_QUA_64:
  case MSH_QUA_81:
  case MSH_QUA_100:
  case MSH_QUA_121:

  case MSH_TET_20:
  case MSH_TET_35:
  case MSH_TET_56:
  case MSH_TET_84:
  case MSH_TET_120:
  case MSH_TET_165:
  case MSH_TET_220:
  case MSH_TET_286:

  case MSH_PRI_18:
  case MSH_PRI_40:
  case MSH_PRI_75:
  case MSH_PRI_126:
  case MSH_PRI_196:
  case MSH_PRI_288:
  case MSH_PRI_405:
  case MSH_PRI_550:

  case MSH_HEX_27:
  case MSH_HEX_64:
  case MSH_HEX_125:
  case MSH_HEX_216:
  case MSH_HEX_343:
  case MSH_HEX_512:
  case MSH_HEX_729:
  case MSH_HEX_1000:

  case MSH_PYR_14:
  case MSH_PYR_30:
  case MSH_PYR_55:
  case MSH_PYR_91:
  case MSH_PYR_140:
  case MSH_PYR_204:
  case MSH_PYR_285:
  case MSH_PYR_385:

  case MSH_TRIH_4: return 0; // Not Serendipity

  case MSH_TRI_9:
  case MSH_TRI_12:
  case MSH_TRI_15I:
  case MSH_TRI_18:
  case MSH_TRI_21I:
  case MSH_TRI_24:
  case MSH_TRI_27:
  case MSH_TRI_30:

  case MSH_QUA_8:
  case MSH_QUA_12:
  case MSH_QUA_16I:
  case MSH_QUA_20:
  case MSH_QUA_24:
  case MSH_QUA_28:
  case MSH_QUA_32:
  case MSH_QUA_36I:
  case MSH_QUA_40:

  case MSH_TET_22:
  case MSH_TET_28:
  case MSH_TET_34:
  case MSH_TET_40:
  case MSH_TET_46:
  case MSH_TET_52:
  case MSH_TET_58:
  case MSH_TET_16:

  case MSH_PRI_15:
  case MSH_PRI_24:
  case MSH_PRI_33:
  case MSH_PRI_42:
  case MSH_PRI_51:
  case MSH_PRI_60:
  case MSH_PRI_69:
  case MSH_PRI_78:

  case MSH_HEX_20:
  case MSH_HEX_32:
  case MSH_HEX_44:
  case MSH_HEX_56:
  case MSH_HEX_68:
  case MSH_HEX_80:
  case MSH_HEX_92:
  case MSH_HEX_104:

  case MSH_PYR_13:
  case MSH_PYR_21:
  case MSH_PYR_29:
  case MSH_PYR_37:
  case MSH_PYR_45:
  case MSH_PYR_53:
  case MSH_PYR_61:
  case MSH_PYR_69: return 2; // Only Serendipity

  default:
    Msg::Warning("Unknown element MSH type %d, assuming not serendipity.",
                 mshtype);
    return 0;
  }
}

int ElementType::getType(int parentType, int order, bool serendip)
{
  switch(parentType) {
  case TYPE_PNT: return MSH_PNT;
  case TYPE_LIN:
    switch(order) {
    case 0: return MSH_LIN_1;
    case 1: return MSH_LIN_2;
    case 2: return MSH_LIN_3;
    case 3: return MSH_LIN_4;
    case 4: return MSH_LIN_5;
    case 5: return MSH_LIN_6;
    case 6: return MSH_LIN_7;
    case 7: return MSH_LIN_8;
    case 8: return MSH_LIN_9;
    case 9: return MSH_LIN_10;
    case 10: return MSH_LIN_11;
    default: Msg::Error("Line order %i unknown", order); return 0;
    }
    break;
  case TYPE_TRI:
    switch(order) {
    case 0: return MSH_TRI_1;
    case 1: return MSH_TRI_3;
    case 2: return MSH_TRI_6;
    case 3: return serendip ? MSH_TRI_9 : MSH_TRI_10;
    case 4: return serendip ? MSH_TRI_12 : MSH_TRI_15;
    case 5: return serendip ? MSH_TRI_15I : MSH_TRI_21;
    case 6: return serendip ? MSH_TRI_18 : MSH_TRI_28;
    case 7: return serendip ? MSH_TRI_21I : MSH_TRI_36;
    case 8: return serendip ? MSH_TRI_24 : MSH_TRI_45;
    case 9: return serendip ? MSH_TRI_27 : MSH_TRI_55;
    case 10: return serendip ? MSH_TRI_30 : MSH_TRI_66;
    default: Msg::Error("Triangle order %i unknown", order); return 0;
    }
    break;
  case TYPE_QUA:
    switch(order) {
    case 0: return MSH_QUA_1;
    case 1: return MSH_QUA_4;
    case 2: return serendip ? MSH_QUA_8 : MSH_QUA_9;
    case 3: return serendip ? MSH_QUA_12 : MSH_QUA_16;
    case 4: return serendip ? MSH_QUA_16I : MSH_QUA_25;
    case 5: return serendip ? MSH_QUA_20 : MSH_QUA_36;
    case 6: return serendip ? MSH_QUA_24 : MSH_QUA_49;
    case 7: return serendip ? MSH_QUA_28 : MSH_QUA_64;
    case 8: return serendip ? MSH_QUA_32 : MSH_QUA_81;
    case 9: return serendip ? MSH_QUA_36I : MSH_QUA_100;
    case 10: return serendip ? MSH_QUA_40 : MSH_QUA_121;
    default: Msg::Error("Quad order %i unknown", order); return 0;
    }
    break;
  case TYPE_TET:
    switch(order) {
    case 0: return MSH_TET_1;
    case 1: return MSH_TET_4;
    case 2: return MSH_TET_10;
    case 3: return serendip ? MSH_TET_16 : MSH_TET_20;
    case 4: return serendip ? MSH_TET_22 : MSH_TET_35;
    case 5: return serendip ? MSH_TET_28 : MSH_TET_56;
    case 6: return serendip ? MSH_TET_34 : MSH_TET_84;
    case 7: return serendip ? MSH_TET_40 : MSH_TET_120;
    case 8: return serendip ? MSH_TET_46 : MSH_TET_165;
    case 9: return serendip ? MSH_TET_52 : MSH_TET_220;
    case 10: return serendip ? MSH_TET_58 : MSH_TET_286;
    default: Msg::Error("Tetrahedron order %i unknown", order); return 0;
    }
    break;
  case TYPE_HEX:
    switch(order) {
    case 0: return MSH_HEX_1;
    case 1: return MSH_HEX_8;
    case 2: return serendip ? MSH_HEX_20 : MSH_HEX_27;
    case 3: return serendip ? MSH_HEX_32 : MSH_HEX_64;
    case 4: return serendip ? MSH_HEX_44 : MSH_HEX_125;
    case 5: return serendip ? MSH_HEX_56 : MSH_HEX_216;
    case 6: return serendip ? MSH_HEX_68 : MSH_HEX_343;
    case 7: return serendip ? MSH_HEX_80 : MSH_HEX_512;
    case 8: return serendip ? MSH_HEX_92 : MSH_HEX_729;
    case 9: return serendip ? MSH_HEX_104 : MSH_HEX_1000;
    default: Msg::Error("hexahedron order %i unknown", order); return 0;
    }
    break;
  case TYPE_PRI:
    switch(order) {
    case 0: return MSH_PRI_1;
    case 1: return MSH_PRI_6;
    case 2: return serendip ? MSH_PRI_15 : MSH_PRI_18;
    case 3: return serendip ? MSH_PRI_24 : MSH_PRI_40;
    case 4: return serendip ? MSH_PRI_33 : MSH_PRI_75;
    case 5: return serendip ? MSH_PRI_42 : MSH_PRI_126;
    case 6: return serendip ? MSH_PRI_51 : MSH_PRI_196;
    case 7: return serendip ? MSH_PRI_60 : MSH_PRI_288;
    case 8: return serendip ? MSH_PRI_69 : MSH_PRI_405;
    case 9: return serendip ? MSH_PRI_78 : MSH_PRI_550;
    default: Msg::Error("Prism order %i unknown", order); return 0;
    }
    break;
  case TYPE_PYR:
    switch(order) {
    case 0: return MSH_PYR_1;
    case 1: return MSH_PYR_5;
    case 2: return serendip ? MSH_PYR_13 : MSH_PYR_14;
    case 3: return serendip ? MSH_PYR_21 : MSH_PYR_30;
    case 4: return serendip ? MSH_PYR_29 : MSH_PYR_55;
    case 5: return serendip ? MSH_PYR_37 : MSH_PYR_91;
    case 6: return serendip ? MSH_PYR_45 : MSH_PYR_140;
    case 7: return serendip ? MSH_PYR_53 : MSH_PYR_204;
    case 8: return serendip ? MSH_PYR_61 : MSH_PYR_285;
    case 9: return serendip ? MSH_PYR_69 : MSH_PYR_385;
    default: Msg::Error("Pyramid order %i unknown", order); return 0;
    }
    break;
  case TYPE_TRIH: return MSH_TRIH_4;
  default:
    Msg::Warning("Unknown element parent type %i, returning 0", parentType);
    return 0;
  }
}

int ElementType::getPrimaryType(int mshtype)
{
  return getType(getParentType(mshtype), 1);
}

std::string ElementType::nameOfParentType(int parentType, bool plural)
{
  switch(parentType) {
  case TYPE_PNT: return plural ? "points" : "point";
  case TYPE_LIN: return plural ? "lines" : "line";
  case TYPE_TRI: return plural ? "triangles" : "triangle";
  case TYPE_QUA: return plural ? "quadrangles" : "quadrangle";
  case TYPE_TET: return plural ? "tetrahedra" : "tetrahedron";
  case TYPE_PYR: return plural ? "pyramids" : "pyramid";
  case TYPE_PRI: return plural ? "prisms" : "prism";
  case TYPE_HEX: return plural ? "hexahedra" : "hexahedron";
  case TYPE_POLYG: return plural ? "polygons" : "polygon";
  case TYPE_POLYH: return plural ? "polyhedra" : "polyhedron";
  case TYPE_XFEM: return "xfem";
  case TYPE_MINI: return "mini";
  case TYPE_TRIH: return plural ? "trihedra" : "trihedron";
  default: return "undefined";
  }
}
