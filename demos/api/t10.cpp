#include <gmsh.h>
#include <sstream>

// this reimplements gmsh/tutorial/t10.geo

int main(int argc, char **argv)
{
  gmshInitialize(argc, argv);
  gmshOptionSetNumber("General.Terminal", 1);

  gmshModelCreate("t1");

  int o;
  double lc = .15;
  gmshModelGeoAddPoint(1, 0.0,0.0,0, o,lc);
  gmshModelGeoAddPoint(2, 1,0.0,0, o,lc);
  gmshModelGeoAddPoint(3, 1,1,0, o,lc);
  gmshModelGeoAddPoint(4, 0,1,0, o,lc);
  gmshModelGeoAddPoint(5, 0.2,.5,0, o,lc);

  gmshModelGeoAddLine(1, 1,2, o);
  gmshModelGeoAddLine(2, 2,3, o);
  gmshModelGeoAddLine(3, 3,4, o);
  gmshModelGeoAddLine(4, 4,1, o);

  gmshModelGeoAddLineLoop(5, {1,2,3,4}, o);
  gmshModelGeoAddPlaneSurface(6, {5}, o);

  gmshModelFieldAdd(1, "Attractor");
  gmshModelFieldSetNumbers(1, "NodesList", {5});
  gmshModelFieldSetNumber(1, "NNodesByEdge", 100);
  gmshModelFieldSetNumbers(1, "EdgesList", {2});

  gmshModelFieldAdd(2, "Threshold");
  gmshModelFieldSetNumber(2, "IField", 1);
  gmshModelFieldSetNumber(2, "LcMin", lc / 30);
  gmshModelFieldSetNumber(2, "LcMax", lc);
  gmshModelFieldSetNumber(2, "DistMin", 0.15);
  gmshModelFieldSetNumber(2, "DistMax", 0.5);

  gmshModelFieldAdd(3, "MathEval");
  gmshModelFieldSetString(3, "F", "Cos(4*3.14*x) * Sin(4*3.14*y) / 10 + 0.101");

  gmshModelFieldAdd(4, "Attractor");
  gmshModelFieldSetNumbers(4, "NodesList", {1});

  gmshModelFieldAdd(5, "MathEval");
  std::stringstream stream;
  stream << "F4^3 + " << lc / 100;
  gmshModelFieldSetString(5, "F", stream.str());

  gmshModelFieldAdd(6, "Box");
  gmshModelFieldSetNumber(6, "VIn", lc / 15);
  gmshModelFieldSetNumber(6, "VOut", lc);
  gmshModelFieldSetNumber(6, "XMin", 0.3);
  gmshModelFieldSetNumber(6, "XMax", 0.6);
  gmshModelFieldSetNumber(6, "YMin", 0.3);
  gmshModelFieldSetNumber(6, "YMax", 0.6);

  gmshModelFieldAdd(7, "Min");
  gmshModelFieldSetNumbers(7, "FieldsList", {2, 3, 5, 6});

  gmshModelFieldSetAsBackground(7);

  gmshModelGeoSynchronize();
  gmshModelMesh(2);
  gmshExport("t10.msh");
  return 0;
}
