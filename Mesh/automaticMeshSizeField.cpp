// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Arthur Bawin

#define ANISO 0
#define ZPOS 1e-8

#include "automaticMeshSizeField.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEntity.h"
#include "MPoint.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "SBoundingBox3d.h"
#include "fullMatrix.h"
#include "GmshMessage.h"
#include "curvature.h"
#include "Numeric.h"
#include "robustPredicates.h"
#include "discreteEdge.h"
#if defined(ANISO)
#include "qmtCrossField.h"
#endif

#include <queue>
#include <list>
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

int modifiedCells;

std::map< p4est_quadrant_t*, std::map< p4est_quadrant_t*, std::vector<int>>> closestDirs;

// Mark all the points which are in mesh->(points | lines) but not in triangles
// Used to get the empty mesh of 2D boundary mesh
static void markMeshPoints(HXTMesh* mesh){
  for(uint32_t i=0; i<mesh->vertices.num; i++)
    mesh->vertices.coord[4*i+3] = 0.0;
  for(uint64_t i=0; i<mesh->lines.num; i++)
    for(int j=0; j<2; j++)
      mesh->vertices.coord[4* mesh->lines.node[2*i+j] + 3] = 1.0;
  for(uint64_t i=0; i<mesh->points.num; i++)
    mesh->vertices.coord[4* mesh->points.node[i] + 3] = 1.0;
}

static HXTStatus emptyMesh2D(HXTMesh *mesh, const char* filename){
  // Remove triangles
  HXT_CHECK(hxtAlignedFree(&mesh->triangles.node));
  HXT_CHECK(hxtAlignedFree(&mesh->triangles.color));
  mesh->triangles.num = mesh->triangles.size = 0;
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
  markMeshPoints(mesh);
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

  HXT_CHECK(hxtMeshWriteGmsh(mesh, filename));

  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.color) );
  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.flag) );
  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.node) );
  HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.neigh) );
  mesh->tetrahedra.num = 0;
  mesh->tetrahedra.size = 0;

  // Remove the point (0,0,1)
  if(mesh->vertices.size == mesh->vertices.num) {
    HXT_CHECK( hxtAlignedRealloc(&mesh->vertices.coord, 4*sizeof(double) * (n)) );
    mesh->vertices.size--;
  }
  mesh->vertices.num--;

  return HXT_STATUS_OK;
}

static inline void norme2(double v[3], double* norme2){
  *norme2 = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

static inline bool isPoint(double x1, double y1, double z1, double x2,
                           double y2, double z2, double tol)
{
  return (fabs(x2 - x1) < tol && fabs(y2 - y1) < tol && fabs(z2 - z1) < tol);
}

void writeNodalCurvature(double *nodalCurvature, int size, const char *filename)
{
  FILE *f = fopen(filename, "w");
  if(f == NULL) {
    printf("Erreur : fileOutput == NULL\n");
    exit(-1);
  }

  for(int i = 0; i < size; ++i) {
    fprintf(f, "%f %f %f - %d\n", nodalCurvature[6 * i + 0],
            nodalCurvature[6 * i + 1], nodalCurvature[6 * i + 2], i);
    fprintf(f, "%f %f %f\n", nodalCurvature[6 * i + 3],
            nodalCurvature[6 * i + 4], nodalCurvature[6 * i + 5]);
  }
  fclose(f);
}

static HXTStatus getAllFacesOfAllRegions(std::vector<GRegion *> &regions,
                                         HXTMesh *m,
                                         std::vector<GFace *> &allFaces)
{
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

static HXTStatus getAllEdgesOfAllFaces(std::vector<GFace *> &faces, HXTMesh *m,
                                       std::vector<GEdge *> &allEdges)
{
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

HXTStatus Gmsh2Hxt(std::vector<GFace *> &faces, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v, GModel *model=nullptr){
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t npts = 0;
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

  // Adds floating nodes (eg control nodes of NURBS) to the HXTMesh
  if(model){
    for(GVertex *gv : model->getVertices()){
      npts += gv->points.size();
      for(size_t i = 0; i < gv->points.size(); i++){
        MVertex *v = gv->points[i]->getVertex(0);
        all.insert(v);
      }
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

  if(model){
    m->points.num = m->points.size = npts;
    HXT_CHECK(hxtAlignedMalloc(&m->points.node, (m->points.num) * sizeof(uint32_t)));
    HXT_CHECK(hxtAlignedMalloc(&m->points.color,(m->points.num) * sizeof(uint32_t)));
    index = 0;
    for(GVertex *gv : model->getVertices()){
      for(size_t i = 0; i < gv->points.size(); i++){
        m->points.node[index] = v2c[gv->points[i]->getVertex(0)];
        m->points.color[index] = gv->tag();
        index++;
      }
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

/* ======================================================================================
   Functions from hxt_octree
   ======================================================================================
 */

static bool rtreeCallback(uint64_t id, void *ctx){
  std::vector<uint64_t> *vec = reinterpret_cast<std::vector<uint64_t> *>(ctx);
  vec->push_back(id);
  return true;
}

/* Create a p4est connectivity structure for the given bounding box. */
static p4est_connectivity_t *p8est_connectivity_new_cube(ForestOptions *forestOptions)
{
  const p4est_topidx_t num_vertices = 8;
  const p4est_topidx_t num_trees = 1;
  const p4est_topidx_t num_ett = 0;
  const p4est_topidx_t num_ctt = 0;

  double centreX = (forestOptions->bbox[0] + forestOptions->bbox[3]) / 2.0;
  double centreY = (forestOptions->bbox[1] + forestOptions->bbox[4]) / 2.0;
  double centreZ = (forestOptions->bbox[2] + forestOptions->bbox[5]) / 2.0;
  double cX = (forestOptions->bbox[3] - forestOptions->bbox[0]) / 2.0;
  double cY = (forestOptions->bbox[4] - forestOptions->bbox[1]) / 2.0;
  double cZ = (forestOptions->bbox[5] - forestOptions->bbox[2]) / 2.0;

  double scalingFactor =
    1.3; // The octree is this times bigger than the surface mesh's bounding box
  double c = scalingFactor * fmax(fmax(cX, cY), cZ);

  // TODO : Compute any bounding box, not necessarily aligned with the axes
  const double vertices[8 * 3] = {
    centreX - c, centreY - c, centreZ - c, centreX + c, centreY - c,
    centreZ - c, centreX - c, centreY + c, centreZ - c, centreX + c,
    centreY + c, centreZ - c, centreX - c, centreY - c, centreZ + c,
    centreX + c, centreY - c, centreZ + c, centreX - c, centreY + c,
    centreZ + c, centreX + c, centreY + c, centreZ + c,
  };
  const p4est_topidx_t tree_to_vertex[1 * 8] = {0, 1, 2, 3, 4, 5, 6, 7};
  const p4est_topidx_t tree_to_tree[1 * 6] = {0, 0, 0, 0, 0, 0};
  const int8_t tree_to_face[1 * 6] = {0, 1, 2, 3, 4, 5};

  return p4est_connectivity_new_copy(
    num_vertices, num_trees, 0, 0, vertices, tree_to_vertex, tree_to_tree,
    tree_to_face, NULL, &num_ett, NULL, NULL, NULL, &num_ctt, NULL, NULL);
}

static p4est_connectivity_t *p8est_connectivity_new_cube2D(ForestOptions *forestOptions)
{
  const p4est_topidx_t num_vertices = 8;
  const p4est_topidx_t num_trees = 1;
  const p4est_topidx_t num_ett = 0;
  const p4est_topidx_t num_ctt = 0;

  double centreX = (forestOptions->bbox[0] + forestOptions->bbox[3]) / 2.0;
  double centreY = (forestOptions->bbox[1] + forestOptions->bbox[4]) / 2.0;
  double centreZ = -ZPOS; // The 2D model is shifted by ZPOS in the z-coordinate
  double cX = (forestOptions->bbox[3] - forestOptions->bbox[0]) / 2.0;
  double cY = (forestOptions->bbox[4] - forestOptions->bbox[1]) / 2.0;
  double cZ = (forestOptions->bbox[5] - forestOptions->bbox[2]) / 2.0;

  double scalingFactor =
    1.3; // The octree is this times bigger than the surface mesh's bounding box
  double c = scalingFactor * fmax(fmax(cX, cY), cZ);

  // TODO : Compute any bounding box, not necessarily aligned with the axes
  const double vertices[8 * 3] = {
    centreX - c, centreY - c, centreZ - c, centreX + c, centreY - c,
    centreZ - c, centreX - c, centreY + c, centreZ - c, centreX + c,
    centreY + c, centreZ - c, centreX - c, centreY - c, centreZ + c,
    centreX + c, centreY - c, centreZ + c, centreX - c, centreY + c,
    centreZ + c, centreX + c, centreY + c, centreZ + c,
  };
  const p4est_topidx_t tree_to_vertex[1 * 8] = {0, 1, 2, 3, 4, 5, 6, 7};
  const p4est_topidx_t tree_to_tree[1 * 6] = {0, 0, 0, 0, 0, 0};
  const int8_t tree_to_face[1 * 6] = {0, 1, 2, 3, 4, 5};

  return p4est_connectivity_new_copy(
    num_vertices, num_trees, 0, 0, vertices, tree_to_vertex, tree_to_tree,
    tree_to_face, NULL, &num_ett, NULL, NULL, NULL, &num_ctt, NULL, NULL);
}

static p4est_connectivity_t *p8est_connectivity_new_square(ForestOptions *forestOptions)
{
  const p4est_topidx_t num_vertices = 8;
  const p4est_topidx_t num_trees = 1;
  const p4est_topidx_t num_ett = 0;
  const p4est_topidx_t num_ctt = 0;

  double centreX = (forestOptions->bbox[0] + forestOptions->bbox[3]) / 2.0;
  double centreY = (forestOptions->bbox[1] + forestOptions->bbox[4]) / 2.0;
  double cX = (forestOptions->bbox[3] - forestOptions->bbox[0]) / 2.0;
  double cY = (forestOptions->bbox[4] - forestOptions->bbox[1]) / 2.0;

  double scalingFactor = 1.3; // The octree is this times bigger than the surface mesh's bounding box
  double c = scalingFactor * fmax(cX, cY);

  // TODO : Compute any bounding box, not necessarily aligned with the axes
  const double vertices[8 * 3] = {
    centreX - c, centreY - c, 0.0, centreX + c, centreY - c, 0.0,
    centreX - c, centreY + c, 0.0, centreX + c, centreY + c, 0.0,
    centreX - c, centreY - c, 0.0, centreX + c, centreY - c, 0.0,
    centreX - c, centreY + c, 0.0, centreX + c, centreY + c, 0.0,
  };
  const p4est_topidx_t tree_to_vertex[1 * 8] = {0, 1, 2, 3, 4, 5, 6, 7};
  const p4est_topidx_t tree_to_tree[1 * 6] = {0, 0, 0, 0, 0, 0};
  const int8_t tree_to_face[1 * 6] = {0, 1, 2, 3, 4, 5};

  return p4est_connectivity_new_copy(
    num_vertices, num_trees, 0, 0, vertices, tree_to_vertex, tree_to_tree,
    tree_to_face, NULL, &num_ett, NULL, NULL, NULL, &num_ctt, NULL, NULL);
}
static inline double bulkSize(double x, double y, double z, double hBulk)
{
  return hBulk;
}

/* Fills xyz[] with the coordinates of the center of the given tree cell. */
static inline void getCellCenter(p4est_t *p4est, p4est_topidx_t which_tree,
                                 p4est_quadrant_t *q, double xyz[3])
{
  p4est_qcoord_t half_length = P4EST_QUADRANT_LEN(q->level) / 2;
  p4est_qcoord_to_vertex(p4est->connectivity, which_tree, q->x + half_length,
                         q->y + half_length, q->z + half_length, xyz);
}

/* Fills min[] & max[] with the coordinates of the cell viewed as a bounding
 * box. */
static inline void getCellBBox(p4est_t *p4est, p4est_topidx_t which_tree,
                               p4est_quadrant_t *q, double min[3],
                               double max[3])
{
  p4est_qcoord_t length = P4EST_QUADRANT_LEN(q->level);
  p4est_qcoord_to_vertex(p4est->connectivity, which_tree, q->x, q->y, q->z,
                         min);
  p4est_qcoord_to_vertex(p4est->connectivity, which_tree, q->x + length,
                         q->y + length, q->z + length, max);
}

/* Fills h with the dimension of the given cell (length of a cell edge). */
static void getCellSize(p4est_t *p4est, p4est_topidx_t which_tree,
                        p4est_quadrant_t *q, double *h)
{
  double min[3], max[3];
  p4est_qcoord_t length = P4EST_QUADRANT_LEN(q->level);
  p4est_qcoord_to_vertex(p4est->connectivity, which_tree, q->x, q->y, q->z,
                         min);
  p4est_qcoord_to_vertex(p4est->connectivity, which_tree, q->x + length,
                         q->y + length, q->z + length, max);
  // All cell edges are supposed to be the same length h (-:
  *h = fmax(max[0] - min[0], fmax(max[1] - min[1], max[2] - min[2]));
}

/* Callback used by p4est to initialize the user_data on each tree cell. */
static inline void initializeCell(p4est_t* p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions  *forestOptions = (ForestOptions *) p4est->user_pointer;
  size_data_t    *data = (size_data_t *) q->p.user_data;

  data = new size_data_t();

  double center[3];
  getCellCenter(p4est, which_tree, q, center);
  data->c[0] = center[0];
  data->c[1] = center[1];
  data->c[2] = center[2];
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
  // data->isPlanar = (fabs(data->c[2]) <= data->h/2. && data->c[2] >= 0.) ? true : false;
  data->isPlanar = ((data->c[2] - data->h/2. <= ZPOS) && (data->c[2] + data->h/2. >= ZPOS));
  data->isStillSmoothed = false;

  // // data->testMap = {{10, 0}, {3, 0}, {5, 0}, {2, 0}};
  // std::cout<< "Foo avant : "<<data->testMap.empty()<<std::endl;
  // // for(auto const& x : data->testMap){
  // //     std::cout << x.first  // string (key)
  // //               << ':' 
  // //               << x.second // string's value 
  // //               << std::endl;
  // // }
  // std::cout<< "Foo size : "<<data->testMap.size()<<std::endl;
  data->testMap[7] = 4;
  std::cout<<data->testMap[7]<<std::endl;
  // std::cout<< "Foo size : "<<data->testMap.max_size()<<std::endl;
  // // std::pair<std::map<int, int>::iterator,bool> res = data->testMap.insert(std::make_pair(10,4));
  // // std::cout<<res.second<<std::endl;
  // std::cout<< "Foo après : "<<data->testMap.empty()<<std::endl;
  // std::cout<< "Foo myMap : "<<data->myMap.empty()<<std::endl;
  // // data->myMap.insert({0,"allo"});
  // // std::cout<<data->myMap[0]<<std::endl;
  // // data->testMap = {};
  // // data->testMap[10] = 4;
  // // data->testMap[2] = 12;
  // // data->testMap[3] = 15;
  // // for(auto const& x : data->testMap){
  // //     std::cout << x.first  // string (key)
  // //               << ':' 
  // //               << x.second // string's value 
  // //               << std::endl;
  // // }
}

// /* Callback used by p4est to initialize the user_data on each tree cell. */
// static inline void initializeCell(p4est_t* p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
//   ForestOptions  *forestOptions = (ForestOptions *) p4est->user_pointer;
//   size_data_t    *data = (size_data_t *) q->p.user_data;

//   double center[3];
//   getCellCenter(p4est, which_tree, q, center);
//   double size[3];
//   size[0] = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
//   if(forestOptions->aniso){
//     size[1] = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
//     size[2] = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
//   }
//   std::map<int,int> testMap = {};
//   SMetric3 M = SMetric3(1. / (forestOptions->hbulk * forestOptions->hbulk));
//   double h;
//   getCellSize(p4est, which_tree, q, &h);
//   bool hasIntersection = false;
//   bool isPlanar = ((data->c[2] - data->h/2. <= ZPOS) && (data->c[2] + data->h/2. >= ZPOS)) ? true : false;

//   // size_data_t dataCpy = size_data_t{
//   //   {size[0],size[1],size[2]},
//   //   {0.,0.,0.,0.,0.,0.,0.,0.,0.},
//   //   {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.},
//   //   testMap,
//   //   M,           // Metric tensor
//   //   {0.,0.,0.,0.,0.,0.,0.,0.,0.},
//   //   h,            // Length of an octant's edge
//   //   {center[0],center[1],center[2]}, 
//   //   hasIntersection, // Has an intersection with the boundary mesh
//   //   isPlanar
//   // };

//   data->size = {size[0],size[1],size[2]};
//   data->dir = {0.,0.,0.,0.,0.,0.,0.,0.,0.};
//   data->dirCorner = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
//   data->testMap = testMap;
//   data->M = M;           // Metric tensor
//   data->ds = {0.,0.,0.,0.,0.,0.,0.,0.,0.};
//   data->h = h;            // Length of an octant's edge
//   data->c = {center[0],center[1],center[2]}; 
//   data->hasIntersection = hasIntersection; // Has an intersection with the boundary mesh
//   data->isPlanar = isPlanar;

//   std::cout<<data->isPlanar<<std::endl;
//   // data->testMap = {{10, 0}, {3, 0}, {5, 0}, {2, 0}};
//   data->testMap[10] = 4;
//   data->testMap[2] = 12;
//   data->testMap[3] = 15;
//   for(auto const& x : data->testMap){
//       std::cout << x.first  // string (key)
//                 << ':' 
//                 << x.second // string's value 
//                 << std::endl;
//   }
// }

/* Creates (allocates) the forestOptions structure. */
HXTStatus forestOptionsCreate(ForestOptions **forestOptions)
{
  HXT_CHECK(hxtAlignedMalloc(forestOptions, sizeof(ForestOptions)));
  if(*forestOptions == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  return HXT_STATUS_OK;
}

/* Destroys forestOptions. */
HXTStatus forestOptionsDelete(ForestOptions **forestOptions)
{
  HXT_CHECK(hxtFree(forestOptions));
  return HXT_STATUS_OK;
}

HXTStatus loadGlobalData(ForestOptions *forestOptions, const char *filename)
{
  FILE *f = fopen(filename, "r");
  if(f == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  char buf[BUFSIZ] = {""};
  if(fgets(buf, BUFSIZ, f) == NULL) {
    return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  }
  sscanf(buf, "%lf %lf", &forestOptions->hmin, &forestOptions->hmax);
  fclose(f);
  Msg::Info("Loaded global data from %s", filename);
  Msg::Info("Min size = %f", forestOptions->hmin);
  Msg::Info("Max size = %f", forestOptions->hmax);
  return HXT_STATUS_OK;
}

/* Creates a (sequential) forest structure by loading a p4est file. */
HXTStatus forestLoad(Forest **forest, const char *forestFile,
                     const char *dataFile, ForestOptions *forestOptions)
{
  if(forestFile == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  HXT_CHECK(hxtMalloc(forest, sizeof(Forest)));
  if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  HXT_CHECK(loadGlobalData(forestOptions, dataFile));

  p4est_connectivity_t *connect;
  sc_MPI_Comm mpicomm = sc_MPI_COMM_WORLD;
  int load_data = true;
  int autopartition = true;
  int broadcasthead = true;

  (*forest)->p4est = p4est_load_ext(forestFile, mpicomm, sizeof(size_data_t),
                                    load_data, autopartition, broadcasthead,
                                    (void *)forestOptions, &connect);
  (*forest)->forestOptions = forestOptions;

  if((*forest)->p4est == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  ForestOptions *fO = (ForestOptions *)(*forest)->p4est->user_pointer;
  if(fO == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  return HXT_STATUS_OK;
}

/* Creates a (sequential) forest structure from the forestOptions information.
   The forest is not refined; it consists of the root octant. */
HXTStatus forestCreate(int argc, char **argv, Forest **forest,
                       const char *filename, ForestOptions *forestOptions)
{
  HXT_CHECK(hxtMalloc(forest, sizeof(Forest)));
  if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  int mpiret;
  sc_MPI_Comm mpicomm;
  p4est_connectivity_t *connect;

  /* Initialize MPI; see sc_mpi.h.
   * If configure --enable-mpi is given these are true MPI calls.
   * Else these are dummy functions that simulate a single-processor run. */
  mpiret = sc_MPI_Init(&argc, &argv);
  SC_CHECK_MPI(mpiret);
  mpicomm = sc_MPI_COMM_WORLD;

  /* These functions are optional.  If called they store the MPI rank as a
   * static variable so subsequent global p4est log messages are only issued
   * from processor zero.  Here we turn off most of the logging; see sc.h. */
  // sc_init(mpicomm, 1, 1, NULL, SC_LP_ESSENTIAL);
  // p4est_init(NULL, SC_LP_PRODUCTION);

  /* Create a connectivity from the bounding box */
  if(forestOptions->dim == 3) {
    connect = p8est_connectivity_new_cube(forestOptions);
  }
  else {
    // connect = p8est_connectivity_new_square(forestOptions);
    connect = p8est_connectivity_new_cube2D(forestOptions);
  }

  if(connect == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  // #ifdef P4EST_WITH_METIS
  //   //  Use metis (if p4est is compiled with the flag '--with-metis') to
  //   //  * reorder the connectivity for better parititioning of the forest
  //   //  * across processors.
  //   p4est_connectivity_reorder(mpicomm, 0, conn, P4EST_CONNECT_FACE);
  // #endif /* P4EST_WITH_METIS */

  // Assign bulkSize callback if no sizeFunction is specified.
  if(forestOptions->sizeFunction == nullptr)
    forestOptions->sizeFunction = &bulkSize;

  std::cout << "SIZEOF = "<<sizeof(size_data_t)<<std::endl;

  (*forest)->p4est = p4est_new(mpicomm, connect, sizeof(size_data_t),
                               initializeCell, (void *)forestOptions);
  (*forest)->forestOptions = forestOptions;

  return HXT_STATUS_OK;
}

/* Deletes the forest structure. */
HXTStatus forestDelete(Forest **forest)
{
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
   ========================================================================================================
 */

/* Callback used by octreeRefineToBulkSize; returns 1 if the cells need
 * refinement, 0 otherwise. */
static inline int refineToBulkSizeCallback(p4est_t *p4est,
                                           p4est_topidx_t which_tree,
                                           p4est_quadrant_t *q)
{
  ForestOptions *forestOptions = (ForestOptions *)p4est->user_pointer;
  size_data_t *data = (size_data_t *)q->p.user_data;
  return data->h > forestOptions->hbulk;
}

/* Used by curvatureRefine; returns 1 if the cell should be
   refined according to the surface mesh curvature, 0 otherwise. */
static int curvatureRefineCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions *forestOptions = (ForestOptions *)p4est->user_pointer;
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
          kmax = fmax(kmax, forestOptions->nodalCurvature[node]);
          hf = fmin(hf, (*forestOptions->featureSizeAtVertices)[node]);
        }
      }
    }

    // There is curvature and/or feature size : the cell size should
    // accurately represent the surface and the feature size, so as not
    // propagate small feature size far from the feature.
    // Cell is refined according to the chosen density of nodes.
    double hc = 2*M_PI/(forestOptions->nodePerTwoPi * kmax);
    int factor = 1;

    if(h > fmax(forestOptions->hmin, fmin(hc, hf)*factor) && h >= forestOptions->hmin){
      return 1;
    } else{
      return 0;
    }
  } else{ // candidates.empty()
    return 0; // If the cell has no intersection with the surface mesh, it is not refined.
  }
}

static int coarsenCallback(p4est_t *p4est, p4est_topidx_t which_tree,
                           p4est_quadrant_t *children[])
{
  ForestOptions *forestOptions = (ForestOptions *)p4est->user_pointer;

  for(int n = 0; n < P4EST_CHILDREN; ++n) {
    size_data_t *data = (size_data_t *)children[n]->p.user_data;

    double min[3], max[3];
    getCellBBox(p4est, which_tree, children[n], min, max);

    std::vector<uint64_t> candidates;
    forestOptions->bndRTree->Search(min, max, rtreeCallback, &candidates);

    // Cells are not merged if any one of them touches the surface mesh.
    if(!candidates.empty()) return 0;
    // Cells are not merged if the resulting cell size is > than hbulk.
    if(2.0 * data->h > forestOptions->hbulk) return 0;
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
    for(auto const &bndElem : candidates){
      if(forestOptions->dim == 3){
        for(int i = 0; i < 3; ++i){
          int node = forestOptions->mesh2D->triangles.node[(size_t) 3*bndElem+i];
          double *v1 = forestOptions->nodalCurvature + 6*node;
          double *v2 = forestOptions->nodalCurvature + 6*node + 3;
          norme2(v1, &k1);
          norme2(v2, &k2);
          k1max = fmax(k1max, fmax(k1,k2));
          k2max = fmax(k2max, fmin(k1,k2)); // TODO : A verifier
          kmax  = fmax(kmax,  fmax(k1,k2));
          hf = fmin(hf, (*forestOptions->featureSizeAtVertices)[node]);
        }
      } else{ // dim = 2
        for(int i = 0; i < 2; ++i){
          int node = forestOptions->mesh2D->lines.node[(size_t) 2*bndElem+i];
          kmax = fmax(kmax, forestOptions->nodalCurvature[node]);
          hf = fmin(hf, (*forestOptions->featureSizeAtVertices)[node]);
        }
      }
    }

    if(!forestOptions->aniso){
      data->size[0] = fmax(forestOptions->hmin, fmin(forestOptions->hmax, fmin(hf, 2*M_PI/(forestOptions->nodePerTwoPi * kmax)) ));
    } else{
      if(forestOptions->dim == 3){
        data->size[0] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * k1max) ));
        data->size[1] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * k2max) ));
        data->size[2] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, hf ));
      } else{
        data->size[0] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * kmax) ));
        data->size[1] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, hf ));
        data->size[2] = NAN;
      }
    }
  }
  else{
    data->size[0] = fmax(forestOptions->hmin, fmin(forestOptions->hmax, data->size[0]));
    if(forestOptions->aniso){
      data->size[0] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[0] ));
      data->size[1] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[1] ));
      data->size[2] = fmax( forestOptions->hmin, fmin(forestOptions->hmax, data->size[2] ));
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
  if(forestOptions->dim == 2){
    data->size[2] = NAN;
    data->ds[2] = data->ds[5] = data->ds[6] = data->ds[7] = data->ds[8] = NAN;
  }
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
  ForestOptions          *forestOptions = (ForestOptions *) user_data;
  // Index of current face on the opposite cell (0 if current is 1 and vice versa).
  int                     iOpp;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  bool isPlanar = false;
  for(int i = 0; i < sides->elem_count; i++){
    if(side[i]->is_hanging){
      for(int j = 0; j < P4EST_HALF; ++j){
        data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
        isPlanar = isPlanar || data->isPlanar;
      }
    } else{
      data = (size_data_t *) side[i]->is.full.quad->p.user_data;
      isPlanar = isPlanar || data->isPlanar;
    }
  }

  if(isPlanar){
  for(int k = 0; k < forestOptions->dim; ++k){
    if(sides->elem_count == 2){
      for(int i = 0; i < 2; i++){
        iOpp = 1 - i;
        which_face_opp = side[iOpp]->face; /* 0,1 == -+x, 2,3 == -+y, 4,5 == -+z */
        if(which_face_opp == 4 || which_face_opp == 5){
          continue;
        }

        // Current cells are hanging
        if(side[i]->is_hanging){
          data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
          if(data_opp->isPlanar){
            SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]); // Unit directions of the opposite cells
            double he_avg = 0.; // Average sizes on the current cells based on neighboring directions
            double foo = 0.;
            int nPlanar = 0;
            for(int j = 0; j < P4EST_HALF; ++j){
              data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
              if(data->isPlanar){
                ++nPlanar;
                he_avg += 1.0/sqrt(dot(e_opp, data->M, e_opp)); // Length along these directions based on the current cell's metric
                foo    += dot(e_opp, data->M, e_opp);
              }
            }
            // he_avg /= P4EST_HALF;
            he_avg /= nPlanar;
            // foo /= P4EST_HALF;
            foo /= nPlanar;
            he_avg = 1./sqrt(foo);

            switch(which_face_opp){
              case 0 : data_opp->ds[3*k+0] -= 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 1 : data_opp->ds[3*k+0] += 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 2 : data_opp->ds[3*k+1] -= 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 3 : data_opp->ds[3*k+1] += 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 4 : data_opp->ds[3*k+2] -= 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
              case 5 : data_opp->ds[3*k+2] += 0.5 * (he_avg - data_opp->size[k])/(data_opp->h/2. + data->h/2.); break;
            }
          }
        } else{ // Current cell is full
          data = (size_data_t *) side[i]->is.full.quad->p.user_data;
          if(data->isPlanar){
            if(side[iOpp]->is_hanging){
              // Msg::Error("Not full-full\n");
              // Msg::Exit(1);
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
                if(data_opp->isPlanar){
                  // Unit directions of the opposite cells
                  SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);
                  // Length along this direction based on the current cell's metric
                  double he = 1.0/sqrt(dot(e_opp, data->M, e_opp));

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
            else{
              // Current full - Opposite full
              data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
              if(data_opp->isPlanar){
                SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]); // The unit direction of the opposite cell associated to size[k]
                double he = 1.0/sqrt(dot(e_opp, data->M, e_opp)); // The length along this direction based on the current cell's metric

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
          } // isPlanar
        }
      }
    }
  }
  }
  // Nothing to do on the boundaries (0 flux)
}

