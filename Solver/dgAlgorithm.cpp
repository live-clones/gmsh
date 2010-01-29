#include <set>
#include "dgAlgorithm.h"
#include "dgGroupOfElements.h"
#include "dgSystemOfEquations.h"
#include "dgConservationLaw.h"
#include "GEntity.h"
#include "MElement.h"
#include "GModel.h"
#include "MEdge.h"
#include "function.h"
#include "dgLimiter.h"
#include "meshPartition.h"

/*
  compute 
    \int \vec{f} \cdot \grad \phi dv   
*/

void dgAlgorithm::residualVolume ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfElements & group, 
				   fullMatrix<double> &solution,
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
  dataCacheMap cacheMap(group.getNbIntegrationPoints());
  dataCacheElement &cacheElement = cacheMap.getElement();
  // provided dataCache
  cacheMap.provideData("UVW").set(group.getIntegrationPointsMatrix());
  dataCacheDouble &solutionQPe = cacheMap.provideData("Solution");
  dataCacheDouble &gradientSolutionQPe = cacheMap.provideData("SolutionGradient");
  gradientSolutionQPe.set(fullMatrix<double>(group.getNbIntegrationPoints()*3,nbFields));
  // needed dataCache
  dataCacheDouble *sourceTerm = claw.newSourceTerm(cacheMap);
    // fluxes in  XYZ coordinates;
  dataCacheDouble *convectiveFlux = claw.newConvectiveFlux(cacheMap);
  dataCacheDouble *diffusiveFlux = claw.newDiffusiveFlux(cacheMap);

  fullMatrix<double> fuvwe;
  fullMatrix<double> source;
  fullMatrix<double> dPsiDx,dofs;
  // ----- 2.3 --- iterate on elements
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
    // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    solutionQPe.setAsProxy(solutionQP, iElement*nbFields, nbFields );
    
    if(gradientSolutionQPe.somethingDependOnMe()){
      dPsiDx.setAsProxy(group.getDPsiDx(),iElement*group.getNbNodes(),group.getNbNodes());
      dofs.setAsProxy(solution, nbFields*iElement, nbFields);
      dPsiDx.mult(dofs, gradientSolutionQPe.set());
    }
    cacheElement.set(group.getElement(iElement));
    if(convectiveFlux || diffusiveFlux) {
      // ----- 2.3.3 --- compute fluxes in UVW coordinates
      for (int iUVW=0;iUVW<group.getDimUVW();iUVW++) {
        // ----- 2.3.3.1 --- get a proxy on the big local flux matrix
        fuvwe.setAsProxy(Fuvw[iUVW], iElement*nbFields,nbFields);
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
              if(diffusiveFlux){
		fuvwe(iPt,k) += ( (*diffusiveFlux)(iPt,iXYZ*nbFields+k)) * factor;
              }
            }
          }
        } 
      }
    }
    if (sourceTerm){
      source.setAsProxy(Source, iElement*claw.nbFields(),claw.nbFields());
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iElement, iPt);
        for (int k=0;k<nbFields;k++){
          source(iPt,k) = (*sourceTerm)(iPt,k)*detJ;
        }
      }
    }
  }
  // ----- 3 ---- do the redistribution at nodes using as many BLAS3 operations as there are local coordinates
  if(convectiveFlux || diffusiveFlux){
    for (int iUVW=0;iUVW<group.getDimUVW();iUVW++){
      residual.gemm(group.getFluxRedistributionMatrix(iUVW),Fuvw[iUVW]);
    }
  }
  if(sourceTerm){
    residual.gemm(group.getSourceRedistributionMatrix(),Source);
  }
}

