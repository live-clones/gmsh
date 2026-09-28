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
#include "StringUtils.h"
#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#endif

// What an output format asks before the file is written: a form bound to the
// options the writer reads, pumped until OK or Cancel. The fields edit the
// options as they are typed, so Cancel puts back what they were worth when
// the window opened. A few formats choose which file to write rather than
// how -- which views, in which flavour -- and write it themselves.

namespace Export {

  namespace {

    using namespace Ui;
    using namespace Declare;

    // --- asking

    int _ask(const std::string &title, const std::function<Item()> &fill)
    {
      if(!Gui::instance().available()) return Gui::ExportGoAhead;
      return Gui::instance().exportOptions.ask(title, fill);
    }


    Field _check(const std::string &label, const std::string &category,
                 const std::string &name)
    { return check(label, category + "." + name); }

    Field _value(const std::string &label, const std::string &category,
                 const std::string &name, double lo, double hi, double step)
    {
      return number(label, category + "." + name).within(lo, hi, step);
    }

    Field _choose(const std::string &label, const std::string &category,
                  const std::string &name,
                  const std::vector<std::string> &words,
                  const std::vector<int> &values)
    {
      std::vector<std::pair<std::string, int>> pairs;
      for(std::size_t i = 0; i < words.size(); i++)
        pairs.push_back({words[i], values[i]});
      return choice(label, category + "." + name, pairs);
    }

    // numbers that are not the option's own
    Field _choose(const std::string &label,
                  const std::vector<std::string> &words,
                  std::function<double()> read,
                  std::function<void(double)> write)
    {
      Field f = choice(label, read, write);
      f.choices = words;
      for(std::size_t i = 0; i < words.size(); i++) f.values.push_back((int)i);
      return f;
    }

    double _num(const char *category, const char *name)
    {
      double v = 0.;
      NumberOption(GMSH_GET, category, 0, name, v, false);
      return v;
    }

    void _setNum(const char *category, const char *name, double v)
    { NumberOption(GMSH_SET | GMSH_GUI, category, 0, name, v, false); }

    // --- pictures

    Item _bitmap(int format)
    {
      bool jpeg = format == FORMAT_JPEG;
      return vbox(
        {_check("Print text strings", "Print", "Text"),
         _check("Print background", "Print", "Background"),
         _check("Composite all window tiles", "Print", "CompositeWindows"),
         _check("Scale sizes with the picture", "Print", "ScalePixelSizes"),
         hbox({_value("", "Print", "Width", -1, 5000, 1).share(.5).tight()
                 .tip("Print.Width"),
               _value("Dimensions", "Print", "Height", -1, 5000, 1).share(.5).tight()
                 .tip("Print.Height")}),
         _value("Supersampling", "Print", "Supersampling", 1, 8, 1)
           .tip("Print.Supersampling"),
         _value("Quality", "Print", "JpegQuality", 1, 100, 1)
           .slid()
           .enabledWhen([jpeg]() { return jpeg; }),
         _value("Smoothing", "Print", "JpegSmoothing", 0, 100, 1)
           .slid()
           .enabledWhen([jpeg]() { return jpeg; })});
    }

    Item _pgf()
    {
      return vbox(
        {_check("Flat graphics", "Print", "PgfTwoDim"),
         _check("Export axis (for entire fig)", "Print", "PgfExportAxis"),
         _check("Horizontal colorbar", "Print", "PgfHorizontalBar"),
         hbox({_value("", "Print", "Width", -1, 5000, 1).share(.5).tight(),
               _value("Dimensions", "Print", "Height", -1, 5000, 1).share(.5).tight()})});
    }

    Item _gif()
    {
      return vbox(
        {_check("Dither", "Print", "GifDither"),
         _check("Interlace", "Print", "GifInterlace"),
         _check("Sort colormap", "Print", "GifSort"),
         _check("Transparent background", "Print", "GifTransparent"),
         _check("Print text strings", "Print", "Text"),
         _check("Print background", "Print", "Background"),
         _check("Composite all window tiles", "Print", "CompositeWindows")});
    }

