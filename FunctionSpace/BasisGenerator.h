#ifndef _BASISGENERATOR_H_
#define _BASISGENERATOR_H_

#include <string>
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
			 int order,
			 std::string family);

  static Basis* generate(int elementType, 
			 int basisType, 
			 int order);

  static Basis* linZaglmayrGen(int basisType, int order);
  static Basis* triZaglmayrGen(int basisType, int order);
  static Basis* quaZaglmayrGen(int basisType, int order);
  static Basis* tetZaglmayrGen(int basisType, int order);
  static Basis* hexZaglmayrGen(int basisType, int order);

 private:
  static Basis* generateZaglmayr(int elementType, 
				 int basisType, 
				 int order);

  static Basis* generateLagrange(int elementType, 
				 int basisType, 
				 int order);  
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

   @fn BasisGenerator::generate(int, int, int, std::string)
   @param elementType The type of the element,
   on which the requested Basis will be created
   @param basisType The Basis type
   @param order The order or the requested Basis
   @param family A string

   This method will @em instanciate the requested Basis,
   of the requested family

   @return Returns a @em pointer to a newly 
   @em instantiated Basis

   @note Element types are:
   @li @c TYPE_LIN for Lines
   @li @c TYPE_TRI for Triangles
   @li @c TYPE_QUA for Quadrangles
   @li @c TYPE_TET for Tetrahedrons
   @li @c TYPE_HEX for Hexahedrons

   @note Basis types are:
   @li @c 0 for 0-Form
   @li @c 1 for 1-Form
   @li @c 2 for 2-Form
   @li @c 3 for 3-Form

   @note Families are:
   @li @c zaglmayr for 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis Functions
   @li @c lagrange for Lagrange's Basis Functions   
   **

   @fn BasisGenerator::generate(int, int, int)
   @param elementType The type of the element,
   on which the requested Basis will be created
   @param basisType The Basis type
   @param order The order or the requested Basis

   Same as 
   BasisGenerator::generate(@c elementType, @c basisType, @c order, @c zaglmayr)

   @return Returns a @em pointer to a newly 
   @em instantiated Basis
   **

   @fn BasisGenerator::linZaglmayrGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   This method will @em instanciate the requested Basis,
   with a @em Line for support
   
   @return Returns a @em pointer to a newly 
   @em instantiated Basis

   @note Basis types are:
   @li @c 0 for 0-Form
   @li @c 1 for 1-Form
   @li @c 2 for 2-Form
   @li @c 3 for 3-Form

   @note The Basis family will be @c zaglmayr
   **

   @fn BasisGenerator::triZaglmayrGen
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

   @note The Basis family will be @c zaglmayr
   **

   @fn BasisGenerator::quaZaglmayrGen
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

   @note The Basis family will be @c zaglmayr
   **

   @fn BasisGenerator::tetZaglmayrGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   This method will @em instanciate the requested Basis,
   with a @em Tetrahedron for support
   
   @return Returns a @em pointer to a newly 
   @em instantiated Basis

   @note Basis types are:
   @li @c 0 for 0-Form
   @li @c 1 for 1-Form
   @li @c 2 for 2-Form
   @li @c 3 for 3-Form

   @note The Basis family will be @c zaglmayr
   **

   @fn BasisGenerator::hexZaglmayrGen
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

   @note The Basis family will be @c zaglmayr
   **
 */

//////////////////////
// Inline Functions //
//////////////////////

inline Basis* BasisGenerator::generate(int elementType, 
				       int basisType, 
				       int order){
  
  return BasisGenerator::generate(elementType, 
				  basisType, 
				  order,
				  "zaglmayr");
}

#endif
