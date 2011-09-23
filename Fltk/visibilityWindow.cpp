// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stdint.h>
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
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "GeoStringInterface.h"
#include "Options.h"
#include "Context.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

class Vis {
 private:
  std::string _name;
 public:
  Vis() {}
  Vis(std::string &name) : _name(name) {}
  virtual ~Vis(){}
  virtual int getTag() const = 0;
  virtual int getDim() const { return -1; }
  virtual std::string getName() const { return _name; }
  virtual std::string getType() const = 0;
  virtual char getVisibility() const = 0;
  virtual void setVisibility(char val, bool recursive=false) = 0;
};

class VisModel : public Vis {
 private:
  GModel *_model;
  int _tag;
 public:
  VisModel(GModel *model, int tag, std::string &name)
    : Vis(name), _model(model), _tag(tag) {}
  ~VisModel(){}
  int getTag() const { return _tag; }
  std::string getType() const { return "Model"; }
  char getVisibility() const { return _model->getVisibility(); }
  void setVisibility(char val, bool recursive=false){ _model->setVisibility(val); }
};

class VisElementary : public Vis {
 private:
  GEntity *_e;
 public:
  VisElementary(GEntity *e, std::string &name) : Vis(name), _e(e) {}
  ~VisElementary(){}
  int getTag() const { return _e->tag(); }
  int getDim() const { return _e->dim(); }
  std::string getType() const
  {
    if(_e->dim() == 0) return "Point";
    else if(_e->dim() == 1) return "Line";
    else if(_e->dim() == 2) return "Surface";
    else return "Volume";
  }
  char getVisibility() const { return _e->getVisibility(); }
  void setVisibility(char val, bool recursive=false)
  {
    _e->setVisibility(val, recursive);
  }
};

class VisPhysical : public Vis {
 private:
  int _tag, _dim;
  char _visible;
  std::vector<GEntity*> _list;
 public:
  VisPhysical(int tag, int dim, std::vector<GEntity*> list, std::string &name) 
    : Vis(name), _tag(tag), _dim(dim), _visible(1), _list(list)  {}
  ~VisPhysical(){}
  int getTag() const { return _tag; }
  int getDim() const { return _dim; }
  std::string getType() const
  {
    if(_dim == 0) return "Point";
    else if(_dim == 1) return "Line";
    else if(_dim == 2) return "Surface";
    else return "Volume";
  }
  char getVisibility() const { return _visible; }
  void setVisibility(char val, bool recursive=false)
  {
    _visible = val;
    for(unsigned int i = 0; i < _list.size(); i++)
      _list[i]->setVisibility(val, recursive);
  }
};

class VisPartition : public Vis {
 private:
  int _tag;
  char _visible;
 public:
  VisPartition(int tag) : _tag(tag), _visible(1) {}
  ~VisPartition(){}
  int getTag() const { return _tag; }
  std::string getType() const { return "Partition"; }
  char getVisibility() const { return _visible; }
  void setVisibility(char val, bool recursive=false)
  {
    GModel *m = GModel::current();
    _visible = val;
    std::vector<GEntity*> entities;
    m->getEntities(entities);
    for(unsigned int i = 0; i < entities.size(); i++)
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++)
        if(entities[i]->getMeshElement(j)->getPartition() == _tag) 
          entities[i]->getMeshElement(j)->setVisibility(val);
  }
};

