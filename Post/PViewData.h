#ifndef _PVIEW_DATA_H_
#define _PVIEW_DATA_H_

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

#include <map>
#include <vector>
#include <string>
#include "GModel.h"
#include "SBoundingBox3d.h"
#include "List.h"

#define VAL_INF 1.e200

// abstract interface to post-processing view data
class PViewData {
 private:
  // flag to mark that the data is 'dirty' and should not be displayed
  bool _dirty;
 public:
  PViewData() : _dirty(true) {}
  virtual ~PViewData(){}
  virtual bool getDirty(){ return _dirty; }
  virtual void setDirty(bool val){ _dirty = val; }
  virtual void finalize(){}
  virtual int getNumTimeSteps() = 0;
  virtual double getMin(int step=-1) = 0;
  virtual double getMax(int step=-1) = 0;
  virtual SBoundingBox3d getBoundingBox() = 0;
  virtual int getNumScalars(){ return 0; }
  virtual int getNumVectors(){ return 0; }
  virtual int getNumTensors(){ return 0; }
  virtual int getNumPoints(){ return 0; }
  virtual int getNumLines(){ return 0; }
  virtual int getNumTriangles(){ return 0; }
  virtual int getNumQuadrangles(){ return 0; }
  virtual int getNumTetrahedra(){ return 0; }
  virtual int getNumHexahedra(){ return 0; }
  virtual int getNumPrisms(){ return 0; }
  virtual int getNumPyramids(){ return 0; }
  virtual int getNumElements() = 0;
  virtual int getDimension(int ele) = 0;
  virtual int getEntity(int ele){ return 0; }
  virtual int getNumNodes(int ele) = 0;
  virtual void getNode(int ele, int nod, double &x, double &y, double &z) = 0;
  virtual int getNumComponents(int ele) = 0;
  virtual void getValue(int ele, int node, int comp, int step, double &val) = 0;
  virtual int getNumEdges(int ele) = 0;
  virtual bool read(std::string filename){}
};

// data container using old-style lists of `discontinuous' element
class PViewDataList : public PViewData {
 public: 
  // FIXME: all these members will be made private once the plugins
  // have been rewritten
  int DataSize; // size(double) or sizeof(float)
  int NbTimeStep;
  double Min, Max;
  std::vector<double> TimeStepMin, TimeStepMax;
  SBoundingBox3d BBox;
  List_T *Time;
  int NbSP, NbVP, NbTP;
  List_T *SP, *VP, *TP; // points
  int NbSL, NbVL, NbTL, NbSL2, NbVL2, NbTL2;
  List_T *SL, *VL, *TL, *SL2, *VL2, *TL2; // lines
  int NbST, NbVT, NbTT, NbST2, NbVT2, NbTT2;
  List_T *ST, *VT, *TT, *ST2, *VT2, *TT2; // triangles
  int NbSQ, NbVQ, NbTQ, NbSQ2, NbVQ2, NbTQ2;
  List_T *SQ, *VQ, *TQ, *SQ2, *VQ2, *TQ2; // quadrangles
  int NbSS, NbVS, NbTS, NbSS2, NbVS2, NbTS2;
  List_T *SS, *VS, *TS, *SS2, *VS2, *TS2; // tetrahedra
  int NbSH, NbVH, NbTH, NbSH2, NbVH2, NbTH2;
  List_T *SH, *VH, *TH, *SH2, *VH2, *TH2; // hexahedra
  int NbSI, NbVI, NbTI, NbSI2, NbVI2, NbTI2;
  List_T *SI, *VI, *TI, *SI2, *VI2, *TI2; // prisms
  int NbSY, NbVY, NbTY, NbSY2, NbVY2, NbTY2;
  List_T *SY, *VY, *TY, *SY2, *VY2, *TY2; // pyramids
  int NbT2, NbT3;
  List_T *T2D, *T2C, *T3D, *T3C; // 2D and 3D text strings
  std::map<int, List_T*> *Grains; // For LMGC90, grains shapes
  std::map<int, int> *DisplayListsOfGrains; // For LMGC90, grains shapes
 private:
  int _index[24];
  int _lastElement, _lastDimension;
  int _lastNumNodes, _lastNumComponents, _lastNumEdges;
  double *_lastXYZ, *_lastVal;
  void _stat(List_T *D, List_T *C, int nb);
  void _stat(List_T *list, int nbcomp, int nbelm, int nbnod);
  void _setLast(int ele);
  void _setLast(int ele, int dim, int nbnod, int nbcomp, int nbedg,
		List_T *list, int nblist);
 public:
  PViewDataList(bool allocate=true);
  ~PViewDataList();
  void finalize();
  int getNumTimeSteps(){ return NbTimeStep; }
  double getMin(int step=-1);
  double getMax(int step=-1);
  SBoundingBox3d getBoundingBox(){ return BBox; }
  int getNumScalars(){ return NbSP + NbSL + NbST + NbSQ + NbSS + NbSH + NbSI + NbSY; }
  int getNumVectors(){ return NbVP + NbVL + NbVT + NbVQ + NbVS + NbVH + NbVI + NbVY; }
  int getNumTensors(){ return NbTP + NbTL + NbTT + NbTQ + NbTS + NbTH + NbTI + NbTY; }
  int getNumPoints(){ return NbSP + NbVP + NbTP; }
  int getNumLines(){ return NbSL + NbVL + NbTL; }
  int getNumTriangles(){ return NbST + NbVT + NbTT; }
  int getNumQuadrangles(){ return NbSQ + NbVQ + NbTQ; }
  int getNumTetrahedra(){ return NbSS + NbVS + NbTS; }
  int getNumHexahedra(){ return NbSH + NbVH + NbTH; }
  int getNumPrisms(){ return NbSI + NbVI + NbTI; }
  int getNumPyramids(){ return NbSY + NbVY + NbTY; }
  int getNumElements()
  {
    return getNumPoints() + getNumLines() + getNumTriangles() + 
      getNumQuadrangles() + getNumTetrahedra() + getNumHexahedra() + 
      getNumPrisms() + getNumPyramids();
  }
  int getDimension(int ele);
  int getNumNodes(int ele);
  void getNode(int ele, int nod, double &x, double &y, double &z);
  int getNumComponents(int ele);
  void getValue(int ele, int node, int comp, int step, double &val);
  int getNumEdges(int ele);
  bool read(std::string filename);
};

// data container using elements from a GModel
class PViewDataGModel : public PViewData {
 private:
  GModel *_model;
  PViewDataList *_cloneToList(); // create old-style data from this
 public:
  PViewDataGModel(){}
  ~PViewDataGModel(){}
  int getNumTimeSteps(){ return 1; }
  double getMin(int step=-1){ return 0.; }
  double getMax(int step=-1){ return 1.; }
  SBoundingBox3d getBoundingBox(){ return SBoundingBox3d(); }
  int getNumElements(){ return _model->numElements(); }
  int getDimension(int ele){ return 0; }
  int getNumNodes(int ele){ return 0; }
  void getNode(int ele, int nod, double &x, double &y, double &z){}
  int getNumComponents(int ele){ return 1; }
  void getValue(int ele, int node, int comp, int step, double &val){}
  int getNumEdges(int ele){ return 0; }
};

#endif
