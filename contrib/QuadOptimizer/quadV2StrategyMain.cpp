// Standalone runner for comparing V2 schedules on an identical saved mesh.
// Build this file and the chosen smallCavityOptimizerV2.cpp against the same
// Gmsh build. Reports contain independent initial/final model quality audits.
#include "smallCavityOptimizerV2.h"
#include "quadCadDistance.h"
#include "GModel.h"
#include "gmsh.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {
  using Clock = std::chrono::steady_clock;

  struct Arguments {
    std::string input, output, geometry, report;
    int schedule = 0;
    int searchMode = 0;
    int searchCandidates = 32;
    int maximumPasses = -1;
    int maximumAccepted = 10000;
    int smoothingPasses = 2;
    int finalWinslowPasses = 0;
    int terminalWinslowPasses = 4;
    bool smartLaplacian = false;
    bool activeNodalSmoothing = true;
    bool terminalMandatory = true;
    bool qualitySwaps = true;
    bool finalPairs = true;
    double finalSplitCadRatio = .2;
    int verbosity = 0;
    double target = 4.;
    double minimum = -1.;
    double maximum = -1.;
  };

  void usage(std::ostream &out)
  {
    out << "Usage: gmshQuadV2Strategy --input frozen.msh --output result.msh "
           "--report result.json [--geometry model.geo|model.brep|reference.msh] "
           "[--schedule 0|1|2] [--target-size 4] [--min-edge h/2] "
           "[--max-edge 2h] [--max-passes -1] [--max-accepted 10000] "
           "[--smoothing-passes 2] [--smart-laplacian 0|1] [--active-smoothing 0|1] "
           "[--final-winslow-passes 0] [--terminal-winslow-passes 4] [--valence 0|1] [--swaps 0|1] [--final-split-cad-ratio 0.2] [--merge-tt 0|1] [--search-mode 0|1|2|3] "
           "[--search-candidates 32] [--verbosity 0]\n";
  }

  int integer(const std::string &value)
  {
    std::size_t end = 0;
    const int result = std::stoi(value, &end);
    if(end != value.size()) throw std::runtime_error("Invalid integer: " + value);
    return result;
  }

  double number(const std::string &value)
  {
    std::size_t end = 0;
    const double result = std::stod(value, &end);
    if(end != value.size() || !std::isfinite(result))
      throw std::runtime_error("Invalid number: " + value);
    return result;
  }

  Arguments parse(int argc, char **argv)
  {
    Arguments args;
    for(int i = 1; i < argc; ++i) {
      const std::string key = argv[i];
      if(i + 1 == argc) throw std::runtime_error("Missing value for " + key);
      const std::string value = argv[++i];
      if(key == "--input") args.input = value;
      else if(key == "--output") args.output = value;
      else if(key == "--geometry") args.geometry = value;
      else if(key == "--report") args.report = value;
      else if(key == "--schedule") args.schedule = integer(value);
      else if(key == "--search-mode") args.searchMode = integer(value);
      else if(key == "--search-candidates") args.searchCandidates = integer(value);
      else if(key == "--target-size") args.target = number(value);
      else if(key == "--min-edge") args.minimum = number(value);
      else if(key == "--max-edge") args.maximum = number(value);
      else if(key == "--max-passes") args.maximumPasses = integer(value);
      else if(key == "--max-accepted") args.maximumAccepted = integer(value);
      else if(key == "--final-split-cad-ratio") args.finalSplitCadRatio = number(value);
      else if(key == "--final-pairs" || key == "--merge-tt") args.finalPairs = integer(value) != 0;
      else if(key == "--terminal-mandatory" || key == "--valence") args.terminalMandatory = integer(value) != 0;
      else if(key == "--active-smoothing") args.activeNodalSmoothing = integer(value) != 0;
      else if(key == "--swaps") args.qualitySwaps = integer(value) != 0;
      else if(key == "--smart-laplacian") args.smartLaplacian = integer(value) != 0;
      else if(key == "--terminal-winslow-passes") args.terminalWinslowPasses = integer(value);
      else if(key == "--final-winslow-passes") args.finalWinslowPasses = integer(value);
      else if(key == "--smoothing-passes") args.smoothingPasses = integer(value);
      else if(key == "--verbosity") args.verbosity = integer(value);
      else throw std::runtime_error("Unknown option: " + key);
    }
    if(args.input.empty() || args.output.empty() || args.report.empty())
      throw std::runtime_error("--input, --output and --report are required");
    if(!(args.target > 0.) || args.schedule < 0 || args.schedule > 2 ||
       args.maximumPasses < -1 || args.maximumAccepted < 0 ||
       args.smoothingPasses < 0 || args.finalWinslowPasses < 0 || args.terminalWinslowPasses < 0 || args.verbosity < 0 ||
       args.searchMode < 0 || args.searchMode > 3 || args.searchCandidates < 1)
      throw std::runtime_error("Invalid schedule, size or optimization budget");
    if(args.minimum < 0.) args.minimum = .5 * args.target;
    if(args.maximum < 0.) args.maximum = 2. * args.target;
    if(args.maximum > 0. && args.minimum > args.maximum)
      throw std::runtime_error("Minimum edge length exceeds maximum edge length");
    const auto input = std::filesystem::weakly_canonical(args.input);
    const auto output = std::filesystem::weakly_canonical(args.output);
    const auto report = std::filesystem::weakly_canonical(args.report);
    if(input == output || input == report || output == report)
      throw std::runtime_error("Input, output and report must be different files");
    if(!args.geometry.empty()) {
      const auto geometry = std::filesystem::weakly_canonical(args.geometry);
      if(geometry == output || geometry == report)
        throw std::runtime_error("Output and report cannot overwrite the geometry");
    }
    return args;
  }

  std::string quoted(const std::string &value)
  {
    std::ostringstream out;
    out << '"';
    for(unsigned char c : value) {
      switch(c) {
      case '"': out << "\\\""; break;
      case '\\': out << "\\\\"; break;
      case '\n': out << "\\n"; break;
      case '\r': out << "\\r"; break;
      case '\t': out << "\\t"; break;
      default:
        if(c < 32)
          out << "\\u" << std::hex << std::setw(4) << std::setfill('0')
              << static_cast<unsigned int>(c) << std::dec;
        else out << c;
      }
    }
    out << '"';
    return out.str();
  }

  // JSON requires finite numbers; null preserves missing/non-finite metrics.
  class JsonObject {
    std::ostream &_out;
    bool _first = true;
  public:
    explicit JsonObject(std::ostream &out) : _out(out) { _out << '{'; }
    ~JsonObject() { _out << '}'; }
    void key(const char *name)
    {
      if(!_first) _out << ',';
      _first = false;
      _out << '\n' << quoted(name) << ':';
    }
    template <typename T> void field(const char *name, T value)
    {
      key(name);
      _out << value;
    }
    void field(const char *name, double value)
    {
      key(name);
      if(std::isfinite(value)) _out << value;
      else _out << "null";
    }
    void field(const char *name, bool value)
    {
      key(name);
      _out << (value ? "true" : "false");
    }
    void field(const char *name, const std::string &value)
    {
      key(name);
      _out << quoted(value);
    }
  };

  void writeAudit(std::ostream &out,
                  const QuadOptimizer::QuadMeshQualitySummary &quality)
  {
    JsonObject json(out);
    json.field("cadMetric", std::string("parametric-chord-gauss-v1"));
    json.field("cadRole", std::string("diagnostic-only"));
#define FIELD(name) json.field(#name, quality.name)
    FIELD(success);
    FIELD(facesWithElements);
    FIELD(nonManifoldFaces);
    FIELD(triangles);
    FIELD(quadrangles);
    FIELD(invalidTriangles);
    FIELD(invalidQuadrangles);
    FIELD(absolutePassElements);
    FIELD(badTriangles);
    FIELD(badQuadrangles);
    FIELD(absoluteQuadrangleViolations);
    FIELD(preferredQuadrangleViolations);
    FIELD(severeValenceVertices);
    FIELD(irregularValenceVertices);
    FIELD(passesShapeSpecifications);
    FIELD(minimumQuadrangleSICN);
    FIELD(averageQuadrangleSICN);
    FIELD(minimumQuadrangleAngleDegrees);
    FIELD(maximumQuadrangleAngleDegrees);
    FIELD(maximumQuadrangleEdgeRatio);
    FIELD(averageQuadrangleEdgeRatio);
    FIELD(maximumQuadrangleSkewingDegrees);
    FIELD(averageQuadrangleSkewingDegrees);
    FIELD(maximumQuadrangleWarpingDegrees);
    FIELD(averageQuadrangleWarpingDegrees);
    FIELD(sizeAudited);
    FIELD(sizeSpecificationsActive);
    FIELD(sizeEdges);
    FIELD(edgesBelowMinimum);
    FIELD(edgesAboveMaximum);
    FIELD(invalidSizeEdges);
    FIELD(minimumEdgeLength);
    FIELD(maximumEdgeLength);
    FIELD(minimumTargetSizeRatio);
    FIELD(maximumTargetSizeRatio);
    FIELD(rmsLogTargetSizeRatio);
    FIELD(cadAudited);
    FIELD(cadElementsRequested);
    FIELD(cadElements);
    FIELD(invalidCadElements);
    FIELD(invalidCadSamples);
    FIELD(maximumSampledCadChordDistance);
    FIELD(rmsCadChordDistance);
#undef FIELD
    const auto criterion = [&json, &out](
      const char *name, const QuadOptimizer::QualityCriterionPassSummary &value) {
      json.key(name);
      JsonObject item(out);
      item.field("applicable", value.applicable);
      item.field("preferredPass", value.preferredPass);
      item.field("absolutePass", value.absolutePass);
    };
    criterion("warping", quality.warping);
    criterion("edgeRatio", quality.edgeRatio);
    criterion("quadrangleMinimumAngle", quality.quadrangleMinimumAngle);
    criterion("quadrangleMaximumAngle", quality.quadrangleMaximumAngle);
    criterion("triangleMinimumAngle", quality.triangleMinimumAngle);
    criterion("triangleMaximumAngle", quality.triangleMaximumAngle);
    criterion("skewing", quality.skewing);
  }

  struct ClosestCadAudit {
    QuadOptimizer::CadDistance::Contribution contribution;
    std::size_t requestedElements = 0, coveredElements = 0;
    std::size_t requestedFaces = 0, coveredFaces = 0;
  };

  ClosestCadAudit auditClosestCad(GModel *model, double targetSize)
  {
    ClosestCadAudit result;
    if(!model) return result;
    for(GFace *face : model->getFaces()) {
      const std::size_t elements = face->getNumMeshElements();
      if(!elements) continue;
      ++result.requestedFaces;
      bool faceComplete = true;
      QuadOptimizer::CadDistance::DistanceCache cache;
      for(std::size_t i = 0; i < elements; ++i) {
        MElement *element = face->getMeshElement(i);
        std::vector<QuadOptimizer::CadDistance::UV> uv;
        QuadOptimizer::CadDistance::elementParameters(face, element, uv);
        const auto contribution = QuadOptimizer::CadDistance::sampleElement(
          face, element, uv,
          [targetSize](const QuadOptimizer::CadDistance::Point &,
                       const QuadOptimizer::CadDistance::UV &) {
            return targetSize;
          }, &cache);
        ++result.requestedElements;
        result.coveredElements += contribution.complete();
        faceComplete = faceComplete && contribution.complete();
        result.contribution += contribution;
      }
      result.coveredFaces += faceComplete;
    }
    return result;
  }

  void writeClosestCadAudit(std::ostream &out, const ClosestCadAudit &audit,
                            double targetSize)
  {
    JsonObject json(out);
    json.field("metric", std::string(QuadOptimizer::CadDistance::metricId()));
    json.field("role", std::string("contract"));
    json.field("targetSizePolicy", std::string("constant-targetSize"));
    json.field("targetSize", targetSize);
    const auto &value = audit.contribution;
    json.field("complete", value.complete() &&
               audit.requestedElements == audit.coveredElements &&
               audit.requestedFaces == audit.coveredFaces);
#define FIELD(name) json.field(#name, value.name)
    FIELD(squaredDistanceIntegral);
    FIELD(normalizedSquaredDistanceIntegral);
    FIELD(sampledArea);
    FIELD(maximumDistance);
    FIELD(maximumNormalizedDistance);
    FIELD(requestedSamples);
    FIELD(coveredSamples);
#undef FIELD
    json.field("requestedElements", audit.requestedElements);
    json.field("coveredElements", audit.coveredElements);
    json.field("requestedFaces", audit.requestedFaces);
    json.field("coveredFaces", audit.coveredFaces);
    const double missing = std::numeric_limits<double>::quiet_NaN();
    json.field("rmsDistance", value.sampledArea > 0. ?
               std::sqrt(value.squaredDistanceIntegral / value.sampledArea) :
               missing);
    json.field("normalizedMeanSquaredDistance", value.sampledArea > 0. ?
               value.normalizedSquaredDistanceIntegral / value.sampledArea :
               missing);
  }

  void writeResult(std::ostream &out,
                   const QuadOptimizer::AllFacesOptimizerResult &result)
  {
    JsonObject json(out);
#define FIELD(name) json.field(#name, result.name)
    FIELD(success);
    FIELD(facesVisited);
    FIELD(facesWithQuadrangles);
    FIELD(facesSkippedInvalidInputCellComplex);
    FIELD(acceptedCavities);
    FIELD(acceptedTerminalMandatoryCavities);
    FIELD(finalInvalidQuadsSplit);
    FIELD(finalQtSwaps);
    FIELD(finalTtMerges);
    FIELD(finalTtCadSwaps);
    FIELD(initialValenceTwoQuadsSplit);
    FIELD(finalCadQuadsSplit);
    FIELD(finalQuadsSplitRejected);
    FIELD(finalQuadDiagonalQueriesFailed);
    FIELD(acceptedEdgeSwaps);
    FIELD(acceptedDiamonds);
    FIELD(acceptedValenceSixSplits);
    FIELD(acceptedQuadTwoTriangleReductions);
    FIELD(acceptedInteriorTriangleTriangleQuadReductions);
    FIELD(acceptedInteriorFourTriangleFanReductions);
    FIELD(acceptedInteriorAlternatingQuadTriangleReductions);
    FIELD(acceptedInteriorQQTQQTReductions);
    FIELD(acceptedBoundaryTriangleQuadTriangleFans);
    FIELD(acceptedTriangleTriangleSwaps);
    FIELD(acceptedSmoothingCavities);
    FIELD(rejectedByWinslow);
    FIELD(rejectedBySize);
    FIELD(rejectedByQuality);
    FIELD(reorientedElements);
    FIELD(warpedQuadranglesSplit);
    FIELD(catastrophicAngleQuadranglesSplit);
    FIELD(sizeRequirementsMet);
#undef FIELD
    bool reachedFixedPoint = !result.faces.empty();
    std::size_t exhaustedIterationBudget = 0, exhaustedCavityBudget = 0;
    std::size_t rejectedByCad = 0, rejectedByOrientation = 0;
    std::size_t rejectedByTopology = 0, rejectedCacheHits = 0;
    for(const auto &face : result.faces) {
      reachedFixedPoint = reachedFixedPoint && face.optimizer.reachedFixedPoint;
      exhaustedIterationBudget += face.optimizer.exhaustedIterationBudget;
      exhaustedCavityBudget += face.optimizer.exhaustedCavityBudget;
      rejectedByCad += face.optimizer.rejectedByCad;
      rejectedByOrientation += face.optimizer.rejectedByOrientation;
      rejectedByTopology += face.optimizer.rejectedByTopology;
      rejectedCacheHits += face.optimizer.rejectedCacheHits;
    }
    json.field("reachedFixedPoint", reachedFixedPoint);
    json.field("facesExhaustedIterationBudget", exhaustedIterationBudget);
    json.field("facesExhaustedCavityBudget", exhaustedCavityBudget);
    json.field("rejectedByCad", rejectedByCad);
    json.field("rejectedByOrientation", rejectedByOrientation);
    json.field("rejectedByTopology", rejectedByTopology);
    json.field("rejectedCacheHits", rejectedCacheHits);
    json.key("faces");
    out << '[';
    for(std::size_t i = 0; i < result.faces.size(); ++i) {
      if(i) out << ',';
      const auto &face = result.faces[i];
      JsonObject faceJson(out);
      faceJson.field("tag", face.faceTag);
      faceJson.field("success", face.optimizer.success);
      faceJson.field("passes", face.optimizer.passes);
      faceJson.field("acceptedCavities", face.optimizer.acceptedCavities);
      faceJson.field("acceptedTerminalMandatoryCavities",
                     face.optimizer.acceptedTerminalMandatoryCavities);
      faceJson.field("finalInvalidQuadsSplit", face.optimizer.finalInvalidQuadsSplit);
      faceJson.field("finalCadQuadsSplit", face.optimizer.finalCadQuadsSplit);
      faceJson.field("finalQuadsSplitRejected", face.optimizer.finalQuadsSplitRejected);
      faceJson.field("finalQuadDiagonalQueriesFailed", face.optimizer.finalQuadDiagonalQueriesFailed);
      faceJson.field("reachedFixedPoint", face.optimizer.reachedFixedPoint);
      faceJson.field("exhaustedIterationBudget",
                     face.optimizer.exhaustedIterationBudget);
      faceJson.field("exhaustedCavityBudget",
                     face.optimizer.exhaustedCavityBudget);
      faceJson.field("initialBadElements",
                     face.optimizer.initialObjective.absoluteBadElementCount);
      faceJson.field("finalBadElements",
                     face.optimizer.finalObjective.absoluteBadElementCount);
    }
    out << ']';
  }

  double seconds(Clock::time_point start)
  {
    return std::chrono::duration<double>(Clock::now() - start).count();
  }
} // namespace

