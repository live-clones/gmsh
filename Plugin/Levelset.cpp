// $Id: Levelset.cpp,v 1.5 2003-11-22 18:45:40 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Levelset.h"
#include "DecomposeInSimplex.h"
#include "List.h"
#include "Views.h"
#include "Iso.h"
#include "Numeric.h"
#include "Context.h"
#include "Malloc.h"

extern Context_T CTX;

GMSH_LevelsetPlugin::GMSH_LevelsetPlugin()
{
  _invert = 0.;
  _ref[0] = _ref[1] = _ref[2] = 0.;
  _valueIndependent = 0; // "moving" levelset
  _valueView = -1; // use same view for levelset and field data
  _valueTimeStep = -1; // use same time step in levelset and field data views
  _orientation = GMSH_LevelsetPlugin::NONE;
}

static void affect(double *xpi, double *ypi, double *zpi, double valpi[12][9], int i,
		   double *xp, double *yp, double *zp, double valp[12][9], int j,
		   int nb)
{
  xpi[i] = xp[j];
  ypi[i] = yp[j];
  zpi[i] = zp[j];
  for(int k = 0; k < nb; k++)
    valpi[i][k] = valp[j][k];
}

int GMSH_LevelsetPlugin::zeroLevelset(int timeStep, 
				      int nbVert, int nbEdg, int exn[12][2],
				      double *x, double *y, double *z, 
				      double *iVal, int iNbComp,
				      double *dVal, int dNbComp,
				      vector<Post_View *> out)
{
  double levels[8], scalarVal[8];

  // compute the value of the levelset function at each node
  if(_valueIndependent) {
    for(int k = 0; k < nbVert; k++)
      levels[k] = levelset(x[k], y[k], z[k], 0.0);
  }
  else{
    for(int k = 0; k < nbVert; k++) {
      double *vals = &iVal[iNbComp * k];
      switch(iNbComp) {
      case 1: // scalar
	scalarVal[k] = vals[0];
	break;
      case 3 : // vector
	scalarVal[k] = sqrt(DSQR(vals[0]) + DSQR(vals[1]) + DSQR(vals[2]));
	break;
      case 9 : // tensor
	scalarVal[k] = ComputeVonMises(vals);
	break;
      }
      levels[k] = levelset(x[k], y[k], z[k], scalarVal[k]);
    }
  }
  
  // interpolate the zero levelset and the field to plot on it
  double xp[12], yp[12], zp[12], valp[12][9];
  int np = 0;
  for(int k = 0; k < nbEdg; k++) {
    if(levels[exn[k][0]] * levels[exn[k][1]] <= 0.0) {
      if(iVal && dVal) {
	double coef = InterpolateIso(x, y, z, levels, 0.0, exn[k][0], exn[k][1],
				     &xp[np], &yp[np], &zp[np]);
	double *val1 = &dVal[dNbComp * exn[k][0]];
	double *val2 = &dVal[dNbComp * exn[k][1]];
	for(int l = 0; l < dNbComp; l++)
	  valp[np][l] = coef * (val2[l] - val1[l]) + val1[l];
      }
      np++;
    }
  }

  if(!iVal || !dVal)
    return np;

  double xpi[12], ypi[12], zpi[12], valpi[12][9];

  // Remove identical nodes (this can happen if an edge actually
  // belongs to the zero levelset, i.e., if levels[] * levels[] ==
  // 0). We should be doing this even for np < 4, but it would slow us
  // down even more... (And we don't really care if some nodes in a
  // postprocessing element are identical.)
  if(np > 4){
    int npi;
    affect(xpi, ypi, zpi, valpi, 0, xp, yp, zp, valp, 0, dNbComp);
    npi = 1;
    for(int j = 1; j < np; j++){
      for(int i = 0; i < npi; i++){
	if(fabs(xp[j] - xpi[i]) < 1.e-12 &&
	   fabs(yp[j] - ypi[i]) < 1.e-12 &&
	   fabs(zp[j] - zpi[i]) < 1.e-12){
	  break;
	}
	if(i == npi-1){
	  affect(xpi, ypi, zpi, valpi, i+1, xp, yp, zp, valp, j, dNbComp);
	  npi++;
	}
      }
    }
    for(int i = 0; i < npi; i++)
      affect(xp, yp, zp, valp, i, xpi, ypi, zpi, valpi, i, dNbComp);
    np = npi;
  }

  // can't deal with this--just return...
  if(np < 1 || np > 4)
    return 0;

  // avoid ``butterflies''
  if(np == 4) {
    affect(xpi, ypi, zpi, valpi, 0, xp, yp, zp, valp, 3, dNbComp);
    affect(xp, yp, zp, valp, 3, xp, yp, zp, valp, 2, dNbComp);
    affect(xp, yp, zp, valp, 2, xpi, ypi, zpi, valpi, 0, dNbComp);
  }
      
  // orient the triangles and the quads to get the normals right
  if(np == 3 || np == 4) {
    if(!timeStep || !_valueIndependent) {
      // test this only once for spatially-fixed views
      double v1[3] = { xp[2] - xp[0], yp[2] - yp[0], zp[2] - zp[0] };
      double v2[3] = { xp[1] - xp[0], yp[1] - yp[0], zp[1] - zp[0] };
      double gr[3], n[3];
      prodve(v1, v2, n);
      switch (_orientation) {
      case MAP:
	gradSimplex(x, y, z, scalarVal, gr);
	prosca(gr, n, &_invert);
	break;
      case PLANE:
	prosca(n, _ref, &_invert);
	break;
      case SPHERE:
	gr[0] = xp[0] - _ref[0];
	gr[1] = yp[0] - _ref[1];
	gr[2] = zp[0] - _ref[2];
	prosca(gr, n, &_invert);
      case NONE:
      default:
	break;
      }
    }
    if(_invert > 0.) {
      double xpi[12], ypi[12], zpi[12], valpi[12][9];
      for(int k = 0; k < np; k++)
	affect(xpi, ypi, zpi, valpi, k, xp, yp, zp, valp, k, dNbComp);
      for(int k = 0; k < np; k++)
	affect(xp, yp, zp, valp, k, xpi, ypi, zpi, valpi, np-k-1, dNbComp);
    }
  }

  // select the output view
  Post_View *view = _valueIndependent ? out[0] : out[timeStep];
  List_T *list;
  int *nbPtr;
  if(np == 1) {
    if(dNbComp == 1)      { list = view->SP; nbPtr = &view->NbSP; }
    else if(dNbComp == 3) { list = view->VP; nbPtr = &view->NbVP; }
    else                  { list = view->TP; nbPtr = &view->NbTP; }
  }
  else if(np == 2) {
    if(dNbComp == 1)      { list = view->SL; nbPtr = &view->NbSL; }
    else if(dNbComp == 3) { list = view->VL; nbPtr = &view->NbVL; }
    else                  { list = view->TL; nbPtr = &view->NbTL; }
  }
  else if(np == 3) {
    if(dNbComp == 1)      { list = view->ST; nbPtr = &view->NbST; }
    else if(dNbComp == 3) { list = view->VT; nbPtr = &view->NbVT; }
    else                  { list = view->TT; nbPtr = &view->NbTT; }
  }
  else{
    if(dNbComp == 1)      { list = view->SQ; nbPtr = &view->NbSQ; }
    else if(dNbComp == 3) { list = view->VQ; nbPtr = &view->NbVQ; }
    else                  { list = view->TQ; nbPtr = &view->NbTQ; }
  }
  
  // copy the elements in the output view
  if(!timeStep || !_valueIndependent) {
    for(int k = 0; k < np; k++) 
      List_Add(list, &xp[k]);
    for(int k = 0; k < np; k++)
      List_Add(list, &yp[k]);
    for(int k = 0; k < np; k++)
      List_Add(list, &zp[k]);
    (*nbPtr)++;
  }
  for(int k = 0; k < np; k++)
    for(int l = 0; l < dNbComp; l++)
      List_Add(list, &valp[k][l]);
  
  return 0;
}

