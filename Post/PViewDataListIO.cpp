// $Id: PViewDataListIO.cpp,v 1.4 2008-01-10 14:56:55 remacle Exp $
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

#include <string.h>
#include <set>
#include "PViewDataList.h"
#include "Numeric.h"
#include "Message.h"
#include "Context.h"

extern Context_T CTX;

bool PViewDataList::read(FILE *fp, double version, int format, int size)
{
  char name[256];
  int t2l, t3l;

  if(version <= 1.0) {
    Msg(DEBUG, "Detected post-processing view format <= 1.0");
    if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
	       name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
	       &NbST, &NbVT, &NbTT, &NbSS, &NbVS, &NbTS)){
      Msg(GERROR, "Read error");
      return false;
    }
    NbT2 = t2l = NbT3 = t3l = 0;
  }
  else if(version == 1.1) {
    Msg(DEBUG, "Detected post-processing view format 1.1");
    if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
	       name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL, 
	       &NbST, &NbVT, &NbTT, &NbSS, &NbVS, &NbTS, &NbT2, &t2l, &NbT3,
	       &t3l)){
      Msg(GERROR, "Read error");
      return false;
    }
  }
  else if(version == 1.2 || version == 1.3) {
    Msg(DEBUG, "Detected post-processing view format %g", version);
    if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
	       "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
	       name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
	       &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ, &NbSS, &NbVS, &NbTS, 
	       &NbSH, &NbVH, &NbTH, &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
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
	       name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
	       &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ, &NbSS, &NbVS, &NbTS, 
	       &NbSH, &NbVH, &NbTH, &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
	       &NbSL2, &NbVL2, &NbTL2, &NbST2, &NbVT2, &NbTT2, &NbSQ2, &NbVQ2, 
	       &NbTQ2, &NbSS2, &NbVS2, &NbTS2, &NbSH2, &NbVH2, &NbTH2, &NbSI2, 
	       &NbVI2, &NbTI2, &NbSY2, &NbVY2, &NbTY2, &NbT2, &t2l, &NbT3, &t3l)){
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
  
  int swap = 0;
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
  
  setName(name);
  finalize();

  return true;
}

static void writeTimePOS(FILE *fp, List_T *list)
{
  if(List_Nbr(list) > 1){
    fprintf(fp, "TIME{");
    for(int i = 0; i < List_Nbr(list); i ++){
      if(i) fprintf(fp, ",");
      fprintf(fp, "%.16g", *(double *)List_Pointer(list, i));
    }
    fprintf(fp, "};\n");
  }
}

static void writeElementPOS(FILE *fp, const char *str, int nbnod, int nb,
			    List_T *list)
{
  if(nb){
    int n = List_Nbr(list) / nb;
    for(int i = 0; i < List_Nbr(list); i += n) {
      double *x = (double *)List_Pointer(list, i);
      double *y = (double *)List_Pointer(list, i + nbnod);
      double *z = (double *)List_Pointer(list, i + 2 * nbnod);
      fprintf(fp, "%s(", str);
      for(int j = 0; j < nbnod; j++) {
	if(j) fprintf(fp, ",");
	fprintf(fp, "%.16g,%.16g,%.16g", x[j], y[j], z[j]);
      }
      fprintf(fp, "){");
      for(int j = 3 * nbnod; j < n; j++) {
	if(j - 3 * nbnod) fprintf(fp, ",");
	fprintf(fp, "%.16g", *(double *)List_Pointer(list, i + j));
      }
      fprintf(fp, "};\n");
    }
  }
}

