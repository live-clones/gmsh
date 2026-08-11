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

int main(int argc, char **argv)
{
  gmsh::initialize();

  gmsh::model::add("t1");

  int order = 1;
  int dim = 2;
  int tagDependent;
  int tagMaster;

  double lc = 1e-1;
  double l = .1, h=.15, w = .2;

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

    gmsh::model::mesh::setTransfiniteCurve(l1,3,"Progression",1);
    gmsh::model::mesh::setTransfiniteCurve(l2,3,"Progression",1);
    gmsh::model::mesh::setTransfiniteCurve(l3,3,"Progression",1);
    gmsh::model::mesh::setTransfiniteCurve(l4,3,"Progression",1);
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
      gmsh::model::mesh::setTransfiniteCurve(allEntities[i].second,3,"Progression",1);

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
    gmsh::model::mesh::getElementEdgeNodesCoord(elementType,nodeTagsMaster,coordNodeMaster,tagMaster,true);
    gmsh::model::mesh::getElementEdgeNodesCoord(elementType,nodeTags,coordNode,tagDependent,true);
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

  return 0;
}
