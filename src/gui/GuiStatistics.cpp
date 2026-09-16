// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "Gui.h"
#include "GuiDeclare.h"

// The statistics: what the model is made of, one tab for the geometry, one
// for the mesh and one for the views. The numbers all come from one array
// that statisticsCompute() fills; which index means what is said here.

namespace {

  using namespace Ui;
  using namespace Declare;

  namespace {

    Field stat(const std::string &label, int index)
    {
      return reads(label, [index]() {
        char tmp[64];
        sprintf(tmp, "%g", statisticsValue(index));
        return std::string(tmp);
      });
    }

    // the quality measures read as an average and the range around it, and say
    // so only once they have been computed
    Field quality(const std::string &label, const std::string &tip, int index,
                  int which)
    {
      Field f = reads(label, [index]() {
        if(!statisticsQuality()) return std::string("Press Update");
        char tmp[128];
        sprintf(tmp, "%.4g (%.4g->%.4g)", statisticsValue(index),
                statisticsValue(index + 1), statisticsValue(index + 2));
        return std::string(tmp);
      });
      f.tooltip = tip;
      f.enabled = statisticsQuality;
      (void)which;
      return f;
    }

  } // namespace

  static Form describeStatistics()
  {
    Form p;
    p.title = "Statistics";

    p.panes.push_back(
      pane({stat("Points", 0), stat("Curves", 1), stat("Surfaces", 2),
            stat("Volumes", 3), stat("Physical groups", 45)},
           "Geometry"));
    {
      Pane mesh;
      mesh.label = "Mesh";
      // A grid, so that the three buttons of a quality line stand under one
      // another: their line begins with a value whose label is "SICN" on one
      // and "Gamma" on the next, and packing them against it would stagger
      // them by the difference.
      mesh.columns = 4;
      const char *counts[] = {
        "Nodes",      "Points",    "Lines",  "Triangles", "Quadrangles",
        "Tetrahedra", "Hexahedra", "Prisms", "Pyramids",  "Trihedra"};
      for(int i = 0; i < 10; i++) mesh.fields.push_back(stat(counts[i], 4 + i));
      mesh.fields.push_back(stat("Time for 1D mesh", 14));
      mesh.fields.push_back(stat("Time for 2D mesh", 15));
      mesh.fields.push_back(stat("Time for 3D mesh", 16));

      struct measure {
        const char *label;
        const char *tip;
        int index;
      };
      const measure measures[] = {
        {"SICN", "~ signed inverse condition number", 18},
        {"Gamma", "~ inscribed_radius / circumscribed_radius (simplices)", 21},
        {"SIGE", "~ signed inverse error on gradient FE solution", 24}};
      for(int i = 0; i < 3; i++) {
        mesh.fields.push_back(
          quality(measures[i].label, measures[i].tip, measures[i].index, i));
        // the three of them belong together at the right of the line, each in
        // a column of its own, as wide as its own text and no wider
        mesh.fields.push_back(
          beside(says([]() { return std::string("Plot"); })));
        Field xy = does("X-Y", [i]() { statisticsHistogram(i, false); });
        xy.enabled = statisticsQuality;
        mesh.fields.push_back(sized(beside(xy), 3.));
        mesh.fields.push_back(sized(
          beside(does("3D", [i]() { statisticsHistogram(i, true); })), 3.));
      }
      mesh.fields.push_back(
        check("Compute statistics for visible entities only",
              &statisticsVisibleOnly()));
      p.panes.push_back(mesh);
    }
    {
      const char *counts[] = {"Views",     "Points",      "Lines",
                              "Triangles", "Quadrangles", "Tetrahedra",
                              "Hexahedra", "Prisms",      "Pyramids",
                              "Trihedra",  "Strings"};
      Pane post;
      post.label = "Post-processing";
      for(int i = 0; i < 11; i++)
        post.fields.push_back(stat(counts[i], 27 + i));
      p.panes.push_back(post);
    }

    p.footer.push_back(says([]() {
      double mb = statisticsMemoryUsage();
      if(mb <= 0.) return std::string("");
      char tmp[64];
      sprintf(tmp, "Memory usage: %gMB", mb);
      return std::string(tmp);
    }));

    // the memory usage and Update share the last line
    p.buttonsInFooter = true;

    Button update;
    update.label = "Update";
    update.isDefault = true;
    update.action = []() { statisticsCompute(true); };
    p.buttons.push_back(update);
    return p;
  }

  // the statistics are counted when the window opens, quality apart: that
  // one costs, and waits for Update; the tab that opens is the one with
  // something in it

} // namespace

Ui::Form GuiStatistics::build()
{
  Ui::Form f = describeStatistics();
  f.id = "statistics";
  return f;
}

void GuiStatistics::show(const std::string &pane)
{
  std::string on = pane;
  if(!visible()) {
    statisticsCompute(false);
    if(on.empty()) {
      // the form is built on show(): the labels are those of the description
      Form f = build();
      int fullest = statisticsFullestPane();
      if(fullest >= 0 && fullest < (int)f.panes.size())
        on = f.panes[fullest].label;
    }
  }
  GuiTabbed::show(on);
}

#endif
