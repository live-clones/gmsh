// Copyright (C) 2013 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef _OPT_HOM_MESH_H_
#define _OPT_HOM_MESH_H_

#include <vector>
#include <map>
#include <bitset>
#include "GFace.h"
#include "MVertex.h"
#include "ParamCoord.h"
#include "polynomialBasis.h"
#include "simpleFunction.h"
#include "approximationError.h"

class Mesh
{
public:
  Mesh(const std::map<MElement*,GEntity*> &element2entity,
       const std::set<MElement*, Less_ElementPtr> &els, std::set<MVertex*> & toFix, bool fixBndNodes, bool fastJacEval);

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
  int getFreeVertexStartIndex(MVertex* vert);

  void approximationErrorAndGradients(int iEl, double &f, std::vector<double> &gradF, double eps, simpleFunction<double> &fct);
  void metricMinAndGradients(int iEl, std::vector<double> &sJ, std::vector<double> &gSJ);
  void scaledJacAndGradients(int iEl, std::vector<double> &sJ, std::vector<double> &gSJ);
  bool bndDistAndGradients(int iEl, double &f , std::vector<double> &gradF, double eps);
  inline int indGSJ(int iEl, int l, int iPC) { return iPC*_nBezEl[iEl]+l; }

  inline double distSq(int iFV);
  inline void gradDistSq(int iV, std::vector<double> &gDSq);

  // Calc. scale of parametric coordinates for preconditioning
  void pcScale(int iFV, std::vector<double> &scale);

  void getUvw(double *it);
  void updateMesh(const double *it);
  void distSqToStraight(std::vector<double> &dSq);
  void elSizeSq(std::vector<double> &sSq);
  void elInSize(std::vector<double> &s);

  void updateGEntityPositions();
  void updateGEntityPositions(const std::vector<SPoint3> &xyz,
			      const std::vector<SPoint3> &uvw);

  void getGEntityPositions(std::vector<SPoint3> &xyz,
			   std::vector<SPoint3> &uvw) ;
  void writeMSH(const char *filename);

private:
  int _dim;
  // Total nb. of parametric coordinates
  int _nPC;
  // Use fast Jacobian estimation?
  bool _fastJacEval;
  // Free vertex id numbers
  std::map<MVertex*,int> _startPC4FV;
  // List of elements
  std::vector<MElement*> _el;
  // Normals to 2D elements for Jacobian regularization and scaling
  std::vector<fullMatrix<double> > _scaledNormEl;
  // Initial Jacobians for 3D elements
  std::vector<double> _invStraightJac;
  // List of vert., free vert.
  std::vector<MVertex*> _vert, _freeVert;
  // Index of free vert. -> index of vert.
  std::vector<int> _fv2V;
  // Is vertex forced?
  std::vector<bool> _forced;
  // Physical coord. of ALL vertices (current, straight, init.)
  std::vector<SPoint3> _xyz, _ixyz;
  // Parametric coord. of FREE vertices (current, straight, init.)
  std::vector<SPoint3> _uvw, _iuvw;
  // Start index of parametric coordinates for a free vertex
  std::vector<int> _startPCFV;
  // Number of parametric coordinates for a free vertex
  std::vector<int> _nPCFV;
  // Free vertices, vertices in element
  std::vector<std::vector<int> > _el2FV, _el2V;
  // Number of Bezier poly. and nodes for an el.
  std::vector<int> _nBezEl, _nNodEl;
  // Index of parametric coord. for an el.
  std::vector<std::vector<int> > _indPCEl;
  // Parametrization for a free vertex
  std::vector<ParamCoord*> _paramFV;

  int addVert(MVertex* vert);
  int addFreeVert(MVertex* vert, const int iV, const int nPCV,
                  ParamCoord *param, std::set<MVertex*> &toFix);
  void calcScaledNormalEl2D(const std::map<MElement*,GEntity*> &element2entity, int iEl);
  static inline int indJB2DBase(int nNod, int l, int i, int j)
  {
    return (l*nNod+i)*nNod+j;
  }
  inline int indJB2D(int iEl, int l, int i, int j)
  {
    return indJB2DBase(_nNodEl[iEl],l,i,j);
  }
  static inline int indJB3DBase(int nNod, int l, int i, int j, int m)
  {
    return ((l*nNod+i)*nNod+j)*nNod+m;
  }
  inline int indJB3D(int iEl, int l, int i, int j, int m)
  {
    return indJB3DBase(_nNodEl[iEl],l,i,j,m);
  }
public: 
  double approximationErr(int iEl, simpleFunction<double> &f)
  {
    return approximationError (f, _el[iEl]);
  }
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
  _paramFV[iFV]->gXyz2gUvw(_uvw[iFV],gXyz,gUvw);

  gDSq[0] = gUvw[0];
  if (_nPCFV[iFV] >= 2) gDSq[1] = gUvw[1];
  if (_nPCFV[iFV] == 3) gDSq[2] = gUvw[2];
}

#endif
