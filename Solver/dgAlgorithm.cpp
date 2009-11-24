#include <set>
#include "dgAlgorithm.h"
#include "dgGroupOfElements.h"
#include "dgConservationLaw.h"
#include "GEntity.h"
#include "MElement.h"
#include "GModel.h"
#include "MEdge.h"
#include "function.h"
/*
  compute 
    \int \vec{f} \cdot \grad \phi dv   
*/

void dgAlgorithm::residualVolume ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfElements & group, 
				   const fullMatrix<double> &solution,
				   fullMatrix<double> &residual // the residual
           )
{ 
  // ----- 1 ----  get the solution at quadrature points
  // ----- 1.1 --- allocate a matrix of size (nbFields * nbElements, nbQuadraturePoints) 
  int nbFields = claw.nbFields();
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * nbFields);
  // ----- 1.2 --- multiply the solution by the collocation matrix
  group.getCollocationMatrix().mult(solution  , solutionQP); 

  // ----- 2 ----  compute all fluxes (diffusive and convective) at integration points
  // ----- 2.1 --- allocate elementary fluxes (compued in XYZ coordinates)
  fullMatrix<double> fConv[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), nbFields ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), nbFields ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), nbFields )};
  fullMatrix<double> fDiff[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), nbFields ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), nbFields ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), nbFields )};
  fullMatrix<double> Source = fullMatrix<double> (group.getNbIntegrationPoints(),group.getNbElements() * nbFields);
  // ----- 2.2 --- allocate parametric fluxes (computed in UVW coordinates) for all elements at all integration points
  fullMatrix<double> Fuvw[3] = {fullMatrix<double> ( group.getNbIntegrationPoints(), group.getNbElements() * nbFields),
				fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * nbFields),
				fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * nbFields)};
  dataCacheMap cacheMap;
  dataCacheElement &cacheElement = cacheMap.getElement();
  // provided dataCache
  cacheMap.provideData("UVW").set(group.getIntegrationPointsMatrix());
  dataCacheDouble &solutionQPe = cacheMap.provideData("Solution");
  dataCacheDouble &gradSolutionQPe = cacheMap.provideData("gradSolution");
  // needed dataCache
  dataCacheDouble *sourceTerm = claw.newSourceTerm(cacheMap);
    // fluxes in  XYZ coordinates;
  dataCacheDouble *convectiveFlux = claw.newConvectiveFlux(cacheMap);
  dataCacheDouble *diffusiveFlux = claw.newDiffusiveFlux(cacheMap);

  // compute the gradient of solution if necessary
  fullMatrix<double> *gradientSolutionQP= 0;
  if (gradSolutionQPe.somethingDependOnMe()) {
    gradientSolutionQP = new  fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * nbFields * 3);
    //group.getGradientOfSolution().mult ( group.getCollocationMatrix() , *gradientSolutionQP); 
  }
  // ----- 2.3 --- iterate on elements
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
    // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    solutionQPe.set(fullMatrix<double>(solutionQP, iElement*nbFields, nbFields ));
    if (gradSolutionQPe.somethingDependOnMe())
      gradSolutionQPe.set(fullMatrix<double>(*gradientSolutionQP, 3*iElement*nbFields,3*nbFields ));
    cacheElement.set(group.getElement(iElement));
    if(convectiveFlux || diffusiveFlux) {
      // ----- 2.3.3 --- compute fluxes in UVW coordinates
      for (int iUVW=0;iUVW<group.getDimUVW();iUVW++) {
        // ----- 2.3.3.1 --- get a proxy on the big local flux matrix
        fullMatrix<double> fuvwe(Fuvw[iUVW], iElement*nbFields,nbFields);
        // ----- 2.3.3.1 --- compute \vec{f}^{UVW} =\vec{f}^{XYZ} J^{-1} and multiply bt detJ
        for (int iXYZ=0;iXYZ<group.getDimXYZ();iXYZ++) {
          for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
            // get the right inv jacobian matrix dU/dX element
            const double invJ = group.getInvJ (iElement, iPt, iUVW, iXYZ);
            // get the detJ at this point
            const double detJ = group.getDetJ (iElement, iPt);
            const double factor = invJ * detJ;
            // compute fluxes in the reference coordinate system at this integration point
            for (int k=0;k<nbFields;k++){
              if(convectiveFlux)
                fuvwe(iPt,k) += ( (*convectiveFlux)(iPt,iXYZ*nbFields+k)) * factor;
              if(diffusiveFlux)
                fuvwe(iPt,k) += ( (*diffusiveFlux)(iPt,iXYZ*nbFields+k)) * factor;
            }
          }
        } 
      }
    }
    if (sourceTerm){
      fullMatrix<double> source(Source, iElement*claw.nbFields(),claw.nbFields());
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iElement, iPt);
        for (int k=0;k<nbFields;k++){
          source(iPt,k) = (*sourceTerm)(iPt,k)*detJ;
        }
      }
    }
    if(gradientSolutionQP)
      delete gradientSolutionQP;
  }
  // ----- 3 ---- do the redistribution at nodes using as many BLAS3 operations as there are local coordinates
  if(convectiveFlux || diffusiveFlux){
    for (int iUVW=0;iUVW<group.getDimUVW();iUVW++){
      residual.gemm(group.getFluxRedistributionMatrix(iUVW),Fuvw[iUVW]);
    }
    if(convectiveFlux)
      delete convectiveFlux;
    if(diffusiveFlux)
      delete diffusiveFlux;
  }
  if(sourceTerm){
    residual.gemm(group.getSourceRedistributionMatrix(),Source);
    delete sourceTerm;
  }
}

