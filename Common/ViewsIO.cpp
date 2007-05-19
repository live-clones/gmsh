// $Id: ViewsIO.cpp,v 1.10 2007-05-19 22:01:27 geuzaine Exp $
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

#include <set>
#include "Gmsh.h"
#include "Numeric.h"
#include "Views.h"
#include "Context.h"

extern Context_T CTX;

#if defined(HAVE_FLTK)
void UpdateViewsInGUI();
#endif

// Read view from file

int ReadView(char *filename)
{
  FILE *fp = fopen(filename, "rb");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", filename);
    return 0;
  }

  char str[256], name[256];
  int i, nb, format, size, testone, swap, t2l, t3l;
  double version;
  Post_View *v;

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
        return 0;
      }
      if(version < 1.0) {
        Msg(GERROR, "This post-processing file is too old (version %g < 1.0)",
            version);
        return 0;
      }
      if(size == sizeof(double))
        Msg(DEBUG, "Data is in double precision format (size==%d)", size);
      else {
        Msg(GERROR, "Unknown data size (%d) in post-processing file", size);
        return 0;
      }
      if(format == 0)
        format = LIST_FORMAT_ASCII;
      else if(format == 1)
        format = LIST_FORMAT_BINARY;
      else {
        Msg(GERROR, "Unknown format for view");
        return 0;
      }
    }

    if(!strncmp(&str[1], "View", 4)) {
      v = BeginView(0);
      if(version <= 1.0) {
        Msg(DEBUG, "Detected post-processing view format <= 1.0");
        if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &v->NbTimeStep,
		   &v->NbSP, &v->NbVP, &v->NbTP, &v->NbSL, &v->NbVL, &v->NbTL,
		   &v->NbST, &v->NbVT, &v->NbTT, &v->NbSS, &v->NbVS, &v->NbTS)){
	  Msg(GERROR, "Read error");
	  return 0;
	}
        v->NbT2 = t2l = v->NbT3 = t3l = 0;
      }
      else if(version == 1.1) {
        Msg(DEBUG, "Detected post-processing view format 1.1");
        if(!fscanf(fp,
		   "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &v->NbTimeStep, &v->NbSP, &v->NbVP, &v->NbTP, &v->NbSL,
		   &v->NbVL, &v->NbTL, &v->NbST, &v->NbVT, &v->NbTT, &v->NbSS,
		   &v->NbVS, &v->NbTS, &v->NbT2, &t2l, &v->NbT3, &t3l)){
	  Msg(GERROR, "Read error");
	  return 0;
	}
      }
      else if(version == 1.2 || version == 1.3) {
        Msg(DEBUG, "Detected post-processing view format %g", version);
        if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
		   "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &v->NbTimeStep,
		   &v->NbSP, &v->NbVP, &v->NbTP, &v->NbSL, &v->NbVL, &v->NbTL,
		   &v->NbST, &v->NbVT, &v->NbTT, &v->NbSQ, &v->NbVQ, &v->NbTQ,
		   &v->NbSS, &v->NbVS, &v->NbTS, &v->NbSH, &v->NbVH, &v->NbTH,
		   &v->NbSI, &v->NbVI, &v->NbTI, &v->NbSY, &v->NbVY, &v->NbTY,
		   &v->NbT2, &t2l, &v->NbT3, &t3l)){
	  Msg(GERROR, "Read error");
	  return 0;
	}
      }
      else if(version == 1.4) {
        Msg(DEBUG, "Detected post-processing view format 1.4");
        if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
		   "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
		   "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		   name, &v->NbTimeStep,
		   &v->NbSP, &v->NbVP, &v->NbTP, &v->NbSL, &v->NbVL, &v->NbTL,
		   &v->NbST, &v->NbVT, &v->NbTT, &v->NbSQ, &v->NbVQ, &v->NbTQ,
		   &v->NbSS, &v->NbVS, &v->NbTS, &v->NbSH, &v->NbVH, &v->NbTH,
		   &v->NbSI, &v->NbVI, &v->NbTI, &v->NbSY, &v->NbVY, &v->NbTY,
		   &v->NbSL2, &v->NbVL2, &v->NbTL2, &v->NbST2, &v->NbVT2, &v->NbTT2,
		   &v->NbSQ2, &v->NbVQ2, &v->NbTQ2, &v->NbSS2, &v->NbVS2, &v->NbTS2,
		   &v->NbSH2, &v->NbVH2, &v->NbTH2, &v->NbSI2, &v->NbVI2, &v->NbTI2,
		   &v->NbSY2, &v->NbVY2, &v->NbTY2, &v->NbT2, &t2l, &v->NbT3, &t3l)){
	  Msg(GERROR, "Read error");
	  return 0;
	}
      }
      else {
        Msg(GERROR, "Unknown post-processing file format (version %g)",
            version);
        return 0;
      }

      for(i = 0; i < (int)strlen(name); i++)
        if(name[i] == '^')
          name[i] = ' ';

      swap = 0;
      if(format == LIST_FORMAT_BINARY) {
        if(!fread(&testone, sizeof(int), 1, fp)){
	  Msg(GERROR, "Read error");
	  return 0;
	}
        if(testone != 1) {
          Msg(INFO, "Swapping bytes from binary file");
          swap = 1;
        }
      }

      v->DataSize = size;

      // Time values
      v->Time = List_CreateFromFile(v->NbTimeStep, 100, size, fp, format, swap);

      // Note: if nb==0, we still allocates the lists (so that they
      // are ready to be filled later, e.g. in plugins)

