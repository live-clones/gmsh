// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Warp.h"
#include "SmoothData.h"
#include "Numeric.h"

StringXNumber WarpOptions_Number[] = {
  {GMSH_FULLRC, "Factor", nullptr, 1., ""},
  {GMSH_FULLRC, "TimeStep", nullptr, 0., ""},
  {GMSH_FULLRC, "SmoothingAngle", nullptr, 180., ""},
  {GMSH_FULLRC, "View", nullptr, -1., ""},
  {GMSH_FULLRC, "OtherView", nullptr, -1., ""}};

extern "C" {
GMSH_Plugin *GMSH_RegisterWarpPlugin() { return new GMSH_WarpPlugin(); }
}

std::string GMSH_WarpPlugin::getHelp() const
{
  return "Plugin(Warp) transforms the elements in the "
         "view `View' by adding to their node coordinates "
         "the vector field stored in the `TimeStep'-th time "
         "step of the view `OtherView', scaled by `Factor'.\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "If `OtherView' < 0, the vector field is taken as the "
         "field of surface normals multiplied by the `TimeStep' "
         "value in `View'. (The smoothing of the surface "
         "normals is controlled by the `SmoothingAngle' "
         "parameter.)\n\n"
         "Plugin(Warp) is executed in-place.";
}

int GMSH_WarpPlugin::getNbOptions() const
{
  return sizeof(WarpOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_WarpPlugin::getOption(int iopt)
{
  return &WarpOptions_Number[iopt];
}

PView *GMSH_WarpPlugin::execute(PView *v)
{
  double factor = WarpOptions_Number[0].def;
  int TimeStep = (int)WarpOptions_Number[1].def;
  double AngleTol = WarpOptions_Number[2].def;
  int iView = (int)WarpOptions_Number[3].def;
  int otherView = (int)WarpOptions_Number[4].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  // without another view, the nodes move along the normals of the surfaces
  bool useNormals = (otherView < 0);
  PView *v2 = useNormals ? v1 : getView(otherView, v);
  if(!v2) return v;

  // the view itself is changed, not the adapted data drawn from it
  PViewData *data1 = v1->getData();
  PViewData *data2 = v2->getData();

  // sanity checks
  if(data1->getNumEntities() != data2->getNumEntities() ||
     data1->getNumElements() != data2->getNumElements()) {
    Msg::Error("Incompatible views");
    return v;
  }
  if(TimeStep < 0 || TimeStep > data2->getNumTimeSteps() - 1) {
    Msg::Error("Invalid TimeStep (%d) in View[%d]", TimeStep, v2->getIndex());
    return v;
  }

  // the normal of a surface element, from its first 3 nodes
  auto normal = [&](int step, int ent, int ele, double n[3]) {
    double x[3], y[3], z[3];
    for(int nod = 0; nod < 3; nod++)
      data1->getNode(step, ent, ele, nod, x[nod], y[nod], z[nod]);
    normal3points(x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], n);
  };

  // smooth normal field if we don't have an explicit warp field
  smooth_normals *normals = nullptr;
  if(useNormals) {
    normals = new smooth_normals(AngleTol);
    int step = data1->getFirstNonEmptyTimeStep();
    for(int ent = 0; ent < data1->getNumEntities(step); ent++) {
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++) {
        if(data1->skipElement(step, ent, ele)) continue;
        if(data1->getDimension(step, ent, ele) != 2) continue;
        double n[3];
        normal(step, ent, ele, n);
        for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++) {
          double x, y, z;
          data1->getNode(step, ent, ele, nod, x, y, z);
          normals->add(x, y, z, n[0], n[1], n[2]);
        }
      }
    }
  }

  // (x,y,z) += factor * mult * (valx, valy, valz)
  forEachNode(
    data1,
    [&](int step, int ent, int ele, int nod) {
      double x, y, z, mult = 1., val[3] = {0., 0., 0.};
      data1->getNode(step, ent, ele, nod, x, y, z);
      if(useNormals) {
        normal(step, ent, ele, val);
        normals->get(x, y, z, val[0], val[1], val[2]);
        if(data1->hasTimeStep(TimeStep) &&
           !data1->skipElement(TimeStep, ent, ele))
          data1->getScalarValue(TimeStep, ent, ele, nod, mult);
      }
      else if(data2->getNumComponents(TimeStep, ent, ele) == 3 &&
              data2->hasTimeStep(TimeStep) &&
              !data2->skipElement(TimeStep, ent, ele)) {
        for(int comp = 0; comp < 3; comp++)
          data2->getValue(TimeStep, ent, ele, nod, comp, val[comp]);
      }
      data1->setNode(step, ent, ele, nod, x + factor * mult * val[0],
                     y + factor * mult * val[1], z + factor * mult * val[2]);
    },
    useNormals ? 2 : -1);

  if(normals) delete normals;

  data1->finalize();
  v1->setChanged(true);

  return v1;
}
