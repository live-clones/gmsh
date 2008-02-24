#ifndef _PVIEW_OPTIONS_H_
#define _PVIEW_OPTIONS_H_

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

#include <string>
#include "ColorTable.h"
#include "SBoundingBox3d.h"

class PViewOptions {
 public:
  enum PlotType {
    Plot3D = 1,
    Plot2DSpace = 2,
    Plot2DTime = 3
  };
  enum IntervalsType {
    Iso = 1,
    Continuous = 2,
    Discrete = 3,
    Numeric = 4
  };
  enum VectorType {
    Segment = 1,
    Arrow = 2,
    Pyramid = 3,
    Arrow3D = 4,
    Displacement = 5
  };
  enum TensorType {
    VonMises = 1
  };
  enum GlyphLocation {
    COG = 1,
    Vertex = 2
  };
  enum RangeType {
    Default = 1,
    Custom = 2,
    PerTimeStep = 3
  };
  enum ScaleType {
    Linear = 1,
    Logarithmic = 2,
    DoubleLogarithmic = 3
  };

  int Type;
  int Position[2], Size[2], AutoPosition;
  char Format[256];
  int Axes, AxesAutoPosition,AxesMikado, AxesTics[3];
  char AxesFormat[3][256], AxesLabel[3][256];
  double AxesPosition[6];
  double CustomMin, CustomMax, TmpMin, TmpMax, ExternalMin, ExternalMax;
  SBoundingBox3d TmpBBox;
  double Offset[3], Raise[3], Transform[3][3], DisplacementFactor, NormalRaise;
  double Explode;
  double ArrowSize, ArrowRelHeadRadius, ArrowRelStemRadius, ArrowRelStemLength;
  double Normals, Tangents;
  int Visible, IntervalsType, NbIso, ArrowSizeProportional;
  int Light, LightTwoSide, LightLines, SmoothNormals;
  double AngleSmoothNormals;
  int SaturateValues, FakeTransparency;
  int ShowElement, ShowTime, ShowScale;
  int ScaleType, RangeType;
  int VectorType, TensorType, GlyphLocation, CenterGlyphs;
  int TimeStep;
  int DrawStrings;
  int DrawPoints, DrawLines, DrawTriangles, DrawQuadrangles;
  int DrawTetrahedra, DrawHexahedra, DrawPrisms, DrawPyramids;
  int DrawScalars, DrawVectors, DrawTensors;
  int Boundary, PointType, LineType, DrawSkinOnly;
  double PointSize, LineWidth;
  GmshColorTable CT;
  int UseStipple, Stipple[10][2];
  char StippleString[10][32];
  int ExternalViewIndex, ViewIndexForGenRaise;
  int UseGenRaise;
  double GenRaiseFactor;
  char GenRaiseX[256], GenRaiseY[256], GenRaiseZ[256];
  void *GenRaise_f[3];
  double TargetError;
  int MaxRecursionLevel;
  struct{
    unsigned int point, line, triangle, quadrangle;
    unsigned int tetrahedron, hexahedron, prism, pyramid;
    unsigned int tangents, normals;
    unsigned int text2d, text3d, axes;
  } color;
 public:
  // static reference container that contains default values
  static PViewOptions reference;
  PViewOptions();
  ~PViewOptions();
  void createGeneralRaise();
  void destroyGeneralRaise();
  double getScaleValue(int iso, int numIso, double min, double max);
  int getScaleIndex(double val, int numIso, double min, double max, 
		    bool forceLinear=false);
  unsigned int getColor(int i, int nb);
  unsigned int getColor(double val, double min, double max, bool forceLinear=false);
  bool skipElement(int numEdges);
};

#endif
