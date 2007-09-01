// $Id: PViewDataListIO.cpp,v 1.1 2007-09-01 16:06:24 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
// 

#include "PViewDataList.h"
#include "Message.h"

bool PViewDataList::read(std::string filename)
{
  FILE *fp = fopen(filename.c_str(), "rb");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", filename.c_str());
    return false;
  }

  char str[256], name[256];
  int format, size, swap, t2l, t3l;
  double version;

  while(1) {

    do {
      if(!fgets(str, 256, fp) || feof(fp))
        break;
    } while(str[0] != '$');
    
    if(feof(fp))
      break;

    if(!strncmp(&str[1], "PostFormat", 10)) {
      if(!fscanf(fp, "%lf %d %d\n", &version, &format, &size)){
        Msg(GERROR, "Read error");
        return false;
      }
      if(version < 1.0) {
        Msg(GERROR, "Post-processing file too old (ver. %g < 1.0)", version);
        return false;
      }
      if(size == sizeof(double))
        Msg(DEBUG, "Data is in double precision format (size==%d)", size);
      else {
        Msg(GERROR, "Unknown data size (%d) in post-processing file", size);
        return false;
      }
      if(format == 0)
        format = LIST_FORMAT_ASCII;
      else if(format == 1)
        format = LIST_FORMAT_BINARY;
      else {
        Msg(GERROR, "Unknown format for view");
        return false;
      }
    }

    if(!strncmp(&str[1], "View", 4)) {
      if(version <= 1.0) {
        Msg(DEBUG, "Detected post-processing view format <= 1.0");
        if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &NbTimeStep,
		   &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
		   &NbST, &NbVT, &NbTT, &NbSS, &NbVS, &NbTS)){
	  Msg(GERROR, "Read error");
	  return false;
	}
        NbT2 = t2l = NbT3 = t3l = 0;
      }
      else if(version == 1.1) {
        Msg(DEBUG, "Detected post-processing view format 1.1");
        if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL,
		   &NbVL, &NbTL, &NbST, &NbVT, &NbTT, &NbSS,
		   &NbVS, &NbTS, &NbT2, &t2l, &NbT3, &t3l)){
	  Msg(GERROR, "Read error");
	  return false;
	}
      }
      else if(version == 1.2 || version == 1.3) {
        Msg(DEBUG, "Detected post-processing view format %g", version);
        if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
		   "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &NbTimeStep,
		   &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
		   &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ,
		   &NbSS, &NbVS, &NbTS, &NbSH, &NbVH, &NbTH,
		   &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
		   &NbT2, &t2l, &NbT3, &t3l)){
	  Msg(GERROR, "Read error");
	  return false;
	}
      }
      else if(version == 1.4) {
        Msg(DEBUG, "Detected post-processing view format 1.4");
        if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
		   "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
		   "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &NbTimeStep,
		   &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
		   &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ,
		   &NbSS, &NbVS, &NbTS, &NbSH, &NbVH, &NbTH,
		   &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
		   &NbSL2, &NbVL2, &NbTL2, &NbST2, &NbVT2, &NbTT2,
		   &NbSQ2, &NbVQ2, &NbTQ2, &NbSS2, &NbVS2, &NbTS2,
		   &NbSH2, &NbVH2, &NbTH2, &NbSI2, &NbVI2, &NbTI2,
		   &NbSY2, &NbVY2, &NbTY2, &NbT2, &t2l, &NbT3, &t3l)){
	  Msg(GERROR, "Read error");
	  return false;
	}
      }
      else {
        Msg(GERROR, "Unknown post-processing file format (version %g)", version);
        return false;
      }
      
      for(int i = 0; i < (int)strlen(name); i++)
        if(name[i] == '^')
          name[i] = ' ';
      
      swap = 0;
      if(format == LIST_FORMAT_BINARY) {
	int testone;
        if(!fread(&testone, sizeof(int), 1, fp)){
	  Msg(GERROR, "Read error");
	  return false;
	}
        if(testone != 1) {
          Msg(INFO, "Swapping bytes from binary file");
          swap = 1;
        }
      }

      DataSize = size;
      
      // Time values
      Time = List_CreateFromFile(NbTimeStep, 100, size, fp, format, swap);

      // Note: if nb==0, we still allocates the lists (so that they
      // are ready to be filled later, e.g. in plugins)