class VisibilityList { // singleton
 private:
  std::vector<Vis*> _entities;
  int _sortMode;
  static VisibilityList *_instance;
  VisibilityList() : _sortMode(-1) {}
 public :
  enum VisibilityType{
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
      switch(instance()->getSortMode()){
      case  1: return v1->getDim() < v2->getDim() ? true : false;
      case -1: return v1->getDim() > v2->getDim() ? true : false;
      case  2: return v1->getTag() < v2->getTag() ? true : false;
      case -2: return v1->getTag() > v2->getTag() ? true : false;
      case  3: return strcmp(v1->getName().c_str(), v2->getName().c_str()) < 0 ?
          true : false;
      default: return strcmp(v1->getName().c_str(), v2->getName().c_str()) > 0 ?
          true : false;
      }
    }
  };
  // repopulate the list with current data of the given type
  void update(VisibilityType type)
  {
    std::map<int, std::string> oldLabels;
#if defined(HAVE_PARSER)
    for(std::map<std::string, std::vector<double> >::iterator it = gmsh_yysymbols.begin();
        it != gmsh_yysymbols.end(); ++it)
      if(it->first.size())
        for(unsigned int i = 0; i < it->second.size(); i++)
          oldLabels[(int)it->second[i]] = std::string("(") + it->first + ")";
#endif
    for(unsigned int i = 0; i < _entities.size(); i++)
      delete _entities[i];
    _entities.clear();
    GModel *m = GModel::current();
    if(type == Models){
      for(unsigned int i = 0; i < GModel::list.size(); i++){
        std::string name = GModel::list[i]->getName();
        if(GModel::list[i] == GModel::current()) name += " (Active)";
        _entities.push_back(new VisModel(GModel::list[i], i, name));
      }
    }
    else if(type == ElementaryEntities){
      std::vector<GEntity*> entities;
      m->getEntities(entities);
      for(unsigned int i = 0; i < entities.size(); i++){
        GEntity *ge = entities[i];
        std::string name = m->getElementaryName(ge->dim(), ge->tag());
        if(name.empty()) name = oldLabels[ge->tag()];
        _entities.push_back(new VisElementary(ge, name));
      }
    }
    else if(type == PhysicalEntities){
      std::map<int, std::vector<GEntity*> > groups[4];
      m->getPhysicalGroups(groups);
      for(int i = 0; i < 4; i++){
        std::map<int, std::vector<GEntity*> >::const_iterator it = groups[i].begin();
        for(; it != groups[i].end(); ++it){
          std::string name = m->getPhysicalName(i, it->first);
          if(name.empty()) name = oldLabels[it->first];
          _entities.push_back(new VisPhysical(it->first, i, it->second, name));
        }
      }
    }
    else if(type == MeshPartitions){
      std::set<int> part = m->getMeshPartitions();
      for(std::set<int>::const_iterator it = part.begin(); it != part.end(); ++it)
        _entities.push_back(new VisPartition(*it));
    }
    std::sort(_entities.begin(), _entities.end(), VisLessThan());
  }
  // get the number of entities in the list
  int getNumEntities() { return _entities.size(); }
  // get the number of entities in the list
  Vis *getEntity(int i) { return _entities[i]; }
  // get the visibility information for the nth entity in the list
  char getVisibility(int n){ return _entities[n]->getVisibility(); }
  // set the visibility information for the nth entity in the list
  void setVisibility(int n, char val, bool recursive=false)
  { 
    _entities[n]->setVisibility(val, recursive);
  }
  // set all entities to be invisible
  void setAllInvisible(VisibilityType type)
  {
    if(type == Models){
      for(unsigned int i = 0; i < GModel::list.size(); i++)
        GModel::list[i]->setVisibility(0);
    }
    else if(type == ElementaryEntities || type == PhysicalEntities){
      // elementary or physical mode: set all entities in the model invisible
      std::vector<GEntity*> entities;
      GModel::current()->getEntities(entities);
      for(unsigned int i = 0; i < entities.size(); i++)
        entities[i]->setVisibility(0);
    }
    // this is superfluous in elementary mode, but we don't care
    for(int i = 0; i < getNumEntities(); i++) setVisibility(i, 0);
  }
  // get the tag of the nth entity in the list
  int getTag(int n){ return _entities[n]->getTag(); }
  // get the browser line for the nth entity in the list
  std::string getBrowserLine(int n)
  {
    std::ostringstream sstream;
    sstream << "\t" << _entities[n]->getType() 
            << "\t" << _entities[n]->getTag() 
            << "\t" << _entities[n]->getName();
    return sstream.str();
  }
  // set the sort mode
  void setSortMode(int mode){ _sortMode = (_sortMode != mode) ? mode : -mode; }
  // get the sort mode
  int getSortMode(){ return _sortMode; }
};

VisibilityList *VisibilityList::_instance = 0;

static void _rebuild_list_browser()
{
  FlGui::instance()->visibility->browser->clear();

  VisibilityList::VisibilityType type;
  switch(FlGui::instance()->visibility->browser_type->value()){
  case 0: type = VisibilityList::Models; break;
  case 2: type = VisibilityList::PhysicalEntities; break;
  case 3: type = VisibilityList::MeshPartitions; break;
  case 1: default: type = VisibilityList::ElementaryEntities; break;
  }

  VisibilityList::instance()->update(type);
  for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++){
    FlGui::instance()->visibility->browser->add
      (VisibilityList::instance()->getBrowserLine(i).c_str());
    if(VisibilityList::instance()->getVisibility(i))
      FlGui::instance()->visibility->browser->select(i + 1);
  }
  
  // activate/deactivate delete button
  if(type == VisibilityList::PhysicalEntities)
    FlGui::instance()->visibility->push[0]->activate();
  else
    FlGui::instance()->visibility->push[0]->deactivate();
}

static void visibility_browser_apply_cb(Fl_Widget *w, void *data)
{
  // if the browser is not empty, get the selections made in the
  // browser and apply them into the model
  if(VisibilityList::instance()->getNumEntities()){
    CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    bool recursive = FlGui::instance()->visibility->butt[0]->value() ? true : false;
    VisibilityList::VisibilityType type;
    switch(FlGui::instance()->visibility->browser_type->value()){
    case 0: type = VisibilityList::Models; break;
    case 2: type = VisibilityList::PhysicalEntities; break;
    case 3: type = VisibilityList::MeshPartitions; break;
    case 1: default: type = VisibilityList::ElementaryEntities; break;
    }
    VisibilityList::instance()->setAllInvisible(type);
    for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++)
      if(FlGui::instance()->visibility->browser->selected(i + 1))
        VisibilityList::instance()->setVisibility(i, 1, recursive);
    // then refresh the browser to account for recursive selections
    for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++)
      if(VisibilityList::instance()->getVisibility(i))
        FlGui::instance()->visibility->browser->select(i + 1);
    drawContext::global()->draw();
  }
}

static void visibility_delete_cb(Fl_Widget *w, void *data)
{
  bool all = true;
  for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++){
    if(!FlGui::instance()->visibility->browser->selected(i + 1)){
      all = false;
      break;
    }
  }
  if(all){
    GModel::current()->deletePhysicalGroups();
  }
  else{
    for(int i = 0; i < VisibilityList::instance()->getNumEntities(); i++){
      if(FlGui::instance()->visibility->browser->selected(i + 1)){
        Vis *v = VisibilityList::instance()->getEntity(i);
        GModel::current()->deletePhysicalGroup(v->getDim(), v->getTag());
      }
    }
  }
  visibility_cb(NULL, (void*)"redraw_only");
}

