#ifndef _BASISGENERATOR_H_
#define _BASISGENERATOR_H_

#include <string>
#include "BasisLocal.h"

/**
    @class BasisGenerator
    @brief A bunch of class method to generate a Local Basis

    A BasisGenerator is a bunch of class methods to generate a local Basis.
*/

class BasisGenerator{
 public:
   BasisGenerator(void);
  ~BasisGenerator(void);

  static BasisLocal* generate(size_t elementType,
                              size_t basisType,
                              size_t order,
                              std::string family);

  static BasisLocal* generate(size_t elementType,
                              size_t basisType,
                              size_t order);

  static BasisLocal* linHierarchicalGen(size_t basisType, size_t order);
  static BasisLocal* triHierarchicalGen(size_t basisType, size_t order);
  static BasisLocal* quaHierarchicalGen(size_t basisType, size_t order);
  static BasisLocal* tetHierarchicalGen(size_t basisType, size_t order);
  static BasisLocal* hexHierarchicalGen(size_t basisType, size_t order);

 private:
  static BasisLocal* generateHierarchical(size_t elementType,
                                          size_t basisType,
                                          size_t order);

  static BasisLocal* generateLagrange(size_t elementType,
                                      size_t basisType,
                                      size_t order);
};


/**
   @fn BasisGenerator::BasisGenerator
   Instantiates a new BasisGenerator

   This class got only class methods, so it is not required to instanciate it.
   **

   @fn BasisGenerator::~BasisGenerator
   Deletes this BasisGenerator
   **

   @fn BasisGenerator::generate(size_t, size_t, size_t, std::string)
   @param elementType The element type of the requested Basis
   @param basisType The Basis type
   @param order The order or the requested Basis
   @param family A string

   This method will instanciate the requested Basis of the requested family

   @return Returns a pointer to a newly instantiated Basis

   Element types are:
   @li @c TYPE_LIN for Lines
   @li @c TYPE_TRI for Triangles
   @li @c TYPE_QUA for Quadrangles
   @li @c TYPE_TET for Tetrahedrons
   @li @c TYPE_HEX for Hexahedrons

   Basis types are:
   @li 0 for 0-Form
   @li 1 for 1-Form
   @li 2 for 2-Form
   @li 3 for 3-Form

   Families are:
   @li hierarchical for
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis functions
   @li lagrange for Lagrange's Basis functions
   **

   @fn BasisGenerator::generate(size_t, size_t, size_t)
   @param elementType The element type of the requested Basis
   @param basisType The Basis type
   @param order The order or the requested Basis

   Same as
   BasisGenerator::generate(elementType, basisType, order, @em hierarchical)

   @return Returns a pointer to a newly instantiated Basis
   **

   @fn BasisGenerator::linHierarchicalGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   This method will instanciate the requested Basis with a Line support

   @return Returns a pointer to a newly instantiated Basis

   Basis types are:
   @li 0 for 0-Form
   @li 1 for 1-Form
   @li 2 for 2-Form
   @li 3 for 3-Form

   The Basis family will be hierarchical
   **

   @fn BasisGenerator::triHierarchicalGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   Same as BasisGenerator::linHierarchicalGen() but for Triangles
   **

   @fn BasisGenerator::quaHierarchicalGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   Same as BasisGenerator::linHierarchicalGen() but for Quadrangles
   **

   @fn BasisGenerator::tetHierarchicalGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   Same as BasisGenerator::linHierarchicalGen() but for Tetrahedra
   **

   @fn BasisGenerator::hexHierarchicalGen
   @param basisType The Basis type
   @param order The order or the requested Basis

   Same as BasisGenerator::linHierarchicalGen() but for Hexahedra
 */

//////////////////////
// Inline Functions //
//////////////////////

inline BasisLocal* BasisGenerator::generate(size_t elementType,
                                            size_t basisType,
                                            size_t order){

  return BasisGenerator::generate(elementType,
                                  basisType,
                                  order,
                                  "hierarchical");
}

#endif
