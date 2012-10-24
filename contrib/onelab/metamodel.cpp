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
  OLMsg::SetLoaderName(loaderName);
  OLMsg::SetOnelabClient(olclient);
  OLMsg::SetGuiWaitFunction(gui_wait_fct);
}

int metamodel(const std::string &action){
  OLMsg::Info("Start metamodel");
  OLMsg::hasGmsh = OLMsg::GetOnelabNumber("IsMetamodel");
  OLMsg::ResetErrorNum();

  parseMode todo;
  if(action == "initialize")
    todo = INITIALIZE;
  else if(action == "check")
    todo = ANALYZE;
  else if(action == "compute"){
    todo = COMPUTE;
  }
  else{
    todo = EXIT;
    OLMsg::Error("Unknown action <%s>", action.c_str());
  }

  std::string modelName = OLMsg::GetOnelabString("Arguments/FileName");
  std::string workingDir = OLMsg::GetOnelabString("Arguments/WorkingDir");
  std::string clientName = "meta";

  MetaModel *myModel =
    new MetaModel(clientName, workingDir, clientName, modelName);
  myModel->setTodo(todo);

  if(OLMsg::GetOnelabNumber("LOGFILES")){
    if(workingDir.size()) workingDir.append(dirSep);
    std::string mystdout = workingDir + "stdout.txt";
    std::string mystderr = workingDir + "stderr.txt";
    freopen(mystdout.c_str(),"w",stdout);
    freopen(mystderr.c_str(),"w",stderr);
  }

  //if not all clients have valid commandlines -> exit metamodel
  if(!myModel->checkCommandLines())
    myModel->setTodo(EXIT);

  if( myModel->isTodo(EXIT)){
    // exit metamodel
  }
  else if( myModel->isTodo(ANALYZE)){
    myModel->analyze();
  }
  else if( myModel->isTodo(COMPUTE)){
    myModel->compute();
  }
  else
    OLMsg::Error("Main: Unknown Action <%d>", todo);
  delete myModel;

  int reload=OLMsg::GetOnelabNumber("Gmsh/NeedReloadGeom");
  int errors=OLMsg::GetErrorNum();
  OLMsg::SetOnelabNumber("Gmsh/NeedReloadGeom",0,false);

  if(errors)
    OLMsg::Error("Leave metamodel - %d errors",errors);
  else
    OLMsg::Info("Leave metamodel - need reload=%d",reload);
  OLMsg::Info("==============================================");

  return reload;
}
