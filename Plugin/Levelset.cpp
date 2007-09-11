// $Id: Levelset.cpp,v 1.34 2007-09-11 14:01:55 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Levelset.h"
#include "MakeSimplex.h"
#include "List.h"
#include "Numeric.h"

GMSH_LevelsetPlugin::GMSH_LevelsetPlugin()
{
  _invert = 0.;
  _ref[0] = _ref[1] = _ref[2] = 0.;
  _valueIndependent = 0; // "moving" levelset
  _valueView = -1; // use same view for levelset and field data
  _valueTimeStep = -1; // use same time step in levelset and field data views
  _recurLevel = 4;
  _targetError = 0.;
  _extractVolume = 0; // to create isovolumes (keep all elements < or > levelset)
  _orientation = GMSH_LevelsetPlugin::NONE;
}

static void affect(double *xpi, double *ypi, double *zpi, double valpi[12][9], int epi[12],
		   int i,
		   double *xp, double *yp, double *zp, double valp[12][9], int ep[12],
		   int j, int nb)
{
  xpi[i] = xp[j];
  ypi[i] = yp[j];
  zpi[i] = zp[j];
  for(int k = 0; k < nb; k++)
    valpi[i][k] = valp[j][k];
  epi[i] = ep[j];
}

static void removeIdenticalNodes(int *np, int nbComp, 
				 double xp[12], double yp[12], double zp[12], 
				 double valp[12][9], int ep[12])
{
  double xpi[12], ypi[12], zpi[12], valpi[12][9];
  int epi[12];

  affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 0, nbComp);
  int npi = 1;
  for(int j = 1; j < *np; j++) {
    for(int i = 0; i < npi; i++) {
      if(fabs(xp[j] - xpi[i]) < 1.e-12 &&
	 fabs(yp[j] - ypi[i]) < 1.e-12 &&
	 fabs(zp[j] - zpi[i]) < 1.e-12) {
	break;
      }
      if(i == npi-1) {
	affect(xpi, ypi, zpi, valpi, epi, npi, xp, yp, zp, valp, ep, j, nbComp);
	npi++;
	break;
      }
    }
  }
  for(int i = 0; i < npi; i++)
    affect(xp, yp, zp, valp, ep, i, xpi, ypi, zpi, valpi, epi, i, nbComp);
  *np = npi;
}

static void reorderQuad(int nbComp, 
			double xp[12], double yp[12], double zp[12], 
			double valp[12][9], int ep[12])
{
  double xpi[1], ypi[1], zpi[1], valpi[1][9];
  int epi[12];
  affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 3, nbComp);
  affect(xp, yp, zp, valp, ep, 3, xp, yp, zp, valp, ep, 2, nbComp);
  affect(xp, yp, zp, valp, ep, 2, xpi, ypi, zpi, valpi, epi, 0, nbComp);
}

static void reorderPrism(int nbComp, 
			 double xp[12], double yp[12], double zp[12], 
			 double valp[12][9], int ep[12],
			 int nbCut, int exn[12][2])
{
  double xpi[6], ypi[6], zpi[6], valpi[6][9];
  int epi[12];

  if(nbCut == 3){
    // 3 first nodes come from zero levelset intersection, next 3 are
    // endpoints of relative edges
    affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 3, nbComp);
    affect(xpi, ypi, zpi, valpi, epi, 1, xp, yp, zp, valp, ep, 4, nbComp);
    affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 5, nbComp);
    for(int i = 0; i < 3; i++){
      int edgecut = ep[i]-1;
      for(int j = 0; j < 3; j++){
	int p = -epi[j]-1;
	if(exn[edgecut][0] == p || exn[edgecut][1] == p)
	  affect(xp, yp, zp, valp, ep, 3+i, xpi, ypi, zpi, valpi, epi, j, nbComp);	  
      }
    }
  }
  else if(nbCut == 4){
    // 4 first nodes come from zero levelset intersection
    affect(xpi, ypi, zpi, valpi, epi, 0, xp, yp, zp, valp, ep, 0, nbComp);
    int edgecut = ep[0]-1;
    int p0 = -ep[4]-1;

    if(exn[edgecut][0] == p0 || exn[edgecut][1] == p0){
      affect(xpi, ypi, zpi, valpi, epi, 1, xp, yp, zp, valp, ep, 4, nbComp);
      if(exn[ep[1]-1][0] == p0 || exn[ep[1]-1][1] == p0){
	affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 1, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 3, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 5, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, nbComp);
      }
      else{
	affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 3, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 1, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 5, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, nbComp);
      }
    }
    else{
      affect(xpi, ypi, zpi, valpi, epi, 1, xp, yp, zp, valp, ep, 5, nbComp);
      if(exn[ep[1]-1][0] == p0 || exn[ep[1]-1][1] == p0){
	affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 1, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 3, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 4, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, nbComp);
      }
      else{
	affect(xpi, ypi, zpi, valpi, epi, 2, xp, yp, zp, valp, ep, 3, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 3, xp, yp, zp, valp, ep, 1, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 4, xp, yp, zp, valp, ep, 4, nbComp);
	affect(xpi, ypi, zpi, valpi, epi, 5, xp, yp, zp, valp, ep, 2, nbComp);
      }
    }
    for(int i = 0; i < 6; i++)
      affect(xp, yp, zp, valp, ep, i, xpi, ypi, zpi, valpi, epi, i, nbComp);
  }
}
 
