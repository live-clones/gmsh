// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _ANALYSECURVEDMESH_H_
#define _ANALYSECURVEDMESH_H_

#include "Plugin.h"
#include "JacobianBasis.h"
#include "MetricBasis.h"
#include "MElement.h"

#include <vector>

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin();
}

class CurvedMeshPluginData
{
private:
  MElement *_el;
  double _minJ, _maxJ, _minR;

public:
  CurvedMeshPluginData(MElement *e,
                       double minJ = 2,
                       double maxJ = 0,
                       double minR = -1)
    : _el(e), _minJ(minJ), _maxJ(maxJ), _minR(minR) {}

  void setMinR(double r) {_minR = r;}
  MElement* element() {return _el;}
  double minJ() {return _minJ;}
  double maxJ() {return _maxJ;}
  double minR() {return _minR;}
};

class GMSH_AnalyseCurvedMeshPlugin : public GMSH_PostPlugin
{
private :
  int _dim;
  GModel *_m;
  double _threshold, _tol;
  int _numPView, _computeMetric;
  bool _recompute;

  bool _computedR3D, _computedR2D;
  bool _computedJ3D, _computedJ2D, _computedJ1D;
  bool _1PViewJ, _2PViewJ, _1PViewR, _2PViewR;
  bool _msgHide;

  std::vector<CurvedMeshPluginData> _data;

public :
  GMSH_AnalyseCurvedMeshPlugin() {
    _computedR3D = false;
    _computedR2D = false;
    _computedJ3D = false;
    _computedJ2D = false;
    _computedJ1D = false;
    _msgHide = true;
    _1PViewJ = false;
    _2PViewJ = false;
    _1PViewR = false;
    _2PViewR = false;
  }
  std::string getName() const { return "AnalyseCurvedMesh"; }
  std::string getShortHelp() const {
    return "Compute bounds on Jacobian and metric quality.";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Amaury Johnen"; }
  int getNbOptions() const;
  StringXNumber *getOption(int);
  PView *execute(PView *);
  void setTol(double tol) {_tol = tol;}
  void computeMinJ(MElement *const *el, int numEl, double *minJ, bool *straight) {
    std::vector<CurvedMeshPluginData> save(_data);
    _data.clear();
    _computeMinMaxJandValidity(el, numEl);
    if (minJ) {
      for (unsigned int i = 0; i < _data.size(); ++i) {
        minJ[i] = _data[i].minJ();
      }
    }
    if (straight) {
      for (unsigned int i = 0; i < _data.size(); ++i) {
        straight[i] = _data[i].maxJ() - _data[i].minJ() < _tol * 1e-1;
      }
    }
    _data = save;
  }

private :
  void _computeMinMaxJandValidity();
  void _computeMinMaxJandValidity(MElement *const *, int numEl);
  void _computeMinR();
  bool _hideWithThreshold();
  void _printStatMetric();
  void _printStatJacobian();
};

#endif