// static void computeGradientCenterAniso(p4est_iter_face_info_t * info, void *user_data){
//   p4est_iter_face_side_t *side[2];
//   sc_array_t             *sides = &(info->sides);
//   size_data_t            *data, *data_opp;
//   int                     which_face;
//   ForestOptions          *forestOptions = (ForestOptions *) user_data;
//   int                     iOpp;

//   side[0] = p4est_iter_fside_array_index_int (sides, 0);
//   side[1] = p4est_iter_fside_array_index_int (sides, 1);

//   bool isPlanar = false;
//   for(int i = 0; i < sides->elem_count; i++){
//     if(side[i]->is_hanging){
//       for(int j = 0; j < P4EST_HALF; ++j){
//         data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
//         isPlanar = isPlanar || data->isPlanar;
//       }
//     } else{
//       data = (size_data_t *) side[i]->is.full.quad->p.user_data;
//       isPlanar = isPlanar || data->isPlanar;
//     }
//   }

//   if(isPlanar){
//     for(int k = 0; k < forestOptions->dim; ++k){
//       if(sides->elem_count == 2){
//         for(int i = 0; i < 2; i++){
//           iOpp = 1 - i;
//           which_face = side[i]->face; /* 0,1 == -+x, 2,3 == -+y, 4,5 == -+z */
//           if(which_face == 4 || which_face == 5){
//             continue;
//           }

//           // Current cells are hanging
//           if(side[i]->is_hanging){
//             data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
//             if(data_opp->isPlanar){
//               for(int j = 0; j < P4EST_HALF; ++j){
//                 data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
//                 if(data->isPlanar){
//                   SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]); // Unit directions of the opposite cells
//                   double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
//                   switch(which_face){
//                     case 0 : data->ds[3*k+0] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 1 : data->ds[3*k+0] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 2 : data->ds[3*k+1] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 3 : data->ds[3*k+1] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 4 : data->ds[3*k+2] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 5 : data->ds[3*k+2] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                   }
//                 }
//               }
//             }
//           } else{ // Current cell is full
//             data = (size_data_t *) side[i]->is.full.quad->p.user_data;
//             if(data->isPlanar){
//               SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
//               if(side[iOpp]->is_hanging){

//                 double he_opp_avg = 0.;
//                 int nPlanar = 0;
//                 for(int j = 0; j < P4EST_HALF; ++j){
//                   data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
//                   if(data_opp->isPlanar){
//                     // he_opp_avg += 1.0/sqrt(dot(e, data_opp->M, e));
//                     he_opp_avg += dot(e, data_opp->M, e);
//                   }
//                 }
//                 he_opp_avg /= nPlanar;
//                 he_opp_avg = 1./sqrt(he_opp_avg);

//                 switch(which_face){
//                   case 0 : data->ds[3*k+0] -= 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                   case 1 : data->ds[3*k+0] += 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                   case 2 : data->ds[3*k+1] -= 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                   case 3 : data->ds[3*k+1] += 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                   case 4 : data->ds[3*k+2] -= 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                   case 5 : data->ds[3*k+2] += 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                 }

//               } else{
//                 // Current full - Opposite full
//                 data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
//                 if(data_opp->isPlanar){
//                   double he_opp = 1.0/sqrt(dot(e, data_opp->M, e)); // The length along this direction based on the current cell's metric
//                   switch(which_face){
//                     case 0 : data->ds[3*k+0] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 1 : data->ds[3*k+0] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 2 : data->ds[3*k+1] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 3 : data->ds[3*k+1] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 4 : data->ds[3*k+2] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                     case 5 : data->ds[3*k+2] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.); break;
//                   }
//                 }
//               }
//             } // isPlanar
//           }
//         }
//       }
//     }
//   }
//   // Nothing to do on the boundaries (0 flux)
// }

static void toutEnUn(p4est_iter_face_info_t * info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t             *sides = &(info->sides);
  size_data_t            *data, *data_opp;
  int                     which_face;
  ForestOptions          *forestOptions = (ForestOptions *) user_data;
  int                     iOpp;
  double                  alpha = forestOptions->gradation - 1.0;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  bool isPlanar = false;
  for(int i = 0; i < sides->elem_count; i++){
    if(side[i]->is_hanging){
      for(int j = 0; j < P4EST_HALF; ++j){
        data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
        isPlanar = isPlanar || data->isPlanar;
      }
    } else{
      data = (size_data_t *) side[i]->is.full.quad->p.user_data;
      isPlanar = isPlanar || data->isPlanar;
    }
  }

  if(isPlanar){
    // for(int k = 0; k < forestOptions->dim; ++k){
      if(sides->elem_count == 2){
        for(int i = 0; i < 2; i++){
          iOpp = 1 - i;
          which_face = side[i]->face; /* 0,1 == -+x, 2,3 == -+y, 4,5 == -+z */
          if(which_face == 4 || which_face == 5){
            continue;
          }

          // Current cells are hanging
          if(side[i]->is_hanging){
            // Msg::Error("Foo\n");
            p4est_quadrant_t *q_opp = side[iOpp]->is.full.quad;
            data_opp = (size_data_t *) q_opp->p.user_data;
            if(data_opp->isPlanar){
              for(int j = 0; j < P4EST_HALF; ++j){
                p4est_quadrant_t *q = side[i]->is.hanging.quad[j];
                data = (size_data_t *) q->p.user_data;
                if(data->isPlanar){
                  switch(which_face){
                    case 0 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+0] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+0]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                          ++modifiedCells;
                        }
                      }
                      break;
                    case 1 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+0] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+0]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                           ++modifiedCells;
                        }
                      }
                      break;
                    case 2 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+1] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+1]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                           ++modifiedCells;
                        }
                      }
                      break;
                    case 3 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+1] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+1]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                           ++modifiedCells;
                        }
                      }
                      break;
                    case 4 : 
                      // data->ds[3*k+2] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                      break;
                    case 5 : 
                      // data->ds[3*k+2] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                      break;
                  }
                }
              }
            }
          } else{ // Current cell is full
            p4est_quadrant_t *q = side[i]->is.full.quad;
            data = (size_data_t *) q->p.user_data;
            if(data->isPlanar){
    
              if(side[iOpp]->is_hanging){

                // Msg::Error("Foo\n");

                // double he_opp_avg = 0.;
                // int nPlanar = 0;
                for(int j = 0; j < P4EST_HALF; ++j){
                  p4est_quadrant_t *q_opp = side[iOpp]->is.hanging.quad[j];
                  data_opp = (size_data_t *) q_opp->p.user_data;
                  if(data_opp->isPlanar){
                //     // he_opp_avg += 1.0/sqrt(dot(e, data_opp->M, e));
                //     he_opp_avg += dot(e, data_opp->M, e);
                    switch(which_face){
                      case 0 : 
                        for(int k = 0; k < forestOptions->dim; ++k){
                          SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                          // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                          int closestDir = closestDirs[q][q_opp][k];
                          double he_opp = data_opp->size[closestDir];
                          data->ds[3*k+0] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                          if(fabs(data->ds[3*k+0]) > alpha){
                            if(data->size[k] > he_opp){
                              data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                            } else{
                              int closestDir = closestDirs[q][q_opp][k];
                              data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                            }
                            ++modifiedCells;
                          }
                        }
                        break;
                      case 1 : 
                        for(int k = 0; k < forestOptions->dim; ++k){
                          SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                          // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                          int closestDir = closestDirs[q][q_opp][k];
                          double he_opp = data_opp->size[closestDir];
                          data->ds[3*k+0] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                          if(fabs(data->ds[3*k+0]) > alpha){
                            if(data->size[k] > he_opp){
                              data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                            } else{
                              int closestDir = closestDirs[q][q_opp][k];
                              data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                            }
                             ++modifiedCells;
                          }
                        }
                        break;
                      case 2 : 
                        for(int k = 0; k < forestOptions->dim; ++k){
                          SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                          // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                          int closestDir = closestDirs[q][q_opp][k];
                          double he_opp = data_opp->size[closestDir];
                          data->ds[3*k+1] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                          if(fabs(data->ds[3*k+1]) > alpha){
                            if(data->size[k] > he_opp){
                              data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                            } else{
                              int closestDir = closestDirs[q][q_opp][k];
                              data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                            }
                             ++modifiedCells;
                          }
                        }
                        break;
                      case 3 : 
                        for(int k = 0; k < forestOptions->dim; ++k){
                          SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                          // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                          int closestDir = closestDirs[q][q_opp][k];
                          double he_opp = data_opp->size[closestDir];
                          data->ds[3*k+1] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                          if(fabs(data->ds[3*k+1]) > alpha){
                            if(data->size[k] > he_opp){
                              data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                            } else{
                              int closestDir = closestDirs[q][q_opp][k];
                              data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                            }
                             ++modifiedCells;
                          }
                        }
                        break;
                      case 4 : 
                        // data->ds[3*k+2] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        break;
                      case 5 : 
                        // data->ds[3*k+2] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        break;
                    }
                  }
                }
                // he_opp_avg /= nPlanar;
                // he_opp_avg = 1./sqrt(he_opp_avg);

                // switch(which_face){
                //   case 0 : data->ds[3*k+0] -= 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
                //   case 1 : data->ds[3*k+0] += 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
                //   case 2 : data->ds[3*k+1] -= 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
                //   case 3 : data->ds[3*k+1] += 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
                //   case 4 : data->ds[3*k+2] -= 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
                //   case 5 : data->ds[3*k+2] += 0.5 * (he_opp_avg - data->size[k])/(data_opp->h/2. + data->h/2.); break;
                // }

              } else{
                // Current full - Opposite full
                p4est_quadrant_t *q_opp = side[iOpp]->is.full.quad;
                data_opp = (size_data_t *) q_opp->p.user_data;
                if(data_opp->isPlanar){
                  
                  switch(which_face){
                    case 0 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+0] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+0]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                          ++modifiedCells;
                        }
                      }
                      break;
                    case 1 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+0] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+0]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                           ++modifiedCells;
                        }
                      }
                      break;
                    case 2 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+1] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+1]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                           ++modifiedCells;
                        }
                      }
                      break;
                    case 3 : 
                      for(int k = 0; k < forestOptions->dim; ++k){
                        SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                        // double he_opp = 1.0/sqrt(dot(e, data_opp->M, e));
                        int closestDir = closestDirs[q][q_opp][k];
                        double he_opp = data_opp->size[closestDir];
                        data->ds[3*k+1] = (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                        if(fabs(data->ds[3*k+1]) > alpha){
                          if(data->size[k] > he_opp){
                            data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                          } else{
                            int closestDir = closestDirs[q][q_opp][k];
                            data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha * (data_opp->h/2. + data->h/2.));
                          }
                           ++modifiedCells;
                        }
                      }
                      break;
                    case 4 : 
                      // data->ds[3*k+2] -= 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                      break;
                    case 5 : 
                      // data->ds[3*k+2] += 0.5 * (he_opp - data->size[k])/(data_opp->h/2. + data->h/2.);
                      break;
                  }
                }
              } // else
            } // isPlanar
          }
        }
      }
    // }
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

