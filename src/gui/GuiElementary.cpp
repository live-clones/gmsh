// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#include "GuiElementary.h"
#include "GuiActions.h"
#include "GuiDeclare.h"
#include "Context.h"
#include "drawContext.h"

using namespace Ui;
using namespace Declare;

namespace {

  // twelve tabs do not fit across the window: the family each belongs to; a
  // parameter and a point stand alone
  struct shape {
    const char *name;
    const char *family;
    const char *label[9];
    const char *value[9];
  };

  const shape _shapes[12] = {
    {"Parameter", "", {"Name", "Value", "Label", "Path"},
     {"lc", "0.1", "", "Parameters"}},
    {"Point", "", {"X", "Y", "Z", "Prescribed mesh size at point"},
     {"0", "0", "0", "1.0"}},
    {"Circle", "Curves",
     {"Center X", "Center Y", "Center Z", "Radius", "Angle 1", "Angle 2"},
     {"0", "0", "0", "0.5", "0", "2*Pi"}},
    {"Ellipse", "Curves",
     {"Center X", "Center Y", "Center Z", "Radius X", "Radius Y", "Angle 1",
      "Angle 2"},
     {"0", "0", "0", "0.5", "0.25", "0", "2*Pi"}},
    {"Disk", "Surfaces",
     {"Center X", "Center Y", "Center Z", "Radius X", "Radius Y"},
     {"0", "0", "0", "0.5", "0.25"}},
    {"Rectangle", "Surfaces", {"X", "Y", "Z", "DX", "DY", "Rounded radius"},
     {"0", "0", "0", "1", "0.5", "0"}},
    {"Sphere", "Volumes",
     {"Center X", "Center Y", "Center Z", "Radius", "Angle 1", "Angle 2",
      "Angle 3"},
     {"0", "0", "0", "0.5", "-Pi/2", "Pi/2", "2*Pi"}},
    {"Cylinder", "Volumes",
     {"Center base X", "Center base Y", "Center base Z", "Axis DX", "Axis DY",
      "Axis DZ", "Radius", "Angle"},
     {"0", "0", "0", "1", "0", "0", "0.5", "2*Pi"}},
    {"Box", "Volumes", {"X", "Y", "Z", "DX", "DY", "DZ"},
     {"0", "0", "0", "1", "1", "1"}},
    {"Torus", "Volumes",
     {"Center X", "Center Y", "Center Z", "Radius 1", "Radius 2", "Angle"},
     {"0", "0", "0", "0.5", "0.2", "2*Pi"}},
    {"Cone", "Volumes",
     {"Center base X", "Center base Y", "Center base Z", "Axis DX", "Axis DY",
      "Axis DZ", "Radius 1", "Radius 2", "Angle"},
     {"0", "0", "0", "1", "0", "0", "0.5", "0.1", "2*Pi"}},
    {"Wedge", "Volumes", {"X", "Y", "Z", "DX", "DY", "DZ", "Top DX"},
     {"0", "0", "0", "0.5", "0.5", "0.5", "0"}}};
  const int _fields[12] = {4, 4, 6, 7, 5, 6, 7, 8, 6, 6, 9, 7};

  // the list shows what was picked and lets a misclick be taken back
  struct picking {
    const char *name;
    const char *family;
    const char *what;
  };
  const picking _picked[9] = {
    {"Line", "Curves", "Select the two ends"},
    {"Spline", "Curves", "Select the control points"},
    {"Bezier", "Curves", "Select the control points"},
    {"B-Spline", "Curves", "Select the control points"},
    {"Circle arc", "Curves", "Select start, centre and end"},
    {"Ellipse arc", "Curves", "Select start, centre, major axis and end"},
    {"Plane surface", "Surfaces", "Select the boundary, then the holes"},
    {"Surface filling", "Surfaces", "Select the boundary, then the holes"},
    {"Volume", "Volumes", "Select the boundary, then the holes"}};

