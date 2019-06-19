#include "automaticMeshSizeField.h"
#include "GModel.h"
#include "GRegion.h"
#include "MVertex.h"

#include <inttypes.h>

#ifdef HAVE_HXT
extern "C" {
#include "hxt_edge.h"
#include "hxt_curvature.h"
#include "hxt_bbox.h"
}
#endif  

double automaticMeshSizeField::operator()(double X, double Y, double Z, GEntity *ge) {  
#ifdef HAVE_HXT
  // return .2;
  double val = 1.e22;
  HXTStatus s = hxtOctreeSearchOne(forest, X, Y, Z, &val);
  if (s == HXT_STATUS_OK){
    return val;
  }
  else Msg::Error ("Cannot find point %g %g %g in the octree",X,Y,Z);
  return val;
#else
  Msg::Error ("Gmsh has to be compiled with HXT for using automaticMeshSizeField");
#endif  
}

automaticMeshSizeField::~automaticMeshSizeField(){
#ifdef HAVE_P4EST
  if (forest)hxtForestDelete(&forest);  
  if (forestOptions)hxtForestOptionsDelete(&forestOptions);
#endif
}  


#ifdef HAVE_HXT

HXTStatus Gmsh2Hxt(std::vector<GRegion *> &regions, HXTMesh *m,
		   std::map<MVertex *, int> &v2c,
		   std::vector<MVertex *> &c2v);

static inline int node2trianglescmp(const void *p0, const void *p1)
{ 
  uint64_t *e0 = (uint64_t*)p0;
  uint64_t *e1 = (uint64_t*)p1;
  
  if (e0[0] < e1[0]) return -1;
  if (e0[0] > e1[0]) return  1;
  return 0;
}

