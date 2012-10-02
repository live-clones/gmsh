// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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

namespace onelabUtils {

  // get command line arguments for the client if "UseCommandLine" is set for
  // this client
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
      o.setAttribute("Closed", "1");
      c->set(o);
      return name;
    }
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

  bool incrementLoop(const std::string &level)
  {
    bool recompute = false, loop = false;
    std::vector<onelab::number> numbers;
    onelab::server::instance()->get(numbers);
    for(unsigned int i = 0; i < numbers.size(); i++){
      if(numbers[i].getAttribute("Loop") == level){
        loop = true;

        if(numbers[i].getChoices().size() > 1){
	  int j=numbers[i].getIndex();
	  if((j>=0) && (j < numbers[i].getChoices().size())){
	    numbers[i].setValue(numbers[i].getChoices()[j]);
	    numbers[i].setIndex(j+1);
	    onelab::server::instance()->set(numbers[i]);
            Msg::Info("Recomputing with %dth choice %s=%g", j,
		      numbers[i].getName().c_str(), numbers[i].getValue());
	    recompute = true;
	  }

          // FIXME should store loopVariable attribute in the parameter
          // -- the following test will loop forever if 2 values are
          // identical in the list of choices
          // std::vector<double> choices(numbers[i].getChoices());
          // for(unsigned int j = 0; j < choices.size() - 1; j++){
          //   if(numbers[i].getValue() == choices[j]){
          //     numbers[i].setValue(choices[j + 1]);
          //     onelab::server::instance()->set(numbers[i]);
          //     Msg::Info("Recomputing with new choice %s=%g",
          //               numbers[i].getName().c_str(), numbers[i].getValue());
          //     recompute = true;
          //     break;
          //   }
	  // }
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

  std::vector<double> getRange(onelab::number &p)
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

  bool updateGraph(const std::string &graphNum)
  {
    bool changed = false;
#if defined(HAVE_POST)
    PView *view = 0;

    for(unsigned int i = 0; i < PView::list.size(); i++){
      if(PView::list[i]->getData()->getFileName() == "OneLab" + graphNum){
        view = PView::list[i];
        break;
      }
    }

    int num = atoi(graphNum.c_str());
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
        view->getData()->setFileName("OneLab" + graphNum);
        view->getOptions()->intervalsType = PViewOptions::Discrete;
        view->getOptions()->autoPosition = num + 2;
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

  bool runGmshClient(const std::string &action, bool meshAuto)
  {
    bool redraw = false;

    onelab::server::citer it = onelab::server::instance()->findClient("Gmsh");
    if(it == onelab::server::instance()->lastClient()) return redraw;

    onelab::client *c = it->second;
    std::string mshFileName = onelabUtils::getMshFileName(c);
    if(action == "initialize") return redraw;

    static std::string modelName = "";
    if(modelName.empty()){
      // first pass is special to prevent model reload, as well as
      // remeshing if a mesh file already exists on disk
      modelName = GModel::current()->getName();
      if(!StatFile(mshFileName))
        onelab::server::instance()->setChanged(false, "Gmsh");
    }

    if(action == "check"){
      if(onelab::server::instance()->getChanged("Gmsh") ||
         modelName != GModel::current()->getName()){
        // reload geometry if Gmsh parameters have been modified or if
        // the model name has changed
        modelName = GModel::current()->getName();
        redraw = true;
        OpenProject(GModel::current()->getFileName());
      }
    }
    else if(action == "compute"){
      if(onelab::server::instance()->getChanged("Gmsh") ||
         modelName != GModel::current()->getName()){
        // reload the geometry, mesh it and save the mesh if Gmsh
        // parameters have been modified or if the model name has
        // changed
        modelName = GModel::current()->getName();
        redraw = true;
        OpenProject(GModel::current()->getFileName());
        if(!GModel::current()->empty() && meshAuto){
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
      onelab::server::instance()->setChanged(false, "Gmsh");
    }

    return redraw;
  }

}

#endif