void GMSH_LevelsetPlugin::evalLevelset(int nbNod, int nbComp,
				       double *x, double *y, double *z, double *val,
				       double *levels, double *scalarVal)
{
  if(_valueIndependent) {
    for(int k = 0; k < nbNod; k++)
      levels[k] = levelset(x[k], y[k], z[k], 0.0);
  }
  else{
    for(int k = 0; k < nbNod; k++) {
      double *vals = &val[nbComp * k];
      switch(nbComp) {
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
}

void GMSH_LevelsetPlugin::addElement(int timeStep, int np, int nbEdg, int dNbComp,
				     double xp[12], double yp[12], double zp[12],
				     double valp[12][9], std::vector<PViewDataList *> &out)
{
  // select the output data
  PViewDataList *data = _valueIndependent ? out[0] : out[timeStep];
  List_T *list;
  int *nbPtr;
  switch(np){
  case 1:
    if(dNbComp == 1)      { list = data->SP; nbPtr = &data->NbSP; }
    else if(dNbComp == 3) { list = data->VP; nbPtr = &data->NbVP; }
    else                  { list = data->TP; nbPtr = &data->NbTP; }
    break;
  case 2:
    if(dNbComp == 1)      { list = data->SL; nbPtr = &data->NbSL; }
    else if(dNbComp == 3) { list = data->VL; nbPtr = &data->NbVL; }
    else                  { list = data->TL; nbPtr = &data->NbTL; }
    break;
  case 3:
    if(dNbComp == 1)      { list = data->ST; nbPtr = &data->NbST; }
    else if(dNbComp == 3) { list = data->VT; nbPtr = &data->NbVT; }
    else                  { list = data->TT; nbPtr = &data->NbTT; }
    break;
  case 4:
    if(!_extractVolume || nbEdg <= 4){
      if(dNbComp == 1)      { list = data->SQ; nbPtr = &data->NbSQ; }
      else if(dNbComp == 3) { list = data->VQ; nbPtr = &data->NbVQ; }
      else                  { list = data->TQ; nbPtr = &data->NbTQ; }
    }
    else{
      if(dNbComp == 1)      { list = data->SS; nbPtr = &data->NbSS; }
      else if(dNbComp == 3) { list = data->VS; nbPtr = &data->NbVS; }
      else                  { list = data->TS; nbPtr = &data->NbTS; }
    }
    break;
  case 5:
    if(dNbComp == 1)      { list = data->SY; nbPtr = &data->NbSY; }
    else if(dNbComp == 3) { list = data->VY; nbPtr = &data->NbVY; }
    else                  { list = data->TY; nbPtr = &data->NbTY; }
    break;
  case 6:
    if(dNbComp == 1)      { list = data->SI; nbPtr = &data->NbSI; }
    else if(dNbComp == 3) { list = data->VI; nbPtr = &data->NbVI; }
    else                  { list = data->TI; nbPtr = &data->NbTI; }
    break;
  case 8: // should never happen
    if(dNbComp == 1)      { list = data->SH; nbPtr = &data->NbSH; }
    else if(dNbComp == 3) { list = data->VH; nbPtr = &data->NbVH; }
    else                  { list = data->TH; nbPtr = &data->NbTH; }
    break;
  default:
    return;
  }

  // copy the elements in the output data
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
}

void GMSH_LevelsetPlugin::nonZeroLevelset(int timeStep, 
					  int nbNod, int nbEdg, int exn[12][2],
					  double *x, double *y, double *z, 
					  double *iVal, int iNbComp,
					  double *dVal, int dNbComp,
					  std::vector<PViewDataList*> &out)
{
  double levels[8], scalarVal[8];
  
  evalLevelset(nbNod, iNbComp, x, y, z, iVal, levels, scalarVal);
  
  int add = 1;
  for(int k = 0; k < nbNod; k++){
    if((_extractVolume < 0. && levels[k] > 0.) ||
       (_extractVolume > 0. && levels[k] < 0.)){
      add = 0;
      break;
    }
  }
  
  if(add){
    double xp[12], yp[12], zp[12], valp[12][9];
    for(int k = 0; k < nbNod; k++){
      xp[k] = x[k];
      yp[k] = y[k];
      zp[k] = z[k];
      for(int l = 0; l < dNbComp; l++)
	valp[k][l] = dVal[dNbComp * k + l];
    }
    addElement(timeStep, nbNod, nbEdg, dNbComp, xp, yp, zp, valp, out);
  }
}

int GMSH_LevelsetPlugin::zeroLevelset(int timeStep, 
				      int nbNod, int nbEdg, int exn[12][2],
				      double *x, double *y, double *z, 
				      double *iVal, int iNbComp,
				      double *dVal, int dNbComp,
				      std::vector<PViewDataList*> &out)
{
  double levels[8], scalarVal[8];

  evalLevelset(nbNod, iNbComp, x, y, z, iVal, levels, scalarVal);

  // interpolate the zero levelset and the field to plot on it
  double xp[12], yp[12], zp[12], valp[12][9];
  int np = 0, ep[12];
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
      ep[np] = k+1;
      np++;
    }
  }

  if(!iVal || !dVal)
    return np;

  // Remove identical nodes (this can happen if an edge actually
  // belongs to the zero levelset, i.e., if levels[] * levels[] == 0)
  if(np > 1)
    removeIdenticalNodes(&np, dNbComp, xp, yp, zp, valp, ep);

  if(nbEdg > 4 && np < 3) // 3D input should only lead to 2D output
    return 0;
  else if(nbEdg > 1 && np < 2) // 2D input should only lead to 1D output
    return 0;
  else if(np < 1 || np > 4) // can't deal with this
    return 0;

  // avoid "butterflies"
  if(np == 4)
    reorderQuad(dNbComp, xp, yp, zp, valp, ep);
      
  // orient the triangles and the quads to get the normals right
  if(!_extractVolume && (np == 3 || np == 4)) {
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
      int epi[12];
      for(int k = 0; k < np; k++)
	affect(xpi, ypi, zpi, valpi, epi, k, xp, yp, zp, valp, ep, k, dNbComp);
      for(int k = 0; k < np; k++)
	affect(xp, yp, zp, valp, ep, k, xpi, ypi, zpi, valpi, epi, np-k-1, dNbComp);
    }
  }

  // if we compute isovolumes, add the nodes on the chosen side 
  if(_extractVolume){
    // FIXME: when cutting 2D views, the elts we get can have the wrong
    // orientation
    int nbCut = np;
    for(int k = 0; k < nbNod; k++){
      if((_extractVolume < 0. && levels[k] < 0.0) ||
	 (_extractVolume > 0. && levels[k] > 0.0)){
	xp[np] = x[k];
	yp[np] = y[k];
	zp[np] = z[k];
	for(int l = 0; l < dNbComp; l++)
	  valp[np][l] = dVal[dNbComp * k + l];
	ep[np] = -(k+1); // node num!
	np++;
      }
    }
    removeIdenticalNodes(&np, dNbComp, xp, yp, zp, valp, ep);
    if(np == 4 && nbEdg <= 4)
      reorderQuad(dNbComp, xp, yp, zp, valp, ep);
    if(np == 6)
      reorderPrism(dNbComp, xp, yp, zp, valp, ep, nbCut, exn);
    if(np > 8) // can't deal with this
      return 0;
  }

  addElement(timeStep, np, nbEdg, dNbComp, xp, yp, zp, valp, out);
  
  return 0;
}

