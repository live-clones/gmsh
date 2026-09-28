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
    CTX::instance()->meshChanged();
    Gui::instance().resetVisibility();
    drawContext::global()->draw();
  };

  return {
    "partition", "Partition",
    vbox({hbox({integer("Number of Partitions", "Mesh.NbPartitions"),
                check("Create ghost cells", "Mesh.PartitionCreateGhostCells")}),
          hbox({check("Create partition topology", "Mesh.PartitionCreateTopology"),
                check("Create physical groups", "Mesh.PartitionCreatePhysicals")}),
          rule(),
          hbox({choice("Algorithm", "Mesh.MetisAlgorithm",
                       Pairs{{"Recursive", 1}, {"K-way", 2}}),
                disclosure("Advanced", &advanced)}),
          vbox({hbox({choice("Edge matching", "Mesh.MetisEdgeMatching",
                             Pairs{{"Random", 1}, {"Sorted heavy-edge", 2}}),
                      choice("Refinement algorithm",
                             "Mesh.MetisRefinementAlgorithm",
                             Pairs{{"FM-based cut", 1},
                                   {"Greedy", 2},
                                   {"Two-sided node FM", 3},
                                   {"One-sided node FM", 4}})}),
                hbox({integer("Triangle", "Mesh.PartitionTriWeight"),
                      integer("Tetrahedron", "Mesh.PartitionTetWeight"),
                      integer("Prism", "Mesh.PartitionPrismWeight")}),
                hbox({integer("Quadrangle", "Mesh.PartitionQuadWeight"),
                      integer("Hexahedron", "Mesh.PartitionHexWeight"),
                      integer("Pyramid", "Mesh.PartitionPyramidWeight")})})
            .visibleWhen(advanced),
          rule(),
          hbox({button("Defaults", defaults), gap(),
                button("Partition", partition)
                  .byDefault()
                  .enabledWhen(metisAvailable)})})};
}

#endif
