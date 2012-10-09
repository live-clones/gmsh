#include "OnelabClients.h"
#include "metamodel.h"

void initializeMetamodel(onelab::client *client)
{
  //called by  "metamodel_cb"
  //copies the Msg::_onelabClient to  OLMsg::_onelabClient
  //This pointer refers to an object of class localGmsh() (cf GmshMessage.cpp)
  //which is a onelab::client with sone Gmsh features (merge and messages).
  OLMsg::SetOnelabClient(client);
}

int metamodel(const std::string &action){
  OLMsg::Info("Start metamodel");

  parseMode todo;
  if(action == "initialize")
    todo = INITIALIZE;
  else if(action == "check")
    todo = ANALYZE;
  else if(action == "compute"){
    todo = COMPUTE;
  }
  else{
    OLMsg::Fatal("Unknown action <%s>", action.c_str());
  }

  std::string modelName = OLMsg::GetOnelabString("Arguments/FileName");
  std::string workingDir = OLMsg::GetOnelabString("Arguments/WorkingDir");
  std::string clientName = "meta";

  std::cout << "FHF ModelName=" << modelName << std::endl;
  std::cout << "FHF WorkingDir=" << workingDir << std::endl;

  MetaModel *myModel =
    new MetaModel(clientName, workingDir, clientName, modelName);
  myModel->setTodo(todo);

  if(OLMsg::GetOnelabNumber("LOGFILES")){
    freopen("stdout.txt","w",stdout);
    freopen("stderr.txt","w",stderr);
  }

  //if not all clients have valid commandlines -> exit metamodel
  if(!myModel->checkCommandLines())
    myModel->setTodo(EXIT);

  if( myModel->isTodo(EXIT)){
    // exit metamodel
  }
  else if( myModel->isTodo(INITIALIZE)){
    myModel->initialize();
  }
  else if( myModel->isTodo(ANALYZE)){
    myModel->analyze();
  }
  else if( myModel->isTodo(COMPUTE)){
    myModel->compute();
  }
  else
    OLMsg::Fatal("Main: Unknown Action <%d>", todo);

  delete myModel;
  OLMsg::Info("Leave metamodel");
  OLMsg::Info("==============================================");
}
