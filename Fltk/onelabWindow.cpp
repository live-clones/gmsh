// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl.H>
#include "GmshConfig.h"
#include "GmshMessage.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#endif

#if defined(HAVE_ONELAB) && (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)

#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include "inputRange.h"
#include "Context.h"
#include "GModel.h"
#include "GmshDefines.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "drawContext.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "menuWindow.h"
#include "fileDialogs.h"
#include "onelabWindow.h"

// This file contains the Gmsh/FLTK specific parts of the OneLab
// interface. You'll need to reimplement this if you plan to build
// a different OneLab server.

class onelabGmshServer : public GmshServer{
 private:
  onelab::localNetworkClient *_client;
 public:
  onelabGmshServer(onelab::localNetworkClient *client)
    : GmshServer(), _client(client) {}
  ~onelabGmshServer(){}
  int NonBlockingSystemCall(const char *str){ return SystemCall(str); }
  int NonBlockingWait(int socket, double waitint, double timeout)
  {
    double start = GetTimeInSeconds();
    while(1){
      if(timeout > 0 && GetTimeInSeconds() - start > timeout)
        return 2; // timout
      if(_client->getPid() < 0 || (_client->getExecutable().empty() &&
                                   !CTX::instance()->solver.listen))
        return 1; // process has been killed or we stopped listening
      // check if there is data (call select with a zero timeout to
      // return immediately, i.e., do polling)
      int ret = Select(0, 0, socket);
      if(ret == 0){ // nothing available
        // if asked, refresh the onelab GUI
        std::vector<onelab::string> ps;
        onelab::server::instance()->get(ps, "Gmsh/Action");
        if(ps.size() && ps[0].getValue() == "refresh"){
          ps[0].setVisible(false);
          ps[0].setValue("");
          onelab::server::instance()->set(ps[0]);
          onelab_cb(0, (void*)"refresh");
        }
        // wait at most waitint seconds and respond to FLTK events
        FlGui::instance()->wait(waitint);
      }
      else if(ret > 0){
        return 0; // data is there!
      }
      else{
        // an error happened
        _client->setPid(-1);
        _client->setGmshServer(0);
        return 1;
      }
    }
  }
};

static void mergePostProcessingFile(const std::string &fileName)
{
  if(!FlGui::instance()->onelab->mergeAuto()) return;

  unsigned int n = PView::list.size();
  // store old step values
  std::vector<int> steps(n, 0);
  if(FlGui::instance()->onelab->showLastStep()){
    for(unsigned int i = 0; i < PView::list.size(); i++)
      steps[i] = (int)opt_view_nb_timestep(i, GMSH_GET, 0);
  }

  // check if there is a mesh in the file
  FILE *fp = fopen(fileName.c_str(), "rb");
  if(!fp){
    Msg::Warning("Unable to open file '%s'", fileName.c_str());
    return;
  }
  char header[256];
  if(!fgets(header, sizeof(header), fp)) return;
  bool haveMesh = false;
  if(!strncmp(header, "$MeshFormat", 11)){
    while(!feof(fp) && fgets(header, sizeof(header), fp)){
      if(!strncmp(header, "$Nodes", 6)){
        haveMesh = true;
        break;
      }
      else if(!strncmp(header, "$NodeData", 9) ||
              !strncmp(header, "$ElementData", 12) ||
              !strncmp(header, "$ElementNodeData", 16)){
        break;
      }
    }
  }
  fclose(fp);

  // if there is a mesh, create a new model to store it (don't merge elements in
  // the current mesh!)
  GModel *old = GModel::current();
  if(haveMesh){
    GModel *m = new GModel();
    GModel::setCurrent(m);
  }
  MergeFile(fileName);
  GModel::setCurrent(old);
  old->setVisibility(1);

  // hide everything except the onelab X-Y graphs
  if(FlGui::instance()->onelab->hideNewViews()){
    for(unsigned int i = 0; i < PView::list.size(); i++){
      if(PView::list[i]->getData()->getFileName().substr(0, 6) != "OneLab")
        PView::list[i]->getOptions()->visible = 0;
    }
  }
  else if(n != PView::list.size()){
    // if we created new views, assume we only want to see those (and the
    // onelab X-Y graphs)
    for(unsigned int i = 0; i < n; i++){
      if(PView::list[i]->getData()->getFileName().substr(0, 6) != "OneLab")
        PView::list[i]->getOptions()->visible = 0;
    }
  }

  // if we added steps, go to the last one
  if(FlGui::instance()->onelab->showLastStep()){
    steps.resize(PView::list.size(), 0);
    for(unsigned int i = 0; i < PView::list.size(); i++){
      int step = (int)opt_view_nb_timestep(i, GMSH_GET, 0);
      if(step > steps[i])
        opt_view_timestep(i, GMSH_SET|GMSH_GUI, step - 1);
    }
  }

  drawContext::global()->draw();
  if(n != PView::list.size())
    FlGui::instance()->menu->setContext(menu_post, 0);
}

