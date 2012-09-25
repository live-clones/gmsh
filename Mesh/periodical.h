// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "GRegion.h"

class voroMetal3D{
 private:
  int counter;
 public:
  voroMetal3D();
  ~voroMetal3D();
  void execute();
  void execute(GRegion*);
  void execute(std::vector<SPoint3>&);
  void execute(std::vector<double>&);
  void print_segment(SPoint3,SPoint3,std::ofstream&);
  void initialize_counter();
  void increase_counter();
  int get_counter();
  void print_geo_point(int,double,double,double,std::ofstream&);
  void print_geo_line(int,int,int,std::ofstream&);
  void print_geo_face(int,int,std::ofstream&);
  void print_geo_volume(int,int,std::ofstream&);
  void print_geo_line_loop(int,std::vector<int>&,std::vector<int>&,std::ofstream&);
  void print_geo_face_loop(int,std::vector<int>&,std::ofstream&);
  void correspondance();
};
