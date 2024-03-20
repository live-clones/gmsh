// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PVIEW_H
#define PVIEW_H

#include <vector>
#include <map>
#include <string>
#include "MVertex.h"
#include "MElement.h"
#include "SPoint3.h"

class PViewData;
class PViewOptions;
class VertexArray;
class smooth_normals;
class GModel;
class GMSH_PostPlugin;
namespace onelab {
  class localNetworkClient;
}

// A post-processing view.
class PView {
private:
  static int _globalTag;
  // unique tag of the view (>= 0)
  int _tag;
  // index of the view in the current view list
  int _index;
  // flag to mark that the view has changed1
  bool _changed;
  // tag of the source view if this view is an alias, -1 otherwise
  int _aliasOf;
  // eye position (for transparency sorting)
  SPoint3 _eye;
  // the options
  PViewOptions *_options;
  // the data
  PViewData *_data;
  // initialize private stuff
  void _init(int tag = -1);

public:
  // create a new view with list-based data
  PView(int tag = -1);
  // construct a new view using the given data
  PView(PViewData *data, int tag = -1);
  // construct a new view, alias of the view "ref"
  PView(PView *ref, bool copyOptions = true, int tag = -1);
  // construct a new list-based view from a simple 2D point dataset
  PView(const std::string &xname, const std::string &yname,
        std::vector<double> &x, std::vector<double> &y);
  // construct a new list-based view from a simple 3D point dataset
  PView(const std::string &name, std::vector<double> &x, std::vector<double> &y,
        std::vector<double> &z, std::vector<double> &v);
  // construct a new mesh-based view from a bunch of data
  PView(const std::string &name, const std::string &type, GModel *model,
        std::map<int, std::vector<double> > &data, double time = 0.,
        int numComp = -1, int tag = -1);
  // add a new time step to a given mesh-based view
  void addStep(GModel *model, const std::map<int, std::vector<double> > &data,
               double time = 0., int numComp = -1);
  // add a new step to a list-based scalar point dataset
  void addStep(std::vector<double> &y);

  // default destructor
  ~PView();

  // set/get global tag
  static int getGlobalTag();
  static void setGlobalTag(int tag);

  // delete the vertex arrays, used to draw the view efficiently
  void deleteVertexArrays();

  // get/set the display options
  PViewOptions *getOptions() { return _options; }
  void setOptions(PViewOptions *val = nullptr);

  // get/set the view data
  PViewData *getData(bool useAdaptiveIfAvailable = false);
  void setData(PViewData *val) { _data = val; }

  // get the view tag (unique and immutable)
  int getTag() { return _tag; }

  // get/set the view index (in the view list)
  int getIndex() { return _index; }
  void setIndex(int val) { _index = val; }

  // get/set the changed flag
  bool &getChanged() { return _changed; }
  void setChanged(bool val);

  // check if the view is an alias ("light copy") of another view
  int getAliasOf() { return _aliasOf; }

  // get/set the eye position (for transparency calculations)
  SPoint3 &getEye() { return _eye; }
  void setEye(SPoint3 &p) { _eye = p; }
  //  void setDrawContext(drawContext *ctx){_ctx=ctx;}

  // get (approx.) memory used by the view, in Mb
  double getMemoryInMb();

#ifndef SWIG
  // the static list of all loaded views
  static std::vector<PView *> list;
#endif

  // combine view
  static void combine(bool time, int how, bool remove, bool copyOptions);

  // find view by name, by fileName, or by number. If timeStep >= 0, return view
  // only if it does *not* contain that timestep; if partition >= 0, return view
  // only if it does *not* contain that partition, if fileName is not empty,
  // return view only if it does *not* have that fileName.
  static PView *getViewByName(const std::string &name, int timeStep = -1,
                              int partition = -1,
                              const std::string &fileName = "");
  static PView *getViewByFileName(const std::string &fileName,
                                  int timeStep = -1, int partition = -1);
  static PView *getViewByTag(int tag, int timeStep = -1, int partition = -1);

  // sort views in ::list by name
  static void sortByName();

  // IO read routines (these are global: they can create multiple
  // views)
  static bool readPOS(const std::string &fileName, int fileIndex = -1);
  static bool readMSH(const std::string &fileName, int fileIndex = -1,
                      int partitionToRead = -1);
  static bool readCGNS(const std::vector<std::vector<MVertex *> > &vertPerZone,
                       const std::vector<std::vector<MElement *> > &eltPerZone,
                       const std::string &fileName);
  static bool readMED(const std::string &fileName, int fileIndex = -1);
  static bool readPCH(const std::string &fileName, int fileIndex = -1);
  static bool writeX3D(const std::string &fileName);
  // IO write routine
  bool write(const std::string &fileName, int format, bool append = false);

  // send to ONELAB server
  void sendToServer(const std::string &name);

  // Routines for export of adapted views to pvtu file format for parallel
  // visualization with paraview
  bool writeAdapt(const std::string &fileName, int useDefaultName,
                  bool isBinary, int adaptLev, double adaptErr, int npart,
                  bool append = false);

  // vertex arrays to draw the elements efficiently
  VertexArray *va_points, *va_lines, *va_triangles, *va_vectors, *va_ellipses;

  // fill the vertex arrays, given the current option and data
  bool fillVertexArrays();

  // fill a vertex array using a raw stream of bytes
  static void fillVertexArray(onelab::localNetworkClient *remote, int length,
                              const char *data, int swap);

  // smoothed normals
  smooth_normals *normals;
};

class nameData {
public:
  std::string name;
  std::vector<int> indices;
  std::vector<PViewData *> data;
  PViewOptions *options;
};

// this is the maximum number of nodes of elements we actually *draw*
// (high order elements are always subdivided before drawing)
#define PVIEW_NMAX 8
void changeCoordinates(PView *p, int ient, int iele, int numNodes, int type,
                       int numComp, double **xyz, double **val);
bool isElementVisible(PViewOptions *opt, int dim, int numNodes, double **xyz);

#endif
