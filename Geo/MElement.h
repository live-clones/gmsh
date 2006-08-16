#ifndef _MELEMENT_H_
#define _MELEMENT_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

// the reference topology is defined in Mesh/{Edge,Face}.cpp
extern int edges_tetra[6][2];
extern int edges_quad[4][2];
extern int edges_hexa[12][2];
extern int edges_prism[9][2];
extern int edges_pyramid[8][2];
extern int trifaces_tetra[4][3];
extern int trifaces_prism[2][3];
extern int trifaces_pyramid[4][3];
extern int quadfaces_hexa[6][4];
extern int quadfaces_prism[3][4];
extern int quadfaces_pyramid[1][4];

class MElement 
{
 private:
  static int _globalNum;
  int _num, _partition;
  char _visible;

 public :
  MElement(int num=0, int part=0) 
    : _partition(part), _visible(true) 
  {
    if(num){
      _num = num;
      _globalNum = std::max(_globalNum, _num);
    }
    else{
      _num = ++_globalNum;
    }
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

  // returns the partition to which the element belongs
  virtual int getPartition(){ return _partition; }

  // get/set the visibility flag
  virtual char getVisibility(){ return _visible; }
  virtual void setVisibility(char val){ _visible = val; }

  // get the vertices
  virtual int getNumVertices() = 0;
  virtual MVertex *getVertex(int num) = 0;

  // get the number of vertices associated with edges, faces and
  // volumes (nonzero only for higher order elements)
  virtual int getNumEdgeVertices(){ return 0; }
  virtual int getNumFaceVertices(){ return 0; }
  virtual int getNumVolumeVertices(){ return 0; }

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

  // compute and change the orientation of 3D elements to get
  // positive volume
  virtual double getVolume(){ return 0.; }
  virtual int getVolumeSign(){ return 1; }
  virtual void setVolumePositive(){}

  // IO routines
  virtual void writeMSH(FILE *fp, double version=1.0, int num=0, 
			int elementary=1, int physical=1);
  virtual void writePOS(FILE *fp, double scalingFactor=1.0,
			int elementary=1);
  virtual void writeSTL(FILE *fp, double scalingFactor=1.0);
  virtual void writeVRML(FILE *fp);
  virtual void writeUNV(FILE *fp, int elementary);
  virtual void writeMESH(FILE *fp, int elementary);
  virtual char *getStringForPOS() = 0;
  virtual int getTypeForMSH() = 0;
  virtual int getTypeForUNV() = 0;
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
  ~MLine(){}
  virtual int getDim(){ return 1; }
  inline int getNumVertices(){ return 2; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 1; }
  virtual MEdge getEdge(int num){ return MEdge(_v[0], _v[1], this); }
  virtual int getNumFaces(){ return 0; }
  virtual MFace getFace(int num){ throw; }
  int getTypeForMSH(){ return LGN1; }
  int getTypeForUNV(){ return 21; } // BEAM
  char *getStringForPOS(){ return "SL"; }
};

class MLine2 : public MLine {
 protected:
  MVertex *_vs[1];
 public :
  MLine2(MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0) 
    : MLine(v0, v1, num, part)
  {
    _vs[0] = v2;
  }
  ~MLine2(){}
  inline int getPolynomialOrder(){ return 2; }
  inline int getNumVertices(){ return 3; }
  inline MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  inline int getNumEdgeVertices(){ return 1; }
  int getNumEdgesRep(){ return 2; }
  MEdge getEdgeRep(int num)
  { 
    static int edges_lin2[2][2] = {
      {0, 2}, {2, 1},
    };
    int i0 = edges_lin2[num][0];
    int i1 = edges_lin2[num][1];
    return MEdge(i0 < 2 ? _v[i0] : _vs[i0 - 2], i1 < 2 ? _v[i1] : _vs[i1 - 2], this);
  }
  int getTypeForMSH(){ return LGN2; }
  int getTypeForUNV(){ return 24; } // BEAM2
  char *getStringForPOS(){ return "SL2"; }
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
  ~MTriangle(){}
  virtual int getDim(){ return 2; }
  inline int getNumVertices(){ return 3; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 3; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_tetra[num][0]], _v[edges_tetra[num][1]], this);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num)
  { 
    return MFace(_v[0], _v[1], _v[2]); 
  }
  int getTypeForMSH(){ return TRI1; }
  int getTypeForUNV(){ return 91; } // THINSHLL
  char *getStringForPOS(){ return "ST"; }
};

