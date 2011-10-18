// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl.H>
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "drawContext.h"
#include "PView.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "menuWindow.h"
#include "fileDialogs.h"
#include "onelab.h"
#include "onelabWindow.h"

// This file contains the Gmsh/FLTK specific parts of the ONELAB
// interface. You'll need to reimplement this if you plan to build
// a different ONELAB server.

class onelabGmshServer : public GmshServer{
 private:
  onelab::localNetworkClient *_client;
 public:
  onelabGmshServer(onelab::localNetworkClient *client) : GmshServer(), _client(client) {}
  ~onelabGmshServer() {}
  int SystemCall(const char *str)
  { 
    return ::SystemCall(str); 
  }
  int NonBlockingWait(int socket, double waitint, double timeout)
  { 
    double start = GetTimeInSeconds();
    while(1){
      if(timeout > 0 && GetTimeInSeconds() - start > timeout)
        return 2; // timout

      if(_client->getPid() < 0)
        return 1; // process has been killed

      // check if there is data (call select with a zero timeout to
      // return immediately, i.e., do polling)
      int ret = Select(0, 0, socket);

      if(ret == 0){ 
        // nothing available: wait at most waitint seconds, and in the
        // meantime respond to FLTK events
        FlGui::instance()->wait(waitint);
      }
      else if(ret > 0){ 
        return 0; // data is there!
      }
      else{ 
        // an error happened
        _client->setPid(-1);
        return 1;
      }
    }
  }
};