  std::string _pickedName(int index)
  {
    const pickedEntities &v = geometryPicked();
    if(index < (int)v.members.size()) {
      std::string line = "[";
      for(std::size_t k = 0; k < v.members[index].size(); k++) {
        if(k) line += ", ";
        line += v.memberWhat + " " + std::to_string(std::abs(v.members[index][k]));
      }
      return line + "]";
    }
    if(index >= (int)v.tags.size()) return std::string();
    return (v.what.size() ? v.what : std::string("Entity")) + " " +
           std::to_string(v.tags[index]);
  }

} // namespace

int GuiElementary::fields(int shape)
{
  return (shape >= 0 && shape < 12) ? _fields[shape] : 0;
}

std::vector<std::string> GuiElementary::values() const
{
  std::vector<std::string> v;
  for(int i = 0; i < fields(shape); i++) v.push_back(value[shape][i]);
  return v;
}

GuiElementary::GuiElementary()
{
  for(int i = 0; i < 12; i++)
    for(int j = 0; j < _fields[i]; j++) value[i][j] = _shapes[i].value[j];
}

Form GuiElementary::build()
{
  auto redraw = []() { drawContext::global()->draw(); };
  auto field = [&](int i, int j) {
    return text(_shapes[i].label[j], &value[i][j]).onChanged(redraw);
  };
  auto typed = [&](int i) {
    std::vector<Item> lines;
    if(i == 10)
      // the cone alone has a second column
      lines = {field(i, 0), field(i, 1), field(i, 2),
               hbox({field(i, 3).share(1.), field(i, 6).share(1.)}),
               hbox({field(i, 4).share(1.), field(i, 7).share(1.)}),
               hbox({field(i, 5).share(1.), field(i, 8).share(1.)})};
    else
      for(int j = 0; j < _fields[i]; j++) lines.push_back(field(i, j));
    lines.push_back(gap());
    lines.push_back(hbox({gap(), button("Add", [this, i]() {
                            shape = i;
                            geometryAddElementary(i, values());
                            drawContext::global()->draw();
                          })}));
    return vbox(lines);
  };
  auto picked = [&](int i) {
    return vbox({label(_picked[i].what),
                 Declare::picked(
                   "", &geometryPicked().tags, _pickedName,
                   [](int index) {
                     if(geometryPicked().editable) geometryUnpick(index);
                   })});
  };
  auto chosen = [](const std::string &name) {
    for(int i = 0; i < 12; i++)
      if(name == _shapes[i].name) geometryElementaryRestart(i);
    for(int i = 0; i < 9; i++)
      if(name == _picked[i].name) geometryElementaryRestart(12 + i);
  };
  auto family = [&](const char *name) {
    std::vector<std::pair<std::string, Item>> members;
    for(int i = 0; i < 12; i++)
      if(!strcmp(_shapes[i].family, name)) members.push_back({_shapes[i].name, typed(i)});
    for(int i = 0; i < 9; i++)
      if(!strcmp(_picked[i].family, name)) members.push_back({_picked[i].name, picked(i)});
    Tabs t;
    t.tabs = members;
    t.chosen = chosen;
    return t;
  };

  // the snap and the frozen axes on one line, a label for each group
  const char *tips[] = {"Toggle (x) or exclusive unselect (Shift+x)",
                        "Toggle (y) or exclusive unselect (Shift+y)",
                        "Toggle (z) or exclusive unselect (Shift+z)"};
  double *snap = CTX::instance()->geom.snap;

  return {"elementary", "Elementary Entity Context",
          vbox({tabs({{"Parameter", typed(0)},
                      {"Point", typed(1)},
                      {"Curves", family("Curves")},
                      {"Surfaces", family("Surfaces")},
                      {"Volumes", family("Volumes")}},
                     chosen),
                hbox({number("X", &snap[0]).sized(3.5).tight(),
                      number("Y", &snap[1]).sized(3.5).tight(),
                      number("Z snap", &snap[2]).sized(3.5).tight(), gap(),
                      check("X", &frozen[0]).tight().tip(tips[0]),
                      check("Y", &frozen[1]).tight().tip(tips[1]),
                      check("Z freeze", &frozen[2]).tight().tip(tips[2])})})};
}

void GuiElementary::showShape(int which)
{
  if(which >= 0 && which < 12)
    show(_shapes[which].name);
  else if(which >= 12 && which < 12 + 9)
    show(_picked[which - 12].name);
  else
    show();
}

#endif
