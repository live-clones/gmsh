// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "VertexArray.h"
#include "Context.h"
#include "Bindings.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

GEntity::GEntity(GModel *m, int t)
  : _model(m), _tag(t), _visible(1), _selection(0),
    _allElementsVisible(1), _obb(0), va_lines(0), va_triangles(0),
    _meshMaster(t)
{
  _color = CTX::instance()->packColor(0, 0, 255, 0);
}

void GEntity::deleteVertexArrays()
{
  if(va_lines) delete va_lines; va_lines = 0;
  if(va_triangles) delete va_triangles; va_triangles = 0;
}

char GEntity::getVisibility()
{
  if(CTX::instance()->hideUnselected && !CTX::instance()->pickElements &&
     !getSelection() && geomType() != ProjectionFace)
    return false;
  return _visible;
}

bool GEntity::useColor()
{
  int r = CTX::instance()->unpackRed(_color);
  int g = CTX::instance()->unpackGreen(_color);
  int b = CTX::instance()->unpackBlue(_color);
  int a = CTX::instance()->unpackAlpha(_color);
  if(r == 0 && g == 0 && b == 255 && a == 0)
    return false;
  return true;
}

std::string GEntity::getInfoString()
{
  std::ostringstream sstream;
  sstream << getTypeString() << " " << tag();

  std::string info = getAdditionalInfoString();
  if(info.size()) sstream << " " << info;

  if(physicals.size()){
    sstream << " (Physical:";
    for(unsigned int i = 0; i < physicals.size(); i++)
      sstream << " " << physicals[i];
    sstream << ")";
  }

  return sstream.str();
}

GVertex *GEntity::cast2Vertex() { return dynamic_cast<GVertex*>(this); }
GEdge *GEntity::cast2Edge() { return dynamic_cast<GEdge*>(this); }
GFace *GEntity::cast2Face() { return dynamic_cast<GFace*>(this); }
GRegion *GEntity::cast2Region() { return dynamic_cast<GRegion*>(this); }

void GEntity::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<GEntity>("GEntity");
  cb->setDescription("A GEntity is a geometrical entity of the model.");
  methodBinding *mb;
  mb = cb->addMethod("getNumMeshElements",
                     (unsigned int (GEntity::*)())&GEntity::getNumMeshElements);
  mb->setDescription("return the number of mesh elements in this entity");
  mb = cb->addMethod("getMeshElement",&GEntity::getMeshElement);
  mb->setDescription("get the mesh element at the given index");
  mb->setArgNames("index",NULL);
  mb = cb->addMethod("getNumMeshVertices",
                     (unsigned int (GEntity::*)())&GEntity::getNumMeshVertices);
  mb->setDescription("return the number of mesh vertices in this entity");
  mb = cb->addMethod("getMeshVertex",&GEntity::getMeshVertex);
  mb->setDescription("get the mesh vertex at the given index");
  mb->setArgNames("index",NULL);
  mb = cb->addMethod("addMeshVertex",&GEntity::addMeshVertex);
  mb->setDescription("insert a new mesh vertex");
  mb->setArgNames("vertex",NULL);
  mb = cb->addMethod("model", &GEntity::model);
  mb->setDescription("returns the geometric model the entity belongs to.");
  mb = cb->addMethod("cast2Vertex", &GEntity::cast2Vertex);
  mb->setDescription("do a dynamic cast of the GEntity to a GVertex (0 if wrong cast).");
  mb = cb->addMethod("cast2Edge", &GEntity::cast2Edge);
  mb->setDescription("do a dynamic cast of the GEntity to a GEdge (0 if wrong cast).");
  mb = cb->addMethod("cast2Face", &GEntity::cast2Face);
  mb->setDescription("do a dynamic cast of the GEntity to a GFace (0 if wrong cast).");
  mb = cb->addMethod("cast2Region", &GEntity::cast2Region);
  mb->setDescription("do a dynamic cast of the GEntity to a GRegion (0 if wrong cast).");
  mb = cb->addMethod("tag", &GEntity::tag);
  mb->setDescription("return the tag of this entity.");

}
