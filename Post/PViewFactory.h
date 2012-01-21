// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PVIEW_FACTORY_H_
#define _PVIEW_FACTORY_H_

// quick hack to have something that we can bind for the summer
// school...  this class has probably to be removed or rewritten

#include<map>
#include<vector>
#include<string>

class GModel;
class PView;
template <class t> class fullMatrix;

class PViewFactory {
  std::map<int,std::vector<double> > _values;
  std::string _name, _type;
  int _dim,_timeStep;
  GModel *_model;
  public:
  PViewFactory(std::string name, std::string type, GModel *model, int timeStep, int dim=3);
  void setEntry(int id, const fullMatrix<double> &val);
  PView *createView();
};

#endif
