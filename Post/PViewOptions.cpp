// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "PViewOptions.h"
#include "mathEvaluator.h"

PViewOptions PViewOptions::reference;

PViewOptions::PViewOptions() : genRaiseEvaluator(0)
{
  ColorTable_InitParam(2, &colorTable);
  ColorTable_Recompute(&colorTable);
}

PViewOptions::~PViewOptions()
{
  if(genRaiseEvaluator) delete genRaiseEvaluator;
}

double PViewOptions::getScaleValue(int iso, int numIso, double min, double max)
{
  if(numIso == 1) return (min + max) / 2.;
  
  if(scaleType == Linear){
    // treat min/max separately to avoid numerical errors (important
    // not to miss first/last discrete iso on piece-wise constant
    // datasets)
    if(iso == 0) return min;
    else if(iso == numIso - 1) return max;
    else return min + iso * (max - min) / (numIso - 1.);
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

void PViewOptions::createGeneralRaise()
{
  const char *names[] = 
    { "x", "y", "z", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8"};
  unsigned int numVariables = sizeof(names) / sizeof(names[0]);
  std::vector<std::string> expressions(3), variables(numVariables);
  expressions[0] = genRaiseX;
  expressions[1] = genRaiseY;
  expressions[2] = genRaiseZ;
  for(unsigned int i = 0; i < numVariables; i++) variables[i] = names[i];

  if(genRaiseEvaluator) delete genRaiseEvaluator;
  genRaiseEvaluator = new mathEvaluator(expressions, variables);
  if(expressions.empty()){
    delete genRaiseEvaluator;
    genRaiseEvaluator = 0;
  }
}

bool PViewOptions::skipElement(int type)
{
  switch(type){
  case TYPE_PNT: return !drawPoints;
  case TYPE_LIN: return !drawLines;
  case TYPE_TRI: return !drawTriangles;
  case TYPE_QUA: return !drawQuadrangles;
  case TYPE_POLYG: return false;
  case TYPE_TET: return !drawTetrahedra;
  case TYPE_HEX: return !drawHexahedra;
  case TYPE_PRI: return !drawPrisms;
  case TYPE_PYR: return !drawPyramids;
  case TYPE_POLYH: return false;
  default: return true;
  }
}
