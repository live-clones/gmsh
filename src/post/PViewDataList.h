
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
private:
  int _nbTimeStep;
  double _min, _max;
  std::vector<double> _timeStepMin, _timeStepMax;
  SBoundingBox3d _bbox;
  std::vector<double> _time;
  int _nbSP, _nbVP, _nbTP;
  std::vector<double> _sp, _vp, _tp; // points
  int _nbSL, _nbVL, _nbTL;
  std::vector<double> _sl, _vl, _tl; // lines
  int _nbST, _nbVT, _nbTT;
  std::vector<double> _st, _vt, _tt; // triangles
  int _nbSQ, _nbVQ, _nbTQ;
  std::vector<double> _sq, _vq, _tq; // quadrangles
  int _nbSS, _nbVS, _nbTS;
  std::vector<double> _ss, _vs, _ts; // tetrahedra
  int _nbSH, _nbVH, _nbTH;
  std::vector<double> _sh, _vh, _th; // hexahedra
  int _nbSI, _nbVI, _nbTI;
  std::vector<double> _si, _vi, _ti; // prisms
  int _nbSY, _nbVY, _nbTY;
  std::vector<double> _sy, _vy, _ty; // pyramids
  int _nbSR, _nbVR, _nbTR;
  std::vector<double> _sr, _vr, _tr; // trihedra
  int _nbT2, _nbT3;
  std::vector<double> _t2d, _t3d; // 2D and 3D text strings
  std::vector<char> _t2c, _t3c;

public:
  // the kinds of lists: points, lines, triangles, quadrangles, tetrahedra,
  // hexahedra, prisms, pyramids and trihedra, each with 1, 3 and 9 components,
  // in this order (that of the files, which have no trihedra)
  struct listKind {
    const char *name;
    int type, dim, numNodes, numEdges, numComp;
    std::vector<double> PViewDataList::*list;
    int PViewDataList::*num;
  };
  static const listKind listKinds[27];

private:
  // the number of elements in the lists up to each one, included
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
  static const listKind *_kind(int numComp, int type);

  // What was last read of an element, kept by each thread: the element, the
  // state of the lists it was read in (a number no other state of any list-
  // based view has: it changes when they are finalized), and where its data
  // is in them. Several threads can then read the view at the same time, and
  // a few views in turn (as plugins reading several views value by value) keep
  // an entry each.
  struct lastElement {
    std::size_t state = 0;
    int ele = -1, dim = 0, numNodes = 0, numComponents = 0, numValues = 0,
        numEdges = 0, type = 0;
    double *xyz = nullptr, *val = nullptr;
  };
  std::size_t _state;
  static thread_local lastElement _lastRead[4];
  lastElement &_last(int ele)
  {
    lastElement &l = _lastRead[_state & 3];
    if(l.state != _state || l.ele != ele) _setLast(l, ele);
    return l;
  }
  // made by an adaptive view (see adaptiveData): its elements are the refined
  // ones, searched as they are (see OctreePost)
  bool _isAdapted;
  // set while smooth() finalizes the view, as finalize() smooths it when
  // PostProcessing.Smoothing is set
  bool _smoothing;
  // the index of the point each point (x, y, z in sequence) is merged with
  static std::vector<std::size_t> _mergePoints(const std::vector<double> &xyz,
                                               double eps, std::size_t &num);
  void _stat(std::vector<double> &D, std::vector<char> &C, int nb);
  // the characters of the string whose record (of nb values: 4 for the 2D
  // strings, 5 for the 3D ones) starts at D[i] are C[beg, end)
  static void _stringSpan(const std::vector<double> &D,
                          const std::vector<char> &C, std::size_t i, int nb,
                          std::size_t &beg, std::size_t &end)
  {
    beg = (std::size_t)D[i + nb - 1];
    end = (i + 2 * nb <= D.size()) ? (std::size_t)D[i + 2 * nb - 1] : C.size();
  }
  void _stat(std::vector<double> &list, int nbcomp, int nbelm, int nbnod,
             int type);
  void _setLast(lastElement &l, int ele);
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
  int getNumTimeSteps() { return _nbTimeStep; }
  double getTime(int step);
  double getMin(int step = -1, bool onlyVisible = false, int tensorRep = 0,
                int forceNumComponents = 0, int componentMap[9] = nullptr);
  double getMax(int step = -1, bool onlyVisible = false, int tensorRep = 0,
                int forceNumComponents = 0, int componentMap[9] = nullptr);
  void setMin(double min) { _min = min; }
  void setMax(double max) { _max = max; }
  SBoundingBox3d getBoundingBox(int step = -1) { return _bbox; }
  void setBoundingBox(SBoundingBox3d &box) { _bbox = box; }
  int getNumScalars(int step = -1);
  int getNumVectors(int step = -1);
  int getNumTensors(int step = -1);
  int getNumPoints(int step = -1) { return _nbSP + _nbVP + _nbTP; }
  int getNumLines(int step = -1) { return _nbSL + _nbVL + _nbTL; }
  int getNumTriangles(int step = -1) { return _nbST + _nbVT + _nbTT; }
  int getNumQuadrangles(int step = -1) { return _nbSQ + _nbVQ + _nbTQ; }
  int getNumTetrahedra(int step = -1) { return _nbSS + _nbVS + _nbTS; }
  int getNumHexahedra(int step = -1) { return _nbSH + _nbVH + _nbTH; }
  int getNumPrisms(int step = -1) { return _nbSI + _nbVI + _nbTI; }
  int getNumPyramids(int step = -1) { return _nbSY + _nbVY + _nbTY; }
  int getNumTrihedra(int step = -1) { return _nbSR + _nbVR + _nbTR; }
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
  int getNumStrings2D() { return _nbT2; }
  int getNumStrings3D() { return _nbT3; }
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
  // the list of the elements of a type with numComp components, their number
  // incremented: the caller appends the element to it (coordinates, then
  // values). Null for a kind the lists cannot hold
  std::vector<double> *incrementList(int numComp, int type, int numNodes = 0);
  // numElements elements appended at once
  void appendList(int numComp, int type, int numElements,
                  const std::vector<double> &values);
  void addTime(double time) { _time.push_back(time); }
  const std::vector<double> &getTimes() const { return _time; }
  void setTimes(const std::vector<double> &times) { _time = times; }
  // a string at (x, y) in the window or at (x, y, z) in the model, with one
  // value per time step
  void addString2D(double x, double y, double style,
                   const std::vector<std::string> &values);
  void addString3D(double x, double y, double z, double style,
                   const std::vector<std::string> &values);
  // remove the elements of a type with numComp components, or the strings of
  // dimension dim
  void clearList(int numComp, int type);
  void clearStrings(int dim);

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
  // write several views in an MSH file, on a single mesh of their elements
  static bool writeMSH(const std::string &fileName,
                       const std::vector<PViewDataList *> &views,
                       double version, bool binary, bool saveMesh,
                       bool multipleView, int partitionNum,
                       bool saveInterpolationMatrices, bool forceNodeData,
                       bool forceElementData);
  virtual void importLists(int N[24], std::vector<double> *V[24]);
  virtual void getListPointers(int N[24], std::vector<double> *V[24]);
  void importList(int index, int n, const std::vector<double> &v,
                  bool finalize);
};

#endif