static void visibility_sort_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;
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
  else if(val == -1){ // invert the selection
    int *state = new int[FlGui::instance()->visibility->browser->size()];
    for(int i = 0; i < FlGui::instance()->visibility->browser->size(); i++)
      state[i] = FlGui::instance()->visibility->browser->selected(i + 1);
    FlGui::instance()->visibility->browser->deselect();
    for(int i = 0; i < FlGui::instance()->visibility->browser->size(); i++)
      if(!state[i]) FlGui::instance()->visibility->browser->select(i + 1);
    delete [] state;
  }
  else if(val == -2){ // create new parameter name for selection
    for(int i = 0; i < FlGui::instance()->visibility->browser->size(); i++){
      if(FlGui::instance()->visibility->browser->selected(i + 1)){
        static char tmpstr[256];
        sprintf(tmpstr, "%d", VisibilityList::instance()->getTag(i));
        FlGui::instance()->geoContext->input[1]->value(tmpstr);
        break;
      }
    }
    FlGui::instance()->geoContext->input[0]->value("NewName");
    FlGui::instance()->geoContext->show(0);
  }
  else { // set new sorting mode
    VisibilityList::instance()->setSortMode(val);
    visibility_cb(NULL, (void*)"redraw_only");
  }
}

class listBrowser : public Fl_Browser{
  int handle(int event)
  {
    switch(event){
    case FL_SHORTCUT:
    case FL_KEYBOARD:
      if(Fl::test_shortcut(FL_CTRL+'a')){
        for(int i = 0; i < size(); i++)
          select(i + 1);
        return 1;
      }
      else if(Fl::test_shortcut(FL_Enter) || 
              Fl::test_shortcut(FL_KP_Enter)){
        visibility_browser_apply_cb(NULL, NULL);
        return 1;
      }
    }
    return Fl_Browser::handle(event);
  }
 public:
  listBrowser(int x, int y, int w , int h, const char* c = 0)
    : Fl_Browser(x, y, w, h, c){}
};

#if defined(HAVE_FL_TREE)

static void _add_vertex(GVertex *gv, Fl_Tree *tree, std::string path)
{
  std::ostringstream vertex;
  vertex << path << "Point " << gv->tag() << "/";
  Fl_Tree_Item *n = tree->add(vertex.str().c_str());
  if(gv->getVisibility()) n->select(1);
  n->user_data((void*)gv);
  n->close();
}

static void _add_edge(GEdge *ge, Fl_Tree *tree, std::string path)
{
  std::ostringstream edge;
  edge << path << "Line " << ge->tag() << "/";
  Fl_Tree_Item *n = tree->add(edge.str().c_str());
  if(ge->getVisibility()) n->select(1);
  n->user_data((void*)ge);
  n->close();
  if(ge->getBeginVertex())
    _add_vertex(ge->getBeginVertex(), tree, edge.str());
  if(ge->getEndVertex())
    _add_vertex(ge->getEndVertex(), tree, edge.str());
}

static void _add_face(GFace *gf, Fl_Tree *tree, std::string path)
{
  std::ostringstream face;
  face << path << "Surface " << gf->tag() << "/";
  Fl_Tree_Item *n = tree->add(face.str().c_str());
  if(gf->getVisibility()) n->select(1);
  n->user_data((void*)gf);
  n->close();
  std::list<GEdge*> edges = gf->edges();
  for(std::list<GEdge*>::iterator it = edges.begin(); it != edges.end(); it++)
    _add_edge(*it, tree, face.str());
}

static void _add_region(GRegion *gr, Fl_Tree *tree, std::string path)
{
  std::ostringstream region;
  region << path << "Volume " << gr->tag() << "/";
  Fl_Tree_Item *n = tree->add(region.str().c_str());
  if(gr->getVisibility()) n->select(1);
  n->user_data((void*)gr);
  n->close();
  std::list<GFace*> faces = gr->faces();
  for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++)
    _add_face(*it, tree, region.str());
}

static void _add_physical_group(int dim, int num, std::vector<GEntity*> &ge,
                                std::map<int, std::string> &oldLabels, 
                                Fl_Tree *tree, std::string path)
{
  if(ge.empty()) return;
  std::string name = ge[0]->model()->getPhysicalName(dim, num);
  if(name.empty()) name = oldLabels[num];
  if(name.size()) name = std::string(" <<") + name + ">>";

  Fl_Tree_Item *n;
  std::ostringstream group;
  group << path;
  switch(dim){
  case 3:
    group << "Physical Volume " << num << name << "/";
    n = tree->add(group.str().c_str());
    n->close();
    for(unsigned int i = 0; i < ge.size(); i++)
      _add_region((GRegion*)ge[i], tree, group.str());
    break;
  case 2:
    group << "Physical Surface " << num << name << "/";
    n = tree->add(group.str().c_str());
    n->close();
    for(unsigned int i = 0; i < ge.size(); i++)
      _add_face((GFace*)ge[i], tree, group.str());
    break;
  case 1:
    group << "Physical Line " << num << name << "/";
    n = tree->add(group.str().c_str());
    n->close();
    for(unsigned int i = 0; i < ge.size(); i++)
      _add_edge((GEdge*)ge[i], tree, group.str());
    break;
  case 0:
    group << "Physical Point " << num << name << "/";
    n = tree->add(group.str().c_str());
    n->close();
    for(unsigned int i = 0; i < ge.size(); i++)
      _add_vertex((GVertex*)ge[i], tree, group.str());
    break;
  default:
    break;
  }
}

