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
// <gmsh@geuz.org>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include "GmshMessage.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "BasisFactory.h"
//#include "OptHomIntegralBoundaryDist.h"
#include "MeshOptPatch.h"


Patch::Patch(const std::map<MElement*,GEntity*> &element2entity,
           const std::set<MElement*> &els, std::set<MVertex*> &toFix,
           bool fixBndNodes)
{

  _dim = (*els.begin())->getDim();

  // Initialize elements, vertices, free vertices and element->vertices
  // connectivity
  const int nElements = els.size();
  _nPC = 0;
  _el.resize(nElements);
  _el2FV.resize(nElements);
  _el2V.resize(nElements);
  _nNodEl.resize(nElements);
  _indPCEl.resize(nElements);
  int iEl = 0;
  bool nonGeoMove = false;
  for(std::set<MElement*>::const_iterator it = els.begin();
      it != els.end(); ++it, ++iEl) {
    _el[iEl] = *it;
    _nNodEl[iEl] = _el[iEl]->getNumVertices();
    for (int iVEl = 0; iVEl < _nNodEl[iEl]; iVEl++) {
      MVertex *vert = _el[iEl]->getVertex(iVEl);
      GEntity *ge = vert->onWhat();
      const int vDim = ge->dim();
      const bool hasParam = ge->haveParametrization();
      int iV = addVert(vert);
      _el2V[iEl].push_back(iV);
      if ((vDim > 0) && (toFix.find(vert) == toFix.end()) && (!fixBndNodes || vDim == _dim)) {   // Free vertex?
        VertexCoord *coord;
        if (vDim == 3) coord = new VertexCoordPhys3D();
        else if (hasParam) coord = new VertexCoordParent(vert);
        else {
          if (vDim == 2) coord = new VertexCoordLocalSurf(vert);
          else coord = new VertexCoordLocalLine(vert);
          nonGeoMove = true;
        }
        int iFV = addFreeVert(vert, iV, vDim, coord, toFix);
        _el2FV[iEl].push_back(iFV);
        for (int i=_startPCFV[iFV]; i<_startPCFV[iFV]+vDim; i++) _indPCEl[iEl].push_back(i);
      }
      else _el2FV[iEl].push_back(-1);
    }
  }

  if (nonGeoMove) Msg::Warning("Some vertices will be moved along local lines "
                            "or planes, they may not remain on the exact geometry");

  // Initial coordinates
  _ixyz.resize(nVert());
  for (int iV = 0; iV < nVert(); iV++) _ixyz[iV] = _vert[iV]->point();
  _iuvw.resize(nFV());
  for (int iFV = 0; iFV < nFV(); iFV++) _iuvw[iFV] = _coordFV[iFV]->getUvw(_freeVert[iFV]);

  // Set current coordinates
  _xyz = _ixyz;
  _uvw = _iuvw;
}


int Patch::addVert(MVertex* vert)
{
  std::vector<MVertex*>::iterator itVert = find(_vert.begin(),_vert.end(),vert);
  if (itVert == _vert.end()) {
    _vert.push_back(vert);
    return _vert.size()-1;
  }
  else return std::distance(_vert.begin(),itVert);

}


int Patch::addFreeVert(MVertex* vert, const int iV, const int nPCV,
                      VertexCoord *param, std::set<MVertex*> &toFix)
{
  std::vector<MVertex*>::iterator itVert = find(_freeVert.begin(),
                                                _freeVert.end(),vert);
  if (itVert == _freeVert.end()) {
    const int iStart = (_startPCFV.size() == 0)? 0 : _startPCFV.back()+_nPCFV.back();
    const bool forcedV = (vert->onWhat()->dim() < 2) || (toFix.find(vert) != toFix.end());
    _freeVert.push_back(vert);
    _coordFV.push_back(param);
    _fv2V.push_back(iV);
    _startPCFV.push_back(iStart);
    _nPCFV.push_back(nPCV);
    _nPC += nPCV;
    _forced.push_back(forcedV);
    return _freeVert.size()-1;
  }
  else return std::distance(_freeVert.begin(),itVert);

}


void Patch::getUvw(double *it)
{
  for (int iFV = 0; iFV < nFV(); iFV++) {
    SPoint3 &uvwV = _uvw[iFV];
    *it = uvwV[0]; it++;
    if (_nPCFV[iFV] >= 2) { *it = uvwV[1]; it++; }
    if (_nPCFV[iFV] == 3) { *it = uvwV[2]; it++; }
  }

}


void Patch::updateMesh(const double *it)
{
  for (int iFV = 0; iFV < nFV(); iFV++) {
    int iV = _fv2V[iFV];
    SPoint3 &uvwV = _uvw[iFV];
    uvwV[0] = *it; it++;
    if (_nPCFV[iFV] >= 2) { uvwV[1] = *it; it++; }
    if (_nPCFV[iFV] == 3) { uvwV[2] = *it; it++; }
    _xyz[iV] = _coordFV[iFV]->uvw2Xyz(uvwV);
  }

}


void Patch::updateGEntityPositions()
{
  for (int iV = 0; iV < nVert(); iV++)
    _vert[iV]->setXYZ(_xyz[iV].x(),_xyz[iV].y(),_xyz[iV].z());
  for (int iFV = 0; iFV < nFV(); iFV++)
    _coordFV[iFV]->exportVertexCoord(_uvw[iFV]);
}


void Patch::pcScale(int iFV, std::vector<double> &scale)
{
  // Calc. derivative of x, y & z w.r.t. parametric coordinates
  const SPoint3 dX(1.,0.,0.), dY(0.,1.,0.), dZ(0.,0.,1.);
  SPoint3 gX, gY, gZ;
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV],dX,gX);
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV],dY,gY);
  _coordFV[iFV]->gXyz2gUvw(_uvw[iFV],dZ,gZ);

  // Scale = inverse norm. of vector (dx/du, dy/du, dz/du)
  scale[0] = 1./sqrt(gX[0]*gX[0]+gY[0]*gY[0]+gZ[0]*gZ[0]);
  if (_nPCFV[iFV] >= 2) scale[1] = 1./sqrt(gX[1]*gX[1]+gY[1]*gY[1]+gZ[1]*gZ[1]);
  if (_nPCFV[iFV] == 3) scale[2] = 1./sqrt(gX[2]*gX[2]+gY[2]*gY[2]+gZ[2]*gZ[2]);
}


void Patch::writeMSH(const char *filename)
{
  FILE *f = fopen(filename, "w");

  fprintf(f, "$MeshFormat\n");
  fprintf(f, "2.2 0 8\n");
  fprintf(f, "$EndMeshFormat\n");

  fprintf(f, "$Nodes\n");
  fprintf(f, "%d\n", nVert());
  for (int i = 0; i < nVert(); i++)
    fprintf(f, "%d %22.15E %22.15E %22.15E\n", i + 1, _xyz[i].x(), _xyz[i].y(), _xyz[i].z());
  fprintf(f, "$EndNodes\n");

  fprintf(f, "$Elements\n");
  fprintf(f, "%d\n", nEl());
  for (int iEl = 0; iEl < nEl(); iEl++) {
    fprintf(f, "%d %d 2 0 0", _el[iEl]->getNum(), _el[iEl]->getTypeForMSH());
    for (size_t iVEl = 0; iVEl < _el2V[iEl].size(); iVEl++)
      fprintf(f, " %d", _el2V[iEl][iVEl] + 1);
    fprintf(f, "\n");
  }
  fprintf(f, "$EndElements\n");

  fclose(f);
}
