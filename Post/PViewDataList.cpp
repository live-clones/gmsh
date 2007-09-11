// $Id: PViewDataList.cpp,v 1.7 2007-09-11 15:29:02 geuzaine Exp $
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

#include "PViewDataList.h"
#include "Numeric.h"
#include "SmoothData.h"
#include "Message.h"
#include "Context.h"

extern Context_T CTX;

PViewDataList::PViewDataList(bool allocate)
  : PViewData(), DataSize(sizeof(double)), NbTimeStep(0), 
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
    NbT2(0), T2D(0), T2C(0), NbT3(0), T3D(0), T3C(0), adaptive(0), 
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
  if(adaptive) delete adaptive;
}

bool PViewDataList::finalize()
{
  // sanity checks
  if(!adaptive){ // if adaptive, just hope for the best ;-)
    // check that number of values per element = 
    // 3 * number of coordinates + (1,2,9) * integer * number of values
  }

  BBox.reset();
  Min = VAL_INF;
  Max = -VAL_INF;

  // finalize text strings first, to get the max value of NbTimeStep
  // for strings-only views (strings are designed to degrade
  // gracefully when some have fewer time steps than others). If there
  // are any elements in the view, this value will be replaced by the
  // minimum number of time steps common to all elements.
  _stat(T2D, T2C, 4); _stat(T3D, T3C, 5);

  // convert all "old-style" (non adaptive) 2nd order elements into
  // linear elements *and* free all the data associated with the 2nd
  // order elements (this is a temporary solution, until we use
  // Adaptive_Views on all curved elements)
  _splitCurvedElements();

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

  if(CTX.post.smooth) smooth();
  
  setDirty(false);

  return true;
}

int PViewDataList::getNumScalars()
{ 
  return NbSP + NbSL + NbST + NbSQ + NbSS + NbSH + NbSI + NbSY; 
}

int PViewDataList::getNumVectors()
{
  return NbVP + NbVL + NbVT + NbVQ + NbVS + NbVH + NbVI + NbVY; 
}

int PViewDataList::getNumTensors()
{ 
  return NbTP + NbTL + NbTT + NbTQ + NbTS + NbTH + NbTI + NbTY; 
}

int PViewDataList::getNumElements(int type)
{
  if(type){
    switch(type){
    case Point: return NbSP + NbVP + NbTP;
    case Line: return NbSL + NbVL + NbTL;
    case Triangle: return NbST + NbVT + NbTT;
    case Quadrangle: return NbSQ + NbVQ + NbTQ;
    case Tetrahedron: return NbSS + NbVS + NbTS;
    case Hexahedron: return NbSH + NbVH + NbTH;
    case Prism: return NbSI + NbVI + NbTI;
    case Pyramid: return NbSY + NbVY + NbTY;
    default: Msg(GERROR, "Unknown element type"); return 0;
    }
  }

  return getNumScalars() + getNumVectors() + getNumTensors();
}

double PViewDataList::getTime(int step)
{
  if(step < 0 || step >= List_Nbr(Time)) return 0.;
  double val;
  List_Read(Time, step, &val);
  return val;
}

double PViewDataList::getMin(int step)
{
  if(step < 0 || step >= TimeStepMin.size()) return Min;
  return TimeStepMin[step];
}

