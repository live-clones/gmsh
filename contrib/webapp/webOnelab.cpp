// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The ONELAB web app: GetDP linked in the module and run in-process, sharing
// Gmsh's ONELAB server (see gmshInProcessClient), and what the page calls
// (through ccall) to run the ONELAB loop and change parameters as the
// graphical interface does. The parameters are read through the Gmsh API
// (gmsh.onelab.get, in JSON).

#if defined(__EMSCRIPTEN__)

#include <algorithm>
#include <cstdlib>
#include <emscripten.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "OS.h"
#include "onelab.h"
#include "onelabUtils.h"
#include "gmshLocalNetworkClient.h"
#include "GmshGlobal.h"
#include "OpenFile.h"
#include "getdp.h"

namespace {
  // GetDP is known as soon as the module starts, so that opening a .pro file
  // and running the solver (in the page or with gmsh.onelab.run()) uses it.
  // Its direct solver is UMFPACK (MUMPS needs Fortran), whose default
  // unsymmetric strategy needs ten times the memory of MUMPS on 3D models
  // (28 GB instead of 0.8 for GetDP's tutorial 10): the symmetric strategy
  // with METIS brings it to 2 GB (the options of a model still apply after)
  struct registerGetDP {
    registerGetDP()
    {
      onelabUtils::setInProcessSolver("GetDP", getdp);
      setenv("PETSC_OPTIONS",
             "-mat_umfpack_strategy SYMMETRIC -mat_umfpack_ordering METIS", 0);
    }
  } _registerGetDP;

  // the client of the solver the last file opened asked for (a .pro file
  // asks for GetDP), as the graphical interface adds it
  void addSolver()
  {
    int num = CTX::instance()->launchSolverAtStartup;
    if(num < 0) return;
    CTX::instance()->launchSolverAtStartup = -1;
    std::string name = opt_solver_name(num, GMSH_GET, "");
    onelabUtils::inProcessSolver solver = onelabUtils::getInProcessSolver(name);
    if(!solver) {
      Msg::Error("Solver '%s' is not available in the web app", name.c_str());
      return;
    }
    onelab::server *s = onelab::server::instance();
    if(s->findClient(name) == s->lastClient()) {
      gmshInProcessClient *c = new gmshInProcessClient(name, solver);
      c->setIndex(num);
    }
  }

  // a parameter changed in the page, as in the tree of the graphical
  // interface: the Gmsh option it stands for, the actions it asks for
  template <class T> int setParameter(T &p)
  {
    onelab::server *s = onelab::server::instance();
    std::vector<T> ps;
    s->get(ps, p.getName());
    T old = ps.empty() ? p : ps[0];
    int ret = 0;
    std::string opt = p.getAttribute("GmshOption");
    if(opt.size()) {
      if(onelabUtils::serverAction(opt)) // for backward compatibility
        ret = 2;
      else
        onelabUtils::setGmshOption(p);
    }
    if(onelabUtils::serverAction(p.getAttribute("ServerAction"))) ret = 2;
    onelabUtils::performServerAction(p);
    s->set(p);
    if(onelabUtils::autoCheck(old, p)) ret |= 1;
    return ret;
  }

  // the solvers of the server (not the clients a solver adds while it runs)
  std::vector<gmshInProcessClient *> solvers()
  {
    onelab::server *s = onelab::server::instance();
    std::vector<gmshInProcessClient *> v;
    for(auto it = s->firstClient(); it != s->lastClient(); it++) {
      auto *c = dynamic_cast<gmshInProcessClient *>(*it);
      if(c && c->getName().find("NoAutoRun") == std::string::npos)
        v.push_back(c);
    }
    return v;
  }

  // a solver about to run: the action it is asked for, in the database
  void setAction(gmshInProcessClient *c, const std::string &action)
  {
    onelabUtils::guessModelName(c);
    onelab::string o(c->getName() + "/Action", action);
    o.setVisible(false);
    o.setNeverChanged(true);
    onelab::server::instance()->set(o);
  }

