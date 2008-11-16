// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MELEMENT_H_
#define _MELEMENT_H_

#include <stdio.h>
#include <algorithm>
#include <string>
#include "GmshDefines.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MFace.h"
#include "GmshMessage.h"
#include "FunctionSpace.h"

struct IntPt{
  double pt[3];
  double weight;
};

class GFace;

// A mesh element.
class MElement 
{
 private:
  // the maximum element id number in the mesh
  static int _globalNum;
  // the id number of the element (this number is unique and is
  // guaranteed never to change once a mesh has been generated)
  int _num;
  // the number of the mesh partition the element belongs to
  short _partition;
  // a visibility flag
  char _visible;
 protected:
  void _getEdgeRep(MVertex *v0, MVertex *v1, 
                   double *x, double *y, double *z, SVector3 *n,
                   int faceIndex=-1);
  void _getFaceRep(MVertex *v0, MVertex *v1, MVertex *v2, 
                   double *x, double *y, double *z, SVector3 *n);
 public :
  MElement(int num=0, int part=0) : _visible(1) 
  {
    if(num){
      _num = num;
      _globalNum = std::max(_globalNum, _num);
    }
    else{
      _num = ++_globalNum;
    }
    _partition = (short)part; 
  }
  virtual ~MElement(){}

  // reset the global node number
  static void resetGlobalNumber(){ _globalNum = 0; }

  // return the tag of the element
  virtual int getNum(){ return _num; }

  // return the geometrical dimension of the element
  virtual int getDim() = 0;

  // return the polynomial order the element
  virtual int getPolynomialOrder() const { return 1; }

  // get/set the partition to which the element belongs
  virtual int getPartition(){ return _partition; }
  virtual void setPartition(int num){ _partition = (short)num; }

  // get/set the visibility flag
  virtual char getVisibility();
  virtual void setVisibility(char val){ _visible = val; }

  // get the vertices
  virtual int getNumVertices() const = 0;
  virtual MVertex *getVertex(int num) = 0;

  // get the vertex using the I-deas UNV ordering
  virtual MVertex *getVertexUNV(int num){ return getVertex(num); }

  // get the vertex using the VTK ordering
  virtual MVertex *getVertexVTK(int num){ return getVertex(num); }

  // get the vertex using the Nastran BDF ordering
  virtual MVertex *getVertexBDF(int num){ return getVertex(num); }

  // get the vertex using MED ordering
  virtual MVertex *getVertexMED(int num){ return getVertex(num); }

  // get the vertex using DIFF ordering
  virtual MVertex *getVertexDIFF(int num){ return getVertex(num); }

  // get the number of vertices associated with edges, faces and
  // volumes (nonzero only for higher order elements)
  virtual int getNumEdgeVertices() const { return 0; }
  virtual int getNumFaceVertices() const { return 0; }
  virtual int getNumVolumeVertices() const { return 0; }

  // get the number of primary vertices (first-order element)
  int getNumPrimaryVertices()
  {
    return getNumVertices() - getNumEdgeVertices() - getNumFaceVertices() -
      getNumVolumeVertices();
  }

  // get the edges
  virtual int getNumEdges() = 0;
  virtual MEdge getEdge(int num) = 0;

  // get an edge representation for drawing
  virtual int getNumEdgesRep() = 0;
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n) = 0;

  // get all the vertices on an edge
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(0);
  }

  // get the faces
  virtual int getNumFaces() = 0;
  virtual MFace getFace(int num) = 0;

  // get a face representation for drawing
  virtual int getNumFacesRep() = 0;
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n) = 0;

  // get all the vertices on a face
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(0);
  }

  // get the max/min edge length
  virtual double maxEdge();
  virtual double minEdge();

  // get the quality measures
  virtual double rhoShapeMeasure();
  virtual double gammaShapeMeasure(){ return 0.; }
  virtual double etaShapeMeasure(){ return 0.; }
  virtual double distoShapeMeasure(){ return 1.0; }

  // compute the barycenter
  virtual SPoint3 barycenter();

  // revert the orientation of the element
  virtual void revert(){}

  // compute and change the orientation of 3D elements to get
  // positive volume
  virtual double getVolume(){ return 0.; }
  virtual int getVolumeSign(){ return 1; }
  virtual void setVolumePositive(){ if(getVolumeSign() < 0) revert(); }
  
  // return an information string for the element
  virtual std::string getInfoString();

  // get the function space for the element
  virtual const gmshFunctionSpace* getFunctionSpace(int order=-1) const
  {
    Msg::Error("Function space not implemented for this type of element");
    return 0;
  }
  
  // return the interpolating nodal shape functions evaluated at point
  // (u,v,w) in parametric coordinates (if order == -1, use the
  // polynomial order of the element)
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int order=-1);

  // return the gradient of of the nodal shape functions evaluated at
  // point (u,v,w) in parametric coordinates (if order == -1, use the
  // polynomial order of the element)
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3],
                                     int order=-1);
  
  // return the Jacobian of the element evaluated at point (u,v,w) in
  // parametric coordinates
  double getJacobian(double u, double v, double w, double jac[3][3]);
  double getPrimaryJacobian(double u, double v, double w, double jac[3][3]);
  
  // get the point in cartesian coordinates corresponding to the point
  // (u,v,w) in parametric coordinates
  virtual void pnt(double u, double v, double w, SPoint3 &p);
  virtual void primaryPnt(double u, double v, double w, SPoint3 &p);
  
  // invert the parametrisation
  virtual void xyz2uvw(double xyz[3], double uvw[3]);

  // test if a point, given in parametric coordinates, belongs to the
  // element
  virtual bool isInside(double u, double v, double w, double tol=1.e-8) = 0;

  // interpolate the given nodal data (resp. its gradient, curl and
  // divergence) at point (u,v,w) in parametric coordinates
  double interpolate(double val[], double u, double v, double w, int stride=1, 
                     int order=-1);
  void interpolateGrad(double val[], double u, double v, double w, double f[3],
                       int stride=1, double invjac[3][3]=0, int order=-1);
  void interpolateCurl(double val[], double u, double v, double w, double f[3],
                       int stride=3, int order=-1);
  double interpolateDiv(double val[], double u, double v, double w, int stride=3,
                        int order=-1);

  // integration routine 
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
  {
    Msg::Error("No integration points defined for this type of element");
  }

  // IO routines
  virtual void writeMSH(FILE *fp, double version=1.0, bool binary=false, 
                        int num=0, int elementary=1, int physical=1);
  virtual void writePOS(FILE *fp, bool printElementary, bool printElementNumber, 
                        bool printGamma, bool printEta, bool printRho, 
                        bool printDisto,double scalingFactor=1.0, int elementary=1);
  virtual void writeSTL(FILE *fp, bool binary=false, double scalingFactor=1.0);
  virtual void writeVRML(FILE *fp);
  virtual void writeUNV(FILE *fp, int num=0, int elementary=1, int physical=1);
  virtual void writeVTK(FILE *fp, bool binary=false, bool bigEndian=false);
  virtual void writeMESH(FILE *fp, int elementary=1);
  virtual void writeBDF(FILE *fp, int format=0, int elementary=1);
  virtual void writeDIFF(FILE *fp, int num, bool binary=false, int physical_property=1);
 
  // info for specific IO formats (returning 0 means that the element
  // is not implemented in that format)
  virtual int getTypeForMSH() const { return 0; }
  virtual int getTypeForUNV() const { return 0; }
  virtual int getTypeForVTK() const { return 0; }
  virtual const char *getStringForPOS() const { return 0; }
  virtual const char *getStringForBDF() const { return 0; }
  virtual const char *getStringForDIFF() const { return 0; }

  // return the number of vertices, as well as the element name if
  // 'name' != 0
  static int getInfoMSH(const int typeMSH, const char **const name=0);
};

class MElementLessThanLexicographic{
 public:
  static double tolerance;
  bool operator()(MElement *e1, MElement *e2) const
  {
    SPoint3 b1 = e1->barycenter();
    SPoint3 b2 = e2->barycenter();
    if(b1.x() - b2.x() >  tolerance) return true;
    if(b1.x() - b2.x() < -tolerance) return false;
    if(b1.y() - b2.y() >  tolerance) return true;
    if(b1.y() - b2.y() < -tolerance) return false;
    if(b1.z() - b2.z() >  tolerance) return true;
    return false;
  }
};

class MElementFactory{
 public:
  MElement *create(int type, std::vector<MVertex*> &v, int num=0, int part=0);
};

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
  MPoint(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v[0];
  }
  ~MPoint(){}
  virtual int getDim(){ return 0; }
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
  virtual int getTypeForMSH() const { return MSH_PNT; }
  virtual int getTypeForVTK() const { return 1; }
  virtual const char *getStringForPOS() const { return "SP"; }
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    s[0] = 1.;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    s[0][0] = s[0][1] = s[0][2] = 0.;
  }
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    return true;
  }
};

/*
 * MLine
 *
 *   0----------1 --> u
 *
 */
class MLine : public MElement {
 protected:
  MVertex *_v[2];
  void _getEdgeVertices(std::vector<MVertex*> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
  }
 public :
  MLine(MVertex *v0, MVertex *v1, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1;
  }
  MLine(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 2; i++) _v[i] = v[i];
  }
  ~MLine(){}
  virtual int getDim(){ return 1; }
  virtual int getNumVertices() const { return 2; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 1; }
  virtual MEdge getEdge(int num){ return MEdge(_v[0], _v[1]); }
  virtual int getNumEdgesRep(){ return 1; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    _getEdgeRep(_v[0], _v[1], x, y, z, n);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(v);
  }
  virtual int getNumFaces(){ return 0; }
  virtual MFace getFace(int num){ return MFace(); }
  virtual int getNumFacesRep(){ return 0; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n){}
  virtual int getTypeForMSH() const { return MSH_LIN_2; }
  virtual int getTypeForUNV() const { return 21; } // linear beam
  virtual int getTypeForVTK() const { return 3; }
  virtual const char *getStringForPOS() const { return "SL"; }
  virtual const char *getStringForBDF() const { return "CBAR"; }
  virtual void revert() 
  {
    MVertex *tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
  }
  virtual const gmshFunctionSpace* getFunctionSpace(int o=-1) const;
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    if(u < -(1. + tol) || u > (1. + tol))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const;
};

/*
 * MLine3
 *
 *   0-----2----1
 *
 */
