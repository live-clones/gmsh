// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
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

GEntity::GEntity(GModel *m,int t)
  : _model(m), _tag(t),_meshMaster(this),_visible(1), _selection(0),
    _allElementsVisible(1), _obb(0), va_lines(0), va_triangles(0)
{
  _color = CTX::instance()->packColor(0, 0, 255, 0);
}

void GEntity::deleteVertexArrays()
{
  if(va_lines) delete va_lines; va_lines = 0;
  if(va_triangles) delete va_triangles; va_triangles = 0;
}

char GEntity::getVisibility()
{
  if(CTX::instance()->hideUnselected && !CTX::instance()->pickElements &&
     !getSelection() && geomType() != ProjectionFace)
    return false;
  return _visible;
}

bool GEntity::useColor()
{
  int r = CTX::instance()->unpackRed(_color);
  int g = CTX::instance()->unpackGreen(_color);
  int b = CTX::instance()->unpackBlue(_color);
  int a = CTX::instance()->unpackAlpha(_color);
  if(r == 0 && g == 0 && b == 255 && a == 0)
    return false;
  return true;
}

std::string GEntity::getInfoString()
{
  std::ostringstream sstream;
  sstream << getTypeString() << " " << tag();

  std::string info = getAdditionalInfoString();
  if(info.size()) sstream << " " << info;

  if(physicals.size()){
    sstream << " (Physical:";
    for(unsigned int i = 0; i < physicals.size(); i++)
      sstream << " " << physicals[i];
    sstream << ")";
  }

  return sstream.str();
}

GVertex *GEntity::cast2Vertex() { return dynamic_cast<GVertex*>(this); }
GEdge *GEntity::cast2Edge() { return dynamic_cast<GEdge*>(this); }
GFace *GEntity::cast2Face() { return dynamic_cast<GFace*>(this); }
GRegion *GEntity::cast2Region() { return dynamic_cast<GRegion*>(this); }

// sets the entity m from which the mesh will be copied
void GEntity::setMeshMaster(GEntity* gMaster)
{
  if (gMaster->dim() != dim()){
    Msg::Error("Model entity %d of dimension %d cannot"
               "be the mesh master of entity %d of dimension %d",
               gMaster->tag(),gMaster->dim(),tag(),dim());
    return;
  }
  _meshMaster = gMaster;
}

void GEntity::setMeshMaster(GEntity* gMaster,const std::vector<double>& tfo)
{
  if (gMaster->dim() != dim()){
    Msg::Error("Model entity %d of dimension %d cannot"
               "be the mesh master of entity %d of dimension %d",
               gMaster->tag(),gMaster->dim(),tag(),dim());
    return;
  }

  if (tfo.size() != 16) {
    Msg::Error("Periodicity transformation from entity %d to %d (dim %d) has %d components"
               ", while 16 are required",
               gMaster->tag(),tag(),gMaster->dim(),tfo.size());
    return;
  }

  affineTransform = tfo;
  _meshMaster = gMaster;
  updateCorrespondingVertices();
}

// gets the entity from which the mesh will be copied
GEntity* GEntity::meshMaster() const { return _meshMaster; }

void GEntity::updateVertices(const std::map<MVertex*,MVertex*>& old2new) {

  // update the list of the vertices

  std::vector<MVertex*> newMeshVertices;
  std::vector<MVertex*>::iterator mIter = mesh_vertices.begin();
  for (;mIter!=mesh_vertices.end();++mIter) {

    MVertex* vtx = *mIter;
    std::map<MVertex*,MVertex*>::const_iterator cIter = old2new.find(vtx);
    if (cIter!=old2new.end()) vtx = cIter->second;
    newMeshVertices.push_back(vtx);
  }

  mesh_vertices.clear();
  mesh_vertices = newMeshVertices;


  // update the periodic vertex lists

  std::map<MVertex*,MVertex*> newCorrespondingVertices;

  std::map<MVertex*,MVertex*>::iterator cIter = correspondingVertices.begin();
  for (;cIter!=correspondingVertices.end();++cIter) {
    
    MVertex* tgt = cIter->first;
    MVertex* src = cIter->second;
    
    std::map<MVertex*,MVertex*>::const_iterator tIter = old2new.find(tgt);
    if (tIter!=old2new.end()) tgt = tIter->second;
    
    std::map<MVertex*,MVertex*>::const_iterator sIter = old2new.find(src);
    if (sIter!=old2new.end()) src = sIter->second;
    
    newCorrespondingVertices.insert(std::make_pair(tgt,src));

  }
  
  correspondingVertices.clear();
  correspondingVertices = newCorrespondingVertices;

  newCorrespondingVertices.clear();

  std::map<MVertex*,MVertex*>::iterator hIter = correspondingHOPoints.begin();
  for (;hIter!=correspondingHOPoints.end();++hIter) {
    
    MVertex* tgt = hIter->first;
    MVertex* src = hIter->second;
    
    std::map<MVertex*,MVertex*>::const_iterator tIter = old2new.find(tgt);
    if (tIter!=old2new.end()) tgt = tIter->second;
    
    std::map<MVertex*,MVertex*>::const_iterator sIter = old2new.find(src);
    if (sIter!=old2new.end()) src = sIter->second;
    
    newCorrespondingVertices.insert(std::make_pair(tgt,src));

  }
  
  correspondingHOPoints.clear();
  correspondingHOPoints = newCorrespondingVertices;

  copyMasterCoordinates();

}

