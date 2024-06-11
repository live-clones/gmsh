// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <algorithm>
#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "VertexArray.h"
#include "Context.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "closestVertex.h"

GEntity::GEntity(GModel *m, int t)
  : _model(m), _tag(t), _meshMaster(this), _visible(1), _selection(0),
    _onlySomeElementsVisible(1), _obb(nullptr), va_lines(nullptr),
    va_triangles(nullptr)
{
  // default color when none is explicitly specified - don't change this, as it
  // is documented and used in scripts to detect if explicit colors are set
  // (cf. useColor() below)
  _color = CTX::instance()->packColor(0, 0, 255, 0);
}

void GEntity::deleteVertexArrays()
{
  if(va_lines) delete va_lines;
  va_lines = nullptr;
  if(va_triangles) delete va_triangles;
  va_triangles = nullptr;
}

char GEntity::getVisibility()
{
  if(CTX::instance()->hideUnselected && !CTX::instance()->pickElements &&
     !getSelection())
    return false;
  return _visible;
}

bool GEntity::useColor()
{
  int r = CTX::instance()->unpackRed(_color);
  int g = CTX::instance()->unpackGreen(_color);
  int b = CTX::instance()->unpackBlue(_color);
  int a = CTX::instance()->unpackAlpha(_color);
  if(r == 0 && g == 0 && b == 255 && a == 0) return false;
  return true;
}

std::string GEntity::getInfoString(bool additional, bool multiline)
{
  std::ostringstream sstream;
  sstream << getTypeString() << " " << tag();

  switch(getNativeType()) {
  case OpenCascadeModel: sstream << " (OCC)"; break;
  case AcisModel: sstream << " (ACIS)"; break;
  case ParasolidModel: sstream << " (Parasolid)"; break;
  default: break;
  }

  {
    std::string name = model()->getElementaryName(dim(), tag());
    if(name.size()) sstream << ": " << name;
  }

  if(additional) {
    std::string info = getAdditionalInfoString(multiline);
    if(info.size()) {
      if(multiline)
        sstream << "\n";
      else
        sstream << " ";
      sstream << info;
    }
  }

  if(physicals.size()) {
    for(std::size_t i = 0; i < physicals.size(); i++) {
      if(multiline)
        sstream << "\n";
      else
        sstream << ", ";
      sstream << "Physical ";
      switch(dim()) {
      case 0: sstream << "Point"; break;
      case 1: sstream << "Curve"; break;
      case 2: sstream << "Surface"; break;
      case 3: sstream << "Volume"; break;
      }
      sstream << " " << std::abs(physicals[i]);
      std::string name =
        model()->getPhysicalName(dim(), std::abs(physicals[i]));
      if(name.size()) sstream << ": " << name;
    }
  }

  if(useColor()) {
    int r = CTX::instance()->unpackRed(_color);
    int g = CTX::instance()->unpackGreen(_color);
    int b = CTX::instance()->unpackBlue(_color);
    if(multiline)
      sstream << "\n";
    else
      sstream << ", ";
    sstream << "Color (" << r << ", " << g << ", " << b << ")";
  }

  return sstream.str();
}

// removes a MeshVertex
void GEntity::removeMeshVertex(MVertex *v, bool del)
{
  auto it = std::find(mesh_vertices.begin(), mesh_vertices.end(), v);
  if(it != mesh_vertices.end()) {
    mesh_vertices.erase(it);
    if(del) delete v;
  }
}

GVertex *GEntity::cast2Vertex() { return dynamic_cast<GVertex *>(this); }
GEdge *GEntity::cast2Edge() { return dynamic_cast<GEdge *>(this); }
GFace *GEntity::cast2Face() { return dynamic_cast<GFace *>(this); }
GRegion *GEntity::cast2Region() { return dynamic_cast<GRegion *>(this); }

// sets the entity m from which the mesh will be copied
void GEntity::setMeshMaster(GEntity *gMaster)
{
  if(gMaster->dim() != dim()) {
    Msg::Error("Model entity %d of dimension %d cannot"
               "be the mesh master of entity %d of dimension %d",
               gMaster->tag(), gMaster->dim(), tag(), dim());
    return;
  }
  _meshMaster = gMaster;
}