static inline void getMaxGradient(p4est_iter_volume_info_t *info, void *user_data){
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double           *gradMax = static_cast<double*>(user_data);
  for(int i = 0; i < 3; ++i)
    gradMax[i] = SC_MAX (fabs(data->ds[i]), gradMax[i]);
}

static inline void getMaxGradientAniso2D(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  if(data->isPlanar){
    double           *gradMax = static_cast<double*>(user_data);
    for(int i = 0; i < 5; ++i){
      if(i != 2){
        gradMax[i] = SC_MAX (fabs(data->ds[i]), gradMax[i]);
      }
    }
  }
}

static inline void getMaxGradientAniso3D(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double           *gradMax = static_cast<double*>(user_data);
  for(int i = 0; i < 9; ++i){
    gradMax[i] = SC_MAX (fabs(data->ds[i]), gradMax[i]);
  }
}

static inline void getMinSize(p4est_iter_volume_info_t *info, void *user_data){
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double* minsize = (double*) user_data;
  *minsize = fmin(*minsize, data->size[0]);
}

HXTStatus forestGetMaxGradient(Forest *forest, double *gradMax){
  if(forest->forestOptions->aniso){
    if(forest->forestOptions->dim == 2){ p4est_iterate (forest->p4est, NULL, (void *) gradMax, getMaxGradientAniso2D, NULL, NULL, NULL); }
    if(forest->forestOptions->dim == 3){ p4est_iterate (forest->p4est, NULL, (void *) gradMax, getMaxGradientAniso3D, NULL, NULL, NULL); }
  } else{
    p4est_iterate (forest->p4est, NULL, (void *) gradMax, getMaxGradient, NULL, NULL, NULL);
  }
  return HXT_STATUS_OK;
}

HXTStatus forestGetMinSize(Forest *forest, double *minsize){
  double minSize = 1e22;
  p4est_iterate(forest->p4est, NULL, (void *)&minSize, getMinSize, NULL, NULL,
                NULL);
  *minsize = minSize;
  return HXT_STATUS_OK;
}

static void limitSize(p4est_iter_face_info_t *info, void *user_data){
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

      if(side[i]->is_hanging) {
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

static void setClosestDirections(p4est_iter_face_info_t * info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t             *sides = &(info->sides);
  size_data_t            *data;
  size_data_t            *data_opp;
  int                     which_dir;
  int                     iOpp;
  ForestOptions          *forestOptions = (ForestOptions*) user_data;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  bool isPlanar = false;
  for(int i = 0; i < sides->elem_count; i++){
    if(side[i]->is_hanging){
      for(int j = 0; j < P4EST_HALF; ++j){
        data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
        isPlanar = isPlanar || data->isPlanar;
      }
    } else{
      data = (size_data_t *) side[i]->is.full.quad->p.user_data;
      isPlanar = isPlanar || data->isPlanar;
    }
  }

  if(isPlanar){
    if(sides->elem_count==2){
      for(int i = 0; i < 2; ++i){
        iOpp = 1 - i;
        which_dir = side[i]->face / 2; // Direction x(0), y(1) ou z(2)
        if(which_dir == 2){
          continue;
        }

        if(side[i]->is_hanging){
          // Current hanging - Opposes full
          p4est_quadrant_t *q_opp = side[iOpp]->is.full.quad;
          data_opp = (size_data_t *) q_opp->p.user_data;
          if(data_opp->isPlanar){

            for(int j = 0; j < P4EST_HALF; ++j){
              p4est_quadrant_t *q = side[i]->is.hanging.quad[j];
              data = (size_data_t *) q->p.user_data;
              if(data->isPlanar){

                std::vector<int> tmp{-1,-1,2}; // In 2D the z-directions are identical
                for(int k = 0; k < forestOptions->dim; ++k){
                  SVector3 e(data->dir[3*k+0],data->dir[3*k+1],data->dir[3*k+2]);
                  if(fabs(e.norm()-1.) > 1e-6){ Msg::Error("e non unitaire : %4.10e\n", e.norm()); }

                  // Identifying closest directions on the current cell
                  double dotMax = -1.0, dotProd;
                  for(int ii = 0; ii < forestOptions->dim; ++ii){
                    SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                    if(fabs(e_opp_ii.norm()-1.) > 1e-6){ Msg::Error("e_opp_ii non unitaire : %4.10e\n", e_opp_ii.norm()); }
                    dotProd = fabs(dot(e, e_opp_ii));
                    if(dotProd > dotMax && tmp[k] != ii){
                      dotMax = fmax(dotMax, dotProd);
                      tmp[k] = ii;
                    }
                  }
                  if(dotMax < sqrt(2)/2.-1e-6){
                    e.print();
                    SVector3 foo0(data_opp->dir[3*0+0], data_opp->dir[3*0+1], data_opp->dir[3*0+2]); foo0.print();
                    SVector3 foo1(data_opp->dir[3*1+0], data_opp->dir[3*1+1], data_opp->dir[3*1+2]); foo1.print();
                    SVector3 foo2(data_opp->dir[3*2+0], data_opp->dir[3*2+1], data_opp->dir[3*2+2]); foo2.print();
                    Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, tmp[k]);
                  }
                } // for each direction k

                closestDirs[q].insert(std::make_pair(q_opp,tmp));
                // for (auto cD : tmp) std::cout << cD << ' ';
                // std::cout<<std::endl;
                // data->closestDir[q_opp] = tmp;

              } // isPlanar
            } // for j hanging
          } // isPlanar
        } // if hanging
        else{
          p4est_quadrant_t *q = side[i]->is.full.quad;
          data = (size_data_t *) q->p.user_data;
          if(data->isPlanar){

            if(side[iOpp]->is_hanging){
              // Current full - Opposite hanging
              for(int j = 0; j < P4EST_HALF; ++j){
                p4est_quadrant_t *q_opp = side[iOpp]->is.hanging.quad[j];
                data_opp = (size_data_t *) q_opp->p.user_data;
                if(data_opp->isPlanar){

                  std::vector<int> tmp{-1,-1,2};
                  for(int k = 0; k < forestOptions->dim; ++k){
                    SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                    if(fabs(e.norm()-1.) > 1e-6){ Msg::Error("e non unitaire : %4.10e\n", e.norm()); }

                    double dotMax = -1.0, dotProd;
                    for(int ii = 0; ii < forestOptions->dim; ++ii){
                      SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                      if(fabs(e_opp_ii.norm()-1.) > 1e-6){ Msg::Error("e_opp_ii non unitaire : %4.10e\n", e_opp_ii.norm()); }
                      dotProd = fabs(dot(e, e_opp_ii));
                      if(dotProd > dotMax && tmp[k] != ii){
                        dotMax = fmax(dotMax, dotProd);
                        tmp[k] = ii;
                      }
                    }
                    if(dotMax < sqrt(2)/2.-1e-6){
                      e.print();
                      SVector3 foo0(data_opp->dir[3*0+0], data_opp->dir[3*0+1], data_opp->dir[3*0+2]); foo0.print();
                      SVector3 foo1(data_opp->dir[3*1+0], data_opp->dir[3*1+1], data_opp->dir[3*1+2]); foo1.print();
                      SVector3 foo2(data_opp->dir[3*2+0], data_opp->dir[3*2+1], data_opp->dir[3*2+2]); foo2.print();
                      Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, tmp[k]);
                    }
                  } // for each direction k

                  closestDirs[q].insert(std::make_pair(q_opp,tmp));
                  // for (auto cD : tmp) std::cout << "foo" << cD << ' ';
                  // std::cout<<std::endl;
                  // data->closestDir[q_opp].push_back(tmp[0]);
                  // data->closestDir[q_opp].push_back(tmp[1]);
                  // data->closestDir[q_opp].push_back(tmp[2]);
                  // Msg::Info("Foo : %d - %d - %d\n", data->closestDir[q_opp][0],data->closestDir[q_opp][1],data->closestDir[q_opp][2]);

                } // isPlanar
              }
            } else{
              // Current full - Oppose full
              p4est_quadrant_t *q_opp = side[iOpp]->is.full.quad;
              data_opp = (size_data_t *) q_opp->p.user_data;
              if(data_opp->isPlanar){

                std::vector<int> tmp{-1,-1,2};
                for(int k = 0; k < forestOptions->dim; ++k){
                  SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                  if(fabs(e.norm()-1.) > 1e-6){ Msg::Error("e non unitaire : %4.10e\n", e.norm()); }

                  double dotMax = -1.0, dotProd;
                  for(int ii = 0; ii < forestOptions->dim; ++ii){
                    SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                    if(fabs(e_opp_ii.norm()-1.) > 1e-6){
                      Msg::Error("e_opp_ii non unitaire : %4.10e\n", e_opp_ii.norm());
                    }
                    dotProd = fabs(dot(e, e_opp_ii));
                    if(dotProd > dotMax && tmp[k] != ii){
                      dotMax = fmax(dotMax, dotProd);
                      tmp[k] = ii;
                    }
                  }
                  if(dotMax < sqrt(2)/2.-1e-6){
                    e.print();
                    SVector3 foo0(data_opp->dir[3*0+0], data_opp->dir[3*0+1], data_opp->dir[3*0+2]); foo0.print();
                    SVector3 foo1(data_opp->dir[3*1+0], data_opp->dir[3*1+1], data_opp->dir[3*1+2]); foo1.print();
                    SVector3 foo2(data_opp->dir[3*2+0], data_opp->dir[3*2+1], data_opp->dir[3*2+2]); foo2.print();
                    Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, tmp[k]);
                  }
                } // for each direction k

                closestDirs[q].insert(std::make_pair(q_opp,tmp));
                // int tmpArray[3] = {tmp[0], tmp[1], tmp[2]};
                // for (auto cD : tmp) std::cout << cD << ' ';
                // std::cout<<std::endl;
                // data->closestDir[q_opp] = tmp;
                // std::cout<<q_opp<<std::endl;
                // data->testMap[10] = 4;
                // data->testMap[2] = 12;
                // data->testMap[3] = 15;
                // for(auto const& x : data->testMap){
                //     std::cout << x.first  // string (key)
                //               << ':' 
                //               << x.second // string's value 
                //               << std::endl;
                // }
                // data->closestDirArray[q_opp] = tmpArray[0];
                // data->closestDir.insert(std::make_pair(q_opp,tmp));
                // data->closestDir[q_opp].push_back(tmp[1]);
                // data->closestDir[q_opp].push_back(tmp[2]);
                // Msg::Info("Foo : %d - %d - %d\n", data->closestDirArray[q_opp][0],data->closestDirArray[q_opp][1],data->closestDirArray[q_opp][2]);
                // Msg::Info("Foo : %d\n", data->closestDirArray[q_opp]);

              } // isPlanar
            } // isFull
          } // isPlanar
        }
      }
    }
  }
}

