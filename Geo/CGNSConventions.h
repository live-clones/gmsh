// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_CONVENTIONS_H
#define CGNS_CONVENTIONS_H

#if defined(HAVE_LIBCGNS)

#include <vector>
#include <string>

// FIXME: cgnslib.h is not suited to namespaces as it is full of defines (hence
// the dirty redefine of csize_t). Namespace CGNS should be removed.
namespace CGNS {
#include <cgnslib.h>
#ifdef cgsize_t
#undef cgsize_t
  typedef int cgsize_t;
#endif
} // namespace CGNS

// msh to CGNS element type
CGNS::ElementType_t msh2CgnsEltType(int mshTag);

// CGNS to msh element type
int cgns2MshEltType(CGNS::ElementType_t);

std::vector<int> &cgns2MshNodeIndex(int mshTag);

std::string cgnsString(const std::string &s);

#endif // HAVE_LIBCGNS

#endif // CGNS_CONVENTIONS_H
