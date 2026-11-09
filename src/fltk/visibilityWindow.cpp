// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <memory>
#include <cstdint>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include "accentTabs.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "drawContext.h"
#include "visibilityWindow.h"
#include "sceneTool.h"
#include "hintInput.h"
#include "paletteWindow.h"
#include "contextWindow.h"
#include "selectionDriver.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "onelabContextWindow.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "scriptStringInterface.h"
#include "Context.h"
#include "StringUtils.h"
#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "partitionRegion.h"
#include "OverlapEntities.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

class Vis {
private:
  std::string _name;

public:
  Vis() {}
  Vis(std::string &name) : _name(name) {}
  virtual ~Vis() {}
  virtual int getTag() const = 0;
  virtual int getDim() const { return -1; }
  virtual std::string getName() const { return _name; }
  virtual std::string getType() const = 0;
  virtual char getVisibility() const = 0;
  virtual void setVisibility(char val, bool recursive = false,
                             bool allmodels = false) = 0;
  std::string getBrowserLine(bool tabs = true)
  {
    std::ostringstream sstream;
    if(tabs)
      sstream << "\t" << getType() << "\t" << getTag() << "\t" << getName();
    else
      sstream << " " << getType() << " " << getTag() << " " << getName();
    return sstream.str();
  }
  bool match(const searchFilter &f) { return f.matches(getBrowserLine(false)); }
};

class VisModel : public Vis {
private:
  GModel *_model;
  int _tag;

public:
  VisModel(GModel *model, int tag, std::string &name)
    : Vis(name), _model(model), _tag(tag)
  {
  }
  ~VisModel() {}
  int getTag() const { return _tag; }
  std::string getType() const { return "Model"; }
  char getVisibility() const { return _model->getVisibility(); }
  void setVisibility(char val, bool recursive = false, bool allmodels = false)
  {
    _model->setVisibility(val);
  }
};

static void setVisibilityOnOtherModels(GEntity *ge, char val, bool recursive)
{
  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m2 = GModel::list[i];
    if(m2 != ge->model()) {
      GEntity *ge2 = nullptr;
      switch(ge->dim()) {
      case 0: ge2 = m2->getVertexByTag(ge->tag()); break;
      case 1: ge2 = m2->getEdgeByTag(ge->tag()); break;
      case 2: ge2 = m2->getFaceByTag(ge->tag()); break;
      case 3: ge2 = m2->getRegionByTag(ge->tag()); break;
      }
      if(ge2) ge2->setVisibility(val, recursive);
    }
  }
}

class VisElementary : public Vis {
private:
  GEntity *_e;

public:
  VisElementary(GEntity *e, std::string &name) : Vis(name), _e(e) {}
  ~VisElementary() {}
  int getTag() const { return _e->tag(); }
  int getDim() const { return _e->dim(); }
  std::string getType() const
  {
    if(_e->dim() == 0)
      return "Point";
    else if(_e->dim() == 1)
      return "Curve";
    else if(_e->dim() == 2)
      return "Surface";
    else
      return "Volume";
  }
  char getVisibility() const { return _e->getVisibility(); }
  void setVisibility(char val, bool recursive = false, bool allmodels = false)
  {
    _e->setVisibility(val, recursive);
    if(allmodels) setVisibilityOnOtherModels(_e, val, recursive);
  }
};

// whether some of the entities are shown (or there are none): how a group or
// a partition is shown in the list when it is filled
static char anyVisible(const std::vector<GEntity *> &entities)
{
  for(GEntity *ge : entities)
    if(ge->getVisibility()) return 1;
  return entities.empty() ? 1 : 0;
}

class VisPhysical : public Vis {
private:
  int _tag, _dim;
  char _visible;
  std::vector<GEntity *> _list;

public:
  VisPhysical(int tag, int dim, const std::vector<GEntity *> &list,
              std::string &name)
    : Vis(name), _tag(tag), _dim(dim), _visible(anyVisible(list)), _list(list)
  {
  }
  ~VisPhysical() {}
  int getTag() const { return _tag; }
  int getDim() const { return _dim; }
  std::string getType() const
  {
    if(_dim == 0)
      return "Point";
    else if(_dim == 1)
      return "Curve";
    else if(_dim == 2)
      return "Surface";
    else
      return "Volume";
  }
  char getVisibility() const { return _visible; }
  void setVisibility(char val, bool recursive = false, bool allmodels = false)
  {
    _visible = val;
    for(std::size_t i = 0; i < _list.size(); i++) {
      _list[i]->setVisibility(val, recursive);
      if(allmodels) setVisibilityOnOtherModels(_list[i], val, recursive);
    }
  }
};

// the partitions of an entity without copying the vector (an overlap entity
// stores a single partition, hence the scratch argument)
static const std::vector<int> *partitionsOf(GEntity *ge, std::vector<int> &tmp)
{
  switch(ge->geomType()) {
  case GEntity::PartitionPoint:
    return &static_cast<partitionVertex *>(ge)->getPartitions();
  case GEntity::PartitionCurve:
    return &static_cast<partitionEdge *>(ge)->getPartitions();
  case GEntity::PartitionSurface:
    return &static_cast<partitionFace *>(ge)->getPartitions();
  case GEntity::PartitionVolume:
    return &static_cast<partitionRegion *>(ge)->getPartitions();
  // overlap entities are not partition entities: they store the partition
  // they belong to as a single tag
  case GEntity::OverlapSurface:
    tmp.assign(1, static_cast<overlapFace *>(ge)->owningPartition());
    return &tmp;
  case GEntity::OverlapVolume:
    tmp.assign(1, static_cast<overlapRegion *>(ge)->owningPartition());
    return &tmp;
  default: return nullptr;
  }
}

// which entities belong to which partition, built once when the browser is
// filled: without it applying a selection walks the model once per partition
static std::map<int, std::vector<GEntity *> > _partitionIndex;
static GModel *_partitionIndexModel = nullptr;

static void buildPartitionIndex(GModel *m)
{
  _partitionIndex.clear();
  _partitionIndexModel = m;
  std::vector<GEntity *> entities;
  m->getEntities(entities);
  std::vector<int> tmp;
  for(std::size_t i = 0; i < entities.size(); i++) {
    const std::vector<int> *ps = partitionsOf(entities[i], tmp);
    if(!ps) continue;
    for(std::size_t j = 0; j < ps->size(); j++)
      _partitionIndex[(*ps)[j]].push_back(entities[i]);
  }
}

