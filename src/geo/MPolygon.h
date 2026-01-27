// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYGON_H
#define MPOLYGON_H

#include "MElement.h"

class MPolygon : public MElement {
private:
  std::vector<MVertex *> _vertices;
  std::vector<MVertex *> _triangles;

public:
  MPolygon(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
  }
  ~MPolygon()
  {
  }
  virtual int getDim() const { return 2; }
  virtual std::size_t getNumVertices() const { return _vertices.size(); }
  virtual MVertex *getVertex(int num) { return _vertices[num]; }
  virtual const MVertex *getVertex(int num) const { return _vertices[num]; }
  virtual int getNumEdges() const { return _vertices.size() - 1; }
  virtual MEdge getEdge(int num) const
  {
    // TODO
    return MEdge();
  }
  virtual int getNumEdgesRep(bool curved) { return getNumEdges(); }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    // TODO
  }
  virtual int getNumFaces() { return 1; }
  virtual MFace getFace(int num) const { return MFace(_vertices); }
  virtual int getNumFacesRep(bool curved)
  {
    // TODO
    return 1;
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    // TODO
  }
  virtual int getType() const { return TYPE_POLYG; }
  virtual int getTypeForMSH() const { return MSH_POLYG_; }
  virtual bool isInside(double u, double v, double w) const
  {
    // TODO
    return false;
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }
};

#endif
