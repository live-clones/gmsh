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



// NOTE Workflow
//  0) - If freeData-NothingElse, clear all data.
//     - If freeData-NothingElse or no checkValidity/compute*, return.
//  1) Loop over all GEntities of considered dimension (dep. dimensionPolicy):
//     a) check that GEntity still exists (NB: GModel::list)
//     b) Clear data if needed (dep. recomputePolicy)
//     c) Count and set flags:
//        - Count the # of element that will be checked for each measure
//        - Set flags to say which element to compute
//        (dep. restrictToVisibleElements and restrictToCurvedElements)
//  2) Compute Validity if needed (dep. skipPreventiveValidityCheck) for 2D,
//     then 3D. Update flags. Gather values minJ, maxJ.
//  3) Compute Disto if needed, then Aspect if needed. For each: 2D, then 3D.
//     Update flags. Gather values of measures.
//  4) Process obtained quantities and print stats (dep.
//     $$$whichPercentileToCompute$$$)
//  5) If hideElements is on:
//     a) If hidingCriterion=1,2, compute the threshold in terms of quality
//     b) Loop over GEntities to hide.
//  6) Do createElementsView and/or createPlotView (dep. $$$percentilePlot$$$)
//     Setting one of them to true does not guarantee the creation of a new
//     PView. The plugin try to avoid the creation of identical PViews.
//     Here is what is taken account:
//     - If the PView is a Plot and forceNewPlotView=true, always (re)create
//     - If the PView do not exists (i.e. _views[n] == nullptr) or if it has
//       been deleted by the user (PView removed from PView::list), create.
//     - If the PView exists, _dataChangedSinceCreation[n] is checked. If
//       false, the PView is recreated, otherwise not.
//  FIXME What about changed visibility of elements?
//


class MElement;

extern "C" {
GMSH_Plugin *GMSH_RegisterAnalyseMeshQuality2Plugin();
}

class GMSH_AnalyseMeshQuality2Plugin : public GMSH_PostPlugin {
private:
  class dataEntities;
  class dataSingleDimension;
  GModel *_m;
  dataSingleDimension *_data2D, *_data3D;
  bool _verbose = false;
  int _dimensionPolicy = 0;


#if defined(HAVE_VISUDEV)
  // Pointwise data
  // FIXME to check after
  bool _createPwView = 0;
  int _elemNumForPwView = 0;
  int _numElementToScan; // FIXME ajouté pour pouvoir compiler
  bool _pwJac = false, _pwIGE = false, _pwICN = false;
  std::map<int, std::vector<double> > _dataPViewJac;
  std::map<int, std::vector<double> > _dataPViewIGE;
  std::map<int, std::vector<double> > _dataPViewICN;
  int _type2tag[20] = {0};
  int _viewOrder = 0;
#endif


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
    return "Compute validity and quality of (curved) elements.";
  }
  std::string getHelp() const override;
  std::string getAuthor() const override { return "Amaury Johnen"; }
  int getNbOptions() const override;
  StringXNumber *getOption(int) override;
  PView *execute(PView *) override;

private:
  void _decideDimensionToCheck(bool &check2D, bool &check3D) const;

  void _info(const std::string &msg, const int verbosityPolicy = 0) const {
    if (_verbose && verbosityPolicy >= 0 || !_verbose && verbosityPolicy <= 0)
      Msg::Info("%s", msg.c_str());
  }
  void _warn(const std::string &msg, const int verbosityPolicy = 0) const {
    if (_verbose && verbosityPolicy >= 0 || !_verbose && verbosityPolicy <= 0)
      Msg::Warning("%s", msg.c_str());
  }
  void _error(const std::string &msg, const int verbosityPolicy = 0) const {
    if (_verbose && verbosityPolicy >= 0 || !_verbose && verbosityPolicy <= 0)
      Msg::Error("%s", msg.c_str());
  }

#if defined(HAVE_VISUDEV)
  void _computePointwiseQuantities(MElement *,
                                   const fullMatrix<double> *normals);
  void _createPViewPointwise();
  void _setInterpolationMatrices(PView *);
#endif

private:
  class dataEntities {
  private:
    GEntity *_ge;
    //bool computedThisRun; // FIXME necessary?
    std::map<MElement*, size_t> _mapElemToIndex;
    std::vector<double> _minJ, _maxJ, _minDisto, _minAspect;
    int _numVisibleElem = 0;
    int _numToCompute[3]{};
    // x bits of char are used for the following information:
    // - First 3 bits: to say if quantities has already been computed
    // FIXME The other 5 bits can be used for different alternatives:
    //         a) element must be computed (1 bits)
    //         b) measure must be computed (3 bits)
    //         c) this element is concerned by this run (1 bits)
    //         d) this measure is concerned by this run (3 bits)
    //       (a) depends on onlyVisible but not first three bits
    //       (b) depends on onlyVisible and first three bits but can be deduced
    //           from first three bits and (a)
    //       (c) and (d) the same but for knowing which element should be used
    //                   for creatinghiding/Pview. However, (d) is less useful
    //                   since normally, measure of a certain element should
    //                   have been computed if the measure has been asked and
    //                   if its flag.
    //        (a) == (c)
    //        I think should use whatever I can use among (a), (b), (c)
    std::vector<char> _flags;

    // NOTE this is for checking if pviews have already been created.
    //  This is to avoid recreating them in the case that the user
    //  launch the plugin first with e.g. Disto, then decide to compute
    //  also Aspect, we do not want to redraw pviews
    // NOTE check that the pview still exist, shoould check PView::list
    std::vector<PView*> _views;

  public:
    explicit dataEntities(GEntity *ge)
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

  class dataSingleDimension {
  private:
    const int _dim = 0;
    std::map<GEntity*, dataEntities> _data;

    // Latest created PView in function of:
    // - type = 3D {0, 2, 4} or 2D {1, 3, 5} pview
    // - measure = validity {0, 1}, disto {2, 3} or aspect {4, 5}
    PView* _views[6]{};

    // Store if data has changed. This is useful if the plugin is executed at
    // least 3 times. Here is an example:
    // 1) Set: checkQualityDisto=1, createElementsView=1
    // 2) Run 1: Disto is computed and a PView is created
    // 3) Set: recomputePolicy=1, createElementsView=0
    // 4) Run 2: Disto is recomputed
    // 5) Set: recomputePolicy=-1, createElementsView=1
    // 6) Run 3: Disto is not recomputed, but a new PView is created
    // Explanation: After run 2, _dataChangedSinceCreation corresponding to the
    //    PView is set to true, thus at third run the new PView is created.
    bool _dataChangedSinceCreation[6]{};

  public:
    explicit dataSingleDimension(int dim) : _dim(dim) {}
    void clear() {_data.clear();}
  };
};





#endif
#endif
