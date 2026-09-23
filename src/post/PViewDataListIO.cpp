// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <set>
#include <unordered_map>
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "GModel.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"
#include "MElement.h"
#include "ElementType.h"
#include "Numeric.h"
#include "StringUtils.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "adaptiveData.h"
#include "OS.h"

static void dVecRead(std::vector<double> &v, int n, FILE *fp, bool binary,
                     int swap)
{
  if(n <= 0) return;
  v.resize(n);
  if(binary) {
    if(!fread(&v[0], sizeof(double), n, fp)) Msg::Error("Read error");
    if(swap) SwapBytes((char *)&v[0], sizeof(double), n);
  }
  else {
    for(int i = 0; i < n; i++) {
      if(fscanf(fp, "%lf", &v[i]) != 1) {
        Msg::Error("Read error");
        break;
      }
    }
  }
}

static void cVecRead(std::vector<char> &v, int n, FILE *fp, bool binary,
                     int swap, bool oldStyle)
{
  if(n <= 0) return;
  v.resize(n);
  if(binary) {
    if(!fread(&v[0], sizeof(char), n, fp)) Msg::Error("Read error");
    if(swap) SwapBytes((char *)&v[0], sizeof(char), n);
  }
  else {
    if(oldStyle) {
      for(int i = 0; i < n; i++) {
        if(fscanf(fp, "%c", &v[i]) != 1) {
          Msg::Error("Read error");
          break;
        }
        if(v[i] == '^') v[i] = '\0';
      }
    }
    else {
      for(int i = 0; i < n; i++) {
        char c = (char)fgetc(fp);
        if(c == EOF) {
          Msg::Error("Read error");
          break;
        }
        else {
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
    for(unsigned i = 0; i < v.size(); i++) fprintf(fp, " %.16g", v[i]);
}

static void cVecWrite(std::vector<char> &v, FILE *fp, bool binary)
{
  if(v.empty()) return;
  if(binary)
    fwrite(&v[0], sizeof(char), v.size(), fp);
  else
    for(unsigned i = 0; i < v.size(); i++) fputc(v[i], fp);
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
    if(fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d\n", name,
              &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL, &NbST,
              &NbVT, &NbTT, &NbSS, &NbVS, &NbTS) != 14) {
      Msg::Error("Read error");
      return false;
    }
    NbT2 = t2l = NbT3 = t3l = 0;
  }
  else if(version == 1.1) {
    Msg::Debug("Detected post-processing view format 1.1");
    if(fscanf(fp, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
              name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
              &NbST, &NbVT, &NbTT, &NbSS, &NbVS, &NbTS, &NbT2, &t2l, &NbT3,
              &t3l) != 18) {
      Msg::Error("Read error");
      return false;
    }
  }
  else if(version == 1.2 || version == 1.3) {
    Msg::Debug("Detected post-processing view format %g", version);
    if(fscanf(fp,
              "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
              "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
              name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
              &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ, &NbSS, &NbVS, &NbTS,
              &NbSH, &NbVH, &NbTH, &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
              &NbT2, &t2l, &NbT3, &t3l) != 30) {
      Msg::Error("Read error");
      return false;
    }
  }
  else if(version == 1.4) {
    Msg::Debug("Detected post-processing view format 1.4");
    if(fscanf(fp,
              "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
              "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
              "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
              name, &NbTimeStep, &NbSP, &NbVP, &NbTP, &NbSL, &NbVL, &NbTL,
              &NbST, &NbVT, &NbTT, &NbSQ, &NbVQ, &NbTQ, &NbSS, &NbVS, &NbTS,
              &NbSH, &NbVH, &NbTH, &NbSI, &NbVI, &NbTI, &NbSY, &NbVY, &NbTY,
              &NbSL2, &NbVL2, &NbTL2, &NbST2, &NbVT2, &NbTT2, &NbSQ2, &NbVQ2,
              &NbTQ2, &NbSS2, &NbVS2, &NbTS2, &NbSH2, &NbVH2, &NbTH2, &NbSI2,
              &NbVI2, &NbTI2, &NbSY2, &NbVY2, &NbTY2, &NbT2, &t2l, &NbT3,
              &t3l) != 51) {
      Msg::Error("Read error");
      return false;
    }
  }
  else {
    Msg::Error("Unknown post-processing file format (version %g)", version);
    return false;
  }

  for(int i = 0; i < (int)strlen(name); i++)
    if(name[i] == '^') name[i] = ' ';

  int swap = 0;
  if(binary) {
    int testone;
    if(!fread(&testone, sizeof(int), 1, fp)) {
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
  if(NbSL2) {
    NbSL = NbSL2;
    setOrder2(TYPE_LIN);
  }
  if(NbVL2) {
    NbVL = NbVL2;
    setOrder2(TYPE_LIN);
  }
  if(NbTL2) {
    NbTL = NbTL2;
    setOrder2(TYPE_LIN);
  }
  if(NbST2) {
    NbST = NbST2;
    setOrder2(TYPE_TRI);
  }
  if(NbVT2) {
    NbVT = NbVT2;
    setOrder2(TYPE_TRI);
  }
  if(NbTT2) {
    NbTT = NbTT2;
    setOrder2(TYPE_TRI);
  }
  if(NbSQ2) {
    NbSQ = NbSQ2;
    setOrder2(TYPE_QUA);
  }
  if(NbVQ2) {
    NbVQ = NbVQ2;
    setOrder2(TYPE_QUA);
  }
  if(NbTQ2) {
    NbTQ = NbTQ2;
    setOrder2(TYPE_QUA);
  }
  if(NbSS2) {
    NbSS = NbSS2;
    setOrder2(TYPE_TET);
  }
  if(NbVS2) {
    NbVS = NbVS2;
    setOrder2(TYPE_TET);
  }
  if(NbTS2) {
    NbTS = NbTS2;
    setOrder2(TYPE_TET);
  }
  if(NbSH2) {
    NbSH = NbSH2;
    setOrder2(TYPE_HEX);
  }
  if(NbVH2) {
    NbVH = NbVH2;
    setOrder2(TYPE_HEX);
  }
  if(NbTH2) {
    NbTH = NbTH2;
    setOrder2(TYPE_HEX);
  }
  if(NbSI2) {
    NbSI = NbSI2;
    setOrder2(TYPE_PRI);
  }
  if(NbVI2) {
    NbVI = NbVI2;
    setOrder2(TYPE_PRI);
  }
  if(NbTI2) {
    NbTI = NbTI2;
    setOrder2(TYPE_PRI);
  }
  if(NbSY2) {
    NbSY = NbSY2;
    setOrder2(TYPE_PYR);
  }
  if(NbVY2) {
    NbVY = NbVY2;
    setOrder2(TYPE_PYR);
  }
  if(NbTY2) {
    NbTY = NbTY2;
    setOrder2(TYPE_PYR);
  }

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
             name, NbTimeStep, NbSP, SP.size(), NbVP, VP.size(), NbTP,
             TP.size(), NbSL, SL.size(), NbVL, VL.size(), NbTL, TL.size(), NbST,
             ST.size(), NbVT, VT.size(), NbTT, TT.size(), NbSQ, SQ.size(), NbVQ,
             VQ.size(), NbTQ, TQ.size(), NbSS, SS.size(), NbVS, VS.size(), NbTS,
             TS.size(), NbSH, SH.size(), NbVH, VH.size(), NbTH, TH.size(), NbSI,
             SI.size(), NbVI, VI.size(), NbTI, TI.size(), NbSY, SY.size(), NbVY,
             VY.size(), NbTY, TY.size(), NbT2, T2D.size(), T2C.size(), NbT3,
             T3D.size(), T3C.size());

  setName(name);
  finalize();
  return true;
}

static void writeTimePOS(FILE *fp, std::vector<double> &list)
{
  if(list.size() > 1) {
    fprintf(fp, "TIME{");
    for(std::size_t i = 0; i < list.size(); i++) {
      if(i) fprintf(fp, ",");
      fprintf(fp, "%.16g", list[i]);
    }
    fprintf(fp, "};\n");
  }
}

static void writeElementPOS(FILE *fp, const char *str, int nbnod, int nb,
                            std::vector<double> &list)
{
  if(nb) {
    int n = list.size() / nb;
    for(std::size_t i = 0; i < list.size(); i += n) {
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
  for(std::size_t j = 0; j < TD.size(); j += nbc) {
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
    while(l < end - start) {
      char *str = &TC[(int)start + l];
      if(l) fprintf(fp, ",");
      fprintf(fp, "\"%s\"", str);
      l += strlen(str) + 1;
    }
    fprintf(fp, "};\n");
  }
}

bool PViewDataList::writePOS(const std::string &fileName, bool binary,
                             bool parsed, bool append)
{
  if(_adaptive) {
    Msg::Warning(
      "Writing adapted dataset (will only export current time step)");
    return _adaptive->getData()->writePOS(fileName, binary, parsed, append);
  }

  if(haveInterpolationMatrices()) {
    Msg::Error(
      "Cannot export datasets with interpolation matrices in old POS format: "
      "consider using the new mesh-based format instead, or select 'Adapt "
      "post-processing data' before exporting");
    return false;
  }

  FILE *fp = Fopen(fileName.c_str(),
                   append ? (binary ? "ab" : "a") : (binary ? "wb" : "w"));
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  if(!parsed && !append) {
    fprintf(fp, "$PostFormat /* Gmsh 1.3, %s */\n",
            binary ? "binary" : "ascii");
    fprintf(fp, "1.3 %d %d\n", binary, (int)sizeof(double));
    fprintf(fp, "$EndPostFormat\n");
  }

  std::string str = getName();
  for(std::size_t i = 0; i < str.size(); i++)
    if(str[i] == ' ') str[i] = '^';

  if(!parsed) {
    fprintf(fp, "$View /* %s */\n", getName().c_str());
    if(str.empty())
      fprintf(fp, "noname ");
    else
      fprintf(fp, "%s ", str.c_str());
    fprintf(fp,
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d\n",
            (int)Time.size(), NbSP, NbVP, NbTP, NbSL, NbVL, NbTL, NbST, NbVT,
            NbTT, NbSQ, NbVQ, NbTQ, NbSS, NbVS, NbTS, NbSH, NbVH, NbTH, NbSI,
            NbVI, NbTI, NbSY, NbVY, NbTY, NbT2, (int)T2C.size(), NbT3,
            (int)T3C.size());
    if(binary) {
      int one = 1;
      if(!fwrite(&one, sizeof(int), 1, fp)) {
        Msg::Error("Write error");
        fclose(fp);
        return false;
      }
    }
    dVecWrite(Time, fp, binary);
    dVecWrite(SP, fp, binary);
    dVecWrite(VP, fp, binary);
    dVecWrite(TP, fp, binary);
    dVecWrite(SL, fp, binary);
    dVecWrite(VL, fp, binary);
    dVecWrite(TL, fp, binary);
    dVecWrite(ST, fp, binary);
    dVecWrite(VT, fp, binary);
    dVecWrite(TT, fp, binary);
    dVecWrite(SQ, fp, binary);
    dVecWrite(VQ, fp, binary);
    dVecWrite(TQ, fp, binary);
    dVecWrite(SS, fp, binary);
    dVecWrite(VS, fp, binary);
    dVecWrite(TS, fp, binary);
    dVecWrite(SH, fp, binary);
    dVecWrite(VH, fp, binary);
    dVecWrite(TH, fp, binary);
    dVecWrite(SI, fp, binary);
    dVecWrite(VI, fp, binary);
    dVecWrite(TI, fp, binary);
    dVecWrite(SY, fp, binary);
    dVecWrite(VY, fp, binary);
    dVecWrite(TY, fp, binary);
    dVecWrite(T2D, fp, binary);
    cVecWrite(T2C, fp, binary);
    dVecWrite(T3D, fp, binary);
    cVecWrite(T3C, fp, binary);
    fprintf(fp, "\n");
    fprintf(fp, "$EndView\n");
  }
  else {
    fprintf(fp, "View \"%s\" {\n", getName().c_str());
    writeTimePOS(fp, Time);
    writeElementPOS(fp, "SP", 1, NbSP, SP);
    writeElementPOS(fp, "VP", 1, NbVP, VP);
    writeElementPOS(fp, "TP", 1, NbTP, TP);
    writeElementPOS(fp, "SL", 2, NbSL, SL);
    writeElementPOS(fp, "VL", 2, NbVL, VL);
    writeElementPOS(fp, "TL", 2, NbTL, TL);
    writeElementPOS(fp, "ST", 3, NbST, ST);
    writeElementPOS(fp, "VT", 3, NbVT, VT);
    writeElementPOS(fp, "TT", 3, NbTT, TT);
    writeElementPOS(fp, "SQ", 4, NbSQ, SQ);
    writeElementPOS(fp, "VQ", 4, NbVQ, VQ);
    writeElementPOS(fp, "TQ", 4, NbTQ, TQ);
    writeElementPOS(fp, "SS", 4, NbSS, SS);
    writeElementPOS(fp, "VS", 4, NbVS, VS);
    writeElementPOS(fp, "TS", 4, NbTS, TS);
    writeElementPOS(fp, "SH", 8, NbSH, SH);
    writeElementPOS(fp, "VH", 8, NbVH, VH);
    writeElementPOS(fp, "TH", 8, NbTH, TH);
    writeElementPOS(fp, "SI", 6, NbSI, SI);
    writeElementPOS(fp, "VI", 6, NbVI, VI);
    writeElementPOS(fp, "TI", 6, NbTI, TI);
    writeElementPOS(fp, "SY", 5, NbSY, SY);
    writeElementPOS(fp, "VY", 5, NbVY, VY);
    writeElementPOS(fp, "TY", 5, NbTY, TY);
    writeTextPOS(fp, 4, NbT2, T2D, T2C);
    writeTextPOS(fp, 5, NbT3, T3D, T3C);
    fprintf(fp, "};\n");
  }

  fclose(fp);
  return true;
}

// The index of the point each point (x, y, z in sequence) is merged with: the
// points closer than eps in each direction, the merged points numbered in the
// order in which they first appear
static std::vector<std::size_t> mergePoints(const std::vector<double> &xyz,
                                            double eps, std::size_t &num)
{
  std::size_t n = xyz.size() / 3;
  const double *p = xyz.data();

  // the points kept, in cells of size eps (two points closer than eps are in
  // the same cell or in neighbors), or at their exact place if eps is too
  // small for the coordinates
  bool exact = !(eps > 0.);
  for(std::size_t i = 0; i < 3 * n && !exact; i++)
    if(std::abs(p[i] / eps) > 1.e15) exact = true;
  struct cellHash {
    std::size_t operator()(const std::array<int64_t, 3> &c) const
    {
      return (std::size_t)(c[0] * 73856093) ^ (std::size_t)(c[1] * 19349663) ^
             (std::size_t)(c[2] * 83492791);
    }
  };
  std::unordered_map<std::array<int64_t, 3>, std::vector<std::size_t>, cellHash>
    grid;
  auto close = [&](std::size_t i, std::size_t j) {
    for(int k = 0; k < 3; k++) {
      double d = std::abs(p[3 * i + k] - p[3 * j + k]);
      if(exact ? (d != 0.) : (d > eps)) return false;
    }
    return true;
  };

  std::vector<std::size_t> merged(n);
  num = 0;
  for(std::size_t i = 0; i < n; i++) {
    std::array<int64_t, 3> c;
    for(int k = 0; k < 3; k++) {
      double x = p[3 * i + k] + 0.; // (-0. is 0.)
      if(exact)
        std::memcpy(&c[k], &x, sizeof(double));
      else
        c[k] = (int64_t)std::floor(x / eps);
    }
    // the cell of the point first, then its neighbors
    bool found = false;
    for(int nb = 0; nb < (exact ? 1 : 27) && !found; nb++) {
      int d[3] = {nb % 3, (nb / 3) % 3, nb / 9}; // 0, then +1, then -1
      std::array<int64_t, 3> cn;
      for(int k = 0; k < 3; k++) cn[k] = c[k] + (d[k] == 2 ? -1 : d[k]);
      auto it = grid.find(cn);
      if(it == grid.end()) continue;
      for(auto j : it->second) {
        if(close(i, j)) {
          merged[i] = merged[j];
          found = true;
          break;
        }
      }
    }
    if(!found) {
      merged[i] = num++;
      grid[c].push_back(i);
    }
  }
  return merged;
}

bool PViewDataList::writeMSH(const std::string &fileName, double version,
                             bool binary, bool saveMesh, bool multipleView,
                             int partitionNum, bool saveInterpolationMatrices,
                             bool forceNodeData, bool forceElementData)
{
  return writeMSH(fileName, {this}, version, binary, saveMesh, multipleView,
                  partitionNum, saveInterpolationMatrices, forceNodeData,
                  forceElementData);
}

// The elements of the lists of the views become the mesh of a temporary model,
// their nodes merged within the geometrical tolerance and the elements of
// different views with the same nodes merged, and their values the data of
// model-based views on it (one per view and number of components), which
// write the file
bool PViewDataList::writeMSH(const std::string &fileName,
                             const std::vector<PViewDataList *> &views,
                             double version, bool binary, bool saveMesh,
                             bool multipleView, int partitionNum,
                             bool saveInterpolationMatrices, bool forceNodeData,
                             bool forceElementData)
{
  // the lists with elements, with the type of their elements in the mesh, and
  // the coordinates of the nodes of all the elements
  struct elementList {
    PViewDataList *view;
    std::vector<double> *list;
    int numEle, numNodes, numComp, mshType, mult;
  };
  std::vector<elementList> lists;
  std::vector<double> xyz;
  SBoundingBox3d bbox;
  for(auto view : views) {
    if(view->_adaptive) {
      Msg::Warning("Writing adapted view '%s' (only its current time step)",
                   view->getName().c_str());
      view = dynamic_cast<PViewDataList *>(view->_adaptive->getData());
      if(!view) continue;
    }
    for(int i = 0; i < 24; i++) {
      std::vector<double> *list = nullptr;
      int *numEle = nullptr, numComp, numNodes;
      int type = view->_getRawData(i, &list, &numEle, &numComp, &numNodes);
      if(!*numEle) continue;
      int mshType = 0;
      for(int order = 0; order <= 10 && !mshType; order++) {
        for(int serendip = 0; serendip < 2 && !mshType; serendip++) {
          int t = ElementType::getType(type, order, serendip);
          if(t > 0 && ElementType::getNumVertices(t) == numNodes) mshType = t;
        }
      }
      if(!mshType) {
        Msg::Warning("Skipping elements with %d nodes of view '%s': no such "
                     "element in MSH",
                     numNodes, view->getName().c_str());
        continue;
      }
      int nb = list->size() / *numEle;
      // the number of values per component of an element at each step
      int mult = (nb - 3 * numNodes) / (view->NbTimeStep * numComp);
      lists.push_back({view, list, *numEle, numNodes, numComp, mshType, mult});
      for(std::size_t e = 0; e < list->size(); e += nb) {
        double *x = &(*list)[e];
        for(int j = 0; j < numNodes; j++) {
          xyz.push_back(x[j]);
          xyz.push_back(x[numNodes + j]);
          xyz.push_back(x[2 * numNodes + j]);
        }
      }
    }
    if(view->NbT2 || view->NbT3)
      Msg::Warning("Strings of view '%s' are not written in MSH",
                   view->getName().c_str());
    bbox += view->BBox;
  }
  if(lists.empty()) {
    Msg::Warning("No elements to write in MSH");
    return true;
  }

  double eps = bbox.empty() ? 0. :
                              norm(SVector3(bbox.max(), bbox.min())) *
                                CTX::instance()->geom.tolerance;
  std::size_t numVertices;
  std::vector<std::size_t> merged = mergePoints(xyz, eps, numVertices);

  // the tag of each element: those of different views with the same type and
  // nodes are the same element (the n-th such element of a view is the n-th of
  // another)
  std::vector<std::size_t> tags;
  std::vector<int> tagType; // the type of each element, by tag - 1
  std::vector<std::size_t> tagNodes; // the index of its first node
  {
    std::unordered_map<std::size_t, std::vector<std::size_t>> same;
    std::unordered_map<std::size_t, std::size_t> used; // in the current view
    PViewDataList *view = nullptr;
    std::size_t node = 0;
    for(auto &l : lists) {
      if(l.view != view) {
        view = l.view;
        used.clear();
      }
      for(int e = 0; e < l.numEle; e++, node += l.numNodes) {
        if(lists.front().view == lists.back().view) { // a single view
          tagType.push_back(l.mshType);
          tagNodes.push_back(node);
          tags.push_back(tagType.size());
          continue;
        }
        std::size_t h = l.mshType;
        for(int j = 0; j < l.numNodes; j++) h = h * 1000003 ^ merged[node + j];
        auto &candidates = same[h];
        std::size_t &n = used[h], tag = 0;
        // the n-th element of the same type and nodes in the previous views
        for(std::size_t k = 0, found = 0; k < candidates.size(); k++) {
          std::size_t t = candidates[k];
          bool eq = (tagType[t - 1] == l.mshType);
          for(int j = 0; j < l.numNodes && eq; j++)
            eq = (merged[tagNodes[t - 1] + j] == merged[node + j]);
          if(eq && found++ == n) {
            tag = t;
            break;
          }
        }
        if(!tag) {
          tag = tagType.size() + 1;
          tagType.push_back(l.mshType);
          tagNodes.push_back(node);
          candidates.push_back(tag);
        }
        n++;
        tags.push_back(tag);
      }
    }
  }

  // the temporary model is current while its mesh is created, so that the
  // numbering of the nodes and elements of the current one is left alone;
  // creating it hides the others
  int current = GModel::getCurrentIndex();
  std::vector<int> visible;
  for(auto m : GModel::list) visible.push_back(m->getVisibility());
  GModel *model = new GModel();
  GModel::setCurrent(model);

  // an entity of each dimension, holding the elements of that dimension; the
  // one of highest dimension holds all the nodes
  GEntity *entities[4] = {nullptr, nullptr, nullptr, nullptr};
  int maxDim = 0;
  for(auto &l : lists) {
    int dim = ElementType::getDimension(l.mshType);
    maxDim = std::max(maxDim, dim);
    if(entities[dim]) continue;
    switch(dim) {
    case 0: {
      GVertex *v = new discreteVertex(model, 1);
      model->add(v);
      entities[0] = v;
    } break;
    case 1: {
      GEdge *e = new discreteEdge(model, 1);
      model->add(e);
      entities[1] = e;
    } break;
    case 2: {
      GFace *f = new discreteFace(model, 1);
      model->add(f);
      entities[2] = f;
    } break;
    case 3: {
      GRegion *r = new discreteRegion(model, 1);
      model->add(r);
      entities[3] = r;
    } break;
    }
  }
  std::vector<MVertex *> vertices(numVertices, nullptr);
  for(std::size_t i = 0; i < merged.size(); i++) {
    std::size_t m = merged[i];
    if(vertices[m]) continue;
    vertices[m] = new MVertex(xyz[3 * i], xyz[3 * i + 1], xyz[3 * i + 2],
                              entities[maxDim], m + 1);
    entities[maxDim]->addMeshVertex(vertices[m]);
  }
  MElementFactory factory;
  for(std::size_t t = 0; t < tagType.size(); t++) {
    int n = ElementType::getNumVertices(tagType[t]);
    std::vector<MVertex *> v(n);
    for(int j = 0; j < n; j++) v[j] = vertices[merged[tagNodes[t] + j]];
    entities[ElementType::getDimension(tagType[t])]->addElement(
      factory.create(tagType[t], v, t + 1));
  }

  GModel::list.erase(
    std::find(GModel::list.begin(), GModel::list.end(), model));
  GModel::setCurrentIndex(current);
  model->setVisibility(0);
  for(std::size_t i = 0; i < visible.size(); i++)
    GModel::list[i]->setVisibility(visible[i]);

  // the data of the elements of each view with each number of components
  PViewDataGModel::DataType type =
    forceNodeData    ? PViewDataGModel::NodeData :
    forceElementData ? PViewDataGModel::ElementData :
                       PViewDataGModel::ElementNodeData;
  std::vector<PViewDataGModel *> data;
  for(std::size_t first = 0; first < lists.size();) {
    PViewDataList *view = lists[first].view;
    std::size_t last = first;
    while(last < lists.size() && lists[last].view == view) last++;
    // the index of the first node and element of the view
    std::size_t node0 = 0, ele0 = 0;
    for(std::size_t k = 0; k < first; k++) {
      node0 += lists[k].numEle * lists[k].numNodes;
      ele0 += lists[k].numEle;
    }
    for(int numComp : {1, 3, 9}) {
      bool any = false, other = false;
      for(std::size_t k = first; k < last; k++) {
        any |= (lists[k].numComp == numComp);
        other |= (lists[k].numComp != numComp);
      }
      if(!any) continue;
      PViewDataGModel *d = new PViewDataGModel(type);
      std::string name = view->getName();
      if(other)
        name += (numComp == 1) ? " (scalar)" :
                (numComp == 3) ? " (vector)" :
                                 " (tensor)";
      d->setName(name);
      if(type == PViewDataGModel::ElementNodeData) {
        for(auto &it : view->_interpolation) {
          if(it.second.size() >= 4)
            d->setInterpolationMatrices(it.first, *it.second[0], *it.second[1],
                                        *it.second[2], *it.second[3]);
          else if(it.second.size() >= 2)
            d->setInterpolationMatrices(it.first, *it.second[0], *it.second[1]);
        }
      }
      for(int step = 0; step < view->NbTimeStep; step++) {
        std::vector<std::size_t> dataTags;
        std::vector<std::vector<double>> values;
        // the value of the last element at each node (NodeData)
        std::vector<const double *> nodeValues;
        if(type == PViewDataGModel::NodeData)
          nodeValues.resize(numVertices, nullptr);
        std::size_t node = node0, ele = ele0;
        for(std::size_t k = first; k < last; k++) {
          auto &l = lists[k];
          std::size_t nb = l.list->size() / l.numEle;
          for(int e = 0; e < l.numEle; e++, node += l.numNodes, ele++) {
            if(l.numComp != numComp) continue;
            const double *v =
              &(*l.list)[e * nb + 3 * l.numNodes] + numComp * l.mult * step;
            if(type == PViewDataGModel::NodeData) {
              for(int j = 0; j < std::min(l.numNodes, l.mult); j++)
                nodeValues[merged[node + j]] = v + numComp * j;
              continue;
            }
            dataTags.push_back(tags[ele]);
            int n = (type == PViewDataGModel::ElementData) ? 1 : l.mult;
            values.emplace_back(v, v + numComp * n);
          }
        }
        for(std::size_t i = 0; i < nodeValues.size(); i++) {
          if(!nodeValues[i]) continue;
          dataTags.push_back(i + 1);
          values.emplace_back(nodeValues[i], nodeValues[i] + numComp);
        }
        d->addData(model, dataTags, values, step, view->getTime(step), -1,
                   numComp, false);
      }
      data.push_back(d);
    }
    first = last;
  }

  bool ok = true;
  for(std::size_t i = 0; i < data.size() && ok; i++)
    ok = data[i]->writeMSH(fileName, version, binary, i ? false : saveMesh,
                           i ? true : multipleView, partitionNum,
                           saveInterpolationMatrices);
  for(auto d : data) delete d;
  delete model;
  return ok;
}

void PViewDataList::importLists(int N[24], std::vector<double> *V[24])
{
  for(int i = 0; i < 24; i++) {
    std::vector<double> *list = nullptr;
    int *nbe = nullptr, nbc, nbn;
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    *nbe = N[i];
    *list = *V[i]; // deep copy
  }
  finalize();
}

void PViewDataList::importList(int index, int n, const std::vector<double> &v,
                               bool fin)
{
  if(index < 0 || index >= 24) {
    Msg::Error("Wrong list index to import");
    return;
  }
  std::vector<double> *list = nullptr;
  int *nbe = nullptr, nbc, nbn;
  _getRawData(index, &list, &nbe, &nbc, &nbn);
  *nbe = n;
  *list = v; // deep copy
  if(fin) finalize();
}

void PViewDataList::getListPointers(int N[24], std::vector<double> *V[24])
{
  for(int i = 0; i < 24; i++) {
    std::vector<double> *list = nullptr;
    int *nbe = nullptr, nbc, nbn;
    _getRawData(i, &list, &nbe, &nbc, &nbn);
    N[i] = *nbe;
    V[i] = list; // copy pointer only
  }
}
