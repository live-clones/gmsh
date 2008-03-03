#ifndef _PVIEW_H_
#define _PVIEW_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
#include "PViewData.h"
#include "PViewOptions.h"

class VertexArray;
class smooth_normals;

// a post-processing view
class PView{
 private:
  static int _globalNum;
  // unique tag of the view (> 0)
  int _num;
  // index of the view in the current view list
  int _index;
  // flag to mark that the view has changed
  bool _changed;
  // tag of the source view if this view is an alias, zero otherwise
  int _aliasOf;
  // eye position (for transparency sorting)
  SPoint3 _eye;
  // the options
  PViewOptions *_options;
  // the data
  PViewData *_data;
  // initialize private stuff
  void _init();
 public:
  // creates a new view with list-based data, allocated or not
  PView(bool allocate=true);
  // constructs a new view using the given data
  PView(PViewData *data);
  // constructs a new view, alias of the view "ref"
  PView(PView *ref, bool copyOptions=true);
  // constructs a new list-based view from a simple 2D dataset
  PView(std::string xname, std::string yname,
	std::vector<double> &x, std::vector<double> &y);
  // default destructor
  ~PView();
  void deleteVertexArrays();
  PViewOptions *getOptions(){ return _options; }  
  void setOptions(PViewOptions *val=0);  
  PViewData *getData(){ return _data; }
  void setData(PViewData *val){ _data = val; }
  int getNum(){ return _num; }
  int getIndex(){ return _index; }
  void setIndex(int val){ _index = val; }
  bool &getChanged(){ return _changed; }
  void setChanged(bool val);
  int getAliasOf(){ return _aliasOf; }
  SPoint3 &getEye(){ return _eye; }
  void setEye(SPoint3 &p){ _eye = p; }

  // the static list of all loaded views
  static std::vector<PView*> list;

  // combine view
  static void combine(bool time, int how, bool remove);

  // combine view
  static PView *getViewByName(std::string name);

  // read view(s) in list format from a file
  static bool readPOS(std::string filename, int fileIndex=-1);
  // read view data from MSH file
  static bool readMSH(std::string filename, int fileIndex=-1);

  // write view to file in given format
  bool write(std::string filename, int format, bool append=false);

  // vertex arrays to draw the elements efficiently
  VertexArray *va_points, *va_lines, *va_triangles, *va_vectors;

  // smoothed normals
  smooth_normals *normals;
};

#endif