static void writeTextPOS(FILE *fp, int nbc, int nb, List_T *TD, List_T *TC)
{
  if(!nb || (nbc != 4 && nbc != 5)) return;
  for(int j = 0; j < List_Nbr(TD); j += nbc){
    double x, y, z, style, start, end;
    List_Read(TD, j, &x);
    List_Read(TD, j+1, &y);
    if(nbc == 5)
      List_Read(TD, j+2, &z);
    List_Read(TD, j+nbc-2, &style);
    if(nbc == 4)
      fprintf(fp, "T2(%g,%g,%g){", x, y, style);
    else
      fprintf(fp, "T3(%g,%g,%g,%g){", x, y, z, style);
    List_Read(TD, j+nbc-1, &start);
    if(j+nbc*2-1 < List_Nbr(TD))
      List_Read(TD, j+nbc*2-1, &end);
    else
      end = List_Nbr(TC);
    int l = 0;
    while(l < end-start){
      char *str = (char*)List_Pointer(TC, (int)start + l);
      if(l) fprintf(fp, ",");
      fprintf(fp, "\"%s\"", str);
      l += strlen(str)+1;
    }
    fprintf(fp, "};\n");
  }
}

bool PViewDataList::writePOS(std::string name, bool binary, bool parsed, bool append)
{
  FILE *fp = fopen(name.c_str(), 
		   append ? (binary ? "ab" : "a") : (binary ? "wb" : "w"));
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  if(!parsed && !append){
    fprintf(fp, "$PostFormat /* Gmsh 1.3, %s */\n", binary ? "binary" : "ascii");
    fprintf(fp, "1.3 %d %d\n", binary, (int)sizeof(double));
    fprintf(fp, "$EndPostFormat\n");
  }

  char str[256];
  strcpy(str, getName().c_str());
  for(int i = 0; i < (int)strlen(str); i++)
    if(str[i] == ' ') str[i] = '^';

  if(!parsed){
    fprintf(fp, "$View /* %s */\n", getName().c_str());
    fprintf(fp, "%s ", str);
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
	    "%d %d %d %d %d %d %d %d %d %d %d %d\n",
	    List_Nbr(Time),
	    NbSP, NbVP, NbTP, NbSL, NbVL, NbTL,
	    NbST, NbVT, NbTT, NbSQ, NbVQ, NbTQ,
	    NbSS, NbVS, NbTS, NbSH, NbVH, NbTH,
	    NbSI, NbVI, NbTI, NbSY, NbVY, NbTY,
	    NbT2, List_Nbr(T2C), NbT3, List_Nbr(T3C));
    int f = binary ? LIST_FORMAT_BINARY : LIST_FORMAT_ASCII;
    if(binary) {
      int one = 1;
      if(!fwrite(&one, sizeof(int), 1, fp)){
	Msg(GERROR, "Write error");
	return false;
      }
    }
    List_WriteToFile(Time, fp, f);
    List_WriteToFile(SP, fp, f); List_WriteToFile(VP, fp, f); 
    List_WriteToFile(TP, fp, f); List_WriteToFile(SL, fp, f);
    List_WriteToFile(VL, fp, f); List_WriteToFile(TL, fp, f);
    List_WriteToFile(ST, fp, f); List_WriteToFile(VT, fp, f);
    List_WriteToFile(TT, fp, f); List_WriteToFile(SQ, fp, f);
    List_WriteToFile(VQ, fp, f); List_WriteToFile(TQ, fp, f);
    List_WriteToFile(SS, fp, f); List_WriteToFile(VS, fp, f);
    List_WriteToFile(TS, fp, f); List_WriteToFile(SH, fp, f);
    List_WriteToFile(VH, fp, f); List_WriteToFile(TH, fp, f);
    List_WriteToFile(SI, fp, f); List_WriteToFile(VI, fp, f);
    List_WriteToFile(TI, fp, f); List_WriteToFile(SY, fp, f);
    List_WriteToFile(VY, fp, f); List_WriteToFile(TY, fp, f);
    List_WriteToFile(T2D, fp, f); List_WriteToFile(T2C, fp, f);
    List_WriteToFile(T3D, fp, f); List_WriteToFile(T3C, fp, f);
    fprintf(fp, "\n");
    fprintf(fp, "$EndView\n");
  }
  else{
    fprintf(fp, "View \"%s\" {\n", getName().c_str());
    writeTimePOS(fp, Time);
    writeElementPOS(fp, "SP", 1, NbSP, SP); writeElementPOS(fp, "VP", 1, NbVP, VP);
    writeElementPOS(fp, "TP", 1, NbTP, TP); writeElementPOS(fp, "SL", 2, NbSL, SL);
    writeElementPOS(fp, "VL", 2, NbVL, VL); writeElementPOS(fp, "TL", 2, NbTL, TL);
    writeElementPOS(fp, "ST", 3, NbST, ST); writeElementPOS(fp, "VT", 3, NbVT, VT);
    writeElementPOS(fp, "TT", 3, NbTT, TT); writeElementPOS(fp, "SQ", 4, NbSQ, SQ);
    writeElementPOS(fp, "VQ", 4, NbVQ, VQ); writeElementPOS(fp, "TQ", 4, NbTQ, TQ);
    writeElementPOS(fp, "SS", 4, NbSS, SS); writeElementPOS(fp, "VS", 4, NbVS, VS);
    writeElementPOS(fp, "TS", 4, NbTS, TS); writeElementPOS(fp, "SH", 8, NbSH, SH);
    writeElementPOS(fp, "VH", 8, NbVH, VH); writeElementPOS(fp, "TH", 8, NbTH, TH);
    writeElementPOS(fp, "SI", 6, NbSI, SI); writeElementPOS(fp, "VI", 6, NbVI, VI);
    writeElementPOS(fp, "TI", 6, NbTI, TI); writeElementPOS(fp, "SY", 5, NbSY, SY);
    writeElementPOS(fp, "VY", 5, NbVY, VY); writeElementPOS(fp, "TY", 5, NbTY, TY);
    writeTextPOS(fp, 4, NbT2, T2D, T2C); writeTextPOS(fp, 5, NbT3, T3D, T3C);
    fprintf(fp, "};\n");
  }

  fclose(fp);
  return true;
}

