#include "automaticMeshSizeField.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEntity.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "curvature.h"
#include "Numeric.h"
#include "robustPredicates.h"
#include "discreteEdge.h"

#include <queue>
#include <inttypes.h>

#ifdef HAVE_HXT
extern "C" {
// #include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_bbox.h"
#include "hxt_tetMesh.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetRefine.h"
#include "hxt_tetRepair.h"
#include "hxt_boundary_recovery.h"
#include "hxt_orientation3d.h"
#include "hxt_orientation3d_tools.h"
#include "hxt_orientation3d_io.h"
#include "hxt_uvw_parametrization.h"
#include "hxt_linear_system.h"
}
#endif

#if defined(HAVE_P4EST)
#include <p8est_search.h>
#endif

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
// Mark all the points which are in mesh->(points | lines) but not in triangles
// Used to get the empty mesh of 2D boundary mesh
static void markMeshPoints(HXTMesh* mesh, bool markTriangles){
  for(uint32_t i=0; i<mesh->vertices.num; i++)
    mesh->vertices.coord[4*i+3] = 0.0;
  for(uint64_t i=0; i<mesh->lines.num; i++)
    for(int j=0; j<2; j++)
      mesh->vertices.coord[4* mesh->lines.node[2*i+j] + 3] = 1.0;
  for(uint64_t i=0; i<mesh->points.num; i++)
    mesh->vertices.coord[4* mesh->points.node[i] + 3] = 1.0;
  if(markTriangles){
    for(uint64_t i=0; i<mesh->triangles.num; i++)
      for(int j=0; j<3; j++)
        mesh->vertices.coord[4* mesh->triangles.node[3*i+j] + 3] = 1.0;
  }
}

static HXTStatus emptyMesh2D(HXTMesh *mesh, bool keepTriangles, const char* filename){
  if(!keepTriangles){
    // Remove triangles
    HXT_CHECK(hxtAlignedFree(&mesh->triangles.node));
    HXT_CHECK(hxtAlignedFree(&mesh->triangles.color));
    mesh->triangles.num = mesh->triangles.size = 0;
  }
  // Add a single other point in (0,0,1)
  uint64_t n = mesh->vertices.num;
  Msg::Info("n = %d", n);
  if(mesh->vertices.size == n) {
    HXT_CHECK( hxtAlignedRealloc(&mesh->vertices.coord, 4*sizeof(double) * (n + 1)) );
    mesh->vertices.size++;
  }
  mesh->vertices.coord[4 * n + 0] = 0;
  mesh->vertices.coord[4 * n + 1] = 0;
  mesh->vertices.coord[4 * n + 2] = 1;
  mesh->vertices.num++;

  // Compute the Delaunay of only the point in mesh->points, mesh->lines and the one we added
  HXTNodeInfo* nodeInfo;
  HXT_CHECK( hxtAlignedMalloc(&nodeInfo, sizeof(HXTNodeInfo)*mesh->vertices.num) );
  markMeshPoints(mesh, keepTriangles);
  uint32_t numToInsert = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    if(mesh->vertices.coord[4 * i + 3]==1.0 || i==n) {
      nodeInfo[numToInsert].node = i;
      nodeInfo[numToInsert].status = HXT_STATUS_TRYAGAIN;
      numToInsert++;
    }
  }
  HXT_INFO("Creating an empty mesh with %u vertices", numToInsert);
  HXTDelaunayOptions delaunayOptions = {NULL, NULL, 0, 0, 0, 0, 0, 1, 0};
  HXT_CHECK( hxtDelaunaySteadyVertices(mesh, &delaunayOptions, nodeInfo, numToInsert) );
  HXT_INFO("Empty mesh finished\n");
  HXT_CHECK( hxtAlignedFree(&nodeInfo) );

  // Find the lines that are missing
  uint64_t nbMissingLines = 0;
  uint64_t* lines2TetMap;
  HXT_CHECK( hxtAlignedMalloc(&lines2TetMap, mesh->lines.num*sizeof(uint64_t)) );
  HXT_CHECK( hxtGetLines2TetMap(mesh, lines2TetMap, &nbMissingLines) );

  // Recover the missing lines
  if (nbMissingLines!=0){
    HXT_INFO("Recovering %" HXTu64 " missing edge(s)", nbMissingLines);

    uint32_t oldNumVertices = mesh->vertices.num;
    HXT_CHECK( hxt_boundary_recovery(mesh) );

    if(oldNumVertices < mesh->vertices.num) {
      HXT_INFO("Steiner(s) point(s) were inserted");
    }

    HXT_CHECK( hxtGetLines2TetMap(mesh, lines2TetMap, &nbMissingLines) );

    if(nbMissingLines!=0)
      return HXT_ERROR_MSG( HXT_STATUS_ERROR, "%" HXTu64 " constrained edge%s still missing (after recovery step).", nbMissingLines, (nbMissingLines>1)?"s are":" is" );

    HXT_INFO("Constrained lines and triangles recovered\n");
  }

  // HXT_INFO("Writing constrained 3D mesh");
  // HXT_CHECK(hxtMeshWriteGmsh(mesh, "out3D_constrained.msh"));

  // There will be exactly one triangle per non-ghost tetrahedron
  HXT_CHECK( hxtRemoveGhosts(mesh) );
  if(!keepTriangles){
    HXT_CHECK(hxtAlignedMalloc(&mesh->triangles.node, 3 * sizeof(uint32_t) * mesh->tetrahedra.num) );

    for(uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      for(int j=0; j<4; j++) {
        uint32_t n0 = mesh->tetrahedra.node[4 * i + getNode0FromFacet(j)];
        uint32_t n1 = mesh->tetrahedra.node[4 * i + getNode1FromFacet(j)];
        uint32_t n2 = mesh->tetrahedra.node[4 * i + getNode2FromFacet(j)];
        if(n0 != n && n1 != n && n2 != n) {
          // add the triangle
          mesh->triangles.node[3 * mesh->triangles.num + 0] = n0;
          mesh->triangles.node[3 * mesh->triangles.num + 1] = n1;
          mesh->triangles.node[3 * mesh->triangles.num + 2] = n2;
          mesh->triangles.num++;
          break;
        } 
      }
    }

    HXT_ASSERT_MSG(mesh->triangles.num == mesh->tetrahedra.num, "My math is broken... or is it the mesh ?");
  }

  HXT_CHECK(hxtMeshWriteGmsh(mesh, filename));


  // HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.color) );
  // HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.flag) );
  // HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.node) );
  // HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.neigh) );
  // mesh->tetrahedra.num = 0;
  // mesh->tetrahedra.size = 0;


  return HXT_STATUS_OK;
}

static inline void norme2(double v[3], double* norme2){
  *norme2 = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

static inline bool isPoint(double x1, double y1, double z1, double x2, double y2, double z2, double tol){
  return (fabs(x2 - x1) < tol && fabs(y2 - y1) < tol && fabs(z2 - z1) < tol);
}

void writeNodalCurvature(double *nodalCurvature, int size, const char *filename){
  FILE* f = fopen(filename, "w");
  if(f==NULL){
  printf("Erreur : fileOutput == NULL\n");
    exit(-1);
  }

  for(int i = 0; i < size; ++i){
    fprintf(f, "%f %f %f - %d\n",
      nodalCurvature[6 * i + 0],
      nodalCurvature[6 * i + 1],
      nodalCurvature[6 * i + 2],i);
    fprintf(f, "%f %f %f\n",
      nodalCurvature[6 * i + 3],
      nodalCurvature[6 * i + 4],
      nodalCurvature[6 * i + 5]);
  }
  fclose(f);
}

static HXTStatus getAllFacesOfAllRegions(std::vector<GRegion *> &regions, HXTMesh *m, std::vector<GFace *> &allFaces){
  std::set<GFace *, GEntityPtrLessThan> allFacesSet;
  if(m) {
    m->brep.numVolumes = regions.size();
    HXT_CHECK(hxtAlignedMalloc(&m->brep.numSurfacesPerVolume,
                               m->brep.numVolumes * sizeof(uint32_t)));
  }
  uint32_t to_alloc = 0;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    if(m) {
      m->brep.numSurfacesPerVolume[i] = f.size() + f_e.size();
      to_alloc += m->brep.numSurfacesPerVolume[i];
    }
    allFacesSet.insert(f.begin(), f.end());
    allFacesSet.insert(f_e.begin(), f_e.end());
  }
  allFaces.insert(allFaces.begin(), allFacesSet.begin(), allFacesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.surfacesPerVolume, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    for(size_t j = 0; j < f.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f[j]->tag();
    for(size_t j = 0; j < f_e.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f_e[j]->tag();
  }


   // printf("volume 0 has %d faces\n",m->brep.numSurfacesPerVolume[0]);
   // for (int i=0;i<m->brep.numSurfacesPerVolume[0];i++)printf("%d",m->brep.surfacesPerVolume[i]); printf("\n");

  return HXT_STATUS_OK;
}

static HXTStatus getAllEdgesOfAllFaces(std::vector<GFace *> &faces, HXTMesh *m, std::vector<GEdge *> &allEdges){
  if(m) {
    m->brep.numSurfaces = faces.size();
    HXT_CHECK(hxtAlignedMalloc(&m->brep.numCurvesPerSurface,
                               m->brep.numSurfaces * sizeof(uint32_t)));
  }
  uint32_t to_alloc = 0;

  std::set<GEdge *, GEntityPtrLessThan> allEdgesSet;
  for(std::size_t i = 0; i < faces.size(); i++) {
    std::vector<GEdge *> const &f = faces[i]->edges();
    std::vector<GEdge *> const &f_e = faces[i]->embeddedEdges();
    if(m) {
      m->brep.numCurvesPerSurface[i] = f.size() + f_e.size();
      to_alloc += m->brep.numCurvesPerSurface[i];
    }
    allEdgesSet.insert(f.begin(), f.end());
    allEdgesSet.insert(f_e.begin(), f_e.end());
  }
  allEdges.insert(allEdges.begin(), allEdgesSet.begin(), allEdgesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.curvesPerSurface, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < faces.size(); i++) {
    std::vector<GEdge *> const &f = faces[i]->edges();
    std::vector<GEdge *> const &f_e = faces[i]->embeddedEdges();
    for(size_t j = 0; j < f.size(); j++)
      m->brep.curvesPerSurface[counter++] = f[j]->tag();
    for(size_t j = 0; j < f_e.size(); j++)
      m->brep.curvesPerSurface[counter++] = f_e[j]->tag();
  }
  return HXT_STATUS_OK;
}

HXTStatus Gmsh2Hxt(std::vector<GFace *> &faces, std::vector<GRegion *> &regions, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v){
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t ntet = 0;
  uint64_t ntri = 0;
  uint64_t nedg = 0;

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    nedg += ge->lines.size();
    for(size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    ntri += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  // Vertices of the surface only
  size_t count = 0;
  c2v.resize(all.size());
  for(MVertex *v : all) {
    v2c[v] = count;
    c2v[count++] = v;
  }

  // Adding volume vertices to the set of all vertices
  for(size_t j = 0; j < regions.size(); j++) {
    GRegion *gr = regions[j];
    ntet += gr->tetrahedra.size();
    for(size_t i = 0; i < gr->tetrahedra.size(); i++) {
      all.insert(gr->tetrahedra[i]->getVertex(0));
      all.insert(gr->tetrahedra[i]->getVertex(1));
      all.insert(gr->tetrahedra[i]->getVertex(2));
      all.insert(gr->tetrahedra[i]->getVertex(3));
    }
  }

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  // Adding volume vertices to the maps
  c2v.resize(all.size());
  std::map<MVertex*, uint32_t>::iterator it;
  for(MVertex *v : all) {
    it = v2c.find(v);
    if(it == v2c.end()){
      v2c[v] = count;
      c2v[count++] = v;
    }
  }
  
  // Writing vertices in the mesh structure
  for(size_t i = 0; i < m->vertices.num; ++i) {
    m->vertices.coord[4 * i + 0] = c2v[i]->x();
    m->vertices.coord[4 * i + 1] = c2v[i]->y();
    m->vertices.coord[4 * i + 2] = c2v[i]->z();
    m->vertices.coord[4 * i + 3] = 0;
  }
  all.clear();

  m->lines.num = m->lines.size = nedg;
  uint64_t index = 0;

  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint32_t)));

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      m->lines.node[2 * index + 0] = v2c[ge->lines[i]->getVertex(0)];
      m->lines.node[2 * index + 1] = v2c[ge->lines[i]->getVertex(1)];
      m->lines.color[index] = ge->tag();
      index++;
    }
  }

  m->triangles.num = m->triangles.size = ntri;
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.color,
                             (m->triangles.num) * sizeof(uint32_t)));

  index = 0;
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.color[index] = gf->tag();
      index++;
    }
  }

  m->tetrahedra.num = m->tetrahedra.size = ntet;
  HXT_CHECK(hxtAlignedMalloc(&m->tetrahedra.node,
                             (m->tetrahedra.num) * 4 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->tetrahedra.color,
                             (m->tetrahedra.num) * sizeof(uint32_t)));
  index = 0;
  for(size_t j = 0; j < regions.size(); j++) {
    GRegion *gr = regions[j];
    for(size_t i = 0; i < gr->tetrahedra.size(); i++) {
      m->tetrahedra.node[4 * index + 0] = v2c[gr->tetrahedra[i]->getVertex(0)];
      m->tetrahedra.node[4 * index + 1] = v2c[gr->tetrahedra[i]->getVertex(1)];
      m->tetrahedra.node[4 * index + 2] = v2c[gr->tetrahedra[i]->getVertex(2)];
      m->tetrahedra.node[4 * index + 3] = v2c[gr->tetrahedra[i]->getVertex(3)];
      m->tetrahedra.color[index] = gr->tag();
      index++;
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus Gmsh2Hxt(std::vector<GFace *> &faces, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v){
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t ntri = 0;
  uint64_t nedg = 0;

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    nedg += ge->lines.size();
    for(size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    ntri += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(MVertex *v : all) {
    m->vertices.coord[4 * count + 0] = v->x();
    m->vertices.coord[4 * count + 1] = v->y();
    m->vertices.coord[4 * count + 2] = v->z();
    m->vertices.coord[4 * count + 3] = 0;
    v2c[v] = count;
    c2v[count++] = v;
  }
  all.clear();

  m->lines.num = m->lines.size = nedg;
  uint64_t index = 0;

  HXT_CHECK(hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint32_t)));

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      m->lines.node[2 * index + 0] = v2c[ge->lines[i]->getVertex(0)];
      m->lines.node[2 * index + 1] = v2c[ge->lines[i]->getVertex(1)];
      m->lines.color[index] = ge->tag();
      index++;
    }
  }

  m->triangles.num = m->triangles.size = ntri;
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.color,
                             (m->triangles.num) * sizeof(uint32_t)));

  index = 0;
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.color[index] = gf->tag();
      index++;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus Gmsh2Hxt(std::vector<GEdge*> &edges, HXTMesh *m, std::map<MVertex*, uint32_t> &v2c, std::vector<MVertex*> &c2v){
  std::set<MVertex *> all;
  uint64_t nedg = 0;

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    nedg += ge->lines.size();
    for(size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(MVertex *v : all) {
    m->vertices.coord[4 * count + 0] = v->x();
    m->vertices.coord[4 * count + 1] = v->y();
    m->vertices.coord[4 * count + 2] = v->z();
    m->vertices.coord[4 * count + 3] = 0;
    v2c[v] = count;
    c2v[count++] = v;
  }
  all.clear();

  m->lines.num = m->lines.size = nedg;
  uint64_t index = 0;

  HXT_CHECK(hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint32_t)));

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      m->lines.node[2 * index + 0] = v2c[ge->lines[i]->getVertex(0)];
      m->lines.node[2 * index + 1] = v2c[ge->lines[i]->getVertex(1)];
      m->lines.color[index] = ge->tag();
      index++;
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus Gmsh2HxtLocal(std::vector<GFace *> &faces, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v){
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t ntri = 0;
  uint64_t nedg = 0;

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    nedg += ge->lines.size();
    for(size_t i = 0; i < ge->lines.size(); i++) {
      // all.insert(ge->lines[i]->getVertex(0));
      // all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    ntri += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  // printf("%d vertices %d triangles\n",all.size(),ntri);

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(std::set<MVertex *>::iterator it = all.begin(); it != all.end(); it++) {
    m->vertices.coord[4 * count + 0] = (*it)->x();
    m->vertices.coord[4 * count + 1] = (*it)->y();
    m->vertices.coord[4 * count + 2] = (*it)->z();
    m->vertices.coord[4 * count + 3] = 0.0;
    v2c[*it] = count;
    c2v[count++] = *it;
  }
  all.clear();

  m->lines.num = m->lines.size = nedg;
  uint64_t index = 0;

  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint32_t)));

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      m->lines.node[2 * index + 0] = v2c[ge->lines[i]->getVertex(0)];
      m->lines.node[2 * index + 1] = v2c[ge->lines[i]->getVertex(1)];
      m->lines.color[index] = ge->tag();
      index++;
    }
  }

  m->triangles.num = m->triangles.size = ntri;
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.color,
                             (m->triangles.num) * sizeof(uint32_t)));

  index = 0;
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.color[index] = gf->tag();
      index++;
    }
  }
  return HXT_STATUS_OK;
}

// HXTStatus Gmsh2HxtGlobal(std::vector<GFace *> &faces, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v){
//   std::vector<GEdge *> edges;
//   HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
//   std::set<MVertex *> all;

//   uint64_t cumsum = 0;
//   uint64_t cumsumNoEdges = 0;
//   for(size_t j = 0; j < edges.size(); j++) {
//     GEdge *ge = edges[j];
//     cumsum += ge->lines.size();
//     for(size_t i = 0; i < ge->lines.size(); i++) {
//       all.insert(ge->lines[i]->getVertex(0));
//       all.insert(ge->lines[i]->getVertex(1));
//     }
//   }

//   for(size_t j = 0; j < faces.size(); j++) {
//     GFace *gf = faces[j];
//     cumsum += gf->triangles.size();
//     cumsumNoEdges += gf->triangles.size();
//     for(size_t i = 0; i < gf->triangles.size(); i++) {
//       all.insert(gf->triangles[i]->getVertex(0));
//       all.insert(gf->triangles[i]->getVertex(1));
//       all.insert(gf->triangles[i]->getVertex(2));
//     }
//   }

//   c2v.resize(cumsum);
//   all.clear();