#define LCD List_CreateFromFile(nb, 1000, size, fp, format, swap)

      // Points
      nb = v->NbSP ? v->NbSP * (v->NbTimeStep * 1 + 3) : 0; v->SP = LCD;
      nb = v->NbVP ? v->NbVP * (v->NbTimeStep * 3 + 3) : 0; v->VP = LCD;
      nb = v->NbTP ? v->NbTP * (v->NbTimeStep * 9 + 3) : 0; v->TP = LCD;

      // Lines
      nb = v->NbSL ? v->NbSL * (v->NbTimeStep * 2 * 1 + 6) : 0; v->SL = LCD;
      nb = v->NbVL ? v->NbVL * (v->NbTimeStep * 2 * 3 + 6) : 0; v->VL = LCD;
      nb = v->NbTL ? v->NbTL * (v->NbTimeStep * 2 * 9 + 6) : 0; v->TL = LCD;

      // Triangles
      nb = v->NbST ? v->NbST * (v->NbTimeStep * 3 * 1 + 9) : 0; v->ST = LCD;
      nb = v->NbVT ? v->NbVT * (v->NbTimeStep * 3 * 3 + 9) : 0; v->VT = LCD;
      nb = v->NbTT ? v->NbTT * (v->NbTimeStep * 3 * 9 + 9) : 0; v->TT = LCD;

      // Quadrangles
      nb = v->NbSQ ? v->NbSQ * (v->NbTimeStep * 4 * 1 + 12) : 0; v->SQ = LCD;
      nb = v->NbVQ ? v->NbVQ * (v->NbTimeStep * 4 * 3 + 12) : 0; v->VQ = LCD;
      nb = v->NbTQ ? v->NbTQ * (v->NbTimeStep * 4 * 9 + 12) : 0; v->TQ = LCD;

      // Tetrahedra
      nb = v->NbSS ? v->NbSS * (v->NbTimeStep * 4 * 1 + 12) : 0; v->SS = LCD;
      nb = v->NbVS ? v->NbVS * (v->NbTimeStep * 4 * 3 + 12) : 0; v->VS = LCD;
      nb = v->NbTS ? v->NbTS * (v->NbTimeStep * 4 * 9 + 12) : 0; v->TS = LCD;

      // Hexahedra
      nb = v->NbSH ? v->NbSH * (v->NbTimeStep * 8 * 1 + 24) : 0; v->SH = LCD;
      nb = v->NbVH ? v->NbVH * (v->NbTimeStep * 8 * 3 + 24) : 0; v->VH = LCD;
      nb = v->NbTH ? v->NbTH * (v->NbTimeStep * 8 * 9 + 24) : 0; v->TH = LCD;

      // Prisms
      nb = v->NbSI ? v->NbSI * (v->NbTimeStep * 6 * 1 + 18) : 0; v->SI = LCD;
      nb = v->NbVI ? v->NbVI * (v->NbTimeStep * 6 * 3 + 18) : 0; v->VI = LCD;
      nb = v->NbTI ? v->NbTI * (v->NbTimeStep * 6 * 9 + 18) : 0; v->TI = LCD;

      // Pyramids
      nb = v->NbSY ? v->NbSY * (v->NbTimeStep * 5 * 1 + 15) : 0; v->SY = LCD;
      nb = v->NbVY ? v->NbVY * (v->NbTimeStep * 5 * 3 + 15) : 0; v->VY = LCD;
      nb = v->NbTY ? v->NbTY * (v->NbTimeStep * 5 * 9 + 15) : 0; v->TY = LCD;

      // 2nd order Lines
      nb = v->NbSL2 ? v->NbSL2 * (v->NbTimeStep * 3 * 1 + 9) : 0; v->SL2 = LCD;
      nb = v->NbVL2 ? v->NbVL2 * (v->NbTimeStep * 3 * 3 + 9) : 0; v->VL2 = LCD;
      nb = v->NbTL2 ? v->NbTL2 * (v->NbTimeStep * 3 * 9 + 9) : 0; v->TL2 = LCD;

      // 2nd order Triangles
      nb = v->NbST2 ? v->NbST2 * (v->NbTimeStep * 6 * 1 + 18) : 0; v->ST2 = LCD;
      nb = v->NbVT2 ? v->NbVT2 * (v->NbTimeStep * 6 * 3 + 18) : 0; v->VT2 = LCD;
      nb = v->NbTT2 ? v->NbTT2 * (v->NbTimeStep * 6 * 9 + 18) : 0; v->TT2 = LCD;

      // 2nd order Quadrangles
      nb = v->NbSQ2 ? v->NbSQ2 * (v->NbTimeStep * 9 * 1 + 27) : 0; v->SQ2 = LCD;
      nb = v->NbVQ2 ? v->NbVQ2 * (v->NbTimeStep * 9 * 3 + 27) : 0; v->VQ2 = LCD;
      nb = v->NbTQ2 ? v->NbTQ2 * (v->NbTimeStep * 9 * 9 + 27) : 0; v->TQ2 = LCD;

      // 2nd order Tetrahedra
      nb = v->NbSS2 ? v->NbSS2 * (v->NbTimeStep * 10 * 1 + 30) : 0; v->SS2 = LCD;
      nb = v->NbVS2 ? v->NbVS2 * (v->NbTimeStep * 10 * 3 + 30) : 0; v->VS2 = LCD;
      nb = v->NbTS2 ? v->NbTS2 * (v->NbTimeStep * 10 * 9 + 30) : 0; v->TS2 = LCD;

      // 2nd order Hexahedra
      nb = v->NbSH2 ? v->NbSH2 * (v->NbTimeStep * 27 * 1 + 81) : 0; v->SH2 = LCD;
      nb = v->NbVH2 ? v->NbVH2 * (v->NbTimeStep * 27 * 3 + 81) : 0; v->VH2 = LCD;
      nb = v->NbTH2 ? v->NbTH2 * (v->NbTimeStep * 27 * 9 + 81) : 0; v->TH2 = LCD;

      // 2nd order Prisms
      nb = v->NbSI2 ? v->NbSI2 * (v->NbTimeStep * 18 * 1 + 54) : 0; v->SI2 = LCD;
      nb = v->NbVI2 ? v->NbVI2 * (v->NbTimeStep * 18 * 3 + 54) : 0; v->VI2 = LCD;
      nb = v->NbTI2 ? v->NbTI2 * (v->NbTimeStep * 18 * 9 + 54) : 0; v->TI2 = LCD;

      // 2nd order Pyramids
      nb = v->NbSY2 ? v->NbSY2 * (v->NbTimeStep * 14 * 1 + 42) : 0; v->SY2 = LCD;
      nb = v->NbVY2 ? v->NbVY2 * (v->NbTimeStep * 14 * 3 + 42) : 0; v->VY2 = LCD;
      nb = v->NbTY2 ? v->NbTY2 * (v->NbTimeStep * 14 * 9 + 42) : 0; v->TY2 = LCD;