double PViewDataList::getMax(int step)
{
  if(step < 0 || step >= TimeStepMax.size()) return Max;
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

static void splitCurvedElement(List_T **in, int *nbin, List_T *out, int *nbout, 
			       int nodin, int nodout, int nbcomp, int nbsplit,
			       int split[][8], int remove=1)
{
  if(*nbin){
    int nb = List_Nbr(*in) / *nbin;
    int nbstep = (nb - 3 * nodin) / (nodin * nbcomp); // we don't know this yet for the view
    for(int i = 0; i < List_Nbr(*in); i += nb) {
      double *coord = (double *)List_Pointer_Fast(*in, i);
      double *val = (double *)List_Pointer_Fast(*in, i + 3 * nodin);
      for(int j = 0; j < nbsplit; j++){
	for(int k = 0; k < nodout; k++)
	  List_Add(out, &coord[split[j][k]]);
	for(int k = 0; k < nodout; k++)
	  List_Add(out, &coord[nodin + split[j][k]]);
	for(int k = 0; k < nodout; k++)
	  List_Add(out, &coord[2 * nodin + split[j][k]]);
	for(int ts = 0; ts < nbstep; ts++){
	  for(int k = 0; k < nodout; k++){
	    for(int l = 0; l < nbcomp; l++){
	      List_Add(out, &val[nodin * nbcomp * ts + nbcomp * split[j][k] + l]);
	    }
	  }
	}
	(*nbout)++;
      }
    }
  }

  if(remove){
    *nbin = 0;
    List_Delete(*in);
    *in = NULL;
  }
}

void PViewDataList::_splitCurvedElements()
{
  int lin[2][8] = { // 2-split
    {0,2}, {2,1}
  };
  splitCurvedElement(&SL2, &NbSL2, SL, &NbSL, 3,2, 1, 2, lin);
  splitCurvedElement(&VL2, &NbVL2, VL, &NbVL, 3,2, 3, 2, lin);
  splitCurvedElement(&TL2, &NbTL2, TL, &NbTL, 3,2, 9, 2, lin);

  int tri[4][8] = { // 4-split
    {0,3,5}, {1,4,3}, {2,5,4}, {3,4,5}
  };
  splitCurvedElement(&ST2, &NbST2, ST, &NbST, 6,3, 1, 4, tri);
  splitCurvedElement(&VT2, &NbVT2, VT, &NbVT, 6,3, 3, 4, tri);
  splitCurvedElement(&TT2, &NbTT2, TT, &NbTT, 6,3, 9, 4, tri);

  int qua[4][8] = { // 4-split
    {0,4,8,7}, {1,5,8,4}, {2,6,8,5}, {3,7,8,6}
  };
  splitCurvedElement(&SQ2, &NbSQ2, SQ, &NbSQ, 9,4, 1, 4, qua);
  splitCurvedElement(&VQ2, &NbVQ2, VQ, &NbVQ, 9,4, 3, 4, qua);
  splitCurvedElement(&TQ2, &NbTQ2, TQ, &NbTQ, 9,4, 9, 4, qua);

  int tet[8][8] = { // 8-split
    {0,4,6,7}, {1,5,4,9}, {2,6,5,8}, {3,9,7,8},
    {4,6,7,8}, {4,6,5,8}, {4,5,9,8}, {4,7,9,8}
  };
  splitCurvedElement(&SS2, &NbSS2, SS, &NbSS, 10,4, 1, 8, tet);
  splitCurvedElement(&VS2, &NbVS2, VS, &NbVS, 10,4, 3, 8, tet);
  splitCurvedElement(&TS2, &NbTS2, TS, &NbTS, 10,4, 9, 8, tet);

  int hex[8][8] = { // 8-split
    {0,8,20,9, 10,21,26,22}, {8,1,11,20, 21,12,23,26},
    {9,20,13,3, 22,26,24,15}, {20,11,2,13, 26,23,14,24},
    {10,21,26,22, 4,16,25,17}, {21,12,23,26, 16,5,18,25},
    {22,26,24,15, 17,25,19,7}, {26,23,14,24, 25,18,6,19}
  };
  splitCurvedElement(&SH2, &NbSH2, SH, &NbSH, 27,8, 1, 8, hex);
  splitCurvedElement(&VH2, &NbVH2, VH, &NbVH, 27,8, 3, 8, hex);
  splitCurvedElement(&TH2, &NbTH2, TH, &NbTH, 27,8, 9, 8, hex);

  int pri[8][8] = { // 8-split
    {0,6,7, 8,15,16}, {1,9,6, 10,17,15}, {2,7,9, 11,16,17}, {6,9,7, 15,17,16},
    {8,15,16, 3,12,13}, {10,17,15, 4,14,12}, {11,16,17, 5,13,14}, {15,17,16, 12,14,13}
  };
  splitCurvedElement(&SI2, &NbSI2, SI, &NbSI, 18,6, 1, 8, pri);
  splitCurvedElement(&VI2, &NbVI2, VI, &NbVI, 18,6, 3, 8, pri);
  splitCurvedElement(&TI2, &NbTI2, TI, &NbTI, 18,6, 9, 8, pri);

  int pyr[6][8] = { // 6 pyramids
    {0,5,13,6, 7}, {5,1,8,13, 9}, {6,13,10,3, 12}, {13,8,2,10, 11},
    {7,9,11,12, 4}, {7,12,11,9, 13}
  };
  splitCurvedElement(&SY2, &NbSY2, SY, &NbSY, 14,5, 1, 6, pyr, 0); // don't remove yet
  splitCurvedElement(&VY2, &NbVY2, VY, &NbVY, 14,5, 3, 6, pyr, 0);
  splitCurvedElement(&TY2, &NbTY2, TY, &NbTY, 14,5, 9, 6, pyr, 0);

  int pyr2[4][8] = { // + 4 tets to fill the holes
    {6,12,7,13}, {7,9,5,13}, {9,11,8,13}, {12,10,11,13}
  };
  splitCurvedElement(&SY2, &NbSY2, SS, &NbSS, 14,4, 1, 4, pyr2);
  splitCurvedElement(&VY2, &NbVY2, VS, &NbVS, 14,4, 3, 4, pyr2);
  splitCurvedElement(&TY2, &NbTY2, TS, &NbTS, 14,4, 9, 4, pyr2);
}

static void generateConnectivities(List_T *list, int nbList, 
				   int nbTimeStep, int nbVert, 
				   smooth_data &data)
{
  if(!nbList) return;
  double *vals = new double[nbTimeStep];
  int nb = List_Nbr(list) / nbList;
  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbVert);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbVert);
    double *v = (double *)List_Pointer_Fast(list, i + 3 * nbVert);
    for(int j = 0; j < nbVert; j++) {
      for(int k = 0; k < nbTimeStep; k++)
        vals[k] = v[j + k * nbVert];
      data.add(x[j], y[j], z[j], nbTimeStep, vals);
    }
  }
  delete [] vals;
}

