#include "hxt_combine_cpp_api.h"

#include <cassert>
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <mutex>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include "tet_mesh.h"
#include "basic_types.h"
#include "hxt_combine_cell.h"
#include "candidate_cell.h"
#include "algorithms.h"
#include "combine_quality.h"
#include "compute_candidate_cells.h"

#include "hxt_omp.h"

/**
* \author Jeanne Pellerin
*/

namespace HXTCombine {

class StoreCandidateCells{
  /**
   * Amount of hexahedra stored in a buffer before trying.
   *
   * Increasing this value can decrease resource contention, but increases
   * memory consumption.
   */
  static constexpr std::size_t BUFFER_SIZE = 4096;

public:
  StoreCandidateCells(const TetMeshForCombining& tetMesh, double minQuality, vector<HXTCombineCell>& cells) :
    tets_(tetMesh), qualityThreshold_(minQuality),
    filler_(omp_get_max_threads(), cells)
  {
    // Reserving space definitely improves the performances on big models
    // But no real good guess. This depends a lot on the input mesh and on the min quality

    // It depends on the cell types, on the tet mesh, on the min quality !
    filler_.reserve(20*tetMesh.nbVertices());
  }

  void operator()(const vector<VertexIndex>& vertices)
  {
    int id = omp_get_thread_num();

    double quality = cellQuality(tets_, vertices);
    if (quality > qualityThreshold_ && isCellReallyValid(tets_, vertices)){
      CandidateCell &cell = filler_.emplaceBack( id, vertices, tets_);
      if(!cell.checkTetsTopology() || !cell.haveTetsSameColor() || !cell.checkQuadFacetColor() || !cell.checkQuadFacetBoundary() ) {
        filler_.popBack(id);
      }
    }
  }
  // For these pyramids..
  void operator()(const vector<VertexIndex>& vertices, TetIndex t0)
  {
    int id = omp_get_thread_num();

    double quality = cellQuality(tets_, vertices);
    if (quality > qualityThreshold_ && isCellReallyValid(tets_, vertices)) {
      CandidateCell &cell = filler_.emplaceBack(id, vertices, t0, tets_);
      if (!cell.checkTetsTopology() || !cell.haveTetsSameColor() || !cell.checkQuadFacetColor() || !cell.checkQuadFacetBoundary()) {
        filler_.popBack(id);
      }
    }
  }

  /**
   * Flushes the buffer of all threads.
   *
   * Must always be called once all cells have been found.
   */
  void flush() {
    filler_.flush();
  }

private:
  const TetMeshForCombining& tets_;
  const double qualityThreshold_;
  ParallelArrayFiller<HXTCombineCell, CandidateCell, CreateCombineCell> filler_;
};


struct CandidateCellStatistics {
  enum CellType { CUBE, BOTELLA, YAMAKAWA, ALL, FALSE_VALID, FAILED, COLOR_TETS, COLOR_FACETS };

  const std::string typeNames_[8]{
    "Cube", "Botella", "Yamakawa", "All Hexes", "False valid",
    "Invalid nb tets", "Invalid tet color", "Invalid facet color" };

  unsigned int data_[8] = { 0,0,0,0,0,0,0,0 };