    Item _gl2ps(int format)
    {
      auto quality = []() { return (int)_num("Print", "EpsQuality"); };
      bool ps = format == FORMAT_PS || format == FORMAT_EPS;
      Field compress = _check("Compress", "Print", "EpsCompress");
#if !defined(HAVE_LIBZ)
      compress.enabledWhen([]() { return false; });
#endif
      return vbox(
        {_choose("Type", "Print", "EpsQuality",
                 {"Raster image", "Vector simple sort", "Vector accurate sort",
                  "Vector unsorted"},
                 {0, 1, 2, 3}),
         compress,
         _check("Remove hidden primitives", "Print", "EpsOcclusionCulling")
           .enabledWhen([quality]() { return quality() != 0; }),
         _check("Optimize BSP tree", "Print", "EpsBestRoot")
           .enabledWhen([quality]() { return quality() == 2; }),
         _check("Use level 3 shading", "Print", "EpsPS3Shading")
           .enabledWhen([quality, ps]() { return ps && quality() != 0; }),
         _check("Print text strings", "Print", "Text"),
         _check("Print background", "Print", "Background")});
    }

    Item _tex()
    {
      return vbox(
        {_check("Print strings as equations", "Print", "TexAsEquation"),
         _check("Force font size", "Print", "TexForceFontSize"),
         _value("Graphics width in mm", "Print", "TexWidthInMm", 0, 5000, 1).share(.5).tight()
           .tip("Print.TexWidthInMm (Set value to 0 to use the natural width "
                "inferred from the width in pixels)")});
    }

    // Preview plays without writing, and the window stays up
    Item _mpeg(const std::string &name)
    {
      auto looping = []() {
        return (int)_num("PostProcessing", "AnimationCycle") == 2;
      };
      return vbox(
        {_choose("", "PostProcessing", "AnimationCycle",
                 {"Cycle through time steps", "Cycle through views",
                  "Loop over print parameter value"},
                 {0, 1, 2}),
         text("", "Print.ParameterCommand")
           .tip("Print.ParameterCommand")
           .enabledWhen(looping),
         hbox(
           {number("", "Print.ParameterFirst").share(1. / 3.).tight()
              .enabledWhen(looping),
            number("", "Print.ParameterLast").share(1. / 3.).tight().enabledWhen(looping),
            number("First / Last / Steps", "Print.ParameterSteps")
                     .within(1, 500, 1).share(1. / 3.).tight()
              .enabledWhen(looping)}),
         _value("Frame duration (in seconds)", "PostProcessing",
                       "AnimationDelay", 1. / 30., 2., 1. / 30.).share(.5).tight(),
         _value("Steps between frames", "PostProcessing",
                       "AnimationStep", 1, 100, 1).share(.5).tight(),
         _check("Print background", "Print", "Background"),
         _check("Composite all window tiles", "Print", "CompositeWindows"),
         _check("Delete temporary files", "Print", "DeleteTemporaryFiles"),
         hbox({button("Preview", [name]() {
           CreateOutputFile(name, FORMAT_MPEG_PREVIEW, false);
         })})});
    }

    // --- the model

    Item _options(const std::string &name)
    {
      // not options: worth their defaults every time the window opens
      static bool onlyModified = true, helpStrings = false;
      onlyModified = true;
      helpStrings = false;
      return vbox({check("Save only modified options", &onlyModified),
                   check("Print help strings", &helpStrings),
                   hbox({button("OK", [name]() {
                     Msg::StatusBar(true, "Writing '%s'...", name.c_str());
                     PrintOptions(0, GMSH_FULLRC, onlyModified, helpStrings,
                                  name.c_str());
                     Msg::StatusBar(true, "Done writing '%s'", name.c_str());
                   })})});
    }

    Item _geo()
    {
      return vbox(
        {_check("Save physical group labels", "Print", "GeoLabels"),
         _check("Only save physical entities", "Print", "GeoOnlyPhysicals")});
    }

    // --- the mesh, and the views saved with it (Mesh.SaveViews) in the
    // formats that can hold them: with views and no mesh, the views are what
    // there is to save

    bool _haveViews()
    {
#if defined(HAVE_POST)
      return !PView::list.empty();
#else
      return false;
#endif
    }

    int _viewsToSave()
    {
      int views = (int)_num("Mesh", "SaveViews");
      if(!views && _haveViews() && !GModel::current()->getNumMeshElements())
        views = 1;
      return views;
    }

    // not the option itself, which is only written once the answer is OK
    int _views = 0;

    Field _viewsField(std::function<bool()> active)
    {
      return choice("Views", &_views, {"None", "Visible", "All"}, {0, 1, 2})
        .tip("Mesh.SaveViews")
        .enabledWhen(active);
    }