bool onelab::localNetworkClient::run()
{
 new_connection:
  _pid = 0;
  _gmshServer = 0;

  onelabGmshServer *server = new onelabGmshServer(this);

  std::string sockname;
  std::ostringstream tmp;
  if(!strstr(CTX::instance()->solver.socketName.c_str(), ":")){
    // Unix socket
    tmp << CTX::instance()->homeDir << CTX::instance()->solver.socketName << getId();
    sockname = FixWindowsPath(tmp.str());
  }
  else{
    // TCP/IP socket
    if(CTX::instance()->solver.socketName.size() &&
       CTX::instance()->solver.socketName[0] == ':')
      tmp << GetHostName(); // prepend hostname if only the port number is given
    tmp << CTX::instance()->solver.socketName << getId();
    sockname = tmp.str();
  }

  std::string command = FixWindowsPath(_executable);
  if(command.size()){
    // complete the command line if "UseCommandLine" is set in the database
    std::vector<onelab::number> n;
    get(n, getName() + "/UseCommandLine");
    if(n.size() && n[0].getValue()){
      std::vector<onelab::string> ps;
      get(ps, getName() + "/Action");
      std::string action = (ps.empty() ? "" : ps[0].getValue());
      get(ps, getName() + "/1ModelName");
      std::string modelName = (ps.empty() ? "" : ps[0].getValue());
      get(ps, getName() + "/9CheckCommand");
      std::string checkCommand = (ps.empty() ? "" : ps[0].getValue());
      get(ps, getName() + "/9ComputeCommand");
      std::string computeCommand = (ps.empty() ? "" : ps[0].getValue());
      if(action == "check")
        command.append(" \"" + modelName + "\" " + checkCommand) ;
      else if(action == "compute")
        command.append(" \"" + modelName + "\" " + computeCommand);
    }
    command.append(" " + getSocketSwitch() + " \"" + getName() + "\" %s");
  }
  else{
    Msg::Info("Listening on socket '%s'", sockname.c_str());
  }

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

    if(_pid < 0 || (command.empty() && !CTX::instance()->solver.listen))
      break;

    int stop = server->NonBlockingWait(sock, 0.001, 0.);

    if(stop || _pid < 0 || (command.empty() && !CTX::instance()->solver.listen))
      break;

    double timer = GetTimeInSeconds();

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
      _gmshServer = server;
      break;
    case GmshSocket::GMSH_STOP:
      _pid = -1;
      _gmshServer = 0;
      break;
    case GmshSocket::GMSH_PARAMETER:
      {
        std::string version, type, name;
        onelab::parameter::getInfoFromChar(message, version, type, name);
        if(type == "number"){
          onelab::number p;
          p.fromChar(message);
          set(p);
        }
        else if(type == "string"){
          onelab::string p;
          p.fromChar(message);
          set(p);
        }
        else
          Msg::Error("FIXME not done for this parameter type: %s", type.c_str());
      }
      break;
    case GmshSocket::GMSH_PARAMETER_QUERY:
      {
        std::string version, type, name, reply;
        onelab::parameter::getInfoFromChar(message, version, type, name);
        if(type == "number"){
          std::vector<onelab::number> par;
          get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else if(type == "string"){
          std::vector<onelab::string> par;
          get(par, name);
          if(par.size() == 1) reply = par[0].toChar();
        }
        else
          Msg::Error("FIXME not done for this parameter type: %s", type.c_str());
        if(reply.size()){
          server->SendMessage(GmshSocket::GMSH_PARAMETER, reply.size(), &reply[0]);
        }
        else{
          reply = "Parameter '" + name + "' not found";
          server->SendMessage(GmshSocket::GMSH_INFO, reply.size(), &reply[0]);
        }
      }
      break;
    case GmshSocket::GMSH_PARAM_QUERY_ALL:
      {
        std::string version, type, name, reply;
        onelab::parameter::getInfoFromChar(message, version, type, name);
	if(type == "number"){
	  std::vector<onelab::number> numbers;
	  get(numbers);
	  for(std::vector<onelab::number>::iterator it = numbers.begin();
              it != numbers.end(); it++){
	    reply = (*it).toChar();
	    server->SendMessage(GmshSocket::GMSH_PARAM_QUERY_ALL, reply.size(), &reply[0]);
	  }
	  reply = "OneLab: sent all numbers";
	  server->SendMessage(GmshSocket::GMSH_PARAM_QUERY_END, reply.size(), &reply[0]);
	}
	else if(type == "string"){
	  std::vector<onelab::string> strings;
	  get(strings);
	  for(std::vector<onelab::string>::iterator it = strings.begin();
              it != strings.end(); it++){
	    reply = (*it).toChar();
	    server->SendMessage(GmshSocket::GMSH_PARAM_QUERY_ALL, reply.size(), &reply[0]);
	  }
	  reply = "OneLab: sent all strings";
	  server->SendMessage(GmshSocket::GMSH_PARAM_QUERY_END, reply.size(), &reply[0]);
	}
        else
          Msg::Error("FIXME query not done for this parameter type: %s", type.c_str());
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
      mergePostProcessingFile(message);
      break;
    case GmshSocket::GMSH_PARSE_STRING:
      ParseString(message);
      drawContext::global()->draw();
      break;
    case GmshSocket::GMSH_SPEED_TEST:
      Msg::Info("got %d Mb message in %g seconds",
                length / 1024 / 1024, GetTimeInSeconds() - timer);
      break;
    case GmshSocket::GMSH_VERTEX_ARRAY:
      {
        int n = PView::list.size();
        PView::fillVertexArray(this, length, &message[0], swap);
        FlGui::instance()->updateViews(n != (int)PView::list.size());
        drawContext::global()->draw();
      }
      break;
    default:
      Msg::Warning("Received unknown message type (%d)", type);
      break;
    }
  }

  _gmshServer = 0;
  server->Shutdown();
  delete server;

  Msg::StatusBar(2, true, "Done running '%s'", _name.c_str());

  if(command.empty()){
    Msg::Info("Client disconnected: starting new connection");
    goto new_connection;
  }

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

static std::string getMshFileName(onelab::client *c)
{
  std::vector<onelab::string> ps;
  c->get(ps, "Gmsh/MshFileName");
  if(ps.size()){
    return ps[0].getValue();
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
    o.setKind("file");
    c->set(o);
    return name;
  }
}

static void guessModelName(onelab::client *c)
{
  std::vector<onelab::number> n;
  c->get(n, c->getName() + "/GuessModelName");
  if(n.size() && n[0].getValue()){
    std::vector<onelab::string> ps;
    c->get(ps, c->getName() + "/1ModelName");
    if(ps.empty()){
      std::vector<std::string> split = SplitFileName(GModel::current()->getFileName());
      std::string ext = "";
      onelab::server::instance()->get(ps, c->getName() + "/FileExtension");
      if(ps.size()) ext = ps[0].getValue();
      std::string name(split[0] + split[1] + ext);
      onelab::string o(c->getName() + "/1ModelName", name, "Model name");
      o.setKind("file");
      c->set(o);
    }
  }
}

static void initializeLoop(const std::string &level)
{
  bool changed = false;
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(numbers[i].getAttribute("Loop") == level){
      if(numbers[i].getChoices().size() > 1){
        numbers[i].setValue(numbers[i].getChoices()[0]);
        onelab::server::instance()->set(numbers[i]);
        changed = true;
      }
      else if(numbers[i].getStep() > 0){
	if(numbers[i].getMin() != -onelab::parameter::maxNumber()){
	  numbers[i].setValue(numbers[i].getMin());
	  onelab::server::instance()->set(numbers[i]);
	  changed = true;
	}
      }
      else if(numbers[i].getStep() < 0){
	if(numbers[i].getMax() != onelab::parameter::maxNumber()){
	  numbers[i].setValue(numbers[i].getMax());
	  onelab::server::instance()->set(numbers[i]);
	  changed = true;
	}
      }
    }
  }

  // force this to make sure that we remesh, even if a mesh exists and
  // we did not actually change a Gmsh parameter
  if(changed)
    onelab::server::instance()->setChanged(true, "Gmsh");
}

