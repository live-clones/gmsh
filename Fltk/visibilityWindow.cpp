// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <string>
#include <regex>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "drawContext.h"
#include "visibilityWindow.h"
#include "paletteWindow.h"
#include "contextWindow.h"
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
#include "Options.h"
#include "Context.h"
#include "StringUtils.h"
#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "partitionRegion.h"

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
  bool match(const std::string &pattern)
  {
    if(pattern.empty()) return true;
    std::string line(getBrowserLine(false));
    try {
      // icase for case-insensitive search
      if(std::regex_search(line,
                           std::regex(pattern, std::regex_constants::icase)))
        return true;
    } catch(...) {
      return false;
    }
    return false;
  }
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

class VisPhysical : public Vis {
private:
  int _tag, _dim;
  char _visible;
  std::vector<GEntity *> _list;

public:
  VisPhysical(int tag, int dim, const std::vector<GEntity *> &list,
              std::string &name)
    : Vis(name), _tag(tag), _dim(dim), _visible(1), _list(list)
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

class VisPartition : public Vis {
private:
  int _tag;
  char _visible;

public:
  VisPartition(int tag) : _tag(tag), _visible(1) {}
  ~VisPartition() {}
  int getTag() const { return _tag; }
  std::string getType() const { return "Partition"; }
  char getVisibility() const { return _visible; }
  void setVisibility(char val, bool recursive = false, bool allmodels = false)
  {
    _visible = val;
    for(std::size_t i = 0; i < GModel::list.size(); i++) {
      GModel *m = GModel::list[i];
      if(allmodels || m == GModel::current()) {
        std::vector<GEntity *> entities;
        m->getEntities(entities);
        for(std::size_t j = 0; j < entities.size(); j++) {
          std::vector<int> ps;
          if(entities[j]->geomType() == GEntity::PartitionPoint)
            ps = static_cast<partitionVertex *>(entities[j])->getPartitions();
          else if(entities[j]->geomType() == GEntity::PartitionCurve)
            ps = static_cast<partitionEdge *>(entities[j])->getPartitions();
          else if(entities[j]->geomType() == GEntity::PartitionSurface)
            ps = static_cast<partitionFace *>(entities[j])->getPartitions();
          else if(entities[j]->geomType() == GEntity::PartitionVolume)
            ps = static_cast<partitionRegion *>(entities[j])->getPartitions();
          for(auto p : ps) {
            if(p == _tag) entities[j]->setVisibility(val, recursive);
          }
        }
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
  void update(VisibilityType type, const std::string &search)
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
    // this is superfluous in elementary mode, but we don't care
    for(int i = 0; i < getNumEntities(); i++) setVisibility(i, 0);
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

  std::string search = FlGui::instance()->visibility->search->value();
  VisibilityList::instance()->update(type, search);

  for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++) {
    FlGui::instance()->visibility->browser->add(
      VisibilityList::instance()->getBrowserLine(i).c_str());
    if(VisibilityList::instance()->getVisibility(i))
      FlGui::instance()->visibility->browser->select(i + 1);
  }
}

static void visibility_browser_apply_cb(Fl_Widget *w, void *data)
{
  // if the browser is not empty, get the selections made in the
  // browser and apply them into the model
  if(VisibilityList::instance()->getNumEntities()) {
    CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    bool recursive =
      FlGui::instance()->visibility->butt[0]->value() ? true : false;
    bool allmodels =
      FlGui::instance()->visibility->butt[1]->value() ? true : false;
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

static void visibility_sort_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char *)data;
  int val;
  if(!strcmp(str, "type"))
    val = 1;
  else if(!strcmp(str, "number"))
    val = 2;
  else if(!strcmp(str, "name"))
    val = 3;
  else if(!strcmp(str, "-"))
    val = -1;
  else if(!strcmp(str, "+"))
    val = -2;
  else
    val = 0;

  if(val == 0) { // select or deselect everything
    int selectall = 0;
    for(int i = 0; i < FlGui::instance()->visibility->browser->size(); i++)
      if(!FlGui::instance()->visibility->browser->selected(i + 1)) {
        selectall = 1;
        break;
      }
    if(selectall)
      for(int i = 0; i < FlGui::instance()->visibility->browser->size(); i++)
        FlGui::instance()->visibility->browser->select(i + 1);
    else
      FlGui::instance()->visibility->browser->deselect();
  }
  else if(val == -1) { // invert the selection
    int *state = new int[FlGui::instance()->visibility->browser->size()];
    for(int i = 0; i < FlGui::instance()->visibility->browser->size(); i++)
      state[i] = FlGui::instance()->visibility->browser->selected(i + 1);
    FlGui::instance()->visibility->browser->deselect();
    for(int i = 0; i < FlGui::instance()->visibility->browser->size(); i++)
      if(!state[i]) FlGui::instance()->visibility->browser->select(i + 1);
    delete[] state;
  }
  else { // set new sorting mode
    VisibilityList::instance()->setSortMode(val);
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

static void _add_vertex(GVertex *gv, Fl_Tree *tree, const std::string &path)
{
  std::ostringstream vertex;
  vertex << path << "Point " << gv->tag();
  std::string name = gv->model()->getElementaryName(0, gv->tag());
  if(!name.empty()) vertex << " - " << ReplaceSubString("/", "|", name);
  vertex << "/";
  Fl_Tree_Item *n = tree->add(vertex.str().c_str());
  if(!n) return;
  if(gv->getVisibility()) n->select(1);
  n->user_data((void *)gv);
  n->close();
}

static void _add_edge(GEdge *ge, Fl_Tree *tree, const std::string &path)
{
  std::ostringstream edge;
  edge << path << "Curve " << ge->tag();
  std::string name = ge->model()->getElementaryName(1, ge->tag());
  if(!name.empty()) edge << " - " << ReplaceSubString("/", "|", name);
  edge << "/";
  Fl_Tree_Item *n = tree->add(edge.str().c_str());
  if(!n) return;
  if(ge->getVisibility()) n->select(1);
  n->user_data((void *)ge);
  n->close();
  if(ge->getBeginVertex()) _add_vertex(ge->getBeginVertex(), tree, edge.str());
  if(ge->getEndVertex()) _add_vertex(ge->getEndVertex(), tree, edge.str());
}

static void _add_face(GFace *gf, Fl_Tree *tree, const std::string &path)
{
  std::ostringstream face;
  face << path << "Surface " << gf->tag();
  std::string name = gf->model()->getElementaryName(2, gf->tag());
  if(!name.empty()) face << " - " << ReplaceSubString("/", "|", name);
  face << "/";
  Fl_Tree_Item *n = tree->add(face.str().c_str());
  if(!n) return;
  if(gf->getVisibility()) n->select(1);
  n->user_data((void *)gf);
  n->close();
  std::vector<GEdge *> const &edges = gf->edges();
  for(auto it = edges.begin(); it != edges.end(); it++)
    _add_edge(*it, tree, face.str());
}

static void _add_region(GRegion *gr, Fl_Tree *tree, const std::string &path)
{
  std::ostringstream region;
  region << path << "Volume " << gr->tag();
  std::string name = gr->model()->getElementaryName(3, gr->tag());
  if(!name.empty()) region << " - " << ReplaceSubString("/", "|", name);
  region << "/";
  Fl_Tree_Item *n = tree->add(region.str().c_str());
  if(!n) return;
  if(gr->getVisibility()) n->select(1);
  n->user_data((void *)gr);
  n->close();
  std::vector<GFace *> faces = gr->faces();
  for(auto it = faces.begin(); it != faces.end(); it++)
    _add_face(*it, tree, region.str());
}

static void _add_physical_group(int dim, int num, std::vector<GEntity *> &ge,
                                std::map<int, std::string> &oldLabels,
                                Fl_Tree *tree, const std::string &path)
{
  if(ge.empty()) return;
  std::string name = ge[0]->model()->getPhysicalName(dim, num);
  if(name.empty()) name = oldLabels[num];
  if(name.size()) name = std::string(" - ") + name;

  Fl_Tree_Item *n;
  std::ostringstream group;
  group << path;
  switch(dim) {
  case 3:
    group << "Physical Volume " << num << name << "/";
    n = tree->add(group.str().c_str());
    if(n) n->close();
    for(std::size_t i = 0; i < ge.size(); i++)
      _add_region((GRegion *)ge[i], tree, group.str());
    break;
  case 2:
    group << "Physical Surface " << num << name << "/";
    n = tree->add(group.str().c_str());
    if(n) n->close();
    for(std::size_t i = 0; i < ge.size(); i++)
      _add_face((GFace *)ge[i], tree, group.str());
    break;
  case 1:
    group << "Physical Curve " << num << name << "/";
    n = tree->add(group.str().c_str());
    if(n) n->close();
    for(std::size_t i = 0; i < ge.size(); i++)
      _add_edge((GEdge *)ge[i], tree, group.str());
    break;
  case 0:
    group << "Physical Point " << num << name << "/";
    n = tree->add(group.str().c_str());
    if(n) n->close();
    for(std::size_t i = 0; i < ge.size(); i++)
      _add_vertex((GVertex *)ge[i], tree, group.str());
    break;
  default: break;
  }
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
    if(numEnt > 50000) {
      FlGui::instance()->visibility->tree->hide();
      FlGui::instance()->visibility->tree_create->show();
      return;
    }
  }

  FlGui::instance()->visibility->tree_create->hide();
  FlGui::instance()->visibility->tree->show();
  FlGui::instance()->visibility->tree->clear();

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
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
      _add_region(*it, FlGui::instance()->visibility->tree, elementary);
    for(auto it = m->firstFace(); it != m->lastFace(); it++)
      _add_face(*it, FlGui::instance()->visibility->tree, elementary);
    for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
      _add_edge(*it, FlGui::instance()->visibility->tree, elementary);
    for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
      _add_vertex(*it, FlGui::instance()->visibility->tree, elementary);

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

static void _recur_set_visible(Fl_Tree_Item *n)
{
  if(n->user_data() && n->is_selected()) {
    GEntity *ge = (GEntity *)n->user_data();
    bool recursive =
      FlGui::instance()->visibility->butt[0]->value() ? true : false;
    ge->setVisibility(1, recursive);
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
  CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
  bool recursive =
    FlGui::instance()->visibility->butt[0]->value() ? true : false;

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

  FlGui::instance()->visibility->updatePerWindow(true);
}

static void visibility_save_cb(Fl_Widget *w, void *data)
{
  Msg::StatusBar(true, "Appending visibility info to '%s'...",
                 GModel::current()->getFileName().c_str());
  // get the whole visibility information in geo format
  std::vector<int> state[4][2];
  GModel *m = GModel::current();
  for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
    (*it)->getVisibility() ? state[0][1].push_back((*it)->tag()) :
                             state[0][0].push_back((*it)->tag());
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
    (*it)->getVisibility() ? state[1][1].push_back((*it)->tag()) :
                             state[1][0].push_back((*it)->tag());
  for(auto it = m->firstFace(); it != m->lastFace(); it++)
    (*it)->getVisibility() ? state[2][1].push_back((*it)->tag()) :
                             state[2][0].push_back((*it)->tag());
  for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
    (*it)->getVisibility() ? state[3][1].push_back((*it)->tag()) :
                             state[3][0].push_back((*it)->tag());
  std::vector<std::pair<int, int> > entities;
  int mode = 0, on = 0, off = 0;
  for(int i = 0; i < 4; i++) {
    on += state[i][1].size();
    off += state[i][0].size();
  }
  if(on > off) {
    scriptSetVisibilityAll(1, GModel::current()->getFileName());
    if(!off) return;
    mode = 0;
  }
  else {
    scriptSetVisibilityAll(0, GModel::current()->getFileName());
    if(!on) return;
    mode = 1;
  }
  for(int i = 0; i < 4; i++) {
    if(state[i][mode].size()) {
      for(std::size_t j = 0; j < state[i][mode].size(); j++) {
        entities.push_back(std::pair<int, int>(i, state[i][mode][j]));
      }
    }
  }
  scriptSetVisibility(mode, entities, GModel::current()->getFileName());
  Msg::StatusBar(true, "Done appending visibility info");
}

static void _set_visibility_by_number(int what, int num, char val,
                                      bool recursive, bool allmodels)
{
  bool all = (num < 0) ? true : false;

  for(std::size_t mod = 0; mod < GModel::list.size(); mod++) {
    GModel *m = GModel::list[mod];
    if(allmodels || m == GModel::current()) {
      std::vector<GEntity *> entities;
      m->getEntities(entities);

      switch(what) {
      case 0: // nodes
        for(std::size_t i = 0; i < entities.size(); i++) {
          for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
            MVertex *v = entities[i]->mesh_vertices[j];
            if(all || (int)v->getNum() == num) v->setVisibility(val);
          }
        }
        break;
      case 1: // elements
        for(std::size_t i = 0; i < entities.size(); i++) {
          for(std::size_t j = 0; j < entities[i]->getNumMeshElements(); j++) {
            MElement *e = entities[i]->getMeshElement(j);
            if(all || (int)e->getNum() == num) e->setVisibility(val);
          }
        }
        break;
      case 2: // point
        for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
          if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
        break;
      case 3: // line
        for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
          if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
        break;
      case 4: // surface
        for(auto it = m->firstFace(); it != m->lastFace(); it++)
          if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
        break;
      case 5: // volume
        for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
          if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
        break;
      case 6: // physical point
        for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
          for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
            if(all || std::abs((*it)->physicals[i]) == num)
              (*it)->setVisibility(val, recursive);
        break;
      case 7: // physical line
        for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
          for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
            if(all || std::abs((*it)->physicals[i]) == num)
              (*it)->setVisibility(val, recursive);
        break;
      case 8: // physical surface
        for(auto it = m->firstFace(); it != m->lastFace(); it++)
          for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
            if(all || std::abs((*it)->physicals[i]) == num)
              (*it)->setVisibility(val, recursive);
        break;
      case 9: // physical volume
        for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
          for(std::size_t i = 0; i < (*it)->physicals.size(); i++)
            if(all || std::abs((*it)->physicals[i]) == num)
              (*it)->setVisibility(val, recursive);
        break;
      }
    }
  }
}

static void _apply_visibility(char mode, bool physical,
                              std::vector<GVertex *> &vertices,
                              std::vector<GEdge *> &edges,
                              std::vector<GFace *> &faces,
                              std::vector<GRegion *> &regions,
                              std::vector<MElement *> &elements)
{
  bool recursive =
    FlGui::instance()->visibility->butt[0]->value() ? true : false;
  bool allmodels =
    FlGui::instance()->visibility->butt[1]->value() ? true : false;

  if(mode == 1) { // when showing a single entity, first hide everything
    if(CTX::instance()->pickElements)
      _set_visibility_by_number(1, -1, 0, false, allmodels);
    else
      for(int i = 2; i <= 5; i++)
        _set_visibility_by_number(i, -1, 0, false, allmodels);
  }

  if(mode == 2) mode = 1;

  if(CTX::instance()->pickElements) {
    for(std::size_t i = 0; i < elements.size(); i++)
      elements[i]->setVisibility(mode);
  }
  else {
    for(std::size_t i = 0; i < vertices.size(); i++) {
      if(!physical)
        vertices[i]->setVisibility(mode, recursive);
      else
        for(std::size_t j = 0; j < vertices[i]->physicals.size(); j++)
          _set_visibility_by_number(6, vertices[i]->physicals[j], mode,
                                    recursive, allmodels);
    }
    for(std::size_t i = 0; i < edges.size(); i++) {
      if(!physical)
        edges[i]->setVisibility(mode, recursive);
      else
        for(std::size_t j = 0; j < edges[i]->physicals.size(); j++)
          _set_visibility_by_number(7, edges[i]->physicals[j], mode, recursive,
                                    allmodels);
    }
    for(std::size_t i = 0; i < faces.size(); i++) {
      if(!physical)
        faces[i]->setVisibility(mode, recursive);
      else
        for(std::size_t j = 0; j < faces[i]->physicals.size(); j++)
          _set_visibility_by_number(8, faces[i]->physicals[j], mode, recursive,
                                    allmodels);
    }
    for(std::size_t i = 0; i < regions.size(); i++) {
      if(!physical)
        regions[i]->setVisibility(mode, recursive);
      else
        for(std::size_t j = 0; j < regions[i]->physicals.size(); j++)
          _set_visibility_by_number(9, regions[i]->physicals[j], mode,
                                    recursive, allmodels);
    }
  }
  int pos = FlGui::instance()->visibility->browser->position();
  visibility_cb(nullptr, (void *)"redraw_only");
  FlGui::instance()->visibility->browser->position(pos);
}

static void visibility_number_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);

  // what = 0 for nodes, 1 for elements, 2 for points, 3 for lines, 4
  // for surfaces, 5 for volumes, 6 for physical points, 7 for
  // physical lines, 8 for physical surfaces and 9 for physical
  // volumes
  int what = (intptr_t)data;
  char val;
  if(what >= 100) { // show
    val = 1;
    what -= 100;
  }
  else { // hide
    val = 0;
  }
  const char *str = FlGui::instance()->visibility->input[what]->value();

  int num = (!strcmp(str, "all") || !strcmp(str, "*")) ? -1 : atoi(str);
  bool recursive =
    FlGui::instance()->visibility->butt[0]->value() ? true : false;
  bool allmodels =
    FlGui::instance()->visibility->butt[1]->value() ? true : false;

  _set_visibility_by_number(what, num, val, recursive, allmodels);

  int pos = FlGui::instance()->visibility->browser->position();
  visibility_cb(nullptr, (void *)"redraw_only");
  FlGui::instance()->visibility->browser->position(pos);
  drawContext::global()->draw();
}

static void visibility_interactive_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  int what;
  char mode; // 0 for hide, 1 for show, 2 for undo
  bool physical = (str.find("physical") != std::string::npos);

  if(str == "elements to hide") {
    CTX::instance()->pickElements = 1;
    what = ENT_ALL;
    mode = 0;
  }
  else if(str == "points to hide" || str == "physical points to hide") {
    CTX::instance()->pickElements = 0;
    what = ENT_POINT;
    mode = 0;
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "curves to hide" || str == "physical curves to hide") {
    CTX::instance()->pickElements = 0;
    what = ENT_CURVE;
    mode = 0;
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "surfaces to hide" || str == "physical surfaces to hide") {
    CTX::instance()->pickElements = 0;
    what = ENT_SURFACE;
    mode = 0;
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "volumes to hide" || str == "physical volumes to hide") {
    CTX::instance()->pickElements = 0;
    what = ENT_VOLUME;
    mode = 0;
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "elements to show") {
    CTX::instance()->pickElements = 1;
    what = ENT_ALL;
    mode = 1;
  }
  else if(str == "points to show" || str == "physical points to show") {
    CTX::instance()->pickElements = 0;
    what = ENT_POINT;
    mode = 1;
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "curves to show" || str == "physical curves to show") {
    CTX::instance()->pickElements = 0;
    what = ENT_CURVE;
    mode = 1;
    opt_geometry_curves(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "surfaces to show" || str == "physical surfaces to show") {
    CTX::instance()->pickElements = 0;
    what = ENT_SURFACE;
    mode = 1;
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "volumes to show" || str == "physical volumes to show") {
    CTX::instance()->pickElements = 0;
    what = ENT_VOLUME;
    mode = 1;
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "show all") {
    bool allmodels =
      FlGui::instance()->visibility->butt[1]->value() ? true : false;
    for(int i = 1; i <= 5; i++) // elements, points, curves, surfaces, volumes
      _set_visibility_by_number(i, -1, 1, false, allmodels);
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    return;
  }
  else
    return;

  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;

  while(1) {
    if(what == ENT_ALL) CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    Msg::StatusGl("Select %s\n[Press %s'q' to abort]", str.c_str(),
                  mode ? "" : "'u' to undo or ");

    char ib = FlGui::instance()->selectEntity(what);
    if(ib == 'l') {
      // store for possible undo later
      vertices = FlGui::instance()->selectedVertices;
      edges = FlGui::instance()->selectedEdges;
      faces = FlGui::instance()->selectedFaces;
      regions = FlGui::instance()->selectedRegions;
      elements = FlGui::instance()->selectedElements;
      _apply_visibility(mode, physical, vertices, edges, faces, regions,
                        elements);
    }
    if(ib == 'u' && !mode) { // undo only in hide mode
      _apply_visibility(2, physical, vertices, edges, faces, regions, elements);
    }
    if(ib == 'q') { break; }
  }

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  Msg::StatusGl("");
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
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
      for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++) {
        drawContext *ctx = FlGui::instance()->graph[i]->gl[j]->getDrawContext();
        ctx->showAll();
      }
    }
    for(int i = 0; i < FlGui::instance()->visibility->per_window->size(); i++)
      FlGui::instance()->visibility->per_window->select(i + 1);
  }
  drawContext::global()->draw();
}

