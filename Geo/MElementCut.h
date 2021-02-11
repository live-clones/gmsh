// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Gaetan Bricteux

#ifndef MELEMENTCUT_H
#define MELEMENTCUT_H

#include "GmshMessage.h"
#include "MElement.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"

class gLevelset;
class GModel;

class MPolyhedron : public MElement {
protected:
  bool _owner;
  MElement *_orig;
  IntPt *_intpt;
  std::vector<MTetrahedron *> _parts;
  std::vector<MVertex *> _vertices;
  std::vector<MVertex *> _innerVertices;
  std::vector<MEdge> _edges;
  std::vector<MFace> _faces;
  void _init();

public:
  MPolyhedron(std::vector<MVertex *> v, int num = 0, int part = 0,
              bool owner = false, MElement *orig = nullptr)
    : MElement(num, part), _owner(owner), _orig(orig), _intpt(nullptr)
  {
    if(v.size() % 4) {
      Msg::Error("Got %d nodes for polyhedron", (int)v.size());
      return;
    }
    for(std::size_t i = 0; i < v.size(); i += 4)
      _parts.push_back(new MTetrahedron(v[i], v[i + 1], v[i + 2], v[i + 3]));
    _init();
  }
  MPolyhedron(std::vector<MTetrahedron *> vT, int num = 0, int part = 0,
              bool owner = false, MElement *orig = nullptr)
    : MElement(num, part), _owner(owner), _orig(orig), _intpt(nullptr)
  {
    for(std::size_t i = 0; i < vT.size(); i++) _parts.push_back(vT[i]);
    _init();
  }
  ~MPolyhedron()
  {
    if(_owner) delete _orig;
    for(std::size_t i = 0; i < _parts.size(); i++) delete _parts[i];
    if(_intpt) delete[] _intpt;
  }
  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const
  {
    return _vertices.size() + _innerVertices.size();
  }
  virtual int getNumVolumeVertices() const { return _innerVertices.size(); }
  virtual MVertex *getVertex(int num)
  {
    return (num < (int)_vertices.size()) ?
             _vertices[num] :
             _innerVertices[num - _vertices.size()];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return (num < (int)_vertices.size()) ?
             _vertices[num] :
             _innerVertices[num - _vertices.size()];
  }
  virtual int getNumEdges() const { return _edges.size(); }
  virtual MEdge getEdge(int num) const { return _edges[num]; }
  virtual int getNumEdgesRep(bool curved) { return _edges.size(); }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    MEdge e(getEdge(num));
    for(std::size_t i = 0; i < _faces.size(); i++)
      for(int j = 0; j < 3; j++)
        if(_faces[i].getEdge(j) == e)
          _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, i);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    v[0] = _edges[num].getVertex(0);
    v[1] = _edges[num].getVertex(1);
  }
  virtual int getNumFaces() { return _faces.size(); }
  virtual MFace getFace(int num) const { return _faces[num]; }
  virtual int getNumFacesRep(bool curved) { return _faces.size(); }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_faces[num].getVertex(0), _faces[num].getVertex(1),
                _faces[num].getVertex(2), x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(3);
    v[0] = _faces[num].getVertex(0);
    v[1] = _faces[num].getVertex(1);
    v[2] = _faces[num].getVertex(2);
  }
  virtual int getType() const { return TYPE_POLYH; }
  virtual int getTypeForMSH() const { return MSH_POLYH_; }
  virtual void reverse()
  {
    for(std::size_t i = 0; i < _parts.size(); i++) _parts[i]->reverse();
    _vertices.clear();
    _innerVertices.clear();
    _edges.clear();
    _faces.clear();
    _init();
  }
  virtual double getVolume()
  {
    double vol = 0;
    for(std::size_t i = 0; i < _parts.size(); i++)
      vol += _parts[i]->getVolume();
    return vol;
  }
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const
  {
    return (_orig ? _orig->getFunctionSpace(order, serendip) : nullptr);
  }
  virtual const JacobianBasis *getJacobianFuncSpace(int order = -1) const
  {
    return (_orig ? _orig->getJacobianFuncSpace(order) : nullptr);
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int o) const
  {
    if(_orig) _orig->getShapeFunctions(u, v, w, s, o);
  }
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int o) const
  {
    if(_orig) _orig->getGradShapeFunctions(u, v, w, s, o);
  }
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int o) const
  {
    if(_orig) _orig->getHessShapeFunctions(u, v, w, s, o);
  }
  virtual std::size_t getNumShapeFunctions() const
  {
    return (_orig ? _orig->getNumShapeFunctions() : 0);
  }
  virtual std::size_t getNumPrimaryShapeFunctions() const
  {
    return (_orig ? _orig->getNumPrimaryShapeFunctions() : 0);
  }
  virtual const MVertex *getShapeFunctionNode(int i) const
  {
    return (_orig ? _orig->getShapeFunctionNode(i) : nullptr);
  }
  virtual MVertex *getShapeFunctionNode(int i)
  {
    return (_orig ? _orig->getShapeFunctionNode(i) : nullptr);
  }

  // the parametric coordinates of the polyhedron are
  // the coordinates in the local parent element.
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false)
  {
    _orig = p;
    _owner = owner;
  }
  virtual int getNumChildren() const { return _parts.size(); }
  virtual MElement *getChild(int i) const { return _parts[i]; }
  virtual bool ownsParent() const { return _owner; }
  virtual std::size_t getNumVerticesForMSH() { return _parts.size() * 4; }
  virtual void getVerticesIdForMSH(std::vector<int> &verts)
  {
    std::size_t n = getNumVerticesForMSH();
    verts.resize(n);
    for(std::size_t i = 0; i < _parts.size(); i++)
      for(int j = 0; j < 4; j++)
        verts[i * 4 + j] = _parts[i]->getVertex(j)->getIndex();
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }
};

