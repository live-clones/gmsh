// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <algorithm>
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "onelab.h"
#include "Iso.h"
#include "MEdge.h"
#include "MFace.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "PViewDataRemote.h"
#include "Numeric.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "Context.h"
#include "OpenFile.h"
#include "mathEvaluator.h"
#include "Options.h"
#include "StringUtils.h"
#include "fullMatrix.h"

static void saturate(int nb, double **val, double vmin, double vmax, int i0 = 0,
                     int i1 = 1, int i2 = 2, int i3 = 3, int i4 = 4, int i5 = 5,
                     int i6 = 6, int i7 = 7)
{
  int id[8] = {i0, i1, i2, i3, i4, i5, i6, i7};
  for(int i = 0; i < nb; i++) {
    if(val[id[i]][0] > vmax)
      val[id[i]][0] = vmax;
    else if(val[id[i]][0] < vmin)
      val[id[i]][0] = vmin;
  }
}

static double saturateVector(double *val, int numComp2, double *val2,
                             double min, double max)
{
  double v = ComputeScalarRep(numComp2, val2); // v >= 0
  if(v < min && v > 1e-15) {
    double f = min / v;
    for(int iComp = 0; iComp < numComp2; ++iComp) val2[iComp] *= f;
    val[0] *= f;
    val[1] *= f;
    val[2] *= f;
    return min;
  }
  if(v > max && v > 1e-15) {
    double f = max / v;
    for(int iComp = 0; iComp < numComp2; ++iComp) val2[iComp] *= f;
    val[0] *= f;
    val[1] *= f;
    val[2] *= f;
    return max;
  }
  return v;
}

static SVector3 normal3(double **xyz, int i0 = 0, int i1 = 1, int i2 = 2)
{
  SVector3 t1(xyz[i1][0] - xyz[i0][0], xyz[i1][1] - xyz[i0][1],
              xyz[i1][2] - xyz[i0][2]);
  SVector3 t2(xyz[i2][0] - xyz[i0][0], xyz[i2][1] - xyz[i0][1],
              xyz[i2][2] - xyz[i0][2]);
  SVector3 n = crossprod(t1, t2);
  n.normalize();
  return n;
}

static SVector3 getPointNormal(PView *p, double v)
{
  PViewOptions *opt = p->getOptions();
  SVector3 n(0., 0., 0.);
  if(opt->pointType > 0) {
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

  if(opt->lineType > 0) {
    if(v) {
      // when we draw tapered cylinders, we use the normalized values
      // (between 0 and 1) stored in the first component of the
      // normals to modulate the width
      double d = opt->tmpMax - opt->tmpMin;
      n[0][0] = (v[0] - opt->tmpMin) / (d ? d : 1.);
      n[1][0] = (v[1] - opt->tmpMin) / (d ? d : 1.);
    }
    else {
      // when we don't have values we use maximum width cylinders
      n[0][0] = n[1][0] = 1.;
    }
  }
  else if(computeNormal) {
    SBoundingBox3d bb = p->getData()->getBoundingBox();
    if(bb.min().z() == bb.max().z())
      n[0] = n[1] = SVector3(0., 0., 1.);
    else if(bb.min().y() == bb.max().y())
      n[0] = n[1] = SVector3(0., 1., 0.);
    else if(bb.min().x() == bb.max().x())
      n[0] = n[1] = SVector3(1., 0., 0.);
    else {
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
                              int numNodes, int numComp, double **val,
                              int &numComp2, double **val2)
{
  PViewOptions *opt = p->getOptions();

  // use self by default
  numComp2 = numComp;
  for(int i = 0; i < numNodes; i++)
    for(int j = 0; j < numComp; j++) val2[i][j] = val[i][j];
  opt->externalMin = opt->tmpMin;
  opt->externalMax = opt->tmpMax;

  if(index < 0 || index >= (int)PView::list.size()) return false;

  PView *p2 = PView::list[index];
  PViewData *data2 = p2->getData(true); // use adaptive data if available

  if(iele >= data2->getNumElements(opt->timeStep, ient)) return false;

  if(!data2->skipElement(opt->timeStep, ient, iele) &&
     data2->getNumNodes(opt->timeStep, ient, iele) == numNodes) {
    numComp2 = data2->getNumComponents(opt->timeStep, ient, iele);
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < numComp2; j++)
        data2->getValue(opt->timeStep, ient, iele, i, j, val2[i][j]);
    if(opt->rangeType == PViewOptions::Custom) {
      opt->externalMin = opt->customMin;
      opt->externalMax = opt->customMax;
    }
    else if(opt->rangeType == PViewOptions::PerTimeStep) {
      opt->externalMin = data2->getMin(opt->timeStep);
      opt->externalMax = data2->getMax(opt->timeStep);
    }
    else {
      opt->externalMin = data2->getMin();
      opt->externalMax = data2->getMax();
    }
    return true;
  }
  return false;
}

static void applyGeneralRaise(PView *p, int numNodes, int numComp,
                              double **vals, double **xyz)
{
  PViewOptions *opt = p->getOptions();
  if(!opt->genRaiseEvaluator) return;

  std::vector<double> values(14, 0.), res(3);
  for(int k = 0; k < numNodes; k++) {
    for(int i = 0; i < 3; i++) values[i] = xyz[k][i];
    for(int i = 0; i < std::min(numComp, 9); i++) values[3 + i] = vals[k][i];
    values[12] = p->getOptions()->timeStep;
    values[13] = p->getOptions()->currentTime;
    if(opt->genRaiseEvaluator->eval(values, res))
      for(int i = 0; i < 3; i++) xyz[k][i] += opt->genRaiseFactor * res[i];
  }
}

void changeCoordinates(PView *p, int ient, int iele, int numNodes, int type,
                       int numComp, double **xyz, double **val)
{
  PViewOptions *opt = p->getOptions();

  if(opt->explode != 1.) {
    double barycenter[3] = {0., 0., 0.};
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++) barycenter[j] += xyz[i][j];
    for(int j = 0; j < 3; j++) barycenter[j] /= (double)numNodes;
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++)
        xyz[i][j] = barycenter[j] + opt->explode * (xyz[i][j] - barycenter[j]);
  }

  if(opt->transform[0][0] != 1. || opt->transform[0][1] != 0. ||
     opt->transform[0][2] != 0. || opt->transform[1][0] != 0. ||
     opt->transform[1][1] != 1. || opt->transform[1][2] != 0. ||
     opt->transform[2][0] != 0. || opt->transform[2][1] != 0. ||
     opt->transform[2][2] != 1.) {
    for(int i = 0; i < numNodes; i++) {
      double old[3] = {xyz[i][0], xyz[i][1], xyz[i][2]};
      for(int j = 0; j < 3; j++) {
        xyz[i][j] = 0.;
        for(int k = 0; k < 3; k++) xyz[i][j] += opt->transform[j][k] * old[k];
      }
    }
  }

  if(opt->offset[0] || opt->offset[1] || opt->offset[2]) {
    for(int i = 0; i < numNodes; i++)
      for(int j = 0; j < 3; j++) xyz[i][j] += opt->offset[j];
  }

  if(opt->raise[0] || opt->raise[1] || opt->raise[2]) {
    for(int i = 0; i < numNodes; i++) {
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++) xyz[i][j] += opt->raise[j] * v;
    }
  }

  if(opt->normalRaise &&
     (type == TYPE_LIN || type == TYPE_TRI || type == TYPE_QUA)) {
    SVector3 n;
    if(type == TYPE_LIN) {
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
    for(int i = 0; i < numNodes; i++) {
      double v = ComputeScalarRep(numComp, val[i]);
      for(int j = 0; j < 3; j++) xyz[i][j] += n[j] * opt->normalRaise * v;
    }
  }

  if(numComp == 3 && opt->vectorType == PViewOptions::Displacement) {
    for(int i = 0; i < numNodes; i++) {
      for(int j = 0; j < 3; j++)
        xyz[i][j] += opt->displacementFactor * val[i][j];
    }
  }

  if(opt->useGenRaise) {
    int numComp2;
    double **val2 = new double *[numNodes];
    for(int i = 0; i < numNodes; i++) val2[i] = new double[9];
    getExternalValues(p, opt->viewIndexForGenRaise, ient, iele, numNodes,
                      numComp, val, numComp2, val2);
    applyGeneralRaise(p, numNodes, numComp2, val2, xyz);
    for(int i = 0; i < numNodes; i++) delete[] val2[i];
    delete[] val2;
  }
}

