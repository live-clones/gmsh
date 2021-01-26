// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "BackgroundMeshManager.h"
#include "BGMBase.h"
#include "BackgroundMesh2D.h"
#include "GEntity.h"
#include "GFace.h"
#include "GRegion.h"
#include "BackgroundMesh3D.h"

std::map<GEntity *, BGMBase *> BGMManager::data =
  std::map<GEntity *, BGMBase *>();
BGMBase *BGMManager::latest2Dbgm = nullptr;
bool BGMManager::use_cross_field = true;

void BGMManager::set_use_cross_field(bool b)
{
  if(b && !BGMManager::use_cross_field) { // need to change...
    data.clear();
  }
  BGMManager::use_cross_field = b;
}

BGMBase *BGMManager::get(GRegion *gf)
{
  auto itfind = data.find(gf);
  if(itfind != data.end()) { return itfind->second; }

  BGMBase *bgm = use_cross_field ? new frameFieldBackgroundMesh3D(gf) :
                                   new backgroundMesh3D(gf);

  data.insert(std::make_pair(gf, bgm));
  return bgm;
}

BGMBase *BGMManager::get(GFace *gf)
{
  auto itfind = data.find(gf);
  if(itfind != data.end()) {
    latest2Dbgm = itfind->second;
    return itfind->second;
  }

  BGMBase *bgm = use_cross_field ? new frameFieldBackgroundMesh2D(gf) :
                                   new backgroundMesh2D(gf);

  data.insert(std::make_pair(gf, bgm));
  latest2Dbgm = bgm;
  return bgm;
}

BGMBase *BGMManager::current2D() { return latest2Dbgm; }
