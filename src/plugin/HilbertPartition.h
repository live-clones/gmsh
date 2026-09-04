// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HILBERT_PARTITION_H
#define HILBERT_PARTITION_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterHilbertPartitionPlugin();
}

class GMSH_HilbertPartitionPlugin : public GMSH_MeshPlugin {
public:
  GMSH_HilbertPartitionPlugin() {}
  std::string getName() const { return "HilbertPartition"; }
  std::string getShortHelp() const { return "Hilbert curve mesh partitioner"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  int run();
};

#endif