//   cumsum = 0;
//   size_t count_c2v2 = 0;
//   for(size_t j = 0; j < faces.size(); ++j){
//     // all propre à la face
//     GFace *gf = faces[j];
//     cumsum += gf->triangles.size();
//     for(size_t i = 0; i < gf->triangles.size(); i++) {
//       all.insert(gf->triangles[i]->getVertex(0));
//       all.insert(gf->triangles[i]->getVertex(1));
//       all.insert(gf->triangles[i]->getVertex(2));
//     }
//     size_t count = 0;
//     for(std::set<MVertex *>::iterator it = all.begin(); it != all.end(); it++) {
//       v2c[*it] = count++;
//       c2v[count_c2v2++] = *it;
//     }
//     all.clear();
//   }

//   return HXT_STATUS_OK;
// }

/* ======================================================================================
   Functions from hxt_octree
   ====================================================================================== */

static bool rtreeCallback(uint64_t id, void *ctx) {
  std::vector<uint64_t>* vec = reinterpret_cast< std::vector<uint64_t>* >(ctx);
  vec->push_back(id);
  return true;
}

/* Create a p4est connectivity structure for the given bounding box. */
static p4est_connectivity_t * p8est_connectivity_new_cube(ForestOptions *forestOptions){
  const p4est_topidx_t num_vertices = 8;
  const p4est_topidx_t num_trees = 1;
  const p4est_topidx_t num_ett = 0;
  const p4est_topidx_t num_ctt = 0;

  double centreX = (forestOptions->bbox[0]+forestOptions->bbox[3]) / 2.0;
  double centreY = (forestOptions->bbox[1]+forestOptions->bbox[4]) / 2.0;
  double centreZ = (forestOptions->bbox[2]+forestOptions->bbox[5]) / 2.0;
  double cX      = (forestOptions->bbox[3]-forestOptions->bbox[0]) / 2.0;
  double cY      = (forestOptions->bbox[4]-forestOptions->bbox[1]) / 2.0;
  double cZ      = (forestOptions->bbox[5]-forestOptions->bbox[2]) / 2.0;

  double scalingFactor = 1.3; // The octree is this times bigger than the surface mesh's bounding box
  double c = scalingFactor * fmax(fmax(cX,cY),cZ);

  // TODO : Compute any bounding box, not necessarily aligned with the axes
  const double vertices[8 * 3] = {
    centreX-c, centreY-c, centreZ-c,
    centreX+c, centreY-c, centreZ-c,
    centreX-c, centreY+c, centreZ-c,
    centreX+c, centreY+c, centreZ-c,
    centreX-c, centreY-c, centreZ+c,
    centreX+c, centreY-c, centreZ+c,
    centreX-c, centreY+c, centreZ+c,
    centreX+c, centreY+c, centreZ+c,
  };
  const p4est_topidx_t tree_to_vertex[1 * 8] = {0, 1, 2, 3, 4, 5, 6, 7};
  const p4est_topidx_t tree_to_tree[1 * 6] = {0, 0, 0, 0, 0, 0};
  const int8_t         tree_to_face[1 * 6] = {0, 1, 2, 3, 4, 5};

  return p4est_connectivity_new_copy (num_vertices, num_trees, 0, 0,
              vertices, tree_to_vertex,
              tree_to_tree, tree_to_face,
              NULL, &num_ett, NULL, NULL,
              NULL, &num_ctt, NULL, NULL);
}

static p4est_connectivity_t * p8est_connectivity_new_square(ForestOptions *forestOptions){
  const p4est_topidx_t num_vertices = 8;
  const p4est_topidx_t num_trees = 1;
  const p4est_topidx_t num_ett = 0;
  const p4est_topidx_t num_ctt = 0;

  double centreX = (forestOptions->bbox[0]+forestOptions->bbox[3]) / 2.0;
  double centreY = (forestOptions->bbox[1]+forestOptions->bbox[4]) / 2.0;
  double cX      = (forestOptions->bbox[3]-forestOptions->bbox[0]) / 2.0;
  double cY      = (forestOptions->bbox[4]-forestOptions->bbox[1]) / 2.0;

  double scalingFactor = 1.5; // The octree is this times bigger than the surface mesh's bounding box
  double c = scalingFactor * fmax(cX,cY);

  // TODO : Compute any bounding box, not necessarily aligned with the axes
  const double vertices[8 * 3] = {
    centreX-c, centreY-c, 0.0,
    centreX+c, centreY-c, 0.0,
    centreX-c, centreY+c, 0.0,
    centreX+c, centreY+c, 0.0,
    centreX-c, centreY-c, 0.0,
    centreX+c, centreY-c, 0.0,
    centreX-c, centreY+c, 0.0,
    centreX+c, centreY+c, 0.0,
  };
  const p4est_topidx_t tree_to_vertex[1 * 8] = {0, 1, 2, 3, 4, 5, 6, 7};
  const p4est_topidx_t tree_to_tree[1 * 6] = {0, 0, 0, 0, 0, 0};
  const int8_t         tree_to_face[1 * 6] = {0, 1, 2, 3, 4, 5};

  return p4est_connectivity_new_copy (num_vertices, num_trees, 0, 0,
              vertices, tree_to_vertex,
              tree_to_tree, tree_to_face,
              NULL, &num_ett, NULL, NULL,
              NULL, &num_ctt, NULL, NULL);

}
static inline double bulkSize(double x, double y, double z, double hBulk){
  return hBulk;
}

/* Fills xyz[] with the coordinates of the center of the given tree cell. */
static inline void getCellCenter(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double xyz[3]){
  p4est_qcoord_t      half_length = P4EST_QUADRANT_LEN (q->level) / 2;
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x + half_length, q->y + half_length, q->z + half_length, xyz);
}

/* Fills min[] & max[] with the coordinates of the cell viewed as a bounding box. */
static inline void getCellBBox(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double min[3], double max[3]){
  p4est_qcoord_t      length = P4EST_QUADRANT_LEN (q->level);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x, q->y, q->z, min);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x + length, q->y + length, q->z + length, max);
}

/* Fills h with the dimension of the given cell (length of a cell edge). */
static void getCellSize(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double *h)
{
  double min[3], max[3];
  p4est_qcoord_t      length = P4EST_QUADRANT_LEN (q->level);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x, q->y, q->z, min);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x + length, q->y + length, q->z + length, max);
  // All cell edges are supposed to be the same length h (-:
  *h = fmax(max[0] - min[0],fmax(max[1] - min[1],max[2] - min[2]));
}

/* Callback used by p4est to initialize the user_data on each tree cell. */
static inline void initializeCell(p4est_t* p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions  *forestOptions = (ForestOptions *) p4est->user_pointer;
  size_data_t    *data = (size_data_t *) q->p.user_data;

  double center[3];
  getCellCenter(p4est, which_tree, q, center);

  // Set cell size
  data->size[0] = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
  if(forestOptions->aniso){
    data->size[1] = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
    data->size[2] = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
  }
  data->M = SMetric3(1. / (forestOptions->hbulk * forestOptions->hbulk));

  // Set size gradient to zero
  for(int i = 0; i < (forestOptions->aniso ? 9 : 3); ++i) data->ds[i] = 0.0;
  // Set cell dimension (edge length)
  getCellSize(p4est, which_tree, q, &(data->h));

  data->hasIntersection = false;
}

/* Creates (allocates) the forestOptions structure. */
HXTStatus forestOptionsCreate(ForestOptions **forestOptions){
  HXT_CHECK( hxtAlignedMalloc (forestOptions, sizeof(ForestOptions)) );
    if(*forestOptions == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  return HXT_STATUS_OK;
}

/* Destroys forestOptions. */
HXTStatus forestOptionsDelete(ForestOptions **forestOptions){
  HXT_CHECK(hxtFree(forestOptions));
  return HXT_STATUS_OK;
}

HXTStatus loadGlobalData(ForestOptions *forestOptions, const char *filename){
  FILE* f = fopen(filename,"r");
  char buf[BUFSIZ]={""};
  if(fgets(buf,BUFSIZ,f) == NULL){
    return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  }
  sscanf(buf, "%lf %lf", &forestOptions->hmin, &forestOptions->hmax);
  fclose(f);
  Msg::Info("Loaded global data from %s",filename);
  Msg::Info("Min size = %f", forestOptions->hmin);
  Msg::Info("Max size = %f", forestOptions->hmax);
  return HXT_STATUS_OK;
}

/* Creates a (sequential) forest structure by loading a p4est file. */
HXTStatus forestLoad(Forest **forest, const char* forestFile, const char *dataFile, ForestOptions *forestOptions){
  if(forestFile == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  HXT_CHECK( hxtMalloc(forest, sizeof(Forest)) );
  if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  HXT_CHECK(loadGlobalData(forestOptions, dataFile));

  p4est_connectivity_t *connect;
  sc_MPI_Comm mpicomm = sc_MPI_COMM_WORLD;
  int load_data = true;
  int autopartition = true;
  int broadcasthead = true;

  (*forest)->p4est = p4est_load_ext(forestFile, mpicomm, sizeof(size_data_t), load_data, autopartition, broadcasthead, (void*) forestOptions, &connect);

  ForestOptions *fO = (ForestOptions*) (*forest)->p4est->user_pointer;
  if(fO == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  return HXT_STATUS_OK;
}

/* Creates a (sequential) forest structure from the forestOptions information.
   The forest is not refined; it consists of the root octant.                   */
HXTStatus forestCreate(int argc, char **argv, Forest **forest, const char* filename, ForestOptions *forestOptions){

  HXT_CHECK( hxtMalloc (forest, sizeof(Forest)) );
  if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  int mpiret;
  sc_MPI_Comm mpicomm;
  p4est_connectivity_t *connect;

  /* Initialize MPI; see sc_mpi.h.
   * If configure --enable-mpi is given these are true MPI calls.
   * Else these are dummy functions that simulate a single-processor run. */
  mpiret = sc_MPI_Init (&argc, &argv);
  SC_CHECK_MPI(mpiret);
  mpicomm = sc_MPI_COMM_WORLD;

  /* These functions are optional.  If called they store the MPI rank as a
   * static variable so subsequent global p4est log messages are only issued
   * from processor zero.  Here we turn off most of the logging; see sc.h. */
  // sc_init(mpicomm, 1, 1, NULL, SC_LP_ESSENTIAL);
  // p4est_init(NULL, SC_LP_PRODUCTION);

  /* Create a connectivity from the bounding box */
  if(forestOptions->dim == 3){ connect = p8est_connectivity_new_cube(forestOptions); }
  else{ connect = p8est_connectivity_new_square(forestOptions); }

  if(connect == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  // #ifdef P4EST_WITH_METIS
  //   //  Use metis (if p4est is compiled with the flag '--with-metis') to
  //   //  * reorder the connectivity for better parititioning of the forest
  //   //  * across processors.
  //   p4est_connectivity_reorder(mpicomm, 0, conn, P4EST_CONNECT_FACE);
  // #endif /* P4EST_WITH_METIS */

  // Assign bulkSize callback if no sizeFunction is specified.
  if(forestOptions->sizeFunction == NULL) forestOptions->sizeFunction = &bulkSize;

  (*forest)->p4est = p4est_new(mpicomm, connect, sizeof(size_data_t), initializeCell, (void*) forestOptions);
  (*forest)->forestOptions = forestOptions;

  return HXT_STATUS_OK;
}

/* Deletes the forest structure. */
HXTStatus forestDelete(Forest **forest){
    /* Destroy the p4est structure. */
    p4est_connectivity_destroy((*forest)->p4est->connectivity);
    p4est_destroy((*forest)->p4est);
    /* Verify that allocations internal to p4est and sc do not leak memory.
     * This should be called if sc_init () has been called earlier. */
    // sc_finalize();
    /* This is standard MPI programs.  Without --enable-mpi, this is a dummy. */
    int mpiret = sc_MPI_Finalize();
    SC_CHECK_MPI(mpiret);

    HXT_CHECK(hxtFree(forest));

    return HXT_STATUS_OK;
}

/* ========================================================================================================
   FOREST REFINEMENT
   ======================================================================================================== */

/* Callback used by octreeRefineToBulkSize; returns 1 if the cells need refinement, 0 otherwise. */
static inline int refineToBulkSizeCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  size_data_t *data = (size_data_t *) q->p.user_data;
  return data->h > forestOptions->hbulk;
}

/* Used by curvatureRefine; returns 1 if the cell should be
   refined according to the surface mesh curvature, 0 otherwise. */
static int curvatureRefineCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions   *forestOptions = (ForestOptions *) p4est->user_pointer;
  double h;
  getCellSize(p4est, which_tree, q, &h);
  double center[3];
  getCellCenter(p4est, which_tree, q, center);

  double min[3], max[3], k1, k2;
  getCellBBox(p4est, which_tree, q, min, max);

  std::vector<uint64_t> candidates;
  forestOptions->bndRTree->Search(min, max, rtreeCallback, &candidates);

  if(!candidates.empty()){
    double kmax = -1.e22; // To get min curvature size
    double hf = DBL_MAX;  // To get min feature size
    for(auto const &bndElem : candidates){
      if(forestOptions->dim == 3){
        for(int i = 0; i < 3; ++i){
          int node = forestOptions->mesh2D->triangles.node[(size_t) 3*bndElem+i];
          // Curvature
          double *v1 = forestOptions->nodalCurvature + 6*node;
          double *v2 = forestOptions->nodalCurvature + 6*node + 3;
          norme2(v1, &k1);
          norme2(v2, &k2);
          kmax = fmax(kmax,fmax(k1,k2));
          // Feature size
          hf = fmin(hf, (*forestOptions->featureSizeAtVertices)[node]);
        }
      } else{
        for(int i = 0; i < 2; ++i){
          int node = forestOptions->mesh2D->lines.node[(size_t) 2*bndElem+i];
          kmax = forestOptions->nodalCurvature[node];
          hf = fmin(hf, (*forestOptions->featureSizeAtVertices)[node]);
        }
      }
    }

    // There is curvature and/or feature size : the cell size should
    // accurately represent the surface and the feature size, so as not
    // propagate small feature size far from the feature.
    // Cell is refined according to the chosen density of nodes.
    double hc = 2*M_PI/(forestOptions->nodePerTwoPi * kmax);
    double nElemPerCell = 2;

    if(h > fmax(forestOptions->hmin,fmin(hc/nElemPerCell, hf)) && h >= forestOptions->hmin){
      return 1;
    } else{
      return 0;
    }
  } else{ // candidates.empty()
    return 0; // If the cell has no intersection with the surface mesh, it is not refined.
  }
}

static int coarsenCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *children[]){
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;

  for(int n = 0; n < P4EST_CHILDREN; ++n){
    size_data_t *data = (size_data_t *) children[n]->p.user_data;

    double min[3], max[3];
    getCellBBox(p4est, which_tree, children[n], min, max);

    std::vector<uint64_t> candidates;
    forestOptions->bndRTree->Search(min, max, rtreeCallback, &candidates);

    // Cells are not merged if any one of them touches the surface mesh.
    if(!candidates.empty()) return 0;
    // Cells are not merged if the resulting cell size is > than hbulk.
    if(2.0*data->h > forestOptions->hbulk) return 0;
  }

  return 1;
}

static void assignSizeAfterRefinement(p4est_iter_volume_info_t * info, void *user_data){
  p4est_t            *p4est = info->p4est;
  p4est_quadrant_t   *q = info->quad;
  p4est_topidx_t      which_tree = info->treeid;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  ForestOptions      *forestOptions = (ForestOptions *) user_data;

  double h;
  getCellSize(p4est, which_tree, q, &h);
  double center[3];
  getCellCenter(p4est, which_tree, q, center);

  double min[3], max[3];
  getCellBBox(p4est, which_tree, q, min, max);

  std::vector<uint64_t> candidates;
  forestOptions->bndRTree->Search(min, max, rtreeCallback, &candidates);

  if(!candidates.empty()){
    double k1, k2, k1max = -1.0e22, k2max = -1.0e22, kmax = -1.0e22, hf = DBL_MAX;
    // for(std::vector<uint64_t>::iterator tri = candidates.begin(); tri != candidates.end(); ++tri){
    for(auto const &bndElem : candidates){
      if(forestOptions->dim == 3){
        for(int i = 0; i < 3; ++i){
          int node = forestOptions->mesh2D->triangles.node[(size_t) 3*bndElem+i];
          double *v1 = forestOptions->nodalCurvature + 6*node;
          double *v2 = forestOptions->nodalCurvature + 6*node + 3;
          norme2(v1, &k1);
          norme2(v2, &k2);
          k1max = fmax(k1max, fmax(k1,k2));
          k2max = fmax(k2max, fmin(k1,k2));
          kmax  = fmax(kmax,  fmax(k1,k2));
          hf = fmin(hf, (*forestOptions->featureSizeAtVertices)[node]);
        } 
      } else{
        for(int i = 0; i < 2; ++i){
          int node = forestOptions->mesh2D->lines.node[(size_t) 2*bndElem+i];
          kmax = forestOptions->nodalCurvature[node];
          hf = fmin(hf, (*forestOptions->featureSizeAtVertices)[node]);
        }
      }
    }

    data->size[0] = fmax(forestOptions->hmin, fmin(forestOptions->hmax, fmin(hf, 2*M_PI/(forestOptions->nodePerTwoPi * kmax)) ));
    
    if(forestOptions->aniso){
      if(forestOptions->dim == 3){
        data->size[0] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * k1max) ));
        data->size[1] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * k2max) ));
        data->size[2] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, hf ));
      } else{
        data->size[0] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * kmax) ));
        data->size[1] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, hf ));
      }
      // Msg::Info("k1 > k2 = %d %t Après limitation :h1 = %4.4e\t h2 = %4.4e\t hn = %4.4e\n", k1max >= k2max, data->size[0], data->size[1], data->size[2]);
    }
  }
  else{
    data->size[0] = fmax(forestOptions->hmin, fmin(forestOptions->hmax, data->size[0]));
    if(forestOptions->aniso){
      if(forestOptions->dim == 3){
        data->size[0] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[0] ));
        data->size[1] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[1] ));
        data->size[2] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[2] ));
      } else{
        data->size[0] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[0] ));
        data->size[1] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[1] ));
      }
    }
  }
}

