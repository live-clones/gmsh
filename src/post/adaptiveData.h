// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ADAPTIVE_DATA_H
#define ADAPTIVE_DATA_H

#include <deque>
#include <set>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sys/stat.h>
#include <assert.h>
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

// Adaptive views. A high-order element is shown through first order
// elements, obtained by subdividing its reference element recursively and
// interpolating the coordinates and the values at the points of the
// subdivision. The subdivision of a reference element is a tree, built once
// per view and kind of element down to the maximum level (adaptiveElements::
// init()); for each element of the view the fields are evaluated at all the
// points of the tree, and an error estimate chooses which elements of the tree
// are kept (adaptiveElements::adapt()).

// A point of the subdivision of a reference element
class adaptiveVertex {
public:
  float x, y, z; // in the reference element (halves of halves: exact)
  int index; // in adaptiveElements::vertices, and in the interpolation matrices
  // for the element of the view being adapted:
  double X, Y, Z; // in the model
  double norm; // what the error is estimated on: the value, or its norm
  double val, valy, valz; // the value (a scalar, a vector or a tensor)
  double valyx, valyy, valyz;
  double valzx, valzy, valzz;

public:
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

// What tells one kind of element from another: its reference element, how it
// is cut in children, and the weights of the children in the error estimate
class adaptiveShape {
public:
  int type; // TYPE_TRI, ...
  int numNodes, numEdges, numChildren;
  double nodes[8][3]; // of the reference element
  // The points of one subdivision: each is the mean of some nodes of the
  // element (one node: the node itself, two: the middle of an edge, ...)
  std::vector<std::vector<int> > points;
  // the nodes of each child, as indices in points
  std::vector<std::vector<int> > children;
  // The mean of a field over an element is estimated by the mean of its
  // values at the nodes. The weighted mean over the children is a better
  // estimate, and equal to the first for a field that varies linearly: their
  // difference measures what another subdivision would bring.
  std::vector<double> weights;
  double sumOfWeights;
  // the diagonal the drawing code cuts quadrangles and hexahedra along, along
  // which the field is tested too (-1 if none)
  int diagonal[2];
  // first order shape functions, for the views that do not provide theirs
  void (*shapeFunctions)(double u, double v, double w, fullVector<double> &sf);
  // the functions a view provides are given by monomials, which are not the
  // same in a pyramid
  bool pyramid;

