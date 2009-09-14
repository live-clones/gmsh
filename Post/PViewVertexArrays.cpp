// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Iso.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "PViewDataRemote.h"
#include "Numeric.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "Context.h"
#include "mathEvaluator.h"

static void saturate(int nb, double val[PVIEW_NMAX][9], double vmin, double vmax, 
                     int i0=0, int i1=1, int i2=2, int i3=3, 
                     int i4=4, int i5=5, int i6=6, int i7=7)
{
  int id[8] = {i0, i1, i2, i3, i4, i5, i6, i7};
  for(int i = 0; i < nb; i++){
    if(val[id[i]][0] > vmax)      val[id[i]][0] = vmax;
    else if(val[id[i]][0] < vmin) val[id[i]][0] = vmin;
  }
}

static SVector3 normal3(double xyz[PVIEW_NMAX][3], int i0=0, int i1=1, int i2=2)
{
  SVector3 t1(xyz[i1][0] - xyz[i0][0], 
              xyz[i1][1] - xyz[i0][1],
              xyz[i1][2] - xyz[i0][2]);
  SVector3 t2(xyz[i2][0] - xyz[i0][0], 
              xyz[i2][1] - xyz[i0][1],
              xyz[i2][2] - xyz[i0][2]);
  SVector3 n = crossprod(t1, t2);
  n.normalize();
  return n;
}

static SVector3 getPointNormal(PView *p, double v)
{
  PViewOptions *opt = p->getOptions();
  SVector3 n(0., 0., 0.);
  if(opt->pointType > 0){
    // when we draw spheres, we use the normalized value (between 0
    // and 1) stored in the first component of the normal to modulate
    // the radius
    double d = opt->tmpMax - opt->tmpMin;
    n[0] = (v - opt->tmpMin) / (d ? d : 1.);
  }
  return n;
}

