// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshConfig.h"

#if defined(HAVE_ONELAB)

#include "GmshDefines.h"
#include "GModel.h"
#include "Context.h"
#include "OS.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "StringUtils.h"
#include "onelabUtils.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_ONELAB2)
#include "OnelabDatabase.h"
#include "OnelabServer.h"
#endif

namespace onelabUtils {

  // get command line arguments for the client if "UseCommandLine" is set for
  // this client
#ifdef HAVE_ONELAB2
  std::vector<std::string> getCommandLine(const std::string &client)
  {
    std::vector<std::string> args;
    std::vector<onelab::number> n;
    OnelabDatabase::instance()->get(n, client + "/UseCommandLine");
    if(n.size() && n[0].getValue()){
      std::vector<onelab::string> ps;
      OnelabDatabase::instance()->get(ps, client + "/Action");
      std::string action = (ps.empty() ? "" : ps[0].getValue());
      OnelabDatabase::instance()->get(ps, client + "/1ModelName");
      std::string modelName = (ps.empty() ? "" : ps[0].getValue());
      OnelabDatabase::instance()->get(ps, client + "/9CheckCommand");
      std::string checkCommand = (ps.empty() ? "" : ps[0].getValue());
      OnelabDatabase::instance()->get(ps, client + "/9ComputeCommand");
      std::string computeCommand = (ps.empty() ? "" : ps[0].getValue());
      if(modelName.size()) args.push_back(" \"" + modelName + "\"");
      if(action == "check")
        args.push_back(" " + checkCommand) ;
      else if(action == "compute")
        args.push_back(" " + computeCommand);
    }
    return args;
  }
  std::string getMshFileName()
  {
    std::string name;
    std::vector<onelab::string> ps;
    OnelabDatabase::instance()->get(ps, "Gmsh/MshFileName");
    if(ps.size()){
      name = ps[0].getValue();
    }
    else{
      name = CTX::instance()->outputFileName;
      if(name.empty()){
        if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
          name = GetDefaultFileName(FORMAT_MSH);
        else
          name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
      }
      onelab::string o("Gmsh/MshFileName", name, "Mesh name");
      o.setKind("file");
      o.setAttribute("Closed", "1");
      OnelabDatabase::instance()->set(o, std::string("Gmsh"));
    }
    return name;
  }

