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
#include "fullMatrix.h"

class MElement;

extern "C" {
GMSH_Plugin *GMSH_RegisterAnalyseMeshQuality2Plugin();
}

class GMSH_AnalyseMeshQuality2Plugin : public GMSH_PostPlugin {
private:
  class DataSingleDimension;
  class DataEntity;
  class StatGenerator;
  struct Counts;
  struct Measures;
  struct ViewKey;
  struct Parameters {
    double dimPolicy = 0;
    bool freeData = false;

    struct Computation {
      bool skip = false;
      // // This distinction is because it is useful to know invalidity on planar
      // // mesh for speeding up computation of quality, but not on curved surface
      bool jacobianOnCurvedGeo = false;
      bool jacobian = false;
      bool disto = false;
      bool aspect = false;
      bool geofit = false;
      bool onlyGivenElemType = false;
      bool acceptedElemType[TYPE_MAX_NUM] = {false};
      bool onlyVisible = false;
      bool onlyCurved = false;
      bool smartRecompute = false;
      bool freeOldData = false;
    } compute;

    struct Post {
      bool createPlot = false;
      bool createElemView = false;
      double plotCutoffPack = 10;
      double statCutoffPack = 10;
    } pview;

    struct Hiding {
      int todo = 0;
      int policy = 0;
      int criterion = 0;
      double threshold = 10;
      bool worst = false;
      bool unhideToo = false;
    } hide;

    struct MetricsToShow {
      int which[7] = {0};
      int M = 0;
      bool regularizeJac = false;
      bool regularizeGFit = false;
      bool skipStats = false;
    } show;

    bool check2D = false;
    bool check3D = false;
  };
  enum Metric { VALIDITY, UNFLIP, MINJAC, RATIOJAC, GEOFIT, DISTO, ASPECT, METRIC_COUNT};
  static const std::array<std::string, METRIC_COUNT> _metricNames;


private:
  GModel *_m;
  DataSingleDimension *_data2D, *_data3D;
  StatGenerator *_statGen;
  Parameters _param;
  // bool _myVerbose = false;
  int _dimensionPolicy = 0;
  int _previousFreeOldData = 1;
  std::map<ViewKey, PView *> _pviews;

#if defined(HAVE_VISUDEV)
  // Pointwise data
  // FIXME to check after
  // bool _createPwView = 0;
  // int _elemNumForPwView = 0;
  // int _numElementToScan; // FIXME ajouté pour pouvoir compiler
  // bool _pwJac = false, _pwIGE = false, _pwICN = false;
  // std::map<int, std::vector<double>> _dataPViewJac;
  // std::map<int, std::vector<double>> _dataPViewIGE;
  // std::map<int, std::vector<double>> _dataPViewICN;
  // int _type2tag[20] = {0};
  // int _viewOrder = 0;
#endif

public:
  GMSH_AnalyseMeshQuality2Plugin()
  {
    _m = nullptr;
    _data2D = new DataSingleDimension(2);
    _data3D = new DataSingleDimension(3);
    _statGen = new StatGenerator();
  }

  ~GMSH_AnalyseMeshQuality2Plugin() override
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
  bool _fetchParameters();
  void _fetchLegacyParameters();
  bool _checkEarlyExitOptions() const;
  void _purgeViews(bool purge2D, bool purge3D);
  void _decideDimensionToCheck(bool &check2D, bool &check3D) const;
  void _computeRequestedData(Counts param, bool check2D, bool check3D) const;
  void _finalizeMeasuresData(std::vector<Measures> &) const;
  void _createPlots(const std::vector<Measures> &);
  bool _createPlotsOneMetric(const Measures &, Metric);
  void _createElementViews(const std::vector<Measures> &);
  bool _createElementViewsOneMetric(const Measures &, Metric);
  bool _performHiding(const std::vector<Measures> &);
  void _findElementsToHide(const Measures &, Metric, std::set<MElement *> &) const;
  bool _hideElements(const Measures &measure, std::vector<MElement *> &elemToHide,
                     size_t &countHidden, size_t &countMadeVisible);

  // Those are static to be able to call them from class members
  static bool _okToPrint(int asked);
  static void _printMessage(void (*func1)(const char *, ...),
                            void (*func2)(bool, const char *, ...),
                            const char *format, va_list, bool logStatusBar = false);
  static void _info(int verbosityPolicy, const char *format, ...);
  static void _warn(int verbosityPolicy, const char *format, ...);
  static void _error(int verbosityPolicy, const char *format, ...);
  static void _status(int verbosityPolicy, const char *format, ...);
  static void _statusBar(int verbosityPolicy, const char *format, ...);

