// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <set>
#include "PViewDataList.h"
#include "MElement.h"
#include "Numeric.h"
#include "StringUtils.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "MVertexPositionSet.h"
#include "Context.h"
#include "adaptiveData.h"

static void dVecRead(std::vector<double> &v, int n, FILE *fp,
                     bool binary, int swap)
{
  if(!n) return;
  v.resize(n);
  if(binary){
    if(!fread(&v[0], sizeof(double), n, fp))
      Msg::Error("Read error");
    if(swap) SwapBytes((char*)&v[0], sizeof(double), n);
  }
  else{
    for(int i = 0; i < n; i++){
      if(!fscanf(fp, "%lf", &v[i])){
        Msg::Error("Read error");
        break;
      }
    }
  }
}

static void cVecRead(std::vector<char> &v, int n, FILE *fp,
                     bool binary, int swap, bool oldStyle)
{
  if(!n) return;
  v.resize(n);
  if(binary){
    if(!fread(&v[0], sizeof(char), n, fp))
      Msg::Error("Read error");
    if(swap) SwapBytes((char*)&v[0], sizeof(char), n);
  }
  else{
    if(oldStyle){
      for(int i = 0; i < n; i++){
        if(!fscanf(fp, "%c", &v[i])){
          Msg::Error("Read error");
          break;
        }
        if(v[i] == '^') v[i] = '\0';
      }
    }
    else{
      for(int i = 0; i < n; i++){
        char c = (char)fgetc(fp);
        if(c == EOF){
          Msg::Error("Read error");
          break;
        }
        else{
          v[i] = c;
        }
      }
    }
  }
}

static void dVecWrite(std::vector<double> &v, FILE *fp, bool binary)
{
  if(v.empty()) return;
  if(binary)
    fwrite(&v[0], sizeof(double), v.size(), fp);
  else
    for(unsigned i = 0; i < v.size(); i++)
      fprintf(fp, " %.16g", v[i]);
}

static void cVecWrite(std::vector<char> &v, FILE *fp, bool binary)
{
  if(v.empty()) return;
  if(binary)
    fwrite(&v[0], sizeof(char), v.size(), fp);
  else
    for(unsigned i = 0; i < v.size(); i++)
      fputc(v[i], fp);
}

