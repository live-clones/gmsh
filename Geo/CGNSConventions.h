// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#ifndef CGNS_CONVENTIONS_H
#define CGNS_CONVENTIONS_H

#include <vector>
#include <string>
#include "GmshConfig.h"
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)

static const std::string::size_type CGNS_MAX_STR_LEN = 33;

// msh to CGNS element type
CGNS_ENUMT(ElementType_t) msh2CgnsEltType(int mshTag);

// CGNS to msh element type
int cgns2MshEltType(CGNS_ENUMT(ElementType_t));

std::vector<int> &cgns2MshNodeIndex(int mshTag);

// std::vector<int> &msh2CgnsNodeIndex(int mshTag);

void msh2CgnsReferenceElement(int mshType, const fullMatrix<double> &mshPts,
                              std::vector<double> &u, std::vector<double> &v,
                              std::vector<double> &w);

// Given two sets of parametric coordinates src and dest, that should contain
// the same nodes in a different order, compute the reordering ind of set src
// to set dest, i.e. src[i] = dest[ind[i]]
bool computeReordering(fullMatrix<double> src, fullMatrix<double> dest,
                       std::vector<int> &ind);

std::string cgnsString(const std::string &s,
                       std::string::size_type maxLength = CGNS_MAX_STR_LEN - 1);

#endif // HAVE_LIBCGNS

#endif // CGNS_CONVENTIONS_H
