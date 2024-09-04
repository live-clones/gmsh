// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PVIEW_FACTORY_H
#define PVIEW_FACTORY_H

// quick hack to have something that we can bind for the summer
// school...  this class has probably to be removed or rewritten

#include <map>
#include <vector>
#include <string>

class GModel;
class PView;
template <class t> class fullMatrix;

class PViewFactory {
  std::map<int, std::vector<double> > _values;
  std::string _name, _type;
  int _dim, _timeStep;
  GModel *_model;

public:
  PViewFactory(std::string name, std::string type, GModel *model, int timeStep,
               int dim = 3);
  void setEntry(int id, const fullMatrix<double> &val);
  PView *createView();
};

#endif