bool onelab::localNetworkClient::run(const std::string &what)
{
  _pid = 0;
  onelabGmshServer *server = new onelabGmshServer(this);
 
  std::string sockname = CTX::instance()->solver.socketName;
  std::string command = _commandLine + " " + what +  " -onelab " + sockname;
#if !defined(WIN32)
  command += " &";
#endif

  int sock;
  try{
    sock = server->Start(command.c_str(), sockname.c_str(),
                         CTX::instance()->solver.timeout);
  }
  catch(const char *err){
    Msg::Error("%s (on socket '%s')", err, sockname.c_str());
    sock = -1;
  }
  
  if(sock < 0){
    server->Shutdown();
    delete server;
    return false;
  }

  Msg::StatusBar(2, true, "Running '%s'...", _name.c_str());

  while(1) {

    if(_pid < 0) break;
    
    int stop = server->NonBlockingWait(sock, 0.1, 0.);
    if(stop || _pid < 0) break;
    
    int type, length, swap;
    if(!server->ReceiveHeader(&type, &length, &swap)){
      Msg::Error("Did not receive message header: stopping server");
      break;
    }

    std::string message(length, ' ');
    if(!server->ReceiveMessage(length, &message[0])){
      Msg::Error("Did not receive message body: stopping server");
      break;
    }

    switch (type) {
    case GmshSocket::GMSH_START:
      _pid = atoi(message.c_str());
      break;
    case GmshSocket::GMSH_STOP:
      _pid = -1;
      break;
    case GmshSocket::GMSH_PARAMETER:
      {
        std::string type, name;
        onelab::parameter::getTypeAndNameFromChar(message, type, name);
        if(type == "number"){
          onelab::number p;
          p.fromChar(message);
          set(p, false);
        }
        else if(type == "string"){
          onelab::string p;
          p.fromChar(message);
          set(p, false);
        }
        else
          Msg::Error("FIXME not done for this parameter type");
      }
      break;
    case GmshSocket::GMSH_PARAMETER_QUERY:
      {
        std::string type, name;
        onelab::parameter::getTypeAndNameFromChar(message, type, name);
        if(type == "number"){
          std::vector<onelab::number> par;
          get(par, name);
          if(par.size() == 1){
            std::string reply = par[0].toChar();
            server->SendMessage(GmshSocket::GMSH_PARAMETER, reply.size(), &reply[0]);
          }
          else{
            std::string reply = "Parameter (number) " + name + " not found";
            server->SendMessage(GmshSocket::GMSH_INFO, reply.size(), &reply[0]);
          }
        }
        else if(type == "string"){
          std::vector<onelab::string> par;
          get(par, name);
          if(par.size() == 1){
            std::string reply = par[0].toChar();
            server->SendMessage(GmshSocket::GMSH_PARAMETER, reply.size(), &reply[0]);
          }
          else{
            std::string reply = "Parameter (string) " + name + " not found";
            server->SendMessage(GmshSocket::GMSH_INFO, reply.size(), &reply[0]);
          }
        }
        else
          Msg::Error("FIXME query not done for this parameter type");
      }
      break;
    case GmshSocket::GMSH_PROGRESS:
      Msg::StatusBar(2, false, "%s %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_INFO:
      Msg::Direct("%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_WARNING:
      Msg::Direct(2, "%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_ERROR:
      Msg::Direct(1, "%-8.8s: %s", _name.c_str(), message.c_str());
      break;
    case GmshSocket::GMSH_MERGE_FILE:
      {
        int n = PView::list.size();
        MergeFile(message);
        drawContext::global()->draw();
        if(n != (int)PView::list.size()) 
          FlGui::instance()->menu->setContext(menu_post, 0);
      }
      break;
    case GmshSocket::GMSH_PARSE_STRING:
      ParseString(message);
      drawContext::global()->draw();
      break;
    default:
      Msg::Warning("Received unknown message type (%d)", type);
      break;
    } 

    FlGui::instance()->check();
  }

  server->Shutdown();
  delete server;

  Msg::StatusBar(2, true, "Done running '%s'", _name.c_str());
  return true;
}

bool onelab::localNetworkClient::kill()
{
  if(_pid > 0) {
    if(KillProcess(_pid)){
      Msg::Info("Killed '%s' (pid %d)", _name.c_str(), _pid);
      _pid = -1;
      return true; 
    }
  }
  _pid = -1;
  return false;
}

static void onelab_save_mesh(onelab::client *c)
{
  std::vector<onelab::string> ps;
  c->get(ps, "Gmsh/MshFileName");
  if(ps.size()){
    CreateOutputFile(ps[0].getValue(), CTX::instance()->mesh.fileFormat);
  }
  else{
    std::string name = CTX::instance()->outputFileName;
    if(name.empty()){
      if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
        name = GetDefaultFileName(FORMAT_MSH);
      else
        name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
    }
    onelab::string o("Gmsh/MshFileName", name, "Mesh name");
    c->set(o);
    CreateOutputFile(o.getValue(), CTX::instance()->mesh.fileFormat);
  }
}

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string action((const char*)data);

  if(action == "edit model"){
    std::string prog = FixWindowsPath(CTX::instance()->editor);
    std::string file = FixWindowsPath(FlGui::instance()->onelab->getModelName());
    SystemCall(ReplaceSubString("%s", file, prog));
    return;
  }

  if(action == "reset"){
    onelab::server::instance()->clear();
    if(onelab::server::instance()->findClient("Gmsh") != 
       onelab::server::instance()->lastClient())
      geometry_reload_cb(0, 0);
    action = "initial check";
  }

  if(action == "choose model"){
    if(fileChooser(FILE_CHOOSER_SINGLE, "Choose", "*.pro"))
      FlGui::instance()->onelab->setModelName(fileChooserGetName(1));
    action = "check";
  }

  if(FlGui::instance()->onelab->getModelName().empty()){
    std::vector<std::string> split = SplitFileName(GModel::current()->getFileName());
    FlGui::instance()->onelab->setModelName(split[0] + split[1] + ".pro");
  }

  FlGui::instance()->onelab->deactivate();
  
  // the Gmsh client is special: it always gets executed first. (The
  // meta-model will allow more flexibility: but in the simple GUI we
  // can assume this)
  onelab::server::citer it = onelab::server::instance()->findClient("Gmsh");
  if(it != onelab::server::instance()->lastClient()){
    static std::string gmshModelName = GModel::current()->getName();
    // reload geometry and/or mesh it if Gmsh parameters have been
    // modified or if the geometrical model has changed
    if(onelab::server::instance()->getChanged("Gmsh") ||
       gmshModelName != GModel::current()->getName()){
      gmshModelName = GModel::current()->getName();
      if(action == "check"){
        geometry_reload_cb(0, 0);
      }
      else if(action == "compute"){
        geometry_reload_cb(0, 0);
        if(FlGui::instance()->onelab->meshAuto()){
          mesh_3d_cb(0, 0);
          onelab_save_mesh(it->second);
        }
        onelab::server::instance()->setChanged(false, "Gmsh");
      }
    }
  }

  // Iterate over all other clients
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    onelab::client *c = it->second;
    if(c->getName() == "Gmsh") continue;
    std::string what = FlGui::instance()->onelab->getModelName();
    if(action == "initial check" || action == "check"){
      c->run(what);
    }
    else if(action == "compute"){
      // get command line from the server
      std::vector<onelab::string> ps;
      onelab::server::instance()->get(ps, c->getName() + "/9Compute");
      if(ps.size()) what += " " + ps[0].getValue();
      c->run(what);
    }
  }

  FlGui::instance()->onelab->activate();

  printf("Gmsh ONELAB db:\n%s\n", onelab::server::instance()->toChar().c_str());

  FlGui::instance()->onelab->rebuildTree();
  FlGui::instance()->onelab->show();
}

static void onelab_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    numbers[0].setValue(((Fl_Check_Button*)w)->value());
    onelab::server::instance()->set(numbers[0]);
  }
}

