#ifndef _BASISGENERATOR_H_
#define _BASISGENERATOR_H_

#include <string>
#include "BasisLocal.h"

/**
    @class BasisGenerator
    @brief A bunch of class method to generate a Local Basis

    A BasisGenerator is a bunch of @em class
    methods to generate a Local Basis (BasisLocal).

    @note
    A BasisGenerator got @em only @em class @em methods,
    so it is not required to instanciate it.
*/

class BasisGenerator{
 public:
   BasisGenerator(void);
  ~BasisGenerator(void);

  static BasisLocal* generate(unsigned int elementType,
			      unsigned int basisType,
			      unsigned int order,
			      std::string family);

  static BasisLocal* generate(unsigned int elementType,
			      unsigned int basisType,
			      unsigned int order);

  static BasisLocal* linHierarchicalGen(unsigned int basisType, unsigned int order);
  static BasisLocal* triHierarchicalGen(unsigned int basisType, unsigned int order);
  static BasisLocal* quaHierarchicalGen(unsigned int basisType, unsigned int order);
  static BasisLocal* tetHierarchicalGen(unsigned int basisType, unsigned int order);
  static BasisLocal* hexHierarchicalGen(unsigned int basisType, unsigned int order);

 private:
  static BasisLocal* generateHierarchical(unsigned int elementType,
					  unsigned int basisType,
					  unsigned int order);

  static BasisLocal* generateLagrange(unsigned int elementType,
				      unsigned int basisType,
				      unsigned int order);
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

   @fn BasisGenerator::generate(unsigned int, unsigned int, unsigned int, std::string)
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
   @li @c hierarchical for
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis Functions
   @li @c lagrange for Lagrange's Basis Functions
   **

   @fn BasisGenerator::generate(unsigned int, unsigned int, unsigned int)
   @param elementType The type of the element,
   on which the requested Basis will be created
   @param basisType The Basis type
   @param order The order or the requested Basis

   Same as
   BasisGenerator::generate(@c elementType, @c basisType, @c order, @c hierarchical)

   @return Returns a @em pointer to a newly
   @em instantiated Basis
   **

   @fn BasisGenerator::linHierarchicalGen
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

   @note The Basis family will be @c hierarchical
   **

   @fn BasisGenerator::triHierarchicalGen
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

   @note The Basis family will be @c hierarchical
   **

   @fn BasisGenerator::quaHierarchicalGen
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

   @note The Basis family will be @c hierarchical
   **

   @fn BasisGenerator::tetHierarchicalGen
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

   @note The Basis family will be @c hierarchical
   **

   @fn BasisGenerator::hexHierarchicalGen
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

   @note The Basis family will be @c hierarchical
   **
 */

//////////////////////
// Inline Functions //
//////////////////////

inline BasisLocal* BasisGenerator::generate(unsigned int elementType,
					    unsigned int basisType,
					    unsigned int order){

  return BasisGenerator::generate(elementType,
				  basisType,
				  order,
				  "hierarchical");
}

#endif
