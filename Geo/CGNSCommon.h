// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_COMMON_H
#define CGNS_COMMON_H

#if defined(HAVE_LIBCGNS)


// FIXME: cgnslib.h is not suited to namespaces as it is full of defines (hence
// the dirty redefine of csize_t). Namespace CGNS should be removed.
namespace CGNS {
#include <cgnslib.h>
#ifdef cgsize_t
#undef cgsize_t
  typedef int cgsize_t;
#endif
} // namespace CGNS


int cgnsError(const int cgIndexFile = -1);

void printProgress(const char *cstr, std::size_t i, std::size_t num);


#endif // HAVE_LIBCGNS

#endif // CGNS_COMMON_H
