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
void messageFromCpp (void *self, std::string level, std::string msg);

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

class iosGModel
{
private:
    void* _objcObject;
public:
    iosGModel(void* objcObject)
    {
        _objcObject = objcObject;
        Msg::SetCallback((GmshMessage*)new MobileMessage(objcObject));
    }
    ~iosGModel(){}
};

#endif /* defined(__Onelab__iosGModel__) */