void dgAlgorithm::residualInterface ( //dofManager &dof, // the DOF manager (maybe useless here)
				     const dgConservationLaw &claw,   // the conservation law
				     dgGroupOfFaces &group, 
				     const fullMatrix<double> &solution, // solution !! at faces nodes
				     fullMatrix<double> &solutionLeft, 
				     fullMatrix<double> &solutionRight, 
				     fullMatrix<double> &residual // residual !! at faces nodes
				      )
{ 
  // A) global operations before entering the loop over the faces
  // A1 ) copy locally some references from the group for the sake of lisibility
  int nbFields = claw.nbFields();
  int nbNodesLeft = group.getGroupLeft().getNbNodes();
  int nbNodesRight = group.getGroupRight().getNbNodes();
  int nbFaces = group.getNbElements();
  //get matrices needed to compute the gradient on both sides
  fullMatrix<double> &DPsiLeftDx = group.getDPsiLeftDxMatrix();
  fullMatrix<double> &DPsiRightDx = group.getDPsiRightDxMatrix();

  // ----- 1 ----  get the solution at quadrature points
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),nbFaces * nbFields*2);
  group.getCollocationMatrix().mult(solution, solutionQP); 
  // needed tocompute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP ( group.getNbIntegrationPoints(), nbFaces*nbFields*2);

  // create one dataCache for each side
  dataCacheMap cacheMapLeft(group.getNbIntegrationPoints());
  dataCacheMap cacheMapRight(group.getNbIntegrationPoints());

  // data this algorithm provide to the cache map (we can maybe move each data to a separate function but
  // I think It's easier like this)
  dataCacheDouble &normals = cacheMapLeft.provideData("Normals");
  dataCacheElement &cacheElementLeft = cacheMapLeft.getElement();
  dataCacheElement &cacheElementRight = cacheMapRight.getElement();
  dataCacheDouble &uvwLeft = cacheMapLeft.provideData("UVW");
  dataCacheDouble &uvwRight = cacheMapRight.provideData("UVW");
  dataCacheDouble &solutionQPLeft = cacheMapLeft.provideData("Solution");
  dataCacheDouble &solutionQPRight = cacheMapRight.provideData("Solution");
  dataCacheDouble &gradientSolutionLeft = cacheMapLeft.provideData("SolutionGradient");
  dataCacheDouble &gradientSolutionRight = cacheMapRight.provideData("SolutionGradient");
  //resize gradientSolutionLeft and Right
  gradientSolutionLeft.set(fullMatrix<double>(group.getNbIntegrationPoints()*3,nbFields));
  gradientSolutionRight.set(fullMatrix<double>(group.getNbIntegrationPoints()*3,nbFields));

  // A2 ) ask the law to provide the fluxes (possibly NULL)
  dataCacheDouble *riemannSolver = claw.newRiemannSolver(cacheMapLeft,cacheMapRight);
  dataCacheDouble *diffusiveFluxLeft = claw.newDiffusiveFlux(cacheMapLeft);
  dataCacheDouble *maximumDiffusivityLeft = claw.newMaximumDiffusivity(cacheMapLeft);
  dataCacheDouble *maximumDiffusivityRight = claw.newMaximumDiffusivity(cacheMapRight);
  dataCacheDouble *diffusiveFluxRight = claw.newDiffusiveFlux(cacheMapRight);
  fullMatrix<double> dPsiLeftDx,dPsiRightDx,dofsLeft,dofsRight,normalFluxQP;

  int p = group.getGroupLeft().getOrder();
  int dim = group.getGroupLeft().getElement(0)->getDim();

  for (int iFace=0 ; iFace < nbFaces ; ++iFace) {
    // B1 )  adjust the proxies for this element
    //      NB  : the B1 section will almost completely disapear 
    //      if we write a function (from the function class) for moving proxies across big matrices
    // give the current elements to the dataCacheMap 
    cacheElementLeft.set(group.getElementLeft(iFace));
    cacheElementRight.set(group.getElementRight(iFace));
    // proxies for the solution
    solutionQPLeft.setAsProxy(solutionQP, iFace*2*nbFields, nbFields);
    solutionQPRight.setAsProxy(solutionQP, (iFace*2+1)*nbFields, nbFields);
    normals.setAsProxy(group.getNormals(), iFace*group.getNbIntegrationPoints(),group.getNbIntegrationPoints());
    // proxies needed to compute the gradient of the solution and the IP term
    dPsiLeftDx.setAsProxy(DPsiLeftDx,iFace*nbNodesLeft,nbNodesLeft);
    dPsiRightDx.setAsProxy(DPsiRightDx,iFace*nbNodesRight,nbNodesRight);
    dofsLeft.setAsProxy(solutionLeft, nbFields*group.getElementLeftId(iFace), nbFields);
    dofsRight.setAsProxy(solutionRight, nbFields*group.getElementRightId(iFace), nbFields);
    uvwLeft.setAsProxy(group.getIntegrationOnElementLeft(iFace));
    uvwRight.setAsProxy(group.getIntegrationOnElementRight(iFace));
    // proxies for the flux
    normalFluxQP.setAsProxy(NormalFluxQP, iFace*nbFields*2, nbFields*2);

    // B2 ) compute the gradient of the solution
    if(gradientSolutionLeft.somethingDependOnMe()){
      dPsiLeftDx.mult(dofsLeft, gradientSolutionLeft.set());
      dPsiRightDx.mult(dofsRight, gradientSolutionRight.set());
    }

    // B3 ) compute fluxes    
    if (diffusiveFluxLeft) {
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iFace, iPt);
        //just for the lisibility :
        const fullMatrix<double> &dfl = (*diffusiveFluxLeft)();
        const fullMatrix<double> &dfr = (*diffusiveFluxRight)();
        for (int k=0;k<nbFields;k++) { 
          double meanNormalFlux =
              ((dfl(iPt,k+nbFields*0 )+dfr(iPt,k+nbFields*0)) * normals(0,iPt)
              +(dfl(iPt,k+nbFields*1 )+dfr(iPt,k+nbFields*1)) * normals(1,iPt)
              +(dfl(iPt,k+nbFields*2 )+dfr(iPt,k+nbFields*2)) * normals(2,iPt))/2;
          double minl = std::min(group.getElementVolumeLeft(iFace),
                                 group.getElementVolumeRight(iFace)
                                )/group.getInterfaceSurface(iFace);
          double nu = std::max((*maximumDiffusivityRight)(iPt,0),(*maximumDiffusivityLeft)(iPt,0));
          double mu = (p+1)*(p+dim)/dim*nu/minl;
          double solutionJumpPenalty = (solutionQPLeft(iPt,k)-solutionQPRight(iPt,k))/2*mu;
          normalFluxQP(iPt,k) -= (meanNormalFlux+solutionJumpPenalty)*detJ;
          normalFluxQP(iPt,k+nbFields) += (meanNormalFlux+solutionJumpPenalty)*detJ;
        }
      }
    }
    if (riemannSolver) {
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iFace, iPt);
        for (int k=0;k<nbFields*2;k++)
          normalFluxQP(iPt,k) += (*riemannSolver)(iPt,k)*detJ;
      }
    }
  }

  // C ) redistribute the flux to the residual (at Faces nodes)

  if(riemannSolver || diffusiveFluxLeft)
    residual.gemm(group.getRedistributionMatrix(),NormalFluxQP);
}

