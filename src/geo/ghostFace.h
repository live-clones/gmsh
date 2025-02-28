// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Anthony Royer

#ifndef GHOST_FACE_H
#define GHOST_FACE_H

#include "GModel.h"
#include "discreteFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MElementCut.h"

class ghostFace : public discreteFace {
private:
  int _partition;
  std::map<MElement *, int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;

public:
  ghostFace(GModel *model, const int num, const int partition)
    : discreteFace(model, num), _partition(partition), _ghostCells(),
      _saveMesh(false), _haveMesh(false)
  {
  }
  virtual ~ghostFace()
  {
    if(!_haveMesh) {
      triangles.clear();
      quadrangles.clear();
      polygons.clear();
      mesh_vertices.clear();
    }
  }
  virtual GeomType geomType() const { return GhostSurface; }
  virtual void setPartition(const int partition) { _partition = partition; }
  virtual int getPartition() const { return _partition; }
  bool saveMesh() const { return _saveMesh; }
  void saveMesh(bool saveMesh) { _saveMesh = saveMesh; }
  bool haveMesh() const { return _haveMesh; }
  void haveMesh(bool haveMesh) { _haveMesh = haveMesh; }
  virtual std::map<MElement *, int> &getGhostCells() { return _ghostCells; }

  virtual void addTriangle(MTriangle *t, int onWhichPartition)
  {
    GFace::addTriangle(t);
    _ghostCells.insert(std::pair<MElement *, int>(t, onWhichPartition));
    model()->addGhostCells(t, _partition);
  }
  virtual void addQuadrangle(MQuadrangle *q, int onWhichPartition)
  {
    GFace::addQuadrangle(q);
    _ghostCells.insert(std::pair<MElement *, int>(q, onWhichPartition));
    model()->addGhostCells(q, _partition);
  }
  virtual void addPolygon(MPolygon *p, int onWhichPartition)
  {
    GFace::addPolygon(p);
    _ghostCells.insert(std::pair<MElement *, int>(p, onWhichPartition));
    model()->addGhostCells(p, _partition);
  }
  virtual void addElement(MElement *e, int onWhichPartition)
  {
    GFace::addElement(e);
    _ghostCells.insert(std::pair<MElement *, int>(e, onWhichPartition));
    model()->addGhostCells(e, _partition);
  }

  // To make the hidden function visible in ghostFace
  using discreteFace::addElement;
  using discreteFace::addQuadrangle;
  using discreteFace::addTriangle;
};

#endif