  void addCell(const TetMeshForCombining& tets, const vector<VertexIndex>& vertices)
  {
    // Min scaled jacobian is above the threshold but the hex is not really valid.
    if (!isCellReallyValid(tets, vertices)) data_[FALSE_VALID]++;
    else {
      CandidateCell hex(vertices, tets);
      if (!hex.checkTetsTopology())        data_[FAILED]++;
      else if (!hex.haveTetsSameColor())   data_[COLOR_TETS]++;
      else if (!hex.checkQuadFacetColor() || !hex.checkQuadFacetBoundary()) data_[COLOR_FACETS]++;
      else {
        if (hex.isCubeDecomposition())      data_[CUBE]++;
        if (hex.isBotellaDecomposition())   data_[BOTELLA]++;
        if (hex.isYamakawaDecomposition())  data_[YAMAKAWA]++;
        data_[ALL]++;
      }
    }
  }
  void addCell(const TetMeshForCombining& tets, const vector<VertexIndex>& vertices, TetIndex t0)
  {
    // Min scaled jacobian is above the threshold but the hex is not really valid.
    if (!isCellReallyValid(tets, vertices)) data_[FALSE_VALID]++;
    else {
      CandidateCell hex(vertices, t0, tets);
      if (!hex.checkTetsTopology())        data_[FAILED]++;
      else if (!hex.haveTetsSameColor())   data_[COLOR_TETS]++;
      else if (!hex.checkQuadFacetColor() || !hex.checkQuadFacetBoundary()) data_[COLOR_FACETS]++;
      else {
        if (hex.isCubeDecomposition())      data_[CUBE]++;
        if (hex.isBotellaDecomposition())   data_[BOTELLA]++;
        if (hex.isYamakawaDecomposition())  data_[YAMAKAWA]++;
        data_[ALL]++;
      }
    }
  }

