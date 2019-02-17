// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _OCC_MESH_ATTRIBUTES_
#define _OCC_MESH_ATTRIBUTES_

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "OS.h"
#include "rtree.h"

#if defined(HAVE_OCC)

#include <Bnd_Box.hxx>
#include <BRepBndLib.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepTools.hxx>

class OCCMeshAttributes {
private:
  int _dim;
  TopoDS_Shape _shape;
  double _meshSize;
  ExtrudeParams *_extrude;
  int _sourceDim;
  TopoDS_Shape _sourceShape;

public:
  OCCMeshAttributes() : _dim(-1), _meshSize(MAX_LC), _extrude(0), _sourceDim(-1)
  {
  }
  OCCMeshAttributes(int dim, TopoDS_Shape shape)
    : _dim(dim), _shape(shape), _meshSize(MAX_LC), _extrude(0), _sourceDim(-1)
  {
  }
  OCCMeshAttributes(int dim, TopoDS_Shape shape, double size)
    : _dim(dim), _shape(shape), _meshSize(size), _extrude(0), _sourceDim(-1)
  {
  }
  OCCMeshAttributes(int dim, TopoDS_Shape shape, ExtrudeParams *e,
                    int sourceDim, TopoDS_Shape sourceShape)
    : _dim(dim), _shape(shape), _meshSize(MAX_LC), _extrude(e),
      _sourceDim(sourceDim), _sourceShape(sourceShape)
  {
  }
  ~OCCMeshAttributes() {}
  int getDim() { return _dim; }
  TopoDS_Shape getShape() { return _shape; }
  double getMeshSize() { return _meshSize; }
  ExtrudeParams *getExtrudeParams() { return _extrude; }
  int getSourceDim() { return _sourceDim; }
  TopoDS_Shape getSourceShape() { return _sourceShape; }
};