static bool incrementLoop(const std::string &level)
{
  bool recompute = false, loop = false;
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(numbers[i].getAttribute("Loop") == level){
      loop = true;

      if(numbers[i].getChoices().size() > 1){
        // FIXME should store loopVariable attribute in the parameter
        // -- the following test will loop forever if 2 values are
        // identical in the list of choices
        std::vector<double> choices(numbers[i].getChoices());
        for(unsigned int j = 0; j < choices.size() - 1; j++){
          if(numbers[i].getValue() == choices[j]){
            numbers[i].setValue(choices[j + 1]);
            onelab::server::instance()->set(numbers[i]);
            Msg::Info("Recomputing with new choice %s=%g",
                      numbers[i].getName().c_str(), numbers[i].getValue());
            recompute = true;
            break;
          }
        }
      }
      else if(numbers[i].getStep() > 0){
	if(numbers[i].getMax() != onelab::parameter::maxNumber() &&
	   numbers[i].getValue() < numbers[i].getMax()){
	  numbers[i].setValue(numbers[i].getValue() + numbers[i].getStep());
	  onelab::server::instance()->set(numbers[i]);
	  Msg::Info("Recomputing with new step %s=%g",
		    numbers[i].getName().c_str(), numbers[i].getValue());
	  recompute = true;
	}
      }
      else if(numbers[i].getStep() < 0){
	if(numbers[i].getMin() != -onelab::parameter::maxNumber() &&
	   numbers[i].getValue() > numbers[i].getMin()){
	  numbers[i].setValue(numbers[i].getValue() + numbers[i].getStep());
	  onelab::server::instance()->set(numbers[i]);
	  Msg::Info("Recomputing with new step %s=%g",
		    numbers[i].getName().c_str(), numbers[i].getValue());
	  recompute = true;
	}
      }
    }
  }

  if(loop && !recompute) // end of this loop level
    initializeLoop(level);

  return recompute;
}

static void initializeLoop()
{
  initializeLoop("1");
  initializeLoop("2");
  initializeLoop("3");

  if(onelab::server::instance()->getChanged())
    FlGui::instance()->onelab->rebuildTree();
}

static bool incrementLoop()
{
  bool ret = false;
  if(incrementLoop("3"))      ret = true;
  else if(incrementLoop("2")) ret = true;
  else if(incrementLoop("1")) ret = true;

  if(onelab::server::instance()->getChanged())
    FlGui::instance()->onelab->rebuildTree();

  return ret;
}

static std::vector<double> getRange(onelab::number &p)
{
  std::vector<double> v;

  if(p.getChoices().size()){
    v = p.getChoices();
  }
  else if(p.getMin() != -onelab::parameter::maxNumber() &&
          p.getMax() != onelab::parameter::maxNumber()){
    if(p.getStep() > 0){
      for(double d = p.getMin(); d <= p.getMax(); d += p.getStep())
	v.push_back(d);
    }
    else if(p.getStep() < 0){
      for(double d = p.getMin(); d <= p.getMax(); d -= p.getStep())
	v.push_back(d);
    }
  }
  return v;
}

