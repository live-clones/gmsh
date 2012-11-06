#ifndef _LAGRANGEGENERATOR_H_
#define _LAGRANGEGENERATOR_H_

#include "LagrangeBasis.h"

/**
   @class LagrangeGenerator
   @brief Generates a Lagrange Basis 

   Generates a Lagrange Basis
 */

class LagrangeGenerator{
 public:
   LagrangeGenerator(void);
  ~LagrangeGenerator(void);

  static LagrangeBasis* generate(unsigned int elementType,
				 unsigned int lagrangeOrder);
};

/**
   @fn LagrangeGenerator::LagrangeGenerator
   Instantiates a new LagrangeGenerator

   @note
   A LagrangeGenerator got @em only @em class @em methods,
   so it is not required to instanciate it.
   **

   @fn LagrangeGenerator::~LagrangeGenerator
   Deletes this LagrangeGenerator
   **

   @fn LagrangeGenerator::generate
   @param elementType The type of the element,
   on which the requested LagrangeBasis will be created
   @param order The order or the requested LagrangeBasis

   This method will @em instanciate the requested LagrangeBasis

   @return Returns a @em pointer to a newly 
   @em instantiated LagrangeBasis

   @note Element types are:
   @li @c TYPE_TRI for Triangles
   @li @c TYPE_QUA for Quadrangles
   @li @c TYPE_TET for Tetrahedrons
   @li @c TYPE_HEX for Hexahedrons
*/

#endif
