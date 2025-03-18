// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ANALYSEMESHQUALITY2_H
#define ANALYSEMESHQUALITY2_H
#include "GmshConfig.h"
#if defined(HAVE_MESH)

#include <map>
#include <vector>
#include "Plugin.h"
#include "GEntity.h" // FIXME necessary?
#include "MElement.h" // FIXME necessary?
class MElement;
class data_elementMinMax2;

extern "C" {
GMSH_Plugin *GMSH_RegisterAnalyseMeshQuality2Plugin();
}

class GMSH_AnalyseMeshQuality2Plugin : public GMSH_PostPlugin {
private:
  class dataGEntities;
  GModel *_m;


#if defined(HAVE_VISUDEV)
  // Pointwise data
  bool _createPwView = 0;
  int _elemNumForPwView = 0;
  bool _pwJac = false, _pwIGE = false, _pwICN = false;
  std::map<int, std::vector<double> > _dataPViewJac;
  std::map<int, std::vector<double> > _dataPViewIGE;
  std::map<int, std::vector<double> > _dataPViewICN;
  int _type2tag[20] = {0};
  int _viewOrder = 0;
#endif

  // for 1d, 2d, 3d
  bool _computedJac[3]{}, _computedIGE[3]{}, _computedICN[3]{};
  bool _pviewJac[3]{}, _pviewIGE[3]{}, _pviewICN[3]{};

  std::vector<data_elementMinMax2> _data;

public:
  GMSH_AnalyseMeshQuality2Plugin()
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
  GMSH_PLUGIN_TYPE getType() const override { return GMSH_MESH_PLUGIN; }
  std::string getName() const override { return "AnalyseMeshQuality2"; }
  std::string getShortHelp() const override
  {
    return "Compute validity and quality of curved elements.";
  }
  std::string getHelp() const override;
  std::string getAuthor() const override { return "Amaury Johnen"; }
  int getNbOptions() const override;
  StringXNumber *getOption(int) override;
  PView *execute(PView *) override;

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

private:
  class dataGEntities {
  private:
    GEntity *_ge;
    //bool computedThisRun; // FIXME necessary?
    std::map<MElement*, size_t> _mapElemToIndex;
    std::vector<double> _minJ, _maxJ, _minDisto, _minAspect;
    int _numVisibleElem;
    // 6 bits of char are used for the following information:
    // - First 3 bits: to say if quantities has been computed
    // - Next 3 bits: to say if the measure has been asked this run (depending
    //                on the plugin parameters restrictToVisibleElements)
    // FIXME or need only 1 bit to say if the element has been asked this run?
    std::vector<char> _computed;

  public:
    explicit dataGEntities(GEntity *ge)
      : _ge(ge), _numVisibleElem(0)
    {
    }
    int getNumVisibleElement() const { return _numVisibleElem; }

    // I separate the computation of each measure because computation can be
    // really heavy and take a a lot of time. Computing the validity is much
    // faster and can help the user to evaluate the time needed to compute the
    // remaining qualities.
    void computeValidity(bool onlyVisible, int recomputePolicy, bool verbose);
    void computeDisto(bool onlyVisible, int recomputePolicy, bool verbose);
    void computeAspect(bool onlyVisible, int recomputePolicy, bool verbose);
    void getValidityValues(std::vector<double> &min, std::vector<double> &max);
    void getDistoValues(std::vector<double> &disto) const;
    void getAspectValues(std::vector<double> &aspect) const;
    void getValues(std::vector<double> *minJ, std::vector<double> *maxJ,
                   std::vector<double> *disto, std::vector<double> *aspect) const;

    // FIXME should i create only one method? bool computeDisto, std::vector<.> *vecDisto)
    //       or just std::vector<.> *vecDisto = nullptr)
  };
};





#endif
#endif