static void onelab_value_input_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    numbers[0].setValue(((Fl_Value_Input*)w)->value());
    onelab::server::instance()->set(numbers[0]);
  }
}

static void onelab_input_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    strings[0].setValue(((Fl_Input_Choice*)w)->value());
    onelab::server::instance()->set(strings[0]);
  }
}

static void onelab_choose_executable_cb(Fl_Widget *w, void *data)
{
  onelab::localNetworkClient *c = (onelab::localNetworkClient*)data;
  std::string pattern = "*";
#if defined(WIN32)
  pattern += ".exe";
#endif
  if(fileChooser(FILE_CHOOSER_SINGLE, "Choose executable", pattern.c_str())){
    std::string exe = fileChooserGetName(1);
    c->setCommandLine(exe);
    // FIXME hack
    opt_solver_executable(0, GMSH_SET, exe);
  }
}

static void onelab_remove_solver_cb(Fl_Widget *w, void *data)
{
  onelab::client *c = (onelab::client*)data;
  FlGui::instance()->onelab->removeSolver(c->getName());
}

onelabWindow::onelabWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int width = 25 * FL_NORMAL_SIZE;
  int height = 15 * BH + 3 * WB;
  
  _win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "ONELAB");
  _win->box(GMSH_WINDOW_BOX);

  _model = new Fl_Input(WB, WB, width - 2*WB - BB/3, BH);
  _model->align(FL_ALIGN_RIGHT);
  _model->callback(onelab_cb, (void*)"check");
  _model->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);

  Fl_Menu_Button *menu = new Fl_Menu_Button(width - WB - BB/3, WB, BB/3, BH);
  menu->add("Choose new model", 0, onelab_cb, (void*)"choose model");
  menu->add("Edit model",  0, onelab_cb, (void*)"edit model");

  _tree = new Fl_Tree(WB, WB+BH, width - 2 * WB, height - 3 * WB - 2 * BH);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  _tree->showroot(0);

  _butt[0] = new Fl_Button(width - WB - BB, height - WB - BH, BB, BH, "Compute");
  _butt[0]->callback(onelab_cb, (void*)"compute");
  _butt[1] = new Fl_Button(width - 2*WB - 2*BB, height - WB - BH, BB, BH, "Check");
  _butt[1]->callback(onelab_cb, (void*)"check");
  _gear = new Fl_Menu_Button
    (_butt[1]->x() - WB - BB/2, _butt[1]->y(), BB/2, BH, "@-1gmsh_gear");
  _gear->add("Reset database", 0, onelab_cb, (void*)"reset");
  _gear->add("Mesh automatically", 0, 0, 0, FL_MENU_TOGGLE);
  ((Fl_Menu_Item*)_gear->menu())[1].set();
  
  Fl_Box *resbox = new Fl_Box(WB, height - BH - 3 * WB, WB, WB);
  _win->resizable(resbox);

  _win->position
    (CTX::instance()->solverPosition[0], CTX::instance()->solverPosition[1]);
  _win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

static std::string getShortName(const std::string &name) 
{
  std::string s = name;
  // remove path
  std::string::size_type last = name.find_last_of('/');
  if(last != std::string::npos)
    s = name.substr(last + 1);
  // remove starting numbers
  while(s.size() && s[0] >= '0' && s[0] <= '9')
    s = s.substr(1);
  return s;
}

