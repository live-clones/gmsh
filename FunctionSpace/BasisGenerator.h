#ifndef _BASISGENERATOR_H_
#define _BASISGENERATOR_H_

#include "Basis.h"

/** 
    @class BasisGenerator
    @brief A bunch of static method to generate basis
    
    A bunch of static method to generate basis
*/

class BasisGenerator{
 public:
   BasisGenerator(void);
  ~BasisGenerator(void);

  static Basis* generate(int elementType, 
			 int basisType, 
			 int order);

  static Basis* TriGen(int basisType, int order);
  static Basis* QuaGen(int basisType, int order);
  static Basis* HexGen(int basisType, int order);
};

#endif