static int getTimeStep(int timeStep, int ts, Post_View *dView)
{
  if(timeStep < 0) {
    return ts;
  }
  if(timeStep >= dView->NbTimeStep) {
    Msg(WARNING, "Wrong TimeStep %d in View[%d]: reverting to TimeStep 0",
	timeStep, dView->Index);
    return 0;
  }
  return timeStep;
}

void GMSH_LevelsetPlugin::executeList(Post_View * iView, List_T * iList, 
				      int iNbElm, int iNbComp,
				      Post_View * dView, List_T * dList, 
				      int dNbElm, int dNbComp,
				      int nbVert, int nbEdg, int exn[12][2], 
				      vector<Post_View *> out)
{
  if(!iNbElm || !dNbElm) 
    return;
  
  if(iNbElm != dNbElm) {
    Msg(WARNING, "View[%d] and View[%d] have a different number of elements (%d != %d)",
	iView->Index, dView->Index, iNbElm, dNbElm);
    return;
  }

  int iNb = List_Nbr(iList) / iNbElm;
  int dNb = List_Nbr(dList) / dNbElm;
  for(int i = 0, j = 0; i < List_Nbr(iList); i += iNb, j += dNb) {
    double *x = (double *)List_Pointer_Fast(iList, i);
    double *y = (double *)List_Pointer_Fast(iList, i + nbVert);
    double *z = (double *)List_Pointer_Fast(iList, i + 2 * nbVert);

    if(nbVert == 2 || nbVert == 3 || (nbVert == 4 && nbEdg == 6)) {
      // easy for simplices: at most one element is created per time step 
      for(int iTS = 0; iTS < iView->NbTimeStep; iTS++) {
	int dTS = getTimeStep(_valueTimeStep, iTS, dView);
	// don't compute the zero levelset of the value view
	if(_valueTimeStep < 0 || iView != dView || dTS != iTS){
	  double *iVal = (double *)List_Pointer_Fast(iList, i + 3 * nbVert + 
						     iNbComp * nbVert * iTS); 
	  double *dVal = (double *)List_Pointer_Fast(dList, j + 3 * nbVert + 
						     dNbComp * nbVert * dTS);
	  zeroLevelset(iTS, nbVert, nbEdg, exn, x, y, z, 
		       iVal, iNbComp, dVal, dNbComp, out);
	}
      }
    }
    else{
      // we decompose the element into simplices
      DecomposeInSimplex iDec(nbVert, iNbComp);
      DecomposeInSimplex dDec(nbVert, dNbComp);
      
      int nbVertNew = iDec.numSimplexNodes();
      int nbEdgNew = (nbVertNew == 4) ? 6 : 3;
      int exnTri[12][2] = {{0,1},{0,2},{1,2}};
      int exnTet[12][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
      double xNew[4], yNew[4], zNew[4];
      double *iValNew = new double[4 * iNbComp];
      double *dValNew = new double[4 * dNbComp];

      if(_valueIndependent) {
	// since the intersection is value-independent, we can loop on
	// the time steps so that only one element gets created per
	// time step. This allows us to still easily generate a
	// *single* multi-timestep view.
	if(zeroLevelset(0, nbVert, nbEdg, exn, x, y, z, NULL, 0, 
			NULL, 0, out)) {
	  for(int k = 0; k < iDec.numSimplices(); k++) {
	    for(int iTS = 0; iTS < iView->NbTimeStep; iTS++) {
	      int dTS = getTimeStep(_valueTimeStep, iTS, dView);
	      // don't compute the zero levelset of the value view
	      if(_valueTimeStep < 0 || iView != dView || dTS != iTS){
		double *iVal = (double *)List_Pointer_Fast(iList, i + 3 * nbVert + 
							   iNbComp * nbVert * iTS); 
		double *dVal = (double *)List_Pointer_Fast(dList, j + 3 * nbVert + 
							   dNbComp * nbVert * dTS);
		iDec.decompose(k, x, y, z, iVal, xNew, yNew, zNew, iValNew);
		dDec.decompose(k, x, y, z, dVal, xNew, yNew, zNew, dValNew);
		zeroLevelset(iTS, nbVertNew, nbEdgNew, (nbVertNew == 4) ? exnTet : exnTri, 
			     xNew, yNew, zNew, iValNew, iNbComp, dValNew, dNbComp, out);
	      }
	    }
	  }
	}
      }
      else{
	// since we generate one view for each time step, we can
	// generate multiple elements per time step without problem.
	for(int iTS = 0; iTS < iView->NbTimeStep; iTS++) {
	  int dTS = getTimeStep(_valueTimeStep, iTS, dView);
	  // don't compute the zero levelset of the value view
	  if(_valueTimeStep < 0 || iView != dView || dTS != iTS){
	    double *iVal = (double *)List_Pointer_Fast(iList, i + 3 * nbVert +
						       iNbComp * nbVert * iTS); 
	    if(zeroLevelset(iTS, nbVert, nbEdg, exn, x, y, z, iVal, iNbComp, 
			    NULL, 0, out)) {
	      double *dVal = (double *)List_Pointer_Fast(dList, j + 3 * nbVert +
							 dNbComp * nbVert * dTS);
	      for(int k = 0; k < iDec.numSimplices(); k++) {
		iDec.decompose(k, x, y, z, iVal, xNew, yNew, zNew, iValNew);
		dDec.decompose(k, x, y, z, dVal, xNew, yNew, zNew, dValNew);
		zeroLevelset(iTS, nbVertNew, nbEdgNew, (nbVertNew == 4) ? exnTet : exnTri, 
			     xNew, yNew, zNew, iValNew, iNbComp, dValNew, dNbComp, out);
	      }
	    }
	  }
	}
      }

      delete [] iValNew;
      delete [] dValNew;
    }

  }
}
  
Post_View *GMSH_LevelsetPlugin::execute(Post_View * v)
{
  Post_View *w;
  vector<Post_View *> out;

  if(_valueView < 0) {
    w = v;
  }
  else if(!(w = (Post_View *)List_Pointer_Test(CTX.post.list, _valueView))) {
    Msg(GERROR, "View[%d] does not exist: reverting to View[%d]", _valueView, 
	v->Index);
    w = v;
  }

  if(_valueIndependent) {
    out.push_back(BeginView(1));
  }
  else{
    for(int ts = 0; ts < v->NbTimeStep; ts++)
      out.push_back(BeginView(1));
  }

  // We should definitely recode the View interface in C++ (and define
  // iterators on the different kinds of elements...)

  // To avoid surprising results, we don't try to plot values of
  // different types on the levelset if the value view (w) is the same
  // as the levelset view (v).

  // lines
  int exnLin[12][2] = {{0,1}};
  executeList(v, v->SL, v->NbSL, 1, w, w->SL, w->NbSL, 1, 2, 1, exnLin, out);
  if(v != w){
    executeList(v, v->SL, v->NbSL, 1, w, w->VL, w->NbVL, 3, 2, 1, exnLin, out);
    executeList(v, v->SL, v->NbSL, 1, w, w->TL, w->NbTL, 9, 2, 1, exnLin, out);
  }

  if(v != w){
    executeList(v, v->VL, v->NbVL, 3, w, w->SL, w->NbSL, 1, 2, 1, exnLin, out);
  }
  executeList(v, v->VL, v->NbVL, 3, w, w->VL, w->NbVL, 3, 2, 1, exnLin, out);
  if(v != w){
    executeList(v, v->VL, v->NbVL, 3, w, w->TL, w->NbTL, 9, 2, 1, exnLin, out);
  }

  if(v != w){
    executeList(v, v->TL, v->NbTL, 9, w, w->SL, w->NbSL, 1, 2, 1, exnLin, out);
    executeList(v, v->TL, v->NbTL, 9, w, w->VL, w->NbVL, 3, 2, 1, exnLin, out);
  }
  executeList(v, v->TL, v->NbTL, 9, w, w->TL, w->NbTL, 9, 2, 1, exnLin, out);

  // triangles
  int exnTri[12][2] = {{0,1}, {0,2}, {1,2}};
  executeList(v, v->ST, v->NbST, 1, w, w->ST, w->NbST, 1, 3, 3, exnTri, out);
  if(v != w){
    executeList(v, v->ST, v->NbST, 1, w, w->VT, w->NbVT, 3, 3, 3, exnTri, out);
    executeList(v, v->ST, v->NbST, 1, w, w->TT, w->NbTT, 9, 3, 3, exnTri, out);
  }

  if(v != w){
    executeList(v, v->VT, v->NbVT, 3, w, w->ST, w->NbST, 1, 3, 3, exnTri, out);
  }
  executeList(v, v->VT, v->NbVT, 3, w, w->VT, w->NbVT, 3, 3, 3, exnTri, out);
  if(v != w){
    executeList(v, v->VT, v->NbVT, 3, w, w->TT, w->NbTT, 9, 3, 3, exnTri, out);
  }

  if(v != w){
    executeList(v, v->TT, v->NbTT, 9, w, w->ST, w->NbST, 1, 3, 3, exnTri, out);
    executeList(v, v->TT, v->NbTT, 9, w, w->VT, w->NbVT, 3, 3, 3, exnTri, out);
  }
  executeList(v, v->TT, v->NbTT, 9, w, w->TT, w->NbTT, 9, 3, 3, exnTri, out);

  // tets
  int exnTet[12][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  executeList(v, v->SS, v->NbSS, 1, w, w->SS, w->NbSS, 1, 4, 6, exnTet, out);
  if(v != w){
    executeList(v, v->SS, v->NbSS, 1, w, w->VS, w->NbVS, 3, 4, 6, exnTet, out);
    executeList(v, v->SS, v->NbSS, 1, w, w->TS, w->NbTS, 9, 4, 6, exnTet, out);
  }

  if(v != w){
    executeList(v, v->VS, v->NbVS, 3, w, w->SS, w->NbSS, 1, 4, 6, exnTet, out);
  }
  executeList(v, v->VS, v->NbVS, 3, w, w->VS, w->NbVS, 3, 4, 6, exnTet, out);
  if(v != w){
    executeList(v, v->VS, v->NbVS, 3, w, w->TS, w->NbTS, 9, 4, 6, exnTet, out);
  }

  if(v != w){
    executeList(v, v->TS, v->NbTS, 9, w, w->SS, w->NbSS, 1, 4, 6, exnTet, out);
    executeList(v, v->TS, v->NbTS, 9, w, w->VS, w->NbVS, 3, 4, 6, exnTet, out);
  }
  executeList(v, v->TS, v->NbTS, 9, w, w->TS, w->NbTS, 9, 4, 6, exnTet, out);

  // quads
  int exnQua[12][2] = {{0,1}, {0,3}, {1,2}, {2,3}};
  executeList(v, v->SQ, v->NbSQ, 1, w, w->SQ, w->NbSQ, 1, 4, 4, exnQua, out);
  if(v != w){
    executeList(v, v->SQ, v->NbSQ, 1, w, w->VQ, w->NbVQ, 3, 4, 4, exnQua, out);
    executeList(v, v->SQ, v->NbSQ, 1, w, w->TQ, w->NbTQ, 9, 4, 4, exnQua, out);
  }

  if(v != w){
    executeList(v, v->VQ, v->NbVQ, 3, w, w->SQ, w->NbSQ, 1, 4, 4, exnQua, out);
  }
  executeList(v, v->VQ, v->NbVQ, 3, w, w->VQ, w->NbVQ, 3, 4, 4, exnQua, out);
  if(v != w){
    executeList(v, v->VQ, v->NbVQ, 3, w, w->TQ, w->NbTQ, 9, 4, 4, exnQua, out);
  }

  if(v != w){
    executeList(v, v->TQ, v->NbTQ, 9, w, w->SQ, w->NbSQ, 1, 4, 4, exnQua, out);
    executeList(v, v->TQ, v->NbTQ, 9, w, w->VQ, w->NbVQ, 3, 4, 4, exnQua, out);
  }
  executeList(v, v->TQ, v->NbTQ, 9, w, w->TQ, w->NbTQ, 9, 4, 4, exnQua, out);

  // hexes
  int exnHex[12][2] = {{0,1}, {0,3}, {0,4}, {1,2}, {1,5}, {2,3},
		       {2,6}, {3,7}, {4,5}, {4,7}, {5,6}, {6,7}};
  executeList(v, v->SH, v->NbSH, 1, w, w->SH, w->NbSH, 1, 8, 12, exnHex, out);
  if(v != w){
    executeList(v, v->SH, v->NbSH, 1, w, w->VH, w->NbVH, 3, 8, 12, exnHex, out);
    executeList(v, v->SH, v->NbSH, 1, w, w->TH, w->NbTH, 9, 8, 12, exnHex, out);
  }

  if(v != w){
    executeList(v, v->VH, v->NbVH, 3, w, w->SH, w->NbSH, 1, 8, 12, exnHex, out);
  }
  executeList(v, v->VH, v->NbVH, 3, w, w->VH, w->NbVH, 3, 8, 12, exnHex, out);
  if(v != w){
    executeList(v, v->VH, v->NbVH, 3, w, w->TH, w->NbTH, 9, 8, 12, exnHex, out);
  }

  if(v != w){
    executeList(v, v->TH, v->NbTH, 9, w, w->SH, w->NbSH, 1, 8, 12, exnHex, out);
    executeList(v, v->TH, v->NbTH, 9, w, w->VH, w->NbVH, 3, 8, 12, exnHex, out);
  }
  executeList(v, v->TH, v->NbTH, 9, w, w->TH, w->NbTH, 9, 8, 12, exnHex, out);

  // prisms
  int exnPri[12][2] = {{0,1}, {0,2}, {0,3}, {1,2}, {1,4}, {2,5},
		       {3,4}, {3,5}, {4,5}};
  executeList(v, v->SI, v->NbSI, 1, w, w->SI, w->NbSI, 1, 6, 9, exnPri, out);
  if(v != w){
    executeList(v, v->SI, v->NbSI, 1, w, w->VI, w->NbVI, 3, 6, 9, exnPri, out);
    executeList(v, v->SI, v->NbSI, 1, w, w->TI, w->NbTI, 9, 6, 9, exnPri, out);
  }

  if(v != w){
    executeList(v, v->VI, v->NbVI, 3, w, w->SI, w->NbSI, 1, 6, 9, exnPri, out);
  }
  executeList(v, v->VI, v->NbVI, 3, w, w->VI, w->NbVI, 3, 6, 9, exnPri, out);
  if(v != w){
    executeList(v, v->VI, v->NbVI, 3, w, w->TI, w->NbTI, 9, 6, 9, exnPri, out);
  }
 
  if(v != w){
    executeList(v, v->TI, v->NbTI, 9, w, w->SI, w->NbSI, 1, 6, 9, exnPri, out);
    executeList(v, v->TI, v->NbTI, 9, w, w->VI, w->NbVI, 3, 6, 9, exnPri, out);
  }
  executeList(v, v->TI, v->NbTI, 9, w, w->TI, w->NbTI, 9, 6, 9, exnPri, out);

  // pyramids
  int exnPyr[12][2] = {{0,1}, {0,3}, {0,4}, {1,2}, {1,4}, {2,3}, {2,4}, {3,4}};
  executeList(v, v->SY, v->NbSY, 1, w, w->SY, w->NbSY, 1, 5, 8, exnPyr, out);
  if(v != w){
    executeList(v, v->SY, v->NbSY, 1, w, w->VY, w->NbVY, 3, 5, 8, exnPyr, out);
    executeList(v, v->SY, v->NbSY, 1, w, w->TY, w->NbTY, 9, 5, 8, exnPyr, out);
  }

  if(v != w){
    executeList(v, v->VY, v->NbVY, 3, w, w->SY, w->NbSY, 1, 5, 8, exnPyr, out);
  }
  executeList(v, v->VY, v->NbVY, 3, w, w->VY, w->NbVY, 3, 5, 8, exnPyr, out);
  if(v != w){
    executeList(v, v->VY, v->NbVY, 3, w, w->TY, w->NbTY, 9, 5, 8, exnPyr, out);
  }

  if(v != w){
    executeList(v, v->TY, v->NbTY, 9, w, w->SY, w->NbSY, 1, 5, 8, exnPyr, out);
    executeList(v, v->TY, v->NbTY, 9, w, w->VY, w->NbVY, 3, 5, 8, exnPyr, out);
  }
  executeList(v, v->TY, v->NbTY, 9, w, w->TY, w->NbTY, 9, 5, 8, exnPyr, out);

  for(unsigned int i = 0; i < out.size(); i++) {
    char name[1024], filename[1024];
    sprintf(name, "cut-%s-%d", v->Name, i);
    sprintf(filename, "cut-%s-%d", v->FileName, i);
    EndView(out[i], 1, filename, name);
  }

  // remove empty views (this is a bit ugly because, due to the
  // dynamic GUI events, this should actually be locked...
  for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; --i) {
    w = (Post_View*) List_Pointer_Test(CTX.post.list, i);
    if(w && w->empty())
      RemoveViewByIndex(i);
  }

  return 0;
}

