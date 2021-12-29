// -----------------------------------------------------------------------------
//
//  Gmsh C++ tutorial 8
//
//  Post-processing and animations
//
// -----------------------------------------------------------------------------

#include <set>
#include <gmsh.h>

// In addition to creating geometries and meshes, the C++ API can also be used
// to manipulate post-processing datasets (called "views" in Gmsh).

int main(int argc, char **argv)
{
  gmsh::initialize();

  gmsh::model::add("t8");

  // We first create a simple geometry
  double lc = 1e-2;
  gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
  gmsh::model::geo::addPoint(.1, 0, 0, lc, 2);
  gmsh::model::geo::addPoint(.1, .3, 0, lc, 3);
  gmsh::model::geo::addPoint(0, .3, 0, lc, 4);
  gmsh::model::geo::addLine(1, 2, 1);
  gmsh::model::geo::addLine(3, 2, 2);
  gmsh::model::geo::addLine(3, 4, 3);
  gmsh::model::geo::addLine(4, 1, 4);
  gmsh::model::geo::addCurveLoop({4, 1, -2, 3}, 1);
  gmsh::model::geo::addPlaneSurface({1}, 1);
  gmsh::model::geo::synchronize();

  // We merge some post-processing views to work on
  try {
    gmsh::merge("../view1.pos");
    gmsh::merge("../view1.pos");
    gmsh::merge("../view4.pos"); // contains 2 views inside
  } catch(...) {
    gmsh::logger::write("Could not load post-processing views: bye!");
    gmsh::finalize();
    return 0;
  }

  // Gmsh can read post-processing views in various formats. Here the
  // `view1.pos' and `view4.pos' files are in the Gmsh "parsed" format, which is
  // interpreted by the GEO script parser. The parsed format should only be used
  // for relatively small datasets of course: for larger datasets using e.g. MSH
  // files is much more efficient. Post-processing views can also be created
  // directly from the C++ API.

  // We then set some general options:
  gmsh::option::setNumber("General.Trackball", 0);
  gmsh::option::setNumber("General.RotationX", 0);
  gmsh::option::setNumber("General.RotationY", 0);
  gmsh::option::setNumber("General.RotationZ", 0);

  int white[3] = {255, 255, 255};
  int black[3] = {0, 0, 0};
  gmsh::option::setColor("General.Background", white[0], white[1], white[2]);

  // We can make our own shorter versions of repetitive methods
  auto set_color = [](std::string name, int c[3]) -> void {
    gmsh::option::setColor(name, c[0], c[1], c[2]);
  };
  set_color("General.Foreground", black);
  set_color("General.Text", black);

  gmsh::option::setNumber("General.Orthographic", 0);
  gmsh::option::setNumber("General.Axes", 0);
  gmsh::option::setNumber("General.SmallAxes", 0);

  // Show the GUI:
  std::set<std::string> args(argv, argv + argc);
  if(!args.count("-nopopup")) gmsh::fltk::initialize();

  // We also set some options for each post-processing view:
  gmsh::option::setNumber("View[0].IntervalsType", 2);
  gmsh::option::setNumber("View[0].OffsetZ", 0.05);
  gmsh::option::setNumber("View[0].RaiseZ", 0);
  gmsh::option::setNumber("View[0].Light", 1);
  gmsh::option::setNumber("View[0].ShowScale", 0);
  gmsh::option::setNumber("View[0].SmoothNormals", 1);

  gmsh::option::setNumber("View[1].IntervalsType", 1);
  // We can't yet set the ColorTable through the API
  // gmsh::option::setColorTable("View[1].ColorTable", "{ Green, Blue }");
  gmsh::option::setNumber("View[1].NbIso", 10);
  gmsh::option::setNumber("View[1].ShowScale", 0);

  gmsh::option::setString("View[2].Name", "Test...");
  gmsh::option::setNumber("View[2].Axes", 1);
  gmsh::option::setNumber("View[2].IntervalsType", 2);
  gmsh::option::setNumber("View[2].Type", 2);
  gmsh::option::setNumber("View[2].IntervalsType", 2);
  gmsh::option::setNumber("View[2].AutoPosition", 0);
  gmsh::option::setNumber("View[2].PositionX", 85);
  gmsh::option::setNumber("View[2].PositionY", 50);
  gmsh::option::setNumber("View[2].Width", 200);
  gmsh::option::setNumber("View[2].Height", 130);

  gmsh::option::setNumber("View[3].Visible", 0);

  // You can save an MPEG movie directly by selecting `File->Export' in the
  // GUI. Several predefined animations are setup, for looping on all the time
  // steps in views, or for looping between views.

  // But the API can be used to build much more complex animations, by changing
  // options at run-time and re-rendering the graphics. Each frame can then be
  // saved to disk as an image, and multiple frames can be encoded to form a
  // movie. Below is an example of such a custom animation.

  int t = 0; // Initial step

  for(int num = 1; num <= 3; num++) {
    double nbt;
    gmsh::option::getNumber("View[0].NbTimeStep", nbt);
    t = (t < nbt - 1) ? t + 1 : 0;

    // Set time step
    gmsh::option::setNumber("View[0].TimeStep", t);
    gmsh::option::setNumber("View[1].TimeStep", t);
    gmsh::option::setNumber("View[2].TimeStep", t);
    gmsh::option::setNumber("View[3].TimeStep", t);

    double max;
    gmsh::option::getNumber("View[0].Max", max);
    gmsh::option::setNumber("View[0].RaiseZ", 0.01 / max * t);

    if(num == 3) {
      double mw;
      gmsh::option::getNumber("General.MenuWidth", mw);
      gmsh::option::setNumber("General.GraphicsWidth", mw + 640);
      gmsh::option::setNumber("General.GraphicsHeight", 480);
    }

    int frames = 50;
    for(int num2 = 1; num2 <= frames; num2++) {
      // Incrementally rotate the scene
      double rotx;
      gmsh::option::getNumber("General.RotationX", rotx);
      gmsh::option::setNumber("General.RotationX", rotx + 10);
      gmsh::option::setNumber("General.RotationY", (rotx + 10) / 3.);
      double rotz;
      gmsh::option::getNumber("General.RotationZ", rotz);
      gmsh::option::setNumber("General.RotationZ", rotz + 0.1);

      // Draw the scene
      gmsh::graphics::draw();

      if(num == 3) {
        // Uncomment the following lines to save each frame to an image file
        // gmsh::write("t2-" + std::to_string(num2) + ".gif");
        // gmsh::write("t2-" + std::to_string(num2) + ".ppm");
        // gmsh::write("t2-" + std::to_string(num2) + ".jpg");
      }
    }

    if(num == 3) {
      // Here we could make a system call to generate a movie...
    }
  }

  if(!args.count("-nopopup")) gmsh::fltk::run();

  gmsh::finalize();

  return 0;
}
