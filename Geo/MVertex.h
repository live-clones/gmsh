// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MVERTEX_H
#define MVERTEX_H

#include <cmath>
#include <stdio.h>
#include <set>
#include <map>
#include <fstream>
#include "SPoint2.h"
#include "SPoint3.h"
#include "MVertexBoundaryLayerData.h"

class GEntity;
class GEdge;
class GFace;
class MVertex;

// A mesh vertex (a "node").
class MVertex {
protected:
  // the id of the vertex: this number is unique and is guaranteed never to
  // change once a vertex has been created, unless the mesh is explicitely
  // renumbered
  std::size_t _num;
  // a vertex index, used during mesh generation or for some IO operations (this
  // index is not necessarily unique, can change after mesh renumbering,
  // etc.). By convention, vertices with negative indices are not saved. (On
  // some architectures _index will be smaller than _num: this is OK, as _index
  // is only used for partial indexing in 2D and 3D meshing, or for IO formats
  // that don't support 64 bit indexing; _index is destined to be eventually
  // removed anyway.)
  long int _index;
  // a visibility and polynomial order flags
  char _visible, _order;
  // the cartesian coordinates of the vertex
  double _x, _y, _z;
  // the geometrical entity the vertex is associated with
  GEntity *_ge;

public:
  MVertex(double x, double y, double z, GEntity *ge = nullptr,
          std::size_t num = 0);
  virtual ~MVertex() {}
  void deleteLast();

  // get/set the visibility flag
  virtual char getVisibility() { return _visible; }
  virtual void setVisibility(char val) { _visible = val; }

  // get the "polynomial order" of the vertex
  int getPolynomialOrder() { return _order; }
  void setPolynomialOrder(int order) { _order = (char)order; }

  // get/set the coordinates
  double x() const { return _x; }
  double y() const { return _y; }
  double z() const { return _z; }
  double &x() { return _x; }
  double &y() { return _y; }
  double &z() { return _z; }

  SPoint3 point() const { return SPoint3(_x, _y, _z); }
  void setXYZ(double x, double y, double z)
  {
    _x = x;
    _y = y;
    _z = z;
  }

  // get/set the parent entity
  GEntity *onWhat() const { return _ge; }
  void setEntity(GEntity *ge) { _ge = ge; }

  // get the immutab vertex number
  std::size_t getNum() const { return _num; }

  // force the immutable number (this should never be used, except when
  // explicitly renumbering the mesh)
  void forceNum(std::size_t num);

  // get/set the index
  long int getIndex() const { return _index; }
  void setIndex(long int index) { _index = index; }

  // get/set ith parameter
  virtual bool getParameter(int i, double &par) const
  {
    par = 0.;
    return false;
  }
  virtual bool setParameter(int i, double par) { return false; }

  // measure distance to another vertex
  double distance(MVertex *const v)
  {
    double dx = _x - v->x();
    double dy = _y - v->y();
    double dz = _z - v->z();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
  }

  // IO routines
  void writeMSH(FILE *fp, bool binary = false, bool saveParametric = false,
                double scalingFactor = 1.0);
  void writeMSH2(FILE *fp, bool binary = false, bool saveParametric = false,
                 double scalingFactor = 1.0);
  void writePLY2(FILE *fp);
  void writeVRML(FILE *fp, double scalingFactor = 1.0);
  void writeUNV(FILE *fp, bool officialExponentFormat,
                double scalingFactor = 1.0);
  void writeVTK(FILE *fp, bool binary = false, double scalingFactor = 1.0,
                bool bigEndian = false);
  void writeMATLAB(FILE *fp, int type, bool binary, double scalingFactor = 1.0);
  void writeTOCHNOG(FILE *fp, int dim, double scalingFactor = 1.0);
  void writeMESH(FILE *fp, double scalingFactor = 1.0);
  void writeNEU(FILE *fp, int dim, double scalingFactor = 1.0);
  void writeBDF(FILE *fp, int format = 0, double scalingFactor = 1.0);
  void writeINP(FILE *fp, double scalingFactor = 1.0);
  void writeKEY(FILE *fp, double scalingFactor = 1.0);
  void writeDIFF(FILE *fp, bool binary, double scalingFactor = 1.0);
  void writeSU2(FILE *fp, int dim, double scalingFactor = 1.0);
};

class MEdgeVertex : public MVertex {
protected:
  double _u, _lc;

public:
  MVertexBoundaryLayerData *bl_data;

  MEdgeVertex(double x, double y, double z, GEntity *ge, double u,
              std::size_t num = 0, double lc = -1.0)
    : MVertex(x, y, z, ge, num), _u(u), _lc(lc), bl_data(nullptr)
  {
  }
  virtual ~MEdgeVertex()
  {
    if(bl_data) delete bl_data;
  }
  virtual bool getParameter(int i, double &par) const
  {
    if(i != 0) return false;
    par = _u;
    return true;
  }
  virtual bool setParameter(int i, double par)
  {
    if(i != 0) return false;
    _u = par;
    return true;
  }
  double getLc() const { return _lc; }
};

class MFaceVertex : public MVertex {
protected:
  double _u, _v;

public:
  MVertexBoundaryLayerData *bl_data;

  MFaceVertex(double x, double y, double z, GEntity *ge, double u, double v,
              std::size_t num = 0)
    : MVertex(x, y, z, ge, num), _u(u), _v(v), bl_data(nullptr)
  {
  }
  virtual ~MFaceVertex()
  {
    if(bl_data) delete bl_data;
  }
  virtual bool getParameter(int i, double &par) const
  {
    if(i == 0) {
      par = _u;
      return true;
    }
    else if(i == 1) {
      par = _v;
      return true;
    }
    return false;
  }
  virtual bool setParameter(int i, double par)
  {
    if(i == 0) {
      _u = par;
      return true;
    }
    else if(i == 1) {
      _v = par;
      return true;
    }
    return false;
  }
};

class MVertexPtrLessThanLexicographic {
  static double tolerance;

public:
  static double getTolerance();
  bool operator()(const MVertex *v1, const MVertex *v2) const;
};

struct MVertexPtrLessThan {
  bool operator()(const MVertex *v1, const MVertex *v2) const
  {
    return v1->getNum() < v2->getNum();
  }
};

struct MVertexPtrEqual {
  bool operator()(const MVertex *v1, const MVertex *v2) const
  {
    return v1->getNum() == v2->getNum();
  }
};

struct MVertexPtrHash {
  size_t operator()(const MVertex *v) const { return v->getNum(); }
};

bool reparamMeshEdgeOnFace(MVertex *v1, MVertex *v2, GFace *gf, SPoint2 &param1,
                           SPoint2 &param2);
bool reparamMeshVertexOnFace(MVertex const *v, const GFace *gf, SPoint2 &param,
                             bool onSurface = true);
bool reparamMeshVertexOnEdge(MVertex *v, const GEdge *ge, double &param);

double angle3Vertices(const MVertex *p1, const MVertex *p2, const MVertex *p3);

inline double distance(MVertex *v1, MVertex *v2)
{
  const double dx = v1->x() - v2->x();
  const double dy = v1->y() - v2->y();
  const double dz = v1->z() - v2->z();
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

#endif
