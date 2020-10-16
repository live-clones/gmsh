#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MLine.h"
#include "MTriangle.h"
#include "SVector3.h"

class MyMesh;

class Cross2D{
 private:
  int test;
 public:
  MyMesh *_mesh;  
  const MEdge *edge;
  double theta;
  Cross2D():_mesh(NULL),edge(NULL),theta(0.0){}
 Cross2D(MyMesh *m,const MEdge *e, double thetaNormal ):_mesh(m),edge(e),theta(thetaNormal){}
  SVector3 getClosestBranchToDirection(const SVector3 &direction){return SVector3();}
};

class MyMesh{
  
 private:
  std::map<MVertex *, std::vector<SVector3>, MVertexPtrLessThan> _darbouxFrameVertices;
  void _computeDarbouxFrameOnFeatureVertices();
  void _computeGaussCurv();
  void _computeGeodesicCurv(){};//probably useless, we will se later
  double _getAngleBetweenEdges(const MEdge &e,const MEdge &eRef, SVector3 &normal);
  
 public:
  std::set<MVertex *, MVertexPtrLessThan> featureVertices;
  std::set<MVertex *, MVertexPtrLessThan> singularities;
  std::map<MVertex *, int, MVertexPtrLessThan> singIndices;
  
  std::set<MLine *, MLinePtrLessThan> lines;
  std::map<MLine *, GEdge *, MLinePtrLessThan> linesEntities;

  std::set<const MEdge *> featureDiscreteEdges;
  std::map<const MEdge *, GEdge *> featureDiscreteEdgesEntities;
  std::set<const MEdge *> cutGraphDiscreteEdges;  
    
  std::set<MTriangle *, MElementPtrLessThan> triangles;
  std::vector<std::set<MTriangle *, MElementPtrLessThan>> trianglesPatchs;
  std::set<MEdge, MEdgeLessThan> edges;
  std::map<const MEdge *, bool> isFeatureEdge;
  std::map<const MEdge *, bool> isCutGraphEdge;

  std::map<MVertex *, std::set<const MEdge *>, MVertexPtrLessThan> featureVertexToEdges;
  std::map<MVertex *, std::set<MTriangle *, MElementPtrLessThan>, MVertexPtrLessThan> vertexToTriangles;
  std::map<MTriangle *, std::vector<const MEdge *>, MElementPtrLessThan> triangleToEdges;
  std::map<const MEdge *, std::vector<MTriangle *>> edgeToTriangles;

  std::map<MVertex *, double, MVertexPtrLessThan> gaussCurv;
  std::map<MVertex *, double, MVertexPtrLessThan> geodesicCurv;

  std::map<const MEdge *, SVector3> normals;
  std::map<MVertex *, SVector3, MVertexPtrLessThan> normalsVertex;
  std::map<const MEdge *, Cross2D> manifoldBasis;
  
  std::map<MVertex *, double, MVertexPtrLessThan> H;
  std::map<const MEdge *, Cross2D> crossField;
  
  /* MyMesh(){} */
  MyMesh(GModel *gm);
  MyMesh(MyMesh &orginalMesh);
  void getSingularities(GModel *gm);
  void updateEdgesAndVertexToTri();
  void updateNormals();
  void createPatchs();
  
  /* MyMesh(GFace *gf){} */
  //DBG
  void viewNormals();
  void viewPatchs();
  void viewDarbouxFrame(size_t i);
  void viewMult(std::map<MVertex *, int> &multVert);
  //
  void computeGeoCharac(){
    _computeDarbouxFrameOnFeatureVertices();
    _computeGeodesicCurv();	
    _computeGaussCurv();
  }
  void computeManifoldBasis();
};

class ConformalMapping{
 private:
  MyMesh *_currentMesh;
  GModel *_gm;
  
  /* std::map<MVertex *, int> _singIndices; */
  std::map<MVertex *, double, MVertexPtrLessThan> _distanceToFeatureAndSing;
  /* std::set<MVertex *, MVertexPtrLessThan> _featureVertices; */
  /* std::set<MVertex *, MVertexPtrLessThan> _singularities; */
    
  MyMesh *_initialMesh;
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> _featureToInitMeshVertex;
  std::map<const MEdge *, MEdge *> _featureToInitMeshEdge;
  MyMesh *_featureCutMesh;
  std::map<MVertex *, MVertex *, MVertexPtrLessThan> _cutGraphToFeatureMeshVertex;
  std::map<const MEdge *, MEdge *> _cutGraphToFeatureMeshEdge;
  MyMesh *_cutGraphCutMesh;
  std::set<MVertex *, MVertexPtrLessThan> _newVerticesInModel;
  std::set<MLine *, MElementPtrLessThan> _newLinesInModel;

  void _getFeatureVertAndSing(){};//deprecated
  void _computeDistancesToBndAndSing();
  void _cutMeshOnFeatureLines();
  void _createCutGraph();
  std::set<const MEdge *> _createEdgeTree();
  void _trimEdgeTree(std::set<const MEdge *> &edgeTree);
  void _computeH();
  void _cutMeshOnCutGraph();
  void _createManifoldBasis(){_currentMesh->computeManifoldBasis();}
  void _computeCrossesFromH(){}
  void _fitModelToInitMesh();
  void _fitModelToFeatureMesh();
  void _fitModelToCutGraphMesh();
  void _viewScalarVertex(std::map<MVertex *, double, MVertexPtrLessThan> &scalar, const std::string& viewName="defaultName");
  void _viewScalarTriangles(std::map<MVertex *, double, MVertexPtrLessThan> &scalar, std::set<MTriangle *, MElementPtrLessThan> &triangles, const std::string& viewName="defaultName");
  void _viewCrosses(std::map<const MEdge *, Cross2D> crossField, const std::string& viewName="Crosses");
  
 public:
  ConformalMapping(GModel *gm);
  ~ConformalMapping();
  static void _viewEdges(std::set<const MEdge*> &edges, const std::string& viewName="defaultName");
  static void _viewScalarEdges(std::map<const MEdge *, double> &scalar, const std::string& viewName="defaultName");
};
