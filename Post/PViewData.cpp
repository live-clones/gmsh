// $Id: PViewData.cpp,v 1.2 2007-08-24 20:14:19 geuzaine Exp $
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
//
// Contributor(s):
// 

#include "PViewData.h"

PViewDataList::PViewDataList(bool allocate)
  : DataSize(sizeof(double)), NbTimeStep(0), 
    ScalarOnly(0), TextOnly(0), Min(VAL_INF), Max(-VAL_INF), Time(0),
    NbSP(0), SP(0), NbVP(0), VP(0), NbTP(0), TP(0),
    NbSL(0), SL(0), NbVL(0), VL(0), NbTL(0), TL(0),
    NbSL2(0), SL2(0), NbVL2(0), VL2(0), NbTL2(0), TL2(0),
    NbST(0), ST(0), NbVT(0), VT(0), NbTT(0), TT(0),
    NbST2(0), ST2(0), NbVT2(0), VT2(0), NbTT2(0), TT2(0),
    NbSQ(0), SQ(0), NbVQ(0), VQ(0), NbTQ(0), TQ(0),
    NbSQ2(0), SQ2(0), NbVQ2(0), VQ2(0), NbTQ2(0), TQ2(0),
    NbSS(0), SS(0), NbVS(0), VS(0), NbTS(0), TS(0),
    NbSS2(0), SS2(0), NbVS2(0), VS2(0), NbTS2(0), TS2(0),
    NbSH(0), SH(0), NbVH(0), VH(0), NbTH(0), TH(0),
    NbSH2(0), SH2(0), NbVH2(0), VH2(0), NbTH2(0), TH2(0),
    NbSI(0), SI(0), NbVI(0), VI(0), NbTI(0), TI(0),
    NbSI2(0), SI2(0), NbVI2(0), VI2(0), NbTI2(0), TI2(0),
    NbSY(0), SY(0), NbVY(0), VY(0), NbTY(0), TY(0),
    NbSY2(0), SY2(0), NbVY2(0), VY2(0), NbTY2(0), TY2(0),
    NbT2(0), T2D(0), T2C(0), NbT3(0), T3D(0), T3C(0)
{
  if(allocate){
#define LCD List_Create(1, 1000, sizeof(double))
    Time = LCD;
    SP = LCD; VP = LCD; TP = LCD;
    SL = LCD; VL = LCD; TL = LCD; SL2 = LCD; VL2 = LCD; TL2 = LCD; 
    ST = LCD; VT = LCD; TT = LCD; ST2 = LCD; VT2 = LCD; TT2 = LCD; 
    SQ = LCD; VQ = LCD; TQ = LCD; SQ2 = LCD; VQ2 = LCD; TQ2 = LCD; 
    SS = LCD; VS = LCD; TS = LCD; SS2 = LCD; VS2 = LCD; TS2 = LCD; 
    SH = LCD; VH = LCD; TH = LCD; SH2 = LCD; VH2 = LCD; TH2 = LCD; 
    SI = LCD; VI = LCD; TI = LCD; SI2 = LCD; VI2 = LCD; TI2 = LCD; 
    SY = LCD; VY = LCD; TY = LCD; SY2 = LCD; VY2 = LCD; TY2 = LCD; 
#undef LCD
    T2D = List_Create(1, 100, sizeof(double));
    T2C = List_Create(1, 100, sizeof(char));
    T3D = List_Create(1, 100, sizeof(double));
    T3C = List_Create(1, 100, sizeof(char));
    Grains = new std::map<int, List_T*>;
    DisplayListsOfGrains= new std::map<int, int>;
  }
}

PViewDataList::~PViewDataList()
{
  List_Delete(Time);
  List_Delete(SP); List_Delete(VP); List_Delete(TP);
  List_Delete(SL); List_Delete(VL); List_Delete(TL);
  List_Delete(ST); List_Delete(VT); List_Delete(TT);
  List_Delete(SQ); List_Delete(VQ); List_Delete(TQ);
  List_Delete(SS); List_Delete(VS); List_Delete(TS);
  List_Delete(SH); List_Delete(VH); List_Delete(TH);
  List_Delete(SI); List_Delete(VI); List_Delete(TI);
  List_Delete(SY); List_Delete(VY); List_Delete(TY);
  List_Delete(T2D); List_Delete(T2C);
  List_Delete(T3D); List_Delete(T3C);
  if(Grains) delete Grains;
  if(DisplayListsOfGrains) delete DisplayListsOfGrains;
}

