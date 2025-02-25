// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef POINTINSERTION_H
#define POINTINSERTION_H

#include "STensor3.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class GSurface;
class GVolume;
class MNode;

extern bool old_algo_hexa();

class Filler2D {
public:
  Filler2D();
  ~Filler2D();
  void pointInsertion2D(GSurface *gf, std::vector<MNode *> &packed,
                        std::vector<SMetric3> &metrics);

private:
  static double time_bgm_and_smoothing, time_insertion;
};

class Filler3D {
private:
  static std::vector<MNode *>
    new_vertices; // these are used in meshGRegion.cpp using static !!!
  static double time_smoothing, time_insert_points, time_meshing;

public:
  Filler3D();
  ~Filler3D();
  virtual bool treat_region(GVolume *);
  static int get_nbr_new_vertices();
  static MNode *get_new_vertex(int);
};

#endif
