// This file reimplements gmsh/tutorial/t9.geo in C++.

#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize();
  gmsh::option::setNumber("General.Terminal", 1);

  gmsh::model::add("t9");

  // add a three-dimensional scalar view to work on:
  try {
    gmsh::merge("../view3.pos");
  }
  catch(...) {
    gmsh::logger::write("Could not load post-processing views: bye!");
    gmsh::finalize();
    return 0;
  }

  // First plugin is Isosurface
  gmsh::plugin::setNumber("Isosurface", "Value", 0.67);
  gmsh::plugin::setNumber("Isosurface", "View", 0);
  gmsh::plugin::run("Isosurface");

  // Second is CutPlane
  gmsh::plugin::setNumber("CutPlane", "A", 0);
  gmsh::plugin::setNumber("CutPlane", "B", 0.2);
  gmsh::plugin::setNumber("CutPlane", "C", 1);
  gmsh::plugin::setNumber("CutPlane", "D", 0);
  gmsh::plugin::setNumber("CutPlane", "View", 0);
  gmsh::plugin::run("CutPlane");

  // Third is Annotate
  gmsh::plugin::setString("Annotate", "Text", "A nice title");
  // By convention, window coordinates larger than 99999 represent the center
  gmsh::plugin::setNumber("Annotate", "X", 1.e5);
  gmsh::plugin::setNumber("Annotate", "Y", 50);
  gmsh::plugin::setString("Annotate", "Font", "Times-BoldItalic");
  gmsh::plugin::setNumber("Annotate", "FontSize", 28);
  gmsh::plugin::setString("Annotate", "Align", "Center");
  gmsh::plugin::setNumber("Annotate", "View", 0);
  gmsh::plugin::run("Annotate");

  gmsh::plugin::setString("Annotate", "Text", "(and a small subtitle)");
  gmsh::plugin::setNumber("Annotate", "Y", 70);
  gmsh::plugin::setString("Annotate", "Font", "Times-Roman");
  gmsh::plugin::setNumber("Annotate", "FontSize", 12);
  gmsh::plugin::run("Annotate");

  // set some general options
  gmsh::option::setNumber("View[0].Light", 1);
  gmsh::option::setNumber("View[0].IntervalsType", 1);
  gmsh::option::setNumber("View[0].NbIso", 6);
  gmsh::option::setNumber("View[0].SmoothNormals", 1);
  gmsh::option::setNumber("View[1].IntervalsType", 2);
  gmsh::option::setNumber("View[2].IntervalsType", 2);

  gmsh::finalize();
  return 0;
}
