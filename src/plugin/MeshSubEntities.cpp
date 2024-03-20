// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  {GMSH_FULLRC, "InputDimension", nullptr, 1.},
  {GMSH_FULLRC, "InputPhysicalGroup", nullptr, 1.},
  {GMSH_FULLRC, "OuputDimension", nullptr, 0.},
  {GMSH_FULLRC, "OuputPhysicalGroup", nullptr, 2000.},
};

extern "C" {
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

  if(inputdim < 0 || inputdim > 3 || outputdim < 0 || outputdim > 3 ||
     outputdim > inputdim) {
    Msg::Error("Bad dimensions");
    return view;
  }

  GModel *m = GModel::current();
  std::map<int, std::vector<GEntity *> > groups;
  m->getPhysicalGroups(inputdim, groups);
  std::vector<GEntity *> entities = groups[inputphysical];

  if(entities.empty()) {
    Msg::Error("Physical group %d (dimension %d) is empty", inputphysical,
               inputdim);
    return view;
  }

  // get input elements
  std::vector<MElement *> elements;
  for(std::size_t i = 0; i < entities.size(); i++)
    for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++)
      elements.push_back(entities[i]->getMeshElement(j));

  if(outputdim == 0) { // create point elements for mesh vertices
    std::set<MVertex *> vertices;
    for(std::size_t i = 0; i < elements.size(); i++) {
      for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++) {
        MVertex *v = elements[i]->getVertex(j);
        vertices.insert(v);
      }
    }
    for(auto it = vertices.begin(); it != vertices.end(); ++it) {
      MVertex *v = *it;
      GVertex *gv = nullptr;
      if(v->onWhat() && v->onWhat()->dim() == 0) {
        gv = (GVertex *)v->onWhat();
      }
      else {
        gv = new discreteVertex(m, m->getMaxElementaryNumber(0) + 1);
        v->setEntity(gv);
        m->add(gv);
      }
      gv->physicals.push_back(outphysical);
      if(gv->points.empty()) gv->points.push_back(new MPoint(v));
    }
    m->pruneMeshVertexAssociations();
  }
  else if(outputdim == 1) { // create line elements for mesh edges
    std::set<MEdge, MEdgeLessThan> edges;
    for(std::size_t i = 0; i < elements.size(); i++) {
      for(int j = 0; j < elements[i]->getNumEdges(); j++) {
        MEdge e = elements[i]->getEdge(j);
        edges.insert(e);
      }
    }
    for(auto it = edges.begin(); it != edges.end(); ++it) {
      const MEdge &e = *it;
      GEdge *ge = nullptr;
      MVertex *v0 = e.getVertex(0), *v1 = e.getVertex(1);
      if(v0->onWhat() && v1->onWhat()) {
        if(v0->onWhat()->dim() == 1 &&
           ((v1->onWhat()->dim() == 1 && v0->onWhat() == v1->onWhat()) ||
            v1->onWhat()->dim() == 0))
          ge = (GEdge *)v0->onWhat();
        else if(v1->onWhat()->dim() == 1 &&
                ((v0->onWhat()->dim() == 1 && v0->onWhat() == v1->onWhat()) ||
                 v0->onWhat()->dim() == 0))
          ge = (GEdge *)v1->onWhat();
      }
      if(!ge) {
        ge = new discreteEdge(m, m->getMaxElementaryNumber(1) + 1, nullptr,
                              nullptr);
        v0->setEntity(ge);
        v1->setEntity(ge);
        m->add(ge);
      }
      ge->physicals.push_back(outphysical);
      if(ge->lines.empty()) ge->lines.push_back(new MLine(v0, v1));
    }
  }
  else {
    Msg::Error("Plugin(MeshSubEntities) not coded yet for output dim %d",
               outputdim);
  }

  CTX::instance()->mesh.changed = ENT_ALL;

  return view;
}
