#ifndef _ALPHA_SHAPES_H_
#define _ALPHA_SHAPES_H_
#include <vector>

#include "GmshConfig.h"
#ifdef HAVE_HXT
#include "meshGRegionHxt.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "GModel.h"
#include "Generator.h"
#include "meshGRegion.h"
#include "meshGFace.h"
#include "meshGEdge.h"
#include "meshPolyMesh.h"
#include "meshTriangulation.h"
#include "qualityMeasures.h"
#include "robustPredicates.h"

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
    const std::vector<double> &nodalSize,
	std::vector<size_t> &elements, 
	std::vector<std::vector<size_t> > &domains,
	std::vector<std::vector<size_t> > &boundaries,
	std::vector<size_t> &neigh);

void createHxtMesh_(const std::string &inputMesh, const std::vector<double>& coord, const std::string &outputMesh, std::vector<double> &pts, std::vector<size_t> &tets);

void constrainedAlphaShapes_(GModel* m, 
                            const int dim, 
                            const int tag,
                            const std::vector<double>& coord, 
                            const std::vector<int>& nodeTags,
                            const double alpha, 
                            const double meanValue,
                            std::vector<size_t> &tetrahedra, 
                            std::vector<std::vector<size_t> > &domains,
                            std::vector<std::vector<size_t> > &boundaries,
                            std::vector<size_t> &neigh,
                            double &hMean,
                            const std::vector<int> &controlTags);

void generateMesh_(const int dim, const int tag, const bool refine, const std::vector<double> &coord, const std::vector<int> &nodeTags);
#endif

void constrainedDelaunayRefinement_(const int dim, const int tag,
                                    const std::vector<std::pair<int, int>> &discreteDimTag,
                                    const std::vector<double> &sizeField, 
                                    const double minRadius, 
                                    std::vector<size_t> &newNodeTags, 
                                    std::vector<double>& newCoords, 
                                    std::vector<double>& newSizeField);


// internal functions, useless for outside
void getFacesToImprove(PolyMesh* pm, GFace* gf, std::vector<double>& sizeAtNodes, std::map<size_t, size_t>& g2v, std::map<size_t, double>& g2sizeAtNodes, std::vector<size_t>& facesToGrade, std::vector<size_t>& facesToImprove);
void getFaceVertices(PolyMesh::Face* face, PolyMesh::Vertex* vertices[3]);                          

#endif
