#ifndef _VISIBILITY_H_
#define _VISIBILITY_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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
  std::map<int, std::string> _labels;
  std::vector<Vis*> _entities;
  int _sortMode;
  static VisibilityManager *manager;
  VisibilityManager() : _sortMode(1) {}

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

  // get the visibility information for the nth entity in the manager
  char getVisibility(int n){ return _entities[n]->getVisibility(); }

  // set the visibility information for the nth entity in the manager
  void setVisibility(char n, int val, bool recursive=false)
  { 
    _entities[n]->setVisibility(val, recursive);
  }

  // set all entities to be invisible
  void setAllInvisible(int type);

  // get the tag of the nth entity in the manager
  int getTag(int n){ return _entities[n]->getTag(); }

  // get the browser line for the nth entity in the manager
  std::string getBrowserLine(int n);

  // set the sort mode
  void setSortMode(int mode){ _sortMode = (_sortMode != mode) ? mode : -mode; }

  // get the sort mode
  int getSortMode(){ return _sortMode; }

  // associate a label with a tag
  void setLabel(int tag, std::string label){ _labels[tag] = label; }

  // get the label associated with a tag
  std::string getLabel(int tag){ return _labels[tag]; }
};

#endif
