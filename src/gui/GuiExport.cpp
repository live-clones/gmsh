// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Stephen Guzik
//   Sebastian Eiser

#include "GmshConfig.h"

#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#include "GuiExport.h"
#include "GuiDeclare.h"
#include "Gui.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "CreateFile.h"
#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#endif

// The windows that ask what an output format takes: a form of a few
// fields bound to the options the writer reads, and OK or Cancel. A few
// choose which file to write rather than how -- which views, in which
// flavour -- and write it themselves.
//
// The form is shown, the loop pumped until a button answers or the window
// is closed, and the form dropped. The fields edit the options as they are
// typed, so Cancel puts back what the options were worth when the window
// opened.

namespace Export {

  namespace {

    using namespace Ui;
    using namespace Declare;

    // --- asking

    // Show the form and wait for its answer
    int _ask(const std::string &title,
             const std::function<void(Form &, int &answer)> &fill)
    {
      if(!Gui::instance().available()) return Gui::ExportGoAhead;
      return Gui::instance().exportOptions.ask(title, fill);
    }

    // --- the fields, said the way the options are named

    Field _check(const std::string &label, const std::string &category,
                 const std::string &name)
    {
      return option(Check, label, category, name);
    }

    Field _value(const std::string &label, const std::string &category,
                 const std::string &name, double lo, double hi, double step)
    {
      return within(option(Number, label, category, name), lo, hi, step);
    }

    // a choice among words, standing for the numbers of the option
    Field _choose(const std::string &label, const std::string &category,
                  const std::string &name,
                  const std::vector<std::string> &words,
                  const std::vector<int> &values)
    {
      Field f = option(Choice, label, category, name);
      f.choices = words;
      f.values = values;
      return f;
    }

    // a choice whose numbers are not the option's own: read and written
    // through the pair given
    Field _choose(const std::string &label,
                  const std::vector<std::string> &words,
                  std::function<double()> read,
                  std::function<void(double)> write)
    {
      Field f;
      f.kind = Choice;
      f.label = label;
      f.choices = words;
      for(std::size_t i = 0; i < words.size(); i++) f.values.push_back((int)i);
      f.readNumber = read;
      f.writeNumber = write;
      return f;
    }

    double _num(const char *category, const char *name)
    {
      double v = 0.;
      NumberOption(GMSH_GET, category, 0, name, v, false);
      return v;
    }

    void _setNum(const char *category, const char *name, double v)
    {
      NumberOption(GMSH_SET | GMSH_GUI, category, 0, name, v, false);
    }

    // --- pictures

    void _bitmap(Form &form, int &, int format)
    {
      std::vector<Field> fields;
      fields.push_back(_check("Print text strings", "Print", "Text"));
      fields.push_back(_check("Print background", "Print", "Background"));
      fields.push_back(
        _check("Composite all window tiles", "Print", "CompositeWindows"));
      Field w = _value("", "Print", "Width", -1, 5000, 1);
      w.tooltip = "Print.Width";
      Field h = _value("Dimensions", "Print", "Height", -1, 5000, 1);
      h.tooltip = "Print.Height";
      fields.push_back(shared(w, .5));
      fields.push_back(beside(shared(h, .5)));
      Field quality = slid(_value("Quality", "Print", "JpegQuality", 1, 100, 1));
      Field smoothing =
        slid(_value("Smoothing", "Print", "JpegSmoothing", 0, 100, 1));
      // only a JPEG has a quality to set
      bool jpeg = format == FORMAT_JPEG;
      quality.enabled = [jpeg]() { return jpeg; };
      smoothing.enabled = [jpeg]() { return jpeg; };
      fields.push_back(quality);
      fields.push_back(smoothing);
      form.panes.push_back(pane("", fields));
    }

