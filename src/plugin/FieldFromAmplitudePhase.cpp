// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "MElement.h"
#include "OctreePost.h"
#include "FieldFromAmplitudePhase.h"

GMSH_FieldFromAmplitudePhasePlugin::GMSH_FieldFromAmplitudePhasePlugin()
  : GMSH_PostPlugin(
      {
        {GMSH_FULLRC, "Wavenumber", nullptr, 5., ""},
        {GMSH_FULLRC, "AmplitudeView", nullptr, 0., ""},
        {GMSH_FULLRC, "PhaseView", nullptr, 1., ""},
      },
      {{GMSH_FULLRC, "MeshFile", nullptr, "fine.msh", ""}})
{
}

std::string GMSH_FieldFromAmplitudePhasePlugin::getHelp() const
{
  return "Plugin(FieldFromAmplitudePhase) builds a complex field 'u' from "
         "amplitude 'a' (complex) and phase 'phi' given in two different "
         "'Views' "
         "u = a * exp(k*phi), with k the wavenumber. \n\n"
         "The result is to be interpolated in a sufficiently fine mesh: "
         "'MeshFile'. \n\n"
         "Plugin(FieldFromAmplitudePhase) generates one new view.";
}

PView *GMSH_FieldFromAmplitudePhasePlugin::execute(PView *v)
{
  double k = (double)option(0);
  int aView = (int)option(1);
  int phiView = (int)option(2);
  std::string fileName = optionStr(0);

  std::string name_model("");

  if(fileName == "") {
    Msg::Info("Could not find mesh file for interpolating U=A*exp(j*k*phi)."
              " Trying to use current model mesh, instead.");
    name_model = GModel::current()->getName();
    fileName = name_model + ".msh";
  }

  PView *va = getView(aView, v);
  if(!va) return v;
  PViewData *aData = va->getData();
  if(aData->getNumTimeSteps() != 2) {
    Msg::Error("Invalid number of time steps for AView, it must be complex!");
    return v;
  }

  PView *vphi = getView(phiView, v);
  if(!vphi) {
    Msg::Error("FieldFromAmplitudePhase plugin could not find PhiView %i",
               phiView);
    return v;
  }
  PViewData *phiData = vphi->getData();

  if(aData->hasMultipleMeshes() || phiData->hasMultipleMeshes()) {
    Msg::Error(
      "FieldFromAmplitudePhase plugin cannot be run on multi-mesh views");
    return v;
  }

  OctreePost *oA = nullptr, *oPhi = nullptr;
  oA = new OctreePost(va);
  oPhi = new OctreePost(vphi);

  GModel::current()->setVisibility(0);
  GModel *umodel = new GModel;
  umodel->readMSH(fileName);
  std::vector<GEntity *> _entities;
  umodel->getEntities(_entities);

  std::set<MVertex *> ve;
  std::map<int, std::vector<double> > dataR;
  std::map<int, std::vector<double> > dataI;

  for(std::size_t ent = 0; ent < _entities.size(); ent++)
    for(std::size_t ele = 0; ele < _entities[ent]->getNumMeshElements();
        ele++) {
      MElement *e = _entities[ent]->getMeshElement(ele);
      for(std::size_t nod = 0; nod < e->getNumVertices(); nod++)
        ve.insert(e->getVertex(nod));
    }

  for(auto it = ve.begin(); it != ve.end(); ++it) {
    double phi, ar, ai;
    std::vector<double> uR(1);
    std::vector<double> uI(1);
    // no value for the nodes outside of the views
    if(!oPhi->searchScalar((*it)->x(), (*it)->y(), (*it)->z(), &phi, 0) ||
       !oA->searchScalar((*it)->x(), (*it)->y(), (*it)->z(), &ar, 0) ||
       !oA->searchScalar((*it)->x(), (*it)->y(), (*it)->z(), &ai, 1))
      continue;

    uR[0] = ar * cos(k * phi) - ai * sin(k * phi);
    uI[0] = ar * sin(k * phi) + ai * cos(k * phi);

    dataR[(*it)->getNum()] = uR;
    dataI[(*it)->getNum()] = uI;
  }

  delete oA;
  delete oPhi;

  PView *vu = new PView("FieldFromAPhi", "NodeData", umodel, dataR, 0.0, 1);
  vu->addStep(umodel, dataI, 1);

  if(name_model.empty())
    umodel->setName("fine");
  else
    umodel->setName(name_model);

  return vu;
}
