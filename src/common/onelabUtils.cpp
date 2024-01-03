// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_ONELAB)

#include "GmshDefines.h"
#include "GModel.h"
#include "Context.h"
#include "Options.h"
#include "OS.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "StringUtils.h"
#include "gmshLocalNetworkClient.h"
#include "onelabUtils.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#include "onelabGroup.h"
#include "drawContext.h"
#endif

namespace onelabUtils {

  // get command line arguments for the client if "UseCommandLine" is set for
  // this client
  std::vector<std::string> getCommandLine(onelab::client *c)
  {
    std::vector<std::string> args;
    std::string name(c->getName());
    std::vector<onelab::number> n;
    c->get(n, name + "/Use command line");
    if(n.size() && n[0].getValue()) {
      std::vector<onelab::string> ps;
      c->get(ps, name + "/Action");
      std::string action = (ps.empty() ? "" : ps[0].getValue());
      c->get(ps, name + "/Model name");
      std::string modelName = (ps.empty() ? "" : ps[0].getValue());
      c->get(ps, name + "/9CheckCommand");
      std::string checkCommand = (ps.empty() ? "" : ps[0].getValue());
      c->get(ps, name + "/9ComputeCommand");
      std::string computeCommand = (ps.empty() ? "" : ps[0].getValue());
      if(modelName.size()) args.push_back(" \"" + modelName + "\"");
      if(action == "check")
        args.push_back(" " + checkCommand);
      else if(action == "compute")
        args.push_back(" " + computeCommand);
      // Propagate -setnumber/-setnumber gmsh option to the client. (Is this a
      // good idea?)
      std::ostringstream sstream;
      sstream.precision(16);
      std::map<std::string, std::vector<double> > cln(
        Msg::GetCommandLineNumbers());
      for(auto it =
            cln.begin();
          it != cln.end(); it++) {
        if(it->second.size() == 1) {
          sstream << " -setnumber " << it->first << " " << it->second[0];
        }
        else {
          sstream << " -setlistofnumbers " << it->first;
          for(std::size_t i = 0; i < it->second.size(); i++)
            sstream << " " << it->second[i];
        }
      }
      std::map<std::string, std::string> cls(Msg::GetCommandLineStrings());
      for(auto it = cls.begin();
          it != cls.end(); it++)
        sstream << " -setstring " << it->first << " " << it->second;
      args.push_back(sstream.str());
    }
    return args;
  }

  std::string getMshFileName(onelab::client *c)
  {
    std::string name;
    std::vector<onelab::string> ps;
    c->get(ps, "Gmsh/MshFileName");
    if(ps.size()) {
      name = ps[0].getValue();
    }
    else {
      name = CTX::instance()->outputFileName;
      if(name.empty()) {
        if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
          name = GetDefaultFileName(FORMAT_MSH);
        else
          name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
      }
      onelab::string o("Gmsh/MshFileName", name, "Mesh name");
      o.setKind("file");
      o.setAttribute("Closed", "1");
      if(!CTX::instance()->showModuleMenu)
        o.setVisible(false);
      c->set(o);
    }
    // we could keep track of mesh file name in "Output files" so we could
    // archive the mesh automatically:
    /*
      onelab::string copy("Gmsh/9Output files", name, "Mesh name");
      copy.setKind("file");
      copy.setVisible(false);
      c->set(copy);
    */
    return name;
  }

  void guessModelName(onelab::client *c)
  {
    std::string geo = GModel::current()->getFileName();
    std::vector<onelab::number> n;
    c->get(n, c->getName() + "/Guess model name");
    if(n.size() && n[0].getValue()) {
      std::vector<onelab::string> ps;
      c->get(ps, c->getName() + "/Model name");
      if(ps.empty()) {
        std::vector<std::string> split = SplitFileName(geo);
        std::string ext = "";
        onelab::server::instance()->get(ps, c->getName() + "/File extension");
        if(ps.size()) ext = ps[0].getValue();
        std::string name(split[0] + split[1] + ext);
        onelab::string o(c->getName() + "/Model name", name);
        o.setKind("file");
        o.setAttribute("Persistent", "1");
        c->set(o);
        geo += std::string(" - ") + name;
      }
      else {
        geo += std::string(" - ") + ps[0].getValue();
      }
    }
    Msg::SetWindowTitle(geo);
  }

