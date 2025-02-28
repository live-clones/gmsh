// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Anthony Royer

#ifndef GHOST_EDGE_H
#define GHOST_EDGE_H

#include "GModel.h"
#include "discreteEdge.h"
#include "MLine.h"

class ghostEdge : public discreteEdge {
private:
  int _partition;
  std::map<MElement *, int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;

public:
  ghostEdge(GModel *model, const int num, const int partition)
    : discreteEdge(model, num, nullptr, nullptr), _partition(partition),
      _ghostCells(), _saveMesh(false), _haveMesh(false)
  {
  }
  virtual ~ghostEdge()
  {
    if(!_haveMesh) {
      lines.clear();
      mesh_vertices.clear();
    }
  }
  virtual GeomType geomType() const { return GhostCurve; }
  virtual void setPartition(const int partition) { _partition = partition; }
  virtual int getPartition() const { return _partition; }
  bool saveMesh() const { return _saveMesh; }
  void saveMesh(bool saveMesh) { _saveMesh = saveMesh; }
  bool haveMesh() const { return _haveMesh; }
  void haveMesh(bool haveMesh) { _haveMesh = haveMesh; }
  virtual std::map<MElement *, int> &getGhostCells() { return _ghostCells; }

  void addLine(MLine *l, int onWhichPartition)
  {
    GEdge::addLine(l);
    _ghostCells.insert(std::pair<MElement *, int>(l, onWhichPartition));
    model()->addGhostCells(l, _partition);
  }
  void addElement(MElement *e, int onWhichPartition)
  {
    GEdge::addElement(e);
    _ghostCells.insert(std::pair<MElement *, int>(e, onWhichPartition));
    model()->addGhostCells(e, _partition);
  }

  // To make the hidden function visible in ghostEdge
  using discreteEdge::addElement;
  using discreteEdge::addLine;
};

#endif
