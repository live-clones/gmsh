// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ADAPTIVE_DATA_H
#define ADAPTIVE_DATA_H

#include <list>
#include <set>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sys/stat.h>
#include <assert.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "fullMatrix.h"

#if defined(WIN32)
typedef unsigned __int8 uint8_t; // Valid for _MSC_VER >= 1300
typedef unsigned __int64 uint64_t;
#define PRIu8 "u"
#define PRIu64 "I64u"
#else
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#endif

typedef std::vector<int> vectInt;

class PViewData;
class PViewDataList;
class GMSH_PostPlugin;

// For old compilers that do not support yet std::to_string()
template <class T> std::string ToString(const T &val)
{
  std::stringstream stream;
  stream << val;
  return stream.str();
}

class adaptiveVertex {
public:
  float x, y, z; //!< parametric coordinates
  double X, Y, Z; //!< cartesian coordinates
  double val, valy, valz; //!< maximal three values
  double valyx, valyy, valyz;
  double valzx, valzy, valzz;

public:
  static adaptiveVertex *add(double x, double y, double z,
                             std::set<adaptiveVertex> &allVertice);
  bool operator<(const adaptiveVertex &other) const
  {
    if(other.x < x) return true;
    if(other.x > x) return false;
    if(other.y < y) return true;
    if(other.y > y) return false;
    if(other.z < z) return true;
    return false;
  }
};

template <class T> class nodMap {
public:
  std::vector<int> mapping;

public:
  void cleanMapping() { mapping.clear(); }
  ~nodMap() { cleanMapping(); }
  int getSize() { return (int)mapping.size(); }
};

class adaptivePoint {
public:
  bool visible;
  adaptiveVertex *p[1];
  adaptivePoint *e[1];
  static std::list<adaptivePoint *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptivePoint(adaptiveVertex *p1) : visible(false)
  {
    p[0] = p1;
    e[0] = nullptr;
  }
  inline double V() const { return p[0]->val; }
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    sf(0) = 1;
  }
  static void create(int maxlevel);
  static void recurCreate(adaptivePoint *e, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptivePoint *e, double AVG, double tol);
};

class adaptiveLine {
public:
  bool visible;
  adaptiveVertex *p[2];
  adaptiveLine *e[2];
  static std::list<adaptiveLine *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptiveLine(adaptiveVertex *p1, adaptiveVertex *p2) : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    e[0] = e[1] = nullptr;
  }
  inline double V() const { return (p[0]->val + p[1]->val) / 2.; }
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    sf(0) = (1 - u) / 2.;
    sf(1) = (1 + u) / 2.;
  }
  static void create(int maxlevel);
  static void recurCreate(adaptiveLine *e, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptiveLine *e, double AVG, double tol);
};

class adaptiveTriangle {
public:
  bool visible;
  adaptiveVertex *p[3];
  adaptiveTriangle *e[4];
  static std::list<adaptiveTriangle *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptiveTriangle(adaptiveVertex *p1, adaptiveVertex *p2, adaptiveVertex *p3)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    e[0] = e[1] = e[2] = e[3] = nullptr;
  }
  inline double V() const { return (p[0]->val + p[1]->val + p[2]->val) / 3.; }
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    sf(0) = 1. - u - v;
    sf(1) = u;
    sf(2) = v;
  }
  static void create(int maxlevel);
  static void recurCreate(adaptiveTriangle *t, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptiveTriangle *t, double AVG, double tol);
};

class adaptiveQuadrangle {
public:
  bool visible;
  adaptiveVertex *p[4];
  adaptiveQuadrangle *e[4];
  static std::list<adaptiveQuadrangle *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptiveQuadrangle(adaptiveVertex *p1, adaptiveVertex *p2, adaptiveVertex *p3,
                     adaptiveVertex *p4)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    e[0] = e[1] = e[2] = e[3] = nullptr;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val) / 4.;
  }
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    sf(0) = 0.25 * (1. - u) * (1. - v);
    sf(1) = 0.25 * (1. + u) * (1. - v);
    sf(2) = 0.25 * (1. + u) * (1. + v);
    sf(3) = 0.25 * (1. - u) * (1. + v);
  }
  static void create(int maxlevel);
  static void recurCreate(adaptiveQuadrangle *q, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptiveQuadrangle *q, double AVG, double tol);
};

