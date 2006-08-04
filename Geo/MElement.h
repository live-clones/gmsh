#ifndef _MELEMENT_H_
#define _MELEMENT_H_

#include <stdio.h>
#include <algorithm>
#include "GmshDefines.h"
#include "MVertex.h"

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
  bool _visible;

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

  // returns the tag of the element
  virtual int getNum(){ return _num; }

  // returns the partition to which the element belongs
  virtual int getPartition(){ return _partition; }

  // get/set the visibility flag
  virtual bool isVisible(){ return _visible; }
  virtual void setVisible(bool val){ _visible = val; }

  // get the vertices
  virtual int getNumVertices() = 0;
  virtual MVertex *getVertex(int num) = 0;

  // get the edges
  virtual int getNumEdges() = 0;
  virtual void getEdge(int num, MVertex *v[2]) = 0;

  // get an edge representation for drawing
  virtual int getNumEdgesRep(){ return getNumEdges(); }
  virtual void getEdgeRep(int num, MVertex *v[2]){ getEdgeRep(num, v); }

  // get the faces
  virtual int getNumFaces() = 0;
  virtual void getFace(int num, MVertex *v[4]) = 0;

  // get a face representation for drawing
  virtual int getNumFacesRep(){ return getNumFaces(); }
  virtual void getFaceRep(int num, MVertex *v[4]){ getFace(num, v); }

  // get the max/min edge length
  virtual double maxEdge();
  virtual double minEdge();

  // get the quality measures
  virtual double rhoShapeMeasure();
  virtual double gammaShapeMeasure(){ return 0.; }
  virtual double etaShapeMeasure(){ return 0.; }

  // computes the barycenter
  virtual void cog(double &x, double &y, double &z);

  // IO routines
  virtual void writeMSH(FILE *fp, double version=1.0, int num=0, 
			int elementary=1, int physical=1);
  virtual void writePOS(FILE *fp);
  virtual char *getStringForPOS() = 0;
  virtual int getTypeForMSH() = 0;
};

class MLine : public MElement {
 protected:
  MVertex *_v[2];
 public :
  MLine (MVertex *v0, MVertex *v1, int num=0, int part=0) 
    : MElement (num, part)
  {
    _v[0] = v0; _v[1] = v1;
  }
  ~MLine(){}
  inline int getNumVertices(){ return 2; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 1; }
  virtual void getEdge(int num, MVertex *v[2])
  {
    v[0] = _v[0]; v[1] = _v[1];
  }
  virtual int getNumFaces(){ return 0; }
  virtual void getFace(int num, MVertex *v[4]) 
  { 
    v[0] = v[1] = v[2] = v[3] = 0; 
  }
  int getTypeForMSH(){ return LGN1; }
  char *getStringForPOS(){ return "SL"; }
};

class MLine2 : public MLine {
 protected:
  MVertex *_vs[1];
 public :
  MLine2 (MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0) 
    : MLine(v0, v1, num, part)
  {
    _vs[0] = v2;
  }
  ~MLine2(){}
  inline int getNumVertices(){ return 3; }
  inline MVertex *getVertex(int num){ return num < 2 ? _v[num] : _vs[num - 2]; }
  int getNumEdgesRep(){ return 2; }
  void getEdgeRep(int num, MVertex *v[2])
  { 
    static int edges_lin2[2][2] = {
      {0, 2}, {2, 1},
    };
    int i0 = edges_lin2[num][0];
    int i1 = edges_lin2[num][1];
    v[0] = i0 < 2? _v[i0] : _vs[i0 - 2];
    v[1] = i1 < 2? _v[i1] : _vs[i1 - 2];
  }
  int getTypeForMSH(){ return LGN2; }
  char *getStringForPOS(){ return "SL2"; }
};

class MTriangle : public MElement {
 protected:
  MVertex *_v[3];
 public :
  MTriangle (MVertex *v0, MVertex *v1, MVertex *v2, int num=0, int part=0) 
    : MElement (num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2;
  }
  ~MTriangle(){}
  inline int getNumVertices(){ return 3; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 3; }
  virtual void getEdge(int num, MVertex *v[2])
  {
    v[0] = _v[edges_tetra[num][0]];
    v[1] = _v[edges_tetra[num][1]];
  }
  virtual int getNumFaces(){ return 1; }
  virtual void getFace(int num, MVertex *v[4])
  {
    v[0] = _v[0]; v[1] = _v[1]; v[2] = _v[2]; v[3] = 0;
  }
  int getTypeForMSH(){ return TRI1; }
  char *getStringForPOS(){ return "ST"; }
};

