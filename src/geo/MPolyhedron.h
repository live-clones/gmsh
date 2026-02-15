// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOLYHEDRON_H
#define MPOLYHEDRON_H

#include "MElement.h"

class MPolyhedron : public MElement {
private:
  std::vector<std::vector<MVertex *>> _vertices;
  std::vector<MVertex *> _tetrahedra;

public:
  MPolyhedron(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
  }
  ~MPolyhedron()
  {
  }
  virtual int getDim() const { return 3; }
  virtual std::size_t getNumVertices() const
  {
    // TODO
    return 0;
  }
  virtual MVertex *getVertex(int num)
  {
    // TODO
    return nullptr;
  }
  virtual const MVertex *getVertex(int num) const
  {
    // TODO
    return nullptr;
  }
  virtual int getNumEdges() const
  {
    // TODO
    return 0;
  }
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
  virtual int getNumFaces() { return _vertices.size(); }
  virtual MFace getFace(int num) const { return MFace(_vertices[num]); }
  virtual int getNumFacesRep(bool curved)
  {
    // TODO
    return 0;
  }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
    // TODO
  }
  virtual int getType() const { return TYPE_POLYH; }
  virtual int getTypeForMSH() const { return MSH_POLYH_; }
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
