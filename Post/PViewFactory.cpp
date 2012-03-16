// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "PViewFactory.h"
#include "GModel.h"
#include "fullMatrix.h"
#include "PView.h"
#include <vector>

PViewFactory::PViewFactory (std::string name, std::string type, GModel *model,
                            int timeStep, int dim)
  : _name(name), _type(type), _dim(dim), _timeStep(timeStep), _model(model)
{
}

void PViewFactory::setEntry (int id, const fullMatrix<double> &val)
{
  std::vector<double> &vv = _values[id];
  vv.resize(val.size1()*val.size2());
  int k=0;
  for (int i=0;i<val.size1(); i++) {
    for (int j=0;j<val.size2(); j++) {
      vv[k++] = val(i,j);
    }
  }
}

PView *PViewFactory::createView ()
{
  return new PView(_name,_type,_model,_values,_timeStep,_dim);
}