HXTStatus automaticMeshSizeField:: updateHXT(){
#ifdef HAVE_P4EST

  printf("%d points per circle\n",_nPointsPerCircle);

  if(!update_needed){
    printf("No update needed\n");
    return HXT_STATUS_OK;
  }
  if (forest)        HXT_CHECK(hxtForestDelete(&forest));  
  if (forestOptions) HXT_CHECK(hxtForestOptionsDelete(&forestOptions));

  
  update_needed = false;
  // --------------------------------------------------------
  // Soit on charge un fichier avec l'octree (ma préférence)
  // Soit on calcule "en live" l'octree ici

  
  // verify that only one region exists in the model
  if (GModel::current()->getNumRegions() != 1){
    printf("#regions = %d \n", GModel::current()->getNumRegions());
    Msg::Error ("automaticMeshSizeField can only work for now on models with one region");
    return HXT_STATUS_ERROR;
  }
  std::vector<GRegion*> regions;
  regions.push_back(*(GModel::current()->firstRegion()));
  // create HXT mesh structure
  HXTMesh *mesh;
  HXTContext *context;
  HXT_CHECK(hxtContextCreate(&context));
  HXT_CHECK(hxtMeshCreate(context, &mesh));
  std::map<MVertex *, int> v2c;
  std::vector<MVertex *> c2v;  
  Gmsh2Hxt(regions, mesh, v2c, c2v);

  printf("%d elements in the mesh \n", mesh->triangles.num);

  double *nodalCurvature;

  int computeCurvatureOnSeparateFaces = 0;

  if(computeCurvatureOnSeparateFaces){
    printf("#faces = %d\n",regions[0]->faces().size());

    HXT_CHECK(hxtMalloc(&nodalCurvature,6*mesh->vertices.num*sizeof(double))); 

    for(uint64_t i = 0; i < 6*mesh->vertices.num; ++i) nodalCurvature[i] = 0.0; 

    // // node2tri
    // uint64_t *node2tri;
    // HXT_CHECK(hxtMalloc(&node2tri,3*2*mesh->triangles.num*sizeof(uint64_t))); 
    // uint64_t counter = 0;
    // for (uint64_t i = 0; i<mesh->triangles.num; i++){
    //   node2tri[counter++] = mesh->triangles.node[3*i+0];
    //   node2tri[counter++] = i;
    //   node2tri[counter++] = mesh->triangles.node[3*i+1];
    //   node2tri[counter++] = i;
    //   node2tri[counter++] = mesh->triangles.node[3*i+2];
    //   node2tri[counter++] = i;
    // }
    
    // qsort(node2tri,3*mesh->triangles.num,2*sizeof(uint64_t),node2trianglescmp);

    for(size_t j = 0; j < regions[0]->faces().size(); j++) {
      // Create HXT mesh structure for each GFace
      HXTMesh *meshFace;
      HXT_CHECK(hxtMeshCreate(context, &meshFace));
      std::map<MVertex *, int> v2c2;
      std::vector<MVertex *> c2v2;  
      GmshFace2Hxt(regions, meshFace, v2c2, c2v2, j);

      printf("%d elements on face %d \n", meshFace->triangles.num, j);

      // Compute curvature
      double           *curvatureCrossfieldFace;
      double           *nodalCurvatureFace;
      HXTEdges         *edgesFace;
      HXT_CHECK(hxtEdgesCreate(meshFace,&edgesFace));
      HXT_CHECK(hxtCurvatureRusinkiewicz(meshFace,&nodalCurvatureFace,&curvatureCrossfieldFace,edgesFace,1));

      // node2tri local
      uint64_t *node2triLoc;
      HXT_CHECK(hxtMalloc(&node2triLoc,3*3*meshFace->triangles.num*sizeof(uint64_t))); 
      uint64_t counter = 0;
      for (uint64_t i = 0; i<meshFace->triangles.num; i++){
        node2triLoc[counter++] = meshFace->triangles.node[3*i+0];
        node2triLoc[counter++] = i;
        node2triLoc[counter++] = (uint64_t) 0;
        node2triLoc[counter++] = meshFace->triangles.node[3*i+1];
        node2triLoc[counter++] = i;
        node2triLoc[counter++] = (uint64_t) 1;
        node2triLoc[counter++] = meshFace->triangles.node[3*i+2];
        node2triLoc[counter++] = i;
        node2triLoc[counter++] = (uint64_t) 2;
      }
      qsort(node2triLoc,3*meshFace->triangles.num,3*sizeof(uint64_t),node2trianglescmp);

      // Replace curvature vectors on the face in global nodalCurvature structure
      uint64_t count = 0;
      for (uint64_t i = 0; i<9*meshFace->triangles.num; i+=3){
        uint64_t iVertex   = node2triLoc[i];
        uint64_t iTriangle = node2triLoc[i+1];
        uint64_t posInTri  = node2triLoc[i+2];
        uint64_t nodeGlobal = mesh->triangles.node[(size_t) 3*iTriangle+posInTri]; 
        // printf("iTriangle = %d \t posInTri = %d \t nodeGlobal = %d \t iVertex = %d \n", iTriangle, posInTri, nodeGlobal, iVertex);
        nodalCurvature[6 * nodeGlobal + 0] = fmax(nodalCurvature[6 * nodeGlobal + 0], nodalCurvatureFace[6 * count + 0]);
        nodalCurvature[6 * nodeGlobal + 1] = fmax(nodalCurvature[6 * nodeGlobal + 1], nodalCurvatureFace[6 * count + 1]);
        nodalCurvature[6 * nodeGlobal + 2] = fmax(nodalCurvature[6 * nodeGlobal + 2], nodalCurvatureFace[6 * count + 2]);
        nodalCurvature[6 * nodeGlobal + 3] = fmax(nodalCurvature[6 * nodeGlobal + 3], nodalCurvatureFace[6 * count + 3]);
        nodalCurvature[6 * nodeGlobal + 4] = fmax(nodalCurvature[6 * nodeGlobal + 4], nodalCurvatureFace[6 * count + 4]);
        nodalCurvature[6 * nodeGlobal + 5] = fmax(nodalCurvature[6 * nodeGlobal + 5], nodalCurvatureFace[6 * count + 5]);
        ++count;
      }

      HXT_CHECK(hxtFree(&node2triLoc));

      HXT_CHECK(hxtEdgesDelete(&edgesFace)       );
      HXT_CHECK(hxtFree(&curvatureCrossfieldFace));
      HXT_CHECK(hxtFree(&nodalCurvatureFace)              );
      HXT_CHECK(hxtMeshDelete(&meshFace)                  );
    }
  }
  else{
    // Compute curvature
    double           *curvatureCrossfield;
    HXTEdges         *edges;
    HXT_CHECK(hxtEdgesCreate(mesh,&edges));
    HXT_CHECK(hxtCurvatureRusinkiewicz(mesh,&nodalCurvature,&curvatureCrossfield,edges,1));

    HXT_CHECK(hxtEdgesDelete(&edges)       );
    HXT_CHECK(hxtFree(&curvatureCrossfield));
  }
  
  // Compute rtree
  RTree<uint64_t, double, 3> triRTree;
  HXTBbox          bbox_triangle;

  for(uint64_t i = 0; i < mesh->triangles.num; ++i){
    hxtBboxInit(&bbox_triangle);
    // Noeuds
    for(uint64_t j = 0; j < 3; ++j){
      double coord[3];
      uint32_t node = mesh->triangles.node[3*i+j];
      // Coordonnees
      for(uint32_t k = 0; k < 3; ++k){ coord[k] = mesh->vertices.coord[(size_t) 4*node+k]; }
      hxtBboxAddOne(&bbox_triangle, coord);
    }
    triRTree.Insert(bbox_triangle.min,bbox_triangle.max, i);
  }
  
  // compute bbox of the mesh
  double            bbox_vertices[6];
  HXTBbox           bbox_mesh;
  hxtBboxInit(&bbox_mesh);
  // Ajout de tous les points du maillages à la bounding box
  HXT_CHECK(hxtBboxAdd(&bbox_mesh, mesh->vertices.coord, mesh->vertices.num));
  for(int i = 0; i < 3; ++i){
    bbox_vertices[i  ] = 1.1*bbox_mesh.min[i];
    bbox_vertices[i+3] = 1.1*bbox_mesh.max[i];
  }
  
  // 1 --> OPTIONS ------------------------------------------
  HXT_CHECK(hxtForestOptionsCreate(&forestOptions));
  forestOptions->nodePerTwoPi = _nPointsPerCircle;  
  forestOptions->bbox = bbox_vertices;
  forestOptions->nodalCurvature = nodalCurvature;
  forestOptions->triRTree = &triRTree;
  forestOptions->mesh = mesh;
  forestOptions->sizeFunction = NULL;
  
  // --------------------------------------------------------
  HXT_CHECK(hxtForestCreate(0, NULL, &forest, NULL, forestOptions));
  //  return HXT_STATUS_OK;
  // ---------------------------------------------------------
  // aller --> niveau 3 par exemple, serait une option ...
  HXT_CHECK(hxtOctreeRefineToLevel(forest, 4/*_nRefine*/));
  // idéalement --> convergence
  int ITER = 0;
  if (forestOptions->nodePerTwoPi > 0){
    HXT_CHECK(hxtOctreeCurvatureRefine(forest, 10/*_nRefine*/));
    // ensuite lissage du gradient 

    double dsdx, dsdy, dsdz;

    while (ITER++ < 4*_nRefine) {
      dsdx = -1;
      dsdy = -1;
      dsdz = -1;
      printf("Lissage%d \n", ITER);
      HXT_CHECK(hxtOctreeComputeGradient(forest)); 

      HXT_CHECK(hxtOctreeComputeMaxGradientX(forest, &dsdx));
      HXT_CHECK(hxtOctreeComputeMaxGradientY(forest, &dsdy));
      HXT_CHECK(hxtOctreeComputeMaxGradientZ(forest, &dsdz));

      HXT_CHECK(hxtOctreeSetMaxGradient(forest));

      printf("dsdx max = %f \n", dsdx);
      printf("dsdy max = %f \n", dsdy);
      printf("dsdz max = %f \n", dsdz);
      // std::string fileVTK = "/home/bawina/Downloads/IMR Templates/Templates-IMR28/LaTeX/Pictures/smoothing_tore" + std::to_string(ITER);
      // write_ds_to_vtk(forest->p4est, fileVTK.c_str()); 
      if(fmax(dsdx,fmax(dsdy,dsdz)) < 0.41) break;
    }
  }

  double sizeMin = 1e22;
  HXT_CHECK(hxtOctreeComputeMinimumSize(forest,&sizeMin));
  printf("sizeMin = %f \n", sizeMin);

  forestOptions->nodePerGap = _nPointsPerGap;
  printf("------- Surfaces proches ------- \n");
  HXT_CHECK(hxtOctreeSurfacesProches(forest));

  sizeMin = 1e22;
  HXT_CHECK(hxtOctreeComputeMinimumSize(forest,&sizeMin));
  printf("sizeMin = %f \n", sizeMin);

  ITER = 0;

  double dsdx, dsdy, dsdz;

  while (ITER++ < 4*_nRefine) {
    dsdx = -1; 
    dsdy = -1;
    dsdz = -1;
    printf("Lissage après surfaces proches %d \n", ITER);
    HXT_CHECK(hxtOctreeComputeGradient(forest));  

    HXT_CHECK(hxtOctreeComputeMaxGradientX(forest, &dsdx));
    HXT_CHECK(hxtOctreeComputeMaxGradientY(forest, &dsdy));
    HXT_CHECK(hxtOctreeComputeMaxGradientZ(forest, &dsdz));

    HXT_CHECK(hxtOctreeSetMaxGradient(forest));

    printf("dsdx max = %f \n", dsdx);
    printf("dsdy max = %f \n", dsdy);
    printf("dsdz max = %f \n", dsdz);

    // std::string fileVTK = "/home/bawina/Downloads/IMR Templates/Templates-IMR28/LaTeX/Pictures/smoothing_tore" + std::to_string(ITER);
      // write_ds_to_vtk(forest->p4est, fileVTK.c_str()); 
    if(fmax(dsdx,fmax(dsdy,dsdz)) < 0.41) break;
   }

  double elemEstimation;
  HXT_CHECK(hxtOctreeElementEstimation(forest, &elemEstimation));
  printf("Estimation du nombre d'éléments : %f \n", elemEstimation);

  // HXT_CHECK(hxtEdgesDelete(&edges)       );
  // HXT_CHECK(hxtFree(&curvatureCrossfield));
  if(nodalCurvature) HXT_CHECK(hxtFree(&nodalCurvature)              );
  HXT_CHECK(hxtMeshDelete(&mesh)                  );
  HXT_CHECK(hxtContextDelete(&context)            );


  return HXT_STATUS_OK;

#endif //ifdef HAVE_P4EST
}
#endif

void automaticMeshSizeField:: update(){
#ifdef HAVE_HXT
  HXTStatus s = updateHXT();
  if (s != HXT_STATUS_OK)Msg::Error ("Something went wrong when computing the octree");
#else
  Msg::Error ("Gmsh has to be compiled with HXT for using automaticMeshSizeField");
#endif    
    
};
