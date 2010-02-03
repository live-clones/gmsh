//
// Description :
//
//
// Author:  <Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "gLevelSetMesh.h"

#include "SPoint3.h"
#include "MElement.h"
#include "MVertex.h"
#include "GModel.h"

double gLevelSetMesh::getVertexValue(MVertex *v) const
{
  return (*_LevelSetValue)[v->getNum()];
}
