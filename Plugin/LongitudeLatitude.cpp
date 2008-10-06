// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "LongitudeLatitude.h"

StringXNumber LongituteLatitudeOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterLongituteLatitudePlugin()
  {
    return new GMSH_LongituteLatitudePlugin();
  }
}

void GMSH_LongituteLatitudePlugin::getName(char *name) const
{
  strcpy(name, "LongituteLatitude");
}

void GMSH_LongituteLatitudePlugin::getInfos(char *author, char *copyright,
			       char *help_text) const
{
  strcpy(author, "J. Lambrechts");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(LongituteLatitude) Project the view `iView'\n"
         "in Longitude-Latitude. If `iView' < 0, the plugin\n"
         "is run on the current view.\n"
         "\n"
         "Plugin(LongituteLatitude) is executed in place.\n");
}

int GMSH_LongituteLatitudePlugin::getNbOptions() const
{
  return sizeof(LongituteLatitudeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_LongituteLatitudePlugin::getOption(int iopt)
{
  return &LongituteLatitudeOptions_Number[iopt];
}

void GMSH_LongituteLatitudePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "LongituteLatitude failed...");
}

PView *GMSH_LongituteLatitudePlugin::execute(PView *v)
{
  int iView = (int)LongituteLatitudeOptions_Number[0].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  // tag all the nodes with "0" (the default tag)
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
	if(data1->skipElement(step, ent, ele)) continue;
	for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++)
	  data1->tagNode(step, ent, ele, nod, 0);
      }
    }
  } 
  // transform all "0" nodes
  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
	if(data1->skipElement(step, ent, ele)) continue;
  int nbComb=data1->getNumComponents(step,ent,ele);
  double vin[3],vout[3];
  double xmin=M_PI,xmax=-M_PI;
	for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++){
	  double x, y, z;
	  int tag = data1->getNode(step, ent, ele, nod, x, y, z);
	  //if(!tag){
	    double x2, y2, z2;
      z2=sqrt(x*x+y*y+z*z);
      y2=asin(z/z2);
      x2=atan2(y,x);
      xmin=std::min(x2,xmin);
      xmax=std::max(x2,xmax);
	    data1->setNode(step, ent, ele, nod, x2*180/M_PI, y2*180/M_PI, z2);
	    data1->tagNode(step, ent, ele, nod, 1);
      if(nbComb==3){
        for(int i=0;i<3;i++)
          data1->getValue(step, ent, ele, nod, i, vin[i]);
        vout[0] = -sin(x2) * vin[0] + cos(x2) * vin[1];
        vout[1] =
          -sin(y2) * (cos(x2) * vin[0] + sin(x2) * vin[1]) +
          cos(y2) * vin[2];
        vout[2] =
          cos(y2) * (cos(x2) * vin[0] + sin(x2) * vin[1]) +
          sin(y2) * vin[2];
        for(int i=0;i<3;i++)
          data1->setValue(step, ent, ele, nod, i, vout[i]);
      }
    //}
  }
  if(xmax-xmin>M_PI){ // periodicity check (broken for continuous views)
    for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++){
      double x,y,z;
	    data1->getNode(step, ent, ele, nod, x, y, z);
      if(xmax*180/M_PI-x > 180) x+=360;
	    data1->setNode(step, ent, ele, nod, x, y, z);
    }
  }
      }
    }
  }

  data1->finalize();
  v1->setChanged(true);
  return v1;
}
