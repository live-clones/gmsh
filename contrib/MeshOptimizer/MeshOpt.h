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

#ifndef _MESHOPT_H_
#define _MESHOPT_H_

#include <string>
#include <math.h>
#include "MeshOptObjectiveFunction.h"
#include "MeshOptPatch.h"

#if defined(HAVE_BFGS)

#include "ap.h"


class MeshOptParameters;


class MeshOpt
{
public:
  Patch patch;
  MeshOpt(const std::map<MElement*,GEntity*> &element2entity,
          const std::set<MElement*> &els, std::set<MVertex*> &toFix,
          bool fixBndNodes, const std::vector<ObjContrib*> &allContrib);
  ~MeshOpt();
  int optimize(MeshOptParameters &par);
  void updateMesh(const alglib::real_1d_array &x);
  void updateResults(MeshOptResults &res);
  void evalObjGrad(const alglib::real_1d_array &x,
                    double &Obj, alglib::real_1d_array &gradObj);
  void printProgress(const alglib::real_1d_array &x, double Obj);

 private:
  int _verbose;
  int _iPass;
  std::vector<ObjContrib*> _allContrib;                                             // All contributions to objective function for all passes
  ObjectiveFunction _objFunc;                                                       // Contributions to objective function for current pass
  int _iter, _intervDisplay;                                                        // Current iteration, interval of iterations for reporting
  double _initObj;                                                                  // Values for reporting
  void calcScale(alglib::real_1d_array &scale);
  void runOptim(alglib::real_1d_array &x,
                const alglib::real_1d_array &initGradObj, int itMax);
};


#endif

#endif
