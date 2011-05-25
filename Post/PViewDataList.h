
// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PVIEW_DATA_LIST_H_
#define _PVIEW_DATA_LIST_H_

#include <vector>
#include <string>
#include "PViewData.h"
#include "SBoundingBox3d.h"

// The container for list-based datasets (for which all elements are
// discontinuous).
class PViewDataList : public PViewData {
 public: 
  // FIXME: all these members will be made private once the plugins
  // have been rewritten
  int NbTimeStep;
  double Min, Max;
  std::vector<double> TimeStepMin, TimeStepMax;
  SBoundingBox3d BBox;
  std::vector<double> Time;
  int NbSP, NbVP, NbTP;
  std::vector<double> SP, VP, TP; // points
  int NbSL, NbVL, NbTL;
  std::vector<double> SL, VL, TL; // lines
  int NbST, NbVT, NbTT;
  std::vector<double> ST, VT, TT; // triangles
  int NbSQ, NbVQ, NbTQ;
  std::vector<double> SQ, VQ, TQ; // quadrangles
  int NbSS, NbVS, NbTS;
  std::vector<double> SS, VS, TS; // tetrahedra
  int NbSH, NbVH, NbTH;
  std::vector<double> SH, VH, TH; // hexahedra
  int NbSI, NbVI, NbTI;
  std::vector<double> SI, VI, TI; // prisms
  int NbSY, NbVY, NbTY;
  std::vector<double> SY, VY, TY; // pyramids
  int NbT2, NbT3;
  std::vector<double> T2D, T3D; // 2D and 3D text strings
  std::vector<char> T2C, T3C; 
 private:
  int _index[24];
  int _lastElement, _lastDimension;
  int _lastNumNodes, _lastNumComponents, _lastNumValues, _lastNumEdges, _lastType;
  double *_lastXYZ, *_lastVal;
  void _stat(std::vector<double> &D, std::vector<char> &C, int nb);
  void _stat(std::vector<double> &list, int nbcomp, int nbelm, int nbnod, int type);
  void _setLast(int ele);
  void _setLast(int ele, int dim, int nbnod, int nbcomp, int nbedg, int type,
                std::vector<double> &list, int nblist);
  void _getString(int dim, int i, int timestep, std::string &str, 
                  double &x, double &y, double &z, double &style);
  int _getRawData(int idxtype, std::vector<double> **l, int **ne, int *nc, int *nn);
 public:
  PViewDataList();
  ~PViewDataList(){}
  bool finalize(bool computeMinMax=true, const std::string &interpolationScheme="");
  int getNumTimeSteps(){ return NbTimeStep; }
  double getTime(int step);
  double getMin(int step=-1, bool onlyVisible=false);
  double getMax(int step=-1, bool onlyVisible=false);
  void setMin(double min) {Min = min;}
  void setMax(double max) {Max = max;}
  SBoundingBox3d getBoundingBox(int step=-1){ return BBox; }
  void setBoundingBox(SBoundingBox3d& box) {BBox = box;}
  int getNumScalars(int step=-1);
  int getNumVectors(int step=-1);
  int getNumTensors(int step=-1);
  int getNumPoints(int step=-1){ return NbSP + NbVP + NbTP; }
  int getNumLines(int step=-1){ return NbSL + NbVL + NbTL; }
  int getNumTriangles(int step=-1){ return NbST + NbVT + NbTT; }
  int getNumQuadrangles(int step=-1){ return NbSQ + NbVQ + NbTQ; }
  int getNumTetrahedra(int step=-1){ return NbSS + NbVS + NbTS; }
  int getNumHexahedra(int step=-1){ return NbSH + NbVH + NbTH; }
  int getNumPrisms(int step=-1){ return NbSI + NbVI + NbTI; }
  int getNumPyramids(int step=-1){ return NbSY + NbVY + NbTY; }
  int getNumEntities(int step=-1){ return 1; }
  int getNumElements(int step=-1, int ent=-1);
  int getDimension(int step, int ent, int ele);
  int getNumNodes(int step, int ent, int ele);
  int getNode(int step, int ent, int ele, int nod, double &x, double &y, double &z);
  void setNode(int step, int ent, int ele, int nod, double x, double y, double z);
  int getNumComponents(int step, int ent, int ele);
  int getNumValues(int step, int ent, int ele);
  void getValue(int step, int ent, int ele, int idx, double &val);
  void getValue(int step, int ent, int ele, int nod, int comp, double &val);
  void setValue(int step, int ent, int ele, int nod, int comp, double val);
  int getNumEdges(int step, int ent, int ele);
  int getType(int step, int ent, int ele);
  int getNumStrings2D(){ return NbT2; }
  int getNumStrings3D(){ return NbT3; }
  void getString2D(int i, int step, std::string &str, 
                   double &x, double &y, double &style);
  void getString3D(int i, int step, std::string &str, 
                   double &x, double &y, double &z, double &style);
  void revertElement(int step, int ent, int ele);
  void smooth();
  bool combineTime(nameData &nd);
  bool combineSpace(nameData &nd);

  // specific to list-based data sets
  void setOrder2(int type);
  std::vector<double> *incrementList(int numComp, int type);

  // I/O routines
  bool readPOS(FILE *fp, double version, bool binary);
  bool writePOS(std::string fileName, bool binary=false, bool parsed=true,
                bool append=false);
  virtual bool writeMSH(std::string fileName, bool binary=false, bool savemesh=true);
};

#endif
