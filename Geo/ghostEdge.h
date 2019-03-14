// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Anthony Royer

#ifndef GHOST_EDGE_H
#define GHOST_EDGE_H

#include "GModel.h"
#include "discreteEdge.h"
#include "MLine.h"

class ghostEdge : public discreteEdge {
private:
  unsigned int _partition;
  std::map<MElement *, unsigned int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;

public:
  ghostEdge(GModel *model, const int num, const unsigned int partition)
    : discreteEdge(model, num, NULL, NULL), _partition(partition),
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

  void addLine(MLine *l, unsigned int onWhichPartition)
  {
    GEdge::addLine(l);
    _ghostCells.insert(
      std::pair<MElement *, unsigned int>(l, onWhichPartition));
    model()->addGhostCells(l, onWhichPartition);
  }
  void addElement(int type, MElement *e, unsigned int onWhichPartition)
  {
    GEdge::addElement(type, e);
    _ghostCells.insert(
      std::pair<MElement *, unsigned int>(e, onWhichPartition));
    model()->addGhostCells(e, onWhichPartition);
  }

  // To make the hidden function visible in ghostEdge
  using discreteEdge::addElement;
  using discreteEdge::addLine;
};

#endif