    void _pgf(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(_check("Flat graphics", "Print", "PgfTwoDim"));
      fields.push_back(
        _check("Export axis (for entire fig)", "Print", "PgfExportAxis"));
      fields.push_back(_check("Horizontal colorbar", "Print", "PgfHorizontalBar"));
      Field w = _value("", "Print", "Width", -1, 5000, 1);
      Field h = _value("Dimensions", "Print", "Height", -1, 5000, 1);
      fields.push_back(shared(w, .5));
      fields.push_back(beside(shared(h, .5)));
      form.panes.push_back(pane("", fields));
    }

    void _gif(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(_check("Dither", "Print", "GifDither"));
      fields.push_back(_check("Interlace", "Print", "GifInterlace"));
      fields.push_back(_check("Sort colormap", "Print", "GifSort"));
      fields.push_back(_check("Transparent background", "Print", "GifTransparent"));
      fields.push_back(_check("Print text strings", "Print", "Text"));
      fields.push_back(_check("Print background", "Print", "Background"));
      fields.push_back(
        _check("Composite all window tiles", "Print", "CompositeWindows"));
      form.panes.push_back(pane("", fields));
    }

    void _gl2ps(Form &form, int &, int format)
    {
      std::vector<Field> fields;
      fields.push_back(_choose("Type", "Print", "EpsQuality",
                               {"Raster image", "Vector simple sort",
                                "Vector accurate sort", "Vector unsorted"},
                               {0, 1, 2, 3}));
      // what the quality allows
      auto quality = []() { return (int)_num("Print", "EpsQuality"); };
      bool ps = format == FORMAT_PS || format == FORMAT_EPS;
      Field compress = _check("Compress", "Print", "EpsCompress");
#if !defined(HAVE_LIBZ)
      compress.enabled = []() { return false; };
#endif
      Field culling =
        _check("Remove hidden primitives", "Print", "EpsOcclusionCulling");
      culling.enabled = [quality]() { return quality() != 0; };
      Field bsp = _check("Optimize BSP tree", "Print", "EpsBestRoot");
      bsp.enabled = [quality]() { return quality() == 2; };
      Field shading = _check("Use level 3 shading", "Print", "EpsPS3Shading");
      shading.enabled = [quality, ps]() { return ps && quality() != 0; };
      fields.push_back(compress);
      fields.push_back(culling);
      fields.push_back(bsp);
      fields.push_back(shading);
      fields.push_back(_check("Print text strings", "Print", "Text"));
      fields.push_back(_check("Print background", "Print", "Background"));
      form.panes.push_back(pane("", fields));
    }

    void _tex(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(
        _check("Print strings as equations", "Print", "TexAsEquation"));
      fields.push_back(_check("Force font size", "Print", "TexForceFontSize"));
      Field w = _value("Graphics width in mm", "Print", "TexWidthInMm", 0, 5000, 1);
      w.tooltip = "Print.TexWidthInMm (Set value to 0 to use the natural "
                  "width inferred from the width in pixels)";
      fields.push_back(shared(w, .5));
      form.panes.push_back(pane("", fields));
    }

    // The animation: which of three things to loop over, and how. The OK
    // writes the film; Preview plays it without writing, and the window
    // stays up for another go.
    void _mpeg(Form &form, int &answer, const std::string &name)
    {
      std::vector<Field> fields;
      fields.push_back(_choose("", "PostProcessing", "AnimationCycle",
                               {"Cycle through time steps",
                                "Cycle through views",
                                "Loop over print parameter value"},
                               {0, 1, 2}));
      auto looping = []() {
        return (int)_num("PostProcessing", "AnimationCycle") == 2;
      };
      Field command = option(Text, "", "Print", "ParameterCommand");
      command.tooltip = "Print.ParameterCommand";
      command.enabled = looping;
      fields.push_back(command);
      Field first = option(Number, "", "Print", "ParameterFirst");
      first.enabled = looping;
      Field last = option(Number, "", "Print", "ParameterLast");
      last.enabled = looping;
      Field steps =
        within(option(Number, "First / Last / Steps", "Print", "ParameterSteps"),
               1, 500, 1);
      steps.enabled = looping;
      fields.push_back(shared(first, 1. / 3.));
      fields.push_back(beside(shared(last, 1. / 3.)));
      fields.push_back(beside(shared(steps, 1. / 3.)));
      fields.push_back(shared(_value("Frame duration (in seconds)",
                                     "PostProcessing", "AnimationDelay",
                                     1. / 30., 2., 1. / 30.),
                              .5));
      fields.push_back(shared(
        _value("Steps between frames", "PostProcessing", "AnimationStep", 1,
               100, 1),
        .5));
      fields.push_back(_check("Print background", "Print", "Background"));
      fields.push_back(
        _check("Composite all window tiles", "Print", "CompositeWindows"));
      fields.push_back(
        _check("Delete temporary files", "Print", "DeleteTemporaryFiles"));
      form.panes.push_back(pane("", fields));
      Button preview;
      preview.label = "Preview";
      preview.action = [name]() {
        CreateOutputFile(name, FORMAT_MPEG_PREVIEW, false);
      };
      form.buttons.push_back(preview);
      (void)answer;
    }

