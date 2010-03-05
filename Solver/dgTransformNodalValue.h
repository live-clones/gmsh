#ifndef _DG_TRANSFORM_NODAL_VALUE_H_
#define _DG_TRANSFORM_NODAL_VALUE_H_

#include "fullMatrix.h"
#include <vector>
class dgDofContainer;
class dgGroupCollection;
class dgConservationLaw;
class binding;

class dgTransformNodalValue{
protected:
  dgConservationLaw *_claw;
public:
  dgTransformNodalValue (dgConservationLaw *claw) : _claw(claw) {}
  virtual int apply ( dgDofContainer *sol)=0;
  virtual int apply_Inverse ( dgDofContainer *sol)=0;
  static void registerBindings(binding *b);
};

class dgSupraTransformNodalValue : public dgTransformNodalValue{
public :
  dgSupraTransformNodalValue (dgConservationLaw *claw) : dgTransformNodalValue (claw) {}
  virtual int apply ( dgDofContainer *solution);
  virtual int apply_Inverse ( dgDofContainer *solution);
};
void dgSupraTransformNodalValueRegisterBindings(binding *b);


#endif