void onelabWindow::rebuildTree()
{
  _tree->clear();
  _tree->sortorder(FL_TREE_SORT_ASCENDING);
  _tree->selectmode(FL_TREE_SELECT_NONE);
  for(unsigned int i = 0; i < _treeWidgets.size(); i++)
    Fl::delete_widget(_treeWidgets[i]);
  _treeWidgets.clear();

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    Fl_Tree_Item *n = _tree->add(numbers[i].getName().c_str());
    n->labelsize(FL_NORMAL_SIZE + 2);
    std::string label = numbers[i].getShortHelp();
    if(label.empty()) label = getShortName(numbers[i].getName());
    _tree->begin();
    if(numbers[i].getChoices().size() == 2 &&
       numbers[i].getChoices()[0] == 0 && numbers[i].getChoices()[1] == 1){
      Fl_Check_Button *but = new Fl_Check_Button(1,1,IW,1);
      _treeWidgets.push_back(but);
      but->copy_label(label.c_str());
      but->value(numbers[i].getValue());
      but->callback(onelab_check_button_cb, (void*)n);
      n->widget(but);
    }
    else{
      Fl_Value_Input *but = new Fl_Value_Input(1,1,IW,1);
      _treeWidgets.push_back(but);
      but->copy_label(label.c_str());
      but->value(numbers[i].getValue());
      if(numbers[i].getMin() != -1.e200)
        but->minimum(numbers[i].getMin());
      if(numbers[i].getMax() != 1.e200)
        but->maximum(numbers[i].getMax());
      if(numbers[i].getStep())
        but->step(numbers[i].getStep());
      but->align(FL_ALIGN_RIGHT);
      but->callback(onelab_value_input_cb, (void*)n);
      but->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);
      n->widget(but);
    }
    _tree->end();
  }

  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings);
  for(unsigned int i = 0; i < strings.size(); i++){
    Fl_Tree_Item *n = _tree->add(strings[i].getName().c_str());
    n->labelsize(FL_NORMAL_SIZE + 2);
    std::string label = strings[i].getShortHelp();
    if(label.empty()) label = getShortName(strings[i].getName());
    _tree->begin();
    Fl_Input_Choice *but = new Fl_Input_Choice(1,1,IW,1);
    _treeWidgets.push_back(but);
    but->copy_label(label.c_str());
    for(unsigned int j = 0; j < strings[i].getChoices().size(); j++)
      but->add(strings[i].getChoices()[j].c_str());
    but->value(strings[i].getValue().c_str());
    but->align(FL_ALIGN_RIGHT);
    but->callback(onelab_input_choice_cb, (void*)n);
    but->when(FL_WHEN_RELEASE|FL_WHEN_ENTER_KEY);
    n->widget(but);
    _tree->end();
  }

  for(Fl_Tree_Item *n = _tree->first(); n; n = n->next()){
    if(n->has_children()){
      _tree->begin();
      Fl_Box *but = new Fl_Box(1,1,IW,1);
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      _treeWidgets.push_back(but);
      but->copy_label(getShortName(n->label()).c_str());
      n->widget(but);
      _tree->end();
    }
  }
  
  _tree->redraw();
}

void onelabWindow::rebuildSolverList()
{
  for(int i = _gear->menu()->size(); i >= 2; i--){
    _gear->remove(i);
  }
  _title = "ONELAB";
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    onelab::client *c = it->second;
    char tmp[256];
    if(c->isNetworkClient()){
      sprintf(tmp, "%s/Choose executable", c->getName().c_str());
      _gear->add(tmp, 0, onelab_choose_executable_cb, (void*)c);
    }
    sprintf(tmp, "%s/Remove", c->getName().c_str());
    _gear->add(tmp, 0, onelab_remove_solver_cb, (void*)c);
    _title += " " + c->getName();
  }
  _win->label(_title.c_str());
}

void onelabWindow::addSolver(const std::string &name, const std::string &commandLine)
{
  onelab::server::citer it = onelab::server::instance()->findClient(name);
  if(it == onelab::server::instance()->lastClient()){
    onelab::client *c = new onelab::localNetworkClient(name, commandLine);
    onelab::server::instance()->registerClient(c);
  }
  FlGui::instance()->onelab->rebuildSolverList();
}

void onelabWindow::removeSolver(const std::string &name)
{
  onelab::server::citer it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()){
    onelab::client *c = it->second;
    onelab::server::instance()->removeClient(name);
    if(c->isNetworkClient()) // cannot delete local gmsh client (allocated in Msg)
      delete it->second;
  }
  FlGui::instance()->onelab->rebuildSolverList();
}

// new solver interface (onelab-based)
void solver_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;

  std::string name = opt_solver_name(num, GMSH_GET, "");
  std::string exe = opt_solver_executable(num, GMSH_GET, "");
  FlGui::instance()->onelab->addSolver(name, exe);

  onelab_cb(0, (void*)"initial check");
}

#endif

