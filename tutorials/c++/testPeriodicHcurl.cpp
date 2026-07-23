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

  double lc = 1e-2;
  gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
  gmsh::model::geo::addPoint(.1, 0, 0, lc, 2);
  gmsh::model::geo::addPoint(.1, .15, 0, lc, 3);
  gmsh::model::geo::addPoint(0, .15, 0, lc, 4);

  int l1 = gmsh::model::geo::addLine(1, 2);
  int l2 = gmsh::model::geo::addLine(3, 2);
  int l3 = gmsh::model::geo::addLine(3, 4);
  int l4 = gmsh::model::geo::addLine(4, 1);

  gmsh::model::geo::addCurveLoop({l4, l1, -l2, l3}, 1);

  gmsh::model::geo::addPlaneSurface({1}, 1);

  gmsh::model::geo::synchronize();


  std::vector<double> translation({1, 0, 0, 0,
                                  0, 1, 0, 0.15, 
                                  0, 0, 1, 0, 
                                  0, 0, 0, 1});


  gmsh::model::mesh::setPeriodic(1, {l3}, {l1}, translation);

  gmsh::model::addPhysicalGroup(1, {l1, l2, l3, l4}, 5);
  gmsh::model::addPhysicalGroup(2, {1}, -1, "My surface");

  gmsh::model::mesh::generate(2);


  int elementType = gmsh::model::mesh::getElementType("line", 1);
  std::string functionSpaceType = "HcurlLegendre"; // no order
  functionSpaceType = "H1Legendre";
  int tagSlave = l3;
  int tagMaster;
  std::vector<int> typeKeys;
  std::vector<int> typeKeysMaster;
  std::vector<std::size_t> entityKeys;
  std::vector<std::size_t> entityKeysMaster;
  std::vector<double> coord;
  std::vector<double> coordMaster;
  std::vector<int> orientationSign;
  gmsh::model::mesh::getPeriodicKeys(elementType,functionSpaceType,tagSlave,tagMaster,typeKeys,typeKeysMaster,
                                      entityKeys,entityKeysMaster,coord,coordMaster,orientationSign,true);
  std::cout << "Out, I have: " <<tagMaster << std::endl;
  PrintVector(entityKeysMaster);
  PrintVector(entityKeys);

  // PrintVector(typeKeysMaster);
  // PrintVector(typeKeys);

  std::cout << " coordinates are ok" << std::endl;
  // PrintVector(coordMaster);
  // PrintVector(coord);

  std::cout << " orientationSign: " << std::endl;
  PrintVector(orientationSign);

  std::vector<int> basisFunctionsOrientationMaster;
  gmsh::model::mesh::getBasisFunctionsOrientation(elementType,functionSpaceType,basisFunctionsOrientationMaster,tagMaster);
  PrintVector(basisFunctionsOrientationMaster);
  std::vector<int> basisFunctionsOrientationDependent;
  gmsh::model::mesh::getBasisFunctionsOrientation(elementType,functionSpaceType,basisFunctionsOrientationDependent,tagSlave);
  PrintVector(basisFunctionsOrientationDependent);

  std::cout << " The reference: " << std::endl;
  tagMaster = l1;
  gmsh::model::mesh::getKeys(elementType, functionSpaceType, typeKeysMaster, entityKeysMaster,coordMaster, tagMaster);
  gmsh::model::mesh::getKeys(elementType, functionSpaceType, typeKeys, entityKeys,coord, tagSlave);
  PrintVector(entityKeysMaster);
  PrintVector(entityKeys);



  gmsh::write("t1.msh");

  std::set<std::string> args(argv, argv + argc);
  if(!args.count("-nopopup")) gmsh::fltk::run();

  gmsh::finalize();

  return 0;
}
