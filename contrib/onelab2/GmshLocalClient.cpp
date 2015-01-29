#include "GmshLocalClient.h"
#include "onelabUtils.h"
#ifdef HAVE_FLTK
#include "FlGui.h"
#include "GmshMessage.h"
#include "onelab2Group.h"
#include "OpenFile.h"
#include "Context.h"

void GmshLocalClient::setCallback(onelabGroup *cb) {_cb_obj = cb;}
void GmshLocalClient::onNewParameter(onelab::parameter *p)
{
  if(_cb_obj) {
    FlGui::instance()->lock();
    _cb_obj->addParameter(*p);
    FlGui::instance()->unlock();
    Fl::awake((void *)NULL);
  }
}
void GmshLocalClient::onUpdateParameter(onelab::parameter *p)
{
  if(_cb_obj) {
    FlGui::instance()->lock();
    _cb_obj->updateParameter(*p);
    FlGui::instance()->unlock();
    Fl::awake((void *)NULL);
  }
}
void GmshLocalClient::onRemoveParameter(onelab::parameter *p)
{
  if(_cb_obj) {
    FlGui::instance()->lock();
    _cb_obj->removeParameter(*p);
    FlGui::instance()->unlock();
    Fl::awake((void *)NULL);
  }
}
void GmshLocalClient::onMessage(const std::string & name, const std::string &message, int level)
{
  FlGui::instance()->lock();
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
  FlGui::instance()->unlock();
  Fl::awake((void *)NULL);
}
void GmshLocalClient::refresh()
{
  Fl::awake(onelab_cb, (void*)"refresh");
}
void GmshLocalClient::mergeFile(const std::string &filename)
{
  FlGui::instance()->lock();
  MergePostProcessingFile(filename, CTX::instance()->solver.autoShowViews, CTX::instance()->solver.autoShowLastStep, true);
  _cb_obj->addLastPostProcessing();
  FlGui::instance()->unlock();
  Fl::awake((void *)NULL);
}
#endif

void GmshLocalClient::run(std::string action) {
  if(getName() == "Gmsh") {
    FlGui::instance()->lock();
    onelabUtils::runGmshClient(action, 2); 
    FlGui::instance()->unlock();
    Fl::awake((void *)NULL);
  }
}
