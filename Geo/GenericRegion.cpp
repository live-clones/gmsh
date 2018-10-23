// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues
//
// Contributed by Paul-Emile Bernard

#include "GModel.h"
#include "GenericVertex.h"
#include "GenericEdge.h"
#include "GenericFace.h"
#include "GenericRegion.h"

GenericRegion::GenericRegion(GModel *m, int num, int _native_id)
  : GRegion(m, num), id(_native_id)
{
}

GenericRegion::~GenericRegion() {}

GEntity::GeomType GenericRegion::geomType() const { return Unknown; }