// mesh attributes are stored according to the center of their associated shape
// bounding box; this allows to efficiently search for potential matches, even
// if the actual underlying shape has been changed (e.g. through boolean
// fragments)
class OCCMeshAttributesRTree {
private:
  RTree<OCCMeshAttributes *, double, 3, double> *_rtree[4];
  std::vector<OCCMeshAttributes *> _all;
  double _tol;
  static bool rtree_callback(OCCMeshAttributes *v, void *ctx)
  {
    std::vector<OCCMeshAttributes *> *out =
      static_cast<std::vector<OCCMeshAttributes *> *>(ctx);
    out->push_back(v);
    return true;
  }

public:
  OCCMeshAttributesRTree(double tolerance = 1.e-8)
  {
    for(int dim = 0; dim < 4; dim++)
      _rtree[dim] = new RTree<OCCMeshAttributes *, double, 3, double>();
    _tol = tolerance;
  }
  ~OCCMeshAttributesRTree()
  {
    clear();
    for(int dim = 0; dim < 4; dim++) delete _rtree[dim];
  }
  void clear()
  {
    for(int dim = 0; dim < 4; dim++) _rtree[dim]->RemoveAll();
    for(std::size_t i = 0; i < _all.size(); i++) delete _all[i];
    _all.clear();
  }
  void print(const std::string &fileName = "")
  {
    FILE *fp = stdout;
    if(fileName.size()) {
      fp = Fopen(fileName.c_str(), "w");
      if(!fp) {
        Msg::Error("Could not open file '%s'", fileName.c_str());
        return;
      }
    }
    fprintf(fp, "View(\"rtree mesh sizes\"){\n");
    for(std::size_t i = 0; i < _all.size(); i++) {
      if(_all[i]->getDim() != 0) continue;
      if(_all[i]->getMeshSize() == MAX_LC) continue;
      gp_Pnt pnt = BRep_Tool::Pnt(TopoDS::Vertex(_all[i]->getShape()));
      fprintf(fp, "SP(%g,%g,%g){%g};\n", pnt.X(), pnt.Y(), pnt.Z(),
              _all[i]->getMeshSize());
    }
    fprintf(fp, "};\n");
    if(fileName.size()) fclose(fp);
  }
  void insert(OCCMeshAttributes *v)
  {
    _all.push_back(v);
    if(v->getDim() < 0 || v->getDim() > 3) return;
    Bnd_Box box;
    try {
      BRepBndLib::Add(v->getShape(), box);
      if(box.IsVoid()) {
        Msg::Debug("Inserting (null or degenerate) shape with void bounding box");
        // BRepTools::Dump(v->getShape(), std::cout);
        return;
      }
    } catch(Standard_Failure &err) {
      Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
      return;
    }
    double xmin, ymin, zmin, xmax, ymax, zmax;
    box.Get(xmin, ymin, zmin, xmax, ymax, zmax);
    double x = 0.5 * (xmin + xmax);
    double y = 0.5 * (ymin + ymax);
    double z = 0.5 * (zmin + zmax);
    double bmin[3] = {x - _tol, y - _tol, z - _tol};
    double bmax[3] = {x + _tol, y + _tol, z + _tol};
    _rtree[v->getDim()]->Insert(bmin, bmax, v);
  }
  void remove(OCCMeshAttributes *v)
  {
    if(v->getDim() < 0 || v->getDim() > 3) return;
    Bnd_Box box;
    try {
      BRepBndLib::Add(v->getShape(), box);
      if(box.IsVoid()) {
        Msg::Debug("Removing (null or degenerate) shape with void bounding box");
        // BRepTools::Dump(v->getShape(), std::cout);
        return;
      }
    } catch(Standard_Failure &err) {
      Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
      return;
    }
    double xmin, ymin, zmin, xmax, ymax, zmax;
    box.Get(xmin, ymin, zmin, xmax, ymax, zmax);
    double x = 0.5 * (xmin + xmax);
    double y = 0.5 * (ymin + ymax);
    double z = 0.5 * (zmin + zmax);
    double bmin[3] = {x - _tol, y - _tol, z - _tol};
    double bmax[3] = {x + _tol, y + _tol, z + _tol};
    _rtree[v->getDim()]->Remove(bmin, bmax, v);
  }
  void find(int dim, const TopoDS_Shape &shape,
            std::vector<OCCMeshAttributes *> &attr, bool requireMeshSize,
            bool requireExtrudeParams, bool excludeSame)
  {
    attr.clear();
    if(dim < 0 || dim > 3) return;
    Bnd_Box box;
    try {
      BRepBndLib::Add(shape, box);
      if(box.IsVoid()) {
        Msg::Debug(
          "Searching for (null or degenerate) shape with void bounding box");
        return;
      }
    } catch(Standard_Failure &err) {
      Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
      return;
    }
    double xmin, ymin, zmin, xmax, ymax, zmax;
    box.Get(xmin, ymin, zmin, xmax, ymax, zmax);
    double x = 0.5 * (xmin + xmax);
    double y = 0.5 * (ymin + ymax);
    double z = 0.5 * (zmin + zmax);
    double bmin[3] = {x - _tol, y - _tol, z - _tol};
    double bmax[3] = {x + _tol, y + _tol, z + _tol};
    std::vector<OCCMeshAttributes *> tmp;
    _rtree[dim]->Search(bmin, bmax, rtree_callback, &tmp);
    Msg::Debug("OCCRTree found %d matches at (%g,%g,%g) in tree of size %d",
               (int)tmp.size(), x, y, z, (int)_all.size());
    if(tmp.empty()) { // no match
      return;
    }
    if(!excludeSame) {
      for(std::size_t i = 0; i < tmp.size(); i++) {
        if(requireMeshSize && tmp[i]->getMeshSize() == MAX_LC) continue;
        if(requireExtrudeParams && !tmp[i]->getExtrudeParams()) continue;
        if(shape.IsSame(tmp[i]->getShape())) { // exact match: same shape
          attr.push_back(tmp[i]);
          Msg::Debug("OCCRTree exact match");
          return;
        }
      }
    }
    // potential matches based on bounding box
    for(std::size_t i = 0; i < tmp.size(); i++) {
      if(requireMeshSize && tmp[i]->getMeshSize() == MAX_LC) continue;
      if(requireExtrudeParams && !tmp[i]->getExtrudeParams()) continue;
      Bnd_Box box2;
      BRepBndLib::Add(tmp[i]->getShape(), box2);
      if(box.Distance(box2) < _tol) {
        attr.push_back(tmp[i]);
      }
    }
    Msg::Debug("OCCRtree %d matches after bounding box filtering",
               (int)attr.size());
  }
  double getMeshSize(int dim, TopoDS_Shape shape)
  {
    std::vector<OCCMeshAttributes *> attr;
    find(dim, shape, attr, true, false, false);
    for(std::size_t i = 0; i < attr.size(); i++) {
      if(attr[i]->getMeshSize() < MAX_LC) return attr[i]->getMeshSize();
    }
    return MAX_LC;
  }
  ExtrudeParams *getExtrudeParams(int dim, TopoDS_Shape shape, int &sourceDim,
                                  TopoDS_Shape &sourceShape)
  {
    std::vector<OCCMeshAttributes *> attr;
    find(dim, shape, attr, false, true, false);
    for(std::size_t i = 0; i < attr.size(); i++) {
      if(attr[i]->getExtrudeParams()) {
        sourceDim = attr[i]->getSourceDim();
        sourceShape = attr[i]->getSourceShape();
        return attr[i]->getExtrudeParams();
      }
    }
    return 0;
  }
  void getSimilarShapes(int dim, TopoDS_Shape shape,
                        std::vector<TopoDS_Shape> &other)
  {
    std::vector<OCCMeshAttributes *> attr;
    find(dim, shape, attr, false, false, true);
    for(std::size_t i = 0; i < attr.size(); i++) {
      TopoDS_Shape s = attr[i]->getShape();
      if(!s.IsNull()) other.push_back(s);
    }
  }
};

#endif
#endif