static void _rebuild_tree_browser(bool force)
{
  if(!force){
    int numEnt = 0;
    for(unsigned int i = 0; i < GModel::list.size(); i++){
      numEnt += GModel::list[i]->getNumRegions() +
        GModel::list[i]->getNumFaces() +
        GModel::list[i]->getNumEdges() +
        GModel::list[i]->getNumVertices();
    }
    if(numEnt > 10000){
      FlGui::instance()->visibility->tree->hide();
      FlGui::instance()->visibility->tree_create->show();
      return;
    }
  }

  FlGui::instance()->visibility->tree_create->hide();
  FlGui::instance()->visibility->tree->show();
  FlGui::instance()->visibility->tree->clear();

  for(unsigned int i = 0; i < GModel::list.size(); i++){
    GModel *m = GModel::list[i];
    std::ostringstream model;
    model << "Model [" << i << "] <<" << m->getName() << ">>";
    if(m == GModel::current()) model << " (Active)";
    model << "/";

    Fl_Tree_Item *n;
    n = FlGui::instance()->visibility->tree->add(model.str().c_str());
    if(m->getVisibility()) n->select(1);
    n->close();

    std::string elementary = model.str() + "Elementary entities/";
    n = FlGui::instance()->visibility->tree->add(elementary.c_str());
    n->close();

    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++)
      _add_region(*it, FlGui::instance()->visibility->tree, elementary);
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
      _add_face(*it, FlGui::instance()->visibility->tree, elementary);
    for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
      _add_edge(*it, FlGui::instance()->visibility->tree, elementary);
    for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); it++)
      _add_vertex(*it, FlGui::instance()->visibility->tree, elementary);

    std::string physical = model.str() + "Physical groups/";
    n = FlGui::instance()->visibility->tree->add(physical.c_str());
    n->close();

    std::map<int, std::vector<GEntity*> > groups[4];
    m->getPhysicalGroups(groups);
    std::map<int, std::string> oldLabels;
#if defined(HAVE_PARSER)
    for(std::map<std::string, std::vector<double> >::iterator it = gmsh_yysymbols.begin();
        it != gmsh_yysymbols.end(); ++it)
      if(it->first.size())
        for(unsigned int i = 0; i < it->second.size(); i++)
          oldLabels[(int)it->second[i]] = std::string("(") + it->first + ")";
#endif
    for(int i = 3; i >= 0; i--)
      for(std::map<int, std::vector<GEntity*> >::iterator it = groups[i].begin();
          it != groups[i].end(); it++)
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
  for(int i = 0; i < n->children(); i++)
    _recur_select(n->child(i));
}

static void _recur_set_visible(Fl_Tree_Item *n)
{
  if(n->user_data() && n->is_selected()){
    GEntity *ge = (GEntity*)n->user_data();
    bool recursive = FlGui::instance()->visibility->butt[0]->value() ? true : false;
    ge->setVisibility(1, recursive);
    // force this: if we ask to see an entity, let's assume that we
    // don't want the whole model to be invisible
    ge->model()->setVisibility(1);
  }
  for(int i = 0; i < n->children(); i++)
    _recur_set_visible(n->child(i));
}

static void _recur_update_selected(Fl_Tree_Item *n)
{
  if(n->user_data()){
    GEntity *ge = (GEntity*)n->user_data();
    n->select(ge->getVisibility() ? 1 : 0);
  }
  for(int i = 0; i < n->children(); i++)
    _recur_update_selected(n->child(i));
}

static void visibility_tree_apply_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  bool recursive = FlGui::instance()->visibility->butt[0]->value() ? true : false;

  Fl_Tree_Item *root = FlGui::instance()->visibility->tree->root();
  for(int i = 0; i < root->children(); i++){
    GModel *m = GModel::list[i];
    Fl_Tree_Item *n = root->child(i);
    // treat special levels separately
    if(recursive){
      if(root->is_selected() || n->is_selected()){ // if root or model is selected
        _recur_select(n);
      }
      else{
        for(int j = 0; j < n->children(); j++){
          if(n->child(j)->is_selected()) // if elementary/physical is selected
            _recur_select(n->child(j));
          else if(j == 1){
            for(int k = 0; k < n->child(j)->children(); k++){
              if(n->child(j)->child(k)->is_selected()) // if physical ent is selected
                _recur_select(n->child(j)->child(k));
            }
          }
        }
      }
    }
    // set all entities as invisible
    std::vector<GEntity*> entities;
    m->getEntities(entities);
    for(unsigned int j = 0; j < entities.size(); j++)
      entities[j]->setVisibility(0);
    // set visibility flag according to tree selection
    _recur_set_visible(n);
    // update tree selection
    _recur_update_selected(n);
  }
  FlGui::instance()->visibility->tree->redraw();
  drawContext::global()->draw();
}

class treeBrowser : public Fl_Tree{
  int handle(int event)
  {
    switch(event){
    case FL_SHORTCUT:
    case FL_KEYBOARD:
      if(Fl::test_shortcut(FL_Enter) || Fl::test_shortcut(FL_KP_Enter)){
        visibility_tree_apply_cb(NULL, NULL);
        return 1;
      }
    }
    return Fl_Tree::handle(event);
  }
 public:
  treeBrowser(int x, int y, int w , int h, const char* c = 0)
    : Fl_Tree(x, y, w, h, c){}
};

#endif

void visibility_cb(Fl_Widget *w, void *data)
{
  // get the visibility info from the model, and update the browser
  // accordingly
  const char *str = (const char*)data;
  if(str && !strcmp(str, "redraw_only"))
    FlGui::instance()->visibility->show(true);
  else
    FlGui::instance()->visibility->show(false);

  _rebuild_list_browser();
#if defined(HAVE_FL_TREE)
  _rebuild_tree_browser(false);
#endif
  FlGui::instance()->visibility->updatePerWindow(true);
}

