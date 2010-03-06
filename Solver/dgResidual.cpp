#include "dgResidual.h"
#include "dgConservationLaw.h"
#include "dgGroupOfElements.h"
#include "function.h"
#include "functionDerivator.h"
#include "dgDofContainer.h"
#include "MElement.h"

dgResidualVolume::dgResidualVolume(const dgConservationLaw &claw):
  _cacheMap(new dataCacheMap),
  _claw(claw),
  _nbFields(_claw.getNbFields()),
  _cacheElement(_cacheMap->getElement()),
  _UVW(_cacheMap->provideData("UVW", 1, 3)),
  _solutionQPe(_cacheMap->provideData("Solution", 1, _nbFields)),
  _gradientSolutionQPe(_cacheMap->provideData("SolutionGradient", 3, _nbFields)),
  _sourceTerm(_claw.newSourceTerm(*_cacheMap)),
  _convectiveFlux(_claw.newConvectiveFlux(*_cacheMap)),
  _diffusiveFlux(_claw.newDiffusiveFlux(*_cacheMap))
{
}

dgResidualVolume::~dgResidualVolume()
{
  delete _cacheMap;
}

void dgResidualVolume::compute1Group(dgGroupOfElements &group, fullMatrix<double> &solution, fullMatrix<double> &residual) 
{
  residual.scale(0);
  _cacheMap->setNbEvaluationPoints(group.getNbIntegrationPoints());
  _UVW.set(group.getIntegrationPointsMatrix());
  // ----- 1 ----  get the solution at quadrature points
  // ----- 1.1 --- allocate a matrix of size (nbFields * nbElements, nbQuadraturePoints) 
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * _nbFields);
  // ----- 1.2 --- multiply the solution by the collocation matrix
  group.getCollocationMatrix().mult(solution  , solutionQP); 
  // ----- 2 ----  compute all fluxes (diffusive and convective) at integration points
  // ----- 2.1 --- allocate elementary fluxes (compued in XYZ coordinates)
  fullMatrix<double> fConv[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields )};
  fullMatrix<double> fDiff[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields )};
  fullMatrix<double> Source = fullMatrix<double> (group.getNbIntegrationPoints(),group.getNbElements() * _nbFields);
  // ----- 2.2 --- allocate parametric fluxes (computed in UVW coordinates) for all elements at all integration points
  fullMatrix<double> Fuvw[3] = {fullMatrix<double> ( group.getNbIntegrationPoints(), group.getNbElements() * _nbFields),
    fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * _nbFields),
    fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * _nbFields)};
  fullMatrix<double> fuvwe;
  fullMatrix<double> source;
  fullMatrix<double> dPsiDx,dofs; 
  // ----- 2.3 --- iterate on elements
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
      // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    _solutionQPe.setAsProxy(solutionQP, iElement*_nbFields, _nbFields );

    if(_gradientSolutionQPe.somethingDependOnMe()){
      dPsiDx.setAsProxy(group.getDPsiDx(),iElement*group.getNbNodes(),group.getNbNodes());
      dofs.setAsProxy(solution, _nbFields*iElement, _nbFields);
      dPsiDx.mult(dofs, _gradientSolutionQPe.set());
    }
    _cacheElement.set(group.getElement(iElement));
    if(_convectiveFlux || _diffusiveFlux) {
      // ----- 2.3.3 --- compute fluxes in UVW coordinates
      for (int iUVW=0;iUVW<group.getDimUVW();iUVW++) {
        // ----- 2.3.3.1 --- get a proxy on the big local flux matrix
        fuvwe.setAsProxy(Fuvw[iUVW], iElement*_nbFields,_nbFields);
        // ----- 2.3.3.1 --- compute \vec{f}^{UVW} =\vec{f}^{XYZ} J^{-1} and multiply bt detJ
        for (int iXYZ=0;iXYZ<group.getDimXYZ();iXYZ++) {
          for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
            // get the right inv jacobian matrix dU/dX element
            const double invJ = group.getInvJ (iElement, iPt, iUVW, iXYZ);
            // get the detJ at this point
            const double detJ = group.getDetJ (iElement, iPt);
            const double factor = invJ * detJ;
            // compute fluxes in the reference coordinate system at this integration point
            for (int k=0;k<_nbFields;k++){
              if(_convectiveFlux)
                fuvwe(iPt,k) += ( (*_convectiveFlux)(iPt,iXYZ*_nbFields+k)) * factor;
              if(_diffusiveFlux){
                fuvwe(iPt,k) += ( (*_diffusiveFlux)(iPt,iXYZ*_nbFields+k)) * factor;
              }
            }
          }
        } 
      }
    }
    if (_sourceTerm){
      source.setAsProxy(Source, iElement*_nbFields,_nbFields);
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iElement, iPt);
        for (int k=0;k<_nbFields;k++){
          source(iPt,k) = (*_sourceTerm)(iPt,k)*detJ;
        }
      }
    }
  }
  // ----- 3 ---- do the redistribution at nodes using as many BLAS3 operations as there are local coordinates
  if(_convectiveFlux || _diffusiveFlux){
    for (int iUVW=0;iUVW<group.getDimUVW();iUVW++){
      residual.gemm(group.getFluxRedistributionMatrix(iUVW),Fuvw[iUVW]);
    }
  }  
  if(_sourceTerm){
    residual.gemm(group.getSourceRedistributionMatrix(),Source);
  }
}

