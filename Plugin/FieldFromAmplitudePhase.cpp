// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "Gmsh.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "MElement.h"
#include "OctreePost.h"
#include "FieldFromAmplitudePhase.h"


StringXNumber FieldFromAmplitudePhaseOptions_Number[] = {
  {GMSH_FULLRC, "Wavenumber", NULL, 5.},
  {GMSH_FULLRC, "AmplitudeView", NULL, 0.},
  {GMSH_FULLRC, "PhaseView", NULL, 1.},
};

StringXString FieldFromAmplitudePhaseOptions_String[] = {
  {GMSH_FULLRC, "MeshFile", NULL, "fine.msh"}
};


extern "C"
{
  GMSH_Plugin *GMSH_RegisterFieldFromAmplitudePhasePlugin()
  {
    return new GMSH_FieldFromAmplitudePhasePlugin();
  }
}

std::string GMSH_FieldFromAmplitudePhasePlugin::getHelp() const
{
  return "Plugin(FieldFromAmplitudePhase) builds a complex field 'u' from "
    "amplitude 'a' (complex) and phase 'phi' given in two different 'Views' "
    "u = a * exp(k*phi), with k the wavenumber. \n\n"
    "The result is to be interpolated in a sufficiently fine mesh: "
    "'MeshFile'. \n\n"
    "Plugin(FieldFromAmplitudePhase) generates one new view.";
}

int GMSH_FieldFromAmplitudePhasePlugin::getNbOptions() const
{
  return sizeof(FieldFromAmplitudePhaseOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_FieldFromAmplitudePhasePlugin::getOption(int iopt)
{
  return &FieldFromAmplitudePhaseOptions_Number[iopt];
}

int GMSH_FieldFromAmplitudePhasePlugin::getNbOptionsStr() const
{
  return sizeof(FieldFromAmplitudePhaseOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_FieldFromAmplitudePhasePlugin::getOptionStr(int iopt)
{
  return &FieldFromAmplitudePhaseOptions_String[iopt];
}

PView *GMSH_FieldFromAmplitudePhasePlugin::execute(PView *v)
{
  double k    = (double)FieldFromAmplitudePhaseOptions_Number[0].def;
  int aView   = (int)FieldFromAmplitudePhaseOptions_Number[1].def;
  int phiView = (int)FieldFromAmplitudePhaseOptions_Number[2].def;
  std::string fileName = FieldFromAmplitudePhaseOptions_String[0].def;

  std::string name_model("") ; 

  if(fileName==""){
    Msg::Info("Could not find mesh file for interpolating U=A*exp(j*k*phi)." 
               " Trying to use current model mesh, instead.") ;
    name_model = GModel::current()->getName() ; 
    fileName = name_model + ".msh" ;
  } 

  PView *va = getView(aView, v);
  if(!va) return v;
  PViewData *aData = va->getData();
  if(aData->getNumTimeSteps() != 2){
    Msg::Error("Invalid number of time steps for AView, it must be complex!");
    return v ;
  }

  PView *vphi = getView(phiView, v);
  if(!vphi){
    Msg::Error("FieldFromAmplitudePhase plugin could not find PhiView %i", phiView);
    return v;
  }
  PViewData *phiData = vphi->getData();
  
  if(aData->hasMultipleMeshes() || phiData->hasMultipleMeshes()){
    Msg::Error("FieldFromAmplitudePhase plugin cannot be run on multi-mesh views");
    return v;
  }

  OctreePost *oA = 0, *oPhi = 0 ;
  oA = new OctreePost(va); 
  oPhi = new OctreePost(vphi); 

  GModel::current()->setVisibility(0);
  GModel *umodel = new GModel ;  
  umodel->readMSH(fileName) ; 
  std::vector<GEntity*> _entities ;
  umodel->getEntities(_entities) ;    
     
  std::set<MVertex*> ve;
  std::map<int, std::vector<double> > dataR ;
  std::map<int, std::vector<double> > dataI ;

  for(unsigned int ent = 0; ent < _entities.size(); ent++)
    for(unsigned int ele = 0; ele < _entities[ent]->getNumMeshElements(); ele++){ 
      MElement *e = _entities[ent]->getMeshElement(ele);	
      for(int nod = 0; nod < e->getNumVertices() ; nod++)
        ve.insert(e->getVertex(nod));
    }
  
  for (std::set<MVertex*>::iterator it = ve.begin(); it != ve.end(); ++it){
    double phi, ar, ai ;
    std::vector<double> uR(1) ;
    std::vector<double> uI(1) ;
    oPhi->searchScalar((*it)->x(), (*it)->y(), (*it)->z(), &phi, 0);
    oA->searchScalar((*it)->x(), (*it)->y(), (*it)->z(), &ar, 0);
    oA->searchScalar((*it)->x(), (*it)->y(), (*it)->z(), &ai, 1);
    
    uR[0] = ar * cos(k*phi) - ai * sin(k*phi) ;
    uI[0] = ar * sin(k*phi) + ai* cos(k*phi) ;
    
    dataR[(*it)->getNum()] = uR ;   
    dataI[(*it)->getNum()] = uI ;   
  }
  
  delete oA ;
  delete oPhi;
    
  PView *vu = new PView("FieldFromAPhi","NodeData", umodel, dataR, 0.0, 1) ;
  vu->addStep(umodel, dataI, 1);

  if(name_model.empty())
    umodel->setName("fine");
  else
    umodel->setName(name_model);

  return vu;
}