static void writeElementSTL(FILE *fp, int nbelm, List_T *list, int nbnod)
{
  if(!nbelm) return;
  int nb = List_Nbr(list) / nbelm;
  for(int i = 0; i < List_Nbr(list); i+=nb){
    double *x = (double*)List_Pointer(list, i);
    double n[3];
    normal3points(x[0], x[3], x[6],
		  x[1], x[4], x[7],
		  x[2], x[5], x[8], n);
    if(nbnod == 3){
      fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
      fprintf(fp, "  outer loop\n");
      fprintf(fp, "    vertex %g %g %g\n", x[0], x[3], x[6]);
      fprintf(fp, "    vertex %g %g %g\n", x[1], x[4], x[7]);
      fprintf(fp, "    vertex %g %g %g\n", x[2], x[5], x[8]);
      fprintf(fp, "  endloop\n");
      fprintf(fp, "endfacet\n");
    }
    else{
      fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
      fprintf(fp, "  outer loop\n");
      fprintf(fp, "    vertex %g %g %g\n", x[0], x[4], x[8]);
      fprintf(fp, "    vertex %g %g %g\n", x[1], x[5], x[9]);
      fprintf(fp, "    vertex %g %g %g\n", x[2], x[6], x[10]);
      fprintf(fp, "  endloop\n");
      fprintf(fp, "endfacet\n");
      fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
      fprintf(fp, "  outer loop\n");
      fprintf(fp, "    vertex %g %g %g\n", x[0], x[4], x[8]);
      fprintf(fp, "    vertex %g %g %g\n", x[2], x[6], x[10]);
      fprintf(fp, "    vertex %g %g %g\n", x[3], x[7], x[11]);
      fprintf(fp, "  endloop\n");
      fprintf(fp, "endfacet\n");
    }
  }
}

bool PViewDataList::writeSTL(std::string name)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  if(!NbST && !NbVT && !NbTT && !NbSQ && !NbVQ && !NbTQ){
    Msg(GERROR, "No surface elements to save");
    return false;
  }

  fprintf(fp, "solid Created by Gmsh\n");
  writeElementSTL(fp, NbST, ST, 3);
  writeElementSTL(fp, NbVT, VT, 3);
  writeElementSTL(fp, NbTT, TT, 3);
  writeElementSTL(fp, NbSQ, SQ, 4);
  writeElementSTL(fp, NbVQ, VQ, 4);
  writeElementSTL(fp, NbTQ, TQ, 4);
  fprintf(fp, "endsolid Created by Gmsh\n");

  fclose(fp);
  return true;
}

