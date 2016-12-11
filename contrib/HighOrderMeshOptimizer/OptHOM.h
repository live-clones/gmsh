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

#ifndef _OPTHOM_H_
#define _OPTHOM_H_

#include <string>
#include <math.h>
#include "GmshConfig.h"
#include "OptHomMesh.h"
#include "simpleFunction.h"

#if defined(HAVE_BFGS)

#include "ap.h"

class OptHOM
{
public:
  Mesh mesh;
  OptHOM(const std::map<MElement*,GEntity*> &element2entity,
         const std::set<MElement*, Less_ElementPtr> &els, std::set<MVertex*> & toFix,
         bool fixBndNodes, bool fastJacEval = false);
  // returns 1 if the mesh has been optimized with success i.e. all jacobians
  // are in the range; returns 0 if the mesh is valid (all jacobians positive,
  // JMIN > 0) but JMIN < barrier_min || JMAX > barrier_max; returns -1 if the
  // mesh is invalid : some jacobians cannot be made positive
  int optimize(double lambda, double lambda3, double barrier_min, double barrier_max,
               bool optimizeMetricMin, int pInt, int itMax, int optPassMax,
               int optimizeCAD, double optCADDistMax, double tolerance);
  void recalcJacDist();
  inline void getJacDist(double &minJ, double &maxJ, double &maxD, double &avgD);
  void updateMesh(const alglib::real_1d_array &x);
  void evalObjGrad(const alglib::real_1d_array &x, double &Obj,
                   alglib::real_1d_array &gradObj);
  void printProgress(const alglib::real_1d_array &x, double Obj);

  double barrier_min, barrier_max, distance_max, geomTol;
 private:
  double lambda, lambda3, jacBar, invLengthScaleSq;
  int iter, progressInterv; // Current iteration, interval of iterations for reporting
  bool _optimizeMetricMin;
  double initObj, initMaxDist, initAvgDist; // Values for reporting
  double minJac, maxJac, maxDist, maxDistCAD, avgDist; // Values for reporting
  bool _optimizeBarrierMax; // false : only moving barrier min;
                            // true : fixed barrier min + moving barrier max
  bool _optimizeCAD; // false : do not minimize the distance between mesh and CAD
                     // true : minimize the distance between mesh and CAD
  bool addApproximationErrorObjGrad(double Fact, double &Obj, alglib::real_1d_array &gradObj, simpleFunction<double>& fct);
  bool addJacObjGrad(double &Obj, alglib::real_1d_array &gradObj);
  bool addBndObjGrad (double Fact, double &Obj, alglib::real_1d_array &gradObj);
  bool addMetricMinObjGrad(double &Obj, alglib::real_1d_array &gradObj);
  bool addDistObjGrad(double Fact, double &Obj, alglib::real_1d_array &gradObj);
  void calcScale(alglib::real_1d_array &scale);
  void OptimPass(alglib::real_1d_array &x, int itMax);
};

void OptHOM::getJacDist(double &minJ, double &maxJ, double &maxD, double &avgD)
{
  minJ = minJac; maxJ = maxJac; maxD = maxDist; avgD = avgDist;
}

double distanceToGeometry(GModel *gm);
void distanceFromElementsToGeometry(GModel *gm, int dim, std::map<MElement*,double> &distances);


#endif

#endif
