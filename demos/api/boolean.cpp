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

  std::vector<int> t = {1,2,3,4,5,6,7,8};
  gmshModelOccAddBox(t[0], -R,-R,-R, 2*R,2*R,2*R);
  gmshModelOccAddSphere(t[1], 0,0,0,Rt);

  std::vector<std::pair<int, int> > o;
  std::vector<std::vector<std::pair<int, int> > > om;

  gmshModelOccBooleanIntersection(t[2], {{3, t[0]}}, {{3, t[1]}}, o, om);
  gmshModelOccAddCylinder(t[3], -2*R,0,0, 4*R,0,0, Rs);
  gmshModelOccAddCylinder(t[4], 0,-2*R,0, 0,4*R,0, Rs);
  gmshModelOccAddCylinder(t[5], 0,0,-2*R, 0,0,4*R, Rs);
  gmshModelOccBooleanUnion(t[6], {{3, t[3]}, {3, t[4]}}, {{3, t[5]}}, o, om);
  gmshModelOccBooleanDifference(t[7], {{3, t[2]}}, {{3, t[6]}}, o, om);

  gmshModelOccSynchronize();

  gmshModelMesh(3);

  gmshExport("boolean.msh");

  gmshFinalize();
  return 0;
}