static double evalClipPlane(int clip, double x, double y, double z)
{
  return CTX::instance()->clipPlane[clip][0] * x +
         CTX::instance()->clipPlane[clip][1] * y +
         CTX::instance()->clipPlane[clip][2] * z +
         CTX::instance()->clipPlane[clip][3];
}

static double intersectClipPlane(int clip, int numNodes, double **xyz)
{
  double val = evalClipPlane(clip, xyz[0][0], xyz[0][1], xyz[0][2]);
  for(int i = 1; i < numNodes; i++) {
    if(val * evalClipPlane(clip, xyz[i][0], xyz[i][1], xyz[i][2]) <= 0)
      return 0.; // the element intersects the cut plane
  }
  return val;
}

bool isElementVisible(PViewOptions *opt, int dim, int numNodes, double **xyz)
{
  if(!CTX::instance()->clipWholeElements) return true;
  bool hidden = false;
  for(int clip = 0; clip < 6; clip++) {
    if(opt->clip & (1 << clip)) {
      if(dim < 3 && CTX::instance()->clipOnlyVolume) {}
      else {
        double d = intersectClipPlane(clip, numNodes, xyz);
        if(dim == 3 && CTX::instance()->clipOnlyDrawIntersectingVolume && d) {
          hidden = true;
          break;
        }
        else if(d < 0) {
          hidden = true;
          break;
        }
      }
    }
  }
  return !hidden;
}

static void addOutlinePoint(PView *p, double **xyz, unsigned int color,
                            bool pre, int i0 = 0)
{
  if(pre) return;
  SVector3 n = getPointNormal(p, 1.);
  p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &color, nullptr,
                    true);
}

static void addScalarPoint(PView *p, double **xyz, double **val, bool pre,
                           int i0 = 0, bool unique = false)
{
  if(pre) return;

  PViewOptions *opt = p->getOptions();

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(1, val, vmin, vmax, i0);

  if(val[i0][0] >= vmin && val[i0][0] <= vmax) {
    unsigned int col = opt->getColor(
      val[i0][0], vmin, vmax, false,
      (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
    SVector3 n = getPointNormal(p, val[i0][0]);
    p->va_points->add(&xyz[i0][0], &xyz[i0][1], &xyz[i0][2], &n, &col, nullptr,
                      unique);
  }
}

static void addOutlineLine(PView *p, double **xyz, unsigned int color, bool pre,
                           int i0 = 0, int i1 = 1)
{
  if(pre) return;

  const int in[2] = {i0, i1};
  unsigned int col[2];
  double x[2], y[2], z[2];
  for(int i = 0; i < 2; i++) {
    x[i] = xyz[in[i]][0];
    y[i] = xyz[in[i]][1];
    z[i] = xyz[in[i]][2];
    col[i] = color;
  }
  SVector3 n[2];
  getLineNormal(p, x, y, z, nullptr, n, true);
  p->va_lines->add(x, y, z, n, col, nullptr, true);
}

static void addScalarLine(PView *p, double **xyz, double **val, bool pre,
                          int i0 = 0, int i1 = 1, bool unique = false)
{
  if(pre) return;

  PViewOptions *opt = p->getOptions();

  if(opt->boundary > 0) {
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

  if(opt->intervalsType == PViewOptions::Continuous) {
    SVector3 n[2];
    getLineNormal(p, x, y, z, v, n, true);
    if(val[i0][0] >= vmin && val[i0][0] <= vmax && val[i1][0] >= vmin &&
       val[i1][0] <= vmax) {
      unsigned int col[2];
      for(int i = 0; i < 2; i++) col[i] = opt->getColor(v[i], vmin, vmax);
      p->va_lines->add(x, y, z, n, col, nullptr, unique);
    }
    else {
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      if(nb == 2) {
        unsigned int col[2];
        for(int i = 0; i < 2; i++) col[i] = opt->getColor(v2[i], vmin, vmax);
        p->va_lines->add(x2, y2, z2, n, col, nullptr, unique);
      }
    }
  }

  if(opt->intervalsType == PViewOptions::Discrete) {
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double min = opt->getScaleValue(k, opt->nbIso + 1, vmin, vmax);
      double max = opt->getScaleValue(k + 1, opt->nbIso + 1, vmin, vmax);
      double x2[2], y2[2], z2[2], v2[2];
      int nb = CutLine(x, y, z, v, min, max, x2, y2, z2, v2);
      if(nb == 2) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[2] = {color, color};
        SVector3 n[2];
        getLineNormal(p, x2, y2, z2, v2, n, true);
        p->va_lines->add(x2, y2, z2, n, col, nullptr, unique);
      }
      if(vmin == vmax) break;
    }
  }

  if(opt->intervalsType == PViewOptions::Iso) {
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double iso = opt->getScaleValue(k, opt->nbIso, vmin, vmax);
      double x2[1], y2[1], z2[1];
      int nb = IsoLine(x, y, z, v, iso, x2, y2, z2);
      if(nb == 1) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        SVector3 n = getPointNormal(p, iso);
        p->va_points->add(x2, y2, z2, &n, &color, nullptr, unique);
      }
      if(vmin == vmax) break;
    }
  }
}

