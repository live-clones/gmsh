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
#include "Geo.h"

// "Elementary Operation Context": translate, rotate, scale, symmetry,
// boolean, fillet and delete, one pane each, on what one then selects.

namespace {

  using namespace Ui;
  using namespace Declare;

  namespace {

    // the fields that only make sense when the mesh is extruded along with the
    // geometry, which is decided by the action that opened the dialog
    std::vector<Field> extrudeFields()
    {
      geometryParameters &g = geometryStore();
      std::vector<Field> f;
      Field mesh = check("Extrude mesh", &g.extrudeMesh);
      mesh.enabled = []() { return Gui::instance().transform.extrude; };
      Field layers = text("Mesh layers", &g.layers);
      layers.enabled = []() {
        return Gui::instance().transform.extrude && geometryStore().extrudeMesh;
      };
      Field recombine = beside(check("Recombine", &g.recombineMesh));
      recombine.enabled = layers.enabled;
      f.push_back(mesh);
      f.push_back(layers);
      f.push_back(recombine);
      return f;
    }

    // "apply on copy" is meaningless while extruding: the extrusion makes the
    // copy itself
    Field onCopy(const std::string &label)
    {
      Field f = check(label, &geometryStore().duplicate);
      f.enabled = []() { return !Gui::instance().transform.extrude; };
      return f;
    }

    std::vector<Field> operator+(std::vector<Field> a,
                                 const std::vector<Field> &b)
    {
      a.insert(a.end(), b.begin(), b.end());
      return a;
    }

  } // namespace

  static Form describeTransform()
  {
    geometryParameters &g = geometryStore();
    Form p;
    p.title = "Elementary Operation Context";

    p.panes.push_back(
      pane(std::vector<Field>{text("DX", &g.tx), text("DY", &g.ty),
                              text("DZ", &g.tz),
                              onCopy("Apply translation on copy")} +
             extrudeFields(),
           "Translate"));
    p.panes.push_back(pane(
      std::vector<Field>{// the three components of the direction are half a
                         // field wide: what they
                         // hold is a component and not a coordinate
                         sized(text("Axis point X", &g.px), 10.),
                         beside(sized(text("Axis direction DX", &g.ax), 5.)),
                         sized(text("Axis point Y", &g.py), 10.),
                         beside(sized(text("Axis direction DY", &g.ay), 5.)),
                         sized(text("Axis point Z", &g.pz), 10.),
                         beside(sized(text("Axis direction DZ", &g.az), 5.)),
                         text("Angle", &g.angle),
                         onCopy("Apply rotation on copy")} +
        extrudeFields(),
      "Rotate"));
    p.panes.push_back(pane({text("Center X", &g.cx), text("Center Y", &g.cy),
                            text("Center Z", &g.cz), text("Scaling X", &g.sx),
                            text("Scaling Y", &g.sy), text("Scaling Z", &g.sz),
                            onCopy("Apply scaling on copy")},
                           "Scale"));
    {
      const char *tip = "A * X + B * Y + C * Z + D = 0";
      p.panes.push_back(pane({text("Symmetry plane coefficient A", &g.sa, tip),
                              text("Symmetry plane coefficient B", &g.sb, tip),
                              text("Symmetry plane coefficient C", &g.sc, tip),
                              text("Symmetry plane coefficient D", &g.sd, tip),
                              onCopy("Apply symmetry on copy")},
                             "Symmetry"));
    }
    p.panes.push_back(pane({check("Delete object", &g.deleteObject),
                            check("Delete tool", &g.deleteTool)},
                           "Boolean"));
    p.panes.push_back(pane({text("Radius", &g.radius)}, "Fillet"));
    p.panes.push_back(pane({check("Recursive", &g.recursive)}, "Delete"));

    Field mode =
      choice("Selection mode", &g.selection,
             {"All entities", "Points", "Curves", "Surfaces", "Volumes"},
             {ENT_ALL, ENT_POINT, ENT_CURVE, ENT_SURFACE, ENT_VOLUME});
    // filleting asks for volumes and then for curves, in that order: there is
    // nothing left to choose
    mode.enabled = []() {
      return Gui::instance().transform.pane() != "Fillet";
    };
    p.footer.push_back(mode);
    return p;
  }

} // namespace

Ui::Form GuiTransform::build()
{
  Ui::Form f = describeTransform();
  f.id = "transform";
  return f;
}

void GuiTransform::show(const std::string &pane, bool extrude_)
{
  extrude = extrude_;
  show(pane);
}

#endif
