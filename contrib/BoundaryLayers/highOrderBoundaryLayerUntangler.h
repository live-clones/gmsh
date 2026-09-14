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

#ifndef HIGH_ORDER_BOUNDARY_LAYER_UNTANGLER_H
#define HIGH_ORDER_BOUNDARY_LAYER_UNTANGLER_H

#include <map>
#include <set>
#include <vector>

class MElement;
class MVertex;
class GModel;

struct MElementPtrLessThan;
struct MVertexPtrLessThan;

bool untangleHighOrderBoundaryLayerPN(
  GModel *m, const std::set<MElement *, MElementPtrLessThan> &toProcess,
  const std::set<MVertex *, MVertexPtrLessThan> &fixed, int order,
  std::map<MElement *, double> *layers = nullptr,
  const std::vector<double> *widths = nullptr, int strategy = 1,
  bool postSplitUntangle = false);

#endif