    // --- the model

    void _options(Form &form, int &, const std::string &name)
    {
      // these two are not options: they say how the option file is written,
      // and are worth their defaults every time the window opens
      static bool onlyModified = true, helpStrings = false;
      onlyModified = true;
      helpStrings = false;
      std::vector<Field> fields;
      fields.push_back(check("Save only modified options", &onlyModified));
      fields.push_back(check("Print help strings", &helpStrings));
      form.panes.push_back(pane("", fields));
      // the OK writes the file
      Button ok;
      ok.label = "OK";
      ok.isDefault = true;
      ok.action = [name]() {
        Msg::StatusBar(true, "Writing '%s'...", name.c_str());
        PrintOptions(0, GMSH_FULLRC, onlyModified, helpStrings, name.c_str());
        Msg::StatusBar(true, "Done writing '%s'", name.c_str());
      };
      form.buttons.push_back(ok);
    }

    void _geo(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(_check("Save physical group labels", "Print", "GeoLabels"));
      fields.push_back(
        _check("Only save physical entities", "Print", "GeoOnlyPhysicals"));
      form.panes.push_back(pane("", fields));
    }

    // --- the mesh

    void _msh(Form &form, int &)
    {
      std::vector<Field> fields;
      // one choice for two options: the version of the format, and whether
      // it is written in binary
      fields.push_back(_choose(
        "Format",
        {"Version 1", "Version 2 ASCII", "Version 2 Binary",
         "Version 4 ASCII", "Version 4 Binary"},
        []() {
          double version = _num("Mesh", "MshFileVersion");
          bool binary = _num("Mesh", "Binary") != 0.;
          if(version == 1.0) return 0.;
          if(version < 4.0) return binary ? 2. : 1.;
          return binary ? 4. : 3.;
        },
        [](double v) {
          int which = (int)v;
          _setNum("Mesh", "MshFileVersion",
                  which == 0 ? 1.0 : (which == 1 || which == 2) ? 2.2 : 4.1);
          _setNum("Mesh", "Binary", (which == 2 || which == 4) ? 1. : 0.);
        }));
      fields.push_back(_check("Save all elements", "Mesh", "SaveAll"));
      fields.push_back(
        _check("Save parametric coordinates", "Mesh", "SaveParametric"));
      // the partitions, when there are any to write
      auto partitioned = []() {
        return GModel::current()->getNumPartitions() > 0 &&
               _num("Mesh", "MshFileVersion") != 1.0;
      };
      Field split =
        _check("Save one file per partition", "Mesh", "PartitionSplitMeshFiles");
      split.enabled = partitioned;
      Field topology =
        _check("Save partition topology file", "Mesh", "PartitionTopologyFile");
      topology.enabled = partitioned;
      fields.push_back(split);
      fields.push_back(topology);
      form.panes.push_back(pane("", fields));
    }