void dgAlgorithm::residualInterface ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfFaces &group, 
           const fullMatrix<double> &solution, // solution !! at faces nodes
           fullMatrix<double> &residual // residual !! at faces nodes
           )
{ 
  int nbFields = claw.nbFields();
  // ----- 1 ----  get the solution at quadrature points
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * nbFields*2);
  group.getCollocationMatrix().mult(solution, solutionQP); 
  // ----- 2 ----  compute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP ( group.getNbIntegrationPoints(), group.getNbElements()*nbFields*2);
  dataCacheMap cacheMapLeft, cacheMapRight;
  // provided dataCache
  cacheMapLeft.provideData("UVW").set(group.getIntegrationPointsMatrix());
  dataCacheDouble &solutionQPLeft = cacheMapLeft.provideData("Solution");
  dataCacheDouble &solutionQPRight = cacheMapRight.provideData("Solution");
  dataCacheDouble &normals = cacheMapLeft.provideData("Normals");
  dataCacheElement &cacheElementLeft = cacheMapLeft.getElement();
  dataCacheElement &cacheElementRight = cacheMapRight.getElement();
  // required data
  dataCacheDouble *riemannSolver = claw.newRiemannSolver(cacheMapLeft,cacheMapRight);
  for (int iFace=0 ; iFace<group.getNbElements() ;++iFace) {
    // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    solutionQPLeft.set(fullMatrix<double>(solutionQP, iFace*2*nbFields, nbFields));
    solutionQPRight.set(fullMatrix<double>(solutionQP, (iFace*2+1)*nbFields, nbFields));
    normals.set(group.getNormals(iFace));
    cacheElementLeft.set(group.getElementLeft(iFace));
    cacheElementRight.set(group.getElementRight(iFace));
    fullMatrix<double> normalFluxQP (NormalFluxQP, iFace*nbFields*2, nbFields*2);
    // ----- 2.3.2 --- compute fluxes
    for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
      const double detJ = group.getDetJ (iFace, iPt);
      for (int k=0;k<nbFields*2;k++)
        normalFluxQP(iPt,k) = (*riemannSolver)(iPt,k)*detJ;
    }
  }
  // ----- 3 ---- do the redistribution at face nodes using BLAS3
  residual.gemm(group.getRedistributionMatrix(),NormalFluxQP);
  delete riemannSolver;
}

