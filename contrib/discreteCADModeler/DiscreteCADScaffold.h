// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
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

#ifndef DISCRETE_CAD_SCAFFOLD_H
#define DISCRETE_CAD_SCAFFOLD_H

class GFace;

// Mesh the discrete surface gf with the Frontal-Delaunay algorithm without its
// parametrization (Mesh.Algorithm = 12): the points are placed on its
// triangulation, which, copied, is also the initial mesh, its nodes (the
// scaffold) removed as the points are inserted (see DiscreteCADScaffold.cpp).
// The boundary curves must be meshed, their nodes on the boundary of the
// triangulation (a watertight discrete model). Returns false, with an error
// message, if the surface cannot be meshed this way.
bool meshGFaceScaffold(GFace *gf);

#endif
