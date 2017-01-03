// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "mathEvaluator.h"

#if defined(HAVE_MATHEX)

mathEvaluator::mathEvaluator(std::vector<std::string> &expressions,
                             std::vector<std::string> &variables)
{
  _expressions.resize(expressions.size());
  _variables.resize(variables.size(), 0.);
  bool error = false;
  for(unsigned int i = 0; i < expressions.size(); i++){
    _expressions[i] = new smlib::mathex();
    for(unsigned int j = 0; j < variables.size(); j++)
      _expressions[i]->addvar(variables[j], &_variables[j]);
    try {
      _expressions[i]->expression(expressions[i]);
      _expressions[i]->parse();
    }
    catch(smlib::mathex::error e) {
      Msg::Error(e.what());
      std::string pos(_expressions[i]->stopposition(), ' ');
      pos.push_back('^');
      Msg::Error(expressions[i].c_str());
      Msg::Error(pos.c_str());
      error = true;
    }
  }
  if(error){
    for(unsigned int i = 0; i < _expressions.size(); i++)
      delete(_expressions[i]);
    _expressions.clear();
  }
}

mathEvaluator::~mathEvaluator()
{
  for(unsigned int i = 0; i < _expressions.size(); i++)
    delete(_expressions[i]);
}

bool mathEvaluator::eval(std::vector<double> &values, std::vector<double> &res)
{
  if(values.size() != _variables.size()){
    Msg::Error("Given %d value(s) for %d variable(s)", values.size(), _variables.size());
    return false;
  }

  if(res.size() != _expressions.size()){
    Msg::Error("Given %d result(s) for %d expression(s)", res.size(), _expressions.size());
    return false;
  }

  for(unsigned int i = 0; i < values.size(); i++)
    _variables[i] = values[i];

  for(unsigned int i = 0; i < _expressions.size(); i++){
    try {
      res[i] = _expressions[i]->eval();
    }
    catch(smlib::mathex::error e) {
      Msg::Error(e.what());
      double eps = 1.e-20;
      for(unsigned int j = 0; j < values.size(); j++)
	_variables[j] = values[j] + eps;
      try {
	res[i] = _expressions[i]->eval();
      }
      catch(smlib::mathex::error e2) {
	  Msg::Error(e2.what());
	  return false;
      }
    }
  }
  return true;
}

#endif
