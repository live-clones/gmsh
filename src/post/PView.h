// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
class PViewDataList;
class adaptiveData;
class PViewOptions;
class VertexArray;
class smooth_normals;
class GModel;
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
  // flag to mark that the view has changed
  bool _changed;
  // tag of the source view if this view is an alias, -1 otherwise
  int _aliasOf;
  // eye position (for transparency sorting)
  SPoint3 _eye;
  // the options
  PViewOptions *_options;
  // the data
  PViewData *_data;
  // for a view whose skin alone is refined, the elements the clipping planes
  // cut, refined apart (and read in place of its adaptive data while what
  // the planes add is built)
  adaptiveData *_clipAdaptive;
  PViewData *_clipLayer;
  void _deleteClipAdaptive();
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
  void setData(PViewData *val)
  {
    _deleteClipAdaptive();
    _data = val;
  }

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

  // get (approx.) memory used by the view, in MB
  double getMemoryInMB();

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
  static bool readMSHInterpolationScheme(FILE *fp);
  static bool readMSHViewData(const std::string &fileName, FILE *fp,
                              bool binary, bool swap, const char *dataType,
                              double version, int partitionToRead = -1);
  static bool readCGNS(const std::vector<std::vector<MVertex *> > &vertPerZone,
                       const std::vector<std::vector<MElement *> > &eltPerZone,
                       const std::string &fileName);
  static bool readMED(const std::string &fileName, int fileIndex = -1);
  static bool writeX3D(const std::string &fileName);
  // (the files to read back, each with a mesh, are added to written)
  static bool writeVTU(
    const std::string &fileName, bool binary, const std::vector<PView *> &views,
    std::vector<std::pair<std::string, bool> > *written = nullptr);
  // the formats of write(), as in PostProcessing.Format
  enum Format {
    POS_ASCII = 0,
    POS_BINARY = 1,
    POS_PARSED = 2,
    STL = 3,
    TXT = 4,
    MSH = 5,
    MED = 6,
    X3D = 7,
    VTU = 8,
    AUTO = 10 // from the extension of the file
  };
  // write the view; if it makes several files, a script to read them back
  // (see CreateReadBackScript()), or else they are added to written, with
  // true if they have a mesh
  bool write(const std::string &fileName, int format, bool append = false,
             std::vector<std::pair<std::string, bool> > *written = nullptr);

  // send to ONELAB server
  void sendToServer(const std::string &name);

  // create the adaptive data of the view if it is drawn adapted
  // (View.AdaptVisualizationGrid), and refine it as the options say: the time
  // step, the recursion level, the target error, the range drawn if it is a
  // custom one, which the error is then relative to, and only the skin of the
  // volumes if nothing else is drawn of them (View.AdaptSkinOnly), unless the
  // whole view is asked for (nothing is done if it is already refined so)
  void adapt(bool whole = false);
  // for a view whose skin alone is refined, refine apart the elements the
  // clipping planes cut, which what the planes add is built from (see
  // useClipLayer); false if the view is not refined so
  bool refineClipLayer();
  // read the elements refined apart in place of the adaptive data, or stop
  void useClipLayer(bool use);
  // refine the whole view if only its skin is, for what reads the refined data
  // as a whole (plugins, probes, the API); the next drawing refines the skin
  // again
  void adaptWhole();
  // widen a range of the refined data to the values inside the volumes (those
  // of the nodes, at the time step drawn) if only the skin is refined
  void widenAdaptedRange(double &min, double &max);
  // the range the target error is relative to, as adaptiveData takes it (the
  // custom range, or else an empty one: that of the data)
  void getAdaptiveRange(double &min, double &max);

  // Views of high order are saved refined if PostProcessing.SaveAdapted says
  // so, as adapted views are drawn (with the recursion level and the target
  // error of the view), each step on a mesh of its own: true if this one is,
  // and the refined steps, a view of a step each (null if the view has no
  // such step), until doneSaving()
  bool savesAdapted();
  std::vector<PViewDataList *> getAdaptedSteps();
  static void doneSaving();
  // true if the view is saved on several meshes: refined with several steps,
  // or with its steps on the meshes of different models. A file holds one
  // mesh: such a view is saved in a file for each, name_0000.ext, named after
  // the first step it holds.
  bool savesSeveralMeshes();

  // vertex arrays to draw the elements efficiently
  VertexArray *va_points, *va_lines, *va_triangles, *va_vectors, *va_ellipses;
  // what the clipping planes add, kept apart so that moving a plane rebuilds
  // only this: the section they cut (capping), or the cut elements drawn
  // whole (whole element mode)
  VertexArray *va_clip_lines, *va_clip_triangles;

  // fill the vertex arrays, given the current option and data
  bool fillVertexArrays();
  // build what the clipping planes add; false when nothing had to change
  bool fillClipVertexArrays();
  void deleteClipVertexArrays();
  void invalidateClipVertexArrays();

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
bool elementIsKept(PViewOptions *opt, int dim, int numNodes, double **xyz);

// An element of a view as it is drawn, at the time step of the view (in its
// adaptive data if any): its nodes, moved as the view says (explode, raise,
// displacement...), and the values at them (the components it is asked to
// show). The memory is kept from one element to the next.
class PViewElement {
private:
  std::vector<double> _xyz, _val;
  std::vector<double *> _xyzRows, _valRows;

public:
  int ent = 0, ele = 0, type = 0, dim = 0, numNodes = 0, numComp = 0;
  double **xyz = nullptr, **val = nullptr;
  // take the element ele of the entity ent; false if it is not drawn: skipped
  // by the sampling or the options, or with more nodes or components than can
  // be drawn (with a warning, once)
  bool select(PView *p, int ent, int ele);
  // read its nodes and its values
  void read(PView *p);
};

#endif