static bool updateOnelabGraph(const std::string &snum)
{
  bool changed = false;

  PView *view = 0;

  for(unsigned int i = 0; i < PView::list.size(); i++){
    if(PView::list[i]->getData()->getFileName() == "OneLab" + snum){
      view = PView::list[i];
      break;
    }
  }

  int num = atoi(snum.c_str());
  std::vector<double> x, y;
  std::string xName, yName;
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    std::string v = numbers[i].getAttribute("Graph");
    v.resize(8, '0');
    if(v[2 * num] == '1'){
      x = getRange(numbers[i]);
      xName = numbers[i].getShortName();
    }
    if(v[2 * num + 1] == '1'){
      y = getRange(numbers[i]);
      yName = numbers[i].getShortName();
    }
  }
  if(x.empty()){
    xName.clear();
    for(unsigned int i = 0; i < y.size(); i++) x.push_back(i);
  }
  if(x.size() && y.size()){
    if(view){
      view->getData()->setXY(x, y);
      view->getData()->setName(yName);
      view->getOptions()->axesLabel[0] = xName;
      view->setChanged(true);
    }
    else{
      view = new PView(xName, yName, x, y);
      view->getData()->setFileName("OneLab" + snum);
      view->getOptions()->intervalsType = PViewOptions::Discrete;
      view->getOptions()->autoPosition = num + 2;
    }
    changed = true;
  }
  else if(view){
    delete view;
    changed = true;
  }

  if(changed) FlGui::instance()->updateViews();
  return changed;
}

static void updateOnelabGraphs()
{
  bool redraw0 = updateOnelabGraph("0");
  bool redraw1 = updateOnelabGraph("1");
  bool redraw2 = updateOnelabGraph("2");
  bool redraw3 = updateOnelabGraph("3");
  if(redraw0 || redraw1 || redraw2 || redraw3)
    drawContext::global()->draw();
}

static void importPhysicalGroups(onelab::client *c, GModel *m)
{
  std::map<int, std::vector<GEntity*> > groups[4];
  m->getPhysicalGroups(groups);
  for(int dim = 0; dim < 3; dim++){
    for(std::map<int, std::vector<GEntity*> >::iterator it = groups[dim].begin();
        it != groups[dim].end(); it++){
      // create "read-only" onelab region
      std::string name = m->getPhysicalName(dim, it->first);
      std::ostringstream num;
      num << it->first;
      if(name.empty())
        name = std::string("Physical") +
          ((dim == 3) ? "Volume" : (dim == 2) ? "Surface" :
           (dim == 1) ? "Line" : "Point") + num.str();
      onelab::region p(name, num.str());
      p.setDimension(dim);
      p.setReadOnly(true);
      c->set(p);
    }
  }
}

static void runGmshClient(const std::string &action)
{
  onelab::server::citer it = onelab::server::instance()->findClient("Gmsh");
  if(it == onelab::server::instance()->lastClient()) return;

  onelab::client *c = it->second;
  std::string mshFileName = getMshFileName(c);
  if(action == "initialize") return;

  static std::string modelName = "";
  if(modelName.empty()){
    // first pass is special to prevent model reload, as well as
    // remeshing if a mesh file already exists on disk
    modelName = GModel::current()->getName();
    importPhysicalGroups(c, GModel::current());
    if(!StatFile(mshFileName))
      onelab::server::instance()->setChanged(false, "Gmsh");
  }

  if(action == "check"){
    if(onelab::server::instance()->getChanged("Gmsh") ||
       modelName != GModel::current()->getName()){
      // reload geometry if Gmsh parameters have been modified or if
      // the model name has changed
      modelName = GModel::current()->getName();
      geometry_reload_cb(0, 0);
      importPhysicalGroups(c, GModel::current());
    }
  }
  else if(action == "compute"){
    if(onelab::server::instance()->getChanged("Gmsh") ||
       modelName != GModel::current()->getName()){
      // reload the geometry, mesh it and save the mesh if Gmsh
      // parameters have been modified or if the model name has
      // changed
      modelName = GModel::current()->getName();
      geometry_reload_cb(0, 0);
      importPhysicalGroups(c, GModel::current());
      if(FlGui::instance()->onelab->meshAuto()){
        mesh_3d_cb(0, 0);
        CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
      }
    }
    else if(StatFile(mshFileName)){
      // mesh+save if the mesh file does not exist
      if(FlGui::instance()->onelab->meshAuto()){
        mesh_3d_cb(0, 0);
        CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
      }
    }
    onelab::server::instance()->setChanged(false, "Gmsh");
  }
}

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string action((const char*)data);

  if(action == "refresh"){
    updateOnelabGraphs();
    FlGui::instance()->onelab->rebuildTree();
    return;
  }

  if(action == "stop"){
    FlGui::instance()->onelab->stop(true);
    FlGui::instance()->onelab->setButtonMode("", "kill");
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++){
      onelab::string o(it->second->getName() + "/Action", "stop");
      o.setVisible(false);
      onelab::server::instance()->set(o);
    }
    return;
  }

  if(action == "kill"){
    FlGui::instance()->onelab->stop(true);
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++)
      it->second->kill();
    return;
  }

  if(action == "dump"){
    std::string db = onelab::server::instance()->toChar();
    Msg::Direct("OneLab database dump:");
    int start = 0;
    for(unsigned int i = 0; i < db.size(); i++){
      if(db[i] == onelab::parameter::charSep()) db[i] = '|';
      if(db[i] == '\n'){
        Msg::Direct("%s", db.substr(start, i - start).c_str());
        start = i + 1;
      }
    }
    FlGui::instance()->showMessages();
    return;
  }

  if(action == "reset"){
    // clear everything except model names and command line setup
    std::vector<onelab::string> modelNames;
    std::vector<onelab::number> useCommandLines;
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
      onelab::client *c = it->second;
      std::vector<onelab::string> ps;
      c->get(ps, c->getName() + "/1ModelName");
      if(ps.size()) modelNames.push_back(ps[0]);
      std::vector<onelab::number> ps2;
      c->get(ps2, c->getName() + "/UseCommandLine");
      if(ps2.size()) useCommandLines.push_back(ps2[0]);
    }
    onelab::server::instance()->clear();
    if(onelab::server::instance()->findClient("Gmsh") !=
       onelab::server::instance()->lastClient())
      geometry_reload_cb(0, 0);
    for(unsigned int i = 0; i < modelNames.size(); i++)
      onelab::server::instance()->set(modelNames[i]);
    for(unsigned int i = 0; i < useCommandLines.size(); i++)
      onelab::server::instance()->set(useCommandLines[i]);
    action = "check";
  }

  FlGui::instance()->onelab->setButtonMode("", "stop");

  if(action == "compute") initializeLoop();

  do{ // enter loop

    // the Gmsh client is special: it always gets executed first. (The
    // meta-model will allow more flexibility: but in the simple GUI
    // we can assume this)
    runGmshClient(action);

    if(action == "compute")
      FlGui::instance()->onelab->checkForErrors("Gmsh");
    if(FlGui::instance()->onelab->stop()) break;

    // iterate over all other clients (there should narmally only be one)
    for(onelab::server::citer it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++){
      onelab::client *c = it->second;
      if(c->getName() == "Gmsh" || // local Gmsh client
         c->getName() == "Listen" || // unknown client connecting through "-listen"
         c->getName() == "GmshRemote") // distant post-processing Gmsh client
        continue;
      if(action != "initialize") guessModelName(c);
      onelab::string o(c->getName() + "/Action", action);
      o.setVisible(false);
      onelab::server::instance()->set(o);
      c->run();
      if(action == "compute")
        FlGui::instance()->onelab->checkForErrors(c->getName());
      if(FlGui::instance()->onelab->stop()) break;
    }

    if(action != "initialize"){
      updateOnelabGraphs();
      FlGui::instance()->onelab->rebuildTree();
    }

  } while(action == "compute" && !FlGui::instance()->onelab->stop() &&
          incrementLoop());

  FlGui::instance()->onelab->stop(false);
  FlGui::instance()->onelab->setButtonMode("check", "compute");
  if(action != "initialize") FlGui::instance()->onelab->show();
}

