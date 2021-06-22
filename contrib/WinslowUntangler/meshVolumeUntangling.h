// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Maxence Reberol

#pragma once

#include <cstdint>

class GRegion;

bool untangleGRegionMeshConstrained(GRegion* gr, int iterMax = 1000, double timeMax = 9999.);
