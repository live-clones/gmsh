// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <string.h>
#include "GmshConfig.h"
#include "Context.h"
#include "OS.h"

#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#endif

CTX::CTX()
{
  // initialize everything that has no default value in
  // DefaultOptions.h
  short int word = 0x0001;
  char *byte = (char*)&word;
  bigEndian = (byte[0] ? 0 : 1);

  const char *tmp;
  if((tmp = GetEnvironmentVar("GMSH_HOME")))
    homeDir = tmp;
  else if((tmp = GetEnvironmentVar("HOME")))
    homeDir = tmp;
  else if((tmp = GetEnvironmentVar("TMP")))
    homeDir = tmp;
  else if((tmp = GetEnvironmentVar("TEMP")))
    homeDir = tmp;
  else
    homeDir = "";
  int len = homeDir.size();
  if(len && homeDir[len - 1] != '/')
    homeDir += "/";

  batch = batchAfterMesh = 0;
  outputFileName = "";
  bgmFileName = "";
  createAppendMeshStatReport = 0;
  lc = 1.;
  min[0] = min[1] = min[2] = max[2] = 0.; 
  max[0] = max[1] = 1.; // for nice view when adding point in new model
  cg[0] = cg[1] = cg[2] = 0.;
  polygonOffset = 0;
  printing = 0;
  meshTimer[0] = meshTimer[1] = meshTimer[2] = 0.;
  drawRotationCenter = 0;
  pickElements = 0;
  geom.draw = 1;
  mesh.draw = 1;
  post.draw = 1;
  post.combineTime = 0; // try to combineTime views at startup
  lock = 0; // very primitive locking
    
#if defined(HAVE_FLTK)
  glFontEnum = FL_HELVETICA;
#else
  glFontEnum = -1;
#endif
  forcedBBox = 0;
  hideUnselected = 0;
  showCompounds = 0;
  numWindows = numTiles = 1;
  deltaFontSize = 0;
  recentFiles.resize(5);
  mesh.optimizeLloyd = 0;

  // need to initialize these too, since the corresponding opt_XXX
  // routine uses the current value to set "mesh.changed"
  mesh.changed = 0;
  mesh.qualityInf = mesh.qualitySup = mesh.qualityType = 0;
  mesh.radiusInf = mesh.radiusSup = 0;
  mesh.lines = mesh.triangles = mesh.tetrahedra = mesh.quadrangles = 0;
  mesh.prisms = mesh.pyramids = mesh.hexahedra = 0;
  mesh.volumesEdges = mesh.volumesFaces = mesh.surfacesEdges = mesh.surfacesFaces = 0;
  mesh.volumesFaces = mesh.surfacesEdges = mesh.surfacesFaces = 0;
  mesh.smoothInternalEdges = mesh.smoothNormals = mesh.reverseAllNormals = 0;
  mesh.explode = mesh.angleSmoothNormals = 0.;
  mesh.numSubEdges = 0;
  mesh.colorCarousel = 0;
  color.mesh.tangents = color.mesh.tetrahedron = color.mesh.triangle = 0;
  color.mesh.prism = color.mesh.pyramid = color.mesh.hexahedron = 0;
  color.mesh.tangents = color.mesh.line = color.mesh.quadrangle = 0;
  for (int i = 0; i < 20; i++)
    color.mesh.carousel[i] = 0;
}

CTX *CTX::_instance = 0;

CTX *CTX::instance()
{
  if(!_instance) _instance = new CTX();
  return _instance;
}

unsigned int CTX::packColor(int R, int G, int B, int A)
{
  if(bigEndian)
    return ( (unsigned int)((R)<<24 | (G)<<16 | (B)<<8 | (A)) );
  else
    return ( (unsigned int)((A)<<24 | (B)<<16 | (G)<<8 | (R)) );
}

int CTX::unpackRed(unsigned int X)
{
  if(bigEndian)
    return ( ( (X) >> 24 ) & 0xff );
  else
    return ( (X) & 0xff );
}

int CTX::unpackGreen(unsigned int X)
{
  if(bigEndian)
    return ( ( (X) >> 16 ) & 0xff );
  else
    return ( ( (X) >> 8 ) & 0xff );
}

int CTX::unpackBlue(unsigned int X)
{
  if(bigEndian)
    return ( ( (X) >> 8 ) & 0xff );
  else
    return ( ( (X) >> 16 ) & 0xff );
}

int CTX::unpackAlpha(unsigned int X)
{
  if(bigEndian)
    return ( (X) & 0xff );
  else
    return ( ( (X) >> 24 ) & 0xff );
}