HXTStatus forestRefine(Forest *forest){
  /* Refine recursively the tree until all cells' size is at most hbulk. */
  p4est_refine_ext(forest->p4est, 1, P4EST_QMAXLEVEL, refineToBulkSizeCallback, initializeCell, NULL);
  // Refine recursively with respect to the curvature
  p4est_refine_ext(forest->p4est, 1, P4EST_QMAXLEVEL, curvatureRefineCallback, initializeCell, NULL);
  // Coarsen
  p4est_coarsen_ext(forest->p4est, 1, 0, coarsenCallback, initializeCell, NULL);
  // Balance the octree to get 2:1 ratio between adjacent cells
  p4est_balance_ext(forest->p4est, P4EST_CONNECT_FACE, initializeCell, NULL);
  // Assign size on the new cells

  p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, assignSizeAfterRefinement, NULL, NULL, NULL);
  // p4est_iterate(forest->p4est, NULL, forest->forestOptions, assignSizeAfterRefinementAniso, NULL, NULL, NULL);

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   SIZE GRADIENT COMPUTATION & LIMITATION
   ======================================================================================================== */
static inline void resetCell(p4est_iter_volume_info_t * info, void *user_data){
  size_data_t   *data = (size_data_t *) info->quad->p.user_data;
  ForestOptions *forestOptions = (ForestOptions *) user_data;
  // Reset gradient.
  for(size_t i = 0; i < (forestOptions->aniso ? 9 : 3); ++i)
    data->ds[i] = 0.0;
}

static void computeGradientCenter(p4est_iter_face_info_t * info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t             *sides = &(info->sides);
  size_data_t            *data;
  size_data_t            *data_opp;
  ForestOptions          *forestOptions = (ForestOptions *) user_data;
  double                  s_avg;
  int                     which_face_opp;
  // Index of current face on the opposite cell (0 if current is 1 and vice versa).
  int                     iOpp;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  for(int k = 0; k < (forestOptions->aniso ? 3 : 1); ++k){
    if(sides->elem_count == 2){

      for(int i = 0; i < 2; i++){
        iOpp = 1 - i;
        which_face_opp = side[iOpp]->face; /* 0,1 == -+x, 2,3 == -+y, 4,5 == -+z */

        // s_avg is the average size on the P4EST_HALF opposite cells
        s_avg = 0;

        // Current cells are hanging
        if (side[i]->is_hanging){
          for(int j = 0; j < P4EST_HALF; j++){
            data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
            s_avg += data->size[k];
          }
          s_avg /= P4EST_HALF;

          data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;

          switch(which_face_opp){
            case 0 : data_opp->ds[3*k+0] -= 0.5 * (s_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 1 : data_opp->ds[3*k+0] += 0.5 * (s_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 2 : data_opp->ds[3*k+1] -= 0.5 * (s_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 3 : data_opp->ds[3*k+1] += 0.5 * (s_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 4 : data_opp->ds[3*k+2] -= 0.5 * (s_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 5 : data_opp->ds[3*k+2] += 0.5 * (s_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
          }
        }
        // Current cell is full
        else{
          data = (size_data_t *) side[i]->is.full.quad->p.user_data;
          if(side[iOpp]->is_hanging){

            // Current full - Opposite hanging
            double s_avg_opp = 0;
            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
              s_avg_opp += data_opp->size[k];
            }
            s_avg_opp /= P4EST_HALF;

            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
              switch(which_face_opp){
                case 0 : data_opp->ds[3*k+0] -= 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 1 : data_opp->ds[3*k+0] += 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 2 : data_opp->ds[3*k+1] -= 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 3 : data_opp->ds[3*k+1] += 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 4 : data_opp->ds[3*k+2] -= 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 5 : data_opp->ds[3*k+2] += 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              }
            }
          }
          else{
            // Current full - Opposite full
            data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
            switch(which_face_opp){
              case 0 : data_opp->ds[3*k+0] -= 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 1 : data_opp->ds[3*k+0] += 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 2 : data_opp->ds[3*k+1] -= 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 3 : data_opp->ds[3*k+1] += 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 4 : data_opp->ds[3*k+2] -= 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 5 : data_opp->ds[3*k+2] += 0.5 * (data->size[k] - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            }
          }
        }
      }
    }
  }
  // Nothing to do on the boundaries (0 flux)
}

static void computeGradientCenterAniso(p4est_iter_face_info_t * info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t             *sides = &(info->sides);
  size_data_t            *data;
  size_data_t            *data_opp;
  int                     which_face_opp;
  // Index of current face on the opposite cell (0 if current is 1 and vice versa).
  int                     iOpp;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  for(int k = 0; k < 3; ++k){
    if(sides->elem_count == 2){
      for(int i = 0; i < 2; i++){
        iOpp = 1 - i;
        which_face_opp = side[iOpp]->face; /* 0,1 == -+x, 2,3 == -+y, 4,5 == -+z */

        // Current cells are hanging
        if (side[i]->is_hanging){
          data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
          // Unit directions of the opposite cells
          SVector3 e(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);

          // Average sizes on the current cells based on neighboring directions
          double he_avg = 0.; // h2_avg = 0, h3_avg = 0;
          for(int j = 0; j < P4EST_HALF; ++j){
            data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
            // Length along these directions based on the current cell's metric
            he_avg += 1.0/sqrt(dot(e, data->M, e));
          }
          he_avg /= P4EST_HALF;

          switch(which_face_opp){
            case 0 : data_opp->ds[3*k+0] -= 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 1 : data_opp->ds[3*k+0] += 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 2 : data_opp->ds[3*k+1] -= 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 3 : data_opp->ds[3*k+1] += 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 4 : data_opp->ds[3*k+2] -= 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            case 5 : data_opp->ds[3*k+2] += 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
          }
        }
        // Current cell is full
        else{
          data = (size_data_t *) side[i]->is.full.quad->p.user_data;

          if(side[iOpp]->is_hanging){
            // Current full - Opposite hanging

            // double h1_avg = 0, h2_avg = 0, h3_avg = 0;
            // for(int j = 0; j < P4EST_HALF; ++j){
            //   data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
            //   // Unit directions of the opposite cells
            //   SVector3 e1(data_opp->dir[0k], data_opp->dir[k1], data_opp->dir[2k]); // A corriger avec 3*k+
            //   // Length along these directions based on the current cell's metric
            //   h1_avg += 1sqrt(dot(e1, data->M, e1));
            // }
            // h1_avg /= P4EST_HALF;

            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
              // Unit directions of the opposite cells
              SVector3 e(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);
              // Length along this direction based on the current cell's metric
              double he = 1.0/sqrt(dot(e, data->M, e));

              switch(which_face_opp){
                case 0 : data_opp->ds[3*k+0] -= 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 1 : data_opp->ds[3*k+0] += 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 2 : data_opp->ds[3*k+1] -= 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 3 : data_opp->ds[3*k+1] += 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 4 : data_opp->ds[3*k+2] -= 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
                case 5 : data_opp->ds[3*k+2] += 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              }
            }
          }
          else{
            // Current full - Opposite full
            data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
            // The unit direction of the opposite cell associated to size[k] 
            SVector3 e(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);
            // The length along this direction based on the current cell's metric
            double he = 1.0/sqrt(dot(e, data->M, e));

            switch(which_face_opp){
              case 0 : data_opp->ds[3*k+0] -= 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 1 : data_opp->ds[3*k+0] += 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 2 : data_opp->ds[3*k+1] -= 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 3 : data_opp->ds[3*k+1] += 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 4 : data_opp->ds[3*k+2] -= 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 5 : data_opp->ds[3*k+2] += 0.5 * (he - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            }
          }
        }
      }
    }
  }
  // Nothing to do on the boundaries (0 flux)
}

HXTStatus forestComputeGradient(Forest *forest){
  // Iterate on each cell to reset size gradient and half lengths.
  p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, resetCell, NULL, NULL, NULL);
  // Compute gradient at cell center using finite differences
  if(forest->forestOptions->aniso){
    p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, NULL, computeGradientCenterAniso, NULL, NULL);
  } else{
    p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, NULL, computeGradientCenter, NULL, NULL);
  }

  return HXT_STATUS_OK;
}

static inline void getMaxGradient(p4est_iter_volume_info_t * info, void *user_data)
{
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double           *gradMax = static_cast<double*>(user_data);
  for(int i = 0; i < 3; ++i)
    gradMax[i] = SC_MAX (fabs(data->ds[i]), gradMax[i]);
}

static inline void getMaxGradientAniso(p4est_iter_volume_info_t * info, void *user_data)
{
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double           *gradMax = static_cast<double*>(user_data);
  for(int i = 0; i < 9; ++i)
    gradMax[i] = SC_MAX (fabs(data->ds[i]), gradMax[i]);
}

static inline void getMinSize(p4est_iter_volume_info_t * info, void *user_data)
{
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double* minsize = (double*) user_data;
  *minsize = fmin(*minsize, data->size[0]);
}

HXTStatus forestGetMaxGradient(Forest *forest, double *gradMax){
  if(forest->forestOptions->aniso){
    p4est_iterate (forest->p4est, NULL, (void *) gradMax, getMaxGradientAniso, NULL, NULL, NULL);
  } else{
    p4est_iterate (forest->p4est, NULL, (void *) gradMax, getMaxGradient, NULL, NULL, NULL);
  }
  return HXT_STATUS_OK;
}

HXTStatus forestGetMinSize(Forest *forest, double *minsize){
  double minSize = 1e22;
  p4est_iterate(forest->p4est, NULL, (void*) &minSize, getMinSize, NULL, NULL, NULL);
  *minsize = minSize;
  return HXT_STATUS_OK;
}

static void limitSize(p4est_iter_face_info_t * info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t        *sides = &(info->sides);
  size_data_t       *data;
  size_data_t       *data_opp;
  int                which_dir;
  int                iOpp;

  ForestOptions     *forestOptions = (ForestOptions*) user_data;
  double             alpha = forestOptions->gradation - 1.0;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  if(sides->elem_count==2){

    for(int i = 0; i < 2; ++i){

      iOpp = 1 - i;
      which_dir = side[i]->face / 2; // Direction x (0), y (1) ou z(2)
      // which_face_opp = side[iOpp]->face;

      if(side[i]->is_hanging){

        // Current hanging - Opposes full
        data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;

        for(int j = 0; j < P4EST_HALF; ++j){

          data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;

          if(fabs(data->ds[which_dir]) > alpha){

            if(data->size[0] > data_opp->size[0]){
              data->size[0] = fmin(data->size[0], data_opp->size[0] + (alpha) * (data_opp->h/2. + data->h/2.));
            } else{
              data_opp->size[0] = fmin(data_opp->size[0], data->size[0] + (alpha) * (data_opp->h/2. + data->h/2.));
            }
          } // if ds > alpha-1
        } // for j hanging
      } // if hanging
      else{

        data = (size_data_t *) side[i]->is.full.quad->p.user_data;

        if(fabs(data->ds[which_dir]) > alpha){
          if(side[iOpp]->is_hanging){
              // Current full - Oppose hanging
            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
              if(data->size[0] > data_opp->size[0]){
                data->size[0] = fmin(data->size[0], data_opp->size[0] + (alpha) * (data_opp->h/2. + data->h/2.));
              } else{
                data_opp->size[0] = fmin(data_opp->size[0], data->size[0] + (alpha) * (data_opp->h/2. + data->h/2.));
              }
            }
          } else{
            // Current full - Oppose full
            data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
            if(data->size[0] > data_opp->size[0]){
              data->size[0] = fmin(data->size[0], data_opp->size[0] + (alpha) * (data_opp->h/2. + data->h/2.));
            } else{
              data_opp->size[0] = fmin(data_opp->size[0], data->size[0] + (alpha) * (data_opp->h/2. + data->h/2.));
            }
          }
        } // if gradient trop grand
      } // else
    }
  }
}

static void limitSizeAniso(p4est_iter_face_info_t * info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t        *sides = &(info->sides);
  size_data_t       *data;
  size_data_t       *data_opp;
  int                which_dir;
  // int                which_face_opp;
  int                iOpp;

  ForestOptions     *forestOptions = (ForestOptions*) user_data;
  double             alpha = forestOptions->gradation - 1.0;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  for(int k = 0; k < 3; ++k){
    if(sides->elem_count==2){

      for(int i = 0; i < 2; ++i){

        iOpp = 1 - i;
        which_dir = side[i]->face / 2; // Direction x (0), y (1) ou z(2)
        // which_face_opp = side[iOpp]->face;

        if(side[i]->is_hanging){

          // Current hanging - Opposes full
          data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
          SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);

          for(int j = 0; j < P4EST_HALF; ++j){
            data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
            SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
            double he = 1.0/sqrt(dot(e_opp, data->M, e_opp)); // Size of opposite directions in current metric
            double he_opp = 1.0/sqrt(dot(e, data_opp->M, e)); // Size of current directions in opposite metric

            if(fabs(data->ds[3*k+which_dir]) > alpha){

              if(data->size[k] > he_opp){
                data->size[k] = fmin(data->size[k], he_opp + (alpha) * (data_opp->h/2. + data->h/2.));
              } 
              if(data_opp->size[k] > he){
                data_opp->size[k] = fmin(data_opp->size[k], he + (alpha) * (data_opp->h/2. + data->h/2.));
              } 
              // Gradient is too large but no size is greater than its projection
              if(data->size[k] < he_opp){
                double dotMax = -1.0, dotProd;
                int closestDir;
                for(size_t ii = 0; ii < 3; ++ii){
                  SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                  dotProd = fabs(dot(e, e_opp_ii));
                  if(dotProd > dotMax){
                    dotMax = fmax(dotMax, dotProd);
                    closestDir = ii;
                  }
                }
                data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
              }
              if(data_opp->size[k] < he){
                double dotMax = -1.0, dotProd;
                int closestDir;
                for(size_t ii = 0; ii < 3; ++ii){
                  SVector3 e_ii(data->dir[3*ii+0], data->dir[3*ii+1], data->dir[3*ii+2]);
                  dotProd = fabs(dot(e_ii, e_opp));
                  if(dotProd > dotMax){
                    dotMax = fmax(dotMax, dotProd);
                    closestDir = ii;
                  }
                }
                data->size[closestDir] = fmin(data->size[closestDir], data_opp->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
              }
            } // if ds > alpha-1
          } // for j hanging
        } // if hanging
        else{

          data = (size_data_t *) side[i]->is.full.quad->p.user_data;
          SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);

          if(fabs(data->ds[3*k+which_dir]) > alpha){
            if(side[iOpp]->is_hanging){
              // Current full - Oppose hanging
              for(int j = 0; j < P4EST_HALF; ++j){
                data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
                SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);
                double he = 1.0/sqrt(dot(e_opp, data->M, e_opp)); // Size of opposite directions in current metric
                double he_opp = 1.0/sqrt(dot(e, data_opp->M, e)); // Size of current directions in opposite metric

                if(data->size[k] > he_opp){
                  data->size[k] = fmin(data->size[k], he_opp + (alpha) * (data_opp->h/2. + data->h/2.));
                } 
                if(data_opp->size[k] > he){
                  data_opp->size[k] = fmin(data_opp->size[k], he + (alpha) * (data_opp->h/2. + data->h/2.));
                } // Gradient is too large but no size is greater than its projection
                if(data->size[k] < he_opp){
                  double dotMax = -1.0, dotProd;
                  int closestDir;
                  for(size_t ii = 0; ii < 3; ++ii){
                    SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                    dotProd = fabs(dot(e, e_opp_ii));
                    if(dotProd > dotMax){
                      dotMax = fmax(dotMax, dotProd);
                      closestDir = ii;
                    }
                  }
                  data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                }
                if(data_opp->size[k] < he){
                  double dotMax = -1.0, dotProd;
                  int closestDir;
                  for(size_t ii = 0; ii < 3; ++ii){
                    SVector3 e_ii(data->dir[3*ii+0], data->dir[3*ii+1], data->dir[3*ii+2]);
                    dotProd = fabs(dot(e_ii, e_opp));
                    if(dotProd > dotMax){
                      dotMax = fmax(dotMax, dotProd);
                      closestDir = ii;
                    }
                  }
                  data->size[closestDir] = fmin(data->size[closestDir], data_opp->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                }
              }
            } else{
              // Current full - Oppose full
              data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
              SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);

              // Length along these directions based on each metric
              double he = 1.0/sqrt(dot(e_opp, data->M, e_opp)); // Size of opposite directions in current metric
              double he_opp = 1.0/sqrt(dot(e, data_opp->M, e)); // Size of current directions in opposite metric

              // Current size is greater than its projection on the opposing cell
              if(data->size[k] > he_opp){ 
                data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
              }
              // Opposing size is greater than its projection on the current cell 
              if(data_opp->size[k] > he){ 
                data_opp->size[k] = fmin(data_opp->size[k], he + alpha * (data_opp->h/2. + data->h/2.));
              } 
              // Gradient is too large but no size is greater than its projection
              // On regarde la direction la plus proche chez le voisin, et on limite la taille selon cette direction chez le voisin
              if(data->size[k] < he_opp){  // printf("ERREUR 3 : (norme e = %4.4e) size[%d] = %4.4e - he_opp = %4.4e - s_cor = %4.4e- size_opp[%d] = %4.4e - he = %4.4e\n", e.norm(), k, data->size[k], he_opp, he_opp + alpha * (data_opp->h/2. + data->h/2.), k, data_opp->size[k], he);
                double dotMax = -1.0, dotProd;
                int closestDir;
                for(size_t ii = 0; ii < 3; ++ii){
                  SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                  dotProd = fabs(dot(e, e_opp_ii));
                  if(dotProd > dotMax){
                    dotMax = fmax(dotMax, dotProd);
                    closestDir = ii;
                  }
                }
                data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
              }
               if(data_opp->size[k] < he){
                double dotMax = -1.0, dotProd;
                int closestDir;
                for(size_t ii = 0; ii < 3; ++ii){
                  SVector3 e_ii(data->dir[3*ii+0], data->dir[3*ii+1], data->dir[3*ii+2]);
                  dotProd = fabs(dot(e_ii, e_opp));
                  if(dotProd > dotMax){
                    dotMax = fmax(dotMax, dotProd);
                    closestDir = ii;
                  }
                }
                // SVector3 e11(data->dir[3*0+0], data->dir[3*0+1], data->dir[3*0+2]);
                // SVector3 e22(data->dir[3*1+0], data->dir[3*1+1], data->dir[3*1+2]);
                // SVector3 e33(data->dir[3*2+0], data->dir[3*2+1], data->dir[3*2+2]);
                // Msg::Info("e_opp = (%+2.2e,%+2.2e,%+2.2e) - e1 = (%+2.2e,%+2.2e,%+2.2e) - e2 = (%+2.2e,%+2.2e,%+2.2e) - e3 = (%+2.2e,%+2.2e,%+2.2e) - Best is %d with dot = %4.4e\n",
                //   e_opp[0], e_opp[1], e_opp[2], e11[0], e11[1], e11[2], e22[0], e22[1], e22[2], e33[0], e33[1], e33[2], closestDir, dotMax);
                data->size[closestDir] = fmin(data->size[closestDir], data_opp->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
              }

            }
          } // if gradient trop grand
        } // else
      }
    }
  }
}