  void initializeLoop(const std::string &level)
  {
    bool changed = false;
    std::vector<onelab::number> numbers;
    onelab::server::instance()->get(numbers);
    for(std::size_t i = 0; i < numbers.size(); i++) {
      if(numbers[i].getAttribute("Loop") == level) {
        if(numbers[i].getChoices().size() > 1) {
          numbers[i].setIndex(0);
          numbers[i].setValue(numbers[i].getChoices()[0]);
          onelab::server::instance()->set(numbers[i]);
          changed = true;
        }
        else if(numbers[i].getStep() > 0) {
          if(numbers[i].getMin() != -onelab::parameter::maxNumber()) {
            numbers[i].setValue(numbers[i].getMin());
            numbers[i].setIndex(0); // indicates we are in a loop
            std::vector<double> choices;
            numbers[0].setChoices(choices);
            onelab::server::instance()->set(numbers[i]);
            changed = true;
          }
        }
        else if(numbers[i].getStep() < 0) {
          if(numbers[i].getMax() != onelab::parameter::maxNumber()) {
            numbers[i].setIndex(0); // indicates we are in a loop
            std::vector<double> choices;
            numbers[0].setChoices(choices);
            numbers[i].setValue(numbers[i].getMax());
            onelab::server::instance()->set(numbers[i]);
            changed = true;
          }
        }
      }
    }

    // force this to make sure that we remesh, even if a mesh exists on disk
    if(changed) setFirstComputationFlag(false);
  }

  bool incrementLoop(const std::string &level)
  {
    const double eps = 1.e-15; // for roundoff
    // called at the end of the do{...} while(incrementLoops);
    bool recompute = false, loop = false;
    std::vector<onelab::number> numbers;
    onelab::server::instance()->get(numbers);
    for(std::size_t i = 0; i < numbers.size(); i++) {
      if(numbers[i].getAttribute("Loop") == level) {
        loop = true;

        if(numbers[i].getChoices().size() > 1) {
          int j = numbers[i].getIndex() + 1;
          if((j >= 0) && (j < (int)numbers[i].getChoices().size())) {
            numbers[i].setValue(numbers[i].getChoices()[j]);
            numbers[i].setIndex(j);
            onelab::server::instance()->set(numbers[i]);
            Msg::Info("Recomputing with %dth choice %s=%g", j,
                      numbers[i].getName().c_str(), numbers[i].getValue());
            recompute = true;
          }
        }
        else if(numbers[i].getStep() > 0) {
          int j = numbers[i].getIndex() + 1;
          double val = numbers[i].getValue() + numbers[i].getStep();
          if(numbers[i].getMax() != onelab::parameter::maxNumber() &&
             val <= numbers[i].getMax() * (1 + eps)) {
            numbers[i].setValue(val);
            numbers[i].setIndex(j);
            onelab::server::instance()->set(numbers[i]);
            Msg::Info("Recomputing with new step %s=%g",
                      numbers[i].getName().c_str(), numbers[i].getValue());
            recompute = true;
          }
          else
            numbers[i].setIndex(numbers[i].getMax()); // FIXME makes sense?
        }
        else if(numbers[i].getStep() < 0) {
          int j = numbers[i].getIndex() + 1;
          double val = numbers[i].getValue() + numbers[i].getStep();
          if(numbers[i].getMin() != -onelab::parameter::maxNumber() &&
             val >= numbers[i].getMin() * (1 - eps)) {
            numbers[i].setValue(val);
            numbers[i].setIndex(j);
            onelab::server::instance()->set(numbers[i]);
            Msg::Info("Recomputing with new step %s=%g",
                      numbers[i].getName().c_str(), numbers[i].getValue());
            recompute = true;
          }
          else
            numbers[i].setIndex(numbers[i].getMin()); // FIXME makes sense?
        }
      }
    }

    if(loop && !recompute) // end of this loop level
      initializeLoop(level);

    return recompute;
  }

