// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include <algorithm>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "Plugin.h"
#include "Numeric.h"
#include "VertexArray.h"
#include "Context.h"
#include "gl2ps.h"

#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#include <FL/gl.H>
#endif

static void drawArrays(drawContext *ctx, PView *p, VertexArray *va, GLint type, 
                       bool useNormalArray)
{
  if(!va || !va->getNumVertices()) return;

  PViewOptions *opt = p->getOptions();

  if(CTX::instance()->polygonOffset || opt->showElement)
    glEnable(GL_POLYGON_OFFSET_FILL);

  if(type == GL_POINTS && opt->pointType > 0){
    for(int i = 0; i < va->getNumVertices(); i++){
      float *p = va->getVertexArray(3 * i);
      glColor4ubv((GLubyte *)va->getColorArray(4 * i));
      double f = 1.;
      if(opt->pointType > 1){
        char *n = va->getNormalArray(3 * i);
        f = char2float(*n);
      }
      if(opt->pointType == 2){
        int s = (int)(opt->pointSize * f);
        if(s){
          glPointSize((float)s);
          gl2psPointSize((float)(s * CTX::instance()->print.epsPointSizeFactor));
          glBegin(GL_POINTS);
          glVertex3d(p[0], p[1], p[2]);
          glEnd();
        }
      }
      else
        ctx->drawSphere(opt->pointSize * f, p[0], p[1], p[2], opt->light);
    }
  }
  else if(type == GL_LINES && opt->lineType > 0){
    for(int i = 0; i < va->getNumVertices(); i += 2){
      float *p0 = va->getVertexArray(3 * i);
      float *p1 = va->getVertexArray(3 * (i + 1));
      double x[2] = {p0[0], p1[0]}, y[2] = {p0[1], p1[1]}, z[2] = {p0[2], p1[2]};
      glColor4ubv((GLubyte *)va->getColorArray(4 * i));
      if(opt->lineType == 2){
        char *n0 = va->getNormalArray(3 * i);
        char *n1 = va->getNormalArray(3 * (i + 1));
        double v0 = char2float(*n0), v1 = char2float(*n1);
        ctx->drawTaperedCylinder(opt->lineWidth, v0, v1, 0., 1., x, y, z, opt->light);
      }
      else
        ctx->drawCylinder(opt->lineWidth, x, y, z, opt->light);
    }
  }
  else{
    glVertexPointer(3, GL_FLOAT, 0, va->getVertexArray());
    glEnableClientState(GL_VERTEX_ARRAY);
    if(useNormalArray){
      glEnable(GL_LIGHTING);
      glNormalPointer(GL_BYTE, 0, va->getNormalArray());
      glEnableClientState(GL_NORMAL_ARRAY);
    }
    else
      glDisableClientState(GL_NORMAL_ARRAY);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, va->getColorArray());
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(type, 0, va->getNumVertices());
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }

  glDisable(GL_POLYGON_OFFSET_FILL);
  glDisable(GL_LIGHTING);
}

