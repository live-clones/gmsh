#ifndef HXT_COMBINE_CPP_API_
#define HXT_COMBINE_CPP_API_

#include <vector>
#include <map>
#include <memory>

#include "hxt_combine_cell.h"
#include "hxt_message.h"
#include "algorithms.h"
#include "tet_mesh.h"

/**
* \file tet_mesh.h C++ API of the Combine module
* \author Jeanne Pellerin
*/

namespace HXTCombine {

/**
* \addtogroup Combine
* @{
*/


/**
* What HXTCombineCellStore::selectAlongFrames proposed and selected
*/
struct FrameSelectionStatistics {
  std::size_t nbProposedHexes = 0;
  std::size_t nbSelectedProposedHexes = 0;
  std::size_t nbFreeVertices = 0;
  std::size_t nbResidualHexes = 0;
  std::size_t nbFreeTets = 0;
  std::size_t nbProposedPrisms = 0;
  // wall and CPU times of the proposal of the candidate cells and of their
  // selection
  double wallCandidates = 0., cpuCandidates = 0.;
  double wallSelection = 0., cpuSelection = 0.;
};

/**
* API structure to create, store and select potential cells 
*
* \warning Implementation of member functions is distributed in several files
*/
class HXTCombineCellStore {
public:
  enum CELLTYPE {HEX, PRISM, PYRAMID, TET};
  static const unsigned int nbCellTypes = 4;

  HXTCombineCellStore(const TetMeshForCombining& mesh):
    mesh_(mesh)
  {
    cells_.resize(nbCellTypes-1);
    selectedCells_.resize(nbCellTypes);
  }

  /**
  * Appends the hexes proposed by a frame field: frames holds the 3 axes of
  * each vertex (9 values), sizes the edge length there (0: no proposal).
  * With startVertices, only from the vertices a with startVertices[a] set;
  * nbChoices (at most 3) neighbours of a are tried along each axis, but not
  * the combinations of the nbChoicesProposed nearest ones only, proposed
  * already by a previous call.
  */
  void computeGuidedHexes(double minQuality, const std::vector<double>& frames,
                          const std::vector<double>& sizes,
                          const std::vector<bool>* startVertices = nullptr,
                          unsigned int nbChoices = 1,
                          unsigned int nbChoicesProposed = 0);
  /**
  * Appends the prisms proposed by a frame field on the facets of the tets
  * with freeTets set
  */
  void computeGuidedPrisms(double minQuality, const std::vector<double>& frames,
                           const std::vector<double>& sizes,
                           const std::vector<bool>& freeTets);

  /**
  * Proposes the hexes along a frame field (see computeGuidedHexes) and
  * selects among them, proposes more around the vertices left in tets and
  * selects again, then, with prisms, the prisms on the tets left
  */
  void selectAlongFrames(double minQuality, const std::vector<double>& frames,
                         const std::vector<double>& sizes, bool prisms,
                         FrameSelectionStatistics* statistics = nullptr);

  /**
  * Incremental selection: selects among the cells of the type, keeping the
  * cells selected by the previous calls since resetSelection, whose
  * candidates may have been appended to since. Hexes are to be selected
  * before the other types.
  */
  void resetSelection();
  void selectCells(CELLTYPE type);

  unsigned int nbSelectedHexes() const;
  unsigned int nbSelectedPrisms() const;
  unsigned int nbSelectedPyramids() const;
  unsigned int nbSelectedTets() const;

  void saveMSH (const std::string& filename, std::array<bool,nbCellTypes> cellType);
  void saveMESH(const std::string& filename, std::array<bool,nbCellTypes> cellType);

public:
  HXTCombineCellArray& hexes() { return cells_[HEX]; }
  HXTCombineCellArray& prisms() { return cells_[PRISM]; }
  HXTCombineCellArray& pyramids() { return cells_[PYRAMID]; }

  std::vector<bool>& selectedHexes() { return selectedCells_[HEX]; }
  std::vector<bool>& selectedPrisms() { return selectedCells_[PRISM]; }
  std::vector<bool>& selectedPyramids() { return selectedCells_[PYRAMID]; }
  std::vector<bool>& selectedTets() { return selectedCells_[TET]; }

private:
  void updateSelectedTets();

  struct Selector;
  const TetMeshForCombining& mesh_;
  std::vector<HXTCombineCellArray> cells_;
  std::vector<std::vector<bool>> selectedCells_;
  std::shared_ptr<Selector> selector_;
};


/** 
* Compute the quality for all provided cells 
* \pre The array holding qualities is allocated and owned by the client
*/
void computeCellQualityVector(
  const TetMeshWrapper& tets, 
  const HXTCombineCellArray& cells,
  double* qualities);

double cellQualityAPI(const TetMeshWrapper& tets, const HXTCombineCell& cell);


/**
* \brief Returns the \param indices of unique instance of HXTCandidate cells
* \details Duplicates are detected using a normalized order on the cells vertices.
* The output size of indices gives the number of different cells in the \param cells vector.
*/
void uniqueCells(const HXTCombineCellArray& cells, vector<unsigned int>& indices);

void writeCandidateCellMESH(
  const HXTCombineCell& cell,
  const TetMeshWrapper& tetMesh,
  std::ofstream& out,
  bool withBoundaryTets);


} // namespace

#endif
