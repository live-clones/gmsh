// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _GL2PGF_H_
#define _GL2PGF_H_

#include <string>
#include "PixelBuffer.h"

int print_pgf(const std::string &name, const int num, const int cnt, 
              PixelBuffer *buffer, double *eulerAngles,
              int *viewport, double *proj, double *model);

#endif