class MLine3 : public MLine {
 protected:
  MVertex *_vs[1];
 public :
  MLine3(MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0) 
    : MLine(v0, v1, num, part)
  {
    _vs[0] = v2;
    _vs[0]->setPolynomialOrder(2);
  }
  MLine3(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MLine(v, num, part)
  {
    _vs[0] = v[2];
    _vs[0]->setPolynomialOrder(2);
  }
  ~MLine3(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 3; }
  virtual MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[3] = {0, 2, 1};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 1; }
  virtual int getNumEdgesRep(){ return 2; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[2][2] = {
      {0, 2}, {2, 1}
    };
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MLine::_getEdgeVertices(v);
    v[2] = _vs[0];
  }
  virtual int getTypeForMSH() const { return MSH_LIN_3; }
  virtual int getTypeForUNV() const { return 24; } // parabolic beam
  //virtual int getTypeForVTK() const { return 21; }
  virtual const char *getStringForPOS() const { return "SL2"; }
};

/*
 * MLineN
 *
 *   0---2---...-(N-1)-1
 *
 */
class MLineN : public MLine {
 protected:
  std::vector<MVertex *> _vs;
 public :
  MLineN(MVertex *v0, MVertex *v1, const std::vector<MVertex*> &vs, int num=0, int part=0) 
    : MLine(v0, v1, num, part), _vs(vs)
  {
    for(unsigned int i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_vs.size() + 1);
  }
  MLineN(const std::vector<MVertex*> &v, int num=0, int part=0) 
    : MLine(v[0] , v[1], num, part)
  {
    for(unsigned int i = 2; i < v.size(); i++)
      _vs.push_back(v[i]);
    for(unsigned int i = 0; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_vs.size() + 1);
  }
  ~MLineN(){}
  virtual int getPolynomialOrder() const { return _vs.size() + 1; }
  virtual int getNumVertices() const { return _vs.size() + 2; }
  virtual MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  virtual int getNumEdgeVertices() const { return _vs.size(); }
  virtual int getNumEdgesRep(){ return _vs.size() + 1; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    _getEdgeRep(getVertex((num == 0) ? 0 : num + 1), 
                getVertex((num == getNumEdgesRep() - 1) ? 1 : num + 2),
                x, y, z, n);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2 + _vs.size());
    MLine::_getEdgeVertices(v);
    for(unsigned int i = 0; i != _vs.size(); ++i) v[i+2] = _vs[i];
  }
  virtual int getTypeForMSH() const 
  { 
    if(_vs.size() == 2) return MSH_LIN_4; 
    if(_vs.size() == 3) return MSH_LIN_5; 
    if(_vs.size() == 4) return MSH_LIN_6; 
    return 0;
  }
};

/* 
 * MTriangle
 *
 *   v
 *   ^
 *   |
 *   2
 *   |`\
 *   |  `\
 *   |    `\
 *   |      `\
 *   |        `\
 *   0----------1 --> u
 *
 */
class MTriangle : public MElement {
 protected:
  MVertex *_v[3];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_tri(num, 0)];
    v[1] = _v[edges_tri(num, 1)];
  }
  void _getFaceVertices(std::vector<MVertex*> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
    v[2] = _v[2];
  }
 public :
  MTriangle(MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2;
  }
  MTriangle(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 3; i++) _v[i] = v[i];
  }
  ~MTriangle(){}
  virtual int getDim(){ return 2; }
  virtual double gammaShapeMeasure();
  virtual double distoShapeMeasure();
  virtual int getNumVertices() const { return 3; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[3] = {0, 2, 1};
    return getVertex(map[num]); 
  }
  virtual MVertex *getOtherVertex(MVertex *v1, MVertex *v2)
  { 
    if(_v[0] != v1 && _v[0] != v2) return _v[0];
    if(_v[1] != v1 && _v[1] != v2) return _v[1];
    if(_v[2] != v1 && _v[2] != v2) return _v[2];
    return 0;
  }
  virtual int getNumEdges(){ return 3; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_tri(num, 0)], _v[edges_tri(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 3; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num)
  { 
    return MFace(_v[0], _v[1], _v[2]); 
  }
  virtual int getNumFacesRep(){ return 1; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    _getFaceRep(_v[0], _v[1], _v[2], x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    _getFaceVertices(v);
  }
  virtual int getTypeForMSH() const { return MSH_TRI_3; }
  virtual int getTypeForUNV() const { return 91; } // thin shell linear triangle
  virtual int getTypeForVTK() const { return 5; }
  virtual const char *getStringForPOS() const { return "ST"; }
  virtual const char *getStringForBDF() const { return "CTRIA3"; }
  virtual const char *getStringForDIFF() const { return "ElmT3n2D"; }
  virtual void revert() 
  {
    MVertex *tmp = _v[1]; _v[1] = _v[2]; _v[2] = tmp;
  }
  virtual const gmshFunctionSpace* getFunctionSpace(int o=-1) const;
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    if(u < (-tol) || v < (-tol) || u > ((1. + tol) - v))
      return false; 
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const;
  virtual SPoint3 circumcenter();
 private:
  int edges_tri(const int edge, const int vert) const
  {
    static const int e[3][2] = {
      {0, 1},
      {1, 2},
      {2, 0}
    };
    return e[edge][vert];
  }
};

/*
 * MTriangle6
 *
 *   2
 *   |`\
 *   |  `\
 *   5    `4
 *   |      `\
 *   |        `\
 *   0-----3----1
 *
 */
class MTriangle6 : public MTriangle {
 protected:
  MVertex *_vs[3];
 public :
  MTriangle6(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
             MVertex *v5, int num=0, int part=0) 
    : MTriangle(v0, v1, v2, num, part)
  {
    _vs[0] = v3; _vs[1] = v4; _vs[2] = v5;
    for(int i = 0; i < 3; i++) _vs[i]->setPolynomialOrder(2);
  }
  MTriangle6(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MTriangle(v, num, part)
  {
    for(int i = 0; i < 3; i++) _vs[i] = v[3 + i];
    for(int i = 0; i < 3; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MTriangle6(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 6; }
  virtual MVertex *getVertex(int num){ return num < 3 ? _v[num] : _vs[num - 3]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[6] = {0, 3, 1, 4, 2, 5};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[6] = {0, 2, 1, 5, 4, 3};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 3; }
  virtual int getNumEdgesRep(){ return 6; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int e[6][2] = {
      {0, 3}, {3, 1},
      {1, 4}, {4, 2},
      {2, 5}, {5, 0}
    }; 
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, 0);
  } 
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MTriangle::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 4; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[4][3] = {
      {0, 3, 5}, {1, 4, 3}, {2, 5, 4}, {3, 4, 5}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(6);
    MTriangle::_getFaceVertices(v);
    v[3] = _vs[0];
    v[4] = _vs[1];
    v[5] = _vs[2];
  }
  virtual int getTypeForMSH() const { return MSH_TRI_6; }
  virtual int getTypeForUNV() const { return 92; } // thin shell parabolic triangle
  //virtual int getTypeForVTK() const { return 22; }
  virtual const char *getStringForPOS() const { return "ST2"; }
  virtual const char *getStringForBDF() const { return "CTRIA6"; }
  virtual const char *getStringForDIFF() const { return "ElmT6n2D"; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[2]; _vs[2] = tmp;
  }
};

/*
 * MTriangleN  FIXME: check the plot
 *
 *   2
 *   |`\                E = order - 1;
 *   |  `\              N = total number of vertices
 * 3+2E   2+2E
 *   |      `\          Interior vertex numbers
 *  ...       ...         for edge 0 <= i <= 2: 3+i*E to 2+(i+1)*E
 *   |          `\        in volume           : 3+3*E to N-1
 * 2+3E           3+E
 *   |  3+3E to N-1 `\
 *   |                `\
 *   0---3--...---2+E---1
 *
 */
class MTriangleN : public MTriangle {
 protected:
  std::vector<MVertex *> _vs;
  const short _order;
  int _orderedIndex(int num)
  {
    if(num == 0) return 0;
    else if(num < _order) return num + 2;
    else if(num == _order) return 1;
    else if(num < 2 * _order) return num + 1;
    else if(num == 2 * _order) return 2;
    else return num;
  }
 public:
  MTriangleN(MVertex *v0, MVertex *v1, MVertex *v2, 
             std::vector<MVertex*> &v, int order, int num=0, int part=0) 
    : MTriangle(v0, v1, v2, num, part) , _vs (v), _order(order)
  {
    for(unsigned int i = 0; i < _vs.size(); i++) _vs[i]->setPolynomialOrder(_order);
  }
  MTriangleN(std::vector<MVertex*> &v, int order, int num=0, int part=0) 
    : MTriangle(v[0], v[1], v[2], num, part) , _order(order)
  {
    for(unsigned int i = 3; i < v.size(); i++) _vs.push_back(v[i]);
    for(unsigned int i = 0; i < _vs.size(); i++) _vs[i]->setPolynomialOrder(_order);
  }
  ~MTriangleN(){}
  virtual int getPolynomialOrder() const { return _order; }
  virtual int getNumVertices() const { return 3 + _vs.size(); }
  virtual MVertex *getVertex(int num){ return num < 3 ? _v[num] : _vs[num - 3]; }
  virtual int getNumFaceVertices() const 
  {
    if(_order == 3 && _vs.size() == 6) return 0;
    if(_order == 3 && _vs.size() == 7) return 1;
    if(_order == 4 && _vs.size() == 9) return 0;
    if(_order == 4 && _vs.size() == 12) return 3;
    if(_order == 5 && _vs.size() == 12) return 0;
    if(_order == 5 && _vs.size() == 18) return 6;
    return 0;
  }
  virtual int getNumEdgeVertices() const { return 3 * (_order - 1); }
  virtual int getNumEdgesRep();
  virtual int getNumFacesRep();
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n);
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(_order + 1);
    MTriangle::_getEdgeVertices(num, v);
    int j = 2;
    const int ie = (num + 1) * (_order - 1);
    for(int i = num * (_order-1); i != ie; ++i) v[j++] = _vs[i];
  }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n);
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3 + _vs.size());
    MTriangle::_getFaceVertices(v);
    for(unsigned int i = 0; i != _vs.size(); ++i) v[i + 3] = _vs[i];
  }
  virtual int getTypeForMSH() const
  {
    if(_order == 3 && _vs.size() == 6) return MSH_TRI_9; 
    if(_order == 3 && _vs.size() == 7) return MSH_TRI_10; 
    if(_order == 4 && _vs.size() == 9) return MSH_TRI_12; 
    if(_order == 4 && _vs.size() == 12) return MSH_TRI_15; 
    if(_order == 5 && _vs.size() == 12) return MSH_TRI_15I; 
    if(_order == 5 && _vs.size() == 18) return MSH_TRI_21;
    return 0;
  }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[2]; _v[2] = tmp;
    std::vector<MVertex*> inv;
    inv.insert(inv.begin(), _vs.rbegin(), _vs.rend());
    _vs = inv;
  }
};