class MTriangle2 : public MTriangle {
 protected:
  MVertex *_vs[3];
 public :
  MTriangle2 (MVertex *v0, MVertex *v1, MVertex *v2, 
	      MVertex *v3, MVertex *v4, MVertex *v5, 
	      int num=0, int part=0) 
    : MTriangle(v0, v1, v2, num, part)
  {
    _vs[0] = v3; _vs[1] = v4; _vs[2] = v5;
  }
  ~MTriangle2(){}
  inline int getNumVertices(){ return 6; }
  inline MVertex *getVertex(int num){ return num < 3 ? _v[num] : _vs[num - 3]; }
  int getNumEdgesRep(){ return 6; }
  void getEdgeRep(int num, MVertex *v[2])
  { 
    static int edges_tri2[6][2] = {
      {0, 3}, {3, 1},
      {1, 4}, {4, 2},
      {2, 5}, {5, 0},
    };
    int i0 = edges_tri2[num][0];
    int i1 = edges_tri2[num][1];
    v[0] = i0 < 3? _v[i0] : _vs[i0 - 3];
    v[1] = i1 < 3? _v[i1] : _vs[i1 - 3];
  }
  int getNumFacesRep(){ return 4; }
  void getFaceRep(int num, MVertex *v[4])
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
    v[0] = i0 < 3? _v[i0] : _vs[i0 - 3];
    v[1] = i1 < 3? _v[i1] : _vs[i1 - 3];
    v[2] = i2 < 3? _v[i2] : _vs[i2 - 3];
    v[3] = 0;
  }
  int getTypeForMSH(){ return TRI2; }
  char *getStringForPOS(){ return "ST2"; }
};

class MQuadrangle : public MElement {
 protected:
  MVertex *_v[4];
 public :
  MQuadrangle(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, 
	      int num=0, int part=0) 
    : MElement (num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
  }
  ~MQuadrangle(){}
  inline int getNumVertices(){ return 4; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 4; }
  virtual void getEdge(int num, MVertex *v[2])
  {
    v[0] = _v[edges_quad[num][0]];
    v[1] = _v[edges_quad[num][1]];
  }
  int getNumFaces(){ return 1; }
  void getFace(int num, MVertex *v[4])
  {
    v[0] = _v[0]; v[1] = _v[1]; v[2] = _v[2]; v[3] = _v[3];
  }
  int getTypeForMSH(){ return QUA1; }
  char *getStringForPOS(){ return "SQ"; }
};

class MQuadrangle2 : public MQuadrangle {
 protected:
  MVertex *_vs[5];
 public :
  MQuadrangle2(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, 
	       MVertex *v4, MVertex *v5, MVertex *v6, MVertex *v7, 
	       MVertex *v8, int num=0, int part=0) 
    : MQuadrangle(v0, v1, v2, v3, num, part)
  {
    _vs[0] = v4; _v[1] = v5; _v[2] = v6; _v[3] = v7; _v[4] = v8;
  }
  ~MQuadrangle2(){}
  inline int getNumVertices(){ return 9; }
  inline MVertex *getVertex(int num){ return num < 4 ? _v[num] : _vs[num - 4]; }
  int getTypeForMSH(){ return QUA2; }
  char *getStringForPOS(){ return "SQ2"; }
};

class MTetrahedron : public MElement {
 protected:
  MVertex *_v[4];
 public :
  MTetrahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, 
	       int num=0, int part=0) 
    : MElement (num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
  }
  ~MTetrahedron(){}
  inline int getNumVertices(){ return 4; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 4; }
  virtual void getEdge(int num, MVertex *v[2])
  {
    v[0] = _v[edges_tetra[num][0]];
    v[1] = _v[edges_tetra[num][1]];
  }
  int getNumFaces(){ return 4; }
  void getFace(int num, MVertex *v[4])
  {
    v[0] = _v[trifaces_tetra[num][0]];
    v[1] = _v[trifaces_tetra[num][1]];
    v[2] = _v[trifaces_tetra[num][2]];
    v[3] = 0;
  }
  int getTypeForMSH(){ return TET1; }
  char *getStringForPOS(){ return "SS"; }
};

