// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_COMMON_H
#define CGNS_COMMON_H

#if defined(HAVE_LIBCGNS)

#include <cgnslib.h>
#if CGNS_VERSION < 3100
typedef int cgsize_t
#endif
#include "fullMatrix.h"


int cgnsError(const char *file, const int line, const int fileIndex = -1);

void printProgress(const char *cstr, std::size_t i, std::size_t num);

#if defined(HAVE_LIBCGNS_CPEX0045)
int evalMonomialBasis(int mshType, const std::vector<double> &u,
                      const std::vector<double> &v,
                      const std::vector<double> &w, fullMatrix<double> &val);
#endif

#endif // HAVE_LIBCGNS

#endif // CGNS_COMMON_H
