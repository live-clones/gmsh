#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MLine.h"
#include "MTriangle.h"
#include "SVector3.h"

class Cross2D{
 public:
  int test;
};

class MyMesh{
  
 private:
  std::map<MVertex *, std::vector<SVector3>, MVertexPtrLessThan> _darbouxFrameVertices;
  void _computeDarbouxFrameOnFeatureVertices();
  void _computeGaussCurv();
  void _computeGeodesicCurv(){}
  
 public:
  std::set<MVertex *, MVertexPtrLessThan> featureVertices;
  std::set<MVertex *, MVertexPtrLessThan> singularities;
  std::map<MVertex *, int> singIndices;
  
  std::set<MLine *, MLinePtrLessThan> lines;
  std::map<MLine *, GEdge *, MLinePtrLessThan> linesEntities;
  
  std::set<const MEdge *> featureDiscreteEdges;
  std::map<const MEdge *, GEdge *> featureDiscreteEdgesEntities;
    
  std::set<MTriangle *, MElementPtrLessThan> triangles;
  std::set<MEdge, MEdgeLessThan> edges;
  std::map<const MEdge *, bool> isFeatureEdge;

  std::map<MVertex *, std::set<const MEdge *>, MVertexPtrLessThan> featureVertexToEdges;
  std::map<MTriangle *, std::vector<const MEdge *>, MElementPtrLessThan> triangleToEdges;
  std::map<const MEdge *, std::vector<MTriangle *>> edgeToTriangles;

  std::map<MVertex *, double, MVertexPtrLessThan> gaussCurv;
  std::map<MVertex *, double, MVertexPtrLessThan> geodesicCurv;
  std::map<const MEdge *, SVector3> normals;
  std::map<MVertex *, SVector3, MVertexPtrLessThan> normalsVertex;
  std::map<const MEdge *, Cross2D> manifoldBasis;
  
  std::map<MVertex *, double, MVertexPtrLessThan> H;
  std::map<const MEdge *, Cross2D> cross2D;
  /* MyMesh(){} */
  MyMesh(GModel *gm);
  MyMesh(MyMesh &orginalMesh);
  void getSingularities(GModel *gm);
  void updateEdges();
  void updateNormals();
  
  /* MyMesh(GFace *gf){} */
  //DBG
  void viewNormals();
  void viewDarbouxFrame();
  void viewMult(std::map<MVertex *, int> &multVert);
  //
  void computeGeoCharac(){
    _computeDarbouxFrameOnFeatureVertices();
    _computeGeodesicCurv();	
    _computeGaussCurv();
  }
  void computeManifoldBasis(){

  }
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

  void _getFeatureVertAndSing(){
    /* for(const MEdge *e: _initialMesh->featureDiscreteEdges){ */
    /*   _initialMesh->featureVertices.insert(e->getVertex(0)); */
    /*   _initialMesh->featureVertices.insert(e->getVertex(1)); */
    /* } */
    //TODO singularities
    /* _singularities.insert(_gm->getMeshVertexByTag(1246)); */
    return;
  };
  void _computeDistancesToBndAndSing();
  void _cutMeshOnFeatureLines();
  void _createCutGraph();
  std::set<const MEdge *> _createEdgeTree();
  void _trimEdgeTree(std::set<const MEdge *> &edgeTree);
  void _cutMeshOnCutGraph(){}
  void _fitModelToInitMesh();
  void _fitModelToFeatureMesh();
  void _fitModelToCutGraphMesh();
  void _viewScalarVertex(std::map<MVertex *, double, MVertexPtrLessThan> &scalar, const std::string& viewName="defaultName");
  void _viewEdges(std::set<const MEdge*> &edges, const std::string& viewName="defaultName");
  
 public:
  ConformalMapping(GModel *gm);
  ~ConformalMapping();
};