class VisPartition : public Vis {
private:
  int _tag;
  char _visible;

public:
  // (after buildPartitionIndex())
  VisPartition(int tag) : _tag(tag), _visible(1)
  {
    auto it = _partitionIndex.find(tag);
    if(it != _partitionIndex.end()) _visible = anyVisible(it->second);
  }
  ~VisPartition() {}
  int getTag() const { return _tag; }
  std::string getType() const { return "Partition"; }
  char getVisibility() const { return _visible; }
  // only mark the partition in the browser, without touching the entities
  void setListVisibility(char val) { _visible = val; }
  void setVisibility(char val, bool recursive = false, bool allmodels = false)
  {
    _visible = val;
    for(std::size_t i = 0; i < GModel::list.size(); i++) {
      GModel *m = GModel::list[i];
      if(!allmodels && m != GModel::current()) continue;
      if(m == _partitionIndexModel) { // the entities are already known
        auto it = _partitionIndex.find(_tag);
        if(it != _partitionIndex.end())
          for(std::size_t j = 0; j < it->second.size(); j++)
            it->second[j]->setVisibility(val, recursive);
        continue;
      }
      std::vector<GEntity *> entities;
      m->getEntities(entities);
      std::vector<int> tmp;
      for(std::size_t j = 0; j < entities.size(); j++) {
        const std::vector<int> *ps = partitionsOf(entities[j], tmp);
        if(!ps) continue;
        for(std::size_t k = 0; k < ps->size(); k++)
          if((*ps)[k] == _tag) entities[j]->setVisibility(val, recursive);
      }
    }
  }
};

class VisibilityList { // singleton
private:
  std::vector<Vis *> _entities;
  int _sortMode;
  static VisibilityList *_instance;
  VisibilityList() : _sortMode(-1) {}

public:
  enum VisibilityType {
    Models = 1,
    ElementaryEntities = 2,
    PhysicalEntities = 3,
    MeshPartitions = 4,
  };
  static VisibilityList *instance()
  {
    if(!_instance) _instance = new VisibilityList();
    return _instance;
  }
  class VisLessThan {
  public:
    bool operator()(const Vis *v1, const Vis *v2) const
    {
      switch(instance()->getSortMode()) {
      case 1:
        if(v1->getDim() < v2->getDim())
          return true;
        else if(v1->getDim() > v2->getDim())
          return false;
        else
          return v1->getTag() < v2->getTag();
      case -1:
        if(v1->getDim() > v2->getDim())
          return true;
        else if(v1->getDim() < v2->getDim())
          return false;
        else
          return v1->getTag() < v2->getTag();
      case 2: return v1->getTag() < v2->getTag() ? true : false;
      case -2: return v1->getTag() > v2->getTag() ? true : false;
      case 3:
        return strcmp(v1->getName().c_str(), v2->getName().c_str()) < 0 ? true :
                                                                          false;
      default:
        return strcmp(v1->getName().c_str(), v2->getName().c_str()) > 0 ? true :
                                                                          false;
      }
    }
  };
  // repopulate the list with current data of the given type
  void update(VisibilityType type, const searchFilter &search)
  {
    std::map<int, std::string> oldLabels;
#if defined(HAVE_PARSER)
    for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); ++it)
      if(it->first.size())
        for(std::size_t i = 0; i < it->second.value.size(); i++)
          oldLabels[(int)it->second.value[i]] =
            std::string("(") + it->first + ")";
#endif
    for(std::size_t i = 0; i < _entities.size(); i++) delete _entities[i];
    _entities.clear();
    GModel *m = GModel::current();

    if(type == Models) {
      for(std::size_t i = 0; i < GModel::list.size(); i++) {
        std::string name = GModel::list[i]->getName();
        if(GModel::list[i] == GModel::current()) name += " (Current Model)";
        Vis *v = new VisModel(GModel::list[i], i, name);
        if(v->match(search))
          _entities.push_back(v);
        else
          delete v;
      }
    }
    else if(type == ElementaryEntities) {
      std::vector<GEntity *> entities;
      m->getEntities(entities);
      for(std::size_t i = 0; i < entities.size(); i++) {
        GEntity *ge = entities[i];
        std::string name = m->getElementaryName(ge->dim(), ge->tag());
        if(name.empty()) name = oldLabels[ge->tag()];
        Vis *v = new VisElementary(ge, name);
        if(v->match(search))
          _entities.push_back(v);
        else
          delete v;
      }
    }
    else if(type == PhysicalEntities) {
      std::map<int, std::vector<GEntity *> > groups[4];
      m->getPhysicalGroups(groups);
      for(int i = 0; i < 4; i++) {
        for(auto it = groups[i].begin(); it != groups[i].end(); ++it) {
          std::string name = m->getPhysicalName(i, it->first);
          if(name.empty()) name = oldLabels[it->first];
          Vis *v = new VisPhysical(it->first, i, it->second, name);
          if(v->match(search))
            _entities.push_back(v);
          else
            delete v;
        }
      }
    }
    else if(type == MeshPartitions) {
      buildPartitionIndex(m);
      for(std::size_t part = 0; part < m->getNumPartitions(); part++) {
        Vis *v = new VisPartition(part + 1);
        if(v->match(search))
          _entities.push_back(v);
        else
          delete v;
      }
    }
    std::sort(_entities.begin(), _entities.end(), VisLessThan());
  }
  // get the number of entities in the list
  int getNumEntities() { return _entities.size(); }
  // get the number of entities in the list
  Vis *getEntity(int i) { return _entities[i]; }
  // get the visibility information for the nth entity in the list
  char getVisibility(int n) { return _entities[n]->getVisibility(); }
  // set the visibility information for the nth entity in the list
  void setVisibility(int n, char val, bool recursive = false,
                     bool allmodels = false)
  {
    _entities[n]->setVisibility(val, recursive, allmodels);
  }
  // set all entities to be invisible
  void setAllInvisible(VisibilityType type, bool allmodels = false)
  {
    if(type == Models) {
      for(std::size_t i = 0; i < GModel::list.size(); i++)
        GModel::list[i]->setVisibility(0);
    }
    else if(type == ElementaryEntities || type == PhysicalEntities) {
      // elementary or physical mode: set all entities in the model invisible
      for(std::size_t i = 0; i < GModel::list.size(); i++) {
        GModel *m = GModel::list[i];
        if(allmodels || m == GModel::current()) {
          std::vector<GEntity *> entities;
          m->getEntities(entities);
          for(std::size_t j = 0; j < entities.size(); j++)
            entities[j]->setVisibility(0);
        }
      }
    }
    if(type == MeshPartitions) {
      // hide everything belonging to a partition in one pass, rather than
      // once per partition; entities in no partition are left alone
      for(std::size_t i = 0; i < GModel::list.size(); i++) {
        GModel *m = GModel::list[i];
        if(!allmodels && m != GModel::current()) continue;
        if(m == _partitionIndexModel) {
          for(auto &p : _partitionIndex)
            for(std::size_t j = 0; j < p.second.size(); j++)
              p.second[j]->setVisibility(0);
        }
        else {
          std::vector<GEntity *> entities;
          m->getEntities(entities);
          std::vector<int> tmp;
          for(std::size_t j = 0; j < entities.size(); j++)
            if(partitionsOf(entities[j], tmp)) entities[j]->setVisibility(0);
        }
      }
      for(int i = 0; i < getNumEntities(); i++)
        static_cast<VisPartition *>(_entities[i])->setListVisibility(0);
    }
    else {
      // this is superfluous in elementary mode, but we don't care
      for(int i = 0; i < getNumEntities(); i++) setVisibility(i, 0);
    }
  }
  // get the dim of the nth entity in the list
  int getDim(int n) { return _entities[n]->getDim(); }
  // get the tag of the nth entity in the list
  int getTag(int n) { return _entities[n]->getTag(); }
  // get the browser line for the nth entity in the list
  std::string getBrowserLine(int n) { return _entities[n]->getBrowserLine(); }
  // set the sort mode
  void setSortMode(int mode) { _sortMode = (_sortMode != mode) ? mode : -mode; }
  // get the sort mode
  int getSortMode() { return _sortMode; }
};

