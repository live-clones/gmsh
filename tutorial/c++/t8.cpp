// This file reimplements gmsh/tutorial/t8.geo in C++.

#include <gmsh.h>

namespace model = gmsh::model;
namespace factory = gmsh::model::geo;
namespace option = gmsh::option;

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  model::add("t8");

  // Copied from t1.cpp...
  double lc = 1e-2;
  factory::addPoint(0, 0, 0, lc, 1);
  factory::addPoint(.1, 0,  0, lc, 2);
  factory::addPoint(.1, .3, 0, lc, 3);
  factory::addPoint(0,  .3, 0, lc, 4);
  factory::addLine(1, 2, 1);
  factory::addLine(3, 2, 2);
  factory::addLine(3, 4, 3);
  factory::addLine(4, 1, 4);
  factory::addCurveLoop({4, 1, -2, 3}, 1);
  factory::addPlaneSurface({1}, 1);
  factory::synchronize();

  try {
    // add post-processing views to work on
    gmsh::merge("../view1.pos");
    gmsh::merge("../view1.pos");
    gmsh::merge("../view4.pos"); // contains 2 views inside
  }
  catch(...) {
    gmsh::logger::write("Could not load post-processing views: bye!");
    gmsh::finalize();
    return 0;
  }

  // set general options
  option::setNumber("General.Trackball", 0);
  option::setNumber("General.RotationX", 0);
  option::setNumber("General.RotationY", 0);
  option::setNumber("General.RotationZ", 0);

  int white[3] = {255, 255, 255};
  int black[3] = {0, 0, 0};

  // Color options are special: setting a color option of "X.Y" actually sets
  // the option "X.Color.Y"
  option::setColor("General.Background", white[0], white[1], white[2]);

  // We could make our own shorter versions of repetitive methods
  auto set_color = [] (std::string name, int c[3]) -> void
                   { option::setColor(name, c[0], c[1], c[2]); };
  set_color("General.Foreground", black);
  set_color("General.Text", black);

  option::setNumber("General.Orthographic", 0);
  option::setNumber("General.Axes", 0);
  option::setNumber("General.SmallAxes", 0);

  // show the GUI
  gmsh::fltk::initialize();

  // set options for each view
  option::setNumber("View[0].IntervalsType", 2);
  option::setNumber("View[0].OffsetZ", 0.05);
  option::setNumber("View[0].RaiseZ", 0);
  option::setNumber("View[0].Light", 1);
  option::setNumber("View[0].ShowScale", 0);
  option::setNumber("View[0].SmoothNormals", 1);

  option::setNumber("View[1].IntervalsType", 1);
  // can't set ColorTable in API yet
  // option::setColorTable("View[1].ColorTable", "{ Green, Blue }");
  option::setNumber("View[1].NbIso", 10);
  option::setNumber("View[1].ShowScale", 0);

  option::setString("View[2].Name", "Test...");
  option::setNumber("View[2].Axes", 1);
  option::setNumber("View[2].IntervalsType", 2);
  option::setNumber("View[2].Type", 2);
  option::setNumber("View[2].IntervalsType", 2);
  option::setNumber("View[2].AutoPosition", 0);
  option::setNumber("View[2].PositionX", 85);
  option::setNumber("View[2].PositionY", 50);
  option::setNumber("View[2].Width", 200);
  option::setNumber("View[2].Height", 130);

  option::setNumber("View[3].Visible", 0);

  int t = 0;

  // step through time for each view
  for(int num = 1; num <= 3; num++) {

    double nbt;
    option::getNumber("View[0].NbTimeStep", nbt);
    t = (t < nbt - 1) ? t + 1 : 0;
    option::setNumber("View[0].TimeStep", t);
    option::setNumber("View[1].TimeStep", t);
    option::setNumber("View[2].TimeStep", t);
    option::setNumber("View[3].TimeStep", t);

    double max;
    option::getNumber("View[0].Max", max);
    option::setNumber("View[0].RaiseZ", 0.01 / max * t);

    if(num == 3) {
      double mw;
      option::getNumber("General.MenuWidth", mw);
      option::setNumber("General.GraphicsWidth", mw + 640);
      option::setNumber("General.GraphicsHeight", 480);
    }

    int frames = 50;
    for(int num2 = 1; num2 <= frames; num2++) {
      double rotx;
      option::getNumber("General.RotationX", rotx);
      option::setNumber("General.RotationX", rotx + 10);
      option::setNumber("General.RotationY", (rotx + 10) / 3.);
      double rotz;
      option::getNumber("General.RotationZ", rotz);
      option::setNumber("General.RotationZ", rotz + 0.1);

      gmsh::graphics::draw();

      // write out the graphics scene to an image file Gmsh will try to detect
      // the file extension
      if(num == 3) {
        // gmsh::write("t2-" + std::to_string(num2) + ".gif");
        // gmsh::write("t2-" + std::to_string(num2) + ".ppm");
        // gmsh::write("t2-" + std::to_string(num2) + ".jpg");
      }
    }

    if(num == 3) {
      // Here we could make a system call to generate a movie...
    }
  }

  gmsh::fltk::run();
  gmsh::finalize();

  return 0;
}