/*
 * MQuadrangle
 *
 *         v
 *         ^
 *         |
 *   3-----------2
 *   |     |     |
 *   |     |     |
 *   |     +---- | --> u
 *   |           |
 *   |           |
 *   0-----------1 
 *
 */
class MQuadrangle : public MElement {
 protected:
  MVertex *_v[4];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_quad(num, 0)];
    v[1] = _v[edges_quad(num, 1)];
  }
  void _getFaceVertices(std::vector<MVertex*> &v) const
  {
    v[0] = _v[0];
    v[1] = _v[1];
    v[2] = _v[2];
    v[3] = _v[3];
  }
 public :
  MQuadrangle(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
  }
  MQuadrangle(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 4; i++) _v[i] = v[i];
  }
  ~MQuadrangle(){}
  virtual int getDim(){ return 2; }
  virtual int getNumVertices() const { return 4; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[4] = {0, 3, 2, 1};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[4] = {0, 1, 3, 2};
    return getVertex(map[num]); 
  }
  virtual int getNumEdges(){ return 4; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_quad(num, 0)], _v[edges_quad(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 4; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num){ return MFace(_v[0], _v[1], _v[2], _v[3]); }
  virtual int getNumFacesRep(){ return 2; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[2][3] = {
      {0, 1, 2}, {0, 2, 3}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(4);
    _getFaceVertices(v);
  }
  virtual int getTypeForMSH() const { return MSH_QUA_4; }
  virtual int getTypeForUNV() const { return 94; } // thin shell linear quadrilateral
  virtual int getTypeForVTK() const { return 9; }
  virtual const char *getStringForPOS() const { return "SQ"; }
  virtual const char *getStringForBDF() const { return "CQUAD4"; }
  virtual const char *getStringForDIFF() const { return "ElmB4n2D"; }
  virtual void revert() 
  {
    MVertex *tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
  }
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    s[0] = (1. - u) * (1. - v) * 0.25;
    s[1] = (1. + u) * (1. - v) * 0.25;
    s[2] = (1. + u) * (1. + v) * 0.25;
    s[3] = (1. - u) * (1. + v) * 0.25;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    s[0][0] = -0.25 * (1. - v); s[0][1] = -0.25 * (1. - u); s[0][2] = 0.;
    s[1][0] =  0.25 * (1. - v); s[1][1] = -0.25 * (1. + u); s[1][2] = 0.;
    s[2][0] =  0.25 * (1. + v); s[2][1] =  0.25 * (1. + u); s[2][2] = 0.;
    s[3][0] = -0.25 * (1. + v); s[3][1] =  0.25 * (1. - u); s[3][2] = 0.;
  }
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    if(u < -(1. + tol) || v < -(1. + tol) || u > (1. + tol) || v > (1. + tol))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const;
 private:
  int edges_quad(const int edge, const int vert) const
  {
    static const int e[4][2] = {
      {0, 1},
      {1, 2},
      {2, 3},
      {3, 0}
    };
    return e[edge][vert];
  }
};

/*
 * MQuadrangle8
 *
 *   3-----6-----2
 *   |           |
 *   |           |
 *   7           5
 *   |           |
 *   |           |
 *   0-----4-----1 
 *
 */
class MQuadrangle8 : public MQuadrangle {
 protected:
  MVertex *_vs[4];
 public :
  MQuadrangle8(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
               MVertex *v5, MVertex *v6, MVertex *v7, int num=0, int part=0) 
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _vs[1] = v5; _vs[2] = v6; _vs[3] = v7;
    for(int i = 0; i < 4; i++) _vs[i]->setPolynomialOrder(2);
  }
  MQuadrangle8(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 4; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 4; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MQuadrangle8(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 8; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[8] = {0, 4, 1, 5, 2, 6, 3, 7};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[8] = {0, 3, 2, 1, 7, 6, 5, 4};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[8] = {0, 1, 3, 2, 4, 7, 5, 6};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 4; }
  virtual int getNumEdgesRep(){ return 8; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[8][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 3},
      {3, 7}, {7, 0}
    };
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MQuadrangle::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 6; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[6][3] = {
      {0, 4, 7}, {1, 5, 4}, {2, 6, 5}, {3, 7, 6}, {4, 5, 6}, {4, 6, 7}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(8);
    MQuadrangle::_getFaceVertices(v);
    v[4] = _vs[0];
    v[5] = _vs[1];
    v[6] = _vs[2];
    v[7] = _vs[3];
  }
  virtual int getTypeForMSH() const { return MSH_QUA_8; }
  virtual int getTypeForUNV() const { return 95; } // shell parabolic quadrilateral
  //virtual int getTypeForVTK() const { return 23; }
  virtual const char *getStringForBDF() const { return "CQUAD8"; }
  virtual const char *getStringForDIFF() const { return "ElmB8n2D"; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
  }
};

/*
 * MQuadrangle9
 *
 *   3-----6-----2
 *   |           |
 *   |           |
 *   7     8     5
 *   |           |
 *   |           |
 *   0-----4-----1 
 *
 */
class MQuadrangle9 : public MQuadrangle {
 protected:
  MVertex *_vs[5];
 public :
  MQuadrangle9(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
               MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, int num=0, int part=0) 
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _vs[1] = v5; _vs[2] = v6; _vs[3] = v7; _vs[4] = v8;
    for(int i = 0; i < 5; i++) _vs[i]->setPolynomialOrder(2);
  }
  MQuadrangle9(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 5; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 5; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MQuadrangle9(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 9; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[9] = {0, 2, 8, 6, 1, 5, 7, 3, 4};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 4; }
  virtual int getNumFaceVertices() const { return 6; }
  virtual int getNumEdgesRep(){ return 8; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[8][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 3},
      {3, 7}, {7, 0}
    };
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, 0);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MQuadrangle::getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 8; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[8][4] = {
      {0, 4, 8}, {0, 8, 7}, {1, 5, 8}, {1, 8, 4}, 
      {2, 6, 8}, {2, 8, 5}, {3, 7, 8}, {3, 8, 6}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(9);
    MQuadrangle::_getFaceVertices(v);
    v[4] = _vs[0];
    v[5] = _vs[1];
    v[6] = _vs[2];
    v[7] = _vs[3];
    v[8] = _vs[4];
  }
  virtual int getTypeForMSH() const { return MSH_QUA_9; }
  virtual const char *getStringForPOS() const { return "SQ2"; }
  virtual const char *getStringForDIFF() const { return "ElmB9n2D"; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
  }
};

/*
 * MTetrahedron
 *
 *                      v
 *                    .
 *                  ,/
 *                 /
 *              2
 *            ,/|`\
 *          ,/  |  `\
 *        ,/    '.   `\
 *      ,/       |     `\
 *    ,/         |       `\
 *   0-----------'.--------1 --> u
 *    `\.         |      ,/
 *       `\.      |    ,/
 *          `\.   '. ,/
 *             `\. |/
 *                `3
 *                   `\.
 *                      ` w
 *
 */
