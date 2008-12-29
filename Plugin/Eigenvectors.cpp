// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Eigenvectors.h"
#include "Numeric.h"
#include "EigSolve.h"

StringXNumber EigenvectorsOptions_Number[] = {
  {GMSH_FULLRC, "ScaleByEigenvalues", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvectorsPlugin()
  {
    return new GMSH_EigenvectorsPlugin();
  }
}

void GMSH_EigenvectorsPlugin::getName(char *name) const
{
  strcpy(name, "Eigenvectors");
}

void GMSH_EigenvectorsPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(Eigenvectors) computes the three (right)\n"
         "eigenvectors of each tensor in the view `iView'\n"
         "and sorts them according to the value of the\n"
         "associated eigenvalues. If `ScaleByEigenvalues'\n"
         "is set, each eigenvector is scaled by its\n"
         "associated eigenvalue. The plugin gives an error\n"
         "if the eigenvectors are complex. If `iView' < 0,\n"
         "the plugin is run on the current view.\n"
         "\n"
         "Plugin(Eigenvectors) creates three new\n"
         "vector views.\n");
}

int GMSH_EigenvectorsPlugin::getNbOptions() const
{
  return sizeof(EigenvectorsOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvectorsPlugin::getOption(int iopt)
{
  return &EigenvectorsOptions_Number[iopt];
}

void GMSH_EigenvectorsPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Eigenvectors failed...");
}

static List_T *incrementList(PViewDataList *data2, int numEdges)
{
  switch(numEdges){
  case 0: data2->NbVP++; return data2->VP;
  case 1: data2->NbVL++; return data2->VL;
  case 3: data2->NbVT++; return data2->VT;
  case 4: data2->NbVQ++; return data2->VQ;
  case 6: data2->NbVS++; return data2->VS;
  case 12: data2->NbVH++; return data2->VH;
  case 9: data2->NbVI++; return data2->VI;
  case 8: data2->NbVY++; return data2->VY;
  default: return 0;
  }
}

static int nonzero(double v[3])
{
  for(int i = 0; i < 3; i++)
    if(fabs(v[i]) > 1.e-16) return 1;
  return 0;
}

PView *GMSH_EigenvectorsPlugin::execute(PView *v)
{
  int scale = (int)EigenvectorsOptions_Number[0].def;
  int iView = (int)EigenvectorsOptions_Number[1].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()){
    Msg::Error("Eigenvectors plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *min = new PView(true);
  PView *mid = new PView(true);
  PView *max = new PView(true);

  PViewDataList *dmin = getDataList(min);
  PViewDataList *dmid = getDataList(mid);
  PViewDataList *dmax = getDataList(max);

  int nbcomplex = 0;

  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numComp = data1->getNumComponents(0, ent, ele);
      if(numComp != 9) continue;
      int numEdges = data1->getNumEdges(0, ent, ele);
      List_T *outmin = incrementList(dmin, numEdges);
      List_T *outmid = incrementList(dmid, numEdges);
      List_T *outmax = incrementList(dmax, numEdges);
      if(!outmin || !outmid || !outmax) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      double xyz[3][8];
      for(int nod = 0; nod < numNodes; nod++)
	data1->getNode(0, ent, ele, nod, xyz[0][nod], xyz[1][nod], xyz[2][nod]);
      for(int i = 0; i < 3; i++){
	for(int nod = 0; nod < numNodes; nod++){
	  List_Add(outmin, &xyz[i][nod]);
	  List_Add(outmid, &xyz[i][nod]);
	  List_Add(outmax, &xyz[i][nod]);
	}
      }
      for(int step = 0; step < data1->getNumTimeSteps(); step++){
	for(int nod = 0; nod < numNodes; nod++){
	  double val[9];
	  for(int comp = 0; comp < numComp; comp++)
	    data1->getValue(step, ent, ele, nod, comp, val[comp]);
	  double wr[3], wi[3], B[9];
	  if(!EigSolve3x3(val, wr, wi, B))
	    Msg::Error("Eigensolver failed to converge");
	  nbcomplex += nonzero(wi); 
	  if(!scale) wr[0] = wr[1] = wr[2] = 1.;
	  for(int i = 0; i < 3; i++){
	    double res;
	    // wrong if there are complex eigenvals (B contains both
	    // real and imag parts: cf. explanation in EigSolve.cpp)
	    res = wr[0] * B[i]; List_Add(outmin, &res);
	    res = wr[1] * B[3 + i]; List_Add(outmid, &res);
	    res = wr[2] * B[6 + i]; List_Add(outmax, &res);
	  }
	}
      }
    }
  }

  if(nbcomplex)
    Msg::Error("%d tensors have complex eigenvalues/eigenvectors", 
	nbcomplex);
  
  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    List_Add(dmin->Time, &time);
    List_Add(dmid->Time, &time);
    List_Add(dmax->Time, &time);
  }
  dmin->setName(data1->getName() + "_MinEigenvectors");
  dmin->setFileName(data1->getName() + "_MinEigenvectors.pos");
  dmin->finalize();
  dmid->setName(data1->getName() + "_MidEigenvectors");
  dmid->setFileName(data1->getName() + "_MidEigenvectors.pos");
  dmid->finalize();
  dmax->setName(data1->getName() + "_MaxEigenvectors");
  dmax->setFileName(data1->getName() + "_MaxEigenvectors.pos");
  dmax->finalize();

  return 0;
}