    void _meshStat(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(_check("Save all elements", "Mesh", "SaveAll"));
      fields.push_back(_check("Print elementary tags", "Print", "PostElementary"));
      fields.push_back(_check("Print element numbers", "Print", "PostElement"));
      fields.push_back(_check("Print SICN quality measure", "Print", "PostSICN"));
      fields.push_back(_check("Print SIGE quality measure", "Print", "PostSIGE"));
      fields.push_back(
        _check("Print Gamma quality measure", "Print", "PostGamma"));
      fields.push_back(_check("Print Eta quality measure", "Print", "PostEta"));
      fields.push_back(
        _check("Print Disto quality measure", "Print", "PostDisto"));
      form.panes.push_back(pane("", fields));
    }

    void _unvInp(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(_check("Save all elements", "Mesh", "SaveAll"));
      fields.push_back(
        _check("Save groups of nodes", "Mesh", "SaveGroupsOfNodes"));
      form.panes.push_back(pane("", fields));
    }

    // LSDYNA and RADIOSS: what to do with each dimension, kept as bits of
    // Mesh.SaveAll, and two bits of Mesh.SaveGroupsOfNodes
    void _keyRad(Form &form, int &)
    {
      std::vector<std::string> what = {"Physical groups", "Save all", "Ignore"};
      auto readBits = [](int on, int off) {
        return [on, off]() {
          int all = (int)_num("Mesh", "SaveAll");
          return (all & on) ? 1. : (all & off) ? 2. : 0.;
        };
      };
      auto writeBits = [](int on, int off) {
        return [on, off](double v) {
          int all = (int)_num("Mesh", "SaveAll") & ~(on | off);
          if((int)v == 1) all |= on;
          if((int)v == 2) all |= off;
          _setNum("Mesh", "SaveAll", all);
        };
      };
      std::vector<Field> fields;
      fields.push_back(_choose("Line", what, readBits(4, 8), writeBits(4, 8)));
      fields.push_back(
        _choose("Surface", what, readBits(16, 32), writeBits(16, 32)));
      fields.push_back(
        _choose("Volume", what, readBits(64, 128), writeBits(64, 128)));
      auto readGroup = [](int bit) {
        return [bit]() {
          return ((int)_num("Mesh", "SaveGroupsOfNodes") & bit) ? 1. : 0.;
        };
      };
      auto writeGroup = [](int bit) {
        return [bit](double v) {
          int g = (int)_num("Mesh", "SaveGroupsOfNodes") & ~bit;
          if(v != 0.) g |= bit;
          _setNum("Mesh", "SaveGroupsOfNodes", g);
        };
      };
      Field elements;
      elements.kind = Check;
      elements.label = "Save groups of elements";
      elements.readNumber = readGroup(2);
      elements.writeNumber = writeGroup(2);
      Field nodes;
      nodes.kind = Check;
      nodes.label = "Save groups of nodes";
      nodes.readNumber = readGroup(1);
      nodes.writeNumber = writeGroup(1);
      fields.push_back(elements);
      fields.push_back(nodes);
      form.panes.push_back(pane("", fields));
    }

    void _bdf(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(_choose("Format", "Mesh", "BdfFieldFormat",
                               {"Free field", "Small field", "Long field"},
                               {0, 1, 2}));
      fields.push_back(_choose("Element tag", "Mesh", "SaveElementTagType",
                               {"Elementary entity", "Physical entity",
                                "Partition"},
                               {1, 2, 3}));
      fields.push_back(_check("Save all elements", "Mesh", "SaveAll"));
      form.panes.push_back(pane("", fields));
    }

    void _stl(Form &form, int &)
    {
      std::vector<Field> fields;
      fields.push_back(
        _choose("Format", "Mesh", "Binary", {"ASCII", "Binary"}, {0, 1}));
      Field all = _check("Save all elements", "Mesh", "SaveAll");
      // one solid per physical surface is by physical group by nature
      all.enabled = []() {
        return (int)_num("Mesh", "StlOneSolidPerSurface") != 2;
      };
      fields.push_back(all);
      fields.push_back(_choose("Solid", "Mesh", "StlOneSolidPerSurface",
                               {"Single", "Per surface", "Per physical surface"},
                               {0, 1, 2}));
      form.panes.push_back(pane("", fields));
    }

