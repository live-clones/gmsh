// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Gilles Marckmann <gilles.marckmann@ec-nantes.fr>

#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "Navigator.h"
#include "Trackball.h"
#include "Context.h"
#include "drawContext.h"
#include "gl2ps.h"

Navigator::Navigator(double _freq, drawContext *_ctx)
  : ax0(0.), ax1(0.), ax0_cur(0.), ax1_cur(0.), speed(0.), awake(true),
    ctx(_ctx), frequency(_freq)
{
  ctx->camera.init();
  pad = CTX::instance()->gamepad;
  along = AXE_Z;
  mode = PEDESTRIAN;
  reference_angle = 3.14 * frequency / 5.;
  reference_speed = 1.5 * frequency * (ctx->camera.Lc) / 25.;
}

Navigator::~Navigator(){};

void Navigator::setDrawContext(drawContext *_ctx)
{
  ctx = _ctx;
  ctx->camera.init();
}

void Navigator::setFrequency(double _freq)
{
  frequency = _freq;
  reference_angle = 3.14 * frequency / 5.;
  reference_speed = 1.5 * frequency * (ctx->camera.Lc) / 100.;
}

void Navigator::setResponseFrequency(double _freq)
{
  reference_angle = 3.14 * frequency / 5. * (_freq / .01);
  reference_speed = 1.5 * frequency * (ctx->camera.Lc) / 100. * (_freq / .01);
}

