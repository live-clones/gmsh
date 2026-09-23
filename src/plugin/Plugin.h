// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PLUGIN_H
#define PLUGIN_H

// A plugin is a class derived from GMSH_PostPlugin (a plugin acting on a
// view) or GMSH_MeshPlugin (on the model). Besides the plugins built into Gmsh,
// plugins can be loaded from shared libraries (see PluginManager.h): such a
// library defines its plugin with GMSH_PLUGIN() below, and is built against the
// headers of the private API and the shared Gmsh library.

// the version of the plugin interface of this file: a plugin loaded from a
// shared library must have been built with the same
#define GMSH_PLUGIN_API_VERSION 2

#include <map>
#include <string>
#include <vector>
#include <functional>
#include "Options.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewDataList.h"

class PluginDialogBox;
class adaptiveElement;
class element;

// an element of a view, as GMSH_PostPlugin::createListData() gives it: its
// corners, for a higher order element
class PluginElement {
private:
  mutable element *_shape = nullptr;

public:
  int ent, ele, type, dim, numNodes, numComp;
  std::vector<double> x, y, z;
  ~PluginElement();
  // the element of shapeFunctions.h on the corners, created when first asked
  element *shape() const;
  // the values of view data at the corners at a step, node after node
  void getValues(PViewData *data, int step, std::vector<double> &val) const;
};

class GMSH_Plugin {
public:
  // plugins acting on the model or on a view
  typedef enum { GMSH_MESH_PLUGIN, GMSH_POST_PLUGIN } GMSH_PLUGIN_TYPE;

  // a dialog box for the user interface
  PluginDialogBox *dialogBox;

  // the numeric and string options of the plugin, with their default values
  GMSH_Plugin(const std::vector<StringXNumber> &numOptions = {},
              const std::vector<StringXString> &strOptions = {});
  virtual ~GMSH_Plugin() {}

  // return plugin type, name and info
  virtual GMSH_PLUGIN_TYPE getType() const = 0;
  virtual std::string getName() const = 0;
  virtual std::string getShortHelp() const = 0;
  virtual std::string getHelp() const = 0;
  virtual std::string getAuthor() const { return "C. Geuzaine, J.-F. Remacle"; }
  virtual std::string getCopyright() const
  {
    return "C. Geuzaine, J.-F. Remacle";
  }

  // the options (virtual for plugins that keep their options themselves)
  virtual int getNbOptions() const { return (int)_numOptions.size(); }
  virtual StringXNumber *getOption(int iopt) { return &_numOptions[iopt]; }
  virtual int getNbOptionsStr() const { return (int)_strOptions.size(); }
  virtual StringXString *getOptionStr(int iopt) { return &_strOptions[iopt]; }

  // the option of the given name, or of a former name given to
  // addOptionAlias(); nullptr if there is none
  StringXNumber *findOption(const std::string &name);
  StringXString *findOptionStr(const std::string &name);
  void addOptionAlias(const std::string &alias, const std::string &name);

  // set the options to the values given to the constructor
  void resetOptions();

  // for the field of numeric option iopt in the dialog box: get its step
  // (action 1), minimum (2) or maximum (3) for view num in value, or set it to
  // value (action 0); false if the option has no such configuration
  virtual bool optionCallback(int iopt, int num, int action, double &value);
  // for the field of string option iopt: set it to value (action 0)
  virtual bool optionStrCallback(int iopt, int num, int action,
                                 std::string &value);

  // draw a preview of what the plugin will do, while its options are edited
  virtual void drawPreview(void *context) {}
  // the plugin whose preview is drawn, if any; setPreview() redraws
  static GMSH_Plugin *preview;
  static void setPreview(GMSH_Plugin *p);

  // serialize plugin options into a string
  std::string serialize();

  // run the plugin
  virtual int run() = 0;

protected:
  // the value of numeric or string option iopt
  double &option(int iopt) { return getOption(iopt)->def; }
  double option(int iopt) const
  { return const_cast<GMSH_Plugin *>(this)->getOption(iopt)->def; }
  std::string &optionStr(int iopt) { return getOptionStr(iopt)->def; }
  // the integers of string option iopt, separated by commas; false (with an
  // error) if it holds anything else
  bool optionIntList(int iopt, std::vector<int> &list);
  // optionCallback() for a numeric option edited with a slider going from min
  // to max by step, whose changes are previewed
  bool sliderOption(int iopt, int action, double &value, double step,
                    double min, double max);

private:
  std::vector<StringXNumber> _numOptions, _numDefaults;
  std::vector<StringXString> _strOptions, _strDefaults;
  std::map<std::string, std::string> _aliases;
};