    Field _adaptedField(std::function<bool()> active)
    {
      return _check("Save high order views refined", "PostProcessing",
                    "SaveAdapted")
        .enabledWhen(active);
    }

    // no views in MSH 1
    bool _mshViews()
    {
      return _haveViews() && _num("Mesh", "MshFileVersion") != 1.0;
    }

    Item _msh()
    {
      auto partitioned = []() {
        return GModel::current()->getNumPartitions() > 0 &&
               _num("Mesh", "MshFileVersion") != 1.0;
      };
      // one choice for the version and the binary flag
      return vbox(
        {_choose(
           "Format",
           {"Version 1", "Version 2 ASCII", "Version 2 Binary",
            "Version 4.1 ASCII", "Version 4.1 Binary", "Version 4.2 ASCII",
            "Version 4.2 Binary"},
           []() {
             double version = _num("Mesh", "MshFileVersion");
             bool binary = _num("Mesh", "Binary") != 0.;
             if(version == 1.0) return 0.;
             if(version < 4.0) return binary ? 2. : 1.;
             if(version < 4.2) return binary ? 4. : 3.;
             return binary ? 6. : 5.;
           },
           [](double v) {
             int which = (int)v;
             _setNum("Mesh", "MshFileVersion",
                     which == 0 ? 1.0 :
                     which <= 2 ? 2.2 :
                     which <= 4 ? 4.1 :
                                  4.2);
             _setNum("Mesh", "Binary", (which && !(which % 2)) ? 1. : 0.);
           }),
         _viewsField(_mshViews),
         _check("Save all elements", "Mesh", "SaveAll"),
         _check("Save parametric coordinates", "Mesh", "SaveParametric"),
         _check("Save one file per partition", "Mesh",
                "PartitionSplitMeshFiles")
           .enabledWhen(partitioned),
         _check("Save partition topology file", "Mesh", "PartitionTopologyFile")
           .enabledWhen(partitioned),
         _adaptedField(_mshViews)});
    }

    Item _med()
    {
      return vbox({_viewsField(_haveViews),
                   _check("Save all elements", "Mesh", "SaveAll")});
    }

    Item _vtu()
    {
      return vbox(
        {_choose("Format", "Mesh", "Binary", {"ASCII", "Binary"}, {0, 1}),
         _viewsField(_haveViews), _check("Save all elements", "Mesh", "SaveAll"),
         _adaptedField(_haveViews)});
    }

    // the views chosen, once the answer is OK
    int _askViews(const std::string &title, std::function<Item()> fill,
                  std::function<bool()> active)
    {
      _views = _viewsToSave();
      int answer = _ask(title, fill);
      if(answer == Gui::ExportGoAhead && active())
        _setNum("Mesh", "SaveViews", _views);
      return answer;
    }

    Item _meshStat()
    {
      return vbox(
        {_check("Save all elements", "Mesh", "SaveAll"),
         _check("Print elementary tags", "Print", "PostElementary"),
         _check("Print element numbers", "Print", "PostElement"),
         _check("Print SICN quality measure", "Print", "PostSICN"),
         _check("Print SIGE quality measure", "Print", "PostSIGE"),
         _check("Print Gamma quality measure", "Print", "PostGamma"),
         _check("Print Eta quality measure", "Print", "PostEta"),
         _check("Print Disto quality measure", "Print", "PostDisto")});
    }

    Item _unvInp()
    {
      return vbox(
        {_check("Save all elements", "Mesh", "SaveAll"),
         _check("Save groups of nodes", "Mesh", "SaveGroupsOfNodes")});
    }

    // bits of Mesh.SaveAll and of Mesh.SaveGroupsOfNodes
    Item _keyRad()
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
      auto readGroup = [](int bit) {
        return [bit]() {
          return ((int)_num("Mesh", "SaveGroupsOfNodes") & bit) != 0;
        };
      };
      auto writeGroup = [](int bit) {
        return [bit](bool on) {
          int g = (int)_num("Mesh", "SaveGroupsOfNodes") & ~bit;
          if(on) g |= bit;
          _setNum("Mesh", "SaveGroupsOfNodes", g);
        };
      };
      return vbox(
        {_choose("Line", what, readBits(4, 8), writeBits(4, 8)),
         _choose("Surface", what, readBits(16, 32), writeBits(16, 32)),
         _choose("Volume", what, readBits(64, 128), writeBits(64, 128)),
         check("Save groups of elements", readGroup(2), writeGroup(2)),
         check("Save groups of nodes", readGroup(1), writeGroup(1))});
    }