static void getLineNormal(PView *p, double x[2], double y[2], double z[2],
                          double *v, SVector3 n[2], bool computeNormal)
{
  PViewOptions *opt = p->getOptions();

  if(opt->lineType > 0){
    if(v){
      // when we draw tapered cylinders, we use the normalized values
      // (between 0 and 1) stored in the first component of the
      // normals to modulate the width
      double d = opt->tmpMax - opt->tmpMin;
      n[0][0] = (v[0] - opt->tmpMin) / (d ? d : 1.);
      n[1][0] = (v[1] - opt->tmpMin) / (d ? d : 1.);
    }
    else{
      // when we don't have values we use maximum width cylinders
      n[0][0] = n[1][0] = 1.;
    }
  }
  else if(computeNormal){
    SBoundingBox3d bb = p->getData()->getBoundingBox();
    if(bb.min().z() == bb.max().z())
      n[0] = n[1] = SVector3(0., 0., 1.);
    else if(bb.min().y() == bb.max().y())
      n[0] = n[1] = SVector3(0., 1., 0.);
    else if(bb.min().x() == bb.max().x())
      n[0] = n[1] = SVector3(1., 0., 0.);
    else{
      // we don't have any info about the normal, just pick one
      SVector3 t(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
      SVector3 ex(0., 0., 0.);
      if(t[0] == 0.)
        ex[0] = 1.;
      else if(t[1] == 0.)
        ex[1] = 1.;
      else
        ex[2] = 1.;
      n[0] = crossprod(t, ex);
      n[0].normalize();
      n[1] = n[0];
    }
  }
}

static bool getExternalValues(PView *p, int index, int ient, int iele, 
                              int numNodes, int numComp, double val[PVIEW_NMAX][9],
                              int &numComp2, double val2[PVIEW_NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  // use self by default
  numComp2 = numComp;
  for(int i = 0; i < numNodes; i++)
    for(int j = 0; j < numComp; j++)
      val2[i][j] = val[i][j];
  opt->externalMin = opt->tmpMin;
  opt->externalMax = opt->tmpMax;

  if(index < 0 || index >= (int)PView::list.size()) return false;

  PView *p2 = PView::list[index];
  PViewData *data2 = p2->getData();

  if(opt->timeStep < data2->getNumTimeSteps() && 
     iele < data2->getNumElements(opt->timeStep, ient)){
    if(data2->getNumNodes(opt->timeStep, ient, iele) == numNodes){
      numComp2 = data2->getNumComponents(opt->timeStep, ient, iele);
      for(int i = 0; i < numNodes; i++)
        for(int j = 0; j < numComp2; j++)
          data2->getValue(opt->timeStep, ient, iele, i, j, val2[i][j]);
      if(opt->rangeType == PViewOptions::Custom){
        opt->externalMin = opt->customMin;
        opt->externalMax = opt->customMax;
      }
      else if(opt->rangeType == PViewOptions::PerTimeStep){
        opt->externalMin = data2->getMin(opt->timeStep);
        opt->externalMax = data2->getMax(opt->timeStep);
      }
      else{
        opt->externalMin = data2->getMin();
        opt->externalMax = data2->getMax();
      }
      return true;
    }
  }
  return false;
}

static void applyGeneralRaise(PView *p, int numNodes, int numComp, 
                              double vals[PVIEW_NMAX][9], double xyz[PVIEW_NMAX][3])
{
  PViewOptions *opt = p->getOptions();
  if(!opt->genRaiseEvaluator) return;

  std::vector<double> values(12, 0.), res(3);
  for(int k = 0; k < numNodes; k++) {
    for(int i = 0; i < 3; i++) values[i] = xyz[k][i];
    for(int i = 0; i < std::min(numComp, 9); i++) values[3 + i] = vals[k][i];
    if(opt->genRaiseEvaluator->eval(values, res))
      for(int i = 0; i < 3; i++)
        xyz[k][i] += opt->genRaiseFactor * res[i];
  }
}

void changeCoordinates(PView *p, int ient, int iele,
                       int numNodes, int type, int numComp, 
                       double xyz[PVIEW_NMAX][3], double val[PVIEW_NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  if(opt->explode != 1.) {
    double barycenter[3] = {0., 0., 0.};
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
        barycenter[j] += xyz[i][j];
    for(int j = 0; j < 3; j++)
      barycenter[j] /= (double)numNodes;
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
        xyz[i][j] = barycenter[j] + opt->explode * (xyz[i][j] - barycenter[j]);
  }
  
  if(opt->transform[0][0] != 1. || opt->transform[0][1] != 0. || 
     opt->transform[0][2] != 0. || opt->transform[1][0] != 0. || 
     opt->transform[1][1] != 1. || opt->transform[1][2] != 0. ||
     opt->transform[2][0] != 0. || opt->transform[2][1] != 0. || 
     opt->transform[2][2] != 1.){
    for(int i = 0; i < numNodes; i++) {
      double old[3] = {xyz[i][0], xyz[i][1], xyz[i][2]};
      for(int j = 0; j < 3; j++){
        xyz[i][j] = 0.;
        for(int k = 0; k < 3; k++)
          xyz[i][j] += opt->transform[j][k] * old[k];
      }
    }
  }
  
  if(opt->offset[0] || opt->offset[1] || opt->offset[2]){
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
        xyz[i][j] += opt->offset[j];
  }
  
  if(opt->raise[0] || opt->raise[1] || opt->raise[2]){
    for(int i = 0; i < numNodes; i++){
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++)
        xyz[i][j] += opt->raise[j] * v;
    }
  }

  if(opt->normalRaise && (type == TYPE_LIN || type == TYPE_TRI || type ==TYPE_QUA)){
    SVector3 n;
    if(type == TYPE_LIN){
      // assumes lines in z=const plane, and raises in that plane
      double x[2] = {xyz[0][0], xyz[1][0]};
      double y[2] = {xyz[0][1], xyz[1][1]};
      double z[2] = {xyz[0][2], xyz[1][2]};
      SVector3 p(0, 0, 1.);
      SVector3 t(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
      n = crossprod(t, p);
      n.normalize();
    }
    else
      n = normal3(xyz);
    for(int i = 0; i < numNodes; i++){
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++)
        xyz[i][j] += n[j] * opt->normalRaise * v;
    }
  }

  if(numComp == 3 && opt->vectorType == PViewOptions::Displacement){
    for(int i = 0; i < numNodes; i++){
      for(int j = 0; j < 3; j++)
        xyz[i][j] += opt->displacementFactor * val[i][j];
    }
  }

  if(opt->useGenRaise){
    int numComp2;
    double val2[PVIEW_NMAX][9];
    getExternalValues(p, opt->viewIndexForGenRaise, ient, iele, numNodes, 
                      numComp, val, numComp2, val2);
    applyGeneralRaise(p, numNodes, numComp2, val2, xyz);
  }
}

static double evalClipPlane(int clip, double x, double y, double z)
{
  return CTX::instance()->clipPlane[clip][0] * x + 
    CTX::instance()->clipPlane[clip][1] * y + 
    CTX::instance()->clipPlane[clip][2] * z + 
    CTX::instance()->clipPlane[clip][3];
}

static double intersectClipPlane(int clip, int numNodes, double xyz[PVIEW_NMAX][3])
{
  double val = evalClipPlane(clip, xyz[0][0], xyz[0][1], xyz[0][2]);
  for(int i = 1; i < numNodes; i++){
    if(val * evalClipPlane(clip, xyz[i][0], xyz[i][1], xyz[i][2]) <= 0)
      return 0.; // the element intersects the cut plane
  }
  return val;
}

static bool isElementVisible(PViewOptions *opt, int dim, int numNodes, 
                             double xyz[PVIEW_NMAX][3])
{
  if(!CTX::instance()->clipWholeElements) return true;
  bool hidden = false;
  for(int clip = 0; clip < 6; clip++){
    if(opt->clip & (1 << clip)){
      if(dim < 3 && CTX::instance()->clipOnlyVolume){
      }
      else{
        double d = intersectClipPlane(clip, numNodes, xyz);
        if(dim == 3 && CTX::instance()->clipOnlyDrawIntersectingVolume && d){
          hidden = true;
          break;
        }
        else if(d < 0){
          hidden = true;
          break;
        }
      }
    }
  }
  return !hidden;
}

static void addOutlinePoint(PView *p, double xyz[PVIEW_NMAX][3], unsigned int color, 
                            bool pre, int i0=0)
{
  if(pre) return;
  SVector3 n = getPointNormal(p, 1.);
  p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &color, 0, true);
}

static void addScalarPoint(PView *p, double xyz[PVIEW_NMAX][3], 
                           double val[PVIEW_NMAX][9], bool pre, int i0=0, 
                           bool unique=false)
{
  if(pre) return;

  PViewOptions *opt = p->getOptions();

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(1, val, vmin, vmax, i0);

  if(val[i0][0] >= vmin && val[i0][0] <= vmax){
    unsigned int col = opt->getColor(val[i0][0], vmin, vmax, false, 
                                     (opt->intervalsType == PViewOptions::Discrete) ? 
                                     opt->nbIso : -1);
    SVector3 n = getPointNormal(p, val[i0][0]);
    p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &col, 0, unique);
  }
}

