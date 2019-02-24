// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// CGNSOptions.h - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#ifndef CGNSOPTIONS_H
#define CGNSOPTIONS_H

#include <string>

class CGNSOptions {
public:
  enum CGNSLocationType { LocVertex = 0, LocFace = 1 };

  std::string baseName;
  std::string zoneName;
  std::string interfaceName;
  std::string patchName;
  int gridConnectivityLocation; // Location of connectivity(values
                                // CGNSLocationType)
  int bocoLocation; // Location of BC (values
                    // CGNSLocationType)
  int normalSource; // Source for BC normal data
                    // 0 - do not write normals
                    // 1 - geometry
                    // 2 - elements
  int vectorDim; // Number of dimensions in a vector
                 // (only relevant for a 2D mesh)
  bool structuredMesh; // = 1 if structured mesh, = 0 if un-structured mesh
  bool writeBC;
  bool writeUserDef; // T - write user-defined elements for
                     //     element types unsupported by CGNS

  CGNSOptions() { setDefaults(); }
  ~CGNSOptions() {}
  void setDefaults()
  {
    baseName = "Base_1";
    zoneName = "Zone_&I%4&";
    interfaceName = "Interface_&I%4&";
    patchName = "Patch_&I%4&";
    gridConnectivityLocation = 0;
    bocoLocation = 0;
    normalSource = 1;
    vectorDim = 2;
    structuredMesh = 0;
    writeBC = true;
    writeUserDef = false;
  }
};

#endif
