// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
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
  unsigned int _partition;
  std::map<MElement *, unsigned int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;

public:
  ghostFace(GModel *model, const int num, const unsigned int partition)
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
  virtual void setPartition(const unsigned int partition)
  {
    _partition = partition;
  }
  virtual unsigned int getPartition() const { return _partition; }
  bool saveMesh() const { return _saveMesh; }
  void saveMesh(bool saveMesh) { _saveMesh = saveMesh; }
  bool haveMesh() const { return _haveMesh; }
  void haveMesh(bool haveMesh) { _haveMesh = haveMesh; }
  virtual std::map<MElement *, unsigned int> &getGhostCells()
  {
    return _ghostCells;
  }

  virtual void addTriangle(MTriangle *t, unsigned int onWhichPartition)
  {
    GFace::addTriangle(t);
    _ghostCells.insert(
      std::pair<MElement *, unsigned int>(t, onWhichPartition));
    model()->addGhostCells(t, onWhichPartition);
  }
  virtual void addQuadrangle(MQuadrangle *q, unsigned int onWhichPartition)
  {
    GFace::addQuadrangle(q);
    _ghostCells.insert(
      std::pair<MElement *, unsigned int>(q, onWhichPartition));
    model()->addGhostCells(q, onWhichPartition);
  }
  virtual void addPolygon(MPolygon *p, unsigned int onWhichPartition)
  {
    GFace::addPolygon(p);
    _ghostCells.insert(
      std::pair<MElement *, unsigned int>(p, onWhichPartition));
    model()->addGhostCells(p, onWhichPartition);
  }
  virtual void addElement(int type, MElement *e, unsigned int onWhichPartition)
  {
    GFace::addElement(type, e);
    _ghostCells.insert(
      std::pair<MElement *, unsigned int>(e, onWhichPartition));
    model()->addGhostCells(e, onWhichPartition);
  }

  // To make the hidden function visible in ghostFace
  using discreteFace::addElement;
  using discreteFace::addQuadrangle;
  using discreteFace::addTriangle;
};

#endif