static void addOutlineLine(PView *p, double xyz[PVIEW_NMAX][3], unsigned int color,
                           bool pre, int i0=0, int i1=1)
{
  if(pre) return;

  const int in[3] = {i0, i1};
  unsigned int col[2];
  double x[2], y[2], z[2];
  for(int i = 0; i < 2; i++){
    x[i] = xyz[in[i]][0]; y[i] = xyz[in[i]][1]; z[i] = xyz[in[i]][2]; 
    col[i] = color;
  }
  SVector3 n[2];
  getLineNormal(p, x, y, z, 0, n, true);
  p->va_lines->add(x, y, z, n, col, 0, true);
}

static void addScalarLine(PView *p, double xyz[PVIEW_NMAX][3], 
                          double val[PVIEW_NMAX][9], bool pre, int i0=0, int i1=1,
                          bool unique=false)
{
  if(pre) return;

  PViewOptions *opt = p->getOptions();

  if(opt->boundary > 0){
    opt->boundary--;
    addScalarPoint(p, xyz, val, pre, i0, true);
    addScalarPoint(p, xyz, val, pre, i1, true);
    opt->boundary++;
    return;
  }

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(2, val, vmin, vmax, i0, i1);

  double x[2] = {xyz[i0][0], xyz[i1][0]};
  double y[2] = {xyz[i0][1], xyz[i1][1]};
  double z[2] = {xyz[i0][2], xyz[i1][2]};
  double v[2] = {val[i0][0], val[i1][0]};

  if(opt->intervalsType == PViewOptions::Continuous){
    SVector3 n[2];
    getLineNormal(p, x, y, z, v, n, true);
    if(val[i0][0] >= vmin && val[i0][0] <= vmax &&
       val[i1][0] >= vmin && val[i1][0] <= vmax){
      unsigned int col[2];
      for(int i = 0; i < 2; i++)
        col[i] = opt->getColor(v[i], vmin, vmax);
      p->va_lines->add(x, y, z, n, col, 0, unique);
    }
    else{
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      if(nb == 2){
        unsigned int col[2];
        for(int i = 0; i < 2; i++)
          col[i] = opt->getColor(v2[i], vmin, vmax);
        p->va_lines->add(x2, y2, z2, n, col, 0, unique);
      }
    }
  }

  if(opt->intervalsType == PViewOptions::Discrete){
    for(int k = 0; k < opt->nbIso; k++){
      if(vmin == vmax) k = opt->nbIso / 2;
      double min = opt->getScaleValue(k, opt->nbIso + 1, vmin, vmax);
      double max = opt->getScaleValue(k + 1, opt->nbIso + 1, vmin, vmax);
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, min, max, x2, y2, z2, v2);
      if(nb == 2){
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[2] = {color, color};
        SVector3 n[2];
        getLineNormal(p, x2, y2, z2, v2, n, true);
        p->va_lines->add(x2, y2, z2, n, col, 0, unique);
      }
      if(vmin == vmax) break;
    }
  }
  
  if(opt->intervalsType == PViewOptions::Iso){
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double iso = opt->getScaleValue(k, opt->nbIso, vmin, vmax);
      double x2[1], y2[1], z2[1];
      int nb = IsoLine(x, y, z, v, iso, x2, y2, z2);
      if(nb == 1){
        unsigned int color = opt->getColor(k, opt->nbIso);
        SVector3 n = getPointNormal(p, iso);
        p->va_points->add(x2, y2, z2, &n, &color, 0, unique);
      }
      if(vmin == vmax) break;
    }
  }
}

