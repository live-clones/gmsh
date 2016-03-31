// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _ANALYSECURVEDMESH_H_
#define _ANALYSECURVEDMESH_H_

#include "Plugin.h"
#include <vector>
class MElement;

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin();
}

class data_elementMinMax
{
private:
  MElement *_el;
  double _minJ, _maxJ, _minR, _minRR;

public:
  data_elementMinMax(MElement *e,
                       double minJ = 2,
                       double maxJ = 0,
                       double minR = -1,
                       double minRR = -1)
    : _el(e), _minJ(minJ), _maxJ(maxJ), _minR(minR), _minRR(minRR) {}

  void setMinR(double r) {_minR = r;}
  void setMinRR(double r) {_minRR = r;}
  MElement* element() {return _el;}
  double minJ() {return _minJ;}
  double maxJ() {return _maxJ;}
  double minR() {return _minR;}
  double minRR() {return _minRR;}
};

class GMSH_AnalyseCurvedMeshPlugin : public GMSH_PostPlugin
{
private :
  GModel *_m;
  double _threshold, _tol;
  int _computeMetric;

  // for 1d, 2d, 3d
  bool _computedR[3], _computedJ[3], _PViewJ[3], _PViewR[3];
  bool _msgHide;

  std::vector<data_elementMinMax> _data;

public :
  GMSH_AnalyseCurvedMeshPlugin() {
    _m = NULL;
    _threshold = _tol = -1;
    _computeMetric = -1;
    for (int i = 0; i < 3; ++i) {
      _computedR[i] = false;
      _computedJ[i] = false;
      _PViewJ[i] = false;
      _PViewR[i] = false;
    }
    _msgHide = true;
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

  // For testing
  void computeMinJ(MElement *const *el, int numEl, double *minJ, bool *straight) {
    std::vector<data_elementMinMax> save(_data);
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
  void computeMinR(MElement *const *el, int numEl, double *minR, bool *straight);
  void test(MElement *const *el, int numEl, int dim) {
    _tol = 1e-3;
    std::vector<data_elementMinMax> save(_data);
    _data.clear();
    _computeMinMaxJandValidity(el, numEl);

    Msg::Info("aaa");
    Msg::Info("aaa");
    _computeMinR(dim);
    _data = save;
  }

private :
  void _computeMinMaxJandValidity(int dim);
  void _computeMinMaxJandValidity(MElement *const *, int numEl);
  void _computeMinR(int dim);
  bool _hideWithThreshold(int askedDim);
  void _printStatMetric();
  void _printStatJacobian();
};

#endif
