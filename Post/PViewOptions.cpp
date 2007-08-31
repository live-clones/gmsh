// $Id: PViewOptions.cpp,v 1.14 2007-08-31 09:18:16 geuzaine Exp $
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

#include "PViewOptions.h"
#include "Message.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

PViewOptions::PViewOptions()
{
  // FIXME: remove this once Options.cpp uses PViewOptions!

  //Type = Plot3D;
  //Type = Plot2DTime;
  Type = Plot2DSpace;

  AutoPosition = 1;
  strcpy(Format, "%g");
  Axes = 1;
  AxesAutoPosition = 1;
  for(int i = 0; i < 3; i++){
    AxesTics[i] = 10;
    strcpy(AxesFormat[i], "%g");
    strcpy(AxesLabel[i], "");
    Offset[i] = Raise[i] = 0.;
    for(int j = 0; j < 3; j++){
      Transform[i][j] = (i == j) ? 1. : 0.;
    }
  }
  DisplacementFactor = 1.;
  Explode = 1.;
  ArrowSize = 60;
  ArrowRelHeadRadius = 0.12;
  ArrowRelStemRadius = 0.02;
  ArrowRelStemLength = 0.56;
  Normals = 0.;
  Tangents = 0.;
  Visible = 1;
  IntervalsType = Continuous;
  //IntervalsType = Discrete;
  //IntervalsType = Iso;
  //IntervalsType = Numeric;
  NbIso = 15;
  ArrowSizeProportional = 1;
  Light = LightTwoSide = 1;
  LightLines = 1;
  SmoothNormals = 0;
  AngleSmoothNormals = 30;
  SaturateValues = 0;
  FakeTransparency = 0;
  ShowElement = 0;
  ShowTime = ShowScale = 1;
  ScaleType = Linear;
  VectorType = Arrow3D;
  //VectorType = Segment;
  //VectorType = Displacement;
  TensorType = VonMises;
  GlyphLocation = COG;
  CenterGlyphs = 0;
  TimeStep = 0;
  DrawStrings = DrawPoints = DrawLines = DrawTriangles = DrawQuadrangles =
    DrawTetrahedra = DrawHexahedra = DrawPrisms = DrawPyramids =
    DrawScalars = DrawVectors = DrawTensors = 1;
  Boundary = 0;
  PointType = LineType = 0;
  PointSize = 6;
  LineWidth = 2;
  UseStipple = 0;
  ExternalViewIndex = ViewIndexForGenRaise = -1;
  UseGenRaise = 0;
  GenRaiseFactor = 0.;
  RangeType = Default;
  RangeType = PerTimeStep;
  //RangeType = Custom;
  CustomMin = 0;
  CustomMax = 1.;

  color.point = 0;
  color.line = 0;
  color.triangle = 0;
  color.quadrangle = 0;
  color.tetrahedron = 0;
  color.hexahedron = 0;
  color.prism = 0;
  color.pyramid = 0;
  color.tangents = 0;
  color.normals = 0;
  color.text2d = 0;
  color.text3d = 0;
  color.axes = 0;

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

