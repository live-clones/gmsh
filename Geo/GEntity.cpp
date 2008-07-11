// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include "GEntity.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "VertexArray.h"
#  include "Context.h"
#endif

extern Context_T CTX;

GEntity::GEntity(GModel *m, int t)
  : _model(m), _tag(t), _visible(true), _selection(0),
    _allElementsVisible(1), va_lines(0), va_triangles(0)
{
  _color = CTX.PACK_COLOR(0, 0, 255, 0);
}

GEntity::~GEntity()
{
  deleteVertexArrays();
}

void GEntity::deleteVertexArrays()
{
  if(va_lines) delete va_lines; va_lines = 0;
  if(va_triangles) delete va_triangles; va_triangles = 0;
}

char GEntity::getVisibility()
{
  if(CTX.hide_unselected && !CTX.pick_elements && !getSelection() &&
     geomType() != ProjectionFace)
    return false;
  return _visible;
}

bool GEntity::useColor()
{
  int r = CTX.UNPACK_RED(_color);
  int g = CTX.UNPACK_GREEN(_color);
  int b = CTX.UNPACK_BLUE(_color);
  int a = CTX.UNPACK_ALPHA(_color);
  if(r == 0 && g == 0 && b == 255 && a == 0)
    return false;
  return true;
}

std::string GEntity::getInfoString()
{
  char tmp[256];
  sprintf(tmp, " %d", tag());

  std::string out = getTypeString() + tmp;

  std::string info = getAdditionalInfoString();
  if(info.size())
    out += " " + info;

  if(physicals.size()){
    out += " (Physical: ";
    for(unsigned int i = 0; i < physicals.size(); i++){
      if(i) out += " ";
      sprintf(tmp, "%d", physicals[i]);
      out += tmp;
    }
    out += ")";
  }

  return out;
}
