#include "automaticMeshSizeField.h"
#include "GModel.h"
#include "GRegion.h"
#include "MVertex.h"

#ifdef HAVE_HXT
extern "C" {
#include "hxt_edge.h"
#include "hxt_curvature.h"
#include "hxt_bbox.h"
}
#endif

double automaticMeshSizeField:: operator()(double X, double Y, double Z, GEntity *ge)
{
  double val = 1.e22;
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = hxtOctreeSearchOne(forest, X, Y, Z, &val);
  if (s == HXT_STATUS_OK){
    return val;
  }
  else Msg::Error ("Cannot find point %g %g %g in the octree",X,Y,Z);
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST for using automaticMeshSizeField");
#endif
  return val;
}

automaticMeshSizeField::~automaticMeshSizeField(){
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  if (forest)hxtForestDelete(&forest);
  if (forestOptions)hxtForestOptionsDelete(&forestOptions);
#endif
}


#if defined(HAVE_HXT) && defined(HAVE_P4EST)

HXTStatus Gmsh2Hxt(std::vector<GRegion *> &regions, HXTMesh *m,
		   std::map<MVertex *, int> &v2c,
		   std::vector<MVertex *> &c2v);


HXTStatus automaticMeshSizeField:: updateHXT(){

  //  printf("%d points per circle\n",_nPointsPerCircle);

  if (!update_needed)return HXT_STATUS_OK;

  if (forest)hxtForestDelete(&forest);
  if (forestOptions)hxtForestOptionsDelete(&forestOptions);

  update_needed = false;
  // --------------------------------------------------------
  // Soit on charge un fichier avec l'octree (ma préférence)
  // Soit on calcule "en live" l'octree ici


  // verify that only one region exists in the model
  if (GModel::current()->getNumRegions() != 1){
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

  // Compute curvature
  double           *curvatureCrossfield;
  double           *nodalCurvature;
  HXTEdges         *edges;
  HXT_CHECK(hxtEdgesCreate(mesh,&edges));
  HXT_CHECK(hxtCurvatureRusinkiewicz(mesh,&nodalCurvature,&curvatureCrossfield,edges,1));

  // compute rtree
  RTree<int , double,3> triRTree;
  HXTBbox          bbox_triangle;

  for(uint64_t i = 0; i < mesh->triangles.num; ++i){
    hxtBboxInit(&bbox_triangle);
    // Noeuds
    for(int j = 0; j < 3; ++j){
      double coord[3];
      int node = mesh->triangles.node[(size_t) 3*i+j];
      // Coordonnees
      for(int k = 0; k < 3; ++k){ coord[k] = mesh->vertices.coord[(size_t) 4*node+k]; }
      hxtBboxAddOne(&bbox_triangle, coord);
    }
    int K = (int)i;
    triRTree.Insert(bbox_triangle.min,bbox_triangle.max,K);
  }

  // compute bbox of the mesh
  double            bbox_vertices[6];
  HXTBbox           bbox_mesh;
  hxtBboxInit(&bbox_mesh);
  // Ajout de tous les points du maillages à la bounding box
  HXT_CHECK(hxtBboxAdd(&bbox_mesh, mesh->vertices.coord, mesh->vertices.num));
  for(int i = 0; i < 3; ++i){
    bbox_vertices[i  ] = 1.3*bbox_mesh.min[i];
    bbox_vertices[i+3] = 1.3*bbox_mesh.max[i];
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
  HXT_CHECK(hxtOctreeRefineToLevel(forest, 3/*_nRefine*/));
  // idéalement --> convergence
  int ITER = 0;
  if (forestOptions->nodePerTwoPi > 0){
    HXT_CHECK(hxtOctreeCurvatureRefine(forest, 3/*_nRefine*/));
    // ensuite lissage du gradient
    while (ITER++ < 4*_nRefine) {
      HXT_CHECK(hxtOctreeComputeLaplacian(forest));
      HXT_CHECK(hxtOctreeSetMaxGradient(forest));
    }
  }
  forestOptions->nodePerGap = _nPointsPerGap;
  printf("coucou\n");
  HXT_CHECK(hxtOctreeSurfacesProches(forest));
  ITER = 0;
  //  while (ITER++ < 4*_nRefine) {
  //    HXT_CHECK(hxtOctreeComputeLaplacian(forest));
  //    HXT_CHECK(hxtOctreeSetMaxGradient(forest));
  //  }

  HXT_CHECK(hxtEdgesDelete(&edges)       );
  HXT_CHECK(hxtFree(&curvatureCrossfield));
  HXT_CHECK(hxtFree(&nodalCurvature)              );
  HXT_CHECK(hxtMeshDelete(&mesh)                  );
  HXT_CHECK(hxtContextDelete(&context)            );
}

#endif

void automaticMeshSizeField:: update(){
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = updateHXT();
  if (s != HXT_STATUS_OK)Msg::Error ("Something went wrong when computing the octree");
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST for using automaticMeshSizeField");
#endif
};
