// $Id: PView.cpp,v 1.6 2007-09-03 06:21:08 geuzaine Exp $
//
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
//
// Contributor(s):
// 

#include "PView.h"
#include "PViewDataList.h"
#include "Message.h"

int PView::_globalNum = 0;
std::vector<PView*> PView::list;

PView::PView(bool allocate)
  : _changed(true), _aliasOf(0), _links(0), _eye(0., 0., 0.), 
    va_points(0), va_lines(0), va_triangles(0), va_vectors(0), 
    normals(0), adaptive(0)
{
  _num = ++_globalNum;
  _data = new PViewDataList(allocate);
  _options = new PViewOptions();
  list.push_back(this);
  // reset indices of all views
  for(unsigned int i = 0; i < list.size(); i++) list[i]->setIndex(i);
}

PView::PView(PView *ref, bool copyOptions)
  : _changed(true), _links(0), _eye(0., 0., 0.), 
    va_points(0), va_lines(0), va_triangles(0), va_vectors(0), 
    normals(0), adaptive(0)
{
  _num = ++_globalNum;
  _aliasOf = ref->getNum();
  ref->getLinks()++;
  _data = ref->getData();
  if(copyOptions)
    _options = new PViewOptions(*ref->getOptions());
  else
    _options = new PViewOptions();
  list.push_back(this);
  // reset indices of all views
  for(unsigned int i = 0; i < list.size(); i++) list[i]->setIndex(i);
}

PView::~PView()
{
  if(va_points) delete va_points;
  if(va_lines) delete va_lines;
  if(va_triangles) delete va_triangles;
  if(va_vectors) delete va_vectors;
  if(normals) delete normals;
  if(adaptive) delete adaptive;

  if(_options) delete _options;

  std::vector<PView*>::iterator it = std::find(list.begin(), list.end(), this);
  if(it != list.end()) list.erase(it);
  for(unsigned int i = 0; i < list.size(); i++) list[i]->setIndex(i);

  if(!_data || _links > 0) return;

  if(_aliasOf){
    for(unsigned int i = 0; i < list.size(); i++){
      if(list[i]->getNum() == _aliasOf){
	// original data still exists, decrement ref counter
	list[i]->getLinks()--;
	return;
      }
    }
    for(unsigned int i = 0; i < list.size(); i++){
      if(list[i]->getAliasOf() == _aliasOf){
	// original is gone, but other aliases exist
	return;
      }
    }
  }

  Msg(DEBUG, "Deleting data in ex-View[%d] (unique num = %d)", _index, _num);
  delete _data;
}

void PView::setChanged(bool val)
{ 
  _changed = val; 
  // reset the eye position everytime we change the view so that the
  // arrays get resorted for transparency
  if(_changed) _eye = SPoint3(0., 0., 0.); 
}

PView *PView::current()
{ 
  if(list.empty()){
    Msg(GERROR, "No view available");
    return 0;
  }
  // return the last one for now
  return list.back();
}
