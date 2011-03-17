// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "Probe.h"
#include "Context.h"
#include "OctreePost.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

int GMSH_ProbePlugin::iview = 0;

StringXNumber ProbeOptions_Number[] = {
  {GMSH_FULLRC, "X", GMSH_ProbePlugin::callbackX, 0.},
  {GMSH_FULLRC, "Y", GMSH_ProbePlugin::callbackY, 0.},
  {GMSH_FULLRC, "Z", GMSH_ProbePlugin::callbackZ, 0.},
  {GMSH_FULLRC, "View", NULL, -1.},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterProbePlugin()
  {
    return new GMSH_ProbePlugin();
  }
}

void GMSH_ProbePlugin::draw(void *context)
{
#if defined(HAVE_OPENGL)
  int num = (int)ProbeOptions_Number[3].def;
  if(num < 0) num = iview;
  if(num >= 0 && num < (int)PView::list.size()){
    double x = ProbeOptions_Number[0].def;
    double y = ProbeOptions_Number[1].def;
    double z = ProbeOptions_Number[2].def;
    drawContext *ctx = (drawContext*)context;
    glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
    glLineWidth((float)CTX::instance()->lineWidth);
    SBoundingBox3d bb = PView::list[num]->getData()->getBoundingBox();
    if(x >= bb.min().x() && x <= bb.max().x() &&
       y >= bb.min().y() && y <= bb.max().y() &&
       z >= bb.min().z() && z <= bb.max().z()){
      // we're inside the bounding box: draw a large cross
      glBegin(GL_LINES);
      glVertex3d(bb.min().x(), y, z); glVertex3d(bb.max().x(), y, z);
      glVertex3d(x, bb.min().y(), z); glVertex3d(x, bb.max().y(), z);
      glVertex3d(x, y, bb.min().z()); glVertex3d(x, y, bb.max().z());
      glEnd();
    }
    else{
      // draw 10-pixel marker
      double d = 10 * ctx->pixel_equiv_x / ctx->s[0];
      glBegin(GL_LINES);
      glVertex3d(x - d, y, z); glVertex3d(x + d, y, z);
      glVertex3d(x, y - d, z); glVertex3d(x, y + d, z);
      glVertex3d(x, y, z - d); glVertex3d(x, y, z + d);
      glEnd();
    }
    ctx->drawSphere(CTX::instance()->pointSize, x, y, z, 1);
  }
#endif
}

double GMSH_ProbePlugin::callback(int num, int action, double value, double *opt)
{
  if(action > 0) iview = num;
  switch(action){ // configure the input field
  case 1: return CTX::instance()->lc / 100.;
  case 2: return -2 * CTX::instance()->lc;
  case 3: return 2 * CTX::instance()->lc;
  default: break;
  }
  *opt = value;
  GMSH_Plugin::setDrawFunction(draw);
  return 0.;
}

double GMSH_ProbePlugin::callbackX(int num, int action, double value)
{
  return callback(num, action, value, &ProbeOptions_Number[0].def);
}

double GMSH_ProbePlugin::callbackY(int num, int action, double value)
{
  return callback(num, action, value, &ProbeOptions_Number[1].def);
}

double GMSH_ProbePlugin::callbackZ(int num, int action, double value)
{
  return callback(num, action, value, &ProbeOptions_Number[2].def);
}

std::string GMSH_ProbePlugin::getHelp() const
{
  return "Plugin(Probe) gets the value of the view `View' at "
    "the point (`X',`Y',`Z').\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(Probe) creates one new view.";
}

int GMSH_ProbePlugin::getNbOptions() const
{
  return sizeof(ProbeOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ProbePlugin::getOption(int iopt)
{
  return &ProbeOptions_Number[iopt];
}

PView *GMSH_ProbePlugin::execute(PView *v)
{
  double x = ProbeOptions_Number[0].def;
  double y = ProbeOptions_Number[1].def;
  double z = ProbeOptions_Number[2].def;
  int iView = (int)ProbeOptions_Number[3].def;
  
  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  int numSteps = v1->getData()->getNumTimeSteps();
  double *val = new double[9 * numSteps];

  OctreePost o(v1);

  if(o.searchScalar(x, y, z, val)){
    data2->SP.push_back(x);
    data2->SP.push_back(y);
    data2->SP.push_back(z);
    for(int i = 0; i < numSteps; i++)
      data2->SP.push_back(val[i]);
    data2->NbSP++;
  }

  if(o.searchVector(x, y, z, val)){
    data2->VP.push_back(x);
    data2->VP.push_back(y);
    data2->VP.push_back(z);
    for(int i = 0; i < numSteps; i++){
      for(int j = 0; j < 3; j++)
        data2->VP.push_back(val[3 * i + j]);
    }
    data2->NbVP++;
  }

  if(o.searchTensor(x, y, z, val)){
    data2->TP.push_back(x);
    data2->TP.push_back(y);
    data2->TP.push_back(z);
    for(int i = 0; i < numSteps; i++){
      for(int j = 0; j < 9; j++)
        data2->TP.push_back(val[9 * i + j]);
    }
    data2->NbTP++;
  }

  delete [] val;
  
  for(int i = 0; i < numSteps; i++){
    double time = v1->getData()->getTime(i);
    data2->Time.push_back(time);
  }
  data2->setName(v1->getData()->getName() + "_Probe");
  data2->setFileName(v1->getData()->getName() + "_Probe.pos");
  data2->finalize();
  
  return v2;
}
