#ifndef _MELEMENT_H_
#define _MELEMENT_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include <algorithm>
#include "GmshDefines.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MFace.h"
#include "Numeric.h"

// A mesh element.
class MElement 
{
 private:
  static int _globalNum;
  int _num;
  short _partition;
  char _visible;

 public :
  MElement(int num=0, int part=0) 
    : _visible(true) 
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

  // returns the tag of the element
  virtual int getNum(){ return _num; }

  // returns the geometrical dimension of the element
  virtual int getDim() = 0;

  // returns the polynomial order the element
  virtual int getPolynomialOrder(){ return 1; }

  // get/set the partition to which the element belongs
  virtual int getPartition(){ return _partition; }
  virtual void setPartition(int num){ _partition = (short)num; }

  // get/set the visibility flag
  virtual char getVisibility(){ return _visible; }
  virtual void setVisibility(char val){ _visible = val; }

  // get the vertices
  virtual int getNumVertices() = 0;
  virtual MVertex *getVertex(int num) = 0;

  // get the vertex using the I-deas UNV ordering
  virtual MVertex *getVertexUNV(int num){ return getVertex(num); }

  // get the vertex using the Nastran BDF ordering
  virtual MVertex *getVertexBDF(int num){ return getVertex(num); }

  // get the number of vertices associated with edges, faces and
  // volumes (nonzero only for higher order elements)
  virtual int getNumEdgeVertices(){ return 0; }
  virtual int getNumFaceVertices(){ return 0; }
  virtual int getNumVolumeVertices(){ return 0; }

  // get the number of primary vertices (first-order element)
  int getNumPrimaryVertices()
  {
    return getNumVertices() - getNumEdgeVertices() - 
      getNumFaceVertices() - getNumVolumeVertices();
  }

  // get the edges
  virtual int getNumEdges() = 0;
  virtual MEdge getEdge(int num) = 0;

  // get an edge representation for drawing
  virtual int getNumEdgesRep(){ return getNumEdges(); }
  virtual MEdge getEdgeRep(int num){ return getEdge(num); }

  // get the faces
  virtual int getNumFaces() = 0;
  virtual MFace getFace(int num) = 0;

  // get a face representation for drawing
  virtual int getNumFacesRep(){ return getNumFaces(); }
  virtual MFace getFaceRep(int num){ return getFace(num); }

  // get the max/min edge length
  virtual double maxEdge();
  virtual double minEdge();

  // get the quality measures
  virtual double rhoShapeMeasure();
  virtual double gammaShapeMeasure(){ return 0.; }
  virtual double etaShapeMeasure(){ return 0.; }

  // computes the barycenter
  virtual SPoint3 barycenter();

  // revert the orientation of the element
  virtual void revert() = 0;

  // compute and change the orientation of 3D elements to get
  // positive volume
  virtual double getVolume(){ return 0.; }
  virtual int getVolumeSign(){ return 1; }
  virtual void setVolumePositive(){ if(getVolumeSign() < 0) revert(); }

  // Returns an information string for the element
  virtual std::string getInfoString();

  // IO routines
  virtual void writeMSH(FILE *fp, double version=1.0, bool binary=false, 
			int num=0, int elementary=1, int physical=1);
  virtual void writePOS(FILE *fp, double scalingFactor=1.0, int elementary=1);
  virtual void writeSTL(FILE *fp, bool binary=false, double scalingFactor=1.0);
  virtual void writeVRML(FILE *fp);
  virtual void writeUNV(FILE *fp, int num=0, int elementary=1, int physical=1);
  virtual void writeMESH(FILE *fp, int elementary=1);
  virtual void writeBDF(FILE *fp, int format=0, int elementary=1);

