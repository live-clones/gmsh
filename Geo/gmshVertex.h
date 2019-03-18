// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_VERTEX_H
#define GMSH_VERTEX_H

#include "GVertex.h"

class Vertex;

class gmshVertex : public GVertex {
protected:
  Vertex *v;

public:
  gmshVertex(GModel *m, Vertex *_v);
  virtual ~gmshVertex() {}
  virtual void resetMeshAttributes();
  virtual GPoint point() const;
  virtual double x() const;
  virtual double y() const;
  virtual double z() const;
  virtual void setPosition(GPoint &p);
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return v; }
  virtual void setPrescribedMeshSizeAtVertex(double l);
  virtual SPoint2 reparamOnFace(const GFace *gf, int) const;
  virtual void writeGEO(FILE *fp, const std::string &meshSizeParameter = "");
  void resetNativePtr(Vertex *_v);
};

#endif
