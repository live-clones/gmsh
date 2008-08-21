// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Eigenvalues.h"
#include "Numeric.h"

StringXNumber EigenvaluesOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEigenvaluesPlugin()
  {
    return new GMSH_EigenvaluesPlugin();
  }
}

void GMSH_EigenvaluesPlugin::getName(char *name) const
{
  strcpy(name, "Eigenvalues");
}

void GMSH_EigenvaluesPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(Eigenvalues) computes the three real\n"
         "eigenvalues of each tensor in the view `iView'.\n"
         "If `iView' < 0, the plugin is run on the current view.\n"
         "\n"
         "Plugin(Eigenvalues) creates three new scalar views.\n");
}

int GMSH_EigenvaluesPlugin::getNbOptions() const
{
  return sizeof(EigenvaluesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EigenvaluesPlugin::getOption(int iopt)
{
  return &EigenvaluesOptions_Number[iopt];
}

void GMSH_EigenvaluesPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Eigenvalues failed...");
}

static List_T *incrementList(PViewDataList *data2, int numEdges)
{
  switch(numEdges){
  case 0: data2->NbSP++; return data2->SP;
  case 1: data2->NbSL++; return data2->SL;
  case 3: data2->NbST++; return data2->ST;
  case 4: data2->NbSQ++; return data2->SQ;
  case 6: data2->NbSS++; return data2->SS;
  case 12: data2->NbSH++; return data2->SH;
  case 9: data2->NbSI++; return data2->SI;
  case 8: data2->NbSY++; return data2->SY;
  default: return 0;
  }
}

PView *GMSH_EigenvaluesPlugin::execute(PView *v)
{
  int iView = (int)EigenvaluesOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  if(data1->hasMultipleMeshes()){
    Msg::Error("Eigenvalues plugin cannot be run on multi-mesh views");
    return v;
  }

  PView *min = new PView(true);
  PView *mid = new PView(true);
  PView *max = new PView(true);

  PViewDataList *dmin = getDataList(min);
  PViewDataList *dmid = getDataList(mid);
  PViewDataList *dmax = getDataList(max);

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
	  double val[9], w[3];
	  for(int comp = 0; comp < numComp; comp++)
	    data1->getValue(step, ent, ele, nod, comp, val[comp]);
	  double A[3][3] = {{val[0], val[1], val[2]},
			    {val[3], val[4], val[5]},
			    {val[6], val[7], val[8]}};
	  eigenvalue(A, w);
	  List_Add(outmin, &w[2]);
	  List_Add(outmid, &w[1]);
	  List_Add(outmax, &w[0]);
	}
      }
    }
  }
  
  for(int i = 0; i < data1->getNumTimeSteps(); i++){
    double time = data1->getTime(i);
    List_Add(dmin->Time, &time);
    List_Add(dmid->Time, &time);
    List_Add(dmax->Time, &time);
  }
  dmin->setName(data1->getName() + "_MinEigenvalues");
  dmin->setFileName(data1->getName() + "_MinEigenvalues.pos");
  dmin->finalize();
  dmid->setName(data1->getName() + "_MidEigenvalues");
  dmid->setFileName(data1->getName() + "_MidEigenvalues.pos");
  dmid->finalize();
  dmax->setName(data1->getName() + "_MaxEigenvalues");
  dmax->setFileName(data1->getName() + "_MaxEigenvalues.pos");
  dmax->finalize();

  return 0;
}