static void addOutlineTriangle(PView *p, double xyz[PVIEW_NMAX][3],
                               unsigned int color, bool pre, int i0=0,
                               int i1=1, int i2=2)
{
  PViewOptions *opt = p->getOptions();

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  for(int i = 0; i < 3; i++){
    double x[2] = {xyz[il[i][0]][0], xyz[il[i][1]][0]};
    double y[2] = {xyz[il[i][0]][1], xyz[il[i][1]][1]};
    double z[2] = {xyz[il[i][0]][2], xyz[il[i][1]][2]};
    SVector3 n[2] = {nfac, nfac};
    unsigned int col[2] = {color, color};
    if(opt->smoothNormals){
      for(int j = 0; j < 2; j++){
        if(pre) p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
        else p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
    }
    getLineNormal(p, x, y, z, 0, n, false);
    if(!pre) p->va_lines->add(x, y, z, n, col, 0, true);
  }
}

static void addScalarTriangle(PView *p, double xyz[PVIEW_NMAX][3], 
                              double val[PVIEW_NMAX][9], 
                              bool pre, int i0=0, int i1=1, int i2=2,
                              bool unique=false, bool skin=false)
{
  PViewOptions *opt = p->getOptions();

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  if(opt->boundary > 0){
    opt->boundary--;
    for(int i = 0; i < 3; i++)
      addScalarLine(p, xyz, val, pre, il[i][0], il[i][1], true);
    opt->boundary++;
    return;
  }

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(3, val, vmin, vmax, i0, i1, i2);

  double x[3] = {xyz[i0][0], xyz[i1][0], xyz[i2][0]};
  double y[3] = {xyz[i0][1], xyz[i1][1], xyz[i2][1]};
  double z[3] = {xyz[i0][2], xyz[i1][2], xyz[i2][2]};
  double v[3] = {val[i0][0], val[i1][0], val[i2][0]};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  if(opt->intervalsType == PViewOptions::Continuous){
    if(val[i0][0] >= vmin && val[i0][0] <= vmax &&
       val[i1][0] >= vmin && val[i1][0] <= vmax &&
       val[i2][0] >= vmin && val[i2][0] <= vmax){
      SVector3 n[3] = {nfac, nfac, nfac};
      unsigned int col[3];
      for(int i = 0; i < 3; i++){
        if(opt->smoothNormals){
          if(pre) p->normals->add(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
          else p->normals->get(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
        }
        col[i] = opt->getColor(v[i], vmin, vmax);
      }
      if(!pre) p->va_triangles->add(x, y, z, n, col, 0, unique, skin);
    }
    else{
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      if(nb >= 3){
        for(int j = 2; j < nb; j++){
          double x3[3] = {x2[0], x2[j - 1], x2[j]};
          double y3[3] = {y2[0], y2[j - 1], y2[j]};
          double z3[3] = {z2[0], z2[j - 1], z2[j]};
          double v3[3] = {v2[0], v2[j - 1], v2[j]};
          SVector3 n[3] = {nfac, nfac, nfac};
          unsigned int col[3];
          for(int i = 0; i < 3; i++){
            if(opt->smoothNormals){
              if(pre) p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
              else p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
            }
            col[i] = opt->getColor(v3[i], vmin, vmax);
          }
          if(!pre) p->va_triangles->add(x3, y3, z3, n, col, 0, unique, skin);
        }
      }
    }
  }

  if(opt->intervalsType == PViewOptions::Discrete){
    for(int k = 0; k < opt->nbIso; k++){
      if(vmin == vmax) k = opt->nbIso / 2;
      double min = opt->getScaleValue(k, opt->nbIso + 1, vmin, vmax);
      double max = opt->getScaleValue(k + 1, opt->nbIso + 1, vmin, vmax);
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, min, max, x2, y2, z2, v2);
      if(nb >= 3){
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[3] = {color, color, color};
        for(int j = 2; j < nb; j++){
          double x3[3] = {x2[0], x2[j - 1], x2[j]};
          double y3[3] = {y2[0], y2[j - 1], y2[j]};
          double z3[3] = {z2[0], z2[j - 1], z2[j]};
          SVector3 n[3] = {nfac, nfac, nfac};
          if(opt->smoothNormals){
            for(int i = 0; i < 3; i++){
              if(pre) p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
              else p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
            }
          }
          if(!pre) p->va_triangles->add(x3, y3, z3, n, col, 0, unique, skin);
        }
      }
      if(vmin == vmax) break;
    }
  }
  
  if(opt->intervalsType == PViewOptions::Iso){
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double iso = opt->getScaleValue(k, opt->nbIso, vmin, vmax);
      double x2[3], y2[3], z2[3];
      int nb = IsoTriangle(x, y, z, v, iso, x2, y2, z2);
      if(nb == 2){
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[2] = {color, color};
        SVector3 n[2] = {nfac, nfac};
        if(opt->smoothNormals){
          for(int i = 0; i < 2; i++){
            if(pre) p->normals->add(x2[i], y2[i], z2[i], n[i][0], n[i][1], n[i][2]);
            else p->normals->get(x2[i], y2[i], z2[i], n[i][0], n[i][1], n[i][2]);
          }
        }
        double v[2] = {iso, iso};
        getLineNormal(p, x, y, z, v, n, false);
        if(!pre) p->va_lines->add(x2, y2, z2, n, col, 0, unique);
      }
      if(vmin == vmax) break;
    }
  }
}

static void addOutlineQuadrangle(PView *p, double xyz[PVIEW_NMAX][3], 
                                 unsigned int color, bool pre, int i0=0, int i1=1, 
                                 int i2=2, int i3=3)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  for(int i = 0; i < 4; i++){
    double x[2] = {xyz[il[i][0]][0], xyz[il[i][1]][0]};
    double y[2] = {xyz[il[i][0]][1], xyz[il[i][1]][1]};
    double z[2] = {xyz[il[i][0]][2], xyz[il[i][1]][2]};
    SVector3 n[2] = {nfac, nfac};
    unsigned int col[2] = {color, color};
    if(opt->smoothNormals){
      for(int j = 0; j < 2; j++){
        if(pre) p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
        else p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
    }
    getLineNormal(p, x, y, z, 0, n, false);
    if(!pre) p->va_lines->add(x, y, z, n, col, 0, true);
  }
}

static void addScalarQuadrangle(PView *p, double xyz[PVIEW_NMAX][3], 
                                double val[PVIEW_NMAX][9], bool pre, int i0=0, 
                                int i1=1, int i2=2, int i3=3, bool unique=false)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};
  const int it[2][3] = {{i0, i1, i2}, {i0, i2, i3}};

  if(opt->boundary > 0){
    opt->boundary--;
    for(int i = 0; i < 4; i++)
      addScalarLine(p, xyz, val, pre, il[i][0], il[i][1], true);
    opt->boundary++;
    return;
  }
  
  for(int i = 0; i < 2; i++)
    addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], unique);
}

