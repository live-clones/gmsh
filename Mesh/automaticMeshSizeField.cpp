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

  // Compute curvature
  double           *curvatureCrossfield;
  double           *nodalCurvature;
  HXTEdges         *edges;
  HXT_CHECK(hxtEdgesCreate(mesh,&edges));
  HXT_CHECK(hxtCurvatureRusinkiewicz(mesh,&nodalCurvature,&curvatureCrossfield,edges,1));
  
  // Compute rtree
  RTree<uint64_t, double, 3> triRTree;
  HXTBbox          bbox_triangle;

  for(uint64_t i = 0; i < mesh->triangles.num; ++i){
    hxtBboxInit(&bbox_triangle);
    if(i<10)printf("Triangle %d \n", i+1);
    // Noeuds
    for(uint64_t j = 0; j < 3; ++j){

      double coord[3];

      uint32_t node = mesh->triangles.node[3*i+j];
      // if(i<10)printf("%d \t", node);
      // if(i<10)printf("%" PRIu32 " \t", mesh->triangles.node[(size_t) 3*i+j]);
      // Coordonnees
      for(uint32_t k = 0; k < 3; ++k){ coord[k] = mesh->vertices.coord[(size_t) 4*node+k]; }
      if(i<10)printf("%f \t %f \t %f \n", coord[0], coord[1], coord[2]);
      hxtBboxAddOne(&bbox_triangle, coord);
    }
    // if(i<10)std::cout<<std::endl;
    // int K = (int) i;
    triRTree.Insert(bbox_triangle.min,bbox_triangle.max, i);
  }
  
  // compute bbox of the mesh
  double            bbox_vertices[6];
  HXTBbox           bbox_mesh;
  hxtBboxInit(&bbox_mesh);
  // Ajout de tous les points du maillages à la bounding box
  HXT_CHECK(hxtBboxAdd(&bbox_mesh, mesh->vertices.coord, mesh->vertices.num));
  for(int i = 0; i < 3; ++i){
    bbox_vertices[i  ] = 2.0*bbox_mesh.min[i];
    bbox_vertices[i+3] = 2.0*bbox_mesh.max[i];
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

  HXT_CHECK(hxtEdgesDelete(&edges)       );
  HXT_CHECK(hxtFree(&curvatureCrossfield));
  HXT_CHECK(hxtFree(&nodalCurvature)              );
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