class MTetrahedron : public MElement {
 protected:
  MVertex *_v[4];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_tetra(num, 0)];
    v[1] = _v[edges_tetra(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[faces_tetra(num, 0)];
    v[1] = _v[faces_tetra(num, 1)];
    v[2] = _v[faces_tetra(num, 2)];
  }
 public :
  MTetrahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
  }
  MTetrahedron(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 4; i++) _v[i] = v[i];
  }
  ~MTetrahedron(){}
  virtual int getDim(){ return 3; }
  virtual int getNumVertices() const { return 4; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[4] = {0, 2, 1, 3};
    return getVertex(map[num]);
  }
  virtual int getNumEdges(){ return 6; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_tetra(num, 0)], _v[edges_tetra(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 6; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[6] = {0, 0, 0, 1, 2, 3};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 4; }
  virtual MFace getFace(int num)
  {
    return MFace(_v[faces_tetra(num, 0)],
		 _v[faces_tetra(num, 1)],
		 _v[faces_tetra(num, 2)]);
  }
  virtual int getNumFacesRep(){ return 4; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    MFace f(getFace(num));
    _getFaceRep(f.getVertex(0), f.getVertex(1), f.getVertex(2), x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    _getFaceVertices(num, v);
  }
  virtual int getTypeForMSH() const { return MSH_TET_4; }
  virtual int getTypeForUNV() const { return 111; } // solid linear tetrahedron
  virtual int getTypeForVTK() const { return 10; }
  virtual const char *getStringForPOS() const { return "SS"; }
  virtual const char *getStringForBDF() const { return "CTETRA"; }
  virtual const char *getStringForDIFF() const { return "ElmT4n3D"; }
  virtual void revert()
  {
    MVertex *tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
  }
  void getMat(double mat[3][3])
  {
    mat[0][0] = _v[1]->x() - _v[0]->x();
    mat[0][1] = _v[2]->x() - _v[0]->x();
    mat[0][2] = _v[3]->x() - _v[0]->x();
    mat[1][0] = _v[1]->y() - _v[0]->y();
    mat[1][1] = _v[2]->y() - _v[0]->y();
    mat[1][2] = _v[3]->y() - _v[0]->y();
    mat[2][0] = _v[1]->z() - _v[0]->z();
    mat[2][1] = _v[2]->z() - _v[0]->z();
    mat[2][2] = _v[3]->z() - _v[0]->z();
  }
  virtual double getVolume();
  virtual int getVolumeSign(){ return (getVolume() >= 0) ? 1 : -1; }
  virtual double gammaShapeMeasure();
  virtual double distoShapeMeasure();
  virtual double etaShapeMeasure();
  void xyz2uvw(double xyz[3], double uvw[3]);
  virtual const gmshFunctionSpace* getFunctionSpace(int o=-1) const;
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    if(u < (-tol) || v < (-tol) || w < (-tol) || u > ((1. + tol) - v - w))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const;
  virtual SPoint3 circumcenter();
 private:
  int edges_tetra(const int edge, const int vert) const
  {
    static const int e[6][2] = {
      {0, 1},
      {1, 2},
      {2, 0},
      {3, 0},
      {3, 2},
      {3, 1}
    };
    return e[edge][vert];
  }
  int faces_tetra(const int face, const int vert) const
  {
    static const int f[4][3] = {
      {0, 2, 1},
      {0, 1, 3},
      {0, 3, 2},
      {3, 1, 2}
    };
    return f[face][vert];
  }
};

/*
 * MTetrahedron10
 *
 *              2 
 *            ,/|`\
 *          ,/  |  `\
 *        ,6    '.   `5
 *      ,/       8     `\
 *    ,/         |       `\
 *   0--------4--'.--------1
 *    `\.         |      ,/
 *       `\.      |    ,9
 *          `7.   '. ,/
 *             `\. |/
 *                `3
 *
 */
class MTetrahedron10 : public MTetrahedron {
 protected:
  MVertex *_vs[6];
 public :
  MTetrahedron10(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
                 MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
                 int num=0, int part=0) 
    : MTetrahedron(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _vs[1] = v5; _vs[2] = v6; _vs[3] = v7; _vs[4] = v8; _vs[5] = v9;
    for(int i = 0; i < 6; i++) _vs[i]->setPolynomialOrder(2);
  }
  MTetrahedron10(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MTetrahedron(v, num, part)
  {
    for(int i = 0; i < 6; i++) _vs[i] = v[4 + i];
    for(int i = 0; i < 6; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MTetrahedron10(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 10; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[10] = {0, 4, 1, 5, 2, 6, 8, 9, 7, 3};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[10] = {0, 2, 1, 3, 6, 5, 4, 7, 8, 9};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 6; }
  virtual int getNumEdgesRep(){ return 12; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[12][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 0},
      {3, 7}, {7, 0},
      {3, 8}, {8, 2},
      {3, 9}, {9, 1}
    };
    static const int f[12] = {0, 0, 0, 1, 2, 3};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MTetrahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 16; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[16][3] = {
      {0, 6, 4}, {2, 5, 6}, {1, 4, 5}, {6, 5, 4},
      {0, 4, 7}, {1, 9, 4}, {3, 7, 9}, {4, 9, 7},
      {0, 7, 6}, {3, 8, 7}, {2, 6, 8}, {7, 8, 6},
      {3, 9, 8}, {1, 5, 9}, {2, 8, 5}, {9, 5, 8}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(6);
    MTetrahedron::_getFaceVertices(num, v);
    static const int f[4][3] = {
      {4, 5, 6},
      {4, 7, 9},
      {6, 7, 8},
      {5, 8, 9}
    };
    v[3] = _vs[f[num][0]];
    v[4] = _vs[f[num][1]];
    v[5] = _vs[f[num][2]];
  }
  virtual int getTypeForMSH() const { return MSH_TET_10; }
  virtual int getTypeForUNV() const { return 118; } // solid parabolic tetrahedron
  //virtual int getTypeForVTK() const { return 24; }
  virtual const char *getStringForPOS() const { return "SS2"; }
  virtual const char *getStringForBDF() const { return "CTETRA"; }
  virtual const char *getStringForDIFF() const { return "ElmT10n3D"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0] ; _v[0]  = _v[1]; _v[1] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
    tmp = _vs[5]; _vs[5] = _vs[3]; _vs[3] = tmp;
  }
};

/*
 * MTetrahedronN  FIXME: check the plot
 *
 *              2
 *            ,/|`\ 
 *          ,/  |  `\              E = order - 1
 *        ,/    '.   `\            C = 4 + 6*E 
 *      ,/       |     `\          F = ((order - 1)*(order - 2))/2
 *    ,/         |       `\	   N = total number of vertices
 *   0-----------'.--------1
 *    `\.         |      ,/        Interior vertex numbers  
 *       `\.      |    ,/            for edge 0 <= i <= 5: 4+i*E to 3+(i+1)*E
 *          `\.   '. ,/		     for face 0 <= j <= 3: C+j*F to C-1+(j+1)*F
 *             `\. |/		     in volume           : C+4*F to N-1
 *                `3
 *
 */



/* tet order 3
   
 *              2
 *            ,/|`\ 
 *          ,5  |  `6              E = order - 1
 *        ,/    12   `\            C = 4 + 6*E 
 *      ,4       |     `7          F = ((order - 1)*(order - 2))/2
 *    ,/         |       `\	   N = total number of vertices
 *   0-----9-----'.--8-----1
 *    `\.         |      ,/        Interior vertex numbers
 *       10.     13    ,14           for edge 0 <= i <= 5: 4+i*E to 3+(i+1)*E
 *          `\.   '. 15		     for face 0 <= j <= 3: C+j*F to C-1+(j+1)*F
 *             11\.|/ 	     in volume           : C+4*F to N-1
 *                `3
 *
 */

static int reverseTet20[20] = {0,2,1,3,  // principal vertices
                               9,8,      // E0 switches with E2
                               7,6,      // E1 inverts direction
                               5,4,      // E2 switches with E0
                               10,11,    // E3 pure w edge > remains the same
                               14,15,    // E4 uw edge swithes with v/w edge E5
                               12,13,    // E5 switches with E4
                               16,       // F0 is uv plane, reverts normal
                               18,       // F1 is uw plane, switches with F2
                               17,       // F2 is vw plane, switches with F1
                               19};      // F3 is uvw plane, reverts normal

static int reverseTet35[35] = {0,2,1,3,  // principal vertices
                               
                               12,11,10, // E0 switches with E2
                               9,8,7,    // E1 inverts direction
                               6,5,4,    // E2 switches with E0
                               13,14,15, // E3 pure w edge > remains the same
                               19,20,21, // E4 uw edge swithes with v/w edge E5
                               16,17,18, // E5 switches with E4
                               22,24,23, // F0 is uv plane, reverts normal
                               28,30,29, // F1 is uw plane, switches with F2, orientation is different
                               25,27,26, // F2 is vw plane, switches with F1
                               31,33,32, // F3 is uvw plane, reverts normal
                               34};      // central node remains 
  
static int reverseTet34[34] = {0,2,1,3,  // principal vertices
                               12,11,10, // E0 switches with E2
                               9,8,7,    // E1 inverts direction
                               6,5,4,    // E2 switches with E0
                               13,14,15, // E3 pure w edge > remains the same
                               19,20,21, // E4 uw edge swithes with v/w edge E5
                               16,17,18, // E5 switches with E4
                               22,24,23, // F0 is uv plane, reverts normal
                               28,29,30, // F1 is uw plane, switches with F2
                               25,26,27, // F2 is vw plane, switches with F1
                               31,33,32};// F3 is uvw plane, reverts normal

class MTetrahedronN : public MTetrahedron {
 protected:
  std::vector<MVertex *> _vs;
  const short _order;
  double _disto;
 public:
  MTetrahedronN(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, 
		std::vector<MVertex*> &v, int order, int num=0, int part=0) 
    : MTetrahedron(v0, v1, v2, v3, num, part) , _vs (v), _order(order),_disto(-1.e22)
  {
    for(unsigned int i = 0; i < _vs.size(); i++) _vs[i]->setPolynomialOrder(_order);
  }
  MTetrahedronN(std::vector<MVertex*> &v, int order, int num=0, int part=0) 
    : MTetrahedron(v[0], v[1], v[2], v[3], num, part) , _order(order),_disto(-1.e22)
  {
    for(unsigned int i = 4; i < v.size(); i++) _vs.push_back(v[i]);
    for(unsigned int i = 0; i < _vs.size(); i++) _vs[i]->setPolynomialOrder(_order);
  }
  ~MTetrahedronN(){}
  virtual double distoShapeMeasure();
  virtual int getPolynomialOrder() const { return _order; }
  virtual int getNumVertices() const { return 4 + _vs.size(); }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual int getNumEdgeVertices() const { return 6 * (_order - 1); }
  virtual int getNumFaceVertices() const
  {
    return 4 * ((_order - 1) * (_order - 2)) / 2;
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(_order + 1);
    MTetrahedron::_getEdgeVertices(num, v);
    int j = 2;
    const int ie = (num + 1) * (_order -1);
    for(int i = num * (_order -1); i != ie; ++i) v[j++] = _vs[i];
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3 + 3 * (_order - 1) + (_order-1) * (_order - 2) /2);
    MTetrahedron::_getFaceVertices(num, v);
    int j = 3;
    int nbV = (_order - 1) * (_order - 2) / 2;
    const int ie = (num+1)*nbV;
    for(int i = num*nbV; i != ie; ++i) v[j++] = _vs[i];
  }
  virtual int getNumVolumeVertices() const 
  {
    switch(getTypeForMSH()){
    case MSH_TET_35 : return 1;
    case MSH_TET_56 : return 4;
    default : return 0;
    }    
  }
  virtual int getTypeForMSH() const 
  {
    // (p+1)*(p+2)*(p+3)/6
    if(_order == 3 && _vs.size() + 4 == 20) return MSH_TET_20; 
    if(_order == 4 && _vs.size() + 4 == 34) return MSH_TET_34; 
    if(_order == 4 && _vs.size() + 4 == 35) return MSH_TET_35; 
    if(_order == 5 && _vs.size() + 4 == 56) return MSH_TET_56; 
    if(_order == 5 && _vs.size() + 4 == 52) return MSH_TET_52; 
    return 0;
  }
  virtual void revert() 
  {    
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[2]; _v[2] = tmp;    
    switch (getTypeForMSH()) {
    case MSH_TET_20:
      {
        std::vector<MVertex*> inv(16);
        for (int i=0;i<16;i++) inv[i] = _vs[reverseTet20[i+4]-4];
        _vs = inv;
        break;
      }
    case MSH_TET_35:
      {
        std::vector<MVertex*> inv(31);
        for (int i=0;i<31;i++) inv[i] = _vs[reverseTet35[i+4]-4];
        _vs = inv;
        break;
      }
    case MSH_TET_34:
      {
        std::vector<MVertex*> inv(30);
        for (int i=0;i<30;i++) inv[i] = _vs[reverseTet34[i+4]-4];
        _vs = inv;
        break;
      }
    default:
      {
        Msg::Error("Reversion of %d order tetrahedron (type %d) not implemented\n",
                   _order, getTypeForMSH());
        break;
      }
    }
  }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n);
  virtual int getNumEdgesRep();
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n);
  virtual int getNumFacesRep();
};

/*
 * MHexahedron
 *
 *          v
 *   3----------2
 *   |\     ^   |\
 *   | \    |   | \
 *   |  \   |   |  \
 *   |   7------+---6
 *   |   |  +-- |-- | -> u
 *   0---+---\--1   | 
 *    \  |    \  \  |
 *     \ |     \  \ |
 *      \|      w  \|
 *       4----------5
 *
 */