static void smoothList(List_T *list, int nbList, double &min, double &max, 
		       std::vector<double> &tsmin, std::vector<double> &tsmax, 
		       int nbTimeStep, int nbVert, smooth_data &data)
{
  if(!nbList) return;
  double *vals = new double[nbTimeStep];
  int nb = List_Nbr(list)/nbList;
  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbVert);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbVert);
    double *v = (double *)List_Pointer_Fast(list, i + 3 * nbVert);
    for(int j = 0; j < nbVert; j++) {
      if(data.get(x[j], y[j], z[j], nbTimeStep, vals)){
	for(int k = 0; k < nbTimeStep; k++) {
	  double dd = vals[k];
          v[j + k * nbVert] = dd;
	  min = std::min(min, dd);
	  max = std::max(max, dd);
          tsmin[k] = std::min(tsmin[k], dd);
          tsmax[k] = std::max(tsmax[k], dd);
        }
      }
    }
  }
  delete [] vals;
}

void PViewDataList::smooth()
{
  double old_eps = xyzv::eps;
  xyzv::eps = CTX.lc * 1.e-8;
  
  if(NbSL || NbST || NbSQ || NbSS || NbSH || NbSI || NbSY) {
    Min = VAL_INF;
    Max = -VAL_INF;
    TimeStepMin.clear();
    TimeStepMax.clear();
    for(int j = 0; j < NbTimeStep; j++){
      TimeStepMin.push_back(VAL_INF);
      TimeStepMax.push_back(-VAL_INF);
    }
    smooth_data data;
    generateConnectivities(SL, NbSL, NbTimeStep, 2, data);
    generateConnectivities(ST, NbST, NbTimeStep, 3, data);
    generateConnectivities(SQ, NbSQ, NbTimeStep, 4, data);
    generateConnectivities(SS, NbSS, NbTimeStep, 4, data);
    generateConnectivities(SH, NbSH, NbTimeStep, 8, data);
    generateConnectivities(SI, NbSI, NbTimeStep, 6, data);
    generateConnectivities(SY, NbSY, NbTimeStep, 5, data);
    smoothList(SL, NbSL, Min, Max, TimeStepMin, TimeStepMax, NbTimeStep, 2, data);
    smoothList(ST, NbST, Min, Max, TimeStepMin, TimeStepMax, NbTimeStep, 3, data);
    smoothList(SQ, NbSQ, Min, Max, TimeStepMin, TimeStepMax, NbTimeStep, 4, data);
    smoothList(SS, NbSS, Min, Max, TimeStepMin, TimeStepMax, NbTimeStep, 4, data);
    smoothList(SH, NbSH, Min, Max, TimeStepMin, TimeStepMax, NbTimeStep, 8, data);
    smoothList(SI, NbSI, Min, Max, TimeStepMin, TimeStepMax, NbTimeStep, 6, data);
    smoothList(SY, NbSY, Min, Max, TimeStepMin, TimeStepMax, NbTimeStep, 5, data);
  }

  xyzv::eps = old_eps;  
}

