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

#include <iostream>
#include <algorithm>
#include "GmshMessage.h"
#include "GmshConfig.h"
#include "MeshOptObjContrib.h"
#include "MeshOptObjectiveFunction.h"
#include "MeshOptCommon.h"
#include "MeshOpt.h"

#if defined(HAVE_BFGS)

#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"
#include "linalg.h"
#include "optimization.h"


namespace {



void evalObjGradFunc(const alglib::real_1d_array &x, double &Obj,
                     alglib::real_1d_array &gradObj, void *MOInst)
{
  (static_cast<MeshOpt*>(MOInst))->evalObjGrad(x, Obj, gradObj);
}


void printProgressFunc(const alglib::real_1d_array &x, double Obj, void *MOInst)
{
  (static_cast<MeshOpt*>(MOInst))->printProgress(x,Obj);
}


}

MeshOpt::MeshOpt(const std::map<MElement*,GEntity*> &element2entity,
                 const std::map<MElement*, GEntity*> &bndEl2Ent,
                 const std::set<MElement*> &els, std::set<MVertex*> &toFix,
                 const std::set<MElement*> &bndEls, const MeshOptParameters &par) :
  patch(element2entity, bndEl2Ent, els, toFix, bndEls, par.fixBndNodes), _verbose(0), _nCurses(1),
  _iPass(0), _iter(0), _intervDisplay(0), _initObj(0)
{
  _allObjFunc.resize(par.pass.size());
  for (int iPass=0; iPass<par.pass.size(); iPass++) {
    _allObjFunc[iPass].resize(par.pass[iPass].contrib.size());
    for (int iC=0; iC<par.pass[iPass].contrib.size(); iC++)
      _allObjFunc[iPass][iC] = par.pass[iPass].contrib[iC]->copy();
  }
  _objFunc = &_allObjFunc[0];
  if (par.nCurses){
    int minCol = 0;
    for (int i=0; i < _objFunc->names().size(); i++){
      if (i > 0)
        minCol += 5;
      minCol += 34;
      minCol += _objFunc->names()[i].size();
    }
    minCol = std::max(minCol, 96);
    int minRow = std::max(34, 34+(int)_objFunc->names().size()-5);
    int nbRow, nbCol;
    mvgetScreenSize(nbRow, nbCol);
    while (nbRow < minRow || nbCol < minCol){
      for (int i=0; i<nbRow; i++){
        mvfillRow(i,' ');
      }
      int firstRow = (nbRow-5)/2;
      mvprintCenter(firstRow,"Given the number of contributions to the objective function, ncurses");
      mvprintCenter(firstRow+1,"enhanced interface requires a terminal window of minimal size");
      mvprintCenter(firstRow+2,"%4ix%4i characters. Yours is %4ix%4i, try resizing the window", minRow, minCol, nbRow, nbCol);
      mvprintCenter(firstRow+3,"then press SPACE.");
      mvpause();
      for (int i=0; i<nbRow; i++){
        mvfillRow(i,' ');
      }
      mvbold(true);
      mvprintCenter(0, "OPTIMIZING MESH");
      mvfillRow(1,'-');
      mvfillRow(10,'-');
      mvfillRow(20,'-');
      mvfillRow(27,'-');
      mvbold(false);
      mvgetScreenSize(nbRow, nbCol);
    }
  }
}


MeshOpt::~MeshOpt()
{
  for (int iPass=0; iPass<_allObjFunc.size(); iPass++)
    for (int iC=0; iC<_allObjFunc[iPass].size(); iC++) delete _allObjFunc[iPass][iC];
  while (_optHistory.size() > 0){
    delete[] _optHistory.back();
    _optHistory.pop_back();
  }
  while (_iterHistory.size() > 0){
    delete[] _iterHistory.back();
    _iterHistory.pop_back();
  }
}


void MeshOpt::evalObjGrad(const alglib::real_1d_array &x, double &obj,
                                         alglib::real_1d_array &gradObj)
{
  patch.updateMesh(x.getcontent());
  _objFunc->compute(obj, gradObj);
  if (_objFunc->targetReached()) {
    if (_verbose > 2) Msg::Info("Reached target values, setting null gradient");
    obj = 0.;
    for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;
  }
}


