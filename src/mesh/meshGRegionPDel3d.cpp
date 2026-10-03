// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <numeric>
#include "meshGRegionPDel3d.h"
#include "pdel3d.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"

static int numThreads3D()
{
  int n = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    n = CTX::instance()->mesh.maxNumThreads3D;
  if(!n) n = Msg::GetMaxThreads();
  return n;
}

void delaunayMeshIn3DPDel3d(std::vector<MVertex *> &v,
                            std::vector<MTetrahedron *> &tets)
{
  const double t0 = TimeOfDay();
  const std::size_t n = v.size();
  pdel3d::Mesh m;
  m.xyz.resize(4 * n);
  for(std::size_t i = 0; i < n; i++) {
    m.xyz[4 * i + 0] = v[i]->x();
    m.xyz[4 * i + 1] = v[i]->y();
    m.xyz[4 * i + 2] = v[i]->z();
    m.xyz[4 * i + 3] = 0.;
  }
  m.reserveTets(8 * n + 16384);
  std::vector<pdel3d::vIdx> toInsert(n);
  std::iota(toInsert.begin(), toInsert.end(), 0);
  std::vector<std::uint8_t> status;
  pdel3d::DelaunayOptions opt;
  opt.numThreads = numThreads3D();
  opt.reorderVertices = true; // toInsert[i] = original index of vertex i
  opt.verbosity = Msg::GetVerbosity() > 5 ? 2 : 1;
  pdel3d::DelaunayStats stats;
  pdel3d::insertVertices(m, opt, toInsert, status, &stats);
  if(Msg::GetVerbosity() > 5) m.verify(true);
  tets.reserve(m.numRealTets());
  for(std::size_t t = 0; t < m.ntet; t++) {
    if(m.isGhost((pdel3d::tIdx)t)) continue;
    const pdel3d::vIdx *nd = &m.node[4 * t];
    tets.push_back(new MTetrahedron(v[toInsert[nd[0]]], v[toInsert[nd[1]]],
                                    v[toInsert[nd[2]]], v[toInsert[nd[3]]]));
  }
  Msg::Info("pdel3d: %lu points, %lu tets (Wall %gs: sort %g, insert %g)", n,
            tets.size(), TimeOfDay() - t0, stats.timeSort, stats.timeInsert);
}