VisibilityList *VisibilityList::_instance = nullptr;

// The list and the tree hold pointers to the entities and the models they
// were built from, deleted with them (by the API, a script merged, a
// synchronization): what they are used for first checks that none was created
// or deleted since, else rebuilds them, the selection made in them being then
// out of date. The rebuild is deferred: the checks run inside the event
// handling of the browser and the tree, which still use their lines and items
// once the callback returns
static int _listStamp = -1, _treeStamp = -1;

static void _rebuild_cb(void *)
{
  if(FlGui::available()) visibility_cb(nullptr, nullptr);
}

static bool _changed(int stamp)
{
  if(stamp == CTX::instance()->entitiesStamp) return false;
  if(!Fl::has_timeout(_rebuild_cb)) {
    Msg::Info("The model changed: the visibility lists are rebuilt");
    Fl::add_timeout(0., _rebuild_cb);
  }
  return true;
}

static bool _listChanged() { return _changed(_listStamp); }

static bool _treeChanged() { return _changed(_treeStamp); }

static void _rebuild_list_browser()
{
  FlGui::instance()->visibility->browser->clear();

  VisibilityList::VisibilityType type;
  switch(FlGui::instance()->visibility->browser_type->value()) {
  case 0: type = VisibilityList::Models; break;
  case 2: type = VisibilityList::PhysicalEntities; break;
  case 3: type = VisibilityList::MeshPartitions; break;
  case 1:
  default: type = VisibilityList::ElementaryEntities; break;
  }

  FlGui::instance()->visibility->filter.set(
    FlGui::instance()->visibility->search);
  VisibilityList::instance()->update(type,
                                     FlGui::instance()->visibility->filter);
  _listStamp = CTX::instance()->entitiesStamp;

  for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++) {
    FlGui::instance()->visibility->browser->add(
      VisibilityList::instance()->getBrowserLine(i).c_str());
    if(VisibilityList::instance()->getVisibility(i))
      FlGui::instance()->visibility->browser->select(i + 1);
  }
}

// what the boxes under the lists ask for: the visibility set recursively (the
// boundaries of an entity too), and in all the models
static bool recursiveVisibility()
{ return FlGui::instance()->visibility->butt[0]->value() != 0; }
static bool allModelsVisibility()
{ return FlGui::instance()->visibility->butt[1]->value() != 0; }

static void visibility_browser_apply_cb(Fl_Widget *w, void *data)
{
  if(_listChanged()) return;
  // if the browser is not empty, get the selections made in the
  // browser and apply them into the model
  if(VisibilityList::instance()->getNumEntities()) {
    CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    bool recursive = recursiveVisibility();
    bool allmodels = allModelsVisibility();
    VisibilityList::VisibilityType type;
    switch(FlGui::instance()->visibility->browser_type->value()) {
    case 0: type = VisibilityList::Models; break;
    case 2: type = VisibilityList::PhysicalEntities; break;
    case 3: type = VisibilityList::MeshPartitions; break;
    case 1:
    default: type = VisibilityList::ElementaryEntities; break;
    }
    VisibilityList::instance()->setAllInvisible(type, allmodels);
    for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++)
      if(FlGui::instance()->visibility->browser->selected(i + 1))
        VisibilityList::instance()->setVisibility(i, 1, recursive, allmodels);
    FlGui::instance()->visibility->browser->deselect();
    for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++)
      if(VisibilityList::instance()->getVisibility(i))
        FlGui::instance()->visibility->browser->select(i + 1, 1);
    drawContext::global()->draw();
  }
}

// "*" selects or deselects all the rows, "-" inverts the selection, and
// "type", "number" or "name" sorts the rows (in reverse order the second time)
static void visibility_sort_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  Fl_Browser *b = FlGui::instance()->visibility->browser;
  if(str == "*") {
    bool all = true;
    for(int i = 1; i <= b->size(); i++)
      if(!b->selected(i)) all = false;
    if(all)
      b->deselect();
    else
      for(int i = 1; i <= b->size(); i++) b->select(i);
  }
  else if(str == "-") {
    for(int i = 1; i <= b->size(); i++) b->select(i, !b->selected(i));
  }
  else {
    VisibilityList::instance()->setSortMode(str == "type"   ? 1 :
                                            str == "number" ? 2 :
                                                              3);
    visibility_cb(nullptr, (void *)"list_only");
  }
}

class listBrowser : public Fl_Browser {
  int handle(int event)
  {
    void *l = selection();

    switch(event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
      if(Fl::test_shortcut(FL_CTRL + 'a')) {
        for(int i = 0; i < size(); i++) select(i + 1);
        return 1;
      }
      else if(Fl::test_shortcut(FL_Enter) || Fl::test_shortcut(FL_KP_Enter)) {
        visibility_browser_apply_cb(nullptr, nullptr);
        if(l) Fl_Browser_::select(l);
        return 1;
      }
      else if(Fl::test_shortcut(FL_Up)) {
        if(l && (l = item_prev(l))) {
          select_only(l, 1);
          visibility_browser_apply_cb(nullptr, nullptr);
          Fl_Browser_::select(l);
          return 1;
        }
      }
      else if(Fl::test_shortcut(FL_Down)) {
        if(l && (l = item_next(l))) {
          select_only(l, 1);
          visibility_browser_apply_cb(nullptr, nullptr);
          Fl_Browser_::select(l);
          return 1;
        }
      }
    }
    return Fl_Browser::handle(event);
  }

public:
  listBrowser(int x, int y, int w, int h, const char *c = nullptr)
    : Fl_Browser(x, y, w, h, c)
  {
  }
};

