// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GHOST_EDGE_H_
#define _GHOST_EDGE_H_

#include "GModel.h"
#include "discreteEdge.h"
#include "MLine.h"

class ghostEdge : public discreteEdge {
private:
  unsigned int _partitions;
  std::map<MElement*, unsigned int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;
public:
  ghostEdge(GModel *model, const int num, const unsigned int partitions)
  : discreteEdge(model, num, NULL, NULL), _partitions(partitions), _ghostCells(), _saveMesh(false),
    _haveMesh(false) {}
  virtual ~ghostEdge()
  {
    if(!_haveMesh){
      lines.clear();
      mesh_vertices.clear();
    }
  }
  virtual GeomType geomType() const { return GhostCurve; }
  virtual void setPartition(const unsigned int partitions) { _partitions = partitions; }
  virtual unsigned int getPartition() const { return _partitions; }
  
  bool saveMesh() const { return _saveMesh; }
  void saveMesh(bool saveMesh) { _saveMesh = saveMesh; }
  bool haveMesh() const { return _haveMesh; }
  void haveMesh(bool haveMesh) { _haveMesh = haveMesh; }
  
  virtual std::map<MElement*, unsigned int> &getGhostCells() { return _ghostCells; }
  
  // To make the hidden function visible in ghostEdge
  using GEdge::addLine;
  using GEdge::addElement;
  
  void addLine(MLine *l, unsigned int onWhichPartition)
  {
    GEdge::addLine(l);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(l,onWhichPartition));
    model()->addGhostCells(l,onWhichPartition);
  }
  void addElement(int type, MElement *e, unsigned int onWhichPartition)
  {
    GEdge::addElement(type, e);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(e,onWhichPartition));
    model()->addGhostCells(e,onWhichPartition);
  }
};

#endif
