#include <hxt_tet_combination_api.h>
#include <tet_mesh.h>
#include <hxt_combine_cpp_api.h>
#include <hxt_combine_cell.h>

int hxt_tet_combination (const std::vector<double> & coord,
			 const std::vector<unsigned int> & tets_in,
			 const std::vector<unsigned int> & triangles_in,
			 const std::vector<uint16_t> & tets_colors_in,
			 const std::vector<uint16_t> & triangles_colors_in,
			 const double & minQuality,
			 const int & doPrisms,
			 const int & doPyramids,
			 std::vector<unsigned int> & tets_out,
			 std::vector<unsigned int> & hexes_out,
			 std::vector<unsigned int> & prisms_out,
			 std::vector<unsigned int> & pyramids_out,
			 std::vector<uint16_t> & tets_colors_out,
			 std::vector<uint16_t> & hexes_colors_out,
			 std::vector<uint16_t> & prisms_colors_out,
			 std::vector<uint16_t> & pyramids_colors_out){
  
  using namespace HXTCombine;

  MeshStore ioMesh;
  
  std::vector<double> hxtcoord;
  buildhxtVertexFromCoordinates(coord, hxtcoord);   
  ioMesh.vertices = hxtcoord;
  ioMesh.tetCorners = tets_in;
  ioMesh.triangleCorners = triangles_in;
  ioMesh.tetColors = tets_colors_in;
  ioMesh.triangleColors = triangles_colors_in;
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
