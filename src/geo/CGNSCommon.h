// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#ifndef CGNS_COMMON_H
#define CGNS_COMMON_H

#include "GmshConfig.h"

#if defined(HAVE_LIBCGNS)

#include <cgnslib.h>
#if CGNS_VERSION < 3100
typedef int cgsize_t
#endif

template <class scalar>
class fullMatrix;

int cgnsError(const char *file, const int line, const int fileIndex = -1);

void printProgress(const char *cstr, std::size_t i, std::size_t num);

#if defined(HAVE_LIBCGNS_CPEX0045)
int evalMonomialBasis(int mshType, const std::vector<double> &u,
                      const std::vector<double> &v,
                      const std::vector<double> &w, fullMatrix<double> &val);
#endif

// Multi-D (IJ/IJK) to linear index conversion (indices start at 0)
template <int DIM>
inline cgsize_t ijk2Ind(const cgsize_t *ijk, const cgsize_t *nijk);

// 2D (IJ) to linear index conversion (indices start at 0)
template <>
inline cgsize_t ijk2Ind<2>(const cgsize_t *ijk, const cgsize_t *nijk)
{
  return ijk[1] * nijk[0] + ijk[0];
}

// 3D (IJK) to linear index conversion (indices start at 0)
template <>
inline cgsize_t ijk2Ind<3>(const cgsize_t *ijk, const cgsize_t *nijk)
{
  return (ijk[2] * nijk[1] + ijk[1]) * nijk[0] + ijk[0];
}

// Multi-D (IJ/IJK) to linear number of entities
template <int DIM> inline cgsize_t nbTotFromIJK(const cgsize_t *nijk);

// 2D (IJ) to linear number of entities
template <> inline cgsize_t nbTotFromIJK<2>(const cgsize_t *nijk)
{
  return nijk[0] * nijk[1];
}

// 3D (IJK) to linear number of entities
template <> inline cgsize_t nbTotFromIJK<3>(const cgsize_t *nijk)
{
  return nijk[0] * nijk[1] * nijk[2];
}

// class to manage indexing in CGNS unstructured zones (starting from 1)
struct UnstructuredIndexing {
  static cgsize_t nbEntInRange(const cgsize_t *range);
  static void entFromRange(const cgsize_t *range, std::vector<cgsize_t> &elt);
  static void entFromList(const std::vector<cgsize_t> &list,
                          std::vector<cgsize_t> &elt);
};

inline cgsize_t UnstructuredIndexing::nbEntInRange(const cgsize_t *range)
{
  return range[1] - range[0] + 1;
}

inline void UnstructuredIndexing::entFromRange(const cgsize_t *range,
                                               std::vector<cgsize_t> &ent)
{
  std::size_t nb = range[1] - range[0] + 1;
  ent.resize(nb);
  cgsize_t iMin = range[0] - 1;
  for(std::size_t i = 0; i < nb; i++) ent[i] = iMin + i;
}

inline void UnstructuredIndexing::entFromList(const std::vector<cgsize_t> &list,
                                              std::vector<cgsize_t> &ent)
{
  std::size_t nb = list.size();
  ent.resize(nb);
  for(std::size_t i = 0; i < nb; i++) ent[i] = list[i] - 1;
}

// class to manage indexing in CGNS structured zones (starting from (1, 1, 1)),
// explicitly instantiated for 2D and 3D in .cpp file
template <int DIM> struct StructuredIndexing {
  static cgsize_t nbEntInRange(const cgsize_t *range);
  static void entFromRange(const cgsize_t *range, const cgsize_t *nbEntIJK,
                           std::vector<cgsize_t> &elt);
  static void entFromList(const std::vector<cgsize_t> &list,
                          const cgsize_t *nbEntIJK, std::vector<cgsize_t> &elt);
};

template <int DIM>
inline cgsize_t StructuredIndexing<DIM>::nbEntInRange(const cgsize_t *range)
{
  cgsize_t nb = 1;
  for(int d = 0; d < DIM; d++) {
    const cgsize_t diff = range[DIM + d] - range[d];
    nb *= (diff >= 0) ? diff + 1 : -diff + 1;
  }
  return nb;
}

#endif // HAVE_LIBCGNS

#endif // CGNS_COMMON_H