void dgAlgorithm::multAddInverseMassMatrix ( /*dofManager &dof,*/
          const dgGroupOfElements & group,
          fullMatrix<double> &residu,
          fullMatrix<double> &sol)
		  
{
  for(int i=0;i<group.getNbElements();i++) {
    fullMatrix<double> residuEl(residu,i,1);
    fullMatrix<double> solEl(sol,i,1);
    solEl.gemm(group.getInverseMassMatrix(i),residuEl);
  }
}

 void dgAlgorithm::rungeKutta (const dgConservationLaw &claw, // conservation law
		  std::vector<dgGroupOfElements*> &eGroups, //group of elements
		  std::vector<dgGroupOfFaces*> &fGroups,  // group of interfacs
		  std::vector<dgGroupOfFaces*> &bGroups, // group of boundaries
		  double h,		
          fullMatrix<double> &residu,
          fullMatrix<double> &sol,
		  int orderRK)
{


// U_{n+1}=U_n+h*(SUM_i a_i*K_i)
// K_i=M^(-1)R(U_n+b_i*K_{i-1})
  
  double a[4] = {h/6.0,h/3.0,h/3.0,h/6.0};
  double b[4] = {0.,h/2.0,h/2.0,h};
  	
  fullMatrix<double> K(sol);
  // Current updated solution
  fullMatrix<double> Unp(sol);
  
  for(int j=0; j<orderRK;j++){
	if(j!=0){
		K.scale(b[j]);
		K.add(sol);
		}
	this->residual(claw,eGroups,fGroups,bGroups,K,residu);
	K.scale(0.);
	for(int i=0;i<eGroups[0]->getNbElements();i++) {
		fullMatrix<double> residuEl(residu,i,1);
		fullMatrix<double> KEl(K,i,1);
		(eGroups[0]->getInverseMassMatrix(i)).mult(residuEl,KEl);
    }
	
	Unp.add(K,a[j]);
  }
  
  sol=Unp;
}


void dgAlgorithm::residualBoundary ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfFaces &group, 
           const fullMatrix<double> &solution, // solution !! at faces nodes
           fullMatrix<double> &residual // residual !! at faces nodes
           )
{ 
  int nbFields = claw.nbFields();
  const dgBoundaryCondition *boundaryCondition = claw.getBoundaryCondition(group.getBoundaryTag());
  // ----- 1 ----  get the solution at quadrature points
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * nbFields);
  group.getCollocationMatrix().mult(solution, solutionQP); 
  // ----- 2 ----  compute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP ( group.getNbIntegrationPoints(), group.getNbElements()*nbFields);

  dataCacheMap cacheMapLeft;
  // provided dataCache
  cacheMapLeft.provideData("UVW").set(group.getIntegrationPointsMatrix());
  dataCacheDouble &solutionQPLeft = cacheMapLeft.provideData("Solution");
  dataCacheDouble &normals = cacheMapLeft.provideData("Normals");
  dataCacheElement &cacheElementLeft = cacheMapLeft.getElement();
  // required data
  dataCacheDouble *boundaryTerm = boundaryCondition->newBoundaryTerm(cacheMapLeft);

  for (int iFace=0 ; iFace<group.getNbElements() ;++iFace) {
    // ----- 2.3.1 --- provide the data to the cacheMap
    solutionQPLeft.set(fullMatrix<double>(solutionQP, iFace*nbFields, nbFields));
    normals.set(group.getNormals(iFace));
    cacheElementLeft.set(group.getElementLeft(iFace));

    // ----- 2.3.2 --- compute fluxes
    fullMatrix<double> normalFluxQP (NormalFluxQP, iFace*nbFields, nbFields);
    for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
      const double detJ = group.getDetJ (iFace, iPt);
      for (int k=0;k<nbFields;k++)
        normalFluxQP(iPt,k) = (*boundaryTerm)(iPt,k)*detJ;
    }
  }
  // ----- 3 ---- do the redistribution at face nodes using BLAS3
  residual.gemm(group.getRedistributionMatrix(),NormalFluxQP);
  delete boundaryTerm;
}

