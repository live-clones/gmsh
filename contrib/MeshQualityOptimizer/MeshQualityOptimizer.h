// MeshQualityOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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

#ifndef MESHQUALITYOPTIMIZER_H
#define MESHQUALITYOPTIMIZER_H

class GModel;

struct MeshQualOptParameters {
  bool onlyValidity;
  bool excludeQuad, excludeHex, excludePrism, excludeBL;
  double minTargetIdealJac;
  double minTargetInvCondNum;
  double weight; // Weight of the node displacement contribution
  int nbLayers; // Number of layers taken around a bad element
  int dim; // Which dimension to optimize
  int maxOptIter; // Max. number of iterations in the optimization process
  int maxBarrierUpdates; // Max. number of barrier moves ("runs")
  bool onlyVisible; // If optimization applied to visible entities ONLY
  double distanceFactor; // Distance criterion for patch creation
  int fixBndNodes; // If points on all (1) or periodic (2) boundaries are fixed
  int strategy; // 0 = connected blobs, 1 = adaptive one-by-one
  int maxPatchAdapt; // Max. nb. of patch adaptation iterations (if adaptive)
  int maxLayersAdaptFact; // Growth factor in number of layers for patch
                          // adaptation (if adaptive)
  double distanceAdaptFact; // Growth factor in distance factor for patch
                            // adaptation (if adaptive)
  int nCurses; // Enhanced text output
  std::string logFileName; // External log file

  int SUCCESS; // 0 --> success , 1 --> Not converged
  double minIdealJac, maxIdealJac; // after optimization, range of jacobians
  double minInvCondNum, maxInvCondNum; // after optimization, range of jacobians
  double CPU; // Time for optimization

  MeshQualOptParameters()
    : onlyValidity(false), excludeQuad(false), excludeHex(false),
      excludePrism(false), excludeBL(false), minTargetIdealJac(0.1),
      minTargetInvCondNum(0.1), weight(1.), nbLayers(6), dim(3),
      maxOptIter(300), maxBarrierUpdates(50), onlyVisible(true),
      distanceFactor(12), fixBndNodes(false), strategy(0), maxPatchAdapt(3),
      maxLayersAdaptFact(2), distanceAdaptFact(2.), nCurses(1), logFileName(""),
      SUCCESS(-1), minIdealJac(0.), maxIdealJac(0.), minInvCondNum(0.),
      maxInvCondNum(0.), CPU(0.)
  {
  }
};

void MeshQualityOptimizer(GModel *gm, MeshQualOptParameters &p);

#endif
