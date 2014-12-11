#include "GmshLocalClient.h"
#include "onelabUtils.h"
#ifdef HAVE_FLTK
#include "onelab2Group.h"

void GmshLocalClient::setCallback(onelabGroup *cb) {_cb_obj = cb;}
void GmshLocalClient::onNewParameter(onelab::parameter *p){if(_cb_obj) _cb_obj->addParameter(*p);}
void GmshLocalClient::onUpdateParameter(onelab::parameter *p){if(_cb_obj) _cb_obj->updateParameter(*p);}
void GmshLocalClient::onRemoveParameter(onelab::parameter *p){if(_cb_obj) _cb_obj->removeParameter(*p);}
#endif

void GmshLocalClient::run(std::string action) {
  if(getName() == "Gmsh") onelabUtils::runGmshClient(action, 2); 
}
