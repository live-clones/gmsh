// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef  _CONJUGATEGRADIENTS
#define  _CONJUGATEGRADIENTS

#include <vector>

double GradientDescent(void (*func)(std::vector<double> &x,
				    double &Obj,
				    bool needGrad,
				    std::vector<double> &gradObj, void *),
		       std::vector<double> &x,
		       void *data); // User data

#endif
