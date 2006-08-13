#include "GEntity.h"

std::string GEntity::getInfoString()
{
  char str[256];
  sprintf(str, "%s %d", getTypeString().c_str(), tag());
  std::string info = getAdditionalInfoString();
  if(info.size()){
    strcat(str, " ");
    strcat(str, info.c_str());
  }
  if(physicals.size()){
    char str2[256] = " [";
    for(unsigned int i = 0; i < physicals.size(); i++){
      char str3[256];
      sprintf(str3, "%d", physicals[i]);
      if(i) strcat(str2, " ");
      strcat(str2, str3);
    }
    strcat(str2, "]");
    strcat(str, str2);
  }
  return std::string(str);
}
