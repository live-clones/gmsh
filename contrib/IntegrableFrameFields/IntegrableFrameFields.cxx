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

std::map<Edge*, OdecoIso2D> transferCoarseToFine(MeshRefiner *mr, std::map<Edge*, OdecoIso2D> &mapEdgeFrameCoarse){
  std::map<Edge*, std::vector<OdecoIso2D>> commonSol;
  for(Element *e: mr->m_coarseElemNotRefined){
    for(size_t k=0; k<e->getNumEdges(); k++){
      Edge *edgOnRefineMesh = mr->m_refinedMesh->getElements()[e->getIndex()]->getEdge(k);
      commonSol[edgOnRefineMesh].push_back(mapEdgeFrameCoarse[e->getEdge(k)]);
    }
  }

  for(Element *e: mr->m_coarseElemRefined){
    std::vector<std::vector<double>> solElCoarse;
    solElCoarse.resize(e->getNumEdges());
    for(auto &v: solElCoarse)
      v.resize(OdecoIso2D::nUnknown);
    for(size_t iN=0; iN<e->getNumEdges(); iN++)
      solElCoarse[iN] = mapEdgeFrameCoarse[e->getEdge(iN)].m_frame;
    std::vector<std::vector<double>> solElCoarseRotated;
    OdecoIso2D::getRotatedSolEl(e, solElCoarse, solElCoarseRotated);

    std::vector<double> vRef = e->getDirEdg(0);
    std::vector<double> n = e->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);
    
    for(Element *eFine: e->getChildren()){
      std::vector<std::vector<double>> coordParam = eFine->getEdgesParamCoordInParentElem();
      for(size_t k=0; k<eFine->getNumEdges(); k++){
        std::vector<double> solInterp = e->interpolateCR(coordParam[k][0], coordParam[k][1], solElCoarseRotated);
        std::vector<double> dirEdgFine = eFine->getEdge(k)->getDir();
        double alpha = -atan2(tools::dotprod(t,dirEdgFine), tools::dotprod(vRef,dirEdgFine));
        std::vector<double> rotatedSol;
        OdecoIso2D::getRotatedSol(solInterp, rotatedSol, alpha);
        OdecoIso2D f(rotatedSol);
        commonSol[eFine->getEdge(k)].push_back(f);
      }
    }
  }

  std::map<Edge*, OdecoIso2D> commonSolReduced;
  for(auto &kv: commonSol){
    std::vector<double> averageFrame(OdecoIso2D::nUnknown, 0.0);
    double nFrames = 0.0;
    for(auto &f: kv.second){
      averageFrame = tools::sum(averageFrame, f.m_frame);
      nFrames += 1.0;
    }
    tools::scale(averageFrame, 1.0/nFrames);
    OdecoIso2D newFrame(averageFrame);
    newFrame.projectOnCrossManifold();
    commonSolReduced[kv.first] = newFrame;
  }
  return commonSolReduced;
}

std::map<Edge*, OdecoAniso2D> transferCoarseToFine(MeshRefiner *mr, std::map<Edge*, OdecoAniso2D> &mapEdgeFrameCoarse){
  std::map<Edge*, std::vector<OdecoAniso2D>> commonSol;
  for(Element *e: mr->m_coarseElemNotRefined){
    for(size_t k=0; k<e->getNumEdges(); k++){
      Edge *edgOnRefineMesh = mr->m_refinedMesh->getElements()[e->getIndex()]->getEdge(k);
      commonSol[edgOnRefineMesh].push_back(mapEdgeFrameCoarse[e->getEdge(k)]);
    }
  }

  for(Element *e: mr->m_coarseElemRefined){
    std::vector<std::vector<double>> solElCoarse;
    solElCoarse.resize(e->getNumEdges());
    for(auto &v: solElCoarse)
      v.resize(OdecoAniso2D::nUnknown);
    for(size_t iN=0; iN<e->getNumEdges(); iN++)
      solElCoarse[iN] = mapEdgeFrameCoarse[e->getEdge(iN)].m_frame;
    std::vector<std::vector<double>> solElCoarseRotated;
    OdecoAniso2D::getRotatedSolEl(e, solElCoarse, solElCoarseRotated);

    std::vector<double> vRef = e->getDirEdg(0);
    std::vector<double> n = e->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);
    
    for(Element *eFine: e->getChildren()){
      std::vector<std::vector<double>> coordParam = eFine->getEdgesParamCoordInParentElem();
      for(size_t k=0; k<eFine->getNumEdges(); k++){
        std::vector<double> solInterp = e->interpolateCR(coordParam[k][0], coordParam[k][1], solElCoarseRotated);
        std::vector<double> dirEdgFine = eFine->getEdge(k)->getDir();
        double alpha = -atan2(tools::dotprod(t,dirEdgFine), tools::dotprod(vRef,dirEdgFine));
        std::vector<double> rotatedSol;
        OdecoAniso2D::getRotatedSol(solInterp, rotatedSol, alpha);
        OdecoAniso2D f(rotatedSol);
        commonSol[eFine->getEdge(k)].push_back(f);
      }
    }
  }

  std::map<Edge*, OdecoAniso2D> commonSolReduced;
  for(auto &kv: commonSol){
    std::vector<double> averageFrame(OdecoAniso2D::nUnknown, 0.0);
    double nFrames = 0.0;
    for(auto &f: kv.second){
      averageFrame = tools::sum(averageFrame, f.m_frame);
      nFrames += 1.0;
    }
    tools::scale(averageFrame, 1.0/nFrames);
    OdecoAniso2D newFrame(averageFrame);
    newFrame.projectOnCrossManifold();
    commonSolReduced[kv.first] = newFrame;
  }
  return commonSolReduced;
}

