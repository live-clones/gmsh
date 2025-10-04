#include <gmsh.h>
#include <set>
#include <cstdlib> // for rand()

int main(int argc, char **argv)
{
  // number of points to tetrahedralize
  std::size_t N = 100;

  gmsh::initialize();

  gmsh::option::setNumber("Mesh.Algorithm3D", 10); // new Delaunay algo

  std::vector<double> points(3 * N), steiner;
  std::vector<std::size_t> tags(N);
  for(auto i = 0; i < N; ++i) {
    tags[i] = i + 1;
    points[3 * i] = (double)std::rand() / (double)RAND_MAX;
    points[3 * i + 1] = (double)std::rand() / (double)RAND_MAX;
    points[3 * i + 2] = (double)std::rand() / (double)RAND_MAX;
  }

  std::vector<std::size_t> tets;
  gmsh::algorithm::tetrahedralize(points, tets, steiner);

  std::set<std::string> args(argv, argv + argc);
  if(!args.count("-nopopup")) {
    int vol = gmsh::model::addDiscreteEntity(3);
    gmsh::model::mesh::addNodes(3, vol, tags, points);
    gmsh::model::mesh::addElementsByType(vol, 4, {}, tets);
    gmsh::fltk::run();
  }

  gmsh::finalize();
  return 0;
}