class MPolygon : public MElement {
protected:
  bool _owner;
  MElement *_orig;
  IntPt *_intpt;
  std::vector<MTriangle *> _parts;
  std::vector<MVertex *> _vertices;
  std::vector<MVertex *> _innerVertices;
  std::vector<MEdge> _edges;
  void _initVertices();

public:
  MPolygon(std::vector<MVertex *> v, int num = 0, int part = 0,
           bool owner = false, MElement *orig = nullptr)
    : MElement(num, part), _owner(owner), _orig(orig), _intpt(nullptr)
  {
    for(std::size_t i = 0; i < v.size() / 3; i++)
      _parts.push_back(new MTriangle(v[i * 3], v[i * 3 + 1], v[i * 3 + 2]));
    _initVertices();
  }
  MPolygon(std::vector<MTriangle *> vT, int num = 0, int part = 0,
           bool owner = false, MElement *orig = nullptr)
    : MElement(num, part), _owner(owner), _orig(orig), _intpt(nullptr)
  {
    for(std::size_t i = 0; i < vT.size(); i++) {
      MTriangle *t = (MTriangle *)vT[i];
      _parts.push_back(t);
    }
    _initVertices();
  }
  ~MPolygon()
  {
    if(_owner) delete _orig;
    for(std::size_t i = 0; i < _parts.size(); i++) delete _parts[i];
    if(_intpt) delete[] _intpt;
  }
  virtual int getDim() const { return 2; }
  virtual std::size_t getNumVertices() const
  {
    return _vertices.size() + _innerVertices.size();
  }
  virtual int getNumFaceVertices() const { return _innerVertices.size(); }
  virtual MVertex *getVertex(int num)
  {
    return (num < (int)_vertices.size()) ?
             _vertices[num] :
             _innerVertices[num - _vertices.size()];
  }
  virtual const MVertex *getVertex(int num) const
  {
    return (num < (int)_vertices.size()) ?
             _vertices[num] :
             _innerVertices[num - _vertices.size()];
  }
  virtual int getNumEdges() const { return _edges.size(); }
  virtual MEdge getEdge(int num) const { return _edges[num]; }
  virtual int getNumEdgesRep(bool curved) { return getNumEdges(); }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(2);
    v[0] = _edges[num].getVertex(0);
    v[1] = _edges[num].getVertex(1);
  }
  virtual int getNumFaces() { return 1; }
  virtual MFace getFace(int num) const { return MFace(_vertices); }
  virtual int getNumFacesRep(bool curved) { return _parts.size(); }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_parts[num]->getVertex(0), _parts[num]->getVertex(1),
                _parts[num]->getVertex(2), x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex *> &v) const
  {
    v.resize(_vertices.size() + _innerVertices.size());
    for(std::size_t i = 0; i < _vertices.size() + _innerVertices.size(); i++)
      v[i] = (i < _vertices.size()) ? _vertices[i] :
                                      _innerVertices[i - _vertices.size()];
  }
  virtual int getType() const { return TYPE_POLYG; }
  virtual int getTypeForMSH() const { return MSH_POLYG_; }
  virtual void reverse()
  {
    for(std::size_t i = 0; i < _parts.size(); i++) _parts[i]->reverse();
    _vertices.clear();
    _innerVertices.clear();
    _edges.clear();
    _initVertices();
  }
  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false)
  {
    _orig = p;
    _owner = owner;
  }
  virtual int getNumChildren() const { return _parts.size(); }
  virtual MElement *getChild(int i) const { return _parts[i]; }
  virtual bool ownsParent() const { return _owner; }
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const
  {
    return (_orig ? _orig->getFunctionSpace(order, serendip) : nullptr);
  }
  virtual const JacobianBasis *getJacobianFuncSpace(int order = -1) const
  {
    return (_orig ? _orig->getJacobianFuncSpace(order) : nullptr);
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int o) const
  {
    if(_orig) _orig->getShapeFunctions(u, v, w, s, o);
  }
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int o) const
  {
    if(_orig) _orig->getGradShapeFunctions(u, v, w, s, o);
  }
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int o) const
  {
    if(_orig) _orig->getHessShapeFunctions(u, v, w, s, o);
  }
  virtual std::size_t getNumShapeFunctions() const
  {
    return (_orig ? _orig->getNumShapeFunctions() : 0);
  }
  virtual std::size_t getNumPrimaryShapeFunctions() const
  {
    return (_orig ? _orig->getNumPrimaryShapeFunctions() : 0);
  }
  virtual const MVertex *getShapeFunctionNode(int i) const
  {
    return (_orig ? _orig->getShapeFunctionNode(i) : nullptr);
  }
  virtual MVertex *getShapeFunctionNode(int i)
  {
    return (_orig ? _orig->getShapeFunctionNode(i) : nullptr);
  }

  // the parametric coordinates of the polygon are
  // the coordinates in the local parent element.
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  virtual std::size_t getNumVerticesForMSH() { return _parts.size() * 3; }
  virtual void getVerticesIdForMSH(std::vector<int> &verts)
  {
    std::size_t n = getNumVerticesForMSH();
    verts.resize(n);
    for(std::size_t i = 0; i < _parts.size(); i++)
      for(int j = 0; j < 3; j++)
        verts[i * 3 + j] = _parts[i]->getVertex(j)->getIndex();
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }
};

