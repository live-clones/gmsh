#ifndef _DG_ALGORITHM_H_
#define _DG_ALGORITHM_H_

#include "fullMatrix.h"
#include <vector>
class GModel;
class dgGroupOfElements;
class dgGroupOfFaces;
class dgConservationLaw;
class dgTerm;

class dgAlgorithm {
 public :
   void residualVolume ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfElements & group, 
           const fullMatrix<double> &solution,
           fullMatrix<double> &residual);
   void residualInterface ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfFaces & group, 
           const fullMatrix<double> &solution, // ! at face nodes
           fullMatrix<double> &residual); // ! at face nodes
   void residualBoundary ( //dofManager &dof, // the DOF manager (maybe useless here)
				   const dgConservationLaw &claw,   // the conservation law
				   const dgGroupOfFaces &group, 
           const fullMatrix<double> &solution, // solution !! at faces nodes
           fullMatrix<double> &residual // residual !! at faces nodes
           );
   // works only if there is only 1 group of element
  void residual( const dgConservationLaw &claw,
      std::vector<dgGroupOfElements*> &eGroups, //group of elements
      std::vector<dgGroupOfFaces*> &fGroups,  // group of interfacs
      std::vector<dgGroupOfFaces*> &bGroups, // group of boundaries
      const fullMatrix<double> &solution, // solution !! at faces nodes
      fullMatrix<double> &residual // residual !! at faces nodes
      );
  void multAddInverseMassMatrix ( /*dofManager &dof,*/
      const dgGroupOfElements & group,
      fullMatrix<double> &residu,
      fullMatrix<double> &sol);
  void buildGroups(GModel *model, int dim, int order,
      std::vector<dgGroupOfElements*> &eGroups,
      std::vector<dgGroupOfFaces*> &fGroups,
      std::vector<dgGroupOfFaces*> &bGroups);
};


#endif