static void limitSizeAniso(p4est_iter_face_info_t * info, void *user_data){
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

  bool isPlanar = false;
  for(int i = 0; i < sides->elem_count; i++){
    if(side[i]->is_hanging){
      for(int j = 0; j < P4EST_HALF; ++j){
        data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
        isPlanar = isPlanar || data->isPlanar;
      }
    } else{
      data = (size_data_t *) side[i]->is.full.quad->p.user_data;
      isPlanar = isPlanar || data->isPlanar;
    }
  }

  if(isPlanar){
  if(sides->elem_count==2){
    for(int k = 0; k < forestOptions->dim; ++k){
      for(int i = 0; i < 2; ++i){
        iOpp = 1 - i;
        which_dir = side[i]->face / 2; // Direction x(0), y(1) ou z(2)
        if(which_dir == 2){
          continue;
        }

        if(side[i]->is_hanging){
          // Current hanging - Opposes full
          p4est_quadrant_t *q_opp = side[iOpp]->is.full.quad;
          data_opp = (size_data_t *) q_opp->p.user_data;
          if(data_opp->isPlanar){
            SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);
            if(fabs(e_opp.norm()-1.) > 1e-6){
              Msg::Error("e_opp non unitaire : %4.10e\n", e_opp.norm());
            }

            for(int j = 0; j < P4EST_HALF; ++j){
              p4est_quadrant_t *q = side[i]->is.hanging.quad[j];
              data = (size_data_t *) q->p.user_data;
              if(data->isPlanar){
                SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
                if(fabs(e.norm()-1.) > 1e-6){
                  Msg::Error("e non unitaire : %4.10e\n", e.norm());
                }
                double he = 1.0/sqrt(dot(e_opp, data->M, e_opp)); // Size of opposite directions in current metric
                double he_opp = 1.0/sqrt(dot(e, data_opp->M, e)); // Size of current directions in opposite metric

                if(fabs(data->ds[3*k+which_dir]) > alpha){

                  if(data->size[k] > he_opp){
                    data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                    ++modifiedCells;
                    data->isStillSmoothed = true;
                  }
                  else if(data_opp->size[k] > he){
                    data_opp->size[k] = fmin(data_opp->size[k], he + alpha * (data_opp->h/2. + data->h/2.));
                    ++modifiedCells;
                    data->isStillSmoothed = true;
                  }
                  // Gradient is too large but no size is greater than its projection
                  else if(data->size[k] < he_opp){
                    double dotMax = -1.0, dotProd;
                    int closestDir = -1;
                    for(int ii = 0; ii < forestOptions->dim; ++ii){
                      SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                      if(fabs(e_opp_ii.norm()-1.) > 1e-6){
                        Msg::Error("e_opp_ii non unitaire : %4.10e\n", e_opp_ii.norm());
                      }
                      dotProd = fabs(dot(e, e_opp_ii));
                      if(dotProd > dotMax){
                        dotMax = fmax(dotMax, dotProd);
                        closestDir = ii;
                      }
                    }
                    if(dotMax < sqrt(2)/2.-1e-6){
                      e.print();
                      SVector3 foo0(data_opp->dir[3*0+0], data_opp->dir[3*0+1], data_opp->dir[3*0+2]); foo0.print();
                      SVector3 foo1(data_opp->dir[3*1+0], data_opp->dir[3*1+1], data_opp->dir[3*1+2]); foo1.print();
                      SVector3 foo2(data_opp->dir[3*2+0], data_opp->dir[3*2+1], data_opp->dir[3*2+2]); foo2.print();
                      Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, closestDir);
                    }
                    if(closestDir != closestDirs[q][q_opp][k]) Msg::Error("Mismatch 1\n");
                    if(closestDir >= 0){
                      data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                      ++modifiedCells;
                      data->isStillSmoothed = true;
                    }
                  }
                  else if(data_opp->size[k] < he){
                    double dotMax = -1.0, dotProd;
                    int closestDir;
                    for(int ii = 0; ii < forestOptions->dim; ++ii){
                      SVector3 e_ii(data->dir[3*ii+0], data->dir[3*ii+1], data->dir[3*ii+2]);
                      if(fabs(e_ii.norm()-1.) > 1e-6){
                        Msg::Error("e_ii non unitaire : %4.10e\n", e_ii.norm());
                      }
                      dotProd = fabs(dot(e_ii, e_opp));
                      if(dotProd > dotMax){
                        dotMax = fmax(dotMax, dotProd);
                        closestDir = ii;
                      }
                    }
                    if(dotMax < sqrt(2)/2.-1e-6){
                      e_opp.print();
                      SVector3 foo0(data->dir[3*0+0], data->dir[3*0+1], data->dir[3*0+2]); foo0.print();
                      SVector3 foo1(data->dir[3*1+0], data->dir[3*1+1], data->dir[3*1+2]); foo1.print();
                      SVector3 foo2(data->dir[3*2+0], data->dir[3*2+1], data->dir[3*2+2]); foo2.print();
                      Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, closestDir);
                    }
                    // int closestDir = closestDirs[q][q_opp][k];
                    if(closestDir != closestDirs[q][q_opp][k]) Msg::Error("Mismatch 2\n");
                    if(closestDir >= 0){
                      data->size[closestDir] = fmin(data->size[closestDir], data_opp->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                      ++modifiedCells;
                      data->isStillSmoothed = true;
                    }
                  } else{
                    Msg::Info("Autre\n");
                  }
                } // if ds > alpha-1
              } // isPlanar
            } // for j hanging
          } // isPlanar
        } // if hanging
        else{
          p4est_quadrant_t *q = side[i]->is.full.quad;
          data = (size_data_t *) q->p.user_data;
          if(data->isPlanar){
            SVector3 e(data->dir[3*k+0], data->dir[3*k+1], data->dir[3*k+2]);
            if(fabs(e.norm()-1.) > 1e-6){
              Msg::Error("e non unitaire : %4.10e\n", e.norm());
            }

            if(fabs(data->ds[3*k+which_dir]) > alpha){
              if(side[iOpp]->is_hanging){
                // Msg::Error("Full-Hanging (2)\n");
                // Msg::Exit(1);
                // Current full - Oppose hanging
                for(int j = 0; j < P4EST_HALF; ++j){
                  p4est_quadrant_t *q_opp = side[iOpp]->is.hanging.quad[j];
                  data_opp = (size_data_t *) q_opp->p.user_data;
                  if(data_opp->isPlanar){
                    SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);
                    if(fabs(e_opp.norm()-1.) > 1e-6){
                      Msg::Error("e_opp non unitaire : %4.10e\n", e_opp.norm());
                    }
                    double he = 1.0/sqrt(dot(e_opp, data->M, e_opp)); // Size of opposite directions in current metric
                    double he_opp = 1.0/sqrt(dot(e, data_opp->M, e)); // Size of current directions in opposite metric

                    // Msg::Info("Current full - Oppose hanging : j = %d - he = %4.4e - he_opp = %4.4e\n", j, he, he_opp);

                    if(data->size[k] > he_opp){
                      data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                      ++modifiedCells;
                      data->isStillSmoothed = true;
                    }
                    else if(data_opp->size[k] > he){
                      data_opp->size[k] = fmin(data_opp->size[k], he + alpha * (data_opp->h/2. + data->h/2.));
                      ++modifiedCells;
                      data->isStillSmoothed = true;
                    } // Gradient is too large but no size is greater than its projection
                    else if(data->size[k] < he_opp){
                      double dotMax = -1.0, dotProd;
                      int closestDir;
                      for(int ii = 0; ii < forestOptions->dim; ++ii){
                        SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                        if(fabs(e_opp_ii.norm()-1.) > 1e-6){
                          Msg::Error("e_opp_ii non unitaire : %4.10e\n", e_opp_ii.norm());
                        }
                        dotProd = fabs(dot(e, e_opp_ii));
                        if(dotProd > dotMax){
                          dotMax = fmax(dotMax, dotProd);
                          closestDir = ii;
                        }
                      }
                      if(dotMax < sqrt(2)/2.-1e-6){
                        e.print();
                        SVector3 foo0(data_opp->dir[3*0+0], data_opp->dir[3*0+1], data_opp->dir[3*0+2]); foo0.print();
                        SVector3 foo1(data_opp->dir[3*1+0], data_opp->dir[3*1+1], data_opp->dir[3*1+2]); foo1.print();
                        SVector3 foo2(data_opp->dir[3*2+0], data_opp->dir[3*2+1], data_opp->dir[3*2+2]); foo2.print();
                        Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, closestDir);
                      }
                      if(closestDir != closestDirs[q][q_opp][k]) Msg::Error("Mismatch 1\n");
                      if(closestDir >= 0){
                        data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                        ++modifiedCells;
                        data->isStillSmoothed = true;
                      }
                    }
                    else if(data_opp->size[k] < he){
                      double dotMax = -1.0, dotProd;
                      int closestDir;
                      for(int ii = 0; ii < forestOptions->dim; ++ii){
                        SVector3 e_ii(data->dir[3*ii+0], data->dir[3*ii+1], data->dir[3*ii+2]);
                        if(fabs(e_ii.norm()-1.) > 1e-6){
                          Msg::Error("e_ii non unitaire : %4.10e\n", e_ii.norm());
                        }
                        dotProd = fabs(dot(e_ii, e_opp));
                        if(dotProd > dotMax){
                          dotMax = fmax(dotMax, dotProd);
                          closestDir = ii;
                        }
                      }
                      if(dotMax < sqrt(2)/2.-1e-6){
                        e_opp.print();
                        SVector3 foo0(data->dir[3*0+0], data->dir[3*0+1], data->dir[3*0+2]); foo0.print();
                        SVector3 foo1(data->dir[3*1+0], data->dir[3*1+1], data->dir[3*1+2]); foo1.print();
                        SVector3 foo2(data->dir[3*2+0], data->dir[3*2+1], data->dir[3*2+2]); foo2.print();
                        Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, closestDir);
                      }
                      if(closestDir != closestDirs[q][q_opp][k]) Msg::Error("Mismatch 2\n");
                      if(closestDir >= 0){
                        data->size[closestDir] = fmin(data->size[closestDir], data_opp->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                        ++modifiedCells;
                        data->isStillSmoothed = true;
                      }
                    }
                    else{
                    Msg::Info("Autre\n");
                  }
                  }
                }
              } else{
                // Current full - Oppose full
                p4est_quadrant_t *q_opp = side[iOpp]->is.full.quad;
                data_opp = (size_data_t *) q_opp->p.user_data;
                if(data_opp->isPlanar){
                  SVector3 e_opp(data_opp->dir[3*k+0], data_opp->dir[3*k+1], data_opp->dir[3*k+2]);
                  if(fabs(e_opp.norm()-1.) > 1e-6){
                    Msg::Error("e_opp non unitaire : %4.10e\n", e_opp.norm());
                  }

                  // Length along these directions based on each metric
                  double he = 1.0/sqrt(dot(e_opp, data->M, e_opp)); // Size of opposite directions in current metric
                  double he_opp = 1.0/sqrt(dot(e, data_opp->M, e)); // Size of current directions in opposite metric

                  // Current size is greater than its projection on the opposing cell
                  if(data->size[k] > he_opp){
                    data->size[k] = fmin(data->size[k], he_opp + alpha * (data_opp->h/2. + data->h/2.));
                    ++modifiedCells;
                    // Msg::Info("1\n");
                    data->isStillSmoothed = true;
                  }
                  // Opposing size is greater than its projection on the current cell
                  else if(data_opp->size[k] > he){
                    data_opp->size[k] = fmin(data_opp->size[k], he + alpha * (data_opp->h/2. + data->h/2.));
                    ++modifiedCells;
                    // Msg::Info("2\n");
                    data->isStillSmoothed = true;
                  }
                  // Gradient is too large but no size is greater than its projection
                  // On regarde la direction la plus proche chez le voisin, et on limite la taille selon cette direction chez le voisin
                  else if(data->size[k] < he_opp){  // printf("ERREUR 3 : (norme e = %4.4e) size[%d] = %4.4e - he_opp = %4.4e - s_cor = %4.4e- size_opp[%d] = %4.4e - he = %4.4e\n", e.norm(), k, data->size[k], he_opp, he_opp + alpha * (data_opp->h/2. + data->h/2.), k, data_opp->size[k], he);
                    double dotMax = -1.0, dotProd;
                    int closestDir;
                    for(int ii = 0; ii < forestOptions->dim; ++ii){
                      SVector3 e_opp_ii(data_opp->dir[3*ii+0], data_opp->dir[3*ii+1], data_opp->dir[3*ii+2]);
                      if(fabs(e_opp_ii.norm()-1.) > 1e-6){
                        Msg::Error("e_opp_ii non unitaire : %4.10e\n", e_opp_ii.norm());
                      }
                      dotProd = fabs(dot(e, e_opp_ii));
                      if(dotProd > dotMax){
                        dotMax = fmax(dotMax, dotProd);
                        closestDir = ii;
                      }
                    }
                    if(dotMax < sqrt(2)/2.-1e-6){
                      e.print();
                      SVector3 foo0(data_opp->dir[3*0+0], data_opp->dir[3*0+1], data_opp->dir[3*0+2]); foo0.print();
                      SVector3 foo1(data_opp->dir[3*1+0], data_opp->dir[3*1+1], data_opp->dir[3*1+2]); foo1.print();
                      SVector3 foo2(data_opp->dir[3*2+0], data_opp->dir[3*2+1], data_opp->dir[3*2+2]); foo2.print();
                      Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, closestDir);
                    }
                    if(closestDir != closestDirs[q][q_opp][k]) Msg::Error("Mismatch 1\n");
                    if(closestDir >= 0){
                      data_opp->size[closestDir] = fmin(data_opp->size[closestDir], data->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                      ++modifiedCells;
                      // Msg::Info("3\n");
                      data->isStillSmoothed = true;
                    }
                  }
                  else if(data_opp->size[k] < he){
                    // Msg::Info("Full-Full (3-4)\n");
                    double dotMax = -1.0, dotProd;
                    int closestDir;
                    for(int ii = 0; ii < forestOptions->dim; ++ii){
                      SVector3 e_ii(data->dir[3*ii+0], data->dir[3*ii+1], data->dir[3*ii+2]);
                      if(fabs(e_ii.norm()-1.) > 1e-6){
                        Msg::Error("e_ii non unitaire : %4.10e\n", e_ii.norm());
                      }
                      dotProd = fabs(dot(e_ii, e_opp));
                      if(dotProd > dotMax){
                        dotMax = fmax(dotMax, dotProd);
                        closestDir = ii;
                      }
                      // Msg::Info("dotMax = %4.4e\n", dotMax);
                    }
                    if(dotMax < sqrt(2)/2.-1e-6){
                      e_opp.print();
                      SVector3 foo0(data->dir[3*0+0], data->dir[3*0+1], data->dir[3*0+2]); foo0.print();
                      SVector3 foo1(data->dir[3*1+0], data->dir[3*1+1], data->dir[3*1+2]); foo1.print();
                      SVector3 foo2(data->dir[3*2+0], data->dir[3*2+1], data->dir[3*2+2]); foo2.print();
                      Msg::Error("dotMax = %4.4e - closestDir = %d\n", dotMax, closestDir);
                    }
                    // SVector3 e11(data->dir[3*0+0], data->dir[3*0+1], data->dir[3*0+2]);
                    // SVector3 e22(data->dir[3*1+0], data->dir[3*1+1], data->dir[3*1+2]);
                    // SVector3 e33(data->dir[3*2+0], data->dir[3*2+1], data->dir[3*2+2]);
                    // Msg::Info("e_opp = (%+2.2e,%+2.2e,%+2.2e) - e1 = (%+2.2e,%+2.2e,%+2.2e) - e2 = (%+2.2e,%+2.2e,%+2.2e) - e3 = (%+2.2e,%+2.2e,%+2.2e) - Best is %d with dot = %4.4e\n",
                    //   e_opp[0], e_opp[1], e_opp[2], e11[0], e11[1], e11[2], e22[0], e22[1], e22[2], e33[0], e33[1], e33[2], closestDir, dotMax);
                    if(closestDir != closestDirs[q][q_opp][k]) Msg::Error("Mismatch 2\n");
                    if(closestDir >= 0){
                      data->size[closestDir] = fmin(data->size[closestDir], data_opp->size[k] + alpha/dotMax * (data_opp->h/2. + data->h/2.));
                      ++modifiedCells;
                      // Msg::Info("4\n");
                      data->isStillSmoothed = true;
                    }
                  }
                  else{
                    Msg::Info("Autre\n");
                  }
                } // isPlanar
              } // isFull
            } // if gradient is too large
          } // else
        }
      }
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
  ForestOptions      *forestOptions = (ForestOptions *) user_data;

  if(forestOptions->dim == 3){
    SVector3 v1(data->dir[0],data->dir[1],data->dir[2]);
    SVector3 v2(data->dir[3],data->dir[4],data->dir[5]);
    SVector3  n(data->dir[6],data->dir[7],data->dir[8]);
    if(isnan(v1.norm()) || isnan(v2.norm()) || isnan(n.norm())) 
      printf("Normes : v1 = %f \t v2 = %f \t n = %f - intersection = %d\n", v1.norm(), v2.norm(), n.norm(), data->hasIntersection);
    SMetric3 m(1.0/(data->size[0]*data->size[0]),
               1.0/(data->size[1]*data->size[1]),
               1.0/(data->size[2]*data->size[2]),
               v1, v2, n);
    data->M = m;
  } 

  else if(forestOptions->dim == 2 && data->isPlanar){
    SVector3  v1(data->dir[0],data->dir[1],data->dir[2]);
    SVector3   n(data->dir[3],data->dir[4],data->dir[5]);
    SVector3   z(0.,0.,1.);
    SMetric3 m(1.0/(data->size[0]*data->size[0]),
               1.0/(data->size[1]*data->size[1]), 
               1.0,
               v1, n, z);
    // m.print("foo");
    if(fabs(m.determinant()) <= 1e-12){
      v1.print();
      n.print();
      z.print();
      double c[3];
      getCellCenter(info->p4est, info->treeid, q, c);
      Msg::Info("tailles : %4.4e - %4.4e %4.4e\n", data->size[0], data->size[1], data->size[2]);
      Msg::Error("det(M) = %f at (%4.4e,%4.4e,%4.4e)\n", m.determinant(), c[0], c[1], c[2]);
      Msg::Exit(-1);
    }
    data->M = m;
  }

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

static void resetSmoothIndicator(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  data->isStillSmoothed = false;
}

HXTStatus forestSizeSmoothing(Forest *forest){
  double gradMax[9], gradLinf, gradLinf_im1 = -1e22;
  int iter = 0, nmax = 100;
  int aniso = forest->forestOptions->aniso;
  int dim = forest->forestOptions->dim;
  double delta_i = 1e22, delta_im1;

  Msg::Info("Identifying closest directions...\t");
  p4est_iterate (forest->p4est, NULL, (void*) forest->forestOptions, NULL, setClosestDirections, NULL, NULL);
  Msg::Info("Done\n");

  do{
    p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, resetSmoothIndicator, NULL, NULL, NULL);
    modifiedCells = 0;
    gradLinf = -1e22;
    delta_im1 = delta_i;
    if(aniso){ HXT_CHECK( forestAssembleMetricTensors(forest)); }
    // HXT_CHECK( forestComputeGradient(forest) );    // Compute gradient
    // HXT_CHECK( forestLimitSize(forest)       );    // Limit large sizes to limit gradient to foresOptions->gradMax
    p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, NULL, toutEnUn, NULL, NULL);
    for(int i = 0; i < (aniso ? 9 : 3); ++i) gradMax[i] = -1e22; // Stopping criterion
    if(dim == 2){
      gradMax[2] = gradMax[5] = gradMax[6] = gradMax[7] = gradMax[8] = NAN;
    }
    HXT_CHECK( forestGetMaxGradient(forest, gradMax) );
    if(dim == 3){ for(int i = 0; i < (aniso ? 9 : 3); ++i) gradLinf = fmax(gradLinf, fabs(gradMax[i])); }
    if(dim == 2){ for(int i = 0; i < (aniso ? 5 : 2); ++i){ if(i!=2) gradLinf = fmax(gradLinf, fabs(gradMax[i])); }}

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
        Msg::Info("Modified cells : %8d Max gradient : %10.3e - grad h1 = (%10.3e - %10.3e - %10.3e) - grad h2 = (%10.3e - %10.3e - %10.3e)",
          modifiedCells,
          gradLinf,
          fabs(gradMax[0]), fabs(gradMax[1]), fabs(gradMax[2]),
          fabs(gradMax[3]), fabs(gradMax[4]), fabs(gradMax[5]));
      }
      if(dim==3){
        Msg::Info("Modified cells : %8d Max gradient : %10.3e - grad h1 = (%10.3e - %10.3e - %10.3e) - grad h2 = (%10.3e - %10.3e - %10.3e) - grad hn = (%10.3e - %10.3e - %10.3e)",
          modifiedCells,
          gradLinf,
          fabs(gradMax[0]), fabs(gradMax[1]), fabs(gradMax[2]),
          fabs(gradMax[3]), fabs(gradMax[4]), fabs(gradMax[5]),
          fabs(gradMax[6]), fabs(gradMax[7]), fabs(gradMax[8]));
      }
    }
    delta_i = gradLinf - gradLinf_im1;
    gradLinf_im1 = gradLinf;
  // } while(iter++ < nmax && gradLinf > forest->forestOptions->gradation - 1.0 + 1e-5 && fabs(delta_i) >= 1e-2 && fabs(delta_im1) >= 1e-2);
  } while(modifiedCells > 0 && iter++ < nmax && gradLinf > forest->forestOptions->gradation - 1.0 + 1e-5);

  return HXT_STATUS_OK;
}

static inline void barycentric(SPoint3 p, SPoint3 a, SPoint3 b, SPoint3 c, double &u, double &v, double &w){
    SVector3 v0 = b - a, v1 = c - a, v2 = p - a;
    double den = v0[0] * v1[1] - v1[0] * v0[1];
    v = (v2[0] * v1[1] - v1[0] * v2[1]) / den;
    w = (v0[0] * v2[1] - v2[0] * v0[1]) / den;
    u = 1.0 - v - w;
}

static inline SVector3 interpolateDirTri(double *dir, uint32_t n0, uint32_t n1, uint32_t n2, double *uvw){
  // double t0 = (dir[9*n0]*dir[9*n0+1] < 0) ? atan2(-dir[9*n0+1],dir[9*n0]) : atan2(dir[9*n0+1],dir[9*n0]); // Angle associated to e1 at vertex 0
  // double t1 = (dir[9*n1]*dir[9*n1+1] < 0) ? atan2(-dir[9*n1+1],dir[9*n1]) : atan2(dir[9*n1+1],dir[9*n1]); // Angle associated to e1 at vertex 1
  // double t2 = (dir[9*n2]*dir[9*n2+1] < 0) ? atan2(-dir[9*n2+1],dir[9*n2]) : atan2(dir[9*n2+1],dir[9*n2]); // Angle associated to e1 at vertex 2
  double t0 = fmin(atan2(-dir[9*n0+1],-dir[9*n0]),atan2(dir[9*n0+1],dir[9*n0])); // Angle associated to e1 at vertex 0
  double t1 = fmin(atan2(-dir[9*n1+1],-dir[9*n1]),atan2(dir[9*n1+1],dir[9*n1])); // Angle associated to e1 at vertex 1
  double t2 = fmin(atan2(-dir[9*n2+1],-dir[9*n2]),atan2(dir[9*n2+1],dir[9*n2])); // Angle associated to e1 at vertex 2

  double cI = (1. - uvw[0] - uvw[1]) * cos(t0) + uvw[0] * cos(t1) + uvw[1] * cos(t2);
  double sI = (1. - uvw[0] - uvw[1]) * sin(t0) + uvw[0] * sin(t1) + uvw[1] * sin(t2);
  double tI = atan2(sI,cI);

  return SVector3(cos(tI),sin(tI),0.);
}

// So far, directions in the octree are assigned based on the closest volume mesh node's directions
// (Closest to the center of the octant)
static void assignDirectionsCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_t            *p4est = info->p4est;
  p4est_quadrant_t   *q = info->quad;
  p4est_topidx_t      which_tree = info->treeid;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  ForestOptions      *forestOptions = (ForestOptions *) user_data;
  HXTMesh            *meshDom = forestOptions->mesh3D;
  HXTMesh            *meshBnd = forestOptions->mesh2D;
