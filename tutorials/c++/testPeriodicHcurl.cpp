#include <set>
#include <gmsh.h>
#include <iostream>

template <typename Type> void PrintVector( std::vector<Type> &vec ) {
    typename  std::vector<Type>::const_iterator it;
    std::cout << "(";
    for(it = vec.begin(); it != vec.end(); it++)
    {
        if(it!= vec.begin()) std::cout << ",";
        std::cout << (*it);
    }
    std::cout << ")" << std::endl;
}

void getInverse33(std::vector<double> &J, std::vector<double> &Jinv, int gp)
{
    for (int Point = 0; Point < gp; ++Point)
    {
        double a = J[9*Point + 0*3+0], b = J[9*Point + 0*3+1], c = J[9*Point + 0*3+2], d = J[9*Point + 1*3+0], e = J[9*Point + 1*3+1], f = J[9*Point + 1*3+2], g = J[9*Point + 2*3+0], h = J[9*Point + 2*3+1], i = J[9*Point + 2*3+2];

        double det = a*e*i + b*f*g + c*d*h-
                        g*e*c - h*f*a - i*d*b;

        Jinv[9*Point + 0*3+0] = 1/det * (e*i - h*f); //ei-fh
        Jinv[9*Point + 0*3+1] = 1/det * (c*h - b*i); //ch-bi
        Jinv[9*Point + 0*3+2] = 1/det * (b*f - c*e); //bf-ce

        Jinv[9*Point + 1*3+0] = 1/det * (f*g - d*i); //fg-di
        Jinv[9*Point + 1*3+1] = 1/det * (a*i - c*g); //ai-cg
        Jinv[9*Point + 1*3+2] = 1/det * (c*d - a*f); //cd-af

        Jinv[9*Point + 2*3+0] = 1/det * (d*h - e*g); //dh-eg
        Jinv[9*Point + 2*3+1] = 1/det * (b*g - a*h); //bg-ah
        Jinv[9*Point + 2*3+2] = 1/det * (a*e - b*d); //ae-bd
    }

}

void getBasisInversed(std::vector<double> &Jinv, int gp,
                      std::vector<double> &basis,std::vector<double> &newBasis)
{
  for (int i = 0; i < 3; ++i)
  {
    newBasis[i] = basis[0]*Jinv[9*gp+3*i+0]+basis[1]*Jinv[9*gp+3*i+1]+basis[2]*Jinv[9*gp+3*i+2];
  }
}

double vw(const std::vector<double> &v,
              const std::vector<double> &w)
{
    return v[0]*(w[0]) + v[1]*(w[1]) + v[2]*(w[2]);
}

