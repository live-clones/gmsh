// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// CGNSOptions.h - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#ifndef _CGNSOPTIONS_H_
#define _CGNSOPTIONS_H_

struct CGNSOptions
{
  // Types
  enum CGNSConnectivityNodeType {
    OneToOne,
    Generalized
  };

  // Data
  int vectorDim;                        // Number of dimensions in a vector
                                        // (only relevant for a 2D mesh)
  int gridConnectivityLocation;         // Location of connectivity
                                        // Same as type GridLocation_t in
                                        // 'cgnslib.h'
  CGNSConnectivityNodeType connectivityNodeType;
                                        // Type of CGNS connectivity description
  std::string baseName;
  std::string zoneName;

  // Default values
  CGNSOptions() :
    vectorDim(2),
    gridConnectivityLocation(2),  // Assumes Vertex = 2 in cgnslib.h
    connectivityNodeType(Generalized),
    baseName("Base_0"),
    zoneName("Zone_&I0&")
  { }
};

#endif