void Navigator::drawIcons()
{
  double l = CTX::instance()->smallAxesSize;
  double dx = CTX::instance()->smallAxesPos[0] + .5 * l;
  double dy = 1.25 * l;

  ctx->fix2dCoordinates(&dx, &dy);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLineWidth((float)CTX::instance()->lineWidth);
  gl2psLineWidth((float)(CTX::instance()->lineWidth *
                         CTX::instance()->print.epsLineWidthFactor));

  glColor4ubv((GLubyte *)&CTX::instance()->color.smallAxes);

  double scale = l / 100.;
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);

  switch(mode) {
  case PEDESTRIAN:
    glBegin(GL_LINES);
    glVertex2d(dx + scale * 3.01052761E+01, dy + scale * 4.07178345E+01);
    glVertex2d(dx + scale * 3.69660988E+01, dy + scale * 3.01357174E+01);
    glVertex2d(dx + scale * 3.69660988E+01, dy + scale * 3.01357174E+01);
    glVertex2d(dx + scale * 4.07505989E+01, dy + scale * 2.80945930E+01);
    glVertex2d(dx + scale * 4.07505989E+01, dy + scale * 2.80945930E+01);
    glVertex2d(dx + scale * 4.87266998E+01, dy + scale * 2.00446148E+01);
    glVertex2d(dx + scale * 4.87266998E+01, dy + scale * 2.00446148E+01);
    glVertex2d(dx + scale * 5.38157959E+01, dy + scale * 1.13534155E+01);
    glVertex2d(dx + scale * 5.38157959E+01, dy + scale * 1.13534155E+01);
    glVertex2d(dx + scale * 5.25646591E+01, dy + scale * 3.44290900E+00);
    glVertex2d(dx + scale * 5.25646591E+01, dy + scale * 3.44290900E+00);
    glVertex2d(dx + scale * 5.01248283E+01, dy + scale * 2.56559372E+00);
    glVertex2d(dx + scale * 5.01248283E+01, dy + scale * 2.56559372E+00);
    glVertex2d(dx + scale * 5.01248283E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 5.01248283E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 5.57356987E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 5.57356987E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 5.98938141E+01, dy + scale * 7.02665806E+00);
    glVertex2d(dx + scale * 5.98938141E+01, dy + scale * 7.02665806E+00);
    glVertex2d(dx + scale * 6.34061890E+01, dy + scale * 1.35390358E+01);
    glVertex2d(dx + scale * 6.34061890E+01, dy + scale * 1.35390358E+01);
    glVertex2d(dx + scale * 6.04280853E+01, dy + scale * 1.56590576E+01);
    glVertex2d(dx + scale * 6.04280853E+01, dy + scale * 1.56590576E+01);
    glVertex2d(dx + scale * 5.67851448E+01, dy + scale * 1.66882896E+01);
    glVertex2d(dx + scale * 5.67851448E+01, dy + scale * 1.66882896E+01);
    glVertex2d(dx + scale * 5.56003265E+01, dy + scale * 1.87117329E+01);
    glVertex2d(dx + scale * 5.56003265E+01, dy + scale * 1.87117329E+01);
    glVertex2d(dx + scale * 5.12019005E+01, dy + scale * 2.62234058E+01);
    glVertex2d(dx + scale * 5.12019005E+01, dy + scale * 2.62234058E+01);
    glVertex2d(dx + scale * 4.87266998E+01, dy + scale * 3.04505730E+01);
    glVertex2d(dx + scale * 4.87266998E+01, dy + scale * 3.04505730E+01);
    glVertex2d(dx + scale * 4.26556816E+01, dy + scale * 3.47723503E+01);
    glVertex2d(dx + scale * 4.26556816E+01, dy + scale * 3.47723503E+01);
    glVertex2d(dx + scale * 4.11023293E+01, dy + scale * 3.66784554E+01);
    glVertex2d(dx + scale * 4.11023293E+01, dy + scale * 3.66784554E+01);
    glVertex2d(dx + scale * 4.07505989E+01, dy + scale * 3.88915939E+01);
    glVertex2d(dx + scale * 4.07505989E+01, dy + scale * 3.88915939E+01);
    glVertex2d(dx + scale * 3.96205177E+01, dy + scale * 4.60021973E+01);
    glVertex2d(dx + scale * 3.96205177E+01, dy + scale * 4.60021973E+01);
    glVertex2d(dx + scale * 3.76618462E+01, dy + scale * 5.14492989E+01);
    glVertex2d(dx + scale * 3.76618462E+01, dy + scale * 5.14492989E+01);
    glVertex2d(dx + scale * 3.82070084E+01, dy + scale * 5.48961716E+01);
    glVertex2d(dx + scale * 3.82070084E+01, dy + scale * 5.48961716E+01);
    glVertex2d(dx + scale * 3.82070084E+01, dy + scale * 5.79802170E+01);
    glVertex2d(dx + scale * 3.82070084E+01, dy + scale * 5.79802170E+01);
    glVertex2d(dx + scale * 3.69349632E+01, dy + scale * 6.15177956E+01);
    glVertex2d(dx + scale * 3.69349632E+01, dy + scale * 6.15177956E+01);
    glVertex2d(dx + scale * 3.25736656E+01, dy + scale * 6.68695145E+01);
    glVertex2d(dx + scale * 3.25736656E+01, dy + scale * 6.68695145E+01);
    glVertex2d(dx + scale * 3.18467827E+01, dy + scale * 7.03163834E+01);
    glVertex2d(dx + scale * 3.18467827E+01, dy + scale * 7.03163834E+01);
    glVertex2d(dx + scale * 3.38457108E+01, dy + scale * 7.73915405E+01);
    glVertex2d(dx + scale * 3.38457108E+01, dy + scale * 7.73915405E+01);
    glVertex2d(dx + scale * 3.38457108E+01, dy + scale * 8.45574112E+01);
    glVertex2d(dx + scale * 3.38457108E+01, dy + scale * 8.45574112E+01);
    glVertex2d(dx + scale * 3.38457108E+01, dy + scale * 8.58094559E+01);
    glVertex2d(dx + scale * 3.45101509E+01, dy + scale * 5.14492989E+01);
    glVertex2d(dx + scale * 3.01052761E+01, dy + scale * 4.07178345E+01);
    glVertex2d(dx + scale * 1.95475960E+01, dy + scale * 7.45358734E+01);
    glVertex2d(dx + scale * 2.16000557E+01, dy + scale * 6.88279419E+01);
    glVertex2d(dx + scale * 2.16000557E+01, dy + scale * 6.88279419E+01);
    glVertex2d(dx + scale * 2.16000557E+01, dy + scale * 6.32443161E+01);
    glVertex2d(dx + scale * 2.16000557E+01, dy + scale * 6.32443161E+01);
    glVertex2d(dx + scale * 2.39542980E+01, dy + scale * 5.92237206E+01);
    glVertex2d(dx + scale * 2.39542980E+01, dy + scale * 5.92237206E+01);
    glVertex2d(dx + scale * 2.06011562E+01, dy + scale * 5.10545654E+01);
    glVertex2d(dx + scale * 2.06011562E+01, dy + scale * 5.10545654E+01);
    glVertex2d(dx + scale * 1.91084385E+01, dy + scale * 4.16166077E+01);
    glVertex2d(dx + scale * 1.91084385E+01, dy + scale * 4.16166077E+01);
    glVertex2d(dx + scale * 1.89741859E+01, dy + scale * 3.61561012E+01);
    glVertex2d(dx + scale * 1.89741859E+01, dy + scale * 3.61561012E+01);
    glVertex2d(dx + scale * 1.80558548E+01, dy + scale * 3.29056969E+01);
    glVertex2d(dx + scale * 1.80558548E+01, dy + scale * 3.29056969E+01);
    glVertex2d(dx + scale * 1.80558548E+01, dy + scale * 2.96775036E+01);
    glVertex2d(dx + scale * 1.80558548E+01, dy + scale * 2.96775036E+01);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 2.55330906E+01);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 2.55330906E+01);
    glVertex2d(dx + scale * 1.53084030E+01, dy + scale * 1.60425396E+01);
    glVertex2d(dx + scale * 1.53084030E+01, dy + scale * 1.60425396E+01);
    glVertex2d(dx + scale * 1.19248409E+01, dy + scale * 9.76899910E+00);
    glVertex2d(dx + scale * 1.19248409E+01, dy + scale * 9.76899910E+00);
    glVertex2d(dx + scale * 1.04403715E+01, dy + scale * 1.05696316E+01);
    glVertex2d(dx + scale * 1.04403715E+01, dy + scale * 1.05696316E+01);
    glVertex2d(dx + scale * 7.35945797E+00, dy + scale * 8.76561642E+00);
    glVertex2d(dx + scale * 7.35945797E+00, dy + scale * 8.76561642E+00);
    glVertex2d(dx + scale * 4.11787891E+00, dy + scale * 8.65881157E+00);
    glVertex2d(dx + scale * 4.11787891E+00, dy + scale * 8.65881157E+00);
    glVertex2d(dx + scale * 1.94821942E+00, dy + scale * 9.27180004E+00);
    glVertex2d(dx + scale * 1.94821942E+00, dy + scale * 9.27180004E+00);
    glVertex2d(dx + scale * 2.77175337E-01, dy + scale * 8.18839359E+00);
    glVertex2d(dx + scale * 2.77175337E-01, dy + scale * 8.18839359E+00);
    glVertex2d(dx + scale * 1.94821942E+00, dy + scale * 5.61097956E+00);
    glVertex2d(dx + scale * 1.94821942E+00, dy + scale * 5.61097956E+00);
    glVertex2d(dx + scale * 6.22622919E+00, dy + scale * 2.56559372E+00);
    glVertex2d(dx + scale * 6.22622919E+00, dy + scale * 2.56559372E+00);
    glVertex2d(dx + scale * 1.11108894E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 1.11108894E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 1.18554187E+00);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 7.02665806E+00);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 7.02665806E+00);
    glVertex2d(dx + scale * 1.65164566E+01, dy + scale * 8.18839359E+00);
    glVertex2d(dx + scale * 1.65164566E+01, dy + scale * 8.18839359E+00);
    glVertex2d(dx + scale * 2.46518440E+01, dy + scale * 2.32723999E+01);
    glVertex2d(dx + scale * 2.46518440E+01, dy + scale * 2.32723999E+01);
    glVertex2d(dx + scale * 2.46518440E+01, dy + scale * 3.04505730E+01);
    glVertex2d(dx + scale * 2.46518440E+01, dy + scale * 3.04505730E+01);
    glVertex2d(dx + scale * 2.58728657E+01, dy + scale * 3.47723503E+01);
    glVertex2d(dx + scale * 2.58728657E+01, dy + scale * 3.47723503E+01);
    glVertex2d(dx + scale * 3.01052761E+01, dy + scale * 4.07178345E+01);
    glVertex2d(dx + scale * 2.75617714E+01, dy + scale * 8.75848465E+01);
    glVertex2d(dx + scale * 3.76618462E+01, dy + scale * 8.47312927E+01);
    glVertex2d(dx + scale * 3.76618462E+01, dy + scale * 8.47312927E+01);
    glVertex2d(dx + scale * 3.92328835E+01, dy + scale * 8.36129227E+01);
    glVertex2d(dx + scale * 3.92328835E+01, dy + scale * 8.36129227E+01);
    glVertex2d(dx + scale * 4.11023293E+01, dy + scale * 7.90666428E+01);
    glVertex2d(dx + scale * 4.11023293E+01, dy + scale * 7.90666428E+01);
    glVertex2d(dx + scale * 4.46455917E+01, dy + scale * 7.30154266E+01);
    glVertex2d(dx + scale * 4.46455917E+01, dy + scale * 7.30154266E+01);
    glVertex2d(dx + scale * 4.62260017E+01, dy + scale * 7.03163834E+01);
    glVertex2d(dx + scale * 4.62260017E+01, dy + scale * 7.03163834E+01);
    glVertex2d(dx + scale * 4.56109505E+01, dy + scale * 6.64276276E+01);
    glVertex2d(dx + scale * 4.56109505E+01, dy + scale * 6.64276276E+01);
    glVertex2d(dx + scale * 4.56109505E+01, dy + scale * 6.53531952E+01);
    glVertex2d(dx + scale * 4.56109505E+01, dy + scale * 6.53531952E+01);
    glVertex2d(dx + scale * 4.87266998E+01, dy + scale * 6.36727524E+01);
    glVertex2d(dx + scale * 4.87266998E+01, dy + scale * 6.36727524E+01);
    glVertex2d(dx + scale * 5.15070915E+01, dy + scale * 6.64276276E+01);
    glVertex2d(dx + scale * 5.15070915E+01, dy + scale * 6.64276276E+01);
    glVertex2d(dx + scale * 5.15070915E+01, dy + scale * 6.88279419E+01);
    glVertex2d(dx + scale * 5.15070915E+01, dy + scale * 6.88279419E+01);
    glVertex2d(dx + scale * 4.95096855E+01, dy + scale * 7.22391281E+01);
    glVertex2d(dx + scale * 4.95096855E+01, dy + scale * 7.22391281E+01);
    glVertex2d(dx + scale * 4.58495522E+01, dy + scale * 8.24180374E+01);
    glVertex2d(dx + scale * 4.58495522E+01, dy + scale * 8.24180374E+01);
    glVertex2d(dx + scale * 4.32594948E+01, dy + scale * 8.68413620E+01);
    glVertex2d(dx + scale * 4.32594948E+01, dy + scale * 8.68413620E+01);
    glVertex2d(dx + scale * 4.18205223E+01, dy + scale * 8.72479095E+01);
    glVertex2d(dx + scale * 4.18205223E+01, dy + scale * 8.72479095E+01);
    glVertex2d(dx + scale * 3.02508583E+01, dy + scale * 9.19968338E+01);
    glVertex2d(dx + scale * 3.02508583E+01, dy + scale * 9.19968338E+01);
    glVertex2d(dx + scale * 2.86896305E+01, dy + scale * 9.26376648E+01);
    glVertex2d(dx + scale * 2.86896305E+01, dy + scale * 9.26376648E+01);
    glVertex2d(dx + scale * 2.80653210E+01, dy + scale * 9.37038651E+01);
    glVertex2d(dx + scale * 2.80653210E+01, dy + scale * 9.37038651E+01);
    glVertex2d(dx + scale * 2.71819935E+01, dy + scale * 9.52124176E+01);
    glVertex2d(dx + scale * 2.71819935E+01, dy + scale * 9.52124176E+01);
    glVertex2d(dx + scale * 2.96779137E+01, dy + scale * 9.61099014E+01);
    glVertex2d(dx + scale * 2.96779137E+01, dy + scale * 9.61099014E+01);
    glVertex2d(dx + scale * 3.02764988E+01, dy + scale * 9.90064621E+01);
    glVertex2d(dx + scale * 3.02764988E+01, dy + scale * 9.90064621E+01);
    glVertex2d(dx + scale * 2.92283592E+01, dy + scale * 1.05601486E+02);
    glVertex2d(dx + scale * 2.92283592E+01, dy + scale * 1.05601486E+02);
    glVertex2d(dx + scale * 2.25053406E+01, dy + scale * 1.08361038E+02);
    glVertex2d(dx + scale * 2.25053406E+01, dy + scale * 1.08361038E+02);
    glVertex2d(dx + scale * 1.72556629E+01, dy + scale * 1.05287109E+02);
    glVertex2d(dx + scale * 1.72556629E+01, dy + scale * 1.05287109E+02);
    glVertex2d(dx + scale * 1.52413979E+01, dy + scale * 9.81576691E+01);
    glVertex2d(dx + scale * 1.52413979E+01, dy + scale * 9.81576691E+01);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 9.25170364E+01);
    glVertex2d(dx + scale * 1.72696590E+01, dy + scale * 9.25170364E+01);
    glVertex2d(dx + scale * 2.16000557E+01, dy + scale * 9.32052612E+01);
    glVertex2d(dx + scale * 2.16000557E+01, dy + scale * 9.32052612E+01);
    glVertex2d(dx + scale * 2.31259499E+01, dy + scale * 8.89617233E+01);
    glVertex2d(dx + scale * 2.31259499E+01, dy + scale * 8.89617233E+01);
    glVertex2d(dx + scale * 2.01361866E+01, dy + scale * 8.34183350E+01);
    glVertex2d(dx + scale * 2.01361866E+01, dy + scale * 8.34183350E+01);
    glVertex2d(dx + scale * 1.86794548E+01, dy + scale * 8.07173691E+01);
    glVertex2d(dx + scale * 1.86794548E+01, dy + scale * 8.07173691E+01);
    glVertex2d(dx + scale * 1.86794548E+01, dy + scale * 7.69501953E+01);
    glVertex2d(dx + scale * 1.86794548E+01, dy + scale * 7.69501953E+01);
    glVertex2d(dx + scale * 1.98941078E+01, dy + scale * 7.35722198E+01);
    glVertex2d(dx + scale * 1.38444281E+01, dy + scale * 7.19181519E+01);
    glVertex2d(dx + scale * 1.31145697E+01, dy + scale * 7.24377136E+01);
    glVertex2d(dx + scale * 1.31145697E+01, dy + scale * 7.24377136E+01);
    glVertex2d(dx + scale * 7.04405022E+00, dy + scale * 7.85644531E+01);
    glVertex2d(dx + scale * 7.04405022E+00, dy + scale * 7.85644531E+01);
    glVertex2d(dx + scale * 6.26990461E+00, dy + scale * 8.07173691E+01);
    glVertex2d(dx + scale * 6.26990461E+00, dy + scale * 8.07173691E+01);
    glVertex2d(dx + scale * 6.94693804E+00, dy + scale * 8.31137161E+01);
    glVertex2d(dx + scale * 6.94693804E+00, dy + scale * 8.31137161E+01);
    glVertex2d(dx + scale * 6.52368259E+00, dy + scale * 8.57768860E+01);
    glVertex2d(dx + scale * 6.52368259E+00, dy + scale * 8.57768860E+01);
    glVertex2d(dx + scale * 5.51406002E+00, dy + scale * 8.63214188E+01);
    glVertex2d(dx + scale * 5.51406002E+00, dy + scale * 8.63214188E+01);
    glVertex2d(dx + scale * 2.57401466E+00, dy + scale * 8.62266617E+01);
    glVertex2d(dx + scale * 2.57401466E+00, dy + scale * 8.62266617E+01);
    glVertex2d(dx + scale * 2.63223171E-01, dy + scale * 8.29805756E+01);
    glVertex2d(dx + scale * 2.63223171E-01, dy + scale * 8.29805756E+01);
    glVertex2d(dx + scale * 5.74481070E-01, dy + scale * 8.10221024E+01);
    glVertex2d(dx + scale * 5.74481070E-01, dy + scale * 8.10221024E+01);
    glVertex2d(dx + scale * 3.50635505E+00, dy + scale * 7.89349899E+01);
    glVertex2d(dx + scale * 3.50635505E+00, dy + scale * 7.89349899E+01);
    glVertex2d(dx + scale * 4.06134844E+00, dy + scale * 7.73915405E+01);
    glVertex2d(dx + scale * 4.06134844E+00, dy + scale * 7.73915405E+01);
    glVertex2d(dx + scale * 1.02916317E+01, dy + scale * 6.82235336E+01);
    glVertex2d(dx + scale * 1.02916317E+01, dy + scale * 6.82235336E+01);
    glVertex2d(dx + scale * 1.35903749E+01, dy + scale * 6.68695145E+01);
    glVertex2d(dx + scale * 1.35903749E+01, dy + scale * 6.68695145E+01);
    glVertex2d(dx + scale * 1.50925760E+01, dy + scale * 6.74096756E+01);
    glVertex2d(dx + scale * 1.50925760E+01, dy + scale * 6.74096756E+01);
    glVertex2d(dx + scale * 2.02666225E+01, dy + scale * 7.25362473E+01);
    glVertex2d(dx + scale * 1.33335953E+01, dy + scale * 7.23014450E+01);
    glVertex2d(dx + scale * 1.86794548E+01, dy + scale * 7.88337784E+01);
    glEnd();
    break;
  case DIVER:
    glBegin(GL_LINES);
    glVertex2d(dx + scale * 4.70261803E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 4.34834213E+01, dy + scale * 3.27708626E+01);
    glVertex2d(dx + scale * 4.34834213E+01, dy + scale * 3.27708626E+01);
    glVertex2d(dx + scale * 4.13941002E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 4.13941002E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 3.96319656E+01, dy + scale * 3.27708626E+01);
    glVertex2d(dx + scale * 4.70261803E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 6.37407417E+01, dy + scale * 2.29766846E+01);
    glVertex2d(dx + scale * 6.37407417E+01, dy + scale * 2.29766846E+01);
    glVertex2d(dx + scale * 6.88277817E+01, dy + scale * 2.83272076E+01);
    glVertex2d(dx + scale * 6.88277817E+01, dy + scale * 2.83272076E+01);
    glVertex2d(dx + scale * 7.49140625E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 7.49140625E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 7.75205078E+01, dy + scale * 3.05546646E+01);
    glVertex2d(dx + scale * 5.73819389E+01, dy + scale * 1.82609520E+01);
    glVertex2d(dx + scale * 6.51033478E+01, dy + scale * 1.64820938E+01);
    glVertex2d(dx + scale * 6.51033478E+01, dy + scale * 1.64820938E+01);
    glVertex2d(dx + scale * 6.72513809E+01, dy + scale * 1.64820938E+01);
    glVertex2d(dx + scale * 6.72513809E+01, dy + scale * 1.64820938E+01);
    glVertex2d(dx + scale * 6.88277817E+01, dy + scale * 1.81401482E+01);
    glVertex2d(dx + scale * 6.88277817E+01, dy + scale * 1.81401482E+01);
    glVertex2d(dx + scale * 7.75205078E+01, dy + scale * 3.05546646E+01);
    glVertex2d(dx + scale * 7.75205078E+01, dy + scale * 3.05546646E+01);
    glVertex2d(dx + scale * 7.91115646E+01, dy + scale * 3.05546646E+01);
    glVertex2d(dx + scale * 7.91115646E+01, dy + scale * 3.05546646E+01);
    glVertex2d(dx + scale * 7.96394882E+01, dy + scale * 3.28461914E+01);
    glVertex2d(dx + scale * 7.96394882E+01, dy + scale * 3.28461914E+01);
    glVertex2d(dx + scale * 8.69550934E+01, dy + scale * 3.72063484E+01);
    glVertex2d(dx + scale * 8.69550934E+01, dy + scale * 3.72063484E+01);
    glVertex2d(dx + scale * 9.21887970E+01, dy + scale * 3.60006065E+01);
    glVertex2d(dx + scale * 9.21887970E+01, dy + scale * 3.60006065E+01);
    glVertex2d(dx + scale * 9.73070221E+01, dy + scale * 4.33102036E+01);
    glVertex2d(dx + scale * 9.73070221E+01, dy + scale * 4.33102036E+01);
    glVertex2d(dx + scale * 9.48979111E+01, dy + scale * 4.38652153E+01);
    glVertex2d(dx + scale * 9.48979111E+01, dy + scale * 4.38652153E+01);
    glVertex2d(dx + scale * 7.96394882E+01, dy + scale * 3.86619072E+01);
    glVertex2d(dx + scale * 7.96394882E+01, dy + scale * 3.86619072E+01);
    glVertex2d(dx + scale * 7.41574936E+01, dy + scale * 3.60006065E+01);
    glVertex2d(dx + scale * 7.41574936E+01, dy + scale * 3.60006065E+01);
    glVertex2d(dx + scale * 7.35288086E+01, dy + scale * 3.32717209E+01);
    glVertex2d(dx + scale * 7.35288086E+01, dy + scale * 3.32717209E+01);
    glVertex2d(dx + scale * 7.49140625E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 7.25460358E+01, dy + scale * 2.34503746E+01);
    glVertex2d(dx + scale * 7.35393219E+01, dy + scale * 2.14043198E+01);
    glVertex2d(dx + scale * 7.35393219E+01, dy + scale * 2.14043198E+01);
    glVertex2d(dx + scale * 7.72988739E+01, dy + scale * 2.26863708E+01);
    glVertex2d(dx + scale * 7.72988739E+01, dy + scale * 2.26863708E+01);
    glVertex2d(dx + scale * 8.08417358E+01, dy + scale * 1.53884392E+01);
    glVertex2d(dx + scale * 8.08417358E+01, dy + scale * 1.53884392E+01);
    glVertex2d(dx + scale * 9.27881927E+01, dy + scale * 5.54670620E+00);
    glVertex2d(dx + scale * 9.27881927E+01, dy + scale * 5.54670620E+00);
    glVertex2d(dx + scale * 1.00075905E+02, dy + scale * 8.03190613E+00);
    glVertex2d(dx + scale * 1.00075905E+02, dy + scale * 8.03190613E+00);
    glVertex2d(dx + scale * 8.60352936E+01, dy + scale * 1.99065475E+01);
    glVertex2d(dx + scale * 8.60352936E+01, dy + scale * 1.99065475E+01);
    glVertex2d(dx + scale * 7.86158524E+01, dy + scale * 2.84351845E+01);
    glVertex2d(dx + scale * 7.86158524E+01, dy + scale * 2.84351845E+01);
    glVertex2d(dx + scale * 7.69795456E+01, dy + scale * 2.67141228E+01);
    glVertex2d(dx + scale * 7.69795456E+01, dy + scale * 2.67141228E+01);
    glVertex2d(dx + scale * 7.41574936E+01, dy + scale * 2.57517700E+01);
    glVertex2d(dx + scale * 7.30426788E+01, dy + scale * 2.24273472E+01);
    glVertex2d(dx + scale * 7.14492264E+01, dy + scale * 2.18839607E+01);
    glVertex2d(dx + scale * 6.16945724E+01, dy + scale * 2.40757561E+01);
    glVertex2d(dx + scale * 6.62687149E+01, dy + scale * 2.56355934E+01);
    glVertex2d(dx + scale * 3.96319656E+01, dy + scale * 3.27708626E+01);
    glVertex2d(dx + scale * 2.45886974E+01, dy + scale * 3.97385635E+01);
    glVertex2d(dx + scale * 2.45886974E+01, dy + scale * 3.97385635E+01);
    glVertex2d(dx + scale * 2.06685200E+01, dy + scale * 3.97385635E+01);
    glVertex2d(dx + scale * 5.73819389E+01, dy + scale * 1.82609520E+01);
    glVertex2d(dx + scale * 5.58739510E+01, dy + scale * 2.29766846E+01);
    glVertex2d(dx + scale * 5.58739510E+01, dy + scale * 2.29766846E+01);
    glVertex2d(dx + scale * 5.10441551E+01, dy + scale * 2.47799721E+01);
    glVertex2d(dx + scale * 5.10441551E+01, dy + scale * 2.47799721E+01);
    glVertex2d(dx + scale * 3.96319656E+01, dy + scale * 3.27708626E+01);
    glVertex2d(dx + scale * 1.71485100E+01, dy + scale * 3.83634911E+01);
    glVertex2d(dx + scale * 2.31309643E+01, dy + scale * 3.34350243E+01);
    glVertex2d(dx + scale * 2.31309643E+01, dy + scale * 3.34350243E+01);
    glVertex2d(dx + scale * 3.66521492E+01, dy + scale * 3.01534729E+01);
    glVertex2d(dx + scale * 3.66521492E+01, dy + scale * 3.01534729E+01);
    glVertex2d(dx + scale * 4.84622536E+01, dy + scale * 2.18839607E+01);
    glVertex2d(dx + scale * 4.84622536E+01, dy + scale * 2.18839607E+01);
    glVertex2d(dx + scale * 5.24489517E+01, dy + scale * 1.73012562E+01);
    glVertex2d(dx + scale * 5.24489517E+01, dy + scale * 1.73012562E+01);
    glVertex2d(dx + scale * 5.73819389E+01, dy + scale * 1.82609520E+01);
    glVertex2d(dx + scale * 2.31120663E+01, dy + scale * 2.08601875E+01);
    glVertex2d(dx + scale * 2.65303173E+01, dy + scale * 1.84667053E+01);
    glVertex2d(dx + scale * 2.65303173E+01, dy + scale * 1.84667053E+01);
    glVertex2d(dx + scale * 2.76829071E+01, dy + scale * 1.88597527E+01);
    glVertex2d(dx + scale * 2.76829071E+01, dy + scale * 1.88597527E+01);
    glVertex2d(dx + scale * 2.98293095E+01, dy + scale * 2.46085243E+01);
    glVertex2d(dx + scale * 2.98293095E+01, dy + scale * 2.46085243E+01);
    glVertex2d(dx + scale * 2.20083504E+01, dy + scale * 2.88094444E+01);
    glVertex2d(dx + scale * 2.20083504E+01, dy + scale * 2.88094444E+01);
    glVertex2d(dx + scale * 1.73340797E+01, dy + scale * 3.05546646E+01);
    glVertex2d(dx + scale * 1.73340797E+01, dy + scale * 3.05546646E+01);
    glVertex2d(dx + scale * 1.43467293E+01, dy + scale * 3.55669289E+01);
    glVertex2d(dx + scale * 1.43467293E+01, dy + scale * 3.55669289E+01);
    glVertex2d(dx + scale * 1.43467293E+01, dy + scale * 3.66936073E+01);
    glVertex2d(dx + scale * 2.31120663E+01, dy + scale * 2.08601875E+01);
    glVertex2d(dx + scale * 1.77385178E+01, dy + scale * 2.08601875E+01);
    glVertex2d(dx + scale * 1.77385178E+01, dy + scale * 2.08601875E+01);
    glVertex2d(dx + scale * 1.45902586E+01, dy + scale * 2.89193249E+01);
    glVertex2d(dx + scale * 1.45902586E+01, dy + scale * 2.89193249E+01);
    glVertex2d(dx + scale * 1.09701309E+01, dy + scale * 3.08638268E+01);
    glVertex2d(dx + scale * 1.09701309E+01, dy + scale * 3.08638268E+01);
    glVertex2d(dx + scale * 1.09701309E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 1.09701309E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 1.02964087E+01, dy + scale * 2.72419567E+01);
    glVertex2d(dx + scale * 1.02964087E+01, dy + scale * 2.72419567E+01);
    glVertex2d(dx + scale * 1.43467293E+01, dy + scale * 1.33082447E+01);
    glVertex2d(dx + scale * 1.43467293E+01, dy + scale * 1.33082447E+01);
    glVertex2d(dx + scale * 1.55345182E+01, dy + scale * 9.59382534E+00);
    glVertex2d(dx + scale * 1.55345182E+01, dy + scale * 9.59382534E+00);
    glVertex2d(dx + scale * 1.72489243E+01, dy + scale * 9.19886017E+00);
    glVertex2d(dx + scale * 1.72489243E+01, dy + scale * 9.19886017E+00);
    glVertex2d(dx + scale * 1.69032230E+01, dy + scale * 1.32596684E+01);
    glVertex2d(dx + scale * 1.69032230E+01, dy + scale * 1.32596684E+01);
    glVertex2d(dx + scale * 1.31571884E+01, dy + scale * 2.49741650E+01);
    glVertex2d(dx + scale * 1.31571884E+01, dy + scale * 2.49741650E+01);
    glVertex2d(dx + scale * 1.69212170E+01, dy + scale * 2.29523678E+01);
    glVertex2d(dx + scale * 3.90322609E+01, dy + scale * 1.84667053E+01);
    glVertex2d(dx + scale * 5.05798721E+01, dy + scale * 1.94497623E+01);
    glVertex2d(dx + scale * 2.31120663E+01, dy + scale * 2.08601875E+01);
    glVertex2d(dx + scale * 3.18689404E+01, dy + scale * 1.13308659E+01);
    glVertex2d(dx + scale * 3.18689404E+01, dy + scale * 1.13308659E+01);
    glVertex2d(dx + scale * 3.67675819E+01, dy + scale * 1.42504940E+01);
    glVertex2d(dx + scale * 3.67675819E+01, dy + scale * 1.42504940E+01);
    glVertex2d(dx + scale * 3.90322609E+01, dy + scale * 1.84667053E+01);
    glVertex2d(dx + scale * 4.70261803E+01, dy + scale * 3.19546795E+01);
    glVertex2d(dx + scale * 4.75925865E+01, dy + scale * 3.30091743E+01);
    glVertex2d(dx + scale * 4.75925865E+01, dy + scale * 3.30091743E+01);
    glVertex2d(dx + scale * 4.81551323E+01, dy + scale * 3.54509926E+01);
    glVertex2d(dx + scale * 4.81551323E+01, dy + scale * 3.54509926E+01);
    glVertex2d(dx + scale * 4.75925865E+01, dy + scale * 3.66097794E+01);
    glVertex2d(dx + scale * 4.75925865E+01, dy + scale * 3.66097794E+01);
    glVertex2d(dx + scale * 4.65963593E+01, dy + scale * 3.86619072E+01);
    glVertex2d(dx + scale * 4.65963593E+01, dy + scale * 3.86619072E+01);
    glVertex2d(dx + scale * 2.57703133E+01, dy + scale * 4.64376678E+01);
    glVertex2d(dx + scale * 2.57703133E+01, dy + scale * 4.64376678E+01);
    glVertex2d(dx + scale * 2.36515903E+01, dy + scale * 4.62573013E+01);
    glVertex2d(dx + scale * 2.36515903E+01, dy + scale * 4.62573013E+01);
    glVertex2d(dx + scale * 2.06685200E+01, dy + scale * 4.50919800E+01);
    glVertex2d(dx + scale * 2.06685200E+01, dy + scale * 4.50919800E+01);
    glVertex2d(dx + scale * 2.02995567E+01, dy + scale * 4.41037750E+01);
    glVertex2d(dx + scale * 4.15640564E+01, dy + scale * 2.67141228E+01);
    glVertex2d(dx + scale * 3.90322609E+01, dy + scale * 1.84667053E+01);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.55669289E+01);
    glVertex2d(dx + scale * 3.22941685E+00, dy + scale * 3.47821503E+01);
    glVertex2d(dx + scale * 1.57866726E+01, dy + scale * 3.79439583E+01);
    glVertex2d(dx + scale * 1.53819942E+01, dy + scale * 4.26975594E+01);
    glVertex2d(dx + scale * 1.53819942E+01, dy + scale * 4.26975594E+01);
    glVertex2d(dx + scale * 1.34937668E+01, dy + scale * 4.58656845E+01);
    glVertex2d(dx + scale * 1.34937668E+01, dy + scale * 4.58656845E+01);
    glVertex2d(dx + scale * 9.24889469E+00, dy + scale * 4.68436165E+01);
    glVertex2d(dx + scale * 9.24889469E+00, dy + scale * 4.68436165E+01);
    glVertex2d(dx + scale * 6.85485315E+00, dy + scale * 4.68436165E+01);
    glVertex2d(dx + scale * 6.85485315E+00, dy + scale * 4.68436165E+01);
    glVertex2d(dx + scale * 2.90823507E+00, dy + scale * 4.44914017E+01);
    glVertex2d(dx + scale * 2.90823507E+00, dy + scale * 4.44914017E+01);
    glVertex2d(dx + scale * 2.90823507E+00, dy + scale * 4.07268143E+01);
    glVertex2d(dx + scale * 5.95178938E+00, dy + scale * 3.35593605E+01);
    glVertex2d(dx + scale * 5.95178938E+00, dy + scale * 3.16901569E+01);
    glVertex2d(dx + scale * 5.95178938E+00, dy + scale * 3.16901569E+01);
    glVertex2d(dx + scale * 7.64524508E+00, dy + scale * 3.16901569E+01);
    glVertex2d(dx + scale * 7.64524508E+00, dy + scale * 3.16901569E+01);
    glVertex2d(dx + scale * 1.12084312E+01, dy + scale * 3.38138428E+01);
    glVertex2d(dx + scale * 1.12084312E+01, dy + scale * 3.38138428E+01);
    glVertex2d(dx + scale * 1.73539886E+01, dy + scale * 3.62145729E+01);
    glVertex2d(dx + scale * 1.73539886E+01, dy + scale * 3.62145729E+01);
    glVertex2d(dx + scale * 2.15019493E+01, dy + scale * 3.78349495E+01);
    glVertex2d(dx + scale * 2.15019493E+01, dy + scale * 3.78349495E+01);
    glVertex2d(dx + scale * 2.46490135E+01, dy + scale * 3.97106285E+01);
    glVertex2d(dx + scale * 2.46490135E+01, dy + scale * 3.97106285E+01);
    glVertex2d(dx + scale * 2.73888340E+01, dy + scale * 4.13435822E+01);
    glVertex2d(dx + scale * 2.73888340E+01, dy + scale * 4.13435822E+01);
    glVertex2d(dx + scale * 2.86334686E+01, dy + scale * 4.46771202E+01);
    glVertex2d(dx + scale * 2.86334686E+01, dy + scale * 4.46771202E+01);
    glVertex2d(dx + scale * 2.71944695E+01, dy + scale * 4.76413078E+01);
    glVertex2d(dx + scale * 2.71944695E+01, dy + scale * 4.76413078E+01);
    glVertex2d(dx + scale * 2.39893608E+01, dy + scale * 4.83796997E+01);
    glVertex2d(dx + scale * 2.39893608E+01, dy + scale * 4.83796997E+01);
    glVertex2d(dx + scale * 1.62659492E+01, dy + scale * 4.59099236E+01);
    glVertex2d(dx + scale * 1.62659492E+01, dy + scale * 4.59099236E+01);
    glVertex2d(dx + scale * 1.52036419E+01, dy + scale * 4.47925949E+01);
    glVertex2d(dx + scale * 1.52036419E+01, dy + scale * 4.47925949E+01);
    glVertex2d(dx + scale * 1.52036419E+01, dy + scale * 4.29968033E+01);
    glVertex2d(dx + scale * 8.08595753E+00, dy + scale * 3.58040657E+01);
    glVertex2d(dx + scale * 5.95178938E+00, dy + scale * 3.35593605E+01);
    glVertex2d(dx + scale * 1.56476307E+01, dy + scale * 4.10665283E+01);
    glVertex2d(dx + scale * 1.93166199E+01, dy + scale * 4.10665283E+01);
    glVertex2d(dx + scale * 1.93166199E+01, dy + scale * 4.10665283E+01);
    glVertex2d(dx + scale * 2.33771973E+01, dy + scale * 4.10665283E+01);
    glVertex2d(dx + scale * 2.33771973E+01, dy + scale * 4.10665283E+01);
    glVertex2d(dx + scale * 2.33771973E+01, dy + scale * 4.26527710E+01);
    glVertex2d(dx + scale * 2.33771973E+01, dy + scale * 4.26527710E+01);
    glVertex2d(dx + scale * 2.13850403E+01, dy + scale * 4.40476913E+01);
    glVertex2d(dx + scale * 2.13850403E+01, dy + scale * 4.40476913E+01);
    glVertex2d(dx + scale * 1.70507278E+01, dy + scale * 4.36787071E+01);
    glVertex2d(dx + scale * 1.70507278E+01, dy + scale * 4.36787071E+01);
    glVertex2d(dx + scale * 1.55381908E+01, dy + scale * 4.08627815E+01);
    glVertex2d(dx + scale * 5.44178314E+01, dy + scale * 5.39478874E+00);
    glVertex2d(dx + scale * 5.19188347E+01, dy + scale * 1.05424643E+01);
    glVertex2d(dx + scale * 5.19188347E+01, dy + scale * 1.05424643E+01);
    glVertex2d(dx + scale * 4.79111748E+01, dy + scale * 1.68014603E+01);
    glVertex2d(dx + scale * 4.79111748E+01, dy + scale * 1.68014603E+01);
    glVertex2d(dx + scale * 4.09703102E+01, dy + scale * 2.47799721E+01);
    glVertex2d(dx + scale * 1.97410069E+01, dy + scale * 2.08601875E+01);
    glVertex2d(dx + scale * 3.03358269E+01, dy + scale * 1.29992170E+01);
    glVertex2d(dx + scale * 3.34980812E+01, dy + scale * 1.23018475E+01);
    glVertex2d(dx + scale * 4.00906754E+01, dy + scale * 6.03390121E+00);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.55669289E+01);
    glVertex2d(dx + scale * 5.95178938E+00, dy + scale * 3.35593605E+01);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.55669289E+01);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.72466736E+01);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.72466736E+01);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.80246620E+01);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.80246620E+01);
    glVertex2d(dx + scale * 6.44296885E+00, dy + scale * 3.80246620E+01);
    glVertex2d(dx + scale * 6.44296885E+00, dy + scale * 3.80246620E+01);
    glVertex2d(dx + scale * 7.81519079E+00, dy + scale * 3.80246620E+01);
    glVertex2d(dx + scale * 7.81519079E+00, dy + scale * 3.80246620E+01);
    glVertex2d(dx + scale * 9.44908714E+00, dy + scale * 4.10665283E+01);
    glVertex2d(dx + scale * 9.44908714E+00, dy + scale * 4.10665283E+01);
    glVertex2d(dx + scale * 7.57615042E+00, dy + scale * 4.31311188E+01);
    glVertex2d(dx + scale * 7.57615042E+00, dy + scale * 4.31311188E+01);
    glVertex2d(dx + scale * 3.57823205E+00, dy + scale * 4.07483292E+01);
    glVertex2d(dx + scale * 3.57823205E+00, dy + scale * 4.07483292E+01);
    glVertex2d(dx + scale * 2.90823507E+00, dy + scale * 3.95009766E+01);
    glVertex2d(dx + scale * 2.90823507E+00, dy + scale * 3.95009766E+01);
    glVertex2d(dx + scale * 8.70941460E-01, dy + scale * 3.73581619E+01);
    glVertex2d(dx + scale * 8.70941460E-01, dy + scale * 3.73581619E+01);
    glVertex2d(dx + scale * 3.22941685E+00, dy + scale * 3.47821503E+01);
    glVertex2d(dx + scale * 3.22941685E+00, dy + scale * 3.47821503E+01);
    glVertex2d(dx + scale * 5.23835278E+00, dy + scale * 3.55669289E+01);
    glVertex2d(dx + scale * 5.53392906E+01, dy + scale * 5.84212208E+00);
    glVertex2d(dx + scale * 5.34963722E+01, dy + scale * 4.94745588E+00);
    glVertex2d(dx + scale * 5.34963722E+01, dy + scale * 4.94745588E+00);
    glVertex2d(dx + scale * 5.33497162E+01, dy + scale * 2.90410757E+00);
    glVertex2d(dx + scale * 5.33497162E+01, dy + scale * 2.90410757E+00);
    glVertex2d(dx + scale * 5.50459785E+01, dy + scale * 1.75542593E+00);
    glVertex2d(dx + scale * 5.50459785E+01, dy + scale * 1.75542593E+00);
    glVertex2d(dx + scale * 5.68888969E+01, dy + scale * 2.65009236E+00);
    glVertex2d(dx + scale * 5.68888969E+01, dy + scale * 2.65009236E+00);
    glVertex2d(dx + scale * 5.70355530E+01, dy + scale * 4.69344044E+00);
    glVertex2d(dx + scale * 5.70355530E+01, dy + scale * 4.69344044E+00);
    glVertex2d(dx + scale * 5.53392906E+01, dy + scale * 5.84212208E+00);
    glVertex2d(dx + scale * 4.06703568E+01, dy + scale * 6.64360666E+00);
    glVertex2d(dx + scale * 3.95109940E+01, dy + scale * 5.42419529E+00);
    glVertex2d(dx + scale * 3.95109940E+01, dy + scale * 5.42419529E+00);
    glVertex2d(dx + scale * 3.99873543E+01, dy + scale * 3.81045246E+00);
    glVertex2d(dx + scale * 3.99873543E+01, dy + scale * 3.81045246E+00);
    glVertex2d(dx + scale * 4.16230736E+01, dy + scale * 3.41612053E+00);
    glVertex2d(dx + scale * 4.16230736E+01, dy + scale * 3.41612053E+00);
    glVertex2d(dx + scale * 4.20994339E+01, dy + scale * 1.80237734E+00);
    glVertex2d(dx + scale * 4.20994339E+01, dy + scale * 1.80237734E+00);
    glVertex2d(dx + scale * 4.37351570E+01, dy + scale * 1.40804553E+00);
    glVertex2d(dx + scale * 4.37351570E+01, dy + scale * 1.40804553E+00);
    glVertex2d(dx + scale * 4.48945198E+01, dy + scale * 2.62745667E+00);
    glVertex2d(dx + scale * 4.48945198E+01, dy + scale * 2.62745667E+00);
    glVertex2d(dx + scale * 4.44181595E+01, dy + scale * 4.24119997E+00);
    glVertex2d(dx + scale * 4.44181595E+01, dy + scale * 4.24119997E+00);
    glVertex2d(dx + scale * 4.27824364E+01, dy + scale * 4.63553190E+00);
    glVertex2d(dx + scale * 4.27824364E+01, dy + scale * 4.63553190E+00);
    glVertex2d(dx + scale * 4.23060799E+01, dy + scale * 6.24927473E+00);
    glVertex2d(dx + scale * 4.23060799E+01, dy + scale * 6.24927473E+00);
    glVertex2d(dx + scale * 4.06703568E+01, dy + scale * 6.64360666E+00);
    glVertex2d(dx + scale * 2.04135437E+01, dy + scale * 5.37603645E+01);
    glVertex2d(dx + scale * 2.09234962E+01, dy + scale * 5.39400024E+01);
    glVertex2d(dx + scale * 2.09234962E+01, dy + scale * 5.39400024E+01);
    glVertex2d(dx + scale * 2.10229034E+01, dy + scale * 5.44714508E+01);
    glVertex2d(dx + scale * 2.10229034E+01, dy + scale * 5.44714508E+01);
    glVertex2d(dx + scale * 2.06123581E+01, dy + scale * 5.48232651E+01);
    glVertex2d(dx + scale * 2.06123581E+01, dy + scale * 5.48232651E+01);
    glVertex2d(dx + scale * 2.01024036E+01, dy + scale * 5.46436272E+01);
    glVertex2d(dx + scale * 2.01024036E+01, dy + scale * 5.46436272E+01);
    glVertex2d(dx + scale * 2.00029964E+01, dy + scale * 5.41121788E+01);
    glVertex2d(dx + scale * 2.00029964E+01, dy + scale * 5.41121788E+01);
    glVertex2d(dx + scale * 2.04135437E+01, dy + scale * 5.37603645E+01);
    glVertex2d(dx + scale * 2.92241192E+01, dy + scale * 5.89225616E+01);
    glVertex2d(dx + scale * 2.92241192E+01, dy + scale * 6.01559525E+01);
    glVertex2d(dx + scale * 2.92241192E+01, dy + scale * 6.01559525E+01);
    glVertex2d(dx + scale * 2.81559734E+01, dy + scale * 6.07726440E+01);
    glVertex2d(dx + scale * 2.81559734E+01, dy + scale * 6.07726440E+01);
    glVertex2d(dx + scale * 2.70878277E+01, dy + scale * 6.01559525E+01);
    glVertex2d(dx + scale * 2.70878277E+01, dy + scale * 6.01559525E+01);
    glVertex2d(dx + scale * 2.70878277E+01, dy + scale * 5.89225616E+01);
    glVertex2d(dx + scale * 2.70878277E+01, dy + scale * 5.89225616E+01);
    glVertex2d(dx + scale * 2.81559734E+01, dy + scale * 5.83058662E+01);
    glVertex2d(dx + scale * 2.81559734E+01, dy + scale * 5.83058662E+01);
    glVertex2d(dx + scale * 2.92241192E+01, dy + scale * 5.89225616E+01);
    glVertex2d(dx + scale * 4.00748558E+01, dy + scale * 6.66682663E+01);
    glVertex2d(dx + scale * 4.00748558E+01, dy + scale * 6.86397629E+01);
    glVertex2d(dx + scale * 4.00748558E+01, dy + scale * 6.86397629E+01);
    glVertex2d(dx + scale * 3.83674927E+01, dy + scale * 6.96255112E+01);
    glVertex2d(dx + scale * 3.83674927E+01, dy + scale * 6.96255112E+01);
    glVertex2d(dx + scale * 3.66601257E+01, dy + scale * 6.86397629E+01);
    glVertex2d(dx + scale * 3.66601257E+01, dy + scale * 6.86397629E+01);
    glVertex2d(dx + scale * 3.66601257E+01, dy + scale * 6.66682663E+01);
    glVertex2d(dx + scale * 3.66601257E+01, dy + scale * 6.66682663E+01);
    glVertex2d(dx + scale * 3.83674927E+01, dy + scale * 6.56825180E+01);
    glVertex2d(dx + scale * 3.83674927E+01, dy + scale * 6.56825180E+01);
    glVertex2d(dx + scale * 4.00748558E+01, dy + scale * 6.66682663E+01);
    glVertex2d(dx + scale * 3.55498581E+01, dy + scale * 5.91182632E+01);
    glVertex2d(dx + scale * 3.62619553E+01, dy + scale * 5.99602509E+01);
    glVertex2d(dx + scale * 3.62619553E+01, dy + scale * 5.99602509E+01);
    glVertex2d(dx + scale * 3.58888245E+01, dy + scale * 6.09979362E+01);
    glVertex2d(dx + scale * 3.58888245E+01, dy + scale * 6.09979362E+01);
    glVertex2d(dx + scale * 3.48035927E+01, dy + scale * 6.11936378E+01);
    glVertex2d(dx + scale * 3.48035927E+01, dy + scale * 6.11936378E+01);
    glVertex2d(dx + scale * 3.40914955E+01, dy + scale * 6.03516541E+01);
    glVertex2d(dx + scale * 3.40914955E+01, dy + scale * 6.03516541E+01);
    glVertex2d(dx + scale * 3.44646263E+01, dy + scale * 5.93139648E+01);
    glVertex2d(dx + scale * 3.44646263E+01, dy + scale * 5.93139648E+01);
    glVertex2d(dx + scale * 3.55498581E+01, dy + scale * 5.91182632E+01);
    glEnd();
    break;
  default: break;
  }

  glDisable(GL_BLEND);
  glDisable(GL_LINE_SMOOTH);
  glPopMatrix();
}