static void addOutlineTetrahedron(PView *p, double xyz[PVIEW_NMAX][3], 
                                  unsigned int color, bool pre)
{
  const int it[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

static void addScalarTetrahedron(PView *p, double xyz[PVIEW_NMAX][3], 
                                 double val[PVIEW_NMAX][9], bool pre, int i0=0, 
                                 int i1=1, int i2=2, int i3=3)
{
  PViewOptions *opt = p->getOptions();

  const int it[4][3] = {{i0, i2, i1}, {i0, i1, i3}, {i0, i3, i2}, {i3, i1, i2}};

  if(opt->boundary > 0 ||
     opt->intervalsType == PViewOptions::Continuous ||
     opt->intervalsType == PViewOptions::Discrete){
    bool skin = (opt->boundary > 0) ? false : opt->drawSkinOnly;
    opt->boundary--;
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true, skin);
    opt->boundary++;
    return;
  }

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(4, val, vmin, vmax, i0, i1, i2, i3);

  double x[4] = {xyz[i0][0], xyz[i1][0], xyz[i2][0], xyz[i3][0]};
  double y[4] = {xyz[i0][1], xyz[i1][1], xyz[i2][1], xyz[i3][1]};
  double z[4] = {xyz[i0][2], xyz[i1][2], xyz[i2][2], xyz[i3][2]};
  double v[4] = {val[i0][0], val[i1][0], val[i2][0], val[i3][0]};

  if(opt->intervalsType == PViewOptions::Iso){
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double iso = opt->getScaleValue(k, opt->nbIso, vmin, vmax);
      double x2[PVIEW_NMAX], y2[PVIEW_NMAX], z2[PVIEW_NMAX], nn[3];
      int nb = IsoSimplex(x, y, z, v, iso, x2, y2, z2, nn);
      if(nb >= 3){
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[3] = {color, color, color};
        for(int j = 2; j < nb; j++){
          double x3[3] = {x2[0], x2[j - 1], x2[j]};
          double y3[3] = {y2[0], y2[j - 1], y2[j]};
          double z3[3] = {z2[0], z2[j - 1], z2[j]};
          SVector3 n[3];
          for(int i = 0; i < 3; i++){
            n[i][0] = nn[0]; n[i][1] = nn[1]; n[i][2] = nn[2];
            if(opt->smoothNormals){
              if(pre) p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
              else p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
            }
          }
          if(!pre) p->va_triangles->add(x3, y3, z3, n, col, 0, false, false);
        }
      }
      if(vmin == vmax) break;
    }
  }
}

static void addOutlineHexahedron(PView *p, double xyz[PVIEW_NMAX][3], 
                                 unsigned int color, bool pre)
{
  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
                        {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};

  for(int i = 0; i < 6; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], 
                         iq[i][2], iq[i][3]);
}

static void addScalarHexahedron(PView *p, double xyz[PVIEW_NMAX][3], 
                                double val[PVIEW_NMAX][9], bool pre)
{
  PViewOptions *opt = p->getOptions();

  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
                        {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
  const int is[6][4] = {{0, 1, 3, 7}, {0, 4, 1, 7}, {1, 4, 5, 7},
                        {1, 2, 3, 7}, {1, 6, 2, 7}, {1, 5, 6, 7}};

  if(opt->boundary > 0){
    opt->boundary--;
    for(int i = 0; i < 6; i++)
      addScalarQuadrangle(p, xyz, val, pre, iq[i][0], iq[i][1], iq[i][2], iq[i][3], true);
    opt->boundary++;
    return;
  }
  
  for(int i = 0; i < 6; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2], is[i][3]);
}

