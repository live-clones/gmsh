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
#include "hxt_tetFlag.h"
#include "hxt_tetRefine.h"
#include "hxt_alphashape.h"
}



void generateMesh_(const int dim, const int tag, const bool refine, const std::vector<double> &coord, const std::vector<size_t> &nodeTags);

void constrainedDelaunayRefinement_(const int dim, const int tag,
                                    const std::vector<size_t> &elementTags,
                                    const std::vector<size_t> &constrainedEdges,
                                    const std::vector<size_t> &nodeTags,
                                    const std::vector<double> &sizeField, 
                                    const double minRadius, 
                                    const double minQuality,
                                    std::vector<size_t> &newNodeTags, 
                                    std::vector<double>& newCoords, 
                                    std::vector<double>& newSizeField, 
                                    std::vector<std::vector<size_t>>& newConstrainedEdges,
                                    std::vector<size_t>& newElementsInRefinement);

void alphaShape_entity(const int dim, const int tag, const double alpha, const std::vector<size_t>& nodeTags, const std::vector<double>& sizeAtNodes, std::vector<std::vector<size_t>>& elementTags, std::vector<std::vector<size_t>>& edges);

void _computeAlphaShape3D(const std::vector<int> & alphaShapeTags, const double alpha, const double hMean,
                        std::function<double(int, int, double, double, double, double)> sizeFieldCallback, 
                        const int refine);

void _computeAlphaShape(const std::vector<int> & alphaShapeTags, const double alpha, const double hMean,
                        std::function<double(int, int, double, double, double, double)> sizeFieldCallback, 
                        const int triangulate, const int refine);

#endif

#endif
