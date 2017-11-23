#include <gmsh.h>

int main(int argc, char **argv)
{
  gmshInitialize();
  gmshOptionSetNumber("General.Terminal", 1);

  std::vector<double> tri1 = {0., 1., 1.,
                              0., 0., 1.,
                              0., 0., 0.};
  std::vector<double> tri2 = {0., 1., 0.,
                              0., 1., 1.,
                              0., 0., 0.};

  for(int step = 0; step < 10; step++){
    tri1.push_back(10.);
    tri1.push_back(10.);
    tri1.push_back(12. + step);
    tri2.push_back(10.);
    tri2.push_back(12. + step);
    tri2.push_back(13. + step);
  }

  int t = gmshViewCreate("some data");
  std::vector<double> data;
  data.insert(data.end(), tri1.begin(), tri1.end());
  data.insert(data.end(), tri2.begin(), tri2.end());

  gmshViewAddListData(t, "ST", 2, data);

  gmshViewExport(t, "data.pos");

  gmshFinalize();
  return 0;
}