  // info for specific IO formats
  virtual int getTypeForMSH() = 0;
  virtual int getTypeForUNV() = 0;
  virtual char *getStringForPOS() = 0;
  virtual char *getStringForBDF() = 0;
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

class MLine : public MElement {
 protected:
  MVertex *_v[2];
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
  virtual int getNumVertices(){ return 2; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 1; }
  virtual MEdge getEdge(int num){ return MEdge(_v[0], _v[1]); }
  virtual int getNumFaces(){ return 0; }
  virtual MFace getFace(int num){ throw; }
  virtual int getTypeForMSH(){ return MSH_LIN_2; }
  virtual int getTypeForUNV(){ return 21; } // linear beam
  virtual char *getStringForPOS(){ return "SL"; }
  virtual char *getStringForBDF(){ return "CBAR"; }
  virtual void revert() 
  {
    MVertex *tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 3; }
  virtual MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[3] = {0, 2, 1};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices(){ return 1; }
  virtual int getNumEdgesRep(){ return 2; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_lin3[2][2] = {
      {0, 2}, {2, 1}
    };
    return MEdge(getVertex(edges_lin3[num][0]), getVertex(edges_lin3[num][1]));
  }
  virtual int getTypeForMSH(){ return MSH_LIN_3; }
  virtual int getTypeForUNV(){ return 24; } // parabolic beam
  virtual char *getStringForPOS(){ return "SL2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
};

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
    for(unsigned int i = 0 ; i < _vs.size(); i++)
      _vs[i]->setPolynomialOrder(_vs.size() + 1);
  }
  ~MLineN(){}
  virtual int getPolynomialOrder(){ return _vs.size() + 1; }
  virtual int getNumVertices(){ return _vs.size() + 2; }
  virtual MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  virtual MVertex *getVertexUNV(int num)
  {
    if(num == 0) return _v[0];
    if(num == (int)_vs.size() + 1) return _v[1];
    return  _vs[num-1];
  }
  virtual int getNumEdgeVertices(){ return _vs.size(); }
  virtual int getNumEdgesRep(){ return _vs.size() + 1; }
  virtual MEdge getEdgeRep(int num)
  { 
    return MEdge(getVertexUNV(num),getVertexUNV(num+1));
  }
  virtual int getTypeForMSH(){ 
    if(_vs.size() == 2) return  MSH_LIN_4; 
    if(_vs.size() == 3) return  MSH_LIN_5; 
    if(_vs.size() == 4) return  MSH_LIN_6; 
    throw;
  }
  virtual int getTypeForUNV(){ throw; } // not available
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return 0; } // not available
};

