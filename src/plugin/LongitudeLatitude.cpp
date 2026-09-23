// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "LongitudeLatitude.h"
#include "OpenFile.h"

StringXNumber LongituteLatitudeOptions_Number[] = {
  {GMSH_FULLRC, "View", nullptr, -1., ""}};

extern "C" {
GMSH_Plugin *GMSH_RegisterLongituteLatitudePlugin()
{
  return new GMSH_LongituteLatitudePlugin();
}
}

std::string GMSH_LongituteLatitudePlugin::getHelp() const
{
  return "Plugin(LongitudeLatitude) projects the view `View' "
         "in longitude-latitude.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(LongitudeLatitude) is executed in place.";
}

int GMSH_LongituteLatitudePlugin::getNbOptions() const
{
  return sizeof(LongituteLatitudeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_LongituteLatitudePlugin::getOption(int iopt)
{
  return &LongituteLatitudeOptions_Number[iopt];
}

PView *GMSH_LongituteLatitudePlugin::execute(PView *v)
{
  int iView = (int)LongituteLatitudeOptions_Number[0].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  // turn the vectors into the frame of each point on the sphere, at every
  // step, before the points move
  for(int step = 0; step < data1->getNumTimeSteps(); step++) {
    forEachValue(data1, step,
                 [&](int ent, int ele, int nod, double x, double y, double z) {
                   if(data1->getNumComponents(step, ent, ele) != 3) return;
                   double lon = atan2(y, x);
                   double lat = asin(z / sqrt(x * x + y * y + z * z));
                   double vin[3], vout[3];
                   for(int i = 0; i < 3; i++)
                     data1->getValue(step, ent, ele, nod, i, vin[i]);
                   double h = cos(lon) * vin[0] + sin(lon) * vin[1];
                   vout[0] = -sin(lon) * vin[0] + cos(lon) * vin[1];
                   vout[1] = -sin(lat) * h + cos(lat) * vin[2];
                   vout[2] = cos(lat) * h + sin(lat) * vin[2];
                   for(int i = 0; i < 3; i++)
                     data1->setValue(step, ent, ele, nod, i, vout[i]);
                 });
  }

  double gxmin = 180, gxmax = -180, gymin = 90, gymax = -90;
  forEachNode(data1, [&](int step, int ent, int ele, int nod) {
    double x, y, z;
    data1->getNode(step, ent, ele, nod, x, y, z);
    double lon = atan2(y, x) * 180 / M_PI;
    double lat = asin(z / sqrt(x * x + y * y + z * z)) * 180 / M_PI;
    gxmin = std::min(lon, gxmin);
    gxmax = std::max(lon, gxmax);
    gymin = std::min(lat, gymin);
    gymax = std::max(lat, gymax);
    data1->setNode(step, ent, ele, nod, lon, lat, 0);
  });

  // elements across the date line: move their nodes on the west side by 360
  // degrees, which only list data can do (model data shares its nodes)
  int step = data1->getFirstNonEmptyTimeStep();
  bool shared = !dynamic_cast<PViewDataList *>(data1);
  for(int ent = 0; !shared && ent < data1->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
      if(data1->skipElement(step, ent, ele)) continue;
      int numNodes = data1->getNumNodes(step, ent, ele);
      double xmin = 180, xmax = -180;
      for(int nod = 0; nod < numNodes; nod++) {
        double x, y, z;
        data1->getNode(step, ent, ele, nod, x, y, z);
        xmin = std::min(x, xmin);
        xmax = std::max(x, xmax);
      }
      if(xmax - xmin <= 180) continue;
      for(int nod = 0; nod < numNodes; nod++) {
        double x, y, z;
        data1->getNode(step, ent, ele, nod, x, y, z);
        if(xmax - x > 180) data1->setNode(step, ent, ele, nod, x + 360, y, z);
      }
    }
  }
  data1->destroyAdaptiveData();
  data1->finalize();
  SetBoundingBox();
  SBoundingBox3d bb(gxmin, gymin, 0, gxmax, gymax, 0);
  data1->setBoundingBox(bb);
  v1->setChanged(true);
  return v1;
}
