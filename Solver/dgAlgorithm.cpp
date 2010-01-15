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
			      std::vector<dgGroupOfElements*> &eGroups,	// group of elements
			      std::vector<dgGroupOfFaces*> &fGroups,		// group of interfacs
			      std::vector<dgGroupOfFaces*> &bGroups,		// group of boundaries
            std::vector<dgGroupOfElements*> &ghostGroups, // group of boundaries
			      double h,				         // time-step
			      dgDofContainer &sol,
			      dgDofContainer &resd,
            dgSystemOfEquations *syst,
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
   
   dgDofContainer K   (eGroups,ghostGroups,claw);
   dgDofContainer Unp (eGroups,ghostGroups,claw);
   
   K._data->scale(0.0);
   K._data->axpy(*(sol._data));
   Unp._data->scale(0.0);
   Unp._data->axpy(*(sol._data));
   
   for(int j=0; j<orderRK;j++){
     if(j){
       K._data->scale(b[j]);
       K._data->axpy(*(sol._data));
     }
     
    if (limiter){
      limiter->apply(K, eGroups, fGroups);
    }
    syst->scatter(&K);
     this->residual(claw,eGroups,fGroups,bGroups,ghostGroups,K._dataProxys,resd._dataProxys);
     K._data->scale(0.);
     for(int k=0;k < eGroups.size();k++) {
       int nbNodes = eGroups[k]->getNbNodes();
       for(int i=0;i<eGroups[k]->getNbElements();i++) {
	 residuEl.setAsProxy(*(resd._dataProxys[k]),i*nbFields,nbFields);
	 KEl.setAsProxy(*(K._dataProxys[k]),i*nbFields,nbFields);
	 iMassEl.setAsProxy(eGroups[k]->getInverseMassMatrix(),i*nbNodes,nbNodes);
	 iMassEl.mult(residuEl,KEl);
       }
     }
     Unp._data->axpy(*(K._data),a[j]);
   }
   if (limiter) limiter->apply(Unp, eGroups, fGroups);
   for (int i=0;i<sol._dataSize;i++){	   
     (*sol._data)(i)=(*Unp._data)(i);
   }
 }



