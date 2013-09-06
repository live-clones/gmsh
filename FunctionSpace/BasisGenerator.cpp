#include "BasisGenerator.h"
#include "GmshDefines.h"
#include "Exception.h"

#include "LineNodeBasis.h"
#include "LineEdgeBasis.h"
#include "LineNedelecBasis.h"
#include "LineLagrangeBasis.h"

#include "TriNodeBasis.h"
#include "TriEdgeBasis.h"
#include "TriNedelecBasis.h"
#include "TriLagrangeBasis.h"

#include "QuadNodeBasis.h"
#include "QuadEdgeBasis.h"
#include "QuadNedelecBasis.h"
#include "QuadLagrangeBasis.h"

#include "TetNodeBasis.h"
#include "TetEdgeBasis.h"
#include "TetNedelecBasis.h"
#include "TetLagrangeBasis.h"

#include "HexNodeBasis.h"
#include "HexEdgeBasis.h"
#include "HexLagrangeBasis.h"

BasisGenerator::BasisGenerator(void){
}

BasisGenerator::~BasisGenerator(void){
}

BasisLocal* BasisGenerator::generate(size_t elementType,
                                     size_t basisType,
                                     size_t order,
                                     std::string family){

  if(!family.compare(std::string("hierarchical")))
    return generateHierarchical(elementType, basisType, order);

  else if(!family.compare(std::string("lagrange")))
    return generateLagrange(elementType, basisType, order);

  else
    throw Exception("Unknwown Basis Family: %s", family.c_str());
}

BasisLocal* BasisGenerator::generateHierarchical(size_t elementType,
                                                 size_t basisType,
                                                 size_t order){
  switch(elementType){
  case TYPE_LIN: return linHierarchicalGen(basisType, order);
  case TYPE_TRI: return triHierarchicalGen(basisType, order);
  case TYPE_QUA: return quaHierarchicalGen(basisType, order);
  case TYPE_TET: return tetHierarchicalGen(basisType, order);
  case TYPE_HEX: return hexHierarchicalGen(basisType, order);

  default: throw Exception("Unknown Element Type (%d) for Basis Generation",
                           elementType);
  }
}

BasisLocal* BasisGenerator::generateLagrange(size_t elementType,
                                             size_t basisType,
                                             size_t order){
  if(basisType != 0)
    throw
      Exception("Cannot Have a %d-Form Lagrange Basis (0-Form only)",
                basisType);

  switch(elementType){
  case TYPE_LIN: return new LineLagrangeBasis(order);
  case TYPE_TRI: return new TriLagrangeBasis(order);
  case TYPE_QUA: return new QuadLagrangeBasis(order);
  case TYPE_TET: return new TetLagrangeBasis(order);
  case TYPE_HEX: return new HexLagrangeBasis(order);

  default: throw Exception("Unknown Element Type (%d) for Basis Generation",
                           elementType);
  }
}

BasisLocal* BasisGenerator::linHierarchicalGen(size_t basisType,
                                               size_t order){
  switch(basisType){
  case 0: return new LineNodeBasis(order);
  case 1:
    if (order == 0) return new LineNedelecBasis();
    else            return new LineEdgeBasis(order);

  case 2: throw Exception("2-form not implemented on Lines");
  case 3: throw Exception("3-form not implemented on Lines");

  default: throw Exception("There is no %d-form", basisType);
  }
}

BasisLocal* BasisGenerator::triHierarchicalGen(size_t basisType,
                                               size_t order){
  switch(basisType){
  case 0: return new TriNodeBasis(order);
  case 1:
    if (order == 0) return new TriNedelecBasis();
    else            return new TriEdgeBasis(order);

  case 2: throw Exception("2-form not implemented on Triangles");
  case 3: throw Exception("3-form not implemented on Triangles");

  default: throw Exception("There is no %d-form", basisType);
  }
}

BasisLocal* BasisGenerator::quaHierarchicalGen(size_t basisType,
                                               size_t order){
  switch(basisType){
  case 0: return new QuadNodeBasis(order);
  case 1:
    if (order == 0) return new QuadNedelecBasis();
    else            return new QuadEdgeBasis(order);

  case 2: throw Exception("2-form not implemented on Quads");
  case 3: throw Exception("3-form not implemented on Quads");

  default: throw Exception("There is no %d-form", basisType);
  }
}

BasisLocal* BasisGenerator::tetHierarchicalGen(size_t basisType,
                                               size_t order){
  switch(basisType){
  case 0: return new TetNodeBasis(order);
  case 1:
    if (order == 0) return new TetNedelecBasis();
    else            return new TetEdgeBasis(order);

  case 2: throw Exception("2-form not implemented on Tetrahedrons");
  case 3: throw Exception("3-form not implemented on Tetrahedrons");

  default: throw Exception("There is no %d-form", basisType);
  }
}

BasisLocal* BasisGenerator::hexHierarchicalGen(size_t basisType,
                                               size_t order){
  switch(basisType){
  case 0: return new HexNodeBasis(order);
    //case 1: return new HexEdgeBasis(order);
  case 1: throw Exception("1-form not implemented on Hexs");
  case 2: throw Exception("2-form not implemented on Hexs");
  case 3: throw Exception("3-form not implemented on Hexs");

  default: throw Exception("There is no %d-form", basisType);
  }
}
