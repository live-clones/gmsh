// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "ElementType.h"
#include "GmshDefines.h"
#include "GmshMessage.h"

int ElementType::ParentTypeFromTag(int tag)
{
  switch(tag) {
    case(MSH_PNT):
      return TYPE_PNT;
    case(MSH_LIN_2):    case(MSH_LIN_3):
    case(MSH_LIN_4):    case(MSH_LIN_5):
    case(MSH_LIN_6):    case(MSH_LIN_7):
    case(MSH_LIN_8):    case(MSH_LIN_9):
    case(MSH_LIN_10):   case(MSH_LIN_11):
    case(MSH_LIN_B):    case(MSH_LIN_C):
    case(MSH_LIN_1):
      return TYPE_LIN;
    case(MSH_TRI_3):    case(MSH_TRI_6):
    case(MSH_TRI_9):    case(MSH_TRI_10):
    case(MSH_TRI_12):   case(MSH_TRI_15):
    case(MSH_TRI_15I):  case(MSH_TRI_21):
    case(MSH_TRI_28):   case(MSH_TRI_36):
    case(MSH_TRI_45):   case(MSH_TRI_55):
    case(MSH_TRI_66):   case(MSH_TRI_18):
    case(MSH_TRI_21I):  case(MSH_TRI_24):
    case(MSH_TRI_27):   case(MSH_TRI_30):
    case(MSH_TRI_B):    case(MSH_TRI_1):
      return TYPE_TRI;
    case(MSH_QUA_4):    case(MSH_QUA_9):
    case(MSH_QUA_8):    case(MSH_QUA_16):
    case(MSH_QUA_25):   case(MSH_QUA_36):
    case(MSH_QUA_12):   case(MSH_QUA_16I):
    case(MSH_QUA_20):   case(MSH_QUA_49):
    case(MSH_QUA_64):   case(MSH_QUA_81):
    case(MSH_QUA_100):  case(MSH_QUA_121):
    case(MSH_QUA_24):   case(MSH_QUA_28):
    case(MSH_QUA_32):   case(MSH_QUA_36I):
    case(MSH_QUA_40):   case(MSH_QUA_1):
      return TYPE_QUA;
    case(MSH_TET_4):    case(MSH_TET_10):
    case(MSH_TET_20):   case(MSH_TET_35):
    case(MSH_TET_56):   case(MSH_TET_22):
    case(MSH_TET_28):   case(MSH_TET_84):
    case(MSH_TET_120):  case(MSH_TET_165):
    case(MSH_TET_220):  case(MSH_TET_286):
    case(MSH_TET_34):   case(MSH_TET_40):
    case(MSH_TET_46):   case(MSH_TET_52):
    case(MSH_TET_58):   case(MSH_TET_1):
    case(MSH_TET_16):
      return TYPE_TET;
    case(MSH_PYR_5):    case(MSH_PYR_14):
    case(MSH_PYR_13):   case(MSH_PYR_30):
    case(MSH_PYR_55):   case(MSH_PYR_91):
    case(MSH_PYR_140):  case(MSH_PYR_204):
    case(MSH_PYR_285):  case(MSH_PYR_385):
    case(MSH_PYR_21):   case(MSH_PYR_29):
    case(MSH_PYR_37):   case(MSH_PYR_45):
    case(MSH_PYR_53):   case(MSH_PYR_61):
    case(MSH_PYR_69):   case(MSH_PYR_1):
      return TYPE_PYR;
    case(MSH_PRI_6):    case(MSH_PRI_18):
    case(MSH_PRI_15):   case(MSH_PRI_1):
    case(MSH_PRI_40):   case(MSH_PRI_75):
    case(MSH_PRI_126):  case(MSH_PRI_196):
    case(MSH_PRI_288):  case(MSH_PRI_405):
    case(MSH_PRI_550):  case(MSH_PRI_24):
    case(MSH_PRI_33):   case(MSH_PRI_42):
    case(MSH_PRI_51):   case(MSH_PRI_60):
    case(MSH_PRI_69):   case(MSH_PRI_78):
      return TYPE_PRI;
    case(MSH_HEX_8):    case(MSH_HEX_27):
    case(MSH_HEX_20):   case(MSH_HEX_1):
    case(MSH_HEX_64):   case(MSH_HEX_125):
    case(MSH_HEX_216):  case(MSH_HEX_343):
    case(MSH_HEX_512):  case(MSH_HEX_729):
    case(MSH_HEX_1000): case(MSH_HEX_32):
    case(MSH_HEX_44):   case(MSH_HEX_56):
    case(MSH_HEX_68):   case(MSH_HEX_80):
    case(MSH_HEX_92):   case(MSH_HEX_104):
      return TYPE_HEX;
    case(MSH_POLYG_):   case(MSH_POLYG_B):
      return TYPE_POLYG;
    case(MSH_POLYH_):
      return TYPE_POLYH;
    case(MSH_PNT_SUB):  case(MSH_LIN_SUB):
    case(MSH_TRI_SUB):  case(MSH_TET_SUB):
      return TYPE_XFEM;
    case(MSH_TRI_MINI):
    case(MSH_TET_MINI):
      return TYPE_MINI;
    case(MSH_TRIH_4):
      return TYPE_TRIH;

    default:
      Msg::Error("Unknown element tag %i for parent type, returning -1.", tag);
      return -1;
  }
}

