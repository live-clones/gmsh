// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef HIGH_ORDER_MESH_FAST_CURVING_H
#define HIGH_ORDER_MESH_FAST_CURVING_H

class GModel;

struct FastCurvingParameters {
  enum OUTERBLCURVE { OUTER_NOCURVE, OUTER_CURVE, OUTER_CURVECONSERVATIVE };
  int dim; // Spatial dimension of the mesh to curve
  bool onlyVisible; // Apply curving to visible entities ONLY?
  bool optimizeGeometry; // Optimize boundary edges/faces to fit geometry?
  OUTERBLCURVE
  curveOuterBL; // Curve also the outer surface of the boundary layer?
  int maxNumLayers; // Maximum number of layers of elements to curve in BL
  double
    maxRho; // Maximum ratio min/max edge/face size for elements to curve in BL
  double maxAngle; // Maximum angle between layers of elements to curve in BL
  double maxAngleInner; // Maximum angle between edges/faces within layers of
                        // triangles/tets to curve in BL

  // New algo (experimental)
  bool useNewAlgo; // Curve boundary layer with new algo
  bool newAlgoSmoothBoundary; // Smooth boundary before
  double newAlgoAlignmentFactor; // Try to align edges of adjacent elements if > 0
  bool newAlgoSmoothEndOfBL; // Smooth last layer
  double newAlgoEndLinearizationFactor; // Reduce curving of last layer if > 0
  bool newAlgoEnsureQualityOuterMesh; // Check the validity/quality of the outer mesh
  // If newAlgoEnsureQualityOuterMesh=ON, newAlgoSmoothEndOfBL=ON or newAlgoEndLinearizationFactor>0:
  double newAlgoBackpropLimit; // % of thickness layer not concerned by backpropagation algorithm

  FastCurvingParameters()
    : dim(3), onlyVisible(true), optimizeGeometry(false),
      curveOuterBL(OUTER_NOCURVE), maxNumLayers(100), maxRho(0.3),
      maxAngle(3.1415927 * 10. / 180.), maxAngleInner(3.1415927 * 30. / 180.)
  {
  }
};

void HighOrderMeshFastCurving(GModel *gm, FastCurvingParameters &p,
                              bool requireBLInfo = false);

#endif
