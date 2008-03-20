// $Id: PView.cpp,v 1.25 2008-03-20 11:44:15 geuzaine Exp $
//
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
//
// Contributor(s):
// 

#include <string.h>
#include <algorithm>
#include "PView.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "StringUtils.h"
#include "Message.h"

int PView::_globalNum = 0;
std::vector<PView*> PView::list;

void PView::_init()
{
  _num = ++_globalNum;
  _changed = true;
  _aliasOf = 0;
  _eye = SPoint3(0., 0., 0.);
  va_points = va_lines = va_triangles = va_vectors = 0;
  normals = 0;
  list.push_back(this);
  for(unsigned int i = 0; i < list.size(); i++) list[i]->setIndex(i);
}

PView::PView(bool allocate)
{
  _init();
  _data = new PViewDataList(allocate);
  _options = new PViewOptions(PViewOptions::reference);
}

PView::PView(PViewData *data)
{
  _init();
  _data = data;
  _options = new PViewOptions(PViewOptions::reference);
}

PView::PView(PView *ref, bool copyOptions)
{
  _init();
  _aliasOf = ref->getNum();
  _data = ref->getData();
  if(copyOptions)
    _options = new PViewOptions(*ref->getOptions());
  else
    _options = new PViewOptions(PViewOptions::reference);
}

PView::PView(std::string xname, std::string yname,
             std::vector<double> &x, std::vector<double> &y)
{
  _init();
  PViewDataList *data = new PViewDataList(true);
  _data = data;
  for(unsigned int i = 0; i < y.size(); i++){
    double d;
    if(x.size() == y.size()){
      List_Add(data->SP, &x[i]);
    }
    else{
      d = y.size() > 1 ? (double)i / (double)(y.size() - 1) : 0.;
      List_Add(data->SP, &d);
    }
    d = 0.;
    List_Add(data->SP, &d);
    List_Add(data->SP, &d);
    List_Add(data->SP, &y[i]);
    data->NbSP++;
  }
  data->setName(yname);
  data->setFileName(yname + ".pos");
  data->finalize();

  _options = new PViewOptions(PViewOptions::reference);
  _options->Type = PViewOptions::Plot2DSpace;
  _options->Axes = 2;
  strcpy(_options->AxesLabel[0], xname.c_str());
}

PView::~PView()
{
  deleteVertexArrays();
  if(normals) delete normals;
  if(_options) delete _options;

  std::vector<PView*>::iterator it = std::find(list.begin(), list.end(), this);
  if(it != list.end()) list.erase(it);
  for(unsigned int i = 0; i < list.size(); i++) list[i]->setIndex(i);

  if(!_data) return;

  // do not delete if another view is an alias of this one
  for(unsigned int i = 0; i < list.size(); i++)
    if(list[i]->getAliasOf() == _num)
      return;
  
  // do not delete if this view is an alias and 1) if the original
  // still exists, or 2) if there are other aliases to the same view
  if(_aliasOf)
    for(unsigned int i = 0; i < list.size(); i++)
      if(list[i]->getNum() == _aliasOf || list[i]->getAliasOf() == _aliasOf)
        return;
  
  Msg(DEBUG, "Deleting data in View[%d] (unique num = %d)", _index, _num);
  delete _data;
}

void PView::deleteVertexArrays()
{
  if(va_points) delete va_points; va_points = 0;
  if(va_lines) delete va_lines; va_lines = 0;
  if(va_triangles) delete va_triangles; va_triangles = 0;
  if(va_vectors) delete va_vectors; va_vectors = 0;
}

void PView::setOptions(PViewOptions *val)
{
  if(val)
    _options = val;
  else if(_options) // deep copy options from reference view
    *_options = PViewOptions::reference;
}

void PView::setChanged(bool val)
{ 
  _changed = val; 
  // reset the eye position everytime we change the view so that the
  // arrays get resorted for transparency
  if(_changed) _eye = SPoint3(0., 0., 0.); 
}

void PView::combine(bool time, int how, bool remove)
{
  // time == true: combine the timesteps (oherwise combine the elements)
  // how == 0: try to combine all visible views
  //        1: try to combine all views
  //        2: try to combine all views having identical names

  std::vector<nameData> nds;
  for(unsigned int i = 0; i < list.size(); i++) {
    PView *p = list[i];
    PViewData *data = p->getData();
    if(how || p->getOptions()->Visible) {
      nameData nd;
      // this will lead to weird results if there are views named
      // "__all__" or "__vis__" :-)
      if(how == 2)
        nd.name = data->getName();
      else if(how == 1)
        nd.name = "__all__";
      else
        nd.name = "__vis__";
      unsigned int j = 0;
      while(j < nds.size()){
        if(nds[j].name == nd.name){
          nds[j].data.push_back(data);
          nds[j].indices.push_back(i);
          break;
        }
        j++;
      }
      if(j == nds.size()){
        nd.data.push_back(data);
        nd.indices.push_back(i);
        nds.push_back(nd);
      }
    }
  }

  std::set<PView*> rm;
  for(unsigned int i = 0; i < nds.size(); i++){
    if(nds[i].data.size() > 1){
      // there's potentially something to combine
      PView *p = new PView(true);
      PViewData *data = p->getData();
      bool res = time ? data->combineTime(nds[i]): data->combineSpace(nds[i]);
      if(res)
        for(unsigned int j = 0; j < nds[i].indices.size(); j++)
          rm.insert(list[nds[i].indices[j]]);
      else
        delete p;
    }
  }
  if(remove)
    for(std::set<PView*>::iterator it = rm.begin(); it != rm.end(); it++)
      delete *it;
}