  // (TYPE_PNT, TYPE_LIN, TYPE_TRI, TYPE_QUA, TYPE_TET, TYPE_HEX, TYPE_PRI or
  // TYPE_PYR)
  static const adaptiveShape &get(int type);
};

// An element of the tree of subdivisions
class adaptiveElement {
public:
  const adaptiveShape *shape;
  bool visible; // kept for the element of the view being adapted?
  adaptiveVertex *p[8]; // its nodes
  adaptiveElement *e[10]; // its children (null at the last level)

public:
  // the mean of the field at the nodes
  double V() const
  {
    double v = p[0]->norm;
    for(int i = 1; i < shape->numNodes; i++) v += p[i]->norm;
    return v / shape->numNodes;
  }
  // the weighted mean over the children
  double meanOfChildren() const
  {
    double v = 0.;
    for(int i = 0; i < shape->numChildren; i++)
      v += shape->weights[i] * e[i]->V();
    return v / shape->sumOfWeights;
  }
};

class nodMap {
public:
  std::vector<int> mapping;

public:
  void cleanMapping() { mapping.clear(); }
  int getSize() { return (int)mapping.size(); }
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

// The value at a point: 1 (scalar), 3 (vector) or 9 (tensor) numbers. Scalars
// and vectors are stored in the object itself: a memory allocation per value
// made adapting a view twice as slow.
class PValues {
private:
  double _small[3];
  void _allocate(int size)
  {
    sizev = size;
    v = (sizev <= 3) ? _small : new double[sizev];
  }

public:
  short int sizev; // acceptable values: 1 (scalar), 3 (vector), 9 (tensor)
  double *v;
  PValues(const PValues &obj)
  {
    _allocate(obj.sizev);
    for(int i = 0; i < sizev; i++) v[i] = obj.v[i];
  }
  PValues(PValues &&obj) noexcept
  {
    sizev = obj.sizev;
    if(obj.v == obj._small) {
      v = _small;
      for(int i = 0; i < sizev; i++) v[i] = obj.v[i];
    }
    else { // take the array over
      v = obj.v;
      obj.v = obj._small;
      obj.sizev = 0;
    }
  }
  PValues(int size)
  {
    _allocate(size);
    for(int i = 0; i < sizev; i++) v[i] = 0.0;
  }
  PValues(double vx)
  {
    _allocate(1);
    v[0] = vx;
  }
  PValues(double vx, double vy, double vz)
  {
    _allocate(3);
    v[0] = vx;
    v[1] = vy;
    v[2] = vz;
  }
  PValues(double vxx, double vxy, double vxz, double vyx, double vyy,
          double vyz, double vzx, double vzy, double vzz)
  {
    _allocate(9);
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
  ~PValues()
  {
    if(v != _small) delete[] v;
  }
  PValues &operator=(const PValues &obj)
  {
    if(this == &obj) return *this;
    if(sizev != obj.sizev) {
      if(v != _small) delete[] v;
      _allocate(obj.sizev);
    }
    for(int i = 0; i < sizev; i++) v[i] = obj.v[i];
    return *this;
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

// The elements of one kind of a view
class adaptiveElements {
private:
  const adaptiveShape &_shape;
  // the shape functions of the view (monomials and coefficients) for the
  // values and for the geometry, if it provides them, and their values at the
  // vertices of the tree
  fullMatrix<double> *_coeffsVal, *_eexpsVal, *_interpolVal;
  fullMatrix<double> *_coeffsGeom, *_eexpsGeom, *_interpolGeom;
  adaptiveElement *_create(const std::vector<adaptiveVertex *> &nodes,
                           int maxLevel, int level);
  adaptiveVertex *_vertex(double x, double y, double z);
  void _error(adaptiveElement *e, double threshold);

public:
  // the tree: its root first
  std::deque<adaptiveElement> all;
  std::set<adaptiveVertex> allVertices;

public:
  adaptiveElements(int type,
                   const std::vector<fullMatrix<double> *> &interpolationMatrices);
  ~adaptiveElements();
  const adaptiveShape &shape() const { return _shape; }
  // build the tree down to the given level, and the _interpolVal and
  // _interpolGeom matrices
  void init(int level);
  // process the element data in coords/values and return the refined
  // elements in coords/values
  bool adapt(double tol, int numComp, std::vector<PCoords> &coords,
             std::vector<PValues> &values, double range,
             GMSH_PostPlugin *plug = nullptr);
  // adapt all the elements of this kind in the input view and add the refined
  // elements in the output view (we will remove this when we switch to true
  // on-the-fly local refinement in drawPost()); polygons and polyhedra are
  // refined through their triangles and tetrahedra (type = TYPE_POLYG or
  // TYPE_POLYH)
  void addInView(double tol, int step, PViewData *in, PViewDataList *out,
                 GMSH_PostPlugin *plug = nullptr, int level = 0,
                 int type = 0);

  // Routines for
  // - export of adapted views to pvtu file format for parallel visualization
  //   with paraview,
  // - and/or generation of VTK data structure for ParaView plugin.

  // addInView for VTK output files
  void addInViewForVTK(int step, PViewData *in, VTKData &myVTKData,
                       bool writeVtk = true, bool buildStaticData = false);

  int countElmLev0(int step, PViewData *in);

  // Build a mapping between all the nodes of the refined element
  // and the node of the canonical refined element in order to
  // generate a connectivity related to the canonical element
  void buildMapping(nodMap &myNodMap, double tol, int &numNodInsert);
};

class adaptiveData {
private:
  int _step, _level;
  double _tol;
  PViewData *_inData;
  PViewDataList *_outData;
  adaptiveElements *_points, *_lines, *_triangles, *_quadrangles;
  adaptiveElements *_tetrahedra, *_hexahedra, *_prisms, *_pyramids;
  // (refined through their triangles and tetrahedra)
  adaptiveElements *_polygons, *_polyhedra;

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