  // Help message
  static std::string _getHelpIntro();
  static std::string _getHelpDefinitions();
  static std::string _getHelpMetrics();
  static std::string _getHelpWWM() ;
  static std::string _getHelpOptionsClarification();
  static std::string _getHelpVisibility();
  static std::string _getHelpAdvancedUse();
  static std::string _getHelpFAQ() ;

  // User guidance
  static std::size_t _printElementToCompute(const Counts &cnt2D, const Counts &cnt3D);
  void _guidanceNoSelectedElem(Counts counts) const;
  bool _checkAndGuideNoDataToShow(Counts counts, bool check2D, bool check3D) const;
  static void _printDetailsMetrics(size_t which[METRIC_COUNT], bool verbose2 = false);

#if defined(HAVE_VISUDEV)
  // void _computePointwiseQuantities(MElement *,
  //                                  const fullMatrix<double> *normals);
  // void _createPViewPointwise();
  // void _setInterpolationMatrices(PView *);
#endif

private:
  class DataSingleDimension {
  private:
    const int _dim;
    std::map<GEntity *, DataEntity> _dataEntities;
    bool _selectedListHasChanged = false;

  public:
    explicit DataSingleDimension(int dim) : _dim(dim) {}
    void clear() { _dataEntities.clear(); }
    void syncWithModel(GModel const *, const Parameters::Computation &, Counts &);
    void getDataEntities(std::vector<DataEntity*> &set)
    {
      for(auto &d : _dataEntities) set.push_back(&d.second);
    }
    bool getSelectedListHasChanged() { return _selectedListHasChanged; }
    void gatherValues(const Counts &, Measures &);
    bool hasDataToShow() const;

  private:
    void _updateGEntitiesList(std::set<GEntity *, GEntityPtrLessThan> &, bool free);
  };

  class DataEntity {
  private:
    GEntity *_ge = nullptr;
    bool _flatnessIsKnown = false;
    bool _isCurvedGeo = false;

    std::map<MElement *, size_t> _mapElemToIndex;
    std::vector<double> _minJ, _maxJ, _minGFit, _maxGFit, _minDisto, _minAspect;

    // Order of 5 metric to compute: jacNDelem, jacCGelem, geofit, disto, aspect
    std::size_t _numToCompute[5]{};
    std::size_t _numSelected = 0;

    // 8 bits of char are used for the following information:
    // - to say if quantities has already been computed
    // - to say if element is visible, known to be straightOrCurved, curved,
    //   requested (see .cpp)
    std::vector<unsigned char> _flags;

    fullMatrix<double> *_normals = nullptr;
    fullMatrix<double> _normalsToPrint;

  public:
    explicit DataEntity(GEntity *ge) : _ge(ge) { _checkFlatnessAndComputeNormals(); }
    DataEntity(const DataEntity &other) : _ge(other._ge)
    {
      if(other._normals) {
        _normals = new fullMatrix<double>(*other._normals);
        _updateNormalsToPrint();
      }
    }
    // Move Constructor
    DataEntity(DataEntity &&other) noexcept
        : _ge(other._ge),
          _flatnessIsKnown(other._flatnessIsKnown),
          _isCurvedGeo(other._isCurvedGeo),
          _mapElemToIndex(std::move(other._mapElemToIndex)),
          _minJ(std::move(other._minJ)),
          _maxJ(std::move(other._maxJ)),
          _minGFit(std::move(other._minGFit)),
          _maxGFit(std::move(other._maxGFit)),
          _minDisto(std::move(other._minDisto)),
          _minAspect(std::move(other._minAspect)),
          _flags(std::move(other._flags)),
          _normals(other._normals),
          _normalsToPrint(std::move(other._normalsToPrint)) {
      // Null out the original pointer in the source object
      other._normals = nullptr;
    }
    ~DataEntity()
    {
      delete _normals;
    }
    size_t getNumSelected() const { return _numSelected; }
    size_t updateElementsAndFlags(const Parameters::Computation &);
    void count(const Parameters::Computation &, Counts &);
    void reset(std::size_t);
    void add(MElement *);
    void add(const std::vector<MElement *> &elements)
    {
      for(auto &e : elements) add(e);
    }
    // std::size_t getNumToCompute(int i) const { return _numToCompute[i]; }
    void addValues(Measures &);
    bool hasDataToShow() const;

    // I separate the computation of each measure because computation can be
    // really heavy and take a a lot of time. Computing the validity is much
    // faster and can help the user to evaluate the time needed to compute the
    // remaining qualities.
    void computeJacDet(MsgProgressStatus &, bool onPlanar, bool onCurved);
    void computeDisto(MsgProgressStatus &, bool considerAsValid);
    void computeAspect(MsgProgressStatus &, bool considerAsValid);
    void computeGeoFit(MsgProgressStatus &);
    void computeGeoFit(GFace *gf, MElement *el, double minmaxO[2]) const;