class adaptivePrism {
public:
  bool visible;
  adaptiveVertex *p[6];
  adaptivePrism *e[8];
  static std::list<adaptivePrism *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptivePrism(adaptiveVertex *p1, adaptiveVertex *p2, adaptiveVertex *p3,
                adaptiveVertex *p4, adaptiveVertex *p5, adaptiveVertex *p6)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    p[5] = p6;
    e[0] = e[1] = e[2] = e[3] = nullptr;
    e[4] = e[5] = e[6] = e[7] = nullptr;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val + p[4]->val +
            p[5]->val) /
           6.;
  }
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    sf(0) = (1. - u - v) * (1 - w) / 2;
    sf(1) = u * (1 - w) / 2;
    sf(2) = v * (1 - w) / 2;
    sf(3) = (1. - u - v) * (1 + w) / 2;
    sf(4) = u * (1 + w) / 2;
    sf(5) = v * (1 + w) / 2;
  }
  static void create(int maxlevel);
  static void recurCreate(adaptivePrism *p, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptivePrism *p, double AVG, double tol);
};

class adaptiveTetrahedron {
public:
  bool visible;
  adaptiveVertex *p[4];
  adaptiveTetrahedron *e[8];
  static std::list<adaptiveTetrahedron *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptiveTetrahedron(adaptiveVertex *p1, adaptiveVertex *p2,
                      adaptiveVertex *p3, adaptiveVertex *p4)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    e[0] = e[1] = e[2] = e[3] = nullptr;
    e[4] = e[5] = e[6] = e[7] = nullptr;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val) / 4.;
  }
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    sf(0) = 1. - u - v - w;
    sf(1) = u;
    sf(2) = v;
    sf(3) = w;
  }
  static void create(int maxlevel);
  static void recurCreate(adaptiveTetrahedron *t, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptiveTetrahedron *t, double AVG, double tol);
};

class adaptiveHexahedron {
public:
  bool visible;
  adaptiveVertex *p[8];
  adaptiveHexahedron *e[8];
  static std::list<adaptiveHexahedron *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptiveHexahedron(adaptiveVertex *p1, adaptiveVertex *p2, adaptiveVertex *p3,
                     adaptiveVertex *p4, adaptiveVertex *p5, adaptiveVertex *p6,
                     adaptiveVertex *p7, adaptiveVertex *p8)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    p[5] = p6;
    p[6] = p7;
    p[7] = p8;
    e[0] = e[1] = e[2] = e[3] = nullptr;
    e[4] = e[5] = e[6] = e[7] = nullptr;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val + p[4]->val +
            p[5]->val + p[6]->val + p[7]->val) /
           8.;
  }
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    sf(0) = 0.125 * (1 - u) * (1 - v) * (1 - w);
    sf(1) = 0.125 * (1 + u) * (1 - v) * (1 - w);
    sf(2) = 0.125 * (1 + u) * (1 + v) * (1 - w);
    sf(3) = 0.125 * (1 - u) * (1 + v) * (1 - w);
    sf(4) = 0.125 * (1 - u) * (1 - v) * (1 + w);
    sf(5) = 0.125 * (1 + u) * (1 - v) * (1 + w);
    sf(6) = 0.125 * (1 + u) * (1 + v) * (1 + w);
    sf(7) = 0.125 * (1 - u) * (1 + v) * (1 + w);
  }
  static void create(int maxlevel);
  static void recurCreate(adaptiveHexahedron *h, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptiveHexahedron *h, double AVG, double tol);
};

// modif koen.hillewaert@cenaero.be, 31/07/2014