  std::string quoted(const std::string &s)
  {
    std::string q = "\"";
    for(char c : s) {
      if(c == '"' || c == '\\') q += '\\';
      if(c == '\n') {
        q += "\\n";
        continue;
      }
      if(c == '\t') {
        q += "\\t";
        continue;
      }
      q += c;
    }
    return q + "\"";
  }

  // in a web worker running a solver: what GetDP asks to show, given to the
  // page (solver.js). GetDP merges such a file in the program, as the files
  // it reads, then asks for a render: the file is then the last one merged.
  // And the database, when GetDP asks for a refresh (Gmsh/Action, e.g. after
  // adding a value to an output drawn on a graph), no more than every quarter
  // of a second, as the graphical interface (gmshLocalNetworkClient)
  class solverMessages : public GmshMessage {
  public:
    void operator()(std::string level, std::string message)
    {
      if(level == "RequestRender") {
        const std::string &file = GmshLastMergedPostProcessingFile();
        if(file.empty()) return;
        EM_ASM(
          {
            if(globalThis.gmshSolverMerge)
              globalThis.gmshSolverMerge(UTF8ToString($0));
          },
          file.c_str());
        return;
      }
      static double lastRefresh = 0.;
      double now = TimeOfDay();
      if(now - lastRefresh < 0.25) return;
      std::vector<onelab::string> ps;
      onelab::server::instance()->get(ps, "Gmsh/Action");
      if(ps.empty() || ps[0].getValue() != "refresh") return;
      ps[0].setValue("");
      onelab::server::instance()->set(ps[0]);
      lastRefresh = now;
      EM_ASM({
        if(globalThis.gmshSolverRefresh) globalThis.gmshSolverRefresh();
      });
    }
  };
} // namespace

extern "C" {

// run "check", "compute" (with the loops over parameters) or "reset" with
// Gmsh and the solvers, as onelab_cb() of the graphical interface; returns
// the number of errors
EMSCRIPTEN_KEEPALIVE int gmshWebOnelab(const char *what)
{
  std::string action(what);
  addSolver();
  if(action == "reset") {
    onelabUtils::resetDb(true);
    action = "check";
  }
  Msg::ResetErrorCounter();
  if(action == "compute") onelabUtils::initializeLoops();
  do {
    onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh);
    for(auto *c : solvers()) {
      setAction(c, action);
      c->run();
      if(action == "compute")
        onelab::server::instance()->setChanged(0, c->getName());
    }
    onelabUtils::updateGraphs();
  } while(action == "compute" && onelabUtils::incrementLoops());
  return Msg::GetErrorCount();
}

// The same loop in steps, for a page that runs the solvers in a web worker,
// as the graphical interface runs them in processes of their own (onelab.html
// and solver.js): the page starts, then for each pass runs Gmsh here and the
// solvers it is given in the worker, the database going along, then asks for
// the next pass. Starting, with "check", "compute" or "reset":
EMSCRIPTEN_KEEPALIVE void gmshWebOnelabStart(const char *what)
{
  std::string action(what);
  addSolver();
  if(action == "reset") onelabUtils::resetDb(true);
  Msg::ResetErrorCounter();
  if(action == "compute") onelabUtils::initializeLoops();
}

// Gmsh's part of a pass ("check" or "compute"), and the solvers to run then,
// in JSON: [{"name":..., "args":[...]}]
EMSCRIPTEN_KEEPALIVE const char *gmshWebOnelabGmsh(const char *what)
{
  std::string action(what);
  onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh);
  static std::string json;
  json = "[";
  for(auto *c : solvers()) {
    setAction(c, action);
    if(json.size() > 1) json += ",";
    json += "{\"name\":" + quoted(c->getName()) + ",\"args\":[";
    std::vector<std::string> args = c->commandLine();
    for(std::size_t i = 0; i < args.size(); i++)
      json += (i ? "," : "") + quoted(args[i]);
    json += "]}";
  }
  json += "]";
  return json.c_str();
}