static void addOutlineTriangle(PView *p, double **xyz, unsigned int color,
                               bool pre, int i0 = 0, int i1 = 1, int i2 = 2)
{
  PViewOptions *opt = p->getOptions();

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  for(int i = 0; i < 3; i++) {
    double x[2] = {xyz[il[i][0]][0], xyz[il[i][1]][0]};
    double y[2] = {xyz[il[i][0]][1], xyz[il[i][1]][1]};
    double z[2] = {xyz[il[i][0]][2], xyz[il[i][1]][2]};
    SVector3 n[2] = {nfac, nfac};
    unsigned int col[2] = {color, color};
    if(opt->smoothNormals) {
      for(int j = 0; j < 2; j++) {
        if(pre)
          p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
        else
          p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
    }
    getLineNormal(p, x, y, z, nullptr, n, false);
    if(!pre) p->va_lines->add(x, y, z, n, col, nullptr, true);
  }
}

static void addScalarTriangle(PView *p, double **xyz, double **val, bool pre,
                              int i0 = 0, int i1 = 1, int i2 = 2,
                              bool unique = false, bool skin = false)
{
  PViewOptions *opt = p->getOptions();

  const int il[3][2] = {{i0, i1}, {i1, i2}, {i2, i0}};

  if(opt->boundary > 0) {
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

  if(opt->intervalsType == PViewOptions::Continuous) {
    if(val[i0][0] >= vmin && val[i0][0] <= vmax && val[i1][0] >= vmin &&
       val[i1][0] <= vmax && val[i2][0] >= vmin && val[i2][0] <= vmax) {
      SVector3 n[3] = {nfac, nfac, nfac};
      unsigned int col[3];
      for(int i = 0; i < 3; i++) {
        if(opt->smoothNormals) {
          if(pre)
            p->normals->add(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
          else
            p->normals->get(x[i], y[i], z[i], n[i][0], n[i][1], n[i][2]);
        }
        col[i] = opt->getColor(v[i], vmin, vmax);
      }
      if(!pre) p->va_triangles->add(x, y, z, n, col, nullptr, unique, skin);
    }
    else {
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, vmin, vmax, x2, y2, z2, v2);
      if(nb >= 3) {
        for(int j = 2; j < nb; j++) {
          double x3[3] = {x2[0], x2[j - 1], x2[j]};
          double y3[3] = {y2[0], y2[j - 1], y2[j]};
          double z3[3] = {z2[0], z2[j - 1], z2[j]};
          double v3[3] = {v2[0], v2[j - 1], v2[j]};
          SVector3 n[3] = {nfac, nfac, nfac};
          unsigned int col[3];
          for(int i = 0; i < 3; i++) {
            if(opt->smoothNormals) {
              if(pre)
                p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
              else
                p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
            }
            col[i] = opt->getColor(v3[i], vmin, vmax);
          }
          if(!pre)
            p->va_triangles->add(x3, y3, z3, n, col, nullptr, unique, skin);
        }
      }
    }
  }

  if(opt->intervalsType == PViewOptions::Discrete) {
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double min = opt->getScaleValue(k, opt->nbIso + 1, vmin, vmax);
      double max = opt->getScaleValue(k + 1, opt->nbIso + 1, vmin, vmax);
      double x2[10], y2[10], z2[10], v2[10];
      int nb = CutTriangle(x, y, z, v, min, max, x2, y2, z2, v2);
      if(nb >= 3) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[3] = {color, color, color};
        for(int j = 2; j < nb; j++) {
          double x3[3] = {x2[0], x2[j - 1], x2[j]};
          double y3[3] = {y2[0], y2[j - 1], y2[j]};
          double z3[3] = {z2[0], z2[j - 1], z2[j]};
          SVector3 n[3] = {nfac, nfac, nfac};
          if(opt->smoothNormals) {
            for(int i = 0; i < 3; i++) {
              if(pre)
                p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
              else
                p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
            }
          }
          if(!pre)
            p->va_triangles->add(x3, y3, z3, n, col, nullptr, unique, skin);
        }
      }
      if(vmin == vmax) break;
    }
  }

  if(opt->intervalsType == PViewOptions::Iso) {
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double iso = opt->getScaleValue(k, opt->nbIso, vmin, vmax);
      double x2[3], y2[3], z2[3];
      int nb = IsoTriangle(x, y, z, v, iso, x2, y2, z2);
      if(nb == 2) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[2] = {color, color};
        SVector3 n[2] = {nfac, nfac};
        if(opt->smoothNormals) {
          for(int i = 0; i < 2; i++) {
            if(pre)
              p->normals->add(x2[i], y2[i], z2[i], n[i][0], n[i][1], n[i][2]);
            else
              p->normals->get(x2[i], y2[i], z2[i], n[i][0], n[i][1], n[i][2]);
          }
        }
        double v[2] = {iso, iso};
        getLineNormal(p, x, y, z, v, n, false);
        if(!pre) p->va_lines->add(x2, y2, z2, n, col, nullptr, unique);
      }
      if(vmin == vmax) break;
    }
  }
}

static void addOutlineQuadrangle(PView *p, double **xyz, unsigned int color,
                                 bool pre, int i0 = 0, int i1 = 1, int i2 = 2,
                                 int i3 = 3)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};

  SVector3 nfac = normal3(xyz, i0, i1, i2);

  for(int i = 0; i < 4; i++) {
    double x[2] = {xyz[il[i][0]][0], xyz[il[i][1]][0]};
    double y[2] = {xyz[il[i][0]][1], xyz[il[i][1]][1]};
    double z[2] = {xyz[il[i][0]][2], xyz[il[i][1]][2]};
    SVector3 n[2] = {nfac, nfac};
    unsigned int col[2] = {color, color};
    if(opt->smoothNormals) {
      for(int j = 0; j < 2; j++) {
        if(pre)
          p->normals->add(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
        else
          p->normals->get(x[j], y[j], z[j], n[j][0], n[j][1], n[j][2]);
      }
    }
    getLineNormal(p, x, y, z, nullptr, n, false);
    if(!pre) p->va_lines->add(x, y, z, n, col, nullptr, true);
  }
}

static void addScalarQuadrangle(PView *p, double **xyz, double **val, bool pre,
                                int i0 = 0, int i1 = 1, int i2 = 2, int i3 = 3,
                                bool unique = false)
{
  PViewOptions *opt = p->getOptions();

  const int il[4][2] = {{i0, i1}, {i1, i2}, {i2, i3}, {i3, i0}};
  const int it[2][3] = {{i0, i1, i2}, {i0, i2, i3}};

  if(opt->boundary > 0) {
    opt->boundary--;
    for(int i = 0; i < 4; i++)
      addScalarLine(p, xyz, val, pre, il[i][0], il[i][1], true);
    opt->boundary++;
    return;
  }

  for(int i = 0; i < 2; i++)
    addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], unique);
}

static void addOutlinePolygon(PView *p, double **xyz, unsigned int color,
                              bool pre, int numNodes)
{
  for(int i = 0; i < numNodes / 3; i++)
    addOutlineTriangle(p, xyz, color, pre, 3 * i, 3 * i + 1, 3 * i + 2);
}

static void addScalarPolygon(PView *p, double **xyz, double **val, bool pre,
                             int numNodes)
{
  PViewOptions *opt = p->getOptions();

  if(opt->boundary > 0) {
    const int il[3][2] = {{0, 1}, {1, 2}, {2, 0}};
    std::map<MEdge, int, MEdgeLessThan> edges;
    std::vector<MVertex *> verts;
    verts.reserve(numNodes);
    for(int i = 0; i < numNodes; i++)
      verts.push_back(new MVertex(xyz[i][0], xyz[i][1], xyz[i][2]));
    for(int i = 0; i < numNodes / 3; i++) {
      for(int j = 0; j < 3; j++) {
        MEdge ed(verts[3 * i + il[j][0]], verts[3 * i + il[j][1]]);
        std::map<MEdge, int, MEdgeLessThan>::iterator ite;
        for(ite = edges.begin(); ite != edges.end(); ite++)
          if((*ite).first == ed) break;
        if(ite == edges.end())
          edges[ed] = 100 * i + j;
        else
          edges.erase(ite);
      }
    }

    opt->boundary--;
    for(auto ite = edges.begin(); ite != edges.end(); ite++) {
      int i = (int)(*ite).second / 100;
      int j = (*ite).second % 100;
      if(j < 3)
        addScalarLine(p, xyz, val, pre, 3 * i + il[j][0], 3 * i + il[j][0],
                      true);
    }
    opt->boundary++;

    for(int i = 0; i < numNodes; i++) delete verts[i];
    return;
  }

  for(int i = 0; i < numNodes / 3; i++)
    addScalarTriangle(p, xyz, val, pre, 3 * i, 3 * i + 1, 3 * i + 2);
}

