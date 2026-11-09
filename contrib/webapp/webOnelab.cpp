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
#include "ColorContrast.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
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

  // the solvers of the server the loops run (not the clients a solver adds
  // while it runs; see onelabUtils::isAutoRunSolver())
  std::vector<gmshInProcessClient *> solvers()
  {
    onelab::server *s = onelab::server::instance();
    std::vector<gmshInProcessClient *> v;
    for(auto it = s->firstClient(); it != s->lastClient(); it++) {
      auto *c = dynamic_cast<gmshInProcessClient *>(*it);
      if(c && onelabUtils::isAutoRunSolver(c)) v.push_back(c);
    }
    return v;
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

// the solvers forgotten, as a model starts, or none (Clear in the page): the
// next file opened adds those it asks for (see addSolver())
EMSCRIPTEN_KEEPALIVE void gmshWebOnelabForgetSolvers()
{
  onelab::server *s = onelab::server::instance();
  std::vector<gmshInProcessClient *> v;
  for(auto it = s->firstClient(); it != s->lastClient(); it++)
    if(auto *c = dynamic_cast<gmshInProcessClient *>(*it)) v.push_back(c);
  // (each unregisters itself)
  for(auto *c : v) delete c;
}

// The ONELAB loop of the graphical interface (onelab_cb()) in steps, for a
// page that runs the solvers in a web worker, as the graphical interface runs
// them in processes of their own (onelab.html and solver.js): the page starts,
// then for each pass runs Gmsh here and the solvers it is given in the worker,
// the database going along, then asks for the next pass. Starting, with
// "check", "compute" or "reset" (whose passes are "check"):
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
    onelabUtils::setSolverAction(c, action);
    if(json.size() > 1) json += ",";
    json += "{\"name\":" + JsonString(c->getName()) + ",\"args\":[";
    std::vector<std::string> args = c->commandLine();
    for(std::size_t i = 0; i < args.size(); i++)
      json += (i ? "," : "") + JsonString(args[i]);
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

// the whole loop, with the solvers run here (run_models.mjs): returns the
// number of errors
EMSCRIPTEN_KEEPALIVE int gmshWebOnelab(const char *what)
{
  std::string pass = (std::string(what) == "reset") ? "check" : what;
  gmshWebOnelabStart(what);
  do {
    gmshWebOnelabGmsh(pass.c_str());
    for(auto *c : solvers()) c->run();
  } while(gmshWebOnelabNext(pass.c_str()));
  return Msg::GetErrorCount();
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
  if(n.fromJSON(json)) return onelabUtils::setParameter(n) & 3;
  onelab::string s;
  if(s.fromJSON(json)) return onelabUtils::setParameter(s) & 3;
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

// that colour as the graphical interface shows it (see ColorContrast.h), on
// the background bg with the text fg of the page (as 0xrrggbb), in dark mode
// or not: as a text (what = 0), as the background of a field (1) or as the
// text on that field (2)
EMSCRIPTEN_KEEPALIVE int gmshWebReadableColor(int rgb, int bg, int fg, int dark,
                                              int what)
{
  if(what == 0) return ReadableTextColor(rgb, bg, bg, dark);
  unsigned int fill = ReadableFillColor(rgb, fg, dark);
  return what == 1 ? fill : ContrastingColor(fill);
}

} // extern "C"

#endif