void dgResidualVolume::compute1GroupWithJacobian(dgGroupOfElements &group, fullMatrix<double> &solution, fullMatrix<double> &residual, fullMatrix<double> &jacobian) 
{
  residual.scale(0);
  _cacheMap->setNbEvaluationPoints(group.getNbIntegrationPoints());
  _UVW.set(group.getIntegrationPointsMatrix());
  // ----- 1 ----  get the solution at quadrature points
  // ----- 1.1 --- allocate a matrix of size (nbFields * nbElements, nbQuadraturePoints) 
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * _nbFields);
  // ----- 1.2 --- multiply the solution by the collocation matrix
  group.getCollocationMatrix().mult(solution  , solutionQP); 
  // ----- 2 ----  compute all fluxes (diffusive and convective) at integration points
  // ----- 2.1 --- allocate elementary fluxes (compued in XYZ coordinates)
  fullMatrix<double> fConv[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields )};
  fullMatrix<double> fDiff[3] = {fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields ),
    fullMatrix<double>( group.getNbIntegrationPoints(), _nbFields )};
  fullMatrix<double> Source = fullMatrix<double> (group.getNbIntegrationPoints(),group.getNbElements() * _nbFields);
  // ----- 2.2 --- allocate parametric fluxes (computed in UVW coordinates) for all elements at all integration points
  fullMatrix<double> Fuvw[3] = {fullMatrix<double> ( group.getNbIntegrationPoints(), group.getNbElements() * _nbFields),
    fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * _nbFields),
    fullMatrix<double> (group.getNbIntegrationPoints(), group.getNbElements() * _nbFields)};
  fullMatrix<double> fuvwe;
  fullMatrix<double> source;
  fullMatrix<double> dPsiDx,dofs;
  int nColA = group.getDimUVW()*group.getNbIntegrationPoints();
  int nColB = group.getDimUVW()*group.getDimUVW()*group.getNbIntegrationPoints();
  fullMatrix<double> A (_nbFields*_nbFields, nColA*group.getNbElements());
  fullMatrix<double> B (_nbFields*_nbFields, nColB*group.getNbElements());
  fullMatrix<double> a, b;
  functionDerivator *dDiffusiveFluxdGradU,*dConvectiveFluxdU;
  if(_diffusiveFlux)
    dDiffusiveFluxdGradU=new functionDerivator(*_diffusiveFlux,_gradientSolutionQPe,1e-6);
  if(_convectiveFlux)
    dConvectiveFluxdU=new functionDerivator(*_convectiveFlux,_solutionQPe,1e-6);
  // ----- 2.3 --- iterate on elements
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
    // ----- 2.3.1 --- build a small object that contains elementary solution, jacobians, gmsh element
    _solutionQPe.setAsProxy(solutionQP, iElement*_nbFields, _nbFields );
    a.setAsProxy(A, iElement*nColA, nColA);
    b.setAsProxy(B, iElement*nColB, nColB);

    if(_gradientSolutionQPe.somethingDependOnMe()){
      dPsiDx.setAsProxy(group.getDPsiDx(),iElement*group.getNbNodes(),group.getNbNodes());
      dofs.setAsProxy(solution, _nbFields*iElement, _nbFields);
      dPsiDx.mult(dofs, _gradientSolutionQPe.set());
    }
    _cacheElement.set(group.getElement(iElement));
    if(_convectiveFlux || _diffusiveFlux) {
      // ----- 2.3.3 --- compute fluxes in UVW coordinates
      for (int iUVW=0;iUVW<group.getDimUVW();iUVW++) {
        // ----- 2.3.3.1 --- get a proxy on the big local flux matrix
        fuvwe.setAsProxy(Fuvw[iUVW], iElement*_nbFields,_nbFields);
        // ----- 2.3.3.1 --- compute \vec{f}^{UVW} =\vec{f}^{XYZ} J^{-1} and multiply bt detJ
        for (int iXYZ=0;iXYZ<group.getDimXYZ();iXYZ++) {
          for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
            // get the right inv jacobian matrix dU/dX element
            const double invJ = group.getInvJ (iElement, iPt, iUVW, iXYZ);
            // get the detJ at this point
            const double detJ = group.getDetJ (iElement, iPt);
            const double factor = invJ * detJ;
            // compute fluxes in the reference coordinate system at this integration point
            for (int k=0;k<_nbFields;k++){
              if(_convectiveFlux)
                fuvwe(iPt,k) += ( (*_convectiveFlux)(iPt,iXYZ*_nbFields+k)) * factor;
              if(_diffusiveFlux){
                fuvwe(iPt,k) += ( (*_diffusiveFlux)(iPt,iXYZ*_nbFields+k)) * factor;
              }
            }
          }
        } 
      }
    }
    if (_sourceTerm){
      source.setAsProxy(Source, iElement*_nbFields,_nbFields);
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iElement, iPt);
        for (int k=0;k<_nbFields;k++){
          source(iPt,k) = (*_sourceTerm)(iPt,k)*detJ;
        }
      }
    }
    int nQP = group.getNbIntegrationPoints();
    int dim = group.getDimUVW();
    if(_diffusiveFlux) {
      dDiffusiveFluxdGradU->compute();
      for (int alpha=0; alpha < dim; alpha++) for (int beta=0; beta < dim; beta++) {
        for(int x=0;x <group.getDimXYZ();x++) for(int y=0;y <group.getDimXYZ();x++) {
          for (int xi=0; xi <group.getNbIntegrationPoints(); xi++) {
            const double invJx = group.getInvJ (iElement, xi, alpha, x);
            const double invJy = group.getInvJ (iElement, xi, beta, y);
            const double detJ = group.getDetJ (iElement, xi);
            const double factor = invJx * invJy * detJ;
            for (int k=0; k< _nbFields; k++) for (int l=0; l<_nbFields; l++) {
              b(k*_nbFields+l,(alpha*dim+beta)*nQP+xi) = dDiffusiveFluxdGradU->get(k*dim+alpha,l*dim+beta,xi)*factor;
            }
          }
        }
      }
    }
    if(_convectiveFlux) {
      dConvectiveFluxdU->compute();
      for (int alpha=0; alpha < dim; alpha++) {
        for(int x=0;x <group.getDimXYZ();x++) {
          for (int xi=0; xi <group.getNbIntegrationPoints(); xi++){
            const double invJ = group.getInvJ (iElement, xi, alpha, x);
            const double detJ = group.getDetJ (iElement, xi);
            const double factor = invJ * detJ;
            for (int k=0; k< _nbFields; k++) for (int l=0; l<_nbFields; l++){
              a(k*_nbFields+l,alpha*nQP+xi) = dConvectiveFluxdU->get(k*dim+alpha,l,xi)*factor;
            }
          }
        }
      }
    }
  }

  // ----- 3 ---- do the redistribution at nodes using as many BLAS3 operations as there are local coordinates
  if(_convectiveFlux || _diffusiveFlux){
    for (int iUVW=0;iUVW<group.getDimUVW();iUVW++){
      residual.gemm(group.getFluxRedistributionMatrix(iUVW),Fuvw[iUVW]);
    }
  }
  if(_sourceTerm){
    residual.gemm(group.getSourceRedistributionMatrix(),Source);
  }
  int nbNodes = group.getNbNodes();
  fullMatrix<double> jacobianK (_nbFields*_nbFields,nbNodes*nbNodes);
  if (_convectiveFlux) {
    jacobianK.gemm(group.getPsiDPsiDXi(),B);
  }
  if (_convectiveFlux) {
    jacobianK.gemm(group.getDPsiDXDPsiDXi(),A);
  }
  fullMatrix<double> jacobianE, jacobianKE;
  for (int iElement=0 ; iElement<group.getNbElements() ;++iElement) {
    jacobianKE.setAsProxy(jacobianK, iElement*_nbFields*_nbFields, _nbFields*_nbFields);
    jacobianKE.setAsProxy(jacobian, iElement*_nbFields*nbNodes, _nbFields*nbNodes);
    for (int k=0; k<_nbFields;k++) for (int l=0;l<_nbFields;l++) {
      for(int i=0; i<nbNodes; i++) for(int j=0; j<nbNodes; j++) {
        jacobianE(l*nbNodes+j, k*nbNodes+i) = jacobianKE(k*_nbFields+l, i*nbNodes+j);
      }
    }
  }
}