bool PViewDataList::readPOS(FILE *fp, double version, bool binary)
{
  char name[256];
  int t2l, t3l;

  int NbSL2 = 0, NbVL2 = 0, NbTL2 = 0, NbST2 = 0, NbVT2 = 0, NbTT2 = 0;
  int NbSQ2 = 0, NbVQ2 = 0, NbTQ2 = 0, NbSS2 = 0, NbVS2 = 0, NbTS2 = 0;
  int NbSH2 = 0, NbVH2 = 0, NbTH2 = 0, NbSI2 = 0, NbVI2 = 0, NbTI2 = 0;
  int NbSY2 = 0, NbVY2 = 0, NbTY2 = 0;
  std::vector<double> SL2, VL2, TL2, ST2, VT2, TT2;
  std::vector<double> SQ2, VQ2, TQ2, SS2, VS2, TS2;
  std::vector<double> SH2, VH2, TH2, SI2, VI2, TI2;
  std::vector<double> SY2, VY2, TY2;

  if(version <= 1.0) {
    Msg::Debug("Detected post-processing view format <= 1.0");
    if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
               name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
               &NbST, &NbVT, &NbTT, &NbSS, &NbVS, &NbTS)){
      Msg::Error("Read error");
      return false;
    }
    NbT2 = t2l = NbT3 = t3l = 0;
  }
  else if(version == 1.1) {
    Msg::Debug("Detected post-processing view format 1.1");
    if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
               name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
               &NbST, &NbVT, &NbTT, &NbSS, &NbVS, &NbTS, &NbT2, &t2l, &NbT3,
               &t3l)){
      Msg::Error("Read error");
      return false;
    }
  }
  else if(version == 1.2 || version == 1.3) {
    Msg::Debug("Detected post-processing view format %g", version);
    if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
               "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
               name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
               &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ, &NbSS, &NbVS, &NbTS,
               &NbSH, &NbVH, &NbTH, &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
               &NbT2, &t2l, &NbT3, &t3l)){
      Msg::Error("Read error");
      return false;
    }
  }
  else if(version == 1.4) {
    Msg::Debug("Detected post-processing view format 1.4");
    if(!fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
               "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
               "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
               name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
               &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ, &NbSS, &NbVS, &NbTS,
               &NbSH, &NbVH, &NbTH, &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
               &NbSL2, &NbVL2, &NbTL2, &NbST2, &NbVT2, &NbTT2, &NbSQ2, &NbVQ2,
               &NbTQ2, &NbSS2, &NbVS2, &NbTS2, &NbSH2, &NbVH2, &NbTH2, &NbSI2,
               &NbVI2, &NbTI2, &NbSY2, &NbVY2, &NbTY2, &NbT2, &t2l, &NbT3, &t3l)){
      Msg::Error("Read error");
      return false;
    }
  }
  else {
    Msg::Error("Unknown post-processing file format (version %g)", version);
    return false;
  }

  for(int i = 0; i < (int)strlen(name); i++)
    if(name[i] == '^')
      name[i] = ' ';

  int swap = 0;
  if(binary) {
    int testone;
    if(!fread(&testone, sizeof(int), 1, fp)){
      Msg::Error("Read error");
      return false;
    }
    if(testone != 1) {
      Msg::Info("Swapping bytes from binary file");
      swap = 1;
    }
  }

  dVecRead(Time, NbTimeStep, fp, binary, swap);
  dVecRead(SP, NbSP * (NbTimeStep * 1 + 3), fp, binary, swap);
  dVecRead(VP, NbVP * (NbTimeStep * 3 + 3), fp, binary, swap);
  dVecRead(TP, NbTP * (NbTimeStep * 9 + 3), fp, binary, swap);
  dVecRead(SL, NbSL * (NbTimeStep * 2 * 1 + 6), fp, binary, swap);
  dVecRead(VL, NbVL * (NbTimeStep * 2 * 3 + 6), fp, binary, swap);
  dVecRead(TL, NbTL * (NbTimeStep * 2 * 9 + 6), fp, binary, swap);
  dVecRead(ST, NbST * (NbTimeStep * 3 * 1 + 9), fp, binary, swap);
  dVecRead(VT, NbVT * (NbTimeStep * 3 * 3 + 9), fp, binary, swap);
  dVecRead(TT, NbTT * (NbTimeStep * 3 * 9 + 9), fp, binary, swap);
  dVecRead(SQ, NbSQ * (NbTimeStep * 4 * 1 + 12), fp, binary, swap);
  dVecRead(VQ, NbVQ * (NbTimeStep * 4 * 3 + 12), fp, binary, swap);
  dVecRead(TQ, NbTQ * (NbTimeStep * 4 * 9 + 12), fp, binary, swap);
  dVecRead(SS, NbSS * (NbTimeStep * 4 * 1 + 12), fp, binary, swap);
  dVecRead(VS, NbVS * (NbTimeStep * 4 * 3 + 12), fp, binary, swap);
  dVecRead(TS, NbTS * (NbTimeStep * 4 * 9 + 12), fp, binary, swap);
  dVecRead(SH, NbSH * (NbTimeStep * 8 * 1 + 24), fp, binary, swap);
  dVecRead(VH, NbVH * (NbTimeStep * 8 * 3 + 24), fp, binary, swap);
  dVecRead(TH, NbTH * (NbTimeStep * 8 * 9 + 24), fp, binary, swap);
  dVecRead(SI, NbSI * (NbTimeStep * 6 * 1 + 18), fp, binary, swap);
  dVecRead(VI, NbVI * (NbTimeStep * 6 * 3 + 18), fp, binary, swap);
  dVecRead(TI, NbTI * (NbTimeStep * 6 * 9 + 18), fp, binary, swap);
  dVecRead(SY, NbSY * (NbTimeStep * 5 * 1 + 15), fp, binary, swap);
  dVecRead(VY, NbVY * (NbTimeStep * 5 * 3 + 15), fp, binary, swap);
  dVecRead(TY, NbTY * (NbTimeStep * 5 * 9 + 15), fp, binary, swap);

  // overwrite first order data with second order data (if any)
  dVecRead(SL, NbSL2 * (NbTimeStep * 3 * 1 + 9), fp, binary, swap);
  dVecRead(VL, NbVL2 * (NbTimeStep * 3 * 3 + 9), fp, binary, swap);
  dVecRead(TL, NbTL2 * (NbTimeStep * 3 * 9 + 9), fp, binary, swap);
  dVecRead(ST, NbST2 * (NbTimeStep * 6 * 1 + 18), fp, binary, swap);
  dVecRead(VT, NbVT2 * (NbTimeStep * 6 * 3 + 18), fp, binary, swap);
  dVecRead(TT, NbTT2 * (NbTimeStep * 6 * 9 + 18), fp, binary, swap);
  dVecRead(SQ, NbSQ2 * (NbTimeStep * 9 * 1 + 27), fp, binary, swap);
  dVecRead(VQ, NbVQ2 * (NbTimeStep * 9 * 3 + 27), fp, binary, swap);
  dVecRead(TQ, NbTQ2 * (NbTimeStep * 9 * 9 + 27), fp, binary, swap);
  dVecRead(SS, NbSS2 * (NbTimeStep * 10 * 1 + 30), fp, binary, swap);
  dVecRead(VS, NbVS2 * (NbTimeStep * 10 * 3 + 30), fp, binary, swap);
  dVecRead(TS, NbTS2 * (NbTimeStep * 10 * 9 + 30), fp, binary, swap);
  dVecRead(SH, NbSH2 * (NbTimeStep * 27 * 1 + 81), fp, binary, swap);
  dVecRead(VH, NbVH2 * (NbTimeStep * 27 * 3 + 81), fp, binary, swap);
  dVecRead(TH, NbTH2 * (NbTimeStep * 27 * 9 + 81), fp, binary, swap);
  dVecRead(SI, NbSI2 * (NbTimeStep * 18 * 1 + 54), fp, binary, swap);
  dVecRead(VI, NbVI2 * (NbTimeStep * 18 * 3 + 54), fp, binary, swap);
  dVecRead(TI, NbTI2 * (NbTimeStep * 18 * 9 + 54), fp, binary, swap);
  dVecRead(SY, NbSY2 * (NbTimeStep * 14 * 1 + 42), fp, binary, swap);
  dVecRead(VY, NbVY2 * (NbTimeStep * 14 * 3 + 42), fp, binary, swap);
  dVecRead(TY, NbTY2 * (NbTimeStep * 14 * 9 + 42), fp, binary, swap);
  if(NbSL2){ NbSL = NbSL2; setOrder2(TYPE_LIN); }
  if(NbVL2){ NbVL = NbVL2; setOrder2(TYPE_LIN); }
  if(NbTL2){ NbTL = NbTL2; setOrder2(TYPE_LIN); }
  if(NbST2){ NbST = NbST2; setOrder2(TYPE_TRI); }
  if(NbVT2){ NbVT = NbVT2; setOrder2(TYPE_TRI); }
  if(NbTT2){ NbTT = NbTT2; setOrder2(TYPE_TRI); }
  if(NbSQ2){ NbSQ = NbSQ2; setOrder2(TYPE_QUA); }
  if(NbVQ2){ NbVQ = NbVQ2; setOrder2(TYPE_QUA); }
  if(NbTQ2){ NbTQ = NbTQ2; setOrder2(TYPE_QUA); }
  if(NbSS2){ NbSS = NbSS2; setOrder2(TYPE_TET); }
  if(NbVS2){ NbVS = NbVS2; setOrder2(TYPE_TET); }
  if(NbTS2){ NbTS = NbTS2; setOrder2(TYPE_TET); }
  if(NbSH2){ NbSH = NbSH2; setOrder2(TYPE_HEX); }
  if(NbVH2){ NbVH = NbVH2; setOrder2(TYPE_HEX); }
  if(NbTH2){ NbTH = NbTH2; setOrder2(TYPE_HEX); }
  if(NbSI2){ NbSI = NbSI2; setOrder2(TYPE_PRI); }
  if(NbVI2){ NbVI = NbVI2; setOrder2(TYPE_PRI); }
  if(NbTI2){ NbTI = NbTI2; setOrder2(TYPE_PRI); }
  if(NbSY2){ NbSY = NbSY2; setOrder2(TYPE_PYR); }
  if(NbVY2){ NbVY = NbVY2; setOrder2(TYPE_PYR); }
  if(NbTY2){ NbTY = NbTY2; setOrder2(TYPE_PYR); }

  dVecRead(T2D, NbT2 * 4, fp, binary, swap);
  cVecRead(T2C, t2l, fp, binary, swap, (version <= 1.2));
  dVecRead(T3D, NbT3 * 5, fp, binary, swap);
  cVecRead(T3C, t3l, fp, binary, swap, (version <= 1.2));

  Msg::Debug("Read View '%s' (%d TimeSteps): "
             "SP(%d/%d) VP(%d/%d) TP(%d/%d) "
             "SL(%d/%d) VL(%d/%d) TL(%d/%d) "
             "ST(%d/%d) VT(%d/%d) TT(%d/%d) "
             "SQ(%d/%d) VQ(%d/%d) TQ(%d/%d) "
             "SS(%d/%d) VS(%d/%d) TS(%d/%d) "
             "SH(%d/%d) VH(%d/%d) TH(%d/%d) "
             "SI(%d/%d) VI(%d/%d) TI(%d/%d) "
             "SY(%d/%d) VY(%d/%d) TY(%d/%d) "
             "T2(%d/%d/%d) T3(%d/%d/%d) ",
             name, NbTimeStep,
             NbSP, SP.size(), NbVP, VP.size(), NbTP, TP.size(),
             NbSL, SL.size(), NbVL, VL.size(), NbTL, TL.size(),
             NbST, ST.size(), NbVT, VT.size(), NbTT, TT.size(),
             NbSQ, SQ.size(), NbVQ, VQ.size(), NbTQ, TQ.size(),
             NbSS, SS.size(), NbVS, VS.size(), NbTS, TS.size(),
             NbSH, SH.size(), NbVH, VH.size(), NbTH, TH.size(),
             NbSI, SI.size(), NbVI, VI.size(), NbTI, TI.size(),
             NbSY, SY.size(), NbVY, VY.size(), NbTY, TY.size(),
             NbT2, T2D.size(), T2C.size(),
             NbT3, T3D.size(), T3C.size());

  setName(name);
  finalize();
  return true;
}