int ElementType::OrderFromTag(int tag)
{
  switch (tag) {
  case MSH_PNT     : return 0;
  case MSH_LIN_1   : return 0;
  case MSH_LIN_2   : return 1;
  case MSH_LIN_3   : return 2;
  case MSH_LIN_4   : return 3;
  case MSH_LIN_5   : return 4;
  case MSH_LIN_6   : return 5;
  case MSH_LIN_7   : return 6;
  case MSH_LIN_8   : return 7;
  case MSH_LIN_9   : return 8;
  case MSH_LIN_10  : return 9;
  case MSH_LIN_11  : return 10;
  case MSH_TRI_1   : return 0;
  case MSH_TRI_3   : return 1;
  case MSH_TRI_6   : return 2;
  case MSH_TRI_10  : return 3;
  case MSH_TRI_15  : return 4;
  case MSH_TRI_21  : return 5;
  case MSH_TRI_28  : return 6;
  case MSH_TRI_36  : return 7;
  case MSH_TRI_45  : return 8;
  case MSH_TRI_55  : return 9;
  case MSH_TRI_66  : return 10;
  case MSH_TRI_9   : return 3;
  case MSH_TRI_12  : return 4;
  case MSH_TRI_15I : return 5;
  case MSH_TRI_18  : return 6;
  case MSH_TRI_21I : return 7;
  case MSH_TRI_24  : return 8;
  case MSH_TRI_27  : return 9;
  case MSH_TRI_30  : return 10;
  case MSH_TRI_MINI  : return 1;
  case MSH_POLYG_  : return 1;
  case MSH_POLYG_B : return 1;
  case MSH_TET_1   : return 0;
  case MSH_TET_4   : return 1;
  case MSH_TET_10  : return 2;
  case MSH_TET_20  : return 3;
  case MSH_TET_35  : return 4;
  case MSH_TET_56  : return 5;
  case MSH_TET_84  : return 6;
  case MSH_TET_120 : return 7;
  case MSH_TET_165 : return 8;
  case MSH_TET_220 : return 9;
  case MSH_TET_286 : return 10;
  case MSH_TET_16  : return 3;
  case MSH_TET_22  : return 4;
  case MSH_TET_28  : return 5;
  case MSH_TET_34  : return 6;
  case MSH_TET_40  : return 7;
  case MSH_TET_46  : return 8;
  case MSH_TET_52  : return 9;
  case MSH_TET_58  : return 10;
  case MSH_TET_MINI  : return 1;
  case MSH_QUA_1   : return 0;
  case MSH_QUA_4   : return 1;
  case MSH_QUA_9   : return 2;
  case MSH_QUA_16  : return 3;
  case MSH_QUA_25  : return 4;
  case MSH_QUA_36  : return 5;
  case MSH_QUA_49  : return 6;
  case MSH_QUA_64  : return 7;
  case MSH_QUA_81  : return 8;
  case MSH_QUA_100 : return 9;
  case MSH_QUA_121 : return 10;
  case MSH_QUA_8   : return 2;
  case MSH_QUA_12  : return 3;
  case MSH_QUA_16I : return 4;
  case MSH_QUA_20  : return 5;
  case MSH_QUA_24  : return 6;
  case MSH_QUA_28  : return 7;
  case MSH_QUA_32  : return 8;
  case MSH_QUA_36I : return 9;
  case MSH_QUA_40  : return 10;
  case MSH_PRI_1   : return 0;
  case MSH_PRI_6   : return 1;
  case MSH_PRI_18  : return 2;
  case MSH_PRI_40  : return 3;
  case MSH_PRI_75  : return 4;
  case MSH_PRI_126 : return 5;
  case MSH_PRI_196 : return 6;
  case MSH_PRI_288 : return 7;
  case MSH_PRI_405 : return 8;
  case MSH_PRI_550 : return 9;
  case MSH_PRI_15  : return 2;
  case MSH_PRI_24  : return 3;
  case MSH_PRI_33  : return 4;
  case MSH_PRI_42 : return 5;
  case MSH_PRI_51 : return 6;
  case MSH_PRI_60 : return 7;
  case MSH_PRI_69 : return 8;
  case MSH_PRI_78 : return 9;
  case MSH_HEX_1   : return 0;
  case MSH_HEX_8   : return 1;
  case MSH_HEX_27  : return 2;
  case MSH_HEX_64  : return 3;
  case MSH_HEX_125 : return 4;
  case MSH_HEX_216 : return 5;
  case MSH_HEX_343 : return 6;
  case MSH_HEX_512 : return 7;
  case MSH_HEX_729 : return 8;
  case MSH_HEX_1000: return 9;
  case MSH_HEX_20  : return 2;
  case MSH_HEX_32  : return 3;
  case MSH_HEX_44  : return 4;
  case MSH_HEX_56 : return 5;
  case MSH_HEX_68 : return 6;
  case MSH_HEX_80 : return 7;
  case MSH_HEX_92 : return 8;
  case MSH_HEX_104 : return 9;
  case MSH_PYR_1   : return 0;
  case MSH_PYR_5   : return 1;
  case MSH_PYR_14  : return 2;
  case MSH_PYR_30  : return 3;
  case MSH_PYR_55  : return 4;
  case MSH_PYR_91  : return 5;
  case MSH_PYR_140 : return 6;
  case MSH_PYR_204 : return 7;
  case MSH_PYR_285 : return 8;
  case MSH_PYR_385 : return 9;
  case MSH_PYR_13  : return 2;
  case MSH_PYR_21  : return 3;
  case MSH_PYR_29  : return 4;
  case MSH_PYR_37  : return 5;
  case MSH_PYR_45 : return 6;
  case MSH_PYR_53 : return 7;
  case MSH_PYR_61 : return 8;
  case MSH_PYR_69 : return 9;
  case MSH_TRIH_4 : return 1;
  case MSH_POLYH_ : return 1;
  default :
    Msg::Warning("Unknown element tag %d, assuming order 1.",tag);
    return 1;
  }
}

