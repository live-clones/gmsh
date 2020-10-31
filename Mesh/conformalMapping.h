#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MLine.h"
#include "MTriangle.h"
#include "SVector3.h"

class MyMesh;

class Cross2D{
 private:
  std::vector<SVector3> _directions;
  void _computeDirections();  
 public:
  MyMesh *_mesh;  
  const MEdge *edge;
  double theta;
 Cross2D():_mesh(NULL),edge(NULL),theta(0.0){}
 Cross2D(MyMesh *m,const MEdge *e, double thetaNormal):_mesh(m),edge(e),theta(thetaNormal){_computeDirections();}
 Cross2D(std::vector<SVector3> dirCross):_mesh(NULL),edge(NULL),theta(0.0){
    _directions.push_back(dirCross[0]);_directions[0].normalize();
    _directions.push_back(dirCross[1]);_directions[1].normalize();
    _directions.push_back(dirCross[2]);_directions[2].normalize();
    if(fabs(dot(_directions[2],crossprod(_directions[0],_directions[1]))-1)>1e-10){
      std::cout << "wrong cross initialisation" << std::endl;
      std::cout << "dir0 X dir1:" << crossprod(_directions[0],_directions[1])[0] << " " << crossprod(_directions[0],_directions[1])[1] << " " << crossprod(_directions[0],_directions[1])[2] << std::endl;
      std::cout << "dir0: " << _directions[0][0] << " " << _directions[0][1] << " " << _directions[0][2] << std::endl;
      std::cout << "dir1: " << _directions[1][0] << " " << _directions[1][1] << " " << _directions[1][2] << std::endl;
      std::cout << "dir2: " << _directions[2][0] << " " << _directions[2][1] << " " << _directions[2][2] << std::endl;
      exit(0);
    }
  }
  SVector3 getClosestBranchToDirection(SVector3 direction);
  std::vector<SVector3> getDirections(){return _directions;}
  double getTheta(){return theta;};
  SVector3 getDirection(size_t iDir){return _directions[iDir];}
  SVector3 getEulerAngles(double &noNutation);
  SVector3 getEulerAngles(std::vector<SVector3> baseRef, double &noNutation);
  static std::vector<SVector3> getDirFromEulerAngles(const SVector3 &eulerAngles);
  static std::vector<SVector3> getDirFromEulerAngles(std::vector<SVector3> baseRef, const SVector3 &eulerAngles);
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
  std::vector<bool> canTrianglePatchBeComputed;
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
  std::map<MVertex *, double, MVertexPtrLessThan> potU;
  std::map<MVertex *, double, MVertexPtrLessThan> potV;
  std::map<const MEdge *, Cross2D> crossField;
  std::map<const MEdge *, double> thetaCF;
  
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
  void _tryFixSing(std::set<MTriangle*, MElementPtrLessThan> patchTri);
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
  void _restoreInitialMesh();
  void _transferCrossesCutToInit();
  void _computeHfromCrosses();
  void _cutMeshOnCutGraph();
  void _createManifoldBasis(){_currentMesh->computeManifoldBasis();}
  void _computeCrossesFromH();
  std::map<const MEdge*, SVector3> _getLifting(MyMesh *mesh, const std::set<MTriangle*, MElementPtrLessThan> &triangles, MTriangle* triangleInit, const SVector3 &dirRef);
  void _solvePotOnPatch(const std::set<MTriangle*, MElementPtrLessThan> &tri, const SVector3 &dirRef, std::map<MVertex *, double, MVertexPtrLessThan> &pot);
  void _computeParametrization();
  void _fitModelToInitMesh();
  void _fitModelToFeatureMesh();
  void _fitModelToCutGraphMesh();
  void _viewScalarVertex(std::map<MVertex *, double, MVertexPtrLessThan> &scalar, const std::string& viewName="defaultName");
  void _viewCrosses(std::map<const MEdge *, Cross2D> crossField, const std::string& viewName="Crosses");
  void _viewVectTri(std::map<const MTriangle *, SVector3, MElementPtrLessThan> vect, const std::string& viewName="Vector");
  
 public:
  ConformalMapping(GModel *gm);
  ~ConformalMapping();
  std::map<MTriangle *, std::vector<std::vector<SVector3>>> getTriEdgScaledCrosses();
  std::map<MVertex *, double, MVertexPtrLessThan> getH();
  static void _viewScalarTriangles(std::map<MVertex *, double, MVertexPtrLessThan> &scalar, std::set<MTriangle *, MElementPtrLessThan> &triangles, const std::string& viewName="defaultName");
  static void _viewEdges(std::set<const MEdge*> &edges, const std::string& viewName="defaultName");
  static void _viewScalarEdges(std::map<const MEdge *, double> &scalar, const std::string& viewName="defaultName");
  static void _viewCrossEdgTri(std::map<MTriangle *, std::vector<std::vector<SVector3>>> &crossEdgTri, const std::string& viewName="defaultName");
  
  static void computeScaledCrossesFromSingularities(GModel *gm,std::map<MTriangle *, std::vector<std::vector<SVector3>>> &crossEdgTri, std::map<MVertex *, double, MVertexPtrLessThan> &H){
    ConformalMapping cm(gm);
    crossEdgTri=cm.getTriEdgScaledCrosses();
    H=cm.getH();
    return;
  }
};
