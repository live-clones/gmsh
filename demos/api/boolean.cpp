#include <gmsh.h>

// this reimplements gmsh/demos/boolean/boolean.geo

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("boolean");

  // from http://en.wikipedia.org/wiki/Constructive_solid_geometry

  gmshOptionSetNumber("Mesh.Algorithm", 6);
  gmshOptionSetNumber("Mesh.CharacteristicLengthMin", 0.4);
  gmshOptionSetNumber("Mesh.CharacteristicLengthMax", 0.4);

  double R = 1.4, Rs = R*.7, Rt = R*1.25;

  std::vector<int> tag = {1,2,3,4,5,6,7,8};
  gmshModelOccAddBox(tag[0], -R,-R,-R, 2*R,2*R,2*R);
  gmshModelOccAddSphere(tag[1], 0,0,0,Rt);

  std::vector<std::pair<int, int> > obj, tool, out;
  std::vector<std::vector<std::pair<int, int> > > outMap;

  obj.push_back(std::pair<int, int>(3, 1));
  tool.push_back(std::pair<int, int>(3, 2));
  gmshModelOccBooleanIntersection(tag[2], obj, tool, out, outMap, true, true);

  gmshModelOccAddCylinder(tag[3], -2*R,0,0, 4*R,0,0, Rs);
  gmshModelOccAddCylinder(tag[4], 0,-2*R,0, 0,4*R,0, Rs);
  gmshModelOccAddCylinder(tag[5], 0,0,-2*R, 0,0,4*R, Rs);

  obj.clear(); tool.clear();
  obj.push_back(std::pair<int, int>(3, 4));
  tool.push_back(std::pair<int, int>(3, 5));
  tool.push_back(std::pair<int, int>(3, 6));
  gmshModelOccBooleanUnion(tag[6], obj, tool, out, outMap, true, true);

  obj.clear(); tool.clear();
  obj.push_back(std::pair<int, int>(3, 3));
  tool.push_back(std::pair<int, int>(3, 7));
  gmshModelOccBooleanDifference(tag[7], obj, tool, out, outMap, true, true);

  gmshModelOccSynchronize();

  gmshModelMesh(3);

  gmshExport("boolean.msh");

  gmshFinalize();
  return 0;
}