void GMSH_LevelsetPlugin::executeList(PViewDataList *iData, List_T *iList,
				      int iNbElm, int iNbComp,
				      PViewDataList *dData, List_T *dList,
				      int dNbElm, int dNbComp,
				      int nbNod, int nbEdg, int exn[12][2], 
				      std::vector<PViewDataList*> &out)
{
  if(!iNbElm || !dNbElm) 
    return;
  
  if(iNbElm != dNbElm) {
    Msg(GERROR, "Views have a different number of elements (%d != %d)", iNbElm, dNbElm);
    return;
  }

  int dTimeStep = _valueTimeStep;
  if(dTimeStep >= dData->getNumTimeSteps()) {
    Msg(GERROR, "Wrong time step %d in view", dTimeStep);
    return;
  }

  int iNb = List_Nbr(iList) / iNbElm;
  int dNb = List_Nbr(dList) / dNbElm;
  for(int i = 0, j = 0; i < List_Nbr(iList); i += iNb, j += dNb) {
    double *x = (double *)List_Pointer_Fast(iList, i);
    double *y = (double *)List_Pointer_Fast(iList, i + nbNod);
    double *z = (double *)List_Pointer_Fast(iList, i + 2 * nbNod);

    if(nbNod == 1 || nbNod == 2 || nbNod == 3 || (nbNod == 4 && nbEdg == 6)) {
      // easy for simplices: at most one element is created per time step 
      for(int iTS = 0; iTS < iData->getNumTimeSteps(); iTS++) {
	int dTS = (dTimeStep < 0) ? iTS : dTimeStep;
	// don't compute the zero levelset of the value view
	if(dTimeStep < 0 || iData != dData || dTS != iTS) {
	  double *iVal = (double *)List_Pointer_Fast(iList, i + 3 * nbNod + 
						     iNbComp * nbNod * iTS); 
	  double *dVal = (double *)List_Pointer_Fast(dList, j + 3 * nbNod + 
						     dNbComp * nbNod * dTS);
	  zeroLevelset(iTS, nbNod, nbEdg, exn, x, y, z, 
		       iVal, iNbComp, dVal, dNbComp, out);
	  if(_extractVolume)
	    nonZeroLevelset(iTS, nbNod, nbEdg, exn, x, y, z, 
			    iVal, iNbComp, dVal, dNbComp, out);
	}
      }
    }
    else{
      // we decompose the element into simplices
      MakeSimplex iDec(nbNod, iNbComp);
      MakeSimplex dDec(nbNod, dNbComp);
      
      int nbNodNew = iDec.numSimplexNodes();
      int nbEdgNew = (nbNodNew == 4) ? 6 : 3;
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
	if(zeroLevelset(0, nbNod, nbEdg, exn, x, y, z, NULL, 0, 
			NULL, 0, out)) {
	  for(int k = 0; k < iDec.numSimplices(); k++) {
	    for(int iTS = 0; iTS < iData->getNumTimeSteps(); iTS++) {
	      int dTS = (dTimeStep < 0) ? iTS : dTimeStep;
	      // don't compute the zero levelset of the value view
	      if(dTimeStep < 0 || iData != dData || dTS != iTS) {
		double *iVal = (double *)List_Pointer_Fast(iList, i + 3 * nbNod + 
							   iNbComp * nbNod * iTS); 
		double *dVal = (double *)List_Pointer_Fast(dList, j + 3 * nbNod + 
							   dNbComp * nbNod * dTS);
		iDec.decompose(k, x, y, z, iVal, xNew, yNew, zNew, iValNew);
		dDec.decompose(k, x, y, z, dVal, xNew, yNew, zNew, dValNew);
		zeroLevelset(iTS, nbNodNew, nbEdgNew, (nbNodNew == 4) ? exnTet : exnTri, 
			     xNew, yNew, zNew, iValNew, iNbComp, dValNew, dNbComp, out);
		if(_extractVolume)
		  nonZeroLevelset(iTS, nbNodNew, nbEdgNew, (nbNodNew == 4) ? exnTet : exnTri, 
				  xNew, yNew, zNew, iValNew, iNbComp, dValNew, dNbComp, out);
	      }
	    }
	  }
	}
	else if(_extractVolume){
	  for(int iTS = 0; iTS < iData->getNumTimeSteps(); iTS++) {
	    int dTS = (dTimeStep < 0) ? iTS : dTimeStep;
	    // don't compute the zero levelset of the value view
	    if(dTimeStep < 0 || iData != dData || dTS != iTS) {
	      double *iVal = (double *)List_Pointer_Fast(iList, i + 3 * nbNod + 
							 iNbComp * nbNod * iTS); 
	      double *dVal = (double *)List_Pointer_Fast(dList, j + 3 * nbNod + 
							 dNbComp * nbNod * dTS);
	      nonZeroLevelset(iTS, nbNod, nbEdg, exn, x, y, z, 
			      iVal, iNbComp, dVal, dNbComp, out);
	    }
	  }
	}
      }
      else{
	// since we generate one view for each time step, we can
	// generate multiple elements per time step without problem.
	for(int iTS = 0; iTS < iData->getNumTimeSteps(); iTS++) {
	  int dTS = (dTimeStep < 0) ? iTS : dTimeStep;
	  // don't compute the zero levelset of the value view
	  if(dTimeStep < 0 || iData != dData || dTS != iTS) {
	    double *iVal = (double *)List_Pointer_Fast(iList, i + 3 * nbNod +
						       iNbComp * nbNod * iTS); 
	    double *dVal = (double *)List_Pointer_Fast(dList, j + 3 * nbNod +
						       dNbComp * nbNod * dTS);
	    if(zeroLevelset(iTS, nbNod, nbEdg, exn, x, y, z, iVal, iNbComp, 
			    NULL, 0, out)) {
	      for(int k = 0; k < iDec.numSimplices(); k++) {
		iDec.decompose(k, x, y, z, iVal, xNew, yNew, zNew, iValNew);
		dDec.decompose(k, x, y, z, dVal, xNew, yNew, zNew, dValNew);
		zeroLevelset(iTS, nbNodNew, nbEdgNew, (nbNodNew == 4) ? exnTet : exnTri, 
			     xNew, yNew, zNew, iValNew, iNbComp, dValNew, dNbComp, out);
		if(_extractVolume)
		  nonZeroLevelset(iTS, nbNodNew, nbEdgNew, (nbNodNew == 4) ? exnTet : exnTri, 
				  xNew, yNew, zNew, iValNew, iNbComp, dValNew, dNbComp, out);
	      }
	    }
	    else if(_extractVolume)
	      nonZeroLevelset(iTS, nbNod, nbEdg, exn, x, y, z, 
			      iVal, iNbComp, dVal, dNbComp, out);
	  }
	}
      }
      
      delete [] iValNew;
      delete [] dValNew;
    }

  }
}
  
