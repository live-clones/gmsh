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
#include "Context.h"
#include "drawContext.h"

// "Elementary Entity Context": what to make, one shape per pane.

namespace {

  using namespace Ui;
  using namespace Declare;

  namespace {

    // the panes, with the label and default value of each of their fields;
    // for every pane but the first, the first three fields are the X, Y and Z
    // the mouse drives
    struct shape {
      const char *name;
      const char *label[9];
      const char *value[9];
    };

    const shape _shapes[12] = {
      {"Parameter",
       {"Name", "Value", "Label", "Path"},
       {"lc", "0.1", "", "Parameters"}},
      {"Point",
       {"X", "Y", "Z", "Prescribed mesh size at point"},
       {"0", "0", "0", "1.0"}},
      {"Circle",
       {"Center X", "Center Y", "Center Z", "Radius", "Angle 1", "Angle 2"},
       {"0", "0", "0", "0.5", "0", "2*Pi"}},
      {"Ellipse",
       {"Center X", "Center Y", "Center Z", "Radius X", "Radius Y", "Angle 1",
        "Angle 2"},
       {"0", "0", "0", "0.5", "0.25", "0", "2*Pi"}},
      {"Disk",
       {"Center X", "Center Y", "Center Z", "Radius X", "Radius Y"},
       {"0", "0", "0", "0.5", "0.25"}},
      {"Rectangle",
       {"X", "Y", "Z", "DX", "DY", "Rounded radius"},
       {"0", "0", "0", "1", "0.5", "0"}},
      {"Sphere",
       {"Center X", "Center Y", "Center Z", "Radius", "Angle 1", "Angle 2",
        "Angle 3"},
       {"0", "0", "0", "0.5", "-Pi/2", "Pi/2", "2*Pi"}},
      {"Cylinder",
       {"Center base X", "Center base Y", "Center base Z", "Axis DX", "Axis DY",
        "Axis DZ", "Radius", "Angle"},
       {"0", "0", "0", "1", "0", "0", "0.5", "2*Pi"}},
      {"Box",
       {"X", "Y", "Z", "DX", "DY", "DZ"},
       {"0", "0", "0", "1", "1", "1"}},
      {"Torus",
       {"Center X", "Center Y", "Center Z", "Radius 1", "Radius 2", "Angle"},
       {"0", "0", "0", "0.5", "0.2", "2*Pi"}},
      {"Cone",
       {"Center base X", "Center base Y", "Center base Z", "Axis DX", "Axis DY",
        "Axis DZ", "Radius 1", "Radius 2", "Angle"},
       {"0", "0", "0", "1", "0", "0", "0.5", "0.1", "2*Pi"}},
      {"Wedge",
       {"X", "Y", "Z", "DX", "DY", "DZ", "Top DX"},
       {"0", "0", "0", "0.5", "0.5", "0.5", "0"}}};

    // where a field goes, when a pane is not simply one field per line: the
    // cone is the only shape with a second column, its radii and its angle
    // beside the axis rather than under it
    struct placed {
      int field;
      bool beside;
    };

    const placed _coneLayout[] = {{0, false}, {1, false}, {2, false},
                                  {3, false}, {6, true},  {4, false},
                                  {7, true},  {5, false}, {8, true}};

    std::vector<placed> _layout(int pane, int fields)
    {
      if(pane == 10 && fields == 9)
        return std::vector<placed>(std::begin(_coneLayout),
                                   std::end(_coneLayout));
      std::vector<placed> plain;
      for(int j = 0; j < fields; j++) plain.push_back({j, false});
      return plain;
    }

    void fillElementaryDefaults()
    {
      static bool done = false;
      if(done) return;
      done = true;
      for(int i = 0; i < 12; i++)
        for(int j = 0; j < geometryElementaryFieldCount(i); j++)
          elementaryStore(i, j) = _shapes[i].value[j];
    }

  } // namespace

    // the commands whose entities are picked in the view rather than typed:
    // the list shows what was picked, and lets a misclick be taken back
    // without starting again
    struct picking {
      const char *name;
      const char *what;
      const char *family;
    };
    const picking _picked[9] = {
      {"Line", "Select the two ends", "Curves"},
      {"Spline", "Select the control points", "Curves"},
      {"Bezier", "Select the control points", "Curves"},
      {"B-Spline", "Select the control points", "Curves"},
      {"Circle arc", "Select start, centre and end", "Curves"},
      {"Ellipse arc", "Select start, centre, major axis and end", "Curves"},
      {"Plane surface", "Select the boundary, then the holes", "Surfaces"},
      {"Surface filling", "Select the boundary, then the holes", "Surfaces"},
      {"Volume", "Select the boundary, then the holes", "Volumes"}};

