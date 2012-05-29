#ifndef _OPT_HOM_MESH_H_
#define _OPT_HOM_MESH_H_

#include <vector>
#include <map>
#include <bitset>
#include "GFace.h"
#include "MVertex.h"
#include "ParamCoord.h"
#include "polynomialBasis.h"
#include "JacobianBasis.h"



class Mesh
{

public:

  Mesh(GEntity *ge, const std::set<MElement*> &els, std::set<MVertex*> & toFix, int method);

  inline const int &nPC() { return _nPC; }
  inline int nVert() { return _vert.size(); }
  inline int nFV() { return _freeVert.size(); }
  inline const bool forced(int iV) { return _forced[iV]; }
  inline int nEl() { return _el.size(); }
  inline const int &nPCFV(int iFV) { return _nPCFV[iFV]; }
  inline int indPCFV(int iFV, int iPC) { return _startPCFV[iFV]+iPC; }
  inline int nPCEl(int iEl) { return _indPCEl[iEl].size(); }
  inline const int &indPCEl(int iEl, int iPC) { return _indPCEl[iEl][iPC]; }
  inline const int &nBezEl(int iEl) { return _nBezEl[iEl]; }

  void scaledJacAndGradients(int iEl, std::vector<double> &sJ, std::vector<double> &gSJ);   
  inline int indGSJ(int iEl, int l, int iPC) { return iPC*_nBezEl[iEl]+l; }

  inline double distSq(int iFV);
  inline void gradDistSq(int iV, std::vector<double> &gDSq);

  void pcScale(int iFV, std::vector<double> &scale);          // Calc. scale of parametric coordinates for preconditioning

  void getUvw(double *it);
  void updateMesh(const double *it);
  void distSqToStraight(std::vector<double> &dSq);

  void updateGEntityPositions();
  void writeMSH(const char *filename);

  enum { METHOD_RELAXBND = 1 << 0, METHOD_FIXBND = 1 << 1, METHOD_PHYSCOORD = 1 << 2,
    METHOD_SURFCOORD = 1 << 3, METHOD_PROJJAC = 1 << 4 };

//  inline double xyzDBG(int iV, int iCoord) { return _xyz[iV][iCoord]; }
//  inline double ixyzDBG(int iV, int iCoord) { return _ixyz[iV][iCoord]; }
//  inline double sxyzDBG(int iV, int iCoord) { return _sxyz[iV][iCoord]; }
//  inline double uvwDBG(int iFV, int iCoord) { return _uvw[iFV][iCoord]; }
//  inline int fv2VDBG(int iFV) { return _fv2V[iFV]; }
//  inline bool forcedDBG(int iV) { return _forced[iV]; }

private:

  GEntity *_ge;
  int _dim;
  int _nPC;                                     // Total nb. of parametric coordinates

  std::vector<MElement*> _el;                   // List of elements
  std::vector<SVector3> _normEl;                // Normals to 2D elements
  std::vector<double> _invStraightJac;          // Initial Jacobians for 3D elements
  std::vector<MVertex*> _vert, _freeVert;       // List of vert., free vert.
  std::vector<int> _fv2V;                       // Index of free vert. -> index of vert.
  std::vector<bool> _forced;                    // Is vertex forced?
  std::vector<SPoint3> _xyz, _ixyz;             // Physical coord. of ALL vertices (current, straight, init.)
  std::vector<SPoint3> _uvw, _iuvw;             // Parametric coord. of FREE vertices (current, straight, init.)
  std::vector<int> _startPCFV;                  // Start index of parametric coordinates for a free vertex
  std::vector<int> _nPCFV;                      // Number of parametric coordinates for a free vertex
  std::vector<std::vector<int> > _el2FV, _el2V; // Free vertices, vertices in element
  std::vector<int> _nBezEl, _nNodEl;            // Number of Bezier poly. and nodes for an el.
  std::vector<std::vector<int> > _indPCEl;      // Index of parametric coord. for an el.

  ParamCoord *_pc;
  bool projJac;                                 // Using "projected" Jacobians or not

  static std::map<int, fullMatrix<double> >  _gradShapeFunctions; // gradients of shape functions at Bezier points 
  static std::map<int, fullMatrix<double> >  _lag2Bez; // gradients of shape functions at Bezier points 

  int addVert(MVertex* vert);
  int addFreeVert(MVertex* vert, const int iV, const int nPCV, std::set<MVertex*> &toFix);
  SVector3 getNormalEl(int iEl);
  static fullMatrix<double> computeGSF(const polynomialBasis *lagrange, const bezierBasis *bezier);
  static inline int indJB2DBase(int nNod, int l, int i, int j) { return (l*nNod+i)*nNod+j; }
  inline int indJB2D(int iEl, int l, int i, int j) { return indJB2DBase(_nNodEl[iEl],l,i,j); }
  static inline int indJB3DBase(int nNod, int l, int i, int j, int m) { return ((l*nNod+i)*nNod+j)*nNod+m; }
  inline int indJB3D(int iEl, int l, int i, int j, int m) { return indJB3DBase(_nNodEl[iEl],l,i,j,m); }

};



double Mesh::distSq(int iFV)
{

  SPoint3 d = _xyz[_fv2V[iFV]]-_ixyz[_fv2V[iFV]];
  return d[0]*d[0]+d[1]*d[1]+d[2]*d[2];

}



void Mesh::gradDistSq(int iFV, std::vector<double> &gDSq)
{

  SPoint3 gXyz = (_xyz[_fv2V[iFV]]-_ixyz[_fv2V[iFV]])*2.;
  SPoint3 gUvw;
  _pc->gXyz2gUvw(_freeVert[iFV],_uvw[iFV],gXyz,gUvw);

  gDSq[0] = gUvw[0];
  if (_nPCFV[iFV] >= 2) gDSq[1] = gUvw[1];
  if (_nPCFV[iFV] == 3) gDSq[2] = gUvw[2];

}



#endif
