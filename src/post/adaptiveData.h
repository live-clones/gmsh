// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ADAPTIVE_DATA_H
#define ADAPTIVE_DATA_H

#include <array>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "fullMatrix.h"

typedef std::vector<int> vectInt;

class PViewData;
class PViewDataList;
class GMSH_PostPlugin;

// (used by ParaView's GmshReader plugin)
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
  unsigned char onFaces; // the faces of the reference element it is on, a bit each
  // for the element of the view being adapted, when a plugin looks at it:
  double X, Y, Z; // in the model
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
// is cut in children
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
  // a child and its node at each of the points
  std::vector<std::array<int, 2> > where;
  // the faces of a volume by their nodes, ordered as the drawing code orders
  // them (the quadrangles first)
  std::vector<std::vector<int> > faces;
  // the diagonal the drawing code cuts quadrangles and hexahedra along (-1 if
  // none)
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
  // for each face, the face of the reference element it lies on (-1 if none)
  signed char onFace[6];

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

class adaptiveVTKWriter; // (in adaptiveData.cpp)

// The values the target error is relative to: the range of the data (all the
// steps), or a range given, as the custom range of a view, outside of which
// the field is drawn as the nearest end of the range, or not at all: an
// element whose values (at the points the error estimate looks at) are all
// on the same side of it then has no error
class adaptiveRange {
public:
  double min, max;
  bool clamp;
  adaptiveRange(double mn = 0., double mx = -1., bool c = false)
    : min(mn), max(mx), clamp(c)
  {
  }
};

// What adapting an element needs to remember: the field and the positions at
// the vertices of the tree where they have been computed (known for the
// element whose number, the stamp, they carry), and the elements that are kept
class adaptiveWork {
public:
  int stamp, numComp;
  const double *inXYZ, *inValues; // the element, as given to adapt()
  adaptiveRange range; // as given to adapt()
  // the faces of the element on the skin, a bit each, when only they are
  // refined (-1: the whole element)
  int skin;
  std::vector<int> evaluated, located;
  std::vector<double> values, norm, xyz;
  std::vector<const adaptiveElement *> visible;
  adaptiveWork()
    : stamp(0), numComp(0), inXYZ(nullptr), inValues(nullptr), skin(-1)
  {
  }
};