// #define FREEZE_DIRECTIONS
  double h, center[3], min[3], max[3];
  getCellSize(p4est, which_tree, q, &h);
  getCellCenter(p4est, which_tree, q, center);

  if(data->isPlanar){
    getCellBBox(p4est, which_tree, q, min, max);
    double cooCorner[12] = {center[0] + h/2., center[1] + h/2., 0.,
                            center[0] + h/2., center[1] - h/2., 0.,
                            center[0] - h/2., center[1] - h/2., 0.,
                            center[0] - h/2., center[1] + h/2., 0.,}; // Just min[] and max[] probably work too
    std::vector<uint64_t> candidates;
    forestOptions->domRTree->Search(min, max, rtreeCallback, &candidates);

    if(!candidates.empty()){
      std::vector<int> cornersToFind{0,1,2,3};
      double dist[5];
      double minDist[5] = {DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX} ;
      int closestNode[5] = {-1, -1, -1, -1, -1};
      bool isInsideAnElem[5] = {false, false, false, false, false};
      for(uint64_t elem : candidates){
        std::vector<int>::iterator it = cornersToFind.begin();
        if(forestOptions->dim == 3){
          uint32_t n0 = meshDom->tetrahedra.node[4*elem];
          uint32_t n1 = meshDom->tetrahedra.node[4*elem+1];
          uint32_t n2 = meshDom->tetrahedra.node[4*elem+2];
          uint32_t n3 = meshDom->tetrahedra.node[4*elem+3];
          MTetrahedron tet((*forestOptions->c2vDom)[n0], (*forestOptions->c2vDom)[n1], (*forestOptions->c2vDom)[n2], (*forestOptions->c2vDom)[n3]);
          double uvw[3]; tet.xyz2uvw(center, uvw);
          bool isInside = tet.isInside(uvw[0], uvw[1], uvw[2]);
          if(isInside){ // Center of the octant is in an tetrahedron
            isInsideAnElem[0] = true;
            double *dir = forestOptions->directions;
            const double directions[36] = {dir[9*n0],dir[9*n0+1],dir[9*n0+2],dir[9*n0+3],dir[9*n0+4],dir[9*n0+5],dir[9*n0+6],dir[9*n0+7],dir[9*n0+8],
                                           dir[9*n1],dir[9*n1+1],dir[9*n1+2],dir[9*n1+3],dir[9*n1+4],dir[9*n1+5],dir[9*n1+6],dir[9*n1+7],dir[9*n1+8],
                                           dir[9*n2],dir[9*n2+1],dir[9*n2+2],dir[9*n2+3],dir[9*n2+4],dir[9*n2+5],dir[9*n2+6],dir[9*n2+7],dir[9*n2+8],
                                           dir[9*n3],dir[9*n3+1],dir[9*n3+2],dir[9*n3+3],dir[9*n3+4],dir[9*n3+5],dir[9*n3+6],dir[9*n3+7],dir[9*n3+8]};
            double dirAtParamNode[9], quality = 0.0;
            int flagTrusted[3] = {0};
            hxtOr3DgetCrossInTetFromDir(directions, uvw, dirAtParamNode, &quality, flagTrusted);
            for(size_t i = 0; i < 9; ++i){
              data->dir[i] = dirAtParamNode[i];
            }
            break;
          } else{ // Looking for closest tet node to the center of the octant
            for(size_t i = 0; i < 4; ++i){
              uint32_t iNode = meshDom->tetrahedra.node[4*elem+i];
              double *x = meshDom->vertices.coord + 4*iNode;
              dist[0] = sqrt( (center[0]-x[0])*(center[0]-x[0]) + (center[1]-x[1])*(center[1]-x[1]) + (center[2]-x[2])*(center[2]-x[2]));
              if(dist[0] < minDist[0]){
                minDist[0] = dist[0];
                closestNode[0] = iNode;
              }
            }
          }
        } else{ // dim = 2
          uint32_t n0 = meshDom->triangles.node[3*elem];
          uint32_t n1 = meshDom->triangles.node[3*elem+1];
          uint32_t n2 = meshDom->triangles.node[3*elem+2];
          MTriangle tri((*forestOptions->c2vDom)[n0], (*forestOptions->c2vDom)[n1], (*forestOptions->c2vDom)[n2]);
          // Assign directions to the center of the octant
          double uvw[3]; tri.xyz2uvw(center, uvw);
          bool isInside = tri.isInside(uvw[0], uvw[1], uvw[2]);
          if(isInside && !isInsideAnElem[0]){ // Center of the octant is in a triangle
            isInsideAnElem[0] = true;
            double *dir = forestOptions->directions;
            SVector3 d0(dir[9*n0+0],dir[9*n0+1],dir[9*n0+2]);
            SVector3 d1(dir[9*n1+0],dir[9*n1+1],dir[9*n1+2]);
            SVector3 d2(dir[9*n2+0],dir[9*n2+1],dir[9*n2+2]);

            // SVector3 avg = d0 * (1-uvw[0]-uvw[1]) + d1 * uvw[0] + d2 * uvw[1];
            SVector3 avg = interpolateDirTri(dir,n0,n1,n2,uvw);

            if(fabs(dot(avg,d0)) < 0.8 || fabs(dot(avg,d1)) < 0.8 || fabs(dot(avg,d2)) < 0.8){
              d0.print();
              d1.print();
              d2.print();
              avg.print();
              Msg::Error("dot\n");
            }


            SVector3 v = crossprod(avg,SVector3(0.,0.,1.));
            // Check interpolated direction is unit
            if(avg.norm() > 1e-6 && v.norm() > 1e-6){
              avg.normalize();
              v.normalize();
            }
            if(fabs(avg.norm() - 1.) > 1e-2 || fabs(v.norm() - 1.) > 1e-2){
              Msg::Error("Moyenne non unitaire : avg.norm = %4.4e - v.norm = %4.4e\n", avg.norm(), v.norm());
              Msg::Exit(1);
            }
            for(size_t i = 0; i < 3; ++i){
              data->dir[i]   = avg[i];
              data->dir[3+i] = v[i];
            }
            data->dir[6] = 0.;
            data->dir[7] = 0.;
            data->dir[8] = 1.;
          }
          // Assign directions to the corners (temporary fix to have a smoother metric field after queries)
          // for(size_t i = 0; i < 4; ++i){
          while(it != cornersToFind.end()){
            int c = *it;
            double uvwCorner[3]; tri.xyz2uvw(cooCorner+3*c, uvwCorner);
            bool isInside = tri.isInside(uvwCorner[0], uvwCorner[1], uvwCorner[2]);
            if(isInside && !isInsideAnElem[1+c]){ // Corner is in a triangle
              isInsideAnElem[1+c] = true;
              double *dir = forestOptions->directions;
              // SVector3 d0(dir[9*n0+0],dir[9*n0+1],dir[9*n0+2]);
              // SVector3 d1(dir[9*n1+0],dir[9*n1+1],dir[9*n1+2]);
              // SVector3 d2(dir[9*n2+0],dir[9*n2+1],dir[9*n2+2]);
              // SVector3 avg = d0 * (1-uvwCorner[0]-uvwCorner[1]) + d1 * uvwCorner[0] + d2 * uvwCorner[1];
              SVector3 avg = interpolateDirTri(dir,n0,n1,n2,uvwCorner);

              SVector3 v = crossprod(avg,SVector3(0.,0.,1.));
              // Check interpolated direction is unit
              if(avg.norm() > 1e-6 && v.norm() > 1e-6){
                avg.normalize();
                v.normalize();
              }
              if(fabs(avg.norm() - 1.) > 1e-2 || fabs(v.norm() - 1.) > 1e-2){
                Msg::Error("Moyenne non unitaire : avg.norm = %4.4e - v.norm = %4.4e\n", avg.norm(), v.norm());
                Msg::Exit(1);
              }
              for(size_t j = 0; j < 3; ++j){
                data->dirCorner[9*c+j]   = avg[j];
                data->dirCorner[9*c+3+j] = v[j];
              }
              data->dirCorner[9*c+6] = 0.;
              data->dirCorner[9*c+7] = 0.;
              data->dirCorner[9*c+8] = 1.;
              it = cornersToFind.erase(it);
            } else{
              ++it;
            }
          }
          // Looking for closest tri node to the center of the octant (not used if inside an element)
          for(size_t i = 0; i < 3; ++i){
            uint32_t iNode = meshDom->triangles.node[3*elem+i];
            double *x = meshDom->vertices.coord + 4*iNode;
            dist[0] = sqrt( (center[0]   -x[0])*(center[0]   -x[0]) + (center[1]    -x[1])*(center[1]    -x[1]) );
            dist[1] = sqrt( (cooCorner[0]-x[0])*(cooCorner[0]-x[0]) + (cooCorner[1] -x[1])*(cooCorner[1] -x[1]) );
            dist[2] = sqrt( (cooCorner[3]-x[0])*(cooCorner[3]-x[0]) + (cooCorner[4] -x[1])*(cooCorner[4] -x[1]) );
            dist[3] = sqrt( (cooCorner[6]-x[0])*(cooCorner[6]-x[0]) + (cooCorner[7] -x[1])*(cooCorner[7] -x[1]) );
            dist[4] = sqrt( (cooCorner[9]-x[0])*(cooCorner[9]-x[0]) + (cooCorner[10]-x[1])*(cooCorner[11]-x[1]) );
            for(size_t j = 0; j < 5; ++j){
              if(dist[j] < minDist[j]){
                minDist[j] = dist[j];
                closestNode[j] = iNode;
              }
            }
          }
        }
      } // for elem : candidates

      // Assign size if nodes are not inside an element
      for(size_t ii = 0; ii < 5; ++ii){
        if(!isInsideAnElem[ii]){
          if(closestNode[ii] >= 0){
            if(forestOptions->dim == 3){
              for(size_t i = 0; i < 9; ++i)
                if(ii==0){ data->dir[i] = forestOptions->directions[9*closestNode[ii]+i]; } // Center
                else     { data->dirCorner[i] = forestOptions->directions[9*closestNode[ii]+i]; Msg::Error("assignDirections in 3D : TODO\n"); } // Corners
            } else{
              if(ii==0){ 
                for(size_t i = 0; i < 6; ++i){
                  data->dir[i] = forestOptions->directions[9*closestNode[ii]+i];
                  data->dir[6] = 0.;
                  data->dir[7] = 0.;
                  data->dir[8] = 1.;
                }
              } else{
                for(size_t i = 0; i < 6; ++i){
                  data->dirCorner[9*(ii-1)+i] = forestOptions->directions[9*closestNode[ii]+i];
                  data->dirCorner[9*(ii-1)+6] = 0.;
                  data->dirCorner[9*(ii-1)+7] = 0.;
                  data->dirCorner[9*(ii-1)+8] = 1.;
                }
              }
            }
          }
          // if(closestTetToCenter >= 0){
          //   for(size_t i = 0; i < 3; ++i){
          //     data->dir[i]   = forestOptions->directionsU[3*closestTetToCenter+i];
          //     data->dir[3+i] = forestOptions->directionsV[3*closestTetToCenter+i];
          //     data->dir[6+i] = forestOptions->directionsW[3*closestTetToCenter+i];
          //   }
          // }
        }
      }
      data->hasIntersection = true;
    } else{
      // Assign directions of the closest node (not the best...)
      int closestNode[5] = {-1, -1, -1, -1, -1}; // TODO : Correct this for 3D
      double minDist[5] = {DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX}, dist[5];
      if(forestOptions->dim == 3){
        // for(uint32_t iNode = 0; iNode < meshBnd->vertices.num; ++iNode){
        //   double *x = meshBnd->vertices.coord + 4*iNode;
        //   dist[0] = sqrt( (center[0]-x[0])*(center[0]-x[0]) + (center[1]-x[1])*(center[1]-x[1]) + (center[2]-x[2])*(center[2]-x[2]));
        //   dist[1] = sqrt( (cooCorner[0]-x[0])*(cooCorner[0]-x[0]) + (cooCorner[1]-x[1])*(cooCorner[1]-x[1]) + (cooCorner[2]-x[2])*(cooCorner[2]-x[2]));
        //   dist[2] = sqrt( (cooCorner[3]-x[0])*(cooCorner[3]-x[0]) + (cooCorner[4]-x[1])*(cooCorner[4]-x[1]) + (cooCorner[5]-x[2])*(cooCorner[5]-x[2]));
        //   dist[3] = sqrt( (cooCorner[6]-x[0])*(cooCorner[6]-x[0]) + (cooCorner[7]-x[1])*(cooCorner[7]-x[1]) + (cooCorner[8]-x[2])*(cooCorner[8]-x[2]));
        //   dist[4] = sqrt( (cooCorner[9]-x[0])*(cooCorner[9]-x[0]) + (cooCorner[10]-x[1])*(cooCorner[11]-x[1]) + (cooCorner[11]-x[2])*(cooCorner[11]-x[2]));
        //   for(size_t i = 0; i < 5; ++i){
        //     if(dist[i] < minDist[i]){
        //       minDist[i] = dist[i];
        //       closestNode[i] = iNode;
        //     }
        //   }
        // }
        // if(closestNode[0] >= 0){
        //   for(size_t i = 0; i < 9; ++i)
        //     data->dir[i] = forestOptions->directions[9*closestNode+i];
        // }
        // for(size_t i = 1; i < 5; ++i){
        //   if(closestNode[i] >= 0){
        //     for(size_t ii = 0; ii < 9; ++ii)
        //       data->dirCorner[9*(i-1)+ii] = forestOptions->directions[9*closestNode+ii];
        //   }
        // }
        Msg::Error("TODO : Correct direction assignment in 3D\n");
      } else{
        for(uint64_t iElm = 0; iElm < meshDom->triangles.num; ++iElm){
          for(size_t j = 0; j < 3; ++j){
            uint32_t iNode = meshDom->triangles.node[3*iElm+j];
            double *x = meshDom->vertices.coord + 4*iNode;
            dist[0] = sqrt( (center[0]   -x[0])*(center[0]   -x[0]) + (center[1]    -x[1])*(center[1]    -x[1]));
            dist[1] = sqrt( (cooCorner[0]-x[0])*(cooCorner[0]-x[0]) + (cooCorner[1] -x[1])*(cooCorner[1] -x[1]));
            dist[2] = sqrt( (cooCorner[3]-x[0])*(cooCorner[3]-x[0]) + (cooCorner[4] -x[1])*(cooCorner[4] -x[1]));
            dist[3] = sqrt( (cooCorner[6]-x[0])*(cooCorner[6]-x[0]) + (cooCorner[7] -x[1])*(cooCorner[7] -x[1]));
            dist[4] = sqrt( (cooCorner[9]-x[0])*(cooCorner[9]-x[0]) + (cooCorner[10]-x[1])*(cooCorner[11]-x[1]));
            for(size_t i = 0; i < 5; ++i){
              if(dist[i] < minDist[i]){
                minDist[i] = dist[i];
                closestNode[i] = iNode;
              }
            }
          }
        }
        if(closestNode[0] >= 0){
          for(size_t i = 0; i < 6; ++i)
            data->dir[i] = forestOptions->directions[9*closestNode[0]+i];
          data->dir[6] = 0.;
          data->dir[7] = 0.;
          data->dir[8] = 1.;
        }
        for(size_t i = 1; i < 5; ++i){
          if(closestNode[i] >= 0){
            for(size_t ii = 0; ii < 6; ++ii)
              data->dirCorner[9*(i-1)+ii] = forestOptions->directions[9*closestNode[i]+ii];
            data->dirCorner[9*(i-1)+6] = 0.;
            data->dirCorner[9*(i-1)+7] = 0.;
            data->dirCorner[9*(i-1)+8] = 1.;
          }
        }
      }
      data->hasIntersection = false;
    }
  }
}

static void markPlanarCells(p4est_iter_face_info_t *info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t             *sides = &(info->sides);
  size_data_t            *data;
  size_data_t            *data_opp;
  int                     which_dir;
  int                     iOpp;
  ForestOptions          *forestOptions = (ForestOptions*) user_data;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  if(sides->elem_count==2){
    for(int i = 0; i < 2; ++i){
      iOpp = 1 - i;
      if(side[i]->is_hanging){
        // Current hanging - Opposes full
        data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
        if(fabs(data_opp->c[2]) <= data_opp->h/2. && data_opp->c[2] >= 0.){
          for(int j = 0; j < P4EST_HALF; ++j){
            data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
            data->isPlanar = true;
          }
        }
      } else{
        data = (size_data_t *) side[i]->is.full.quad->p.user_data;
        if(side[iOpp]->is_hanging){
          // Current full - Oppose hanging
          for(int j = 0; j < P4EST_HALF; ++j){
            data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
            if(fabs(data_opp->c[2]) <= data_opp->h/2. && data_opp->c[2] >= 0.){
              data->isPlanar = true;
            }
          }
        } else{
          // Current full - Oppose full
          data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
          if(fabs(data_opp->c[2]) <= data_opp->h/2. && data_opp->c[2] >= 0.){
            data->isPlanar = true;
          }
        }
      }
    }
  }
}