void Navigator::move()
{
  if(pad->toggle(pad->button_map[3])) {
    switch(mode) {
    case PEDESTRIAN: mode = DIVER; break;
    case DIVER: mode = PEDESTRIAN; break;
    default: break;
    }
  }
  // reset 1:1
  if(pad->toggle(pad->button_map[8])) {
    ctx->camera.lookAtCg();
    reference_speed = 1.5 * frequency * (ctx->camera.Lc) / 100.;
  }
  // change the plane
  if(pad->toggle(pad->button_map[0])) ctx->camera.lookAtCg();
  if(pad->toggle(pad->button_map[1])) {
    switch(along) {
    case AXE_X:
      along = AXE_Y;
      ctx->camera.alongY();
      break;
    case AXE_Y:
      along = AXE_Z;
      ctx->camera.alongZ();
      break;
    case AXE_Z:
      along = AXE_X;
      ctx->camera.alongX();
      break;
    default: break;
    }
  }
  // reset vertical axe or invers it
  if(pad->toggle(pad->button_map[2])) {
    switch(along) {
    case AXE_X: ctx->camera.upZ(); break;
    case AXE_Y: ctx->camera.upX(); break;
    case AXE_Z: ctx->camera.upY(); break;
    default: break;
    }
  }
  // head movement is damped to avoid nausea
  if(pad->button[pad->button_map[4]]) {
    ax0 = int(pad->axe[pad->axe_map[0]] * 10) / 10.;
    ax1 = int(pad->axe[pad->axe_map[1]] * 10) / 10.;
    if(ax1 > 0.) ax0 = -ax0;
  }
  else {
    ax0 = 0.;
    ax1 = 0.;
  }
  if((ax0 - ax0_cur) > 0.) {
    ax0_cur = ax0_cur + std::min((ax0 - ax0_cur), 0.005);
  }
  else {
    ax0_cur = ax0_cur + std::max((ax0 - ax0_cur), -0.005);
  }

  if((ax1 - ax1_cur) > 0.) {
    ax1_cur = ax1_cur + std::min((ax1 - ax1_cur), 0.005);
  }
  else {
    ax1_cur = ax1_cur + std::max((ax1 - ax1_cur), -0.005);
  }

  azimut = -(ax0_cur) * (2. * ctx->camera.aperture * 0.01745329);
  elevation = (ax1_cur) * (2. * ctx->camera.aperture * 0.01745329);

  //========================================================

  switch(mode) {
  case PEDESTRIAN:
    //------------------------------------------
    // accelaration
    if(!pad->button[pad->button_map[4]]) {
      if(pad->axe[pad->axe_map[1]] != 0.) {
        acc = -pad->axe[pad->axe_map[1]] * ctx->camera.Lc / 500. * frequency;
        if(acc > 0.) { speed = reference_speed + acc; }
        else {
          speed = reference_speed + 2. * acc;
        }
        speed = std::max(speed, (frequency * ctx->camera.Lc / 1000.));
        reference_speed = std::min(speed, (frequency * (ctx->camera.Lc)));
        /*
          std::cout<<"acc: "<< acc << std::endl;
          std::cout<<"lc: "<< ctx->camera.Lc << std::endl;
          std::cout<<"vitesse: "<< reference_speed << std::endl;
        */
      }
    }
    lift = -.25 * pad->axe[pad->axe_map[5]] * reference_speed;
    lateral = 0.25 * pad->axe[pad->axe_map[4]] * reference_speed;
    angular_lat = -1.0 * (pad->axe[pad->axe_map[2]]) * reference_angle;
    // walk else run
    if(pad->button[pad->button_map[6]]) {
      speed = -1.0 * pad->axe[pad->axe_map[3]] * reference_speed;
    }
    else {
      speed = -4.0 * (pad->axe[pad->axe_map[3]]) * reference_speed;
    }
    ctx->camera.move_and_look(speed, lateral, lift, 0., 0., angular_lat, azimut,
                              elevation);
    //-------------------------------------

    break; // end of mode PESDESTRIAN

  case DIVER:
    //-------------------------------------
    // accelaration
    //    pad->affiche();
    if(!pad->button[pad->button_map[4]]) {
      angular_fr = 1.0 * (pad->axe[pad->axe_map[0]]) * reference_angle;
      if(pad->axe[pad->axe_map[1]] != 0.) {
        acc = -pad->axe[pad->axe_map[1]] * ctx->camera.Lc / 1000. * frequency;
        if(acc > 0.) { speed = reference_speed + acc; }
        else {
          speed = reference_speed + 2. * acc;
        }
        speed = std::max(speed, (frequency * ctx->camera.Lc / 1000.));
        reference_speed = std::min(speed, (frequency * (ctx->camera.Lc)));
      }
      if(pad->button[pad->button_map[6]]) { speed = reference_speed; }
      else {
        speed = 0.;
      }
    }

    lift = -.25 * pad->axe[pad->axe_map[5]] * reference_speed;
    lateral = 0.25 * pad->axe[pad->axe_map[4]] * reference_speed;
    angular_lat = -1.0 * (pad->axe[pad->axe_map[2]]) * reference_angle;
    angular_up = 1.0 * (pad->axe[pad->axe_map[3]]) * reference_angle;

    ctx->camera.move_and_look(speed, lateral, lift, angular_fr, angular_up,
                              angular_lat, azimut, elevation);
    //-------------------------------------
    break; // end of mode DIVER

  case PLANE: break; // end of mode PLANE

  case CAR: break; // end of mode CAR

  default: break;

  } // end of switch(mode)
}
