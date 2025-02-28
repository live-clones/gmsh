#if defined(BUILD_ANDROID)
#include <GLES/gl.h>
#include <GLES/glext.h>
#else
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#endif

#include <gmsh/GmshGlobal.h>
#include <gmsh/GModel.h>
#include <gmsh/PView.h>
#include <gmsh/PViewData.h>
#include <gmsh/Context.h>

#include "drawContext.h"

// from GModelVertexArrays
extern unsigned int getColorByEntity(GEntity *e);

void drawMeshVertex(GVertex *e)
{
  if(!CTX::instance()->mesh.nodes) return;
  std::vector<GLfloat> vertex;
  std::vector<GLubyte> color;
  for(unsigned int i = 0; i < e->mesh_vertices.size(); i++) {
    MVertex *v = e->mesh_vertices[i];
    if(!v->getVisibility()) continue;
    unsigned int col;
    if(CTX::instance()->mesh.colorCarousel == 0 ||
       CTX::instance()->mesh.volumeFaces ||
       CTX::instance()->mesh.surfaceFaces) {
      if(v->getPolynomialOrder() > 1)
        col = CTX::instance()->color.mesh.nodeSup;
      else
        col = CTX::instance()->color.mesh.node;
    }
    else
      col = getColorByEntity(e);
    color.push_back((GLubyte)CTX::instance()->unpackRed(col));
    color.push_back((GLubyte)CTX::instance()->unpackGreen(col));
    color.push_back((GLubyte)CTX::instance()->unpackBlue(col));
    color.push_back((GLubyte)CTX::instance()->unpackAlpha(col));
    vertex.push_back(v->x());
    vertex.push_back(v->y());
    vertex.push_back(v->z());
  }
  glVertexPointer(3, GL_FLOAT, 0, &vertex.front());
  glEnableClientState(GL_VERTEX_ARRAY);
  glColorPointer(4, GL_UNSIGNED_BYTE, (int)color.size() / 4, &color.front());
  glEnableClientState(GL_COLOR_ARRAY);
  glDrawArrays(GL_POINTS, 0, (int)vertex.size() / 3);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
}

void drawMeshEdge(GEdge *e)
{
  if(!e->getVisibility()) return;
  glLineWidth(CTX::instance()->mesh.lineWidth);
  drawArray(e->va_lines, GL_LINES, true);
}

void drawMeshFace(GFace *f)
{
  if(!f->getVisibility()) return;
  drawArray(f->va_lines, GL_LINES, true);
}

void drawMeshRegion(GRegion *r)
{
  if(!r->getVisibility()) return;
  drawArray(r->va_lines, GL_LINES, true);
}

void drawContext::drawMesh()
{
  if(!CTX::instance()->mesh.draw) return;

  if(CTX::instance()->mesh.changed)
    for(unsigned int i = 0; i < GModel::list.size(); i++)
      for(unsigned int j = 0; j < PView::list.size(); j++)
        if(PView::list[j]->getData()->hasModel(GModel::list[i]))
          PView::list[j]->setChanged(true);

  unsigned int col = CTX::instance()->color.mesh.line;
  glColor4ub((GLubyte)CTX::instance()->unpackRed(col),
             (GLubyte)CTX::instance()->unpackGreen(col),
             (GLubyte)CTX::instance()->unpackBlue(col),
             (GLubyte)CTX::instance()->unpackAlpha(col));
  for(unsigned int i = 0; i < GModel::list.size(); i++) {
    GModel *m = GModel::list[i];
    m->fillVertexArrays();
    if(!m->getVisibility()) continue;
    int status = m->getMeshStatus();
    if(status >= 0)
      std::for_each(m->firstVertex(), m->lastVertex(), drawMeshVertex);
    if(status >= 1) std::for_each(m->firstEdge(), m->lastEdge(), drawMeshEdge);
    if(status >= 2) std::for_each(m->firstFace(), m->lastFace(), drawMeshFace);
    if(status >= 3)
      std::for_each(m->firstRegion(), m->lastRegion(), drawMeshRegion);
  }
  CTX::instance()->mesh.changed = 0;
}
