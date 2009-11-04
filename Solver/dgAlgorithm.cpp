#include "dgAlgorithm.h"

/*
  compute 
    \int \vec{f} \cdot \grad \phi dv   
*/

void dgAlgorithm::residualVolume ( dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const groupOfElements & group ) // the residual
{ 
  // get the solution at quadrature points
  fullMatrix<double> solutionQp (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints());
  // solutionQp  ( NbE x NbFields , NbQuad)
  // collocation ( NbNod , NbQuad)
  // solution    ( NbE x NbFields, nbNodes)
  group.getSolution().mult ( group.getCollocationMatrix() , solutionQp); 
  
  // for all elements of the group,
  // compute all fluxes, both diffusive and convective, in reference coordinates
  fullMatrix<double> fConv[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() )};
  fullMatrix<double> fDiff[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() ),
				 fullMatrix<double>( group.getNbIntegrationPoints(), group.nbFields() )};
  fullMatrix<double> Fuvw[3] = {fullMatrix<double> (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints()),
				fullMatrix<double> (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints()),
				fullMatrix<double> (group.getNbElements() * group.getNbFields(), group.getNbIntegrationPoints())};
  // for all elements of the group
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {        
    dgElement DGE = group.getDGElement(iElement);
    // compute convective and diffusive fluxes in XYZ coordinates
    if (claw.convectiveFlux()) (*claw.convectiveFlux())(DGE,fConv);
    if (claw.diffusiveFlux()) (*claw.diffusiveFlux())(DGE,fDiff);
    
    for (int iUVW=0;iUVW<group.getDimUVW();iUVW++) {
      // proxy to the elementary values
      fullMatrix<double> fuvwe(Fuvw[iUVW], iElement*claw.nbFields(),claw.nbFields());
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
  // finally, premultiply with the redistribution matrices
  // this is the "heavy load" part
  for (int iUVW=0;iUVW<group.getDimUVW();iUVW++)
    group.getResidual().dgemm(group.getCollocationMatrix(iUVW), Fuvw[iUVW]);
}
