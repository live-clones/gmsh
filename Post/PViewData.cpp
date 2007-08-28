// $Id: PViewData.cpp,v 1.6 2007-08-28 22:54:06 geuzaine Exp $
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
#include "Numeric.h"

PViewDataList::PViewDataList(bool allocate)
  : DataSize(sizeof(double)), NbTimeStep(0), 
    Min(VAL_INF), Max(-VAL_INF), Time(0),
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
    NbT2(0), T2D(0), T2C(0), NbT3(0), T3D(0), T3C(0),
    _lastElement(-1), _lastDimension(-1), _lastNumNodes(-1), 
    _lastNumComponents(-1), _lastNumEdges(-1), _lastXYZ(0), _lastVal(0)
{
  for(int i = 0; i < 24; i++) _index[i] = 0;

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

  // compute starting element indices
  int nb[24] = {NbSP, NbVP, NbTP,  NbSL, NbVL, NbTL,  NbST, NbVT, NbTT, 
		NbSQ, NbVQ, NbTQ,  NbSS, NbVS, NbTS,  NbSH, NbVH, NbTH, 
		NbSI, NbVI, NbTI,  NbSY, NbVY, NbTY};
  for(int i = 0; i < 24; i++){
    _index[i] = 0;
    for(int j = 0; j <= i; j++)
      _index[i] += nb[j];
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

void PViewDataList::_stat(List_T *list, int nbcomp, int nbelm, int nbnod)
{
  // compute statistics for element lists
  if(!nbelm) return;

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
	l0 = ComputeVonMises(V + j); // FIXME: can do better?
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

void PViewDataList::_setLast(int ele, int dim, int nbnod, int nbcomp, int nbedg,
			     List_T *list, int nblist)
{
  _lastDimension = dim;
  _lastNumNodes = nbnod;
  _lastNumComponents = nbcomp;
  _lastNumEdges = nbedg;
  int nb = List_Nbr(list) / nblist;
  _lastXYZ = (double*)List_Pointer_Fast(list, ele * nb);
  _lastVal = (double*)List_Pointer_Fast(list, ele * nb + 3 * _lastNumNodes);
}

void PViewDataList::_setLast(int ele)
{
  _lastElement = ele;
  if(ele < _index[2]){ // points
    if(ele < _index[0]) _setLast(ele, 0, 1, 1, 0, SP, NbSP);
    else if(ele < _index[1]) _setLast(ele - _index[0], 0, 1, 3, 0, VP, NbVP);
    else _setLast(ele - _index[1], 0, 1, 9, 0, TP, NbTP);
  }
  else if(ele < _index[5]){ // lines
    if(ele < _index[3]) _setLast(ele - _index[2], 1, 2, 1, 1, SL, NbSL);
    else if(ele < _index[4]) _setLast(ele - _index[3], 1, 2, 3, 1, VL, NbVL);
    else _setLast(ele - _index[4], 1, 2, 9, 1, TL, NbTL);
  }
  else if(ele < _index[8]){ // triangles
    if(ele < _index[6]) _setLast(ele - _index[5], 2, 3, 1, 3, ST, NbST);
    else if(ele < _index[7]) _setLast(ele - _index[6], 2, 3, 3, 3, VT, NbVT);
    else _setLast(ele - _index[7], 2, 3, 9, 3, TT, NbTT);
  }
  else if(ele < _index[11]){ // quadrangles
    if(ele < _index[9]) _setLast(ele - _index[8], 2, 4, 1, 4, SQ, NbSQ);
    else if(ele < _index[10]) _setLast(ele - _index[9], 2, 4, 3, 4, VQ, NbVQ);
    else _setLast(ele - _index[10], 2, 4, 9, 4, TQ, NbTQ);
  }
  else if(ele < _index[14]){ // tetrahedra
    if(ele < _index[12]) _setLast(ele - _index[11], 3, 4, 1, 6, SS, NbSS);
    else if(ele < _index[13]) _setLast(ele - _index[12], 3, 4, 3, 6, VS, NbVS);
    else _setLast(ele - _index[13], 3, 2, 9, 6, TS, NbTS);
  }
  else if(ele < _index[17]){ // hexahedra
    if(ele < _index[15]) _setLast(ele - _index[14], 3, 8, 1, 12, SH, NbSH);
    else if(ele < _index[16]) _setLast(ele - _index[15], 3, 8, 3, 12, VH, NbVH);
    else _setLast(ele - _index[16], 3, 8, 9, 12, TH, NbTH);
  }
  else if(ele < _index[20]){ // prisms
    if(ele < _index[18]) _setLast(ele - _index[17], 3, 6, 1, 9, SI, NbSI);
    else if(ele < _index[19]) _setLast(ele - _index[18], 3, 6, 3, 9, VI, NbVI);
    else _setLast(ele - _index[19], 3, 6, 9, 9, TI, NbTI);
  }
  else{ // pyramids
    if(ele < _index[21]) _setLast(ele - _index[20], 3, 5, 1, 15, SY, NbSY);
    else if(ele < _index[22]) _setLast(ele - _index[21], 3, 5, 3, 15, VY, NbVY);
    else _setLast(ele - _index[22], 3, 5, 9, 15, TY, NbTY);
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

int PViewDataList::getNumEdges(int ele)
{
  if(ele != _lastElement) _setLast(ele);
  return _lastNumEdges;
}

void PViewDataList::_getString(int dim, int i, int timestep, std::string &str, 
			       double &x, double &y, double &z, double &style)
{
  // 3D: T3D is a list of double: x,y,z,style,index,x,y,z,style,index,...
  //     T3C is a list of chars: string\0,string\0,string\0,string\0,...
  //     Parser format is: T3(x,y,z,style){"str","str",...};
  // 2D: T2D is a list of double: x,y,style,index,x,y,style,index,...
  //     T2C is a list of chars: string\0,string\0,string\0,string\0,...
  //     Parser format is: T2(x,y,style){"str","str",...};

  int nb = (dim == 2) ? NbT2 : NbT3;
  List_T *td = (dim == 2) ? T2D : T3D;
  List_T *tc = (dim == 2) ? T2C : T3C;
  int nbd = (dim == 2) ? 4 : 5;

  int index, nbchar;
  double *d1 = (double *)List_Pointer(td, i * nbd);
  double *d2 = (double *)List_Pointer_Test(td, (i + 1) * nbd);
  if(dim == 2) {
    x = d1[0];
    y = d1[1];
    z = 0.;
    style = d1[2];
    index = (int)d1[3];
    if(d2)
      nbchar = (int)d2[3] - index;
    else
      nbchar = List_Nbr(tc) - index;
  }
  else {
    x = d1[0];
    y = d1[1];
    z = d1[2];
    style = d1[3];
    index = (int)d1[4];
    if(d2)
      nbchar = (int)d2[4] - index;
    else
      nbchar = List_Nbr(tc) - index;
  }
  
  char *c = (char *)List_Pointer(tc, index);
  int k = 0, l = 0;
  while(k < nbchar && l != timestep) {
    if(c[k++] == '\0')
      l++;
  }
  if(k < nbchar && l == timestep)
    str = std::string(&c[k]);
  else
    str = std::string(c);
}

void PViewDataList::getString2D(int i, int step, std::string &str, 
				double &x, double &y, double &style)
{
  double z;
  _getString(2, i, step, str, x, y, z, style);
}

void PViewDataList::getString3D(int i, int step, std::string &str, 
				double &x, double &y, double &z, double &style)
{
  _getString(3, i, step, str, x, y, z, style);
}
