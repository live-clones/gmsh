// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include "GuiPartition.h"
#include "GuiDeclare.h"
#include "Gui.h"
#include "Context.h"
#include "GModel.h"
#include "Options.h"
#include "drawContext.h"

using namespace Declare;

#ifdef HAVE_METIS
constexpr bool metisAvailable = true;
#else
constexpr bool metisAvailable = false;
#endif

Form GuiPartition::build()
{
  auto defaults = []() {
    for(const char *name :
        {"NbPartitions", "PartitionCreateTopology", "PartitionCreateGhostCells",
         "PartitionCreatePhysicals", "MetisAlgorithm", "MetisEdgeMatching",
         "MetisRefinementAlgorithm", "PartitionTriWeight",
         "PartitionQuadWeight", "PartitionTetWeight", "PartitionPrismWeight",
         "PartitionPyramidWeight", "PartitionHexWeight"}) {
      double value;
      NumberOption(GMSH_SET_DEFAULT | GMSH_GUI, "Mesh", 0, name, value, true);
    }
  };

  auto partition = []() {
    if(GModel::current()->partitionMesh(CTX::instance()->mesh.numPartitions))
      return;
    opt_mesh_zone_definition(0, GMSH_SET, 2.); // the zones are the partitions
    opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 3.);
    CTX::instance()->mesh.changed = ENT_ALL;
    Gui::instance().resetVisibility();
    drawContext::global()->draw();
  };

  return {
    "partition", "Partition",
    vbox(
      {hbox({labeled(integer("Mesh.NbPartitions"), "Number of Partitions"),
             labeled(check("Mesh.PartitionCreateGhostCells"),
                     "Create ghost cells")}),
       hbox({labeled(check("Mesh.PartitionCreateTopology"),
                     "Create partition topology"),
             labeled(check("Mesh.PartitionCreatePhysicals"),
                     "Create physical groups")}),
       rule(),
       hbox({labeled(
               option("Mesh.MetisAlgorithm", {{"Recursive", 1}, {"K-way", 2}}),
               "Algorithm"),
             disclosure("Advanced", &advanced)}),
       visibleWhen(
         advanced,
         vbox({hbox({labeled(option("Mesh.MetisEdgeMatching",
                                    {{"Random", 1}, {"Sorted heavy-edge", 2}}),
                             "Edge matching"),
                     labeled(option("Mesh.MetisRefinementAlgorithm",
                                    {{"FM-based cut", 1},
                                     {"Greedy", 2},
                                     {"Two-sided node FM", 3},
                                     {"One-sided node FM", 4}}),
                             "Refinement algorithm")}),
               hbox({labeled(integer("Mesh.PartitionTriWeight"), "Triangle"),
                     labeled(integer("Mesh.PartitionTetWeight"), "Tetrahedron"),
                     labeled(integer("Mesh.PartitionPrismWeight"), "Prism")}),
               hbox({labeled(integer("Mesh.PartitionQuadWeight"), "Quadrangle"),
                     labeled(integer("Mesh.PartitionHexWeight"), "Hexahedron"),
                     labeled(integer("Mesh.PartitionPyramidWeight"),
                             "Pyramid")})})),
       rule(),
       hbox({button("Defaults", defaults), gap(),
             enabledWhen(metisAvailable,
                         byDefault(button("Partition", partition)))})})};
}

#endif