static void drawEllipseArray(drawContext *ctx, PView *p, VertexArray *va)
{
  if(!va || va->getNumVerticesPerElement() != 4) return;

  PViewOptions *opt = p->getOptions();
  
  for(int i = 0; i < va->getNumVertices(); i += 4) {
    float *s = va->getVertexArray(3 * i);
    float vv[3][3];
    double lmax = opt->tmpMax;
    double scale = (opt->arrowSizeMax - opt->arrowSizeMin) *ctx->pixel_equiv_x / ctx->s[0]/2;
    double lmin = opt->arrowSizeMin * ctx->pixel_equiv_x / ctx->s[0]/2;
    for (int j = 0; j < 3; j++) {
      float *v = va->getVertexArray(3 * (i + j + 1));
      double l = sqrt (v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
      double l2 = std::min(1., l/lmax);
      for (int k = 0; k < 3; k++) {
        vv[j][k] = v[k]/l*(scale*l2 + lmin);
      }
    }
    glColor4ubv((GLubyte *)va->getColorArray(4 * i));
    if (opt->tensorType == PViewOptions::Ellipsoid)
      ctx->drawEllipsoid(s[0], s[1], s[2], vv[0], vv[1], vv[2], opt->light);
    else
      ctx->drawEllipse(s[0], s[1], s[2], vv[0], vv[1], opt->light);
  }
}

static void drawVectorArray(drawContext *ctx, PView *p, VertexArray *va)
{
  if(!va || va->getNumVerticesPerElement() != 2) return;

  PViewOptions *opt = p->getOptions();
  
  for(int i = 0; i < va->getNumVertices(); i += 2){
    float *s = va->getVertexArray(3 * i);
    float *v = va->getVertexArray(3 * (i + 1));
    glColor4ubv((GLubyte *)va->getColorArray(4 * i));
    double l = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    double lmax = opt->tmpMax;
    if((l || opt->vectorType == 6) && lmax){
      double scale = (opt->arrowSizeMax - opt->arrowSizeMin) / lmax;
      // log scaling
      if(opt->scaleType == PViewOptions::Logarithmic && 
         opt->tmpMin > 0 && opt->tmpMax > opt->tmpMin && l != opt->tmpMin){
        scale = (opt->arrowSizeMax - opt->arrowSizeMin) / l * 
          log10(l / opt->tmpMin) / log10(opt->tmpMax / opt->tmpMin);
      }
      if(opt->arrowSizeMin && l) scale += opt->arrowSizeMin / l;
      double px = scale * v[0];
      double py = scale * v[1];
      double pz = scale * v[2];
      // only draw vectors larger than 1 pixel on screen, except when
      // drawing "comet" glyphs
      if(opt->vectorType == 6 || fabs(px) > 1. || fabs(py) > 1. || fabs(pz) > 1.){
        double d = ctx->pixel_equiv_x / ctx->s[0];
        double dx = px * d, dy = py * d, dz = pz * d;
        double x = s[0], y = s[1], z = s[2];
        if(opt->centerGlyphs == 2){
          x -= dx; y -= dy; z -= dz;
        }
        else if(opt->centerGlyphs == 1){
          x -= 0.5 * dx; y -= 0.5 * dy; z -= 0.5 * dz;
        }
        ctx->drawVector(opt->vectorType, opt->intervalsType != PViewOptions::Iso,
                        x, y, z, dx, dy, dz, opt->light);
      }
    }
  }
}

static std::string stringValue(int numComp, double d[9], double norm, 
                               const char *format)
{
  char label[100];
  if(numComp == 1)
    sprintf(label, format, d[0]);
  else if(numComp == 3){
    char str[3][32];
    sprintf(str[0], format, d[0]);
    sprintf(str[1], format, d[1]);
    sprintf(str[2], format, d[2]);
    sprintf(label, "(%s,%s,%s)", str[0], str[1], str[2]);
  }
  else if(numComp == 9)
    sprintf(label, format, norm);
  return std::string(label);
}

static void drawNumberGlyphs(drawContext *ctx, PView *p, int numNodes, int numComp, 
                             double xyz[PVIEW_NMAX][3], double val[PVIEW_NMAX][9])
{
  PViewOptions *opt = p->getOptions();
  double d[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};

  double vmin = opt->tmpMin, vmax = opt->tmpMax;

  if(opt->glyphLocation == PViewOptions::COG){
    SPoint3 pc(0., 0., 0.);
    for(int i = 0; i < numNodes; i++){
      pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
      for(int j = 0; j < numComp; j++) d[j] += val[i][j];
    }
    pc /= (double)numNodes;
    for(int j = 0; j < numComp; j++) d[j] /= (double)numNodes;
    double v = ComputeScalarRep(numComp, d);
    if(v >= vmin && v <= vmax){
      unsigned int col = opt->getColor(v, vmin, vmax, false, opt->nbIso);
      glColor4ubv((GLubyte *) & col);
      glRasterPos3d(pc.x(), pc.y(), pc.z());
      if(opt->centerGlyphs == 2)
        ctx->drawStringRight(stringValue(numComp, d, v, opt->format.c_str()));
      else if(opt->centerGlyphs == 1)
        ctx->drawStringCenter(stringValue(numComp, d, v, opt->format.c_str()));
      else
        ctx->drawString(stringValue(numComp, d, v, opt->format.c_str()));
    }
  }
  else if(opt->glyphLocation == PViewOptions::Vertex){
    for(int i = 0; i < numNodes; i++){
      double v = ComputeScalarRep(numComp, val[i]);
      if(v >= vmin && v <= vmax){
        unsigned int col = opt->getColor(v, vmin, vmax, false, opt->nbIso);
        glColor4ubv((GLubyte *) & col);
        glRasterPos3d(xyz[i][0], xyz[i][1], xyz[i][2]);
        if(opt->centerGlyphs == 2)
          ctx->drawStringRight(stringValue(numComp, val[i], v, opt->format.c_str()));
        else if(opt->centerGlyphs == 1)
          ctx->drawStringCenter(stringValue(numComp, val[i], v, opt->format.c_str()));
        else
          ctx->drawString(stringValue(numComp, val[i], v, opt->format.c_str()));
      }
    }
  }
}

static void drawNormalVectorGlyphs(drawContext *ctx, PView *p, int numNodes, 
                                   double xyz[PVIEW_NMAX][3], double val[PVIEW_NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  SPoint3 pc(0., 0., 0.);
  for(int i = 0; i < numNodes; i++)
    pc += SPoint3(xyz[i][0], xyz[i][1], xyz[i][2]);
  pc /= (double)numNodes;

  SVector3 t1(xyz[1][0] - xyz[0][0], xyz[1][1] - xyz[0][1], xyz[1][2] - xyz[0][2]);
  SVector3 t2(xyz[2][0] - xyz[0][0], xyz[2][1] - xyz[0][1], xyz[2][2] - xyz[0][2]);
  SVector3 n = crossprod(t1, t2);
  n.normalize();

  for(int i = 0; i < 3; i++)
    n[i] *= opt->normals * ctx->pixel_equiv_x / ctx->s[i];
  glColor4ubv((GLubyte *) & opt->color.normals);
  ctx->drawVector(CTX::instance()->vectorType, 0, pc[0], pc[1], pc[2], n[0], n[1], n[2],
                  opt->light);
}

static void drawTangentVectorGlyphs(drawContext *ctx, PView *p, int numNodes,
                                    double xyz[PVIEW_NMAX][3], double val[PVIEW_NMAX][9])
{
  PViewOptions *opt = p->getOptions();

  SPoint3 p0(xyz[0][0], xyz[0][1], xyz[0][2]);
  SPoint3 p1(xyz[1][0], xyz[1][1], xyz[1][2]);
  SVector3 pc = 0.5 * (p0 + p1);
  SVector3 t(p0, p1);
  t.normalize();
  for(int i = 0; i < 3; i++)
    t[i] *= opt->tangents * ctx->pixel_equiv_x / ctx->s[i];
  glColor4ubv((GLubyte *) & opt->color.tangents);
  ctx->drawVector(CTX::instance()->vectorType, 0, pc[0], pc[1], pc[2], t[0], t[1], t[2], 
                  opt->light);
}

static void drawGlyphs(drawContext *ctx, PView *p)
{
  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  if(!opt->normals && !opt->tangents && opt->intervalsType != PViewOptions::Numeric)
    return;

  Msg::Debug("drawing extra glyphs (this is slow...)");

  // speedup drawing of textured fonts on cocoa mac version
#if defined(HAVE_FLTK) && defined(__APPLE__) && defined(HAVE_64BIT_SIZE_T)
#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
  if(opt->intervalsType == PViewOptions::Numeric){
    int numStrings = 0;
    for(int ent = 0; ent < data->getNumEntities(opt->timeStep); ent++)
      numStrings += data->getNumElements(opt->timeStep, ent);
    if(gl_texture_pile_height() < numStrings)
      gl_texture_pile_height(numStrings);
  }
#endif
#endif

  double xyz[PVIEW_NMAX][3], val[PVIEW_NMAX][9];
  for(int ent = 0; ent < data->getNumEntities(opt->timeStep); ent++){
    if(data->skipEntity(opt->timeStep, ent)) continue;
    for(int i = 0; i < data->getNumElements(opt->timeStep, ent); i++){
      if(data->skipElement(opt->timeStep, ent, i, true, opt->sampling)) continue;
      int type = data->getType(opt->timeStep, ent, i);
      if(opt->skipElement(type)) continue;
      int dim = data->getDimension(opt->timeStep, ent, i);
      int numComp = data->getNumComponents(opt->timeStep, ent, i);
      int numNodes = data->getNumNodes(opt->timeStep, ent, i);
      for(int j = 0; j < numNodes; j++){
        data->getNode(opt->timeStep, ent, i, j, xyz[j][0], xyz[j][1], xyz[j][2]);
        if(opt->forceNumComponents){
          for(int k = 0; k < opt->forceNumComponents; k++){
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
      if(!isElementVisible(opt, dim, numNodes, xyz)) continue;
      if(opt->intervalsType == PViewOptions::Numeric)
        drawNumberGlyphs(ctx, p, numNodes, numComp, xyz, val);
      if(dim == 2 && opt->normals)
        drawNormalVectorGlyphs(ctx, p, numNodes, xyz, val);
      else if(dim == 1 && opt->tangents)
        drawTangentVectorGlyphs(ctx, p, numNodes, xyz, val);  
    }
  }
}

static bool eyeChanged(drawContext *ctx, PView *p)
{
  double zeye = 100 * CTX::instance()->lc;
  SPoint3 tmp(ctx->rot[2] * zeye, ctx->rot[6] * zeye, ctx->rot[10] * zeye);
  if(tmp.distance(p->getEye()) > 1.e-3){
    p->setEye(tmp);
    return true;
  }
  return false;
}

class drawPView {
 private:
  drawContext *_ctx;
 public:
  drawPView(drawContext *ctx) : _ctx(ctx) {}
  void operator () (PView *p)
  {
    // use adaptive data if available
    PViewData *data = p->getData(true);
    PViewOptions *opt = p->getOptions();

    if(data->getDirty() || !data->getNumTimeSteps()) return;
    if(!opt->visible || opt->type != PViewOptions::Plot3D) return;
    if(!_ctx->isVisible(p)) return;
   
    glPointSize((float)opt->pointSize);
    gl2psPointSize((float)(opt->pointSize * 
                           CTX::instance()->print.epsPointSizeFactor));
    
    glLineWidth((float)opt->lineWidth);
    gl2psLineWidth((float)(opt->lineWidth *
                           CTX::instance()->print.epsLineWidthFactor));
    
    if(opt->lightTwoSide)
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    else
      glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    
    if(!CTX::instance()->clipWholeElements){
      for(int i = 0; i < 6; i++)
        if(opt->clip & (1 << i))
          glEnable((GLenum)(GL_CLIP_PLANE0 + i));
        else
          glDisable((GLenum)(GL_CLIP_PLANE0 + i));
    }

    if(CTX::instance()->alpha && ColorTable_IsAlpha(&opt->colorTable)){
      if(opt->fakeTransparency){
        // simple additive blending "a la xpost":
        glBlendFunc(GL_SRC_ALPHA, GL_ONE); // glBlendEquation(GL_FUNC_ADD);
        // maximum intensity projection "a la volsuite":
        // glBlendFunc(GL_ONE, GL_ONE); // glBlendEquation(GL_MAX);
        glEnable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
      }
      else{
        // real translucent blending (requires back-to-front traversal)
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        // glBlendEquation(GL_FUNC_ADD);
        glEnable(GL_BLEND);
        if(p->va_triangles && p->va_triangles->getNumVertices() && 
           eyeChanged(_ctx, p)){
          Msg::Debug("Sorting View[%d] for transparency", p->getIndex());
          p->va_triangles->sort(p->getEye().x(), p->getEye().y(), p->getEye().z());
        }
      }
    }

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

    // draw all the vertex arrays
    drawArrays(_ctx, p, p->va_points, GL_POINTS, false);
    drawArrays(_ctx, p, p->va_lines, GL_LINES, opt->light && opt->lightLines);
    drawArrays(_ctx, p, p->va_triangles, GL_TRIANGLES, opt->light);

    // draw the "pseudo" vertex arrays for vectors
    drawVectorArray(_ctx, p, p->va_vectors);
    drawEllipseArray(_ctx, p, p->va_ellipses);

    // to avoid looping over elements (and to enable drawing glyphs
    // for remote views) we should also store these glyphs in "pseudo"
    // vertex arrays
    drawGlyphs(_ctx, p);

    // draw the 3D strings
    if(opt->drawStrings){
      glColor4ubv((GLubyte *) & opt->color.text3d);
      for(int i = 0; i < data->getNumStrings3D(); i++){
        double x, y, z, style;
        std::string str;
        data->getString3D(i, opt->timeStep, str, x, y, z, style);
        glRasterPos3d(x, y, z);
        _ctx->drawString(str, style);
      }
    }
    
    if(CTX::instance()->alpha){
      glDisable(GL_BLEND);
      glEnable(GL_DEPTH_TEST);
    }

    for(int i = 0; i < 6; i++)
      glDisable((GLenum)(GL_CLIP_PLANE0 + i));

    if(opt->axes && opt->type == PViewOptions::Plot3D){
      glColor4ubv((GLubyte *) & opt->color.axes);
      glLineWidth((float)CTX::instance()->lineWidth);
      gl2psLineWidth((float)(CTX::instance()->lineWidth * 
                             CTX::instance()->print.epsLineWidthFactor));
      if(!opt->axesAutoPosition)
        _ctx->drawAxes(opt->axes, opt->axesTics, opt->axesFormat, opt->axesLabel,
                       opt->axesPosition, opt->axesMikado);
      else if(!opt->tmpBBox.empty())
        _ctx->drawAxes(opt->axes, opt->axesTics, opt->axesFormat, opt->axesLabel,
                       opt->tmpBBox, opt->axesMikado);
    }
    
  }
};

class drawPViewBoundingBox {
 private:
  drawContext *_ctx;
 public:
  drawPViewBoundingBox(drawContext *ctx) : _ctx(ctx) {}
  void operator () (PView *p)
  {
    PViewData *data = p->getData();
    PViewOptions *opt = p->getOptions();

    if(!opt->visible || opt->type != PViewOptions::Plot3D) return;

    SBoundingBox3d bb = data->getBoundingBox(opt->timeStep);
    if(bb.empty()) return;

    glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
    glLineWidth((float)CTX::instance()->lineWidth);
    gl2psLineWidth((float)(CTX::instance()->lineWidth * 
                           CTX::instance()->print.epsLineWidthFactor));

    _ctx->drawBox(bb.min().x(), bb.min().y(), bb.min().z(),
                  bb.max().x(), bb.max().y(), bb.max().z());
    glColor3d(1., 0., 0.);
    for(int i = 0; i < 6; i++)
      if(opt->clip & (1 << i))
        _ctx->drawPlaneInBoundingBox(bb.min().x(), bb.min().y(), bb.min().z(),
                                     bb.max().x(), bb.max().y(), bb.max().z(),
                                     CTX::instance()->clipPlane[i][0], 
                                     CTX::instance()->clipPlane[i][1], 
                                     CTX::instance()->clipPlane[i][2], 
                                     CTX::instance()->clipPlane[i][3]);
  }
};

void drawContext::drawPost()
{
  // draw any plugin-specific stuff
  if(GMSH_Plugin::draw) (*GMSH_Plugin::draw)(this);

  if(PView::list.empty()) return;

  if(CTX::instance()->drawBBox || !CTX::instance()->post.draw)
    std::for_each(PView::list.begin(), PView::list.end(), drawPViewBoundingBox(this));

  if(!CTX::instance()->post.draw) return;

  for(unsigned int i = 0; i < PView::list.size(); i++)
    PView::list[i]->fillVertexArrays();
  std::for_each(PView::list.begin(), PView::list.end(), drawPView(this));
}