    Item _bdf()
    {
      return vbox(
        {_choose("Format", "Mesh", "BdfFieldFormat",
                 {"Free field", "Small field", "Long field"}, {0, 1, 2}),
         _choose("Element tag", "Mesh", "SaveElementTagType",
                 {"Elementary entity", "Physical entity", "Partition"},
                 {1, 2, 3}),
         _check("Save all elements", "Mesh", "SaveAll")});
    }

    Item _stl()
    {
      return vbox(
        {_choose("Format", "Mesh", "Binary", {"ASCII", "Binary"}, {0, 1}),
         _check("Save all elements", "Mesh", "SaveAll").enabledWhen([]() {
           return (int)_num("Mesh", "StlOneSolidPerSurface") != 2;
         }),
         _choose("Solid", "Mesh", "StlOneSolidPerSurface",
                 {"Single", "Per surface", "Per physical surface"},
                 {0, 1, 2})});
    }

    Item _genericMesh(bool binary, bool elementTag)
    {
      return vbox(
        {_choose("Format", "Mesh", "Binary", {"ASCII", "Binary"}, {0, 1})
           .enabledWhen([binary]() { return binary; }),
         _choose("Element tag", "Mesh", "SaveElementTagType",
                 {"Elementary entity", "Physical entity", "Partition"},
                 {1, 2, 3})
           .enabledWhen([elementTag]() { return elementTag; }),
         _check("Save all elements", "Mesh", "SaveAll")});
    }

    // --- the views, which write what they choose

#if defined(HAVE_POST)
    // write the current, visible or all views (which = 0, 1 or 2): in the
    // file, or if the format cannot hold several, in a file for each,
    // name_i.ext
    void _saveViews(const std::string &name, int which, int format,
                    bool canAppend)
    {
      std::vector<PView *> views;
      if(which == 0 && PView::list.size()) {
        int iview = Gui::instance().options.view;
        if(iview < 0 || iview >= (int)PView::list.size()) {
          Msg::Info("No or invalid current view: saving View[0]");
          iview = 0;
        }
        views.push_back(PView::list[iview]);
      }
      else {
        for(auto v : PView::list)
          if(which == 2 || v->getOptions()->visible) views.push_back(v);
      }
      if(views.empty()) {
        Msg::Error((which == 1) ? "No visible view" : "No views to save");
        return;
      }
      std::vector<std::string> split = SplitFileName(name);
      std::vector<std::pair<std::string, bool> > files;
      for(std::size_t i = 0; i < views.size(); i++) {
        std::string fileName = name;
        if(!canAppend && views.size() > 1)
          fileName = split[0] + split[1] + "_" +
                     std::to_string(views[i]->getIndex()) + split[2];
        views[i]->write(fileName, format, i ? canAppend : false, &files);
      }
      CreateReadBackScript(name, files);
    }

    // not an option: asked each time, and forgotten
    const std::vector<std::string> _whichViews = {"Current", "Visible", "All"};

    Item _pos(const std::string &name)
    {
      static int which = 0, flavour = 0;
      which = 0;
      flavour = 0;
      return vbox(
        {choice("View(s)", &which, _whichViews, {0, 1, 2}),
         choice("Format", &flavour, {"Parsed", "Legacy ASCII", "Legacy Binary"},
                {0, 1, 2}),
         _check("Save high order views refined", "PostProcessing",
                "SaveAdapted"),
         hbox({button("OK", [name]() {
           const int formats[] = {PView::POS_PARSED, PView::POS_ASCII,
                                  PView::POS_BINARY};
           int format = formats[flavour];
           _saveViews(name, which, format, format == PView::POS_PARSED);
         })})});
    }

    Item _x3dView(const std::string &name)
    {
      static int which = 0;
      which = 0;
      return vbox(
        {choice("View(s)", &which, _whichViews, {0, 1, 2}),
         _check("Remove inner borders", "Print", "X3dRemoveInnerBorders"),
         number("Log10(Precision)",
                []() { return std::log10(_num("Print", "X3dPrecision")); },
                [](double v) {
                  _setNum("Print", "X3dPrecision", std::pow(10., v));
                })
             .tip("Print.X3dPrecision")
             .within(-16, 16, .25).share(.7).tight(),
         _value("Transparency", "Print", "X3dTransparency", 0., 1., .05).share(.7).tight(),
         _check("High compatibility (no scale)", "Print", "X3dCompatibility"),
         hbox(
           {button("OK", [name]() {
             _saveViews(name, which, PView::X3D, false);
           })})});
    }

