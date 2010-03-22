#include "dgTransformNodalValue.h" 
#include "dgGroupOfElements.h"   
#include "dgSystemOfEquations.h" 
#include "function.h"

//----------------------------------------------------------------------------------   
static double n_supra = 20;

int dgSupraTransformNodalValue::apply ( dgDofContainer *solution)
{    
  
  
  fullVector<double> sol = (*solution).getVector(); 
  for (int i=0;i< sol.size();i++){
   
     if ((sol)(i)<0) (sol)(i)=-pow(- (sol)(i), 1/n_supra);
       else (sol)(i)=pow( (sol)(i), 1/n_supra);
     }
  
  return 1;        
}

int dgSupraTransformNodalValue::apply_Inverse ( dgDofContainer *solution)
{    
  

  fullVector<double> sol = (*solution).getVector(); 
  for (int i=0;i< sol.size();i++){
   
     if ((sol)(i)<0) (sol)(i)=-pow(- (sol)(i), n_supra);
       else (sol)(i)=pow( (sol)(i), n_supra);
     }
  
  return 1;
}


#include "Bindings.h"

void dgTransformNodalValue::registerBindings(binding *b) {
  classBinding *cb = b->addClass<dgTransformNodalValue>("dgTransformNodalValue");
  cb->setDescription("Parent class for transformations of nodal value");
  methodBinding *cm;
  cm = cb->addMethod("apply",&dgTransformNodalValue::apply);
  cm->setArgNames("solution",NULL);
  cm->setDescription("apply a transformation of the solution");

  cm = cb->addMethod("apply_Inverse",&dgTransformNodalValue::apply_Inverse);
  cm->setArgNames("solution",NULL);
  cm->setDescription("apply an inverse transformation of the solution");
}

void dgSupraTransformNodalValueRegisterBindings(binding *b) {
  classBinding *cb = b->addClass<dgSupraTransformNodalValue>("dgSupraTransformNodalValue");
  cb->setDescription("Transformation of nodal value with the power law of superconductors");
  methodBinding *cm;
  cm = cb->setConstructor<dgSupraTransformNodalValue,dgConservationLaw *>();
  cm->setDescription("exemple");
  cm->setArgNames("law",NULL);
  cb->setParentClass<dgTransformNodalValue>();
}