class MTriangle2 : public MTriangle {
 protected:
  MVertex *_vs[3];
 public :
  MTriangle2(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4,
	     MVertex *v5, int num=0, int part=0) 
    : MTriangle(v0, v1, v2, num, part)
  {
    _vs[0] = v3; _vs[1] = v4; _vs[2] = v5;
  }
  ~MTriangle2(){}
  inline int getPolynomialOrder(){ return 2; }
  inline int getNumVertices(){ return 6; }
  inline MVertex *getVertex(int num){ return num < 3 ? _v[num] : _vs[num - 3]; }
  inline int getNumEdgeVertices(){ return 3; }
  int getNumEdgesRep(){ return 6; }
  MEdge getEdgeRep(int num)
  { 
    static int edges_tri2[6][2] = {
      {0, 3}, {3, 1},
      {1, 4}, {4, 2},
      {2, 5}, {5, 0},
    };
    int i0 = edges_tri2[num][0];
    int i1 = edges_tri2[num][1];
    return MEdge(i0 < 3 ? _v[i0] : _vs[i0 - 3], i1 < 3 ? _v[i1] : _vs[i1 - 3], this);
  }
  int getNumFacesRep(){ return 4; }
  MFace getFaceRep(int num)
  { 
    static int trifaces_tri2[4][3] = {
      {0, 3, 5},
      {1, 4, 3},
      {2, 5, 4},
      {3, 4, 5},
    };
    int i0 = trifaces_tri2[num][0];
    int i1 = trifaces_tri2[num][1];
    int i2 = trifaces_tri2[num][2];
    return MFace(i0 < 3 ? _v[i0] : _vs[i0 - 3],
		 i1 < 3 ? _v[i1] : _vs[i1 - 3],
		 i2 < 3 ? _v[i2] : _vs[i2 - 3]);
  }
  int getTypeForMSH(){ return TRI2; }
  int getTypeForUNV(){ return 92; } // THINSHLL2
  char *getStringForPOS(){ return "ST2"; }
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
  ~MQuadrangle(){}
  virtual int getDim(){ return 2; }
  inline int getNumVertices(){ return 4; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 4; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_quad[num][0]], _v[edges_quad[num][1]], this);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num){ return MFace(_v[0], _v[1], _v[2], _v[3]); }
  int getTypeForMSH(){ return QUA1; }
  int getTypeForUNV(){ return 94; } // QUAD
  char *getStringForPOS(){ return "SQ"; }
};

class MQuadrangle2 : public MQuadrangle {
 protected:
  MVertex *_vs[5];
 public :
  MQuadrangle2(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
	       MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, int num=0, int part=0) 
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _v[1] = v5; _v[2] = v6; _v[3] = v7; _v[4] = v8;
  }
  ~MQuadrangle2(){}
  inline int getPolynomialOrder(){ return 2; }
  inline int getNumVertices(){ return 9; }
  inline MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  inline int getNumEdgeVertices(){ return 4; }
  inline int getNumFaceVertices(){ return 1; }
  // TODO: edgeRep, faceRep
  int getTypeForMSH(){ return QUA2; }
  int getTypeForUNV(){ return 95; } // ???? QUAD2
  char *getStringForPOS(){ return "SQ2"; }
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
  ~MTetrahedron(){}
  virtual int getDim(){ return 3; }
  inline int getNumVertices(){ return 4; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 4; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_tetra[num][0]], _v[edges_tetra[num][1]], this);
  }
  virtual int getNumFaces(){ return 4; }
  virtual MFace getFace(int num)
  {
    return MFace(_v[trifaces_tetra[num][0]],
		 _v[trifaces_tetra[num][1]],
		 _v[trifaces_tetra[num][2]]);
  }
  int getTypeForMSH(){ return TET1; }
  int getTypeForUNV(){ return 111; } // SOLIDFEM
  char *getStringForPOS(){ return "SS"; }
  virtual double getVolume()
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
    return det3x3(mat) / 6.;
  }
  virtual int getVolumeSign(){ return sign(getVolume()); }
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    }
  }
  virtual double gammaShapeMeasure();
  virtual double etaShapeMeasure();
};

