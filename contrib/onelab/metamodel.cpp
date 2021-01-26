#include "OnelabClients.h"
#include "metamodel.h"

/* PYTHON functions */

void modelName(const std::string &name, const std::string &wdir = "")
{
  OLMsg::InitializeOnelab("onelab");
  OLMsg::SetOnelabString("Arguments/FileName", name);
  OLMsg::SetOnelabString("Arguments/WorkingDir", wdir);
  OLMsg::SetVerbosity(0);
}

void setNumber(const std::string &name, const double value)
{
  OLMsg::SetOnelabNumber(name, value);
}
void setString(const std::string &name, const std::string &value)
{
  OLMsg::SetOnelabString(name, value);
}
double getNumber(const std::string &name)
{
  return OLMsg::GetOnelabNumber(name);
}
std::string getString(const std::string &name)
{
  return OLMsg::GetOnelabString(name);
}

/* Interface Gmsh - Metamodels */

void initializeMetamodel(const std::string &loaderName,
                         onelab::client *olclient,
                         void (*gui_wait_fct)(double time), const int verbosity)
{
  // called by  "metamodel_cb"
  // copies the Msg::_onelabClient to  OLMsg::_onelabClient
  // This pointer refers to an object of class localGmsh() (cf GmshMessage.cpp)
  // which is a onelab::client with sone Gmsh features (merge and messages).
  // Initilizes also the wait function the Gmsh Gui
  // so that Gmsh windows may remain active during client computations.
  OLMsg::SetOnelabClient(olclient);
  OLMsg::SetOnelabString("LoaderPathName", loaderName, false);
  OLMsg::SetGuiWaitFunction(gui_wait_fct);
  OLMsg::SetVerbosity(verbosity);
}

int metamodel(const std::string &action)
{
  int errors;

  OLMsg::Info("Start metamodel");
  OLMsg::hasGmsh = OLMsg::GetOnelabNumber("IsMetamodel");
  OLMsg::ResetErrorCounter();

  std::string modelName = OLMsg::GetOnelabString("Arguments/FileName");
  std::string workingDir = OLMsg::GetOnelabString("Arguments/WorkingDir");
  std::string clientName = "meta";

  parseMode todo;
  if(action == "compute")
    todo = COMPUTE;
  else {
    todo = ANALYZE;
  }
  OLMsg::SetOnelabNumber("Metamodel/Action", todo, false);

  MetaModel *myModel = new MetaModel("meta", workingDir, "meta", modelName);
  myModel->setTodo(todo);

  if(OLMsg::GetErrorCount()) myModel->setTodo(EXIT);

  if(OLMsg::GetOnelabNumber("LOGFILES")) {
    std::string mystdout = FixWindowsQuotes(workingDir + "stdout.txt");
    std::string mystderr = FixWindowsQuotes(workingDir + "stderr.txt");
    OLMsg::Info("Redirecting stdout into <%s>", mystdout.c_str());
    OLMsg::Info("Redirecting stderr into <%s>", mystderr.c_str());
    if(!freopen(mystdout.c_str(), "w", stdout)) return 0;
    if(!freopen(mystderr.c_str(), "w", stderr)) return 0;
  }

  if(myModel->isTodo(ANALYZE)) {
    // myModel->analyze(); the constructor myModel makes the analysis
  }
  else if(myModel->isTodo(COMPUTE)) {
    myModel->compute();
  }
  else if(myModel->isTodo(EXIT)) {
  }
  else
    OLMsg::Error("Main: Unknown Action <%d>", todo);
  delete myModel;

  if((errors = OLMsg::GetErrorCount())) {
    OLMsg::Error("Leave metamodel - %d errors", errors);
    OLMsg::Info("=====  O  N  E  L  A  B  =====");
    return 0;
  }

  int reload = OLMsg::GetOnelabNumber("Gmsh/NeedReloadGeom");
  OLMsg::SetOnelabNumber("Gmsh/NeedReloadGeom", 0, false);

  OLMsg::Info("Leave metamodel - need reload=%d", reload);
  OLMsg::Info("=====  O  N  E  L  A  B  =====");
  return reload;
}
