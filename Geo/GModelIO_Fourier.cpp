// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
#include <string>
#include "GModel.h"
#include "GmshMessage.h"
#include "fourierVertex.h"
#include "fourierEdge.h"
#include "fourierFace.h"
#include "GModelIO_Fourier.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_FPatch.h"
#include "FM_PCurve.h"
#include "FM_TopoVertex.h"
#include "FM_TopoEdge.h"
#include "FM_TopoFace.h"

void FM_Internals::makeGFace(FM::Patch* patch, GModel* model)
{
  double LL[2], LR[2], UL[2], UR[2];
  LL[0] = 0.0; LL[1] = 0.0;
  LR[0] = 1.0; LR[1] = 0.0;
  UL[0] = 0.0; UL[1] = 1.0;
  UR[0] = 1.0; UR[1] = 1.0;
  
  int i1, i2;
  double xx,yy,zz;

  int tagVertex = model->getNumVertices();
  patch->F(LL[0], LL[1], xx, yy, zz);
  FM::TopoVertex* vLL = new FM::TopoVertex(++tagVertex, xx, yy, zz);
  model->add(new fourierVertex(model, vLL->GetTag(), vLL));
  patch->F(LR[0], LR[1], xx, yy, zz);
  FM::TopoVertex* vLR = new FM::TopoVertex(++tagVertex, xx, yy, zz);
  model->add(new fourierVertex(model, vLR->GetTag(), vLR));
  patch->F(UL[0], UL[1], xx, yy, zz);
  FM::TopoVertex* vUL = new FM::TopoVertex(++tagVertex, xx, yy, zz);
  model->add(new fourierVertex(model, vUL->GetTag(), vUL));
  patch->F(UR[0], UR[1], xx, yy, zz);
  FM::TopoVertex* vUR = new FM::TopoVertex(++tagVertex, xx, yy, zz);
  model->add(new fourierVertex(model, vUR->GetTag(), vUR));
  
  FM::Curve* curveB = new FM::PCurve(LL, LR, patch);
  FM::Curve* curveR = new FM::PCurve(LR, UR, patch);
  FM::Curve* curveT = new FM::PCurve(UR, UL, patch);
  FM::Curve* curveL = new FM::PCurve(UL, LL, patch);
  
  int tagEdge = model->getNumEdges();
  FM::TopoEdge* eB = new FM::TopoEdge(++tagEdge, curveB, vLL, vLR);
  i1 = eB->GetStartPoint()->GetTag();
  i2 = eB->GetEndPoint()->GetTag();
  model->add(new fourierEdge(model, eB, eB->GetTag(), model->getVertexByTag(i1),
			 model->getVertexByTag(i2)));
  FM::TopoEdge* eR = new FM::TopoEdge(++tagEdge, curveR, vLR, vUR); 
  i1 = eR->GetStartPoint()->GetTag();
  i2 = eR->GetEndPoint()->GetTag();
  model->add(new fourierEdge(model, eR, eR->GetTag(), model->getVertexByTag(i1),
			 model->getVertexByTag(i2))); 
  FM::TopoEdge* eT = new FM::TopoEdge(++tagEdge, curveT, vUR, vUL);
  i1 = eT->GetStartPoint()->GetTag();
  i2 = eT->GetEndPoint()->GetTag();
  model->add(new fourierEdge(model, eT, eT->GetTag(), model->getVertexByTag(i1),
			 model->getVertexByTag(i2)));
  FM::TopoEdge* eL = new FM::TopoEdge(++tagEdge, curveL, vUL, vLL); 
  i1 = eL->GetStartPoint()->GetTag();
  i2 = eL->GetEndPoint()->GetTag();
  model->add(new fourierEdge(model, eL, eL->GetTag(), model->getVertexByTag(i1),
			 model->getVertexByTag(i2)));
  
  FM::TopoFace* face = new FM::TopoFace(model->getNumFaces() + 1, patch);
  face->AddEdge(eB); face->AddEdge(eR); 
  face->AddEdge(eT); face->AddEdge(eL);
  std::list<GEdge*> l_edges;
  for (int j = 0; j < face->GetNumEdges(); j++) {
    int tag = face->GetEdge(j)->GetTag(); 
    l_edges.push_back(model->getEdgeByTag(tag));
  }
  model->add(new fourierFace(model, face, face->GetTag(), l_edges));
}

void FM_Internals::loadFM()
{
  reader.push_back(new FM::Reader());
}

void FM_Internals::loadFM(const char* filename)
{
  reader.push_back(new FM::Reader(filename));
}

void FM_Internals::buildGModel(FM::Reader* reader, GModel* model)
{
  for (int i = 0; i < reader->GetNumPatches(); i++)
    makeGFace(reader->GetPatch(i), model);
}

void GModel::_createFMInternals()
{
  if (!_fm_internals)
    _fm_internals = new FM_Internals;  
}

void GModel::_deleteFMInternals()
{
  delete _fm_internals;
  _fm_internals = 0;
}

int GModel::readFourier()
{
  _createFMInternals();
  getFMInternals()->loadFM();
  return 1;
}

int GModel::readFourier(const std::string &filename)
{
  _createFMInternals();
  getFMInternals()->loadFM(filename.c_str());
  getFMInternals()->buildGModel(getFMInternals()->current(),this);

  return 1;
}

int GModel::writeFourier(const std::string &filename)
{
  return 0;
}

#else

void GModel::_createFMInternals()
{
}

void GModel::_deleteFMInternals()
{
}

int GModel::readFourier(const std::string &fn)
{
  Msg::Error("Gmsh has to be compiled with Fourier Model support to load '%s'",
      fn.c_str());
  return 0;
}

int GModel::writeFourier(const std::string &fn)
{
  Msg::Error("Gmsh has to be compiled with Fourier Model support to load '%s'",
	     fn.c_str());
  return 0;
}

#endif