class MTetrahedron2 : public MTetrahedron {
 protected:
  MVertex *_vs[6];
 public :
  MTetrahedron2(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
		MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
		int num=0, int part=0) 
    : MTetrahedron(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _vs[1] = v5; _vs[2] = v6; _vs[3] = v7; _vs[4] = v8; _vs[5] = v9;
  }
  ~MTetrahedron2(){}
  inline int getPolynomialOrder(){ return 2; }
  inline int getNumVertices(){ return 10; }
  inline MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  inline int getNumEdgeVertices(){ return 6; }
  // TODO: edgeRep, faceRep
  int getTypeForMSH(){ return TET2; }
  int getTypeForUNV(){ return 118; } // SOLIDFEM2
  char *getStringForPOS(){ return "SS2"; }
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
      tmp = _vs[1]; _vs[1] = _vs[2]; _vs[2] = tmp;
      tmp = _vs[5]; _vs[5] = _vs[3]; _vs[3] = tmp;
    }
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
  ~MHexahedron(){}
  virtual int getDim(){ return 3; }
  inline int getNumVertices(){ return 8; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 12; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_hexa[num][0]], _v[edges_hexa[num][1]], this);
  }
  virtual int getNumFaces(){ return 6; }
  virtual MFace getFace(int num)
  {
    return MFace(_v[quadfaces_hexa[num][0]],
		 _v[quadfaces_hexa[num][1]],
		 _v[quadfaces_hexa[num][2]],
		 _v[quadfaces_hexa[num][3]]);
  }
  int getTypeForMSH(){ return HEX1; }
  int getTypeForUNV(){ return 115; } // BRICK
  char *getStringForPOS(){ return "SH"; }
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
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
      tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    }
  }
};

class MHexahedron2 : public MHexahedron {
 protected:
  MVertex *_vs[19];
 public :
  MHexahedron2(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
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
  }
  ~MHexahedron2(){}
  inline int getPolynomialOrder(){ return 2; }
  inline int getNumVertices(){ return 27; }
  inline MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  inline int getNumEdgeVertices(){ return 12; }
  inline int getNumFaceVertices(){ return 6; }
  inline int getNumVolumeVertices(){ return 1; }
  // TODO: edgeRep, faceRep
  int getTypeForMSH(){ return HEX2; }
  int getTypeForUNV(){ return 116; } // ???? BRICK2
  char *getStringForPOS(){ return "SH2"; }
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
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
  ~MPrism(){}
  virtual int getDim(){ return 3; }
  inline int getNumVertices(){ return 6; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 9; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_prism[num][0]], _v[edges_prism[num][1]], this);
  }
  virtual int getNumFaces(){ return 5; }
  virtual MFace getFace(int num)
  {
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
  int getTypeForMSH(){ return PRI1; }
  int getTypeForUNV(){ return 112; } // WEDGE
  char *getStringForPOS(){ return "SI"; }
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
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
      tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
    }
  }
};

