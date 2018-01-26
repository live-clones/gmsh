// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "Summation.h"
#include "OctreePost.h"
#include "GEntity.h"
#include <algorithm>

StringXNumber SummationOptions_Number[] = {
  {GMSH_FULLRC, "ForceInterpolation", NULL, 0.},
  {GMSH_FULLRC, "PhysicalRegion", NULL, -1.},
  {GMSH_FULLRC, "View 0", NULL, -1.},
  {GMSH_FULLRC, "View 1", NULL, -1.},
  {GMSH_FULLRC, "View 2", NULL, -1.},
  {GMSH_FULLRC, "View 3", NULL, -1.}
};

StringXString SummationOptions_String[] = {
  /*  {GMSH_FULLRC, "Expression0", NULL, "Sqrt(v0^2+v1^2+v2^2)"},
  {GMSH_FULLRC, "Expression1", NULL, ""},
  {GMSH_FULLRC, "Expression2", NULL, ""},
  {GMSH_FULLRC, "Expression3", NULL, ""},
  {GMSH_FULLRC, "Expression4", NULL, ""},
  {GMSH_FULLRC, "Expression5", NULL, ""},
  {GMSH_FULLRC, "Expression6", NULL, ""},
  {GMSH_FULLRC, "Expression7", NULL, ""},
  {GMSH_FULLRC, "Expression8", NULL, ""}
  */
};


extern "C"
{
  GMSH_Plugin *GMSH_RegisterSummationPlugin()
  {
    return new GMSH_SummationPlugin();
  }
}

std::string GMSH_SummationPlugin::getHelp() const
{
  return "TODO Plugin(Summation) creates a new view";
}

int GMSH_SummationPlugin::getNbOptions() const
{
  return sizeof(SummationOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SummationPlugin::getOption(int iopt)
{
  return &SummationOptions_Number[iopt];
}

int GMSH_SummationPlugin::getNbOptionsStr() const
{
  return sizeof(SummationOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_SummationPlugin::getOptionStr(int iopt)
{
  return &SummationOptions_String[iopt];
}

PView *GMSH_SummationPlugin::execute(PView *view)
{
  int nviewmax = 4;
  std::vector<int> views_indices;
  std::vector<PView*> pviews;
  std::vector<PViewData*> pviewsdata;
  
  int forceInterpolation = (int)SummationOptions_Number[0].def;
  int physicalRegion = (int)SummationOptions_Number[1].def;

  //Get view indices and PViews
  for (int i =0; i < nviewmax; i++)
    {
      int iview = (int)SummationOptions_Number[i].def;
      if(iview > -1)
	{
	  views_indices.push_back(iview);
	  pviews.push_back(getView(iiew, view));
	  if(!pviews.back()){
	    Msg::Error("Summation plugin could not find view %i", iview);
	    return view;
	  }
	  pviewsdata.push_back(getPossiblyAdaptiveData(pviews.back()));
	  if(pviewsdata.back()->hasMultipleMeshes()){
	    Msg::Error("Summation plugin cannot be applied to multi-mesh views");
	    return view;
	  }
	}
    }  
  int nview = pviews.size();
  //TODO: add check on nb of TimeStep, ...
  //Right now : only one TimeStep
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);
  int firstNonEmptyStep =  pviewdata[0]->getFirstNonEmptyTimeStep();
  int timeBeg = firstNonEmptyStep;
  int timeEnd = pviewdata[0]->getNumTimeSteps();
  for(int ent = 0; ent < pviewdata[0]->getNumEntities(timeBeg); ent++){
    for(int ele = 0; ele < pviewdata[0]->getNumElements(timeBeg, ent); ele++){
      if(pviewdata[0]->skipElement(timeBeg, ent, ele)) continue;
      int numNodes = pviewdata[0]->getNumNodes(timeBeg, ent, ele);
      int type = pviewdata[0]->getType(timeBeg, ent, ele);
      int numComp = pviewdata[0]->getNumComponents(timeBeg, ent, ele);
      int numComp2 = numComp;
      std::vector<double> *out = data2->incrementList(numComp2, type, numNodes);
      std::vector<std::vector<double> > v(nview);
      for (int i = 0; i < nview; i++)
	v[i].resize(std::max(9, numComp), 0.);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
	  pviewdata[0]->getNode(timeBeg, ent, ele, nod, x[nod], y[nod], z[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = timeBeg; step < timeEnd; step++){
	if(!pviewdata[0]->hasTimeStep(step)) continue;
        for(int nod = 0; nod < numNodes; nod++){
          for(int comp = 0; comp < numComp; comp++){
	    v[comp]=0;
	    for(int iview = 0; iview < nview; iview++)
	      {
		double d;
		pviewdata[i]->getValue(step, ent, ele, nod, comp, d);
		v[comp] +=d;
	      }
	  }
	  for(int i = 0; i < numComp2; i++)
	    out->push_back(v[i]);
	}
      }
    }
  }

  for(int i = firstNonEmptyStep; i < pviewdata[0]->getNumTimeSteps(); i++) {
    if(!pviewdata[0]->hasTimeStep(i)) continue;
    data2->Time.push_back(pviewdata[0]->getTime(i));
  }

  data2->setName(data1->getName() + "_Summation");
  data2->setFileName(data1->getName() + "_Summation.pos");
  data2->finalize();

  return v2;
}
