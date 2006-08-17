#include "GEntity.h"
#include "MRep.h"
#include "Context.h"

extern Context_T CTX;

GEntity::GEntity(GModel *m, int t)
  : _model(m), _tag(t), _visible(true), _selection(0), meshRep(0) 
{
  _color = CTX.PACK_COLOR(0, 0, 255, 0);
}

GEntity::~GEntity()
{
  if(meshRep) delete meshRep; 
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
    out += " [";
    for(unsigned int i = 0; i < physicals.size(); i++){
      if(i) out += " ";
      sprintf(tmp, "%d", physicals[i]);
      out += tmp;
    }
    out += "]";
  }

  return out;
}
