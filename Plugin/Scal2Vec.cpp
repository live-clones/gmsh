// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Scal2Vec.h"
#include "PViewOptions.h"
#include "shapeFunctions.h"

StringXNumber Scal2VecOptions_Number[] = {
  {GMSH_FULLRC, "View X", NULL, -1.},
  {GMSH_FULLRC, "View Y", NULL, -1.},
  {GMSH_FULLRC, "View Z", NULL, -1.}
};

StringXString Scal2VecOptions_String[] = {
  {GMSH_FULLRC, "Name NewView", NULL, "NewView"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterScal2VecPlugin()
  {
    return new GMSH_Scal2VecPlugin();
  }
}

std::string GMSH_Scal2VecPlugin::getHelp() const
{
  return "Plugin(Scal2Vec) converts the scalar fields of 'View X', "
         "'View Y' and/or 'View Z' into a vectorial field. "
         "The new view 'Name NewView' contains it.\n\n"
         "If the value of 'View X', 'View Y' or 'View Z' is -1, "
         "the value of the vectorial field in the corresponding direction is 0.";
}

int GMSH_Scal2VecPlugin::getNbOptions() const
{
  return sizeof(Scal2VecOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_Scal2VecPlugin::getOption(int iopt)
{
  return &Scal2VecOptions_Number[iopt];
}

int GMSH_Scal2VecPlugin::getNbOptionsStr() const
{
  return sizeof(Scal2VecOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_Scal2VecPlugin::getOptionStr(int iopt)
{
  return &Scal2VecOptions_String[iopt];
}


PView *GMSH_Scal2VecPlugin::execute(PView *v)
{
  int iViewX = (int)Scal2VecOptions_Number[0].def;
  int iViewY = (int)Scal2VecOptions_Number[1].def;
  int iViewZ = (int)Scal2VecOptions_Number[2].def;
  std::string nameNewView = Scal2VecOptions_String[0].def;
  
  PView *vRef = 0, *vX = 0, *vY = 0, *vZ = 0;
  PViewData *dataRef, *dataX, *dataY, *dataZ;
  
  // Load data
  if(iViewX >= 0){
    vX = getView(iViewX, v);
    if(!vX){
      Msg::Error("Scal2Vec plugin could not find View X: %i", iViewX);
      return v;
    }
    dataX = vX->getData();
    if(!vRef){
      vRef = vX;
      dataRef = dataX;
    }
  }
  if(iViewY >= 0){
    vY = getView(iViewY, v);
    if(!vY){
      Msg::Error("Scal2Vec plugin could not find View Y: %i", iViewY);
      return v;
    }
    dataY = vY->getData();
    if(!vRef){
      vRef = vY;
      dataRef = dataY;
    }
  }
  if(iViewZ >= 0){
    vZ = getView(iViewZ, v);
    if(!vZ){
      Msg::Error("Scal2Vec plugin could not find View Z: %i", iViewZ);
      return v;
    }
    dataZ = vZ->getData();
    if(!vRef){
      vRef = vZ;
      dataRef = dataZ;
    }
  }
  if(!vRef){
    Msg::Error("Scal2Vec plugin could not find any view.", iViewZ);
    return v;
  }
  
  // Initialize the new view
  PView *vNew = new PView();
  PViewDataList *dataNew = getDataList(vNew);
  
  for(int ent = 0; ent < dataRef->getNumEntities(0); ent++){
    for(int ele = 0; ele < dataRef->getNumElements(0, ent); ele++){
      if(dataRef->skipElement(0, ent, ele)) continue;
      int numComp = 3; // The 3 components of the new view: x,y,z
      int type = dataRef->getType(0, ent, ele);
      int numNodes = dataRef->getNumNodes(0, ent, ele);
      std::vector<double> *out = dataNew->incrementList(numComp, type, numNodes); // Pointer in data of the new view
      if(!out) continue;
      double x[8], y[8], z[8], valX, valY, valZ;
      for(int nod = 0; nod < numNodes; nod++)
        dataRef->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
      int dim = dataRef->getDimension(0, ent, ele);
      elementFactory factory;
      element *element = factory.create(numNodes, dim, x, y, z);
      if(!element) continue;
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]); // Save coordinates (x,y,z)
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = 0; step < dataRef->getNumTimeSteps(); step++){
        for(int nod = 0; nod < numNodes; nod++){
          if(vX) dataX->getValue(step, ent, ele, nod, 0, valX); else valX = 0;
          if(vY) dataY->getValue(step, ent, ele, nod, 0, valY); else valY = 0;
          if(vZ) dataZ->getValue(step, ent, ele, nod, 0, valZ); else valZ = 0;
          out->push_back(valX); // Save values (fx,fy,fz)
          out->push_back(valY);
          out->push_back(valZ);
        }
      }
      delete element;
    }
  }
  
  for(int step = 0; step < dataRef->getNumTimeSteps(); step++){
    if(dataRef->hasTimeStep(step)){
      double time = dataRef->getTime(step);
      dataNew->Time.push_back(time);
    }
  }
  
  dataNew->setName(nameNewView);
  dataNew->setFileName(nameNewView + ".pos");
  dataNew->finalize();
  
  return vNew;
}