// an entity in the tree, under path, with its boundary below it: the ends of
// a curve, the curves of a surface, the surfaces of a volume
static void _add_entity(GEntity *ge, Fl_Tree *tree, const std::string &path)
{
  int dim = ge->dim();
  std::ostringstream entity;
  entity << path << selectionDriver::entityKinds[dim].name << " " << ge->tag();
  std::string name = ge->model()->getElementaryName(dim, ge->tag());
  if(!name.empty()) entity << " - " << ReplaceSubString("/", "|", name);
  entity << "/";
  Fl_Tree_Item *n = tree->add(entity.str().c_str());
  if(!n) return;
  if(ge->getVisibility()) n->select(1);
  n->user_data((void *)ge);
  n->close();
  std::vector<GEntity *> boundary;
  if(dim == 1) {
    GEdge *e = (GEdge *)ge;
    if(e->getBeginVertex()) boundary.push_back(e->getBeginVertex());
    if(e->getEndVertex()) boundary.push_back(e->getEndVertex());
  }
  else if(dim == 2)
    for(GEdge *e : ((GFace *)ge)->edges()) boundary.push_back(e);
  else if(dim == 3)
    for(GFace *f : ((GRegion *)ge)->faces()) boundary.push_back(f);
  for(GEntity *b : boundary) _add_entity(b, tree, entity.str());
}

static void _add_physical_group(int dim, int num, std::vector<GEntity *> &ge,
                                std::map<int, std::string> &oldLabels,
                                Fl_Tree *tree, const std::string &path)
{
  if(ge.empty() || dim < 0 || dim > 3) return;
  std::string name = ge[0]->model()->getPhysicalName(dim, num);
  if(name.empty()) name = oldLabels[num];
  if(name.size()) name = std::string(" - ") + name;
  std::ostringstream group;
  group << path << "Physical " << selectionDriver::entityKinds[dim].name << " "
        << num << name << "/";
  Fl_Tree_Item *n = tree->add(group.str().c_str());
  if(n) n->close();
  for(std::size_t i = 0; i < ge.size(); i++)
    _add_entity(ge[i], tree, group.str());
}

static void _rebuild_tree_browser(bool force)
{
  if(!force) {
    int numEnt = 0;
    for(std::size_t i = 0; i < GModel::list.size(); i++) {
      numEnt +=
        GModel::list[i]->getNumRegions() + GModel::list[i]->getNumFaces() +
        GModel::list[i]->getNumEdges() + GModel::list[i]->getNumVertices();
    }
    if(numEnt > 10000) {
      FlGui::instance()->visibility->tree->hide();
      FlGui::instance()->visibility->tree_create->show();
      return;
    }
  }

  FlGui::instance()->visibility->tree_create->hide();
  FlGui::instance()->visibility->tree->show();
  FlGui::instance()->visibility->tree->clear();
  _treeStamp = CTX::instance()->entitiesStamp;

  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    std::ostringstream model;
    model << "Model " << i;
    if(m->getName().size()) model << " - " << m->getName();
    if(m == GModel::current()) model << " (Current Model)";
    model << "/";

    Fl_Tree_Item *n;
    n = FlGui::instance()->visibility->tree->add(model.str().c_str());
    if(n) {
      if(m->getVisibility()) n->select(1);
      n->close();
    }

    std::string elementary = model.str() + "Elementary entities/";
    n = FlGui::instance()->visibility->tree->add(elementary.c_str());
    if(n) n->close();
    // the volumes first, then the surfaces, the curves and the points
    for(int dim = 3; dim >= 0; dim--) {
      std::vector<GEntity *> entities;
      m->getEntities(entities, dim);
      for(GEntity *ge : entities)
        _add_entity(ge, FlGui::instance()->visibility->tree, elementary);
    }

    std::string physical = model.str() + "Physical groups/";
    n = FlGui::instance()->visibility->tree->add(physical.c_str());
    if(n) n->close();

    std::map<int, std::vector<GEntity *> > groups[4];
    m->getPhysicalGroups(groups);
    std::map<int, std::string> oldLabels;
#if defined(HAVE_PARSER)
    for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); ++it)
      if(it->first.size())
        for(std::size_t i = 0; i < it->second.value.size(); i++)
          oldLabels[(int)it->second.value[i]] =
            std::string("(") + it->first + ")";
#endif
    for(int i = 3; i >= 0; i--)
      for(auto it = groups[i].begin(); it != groups[i].end(); it++)
        _add_physical_group(i, it->first, it->second, oldLabels,
                            FlGui::instance()->visibility->tree, physical);
  }

  FlGui::instance()->visibility->tree->root_label("Gmsh");
  FlGui::instance()->visibility->tree->redraw();
}

static void build_tree_cb(Fl_Widget *w, void *data)
{
  _rebuild_tree_browser(true);
}

static void _recur_select(Fl_Tree_Item *n)
{
  n->select(1);
  for(int i = 0; i < n->children(); i++) _recur_select(n->child(i));
}

// the selected entities of the tree under n shown (with what they are bounded
// by if "recursively" is checked): every row is visited, whatever the option,
// as the rows of the model and of the groups hold no entity
static void _recur_set_visible(Fl_Tree_Item *n)
{
  if(n->user_data() && n->is_selected()) {
    GEntity *ge = (GEntity *)n->user_data();
    ge->setVisibility(1, recursiveVisibility());
    // force this: if we ask to see an entity, let's assume that we
    // don't want the whole model to be invisible
    ge->model()->setVisibility(1);
  }
  for(int i = 0; i < n->children(); i++) _recur_set_visible(n->child(i));
}

static void _recur_update_selected(Fl_Tree_Item *n)
{
  if(n->user_data()) {
    GEntity *ge = (GEntity *)n->user_data();
    n->select(ge->getVisibility() ? 1 : 0);
  }
  for(int i = 0; i < n->children(); i++) _recur_update_selected(n->child(i));
}