//

void GEntity::addVerticesInSet(std::set<MVertex*>&vtcs,bool closure) const {


  vtcs.insert(mesh_vertices.begin(),mesh_vertices.end());
  
  if (closure) {
    switch (dim()) {
    case 3:
      {
        std::list<GFace*> clos = faces();
        std::list<GFace*>::iterator cIter = clos.begin();
        for (;cIter!=clos.end();++cIter) (*cIter)->addVerticesInSet(vtcs,true);
        break;
      }
    case 2:
      {
        std::list<GEdge*> clos = edges();
        std::list<GEdge*>::iterator cIter = clos.begin();
        for (;cIter!=clos.end();++cIter) (*cIter)->addVerticesInSet(vtcs,true);
        break;
      }
    case 1:
      {
        std::list<GVertex*> clos = vertices();
        std::list<GVertex*>::iterator cIter = clos.begin();
        for (;cIter!=clos.end();++cIter) (*cIter)->addVerticesInSet(vtcs,true);
        break;
      }
    }
  }
}

void GEntity::updateCorrespondingVertices() {

  if (_meshMaster != this && affineTransform.size() == 16) {
    
    correspondingVertices.clear();
    closestVertexFinder cvf(_meshMaster,true);
    
    if (cvf.getNbVtcs()) {
      
      
      std::vector<double> tfo = affineTransform;
      std::vector<double> inv;
      invertAffineTransformation(tfo,inv);
      
      std::set<MVertex*> vtcs;
      this->addVerticesInSet(vtcs,true);
      
      std::set<MVertex*>::iterator vIter = vtcs.begin();
      for (;vIter!=vtcs.end();++vIter) {
        
        MVertex* tv = *vIter;
        // double tgt[4] = {tv->x(),tv->y(),tv->z(),1};
        // double xyz[4] = {0,0,0,0};
        
        // int idx = 0;
        // for (int i=0;i<3;i++) for (int j=0;j<4;j++) tgt[i] += inv[idx++] * ori[j];
        
        MVertex* sv = cvf(tv->point(),inv);
        
        correspondingVertices[tv] = sv;

        double src[4] = {sv->x(),sv->y(),sv->z(),1};
        double xyz[4] = {0,0,0,0};
        int idx = 0;
        for (int i=0;i<3;i++) {
          xyz[i] = 0;
          for (int j=0;j<4;j++) xyz[i] += tfo[idx++] * src[j];
        }
        
        tv->x() = xyz[0];
        tv->y() = xyz[1];
        tv->z() = xyz[2];
      }
    }
  }
}


void GEntity::copyMasterCoordinates() {

  if (_meshMaster != this && affineTransform.size() == 16) {
    
    std::map<MVertex*,MVertex*>::iterator cvIter = correspondingVertices.begin();
    
    for (;cvIter!=correspondingVertices.end();++cvIter) {

      MVertex* tv = cvIter->first;
      MVertex* sv = cvIter->second;
      

      double src[4] = {sv->x(),sv->y(),sv->z(),1};
      double tgt[3] = {0,0,0};

      int idx = 0;
      for (int i=0;i<3;i++) for (int j=0;j<4;j++) tgt[i] += affineTransform[idx++] * src[j];
      
      tv->x() = tgt[0];
      tv->y() = tgt[1];
      tv->z() = tgt[2];
      
    }

    cvIter = correspondingHOPoints.begin();
    
    for (;cvIter!=correspondingHOPoints.end();++cvIter) {

      MVertex* tv = cvIter->first;
      MVertex* sv = cvIter->second;
      
      double src[4] = {sv->x(),sv->y(),sv->z(),1};
      double tgt[3] = {0,0,0};

      int idx = 0;
      for (int i=0;i<3;i++) for (int j=0;j<4;j++) tgt[i] += affineTransform[idx++] * src[j];

      
      tv->x() = tgt[0];
      tv->y() = tgt[1];
      tv->z() = tgt[2];
      
    }

  }
}