#if defined(ANISO)
HXTStatus forestSmoothDirections(Forest *forest){

  ForestOptions *fO = forest->forestOptions;
  HXTMesh *meshDom = fO->mesh3D;
  HXTMesh *meshBnd = fO->mesh2D;

  double *directions = fO->directions;

  int *isBoundaryCondition;
  HXT_CHECK(hxtMalloc(&isBoundaryCondition, meshDom->vertices.num*sizeof(int)));
  for (uint64_t i = 0; i < meshDom->vertices.num; ++i)
    isBoundaryCondition[i]=0;

  FILE* myfile = fopen("justTheDirections.pos","w");
  fprintf(myfile,"View \"justTheDirections\"{\n");

  if(fO->dim == 3){
    double *frames; // C'est un tableau qui contient les 9 composantes representant les frames en chaque noeuds du maillage.
    //--structure: frames[9*iNode + k], k compris entre 0 et 8 inclus
    HXT_CHECK(hxtMalloc(&frames, meshDom->vertices.num*sizeof(double)*9));
    for (uint64_t i = 0; i < meshDom->vertices.num*9; ++i)
      frames[i] = 0.;

    for(size_t iTri = 0; iTri < meshDom->triangles.num; ++iTri){
      for(size_t jNode = 0; jNode < 3; ++jNode){
        uint32_t iNbc = meshDom->triangles.node[(size_t) 3*iTri+jNode];
        double *v1 = fO->nodalCurvature + 6*iNbc;
        double *v2 = fO->nodalCurvature + 6*iNbc + 3;
        double *n  = fO->nodeNormals    + 3*iNbc;

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

    //--une fois les frames calculées, il faut postraiter pour récupérer les directions
    // boucle sur tous les noeuds du maillage iN
    for(size_t i = 0; i < meshDom->vertices.num; ++i){
      if(!isBoundaryCondition[i]){
        double stableDir[3]={0.0}; //données sur la qualité de la frame, pas d'utilité pour toi
        double dirN[9]={0.0};      //directions de la croix, stockées comme ça: {u0,u1,u2,v0,v1,v2,w0,w1,w2}
        hxtOr3DframeToDirections(frames + 9*i, stableDir, dirN);
        for(size_t j = 0; j < 9; ++j){
          directions[9*i+j] = dirN[j];
        }
      }
    }

    FILE* myfile2 = fopen("directionsPreservees.pos","w");
    fprintf(myfile2,"View \"directionsPreservees\"{\n");
    for(size_t i = 0; i < meshDom->triangles.num; ++i){
      for(size_t jj = 0; jj < 3; ++jj){
        uint32_t iNbc = meshDom->triangles.node[(size_t) 3*i+jj];
        double *x = meshDom->vertices.coord + 4*iNbc;
        double localDir[9] = {directions[9*iNbc+0],directions[9*iNbc+1],directions[9*iNbc+2],
                              directions[9*iNbc+3],directions[9*iNbc+4],directions[9*iNbc+5],
                              directions[9*iNbc+6],directions[9*iNbc+7],directions[9*iNbc+8],};
        for (int j = 0; j < 3; ++j) {
          double d[3] = {localDir[3*j+0], localDir[3*j+1], localDir[3*j+2]};
          if(j==0){
            fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], 1.0/2.0*d[0], 1.0/2.0*d[1], 1.0/2.0*d[2]);
            fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-1.0/2.0*d[0],-1.0/2.0*d[1],-1.0/2.0*d[2]);
          } else{
            fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], d[0], d[1], d[2]);
            fprintf(myfile2,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-d[0],-d[1],-d[2]);
          }
        }
      }
    }

    fprintf(myfile2,"};");
    fclose(myfile2);

    HXT_CHECK(hxtOr3DWritePosCrossesFromFrames(meshBnd, frames, "thisShouldBeBetter.pos", NULL));

    // for(uint64_t i = 0; i < 3*meshDom->tetrahedra.num; ++i){
    //   fO->directionsU[i] = liftU[i];
    //   fO->directionsV[i] = liftV[i];
    //   fO->directionsW[i] = liftW[i];
    // }

    // HXT_CHECK(hxtFree(&directionsElem));
    // HXT_CHECK(hxtFree(&smoothnessIndicator));
    // HXT_CHECK(hxtFree(&liftU));
    // HXT_CHECK(hxtFree(&liftV));
    // HXT_CHECK(hxtFree(&liftW));
    HXT_CHECK(hxtFree(&frames));
    HXT_CHECK(hxtFree(&isBoundaryCondition));

  } else{ // dim = 2
    std::vector<std::array<double,9>> *triDir = fO->triangleDirections;
#ifndef FREEZE_DIRECTIONS
    bool load = true;
    if(load){
      Msg::Info("Loading directions");
      FILE *myDir = fopen("justTheDirections.txt", "r");
      char buf[BUFSIZ];
      double aa,bb,cc,dd,ee,ff,gg,hh,ii;
      uint64_t cnt = 0;
      while( fgets(buf, BUFSIZ, myDir )!=NULL){
        sscanf(buf, "%lf %lf %lf %lf %lf %lf %lf %lf %lf", &aa, &bb, &cc, &dd, &ee, &ff, &gg, &hh, &ii);
        (*triDir)[cnt][0] = aa;
        (*triDir)[cnt][1] = bb;
        (*triDir)[cnt][2] = cc;
        (*triDir)[cnt][3] = dd;
        (*triDir)[cnt][4] = ee;
        (*triDir)[cnt][5] = ff;
        (*triDir)[cnt][6] = gg;
        (*triDir)[cnt][7] = hh;
        (*triDir)[cnt][8] = ii;
        ++cnt;
      }

      if(cnt != meshDom->triangles.num){
        Msg::Error("Mismatch : cnt = %d et #tri = %d\n", cnt, meshDom->triangles.num);
      }

      Msg::Info("[0] = %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e\n",
          (*triDir)[0][0], (*triDir)[0][1], (*triDir)[0][2],
          (*triDir)[0][3], (*triDir)[0][4], (*triDir)[0][5],
          (*triDir)[0][6], (*triDir)[0][7], (*triDir)[0][8]);
      Msg::Info("[1] = %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e\n",
          (*triDir)[1][0], (*triDir)[1][1], (*triDir)[1][2],
          (*triDir)[1][3], (*triDir)[1][4], (*triDir)[1][5],
          (*triDir)[1][6], (*triDir)[1][7], (*triDir)[1][8]);
      Msg::Info("[n-1] = %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e\n",
          (*triDir)[cnt-2][0], (*triDir)[cnt-2][1], (*triDir)[cnt-2][2],
          (*triDir)[cnt-2][3], (*triDir)[cnt-2][4], (*triDir)[cnt-2][5],
          (*triDir)[cnt-2][6], (*triDir)[cnt-2][7], (*triDir)[cnt-2][8]);
      Msg::Info("[n] = %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e\n",
          (*triDir)[cnt-1][0], (*triDir)[cnt-1][1], (*triDir)[cnt-1][2],
          (*triDir)[cnt-1][3], (*triDir)[cnt-1][4], (*triDir)[cnt-1][5],
          (*triDir)[cnt-1][6], (*triDir)[cnt-1][7], (*triDir)[cnt-1][8]);

      fclose(myDir);
    } else{
      FILE* myDir = fopen("justTheDirections.txt","w");
      std::vector<MTriangle*> triangles;
      for(size_t i = 0; i < meshDom->triangles.num; ++i){
        triangles.push_back(new MTriangle((*fO->c2vDom)[ meshDom->triangles.node[3*i+0] ],
                                          (*fO->c2vDom)[ meshDom->triangles.node[3*i+1] ],
                                          (*fO->c2vDom)[ meshDom->triangles.node[3*i+2] ]));
      }

      std::vector<MLine*> lines;
      for(size_t i = 0; i < meshBnd->lines.num; ++i){
        lines.push_back(new MLine((*fO->c2vBnd)[ meshBnd->lines.node[2*i+0] ],
                                  (*fO->c2vBnd)[ meshBnd->lines.node[2*i+1] ]));
      }

      std::vector<std::array<double,3> > triEdgeTheta;
      computeCrossFieldWithHeatEquation(4,triangles,lines,triEdgeTheta);
      convertToPerTriangleCrossFieldDirections(4,triangles,triEdgeTheta, *triDir);

      Msg::Info("Writing 2D directions");
      for(size_t i = 0; i < meshDom->triangles.num; ++i){
        SVector3 foo1((*triDir)[i][0], (*triDir)[i][1], (*triDir)[i][2]);
        SVector3 foo2((*triDir)[i][3], (*triDir)[i][4], (*triDir)[i][5]);
        SVector3 foo3((*triDir)[i][6], (*triDir)[i][7], (*triDir)[i][8]);
        if(foo1.norm() <= 1e-3) Msg::Error("Dir1");
        if(foo2.norm() <= 1e-3) Msg::Error("Dir2");
        if(foo3.norm() <= 1e-3) Msg::Error("Dir3");
        fprintf(myDir, "%10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e %10.10e\n",
          (*triDir)[i][0], (*triDir)[i][1], (*triDir)[i][2],
          (*triDir)[i][3], (*triDir)[i][4], (*triDir)[i][5],
          (*triDir)[i][6], (*triDir)[i][7], (*triDir)[i][8]);
      }
      fclose(myDir);
    }

    for(size_t i = 0; i < meshDom->vertices.num; ++i){
      for(size_t j = 0; j < 9; ++j){
        directions[9*i+j] = NAN;
      }
    }

    SVector3 ez(0.,0.,1.);
    // Impose directions on boundary nodes
    for(size_t i = 0; i < meshBnd->lines.num; ++i){
      uint32_t node0 = meshBnd->lines.node[2*i+0];
      uint32_t node1 = meshBnd->lines.node[2*i+1];
      MVertex *v0 = (*forest->forestOptions->c2vBnd)[node0];
      MVertex *v1 = (*forest->forestOptions->c2vBnd)[node1];
      MEdge e(v0,v1);
      SVector3 dir0 = e.tangent();
      SVector3 dir1 = crossprod(dir0,ez);
      // Check directions are unit
      if(dir0.norm() > 1e-6 && dir1.norm() > 1e-6){
        dir0.normalize();
        dir1.normalize();
      }
      if(fabs(dir0.norm() - 1.) > 1e-2 || fabs(dir1.norm() - 1.) > 1e-2){
        Msg::Error("In smoothDirections : directions are not unit : dir0.norm = %4.4e - dir1.norm = %4.4e\n", dir0.norm(), dir1.norm());
        Msg::Exit(1);
      }
      // Check directions are orthogonal
      if(fabs(dot(dir0,dir1)) > 1e-6){
        Msg::Error("In smoothDirections : directions are not orthogonal : dot = %4.4e\n", fabs(dot(dir0,dir1)));
        Msg::Exit(1);
      }
      uint32_t node0Dom = (*forest->forestOptions->v2cDom)[v0];
      directions[9 * node0Dom + 0] = dir0[0];
      directions[9 * node0Dom + 1] = dir0[1];
      directions[9 * node0Dom + 2] = dir0[2];
      directions[9 * node0Dom + 3] = dir1[0];
      directions[9 * node0Dom + 4] = dir1[1];
      directions[9 * node0Dom + 5] = dir1[2];
      isBoundaryCondition[node0Dom] = 1;
    }

    // Assign directions on interior nodes
    for(size_t i = 0; i < meshDom->triangles.num; ++i){
      for(size_t j = 0; j < 3; ++j){
        uint32_t iNode = meshDom->triangles.node[3*i+j];
        if(!isBoundaryCondition[iNode]){
          SVector3 dir0((*triDir)[i][3*j+0],(*triDir)[i][3*j+1],(*triDir)[i][3*j+2]);
          SVector3 dir1 = crossprod(dir0,ez);
          // Check directions are unit
          if(dir0.norm() > 1e-6 && dir1.norm() > 1e-6){
            dir0.normalize();
            dir1.normalize();
          }
          if(fabs(dir0.norm() - 1.) > 1e-2 || fabs(dir1.norm() - 1.) > 1e-2){
            Msg::Error("In smoothDirections : directions are not unit : dir0.norm = %4.4e - dir1.norm = %4.4e\n", dir0.norm(), dir1.norm());
            Msg::Exit(1);
          }
          // Check directions are orthogonal
          if(fabs(dot(dir0,dir1)) > 1e-6){
            Msg::Error("In smoothDirections : directions are not orthogonal : dot = %4.4e\n", fabs(dot(dir0,dir1)));
            Msg::Exit(1);
          }
          directions[9*iNode+0] = dir0[0];
          directions[9*iNode+1] = dir0[1];
          directions[9*iNode+2] = dir0[2];
          directions[9*iNode+3] = dir1[0];
          directions[9*iNode+4] = dir1[1];
          directions[9*iNode+5] = dir1[2];
        }
      }
    }

    // Lift the directions (part1)
    std::list<uint32_t> *adj = new std::list<uint32_t>[meshDom->vertices.num];
    for(size_t i = 0; i < meshDom->triangles.num; ++i){
      adj[meshDom->triangles.node[3*i+0]].push_back(meshDom->triangles.node[3*i+1]);
      adj[meshDom->triangles.node[3*i+1]].push_back(meshDom->triangles.node[3*i+0]);
      adj[meshDom->triangles.node[3*i+0]].push_back(meshDom->triangles.node[3*i+2]);
      adj[meshDom->triangles.node[3*i+2]].push_back(meshDom->triangles.node[3*i+0]);
      adj[meshDom->triangles.node[3*i+1]].push_back(meshDom->triangles.node[3*i+2]);
      adj[meshDom->triangles.node[3*i+2]].push_back(meshDom->triangles.node[3*i+1]);
    }

    // Assign directions on floating nodes (if any)
    FILE* myfile3 = fopen("patch.pos","w");
    fprintf(myfile3,"View \"patch\"{\n");
    for(size_t i = 0; i < meshDom->points.num; ++i){
      uint32_t iNode = meshDom->points.node[i];
      if(isnan(directions[9*iNode+0])){
        double *x = meshDom->vertices.coord + 4*iNode;
        fprintf(myfile3,"SP(%.16g,%.16g,%.16g){%.16g};\n", x[0], x[1], x[2], iNode, iNode, iNode);
        double dx = 1e-3;
        double min[3] = {x[0]-dx, x[1]-dx, x[2]-dx};
        double max[3] = {x[0]+dx, x[1]+dx, x[2]+dx};
        std::vector<uint64_t> candidates;
        fO->domRTree->Search(min, max, rtreeCallback, &candidates);
        bool isSet = false;
        for(auto elem : candidates){
          uint32_t n0 = meshDom->triangles.node[3*elem];
          uint32_t n1 = meshDom->triangles.node[3*elem+1];
          uint32_t n2 = meshDom->triangles.node[3*elem+2];

          adj[n0].push_back(iNode); // Add an adjacency relation for the lifting
          adj[iNode].push_back(n0);

          MTriangle tri((*fO->c2vDom)[n0], (*fO->c2vDom)[n1], (*fO->c2vDom)[n2]);
          double uvw[3]; tri.xyz2uvw(x, uvw);
          bool isInside = tri.isInside(uvw[0], uvw[1], uvw[2]);
          if(isInside){
            fprintf(myfile3,"ST(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",
              (*fO->c2vDom)[n0]->point().x(),(*fO->c2vDom)[n0]->point().y(),(*fO->c2vDom)[n0]->point().z(),
              (*fO->c2vDom)[n1]->point().x(),(*fO->c2vDom)[n1]->point().y(),(*fO->c2vDom)[n1]->point().z(),
              (*fO->c2vDom)[n2]->point().x(),(*fO->c2vDom)[n2]->point().y(),(*fO->c2vDom)[n2]->point().z(),
              1.0,1.0,1.0);
            SVector3 d0(directions[9*n0+0],directions[9*n0+1],directions[9*n0+2]);
            SVector3 d1(directions[9*n1+0],directions[9*n1+1],directions[9*n1+2]);
            SVector3 d2(directions[9*n2+0],directions[9*n2+1],directions[9*n2+2]);

            double ub, vb, wb;
            barycentric(SPoint3(x), (*fO->c2vDom)[n0]->point(), (*fO->c2vDom)[n1]->point(), (*fO->c2vDom)[n2]->point(), ub, vb, wb);
            // SVector3 avg = d0 * (1.-uvw[0]-uvw[1]) + d1 * uvw[0] + d2 * uvw[1];
            SVector3 avg = d0 * ub + d1 * vb + d2 * wb;

            SVector3 v = crossprod(avg,SVector3(0.,0.,1.));
            // Check interpolated direction is unit
            if(avg.norm() > 1e-6 && v.norm() > 1e-6){
              avg.normalize();
              v.normalize();
            }
            if(fabs(avg.norm() - 1.) > 1e-2 || fabs(v.norm() - 1.) > 1e-2){
              Msg::Error("Moyenne non unitaire : avg.norm = %4.4e - v.norm = %4.4e\n", avg.norm(), v.norm());
              Msg::Exit(1);
            }
            for(size_t i = 0; i < 3; ++i){
              directions[9*iNode+i]   = avg[i];
              directions[9*iNode+3+i] = v[i];
            }
            // }

            directions[9*iNode+6] = 0.;
            directions[9*iNode+7] = 0.;
            directions[9*iNode+8] = 1.;
            
            isSet = true;
            // Msg::Info("Directions initialized at floating node %d\n", iNode);
          }
        }
        if(!isSet){
          Msg::Warning("Directions at floating node %d were not initialized : node is not inside any triangle\n", iNode);
        }
      }
    }
    fprintf(myfile3,"};"); fclose(myfile3);

    // Lift the directions (part2)
    uint32_t current = (*fO->v2cDom)[(*fO->c2vBnd)[0]];
    // std::vector<bool> visited(meshDom->vertices.num,false);
    std::list<uint32_t> q;
    // visited[current] = true;
    for(size_t i = 0; i < meshBnd->vertices.num; ++i){
      q.push_back((*fO->v2cDom)[(*fO->c2vBnd)[i]]);
    }
    std::list<uint32_t>::iterator i;
    
    while(!q.empty()){
      current = q.front();
      q.pop_front();
      for (i = adj[current].begin(); i != adj[current].end(); ++i){
        if(!isBoundaryCondition[*i]){
          // Adjust directions numbering
          SVector3    dir0(directions[9*(*i)+0],   directions[9*(*i)+1],   directions[9*(*i)+2]);
          SVector3 dir0ref(directions[9*current+0],directions[9*current+1],directions[9*current+2]);
          SVector3 dir1ref(directions[9*current+3],directions[9*current+4],directions[9*current+5]);
          if(fabs(dot(dir0,dir1ref)) > fabs(dot(dir0,dir0ref))){
            SVector3 dir1(directions[9*(*i)+3],directions[9*(*i)+4],directions[9*(*i)+5]);
            directions[9*(*i)+0] = dir1[0];
            directions[9*(*i)+1] = dir1[1];
            directions[9*(*i)+2] = dir1[2];
            directions[9*(*i)+3] = dir0[0];
            directions[9*(*i)+4] = dir0[1];
            directions[9*(*i)+5] = dir0[2];
          }
          isBoundaryCondition[*i] = true;
          q.push_back(*i);
        }
      }
    }

    // Be super duper sure it's normalized
    for(size_t i = 0; i < meshDom->vertices.num; ++i){
      for(size_t j = 0; j < 2; ++j){
        SVector3 d(directions[9*i+3*j+0],directions[9*i+3*j+1],directions[9*i+3*j+2]);
        if( fabs(d.norm() - 1.) > 1e-5){
          Msg::Error("Direction non unitaire : d.norm = %4.4e\n", d.norm());
        }
      }
    }

    for(size_t i = 0; i < meshDom->vertices.num; ++i){
      double *x = meshDom->vertices.coord + 4*i;
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], 0.5*directions[9*i+0], 0.5*directions[9*i+1], 0.5*directions[9*i+2]);
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-0.5*directions[9*i+0],-0.5*directions[9*i+1],-0.5*directions[9*i+2]);
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2], directions[9*i+3], directions[9*i+4], directions[9*i+5]);
      fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",x[0],x[1],x[2],-directions[9*i+3],-directions[9*i+4],-directions[9*i+5]);
    }
#endif
  }

  fprintf(myfile,"};"); fclose(myfile);

  // HXT_CHECK(hxtOr3DWritePosCrossesFromFrames(meshDom, frames, "myFramesBeforeSolve.pos", NULL));

  printf("Marking intersecting octants and their neighbors...\n");
  // p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, NULL, markPlanarCells, NULL, NULL);
  printf("Done\n");
  // printf("Drawing...\n");
  // HXT_CHECK(forestExport(forest, "foo.pos"));
  // printf("Done\n");
  printf("Transferring directions to the octree...\n");
  p4est_iterate(forest->p4est, NULL, (void*) forest->forestOptions, assignDirectionsCallback, NULL, NULL, NULL);
  printf("Done\n");

  return HXT_STATUS_OK;
}
#endif

/* ========================================================================================================
   SEARCH AND REPLACE
   ========================================================================================================
 */

static int searchAndAssignConstant(p4est_t *p4est, p4est_topidx_t which_tree,
                                   p4est_quadrant_t *q,
                                   p4est_locidx_t local_num, void *point)
{
  bool in_box, is_leaf = local_num >= 0;
  size_data_t *data = (size_data_t *)q->p.user_data;
  size_point_t *p = (size_point_t *)point;
  ForestOptions *forestOptions = (ForestOptions *)p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants
  // because it seems to be undefined. Otherwise it's contained in
  // q->p.user_data.
  double h, center[3];
  if(!is_leaf)
    getCellSize(p4est, which_tree, q, &h);
  else
    h = data->h;
  getCellCenter(p4est, which_tree, q, center);

  // double epsilon = 1e-13;
  // in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. -
  // epsilon); in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y >
  // center[1] - h/2. - epsilon); in_box &= (p->z < center[2] + h/2. + epsilon)
  // && (p->z > center[2] - h/2. - epsilon);
  in_box = (p->x <= center[0] + h / 2.) && (p->x >= center[0] - h / 2.);
  in_box &= (p->y <= center[1] + h / 2.) && (p->y >= center[1] - h / 2.);
  in_box &= (p->z <= center[2] + h / 2.) && (p->z >= center[2] - h / 2.);

  // A point can be on the exact boundary of two cells, hence we take the min.
  if(in_box && is_leaf){
    p->size = fmin(p->size, data->size[0]);
    p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
    p->isFound = true;
  }

  return in_box;
}

static int searchAndAssignConstantAniso(p4est_t *p4est,
                                        p4est_topidx_t which_tree,
                                        p4est_quadrant_t *q,
                                        p4est_locidx_t local_num, void *point)
{
  bool in_box, is_leaf = local_num >= 0;
  size_data_t *data = (size_data_t *)q->p.user_data;
  size_point_t *p = (size_point_t *)point;
  // ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants
  // because it seems to be undefined. Otherwise it's contained in
  // q->p.user_data.
  double h, center[3];
  if(!is_leaf)
    getCellSize(p4est, which_tree, q, &h);
  else
    h = data->h;
  getCellCenter(p4est, which_tree, q, center);

  // double epsilon = 1e-13;
  // in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. - epsilon);
  // in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y > center[1] - h/2. - epsilon);
  // in_box &= (p->z < center[2] + h/2. + epsilon) && (p->z > center[2] - h/2. - epsilon);
  in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
  in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
  in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

  if(in_box && is_leaf){
    // p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
    p->m = data->M;
    // p->m = SMetric3(1.0);
    // p->m.print("p->m");
    p->isFound = true;
  }

  return in_box;
}

static int searchAndAssignLinearAniso(p4est_t *p4est,
                                      p4est_topidx_t which_tree,
                                      p4est_quadrant_t *q,
                                      p4est_locidx_t local_num, void *point)
{
  bool in_box, is_leaf = local_num >= 0;
  size_data_t *data = (size_data_t *)q->p.user_data;
  size_point_t *p = (size_point_t *)point;
  ForestOptions *fO = (ForestOptions *) p4est->user_pointer;
  double h, center[3];
  if(!is_leaf)
    getCellSize(p4est, which_tree, q, &h);
  else
    h = data->h;
  getCellCenter(p4est, which_tree, q, center);

  double eps = 1e-12;
  in_box  = (p->x <= center[0] + h/2. + eps) && (p->x >= center[0] - h/2. - eps);
  in_box &= (p->y <= center[1] + h/2. + eps) && (p->y >= center[1] - h/2. - eps);
  in_box &= (p->z <= center[2] + h/2. + eps) && (p->z >= center[2] - h/2. - eps);

  if(in_box && is_leaf){
    // if(fO->dim == 2){
      double *dC = data->dirCorner;
      // SMetric3 m1(1.0,1.0,1.0,SVector3(dC[0] ,dC[1] ,dC[2] ),SVector3(dC[3] ,dC[4] ,dC[5] ),SVector3(dC[6] ,dC[7] ,dC[8] ));
      // SMetric3 m2(1.0,1.0,1.0,SVector3(dC[9] ,dC[10],dC[11]),SVector3(dC[12],dC[13],dC[14]),SVector3(dC[15],dC[16],dC[17]));
      // SMetric3 m3(1.0,1.0,1.0,SVector3(dC[18],dC[19],dC[20]),SVector3(dC[21],dC[22],dC[23]),SVector3(dC[24],dC[25],dC[26]));
      // SMetric3 m4(1.0,1.0,1.0,SVector3(dC[27],dC[28],dC[29]),SVector3(dC[30],dC[31],dC[32]),SVector3(dC[33],dC[34],dC[35]));
      double t1 = fmin(atan2(-dC[1] ,-dC[0] ), atan2(dC[1] ,dC[0] )); // Angle associated to e1 at corner 1 ( 1, 1)
      double t2 = fmin(atan2(-dC[10],-dC[9] ), atan2(dC[10],dC[9] )); // Angle associated to e1 at corner 2 ( 1,-1)
      double t3 = fmin(atan2(-dC[19],-dC[18]), atan2(dC[19],dC[18])); // Angle associated to e1 at corner 3 (-1,-1)
      double t4 = fmin(atan2(-dC[28],-dC[27]), atan2(dC[28],dC[27])); // Angle associated to e1 at corner 4 (-1, 1)

      double xsi = 2.*(p->x-center[0])/h;
      double eta = 2.*(p->y-center[1])/h;

      double cI = (1+xsi)*(1+eta)/4. * cos(t1) + (1+xsi)*(1-eta)/4. * cos(t2) + (1-xsi)*(1-eta)/4. * cos(t3) + (1-xsi)*(1+eta)/4. * cos(t4);
      double sI = (1+xsi)*(1+eta)/4. * sin(t1) + (1+xsi)*(1-eta)/4. * sin(t2) + (1-xsi)*(1-eta)/4. * sin(t3) + (1-xsi)*(1+eta)/4. * sin(t4);
      double tI = atan2(sI,cI);

      SVector3 v0(cos(tI),sin(tI),0.);
      SVector3  n(     0.,     0.,1.);
      SVector3 v1 = crossprod(v0, n);

      double h0 = data->size[0] + data->ds[0]*(p->x-center[0]) + data->ds[1]*(p->y-center[1]); // + data->ds[2]*(p->z-center[2]);
      double h1 = data->size[1] + data->ds[3]*(p->x-center[0]) + data->ds[4]*(p->y-center[1]); // + data->ds[5]*(p->z-center[2]);
      SMetric3 m(1.0/(h0*h0), 1.0/(h1*h1), 1.0, v0, v1, n);
      p->m = m;
      p->isFound = true;
    // }
  }

  return in_box;
}