static void writeElementTXT(FILE *file, int nbelm, List_T *list,
			    int nbnod, int nbcomp, int nbtime)
{
  if(!nbelm) return;
  int nb = List_Nbr(list) / nbelm;
  for(int i = 0; i < List_Nbr(list); i += nb){
    double *x = (double*)List_Pointer(list, i);
    for(int j = 0; j < nbnod * (3 + nbcomp * nbtime); j++)
      fprintf(file, "%.16g ", x[j]);
    fprintf(file, "\n");
  }
  fprintf(file, "\n");
}

bool PViewDataList::writeTXT(std::string name)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  writeElementTXT(fp, NbSP, SP, 1, 1, NbTimeStep);
  writeElementTXT(fp, NbVP, VP, 1, 3, NbTimeStep);
  writeElementTXT(fp, NbTP, TP, 1, 9, NbTimeStep);
  writeElementTXT(fp, NbSL, SL, 2, 1, NbTimeStep);
  writeElementTXT(fp, NbVL, VL, 2, 3, NbTimeStep);
  writeElementTXT(fp, NbTL, TL, 2, 9, NbTimeStep);
  writeElementTXT(fp, NbST, ST, 3, 1, NbTimeStep);
  writeElementTXT(fp, NbVT, VT, 3, 3, NbTimeStep);
  writeElementTXT(fp, NbTT, TT, 3, 9, NbTimeStep);
  writeElementTXT(fp, NbSQ, SQ, 4, 1, NbTimeStep);
  writeElementTXT(fp, NbVQ, VQ, 4, 3, NbTimeStep);
  writeElementTXT(fp, NbTQ, TQ, 4, 9, NbTimeStep);
  writeElementTXT(fp, NbSS, SS, 4, 1, NbTimeStep);
  writeElementTXT(fp, NbVS, VS, 4, 3, NbTimeStep);
  writeElementTXT(fp, NbTS, TS, 4, 9, NbTimeStep);
  writeElementTXT(fp, NbSH, SH, 8, 1, NbTimeStep);
  writeElementTXT(fp, NbVH, VH, 8, 3, NbTimeStep);
  writeElementTXT(fp, NbTH, TH, 8, 9, NbTimeStep);
  writeElementTXT(fp, NbSI, SI, 6, 1, NbTimeStep);
  writeElementTXT(fp, NbVI, VI, 6, 3, NbTimeStep);
  writeElementTXT(fp, NbTI, TI, 6, 9, NbTimeStep);
  writeElementTXT(fp, NbSY, SY, 5, 1, NbTimeStep);
  writeElementTXT(fp, NbVY, VY, 5, 3, NbTimeStep);
  writeElementTXT(fp, NbTY, TY, 5, 9, NbTimeStep);

  fclose(fp);
  return true;
}

class pVertex{
 public:
  int Num;
  double X, Y, Z;
  pVertex() : Num(0), X(0.), Y(0.), Z(0.) {}
  pVertex(double x, double y, double z) : Num(0), X(x), Y(y), Z(z) {}
};

class pVertexLessThan{
 public:
  bool operator()(const pVertex ent1, const pVertex ent2) const
  {
    double tol = CTX.lc * 1.e-10 ;
    if(ent1.X - ent2.X  >  tol) return true;
    if(ent1.X - ent2.X  < -tol) return false;
    if(ent1.Y - ent2.Y  >  tol) return true;
    if(ent1.Y - ent2.Y  < -tol) return false;
    if(ent1.Z - ent2.Z  >  tol) return true;
    return false;
  }
};

