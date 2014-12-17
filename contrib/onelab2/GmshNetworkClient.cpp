#include <iostream>

#include "GmshNetworkClient.h"
#ifdef HAVE_FLTK
#include "onelab2Group.h"
#include "GmshMessage.h"

void GmshNetworkClient::setCallback(onelabGroup *cb) {_cb_obj = cb;}
void GmshNetworkClient::onNewParameter(onelab::parameter *p)
{
  if(_cb_obj) {
    Fl::lock();
    _cb_obj->addParameter(*p);
    Fl::unlock();
  }
  Fl::awake((void *)NULL);
}
void GmshNetworkClient::onUpdateParameter(onelab::parameter *p)
{
  if(_cb_obj) {
    Fl::lock();
    _cb_obj->updateParameter(*p);
    Fl::unlock();
  }
  Fl::awake((void *)NULL);
}
void GmshNetworkClient::onRemoveParameter(onelab::parameter *p)
{
  if(_cb_obj) {
    Fl::lock();
    _cb_obj->removeParameter(*p);
    Fl::unlock();
  }
  Fl::awake((void *)NULL);
}
void GmshNetworkClient::onMessage(const std::string & name, const std::string &message, int level)
{
  Fl::lock();
  switch(level) {
    case OnelabAttrMessage::Info:
      Msg::Direct("Info    : %s - %s", name.c_str(), message.c_str());
      break;
    case OnelabAttrMessage::Warning:
      Msg::Warning("%s - %s", name.c_str(), message.c_str());
      break;
    case OnelabAttrMessage::Error:
      Msg::Error("%s - %s", name.c_str(), message.c_str());
      break;
  }
  Fl::unlock();
  Fl::awake((void *)NULL);
}
#endif