static void writeTimePOS(FILE *fp, std::vector<double> &list)
{
  if(list.size() > 1){
    fprintf(fp, "TIME{");
    for(unsigned int i = 0; i < list.size(); i++){
      if(i) fprintf(fp, ",");
      fprintf(fp, "%.16g", list[i]);
    }
    fprintf(fp, "};\n");
  }
}

static void writeElementPOS(FILE *fp, const char *str, int nbnod, int nb,
                            std::vector<double> &list)
{
  if(nb){
    int n = list.size() / nb;
    for(unsigned int i = 0; i < list.size(); i += n) {
      double *x = &list[i];
      double *y = &list[i + nbnod];
      double *z = &list[i + 2 * nbnod];
      fprintf(fp, "%s(", str);
      for(int j = 0; j < nbnod; j++) {
        if(j) fprintf(fp, ",");
        fprintf(fp, "%.16g,%.16g,%.16g", x[j], y[j], z[j]);
      }
      fprintf(fp, "){");
      for(int j = 3 * nbnod; j < n; j++) {
        if(j - 3 * nbnod) fprintf(fp, ",");
        fprintf(fp, "%.16g", list[i + j]);
      }
      fprintf(fp, "};\n");
    }
  }
}

static void writeTextPOS(FILE *fp, int nbc, int nb, std::vector<double> &TD,
                         std::vector<char> &TC)
{
  if(!nb || (nbc != 4 && nbc != 5)) return;
  for(unsigned int j = 0; j < TD.size(); j += nbc){
    double x = TD[j];
    double y = TD[j + 1];
    double z = (nbc == 5) ? TD[j + 2] : 0.;
    double style = TD[j + nbc - 2];
    if(nbc == 4)
      fprintf(fp, "T2(%g,%g,%g){", x, y, style);
    else
      fprintf(fp, "T3(%g,%g,%g,%g){", x, y, z, style);
    double start = TD[j + nbc - 1];
    double end;
    if(j + nbc * 2 - 1 < TD.size())
      end = TD[j + nbc * 2 - 1];
    else
      end = TC.size();
    int l = 0;
    while(l < end - start){
      char *str = &TC[(int)start + l];
      if(l) fprintf(fp, ",");
      fprintf(fp, "\"%s\"", str);
      l += strlen(str) + 1;
    }
    fprintf(fp, "};\n");
  }
}