    Item _genericView(const std::string &name, int format)
    {
      static int which = 0;
      which = 0;
      return vbox({choice("View(s)", &which, _whichViews, {0, 1, 2}),
                   hbox({button("OK", [name, format]() {
                     _saveViews(name, which, format, false);
                   })})});
    }
#endif

  } // namespace

  int askOptions(int format, const std::string &fileName,
                 const std::string &entry)
  {
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
      return _ask("JPEG Options", []() { return _bitmap(FORMAT_JPEG); });
    case FORMAT_PNG:
      return _ask("PNG Options", []() { return _bitmap(FORMAT_PNG); });
    case FORMAT_PPM:
      return _ask("PPM Options", []() { return _bitmap(FORMAT_PPM); });
    case FORMAT_YUV:
      return _ask("YUV Options", []() { return _bitmap(FORMAT_YUV); });
    case FORMAT_GIF: return _ask("GIF Options", _gif);
    case FORMAT_PGF: return _ask("PGF Options", _pgf);
    case FORMAT_EPS:
      return _ask("EPS Options", []() { return _gl2ps(FORMAT_EPS); });
    case FORMAT_PS:
      return _ask("PS Options", []() { return _gl2ps(FORMAT_PS); });
    case FORMAT_PDF:
      return _ask("PDF Options", []() { return _gl2ps(FORMAT_PDF); });
    case FORMAT_SVG:
      return _ask("SVG Options", []() { return _gl2ps(FORMAT_SVG); });
    case FORMAT_TIKZ:
      return _ask("TIKZ Options", []() { return _gl2ps(FORMAT_TIKZ); });
    case FORMAT_TEX: return _ask("LaTeX Options", _tex);
    case FORMAT_MPEG:
    case FORMAT_MP4:
    case FORMAT_MPEG_PREVIEW:
      return _ask("Movie Options", [&]() { return _mpeg(fileName); });
    // --- the model
    case FORMAT_OPT:
      return _ask("Options", [&]() { return _options(fileName); });
    case FORMAT_GEO: return _ask("GEO Options", _geo);
    // --- the mesh
    case FORMAT_MSH: return _askViews("MSH Options", _msh, _mshViews);
    case FORMAT_VTU:
    case FORMAT_PVTU: return _askViews("VTU Options", _vtu, _haveViews);
    case FORMAT_UNV: return _ask("UNV Options", _unvInp);
    case FORMAT_INP: return _ask("Abaqus INP Options", _unvInp);
    case FORMAT_KEY: return _ask("LSDYNA KEY Options", _keyRad);
    case FORMAT_RAD: return _ask("RADIOSS Block Options", _keyRad);
    case FORMAT_BDF: return _ask("BDF Options", _bdf);
    case FORMAT_STL: return _ask("STL Options", _stl);
    case FORMAT_VTK:
      return _ask("VTK Options", []() { return _genericMesh(true, false); });
    case FORMAT_TOCHNOG:
      return _ask("Tochnog Options",
                  []() { return _genericMesh(true, false); });
    case FORMAT_DIFF:
      return _ask("Diffpack Options",
                  []() { return _genericMesh(true, false); });
    case FORMAT_MESH:
      return _ask("MESH Options", []() { return _genericMesh(false, true); });
    case FORMAT_IR3:
      return _ask("Iridium Options",
                  []() { return _genericMesh(false, true); });
    case FORMAT_CELUM:
      return _ask("CELUM Options", []() { return _genericMesh(false, false); });
    case FORMAT_SU2:
      return _ask("SU2 Options", []() { return _genericMesh(false, false); });
    case FORMAT_MED: return _askViews("MED Options", _med, _haveViews);
    case FORMAT_OFF:
      return _ask("OFF Options", []() { return _genericMesh(false, false); });
    case FORMAT_OBJ:
      return _ask("OBJ Options", []() { return _genericMesh(false, false); });
    case FORMAT_MAIL:
      return _ask("MAIL Options", []() { return _genericMesh(false, false); });
    case FORMAT_MATLAB:
      return _ask("MATLAB Options",
                  []() { return _genericMesh(false, false); });
    case FORMAT_P3D:
      return _ask("P3D Options", []() { return _genericMesh(false, false); });
    case FORMAT_VRML:
      return _ask("VRML Options", []() { return _genericMesh(false, false); });
    case FORMAT_PLY2:
      return _ask("PLY2 Options", []() { return _genericMesh(false, false); });
    case FORMAT_NEU:
      return _ask("NEU Options", []() { return _genericMesh(false, false); });
      // --- the views, or the mesh where there is no view to write
#if defined(HAVE_POST)
    case FORMAT_POS:
      if(statistics) return _ask("POS Options", _meshStat);
      return _ask("POS Options", [&]() { return _pos(fileName); });
    case FORMAT_RMED:
      return _ask("MED Options",
                  [&]() { return _genericView(fileName, PView::MED); });
    case FORMAT_TXT:
      return _ask("TXT Options",
                  [&]() { return _genericView(fileName, PView::TXT); });
    case FORMAT_X3D:
      if(views)
        return _ask("X3D Options", [&]() { return _x3dView(fileName); });
      return _ask("X3D Options", []() { return _genericMesh(false, false); });
#else
    case FORMAT_POS: return _ask("POS Options", _meshStat);
    case FORMAT_X3D:
      return _ask("X3D Options", []() { return _genericMesh(false, false); });
#endif
    default: return Gui::ExportGoAhead;
    }
  }

} // namespace Export