void dgResidualVolume::computeAndMap1Group(dgGroupOfElements &group, dgDofContainer &solution, dgDofContainer &residual) 
{
  compute1Group (group, solution.getGroupProxy(&group), residual.getGroupProxy(&group));
}


dgResidualInterface::dgResidualInterface (const dgConservationLaw &claw) :
  _cacheMapLeft (new dataCacheMap),
  _cacheMapRight (new dataCacheMap),
  _claw(claw),
  _nbFields(claw.getNbFields()),
  _cacheElementLeft(_cacheMapLeft->getElement()),
  _cacheElementRight(_cacheMapRight->getElement()),
  _uvwLeft(_cacheMapLeft->provideData("UVW",1,3)),
  _uvwRight(_cacheMapRight->provideData("UVW",1,3)),
  _solutionQPLeft(_cacheMapLeft->provideData("Solution",1,_nbFields)),
  _solutionQPRight(_cacheMapRight->provideData("Solution",1,_nbFields)),
  _gradientSolutionLeft(_cacheMapLeft->provideData("SolutionGradient",3,_nbFields)),
  _gradientSolutionRight(_cacheMapRight->provideData("SolutionGradient",3,_nbFields)),
  _normals(_cacheMapLeft->provideData("Normals",1,1)),
  _riemannSolver(claw.newRiemannSolver(*_cacheMapLeft,*_cacheMapRight)),
  _diffusiveFluxLeft(claw.newDiffusiveFlux(*_cacheMapLeft)),
  _diffusiveFluxRight(claw.newDiffusiveFlux(*_cacheMapRight)),
  _maximumDiffusivityLeft(claw.newMaximumDiffusivity(*_cacheMapLeft)),
  _maximumDiffusivityRight(claw.newMaximumDiffusivity(*_cacheMapRight))
{
}