static void visibility_tree_apply_cb(Fl_Widget *w, void *data)
{
  if(_treeChanged()) return;
  CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
  bool recursive = recursiveVisibility();

  Fl_Tree_Item *root = FlGui::instance()->visibility->tree->root();
  for(int i = 0; i < root->children(); i++) {
    GModel *m = GModel::list[i];
    Fl_Tree_Item *n = root->child(i);
    // treat special levels separately
    if(recursive) {
      if(root->is_selected() ||
         n->is_selected()) { // if root or model is selected
        _recur_select(n);
      }
      else {
        for(int j = 0; j < n->children(); j++) {
          if(n->child(j)->is_selected()) // if elementary/physical is selected
            _recur_select(n->child(j));
          else if(j == 1) {
            for(int k = 0; k < n->child(j)->children(); k++) {
              if(n->child(j)
                   ->child(k)
                   ->is_selected()) // if physical ent is selected
                _recur_select(n->child(j)->child(k));
            }
          }
        }
      }
    }
    // set all entities as invisible
    std::vector<GEntity *> entities;
    m->getEntities(entities);
    for(std::size_t j = 0; j < entities.size(); j++)
      entities[j]->setVisibility(0);
    // set visibility flag according to tree selection
    _recur_set_visible(n);
    // update tree selection
    _recur_update_selected(n);
  }
  FlGui::instance()->visibility->tree->redraw();
  drawContext::global()->draw();
}

class treeBrowser : public Fl_Tree {
  int handle(int event)
  {
    switch(event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
      if(Fl::test_shortcut(FL_Enter) || Fl::test_shortcut(FL_KP_Enter)) {
        visibility_tree_apply_cb(nullptr, nullptr);
        return 1;
      }
    }
    return Fl_Tree::handle(event);
  }

public:
  treeBrowser(int x, int y, int w, int h, const char *c = nullptr)
    : Fl_Tree(x, y, w, h, c)
  {
  }
};

void visibility_cb(Fl_Widget *w, void *data)
{
  // get the visibility info from the model, and update the browser accordingly
  std::string tmp;
  if(data) tmp = (const char *)data;
  if(tmp.find("redraw_only") != std::string::npos)
    FlGui::instance()->visibility->show(true);
  else
    FlGui::instance()->visibility->show(false);

  _rebuild_list_browser();

  if(tmp.find("list_only") == std::string::npos) _rebuild_tree_browser(false);

  FlGui::instance()->visibility->updatePerWindow();
}

void visibility_save(const std::string &fileName)
{
  // get the whole visibility information in geo format
  std::vector<int> state[4][2];
  for(int dim = 0; dim < 4; dim++) {
    std::vector<GEntity *> entities;
    GModel::current()->getEntities(entities, dim);
    for(GEntity *ge : entities)
      state[dim][ge->getVisibility() ? 1 : 0].push_back(ge->tag());
  }
  std::vector<std::pair<int, int> > entities;
  int mode = 0, on = 0, off = 0;
  for(int i = 0; i < 4; i++) {
    on += state[i][1].size();
    off += state[i][0].size();
  }
  if(on > off) {
    scriptSetVisibilityAll(1, fileName);
    if(!off) return;
    mode = 0;
  }
  else {
    scriptSetVisibilityAll(0, fileName);
    if(!on) return;
    mode = 1;
  }
  for(int i = 0; i < 4; i++) {
    if(state[i][mode].size()) {
      for(std::size_t j = 0; j < state[i][mode].size(); j++) {
        entities.push_back(std::make_pair(i, state[i][mode][j]));
      }
    }
  }
  scriptSetVisibility(mode, entities, fileName);
}

static void visibility_save_cb(Fl_Widget *w, void *data)
{
  Msg::StatusBar(true, "Appending visibility info to '%s'...",
                 GModel::current()->getFileName().c_str());
  visibility_save(GModel::current()->getFileName());
  Msg::StatusBar(true, "Done appending visibility info");
}

// The rows of the Numeric and Interactive tabs: the nodes and the elements,
// then the elementary entities and the physical groups of each dimension
// (ROW_ENTITIES + dim, ROW_PHYSICALS + dim)
enum { ROW_NODES = 0, ROW_ELEMENTS = 1, ROW_ENTITIES = 2, ROW_PHYSICALS = 6,
       NUM_ROWS = 10 };

// the section of the tabs a row is in
static const char *_rowSection(int row)
{
  return row < ROW_ENTITIES ? "Mesh" :
         row < ROW_PHYSICALS ? "Elementary entities" :
                               "Physical groups";
}

// the name of what a row shows or hides: "Node", "Element", "Point"...
static const char *_rowName(int row)
{
  if(row == ROW_NODES) return "Node";
  if(row == ROW_ELEMENTS) return "Element";
  return selectionDriver::entityKinds[(row - ROW_ENTITIES) % 4].name;
}

// the nodes, elements, entities or physical groups of a row with number num
// (all for num < 0) shown or hidden
static void _set_visibility_by_number(int row, int num, char val,
                                      bool recursive, bool allmodels)
{
  bool all = (num < 0) ? true : false;

  for(std::size_t mod = 0; mod < GModel::list.size(); mod++) {
    GModel *m = GModel::list[mod];
    if(!allmodels && m != GModel::current()) continue;
    std::vector<GEntity *> entities;
    m->getEntities(entities);
    if(row == ROW_NODES) {
      for(std::size_t i = 0; i < entities.size(); i++) {
        for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
          MVertex *v = entities[i]->mesh_vertices[j];
          if(all || (int)v->getNum() == num) v->setVisibility(val);
        }
      }
    }
    else if(row == ROW_ELEMENTS) {
      for(std::size_t i = 0; i < entities.size(); i++) {
        for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
          MElement *e = entities[i]->getMeshElement(j);
          if(all || (int)e->getNum() == num) e->setVisibility(val);
        }
      }
    }
    else if(row < NUM_ROWS) {
      bool physical = (row >= ROW_PHYSICALS);
      std::vector<GEntity *> dimEntities;
      m->getEntities(dimEntities, (row - ROW_ENTITIES) % 4);
      for(GEntity *ge : dimEntities) {
        if(!physical) {
          if(all || ge->tag() == num) ge->setVisibility(val, recursive);
          continue;
        }
        for(std::size_t i = 0; i < ge->physicals.size(); i++)
          if(all || std::abs(ge->physicals[i]) == num)
            ge->setVisibility(val, recursive);
      }
    }
  }
}

// what is done to the elements, entities or physical groups picked in the
// Interactive tab: hidden, shown alone, or shown again (the undo of a hide)
enum pickAction { PickHide, PickShow, PickUndo };

