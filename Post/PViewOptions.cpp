// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "PViewOptions.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

PViewOptions PViewOptions::reference;

PViewOptions::PViewOptions()
{
  for(int i = 0; i < 3; i++) genRaiseFunction[i] = 0;
  ColorTable_InitParam(2, &colorTable);
  ColorTable_Recompute(&colorTable);
}

PViewOptions::~PViewOptions()
{
  destroyGeneralRaise();
}

double PViewOptions::getScaleValue(int iso, int numIso, double min, double max)
{
  if(numIso == 1) return (min + max) / 2.;
  
  if(scaleType == Linear){
    return min + iso * (max - min) / (numIso - 1.);
  }
  else if(scaleType == Logarithmic){
    // should translate scale instead, with smallest val an option!
    if(min <= 0.) return 0;
    return pow(10., log10(min) + iso * (log10(max) - log10(min)) / (numIso - 1.));
  }
  else if(scaleType == DoubleLogarithmic){
    if(min <= 0.) return 0;
    double iso2 = iso / 2.;
    double numIso2 = numIso / 2.;
    return pow(10., log10(min) + iso2 * (log10(max) - log10(min)) / (numIso2 - 1.));
  }
  return 0.;
}

int PViewOptions::getScaleIndex(double val, int numIso, double min, double max,
                                bool forceLinear)
{
  if(min == max) return numIso / 2;

  if(forceLinear || scaleType == Linear){
    return (int)((val - min) * (numIso - 1) / (max - min));
  }
  else if(scaleType == Logarithmic){
    if(min <= 0.) return 0;
    return (int)((log10(val) - log10(min)) * (numIso - 1) / (log10(max) - log10(min)));
  }
  else if(scaleType == DoubleLogarithmic){
    // FIXME
    if(min <= 0.) return 0;
    return (int)((log10(val) - log10(min)) * (numIso - 1) / (log10(max) - log10(min)));
  }
  return 0;
}

unsigned int PViewOptions::getColor(double val, double min, double max, 
                                    bool forceLinear, int numColors)
{
  if(colorTable.size == 1) return colorTable.table[0];

  if(numColors <= 0){ // use full colormap
    int index = getScaleIndex(val, colorTable.size, min, max, forceLinear);
    if(index < 0) index = 0;
    else if(index > colorTable.size - 1) index = colorTable.size - 1;
    return colorTable.table[index];
  }
  else{
    // the maximum should belong to the last interval: so use
    // numColors + 1 and correct afterwards
    int index = getScaleIndex(val, numColors + 1, min, max, forceLinear);
    if(index > numColors - 1) index = numColors - 1;
    return getColor(index, numColors);
  }
}

unsigned int PViewOptions::getColor(int i, int nb)
{
  int index = (nb == 1) ? colorTable.size / 2 : 
    (int)(i / (double)(nb - 1) * (colorTable.size - 1) + 0.5);
  if(index < 0) index = 0;
  else if(index > colorTable.size - 1) index = colorTable.size - 1;
  return colorTable.table[index];
}

void PViewOptions::destroyGeneralRaise()
{
  for(int i = 0; i < 3; i++){
#if defined(HAVE_MATH_EVAL)
    if(genRaiseFunction[i])
      evaluator_destroy(genRaiseFunction[i]);
    genRaiseFunction[i] = 0;
#else
    genRaiseFunction[i] = (void*)-1;
#endif
  }
}

void PViewOptions::createGeneralRaise()
{
  destroyGeneralRaise();

  const char *expr[3] = {genRaiseX.c_str(), genRaiseY.c_str(), genRaiseZ.c_str()};
#if defined(HAVE_MATH_EVAL)
  for(int i = 0; i < 3; i++) {
    if(strlen(expr[i])) {
      if(!(genRaiseFunction[i] = evaluator_create((char*)expr[i])))
        Msg::Error("Invalid expression '%s'", expr[i]);
    }
  }
#else
  for(int i = 0; i < 3; i++) {
    if(!strcmp(expr[i], "v0")) genRaiseFunction[i] = (void*)0;
    else if(!strcmp(expr[i], "v1")) genRaiseFunction[i] = (void*)1;
    else if(!strcmp(expr[i], "v2")) genRaiseFunction[i] = (void*)2;
    else if(!strcmp(expr[i], "v3")) genRaiseFunction[i] = (void*)3;
    else if(!strcmp(expr[i], "v4")) genRaiseFunction[i] = (void*)4;
    else if(!strcmp(expr[i], "v5")) genRaiseFunction[i] = (void*)5;
    else if(!strcmp(expr[i], "v6")) genRaiseFunction[i] = (void*)6;
    else if(!strcmp(expr[i], "v7")) genRaiseFunction[i] = (void*)7;
    else if(!strcmp(expr[i], "v8")) genRaiseFunction[i] = (void*)8;
    else if(strlen(expr[i])) {
      Msg::Error("Invalid expression '%s'", expr[i]);
      return;
    }
  }
#endif
}

bool PViewOptions::skipElement(int type)
{
  switch(type){
  case TYPE_PNT: return !drawPoints;
  case TYPE_LIN: return !drawLines;
  case TYPE_TRI: return !drawTriangles;
  case TYPE_QUA: return !drawQuadrangles;
  case TYPE_TET: return !drawTetrahedra;
  case TYPE_HEX: return !drawHexahedra;
  case TYPE_PRI: return !drawPrisms;
  case TYPE_PYR: return !drawPyramids;
  default: return true;
  }
}