class MLineChild : public MLine {
protected:
  bool _owner;
  MElement *_orig;
  IntPt *_intpt;

public:
  MLineChild(MVertex *v0, MVertex *v1, int num = 0, int part = 0,
             bool owner = false, MElement *orig = nullptr)
    : MLine(v0, v1, num, part), _owner(owner), _orig(orig), _intpt(nullptr)
  {
  }
  MLineChild(const std::vector<MVertex *> &v, int num = 0, int part = 0,
             bool owner = false, MElement *orig = nullptr)
    : MLine(v, num, part), _owner(owner), _orig(orig), _intpt(nullptr)
  {
  }
  ~MLineChild()
  {
    if(_owner) delete _orig;
  }
  virtual int getTypeForMSH() const { return MSH_LIN_C; }
  virtual const nodalBasis *getFunctionSpace(int order = -1,
                                             bool serendip = false) const
  {
    if(_orig) return _orig->getFunctionSpace(order, serendip);
    return nullptr;
  }
  virtual const JacobianBasis *getJacobianFuncSpace(int order = -1) const
  {
    if(_orig) return _orig->getJacobianFuncSpace(order);
    return nullptr;
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int o) const
  {
    if(_orig) _orig->getShapeFunctions(u, v, w, s, o);
  }
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int o) const
  {
    if(_orig) _orig->getGradShapeFunctions(u, v, w, s, o);
  }
  virtual void getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int o) const
  {
    if(_orig) _orig->getHessShapeFunctions(u, v, w, s, o);
  }
  // the parametric coordinates of the LineChildren are
  // the coordinates in the local parent element.
  virtual bool isInside(double u, double v, double w) const;
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
  virtual MElement *getParent() const { return _orig; }
  virtual void setParent(MElement *p, bool owner = false)
  {
    _orig = p;
    _owner = owner;
  }
  virtual bool ownsParent() const { return _owner; }
};

// -------------------- Border classes

