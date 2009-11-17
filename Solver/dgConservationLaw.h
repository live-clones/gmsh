#ifndef _DG_CONSERVATION_LAW_H_
#define _DG_CONSERVATION_LAW_H_

/*
  \partial_t L(u) =   \nabla \cdot (\vec{f}(u,forcings))  -> convective flux f
                    + \nabla \cdot (\vec{g}(u,\nabla u,forcings)  -> diffusive flux g
		    + r(u,forcings)                       -> source term r
*/
#include "fullMatrix.h"
class dgElement; 
class dgFace;

class dgTerm{
 public:
  virtual ~dgTerm () {}
  virtual void operator () (const dgElement &, fullMatrix<double> fcx[]) const = 0;
};

class dgFaceTerm{
 public:
  virtual ~dgFaceTerm () {}
  virtual void operator () (const dgFace &, fullMatrix<double> fcx[]) const = 0;
};

class dgBoundaryCondition {
public:
  virtual ~dgBoundaryCondition () {}
  typedef enum {FLUX=0,EXTERNAL_VALUES}boundaryType;
  virtual void operator () (const dgFace&, fullMatrix<double> fcx[]) const = 0;
  virtual boundaryType  type() const =0;
};

class dgConservationLaw {
  protected :
  int _nbf;
  dgTerm *_diffusive, *_convective, *_source, *_maxConvectiveSpeed;
  dgFaceTerm *_riemannSolver;
  std::map<const std::string,dgBoundaryCondition*> _boundaryConditions;
public:
  dgConservationLaw () : _diffusive(0), _convective(0), _source (0), 
			 _riemannSolver(0),_maxConvectiveSpeed (0) {}
  ~dgConservationLaw () {}

  int nbFields() const {return _nbf;}

  inline const dgTerm     * convectiveFlux () const {return _convective;}
  inline const dgTerm     * diffusiveFlux  () const {return _diffusive;}
  inline const dgTerm     * sourceTerm     () const {return _source;}
  inline const dgFaceTerm * riemannSolver  () const {return _riemannSolver;}
  inline const dgTerm     * maxConvectiveSpeed () const {return _maxConvectiveSpeed;}
  inline const dgBoundaryCondition *boundaryCondition(const std::string tag) const {
    std::map<const std::string,dgBoundaryCondition*>::const_iterator it = _boundaryConditions.find(tag);
    if(it==_boundaryConditions.end())
      throw;
    return it->second;
  }

};

dgConservationLaw *dgNewConservationLawAdvection();

#endif