static void onelab_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Check_Button *o = (Fl_Check_Button*)w;
    numbers[0].setValue(o->value());
    onelab::server::instance()->set(numbers[0]);
  }
}

static void onelab_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    Fl_Choice *o = (Fl_Choice*)w;
    std::vector<double> choices = numbers[0].getChoices();
    if(o->value() < (int)choices.size()) numbers[0].setValue(choices[o->value()]);
    onelab::server::instance()->set(numbers[0]);
  }
}

static void onelab_input_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()){
    inputRange *o = (inputRange*)w;
    if(o->doCallbackOnValues()){
      numbers[0].setValue(o->value());
      numbers[0].setMin(o->minimum());
      numbers[0].setMax(o->maximum());
      numbers[0].setStep(o->step());
      numbers[0].setChoices(o->choices());
    }
    o->doCallbackOnValues(true);
    numbers[0].setAttribute("Loop", o->loop());
    numbers[0].setAttribute("Graph", o->graph());
    onelab::server::instance()->set(numbers[0]);
    updateOnelabGraphs();
  }
}

static void onelab_input_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name = FlGui::instance()->onelab->getPath((Fl_Tree_Item*)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()){
    Fl_Input_Choice *o = (Fl_Input_Choice*)w;
    strings[0].setValue(o->value());
    onelab::server::instance()->set(strings[0]);
  }
}

static void onelab_input_choice_file_chooser_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice*)w->parent();
  if(fileChooser(FILE_CHOOSER_SINGLE, "Choose", "", but->value())){
    but->value(fileChooserGetName(1).c_str());
    but->do_callback(but, data);
  }
}

static void onelab_input_choice_file_edit_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice*)w->parent();
  std::string prog = FixWindowsPath(CTX::instance()->editor);
  std::string file = FixWindowsPath(but->value());
  SystemCall(ReplaceSubString("%s", file, prog));
}

static void onelab_input_choice_file_merge_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice*)w->parent();
  std::string file = FixWindowsPath(but->value());
  MergeFile(file);
  drawContext::global()->draw();
}

static void onelab_choose_executable_cb(Fl_Widget *w, void *data)
{
  onelab::localNetworkClient *c = (onelab::localNetworkClient*)data;
  std::string pattern = "*";
#if defined(WIN32)
  pattern += ".exe";
#endif
  const char *old = 0;
  if(!c->getExecutable().empty()) old = c->getExecutable().c_str();

  if(fileChooser(FILE_CHOOSER_SINGLE, "Choose executable", pattern.c_str(), old)){
    std::string exe = fileChooserGetName(1);
    c->setExecutable(exe);
    if(c->getIndex() >= 0 && c->getIndex() < 5)
      opt_solver_executable(c->getIndex(), GMSH_SET, exe);
  }
}

static void onelab_remove_solver_cb(Fl_Widget *w, void *data)
{
  onelab::client *c = (onelab::client*)data;
  FlGui::instance()->onelab->removeSolver(c->getName());
}

static void onelab_add_solver_cb(Fl_Widget *w, void *data)
{
  for(int i = 0; i < 5; i++){
    if(opt_solver_name(i, GMSH_GET, "").empty()){
      const char *name = fl_input("Client name:", "");
      if(name){
        FlGui::instance()->onelab->addSolver(name, "", "", i);
      }
      return;
    }
  }
}