    void _genericMesh(Form &form, int &, bool binary, bool elementTag)
    {
      std::vector<Field> fields;
      Field format =
        _choose("Format", "Mesh", "Binary", {"ASCII", "Binary"}, {0, 1});
      format.enabled = [binary]() { return binary; };
      Field tag = _choose("Element tag", "Mesh", "SaveElementTagType",
                          {"Elementary entity", "Physical entity", "Partition"},
                          {1, 2, 3});
      tag.enabled = [elementTag]() { return elementTag; };
      fields.push_back(format);
      fields.push_back(tag);
      fields.push_back(_check("Save all elements", "Mesh", "SaveAll"));
      form.panes.push_back(pane("", fields));
    }

    // --- the views, which write what they choose

#if defined(HAVE_POST)
    void _saveViews(const std::string &name, int which, int format,
                    bool canAppend)
    {
      if(PView::list.empty()) {
        Msg::Error("No views to save");
        return;
      }
      if(which == 0) {
        int iview = Gui::instance().options.view;
        if(iview < 0 || iview >= (int)PView::list.size()) {
          Msg::Info("No or invalid current view: saving View[0]");
          iview = 0;
        }
        PView::list[iview]->write(name, format);
        return;
      }
      if(which == 1) {
        int numVisible = 0;
        for(std::size_t i = 0; i < PView::list.size(); i++)
          if(PView::list[i]->getOptions()->visible) numVisible++;
        if(!numVisible) {
          Msg::Error("No visible view");
          return;
        }
        bool first = true;
        for(std::size_t i = 0; i < PView::list.size(); i++) {
          if(!PView::list[i]->getOptions()->visible) continue;
          std::string fileName = name;
          if(!canAppend && numVisible > 1) {
            std::ostringstream os;
            os << "_" << i;
            fileName += os.str();
          }
          PView::list[i]->write(fileName, format, first ? false : canAppend);
          first = false;
        }
        return;
      }
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        std::string fileName = name;
        if(!canAppend && PView::list.size() > 1) {
          std::ostringstream os;
          os << "_" << i;
          fileName += os.str();
        }
        PView::list[i]->write(fileName, format, i ? canAppend : false);
      }
    }

