#include <gmsh.h>
#include <math.h>

int main()
{
  gmsh::initialize();

  int N = 2500;

  double tic = gmsh::logger::getWallTime();
  std::vector<double> coords; // x, y, z coordinates of all the nodes
  std::vector<std::size_t> nodes; // tags of corresponding nodes
  std::vector<std::size_t> tris; // connectivities (node tags) of triangle elements

  auto tag = [N](int i, int j) {
    return (N + 1) * i + j + 1;
  };

  for(int i = 0; i < N + 1; i++) {
    for(int j = 0; j < N + 1; j++) {
      nodes.push_back(tag(i, j));
      coords.push_back((double)i / N);
      coords.push_back((double)j / N);
      coords.push_back(0.05 * sin(10 * (double)(i + j) / N));
      if(i > 0 && j > 0) {
        tris.push_back(tag(i - 1, j - 1));
        tris.push_back(tag(i, j - 1));
        tris.push_back(tag(i - 1, j));
        tris.push_back(tag(i, j - 1));
        tris.push_back(tag(i, j));
        tris.push_back(tag(i - 1, j));
      }
    }
  }

  double toc = gmsh::logger::getWallTime();
  printf("==> created nodes and connectivities in %g seconds\n", toc - tic);

  tic = gmsh::logger::getWallTime();
  int surf = gmsh::model::addDiscreteEntity(2);
  toc = gmsh::logger::getWallTime();
  printf("==> created surface in %g seconds\n", toc - tic);

  tic = gmsh::logger::getWallTime();
  gmsh::model::mesh::addNodes(2, 1, nodes, coords);
  toc = gmsh::logger::getWallTime();
  printf("==> imported nodes in %g seconds\n", toc - tic);

  tic = gmsh::logger::getWallTime();
  gmsh::model::mesh::addElementsByType(1, 2, {}, tris);
  toc = gmsh::logger::getWallTime();
  printf("==> imported elements in %g seconds\n", toc - tic);

  tic = gmsh::logger::getWallTime();
  gmsh::option::setNumber("Mesh.Binary", 1);
  gmsh::write("import_perf.msh");
  toc = gmsh::logger::getWallTime();
  printf("==> wrote to disk in %g seconds\n", toc - tic);

  tic = gmsh::logger::getWallTime();
  gmsh::merge("import_perf.msh");
  toc = gmsh::logger::getWallTime();
  printf("==> read from disk in %g seconds\n", toc - tic);

  //gmsh::fltk::run();

  gmsh::finalize();
  return 0;
}