// The base class for post-processing plugins. The user can either
// modify or duplicate a post-processing view
class GMSH_PostPlugin : public GMSH_Plugin {
private:
  mutable bool _warnedGauss = false, _warnedCorners = false;

public:
  using GMSH_Plugin::GMSH_Plugin;
  inline GMSH_PLUGIN_TYPE getType() const
  {
    return GMSH_Plugin::GMSH_POST_PLUGIN;
  }
  // run the plugin
  virtual int run()
  {
    PView *v = execute(nullptr);
    if(v) return v->getTag();
    return 0;
  }
  // if the returned pointer is the same as the argument, then the
  // view is simply modified, else, a new view is added in the view
  // list
  virtual PView *execute(PView *) = 0;
  // excute on a remote dataset
  virtual PView *executeRemote(PView *);
  // get the view given an index and a default value (if index < 0 use
  // the default view if available; otherwise use the last view in the
  // list)
  virtual PView *getView(int index, PView *view);
  // get the data in list format
  virtual PViewDataList *getDataList(PView *view, bool showError = true);
  // get the the adapted data (i.e. linear, on refined mesh) if
  // available, otherwise get the original data
  virtual PViewData *getPossiblyAdaptiveData(PView *view);
  // the number of nodes of an element of a view to read, for a plugin that
  // writes first order elements (all list data holds) or that uses the element
  // classes of shapeFunctions.h (which only know those): the corners of a
  // higher order element, which come first; 0 for Gauss point data
  int getNumCornerNodes(PViewData *data, int step, int ent, int ele) const;
  // for a plugin that changes a view in place: call f once for each node of
  // the view (the nodes of model data are those of the mesh, shared by its
  // elements and its steps), with the first non-empty step, through the
  // elements of dimension dim only if dim >= 0; Gauss point data, whose points
  // are not nodes, is skipped
  void forEachNode(PViewData *data,
                   const std::function<void(int step, int ent, int ele,
                                            int nod)> &f,
                   int dim = -1) const;
  // create list data from the elements of a view: for each element with data,
  // numComp(e) gives the number of components of its values in the outputs
  // (1, 3 or 9; 0 skips the element), and values(e, step, res) computes them
  // for each step of the view with data, res[i] getting the numNodes * numComp
  // values of output i, node after node (false skips the element); the outputs
  // get the times of the steps
  void createListData(
    PViewData *data, const std::vector<PViewDataList *> &out,
    const std::function<int(const PluginElement &e)> &numComp,
    const std::function<bool(const PluginElement &e, int step,
                             std::vector<std::vector<double> > &res)> &values)
    const;
  // call f once for each value of the given step of a view, with the
  // coordinates it is given at: a node shared by elements (node data) once,
  // one value per element (element data) once, at the barycenter of the
  // element
  void forEachValue(PViewData *data, int step,
                    const std::function<void(int ent, int ele, int nod,
                                             double x, double y, double z)> &f)
    const;
  // (given the root of the tree of subdivisions of an adaptive view)
  virtual void assignSpecificVisibility(adaptiveElement *root) const {}
};

class GMSH_MeshPlugin : public GMSH_Plugin {
public:
  using GMSH_Plugin::GMSH_Plugin;
  inline GMSH_PLUGIN_TYPE getType() const
  {
    return GMSH_Plugin::GMSH_MESH_PLUGIN;
  }
  virtual int run() { return 0; }
};

// the functions a shared library defining a plugin exports: write
//   GMSH_PLUGIN(MyPlugin)
// in one of its source files, MyPlugin being the class of the plugin
#if defined(_WIN32)
#define GMSH_PLUGIN_EXPORT extern "C" __declspec(dllexport)
#else
#define GMSH_PLUGIN_EXPORT extern "C" __attribute__((visibility("default")))
#endif
#define GMSH_PLUGIN(className)                                                 \
  GMSH_PLUGIN_EXPORT int GMSH_PluginApiVersion()                               \
  {                                                                            \
    return GMSH_PLUGIN_API_VERSION;                                            \
  }                                                                            \
  GMSH_PLUGIN_EXPORT GMSH_Plugin *GMSH_RegisterPlugin()                        \
  {                                                                            \
    return new className();                                                    \
  }

#endif
