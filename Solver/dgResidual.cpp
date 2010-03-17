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
  _UVW(_cacheMap->provideParametricCoordinates()),
  _solutionQPe(_cacheMap->provideSolution(_nbFields)),
  _gradientSolutionQPe(_cacheMap->provideSolutionGradient(_nbFields)),
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


dgResidualInterface::dgResidualInterface (const dgConservationLaw &claw):
  _claw (claw)
{
  _nbFields = _claw.getNbFields(); 
}

void dgResidualInterface::compute1Group ( //dofManager &dof, // the DOF manager (maybe useless here)
				     dgGroupOfFaces &group, 
				     const fullMatrix<double> &solution, // solution !! at faces nodes
             const std::vector<const fullMatrix<double>*> & solutionOnElements,
				     fullMatrix<double> &residual // residual !! at faces nodes
				      )
{ 
  // A) global operations before entering the loop over the faces
  // A1 ) copy locally some references from the group for the sake of lisibility
  int nbConnections = group.getNbGroupOfConnections();
  std::vector<dataCacheMap> caches(nbConnections);
  std::vector<const dgGroupOfConnections*> connections(nbConnections);
  std::vector<const dgGroupOfElements*> elementGroups(nbConnections);
  std::vector<dataCacheDouble*> diffusiveFluxes(nbConnections), maximumDiffusivities(nbConnections);
  for (int i=0; i<nbConnections; i++) {
    connections[i] = &group.getGroupOfConnections(i);
    elementGroups[i] = &connections[i]->getGroupOfElements();
    caches[i].provideParametricCoordinates();
    caches[i].provideSolution(_nbFields);
    caches[i].provideSolutionGradient(_nbFields);
    caches[i].provideNormals();
    diffusiveFluxes[i] =_claw.newDiffusiveFlux(caches[i]);
    maximumDiffusivities[i] = _claw.newMaximumDiffusivity(caches[i]); 
    caches[i].setNbEvaluationPoints(group.getNbIntegrationPoints());
  }
  dataCacheDouble *riemannSolver = NULL;
  if (nbConnections == 2)
    riemannSolver = _claw.newRiemannSolver(caches[0], caches[1]); 
  if (nbConnections == 3)
    riemannSolver = _claw.newBifurcationRiemannSolver(caches[0], caches[1], caches[2]); 
    
  // ----- 1 ----  get the solution at quadrature points
  int nbFaces = group.getNbElements();
  fullMatrix<double> solutionQP (group.getNbIntegrationPoints(), nbFaces * _nbFields*nbConnections);
  group.getCollocationMatrix().mult (solution, solutionQP); 
  // needed tocompute normal fluxes  at integration points
  fullMatrix<double> NormalFluxQP (group.getNbIntegrationPoints(), nbFaces*_nbFields*nbConnections);
  fullMatrix<double> normalFluxQP, dofs, dPsiDx;
  int p = elementGroups[0]->getOrder();
  int dim = connections[0]->getElement(0)->getDim();
  for (int iFace=0 ; iFace < nbFaces ; ++iFace) {
    for (int i=0; i<nbConnections; i++) {
      // B1 )  adjust the proxies for this element
      caches[i].getElement().set(connections[i]->getElement(iFace));
      caches[i].getParametricCoordinates(NULL).setAsProxy(connections[i]->getIntegrationPointsOnElement(iFace));
      caches[i].getSolution(NULL).setAsProxy(solutionQP, (iFace*nbConnections+i)*_nbFields, _nbFields);
      caches[i].getNormals(NULL).setAsProxy(connections[i]->getNormals(), iFace*group.getNbIntegrationPoints(), group.getNbIntegrationPoints());
      // B2 ) compute the gradient of the solution
      if(caches[i].getSolutionGradient(NULL).somethingDependOnMe()) {
        dofs.setAsProxy(*solutionOnElements[i], _nbFields*connections[i]->getElementId(iFace), _nbFields);
        dPsiDx.setAsProxy(connections[i]->getDPsiDx(),iFace*elementGroups[i]->getNbNodes(),elementGroups[i]->getNbNodes());
        dPsiDx.mult(dofs, caches[i].getSolutionGradient(NULL).set());
      }
    }
    // proxies for the flux
    normalFluxQP.setAsProxy(NormalFluxQP, iFace*_nbFields*nbConnections, _nbFields*nbConnections);
    // B3 ) compute fluxes    
    if (diffusiveFluxes[0] && nbConnections==2) { // IP only implemented for 2-sides faces (not for bifurcations)
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iFace, iPt);
        //just for the lisibility :
        const fullMatrix<double> &dfl = (*diffusiveFluxes[0])();
        const fullMatrix<double> &dfr = (*diffusiveFluxes[1])();
        const fullMatrix<double> &n = (caches[0].getNormals(NULL))();
        for (int k=0;k<_nbFields;k++) { 
          double meanNormalFlux =
              ((dfl(iPt,k+_nbFields*0)+dfr(iPt,k+_nbFields*0)) * n(0,iPt)
              +(dfl(iPt,k+_nbFields*1)+dfr(iPt,k+_nbFields*1)) * n(1,iPt)
              +(dfl(iPt,k+_nbFields*2)+dfr(iPt,k+_nbFields*2)) * n(2,iPt))/2;
          double minl = std::min(elementGroups[0]->getElementVolume(connections[0]->getElementId(iFace)),
                                 elementGroups[1]->getElementVolume(connections[1]->getElementId(iFace))
                                )/group.getInterfaceSurface(iFace);
          double nu = std::max((*maximumDiffusivities[1])(iPt,0),(*maximumDiffusivities[0])(iPt,0));
          double mu = (p+1)*(p+dim)/dim*nu/minl;
          double solutionJumpPenalty = (caches[0].getSolution(NULL)(iPt,k)-caches[1].getSolution(NULL)(iPt,k))/2*mu;
          normalFluxQP(iPt,k) -= (meanNormalFlux+solutionJumpPenalty)*detJ;
          normalFluxQP(iPt,k+_nbFields) += (meanNormalFlux+solutionJumpPenalty)*detJ;
        }
      }
    }
    if (riemannSolver) {
      for (int iPt =0; iPt< group.getNbIntegrationPoints(); iPt++) {
        const double detJ = group.getDetJ (iFace, iPt);
        for (int k=0;k<_nbFields*nbConnections;k++)
          normalFluxQP(iPt,k) += (*riemannSolver)(iPt,k)*detJ;
      }
    }
  }
  // C ) redistribute the flux to the residual (at Faces nodes)
  if(riemannSolver || diffusiveFluxes[0])
    residual.gemm(group.getRedistributionMatrix(),NormalFluxQP);
}


