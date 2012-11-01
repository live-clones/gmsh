#include "OnelabClients.h"
#include "metamodel.h"


void initializeMetamodel(const std::string &loaderName, onelab::client *olclient, void (*gui_wait_fct)(double time))
{
  //called by  "metamodel_cb"
  //copies the Msg::_onelabClient to  OLMsg::_onelabClient
  //This pointer refers to an object of class localGmsh() (cf GmshMessage.cpp)
  //which is a onelab::client with sone Gmsh features (merge and messages).
  //Initilizes also the wait function the Gmsh Gui
  //so that Gmsh windows may remain active during client computations.
  OLMsg::SetOnelabClient(olclient);
  OLMsg::Info("I can now communicate with gmsh");
  OLMsg::SetOnelabString("LoaderPathName",loaderName,false);
  OLMsg::SetGuiWaitFunction(gui_wait_fct);
}

int metamodel(const std::string &action){
  int errors;

  OLMsg::Info("Start metamodel");
  OLMsg::hasGmsh = OLMsg::GetOnelabNumber("IsMetamodel");
  OLMsg::ResetErrorCounter();

  parseMode todo;
  // if(action == "initialize")
  //   todo = INITIALIZE;

  if(action == "compute")
    todo = COMPUTE;
  else{
    todo = ANALYZE;
  }

  std::string modelName = OLMsg::GetOnelabString("Arguments/FileName");
  std::string workingDir = OLMsg::GetOnelabString("Arguments/WorkingDir");
  std::string clientName = "meta";

  MetaModel *myModel =
    new MetaModel("meta", workingDir, "meta", modelName);
  myModel->setTodo(todo);

  if(OLMsg::GetOnelabNumber("LOGFILES")){
    std::string mystdout = FixWindowsQuotes(workingDir + "stdout.txt");
    std::string mystderr = FixWindowsQuotes(workingDir + "stderr.txt");
    OLMsg::Info("Redirecting stdout into <%s>",mystdout.c_str());
    OLMsg::Info("Redirecting stderr into <%s>",mystderr.c_str());
    freopen(mystdout.c_str(),"w",stdout);
    freopen(mystderr.c_str(),"w",stderr);
  }

  if(OLMsg::GetErrorCount()) myModel->setTodo(EXIT);

  if( myModel->isTodo(ANALYZE)){
    myModel->analyze();
  }
  else if( myModel->isTodo(COMPUTE)){
    myModel->compute();
  }
  else if( myModel->isTodo(EXIT)){
  }
  else
    OLMsg::Error("Main: Unknown Action <%d>", todo);
  delete myModel;

  if((errors=OLMsg::GetErrorCount())){
    OLMsg::Error("Leave metamodel - %d errors",errors);
    OLMsg::Info("==============================================");
    return 0;
  }

  int reload=OLMsg::GetOnelabNumber("Gmsh/NeedReloadGeom");
  OLMsg::SetOnelabNumber("Gmsh/NeedReloadGeom",0,false);

  OLMsg::Info("Leave metamodel - need reload=%d", reload);
  OLMsg::Info("==============================================");
  return reload;
}