    void _saveAdaptedViews(const std::string &name, int useDefaultName,
                           int which, bool isBinary, int adaptLev,
                           double adaptErr, int npart, bool canAppend)
    {
      if(PView::list.empty()) {
        Msg::Error("No views to save");
        return;
      }
      if(which == 0) {
        int iview = Gui::instance().options.view;
        if(iview < 0 || iview >= (int)PView::list.size()) {
          Msg::Info("No or invalid current view: saving View[0]");
          iview = 0;
        }
        PView::list[iview]->writeAdapt(name, useDefaultName, isBinary, adaptLev,
                                       adaptErr, npart);
        return;
      }
      if(which == 1) {
        int numVisible = 0;
        for(std::size_t i = 0; i < PView::list.size(); i++)
          if(PView::list[i]->getOptions()->visible) numVisible++;
        if(!numVisible) {
          Msg::Error("No visible view");
          return;
        }
        bool first = true;
        for(std::size_t i = 0; i < PView::list.size(); i++) {
          if(!PView::list[i]->getOptions()->visible) continue;
          std::string fileName = name;
          if(!canAppend && numVisible > 1) {
            std::ostringstream os;
            os << "_" << i;
            fileName += os.str();
          }
          PView::list[i]->writeAdapt(fileName, useDefaultName, isBinary,
                                     adaptLev, adaptErr, npart,
                                     first ? false : canAppend);
          first = false;
        }
        return;
      }
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        std::string fileName = name;
        if(!canAppend && PView::list.size() > 1) {
          std::ostringstream os;
          os << "_" << i;
          fileName += os.str();
        }
        PView::list[i]->writeAdapt(fileName, useDefaultName, isBinary, adaptLev,
                                   adaptErr, npart, i ? canAppend : false);
      }
    }

    // which views: current, visible or all. Not an option: what the window
    // asks each time, and forgets.
    const std::vector<std::string> _whichViews = {"Current", "Visible", "All"};

    void _pos(Form &form, int &, const std::string &name)
    {
      static int which = 0, flavour = 0;
      which = 0;
      flavour = 0;
      std::vector<Field> fields;
      fields.push_back(choice("View(s)", &which, _whichViews, {0, 1, 2}));
      fields.push_back(choice("Format", &flavour,
                              {"Parsed", "Mesh-based", "Legacy ASCII",
                               "Legacy Binary"},
                              {0, 1, 2, 3}));
      form.panes.push_back(pane("", fields));
      Button ok;
      ok.label = "OK";
      ok.isDefault = true;
      ok.action = [name]() {
        int format = flavour == 0 ? 2 : flavour == 1 ? 5 : flavour == 2 ? 0 : 1;
        _saveViews(name, which, format, format == 2);
      };
      form.buttons.push_back(ok);
    }

    void _pvtu(Form &form, int &, const std::string &name)
    {
      static int which = 0, flavour = 0;
      static double level = 1., error = -1.e-4, parts = 4.;
      static bool defaultName = true;
      which = 0;
      flavour = 0;
      std::vector<Field> fields;
      fields.push_back(choice("View(s)", &which, _whichViews, {0, 1, 2}));
      fields.push_back(choice("Format", &flavour, {"Binary", "ASCII"}, {0, 1}));
      fields.push_back(within(number("Recursion level", &level), 0, 6, 1));
      fields.push_back(within(number("Target error", &error), -1.e-4, 0.1, 1.e-4));
      fields.push_back(within(number("Number of parts", &parts), 1, 262144, 1));
      fields.push_back(check("Use default filename", &defaultName));
      form.panes.push_back(pane("", fields));
      Button ok;
      ok.label = "OK";
      ok.isDefault = true;
      ok.action = [name]() {
        // one view at a time in a pvtu set: nothing appends
        _saveAdaptedViews(name, defaultName ? 1 : 0, which, flavour == 0,
                          (int)level, error, (int)parts, false);
      };
      form.buttons.push_back(ok);
    }

    void _x3dView(Form &form, int &, const std::string &name)
    {
      static int which = 0;
      which = 0;
      std::vector<Field> fields;
      fields.push_back(choice("View(s)", &which, _whichViews, {0, 1, 2}));
      fields.push_back(
        _check("Remove inner borders", "Print", "X3dRemoveInnerBorders"));
      // the precision is asked as its logarithm
      Field precision;
      precision.kind = Number;
      precision.label = "Log10(Precision)";
      precision.tooltip = "Print.X3dPrecision";
      precision.minimum = -16;
      precision.maximum = 16;
      precision.step = .25;
      precision.readNumber = []() {
        return std::log10(_num("Print", "X3dPrecision"));
      };
      precision.writeNumber = [](double v) {
        _setNum("Print", "X3dPrecision", std::pow(10., v));
      };
      fields.push_back(shared(precision, .7));
      fields.push_back(shared(
        _value("Transparency", "Print", "X3dTransparency", 0., 1., .05), .7));
      fields.push_back(
        _check("High compatibility (no scale)", "Print", "X3dCompatibility"));
      form.panes.push_back(pane("", fields));
      Button ok;
      ok.label = "OK";
      ok.isDefault = true;
      ok.action = [name]() { _saveViews(name, which, 7, false); };
      form.buttons.push_back(ok);
    }

    void _genericView(Form &form, int &, const std::string &name, int format)
    {
      static int which = 0;
      which = 0;
      std::vector<Field> fields;
      fields.push_back(choice("View(s)", &which, _whichViews, {0, 1, 2}));
      form.panes.push_back(pane("", fields));
      Button ok;
      ok.label = "OK";
      ok.isDefault = true;
      ok.action = [name, format]() { _saveViews(name, which, format, false); };
      form.buttons.push_back(ok);
    }