PView *PView::getViewByName(std::string name, int timeStep, int partition)
{
  for(unsigned int i = 0; i < list.size(); i++){
    if(list[i]->getData()->getName() == name &&
       ((timeStep < 0 || !list[i]->getData()->hasTimeStep(timeStep)) ||
        (partition < 0 || !list[i]->getData()->hasPartition(partition))))
      return list[i];
  }
  return 0;
}

bool PView::readPOS(std::string fileName, int fileIndex)
{
  FILE *fp = fopen(fileName.c_str(), "rb");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
    return false;
  }

  char str[256] = "XXX";
  double version;
  int format, size, index = -1;

  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } 
    
    if(feof(fp))
      break;

    if(!strncmp(&str[1], "PostFormat", 10)) {

      if(!fscanf(fp, "%lf %d %d\n", &version, &format, &size)){
        Msg(GERROR, "Read error");
        return false;
      }
      if(version < 1.0) {
        Msg(GERROR, "Post-processing file too old (ver. %g < 1.0)", version);
        return false;
      }
      if(size == sizeof(double))
        Msg(DEBUG, "Data is in double precision format (size==%d)", size);
      else {
        Msg(GERROR, "Unknown data size (%d) in post-processing file", size);
        return false;
      }
      if(format == 0)
        format = LIST_FORMAT_ASCII;
      else if(format == 1)
        format = LIST_FORMAT_BINARY;
      else {
        Msg(GERROR, "Unknown format for view");
        return false;
      }

    }
    else if(!strncmp(&str[1], "View", 4)){

      index++;
      if(fileIndex < 0 || fileIndex == index){
        PViewDataList *d = new PViewDataList(false);
        if(!d->readPOS(fp, version, format, size)){
          Msg(GERROR, "Could not read data in list format");
          delete d;
          return false;
        }
        else{
          d->setFileName(fileName);
          d->setFileIndex(index);
          new PView(d);
        }
      }

    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } while(str[0] != '$');

  }

  fclose(fp);

  return true;
}

bool PView::readMSH(std::string fileName, int fileIndex)
{
  FILE *fp = fopen(fileName.c_str(), "rb");
  if(!fp){
    Msg(GERROR, "Unable to open file '%s'", fileName.c_str());
    return false;
  }

  char str[256] = "XXX";
  int index = -1;
  bool binary = false, swap = false;

  while(1) {

    while(str[0] != '$'){
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    }
    
    if(feof(fp))
      break;

    if(!strncmp(&str[1], "MeshFormat", 10)) {
      double version;
      if(!fgets(str, sizeof(str), fp)) return false;
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) return false;
      if(format){
        binary = true;
        Msg(INFO, "Mesh is in binary format");
        int one;
        if(fread(&one, sizeof(int), 1, fp) != 1) return 0;
        if(one != 1){
          swap = true;
          Msg(INFO, "Swapping bytes from binary file");
        }
      }
    }
    else if(!strncmp(&str[1], "NodeData", 8)) {
      index++;
      if(fileIndex < 0 || fileIndex == index){
        // read data info
        if(!fgets(str, sizeof(str), fp)) return false;
        std::string name = extractDoubleQuotedString(str, sizeof(str));
        int timeStep, partition, interpolationScheme, numComp, numNodes;
        double time;
        if(!fgets(str, sizeof(str), fp)) return false;
        if(sscanf(str, "%d %lf %d %d %d %d", &timeStep, &time, &partition,
                  &interpolationScheme, &numComp, &numNodes) != 6) return false;
        // either get existing viewData, or create new one
        PView *p = getViewByName(name, timeStep, partition);
        PViewDataGModel *d = 0;
        if(p) d = dynamic_cast<PViewDataGModel*>(p->getData());
        bool create = d ? false : true;
        if(create) d = new PViewDataGModel();
        if(!d->readMSH(fileName, fileIndex, fp, binary, swap, timeStep, 
                       time, partition, numComp, numNodes)){
          Msg(GERROR, "Could not read data in msh file");
          if(create) delete d;
          return false;
        }
        else{
          d->setName(name);
          d->setFileName(fileName);
          d->setFileIndex(index);
          if(create) new PView(d);
        }
      }
    }
    
    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp))
        break;
    } while(str[0] != '$');
  }

  fclose(fp);
  return true;
}

bool PView::write(std::string fileName, int format, bool append)
{
  Msg(STATUS2, "Writing '%s'", fileName.c_str());

  bool ret;
  switch(format){
  case 0: ret = _data->writePOS(fileName, false, false, append); break; // ASCII
  case 1: ret = _data->writePOS(fileName, true, false, append); break; // binary
  case 2: ret = _data->writePOS(fileName, false, true, append); break; // parsed
  case 3: ret = _data->writeSTL(fileName); break;
  case 4: ret = _data->writeTXT(fileName); break;
  case 5: ret = _data->writeMSH(fileName); break;
  default: ret = false; Msg(GERROR, "Unknown view format %d", format); break;
  }

  Msg(STATUS2, "Wrote '%s'", fileName.c_str());
  return ret;
}
