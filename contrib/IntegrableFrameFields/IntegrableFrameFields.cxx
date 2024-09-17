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

  FrameField<OdecoIso2D> cleanedFramesIso(&m_orig, 0.0, "hardBC");
  FrameField<OdecoAniso2D> cleanedFramesAniso(&m_orig, 0.0, "hardBC");
  // FrameField<OdecoIso2D> cleanedFramesIso(&m_orig, 0.0, "smoothBC");
  // FrameField<OdecoAniso2D> cleanedFramesAniso(&m_orig, 0.0, "smoothBC");

  // FrameField<OdecoAniso2D> finalFrameField(&m_orig, 1.0, "smoothBC");
  FrameField<OdecoAniso2D> finalFrameField(&m_orig, 1.0, "hardBC");
  int nRefinementsMax = 0;
  while(nRefinement < nRefinementsMax){
    std::cout << "++++++++++++++++++++++++++++++++++++ Refinement stage " << nRefinement + 1 << " ++++++++++++++++++++++++++++++++++++" << std::endl;
    Mesh *m = listMeshes[listMeshes.size()-1];
    
    double fact = 1.0;
    FrameField<OdecoAniso2D> framefieldAniso(m, fact, "hardBC");
    // FrameField<OdecoAniso2D> framefieldAniso(m, fact, "smoothBC");
    FrameField<OdecoIso2D> framefield(m, fact, "hardBC");
    // framefield.m_typeBC = "hardBC";
    // FrameField<OdecoAniso2D> framefield(m, fact);
    
    if(edgeFrameInit.size() == 0){
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
    
    framefield.generateIntegrableFrameField();

    framefield.printFrameFieldData("Integrable frames glob");

    std::cout << "+++ --- +++ Integrability error glob before proj: " << framefield.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;
    framefield.projectFrames();

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

    std::cout << "+++ --- +++ Integrability error aniso before proj: " << framefieldAniso.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;

    std::cout << "+++ --- +++ Integrability error aniso after proj: " << framefieldAniso.getTotalIntegrabilityError() << " +++ --- +++" << std::endl;
    framefieldAniso._generateIntegrableFrameFieldImposedDIrections();
    framefieldAniso.printFrameFieldData("Integrable anisotrope frames with imposed dir");
    framefieldAniso.projectFrames();
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
    std::map<Element*, double> mapElemErrorInt = framefieldAniso.getIntegrabilityError();
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

    if(nRefinement >= nRefinementsMax){
      cleanedFramesIso = framefield.getCleanedFramefield();
      finalFrameField = framefieldAniso;
      cleanedFramesAniso = framefieldAniso.getCleanedFramefield();
    }
  }

  if(0){
    std::vector<Edge*> cg;
    std::map<Edge*, std::vector<double>> cgVisu;
    // cleanedFramesIso.printFrameFieldData("Cleaned Iso");
    // cg = cleanedFramesIso.getCutGraph();
    // for(Edge *edg: cg)
    //   cgVisu[edg] = {1.0, 1.0};
    // visu::scalarField(cgVisu, "CutGraph");

    // Mesh *cutMesh = new Mesh;
    // MeshRefiner meshCutter(cleanedFramesIso.getMesh(), cutMesh);
    // meshCutter.cutMeshOnEdges(cg);

    // FrameField<OdecoIso2D> frameFieldOnCutMeshIso(cutMesh);
    // std::map<Edge*, OdecoIso2D> mapFramesOnCutMesh;
    // std::map<Edge*, OdecoIso2D> mapFramesCleaned = cleanedFramesIso.getFrameField();
    // for(size_t kEl=0; kEl<cleanedFramesIso.getMesh()->getNumElements(); kEl++){
    //   Element *e = cleanedFramesIso.getMesh()->getElement(kEl);
    //   Element *eCut = cutMesh->getElement(kEl);
    //   for(size_t kEdg=0; kEdg<e->getNumEdges(); kEdg++)
    //     mapFramesOnCutMesh[eCut->getEdge(kEdg)] = mapFramesCleaned[e->getEdge(kEdg)];
    // }
    // for(auto &kv: mapFramesOnCutMesh){
    //   std::vector<std::vector<double>> dirFrames = kv.second.getDirections();
    //   for(auto &v: dirFrames){
    //     tools::normalize(v);
    //     tools::scale(v, 0.1);
    //   }
    //   std::vector<std::vector<double>> newDirs{dirFrames[0], dirFrames[1]};
    //   OdecoIso2D newF(newDirs);
    //   kv.second = newF;
    // }
    // frameFieldOnCutMeshIso.setInitFrameField(mapFramesOnCutMesh);
    // frameFieldOnCutMeshIso.printFrameFieldData("ON CUT MESH");
    // frameFieldOnCutMeshIso.computeParametrization();


    cleanedFramesAniso.printFrameFieldData("Cleaned Aniso");
    cg = cleanedFramesAniso.getCutGraph();
    cgVisu.clear();
    for(Edge *edg: cg)
      cgVisu[edg] = {1.0, 1.0};
    visu::scalarField(cgVisu, "CutGraph");
    
    Mesh *cutMeshAniso = new Mesh;
    MeshRefiner meshCutterAniso(cleanedFramesAniso.getMesh(), cutMeshAniso);
    meshCutterAniso.cutMeshOnEdges(cg);

    std::cout << "uncut mesh: " << std::endl;
    cleanedFramesAniso.getMesh()->printInfos();
    std::cout << "cutmesh: " << std::endl;
    cutMeshAniso->printInfos();
    FrameField<OdecoAniso2D> frameFieldOnCutMeshAniso(cutMeshAniso);
    std::map<Edge*, OdecoAniso2D> mapFramesOnCutMeshAniso;
    std::map<Edge*, OdecoAniso2D> mapFramesCleanedAniso = cleanedFramesAniso.getFrameField();
    for(size_t kEl=0; kEl<cleanedFramesAniso.getMesh()->getNumElements(); kEl++){
      Element *e = cleanedFramesAniso.getMesh()->getElement(kEl);
      Element *eCut = cutMeshAniso->getElement(kEl);
      for(size_t kEdg=0; kEdg<e->getNumEdges(); kEdg++)
        mapFramesOnCutMeshAniso[eCut->getEdge(kEdg)] = mapFramesCleanedAniso[e->getEdge(kEdg)];
    }
    frameFieldOnCutMeshAniso.setInitFrameField(mapFramesOnCutMeshAniso);
    std::vector<std::tuple<size_t, size_t, OdecoAniso2D>> listFrameFieldBC;
    frameFieldOnCutMeshAniso.getQuantizedFrameFieldBC(listFrameFieldBC);

    // frameFieldOnCutMeshIso.printFrameFieldData("ON CUT MESH");
    frameFieldOnCutMeshAniso.computeParametrization();
    std::vector<Edge*> fixedEdgesQuantized;
    for(auto &tpl: listFrameFieldBC){
      Mesh *currMesh = cleanedFramesAniso.getMesh();
      Element *e = currMesh->getElement(std::get<0>(tpl));
      size_t iLocEdg = std::get<1>(tpl);
      OdecoAniso2D frameToImpose = std::get<2>(tpl);
      Edge *edg = e->getEdge(iLocEdg);
      fixedEdgesQuantized.push_back(edg);
      cleanedFramesAniso.m_mapEdgeFrames[edg] = frameToImpose;
    }
    cleanedFramesAniso.addFixedEdges(fixedEdgesQuantized);
    cleanedFramesAniso._generateIntegrableFrameFieldImposedDIrections();
    cleanedFramesAniso.printFrameFieldData("Cleaned Aniso Quantized");

    mapFramesOnCutMeshAniso.clear();
    mapFramesCleanedAniso = cleanedFramesAniso.getFrameField();
    for(size_t kEl=0; kEl<cleanedFramesAniso.getMesh()->getNumElements(); kEl++){
      Element *e = cleanedFramesAniso.getMesh()->getElement(kEl);
      Element *eCut = cutMeshAniso->getElement(kEl);
      for(size_t kEdg=0; kEdg<e->getNumEdges(); kEdg++)
        mapFramesOnCutMeshAniso[eCut->getEdge(kEdg)] = mapFramesCleanedAniso[e->getEdge(kEdg)];
    }
    frameFieldOnCutMeshAniso.setInitFrameField(mapFramesOnCutMeshAniso);

    // frameFieldOnCutMeshIso.printFrameFieldData("ON CUT MESH");
    frameFieldOnCutMeshAniso.computeParametrization();
    std::map<Edge*, std::vector<double>> cgVisuDbg;
    for(Edge *edg: frameFieldOnCutMeshAniso.getMesh()->getEdges()){
      if(edg->isOnCutGraph())
        cgVisuDbg[edg] = {1.0, 1.0};
    }
    visu::scalarField(cgVisuDbg, "CutGraphDBG");

  }
  
  // visu::scalarField(checkData, "TEST DATA");
  // for(MElement *e: Mesh::hangingGmshElementsCollector)
  //   delete e;
  // Mesh::hangingGmshElementsCollector.clear();
}

