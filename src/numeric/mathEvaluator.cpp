// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "mathEvaluator.h"

#if defined(HAVE_MATHEX)

mathEvaluator::mathEvaluator(std::vector<std::string> &expressions,
                             const std::vector<std::string> &variables)
{
  static std::string lastError;

  _expressions.resize(expressions.size());
  _variables.resize(variables.size(), 0.);
  bool error = false;
  for(std::size_t i = 0; i < expressions.size(); i++) {
    _expressions[i] = new smlib::mathex();
    for(std::size_t j = 0; j < variables.size(); j++)
      _expressions[i]->addvar(variables[j], &_variables[j]);
    try {
      _expressions[i]->expression(expressions[i]);
      _expressions[i]->parse();
    } catch(smlib::mathex::error &e) {
      if(e.what() + expressions[i] != lastError) {
        lastError = e.what() + expressions[i];
        Msg::Error(e.what());
        std::string pos(_expressions[i]->stopposition(), ' ');
        pos.push_back('^');
        Msg::Error(expressions[i].c_str());
        Msg::Error(pos.c_str());
      }
      error = true;
    }
  }
  if(error) {
    for(std::size_t i = 0; i < _expressions.size(); i++)
      delete(_expressions[i]);
    _expressions.clear();
    expressions.clear();
  }
}

mathEvaluator::~mathEvaluator()
{
  for(std::size_t i = 0; i < _expressions.size(); i++) delete(_expressions[i]);
}

bool mathEvaluator::eval(const std::vector<double> &values,
                         std::vector<double> &res) const
{
  if(values.size() != _variables.size()) {
    Msg::Error("Given %d value(s) for %d variable(s)", values.size(),
               _variables.size());
    return false;
  }

  if(res.size() != _expressions.size()) {
    Msg::Error("Given %d result(s) for %d expression(s)", res.size(),
               _expressions.size());
    return false;
  }

  // (a stack for each thread: the expressions are only read)
  static thread_local std::vector<double> stack;
  for(std::size_t i = 0; i < _expressions.size(); i++) {
    try {
      res[i] = _expressions[i]->eval(values.data(), stack);
    } catch(smlib::mathex::error &e) {
      Msg::Error(e.what());
      std::vector<double> shifted(values);
      for(auto &v : shifted) v += 1.e-20;
      try {
        res[i] = _expressions[i]->eval(shifted.data(), stack);
      } catch(smlib::mathex::error &e2) {
        Msg::Error(e2.what());
        return false;
      }
    }
  }
  return true;
}

#endif
