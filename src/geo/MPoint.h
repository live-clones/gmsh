// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MPOINT_H
#define MPOINT_H

#include "MElement.h"
#include "BasisFactory.h"

/*
 * MPoint
 *
 */
class MPoint : public MElement {
protected:
  MVertex *_v[1];

public:
  MPoint(MVertex *v0, int num = 0, int part = 0) : MElement(num, part)
  {
    _v[0] = v0;
  }
  MPoint(const std::vector<MVertex *> &v, int num = 0, int part = 0)
    : MElement(num, part)
  {
    _v[0] = v[0];
  }
  ~MPoint() {}
  virtual int getDim() const { return 0; }
  virtual std::size_t getNumVertices() const { return 1; }
  virtual MVertex *getVertex(int num) { return _v[0]; }
  virtual const MVertex *getVertex(int num) const { return _v[0]; }
  virtual void setVertex(int num, MVertex *v) { _v[0] = v; }
  virtual int getNumEdges() const { return 0; }
  virtual MEdge getEdge(int num) const { return MEdge(); }
  virtual int getNumEdgesRep(bool curved) { return 0; }
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
  }
  virtual int getNumFaces() { return 0; }
  virtual MFace getFace(int num) const { return MFace(); }
  virtual int getNumFacesRep(bool curved) { return 0; }
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
  {
  }
  virtual int getType() const { return TYPE_PNT; }
  virtual int getTypeForMSH() const { return MSH_PNT; }
  virtual int getTypeForVTK() const { return 1; }
  virtual const char *getStringForPOS() const { return "SP"; }
  virtual void getNode(int num, double &u, double &v, double &w) const
  {
    u = v = w = 0.;
  }
  virtual SPoint3 barycenterUVW() const { return SPoint3(0., 0., 0.); }
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int o) const
  {
    s[0] = 1.;
  }
  virtual void getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int o) const
  {
    s[0][0] = s[0][1] = s[0][2] = 0.;
  }
  virtual const JacobianBasis *getJacobianFuncSpace(int o) const
  {
    return BasisFactory::getJacobianBasis(MSH_PNT);
  }
  virtual bool isInside(double u, double v, double w) const
  {
    double tol = getTolerance();
    if(fabs(u) > tol || fabs(v) > tol || fabs(w) > tol) return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
  {
    static IntPt GQL[1];
    GQL[0].pt[0] = 0;
    GQL[0].pt[1] = 0;
    GQL[0].pt[2] = 0;
    GQL[0].weight = 1;
    *npts = 1;
    *pts = GQL;
  }
  virtual int numCommonNodesInDualGraph(const MElement *const other) const
  {
    return 1;
  }
};

#endif
