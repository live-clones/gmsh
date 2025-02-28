// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FRAME_SOLVER_H
#define FRAME_SOLVER_H

class GVertex;

#include <map>
#include <string>
#include "PView.h"
#include "dofManager.h"
#include "fullMatrix.h"
#include "MLine.h"

struct gmshBeam2d {
  MLine *_element;
  double _i, _a, _e, _l;
  bool _rigidNodes[2];
  double _forceVector[6];
  double _displacement[6];
  int _rotationTags[2];
  fullMatrix<double> _stiffness;
  gmshBeam2d(MLine *l, double E, double I, double A, int r[2])
    : _element(l), _i(I), _a(A), _e(E)
  {
    _l = distance(_element->getVertex(0), _element->getVertex(1));
    _rotationTags[0] = _rotationTags[1] = 0;
    _rigidNodes[0] = r[0];
    _rigidNodes[1] = r[1];
    for(int i = 0; i < 6; i++) _displacement[i] = 0.;
  }
  inline bool isRigid(MVertex *v) const
  {
    return _element->getVertex(0) == v ? _rigidNodes[0] : _rigidNodes[1];
  }
  inline void setRotationTag(MVertex *v, int tag)
  {
    _element->getVertex(0) == v ? _rotationTags[0] = tag :
                                  _rotationTags[1] = tag;
  }
};

struct gmshFixation {
  GVertex *_vertex;
  int _direction;
  double _value;
  gmshFixation(GVertex *v, int d, double val)
    : _vertex(v), _direction(d), _value(val)
  {
  }
};

// a solver that computes equilibriums of frames...
class frameSolver2d {
  dofManager<double> *pAssembler;
  std::vector<gmshBeam2d> _beams;
  std::vector<std::pair<GVertex *, std::vector<double> > > _nodalForces;
  std::vector<gmshFixation> _fixations;
  GModel *_myModel;
  void computeStiffnessMatrix(int iBeam, fullMatrix<double> &K);
  void createDofs();
  void computeRotationTags();
  void addBeamsOrBars(const std::vector<int> &modelEdges, double E, double I,
                      double A, int r[2]);

public:
  frameSolver2d(GModel *myModel);
  void addBeams(const std::vector<int> &modelEdges, double E, double I,
                double A);
  void addBars(const std::vector<int> &modelEdges, double E, double I,
               double A);
  void addNodalForces(const std::vector<int> &modelVertices,
                      const std::vector<double> &force);
  void addFixations(const std::vector<int> &dirs,
                    const std::vector<int> &modelVertices, double value);
  void exportFrameData(const char *displ, const char *M);
  void solve();
};

#endif