  void printCategories(std::ofstream& out) const
  {
    for (unsigned int i = 0; i <8; ++i)
      out << std::setw(20) << std::left << typeNames_[i];
  }
  void printData(std::ofstream& out) const
  {
    for (unsigned int i = 0; i <8; ++i)
      out << std::setw(20) << std::left << data_[i];
  }
  void operator+=(const CandidateCellStatistics& rhs)
  {
    for (unsigned int i = 0; i <8; ++i)
      data_[i] += rhs.data_[i];
  }
  void reset() {
    for (unsigned int i = 0; i < 8; ++i)
      data_[i]=0;
  }
};


/**
 * Specifically written to produce results for IMR 2017 and compare our algorithm
 * to the pattern based method
 */
class ClassifyCandidateHexes {
public:
  ClassifyCandidateHexes(const TetMeshForCombining& tetMesh, double minQuality,
    vector<CandidateCellStatistics>& nbHexesPerThreadPerType)
    :tets_(tetMesh), qualityThreshold_(minQuality), stats_(nbHexesPerThreadPerType)
  {
    stats_.resize(omp_get_max_threads());
  }
  void operator()(const vector<VertexIndex>& hexVertices)
  {
    if (cellQuality(tets_, hexVertices) > qualityThreshold_) {
      unsigned int iThread = omp_get_thread_num();
      stats_[iThread].addCell(tets_, hexVertices);
    }
  }
  void operator()(const vector<VertexIndex>& vertices, TetIndex t0)
  {
    double quality = cellQuality(tets_, vertices);
    if (quality > qualityThreshold_ ) {
      unsigned int iThread = omp_get_thread_num();
      stats_[iThread].addCell(tets_, vertices, t0);
    }
  }

private:
  const TetMeshForCombining& tets_;
  const double qualityThreshold_;
  vector<CandidateCellStatistics>& stats_;
};


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void countAndCompareCellsIMR(std::ofstream& out, TetMeshForCombining& tetMesh, const vector<double>& minQualities)
{
  CandidateCellStatistics stats;

  out << std::setw(20) << std::left << "Q min"
      << std::setw(20) << std::left << "timing";
  stats.printCategories(out);
  out << std::endl;

  unsigned int nbThreads = omp_get_max_threads();

  for (unsigned int i = 0; i < minQualities.size(); ++i) {
    double minQuality = minQualities[i];

    auto t0 = std::chrono::high_resolution_clock::now();

    vector<CandidateCellStatistics> threadStats(nbThreads);
    ClassifyCandidateHexes counter(tetMesh, minQuality, threadStats);

    computeAllHex(counter, tetMesh, minQuality);

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> countTiming(t1 - t0);

    stats.reset();
    for (unsigned int j = 0; j < nbThreads; ++j) {
      stats += threadStats[j];
    }

    out << std::setw(20) << std::left << minQuality
        << std::setw(20) << std::left << countTiming.count();
    stats.printData(out);
    out << std::endl;
  }
  // PRISMS
  for (unsigned int i = 0; i < minQualities.size(); ++i) {
    double minQuality = minQualities[i];

    auto t0 = std::chrono::high_resolution_clock::now();

    vector<CandidateCellStatistics> threadStats(nbThreads);
    ClassifyCandidateHexes counter(tetMesh, minQuality, threadStats);

    computeAllPrisms(counter, tetMesh, minQuality);

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> countTiming(t1 - t0);

    stats.reset();
    for (unsigned int j = 0; j < nbThreads; ++j) {
      stats += threadStats[j];
    }
    out << std::setw(20) << std::left << minQuality
      << std::setw(20) << std::left << countTiming.count();
    stats.printData(out);
    out << std::endl;
  }
  //PYRAMIDS
  for (unsigned int i = 0; i < minQualities.size(); ++i) {
    double minQuality = minQualities[i];

    auto t0 = std::chrono::high_resolution_clock::now();

    vector<CandidateCellStatistics> threadStats(nbThreads);
    ClassifyCandidateHexes counter(tetMesh, minQuality, threadStats);

    computeAllPyramids(counter, tetMesh, 0);

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> countTiming(t1 - t0);

    stats.reset();
    for (unsigned int j = 0; j < nbThreads; ++j) {
      stats += threadStats[j];
    }

    out << std::setw(20) << std::left << minQuality
      << std::setw(20) << std::left << countTiming.count();
    stats.printData(out);
    out << std::endl;
  }

  out << std::endl;
}


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void HXTCombineCellStore::computeHexes(double minQuality) {
  StoreCandidateCells store(mesh_, minQuality, hexes());

  computeAllHex(store, mesh_, minQuality);

  store.flush();
}
void HXTCombineCellStore::computePrisms(double minQuality) {
  StoreCandidateCells store(mesh_, minQuality, prisms());

  computeAllPrisms(store, mesh_, minQuality);

  store.flush();
}

void HXTCombineCellStore::computePyramids(double minQuality) {
  StoreCandidateCells store(mesh_, minQuality, pyramids());

  computeAllPyramids(store, mesh_, 0);

  store.flush();
}


void computePotentialHexes(
  TetMeshForCombining& tetMesh, double hexQualityThreshold, vector<HXTCombineCell>& hexes)
{
  StoreCandidateCells store(tetMesh, hexQualityThreshold, hexes);
  computeAllHex(store, tetMesh, hexQualityThreshold);
  store.flush();
}

void computePotentialPrisms(
  TetMeshForCombining& tetMesh, double prismQualityThreshold, vector<HXTCombineCell>& prisms)
{
  StoreCandidateCells store(tetMesh, prismQualityThreshold, prisms);
  computeAllPrisms(store, tetMesh, prismQualityThreshold);
  store.flush();
}



//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

double cellQualityAPI(const TetMeshWrapper& tets, const HXTCombineCell& cell) {
  if (cell.isHex()) {
    vec3 points[8];
    for (HexVertexIndex j = 0; j < 8; ++j) {
      points[j] = tets.point(cell.vertex(j));
    }
    return hexSubdivisionBasedQuality((::point3d*)points);
  }
  else if (cell.isPrism()) {
    vector<vec3> points(6);
    for (PrismVertexIndex j = 0; j <6; ++j) {
      points[j] = tets.point(cell.vertex(j));
    }
    return cellApproximateQuality<Prism>(points.data());
  }
  else if (cell.isPyramid()) {
    vector<vec3> points(5);
    for (CellVertexIndex j = 0; j < 5; ++j) {
      points[j] = tets.point(cell.vertex(j));
    }
    return cellApproximateQuality<Pyramid>(points.data());
  }
  else return 0;
}

void computeCellQualityVector(
  const TetMeshWrapper& tets,
  const std::vector<HXTCombineCell>& cells,
  double* qualities)
{
#pragma omp parallel for
  for (int i = 0; i < (int)cells.size(); ++i) {
    qualities[i] = cellQualityAPI(tets, cells[i]);
  }
}

}
