// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYGON_H
#define MPOLYGON_H

#include "MElement.h"

class MPolygon : public MElement {
private:
  std::vector<MVertex *> _v, _tri;

public:
  MPolygon(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part), _v(v)
  {
  }
  ~MPolygon()
  {
  }
  virtual int getDim() const { return 2; }
  virtual std::size_t getNumVertices() const { return _v.size(); }
  virtual MVertex *getVertex(int num) { return _v[num]; }
  virtual const MVertex *getVertex(int num) const { return _v[num]; }
  virtual int getNumEdges() const { return _v.size(); }
  virtual MEdge getEdge(int num) const
  {
    if(num < (int)_v.size() - 1) return MEdge(_v[num], _v[num + 1]);
    return MEdge(_v[num - 1], _v[0]);
  }
  virtual int getNumEdgesRep(bool curved) { return getNumEdges(); }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    MEdge e = getEdge(num);
    for(int i = 0; i < 2; i++) {
      x[i] = e.getVertex(i)->x();
      y[i] = e.getVertex(i)->y();
      z[i] = e.getVertex(i)->z();
      n[i] = SVector3(0., 0., 1.); // TODO
    }
  }
  virtual int getNumFaces() { return 1; }
  virtual MFace getFace(int num) const { return MFace(_v); }
  virtual int getNumFacesRep(bool curved)
  {
    return _tri.size() / 3;
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    _getFaceRep(_v[3 * num], _v[3 * num + 1], _v[3 * num + 2], x, y, z, n);
  }
  virtual int getType() const { return TYPE_POLYG; }
  virtual int getTypeForMSH() const { return MSH_POLYG_; }
  virtual bool isInside(double u, double v, double w) const
  {
    return false; // TODO
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }
};

#endif