class MPrism2 : public MPrism {
 protected:
  MVertex *_vs[12];
 public :
  MPrism2(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
	  MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
	  MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, MVertex *v14,
	  MVertex *v15, MVertex *v16, MVertex *v17, int num=0, int part=0) 
    : MPrism(v0, v1, v2, v3, v4, v5, num, part)
  {
    _vs[0] = v6; _vs[1] = v7; _vs[2] = v8; _vs[3] = v9; _vs[4] = v10; 
    _vs[5] = v11; _vs[6] = v12; _vs[7] = v13; _vs[8] = v14; _vs[9] = v15; 
    _vs[10] = v16; _vs[11] = v17; 
  }
  ~MPrism2(){}
  inline int getPolynomialOrder(){ return 2; }
  inline int getNumVertices(){ return 18; }
  inline MVertex *getVertex(int num){ return num < 6 ? _v[num] : _vs[num - 6]; }
  inline int getNumEdgeVertices(){ return 9; }
  inline int getNumFaceVertices(){ return 3; }
  // TODO: edgeRep, faceRep
  int getTypeForMSH(){ return PRI2; }
  int getTypeForUNV(){ return 113; } // ???? WEDGE2
  char *getStringForPOS(){ return "SI2"; }
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
      tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
      tmp = _vs[1]; _vs[1] = _vs[3]; _vs[3] = tmp;
      tmp = _vs[2]; _vs[2] = _vs[4]; _vs[4] = tmp;
      tmp = _vs[7]; _vs[7] = _vs[8]; _vs[8] = tmp;
    }
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
  ~MPyramid(){}
  virtual int getDim(){ return 3; }
  inline int getNumVertices(){ return 5; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 8; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_pyramid[num][0]], _v[edges_pyramid[num][1]], this);
  }
  virtual int getNumFaces(){ return 5; }
  virtual MFace getFace(int num)
  {
    if(num < 4)
      return MFace(_v[trifaces_pyramid[num][0]],
		   _v[trifaces_pyramid[num][1]],
		   _v[trifaces_pyramid[num][2]]);
    else
      return MFace(_v[quadfaces_pyramid[num - 4][0]],
		   _v[quadfaces_pyramid[num - 4][1]],
		   _v[quadfaces_pyramid[num - 4][2]],
		   _v[quadfaces_pyramid[num - 4][3]]);
  }
  int getTypeForMSH(){ return PYR1; }
  int getTypeForUNV(){ throw; }
  char *getStringForPOS(){ return "SY"; }
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
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    }
  }
};

class MPyramid2 : public MPyramid {
 protected:
  MVertex *_vs[9];
 public :
  MPyramid2(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4, 
	    MVertex *v5, MVertex *v6, MVertex *v7, MVertex *v8, MVertex *v9,
	    MVertex *v10, MVertex *v11, MVertex *v12, MVertex *v13, 
	    int num=0, int part=0) 
    : MPyramid(v0, v1, v2, v3, v4, num, part)
  {
    _vs[0] = v5; _vs[1] = v6; _vs[2] = v7; _vs[3] = v8; _vs[4] = v9; 
    _vs[5] = v10; _vs[6] = v11; _vs[7] = v12; _vs[8] = v13; 
  }
  ~MPyramid2(){}
  inline int getPolynomialOrder(){ return 2; }
  inline int getNumVertices(){ return 14; }
  inline MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  inline int getNumEdgeVertices(){ return 8; }
  inline int getNumFaceVertices(){ return 1; }
  // TODO: edgeRep, faceRep
  int getTypeForMSH(){ return PYR2; }
  int getTypeForUNV(){ throw; }
  char *getStringForPOS(){ return "SY2"; }
  void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
      tmp = _vs[0]; _vs[0] = _vs[3]; _vs[3] = tmp;
      tmp = _vs[1]; _vs[1] = _vs[5]; _vs[5] = tmp;
      tmp = _vs[2]; _vs[2] = _vs[6]; _vs[6] = tmp;
    }
  }
};

#endif