onelabWindow::onelabWindow(int deltaFontSize)
  : _deltaFontSize(deltaFontSize), _stop(false)
{
  FL_NORMAL_SIZE -= _deltaFontSize;

  int width = CTX::instance()->solverSize[0];
  int height = CTX::instance()->solverSize[1];

  _win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "OneLab");
  _win->box(GMSH_WINDOW_BOX);

  _tree = new Fl_Tree(WB, WB, width - 2 * WB, height - 3 * WB - BH);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  _tree->showroot(0);

  _itemWidth = (int)(0.5 * _tree->w());

  _butt[0] = new Fl_Button(width - 2*WB - 2*BB, height - WB - BH, BB, BH, "Check");
  _butt[0]->callback(onelab_cb, (void*)"check");
  _butt[1] = new Fl_Button(width - WB - BB, height - WB - BH, BB, BH, "Compute");
  _butt[1]->callback(onelab_cb, (void*)"compute");

  _gear = new Fl_Menu_Button
    (_butt[0]->x() - WB - BB/2, _butt[0]->y(), BB/2, BH, "@-1gmsh_gear");
  _gear->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  _gear->add("Reset database", 0, onelab_cb, (void*)"reset");
  _gear->add("_Print database", 0, onelab_cb, (void*)"dump");
  _gear->add("Remesh automatically", 0, 0, 0, FL_MENU_TOGGLE);
  _gear->add("Merge results automatically", 0, 0, 0, FL_MENU_TOGGLE);
  _gear->add("Hide new views", 0, 0, 0, FL_MENU_TOGGLE);
  _gear->add("_Always show last step", 0, 0, 0, FL_MENU_TOGGLE);
  ((Fl_Menu_Item*)_gear->menu())[2].set();
  ((Fl_Menu_Item*)_gear->menu())[3].set();
  ((Fl_Menu_Item*)_gear->menu())[4].clear();
  ((Fl_Menu_Item*)_gear->menu())[5].set();
  _gearFrozenMenuSize = _gear->menu()->size();

  Fl_Box *resbox = new Fl_Box(WB, WB,
                              width - 2 * BB - BB / 2 - 4 * WB,
                              height - 3 * WB - BH);
  _win->resizable(resbox);
  _win->size_range(2 * BB + BB / 2 + 4 * WB + 1, 2 * BH + 3 * WB);

  _win->position
    (CTX::instance()->solverPosition[0], CTX::instance()->solverPosition[1]);
  _win->end();

  FL_NORMAL_SIZE += _deltaFontSize;
}

static bool getFlColor(const std::string &str, Fl_Color &c)
{
  if(str == "1"){
    c = FL_YELLOW;
    return true;
  }
  int r, g, b;
  if(str.size() && GetRGBForString(str.c_str(), r, g, b)){
    c = fl_color_cube(r * (FL_NUM_RED - 1) / 255,
                      g * (FL_NUM_GREEN - 1) / 255,
                      b * (FL_NUM_BLUE - 1) / 255);
    return true;
  }
  c = FL_BLACK;
  return false;
}

void onelabWindow::_addParameter(onelab::number &p)
{
  std::string label = p.getShortName();
  std::vector<double> choices = p.getChoices();
  bool highlight = false;
  Fl_Color c;
  if(getFlColor(p.getAttribute("Highlight"), c)) highlight = true;

  Fl_Tree_Item *n = _tree->add(p.getName().c_str());
  n->labelsize(FL_NORMAL_SIZE + 5);
  _tree->begin();
  Fl_Widget *widget;
  if(p.getReadOnly()){
    // non-editable value
    Fl_Output *but = new Fl_Output(1, 1, _itemWidth, 1);
    char tmp[128];
    sprintf(tmp, "%g", p.getValue());
    but->value(tmp);
    if(highlight) but->color(c);
    widget = but;
  }
  else if(choices.size() && choices.size() == p.getValueLabels().size()){
    // enumeration (display choices as value labels, not numbers)
    Fl_Choice *but = new Fl_Choice(1, 1, _itemWidth, 1);
    std::vector<Fl_Menu_Item> menu;
    std::map<double, std::string> labels(p.getValueLabels());
    for(std::map<double, std::string>::iterator it = labels.begin();
        it != labels.end(); it++){
      char *str = strdup(it->second.c_str());
      _treeStrings.push_back(str);
      Fl_Menu_Item it = {str, 0, 0, 0, 0};
      menu.push_back(it);
    }
    Fl_Menu_Item it = {0};
    menu.push_back(it);
    but->copy(&menu[0]);
    for(unsigned int i = 0; i < choices.size(); i++){
      if(p.getValue() == choices[i]){
        but->value(i);
        break;
      }
    }
    but->callback(onelab_choice_cb, (void*)n);
    if(highlight) n->labelbgcolor(c);
    widget = but;
  }
  else if(choices.size() == 2 && choices[0] == 0 && choices[1] == 1){
    // check box (boolean choice)
    Fl_Check_Button *but = new Fl_Check_Button(1, 1, _itemWidth, 1);
    but->value(p.getValue());
    but->callback(onelab_check_button_cb, (void*)n);
    if(highlight) n->labelbgcolor(c);
    widget = but;
  }
  else{
    // general number input
    inputRange *but = new inputRange
      (1, 1, _itemWidth, 1, onelab::parameter::maxNumber());
    but->value(p.getValue());
    but->minimum(p.getMin());
    but->maximum(p.getMax());
    but->step(p.getStep());
    but->choices(p.getChoices());
    but->loop(p.getAttribute("Loop"));
    but->graph(p.getAttribute("Graph"));
    but->callback(onelab_input_range_cb, (void*)n);
    but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    if(highlight) but->color(c);
    widget = but;
  }

  _treeWidgets.push_back(widget);
  widget->copy_label(label.c_str());
  widget->align(FL_ALIGN_RIGHT);
  n->widget(widget);
  _tree->end();
}

