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
// <gmsh@geuz.org>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef _MESHQUALITYOPTIMIZER_H_
#define _MESHQUALITYOPTIMIZER_H_

class GModel;

struct MeshQualOptParameters {
  double minTargetNCJ, maxTargetNCJ;
  double weightFixed ; // weight of the energy for fixed nodes
  double weightFree ; // weight of the energy for free nodes
  int nbLayers ; // number of layers taken around a bad element
  int dim ; // which dimension to optimize
  int itMax ; // max number of iterations in the optimization process
  int optPassMax ; // max number of optimization passes
  bool onlyVisible ; // apply optimization to visible entities ONLY
  double distanceFactor; // filter elements such that no elements further away
                         // than DistanceFactor times the max distance to
                         // straight sided version of an element are optimized
  bool fixBndNodes;  // how jacobians are computed and if points can move on boundaries
  int strategy; // 0 = connected blobs, 1 = adaptive one-by-one
  int maxAdaptBlob; // Max. nb. of blob adaptation interations
  int adaptBlobLayerFact; // Growth factor in number of layers for blob adaptation
  double adaptBlobDistFact; // Growth factor in distance factor for blob adaptation

  int SUCCESS ; // 0 --> success , 1 --> Not converged
  double minNCJ, maxNCJ; // after optimization, range of jacobians
  double CPU; // Time for optimization

  MeshQualOptParameters ()
    : minTargetNCJ(0.5), maxTargetNCJ(1.5), weightFixed(1000.),
      weightFree (1.), nbLayers (6) , dim(3) , itMax(300), optPassMax(50),
      onlyVisible(true), distanceFactor(12), fixBndNodes(false), strategy(0),
      maxAdaptBlob(3), adaptBlobLayerFact(2.), adaptBlobDistFact(2.)
  {
  }
};

void MeshQualityOptimizer(GModel *gm, MeshQualOptParameters &p);

#endif
