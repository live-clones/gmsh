// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "Gui.h"
#include "GuiDeclare.h"
#include "Options.h"

using namespace Ui;
using namespace Declare;

namespace {

  // a Mesh option, by its name in the option table
  Field mesh(FieldKind kind, const std::string &label, const char *name)
  {
    return option(kind, label, "Mesh", name);
  }

  Field meshChoice(const std::string &label, const char *name,
                   const std::vector<std::string> &choices,
                   const std::vector<int> &values)
  {
    Field f = mesh(Choice, label, name);
    f.choices = choices;
    f.values = values;
    return f;
  }

  // every option of the partitioner back to what Gmsh was built with
  void defaults()
  {
    for(const char *name :
        {"NbPartitions", "PartitionCreateTopology", "PartitionCreateGhostCells",
         "PartitionCreatePhysicals", "MetisAlgorithm", "MetisEdgeMatching",
         "MetisRefinementAlgorithm", "PartitionTriWeight", "PartitionQuadWeight",
         "PartitionTetWeight", "PartitionPrismWeight", "PartitionPyramidWeight",
         "PartitionHexWeight"}) {
      for(StringXNumber *o = GetNumberOptionCategory("Mesh"); o->str; o++)
        if(!strcmp(o->str, name))
          o->function(0, GMSH_SET | GMSH_GUI, o->def);
    }
  }

#ifdef HAVE_METIS
  constexpr bool metisAvailable = true;
#else
  constexpr bool metisAvailable = false;
#endif

} // namespace

Form GuiPartition::build()
{
  Form f;
  f.id = "partition";
  f.title = "Partition";

  f.panes.push_back(ruled(pane(
    "", {mesh(Integer, "Number of Partitions", "NbPartitions"),
         beside(mesh(Check, "Create ghost cells", "PartitionCreateGhostCells")),
         mesh(Check, "Create partition topology", "PartitionCreateTopology"),
         beside(mesh(Check, "Create physical groups", "PartitionCreatePhysicals"))})));

  f.panes.push_back(ruled(pane(
    "", {meshChoice("Algorithm", "MetisAlgorithm", {"Recursive", "K-way"}, {1, 2}),
         beside(disclosure("Advanced", &advanced))})));

  Pane advancedPane = pane(
    "", {meshChoice("Edge matching", "MetisEdgeMatching",
                    {"Random", "Sorted heavy-edge"}, {1, 2}),
         beside(meshChoice("Refinement algorithm", "MetisRefinementAlgorithm",
                           {"FM-based cut", "Greedy", "Two-sided node FM",
                            "One-sided node FM"},
                           {1, 2, 3, 4})),
         mesh(Integer, "Triangle", "PartitionTriWeight"),
         beside(mesh(Integer, "Tetrahedron", "PartitionTetWeight")),
         beside(mesh(Integer, "Prism", "PartitionPrismWeight")),
         mesh(Integer, "Quadrangle", "PartitionQuadWeight"),
         beside(mesh(Integer, "Hexahedron", "PartitionHexWeight")),
         beside(mesh(Integer, "Pyramid", "PartitionPyramidWeight"))});
  advancedPane.visible = [this]() { return advanced; };
  f.panes.push_back(ruled(advancedPane));

  Button reset;
  reset.label = "Defaults";
  reset.action = defaults;
  reset.apart = true;
  Button partition;
  partition.label = "Partition";
  partition.action = meshPartition;
  partition.isDefault = true;
  partition.enabled = []() { return metisAvailable; };
  f.buttons = {reset, partition};
  return f;
}

#endif