int main(int argc, char **argv)
{
  gmsh::initialize();

  gmsh::model::add("t1");

  int order = 2;
  int dim = 2;
  int tagDependent;
  int tagMaster;

  double lc = 1e-1;
  double l = .1, h=.15, w = .2;
  int NbrElement = 10;

  std::vector<double> translation({1, 0, 0, 0,
                                   0, 1, 0, h, 
                                   0, 0, 1, 0, 
                                   0, 0, 0, 1});

  int tagMasterBackUp;
  if(dim==2)
  {
    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(l, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(l, h, 0, lc, 3);
    gmsh::model::geo::addPoint(0, h, 0, lc, 4);

    int l1 = gmsh::model::geo::addLine(1, 2);
    int l2 = gmsh::model::geo::addLine(3, 2);
    int l3 = gmsh::model::geo::addLine(3, 4);
    int l4 = gmsh::model::geo::addLine(4, 1);
    tagMasterBackUp = l1;

    gmsh::model::geo::addCurveLoop({l4, l1, -l2, l3}, 1);
    gmsh::model::geo::addPlaneSurface({1}, 1);

    gmsh::model::geo::synchronize();
    gmsh::model::mesh::setPeriodic(dim-1, {l3}, {l1}, translation);

    gmsh::model::mesh::setTransfiniteCurve(l1,NbrElement,"Progression",1);
    gmsh::model::mesh::setTransfiniteCurve(l2,NbrElement,"Progression",1);
    gmsh::model::mesh::setTransfiniteCurve(l3,NbrElement,"Progression",1);
    gmsh::model::mesh::setTransfiniteCurve(l4,NbrElement,"Progression",1);
    gmsh::model::mesh::setTransfiniteSurface(1);

    gmsh::model::mesh::setRecombine(2, 1);


    tagDependent = l3;
  }

  if(dim==3)
  {
    int boxTag = gmsh::model::occ::addBox(0, 0, 0, l, h, w, 1);

    gmsh::model::occ::synchronize();

    std::vector<std::pair<int, int> > allEntities;

    std::vector<std::pair<int, int> > outputMaster, outputDependent, allBoundaries;
    gmsh::model::getEntities(allEntities, 3);
    gmsh::model::getBoundary(allEntities, allBoundaries);

    std::vector<double> dist, coord;
    double x0 = l/2, y0 = 0 , z0 = h/2;

    gmsh::model::occ::getClosestEntities(x0, y0, z0, allBoundaries, outputMaster, dist, coord, 1); // Looking for only one entity
    gmsh::model::addPhysicalGroup(2, {outputMaster[0].second}, 100, "Master");

    double x1 = l/2, y1 = h , z1 = h/2;
    gmsh::model::occ::getClosestEntities(x1, y1, z1, allBoundaries, outputDependent, dist, coord, 1); // Looking for only one entity
    gmsh::model::addPhysicalGroup(2, {outputDependent[0].second}, 101, "Dependent");

    gmsh::model::mesh::setPeriodic(dim-1, {outputDependent[0].second}, {outputMaster[0].second}, translation);
    tagDependent = outputDependent[0].second;
    tagMasterBackUp = outputMaster[0].second;


    // Transfinite mesh
    gmsh::model::getEntities(allEntities, 1);
    for (int i = 0; i < allEntities.size(); ++i)
      gmsh::model::mesh::setTransfiniteCurve(allEntities[i].second,NbrElement,"Progression",1);

    gmsh::model::getEntities(allEntities, 2);
    for (int i = 0; i < allEntities.size(); ++i)
      gmsh::model::mesh::setTransfiniteSurface(allEntities[i].second);

    gmsh::model::mesh::setTransfiniteVolume(boxTag);

  }


  gmsh::model::mesh::generate(dim);
  gmsh::model::mesh::setOrder(order);






  int elementType;
  if(dim==2)
    elementType = gmsh::model::mesh::getElementType("line",order);
  else if(dim==3)
    elementType = gmsh::model::mesh::getElementType("triangle",order);

  std::string functionSpaceType = "HcurlLegendre"; // no order
  // functionSpaceType = "H1Legendre"; // H1legendre is defined by the end nodes but HCurl is edges but the numbers don't match in gui.

  functionSpaceType+=std::to_string(order-1);

  std::cout << "\nComparison of outputs for master/dependent using getPeriodicKeys for functionSpaceType:" << functionSpaceType << "\n" << std::endl;
  

  std::vector<int> typeKeys;
  std::vector<int> typeKeysMaster;
  std::vector<std::size_t> entityKeys;
  std::vector<std::size_t> entityKeysMaster;
  std::vector<double> coord;
  std::vector<double> coordMaster;
  std::vector<int> orientationSign;
  gmsh::model::mesh::getPeriodicKeys(elementType,functionSpaceType,tagDependent,tagMaster,typeKeys,typeKeysMaster,
                                      entityKeys,entityKeysMaster,coord,coordMaster,orientationSign,true);

  std::cout << "Check if the tagMaster is the right one: tagMasterBackUp" << std::endl;
  std::cout << "tagMaster: " <<tagMaster  << " tagMasterBackUp: " <<tagMasterBackUp << std::endl;

  std::cout << "\nCheck the keys of the master and the dependent to see the effect getPeriodicKeys has on it" << std::endl;
  PrintVector(entityKeysMaster);
  PrintVector(entityKeys);

  std::cout << "\nCheck the Typekeys of the master and the dependent to see the effect getPeriodicKeys has on it" << std::endl;
  PrintVector(typeKeysMaster);
  PrintVector(typeKeys);

  std::cout << " \nCoordinates of the keys: " << std::endl;
  PrintVector(coord);
  PrintVector(coordMaster);

  std::cout << " \nFutur vector returning the link +/-1 between the keys: orientationSign: " << std::endl;
  PrintVector(orientationSign);

  std::vector<int> basisFunctionsOrientationMaster;
  gmsh::model::mesh::getBasisFunctionsOrientation(elementType,functionSpaceType,basisFunctionsOrientationMaster,tagMaster);
  std::vector<int> basisFunctionsOrientationDependent;
  gmsh::model::mesh::getBasisFunctionsOrientation(elementType,functionSpaceType,basisFunctionsOrientationDependent,tagDependent);

  std::cout << "\nReturn orientation of the basis function for dependent and master" << std::endl;
  PrintVector(basisFunctionsOrientationMaster);
  PrintVector(basisFunctionsOrientationDependent);





  std::vector<std::size_t> nodeTagsMaster, nodeTags;
  std::vector<double> coordNodeMaster,coordNode;
  if(dim==2)
  {
    std::size_t numElements;
    gmsh::model::mesh::getElementEdgeNodesCoord(elementType,nodeTagsMaster,coordNodeMaster,numElements,tagMaster,true);
    gmsh::model::mesh::getElementEdgeNodesCoord(elementType,nodeTags,coordNode,numElements,tagDependent,true);
  }
  else if(dim==3)
  {
    int elementType3D = gmsh::model::mesh::getElementType("tetrahedron",order);
    gmsh::model::mesh::getElementFaceNodesCoord(elementType,elementType,nodeTagsMaster,coordNodeMaster,tagMaster,true);
    gmsh::model::mesh::getElementFaceNodesCoord(elementType,elementType,nodeTags,coordNode,tagDependent,true);
  }
  std::cout << "\nReturn the coordinates of the nodes of the edge/face for dependent and master" << std::endl;
  PrintVector(coordNodeMaster);
  PrintVector(coordNode);



  if(dim==3)
  {
    std::vector<std::size_t> edgeNodesMaster, edgeNodesDependent;
    gmsh::model::mesh::getElementEdgeNodes(elementType, edgeNodesDependent, tagDependent);
    gmsh::model::mesh::getElementEdgeNodes(elementType, edgeNodesMaster, tagMasterBackUp);

    gmsh::model::mesh::createEdges();

    std::vector<std::size_t> edgeTagsMaster,edgeTagsDependent;
    std::vector<int> edgeOrientations;
    gmsh::model::mesh::getEdges(edgeNodesMaster, edgeTagsMaster, edgeOrientations);
    gmsh::model::mesh::getEdges(edgeNodesDependent, edgeTagsDependent, edgeOrientations);

    std::cout << " \n The keys for edges in 3D have tags created for this need, not visible in ht GUI: " << std::endl;
    PrintVector(edgeTagsMaster);
    PrintVector(edgeTagsDependent);
  }


  gmsh::write("t1.msh");

  std::set<std::string> args(argv, argv + argc);
  if(!args.count("-nopopup")) gmsh::fltk::run();

  gmsh::finalize();



  /*

  std::unordered_map<int,std::unordered_map<int,int>> dof2dof2value;
  std::unordered_map<int,int> dof2value;
  std::vector<double> elementTypes,elementTags,nodeTags,localCoords,weights,jacobians,
                      determinants,Global_GP_coord,basisFunctionsOrientation,
                      basisFunctions,curl_basisFunctions,basisDof,basisDof2,newBasis,newBasis2,invJacobian,keys;
  int numComponents, numOrientations;
  double vector, somme, sommeSource;

  double term, termCurl, termSource;


  gmsh::model::getEntities(entityTags, dim);
  entityTags.push_back(tagSource);
  
  for (int i = 0; i < entityTags.size(); ++i)
  {
    gmsh::model::mesh::getElements(elementTypes, elementTags, nodeTags, dimension, EntityTags[j]);

    for (int e = 0; e < elementTags.size(); ++e)
    {
      gmsh::model::mesh::getIntegrationPoints(elementTypes[e],gauss,localCoords, weights);
      gmsh::model::mesh::getJacobians(elementTypes[e],localCoords,jacobians,determinants,Global_GP_coord,EntityTags[j]);

      gmsh::model::mesh::getBasisFunctions(elementTypes[e],localCoords,functionSpaceType,numComponents,basisFunctions,numOrientations);
      gmsh::model::mesh::getBasisFunctions(elementTypes[e],localCoords,curl_functionSpaceType,numComponents,curl_basisFunctions,numOrientations);

      gmsh::model::mesh::getBasisFunctionsOrientation(elementTypes[e],functionSpaceType,basisFunctionsOrientation,entityTags[i]);
      gmsh::model::mesh::getKeysForElement();

      getInverse33(Jacobian,invJacobian,weights.size());
      for (int dof = 0; dof < keys.size(); ++dof)
      {
        sommeSource=0;
        for (int dof2 = 0; dof2 < keys.size(); ++dof2)
        {
          somme=0;
          for (int g = 0; g < weights.size(); ++g)
          {
            basisDof[0]=basisFunctions[dof,orientation,g+0];
            basisDof[0]=basisFunctions[dof,orientation,g+0];
            basisDof[0]=basisFunctions[dof,orientation,g+0];
            getBasisInversed(invJacobian,g,basisDof,newBasis);

            basisDof2[0]=basisFunctions[dof2,orientation,g+0];
            basisDof2[0]=basisFunctions[dof2,orientation,g+0];
            basisDof2[0]=basisFunctions[dof2,orientation,g+0];
            getBasisInversed(invJacobian,g,basisDof2,newBasis2);

            vectorProduct = vw(newBasis,newBasis2);
            somme+=weights[g] * vectorProduct * determinant[] * term;


// if curl, how do I do the invJacobians product to nabla?
            basisDof[0]=basisFunctions[dof,orientation,g+0];
            basisDof[0]=basisFunctions[dof,orientation,g+0];
            basisDof[0]=basisFunctions[dof,orientation,g+0];
            getBasisInversed(invJacobian,g,basisDof,newBasis);

            basisDof2[0]=basisFunctions[dof2,orientation,g+0];
            basisDof2[0]=basisFunctions[dof2,orientation,g+0];
            basisDof2[0]=basisFunctions[dof2,orientation,g+0];
            getBasisInversed(invJacobian,g,basisDof2,newBasis2);

            vectorProduct = vw(newBasis,newBasis2);
            somme+=weights[g] * vectorProduct * determinant[] * termCurl;


            if(entityTags[i] == tagSource && dof == 0)
            {
              vectorProduct = invJacobian * basisFunctions[dof2];
              sommeSource+=weights[g] * vectorProduct * determinant[] * termSource;
            }


          }
          dof2dof2value.insert()
        }
        dof2value.insert()
      }
    }
  }

  // Periodicity
  for (int i = 0; i < entityKeysMaster.size(); ++i)
  {
    dof2dof2value[entityKeysMaster[i]]=dof2dof2value[entityKeys[i]];
  }


// How to apply Dirichlet and print the solution:
      
    ->  Mii=1 & Ji=Eimp

*/

  return 0;
}