class adaptivePyramid {
public:
  bool visible;
  adaptiveVertex *p[5];
  adaptivePyramid *e[10];
  static std::list<adaptivePyramid *> all;
  static std::set<adaptiveVertex> allVertices;
  static int numNodes, numEdges;

public:
  adaptivePyramid(adaptiveVertex *p1, adaptiveVertex *p2, adaptiveVertex *p3,
                  adaptiveVertex *p4, adaptiveVertex *p5)
    : visible(false)
  {
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    p[3] = p4;
    p[4] = p5;
    for(int i = 0; i < 10; i++) e[i] = nullptr;
  }
  inline double V() const
  {
    return (p[0]->val + p[1]->val + p[2]->val + p[3]->val + p[4]->val) / 5.;
  }
  // barycentric coordinates ?
  inline static void GSF(double u, double v, double w, fullVector<double> &sf)
  {
    double ww = 0.25 / std::max(1e-14, 1. - w);
    sf(0) = (1 - u - w) * (1 - v - w) * ww;
    sf(1) = (1 + u - w) * (1 - v - w) * ww;
    sf(2) = (1 + u - w) * (1 + v - w) * ww;
    sf(3) = (1 - u - w) * (1 + v - w) * ww;
    sf(4) = w;
  }
  static void create(int maxlevel);
  static void recurCreate(adaptivePyramid *h, int maxlevel, int level);
  static void error(double AVG, double tol);
  static void recurError(adaptivePyramid *h, double AVG, double tol);
};

class PCoords {
public:
  double c[3];
  PCoords(double x, double y, double z)
  {
    c[0] = x;
    c[1] = y;
    c[2] = z;
  }
};

class PValues {
public:
  short int sizev; // acceptable values: 1 (scalar), 3 (vector), 9 (tensor)
  double *v;
  PValues(const PValues &obj)
  {
    sizev = obj.sizev;
    v = new double[sizev];
    for(int i = 0; i < sizev; i++) { v[i] = obj.v[i]; }
  }
  PValues(int size)
  {
    sizev = size;
    v = new double[sizev];
    for(int i = 0; i < sizev; i++) { v[i] = 0.0; }
  }
  PValues(double vx)
  {
    sizev = 1;
    v = new double[sizev];
    v[0] = vx;
  }
  PValues(double vx, double vy, double vz)
  {
    sizev = 3;
    v = new double[sizev];
    v[0] = vx;
    v[1] = vy;
    v[2] = vz;
  }
  PValues(double vxx, double vxy, double vxz, double vyx, double vyy,
          double vyz, double vzx, double vzy, double vzz)
  {
    sizev = 9;
    v = new double[sizev];
    v[0] = vxx;
    v[1] = vxy;
    v[2] = vxz;
    v[3] = vyx;
    v[4] = vyy;
    v[5] = vyz;
    v[6] = vzx;
    v[7] = vzy;
    v[8] = vzz;
  }
  ~PValues() { delete[] v; }
  void operator=(const PValues &obj)
  {
    // Assume PValues object has already been generated
    // and v allocated when the operator = is called
    if(sizev != obj.sizev)
      Msg::Error("In PValues overlodaing operator: size mistmatch %d %d",
                 sizev);
    for(int i = 0; i < sizev; i++) { v[i] = obj.v[i]; }
  }
};

class globalVTKData {
public:
  static std::vector<vectInt>
    vtkGlobalConnectivity; // conectivity (vector of vector)
  static std::vector<int> vtkGlobalCellType; // topology
  static std::vector<PCoords> vtkGlobalCoords; // coordinates
  static std::vector<PValues>
    vtkGlobalValues; // nodal values (either scalar or vector)
  globalVTKData();
  static void clearGlobalConnectivity()
  {
    for(auto it = vtkGlobalConnectivity.begin();
        it != vtkGlobalConnectivity.end(); ++it) {
      it->clear();
    }
    vtkGlobalConnectivity.clear();
    std::vector<vectInt>().swap(vtkGlobalConnectivity);
  }
  static void clearGlobalCellType()
  {
    vtkGlobalCellType.clear();
    std::vector<int>().swap(vtkGlobalCellType);
  }
  static void clearGlobalCoords()
  {
    vtkGlobalCoords.clear();
    std::vector<PCoords>().swap(vtkGlobalCoords);
  }
  static void clearGlobalValues()
  {
    vtkGlobalValues.clear();
    std::vector<PValues>().swap(vtkGlobalValues);
  }
  static void clearGlobalData()
  {
    clearGlobalConnectivity();
    clearGlobalCellType();
    clearGlobalCoords();
    clearGlobalValues();
  }
  ~globalVTKData() { clearGlobalData(); }
};

