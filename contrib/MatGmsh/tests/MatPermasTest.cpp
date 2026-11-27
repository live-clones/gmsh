// The PERMAS export of a shell mesh with thickness groups, and its reading
#include "MatPermas.h"
#include "MatPipeline.h"
#include "gmsh.h"
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace matgmsh_native;
namespace {
void check(bool condition, const std::string &message)
{
  if(!condition) throw std::runtime_error(message);
}

std::string text(const std::string &file)
{
  std::ifstream f(file);
  std::stringstream s;
  s << f.rdbuf();
  return s.str();
}

bool startsWith(const std::string &s, const std::string &start)
{
  return !s.compare(0, start.size(), start);
}

bool endsWith(const std::string &s, const std::string &end)
{
  return s.size() >= end.size() && !s.compare(s.size() - end.size(), end.size(), end);
}

std::string line(const char *format, ...)
{
  char s[256];
  va_list args;
  va_start(args, format);
  vsnprintf(s, sizeof(s), format, args);
  va_end(args);
  return s;
}

// Two triangles and a quadrangle. The thickness at the nodes: 1.1 as a float
// (1.100000024) at nodes 1, 2, 3, 1.25 at node 4, 2.25 at nodes 5, 6, 7; the
// mean at the corners: 1.1 (a float), 1.15 and 2, in the sets thick_1.100,
// thick_1.200 and thick_2.000. The same file from gmsh::write and a view of
// node data, and read back.
void thicknessSets()
{
  gmsh::model::add("permas");
  gmsh::model::addDiscreteEntity(2, 1);
  const std::vector<std::size_t> nodes = {1, 2, 3, 4, 5, 6, 7};
  gmsh::model::mesh::addNodes(2, 1, nodes,
                              {0, 0, 0,  1.5, -0.25, 1e-7,  0, 1, 0,  1, 1, 0,
                               2, 1, 0,  2, 2, 0,  1, 2, 0});
  gmsh::model::mesh::addElementsByType(1, 2, {10, 11}, {1, 2, 3, 2, 4, 3});
  gmsh::model::mesh::addElementsByType(1, 3, {12}, {4, 5, 6, 7});
  const double f = (double)1.1f;
  const std::vector<double> values = {f, f, f, 1.25, 2.25, 2.25, 2.25};

  PermasOptions options;
  PermasReport report;
  std::string error;
  check(writePermas(currentModel(), "MatPermasTest.dat", nodalThickness(nodes, values),
                    options, report, error),
        "write: " + error);
  check(report.nodes == 7 && report.triangles == 2 && report.quadrangles == 1 &&
          report.sets == 3 && !report.withoutThickness,
        "the report");
  check(report.minThickness == 1.1 && report.maxThickness == 2., "the range of the sets");
  const std::string dat = text("MatPermasTest.dat");
  check(startsWith(dat, "!\n$ENTER COMPONENT NAME = AUTO_MESH\n!\n$STRUCTURE\n$COOR \n"),
        "the header");
  check(dat.find(line("%12d %24s %24s %24s \n", 2, "1.5", "-0.25", "1.E-7")) !=
          std::string::npos,
        "the line of a node");
  // the quadrangles before the triangles, by set
  const std::size_t quad = dat.find("$ELEMENT TYPE = QUAD4 ESET = thick_2.000\n"),
                    tri1 = dat.find("$ELEMENT TYPE = TRIA3 ESET = thick_1.100\n"),
                    tri2 = dat.find("$ELEMENT TYPE = TRIA3 ESET = thick_1.200\n");
  check(quad != std::string::npos && quad < tri1 && tri1 < tri2, "the element blocks");
  check(dat.find(line("%12d %12d %12d %12d %12d \n", 12, 4, 5, 6, 7)) != std::string::npos,
        "the line of an element");
  check(dat.find(line("%-40s %24s \n", "thick_1.100", "1.1")) != std::string::npos &&
          dat.find(line("%-40s %24s \n", "thick_2.000", "2.")) != std::string::npos,
        "the thickness of the sets");
  check(dat.find("$ELPROP") == std::string::npos, "no material");
  check(endsWith(dat, "!\n$END SYSTEM\n$EXIT COMPONENT\n!\n$FIN\n"), "the end");

  // the material of each set
  options.material = "STEEL";
  check(writePermas(currentModel(), "MatPermasTest_material.dat",
                    nodalThickness(nodes, values), options, report, error),
        "write with a material: " + error);
  check(text("MatPermasTest_material.dat")
            .find(line("%-41s GEODAT = %-41s MATERIAL =  %s \n", "thick_1.200",
                       "thick_1.200", "STEEL")) != std::string::npos,
        "the material of a set");

  // the thickness of a view of node data on the model (File > Export)
  const int view = gmsh::view::add("MAT mid-surface thickness");
  std::vector<std::vector<double> > data;
  for(double v : values) data.push_back({v});
  gmsh::view::addModelData(view, 0, "permas", "NodeData", nodes, data);
  gmsh::write("MatPermasTest_view.dat");
  check(text("MatPermasTest_view.dat") == dat, "the export of the thickness of a view");

  // read back: a physical surface per set and the thickness of the elements
  gmsh::open("MatPermasTest.dat");
  gmsh::vectorpair groups;
  gmsh::model::getPhysicalGroups(groups, 2);
  std::vector<std::string> names;
  for(auto &g : groups) {
    std::string name;
    gmsh::model::getPhysicalName(2, g.second, name);
    names.push_back(name);
  }
  check(names == std::vector<std::string>({"thick_2.000", "thick_1.100", "thick_1.200"}),
        "the sets read");
  std::vector<int> types;
  std::vector<std::vector<std::size_t> > tags, elementNodes;
  gmsh::model::mesh::getElements(types, tags, elementNodes, 2);
  std::size_t elements = 0;
  for(auto &t : tags) elements += t.size();
  check(elements == 3, "the elements read");
  // (the model and the view written are still there: gmsh::open adds a model)
  std::vector<int> views;
  gmsh::view::getTags(views);
  int thicknessView = -1;
  for(int v : views) {
    std::string name;
    gmsh::view::option::getString(v, "Name", name);
    if(name == "PERMAS thickness") thicknessView = v;
  }
  check(thicknessView >= 0, "the view of the thickness");
  std::string type;
  std::vector<std::size_t> read;
  std::vector<std::vector<double> > thickness;
  double time;
  int components;
  gmsh::view::getModelData(thicknessView, 0, type, read, thickness, time, components);
  check(type == "ElementData" && read.size() == 3, "element data");
  for(std::size_t i = 0; i < read.size(); i++) {
    const double expected = read[i] == 10 ? 1.1 : read[i] == 11 ? 1.2 : 2.;
    check(thickness[i][0] == expected, "the thickness of an element read");
  }
  for(const char *file :
      {"MatPermasTest.dat", "MatPermasTest_material.dat", "MatPermasTest_view.dat"})
    std::remove(file);
}
} // namespace

int main()
{
  try {
    gmsh::initialize();
    gmsh::option::setNumber("General.Terminal", 0);
    thicknessSets();
    gmsh::finalize();
    std::cout << "MatPermas: 1 test passed\n";
    return 0;
  }
  catch(const std::exception &e) {
    std::cerr << "MatPermas test: " << e.what() << '\n';
    if(gmsh::isInitialized()) gmsh::finalize();
    return 1;
  }
}
