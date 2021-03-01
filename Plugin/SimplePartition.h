// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SIMPLE_PARTITION_H
#define SIMPLE_PARTITION_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterSimplePartitionPlugin();
}

class GMSH_SimplePartitionPlugin : public GMSH_MeshPlugin {
public:
  GMSH_SimplePartitionPlugin() {}
  std::string getName() const { return "SimplePartition"; }
  std::string getShortHelp() const { return "Simple mesh partitioner"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  void run();
};

#endif
