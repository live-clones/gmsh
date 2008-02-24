// $Id: PViewOptions.cpp,v 1.19 2008-02-24 16:18:19 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
#include "PViewOptions.h"
#include "Message.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

PViewOptions PViewOptions::reference;

PViewOptions::PViewOptions()
{
  for(int i = 0; i < 3; i++) GenRaise_f[i] = 0;
  ColorTable_InitParam(2, &CT);
  ColorTable_Recompute(&CT);
}

PViewOptions::~PViewOptions()
{
  destroyGeneralRaise();
}

double PViewOptions::getScaleValue(int iso, int numIso, double min, double max)
{
  if(numIso == 1) return (min + max) / 2.;
  
  if(ScaleType == Linear){
    return min + iso * (max - min) / (numIso - 1.);
  }
  else if(ScaleType == Logarithmic){
    // should translate scale instead, with smallest val an option!
    if(min < 0.) return 0;
    return pow(10., log10(min) + iso * (log10(max) - log10(min)) / (numIso - 1.));
  }
  else if(ScaleType == DoubleLogarithmic){
    if(min < 0.) return 0;
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

  if(forceLinear || ScaleType == Linear){
    return (int)((val - min) * (numIso - 1) / (max - min));
  }
  else if(ScaleType == Logarithmic){
    if(min <= 0.) return 0;
    return (int)((log10(val) - log10(min)) * (numIso - 1) / (log10(max) - log10(min)));
  }
  else if(ScaleType == DoubleLogarithmic){
    // FIXME
    if(min <= 0.) return 0;
    return (int)((log10(val) - log10(min)) * (numIso - 1) / (log10(max) - log10(min)));
  }
  return 0;
}

// val in [min, max]
unsigned int PViewOptions::getColor(double val, double min, double max, 
				    bool forceLinear)
{
  if(CT.size == 1) return CT.table[0];
  int index = getScaleIndex(val, CT.size, min, max, forceLinear);
  return CT.table[index];
}

// i in [0, nb - 1]
unsigned int PViewOptions::getColor(int i, int nb)
{
  int index = (nb == 1) ? CT.size / 2 : 
    (int)(i / (double)(nb - 1) * (CT.size - 1) + 0.5);
  return CT.table[index];
}

void PViewOptions::destroyGeneralRaise()
{
  for(int i = 0; i < 3; i++){
#if defined(HAVE_MATH_EVAL)
    if(GenRaise_f[i])
      evaluator_destroy(GenRaise_f[i]);
    GenRaise_f[i] = 0;
#else
    GenRaise_f[i] = (void*)-1;
#endif
  }
}

void PViewOptions::createGeneralRaise()
{
  destroyGeneralRaise();

  char *expr[3] = {GenRaiseX, GenRaiseY, GenRaiseZ};
#if defined(HAVE_MATH_EVAL)
  for(int i = 0; i < 3; i++) {
    if(strlen(expr[i])) {
      if(!(GenRaise_f[i] = evaluator_create(expr[i])))
        Msg(GERROR, "Invalid expression '%s'", expr[i]);
    }
  }
#else
  for(int i = 0; i < 3; i++) {
    if(!strcmp(expr[i], "v0")) GenRaise_f[i] = (void*)0;
    else if(!strcmp(expr[i], "v1")) GenRaise_f[i] = (void*)1;
    else if(!strcmp(expr[i], "v2")) GenRaise_f[i] = (void*)2;
    else if(!strcmp(expr[i], "v3")) GenRaise_f[i] = (void*)3;
    else if(!strcmp(expr[i], "v4")) GenRaise_f[i] = (void*)4;
    else if(!strcmp(expr[i], "v5")) GenRaise_f[i] = (void*)5;
    else if(!strcmp(expr[i], "v6")) GenRaise_f[i] = (void*)6;
    else if(!strcmp(expr[i], "v7")) GenRaise_f[i] = (void*)7;
    else if(!strcmp(expr[i], "v8")) GenRaise_f[i] = (void*)8;
    else if(strlen(expr[i])) {
      Msg(GERROR, "Invalid expression '%s'", expr[i]);
      return;
    }
  }
#endif
}

bool PViewOptions::skipElement(int numEdges)
{
  switch(numEdges){
  case 0: return !DrawPoints;
  case 1: return !DrawLines;
  case 3: return !DrawTriangles;
  case 4: return !DrawQuadrangles;
  case 6: return !DrawTetrahedra;
  case 12: return !DrawHexahedra;
  case 9: return !DrawPrisms;
  case 8: return !DrawPyramids;
  default: return true;
  }
}
