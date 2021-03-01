// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#ifndef POINTINSERTION_H
#define POINTINSERTION_H

#include "STensor3.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class GFace;
class GRegion;
class MVertex;

extern bool old_algo_hexa();

class Filler2D {
public:
  Filler2D();
  ~Filler2D();
  void pointInsertion2D(GFace *gf, std::vector<MVertex *> &packed,
                        std::vector<SMetric3> &metrics);

private:
  static double time_bgm_and_smoothing, time_insertion;
};

class Filler3D {
private:
  static std::vector<MVertex *>
    new_vertices; // these are used in meshGRegion.cpp using static !!!
  static double time_smoothing, time_insert_points, time_meshing;

public:
  Filler3D();
  ~Filler3D();
  virtual bool treat_region(GRegion *);
  static int get_nbr_new_vertices();
  static MVertex *get_new_vertex(int);
};

#endif
