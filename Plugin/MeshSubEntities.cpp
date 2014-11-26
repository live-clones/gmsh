// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "MeshSubEntities.h"
#include "GModel.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "MElement.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MEdge.h"
#include "MFace.h"
#include "Context.h"

StringXNumber MeshSubEntitiesOptions_Number[] = {
  {GMSH_FULLRC, "InputDimension", NULL, 1.},
  {GMSH_FULLRC, "InputPhysicalGroup", NULL, 1.},
  {GMSH_FULLRC, "OuputDimension", NULL, 0.},
  {GMSH_FULLRC, "OuputPhysicalGroup", NULL, 2000.},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterMeshSubEntitiesPlugin()
  {
    return new GMSH_MeshSubEntitiesPlugin();
  }
}

std::string GMSH_MeshSubEntitiesPlugin::getHelp() const
{
  return "Plugin(MeshSubEntities) creates mesh elements for the "
    "entities of dimension `OutputDimension' (0 for vertices, "
    "1 for edges, 2 for faces) of the `InputPhysicalGroup' of "
    "dimension `InputDimension'. The plugin creates new elements "
    "belonging to `OutputPhysicalGroup'.";
}

int GMSH_MeshSubEntitiesPlugin::getNbOptions() const
{
  return sizeof(MeshSubEntitiesOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MeshSubEntitiesPlugin::getOption(int iopt)
{
  return &MeshSubEntitiesOptions_Number[iopt];
}

PView *GMSH_MeshSubEntitiesPlugin::execute(PView *view)
{
  int inputdim = (int)MeshSubEntitiesOptions_Number[0].def;
  int inputphysical = (int)MeshSubEntitiesOptions_Number[1].def;
  int outputdim = (int)MeshSubEntitiesOptions_Number[2].def;
  int outphysical = (int)MeshSubEntitiesOptions_Number[3].def;

  if(inputdim < 0 || inputdim > 3 || outputdim > inputdim){
    Msg::Error("Bad dimensions");
    return view;
  }

  if(outputdim != 0){
    Msg::Error("Only vertices coded for now");
    return view;
  }

  GModel *m = GModel::current();
  std::map<int, std::vector<GEntity*> > groups[4];
  m->getPhysicalGroups(groups);
  std::vector<GEntity*> entities = groups[inputdim][inputphysical];

  if(entities.empty()){
    Msg::Error("Physical group %d (dimension %d) is empty", inputphysical, inputdim);
    return view;
  }

  // get input elements
  std::vector<MElement*> elements;
  for(unsigned int i = 0; i < entities.size(); i++)
    for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
      elements.push_back(entities[i]->getMeshElement(j));

  // FIXME: generalize this to outputdim != 0 !
  std::set<MVertex*> vertices;
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumVertices(); j++){
      MVertex *v = elements[i]->getVertex(j);
      vertices.insert(v);
    }
  }
  for(std::set<MVertex*>::const_iterator it = vertices.begin(); 
      it != vertices.end(); ++it){
    MVertex *v = *it;
    GVertex *gv = 0;
    if(v->onWhat() && v->onWhat()->dim() == 0){
      gv = (GVertex*)v->onWhat();
    }
    else{
      gv = new discreteVertex(m, m->getMaxElementaryNumber(0) + 1);
      v->setEntity(gv);
      m->add(gv);
    }
    gv->physicals.push_back(outphysical);
    gv->points.push_back(new MPoint(v));
  }
  m->pruneMeshVertexAssociations();

  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}