#define LCD List_CreateFromFile(nb, 1000, size, fp, format, swap)
      int nb;
      // Points
      nb = NbSP ? NbSP * (NbTimeStep * 1 + 3) : 0; SP = LCD;
      nb = NbVP ? NbVP * (NbTimeStep * 3 + 3) : 0; VP = LCD;
      nb = NbTP ? NbTP * (NbTimeStep * 9 + 3) : 0; TP = LCD;

      // Lines
      nb = NbSL ? NbSL * (NbTimeStep * 2 * 1 + 6) : 0; SL = LCD;
      nb = NbVL ? NbVL * (NbTimeStep * 2 * 3 + 6) : 0; VL = LCD;
      nb = NbTL ? NbTL * (NbTimeStep * 2 * 9 + 6) : 0; TL = LCD;

      // Triangles
      nb = NbST ? NbST * (NbTimeStep * 3 * 1 + 9) : 0; ST = LCD;
      nb = NbVT ? NbVT * (NbTimeStep * 3 * 3 + 9) : 0; VT = LCD;
      nb = NbTT ? NbTT * (NbTimeStep * 3 * 9 + 9) : 0; TT = LCD;

      // Quadrangles
      nb = NbSQ ? NbSQ * (NbTimeStep * 4 * 1 + 12) : 0; SQ = LCD;
      nb = NbVQ ? NbVQ * (NbTimeStep * 4 * 3 + 12) : 0; VQ = LCD;
      nb = NbTQ ? NbTQ * (NbTimeStep * 4 * 9 + 12) : 0; TQ = LCD;

      // Tetrahedra
      nb = NbSS ? NbSS * (NbTimeStep * 4 * 1 + 12) : 0; SS = LCD;
      nb = NbVS ? NbVS * (NbTimeStep * 4 * 3 + 12) : 0; VS = LCD;
      nb = NbTS ? NbTS * (NbTimeStep * 4 * 9 + 12) : 0; TS = LCD;

      // Hexahedra
      nb = NbSH ? NbSH * (NbTimeStep * 8 * 1 + 24) : 0; SH = LCD;
      nb = NbVH ? NbVH * (NbTimeStep * 8 * 3 + 24) : 0; VH = LCD;
      nb = NbTH ? NbTH * (NbTimeStep * 8 * 9 + 24) : 0; TH = LCD;

      // Prisms
      nb = NbSI ? NbSI * (NbTimeStep * 6 * 1 + 18) : 0; SI = LCD;
      nb = NbVI ? NbVI * (NbTimeStep * 6 * 3 + 18) : 0; VI = LCD;
      nb = NbTI ? NbTI * (NbTimeStep * 6 * 9 + 18) : 0; TI = LCD;

      // Pyramids
      nb = NbSY ? NbSY * (NbTimeStep * 5 * 1 + 15) : 0; SY = LCD;
      nb = NbVY ? NbVY * (NbTimeStep * 5 * 3 + 15) : 0; VY = LCD;
      nb = NbTY ? NbTY * (NbTimeStep * 5 * 9 + 15) : 0; TY = LCD;

      // 2nd order Lines
      nb = NbSL2 ? NbSL2 * (NbTimeStep * 3 * 1 + 9) : 0; SL2 = LCD;
      nb = NbVL2 ? NbVL2 * (NbTimeStep * 3 * 3 + 9) : 0; VL2 = LCD;
      nb = NbTL2 ? NbTL2 * (NbTimeStep * 3 * 9 + 9) : 0; TL2 = LCD;

      // 2nd order Triangles
      nb = NbST2 ? NbST2 * (NbTimeStep * 6 * 1 + 18) : 0; ST2 = LCD;
      nb = NbVT2 ? NbVT2 * (NbTimeStep * 6 * 3 + 18) : 0; VT2 = LCD;
      nb = NbTT2 ? NbTT2 * (NbTimeStep * 6 * 9 + 18) : 0; TT2 = LCD;

      // 2nd order Quadrangles
      nb = NbSQ2 ? NbSQ2 * (NbTimeStep * 9 * 1 + 27) : 0; SQ2 = LCD;
      nb = NbVQ2 ? NbVQ2 * (NbTimeStep * 9 * 3 + 27) : 0; VQ2 = LCD;
      nb = NbTQ2 ? NbTQ2 * (NbTimeStep * 9 * 9 + 27) : 0; TQ2 = LCD;

      // 2nd order Tetrahedra
      nb = NbSS2 ? NbSS2 * (NbTimeStep * 10 * 1 + 30) : 0; SS2 = LCD;
      nb = NbVS2 ? NbVS2 * (NbTimeStep * 10 * 3 + 30) : 0; VS2 = LCD;
      nb = NbTS2 ? NbTS2 * (NbTimeStep * 10 * 9 + 30) : 0; TS2 = LCD;

      // 2nd order Hexahedra
      nb = NbSH2 ? NbSH2 * (NbTimeStep * 27 * 1 + 81) : 0; SH2 = LCD;
      nb = NbVH2 ? NbVH2 * (NbTimeStep * 27 * 3 + 81) : 0; VH2 = LCD;
      nb = NbTH2 ? NbTH2 * (NbTimeStep * 27 * 9 + 81) : 0; TH2 = LCD;

      // 2nd order Prisms
      nb = NbSI2 ? NbSI2 * (NbTimeStep * 18 * 1 + 54) : 0; SI2 = LCD;
      nb = NbVI2 ? NbVI2 * (NbTimeStep * 18 * 3 + 54) : 0; VI2 = LCD;
      nb = NbTI2 ? NbTI2 * (NbTimeStep * 18 * 9 + 54) : 0; TI2 = LCD;

      // 2nd order Pyramids
      nb = NbSY2 ? NbSY2 * (NbTimeStep * 14 * 1 + 42) : 0; SY2 = LCD;
      nb = NbVY2 ? NbVY2 * (NbTimeStep * 14 * 3 + 42) : 0; VY2 = LCD;
      nb = NbTY2 ? NbTY2 * (NbTimeStep * 14 * 9 + 42) : 0; TY2 = LCD;