HXTStatus forestLimitSize(Forest *forest){
  if(forest->forestOptions->aniso){
    p4est_iterate (forest->p4est, NULL, (void*) forest->forestOptions, NULL, limitSizeAniso, NULL, NULL);
  } else{
    p4est_iterate (forest->p4est, NULL, (void*) forest->forestOptions, NULL, limitSize, NULL, NULL);
  }
  return HXT_STATUS_OK;
}

static void assembleMetricTensorCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;

  SVector3 v1(data->dir[0],data->dir[1],data->dir[2]);
  SVector3 v2(data->dir[3],data->dir[4],data->dir[5]);
  SVector3  n(data->dir[6],data->dir[7],data->dir[8]);
  if(isnan(v1.norm()) || isnan(v2.norm()) || isnan(n.norm()))
    printf("Normes : %f \t %f \t %f\n", v1.norm(), v2.norm(), n.norm());
  SMetric3 m(1.0/(data->size[0]*data->size[0]),
             1.0/(data->size[1]*data->size[1]),
             1.0/(data->size[2]*data->size[2]), 
             v1, v2, n);
  data->M = m;
  // Msg::Info("Assembled metric with sizes (%2.2e,%2.2e,%2.2e) and directions (%2.2e,%2.2e,%2.2e) - (%2.2e,%2.2e,%2.2e) - (%2.2e,%2.2e,%2.2e)",
    // data->size[0],
    // data->size[1],
    // data->size[2],
    // data->dir[0],data->dir[1],data->dir[2],
    // data->dir[3],data->dir[4],data->dir[5],
    // data->dir[6],data->dir[7],data->dir[8]);
}

HXTStatus forestAssembleMetricTensors(Forest *forest){
  p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, assembleMetricTensorCallback, NULL, NULL, NULL);
  return HXT_STATUS_OK;
}

HXTStatus forestSizeSmoothing(Forest *forest){
  double gradMax[9], gradLinf;
  int iter = 0, nmax = 25;
  int aniso = forest->forestOptions->aniso;
  int dim = forest->forestOptions->dim;

  do{
    gradLinf = -1e22;
    if(aniso){ HXT_CHECK( forestAssembleMetricTensors(forest)); }
    HXT_CHECK( forestComputeGradient(forest) );    // Compute gradient
    HXT_CHECK( forestLimitSize(forest)       );    // Limit large sizes to limit gradient to foresOptions->gradMax
    for(int i = 0; i < (aniso ? dim*dim : dim); ++i) gradMax[i] = -1e22; // Stopping criterion
    HXT_CHECK( forestGetMaxGradient(forest, gradMax) );
    for(int i = 0; i < (aniso ? dim*dim : dim); ++i) gradLinf = fmax(gradLinf, fabs(gradMax[i]));

    if(!aniso){
      if(dim==2){
        Msg::Info("Max gradient during size limitation : grad h = (%10.5e - %10.5e)", fabs(gradMax[0]), fabs(gradMax[1]));
      }
      if(dim==3){
        Msg::Info("Max gradient during size limitation : grad h = (%10.5e - %10.5e - %10.5e)",
        fabs(gradMax[0]), fabs(gradMax[1]), fabs(gradMax[2]));
      }
    } else{
      if(dim==2){
        Msg::Info("Max gradient during size limitation : grad hc = (%10.5e - %10.5e) - grad hn = (%10.5e - %10.5e)",
        fabs(gradMax[0]), fabs(gradMax[1]), fabs(gradMax[2]), fabs(gradMax[3]));
      }
      if(dim==3){
        Msg::Info("Max gradient during size limitation : grad h1 = (%10.5e - %10.5e - %10.5e) - grad h2 = (%10.5e - %10.5e - %10.5e) - grad hn = (%10.5e - %10.5e - %10.5e)",
        fabs(gradMax[0]), fabs(gradMax[1]), fabs(gradMax[2]),
        fabs(gradMax[3]), fabs(gradMax[4]), fabs(gradMax[5]),
        fabs(gradMax[6]), fabs(gradMax[7]), fabs(gradMax[8]));
      }
    }
  } while(iter++ < nmax && gradLinf > forest->forestOptions->gradation - 1.0 + 1e-5);

  return HXT_STATUS_OK;
}

// So far, directions in the octree are assigned based on the closest volume mesh node's directions
// (Closest to the center of the octant)
static void assignDirectionsCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_t            *p4est = info->p4est;
  p4est_quadrant_t   *q = info->quad;
  p4est_topidx_t      which_tree = info->treeid;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  ForestOptions      *forestOptions = (ForestOptions *) user_data;
  HXTMesh            *mesh3D = forestOptions->mesh3D;

  // if(forestOptions->dim == 3){

    double h, center[3], min[3], max[3];
    getCellSize(p4est, which_tree, q, &h);
    getCellCenter(p4est, which_tree, q, center);
    getCellBBox(p4est, which_tree, q, min, max);
    std::vector<uint64_t> candidates;
    forestOptions->domRTree->Search(min, max, rtreeCallback, &candidates);

    if(!candidates.empty()){
      uint32_t closestNodeToCenter = -1;
      // uint32_t closestTetToCenter  = -1;
      double dist, minDist = DBL_MAX, x, y, z; // xb, yb, zb;
      bool isInsideATet = false;
      for(std::vector<uint64_t>::iterator tet = candidates.begin(); tet != candidates.end(); ++tet){

        // Gmsh Mtet
        uint32_t n0 = mesh3D->tetrahedra.node[4*(*tet)];
        uint32_t n1 = mesh3D->tetrahedra.node[4*(*tet)+1];
        uint32_t n2 = mesh3D->tetrahedra.node[4*(*tet)+2];
        uint32_t n3 = mesh3D->tetrahedra.node[4*(*tet)+3];

        MTetrahedron tetGMSH((*forestOptions->c2vDom)[n0],
                             (*forestOptions->c2vDom)[n1],
                             (*forestOptions->c2vDom)[n2],
                             (*forestOptions->c2vDom)[n3]);

        double uvw[3];
        tetGMSH.xyz2uvw(center, uvw);
        bool isInside = tetGMSH.isInside(uvw[0], uvw[1], uvw[2]);

        if(isInside){
          isInsideATet = true;
          double *dir = forestOptions->directions;
          const double directions[36] = {dir[9*n0],dir[9*n0+1],dir[9*n0+2],dir[9*n0+3],dir[9*n0+4],dir[9*n0+5],dir[9*n0+6],dir[9*n0+7],dir[9*n0+8],
                                         dir[9*n1],dir[9*n1+1],dir[9*n1+2],dir[9*n1+3],dir[9*n1+4],dir[9*n1+5],dir[9*n1+6],dir[9*n1+7],dir[9*n1+8],
                                         dir[9*n2],dir[9*n2+1],dir[9*n2+2],dir[9*n2+3],dir[9*n2+4],dir[9*n2+5],dir[9*n2+6],dir[9*n2+7],dir[9*n2+8],
                                         dir[9*n3],dir[9*n3+1],dir[9*n3+2],dir[9*n3+3],dir[9*n3+4],dir[9*n3+5],dir[9*n3+6],dir[9*n3+7],dir[9*n3+8]};
          double dirAtParamNode[9], quality = 0.0;
          int flagTrusted[3] = {0};
          hxtOr3DgetCrossInTetFromDir(directions, uvw, dirAtParamNode, &quality, flagTrusted);

          for(size_t i = 0; i < 9; ++i)
            data->dir[i] = dirAtParamNode[i];
          data->hasIntersection = true;
        }
        // xb = 0., yb = 0., zb = 0.;
        for(size_t i = 0; i < 4; ++i){
          uint32_t node = mesh3D->tetrahedra.node[4*(*tet)+i];
          x = mesh3D->vertices.coord[(size_t) 4*node+0];
          y = mesh3D->vertices.coord[(size_t) 4*node+1];
          z = mesh3D->vertices.coord[(size_t) 4*node+2];

          // Assign octant's directions based on closest tet node to the center
          dist = sqrt( (center[0]-x)*(center[0]-x) + (center[1]-y)*(center[1]-y) + (center[2]-z)*(center[2]-z));
          if(dist < minDist){
            minDist = dist;
            closestNodeToCenter = node;
          }

          // // Assign octant's directions based on closest tet barycenter
          // xb += x;
          // yb += y;
          // zb += z;
        }
        // xb /= 4.; yb /= 4.; zb /= 4.; // Barycenter
        // dist = sqrt( (center[0]-xb)*(center[0]-xb) + (center[1]-yb)*(center[1]-yb) + (center[2]-zb)*(center[2]-zb));
        // if(dist < minDist){
        //   minDist = dist;
        //   closestTetToCenter = *tet;
        // }
      } // for tet : candidates

      if(!isInsideATet){
        if(closestNodeToCenter >= 0){
          for(size_t i = 0; i < 9; ++i)
            data->dir[i] = forestOptions->directions[9*closestNodeToCenter+i];
        }
        // if(closestTetToCenter >= 0){
        //   for(size_t i = 0; i < 3; ++i){
        //     data->dir[i]   = forestOptions->directionsU[3*closestTetToCenter+i];
        //     data->dir[3+i] = forestOptions->directionsV[3*closestTetToCenter+i];
        //     data->dir[6+i] = forestOptions->directionsW[3*closestTetToCenter+i];
        //   }
        // }
        data->hasIntersection = true;
      }
    } else{
      // Assign directions of the closest node (not the best...)
      uint32_t closestNode = -1;
      double minDist = DBL_MAX, dist,x,y,z;
      for(uint32_t i = 0; i < forestOptions->mesh2D->vertices.num; ++i){
        x = forestOptions->mesh2D->vertices.coord[(size_t) 4*i+0];
        y = forestOptions->mesh2D->vertices.coord[(size_t) 4*i+1];
        z = forestOptions->mesh2D->vertices.coord[(size_t) 4*i+2];
        dist = sqrt( (center[0]-x)*(center[0]-x) + (center[1]-y)*(center[1]-y) + (center[2]-z)*(center[2]-z));
        if(dist < minDist){
          minDist = dist;
          closestNode = i;
        }
      }
      if(closestNode >= 0){
        for(size_t i = 0; i < 9; ++i)
          data->dir[i] = forestOptions->directions[9*closestNode+i];
      }
      
      // data->dir[0] = 1.;
      // data->dir[1] = 0.;
      // data->dir[2] = 0.;
      // data->dir[3] = 0.;
      // data->dir[4] = 1.;
      // data->dir[5] = 0.;
      // data->dir[6] = 0.;
      // data->dir[7] = 0.;
      // data->dir[8] = 1.;
      data->hasIntersection = false;
    }
  // }
}

HXTStatus forestSmoothDirections(Forest *forest){
  
  ForestOptions *forestOptions = forest->forestOptions;
  HXTMesh *meshDom = forest->forestOptions->mesh3D;
  HXTMesh *meshBnd = forest->forestOptions->mesh2D;
  double *frames; // C'est un tableau qui contient les 9 composantes representant les frames en chaque noeuds du maillage.
  //--structure: frames[9*iNode + k], k compris entre 0 et 8 inclus
  HXT_CHECK(hxtMalloc(&frames, meshDom->vertices.num*sizeof(double)*9));
  for (uint64_t i = 0; i < meshDom->vertices.num*9; ++i)
    frames[i] = 0.; 

  double *directions = forestOptions->directions;

  int *isBoundaryCondition;

  FILE* myfile = fopen("justTheDirections.pos","w");
  fprintf(myfile,"View \"justTheDirections\"{\n");

  if(forestOptions->dim == 3){

    HXT_CHECK(hxtMalloc(&isBoundaryCondition, meshDom->vertices.num*sizeof(int)));
    for (uint64_t i = 0; i < meshDom->vertices.num; ++i)
      isBoundaryCondition[i]=0;

    for(size_t i = 0; i < meshDom->triangles.num; ++i){
      for(size_t jj = 0; jj < 3; ++jj){
        uint32_t iNbc = meshDom->triangles.node[(size_t) 3*i+jj];
        double *v1 = forestOptions->nodalCurvature + 6*iNbc;
        double *v2 = forestOptions->nodalCurvature + 6*iNbc + 3;
        double *n  = forestOptions->nodeNormals    + 3*iNbc;

        double *x = meshDom->vertices.coord + 4*iNbc;

        double tol = 1e-6;
        SVector3 V1(v1[0],v1[1],v1[2]); if(V1.norm() >= tol){ V1.normalize(); }; 
        SVector3 V2(v2[0],v2[1],v2[2]); if(V2.norm() >= tol){ V2.normalize(); };
        SVector3  N( n[0], n[1], n[2]); if( N.norm() >= tol){  N.normalize(); };

        double dirBC[9];
        dirBC[0] = V1[0]; dirBC[1] = V1[1]; dirBC[2] = V1[2];
        dirBC[3] = V2[0]; dirBC[4] = V2[1]; dirBC[5] = V2[2];
        dirBC[6] =  N[0]; dirBC[7] =  N[1]; dirBC[8] =  N[2];

        for (int j = 0; j < 3; ++j) {
          double d[3] = {dirBC[3*j+0], dirBC[3*j+1], dirBC[3*j+2]};
          if(j==0){
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], 1.0/2.0*d[0], 1.0/2.0*d[1], 1.0/2.0*d[2]);
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-1.0/2.0*d[0],-1.0/2.0*d[1],-1.0/2.0*d[2]);
          } else{
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], d[0], d[1], d[2]);
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-d[0],-d[1],-d[2]);
          }
        }

        // Converting BC directions to BC frames
        if(V1.norm() >= tol && V2.norm() >= tol && N.norm() >= tol){
          isBoundaryCondition[iNbc] = 1;

          // Assigning those directions directly in the directions array for boundary nodes
          for(size_t j = 0; j < 9; ++j){
            directions[9*iNbc+j] = dirBC[j];
          }

          double frameBC[9]={0.0};
          hxtOr3DdirectionsToFrame(dirBC, frameBC);
          double frameProj[9]={0.0};
          hxtOr3DprojectFrameOnCrossManifold(frameBC, frameProj);
          for(int k = 0; k < 9 ; ++k)
            frames[9*iNbc + k]=frameProj[k];
          // for(size_t k = 0; k < 9; ++k)
          //   frames[9*iNbc + k]= frameBC[k]; // pour k de 0 à 8
        }
      }
    } // for boundary nodes
  } else{ // dim = 2
    HXT_CHECK(hxtMalloc(&isBoundaryCondition, meshDom->vertices.num*sizeof(int)));
    for (uint64_t i = 0; i < meshDom->vertices.num; ++i)
      isBoundaryCondition[i]=0;

    for(size_t iLine = 0; iLine < meshDom->lines.num; ++iLine){
      for(size_t i = 0; i < 2; ++i){
        uint32_t iNbc = meshDom->lines.node[(size_t) 2*iLine + i];
        MVertex *v = (*forestOptions->c2vBnd)[iNbc]; // The current vertex
        uint32_t c = (*forestOptions->v2cBnd)[v];    // Its label in the HXTMesh

        if(c != iNbc) Msg::Error("%d - %d\n", c, iNbc);

        double  r = forestOptions->nodalCurvature[c];
        double *n = forestOptions->nodeNormals + 3*c;
        double *x = meshDom->vertices.coord + 4*iNbc;

        double tol = 1e-6;
        SVector3 N(n[0], n[1], n[2]); 
        if( N.norm() >= tol){  N.normalize(); };
        SVector3 R = crossprod(N, SVector3(0.,0.,1.));
        if( R.norm() >= tol){  R.normalize(); };

        double dirBC[9];
        dirBC[0] = R[0]; dirBC[1] = R[1]; dirBC[2] = R[2];
        dirBC[3] = N[0]; dirBC[4] = N[1]; dirBC[5] = N[2];
        dirBC[6] =   0.; dirBC[7] =   0.; dirBC[8] =   1.;

        for(int j = 0; j < 3; ++j){
          double d[3] = {dirBC[3*j+0], dirBC[3*j+1], dirBC[3*j+2]};
          if(j==0){
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], 1.0/2.0*d[0], 1.0/2.0*d[1], 1.0/2.0*d[2]);
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-1.0/2.0*d[0],-1.0/2.0*d[1],-1.0/2.0*d[2]);
          } else{
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], d[0], d[1], d[2]);
            fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-d[0],-d[1],-d[2]);
          }
        }

        Msg::Info("N = (%+2.2e,%+2.2e,%+2.2e) - R = (%+2.2e,%+2.2e,%+2.2e)\n", N[0], N[1], N[2], R[0], R[1], R[2]);

        // Converting BC directions to BC frames
        if(N.norm() >= tol && R.norm() >= tol){
          isBoundaryCondition[iNbc] = 1;
          // Assigning those directions directly in the directions array for boundary nodes
          for(size_t j = 0; j < 9; ++j){
            directions[9*iNbc+j] = dirBC[j];
          }
          double frameBC[9]={0.0};
          hxtOr3DdirectionsToFrame(dirBC, frameBC);
          double frameProj[9]={0.0};
          hxtOr3DprojectFrameOnCrossManifold(frameBC, frameProj);
          for(int k = 0; k < 9 ; ++k)
            frames[9*iNbc + k]=frameProj[k];
          // for(size_t k = 0; k < 9; ++k)
          //   frames[9*iNbc + k]= frameBC[k]; // pour k de 0 à 8
        }
      }
    } // for boundary nodes
  }

  fprintf(myfile,"};");
  fclose(myfile);

  HXT_CHECK(hxtOr3DWritePosCrossesFromFrames(meshDom, frames, "myFramesBeforeSolve.pos", NULL));
  
  HXT_CHECK(hxtInitializeLinearSystems(NULL, NULL));
  int solver=5;
  int maxIter=3000;
  double precision=1e-6;
  double epsilon=-1.0;
  int L=1;
  int P=0;
  HXT_CHECK(hxtOr3DComputeFrames(meshDom, frames, precision, maxIter, solver, epsilon, L, P, isBoundaryCondition));
  HXT_CHECK(hxtOr3DWritePosCrossesFromFrames(meshDom, frames, "myFrames.pos", NULL));

  // HxtUVWParamOptions uvwOptions;
  // uvwOptions.ignore_scaling = 0;
  // uvwOptions.debug = 1;
  // uvwOptions.verbose = 1;
  // double *liftU; //Une direction par tet, liftU[3*tetNum + i], i = 0..2
  // HXT_CHECK(hxtMalloc(&liftU, meshDom->tetrahedra.num*3*sizeof(double)));
  // double *liftV; //Une direction par tet, liftV[3*tetNum + i], i = 0..2
  // HXT_CHECK(hxtMalloc(&liftV, meshDom->tetrahedra.num*3*sizeof(double)));
  // double *liftW; //Une direction par tet, liftW[3*tetNum + i], i = 0..2
  // HXT_CHECK(hxtMalloc(&liftW, meshDom->tetrahedra.num*3*sizeof(double)));
  // double *directionsVertices;
  // HXT_CHECK(hxtMalloc(&directionsVertices, sizeof(double)*9*meshDom->tetrahedra.num));
  // for (uint64_t i = 0; i < meshDom->vertices.num; ++i){ //Transforme les représentations des frames en 3 directions orthogonales qui sont stockées dans directionsVertices
  //   double stableDir[3]={0.0};
  //   hxtOr3DframeToDirections(frames + 9*i, stableDir, directionsVertices + 9*i);
  //  }
  // double *directionsElem;
  // HXT_CHECK(hxtMalloc(&directionsElem, sizeof(double)*9*meshDom->tetrahedra.num));
  // double *smoothnessIndicator;
  // HXT_CHECK(hxtMalloc(&smoothnessIndicator, meshDom->tetrahedra.num*sizeof(double)));
    
  // HXT_CHECK(hxtOr3DcrossNodesToElem(meshDom, directionsVertices, directionsElem, smoothnessIndicator)); //On a besoin de transformer les croix par noeuds en croix par tet pour faire le lifting plus facilement
  // HXT_CHECK(get_lifting(meshDom, directionsElem, smoothnessIndicator, &uvwOptions, liftU, liftV, liftW));
  // hxtOr3DWritePosVectorTet(meshDom, liftU, "liftU.pos"); //Crée un fichier pos pour visualiser le lifting
  // hxtOr3DWritePosVectorTet(meshDom, liftV, "liftV.pos");
  // hxtOr3DWritePosVectorTet(meshDom, liftW, "liftW.pos");

  // //--une fois les frames calculées, il faut postraiter pour récupérer les directions
  // // boucle sur tous les noeuds du maillage iN
  // for(size_t i = 0; i < meshDom->vertices.num; ++i){
  //   if(!isBoundaryCondition[i]){
  //     double stableDir[3]={0.0}; //données sur la qualité de la frame, pas d'utilité pour toi
  //     double dirN[9]={0.0};      //directions de la croix, stockées comme ça: {u0,u1,u2,v0,v1,v2,w0,w1,w2}
  //     hxtOr3DframeToDirections(frames + 9*i, stableDir, dirN);
  //     for(size_t j = 0; j < 9; ++j){
  //       directions[9*i+j] = dirN[j];
  //     }
  //   }
  // }

  // FILE* myfile2 = fopen("directionsPreservees.pos","w");
  // fprintf(myfile2,"View \"directionsPreservees\"{\n");
  // for(size_t i = 0; i < meshDom->triangles.num; ++i){
  //   for(size_t jj = 0; jj < 3; ++jj){
  //     uint32_t iNbc = meshDom->triangles.node[(size_t) 3*i+jj];
  //     double *x = meshDom->vertices.coord + 4*iNbc;
  //     double localDir[9] = {directions[9*iNbc+0],directions[9*iNbc+1],directions[9*iNbc+2],
  //                           directions[9*iNbc+3],directions[9*iNbc+4],directions[9*iNbc+5],
  //                           directions[9*iNbc+6],directions[9*iNbc+7],directions[9*iNbc+8],};
  //     for (int j = 0; j < 3; ++j) {
  //       double d[3] = {localDir[3*j+0], localDir[3*j+1], localDir[3*j+2]};
  //       if(j==0){
  //         fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], 1.0/2.0*d[0], 1.0/2.0*d[1], 1.0/2.0*d[2]);
  //         fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-1.0/2.0*d[0],-1.0/2.0*d[1],-1.0/2.0*d[2]);
  //       } else{
  //         fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], d[0], d[1], d[2]);
  //         fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-d[0],-d[1],-d[2]);
  //       }
  //     }
  //   }
  // }

  // fprintf(myfile2,"};");
  // fclose(myfile2);

  // HXT_CHECK(hxtOr3DWritePosCrossesFromFrames(forest->forestOptions->mesh2D, frames, "thisShouldBeBetter.pos", NULL));

  // for(uint64_t i = 0; i < 3*meshDom->tetrahedra.num; ++i){
  //   forestOptions->directionsU[i] = liftU[i];
  //   forestOptions->directionsV[i] = liftV[i];
  //   forestOptions->directionsW[i] = liftW[i];
  // }

  // p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, assignDirectionsCallback, NULL, NULL, NULL);

  // HXT_CHECK(hxtFree(&directionsElem));
  // HXT_CHECK(hxtFree(&smoothnessIndicator));
  // HXT_CHECK(hxtFree(&liftU));
  // HXT_CHECK(hxtFree(&liftV));
  // HXT_CHECK(hxtFree(&liftW));
  HXT_CHECK(hxtFree(&frames));
  HXT_CHECK(hxtFree(&isBoundaryCondition));

  Msg::Error("Ending");
  Msg::Exit(1);


  return HXT_STATUS_OK;
}