static void addOutlinePrism(PView *p, double xyz[PVIEW_NMAX][3], unsigned int color, 
                            bool pre)
{
  const int iq[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
  const int it[2][3] = {{0, 2, 1}, {3, 4, 5}};

  for(int i = 0; i < 3; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], iq[i][2], iq[i][3]);
  for(int i = 0; i < 2; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}
static void addScalarPrism(PView *p, double xyz[PVIEW_NMAX][3], 
                           double val[PVIEW_NMAX][9], bool pre)
{
  PViewOptions *opt = p->getOptions();
  const int iq[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
  const int it[2][3] = {{0, 2, 1}, {3, 4, 5}};
  const int is[3][4] = {{0, 1, 2, 3}, {3, 4, 5, 2}, {1, 2, 4, 3}};

  if(opt->boundary > 0){
    opt->boundary--;
    for(int i = 0; i < 3; i++)
      addScalarQuadrangle(p, xyz, val, pre, iq[i][0], iq[i][1], iq[i][2], iq[i][3], true);
    for(int i = 0; i < 2; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
    opt->boundary++;
    return;
  }
  
  for(int i = 0; i < 3; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2], is[i][3]);
}

static void addOutlinePyramid(PView *p, double xyz[PVIEW_NMAX][3],
                              unsigned int color, bool pre)
{
  const int it[4][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};

  addOutlineQuadrangle(p, xyz, color, pre, 0, 3, 2, 1);
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

static void addScalarPyramid(PView *p, double xyz[PVIEW_NMAX][3], 
                             double val[PVIEW_NMAX][9], bool pre)
{
  PViewOptions *opt = p->getOptions();

  const int it[4][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};
  const int is[2][4] = {{0, 1, 2, 4}, {2, 3, 0, 4}};

  if(opt->boundary > 0){
    opt->boundary--;
    addScalarQuadrangle(p, xyz, val, pre, 0, 3, 2, 1, true);
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
    opt->boundary++;
    return;
  }

  for(int i = 0; i < 2; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2], is[i][3]);
}

static void addOutlineElement(PView *p, int type, double xyz[PVIEW_NMAX][3], bool pre)
{
  PViewOptions *opt = p->getOptions();
  switch(type){
  case TYPE_PNT: addOutlinePoint(p, xyz, opt->color.point, pre); break;
  case TYPE_LIN: addOutlineLine(p, xyz, opt->color.line, pre); break;
  case TYPE_TRI: addOutlineTriangle(p, xyz, opt->color.triangle, pre); break;
  case TYPE_QUA: addOutlineQuadrangle(p, xyz, opt->color.quadrangle, pre); break;
  case TYPE_TET: addOutlineTetrahedron(p, xyz, opt->color.tetrahedron, pre); break;
  case TYPE_HEX: addOutlineHexahedron(p, xyz, opt->color.hexahedron, pre); break;
  case TYPE_PRI: addOutlinePrism(p, xyz, opt->color.prism, pre); break;
  case TYPE_PYR: addOutlinePyramid(p, xyz, opt->color.pyramid, pre); break;
  }
}

static void addScalarElement(PView *p, int type, double xyz[PVIEW_NMAX][3],
                             double val[PVIEW_NMAX][9], bool pre)
{
  switch(type){
  case TYPE_PNT: addScalarPoint(p, xyz, val, pre); break;
  case TYPE_LIN: addScalarLine(p, xyz, val, pre); break;
  case TYPE_TRI: addScalarTriangle(p, xyz, val, pre); break;
  case TYPE_QUA: addScalarQuadrangle(p, xyz, val, pre); break;
  case TYPE_TET: addScalarTetrahedron(p, xyz, val, pre); break;
  case TYPE_HEX: addScalarHexahedron(p, xyz, val, pre); break;
  case TYPE_PRI: addScalarPrism(p, xyz, val, pre); break;
  case TYPE_PYR: addScalarPyramid(p, xyz, val, pre); break;
  }
}

static void addVectorElement(PView *p, int ient, int iele, int numNodes, 
                             int type, double xyz[PVIEW_NMAX][3],
                             double val[PVIEW_NMAX][9], bool pre)
{
  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  int numComp2;
  double val2[PVIEW_NMAX][9];
  getExternalValues(p, opt->externalViewIndex, ient, iele, numNodes, 
                    3, val, numComp2, val2);

  if(opt->vectorType == PViewOptions::Displacement){
    for(int i = 0; i < numNodes; i++)
      val2[i][0] = ComputeScalarRep(numComp2, val2[i]);

    // add scalar element with correct min/max
    double min = opt->tmpMin, max = opt->tmpMax;
    opt->tmpMin = opt->externalMin;
    opt->tmpMax = opt->externalMax;
    addScalarElement(p, type, xyz, val2, pre);
    opt->tmpMin = min;
    opt->tmpMax = max;

    // add point trajectories
    if(!pre && numNodes == 1 && opt->timeStep > 0 && opt->lineWidth){
      for(int ts = 0; ts < opt->timeStep; ts++){
        double xyz0[3], dxyz[3][2];
        for(int j = 0; j < 3; j++){
          data->getNode(ts, ient, iele, 0, xyz0[0], xyz0[1], xyz0[2]);
          data->getValue(ts, ient, iele, 0, j, dxyz[j][0]);
          data->getValue(ts + 1, ient, iele, 0, j, dxyz[j][1]);
        }
        unsigned int col[2];
        double norm[2];
        for(int i = 0; i < 2; i++){
          norm[i] = sqrt(dxyz[0][i] * dxyz[0][i] + 
                         dxyz[1][i] * dxyz[1][i] + 
                         dxyz[2][i] * dxyz[2][i]);
          col[i] = opt->getColor(norm[i], opt->tmpMin, opt->tmpMax);
        }
        for(int j = 0; j < 3; j++){     
          dxyz[j][0] = xyz0[j] + dxyz[j][0] * opt->displacementFactor;
          dxyz[j][1] = xyz0[j] + dxyz[j][1] * opt->displacementFactor;
        }
        SVector3 n[2];
        getLineNormal(p, dxyz[0], dxyz[1], dxyz[2], norm, n, true);
        p->va_lines->add(dxyz[0], dxyz[1], dxyz[2], n, col, 0, false);
      }
    }
    return;
  }

  if(pre) return;

  if(opt->glyphLocation == PViewOptions::Vertex){
    for(int i = 0; i < numNodes; i++){
      double v2 = ComputeScalarRep(numComp2, val2[i]);
      if(v2 >= opt->externalMin && v2 <= opt->externalMax){
        unsigned int color = opt->getColor(v2, opt->externalMin, opt->externalMax, false,
                                           (opt->intervalsType == PViewOptions::Discrete) ? 
                                           opt->nbIso : -1);
        unsigned int col[2] = {color, color};
        double dxyz[3][2];
        for(int j = 0; j < 3; j++){
          dxyz[j][0] = xyz[i][j];
          dxyz[j][1] = val[i][j];
        }
        p->va_vectors->add(dxyz[0], dxyz[1], dxyz[2], 0, col, 0, false);
      }
    }
  }

  if(opt->glyphLocation == PViewOptions::COG){
    SPoint3 pc(0., 0., 0.);
    double d[3] = {0., 0., 0.};
    double d2[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};

    for(int i = 0; i < numNodes; i++){
      pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
      for(int j = 0; j < 3; j++) d[j] += val[i][j];
      for(int j = 0; j < numComp2; j++) d2[j] += val2[i][j];
    }
    pc /= (double)numNodes;
    for(int j = 0; j < 3; j++) d[j] /= (double)numNodes;
    for(int j = 0; j < numComp2; j++) d2[j] /= (double)numNodes;

    // need tolerance since we compare computed results (the average)
    // instead of the raw data used to compute bounds
    double v2 = ComputeScalarRep(numComp2, d2);
    if(v2 >= opt->externalMin * (1. - 1.e-15) &&
       v2 <= opt->externalMax * (1. + 1.e-15)){
      unsigned int color = opt->getColor(v2, opt->externalMin, opt->externalMax, false,
                                         (opt->intervalsType == PViewOptions::Discrete) ? 
                                         opt->nbIso : -1);
      unsigned int col[2] = {color, color};
      double dxyz[3][2];
      for(int i = 0; i < 3; i++){
        dxyz[i][0] = pc[i];
        dxyz[i][1] = d[i];
      }
      p->va_vectors->add(dxyz[0], dxyz[1], dxyz[2], 0, col, 0, false);
    }
  }
}

static void addTensorElement(PView *p, int numNodes, int type,
                             double xyz[PVIEW_NMAX][3], double val[PVIEW_NMAX][9], 
                             bool pre)
{
  PViewOptions *opt = p->getOptions();

  if(opt->tensorType == PViewOptions::VonMises){
    for(int i = 0; i < numNodes; i++)
      val[i][0] = ComputeVonMises(val[i]);
    addScalarElement(p, type, xyz, val, pre);
  }
}

static void addElementsInArrays(PView *p, bool preprocessNormalsOnly)
{
  static int numNodesError = 0, numCompError = 0;

  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();
  
  opt->tmpBBox.reset();

  double xyz[PVIEW_NMAX][3], val[PVIEW_NMAX][9];
  for(int ent = 0; ent < data->getNumEntities(opt->timeStep); ent++){
    if(data->skipEntity(opt->timeStep, ent)) continue;
    for(int i = 0; i < data->getNumElements(opt->timeStep, ent); i++){
      if(data->skipElement(opt->timeStep, ent, i, true)) continue;
      int type = data->getType(opt->timeStep, ent, i);
      if(opt->skipElement(type)) continue;
      int numComp = data->getNumComponents(opt->timeStep, ent, i);
      int numNodes = data->getNumNodes(opt->timeStep, ent, i);
      if(numNodes > PVIEW_NMAX){
        if(numNodesError != numNodes){
          numNodesError = numNodes;
          Msg::Error("You should never draw views with > %d nodes per element: use",
                     PVIEW_NMAX);
          Msg::Error("'Adapt visualization grid' to view high-order datasets!");
        }
        continue;
      }
      if(numComp > 9){
        if(numCompError != numComp){
          numCompError = numComp;
          Msg::Error("You should never draw views with > 9 values per node: use");
          Msg::Error("'Adapt visualization grid' to view high-order datasets!");
        }
        continue;
      }
      for(int j = 0; j < numNodes; j++){
        data->getNode(opt->timeStep, ent, i, j, xyz[j][0], xyz[j][1], xyz[j][2]);
        for(int k = 0; k < numComp; k++)
          data->getValue(opt->timeStep, ent, i, j, k, val[j][k]);
      }
      changeCoordinates(p, ent, i, numNodes, type, numComp, xyz, val);
      int dim = data->getDimension(opt->timeStep, ent, i);
      if(!isElementVisible(opt, dim, numNodes, xyz)) continue;

      for(int j = 0; j < numNodes; j++)
        opt->tmpBBox += SPoint3(xyz[j][0], xyz[j][1], xyz[j][2]);
      
      if(opt->showElement && !data->useGaussPoints()) 
        addOutlineElement(p, type, xyz, preprocessNormalsOnly);
      
      if(opt->intervalsType != PViewOptions::Numeric){
        if(data->useGaussPoints()){
          for(int j = 0; j < numNodes; j++){
            double xyz2[PVIEW_NMAX][3], val2[PVIEW_NMAX][9];
            xyz2[0][0] = xyz[j][0];
            xyz2[0][1] = xyz[j][1];
            xyz2[0][2] = xyz[j][2];
            for(int k = 0; k < numComp; k++)
              val2[0][k] = val[j][k];
            if(numComp == 1 && opt->drawScalars)
              addScalarElement(p, TYPE_PNT, xyz2, val2, preprocessNormalsOnly);
            else if(numComp == 3 && opt->drawVectors)
              addVectorElement(p, ent, i, 1, TYPE_PNT, xyz2, val2, preprocessNormalsOnly);
            else if(numComp == 9 && opt->drawTensors)
              addTensorElement(p, 1, TYPE_PNT, xyz2, val2, preprocessNormalsOnly);
          }
        }
        else if(numComp == 1 && opt->drawScalars)
          addScalarElement(p, type, xyz, val, preprocessNormalsOnly);
        else if(numComp == 3 && opt->drawVectors)
          addVectorElement(p, ent, i, numNodes, type, xyz, val, preprocessNormalsOnly);
        else if(numComp == 9 && opt->drawTensors)
          addTensorElement(p, numNodes, type, xyz, val, preprocessNormalsOnly);
      }
    }
  }
}

class initPView {
 private:
  // we try to estimate how many primitives will end up in the vertex
  // arrays, since reallocating the arrays takes a huge amount of time
  // on Windows/Cygwin
  int _estimateIfClipped(PView *p, int num)
  {
    if(CTX::instance()->clipWholeElements && 
       CTX::instance()->clipOnlyDrawIntersectingVolume){
      PViewOptions *opt = p->getOptions();
      for(int clip = 0; clip < 6; clip++){
        if(opt->clip & (1 << clip))
          return (int)sqrt((double)num);
      }
    }
    return num;
  }
  int _estimateNumPoints(PView *p)
  {
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();
    int heuristic = data->getNumPoints(opt->timeStep);
    return heuristic + 10000;
  }
  int _estimateNumLines(PView *p)
  {
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();
    int heuristic = data->getNumLines(opt->timeStep);
    return heuristic + 10000;
  }
  int _estimateNumTriangles(PView *p)
  {
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();
    int tris = data->getNumTriangles(opt->timeStep);
    int quads = data->getNumQuadrangles(opt->timeStep);
    int tets = data->getNumTetrahedra(opt->timeStep);
    int prisms = data->getNumPrisms(opt->timeStep);
    int pyrs = data->getNumPyramids(opt->timeStep);
    int hexas = data->getNumHexahedra(opt->timeStep);
    int heuristic = 0;
    if(opt->intervalsType == PViewOptions::Iso)
      heuristic = (tets + prisms + pyrs + hexas) / 10;
    else if(opt->intervalsType == PViewOptions::Continuous)
      heuristic = (tris + 2 * quads + 6 * tets + 
                   8 * prisms + 6 * pyrs + 12 * hexas);
    else if(opt->intervalsType == PViewOptions::Discrete)
      heuristic = (tris + 2 * quads + 6 * tets + 
                   8 * prisms + 6 * pyrs + 12 * hexas) * 2;
    heuristic = _estimateIfClipped(p, heuristic);
    return heuristic + 10000;
  }
  int _estimateNumVectors(PView *p)
  {
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();
    int heuristic = data->getNumVectors(opt->timeStep);
    heuristic = _estimateIfClipped(p, heuristic);
    return heuristic + 1000;
  }
 public:
  void operator () (PView *p)
  {
    // use adaptive data if available
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();

    if(data->getDirty() || !data->getNumTimeSteps() || !p->getChanged()) return;
    if(!opt->visible || opt->type != PViewOptions::Plot3D) return;

    if(opt->useGenRaise) opt->createGeneralRaise();

    if(opt->rangeType == PViewOptions::Custom){
      opt->tmpMin = opt->customMin;
      opt->tmpMax = opt->customMax;
    }
    else if(opt->rangeType == PViewOptions::PerTimeStep){
      opt->tmpMin = data->getMin(opt->timeStep);
      opt->tmpMax = data->getMax(opt->timeStep);
    }
    else{
      // FIXME: this is not perfect for multi-step adaptive views, as
      // we don't have the correct min/max info for the other steps
      opt->tmpMin = data->getMin();
      opt->tmpMax = data->getMax();
    }

    p->deleteVertexArrays();
    p->va_points = new VertexArray(1, _estimateNumPoints(p));
    p->va_lines = new VertexArray(2, _estimateNumLines(p));
    p->va_triangles = new VertexArray(3, _estimateNumTriangles(p));
    p->va_vectors = new VertexArray(2, _estimateNumVectors(p));

    if(p->normals) delete p->normals;
    p->normals = new smooth_normals(opt->angleSmoothNormals);

    if(opt->smoothNormals) addElementsInArrays(p, true);
    addElementsInArrays(p, false);

    p->va_points->finalize();
    p->va_lines->finalize();
    p->va_triangles->finalize();
    p->va_vectors->finalize();

    Msg::Info("%d vertices in vertex arrays", p->va_points->getNumVertices() + 
              p->va_lines->getNumVertices() + p->va_triangles->getNumVertices() + 
              p->va_vectors->getNumVertices());

    p->setChanged(false);
  }
};

void PView::fillVertexArrays()
{
  initPView init;
  init(this);
}

void PView::fillVertexArray(int length, const char *bytes)
{
  int is = sizeof(int);

  if(length < 2 * is){
    Msg::Error("Too few bytes to create vertex array: %d", length);
    return;
  }
  
  int num; memcpy(&num, &bytes[0], is);
  int type; memcpy(&type, &bytes[is], is);

  // we should also serialize the following info
  //   min, max
  //   time value
  //   bounding box
  
  Msg::Info("Filling vertex array (type %d) in view num %d", type, num);

  PView *view;
  if(num >= 0 && num < (int)list.size()){
    view = PView::list[num];
  }
  else{
    Msg::Info("View num %d does not exist: creating new view");
    view = new PView(new PViewDataRemote);
  }

  switch(type){
  case 1: 
    if(view->va_points) delete view->va_points; 
    view->va_points = new VertexArray(1, 100);
    view->va_points->fromChar(bytes);
    break;
  case 2: 
    if(view->va_lines) delete view->va_lines; 
    view->va_lines = new VertexArray(2, 100);
    view->va_lines->fromChar(bytes);
    break;
  case 3:
    if(view->va_triangles) delete view->va_triangles;
    view->va_triangles = new VertexArray(3, 100);
    view->va_triangles->fromChar(bytes);
    break;
  case 4:
    if(view->va_vectors) delete view->va_vectors;
    view->va_vectors = new VertexArray(2, 100);
    view->va_vectors->fromChar(bytes);
    break;
  default: 
    Msg::Error("Cannot fill vertex array of type %d", type);
    return;
  }

  view->setChanged(false);
  view->getData()->setDirty(false);
}