static void
_apply_visibility(pickAction action, bool physical, bool pickElements,
                  std::vector<GVertex *> &vertices, std::vector<GEdge *> &edges,
                  std::vector<GFace *> &faces, std::vector<GRegion *> &regions,
                  std::vector<MElement *> &elements)
{
  bool recursive = recursiveVisibility();
  bool allmodels = allModelsVisibility();

  if(action ==
     PickShow) { // when showing a single entity, first hide everything
    if(pickElements)
      _set_visibility_by_number(ROW_ELEMENTS, -1, 0, false, allmodels);
    else
      for(int dim = 0; dim < 4; dim++)
        _set_visibility_by_number(ROW_ENTITIES + dim, -1, 0, false, allmodels);
  }

  char mode = (action == PickHide) ? 0 : 1;

  if(pickElements) {
    for(std::size_t i = 0; i < elements.size(); i++)
      elements[i]->setVisibility(mode);
  }
  else {
    // a picked entity, or the physical groups it belongs to
    auto apply = [&](GEntity *ge) {
      if(!physical) {
        ge->setVisibility(mode, recursive);
        return;
      }
      for(std::size_t j = 0; j < ge->physicals.size(); j++)
        _set_visibility_by_number(ROW_PHYSICALS + ge->dim(),
                                  std::abs(ge->physicals[j]), mode, recursive,
                                  allmodels);
    };
    for(GVertex *v : vertices) apply(v);
    for(GEdge *e : edges) apply(e);
    for(GFace *f : faces) apply(f);
    for(GRegion *r : regions) apply(r);
  }
  int pos = FlGui::instance()->visibility->browser->position();
  visibility_cb(nullptr, (void *)"redraw_only");
  FlGui::instance()->visibility->browser->position(pos);
}

