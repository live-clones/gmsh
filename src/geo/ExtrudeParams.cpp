// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "Geo.h"
#include "ExtrudeParams.h"

smooth_data *ExtrudeParams::normals[2] = {nullptr, nullptr};
std::vector<SPoint3> ExtrudeParams::normalsCoherence;

// Scale last layer size locally If one section of the boundary layer index = 0
// or 1 is not supposed to be scaled...that section's normals will have
// scaleFactor = 1.0 (exactly 1.0 to all sig figs) ...however, if that
// non-scaled section borders a scaled section, the boundary normals will
// extrude consistently (an average of scaled and non-scaled heights).
bool ExtrudeParams::calcLayerScaleFactor[2] = {0, 0};

ExtrudeParams::ExtrudeParams(int ModeEx)
{
  geo.Mode = ModeEx;
  geo.Source = -1;
  mesh.ExtrudeMesh = false;
  mesh.Recombine = false;
  mesh.QuadToTri = NO_QUADTRI;
  // determines if a layer is scaled by source grid size (1) or not (0)...only
  // meant for boundary layers
  mesh.ScaleLast = false;
  mesh.ViewIndex = -1;
  mesh.BoundaryLayerIndex = 0;
}

void ExtrudeParams::fill(int type, double T0, double T1, double T2, double A0,
                         double A1, double A2, double X0, double X1, double X2,
                         double angle)
{
  geo.trans[0] = T0;
  geo.trans[1] = T1;
  geo.trans[2] = T2;
  geo.axe[0] = A0;
  geo.axe[1] = A1;
  geo.axe[2] = A2;
  geo.pt[0] = X0;
  geo.pt[1] = X1;
  geo.pt[2] = X2;
  geo.angle = angle;
  geo.Type = type;
}

void ExtrudeParams::Extrude(int iLayer, int iElemLayer, double &x, double &y,
                            double &z)
{
  double t = u(iLayer, iElemLayer);
  // This definitely relies on fixing lateral boundary extruded surfaces if
  // mesh.ScaleLast is changed by ReplaceDuplicates.  This is done in
  // BoundaryLayers.cpp right now.
  if(geo.Type == BOUNDARY_LAYER && iLayer == mesh.NbLayer - 1 &&
     mesh.BoundaryLayerIndex >= 0 && mesh.BoundaryLayerIndex <= 1 &&
     calcLayerScaleFactor[mesh.BoundaryLayerIndex] &&
     normals[mesh.BoundaryLayerIndex]) {
    double scale = 1.0;
    normals[mesh.BoundaryLayerIndex]->get_scale(x, y, z, &scale);
    if(fabs(scale - 1.0) <= xyzv::eps)
      scale = 1.0;
    else {
      if(mesh.NbLayer <= 1)
        t = t * scale;
      else
        t = (t - mesh.hLayer[mesh.NbLayer - 2]) * scale +
            mesh.hLayer[mesh.NbLayer - 2];
    }
  }

  Extrude(t, x, y, z);
}

void ExtrudeParams::Extrude(double t, double &x, double &y, double &z)
{
  double dx, dy, dz, angle;
  double n[3] = {0., 0., 0.};

  switch(geo.Type) {
  case TRANSLATE:
    dx = geo.trans[0] * t;
    dy = geo.trans[1] * t;
    dz = geo.trans[2] * t;
    x += dx;
    y += dy;
    z += dz;
    break;
  case ROTATE:
    angle = geo.angle;
    geo.angle = geo.angle * t;
    ProtudeXYZ(x, y, z, this);
    geo.angle = angle;
    break;
  case TRANSLATE_ROTATE:
    angle = geo.angle;
    geo.angle = geo.angle * t;
    ProtudeXYZ(x, y, z, this);
    geo.angle = angle;
    dx = geo.trans[0] * t;
    dy = geo.trans[1] * t;
    dz = geo.trans[2] * t;
    x += dx;
    y += dy;
    z += dz;
    break;
  case BOUNDARY_LAYER:
    if(mesh.BoundaryLayerIndex >= 0 && mesh.BoundaryLayerIndex <= 1 &&
       normals[mesh.BoundaryLayerIndex])
      normals[mesh.BoundaryLayerIndex]->get(x, y, z, 3, n);
    x += n[0] * t;
    y += n[1] * t;
    z += n[2] * t;
    break;
  default: Msg::Error("Unknown extrusion type"); break;
  }
}

double ExtrudeParams::u(int iLayer, int iElemLayer)
{
  double t0, t1;

  if(!iLayer) {
    t0 = 0.0;
    t1 = mesh.hLayer[0];
  }
  else {
    t0 = mesh.hLayer[iLayer - 1];
    t1 = mesh.hLayer[iLayer];
  }
  double t = (double)iElemLayer / (double)mesh.NbElmLayer[iLayer];
  return t0 + t * (t1 - t0);
}

void ExtrudeParams::GetAffineTransform(std::vector<double> &tfo)
{
  tfo.clear();
  double v[3], m1[4][4], m2[4][4], m3[4][4];
  switch(geo.Type) {
  case TRANSLATE:
    SetTranslationMatrix(m1, geo.trans);
    tfo.resize(16);
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) tfo[i * 4 + j] = m1[i][j];
    break;
  case ROTATE:
  case TRANSLATE_ROTATE:
    v[0] = -geo.pt[0];
    v[1] = -geo.pt[1];
    v[2] = -geo.pt[2];
    SetTranslationMatrix(m1, v);
    SetRotationMatrix(m2, geo.axe, geo.angle);
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        m3[i][j] = 0;
        for(int k = 0; k < 4; k++) { m3[i][j] += m1[i][k] * m2[k][j]; }
      }
    }
    SetTranslationMatrix(m1, geo.pt);
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        m2[i][j] = 0;
        for(int k = 0; k < 4; k++) { m2[i][j] += m3[i][k] * m1[k][j]; }
      }
    }
    tfo.resize(16);
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++) tfo[i * 4 + j] = m2[i][j];
    if(geo.Type == TRANSLATE_ROTATE) {
      tfo[3] += geo.trans[0];
      tfo[7] += geo.trans[1];
      tfo[11] += geo.trans[2];
    }
    break;
  }
}