bool PViewDataList::writePOS(const std::string &fileName, bool binary, bool parsed,
                             bool append)
{
  if(_adaptive){
    Msg::Warning("Writing adapted dataset (will only export current time step)");
    return _adaptive->getData()->writePOS(fileName, binary, parsed, append);
  }

  if(haveInterpolationMatrices()){
    Msg::Error("Cannot export datasets with interpolation matrices in old POS format: "
               "consider using the new mesh-based format instead, or select 'Adapt "
               "post-processing data' before exporting");
    return false;
  }

  FILE *fp = fopen(fileName.c_str(),
                   append ? (binary ? "ab" : "a") : (binary ? "wb" : "w"));
  if(!fp){
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  if(!parsed && !append){
    fprintf(fp, "$PostFormat /* Gmsh 1.3, %s */\n", binary ? "binary" : "ascii");
    fprintf(fp, "1.3 %d %d\n", binary, (int)sizeof(double));
    fprintf(fp, "$EndPostFormat\n");
  }

  std::string str = getName();
  for(unsigned int i = 0; i < str.size(); i++)
    if(str[i] == ' ') str[i] = '^';

  if(!parsed){
    fprintf(fp, "$View /* %s */\n", getName().c_str());
    if (str.empty())
      fprintf(fp, "noname ");
    else
      fprintf(fp, "%s ", str.c_str());
    fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d\n",
            (int)Time.size(),
            NbSP, NbVP, NbTP, NbSL, NbVL, NbTL,
            NbST, NbVT, NbTT, NbSQ, NbVQ, NbTQ,
            NbSS, NbVS, NbTS, NbSH, NbVH, NbTH,
            NbSI, NbVI, NbTI, NbSY, NbVY, NbTY,
            NbT2, (int)T2C.size(), NbT3, (int)T3C.size());
    if(binary) {
      int one = 1;
      if(!fwrite(&one, sizeof(int), 1, fp)){
        Msg::Error("Write error");
        return false;
      }
    }
    dVecWrite(Time, fp, binary);
    dVecWrite(SP, fp, binary); dVecWrite(VP, fp, binary);
    dVecWrite(TP, fp, binary); dVecWrite(SL, fp, binary);
    dVecWrite(VL, fp, binary); dVecWrite(TL, fp, binary);
    dVecWrite(ST, fp, binary); dVecWrite(VT, fp, binary);
    dVecWrite(TT, fp, binary); dVecWrite(SQ, fp, binary);
    dVecWrite(VQ, fp, binary); dVecWrite(TQ, fp, binary);
    dVecWrite(SS, fp, binary); dVecWrite(VS, fp, binary);
    dVecWrite(TS, fp, binary); dVecWrite(SH, fp, binary);
    dVecWrite(VH, fp, binary); dVecWrite(TH, fp, binary);
    dVecWrite(SI, fp, binary); dVecWrite(VI, fp, binary);
    dVecWrite(TI, fp, binary); dVecWrite(SY, fp, binary);
    dVecWrite(VY, fp, binary); dVecWrite(TY, fp, binary);
    dVecWrite(T2D, fp, binary); cVecWrite(T2C, fp, binary);
    dVecWrite(T3D, fp, binary); cVecWrite(T3C, fp, binary);
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

static void createVertices(std::vector<double> &list, int nbelm, int nbnod,
                           std::vector<MVertex*> &nodes)
{
  if(!nbelm) return;
  int nb = list.size() / nbelm;
  for(unsigned int i = 0; i < list.size(); i += nb){
    double *x = &list[i];
    double *y = &list[i + nbnod];
    double *z = &list[i + 2 * nbnod];
    for(int j = 0; j < nbnod; j++)
      nodes.push_back(new MVertex(x[j], y[j], z[j]));
  }
}

static void createElements(std::vector<double> &list, int nbelm, int nbnod,
                           MVertexPositionSet &pos, std::vector<MElement*> &elements,
                           double eps, int type)
{
  if(!nbelm) return;
  int t = 0;
  // reverse-engineer geometrical element type according to the number
  // of nodes (this should be completed, but is likely enough for most
  // legacy .pos files out there...)
  switch(type){
  case TYPE_PNT : t = MSH_PNT; break;
  case TYPE_LIN :
    switch(nbnod){
    case 2: t = MSH_LIN_2; break;
    case 3: t = MSH_LIN_3; break;
    }
    break;
  case TYPE_TRI :
    switch(nbnod){
    case 3: t = MSH_TRI_3; break;
    case 6: t = MSH_TRI_6; break;
    }
    break;
  case TYPE_QUA :
    switch(nbnod){
    case 4: t = MSH_QUA_4; break;
    case 8: t = MSH_QUA_8; break;
    case 9: t = MSH_QUA_9; break;
    }
    break;
  case TYPE_TET :
    switch(nbnod){
    case 4: t = MSH_TET_4; break;
    case 10: t = MSH_TET_10; break;
    }
    break;
  case TYPE_HEX :
    switch(nbnod){
    case 8: t = MSH_HEX_8; break;
    case 20: t = MSH_HEX_20; break;
    case 27: t = MSH_HEX_27; break;
    }
    break;
  case TYPE_PRI :
    switch(nbnod){
    case 6: t = MSH_PRI_6; break;
    case 15: t = MSH_PRI_15; break;
    case 18: t = MSH_PRI_18; break;
    }
    break;
  case TYPE_PYR :
    switch(nbnod){
    case 5: t = MSH_PYR_5; break;
    case 13: t = MSH_PYR_13; break;
    case 14: t = MSH_PYR_14; break;
    }
    break;
  }
  if(!t){
    Msg::Warning("Discarding elements of type (%d nodes)", nbnod);
    return;
  }
  MElementFactory factory;
  int nb = list.size() / nbelm;
  for(unsigned int i = 0; i < list.size(); i += nb){
    double *x = &list[i];
    double *y = &list[i + nbnod];
    double *z = &list[i + 2 * nbnod];
    std::vector<MVertex*> verts(nbnod);
    for(int j = 0; j < nbnod; j++)
      verts[j] = pos.find(x[j], y[j], z[j], eps);
    MElement *e = factory.create(t, verts);
    elements.push_back(e);
  }
}

bool PViewDataList::writeMSH(const std::string &fileName, bool binary, bool savemesh)
{
  if(_adaptive){
    Msg::Warning("Writing adapted dataset (will only export current time step)");
    return _adaptive->getData()->writeMSH(fileName, binary);
  }

  FILE *fp = fopen(fileName.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  double tol = CTX::instance()->geom.tolerance;
  double eps = norm(SVector3(BBox.max(), BBox.min())) * tol;

  std::vector<MVertex*> vertices;
  std::vector<MElement*> elements;

  int numComponents = 9;
  for(int i = 0; i < 24; i++){
    std::vector<double> *list = 0;
    int *numEle = 0, numNodes, numComp;
    _getRawData(i, &list, &numEle, &numComp, &numNodes);
    if(*numEle) numComponents = std::min(numComponents, numComp);
    createVertices(*list, *numEle, numNodes, vertices);
  }
  MVertexPositionSet pos(vertices);

  for(int i = 0; i < 24; i++){
    std::vector<double> *list = 0;
    int *numEle = 0, numComp, numNodes;
    int typ = _getRawData(i, &list, &numEle, &numComp, &numNodes);
    createElements(*list, *numEle, numNodes, pos, elements, eps, typ);
  }

  int num = 0;
  for(unsigned int i = 0; i < vertices.size(); i++)
    if(vertices[i]->getIndex() < 0)
      vertices[i]->setIndex(++num);

  fprintf(fp, "$MeshFormat\n2.2 0 8\n$EndMeshFormat\n");
  fprintf(fp, "$Nodes\n");
  fprintf(fp, "%d\n", num);
  for(unsigned int i = 0; i < vertices.size(); i++){
    MVertex *v = vertices[i];
    if(v->getIndex() > 0)
      fprintf(fp, "%d %.16g %.16g %.16g\n", v->getIndex(), v->x(), v->y(), v->z());
  }
  fprintf(fp, "$EndNodes\n");

  fprintf(fp, "$Elements\n");
  fprintf(fp, "%d\n", (int)elements.size());
  for(unsigned int i = 0; i < elements.size(); i++)
    elements[i]->writeMSH2(fp, 2.2, false, i + 1);
  fprintf(fp, "$EndElements\n");

  if(haveInterpolationMatrices()){
    fprintf(fp, "$InterpolationScheme\n");
    fprintf(fp, "\"INTERPOLATION_SCHEME\"\n");
    fprintf(fp, "%d\n", (int)_interpolation.size());
    for(interpolationMatrices::iterator it = _interpolation.begin();
        it != _interpolation.end(); it++){
      if(it->second.size() >= 2){
        fprintf(fp, "%d\n2\n", it->first);
        for(int mat = 0; mat < 2; mat++){
          int m = it->second[mat]->size1(), n = it->second[mat]->size2();
          fprintf(fp, "%d %d\n", m, n);
          for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
              fprintf(fp, "%.16g ", it->second[mat]->get(i, j));
            fprintf(fp, "\n");
          }
        }
      }
    }
    fprintf(fp, "$EndInterpolationScheme\n");
  }

  for(int ts = 0; ts < NbTimeStep; ts++){
    fprintf(fp, "$ElementNodeData\n");
    if(haveInterpolationMatrices())
      fprintf(fp, "2\n\"%s\"\n\"INTERPOLATION_SCHEME\"\n", getName().c_str());
    else
      fprintf(fp, "1\n\"%s\"\n", getName().c_str());
    fprintf(fp, "1\n%.16g\n", getTime(ts));
    fprintf(fp, "3\n%d\n%d\n%d\n", ts, numComponents, (int)elements.size());
    num = 0;
    for(int i = 0; i < 24; i++){
      std::vector<double> *list = 0;
      int *numEle = 0, numComp, numNodes;
      int typ = _getRawData(i, &list, &numEle, &numComp, &numNodes);
      if(*numEle){
        int mult = numNodes;
        if(_interpolation.count(typ))
          mult = _interpolation[typ][0]->size1();
        int nb = list->size() / *numEle;
        for(unsigned int i = 0; i < list->size(); i += nb){
          double *v = &(*list)[i + 3 * numNodes];
          fprintf(fp, "%d %d", ++num, mult);
          for(int j = 0; j < numComponents * mult; j++)
            fprintf(fp, " %.16g", v[numComponents * mult * ts + j]);
          fprintf(fp, "\n");
        }
      }
    }
    fprintf(fp, "$EndElementNodeData\n");
  }

  fclose(fp);
  return true;
}
