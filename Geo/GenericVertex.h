// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GENERIC_VERTEX_H_
#define _GENERIC_VERTEX_H_

#include "GmshConfig.h"
#include "GModel.h"
#include "GVertex.h"
#include <vector>

using namespace std;

/* The set of Generic Entities is a generic interface to any other modeler.
  Callbacks (function pointers) are given, sending requests, enquiries, to the
  native modeler. */

class GenericVertex : public GVertex {
 protected:
  int id;
  double _x, _y, _z;
 public:
  // callbacks typedef
  typedef bool (*ptrfunction_int_vector)(int, vector<double>&);

  GenericVertex(GModel *m, int num, int _native_id);
  virtual ~GenericVertex();

  virtual GPoint point() const { return GPoint(x(), y(), z()); }
  virtual double x() const { return _x; }
  virtual double y() const { return _y; }
  virtual double z() const { return _z; }

  virtual void setPosition(GPoint &p);
  virtual SPoint2 reparamOnFace(const GFace *gf, int) const;

  ModelType getNativeType() const { return GenericModel; }
  virtual int getNativeInt()const{return id;};

  // sets the callbacks
  static void setVertexXYZ(ptrfunction_int_vector fct){VertexXYZ = fct;};

private:
  // the callbacks:
  // fills vector xyz for vertex of int id
  static ptrfunction_int_vector VertexXYZ;
};

#endif
