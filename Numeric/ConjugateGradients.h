// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CONJUGATE_GRADIENTS_H
#define CONJUGATE_GRADIENTS_H

#include <vector>

double GradientDescent(void (*func)(std::vector<double> &x, double &Obj,
                                    bool needGrad, std::vector<double> &gradObj,
                                    void *),
                       std::vector<double> &x,
                       void *data); // User data

#endif