void PViewDataList::finalize()
{
  // finalize text strings first, to get the max value of NbTimeStep
  // for strings-only views (strings are designed to degrade
  // gracefully when some have fewer time steps than others). If there
  // are any elements in the view, this value will be replaced by the
  // minimum number of time steps common to all elements.
  _stat(T2D, T2C, 4); _stat(T3D, T3C, 5);

  // convert all "old-style" (non adaptive) 2nd order elements into
  // linear elements *and* free all the data associated with the
  // 2nd order elements
  //FIXME:   _splitCurvedElements();

  // compute min/max and other statistics for all element lists
  _stat(SP, 1, NbSP, 1); _stat(VP, 3, NbVP, 1); _stat(TP, 9, NbTP, 1);
  _stat(SL, 1, NbSL, 2); _stat(VL, 3, NbVL, 2); _stat(TL, 9, NbTL, 2);
  _stat(ST, 1, NbST, 3); _stat(VT, 3, NbVT, 3); _stat(TT, 9, NbTT, 3);
  _stat(SQ, 1, NbSQ, 4); _stat(VQ, 3, NbVQ, 4); _stat(TQ, 9, NbTQ, 4);
  _stat(SS, 1, NbSS, 4); _stat(VS, 3, NbVS, 4); _stat(TS, 9, NbTS, 4);
  _stat(SH, 1, NbSH, 8); _stat(VH, 3, NbVH, 8); _stat(TH, 9, NbTH, 8);
  _stat(SI, 1, NbSI, 6); _stat(VI, 3, NbVI, 6); _stat(TI, 9, NbTI, 6);
  _stat(SY, 1, NbSY, 5); _stat(VY, 3, NbVY, 5); _stat(TY, 9, NbTY, 5);

  // add dummy time values if none (or too few) time values are
  // provided (e.g. using the old parsed format)
  if(Time && List_Nbr(Time) < NbTimeStep) {
    for(int i = List_Nbr(Time); i < NbTimeStep; i++) {
      double d = (double)i;
      List_Add(Time, &d);
    }
  }

  setDirty(false);
}

double PViewDataList::getMin(int step)
{
  if(step < 0) return Min;
  return TimeStepMin[step];
}

double PViewDataList::getMax(int step)
{
  if(step < 0) return Max;
  return TimeStepMax[step];
}

void PViewDataList::_stat(List_T *D, List_T *C, int nb)
{
  // compute statistics for text lists
  for(int i = 0; i < List_Nbr(D); i += nb){
    double beg, end;
    List_Read(D, i + nb - 1, &beg);
    if(i > List_Nbr(D) - 2 * nb)
      end = (double)List_Nbr(C);
    else
      List_Read(D, i + nb + nb - 1, &end);
    char *c = (char*)List_Pointer(C, (int)beg);
    int nbtime = 0;
    for(int j = 0; j < (int)(end - beg); j++)
      if(c[j] == '\0') nbtime++;
    if(nbtime > NbTimeStep) 
      NbTimeStep = nbtime;
  }
  if(nb == 5){
    for(int i = 0; i < List_Nbr(D); i += nb){
      double x, y, z;
      List_Read(D, i, &x);
      List_Read(D, i + 1, &y);
      List_Read(D, i + 2, &z);
      BBox += SPoint3(x, y, z);
    }
  }
}

double vonMises(double *V)
{
  double tr = (V[0] + V[4] + V[8]) / 3.;
  double v11 = V[0] - tr, v12 = V[1],      v13 = V[2];
  double v21 = V[3],      v22 = V[4] - tr, v23 = V[5];
  double v31 = V[6],      v32 = V[7],      v33 = V[8] - tr;
  return sqrt(1.5 * (v11 * v11 + v12 * v12 + v13 * v13 +
                     v21 * v21 + v22 * v22 + v23 * v23 +
                     v31 * v31 + v32 * v32 + v33 * v33));
}

void PViewDataList::_stat(List_T *list, int nbcomp, int nbelm, int nbnod)
{
  // compute statistics for element lists
  if(!nbelm) return;

  TextOnly = false;
  if(nbcomp > 1) ScalarOnly = false;
  
  int nb = List_Nbr(list) / nbelm;
  for(int i = 0; i < List_Nbr(list); i += nb){
    int N = nb - 3 * nbnod;
    double *X = (double *)List_Pointer_Fast(list, i);
    double *Y = (double *)List_Pointer_Fast(list, i + 1 * nbnod);
    double *Z = (double *)List_Pointer_Fast(list, i + 2 * nbnod);
    double *V = (double *)List_Pointer_Fast(list, i + 3 * nbnod);

    // update bounding box
    for(int j = 0; j < nbnod; j++)
      BBox += SPoint3(X[j], Y[j], Z[j]);

    // update num time steps
    if(Min == VAL_INF || Max == -VAL_INF){
      NbTimeStep = N / (nbcomp * nbnod);
      TimeStepMin.clear();
      TimeStepMax.clear();
      for(int j = 0; j < NbTimeStep; j++){	  
	TimeStepMin.push_back(VAL_INF);
	TimeStepMax.push_back(-VAL_INF);
      }
    }
    else if(N / (nbcomp * nbnod) < NbTimeStep){
      // if some elts have less steps, reduce the total number!
      NbTimeStep = N / (nbcomp * nbnod);
    }
    
    // update min/max
    for(int j = 0; j < N; j += nbcomp) {
      double l0;
      if(nbcomp == 1)
	l0 = V[j];
      else if(nbcomp == 3)
	l0 = sqrt(DSQR(V[j]) + DSQR(V[j + 1]) + DSQR(V[j + 2]));
      else
	l0 = vonMises(V + j); // FIXME: can do better?
      Min = std::min(l0, Min);
      Max = std::max(l0, Max);
      int ts = j / (nbcomp * nbnod);
      if(ts < NbTimeStep){ // security
	TimeStepMin[ts] = std::min(l0, TimeStepMin[ts]);
	TimeStepMax[ts] = std::max(l0, TimeStepMax[ts]);
      }
    }
  }
}

