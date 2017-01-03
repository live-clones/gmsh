// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshMessage.h"
#include "Geo.h"
#include "ExtrudeParams.h"

smooth_data* ExtrudeParams::normals[2] = {0, 0};
std::vector<SPoint3> ExtrudeParams::normalsCoherence;

// Scale last layer size locally If one section of the boundary layer index = 0
// or 1 is not supposed to be scaled...that section's normals will have
// scaleFactor = 1.0 (exactly 1.0 to all sig figs) ...however, if that
// non-scaled section borders a scaled section, the boundary normals will
// extrude consistently (an average of scaled and non-scaled heights).
bool ExtrudeParams::calcLayerScaleFactor[2] = {0, 0};

static void Projette(double p[3], double mat[3][3])
{
  double X = p[0] * mat[0][0] + p[1] * mat[0][1] + p[2] * mat[0][2];
  double Y = p[0] * mat[1][0] + p[1] * mat[1][1] + p[2] * mat[1][2];
  double Z = p[0] * mat[2][0] + p[1] * mat[2][1] + p[2] * mat[2][2];
  p[0] = X;
  p[1] = Y;
  p[2] = Z;
}

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

void ExtrudeParams::fill(int type,
                         double T0, double T1, double T2,
                         double A0, double A1, double A2,
                         double X0, double X1, double X2, double angle)
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

void ExtrudeParams::Extrude(int iLayer, int iElemLayer,
                            double &x, double &y, double &z)
{
  double t = u(iLayer, iElemLayer);
  // This definitely relies on fixing lateral boundary extruded surfaces if
  // mesh.ScaleLast is changed by ReplaceDuplicates.  This is done in
  // BoundaryLayers.cpp right now.
  if(geo.Type == BOUNDARY_LAYER && iLayer == mesh.NbLayer-1 &&
     mesh.BoundaryLayerIndex >= 0 && mesh.BoundaryLayerIndex <= 1 &&
     calcLayerScaleFactor[mesh.BoundaryLayerIndex] &&
     normals[mesh.BoundaryLayerIndex]){
    double scale = 1.0;
    normals[mesh.BoundaryLayerIndex]->get_scale(x, y, z, &scale);
    if(fabs(scale-1.0) <= xyzv::eps)
      scale = 1.0;
    else{
      if(mesh.NbLayer <= 1)
	t = t * scale;
      else
        t = (t-mesh.hLayer[mesh.NbLayer-2])*scale + mesh.hLayer[mesh.NbLayer-2];
    }
  }

  Extrude(t, x, y, z);
}

void ExtrudeParams::Rotate(double matr[3][3])
{
  Projette(geo.trans, matr);
  Projette(geo.axe, matr);
  Projette(geo.pt, matr);
  geo.angle = -geo.angle;
}

void ExtrudeParams::Extrude(double t, double &x, double &y, double &z)
{
  double dx, dy, dz, angle;
  double n[3] = {0., 0., 0.};

  switch (geo.Type) {
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
  default:
    Msg::Error("Unknown extrusion type");
    break;
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
