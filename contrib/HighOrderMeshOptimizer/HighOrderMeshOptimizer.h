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

#ifndef HIGH_ORDER_MESH_OPTIMIZER_H
#define HIGH_ORDER_MESH_OPTIMIZER_H

class GModel;
class GEntity;

struct OptHomParameters {
  // INPUT ------>
  double BARRIER_MIN_METRIC; // minimum scaled jcaobian
  double BARRIER_MIN; // minimum scaled jcaobian
  double BARRIER_MAX; // maximum scaled jcaobian
  double weight; // weight of the energy for nodes
  int nbLayers; // number of layers taken around a bad element
  int dim; // which dimension to optimize
  int itMax; // max number of iterations in the optimization process
  int optPassMax; // max number of optimization passes
  double TMAX; // max CPU time allowed
  bool onlyVisible; // apply optimization to visible entities ONLY
  double distanceFactor; // filter elements such that no elements further away
                         // than DistanceFactor times the max distance to
                         // straight sided version of an element are optimized
  int fixBndNodes; // are points on all (1) or periodic (2) boundaries are fixed
  int strategy; // 0 = connected blobs, 1 = adaptive one-by-one
  int maxAdaptBlob; // Max. nb. of blob adaptation interations
  int
    adaptBlobLayerFact; // Growth factor in number of layers for blob adaptation
  double
    adaptBlobDistFact; // Growth factor in distance factor for blob adaptation
  bool optPrimSurfMesh; // Enable optimisation of p1 surface meshes
  bool optCAD; // Enable optimization of mesh vertices positions for geometrical
               // fitting
  double optCADWeight; // Weight
  double optCADDistMax; // Maximum allowed distance from the CAD
  double discrTolerance;
  bool lockCurvedBLElts; // Do not include in optimization elements already
                         // fixed by "fast curving"

  // OUTPUT ------>
  int SUCCESS; // 0 --> success , 1 --> Not converged
  int numBlobs;
  double minJac, maxJac; // after optimization, range of jacobians
  double CPU; // Time for optimization

  OptHomParameters()
    : BARRIER_MIN_METRIC(-1.), BARRIER_MIN(0.1), BARRIER_MAX(2.0), weight(1.),
      nbLayers(6), dim(3), itMax(300), optPassMax(50), onlyVisible(true),
      distanceFactor(12), fixBndNodes(0), strategy(0), maxAdaptBlob(3),
      adaptBlobLayerFact(2.), adaptBlobDistFact(2.), optPrimSurfMesh(false),
      optCAD(false), optCADWeight(1000.), optCADDistMax(1.e22),
      discrTolerance(1.e-4), lockCurvedBLElts(true), SUCCESS(0), numBlobs(0),
      minJac(0.), maxJac(0.), CPU(0.)
  {
  }
};

void HighOrderMeshOptimizer(GModel *gm, OptHomParameters &p);

#endif