/* ========================================================================================================
   SEARCH AND REPLACE
   ======================================================================================================== */

inline static bool isPoint(double x, double y, double z, size_point_t *p, double tol){
  return (fabs(p->x - x) < tol && fabs(p->y - y) < tol && fabs(p->z - z) < tol);
}

static int searchAndAssignConstant(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
  bool in_box, is_leaf = local_num >= 0;
  size_data_t   *data = (size_data_t *) q->p.user_data;
  size_point_t  *p    = (size_point_t *) point;
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants
  // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
  double h, center[3];
  if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
  else h = data->h;
  getCellCenter(p4est, which_tree, q, center);

  // double epsilon = 1e-13;
  // in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. - epsilon);
  // in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y > center[1] - h/2. - epsilon);
  // in_box &= (p->z < center[2] + h/2. + epsilon) && (p->z > center[2] - h/2. - epsilon);
  in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
  in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
  in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

  // A point can be on the exact boundary of two cells, hence we take the min.
  if(in_box && is_leaf){
    p->size = fmin(p->size, data->size[0]);
    p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
    p->isFound = true;
  }

  return in_box;
}

static int searchAndAssignConstantAniso(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
  bool in_box, is_leaf = local_num >= 0;
  size_data_t   *data = (size_data_t *) q->p.user_data;
  size_point_t  *p    = (size_point_t *) point;
  // ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants
  // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
  double h, center[3];
  if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
  else h = data->h;
  getCellCenter(p4est, which_tree, q, center);

  // double epsilon = 1e-13;
  // in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. - epsilon);
  // in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y > center[1] - h/2. - epsilon);
  // in_box &= (p->z < center[2] + h/2. + epsilon) && (p->z > center[2] - h/2. - epsilon);
  in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
  in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
  in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

  // A point can be on the exact boundary of two cells, hence we take the min.
  if(in_box && is_leaf){
    // p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
    p->m = data->M;
    // p->m = SMetric3(1.0);
    // p->m.print("p->m");
    p->isFound = true;
  }

  return in_box;
}

static int searchAndAssignLinear(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
  bool in_box = false, is_leaf = local_num >= 0;
  size_data_t   *data = (size_data_t *) q->p.user_data;
  size_point_t  *p    = (size_point_t *) point;
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants
  // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
  double h, center[3];
  // if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
  // else h = data->h;
  getCellSize(p4est, which_tree, q, &h);
  getCellCenter(p4est, which_tree, q, center);

  double epsilon = 1e-10;
  // in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. - epsilon);
  // in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y > center[1] - h/2. - epsilon);
  // in_box &= (p->z < center[2] + h/2. + epsilon) && (p->z > center[2] - h/2. - epsilon);

  // This misses some points...
  // in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
  // in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
  // in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

  SPoint3 C(center), P(p->x,p->y,p->z);
  SVector3 dir(C,P);
  SVector3 dx(1.,0.,0.);
  SVector3 dy(0.,1.,0.);
  SVector3 dz(0.,0.,1.);

  in_box = fabs(dot(dir,dx)) <= (h/2. + epsilon) && fabs(dot(dir,dy)) <= (h/2. + epsilon) && fabs(dot(dir,dz)) <= (h/2. + epsilon);

  // A point can be on the exact boundary of two cells, hence we take the min.
  if(in_box && is_leaf){
    p->size = fmin(p->size, data->size[0] + data->ds[0]*(p->x - center[0]) + data->ds[1]*(p->y - center[1]) + data->ds[2]*(p->z - center[2]) );
    p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
    p->isFound = true;
  }

  p->parcourus++;

  // if(is_leaf && !p->isFound && fabs(p->x) < 1e-4){
  // if(in_box && !p->isFound && fabs(p->x) < 1e-4){
  //   printf("Point (%4.16e,%4.16e,%4.16e)\n", p->x, p->y, p->z);
  //   printf("h = %4.16e, center = (%4.16e, %4.16e, %4.16e)\n", h, center[0], center[1], center[2]);
  //   printf("%4.16e <= x <= %4.16e (%d)\n", center[0]-h/2., center[0]+h/2., (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.) );
  //   printf("%4.16e <= y <= %4.16e (%d)\n", center[1]-h/2., center[1]+h/2., (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.) );
  //   printf("%4.16e <= z <= %4.16e (%d)\n", center[2]-h/2., center[2]+h/2., (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.) );
  // }

  return in_box;
}

// static int replace(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
//     bool in_box, is_leaf = local_num >= 0;
//     size_data_t  *data = (size_data_t *) q->p.user_data;
//     size_point_t *p    = (size_point_t *) point;
//     double h, center[3];
//     if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
//     else h = data->h;
//     getCellCenter(p4est, which_tree, q, center);

//     in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
//     in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
//     in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

//     if(in_box && is_leaf){
//         data->size = fmin(data->size, p->size);
//     }

//     return in_box;
// }

/* Search for a single point in the tree structure and returns its size.
   See searchAndAssign for the detailed comments. */
HXTStatus forestSearchOne(Forest *forest, double x, double y, double z, double *size, int linear){
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), 1);

  size_point_t *p = (size_point_t *) sc_array_index(points, 0);
  p->x = x;
  p->y = y;
  p->z = z;
  p->size = 1.0e22;
  p->isFound = false;
  p->parcourus = 0;

  if(linear){
    p4est_search(forest->p4est, NULL, searchAndAssignLinear, points);
  } else{
    p4est_search(forest->p4est, NULL, searchAndAssignConstant, points);
  }

  if(!p->isFound){
    Msg::Info("(%+.4f,%+.4f,%+.4f) was not found in the meshsize field 8-|", x,y,z);
    Msg::Info("Octants parcourus : %d\n", p->parcourus);
  }
  *size = p->size;

  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

HXTStatus forestSearchOneAniso(Forest *forest, double x, double y, double z, SMetric3 &m, int linear){
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), 1);

  size_point_t *p = (size_point_t *) sc_array_index(points, 0);
  p->x = x;
  p->y = y;
  p->z = z;
  p->m = SMetric3(1.0);
  p->isFound = false;

  p4est_search(forest->p4est, NULL, searchAndAssignConstantAniso, points);

  if(!p->isFound) Msg::Info("Point (%f,%f,%f) n'a pas été trouvé dans l'octree 8-|", x,y,z);
  else m = p->m;

  // m.print("apres search");

  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

// Not finished
HXTStatus hxtForestSearch(Forest *forest, std::vector<double> *x, std::vector<double> *y, std::vector<double> *z, std::vector<double> *size){
  // Array of size_point_t to search in the tree
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), (*x).size());
  size_point_t *p;

  for(size_t i = 0; i < (*x).size(); ++i){
    p = (size_point_t *) sc_array_index(points, i);
    p->x = (*x)[i];
    p->y = (*y)[i];
    p->z = (*z)[i];
    p->size = -1.0;
  }

  // Search on all cells
  p4est_search(forest->p4est, NULL, searchAndAssignLinear, points);

  // Get the sizes
  for(size_t i = 0; i < (*x).size(); ++i){
    p = (size_point_t *) sc_array_index(points, i);
    (*size)[i] = p->size;
  }

  // Clean up
  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   CLOSE SURFACES DETECTION
   ======================================================================================================== */

// To quickly sort 3 integers
static void sort3(int *d){
#define SWAP(x,y) if (d[y] < d[x]) { int tmp = d[x]; d[x] = d[y]; d[y] = tmp; }
  SWAP(0, 1);
  SWAP(1, 2);
  SWAP(0, 1);
#undef SWAP
}

// To quickly sort 4 integers
static void sort4(int *d){
#define SWAP(x,y) if (d[y] < d[x]) { int tmp = d[x]; d[x] = d[y]; d[y] = tmp; }
  SWAP(0, 1);
  SWAP(2, 3);
  SWAP(0, 2);
  SWAP(1, 3);
  SWAP(1, 2);
#undef SWAP
}

// Checks whether two MTetrahedra have a common face without creating MFaces (slow)
// Returns the index of the common face in t1 if any, -1 otherwise
static int commonFaceTetFast(MTetrahedron *t1, MTetrahedron *t2){
  int t10 = t1->getVertex(0)->getNum();
  int t11 = t1->getVertex(1)->getNum();
  int t12 = t1->getVertex(2)->getNum();
  int t13 = t1->getVertex(3)->getNum();
  int t20 = t2->getVertex(0)->getNum();
  int t21 = t2->getVertex(1)->getNum();
  int t22 = t2->getVertex(2)->getNum();
  int t23 = t2->getVertex(3)->getNum();

  bool b0 = (t10 == t20) || (t10 == t21) || (t10 == t22) || (t10 == t23);
  bool b1 = (t11 == t20) || (t11 == t21) || (t11 == t22) || (t11 == t23);
  bool b2 = (t12 == t20) || (t12 == t21) || (t12 == t22) || (t12 == t23);
  bool b3 = (t13 == t20) || (t13 == t21) || (t13 == t22) || (t13 == t23);

  if(b0+b1+b2+b3 < 3){
    return -1;
  } else{
    int v1[4]    = {t10, t11, t12, t13};
    int v1cpy[4] = {t10, t11, t12, t13};
    int v2[4]    = {t20, t21, t22, t23};
    sort4(v1);
    sort4(v2);
    t10 = v1[0]; t11 = v1[1]; t12 = v1[2]; t13 = v1[3];
    t20 = v2[0]; t21 = v2[1]; t22 = v2[2]; t23 = v2[3];

    bool b00 = (t11==t21) && (t12==t22) && (t13==t23);
    bool b01 = (t11==t20) && (t12==t22) && (t13==t23);
    bool b02 = (t11==t20) && (t12==t21) && (t13==t23);
    bool b03 = (t11==t20) && (t12==t21) && (t13==t22);

    bool b10 = (t10==t21) && (t12==t22) && (t13==t23);
    bool b11 = (t10==t20) && (t12==t22) && (t13==t23);
    bool b12 = (t10==t20) && (t12==t21) && (t13==t23);
    bool b13 = (t10==t20) && (t12==t21) && (t13==t22);

    bool b20 = (t10==t21) && (t11==t22) && (t12==t23);
    bool b21 = (t10==t20) && (t11==t22) && (t12==t23);
    bool b22 = (t10==t20) && (t11==t21) && (t12==t23);
    bool b23 = (t10==t20) && (t11==t21) && (t12==t22);

    bool b30 = (t10==t21) && (t11==t22) && (t13==t23);
    bool b31 = (t10==t20) && (t11==t22) && (t13==t23);
    bool b32 = (t10==t20) && (t11==t21) && (t13==t23);
    bool b33 = (t10==t20) && (t11==t21) && (t13==t22);

    int missing = -1; // The vertex that is missing from the common face
    if      (b00 || b01 || b02 || b03) missing = 0; //return 3;
    else if (b10 || b11 || b12 || b13) missing = 1; //return 2;
    else if (b20 || b21 || b22 || b23) missing = 3; //return 0;
    else if (b30 || b31 || b32 || b33) missing = 2; //return 1;

    if(missing >= 0){
      if      (v1cpy[0] == v1[missing]) return 3;
      else if (v1cpy[1] == v1[missing]) return 2;
      else if (v1cpy[2] == v1[missing]) return 1;
      else if (v1cpy[3] == v1[missing]) return 0;
    }

    return -1;
  }
}

static int commonEdgeTriFast(MTriangle *t1, MTriangle *t2){
  int t10 = t1->getVertex(0)->getNum();
  int t11 = t1->getVertex(1)->getNum();
  int t12 = t1->getVertex(2)->getNum();
  int t20 = t2->getVertex(0)->getNum();
  int t21 = t2->getVertex(1)->getNum();
  int t22 = t2->getVertex(2)->getNum();

  bool b0 = (t10 == t20) || (t10 == t21) || (t10 == t22);
  bool b1 = (t11 == t20) || (t11 == t21) || (t11 == t22);
  bool b2 = (t12 == t20) || (t12 == t21) || (t12 == t22);

  if(b0+b1+b2 < 2){
    return -1;
  } else{
    int v1[3]    = {t10, t11, t12};
    int v1cpy[3] = {t10, t11, t12};
    int v2[3]    = {t20, t21, t22};
    sort3(v1);
    sort3(v2);
    t10 = v1[0]; t11 = v1[1]; t12 = v1[2];
    t20 = v2[0]; t21 = v2[1]; t22 = v2[2];

    bool b00 = (t11==t21) && (t12==t22);
    bool b01 = (t11==t20) && (t12==t22);
    bool b02 = (t11==t20) && (t12==t21);

    bool b10 = (t10==t20) && (t12==t22);
    bool b11 = (t10==t21) && (t12==t22);
    bool b12 = (t10==t20) && (t12==t21);

    bool b20 = (t10==t20) && (t11==t21);
    bool b21 = (t10==t20) && (t11==t22);
    bool b22 = (t10==t21) && (t11==t22);

    int missing = -1; // The vertex that is missing from the common edge
    if      (b00 || b01 || b02) missing = 0; //return 1;
    else if (b10 || b11 || b12) missing = 1; //return 2;
    else if (b20 || b21 || b22) missing = 2; //return 0;

    if(missing >= 0){
      if      (v1cpy[0] == v1[missing]) return 1;
      else if (v1cpy[1] == v1[missing]) return 2;
      else if (v1cpy[2] == v1[missing]) return 0;
    }

    return -1;
  }
}

