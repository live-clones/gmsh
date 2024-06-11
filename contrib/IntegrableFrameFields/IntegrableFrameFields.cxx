// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#include <IntegrableFrameFields.hxx>
#include <IffTools.hxx>
#include <GModel.h>
#include <MTriangle.h>
#include <MQuadrangle.h>
#include <MLine.h>
#include <IffTools.hxx>
#include <ObjectiveFunctions.hxx>
#include <Solver.hxx>
#include <Visualization.hxx>
#include <gmsh.h>
#include <odecoFrames.hxx>
#include <FrameField.hxx>

using namespace IFF;

void iffComputeIntegrableFrameField(GModel *gm){
  std::vector<MElement*> elements;
  std::vector<MLine*> lines;
  for(GFace *gf: gm->getFaces()){
    elements.insert(elements.end(), gf->triangles.begin(), gf->triangles.end());
    elements.insert(elements.end(), gf->quadrangles.begin(), gf->quadrangles.end());
  }
  for(GEdge *ge: gm->getEdges())
    lines.insert(lines.end(), ge->lines.begin(), ge->lines.end());

  // Mesh m(elements, lines);
  // m.printInfos();
  
  Mesh m_orig(elements, lines);
  m_orig.printInfos();
  Mesh m;
  MeshRefiner(&m_orig, &m);
  m.printInfos();

  std::map<Element*, std::vector<double>> mapElemNormal;
  for(Element* e: m.getElements())
    mapElemNormal[e] = e->getNormal();
  visu::vectorField(mapElemNormal, "Normales");
  // exit(0);
  // FrameField<GLIso2D> framefield(&m);
  FrameField<OdecoIso2D> framefield(&m);
  // FrameField<OdecoAniso2D> framefield(&m);
  framefield.generate();
  std::map<Element*, double> mapElemErrorIntDensitySmooth = framefield.getIntegrabilityErrorDensity();
  visu::scalarField(mapElemErrorIntDensitySmooth, "Integrability error density smooth ff");
  std::map<Element *, std::vector<std::vector<double>>> mapElemDir = framefield.getDirectionsPerElem();
  visu::framefield(mapElemDir, "Smooth frames");
  framefield.generateIntegrableFrameField();
  mapElemDir = framefield.getDirectionsPerElem();
  visu::framefield(mapElemDir, "Integrable frames");
  framefield._locateSingularities();
  framefield._locateSingularitiesVertices();
  visu::scalarField(framefield.m_singularities, "Sings");
  visu::scalarField(framefield.m_singularitiesVertices, "SingsVert");
  std::map<Element*, double> mapElemErrorIntDensity = framefield.getIntegrabilityErrorDensity();
  visu::scalarField(mapElemErrorIntDensity, "Integrability error density");
  // for(MElement *e: Mesh::hangingGmshElementsCollector)
  //   delete e;
  // Mesh::hangingGmshElementsCollector.clear();
}

