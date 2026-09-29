// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <map>
#include <string>
#include <vector>

#include "GuiPhysical.h"
#include "GuiDeclare.h"
#include "GModel.h"
#include "Geo.h"

using namespace Ui;
using namespace Declare;

int GuiPhysical::dimension() const
{
  if(type == "Volume") return 3;
  if(type == "Surface") return 2;
  if(type == "Curve") return 1;
  return 0;
}

void GuiPhysical::groups(std::map<int, std::string> &tags,
                         std::map<std::string, int> &names) const
{
  std::map<int, std::vector<GEntity *> > found;
  GModel::current()->getPhysicalGroups(dimension(), found);
  for(auto &g : found) {
    std::string n = GModel::current()->getPhysicalName(dimension(), g.first);
    tags[g.first] = n;
    if(n.size()) names[n] = g.first;
  }
}

// an existing group, or a new one whose tag Gmsh picks
void GuiPhysical::changed()
{
  std::map<int, std::string> tags;
  std::map<std::string, int> names;
  groups(tags, names);

  // the tag the other pane would give a new group means nothing here: the first
  // group there is
  if(pane() == "Remove") {
    if(tags.find(tag) == tags.end()) {
      tag = tags.empty() ? 0 : tags.begin()->first;
      name = tags.empty() ? "" : tags.begin()->second;
    }
    return;
  }

  auto byName = names.find(name);
  if(byName != names.end()) {
    append = true;
    if(automatic) tag = byName->second;
    return;
  }
  if(!automatic && tags.find(tag) != tags.end()) {
    append = true;
    return;
  }
  append = false;
  if(automatic) tag = NEWPHYSICAL();
}

Form GuiPhysical::build()
{
  std::string lower = type;
  for(auto &c : lower) c = (char)tolower((unsigned char)c);
  auto update = [this]() { changed(); };
  auto named = [this](std::vector<std::string> &labels, std::vector<int> &values) {
    std::map<int, std::string> tags;
    std::map<std::string, int> names;
    groups(tags, names);
    for(auto &n : names) {
      labels.push_back(n.first);
      values.push_back(n.second);
    }
  };
  auto tagged = [this](std::vector<std::string> &labels, std::vector<int> &values) {
    std::map<int, std::string> tags;
    std::map<std::string, int> names;
    groups(tags, names);
    for(auto &t : tags) {
      labels.push_back(std::to_string(t.first) +
                       (t.second.size() ? ": " + t.second : ""));
      values.push_back(t.first);
    }
  };
  auto pick = [this]() {
    std::map<int, std::string> tags;
    std::map<std::string, int> names;
    groups(tags, names);
    auto it = tags.find(tag);
    name = (it != tags.end()) ? it->second : "";
  };

  return {"physical", "Physical " + type + " Context",
          tabs({{"Add",
                 vbox({label("Create or choose group, and select " + lower +
                             "(s) to add"),
                       text("Name", &name).offering(named).onChanged(update),
                       hbox({integer("Tag", &tag)
                               .enabledWhen([this]() { return !automatic; })
                               .onChanged(update),
                             check("Automatic", &automatic).onChanged(update)})})},
                {"Remove",
                 // as wide as the Name field of the other pane: a choice sized
                 // to its entries is a sliver without groups
                 vbox({label("Choose group and select " + lower + "(s) to remove"),
                       choice("", &tag).offering(tagged).sized(18.).onChanged(pick)})}},
               [this](const std::string &) { changed(); })};
}

void GuiPhysical::load() { changed(); }

void GuiPhysical::show(const std::string &type_, bool remove_)
{
  type = type_;
  remove = remove_;
  show(remove ? "Remove" : "Add");
}

#endif
