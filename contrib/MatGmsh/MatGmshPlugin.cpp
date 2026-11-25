// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
// See LICENSE.txt in the Gmsh root directory for license information.

#include "MatGmshPlugin.h"
#include "MatPipeline.h"
#include "GModel.h"
#include "PViewOptions.h"

#include <cmath>
#include <exception>
#include <filesystem>
#include <utility>

GMSH_MatGmshPlugin::GMSH_MatGmshPlugin()
  : GMSH_PostPlugin(
      {{GMSH_FULLRC, "Thickness", nullptr, 1., ""},
       {GMSH_FULLRC, "Project", nullptr, 0., ""},
       {GMSH_FULLRC, "Stage", nullptr, 0., ""},
       {GMSH_FULLRC, "ExtensionLength", nullptr, 0., ""},
       {GMSH_FULLRC, "ExtensionLayers", nullptr, 12., ""},
       {GMSH_FULLRC, "ShowStages", nullptr, 1., ""},
       {GMSH_FULLRC, "LegacyCleanup", nullptr, 1., ""}},
      {{GMSH_FULLRC, "OutputPrefix", nullptr, "matgmsh", ""}})
{
}

std::string GMSH_MatGmshPlugin::getHelp() const
{
  return "Plugin(MatGmsh) computes the filtered medial-axis transform from "
         "the existing first-order triangular surface mesh of the current "
         "model. Mesh the source surfaces before running the plugin. The "
         "source CAD and its surface mesh are retained.\n\n"
         "`Thickness' is the maximum-thickness parameter. `Stage' selects "
         "the last stage: 0 for filtered MAT, 1 for optional projection, "
         "2 for free-boundary extension. `Project' enables local "
         "mid-surface projection; a rejected projection retains its input. "
         "The projection setting has no effect when Stage is 0.\n\n"
         "`ExtensionLength' bounds the extension distance (0 means three "
         "times Thickness); `ExtensionLayers' controls the number of "
         "layers. Reaching this distance is not a successful contact: "
         "unresolved fronts are recorded in the report. `LegacyCleanup' "
         "preserves the historical filtered-MAT cleanup policy.\n\n"
         "The result is displayed in a new list-based view, colored by "
         "branch. With `ShowStages', earlier stages are also available "
         "as initially hidden views. These views do not replace the CAD. "
         "If `OutputPrefix' is nonempty, the computed mesh stages are "
         "written as <prefix>_<stage>.msh and the diagnostic report as "
         "<prefix>_report.json. An empty prefix disables file output.";
}

PView *GMSH_MatGmshPlugin::execute(PView *v)
{
  using namespace matgmsh_native;
  for(int i = 0; i < getNbOptions(); ++i) {
    if(!std::isfinite(option(i))) {
      Msg::Error("Plugin(MatGmsh): option %s must be finite", getOption(i)->str);
      return v;
    }
  }
  if(option(0) <= 0. || option(2) < 0. || option(2) > 2. ||
     option(2) != std::floor(option(2)) || option(3) < 0. ||
     option(4) < 1. || option(4) > 10000. ||
     option(4) != std::floor(option(4))) {
    Msg::Error("Plugin(MatGmsh): positive Thickness, Stage 0/1/2, "
               "nonnegative ExtensionLength and integer ExtensionLayers "
               "between 1 and 10000 are required");
    return v;
  }
  Options options;
  options.thickness = option(0);
  options.project = option(1) != 0.;
  options.stopAfter = static_cast<Stage>(static_cast<int>(option(2)));
  options.extensionLength = option(3);
  options.extensionLayers = static_cast<int>(option(4));
  options.legacyCleanup = option(6) != 0.;
  Result result;
  std::string error;
  try {
    if(!compute(GModel::current(), options, result, error)) {
      Msg::Error("Plugin(MatGmsh): %s", error.c_str());
      return v;
    }
    for(const auto &warning : result.warnings)
      Msg::Warning("Plugin(MatGmsh): %s", warning.c_str());

    std::vector<std::pair<std::string, const Mesh *> > stages;
    if(!result.raw.triangles.empty()) stages.push_back({"raw", &result.raw});
    stages.push_back({"filtered", &result.filtered});
    if(options.stopAfter != Stage::Filtered)
      stages.push_back({"projected", &result.projected});
    if(options.stopAfter == Stage::Extended)
      stages.push_back({"extended", &result.extended});

    const std::string prefix = optionStr(0);
    if(!prefix.empty()) {
      const auto parent = std::filesystem::path(prefix).parent_path();
      if(!parent.empty()) std::filesystem::create_directories(parent);
      for(const auto &stage : stages) {
        if(stage.second->triangles.empty()) continue;
        if(!writeMesh(*stage.second, prefix + "_" + stage.first + ".msh", error)) {
          Msg::Error("Plugin(MatGmsh): %s", error.c_str());
          return v;
        }
      }
      if(!writeReport(result, options, prefix + "_report.json", error)) {
        Msg::Error("Plugin(MatGmsh): %s", error.c_str());
        return v;
      }
    }

    PView *last = v;
    for(std::size_t i = 0; i < stages.size(); ++i) {
      const bool final = i + 1 == stages.size();
      if(!final && option(5) == 0.) continue;
      const Mesh &mesh = *stages[i].second;
      if(mesh.triangles.empty()) continue;
      PView *view = new PView();
      PViewDataList *data = getDataList(view);
      for(std::size_t t = 0; t < mesh.triangles.size() / 3; ++t) {
        auto *values = data->incrementList(1, TYPE_TRI);
        for(int component = 0; component < 3; ++component)
          for(int corner = 0; corner < 3; ++corner)
            values->push_back(mesh.xyz[3 * mesh.triangles[3 * t + corner] + component]);
        const double branch = t < mesh.branch.size() ? mesh.branch[t] : 0.;
        values->insert(values->end(), {branch, branch, branch});
      }
      data->setName("MAT " + stages[i].first);
      data->setFileName((prefix.empty() ? "matgmsh" : prefix) + "_" +
                        stages[i].first + ".pos");
      data->finalize();
      view->getOptions()->visible = final ? 1 : 0;
      last = view;
    }
    Msg::Info("Plugin(MatGmsh): %lu filtered triangles, projection %s",
              result.filtered.triangles.size() / 3, result.projectionStatus.c_str());
    if(options.stopAfter == Stage::Extended)
      Msg::Info("Plugin(MatGmsh): extension %s; %s",
                result.extension.complete ? "complete" : "incomplete",
                result.extension.message.c_str());
    return last;
  }
  catch(const std::exception &exception) {
    Msg::Error("Plugin(MatGmsh): %s", exception.what());
    return v;
  }
}