bool PViewDataList::combineSpace(nameData &nd)
{
  // sanity checks
  if(nd.data.size() < 2) return false;
  int ts = nd.data[0]->getNumTimeSteps();
  for(unsigned int i = 1; i < nd.data.size(); i++) {
    if(nd.data[i]->getNumTimeSteps() != ts){
      Msg(GERROR, "Cannot combine views having different number of time steps");
      return false;
    }
  }

  for(unsigned int i = 0; i < nd.data.size(); i++) {
    PViewDataList *l = dynamic_cast<PViewDataList*>(nd.data[i]);
    if(!l){
      Msg(GERROR, "Cannot combine hybrid data");
      return false;
    }
    // merge elememts
    List_Merge(l->SP, SP); NbSP += l->NbSP; List_Merge(l->VP, VP); NbVP += l->NbVP;
    List_Merge(l->TP, TP); NbTP += l->NbTP; List_Merge(l->SL, SL); NbSL += l->NbSL;
    List_Merge(l->VL, VL); NbVL += l->NbVL; List_Merge(l->TL, TL); NbTL += l->NbTL;
    List_Merge(l->ST, ST); NbST += l->NbST; List_Merge(l->VT, VT); NbVT += l->NbVT;
    List_Merge(l->TT, TT); NbTT += l->NbTT; List_Merge(l->SQ, SQ); NbSQ += l->NbSQ;
    List_Merge(l->VQ, VQ); NbVQ += l->NbVQ; List_Merge(l->TQ, TQ); NbTQ += l->NbTQ;
    List_Merge(l->SS, SS); NbSS += l->NbSS; List_Merge(l->VS, VS); NbVS += l->NbVS;
    List_Merge(l->TS, TS); NbTS += l->NbTS; List_Merge(l->SH, SH); NbSH += l->NbSH;
    List_Merge(l->VH, VH); NbVH += l->NbVH; List_Merge(l->TH, TH); NbTH += l->NbTH;
    List_Merge(l->SI, SI); NbSI += l->NbSI; List_Merge(l->VI, VI); NbVI += l->NbVI;
    List_Merge(l->TI, TI); NbTI += l->NbTI; List_Merge(l->SY, SY); NbSY += l->NbSY;
    List_Merge(l->VY, VY); NbVY += l->NbVY; List_Merge(l->TY, TY); NbTY += l->NbTY;

    // merge strings
    for(int i = 0; i < List_Nbr(l->T2D); i += 4){
      List_Add(T2D, List_Pointer(l->T2D, i));
      List_Add(T2D, List_Pointer(l->T2D, i + 1));
      List_Add(T2D, List_Pointer(l->T2D, i + 2)); 
      double d = List_Nbr(T2C);
      List_Add(T2D, &d);
      double beg, end;
      List_Read(l->T2D, i + 3, &beg); 
      if(i > List_Nbr(l->T2D) - 8)
	end = (double)List_Nbr(l->T2C);
      else
	List_Read(l->T2D, i + 3 + 4, &end); 
      char *c = (char*)List_Pointer(l->T2C, (int)beg);
      for(int j = 0; j < (int)(end - beg); j++)
	List_Add(T2C, &c[j]); 
      NbT2++;
    }
    for(int i = 0; i < List_Nbr(l->T3D); i += 5){
      List_Add(T3D, List_Pointer(l->T3D, i));
      List_Add(T3D, List_Pointer(l->T3D, i + 1));
      List_Add(T3D, List_Pointer(l->T3D, i + 2)); 
      List_Add(T3D, List_Pointer(l->T3D, i + 3)); 
      double d = List_Nbr(T3C);
      List_Add(T3D, &d);
      double beg, end;
      List_Read(l->T3D, i + 4, &beg); 
      if(i > List_Nbr(l->T3D) - 10)
	end = (double)List_Nbr(l->T3C);
      else
	List_Read(l->T3D, i + 4 + 5, &end); 
      char *c = (char*)List_Pointer(l->T3C, (int)beg);
      for(int j = 0; j < (int)(end-beg); j++)
	List_Add(T3C, &c[j]); 
      NbT3++;
    }
  }
  
  std::string tmp;
  if(nd.name == "__all__")
    tmp = "all";
  else if(nd.name == "__vis__")
    tmp = "visible";
  else
    tmp = nd.name;
  char name[256];
  sprintf(name, "%s_Combine", tmp.c_str());

  setName(name);
  setFileName(std::string(name) + ".pos");
  return finalize();
}

