// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VOROMETAL_H
#define VOROMETAL_H

#include <vector>
#include "Plugin.h"

class geo_cell {
public:
  std::vector<std::pair<int, int> > lines;
  std::vector<std::vector<int> > line_loops;
  std::vector<std::vector<int> > orientations;
  std::vector<int> points2;
  std::vector<int> lines2;
  std::vector<int> line_loops2;
  std::vector<int> faces2;
  int face_loops2;
  geo_cell() {}
  ~geo_cell() {}
  int search_line(std::pair<int, int> line)
  {
    std::size_t i;
    for(i = 0; i < lines.size(); i++) {
      if(lines[i].first == line.first && lines[i].second == line.second)
        return i;
      if(lines[i].first == line.second && lines[i].second == line.first)
        return i;
    }
    return -1;
  }
};

class voroMetal3D {
private:
  int counter;

public:
  voroMetal3D() {}
  ~voroMetal3D() {}
  void execute(double);
  void execute(GRegion *, double);
  void execute(std::vector<SPoint3> &, std::vector<double> &, int, double,
               double, double, double);
  void execute(std::vector<double> &, int, double, double, double, double);
  void print_segment(SPoint3, SPoint3, std::ofstream &);
  void initialize_counter();
  void increase_counter();
  int get_counter();
  void print_geo_point(int, double, double, double, std::ofstream &);
  void print_geo_line(int, int, int, std::ofstream &);
  void print_geo_face(int, int, std::ofstream &);
  void print_geo_physical_face(int, int, std::ofstream &);
  void print_geo_volume(int, int, std::ofstream &);
  void print_geo_physical_volume(int, int, std::ofstream &);
  void print_geo_line_loop(int, std::vector<int> &, std::vector<int> &,
                           std::ofstream &);
  void print_geo_face_loop(int, std::vector<int> &, std::ofstream &);
  void correspondance(double, double, double, double);
  bool correspondance(double, double, double, double, int &, double, double,
                      double);
  void correspondance(double, double, double, double, int, bool &, double,
                      double, double);
  bool equal(double, double, double);
};

extern "C" {
GMSH_Plugin *GMSH_RegisterVoroMetalPlugin();
}

class GMSH_VoroMetalPlugin : public GMSH_PostPlugin {
public:
  GMSH_VoroMetalPlugin() {}
  std::string getName() const { return "VoroMetal"; }
  std::string getShortHelp() const { return "Voronoi microstructures"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "Tristan Carrier & Maxime Melchior"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
