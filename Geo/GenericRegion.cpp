// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GenericVertex.h"
#include "GenericEdge.h"
#include "GenericFace.h"
#include "GenericRegion.h"

GenericRegion::GenericRegion(GModel *m, int num, int _native_id):GRegion(m, num), id(_native_id)
{
}

GenericRegion::~GenericRegion()
{
}

GEntity::GeomType GenericRegion::geomType() const
{
  return Unknown;
}
