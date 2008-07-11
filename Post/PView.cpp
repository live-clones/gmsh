// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
// 

#include <string.h>
#include <algorithm>
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "PViewDataList.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "adaptiveData.h"
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
  
  Msg::Debug("Deleting data in View[%d] (unique num = %d)", _index, _num);
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

PViewData *PView::getData(bool useAdaptiveIfAvailable)
{ 
  if(useAdaptiveIfAvailable && _data->isAdaptive()) 
    return _data->getAdaptiveData()->getData();
  return _data;
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

