// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GRegion.h"

class voroMetal3D{
 public:
  voroMetal3D();
  ~voroMetal3D();
  void execute();
  void execute(GRegion*);
  void execute(std::vector<SPoint3>&);
  void print_segment(SPoint3,SPoint3,std::ofstream&);
};