static int searchAndAssignLinear(p4est_t *p4est, p4est_topidx_t which_tree,
                                 p4est_quadrant_t *q, p4est_locidx_t local_num,
                                 void *point)
{
  bool in_box = false, is_leaf = local_num >= 0;
  size_data_t *data = (size_data_t *)q->p.user_data;
  size_point_t *p = (size_point_t *)point;
  ForestOptions *forestOptions = (ForestOptions *)p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants
  // because it seems to be undefined. Otherwise it's contained in
  // q->p.user_data.
  double h, center[3];
  // if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
  // else h = data->h;
  getCellSize(p4est, which_tree, q, &h);
  getCellCenter(p4est, which_tree, q, center);

  double epsilon = 1e-10;
  // in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. -
  // epsilon); in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y >
  // center[1] - h/2. - epsilon); in_box &= (p->z < center[2] + h/2. + epsilon)
  // && (p->z > center[2] - h/2. - epsilon);

  // This misses some points...
  // in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
  // in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
  // in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

  SPoint3 C(center), P(p->x, p->y, p->z);
  SVector3 dir(C, P);
  SVector3 dx(1., 0., 0.);
  SVector3 dy(0., 1., 0.);
  SVector3 dz(0., 0., 1.);

  in_box = fabs(dot(dir, dx)) <= (h / 2. + epsilon) &&
           fabs(dot(dir, dy)) <= (h / 2. + epsilon) &&
           fabs(dot(dir, dz)) <= (h / 2. + epsilon);

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
  //   printf("h = %4.16e, center = (%4.16e, %4.16e, %4.16e)\n", h, center[0],
  //   center[1], center[2]); printf("%4.16e <= x <= %4.16e (%d)\n",
  //   center[0]-h/2., center[0]+h/2., (p->x <= center[0] + h/2.) && (p->x >=
  //   center[0] - h/2.) ); printf("%4.16e <= y <= %4.16e (%d)\n",
  //   center[1]-h/2., center[1]+h/2., (p->y <= center[1] + h/2.) && (p->y >=
  //   center[1] - h/2.) ); printf("%4.16e <= z <= %4.16e (%d)\n",
  //   center[2]-h/2., center[2]+h/2., (p->z <= center[2] + h/2.) && (p->z >=
  //   center[2] - h/2.) );
  // }

  return in_box;
}

// static int replace(p4est_t * p4est, p4est_topidx_t which_tree,
// p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
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
HXTStatus forestSearchOne(Forest *forest, double x, double y, double z,
                          double *size, int linear)
{
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), 1);

  size_point_t *p = (size_point_t *)sc_array_index(points, 0);
  p->x = x;
  p->y = y;
  p->z = z;
  p->size = 1.0e22;
  p->isFound = false;
  p->parcourus = 0;

  if(linear) {
    p4est_search(forest->p4est, NULL, searchAndAssignLinear, points);
  }
  else {
    p4est_search(forest->p4est, NULL, searchAndAssignConstant, points);
  }

  if(!p->isFound) {
    Msg::Info("(%+.4f,%+.4f,%+.4f) was not found in the meshsize field 8-|", x,
              y, z);
    Msg::Info("Octants parcourus : %d\n", p->parcourus);
  }
  *size = p->size;

  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

HXTStatus forestSearchOneAniso(Forest *forest, double x, double y, double z,
                               SMetric3 &m, int linear)
{
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), 1);

  size_point_t *p = (size_point_t *)sc_array_index(points, 0);
  p->x = x;
  p->y = y;
  p->z = z;
  p->m = SMetric3(1.0);
  p->isFound = false;

  // p4est_search(forest->p4est, nullptr, searchAndAssignConstantAniso, points);
  if(linear) {
    p4est_search(forest->p4est, NULL, searchAndAssignLinearAniso, points);
  }
  else {
    p4est_search(forest->p4est, NULL, searchAndAssignConstantAniso, points);
  }

  if(!p->isFound)
    Msg::Info("Point (%f,%f,%f) n'a pas été trouvé dans l'octree 8-|", x, y, z);
  else
    m = p->m;

  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

// Not finished
HXTStatus hxtForestSearch(Forest *forest, std::vector<double> *x,
                          std::vector<double> *y, std::vector<double> *z,
                          std::vector<double> *size)
{
  // Array of size_point_t to search in the tree
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), (*x).size());
  size_point_t *p;

  for(size_t i = 0; i < (*x).size(); ++i) {
    p = (size_point_t *)sc_array_index(points, i);
    p->x = (*x)[i];
    p->y = (*y)[i];
    p->z = (*z)[i];
    p->size = -1.0;
  }

  // Search on all cells
  p4est_search(forest->p4est, nullptr, searchAndAssignLinear, points);

  // Get the sizes
  for(size_t i = 0; i < (*x).size(); ++i) {
    p = (size_point_t *)sc_array_index(points, i);
    (*size)[i] = p->size;
  }

  // Clean up
  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   CLOSE SURFACES DETECTION
   ========================================================================================================
 */

// To quickly sort 3 integers
static void sort3(int *d){
#define SWAP(x, y)                                                             \
  if(d[y] < d[x]) {                                                            \
    int tmp = d[x];                                                            \
    d[x] = d[y];                                                               \
    d[y] = tmp;                                                                \
  }
  SWAP(0, 1);
  SWAP(1, 2);
  SWAP(0, 1);
#undef SWAP
}

// To quickly sort 4 integers
static void sort4(int *d)
{
#define SWAP(x, y)                                                             \
  if(d[y] < d[x]) {                                                            \
    int tmp = d[x];                                                            \
    d[x] = d[y];                                                               \
    d[y] = tmp;                                                                \
  }
  SWAP(0, 1);
  SWAP(2, 3);
  SWAP(0, 2);
  SWAP(1, 3);
  SWAP(1, 2);
#undef SWAP
}

