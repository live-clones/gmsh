#ifndef HXT_TET_COMBINATION_API_H
#define HXT_TET_COMBINATION_API_H

#include <vector>

// returns 0 if everything worked right
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
			 std::vector<uint16_t> & pyramids_colors_out);
#endif
