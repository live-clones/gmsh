#include <iostream>

#include "GmshNetworkClient.h"
#ifdef HAVE_FLTK
#include "onelab2Group.h"

void GmshNetworkClient::setCallback(onelabGroup *cb) {_cb_obj = cb;}
void GmshNetworkClient::onNewParameter(onelab::parameter *p){if(_cb_obj) _cb_obj->addParameter(*p);}
void GmshNetworkClient::onUpdateParameter(onelab::parameter *p){if(_cb_obj) _cb_obj->updateParameter(*p);}
void GmshNetworkClient::onRemoveParameter(onelab::parameter *p){if(_cb_obj) _cb_obj->removeParameter(*p);}
#endif
