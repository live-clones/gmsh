// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _SIMPLE_PARTITION_H_
#define _SIMPLE_PARTITION_H_

#include "Plugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSimplePartitionPlugin();
}

class GMSH_SimplePartitionPlugin : public GMSH_PostPlugin
{
 public:
  GMSH_SimplePartitionPlugin(){}
  std::string getName() const { return "SimplePartition"; }
  std::string getShortHelp() const
  {
    return "Simple mesh partitioner";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber* getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString* getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