void PViewDataList::_getListIndices(int index[24])
{
  int nb[24] = {NbSP, NbVP, NbTP,  NbSL, NbVL, NbTL,  NbST, NbVT, NbTT, 
		NbSQ, NbVQ, NbTQ,  NbSS, NbVS, NbTS,  NbSH, NbVH, NbTH, 
		NbSI, NbVI, NbTI,  NbSY, NbVY, NbTY};
  for(int i = 0; i < 24; i++){
    index[i] = 0;
    for(int j = 0; j <= i; j++)
      index[i] += nb[j];
  }
}

void PViewDataList::_setLast(int ele, int dim, int nbnod, int nbcomp, 
			     List_T *list, int nblist)
{
  _lastDimension = dim;
  _lastNumNodes = nbnod;
  _lastNumComponents = nbcomp;
  int nb = List_Nbr(list) / nblist;
  _lastXYZ = (double*)List_Pointer_Fast(list, ele * nb);
  _lastVal = (double*)List_Pointer_Fast(list, ele * nb + 3 * _lastNumNodes);
}

void PViewDataList::_setLast(int ele)
{
  int idx[24];
  _getListIndices(idx);
  _lastElement = ele;
  if(ele < idx[2]){ // points
    if(ele < idx[0]) _setLast(ele, 0, 1, 1, SP, NbSP);
    else if(ele < idx[1]) _setLast(ele - idx[0], 0, 1, 3, VP, NbVP);
    else _setLast(ele - idx[1], 0, 1, 9, TP, NbTP);
  }
  else if(ele < idx[5]){ // lines
    if(ele < idx[3]) _setLast(ele - idx[2], 1, 2, 1, SL, NbSL);
    else if(ele < idx[4]) _setLast(ele - idx[3], 1, 2, 3, VL, NbVL);
    else _setLast(ele - idx[4], 1, 2, 9, TL, NbTL);
  }
  else if(ele < idx[8]){ // triangles
    if(ele < idx[6]) _setLast(ele - idx[5], 2, 3, 1, ST, NbST);
    else if(ele < idx[7]) _setLast(ele - idx[6], 2, 3, 3, VT, NbVT);
    else _setLast(ele - idx[7], 2, 3, 9, TT, NbTT);
  }
  else if(ele < idx[11]){ // quadrangles
    if(ele < idx[9]) _setLast(ele - idx[8], 2, 4, 1, SQ, NbSQ);
    else if(ele < idx[10]) _setLast(ele - idx[9], 2, 4, 3, VQ, NbVQ);
    else _setLast(ele - idx[10], 2, 4, 9, TQ, NbTQ);
  }
  else if(ele < idx[14]){ // tetrahedra
    if(ele < idx[12]) _setLast(ele - idx[11], 3, 4, 1, SS, NbSS);
    else if(ele < idx[13]) _setLast(ele - idx[12], 3, 4, 3, VS, NbVS);
    else _setLast(ele - idx[13], 3, 2, 9, TS, NbTS);
  }
  else if(ele < idx[17]){ // hexahedra
    if(ele < idx[15]) _setLast(ele - idx[14], 3, 8, 1, SH, NbSH);
    else if(ele < idx[16]) _setLast(ele - idx[15], 3, 8, 3, VH, NbVH);
    else _setLast(ele - idx[16], 3, 8, 9, TH, NbTH);
  }
  else if(ele < idx[20]){ // prisms
    if(ele < idx[18]) _setLast(ele - idx[17], 3, 6, 1, SI, NbSI);
    else if(ele < idx[19]) _setLast(ele - idx[18], 3, 6, 3, VI, NbVI);
    else _setLast(ele - idx[19], 3, 6, 9, TI, NbTI);
  }
  else{ // pyramids
    if(ele < idx[21]) _setLast(ele - idx[20], 3, 5, 1, SY, NbSY);
    else if(ele < idx[22]) _setLast(ele - idx[21], 3, 5, 3, VY, NbVY);
    else _setLast(ele - idx[22], 3, 5, 9, TY, NbTY);
  }
}

int PViewDataList::getDimension(int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastDimension;
}

int PViewDataList::getNumNodes(int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastNumNodes;
}

void PViewDataList::getNode(int ele, int nod, double &x, double &y, double &z)
{
  if(ele != _lastElement) _setLast(ele);
  x = _lastXYZ[nod];
  y = _lastXYZ[_lastNumNodes + nod];
  z = _lastXYZ[2 * _lastNumNodes + nod];
}

int PViewDataList::getNumComponents(int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastNumComponents;
}

void PViewDataList::getValue(int ele, int nod, int comp, int step, double &val)
{
  if(ele != _lastElement) _setLast(ele);
  val = _lastVal[step * _lastNumNodes  * _lastNumComponents + 
		 nod * _lastNumComponents +
		 comp];
}
