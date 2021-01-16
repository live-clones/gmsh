// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string.h>
#include "GModel.h"
#include "OS.h"
#include "GmshMessage.h"

int GModel::readMSH(const std::string &name)
{
  FILE *fp = Fopen(name.c_str(), "rb");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // detect prehistoric MSH files (without MeshFormat header)
  char str[256] = "";
  if(!fgets(str, sizeof(str), fp)) {
    fclose(fp);
    return 0;
  }
  if(!strncmp(&str[1], "NOD", 3) || !strncmp(&str[1], "NOE", 3)) {
    fclose(fp);
    return _readMSH2(name);
  }
  strcpy(str, "");
  rewind(fp);

  while(1) {
    while(str[0] != '$') {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    }

    if(feof(fp)) break;

    // $MeshFormat section
    if(!strncmp(&str[1], "MeshFormat", 10)) {
      if(!fgets(str, sizeof(str), fp)) {
        fclose(fp);
        return 0;
      }
      double version = 0.;
      int format, size;
      if(sscanf(str, "%lf %d %d", &version, &format, &size) != 3) {
        fclose(fp);
        return 0;
      }
      fclose(fp);
      if(version < 3.0) { return _readMSH2(name); }
      else if(version < 4.0) {
        return _readMSH3(name);
      }
      else if(version < 5.0) {
        return _readMSH4(name);
      }
      else {
        Msg::Error("Unknown MSH file version %g", version);
        return 0;
      }
    }

    do {
      if(!fgets(str, sizeof(str), fp) || feof(fp)) break;
    } while(str[0] != '$');
  }

  fclose(fp);

  return 0;
}

int GModel::writeMSH(const std::string &name, double version, bool binary,
                     bool saveAll, bool saveParametric, double scalingFactor,
                     int elementStartNum, int saveSinglePartition, bool append)
{
  if(version < 4.0 && getNumPartitions() > 0) {
    Msg::Warning("Saving a partitioned mesh in a format older than 4.0 may "
                 "cause information loss");
  }

  if(version < 3.0) {
    return _writeMSH2(name, version, binary, saveAll, saveParametric,
                      scalingFactor, elementStartNum, saveSinglePartition,
                      append, true);
  }
  else if(version < 4.0) {
    return _writeMSH3(name, version, binary, saveAll, saveParametric,
                      scalingFactor, elementStartNum, saveSinglePartition,
                      append);
  }
  else if(version < 5.0) {
    return _writeMSH4(name, version, binary, saveAll, saveParametric,
                      scalingFactor, append);
  }

  Msg::Error("Unknown MSH file version %g", version);
  return 0;
}

int GModel::writePartitionedMSH(const std::string &baseName, double version,
                                bool binary, bool saveAll, bool saveParametric,
                                double scalingFactor)
{
  if(version < 4.0 && getNumPartitions() > 0) {
    Msg::Warning("Saving a partitioned mesh in a format older than 4.0 may "
                 "cause information loss");
  }

  if(version < 3.0) {
    return _writePartitionedMSH2(baseName, binary, saveAll, saveParametric,
                                 scalingFactor);
  }
  else if(version < 4.0) {
    return _writePartitionedMSH3(baseName, version, binary, saveAll,
                                 saveParametric, scalingFactor);
  }
  else if(version < 5.0) {
    return _writePartitionedMSH4(baseName, version, binary, saveAll,
                                 saveParametric, scalingFactor);
  }

  Msg::Error("Unknown MSH file version %g", version);
  return 0;
}