class MHexahedron : public MElement {
 protected:
  MVertex *_v[8];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_hexa(num, 0)];
    v[1] = _v[edges_hexa(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[faces_hexa(num, 0)];
    v[1] = _v[faces_hexa(num, 1)];
    v[2] = _v[faces_hexa(num, 2)];
    v[3] = _v[faces_hexa(num, 3)];
  }
 public :
  MHexahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
              MVertex *v5, MVertex *v6, MVertex *v7, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
    _v[4] = v4; _v[5] = v5; _v[6] = v6; _v[7] = v7;
  }
  MHexahedron(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 8; i++) _v[i] = v[i];
  }
  ~MHexahedron(){}
  virtual int getDim(){ return 3; }
  virtual int getNumVertices() const { return 8; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[8] = {0, 3, 2, 1, 4, 7, 6, 5};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[8] = {2, 3, 7, 6, 0, 1, 5, 4};
    return getVertex(map[num]); 
  }
  virtual int getNumEdges(){ return 12; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_hexa(num, 0)], _v[edges_hexa(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 12; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[12] = {0, 0, 1, 0, 1, 0, 3, 2, 1, 2, 3, 4};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 6; }
  virtual MFace getFace(int num)
  {
    return MFace(_v[faces_hexa(num, 0)],
		 _v[faces_hexa(num, 1)],
		 _v[faces_hexa(num, 2)],
		 _v[faces_hexa(num, 3)]);
  }
  virtual int getNumFacesRep(){ return 12; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[12][3] = {
      {0, 3, 2}, {0, 2, 1},
      {0, 1, 5}, {0, 5, 4},
      {0, 4, 7}, {0, 7, 3},
      {1, 2, 6}, {1, 6, 5},
      {2, 3, 7}, {2, 7, 6},
      {4, 5, 6}, {4, 6, 7}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(4);
    _getFaceVertices(num, v);
  }
  virtual int getTypeForMSH() const { return MSH_HEX_8; }
  virtual int getTypeForUNV() const { return 115; } // solid linear brick
  virtual int getTypeForVTK() const { return 12; }
  virtual const char *getStringForPOS() const { return "SH"; }
  virtual const char *getStringForBDF() const { return "CHEXA"; }
  virtual const char *getStringForDIFF() const { return "ElmB8n3D"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
  }
  virtual int getVolumeSign();
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    s[0] = (1. - u) * (1. - v) * (1. - w) * 0.125;
    s[1] = (1. + u) * (1. - v) * (1. - w) * 0.125;
    s[2] = (1. + u) * (1. + v) * (1. - w) * 0.125;
    s[3] = (1. - u) * (1. + v) * (1. - w) * 0.125;
    s[4] = (1. - u) * (1. - v) * (1. + w) * 0.125;
    s[5] = (1. + u) * (1. - v) * (1. + w) * 0.125;
    s[6] = (1. + u) * (1. + v) * (1. + w) * 0.125;
    s[7] = (1. - u) * (1. + v) * (1. + w) * 0.125;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    s[0][0] = -0.125 * (1. - v) * (1. - w);
    s[0][1] = -0.125 * (1. - u) * (1. - w);
    s[0][2] = -0.125 * (1. - u) * (1. - v);
    s[1][0] =  0.125 * (1. - v) * (1. - w);
    s[1][1] = -0.125 * (1. + u) * (1. - w);
    s[1][2] = -0.125 * (1. + u) * (1. - v);
    s[2][0] =  0.125 * (1. + v) * (1. - w);
    s[2][1] =  0.125 * (1. + u) * (1. - w);
    s[2][2] = -0.125 * (1. + u) * (1. + v);
    s[3][0] = -0.125 * (1. + v) * (1. - w);
    s[3][1] =  0.125 * (1. - u) * (1. - w);
    s[3][2] = -0.125 * (1. - u) * (1. + v);
    s[4][0] = -0.125 * (1. - v) * (1. + w);
    s[4][1] = -0.125 * (1. - u) * (1. + w);
    s[4][2] =  0.125 * (1. - u) * (1. - v);
    s[5][0] =  0.125 * (1. - v) * (1. + w);
    s[5][1] = -0.125 * (1. + u) * (1. + w);
    s[5][2] =  0.125 * (1. + u) * (1. - v);
    s[6][0] =  0.125 * (1. + v) * (1. + w);
    s[6][1] =  0.125 * (1. + u) * (1. + w);
    s[6][2] =  0.125 * (1. + u) * (1. + v);
    s[7][0] = -0.125 * (1. + v) * (1. + w);
    s[7][1] =  0.125 * (1. - u) * (1. + w);
    s[7][2] =  0.125 * (1. - u) * (1. + v);
  }
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    if(u < -(1. + tol) || v < -(1. + tol) || w < -(1. + tol) || 
       u > (1. + tol) || v > (1. + tol) || w > (1. + tol))
      return false;
    return true;
  }
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const;
 private:
  int edges_hexa(const int edge, const int vert) const
  {
    static const int e[12][2] = {
      {0, 1},
      {0, 3},
      {0, 4},
      {1, 2},
      {1, 5},
      {2, 3},
      {2, 6},
      {3, 7},
      {4, 5},
      {4, 7},
      {5, 6},
      {6, 7}
    };
    return e[edge][vert];
  }
  int faces_hexa(const int face, const int vert) const
  {
    static const int f[6][4] = {
      {0, 3, 2, 1},
      {0, 1, 5, 4},
      {0, 4, 7, 3},
      {1, 2, 6, 5},
      {2, 3, 7, 6},
      {4, 5, 6, 7}
    };
    return f[face][vert];
  }
};

/*
 * MHexahedron20
 *
 *   3----13----2
 *   |\         |\
 *   | 15       | 14
 *   9  \       11 \
 *   |   7----19+---6
 *   |   |      |   |
 *   0---+-8----1   | 
 *    \  17      \  18
 *    10 |        12|
 *      \|         \|
 *       4----16----5
 *
 */
class MHexahedron20 : public MHexahedron {
 protected:
  MVertex *_vs[12];
 public :
  MHexahedron20(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
                MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
                MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
                MVertex *v15, MVertex *v16, MVertex *v17, MVertex *v18, MVertex *v19,
                int num=0, int part=0) 
    : MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7, num, part)
  {
    _vs[0] = v8; _vs[1] = v9; _vs[2] = v10; _vs[3] = v11; _vs[4] = v12; 
    _vs[5] = v13; _vs[6] = v14; _vs[7] = v15; _vs[8] = v16; _vs[9] = v17; 
    _vs[10] = v18; _vs[11] = v19; 
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  MHexahedron20(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[8 + i];
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MHexahedron20(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 20; }
  virtual MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[20] = {0, 8, 1, 11, 2, 13, 3, 9, 10, 12, 
                                14, 15, 4, 16, 5, 18, 6, 19, 7, 17};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 11, 13, 
                                9, 10, 12, 14, 15, 16, 18, 19, 17};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[20] = {0, 3, 2, 1, 4, 7, 6, 5, 9, 13, 11, 
				8, 17, 19, 18, 16, 10, 15, 14, 12};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[20] = {2, 3, 7, 6, 0, 1, 5, 4, 9, 18, 12, 
				19, 14, 11, 15, 13, 8, 16, 17, 10};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 12; }
  virtual int getNumEdgesRep(){ return 24; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[24][2] = {
      {0, 8}, {8, 1},
      {0, 9}, {9, 3},
      {0, 10}, {10, 4},
      {1, 11}, {11, 2},
      {1, 12}, {12, 5},
      {2, 13}, {13, 3},
      {2, 14}, {14, 6},
      {3, 15}, {15, 7},
      {4, 16}, {16, 5},
      {4, 17}, {17, 7},
      {5, 18}, {18, 6},
      {6, 19}, {19, 7}
    };
    static const int f[12] = {0, 0, 1, 0, 1, 0, 3, 2, 1, 2, 3, 4};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MHexahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 36; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[36][3] = {
      {0, 9, 8}, {3, 13, 9}, {2, 11, 13}, {1, 8, 11}, {8, 9, 13}, {8, 13, 11},
      {0, 8, 10}, {1, 12, 8}, {5, 16, 12}, {4, 10, 16}, {8, 12, 16}, {8, 16, 10},
      {0, 10, 9}, {4, 17, 10}, {7, 15, 17}, {3, 9, 7}, {9, 10, 17}, {9, 17, 15},
      {1, 11, 12}, {2, 14, 11}, {6, 18, 14}, {5, 12, 18}, {11, 14, 18}, {11, 18, 12},
      {2, 13, 14}, {3, 15, 13}, {7, 19, 15}, {6, 14, 19}, {13, 15, 19}, {13, 19, 14},
      {4, 16, 17}, {5, 18, 16}, {6, 19, 18}, {7, 17, 19}, {16, 18, 19}, {16, 19, 17}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(8);
    MHexahedron::_getFaceVertices(num, v);
    static const int f[6][4] = {
      {1,  5,  3, 0},
      {0,  4,  8, 2},
      {2,  9,  7, 1},
      {3,  6, 10, 4},
      {5,  7, 11, 6},
      {8, 10, 11, 9}
    };
    v[4] = _vs[f[num][0]];
    v[5] = _vs[f[num][1]];
    v[6] = _vs[f[num][2]];
    v[7] = _vs[f[num][3]];
  }
  virtual int getTypeForMSH() const { return MSH_HEX_20; }
  virtual int getTypeForUNV() const { return 116; } // solid parabolic brick
  //virtual int getTypeForVTK() const { return 25; }
  virtual const char *getStringForBDF() const { return "CHEXA"; }
  virtual const char *getStringForDIFF() const { return "ElmB20n3D"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    MVertex *old[12];
    for(int i = 0; i < 12; i++) old[i] = _vs[i];
    _vs[0] = old[3]; _vs[3] = old[0];
    _vs[1] = old[5]; _vs[5] = old[1];
    _vs[2] = old[6]; _vs[6] = old[2];
    _vs[8] = old[10]; _vs[10] = old[8];
    _vs[9] = old[11]; _vs[11] = old[9];
  }
};

/*
 * MHexahedron27
 *
 *   3----13----2
 *   |\         |\
 *   |15    24  | 14
 *   9  \ 20    11 \
 *   |   7----19+---6
 *   |22 |  26  | 23|
 *   0---+-8----1   |
 *    \ 17    25 \  18
 *    10 |  21    12|
 *      \|         \|
 *       4----16----5
 *
 */