ObjectiveFunction *MeshOpt::objFunction()
{
  return  _objFunc;
}

void MeshOpt::printProgress(const alglib::real_1d_array &x, double Obj)
{
  _iter++;

  if (_nCurses){
    mvprintCenter(21, "Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E)", _iter, Obj, Obj/_initObj);
    if (_iterHistory.size() < 5){
      _iterHistory.push_back(new char[1000]);
    } else {
      _iterHistory.push_back(_iterHistory.front());
      _iterHistory.pop_front();
    }
    sprintf(_iterHistory.back(), _objFunc->minMaxStr().c_str());
    mvprintList(22, 5, _iterHistory, 1);
  }
  if ((_verbose > 2) && (_iter % _intervDisplay == 0 || _nCurses))
    Msg::Info(("--> Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E)" +
              _objFunc->minMaxStr()).c_str(), _iter, Obj, Obj/_initObj);
}


void MeshOpt::calcScale(alglib::real_1d_array &scale)
{
  scale.setlength(patch.nPC());

  // Calculate scale
  for (int iFV = 0; iFV < patch.nFV(); iFV++) {
    std::vector<double> scaleFV(patch.nPCFV(iFV),1.);
    patch.pcScale(iFV,scaleFV);
    for (int iPC = 0; iPC < patch.nPCFV(iFV); iPC++)
      scale[patch.indPCFV(iFV,iPC)] = scaleFV[iPC];
  }
}


void MeshOpt::updateResults()
{
  _objFunc->updateResults();
}


void MeshOpt::runOptim(alglib::real_1d_array &x,
                       const alglib::real_1d_array &initGradObj, int itMax, int iBar)
{
  static const double EPSG = 0.;
  static const double EPSF = 0.;
  static const double EPSX = 0.;

  _iter = 0;

  alglib::real_1d_array scale;
  calcScale(scale);

  int iterationscount = 0, nfev = 0, terminationtype = -1;
  alglib::mincgstate state;
  alglib::mincgreport rep;
  try {
    mincgcreate(x, state);
    mincgsetscale(state,scale);
    mincgsetprecscale(state);
    mincgsetcond(state, EPSG, EPSF, EPSX, itMax);
    mincgsetxrep(state, true);
    alglib::mincgoptimize(state, evalObjGradFunc, printProgressFunc, this);
    mincgresults(state, x, rep);
  }
  catch(alglib::ap_error &e) {
    Msg::Error("%s", e.msg.c_str());
  }
  iterationscount = rep.iterationscount;
  nfev = rep.nfev;
  terminationtype = rep.terminationtype;
  if (_nCurses){
    if (_optHistory.size() < 8){
      _optHistory.push_front(new char[1000]);
    } else {
      _optHistory.push_front(_optHistory.back());
      _optHistory.pop_back();
    }
    switch(int(terminationtype)) {
    case 1:  sprintf(_optHistory.front(),"Optimization run %3d (%3d iterations, %3d function evaluations): rel function improvement <= EpsF", iBar, iterationscount, nfev); break;
    case 2:  sprintf(_optHistory.front(),"Optimization run %3d (%3d iterations, %3d function evaluations): rel step <= EpsX                ", iBar, iterationscount, nfev); break;
    case 4:  sprintf(_optHistory.front(),"Optimization run %3d (%3d iterations, %3d function evaluations): gradient norm <= EpsG           ", iBar, iterationscount, nfev); break;
    case 5:  sprintf(_optHistory.front(),"Optimization run %3d (%3d iterations, %3d function evaluations): max number of steps taken       ", iBar, iterationscount, nfev); break;
    default: sprintf(_optHistory.front(),"Optimization run %3d (%3d iterations, %3d function evaluations): code %d                                              ", iBar, iterationscount, nfev, int(terminationtype)); break;
    }
    if (_optHistory.size() < 8){
      _optHistory.push_front(new char[1000]);
    } else {
      _optHistory.push_front(_optHistory.back());
      _optHistory.pop_back();
    }
    sprintf(_optHistory.front(), _iterHistory.back());
    mvprintList(19, -8, _optHistory, 2);
    while (_iterHistory.size() > 0){
      delete[] _iterHistory.back();
      _iterHistory.pop_back();
    }
    mvprintList(22, 5, _iterHistory, 1);
  }
  if (_verbose > 2) {
    Msg::Info("Optimization finalized after %d iterations (%d function evaluations),",
              iterationscount, nfev);
    switch(int(terminationtype)) {
    case 1: Msg::Info("because relative function improvement is no more than EpsF"); break;
    case 2: Msg::Info("because relative step is no more than EpsX"); break;
    case 4: Msg::Info("because gradient norm is no more than EpsG"); break;
    case 5: Msg::Info("because the maximum number of steps was taken"); break;
    default: Msg::Info("with code %d", int(terminationtype)); break;
    }
  }
}