int ElementType::DimensionFromTag(int tag)
{
  switch(tag) {
    case(MSH_PNT):      case(MSH_PNT_SUB):
      return 0;

    case(MSH_LIN_2):    case(MSH_LIN_3):
    case(MSH_LIN_4):    case(MSH_LIN_5):
    case(MSH_LIN_6):    case(MSH_LIN_7):
    case(MSH_LIN_8):    case(MSH_LIN_9):
    case(MSH_LIN_10):   case(MSH_LIN_11):
    case(MSH_LIN_B):    case(MSH_LIN_C):
    case(MSH_LIN_1):    case(MSH_LIN_SUB):
      return 1;

    case(MSH_TRI_3):    case(MSH_TRI_6):
    case(MSH_TRI_9):    case(MSH_TRI_10):
    case(MSH_TRI_12):   case(MSH_TRI_15):
    case(MSH_TRI_15I):  case(MSH_TRI_21):
    case(MSH_TRI_28):   case(MSH_TRI_36):
    case(MSH_TRI_45):   case(MSH_TRI_55):
    case(MSH_TRI_66):   case(MSH_TRI_18):
    case(MSH_TRI_21I):  case(MSH_TRI_24):
    case(MSH_TRI_27):   case(MSH_TRI_30):
    case(MSH_TRI_B):    case(MSH_TRI_1):
    case(MSH_TRI_SUB):  case(MSH_TRI_MINI):

    case(MSH_QUA_4):    case(MSH_QUA_9):
    case(MSH_QUA_8):    case(MSH_QUA_16):
    case(MSH_QUA_25):   case(MSH_QUA_36):
    case(MSH_QUA_12):   case(MSH_QUA_16I):
    case(MSH_QUA_20):   case(MSH_QUA_49):
    case(MSH_QUA_64):   case(MSH_QUA_81):
    case(MSH_QUA_100):  case(MSH_QUA_121):
    case(MSH_QUA_24):   case(MSH_QUA_28):
    case(MSH_QUA_32):   case(MSH_QUA_36I):
    case(MSH_QUA_40):   case(MSH_QUA_1):

    case(MSH_POLYG_):   case(MSH_POLYG_B):
      return 2;

    case(MSH_TET_4):    case(MSH_TET_10):
    case(MSH_TET_20):   case(MSH_TET_35):
    case(MSH_TET_56):   case(MSH_TET_22):
    case(MSH_TET_28):   case(MSH_TET_84):
    case(MSH_TET_120):  case(MSH_TET_165):
    case(MSH_TET_220):  case(MSH_TET_286):
    case(MSH_TET_34):   case(MSH_TET_40):
    case(MSH_TET_46):   case(MSH_TET_52):
    case(MSH_TET_58):   case(MSH_TET_1):
    case(MSH_TET_16):   case(MSH_TET_SUB):
    case(MSH_TET_MINI):

    case(MSH_PYR_5):    case(MSH_PYR_14):
    case(MSH_PYR_13):   case(MSH_PYR_30):
    case(MSH_PYR_55):   case(MSH_PYR_91):
    case(MSH_PYR_140):  case(MSH_PYR_204):
    case(MSH_PYR_285):  case(MSH_PYR_385):
    case(MSH_PYR_21):   case(MSH_PYR_29):
    case(MSH_PYR_37):   case(MSH_PYR_45):
    case(MSH_PYR_53):   case(MSH_PYR_61):
    case(MSH_PYR_69):   case(MSH_PYR_1):

    case(MSH_PRI_6):    case(MSH_PRI_18):
    case(MSH_PRI_15):   case(MSH_PRI_1):
    case(MSH_PRI_40):   case(MSH_PRI_75):
    case(MSH_PRI_126):  case(MSH_PRI_196):
    case(MSH_PRI_288):  case(MSH_PRI_405):
    case(MSH_PRI_550):  case(MSH_PRI_24):
    case(MSH_PRI_33):   case(MSH_PRI_42):
    case(MSH_PRI_51):   case(MSH_PRI_60):
    case(MSH_PRI_69):   case(MSH_PRI_78):

    case(MSH_HEX_8):    case(MSH_HEX_27):
    case(MSH_HEX_20):   case(MSH_HEX_1):
    case(MSH_HEX_64):   case(MSH_HEX_125):
    case(MSH_HEX_216):  case(MSH_HEX_343):
    case(MSH_HEX_512):  case(MSH_HEX_729):
    case(MSH_HEX_1000): case(MSH_HEX_32):
    case(MSH_HEX_44):   case(MSH_HEX_56):
    case(MSH_HEX_68):   case(MSH_HEX_80):
    case(MSH_HEX_92):   case(MSH_HEX_104):

    case(MSH_TRIH_4):
      
    case(MSH_POLYH_):
      return 3;

    default:
      Msg::Error("Unknown element tag %i for dimension, returning -1.", tag);
      return -1;
  }
}