  std::vector<double> getRange(onelab::number &p)
  {
    const double eps = 1.e-15; // for roundoff
    std::vector<double> v;
    if(p.getChoices().size()) {
      v = p.getChoices();
    }
    else if(p.getMin() != -onelab::parameter::maxNumber() &&
            p.getMax() != onelab::parameter::maxNumber()) {
      if(p.getStep() > 0) {
        for(double d = p.getMin(); d <= p.getMax() * (1 + eps);
            d += p.getStep())
          v.push_back(d);
      }
      else if(p.getStep() < 0) {
        for(double d = p.getMin(); d <= p.getMax() * (1 + eps);
            d -= p.getStep())
          v.push_back(d);
      }
    }
    return v;
  }

  bool updateGraph(const std::string &graphNum)
  {
    bool changed = false;
#if defined(HAVE_POST)
    PView *view = nullptr;

    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(PView::list[i]->getData()->getFileName() == "ONELAB" + graphNum) {
        view = PView::list[i];
        break;
      }
    }

    int num = atoi(graphNum.c_str());
    std::vector<double> x, y;
    std::string xName, yName;
    int graphType = 3;
    std::vector<onelab::number> numbers;
    onelab::server::instance()->get(numbers);
    for(std::size_t i = 0; i < numbers.size(); i++) {
      std::string v = numbers[i].getAttribute("Graph");
      v.resize(36, '0');
      if(v[2 * num] != '0') {
        x = getRange(numbers[i]);
        xName = numbers[i].getShortName();
      }
      if(v[2 * num + 1] != '0') {
        y = getRange(numbers[i]);
        yName = numbers[i].getShortName();
        char t = v[2 * num + 1];
        graphType =
          (t == '1') ? 1 : (t == '2') ? 2 : (t == '3') ? 3 : (t == '4') ? 4 : 3;
      }
    }
    if(x.empty()) {
      xName.clear();
      for(std::size_t i = 0; i < y.size(); i++) x.push_back(i);
    }
    if(x.size() && y.size()) {
      if(x.size() != y.size())
        Msg::Info("X-Y data series have different length (%d != %d)",
                  (int)x.size(), (int)y.size());
      if(view) {
        view->getData()->setXY(x, y);
        view->getData()->setName(yName);
        view->getOptions()->axesLabel[0] = xName;
        view->setChanged(true);
      }
      else {
        view = new PView(xName, yName, x, y);
        view->getData()->setFileName("ONELAB" + graphNum);
        view->getOptions()->intervalsType = graphType;
        view->getOptions()->autoPosition = num / 2 + 2;
      }
      changed = true;
    }
    else if(view) {
      delete view;
      changed = true;
    }
#endif
    return changed;
  }

  static bool _firstComputation = true;
  void setFirstComputationFlag(bool val) { _firstComputation = val; }
  bool getFirstComputationFlag() { return _firstComputation; }
  bool runGmshClient(const std::string &action, int meshAuto)
  {
    bool redraw = false;

    auto it = onelab::server::instance()->findClient("Gmsh");
    if(it == onelab::server::instance()->lastClient()) return redraw;

    // do nothing in case of a metamodel
    std::vector<onelab::number> pn;
    onelab::server::instance()->get(pn, "IsPyMetamodel");
    if(pn.size() && pn[0].getValue()) return redraw;
    onelab::server::instance()->get(pn, "IsMetamodel");
    if(pn.size() && pn[0].getValue()) return redraw;

    // do nothing if there is no file name associated with the model (e.g. when
    // Gmsh is run interactively through the API and no model file is opened)
    if(GModel::current()->getFileName().empty()) return redraw;

    onelab::client *c = *it;
    std::string mshFileName = onelabUtils::getMshFileName(c);

    int changed = onelab::server::instance()->getChanged("Gmsh");
    // if = 0: do nothing
    //    = 1: only save mesh (e.g. if physiscals changed)
    //    = 2: mesh and save mesh (e.g. if char length changed)
    //    > 2: reload geometry, mesh and save mesh (other things have changed)

    if(meshAuto < 0) { // the geometry creates the mesh
      meshAuto = 0;
      if(changed) changed = 3;
    }

    Msg::SetOnelabAction(action);

    if(action == "initialize") {
      // nothing to do
    }
    else if(action == "reset") {
      setFirstComputationFlag(false);
      // nothing more to do: "check" will be called right afterwards
    }
    else if(action == "check_always") {
      redraw = true;
      OpenProject(GModel::current()->getFileName());
      onelab::server::instance()->thresholdChanged(2, "Gmsh");
    }
    else if(action == "check") {
      if(changed > 2) {
        redraw = true;
        OpenProject(GModel::current()->getFileName());
        onelab::server::instance()->thresholdChanged(2, "Gmsh");
      }
    }
    else if(action == "compute") {
      if(changed) {
        redraw = true;
        if(changed > 2) {
          OpenProject(GModel::current()->getFileName());
        }
        if(getFirstComputationFlag() && !StatFile(mshFileName) &&
           meshAuto != 2) {
          Msg::Info("Skipping mesh generation: assuming '%s' is up-to-date "
                    "(use Solver.AutoMesh=2 to force mesh generation)",
                    mshFileName.c_str());
        }
        else if(!GModel::current()->empty() && meshAuto) {
          if(changed > 1 || StatFile(mshFileName) ||
             (!StatFile(mshFileName) && GModel::current()->getMeshStatus() <
                                          GModel::current()->getDim())) {
            GModel::current()->deleteMesh();
            GModel::current()->mesh(3);
          }
          CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
        }
      }
      else if(StatFile(mshFileName)) {
        // mesh+save if the mesh file does not exist
        if(meshAuto) {
          redraw = true;
          if(changed > 1 ||
             GModel::current()->getMeshStatus() < GModel::current()->getDim()) {
            GModel::current()->deleteMesh();
            GModel::current()->mesh(3);
          }
          CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
        }
      }
      setFirstComputationFlag(false);
      onelab::server::instance()->setChanged(0, "Gmsh");
    }

    Msg::SetOnelabAction("");

    return redraw;
  }

  void runClient(const std::string &name, const std::string &command)
  {
    if(name.size()) {
      // try to run as a subclient of Gmsh; or if not as a new client
      onelab::remoteNetworkClient *c =
        dynamic_cast<onelab::remoteNetworkClient *>(Msg::GetOnelabClient());
      if(c) {
        c->runSubClient(name, command);
      }
      else {
        gmshLocalNetworkClient client(name, command, "", true);
        client.run();
      }
    }
    else {
      // try to run a client that might have been selected previously, e.g. by
      // opening a file with known client extension (like ".pro")
      int num = CTX::instance()->launchSolverAtStartup;
      std::string name, exe, host;
      if(num == -1) {
        // no client to run
        return;
      }
      else if(num == -2) {
        // just run local Gmsh client
      }
      else if(num >= 0) {
        // run local Gmsh client + solver num
        name = opt_solver_name(num, GMSH_GET, "");
        exe = opt_solver_executable(num, GMSH_GET, "");
        host = opt_solver_remote_login(num, GMSH_GET, "");
        if(exe.empty()) {
          Msg::Error("Solver executable name not provided");
          return;
        }
      }
      else {
        Msg::Error("Unknown client to run in batch mode (%d)", num);
        return;
      }

      onelab::number n("0Metamodel/Batch", CTX::instance()->batch);
      n.setVisible(false);
      onelab::server::instance()->set(n);

      // create client
      onelab::localNetworkClient *c = nullptr;
      onelab::string o;
      if(name.size()) {
        c = new gmshLocalNetworkClient(name, exe, host);
        c->setIndex(num);
        o = c->getName() + "/Action";
      }

      // initialize
      onelabUtils::runGmshClient("initialize",
                                 CTX::instance()->solver.autoMesh);
      if(c) {
        o.setValue("initialize");
        onelab::server::instance()->set(o);
        c->run();
      }

      // load db
      if(CTX::instance()->solver.autoLoadDatabase) {
        std::vector<std::string> split =
          SplitFileName(GModel::current()->getFileName());
        std::string db = split[0] + split[1] + ".db";
        if(!StatFile(db)) loadDb(db);
      }

      // check
      onelabUtils::runGmshClient("check", CTX::instance()->solver.autoMesh);
      if(c) {
        onelabUtils::guessModelName(c);
        o.setValue("check");
        onelab::server::instance()->set(o);
        c->run();
      }

      // compute
      initializeLoops();
      do {
        onelabUtils::runGmshClient("compute", CTX::instance()->solver.autoMesh);
        if(c) {
          onelabUtils::guessModelName(c);
          o.setValue("compute");
          onelab::server::instance()->set(o);
          c->run();
          onelab::server::instance()->setChanged(0, c->getName());
        }
      } while(incrementLoops());

      if(CTX::instance()->solver.autoSaveDatabase ||
         CTX::instance()->solver.autoArchiveOutputFiles) {
        std::vector<std::string> split =
          SplitFileName(GModel::current()->getFileName());
        std::string db = split[0] + split[1] + ".db";
        if(CTX::instance()->solver.autoArchiveOutputFiles)
          archiveOutputFiles(db);
        if(CTX::instance()->solver.autoSaveDatabase) saveDb(db);
      }
    }
  }

  // update x using y, giving priority to any settings in x that can be set in
  // the GUI. The value of x is only changed if y is read-only.
  double updateNumber(onelab::number &x, onelab::number &y,
                      const bool readOnlyRange)
  {
    bool noRange = true, noChoices = true, noLoop = true;
    bool noGraph = true, noClosed = true;

    if(y.getReadOnly()) {
      x.setValue(y.getValue());
      x.setReadOnly(true);
    }
    double val = x.getValue();

    // keep track of these attributes, which can be changed server-side (unless,
    // for the range/choices, when explicitly setting these attributes as
    // ReadOnly)
    if(!readOnlyRange) {
      if(x.getMin() != -onelab::parameter::maxNumber() ||
         x.getMax() != onelab::parameter::maxNumber() || x.getStep() != 0.)
        noRange = false;
      if(x.getChoices().size()) noChoices = false;
    }
    if(x.getAttribute("Loop").size()) noLoop = false;
    if(x.getAttribute("Graph").size()) noGraph = false;
    if(x.getAttribute("Closed").size()) noClosed = false;

    if(noRange) {
      bool noRangeEither = true;
      if(y.getMin() != -onelab::parameter::maxNumber() ||
         y.getMax() != onelab::parameter::maxNumber() || y.getStep() != 0.)
        noRangeEither = false;
      if(!noRangeEither) {
        x.setMin(y.getMin());
        x.setMax(y.getMax());
      }
      else {
        // if no range/min/max/step info is provided, try to compute a
        // reasonnable range and step (this makes the GUI much nicer to use)
        bool isInteger = (floor(val) == val);
        double fact = isInteger ? 5. : 20.;
        if(val > 0) {
          x.setMin(val / fact);
          x.setMax(val * fact);
          x.setStep((x.getMax() - x.getMin()) / 100.);
        }
        else if(val < 0) {
          x.setMin(val * fact);
          x.setMax(val / fact);
          x.setStep((x.getMax() - x.getMin()) / 100.);
        }
        if(val && isInteger) {
          x.setMin((int)x.getMin());
          x.setMax((int)x.getMax());
          x.setStep((int)x.getStep());
        }
      }
    }
    if(noChoices) {
      x.setChoices(y.getChoices());
      x.setValueLabels(y.getValueLabels());
    }
    if(noLoop) x.setAttribute("Loop", y.getAttribute("Loop"));
    if(noGraph) x.setAttribute("Graph", y.getAttribute("Graph"));
    if(noClosed) x.setAttribute("Closed", y.getAttribute("Closed"));
    return val;
  }

  bool haveSolverToRun()
  {
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++) {
      onelab::client *c = *it;
      if(c->getName() != "Gmsh" && c->getName() != "Listen" &&
         c->getName() != "GmshRemote" &&
         c->getName().find("NoAutoRun") == std::string::npos)
        return true;
    }
    return false;
  }

  // update x using y, giving priority to any settings in x that can be set in
  // the GUI. The value of x is only changed if y is read-only.
  std::string updateString(onelab::string &x, onelab::string &y)
  {
    bool noChoices = true, noClosed = true, noMultipleSelection = true;

    if(y.getReadOnly()) {
      x.setValue(y.getValue());
      x.setReadOnly(true);
    }
    std::string val = x.getValue();

    // keep track of these attributes, which can be changed server-side
    if(x.getChoices().size()) noChoices = false;
    if(x.getAttribute("Closed").size()) noClosed = false;
    if(x.getAttribute("MultipleSelection").size()) noMultipleSelection = false;

    // if(copt.count("Kind")) ps[0].setKind(copt["Kind"][0]);
    if(noChoices) x.setChoices(y.getChoices());
    if(noClosed) x.setAttribute("Closed", y.getAttribute("Closed"));
    if(noMultipleSelection)
      x.setAttribute("MultipleSelection", y.getAttribute("MultipleSelection"));

    return val;
  }

  void initializeLoops()
  {
    onelabUtils::initializeLoop("1");
    onelabUtils::initializeLoop("2");
    onelabUtils::initializeLoop("3");

#if defined(HAVE_FLTK)
    if(FlGui::available() && onelab::server::instance()->getChanged())
      FlGui::instance()->rebuildTree(false);
#endif
  }

  bool incrementLoops()
  {
    bool ret = false;
    if(onelabUtils::incrementLoop("3"))
      ret = true;
    else if(onelabUtils::incrementLoop("2"))
      ret = true;
    else if(onelabUtils::incrementLoop("1"))
      ret = true;

    // Define ONELAB parameter indicating whether or not in a loop
    onelab::number n("0Metamodel/Loop", ret ? 1 : 0);
    n.setVisible(false);
    onelab::server::instance()->set(n);

#if defined(HAVE_FLTK)
    if(FlGui::available() && onelab::server::instance()->getChanged())
      FlGui::instance()->rebuildTree(false);
#endif
    return ret;
  }

  void updateGraphs()
  {
    bool redraw = false;
    for(int i = 0; i < 18; i++) {
      std::ostringstream tmp;
      tmp << i;
      bool ret = onelabUtils::updateGraph(tmp.str());
      redraw = redraw || ret;
    }
    if(redraw) {
    // don't delete the widgets, as this is called in widget callbacks
#if defined(HAVE_FLTK)
      FlGui::instance()->updateViews(true, false);
      drawContext::global()->draw();
#endif
    }
  }

  std::string timeStamp()
  {
    time_t now;
    time(&now);
    tm *t = localtime(&now);
    char stamp[73];
    // stamp.size() is always 20
    sprintf(stamp, "_%04d-%02d-%02d_%02d-%02d-%02d", 1900 + t->tm_year,
            1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return std::string(stamp);
  }

  void saveDb(const std::string &fileName)
  {
    FILE *fp = Fopen(fileName.c_str(), "wb");
    if(fp) {
      Msg::StatusBar(true, "Saving database '%s'...", fileName.c_str());
      onelab::server::instance()->toFile(fp);
      fclose(fp);
      Msg::StatusBar(true, "Done saving database '%s'", fileName.c_str());
    }
    else
      Msg::Error("Could not save database '%s'", fileName.c_str());

#if 0
    fp = Fopen((fileName + ".json").c_str(), "wb");
    if(fp){
      std::string json;
      onelab::server::instance()->toJSON(json, "Gmsh");
      fwrite(json.c_str(), sizeof(char), json.size(), fp);
      fclose(fp);
    }
#endif
  }

  void archiveOutputFiles(const std::string &fileName)
  {
    std::string stamp;
    std::vector<onelab::string> ps;
    onelab::server::instance()->get(ps, "0Metamodel/9Tag");
    if(ps.size() && ps[0].getValue().size())
      stamp.assign(timeStamp() + "_" + ps[0].getValue());
    else
      stamp.assign(timeStamp());

    // add time stamp in all output files in the db, and rename them on disk
    std::vector<onelab::string> strings;
    onelab::server::instance()->get(strings);
    for(std::size_t i = 0; i < strings.size(); i++) {
      if(strings[i].getName().find("9Output files") != std::string::npos) {
        std::vector<std::string> names = strings[i].getChoices();
        names.push_back(strings[i].getValue());
        for(std::size_t j = 0; j < names.size(); j++) {
          std::vector<std::string> split = SplitFileName(names[j]);
          int n = split[1].size();
          // if name is not already stamped
          if(n < 18 || split[1][n - 3] != '-' || split[1][n - 6] != '-' ||
             split[1][n - 9] != '_') {
            std::string old = names[j];
            CreateSingleDir(split[0] + "archive/");
            names[j] = split[0] + "archive/" + split[1] + stamp + split[2];
            Msg::Info("Renaming '%s' into '%s'", old.c_str(), names[j].c_str());
            rename(old.c_str(), names[j].c_str());
          }
        }
        strings[i].setValue(names.back());
        names.pop_back();
        strings[i].setChoices(names);
        onelab::server::instance()->set(strings[i]);
      }
    }

    // save stamped db
    {
      std::vector<std::string> split = SplitFileName(fileName);
      CreateSingleDir(split[0] + "archive/");
      saveDb(split[0] + "archive/" + split[1] + stamp + split[2]);
    }

#if defined(HAVE_FLTK)
    FlGui::instance()->rebuildTree(true);
#endif
  }

  void archiveSolutionFiles(const std::string &fileName)
  {
    // extract tag from db fileName, use fileName as tag otherwise
    std::vector<std::string> split = SplitFileName(fileName);
    std::string dir = split[0] + "archive/";
    std::string tag = split[1];
    if(!tag.compare(0, 6, "onelab"))
      tag.assign(tag.substr(6)); // cut off 'onelab' if present

    // add tag to all solution files in the db, and rename them on disk
    std::vector<onelab::string> strings;
    onelab::server::instance()->get(strings, "0Metamodel/9Solution files");
    if(strings.size()) {
      std::vector<std::string> names = strings[0].getChoices();
      if(names.size()) {
        for(std::size_t j = 0; j < names.size(); j++) {
          std::vector<std::string> split = SplitFileName(names[j]);
          std::string old = names[j];
          CreateSingleDir(dir);
          names[j] = dir + split[1] + tag + split[2];
          Msg::Info("Renaming '%s' into '%s'", old.c_str(), names[j].c_str());
          rename(old.c_str(), names[j].c_str());
        }
        strings[0].setValue(names[0]);
        strings[0].setChoices(names);
        onelab::server::instance()->set(strings[0]);
#if defined(HAVE_FLTK)
        FlGui::instance()->rebuildTree(true);
#endif
      }
    }
  }

  void loadDb(const std::string &name)
  {
    Msg::StatusBar(true, "Loading database '%s'...", name.c_str());
    FILE *fp = Fopen(name.c_str(), "rb");
    if(fp) {
      onelab::server::instance()->fromFile(fp);
      fclose(fp);
      Msg::StatusBar(true, "Done loading database '%s'", name.c_str());
    }
    else
      Msg::Error("Could not load database '%s'", name.c_str());
  }

  void resetDb(bool runGmshClient)
  {
    Msg::Info("Resetting database");

    // clear everything except persistent parameters
    std::vector<onelab::number> allNumbers, persistentNumbers;
    std::vector<onelab::string> allStrings, persistentStrings;
    onelab::server::instance()->get(allNumbers);
    onelab::server::instance()->get(allStrings);
    bool ismetamodel = false;
    for(std::size_t i = 0; i < allNumbers.size(); i++) {
      if(allNumbers[i].getAttribute("Persistent") == "1")
        persistentNumbers.push_back(allNumbers[i]);
      // these 2 should always be persistent
      if(allNumbers[i].getName() == "IsMetamodel" ||
         allNumbers[i].getName() == "IsPyMetamodel"){
        ismetamodel = allNumbers[i].getValue() ? true : false;
        persistentNumbers.push_back(allNumbers[i]);
      }
    }
    for(std::size_t i = 0; i < allStrings.size(); i++) {
      if(allStrings[i].getAttribute("Persistent") == "1")
        persistentStrings.push_back(allStrings[i]);
    }

    // clear the db
    onelab::server::instance()->clear();

    // run Gmsh client for non-metamodels (we need to check ismetamodel here
    // since the db has been cleared and the check cannot work in
    // runGmshClient!)
    if(runGmshClient && !ismetamodel){
      onelabUtils::runGmshClient("reset", CTX::instance()->solver.autoMesh);
    }

    for(std::size_t i = 0; i < persistentNumbers.size(); i++) {
      Msg::Debug("Restoring persistent parameter %s",
                 persistentNumbers[i].getName().c_str());
      onelab::server::instance()->set(persistentNumbers[i]);
    }
    for(std::size_t i = 0; i < persistentStrings.size(); i++) {
      Msg::Debug("Restoring persistent parameter %s",
                 persistentStrings[i].getName().c_str());
      onelab::server::instance()->set(persistentStrings[i]);
    }

    // mark all parameters as changed
    onelab::server::instance()->setChanged(3);
  }

} // namespace onelabUtils

#endif
