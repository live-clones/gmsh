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
#include "alphaShape_ocTree2.h"

extern "C" {
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetOpti.h"
#include "hxt_tetColor.h"
#include "hxt_tetFlag.h"
#include "hxt_tetRefine.h"
#include "hxt_alphashape.h"
}


struct alphaShapeBndEdge {
  double x0, y0, x1, y1;
  int tag;
};

void _computeAlphaShape3D(const std::vector<int> & alphaShapeTags, const double alpha, const double hMean,
                        std::function<double(int, int, double, double, double, double)> sizeFieldCallback, 
                        const int triangulate, const int refine);

void _decimateTriangulation(const int faceTag, const double thresholdDistance);

PolyMesh* _alphaShapeDelaunay2D(const int tag, const std::string boundaryModelName);

void _alphaShape2D(PolyMesh* pm, const double alpha, const int faceTag, const int bndTag, const int sizeFieldTag, const bool usePreviousMesh = false);

void _edgeRecover(PolyMesh* pm, const int tag, const int bndTag, const std::string & boundaryModel, std::vector<PolyMesh::Vertex*> & controlNodes, OctreeNode<2, 32, alphaShapeBndEdge*> &bnd_octree, const double boundary_tol);

void _delaunayRefinement(PolyMesh* pm, const int tag, const int bndTag, const int sizeFieldTag, std::vector<PolyMesh::Vertex*> & controlNodes);

void alphaShapePolyMesh2Gmsh(PolyMesh* pm, const int tag, const int bndTag, const std::string & boundaryModel, OctreeNode<2, 32, alphaShapeBndEdge*> &bnd_octree, const double boundary_tol);

void registerAlphaShapeField(FieldManager* fm);

void _createBoundaryOctree(const std::string & boundaryModel, const int bndTag, OctreeNode<2, 32, alphaShapeBndEdge*>& octree, std::vector<alphaShapeBndEdge>& bndEdges);


#endif

#endif