static void addOutlineTetrahedron(PView *p, double **xyz, unsigned int color,
                                  bool pre)
{
  const int it[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

static void addScalarTetrahedron(PView *p, double **xyz, double **val, bool pre,
                                 int i0 = 0, int i1 = 1, int i2 = 2, int i3 = 3)
{
  PViewOptions *opt = p->getOptions();

  const int it[4][3] = {{i0, i2, i1}, {i0, i1, i3}, {i0, i3, i2}, {i3, i1, i2}};

  if(opt->boundary > 0 || opt->intervalsType == PViewOptions::Continuous ||
     opt->intervalsType == PViewOptions::Discrete) {
    bool skin = (opt->boundary > 0) ? false : opt->drawSkinOnly;
    opt->boundary--;
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true,
                        skin);
    opt->boundary++;
    return;
  }

  double vmin = opt->tmpMin, vmax = opt->tmpMax;
  if(opt->saturateValues) saturate(4, val, vmin, vmax, i0, i1, i2, i3);

  double x[4] = {xyz[i0][0], xyz[i1][0], xyz[i2][0], xyz[i3][0]};
  double y[4] = {xyz[i0][1], xyz[i1][1], xyz[i2][1], xyz[i3][1]};
  double z[4] = {xyz[i0][2], xyz[i1][2], xyz[i2][2], xyz[i3][2]};
  double v[4] = {val[i0][0], val[i1][0], val[i2][0], val[i3][0]};

  if(opt->intervalsType == PViewOptions::Iso) {
    for(int k = 0; k < opt->nbIso; k++) {
      if(vmin == vmax) k = opt->nbIso / 2;
      double iso = opt->getScaleValue(k, opt->nbIso, vmin, vmax);
      double x2[6], y2[6], z2[6], nn[3];
      int nb = IsoSimplex(x, y, z, v, iso, x2, y2, z2, nn);
      if(nb >= 3) {
        unsigned int color = opt->getColor(k, opt->nbIso);
        unsigned int col[3] = {color, color, color};
        for(int j = 2; j < nb; j++) {
          double x3[3] = {x2[0], x2[j - 1], x2[j]};
          double y3[3] = {y2[0], y2[j - 1], y2[j]};
          double z3[3] = {z2[0], z2[j - 1], z2[j]};
          SVector3 n[3];
          for(int i = 0; i < 3; i++) {
            n[i][0] = nn[0];
            n[i][1] = nn[1];
            n[i][2] = nn[2];
            if(opt->smoothNormals) {
              if(pre)
                p->normals->add(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
              else
                p->normals->get(x3[i], y3[i], z3[i], n[i][0], n[i][1], n[i][2]);
            }
          }
          if(!pre)
            p->va_triangles->add(x3, y3, z3, n, col, nullptr, false, false);
        }
      }
      if(vmin == vmax) break;
    }
  }
}

static void addOutlineHexahedron(PView *p, double **xyz, unsigned int color,
                                 bool pre)
{
  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
                        {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};

  for(int i = 0; i < 6; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], iq[i][2],
                         iq[i][3]);
}

static void addScalarHexahedron(PView *p, double **xyz, double **val, bool pre)
{
  PViewOptions *opt = p->getOptions();

  const int iq[6][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {0, 4, 7, 3},
                        {1, 2, 6, 5}, {2, 3, 7, 6}, {4, 5, 6, 7}};
  const int is[6][4] = {{0, 1, 3, 7}, {0, 4, 1, 7}, {1, 4, 5, 7},
                        {1, 2, 3, 7}, {1, 6, 2, 7}, {1, 5, 6, 7}};

  if(opt->boundary > 0) {
    opt->boundary--;
    for(int i = 0; i < 6; i++)
      addScalarQuadrangle(p, xyz, val, pre, iq[i][0], iq[i][1], iq[i][2],
                          iq[i][3], true);
    opt->boundary++;
    return;
  }

  for(int i = 0; i < 6; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2],
                         is[i][3]);
}

static void addOutlinePrism(PView *p, double **xyz, unsigned int color,
                            bool pre)
{
  const int iq[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
  const int it[2][3] = {{0, 2, 1}, {3, 4, 5}};

  for(int i = 0; i < 3; i++)
    addOutlineQuadrangle(p, xyz, color, pre, iq[i][0], iq[i][1], iq[i][2],
                         iq[i][3]);
  for(int i = 0; i < 2; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

static void addScalarPrism(PView *p, double **xyz, double **val, bool pre)
{
  PViewOptions *opt = p->getOptions();
  const int iq[3][4] = {{0, 1, 4, 3}, {0, 3, 5, 2}, {1, 2, 5, 4}};
  const int it[2][3] = {{0, 2, 1}, {3, 4, 5}};
  const int is[3][4] = {{0, 1, 2, 4}, {0, 4, 2, 5}, {0, 3, 4, 5}};

  if(opt->boundary > 0) {
    opt->boundary--;
    for(int i = 0; i < 3; i++)
      addScalarQuadrangle(p, xyz, val, pre, iq[i][0], iq[i][1], iq[i][2],
                          iq[i][3], true);
    for(int i = 0; i < 2; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
    opt->boundary++;
    return;
  }

  for(int i = 0; i < 3; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2],
                         is[i][3]);
}

static void addOutlinePyramid(PView *p, double **xyz, unsigned int color,
                              bool pre)
{
  const int it[4][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};

  addOutlineQuadrangle(p, xyz, color, pre, 0, 3, 2, 1);
  for(int i = 0; i < 4; i++)
    addOutlineTriangle(p, xyz, color, pre, it[i][0], it[i][1], it[i][2]);
}

static void addScalarPyramid(PView *p, double **xyz, double **val, bool pre)
{
  PViewOptions *opt = p->getOptions();

  const int it[4][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4}, {2, 3, 4}};
  const int is[2][4] = {{0, 1, 3, 4}, {1, 2, 3, 4}};

  if(opt->boundary > 0) {
    opt->boundary--;
    addScalarQuadrangle(p, xyz, val, pre, 0, 3, 2, 1, true);
    for(int i = 0; i < 4; i++)
      addScalarTriangle(p, xyz, val, pre, it[i][0], it[i][1], it[i][2], true);
    opt->boundary++;
    return;
  }

  for(int i = 0; i < 2; i++)
    addScalarTetrahedron(p, xyz, val, pre, is[i][0], is[i][1], is[i][2],
                         is[i][3]);
}

static void addOutlineTrihedron(PView *p, double **xyz, unsigned int color,
                                bool pre)
{
  addOutlineQuadrangle(p, xyz, color, pre, 0, 1, 2, 3);
}

static void addScalarTrihedron(PView *p, double **xyz, double **val, bool pre,
                               int i0 = 0, int i1 = 1, int i2 = 2, int i3 = 3,
                               bool unique = false)
{
  addScalarQuadrangle(p, xyz, val, pre, i0, i1, i2, i3, unique);
}

static void addOutlinePolyhedron(PView *p, double **xyz, unsigned int color,
                                 bool pre, int numNodes)
{
  // FIXME: this code is horribly slow
  const int it[4][3] = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2}};
  std::map<MFace, int, MFaceLessThan> triFaces;
  std::vector<MVertex *> verts;
  verts.reserve(numNodes);
  for(int i = 0; i < numNodes; i++)
    verts.push_back(new MVertex(xyz[i][0], xyz[i][1], xyz[i][2]));
  for(int i = 0; i < numNodes / 4; i++) {
    for(int j = 0; j < 4; j++) {
      MFace f(verts[4 * i + it[j][0]], verts[4 * i + it[j][1]],
              verts[4 * i + it[j][2]]);
      std::map<MFace, int, MFaceLessThan>::iterator ite;
      for(ite = triFaces.begin(); ite != triFaces.end(); ite++)
        if((*ite).first == f) break;
      if(ite == triFaces.end())
        triFaces[f] = 100 * i + j;
      else
        triFaces.erase(ite);
    }
  }
  for(auto ite = triFaces.begin(); ite != triFaces.end(); ite++) {
    int i = (int)(*ite).second / 100;
    int j = (*ite).second % 100;
    if(j < 4)
      addOutlineTriangle(p, xyz, color, pre, 4 * i + it[j][0], 4 * i + it[j][1],
                         4 * i + it[j][2]);
  }
  for(int i = 0; i < numNodes; i++) delete verts[i];
}

static void addScalarPolyhedron(PView *p, double **xyz, double **val, bool pre,
                                int numNodes)
{
  PViewOptions *opt = p->getOptions();

  if(opt->boundary > 0) { return; }

  for(int i = 0; i < numNodes / 4; i++)
    addScalarTetrahedron(p, xyz, val, pre, 4 * i, 4 * i + 1, 4 * i + 2,
                         4 * i + 3);
}