    Pane pickingPane(int which)
    {
      Pane q;
      q.label = _picked[which].name;
      q.group = _picked[which].family;
      // the pane of a picked shape sits after the twelve typed ones
      int pane = 12 + which;
      q.chosen = [pane]() { geometryElementaryRestart(pane); };
      std::string what = _picked[which].what;
      q.fields.push_back(says([what]() { return what; }));
      q.fields.push_back(picked(
        "", &geometryPicked().tags,
        [](int index) {
          const pickedEntities &v = geometryPicked();
          // a loop is worth more as the curves it closes than as its own
          // number, so it is shown as its contents
          if(index < (int)v.members.size()) {
            std::string line = "[";
            for(std::size_t k = 0; k < v.members[index].size(); k++) {
              if(k) line += ", ";
              line += v.memberWhat + " " +
                      std::to_string(std::abs(v.members[index][k]));
            }
            return line + "]";
          }
          if(index >= (int)v.tags.size()) return std::string();
          return (v.what.size() ? v.what : std::string("Entity")) + " " +
                 std::to_string(v.tags[index]);
        },
        // a loop already written to the script cannot be taken back from here
        [](int index) {
          if(geometryPicked().editable) geometryUnpick(index);
        }));
      return q;
    }

  static Form describeElementary()
  {
    fillElementaryDefaults();

    Form p;
    p.title = "Elementary Entity Context";

    for(int i = 0; i < 12; i++) {
      Pane q;
      q.label = _shapes[i].name;
      // twelve tabs do not fit across a window this wide: they are grouped by
      // what they make; a parameter is not a shape and a point has no extent,
      // so those two stand alone
      static const char *family[12] = {"",        "",        "Curves",
                                       "Curves",  "Surfaces", "Surfaces",
                                       "Volumes", "Volumes", "Volumes",
                                       "Volumes", "Volumes", "Volumes"};
      q.group = family[i];
      int n = geometryElementaryFieldCount(i);
      for(const auto &at : _layout(i, n)) {
        int j = at.field;
        Field f = text(_shapes[i].label[j], &elementaryStore(i, j));
        f.sameRow = at.beside;
        // the shape being built is previewed on top of the model
        // geometryAddPointBasedEntity() owns the preview for the whole time it
        // is placing something, and _drawTransientShape() reads the values
        // from the store: typing one only has to ask for a redraw
        f.changed = []() { drawContext::global()->draw(); };
        q.fields.push_back(f);
        // a second column is not a line cut in two: each takes a whole field and
        // simply starts further along
        if(at.beside && q.fields.size() >= 2) {
          q.fields[q.fields.size() - 1].widthShare = 1.;
          q.fields[q.fields.size() - 2].widthShare = 1.;
        }
      }
      q.chosen = [i]() { geometryElementaryRestart(i); };
      q.buttonLabel = "Add";
      q.button = [i]() {
        elementaryPaneStore() = i;
        geometryAddElementary(elementaryStoreParameters());
        drawContext::global()->draw();
      };
      p.panes.push_back(q);
    }

    // and the ones whose entities are picked, which show what has been picked
    for(int i = 0; i < 9; i++) p.panes.push_back(pickingPane(i));

    // The grid the coordinates snap to, and the axes the mouse may not move,
    // on one line: three little numbers together at the left, three checks
    // together at the right, one label for each group.
    const char *axes[] = {"X", "Y", "Z snap"};
    for(int i = 0; i < 3; i++) {
      Field f = tight(sized(number(axes[i], &CTX::instance()->geom.snap[i]), 3.5));
      if(i) f.sameRow = true;
      p.footer.push_back(f);
    }
    p.footer.push_back(stretch());

    // which coordinates the mouse must leave alone while placing an entity
    const char *freeze[] = {"X", "Y", "Z freeze"};
    const char *tips[] = {"Toggle (x) or exclusive unselect (Shift+x)",
                          "Toggle (y) or exclusive unselect (Shift+y)",
                          "Toggle (z) or exclusive unselect (Shift+z)"};
    Field fx = tight(beside(check(freeze[0], &elementaryFrozen(0))));
    Field fy = tight(beside(check(freeze[1], &elementaryFrozen(1))));
    Field fz = tight(beside(check(freeze[2], &elementaryFrozen(2))));
    fx.tooltip = tips[0];
    fy.tooltip = tips[1];
    fz.tooltip = tips[2];
    p.footer.push_back(fx);
    p.footer.push_back(beside(fy));
    p.footer.push_back(beside(fz));
    return p;
  }

} // namespace

Ui::Form GuiElementary::build()
{
  Ui::Form f = describeElementary();
  f.id = "elementary";
  return f;
}


void GuiElementary::showShape(int shape)
{
  if(shape >= 0 && shape < 12)
    show(_shapes[shape].name);
  else if(shape >= 12 && shape < 12 + 9)
    show(_picked[shape - 12].name);
  else
    show();
}

#endif
