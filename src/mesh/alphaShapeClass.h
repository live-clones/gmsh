#ifndef _ALPHA_SHAPE_CLASS_H_
#define _ALPHA_SHAPE_CLASS_H_
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
#include "alphaShape_ocTree.h"
#include <unordered_set>


class AlphaShapeClass {
    struct _alphaShapeBndEdge {
      double x0, y0, x1, y1;
      int tag;
    };

    struct _meshTriangle {
        double x0, y0, x1, y1, x2, y2;
        size_t idx;
    };

    private:

        PolyMesh* _pm;
        std::string _name;
        SBoundingBox3d* _bb;

        OctreeNode<2, 32, _alphaShapeBndEdge*>* _GModelOctree; // Octree for the GModel boundary edges
        std::vector<_alphaShapeBndEdge> _bndEdges; // Boundary edges (of the boundary model) that are stored in the octree
        std::unordered_set<size_t> _bndNodes; // Boundary nodes (of the alpha shape)

        OctreeNode<2, 32, _meshTriangle*>* _alphaShapeOctree; // Octree for the old mesh (before refinement) to return the position of the new nodes in the old mesh
        std::vector<_meshTriangle> _meshTriangles;

        // Alpha shape mesh
        std::vector<size_t> _asNodes;                  // --> index in the (delaunay) polymesh
        std::vector<std::vector<size_t>> _asTriangles; // --> triplets of indices in _asNodes
        std::vector<std::vector<size_t>> _asEdges;     // --> pairs of indices in _asNodes
        
        std::vector<PolyMesh::Vertex*> _verticesInDelaunay; // Indices of the vertices in the delaunay mesh 

        void updateAlphaShapeMesh();

        static int delaunayCriterion(PolyMesh::HalfEdge *he, void* val);
        PolyMesh::Face *WalkGeneral(PolyMesh::Face *f, double x, double y, PolyMesh::HalfEdge** heBnd = nullptr);
        void initialize_rectangle(PolyMesh* pm, double xmin, double xmax, double ymin, double ymax);
        void faceInfo(PolyMesh::HalfEdge *he, double *x_center, double *R, double *quality);
        static int delaunayCriterionColors(PolyMesh::HalfEdge *he, void* val);
        void checkDelaunay(std::vector<PolyMesh::HalfEdge* > *_t = nullptr);
        void delaunayCheckColors(std::vector<PolyMesh::HalfEdge* > hes, std::vector<PolyMesh::HalfEdge* > *_t);

        void xyz2uvw(_meshTriangle *tri, double xyz[3], double uvw[3]);
        bool isInside(_meshTriangle *tri, double uvw[3]);
        void WalkAlphaShape(PolyMesh::Face *f, double* cc, PolyMesh::HalfEdge** heCandidate, bool* found, int* onEdgeFlag);
        void getVerticesWithinRadius(PolyMesh::Vertex* v, double R, std::vector<PolyMesh::Vertex*> * closeVertices);
        bool boundaryCheck(PolyMesh::Vertex* v);

    public:
        AlphaShapeClass(const std::string &name = "");
        ~AlphaShapeClass();

        void clear(); // Clear the alpha shape

        // Function to add vertices to the alpha shape
        void triangulate(const std::vector<double> &vertices, const bool removeExistingVertices);

        // Compute the alpha shape 
        void alphaShape2D(const double alpha, const std::vector<double> &sizeAtElements);

        // Get all nodes
        void getNodes(std::vector<double> &vertices);

        // Get all elements
        void getElements(std::vector<size_t> &elementNodes);
        
        // Filter nodes if too close
        void filterNodes(const std::vector<double> &sizeAtNodes, const double tolerance);

        // Refine boundary edges of alpha shape
        void edgeRefine(const std::vector<size_t> &nodeTags, const std::vector<double>& sizeAtNodes, const double tolerance);

        // Refine the volume mesh of alpha shape
        void volumeRefine(const std::vector<size_t> &nodeTags, const std::vector<double>& sizeAtNodes, const double minQualityLimit, const double minSizeLimit);

        // Chew's algorithm for refinement (volume + boundary)
        void applyChew(const std::vector<double>& sizeAtNodes, const double minQualityLimit, const double minSizeLimit);

        // Move nodes
        void moveNodes(const std::vector<double> & displacement, const bool recoverDelaunay);

        // Set the Model for the boundary of the problem (a GModel) --> creates an octree of the faces of the model
        void setBoundaryModel(const std::string & bModel);

        // Match the boundary of the alpha shape with a GModel
        void matchAlphaShapeWithModel(const std::string & boundaryModelName, const double tolerance, std::vector<int> & coloredEdges);

        // Correct displacement so the nodes stay inside the boundary model
        void correctDisplacement(const std::vector<double> & dx, const double tolerance, std::vector<double>& correctedDx);

        // Create an octree on the triangles of the alpha shape
        // This is used to find the position of the new nodes in the old mesh
        void createAlphaShapeOctree();

        // Get the triangles and parametric coordinates in the triangles for given points
        void getTrianglesAndParametricCoords(const std::vector<double> & points, std::vector<size_t> & triangles, std::vector<double> & parametricCoords);

        // Get Clean alpha shape mesh, removing any nodes that are not part of the alpha shape
        void getAlphaShapeMesh(std::vector<double> & coords, std::vector<size_t> & triangles, std::vector<size_t> & edges);

        // Get The full delaunay mesh
        void getDelaunayMesh(std::vector<double> & coords, std::vector<size_t> & triangles);

        // Get/set methods for the alpha shape class
        static AlphaShapeClass *get(int tag);
        void set(int tag, AlphaShapeClass* as);


    // private:

};  

#endif

#endif
