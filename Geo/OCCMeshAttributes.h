// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _OCC_MESH_ATTRIBUTES_
#define _OCC_MESH_ATTRIBUTES_

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "rtree.h"

#if defined(HAVE_OCC)

#include <Bnd_Box.hxx>
#include <BRepBndLib.hxx>
#include <TopoDS_Shape.hxx>

class OCCMeshAttr {
 private:
  int dim;
  TopoDS_Shape _shape;
  Bnd_Box _box;
  double _meshSize;
  ExtrudeParams *_extrude;
  TopoDS_Shape _source;
  Bnd_Box _sourceBox;
 public:
  OCCMeshAttr() : _dim(-1), _meshSize(MAX_LC), _extrude(0) {}
  OCCMeshAttr(int dim, TopoDS_Shape shape, double size)
    : _dim(dim), _shape(shape), _meshSize(size), _extrude(0)
  {
    BRepBndLib::Add(shape, _box);
  }
  OCCMeshAttr(int dim, TopoDS_Shape shape, ExtrudeParams *e, TopoDS_Shape source)
    : _dim(dim), _shape(shape), _meshSize(MAX_LC), _extrude(e), _source(source)
  {
    BRepBndLib::Add(shape, _box);
    BRepBndLib::Add(source, _sourceBox);
  }
  ~OCCMeshAttr(){}
  TopoDS_Shape getDim(){ return _dim; }
  TopoDS_Shape getShape(){ return _shape; }
  Bnd_Box getShapeBox(){ return _box; }
  double getMeshSize(){ return _meshSize; }
  ExtrudeParams *getExtrudeParam(){ return _extrude; }
  TopoDS_Shape getSourceShape(){ return _source; }
  Bnd_Box getSourceShapeBox(){ return _sourceBox; }
};

class OCCMeshAttributes{
 private:
  RTree<OCCMeshAttr*, double, 3, double> *_rtree[4];
  std::vector<OCCMeshAttr*> _all;
  double _tol;
  static bool rtree_callback(OCCMeshAttr *v, void *ctx)
  {
    std::vector<OCCMeshAttr*> *out = static_cast<std::vector<OCCMeshAttr*>*>(ctx);
    out->push_back(v);
    return true;
  }
 public:
  OCCMeshAttributes(double tolerance = 1.e-8)
  {
    for(int dim = 0; dim < 4; dim++)
      _rtree[dim] = new RTree<OCCMeshAttr*, double, 3, double>();
    _tol = tolerance;
  }
  ~OCCMeshAttributes()
  {
    clear();
    for(int dim = 0; dim < 4; dim++)
      delete _rtree[dim];
  }
  void clear()
  {
    for(int dim = 0; dim < 4; dim++)
      _rtree[dim]->RemoveAll();
    for(unsigned int i = 0; i < _all.size(); i++)
      delete _all[i];
    _all.clear();
  }
  void insert(OCCMeshAttr *v)
  {
    _all.push_back(v);
    if(v->getDim() < 0 || v->getDim() > 3) return;
    double xmin, ymin, zmin, xmax, ymax, zmax;
    v->getBox().Get(xmin, ymin, zmin, xmax, ymax, zmax);
    double x = 0.5 * (xmin + xmax);
    double y = 0.5 * (ymin + ymax);
    double z = 0.5 * (zmin + zmax);
    double bmin[3] = {x - _tol, y - _tol, z - _tol};
    double bmax[3] = {x + _tol, y + _tol, z + _tol};
    _rtree[v->getDim()]->Insert(bmin, bmax, v);
  }
  void find(TopoDS_Shape shape, std::vector<OCCMeshAttr*> &attr)
  {
    attribs.clear();

    Bnd_Box box;
    BRepBndLib::Add(shape(), box);
    double xmin, ymin, zmin, xmax, ymax, zmax;
    box.Get(xmin, ymin, zmin, xmax, ymax, zmax);
    double x = 0.5 * (xmin + xmax);
    double y = 0.5 * (ymin + ymax);
    double z = 0.5 * (zmin + zmax);
    double bmin[3] = {x - _tol, y - _tol, z - _tol};
    double bmax[3] = {x + _tol, y + _tol, z + _tol};
    std::vector<OCCMeshAttr*> tmp
    _rtree->Search(bmin, bmax, rtree_callback, &tmp);
    printf("found %d matches in rtree of size %d\n", tmp.size(), _all->size());
    if(tmp.empty()){ // no match
      return;
    }
    for(unsigned int i = 0; i < tmp.size(); i++){
      if(shape.IsSame(tmp[i]->getShape())){ // exact match: same shape
        attrib.push_back(tmp[i]);
        return;
      }
    }
    // potential matches based on bounding box
    gp_Pnt pmin1 = box.CornerMin(), pmax1 = box.CornerMax();
    for(unsigned int i = 0; i < tmp.size(); i++){
      Bnd_Box box2;
      BRepBndLib::Add(tmp[i]->getShape(), box2);
      gp_Pnt pmin2 = box2.CornerMin(), pmax2 = box2.CornerMax();
      if(pmin1.Distance(pmin2) < CTX::instance()->geom.tolerance &&
         pmax1.Distance(pmax2) < CTX::instance()->geom.tolerance){
        attribs.push_back(tmp[i]);
      }
    }
    printf("-> %d matches after filtering", attribs.size());
  }
  double getMeshSize(TopoDS_Shape shape)
  {
    std::vector<OCCMeshAttr*> attr;
    find(shape, attr);
    for(unsigned int i = 0; i < attr.size(); i++){
      if(attr[i]->getMeshSize() < MAX_LC)
        return attr[i]->getMeshSize();
    }
    return MAX_LC;
  }
};

#endif
#endif