  void guessModelName(const std::string &client)
  {
    std::vector<onelab::number> n;
    OnelabDatabase::instance()->get(n, client + "/GuessModelName");
    if(n.size() && n[0].getValue()){
      std::vector<onelab::string> ps;
      OnelabDatabase::instance()->get(ps, client + "/1ModelName");
      if(ps.empty()){
        OnelabDatabase::instance()->get(ps, "Gmsh/1ModelName");
        std::vector<std::string> split;
        if(!ps.empty()) split = SplitFileName(ps[0].getValue());
        else split = SplitFileName(GModel::current()->getFileName());
        std::string ext = "";
        OnelabDatabase::instance()->get(ps, client + "/FileExtension");
        if(ps.size()) ext = ps[0].getValue();
        std::string name(split[0] + split[1] + ext);
        onelab::string o(client + "/1ModelName", name, "Model name");
        o.setKind("file");
        OnelabDatabase::instance()->set(o, client);
      }
    }
  }

#else
  std::vector<std::string> getCommandLine(onelab::client *c)
  {
    std::vector<std::string> args;
    std::string name(c->getName());
    std::vector<onelab::number> n;
    c->get(n, name + "/UseCommandLine");
    if(n.size() && n[0].getValue()){
      std::vector<onelab::string> ps;
      c->get(ps, name + "/Action");
      std::string action = (ps.empty() ? "" : ps[0].getValue());
      c->get(ps, name + "/1ModelName");
      std::string modelName = (ps.empty() ? "" : ps[0].getValue());
      c->get(ps, name + "/9CheckCommand");
      std::string checkCommand = (ps.empty() ? "" : ps[0].getValue());
      c->get(ps, name + "/9ComputeCommand");
      std::string computeCommand = (ps.empty() ? "" : ps[0].getValue());
      if(modelName.size()) args.push_back(" \"" + modelName + "\"");
      if(action == "check")
        args.push_back(" " + checkCommand) ;
      else if(action == "compute")
        args.push_back(" " + computeCommand);
    }
    return args;
  }
  std::string getMshFileName(onelab::client *c)
  {

    std::string name;
    std::vector<onelab::string> ps;
    c->get(ps, "Gmsh/MshFileName");
    if(ps.size()){
      name = ps[0].getValue();
    }
    else{
      name = CTX::instance()->outputFileName;
      if(name.empty()){
        if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
          name = GetDefaultFileName(FORMAT_MSH);
        else
          name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
      }
      onelab::string o("Gmsh/MshFileName", name, "Mesh name");
      o.setKind("file");
      o.setAttribute("Closed", "1");
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

#endif

  void initializeLoop(const std::string &level)
  {
    bool changed = false;
    std::vector<onelab::number> numbers;
    onelab::server::instance()->get(numbers);
    for(unsigned int i = 0; i < numbers.size(); i++){

      if(numbers[i].getAttribute("Loop") == level){
        if(numbers[i].getChoices().size() > 1){
	  numbers[i].setIndex(0);
          numbers[i].setValue(numbers[i].getChoices()[0]);
          onelab::server::instance()->set(numbers[i]);
          changed = true;
        }
        else if(numbers[i].getStep() > 0){
          if(numbers[i].getMin() != -onelab::parameter::maxNumber()){
            numbers[i].setValue(numbers[i].getMin());
	    numbers[i].setIndex(0); // indicates we are in a loop
	    std::vector<double> choices;
	    numbers[0].setChoices(choices);
            onelab::server::instance()->set(numbers[i]);
            changed = true;
          }
        }
        else if(numbers[i].getStep() < 0){
          if(numbers[i].getMax() != onelab::parameter::maxNumber()){
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
    for(unsigned int i = 0; i < numbers.size(); i++){
      if(numbers[i].getAttribute("Loop") == level){
        loop = true;

        if(numbers[i].getChoices().size() > 1){
	  int j = numbers[i].getIndex() + 1;
	  if((j >= 0) && (j < (int) numbers[i].getChoices().size())){
	    numbers[i].setValue(numbers[i].getChoices()[j]);
	    numbers[i].setIndex(j);
	    onelab::server::instance()->set(numbers[i]);
            Msg::Info("Recomputing with %dth choice %s=%g", j,
		      numbers[i].getName().c_str(), numbers[i].getValue());
	    recompute = true;
	  }
	}
        else if(numbers[i].getStep() > 0){
	  int j = numbers[i].getIndex() + 1;
	  double val = numbers[i].getValue() + numbers[i].getStep();
          if(numbers[i].getMax() != onelab::parameter::maxNumber() &&
             val <= numbers[i].getMax() * (1 + eps)){
            numbers[i].setValue(val);
	    numbers[i].setIndex(j);
            onelab::server::instance()->set(numbers[i]);
            Msg::Info("Recomputing with new step %s=%g",
                      numbers[i].getName().c_str(), numbers[i].getValue());
            recompute = true;
          }
	  else
	    numbers[i].setIndex(numbers[i].getMax());// FIXME makes sense?
        }
        else if(numbers[i].getStep() < 0){
	  int j = numbers[i].getIndex() + 1;
	  double val = numbers[i].getValue() + numbers[i].getStep();
          if(numbers[i].getMin() != -onelab::parameter::maxNumber() &&
             val >= numbers[i].getMin() * (1 - eps)){
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
    if(p.getChoices().size()){
      v = p.getChoices();
    }
    else if(p.getMin() != -onelab::parameter::maxNumber() &&
            p.getMax() != onelab::parameter::maxNumber()){
      if(p.getStep() > 0){
        for(double d = p.getMin(); d <= p.getMax() * (1 + eps); d += p.getStep())
          v.push_back(d);
      }
      else if(p.getStep() < 0){
        for(double d = p.getMin(); d <= p.getMax() * (1 + eps); d -= p.getStep())
          v.push_back(d);
      }
    }
    return v;
  }

  bool updateGraph(const std::string &graphNum)
  {
    bool changed = false;
#if defined(HAVE_POST)
    PView *view = 0;

    for(unsigned int i = 0; i < PView::list.size(); i++){
      if(PView::list[i]->getData()->getFileName() == "ONELAB" + graphNum){
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
    for(unsigned int i = 0; i < numbers.size(); i++){
      std::string v = numbers[i].getAttribute("Graph");
      v.resize(36, '0');
      if(v[2 * num] != '0'){
        x = getRange(numbers[i]);
        xName = numbers[i].getShortName();
      }
      if(v[2 * num + 1] != '0'){
        y = getRange(numbers[i]);
        yName = numbers[i].getShortName();
        char t = v[2 * num + 1];
        graphType = (t == '1') ? 1 : (t == '2') ? 2 : (t == '3') ? 3 :
          (t == '4') ? 4 : 3;
      }
    }
    if(x.empty()){
      xName.clear();
      for(unsigned int i = 0; i < y.size(); i++) x.push_back(i);
    }
    if(x.size() && y.size()){
      if(x.size() != y.size())
        Msg::Info("X-Y data series have different length (%d != %d)",
                  (int)x.size(), (int)y.size());
      if(view){
        view->getData()->setXY(x, y);
        view->getData()->setName(yName);
        view->getOptions()->axesLabel[0] = xName;
        view->setChanged(true);
      }
      else{
        view = new PView(xName, yName, x, y);
        view->getData()->setFileName("ONELAB" + graphNum);
        view->getOptions()->intervalsType = graphType;
        view->getOptions()->autoPosition = num / 2 + 2;
      }
      changed = true;
    }
    else if(view){
      delete view;
      changed = true;
    }
#endif
    return changed;
  }

  static bool _firstComputation = true;
  void setFirstComputationFlag(bool val){ _firstComputation = val; }
  bool getFirstComputationFlag(){ return _firstComputation; }
#ifdef HAVE_ONELAB2
  bool runGmshClient(const std::string &action, int meshAuto)
  {
    bool redraw = false;

    // do nothing in case of a python metamodel
    std::vector<onelab::number> pn;
    OnelabDatabase::instance()->get(pn, "IsPyMetamodel");
    if(pn.size() && pn[0].getValue()) return redraw;

    OnelabLocalNetworkClient *c = OnelabServer::instance()->getClient("Gmsh");
    std::cout << ((c != NULL)?"not":"ok") << std::endl;
    if(c != NULL) return redraw; // Gmsh is remote TODO

    std::string mshFileName = onelabUtils::getMshFileName();

    Msg::SetGmshOnelabAction(action);

    static std::string modelName = GModel::current()->getName();

    if(action == "initialize"){
      // nothing to do
    }
    else if(action == "reset"){
      setFirstComputationFlag(false);
      // nothing more to do: "check" will be called right afterwards
    }
    else if(action == "check"){
      if(OnelabServer::instance()->getChanged("Gmsh") ||
         modelName != GModel::current()->getName()){
        // reload geometry if Gmsh parameters have been modified or
        // if the model name has changed
        modelName = GModel::current()->getName();
        redraw = true;
        OpenProject(GModel::current()->getFileName(), false);
        OnelabServer::instance()->setChanged(true, "Gmsh");
      }
    }
    else if(action == "compute"){
      std::cout <<
        "Gmsh getChanged is " << OnelabServer::instance()->getChanged("Gmsh") << std::endl <<
        "modelName is " << modelName << std::endl <<
        "current GModel is" << GModel::current()->getName() << std::endl <<
        "stat file " << mshFileName << " is " << StatFile(mshFileName) << std::endl <<
        "meshAuto is " << meshAuto 
        << std::endl;
      if(OnelabServer::instance()->getChanged("Gmsh") ||
         modelName != GModel::current()->getName()){
        // reload the geometry, mesh it and save the mesh if Gmsh parameters
        // have been modified or if the model name has changed
        modelName = GModel::current()->getName();
        redraw = true;
        OpenProject(GModel::current()->getFileName(), false);
        if(getFirstComputationFlag() && !StatFile(mshFileName) && meshAuto != 2){
          Msg::Info("Skipping mesh generation: assuming '%s' is up-to-date "
                    "(use Solver.AutoMesh=2 to force mesh generation)",
                    mshFileName.c_str());
        }
        else if(!GModel::current()->empty() && meshAuto){
          GModel::current()->mesh(3);
          CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
        }
      }
      else if(StatFile(mshFileName)){
        // mesh+save if the mesh file does not exist
        if(meshAuto){
          redraw = true;
          GModel::current()->mesh(3);
          CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
        }
      }
      setFirstComputationFlag(false);
      OnelabServer::instance()->setChanged(false, "Gmsh");
    }

    Msg::SetGmshOnelabAction("");

    return redraw;
  }
#else
  bool runGmshClient(const std::string &action, int meshAuto)
  {
    bool redraw = false;

    // do nothing in case of a python metamodel
    std::vector<onelab::number> pn;
    onelab::server::instance()->get(pn, "IsPyMetamodel");
    if(pn.size() && pn[0].getValue()) return redraw;

    onelab::server::citer it = onelab::server::instance()->findClient("Gmsh");
    if(it == onelab::server::instance()->lastClient()) return redraw;

    onelab::client *c = it->second;
    std::string mshFileName = onelabUtils::getMshFileName(c);

    Msg::SetGmshOnelabAction(action);

    static std::string modelName = GModel::current()->getName();

    if(action == "initialize"){
      // nothing to do
    }
    else if(action == "reset"){
      setFirstComputationFlag(false);
      // nothing more to do: "check" will be called right afterwards
    }
    else if(action == "check"){
      if(onelab::server::instance()->getChanged("Gmsh") ||
         modelName != GModel::current()->getName()){
        // reload geometry if Gmsh parameters have been modified or
        // if the model name has changed
        modelName = GModel::current()->getName();
        redraw = true;
        OpenProject(GModel::current()->getFileName(), false);
      }
    }
    else if(action == "compute"){
      if(onelab::server::instance()->getChanged("Gmsh") ||
         modelName != GModel::current()->getName()){
        // reload the geometry, mesh it and save the mesh if Gmsh parameters
        // have been modified or if the model name has changed
        modelName = GModel::current()->getName();
        redraw = true;
        OpenProject(GModel::current()->getFileName(), false);
        if(getFirstComputationFlag() && !StatFile(mshFileName) && meshAuto != 2){
          Msg::Info("Skipping mesh generation: assuming '%s' is up-to-date "
                    "(use Solver.AutoMesh=2 to force mesh generation)",
                    mshFileName.c_str());
        }
        else if(!GModel::current()->empty() && meshAuto){
          GModel::current()->mesh(3);
          CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
        }
      }
      else if(StatFile(mshFileName)){
        // mesh+save if the mesh file does not exist
        if(meshAuto){
          redraw = true;
          GModel::current()->mesh(3);
          CreateOutputFile(mshFileName, CTX::instance()->mesh.fileFormat);
        }
      }
      setFirstComputationFlag(false);
      onelab::server::instance()->setChanged(false, "Gmsh");
    }

    Msg::SetGmshOnelabAction("");

    return redraw;
  }
#endif
  // update x using y, giving priority to any settings in x that can be set in
  // the GUI. The value of x is only changed if y is read-only.
  double updateNumber(onelab::number &x, onelab::number &y, const bool readOnlyRange)
  {
    bool noRange = true, noChoices = true, noLoop = true;
    bool noGraph = true, noClosed = true;

    if(y.getReadOnly()){
      x.setValue(y.getValue());
      x.setReadOnly(true);
    }
    double val = x.getValue();

    // keep track of these attributes, which can be changed server-side (unless,
    // for the range/choices, when explicitely setting these attributes as
    // ReadOnly)
    if(!readOnlyRange){
      if(x.getMin() != -onelab::parameter::maxNumber() ||
	 x.getMax() != onelab::parameter::maxNumber() ||
	 x.getStep() != 0.) noRange = false;
      if(x.getChoices().size()) noChoices = false;
    }
    if(x.getAttribute("Loop").size()) noLoop = false;
    if(x.getAttribute("Graph").size()) noGraph = false;
    if(x.getAttribute("Closed").size()) noClosed = false;

    if(noRange){
      bool noRangeEither = true;
      if(y.getMin() != -onelab::parameter::maxNumber() ||
	 y.getMax() != onelab::parameter::maxNumber() ||
	 y.getStep() != 0.) noRangeEither = false;
      if(!noRangeEither){
	x.setMin(y.getMin());
	x.setMax(y.getMax());
      }
      else{
	// if no range/min/max/step info is provided, try to compute a reasonnable
	// range and step (this makes the GUI much nicer to use)
	bool isInteger = (floor(val) == val);
	double fact = isInteger ? 5. : 20.;
	if(val > 0){
	  x.setMin(val / fact);
	  x.setMax(val * fact);
	  x.setStep((x.getMax() - x.getMin()) / 100.);
	}
	else if(val < 0){
	  x.setMin(val * fact);
	  x.setMax(val / fact);
	  x.setStep((x.getMax() - x.getMin()) / 100.);
	}
	if(val && isInteger){
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
    if(noClosed) x.setAttribute("Closed",  y.getAttribute("Closed"));
    return val;
  }

  // update x using y, giving priority to any settings in x that can be set in
  // the GUI. The value of x is only changed if y is read-only.
  std::string updateString(onelab::string &x, onelab::string &y)
  {
    bool noChoices = true, noClosed = true, noMultipleSelection = true;

    if(y.getReadOnly()){
      x.setValue(y.getValue());
      x.setReadOnly(true);
    }
    std::string val = x.getValue();

    // keep track of these attributes, which can be changed server-side
    if(x.getChoices().size()) noChoices = false;
    if(x.getAttribute("Closed").size()) noClosed = false;
    if(x.getAttribute("MultipleSelection").size()) noMultipleSelection = false;

    //if(copt.count("Kind")) ps[0].setKind(copt["Kind"][0]);
    if(noChoices) x.setChoices(y.getChoices());
    if(noClosed) x.setAttribute("Closed", y.getAttribute("Closed"));
    if(noMultipleSelection)
      x.setAttribute("MultipleSelection", y.getAttribute("MultipleSelection"));

    return val;
  }

}
#endif