static void addOutlineElement(PView *p, int type, double **xyz, bool pre,
                              int numNodes)
{
  PViewOptions *opt = p->getOptions();
  switch(type) {
  case TYPE_PNT: addOutlinePoint(p, xyz, opt->color.point, pre); break;
  case TYPE_LIN: addOutlineLine(p, xyz, opt->color.line, pre); break;
  case TYPE_TRI: addOutlineTriangle(p, xyz, opt->color.triangle, pre); break;
  case TYPE_QUA:
    addOutlineQuadrangle(p, xyz, opt->color.quadrangle, pre);
    break;
  case TYPE_POLYG:
    addOutlinePolygon(p, xyz, opt->color.quadrangle, pre, numNodes);
    break;
  case TYPE_TET:
    addOutlineTetrahedron(p, xyz, opt->color.tetrahedron, pre);
    break;
  case TYPE_HEX:
    addOutlineHexahedron(p, xyz, opt->color.hexahedron, pre);
    break;
  case TYPE_PRI: addOutlinePrism(p, xyz, opt->color.prism, pre); break;
  case TYPE_PYR: addOutlinePyramid(p, xyz, opt->color.pyramid, pre); break;
  case TYPE_TRIH: addOutlineTrihedron(p, xyz, opt->color.pyramid, pre); break;
  case TYPE_POLYH:
    addOutlinePolyhedron(p, xyz, opt->color.pyramid, pre, numNodes);
    break;
  }
}

static void addScalarElement(PView *p, int type, double **xyz, double **val,
                             bool pre, int numNodes)
{
  switch(type) {
  case TYPE_PNT: addScalarPoint(p, xyz, val, pre); break;
  case TYPE_LIN: addScalarLine(p, xyz, val, pre); break;
  case TYPE_TRI: addScalarTriangle(p, xyz, val, pre); break;
  case TYPE_QUA: addScalarQuadrangle(p, xyz, val, pre); break;
  case TYPE_POLYG: addScalarPolygon(p, xyz, val, pre, numNodes); break;
  case TYPE_TET: addScalarTetrahedron(p, xyz, val, pre); break;
  case TYPE_HEX: addScalarHexahedron(p, xyz, val, pre); break;
  case TYPE_PRI: addScalarPrism(p, xyz, val, pre); break;
  case TYPE_PYR: addScalarPyramid(p, xyz, val, pre); break;
  case TYPE_TRIH: addScalarTrihedron(p, xyz, val, pre); break;
  case TYPE_POLYH: addScalarPolyhedron(p, xyz, val, pre, numNodes); break;
  }
}

