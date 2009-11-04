#include "dgAlgorithm.h"

/*
  compute 
    \int \vec{f} \cdot \grad \phi dv   
*/

void dgAlgorithm::residualVolume ( dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const groupOfElements & group ) // the residual
{ 
  // ----- 1 ----  get the solution at quadrature points
  // ----- 1.1 --- allocate a matrix of size (nbFields * nbElements, nbQuadraturePoints) 
  fullMatrix<double> solutionQP (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints());
  // ----- 1.2 --- multiply the solution by the collocation matrix
  group.getSolution().mult ( group.getCollocationMatrix() , solutionQP); 
  // ----- 1.3 --- if the conservation law is diffusive, compute the gradients too
  fullMatrix<double> *gradientSolutionQP= 0;
  if (claw.diffusiveFlux()){
     gradientSolutionQP = new  fullMatrix<double> (group.getNbElements() * group.getNbFields() * 3, group.getNbIntegrationPoints());
     group.getGradientOfSolution().mult ( group.getCollocationMatrix() , solutionQP); 
  }
  

  // ----- 2 ----  compute all fluxes (diffusive and convective) at integration points
  // ----- 2.1 --- allocate elementary fluxes (compued in XYZ coordinates)
  fullMatrix<double> fConv[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() )};
  fullMatrix<double> fDiff[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() )};
  // ----- 2.2 --- allocate parametric fluxes (compued in UVW coordinates) for all elements at all integration points
  fullMatrix<double> Fuvw[3] = {fullMatrix<double> (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints()),
				fullMatrix<double> (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints()),
				fullMatrix<double> (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints())};
  // ----- 2.3 --- iterate on elements
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {        
    // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    fullMatrix<double> solutionQPe (solutionQP, iElement*claw.nbFields(),claw.nbFields() );
    fullMatrix<double> *gradSolutionQPe;
    if (claw.diffusiveFlux()) gradSolutionQPe = new fullMatrix<double>(*gradSolutionQP, 3*iElement*claw.nbFields(),3*claw.nbFields() );      
    else gradSolutionQPe = new fullMatrix<double>
    dgElement DGE( group.getElement(iElement), solutionQPe, *gradSolutionQPe, group.getIntegrationPointsMatrix());
    // ----- 2.3.2 --- compute fluxes in XYZ coordinates
    if (claw.convectiveFlux()) (*claw.convectiveFlux())(DGE,fConv);
    if (claw.diffusiveFlux()) (*claw.diffusiveFlux())(DGE,fDiff);
    
    // ----- 2.3.3 --- compute fluxes in UVW coordinates
    for (int iUVW=0;iUVW<group.getDimUVW();iUVW++) {
    // ----- 2.3.3.1 --- get a proxy on the big local flux matrix
      fullMatrix<double> fuvwe(Fuvw[iUVW], iElement*claw.nbFields(),claw.nbFields());
      // ----- 2.3.3.1 --- compute \vec{f}^{UVW} =\vec{f}^{XYZ} J^{-1} and multiply bt detJ
      for (int iXYZ=0;iXYZ<group.getDimXYZ();iXYZ++) {
	for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
	  // get the right inv jacobian matrix dU/dX element
	  const double invJ = group.getInvJ (iElement, iPt, iXYZ, iUVW);
	  // get the detJ at this point
	  const double detJ = group.getDetJ (iElement, iPt);
	  const double factor = invJ * detJ;
	  // compute fluxes in the reference coordinate system at this integration point
	  for (int k=0;k<group.nbFields();k++) {
	    fuvwe(iPt,k) += ( fConv[iXYZ](iPt,k) + fDiff[iXYZ](iPt,k)) * factor;
	  }
	}
      } 
    }
  }
  // ----- 3 ---- do the redistribution at nodes using as many BLAS3 operations as there are local coordinates
  for (int iUVW=0;iUVW<group.getDimUVW();iUVW++)
    group.getResidual().dgemm(group.getRedistributionMatrix(iUVW), Fuvw[iUVW]);
}
