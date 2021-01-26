// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, F. Henrotte
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef METAMODEL_H
#define METAMODEL_H

#include <string>

namespace onelab {
  class client;
}

int metamodel(const std::string &todo);
void initializeMetamodel(const std::string &, onelab::client *,
                         void (*wait)(double time), const int verbosity);

/* PYTHON functions */

void modelName(const std::string &name, const std::string &wdir);
void setNumber(const std::string &name, const double value);
void setString(const std::string &name, const std::string &value);
double getNumber(const std::string &name);
std::string getString(const std::string &name);

#endif
