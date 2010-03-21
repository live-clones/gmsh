#include "dgTransformNodalValue.h" 
#include "dgGroupOfElements.h"   
#include "dgSystemOfEquations.h" 
#include "function.h"

//----------------------------------------------------------------------------------   
static double n_supra = 20;

int dgSupraTransformNodalValue::apply ( dgDofContainer *solution)
{    
  dgGroupCollection *groups=solution->getGroups();
  int nbFields =_claw->getNbFields();    


  for (int iGroup=0 ; iGroup<groups->getNbElementGroups() ; iGroup++) {
    dgGroupOfElements &group = *groups->getElementGroup(iGroup);
    fullMatrix<double> &sol = solution->getGroupProxy(iGroup);
    fullMatrix<double> Temp;  
     for (int iElement=0 ; iElement<group.getNbElements() ; ++iElement)  { 
      Temp.setAsProxy(sol, nbFields*iElement, nbFields );  
      int fSize = Temp.size1();         
      for (int k=0; k<nbFields; ++k) {
         
        for (int i=0; i<fSize; ++i) {
          if (Temp(i,k)<0) Temp(i,k) = - pow(fabs(Temp(i,k)),1/n_supra);
            else Temp(i,k) = pow(fabs(Temp(i,k)),1/n_supra);
          // Temp(i,k) = Temp(i,k)*0.5;
          }
      
      }
     }
  }
        
}

int dgSupraTransformNodalValue::apply_Inverse ( dgDofContainer *solution)
{    
  dgGroupCollection *groups=solution->getGroups();
  int nbFields =_claw->getNbFields();    
  for (int iGroup=0 ; iGroup<groups->getNbElementGroups() ; iGroup++) {
    dgGroupOfElements &group = *groups->getElementGroup(iGroup);
    fullMatrix<double> &sol = solution->getGroupProxy(iGroup);
    fullMatrix<double> Temp;  
     for (int iElement=0 ; iElement<group.getNbElements() ; ++iElement)  { 
      Temp.setAsProxy(sol, nbFields*iElement, nbFields ); 
      int fSize = Temp.size1();         
      for (int k=0; k<nbFields; ++k) {
         
        
        for (int i=0; i<fSize; ++i) {
           if (Temp(i,k)<0) Temp(i,k) =- pow(fabs(Temp(i,k)),n_supra);
           else Temp(i,k) = pow(fabs(Temp(i,k)),n_supra);
          //Temp(i,k) = 2*Temp(i,k);
          
       }

      }
     }
  }     
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

