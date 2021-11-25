#ifndef HXT_TET_COMBINATION_API_H
#define HXT_TET_COMBINATION_API_H

#include <vector>

// returns 0 if everything worked right
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
			 std::vector<size_t> & pyramids_colors_out);
#endif
