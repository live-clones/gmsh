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
#include "GModel.h"
#include "Geo.h"

// "Physical Group Context": the group an entity is added to or removed
// from.

namespace {

  using namespace Ui;
  using namespace Declare;

  namespace {

    int physicalDimension()
    {
      const std::string &t = Gui::instance().physical.type;
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

    // naming a group that already exists means adding to it rather than
    // creating another one, which the dialog says in words
  } // namespace

  // which group the name and the tag stand for: an existing one, which the
  // entities are added to, or a new one, whose tag Gmsh picks; worked out
  // on every change and when it opens
  void physicalChanged()
  {
    geometryParameters &g = geometryStore();
    std::map<int, std::string> tags;
    std::map<std::string, int> names;
    physicalGroups(tags, names);

    // Removing acts on a group that exists. The tag the other pane would give
    // a new group means nothing here, so fall back to the first there is --
    // otherwise the list shows one group and the button removes another.
    if(Gui::instance().physical.pane() == "Remove") {
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
    std::string s = Gui::instance().physical.type;
    for(auto &c : s) c = (char)tolower((unsigned char)c);
    return s;
  }

  static Form describePhysical()
  {
    geometryParameters &g = geometryStore();
    Form p;
    // it says which kind of entity it is naming
    p.title = "Physical " + Gui::instance().physical.type + " Context";

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
      // no label, the line above already says what it is; as wide as the Name
      // field of the other pane: a choice sized to its longest entry is a
      // sliver when the model has no groups yet
      Field group = sized(integer("", &g.physicalTag), 18.);
      group.kind = Choice;
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

} // namespace

Ui::Form GuiPhysical::build()
{
  Ui::Form f = describePhysical();
  f.id = "physical";
  return f;
}

void GuiPhysical::load() { physicalChanged(); }


void GuiPhysical::show(const std::string &type_, bool remove_)
{
  type = type_;
  remove = remove_;
  show(remove ? "Remove" : "Add");
}

#endif
