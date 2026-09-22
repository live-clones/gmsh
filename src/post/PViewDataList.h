
// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PVIEW_DATA_LIST_H
#define PVIEW_DATA_LIST_H

#include <vector>
#include <atomic>
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
  int NbSR, NbVR, NbTR;
  std::vector<double> SR, VR, TR; // trihedra
  int NbT2, NbT3;
  std::vector<double> T2D, T3D; // 2D and 3D text strings
  std::vector<char> T2C, T3C;

private:
  int _index[27];
  // list-based data has no topology: node identifiers are recreated once, by
  // merging the nodes that have the same coordinates, and cached here. _nodeId
  // is indexed by _nodeOffset[element] + node
  std::vector<unsigned int> _nodeId, _nodeOffset;
  std::atomic<int> _nodeIndexStatus; // 0: not built, 1: built, -1: none
  // see getSkinMasks(): given by the adaptive views, which know where the
  // refined elements come from
  std::vector<unsigned char> _skinMasks;
  void _buildNodeIndex();

  // What was last read of an element, kept by each thread: the element, the
  // state of the lists it was read in (a number no other state of any list-
  // based view has: it changes when they are finalized), and where its data
  // is in them. Several threads can then read the view at the same time.
  struct lastElement {
    std::size_t state = 0;
    int ele = -1, dim = 0, numNodes = 0, numComponents = 0, numValues = 0,
        numEdges = 0, type = 0;
    double *xyz = nullptr, *val = nullptr;
  };
  std::size_t _state;
  static thread_local lastElement _lastRead;
  lastElement &_last(int ele)
  {
    if(_lastRead.state != _state || _lastRead.ele != ele) _setLast(_lastRead, ele);
    return _lastRead;
  }
  bool _isAdapted;
  void _stat(std::vector<double> &D, std::vector<char> &C, int nb);
  void _stat(std::vector<double> &list, int nbcomp, int nbelm, int nbnod,
             int type);
  void _setLast(lastElement &l, int ele);
  void _setLast(lastElement &l, int i, int dim, int nbnod, int nbcomp,
                int nbedg, int type, std::vector<double> &list, int nblist);
  void _getString(int dim, int i, int timestep, std::string &str, double &x,
                  double &y, double &z, double &style);
  int _getRawData(int idxtype, std::vector<double> **l, int **ne, int *nc,
                  int *nn);

public:
  PViewDataList(bool isAdapted = false);
  ~PViewDataList() {}
  bool isAdapted() { return _isAdapted; }
  bool finalize(bool computeMinMax = true,
                const std::string &interpolationScheme = "");
  int getNumTimeSteps() { return NbTimeStep; }
  double getTime(int step);
  double getMin(int step = -1, bool onlyVisible = false, int tensorRep = 0,
                int forceNumComponents = 0, int componentMap[9] = nullptr);
  double getMax(int step = -1, bool onlyVisible = false, int tensorRep = 0,
                int forceNumComponents = 0, int componentMap[9] = nullptr);
  void setMin(double min) { Min = min; }
  void setMax(double max) { Max = max; }
  SBoundingBox3d getBoundingBox(int step = -1) { return BBox; }
  void setBoundingBox(SBoundingBox3d &box) { BBox = box; }
  int getNumScalars(int step = -1);
  int getNumVectors(int step = -1);
  int getNumTensors(int step = -1);
  int getNumPoints(int step = -1) { return NbSP + NbVP + NbTP; }
  int getNumLines(int step = -1) { return NbSL + NbVL + NbTL; }
  int getNumTriangles(int step = -1) { return NbST + NbVT + NbTT; }
  int getNumQuadrangles(int step = -1) { return NbSQ + NbVQ + NbTQ; }
  int getNumTetrahedra(int step = -1) { return NbSS + NbVS + NbTS; }
  int getNumHexahedra(int step = -1) { return NbSH + NbVH + NbTH; }
  int getNumPrisms(int step = -1) { return NbSI + NbVI + NbTI; }
  int getNumPyramids(int step = -1) { return NbSY + NbVY + NbTY; }
  int getNumTrihedra(int step = -1) { return NbSR + NbVR + NbTR; }
  int getNumEntities(int step = -1) { return 1; }
  int getNumElements(int step = -1, int ent = -1);
  int getDimension(int step, int ent, int ele);
  int getNumNodes(int step, int ent, int ele);
  int getNode(int step, int ent, int ele, int nod, double &x, double &y,
              double &z);
  void getElementInfo(int step, int ent, int ele, int &type, int &dim,
                      int &numNodes, int &numComp)
  {
    lastElement &l = _last(ele);
    type = l.type;
    dim = l.dim;
    numNodes = l.numNodes;
    numComp = l.numComponents;
  }
  void getNodesAndValues(int step, int ent, int ele, int numNodes, int numComp,
                         double **xyz, double **val);
  // (several threads can read the data at the same time, see _last())
  bool isThreadSafe() { return true; }
  std::size_t getNodeId(int step, int ent, int ele, int nod);
  const std::vector<unsigned char> *getSkinMasks()
  {
    return _skinMasks.empty() ? nullptr : &_skinMasks;
  }
  void setSkinMasks(const std::vector<unsigned char> &masks)
  {
    _skinMasks = masks;
  }
  void setNode(int step, int ent, int ele, int nod, double x, double y,
               double z);
  int getNumComponents(int step, int ent, int ele);
  int getNumValues(int step, int ent, int ele);
  void getValue(int step, int ent, int ele, int idx, double &val);
  void getValue(int step, int ent, int ele, int nod, int comp, double &val);
  void setValue(int step, int ent, int ele, int nod, int comp, double val);
  int getNumEdges(int step, int ent, int ele);
  int getType(int step, int ent, int ele);
  int getNumStrings2D() { return NbT2; }
  int getNumStrings3D() { return NbT3; }
  void getString2D(int i, int step, std::string &str, double &x, double &y,
                   double &style);
  void getString3D(int i, int step, std::string &str, double &x, double &y,
                   double &z, double &style);
  void reverseElement(int step, int ent, int ele);
  void smooth();
  bool combineTime(nameData &nd);
  bool combineSpace(nameData &nd);
  void setXY(std::vector<double> &x, std::vector<double> &y);
  void setXYZV(std::vector<double> &x, std::vector<double> &y,
               std::vector<double> &z, std::vector<double> &v);
  void addStep(std::vector<double> &y);
  bool isListBased() { return true; }
  double getMemoryInMB();

  // specific to list-based data sets
  void setOrder2(int type);
  std::vector<double> *incrementList(int numComp, int type, int numNodes = 0);

  // I/O routines
  bool readPOS(FILE *fp, double version, bool binary);
  bool writePOS(const std::string &fileName, bool binary = false,
                bool parsed = true, bool append = false);
  virtual bool writeMSH(const std::string &fileName, double version = 2.2,
                        bool binary = false, bool savemesh = true,
                        bool multipleView = false, int partitionNum = -1,
                        bool saveInterpolationMatrices = true,
                        bool forceNodeData = false,
                        bool forceElementData = false);
  virtual void importLists(int N[24], std::vector<double> *V[24]);
  virtual void getListPointers(int N[24], std::vector<double> *V[24]);
  void importList(int index, int n, const std::vector<double> &v,
                  bool finalize);
};

#endif
