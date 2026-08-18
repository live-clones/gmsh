#include "smallCavityOptimizer.h"

#include "gmsh.h"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  if(argc < 5 || argc > 6) {
    std::cerr << "Usage: gmshQuadOptimizer input.msh face-tag|all output.msh "
                 "quality.pos [maximum-accepted-cavities|--smooth-existing]\n";
    return 1;
  }
  try {
    gmsh::initialize();
    gmsh::open(argv[1]);
    const std::string faceArgument = argv[2];
    QuadOptimizer::SmallCavityOptimizerOptions options;
    options.verbose = 1;
    if(const char *verbosity = std::getenv("GMSH_QUADOPTIMIZER_VERBOSE"))
      options.verbose = std::atoi(verbosity);
    if(faceArgument == "all") {
      if(argc == 6) options.maximumAcceptedCavities = std::stoi(argv[5]);
      const auto optimizationStart = std::chrono::steady_clock::now();
      const auto result =
        QuadOptimizer::optimizeSmallQuadCavitiesAllFaces(options);
      const double optimizationSeconds =
        std::chrono::duration<double>(std::chrono::steady_clock::now() -
                                      optimizationStart)
          .count();
      if(!result.success ||
         !QuadOptimizer::writeModelQualityPos(argv[4])) {
        std::cerr << "Could not optimize all faces or write " << argv[4]
                  << '\n';
        gmsh::finalize();
        return 2;
      }
      gmsh::option::setNumber("Mesh.MshFileVersion", 4.1);
      gmsh::option::setNumber("Mesh.Binary", 0.);
      gmsh::write(argv[3]);
      std::cout << "facesVisited=" << result.facesVisited
                << " facesWithQuadrangles=" << result.facesWithQuadrangles
                << " acceptedTopologies=" << result.acceptedCavities
                << " optimizationSeconds=" << optimizationSeconds
                << " absoluteViolations="
                << result.initialObjective.absoluteViolationCount << "->"
                << result.finalObjective.absoluteViolationCount
                << " preferredViolations="
                << result.initialObjective.preferredViolationCount << "->"
                << result.finalObjective.preferredViolationCount << '\n';
      for(const auto &face : result.faces)
        std::cout << "face=" << face.faceTag
                  << " passes=" << face.optimizer.passes
                  << " acceptedDiamonds="
                  << face.optimizer.acceptedDiamonds
                  << " acceptedValence6="
                  << face.optimizer.acceptedValenceSixSplits
                  << " acceptedBoundaryTQT="
                  << face.optimizer.acceptedBoundaryTriangleQuadTriangleFans
                  << " finalSmooth="
                  << face.optimizer.acceptedFinalSmoothingCavities
                  << " acceptedI1="
                  << face.optimizer.acceptedOneInteriorVertexCavities
                  << " acceptedEdgeSwaps="
                  << face.optimizer.acceptedEdgeSwaps
                  << " rejectedEdgeNoIntersection="
                  << face.optimizer.rejectedEdgeSwapsNoIntersection
                  << " rejectedEdgeNonConvex="
                  << face.optimizer.rejectedEdgeSwapsNonConvex
                  << " acceptedI3="
                  << face.optimizer.acceptedThreeInteriorVertexCavities
                  << " acceptedI4="
                  << face.optimizer.acceptedFourInteriorVertexCavities
                  << " cavitiesVisited=" << face.optimizer.cavitiesVisited
                  << " optimizedCandidates="
                  << face.optimizer.topologyCandidatesOptimized << '\n';
      gmsh::finalize();
      return 0;
    }
    const int faceTag = std::stoi(faceArgument);
    if(argc == 6 && std::string(argv[5]) == "--smooth-existing") {
      options.verbose = 0;
      const auto optimizationStart = std::chrono::steady_clock::now();
      const auto result =
        QuadOptimizer::smoothExistingQuadCavities(faceTag, options);
      const double optimizationSeconds =
        std::chrono::duration<double>(std::chrono::steady_clock::now() -
                                      optimizationStart)
          .count();
      if(!result.success) {
        std::cerr << "Face " << faceTag << " was not found or smoothing "
                     "options are invalid\n";
        gmsh::finalize();
        return 2;
      }
      if(!QuadOptimizer::writeFaceQualityPos(faceTag, argv[4])) {
        std::cerr << "Could not write " << argv[4] << '\n';
        gmsh::finalize();
        return 3;
      }
      gmsh::option::setNumber("Mesh.MshFileVersion", 4.1);
      gmsh::option::setNumber("Mesh.Binary", 0.);
      gmsh::write(argv[3]);
      std::cout << "smoothingPasses=" << result.passes
                << " quadsVisited=" << result.quadsVisited
                << " admissibleCavities=" << result.admissibleCavities
                << " cavitiesOptimized=" << result.cavitiesOptimized
                << " accepted=" << result.acceptedCavities
                << " rejectedWinslow=" << result.rejectedByWinslow
                << " rejectedSize=" << result.rejectedBySize
                << " rejectedQuality=" << result.rejectedByQuality
                << " optimizationSeconds=" << optimizationSeconds
                << " absoluteViolations="
                << result.initialObjective.absoluteViolationCount << "->"
                << result.finalObjective.absoluteViolationCount
                << " preferredViolations="
                << result.initialObjective.preferredViolationCount << "->"
                << result.finalObjective.preferredViolationCount << '\n';
      gmsh::finalize();
      return 0;
    }
    if(argc == 6) options.maximumAcceptedCavities = std::stoi(argv[5]);
    const auto result =
      QuadOptimizer::optimizeSmallQuadCavities(faceTag, options);
    if(!result.success) {
      std::cerr << "Face " << faceTag << " was not found or optimizer "
                   "options are invalid\n";
      gmsh::finalize();
      return 2;
    }
    if(!QuadOptimizer::writeFaceQualityPos(faceTag, argv[4])) {
      std::cerr << "Could not write " << argv[4] << '\n';
      gmsh::finalize();
      return 3;
    }
    gmsh::option::setNumber("Mesh.MshFileVersion", 4.1);
    gmsh::option::setNumber("Mesh.Binary", 0.);
    gmsh::write(argv[3]);
    std::cout << "passes=" << result.passes
              << " cavitiesVisited=" << result.cavitiesVisited
              << " optimizedCandidates="
              << result.topologyCandidatesOptimized
              << " acceptedDiamonds="
              << result.acceptedDiamonds
              << " acceptedValence6="
              << result.acceptedValenceSixSplits
              << " acceptedBoundaryTQT="
              << result.acceptedBoundaryTriangleQuadTriangleFans
              << " finalSmooth="
              << result.acceptedFinalSmoothingCavities
              << " acceptedI1="
              << result.acceptedOneInteriorVertexCavities
              << " acceptedEdgeSwaps="
              << result.acceptedEdgeSwaps
              << " rejectedEdgeNoIntersection="
              << result.rejectedEdgeSwapsNoIntersection
              << " rejectedEdgeNonConvex="
              << result.rejectedEdgeSwapsNonConvex
              << " acceptedI3="
              << result.acceptedThreeInteriorVertexCavities
              << " acceptedI4="
              << result.acceptedFourInteriorVertexCavities
              << " absoluteViolations="
              << result.initialObjective.absoluteViolationCount << "->"
              << result.finalObjective.absoluteViolationCount
              << " preferredViolations="
              << result.initialObjective.preferredViolationCount << "->"
              << result.finalObjective.preferredViolationCount << '\n';
    gmsh::finalize();
    return result.success ? 0 : 4;
  }
  catch(const std::exception &error) {
    std::cerr << "gmshQuadOptimizer: " << error.what() << '\n';
    if(gmsh::isInitialized()) gmsh::finalize();
    return 5;
  }
}