void iffComputeIntegrableFrameField(GModel *gm){
  std::vector<MElement*> elements;
  std::vector<MLine*> lines;
  std::vector<MVertex*> geoNodes;
  for(GVertex *gv: gm->getVertices()){
    geoNodes.push_back(gv->getMeshVertex(0));
  }
  for(GFace *gf: gm->getFaces()){
    elements.insert(elements.end(), gf->triangles.begin(), gf->triangles.end());
    elements.insert(elements.end(), gf->quadrangles.begin(), gf->quadrangles.end());
  }
  for(GEdge *ge: gm->getEdges())
    lines.insert(lines.end(), ge->lines.begin(), ge->lines.end());
  
  Mesh m_orig(elements, lines, geoNodes);
  m_orig.printInfos();

  int nRefinement = -1;
  std::vector<Mesh*> listMeshes{&m_orig};
  std::vector<MeshRefiner*> listMeshRefiner;
  
  std::map<Edge*, OdecoIso2D> edgeFrameInit;
  // std::map<Edge*, OdecoIso2D> edgeFrameInit;
  std::map<Edge*, OdecoAniso2D> edgeFrameInitAniso;
  
  int nRefinementsMax = 0;
  while(nRefinement < nRefinementsMax){
    std::cout << "++++++++++++++++++++++++++++++++++++ Refinement stage " << nRefinement + 1 << " ++++++++++++++++++++++++++++++++++++" << std::endl;
    Mesh *m = listMeshes[listMeshes.size()-1];
    
    double fact = 1.0;
    // FrameField<GLIso2D> framefield(m);
    // FrameField<OdecoIso2D> framefield(m, fact);
    // FrameField<OdecoAniso2D> framefieldAniso(m, fact, "smoothBC");
    FrameField<OdecoAniso2D> framefieldAniso(m, fact, "hardBC");
    FrameField<OdecoIso2D> framefield(m, fact, "hardBC");
    // framefield.m_typeBC = "hardBC";
    // FrameField<OdecoAniso2D> framefield(m, fact);
    
    if(edgeFrameInit.size() == 0){
    // if(1){
      framefield.generateLaplacianSolution();
      std::map<Element *, std::vector<std::vector<double>>> mapElemDirInit = framefield.getDirectionsPerElem();
      visu::framefield(mapElemDirInit, "Laplacian frames");
      framefield.generate();
    }
    else{
      std::vector<Edge*> listFixedEdges = listMeshRefiner[listMeshRefiner.size()-1]->getEdgesCLMultiGrille();

      framefield.setFixedEdges(listFixedEdges);
      framefield.setInitFrameField(edgeFrameInit);
      framefield.generateNoComp();
      framefield._locateSingularities();
      framefield._locateSingularitiesVertices();
      visu::scalarField(framefield.m_singularities, "Sings Init");
      visu::scalarField(framefield.m_singularitiesVertices, "SingsVert Init");
      std::map<Element *, std::vector<std::vector<double>>> mapElemDirInit = framefield.getDirectionsPerElem();
      visu::framefield(mapElemDirInit, "Init frames");

    }
    framefield.projectFrames();
    framefield.printFrameFieldData("Smooth frames");
    
    // framefield.generateIntegrableFrameField();
    // framefield.printFrameFieldData("Integrable frames glob");

    // double integrabilityErrorGlob = 0.0;
    // std::map<Element*, double> mapElemErrorIntGlob = framefield.getIntegrabilityError();
    // for(auto &kv: mapElemErrorIntGlob)
    //   integrabilityErrorGlob += kv.second;
    std::cout << "+++ --- +++ Integrability error glob before proj: " << framefield.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;
    framefield.projectFrames();
    // mapElemErrorIntGlob = framefield.getIntegrabilityError();
    // integrabilityErrorGlob = 0.0;
    // for(auto &kv: mapElemErrorIntGlob)
    //   integrabilityErrorGlob += kv.second;
    std::cout << "+++ --- +++ Integrability error glob after proj: " << framefield.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;
    // // ------------
    // framefield.generateIntegrableFrameFieldCustom();
    // mapElemDir = framefield.getDirectionsPerElem();
    // ------------
    
    framefield._generateIntegrableFrameFieldImposedDIrections();
    framefield.printFrameFieldData("Integrable frames glob with imposed dir");
    std::cout << "+++ --- +++ Integrability error glob with imposed dir: " << framefield.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;

    //Compute anisotrope integrable framefield based on isotrope solution
    std::map<Edge*, OdecoAniso2D> initAnisoFrames;
    for(auto &kv: framefield.getFrameField()){
      OdecoAniso2D fAniso({kv.second.m_frame[0], 0.0, 0.0, kv.second.m_frame[1], kv.second.m_frame[2]});
      initAnisoFrames[kv.first] = fAniso;
    }
    framefieldAniso.setInitFrameField(initAnisoFrames);
    framefieldAniso._generateIntegrableFrameFieldImposedDIrections();
    framefieldAniso.generateIntegrableFrameField();
    framefieldAniso.printFrameFieldData("Integrable anisotrope frames");
    // double integrabilityErrorAniso = 0.0;
    // std::map<Element*, double> mapElemErrorIntAniso = framefieldAniso.getIntegrabilityError();
    // for(auto &kv: mapElemErrorIntAniso)
    //   integrabilityErrorAniso += kv.second;
    std::cout << "+++ --- +++ Integrability error aniso before proj: " << framefieldAniso.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;
    framefieldAniso.projectFrames();
    // mapElemErrorIntAniso = framefieldAniso.getIntegrabilityError();
    // integrabilityErrorAniso = 0.0;
    // for(auto &kv: mapElemErrorIntAniso)
    //   integrabilityErrorAniso += kv.second;
    std::cout << "+++ --- +++ Integrability error aniso after proj: " << framefieldAniso.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;
    framefieldAniso._generateIntegrableFrameFieldImposedDIrections();
    framefieldAniso.printFrameFieldData("Integrable anisotrope frames with imposed dir");
    std::cout << "+++ --- +++ Integrability error aniso with imposed dir: " << framefieldAniso.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;
    //
    
    //Refinment based on integrability density error
    std::map<Element*, double> mapElemErrorIntDensity = framefield.getIntegrabilityErrorDensity();
    std::vector<size_t> elemToRefine;
    std::vector<Element*> allowedElements;
    if(listMeshRefiner.size()>0)
      allowedElements = listMeshRefiner[listMeshRefiner.size()-1]->getFineElemRefinedUnmodified();
    for(auto &kv: mapElemErrorIntDensity){
    // for(auto &kv: mapElemErrorInt){
      if(kv.second > 0.2){
        if(allowedElements.size() > 0){
          if(std::find(allowedElements.begin(), allowedElements.end(), kv.first) != allowedElements.end())
            elemToRefine.push_back(kv.first->getIndex());
        }
        else
          elemToRefine.push_back(kv.first->getIndex());
      }
    }

    double integrabilityError = 0.0;
    std::map<Element*, double> mapElemErrorInt = framefield.getIntegrabilityError();
    for(auto &kv: mapElemErrorInt)
      integrabilityError += kv.second;
    std::cout << "+++ --- +++ Integrability error: " << integrabilityError << " +++ --- +++" << std::endl;
    Mesh *mRefined = new Mesh;
    MeshRefiner *mr = new MeshRefiner(m, mRefined);
    listMeshRefiner.push_back(mr);
    mr->refineMesh(elemToRefine);
    mRefined->printInfos();
    listMeshes.push_back(mRefined);
    auto ff = framefield.getFrameField();
    edgeFrameInit = transferCoarseToFine(mr, ff);
    nRefinement++;
  }
  // for(MElement *e: Mesh::hangingGmshElementsCollector)
  //   delete e;
  // Mesh::hangingGmshElementsCollector.clear();
}

