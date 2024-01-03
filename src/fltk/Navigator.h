// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Gilles Marckmann <gilles.marckmann@ec-nantes.fr>
//

#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "drawContext.h"
#include "Camera.h"
#include "GamePad.h"

typedef enum { AXE_X, AXE_Y, AXE_Z } AXE;
typedef enum { PLANE, PEDESTRIAN, DIVER, CAR } NAV_MODE;

class Navigator {
public:
  double ax0, ax1, ax0_cur, ax1_cur;
  double speed, acc;
  double lateral;
  double angular_lat;
  double angular_up;
  double angular_fr;
  AXE along;
  NAV_MODE mode;
  double axe[3];
  double quatern[4];
  bool awake;
  double reference_angle;
  double reference_speed;
  double angle_up;
  double angle_rl;
  double angle_fr;
  drawContext *ctx;
  double frequency;
  GamePad *pad;
  double azimut;
  double elevation;
  double lift;
  int ncount;

public:
  Navigator(double _freq, drawContext *_ctx);
  Navigator();
  ~Navigator();
  void setFrequency(double _freq);
  void setResponseFrequency(double _freq);
  void setDrawContext(drawContext *_ctx);
  void move();
  void drawIcons();
};

#endif