#undef LCD

      // 2D strings
      nb = v->NbT2 ? v->NbT2 * 4 : 0;
      v->T2D = List_CreateFromFile(nb, 100, size, fp, format, swap);
      if(version <= 1.2)
	v->T2C = List_CreateFromFileOld(t2l, 100, sizeof(char), fp, format, swap);
      else
	v->T2C = List_CreateFromFile(t2l, 100, sizeof(char), fp, format, swap);

      // 3D strings
      nb = v->NbT3 ? v->NbT3 * 5 : 0;
      v->T3D = List_CreateFromFile(nb, 100, size, fp, format, swap);
      if(version <= 1.2)
	v->T3C = List_CreateFromFileOld(t3l, 100, sizeof(char), fp, format, swap);
      else
	v->T3C = List_CreateFromFile(t3l, 100, sizeof(char), fp, format, swap);

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
	  name, v->NbTimeStep,
          v->NbSP, List_Nbr(v->SP), v->NbVP, List_Nbr(v->VP), v->NbTP, List_Nbr(v->TP),
          v->NbSL, List_Nbr(v->SL), v->NbVL, List_Nbr(v->VL), v->NbTL, List_Nbr(v->TL),
          v->NbST, List_Nbr(v->ST), v->NbVT, List_Nbr(v->VT), v->NbTT, List_Nbr(v->TT),
          v->NbSQ, List_Nbr(v->SQ), v->NbVQ, List_Nbr(v->VQ), v->NbTQ, List_Nbr(v->TQ),
          v->NbSS, List_Nbr(v->SS), v->NbVS, List_Nbr(v->VS), v->NbTS, List_Nbr(v->TS),
          v->NbSH, List_Nbr(v->SH), v->NbVH, List_Nbr(v->VH), v->NbTH, List_Nbr(v->TH),
          v->NbSI, List_Nbr(v->SI), v->NbVI, List_Nbr(v->VI), v->NbTI, List_Nbr(v->TI),
          v->NbSY, List_Nbr(v->SY), v->NbVY, List_Nbr(v->VY), v->NbTY, List_Nbr(v->TY),
          v->NbSL2, List_Nbr(v->SL2), v->NbVL2, List_Nbr(v->VL2), v->NbTL2, List_Nbr(v->TL2),
          v->NbST2, List_Nbr(v->ST2), v->NbVT2, List_Nbr(v->VT2), v->NbTT2, List_Nbr(v->TT2),
          v->NbSQ2, List_Nbr(v->SQ2), v->NbVQ2, List_Nbr(v->VQ2), v->NbTQ2, List_Nbr(v->TQ2),
          v->NbSS2, List_Nbr(v->SS2), v->NbVS2, List_Nbr(v->VS2), v->NbTS2, List_Nbr(v->TS2),
          v->NbSH2, List_Nbr(v->SH2), v->NbVH2, List_Nbr(v->VH2), v->NbTH2, List_Nbr(v->TH2),
          v->NbSI2, List_Nbr(v->SI2), v->NbVI2, List_Nbr(v->VI2), v->NbTI2, List_Nbr(v->TI2),
          v->NbSY2, List_Nbr(v->SY2), v->NbVY2, List_Nbr(v->VY2), v->NbTY2, List_Nbr(v->TY2),
	  v->NbT2, List_Nbr(v->T2D), List_Nbr(v->T2C), 
	  v->NbT3, List_Nbr(v->T3D), List_Nbr(v->T3C));
      
      // don't update the ui after each view, but only at the end
      EndView(v, 0, filename, name); 
    }

    do {
      if(!fgets(str, 256, fp) || feof(fp))
        Msg(GERROR, "Prematured end of file");
    } while(str[0] != '$');

  }

