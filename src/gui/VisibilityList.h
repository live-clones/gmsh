// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VISIBILITY_LIST_H
#define VISIBILITY_LIST_H

// the entities the visibility panel shows, with their visibility state

#include "GmshConfig.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <regex>
#include <algorithm>

#include "GmshDefines.h"
#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "Context.h"
#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "partitionRegion.h"
#include "OverlapEntities.h"
#include <string.h>

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
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

// the partitions of an entity without copying the vector (an overlap entity
// stores a single partition, hence the scratch argument)
inline const std::vector<int> *partitionsOf(GEntity *ge, std::vector<int> &tmp)
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

// which entities belong to which partition, built once when the list is
// filled: without it applying a selection walks the model once per partition
class PartitionIndex {
public:
  static std::map<int, std::vector<GEntity *> > &of()
  {
    static std::map<int, std::vector<GEntity *> > index;
    return index;
  }
  static GModel *&model()
  {
    static GModel *m = nullptr;
    return m;
  }
  static void build(GModel *m)
  {
    of().clear();
    model() = m;
    std::vector<GEntity *> entities;
    m->getEntities(entities);
    std::vector<int> tmp;
    for(std::size_t i = 0; i < entities.size(); i++) {
      const std::vector<int> *ps = partitionsOf(entities[i], tmp);
      if(!ps) continue;
      for(std::size_t j = 0; j < ps->size(); j++)
        of()[(*ps)[j]].push_back(entities[i]);
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
  // only mark the partition in the list, without touching the entities
  void setListVisibility(char val) { _visible = val; }
  void setVisibility(char val, bool recursive = false, bool allmodels = false)
  {
    _visible = val;
    for(std::size_t i = 0; i < GModel::list.size(); i++) {
      GModel *m = GModel::list[i];
      if(!allmodels && m != GModel::current()) continue;
      if(m == PartitionIndex::model()) { // the entities are already known
        auto it = PartitionIndex::of().find(_tag);
        if(it != PartitionIndex::of().end())
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
      PartitionIndex::build(m);
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
  int getNumEntities() { return _entities.size(); }
  Vis *getEntity(int i) { return _entities[i]; }
  char getVisibility(int n) { return _entities[n]->getVisibility(); }
  void setVisibility(int n, char val, bool recursive = false,
                     bool allmodels = false)
  {
    _entities[n]->setVisibility(val, recursive, allmodels);
  }
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
        if(m == PartitionIndex::model()) {
          for(auto &p : PartitionIndex::of())
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
  int getDim(int n) { return _entities[n]->getDim(); }
  int getTag(int n) { return _entities[n]->getTag(); }
  std::string getBrowserLine(int n) { return _entities[n]->getBrowserLine(); }
  void setSortMode(int mode) { _sortMode = (_sortMode != mode) ? mode : -mode; }
  int getSortMode() { return _sortMode; }
};

#endif
