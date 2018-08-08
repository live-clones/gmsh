// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Anthony Royer

#ifndef _GHOST_FACE_H_
#define _GHOST_FACE_H_

#include "GModel.h"
#include "discreteFace.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MElementCut.h"

class ghostFace : public discreteFace {
private:
  unsigned int _partitions;
  std::map<MElement *, unsigned int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;

public:
  ghostFace(GModel *model, const int num, const unsigned int partitions)
    : discreteFace(model, num), _partitions(partitions), _ghostCells(),
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
  virtual void setPartition(const unsigned int partitions)
  {
    _partitions = partitions;
  }
  virtual unsigned int getPartition() const { return _partitions; }
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