static void addVectorElement(PView *p, int ient, int iele, int numNodes,
                             int type, double **xyz, double **val, bool pre)
{
  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  int numComp2;
  double **val2 = new double *[numNodes];
  for(int i = 0; i < numNodes; i++) val2[i] = new double[9];
  getExternalValues(p, opt->externalViewIndex, ient, iele, numNodes, 3, val,
                    numComp2, val2);

  if(opt->vectorType == PViewOptions::Displacement) {
    for(int i = 0; i < numNodes; i++)
      val2[i][0] = ComputeScalarRep(numComp2, val2[i]);

    // add scalar element with correct min/max
    double min = opt->tmpMin, max = opt->tmpMax;
    opt->tmpMin = opt->externalMin;
    opt->tmpMax = opt->externalMax;
    addScalarElement(p, type, xyz, val2, pre, numNodes);
    opt->tmpMin = min;
    opt->tmpMax = max;

    // add point trajectories
    // FIXME: this should be optional
    if(!pre && numNodes == 1 && opt->timeStep > 0 && opt->lineWidth) {
      for(int ts = 0; ts < opt->timeStep; ts++) {
        if(!data->hasTimeStep(ts)) continue;
        int numComp = data->getNumComponents(ts, ient, iele);
        double xyz0[3], dxyz[3][2] = {{0., 0.}, {0., 0.}, {0., 0.}};
        data->getNode(ts, ient, iele, 0, xyz0[0], xyz0[1], xyz0[2]);
        for(int j = 0; j < 3; j++) {
          int comp = opt->forceNumComponents ? opt->componentMap[j] : j;
          if(comp >= 0 && comp < numComp) {
            data->getValue(ts, ient, iele, 0, comp, dxyz[j][0]);
            data->getValue(ts + 1, ient, iele, 0, comp, dxyz[j][1]);
          }
        }
        unsigned int col[2];
        double norm[2];
        for(int i = 0; i < 2; i++) {
          norm[i] = sqrt(dxyz[0][i] * dxyz[0][i] + dxyz[1][i] * dxyz[1][i] +
                         dxyz[2][i] * dxyz[2][i]);
          col[i] = opt->getColor(norm[i], opt->tmpMin, opt->tmpMax);
        }
        for(int j = 0; j < 3; j++) {
          dxyz[j][0] = xyz0[j] + dxyz[j][0] * opt->displacementFactor;
          dxyz[j][1] = xyz0[j] + dxyz[j][1] * opt->displacementFactor;
        }
        SVector3 n[2];
        getLineNormal(p, dxyz[0], dxyz[1], dxyz[2], norm, n, true);
        p->va_lines->add(dxyz[0], dxyz[1], dxyz[2], n, col, nullptr, false);
      }
    }
    for(int i = 0; i < numNodes; i++) delete[] val2[i];
    delete[] val2;
    return;
  }

  if(pre) {
    for(int i = 0; i < numNodes; i++) delete[] val2[i];
    delete[] val2;
    return;
  }

  if(opt->glyphLocation == PViewOptions::Vertex) {
    for(int i = 0; i < numNodes; i++) {
      double v2 = opt->saturateValues ?
                    saturateVector(val[i], numComp2, val2[i], opt->externalMin,
                                   opt->externalMax) :
                    ComputeScalarRep(numComp2, val2[i]);
      if(v2 >= opt->externalMin && v2 <= opt->externalMax) {
        unsigned int color = opt->getColor(
          v2, opt->externalMin, opt->externalMax, false,
          (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
        unsigned int col[2] = {color, color};
        double dxyz[3][2];
        for(int j = 0; j < 3; j++) {
          dxyz[j][0] = xyz[i][j];
          dxyz[j][1] = val[i][j];
        }
        p->va_vectors->add(dxyz[0], dxyz[1], dxyz[2], nullptr, col, nullptr,
                           false);
      }
    }
  }

  if(opt->glyphLocation == PViewOptions::COG) {
    // compute value by averaging the norm and averaging the directions (this
    // allows to preserve the min/max)
    SPoint3 pc(0., 0., 0.);
    double d[3] = {0., 0., 0.};
    double v2 = 0.;
    for(int i = 0; i < numNodes; i++) {
      pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
      v2 += opt->saturateValues ?
              saturateVector(val[i], numComp2, val2[i], opt->externalMin,
                             opt->externalMax) :
              ComputeScalarRep(numComp2, val2[i]);
      for(int j = 0; j < 3; j++) d[j] += val[i][j];
    }
    pc /= (double)numNodes;
    v2 /= (double)numNodes;
    norme(d);
    for(int i = 0; i < 3; i++) d[i] *= v2;

    // need tolerance since we compare computed results (the average)
    // instead of the raw data used to compute bounds
    if(v2 >= opt->externalMin * (1. - 1.e-15) &&
       v2 <= opt->externalMax * (1. + 1.e-15)) {
      unsigned int color = opt->getColor(
        v2, opt->externalMin, opt->externalMax, false,
        (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
      unsigned int col[2] = {color, color};
      double dxyz[3][2];
      for(int i = 0; i < 3; i++) {
        dxyz[i][0] = pc[i];
        dxyz[i][1] = d[i];
      }
      p->va_vectors->add(dxyz[0], dxyz[1], dxyz[2], nullptr, col, nullptr,
                         false);
    }
  }
  for(int i = 0; i < numNodes; i++) delete[] val2[i];
  delete[] val2;
}

static void addTriangle(PView *p, PViewOptions *opt, double *x0, double *x1,
                        double *x2, SPoint3 &xx, double val)
{
  unsigned int color = opt->getColor(
    val, opt->tmpMin, opt->tmpMax, false,
    (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);

  SVector3 a(x1[0] - x0[0], x1[1] - x0[1], x1[2] - x0[2]);
  SVector3 b(x2[0] - x0[0], x2[1] - x0[1], x2[2] - x0[2]);
  SVector3 c(xx.x() - x0[0], xx.y() - x0[1], xx.z() - x0[2]);
  SVector3 N = crossprod(a, b);
  unsigned int col[3] = {color, color, color};
  N.normalize();
  if(dot(c, N) > 0) {
    double XX[3] = {x0[0], x1[0], x2[0]};
    double YY[3] = {x0[1], x1[1], x2[1]};
    double ZZ[3] = {x0[2], x1[2], x2[2]};
    SVector3 NN[3] = {N, N, N};
    p->va_triangles->add(XX, YY, ZZ, NN, col, nullptr, false);
  }
  else {
    double XX[3] = {x1[0], x0[0], x2[0]};
    double YY[3] = {x1[1], x0[1], x2[1]};
    double ZZ[3] = {x1[2], x0[2], x2[2]};
    SVector3 NN[3] = {-N, -N, -N};
    p->va_triangles->add(XX, YY, ZZ, NN, col, nullptr, false);
  }
}

static void addTensorElement(PView *p, int iEnt, int iEle, int numNodes,
                             int type, double **xyz, double **val, bool pre)
{
  PViewOptions *opt = p->getOptions();
  fullMatrix<double> tensor(3, 3);
  fullVector<double> S(3), imS(3);
  fullMatrix<double> leftV(3, 3), rightV(3, 3);

  if(opt->tensorType == PViewOptions::VonMises) {
    for(int i = 0; i < numNodes; i++) val[i][0] = ComputeVonMises(val[i]);
    addScalarElement(p, type, xyz, val, pre, numNodes);
  }
  else if(opt->tensorType == PViewOptions::FrameVectors) {
    if(opt->glyphLocation == PViewOptions::Vertex) {

      double **vval = new double *[numNodes];
      for(int j = 0; j < numNodes; j++) vval[j] = new double[3];

      // Plot six vectors to visualize a frame
      for(int i = 0; i < 3; i++) { // for each branch
        for(int d = 0; d < 2; d++) { // for each direction
          for(int j = 0; j < numNodes; j++) { // for each node
            for(int k = 0; k < 3; k++) { // for each vector component
              vval[j][k] = (2*d-1) * val[j][3*i+k];
            }
          }
          addVectorElement(p, iEnt, iEle, numNodes, type, xyz, vval, pre);
        }
      }
    }
  }
  else if(opt->tensorType == PViewOptions::Frame) {
    if(opt->glyphLocation == PViewOptions::Vertex) {
      for(int i = 0; i < numNodes; i++) {
        double d0[3], d1[3], d2[3];
        double nrm = sqrt(val[i][0] * val[i][0] + val[i][1] * val[i][1] +
                          val[i][2] * val[i][2]);

        for(int j = 0; j < 3; j++) {
          d0[j] = opt->displacementFactor * val[i][j + 0 * 3] / nrm;
          d1[j] = opt->displacementFactor * val[i][j + 1 * 3] / nrm;
          d2[j] = opt->displacementFactor * val[i][j + 2 * 3] / nrm;
        }
        double x = xyz[i][0];
        double y = xyz[i][1];
        double z = xyz[i][2];

        SPoint3 xx(x, y, z);
        double x0[3] = {x + d0[0] + d1[0] + d2[0], y + d0[1] + d1[1] + d2[1],
                        z + d0[2] + d1[2] + d2[2]};
        double x1[3] = {x - d0[0] + d1[0] + d2[0], y - d0[1] + d1[1] + d2[1],
                        z - d0[2] + d1[2] + d2[2]};
        double x2[3] = {x - d0[0] - d1[0] + d2[0], y - d0[1] - d1[1] + d2[1],
                        z - d0[2] - d1[2] + d2[2]};
        double x3[3] = {x + d0[0] - d1[0] + d2[0], y + d0[1] - d1[1] + d2[1],
                        z + d0[2] - d1[2] + d2[2]};

        double x4[3] = {x + d0[0] + d1[0] - d2[0], y + d0[1] + d1[1] - d2[1],
                        z + d0[2] + d1[2] - d2[2]};
        double x5[3] = {x - d0[0] + d1[0] - d2[0], y - d0[1] + d1[1] - d2[1],
                        z - d0[2] + d1[2] - d2[2]};
        double x6[3] = {x - d0[0] - d1[0] - d2[0], y - d0[1] - d1[1] - d2[1],
                        z - d0[2] - d1[2] - d2[2]};
        double x7[3] = {x + d0[0] - d1[0] - d2[0], y + d0[1] - d1[1] - d2[1],
                        z + d0[2] - d1[2] - d2[2]};

        if((nrm > opt->tmpMin && opt->tmpMax) || opt->saturateValues) {
          addTriangle(p, opt, x0, x1, x2, xx, nrm);
          addTriangle(p, opt, x2, x3, x0, xx, nrm);
          addTriangle(p, opt, x4, x7, x6, xx, nrm);
          addTriangle(p, opt, x6, x5, x4, xx, nrm);
          addTriangle(p, opt, x0, x3, x7, xx, nrm);
          addTriangle(p, opt, x7, x4, x0, xx, nrm);
          addTriangle(p, opt, x1, x5, x6, xx, nrm);
          addTriangle(p, opt, x6, x2, x1, xx, nrm);
          addTriangle(p, opt, x0, x4, x5, xx, nrm);
          addTriangle(p, opt, x5, x1, x0, xx, nrm);
          addTriangle(p, opt, x3, x2, x6, xx, nrm);
          addTriangle(p, opt, x6, x7, x3, xx, nrm);
        }
      }
    }
  }
  else if(opt->tensorType == PViewOptions::Ellipse ||
          opt->tensorType == PViewOptions::Ellipsoid ||
	  opt->tensorType == PViewOptions::Frame) {
    if(opt->glyphLocation == PViewOptions::Vertex) {
      double vval[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
      for(int i = 0; i < numNodes; i++) {
	if (opt->tensorType == PViewOptions::Frame) {
	  SVector3 v0 (val[i][0],val[i][3],val[i][6]);
	  SVector3 v1 (val[i][1],val[i][4],val[i][7]);
	  SVector3 v2 (val[i][2],val[i][5],val[i][8]);
	  S(0) = v0.norm();
	  S(1) = v1.norm();
	  S(2) = v2.norm();
	  for(int k = 0; k < 3; k++) vval[k][0] = xyz[i][k];
	  vval[0][1] = v0.x();
	  vval[0][2] = v0.y();
	  vval[0][3] = v0.z();
	  vval[1][1] = v1.x();
	  vval[1][2] = v1.y();
	  vval[1][3] = v1.z();
	  vval[2][1] = v2.x();
	  vval[2][2] = v2.y();
	  vval[2][3] = v2.z();
	}
	else {
	  for(int j = 0; j < 3; j++) {
	    tensor(j, 0) = val[i][0 + j * 3];
	    tensor(j, 1) = val[i][1 + j * 3];
	    tensor(j, 2) = val[i][2 + j * 3];
	  }	  
	  tensor.eig(S, imS, leftV, rightV, false);
	  for(int k = 0; k < 3; k++) {
	    vval[k][0] = xyz[i][k];
	    for(int j = 0; j < 3; j++) { vval[k][j + 1] = rightV(k, j) * S(j); }
	  }
	}
	
	//	double lmax = std::max(S(0), std::max(S(1), S(2)));
	//	double lmin = std::min(S(0), std::min(S(1), S(2)));
	double det = S(0)*S(1)*S(2);

	printf("%12.5E %12.5E %12.5E \n",det,opt->tmpMin, opt->tmpMax);
	
        unsigned int color = opt->getColor(
          det, opt->tmpMin, opt->tmpMax, false,
          (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
        unsigned int col[4] = {color, color, color, color};
        p->va_ellipses->add(vval[0], vval[1], vval[2], nullptr, col, nullptr,
                            false);
      }
    }
    else if(opt->glyphLocation == PViewOptions::COG) {
      double vval[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
      for(int i = 0; i < numNodes; i++) {
        for(int j = 0; j < 3; j++) {
          tensor(j, 0) = val[i][0 + j * 3];
          tensor(j, 1) = val[i][1 + j * 3];
          tensor(j, 2) = val[i][2 + j * 3];
        }
        tensor.eig(S, imS, leftV, rightV, false);
        for(int j = 0; j < 3; j++) {
          vval[0][j + 1] += rightV(0, j) * S(j) / numNodes;
          vval[1][j + 1] += rightV(1, j) * S(j) / numNodes;
          vval[2][j + 1] += rightV(2, j) * S(j) / numNodes;
        }
        vval[0][0] += xyz[i][0] / numNodes;
        vval[1][0] += xyz[i][1] / numNodes;
        vval[2][0] += xyz[i][2] / numNodes;
      }
      double lmax = std::max(S(0), std::max(S(1), S(2)));
      unsigned int color = opt->getColor(
        lmax, opt->tmpMin, opt->tmpMax, false,
        (opt->intervalsType == PViewOptions::Discrete) ? opt->nbIso : -1);
      unsigned int col[4] = {color, color, color, color};
      p->va_ellipses->add(vval[0], vval[1], vval[2], nullptr, col, nullptr,
                          false);
    }
  }
  else {
    double **vval[3] = {new double *[numNodes], new double *[numNodes],
                        new double *[numNodes]};
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < numNodes; j++) vval[i][j] = new double[3];
    for(int i = 0; i < numNodes; i++) {
      for(int j = 0; j < 3; j++) {
        tensor(j, 0) = val[i][0 + j * 3];
        tensor(j, 1) = val[i][1 + j * 3];
        tensor(j, 2) = val[i][2 + j * 3];
      }
      tensor.eig(S, imS, leftV, rightV,
                 opt->tensorType != PViewOptions::EigenVectors);
      if(PViewOptions::MinEigenValue == opt->tensorType)
        val[i][0] = S(0);
      else if(PViewOptions::MaxEigenValue == opt->tensorType)
        val[i][0] = S(2);
      else if(PViewOptions::EigenVectors == opt->tensorType) {
        for(int j = 0; j < 3; j++) {
          vval[0][i][j] = rightV(j, 0) * S(0);
          vval[1][i][j] = rightV(j, 1) * S(1);
          vval[2][i][j] = rightV(j, 2) * S(2);
        }
      }
    }

    if(PViewOptions::EigenVectors == opt->tensorType) {
      addVectorElement(p, iEnt, iEle, numNodes, type, xyz, vval[0], pre);
      addVectorElement(p, iEnt, iEle, numNodes, type, xyz, vval[1], pre);
      addVectorElement(p, iEnt, iEle, numNodes, type, xyz, vval[2], pre);
    }
    else
      addScalarElement(p, type, xyz, val, pre, numNodes);
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < numNodes; j++) delete[] vval[i][j];
      delete[] vval[i];
    }
  }
}

static void addElementsInArrays(PView *p, bool preprocessNormalsOnly)
{
  static int numNodesError = 0, numCompError = 0;

  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  opt->tmpBBox.reset();

  int NMAX = PVIEW_NMAX;
  double **xyz = new double *[NMAX];
  double **val = new double *[NMAX];
  for(int i = 0; i < NMAX; i++) {
    xyz[i] = new double[3];
    val[i] = new double[9];
  }
  for(int ent = 0; ent < data->getNumEntities(opt->timeStep); ent++) {
    if(data->skipEntity(opt->timeStep, ent)) continue;
    for(int i = 0; i < data->getNumElements(opt->timeStep, ent); i++) {
      if(data->skipElement(opt->timeStep, ent, i, true, opt->sampling))
        continue;
      int type = data->getType(opt->timeStep, ent, i);
      if(opt->skipElement(type)) continue;
      int numComp = data->getNumComponents(opt->timeStep, ent, i);
      int numNodes = data->getNumNodes(opt->timeStep, ent, i);
      if(numNodes > PVIEW_NMAX) {
        if(type == TYPE_POLYG || type == TYPE_POLYH) {
          if(numNodes > NMAX) {
            for(int j = 0; j < NMAX; j++) {
              delete[] xyz[j];
              delete[] val[j];
            }
            delete[] xyz;
            delete[] val;
            NMAX = numNodes;
            xyz = new double *[NMAX];
            val = new double *[NMAX];
            for(int j = 0; j < NMAX; j++) {
              xyz[j] = new double[3];
              val[j] = new double[9];
            }
          }
        }
        else {
          if(numNodesError != numNodes) {
            numNodesError = numNodes;
            Msg::Warning(
              "Fields with %d nodes per element cannot be displayed: "
              "either force the field type or select 'Adapt visualization "
              "grid' if the field is high-order",
              numNodes);
          }
          continue;
        }
      }
      if((numComp > 9 && !opt->forceNumComponents) ||
         opt->forceNumComponents > 9) {
        if(numCompError != numComp) {
          numCompError = numComp;
          Msg::Warning(
            "Fields with %d components cannot be displayed: "
            "either force the field type or select 'Adapt visualization "
            "grid' if the field is high-order",
            numComp);
        }
        continue;
      }
      for(int j = 0; j < numNodes; j++) {
        data->getNode(opt->timeStep, ent, i, j, xyz[j][0], xyz[j][1],
                      xyz[j][2]);
        if(opt->forceNumComponents) {
          for(int k = 0; k < opt->forceNumComponents; k++) {
            int comp = opt->componentMap[k];
            if(comp >= 0 && comp < numComp)
              data->getValue(opt->timeStep, ent, i, j, comp, val[j][k]);
            else
              val[j][k] = 0.;
          }
        }
        else
          for(int k = 0; k < numComp; k++)
            data->getValue(opt->timeStep, ent, i, j, k, val[j][k]);
      }
      if(opt->forceNumComponents) numComp = opt->forceNumComponents;

      changeCoordinates(p, ent, i, numNodes, type, numComp, xyz, val);
      int dim = data->getDimension(opt->timeStep, ent, i);
      if(!isElementVisible(opt, dim, numNodes, xyz)) continue;

      for(int j = 0; j < numNodes; j++)
        opt->tmpBBox += SPoint3(xyz[j][0], xyz[j][1], xyz[j][2]);

      if(opt->showElement && !data->useGaussPoints())
        addOutlineElement(p, type, xyz, preprocessNormalsOnly, numNodes);

      if(opt->intervalsType != PViewOptions::Numeric) {
        if(data->useGaussPoints()) {
          for(int j = 0; j < numNodes; j++) {
            double *x2 = new double[3];
            double **xyz2 = &x2;
            double *v2 = new double[9];
            double **val2 = &v2;
            xyz2[0][0] = xyz[j][0];
            xyz2[0][1] = xyz[j][1];
            xyz2[0][2] = xyz[j][2];
            for(int k = 0; k < numComp; k++) val2[0][k] = val[j][k];
            if(numComp == 1 && opt->drawScalars)
              addScalarElement(p, TYPE_PNT, xyz2, val2, preprocessNormalsOnly,
                               numNodes);
            else if(numComp == 3 && opt->drawVectors)
              addVectorElement(p, ent, i, 1, TYPE_PNT, xyz2, val2,
                               preprocessNormalsOnly);
            else if(numComp == 9 && opt->drawTensors)
              addTensorElement(p, ent, i, 1, TYPE_PNT, xyz2, val2,
                               preprocessNormalsOnly);
            delete[] x2;
            delete[] v2;
          }
        }
        else if(numComp == 1 && opt->drawScalars)
          addScalarElement(p, type, xyz, val, preprocessNormalsOnly, numNodes);
        else if(numComp == 3 && opt->drawVectors)
          addVectorElement(p, ent, i, numNodes, type, xyz, val,
                           preprocessNormalsOnly);
        else if(numComp == 9 && opt->drawTensors)
          addTensorElement(p, ent, i, numNodes, type, xyz, val,
                           preprocessNormalsOnly);
      }
    }
  }
  for(int j = 0; j < NMAX; j++) {
    delete[] xyz[j];
    delete[] val[j];
  }
  delete[] xyz;
  delete[] val;
}

class initPView {
private:
  // we try to estimate how many primitives will end up in the vertex
  // arrays, since reallocating the arrays takes a huge amount of time
  // on Windows/Cygwin
  int _estimateIfClipped(PView *p, int num)
  {
    if(CTX::instance()->clipWholeElements &&
       CTX::instance()->clipOnlyDrawIntersectingVolume) {
      PViewOptions *opt = p->getOptions();
      for(int clip = 0; clip < 6; clip++) {
        if(opt->clip & (1 << clip)) return (int)sqrt((double)num);
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
    int polygs = data->getNumPolygons(opt->timeStep);
    int tets = data->getNumTetrahedra(opt->timeStep);
    int prisms = data->getNumPrisms(opt->timeStep);
    int pyrs = data->getNumPyramids(opt->timeStep);
    int trihs = data->getNumTrihedra(opt->timeStep);
    int hexas = data->getNumHexahedra(opt->timeStep);
    int polyhs = data->getNumPolyhedra(opt->timeStep);
    int heuristic = 0;
    if(opt->intervalsType == PViewOptions::Iso)
      heuristic = (tets + prisms + pyrs + hexas + polyhs) / 10;
    else if(opt->intervalsType == PViewOptions::Continuous)
      heuristic = (tris + 2 * quads + 3 * polygs + 6 * tets + 8 * prisms +
                   6 * pyrs + 2 * trihs + 12 * hexas + 10 * polyhs);
    else if(opt->intervalsType == PViewOptions::Discrete)
      heuristic = (tris + 2 * quads + 3 * polygs + 6 * tets + 8 * prisms +
                   6 * pyrs + 2 * trihs + 12 * hexas + 10 * polyhs) *
                  2;
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
  int _estimateNumEllipses(PView *p)
  {
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();
    int heuristic = data->getNumTensors(opt->timeStep);
    heuristic = _estimateIfClipped(p, heuristic);
    return heuristic + 1000;
  }

public:
  bool operator()(PView *p)
  {
    // use adaptive data if available
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();

    if(data->getDirty() || !data->getNumTimeSteps() || !p->getChanged())
      return false;
    if(!opt->visible || opt->type != PViewOptions::Plot3D) return false;

    p->deleteVertexArrays();

    if(data->isRemote()) {
      // FIXME: need to rewrite option code and add nice serialization
      std::string fileName =
        CTX::instance()->homeDir + CTX::instance()->tmpFileName;
      PrintOptions(0, GMSH_FULLRC, 0, 0, fileName.c_str());
      std::string options = ConvertFileToString(fileName);
      data->fillRemoteVertexArrays(options);
      return false;
    }

    if(opt->useGenRaise) opt->createGeneralRaise();

    if(opt->rangeType == PViewOptions::Custom) {
      opt->tmpMin = opt->customMin;
      opt->tmpMax = opt->customMax;
    }
    else if(opt->rangeType == PViewOptions::PerTimeStep) {
      opt->tmpMin = data->getMin(opt->timeStep);
      opt->tmpMax = data->getMax(opt->timeStep);
    }
    else {
      // FIXME: this is not perfect for multi-step adaptive views, as
      // we don't have the correct min/max info for the other steps
      opt->tmpMin = data->getMin();
      opt->tmpMax = data->getMax();
    }

    p->va_points = new VertexArray(1, _estimateNumPoints(p));
    p->va_lines = new VertexArray(2, _estimateNumLines(p));
    p->va_triangles = new VertexArray(3, _estimateNumTriangles(p));
    p->va_vectors = new VertexArray(2, _estimateNumVectors(p));
    p->va_ellipses = new VertexArray(4, _estimateNumEllipses(p));

    if(p->normals) delete p->normals;

    p->normals = new smooth_normals(opt->angleSmoothNormals);

    if(opt->smoothNormals) addElementsInArrays(p, true);
    addElementsInArrays(p, false);

    p->va_points->finalize();
    p->va_lines->finalize();
    p->va_triangles->finalize();
    p->va_vectors->finalize();
    p->va_ellipses->finalize();

    Msg::Debug(
      "%d vertices in vertex arrays (%g Mb)",
      p->va_points->getNumVertices() + p->va_lines->getNumVertices() +
        p->va_triangles->getNumVertices() + p->va_vectors->getNumVertices() +
        p->va_ellipses->getNumVertices(),
      p->va_points->getMemoryInMb() + p->va_lines->getMemoryInMb() +
        p->va_triangles->getMemoryInMb() + p->va_vectors->getMemoryInMb() +
        p->va_ellipses->getMemoryInMb());

    p->setChanged(false);
    return true;
  }
};

bool PView::fillVertexArrays()
{
  initPView init;
  return init(this);
}

void PView::fillVertexArray(onelab::localNetworkClient *remote, int length,
                            const char *bytes, int swap)
{
  std::string name;
  int tag, type, numSteps;
  double min, max, time, xmin, ymin, zmin, xmax, ymax, zmax;
  if(!VertexArray::decodeHeader(length, bytes, swap, name, tag, type, min, max,
                                numSteps, time, xmin, ymin, zmin, xmax, ymax,
                                zmax))
    return;

  Msg::Debug("Filling vertex array (type %d) in view tag %d", type, tag);

  SBoundingBox3d bbox(xmin, ymin, zmin, xmax, ymax, zmax);

  PView *p = PView::getViewByTag(tag);
  if(!p) {
    Msg::Info("View tag %d does not exist: creating new view", tag);
    PViewData *data =
      new PViewDataRemote(remote, min, max, numSteps, time, bbox);
    data->setName(name + " (remote)");
    p = new PView(data, tag);
    SetBoundingBox();
  }
  else {
    PViewDataRemote *data = dynamic_cast<PViewDataRemote *>(p->getData());
    if(data) {
      data->setMin(min);
      data->setMax(max);
      data->setTime(time);
      data->setBoundingBox(bbox);
    }
  }
  // not perfect (does not take transformations into account)
  p->getOptions()->tmpBBox = bbox;

  switch(type) {
  case 1:
    if(p->va_points) delete p->va_points;
    p->va_points = new VertexArray(1, 100);
    p->va_points->fromChar(length, bytes, swap);
    break;
  case 2:
    if(p->va_lines) delete p->va_lines;
    p->va_lines = new VertexArray(2, 100);
    p->va_lines->fromChar(length, bytes, swap);
    break;
  case 3:
    if(p->va_triangles) delete p->va_triangles;
    p->va_triangles = new VertexArray(3, 100);
    p->va_triangles->fromChar(length, bytes, swap);
    break;
  case 4:
    if(p->va_vectors) delete p->va_vectors;
    p->va_vectors = new VertexArray(2, 100);
    p->va_vectors->fromChar(length, bytes, swap);
    break;
  case 5:
    if(p->va_ellipses) delete p->va_ellipses;
    p->va_ellipses = new VertexArray(4, 100);
    p->va_ellipses->fromChar(length, bytes, swap);
    break;
  default: Msg::Error("Cannot fill vertex array of type %d", type); return;
  }

  p->setChanged(false);
  p->getData()->setDirty(false);
}
