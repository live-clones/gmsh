// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MPOINT_H_
#define _MPOINT_H_

#include "MElement.h"

/*
 * MPoint
 *
 */
class MPoint : public MElement {
 protected:
  MVertex *_v[1];
 public :
  MPoint(MVertex *v0, int num=0, int part=0)
    : MElement(num, part)
  {
    _v[0] = v0;
  }
  MPoint(const std::vector<MVertex*> &v, int num=0, int part=0)
    : MElement(num, part)
  {
    _v[0] = v[0];
  }
  ~MPoint(){}
  virtual int getDim() const { return 0; }
  virtual int getNumVertices() const { return 1; }
  virtual MVertex *getVertex(int num){ return _v[0]; }
  virtual int getNumEdges(){ return 0; }
  virtual MEdge getEdge(int num){ return MEdge(); }
  virtual int getNumEdgesRep(){ return 0; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n){}
  virtual int getNumFaces(){ return 0; }
  virtual MFace getFace(int num){ return MFace(); }
  virtual int getNumFacesRep(){ return 0; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n){}
  virtual int getType() const { return TYPE_PNT; }
  virtual int getTypeForMSH() const { return MSH_PNT; }
  virtual int getTypeForVTK() const { return 1; }
  virtual const char *getStringForPOS() const { return "SP"; }
  void getNode(int num, double &u, double &v, double &w)
  {
    u = v = w = 0.;
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o)
  {
    s[0] = 1.;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o)
  {
    s[0][0] = s[0][1] = s[0][2] = 0.;
  }
  virtual const polynomialBasis* getFunctionSpace(int o) const
  {
    return polynomialBases::find(MSH_PNT);
  }
  virtual const JacobianBasis* getJacobianFuncSpace(int o) const
  {
    return JacobianBases::find(MSH_PNT);
  }
  virtual bool isInside(double u, double v, double w)
  {
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
};

#endif
