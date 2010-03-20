// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <vector>
#include <string>
#include "CGNSOptions.h"
#include "meshPartitionOptions.h"

// The interface-independent context.

struct contextMeshOptions {
  int draw, changed, light, lightTwoSide, lightLines, pointType;
  int points, lines, triangles, quadrangles, tetrahedra, hexahedra, prisms, pyramids;
  int surfacesEdges, surfacesFaces, volumesEdges, volumesFaces, numSubEdges;
  int pointsNum, linesNum, surfacesNum, volumesNum;
  int optimize, optimizeNetgen, refineSteps, qualityType, labelType, remove4triangles;
  double normals, tangents, explode, angleSmoothNormals, allowSwapEdgeAngle;
  double mshFileVersion, mshFilePartitioned, labelFrequency, pointSize, lineWidth;
  double qualityInf, qualitySup, radiusInf, radiusSup;
  double scalingFactor, lcFactor, randFactor, lcIntegrationPrecision;
  double lcMin, lcMax, toleranceEdgeLength;
  int lcFromPoints, lcFromCurvature, lcExtendFromBoundary;
  int dual, voronoi, drawSkinOnly, colorCarousel;
  int format, nbSmoothing, algo2d, algo3d, algoSubdivide;
  int order, secondOrderLinear, secondOrderIncomplete;
  int secondOrderExperimental, meshOnlyVisible;
  int smoothInternalEdges, minCircPoints, minCurvPoints;
  int saveAll, saveGroupsOfNodes, binary, bdfFieldFormat, saveParametric;
  int smoothNormals, reverseAllNormals, zoneDefinition, clip;
  int saveElementTagType;  
};

struct contextGeometryOptions {
  int draw, light, lightTwoSide, points, lines, surfaces, volumes;
  int pointsNum, linesNum, surfacesNum, volumesNum;
  double pointSize, lineWidth, selectedPointSize, selectedLineWidth;
  int pointType, lineType, surfaceType, numSubEdges;
  int oldCircle, extrudeSplinePoints, extrudeReturnLateral, oldNewreg;
  double normals, tangents, scalingFactor;
  int autoCoherence, highlightOrphans, clip, useTransform;
  double tolerance, snap[3], transform[3][3], offset[3];
  int occFixSmallEdges, occFixSmallFaces, occSewFaces, occConnectFaces;
  int copyMeshingMethod, exactExtrusion;
  int matchGeomAndMesh;
};

