// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GHOST_REGION_H
#define GHOST_REGION_H

#include "GModel.h"
#include "discreteRegion.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MElementCut.h"

class ghostRegion : public discreteRegion {
private:
  int _partition;
  std::map<MElement *, int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;

public:
  ghostRegion(GModel *model, const int num, const int partition)
    : discreteRegion(model, num), _partition(partition), _ghostCells(),
      _saveMesh(false), _haveMesh(false)
  {
  }
  virtual ~ghostRegion()
  {
    if(!_haveMesh) {
      tetrahedra.clear();
      hexahedra.clear();
      prisms.clear();
      pyramids.clear();
      trihedra.clear();
      polyhedra.clear();
      mesh_vertices.clear();
    }
  }
  virtual GeomType geomType() const { return GhostVolume; }
  virtual void setPartition(const int partition) { _partition = partition; }
  virtual int getPartition() const { return _partition; }
  bool saveMesh() const { return _saveMesh; }
  void saveMesh(bool saveMesh) { _saveMesh = saveMesh; }
  bool haveMesh() const { return _haveMesh; }
  void haveMesh(bool haveMesh) { _haveMesh = haveMesh; }
  virtual std::map<MElement *, int> &getGhostCells() { return _ghostCells; }

  void addTetrahedron(MTetrahedron *t, int onWhichPartition)
  {
    GRegion::addTetrahedron(t);
    _ghostCells.insert(std::pair<MElement *, int>(t, onWhichPartition));
    model()->addGhostCells(t, _partition);
  }
  void addHexahedron(MHexahedron *h, int onWhichPartition)
  {
    GRegion::addHexahedron(h);
    _ghostCells.insert(std::pair<MElement *, int>(h, onWhichPartition));
    model()->addGhostCells(h, _partition);
  }
  void addPrism(MPrism *p, int onWhichPartition)
  {
    GRegion::addPrism(p);
    _ghostCells.insert(std::pair<MElement *, int>(p, onWhichPartition));
    model()->addGhostCells(p, _partition);
  }
  void addPyramid(MPyramid *p, int onWhichPartition)
  {
    GRegion::addPyramid(p);
    _ghostCells.insert(std::pair<MElement *, int>(p, onWhichPartition));
    model()->addGhostCells(p, _partition);
  }
  void addPolyhedron(MPolyhedron *p, int onWhichPartition)
  {
    GRegion::addPolyhedron(p);
    _ghostCells.insert(std::pair<MElement *, int>(p, onWhichPartition));
    model()->addGhostCells(p, _partition);
  }
  void addTrihedron(MTrihedron *t, int onWhichPartition)
  {
    GRegion::addTrihedron(t);
    _ghostCells.insert(std::pair<MElement *, int>(t, onWhichPartition));
    model()->addGhostCells(t, _partition);
  }
  void addElement(MElement *e, int onWhichPartition)
  {
    GRegion::addElement(e);
    _ghostCells.insert(std::pair<MElement *, int>(e, onWhichPartition));
    model()->addGhostCells(e, _partition);
  }

  // To make the hidden function visible in ghostRegion
  using discreteRegion::addElement;
  using discreteRegion::addHexahedron;
  using discreteRegion::addPolyhedron;
  using discreteRegion::addPrism;
  using discreteRegion::addPyramid;
  using discreteRegion::addTetrahedron;
  using discreteRegion::addTrihedron;
};

#endif
