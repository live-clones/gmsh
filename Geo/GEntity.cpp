// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <sstream>
#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "VertexArray.h"
#include "Context.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"

GEntity::GEntity(GModel *m, int t)
  : _model(m), _tag(t), _meshMaster(t), _visible(1), _selection(0),
    _allElementsVisible(1), _obb(0), va_lines(0), va_triangles(0)
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

// sets the entity m from which the mesh will be copied
void GEntity::setMeshMaster(int m_signed)
{
  if(m_signed == tag()){ _meshMaster = m_signed; return; }

  GEntity *gMaster = 0;
  int m = abs(m_signed);
  switch(dim()){
  case 0 : gMaster = model()->getVertexByTag(m); break;
  case 1 : gMaster = model()->getEdgeByTag(m); break;
  case 2 : gMaster = model()->getFaceByTag(m); break;
  case 3 : gMaster = model()->getRegionByTag(m); break;
  }
  if (!gMaster){
    Msg::Error("Model entity %d of dimension %d cannot be the mesh master of entity %d",
               m, dim(), tag());
    return;
  }
  int masterOfMaster = gMaster->meshMaster();

  if (masterOfMaster == gMaster->tag()){
    _meshMaster = m_signed;
  }
  else {
    setMeshMaster ( masterOfMaster * ((m_signed > 0) ? 1 : -1));
  }
}

// gets the entity from which the mesh will be copied
int GEntity::meshMaster() const
{
  if (_meshMaster == tag()) return tag();

  GEntity *gMaster = 0;
  switch(dim()){
  case 0 : gMaster = model()->getVertexByTag(abs(_meshMaster)); break;
  case 1 : gMaster = model()->getEdgeByTag(abs(_meshMaster)); break;
  case 2 : gMaster = model()->getFaceByTag(abs(_meshMaster)); break;
  case 3 : gMaster = model()->getRegionByTag(abs(_meshMaster)); break;
  }
  if (!gMaster){
    Msg::Error("Could not find mesh master entity %d",_meshMaster);
    return tag();
  }
  int masterOfMaster = gMaster->meshMaster();

  if (masterOfMaster == gMaster->tag()){
    return _meshMaster ;
  }
  else {
    return gMaster->meshMaster() * ((_meshMaster > 0) ? 1 : -1);
  }
}