class MHexahedron27 : public MHexahedron {
 protected:
  MVertex *_vs[19];
 public :
  MHexahedron27(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
                MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
                MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
                MVertex *v15, MVertex *v16, MVertex *v17, MVertex *v18, MVertex *v19,
                MVertex *v20, MVertex *v21, MVertex *v22, MVertex *v23, MVertex *v24,
                MVertex *v25, MVertex *v26, int num=0, int part=0) 
    : MHexahedron(v0, v1, v2, v3, v4, v5, v6, v7, num, part)
  {
    _vs[0] = v8; _vs[1] = v9; _vs[2] = v10; _vs[3] = v11; _vs[4] = v12; 
    _vs[5] = v13; _vs[6] = v14; _vs[7] = v15; _vs[8] = v16; _vs[9] = v17; 
    _vs[10] = v18; _vs[11] = v19; _vs[12] = v20; _vs[13] = v21; _vs[14] = v22;
    _vs[15] = v23; _vs[16] = v24; _vs[17] = v25; _vs[18] = v26;
    for(int i = 0; i < 19; i++) _vs[i]->setPolynomialOrder(2);
  }
  MHexahedron27(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 19; i++) _vs[i] = v[8 + i];
    for(int i = 0; i < 19; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MHexahedron27(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 27; }
  virtual MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  virtual MVertex *getVertexDIFF(int num)
  {
    static const int map[27] = {6, 8, 26, 24, 0, 2, 20, 18, 7, 15, 3, 17, 5, 25, 
                                23, 21, 1, 9, 11, 19, 16, 4, 12, 14, 22, 10, 13};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 12; }
  virtual int getNumFaceVertices() const { return 6; }
  virtual int getNumVolumeVertices() const { return 1; }
  virtual int getNumEdgesRep(){ return 24; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[24][2] = {
      {0, 8}, {8, 1},
      {0, 9}, {9, 3},
      {0, 10}, {10, 4},
      {1, 11}, {11, 2},
      {1, 12}, {12, 5},
      {2, 13}, {13, 3},
      {2, 14}, {14, 6},
      {3, 15}, {15, 7},
      {4, 16}, {16, 5},
      {4, 17}, {17, 7},
      {5, 18}, {18, 6},
      {6, 19}, {19, 7}
    };
    static const int f[12] = {0, 0, 1, 0, 1, 0, 3, 2, 1, 2, 3, 4};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MHexahedron::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 48; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[48][3] = {
      {0, 9, 20}, {0, 20, 8}, {3, 13, 20}, {3, 20, 9}, 
      {2, 11, 20}, {2, 20, 13}, {1, 8, 20}, {1, 20, 11},
      {0, 8, 21}, {0, 21, 10}, {1, 12, 21}, {1, 21, 8}, 
      {5, 16, 21}, {5, 21, 12}, {4, 10, 21}, {4, 21, 16}, 
      {0, 10, 22}, {0, 22, 9}, {4, 17, 22}, {4, 22, 10}, 
      {7, 15, 22}, {7, 22, 17}, {3, 9, 22}, {3, 22, 15},  
      {1, 11, 23}, {1, 23, 12}, {2, 14, 23}, {2, 23, 11}, 
      {6, 18, 23}, {6, 23, 14}, {5, 12, 23}, {5, 23, 18}, 
      {2, 13, 24}, {2, 24, 14}, {3, 15, 24}, {3, 24, 13}, 
      {7, 19, 24}, {7, 24, 15}, {6, 14, 24}, {6, 24, 19}, 
      {4, 16, 25}, {4, 25, 17}, {5, 18, 25}, {5, 25, 16}, 
      {6, 19, 25}, {6, 25, 18}, {7, 17, 25}, {7, 25, 19}  
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(9);
    MHexahedron::_getFaceVertices(num, v);
    static const int f[6][4] = {
      {1,  5,  3, 0},
      {0,  4,  8, 2},
      {2,  9,  7, 1},
      {3,  6, 10, 4},
      {5,  7, 11, 6},
      {8, 10, 11, 9}
    };
    v[4] = _vs[f[num][0]];
    v[5] = _vs[f[num][1]];
    v[6] = _vs[f[num][2]];
    v[7] = _vs[f[num][3]];
    v[8] = _vs[12+num];
  }
  virtual int getTypeForMSH() const { return MSH_HEX_27; }
  virtual const char *getStringForPOS() const { return "SH2"; }
  virtual const char *getStringForDIFF() const { return "ElmB27n3D"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    MVertex *old[19];
    for(int i = 0; i < 19; i++) old[i] = _vs[i];
    // edge vertices
    _vs[0] = old[3]; _vs[3] = old[0];
    _vs[1] = old[5]; _vs[5] = old[1];
    _vs[2] = old[6]; _vs[6] = old[2];
    _vs[8] = old[10]; _vs[10] = old[8];
    _vs[9] = old[11]; _vs[11] = old[9];
    // face vertices
    _vs[13] = old[15]; _vs[15] = old[13];
    _vs[14] = old[16]; _vs[16] = old[14];
  }
};

/*
 * MPrism
 *
 *               w
 *               ^
 *               |
 *               3
 *             ,/|`\
 *           ,/  |  `\
 *         ,/    |    `\
 *        4------+------5
 *        |      |      |
 *        |    ,/|`\    |
 *        |  ,/  |  `\  |
 *        |,/    |    `\|
 *       ,|      |      `\
 *     ,/ |      0      | `\
 *    u   |    ,/ `\    |    v
 *        |  ,/     `\  |
 *        |,/         `\|
 *        1-------------2
 *
 */
class MPrism : public MElement {
 protected:
  MVertex *_v[6];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_prism(num, 0)];
    v[1] = _v[edges_prism(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[faces_prism(num, 0)];
    v[1] = _v[faces_prism(num, 1)];
    v[2] = _v[faces_prism(num, 2)];
    if(num >= 2) v[3] = _v[faces_prism(num, 3)];
  }
 public :
  MPrism(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
         MVertex *v5, int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
    _v[4] = v4; _v[5] = v5; 
  }
  MPrism(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 6; i++) _v[i] = v[i];
  }
  ~MPrism(){}
  virtual int getDim(){ return 3; }
  virtual int getNumVertices() const { return 6; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[6] = {0, 2, 1, 3, 5, 4};
    return getVertex(map[num]); 
  }
  virtual int getNumEdges(){ return 9; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_prism(num, 0)], _v[edges_prism(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 9; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[9] = {0, 1, 2, 0, 2, 3, 1, 1, 1};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 5; }
  virtual MFace getFace(int num)
  {
    if(num < 2)
      return MFace(_v[faces_prism(num, 0)],
                   _v[faces_prism(num, 1)],
                   _v[faces_prism(num, 2)]);
    else
      return MFace(_v[faces_prism(num, 0)],
                   _v[faces_prism(num, 1)],
                   _v[faces_prism(num, 2)],
                   _v[faces_prism(num, 3)]);
  }
  virtual int getNumFacesRep(){ return 8; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[8][3] = {
      {0, 2, 1},
      {3, 4, 5},
      {0, 1, 4}, {0, 4, 3},
      {0, 3, 5}, {0, 5, 2},
      {1, 2, 5}, {1, 5, 4}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 2) ? 3 : 4);
    _getFaceVertices(num, v);
  }
  virtual int getTypeForMSH() const { return MSH_PRI_6; }
  virtual int getTypeForUNV() const { return 112; } // solid linear wedge
  virtual int getTypeForVTK() const { return 13; }
  virtual const char *getStringForPOS() const { return "SI"; }
  virtual const char *getStringForBDF() const { return "CPENTA"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
  }
  virtual int getVolumeSign();
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    s[0] = (1. - u - v) * (1. - w) * 0.5;
    s[1] =       u      * (1. - w) * 0.5;
    s[2] =           v  * (1. - w) * 0.5;
    s[3] = (1. - u - v) * (1. + w) * 0.5;
    s[4] =       u      * (1. + w) * 0.5;
    s[5] =           v  * (1. + w) * 0.5;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    s[0][0] = -0.5 * (1. - w)    ;
    s[0][1] = -0.5 * (1. - w)    ;
    s[0][2] = -0.5 * (1. - u - v);
    s[1][0] =  0.5 * (1. - w)    ;
    s[1][1] =  0.                ;
    s[1][2] = -0.5 * u           ;
    s[2][0] =  0.                ;
    s[2][1] =  0.5 * (1. - w)    ;
    s[2][2] = -0.5 * v           ;
    s[3][0] = -0.5 * (1. + w)    ;
    s[3][1] = -0.5 * (1. + w)    ;
    s[3][2] =  0.5 * (1. - u - v);
    s[4][0] =  0.5 * (1. + w)    ;
    s[4][1] =  0.                ;
    s[4][2] =  0.5 * u           ;
    s[5][0] =  0.                ;
    s[5][1] =  0.5 * (1. + w)    ;
    s[5][2] =  0.5 * v           ;
  }
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    if(w > (1. + tol) || w < -(1. + tol) || u < (1. + tol)
       || v < (1. + tol) || u > ((1. + tol) - v))
      return false;
    return true;
  }
 private:
  int edges_prism(const int edge, const int vert) const
  {
    static const int e[9][2] = {
      {0, 1},
      {0, 2},
      {0, 3},
      {1, 2},
      {1, 4},
      {2, 5},
      {3, 4},
      {3, 5},
      {4, 5}
    };
    return e[edge][vert];
  }
  int faces_prism(const int face, const int vert) const
  {
    static const int f[5][4] = {
      {0, 2, 1, -1},
      {3, 4, 5, -1},
      {0, 1, 4,  3},
      {0, 3, 5,  2},
      {1, 2, 5,  4}
    };
    return f[face][vert];
  }
};

/*
 * MPrism15
 *
 *               3
 *             ,/|`\
 *           12  |  13
 *         ,/    |    `\
 *        4------14-----5
 *        |      8      |
 *        |      |      |
 *        |      |      |
 *        |      |      |
 *        10     |      11
 *        |      0      |
 *        |    ,/ `\    |
 *        |  ,6     `7  |
 *        |,/         `\|
 *        1------9------2
 *
 */
