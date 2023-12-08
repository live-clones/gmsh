#ifndef ONELAB_IOS_UTILS_H
#define ONELAB_IOS_UTILS_H

#include <iostream>
#include <string>

#include <Gmsh/GmshMessage.h>

void messageFromCpp(void *self, std::string level, std::string msg);
void getBitmap(void *self, const char *text, int textsize, unsigned char **map,
               int *height, int *width, int *realWidth = NULL);
void getBitmapFromString(const char *text, int textsize, unsigned char **map,
                         int *height, int *width, int *realWidth = NULL);
void setObjCBridge(void *objcObject);

class MobileMessage : GmshMessage {
private:
  void *_objcObject;

public:
  MobileMessage(void *objcObject) { _objcObject = objcObject; }
  ~MobileMessage() {}
  void operator()(std::string level, std::string message)
  {
    messageFromCpp(_objcObject, level, message);
  }
};

#endif
