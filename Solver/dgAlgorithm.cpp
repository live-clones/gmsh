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


// works for any number of groups 

/*
void dgAlgorithm::residualForSomeGroups( const dgConservationLaw &claw,
          std::vector<dgGroupOfElements *>groups,
          dgGroupCollection &groupCollection,
          dgDofContainer &solution,
          dgDofContainer &residu)
{
  solution.scatter();
  int nbFields=claw.getNbFields();
  //volume term
  std::set<dgGroupOfFaces *>groupOfInternalFacesToUpdate;
  std::vector<dgGroupOfFaces *>groupOfBoundaryFacesToUpdate;
  for(size_t i=0;i<groups.size() ; i++) {
    int groupId=groups[i]->getId();
    residu.getGroupProxy(groupId).scale(0);
    residualVolume(claw,*groups[i],solution.getGroupProxy(groupId),residu.getGroupProxy(groupId));
    groupOfInternalFacesToUpdate.insert(groups[i]->getGroupsOfNeighboringFaces()->begin(),groups[i]->getGroupsOfNeighboringFaces()->end());
    groupOfBoundaryFacesToUpdate.insert(groupOfBoundaryFacesToUpdate.end(),groups[i]->getGroupsOfBoundaryFaces()->begin(),groups[i]->getGroupsOfBoundaryFaces()->end());
    groupOfInternalFacesToUpdate.insert(groups[i]->getGroupOfInsideFaces());
  }
  for(std::set<dgGroupOfFaces *>::iterator it=groupOfInternalFacesToUpdate.begin();it!=groupOfInternalFacesToUpdate.end();it++) {
    dgGroupOfFaces *faces = *it;
    int iGroupLeft = -1, iGroupRight = -1;
    for(size_t j=0;j<groupCollection.getNbElementGroups(); j++) {
      dgGroupOfElements *groupj = groupCollection.getElementGroup(j);
      if (groupj == &faces->getGroupLeft()) iGroupLeft = j;
      if (groupj == &faces->getGroupRight()) iGroupRight= j;
    }
    for(size_t j=0;j<groupCollection.getNbGhostGroups(); j++) {
      dgGroupOfElements *groupj = groupCollection.getGhostGroup(j);
      if (groupj == &faces->getGroupLeft()) iGroupLeft = j;
      if (groupj == &faces->getGroupLeft())iGroupLeft = j + groupCollection.getNbElementGroups();
      if (groupj == &faces->getGroupRight())iGroupRight= j + groupCollection.getNbElementGroups();
    }
    fullMatrix<double> solInterface(faces->getNbNodes(),faces->getNbElements()*2*nbFields);
    fullMatrix<double> residuInterface(faces->getNbNodes(),faces->getNbElements()*2*nbFields);
    faces->mapToInterface(nbFields, solution.getGroupProxy(iGroupLeft), solution.getGroupProxy(iGroupRight), solInterface);
    residualInterface(claw,*faces,solInterface,solution.getGroupProxy(iGroupLeft), solution.getGroupProxy(iGroupRight),residuInterface);
    faces->mapFromInterface(nbFields, residuInterface,residu.getGroupProxy(iGroupLeft), residu.getGroupProxy(iGroupRight));
  }
  //boundaries
  for(size_t i=0;i<groupOfBoundaryFacesToUpdate.size() ; i++) {
    dgGroupOfFaces *faces = groupOfBoundaryFacesToUpdate[i];
    int iGroupLeft = -1, iGroupRight = -1;
    for(size_t j=0;j<groupCollection.getNbElementGroups(); j++) {
      dgGroupOfElements *groupj = groupCollection.getElementGroup(j);
      if (groupj == &faces->getGroupLeft())iGroupLeft = j;
      if (groupj == &faces->getGroupRight())iGroupRight= j;
    }
    fullMatrix<double> solInterface(faces->getNbNodes(),faces->getNbElements()*nbFields);
    fullMatrix<double> residuInterface(faces->getNbNodes(),faces->getNbElements()*nbFields);
    faces->mapToInterface(nbFields, solution.getGroupProxy(iGroupLeft), solution.getGroupProxy(iGroupRight), solInterface);
    residualBoundary(claw,*faces,solInterface,solution.getGroupProxy(iGroupLeft),residuInterface);
    faces->mapFromInterface(nbFields, residuInterface, residu.getGroupProxy(iGroupLeft), residu.getGroupProxy(iGroupRight));
  }
}
*/

void dgAlgorithm::computeElementaryTimeSteps ( //dofManager &dof, // the DOF manager (maybe useless here)
					      const dgConservationLaw &claw,   // the conservation law
					      const dgGroupOfElements & group, 
					      fullMatrix<double> &solution,
					      std::vector<double> & DT
					       )
{ 
  const int nbFields = claw.getNbFields();
  dataCacheMap cacheMap;
  cacheMap.setNbEvaluationPoints(group.getNbIntegrationPoints());
  dataCacheDouble &sol = cacheMap.provideData("Solution",1,nbFields);
  dataCacheDouble &UVW = cacheMap.provideData("UVW",1,3);
  UVW.set(group.getIntegrationPointsMatrix());
  dataCacheElement &cacheElement = cacheMap.getElement();
  // provided dataCache
  dataCacheDouble *maxConvectiveSpeed = claw.newMaxConvectiveSpeed(cacheMap);
  dataCacheDouble *maximumDiffusivity = claw.newMaximumDiffusivity(cacheMap);
	
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