void dgAlgorithm::multAddInverseMassMatrix ( /*dofManager &dof,*/
					    const dgGroupOfElements & group,
					    fullMatrix<double> &residu,
					    fullMatrix<double> &sol)
{
  fullMatrix<double> residuEl;
  fullMatrix<double> solEl;
  fullMatrix<double> iMassEl;
  int nFields=sol.size2()/group.getNbElements();
  for(int i=0;i<group.getNbElements();i++) {
    residuEl.setAsProxy(residu,i*nFields,nFields);
    solEl.setAsProxy(sol,i*nFields,nFields);
    iMassEl.setAsProxy(group.getInverseMassMatrix(),i*group.getNbNodes(),group.getNbNodes());
    solEl.gemm(iMassEl,residuEl);
  }
}


void dgAlgorithm::rungeKutta (const dgConservationLaw &claw,			// conservation law
            dgGroupCollection &groups,
			      double h,				         // time-step
			      dgDofContainer &sol,
			      dgDofContainer &resd,
			      dgLimiter *limiter,
			      int orderRK
            )				        // order of RK integrator
{

  // U_{n+1}=U_n+h*(SUM_i a_i*K_i)
  // K_i=M^(-1)R(U_n+b_i*K_{i-1})

  double a[4] = {h/6.0,h/3.0,h/3.0,h/6.0};
  double b[4] = {0.,h/2.0,h/2.0,h};

  if (orderRK == 1){
    a[0] = h;
  }

  // Current updated solution
  fullMatrix<double> residuEl, KEl;
  fullMatrix<double> iMassEl;

  int nbFields = claw.nbFields();

  dgDofContainer K   (groups,nbFields);
  dgDofContainer Unp (groups,nbFields);
  K.scale(0.);
  K.axpy(sol);
  Unp.scale(0.);
  Unp.axpy(sol);

  for(int j=0; j<orderRK;j++){
    if(j){
      K.scale(b[j]);
      K.axpy(sol);
    }

    if (limiter){
      limiter->apply(K, groups);
    }
    this->residual(claw,groups,K,resd);
    K.scale(0.);
    for(int k=0; k < groups.getNbElementGroups(); k++) {
      dgGroupOfElements *group = groups.getElementGroup(k);
      int nbNodes = group->getNbNodes();
      for(int i=0;i<group->getNbElements();i++) {
        residuEl.setAsProxy(resd.getGroupProxy(k),i*nbFields,nbFields);
        KEl.setAsProxy(K.getGroupProxy(k),i*nbFields,nbFields);
        iMassEl.setAsProxy(group->getInverseMassMatrix(),i*nbNodes,nbNodes);
        iMassEl.mult(residuEl,KEl);
      }
    }
    Unp.axpy(K,a[j]);
  }
  if (limiter) limiter->apply(Unp, groups);
  sol.scale(0.);
  sol.axpy(Unp);
}