  private:
    void _count(unsigned char mask, std::size_t &cnt);
    void _countCurved(std::size_t &known, std::size_t &curved);
    void _countAvailableValues(const Parameters::Computation &, std::size_t cnt[5],
      size_t &numForWarningNotValidity);
    void _checkFlatnessAndComputeNormals();
    void _updateNormalsToPrint();
  };

  class StatGenerator {
  private:
    static constexpr int _colWidth = 10;
    static constexpr int _N = 10; // max number of stored coefficients
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
    std::vector<double> getCutoffPlots() const { return _plotCutoffs; }
    void printStats(const Parameters &, const std::vector<Measures> &measures);

  private:
    void _unpackCutoff(double input, std::vector<double> &cutoffs) const;
    void _printStats(const Measures &measure);
    void _printStatsOneMetric(const Measures &measure, Metric metric, bool showPercentElem);
    const std::vector<double> &_getCoefficients(double cutoff, size_t num);
    void _computeCoefficients(double cutoff, size_t sz, std::vector<double> &);
  };

  struct Counts {
    // This struct helps determine what will be computed, why the plugin has
    // nothing to analyze or other things

    // Order of 5 metric to compute: jacNDelem, jacCGelem, geofit, disto, aspect
    std::size_t metricValsAvailOnSelectedElem[5]{};
    std::size_t metricValsToCompute[5]{};
    // NB: metricValsToCompute[i] != reqElem - metricValsToCompute[i] in
    //     general because of OmitMetricsComputation option

    // For stopping early, and for reserving size vector
    std::size_t reqElem = 0;
    std::size_t reqElemOkGeoFit = 0;
    std::size_t reqElemOnCurvGeo = 0;

    // For warning about longer computation
    std::size_t distoOrAspectToComputeButUnknownValidity = 0;

    // For guiding when reqElem == 0:
    std::size_t elem = 0;
    std::size_t elemOnCurvGeo = 0;
    std::size_t elemVisible = 0;
    std::size_t elemCurved = 0;
    std::size_t elemWithKnownCurving = 0; // NOTE: unused
    std::size_t elem_byType[TYPE_MAX_NUM]{};

    std::size_t geoEntFlat[3]{};
    std::size_t geoEntCurved[3]{};

    // Methods
    Counts operator+(const Counts &) const;
  };

  struct Measures {
    bool dim2Elem;
    bool dim3Elem;
    const char* dimStr;
    const char* dimStrShort;
    // Data for all elements
    std::vector<double> minJ;
    std::vector<double> maxJ;
    std::vector<double> ratioJ;
    std::vector<double> minDisto;
    std::vector<double> minAspect;
    std::vector<bool> isOnCurvedGeo;
    std::vector<MElement *> elements;
    // Data for elements on curved geometry
    std::vector<double> minGFit;
    std::vector<double> maxGFit;
    std::vector<MElement *> elementsGFit;
    // Data for elements on straight geometry
    std::vector<double> isValid;
    std::vector<double> isNotFlipped;
    std::vector<MElement *> elementsStraightGeo;
    size_t numInvalidElements;
    size_t numFlippedElements;
    std::size_t numToShow[7]{};

    static Measures combine(const Measures &, const Measures &, const char *name, const char *shortName);
    void getValues(Metric m, std::vector<double> &values, std::vector<MElement *> *filteredElements = nullptr) const;
    const std::vector<double> &_getValues(Metric m) const;
    const std::vector<MElement *> &_getElements(Metric m) const;
  };

  struct ViewKey {
    bool dim2Elem;
    bool dim3Elem;
    Metric metric;
    enum TypeView { PLOT, ELEMENTS } typeView;
    double cutoff;

    ViewKey(bool d2, bool d3, Metric m, TypeView t, double c)
      : dim2Elem(d2), dim3Elem(d3), metric(m), typeView(t), cutoff(c) {}

    // Equality operator for unordered_map or map
    bool operator==(const ViewKey &other) const {
      return std::tie(dim2Elem, dim3Elem, metric, typeView, cutoff) ==
             std::tie(other.dim2Elem, other.dim3Elem, other.metric, other.typeView, other.cutoff);
    }

    // Less-than operator for std::map
    bool operator<(const ViewKey &other) const {
      return std::tie(dim2Elem, dim3Elem, metric, typeView, cutoff) <
             std::tie(other.dim2Elem, other.dim3Elem, other.metric, other.typeView, other.cutoff);
    }
  };

};

#endif
#endif