int MeshOpt::optimize(const MeshOptParameters &par)
{
  _intervDisplay = par.displayInterv;
  _verbose = par.verbose;
  _nCurses = par.nCurses;
  // Set initial guess & result
  int result = 1;
  alglib::real_1d_array x;
  x.setlength(patch.nPC());
  patch.getUvw(x.getcontent());
  if (_nCurses){
    mvprintCenter(11, "%7i elements, %7i vertices, %7i free vertices, %7i variables",
                patch.nEl(), patch.nVert(), patch.nFV(), patch.nPC());
  }
  if (_verbose > 2)
      Msg::Info("Patch composed of %i elements, %i vertices, %i free vertices, %i variables",
                patch.nEl(), patch.nVert(), patch.nFV(), patch.nPC());

  // Loop on passes
  for (_iPass=0; _iPass<par.pass.size(); _iPass++) {

    // Set objective function Output if required
    _objFunc = &_allObjFunc[_iPass];
    if (_verbose > 2) {
      std::string msgStr = "* Pass %d with contributions: " + _objFunc->contribNames();
      Msg::Info(msgStr.c_str(), _iPass);
    }

    // Initialize contributions
    _objFunc->initialize(&patch);
    _objFunc->updateParameters();

    // Calculate initial objective function value and gradient
   _initObj = 0.;
    alglib::real_1d_array gradObj;
    gradObj.setlength(patch.nPC());
    for (int i = 0; i < patch.nPC(); i++) gradObj[i] = 0.;
    evalObjGrad(x, _initObj, gradObj);

    // Loop for update of objective function parameters (barrier movement)
    bool targetReached = _objFunc->targetReached();
    for (int iBar=0; (iBar<par.pass[_iPass].maxParamUpdates) && (!targetReached); iBar++) {
      if (_nCurses){
        mvbold(true);
        mvprintCenter(20, " OPTIMIZATION RUN %3d ", iBar);
        mvbold(false);
        if (iBar == 0){
          while (_optHistory.size() > 0){
            delete[] _optHistory.back();
            _optHistory.pop_back();
          }
        }
        mvprintList(19, -8, _optHistory, 2);
      }
      if (_verbose > 2){
        Msg::Info("--- Optimization run %d", iBar);
        Msg::Info("%s", _objFunc->minMaxStr().c_str());
      }
      _objFunc->updateParameters();
      runOptim(x, gradObj, par.pass[_iPass].maxOptIter, iBar);
      _objFunc->updateMinMax();
      targetReached = _objFunc->targetReached();
      if (_objFunc->stagnated()) {
        if (_verbose > 2) Msg::Info("Stagnation detected, stopping optimization");
        break;
      }
    }

    // Check results of pass and output if required
    if (!targetReached) result = 0;
    std::string failMeasures = _objFunc->failMeasures();
    if (!failMeasures.empty()) {
      result = -1;
      if (_verbose > 2)
        Msg::Error("Failed to reach critical value in pass %d "
                    "for measure(s): %s", _iPass, failMeasures.c_str());
    }
    if (_verbose > 2) {
      if (targetReached)
        Msg::Info("Target reached for pass %d", _iPass);
      else {
        std::string failedTargets = _objFunc->targetsNotReached();
        Msg::Warning("Failed to reach target in pass %d for "
                      "contributions %s", _iPass, failedTargets.c_str());
      }
    }
    if (result == -1) break;
  }                                                                       // Pass loop

  return result;
}


#endif
