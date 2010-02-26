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
