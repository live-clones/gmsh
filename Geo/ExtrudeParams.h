// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRUDE_PARAMS_H
#define EXTRUDE_PARAMS_H

#include <vector>
#include <map>
#include <string>
#include "SmoothData.h"
#include "SPoint3.h"
#include "MElement.h"

// geo.Mode
#define EXTRUDED_ENTITY 1
#define COPIED_ENTITY 2

// geo.Type
#define TRANSLATE 1
#define ROTATE 2
#define TRANSLATE_ROTATE 3
#define BOUNDARY_LAYER 4

class ExtrudeParams {
public:
  ExtrudeParams(int Mode = EXTRUDED_ENTITY);
  void fill(int type, double T0, double T1, double T2, double A0, double A1,
            double A2, double X0, double X1, double X2, double angle);
  double u(int iLayer, int iElemLayer);
  void Extrude(int iLayer, int iElemLayer, double &dx, double &dy, double &dz);
  void Extrude(double t, double &x, double &y, double &z);
  void GetAffineTransform(std::vector<double> &tfo);
  struct {
    bool ExtrudeMesh;
    bool Recombine;
    int QuadToTri;
    int NbLayer;
    std::vector<int> NbElmLayer;
    std::vector<double> hLayer;
    // added by Trevor Strickler 07/07/2013 (determines if a layer is scaled by
    // source grid size (1) or not (0))...only meant for boundary layers
    bool ScaleLast;
    std::map<int, std::pair<double, std::vector<int> > > Holes;
    int ViewIndex, BoundaryLayerIndex;
  } mesh;
  struct {
    int Mode;
    int Type;
    int Source;
    double trans[3];
    double axe[3], pt[3], angle;
  } geo;

  // Added by Trevor Strickler: to scale last layer size locally. If one section
  // of the boundary layer index = 0 or 1 is not supposed to be scaled...that
  // section's normals will have scaleFactor = 1.0 (exactly 1.0 to all sig figs)
  // ...however, if that non-scaled section borders a scaled section, the
  // boundary normals will extrude consistently (an average of scaled and
  // non-scaled heights).
  static bool calcLayerScaleFactor[2]; // give a global awareness of whether
                                       // last layer scaling is to be used.
  static smooth_data *normals[2];
  static std::vector<SPoint3> normalsCoherence;
};

#endif