// The elements of one kind of a view
class adaptiveElements {
private:
  const adaptiveShape &_shape;
  // the shape functions of the view (monomials and coefficients) for the
  // values and for the geometry, if it provides them, and their values at the
  // vertices of the tree
  fullMatrix<double> *_coeffsVal, *_eexpsVal;
  fullMatrix<double> *_coeffsGeom, *_eexpsGeom;
  std::vector<double> _interpolVal, _interpolGeom; // a row per vertex
  int _numVals, _numNodes; // their numbers of columns
  std::vector<const adaptiveElement *> _leaves; // the last level of the tree
  void _evaluate(adaptiveWork &w, const adaptiveVertex *p) const;
  void _locate(adaptiveWork &w, const adaptiveVertex *p) const;
  double _errorOf(adaptiveWork &w, const adaptiveElement *e) const;
  // does the element have a face on the skin, if only the skin is refined?
  static bool _onSkin(const adaptiveWork &w, const adaptiveElement *e)
  {
    if(w.skin < 0) return true;
    for(int f = 0; f < 6; f++)
      if(e->onFace[f] >= 0 && (w.skin & (1 << e->onFace[f]))) return true;
    return false;
  }
  void _error(adaptiveWork &w, const adaptiveElement *e,
              double threshold) const;
  void _askPlugin(adaptiveWork &w, GMSH_PostPlugin *plug);
  int _addPolytope(int level, int step, PViewData *in, int ent, int ele,
                   int numComp, std::vector<double> &list);
  adaptiveElement *_create(const std::vector<adaptiveVertex *> &nodes,
                           int maxLevel, int level);
  adaptiveVertex *_vertex(double x, double y, double z);

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
  // Refine an element of the view, given as the x, then the y, then the z
  // of its nodes and its values a component after the other, and as the bits
  // of its faces that are on the skin of the view. The elements that are kept
  // are added to out as the lists of a view hold them (and the bits of their
  // faces to outSkin); returns their number. The tree is only read, unless
  // there is a plugin: several threads can adapt elements at the same time,
  // each with its own workspace.
  // (range: that of the values the target error is relative to; skinOnly:
  // refine only the faces on the skin, the elements with a face there being
  // kept, and the error being looked at on them)
  int adapt(adaptiveWork &w, double tol, int numComp, const double *xyz,
            const double *values, const adaptiveRange &range,
            GMSH_PostPlugin *plug, unsigned char onSkin,
            std::vector<double> &out, std::vector<unsigned char> *outSkin,
            bool skinOnly = false);
  // adapt all the elements of this kind in the input view and add the refined
  // elements in the output view (we will remove this when we switch to true
  // on-the-fly local refinement in drawPost()); polygons and polyhedra are
  // refined through their triangles and tetrahedra (type = TYPE_POLYG or
  // TYPE_POLYH)
  // (inSkin: for each entity and element of the input view, its faces on the
  // skin of the view; outSkin: the same for the elements added; range: the
  // one given, if its min is not above its max, or else that of the data)
  void addInView(double tol, int step, PViewData *in, PViewDataList *out,
                 GMSH_PostPlugin *plug = nullptr, int level = 0, int type = 0,
                 const std::vector<std::vector<unsigned char> > *inSkin = nullptr,
                 std::vector<unsigned char> *outSkin = nullptr,
                 const adaptiveRange &range = adaptiveRange(),
                 bool skinOnly = false);

  // Routines for
  // - export of adapted views to pvtu file format for parallel visualization
  //   with paraview,
  // - and/or generation of VTK data structure for ParaView plugin.

  // addInView for VTK output files and for globalVTKData
  void addInViewForVTK(int step, double tol, PViewData *in,
                       adaptiveVTKWriter *writer, bool buildStaticData,
                       int &numPoints,
                       const adaptiveRange &range = adaptiveRange());

  int countElmLev0(int step, PViewData *in);

  // Build a mapping between all the nodes of the refined element
  // and the node of the canonical refined element in order to
  // generate a connectivity related to the canonical element
  void buildMapping(const adaptiveWork &w, nodMap &myNodMap, double tol,
                    int &numNodInsert);
};

class adaptiveData {
private:
  int _step, _level;
  double _tol;
  adaptiveRange _range; // (as given)
  // only the skin refined (as asked, and as done: not without a skin)
  bool _skinAsked, _skinOnly;
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

  bool _findSkin(int step, std::vector<std::vector<unsigned char> > &skin);

public:
  adaptiveData(PViewData *data, bool outDataInit = true);
  ~adaptiveData();
  PViewData *getData() { return (PViewData *)_outData; }
  // (min and max: the range the target error is relative to, if min is not
  // above max, e.g. the custom range of the view; see adaptiveRange)
  // (skinOnly: refine only the faces of the volumes on the skin of the view,
  // for a view that only draws them)
  void changeResolution(int step, int level, double tol,
                        GMSH_PostPlugin *plug = nullptr, double min = 0.,
                        double max = -1., bool skinOnly = false);
  bool isSkinOnly() const { return _skinOnly; }
  int countTotElmLev0(int step, PViewData *in);
  void changeResolutionForVTK(int step, int level, double tol, int npart = 1,
                              bool isBinary = true,
                              const std::string &guifileName = "unknown",
                              int useDefaultName = 1, double min = 0.,
                              double max = -1.);
  void upBuildStaticData(bool newValue) { buildStaticData = newValue; }
  void upWriteVTK(bool newValue) { writeVTK = newValue; }
};

#endif