int main(int argc, char **argv)
{
  if(argc == 2 && std::string(argv[1]) == "--help") {
    usage(std::cout);
    return 0;
  }
  bool initialized = false;
  try {
    const Arguments args = parse(argc, argv);
    gmsh::initialize(0, nullptr, false);
    initialized = true;
    gmsh::option::setNumber("General.Terminal", 1.);
    gmsh::option::setNumber("General.NumThreads", 1.);
    gmsh::option::setNumber("General.Verbosity", args.verbosity);
    const auto loadStart = Clock::now();
    if(args.geometry.empty()) gmsh::open(args.input);
    else {
      gmsh::open(args.geometry);
      gmsh::model::mesh::clear();
      // The mesh supplies its own embedded relations when merged below.
      // Retaining the reference relations would duplicate every constraint.
      gmsh::vectorpair surfaces;
      gmsh::model::getEntities(surfaces, 2);
      gmsh::model::mesh::removeEmbedded(surfaces);
      gmsh::merge(args.input);
    }
    const double loadSeconds = seconds(loadStart);

    QuadOptimizer::SmallCavityOptimizerOptions options;
    options.fastInteractiveCleanUp = true;
    options.stagedTopologyThenQuality = true;
    options.enforceSizeMap = true;
    options.targetSize = args.target;
    options.minimumEdgeLength = args.minimum;
    options.maximumEdgeLength = args.maximum;
    options.minimumEdgeSizeRatio = 0.;
    options.maximumEdgeSizeRatio = 0.;
    options.maximumOptimizationPasses = args.maximumPasses;
    options.maximumAcceptedCavities = args.maximumAccepted;
    options.finalSmoothingPasses = args.smoothingPasses;
    options.smartLaplacian = args.smartLaplacian;
    options.activeNodalSmoothing = args.activeNodalSmoothing;
    options.finalWinslowPasses = args.finalWinslowPasses;
    options.terminalWinslowPasses = args.terminalWinslowPasses;
    options.terminalMandatoryCleanup = args.terminalMandatory;
    options.qualitySwaps = args.qualitySwaps;
    options.finalSplitCadDistanceRatio = args.finalSplitCadRatio;
    options.finalPairCleanup = args.finalPairs;
    options.verbose = std::max(0, args.verbosity - 4);
    options.v2Schedule = args.schedule;
    options.v2SearchMode = args.searchMode;
    options.v2SearchCandidateLimit = args.searchCandidates;

    const auto initialAuditStart = Clock::now();
    const auto initial =
      QuadOptimizer::summarizeQuadMeshQuality(GModel::current(), options);
    const double initialAuditSeconds = seconds(initialAuditStart);
    const auto initialClosestCadStart = Clock::now();
    const auto initialClosestCad = auditClosestCad(GModel::current(), args.target);
    const double initialClosestCadSeconds = seconds(initialClosestCadStart);
    const auto optimizerStart = Clock::now();
    const auto result =
      QuadOptimizer::optimizeSmallQuadCavitiesAllFacesV2(options);
    const double optimizerSeconds = seconds(optimizerStart);
    const auto finalAuditStart = Clock::now();
    const auto final =
      QuadOptimizer::summarizeQuadMeshQuality(GModel::current(), options);
    const double finalAuditSeconds = seconds(finalAuditStart);
    const auto finalClosestCadStart = Clock::now();
    const auto finalClosestCad = auditClosestCad(GModel::current(), args.target);
    const double finalClosestCadSeconds = seconds(finalClosestCadStart);

    const auto writeStart = Clock::now();
    gmsh::option::setNumber("Mesh.MshFileVersion", 4.1);
    gmsh::option::setNumber("Mesh.Binary", 0.);
    gmsh::option::setNumber("Mesh.SaveAll", 1.);
    gmsh::option::setNumber("Mesh.SaveParametric", 1.);
    gmsh::write(args.output);
    const double writeSeconds = seconds(writeStart);

    std::ofstream report(args.report);
    if(!report) throw std::runtime_error("Cannot open report: " + args.report);
    report << std::setprecision(17);
    {
      JsonObject json(report);
      json.field("schemaVersion", 2);
      json.field("cadContractMetric",
                 std::string(QuadOptimizer::CadDistance::metricId()));
      json.field("input", args.input);
      json.field("output", args.output);
      json.field("geometry", args.geometry);
      json.key("configuration");
      {
        JsonObject configuration(report);
        configuration.field("schedule", args.schedule);
        configuration.field("searchMode", args.searchMode);
        configuration.field("searchCandidateLimit", args.searchCandidates);
        configuration.field("targetSize", args.target);
        configuration.field("minimumEdgeLength", args.minimum);
        configuration.field("maximumEdgeLength", args.maximum);
        configuration.field("maximumOptimizationPasses", args.maximumPasses);
        configuration.field("maximumAcceptedCavities", args.maximumAccepted);
        configuration.field("finalSmoothingPasses", args.smoothingPasses);
        configuration.field("smartLaplacian", args.smartLaplacian);
        configuration.field("activeNodalSmoothing", args.activeNodalSmoothing);
        configuration.field("finalWinslowPasses", args.finalWinslowPasses);
        configuration.field("terminalWinslowPasses", args.terminalWinslowPasses);
        configuration.field("terminalMandatoryCleanup", args.terminalMandatory);
        configuration.field("qualitySwaps", args.qualitySwaps);
        configuration.field("finalSplitCadDistanceRatio", args.finalSplitCadRatio);
        configuration.field("finalPairCleanup", args.finalPairs);
      }
      json.key("timingsSeconds");
      {
        JsonObject timings(report);
        timings.field("load", loadSeconds);
        timings.field("initialAudit", initialAuditSeconds);
        timings.field("initialClosestCadAudit", initialClosestCadSeconds);
        timings.field("optimizer", optimizerSeconds);
        timings.field("finalAudit", finalAuditSeconds);
        timings.field("finalClosestCadAudit", finalClosestCadSeconds);
        timings.field("write", writeSeconds);
      }
      json.key("initial");
      writeAudit(report, initial);
      json.key("final");
      writeAudit(report, final);
      json.key("closestCadInitial");
      writeClosestCadAudit(report, initialClosestCad, args.target);
      json.key("closestCadFinal");
      writeClosestCadAudit(report, finalClosestCad, args.target);
      json.key("optimizer");
      writeResult(report, result);
    }
    report << '\n';
    report.close();
    if(!report) throw std::runtime_error("Could not write report: " + args.report);
    std::cout << "QUAD_V2_REPORT " << quoted(args.report) << '\n';
    gmsh::finalize();
    initialized = false;
    return result.success && initial.success && final.success ? 0 : 2;
  }
  catch(const std::exception &error) {
    std::cerr << "gmshQuadV2Strategy: " << error.what() << '\n';
  }
  catch(...) {
    std::string error = "Gmsh operation failed";
    if(initialized) {
      try { gmsh::logger::getLastError(error); }
      catch(...) {}
    }
    std::cerr << "gmshQuadV2Strategy: " << error << '\n';
  }
  if(initialized) {
    try { gmsh::finalize(); }
    catch(...) {}
  }
  return 1;
}
