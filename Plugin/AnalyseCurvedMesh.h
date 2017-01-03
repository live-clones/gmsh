// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
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
  double _minJ, _maxJ, _minS, _minI;
public:
  data_elementMinMax(MElement *e,
                     double minJ = 2,
                     double maxJ = 0,
                     double minS = -1,
                     double minI = -1)
    : _el(e), _minJ(minJ), _maxJ(maxJ), _minS(minS), _minI(minI) {}
  void setMinS(double r) { _minS = r; }
  void setMinI(double r) { _minI = r; }
  MElement* element() { return _el; }
  double minJ() { return _minJ; }
  double maxJ() { return _maxJ; }
  double minS() { return _minS; }
  double minI() { return _minI; }
};

class GMSH_AnalyseCurvedMeshPlugin : public GMSH_PostPlugin
{
private :
  GModel *_m;
  double _threshold;

  // for 1d, 2d, 3d
  bool _computedJ[3], _computedS[3], _computedI[3];
  bool _PViewJ[3], _PViewS[3], _PViewI[3];

  std::vector<data_elementMinMax> _data;

public :
  GMSH_AnalyseCurvedMeshPlugin()
  {
    _m = NULL;
    _threshold = -1;
    for (int i = 0; i < 3; ++i) {
      _computedJ[i] = false;
      _computedS[i] = false;
      _computedI[i] = false;
      _PViewJ[i] = false;
      _PViewS[i] = false;
      _PViewI[i] = false;
    }
  }
  std::string getName() const { return "AnalyseCurvedMesh"; }
  std::string getShortHelp() const
  {
    return "Compute bounds on Jacobian and metric quality.";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Amaury Johnen"; }
  int getNbOptions() const;
  StringXNumber* getOption(int);
  PView* execute(PView *);

  // For testing
  void computeMinJ(MElement *const *el, int numEl, double *minJ, bool *straight)
  {
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
        straight[i] = _data[i].maxJ() - _data[i].minJ() < 1e-5;
      }
    }
    _data = save;
  }
  void computeMinR(MElement *const *el, int numEl, double *minR, bool *straight);
  void test(MElement *const *el, int numEl, int dim)
  {
    std::vector<data_elementMinMax> save(_data);
    _data.clear();
    _computeMinMaxJandValidity(el, numEl);

    Msg::Info("aaa");
    Msg::Info("aaa");
    _computeMinIsotropy(dim);
    _data = save;
  }

private :
  void _computeMinMaxJandValidity(int dim);
  void _computeMinMaxJandValidity(MElement *const *, int numEl);
  void _computeMinScaledJac(int dim);
  void _computeMinIsotropy(int dim);
  int _hideWithThreshold(int askedDim, int whichMeasure);
  void _printStatJacobian();
  void _printStatScaledJac();
  void _printStatIsotropy();
};

#endif