void dgResidualInterface::compute1Group ( //dofManager &dof, // the DOF manager (maybe useless here)
				     dgGroupOfFaces &group, 
				     const fullMatrix<double> &solution, // solution !! at faces nodes
				     fullMatrix<double> &solutionLeft, 
				     fullMatrix<double> &solutionRight, 
				     fullMatrix<double> &residual // residual !! at faces nodes
				      )
{ 
  // A) global operations before entering the loop over the faces
  // A1 ) copy locally some references from the group for the sake of lisibility
  const dgGroupOfConnections &left = group.getGroupOfConnections(0);
  const dgGroupOfConnections &right = group.getGroupOfConnections(1);
  const dgGroupOfElements &groupLeft = left.getGroupOfElements();
  const dgGroupOfElements &groupRight = right.getGroupOfElements();
  int nbFaces = group.getNbElements();
  //get matrices needed to compute the gradient on both sides
  const fullMatrix<double> &DPsiLeftDx = left.getDPsiDx();
  const fullMatrix<double> &DPsiRightDx = right.getDPsiDx();
  // ----- 1 ----  get the solution at quadrature points
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),nbFaces * _nbFields*2);
  group.getCollocationMatrix().mult(solution, solutionQP); 
  // needed tocompute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP ( group.getNbIntegrationPoints(), nbFaces*_nbFields*2);
  // create one dataCache for each side
  _cacheMapLeft->setNbEvaluationPoints(group.getNbIntegrationPoints());
  _cacheMapRight->setNbEvaluationPoints(group.getNbIntegrationPoints());
  fullMatrix<double> dPsiLeftDx,dPsiRightDx,dofsLeft,dofsRight,normalFluxQP;
  int p = groupLeft.getOrder();
  int dim = left.getElement(0)->getDim();
  for (int iFace=0 ; iFace < nbFaces ; ++iFace) {
    // B1 )  adjust the proxies for this element
    //      NB  : the B1 section will almost completely disapear 
    //      if we write a function (from the function class) for moving proxies across big matrices
    // give the current elements to the dataCacheMap 
    _cacheElementLeft.set(left.getElement(iFace));
    _cacheElementRight.set(left.getElement(iFace));
    // proxies for the solution
    _solutionQPLeft.setAsProxy(solutionQP, iFace*2*_nbFields, _nbFields);
    _solutionQPRight.setAsProxy(solutionQP, (iFace*2+1)*_nbFields, _nbFields);
    _normals.setAsProxy(left.getNormals(), iFace*group.getNbIntegrationPoints(),group.getNbIntegrationPoints());
    // proxies needed to compute the gradient of the solution and the IP term
    dPsiLeftDx.setAsProxy(DPsiLeftDx,iFace*groupLeft.getNbNodes(),groupLeft.getNbNodes());
    dPsiRightDx.setAsProxy(DPsiRightDx,iFace*groupRight.getNbNodes(),groupRight.getNbNodes());
    dofsLeft.setAsProxy(solutionLeft, _nbFields*left.getElementId(iFace), _nbFields);
    dofsRight.setAsProxy(solutionRight, _nbFields*right.getElementId(iFace), _nbFields);
    _uvwLeft.setAsProxy(left.getIntegrationPointsOnElement(iFace));
    _uvwRight.setAsProxy(right.getIntegrationPointsOnElement(iFace));
    // proxies for the flux
    normalFluxQP.setAsProxy(NormalFluxQP, iFace*_nbFields*2, _nbFields*2);
    // B2 ) compute the gradient of the solution
    if(_gradientSolutionLeft.somethingDependOnMe()){
      dPsiLeftDx.mult(dofsLeft, _gradientSolutionLeft.set());
      dPsiRightDx.mult(dofsRight, _gradientSolutionRight.set());
    }
    // B3 ) compute fluxes    
    if (_diffusiveFluxLeft) {
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iFace, iPt);
        //just for the lisibility :
        const fullMatrix<double> &dfl = (*_diffusiveFluxLeft)();
        const fullMatrix<double> &dfr = (*_diffusiveFluxRight)();
        for (int k=0;k<_nbFields;k++) { 
          double meanNormalFlux =
              ((dfl(iPt,k+_nbFields*0 )+dfr(iPt,k+_nbFields*0)) * _normals(0,iPt)
              +(dfl(iPt,k+_nbFields*1 )+dfr(iPt,k+_nbFields*1)) * _normals(1,iPt)
              +(dfl(iPt,k+_nbFields*2 )+dfr(iPt,k+_nbFields*2)) * _normals(2,iPt))/2;
          double minl = std::min(groupLeft.getElementVolume(left.getElementId(iFace)),
                                 groupRight.getElementVolume(right.getElementId(iFace))
                                )/group.getInterfaceSurface(iFace);
          double nu = std::max((*_maximumDiffusivityRight)(iPt,0),(*_maximumDiffusivityLeft)(iPt,0));
          double mu = (p+1)*(p+dim)/dim*nu/minl;
          double solutionJumpPenalty = (_solutionQPLeft(iPt,k)-_solutionQPRight(iPt,k))/2*mu;
          normalFluxQP(iPt,k) -= (meanNormalFlux+solutionJumpPenalty)*detJ;
          normalFluxQP(iPt,k+_nbFields) += (meanNormalFlux+solutionJumpPenalty)*detJ;
        }
      }
    }
    if (_riemannSolver) {
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iFace, iPt);
        for (int k=0;k<_nbFields*2;k++)
          normalFluxQP(iPt,k) += (*_riemannSolver)(iPt,k)*detJ;
      }
    }
  }
  // C ) redistribute the flux to the residual (at Faces nodes)
  if(_riemannSolver || _diffusiveFluxLeft)
    residual.gemm(group.getRedistributionMatrix(),NormalFluxQP);
}


