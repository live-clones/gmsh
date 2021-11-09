#ifndef _ALPHA_SHAPES_H_
#define _ALPHA_SHAPES_H_
#include <vector>

int alphaShapes_ (const double threshold,
		  const std::vector<double> &pts,
		  std::vector<size_t> &tetrahedra, 
		  std::vector<std::vector<size_t> > &domains,
		  std::vector<std::vector<size_t> > &boundaries,
		  std::vector<size_t> &neigh);

#endif
