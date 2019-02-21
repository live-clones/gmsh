#include "HierarchicalBasisGenerator.h"

namespace HierarchicalBasis{

namespace{
//Each physical mesh edge will  be assigned a unique orientation,and all edges of physical mesh quadrilaterals will be equipped with an orientation ag , indicating whether the image of the corresponding edge of the reference domain through the reference map has the same or opposite orientation
//The global edge orientation always pointing from the vertex with the lower global vertex number to the one with the higher one.

  std::vector<int>  getOrientationFlag(MElement* e){
    int numberVertices=e->getNumVertices();
    std::map<int , int> indiceDictionary;
    for(int i=0;i<numberVertices;i++){
      indiceDictionary[e->getVertex(i)->getNum()]=i;
    }
    int numberEdge=e->getNumEdges();
    std::vector<int> flag(numberEdge);
    for(int i=0;i<numberEdge;i++){
      MEdge edge=e->getEdge(i);
// je suppose ici que j'ai un quadrangle, il faudra mettre un switch case pour les differents cas (donc il faut connaitre le type de l'élément avec getType mais ou sont défini TYPE_QUA par exemple
      if (MQuadrangle::edges_quad(i,0)!=indiceDictionary.find( edge.getMinVertex()->getNum())->second){

	flag[i]=-1;
     }
     else{
	flag[i]=1;
     }
  }
  return flag;
}
}



}



GMSH_API void hierarchicalBasisGeneratorForElements(const int tag,
                                                          const int dim,
                                                          const std::string & integrationType,
                                                          const std::string & elementType,
                                                          std::vector<double> & hierarchicalBasis,
						    std::vector<double> & weight){





GMSH_API void gmsh::model::mesh::getBasisFunctions(
  const int elementType, const std::string &integrationType,
  const std::string &functionSpaceType, std::vector<double> &integrationPoints,
  int &numComponents, std::vector<double> &basisFunctions)
{


  hierarchicalBasis.clear();
  weight.clear();
  vector<int> elementTags;
  vector<int> nodeTags;
  gmsh::model::mesh::getElementsByType(elementType,elementTags, nodeTags, tag);
  for(int i=0;i<elementTags.size();i++){
	MElement *e= GModel::current()->getMeshElementByTag(elementTag);
        int order=e->getPolynomialOrder() 
   
  }