void onelabWindow::_addParameter(onelab::string &p)
{
  std::string label = p.getShortName();
  std::vector<std::string> choices = p.getChoices();
  bool highlight = false;
  Fl_Color c;
  if(getFlColor(p.getAttribute("Highlight"), c)) highlight = true;

  Fl_Tree_Item *n = _tree->add(p.getName().c_str());
  n->labelsize(FL_NORMAL_SIZE + 5);
  _tree->begin();
  Fl_Widget *widget;
  if(p.getReadOnly()){
    // non-editable value
    Fl_Output *but = new Fl_Output(1, 1, _itemWidth, 1);
    but->value(p.getValue().c_str());
    if(highlight) but->color(c);
    widget = but;
  }
  else{
    // general string input
    Fl_Input_Choice *but = new Fl_Input_Choice(1, 1, _itemWidth, 1);
    std::vector<Fl_Menu_Item> menu;
    for(unsigned int j = 0; j < choices.size(); j++){
      char *str = strdup(choices[j].c_str());
      _treeStrings.push_back(str);
      bool divider = (p.getKind() == "file" &&
                      j == choices.size() - 1);
      Fl_Menu_Item it = {str, 0, 0, 0, divider ? FL_MENU_DIVIDER : 0};
      menu.push_back(it);
    }
    if(p.getKind() == "file"){
      Fl_Menu_Item it = {"Choose...", 0, onelab_input_choice_file_chooser_cb, (void*)n};
      menu.push_back(it);
      Fl_Menu_Item it2 = {"Edit...", 0, onelab_input_choice_file_edit_cb, (void*)n};
      menu.push_back(it2);
      if(GuessFileFormatFromFileName(p.getValue()) >= 0){
        Fl_Menu_Item it3 = {"Merge...", 0, onelab_input_choice_file_merge_cb, (void*)n};
        menu.push_back(it3);
      }
    }
    Fl_Menu_Item it = {0};
    menu.push_back(it);
    but->menubutton()->copy(&menu[0]);
    but->value(p.getValue().c_str());
    but->callback(onelab_input_choice_cb, (void*)n);
    but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    if(highlight) but->input()->color(c);
    widget = but;
  }

  _treeWidgets.push_back(widget);
  widget->copy_label(label.c_str());
  widget->align(FL_ALIGN_RIGHT);
  n->widget(widget);
  _tree->end();
}

void onelabWindow::rebuildTree()
{
  FL_NORMAL_SIZE -= _deltaFontSize;

  _itemWidth = (int)(0.45 * _tree->w());

  std::vector<std::string> closed;
  for (Fl_Tree_Item *n = _tree->first(); n; n = n->next())
    if(n->is_close()) closed.push_back(getPath(n));

  _tree->clear();
  _tree->sortorder(FL_TREE_SORT_ASCENDING);
  _tree->selectmode(FL_TREE_SELECT_NONE);

  for(unsigned int i = 0; i < _treeWidgets.size(); i++)
    Fl::delete_widget(_treeWidgets[i]);
  _treeWidgets.clear();
  for(unsigned int i = 0; i < _treeStrings.size(); i++)
    free(_treeStrings[i]);
  _treeStrings.clear();

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(!numbers[i].getVisible()) continue;
    _addParameter(numbers[i]);
  }

  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings);
  for(unsigned int i = 0; i < strings.size(); i++){
    if(!strings[i].getVisible()) continue;
    _addParameter(strings[i]);
  }

  for(Fl_Tree_Item *n = _tree->first(); n; n = n->next()){
    if(n->has_children()){
      _tree->begin();
      Fl_Box *but = new Fl_Box(1, 1, _itemWidth, 1);
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
      _treeWidgets.push_back(but);
      onelab::string o(n->label());
      but->copy_label(o.getShortName().c_str());
      n->widget(but);
      _tree->end();
    }
  }

  for(unsigned int i = 0; i < closed.size(); i++)
    _tree->close(closed[i].c_str());

  _tree->redraw();

  FlGui::check(); // necessary e.g. on windows to avoid "ghosting"

  FL_NORMAL_SIZE += _deltaFontSize;
}

void onelabWindow::checkForErrors(const std::string &client)
{
  if(Msg::GetErrorCount() > 0 && !CTX::instance()->expertMode){
    Msg::ResetErrorCounter();
    std::string msg
      (client + " reported an error: do you really want to continue?\n\n"
       "(To disable this warning in the future, select `Enable expert mode'\n"
       "in the option dialog.)");
    if(Msg::GetAnswer(msg.c_str(), 1, "Stop", "Continue") == 0)
      _stop = true;
  }
}

void onelabWindow::setButtonMode(const std::string &butt0, const std::string &butt1)
{
  if(butt0 == "check"){
    _butt[0]->activate();
    _butt[0]->label("Check");
    _butt[0]->callback(onelab_cb, (void*)"check");
  }
  else{
    _butt[0]->deactivate();
  }

  if(butt1 == "compute"){
    _butt[1]->activate();
    _butt[1]->label("Compute");
    _butt[1]->callback(onelab_cb, (void*)"compute");
    for(int i = 0; i < _gear->menu()->size(); i++)
      ((Fl_Menu_Item*)_gear->menu())[i].activate();
  }
  else if(butt1 == "stop"){
    _butt[1]->activate();
    _butt[1]->label("Stop");
    _butt[1]->callback(onelab_cb, (void*)"stop");
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < 1 || i > 5) ((Fl_Menu_Item*)_gear->menu())[i].deactivate();
  }
  else if(butt1 == "kill"){
    _butt[1]->activate();
    _butt[1]->label("Kill");
    _butt[1]->callback(onelab_cb, (void*)"kill");
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < 1 || i > 5) ((Fl_Menu_Item*)_gear->menu())[i].deactivate();
  }
  else{
    _butt[1]->deactivate();
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < 1 || i > 5) ((Fl_Menu_Item*)_gear->menu())[i].deactivate();
  }
}