class MPrism15 : public MPrism {
 protected:
  MVertex *_vs[9];
 public :
  MPrism15(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
           MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
           MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
           int num=0, int part=0) 
    : MPrism(v0, v1, v2, v3, v4, v5, num, part)
  {
    _vs[0] = v6; _vs[1] = v7; _vs[2] = v8; _vs[3] = v9; _vs[4] = v10; 
    _vs[5] = v11; _vs[6] = v12; _vs[7] = v13; _vs[8] = v14;
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPrism15(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 9; i++) _vs[i] = v[6 + i];
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPrism15(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 15; }
  virtual MVertex *getVertex(int num){ return num < 6 ? _v[num] : _vs[num - 6]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[15] = {0, 6, 1, 9, 2, 7, 8, 10, 11, 3, 12, 4, 14, 5, 13};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexBDF(int num)
  {
    static const int map[15] = {0, 1, 2, 3, 4, 5, 6, 9, 7, 8, 10, 11, 12, 14, 13};
    return getVertex(map[num]); 
  }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[15] = {0, 2, 1, 3, 5, 4, 7, 9, 6, 13, 14, 12, 8, 11, 10};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 9; }
  virtual int getNumEdgesRep(){ return 18; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[18][2] = {
      {0, 6}, {6, 1},
      {0, 7}, {7, 2},
      {0, 8}, {8, 3},
      {1, 9}, {9, 2},
      {1, 10}, {10, 4},
      {2, 11}, {11, 5},
      {3, 12}, {12, 4},
      {3, 13}, {13, 5},
      {4, 14}, {14, 5}
    };
    static const int f[9] = {0, 1, 2, 0, 2, 3, 1, 1, 1};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPrism::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 26; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[26][3] = {
      {0, 7, 6}, {2, 9, 7}, {1, 6, 9}, {6, 7, 9},
      {3, 12, 13}, {4, 14, 12}, {5, 13, 14}, {12, 14, 13},
      {0, 6, 8}, {1, 10, 6}, {4, 12, 10}, {3, 8, 12}, {6, 10, 12}, {6, 12, 8},
      {0, 8, 7}, {3, 13, 8}, {5, 11, 13}, {2, 7, 11}, {7, 8, 13}, {7, 13, 11},
      {1, 9, 10}, {2, 11, 9}, {5, 14, 11}, {4, 10, 14}, {9, 11, 14}, {9, 14, 10}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 2) ? 6 : 8);
    MPrism::_getFaceVertices(num, v);
    static const int f[5][4] = {
      {1, 3, 0, -1},
      {6, 8, 7, -1},
      {0, 4, 6,  2},
      {2, 7, 5,  1},
      {3, 5, 8,  4}
    };
    const int i = (num < 2) ? 3 : 4;
    v[i  ] = _vs[f[num][0]];
    v[i+1] = _vs[f[num][1]];
    v[i+2] = _vs[f[num][2]];
    if (num >= 2) v[7] = _vs[f[num][3]];
  }
  virtual int getTypeForMSH() const { return MSH_PRI_15; }
  virtual int getTypeForUNV() const { return 113; } // solid parabolic wedge
  virtual const char *getStringForBDF() const { return "CPENTA"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[4]; _vs[4] = tmp;
    tmp = _vs[7]; _vs[7] = _vs[8]; _vs[8] = tmp;
  }
};

/*
 * MPrism18
 *
 *               3
 *             ,/|`\
 *           12  |  13
 *         ,/    |    `\
 *        4------14-----5
 *        |      8      |
 *        |    ,/|`\    |
 *        |  15  |  16  |
 *        |,/    |    `\|
 *        10-----17-----11
 *        |      0      |
 *        |    ,/ `\    |
 *        |  ,6     `7  |
 *        |,/         `\|
 *        1------9------2
 *
 */
class MPrism18 : public MPrism {
 protected:
  MVertex *_vs[12];
 public :
  MPrism18(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
           MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
           MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
           MVertex *v15, MVertex *v16, MVertex *v17, int num=0, int part=0) 
    : MPrism(v0, v1, v2, v3, v4, v5, num, part)
  {
    _vs[0] = v6; _vs[1] = v7; _vs[2] = v8; _vs[3] = v9; _vs[4] = v10; 
    _vs[5] = v11; _vs[6] = v12; _vs[7] = v13; _vs[8] = v14; _vs[9] = v15; 
    _vs[10] = v16; _vs[11] = v17; 
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPrism18(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[6 + i];
    for(int i = 0; i < 12; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPrism18(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 18; }
  virtual MVertex *getVertex(int num){ return num < 6 ? _v[num] : _vs[num - 6]; }
  virtual int getNumEdgeVertices() const { return 9; }
  virtual int getNumFaceVertices() const { return 3; }
  virtual int getNumEdgesRep(){ return 18; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[18][2] = {
      {0, 6}, {6, 1},
      {0, 7}, {7, 2},
      {0, 8}, {8, 3},
      {1, 9}, {9, 2},
      {1, 10}, {10, 4},
      {2, 11}, {11, 5},
      {3, 12}, {12, 4},
      {3, 13}, {13, 5},
      {4, 14}, {14, 5}
    };
    static const int f[9] = {0, 1, 2, 0, 2, 3, 1, 1, 1};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPrism::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 32; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[32][3] = {
      {0, 7, 6}, {2, 9, 7}, {1, 6, 9}, {6, 7, 9},
      {3, 12, 13}, {4, 14, 12}, {5, 13, 14}, {12, 14, 13},
      {0, 6, 15}, {0, 15, 8}, {1, 10, 15}, {1, 15, 6},  
      {4, 12, 15}, {4, 15, 10}, {3, 8, 15}, {3, 15, 12},  
      {0, 8, 16}, {0, 16, 7}, {3, 13, 16}, {3, 16, 8},  
      {5, 11, 16}, {5, 16, 13}, {2, 7, 16}, {2, 16, 11},  
      {1, 9, 17}, {1, 17, 10}, {2, 11, 17}, {2, 17, 9},  
      {5, 14, 17}, {5, 17, 11}, {4, 10, 17}, {4, 17, 14}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 2) ? 6 : 9);
    MPrism::_getFaceVertices(num, v);
    static const int f[5][4] = {
      {1, 3, 0, -1},
      {6, 8, 7, -1},
      {0, 4, 6,  2},
      {2, 7, 5,  1},
      {3, 5, 8,  4}
    };
    const int i = (num < 2) ? 3 : 4;
    v[i  ] = _vs[f[num][0]];
    v[i+1] = _vs[f[num][1]];
    v[i+2] = _vs[f[num][2]];
    if (num >= 2) {
      v[7] = _vs[f[num][3]];
      v[8] = _vs[7+num];
    }
  }
  virtual int getTypeForMSH() const { return MSH_PRI_18; }
  virtual const char *getStringForPOS() const { return "SI2"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
    // edge vertices
    tmp = _vs[1]; _vs[1] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[4]; _vs[4] = tmp;
    tmp = _vs[7]; _vs[7] = _vs[8]; _vs[8] = tmp;
    // quad face vertices
    tmp = _vs[10]; _vs[10] = _vs[11]; _vs[11] = tmp;
  }
};

/*
 * MPyramid
 *
 *                 4
 *               ,/|\
 *             ,/ .'|\
 *           ,/   | | \
 *         ,/    .' | `.
 *       ,/      |  '.  \
 *     ,/       .' w |   \
 *   ,/         |  ^ |    \
 *  0----------.'--|-3    `. 
 *   `\        |   |  `\    \
 *     `\     .'   +----`\ - \ -> v
 *       `\   |    `\     `\  \
 *         `\.'      `\     `\`
 *            1----------------2
 *                      `\
 *                         u
 *
 */
class MPyramid : public MElement {
 protected:
  MVertex *_v[5];
  void _getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v[0] = _v[edges_pyramid(num, 0)];
    v[1] = _v[edges_pyramid(num, 1)];
  }
  void _getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    if(num < 4) {
      v[0] = _v[faces_pyramid(num, 0)];
      v[1] = _v[faces_pyramid(num, 1)];
      v[2] = _v[faces_pyramid(num, 2)];
    }
    else {
      v[0] = _v[0];
      v[1] = _v[3];
      v[2] = _v[2];
      v[3] = _v[1];
    }
  }
 public :
  MPyramid(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
           int num=0, int part=0) 
    : MElement(num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3; _v[4] = v4;
  }
  MPyramid(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MElement(num, part)
  {
    for(int i = 0; i < 5; i++) _v[i] = v[i];
  }
  ~MPyramid(){}
  virtual int getDim(){ return 3; }
  virtual int getNumVertices() const { return 5; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[5] = {0, 3, 2, 1, 4};
    return getVertex(map[num]); 
  }
  virtual int getNumEdges(){ return 8; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_pyramid(num, 0)], _v[edges_pyramid(num, 1)]);
  }
  virtual int getNumEdgesRep(){ return 8; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  {
    static const int f[8] = {0, 1, 1, 2, 0, 3, 2, 3};
    MEdge e(getEdge(num));
    _getEdgeRep(e.getVertex(0), e.getVertex(1), x, y, z, n, f[num]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(2);
    _getEdgeVertices(num, v);
  }
  virtual int getNumFaces(){ return 5; }
  virtual MFace getFace(int num)
  {
    if(num < 4)
      return MFace(_v[faces_pyramid(num, 0)],
                   _v[faces_pyramid(num, 1)],
                   _v[faces_pyramid(num, 2)]);
    else
      return MFace(_v[0], _v[3], _v[2], _v[1]);
  }
  virtual int getNumFacesRep(){ return 6; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[6][3] = {
      {0, 1, 4},
      {3, 0, 4},
      {1, 2, 4},
      {2, 3, 4},
      {0, 3, 2}, {0, 2, 1}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 4) ? 3 : 4);
    _getFaceVertices(num, v);
  }
  virtual int getTypeForMSH() const { return MSH_PYR_5; }
  virtual int getTypeForVTK() const { return 14; }
  virtual const char *getStringForPOS() const { return "SY"; }
  virtual const char *getStringForBDF() const { return "CPYRAM"; }
  virtual void revert()
  {
    MVertex *tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
  }
  virtual int getVolumeSign();
  virtual void getShapeFunctions(double u, double v, double w, double s[], int o) 
  {
    double r = (w != 1.) ? (u * v * w / (1. - w)) : 0.;
    s[0] = 0.25 * ((1. - u) * (1. - v) - w + r);
    s[1] = 0.25 * ((1. + u) * (1. - v) - w - r);
    s[2] = 0.25 * ((1. + u) * (1. + v) - w + r);
    s[3] = 0.25 * ((1. - u) * (1. + v) - w - r);
    s[4] = w;
  }
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3], int o) 
  {
    if(w == 1.) {
        s[0][0] = -0.25 ; 
        s[0][1] = -0.25 ;
        s[0][2] = -0.25 ; 
	s[1][0] =  0.25 ; 
	s[1][1] = -0.25 ;
	s[1][2] = -0.25 ; 
	s[2][0] =  0.25 ; 
	s[2][1] =  0.25 ;
	s[2][2] = -0.25 ; 
	s[3][0] = -0.25 ; 
	s[3][1] =  0.25 ;
	s[3][2] = -0.25 ; 
    }
    else{
      s[0][0] = 0.25 * ( -(1. - v) + v * w / (1. - w)) ;
      s[0][1] = 0.25 * ( -(1. - u) + u * w / (1. - w)) ;
      s[0][2] = 0.25 * ( -1.     + u * v / (1. - w) + u * v * w / (1. - w) / (1. - w)) ; 
      s[1][0] = 0.25 * (  (1. - v) - v * w / (1. - w)) ;
      s[1][1] = 0.25 * ( -(1. + u) - u * w / (1. - w)) ;
      s[1][2] = 0.25 * ( -1.     - u * v / (1. - w) - u * v * w / (1. - w) / (1. - w)) ; 
      s[2][0] = 0.25 * (  (1. + v) + v * w / (1. - w)) ;
      s[2][1] = 0.25 * (  (1. + u) + u * w / (1. - w)) ;
      s[2][2] = 0.25 * ( -1.     + u * v / (1. - w) + u * v * w / (1. - w) / (1. - w)) ; 
      s[3][0] = 0.25 * ( -(1. + v) - v * w / (1. - w)) ;
      s[3][1] = 0.25 * (  (1. - u) - u * w / (1. - w)) ;
      s[3][2] = 0.25 * ( -1.     - u * v / (1. - w) - u * v * w / (1. - w) / (1. - w)) ; 
    }
    s[4][0] = 0.; 
    s[4][1] = 0.;
    s[4][2] = 1.;
  }
  virtual bool isInside(double u, double v, double w, double tol=1.e-8)
  {
    if(u < (w - (1. + tol)) || u > ((1. + tol) - w) || v < (w - (1. + tol)) ||
       v > ((1. + tol) - w) || w < (-tol) || w > (1. + tol))
      return false;
    return true;
  }
 private:
  int edges_pyramid(const int edge, const int vert) const
  {
    static const int e[8][2] = {
      {0, 1},
      {0, 3},
      {0, 4},
      {1, 2},
      {1, 4},
      {2, 3},
      {2, 4},
      {3, 4}
    };
    return e[edge][vert];
  }
  int faces_pyramid(const int face, const int vert) const
  {
    // only triangular faces
    static const int f[4][3] = {
      {0, 1, 4},
      {3, 0, 4},
      {1, 2, 4},
      {2, 3, 4}
    };
    return f[face][vert];
  }
};