static void getNodeMSH(int nbelm, List_T *list, int nbnod, int nbcomp, 
		       std::set<pVertex, pVertexLessThan> *nodes,
		       int *numelm)
{
  if(!nbelm) return;
  int nb = List_Nbr(list) / nbelm;
  for(int i = 0; i < List_Nbr(list); i+=nb){
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbnod);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbnod);
    for(int j = 0; j < nbnod; j++) {
      pVertex n(x[j], y[j], z[j]);
      std::set<pVertex, pVertexLessThan>::iterator it = nodes->find(n);
      if(it == nodes->end()){
	n.Num = nodes->size() + 1;
	nodes->insert(n);
      }
    }
    (*numelm)++;
  }
}

static void writeElementMSH(FILE *fp, int num, int nbnod, pVertex nod[8], 
			    int nbcomp, double *vals, int dim)
{
  // compute average value in elm
  double d = 0.;
  for(int k = 0; k < nbnod; k++) {
    double *v = &vals[nbcomp * k];
    switch(nbcomp) {
    case 1: // scalar
      d += v[0];
      break;
    case 3 : // vector
      d += sqrt(DSQR(v[0]) + DSQR(v[1]) + DSQR(v[2]));
      break;
    case 9 : // tensor
      d += ComputeVonMises(v);
      break;
    }
  }
  d /= (double)nbnod;

  // assign val as elementary region number
  int ele = (int)fabs(d), phys = 1;
  
  switch(dim){
  case 0:
    fprintf(fp, "%d 15 %d %d 1 %d\n", num, phys, ele, nod[0].Num);
    break;
  case 1:
    fprintf(fp, "%d 1 %d %d 2 %d %d\n", num, phys, ele, nod[0].Num, nod[1].Num);
    break;
  case 2:
    if(nbnod == 3)
      fprintf(fp, "%d 2 %d %d 3 %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num);
    else
      fprintf(fp, "%d 3 %d %d 4 %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num);
    break;
  case 3:
  default:
    if(nbnod == 4)
      fprintf(fp, "%d 4 %d %d 4 %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num);
    else if(nbnod == 5)
      fprintf(fp, "%d 7 %d %d 5 %d %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num, nod[4].Num);
    else if(nbnod == 6)
      fprintf(fp, "%d 6 %d %d 6 %d %d %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num, nod[4].Num, 
	      nod[5].Num);
    else
      fprintf(fp, "%d 5 %d %d 8 %d %d %d %d %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num, nod[4].Num, 
	      nod[5].Num, nod[6].Num, nod[7].Num);
    break;
  }
}

static void writeElementsMSH(FILE *fp, int nbelm, List_T *list,
			     int nbnod, int nbcomp, int dim, 
			     std::set<pVertex, pVertexLessThan> *nodes,
			     int *numelm)
{
  if(!nbelm) return;
  pVertex nod[8];
  int nb = List_Nbr(list) / nbelm;
  for(int i = 0; i < List_Nbr(list); i+=nb){
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbnod);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbnod);
    double *v = (double *)List_Pointer_Fast(list, i + 3 * nbnod);
    for(int j = 0; j < nbnod; j++) {
      pVertex n(x[j], y[j], z[j]);
      std::set<pVertex, pVertexLessThan>::iterator it = nodes->find(n);
      if(it == nodes->end()){
	Msg(GERROR, "Unknown node in element");
	return;
      }
      else{
	nod[j] = (pVertex)(*it);
      }
    }
    (*numelm)++;
    writeElementMSH(fp, *numelm, nbnod, nod, nbcomp, v, dim);
  }
}

bool PViewDataList::writeMSH(std::string name)
{
  FILE *fp = fopen(name.c_str(), "w");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", name.c_str());
    return false;
  }

  std::set<pVertex, pVertexLessThan> nodes;
  int numelm = 0;
  getNodeMSH(NbSP, SP, 1, 1, &nodes, &numelm);
  getNodeMSH(NbVP, VP, 1, 3, &nodes, &numelm);
  getNodeMSH(NbTP, TP, 1, 9, &nodes, &numelm);
  getNodeMSH(NbSL, SL, 2, 1, &nodes, &numelm);
  getNodeMSH(NbVL, VL, 2, 3, &nodes, &numelm);
  getNodeMSH(NbTL, TL, 2, 9, &nodes, &numelm);
  getNodeMSH(NbST, ST, 3, 1, &nodes, &numelm);
  getNodeMSH(NbVT, VT, 3, 3, &nodes, &numelm);
  getNodeMSH(NbTT, TT, 3, 9, &nodes, &numelm);
  getNodeMSH(NbSQ, SQ, 4, 1, &nodes, &numelm);
  getNodeMSH(NbVQ, VQ, 4, 3, &nodes, &numelm);
  getNodeMSH(NbTQ, TQ, 4, 9, &nodes, &numelm);
  getNodeMSH(NbSS, SS, 4, 1, &nodes, &numelm);
  getNodeMSH(NbVS, VS, 4, 3, &nodes, &numelm);
  getNodeMSH(NbTS, TS, 4, 9, &nodes, &numelm);
  getNodeMSH(NbSH, SH, 8, 1, &nodes, &numelm);
  getNodeMSH(NbVH, VH, 8, 3, &nodes, &numelm);
  getNodeMSH(NbTH, TH, 8, 9, &nodes, &numelm);
  getNodeMSH(NbSI, SI, 6, 1, &nodes, &numelm);
  getNodeMSH(NbVI, VI, 6, 3, &nodes, &numelm);
  getNodeMSH(NbTI, TI, 6, 9, &nodes, &numelm);
  getNodeMSH(NbSY, SY, 5, 1, &nodes, &numelm);
  getNodeMSH(NbVY, VY, 5, 3, &nodes, &numelm);
  getNodeMSH(NbTY, TY, 5, 9, &nodes, &numelm);

  fprintf(fp, "$NOD\n");
  fprintf(fp, "%d\n", (int)nodes.size());
  std::set<pVertex, pVertexLessThan>::iterator it = nodes.begin();
  for(; it != nodes.end(); ++it){
    pVertex n = (pVertex)(*it);
    fprintf(fp, "%d %.16g %.16g %.16g\n", n.Num, n.X, n.Y, n.Z);
  }
  fprintf(fp, "$ENDNOD\n");

  fprintf(fp, "$ELM\n");
  fprintf(fp, "%d\n", numelm);
  numelm = 0;
  writeElementsMSH(fp, NbSP, SP, 1, 1, 0, &nodes, &numelm);
  writeElementsMSH(fp, NbVP, VP, 1, 3, 0, &nodes, &numelm);
  writeElementsMSH(fp, NbTP, TP, 1, 9, 0, &nodes, &numelm);
  writeElementsMSH(fp, NbSL, SL, 2, 1, 1, &nodes, &numelm);
  writeElementsMSH(fp, NbVL, VL, 2, 3, 1, &nodes, &numelm);
  writeElementsMSH(fp, NbTL, TL, 2, 9, 1, &nodes, &numelm);
  writeElementsMSH(fp, NbST, ST, 3, 1, 2, &nodes, &numelm);
  writeElementsMSH(fp, NbVT, VT, 3, 3, 2, &nodes, &numelm);
  writeElementsMSH(fp, NbTT, TT, 3, 9, 2, &nodes, &numelm);
  writeElementsMSH(fp, NbSQ, SQ, 4, 1, 2, &nodes, &numelm);
  writeElementsMSH(fp, NbVQ, VQ, 4, 3, 2, &nodes, &numelm);
  writeElementsMSH(fp, NbTQ, TQ, 4, 9, 2, &nodes, &numelm);
  writeElementsMSH(fp, NbSS, SS, 4, 1, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbVS, VS, 4, 3, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbTS, TS, 4, 9, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbSH, SH, 8, 1, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbVH, VH, 8, 3, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbTH, TH, 8, 9, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbSI, SI, 6, 1, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbVI, VI, 6, 3, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbTI, TI, 6, 9, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbSY, SY, 5, 1, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbVY, VY, 5, 3, 3, &nodes, &numelm);
  writeElementsMSH(fp, NbTY, TY, 5, 9, 3, &nodes, &numelm);
  fprintf(fp, "$ENDELM\n");

  fclose(fp);
  return true;
}