#if defined(HAVE_FLTK)
  UpdateViewsInGUI();
#endif

  return 1;
}

// Write view to file in Parsed, ASCII or Binary format

static void write_parsed_time(List_T *list, FILE *fp)
{
  if(List_Nbr(list) > 1) {
    fprintf(fp, "TIME{");
    for(int i = 0; i < List_Nbr(list); i ++) {
      if(i) fprintf(fp, ",");
      fprintf(fp, "%.16g", *(double *)List_Pointer(list, i));
    }
    fprintf(fp, "};\n");
  }
}

static void write_parsed_elements(char *str, int nbnod, int nb, List_T *list, FILE *fp)
{
  if(nb) {
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

static void write_parsed_strings(int nbc, int nb, List_T *TD, List_T *TC, FILE *fp)
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

void WriteViewPOS(Post_View *v, FILE *file, int binary=0, int parsed=1, int append=0)
{
  char name[256];
  int f, One = 1;

  if(!parsed && !append){
    fprintf(file, "$PostFormat /* Gmsh 1.3, %s */\n",
	    binary ? "binary" : "ascii");
    fprintf(file, "1.3 %d %d\n", binary, (int)sizeof(double));
    fprintf(file, "$EndPostFormat\n");
  }

  strcpy(name, v->Name);
  for(int i = 0; i < (int)strlen(name); i++)
    if(name[i] == ' ') name[i] = '^';

  if(!parsed){
    fprintf(file, "$View /* %s */\n", v->Name);
    fprintf(file, "%s ", name);
    fprintf(file, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
	    "%d %d %d %d %d %d %d %d %d %d %d %d\n",
	    List_Nbr(v->Time),
	    v->NbSP, v->NbVP, v->NbTP, v->NbSL, v->NbVL, v->NbTL,
	    v->NbST, v->NbVT, v->NbTT, v->NbSQ, v->NbVQ, v->NbTQ,
	    v->NbSS, v->NbVS, v->NbTS, v->NbSH, v->NbVH, v->NbTH,
	    v->NbSI, v->NbVI, v->NbTI, v->NbSY, v->NbVY, v->NbTY,
	    v->NbT2, List_Nbr(v->T2C), v->NbT3, List_Nbr(v->T3C));
    if(binary) {
      f = LIST_FORMAT_BINARY;
      if(!fwrite(&One, sizeof(int), 1, file)){
	Msg(GERROR, "Write error");
	return;
      }
    }
    else
      f = LIST_FORMAT_ASCII;
    List_WriteToFile(v->Time, file, f);
    List_WriteToFile(v->SP, file, f);
    List_WriteToFile(v->VP, file, f);
    List_WriteToFile(v->TP, file, f);
    List_WriteToFile(v->SL, file, f);
    List_WriteToFile(v->VL, file, f);
    List_WriteToFile(v->TL, file, f);
    List_WriteToFile(v->ST, file, f);
    List_WriteToFile(v->VT, file, f);
    List_WriteToFile(v->TT, file, f);
    List_WriteToFile(v->SQ, file, f);
    List_WriteToFile(v->VQ, file, f);
    List_WriteToFile(v->TQ, file, f);
    List_WriteToFile(v->SS, file, f);
    List_WriteToFile(v->VS, file, f);
    List_WriteToFile(v->TS, file, f);
    List_WriteToFile(v->SH, file, f);
    List_WriteToFile(v->VH, file, f);
    List_WriteToFile(v->TH, file, f);
    List_WriteToFile(v->SI, file, f);
    List_WriteToFile(v->VI, file, f);
    List_WriteToFile(v->TI, file, f);
    List_WriteToFile(v->SY, file, f);
    List_WriteToFile(v->VY, file, f);
    List_WriteToFile(v->TY, file, f);
    List_WriteToFile(v->T2D, file, f);
    List_WriteToFile(v->T2C, file, f);
    List_WriteToFile(v->T3D, file, f);
    List_WriteToFile(v->T3C, file, f);
    fprintf(file, "\n");
    fprintf(file, "$EndView\n");
  }
  else{
    fprintf(file, "View \"%s\" {\n", v->Name);
    write_parsed_time(v->Time, file);
    write_parsed_elements("SP", 1, v->NbSP, v->SP, file);
    write_parsed_elements("VP", 1, v->NbVP, v->VP, file);
    write_parsed_elements("TP", 1, v->NbTP, v->TP, file);
    write_parsed_elements("SL", 2, v->NbSL, v->SL, file);
    write_parsed_elements("VL", 2, v->NbVL, v->VL, file);
    write_parsed_elements("TL", 2, v->NbTL, v->TL, file);
    write_parsed_elements("ST", 3, v->NbST, v->ST, file);
    write_parsed_elements("VT", 3, v->NbVT, v->VT, file);
    write_parsed_elements("TT", 3, v->NbTT, v->TT, file);
    write_parsed_elements("SQ", 4, v->NbSQ, v->SQ, file);
    write_parsed_elements("VQ", 4, v->NbVQ, v->VQ, file);
    write_parsed_elements("TQ", 4, v->NbTQ, v->TQ, file);
    write_parsed_elements("SS", 4, v->NbSS, v->SS, file);
    write_parsed_elements("VS", 4, v->NbVS, v->VS, file);
    write_parsed_elements("TS", 4, v->NbTS, v->TS, file);
    write_parsed_elements("SH", 8, v->NbSH, v->SH, file);
    write_parsed_elements("VH", 8, v->NbVH, v->VH, file);
    write_parsed_elements("TH", 8, v->NbTH, v->TH, file);
    write_parsed_elements("SI", 6, v->NbSI, v->SI, file);
    write_parsed_elements("VI", 6, v->NbVI, v->VI, file);
    write_parsed_elements("TI", 6, v->NbTI, v->TI, file);
    write_parsed_elements("SY", 5, v->NbSY, v->SY, file);
    write_parsed_elements("VY", 5, v->NbVY, v->VY, file);
    write_parsed_elements("TY", 5, v->NbTY, v->TY, file);
    write_parsed_strings(4, v->NbT2, v->T2D, v->T2C, file);
    write_parsed_strings(5, v->NbT3, v->T3D, v->T3C, file);
    fprintf(file, "};\n");
  }
}

// Write view to file in STL format

static void write_stl(FILE *file, int nbelm, List_T *list, int nbnod)
{
  if(nbelm){
    int nb = List_Nbr(list) / nbelm;
    for(int i = 0; i < List_Nbr(list); i+=nb){
      double *x = (double*)List_Pointer(list, i);
      double n[3];
      normal3points(x[0], x[3], x[6],
		    x[1], x[4], x[7],
		    x[2], x[5], x[8], n);
      if(nbnod == 3){
	fprintf(file, "facet normal %g %g %g\n", n[0], n[1], n[2]);
	fprintf(file, "  outer loop\n");
	fprintf(file, "    vertex %g %g %g\n", x[0], x[3], x[6]);
	fprintf(file, "    vertex %g %g %g\n", x[1], x[4], x[7]);
	fprintf(file, "    vertex %g %g %g\n", x[2], x[5], x[8]);
	fprintf(file, "  endloop\n");
	fprintf(file, "endfacet\n");
      }
      else{
	fprintf(file, "facet normal %g %g %g\n", n[0], n[1], n[2]);
	fprintf(file, "  outer loop\n");
	fprintf(file, "    vertex %g %g %g\n", x[0], x[4], x[8]);
	fprintf(file, "    vertex %g %g %g\n", x[1], x[5], x[9]);
	fprintf(file, "    vertex %g %g %g\n", x[2], x[6], x[10]);
	fprintf(file, "  endloop\n");
	fprintf(file, "endfacet\n");
	fprintf(file, "facet normal %g %g %g\n", n[0], n[1], n[2]);
	fprintf(file, "  outer loop\n");
	fprintf(file, "    vertex %g %g %g\n", x[0], x[4], x[8]);
	fprintf(file, "    vertex %g %g %g\n", x[2], x[6], x[10]);
	fprintf(file, "    vertex %g %g %g\n", x[3], x[7], x[11]);
	fprintf(file, "  endloop\n");
	fprintf(file, "endfacet\n");
      }
    }
  }
}

void WriteViewSTL(Post_View *v, FILE *file)
{
  if(!v->NbST && !v->NbVT && !v->NbTT &&
     !v->NbSQ && !v->NbVQ && !v->NbTQ){
    Msg(GERROR, "No surface elements to save");
    return;
  }

  fprintf(file, "solid Created by Gmsh\n");
  write_stl(file, v->NbST, v->ST, 3);
  write_stl(file, v->NbVT, v->VT, 3);
  write_stl(file, v->NbTT, v->TT, 3);
  write_stl(file, v->NbSQ, v->SQ, 4);
  write_stl(file, v->NbVQ, v->VQ, 4);
  write_stl(file, v->NbTQ, v->TQ, 4);
  fprintf(file, "endsolid Created by Gmsh\n");
}

// Write view to file in Text format (should change this to have 2
// choices: "Tabular (By Element)" and "Tabular (By Time Step)")

static void write_txt(FILE *file, int nbelm, List_T *list,
		      int nbnod, int nbcomp, int nbtime)
{
  if(nbelm){
    int nb = List_Nbr(list) / nbelm;
    for(int i = 0; i < List_Nbr(list); i+=nb){
      double *x = (double*)List_Pointer(list, i);
      for(int j = 0; j < nbnod*(3+nbcomp*nbtime); j++)
	fprintf(file, "%.16g ", x[j]);
      fprintf(file, "\n");
    }
    fprintf(file, "\n");
  }
}

void WriteViewTXT(Post_View *v, FILE *file)
{
  write_txt(file, v->NbSP, v->SP, 1, 1, v->NbTimeStep);
  write_txt(file, v->NbVP, v->VP, 1, 3, v->NbTimeStep);
  write_txt(file, v->NbTP, v->TP, 1, 9, v->NbTimeStep);
  write_txt(file, v->NbSL, v->SL, 2, 1, v->NbTimeStep);
  write_txt(file, v->NbVL, v->VL, 2, 3, v->NbTimeStep);
  write_txt(file, v->NbTL, v->TL, 2, 9, v->NbTimeStep);
  write_txt(file, v->NbST, v->ST, 3, 1, v->NbTimeStep);
  write_txt(file, v->NbVT, v->VT, 3, 3, v->NbTimeStep);
  write_txt(file, v->NbTT, v->TT, 3, 9, v->NbTimeStep);
  write_txt(file, v->NbSQ, v->SQ, 4, 1, v->NbTimeStep);
  write_txt(file, v->NbVQ, v->VQ, 4, 3, v->NbTimeStep);
  write_txt(file, v->NbTQ, v->TQ, 4, 9, v->NbTimeStep);
  write_txt(file, v->NbSS, v->SS, 4, 1, v->NbTimeStep);
  write_txt(file, v->NbVS, v->VS, 4, 3, v->NbTimeStep);
  write_txt(file, v->NbTS, v->TS, 4, 9, v->NbTimeStep);
  write_txt(file, v->NbSH, v->SH, 8, 1, v->NbTimeStep);
  write_txt(file, v->NbVH, v->VH, 8, 3, v->NbTimeStep);
  write_txt(file, v->NbTH, v->TH, 8, 9, v->NbTimeStep);
  write_txt(file, v->NbSI, v->SI, 6, 1, v->NbTimeStep);
  write_txt(file, v->NbVI, v->VI, 6, 3, v->NbTimeStep);
  write_txt(file, v->NbTI, v->TI, 6, 9, v->NbTimeStep);
  write_txt(file, v->NbSY, v->SY, 5, 1, v->NbTimeStep);
  write_txt(file, v->NbVY, v->VY, 5, 3, v->NbTimeStep);
  write_txt(file, v->NbTY, v->TY, 5, 9, v->NbTimeStep);
}

// Write view to file in MSH format

class Nod{
 public:
  int Num;
  double X, Y, Z;
  Nod() : Num(0), X(0.), Y(0.), Z(0.) {}
  Nod(double x, double y, double z) : Num(0), X(x), Y(y), Z(z) {}
};

class NodCompPos{
 public:
  bool operator()(const Nod ent1, const Nod ent2) const
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

static void get_nod(int nbelm, List_T *list, int nbnod, int nbcomp, 
		    std::set<Nod, NodCompPos> *nodes,
		    int *numelm)
{
  if(nbelm){
    int nb = List_Nbr(list) / nbelm;
    for(int i = 0; i < List_Nbr(list); i+=nb){
      double *x = (double *)List_Pointer_Fast(list, i);
      double *y = (double *)List_Pointer_Fast(list, i + nbnod);
      double *z = (double *)List_Pointer_Fast(list, i + 2 * nbnod);
      for(int j = 0; j < nbnod; j++) {
	Nod n(x[j], y[j], z[j]);
	std::set<Nod, NodCompPos>::iterator it = nodes->find(n);
	if(it == nodes->end()){
	  n.Num = nodes->size() + 1;
	  nodes->insert(n);
	}
      }
      (*numelm)++;
    }
  }
}

static void print_elm(FILE *file, int num, int nbnod, Nod nod[8], 
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
    fprintf(file, "%d 15 %d %d 1 %d\n", num, phys, ele, nod[0].Num);
    break;
  case 1:
    fprintf(file, "%d 1 %d %d 2 %d %d\n", num, phys, ele, nod[0].Num, nod[1].Num);
    break;
  case 2:
    if(nbnod == 3)
      fprintf(file, "%d 2 %d %d 3 %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num);
    else
      fprintf(file, "%d 3 %d %d 4 %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num);
    break;
  case 3:
  default:
    if(nbnod == 4)
      fprintf(file, "%d 4 %d %d 4 %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num);
    else if(nbnod == 5)
      fprintf(file, "%d 7 %d %d 5 %d %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num, nod[4].Num);
    else if(nbnod == 6)
      fprintf(file, "%d 6 %d %d 6 %d %d %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num, nod[4].Num, 
	      nod[5].Num);
    else
      fprintf(file, "%d 5 %d %d 8 %d %d %d %d %d %d %d %d\n", num, phys, ele, 
	      nod[0].Num, nod[1].Num, nod[2].Num, nod[3].Num, nod[4].Num, 
	      nod[5].Num, nod[6].Num, nod[7].Num);
    break;
  }
}

static void print_elms(FILE *file, int nbelm, List_T *list,
		       int nbnod, int nbcomp, int dim, 
		       std::set<Nod, NodCompPos> *nodes,
		       int *numelm)
{
  Nod nod[8];

  if(nbelm){
    int nb = List_Nbr(list) / nbelm;
    for(int i = 0; i < List_Nbr(list); i+=nb){
      double *x = (double *)List_Pointer_Fast(list, i);
      double *y = (double *)List_Pointer_Fast(list, i + nbnod);
      double *z = (double *)List_Pointer_Fast(list, i + 2 * nbnod);
      double *v = (double *)List_Pointer_Fast(list, i + 3 * nbnod);
      for(int j = 0; j < nbnod; j++) {
	Nod n(x[j], y[j], z[j]);
	std::set<Nod, NodCompPos>::iterator it = nodes->find(n);
	if(it == nodes->end()){
	  Msg(GERROR, "Unknown node in element");
	  return;
	}
	else{
	  nod[j] = (Nod)(*it);
	}
      }
      (*numelm)++;
      print_elm(file, *numelm, nbnod, nod, nbcomp, v, dim);
    }
  }
}

void WriteViewMSH(Post_View *v, FILE *file)
{
  std::set<Nod, NodCompPos> nodes;
  int numelm = 0;
  get_nod(v->NbSP, v->SP, 1, 1, &nodes, &numelm);
  get_nod(v->NbVP, v->VP, 1, 3, &nodes, &numelm);
  get_nod(v->NbTP, v->TP, 1, 9, &nodes, &numelm);
  get_nod(v->NbSL, v->SL, 2, 1, &nodes, &numelm);
  get_nod(v->NbVL, v->VL, 2, 3, &nodes, &numelm);
  get_nod(v->NbTL, v->TL, 2, 9, &nodes, &numelm);
  get_nod(v->NbST, v->ST, 3, 1, &nodes, &numelm);
  get_nod(v->NbVT, v->VT, 3, 3, &nodes, &numelm);
  get_nod(v->NbTT, v->TT, 3, 9, &nodes, &numelm);
  get_nod(v->NbSQ, v->SQ, 4, 1, &nodes, &numelm);
  get_nod(v->NbVQ, v->VQ, 4, 3, &nodes, &numelm);
  get_nod(v->NbTQ, v->TQ, 4, 9, &nodes, &numelm);
  get_nod(v->NbSS, v->SS, 4, 1, &nodes, &numelm);
  get_nod(v->NbVS, v->VS, 4, 3, &nodes, &numelm);
  get_nod(v->NbTS, v->TS, 4, 9, &nodes, &numelm);
  get_nod(v->NbSH, v->SH, 8, 1, &nodes, &numelm);
  get_nod(v->NbVH, v->VH, 8, 3, &nodes, &numelm);
  get_nod(v->NbTH, v->TH, 8, 9, &nodes, &numelm);
  get_nod(v->NbSI, v->SI, 6, 1, &nodes, &numelm);
  get_nod(v->NbVI, v->VI, 6, 3, &nodes, &numelm);
  get_nod(v->NbTI, v->TI, 6, 9, &nodes, &numelm);
  get_nod(v->NbSY, v->SY, 5, 1, &nodes, &numelm);
  get_nod(v->NbVY, v->VY, 5, 3, &nodes, &numelm);
  get_nod(v->NbTY, v->TY, 5, 9, &nodes, &numelm);

  fprintf(file, "$NOD\n");
  fprintf(file, "%d\n", (int)nodes.size());
  std::set<Nod, NodCompPos>::const_iterator it = nodes.begin();
  std::set<Nod, NodCompPos>::const_iterator ite = nodes.end();
  for(; it != ite; ++it){
    Nod n = (Nod)(*it);
    fprintf(file, "%d %.16g %.16g %.16g\n", n.Num, n.X, n.Y, n.Z);
  }
  fprintf(file, "$ENDNOD\n");

  fprintf(file, "$ELM\n");
  fprintf(file, "%d\n", numelm);
  numelm = 0;
  print_elms(file, v->NbSP, v->SP, 1, 1, 0, &nodes, &numelm);
  print_elms(file, v->NbVP, v->VP, 1, 3, 0, &nodes, &numelm);
  print_elms(file, v->NbTP, v->TP, 1, 9, 0, &nodes, &numelm);
  print_elms(file, v->NbSL, v->SL, 2, 1, 1, &nodes, &numelm);
  print_elms(file, v->NbVL, v->VL, 2, 3, 1, &nodes, &numelm);
  print_elms(file, v->NbTL, v->TL, 2, 9, 1, &nodes, &numelm);
  print_elms(file, v->NbST, v->ST, 3, 1, 2, &nodes, &numelm);
  print_elms(file, v->NbVT, v->VT, 3, 3, 2, &nodes, &numelm);
  print_elms(file, v->NbTT, v->TT, 3, 9, 2, &nodes, &numelm);
  print_elms(file, v->NbSQ, v->SQ, 4, 1, 2, &nodes, &numelm);
  print_elms(file, v->NbVQ, v->VQ, 4, 3, 2, &nodes, &numelm);
  print_elms(file, v->NbTQ, v->TQ, 4, 9, 2, &nodes, &numelm);
  print_elms(file, v->NbSS, v->SS, 4, 1, 3, &nodes, &numelm);
  print_elms(file, v->NbVS, v->VS, 4, 3, 3, &nodes, &numelm);
  print_elms(file, v->NbTS, v->TS, 4, 9, 3, &nodes, &numelm);
  print_elms(file, v->NbSH, v->SH, 8, 1, 3, &nodes, &numelm);
  print_elms(file, v->NbVH, v->VH, 8, 3, 3, &nodes, &numelm);
  print_elms(file, v->NbTH, v->TH, 8, 9, 3, &nodes, &numelm);
  print_elms(file, v->NbSI, v->SI, 6, 1, 3, &nodes, &numelm);
  print_elms(file, v->NbVI, v->VI, 6, 3, 3, &nodes, &numelm);
  print_elms(file, v->NbTI, v->TI, 6, 9, 3, &nodes, &numelm);
  print_elms(file, v->NbSY, v->SY, 5, 1, 3, &nodes, &numelm);
  print_elms(file, v->NbVY, v->VY, 5, 3, 3, &nodes, &numelm);
  print_elms(file, v->NbTY, v->TY, 5, 9, 3, &nodes, &numelm);
  fprintf(file, "$ENDELM\n");
}

// Write view to file

void WriteView(Post_View *v, char *filename, int format, int append)
{
  FILE *file;
  int binary = (format == 1) ? 1 : 0;
  int parsed = (format == 2);
  int stl = (format == 3);
  int txt = (format == 4);
  int msh = (format == 5);

  if(filename) {
    file = fopen(filename, append ? (binary ? "ab" : "a") : (binary ? "wb" : "w"));
    if(!file) {
      Msg(GERROR, "Unable to open file '%s'", filename);
      return;
    }
    if(!append)
      Msg(STATUS2, "Writing '%s'", filename);
  }
  else
    file = stdout;

  if(stl)
    WriteViewSTL(v, file);
  else if(txt)
    WriteViewTXT(v, file);
  else if(msh)
    WriteViewMSH(v, file);
  else
    WriteViewPOS(v, file, binary, parsed, append);
  
  if(filename) {
    fclose(file);
    Msg(STATUS2, "Wrote '%s'", filename);
  }
 
}