/*
 * MPyramid13
 *
 *                 4
 *               ,/|\
 *             ,/ .'|\
 *           ,/   | | \
 *         ,/    .' | `.
 *       ,7      |  12  \
 *     ,/       .'   |   \
 *   ,/         9    |    11
 *  0--------6-.'----3    `. 
 *   `\        |      `\    \
 *     `5     .'        10   \ 
 *       `\   |           `\  \
 *         `\.'             `\`
 *            1--------8-------2
 *                        
 */
class MPyramid13 : public MPyramid {
 protected:
  MVertex *_vs[8];
 public :
  MPyramid13(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
             MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
             MVertex *v10, MVertex *v11, MVertex *v12, int num=0, int part=0) 
    : MPyramid(v0, v1, v2, v3, v4, num, part)
  {
    _vs[0] = v5; _vs[1] = v6; _vs[2] = v7; _vs[3] = v8; _vs[4] = v9; 
    _vs[5] = v10; _vs[6] = v11; _vs[7] = v12;
    for(int i = 0; i < 8; i++) _vs[i]->setPolynomialOrder(2);
  }
  MPyramid13(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPyramid(v, num, part)
  {
    for(int i = 0; i < 8; i++) _vs[i] = v[5 + i];
    for(int i = 0; i < 8; i++) _vs[i]->setPolynomialOrder(2);
  }
  ~MPyramid13(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 13; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual MVertex *getVertexMED(int num)
  {
    static const int map[13] = {0, 3, 2, 1, 4, 6, 10, 8, 5, 7, 12, 11, 9};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices() const { return 8; }
  virtual int getNumEdgesRep(){ return 16; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[16][2] = {
      {0, 5}, {5, 1},
      {0, 6}, {6, 3},
      {0, 7}, {7, 4},
      {1, 8}, {8, 2},
      {1, 9}, {9, 4},
      {2, 10}, {10, 3},
      {2, 11}, {11, 4},
      {3, 12}, {12, 4}
    };
    static const int f[8] = {0, 1, 1, 2, 0, 3, 2, 3};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPyramid::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 22; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[22][3] = {
      {0, 5, 7}, {1, 9, 5}, {4, 7, 9}, {5, 9, 7},
      {3, 6, 12}, {0, 7, 6}, {4, 12, 7}, {6, 7, 12},
      {1, 8, 9}, {2, 11, 8}, {4, 9, 11}, {8, 11, 9},
      {2, 10, 11}, {3, 12, 10}, {4, 11, 12}, {10, 12, 11},
      {0, 6, 5}, {3, 10, 6}, {2, 8, 10}, {1, 5, 8}, {5, 6, 10}, {5, 10, 8}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 4) ? 6 : 8);
    MPyramid::_getFaceVertices(num, v);
    static const int f[4][3] = {
      {0, 4, 2},
      {1, 2, 7},
      {3, 6, 4},
      {5, 7, 6}
    };
    if(num < 4) {
      v[3] = _vs[f[num][0]];
      v[4] = _vs[f[num][1]];
      v[5] = _vs[f[num][2]];
    }
    else {
      v[4] = _vs[1];
      v[5] = _vs[5];
      v[6] = _vs[3];
      v[7] = _vs[0];
    }
  }
  virtual int getTypeForMSH() const { return MSH_PYR_13; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[5]; _vs[5] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[6]; _vs[6] = tmp;
  }
};

/*
 * MPyramid14
 *
 *                 4
 *               ,/|\
 *             ,/ .'|\
 *           ,/   | | \
 *         ,/    .' | `.
 *       ,7      |  12  \
 *     ,/       .'   |   \
 *   ,/         9    |    11
 *  0--------6-.'----3    `. 
 *   `\        |      `\    \
 *     `5     .' 13     10   \ 
 *       `\   |           `\  \
 *         `\.'             `\`
 *            1--------8-------2
 *
 */
class MPyramid14 : public MPyramid {
 protected:
  MVertex *_vs[9];
 public :
  MPyramid14(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
             MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
             MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, 
             int num=0, int part=0) 
    : MPyramid(v0, v1, v2, v3, v4, num, part)
  {
    _vs[0] = v5; _vs[1] = v6; _vs[2] = v7; _vs[3] = v8; _vs[4] = v9; 
    _vs[5] = v10; _vs[6] = v11; _vs[7] = v12; _vs[8] = v13; 
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);   
  }
  MPyramid14(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPyramid(v, num, part)
  {
    for(int i = 0; i < 9; i++) _vs[i] = v[5 + i];
    for(int i = 0; i < 9; i++) _vs[i]->setPolynomialOrder(2);   
  }
  ~MPyramid14(){}
  virtual int getPolynomialOrder() const { return 2; }
  virtual int getNumVertices() const { return 14; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual int getNumEdgeVertices() const { return 8; }
  virtual int getNumFaceVertices() const { return 1; }
  virtual int getNumEdgesRep(){ return 16; }
  virtual void getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int e[16][2] = {
      {0, 5}, {5, 1},
      {0, 6}, {6, 3},
      {0, 7}, {7, 4},
      {1, 8}, {8, 2},
      {1, 9}, {9, 4},
      {2, 10}, {10, 3},
      {2, 11}, {11, 4},
      {3, 12}, {12, 4}
    };
    static const int f[8] = {0, 1, 1, 2, 0, 3, 2, 3};
    _getEdgeRep(getVertex(e[num][0]), getVertex(e[num][1]), x, y, z, n, f[num / 2]);
  }
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(3);
    MPyramid::_getEdgeVertices(num, v);
    v[2] = _vs[num];
  }
  virtual int getNumFacesRep(){ return 24; }
  virtual void getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
  { 
    static const int f[24][3] = {
      {0, 5, 7}, {1, 9, 5}, {4, 7, 9}, {5, 9, 7},
      {3, 6, 12}, {0, 7, 6}, {4, 12, 7}, {6, 7, 12},
      {1, 8, 9}, {2, 11, 8}, {4, 9, 11}, {8, 11, 9},
      {2, 10, 11}, {3, 12, 10}, {4, 11, 12}, {10, 12, 11},
      {0, 6, 13}, {0, 13, 5}, {3, 10, 13}, {3, 13, 6}, 
      {2, 8, 13}, {2, 13, 10}, {1, 5, 13}, {1, 13, 8}
    };
    _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
                x, y, z, n);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize((num < 4) ? 6 : 9);
    MPyramid::_getFaceVertices(num, v);
    static const int f[4][3] = {
      {0, 4, 2},
      {1, 2, 7},
      {3, 6, 4},
      {5, 7, 6}
    };
    if(num < 4) {
      v[3] = _vs[f[num][0]];
      v[4] = _vs[f[num][1]];
      v[5] = _vs[f[num][2]];
    }
    else {
      v[4] = _vs[1];
      v[5] = _vs[5];
      v[6] = _vs[3];
      v[7] = _vs[0];
      v[8] = _vs[8];
    }
  }
  virtual int getTypeForMSH() const { return MSH_PYR_14; }
  virtual const char *getStringForPOS() const { return "SY2"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[5]; _vs[5] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[6]; _vs[6] = tmp;
  }
};

template <class T> 
void sort3(T *t[3])
{
  T *temp;
  if(t[0] > t[1]){
    temp = t[1];
    t[1] = t[0];
    t[0] = temp;
  }
  if(t[1] > t[2]){
    temp = t[2];
    t[2] = t[1];
    t[1] = temp;
  }
  if(t[0] > t[1]){
    temp = t[1];
    t[1] = t[0];
    t[0] = temp;
  }
}

struct compareMTriangleLexicographic
{
  bool operator () (MTriangle *t1, MTriangle *t2) const
  {
    MVertex *_v1[3] = {t1->getVertex(0), t1->getVertex(1), t1->getVertex(2)};
    MVertex *_v2[3] = {t2->getVertex(0), t2->getVertex(1), t2->getVertex(2)};
    sort3(_v1);
    sort3(_v2);
    if(_v1[0] < _v2[0]) return true;
    if(_v1[0] > _v2[0]) return false;
    if(_v1[1] < _v2[1]) return true;
    if(_v1[1] > _v2[1]) return false;
    if(_v1[2] < _v2[2]) return true;
    return false;
  }
};

// Traits of various elements based on the dimension.  These generally define
// the faces of 2-D elements as MEdge and 3-D elements as MFace.

template <unsigned DIM> struct DimTr;
template <> struct DimTr<2>
{
  typedef MEdge FaceT;
  static int getNumFace(MElement *const element)
  {
    return element->getNumEdges();
  }
  static MEdge getFace(MElement *const element, const int iFace)
  {
    return element->getEdge(iFace);
  }
  static void getAllFaceVertices(MElement *const element, const int iFace,
                                 std::vector<MVertex*> &v)
  {
    element->getEdgeVertices(iFace, v);
  }
};

template <> struct DimTr<3>
{
  typedef MFace FaceT;
  static int getNumFace(MElement *const element)
  {
    return element->getNumFaces();
  }
  static MFace getFace(MElement *const element, const int iFace)
  {
    return element->getFace(iFace);
  }
  static void getAllFaceVertices(MElement *const element, const int iFace,
                                 std::vector<MVertex*> &v)
  {
    element->getFaceVertices(iFace, v);
  }
};

#endif
