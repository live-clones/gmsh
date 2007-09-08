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
#include "PViewData.h"
#include "PViewOptions.h"

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
  // reference counter (how many views link to this one)
  int _links;
  // eye position (for transparency sorting)
  SPoint3 _eye;
  // the options
  PViewOptions *_options;
  // the data
  PViewData *_data;
 public:
  // default constructor
  PView(bool allocate=true);
  // alias constructor
  PView(PView *ref, bool copyOptions=true);
  // default destructor
  ~PView();
  PViewOptions *getOptions(){ return _options; }  
  PViewData *getData(){ return _data; }
  int getNum(){ return _num; }
  int getIndex(){ return _index; }
  void setIndex(int val){ _index = val; }
  bool getChanged(){ return _changed; }
  void setChanged(bool val);
  int &getLinks(){ return _links; }
  int getAliasOf(){ return _aliasOf; }
  SPoint3 &getEye(){ return _eye; }
  void setEye(SPoint3 &p){ _eye = p; }

  // the static list of all loaded views
  static std::vector<PView*> list;
  // the current view
  static PView *current();
  // read view(s) in list format from a file
  static bool read(std::string filename, int fileIndex=-1);
  // combine view
  static void combine(bool time, int how, bool remove);

  // vertex arrays to draw triangles and lines efficiently
  VertexArray *va_points, *va_lines, *va_triangles, *va_vectors;
  // smoothed normals
  smooth_normals *normals;
};

#endif
