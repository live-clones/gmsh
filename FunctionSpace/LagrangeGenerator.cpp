#include "Exception.h"
#include "TriLagrangeBasis.h"
#include "LagrangeGenerator.h"

LagrangeGenerator::LagrangeGenerator(void){
}

LagrangeGenerator::~LagrangeGenerator(void){
}

LagrangeBasis* LagrangeGenerator::generate(unsigned int elementType,
					   unsigned int lagrangeOrder){
  switch(elementType){
  case TYPE_TRI: return new TriLagrangeBasis(lagrangeOrder);
  case TYPE_QUA: throw Exception("Lagrange Basis on Quads not Implemented");
  case TYPE_TET: throw Exception("Lagrange Basis on Tets not Implemented");
  case TYPE_HEX: throw Exception("Lagrange Basis on Hexs not Implemented");

  default: throw Exception("Unknown Element Type (%d) for Lagrange Basis", 
			   elementType);
  }
}
