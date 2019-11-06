// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_CONVENTIONS_H
#define CGNS_CONVENTIONS_H

#include <vector>
#include <string>
#include "fullMatrix.h"
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)


static const std::string::size_type CGNS_MAX_STR_LEN = 32;

// msh to CGNS element type
ElementType_t msh2CgnsEltType(int mshTag);

// CGNS to msh element type
int cgns2MshEltType(ElementType_t);

std::vector<int> &cgns2MshNodeIndex(int mshTag);

// std::vector<int> &msh2CgnsNodeIndex(int mshTag);

void msh2CgnsReferenceElement(int mshType, const fullMatrix<double> &mshPts,
                              std::vector<double> &u, std::vector<double> &v,
                              std::vector<double> &w);

std::string cgnsString(const std::string &s,
                       std::string::size_type maxLength = CGNS_MAX_STR_LEN);


#endif // HAVE_LIBCGNS

#endif // CGNS_CONVENTIONS_H
