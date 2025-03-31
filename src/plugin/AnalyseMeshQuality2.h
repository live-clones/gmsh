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
#include <cstdarg>
#include "Plugin.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "GEntity.h" // FIXME necessary?
#include "MElement.h" // FIXME necessary?

// NOTE Workflow
//  0) - If freeData-NothingElse, clear all data.
//     - If freeData-NothingElse or no checkValidity/compute*, return.
//  1) Loop over all GEntities of considered dimension (dep. dimensionPolicy):
//     a) check that GEntity still exists (NB: GModel::faces or regions)
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
  static bool _verbose;

private:
  class DataSingleDimension;
  class DataEntity;
  class StatGenerator;
  struct Counts;
  struct Measures;

private:
  struct Parameters {
    struct Compute {
      bool validity = false;
      bool disto = false;
      bool aspect = false;
      bool onlyVisible = false;
      bool onlyCurved = false;
      bool lazyValidity = false;
      int policy = 0;
    } compute;

    struct Post {
      bool create2D = false;
      bool create3D = false;
      bool forceNew = false;
      double plotCutoffPack = 10;
    } pview;

    struct Hidding {
      bool yes = false;
      bool worst = false;
      int criterion = 2;
      double threshold = 10;
    } hide;

    double statCutoffPack = 10;
    double dimPolicy = 0;
    bool freeData = false;
    bool checkValidity = false;
    bool check2D = false;
    bool check3D = false;
    bool printJac = false;
  };

private:
  GModel *_m;
  DataSingleDimension *_data2D, *_data3D;
  StatGenerator *_statGen;
  Parameters _param;
  bool _myVerbose = false;
  int _dimensionPolicy = 0;

#if defined(HAVE_VISUDEV)
  // Pointwise data
  // FIXME to check after
  bool _createPwView = 0;
  int _elemNumForPwView = 0;
  int _numElementToScan; // FIXME ajouté pour pouvoir compiler
  bool _pwJac = false, _pwIGE = false, _pwICN = false;
  std::map<int, std::vector<double>> _dataPViewJac;
  std::map<int, std::vector<double>> _dataPViewIGE;
  std::map<int, std::vector<double>> _dataPViewICN;
  int _type2tag[20] = {0};
  int _viewOrder = 0;
#endif

public:
  GMSH_AnalyseMeshQuality2Plugin()
  {
    _m = nullptr;
    _data2D = new DataSingleDimension(2);
    _data3D = new DataSingleDimension(3);
    _statGen = new StatGenerator();
  }
  virtual ~GMSH_AnalyseMeshQuality2Plugin()
  {
    delete _data2D;
    delete _data3D;
    delete _statGen;
  }
  GMSH_PLUGIN_TYPE getType() const override { return GMSH_MESH_PLUGIN; }
  std::string getName() const override { return "AnalyseMeshQuality2"; }
  std::string getShortHelp() const override
  {
    return "Compute validity and quality of (curved) elements.";
  }
  std::string getHelp() const override;
  std::string getAuthor() const override { return "Amaury Johnen"; }
  int getNbOptions(bool legacy = false) const override;
  StringXNumber *getOption(int) override;
  std::string getOptionsSectionHeader(int) const override;
  PView *execute(PView *) override;

private:
  void _fetchParameters();
  void _decideDimensionToCheck(bool &check2D, bool &check3D) const;
  void _computeMissingData(Counts param, bool check2D, bool check3D) const;
  void _printStats(Measures &m2, Measures &m3) const;
  void _printStats(Measures &, const char* str_dim) const;

  // Those are static to be able to call them from class members
  static bool _okToPrint(int verb)
  {
    return (_verbose && verb >= 0) || (!_verbose && verb <= 0);
  }
  static void _printMessage(void (*func)(const char *, ...), const char *format,
                            va_list);
  static void _info(int verbosityPolicy, const char *format, ...);
  static void _warn(int verbosityPolicy, const char *format, ...);
  static void _error(int verbosityPolicy, const char *format, ...);
  // static void _status(int verbosityPolicy, const char *format, ...); // FIXME implement this?
  void _devPrintCount(const Counts &) const;
  std::size_t _printElementToCompute(const Counts &cnt2D, const Counts &cnt3D) const;
  std::size_t _guidanceNothingToCompute(Counts counts,
                                        bool check2D, bool check3D) const;

#if defined(HAVE_VISUDEV)
  void _computePointwiseQuantities(MElement *,
                                   const fullMatrix<double> *normals);
  void _createPViewPointwise();
  void _setInterpolationMatrices(PView *);
#endif

