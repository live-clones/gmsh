#ifndef _DG_CONSERVATION_LAW_H_
#define _DG_CONSERVATION_LAW_H_

/*
  \partial_t L(u) =   \nabla \cdot (\vec{f}(u,forcings))  -> convective flux f
                    + \nabla \cdot (\vec{g}(u,\nabla u,forcings)  -> diffusive flux g
		    + r(u,forcings)                       -> source term r
*/

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

class dgConservationLaw {
  int _nbf;
  dgTerm *_diffusive, *_convective, *_source, *_maxConvectiveSpeed;
  dgFaceTerm *_riemannSolver;
public:
  dgConservationLaw () : _diffusive(0), _convective(0), _source (0), 
			 _riemannSolver(0),_maxConvectiveSpeed (0) {}
  ~dgConservationLaw () {}

  int nbFields() const {return nbf;}

  inline const dgTerm     * convectiveFlux () {return _convective;}
  inline const dgTerm     * diffusiveFlux  () {return _diffusive;}
  inline const dgTerm     * sourceTerm     () {return _source;}
  inline const dgFaceTerm * riemannSolver  () {return _riemannSolver;}
  inline const dgTerm     * maxConvectiveSpeed () {return _maxConvectiveSpeed;}

};



#endif