class MTriangleBorder : public MTriangle {
protected:
  MElement *_domains[2];
  IntPt *_intpt;

public:
  MTriangleBorder(MVertex *v0, MVertex *v1, MVertex *v2, int num = 0,
                  int part = 0, MElement *d1 = nullptr, MElement *d2 = nullptr)
    : MTriangle(v0, v1, v2, num, part), _intpt(nullptr)
  {
    _domains[0] = d1;
    _domains[1] = d2;
  }
  MTriangleBorder(const std::vector<MVertex *> &v, int num = 0, int part = 0,
                  MElement *d1 = nullptr, MElement *d2 = nullptr)
    : MTriangle(v, num, part), _intpt(nullptr)
  {
    _domains[0] = d1;
    _domains[1] = d2;
  }
  ~MTriangleBorder() {}
  virtual MElement *getDomain(int i) const { return _domains[i]; }
  virtual void setDomain(MElement *d, int i) { _domains[i] = d; }
  virtual MElement *getParent() const
  {
    if(_domains[0]) return _domains[0]->getParent();
    if(_domains[1]) return _domains[1]->getParent();
    return nullptr;
  }
  virtual int getTypeForMSH() const { return MSH_TRI_B; }
  virtual bool isInside(double u, double v, double w) const;
  // the integration points of the MTriangleBorder are in the parent element
  // space
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
};

class MPolygonBorder : public MPolygon {
protected:
  MElement *_domains[2];
  IntPt *_intpt;

public:
  MPolygonBorder(const std::vector<MTriangle *> &v, int num = 0, int part = 0,
                 bool own = false, MElement *p = nullptr,
                 MElement *d1 = nullptr, MElement *d2 = nullptr)
    : MPolygon(v, num, part, own, p), _intpt(nullptr)
  {
    _domains[0] = d1;
    _domains[1] = d2;
  }
  MPolygonBorder(const std::vector<MVertex *> &v, int num = 0, int part = 0,
                 bool own = false, MElement *p = nullptr,
                 MElement *d1 = nullptr, MElement *d2 = nullptr)
    : MPolygon(v, num, part, own, p), _intpt(nullptr)
  {
    _domains[0] = d1;
    _domains[1] = d2;
  }
  ~MPolygonBorder() {}
  virtual MElement *getDomain(int i) const { return _domains[i]; }
  virtual void setDomain(MElement *d, int i) { _domains[i] = d; }
  virtual MElement *getParent() const
  {
    if(_domains[0]) return _domains[0]->getParent();
    if(_domains[1]) return _domains[1]->getParent();
    return nullptr;
  }
  virtual int getTypeForMSH() const { return MSH_POLYG_B; }
};

class MLineBorder : public MLine {
protected:
  MElement *_domains[2];
  IntPt *_intpt;

public:
  MLineBorder(MVertex *v0, MVertex *v1, int num = 0, int part = 0,
              MElement *d1 = nullptr, MElement *d2 = nullptr)
    : MLine(v0, v1, num, part), _intpt(nullptr)
  {
    _domains[0] = d1;
    _domains[1] = d2;
  }
  MLineBorder(const std::vector<MVertex *> &v, int num = 0, int part = 0,
              MElement *d1 = nullptr, MElement *d2 = nullptr)
    : MLine(v, num, part), _intpt(nullptr)
  {
    _domains[0] = d1;
    _domains[1] = d2;
  }
  ~MLineBorder() {}
  virtual MElement *getDomain(int i) const { return _domains[i]; }
  virtual void setDomain(MElement *d, int i) { _domains[i] = d; }
  virtual MElement *getParent() const
  {
    if(_domains[0]) return _domains[0]->getParent();
    if(_domains[1]) return _domains[1]->getParent();
    return nullptr;
  }
  virtual int getTypeForMSH() const { return MSH_LIN_B; }
  virtual bool isInside(double u, double v, double w) const;
  // the integration points of the MLineBorder are in the parent element space
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts);
};

// Build a new GModel with elements on each side of the levelset ls.
// New physical and elementary entities are created.
// The physical and elementary numbers of the elements with ls < 0 are
// the physical and elementary number of the elements cut.
// The physical and elementary numbers of the elements with ls > 0 are
// the maximum physical and elementary numbers existing in their dimension + 1.
// The physical and elementary numbers of the elements on the border (ls=0) are
// the levelset tag, unless an entity of the same dimension has already this
// number, knowing that the elements are cut in ascending dimension order
// (points, lines, surfaces and then volumes).
GModel *buildCutMesh(GModel *gm, gLevelset *ls,
                     std::map<int, std::vector<MElement *> > elements[10],
                     std::map<int, MVertex *> &vertexMap,
                     std::map<int, std::map<int, std::string> > physicals[4],
                     bool cutElem);

#endif