void dgResidualInterface::computeAndMap1Group (dgGroupOfFaces &faces, dgDofContainer &solution, dgDofContainer &residual)
{
  fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*2*_nbFields);
  fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*2*_nbFields);
  const dgGroupOfElements *groupLeft = &faces.getGroupOfConnections(0).getGroupOfElements();
  const dgGroupOfElements *groupRight = &faces.getGroupOfConnections(1).getGroupOfElements();
  faces.mapToInterface(_nbFields, solution.getGroupProxy(groupLeft), solution.getGroupProxy(groupRight), solInterface);
  compute1Group(faces,solInterface,solution.getGroupProxy(groupLeft), solution.getGroupProxy(groupRight),residuInterface);
  faces.mapFromInterface(_nbFields, residuInterface,residual.getGroupProxy(groupLeft), residual.getGroupProxy(groupRight));
}

dgResidualInterface::~dgResidualInterface () 
{
  delete _cacheMapLeft;
  delete _cacheMapRight;
}


dgResidualBoundary::dgResidualBoundary(const dgConservationLaw &claw):_claw(claw){
}

void dgResidualBoundary::compute1Group(
				     dgGroupOfFaces &group, 
				     const fullMatrix<double> &solution, // solution !! at faces nodes
				     fullMatrix<double> &solutionLeft, 
				     fullMatrix<double> &residual // residual !! at faces nodes
            )
{
  //should be splitted like dgResidualInterface and dgResidualVolume
  //but i do not do it know because dgResidualBoundary will probably disapear when we will have list of elements on interfaces
  const dgGroupOfConnections &left = group.getGroupOfConnections(0);
  const dgGroupOfElements &groupLeft = left.getGroupOfElements();
  int nbFields = _claw.getNbFields();
  const dgBoundaryCondition *boundaryCondition = _claw.getBoundaryCondition(group.getPhysicalTag());
  // ----- 1 ----  get the solution at quadrature points
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(),group.getNbElements() * nbFields);
  group.getCollocationMatrix().mult(solution, solutionQP); 
  // ----- 2 ----  compute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP ( group.getNbIntegrationPoints(), group.getNbElements()*nbFields);

  dataCacheMap cacheMapLeft;
  cacheMapLeft.setNbEvaluationPoints(group.getNbIntegrationPoints());
  const fullMatrix<double> &DPsiLeftDx = left.getDPsiDx();
  // provided dataCache
  dataCacheDouble &uvw=cacheMapLeft.provideData("UVW",1,3);
  dataCacheDouble &solutionQPLeft = cacheMapLeft.provideData("Solution",1,nbFields);
  dataCacheDouble &gradientSolutionLeft = cacheMapLeft.provideData("SolutionGradient",3,nbFields);
  dataCacheDouble &normals = cacheMapLeft.provideData("Normals",1,1);
  dataCacheElement &cacheElementLeft = cacheMapLeft.getElement();
  // required data
  // inviscid
  dataCacheDouble *boundaryTerm = boundaryCondition->newBoundaryTerm(cacheMapLeft);
  // viscous
  dataCacheDouble *diffusiveFluxLeft = _claw.newDiffusiveFlux(cacheMapLeft);
  dataCacheDouble *maximumDiffusivityLeft = _claw.newMaximumDiffusivity(cacheMapLeft);
  dataCacheDouble *maximumDiffusivityOut = boundaryCondition->newMaximumDiffusivity(cacheMapLeft);
  dataCacheDouble *neumann   = boundaryCondition->newDiffusiveNeumannBC(cacheMapLeft);
  dataCacheDouble *dirichlet = boundaryCondition->newDiffusiveDirichletBC(cacheMapLeft);

  fullMatrix<double> normalFluxQP,dPsiLeftDx,dofsLeft;

  int p = groupLeft.getOrder();
  int dim = left.getElement(0)->getDim();

  for (int iFace=0 ; iFace<group.getNbElements() ;++iFace) {
    normalFluxQP.setAsProxy(NormalFluxQP, iFace*nbFields, nbFields);
    // ----- 2.3.1 --- provide the data to the cacheMap
    solutionQPLeft.setAsProxy(solutionQP, iFace*nbFields, nbFields);
    normals.setAsProxy(left.getNormals(),iFace*group.getNbIntegrationPoints(),group.getNbIntegrationPoints());
    // proxies needed to compute the gradient of the solution and the IP term
    dPsiLeftDx.setAsProxy(DPsiLeftDx,iFace*groupLeft.getNbNodes(), groupLeft.getNbNodes());
    dofsLeft.setAsProxy(solutionLeft, nbFields*left.getElementId(iFace), nbFields);

    uvw.setAsProxy(left.getIntegrationPointsOnElement(iFace));
    cacheElementLeft.set(left.getElement(iFace));

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
          double minl = groupLeft.getElementVolume(left.getElementId(iFace))/group.getInterfaceSurface(iFace);
          double nu = (*maximumDiffusivityLeft)(iPt,0);
          if(maximumDiffusivityOut)
            nu = std::max(nu,(*maximumDiffusivityOut)(iPt,0));
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

void dgResidualBoundary::computeAndMap1Group(dgGroupOfFaces &faces, dgDofContainer &solution, dgDofContainer &residual)
{
  int _nbFields = _claw.getNbFields();
  fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*_nbFields);
  fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*_nbFields);
  const dgGroupOfElements &groupLeft = faces.getGroupOfConnections(0).getGroupOfElements();
  faces.mapToInterface(_nbFields, solution.getGroupProxy(&groupLeft), solution.getGroupProxy(&groupLeft), solInterface);
  compute1Group(faces,solInterface,solution.getGroupProxy(&groupLeft),residuInterface);
  faces.mapFromInterface(_nbFields, residuInterface, residual.getGroupProxy(&groupLeft), residual.getGroupProxy(&groupLeft));
}

