// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The one description of the context dialogs, built by both interfaces. See
// GuiDialogs.h for the model; this file is meant to read like the forms it
// describes.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <map>
#include <string>
#include <vector>

#include "GuiDialogs.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "Context.h"
#include "GamePad.h"
#include "Options.h"
#include "GModel.h"
#include "GEntity.h"
#include "Geo.h"
#include "drawContext.h"

namespace Dialog {

  // --- where a field's value lives when it says a store address
  //
  // The vocabulary of src/gui knows that a field may name a place rather than
  // point at a variable, and nothing more: what the three parts of the name
  // mean is said here, once, and it is the only thing that ties the option
  // system of Gmsh to the description of a form.

  void installStore()
  {
    Ui::Store store;
    store.getNumber = [](const std::string &category, const std::string &name,
                         int index) {
      double v = 0.;
      NumberOption(GMSH_GET, category.c_str(), index, name.c_str(), v, false);
      return v;
    };
    store.setNumber = [](const std::string &category, const std::string &name,
                         int index, double v) {
      NumberOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(),
                   v, false);
    };
    store.getText = [](const std::string &category, const std::string &name,
                       int index) {
      std::string v;
      StringOption(GMSH_GET, category.c_str(), index, name.c_str(), v, false);
      return v;
    };
    store.setText = [](const std::string &category, const std::string &name,
                       int index, const std::string &v) {
      std::string s(v);
      StringOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(),
                   s, false);
    };
    store.getColour = [](const std::string &category, const std::string &name,
                         int index) {
      unsigned int v = 0;
      ColorOption(GMSH_GET, category.c_str(), index, name.c_str(), v, false);
      CTX *c = CTX::instance();
      return Ui::Colour((unsigned char)c->unpackRed(v),
                        (unsigned char)c->unpackGreen(v),
                        (unsigned char)c->unpackBlue(v),
                        (unsigned char)c->unpackAlpha(v));
    };
    store.setColour = [](const std::string &category, const std::string &name,
                         int index, const Ui::Colour &c) {
      unsigned int v = CTX::instance()->packColor(c.r, c.g, c.b, c.a);
      ColorOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(),
                  v, false);
    };
    Ui::setStore(store);
  }

  namespace {
    // Installed before anything can ask a field for its value. It captures
    // nothing and touches CTX only when a field is actually read, so there is
    // no order to get wrong here.
    struct _installer {
      _installer() { installStore(); }
    };
    _installer _install;
  } // namespace

  // --- what each dialog is showing

  int &currentPane(int dialog)
  {
    static int pane[NumDialogs] = {0, 0, 0, 0};
    static int nowhere = 0;
    if(dialog < 0 || dialog >= NumDialogs) return nowhere;
    return pane[dialog];
  }

  bool &extrudeMode()
  {
    static bool mode = false;
    return mode;
  }

  std::string &physicalType()
  {
    static std::string type = "Point";
    return type;
  }

  bool &physicalRemove()
  {
    static bool remove = false;
    return remove;
  }

  void partitionRead();
  void highOrderRead();
  void physicalChanged();

  void show(int dialog, int pane)
  {
    if(pane >= 0) currentPane(dialog) = pane;
    // the partitioner edits a copy, taken when it is shown
    if(dialog == Partition) partitionRead();
    // the high order dialog asks the mesh what it already is
    if(dialog == HighOrder) highOrderRead();
    // The statistics are counted when the window opens, quality apart: that one
    // costs, and waits for Update. The tab that opens is the one with something
    // in it, as the window this replaces chooses it.
    // the clipping dialog edits a copy of the plane it is showing
    if(dialog == Clipping) clippingRead();
    // and the physical one works out which group it is about
    if(dialog == Physical) physicalChanged();
    if(dialog == Statistics && !Gui::dialogVisible(Statistics)) {
      statisticsCompute(false);
      if(pane < 0) currentPane(Statistics) = statisticsFullestPane();
    }
    Gui::showDialog(dialog);
  }

  void showTransform(int pane, bool extrude)
  {
    extrudeMode() = extrude;
    show(Transform, pane);
  }

  void showPhysical(const std::string &type, bool remove)
  {
    physicalType() = type;
    physicalRemove() = remove;
    show(Physical, remove ? 1 : 0);
  }

  namespace {

    // the fields that only make sense when the mesh is extruded along with the
    // geometry, which is decided by the action that opened the dialog
    std::vector<Field> extrudeFields()
    {
      geometryParameters &g = geometryStore();
      std::vector<Field> f;
      Field mesh = check("Extrude mesh", &g.extrudeMesh);
      mesh.enabled = []() { return extrudeMode(); };
      Field layers = text("Mesh layers", &g.layers);
      layers.enabled = []() { return extrudeMode() && geometryStore().extrudeMesh; };
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
      f.enabled = []() { return !extrudeMode(); };
      return f;
    }

    std::vector<Field> operator+(std::vector<Field> a,
                                 const std::vector<Field> &b)
    {
      a.insert(a.end(), b.begin(), b.end());
      return a;
    }

  } // namespace

  // --- "Mesh Context"

  Panel meshContext()
  {
    geometryParameters &g = geometryStore();
    Panel p;
    p.title = "Mesh Context";
    p.panes.push_back(pane("Element size", {text("Value", &g.meshSize)}));
    p.panes.push_back(
      pane("Transfinite curve",
           {text("Number of points", &g.transfinitePoints),
            choice("Type", &g.transfiniteType,
                   {"Progression", "Bump", "Beta", "Progression_HWall",
                    "Bump_HWall", "Beta_HWall"}),
            text("Parameter", &g.transfiniteParameter)}));
    p.panes.push_back(pane("Transfinite Surface",
                           {choice("Transfinite Arrangement",
                                   &g.transfiniteArrangement,
                                   {"Left", "Right", "Alternated"})}));
    return p;
  }

  // --- "Elementary Operation Context"

  Panel transformContext()
  {
    geometryParameters &g = geometryStore();
    Panel p;
    p.title = "Elementary Operation Context";

    p.panes.push_back(pane(
      "Translate", std::vector<Field>{text("DX", &g.tx), text("DY", &g.ty),
                                      text("DZ", &g.tz),
                                      onCopy("Apply translation on copy")} +
                     extrudeFields()));
    p.panes.push_back(pane(
      "Rotate",
      std::vector<Field>{
        text("Axis point X", &g.px), beside(text("Axis direction DX", &g.ax)),
        text("Axis point Y", &g.py), beside(text("Axis direction DY", &g.ay)),
        text("Axis point Z", &g.pz), beside(text("Axis direction DZ", &g.az)),
        text("Angle", &g.angle), onCopy("Apply rotation on copy")} +
        extrudeFields()));
    p.panes.push_back(pane(
      "Scale", {text("Center X", &g.cx), text("Center Y", &g.cy),
                text("Center Z", &g.cz), text("Scaling X", &g.sx),
                text("Scaling Y", &g.sy), text("Scaling Z", &g.sz),
                onCopy("Apply scaling on copy")}));
    {
      const char *tip = "A * X + B * Y + C * Z + D = 0";
      p.panes.push_back(
        pane("Symmetry", {text("Symmetry plane coefficient A", &g.sa, tip),
                          text("Symmetry plane coefficient B", &g.sb, tip),
                          text("Symmetry plane coefficient C", &g.sc, tip),
                          text("Symmetry plane coefficient D", &g.sd, tip),
                          onCopy("Apply symmetry on copy")}));
    }
    p.panes.push_back(pane("Boolean", {check("Delete object", &g.deleteObject),
                                       check("Delete tool", &g.deleteTool)}));
    p.panes.push_back(pane("Fillet", {text("Radius", &g.radius)}));
    p.panes.push_back(pane("Delete", {check("Recursive", &g.recursive)}));

    Field mode = choice(
      "Selection mode", &g.selection,
      {"All entities", "Points", "Curves", "Surfaces", "Volumes"},
      {ENT_ALL, ENT_POINT, ENT_CURVE, ENT_SURFACE, ENT_VOLUME});
    // Filleting asks for volumes and then for curves, in that order: there is
    // nothing left to choose. It is the one operation of the ten that the
    // window this replaces greys it out for.
    mode.enabled = []() { return currentPane(Transform) != 5; };
    p.footer.push_back(mode);
    return p;
  }

  // --- "Elementary Entity Context"

  namespace {

    // The panes, with the label and default value of each of their fields, in
    // the order the FLTK window shows them. For every pane but the first, the
    // first three fields are the X, Y and Z the mouse drives.
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

    // Where a field goes, when a pane is not simply one field per line. The
    // cone is the only shape the window this replaces gives a second column:
    // its radii and its angle sit beside the axis rather than under it.
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

    // The commands whose entities are picked in the view rather than typed.
    // They had no pane at all: one saw the prompt in the status bar and had to
    // remember what one had clicked. The list shows it, and lets a misclick be
    // taken back without starting again.
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

  Panel elementaryContext()
  {
    fillElementaryDefaults();

    Panel p;
    p.title = "Elementary Entity Context";

    for(int i = 0; i < 12; i++) {
      Pane q;
      q.label = _shapes[i].name;
      // Twelve tabs do not fit across a window this wide; the window this
      // replaces carried two sets of six and a button to swap them without
      // saying what it swapped. They are grouped by what they make, in the
      // words Gmsh uses everywhere else. A parameter is not a shape and a
      // point has no extent, so those two stand alone.
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

  // --- "Physical Group Context"

  namespace {

    int physicalDimension()
    {
      const std::string &t = physicalType();
      if(t == "Volume") return 3;
      if(t == "Surface") return 2;
      if(t == "Curve") return 1;
      return 0;
    }

    // the groups that already exist, so that one can add to them or remove them
    void physicalGroups(std::map<int, std::string> &tags,
                        std::map<std::string, int> &names)
    {
      std::map<int, std::vector<GEntity *> > groups;
      GModel::current()->getPhysicalGroups(physicalDimension(), groups);
      for(auto &g : groups) {
        std::string name =
          GModel::current()->getPhysicalName(physicalDimension(), g.first);
        tags[g.first] = name;
        if(name.size()) names[name] = g.first;
      }
    }

    // Naming a group that already exists means adding to it rather than
    // creating another one, which is what the FLTK dialog says by colouring the
    // fields; here it says it in words.
  } // namespace

  // Which group the name and the tag stand for: an existing one, which the
  // entities are added to, or a new one, whose tag Gmsh picks. The window this
  // replaces works it out on every change and when it opens.
  void physicalChanged()
  {
    geometryParameters &g = geometryStore();
    std::map<int, std::string> tags;
    std::map<std::string, int> names;
    physicalGroups(tags, names);

    // Removing acts on a group that exists. The tag the other pane would give
    // a new group means nothing here, so fall back to the first there is --
    // otherwise the list shows one group and the button removes another.
    if(currentPane(Physical) == 1) {
      if(tags.find(g.physicalTag) == tags.end()) {
        g.physicalTag = tags.empty() ? 0 : tags.begin()->first;
        g.physicalName = tags.empty() ? "" : tags.begin()->second;
      }
      return;
    }

    auto byName = names.find(g.physicalName);
    if(byName != names.end()) {
      g.physicalAppend = true;
      if(g.physicalAutomatic) g.physicalTag = byName->second;
      return;
    }
    if(!g.physicalAutomatic && tags.find(g.physicalTag) != tags.end()) {
      g.physicalAppend = true;
      return;
    }
    g.physicalAppend = false;
    if(g.physicalAutomatic) g.physicalTag = NEWPHYSICAL();
  }

  // the kind of entity the dialog is grouping, as it reads in a sentence
  static std::string lowerType()
  {
    std::string s = physicalType();
    for(auto &c : s) c = (char)tolower((unsigned char)c);
    return s;
  }

  Panel physicalContext()
  {
    geometryParameters &g = geometryStore();
    Panel p;
    p.title = "Physical Group Context";

    {
      Pane add;
      add.label = "Add";
      add.chosen = physicalChanged;
      add.fields.push_back(says([]() {
        return "Create or choose group, and select " + lowerType() + "(s) to add";
      }));
      Field name = text("Name", &g.physicalName);
      name.dynamicChoices = [](std::vector<std::string> &labels,
                               std::vector<int> &values) {
        std::map<int, std::string> tags;
        std::map<std::string, int> names;
        physicalGroups(tags, names);
        for(auto &n : names) {
          labels.push_back(n.first);
          values.push_back(n.second);
        }
      };
      name.changed = physicalChanged;
      add.fields.push_back(name);

      Field tag = integer("Tag", &g.physicalTag);
      tag.enabled = []() { return !geometryStore().physicalAutomatic; };
      tag.changed = physicalChanged;
      add.fields.push_back(tag);

      Field automatic = beside(check("Automatic", &g.physicalAutomatic));
      automatic.changed = physicalChanged;
      add.fields.push_back(automatic);
      p.panes.push_back(add);
    }
    {
      Pane remove;
      remove.label = "Remove";
      remove.chosen = physicalChanged;
      remove.fields.push_back(says([]() {
        return "Choose group and select " + lowerType() + "(s) to remove";
      }));
      // no label: the line above already says what it is, as in the window
      // this replaces
      // as wide as the Name field of the other pane, whatever it happens to
      // hold: a choice sized to its longest entry is a sliver when the model
      // has no groups yet
      Field group = sized(integer("", &g.physicalTag), 18.);
      group.kind = Choice;
      group.integer = &g.physicalTag;
      group.dynamicChoices = [](std::vector<std::string> &labels,
                                std::vector<int> &values) {
        std::map<int, std::string> tags;
        std::map<std::string, int> names;
        physicalGroups(tags, names);
        for(auto &t : tags) {
          std::string label = std::to_string(t.first);
          if(t.second.size()) label += ": " + t.second;
          labels.push_back(label);
          values.push_back(t.first);
        }
      };
      group.changed = []() {
        std::map<int, std::string> tags;
        std::map<std::string, int> names;
        physicalGroups(tags, names);
        auto it = tags.find(geometryStore().physicalTag);
        geometryStore().physicalName = (it != tags.end()) ? it->second : "";
      };
      remove.fields.push_back(group);
      p.panes.push_back(remove);
    }
    return p;
  }

  // --- the mesh partitioner
  //
  // Like the FLTK dialog it replaces, it works on a copy: the values are read
  // from the options when it is shown and only written back by "Partition", so
  // that closing it changes nothing. That is why the fields are bound to a
  // store of ours rather than to the options themselves.

  namespace {

    struct partitionValues {
      int num;
      bool topology, physicals, ghostCells;
      int algorithm, edgeMatching, refinement;
      int triWeight, quaWeight, tetWeight, priWeight, pyrWeight, hexWeight;
      // the only partitioner there is, but the dialog has always said so
      int partitioner;
      bool advanced;
      // partitionRead() fills them from the options before the window shows,
      // but a value that is never anything is easier to spot than one that is
      // whatever the stack held
      partitionValues()
        : num(0), topology(false), physicals(false), ghostCells(false),
          algorithm(0), edgeMatching(0), refinement(0), triWeight(0),
          quaWeight(0), tetWeight(0), priWeight(0), pyrWeight(0), hexWeight(0),
          partitioner(1), advanced(false)
      {
      }
    };

    partitionValues &partitionStore()
    {
      static partitionValues v;
      return v;
    }

  } // namespace

  void partitionRead()
  {
    partitionValues &v = partitionStore();
    auto &m = CTX::instance()->mesh;
    v.num = m.numPartitions;
    v.topology = m.partitionCreateTopology;
    v.physicals = m.partitionCreatePhysicals;
    v.ghostCells = m.partitionCreateGhostCells;
    v.algorithm = m.metisAlgorithm;
    v.edgeMatching = m.metisEdgeMatching;
    v.refinement = m.metisRefinementAlgorithm;
    v.triWeight = m.partitionTriWeight;
    v.quaWeight = m.partitionQuaWeight;
    v.tetWeight = m.partitionTetWeight;
    v.priWeight = m.partitionPriWeight;
    v.pyrWeight = m.partitionPyrWeight;
    v.hexWeight = m.partitionHexWeight;
  }

  static void partitionWrite()
  {
    partitionValues &v = partitionStore();
    auto &m = CTX::instance()->mesh;
    m.numPartitions = v.num;
    m.partitionCreateTopology = v.topology;
    m.partitionCreatePhysicals = v.physicals;
    m.partitionCreateGhostCells = v.ghostCells;
    m.metisAlgorithm = v.algorithm;
    m.metisEdgeMatching = v.edgeMatching;
    m.metisRefinementAlgorithm = v.refinement;
    m.partitionTriWeight = v.triWeight;
    m.partitionQuaWeight = v.quaWeight;
    m.partitionTetWeight = v.tetWeight;
    m.partitionPriWeight = v.priWeight;
    m.partitionPyrWeight = v.pyrWeight;
    m.partitionHexWeight = v.hexWeight;
  }

  Panel partition()
  {
    partitionValues &v = partitionStore();
    Panel p;
    p.title = "Partition";
    p.tabbed = false;

    {
      Field who = choice("Partitioner", &v.partitioner, {"Metis"}, {1});
#if !defined(HAVE_METIS)
      who.enabled = []() { return false; };
#endif

      Field num = integer("Number of Partitions", &v.num);
      // as in the FLTK dialog, the count picks the algorithm for you
      num.changed = []() {
        partitionStore().algorithm = (partitionStore().num <= 8) ? 1 : 2;
      };

      p.panes.push_back(ruled(pane(
        "", {who, beside(num), check("Create partition topology", &v.topology),
             beside(check("Create ghost cells", &v.ghostCells)),
             check("Create physical groups", &v.physicals)})));
    }

    p.panes.push_back(ruled(pane(
      "", {choice("Algorithm", &v.algorithm, {"Recursive", "K-way"}, {1, 2}),
           beside(disclosure("Advanced", &v.advanced))})));

    {
      Pane adv;
      adv.visible = []() { return partitionStore().advanced; };
      adv.fields.push_back(choice("Edge matching", &v.edgeMatching,
                                  {"Random", "Sorted heavy-edge"}, {1, 2}));
      adv.fields.push_back(beside(
        choice("Refinement algorithm", &v.refinement,
               {"FM-based cut", "Greedy", "Two-sided node FM",
                "One-sided node FM"},
               {1, 2, 3, 4})));
      // the weights are two rows of three, as in the window this replaces
      adv.fields.push_back(integer("Triangle", &v.triWeight));
      adv.fields.push_back(beside(integer("Tetrahedron", &v.tetWeight)));
      adv.fields.push_back(beside(integer("Prism", &v.priWeight)));
      adv.fields.push_back(integer("Quadrangle", &v.quaWeight));
      adv.fields.push_back(beside(integer("Hexahedron", &v.hexWeight)));
      adv.fields.push_back(beside(integer("Pyramid", &v.pyrWeight)));
      adv.separatorAfter = true;
      p.panes.push_back(adv);
    }

    Button defaults;
    defaults.label = "Defaults";
    defaults.apart = true;
    // in the FLTK dialog this reads the options again, throwing the edits away
    defaults.action = partitionRead;
    p.buttons.push_back(defaults);

    Button go;
    go.label = "Partition";
    go.isDefault = true;
    go.action = []() {
      partitionWrite();
      meshPartition();
    };
    p.buttons.push_back(go);
    return p;
  }


  // --- the high order tools
  //
  // Two sections one under the other: making the nodes of a high order mesh,
  // then moving them until the elements are valid. What the second one offers
  // depends on the algorithm, and the optimizer is the only one that uses more
  // than the number of layers.

  namespace {

    highOrderParameters &hoStore() { return highOrderStore(); }

    bool hoOptimizing() { return hoStore().algorithm == 0; }
    // the patch adaptation fields only mean something to that one strategy
    bool hoAdaptive()
    {
      return hoOptimizing() && hoStore().strategy == 1;
    }

  } // namespace

  void highOrderRead()
  {
    int order = -1;
    bool complete = true, cad = true;
    highOrderMeshInfo(order, complete, cad);
    highOrderParameters &v = hoStore();
    if(order > 0) v.order = order;
    v.incomplete = !complete;
    v.cadAvailable = cad;
    // the window this replaces offers "free" when there is a CAD model to move
    // the boundary nodes along, and greys the choice out when there is not
    v.boundaryNodes = cad ? 1 : 0;
  }

  Panel highOrder()
  {
    highOrderParameters &v = hoStore();
    Panel p;
    p.title = "High-order tools";
    p.tabbed = false;

    {
      Pane head;
      head.fields.push_back(says([]() {
        return hoStore().cadAvailable ? "CAD model is available" :
                                        "CAD model is not available";
      }));
      head.fields.push_back(
        check("Only apply high-order tools to visible entities", &v.onlyVisible));
      head.fields.push_back(check("Show detailed log messages", &v.showLog));
      p.panes.push_back(ruled(head));
    }

    {
      Pane gen;
      gen.label = "1. Generation of high-order nodes";
      gen.fields.push_back(
        within(integer("Polynomial order", &v.order), 1, 10, 1));
      gen.fields.push_back(check("Generate incomplete elements", &v.incomplete));
      gen.fields.push_back(check("Use CAD model to curve mesh", &v.useCAD));
      gen.buttonLabel = "Generate";
      gen.button = []() {
        highOrderParameters p = hoStore();
        p.linear = !p.useCAD;
        highOrderSetOrder(p);
      };
      p.panes.push_back(ruled(gen));
    }

    {
      Pane opt;
      opt.label = "2. Regularization of high-order elements";
      opt.fields.push_back(
        choice("Algorithm", &v.algorithm,
               {"Optimization", "Elastic Analogy", "Fast Curving",
                "Boundary Layer Curving (experimental)"},
               {0, 1, 2, 3}));

      // the two ends of the range share a line, and one label. Each takes
      // half the width of an input rather than a share of the line, so that
      // the pair fills exactly one, as in the window this replaces
      Field lo = shared(within(number("", &v.thresholdMin), 0., 1., .01), .5);
      Field hi = beside(shared(
        within(number("Target Jacobian range", &v.thresholdMax), 1., 10., .01),
        .5));
      lo.enabled = hoOptimizing;
      hi.enabled = hoOptimizing;
      opt.fields.push_back(lo);
      opt.fields.push_back(hi);

      // the only field every algorithm uses
      opt.fields.push_back(
        within(integer("Number of layers", &v.numLayers), 1, 250, 1));

      auto onlyOptimizer = [](Field f) {
        f.enabled = hoOptimizing;
        return f;
      };
      opt.fields.push_back(onlyOptimizer(
        within(number("Distance factor", &v.distanceFactor), 1., 20000., 1.)));
      {
        Field nodes = choice("Boundary nodes", &v.boundaryNodes,
                             {"Fixed", "Free"}, {0, 1});
        // without a CAD model there is nothing to move them along
        nodes.enabled = []() {
          return hoOptimizing() && hoStore().cadAvailable;
        };
        opt.fields.push_back(nodes);
      }
      opt.fields.push_back(onlyOptimizer(
        number("Weight on node displacement", &v.weight)));
      opt.fields.push_back(onlyOptimizer(
        within(integer("Maximum number of iterations", &v.iterMax), 1, 10000, 10)));
      opt.fields.push_back(onlyOptimizer(within(
        integer("Max. number of barrier updates", &v.passMax), 1, 100, 1)));
      opt.fields.push_back(onlyOptimizer(
        choice("Strategy", &v.strategy,
               {"Disjoint strong", "Adaptive one-by-one", "Disjoint weak"},
               {0, 1, 2})));

      auto onlyAdaptive = [](Field f) {
        f.enabled = hoAdaptive;
        return f;
      };
      opt.fields.push_back(onlyAdaptive(within(
        number("Max. number of patch adaptation iter.", &v.maxAdaptBlob), 1., 100.,
               1.)));
      opt.fields.push_back(onlyAdaptive(within(
        integer("Num. layer adaptation factor", &v.adaptBlobLayerFact), 1, 100, 1)));
      opt.fields.push_back(onlyAdaptive(within(
        number("Distance adaptation factor", &v.adaptBlobDistFact), 1., 100., 1.)));

      opt.buttonLabel = "Regularize";
      opt.button = []() {
        highOrderParameters p = hoStore();
        // as the window this replaces computes it: free boundary nodes only
        // mean anything when there is a CAD model
        p.fixBoundaryNodes = (p.cadAvailable && p.boundaryNodes) ? true : false;
        if(p.showLog) Gui::showPanel(Gui::PanelMessageConsole, true);
        highOrderOptimize(p);
      };
      p.panes.push_back(opt);
    }
    return p;
  }


  // --- the manipulator
  //
  // A three by three grid: the rotation, the translation and the scale of the
  // view, one row each, X Y and Z across. The values are Gmsh options, and
  // setting one reaches the draw context of the window that has the focus, so
  // there is nothing of our own to hold.

  Panel manipulator()
  {
    Panel p;
    p.title = "Manipulator";
    p.tabbed = false;

    auto axis = [](const char *name, int i, double lo, double hi, double step) {
      std::string full = std::string(name) + (char)('X' + i);
      Field f = within(option(Number, "", "General", full), lo, hi, step);
      f.tooltip = "General." + full;
      f.changed = []() {
        // The rotation is kept as a quaternion and the three angles are read
        // back from it. Without this, an angle that has just been given is
        // recomputed away before it is ever drawn.
        if(drawContext *ctx = Gui::getCurrentDrawContext())
          ctx->setQuaternionFromEulerAngles();
        drawContext::global()->draw();
      };
      f.sameRow = true;
      // three narrow boxes across, as the window this replaces has them:
      // seven times the font size is what it gives them, and it is what the
      // two interfaces should give them whatever they call an ordinary field
      f.widthEm = 7.;
      return f;
    };

    Pane grid;
    // A grid, and not three lines that each share themselves out: the columns
    // of one row have to line up with the columns of the next, and "Rotation"
    // is not as wide as "Translation".
    grid.columns = 4;
    // the heading of each column, over nothing in the first
    grid.fields.push_back(says([]() { return std::string(""); }));
    for(int i = 0; i < 3; i++) {
      Field h = says([i]() { return std::string(1, (char)('X' + i)); });
      h.sameRow = true;
      grid.fields.push_back(h);
    }
    struct row {
      const char *name;
      double lo, hi, step;
    };
    // the translation is bounded by the size of the model, which the window
    // this replaces recomputes every time it shows; leaving it open is simpler
    // and no less correct
    const row rows[] = {{"Rotation", -360., 360., 1.},
                        {"Translation", 0., 0., 0.},
                        {"Scale", 0.01, 100., 0.01}};
    for(const auto &r : rows) {
      std::string label = r.name;
      grid.fields.push_back(says([label]() { return label; }));
      for(int i = 0; i < 3; i++)
        grid.fields.push_back(axis(r.name, i, r.lo, r.hi, r.step));
    }
    p.panes.push_back(grid);

    Button reset;
    reset.label = "Reset";
    // a plain button in the window this replaces: resetting the view is not
    // what pressing Enter in one of these boxes should do
    reset.action = []() {
      if(drawContext *ctx = Gui::getCurrentDrawContext())
        viewSetOrientation(ctx, "reset", false);
      drawContext::global()->draw();
    };
    p.buttons.push_back(reset);
    return p;
  }


  // --- the statistics
  //
  // What the model is made of, one tab for the geometry, one for the mesh and
  // one for the views. The numbers all come from one array that
  // statisticsCompute() fills; which index means what is said here, once, and
  // nowhere else.

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

  Panel statistics()
  {
    Panel p;
    p.title = "Statistics";

    p.panes.push_back(pane("Geometry", {stat("Points", 0), stat("Curves", 1),
                                        stat("Surfaces", 2), stat("Volumes", 3),
                                        stat("Physical groups", 45)}));
    {
      Pane mesh;
      mesh.label = "Mesh";
      // A grid, so that the three buttons of a quality line stand under one
      // another: their line begins with a value whose label is "SICN" on one
      // and "Gamma" on the next, and packing them against it would stagger
      // them by the difference.
      mesh.columns = 4;
      const char *counts[] = {"Nodes",      "Points",   "Lines",
                              "Triangles",  "Quadrangles", "Tetrahedra",
                              "Hexahedra",  "Prisms",   "Pyramids",
                              "Trihedra"};
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
      mesh.fields.push_back(check("Compute statistics for visible entities only",
                                  &statisticsVisibleOnly()));
      p.panes.push_back(mesh);
    }
    {
      const char *counts[] = {"Views",      "Points",      "Lines",
                              "Triangles",  "Quadrangles", "Tetrahedra",
                              "Hexahedra",  "Prisms",      "Pyramids",
                              "Trihedra",   "Strings"};
      Pane post;
      post.label = "Post-processing";
      for(int i = 0; i < 11; i++) post.fields.push_back(stat(counts[i], 27 + i));
      p.panes.push_back(post);
    }

    p.footer.push_back(says([]() {
      double mb = statisticsMemoryUsage();
      if(mb <= 0.) return std::string("");
      char tmp[64];
      sprintf(tmp, "Memory usage: %gMB", mb);
      return std::string(tmp);
    }));

    // the memory usage and Update share the last line, as they do in the
    // window this replaces
    p.buttonsInFooter = true;

    Button update;
    update.label = "Update";
    update.isDefault = true;
    update.action = []() { statisticsCompute(true); };
    p.buttons.push_back(update);
    return p;
  }

  // --- the clipping planes
  //
  // Six planes, or the box that six of them make, and a list down the side of
  // what each cuts. The dialog works on a copy, as the partitioner does: the
  // plane being edited is read when it is chosen and written back at every
  // change.

  Panel clipping()
  {
    clippingParameters &v = clippingStore();
    Panel p;
    p.title = "Clipping";

    // what the planes cut: the geometry, the mesh, and each view
    p.side.push_back(chooseFrom(
      [](std::vector<std::string> &labels, std::vector<int> &values) {
        clippingTargets(labels);
        for(std::size_t i = 0; i < labels.size(); i++) values.push_back((int)i);
      },
      clippingCuts, clippingSetCuts, true));
    p.side.back().rows = 8;

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
        // No bounds and no step, as in the window this replaces: the first
        // three are a direction that is normalised anyway, so holding them
        // between -1 and 1 would only rewrite what was typed.
        Field f = number(names[j], &v.coefficient[j], tip);
        f.changed = []() {
          clippingStore().asBox = false;
          clippingWrite();
        };
        planes.fields.push_back(f);
      }
      // the window this replaces says this with a tall thin "-" beside the
      // four numbers; on its own line it has room to say what it does
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

  // --- the gamepad
  //
  // What the pad is doing -- a light per button and per axis, which the panel
  // watches rather than holds -- and what each of its buttons and axes is
  // made to do. The window this replaces is one column of lights over two
  // columns of mappings.

  namespace {

    // a light that says whether a button or an axis is being used: it is read
    // and never set, and is drawn dead, as that window draws it
    Field light(const std::string &label, std::function<double()> what)
    {
      Field f;
      f.kind = Check;
      f.label = label;
      f.readNumber = what;
      f.enabled = []() { return false; };
      f.packed = true;
      f.sameRow = true;
      return f;
    }

    // one of the numbers that say which button or axis does what
    Field mapped(const std::string &label, int *value)
    {
      Field f;
      f.kind = Integer;
      f.label = label;
      f.integer = value;
      f.widthEm = 2.5;
      return f;
    }

  } // namespace

  Panel gamepad()
  {
    Panel p;
    p.title = "Gamepad Configuration Tool (in work)";
    p.tabbed = false;
    GamePad *pad = CTX::instance()->gamepad;
    if(!pad) return p;
    // the lights follow the pad, which nothing else tells us about
    p.refreshEvery = pad->frequency > 0. ? pad->frequency : .1;

    Pane pane;
    pane.columns = 2;
    pane.fields.push_back(says([]() { return std::string("Gamepad buttons:"); }));
    for(int i = 0; i < 13 && i < GP_BUTTONS; i++) {
      Field f = light(std::to_string(i),
                      [pad, i]() { return pad->button[i] ? 1. : 0.; });
      if(!i) f.sameRow = false;
      pane.fields.push_back(f);
    }
    pane.fields.push_back(says([]() { return std::string("Gamepad axes:"); }));
    for(int i = 0; i < 9 && i < GP_AXES; i++) {
      Field f = light(std::to_string(i),
                      [pad, i]() { return pad->axe[i] != 0. ? 1. : 0.; });
      if(!i) f.sameRow = false;
      pane.fields.push_back(f);
    }
    pane.fields.push_back(says([]() { return std::string("Preferences:"); }));

    // the axes on the left, the buttons on the right, as that window has them
    const char *const axes[] = {"head right/left with button (*)",
                                "head up/down with button (*)",
                                "turn left/right",
                                "for/backward or up/down ",
                                "move aside left/right",
                                "move up/down",
                                "speed up/slow down"};
    const char *const buttons[] = {"1:1",
                                   "permute axes",
                                   "reset/invers up axis",
                                   "change nav-mode",
                                   "(*) move head",
                                   " ",
                                   "walk / swimm",
                                   " ",
                                   "1:1 ; reset speed"};
    Field left = says([]() { return std::string("Action Axes:"); });
    Field right = says([]() { return std::string("Action buttons:"); });
    right.sameRow = true;
    pane.fields.push_back(left);
    pane.fields.push_back(right);
    for(int i = 0; i < 9; i++) {
      if(i < 7)
        pane.fields.push_back(mapped(axes[i], &pad->axe_map[i]));
      else
        // nothing on the left of these two: the buttons outnumber the axes
        pane.fields.push_back(says([]() { return std::string(""); }));
      Field f = mapped(buttons[i], &pad->button_map[i]);
      f.sameRow = true;
      pane.fields.push_back(f);
    }
    p.panes.push_back(pane);
    return p;
  }

  Panel panel(int dialog)
  {
    switch(dialog) {
    case Elementary: return elementaryContext();
    case Physical: return physicalContext();
    case Transform: return transformContext();
    case Mesh: return meshContext();
    case Partition: return partition();
    case HighOrder: return highOrder();
    case Manipulator: return manipulator();
    case Statistics: return statistics();
    case Clipping: return clipping();
    case Options: return options();
    case Gamepad: return gamepad();
    case Visibility: return visibility();
    case Plugins: return plugins();
    case Fields: return fields();
    case Classify: return classify();
    case Shortcuts: return shortcuts();
    case CurrentOptions: return currentOptions();
    case About: return about();
    case OnelabContext: return onelabContext();
    case OptionValue: return optionValue();
    case Arrow: return arrow();
    case History: return history();
    default: return Panel();
    }
  }

} // namespace Dialog

#endif
