// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <string.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "PViewOptions.h"
#include "mathEvaluator.h"

PViewOptions::PViewOptions() : genRaiseEvaluator(nullptr)
{
  ColorTable_InitParam(2, &colorTable);
  ColorTable_Recompute(&colorTable);
  currentTime = 0.;
}

PViewOptions::~PViewOptions()
{
  if(genRaiseEvaluator) delete genRaiseEvaluator;
}

PViewOptions *PViewOptions::_reference = nullptr;

PViewOptions *PViewOptions::reference()
{
  if(!_reference) _reference = new PViewOptions();
  return _reference;
}

double PViewOptions::getScaleThreshold(double min, double max) const
{
  if(scaleThreshold > 0.) return scaleThreshold;
  double m = std::max(fabs(min), fabs(max));
  return (m > 0.) ? m * 1.e-4 : 1.;
}

double PViewOptions::scaleForward(double v, double min, double max) const
{
  int type = getScaleType(min, max);
  if(type == Logarithmic) return log10(v);
  if(type == SymmetricLogarithmic) {
    // logarithmic beyond the threshold, linear inside it, and smooth where
    // they meet: a field that changes sign has both of its tails readable
    double s = getScaleThreshold(min, max);
    return (v < 0. ? -1. : 1.) * log10(1. + fabs(v) / s);
  }
  return v;
}

double PViewOptions::scaleInverse(double u, double min, double max) const
{
  int type = getScaleType(min, max);
  if(type == Logarithmic) return pow(10., u);
  if(type == SymmetricLogarithmic) {
    double s = getScaleThreshold(min, max);
    return (u < 0. ? -1. : 1.) * s * (pow(10., fabs(u)) - 1.);
  }
  return u;
}

double PViewOptions::getScaleValue(int iso, int numIso, double min, double max)
{
  if(numIso == 1) return (min + max) / 2.;

  // treat min/max separately to avoid numerical errors (important not to
  // miss first/last discrete iso on piece-wise constant datasets)
  if(iso <= 0) return min;
  if(iso >= numIso - 1) return max;

  double a = scaleForward(min, min, max), b = scaleForward(max, min, max);
  return scaleInverse(a + iso * (b - a) / (numIso - 1.), min, max);
}

int PViewOptions::getScaleIndex(double val, int numIso, double min, double max,
                                bool forceLinear)
{
  if(min == max) return numIso / 2;

  if(forceLinear || getScaleType(min, max) == Linear)
    return (int)((val - min) * (numIso - 1) / (max - min));

  // a value with no logarithm is off the end of a logarithmic scale
  if(scaleType == Logarithmic && val <= 0.) return 0;

  double a = scaleForward(min, min, max), b = scaleForward(max, min, max);
  return (int)((scaleForward(val, min, max) - a) * (numIso - 1) / (b - a));
}

unsigned int PViewOptions::getColor(double val, double min, double max,
                                    bool forceLinear, int numColors)
{
  if(colorTable.size == 1) return colorTable.table[0];

  if(numColors <= 0) { // use full colormap
    int index = getScaleIndex(val, colorTable.size, min, max, forceLinear);
    if(index < 0)
      index = 0;
    else if(index > colorTable.size - 1)
      index = colorTable.size - 1;
    return colorTable.table[index];
  }
  else {
    // the maximum should belong to the last interval: so use
    // numColors + 1 and correct afterwards
    int index = getScaleIndex(val, numColors + 1, min, max, forceLinear);
    if(index > numColors - 1) index = numColors - 1;
    return getColor(index, numColors);
  }
}

unsigned int PViewOptions::getColor(int i, int nb)
{
  int index = (nb == 1) ?
                colorTable.size / 2 :
                (int)(i / (double)(nb - 1) * (colorTable.size - 1) + 0.5);
  if(index < 0)
    index = 0;
  else if(index > colorTable.size - 1)
    index = colorTable.size - 1;
  return colorTable.table[index];
}

void PViewOptions::createGeneralRaise()
{
  const char *names[] = {"x",  "y",  "z",  "v0", "v1", "v2", "v3",
                         "v4", "v5", "v6", "v7", "v8", "s",  "t"};
  std::size_t numVariables = sizeof(names) / sizeof(names[0]);
  std::vector<std::string> expressions(3), variables(numVariables);
  expressions[0] = genRaiseX;
  expressions[1] = genRaiseY;
  expressions[2] = genRaiseZ;
  for(std::size_t i = 0; i < numVariables; i++) variables[i] = names[i];

  if(genRaiseEvaluator) delete genRaiseEvaluator;
  genRaiseEvaluator = new mathEvaluator(expressions, variables);
  if(expressions.empty()) {
    delete genRaiseEvaluator;
    genRaiseEvaluator = nullptr;
  }
}

bool PViewOptions::skipElement(int type)
{
  switch(type) {
  case TYPE_PNT: return !drawPoints;
  case TYPE_LIN: return !drawLines;
  case TYPE_TRI: return !drawTriangles;
  case TYPE_QUA: return !drawQuadrangles;
  case TYPE_POLYG: return false;
  case TYPE_TET: return !drawTetrahedra;
  case TYPE_HEX: return !drawHexahedra;
  case TYPE_PRI: return !drawPrisms;
  case TYPE_PYR: return !drawPyramids;
  case TYPE_TRIH: return !drawTrihedra;
  case TYPE_POLYH: return false;
  default: return true;
  }
}