void PViewDataList::getRawData(int type, List_T **l, int **ne, int *nc, int *nn)
{
  switch(type){
  case 0 : *l = SP; *ne = &NbSP; *nc = 1; *nn = 1; break;
  case 1 : *l = VP; *ne = &NbVP; *nc = 3; *nn = 1; break;
  case 2 : *l = TP; *ne = &NbTP; *nc = 9; *nn = 1; break;
  case 3 : *l = SL; *ne = &NbSL; *nc = 1; *nn = 2; break;
  case 4 : *l = VL; *ne = &NbVL; *nc = 3; *nn = 2; break;
  case 5 : *l = TL; *ne = &NbTL; *nc = 9; *nn = 2; break;
  case 6 : *l = ST; *ne = &NbST; *nc = 1; *nn = 3; break;
  case 7 : *l = VT; *ne = &NbVT; *nc = 3; *nn = 3; break;
  case 8 : *l = TT; *ne = &NbTT; *nc = 9; *nn = 3; break;
  case 9 : *l = SQ; *ne = &NbSQ; *nc = 1; *nn = 4; break;
  case 10: *l = VQ; *ne = &NbVQ; *nc = 3; *nn = 4; break;
  case 11: *l = TQ; *ne = &NbTQ; *nc = 9; *nn = 4; break;
  case 12: *l = SS; *ne = &NbSS; *nc = 1; *nn = 4; break;
  case 13: *l = VS; *ne = &NbVS; *nc = 3; *nn = 4; break;
  case 14: *l = TS; *ne = &NbTS; *nc = 9; *nn = 4; break;
  case 15: *l = SH; *ne = &NbSH; *nc = 1; *nn = 8; break;
  case 16: *l = VH; *ne = &NbVH; *nc = 3; *nn = 8; break;
  case 17: *l = TH; *ne = &NbTH; *nc = 9; *nn = 8; break;
  case 18: *l = SI; *ne = &NbSI; *nc = 1; *nn = 6; break;
  case 19: *l = VI; *ne = &NbVI; *nc = 3; *nn = 6; break;
  case 20: *l = TI; *ne = &NbTI; *nc = 9; *nn = 6; break;
  case 21: *l = SY; *ne = &NbSY; *nc = 1; *nn = 5; break;
  case 22: *l = VY; *ne = &NbVY; *nc = 3; *nn = 5; break;
  case 23: *l = TY; *ne = &NbTY; *nc = 9; *nn = 5; break;
  default: Msg(GERROR, "Wrong type in PViewDataList"); break;
  }
}

