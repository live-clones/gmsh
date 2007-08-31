#ifndef _PVIEW_H_
#define _PVIEW_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include <vector>
#include <string>
#include "VertexArray.h"
#include "SmoothData.h"
#include "AdaptiveViews.h"
#include "PViewData.h"
#include "PViewOptions.h"

// a post-processing view
class PView{
 private:
  // unique tag of the view
  int _num;
  // index of the view in the current view list
  int _index;
  // flag to mark that the view has changed
  bool _changed;
  // flag to mark that the view is an alias of another view
  int _aliasOf;
  // flag to mark that some other views link to this one
  bool _links;
  // name of the view
  std::string _name;
  // name of the file the view was loaded from
  std::string _filename;
  // eye position
  SPoint3 _eye;
  // the options
  PViewOptions *_options;
  // the data
  PViewData *_data;
 public:
  PView(bool allocate=true) :
    _num(0), _index(0), _changed(true), _aliasOf(-1), 
    _links(false), _name(""), _filename(""), _eye(0., 0., 0.),
    _options(0), _data(0), va_points(0), va_lines(0), va_triangles(0),
    va_vectors(0), normals(0), adaptive(0)
  {
    _data = new PViewDataList(allocate);
    _options = new PViewOptions;
    list.push_back(this);
    // reset indices
    for(unsigned int i = 0; i < list.size(); i++) list[i]->setIndex(i);
  }
  ~PView()
  {
    if(_options) delete _options;
    if(_data) delete _data;
    if(va_points) delete va_points;
    if(va_lines) delete va_lines;
    if(va_triangles) delete va_triangles;
    if(va_vectors) delete va_vectors;
    if(normals) delete normals;
    if(adaptive) delete adaptive;
  }
  // the static list of all loaded views
  static std::vector<PView*> list;
  // the current view
  static PView *current();
  PViewOptions *getOptions(){ return _options; }  
  PViewData *getData(){ return _data; }
  std::string getName(){ return _name; }
  void setName(std::string val){ _name = val; }
  int getIndex(){ return _index; }
  void setIndex(int val){ _index = val; }
  bool getChanged(){ return _changed; }
  void setChanged(bool val);
  SPoint3 &getEye(){ return _eye; }
  void setEye(SPoint3 &p){ _eye = p; }
  void setGlobalResolutionLevel(int level)
  {
    //if(adaptive) adaptive->setGlobalResolutionLevel(this, level);
  }
  void setAdaptiveResolutionLevel(int level, GMSH_Post_Plugin *plugin = 0)
  {
    //if(adaptive) adaptive->setAdaptiveResolutionLevel(this, level, plugin);
  }

  // vertex arrays to draw triangles and lines efficiently
  VertexArray *va_points, *va_lines, *va_triangles, *va_vectors;
  // smoothed normals
  smooth_normals *normals;
  // adaptative rendering for high-order datasets
  Adaptive_Post_View *adaptive;

};

#endif
