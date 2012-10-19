#include "BasisGenerator.h"
#include "GmshDefines.h"
#include "Exception.h"

#include "QuadNodeBasis.h"
#include "QuadEdgeBasis.h"

#include "TriNodeBasis.h"
#include "TriEdgeBasis.h"
#include "TriNedelecBasis.h"

#include "TetNodeBasis.h"

#include "HexNodeBasis.h"
#include "HexEdgeBasis.h"


BasisGenerator::BasisGenerator(void){
}

BasisGenerator::~BasisGenerator(void){
}

Basis* BasisGenerator::generate(int elementType, 
				int basisType, 
				int order){
  switch(elementType){
  case TYPE_TRI: return triGen(basisType, order);
  case TYPE_QUA: return quaGen(basisType, order);
  case TYPE_TET: return tetGen(basisType, order);
  case TYPE_HEX: return hexGen(basisType, order);

  default: throw Exception("Unknown Element Type (%d) for Basis Generation", 
			   elementType);
  }
}

Basis* BasisGenerator::triGen(int basisType, 
			      int order){
  switch(basisType){
  case  0: return new TriNodeBasis(order);
  case  1: 
    if (order == 0) return new TriNedelecBasis();
    else            return new TriEdgeBasis(order);

  case  2: throw Exception("2-form not implemented on Triangles");
  case  3: throw Exception("3-form not implemented on Triangles");

  default: throw Exception("There is no %d-form", basisType);
  }  
}

Basis* BasisGenerator::quaGen(int basisType, 
			      int order){
  switch(basisType){
  case  0: return new QuadNodeBasis(order);
  case  1: return new QuadEdgeBasis(order);
  case  2: throw Exception("2-form not implemented on Quads");
  case  3: throw Exception("3-form not implemented on Quads");

  default: throw Exception("There is no %d-form", basisType);
  }  
}

Basis* BasisGenerator::tetGen(int basisType, 
			      int order){
  switch(basisType){
  case  0: return new TetNodeBasis(order);
  case  1: throw Exception("1-form not implemented on Tetrahedrons");
  case  2: throw Exception("2-form not implemented on Tetrahedrons");
  case  3: throw Exception("3-form not implemented on Tetrahedrons");

  default: throw Exception("There is no %d-form", basisType);
  }  
}

Basis* BasisGenerator::hexGen(int basisType, 
			      int order){
  switch(basisType){
  case  0: return new HexNodeBasis(order);
  case  1: return new HexEdgeBasis(order);
  case  2: throw Exception("2-form not implemented on Hexs");
  case  3: throw Exception("3-form not implemented on Hexs");

  default: throw Exception("There is no %d-form", basisType);
  }  
}
