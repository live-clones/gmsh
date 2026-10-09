// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Tests of the hierarchical basis functions: run with the name of a test, e.g.
//
//   hierarchicalBasisTests derivatives
//
// or with "reference file.txt" to compare with reference values ("reference
// file.txt write" to generate them). The program returns 0 if all the checks
// passed.

#include <chrono>
#include <cstdio>
#include <functional>
#include <map>
#include <stdexcept>
#include "gmsh.h"
#include "basisTest.h"

int main(int argc, char **argv)
{
  const std::map<std::string, std::function<void()>> tests = {
    {"counts", bt::testCounts},         {"derivatives", bt::testDerivatives},
    {"spaces", bt::testSpaces},         {"traces", bt::testTraces},
    {"conformity", bt::testConformity}, {"api", bt::testApi},
    {"periodic", bt::testPeriodic},     {"hierarchy", bt::testHierarchy},
    {"parts", bt::testParts},           {"l2", bt::testL2}};

  std::string name = argc > 1 ? argv[1] : "";
  if(!tests.count(name) && name != "reference") {
    std::printf("Usage: %s test, with test one of:", argv[0]);
    for(auto &t : tests) std::printf(" %s", t.first.c_str());
    std::printf(" reference (file.txt [write])\n");
    return 1;
  }

  gmsh::initialize();
  // no messages: the errors expected by the tests would be printed
  gmsh::option::setNumber("General.Verbosity", 0);
  // errors in the API throw exceptions, so that a failure cannot go unnoticed
  gmsh::option::setNumber("General.AbortOnError", 3);
  auto start = std::chrono::steady_clock::now();
  try {
    if(name == "reference") {
      if(argc < 3) throw std::runtime_error("missing reference file name");
      bt::testReference(argv[2], argc > 3 && std::string(argv[3]) == "write");
    }
    else
      tests.at(name)();
  } catch(std::exception &e) {
    bt::check(false, "%s: unexpected exception: %s", name.c_str(), e.what());
  }
  double t =
    std::chrono::duration<double>(std::chrono::steady_clock::now() - start)
      .count();
  std::printf("%s: %d checks, %d failures (%.1f s)\n", name.c_str(),
              bt::numChecks(), bt::numFailures(), t);
  gmsh::finalize();
  return bt::numFailures() ? 1 : 0;
}
