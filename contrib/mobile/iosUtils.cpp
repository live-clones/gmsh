#include "iosUtils.h"

static void *objc;

void getBitmapFromString(const char *text, int textsize, unsigned char **map,
                         int *height, int *width, int *realWidth)
{
  getBitmap(objc, text, textsize, map, height, width, realWidth);
}

void setObjCBridge(void *objcObject)
{
  objc = objcObject;
  Msg::SetCallback((GmshMessage *)new MobileMessage(objcObject));
}
