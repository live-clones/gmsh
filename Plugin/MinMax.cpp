// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MinMax.h"
#include "PViewOptions.h"

StringXNumber MinMaxOptions_Number[] = {
  {GMSH_FULLRC, "View", NULL, -1.},
  {GMSH_FULLRC, "OverTime", NULL, 0},
  {GMSH_FULLRC, "Argument", NULL, 0}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterMinMaxPlugin()
  {
    return new GMSH_MinMaxPlugin();
  }
}

std::string GMSH_MinMaxPlugin::getHelp() const
{
  return "Plugin(MinMax) computes the min/max of a view.\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "If `OverTime' = 1, calculates the min/max over space AND time\n\n"
    "If `Argument' = 1, calculates the min/max AND the argmin/argmax\n\n"
    "Plugin(MinMax) creates two new views.";
}

int GMSH_MinMaxPlugin::getNbOptions() const
{
  return sizeof(MinMaxOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MinMaxPlugin::getOption(int iopt)
{
  return &MinMaxOptions_Number[iopt];
}

PView *GMSH_MinMaxPlugin::execute(PView * v)
{
  int iView = (int)MinMaxOptions_Number[0].def;
  int overTime = (int)MinMaxOptions_Number[1].def;
  int argument = (int)MinMaxOptions_Number[2].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();
  PView *vMin = new PView();
  PView *vMax = new PView();
  PViewDataList *dataMin = getDataList(vMin);
  PViewDataList *dataMax = getDataList(vMax);
  
  if(!argument){
    double x = data1->getBoundingBox().center().x();
    double y = data1->getBoundingBox().center().y();
    double z = data1->getBoundingBox().center().z();
    dataMin->SP.push_back(x); dataMin->SP.push_back(y); dataMin->SP.push_back(z);
    dataMax->SP.push_back(x); dataMax->SP.push_back(y); dataMax->SP.push_back(z);
    dataMin->NbSP = 1;
    dataMax->NbSP = 1;
  }

  double minView=VAL_INF, maxView=-VAL_INF, min=VAL_INF, max=-VAL_INF, timeMin=0, timeMax=0;
  double xmin, ymin, zmin, xmax, ymax, zmax;

  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    if(data1->hasTimeStep(step)){

      //minView=data1->getMin(step); 
      //maxView=data1->getMax(step);
 
      for(int ent = 0; ent < data1->getNumEntities(step); ent++){
	for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
	  for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++){
	    double val;
	    data1->getScalarValue(step, ent, ele, nod, val);
	    if(val<minView){
	      data1->getNode(step, ent, ele, nod, xmin, ymin, zmin);
	      minView=val;
	    }
	    if(val>maxView){
	      data1->getNode(step, ent, ele, nod, xmax, ymax, zmax);
	      maxView=val;
	    }
	  }
	}
      }
      if(!overTime){ 
	// one stores min/max and at each time step 
	if(argument){
	  dataMin->SP.push_back(xmin); dataMin->SP.push_back(ymin); dataMin->SP.push_back(zmin);
	  dataMax->SP.push_back(xmax); dataMax->SP.push_back(ymax); dataMax->SP.push_back(zmax);
	  (dataMin->NbSP)++;
	  (dataMax->NbSP)++;
	}
	dataMin->SP.push_back(minView);
	dataMax->SP.push_back(maxView);
	double time = data1->getTime(step);
	dataMin->Time.push_back(time);//?
	dataMax->Time.push_back(time);//?
      }
      else{
	if(minView<min){
	  min=minView;
	  timeMin = data1->getTime(step);
	}
	if(maxView>max){ 
	  max=maxView;
	  timeMax = data1->getTime(step);
	} 
      }
    }
  }

  if(overTime){ 
    dataMin->SP.push_back(min);
    dataMax->SP.push_back(max);
    dataMin->Time.push_back(timeMin);//?
    dataMax->Time.push_back(timeMax);//?
  }

  // dataMin->NbSP = 1;
  // dataMax->NbSP = 1;

  vMin->getOptions()->intervalsType = PViewOptions::Numeric;
  vMax->getOptions()->intervalsType = PViewOptions::Numeric;
  
  /*
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    if(data1->hasTimeStep(step)){
      if(overTime){
	dataMin->Time.push_back(timeMin);
	dataMax->Time.push_back(timeMax);
      }
      else{
	double time = data1->getTime(step);
	dataMin->Time.push_back(time);
	dataMax->Time.push_back(time);
      }
    }
  }
  */

  dataMin->setName(data1->getName() + "_Min");
  dataMin->setFileName(data1->getName() + "_Min.pos");
  dataMin->finalize();
  dataMax->setName(data1->getName() + "_Max");
  dataMax->setFileName(data1->getName() + "_Max.pos");
  dataMax->finalize();
  
  return 0;
}