void GEntity::setMeshMaster(GEntity *gMaster, const std::vector<double> &tfo,
                            bool updateCorrespVert)
{
  if(gMaster->dim() != dim()) {
    Msg::Error("Model entity %d of dimension %d cannot"
               "be the mesh master of entity %d of dimension %d",
               gMaster->tag(), gMaster->dim(), tag(), dim());
    return;
  }

  if(tfo.empty()) {
    GEntity::setMeshMaster(gMaster);
    return;
  }

  if(tfo.size() != 16) {
    Msg::Error("Periodicity transformation from entity %d to %d (dim %d) has "
               "%d components, while 16 are required",
               gMaster->tag(), tag(), gMaster->dim(), tfo.size());
    return;
  }

  affineTransform = tfo;
  _meshMaster = gMaster;
  if(updateCorrespVert) updateCorrespondingVertices();
}

void GEntity::addVerticesInSet(std::set<MVertex *> &vtcs, bool closure) const
{
  vtcs.insert(mesh_vertices.begin(), mesh_vertices.end());

  if(closure) {
    switch(dim()) {
    case 3: {
      std::vector<GFace *> clos = faces();
      auto cIter = clos.begin();
      for(; cIter != clos.end(); ++cIter)
        (*cIter)->addVerticesInSet(vtcs, true);
      break;
    }
    case 2: {
      std::vector<GEdge *> clos = edges();
      auto cIter = clos.begin();
      for(; cIter != clos.end(); ++cIter)
        (*cIter)->addVerticesInSet(vtcs, true);
      break;
    }
    case 1: {
      std::vector<GVertex *> clos = vertices();
      auto cIter = clos.begin();
      for(; cIter != clos.end(); ++cIter)
        (*cIter)->addVerticesInSet(vtcs, true);
      break;
    }
    }
  }
}

void GEntity::updateCorrespondingVertices()
{
  if(_meshMaster != this && affineTransform.size() == 16) {
    correspondingVertices.clear();
    closestVertexFinder cvf(_meshMaster, true);

    if(cvf.getNbVtcs()) {
      std::vector<double> tfo = affineTransform;
      std::vector<double> inv;
      invertAffineTransformation(tfo, inv);

      std::set<MVertex *> vtcs;
      this->addVerticesInSet(vtcs, true);

      auto vIter = vtcs.begin();
      for(; vIter != vtcs.end(); ++vIter) {
        MVertex *tv = *vIter;
        // double tgt[4] = {tv->x(),tv->y(),tv->z(),1};
        // double xyz[4] = {0,0,0,0};

        // int idx = 0;
        // for (int i=0;i<3;i++) for (int j=0;j<4;j++) tgt[i] += inv[idx++] *
        // ori[j];
        MVertex *sv = cvf(tv->point(), inv);

        correspondingVertices[tv] = sv;

        double src[4] = {sv->x(), sv->y(), sv->z(), 1};
        double xyz[4] = {0, 0, 0, 0};
        int idx = 0;
        for(int i = 0; i < 3; i++) {
          xyz[i] = 0;
          for(int j = 0; j < 4; j++) xyz[i] += tfo[idx++] * src[j];
        }

        tv->x() = xyz[0];
        tv->y() = xyz[1];
        tv->z() = xyz[2];
      }
    }
  }
}

void GEntity::copyMasterCoordinates()
{
  if(_meshMaster != this && affineTransform.size() == 16) {
    auto cvIter = correspondingVertices.begin();

    for(; cvIter != correspondingVertices.end(); ++cvIter) {
      MVertex *tv = cvIter->first;
      MVertex *sv = cvIter->second;
      double src[4] = {sv->x(), sv->y(), sv->z(), 1};
      double tgt[3] = {0, 0, 0};
      int idx = 0;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++) tgt[i] += affineTransform[idx++] * src[j];
      tv->x() = tgt[0];
      tv->y() = tgt[1];
      tv->z() = tgt[2];
    }

    cvIter = correspondingHighOrderVertices.begin();

    for(; cvIter != correspondingHighOrderVertices.end(); ++cvIter) {
      MVertex *tv = cvIter->first;
      MVertex *sv = cvIter->second;

      double src[4] = {sv->x(), sv->y(), sv->z(), 1};
      double tgt[3] = {0, 0, 0};

      int idx = 0;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++) tgt[i] += affineTransform[idx++] * src[j];

      tv->x() = tgt[0];
      tv->y() = tgt[1];
      tv->z() = tgt[2];
    }
  }
}