private:
  class DataSingleDimension {
  private:
    const int _dim;
    std::map<GEntity *, DataEntity> _dataEntities;

    // Latest created PView in function of:
    // - type = 3D {0, 2, 4} or 2D {1, 3, 5} pview
    // - measure = validity {0, 1}, disto {2, 3} or aspect {4, 5}
    PView *_views[6]{};

    // Store if data has changed. This is useful if the plugin is executed at
    // least 3 times. Here is an example:
    // 1) Set: checkQualityDisto=1, createElementsView=1
    // 2) Run 1: Disto is computed and a PView is created
    // 3) Set: recomputePolicy=1, createElementsView=0
    // 4) Run 2: Disto is recomputed
    // 5) Set: recomputePolicy=-1, createElementsView=1
    // 6) Run 3: Disto is not recomputed, but a new PView is created
    // Explanation: After run 2, _changedSincePViewCreation corresponding to the
    //    PView is set to true, thus at third run the new PView is created.
    bool _changedSincePViewCreation[6]{};

  public:
    explicit DataSingleDimension(int dim) : _dim(dim) {}
    void clear() { _dataEntities.clear(); }
    void initialize(GModel const *, const Parameters::Compute &, Counts &);
    void getDataEntities(std::vector<DataEntity*> &set)
    {
      for(auto &d : _dataEntities) set.push_back(&d.second);
    }
    void gatherValues(const Counts &, Measures &);

  private:
    void _updateGEntities(std::vector<GEntity *> &, int recomputePolicy);
  };

  class DataEntity {
  private:
    GEntity *_ge;
    // bool computedThisRun; // FIXME necessary?
    std::map<MElement *, size_t> _mapElemToIndex;
    std::vector<double> _minJ, _maxJ, _minDisto, _minAspect;
    std::size_t _numToCompute[3]{};
    std::size_t _numToShow[3]{};
    // 8 bits of char are used for the following information:
    // - to say if quantities has already been computed
    // - to say if element is 'in GEntity', visible, known to be straight
    //   or curved, curved, requested
    std::vector<unsigned char> _flags;

  public:
    explicit DataEntity(GEntity *ge) : _ge(ge) {}
    void getNumShownElement(std::size_t num[3]) const
    {
      for(int i = 0; i < 3; ++i) num[i] = _numToShow[i];
    }
    //void countNewElement(ComputeParameters, std::size_t cnt[3]) const;
    void initialize(const Parameters::Compute &);
    void count(const Parameters::Compute &, Counts &);
    void reset(std::size_t);
    void add(MElement *);
    void add(std::vector<MElement *> &elements)
    {
      for(auto &e : elements) add(e);
    }
    GEntity *getEntity() const { return _ge; }
    std::size_t getNumToCompute(int i) const { return _numToCompute[i]; }
    void addValues(Measures &);

    // I separate the computation of each measure because computation can be
    // really heavy and take a a lot of time. Computing the validity is much
    // faster and can help the user to evaluate the time needed to compute the
    // remaining qualities.
    void computeValidity(MsgProgressStatus &);
    void computeDisto(MsgProgressStatus &, bool considerAsValid);
    void computeAspect(MsgProgressStatus &, bool considerAsValid);

    // FIXME should i create only one method? bool computeDisto, std::vector<.>
    //       *vecDisto) or just std::vector<.> *vecDisto = nullptr)

  private:
    void _count(unsigned char mask, std::size_t &toCompute,
                std::size_t &toShow);
    void _countCurved(std::size_t &known, std::size_t &curved);
  };

  class StatGenerator {
  private:
    static const int _colWidth = 10;
    static const int _N = 10; // max number of stored coefficients
    int _idxCall = 0;
    std::vector<int> _idxLastCall;
    std::vector<std::vector<double>> _coeff;
    std::map<std::pair<double, size_t>, size_t> _cutoffvsNumValues;

    std::vector<double> _statCutoffs;
    std::vector<double> _plotCutoffs;

  public:
    StatGenerator()
    {
      _idxLastCall.reserve(_N);
      _coeff.reserve(_N);
    }

    void setCutoffStats(double pack)
    {
      _unpackCutoff(pack, _statCutoffs);
    }
    void setCutoffPlots(double pack)
    {
      _unpackCutoff(pack, _plotCutoffs);
    }
    void printStats(const Parameters &, const Measures &m2, const Measures &m3);

  private:
    void _unpackCutoff(double input, std::vector<double> &cutoffs) const;
    void _printStats(const Measures &measure, const char* str_dim, bool printJac);
    void _printStatsOneMeasure(const std::vector<double> &measure, const char* str, bool useG = false);
    const std::vector<double> &_getCoefficients(double cutoff, size_t num);
    void _computeCoefficients(double cutoff, size_t sz, std::vector<double> &);
  };

  struct Counts {
    std::size_t elToCompute[3]{}; // for three measures
    std::size_t elToShow[3]{};
    std::size_t totalEl = 0;
    std::size_t elCurvedComputed = 0;
    std::size_t curvedEl = 0;
    std::size_t existingEl = 0;
    std::size_t visibleEl = 0;
    Counts operator+(const Counts &) const;
  };

  struct Measures {
    bool validity;
    bool disto;
    bool aspect;
    std::vector<double> minJ;
    std::vector<double> maxJ;
    std::vector<double> minDisto;
    std::vector<double> minAspect;
    Measures(bool needValidity, bool needDisto, bool needAspect) {
      validity = needValidity;
      disto = needDisto;
      aspect = needAspect;
    }
  };
};

#endif
#endif
