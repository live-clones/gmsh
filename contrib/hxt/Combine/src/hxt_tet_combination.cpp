#include <hxt_tet_combination.h>
#include <tet_mesh.h>
#include <hxt_combine_cpp_api.h>
#include <hxt_combine_cell.h>

int hxt_tet_combination (const std::vector<double> & coord,
			 const std::vector<size_t> & tets_in,
			 const std::vector<size_t> & triangles_in,
			 const std::vector<size_t> & tets_colors_in,
			 const std::vector<size_t> & triangles_colors_in,
			 const double & minQuality,
			 const int & doPrisms,
			 const int & doPyramids,
			 std::vector<size_t> & tets_out,
			 std::vector<size_t> & hexes_out,
			 std::vector<size_t> & prisms_out,
			 std::vector<size_t> & pyramids_out,
			 std::vector<size_t> & tets_colors_out,
			 std::vector<size_t> & hexes_colors_out,
			 std::vector<size_t> & prisms_colors_out,
			 std::vector<size_t> & pyramids_colors_out){
  
  using namespace HXTCombine;

  MeshStore ioMesh;
  
  std::vector<double> hxtcoord;
  buildhxtVertexFromCoordinates(coord, hxtcoord);   
  ioMesh.vertices = hxtcoord;
  ioMesh.tetCorners = tets_in;
  ioMesh.triangleCorners = triangles_in;
  ioMesh.tetColors = tets_colors;
  ioMesh.triangleCoolors = triangles_colors;
  computeTetAdjacencies(ioMesh);  

  TetMeshForCombining tets(&ioMesh);
  HXTCombineCellStore TheResult(tets);
  
  TheResult.computeHexes(minQuality);
  if (doPrisms)
    TheResult.computePrisms(minQuality);
  if (doPyramids)
    TheResult.computePyramids(minQuality);
  std::array<bool, 4> cellTypes { true, bool(doPrisms), bool(doPyramids), true };
  TheResult.selectCellsGreedy(cellTypes);

  return 0;
 
}
