#ifndef _DISCRETE_VERTEX_H_
#define _DISCRETE_VERTEX_H_

#include "GModel.h"
#include "GVertex.h"
#include "MVertex.h"

class discreteVertex : public GVertex {
 private:
  double _x, _y, _z;
 public:
  discreteVertex(GModel *m, int num, double x, double y, double z)
    : GVertex(m, num), _x(x), _y(y), _z(z)
  {
    mesh_vertices.push_back(new MVertex(x, y, z, this));
  }
  discreteVertex(GModel *m, int num) : GVertex(m, num) {}
  virtual ~discreteVertex() {}
  virtual GPoint point() const { return GPoint(_x, _y, _z); }
  virtual double x() const { return _x; }
  virtual double y() const { return _y; }
  virtual double z() const { return _z; }
};

#endif
