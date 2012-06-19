// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GRegion.h"

class VoronoiElement;

class clip{
 public:
  clip();
  ~clip();
  void execute();
  void execute(GRegion*);
  void execute(std::vector<SPoint3>&,std::vector<VoronoiElement>&);
  double min(double,double);
  double max(double,double);
  int category(int,int,int,int);
  void print_segment(SPoint3,SPoint3,std::ofstream&);
};