static void visibility_save_cb(Fl_Widget *w, void *data)
{
  Msg::StatusBar(2, true, "Appending visibility info to '%s'...", 
                 GModel::current()->getFileName().c_str());
  // get the whole visibility information in geo format
  std::vector<int> state[4][2];
  GModel *m = GModel::current();
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); it++)
    (*it)->getVisibility() ?
      state[0][1].push_back((*it)->tag()) : state[0][0].push_back((*it)->tag());
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
    (*it)->getVisibility() ? 
      state[1][1].push_back((*it)->tag()) : state[1][0].push_back((*it)->tag());
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
    (*it)->getVisibility() ? 
      state[2][1].push_back((*it)->tag()) : state[2][0].push_back((*it)->tag());
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++)
    (*it)->getVisibility() ? 
      state[3][1].push_back((*it)->tag()) : state[3][0].push_back((*it)->tag());
  char tmp[256];
  const char *labels[4] = {"Point", "Line", "Surface", "Volume"};
  std::string str;
  int mode;
  int on = 0, off = 0;
  for(int i = 0; i < 4; i++){
    on += state[i][1].size();
    off += state[i][0].size();
  }
  if(on > off){
    add_infile("Show \"*\";", GModel::current()->getFileName());
    if(!off) return;
    str += "Hide {\n";
    mode = 0;
  }
  else{
    add_infile("Hide \"*\";", GModel::current()->getFileName());
    if(!on) return;
    str += "Show {\n";
    mode = 1;
  }
  for(int i = 0; i < 4; i++){
    if(state[i][mode].size()){
      str += labels[i];
      str += "{";
      for(unsigned int j = 0; j < state[i][mode].size(); j++){
        if(j) str += ",";
        sprintf(tmp, "%d", state[i][mode][j]);
        str += tmp;
      }
      str += "};\n";
    }
  }
  str += "}\n";
  add_infile(str, GModel::current()->getFileName());
  Msg::StatusBar(2, true, "Done appending visibility info");
}

static void _set_visibility_by_number(int what, int num, char val, bool recursive)
{
  bool all = (num < 0) ? true : false;

  GModel *m = GModel::current();
  std::vector<GEntity*> entities;
  m->getEntities(entities);

  switch(what){
  case 0: // nodes
    for(unsigned int i = 0; i < entities.size(); i++){
      for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
        MVertex *v = entities[i]->mesh_vertices[j];
        if(all || v->getNum() == num) v->setVisibility(val);
      }
    }
    break;
  case 1: // elements
    for(unsigned int i = 0; i < entities.size(); i++){
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        if(all || e->getNum() == num) e->setVisibility(val);
      }
    }
    break;
  case 2: // point
    for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
    break;
  case 3: // line
    for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
    break;
  case 4: // surface
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
    break;
  case 5: // volume
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val, recursive);
    break;
  case 6: // physical point
    for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); it++)
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
        if (all || std::abs((*it)->physicals[i]) == num)
          (*it)->setVisibility(val, recursive);
    break;
  case 7: // physical line
    for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
        if (all || std::abs((*it)->physicals[i]) == num) 
          (*it)->setVisibility(val, recursive);
    break;
  case 8: // physical surface
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
        if (all || std::abs((*it)->physicals[i]) == num) 
          (*it)->setVisibility(val, recursive);
    break;
  case 9: // physical volume
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++)
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
        if (all || std::abs((*it)->physicals[i]) == num) 
          (*it)->setVisibility(val, recursive);
    break;
  }
}

