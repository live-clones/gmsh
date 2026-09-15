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

// The clipping planes: six planes, or the box that six of them make, and
// a list down the side of what each cuts. The dialog works on a copy: the
// plane being edited is read when it is chosen and written back at every
// change.

namespace {

  using namespace Ui;
  using namespace Declare;

  static Form describeClipping()
  {
    clippingParameters &v = clippingStore();
    Form p;
    p.title = "Clipping";

    // what the planes cut: the geometry, the mesh, and each view
    p.side.push_back(chooseFrom(
      [](std::vector<std::string> &labels, std::vector<int> &values) {
        clippingTargets(labels);
        for(std::size_t i = 0; i < labels.size(); i++) values.push_back((int)i);
      },
      clippingCuts, clippingSetCuts, true));
    // as tall as the window
    p.side.back().rows = 0;

    {
      Pane planes;
      planes.label = "Planes";
      Field which = choice("", &v.plane,
                           {"Plane 0", "Plane 1", "Plane 2", "Plane 3",
                            "Plane 4", "Plane 5"},
                           {0, 1, 2, 3, 4, 5});
      which.changed = []() {
        clippingStore().asBox = false;
        clippingRead();
      };
      planes.fields.push_back(which);

      const char *tip = "A * X + B * Y + C * Z + D = 0";
      const char *names[] = {"A", "B", "C", "D"};
      for(int j = 0; j < 4; j++) {
        // no bounds and no step: the first three are a direction that is
        // normalised anyway
        Field f = number(names[j], &v.coefficient[j], tip);
        f.changed = []() {
          clippingStore().asBox = false;
          clippingWrite();
        };
        planes.fields.push_back(f);
      }
      Field invert = does("Invert", clippingInvert);
      invert.tooltip = "Invert orientation";
      planes.fields.push_back(tight(invert));
      p.panes.push_back(planes);
    }
    {
      Pane box;
      box.label = "Box";
      const char *names[] = {"X", "Y", "Z", "DX", "DY", "DZ"};
      double *values[] = {&v.centre[0], &v.centre[1], &v.centre[2],
                          &v.size[0],   &v.size[1],   &v.size[2]};
      for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 2; k++) {
          Field f = number(names[j + 3 * k], values[j + 3 * k]);
          f.changed = []() {
            clippingStore().asBox = true;
            clippingWrite();
          };
          if(k) f.sameRow = true;
          box.fields.push_back(f);
        }
      }
      p.panes.push_back(box);
    }

    auto apply = []() { clippingWrite(); };
    Field whole = check("Keep whole elements", &v.wholeElements);
    whole.changed = apply;
    Field layer = check("Only draw volume layer", &v.onlyDrawIntersecting);
    layer.changed = apply;
    Field only = check("Cut only volume elements", &v.onlyVolume);
    only.changed = apply;
    p.footer.push_back(whole);
    p.footer.push_back(layer);
    p.footer.push_back(only);

    Button redraw;
    redraw.label = "Redraw";
    redraw.isDefault = true;
    redraw.action = clippingWrite;
    p.buttons.push_back(redraw);

    Button reset;
    reset.label = "Reset";
    reset.action = clippingReset;
    p.buttons.push_back(reset);
    return p;
  }

} // namespace

Ui::Form GuiClipping::build()
{
  Ui::Form f = describeClipping();
  f.id = "clipping";
  return f;
}

void GuiClipping::load() { clippingRead(); }


#endif
