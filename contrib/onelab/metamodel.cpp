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
  int errors;

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

  if(OLMsg::GetOnelabNumber("LOGFILES")){
    if(workingDir.size()) workingDir.append(dirSep);
    std::string mystdout = FixWindowsQuotes(workingDir + "stdout.txt");
    std::string mystderr = FixWindowsQuotes(workingDir + "stderr.txt");
    freopen(mystdout.c_str(),"w",stdout);
    freopen(mystderr.c_str(),"w",stderr);
    OLMsg::Info("Redirecting stdout into <%s>",mystdout.c_str());
    OLMsg::Info("Redirecting stderr into <%s>",mystderr.c_str());
  }

  MetaModel *myModel =
    new MetaModel("meta", workingDir, "meta", modelName);
  myModel->setTodo(todo);

  //if not all clients have valid commandlines -> exit metamodel
  // if(!myModel->checkCommandLines())
  //   myModel->setTodo(EXIT);

  if(OLMsg::GetErrorNum()) myModel->setTodo(EXIT);

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

  if((errors=OLMsg::GetErrorNum())){
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