class VTKData {
public:
  // Data container to write output files readable for ParaView
  // vtk legacy and vtu for now
  std::string vtkFieldName;
  std::string vtkFileName;
  std::string vtkFormat;
  std::string vtkDirName;

  int vtkStep;
  int vtkLevel;
  int vtkNumComp;
  double vtkTol;
  int vtkNpart;

  bool vtkIsBinary;
  int vtkUseDefaultName;
  int minElmPerPart, maxElmPerPart, numPartMinElm, numPartMaxElm;

  // File variables
  FILE *vtkFile;
  FILE *vtkFileCoord;
  FILE *vtkFileConnect;
  FILE *vtkFileCellOffset;
  FILE *vtkFileCellType;
  FILE *vtkFileNodVal;
  int vtkCountFile;

  int vtkTotNumElmLev0;
  int vtkCountTotElmLev0;
  int vtkCountTotNod;
  int vtkCountTotElm;
  int vtkCountCoord;
  int vtkCountTotNodConnect;
  int vtkCountTotVal;
  int vtkCountCellOffset; // used only for ascii output
  int vtkCountCellType; // used only for ascii output

  std::vector<vectInt> vtkLocalConnectivity; // conectivity (vector of vector)
  std::vector<int> vtkLocalCellType; // topology
  std::vector<PCoords> vtkLocalCoords; // coordinates
  std::vector<PValues> vtkLocalValues; // nodal values (either scalar or vector)

public:
  VTKData(std::string fieldName = "unknown", int numComp = -1, int step = -1,
          int level = -1, double tol = 0.0, std::string filename = "unknown",
          int useDefaultName = 1, int npart = -1, bool isBinary = true)
  {
    vtkIsBinary = isBinary; // choice: true, false
    vtkFormat =
      std::string("vtu"); // choice: vtk (VTK legacy), vtu (XML appended)

    vtkFieldName = fieldName;
    vtkFileName = filename;
    vtkUseDefaultName = useDefaultName;
    vtkNumComp = numComp;
    vtkStep = step;
    vtkLevel = level;
    vtkTol = tol;
    vtkNpart = npart;

    vtkCountFile = 0;
    vtkTotNumElmLev0 = 0;
    vtkCountTotElmLev0 = 0;
    vtkCountTotNod = 0;
    vtkCountTotElm = 0;
    vtkCountCoord = 0;
    vtkCountTotNodConnect = 0;
    vtkCountTotVal = 0;
    vtkCountCellOffset = 0; // used only for ascii output
    vtkCountCellType = 0;
  }
  void clearLocalData()
  {
    for(auto it = vtkLocalConnectivity.begin();
        it != vtkLocalConnectivity.end(); ++it) {
      it->clear();
    }
    vtkLocalConnectivity.clear();
    vtkLocalCellType.clear();
    vtkLocalCoords.clear();
    vtkLocalValues.clear();
  }
  ~VTKData() { clearLocalData(); }
  void incrementTotNod(int increment) { vtkCountTotNod += increment; }
  void incrementTotElm(int increment) { vtkCountTotElm += increment; }
  void incrementTotElmLev0(int increment) { vtkCountTotElmLev0 += increment; }
  bool isLittleEndian();
  void SwapArrayByteOrder(void *array, int nbytes,
                          int nItems); // used only for VTK
  int getPVCellType(int numEdges);
  // void writeParaViewData();
  void writeVTKElmData();
  void initVTKFile();
  void finalizeVTKFile();
  void setFileDistribution()
  {
    int tmpmod = vtkTotNumElmLev0 % vtkNpart;
    minElmPerPart = (vtkTotNumElmLev0 - tmpmod) / vtkNpart;
    numPartMinElm = vtkNpart - tmpmod;

    if(tmpmod == 0)
      maxElmPerPart = minElmPerPart;
    else
      maxElmPerPart = minElmPerPart + 1;
    numPartMaxElm = tmpmod;
    assert(vtkTotNumElmLev0 ==
           minElmPerPart * numPartMinElm + maxElmPerPart * numPartMaxElm);
  }
};