// Gives > 0 if element tag is in Serendipity Family.
// Gives < 2 if element tag is in 'Normal' Family.
// 1 is for element that is either Serendipity or not !
int ElementType::SerendipityFromTag(int tag)
{
  switch (tag) {
  case MSH_PNT     : case MSH_LIN_1   :
  case MSH_LIN_2   : case MSH_LIN_3   :
  case MSH_LIN_4   : case MSH_LIN_5   :
  case MSH_LIN_6   : case MSH_LIN_7   :
  case MSH_LIN_8   : case MSH_LIN_9   :
  case MSH_LIN_10  : case MSH_LIN_11  :

  case MSH_TRI_1   : case MSH_TRI_3   :
  case MSH_TRI_6   :

  case MSH_QUA_1   : case MSH_QUA_4   :

  case MSH_TET_1   : case MSH_TET_4   :
  case MSH_TET_10  :

  case MSH_PRI_1   : case MSH_PRI_6   :

  case MSH_HEX_1   : case MSH_HEX_8   :

  case MSH_PYR_1   : case MSH_PYR_5   :

  case MSH_POLYG_  : case MSH_POLYG_B :
  case MSH_POLYH_  :

    return 1; // Serendipity or not


  case MSH_TRI_10  : case MSH_TRI_15  :
  case MSH_TRI_21  : case MSH_TRI_28  :
  case MSH_TRI_36  : case MSH_TRI_45  :
  case MSH_TRI_55  : case MSH_TRI_66  :

  case MSH_QUA_9   : case MSH_QUA_16  :
  case MSH_QUA_25  : case MSH_QUA_36  :
  case MSH_QUA_49  : case MSH_QUA_64  :
  case MSH_QUA_81  : case MSH_QUA_100 :
  case MSH_QUA_121 :

  case MSH_TET_20  : case MSH_TET_35  :
  case MSH_TET_56  : case MSH_TET_84  :
  case MSH_TET_120 : case MSH_TET_165 :
  case MSH_TET_220 : case MSH_TET_286 :

  case MSH_PRI_18  : case MSH_PRI_40  :
  case MSH_PRI_75  : case MSH_PRI_126 :
  case MSH_PRI_196 : case MSH_PRI_288 :
  case MSH_PRI_405 : case MSH_PRI_550 :

  case MSH_HEX_27  : case MSH_HEX_64  :
  case MSH_HEX_125 : case MSH_HEX_216 :
  case MSH_HEX_343 : case MSH_HEX_512 :
  case MSH_HEX_729 : case MSH_HEX_1000:

  case MSH_PYR_14  : case MSH_PYR_30  :
  case MSH_PYR_55  : case MSH_PYR_91  :
  case MSH_PYR_140 : case MSH_PYR_204 :
  case MSH_PYR_285 : case MSH_PYR_385 :

  case MSH_TRIH_4 :
    
    return 0; // Not Serendipity


  case MSH_TRI_9   : case MSH_TRI_12  :
  case MSH_TRI_15I : case MSH_TRI_18  :
  case MSH_TRI_21I : case MSH_TRI_24  :
  case MSH_TRI_27  : case MSH_TRI_30  :

  case MSH_QUA_8   : case MSH_QUA_12  :
  case MSH_QUA_16I : case MSH_QUA_20  :
  case MSH_QUA_24  : case MSH_QUA_28  :
  case MSH_QUA_32  : case MSH_QUA_36I :
  case MSH_QUA_40  :

  case MSH_TET_22  : case MSH_TET_28  :
  case MSH_TET_34  : case MSH_TET_40 :
  case MSH_TET_46 :  case MSH_TET_52 :
  case MSH_TET_58 :  case MSH_TET_16 :

  case MSH_PRI_15  : case MSH_PRI_24  :
  case MSH_PRI_33  : case MSH_PRI_42 :
  case MSH_PRI_51 :  case MSH_PRI_60 :
  case MSH_PRI_69 :  case MSH_PRI_78 :

  case MSH_HEX_20  : case MSH_HEX_32  :
  case MSH_HEX_44  : case MSH_HEX_56 :
  case MSH_HEX_68 :  case MSH_HEX_80 :
  case MSH_HEX_92 :  case MSH_HEX_104 :

  case MSH_PYR_13  : case MSH_PYR_21  :
  case MSH_PYR_29  : case MSH_PYR_37  :
  case MSH_PYR_45 :  case MSH_PYR_53 :
  case MSH_PYR_61 :  case MSH_PYR_69 :

    return 2; // Only Serendipity

  default :
    Msg::Warning("Unknown element tag %d, assuming not serendipity.",tag);
    return 0;
  }
}