// Checks whether two MTetrahedra have a common face without creating MFaces
// (slow) Returns the index of the common face in t1 if any, -1 otherwise
static int commonFaceTetFast(MTetrahedron *t1, MTetrahedron *t2)
{
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

  if(b0 + b1 + b2 + b3 < 3) { return -1; }
  else {
    int v1[4] = {t10, t11, t12, t13};
    int v1cpy[4] = {t10, t11, t12, t13};
    int v2[4] = {t20, t21, t22, t23};
    sort4(v1);
    sort4(v2);
    t10 = v1[0];
    t11 = v1[1];
    t12 = v1[2];
    t13 = v1[3];
    t20 = v2[0];
    t21 = v2[1];
    t22 = v2[2];
    t23 = v2[3];

    bool b00 = (t11 == t21) && (t12 == t22) && (t13 == t23);
    bool b01 = (t11 == t20) && (t12 == t22) && (t13 == t23);
    bool b02 = (t11 == t20) && (t12 == t21) && (t13 == t23);
    bool b03 = (t11 == t20) && (t12 == t21) && (t13 == t22);

    bool b10 = (t10 == t21) && (t12 == t22) && (t13 == t23);
    bool b11 = (t10 == t20) && (t12 == t22) && (t13 == t23);
    bool b12 = (t10 == t20) && (t12 == t21) && (t13 == t23);
    bool b13 = (t10 == t20) && (t12 == t21) && (t13 == t22);

    bool b20 = (t10 == t21) && (t11 == t22) && (t12 == t23);
    bool b21 = (t10 == t20) && (t11 == t22) && (t12 == t23);
    bool b22 = (t10 == t20) && (t11 == t21) && (t12 == t23);
    bool b23 = (t10 == t20) && (t11 == t21) && (t12 == t22);

    bool b30 = (t10 == t21) && (t11 == t22) && (t13 == t23);
    bool b31 = (t10 == t20) && (t11 == t22) && (t13 == t23);
    bool b32 = (t10 == t20) && (t11 == t21) && (t13 == t23);
    bool b33 = (t10 == t20) && (t11 == t21) && (t13 == t22);

    int missing = -1; // The vertex that is missing from the common face
    if(b00 || b01 || b02 || b03)
      missing = 0; // return 3;
    else if(b10 || b11 || b12 || b13)
      missing = 1; // return 2;
    else if(b20 || b21 || b22 || b23)
      missing = 3; // return 0;
    else if(b30 || b31 || b32 || b33)
      missing = 2; // return 1;

    if(missing >= 0) {
      if(v1cpy[0] == v1[missing])
        return 3;
      else if(v1cpy[1] == v1[missing])
        return 2;
      else if(v1cpy[2] == v1[missing])
        return 1;
      else if(v1cpy[3] == v1[missing])
        return 0;
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
static bool sortClockwise(SPoint3 a, SPoint3 b, SPoint3 center, SVector3 normal)
{
  // If dot(n, cross(A-C, B-C)) is positive, B is counterclockwise from A; if
  // it's negative, B is clockwise from A.
  SVector3 tmp = crossprod(SVector3(center, a), SVector3(center, b));
  return dot(normal, tmp) <= 0;
}

// Computes the medial axis of the geometry and assigns the feature size at vertices
HXTStatus featureSize(Forest* forest){

  HXTMesh *meshBnd   = forest->forestOptions->mesh2D;
  int nLayersPerGap = forest->forestOptions->nodePerGap;
  double hmin = forest->forestOptions->hmin;
  double hmax = forest->forestOptions->hmax;

  // std::vector<MVertex*> allVertices;
  std::vector<double> sizeAtVertices(meshBnd->vertices.num, DBL_MAX);
  // for(size_t i = 0; i < meshBnd->vertices.num; ++i){
  //   allVertices.push_back(new MVertex(meshBnd->vertices.coord[4*i+0],
  //                                     meshBnd->vertices.coord[4*i+1],
  //                                     meshBnd->vertices.coord[4*i+2]));
  // }

  // int firstVertex = allVertices[0]->getNum();

  // All tets
  std::vector<MTetrahedron*> allTets;
  std::vector<std::set<uint64_t>> tetIncidents(meshBnd->vertices.num);
  std::vector<std::set<MEdge,MEdgeLessThan>> edgIncidents(meshBnd->vertices.num);

  // The empty mesh is stored in meshBnd, so it does have tets
  uint64_t count = 0;
  for(size_t i = 0; i < meshBnd->tetrahedra.num; ++i){
    if(meshBnd->tetrahedra.node[4*i+3] != HXT_GHOST_VERTEX){
      allTets.push_back(new MTetrahedron((*forest->forestOptions->c2vBnd)[ meshBnd->tetrahedra.node[4*i+0] ],
                                         (*forest->forestOptions->c2vBnd)[ meshBnd->tetrahedra.node[4*i+1] ],
                                         (*forest->forestOptions->c2vBnd)[ meshBnd->tetrahedra.node[4*i+2] ],
                                         (*forest->forestOptions->c2vBnd)[ meshBnd->tetrahedra.node[4*i+3] ]) );

      for(size_t j = 0; j < 4; ++j){
        // tetIncidents[ meshBnd->tetrahedra.node[4*i+j] ].push_back(count);
        tetIncidents[ meshBnd->tetrahedra.node[4*i+j] ].insert(count);
      }
      for(size_t j = 0; j < 6; ++j) {
        MEdge e = allTets[count]->getEdge(j);
        // TODO : fix this with v2c
        // edgIncidents[allTets[count]->getEdge(j).getVertex(0)->getNum() - firstVertex].push_back(e);
        // edgIncidents[allTets[count]->getEdge(j).getVertex(1)->getNum() - firstVertex].push_back(e);
        edgIncidents[ (*forest->forestOptions->v2cBnd)[e.getVertex(0)] ].insert(e);
        edgIncidents[ (*forest->forestOptions->v2cBnd)[e.getVertex(1)] ].insert(e);
      }

      ++count;
    }
  }

  std::set<MEdge, MEdgeLessThan> axis;
  int elemDrawn = 0;

  FILE *file = fopen("medialAxis_toDraw.pos", "w");
  if(file == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  FILE *file2 = fopen("keptEdges.pos", "w");
  if(file2 == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  bool draw = true;
  if(draw) {
    fprintf(file, "View \"medialAxis\" {\n");
    fprintf(file2, "View \"keptEdges\" {\n");
  }

  int indFace;

  for(size_t i = 0; i < meshBnd->vertices.num; ++i){
    // Pôle de p : circumcenter le plus loin parmi les tets incidents à p
    SPoint3 pole(0.,0.,0.),
             tmp(0.,0.,0.),
               p(meshBnd->vertices.coord[4*i+0], meshBnd->vertices.coord[4*i+1], meshBnd->vertices.coord[4*i+2]);
    double d = 0.;

    // for(size_t j = 0; j < tetIncidents[i].size(); ++j) {
    for(auto const &tet : tetIncidents[i]){
      // tmp = allTets[tetIncidents[i][j]]->circumcenter();
      tmp = allTets[tet]->circumcenter();
      if(p.distance(tmp) > d) pole = tmp;
      d = fmax(d, p.distance(tmp));
    }

    // Pole vector
    SPoint3 vp = pole - p;
    double D = -(vp[0] * p[0] + vp[1] * p[1] + vp[2] * p[2]);
    SPoint3 p1(
      0., 0.,
      -D / vp[2]); // 2 points sur le plan qui passe par p et de normale vp
    SPoint3 p2(0., -D / vp[1], 0.);

    std::vector<MFace> up; // umbrella
    // Boucle sur les voronoi edges (paires de centres)
    double orientj, orientk;
    // for(size_t j = 0; j < tetIncidents[i].size(); ++j) {
    for(auto const &tetj : tetIncidents[i]) {
      // uint64_t tetj = tetIncidents[i][j];
      SPoint3 cj = allTets[tetj]->circumcenter();
      // for(size_t k = j; k < tetIncidents[i].size(); ++k) {
      for(auto const &tetk : tetIncidents[i]) {
        // uint64_t tetk = tetIncidents[i][k];
        if(tetj != tetk) {
          indFace = commonFaceTetFast(allTets[tetj], allTets[tetk]);
          if(indFace >= 0) {
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
      // uint32_t v0 = e.getVertex(0)->getNum() - firstVertex;
      // uint32_t v1 = e.getVertex(1)->getNum() - firstVertex;
      uint32_t v0 = (*forest->forestOptions->v2cBnd)[e.getVertex(0)];
      uint32_t v1 = (*forest->forestOptions->v2cBnd)[e.getVertex(1)];
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
                // for(size_t jj = 0; jj < tetIncidents[i].size(); ++jj){
                for(auto const &tetj : tetIncidents[i]){
                  // uint64_t tetj = tetIncidents[i][jj];
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
    fprintf(file, "};"); fclose(file);
    fprintf(file2, "};"); fclose(file2);
  }

  for(size_t i = 0; i < meshBnd->vertices.num; ++i){
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

  std::vector<MTriangle*> allTris;
  std::vector<std::set<uint64_t>> triIncidents(meshBnd->vertices.num);
  std::vector<std::set<MEdge,MEdgeLessThan>> edgIncidents(meshBnd->vertices.num);

  // The empty mesh is stored in meshBnd, so it does have triangles
  uint64_t count = 0;
  for(size_t i = 0; i < meshBnd->triangles.num; ++i){
      allTris.push_back(new MTriangle((*forest->forestOptions->c2vBnd)[ meshBnd->triangles.node[3*i+0] ],
                                      (*forest->forestOptions->c2vBnd)[ meshBnd->triangles.node[3*i+1] ],
                                      (*forest->forestOptions->c2vBnd)[ meshBnd->triangles.node[3*i+2] ]));

      for(size_t j = 0; j < 3; ++j){
        triIncidents[ meshBnd->triangles.node[3*i+j] ].insert(count);
        MEdge e = allTris[count]->getEdge(j);
        edgIncidents[ (*forest->forestOptions->v2cBnd)[e.getVertex(0)] ].insert(e);
        edgIncidents[ (*forest->forestOptions->v2cBnd)[e.getVertex(1)] ].insert(e);
      }
      ++count;
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

    SPoint3 vp = pole - p; // Pole vector
    double a = (p[0] - pole[0])/(pole[1] - p[1]); // Equation of the line perpendicular to vp passing through p
    double b = p[1] - a*p[0];
    SPoint3 p1(0., b, 0.); // Another point on this line

    std::vector<MEdge> up; // umbrella
    // Boucle sur les voronoi edges (paires de centres)
    double orientj, orientk;
    for(auto const &trij : triIncidents[i]){
      SPoint3 cj = allTris[trij]->circumcenter();
      for(auto const &trik : triIncidents[i]){
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

    double theta = M_PI/8., rho = 8., maxAngle, minRatio, localAngle, alpha0, alpha1;
    std::vector<MEdge> checkedEdges;
    bool checked;
    for(auto const &e : edgIncidents[i]){ // boucler sur les aretes incidentes à p
      checked = false;
      for(size_t k = 0; k < checkedEdges.size(); ++k) {
        if(e == checkedEdges[k]) {
          checked = true;
          break;
        }
      }

      if(checked) { continue; }
      else {
        checkedEdges.push_back(e);
      }

      maxAngle = 0.0;
      minRatio = DBL_MAX;

      uint32_t v0 = (*forest->forestOptions->v2cBnd)[e.getVertex(0)];
      uint32_t v1 = (*forest->forestOptions->v2cBnd)[e.getVertex(1)];
      if(v0 == i || v1 == i) {
        for(size_t l = 0; l < up.size(); ++l) {
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

        if(maxAngle < M_PI / 2. - theta || minRatio > rho) {
          double *n0 = forest->forestOptions->nodeNormals + 3 * v0;
          double *n1 = forest->forestOptions->nodeNormals + 3 * v1;
          alpha0 = angle(SVector3(n0), e.tangent());
          alpha1 = angle(SVector3(n1), e.tangent());

          if(fmin(alpha0, fabs(M_PI - alpha0)) < M_PI / 8. &&
             fmin(alpha1, fabs(M_PI - alpha1)) < M_PI / 8.) {
            // Add edge to the set (axis, though actually unused), modifiy size at its extrmities and draw the dual facet
            auto ret = axis.insert(e);

            if(ret.second) {
              double h = e.length() / nLayersPerGap;
              h = fmax(h, hmin);
              h = fmin(h, hmax);
              sizeAtVertices[v0] = fmin(h, sizeAtVertices[v0]);
              sizeAtVertices[v1] = fmin(h, sizeAtVertices[v1]);

              fprintf(file2, "SL(%f,%f,%f, %f,%f,%f){%2.4e,%2.4e};\n",
                      e.getVertex(0)->x(), e.getVertex(0)->y(), e.getVertex(0)->z(),
                      e.getVertex(1)->x(), e.getVertex(1)->y(), e.getVertex(1)->z(),
                      10.0,10.0);

              if(draw) {
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
          } // if edges does not have a too large angle with normals to its
            // extremities
        } // if edge passes conditions
      } // if i is an edge vertex
    } // for incident edges
  } // for vertices.num

  if(draw) {
    fprintf(file, "};");  fclose(file);
    fprintf(file2, "};"); fclose(file2);
  }

  for(size_t i = 0; i < meshBnd->vertices.num; ++i){
    (*forest->forestOptions->featureSizeAtVertices)[i] = sizeAtVertices[i];
  }

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   ESTIMATE NUMBER OF TETRAHEDRA IN THE VOLUME MESH
   ========================================================================================================
 */

static void elementEstimate(p4est_iter_volume_info_t *info, void *user_data)
{
  p4est_quadrant_t *q = info->quad;
  size_data_t *data = (size_data_t *)q->p.user_data;
  p4est_t *p4est = info->p4est;
  p4est_topidx_t which_tree = info->treeid;

  double center[3];
  getCellCenter(p4est, which_tree, q, center);

  double octantVolume = data->h * data->h * data->h;
  double tetVolume = data->size[0] * data->size[0] * data->size[0] * sqrt(2) / 12.0;

  *((double *)user_data) += octantVolume / tetVolume;
}

HXTStatus hxtOctreeElementEstimation(Forest *forest, double *elemEstimate)
{
  p4est_iterate(forest->p4est, nullptr, (void *)elemEstimate, elementEstimate, nullptr, nullptr, nullptr);
  return HXT_STATUS_OK;
}

/* ========================================================================================================
   EXPORT
   ========================================================================================================
 */

HXTStatus saveGlobalData(Forest *forest, const char *filename)
{
  FILE *f = fopen(filename, "w");
  if(f == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  fprintf(f, "%f %f\n", forest->forestOptions->hmin,
          forest->forestOptions->hmax);
  fclose(f);
  Msg::Info("Writing global size field data in %s", filename);
  return HXT_STATUS_OK;
}

static void exportToHexCallback(p4est_iter_volume_info_t *info, void *user_data)
{
  p4est_quadrant_t *q = info->quad;
  size_data_t *data = (size_data_t *)q->p.user_data;
  p4est_t *p4est = info->p4est;
  p4est_topidx_t which_tree = info->treeid;

  FILE *f = (FILE *)user_data;
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
  //   data->hasIntersection, data->hasIntersection, data->hasIntersection,
  //   data->hasIntersection, data->hasIntersection, data->hasIntersection,
  //   data->hasIntersection, data->hasIntersection);
}

static void exportToCrossesAnisoCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  if(data->isPlanar){
  // if(fabs(data->c[2]) <= data->h/2. && data->c[2] >= 0.){

  FILE* f = (FILE*) user_data;
  double center[3], x[8], y[8], z[8];
  getCellCenter(p4est, which_tree, q, center);
  double h = data->h/2.0, epsilon = 1e-12, s = 1.0; //data->size[0];
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

  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[0], y[0], z[0], x[1], y[1], z[1], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[2], y[2], z[2], x[1], y[1], z[1], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[2], y[2], z[2], x[3], y[3], z[3], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[0], y[0], z[0], x[3], y[3], z[3], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[0], y[0], z[0], x[4], y[4], z[4], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[1], y[1], z[1], x[5], y[5], z[5], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[2], y[2], z[2], x[6], y[6], z[6], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[3], y[3], z[3], x[7], y[7], z[7], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[4], y[4], z[4], x[5], y[5], z[5], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[6], y[6], z[6], x[5], y[5], z[5], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[6], y[6], z[6], x[7], y[7], z[7], s, s);
  fprintf(f, "SL(%f,%f,%f, %f,%f,%f){%f,%f};\n", x[4], y[4], z[4], x[7], y[7], z[7], s, s);

  double dir[9]={data->dir[0], data->dir[1], data->dir[2],
                 data->dir[3], data->dir[4], data->dir[5],
                 data->dir[6], data->dir[7], data->dir[8]};

  for (int j = 0; j < 2; ++j) {
    double d[3] = {dir[3*j+0], dir[3*j+1], dir[3*j+2]};
    // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2], data->size[j]*d[0], data->size[j]*d[1], data->size[j]*d[2]);
    // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2],-data->size[j]*d[0],-data->size[j]*d[1],-data->size[j]*d[2]);
    if(j==1){
      // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2], 0.5*d[0], 0.5*d[1], 0.5*d[2]);
      fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2], data->size[j]*d[0], data->size[j]*d[1], data->size[j]*d[2]);
      // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2],-0.5*d[0],-0.5*d[1],-0.5*d[2]);
      fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2],-data->size[j]*d[0],-data->size[j]*d[1],-data->size[j]*d[2]);
    } else{
      // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2], d[0], d[1], d[2]);
      fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2], data->size[j]*d[0], data->size[j]*d[1], data->size[j]*d[2]);
      // fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2],-d[0],-d[1],-d[2]);
      fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",center[0],center[1],center[2],-data->size[j]*d[0],-data->size[j]*d[1],-data->size[j]*d[2]);
    }
  }

  // Directions at corners
  double cooCorner[12] = {center[0] + h, center[1] + h, 0.,
                          center[0] + h, center[1] - h, 0.,
                          center[0] - h, center[1] - h, 0.,
                          center[0] - h, center[1] + h, 0.,};
  for(int iC = 0; iC < 4; ++iC){
    double *coo = cooCorner+3*iC;
    for (int j = 0; j < 2; ++j) {
      double d[3] = {data->dirCorner[9*iC+3*j+0], data->dirCorner[9*iC+3*j+1], data->dirCorner[9*iC+3*j+2]};
      if(j==1){
        fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",coo[0],coo[1],coo[2], 0.5*d[0], 0.5*d[1], 0.5*d[2]);
        fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",coo[0],coo[1],coo[2],-0.5*d[0],-0.5*d[1],-0.5*d[2]);
      } else{
        fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",coo[0],coo[1],coo[2], d[0], d[1], d[2]);
        fprintf(f,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",coo[0],coo[1],coo[2],-d[0],-d[1],-d[2]);
      }
    }
  }

  }
}

static void exportToFramesAnisoCallback(p4est_iter_volume_info_t * info, void *user_data){
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

static void exporth1ToQuadCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;
  FILE *f = (FILE *)user_data;
  double center[3], x[8], y[8], z[8]; getCellCenter(p4est, which_tree, q, center);
  double h = data->h/2.0, s = data->size[0], epsilon = 1e-12;
  x[0] = x[3] = center[0]-h - epsilon; x[1] = x[2] = center[0]+h + epsilon;
  y[0] = y[1] = center[1]-h - epsilon; y[2] = y[3] = center[1]+h + epsilon;
  z[0] = z[1] = 0.0; z[2] = z[3] = 0.0;
  fprintf(f, "SQ(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3], s, s, s, s);
}

static void exporth2ToQuadCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;
  FILE *f = (FILE *)user_data;
  double center[3], x[8], y[8], z[8]; getCellCenter(p4est, which_tree, q, center);
  double h = data->h/2.0, s = data->size[1], epsilon = 1e-12;
  x[0] = x[3] = center[0]-h - epsilon; x[1] = x[2] = center[0]+h + epsilon;
  y[0] = y[1] = center[1]-h - epsilon; y[2] = y[3] = center[1]+h + epsilon;
  z[0] = z[1] = 0.0; z[2] = z[3] = 0.0;
  fprintf(f, "SQ(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3], s, s, s, s);
}

HXTStatus forestExport(Forest *forest, const char *forestFile)
{
  FILE *f = fopen(forestFile, "w");
  if(f == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  fprintf(f, "View \"sizeField\" {\n");

  FILE *f1, *f2;
  if(forest->forestOptions->aniso && forest->forestOptions->dim==2){
    f1 = fopen("h1_aniso.pos", "w"); if(f1 == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
    fprintf(f1, "View \"h1 aniso\" {\n");
    f2 = fopen("h2_aniso.pos", "w"); if(f2 == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
    fprintf(f2, "View \"h2 aniso\" {\n");
  }

  if(forest->forestOptions->aniso){
    if      (forest->forestOptions->dim == 3){ p4est_iterate(forest->p4est, NULL, (void*) f, exportToFramesAnisoCallback, NULL, NULL, NULL); }
    else if (forest->forestOptions->dim == 2){ 
      // Export the crosses
      p4est_iterate(forest->p4est, NULL, (void*) f, exportToCrossesAnisoCallback, NULL, NULL, NULL); 
      // Also export the scalar sizes in two different files
      p4est_iterate(forest->p4est, NULL, (void*) f1, exporth1ToQuadCallback, NULL, NULL, NULL); 
      p4est_iterate(forest->p4est, NULL, (void*) f2, exporth2ToQuadCallback, NULL, NULL, NULL); 
    }
  } else{
    if      (forest->forestOptions->dim == 3){ p4est_iterate(forest->p4est, NULL, (void*) f, exportToHexCallback, NULL, NULL, NULL);  }
    else if (forest->forestOptions->dim == 2){ p4est_iterate(forest->p4est, NULL, (void*) f, exporth1ToQuadCallback, NULL, NULL, NULL); }
  }

  fprintf(f, "};"); fclose(f);
  if(forest->forestOptions->aniso && forest->forestOptions->dim==2){
    fprintf(f1, "};"); fclose(f1);
    fprintf(f2, "};"); fclose(f2);
  }

  return HXT_STATUS_OK;
}

HXTStatus forestSave(Forest *forest, const char *forestFile,
                     const char *dataFile)
{
  HXT_CHECK(saveGlobalData(forest, dataFile));
  p4est_save_ext(forestFile, forest->p4est, true, false);
  return HXT_STATUS_OK;
}

HXTStatus forestWriteSolFile2D(Forest *forest, const char *solFile){
  FILE* f = fopen(solFile, "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  fprintf(f, "MeshVersionFormatted 1\n\n");
  fprintf(f, "Dimension 2\n\n");
  fprintf(f, "SolAtVertices\n");
  fprintf(f, "%d\n", forest->forestOptions->mesh3D->vertices.num);
  fprintf(f, "1 3\n");

  for(size_t i = 0; i < forest->forestOptions->mesh3D->vertices.num; ++i){
    double x = forest->forestOptions->mesh3D->vertices.coord[(size_t) 4*i+0];
    double y = forest->forestOptions->mesh3D->vertices.coord[(size_t) 4*i+1];
    double z = forest->forestOptions->mesh3D->vertices.coord[(size_t) 4*i+2];
    SMetric3 m;
    HXT_CHECK(forestSearchOneAniso(forest, x, y, z, m, true));
    fprintf(f, "%f %f %f\n", m(0,0), m(0,1), m(1,1));
  }

  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus forestWriteSolFile3DSurface(Forest *forest, const char *solFile){
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
    HXT_CHECK(forestSearchOneAniso(forest, x, y, z, m, true));
    fprintf(f, "%f %f %f %f %f %f\n", m(0,0), m(0,1), m(1,1), m(0,2), m(1,2), m(2,2));
  }

  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus forestWriteSolFile3DVolume(Forest *forest, const char *solFile){
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
    HXT_CHECK(forestSearchOneAniso(forest, x, y, z, m, true));
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
   ======================================================================================
 */

double automaticMeshSizeField::operator()(double X, double Y, double Z,
                                          GEntity *ge)
{
  double val = 1.e17;
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = forestSearchOne(forest, X, Y, Z, &val, true);
  if(s == HXT_STATUS_OK) { return val; }
  else
    Msg::Error("Cannot find point %g %g %g in the octree", X, Y, Z);
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST to use automaticMeshSizeField");
#endif
  return val;
}

void automaticMeshSizeField::operator()(double X, double Y, double Z,
                                        SMetric3 &m, GEntity *ge)
{
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = forestSearchOneAniso(forest, X, Y, Z, m, true);
  if(fabs(m.determinant()) < 1e-13)
    m = SMetric3();
  if (s != HXT_STATUS_OK) Msg::Error ("Cannot find point %g %g %g in the octree",X,Y,Z);
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST to use automaticMeshSizeField");
#endif
}

automaticMeshSizeField::~automaticMeshSizeField()
{
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  if(forest) forestDelete(&forest);
  if(forestOptions) forestOptionsDelete(&forestOptions);
#endif
}

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
HXTStatus automaticMeshSizeField::updateHXT()
{
  if(!updateNeeded) return HXT_STATUS_OK;

  if(forestOptions) HXT_CHECK(forestOptionsDelete(&forestOptions));
  if(forest) HXT_CHECK(forestDelete(&forest));

  updateNeeded = false;

  if(!_forestFile.empty()) {



    if(_nPointsPerGap == -2){
      Msg::Info("Loophole pour calculer la qualité\n");
      double gamma;
      std::vector<int> hist(100,0);
      // Evaluate gamma quality of the mesh
      std::vector<GFace*> faces;
      std::vector<GRegion*> regions;
      for(auto const &region : GModel::current()->getRegions()){
        regions.push_back(region);
      }
      std::vector<MTetrahedron*> allTets;
      for(auto const &r : regions){
        std::vector<MTetrahedron*> tets = r->tetrahedra;
        for(auto const &t : tets){
          gamma = t->gammaShapeMeasure();
          int ind = floor(gamma/ float (1.0/100.0));
          if(ind == 0){
            Msg::Info("gamma = %10.16e\n", gamma);
          }
          hist[ind]++;
        }
      }
      FILE* myfile = fopen("gamma.txt","w");
      for(int i = 0; i < 100; ++i){
        Msg::Info("hist[%d] = %d\n", i, hist[i]);
        fprintf(myfile, "%2.12f \t %d\n", double (i)/99.0, hist[i]);
      }
      fclose(myfile);
    }



    else{
    // Load .p4est file if given a valid file name
    Msg::Info("Loading size field from %s", _forestFile.c_str());
    HXT_CHECK(forestOptionsCreate(&forestOptions));
    size_t lastindex = _forestFile.find_last_of(".");
    std::string root = _forestFile.substr(0, lastindex);
    std::string forestFile = root + ".p4est";
    std::string dataFile = root + ".data";

    int dim = GModel::current()->getDim();
    HXTMesh *meshDom, *meshBnd;
    std::vector<MVertex *>        c2vDom, c2vBnd;
    std::map<MVertex *, uint32_t> v2cDom, v2cBnd;

    if(dim == 3){
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
    } else{ // dim = 2
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
      // HXT_CHECK(Gmsh2Hxt(faces, meshDom, v2cDom, c2vDom));
      HXT_CHECK(Gmsh2Hxt(faces, meshDom, v2cDom, c2vDom, GModel::current()));
      HXT_CHECK(Gmsh2Hxt(edges, meshBnd, v2cBnd, c2vBnd));
    }

    forestOptions->mesh3D = meshDom;
    forestOptions->mesh2D = meshBnd;

    HXT_CHECK(forestLoad(&forest, forestFile.c_str(), dataFile.c_str(), forestOptions));

    // Only evaluate size field at vertices (to remesh iteratively with mmg)
    if(_nPointsPerGap == -1){ // TODO : make this clean
      Msg::Info("Nombre de noeuds : %d\n", forestOptions->mesh3D->vertices.num);
      Msg::Info("Nombre de noeuds : %d\n", forest->forestOptions->mesh3D->vertices.num);
      // HXT_CHECK(forestWriteSolFile2D(forest, "metric.sol"));
      // HXT_CHECK(forestWriteSolFile3DSurface(forest, "metricBnd.sol"));
      HXT_CHECK(forestWriteSolFile3DVolume(forest, "metricDom.sol"));
    }
  }

  }
  else {
    // Compute the size field otherwise
    int dim = GModel::current()->getDim();

    HXT_CHECK(forestOptionsCreate(&forestOptions));

    Msg::Info("Gradation = %f\n", _gradation);
    Msg::Info("Node density = %d\n", _nPointsPerCircle);
    if(dim == 3) {
      if(_nPointsPerGap > 0) { 
        Msg::Info("Layers per gap = %d\n", _nPointsPerGap);
      } else { 
        Msg::Info("Layers per gap = %d : not detecting features.\n", _nPointsPerGap);
      }
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
      for(uint32_t i = 0; i < 6*meshBnd->vertices.num; ++i){
        nodalCurvature[i] = 0.0;
      }

      // Compute curvature of the faces
      for(auto const &face : faces) {
        HXTMesh *meshFace;
        HXT_CHECK(hxtMeshCreate(&meshFace));
        std::vector<GFace*> oneFace(1, face);
        std::map<MVertex *, uint32_t> v2cLoc;
        std::vector<MVertex *>        c2vLoc;
        // Gmsh2HxtLocal(oneFace, meshFace, v2cLoc, c2vLoc);
        Gmsh2Hxt(oneFace, meshFace, v2cLoc, c2vLoc);

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
      for(uint32_t i = 0; i < 3*meshBnd->vertices.num; ++i){
        nodeNormals[i] = 0.0;
      }

      // Same function but returns the normals
      // Must be called on the global structure for tris and nodes, not the ones based on each face
      CurvatureRusinkiewicz(tris, nodes, curv, nodeNormals);

      // Add bboxes of the surface mesh to rtree
      HXTBbox bbox_triangle;
      for(uint64_t i = 0; i < meshBnd->triangles.num; ++i){
        hxtBboxInit(&bbox_triangle);
        for(uint64_t j = 0; j < 3; ++j) {
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

      HXT_CHECK(Gmsh2Hxt(faces, meshDom, v2cDom, c2vDom, GModel::current()));
      HXT_CHECK(Gmsh2Hxt(edges, meshBnd, v2cBnd, c2vBnd));

      if(meshBnd->vertices.num == 0){
        Msg::Error("Boundary mesh is empty : can't compute a size field.");
        HXT_CHECK(hxtMeshDelete(&meshDom));
        HXT_CHECK(hxtMeshDelete(&meshBnd));
        Msg::Exit(1);
      }

      // Noeuds flottants (par exemple points de controle de NURBS)
      // int nVert = GModel::current()->getVertices().size();
      // Msg::Info("%d NOEUDS FLOTTANTS ?\n", nVert);
      // std::set<MVertex *> all;


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

      Msg::Info("Boundary mesh before emptyMesh :");
      Msg::Info("Nombre de noeuds : %d\n",  meshBnd->vertices.num);
      Msg::Info("Nombre de lignes : %lu\n", meshBnd->lines.num);
      Msg::Info("Nombre de triang : %lu\n", meshBnd->triangles.num);
      Msg::Info("Nombre de tetras : %lu\n", meshBnd->tetrahedra.num);

      // Get Delaunay triangulation (empty mesh) of the edges vertices
      HXT_CHECK(emptyMesh2D(meshBnd, "delaunayBnd.msh"));
      // HXT_CHECK(emptyMesh2D(meshDom, true , "delaunayDom.msh"));

      Msg::Info("Boundary mesh after emptyMesh :");
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
    if(_hbulk < 0 || _hmin < 0) {
      double L = -1.0;
      for(int i = 0; i < 3; ++i) {
        L = fmax(L, bbox_vertices[i + 3] - bbox_vertices[i]);
      }
      _hbulk < 0 ? _hbulk = L / 20. : _hbulk;
      _hmin < 0 ? _hmin = L / 4000. : _hmin;
      Msg::Info("Bulk size is set to %f", _hbulk);
      Msg::Info("Min  size is set to %f", _hmin);
    }

    if(_hmax < 0) _hmax = _hbulk;

    std::vector<double> sizeAtVertices(meshBnd->vertices.num, DBL_MAX);
    std::vector<std::array<double,9>> triangleDirections(meshDom->triangles.num);

    forestOptions->aniso = false; // TODO : maybe a command line option ?
    forestOptions->dim = dim;
    forestOptions->hmax = _hmax;
    forestOptions->hmin = _hmin;
    forestOptions->hbulk = _hbulk;
    forestOptions->gradation = _gradation;
    forestOptions->nodePerTwoPi = _nPointsPerCircle;
    forestOptions->nodePerGap = _nPointsPerGap;
    forestOptions->bbox = bbox_vertices; 
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
    forestOptions->v2cDom = &v2cDom;
    forestOptions->v2cBnd = &v2cBnd;
    forestOptions->c2vBnd = &c2vBnd;
    forestOptions->triangleDirections = &triangleDirections;
    forestOptions->sizeFunction = NULL;

    HXT_CHECK(forestCreate(0, nullptr, &forest, nullptr, forestOptions));

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
      }
      Msg::Info("Limiting size gradient...");
      HXT_CHECK(forestSizeSmoothing(forest));
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
      // if(dim == 2){ 
        // HXT_CHECK(forestWriteSolFile2D(forest, "metric.sol"));
      // } else{
        // HXT_CHECK(forestWriteSolFile3DSurface(forest, "metricBnd.sol"));
        HXT_CHECK(forestWriteSolFile3DVolume(forest, "metricDom.sol"));
      // }
    }

    debug = true;
    if(debug) {
      // Export size field in .pos file
      forestFile = GModel::current()->getName() + ".pos";
      HXT_CHECK(forestExport(forest, forestFile.c_str()));
    }

    HXT_CHECK(hxtFree(&nodalCurvature));
    HXT_CHECK(hxtFree(&directions));
    if(dim == 3){
      HXT_CHECK(hxtFree(&directionsU));
      HXT_CHECK(hxtFree(&directionsV));
      HXT_CHECK(hxtFree(&directionsW));
    }
    HXT_CHECK(hxtMeshDelete(&meshBnd));
    HXT_CHECK(hxtMeshDelete(&meshDom));
  }

  return HXT_STATUS_OK;
}

#endif

void automaticMeshSizeField::update()
{
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = updateHXT();
  if(s != HXT_STATUS_OK)
    Msg::Error("Something went wrong when computing the octree");
#else
  Msg::Error(
    "Gmsh has to be compiled with HXT and P4EST to use automaticMeshSizeField");
#endif
};