void dgAlgorithm::buildGroups(GModel *model, int dim, int order,
    std::vector<dgGroupOfElements*> &eGroups,
    std::vector<dgGroupOfFaces*> &fGroups,
    std::vector<dgGroupOfFaces*> &bGroups) 
{
  std::map<const std::string,std::set<MEdge, Less_Edge> > boundaryEdges;
  std::map<const std::string,std::set<MFace, Less_Face> > boundaryFaces;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  std::vector<MElement *> allElements;
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *entity = entities[i];
    if(entity->dim() == dim-1){
      for(unsigned int j = 0; j < entity->physicals.size(); j++){
        const std::string physicalName = model->getPhysicalName(entity->dim(), entity->physicals[j]);
        for (int k = 0; k < entity->getNumMeshElements(); k++) {
          MElement *element = entity->getMeshElement(k);
          if(dim==2)
            boundaryEdges[physicalName].insert( MEdge(element->getVertex(0), element->getVertex(1)) );
          else
            boundaryFaces[physicalName].insert( MFace(element->getVertex(0), element->getVertex(1),element->getVertex(2)) );
        }
      }
    }else if(entity->dim() == dim){
      for (int iel=0; iel<entity->getNumMeshElements(); iel++)
        allElements.push_back(entity->getMeshElement(iel));
    }
  }
  eGroups.push_back(new dgGroupOfElements(allElements,order));
  fGroups.push_back(new dgGroupOfFaces(*eGroups[0],order));
  if(dim==2){
    std::map<const std::string, std::set<MEdge, Less_Edge> >::iterator mapIt;
    for(mapIt=boundaryEdges.begin(); mapIt!=boundaryEdges.end(); mapIt++) {
      bGroups.push_back(new dgGroupOfFaces(*eGroups[0],mapIt->first,order,mapIt->second));
    }
  }else if(dim=3){
    std::map<const std::string, std::set<MFace, Less_Face> >::iterator mapIt;
    for(mapIt=boundaryFaces.begin(); mapIt!=boundaryFaces.end(); mapIt++) {
      bGroups.push_back(new dgGroupOfFaces(*eGroups[0],mapIt->first,order,mapIt->second));
    }
  }else throw;
}

// works only if there is only 1 group of element
void dgAlgorithm::residual( const dgConservationLaw &claw,
    std::vector<dgGroupOfElements*> &eGroups, //group of elements
    std::vector<dgGroupOfFaces*> &fGroups,  // group of interfacs
    std::vector<dgGroupOfFaces*> &bGroups, // group of boundaries
    const fullMatrix<double> &solution, // solution
    fullMatrix<double> &residu) // residual
{
  dgAlgorithm algo;
  residu.scale(0);
  //volume term
  for(size_t i=0;i<eGroups.size() ; i++) {
    algo.residualVolume(claw,*eGroups[i],solution,residu);
  }
  //interface term
  for(size_t i=0;i<fGroups.size() ; i++) {
    dgGroupOfFaces &faces = *fGroups[i];
    fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*2);
    fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*2);
    faces.mapToInterface(1, solution, solution, solInterface);
    algo.residualInterface(claw,faces,solInterface,residuInterface);
    faces.mapFromInterface(1, residuInterface, residu, residu);
  }
  //boundaries
  for(size_t i=0;i<bGroups.size() ; i++) {
    dgGroupOfFaces &faces = *bGroups[i];
    fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements());
    fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements());
    faces.mapToInterface(1, solution, solution, solInterface);
    algo.residualBoundary(claw,faces,solInterface,residuInterface);
    faces.mapFromInterface(1, residuInterface, residu, residu);
  }
}
