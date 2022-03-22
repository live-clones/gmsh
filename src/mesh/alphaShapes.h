#ifndef _ALPHA_SHAPES_H_
#define _ALPHA_SHAPES_H_
#include <vector>

#include "meshGRegionHxt.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "GModel.h"
#include "Generator.h"
#include "meshGRegion.h"

extern "C" {
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetOpti.h"
#include "hxt_tetColor.h"
}

int computeTetNeighbors_ (const std::vector<size_t> &tetrahedra, std::vector<size_t> &neigh);

int alphaShapes_ (const double threshold,
	const int dim,
	const std::vector<double> &pts,
	std::vector<size_t> &elements, 
	std::vector<std::vector<size_t> > &domains,
	std::vector<std::vector<size_t> > &boundaries,
	std::vector<size_t> &neigh, 
	const double meanValue);

void createHxtMesh_(const std::string &inputMesh, const std::vector<double>& coord, const std::string &outputMesh, std::vector<double> &pts, std::vector<size_t> &tets);

void constrainedAlphaShapes_(GModel* m, 
                            const int dim, 
                            const std::vector<double>& coord, 
                            const std::vector<int>& nodeTags,
                            const double alpha, 
                            const double meanValue,
                            std::vector<size_t> &tetrahedra, 
                            std::vector<std::vector<size_t> > &domains,
                            std::vector<std::vector<size_t> > &boundaries,
                            std::vector<size_t> &neigh,
                            const std::vector<int> &controlTags);
#endif