static void browser_cb(Fl_Widget *w, void *data)
{
  if(Fl::event_clicks()) {
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
#if(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
  Fl_Tree *tree = (Fl_Tree *)w;
  if(tree->callback_reason() == FL_TREE_REASON_RESELECTED &&
     Fl::event_clicks()) {
    // double click
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
#endif
}

visibilityWindow::visibilityWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int CC = BB;

  static int cols[5] = {3 * WB, CC, CC, 2 * CC, 0};
  int width = cols[0] + cols[1] + cols[2] + cols[3] + 4 * WB;
  int height = 18 * BH;
  int brw = width - 4 * WB;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Visibility");
  win->box(GMSH_WINDOW_BOX);

  Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
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

    Fl_Group *o =
      new Fl_Group(2 * WB + w1 + WB, height - 2 * BH - 3 * WB, w2, BH);
    o->tooltip("Filter list using regular expression");
    o->box(FL_DOWN_BOX);
    o->color(FL_BACKGROUND2_COLOR);
    search = new Fl_Input(2 * WB + w1 + WB + BH, height - 2 * BH - 3 * WB + 2,
                          w2 - BH - 2, BH - 4, "@gmsh_search");
    search->box(FL_FLAT_BOX);
    search->callback(visibility_cb, (void *)"list_only");
    search->when(FL_WHEN_CHANGED);
    o->resizable(search);
    o->end();

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
#if(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
    tree->item_reselect_mode(FL_TREE_SELECTABLE_ALWAYS); // for double-clicks
#endif
    tree->callback(tree_cb);
    tree->hide();

    tree_create =
      new Fl_Button(2 * WB, 2 * WB + BH, brw, height - 6 * WB - 3 * BH,
                    "The model contains more than 50 thousand entities,\n"
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
    for(int i = 0; i < 10; i++) {
      if(i == 0) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Mesh");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 2) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Elementary entities");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 6) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Physical groups");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      input[i] = new Fl_Input(width / 2 - WB / 2 - IW, yy, IW, BH);
      input[i]->align(FL_ALIGN_LEFT);
      input[i]->value("*");

      Fl_Button *o1 = new Fl_Button(width / 2 + WB / 2, yy, CC, BH, "Show");
      o1->callback(visibility_number_cb, (void *)(100 + (intptr_t)i));

      Fl_Button *o2 =
        new Fl_Button(width / 2 + WB / 2 + CC + WB, yy, CC, BH, "Hide");
      o2->callback(visibility_number_cb, (void *)(intptr_t)i);
      yy += BH;
    }

    input[0]->label("Node");
    input[0]->tooltip("Enter node number, or *");

    input[1]->label("Element");
    input[1]->tooltip("Enter element number, or *");

    input[2]->label("Point");
    input[2]->tooltip("Enter point number, or *");

    input[3]->label("Curve");
    input[3]->tooltip("Enter curve number, or *");

    input[4]->label("Surface");
    input[4]->tooltip("Enter surface number, or *");

    input[5]->label("Volume");
    input[5]->tooltip("Enter volume number, or *");

    input[6]->label("Point");
    input[6]->tooltip("Enter point number, or *");

    input[7]->label("Curve");
    input[7]->tooltip("Enter curve number, or *");

    input[8]->label("Surface");
    input[8]->tooltip("Enter surface number, or *");

    input[9]->label("Volume");
    input[9]->tooltip("Enter volume number, or *");

    g->end();
  }
  {
    Fl_Group *g = new Fl_Group(WB, WB + BH, width - 2 * WB,
                               height - 3 * WB - 2 * BH, "Interactive");
    g->resizable(nullptr);

    Fl_Button *bb[20];
    int ll = width / 2 - BH - WB - IW;
    int ll2 = ll + IW + WB + 2 * BH + WB;
    int yy = 2 * WB + BH;
    for(int i = 0; i < 9; i++) {
      if(i == 0) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Mesh");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 1) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Elementary entities");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 5) {
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Physical groups");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      bb[2 * i] = new Fl_Button(ll, yy, IW, BH);
      bb[2 * i + 1] = new Fl_Button(ll2, yy, IW, BH);
      yy += BH;
    }
    bb[0]->label("Hide elements");
    bb[0]->callback(visibility_interactive_cb, (void *)"elements to hide");
    bb[1]->label("Show elements");
    bb[1]->callback(visibility_interactive_cb, (void *)"elements to show");
    bb[2]->label("Hide points");
    bb[2]->callback(visibility_interactive_cb, (void *)"points to hide");
    bb[3]->label("Show points");
    bb[3]->callback(visibility_interactive_cb, (void *)"points to show");
    bb[4]->label("Hide curves");
    bb[4]->callback(visibility_interactive_cb, (void *)"curves to hide");
    bb[5]->label("Show curves");
    bb[5]->callback(visibility_interactive_cb, (void *)"curves to show");
    bb[6]->label("Hide surfaces");
    bb[6]->callback(visibility_interactive_cb, (void *)"surfaces to hide");
    bb[7]->label("Show surfaces");
    bb[7]->callback(visibility_interactive_cb, (void *)"surfaces to show");
    bb[8]->label("Hide volumes");
    bb[8]->callback(visibility_interactive_cb, (void *)"volumes to hide");
    bb[9]->label("Show volumes");
    bb[9]->callback(visibility_interactive_cb, (void *)"volumes to show");
    bb[10]->label("Hide points");
    bb[10]->callback(visibility_interactive_cb,
                     (void *)"physical points to hide");
    bb[11]->label("Show points");
    bb[11]->callback(visibility_interactive_cb,
                     (void *)"physical points to show");
    bb[12]->label("Hide curves");
    bb[12]->callback(visibility_interactive_cb,
                     (void *)"physical curves to hide");
    bb[13]->label("Show curves");
    bb[13]->callback(visibility_interactive_cb,
                     (void *)"physical curves to show");
    bb[14]->label("Hide surfaces");
    bb[14]->callback(visibility_interactive_cb,
                     (void *)"physical surfaces to hide");
    bb[15]->label("Show surfaces");
    bb[15]->callback(visibility_interactive_cb,
                     (void *)"physical surfaces to show");
    bb[16]->label("Hide volumes");
    bb[16]->callback(visibility_interactive_cb,
                     (void *)"physical volumes to hide");
    bb[17]->label("Show volumes");
    bb[17]->callback(visibility_interactive_cb,
                     (void *)"physical volumes to show");

    bb[18] = new Fl_Button(ll + IW + WB, 2 * WB + 2 * BH, 2 * BH, 11 * BH,
                           "Show\nAll");
    bb[18]->callback(visibility_interactive_cb, (void *)"show all");

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
  win->size_range(width, 15 * BH + 5 * WB);

  {
    int aw = (int)(3.5 * FL_NORMAL_SIZE);

    Fl_Group *g = new Fl_Group(WB, height - BH - WB, width - 2 * WB - CC, BH);
    g->resizable(nullptr);

    Fl_Box *b = new Fl_Box(WB, height - BH - WB, aw, BH, "Apply");
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    butt[0] = new Fl_Check_Button(WB + aw + WB, height - BH - WB, 2 * aw, BH,
                                  "recursively");
    butt[0]->type(FL_TOGGLE_BUTTON);
    butt[0]->value(1);

    butt[1] = new Fl_Check_Button(WB + 3 * aw + 2 * WB, height - BH - WB,
                                  3 * aw, BH, "to all models");
    butt[1]->type(FL_TOGGLE_BUTTON);
    butt[1]->value(1);

    g->end();

    Fl_Button *o1 =
      new Fl_Button(width - CC - WB, height - BH - WB, CC, BH, "Save");
    o1->callback(visibility_save_cb);
  }

  win->position(CTX::instance()->visPosition[0],
                CTX::instance()->visPosition[1]);
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

void visibilityWindow::updatePerWindow(bool force)
{
  static openglWindow *gl = nullptr;
  if(!force && gl == FlGui::instance()->getCurrentOpenglWindow()) return;

  gl = FlGui::instance()->getCurrentOpenglWindow();
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
