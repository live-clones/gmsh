#include "dgAlgorithm.h"
#include "dgGroupOfElements.h"
#include "dgConservationLaw.h"

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
  // ----- 1.3 --- if the conservation law is diffusive, compute the gradients too
  fullMatrix<double> *gradientSolutionQP= 0;
  if (claw.diffusiveFlux()){
     gradientSolutionQP = new  fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * nbFields * 3);
     //group.getGradientOfSolution().mult ( group.getCollocationMatrix() , *gradientSolutionQP); 
  }
  
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
  fullMatrix<double> Fuvw[3] = {fullMatrix<double> (group.getNbElements() * nbFields, group.getNbIntegrationPoints()),
				fullMatrix<double> (group.getNbElements() * nbFields, group.getNbIntegrationPoints()),
				fullMatrix<double> (group.getNbElements() * nbFields, group.getNbIntegrationPoints())};
  // ----- 2.3 --- iterate on elements
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
    // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    fullMatrix<double> solutionQPe (solutionQP, iElement*nbFields, nbFields );
    fullMatrix<double> *gradSolutionQPe;
    if (claw.diffusiveFlux()) gradSolutionQPe = new fullMatrix<double>(*gradientSolutionQP, 3*iElement*nbFields,3*nbFields );      
    else gradSolutionQPe = new fullMatrix<double>;
    dgElement DGE( group.getElement(iElement), solutionQPe, *gradSolutionQPe, group.getIntegrationPointsMatrix());
    if(claw.convectiveFlux() || claw.diffusiveFlux()){
      // ----- 2.3.2 --- compute fluxes in XYZ coordinates
      if (claw.convectiveFlux()) (*claw.convectiveFlux())(DGE,fConv);
      if (claw.diffusiveFlux()) (*claw.diffusiveFlux())(DGE,fDiff);

      // ----- 2.3.3 --- compute fluxes in UVW coordinates
      for (int iUVW=0;iUVW<group.getDimUVW();iUVW++) {
        // ----- 2.3.3.1 --- get a proxy on the big local flux matrix
        fullMatrix<double> fuvwe(Fuvw[iUVW], iElement*nbFields,nbFields);
        // ----- 2.3.3.1 --- compute \vec{f}^{UVW} =\vec{f}^{XYZ} J^{-1} and multiply bt detJ
        for (int iXYZ=0;iXYZ<group.getDimXYZ();iXYZ++) {
          for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
            // get the right inv jacobian matrix dU/dX element
            const double invJ = group.getInvJ (iElement, iPt, iXYZ, iUVW);
            // get the detJ at this point
            const double detJ = group.getDetJ (iElement, iPt);
            const double factor = invJ * detJ;
            // compute fluxes in the reference coordinate system at this integration point
            for (int k=0;k<nbFields;k++) {
              fuvwe(iPt,k) += ( fConv[iXYZ](iPt,k) + fDiff[iXYZ](iPt,k)) * factor;
            }
          }
        } 
      }
    }
    if (claw.sourceTerm()){
      fullMatrix<double> source(Source, iElement*claw.nbFields(),claw.nbFields());
      (*claw.sourceTerm())(DGE,&source); 
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iElement, iPt);
        for (int k=0;k<nbFields;k++)
          source(iPt,k) *= detJ;
      }
    }
    delete gradSolutionQPe;
  }
  // ----- 3 ---- do the redistribution at nodes using as many BLAS3 operations as there are local coordinates
  if(claw.convectiveFlux() || claw.diffusiveFlux()){
    for (int iUVW=0;iUVW<group.getDimUVW();iUVW++)
      residual.gemm(group.getFluxRedistributionMatrix(iUVW),Fuvw[iUVW]);
  }
  if(claw.sourceTerm()){
    residual.gemm(group.getSourceRedistributionMatrix(),Source);
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
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * nbFields);
  group.getCollocationMatrix().mult(solution, solutionQP); 
  // ----- 2 ----  compute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP ( group.getNbIntegrationPoints(), group.getNbElements()*nbFields*2);
  for (int iFace=0 ; iFace<group.getNbElements() ;++iFace) {
    // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    fullMatrix<double> solutionQPLeft (solutionQP, iFace*2*nbFields, nbFields );
    fullMatrix<double> solutionQPRight (solutionQP, (iFace*2+1)*nbFields, nbFields );
    fullMatrix<double> normalFluxQP (NormalFluxQP, iFace*2*nbFields, nbFields*2);
    dgFace DGF( group.getFace(iFace), group.getElementLeft(iFace), group.getElementRight(iFace),
                solutionQPLeft, solutionQPRight, group.getIntegrationPointsMatrix());
    // ----- 2.3.2 --- compute fluxes
    (*claw.riemannSolver())(DGF,&normalFluxQP);
    for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
      const double detJ = group.getDetJ (iFace, iPt);
      for (int k=0;k<nbFields*2;k++) {
        normalFluxQP(iPt,k) *= detJ;
      }
    }
  }
  // ----- 3 ---- do the redistribution at face nodes using BLAS3
  residual.gemm(group.getRedistributionMatrix(),NormalFluxQP);
}

