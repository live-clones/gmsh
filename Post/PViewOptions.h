// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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

  int type;
  int position[2], size[2], autoPosition;
  std::string format;
  int axes, axesAutoPosition, axesMikado, axesTics[3];
  std::string axesFormat[3], axesLabel[3];
  double axesPosition[6];
  double customMin, customMax, tmpMin, tmpMax, externalMin, externalMax;
  SBoundingBox3d tmpBBox;
  double offset[3], raise[3], transform[3][3], displacementFactor, normalRaise;
  double explode;
  double arrowSizeMin, arrowSizeMax;
  double normals, tangents;
  int visible, intervalsType, nbIso;
  int light, lightTwoSide, lightLines, smoothNormals;
  double angleSmoothNormals;
  int saturateValues, fakeTransparency;
  int showElement, showTime, showScale;
  int scaleType, rangeType;
  int vectorType, tensorType, glyphLocation, centerGlyphs;
  int timeStep;
  int drawStrings;
  int drawPoints, drawLines, drawTriangles, drawQuadrangles;
  int drawTetrahedra, drawHexahedra, drawPrisms, drawPyramids;
  int drawScalars, drawVectors, drawTensors;
  int boundary, pointType, lineType, drawSkinOnly;
  double pointSize, lineWidth;
  GmshColorTable colorTable;
  int useStipple, stipple[10][2];
  std::string stippleString[10];
  int externalViewIndex, viewIndexForGenRaise;
  int useGenRaise;
  double genRaiseFactor;
  std::string genRaiseX, genRaiseY, genRaiseZ;
  void *genRaiseFunction[3];
  int adaptVisualizationGrid, maxRecursionLevel;
  double targetError;
  int clip; // status of clip planes (bit array)
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
  // return true if one should not draw elements with type type
  bool skipElement(int type);
};

#endif