class CTX {
 private:
  static CTX *_instance;
 public:
  CTX();
  ~CTX(){}
  static CTX *instance();
 public:
  // files on the command line and various file names
  std::vector<std::string> files;
  std::string bgmFileName, outputFileName, defaultFileName, tmpFileName;
  std::string sessionFileName, optionsFileName, errorFileName;
  std::string meshStatReportFileName;
  // the home directory
  std::string homeDir;
  // file history
  std::vector<std::string> recentFiles;
  // create mesh statistics report (0: do nothing, 1: create, 2: append)
  int createAppendMeshStatReport;
  // save session/option file on exit?
  int sessionSave, optionsSave;
  // ask confirmation when overwriting files?
  int confirmOverwrite;
  // forced display host:0.0 under X11 
  std::string display;
  // FLTK theme
  std::string guiTheme;
  // print messages on to the terminal?
  int terminal;
  // number of graphical windows/tiles
  int numWindows, numTiles;
  // text editor and web browser command (with included '%s')
  std::string editor, webBrowser;
  // pattern of files to watch out for
  std::string watchFilePattern;
  // show tootips in the GUI?
  int tooltips;
  // scroll automatically to last message in the message window?
  int msgAutoScroll;
  // position and size of various windows in the GUI
  int menuPosition[2], glPosition[2], glSize[2], msgPosition[2], msgSize[2];
  int optPosition[2], visPosition[2], clipPosition[2], manipPosition[2];
  int statPosition[2], ctxPosition[2], solverPosition[2];
  int pluginPosition[2], pluginSize[2], fieldPosition[2], fieldSize[2];
  int fileChooserPosition[2];
  // use the system menu bar on Mac OS X?
  int systemMenuBar;
  // batch mode (-4: lua session, -3: server daemon, -2: check coherence, -1: write
  // geo, 0: full gfx, 1: 1D mesh, 2: 2D mesh, 3: 3D mesh, 4: adapt
  // mesh, 5: refine mesh)
  int batch; 
  // batch operations to apply after meshing (1: partition mesh)
  int batchAfterMesh;
  // initial menu (0: automatic, 1: geom, 2: mesh, 3: solver, 4: post)
  int initialContext;
  // never popup dialogs in scripts (use default values instead)?
  int noPopup;
  // make all windows "non modal"?
  int nonModalWindows;
  // clipping plane distance factor
  double clipFactor;
  // do or do not use the trackball for rotations
  int useTrackball;
  // point around which to rotate the scene
  double rotationCenter[3];
  // rotate around the center of mass instead of rotationCenter[]
  int rotationCenterCg;
  // "overall" x, y and z min used for drawing and lc computation
  double min[3], max[3];
  // "center of mass" of the current geometry, used for graphics only
  double cg[3];
  // characteristic length for the whole problem (never used in mesh
  // generation ->only for geo/post)
  double lc;
  // double buffer/antialias graphics?
  int db, antialiasing;
  // orthogonal projection? 
  int ortho;
  // draw the bounding boxes and the rot center?
  int drawBBox, drawRotationCenter;
  // draw simplified model during user interaction?
  int fastRedraw;
  // small axes options
  int smallAxes, smallAxesSize, smallAxesPos[2];
  // large axes options
  int axes, axesAutoPosition, axesTics[3], axesMikado;
  double axesPosition[6];
  std::string axesLabel[3], axesFormat[3];
  // simple dynamic lock (should be a mutex) 
  int lock;
  // enable alpha blending?
  int alpha;
  // mouse2 zoom coefficient
  double zoomFactor;
  // draw background gradient?
  int bgGradient;
  // draw background image?
  std::string bgImageFileName;
  double bgImagePosition[2];
  // fltk font size (and delta for palette windows)
  int fontSize, deltaFontSize;
  // font name, FLTK enum and size for opengl graphics
  std::string glFont, glFontTitle;
  int glFontEnum, glFontEnumTitle, glFontSize, glFontSizeTitle;
  // point/line widths
  double pointSize, lineWidth;
  // light options
  int light[6];
  double lightPosition[6][4], shine, shineExponent;
  // clipping plane options
  double clipPlane[6][4];
  int clipWholeElements, clipOnlyDrawIntersectingVolume, clipOnlyVolume;
  // polygon offset options
  int polygonOffset, polygonOffsetAlways;
  double polygonOffsetFactor, polygonOffsetUnits;
  // color scheme
  int colorScheme;
  // number of subdivisions for gluQuadrics
  int quadricSubdivisions;
  // vector display type and options (for normals, etc.)
  int vectorType;
  double arrowRelHeadRadius, arrowRelStemRadius, arrowRelStemLength;
  // records cpu times for 1-D, 2-D and 3-D mesh generation
  double meshTimer[3];
  // dynamic variable tracking if the bbox is currently imposed
  int forcedBBox;
  // enable selection/hover/picking using the mouse
  int mouseSelection, mouseHoverMeshes, pickElements;
  // disable some warnings for expert users?
  int expertMode;
  // dynamic: equal to 1 while gmsh is printing
  int printing;
  // hide all unselected entities?
  int hideUnselected;
  // temporary storage of rotation, translation, scale (until the GUI
  // is ready)
  double tmpRotation[3], tmpTranslation[3], tmpScale[3], tmpQuaternion[4];
  // geometry options 
  contextGeometryOptions geom;
  // mesh options 
  contextMeshOptions mesh;
  // FIXME: putting these in the mesh struct (where they belong) causes 
  // an LNK1179 error ("duplicate COMDAT") with MSVC...
  meshPartitionOptions partitionOptions;
  CGNSOptions cgnsOptions;
  // post processing options 
  struct{
    int draw, link, horizontalScales;
    int smooth, animCycle, combineTime, combineRemoveOrig;
    int fileFormat, plugins;
    double animDelay;
  }post;
  // solver options 
  struct{
    int plugins, listen;
    std::string socketName;
  }solver;
  // print options 
  struct{
    int format, epsQuality, epsBackground, epsCompress, epsPS3Shading;
    int epsOcclusionCulling, epsBestRoot;
    double epsLineWidthFactor, epsPointSizeFactor;
    int jpegQuality, jpegSmoothing, geoLabels, text, texAsEquation;
    int gifDither, gifSort, gifInterlace, gifTransparent;
    int posElementary, posElement, posGamma, posEta, posRho, posDisto;
    int compositeWindows;
  } print;
  // color options
  struct{
    unsigned int bg, bgGrad, fg, text, axes, smallAxes;
    unsigned int ambientLight[6], diffuseLight[6], specularLight[6];
    struct{
      unsigned int point, line, surface, volume;
      unsigned int selection, highlight[3], projection;
      unsigned int tangents, normals;
    } geom;
    struct{
      unsigned int vertex, vertexSup, line, triangle, quadrangle;
      unsigned int tetrahedron, hexahedron, prism, pyramid;
      unsigned int carousel[20];
      unsigned int tangents, normals;
    } mesh;
  } color;
  // is the machine big-endian?
  int bigEndian;
  // how RGBA values are packed and unpacked into/from an unsigned
  // integer to be fed to glColor4ubv (depends on machine byte
  // ordering!):
  unsigned int packColor(int R, int G, int B, int A);
  int unpackRed(unsigned int X);
  int unpackGreen(unsigned int X);
  int unpackBlue(unsigned int X);
  int unpackAlpha(unsigned int X);
};

#endif
