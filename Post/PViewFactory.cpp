#include "PViewFactory.h"
#include "GModel.h"
#include "fullMatrix.h"
#include "PView.h"
#include <vector>
#include "Bindings.h"

PViewFactory::PViewFactory (std::string name, std::string type, GModel *model, int timeStep, int dim):_model(model),_name(name),_type(type),_timeStep(timeStep), _dim(dim)
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

void PViewFactory::registerBindings (class binding *b)
{
  classBinding *cb = b->addClass<PViewFactory>("PViewFactory");
  cb->setDescription("A class to format the input data of post-procession views");
  methodBinding *mb = cb->addMethod("setEntry", &PViewFactory::setEntry);
  mb->setDescription("attach  data (values) on the ith nodes or elemnent");
  mb->setArgNames("i", "values", NULL);
  mb = cb->setConstructor<PViewFactory, std::string, std::string, GModel*,int,int>();
  mb->setDescription("create a new factory for post-processing view based on a GModel. The type can be 'NodeData', 'ElementData' or 'ElementNodeData'");
  mb->setArgNames("name", "type", "model","timeStep", "dimension", NULL);
  mb = cb->addMethod("createView",&PViewFactory::createView);
  mb->setDescription("create a post-processing view with the current data");
}
