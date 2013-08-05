//
//  iosGModel.cpp
//  Onelab
//
//  Created by Maxime Graulich on 05/08/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#include "iosGModel.h"

static void * objc;

void getBitmapFromString(const char *text, int textsize, unsigned char **map, int *height, int *width, int *realWidth)
{
    getBitmap(objc, text, textsize, map, height, width, realWidth);
}

void setObjCBridge(void *objcObject)
{
    objc = objcObject;
    Msg::SetCallback((GmshMessage*)new MobileMessage(objcObject));
}