// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SIZE_FIELD_H
#define SIZE_FIELD_H

class GModel;

int createSizeFieldFromExistingMesh(GModel *gm, bool computeCrosses);

#endif
