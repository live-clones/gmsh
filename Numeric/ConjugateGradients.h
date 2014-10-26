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