int GuiExport::ask(const std::string &title,
                   const std::function<Ui::Item()> &fill)
{
  _title = title;
  _fill = fill;
  _answer = -1;
  _remembered = false;
  show();
  while(_answer < 0 && visible()) Gui::instance().wait(0.05, true);
  if(_answer < 0) _answer = Gui::ExportCancelled;
  hide();
  if(_answer == Gui::ExportCancelled) {
    for(std::size_t i = 0; i < _fields.size(); i++) {
      const Ui::Field &f = _fields[i];
      if(f.kind == Ui::Text || f.kind == Ui::Output) {
        if(f.writeText) const_cast<Ui::Field &>(f).setText(_texts[i]);
      }
      else
        const_cast<Ui::Field &>(f).setNumber(_numbers[i]);
    }
  }
  return _answer;
}

// a form that writes the file itself declares its own OK, answering "done"; one
// that only sets options is given one answering "go ahead"
Ui::Form GuiExport::build()
{
  using namespace Ui;
  using namespace Declare;
  Item given = _fill ? _fill() : Item();
  Box body;
  if(given.kind == Item::ABox && given.box->direction == Box::Down)
    body = *given.box;
  else
    body.items.push_back(given);
  Box row;
  row.direction = Box::Across;
  if(body.items.size() && body.items.back().kind == Item::ABox &&
     body.items.back().box->direction == Box::Across) {
    bool buttons = true;
    for(const Item &i : body.items.back().box->items)
      if(i.kind != Item::AField || i.field.kind != Action) buttons = false;
    if(buttons) {
      row = *body.items.back().box;
      body.items.pop_back();
    }
  }
  bool writes = false;
  for(Item &i : row.items) {
    if(i.field.label != "OK") continue;
    writes = true;
    std::function<void()> write = i.field.changed;
    i.field.byDefault().onChanged([write, this]() {
      if(_answer >= 0) return;
      if(write) write();
      _answer = Gui::ExportDone;
    });
  }
  if(!writes)
    row.items.push_back(button("OK", [this]() {
                          if(_answer < 0) _answer = Gui::ExportGoAhead;
                        }).byDefault());
  row.items.push_back(button("Cancel", [this]() {
    if(_answer < 0) _answer = Gui::ExportCancelled;
  }));
  row.items.insert(row.items.begin(), gap());
  body.items.push_back(row);

  if(!_remembered) {
    _fields.clear();
    _numbers.clear();
    _texts.clear();
    std::function<void(const Item &)> each = [&](const Item &it) {
      if(it.kind == Item::ABox)
        for(const Item &i : it.box->items) each(i);
      if(it.kind != Item::AField) return;
      const Field &f = it.field;
      if(!f.readNumber && !f.readText) return;
      _fields.push_back(f);
      _numbers.push_back(f.getNumber());
      _texts.push_back(f.getText());
    };
    each(Item(body));
    _remembered = true;
  }
  return {"export", _title, body};
}
