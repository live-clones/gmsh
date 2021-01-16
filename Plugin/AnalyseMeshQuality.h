// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ANALYSEMESHQUALITY_H
#define ANALYSEMESHQUALITY_H

#include "Plugin.h"
#include <vector>
class MElement;

extern "C" {
GMSH_Plugin *GMSH_RegisterAnalyseMeshQualityPlugin();
}

class data_elementMinMax {
private:
  MElement *_el;
  double _minJac, _maxJac, _minIGE, _minICN;

public:
  data_elementMinMax(MElement *e, double minJ = 2, double maxJ = 0,
                     double minIGE = -1, double minICN = -1)
    : _el(e), _minJac(minJ), _maxJac(maxJ), _minIGE(minIGE), _minICN(minICN)
  {
  }
  void setMinS(double r) { _minIGE = r; }
  void setMinI(double r) { _minICN = r; }
  MElement *element() { return _el; }
  double minJ() { return _minJac; }
  double maxJ() { return _maxJac; }
  double minS() { return _minIGE; }
  double minI() { return _minICN; }
};

class GMSH_AnalyseMeshQualityPlugin : public GMSH_PostPlugin {
private:
  GModel *_m;

#if defined(HAVE_VISUDEV)
  // Pointwise data
  int _numElementToScan;
  bool _pwJac, _pwIGE, _pwICN;
  std::map<int, std::vector<double> > _dataPViewJac;
  std::map<int, std::vector<double> > _dataPViewIGE;
  std::map<int, std::vector<double> > _dataPViewICN;
  int _type2tag[20] = {0};
  int _viewOrder = 0;
#endif

  // for 1d, 2d, 3d
  bool _computedJac[3], _computedIGE[3], _computedICN[3];
  bool _pviewJac[3], _pviewIGE[3], _pviewICN[3];

  std::vector<data_elementMinMax> _data;

public:
  GMSH_AnalyseMeshQualityPlugin()
  {
    _m = nullptr;
    for(int i = 0; i < 3; ++i) {
      _computedJac[i] = false;
      _computedIGE[i] = false;
      _computedICN[i] = false;
      _pviewJac[i] = false;
      _pviewIGE[i] = false;
      _pviewICN[i] = false;
    }
  }
  std::string getName() const { return "AnalyseMeshQuality"; }
  std::string getShortHelp() const
  {
    return "Compute validity and quality of curved elements.";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Amaury Johnen"; }
  int getNbOptions() const;
  StringXNumber *getOption(int);
  PView *execute(PView *);

private:
  void _computeMinMaxJandValidity(int dim);
  void _computeMinIGE(int dim);
  void _computeMinICN(int dim);
  int _hideWithThreshold(int askedDim, int whichMeasure, double threshold,
                         bool greater);
  void _printStatJacobian();
  void _printStatIGE();
  void _printStatICN();
  void _clear(int askedDim);

#if defined(HAVE_VISUDEV)
  void _computePointwiseQuantities(MElement *,
                                   const fullMatrix<double> *normals);
  void _createPViewPointwise();
  void _setInterpolationMatrices(PView *);
#endif
};

#endif