bool onelabWindow::isBusy()
{
  std::string s(_butt[1]->label());
  if(s == "Compute") return false;
  return true;
}

void onelabWindow::rebuildSolverList()
{
  // update OneLab window title and gear menu
  _title = "OneLab";
  for(int i = _gear->menu()->size(); i >= _gearFrozenMenuSize - 1; i--)
    _gear->remove(i);
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++){
    if(it == onelab::server::instance()->firstClient()) _title += " -";
    if(it->second->isNetworkClient()){
      onelab::localNetworkClient *c = (onelab::localNetworkClient*)it->second;
      char tmp[256];
      sprintf(tmp, "%s/Choose executable", c->getName().c_str());
      _gear->add(tmp, 0, onelab_choose_executable_cb, (void*)c);
      sprintf(tmp, "%s/Remove", c->getName().c_str());
      _gear->add(tmp, 0, onelab_remove_solver_cb, (void*)c);
    }
    _title += " " + it->second->getName();
  }
  _gear->add("Add new client...", 0, onelab_add_solver_cb);
  _win->label(_title.c_str());

  // update Gmsh solver menu
  std::vector<std::string> names, exes, hosts;
  for(int i = 0; i < 5; i++){
    if(opt_solver_name(i, GMSH_GET, "").size()){
      names.push_back(opt_solver_name(i, GMSH_GET, ""));
      exes.push_back(opt_solver_executable(i, GMSH_GET, ""));
      hosts.push_back(opt_solver_remote_login(i, GMSH_GET, ""));
    }
  }
  for(unsigned int i = 0; i < 5; i++){
    if(i < names.size()){
      onelab::server::citer it = onelab::server::instance()->findClient(names[i]);
      if(it != onelab::server::instance()->lastClient())
        it->second->setIndex(i);
      opt_solver_name(i, GMSH_SET, names[i]);
      opt_solver_executable(i, GMSH_SET, exes[i]);
      opt_solver_remote_login(i, GMSH_SET, hosts[i]);
    }
    else{
      opt_solver_name(i, GMSH_SET, "");
      opt_solver_executable(i, GMSH_SET, "");
      opt_solver_remote_login(i, GMSH_SET, "");
    }
  }
  FlGui::instance()->menu->setContext(menu_solver, 0);
}

void onelabWindow::addSolver(const std::string &name, const std::string &executable,
                             const std::string &remoteLogin, int index)
{
  if(onelab::server::instance()->findClient(name) !=
     onelab::server::instance()->lastClient()) return; // solver already exists

  // unregister the other non-local clients so we keep only the new one
  std::vector<onelab::client*> networkClients;
  for(onelab::server::citer it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++)
    if(it->second->isNetworkClient())
      networkClients.push_back(it->second);
  for(unsigned int i = 0; i < networkClients.size(); i++){
    onelab::server::instance()->unregisterClient(networkClients[i]);
    delete networkClients[i];
  }

  // create and register the new client
  onelab::localNetworkClient *c = new onelab::localNetworkClient(name, executable,
                                                                 remoteLogin);
  c->setIndex(index);
  opt_solver_name(index, GMSH_SET, name);
  if(executable.empty())
    onelab_choose_executable_cb(0, (void *)c);
  opt_solver_remote_login(index, GMSH_SET, remoteLogin);

  FlGui::instance()->onelab->rebuildSolverList();

  // initialize the client
  onelab_cb(0, (void*)"initialize");
}

void onelabWindow::removeSolver(const std::string &name)
{
  onelab::server::citer it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()){
    onelab::client *c = it->second;
    if(c->isNetworkClient()){
      onelab::server::instance()->unregisterClient(c);
      if(c->getIndex() >= 0 && c->getIndex() < 5){
        opt_solver_name(c->getIndex(), GMSH_SET, "");
        opt_solver_executable(c->getIndex(), GMSH_SET, "");
        opt_solver_remote_login(c->getIndex(), GMSH_SET, "");
      }
      delete c;
    }
  }
  FlGui::instance()->onelab->rebuildSolverList();
}

void solver_cb(Fl_Widget *w, void *data)
{
  Msg::ResetErrorCounter();

  int num = (intptr_t)data;
  if(num >= 0){
    std::string name = opt_solver_name(num, GMSH_GET, "");
    std::string exe = opt_solver_executable(num, GMSH_GET, "");
    std::string host = opt_solver_remote_login(num, GMSH_GET, "");
    FlGui::instance()->onelab->addSolver(name, exe, host, num);
  }
  else
    FlGui::instance()->onelab->rebuildSolverList();

  if(FlGui::instance()->onelab->isBusy())
    FlGui::instance()->onelab->show();
  else
    onelab_cb(0, (void*)"check");
}

#else

#if defined(HAVE_ONELAB)

bool onelab::localNetworkClient::run()
{
  Msg::Error("The solver interface requires OneLab and FLTK 1.3");
  return false;
}

bool onelab::localNetworkClient::kill()
{
  Msg::Error("The solver interface requires OneLab and FLTK 1.3");
  return false;
}

#endif

void solver_cb(Fl_Widget *w, void *data)
{
  Msg::Error("The solver interface requires OneLab and FLTK 1.3");
}

#endif