PView *GMSH_LevelsetPlugin::execute(PView *v)
{
  PView *w;
  std::vector<PViewDataList*> out;

  PViewDataList *dv = getDataList(v);
  if(!dv) return v;

  if(dv->isAdaptive()){
    dv->adaptive->setTolerance(_targetError);
    if(dv->NbST || dv->NbSS || dv->NbSQ || dv->NbSH)
      dv->setAdaptiveResolutionLevel(_recurLevel, this);
  }

  if(_valueView < 0) {
    w = v;
  }
  else if(_valueView < 0 || _valueView > PView::list.size() - 1){
    Msg(GERROR, "View[%d] does not exist: reverting to View[%d]", 
	_valueView, v->getIndex());
    w = v;
  }
  else{
    w = PView::list[_valueView];
  }

  PViewDataList *dw = getDataList(w);
  if(!dw) return v;

  if(_valueIndependent) {
    out.push_back(getDataList(new PView(true)));
  }
  else{
    for(int ts = 0; ts < dv->getNumTimeSteps(); ts++)
      out.push_back(getDataList(new PView(true)));
  }

  // We should definitely recode the View interface in C++ (and define
  // iterators on the different kinds of elements...)

  // To avoid surprising results, we don't try to plot values of
  // different types on the levelset if the value view (w) is the same
  // as the levelset view (v).

  // points
  executeList(dv, dv->SP, dv->NbSP, 1, dw, dw->SP, dw->NbSP, 1, 1, 0, 0, out);
  if(dv != dw) {
    executeList(dv, dv->SP, dv->NbSP, 1, dw, dw->VP, dw->NbVP, 3, 1, 0, 0, out);
    executeList(dv, dv->SP, dv->NbSP, 1, dw, dw->TP, dw->NbTP, 9, 1, 0, 0, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VP, dv->NbVP, 3, dw, dw->SP, dw->NbSP, 1, 1, 0, 0, out);
  }
  executeList(dv, dv->VP, dv->NbVP, 3, dw, dw->VP, dw->NbVP, 3, 1, 0, 0, out);
  if(dv != dw) {
    executeList(dv, dv->VP, dv->NbVP, 3, dw, dw->TP, dw->NbTP, 9, 1, 0, 0, out);
  }

  if(dv != dw) {
    executeList(dv, dv->TP, dv->NbTP, 9, dw, dw->SP, dw->NbSP, 1, 1, 0, 0, out);
    executeList(dv, dv->TP, dv->NbTP, 9, dw, dw->VP, dw->NbVP, 3, 1, 0, 0, out);
  }
  executeList(dv, dv->TP, dv->NbTP, 9, dw, dw->TP, dw->NbTP, 9, 1, 0, 0, out);

  // lines
  int exnLin[12][2] = {{0,1}};
  executeList(dv, dv->SL, dv->NbSL, 1, dw, dw->SL, dw->NbSL, 1, 2, 1, exnLin, out);
  if(dv != dw) {
    executeList(dv, dv->SL, dv->NbSL, 1, dw, dw->VL, dw->NbVL, 3, 2, 1, exnLin, out);
    executeList(dv, dv->SL, dv->NbSL, 1, dw, dw->TL, dw->NbTL, 9, 2, 1, exnLin, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VL, dv->NbVL, 3, dw, dw->SL, dw->NbSL, 1, 2, 1, exnLin, out);
  }
  executeList(dv, dv->VL, dv->NbVL, 3, dw, dw->VL, dw->NbVL, 3, 2, 1, exnLin, out);
  if(dv != dw) {
    executeList(dv, dv->VL, dv->NbVL, 3, dw, dw->TL, dw->NbTL, 9, 2, 1, exnLin, out);
  }

  if(dv != dw) {
    executeList(dv, dv->TL, dv->NbTL, 9, dw, dw->SL, dw->NbSL, 1, 2, 1, exnLin, out);
    executeList(dv, dv->TL, dv->NbTL, 9, dw, dw->VL, dw->NbVL, 3, 2, 1, exnLin, out);
  }
  executeList(dv, dv->TL, dv->NbTL, 9, dw, dw->TL, dw->NbTL, 9, 2, 1, exnLin, out);

  // triangles
  int exnTri[12][2] = {{0,1}, {0,2}, {1,2}};
  executeList(dv, dv->ST, dv->NbST, 1, dw, dw->ST, dw->NbST, 1, 3, 3, exnTri, out);
  if(dv != dw) {
    executeList(dv, dv->ST, dv->NbST, 1, dw, dw->VT, dw->NbVT, 3, 3, 3, exnTri, out);
    executeList(dv, dv->ST, dv->NbST, 1, dw, dw->TT, dw->NbTT, 9, 3, 3, exnTri, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VT, dv->NbVT, 3, dw, dw->ST, dw->NbST, 1, 3, 3, exnTri, out);
  }
  executeList(dv, dv->VT, dv->NbVT, 3, dw, dw->VT, dw->NbVT, 3, 3, 3, exnTri, out);
  if(dv != dw) {
    executeList(dv, dv->VT, dv->NbVT, 3, dw, dw->TT, dw->NbTT, 9, 3, 3, exnTri, out);
  }

  if(dv != dw) {
    executeList(dv, dv->TT, dv->NbTT, 9, dw, dw->ST, dw->NbST, 1, 3, 3, exnTri, out);
    executeList(dv, dv->TT, dv->NbTT, 9, dw, dw->VT, dw->NbVT, 3, 3, 3, exnTri, out);
  }
  executeList(dv, dv->TT, dv->NbTT, 9, dw, dw->TT, dw->NbTT, 9, 3, 3, exnTri, out);

  // tets
  int exnTet[12][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  executeList(dv, dv->SS, dv->NbSS, 1, dw, dw->SS, dw->NbSS, 1, 4, 6, exnTet, out);
  if(dv != dw) {
    executeList(dv, dv->SS, dv->NbSS, 1, dw, dw->VS, dw->NbVS, 3, 4, 6, exnTet, out);
    executeList(dv, dv->SS, dv->NbSS, 1, dw, dw->TS, dw->NbTS, 9, 4, 6, exnTet, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VS, dv->NbVS, 3, dw, dw->SS, dw->NbSS, 1, 4, 6, exnTet, out);
  }
  executeList(dv, dv->VS, dv->NbVS, 3, dw, dw->VS, dw->NbVS, 3, 4, 6, exnTet, out);
  if(dv != dw) {
    executeList(dv, dv->VS, dv->NbVS, 3, dw, dw->TS, dw->NbTS, 9, 4, 6, exnTet, out);
  }

  if(dv != dw) {
    executeList(dv, dv->TS, dv->NbTS, 9, dw, dw->SS, dw->NbSS, 1, 4, 6, exnTet, out);
    executeList(dv, dv->TS, dv->NbTS, 9, dw, dw->VS, dw->NbVS, 3, 4, 6, exnTet, out);
  }
  executeList(dv, dv->TS, dv->NbTS, 9, dw, dw->TS, dw->NbTS, 9, 4, 6, exnTet, out);

  // quads
  int exnQua[12][2] = {{0,1}, {0,3}, {1,2}, {2,3}};
  executeList(dv, dv->SQ, dv->NbSQ, 1, dw, dw->SQ, dw->NbSQ, 1, 4, 4, exnQua, out);
  if(dv != dw) {
    executeList(dv, dv->SQ, dv->NbSQ, 1, dw, dw->VQ, dw->NbVQ, 3, 4, 4, exnQua, out);
    executeList(dv, dv->SQ, dv->NbSQ, 1, dw, dw->TQ, dw->NbTQ, 9, 4, 4, exnQua, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VQ, dv->NbVQ, 3, dw, dw->SQ, dw->NbSQ, 1, 4, 4, exnQua, out);
  }
  executeList(dv, dv->VQ, dv->NbVQ, 3, dw, dw->VQ, dw->NbVQ, 3, 4, 4, exnQua, out);
  if(dv != dw) {
    executeList(dv, dv->VQ, dv->NbVQ, 3, dw, dw->TQ, dw->NbTQ, 9, 4, 4, exnQua, out);
  }

  if(dv != dw) {
    executeList(dv, dv->TQ, dv->NbTQ, 9, dw, dw->SQ, dw->NbSQ, 1, 4, 4, exnQua, out);
    executeList(dv, dv->TQ, dv->NbTQ, 9, dw, dw->VQ, dw->NbVQ, 3, 4, 4, exnQua, out);
  }
  executeList(dv, dv->TQ, dv->NbTQ, 9, dw, dw->TQ, dw->NbTQ, 9, 4, 4, exnQua, out);

  // hexes
  int exnHex[12][2] = {{0,1}, {0,3}, {0,4}, {1,2}, {1,5}, {2,3},
		       {2,6}, {3,7}, {4,5}, {4,7}, {5,6}, {6,7}};
  executeList(dv, dv->SH, dv->NbSH, 1, dw, dw->SH, dw->NbSH, 1, 8, 12, exnHex, out);
  if(dv != dw) {
    executeList(dv, dv->SH, dv->NbSH, 1, dw, dw->VH, dw->NbVH, 3, 8, 12, exnHex, out);
    executeList(dv, dv->SH, dv->NbSH, 1, dw, dw->TH, dw->NbTH, 9, 8, 12, exnHex, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VH, dv->NbVH, 3, dw, dw->SH, dw->NbSH, 1, 8, 12, exnHex, out);
  }
  executeList(dv, dv->VH, dv->NbVH, 3, dw, dw->VH, dw->NbVH, 3, 8, 12, exnHex, out);
  if(dv != dw) {
    executeList(dv, dv->VH, dv->NbVH, 3, dw, dw->TH, dw->NbTH, 9, 8, 12, exnHex, out);
  }

  if(dv != dw) {
    executeList(dv, dv->TH, dv->NbTH, 9, dw, dw->SH, dw->NbSH, 1, 8, 12, exnHex, out);
    executeList(dv, dv->TH, dv->NbTH, 9, dw, dw->VH, dw->NbVH, 3, 8, 12, exnHex, out);
  }
  executeList(dv, dv->TH, dv->NbTH, 9, dw, dw->TH, dw->NbTH, 9, 8, 12, exnHex, out);

  // prisms
  int exnPri[12][2] = {{0,1}, {0,2}, {0,3}, {1,2}, {1,4}, {2,5},
		       {3,4}, {3,5}, {4,5}};
  executeList(dv, dv->SI, dv->NbSI, 1, dw, dw->SI, dw->NbSI, 1, 6, 9, exnPri, out);
  if(dv != dw) {
    executeList(dv, dv->SI, dv->NbSI, 1, dw, dw->VI, dw->NbVI, 3, 6, 9, exnPri, out);
    executeList(dv, dv->SI, dv->NbSI, 1, dw, dw->TI, dw->NbTI, 9, 6, 9, exnPri, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VI, dv->NbVI, 3, dw, dw->SI, dw->NbSI, 1, 6, 9, exnPri, out);
  }
  executeList(dv, dv->VI, dv->NbVI, 3, dw, dw->VI, dw->NbVI, 3, 6, 9, exnPri, out);
  if(dv != dw) {
    executeList(dv, dv->VI, dv->NbVI, 3, dw, dw->TI, dw->NbTI, 9, 6, 9, exnPri, out);
  }
 
  if(dv != dw) {
    executeList(dv, dv->TI, dv->NbTI, 9, dw, dw->SI, dw->NbSI, 1, 6, 9, exnPri, out);
    executeList(dv, dv->TI, dv->NbTI, 9, dw, dw->VI, dw->NbVI, 3, 6, 9, exnPri, out);
  }
  executeList(dv, dv->TI, dv->NbTI, 9, dw, dw->TI, dw->NbTI, 9, 6, 9, exnPri, out);

  // pyramids
  int exnPyr[12][2] = {{0,1}, {0,3}, {0,4}, {1,2}, {1,4}, {2,3}, {2,4}, {3,4}};
  executeList(dv, dv->SY, dv->NbSY, 1, dw, dw->SY, dw->NbSY, 1, 5, 8, exnPyr, out);
  if(dv != dw) {
    executeList(dv, dv->SY, dv->NbSY, 1, dw, dw->VY, dw->NbVY, 3, 5, 8, exnPyr, out);
    executeList(dv, dv->SY, dv->NbSY, 1, dw, dw->TY, dw->NbTY, 9, 5, 8, exnPyr, out);
  }

  if(dv != dw) {
    executeList(dv, dv->VY, dv->NbVY, 3, dw, dw->SY, dw->NbSY, 1, 5, 8, exnPyr, out);
  }
  executeList(dv, dv->VY, dv->NbVY, 3, dw, dw->VY, dw->NbVY, 3, 5, 8, exnPyr, out);
  if(dv != dw) {
    executeList(dv, dv->VY, dv->NbVY, 3, dw, dw->TY, dw->NbTY, 9, 5, 8, exnPyr, out);
  }

  if(dv != dw) {
    executeList(dv, dv->TY, dv->NbTY, 9, dw, dw->SY, dw->NbSY, 1, 5, 8, exnPyr, out);
    executeList(dv, dv->TY, dv->NbTY, 9, dw, dw->VY, dw->NbVY, 3, 5, 8, exnPyr, out);
  }
  executeList(dv, dv->TY, dv->NbTY, 9, dw, dw->TY, dw->NbTY, 9, 5, 8, exnPyr, out);

  for(unsigned int i = 0; i < out.size(); i++) {
    // FIXME: create time data
    char tmp[246];
    sprintf(tmp, "_Levelset_%d", i);
    out[i]->setName(dv->getName() + tmp);
    out[i]->setFileName(dv->getFileName() + tmp + ".pos");
    out[i]->finalize();
  }

  return 0;
}

// On high order maps, we draw only the elements that have a cut with
// the levelset, this is as accurate as it should be

static bool recur_sign_change(adapt_triangle *t, double val,
			      const GMSH_LevelsetPlugin *plug)
{
  if(!t->e[0] || t->visible){
    double v1 = plug->levelset(t->p[0]->X, t->p[0]->Y, t->p[0]->Z, t->p[0]->val);
    double v2 = plug->levelset(t->p[1]->X, t->p[1]->Y, t->p[1]->Z, t->p[1]->val);
    double v3 = plug->levelset(t->p[2]->X, t->p[2]->Y, t->p[2]->Z, t->p[2]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0)
      t->visible = false;
    else
      t->visible = true;
    return t->visible;
  }
  else{
    bool sc1 = recur_sign_change(t->e[0], val, plug);
    bool sc2 = recur_sign_change(t->e[1], val, plug);
    bool sc3 = recur_sign_change(t->e[2], val, plug);
    bool sc4 = recur_sign_change(t->e[3], val, plug);
    if(sc1 || sc2 || sc3 || sc4){
      if (!sc1) t->e[0]->visible = true;
      if (!sc2) t->e[1]->visible = true;
      if (!sc3) t->e[2]->visible = true;
      if (!sc4) t->e[3]->visible = true;
      return true;
    }
    t->visible = false;
    return false;
  }      
}

static bool recur_sign_change(adapt_tet *t, double val, 
			      const GMSH_LevelsetPlugin *plug)
{
  if(!t->e[0] || t->visible){
    double v1 = plug->levelset(t->p[0]->X, t->p[0]->Y, t->p[0]->Z, t->p[0]->val);
    double v2 = plug->levelset(t->p[1]->X, t->p[1]->Y, t->p[1]->Z, t->p[1]->val);
    double v3 = plug->levelset(t->p[2]->X, t->p[2]->Y, t->p[2]->Z, t->p[2]->val);
    double v4 = plug->levelset(t->p[3]->X, t->p[3]->Y, t->p[3]->Z, t->p[3]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0 && v1 * v4 > 0)
      t->visible = false;
    else
      t->visible = true;
    return t->visible;
  }
  else{
    bool sc1 = recur_sign_change(t->e[0], val, plug);
    bool sc2 = recur_sign_change(t->e[1], val, plug);
    bool sc3 = recur_sign_change(t->e[2], val, plug);
    bool sc4 = recur_sign_change(t->e[3], val, plug);
    bool sc5 = recur_sign_change(t->e[4], val, plug);
    bool sc6 = recur_sign_change(t->e[5], val, plug);
    bool sc7 = recur_sign_change(t->e[6], val, plug);
    bool sc8 = recur_sign_change(t->e[7], val, plug);
    if(sc1 || sc2 || sc3 || sc4 || sc5 || sc6 || sc7 || sc8){
      if(!sc1) t->e[0]->visible = true;
      if(!sc2) t->e[1]->visible = true;
      if(!sc3) t->e[2]->visible = true;
      if(!sc4) t->e[3]->visible = true;
      if(!sc5) t->e[4]->visible = true;
      if(!sc6) t->e[5]->visible = true;
      if(!sc7) t->e[6]->visible = true;
      if(!sc8) t->e[7]->visible = true;
      return true;
    }
    t->visible = false;
    return false;
  }      
}

static bool recur_sign_change(adapt_hex *t, double val,
			      const GMSH_LevelsetPlugin *plug)
{
  if (!t->e[0]|| t->visible){
    double v1 = plug->levelset(t->p[0]->X, t->p[0]->Y, t->p[0]->Z, t->p[0]->val);
    double v2 = plug->levelset(t->p[1]->X, t->p[1]->Y, t->p[1]->Z, t->p[1]->val);
    double v3 = plug->levelset(t->p[2]->X, t->p[2]->Y, t->p[2]->Z, t->p[2]->val);
    double v4 = plug->levelset(t->p[3]->X, t->p[3]->Y, t->p[3]->Z, t->p[3]->val);
    double v5 = plug->levelset(t->p[4]->X, t->p[4]->Y, t->p[4]->Z, t->p[4]->val);
    double v6 = plug->levelset(t->p[5]->X, t->p[5]->Y, t->p[5]->Z, t->p[5]->val);
    double v7 = plug->levelset(t->p[6]->X, t->p[6]->Y, t->p[6]->Z, t->p[6]->val);
    double v8 = plug->levelset(t->p[7]->X, t->p[7]->Y, t->p[7]->Z, t->p[7]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0 && v1 * v4 > 0 && v1 * v5 > 0 && 
       v1 * v6 > 0 && v1 * v7 > 0 && v1 * v8 > 0)
      t->visible = false;
    else
      t->visible = true;
    return t->visible;
  }
  else{
    bool sc1 = recur_sign_change(t->e[0], val, plug);
    bool sc2 = recur_sign_change(t->e[1], val, plug);
    bool sc3 = recur_sign_change(t->e[2], val, plug);
    bool sc4 = recur_sign_change(t->e[3], val, plug);
    bool sc5 = recur_sign_change(t->e[4], val, plug);
    bool sc6 = recur_sign_change(t->e[5], val, plug);
    bool sc7 = recur_sign_change(t->e[6], val, plug);
    bool sc8 = recur_sign_change(t->e[7], val, plug);
    if(sc1 || sc2 || sc3 || sc4 || sc5 || sc6 || sc7 || sc8){
      if (!sc1) t->e[0]->visible = true;
      if (!sc2) t->e[1]->visible = true;
      if (!sc3) t->e[2]->visible = true;
      if (!sc4) t->e[3]->visible = true;
      if (!sc5) t->e[4]->visible = true;
      if (!sc6) t->e[5]->visible = true;
      if (!sc7) t->e[6]->visible = true;
      if (!sc8) t->e[7]->visible = true;
      return true;
    }
    t->visible = false;
    return false;
  }      
}

static bool recur_sign_change (adapt_quad *q, double val,
			       const GMSH_LevelsetPlugin *plug)
{
  if(!q->e[0]|| q->visible){
    double v1 = plug->levelset(q->p[0]->X, q->p[0]->Y, q->p[0]->Z, q->p[0]->val);
    double v2 = plug->levelset(q->p[1]->X, q->p[1]->Y, q->p[1]->Z, q->p[1]->val);
    double v3 = plug->levelset(q->p[2]->X, q->p[2]->Y, q->p[2]->Z, q->p[2]->val);
    double v4 = plug->levelset(q->p[3]->X, q->p[3]->Y, q->p[3]->Z, q->p[3]->val);
    if(v1 * v2 > 0 && v1 * v3 > 0 && v1 * v4 > 0)
      q->visible = false;
    else
      q->visible = true;
    return q->visible;
  }
  else{
    bool sc1 = recur_sign_change(q->e[0], val, plug);
    bool sc2 = recur_sign_change(q->e[1], val, plug);
    bool sc3 = recur_sign_change(q->e[2], val, plug);
    bool sc4 = recur_sign_change(q->e[3], val, plug);
    if(sc1 || sc2 || sc3 || sc4 ){
      if(!sc1) q->e[0]->visible = true;
      if(!sc2) q->e[1]->visible = true;
      if(!sc3) q->e[2]->visible = true;
      if(!sc4) q->e[3]->visible = true;
      return true;
    }
    q->visible = false;
    return false;
  }      
}

void GMSH_LevelsetPlugin::assignSpecificVisibility () const
{
  if(adapt_triangle::all_elems.size()){
    adapt_triangle *t = *adapt_triangle::all_elems.begin();
    if(!t->visible) t->visible = !recur_sign_change(t, _valueView, this);
  }
  if(adapt_tet::all_elems.size()){
    adapt_tet *te = *adapt_tet::all_elems.begin();
    if(!te->visible) te->visible = !recur_sign_change(te, _valueView, this);
  }
  if(adapt_quad::all_elems.size()){
    adapt_quad *qe = *adapt_quad::all_elems.begin();
    if(!qe->visible) qe->visible = !recur_sign_change(qe, _valueView, this);
  }
  if(adapt_hex::all_elems.size()){
    adapt_hex *he = *adapt_hex::all_elems.begin();
    if(!he->visible) he->visible = !recur_sign_change(he, _valueView, this);
  }
}
