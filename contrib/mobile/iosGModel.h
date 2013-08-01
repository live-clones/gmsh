//
//  iosGModel.h
//  Onelab
//
//  Created by Maxime Graulich on 07/05/13.
//  Copyright (c) 2013 Maxime Graulich. All rights reserved.
//

#ifndef __Onelab__iosGModel__
#define __Onelab__iosGModel__

#include <iostream>
#include <string>

#include "drawContext.h"

static void * objc;

void messageFromCpp (void *self, std::string level, std::string msg);
void getBitmap(void *self, const char *text, int textsize, unsigned char **map, int *height, int *width, int *realWidth=NULL);
//void getBitmapFromString(const char *text, int textsize, unsigned char **map, int *height, int *width, int *realWidth=NULL);
void getBitmapFromString(const char *text, int textsize, unsigned char **map, int *height, int *width, int *realWidth)
{
    getBitmap(objc, text, textsize, map, height, width, realWidth);
}

class MobileMessage : GmshMessage
{
private:
    void* _objcObject;
public:
    MobileMessage(void* objcObject){_objcObject = objcObject;}
    ~MobileMessage(){}
    void operator()(std::string level, std::string message)
    {
        messageFromCpp(_objcObject, level, message);
    }
};
void setObjCBridge(void *objcObject)
{
    objc = objcObject;
    Msg::SetCallback((GmshMessage*)new MobileMessage(objcObject));
}

#endif /* defined(__Onelab__iosGModel__) */
