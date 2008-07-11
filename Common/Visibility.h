// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _VISIBILITY_H_
#define _VISIBILITY_H_

#include <string>
#include <map>
#include <vector>
#include "GmshDefines.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

class Vis {
 public:
  Vis(){}
  virtual ~Vis(){}
  virtual int getTag() const = 0;
  virtual int getDim() const = 0;
  virtual std::string getName() const = 0;
  virtual char getVisibility() const = 0;
  virtual void setVisibility(char val, bool recursive=false) = 0;
};

class VisElementary : public Vis {
 private:
  GEntity *_e;
  int _dim;
 public:
  VisElementary(GVertex *e) : _e(e), _dim(0) {}
  VisElementary(GEdge *e) : _e(e), _dim(1) {}
  VisElementary(GFace *e) : _e(e), _dim(2) {}
  VisElementary(GRegion *e) : _e(e), _dim(3) {}
  ~VisElementary(){}
  int getTag() const { return _e->tag(); }
  int getDim() const { return _dim; }
  std::string getName() const
  {
    if(_dim == 0) return "Point";
    else if(_dim == 1) return "Line";
    else if(_dim == 2) return "Surface";
    else return "Volume";
  }
  char getVisibility() const { return _e->getVisibility(); }
  void setVisibility(char val, bool recursive=false);
};

class VisPhysical : public Vis {
 private:
  int _tag, _dim;
  char _visible;
  std::vector<GEntity*> _list;
 public:
  VisPhysical(int tag, int dim, std::vector<GEntity*> list) 
    : _tag(tag), _dim(dim), _visible(true), _list(list)  {}
  ~VisPhysical(){}
  int getTag() const { return _tag; }
  int getDim() const { return _dim; }
  std::string getName() const
  {
    if(_dim == 0) return "Point";
    else if(_dim == 1) return "Line";
    else if(_dim == 2) return "Surface";
    else return "Volume";
  }
  char getVisibility() const { return _visible; }
  void setVisibility(char val, bool recursive=false);
};

class VisPartition : public Vis {
 private:
  int _tag;
  char _visible;
 public:
  VisPartition(int tag) : _tag(tag), _visible(true) {}
  ~VisPartition(){}
  int getTag() const { return _tag; }
  int getDim() const { return -1; }
  std::string getName() const { return "Partition"; }
  char getVisibility() const { return _visible; }
  void setVisibility(char val, bool recursive=false);
};

// Singleton, one visibility manager for the whole interface
class VisibilityManager {
 private:
  std::map<int, std::pair<std::string, int> > _labels;
  std::vector<Vis*> _entities;
  int _sortMode;
  static VisibilityManager *manager;
  VisibilityManager() : _sortMode(-1) {}

 public :
  // create the only instance of the manager
  static VisibilityManager *instance()
  {
    if(!manager) manager = new VisibilityManager();
    return manager;
  }
  
  // repopulate the manager with current data of the given type
  void update(int type);

  // get the number of entities in the manager
  int getNumEntities() { return _entities.size(); }

  // get the number of entities in the manager
  Vis *getEntity(int i) { return _entities[i]; }

  // get the visibility information for the nth entity in the manager
  char getVisibility(int n){ return _entities[n]->getVisibility(); }

  // set the visibility information for the nth entity in the manager
  void setVisibility(int n, char val, bool recursive=false)
  { 
    _entities[n]->setVisibility(val, recursive);
  }

  // set all entities to be invisible
  void setAllInvisible(int type);

  // set the visibility of one or all entites of a given type (0=node,
  // 1=element, 2=point, 3=line, 4=surface, 5=volume, 6=physical
  // point, 7=physical line, 8=physical surface, 9=physical volume)
  void setVisibilityByNumber(int type, int num, char val, bool recursive=false);

  // get the tag of the nth entity in the manager
  int getTag(int n){ return _entities[n]->getTag(); }

  // get the browser line for the nth entity in the manager
  std::string getBrowserLine(int n);

  // get the whole visibility information in geo format
  std::string getStringForGEO();

  // set the sort mode
  void setSortMode(int mode){ _sortMode = (_sortMode != mode) ? mode : -mode; }

  // get the sort mode
  int getSortMode(){ return _sortMode; }

  // associate a label with a tag (quality=0 for "old-style" unreliable labels)
  void setLabel(int tag, std::string label, int quality=1)
  { 
    _labels[tag] = std::make_pair(label, quality); 
  }

  // get the label associated with a tag
  std::string getLabel(int tag){ return _labels[tag].first; }
};

#endif