bool PViewDataList::combineTime(nameData &nd)
{
  // sanity checks
  if(nd.data.size() < 2) return false;
  std::vector<PViewDataList*> data(nd.data.size());
  for(unsigned int i = 0; i < nd.data.size(); i++){
    data[i] = dynamic_cast<PViewDataList*>(nd.data[i]);
    if(!data[i]){
      Msg(GERROR, "Cannot combine hybrid data");
      return false;
    }
  }

  int *nbe = 0, *nbe2 = 0, nbn, nbn2, nbc, nbc2;
  List_T *list = 0, *list2 = 0;
  
  // use the first data set as the reference
  for(int i = 0; i < 24; i++){
    getRawData(i, &list, &nbe, &nbc, &nbn);
    data[0]->getRawData(i, &list2, &nbe2, &nbc2, &nbn2);
    *nbe = *nbe2;
  }
  NbT2 = data[0]->NbT2;
  NbT3 = data[0]->NbT3;

  // merge values for all element types
  for(int i = 0; i < 24; i++){
    getRawData(i, &list, &nbe, &nbc, &nbn);
    for(int j = 0; j < *nbe; j++){
      for(unsigned int k = 0; k < data.size(); k++){
	data[k]->getRawData(i, &list2, &nbe2, &nbc2, &nbn2);
	if(*nbe && *nbe == *nbe2){
	  int nb2 = List_Nbr(list2) / *nbe2;
	  if(!k){ 
	    // copy coordinates of elm j (we are always here as
	    // expected, since the ref view is the first one)
	    for(int l = 0; l < 3 * nbn2; l++)
	      List_Add(list, List_Pointer(list2, j * nb2 + l));
	  }
	  // copy values of elm j
	  for(int l = 0; l < data[k]->getNumTimeSteps() * nbc2 * nbn2; l++)
	    List_Add(list, List_Pointer(list2, j * nb2 + 3 * nbn2 + l));
	}
      }
    }
  }

  // merge 2d strings
  for(int j = 0; j < NbT2; j++){
    for(unsigned int k = 0; k < data.size(); k++){
      if(NbT2 == data[k]->NbT2){
	if(!k){
	  // copy coordinates 
	  List_Add(T2D, List_Pointer(data[k]->T2D, j * 4));
	  List_Add(T2D, List_Pointer(data[k]->T2D, j * 4 + 1));
	  List_Add(T2D, List_Pointer(data[k]->T2D, j * 4 + 2));
	  // index
	  double d = List_Nbr(T2C);
	  List_Add(T2D, &d);
	}
	// copy char values
	double beg, end;
	List_Read(data[k]->T2D, j * 4 + 3, &beg);
	if(j == NbT2 - 1)
	  end = (double)List_Nbr(data[k]->T2C);
	else
	  List_Read(data[k]->T2D, j * 4 + 4 + 3, &end);
	char *c = (char*)List_Pointer(data[k]->T2C, (int)beg);
	for(int l = 0; l < (int)(end - beg); l++)
	  List_Add(T2C, &c[l]);
      }
    }
  }

  // merge 3d strings
  for(int j = 0; j < NbT3; j++){
    for(unsigned int k = 0; k < data.size(); k++){
      if(NbT3 == data[k]->NbT3){
	if(!k){
	  // copy coordinates 
	  List_Add(T3D, List_Pointer(data[k]->T3D, j * 5));
	  List_Add(T3D, List_Pointer(data[k]->T3D, j * 5 + 1));
	  List_Add(T3D, List_Pointer(data[k]->T3D, j * 5 + 2));
	  List_Add(T3D, List_Pointer(data[k]->T3D, j * 5 + 3));
	  // index
	  double d = List_Nbr(T3C);
	  List_Add(T3D, &d);
	}
	// copy char values
	double beg, end;
	List_Read(data[k]->T3D, j * 5 + 4, &beg);
	if(j == NbT3 - 1)
	  end = (double)List_Nbr(data[k]->T3C);
	else
	  List_Read(data[k]->T3D, j * 5 + 5 + 4, &end);
	char *c = (char*)List_Pointer(data[k]->T3C, (int)beg);
	for(int l = 0; l < (int)(end - beg); l++)
	  List_Add(T3C, &c[l]);
      }
    }
  }

  // create the time data
  for(unsigned int i = 0; i < data.size(); i++)
    List_Merge(data[i]->Time, Time);
  
  // if all the time values are the same, it probably means that the
  // original views didn't have any time data: then we'll just use
  // time step values
  if(List_Nbr(Time)){
    double t0, ti;
    List_Read(Time, 0, &t0);
    bool allTheSame = true;
    for(int i = 1; i < List_Nbr(Time); i++){
      List_Read(Time, i, &ti);
      if(ti != t0){
	allTheSame = false;
	break;
      }
    }
    if(allTheSame) List_Reset(Time);
  }

  std::string tmp;
  if(nd.name == "__all__")
    tmp = "all";
  else if(nd.name == "__vis__")
    tmp = "visible";
  else
    tmp = nd.name;
  char name[256];
  sprintf(name, "%s_Combine", tmp.c_str());

  setName(name);
  setFileName(std::string(name) + ".pos");
  return finalize();
}

