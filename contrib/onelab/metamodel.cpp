#include "OnelabClients.h"
#include "metamodel.h"

void initializeMetamodel(onelab::client *client)
{
  OLMsg::SetOnelabClient(client);
}

int metamodel(const std::string &action){

  parseMode todo;
  if(action == "check"){
    todo = ANALYZE;
  }
  else if(action == "compute"){
    todo = COMPUTE;
  }
  else{
    todo = STOP;
  }

  std::string modelName = OLMsg::GetOnelabString("Arguments/FileName");
  std::string workingDir = OLMsg::GetOnelabString("Arguments/WorkingDir");
  std::string clientName = "meta";

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
}