static void _apply_visibility(char mode, bool physical,
                              std::vector<GVertex*> &vertices,
                              std::vector<GEdge*> &edges,
                              std::vector<GFace*> &faces,
                              std::vector<GRegion*> &regions,
                              std::vector<MElement*> &elements)
{
  bool recursive = FlGui::instance()->visibility->butt[0]->value() ? true : false;

  if(mode == 1){ // when showing a single entity, first hide everything
    if(CTX::instance()->pickElements)
      _set_visibility_by_number(1, -1, 0, false);
    else
      for(int i = 2; i <= 5; i++)
        _set_visibility_by_number(i, -1, 0, false);
  }

  if(mode == 2) mode = 1;
  
  if(CTX::instance()->pickElements){
    for(unsigned int i = 0; i < elements.size(); i++)
      elements[i]->setVisibility(mode);
  }
  else{
    for(unsigned int i = 0; i < vertices.size(); i++){
      if(!physical)
        vertices[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < vertices[i]->physicals.size(); j++)
          _set_visibility_by_number(6, vertices[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < edges.size(); i++){
      if(!physical)
        edges[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < edges[i]->physicals.size(); j++)
          _set_visibility_by_number(7, edges[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < faces.size(); i++){
      if(!physical)
        faces[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < faces[i]->physicals.size(); j++)
          _set_visibility_by_number(8, faces[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < regions.size(); i++){
      if(!physical)
        regions[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < regions[i]->physicals.size(); j++)
          _set_visibility_by_number(9, regions[i]->physicals[j], mode, recursive);
    }
  }
  int pos = FlGui::instance()->visibility->browser->position();
  visibility_cb(NULL, (void*)"redraw_only");
  FlGui::instance()->visibility->browser->position(pos);
}

static void visibility_number_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);

  // what = 0 for nodes, 1 for elements, 2 for points, 3 for lines, 4
  // for surfaces, 5 for volumes, 6 for physical points, 7 for
  // physical lines, 8 for physical surfaces and 9 for physical
  // volumes
  int what = (intptr_t)data;
  char val;
  if(what >= 100){ // show
    val = 1;
    what -= 100;
  }
  else{ // hide
    val = 0;
  }
  const char *str = FlGui::instance()->visibility->input[what]->value();

  int num = (!strcmp(str, "all") || !strcmp(str, "*")) ? -1 : atoi(str);
  bool recursive = FlGui::instance()->visibility->butt[0]->value() ? true : false;
  
  _set_visibility_by_number(what, num, val, recursive);

  int pos = FlGui::instance()->visibility->browser->position();
  visibility_cb(NULL, (void*)"redraw_only");
  FlGui::instance()->visibility->browser->position(pos);
  drawContext::global()->draw();
}

static void visibility_interactive_cb(Fl_Widget *w, void *data)
{
  std::string str((const char*)data);
  int what;
  char mode; // 0 for hide, 1 for show, 2 for undo
  bool physical = (str.find("physical") != std::string::npos);

  if(str == "elements to hide"){
    CTX::instance()->pickElements = 1;
    what = ENT_ALL;
    mode = 0;
  }
  else if(str == "points to hide" || str == "physical points to hide"){
    CTX::instance()->pickElements = 0;
    what = ENT_POINT;
    mode = 0;
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "lines to hide" || str == "physical lines to hide"){
    CTX::instance()->pickElements = 0;
    what = ENT_LINE;
    mode = 0;
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "surfaces to hide" || str == "physical surfaces to hide"){
    CTX::instance()->pickElements = 0;
    what = ENT_SURFACE;
    mode = 0;
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "volumes to hide" || str == "physical volumes to hide"){
    CTX::instance()->pickElements = 0;
    what = ENT_VOLUME;
    mode = 0;
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "elements to show"){
    CTX::instance()->pickElements = 1;
    what = ENT_ALL;
    mode = 1;
  }
  else if(str == "points to show" || str == "physical points to show"){
    CTX::instance()->pickElements = 0;
    what = ENT_POINT;
    mode = 1;
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "lines to show" || str == "physical lines to show"){
    CTX::instance()->pickElements = 0;
    what = ENT_LINE;
    mode = 1;
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "surfaces to show" || str == "physical surfaces to show"){
    CTX::instance()->pickElements = 0;
    what = ENT_SURFACE;
    mode = 1;
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "volumes to show" || str == "physical volumes to show"){
    CTX::instance()->pickElements = 0;
    what = ENT_VOLUME;
    mode = 1;
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(str == "show all"){
    for(int i = 1; i <= 5; i++) // elements, points, lines, surfaces, volumes
      _set_visibility_by_number(i, -1, 1, false);
    CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();  
    return;
  }
  else
    return;

  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;

  while(1) {
    if(what == ENT_ALL) 
      CTX::instance()->mesh.changed = ENT_ALL;
    drawContext::global()->draw();
    Msg::StatusBar(3, false, "Select %s\n[Press %s'q' to abort]", 
                   str.c_str(), mode ? "" : "'u' to undo or ");

    char ib = FlGui::instance()->selectEntity(what);
    if(ib == 'l') {
      // store for possible undo later
      vertices = FlGui::instance()->selectedVertices;
      edges = FlGui::instance()->selectedEdges;
      faces = FlGui::instance()->selectedFaces;
      regions = FlGui::instance()->selectedRegions;
      elements = FlGui::instance()->selectedElements;
      _apply_visibility(mode, physical, vertices, edges, faces, regions, elements);
    }
    if(ib == 'u' && !mode){ // undo only in hide mode
      _apply_visibility(2, physical, vertices, edges, faces, regions, elements);
    }
    if(ib == 'q'){
      break;
    }
  }

  CTX::instance()->mesh.changed = ENT_ALL;
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();  
  Msg::StatusBar(3, false, "");
}

static void visibility_per_window_cb(Fl_Widget *w, void *data)
{
  std::string what = (const char*)data;
  if(what == "item"){
    drawContext *ctx = FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
    for(unsigned int i = 0; 
        i < (unsigned int)FlGui::instance()->visibility->per_window->size(); i++){
      if(i < GModel::list.size()){
        GModel *m = GModel::list[i];
        if(FlGui::instance()->visibility->per_window->selected(i + 1)) ctx->show(m);
        else ctx->hide(m);
      }
      else if(i < GModel::list.size() + PView::list.size()){
        PView *v = PView::list[i - GModel::list.size()];
        if(FlGui::instance()->visibility->per_window->selected(i + 1)) ctx->show(v);
        else ctx->hide(v);
      }
    }
  }
  else if(what == "reset_all"){
    for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++){
      for(unsigned int j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++){
        drawContext *ctx = FlGui::instance()->graph[i]->gl[j]->getDrawContext();
        ctx->showAll();
      }
    }
    for(int i = 0; i < FlGui::instance()->visibility->per_window->size(); i++)
      FlGui::instance()->visibility->per_window->select(i + 1);
  }
  drawContext::global()->draw();
}

visibilityWindow::visibilityWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  static int cols[5] = {2 * WB, BB, BB, 2 * BB, 0};
  int width = cols[0] + cols[1] + cols[2] + cols[3] + 6 * WB;
  int height = 18 * BH;
  int brw = width - 4 * WB;

  win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "Visibility");
  win->box(GMSH_WINDOW_BOX);

  Fl_Tabs *o = new Fl_Tabs
    (WB, WB, width - 2 * WB, height - 3 * WB - BH);
  {
    Fl_Group *g = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "List browser");

    Fl_Button *o0 = new Fl_Button
      (2 * WB, 2 * WB + BH, cols[0], BH/2, "*");
    o0->align(FL_ALIGN_TOP | FL_ALIGN_INSIDE);
    o0->tooltip("Select/unselect all");
    o0->callback(visibility_sort_cb, (void *)"*");

    Fl_Button *o1 = new Fl_Button
      (2 * WB, 2 * WB + BH + BH/2, cols[0], BH - BH/2, "-");
    o1->tooltip("Invert selection");
    o1->callback(visibility_sort_cb, (void *)"-");

    Fl_Button *o2 = new Fl_Button
      (2 * WB + cols[0], 2 * WB + BH, cols[1], BH, "Type");
    o2->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o2->tooltip("Sort by type");
    o2->callback(visibility_sort_cb, (void *)"type");

    Fl_Button *o3 = new Fl_Button
      (2 * WB + cols[0] + cols[1], 2 * WB + BH, cols[2], BH, "Number");
    o3->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o3->tooltip("Sort by number");
    o3->callback(visibility_sort_cb, (void *)"number");

    Fl_Button *o4 = new Fl_Button
      (2 * WB + cols[0] + cols[1] + cols[2], 2 * WB + BH, cols[3], BH, "Name");
    o4->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    o4->tooltip("Sort by name");
    o4->callback(visibility_sort_cb, (void *)"name");

    Fl_Button *o5 = new Fl_Button
      (width - 4 * WB, 2 * WB + BH, 2 * WB, BH, "+");
    o5->tooltip("Add parameter name for first selected item");
    o5->callback(visibility_sort_cb, (void *)"+");

    {
      Fl_Group *gg = new Fl_Group
        (2 * WB, 2 * WB + 2 * BH, brw, height - 6 * WB - 4 * BH);
      
      browser = new listBrowser
        (2 * WB, 2 * WB + 2 * BH, brw, height - 6 * WB - 4 * BH);
      browser->type(FL_MULTI_BROWSER);
      browser->textsize(FL_NORMAL_SIZE - 1);
      browser->column_widths(cols);
      
      gg->end();
      Fl_Group::current()->resizable(gg);
    }

    static Fl_Menu_Item browser_type_table[] = {
      {"Models", 0, (Fl_Callback *) visibility_cb},
      {"Elementary entities", 0, (Fl_Callback *) visibility_cb},
      {"Physical groups", 0, (Fl_Callback *) visibility_cb},
      {"Mesh partitions", 0, (Fl_Callback *) visibility_cb},
      {0}
    };
    browser_type = new Fl_Choice
      (2 * WB, height - 2 * BH - 3 * WB, (width - 3 * WB) / 2, BH);
    browser_type->menu(browser_type_table);
    browser_type->value(1);

    push[0] = new Fl_Button
      (width - 2 * BB - 3 * WB, height - 2 * BH - 3 * WB, BB, BH, "Delete");
    push[0]->callback(visibility_delete_cb);

    Fl_Return_Button *b1 = new Fl_Return_Button
      (width - 1 * BB - 2 * WB, height - 2 * BH - 3 * WB, BB, BH, "Apply");
    b1->callback(visibility_browser_apply_cb);

    g->end();
    Fl_Group::current()->resizable(g);
  }
#if defined(HAVE_FL_TREE)
  {
    Fl_Group *g = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Tree browser");

    tree = new treeBrowser(2 * WB, 2 * WB + BH, brw, height - 6 * WB - 3 * BH);
    tree->labelsize(FL_NORMAL_SIZE - 1);
    tree->selectmode(FL_TREE_SELECT_MULTI);
    tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
    tree->hide();

    tree_create = new Fl_Button
      (2 * WB, 2 * WB + BH, brw, height - 6 * WB - 3 * BH,
       "The model contains more than ten thousand entities,\n"
       "which might slow down the tree browser.\n\n"
       "Create tree browser anyway?");
    tree_create->callback(build_tree_cb);

    Fl_Return_Button *b1 = new Fl_Return_Button
      (width - 1 * BB - 2 * WB, height - 2 * BH - 3 * WB, BB, BH, "Apply");
    b1->callback(visibility_tree_apply_cb);

    g->resizable(tree);
    g->end();
  }
#endif
  {
    Fl_Group *g = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Numeric");
    g->resizable(NULL);

    int yy = 2 * WB + BH;
    for(int i = 0; i < 10; i++){
      if(i == 0){
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Mesh:");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 2){
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Elementary entities:");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 6){
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Physical groups:");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      input[i] = new Fl_Input(width / 2 - WB / 2 - IW, yy, IW, BH);
      input[i]->align(FL_ALIGN_LEFT);
      input[i]->value("*");

      Fl_Button *o1 = new Fl_Button(width / 2 + WB / 2, yy, BB, BH, "Show");
      o1->callback(visibility_number_cb, (void *)(100+i));

      Fl_Button *o2 = new Fl_Button(width / 2 + WB / 2 + BB + WB, yy, BB, BH, "Hide");
      o2->callback(visibility_number_cb, (void *)i);
      yy += BH;
    }

    input[0]->label("Node");
    input[0]->tooltip("Enter node number, or *");

    input[1]->label("Element");
    input[1]->tooltip("Enter element number, or *");

    input[2]->label("Point");
    input[2]->tooltip("Enter point number, or *");

    input[3]->label("Line");
    input[3]->tooltip("Enter line number, or *");

    input[4]->label("Surface");
    input[4]->tooltip("Enter surface number, or *");

    input[5]->label("Volume");
    input[5]->tooltip("Enter volume number, or *");

    input[6]->label("Point");
    input[6]->tooltip("Enter point number, or *");

    input[7]->label("Line");
    input[7]->tooltip("Enter line number, or *");

    input[8]->label("Surface");
    input[8]->tooltip("Enter surface number, or *");

    input[9]->label("Volume");
    input[9]->tooltip("Enter volume number, or *");

    g->end();
  }
  {
    Fl_Group *g = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Interactive");
    g->resizable(NULL);

    Fl_Button* bb[20];
    int ll = width/2 - BH - WB - IW;
    int ll2 = ll + IW + WB + 2*BH + WB;
    int yy = 2 * WB + BH;
    for(int i = 0; i < 9; i++){
      if(i == 0){
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Mesh:");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 1){
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Elementary entities:");
        b->labelfont(FL_BOLD);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        yy += BH;
      }
      else if(i == 5){
        Fl_Box *b = new Fl_Box(2 * WB, yy, IW, BH, "Physical groups:");
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
    bb[4]->label("Hide lines");
    bb[4]->callback(visibility_interactive_cb, (void *)"lines to hide");
    bb[5]->label("Show lines");
    bb[5]->callback(visibility_interactive_cb, (void *)"lines to show");
    bb[6]->label("Hide surfaces");
    bb[6]->callback(visibility_interactive_cb, (void *)"surfaces to hide");
    bb[7]->label("Show surfaces");
    bb[7]->callback(visibility_interactive_cb, (void *)"surfaces to show");
    bb[8]->label("Hide volumes");
    bb[8]->callback(visibility_interactive_cb, (void *)"volumes to hide");
    bb[9]->label("Show volumes");
    bb[9]->callback(visibility_interactive_cb, (void *)"volumes to show");
    bb[10]->label("Hide points");
    bb[10]->callback(visibility_interactive_cb, (void *)"physical points to hide");
    bb[11]->label("Show points");
    bb[11]->callback(visibility_interactive_cb, (void *)"physical points to show");
    bb[12]->label("Hide lines");
    bb[12]->callback(visibility_interactive_cb, (void *)"physical lines to hide");
    bb[13]->label("Show lines");
    bb[13]->callback(visibility_interactive_cb, (void *)"physical lines to show");
    bb[14]->label("Hide surfaces");
    bb[14]->callback(visibility_interactive_cb, (void *)"physical surfaces to hide");
    bb[15]->label("Show surfaces");
    bb[15]->callback(visibility_interactive_cb, (void *)"physical surfaces to show");
    bb[16]->label("Hide volumes");
    bb[16]->callback(visibility_interactive_cb, (void *)"physical volumes to hide");
    bb[17]->label("Show volumes");
    bb[17]->callback(visibility_interactive_cb, (void *)"physical volumes to show");

    bb[18] = new Fl_Button
      (ll + IW + WB, 2 * WB + 2 * BH, 2 * BH, 11 * BH, "Show\nAll");
    bb[18]->callback(visibility_interactive_cb, (void *)"show all");
    
    g->end();
  }
  {
    Fl_Group *g = new Fl_Group
      (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Per window");
    g->resizable(NULL);

    per_window = new Fl_Multi_Browser
      (2 * WB, 2 * WB + BH, brw, height - 6 * WB - 3 * BH);
    per_window->callback(visibility_per_window_cb, (void*)"item");

    Fl_Button *b1 = new Fl_Button
      (width - 1 * BB - 2 * WB, height - 2 * BH - 3 * WB, BB, BH, "Reset all");
    b1->callback(visibility_per_window_cb, (void*)"reset_all");
 
    g->resizable(per_window);
    g->end();
  }
  o->end();

  win->resizable(o);
  win->size_range(width, 15 * BH + 5 * WB, width);

  {
    int ww = (width - 3 * WB) / 2;
    butt[0] = new Fl_Check_Button
      (WB, height - BH - WB, ww, BH, "Set visibility recursively");
    butt[0]->type(FL_TOGGLE_BUTTON);
    butt[0]->value(1);

    Fl_Button *o1 = new Fl_Button
      (width - ww - WB, height - BH - WB, ww, BH, "Save current visibility");
    o1->callback(visibility_save_cb);
  }

  win->position(CTX::instance()->visPosition[0], CTX::instance()->visPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void visibilityWindow::show(bool redrawOnly)
{
  if(win->shown() && redrawOnly)
    win->redraw();
  else
    win->show();
}

void visibilityWindow::updatePerWindow(bool force)
{
  static openglWindow *gl = 0;
  if(!force && gl == FlGui::instance()->getCurrentOpenglWindow()) return;

  gl = FlGui::instance()->getCurrentOpenglWindow();
  drawContext *ctx = gl->getDrawContext();
 
  per_window->clear();
  int line = 1;

  for(unsigned int i = 0; i < GModel::list.size(); i++){
    GModel *m = GModel::list[i];
    std::ostringstream sstream;
    sstream << "Model [" << i << "] <<" << m->getName() << ">>";
    per_window->add(sstream.str().c_str());
    if(ctx->isVisible(m))
      per_window->select(line, 1);
    line++;
  }

  for(unsigned int i = 0; i < PView::list.size(); i++){
    PView *v = PView::list[i];
    std::ostringstream sstream;
    sstream << "View [" << i << "] <<" << v->getData()->getName() << ">>";
    per_window->add(sstream.str().c_str());
    if(ctx->isVisible(v))
      per_window->select(line, 1);
    line++;
  }
}