// Only used to draw facets of the medial axis
static bool sortClockwise(SPoint3 a, SPoint3 b, SPoint3 center, SVector3 normal){
  // If dot(n, cross(A-C, B-C)) is positive, B is counterclockwise from A; if it's negative, B is clockwise from A.
  SVector3 tmp = crossprod(SVector3(center,a),SVector3(center,b));
  return dot(normal, tmp) <= 0;
}

// Computes the medial axis of the geometry and assigns the feature size at vertices
HXTStatus featureSize(Forest* forest){

  HXTMesh *mesh2D   = forest->forestOptions->mesh2D;
  int nLayersPerGap = forest->forestOptions->nodePerGap;
  double hmin       = forest->forestOptions->hmin;
  double hmax       = forest->forestOptions->hmax;

  std::vector<MVertex*> allVertices;
  std::vector<double> sizeAtVertices(mesh2D->vertices.num, DBL_MAX);
  for(size_t i = 0; i < mesh2D->vertices.num; ++i){
    allVertices.push_back(new MVertex(mesh2D->vertices.coord[4*i+0],
                                      mesh2D->vertices.coord[4*i+1],
                                      mesh2D->vertices.coord[4*i+2]));
  }

  int firstVertex = allVertices[0]->getNum();

  // All tets
  uint64_t count = 0;
  std::vector<MTetrahedron*> allTets;
  std::vector<std::vector<uint64_t>> tetIncidents;
  std::vector<std::vector<MEdge>> edgIncidents;
  for(uint32_t i = 0; i < mesh2D->vertices.num; ++i){
    std::vector<uint64_t> vTet;
    tetIncidents.push_back(vTet);
    std::vector<MEdge> vEdg;
    edgIncidents.push_back(vEdg);
  }

  // The empty mesh is stored in mesh2D, so it does have tets
  for(size_t i = 0; i < mesh2D->tetrahedra.num; ++i){
    if(mesh2D->tetrahedra.node[4*i+3] != HXT_GHOST_VERTEX){
      allTets.push_back(new MTetrahedron(allVertices[ mesh2D->tetrahedra.node[4*i+0] ],
                                         allVertices[ mesh2D->tetrahedra.node[4*i+1] ],
                                         allVertices[ mesh2D->tetrahedra.node[4*i+2] ],
                                         allVertices[ mesh2D->tetrahedra.node[4*i+3] ]) );

      for(size_t j = 0; j < 4; ++j){
        tetIncidents[ mesh2D->tetrahedra.node[4*i+j] ].push_back(count);
      }
      for(size_t j = 0; j < 6; ++j){
        MEdge e = allTets[count]->getEdge(j);
        edgIncidents[ allTets[count]->getEdge(j).getVertex(0)->getNum() - firstVertex ].push_back(e);
        edgIncidents[ allTets[count]->getEdge(j).getVertex(1)->getNum() - firstVertex ].push_back(e);
      }
      ++count;
    }
  }

  std::set<MEdge,MEdgeLessThan> axis;
  int elemDrawn = 0;

  FILE* file = fopen("medialAxis_toDraw.pos", "w");
  if(file==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  FILE* file2 = fopen("keptEdges.pos", "w");
  if(file2==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  bool draw = true;
  if(draw){
    fprintf(file, "View \"medialAxis\" {\n");
    fprintf(file2, "View \"keptEdges\" {\n");
  }

  int indFace;

  for(size_t i = 0; i < mesh2D->vertices.num; ++i){
    // Pôle de p : circumcenter le plus loin parmi les tets incidents à p
    SPoint3 pole(0.,0.,0.),
             tmp(0.,0.,0.),
               p(mesh2D->vertices.coord[4*i+0], mesh2D->vertices.coord[4*i+1], mesh2D->vertices.coord[4*i+2]);
    double d = 0.;

    for(size_t j = 0; j < tetIncidents[i].size(); ++j){
      tmp = allTets[ tetIncidents[i][j] ]->circumcenter();
      if(p.distance(tmp) > d) pole = tmp;
      d = fmax(d, p.distance(tmp));
    }

    // Pole vector
    SPoint3 vp = pole - p;
    double D = -(vp[0]*p[0] + vp[1]*p[1] + vp[2]*p[2]);
    SPoint3 p1(0., 0., -D/vp[2]); // 2 points sur le plan qui passe par p et de normale vp
    SPoint3 p2(0., -D/vp[1], 0.);

    std::vector<MFace> up; // umbrella
    // Boucle sur les voronoi edges (paires de centres)
    double orientj, orientk;
    for(size_t j = 0; j < tetIncidents[i].size(); ++j){
      uint64_t tetj = tetIncidents[i][j];
      SPoint3 cj = allTets[tetj]->circumcenter();
      for(size_t k = j; k < tetIncidents[i].size(); ++k){
        uint64_t tetk = tetIncidents[i][k];
        if( tetj != tetk ){
          indFace = commonFaceTetFast(allTets[tetj], allTets[tetk]);
          if(indFace >= 0){
            SPoint3 ck = allTets[tetk]->circumcenter();
            orientj = robustPredicates::orient3d((double*) p, (double*) p1, (double*) p2, (double*) cj);
            orientk = robustPredicates::orient3d((double*) p, (double*) p1, (double*) p2, (double*) ck);
            if(orientj*orientk < 0){
              up.push_back(allTets[tetj]->getFace(indFace));
              // break; ?
            }
          }
        }
      }
    }

    double theta = M_PI/8., rho = 8., maxAngle, minRatio, localAngle, alpha0, alpha1;
    std::vector<MEdge> checkedEdges;
    bool checked;
    for(size_t j = 0; j < edgIncidents[i].size(); ++j){ // boucler sur les aretes incidentes à p

      MEdge e = edgIncidents[i][j];
      checked = false;
      for(size_t k = 0; k < checkedEdges.size(); ++k){
        if(e == checkedEdges[k]){
          checked = true;
          break;
        }
      }

      if(checked){ continue; }
      else{ checkedEdges.push_back(e); }

      maxAngle = 0.0;
      minRatio = DBL_MAX;

      uint32_t v0 = e.getVertex(0)->getNum() - firstVertex;
      uint32_t v1 = e.getVertex(1)->getNum() - firstVertex;
      if(v0 == i || v1 == i){
        for(size_t l = 0; l < up.size(); ++l){
          // Angle condition
          localAngle = angle( e.tangent(), up[l].normal() );
          localAngle = fmin(localAngle, fabs(M_PI - localAngle));
          maxAngle = fmax(maxAngle, localAngle);

          // Ratio condition
          MTriangle tri(up[l].getVertex(0),up[l].getVertex(1),up[l].getVertex(2));
          minRatio = fmin(minRatio, e.length() / tri.getOuterRadius());
        }

        if(maxAngle < M_PI/2. - theta || minRatio > rho){
          double *n0 = forest->forestOptions->nodeNormals + 3*v0;
          double *n1 = forest->forestOptions->nodeNormals + 3*v1;
          alpha0 = angle(SVector3(n0), e.tangent());
          alpha1 = angle(SVector3(n1), e.tangent());

          if( fmin(alpha0, fabs(M_PI-alpha0)) < M_PI/8. && fmin(alpha1, fabs(M_PI-alpha1)) < M_PI/8.){
            // Add edge to the set (axis, though actually unused), modifiy size at its extrmities and draw the dual facet
            std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> ret = axis.insert(e);

            if(ret.second){
              double h = e.length()/nLayersPerGap;
              h = fmax(h, hmin);
              h = fmin(h, hmax);
              sizeAtVertices[ v0 ] = fmin(h, sizeAtVertices[ v0 ]);
              sizeAtVertices[ v1 ] = fmin(h, sizeAtVertices[ v1 ]);

              fprintf(file2, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n",
                      e.getVertex(0)->x(), e.getVertex(0)->y(), e.getVertex(0)->z(),
                      e.getVertex(1)->x(), e.getVertex(1)->y(), e.getVertex(1)->z(),
                      e.length(), e.length());

              if(draw){
                // Turning around the edge to draw the facet
                std::vector<SPoint3> centers;
                for(size_t jj = 0; jj < tetIncidents[i].size(); ++jj){
                  uint64_t tetj = tetIncidents[i][jj];
                  for(size_t b = 0; b < 6; ++b){
                    if(allTets[tetj]->getEdge(b) == e) centers.push_back(allTets[tetj]->circumcenter());
                  }
                }
                if(centers.size() > 2){
                  // Center of the face
                  SPoint3 c(0.,0.,0.);
                  for(size_t a = 0; a < centers.size(); ++a){
                    c += centers[a];
                  }
                  c /= centers.size();
                  SVector3 normal = crossprod(SVector3(c,centers[0]),SVector3(c,centers[1]));
                  normal.normalize();
                  // Sort clockwise around center
                  sort(centers.begin(), centers.end(), [c,normal](SPoint3 a, SPoint3 b) { return sortClockwise(a,b,c,normal); });
                  // Draw
                  for(size_t a = 1; a < centers.size()-1; ++a){
                    fprintf(file, "ST(%f,%f,%f, %f,%f,%f, %f,%f,%f){%d,%d,%d};\n",
                      centers[0][0],centers[0][1],centers[0][2],
                      centers[a][0],centers[a][1],centers[a][2],
                      centers[a+1][0],centers[a+1][1],centers[a+1][2],
                      1,1,1);
                  }
                  fprintf(file, "ST(%f,%f,%f, %f,%f,%f, %f,%f,%f){%d,%d,%d};\n",
                      centers[0][0],centers[0][1],centers[0][2],
                      centers[centers.size()-1][0],centers[centers.size()-1][1],centers[centers.size()-1][2],
                      centers[1][0],centers[1][1],centers[1][2],
                      1,1,1);
                  ++elemDrawn;
                }
              }
            } // if edge was inserted
          } // if edges does not have a too large angle with normals to its extremities
        } // if edge passes conditions
      } // if i is an edge vertex
    } // for incident edges
  } // for vertices.num

  if(draw){
    fprintf(file, "};");
    fclose(file);
  }

  for(size_t i = 0; i < mesh2D->vertices.num; ++i){
    (*forest->forestOptions->featureSizeAtVertices)[i] = sizeAtVertices[i];
  }

  return HXT_STATUS_OK;

}

HXTStatus featureSize2D(Forest* forest){

  HXTMesh *meshBnd  = forest->forestOptions->mesh2D;
  int nLayersPerGap = forest->forestOptions->nodePerGap;
  double hmin       = forest->forestOptions->hmin;
  double hmax       = forest->forestOptions->hmax;

  std::vector<double> sizeAtVertices(meshBnd->vertices.num, DBL_MAX);

  int firstVertex = (*forest->forestOptions->c2vBnd)[0]->getNum();

  // All triangles
  std::vector<MTriangle*> allTris;
  std::vector<std::set<uint64_t>> triIncidents(meshBnd->vertices.num);
  std::vector<std::set<MEdge,MEdgeLessThan>> edgIncidents(meshBnd->vertices.num);

  // The empty mesh is stored in meshBnd, so it does have triangles
  uint64_t count = 0;
  for(size_t i = 0; i < meshBnd->triangles.num; ++i){
    // if(meshBnd->triangles.node[3*i+2] != HXT_GHOST_VERTEX){
      allTris.push_back(new MTriangle((*forest->forestOptions->c2vBnd)[ meshBnd->triangles.node[3*i+0] ],
                                      (*forest->forestOptions->c2vBnd)[ meshBnd->triangles.node[3*i+1] ],
                                      (*forest->forestOptions->c2vBnd)[ meshBnd->triangles.node[3*i+2] ]));

      for(size_t j = 0; j < 3; ++j){
        triIncidents[ meshBnd->triangles.node[3*i+j] ].insert(count);
      }
      for(size_t j = 0; j < 3; ++j){
        MEdge e = allTris[count]->getEdge(j);
        edgIncidents[ allTris[count]->getEdge(j).getVertex(0)->getNum() - firstVertex ].insert(e);
        edgIncidents[ allTris[count]->getEdge(j).getVertex(1)->getNum() - firstVertex ].insert(e);
      }
      ++count;
    // }
  }

  std::set<MEdge,MEdgeLessThan> axis;
  int elemDrawn = 0;

  FILE* file = fopen("medialAxis2D.pos", "w");
  if(file==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  FILE* file2 = fopen("keptEdges.pos", "w");
  if(file2==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  bool draw = true;
  if(draw){
    fprintf(file, "View \"medialAxis\" {\n");
    fprintf(file2, "View \"keptEdges\" {\n");
  }

  int indEdge;

  for(size_t i = 0; i < meshBnd->vertices.num; ++i){
    // Pôle de p : circumcenter le plus loin parmi les tets incidents à p
    SPoint3 pole(0.,0.,0.),
             tmp(0.,0.,0.),
               p(meshBnd->vertices.coord[4*i+0], meshBnd->vertices.coord[4*i+1], meshBnd->vertices.coord[4*i+2]);
    double d = 0.;

    for(auto const &tri : triIncidents[i]){
      tmp = allTris[ tri ]->circumcenter();
      if(p.distance(tmp) > d) pole = tmp;
      d = fmax(d, p.distance(tmp));
    }

    // Pole vector
    SPoint3 vp = pole - p;
    // Equation of the line perpendicular to vp passing through p
    double a = (p[0] - pole[0])/(pole[1] - p[1]);
    double b = p[1] - a*p[0];
    // Another point on this line
    SPoint3 p1(0., b, 0.);

    std::vector<MEdge> up; // umbrella
    // Boucle sur les voronoi edges (paires de centres)
    double orientj, orientk;
    for(auto const &trij : triIncidents[i]){
      // uint64_t trij = triIncidents[i][j];
      SPoint3 cj = allTris[trij]->circumcenter();
      for(auto const &trik : triIncidents[i]){
        // uint64_t trik = triIncidents[i][k];
        if( trij != trik ){
          indEdge = commonEdgeTriFast(allTris[trij], allTris[trik]);
          if(indEdge >= 0){
            SPoint3 ck = allTris[trik]->circumcenter();
            orientj = robustPredicates::orient2d((double*) p, (double*) p1, (double*) cj);
            orientk = robustPredicates::orient2d((double*) p, (double*) p1, (double*) ck);
            if(orientj*orientk < 0){
              up.push_back(allTris[trij]->getEdge(indEdge));
              // break; ?
            }
          }
        }
      }
    }

    // if(i % 10){
    // for(auto const &e : up){
    //   fprintf(file, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n",
    //                   e.getVertex(0)->x(), e.getVertex(0)->y(), e.getVertex(0)->z(),
    //                   e.getVertex(1)->x(), e.getVertex(1)->y(), e.getVertex(1)->z(),
    //                   e.length(), e.length());
    // }
    // }

    double theta = M_PI/8., rho = 8., maxAngle, minRatio, localAngle, alpha0, alpha1;
    std::vector<MEdge> checkedEdges;
    bool checked;
    // for(size_t j = 0; j < edgIncidents[i].size(); ++j){ // boucler sur les aretes incidentes à p
    for(auto const &e : edgIncidents[i]){ // boucler sur les aretes incidentes à p
      // MEdge e = edgIncidents[i][j];
      checked = false;
      for(size_t k = 0; k < checkedEdges.size(); ++k){
        if(e == checkedEdges[k]){
          checked = true;
          break;
        }
      }

      if(checked){ continue; }
      else{ checkedEdges.push_back(e); }

      maxAngle = 0.0;
      minRatio = DBL_MAX;

      uint32_t v0 = e.getVertex(0)->getNum() - firstVertex;
      uint32_t v1 = e.getVertex(1)->getNum() - firstVertex;
      if(v0 == i || v1 == i){
        for(size_t l = 0; l < up.size(); ++l){
          // Angle condition
          SVector3 t = up[l].tangent(), normal(0.,0.,0.);
          if(t[2] <= 1e-10){ // Assuming the model is in the XY plane
            normal = crossprod(t, SVector3(0.,0.,1.));
          }
          normal.normalize();
          localAngle = angle( e.tangent(), normal );
          localAngle = fmin(localAngle, fabs(M_PI - localAngle));
          maxAngle = fmax(maxAngle, localAngle);


          // Ratio condition
          // MTriangle tri(up[l].getVertex(0),up[l].getVertex(1),up[l].getVertex(2));
          // minRatio = fmin(minRatio, e.length() / tri.getOuterRadius());
          minRatio = fmin(minRatio, e.length() / (up[l].length()/2.) );
        }

        if(maxAngle < M_PI/2. - theta || minRatio > rho){
          double *n0 = forest->forestOptions->nodeNormals + 3*v0;
          double *n1 = forest->forestOptions->nodeNormals + 3*v1;
          alpha0 = angle(SVector3(n0), e.tangent());
          alpha1 = angle(SVector3(n1), e.tangent());

          if( fmin(alpha0, fabs(M_PI-alpha0)) < M_PI/8. && fmin(alpha1, fabs(M_PI-alpha1)) < M_PI/8.){
            // Add edge to the set (axis, though actually unused), modifiy size at its extrmities and draw the dual facet
            std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> ret = axis.insert(e);

            if(ret.second){
              double h = e.length()/nLayersPerGap;
              h = fmax(h, hmin);
              h = fmin(h, hmax);
              sizeAtVertices[ v0 ] = fmin(h, sizeAtVertices[ v0 ]);
              sizeAtVertices[ v1 ] = fmin(h, sizeAtVertices[ v1 ]);

              fprintf(file2, "SL(%f,%f,%f, %f,%f,%f){%2.4e,%2.4e};\n",
                      e.getVertex(0)->x(), e.getVertex(0)->y(), e.getVertex(0)->z(),
                      e.getVertex(1)->x(), e.getVertex(1)->y(), e.getVertex(1)->z(),
                      10.0,10.0);

              if(draw){
                // Turning around the edge to draw the facet
                std::vector<SPoint3> centers;
                for(auto const &trij : triIncidents[i]){
                  for(size_t ii = 0; ii < 3; ++ii){
                    if(allTris[trij]->getEdge(ii) == e) centers.push_back(allTris[trij]->circumcenter());
                  }
                }
                if(centers.size() == 2){
                  fprintf(file, "SL(%f,%f,%f, %f,%f,%f){%2.4e,%2.4e};\n", 
                    centers[0].x(),centers[0].y(),centers[0].z(),
                    centers[1].x(),centers[1].y(),centers[1].z(),
                    200.0,200.0);
                  ++elemDrawn;
                }
              }
            } // if edge was inserted
          } // if edges does not have a too large angle with normals to its extremities
        } // if edge passes conditions
      } // if i is an edge vertex
    } // for incident edges
  } // for vertices.num

  if(draw){
    fprintf(file, "};");
    fclose(file);
    fprintf(file2, "};");
    fclose(file2);
  }

  for(size_t i = 0; i < meshBnd->vertices.num; ++i){
    (*forest->forestOptions->featureSizeAtVertices)[i] = sizeAtVertices[i];
  }

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   ESTIMATE NUMBER OF TETRAHEDRA IN THE VOLUME MESH
   ======================================================================================================== */

static void elementEstimate(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  double center[3];
  getCellCenter(p4est, which_tree, q, center);

  double octantVolume = data->h * data->h * data->h;
  double tetVolume = data->size[0] * data->size[0] * data->size[0] * sqrt(2) / 12.0;

  *((double *) user_data) += octantVolume/tetVolume;
}

HXTStatus hxtOctreeElementEstimation(Forest *forest, double *elemEstimate){
  p4est_iterate (forest->p4est, NULL, (void *) elemEstimate, elementEstimate, NULL, NULL, NULL);
  return HXT_STATUS_OK;
}

/* ========================================================================================================
   EXPORT
   ======================================================================================================== */

HXTStatus saveGlobalData(Forest *forest, const char *filename){
  FILE* f = fopen(filename, "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  fprintf(f, "%f %f\n", forest->forestOptions->hmin, forest->forestOptions->hmax);
  fclose(f);
  Msg::Info("Writing global size field data in %s", filename);
  return HXT_STATUS_OK;
}

static void exportToHexCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  FILE* f = (FILE*) user_data;
  double center[3], x[8], y[8], z[8];
  getCellCenter(p4est, which_tree, q, center);
  double h = data->h/2.0, s = data->size[0], epsilon = 1e-12;
  x[0] = x[3] = x[4] = x[7] = center[0]-h - epsilon;
  x[1] = x[2] = x[5] = x[6] = center[0]+h + epsilon;
  y[0] = y[1] = y[4] = y[5] = center[1]-h - epsilon;
  y[2] = y[3] = y[6] = y[7] = center[1]+h + epsilon;
  z[0] = z[1] = z[2] = z[3] = center[2]-h - epsilon;
  z[4] = z[5] = z[6] = z[7] = center[2]+h + epsilon;

  fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f,%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f,%f,%f,%f,%f};\n",
    x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3],
    x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7],
    s, s, s, s, s, s, s, s);
  // fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f,%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%d, %d, %d, %d, %d, %d, %d, %d};\n",
  //   x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3],
  //   x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7],
  //   data->hasIntersection, data->hasIntersection, data->hasIntersection, data->hasIntersection,
  //   data->hasIntersection, data->hasIntersection, data->hasIntersection, data->hasIntersection);
}

static void exportToCrossesAnisoCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  FILE* f = (FILE*) user_data;
  double center[3], x[8], y[8], z[8];
  getCellCenter(p4est, which_tree, q, center);
  double h = data->h/2.0, epsilon = 1e-12; // s = data->size[0];
  x[0] = x[3] = x[4] = x[7] = center[0]-h - epsilon;
  x[1] = x[2] = x[5] = x[6] = center[0]+h + epsilon;
  y[0] = y[1] = y[4] = y[5] = center[1]-h - epsilon;
  y[2] = y[3] = y[6] = y[7] = center[1]+h + epsilon;
  z[0] = z[1] = z[2] = z[3] = center[2]-h - epsilon;
  z[4] = z[5] = z[6] = z[7] = center[2]+h + epsilon;

  // fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f,%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f,%f,%f,%f,%f};\n",
  //   x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3],
  //   x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7],
  //   s, s, s, s, s, s, s, s);

  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[0], y[0], z[0], x[1], y[1], z[1], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[2], y[2], z[2], x[1], y[1], z[1], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[2], y[2], z[2], x[3], y[3], z[3], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[0], y[0], z[0], x[3], y[3], z[3], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[0], y[0], z[0], x[4], y[4], z[4], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[1], y[1], z[1], x[5], y[5], z[5], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[2], y[2], z[2], x[6], y[6], z[6], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[3], y[3], z[3], x[7], y[7], z[7], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[4], y[4], z[4], x[5], y[5], z[5], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[6], y[6], z[6], x[5], y[5], z[5], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[6], y[6], z[6], x[7], y[7], z[7], s, s);
  // fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[4], y[4], z[4], x[7], y[7], z[7], s, s);
  
  // double cross[9];

  double dir[9]={data->dir[0], data->dir[1], data->dir[2],
                 data->dir[3], data->dir[4], data->dir[5],
                 data->dir[6], data->dir[7], data->dir[8]};
                   
  // double frame[9]={0.0};
  // hxtOr3DdirectionsToFrame(dir, frame);

  // // double *x = mesh->vertices.coord +4*i;
  // // const double *vertexFrame = frames+i*9;
  // double stableDir[3]={0.0};
  // hxtOr3DframeToDirections(frame, stableDir, cross);
  // double color[3];
  // for(int k=0;k<3;k++)
  //   color[k]=1.0;
  // double quality=0.0;
  // hxtOr3DcomputeQuality(frame,&quality);
  // if(quality>0.25){
  //   for(int k=0; k<3; k++){
  //     double val=stableDir[k]-0.9;
  //     (val<0)? color[k]=0.:color[k]=0.5;
  //   }
  // }
  if(data->hasIntersection){
    for (int j = 0; j < 3; ++j) {
      // double d[3] = {cross[3*j+0], cross[3*j+1], cross[3*j+2]};
      double d[3] = {dir[3*j+0], dir[3*j+1], dir[3*j+2]};
      // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2], color[j]*d[0], color[j]*d[1], color[j]*d[2]);
      // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2],-color[j]*d[0],-color[j]*d[1],-color[j]*d[2]);
      fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2], data->size[j]/sqrt(3.)*d[0], data->size[j]/sqrt(3.)*d[1], data->size[j]/sqrt(3.)*d[2]);
      fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2],-data->size[j]/sqrt(3.)*d[0],-data->size[j]/sqrt(3.)*d[1],-data->size[j]/sqrt(3.)*d[2]);

    }
  }
}

