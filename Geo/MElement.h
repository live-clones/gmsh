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
  virtual int getTypeForMSH(){ return LIN_2; }
  virtual int getTypeForUNV(){ return 21; } // linear beam
  virtual char *getStringForPOS(){ return "SL"; }
  virtual char *getStringForBDF(){ return "CBAR"; }
};

class MLine3 : public MLine {
 protected:
  MVertex *_vs[1];
 public :
  MLine3(MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0) 
    : MLine(v0, v1, num, part)
  {
    _vs[0] = v2;
  }
  MLine3(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MLine(v, num, part)
  {
    _vs[0] = v[2];
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
    static const int edges_lin2[2][2] = {
      {0, 2}, {2, 1},
    };
    int i0 = edges_lin2[num][0];
    int i1 = edges_lin2[num][1];
    return MEdge(i0 < 2 ? _v[i0] : _vs[i0 - 2], i1 < 2 ? _v[i1] : _vs[i1 - 2]);
  }
  virtual int getTypeForMSH(){ return LIN_3; }
  virtual int getTypeForUNV(){ return 24; } // parabolic beam
  virtual char *getStringForPOS(){ return "SL2"; }
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
  virtual int getNumVertices(){ return 3; }
  virtual MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 3; }
  virtual MEdge getEdge(int num)
  {
    return MEdge(_v[edges_tetra[num][0]], _v[edges_tetra[num][1]]);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num)
  { 
    return MFace(_v[0], _v[1], _v[2]); 
  }
  virtual int getTypeForMSH(){ return TRI_3; }
  virtual int getTypeForUNV(){ return 91; } // thin shell linear triangle
  virtual char *getStringForPOS(){ return "ST"; }
  virtual char *getStringForBDF(){ return "CTRIA3"; }
  virtual void revert() 
  {
    MVertex *vv = _v[0];
    _v[0] = _v[1];
    _v[1] = vv;
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
  }
  MTriangle6(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MTriangle(v, num, part)
  {
    for(int i = 0; i < 3; i++) _vs[i] = v[3 + i];
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
    static const int edges_tri2[6][2] = {
      {0, 3}, {3, 1},
      {1, 4}, {4, 2},
      {2, 5}, {5, 0},
    };
    int i0 = edges_tri2[num][0];
    int i1 = edges_tri2[num][1];
    return MEdge(i0 < 3 ? _v[i0] : _vs[i0 - 3], i1 < 3 ? _v[i1] : _vs[i1 - 3]);
  }
  virtual int getNumFacesRep(){ return 4; }
  virtual MFace getFaceRep(int num)
  { 
    static const int trifaces_tri2[4][3] = {
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
  virtual int getTypeForMSH(){ return TRI_6; }
  virtual int getTypeForUNV(){ return 92; } // thin shell parabolic triangle
  virtual char *getStringForPOS(){ return "ST2"; }
  virtual char *getStringForBDF(){ return "CTRIA6"; }
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
    return MEdge(_v[edges_quad[num][0]], _v[edges_quad[num][1]]);
  }
  virtual int getNumFaces(){ return 1; }
  virtual MFace getFace(int num){ return MFace(_v[0], _v[1], _v[2], _v[3]); }
  virtual int getTypeForMSH(){ return QUA_4; }
  virtual int getTypeForUNV(){ return 94; } // thin shell linear quadrilateral
  virtual char *getStringForPOS(){ return "SQ"; }
  virtual char *getStringForBDF(){ return "CQUAD4"; }
  virtual void revert() 
  {
    MVertex *vv = _v[1];
    _v[1] = _v[3];
    _v[3] = vv;
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
  }
  MQuadrangle8(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 4; i++) _vs[i] = v[4 + i];
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
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return QUA_8; }
  virtual int getTypeForUNV(){ return 95; } // shell parabolic quadrilateral
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return "CQUAD8"; }
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
  }
  MQuadrangle9(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MQuadrangle(v, num, part)
  {
    for(int i = 0; i < 5; i++) _vs[i] = v[4 + i];
  }
  ~MQuadrangle9(){}
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 9; }
  virtual MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  virtual int getNumEdgeVertices(){ return 4; }
  virtual int getNumFaceVertices(){ return 1; }
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return QUA_9; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SQ2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
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
    return MEdge(_v[edges_tetra[num][0]], _v[edges_tetra[num][1]]);
  }
  virtual int getNumFaces(){ return 4; }
  virtual MFace getFace(int num)
  {
    return MFace(_v[trifaces_tetra[num][0]],
		 _v[trifaces_tetra[num][1]],
		 _v[trifaces_tetra[num][2]]);
  }
  virtual int getTypeForMSH(){ return TET_4; }
  virtual int getTypeForUNV(){ return 111; } // solid linear tetrahedron
  virtual char *getStringForPOS(){ return "SS"; }
  virtual char *getStringForBDF(){ return "CTETRA"; }
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
  virtual void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
    }
  }
  virtual double gammaShapeMeasure();
  virtual double etaShapeMeasure();
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
  }
  MTetrahedron10(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MTetrahedron(v, num, part)
  {
    for(int i = 0; i < 6; i++) _vs[i] = v[4 + i];
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
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return TET_10; }
  virtual int getTypeForUNV(){ return 118; } // solid parabolic tetrahedron
  virtual char *getStringForPOS(){ return "SS2"; }
  virtual char *getStringForBDF(){ return "CTETRA"; }
  virtual void setVolumePositive()
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
    return MEdge(_v[edges_hexa[num][0]], _v[edges_hexa[num][1]]);
  }
  virtual int getNumFaces(){ return 6; }
  virtual MFace getFace(int num)
  {
    return MFace(_v[quadfaces_hexa[num][0]],
		 _v[quadfaces_hexa[num][1]],
		 _v[quadfaces_hexa[num][2]],
		 _v[quadfaces_hexa[num][3]]);
  }
  virtual int getTypeForMSH(){ return HEX_8; }
  virtual int getTypeForUNV(){ return 115; } // solid linear brick
  virtual char *getStringForPOS(){ return "SH"; }
  virtual char *getStringForBDF(){ return "CHEXA"; }
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
  virtual void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
      tmp = _v[4]; _v[4] = _v[6]; _v[6] = tmp;
    }
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
  }
  MHexahedron20(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[8 + i];
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
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return HEX_20; }
  virtual int getTypeForUNV(){ return 116; } // solid parabolic brick
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return "CHEXA"; }
  virtual void setVolumePositive()
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
  }
  MHexahedron27(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MHexahedron(v, num, part)
  {
    for(int i = 0; i < 19; i++) _vs[i] = v[8 + i];
  }
  ~MHexahedron27(){}
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 27; }
  virtual MVertex *getVertex(int num){ return num < 8 ? _v[num] : _vs[num - 8]; }
  virtual int getNumEdgeVertices(){ return 12; }
  virtual int getNumFaceVertices(){ return 6; }
  virtual int getNumVolumeVertices(){ return 1; }
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return HEX_27; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SH2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void setVolumePositive()
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
    return MEdge(_v[edges_prism[num][0]], _v[edges_prism[num][1]]);
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
  virtual int getTypeForMSH(){ return PRI_6; }
  virtual int getTypeForUNV(){ return 112; } // solid linear wedge
  virtual char *getStringForPOS(){ return "SI"; }
  virtual char *getStringForBDF(){ return "CPENTA"; }
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
  virtual void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[1]; _v[1] = tmp;
      tmp = _v[3]; _v[3] = _v[4]; _v[4] = tmp;
    }
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
  }
  MPrism15(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 9; i++) _vs[i] = v[6 + i];
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
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return PRI_15; }
  virtual int getTypeForUNV(){ return 113; } // solid parabolic wedge
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return "CPENTA"; }
  virtual void setVolumePositive()
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
  }
  MPrism18(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPrism(v, num, part)
  {
    for(int i = 0; i < 12; i++) _vs[i] = v[6 + i];
  }
  ~MPrism18(){}
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 18; }
  virtual MVertex *getVertex(int num){ return num < 6 ? _v[num] : _vs[num - 6]; }
  virtual int getNumEdgeVertices(){ return 9; }
  virtual int getNumFaceVertices(){ return 3; }
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return PRI_18; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SI2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void setVolumePositive()
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
    return MEdge(_v[edges_pyramid[num][0]], _v[edges_pyramid[num][1]]);
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
  virtual int getTypeForMSH(){ return PYR_5; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SY"; }
  virtual char *getStringForBDF(){ return "CPYRAM"; }
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
  virtual void setVolumePositive()
  {
    if(getVolumeSign() < 0){
      MVertex *tmp;
      tmp = _v[0]; _v[0] = _v[2]; _v[2] = tmp;
    }
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
  }
  MPyramid13(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPyramid(v, num, part)
  {
    for(int i = 0; i < 8; i++) _vs[i] = v[5 + i];
  }
  ~MPyramid13(){}
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 13; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual int getNumEdgeVertices(){ return 8; }
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return PYR_13; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return 0; } // not available
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void setVolumePositive()
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
  }
  MPyramid14(std::vector<MVertex*> &v, int num=0, int part=0) 
    : MPyramid(v, num, part)
  {
    for(int i = 0; i < 9; i++) _vs[i] = v[5 + i];
  }
  ~MPyramid14(){}
  virtual int getPolynomialOrder(){ return 2; }
  virtual int getNumVertices(){ return 14; }
  virtual MVertex *getVertex(int num){ return num < 5 ? _v[num] : _vs[num - 5]; }
  virtual int getNumEdgeVertices(){ return 8; }
  virtual int getNumFaceVertices(){ return 1; }
  // TODO: edgeRep, faceRep
  virtual int getTypeForMSH(){ return PYR_14; }
  virtual int getTypeForUNV(){ return 0; } // not available
  virtual char *getStringForPOS(){ return "SY2"; }
  virtual char *getStringForBDF(){ return 0; } // not available
  virtual void setVolumePositive()
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
