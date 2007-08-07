#include <string>
#include "GModel.h"
#include "Message.h"
#include "FFace.h"
#include "GModelIO_F.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FVertex.h"
#include "FEdge.h"
#include "FFace.h"
#include "FPatch.h"
#include "FCurve.h"
#include "FM_Vertex.h"
#include "FM_Edge.h"
#include "FM_Face.h"
#include "FM_Reader.h"

extern GModel *GMODEL;

void makeGFace(Patch* patch)
{
  double LL[2], LR[2], UL[2], UR[2];
  LL[0] = 0.0; LL[1] = 0.0;
  LR[0] = 1.0; LR[1] = 0.0;
  UL[0] = 0.0; UL[1] = 1.0;
  UR[0] = 1.0; UR[1] = 1.0;
  
  int i1, i2;
  double xx,yy,zz;
  
  int tagVertex = GMODEL->numVertex();
  patch->F(LL[0],LL[1],xx,yy,zz);
  FM_Vertex* vLL = new FM_Vertex(++tagVertex,xx,yy,zz);
  GMODEL->add(new FVertex(GMODEL,vLL->GetTag(),vLL));
  patch->F(LR[0],LR[1],xx,yy,zz);
  FM_Vertex* vLR = new FM_Vertex(++tagVertex,xx,yy,zz);
  GMODEL->add(new FVertex(GMODEL,vLR->GetTag(),vLR));
  patch->F(UL[0],UL[1],xx,yy,zz);
  FM_Vertex* vUL = new FM_Vertex(++tagVertex,xx,yy,zz);
  GMODEL->add(new FVertex(GMODEL,vUL->GetTag(),vUL));
  patch->F(UR[0],UR[1],xx,yy,zz);
  FM_Vertex* vUR = new FM_Vertex(++tagVertex,xx,yy,zz);
  GMODEL->add(new FVertex(GMODEL,vUR->GetTag(),vUR));
  
  Curve* curveB = new FCurve(0,patch,LL,LR);
  Curve* curveR = new FCurve(0,patch,LR,UR);
  Curve* curveT = new FCurve(0,patch,UR,UL);
  Curve* curveL = new FCurve(0,patch,UL,LL);
  
  int tagEdge = GMODEL->numEdge();
  FM_Edge* eB = new FM_Edge(++tagEdge,curveB,vLL,vLR);
  i1 = eB->GetStartPoint()->GetTag();
  i2 = eB->GetEndPoint()->GetTag();
  GMODEL->add(new FEdge(GMODEL,eB,eB->GetTag(),GMODEL->vertexByTag(i1),
			GMODEL->vertexByTag(i2)));
  FM_Edge* eR = new FM_Edge(++tagEdge,curveR,vLR,vUR); 
  i1 = eR->GetStartPoint()->GetTag();
  i2 = eR->GetEndPoint()->GetTag();
  GMODEL->add(new FEdge(GMODEL,eR,eR->GetTag(),GMODEL->vertexByTag(i1),
			GMODEL->vertexByTag(i2))); 
  FM_Edge* eT = new FM_Edge(++tagEdge,curveT,vUR,vUL);
  i1 = eT->GetStartPoint()->GetTag();
  i2 = eT->GetEndPoint()->GetTag();
  GMODEL->add(new FEdge(GMODEL,eT,eT->GetTag(),GMODEL->vertexByTag(i1),
			GMODEL->vertexByTag(i2)));
  FM_Edge* eL = new FM_Edge(++tagEdge,curveL,vUL,vLL); 
  i1 = eL->GetStartPoint()->GetTag();
  i2 = eL->GetEndPoint()->GetTag();
  GMODEL->add(new FEdge(GMODEL,eL,eL->GetTag(),GMODEL->vertexByTag(i1),
			GMODEL->vertexByTag(i2)));
  
  FM_Face* face = new FM_Face(GMODEL->numFace() + 1,patch);
  face->AddEdge(eB); face->AddEdge(eR); 
  face->AddEdge(eT); face->AddEdge(eL);
  std::list<GEdge*> l_edges;
  for (int j=0;j<face->GetNumEdges();j++) {
    int tag = face->GetEdge(j)->GetTag(); 
    l_edges.push_back(GMODEL->edgeByTag(tag));
  }
  GMODEL->add(new FFace(GMODEL,face,face->GetTag(),l_edges));
}

int GModel::readF(const std::string &filename)
{
  FM_Reader* reader = new FM_Reader(filename.c_str());
  for (int i = 0; i < reader->GetNumPatches(); i++)
    makeGFace(reader->GetPatch(i));

  return 1;
}

#else

int GModel::readF(const std::string &fn)
{
  Msg(GERROR,"Gmsh has to be compiled with Fourier Model support to load %s",
      fn.c_str());
  return 0;
}

#endif