template <class T> class adaptiveElements {
private:
  fullMatrix<double> *_coeffsVal, *_eexpsVal, *_interpolVal;
  fullMatrix<double> *_coeffsGeom, *_eexpsGeom, *_interpolGeom;

public:
  adaptiveElements(std::vector<fullMatrix<double> *> &interpolationMatrices);
  ~adaptiveElements();
  // create the _interpolVal and _interpolGeom matrices at the given
  // refinement level
  void init(int level);
  // process the element data in coords/values and return the refined
  // elements in coords/values
  bool adapt(double tol, int numComp, std::vector<PCoords> &coords,
             std::vector<PValues> &values, double &minVal, double &maxVal,
             GMSH_PostPlugin *plug = nullptr, bool onlyComputeMinMax = false);
  // adapt all the T-type elements in the input view and add the
  // refined elements in the output view (we will remove this when we
  // switch to true on-the-fly local refinement in drawPost())
  void addInView(double tol, int step, PViewData *in, PViewDataList *out,
                 GMSH_PostPlugin *plug = nullptr);

  // Routines for
  // - export of adapted views to pvtu file format for parallel visualization
  //   with paraview,
  // - and/or generation of VTK data structure for ParaView plugin.

  // Clone of adapt for VTK output files
  void adaptForVTK(double tol, int numComp, std::vector<PCoords> &coords,
                   std::vector<PValues> &values, double &minVal,
                   double &maxVal);

  // Clone of addInView for VTK output files
  void addInViewForVTK(int step, PViewData *in, VTKData &myVTKData,
                       bool writeVtk = true, bool buildStaticData = false);

  int countElmLev0(int step, PViewData *in);

  // Build a mapping between all the nodes of the refined element
  // and the node of the canonical refined element in order to
  // generate a connectivity related to the canonical element
  void buildMapping(nodMap<T> &myNodMap, double tol, int &numNodInsert);
};

class adaptiveData {
private:
  int _step, _level;
  double _tol;
  PViewData *_inData;
  PViewDataList *_outData;
  adaptiveElements<adaptivePoint> *_points;
  adaptiveElements<adaptiveLine> *_lines;
  adaptiveElements<adaptiveTriangle> *_triangles;
  adaptiveElements<adaptiveQuadrangle> *_quadrangles;
  adaptiveElements<adaptiveTetrahedron> *_tetrahedra;
  adaptiveElements<adaptiveHexahedron> *_hexahedra;
  adaptiveElements<adaptivePrism> *_prisms;
  adaptiveElements<adaptivePyramid> *_pyramids;

  // When set to true, this builds a global VTK data structure (connectivity,
  // coords, etc) for the adaptive views.  This can be very memory consuming for
  // high adaptation levels. Use with caution.  Useful when GMSH is used as an
  // external library to provide for instance a GMSH reader in a ParaView
  // plugin.  By default, set to false in the constructor.
  bool buildStaticData;

  // This variable helps limit memory consumption (no global data structure)
  // when GMSH is requested to write the data structure of adapted view under
  // pvtu format In this case, one adapted element is considered at a time so
  // that it can generate billions of adapted elements on a single core, as long
  // as disk space allows it.  This variable is set to true by default in the
  // constructor.
  bool writeVTK;

public:
  static double timerInit, timerAdapt;
  adaptiveData(PViewData *data, bool outDataInit = true);
  ~adaptiveData();
  PViewData *getData() { return (PViewData *)_outData; }
  void changeResolution(int step, int level, double tol,
                        GMSH_PostPlugin *plug = nullptr);
  int countTotElmLev0(int step, PViewData *in);
  void changeResolutionForVTK(int step, int level, double tol, int npart = 1,
                              bool isBinary = true,
                              const std::string &guifileName = "unknown",
                              int useDefaultName = 1);
  void upBuildStaticData(bool newValue) { buildStaticData = newValue; }
  void upWriteVTK(bool newValue) { writeVTK = newValue; }
};

#endif