void dgResidualInterface::computeAndMap1Group (dgGroupOfFaces &faces, dgDofContainer &solution, dgDofContainer &residual)
{
  int nbConnections = faces.getNbGroupOfConnections();
  fullMatrix<double> solInterface(faces.getNbNodes(),faces.getNbElements()*_nbFields*nbConnections);
  fullMatrix<double> residuInterface(faces.getNbNodes(),faces.getNbElements()*_nbFields*nbConnections);

  std::vector<const dgGroupOfElements *> elGroups(nbConnections);
  std::vector<const fullMatrix<double> *> solutionProxies(nbConnections);
  std::vector<fullMatrix<double> *> residualProxies(nbConnections);
  for (int i=0; i<nbConnections; i++) {
    elGroups[i] = &faces.getGroupOfConnections(i).getGroupOfElements();
    solutionProxies[i] = &solution.getGroupProxy(elGroups[i]);
    residualProxies[i] = &residual.getGroupProxy(elGroups[i]);
  }
  faces.mapToInterface(_nbFields, solutionProxies, solInterface);
  compute1Group(faces, solInterface, solutionProxies, residuInterface);
  faces.mapFromInterface(_nbFields, residuInterface, residualProxies);
}

dgResidualInterface::~dgResidualInterface () 
{
}


dgResidualBoundary::dgResidualBoundary(const dgConservationLaw &claw):_claw(claw){
}

void dgResidualBoundary::compute1Group(
				     dgGroupOfFaces &group, 
				     const fullMatrix<double> &solution, // solution !! at faces nodes
				     const fullMatrix<double> &solutionLeft, 
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
  dataCacheDouble &uvw=cacheMapLeft.provideParametricCoordinates();
  dataCacheDouble &solutionQPLeft = cacheMapLeft.provideSolution(nbFields);
  dataCacheDouble &gradientSolutionLeft = cacheMapLeft.provideSolutionGradient(nbFields);
  dataCacheDouble &normals = cacheMapLeft.provideNormals();
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
  int nbConnections = faces.getNbGroupOfConnections();
  fullMatrix<double> solInterface(faces.getNbNodes(), faces.getNbElements()*_nbFields*nbConnections);
  fullMatrix<double> residuInterface(faces.getNbNodes(), faces.getNbElements()*_nbFields*nbConnections);

  std::vector<const dgGroupOfElements *> elGroups(nbConnections);
  std::vector<const fullMatrix<double> *> solutionProxies(nbConnections);
  std::vector<fullMatrix<double> *> residualProxies(nbConnections);
  for (int i=0; i<nbConnections; i++) {
    elGroups[i] = &faces.getGroupOfConnections(i).getGroupOfElements();
    solutionProxies[i] = &solution.getGroupProxy(elGroups[i]);
    residualProxies[i] = &residual.getGroupProxy(elGroups[i]);
  }
  faces.mapToInterface(_nbFields, solutionProxies, solInterface);
  compute1Group(faces, solInterface, *solutionProxies[0],residuInterface);
  faces.mapFromInterface(_nbFields, residuInterface, residualProxies);
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
//  mb = cb->addMethod("compute1Group", &dgResidualInterface::compute1Group);
  //mb->setDescription("compute the residual for one group given fullMatrices with the solution at faces nodes and at element nodes"); 
  //mb->setArgNames("group", "solutionFaces", "solutionOnElements", "residual", NULL);

  cb = b->addClass<dgResidualBoundary>("dgResidualBoundary");
  cb->setDescription("compute the residual for one boundary dgGroupOfFaces");
  mb = cb->addMethod("computeAndMap1Group",&dgResidualBoundary::computeAndMap1Group);
  mb->setDescription("compute the residual for one group given a dgDofContainer solution"); 
  mb->setArgNames("group", "solution", "residual", NULL);
  mb = cb->addMethod("compute1Group", &dgResidualBoundary::compute1Group);
  mb->setDescription("compute the residual for one group given fullMatrices with the solution at faces nodes and at element nodes"); 
  mb->setArgNames("group", "solutionFaces", "solutionGroupLeft", "residual", NULL);
}
