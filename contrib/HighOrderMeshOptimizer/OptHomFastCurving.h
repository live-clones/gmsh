// Copyright (C) 2013 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef _OPTHOMFASTCURVING_H_
#define _OPTHOMFASTCURVING_H_

class GModel;

struct FastCurvingParameters {
  int dim ;                       // Spatial dimension of the mesh to curve
  bool onlyVisible ;              // Apply curving to visible entities ONLY?
  bool optimizeGeometry;          // Optimize boundary edges/faces to fit geometry?
  bool curveOuterBL;              // Curve also the outer surface of the boundary layer?
  int maxNumLayers;               // Maximum number of layers of elements to curve in BL
  double maxRho;                  // Maximum ratio min/max edge/face size for elements to curve in BL
  double maxAngle;                // Maximum angle between layers of elements to curve in BL
  double maxAngleInner;           // Maximum angle between edges/faces within layers of triangles/tets to curve in BL

  FastCurvingParameters () :
    dim(3), onlyVisible(true), optimizeGeometry(false),
    curveOuterBL(false), maxNumLayers(100), maxRho(0.5),
    maxAngle(3.1415927*10./180.), maxAngleInner(3.1415927*30./180.)
  {
  }
};

void HighOrderMeshFastCurving(GModel *gm, FastCurvingParameters &p);

#endif
