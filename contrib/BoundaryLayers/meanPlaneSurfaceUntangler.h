// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MEAN_PLANE_SURFACE_UNTANGLER_H
#define MEAN_PLANE_SURFACE_UNTANGLER_H

#include <set>
#include <map>

class GFace;
class MElement;
class MVertex;

struct MElementPtrLessThan;
struct MVertexPtrLessThan;

struct MeanPlaneSurfaceUntanglerOptions {
  double normalAngle = 5. * 3.14159265358979323846 / 180.;
  double distanceTolerance = 5.e-2;
  double extensionDistanceTolerance = 1.e-3;
  double moveTolerance = 1.e-4;
  double lambda = 1.;
  int iterMaxInner = 300;
  int iterMaxOuter = 100;
  int iterFailMax = 10;
  int maxPatchRings = 2;
  int numSweeps = 100;
  double timeMax = 9999.;
  bool verbose = true;
  bool writePatchDebugPos = false;
  bool lockPatchBoundary = true;
};

bool untangleSurfaceMeanPlanePatches(
  GFace *gf, const std::set<MElement *, MElementPtrLessThan> &toProcess,
  const std::set<MVertex *, MVertexPtrLessThan> &fixed,
  const MeanPlaneSurfaceUntanglerOptions &options =
    MeanPlaneSurfaceUntanglerOptions());

bool untangleSurfaceMeanPlanePatchesP1(
  GFace *gf, const std::set<MElement *, MElementPtrLessThan> &toProcess,
  const std::set<MVertex *, MVertexPtrLessThan> &fixed,
  const std::map<MElement *, double> &layers,
  const MeanPlaneSurfaceUntanglerOptions &options =
    MeanPlaneSurfaceUntanglerOptions());

#endif