// the Show (val 1) or Hide (val 0) button of a row of the Numeric tab
static void _visibility_number(int row, char val)
{
  CTX::instance()->meshChanged(ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
  const char *str = FlGui::instance()->visibility->input[row]->value();
  int num = (!strcmp(str, "all") || !strcmp(str, "*")) ? -1 : atoi(str);
  bool recursive = recursiveVisibility();
  bool allmodels = allModelsVisibility();

  _set_visibility_by_number(row, num, val, recursive, allmodels);

  int pos = FlGui::instance()->visibility->browser->position();
  visibility_cb(nullptr, (void *)"redraw_only");
  FlGui::instance()->visibility->browser->position(pos);
  drawContext::global()->draw();
}

static void visibility_number_show_cb(Fl_Widget *w, void *data)
{
  _visibility_number((intptr_t)data, 1);
}

static void visibility_number_hide_cb(Fl_Widget *w, void *data)
{
  _visibility_number((intptr_t)data, 0);
}

// the elements, entities or physical groups of a row of the Interactive tab
// picked in the scene, until 'q', to be shown or hidden: a tool of the
// current window (see sceneTool)
static void _visibility_interactive(int row, bool show)
{
  bool physical = (row >= ROW_PHYSICALS);
  bool elements = (row == ROW_ELEMENTS);
  int dim = (row - ROW_ENTITIES) % 4, what;
  std::string str = physical ? "physical " : "";
  if(elements) {
    what = ENT_ALL;
    str += "elements";
  }
  else {
    what = selectionDriver::entityKinds[dim].type;
    str += selectionDriver::entityKinds[dim].names;
    // the surfaces and volumes are drawn by their mesh once they have one
    if(dim < 2 || GModel::current()->getMeshStatus() < dim)
      selectionDriver::show(what);
  }
  str += show ? " to show" : " to hide";
  std::string status = "Select " + str + "\n[Press " +
                       (show ? "" : "'u' to undo or ") + "Escape to abort]";

  // what was picked last, for an undo, and when (the model or its mesh may
  // change meanwhile, and what an undo would show again be gone)
  struct picked {
    std::vector<GVertex *> vertices;
    std::vector<GEdge *> edges;
    std::vector<GFace *> faces;
    std::vector<GRegion *> regions;
    std::vector<MElement *> elements;
    modelStamps stamps;
  };
  auto last = std::make_shared<picked>();

  // (the elements drawn one by one for their picking)
  if(elements) CTX::instance()->meshChanged();
  sceneTool::start(
    new functionTool(
      "Visibility", what, elements, [status](sceneView *) { return status; },
      [=](char ib, sceneView *, const scenePicks &p) {
        if(ib == 'q') return false;
        if(last->stamps.changed()) *last = picked();
        last->stamps.record();
        if(ib == 'l') {
          last->vertices = p.vertices;
          last->edges = p.edges;
          last->faces = p.faces;
          last->regions = p.regions;
          last->elements = p.elements;
          _apply_visibility(show ? PickShow : PickHide, physical, elements,
                            last->vertices, last->edges, last->faces,
                            last->regions, last->elements);
        }
        if(ib == 'u' && !show) // undo only in hide mode
          _apply_visibility(PickUndo, physical, elements, last->vertices,
                            last->edges, last->faces, last->regions,
                            last->elements);
        if(elements) CTX::instance()->meshChanged();
        return true;
      },
      []() {
        CTX::instance()->meshChanged();
        drawContext::global()->draw();
      }),
    FlGui::instance()->getCurrentOpenglWindow(),
    (Fl_Window *)FlGui::instance()->visibility->win);
}

static void visibility_pick_show_cb(Fl_Widget *w, void *data)
{ _visibility_interactive((intptr_t)data, true); }

static void visibility_pick_hide_cb(Fl_Widget *w, void *data)
{ _visibility_interactive((intptr_t)data, false); }

static void visibility_show_all_cb(Fl_Widget *w, void *data)
{
  bool allmodels = allModelsVisibility();
  _set_visibility_by_number(ROW_ELEMENTS, -1, 1, false, allmodels);
  for(int dim = 0; dim < 4; dim++)
    _set_visibility_by_number(ROW_ENTITIES + dim, -1, 1, false, allmodels);
  CTX::instance()->meshChanged();
  drawContext::global()->draw();
}

static void visibility_per_window_cb(Fl_Widget *w, void *data)
{
  std::string what = (const char *)data;
  if(what == "item") {
    drawContext *ctx =
      FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
    for(int i = 0; i < FlGui::instance()->visibility->per_window->size(); i++) {
      if(i < (int)GModel::list.size()) {
        GModel *m = GModel::list[i];
        if(FlGui::instance()->visibility->per_window->selected(i + 1))
          ctx->show(m);
        else
          ctx->hide(m);
      }
      else if(i < (int)(GModel::list.size() + PView::list.size())) {
        PView *v = PView::list[i - GModel::list.size()];
        if(FlGui::instance()->visibility->per_window->selected(i + 1))
          ctx->show(v);
        else
          ctx->hide(v);
      }
    }
  }
  else if(what == "reset_all") {
    for(openglWindow *gl : FlGui::instance()->openglWindows())
      gl->getDrawContext()->showAll();
    for(int i = 0; i < FlGui::instance()->visibility->per_window->size(); i++)
      FlGui::instance()->visibility->per_window->select(i + 1);
  }
  drawContext::global()->draw();
}

static void browser_cb(Fl_Widget *w, void *data)
{
  if(Fl::event_clicks()) {
    if(_listChanged()) return;
    int n = FlGui::instance()->visibility->browser->value() - 1;
    if(n >= 0 && n < VisibilityList::instance()->getNumEntities()) {
      int dim = VisibilityList::instance()->getDim(n);
      int tag = VisibilityList::instance()->getTag(n);
      if(FlGui::instance()->visibility->browser_type->value() == 1) {
        FlGui::instance()->onelabContext->show(dim, tag);
      }
      else if(FlGui::instance()->visibility->browser_type->value() == 2) {
        std::map<int, std::vector<GEntity *> > groups;
        GModel::current()->getPhysicalGroups(dim, groups);
        auto it = groups.find(tag);
        if(it != groups.end() && it->second.size())
          FlGui::instance()->onelabContext->show(dim, it->second[0]->tag());
      }
    }
  }
}

static void tree_cb(Fl_Widget *w, void *data)
{
  Fl_Tree *tree = (Fl_Tree *)w;
  if(tree->callback_reason() == FL_TREE_REASON_RESELECTED &&
     Fl::event_clicks()) {
    // double click
    if(_treeChanged()) return;
    Fl_Tree_Item *item = (Fl_Tree_Item *)tree->callback_item();
    GEntity *ge = nullptr;
    if(item) {
      if(item->user_data()) { ge = (GEntity *)item->user_data(); }
      else if(item->children() && item->child(0) &&
              item->child(0)->user_data()) {
        ge = (GEntity *)item->child(0)->user_data();
      }
    }
    if(ge) FlGui::instance()->onelabContext->show(ge->dim(), ge->tag());
  }
}

static void visibility_tab_cb(Fl_Widget *w, void *data)
{
  Fl_Tabs *t = (Fl_Tabs *)w;
  int i = t->find(t->value());
  ((paletteWindow *)t->window())->leastHeight(((int *)data)[i]);
}

visibilityWindow::visibilityWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int CC = BB;

  // as narrow as the option window; the last column takes what is left
  int width = TW;
  static int cols[5] = {3 * WB, CC, CC, 0, 0};
  cols[3] = width - 4 * WB - cols[0] - cols[1] - cols[2];
  int height = 18 * BH;
  int brw = width - 4 * WB;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Visibility",
                          CTX::instance()->visOffset);
  win->box(GMSH_WINDOW_BOX);

  Fl_Tabs *o = new accentTabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
  // the least height: three rows of the list, tree or windows, all of the
  // numeric and interactive tabs
  static int least[5];
  least[0] = least[1] = least[4] = 7 * BH + 6 * WB;
  least[2] = least[3] = 15 * BH + 5 * WB;
  o->callback(visibility_tab_cb, least);
  {
    Fl_Group *g = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "List");

    {
      Fl_Group *gg = new Fl_Group(2 * WB, WB + BH,
                                  cols[0] + cols[1] + cols[2] + cols[3], BH);

      Fl_Button *o0 = new Fl_Button(2 * WB, 2 * WB + BH, cols[0], BH / 2, "*");
      o0->box(FL_THIN_DOWN_BOX);
      o0->color(FL_BACKGROUND2_COLOR);
      o0->labelfont(FL_BOLD);
      o0->align(FL_ALIGN_TOP | FL_ALIGN_INSIDE);
      o0->tooltip("Select/unselect all");
      o0->callback(visibility_sort_cb, (void *)"*");

      Fl_Button *o1 =
        new Fl_Button(2 * WB, 2 * WB + BH + BH / 2, cols[0], BH - BH / 2, "-");
      o1->box(FL_THIN_DOWN_BOX);
      o1->color(FL_BACKGROUND2_COLOR);
      o1->labelfont(FL_BOLD);
      o1->tooltip("Invert selection");
      o1->callback(visibility_sort_cb, (void *)"-");

      Fl_Button *o2 =
        new Fl_Button(2 * WB + cols[0], 2 * WB + BH, cols[1], BH, "Type");
      o2->box(FL_THIN_DOWN_BOX);
      o2->color(FL_BACKGROUND2_COLOR);
      o2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      o2->tooltip("Sort by type");
      o2->callback(visibility_sort_cb, (void *)"type");

      Fl_Button *o3 = new Fl_Button(2 * WB + cols[0] + cols[1], 2 * WB + BH,
                                    cols[2], BH, "Number");
      o3->box(FL_THIN_DOWN_BOX);
      o3->color(FL_BACKGROUND2_COLOR);
      o3->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      o3->tooltip("Sort by number");
      o3->callback(visibility_sort_cb, (void *)"number");

      Fl_Button *o4 = new Fl_Button(2 * WB + cols[0] + cols[1] + cols[2],
                                    2 * WB + BH, cols[3], BH, "Name");
      o4->box(FL_THIN_DOWN_BOX);
      o4->color(FL_BACKGROUND2_COLOR);
      o4->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      o4->tooltip("Sort by name");
      o4->callback(visibility_sort_cb, (void *)"name");

      gg->resizable(o4);
      gg->end();
    }
    {
      Fl_Group *gg =
        new Fl_Group(2 * WB, 2 * WB + 2 * BH, brw, height - 6 * WB - 4 * BH);

      browser =
        new listBrowser(2 * WB, 2 * WB + 2 * BH, brw, height - 6 * WB - 4 * BH);
      browser->type(FL_MULTI_BROWSER);
      browser->textsize(FL_NORMAL_SIZE - 1);
      browser->column_widths(cols);
      browser->callback(browser_cb);

      gg->end();
      Fl_Group::current()->resizable(gg);
    }

    static Fl_Menu_Item browser_type_table[] = {
      {"Models", 0, (Fl_Callback *)visibility_cb, (void *)"list_only"},
      {"Elementary entities", 0, (Fl_Callback *)visibility_cb,
       (void *)"list_only"},
      {"Physical groups", 0, (Fl_Callback *)visibility_cb, (void *)"list_only"},
      {"Mesh partitions", 0, (Fl_Callback *)visibility_cb, (void *)"list_only"},
      {nullptr}};

    double w1 = 1.7 * CC;
    double w3 = CC;
    double w2 = (width - 6 * WB - w1 - w3);
    browser_type = new Fl_Choice(2 * WB, height - 2 * BH - 3 * WB, w1, BH);
    browser_type->menu(browser_type_table);

    search = searchBox(
      2 * WB + w1 + WB, height - 2 * BH - 3 * WB, w2, BH, "Filter list",
      "Show only the entries matching the regular expression,\n"
      "whatever the case",
      visibility_cb);
    search->user_data((void *)"list_only");

    Fl_Return_Button *b1 = new Fl_Return_Button(
      width - 2 * WB - w3, height - 2 * BH - 3 * WB, w3, BH, "Apply");
    b1->callback(visibility_browser_apply_cb);

    g->end();
    Fl_Group::current()->resizable(g);
  }
  {
    Fl_Group *g = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "Tree");

    tree = new treeBrowser(2 * WB, 2 * WB + BH, brw, height - 6 * WB - 3 * BH);
    tree->labelsize(FL_NORMAL_SIZE - 1);
    tree->selectmode(FL_TREE_SELECT_MULTI);
    tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
    tree->item_reselect_mode(FL_TREE_SELECTABLE_ALWAYS); // for double-clicks
    tree->callback(tree_cb);
    tree->hide();

    tree_create =
      new Fl_Button(2 * WB, 2 * WB + BH, brw, height - 6 * WB - 3 * BH,
                    "The model contains more than 10 thousand entities,\n"
                    "which might slow down the tree browser.\n\n"
                    "Create tree browser anyway?");
    tree_create->callback(build_tree_cb);

    Fl_Return_Button *b1 = new Fl_Return_Button(
      width - 1 * CC - 2 * WB, height - 2 * BH - 3 * WB, CC, BH, "Apply");
    b1->callback(visibility_tree_apply_cb);

    g->resizable(tree);
    g->end();
  }
  {
    Fl_Group *g = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "Numeric");
    g->resizable(nullptr);

    int yy = 2 * WB + BH;
    for(int row = 0; row < NUM_ROWS; row++) {
      if(!row || strcmp(_rowSection(row), _rowSection(row - 1))) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, _rowSection(row));
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      input[row] = new Fl_Input(width / 2 - WB / 2 - IW, yy, IW, BH);
      input[row]->align(FL_ALIGN_LEFT);
      input[row]->value("*");
      input[row]->label(_rowName(row));
      std::string name = _rowName(row);
      name[0] = tolower(name[0]);
      input[row]->copy_tooltip(("Enter " + name + " number, or *").c_str());

      Fl_Button *o1 = new Fl_Button(width / 2 + WB / 2, yy, CC, BH, "Show");
      o1->callback(visibility_number_show_cb, (void *)(intptr_t)row);

      Fl_Button *o2 =
        new Fl_Button(width / 2 + WB / 2 + CC + WB, yy, CC, BH, "Hide");
      o2->callback(visibility_number_hide_cb, (void *)(intptr_t)row);
      yy += BH;
    }

    g->end();
  }
  {
    Fl_Group *g = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "Interactive");
    g->resizable(nullptr);

    int ll = width / 2 - BH - WB - IW;
    int ll2 = ll + IW + WB + 2 * BH + WB;
    int yy = 2 * WB + BH;
    // the rows of the Numeric tab but the nodes, picked in the scene
    for(int row = ROW_ELEMENTS; row < NUM_ROWS; row++) {
      if(row == ROW_ELEMENTS ||
         strcmp(_rowSection(row), _rowSection(row - 1))) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, _rowSection(row));
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      std::string names =
        row == ROW_ELEMENTS ?
          "elements" :
          selectionDriver::entityKinds[(row - ROW_ENTITIES) % 4].names;
      Fl_Button *hide = new Fl_Button(ll, yy, IW, BH);
      hide->copy_label(("Hide " + names).c_str());
      hide->callback(visibility_pick_hide_cb, (void *)(intptr_t)row);
      Fl_Button *show = new Fl_Button(ll2, yy, IW, BH);
      show->copy_label(("Show " + names).c_str());
      show->callback(visibility_pick_show_cb, (void *)(intptr_t)row);
      yy += BH;
    }

    Fl_Button *all = new Fl_Button(ll + IW + WB, 2 * WB + 2 * BH, 2 * BH,
                                   11 * BH, "Show\nAll");
    all->callback(visibility_show_all_cb);

    g->end();
  }
  {
    Fl_Group *g = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "Per window");

    per_window =
      new Fl_Multi_Browser(2 * WB, 2 * WB + BH, brw, height - 6 * WB - 3 * BH);
    per_window->callback(visibility_per_window_cb, (void *)"item");

    Fl_Button *b1 = new Fl_Button(
      width - 1 * CC - 2 * WB, height - 2 * BH - 3 * WB, CC, BH, "Reset all");
    b1->callback(visibility_per_window_cb, (void *)"reset_all");

    g->resizable(per_window);
    g->end();
  }
  o->end();

  win->resizable(o);
  ((paletteWindow *)win)->sizeRange(width, least[0]);

  {
    int aw = (int)(3.5 * FL_NORMAL_SIZE);

    Fl_Group *g = new Fl_Group(WB, height - BH - WB, width - 2 * WB - CC, BH);
    g->resizable(nullptr);

    Fl_Box *b = new Fl_Box(WB, height - BH - WB, aw, BH, "Apply");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    butt[0] = new Fl_Check_Button(WB + aw + WB, height - BH - WB, 2 * aw, BH,
                                  "recursively");
    butt[0]->value(1);

    butt[1] = new Fl_Check_Button(WB + 3 * aw + 2 * WB, height - BH - WB,
                                  3 * aw, BH, "to all models");
    butt[1]->value(1);

    g->end();

    Fl_Button *o1 =
      new Fl_Button(width - CC - WB, height - BH - WB, CC, BH, "Save");
    o1->callback(visibility_save_cb);
  }

  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void visibilityWindow::show(bool redrawOnly)
{
  static bool first = true;
  if(win->shown() && redrawOnly)
    win->redraw();
  else {
    if(first) {
      browser_type->value(GModel::current()->noPhysicalGroups() ? 1 : 2);
      first = false;
    }
    win->show();
  }
}

void visibilityWindow::updatePerWindow()
{
  openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
  drawContext *ctx = gl->getDrawContext();

  per_window->clear();
  int line = 1;

  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    std::ostringstream sstream;
    sstream << "Model " << i;
    if(m->getName().size()) sstream << " - " << m->getName();
    per_window->add(sstream.str().c_str());
    if(ctx->isVisible(m)) per_window->select(line, 1);
    line++;
  }

  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PView *v = PView::list[i];
    std::ostringstream sstream;
    sstream << "View [" << i << "]";
    if(v->getData()->getName().size())
      sstream << " - " << v->getData()->getName();
    per_window->add(sstream.str().c_str());
    if(ctx->isVisible(v)) per_window->select(line, 1);
    line++;
  }
}