class MHexahedron : public MElement {
 protected:
  MVertex *_v[8];
 public :
  MHexahedron(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, 
	      MVertex *v4, MVertex *v5, MVertex *v6, MVertex *v7, 
	      int num=0, int part=0) 
    : MElement (num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
    _v[4] = v4; _v[5] = v5; _v[6] = v6; _v[7] = v7;
  }
  ~MHexahedron(){}
  inline int getNumVertices(){ return 8; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 12; }
  virtual void getEdge(int num, MVertex *v[2])
  {
    v[0] = _v[edges_hexa[num][0]];
    v[1] = _v[edges_hexa[num][1]];
  }
  int getNumFaces(){ return 6; }
  void getFace(int num, MVertex *v[4])
  {
    v[0] = _v[quadfaces_hexa[num][0]];
    v[1] = _v[quadfaces_hexa[num][1]];
    v[2] = _v[quadfaces_hexa[num][2]];
    v[3] = _v[quadfaces_hexa[num][3]];
  }
  int getTypeForMSH(){ return HEX1; }
  char *getStringForPOS(){ return "SH"; }
};

class MPrism : public MElement {
 protected:
  MVertex *_v[6];
 public :
  MPrism(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, 
	 MVertex *v4, MVertex *v5, int num=0, int part=0) 
    : MElement (num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
    _v[4] = v4; _v[5] = v5; 
  }
  ~MPrism(){}
  inline int getNumVertices(){ return 6; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 9; }
  virtual void getEdge(int num, MVertex *v[2])
  {
    v[0] = _v[edges_prism[num][0]];
    v[1] = _v[edges_prism[num][1]];
  }
  int getNumFaces(){ return 5; }
  void getFace(int num, MVertex *v[4])
  {
    if(num < 3){
      v[0] = _v[trifaces_prism[num][0]];
      v[1] = _v[trifaces_prism[num][1]];
      v[2] = _v[trifaces_prism[num][2]];
      v[3] = 0;
    }
    else{
      v[0] = _v[quadfaces_prism[num - 3][0]];
      v[1] = _v[quadfaces_prism[num - 3][1]];
      v[2] = _v[quadfaces_prism[num - 3][2]];
      v[3] = _v[quadfaces_prism[num - 3][3]];
    }
  }
  int getTypeForMSH(){ return PRI1; }
  char *getStringForPOS(){ return "SI"; }
};

class MPyramid : public MElement {
 protected:
  MVertex *_v[5];
 public :
  MPyramid(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3, 
	   MVertex *v4, int num=0, int part=0) 
    : MElement (num, part)
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3; _v[4] = v4;
  }
  ~MPyramid(){}
  inline int getNumVertices(){ return 5; }
  inline MVertex *getVertex(int num){ return _v[num]; }
  virtual int getNumEdges(){ return 8; }
  virtual void getEdge(int num, MVertex *v[2])
  {
    v[0] = _v[edges_pyramid[num][0]];
    v[1] = _v[edges_pyramid[num][1]];
  }
  int getNumFaces(){ return 5; }
  void getFace(int num, MVertex *v[4])
  {
    if(num < 4){
      v[0] = _v[trifaces_pyramid[num][0]];
      v[1] = _v[trifaces_pyramid[num][1]];
      v[2] = _v[trifaces_pyramid[num][2]];
      v[3] = 0;
    }
    else{
      v[0] = _v[quadfaces_pyramid[num - 4][0]];
      v[1] = _v[quadfaces_pyramid[num - 4][1]];
      v[2] = _v[quadfaces_pyramid[num - 4][2]];
      v[3] = _v[quadfaces_pyramid[num - 4][3]];
    }
  }
  int getTypeForMSH(){ return PYR1; }
  char *getStringForPOS(){ return "SY"; }
};

#endif
