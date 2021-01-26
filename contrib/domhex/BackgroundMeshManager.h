// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BACKGROUND_MESH_MANAGER_H
#define BACKGROUND_MESH_MANAGER_H

#include <map>
#include "BGMBase.h"

class GEntity;
class GFace;
class GRegion;

class BGMManager {
public:
  static BGMBase *get(GFace *gf);
  static BGMBase *get(GRegion *gf);
  static BGMBase *current2D();
  static void set_use_cross_field(bool b);

private:
  static bool use_cross_field;
  static BGMBase *latest2Dbgm;
  static std::map<GEntity *, BGMBase *> data;
};

#endif
