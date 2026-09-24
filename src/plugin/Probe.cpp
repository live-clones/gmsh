// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "Probe.h"
#include "Context.h"
#include "OctreePost.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

GMSH_ProbePlugin::GMSH_ProbePlugin()
  : GMSH_PostPlugin({{GMSH_FULLRC, "X", nullptr, 0., ""},
                     {GMSH_FULLRC, "Y", nullptr, 0., ""},
                     {GMSH_FULLRC, "Z", nullptr, 0., ""},
                     {GMSH_FULLRC, "View", nullptr, -1., ""}})
{
}

void GMSH_ProbePlugin::drawPreview(void *context)
{
#if defined(HAVE_OPENGL)
  int num = (int)option(3);
  if(num < 0) num = _iview;
  if(num >= 0 && num < (int)PView::list.size()) {
    double x = option(0);
    double y = option(1);
    double z = option(2);
    drawContext *ctx = (drawContext *)context;
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
    gmshLineWidth((float)CTX::instance()->lineWidth);
    SBoundingBox3d bb = PView::list[num]->getData()->getBoundingBox();
    if(x >= bb.min().x() && x <= bb.max().x() && y >= bb.min().y() &&
       y <= bb.max().y() && z >= bb.min().z() && z <= bb.max().z()) {
      // we're inside the bounding box: draw a large cross
      gmshBegin(GL_LINES);
      gmshVertex3d(bb.min().x(), y, z);
      gmshVertex3d(bb.max().x(), y, z);
      gmshVertex3d(x, bb.min().y(), z);
      gmshVertex3d(x, bb.max().y(), z);
      gmshVertex3d(x, y, bb.min().z());
      gmshVertex3d(x, y, bb.max().z());
      gmshEnd();
    }
    else {
      // draw 10-pixel marker
      double d = 10 * ctx->pixel_equiv_x / ctx->s[0];
      gmshBegin(GL_LINES);
      gmshVertex3d(x - d, y, z);
      gmshVertex3d(x + d, y, z);
      gmshVertex3d(x, y - d, z);
      gmshVertex3d(x, y + d, z);
      gmshVertex3d(x, y, z - d);
      gmshVertex3d(x, y, z + d);
      gmshEnd();
    }
    ctx->drawSphere(CTX::instance()->pointSize, x, y, z, 1);
  }
#endif
}

bool GMSH_ProbePlugin::optionCallback(int iopt, int num, int action,
                                      double &value)
{
  if(iopt > 2) return false;
  if(action > 0) _iview = num;
  double lc = CTX::instance()->lc;
  return sliderOption(iopt, action, value, lc / 100., -2 * lc, 2 * lc);
}

std::string GMSH_ProbePlugin::getHelp() const
{
  return "Plugin(Probe) gets the value of the view `View' at "
         "the point (`X',`Y',`Z').\n\n"
         "If `View' < 0, the plugin is run on the current view.\n\n"
         "Plugin(Probe) creates one new view.";
}

PView *GMSH_ProbePlugin::execute(PView *v)
{
  double x = option(0);
  double y = option(1);
  double z = option(2);
  int iView = (int)option(3);

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  // the data the search structure is built on: adapted if it can be
  PViewData *data1 = getPossiblyAdaptiveData(v1);
  int numSteps = data1->getNumTimeSteps();
  double *val = new double[9 * numSteps];

  OctreePost o(v1);

  if(o.searchScalar(x, y, z, val)) {
    data2->SP.push_back(x);
    data2->SP.push_back(y);
    data2->SP.push_back(z);
    for(int i = 0; i < numSteps; i++) data2->SP.push_back(val[i]);
    data2->NbSP++;
  }

  if(o.searchVector(x, y, z, val)) {
    data2->VP.push_back(x);
    data2->VP.push_back(y);
    data2->VP.push_back(z);
    for(int i = 0; i < numSteps; i++) {
      for(int j = 0; j < 3; j++) data2->VP.push_back(val[3 * i + j]);
    }
    data2->NbVP++;
  }

  if(o.searchTensor(x, y, z, val)) {
    data2->TP.push_back(x);
    data2->TP.push_back(y);
    data2->TP.push_back(z);
    for(int i = 0; i < numSteps; i++) {
      for(int j = 0; j < 9; j++) data2->TP.push_back(val[9 * i + j]);
    }
    data2->NbTP++;
  }

  delete[] val;

  for(int i = 0; i < numSteps; i++) {
    double time = data1->getTime(i);
    data2->Time.push_back(time);
  }
  data2->setName(v1->getData()->getName() + "_Probe");
  data2->setFileName(v1->getData()->getName() + "_Probe.pos");
  data2->finalize();

  return v2;
}
