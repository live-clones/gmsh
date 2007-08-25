// $Id: PViewOptions.cpp,v 1.4 2007-08-25 19:19:49 geuzaine Exp $
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

PViewOptions::PViewOptions()
{
  // FIXME: remove this once Options.cpp uses PViewOptions!
  Type = Plot3D;
  AutoPosition = 1;
  strcpy(Format, "%g");
  Axes = 0;
  for(int i = 0; i < 3; i++){
    Offset[i] = Raise[i] = 0.;
    for(int j = 0; j < 3; j++){
      Transform[i][j] = (i == j) ? 1. : 0.;
    }
  }
  DisplacementFactor = 0.;
  Explode = 1.;
  ArrowSize = 50;
  ArrowRelHeadRadius = 0.5;
  ArrowRelStemRadius = 0.2;
  ArrowRelStemLength = 0.7;
  Normals = Tangents = 0.;
  Visible = 1;
  IntervalsType = Continuous;
  //IntervalsType = Discrete;
  NbIso = 15;
  ArrowSizeProportional = 0;
  Light = LightTwoSide = 1;
  LightLines = 1;
  SmoothNormals = 0;
  AngleSmoothNormals = 30;
  SaturateValues = 0;
  FakeTransparency = 0;
  ShowElement = 1;
  ShowTime = ShowScale = 1;
  ScaleType = Default;
  RangeType = Linear;
  VectorType = Arrow3D;
  TensorType = VonMises;
  GlyphLocation = COG;
  TimeStep = 0;
  DrawStrings = DrawPoints = DrawLines = DrawTriangles = DrawQuadrangles =
    DrawTetrahedra = DrawHexahedra = DrawPrisms = DrawPyramids =
    DrawScalars = DrawVectors = DrawTensors = 1;
  Boundary = 0;
  PointType = LineType = 0;
  PointSize = LineWidth = 1;
  UseStipple = 0;
  ExternalViewIndex = ViewIndexForGenRaise = -1;
  UseGenRaise = 0;
  GenRaiseFactor = 0.;

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

// val in [min, max]
unsigned int PViewOptions::getColor(double val, double min, double max)
{
  //int index = v->GIFV(min, max, v->CT.size, val);

  if(CT.size == 1) return CT.table[0];

  int index = (min == max) ? CT.size / 2 :
    (int)((val - min) * (CT.size - 1) / (max - min));

  return CT.table[index];
}

// i in [0, nb - 1]
unsigned int PViewOptions::getColor(int i, int nb)
{
  int index = (nb == 1) ? CT.size / 2 : 
    (int)(i / (double)(nb - 1) * (CT.size - 1) + 0.5);

  return CT.table[index];
}
