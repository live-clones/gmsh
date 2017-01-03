// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _BACKGROUND_MESH_MANAGER_H_
#define _BACKGROUND_MESH_MANAGER_H_

#include <map>
#include "BGMBase.h"

using namespace std;

class GEntity;
class GFace;
class GRegion;

class BGMManager{
public:
  static BGMBase* get(GFace *gf);
  static BGMBase* get(GRegion *gf);
  static BGMBase* current2D();
  static void set_use_cross_field(bool b);
private:
  static bool use_cross_field;
  static BGMBase *latest2Dbgm;
  static map<GEntity*,BGMBase*> data;
};

#endif
