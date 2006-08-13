#include "GEntity.h"

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