int ElementType::getTag(int parentTag, int order, bool serendip)
{
  switch (parentTag) {
  case TYPE_PNT :
    return MSH_PNT;
  case TYPE_LIN :
    switch(order) {
    case 0 : return MSH_LIN_1;
    case 1 : return MSH_LIN_2;
    case 2 : return MSH_LIN_3;
    case 3 : return MSH_LIN_4;
    case 4 : return MSH_LIN_5;
    case 5 : return MSH_LIN_6;
    case 6 : return MSH_LIN_7;
    case 7 : return MSH_LIN_8;
    case 8 : return MSH_LIN_9;
    case 9 : return MSH_LIN_10;
    case 10: return MSH_LIN_11;
    default : Msg::Error("line order %i unknown", order); return 0;
    }
    break;
  case TYPE_TRI :
    switch(order) {
    case 0 : return MSH_TRI_1;
    case 1 : return MSH_TRI_3;
    case 2 : return MSH_TRI_6;
    case 3 : return serendip ? MSH_TRI_9  : MSH_TRI_10;
    case 4 : return serendip ? MSH_TRI_12 : MSH_TRI_15;
    case 5 : return serendip ? MSH_TRI_15I: MSH_TRI_21;
    case 6 : return serendip ? MSH_TRI_18 : MSH_TRI_28;
    case 7 : return serendip ? MSH_TRI_21I: MSH_TRI_36;
    case 8 : return serendip ? MSH_TRI_24 : MSH_TRI_45;
    case 9 : return serendip ? MSH_TRI_27 : MSH_TRI_55;
    case 10: return serendip ? MSH_TRI_30 : MSH_TRI_66;
    default : Msg::Error("triangle order %i unknown", order); return 0;
    }
    break;
  case TYPE_QUA :
    switch(order) {
    case 0 : return MSH_QUA_1;
    case 1 : return MSH_QUA_4;
    case 2 : return serendip ? MSH_QUA_8  : MSH_QUA_9;
    case 3 : return serendip ? MSH_QUA_12 : MSH_QUA_16;
    case 4 : return serendip ? MSH_QUA_16I: MSH_QUA_25;
    case 5 : return serendip ? MSH_QUA_20 : MSH_QUA_36;
    case 6 : return serendip ? MSH_QUA_24 : MSH_QUA_49;
    case 7 : return serendip ? MSH_QUA_28 : MSH_QUA_64;
    case 8 : return serendip ? MSH_QUA_32 : MSH_QUA_81;
    case 9 : return serendip ? MSH_QUA_36I: MSH_QUA_100;
    case 10: return serendip ? MSH_QUA_40 : MSH_QUA_121;
    default : Msg::Error("quad order %i unknown", order); return 0;
    }
    break;
  case TYPE_TET :
    switch(order) {
    case 0 : return MSH_TET_1;
    case 1 : return MSH_TET_4;
    case 2 : return MSH_TET_10;
    case 3 : return serendip ? MSH_TET_16 : MSH_TET_20;
    case 4 : return serendip ? MSH_TET_22 : MSH_TET_35;
    case 5 : return serendip ? MSH_TET_28 : MSH_TET_56;
    case 6 : return serendip ? MSH_TET_34 : MSH_TET_84;
    case 7 : return serendip ? MSH_TET_40: MSH_TET_120;
    case 8 : return serendip ? MSH_TET_46: MSH_TET_165;
    case 9 : return serendip ? MSH_TET_52: MSH_TET_220;
    case 10: return serendip ? MSH_TET_58: MSH_TET_286;
    default : Msg::Error("terahedron order %i unknown", order); return 0;
    }
    break;
  case TYPE_HEX :
    switch(order) {
    case 0 : return MSH_HEX_1;
    case 1 : return MSH_HEX_8;
    case 2 : return serendip ? MSH_HEX_20 : MSH_HEX_27;
    case 3 : return serendip ? MSH_HEX_32 : MSH_HEX_64;
    case 4 : return serendip ? MSH_HEX_44 : MSH_HEX_125;
    case 5 : return serendip ? MSH_HEX_56: MSH_HEX_216;
    case 6 : return serendip ? MSH_HEX_68: MSH_HEX_343;
    case 7 : return serendip ? MSH_HEX_80: MSH_HEX_512;
    case 8 : return serendip ? MSH_HEX_92: MSH_HEX_729;
    case 9 : return serendip ? MSH_HEX_104: MSH_HEX_1000;
    default : Msg::Error("hexahedron order %i unknown", order); return 0;
    }
    break;
  case TYPE_PRI :
    switch(order) {
    case 0 : return MSH_PRI_1;
    case 1 : return MSH_PRI_6;
    case 2 : return serendip ? MSH_PRI_15 : MSH_PRI_18;
    case 3 : return serendip ? MSH_PRI_24 : MSH_PRI_40;
    case 4 : return serendip ? MSH_PRI_33 : MSH_PRI_75;
    case 5 : return serendip ? MSH_PRI_42 : MSH_PRI_126;
    case 6 : return serendip ? MSH_PRI_51 : MSH_PRI_196;
    case 7 : return serendip ? MSH_PRI_60 : MSH_PRI_288;
    case 8 : return serendip ? MSH_PRI_69 : MSH_PRI_405;
    case 9 : return serendip ? MSH_PRI_78 : MSH_PRI_550;
    default : Msg::Error("prism order %i unknown", order); return 0;
    }
    break;
  case TYPE_PYR :
    switch(order) {
    case 0 : return MSH_PYR_1;
    case 1 : return MSH_PYR_5;
    case 2 : return serendip ? MSH_PYR_13 : MSH_PYR_14;
    case 3: return serendip ? MSH_PYR_21 : MSH_PYR_30;
    case 4: return serendip ? MSH_PYR_29 : MSH_PYR_55;
    case 5: return serendip ? MSH_PYR_37 : MSH_PYR_91;
    case 6: return serendip ? MSH_PYR_45 : MSH_PYR_140;
    case 7: return serendip ? MSH_PYR_53 : MSH_PYR_204;
    case 8: return serendip ? MSH_PYR_61 : MSH_PYR_285;
    case 9: return serendip ? MSH_PYR_69 : MSH_PYR_385;
    default : Msg::Error("pyramid order %i unknown", order); return 0;
    }
    break;
  case TYPE_TRIH :
    return MSH_TRIH_4;
  default : Msg::Warning("unknown element type %i, returning 0", parentTag); return 0;
  }
}

int ElementType::getPrimaryTag(int tag) {
  return getTag(ParentTypeFromTag(tag), 1);
}