#endif

  } // namespace

  int askOptions(int format, const std::string &fileName,
                 const std::string &entry)
  {
    // a couple of lines of the chooser share a format and not a question
    bool statistics = entry.find("Mesh Statistics") != std::string::npos;
#if defined(HAVE_POST)
    bool views = !PView::list.empty();
#else
    bool views = false;
#endif
    switch(format) {
    // --- nothing to ask
    case FORMAT_BREP:
    case FORMAT_IGES:
    case FORMAT_STEP:
    case FORMAT_VIS:
    case FORMAT_XAO:
    case FORMAT_XMT:
    case FORMAT_CGNS: return Gui::ExportGoAhead;
    // --- pictures
    case FORMAT_JPEG:
      return _ask("JPEG Options", [](Form &f, int &a) { _bitmap(f, a, FORMAT_JPEG); });
    case FORMAT_PNG:
      return _ask("PNG Options", [](Form &f, int &a) { _bitmap(f, a, FORMAT_PNG); });
    case FORMAT_PPM:
      return _ask("PPM Options", [](Form &f, int &a) { _bitmap(f, a, FORMAT_PPM); });
    case FORMAT_YUV:
      return _ask("YUV Options", [](Form &f, int &a) { _bitmap(f, a, FORMAT_YUV); });
    case FORMAT_GIF: return _ask("GIF Options", _gif);
    case FORMAT_PGF: return _ask("PGF Options", _pgf);
    case FORMAT_EPS:
      return _ask("EPS Options", [](Form &f, int &a) { _gl2ps(f, a, FORMAT_EPS); });
    case FORMAT_PS:
      return _ask("PS Options", [](Form &f, int &a) { _gl2ps(f, a, FORMAT_PS); });
    case FORMAT_PDF:
      return _ask("PDF Options", [](Form &f, int &a) { _gl2ps(f, a, FORMAT_PDF); });
    case FORMAT_SVG:
      return _ask("SVG Options", [](Form &f, int &a) { _gl2ps(f, a, FORMAT_SVG); });
    case FORMAT_TIKZ:
      return _ask("TIKZ Options", [](Form &f, int &a) { _gl2ps(f, a, FORMAT_TIKZ); });
    case FORMAT_TEX: return _ask("LaTeX Options", _tex);
    case FORMAT_MPEG:
    case FORMAT_MPEG_PREVIEW:
      return _ask("MPEG Options",
                  [&](Form &f, int &a) { _mpeg(f, a, fileName); });
    // --- the model
    case FORMAT_OPT:
      return _ask("Options",
                         [&](Form &f, int &a) { _options(f, a, fileName); });
    case FORMAT_GEO: return _ask("GEO Options", _geo);
    // --- the mesh
    case FORMAT_MSH: return _ask("MSH Options", _msh);
    case FORMAT_UNV: return _ask("UNV Options", _unvInp);
    case FORMAT_INP: return _ask("Abaqus INP Options", _unvInp);
    case FORMAT_KEY: return _ask("LSDYNA KEY Options", _keyRad);
    case FORMAT_RAD: return _ask("RADIOSS Block Options", _keyRad);
    case FORMAT_BDF: return _ask("BDF Options", _bdf);
    case FORMAT_STL: return _ask("STL Options", _stl);
    case FORMAT_VTK:
      return _ask("VTK Options", [](Form &f, int &a) { _genericMesh(f, a, true, false); });
    case FORMAT_TOCHNOG:
      return _ask("Tochnog Options", [](Form &f, int &a) { _genericMesh(f, a, true, false); });
    case FORMAT_DIFF:
      return _ask("Diffpack Options", [](Form &f, int &a) { _genericMesh(f, a, true, false); });
    case FORMAT_MESH:
      return _ask("MESH Options", [](Form &f, int &a) { _genericMesh(f, a, false, true); });
    case FORMAT_IR3:
      return _ask("Iridium Options", [](Form &f, int &a) { _genericMesh(f, a, false, true); });
    case FORMAT_CELUM:
      return _ask("CELUM Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_SU2:
      return _ask("SU2 Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_MED:
      return _ask("MED Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_OFF:
      return _ask("OFF Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_OBJ:
      return _ask("OBJ Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_MAIL:
      return _ask("MAIL Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_MATLAB:
      return _ask("MATLAB Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_P3D:
      return _ask("P3D Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_VRML:
      return _ask("VRML Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_PLY2:
      return _ask("PLY2 Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    case FORMAT_NEU:
      return _ask("NEU Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
    // --- the views, or the mesh where there is no view to write
#if defined(HAVE_POST)
    case FORMAT_POS:
      if(statistics) return _ask("POS Options", _meshStat);
      return _ask("POS Options",
                         [&](Form &f, int &a) { _pos(f, a, fileName); });
    case FORMAT_PVTU:
      return _ask("Adaptive View Options",
                         [&](Form &f, int &a) { _pvtu(f, a, fileName); });
    case FORMAT_RMED:
      return _ask("MED Options", [&](Form &f, int &a) {
        _genericView(f, a, fileName, 6);
      });
    case FORMAT_TXT:
      return _ask("TXT Options", [&](Form &f, int &a) {
        _genericView(f, a, fileName, 4);
      });
    case FORMAT_X3D:
      if(views)
        return _ask("X3D Options", [&](Form &f, int &a) {
          _x3dView(f, a, fileName);
        });
      return _ask("X3D Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
#else
    case FORMAT_POS: return _ask("POS Options", _meshStat);
    case FORMAT_X3D:
      return _ask("X3D Options", [](Form &f, int &a) { _genericMesh(f, a, false, false); });
#endif
    default: return Gui::ExportGoAhead;
    }
  }

} // namespace Export

int GuiExport::ask(const std::string &title,
                   const std::function<void(Ui::Form &, int &)> &fill)
{
  _title = title;
  _fill = fill;
  _answer = -1;
  _remembered = false;
  show();
  while(_answer < 0 && visible()) Gui::instance().wait(0.05, true);
  // closed by its cross: nothing was chosen
  if(_answer < 0) _answer = Gui::ExportCancelled;
  hide();
  if(_answer == Gui::ExportCancelled) {
    for(std::size_t i = 0; i < _fields.size(); i++) {
      const Ui::Field &f = _fields[i];
      if(f.kind == Ui::Text || f.kind == Ui::Output) {
        if(f.writeText)
          const_cast<Ui::Field &>(f).setText(_texts[i]);
      }
      else
        const_cast<Ui::Field &>(f).setNumber(_numbers[i]);
    }
  }
  return _answer;
}

// The form `fill` describes, with OK and Cancel: a form that writes the file
// itself declares its own OK, which answers "done" once it has; one that
// only sets options is given an OK that answers "go ahead".
Ui::Form GuiExport::build()
{
  Ui::Form form;
  form.id = "export";
  form.title = _title;
  if(_fill) _fill(form, _answer);
  bool writes = false;
  for(auto &b : form.buttons) {
    if(b.label != "OK") continue;
    writes = true;
    std::function<void()> write = b.action;
    b.isDefault = true;
    b.action = [write, this]() {
      if(_answer >= 0) return;
      if(write) write();
      _answer = Gui::ExportDone;
    };
  }
  if(!writes) {
    Ui::Button ok;
    ok.label = "OK";
    ok.isDefault = true;
    ok.action = [this]() {
      if(_answer < 0) _answer = Gui::ExportGoAhead;
    };
    form.buttons.push_back(ok);
  }
  Ui::Button cancel;
  cancel.label = "Cancel";
  cancel.action = [this]() {
    if(_answer < 0) _answer = Gui::ExportCancelled;
  };
  form.buttons.push_back(cancel);
  if(!_remembered) {
    _fields.clear();
    _numbers.clear();
    _texts.clear();
    auto each = [&](const std::vector<Ui::Field> &fields) {
      for(const auto &f : fields) {
        if(!f.readNumber && !f.readText) continue;
        _fields.push_back(f);
        _numbers.push_back(f.getNumber());
        _texts.push_back(f.getText());
      }
    };
    for(const auto &q : form.panes) each(q.fields);
    each(form.footer);
    _remembered = true;
  }
  return form;
}
