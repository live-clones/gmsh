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
  double _minJac, _maxJac, _minIGE, _minICN;
public:
  data_elementMinMax(MElement *e,
                     double minJ = 2,
                     double maxJ = 0,
                     double minIGE = -1,
                     double minICN = -1)
    : _el(e), _minJac(minJ), _maxJac(maxJ), _minIGE(minIGE), _minICN(minICN) {}
  void setMinS(double r) { _minIGE = r; }
  void setMinI(double r) { _minICN = r; }
  MElement* element() { return _el; }
  double minJ() { return _minJac; }
  double maxJ() { return _maxJac; }
  double minS() { return _minIGE; }
  double minI() { return _minICN; }
};

class GMSH_AnalyseCurvedMeshPlugin : public GMSH_PostPlugin
{
private :
  GModel *_m;
  double _threshold;

  // for 1d, 2d, 3d
  bool _computedJac[3], _computedIGE[3], _computedICN[3];
  bool _PViewJac[3], _PViewIGE[3], _PViewICN[3];

  std::vector<data_elementMinMax> _data;

public :
  GMSH_AnalyseCurvedMeshPlugin()
  {
    _m = NULL;
    _threshold = -1;
    for (int i = 0; i < 3; ++i) {
      _computedJac[i] = false;
      _computedIGE[i] = false;
      _computedICN[i] = false;
      _PViewJac[i] = false;
      _PViewIGE[i] = false;
      _PViewICN [i] = false;
    }
  }
  std::string getName() const { return "AnalyseCurvedMesh"; }
  std::string getShortHelp() const
  {
    return "Compute validity and quality of curved elements.";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Amaury Johnen"; }
  int getNbOptions() const;
  StringXNumber* getOption(int);
  PView* execute(PView *);

private :
  void _computeMinMaxJandValidity(int dim);
  void _computeMinIGE(int dim);
  void _computeMinICN(int dim);
  int _hideWithThreshold(int askedDim, int whichMeasure);
  void _printStatJacobian();
  void _printStatIGE();
  void _printStatICN();
};

#endif
