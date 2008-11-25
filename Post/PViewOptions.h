// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PVIEW_OPTIONS_H_
#define _PVIEW_OPTIONS_H_

#include <string>
#include "ColorTable.h"
#include "SBoundingBox3d.h"

// The display options of a post-processing view.
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
  int Clip; // status of clip planes (bit array)
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
  // return a floating point value in [min, max] corresponding to the
  // integer iso in [0, numIso - 1]
  double getScaleValue(int iso, int numIso, double min, double max);
  // return an integer in [0, numIso - 1] corresponding to the
  // floating point value val in [min, max]
  int getScaleIndex(double val, int numIso, double min, double max, 
                    bool forceLinear=false);
  // get color for val in [min, max] (only use numColors if > 0
  // instead of all available colors)
  unsigned int getColor(double val, double min, double max, 
                        bool forceLinear=false, int numColors=-1);
  // get i-th color amongst nb (i in [0, nb - 1])
  unsigned int getColor(int i, int nb);
  // create/destroy math evaluators for general raise option
  void createGeneralRaise();
  void destroyGeneralRaise();
  // return true if one should not draw elements with numEdges edges
  bool skipElement(int numEdges);
};

#endif