// the end of a pass, once the solvers have run and their database is back:
// returns 1 if there is another pass (a loop over parameters)
EMSCRIPTEN_KEEPALIVE int gmshWebOnelabNext(const char *what)
{
  std::string action(what);
  if(action == "compute")
    for(auto *c : solvers())
      onelab::server::instance()->setChanged(0, c->getName());
  onelabUtils::updateGraphs();
  return (action == "compute" && onelabUtils::incrementLoops()) ? 1 : 0;
}

// the errors since the start
EMSCRIPTEN_KEEPALIVE int gmshWebErrorCount() { return Msg::GetErrorCount(); }

// In the web worker: run a solver with the arguments of gmshWebOnelabGmsh()
// (separated by new lines), with the database the page sent; the files it
// asks to show go to the page as they are written. Returns the errors
EMSCRIPTEN_KEEPALIVE int gmshWebSolve(const char *argv)
{
  std::vector<std::string> args;
  std::string a(argv);
  for(std::size_t start = 0, end; start < a.size(); start = end + 1) {
    end = a.find('\n', start);
    if(end == std::string::npos) end = a.size();
    args.push_back(a.substr(start, end - start));
  }
  if(args.empty()) return 1;
  onelabUtils::inProcessSolver solver =
    onelabUtils::getInProcessSolver(args[0]);
  if(!solver) {
    Msg::Error("Solver '%s' is not available in the web app", args[0].c_str());
    return 1;
  }
  static solverMessages messages;
  Msg::SetCallback(&messages);
  Msg::ResetErrorCounter();
  int errors = 0;
  try {
    errors = solver(args, onelab::server::instance());
  } catch(...) {
    Msg::Error("'%s' stopped on an error", args[0].c_str());
    errors = 1;
  }
  Msg::SetCallback(nullptr);
  return std::max(errors, Msg::GetErrorCount());
}

// On the page: show a file a solver wrote, as the graphical interface does
// when a solver asks for it (gmshLocalNetworkClient)
EMSCRIPTEN_KEEPALIVE void gmshWebMergeFile(const char *name)
{
  if(!CTX::instance()->solver.autoMergeFile) return;
  bool changedBeforeMerge = onelab::server::instance()->getChanged("Gmsh");
  MergePostProcessingFile(name, CTX::instance()->solver.autoShowViews,
                          CTX::instance()->solver.autoShowLastStep, true);
  onelab::server::instance()->setChanged(changedBeforeMerge, "Gmsh");
}

// On the page: the X-Y graphs of the parameters drawn on them (their "Graph"
// attribute), made again from their values, as the graphical interface does
// on a refresh
EMSCRIPTEN_KEEPALIVE void gmshWebUpdateGraphs() { onelabUtils::updateGraphs(); }

// change a parameter, given in JSON as gmsh.onelab.get() gives them: returns
// 1 if the model is to be checked, 2 if other parameters were reset, or -1
EMSCRIPTEN_KEEPALIVE int gmshWebOnelabSet(const char *json)
{
  onelab::number n;
  if(n.fromJSON(json)) return setParameter(n);
  onelab::string s;
  if(s.fromJSON(json)) return setParameter(s);
  return -1;
}

// extract a zip archive (e.g. a model with its included files) in a directory
EMSCRIPTEN_KEEPALIVE void gmshWebUnzip(const char *fileName, const char *dir)
{
  UnzipFile(fileName, dir);
}

// the colour of a name as the graphical interface reads it (the "Highlight"
// of a parameter, an X11 name such as LightSteelBlue1), as 0xrrggbb, or -1
EMSCRIPTEN_KEEPALIVE int gmshWebColor(const char *name)
{
  int r, g, b;
  if(!GetRGBForString(name, r, g, b)) return -1;
  return (r << 16) | (g << 8) | b;
}

} // extern "C"

#endif
