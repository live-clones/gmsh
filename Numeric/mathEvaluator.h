// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MATH_EVALUATOR_H_
#define _MATH_EVALUATOR_H_

#include <vector>
#include <string>
#include "GmshConfig.h"
#include "GmshMessage.h"

#if defined(HAVE_MATHEX)

#include "mathex.h"

class mathEvaluator{
 private:
  std::vector<smlib::mathex*> _expressions;
  std::vector<double> _variables;
 public:
  // initialize one or more expressions depending on zero or more
  // variables. If an error occurs the vector of expressions is
  // cleared.
  mathEvaluator(std::vector<std::string> &expressions,
                std::vector<std::string> &variables);
  ~mathEvaluator();
  // evaluate the expression(s) using the given values and fill the
  // result vector. Returns true if the evaluation succeeded.
  bool eval(std::vector<double> &values, std::vector<double> &res);
};

#else

class mathEvaluator{
 public:
  mathEvaluator(std::vector<std::string> &expressions,
                std::vector<std::string> &variables)
  {
    Msg::Error("Gmsh must be compiled with MathEx support to evaluate math "
               "expressions");
    expressions.clear();
  }
  ~mathEvaluator(){}
  bool eval(std::vector<double> &values, std::vector<double> &res)
  {
    return false;
  }
};

#endif

#endif