void dgResidual::compute(dgGroupCollection &groups, dgDofContainer &solution, dgDofContainer &residual)
{
  solution.scatter();
  dgResidualVolume residualVolume(_claw);
  for (int i=0; i<groups.getNbElementGroups(); i++)
    residualVolume.computeAndMap1Group(*groups.getElementGroup(i), solution, residual);
  dgResidualInterface residualInterface(_claw);
  for(size_t i=0;i<groups.getNbFaceGroups() ; i++){
    residualInterface.computeAndMap1Group(*groups.getFaceGroup(i), solution, residual);
  }
  dgResidualBoundary residualBoundary(_claw);
  for(size_t i=0;i<groups.getNbBoundaryGroups() ; i++)
    residualBoundary.computeAndMap1Group(*groups.getBoundaryGroup(i), solution, residual);
}

#include "Bindings.h"
void dgResidual::registerBindings (binding *b)
{
  classBinding *cb = b->addClass<dgResidual>("dgResidual");
  cb->setDescription("compute the residual, given a conservation law and a solution dof container");
  methodBinding *mb;
  mb = cb->addMethod("compute", &dgResidual::compute);
  mb->setDescription("compute the residual");
  mb->setArgNames("groups", "solution", "residual",NULL);
  mb = cb->setConstructor<dgResidual, dgConservationLaw*>();
  mb->setDescription("a new object used to compute the residual");
  mb->setArgNames("law",NULL);

  cb = b->addClass<dgResidualVolume>("dgResidualVolume");
  cb->setDescription("compute the residual for one dgGroupOfFaces");
  mb = cb->addMethod("computeAndMap1Group",&dgResidualVolume::computeAndMap1Group);
  mb->setDescription("compute the residual for one group given a dgDofContainer solution"); 
  mb->setArgNames("group", "solution", "residual", NULL);
  mb = cb->addMethod("compute1Group", &dgResidualVolume::compute1Group);
  mb->setDescription("compute the residual for one group given a fullMatrix proxy to the solution relative to this group"); 
  mb->setArgNames("group", "solution", "residual", NULL);

  mb = cb->addMethod("compute1GroupWithJacobian", &dgResidualVolume::compute1GroupWithJacobian);
  mb->setDescription("compute the residual for one group given a fullMatrix proxy to the solution relative to this group"); 
  mb->setArgNames("group", "solution", "residual", "jacobian", NULL);

  cb = b->addClass<dgResidualInterface>("dgResidualInterface");
  cb->setDescription("compute the residual for one dgGroupOfElements");
  mb = cb->addMethod("computeAndMap1Group",&dgResidualInterface::computeAndMap1Group);
  mb->setDescription("compute the residual for one group given a dgDofContainer solution"); 
  mb->setArgNames("group", "solution", "residual", NULL);
  mb = cb->addMethod("compute1Group", &dgResidualInterface::compute1Group);
  mb->setDescription("compute the residual for one group given fullMatrices with the solution at faces nodes and at element nodes"); 
  mb->setArgNames("group", "solutionFaces", "solutionGroupLeft", "solutionGroupRight", "residual", NULL);

  cb = b->addClass<dgResidualBoundary>("dgResidualBoundary");
  cb->setDescription("compute the residual for one boundary dgGroupOfFaces");
  mb = cb->addMethod("computeAndMap1Group",&dgResidualBoundary::computeAndMap1Group);
  mb->setDescription("compute the residual for one group given a dgDofContainer solution"); 
  mb->setArgNames("group", "solution", "residual", NULL);
  mb = cb->addMethod("compute1Group", &dgResidualBoundary::compute1Group);
  mb->setDescription("compute the residual for one group given fullMatrices with the solution at faces nodes and at element nodes"); 
  mb->setArgNames("group", "solutionFaces", "solutionGroupLeft", "residual", NULL);
}
