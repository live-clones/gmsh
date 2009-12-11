#ifndef _DG_CONSERVATION_LAW_H_
#define _DG_CONSERVATION_LAW_H_

/*
  \partial_t L(u) =   \nabla \cdot (\vec{f}(u,forcings))  -> convective flux f
                    + \nabla \cdot (\vec{g}(u,\nabla u,forcings)  -> diffusive flux g
		    + r(u,forcings)                       -> source term r
*/
#include "fullMatrix.h"
class dataCacheDouble;
class dataCacheMap;

class dgConservationLaw;

class dgBoundaryCondition {
 public:
  virtual ~dgBoundaryCondition () {}
  virtual dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const = 0;
  //a generic boundary condition using the Riemann solver of the conservation Law
  static dgBoundaryCondition *newOutsideValueCondition(dgConservationLaw &claw,const std::string outsideValueFunctionName);
  static dgBoundaryCondition *new0FluxCondition(dgConservationLaw &claw);
};

class dgConservationLaw {
  std::map<const std::string,dgBoundaryCondition*> _boundaryConditions;
 protected :
  int _nbf;
 public:
  virtual ~dgConservationLaw () {}

  int nbFields() const {return _nbf;}

  virtual dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const {return NULL;} 
  virtual dataCacheDouble *newDiffusiveFlux (dataCacheMap &cacheMap) const {return NULL;} 
  virtual dataCacheDouble *newDiffusiveInterfaceTerm (dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {return NULL;} 
  virtual dataCacheDouble *newMaximumDiffusivity (dataCacheMap &cacheMap) const {return NULL;} 
  virtual dataCacheDouble *newConvectiveFlux (dataCacheMap &cacheMap) const {return NULL;}
  virtual dataCacheDouble *newMaxConvectiveSpeed (dataCacheMap &cacheMap) const {return NULL;}
  virtual dataCacheDouble *newRiemannSolver (dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {return NULL;}

  inline const dgBoundaryCondition *getBoundaryCondition(const std::string tag) const {
    std::map<const std::string,dgBoundaryCondition*>::const_iterator it = _boundaryConditions.find(tag);
    if(it==_boundaryConditions.end())
      throw;
    return it->second;
  }

  inline void addBoundaryCondition(const std::string tag, dgBoundaryCondition * condition) {
    if(_boundaryConditions.find(tag)!=_boundaryConditions.end())
      throw;
    _boundaryConditions[tag]=condition;
  }

};

dgConservationLaw *dgNewConservationLawAdvection(const std::string vname,const std::string nuname);
dgConservationLaw *dgNewConservationLawShallowWater2d();
dgConservationLaw *dgNewConservationLawWaveEquation();
dgConservationLaw *dgNewPerfectGasLaw2d();

dgBoundaryCondition *dgNewBoundaryConditionWaveEquationWall();
dgBoundaryCondition *dgNewBoundaryConditionShallowWater2dWall();
dgBoundaryCondition *dgNewBoundaryConditionPerfectGasLaw2dWall();
dgBoundaryCondition *dgNewBoundaryConditionPerfectGasLaw2dFreeStream(std::string&);


#endif