class MTriangle : public MElement {
 protected:
  MVertex *_v[3];
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
  virtual void  getMat(double mat[2][2])
  {
    mat[0][0] = _v[1]->x() - _v[0]->x();
    mat[0][1] = _v[2]->x() - _v[0]->x();
    mat[1][0] = _v[1]->y() - _v[0]->y();
    mat[1][1] = _v[2]->y() - _v[0]->y();
  }
  void circumcenterXY(double *res) const;
  double getSurfaceXY() const;
  bool invertmappingXY(double *p, double *uv, double tol = 1.e-8);
  virtual int getNumVertices(){ return 3; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 3; }
  virtual MEdge getEdge(int num)
  {
    static const int edges_tri[3][2] = {
      {0, 1},
      {1, 2},
      {2, 0}
    };
    return MEdge(_v[edges_tri[num][0]], _v[edges_tri[num][1]]);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num)
  { 
    return MFace(_v[0], _v[1], _v[2]); 
  }
  virtual int getTypeForMSH(){ return MSH_TRI_3; }
  virtual int getTypeForUNV(){ return 91; } // thin shell linear triangle
  virtual char *getStringForPOS(){ return "ST"; }
  virtual char *getStringForBDF(){ return "CTRIA3"; }
  virtual void revert() 
  {
    MVertex *tmp = _v[1]; _v[1] = _v[2]; _v[2] = tmp;
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 6; }
  virtual MVertex *getVertex(int num){ return num < 3 ? _v[num] : _vs[num - 3]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[6] = {0, 3, 1, 4, 2, 5};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices(){ return 3; }
  virtual int getNumEdgesRep(){ return 6; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_tri6[6][2] = {
      {0, 3}, {3, 1},
      {1, 4}, {4, 2},
      {2, 5}, {5, 0}
    };
    return MEdge(getVertex(edges_tri6[num][0]), getVertex(edges_tri6[num][1]));
  }
  virtual int getNumFacesRep(){ return 4; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_tri2[4][3] = {
      {0, 3, 5}, {1, 4, 3}, {2, 5, 4}, {3, 4, 5}
    };
    return MFace(getVertex(trifaces_tri2[num][0]),
		 getVertex(trifaces_tri2[num][1]),
		 getVertex(trifaces_tri2[num][2]));
  }
  virtual int getTypeForMSH(){ 
    return MSH_TRI_6; }
  virtual int getTypeForUNV(){ return 92; } // thin shell parabolic triangle
  virtual char *getStringForPOS(){ return "ST2"; }
  virtual char *getStringForBDF(){ return "CTRIA6"; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[2]; _vs[2] = tmp;
  }
};

class MTriangleN : public MTriangle {
 protected:
  std::vector<MVertex *> _vs;
  const short _order;
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
  virtual int getPolynomialOrder(){
    return _order;
  }
  virtual int getNumVertices(){ return 3 + _vs.size() ; }
  virtual MVertex *getVertex(int num){ return num < 3 ? _v[num] : _vs[num - 3]; }
  virtual MVertex *getVertexUNV(int num)
  {
    if (num == 0) return _v[0];
    if (num  < _order ) return _vs[num - 1];
    if (num  == _order ) return _v[1];
    if (num  < 2* _order ) return _vs[num - 2];
    if (num  == 2*_order ) return _v[2];
    return _vs[num - 3];
  }
  virtual int getNumFaceVertices();
  virtual int getNumEdgeVertices(){ return _order - 1; }
  virtual int getNumEdgesRep(){ return 3 * _order ; }
  virtual MEdge getEdgeRep(int num)
  { 
    return MEdge(getVertexUNV(num), getVertexUNV((num+1)%(3*_order)));
  }
  virtual int getNumFacesRep();
  virtual MFace getFaceRep(int num);
  virtual int getTypeForMSH(){
    if (_order == 3 && _vs.size() == 6) return MSH_TRI_9; 
    if (_order == 3 && _vs.size() == 7) return MSH_TRI_10; 
    if (_order == 4 && _vs.size() == 9) return MSH_TRI_12; 
    if (_order == 4 && _vs.size() == 12) return MSH_TRI_15; 
    if (_order == 5 && _vs.size() == 12) return MSH_TRI_15I; 
    if (_order == 5 && _vs.size() == 18) return MSH_TRI_21;
    throw;
  }
  virtual int getTypeForUNV(){ throw; } // thin shell parabolic triangle
  virtual char *getStringForPOS(){ return 0; }
  virtual char *getStringForBDF(){ return 0; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[2]; _v[2] = tmp;
    std::vector<MVertex*> inv;
    inv.insert (inv.begin(),_vs.rbegin(),_vs.rend());
    _vs = inv;
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

class MQuadrangle : public MElement {
 protected:
  MVertex *_v[4];
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
  virtual int getNumVertices(){ return 4; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 4; }
  virtual MEdge getEdge(int num)
  {
    static const int edges_quad[4][2] = {
      {0, 1},
      {1, 2},
      {2, 3},
      {3, 0}
    };
    return MEdge(_v[edges_quad[num][0]], _v[edges_quad[num][1]]);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num){ return MFace(_v[0], _v[1], _v[2], _v[3]); }
  virtual int getTypeForMSH(){ return MSH_QUA_4; }
  virtual int getTypeForUNV(){ return 94; } // thin shell linear quadrilateral
  virtual char *getStringForPOS(){ return "SQ"; }
  virtual char *getStringForBDF(){ return "CQUAD4"; }
  virtual void revert() 
  {
    MVertex *tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 8; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual MVertex *getVertexUNV(int num)
  {
    static const int map[8] = {0, 4, 1, 5, 2, 6, 3, 7};
    return getVertex(map[num]); 
  }
  virtual int getNumEdgeVertices(){ return 4; }
  virtual int getNumEdgesRep(){ return 8; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_qua8[8][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 3},
      {3, 7}, {7, 0}
    };
    return MEdge(getVertex(edges_qua8[num][0]), getVertex(edges_qua8[num][1]));
  }
  virtual int getNumFacesRep(){ return 6; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_qua8[6][3] = {
      {0, 4, 7}, {1, 5, 4}, {2, 6, 5}, {3, 7, 6}, {4, 5, 6}, {4, 6, 7}
    };
    return MFace(getVertex(trifaces_qua8[num][0]),
		 getVertex(trifaces_qua8[num][1]),
		 getVertex(trifaces_qua8[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_QUA_8; }
  virtual int getTypeForUNV(){ return 95; } // shell parabolic quadrilateral
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return "CQUAD8"; }
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 9; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual int getNumEdgeVertices(){ return 4; }
  virtual int getNumFaceVertices(){ return 1; }
  virtual int getNumEdgesRep(){ return 8; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_qua9[8][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 3},
      {3, 7}, {7, 0}
    };
    return MEdge(getVertex(edges_qua9[num][0]), getVertex(edges_qua9[num][1]));
  }
  virtual int getNumFacesRep(){ return 8; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_qua9[8][4] = {
      {0, 4, 8}, {0, 8, 7}, {1, 5, 8}, {1, 8, 4}, 
      {2, 6, 8}, {2, 8, 5}, {3, 7, 8}, {3, 8, 6}
    };
    return MFace(getVertex(trifaces_qua9[num][0]),
		 getVertex(trifaces_qua9[num][1]),
		 getVertex(trifaces_qua9[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_QUA_9; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SQ2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void revert() 
  {
    MVertex *tmp;
    tmp = _v[1]; _v[1] = _v[3]; _v[3] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
  }
};

class MTetrahedron : public MElement {
 protected:
  MVertex *_v[4];
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
  virtual int getNumVertices(){ return 4; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 6; }
  virtual MEdge getEdge(int num)
  {
    static const int edges_tetra[6][2] = {
      {0, 1},
      {1, 2},
      {2, 0},
      {3, 0},
      {3, 2},
      {3, 1}
    };
    return MEdge(_v[edges_tetra[num][0]], _v[edges_tetra[num][1]]);
  }
  virtual int getNumFaces(){ return 4; }
  virtual MFace getFace(int num)
  {
    static const int trifaces_tetra[4][3] = {
      {0, 2, 1},
      {0, 1, 3},
      {0, 3, 2},
      {3, 1, 2}
    };
    return MFace(_v[trifaces_tetra[num][0]],
		 _v[trifaces_tetra[num][1]],
		 _v[trifaces_tetra[num][2]]);
  }
  virtual int getTypeForMSH(){ return MSH_TET_4; }
  virtual int getTypeForUNV(){ return 111; } // solid linear tetrahedron
  virtual char *getStringForPOS(){ return "SS"; }
  virtual char *getStringForBDF(){ return "CTETRA"; }
  virtual void revert()
  {
    MVertex *tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
  }
  virtual void  getMat(double mat[3][3])
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
  virtual double getVolume()
  { 
    double mat[3][3];
    getMat(mat);
    return det3x3(mat) / 6.;
  }
  virtual int getVolumeSign(){ return sign(getVolume()); }
  virtual double gammaShapeMeasure();
  virtual double etaShapeMeasure();
  // returns true if the point lies inside the tet
  inline bool invertmapping(double *p, double *uvw, double tol = 1.e-8)
  {
    double mat[3][3];
    double b[3], dum;
    getMat(mat);
    b[0] = p[0] - getVertex(0)->x();
    b[1] = p[1] - getVertex(0)->y();
    b[2] = p[2] - getVertex(0)->z();
    sys3x3(mat, b, uvw, &dum);
    if(uvw[0] >= -tol && uvw[1] >= -tol && uvw[2] >= -tol &&
       uvw[0] <= 1. + tol && uvw[1] <= 1. + tol && uvw[2] <= 1. + tol &&
       1. - uvw[0] - uvw[1] - uvw[2] > -tol) {
      return true;
    }
    return false;
  }
  inline void circumcenter(double *res)
  {
    double X[4] = {_v[0]->x(), _v[1]->x(), _v[2]->x(), _v[3]->x()};
    double Y[4] = {_v[0]->y(), _v[1]->y(), _v[2]->y(), _v[3]->y()};
    double Z[4] = {_v[0]->z(), _v[1]->z(), _v[2]->z(), _v[3]->z()};
    double mat[3][3], b[3], dum;    
    b[0] = X[1] * X[1] - X[0] * X[0] +
      Y[1] * Y[1] - Y[0] * Y[0] + Z[1] * Z[1] - Z[0] * Z[0];
    b[1] = X[2] * X[2] - X[1] * X[1] +
      Y[2] * Y[2] - Y[1] * Y[1] + Z[2] * Z[2] - Z[1] * Z[1];
    b[2] = X[3] * X[3] - X[2] * X[2] +
      Y[3] * Y[3] - Y[2] * Y[2] + Z[3] * Z[3] - Z[2] * Z[2];
    for(int i = 0; i < 3; i++)
      b[i] *= 0.5;
    mat[0][0] = X[1] - X[0];
    mat[0][1] = Y[1] - Y[0];
    mat[0][2] = Z[1] - Z[0];
    mat[1][0] = X[2] - X[1];
    mat[1][1] = Y[2] - Y[1];
    mat[1][2] = Z[2] - Z[1];
    mat[2][0] = X[3] - X[2];
    mat[2][1] = Y[3] - Y[2];
    mat[2][2] = Z[3] - Z[2];
    if(!sys3x3(mat, b, res, &dum)) {
      res[0] = res[1] = res[2] = 10.0e10;
    }
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 10; }
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
  virtual int getNumEdgeVertices(){ return 6; }
  virtual int getNumEdgesRep(){ return 12; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_tetra10[12][2] = {
      {0, 4}, {4, 1},
      {1, 5}, {5, 2},
      {2, 6}, {6, 0},
      {3, 7}, {7, 0},
      {3, 8}, {8, 2},
      {3, 9}, {9, 1}
    };
    return MEdge(getVertex(edges_tetra10[num][0]), getVertex(edges_tetra10[num][1]));
  }
  virtual int getNumFacesRep(){ return 16; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_tetra10[16][3] = {
      {0, 6, 4}, {2, 5, 6}, {1, 4, 5}, {6, 5, 4},
      {0, 4, 7}, {1, 9, 4}, {3, 7, 9}, {4, 9, 7},
      {0, 7, 6}, {3, 8, 7}, {2, 6, 8}, {7, 8, 6},
      {3, 9, 8}, {1, 5, 9}, {2, 8, 5}, {9, 5, 8}
    };
    return MFace(getVertex(trifaces_tetra10[num][0]),
		 getVertex(trifaces_tetra10[num][1]),
		 getVertex(trifaces_tetra10[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_TET_10; }
  virtual int getTypeForUNV(){ return 118; } // solid parabolic tetrahedron
  virtual char *getStringForPOS(){ return "SS2"; }
  virtual char *getStringForBDF(){ return "CTETRA"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
    tmp = _vs[5]; _vs[5] = _vs[3]; _vs[3] = tmp;
  }
};

class MHexahedron : public MElement {
 protected:
  MVertex *_v[8];
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
  virtual int getNumVertices(){ return 8; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 12; }
  virtual MEdge getEdge(int num)
  {
    static const int edges_hexa[12][2] = {
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
    return MEdge(_v[edges_hexa[num][0]], _v[edges_hexa[num][1]]);
  }
  virtual int getNumFaces(){ return 6; }
  virtual MFace getFace(int num)
  {
    static const int quadfaces_hexa[6][4] = {
      {0, 3, 2, 1},
      {0, 1, 5, 4},
      {0, 4, 7, 3},
      {1, 2, 6, 5},
      {2, 3, 7, 6},
      {4, 5, 6, 7}
    };
    return MFace(_v[quadfaces_hexa[num][0]],
		 _v[quadfaces_hexa[num][1]],
		 _v[quadfaces_hexa[num][2]],
		 _v[quadfaces_hexa[num][3]]);
  }
  virtual int getTypeForMSH(){ return MSH_HEX_8; }
  virtual int getTypeForUNV(){ return 115; } // solid linear brick
  virtual char *getStringForPOS(){ return "SH"; }
  virtual char *getStringForBDF(){ return "CHEXA"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
  }
  virtual int getVolumeSign()
  { 
    double mat[3][3];
    mat[0][0] = _v[1]->x() - _v[0]->x();
    mat[0][1] = _v[3]->x() - _v[0]->x();
    mat[0][2] = _v[4]->x() - _v[0]->x();
    mat[1][0] = _v[1]->y() - _v[0]->y();
    mat[1][1] = _v[3]->y() - _v[0]->y();
    mat[1][2] = _v[4]->y() - _v[0]->y();
    mat[2][0] = _v[1]->z() - _v[0]->z();
    mat[2][1] = _v[3]->z() - _v[0]->z();
    mat[2][2] = _v[4]->z() - _v[0]->z();
    return sign(det3x3(mat));
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 20; }
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
  virtual int getNumEdgeVertices(){ return 12; }
  virtual int getNumEdgesRep(){ return 24; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_hexa20[24][2] = {
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
    return MEdge(getVertex(edges_hexa20[num][0]), getVertex(edges_hexa20[num][1]));
  }
  virtual int getNumFacesRep(){ return 36; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_hexa20[36][3] = {
      {0, 9, 8}, {3, 13, 9}, {2, 11, 13}, {1, 8, 11}, {8, 9, 13}, {8, 13, 11},
      {0, 8, 10}, {1, 12, 8}, {5, 16, 12}, {4, 10, 16}, {8, 12, 16}, {8, 16, 10},
      {0, 10, 9}, {4, 17, 10}, {7, 15, 17}, {3, 9, 7}, {9, 10, 17}, {9, 17, 15},
      {1, 11, 12}, {2, 14, 11}, {6, 18, 14}, {5, 12, 18}, {11, 14, 18}, {11, 18, 12},
      {2, 13, 14}, {3, 15, 13}, {7, 19, 15}, {6, 14, 19}, {13, 15, 19}, {13, 19, 14},
      {4, 16, 17}, {5, 18, 16}, {6, 19, 18}, {7, 17, 19}, {16, 18, 19}, {16, 19, 17}
    };
    return MFace(getVertex(trifaces_hexa20[num][0]),
		 getVertex(trifaces_hexa20[num][1]),
		 getVertex(trifaces_hexa20[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_HEX_20; }
  virtual int getTypeForUNV(){ return 116; } // solid parabolic brick
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return "CHEXA"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    MVertex *old[12];
    for(int i = 0; i < 12; i++) old[i] = _vs[i];
    _vs[0] = old[3]; _vs[1] = old[5]; _vs[2] = old[6];
    _vs[3] = old[0]; _vs[4] = old[4]; _vs[5] = old[1];
    _vs[6] = old[2]; _vs[7] = old[7]; _vs[8] = old[10];
    _vs[9] = old[11]; _vs[10] = old[8]; _vs[11] = old[9];
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 27; }
  virtual MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  virtual int getNumEdgeVertices(){ return 12; }
  virtual int getNumFaceVertices(){ return 6; }
  virtual int getNumVolumeVertices(){ return 1; }
  virtual int getNumEdgesRep(){ return 24; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_hexa27[24][2] = {
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
    return MEdge(getVertex(edges_hexa27[num][0]), getVertex(edges_hexa27[num][1]));
  }
  virtual int getNumFacesRep(){ return 48; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_hexa27[48][3] = {
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
    return MFace(getVertex(trifaces_hexa27[num][0]),
		 getVertex(trifaces_hexa27[num][1]),
		 getVertex(trifaces_hexa27[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_HEX_27; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SH2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    MVertex *old[12];
    for(int i = 0; i < 12; i++) old[i] = _vs[i];
    _vs[0] = old[3]; _vs[1] = old[5]; _vs[2] = old[6];
    _vs[3] = old[0]; _vs[4] = old[4]; _vs[5] = old[1];
    _vs[6] = old[2]; _vs[7] = old[7]; _vs[8] = old[10];
    _vs[9] = old[11]; _vs[10] = old[8]; _vs[11] = old[9];
  }
};

class MPrism : public MElement {
 protected:
  MVertex *_v[6];
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
  virtual int getNumVertices(){ return 6; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 9; }
  virtual MEdge getEdge(int num)
  {
    static const int edges_prism[9][2] = {
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
    return MEdge(_v[edges_prism[num][0]], _v[edges_prism[num][1]]);
  }
  virtual int getNumFaces(){ return 5; }
  virtual MFace getFace(int num)
  {
    static const int trifaces_prism[2][3] = {
      {0, 2, 1},
      {3, 4, 5}
    };
    static const int quadfaces_prism[3][4] = {
      {0, 1, 4, 3},
      {0, 3, 5, 2},
      {1, 2, 5, 4}
    };
    if(num < 2)
      return MFace(_v[trifaces_prism[num][0]],
		   _v[trifaces_prism[num][1]],
		   _v[trifaces_prism[num][2]]);
    else
      return MFace(_v[quadfaces_prism[num - 2][0]],
		   _v[quadfaces_prism[num - 2][1]],
		   _v[quadfaces_prism[num - 2][2]],
		   _v[quadfaces_prism[num - 2][3]]);
  }
  virtual int getTypeForMSH(){ return MSH_PRI_6; }
  virtual int getTypeForUNV(){ return 112; } // solid linear wedge
  virtual char *getStringForPOS(){ return "SI"; }
  virtual char *getStringForBDF(){ return "CPENTA"; }
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
  }
  virtual int getVolumeSign()
  { 
    double mat[3][3];
    mat[0][0] = _v[1]->x() - _v[0]->x();
    mat[0][1] = _v[2]->x() - _v[0]->x();
    mat[0][2] = _v[3]->x() - _v[0]->x();
    mat[1][0] = _v[1]->y() - _v[0]->y();
    mat[1][1] = _v[2]->y() - _v[0]->y();
    mat[1][2] = _v[3]->y() - _v[0]->y();
    mat[2][0] = _v[1]->z() - _v[0]->z();
    mat[2][1] = _v[2]->z() - _v[0]->z();
    mat[2][2] = _v[3]->z() - _v[0]->z();
    return sign(det3x3(mat));
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 15; }
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
  virtual int getNumEdgeVertices(){ return 9; }
  virtual int getNumEdgesRep(){ return 18; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_prism15[18][2] = {
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
    return MEdge(getVertex(edges_prism15[num][0]), getVertex(edges_prism15[num][1]));
  }
  virtual int getNumFacesRep(){ return 26; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_prism15[26][3] = {
      {0, 7, 6}, {2, 9, 7}, {1, 6, 9}, {6, 7, 9},
      {3, 12, 13}, {4, 14, 12}, {5, 13, 14}, {12, 14, 13},
      {0, 6, 8}, {1, 10, 6}, {4, 12, 10}, {3, 8, 12}, {6, 10, 12}, {6, 12, 8},
      {0, 8, 7}, {3, 13, 8}, {5, 11, 13}, {2, 7, 11}, {7, 8, 13}, {7, 13, 11},
      {1, 9, 10}, {2, 11, 9}, {5, 14, 11}, {4, 10, 14}, {9, 11, 14}, {9, 14, 10}
    };
    return MFace(getVertex(trifaces_prism15[num][0]),
		 getVertex(trifaces_prism15[num][1]),
		 getVertex(trifaces_prism15[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_PRI_15; }
  virtual int getTypeForUNV(){ return 113; } // solid parabolic wedge
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return "CPENTA"; }
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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 18; }
  virtual MVertex *getVertex(int num){ return num < 6 ? _v[num] : _vs[num - 6]; }
  virtual int getNumEdgeVertices(){ return 9; }
  virtual int getNumFaceVertices(){ return 3; }
  virtual int getNumEdgesRep(){ return 18; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_prism18[18][2] = {
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
    return MEdge(getVertex(edges_prism18[num][0]), getVertex(edges_prism18[num][1]));
  }
  virtual int getNumFacesRep(){ return 32; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_prism18[32][3] = {
      {0, 7, 6}, {2, 9, 7}, {1, 6, 9}, {6, 7, 9},
      {3, 12, 13}, {4, 14, 12}, {5, 13, 14}, {12, 14, 13},
      {0, 6, 15}, {0, 15, 8}, {1, 10, 15}, {1, 15, 6},  
      {4, 12, 15}, {4, 15, 10}, {3, 8, 15}, {3, 15, 12},  
      {0, 8, 16}, {0, 16, 7}, {3, 13, 16}, {3, 16, 8},  
      {5, 11, 16}, {5, 16, 13}, {2, 7, 16}, {2, 16, 11},  
      {1, 9, 17}, {1, 17, 10}, {2, 11, 17}, {2, 17, 9},  
      {5, 14, 17}, {5, 17, 11}, {4, 10, 17}, {4, 17, 14}
    };
    return MFace(getVertex(trifaces_prism18[num][0]),
		 getVertex(trifaces_prism18[num][1]),
		 getVertex(trifaces_prism18[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_PRI_18; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SI2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
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

class MPyramid : public MElement {
 protected:
  MVertex *_v[5];
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
  virtual int getNumVertices(){ return 5; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 8; }
  virtual MEdge getEdge(int num)
  {
    static const int edges_pyramid[8][2] = {
      {0, 1},
      {0, 3},
      {0, 4},
      {1, 2},
      {1, 4},
      {2, 3},
      {2, 4},
      {3, 4}
    };
    return MEdge(_v[edges_pyramid[num][0]], _v[edges_pyramid[num][1]]);
  }
  virtual int getNumFaces(){ return 5; }
  virtual MFace getFace(int num)
  {
    static const int trifaces_pyramid[4][3] = {
      {0, 1, 4},
      {3, 0, 4},
      {1, 2, 4},
      {2, 3, 4}
    };
    if(num < 4)
      return MFace(_v[trifaces_pyramid[num][0]],
		   _v[trifaces_pyramid[num][1]],
		   _v[trifaces_pyramid[num][2]]);
    else
      return MFace(_v[0], _v[3], _v[2], _v[1]);
  }
  virtual int getTypeForMSH(){ return MSH_PYR_5; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SY"; }
  virtual char *getStringForBDF(){ return "CPYRAM"; }
  virtual void revert()
  {
    MVertex *tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
  }
  virtual int getVolumeSign()
  { 
    double mat[3][3];
    mat[0][0] = _v[1]->x() - _v[0]->x();
    mat[0][1] = _v[3]->x() - _v[0]->x();
    mat[0][2] = _v[4]->x() - _v[0]->x();
    mat[1][0] = _v[1]->y() - _v[0]->y();
    mat[1][1] = _v[3]->y() - _v[0]->y();
    mat[1][2] = _v[4]->y() - _v[0]->y();
    mat[2][0] = _v[1]->z() - _v[0]->z();
    mat[2][1] = _v[3]->z() - _v[0]->z();
    mat[2][2] = _v[4]->z() - _v[0]->z();
    return sign(det3x3(mat));
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 13; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual int getNumEdgeVertices(){ return 8; }
  virtual int getNumEdgesRep(){ return 16; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_pyramid13[16][2] = {
      {0, 5}, {5, 1},
      {0, 6}, {6, 3},
      {0, 7}, {7, 4},
      {1, 8}, {8, 2},
      {1, 9}, {9, 4},
      {2, 10}, {10, 3},
      {2, 11}, {11, 4},
      {3, 12}, {12, 4}
    };
    return MEdge(getVertex(edges_pyramid13[num][0]), getVertex(edges_pyramid13[num][1]));
  }
  virtual int getNumFacesRep(){ return 22; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_pyramid13[22][3] = {
      {0, 5, 7}, {1, 9, 5}, {4, 7, 9}, {5, 9, 7},
      {3, 6, 12}, {0, 7, 6}, {4, 12, 7}, {6, 7, 12},
      {1, 8, 9}, {2, 11, 8}, {4, 9, 11}, {8, 11, 9},
      {2, 10, 11}, {3, 12, 10}, {4, 11, 12}, {10, 12, 11},
      {0, 6, 5}, {3, 10, 6}, {2, 8, 10}, {1, 5, 8}, {5, 6, 10}, {5, 10, 8}
    };
    return MFace(getVertex(trifaces_pyramid13[num][0]),
		 getVertex(trifaces_pyramid13[num][1]),
		 getVertex(trifaces_pyramid13[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_PYR_13; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[5]; _vs[5] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[6]; _vs[6] = tmp;
  }
};

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
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 14; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual int getNumEdgeVertices(){ return 8; }
  virtual int getNumFaceVertices(){ return 1; }
  virtual int getNumEdgesRep(){ return 16; }
  virtual MEdge getEdgeRep(int num)
  { 
    static const int edges_pyramid14[16][2] = {
      {0, 5}, {5, 1},
      {0, 6}, {6, 3},
      {0, 7}, {7, 4},
      {1, 8}, {8, 2},
      {1, 9}, {9, 4},
      {2, 10}, {10, 3},
      {2, 11}, {11, 4},
      {3, 12}, {12, 4}
    };
    return MEdge(getVertex(edges_pyramid14[num][0]), getVertex(edges_pyramid14[num][1]));
  }
  virtual int getNumFacesRep(){ return 24; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_pyramid14[24][3] = {
      {0, 5, 7}, {1, 9, 5}, {4, 7, 9}, {5, 9, 7},
      {3, 6, 12}, {0, 7, 6}, {4, 12, 7}, {6, 7, 12},
      {1, 8, 9}, {2, 11, 8}, {4, 9, 11}, {8, 11, 9},
      {2, 10, 11}, {3, 12, 10}, {4, 11, 12}, {10, 12, 11},
      {0, 6, 13}, {0, 13, 5}, {3, 10, 13}, {3, 13, 6}, 
      {2, 8, 13}, {2, 13, 10}, {1, 5, 13}, {1, 13, 8}
    };
    return MFace(getVertex(trifaces_pyramid14[num][0]),
		 getVertex(trifaces_pyramid14[num][1]),
		 getVertex(trifaces_pyramid14[num][2]));
  }
  virtual int getTypeForMSH(){ return MSH_PYR_14; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SY2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void revert()
  {
    MVertex *tmp;
    tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
    tmp = _vs[1]; _vs[1] = _vs[5]; _vs[5] = tmp;
    tmp = _vs[2]; _vs[2] = _vs[6]; _vs[6] = tmp;
  }
};

#endif