void dgAlgorithm::multirateRungeKutta (const dgConservationLaw &claw,			// conservation law
			      std::vector<dgGroupOfElements*> &eGroups,	// group of elements
			      std::vector<dgGroupOfFaces*> &fGroups,		// group of interfacs
			      std::vector<dgGroupOfFaces*> &bGroups,		// group of boundaries
			    std::vector<dgGroupOfElements*> &ghostGroups, // group of boundaries
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
   

// Small step RK43
   double A[10][10]={
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
   double b[10]={1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0,1.0/12.0, 1.0/6.0, 1.0/6.0,1.0/12.0,0};
   double c[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };

// Big step RK43
//   double A[10][10]={
//{0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
//{1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
//{1.0/4.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
//{1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
//{1.0/2.0 ,  0,         0,         0,         0,         0,         0,         0,         0,         0},
//{-1.0/6.0,  0,         0,         0,         2.0/3.0,   0,         0,         0,         0,         0},
//{1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
//{1.0/12.0,  0,         0,         0,         1.0/6.0,   1.0/2.0,   0,         0,         0,         0},
//{1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
//{1.0/3.0 ,  0,         0,         0,         -1.0/3.0,  1,         0,         0,         0,         0},
//   };
//   double b[10]={1.0/6.0, 0 , 0 , 0 , 1.0/3.0,1.0/3.0, 0 , 0 , 0 , 1.0/6.0};
//   double c[10]={0, 1.0/4.0, 1.0/4.0, 1.0/2.0, 1.0/2.0, 1.0/2.0, 3.0/4.0, 3.0/4.0, 1, 1 };


   // fullMatrix<double> K(sol);
   // Current updated solution
   // fullMatrix<double> Unp(sol);
   fullMatrix<double> residuEl, KEl;
   fullMatrix<double> iMassEl;
   
   int nbFields = claw.nbFields();
   
   dgDofContainer **K;
   K=new dgDofContainer*[nStages];
   for(int i=0;i<nStages;i++){
     K[i]=new dgDofContainer(eGroups,claw);
     K[i]->_data->scale(0.0);
   }
   dgDofContainer Unp (eGroups,claw);
   dgDofContainer tmp (eGroups,claw);

   Unp._data->scale(0.0);
   Unp._data->axpy(*(sol._data));

   for(int j=0; j<nStages;j++){
     tmp._data->scale(0.0);
     tmp._data->axpy(*(sol._data));
     for(int k=0;k < eGroups.size();k++) {
       for(int i=0;i<j;i++){
         if(fabs(A[j][i])>1e-12){
           tmp.getGroupProxy(k).add(K[i]->getGroupProxy(k),h*A[j][i]);
         }
       }
     }
     this->residual(claw,eGroups,fGroups,bGroups,ghostGroups,tmp._dataProxys,resd._dataProxys);
     for(int k=0;k < eGroups.size();k++) {
       int nbNodes = eGroups[k]->getNbNodes();
       for(int i=0;i<eGroups[k]->getNbElements();i++) {
         residuEl.setAsProxy(*(resd._dataProxys[k]),i*nbFields,nbFields);
         KEl.setAsProxy(*(K[j]->_dataProxys[k]),i*nbFields,nbFields);
         iMassEl.setAsProxy(eGroups[k]->getInverseMassMatrix(),i*nbNodes,nbNodes);
         iMassEl.mult(residuEl,KEl);
       }
       Unp.getGroupProxy(k).add(K[j]->getGroupProxy(k),h*b[j]);
     }
   }
   
   for (int i=0;i<sol._dataSize;i++){
     (*sol._data)(i)=(*Unp._data)(i);
   }
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

/*
void dgAlgorithm::buildGroupsOfFaces(GModel *model, int dim, int order,
				     std::vector<dgGroupOfElements*> &eGroups,
				     std::vector<dgGroupOfFaces*> &fGroups,
				     std::vector<dgGroupOfFaces*> &bGroups){
}

void dgAlgorithm::buildMandatoryGroups(dgGroupOfElements &eGroup,
				       std::vector<dgGroupOfElements*> &partitionedGroups){
}

void dgAlgorithm::partitionGroup(dgGroupOfElements &eGroup,
				 std::vector<dgGroupOfElements*> &partitionedGroups){
}
*/

//static void partitionGroup (std::vector<MElement *>,){
//}

// this function creates groups of elements
// First, groups of faces are created on every physical group
// of dimension equal to the dimension of the problem minus one
// Then, groups of elements are created 
//  -) Elements of different types are separated
//  -) Then those groups are split into partitions
//  -) Finally, those groups are re-numbered 
// Finally, group of interfaces are created
//  -) Groups of faces internal to a given group
//  -) Groups of faces between groups.
 
void dgAlgorithm::buildGroups(GModel *model, int dim, int order,
    std::vector<dgGroupOfElements*> &eGroups,
    std::vector<dgGroupOfFaces*> &fGroups,
    std::vector<dgGroupOfFaces*> &bGroups,
    std::vector<dgGroupOfElements*> &ghostGroups
    ) 
{
  std::map<const std::string,std::set<MVertex*> > boundaryVertices;
  std::map<const std::string,std::set<MEdge, Less_Edge> > boundaryEdges;
  std::map<const std::string,std::set<MFace, Less_Face> > boundaryFaces;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  std::map<int, std::vector<MElement *> >localElements;
  std::vector<std::map<int, std::vector<MElement *> > >ghostElements(Msg::GetCommSize()); // [partition][elementType]
  int nlocal=0;
  int nghosts=0;
  std::multimap<MElement*, short> &ghostsCells = model->getGhostCells();
  for(unsigned int i = 0; i < entities.size(); i++){
    GEntity *entity = entities[i];
    if(entity->dim() == dim-1){
      for(unsigned int j = 0; j < entity->physicals.size(); j++){
        const std::string physicalName = model->getPhysicalName(entity->dim(), entity->physicals[j]);
        for (int k = 0; k < entity->getNumMeshElements(); k++) {
          MElement *element = entity->getMeshElement(k);
          switch(dim) {
            case 1:
              boundaryVertices[physicalName].insert( element->getVertex(0) ); 
              break;
            case 2:
              boundaryEdges[physicalName].insert( element->getEdge(0) );
            break;
            case 3:
              boundaryFaces[physicalName].insert( element->getFace(0));
            break;
            default :
            throw;
          }
        }
      }
    }else if(entity->dim() == dim){
      for (int iel=0; iel<entity->getNumMeshElements(); iel++){
        MElement *el=entity->getMeshElement(iel);
        if(el->getPartition()==Msg::GetCommRank()+1 || el->getPartition()==0){
          localElements[el->getType()].push_back(el);
          nlocal++;
        }else{
          std::multimap<MElement*, short>::iterator ghost=ghostsCells.lower_bound(el);
          while(ghost!= ghostsCells.end() && ghost->first==el){
            nghosts+=(abs(ghost->second)-1==Msg::GetCommRank());
            ghostElements[el->getPartition()-1][el->getType()].push_back(el);
            ghost++;
          }
        }
      }
    }
  }


  Msg::Info("%d groups of elements",localElements.size());
  // do a group of elements for every element type in the mesh
  for (std::map<int, std::vector<MElement *> >::iterator it = localElements.begin(); it !=localElements.end() ; ++it){
    eGroups.push_back(new dgGroupOfElements(it->second,order));
  }


  for (int i=0;i<eGroups.size();i++){
    // create a group of faces on the boundary for every group ef elements
    switch(dim) {
    case 1 : {
      std::map<const std::string, std::set<MVertex*> >::iterator mapIt;
      for(mapIt=boundaryVertices.begin(); mapIt!=boundaryVertices.end(); mapIt++) {
        bGroups.push_back(new dgGroupOfFaces(*eGroups[i],mapIt->first,order,mapIt->second));
      }
      break;
    }
    case 2 : {
      std::map<const std::string, std::set<MEdge, Less_Edge> >::iterator mapIt;
      for(mapIt=boundaryEdges.begin(); mapIt!=boundaryEdges.end(); mapIt++) {
        bGroups.push_back(new dgGroupOfFaces(*eGroups[i],mapIt->first,order,mapIt->second));
      }
      break;
    }
    case 3 : {
      std::map<const std::string, std::set<MFace, Less_Face> >::iterator mapIt;
      for(mapIt=boundaryFaces.begin(); mapIt!=boundaryFaces.end(); mapIt++) {
        bGroups.push_back(new dgGroupOfFaces(*eGroups[i],mapIt->first,order,mapIt->second));
      }
      break;
    }
    }
    // create a group of faces for every face that is common to elements of the same group 
    fGroups.push_back(new dgGroupOfFaces(*eGroups[i],order));
    // create a groupe of d
    for (int j=i+1;j<eGroups.size();j++){
      dgGroupOfFaces *gof = new dgGroupOfFaces(*eGroups[i],*eGroups[j],order);
      if (gof->getNbElements())
        fGroups.push_back(gof);
      else
        delete gof;
    }
  }
  //create ghost groups
  for(int i=0;i<Msg::GetCommSize();i++){
    for (std::map<int, std::vector<MElement *> >::iterator it = ghostElements[i].begin(); it !=ghostElements[i].end() ; ++it){
      ghostGroups.push_back(new dgGroupOfElements(it->second,order,i));
    }
  }
  //create face group for ghostGroups
  for (int i=0; i<ghostGroups.size(); i++){
    for (int j=0;j<eGroups.size();j++){
      dgGroupOfFaces *gof = new dgGroupOfFaces(*ghostGroups[i],*eGroups[j],order);
      if (gof->getNbElements())
        fGroups.push_back(gof);
      else
        delete gof;
    }
  }
}
// works for any number of groups 
void dgAlgorithm::residual( const dgConservationLaw &claw,
			    std::vector<dgGroupOfElements*> &eGroups, //group of elements
			    std::vector<dgGroupOfFaces*> &fGroups,  // group of interfacs
			    std::vector<dgGroupOfFaces*> &bGroups, // group of boundaries
			    std::vector<dgGroupOfElements*> &ghostGroups, // group of boundaries
			    std::vector<fullMatrix<double> *> &solution, // solution
			    std::vector<fullMatrix<double> *> &residu) // residual
{
  int nbFields=claw.nbFields();
  //volume term
  for(size_t i=0;i<eGroups.size() ; i++) {
    residu[i]->scale(0);
    
    residualVolume(claw,*eGroups[i],*solution[i],*residu[i]);
  }
  //  residu[0]->print("Volume");
  //interface term
  for(size_t i=0;i<fGroups.size() ; i++) {
    dgGroupOfFaces &faces = *fGroups[i];
    int iGroupLeft = -1, iGroupRight = -1;
    for(size_t j=0;j<eGroups.size() ; j++) {
      if (eGroups[j] == &faces.getGroupLeft())iGroupLeft = j;
      if (eGroups[j] == &faces.getGroupRight())iGroupRight= j;
    }
    for(size_t j=0;j<ghostGroups.size() ; j++) {
      if (ghostGroups[j] == &faces.getGroupLeft())iGroupLeft = j+eGroups.size();
      if (ghostGroups[j] == &faces.getGroupRight())iGroupRight= j+eGroups.size();
    }
    fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*2*nbFields);
    fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*2*nbFields);
    faces.mapToInterface(nbFields, *solution[iGroupLeft], *solution[iGroupRight], solInterface);
    residualInterface(claw,faces,solInterface,*solution[iGroupLeft], *solution[iGroupRight],residuInterface);
    faces.mapFromInterface(nbFields, residuInterface, *residu[iGroupLeft], *residu[iGroupRight]);
  }
  //  residu[0]->print("Interfaces");
  //boundaries
  for(size_t i=0;i<bGroups.size() ; i++) {
    dgGroupOfFaces &faces = *bGroups[i];
    int iGroupLeft = -1, iGroupRight = -1;
    for(size_t j=0;j<eGroups.size() ; j++) {
      if (eGroups[j] == &faces.getGroupLeft())iGroupLeft = j;
      if (eGroups[j] == &faces.getGroupRight())iGroupRight= j;
    }
    fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*nbFields);
    fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*nbFields);
    faces.mapToInterface(nbFields, *solution[iGroupLeft], *solution[iGroupRight], solInterface);
    residualBoundary(claw,faces,solInterface,*solution[iGroupLeft],residuInterface);
    faces.mapFromInterface(nbFields, residuInterface, *residu[iGroupLeft], *residu[iGroupRight]);
  }

  //  residu[0]->print("Boundaries");
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

