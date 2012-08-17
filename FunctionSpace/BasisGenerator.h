#ifndef _BASISGENERATOR_H_
#define _BASISGENERATOR_H_

#include "Basis.h"

/**
    @class BasisGenerator
    @brief A bunch of class method to generate a Basis
    
    A BasisGenerator is a bunch of @em class 
    methods to generate a Basis.

    @note
    A BasisGenerator got @em only @em class @em methods,
    so it is not required to instanciate it.
*/

class BasisGenerator{
 public:
   BasisGenerator(void);
  ~BasisGenerator(void);

  static Basis* generate(int elementType, 
			 int basisType, 
			 int order);

  static Basis* triGen(int basisType, int order);
  static Basis* quaGen(int basisType, int order);
  static Basis* hexGen(int basisType, int order);
};


/**
   @fn BasisGenerator::BasisGenerator
   Instantiates a new BasisGenerator

   @note
   A BasisGenerator got @em only @em class @em methods,
   so it is not required to instanciate it.
   **

   @fn BasisGenerator::~BasisGenerator
   Deletes this BasisGenerator
   **

   @fn BasisGenerator::generate
   @param elementType The type of the element,
   on which the requested Basis will be created
   @param basisType The Basis type
   @param order The order or the requested Basis

   This method will @em instanciate the requested Basis

   @return Returns a @em pointer to a newly 
   @em instantiated Basis

   @note Element types are:
   @li @c TYPE_TRI for Triangles
   @li @c TYPE_QUA for Quadrangles
   @li @c TYPE_HEX for Hexahedrons

   @note Basis types are:
   @li @c 0 for 0-Form
   @li @c 1 for 1-Form
   @li @c 2 for 2-Form
   @li @c 3 for 3-Form
   **

   @fn BasisGenerator::triGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   This method will @em instanciate the requested Basis,
   with a @em Triangle for support
   
   @return Returns a @em pointer to a newly 
   @em instantiated Basis

   @note Basis types are:
   @li @c 0 for 0-Form
   @li @c 1 for 1-Form
   @li @c 2 for 2-Form
   @li @c 3 for 3-Form
   **

   @fn BasisGenerator::quaGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   This method will @em instanciate the requested Basis,
   with a @em Quadrangle for support

   @return Returns a @em pointer to a newly 
   @em instantiated Basis

   @note Basis types are:
   @li @c 0 for 0-Form
   @li @c 1 for 1-Form
   @li @c 2 for 2-Form
   @li @c 3 for 3-Form
   **

   @fn BasisGenerator::hexGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   This method will @em instanciate the requested Basis,
   with a @em Hexahedron for support

   @return Returns a @em pointer to a newly 
   @em instantiated Basis

   @note Basis types are:
   @li @c 0 for 0-Form
   @li @c 1 for 1-Form
   @li @c 2 for 2-Form
   @li @c 3 for 3-Form
   **
 */

#endif