#undef LCD

      // 2D strings
      nb = NbT2 ? NbT2 * 4 : 0;
      T2D = List_CreateFromFile(nb, 100, size, fp, format, swap);
      if(version <= 1.2)
	T2C = List_CreateFromFileOld(t2l, 100, sizeof(char), fp, format, swap);
      else
	T2C = List_CreateFromFile(t2l, 100, sizeof(char), fp, format, swap);

      // 3D strings
      nb = NbT3 ? NbT3 * 5 : 0;
      T3D = List_CreateFromFile(nb, 100, size, fp, format, swap);
      if(version <= 1.2)
	T3C = List_CreateFromFileOld(t3l, 100, sizeof(char), fp, format, swap);
      else
	T3C = List_CreateFromFile(t3l, 100, sizeof(char), fp, format, swap);

      Msg(DEBUG,
          "Read View '%s' (%d TimeSteps): "
	  "SP(%d/%d) VP(%d/%d) TP(%d/%d) "
	  "SL(%d/%d) VL(%d/%d) TL(%d/%d) "
	  "ST(%d/%d) VT(%d/%d) TT(%d/%d) "
	  "SQ(%d/%d) VQ(%d/%d) TQ(%d/%d) "
	  "SS(%d/%d) VS(%d/%d) TS(%d/%d) "
	  "SH(%d/%d) VH(%d/%d) TH(%d/%d) "
	  "SI(%d/%d) VI(%d/%d) TI(%d/%d) "
	  "SY(%d/%d) VY(%d/%d) TY(%d/%d) " 
	  "SL2(%d/%d) VL2(%d/%d) TL2(%d/%d) "
	  "ST2(%d/%d) VT2(%d/%d) TT2(%d/%d) "
	  "SQ2(%d/%d) VQ2(%d/%d) TQ2(%d/%d) "
	  "SS2(%d/%d) VS2(%d/%d) TS2(%d/%d) " 
	  "SH2(%d/%d) VH2(%d/%d) TH2(%d/%d) "
	  "SI2(%d/%d) VI2(%d/%d) TI2(%d/%d) "
	  "SY2(%d/%d) VY2(%d/%d) TY2(%d/%d) "
	  "T2(%d/%d/%d) T3(%d/%d/%d) ", 
	  name, NbTimeStep,
          NbSP, List_Nbr(SP), NbVP, List_Nbr(VP), NbTP, List_Nbr(TP),
          NbSL, List_Nbr(SL), NbVL, List_Nbr(VL), NbTL, List_Nbr(TL),
          NbST, List_Nbr(ST), NbVT, List_Nbr(VT), NbTT, List_Nbr(TT),
          NbSQ, List_Nbr(SQ), NbVQ, List_Nbr(VQ), NbTQ, List_Nbr(TQ),
          NbSS, List_Nbr(SS), NbVS, List_Nbr(VS), NbTS, List_Nbr(TS),
          NbSH, List_Nbr(SH), NbVH, List_Nbr(VH), NbTH, List_Nbr(TH),
          NbSI, List_Nbr(SI), NbVI, List_Nbr(VI), NbTI, List_Nbr(TI),
          NbSY, List_Nbr(SY), NbVY, List_Nbr(VY), NbTY, List_Nbr(TY),
          NbSL2, List_Nbr(SL2), NbVL2, List_Nbr(VL2), NbTL2, List_Nbr(TL2),
          NbST2, List_Nbr(ST2), NbVT2, List_Nbr(VT2), NbTT2, List_Nbr(TT2),
          NbSQ2, List_Nbr(SQ2), NbVQ2, List_Nbr(VQ2), NbTQ2, List_Nbr(TQ2),
          NbSS2, List_Nbr(SS2), NbVS2, List_Nbr(VS2), NbTS2, List_Nbr(TS2),
          NbSH2, List_Nbr(SH2), NbVH2, List_Nbr(VH2), NbTH2, List_Nbr(TH2),
          NbSI2, List_Nbr(SI2), NbVI2, List_Nbr(VI2), NbTI2, List_Nbr(TI2),
          NbSY2, List_Nbr(SY2), NbVY2, List_Nbr(VY2), NbTY2, List_Nbr(TY2),
	  NbT2, List_Nbr(T2D), List_Nbr(T2C), 
	  NbT3, List_Nbr(T3D), List_Nbr(T3C));
      
      finalize();
    }

    do {
      if(!fgets(str, 256, fp) || feof(fp))
        Msg(GERROR, "Prematured end of file");
    } while(str[0] != '$');
    
  }

  return true;
}
