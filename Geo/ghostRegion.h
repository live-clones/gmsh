// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GHOST_REGION_H_
#define _GHOST_REGION_H_

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
  unsigned int _partitions;
  std::map<MElement*, unsigned int> _ghostCells;
  bool _saveMesh;
  bool _haveMesh;
public:
  ghostRegion(GModel *model, const int num, const unsigned int partitions)
  : discreteRegion(model, num), _partitions(partitions), _ghostCells(), _saveMesh(false),
  _haveMesh(false) {}
  virtual ~ghostRegion()
  {
    if(!_haveMesh){
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
  virtual void setPartition(const unsigned int partitions) { _partitions = partitions; }
  virtual unsigned int getPartition() const { return _partitions; }
  
  bool saveMesh() const { return _saveMesh; }
  void saveMesh(bool saveMesh) { _saveMesh = saveMesh; }
  bool haveMesh() const { return _haveMesh; }
  void haveMesh(bool haveMesh) { _haveMesh = haveMesh; }
  
  virtual std::map<MElement*, unsigned int> &getGhostCells() { return _ghostCells; }
  
  void addTetrahedron(MTetrahedron *t, unsigned int onWhichPartition)
  {
    GRegion::addTetrahedron(t);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(t,onWhichPartition));
    model()->addGhostCells(t,onWhichPartition);
  }
  void addHexahedron(MHexahedron *h, unsigned int onWhichPartition)
  {
    GRegion::addHexahedron(h);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(h,onWhichPartition));
    model()->addGhostCells(h,onWhichPartition);
  }
  void addPrism(MPrism *p, unsigned int onWhichPartition)
  {
    GRegion::addPrism(p);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(p,onWhichPartition));
    model()->addGhostCells(p,onWhichPartition);
  }
  void addPyramid(MPyramid *p, unsigned int onWhichPartition)
  {
    GRegion::addPyramid(p);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(p,onWhichPartition));
    model()->addGhostCells(p,onWhichPartition);
  }
  void addPolyhedron(MPolyhedron *p, unsigned int onWhichPartition)
  {
    GRegion::addPolyhedron(p);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(p,onWhichPartition));
    model()->addGhostCells(p,onWhichPartition);
  }
  void addTrihedron(MTrihedron *t, unsigned int onWhichPartition)
  {
    GRegion::addTrihedron(t);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(t,onWhichPartition));
    model()->addGhostCells(t,onWhichPartition);
  }
  void addElement(int type, MElement *e, unsigned int onWhichPartition)
  {
    GRegion::addElement(type, e);
    _ghostCells.insert(std::pair<MElement*, unsigned int>(e,onWhichPartition));
    model()->addGhostCells(e,onWhichPartition);
  }
};

#endif