static void exportToQuadCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;

  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  FILE* f = (FILE*) user_data;

  double center[3], x[8], y[8], z[8];
  getCellCenter(p4est, which_tree, q, center);

  double h = data->h/2.0, s = data->size[0], epsilon = 1e-12;
  x[0] = x[3] = center[0]-h - epsilon;
  x[1] = x[2] = center[0]+h + epsilon;
  y[0] = y[1] = center[1]-h - epsilon;
  y[2] = y[3] = center[1]+h + epsilon;
  z[0] = z[1] = 0.0;
  z[2] = z[3] = 0.0;

  fprintf(f, "SQ(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n",
    x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3],
    s, s, s, s);
}

HXTStatus forestExport(Forest *forest, const char *forestFile){
  FILE* f = fopen(forestFile, "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  fprintf(f, "View \"sizeField\" {\n");
  if(forest->forestOptions->aniso){
    p4est_iterate(forest->p4est, NULL, (void*) f, exportToCrossesAnisoCallback, NULL, NULL, NULL);
  } else{
    if      (forest->forestOptions->dim == 3){ p4est_iterate(forest->p4est, NULL, (void*) f, exportToHexCallback, NULL, NULL, NULL);  }
    else if (forest->forestOptions->dim == 2){ p4est_iterate(forest->p4est, NULL, (void*) f, exportToQuadCallback, NULL, NULL, NULL); }
  }
  
  fprintf(f, "};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus forestSave(Forest *forest, const char *forestFile, const char *dataFile){
  HXT_CHECK( saveGlobalData(forest, dataFile) );
  p4est_save_ext(forestFile, forest->p4est, true, false);
  return HXT_STATUS_OK;
}

HXTStatus forestWriteSolFileSurface(Forest *forest, const char *solFile){
  FILE* f = fopen(solFile, "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  fprintf(f, "MeshVersionFormatted 1\n\n");
  fprintf(f, "Dimension 3\n\n");
  fprintf(f, "SolAtVertices\n");
  fprintf(f, "%d\n", forest->forestOptions->mesh2D->vertices.num);
  fprintf(f, "1 3\n");

  for(size_t i = 0; i < forest->forestOptions->mesh2D->vertices.num; ++i){
    double x = forest->forestOptions->mesh2D->vertices.coord[(size_t) 4*i+0];
    double y = forest->forestOptions->mesh2D->vertices.coord[(size_t) 4*i+1];
    double z = forest->forestOptions->mesh2D->vertices.coord[(size_t) 4*i+2];
    SMetric3 m;
    HXT_CHECK(forestSearchOneAniso(forest, x, y, z, m, false));
    fprintf(f, "%f %f %f %f %f %f\n", m(0,0), m(0,1), m(1,1), m(0,2), m(1,2), m(2,2));
  }

  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus forestWriteSolFileVolume(Forest *forest, const char *solFile){
  FILE* f = fopen(solFile, "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  fprintf(f, "MeshVersionFormatted 1\n\n");
  fprintf(f, "Dimension 3\n\n");
  fprintf(f, "SolAtVertices\n");
  fprintf(f, "%d\n", forest->forestOptions->mesh3D->vertices.num);
  fprintf(f, "1 3\n");

  for(size_t i = 0; i < forest->forestOptions->mesh3D->vertices.num; ++i){
    double x = forest->forestOptions->mesh3D->vertices.coord[(size_t) 4*i+0];
    double y = forest->forestOptions->mesh3D->vertices.coord[(size_t) 4*i+1];
    double z = forest->forestOptions->mesh3D->vertices.coord[(size_t) 4*i+2];
    SMetric3 m;
    HXT_CHECK(forestSearchOneAniso(forest, x, y, z, m, false));
    fprintf(f, "%f %f %f %f %f %f\n", m(0,0), m(0,1), m(1,1), m(0,2), m(1,2), m(2,2));
  }

  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus writeRTree(RTree<uint64_t,double,3>  *rtree, const char *filename){
  RTree<uint64_t, double, 3>::Iterator it;
  FILE* f = fopen(filename, "w");
  fprintf(f, "View \"rtree\" {\n");
  int itIndex = 0;
  double s = 1.0;
  double x[8], y[8], z[8];
  // Using custom GetNext2 to display intermediary rectangles
  for( rtree->GetFirst(it); !rtree->IsNull(it); rtree->GetNext2(it) )
  {
    int value = rtree->GetAt(it);
    double boundsMin[3] = {0,0,0};
    double boundsMax[3] = {0,0,0};
    it.GetBounds(boundsMin, boundsMax);
    std::cout << "it[" << itIndex++ << "] " << value << " = (" << boundsMin[0] << "," << boundsMin[1] << "," << boundsMin[2] << "," << boundsMax[0] << "," << boundsMax[1] << "," << boundsMax[2] << ")\n";
    x[0] = x[3] = x[4] = x[7] = boundsMin[0];
    x[1] = x[2] = x[5] = x[6] = boundsMax[0];
    y[0] = y[1] = y[4] = y[5] = boundsMin[1];
    y[2] = y[3] = y[6] = y[7] = boundsMax[1];
    z[0] = z[1] = z[2] = z[3] = boundsMin[2];
    z[4] = z[5] = z[6] = z[7] = boundsMax[2];
    fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f,%f,%f,%f,%f};\n",
      x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3],
      x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7],
      s, s, s, s, s, s, s, s);
  }
  // Adding the root rectangle (the bbox)
  // x[0] = x[3] = x[4] = x[7] = bbox_mesh.min[0];
  // x[1] = x[2] = x[5] = x[6] = bbox_mesh.max[0];
  // y[0] = y[1] = y[4] = y[5] = bbox_mesh.min[1];
  // y[2] = y[3] = y[6] = y[7] = bbox_mesh.max[1];
  // z[0] = z[1] = z[2] = z[3] = bbox_mesh.min[2];
  // z[4] = z[5] = z[6] = z[7] = bbox_mesh.max[2];
  // fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f,%f,%f,%f,%f};\n",
  //     x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3],
  //     x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7],
  //     s, s, s, s, s, s, s, s);
  fprintf(f, "};");
  fclose(f);

  return HXT_STATUS_OK;
}

#endif

/* ======================================================================================
   End functions from hxt_octree
   ====================================================================================== */

double automaticMeshSizeField::operator()(double X, double Y, double Z, GEntity *ge) {
  double val = 1.e17;
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = forestSearchOne(forest, X, Y, Z, &val, true);
  if (s == HXT_STATUS_OK){
    return val;
  }
  else Msg::Error ("Cannot find point %g %g %g in the octree",X,Y,Z);
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST to use automaticMeshSizeField");
#endif
  return val;
}

void automaticMeshSizeField::operator()(double X, double Y, double Z, SMetric3 &m, GEntity *ge){
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = forestSearchOneAniso(forest, X, Y, Z, m, false);
  if(fabs(m.determinant()) < 1e-13)
    m = SMetric3();
  if (s != HXT_STATUS_OK) Msg::Error ("Cannot find point %g %g %g in the octree",X,Y,Z);
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST to use automaticMeshSizeField");
#endif
}

automaticMeshSizeField::~automaticMeshSizeField(){
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  if (forest) forestDelete(&forest);
  if (forestOptions) forestOptionsDelete(&forestOptions);
#endif
}

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
HXTStatus automaticMeshSizeField::updateHXT(){

  if(!updateNeeded)
    return HXT_STATUS_OK;

  if (forestOptions) HXT_CHECK(forestOptionsDelete(&forestOptions));
  if (forest)        HXT_CHECK(forestDelete(&forest));

  updateNeeded = false;

  if(!_forestFile.empty()){
    // Load .p4est file if given a valid file name
    Msg::Info("Loading size field from %s", _forestFile.c_str());
    HXT_CHECK(forestOptionsCreate(&forestOptions));
    size_t lastindex = _forestFile.find_last_of(".");
    std::string root = _forestFile.substr(0, lastindex);
    std::string forestFile = root + ".p4est";
    std::string dataFile   = root + ".data";
    HXT_CHECK( forestLoad(&forest, forestFile.c_str(), dataFile.c_str(), forestOptions) );
  } else{
    // Compute the size field otherwise
    int dim = GModel::current()->getDim();

    HXT_CHECK(forestOptionsCreate(&forestOptions));

    Msg::Info("Gradation = %f\n", _gradation);
    Msg::Info("Node density = %d\n", _nPointsPerCircle);
    if(dim == 3){
      if(_nPointsPerGap > 0){
        Msg::Info("Layers per gap = %d\n", _nPointsPerGap); }
      else{
        Msg::Info("Layers per gap = %d : not detecting features.\n", _nPointsPerGap);}
    }

    // The bounding box of the mesh/model
    double bbox_vertices[6];

    RTree<uint64_t, double, 3> bndRTree;
    RTree<uint64_t, double, 3> domRTree;
    HXTMesh *meshDom;
    HXTMesh *meshBnd;
    std::vector<MVertex *>        c2vDom;
    std::map<MVertex *, uint32_t> v2cDom;
    std::vector<MVertex *>        c2vBnd;
    std::map<MVertex *, uint32_t> v2cBnd;

    double *nodalCurvature;
    double *directions;
    double *directionsU;
    double *directionsV;
    double *directionsW;
    std::vector<double> nodeNormals;

    int debug = true;    

    if(dim == 3){

      // 1. Get all faces of the model and create HXT mesh structure
      std::vector<GFace*> faces;
      std::vector<GRegion*> regions;
      HXT_CHECK(hxtMeshCreate(&meshBnd));
      HXT_CHECK(hxtMeshCreate(&meshDom));

      for(auto const &region : GModel::current()->getRegions()){
        regions.push_back(region);
      }
      HXT_CHECK( getAllFacesOfAllRegions(regions, NULL, faces) );
      if(regions.empty() || faces.empty()){
        if(regions.empty()) Msg::Info("No volume in the model : looping over model faces instead.");
        if(faces.empty())   Msg::Info("No faces found in model volumes : looping over model faces instead.");
        for(auto const &face : GModel::current()->getFaces()){
          faces.push_back(face);
          Msg::Info("Looping over model faces - current has %d elements\n", face->getNumMeshElements());
        }
      }

      if(faces.empty()){
        Msg::Error("Error : model has no faces or volume faces.");
      }
      
      HXT_CHECK(Gmsh2Hxt(faces, meshBnd, v2cBnd, c2vBnd));
      HXT_CHECK(Gmsh2Hxt(faces, regions, meshDom, v2cDom, c2vDom));

      Msg::Info("Comparaison des maillages HXT :");
      printf("Nombre de noeuds : 2D - %d \t 3D - %d\n", meshBnd->vertices.num, meshDom->vertices.num);
      printf("Nombre de triang : 2D - %lu \t 3D - %lu\n", meshBnd->triangles.num, meshDom->triangles.num);
      printf("Nombre de tetras : 2D - %lu \t 3D - %lu\n", meshBnd->tetrahedra.num, meshDom->tetrahedra.num);

      if(meshBnd->vertices.num == 0){
        Msg::Error("Boundary mesh is empty");
        HXT_CHECK(hxtMeshDelete(&meshBnd));
        HXT_CHECK(hxtMeshDelete(&meshDom));
        Msg::Exit(1);
      }

      // 2. Compute curvature of the faces
      HXT_CHECK(hxtMalloc(&nodalCurvature,6*meshBnd->vertices.num*sizeof(double)));

      // Compute curvature of the faces
      for(auto const &face : faces) {
        HXTMesh *meshFace;
        HXT_CHECK(hxtMeshCreate(&meshFace));
        std::vector<GFace*> oneFace(1, face);
        std::map<MVertex *, uint32_t> v2cLoc;
        std::vector<MVertex *>        c2vLoc;
        Gmsh2HxtLocal(oneFace, meshFace, v2cLoc, c2vLoc);

        std::vector<std::pair<SVector3, SVector3> > curv;
        std::vector<int> tris(meshFace->triangles.node, meshFace->triangles.node + 3*meshFace->triangles.num);
        std::vector<SPoint3> nodes(meshFace->vertices.num);
        for(uint32_t i = 0; i < meshFace->vertices.num; ++i){
          nodes[i] = c2vLoc[i]->point();
        }

        if(face->triangles.empty()){
          Msg::Info("Skipping curvature computation on face %d with 0 element", face->tag());
        } else{
          // Compute curvature of the face
          CurvatureRusinkiewicz(tris, nodes, curv);
          // Assemble curvature vectors of the face in global nodalCurvature structure
          for (uint32_t i = 0; i < meshFace->vertices.num; ++i){
            uint32_t nodeGlobal = v2cBnd[ c2vLoc[i] ];
            nodalCurvature[6 * nodeGlobal + 0] = curv[i].first[0];
            nodalCurvature[6 * nodeGlobal + 1] = curv[i].first[1];
            nodalCurvature[6 * nodeGlobal + 2] = curv[i].first[2];
            nodalCurvature[6 * nodeGlobal + 3] = curv[i].second[0];
            nodalCurvature[6 * nodeGlobal + 4] = curv[i].second[1];
            nodalCurvature[6 * nodeGlobal + 5] = curv[i].second[2];
          }
        }

        HXT_CHECK(hxtMeshDelete(&meshFace));
      } // for faces.size()

      debug = true;
      if(debug) writeNodalCurvature(nodalCurvature, meshBnd->vertices.num, "nodalCurvature.txt");

      // 3. Compute an approximation of the medial axis to get feature size
      // Compute Delaunay tetrahedrization of the (empty) surface mesh
      HXTDelaunayOptions delaunayOptions = {NULL, NULL, 0, 0, 0, 0, 2, 1, 0};
      HXT_CHECK(hxtEmptyMesh(meshBnd, &delaunayOptions));

      // Compute normal vectors
      std::vector<std::pair<SVector3, SVector3> > curv;
      std::vector<int> tris(meshBnd->triangles.node, meshBnd->triangles.node + 3*meshBnd->triangles.num);
      std::vector<SPoint3> nodes(meshBnd->vertices.num);
      for(size_t i = 0; i < meshBnd->vertices.num; ++i){
        nodes[i] = c2vBnd[i]->point();
      }

      nodeNormals.reserve(3*meshBnd->vertices.num);
      for(uint32_t i = 0; i < 3*meshBnd->vertices.num; ++i)
        nodeNormals[i] = 0.0;

      // Same function but returns the normals
      // Must be called on the global structure for tris and nodes, not the ones based on each face
      CurvatureRusinkiewicz(tris, nodes, curv, nodeNormals);

      // Add bboxes of the surface mesh to rtree
      HXTBbox bbox_triangle;
      for(uint64_t i = 0; i < meshBnd->triangles.num; ++i){
        hxtBboxInit(&bbox_triangle);
        for(uint64_t j = 0; j < 3; ++j){
          double coord[3];
          uint32_t node = meshBnd->triangles.node[3*i+j];
          for(uint32_t k = 0; k < 3; ++k){ coord[k] = meshBnd->vertices.coord[(size_t) 4*node+k]; }
          hxtBboxAddOne(&bbox_triangle, coord);
        }
        SBoundingBox3d cube_bbox(bbox_triangle.min[0], bbox_triangle.min[1], bbox_triangle.min[2],
                                 bbox_triangle.max[0], bbox_triangle.max[1], bbox_triangle.max[2]);
        bndRTree.Insert((double*)(cube_bbox.min()), (double*)(cube_bbox.max()), i);
      }

      // Add bboxes of the volume mesh to rtree
      HXTBbox bbox_tet;
      for(uint64_t i = 0; i < meshDom->tetrahedra.num; ++i){
        hxtBboxInit(&bbox_tet);
        for(uint64_t j = 0; j < 4; ++j){
          double coord[3];
          uint32_t node = meshDom->tetrahedra.node[4*i+j];
          for(uint32_t k = 0; k < 3; ++k){ coord[k] = meshDom->vertices.coord[(size_t) 4*node+k]; }
          hxtBboxAddOne(&bbox_tet, coord);
        }
        SBoundingBox3d cube_bbox(bbox_tet.min[0], bbox_tet.min[1], bbox_tet.min[2],
                                 bbox_tet.max[0], bbox_tet.max[1], bbox_tet.max[2]);
        domRTree.Insert((double*)(cube_bbox.min()), (double*)(cube_bbox.max()), i);
      }

      // Export RTrees in .pos file
      bool exportRTree = false;
      if(exportRTree){ HXT_CHECK(writeRTree(&bndRTree, "rtreeBnd.pos")); }
      if(exportRTree){ HXT_CHECK(writeRTree(&domRTree, "rtreeDom.pos")); }

      HXT_CHECK(hxtMalloc(&directions,9*meshDom->vertices.num*sizeof(double)));
      HXT_CHECK(hxtMalloc(&directionsU,3*meshDom->tetrahedra.num*sizeof(double)));
      HXT_CHECK(hxtMalloc(&directionsV,3*meshDom->tetrahedra.num*sizeof(double)));
      HXT_CHECK(hxtMalloc(&directionsW,3*meshDom->tetrahedra.num*sizeof(double)));

    } // if dim==3

    if(dim == 2){
      // 1. Get all faces of the model and create global HXT mesh structure
      std::vector<GEdge*> edges;
      std::vector<GFace*> faces;
      HXT_CHECK(hxtMeshCreate(&meshDom));
      HXT_CHECK(hxtMeshCreate(&meshBnd));

      for(auto const &face : GModel::current()->getFaces()){
        faces.push_back(face);
      }
      HXT_CHECK( getAllEdgesOfAllFaces(faces, NULL, edges) );
      if(faces.empty() || edges.empty()){
        if(faces.empty()) Msg::Info("No faces in the model : looping over model edges instead.");
        if(edges.empty()) Msg::Info("No edges found in model faces : looping over model edges instead.");
        for(auto const &edge : GModel::current()->getEdges()){
          edges.push_back(edge);
          Msg::Info("Looping over model edges - current has %d elements\n", edge->getNumMeshElements());
        }
      }

      if(edges.empty()){
        Msg::Error("Error : model has no edges or face edges.");
      } else{
        Msg::Info("Model has %d edges and %d faces\n", edges.size(), faces.size());
      }

      HXT_CHECK(Gmsh2Hxt(faces, meshDom, v2cDom, c2vDom));
      HXT_CHECK(Gmsh2Hxt(edges, meshBnd, v2cBnd, c2vBnd));

      if(meshBnd->vertices.num == 0){
        Msg::Error("Boundary mesh is empty : can't compute a size field.");
        HXT_CHECK(hxtMeshDelete(&meshDom));
        HXT_CHECK(hxtMeshDelete(&meshBnd));
        Msg::Exit(1);
      }
      
      // 2. Compute curvature of the edges
      HXT_CHECK(hxtMalloc(&nodalCurvature,meshBnd->vertices.num*sizeof(double)));

      for(auto const &edge : edges){
        discreteEdge dEdge(GModel::current(), edge->tag());
        for(size_t i = 0; i < edge->getNumMeshElementsByType(TYPE_LIN); ++i){
          dEdge.addElement(TYPE_LIN, edge->getMeshElementByType(TYPE_LIN,i));
        }
        dEdge.createGeometry();
        for(auto const &vert : edge->mesh_vertices){
          double par = dEdge.parFromPoint(vert->point());
          nodalCurvature[v2cBnd[vert]] = dEdge.curvature(par);
        }
        while(dEdge.getNumMeshElements()){
          dEdge.removeElement(TYPE_LIN, dEdge.getMeshElement(0));
        }
      }

      // 3. Compute an approximation of the medial axis

      // Get Delaunay triangulation (empty mesh) of the edges vertices
      HXT_CHECK(emptyMesh2D(meshBnd, false, "delaunayBnd.msh"));
      HXT_CHECK(emptyMesh2D(meshDom, true , "delaunayDom.msh"));

      Msg::Info("Boundary mesh :");
      Msg::Info("Nombre de noeuds : %d\n",  meshBnd->vertices.num);
      Msg::Info("Nombre de lignes : %lu\n", meshBnd->lines.num);
      Msg::Info("Nombre de triang : %lu\n", meshBnd->triangles.num);
      Msg::Info("Nombre de tetras : %lu\n", meshBnd->tetrahedra.num);

      Msg::Info("Domain mesh :");
      Msg::Info("Nombre de noeuds : %d\n",  meshDom->vertices.num);
      Msg::Info("Nombre de lignes : %lu\n", meshDom->lines.num);
      Msg::Info("Nombre de triang : %lu\n", meshDom->triangles.num);
      Msg::Info("Nombre de tetras : %lu\n", meshDom->tetrahedra.num);

      // Normal vectors at vertices
      FILE* myfile = fopen("normals.pos","w");
      fprintf(myfile,"View \"normals\"{\n");

      nodeNormals.reserve(3*meshBnd->vertices.num);
      for(uint32_t i = 0; i < 3*meshBnd->vertices.num; ++i)
        nodeNormals[i] = 0.0;

      // Loop over the GEdge
      for(auto const &edge : edges){
        for(size_t i = 0; i < edge->getNumMeshElementsByType(TYPE_LIN); ++i){
          MEdge e = (reinterpret_cast<MLine *>(edge->getMeshElementByType(TYPE_LIN,i)))->getEdge(0);
          SVector3 t = e.tangent(), normal(0.,0.,0.);
          if(t[2] <= 1e-10){ // Assuming the model is in the XY plane
            normal = crossprod(t, SVector3(0.,0.,1.));
          }
          normal.normalize();
          nodeNormals[3*v2cBnd[e.getVertex(0)]+0] += normal(0);
          nodeNormals[3*v2cBnd[e.getVertex(0)]+1] += normal(1);
          nodeNormals[3*v2cBnd[e.getVertex(0)]+2] += normal(2);
          nodeNormals[3*v2cBnd[e.getVertex(1)]+0] += normal(0);
          nodeNormals[3*v2cBnd[e.getVertex(1)]+1] += normal(1);
          nodeNormals[3*v2cBnd[e.getVertex(1)]+2] += normal(2);
          // fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",
          //   (e.getVertex(0)->x() + e.getVertex(1)->x())/2.,
          //   (e.getVertex(0)->y() + e.getVertex(1)->y())/2.,
          //   (e.getVertex(0)->z() + e.getVertex(1)->z())/2.,
          //   normal(0), normal(1), normal(2));
        }
      }

      for(uint32_t i = 0; i < meshBnd->vertices.num; ++i){
        SVector3 v(nodeNormals[3*i],nodeNormals[3*i+1],nodeNormals[3*i+2]);
        v.normalize();
        nodeNormals[3*i+0] = v[0];
        nodeNormals[3*i+1] = v[1];
        nodeNormals[3*i+2] = v[2];
      }

      for(uint32_t i = 0; i < meshBnd->vertices.num; ++i){
        double *x = meshBnd->vertices.coord + 4*i;
        fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",
            x[0], x[1], x[2], nodeNormals[3*i+0], nodeNormals[3*i+1], nodeNormals[3*i+2]);
      }

      fprintf(myfile,"};");
      fclose(myfile);

      forestOptions->v2cBnd = &v2cBnd;
      forestOptions->c2vBnd = &c2vBnd;

      // 4. RTree for surface and boundary meshes
      // Add bboxes of the inside/volume mesh to rtree
      HXTBbox bbox_triangle;
      for(uint64_t i = 0; i < meshDom->triangles.num; ++i){
        hxtBboxInit(&bbox_triangle);
        for(uint64_t j = 0; j < 3; ++j){
          double coord[3];
          uint32_t node = meshDom->triangles.node[3*i+j];
          for(uint32_t k = 0; k < 3; ++k){ coord[k] = meshDom->vertices.coord[(size_t) 4*node+k]; }
          hxtBboxAddOne(&bbox_triangle, coord);
        }
        SBoundingBox3d cube_bbox(bbox_triangle.min[0], bbox_triangle.min[1], bbox_triangle.min[2],
                                 bbox_triangle.max[0], bbox_triangle.max[1], bbox_triangle.max[2]);
        domRTree.Insert((double*)(cube_bbox.min()), (double*)(cube_bbox.max()), i);
      }

      // Add bboxes of the boundary mesh to rtree
      HXTBbox bbox_edge;
      for(uint64_t i = 0; i < meshBnd->lines.num; ++i){
        hxtBboxInit(&bbox_edge);
        for(uint64_t j = 0; j < 2; ++j){
          double coord[3];
          uint32_t node = meshBnd->lines.node[2*i+j];
          for(uint32_t k = 0; k < 3; ++k){ coord[k] = meshBnd->vertices.coord[(size_t) 4*node+k]; }
          hxtBboxAddOne(&bbox_edge, coord);
        }
        SBoundingBox3d cube_bbox(bbox_edge.min[0], bbox_edge.min[1], bbox_edge.min[2],
                                 bbox_edge.max[0], bbox_edge.max[1], bbox_edge.max[2]);
        bndRTree.Insert((double*)(cube_bbox.min()), (double*)(cube_bbox.max()), i);
      }

      HXT_CHECK(hxtMalloc(&directions,9*meshDom->vertices.num*sizeof(double)));
      // HXT_CHECK(hxtMalloc(&directionsU,3*mesh3D->tetrahedra.num*sizeof(double)));
      // HXT_CHECK(hxtMalloc(&directionsV,3*mesh3D->tetrahedra.num*sizeof(double)));
      // HXT_CHECK(hxtMalloc(&directionsW,3*mesh3D->tetrahedra.num*sizeof(double)));
    }

    // Compute bbox of the mesh
    HXTBbox bbox_mesh;
    hxtBboxInit(&bbox_mesh);
    hxtBboxAdd(&bbox_mesh, meshBnd->vertices.coord, meshBnd->vertices.num);
    for(int i = 0; i < 3; ++i){
      bbox_vertices[i  ] = bbox_mesh.min[i];
      bbox_vertices[i+3] = bbox_mesh.max[i];
    }

    // Export RTrees in .pos file
    bool exportRTree = false;
    if(exportRTree){ HXT_CHECK(writeRTree(&bndRTree, "rtreeBnd.pos")); }
    if(exportRTree){ HXT_CHECK(writeRTree(&domRTree, "rtreeDom.pos")); }

    // Set the bulk size and the min size from the bbox
    if(_hbulk < 0 || _hmin < 0){
      double L = -1.0;
      for(int i = 0; i < 3; ++i){
        L = fmax(L, bbox_vertices[i+3] - bbox_vertices[i] );
      }
      _hbulk < 0 ? _hbulk = L/20.   : _hbulk;
      _hmin  < 0 ? _hmin  = L/1000. : _hmin;
      Msg::Info("Bulk size is set to %f", _hbulk);
      Msg::Info("Min  size is set to %f", _hmin);
    }

    if(_hmax < 0)
      _hmax = _hbulk;

    std::vector<double> sizeAtVertices(meshBnd->vertices.num, DBL_MAX);

    forestOptions->aniso = true;
    forestOptions->dim = dim;
    forestOptions->hmax = 1e3; // _hmax;
    forestOptions->hmin = 1e-3; // _hmin;
    forestOptions->hbulk = 1e3; //_hbulk;
    forestOptions->gradation = _gradation;
    forestOptions->nodePerTwoPi = _nPointsPerCircle;
    forestOptions->nodePerGap = _nPointsPerGap;
    forestOptions->bbox = bbox_vertices;
    forestOptions->sizeFunction = NULL;
    forestOptions->nodalCurvature = nodalCurvature;
    forestOptions->directions = directions;
    forestOptions->directionsU = directionsU;
    forestOptions->directionsV = directionsV;
    forestOptions->directionsW = directionsW;
    forestOptions->nodeNormals = &nodeNormals[0];
    forestOptions->featureSizeAtVertices = &sizeAtVertices;
    forestOptions->bndRTree = &bndRTree;
    forestOptions->domRTree = &domRTree;
    forestOptions->mesh2D = meshBnd;
    forestOptions->mesh3D = meshDom;
    forestOptions->c2vDom = &c2vDom;

    HXT_CHECK(forestCreate(0, NULL, &forest, NULL, forestOptions));

    if(_nPointsPerGap > 0){
      Msg::Info("Detecting features...");
      if(dim == 3){ HXT_CHECK(featureSize(forest));   }
      if(dim == 2){ HXT_CHECK(featureSize2D(forest)); }
    }

    if(_nPointsPerCircle > 0){
      Msg::Info("Refining octree...");
      HXT_CHECK(forestRefine(forest));
    }

    if(_smoothing){
      if(forestOptions->aniso){
        Msg::Info("Propagating directions...");
        HXT_CHECK(forestSmoothDirections(forest));
        HXT_CHECK(forestExport(forest, "initialSize.pos"));
      }
      // Msg::Info("Limiting size gradient...");
      // HXT_CHECK(forestSizeSmoothing(forest));
    }

    // double elemEstimation;
    // HXT_CHECK(hxtOctreeElementEstimation(forest, &elemEstimation));
    // Msg::Info("Estimated number of tetrahedra in the bounding box : %ld", (uint64_t) ceil(elemEstimation));

    // Save forest in .p4est file
    std::string forestFile = GModel::current()->getName() + ".p4est";
    std::string dataFile   = GModel::current()->getName() + ".data";
    Msg::Info("Writing size field in %s", forestFile.c_str());
    HXT_CHECK(forestSave(forest, forestFile.c_str(), dataFile.c_str()));

    // Export .sol file for MMG if aniso
    if(forestOptions->aniso){
      HXT_CHECK(forestWriteSolFileSurface(forest, "metricBnd.sol"));
      HXT_CHECK(forestWriteSolFileVolume(forest, "metricDom.sol"));
    }

    debug = false;
    if(debug){
      // Export size field in .pos file
      forestFile = GModel::current()->getName() + ".pos";
      HXT_CHECK(forestExport(forest, forestFile.c_str()));
    }

    HXT_CHECK(hxtFree(&nodalCurvature));
    HXT_CHECK(hxtFree(&directions));
    HXT_CHECK(hxtFree(&directionsU));
    HXT_CHECK(hxtFree(&directionsV));
    HXT_CHECK(hxtFree(&directionsW));
    HXT_CHECK(hxtMeshDelete(&meshBnd));
    HXT_CHECK(hxtMeshDelete(&meshDom));
  }

  return HXT_STATUS_OK;
}

#endif

void automaticMeshSizeField::update(){
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = updateHXT();
  if (s != HXT_STATUS_OK) Msg::Error ("Something went wrong when computing the octree");
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST to use automaticMeshSizeField");
#endif
};