void dgAlgorithm::multirateRungeKutta (const dgConservationLaw &claw,			// conservation law
            dgGroupCollection &groups,
			      double h,				        // time-step
			      dgDofContainer &sol,
			      dgDofContainer &resd,			       
			      int orderRK)				        // order of RK integrator
 {

   // U_{n+1}=U_n+h*(SUM_i a_i*K_i)
   // K_i=M^(-1)R(U_n+b_i*K_{i-1})
   
   int nStages=10;
//  classical RK44
//   double A[4][4]={
//      {0, 0, 0, 0},
//      {1.0/2.0, 0, 0 ,0},
//      {0, 1.0/2.0, 0, 0},
//      {0, 0, 1, 0}
//   };
//   double b[4]={1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
//   double c[4]={0, 1.0/2.0, 1.0/2.0, 1};

// 3/8 RK44
//   double A[4][4]={
//      {0, 0, 0, 0},
//      {1.0/3.0, 0, 0 ,0},
//      {-1.0/3.0, 1.0, 0, 0},
//      {1, -1, 1, 0}
//   };
//   double b[4]={1.0/8.0, 3.0/8.0, 3.0/8.0, 1.0/8.0};
//   double c[4]={0, 1.0/3.0, 2.0/3.0, 1};

// RK43 from Schlegel et al. JCAM 2009
//   double A[4][4]={
//      {0, 0, 0, 0},
//      {1.0/2.0, 0, 0 ,0},
//      {-1.0/6.0, 2.0/3.0, 0, 0},
//      {1.0/3.0, -1.0/3.0, 1, 0}
//   };
//   double b[4]={1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
//   double c[4]={0, 1.0/2.0, 1.0/2.0, 1};
   
	 double A[10][10];
	 double *b;
	 double *c;
// Small step RK43
   double A1[10][10]={
{0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
{1.0/4.0   ,0,         0,         0,         0,         0,         0,         0,         0,         0},
{-1.0/12.0, 1.0/3.0,   0,         0,         0,         0,         0,         0,         0,         0},
{1.0/6.0,   -1.0/6.0,  1.0/2.0,   0,         0,         0,         0,         0,         0,         0},
{1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         0,         0,         0,         0,         0},
{1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         0,         0,         0,         0,         0},
{1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/4.0,   0,         0,         0,         0},
{1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         -1.0/12.0, 1.0/3.0,   0,         0,         0},
{1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/6.0,   -1.0/6.0,  1.0/2.0,   0,         0},
{1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0,  0,         1.0/12.0,  1.0/6.0,   1.0/6.0,   1.0/12.0, 0}
   };
   double b1[10]={1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0,1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0};
   double c1[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };

// Big step RK43
   double A2[10][10]={
{0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
{1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
{1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
{1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
{1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
{-1.0/6.0,  0,         0,         0,         2.0/3.0,   0,         0,         0,         0,         0},
{1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
{1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
{1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
{1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
   };
   double b2[10]={1.0/6.0, 0 , 0 , 0 , 1.0/3.0,1.0/3.0, 0 , 0 , 0 , 1.0/6.0};
   double c2[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };


   // fullMatrix<double> K(sol);
   // Current updated solution
   // fullMatrix<double> Unp(sol);
   fullMatrix<double> residuEl, KEl;
   fullMatrix<double> iMassEl;
   
   int nbFields = claw.nbFields();
   
   dgDofContainer **K;
   K=new dgDofContainer*[nStages];
   for(int i=0;i<nStages;i++){
     K[i]=new dgDofContainer(groups,nbFields);
     K[i]->scale(0.);
   }
   dgDofContainer Unp (groups,nbFields);
   dgDofContainer tmp (groups,nbFields);

   Unp.scale(0.0);
   Unp.axpy(sol);
   // Case of 2 groups: first with big steps, second with small steps	 
   for(int j=0; j<nStages;j++){
     tmp.scale(0.0);
     tmp.axpy(sol);
     for(int k=0;k < groups.getNbElementGroups();k++) {
		 if (k==0) {
			 for (int ii=0; ii<10; ii++) {
				 for (int jj=0; jj<10; jj++) {
					 A[ii][jj]=A2[ii][jj];
				 }
			 }
		 }
		 else{
			 for (int ii=0; ii<10; ii++) {
				 for (int jj=0; jj<10; jj++) {
					 A[ii][jj]=A1[ii][jj];
				 }
			 }
		 }
       for(int i=0;i<j;i++){
         if(fabs(A[j][i])>1e-12){
           tmp.getGroupProxy(k).add(K[i]->getGroupProxy(k),h*A[j][i]);
         }
       }
     }
     this->residual(claw,groups,tmp,resd);
     for(int k=0;k < groups.getNbElementGroups(); k++) {
		 if (k==0) {
			 b=b2;
			 c=c2;
		 }
		 else{
			 b=b1;
			 c=c1;
		 }
		 
       dgGroupOfElements *group = groups.getElementGroup(k);
       int nbNodes = group->getNbNodes();
       for(int i=0;i<group->getNbElements();i++) {
         residuEl.setAsProxy(resd.getGroupProxy(k),i*nbFields,nbFields);
         KEl.setAsProxy(K[j]->getGroupProxy(k),i*nbFields,nbFields);
         iMassEl.setAsProxy(group->getInverseMassMatrix(),i*nbNodes,nbNodes);
         iMassEl.mult(residuEl,KEl);
       }
       Unp.getGroupProxy(k).add(K[j]->getGroupProxy(k),h*b[j]);
     }
   }
   sol.scale(0.);
   sol.axpy(Unp);

   for(int i=0;i<nStages;i++){
     delete K[i];
   }
   delete []K;
 }

void dgAlgorithm::residualBoundary ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   dgGroupOfFaces &group, 
				   const fullMatrix<double> &solution, // solution !! at faces nodes
				   fullMatrix<double> &solutionLeft, 
				   fullMatrix<double> &residual // residual !! at faces nodes
				     )
{ 
  int nbFields = claw.nbFields();
  int nbNodesLeft = group.getGroupLeft().getNbNodes();
  const dgBoundaryCondition *boundaryCondition = claw.getBoundaryCondition(group.getBoundaryTag());
  // ----- 1 ----  get the solution at quadrature points
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * nbFields);
  group.getCollocationMatrix().mult(solution, solutionQP); 
  // ----- 2 ----  compute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP ( group.getNbIntegrationPoints(), group.getNbElements()*nbFields);

  dataCacheMap cacheMapLeft(group.getNbIntegrationPoints());
  fullMatrix<double> &DPsiLeftDx = group.getDPsiLeftDxMatrix();
  // provided dataCache
  dataCacheDouble &uvw=cacheMapLeft.provideData("UVW");
  dataCacheDouble &solutionQPLeft = cacheMapLeft.provideData("Solution");
  dataCacheDouble &gradientSolutionLeft = cacheMapLeft.provideData("SolutionGradient");
  dataCacheDouble &normals = cacheMapLeft.provideData("Normals");
  dataCacheElement &cacheElementLeft = cacheMapLeft.getElement();
  gradientSolutionLeft.set(fullMatrix<double>(group.getNbIntegrationPoints()*3,nbFields));
  // required data
  // inviscid
  dataCacheDouble *boundaryTerm = boundaryCondition->newBoundaryTerm(cacheMapLeft);
  // viscous
  dataCacheDouble *diffusiveFluxLeft = claw.newDiffusiveFlux(cacheMapLeft);
  dataCacheDouble *maximumDiffusivityLeft = claw.newMaximumDiffusivity(cacheMapLeft);
  dataCacheDouble *neumann   = boundaryCondition->newDiffusiveNeumannBC(cacheMapLeft);
  dataCacheDouble *dirichlet = boundaryCondition->newDiffusiveDirichletBC(cacheMapLeft);

  fullMatrix<double> normalFluxQP,dPsiLeftDx,dofsLeft;

  int p = group.getGroupLeft().getOrder();
  int dim = group.getGroupLeft().getElement(0)->getDim();

  for (int iFace=0 ; iFace<group.getNbElements() ;++iFace) {
    normalFluxQP.setAsProxy(NormalFluxQP, iFace*nbFields, nbFields);
    // ----- 2.3.1 --- provide the data to the cacheMap
    solutionQPLeft.setAsProxy(solutionQP, iFace*nbFields, nbFields);
    normals.setAsProxy(group.getNormals(),iFace*group.getNbIntegrationPoints(),group.getNbIntegrationPoints());
    // proxies needed to compute the gradient of the solution and the IP term
    dPsiLeftDx.setAsProxy(DPsiLeftDx,iFace*nbNodesLeft,nbNodesLeft);
    dofsLeft.setAsProxy(solutionLeft, nbFields*group.getElementLeftId(iFace), nbFields);

    uvw.setAsProxy(group.getIntegrationOnElementLeft(iFace));
    cacheElementLeft.set(group.getElementLeft(iFace));

    // compute the gradient of the solution
    if(gradientSolutionLeft.somethingDependOnMe()){
      dPsiLeftDx.mult(dofsLeft, gradientSolutionLeft.set());
    }

    // ----- 2.3.2 --- compute inviscid contribution
    for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
      const double detJ = group.getDetJ (iFace, iPt);
      for (int k=0;k<nbFields;k++)
        normalFluxQP(iPt,k) = (*boundaryTerm)(iPt,k)*detJ;
    }

    // ----- 2.3.3 --- compute viscous contribution
    if (diffusiveFluxLeft) {
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iFace, iPt);
        //just for the lisibility :
        for (int k=0;k<nbFields;k++) { 
          double minl = group.getElementVolumeLeft(iFace)/group.getInterfaceSurface(iFace);
          double nu = (*maximumDiffusivityLeft)(iPt,0);
	  double mu = (p+1)*(p+dim)/dim*nu/minl;
          double solutionJumpPenalty = (solutionQPLeft(iPt,k)-(*dirichlet)(iPt,k))/2*mu;
          normalFluxQP(iPt,k) -= ((*neumann)(iPt,k)+solutionJumpPenalty)*detJ;
        }
      }
    }    

  }
  // ----- 3 ---- do the redistribution at face nodes using BLAS3
  residual.gemm(group.getRedistributionMatrix(),NormalFluxQP);
}

// works for any number of groups 
void dgAlgorithm::residual( const dgConservationLaw &claw,
          dgGroupCollection &groups,
          dgDofContainer &solution,
          dgDofContainer &residu)
{
  solution.scatter();
  int nbFields=claw.nbFields();
  //volume term
  for(size_t i=0;i<groups.getNbElementGroups() ; i++) {
    residu.getGroupProxy(i).scale(0);
    residualVolume(claw,*groups.getElementGroup(i),solution.getGroupProxy(i),residu.getGroupProxy(i));
  }
  //  residu[0]->print("Volume");
  //interface term
  for(size_t i=0;i<groups.getNbFaceGroups() ; i++) {
    dgGroupOfFaces &faces = *groups.getFaceGroup(i);
    int iGroupLeft = -1, iGroupRight = -1;
    for(size_t j=0;j<groups.getNbElementGroups(); j++) {
      dgGroupOfElements *groupj = groups.getElementGroup(j);
      if (groupj == &faces.getGroupLeft()) iGroupLeft = j;
      if (groupj == &faces.getGroupRight()) iGroupRight= j;
    }
    for(size_t j=0;j<groups.getNbGhostGroups(); j++) {
      dgGroupOfElements *groupj = groups.getGhostGroup(j);
      if (groupj == &faces.getGroupLeft()) iGroupLeft = j;
      if (groupj == &faces.getGroupLeft())iGroupLeft = j + groups.getNbElementGroups();
      if (groupj == &faces.getGroupRight())iGroupRight= j + groups.getNbElementGroups();
    }
    fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*2*nbFields);
    fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*2*nbFields);
    faces.mapToInterface(nbFields, solution.getGroupProxy(iGroupLeft), solution.getGroupProxy(iGroupRight), solInterface);
    residualInterface(claw,faces,solInterface,solution.getGroupProxy(iGroupLeft), solution.getGroupProxy(iGroupRight),residuInterface);
    faces.mapFromInterface(nbFields, residuInterface,residu.getGroupProxy(iGroupLeft), residu.getGroupProxy(iGroupRight));
  }
  //boundaries
  for(size_t i=0;i<groups.getNbBoundaryGroups() ; i++) {
    dgGroupOfFaces &faces = *groups.getBoundaryGroup(i);
    int iGroupLeft = -1, iGroupRight = -1;
    for(size_t j=0;j<groups.getNbElementGroups(); j++) {
      dgGroupOfElements *groupj = groups.getElementGroup(j);
      if (groupj == &faces.getGroupLeft())iGroupLeft = j;
      if (groupj == &faces.getGroupRight())iGroupRight= j;
    }
    fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*nbFields);
    fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*nbFields);
    faces.mapToInterface(nbFields, solution.getGroupProxy(iGroupLeft), solution.getGroupProxy(iGroupRight), solInterface);
    residualBoundary(claw,faces,solInterface,solution.getGroupProxy(iGroupLeft),residuInterface);
    faces.mapFromInterface(nbFields, residuInterface, residu.getGroupProxy(iGroupLeft), residu.getGroupProxy(iGroupRight));
  }
}

void dgAlgorithm::computeElementaryTimeSteps ( //dofManager &dof, // the DOF manager (maybe useless here)
					      const dgConservationLaw &claw,   // the conservation law
					      const dgGroupOfElements & group, 
					      fullMatrix<double> &solution,
					      std::vector<double> & DT
					       )
{ 
  dataCacheMap cacheMap(group.getNbNodes());
  dataCacheDouble &sol = cacheMap.provideData("Solution");
  dataCacheElement &cacheElement = cacheMap.getElement();
  // provided dataCache
  dataCacheDouble *maxConvectiveSpeed = claw.newMaxConvectiveSpeed(cacheMap);
  dataCacheDouble *maximumDiffusivity = claw.newMaximumDiffusivity(cacheMap);
	
  const int nbFields = claw.nbFields();
  /* This is an estimate on how lengths changes with p 
     It is merely the smallest distance between gauss 
     points at order p + 1 */
  const double p   = group.getOrder();
  const double Cip = 3 * (p + 1) * (p + group.getDimUVW()) ;
  double l_red = 1./3.*p*p +7./6.*p +1.0;
  double l_red_sq = l_red*l_red;
  DT.resize(group.getNbElements());
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
    sol.setAsProxy(solution, iElement*nbFields, nbFields);
    MElement *e = group.getElement(iElement);
    cacheElement.set(e);
    const double L = e->minEdge();
    double spectralRadius = 0.0;
    if (maximumDiffusivity){
      double nu = (*maximumDiffusivity)(0,0);
      for (int k=1;k<group.getNbNodes();k++) nu = std::max((*maximumDiffusivity)(k,0), nu);
      spectralRadius +=  group.getDimUVW()*nu/(L*L)*std::max(l_red_sq,6.*l_red*Cip);
      spectralRadius +=  4.0*nu*l_red*Cip/(L*L);
    }
    if (maxConvectiveSpeed){
      double c = (*maxConvectiveSpeed)(0,0);
      for (int k=1;k<group.getNbNodes();k++) c = std::max((*maxConvectiveSpeed)(k,0), c);
      spectralRadius += 4.0*c*l_red/L; 
    }
    DT[iElement] = 1./spectralRadius;
  }
}
