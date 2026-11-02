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
    // the solvers (not the clients a solver adds while it runs)
    onelab::server *s = onelab::server::instance();
    std::vector<onelab::localNetworkClient *> solvers;
    for(auto it = s->firstClient(); it != s->lastClient(); it++) {
      auto *c = dynamic_cast<onelab::localNetworkClient *>(*it);
      if(c && c->getName().find("NoAutoRun") == std::string::npos)
        solvers.push_back(c);
    }
    for(auto *c : solvers) {
      onelabUtils::guessModelName(c);
      onelab::string o(c->getName() + "/Action", action);
      o.setVisible(false);
      o.setNeverChanged(true);
      s->set(o);
      c->run();
      if(action == "compute") s->setChanged(0, c->getName());
    }
    onelabUtils::updateGraphs();
  } while(action == "compute" && onelabUtils::incrementLoops());
  return Msg::GetErrorCount();
}

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

} // extern "C"

#endif
