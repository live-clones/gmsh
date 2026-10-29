// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_EDGE_H
#define DISCRETE_EDGE_H

#include <map>
#include "GModel.h"
#include "GEdge.h"

class discreteEdge : public GEdge {
private:
  std::vector<double> _pars;
  std::vector<SPoint3> _discretization;
  // the parameters of the points of the discretization on surfaces, on both
  // sides of those of which the curve is a seam
  std::map<const GFace *, std::vector<SPoint2> > _onFace[2];
  ModelType _nativeType = UnknownModel;
  bool _getLocalParameter(const double &t, int &iEdge, double &tLoc) const;

public:
  // (geo: also create the curve in the GEO internals, so that scripts can
  // refer to it)
  discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1,
               bool geo = true);
  discreteEdge(GModel *model, int num, bool geo = true);
  discreteEdge(GModel *model);
  virtual ~discreteEdge() {}
  virtual GeomType geomType() const { return DiscreteCurve; }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature(double par) const;
  virtual bool haveParametrization() { return !_pars.empty(); }
  virtual Range<double> parBounds(int) const;
  int createGeometry();
  virtual void mesh(bool verbose);
  int minimumDrawSegments() const { return 2 * _pars.size(); }
  virtual int minimumMeshSegments() const;
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;
  // the parameters of the points of the discretization on the surface face,
  // instead of their closest points; on its two sides (dir 1 and any other
  // value for reparamOnFace) if the curve is a seam of the surface
  void setReparamOnFace(const GFace *face, const std::vector<SPoint2> &uv,
                        const std::vector<SPoint2> &otherSide =
                          std::vector<SPoint2>());
  virtual bool isSeam(const GFace *face) const
  {
    return _onFace[1].count(face) > 0;
  }
  bool writeParametrization(FILE *fp, bool binary);
  bool readParametrization(FILE *fp, bool binary);
  // UnknownModel, or the modeler that created the entity (the discrete CAD
  // modeler); a GEO synchronize removes the discrete entities of unknown
  // origin that the GEO internals do not hold
  void setNativeType(ModelType type) { _nativeType = type; }
  virtual ModelType getNativeType() const { return _nativeType; }
};

#endif
