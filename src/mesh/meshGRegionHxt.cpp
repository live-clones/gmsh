// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <set>
#include <stdexcept>

#include "GmshConfig.h"
#include "meshGRegionHxt.h"
#include "Context.h"
#include "MVertex.h"
#include "GRegion.h"
#include "discreteRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MPoint.h"
#include "GmshMessage.h"
#include "BackgroundMeshTools.h"
#include "OS.h"

#if defined(HAVE_HXT)

#include "hxt_omp.h"
extern "C" {
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
#include "hxt_boundary_recovery.h"
#include "hxt_tools.h"
#include "hxt_tetOpti.h"
#include "hxt_tetRepair.h"
#include "hxt_tetFlag.h"
}

static int getNumThreads()
{
  int nthreads = CTX::instance()->numThreads;
  if(CTX::instance()->mesh.maxNumThreads3D > 0)
    nthreads = CTX::instance()->mesh.maxNumThreads3D;
  if(!nthreads) nthreads = Msg::GetMaxThreads();
  return nthreads;
}

static HXTStatus messageCallback(HXTMessage *msg)
{
  if(msg) Msg::Info("%s", msg->string);
  return HXT_STATUS_OK;
}

static HXTStatus nodalSizesCallBack(double *pts, uint32_t *volume,
                                    size_t numPts, void *userData)
{
  std::vector<GRegion *> *allGR = (std::vector<GRegion *> *)userData;

  double lcGlob = CTX::instance()->lc;
  int useInterpolatedSize = Extend2dMeshIn3dVolumes();

  HXT_INFO("Computing %smesh sizes...",
           useInterpolatedSize ? "interpolated " : "");

  int nthreads = getNumThreads();
  bool exceptions = false;
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t i = 0; i < numPts; i++) {
    if(exceptions) continue;
    if(volume[i] >= allGR->size()) {
      Msg::Error("Invalid volume tag %d in mesh size calculation", volume[i]);
      continue;
    }
    GRegion *gr = (*allGR)[volume[i]];
    try { // OpenMP forbids leaving block via exception
      double lc = BGM_MeshSizeWithoutScaling(gr, 0, 0, pts[4 * i + 0],
                                             pts[4 * i + 1], pts[4 * i + 2]);
      if(useInterpolatedSize && pts[4 * i + 3] > 0.0)
        pts[4 * i + 3] = std::min(pts[4 * i + 3], std::min(lcGlob, lc));
      else
        pts[4 * i + 3] = std::min(lcGlob, lc);
    } catch(...) {
      exceptions = true;
    }
  }

  if(exceptions) throw std::runtime_error(Msg::GetLastError());

  HXT_INFO("Done computing %smesh sizes",
           useInterpolatedSize ? "interpolated " : "");

  return HXT_STATUS_OK;
}

static HXTStatus getAllSurfaces(std::vector<GRegion *> &regions, HXTMesh *m,
                                std::vector<GFace *> &allSurfaces)
{
  std::set<GFace *, GEntityPtrLessThan> allSurfacesSet;
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
    allSurfacesSet.insert(f.begin(), f.end());
    allSurfacesSet.insert(f_e.begin(), f_e.end());
  }

  // verify that all elements are triangles
  for(auto const &gf : allSurfacesSet) {
    if(gf->quadrangles.size() != 0 || gf->polygons.size() != 0) {
      std::size_t num = gf->quadrangles.size() + gf->polygons.size();
      Msg::Error("Surface %d contains %zu elements which are not triangles. "
                 "The HXT 3D meshing algorithm only supports triangles.",
                 gf->tag(), num);
      return HXT_STATUS_ERROR;
    }
  }

  allSurfaces.insert(allSurfaces.end(), allSurfacesSet.begin(),
                     allSurfacesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.surfacesPerVolume, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    for(std::size_t j = 0; j < f.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f[j]->tag();
    for(std::size_t j = 0; j < f_e.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f_e[j]->tag();
  }

  return HXT_STATUS_OK;
}

static HXTStatus getAllCurves(std::vector<GRegion *> &regions,
                              std::vector<GFace *> &surfaces, HXTMesh *m,
                              std::vector<GEdge *> &allCurves)
{
  if(m) {
    m->brep.numSurfaces = surfaces.size();
    HXT_CHECK(hxtAlignedMalloc(&m->brep.numCurvesPerSurface,
                               m->brep.numSurfaces * sizeof(uint32_t)));
  }
  uint32_t to_alloc = 0;

  std::set<GEdge *, GEntityPtrLessThan> allCurvesSet;

  for(std::size_t i = 0; i < surfaces.size(); i++) {
    std::vector<GEdge *> const &f = surfaces[i]->edges();
    std::vector<GEdge *> const &f_e = surfaces[i]->embeddedEdges();
    if(m) {
      m->brep.numCurvesPerSurface[i] = f.size() + f_e.size();
      to_alloc += m->brep.numCurvesPerSurface[i];
    }
    allCurvesSet.insert(f.begin(), f.end());
    allCurvesSet.insert(f_e.begin(), f_e.end());
  }
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GEdge *> const &r_e = regions[i]->embeddedEdges();
    allCurvesSet.insert(r_e.begin(), r_e.end());
  }
  allCurves.insert(allCurves.end(), allCurvesSet.begin(), allCurvesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.curvesPerSurface, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < surfaces.size(); i++) {
    std::vector<GEdge *> const &f = surfaces[i]->edges();
    std::vector<GEdge *> const &f_e = surfaces[i]->embeddedEdges();
    for(std::size_t j = 0; j < f.size(); j++)
      m->brep.curvesPerSurface[counter++] = f[j]->tag();
    for(std::size_t j = 0; j < f_e.size(); j++)
      m->brep.curvesPerSurface[counter++] = f_e[j]->tag();
  }

  return HXT_STATUS_OK;
}

static HXTStatus Hxt2Gmsh(std::vector<GRegion *> &regions, HXTMesh *m,
                          std::map<MVertex *, uint32_t> &v2c,
                          std::vector<MVertex *> &c2v)
{
  Msg::Debug("Start Hxt2Gmsh");

  HXT_CHECK(hxtAlignedFree(&m->tetrahedra.neigh));
  HXT_CHECK(hxtAlignedFree(&m->tetrahedra.flag));
  HXT_CHECK(hxtAlignedFree(&m->points.node));
  HXT_CHECK(hxtAlignedFree(&m->points.color));

  std::map<uint32_t, GEdge *> i2e;
  std::map<uint32_t, GFace *> i2f;
  { // deleting old faces and edges, and filling i2e
    std::vector<GFace *> allSurfaces;
    std::vector<GEdge *> allCurves;
    HXT_CHECK(getAllSurfaces(regions, nullptr, allSurfaces));
    HXT_CHECK(getAllCurves(regions, allSurfaces, nullptr, allCurves));

    for(std::size_t j = 0; j < allCurves.size(); j++) {
      i2e[allCurves[j]->tag()] = allCurves[j];
      GEdge *ge = allCurves[j];
      for(std::size_t i = 0; i < ge->lines.size(); i++) delete ge->lines[i];
      ge->lines.clear();
    }

    for(std::size_t j = 0; j < allSurfaces.size(); j++) {
      i2f[allSurfaces[j]->tag()] = allSurfaces[j];
      GFace *gf = allSurfaces[j];
      for(std::size_t i = 0; i < gf->triangles.size(); i++)
        delete gf->triangles[i];
      gf->triangles.clear();
    }
  }

  c2v.resize(m->vertices.num, nullptr);

  uint32_t warning = 0;
  for(std::size_t i = 0; i < m->lines.num; i++) {
    uint32_t c = m->lines.color[i];
    auto ge = i2e.find(c);
    if(ge == i2e.end()) {
      if(warning != c) {
        warning = c;
        Msg::Warning("Could not find curve for HXT color %d", c);
      }
      continue;
    }

    uint32_t i0 = m->lines.node[2 * i + 0];
    uint32_t i1 = m->lines.node[2 * i + 1];
    if(!c2v[i0]) {
      double *xyz = &m->vertices.coord[4 * i0];
      // FIXME compute true coordinates
      c2v[i0] = new MEdgeVertex(xyz[0], xyz[1], xyz[2], ge->second, 0);
    }
    if(!c2v[i1]) {
      // FIXME compute true coordinates
      double *xyz = &m->vertices.coord[4 * i1];
      c2v[i1] = new MEdgeVertex(xyz[0], xyz[1], xyz[2], ge->second, 0);
    }
    ge->second->lines.push_back(new MLine(c2v[i0], c2v[i1]));
  }
  HXT_CHECK(hxtAlignedFree(&m->lines.node));
  HXT_CHECK(hxtAlignedFree(&m->lines.color));

  for(std::size_t i = 0; i < m->triangles.num; i++) {
    uint32_t c = m->triangles.color[i];
    auto gf = i2f.find(c);
    if(gf == i2f.end()) {
      if(warning != c) {
        warning = c;
        Msg::Warning("Could not find surface for HXT color %d", c);
      }
      continue;
    }

    uint32_t i0 = m->triangles.node[3 * i + 0];
    uint32_t i1 = m->triangles.node[3 * i + 1];
    uint32_t i2 = m->triangles.node[3 * i + 2];
    if(!c2v[i0]) {
      // FIXME compute true coordinates
      double *xyz = &m->vertices.coord[4 * i0];
      c2v[i0] = new MFaceVertex(xyz[0], xyz[1], xyz[2], gf->second, 0, 0);
    }
    if(!c2v[i1]) {
      // FIXME compute true coordinates
      double *xyz = &m->vertices.coord[4 * i1];
      c2v[i1] = new MFaceVertex(xyz[0], xyz[1], xyz[2], gf->second, 0, 0);
    }
    if(!c2v[i2]) {
      // FIXME compute true coordinates
      double *xyz = &m->vertices.coord[4 * i2];
      c2v[i2] = new MFaceVertex(xyz[0], xyz[1], xyz[2], gf->second, 0, 0);
    }
    gf->second->triangles.push_back(new MTriangle(c2v[i0], c2v[i1], c2v[i2]));
  }
  HXT_CHECK(hxtAlignedFree(&m->triangles.node));
  HXT_CHECK(hxtAlignedFree(&m->triangles.color));

#if 1
  std::vector<std::size_t> numtet(regions.size(), 0);
  for(std::size_t i = 0; i < m->tetrahedra.num; i++) {
    uint16_t c = m->tetrahedra.color[i];
    if(c >= numtet.size()) continue;
    numtet[c]++;
  }
  for(std::size_t c = 0; c < numtet.size(); c++) {
    regions[c]->tetrahedra.reserve(numtet[c]);
    regions[c]->mesh_vertices.reserve(numtet[c] / 6);
  }
  for(std::size_t i = 0; i < m->tetrahedra.num; i++) {
    uint16_t c = m->tetrahedra.color[i];
    if(c >= regions.size()) continue;
    GRegion *gr = regions[c];
    MVertex *vv[4];
    uint32_t *nodes = &m->tetrahedra.node[4 * i];
    for(int j = 0; j < 4; j++) {
      if(c2v[nodes[j]]) {
        vv[j] = c2v[nodes[j]];
        continue;
      }
      double *xyz = &m->vertices.coord[4 * nodes[j]];
      vv[j] = new MVertex(xyz[0], xyz[1], xyz[2], gr);
      gr->mesh_vertices.push_back(vv[j]);
      c2v[nodes[j]] = vv[j];
    }
    gr->tetrahedra.push_back(new MTetrahedron(vv[0], vv[1], vv[2], vv[3]));
  }
#else
  // TODO redo multi-threaded version
#endif

  Msg::Debug("End Hxt2Gmsh");
  return HXT_STATUS_OK;
}

HXTStatus Gmsh2Hxt(std::vector<GRegion *> &regions, HXTMesh *m,
                   std::map<MVertex *, uint32_t> &v2c,
                   std::vector<MVertex *> &c2v)
{
  std::set<MVertex *, MVertexPtrLessThan> all;
  std::vector<GFace *> surfaces;
  std::vector<GEdge *> curves;
  std::vector<GVertex *> points;
  std::map<MVertex *, double> vlc;

  HXT_CHECK(getAllSurfaces(regions, m, surfaces));
  HXT_CHECK(getAllCurves(regions, surfaces, m, curves));

  uint64_t index = 0, ntri = 0, nedg = 0, npts = 0;

  // embedded points in volumes (all other embedded points will be in the
  // curve/surface meshes already)
  for(GRegion *gr : regions) {
    for(GVertex *gv : gr->embeddedVertices()) {
      points.push_back(gv);
      npts += gv->points.size();
      for(std::size_t i = 0; i < gv->points.size(); i++) {
        MVertex *v = gv->points[i]->getVertex(0);
        all.insert(v);
        if(gv->prescribedMeshSizeAtVertex() != MAX_LC)
          vlc[v] = gv->prescribedMeshSizeAtVertex();
      }
    }
  }

  for(std::size_t j = 0; j < curves.size(); j++) {
    GEdge *ge = curves[j];
    nedg += ge->lines.size();
    for(std::size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(std::size_t j = 0; j < surfaces.size(); j++) {
    GFace *gf = surfaces[j];
    ntri += gf->triangles.size();
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  std::size_t count = 0;
  c2v.resize(all.size());
  for(MVertex *v : all) {
    m->vertices.coord[4 * count + 0] = v->x();
    m->vertices.coord[4 * count + 1] = v->y();
    m->vertices.coord[4 * count + 2] = v->z();
    m->vertices.coord[4 * count + 3] = 0;
    if(CTX::instance()
         ->mesh.lcFromPoints) { // size on embedded points in volume
      auto it = vlc.find(v);
      if(it != vlc.end()) m->vertices.coord[4 * count + 3] = it->second;
    }
    v2c[v] = count;
    c2v[count++] = v;
  }
  all.clear();

  m->points.num = m->points.size = npts;
  HXT_CHECK(
    hxtAlignedMalloc(&m->points.node, (m->points.num) * sizeof(uint32_t)));
  HXT_CHECK(
    hxtAlignedMalloc(&m->points.color, (m->points.num) * sizeof(uint32_t)));
  index = 0;
  for(std::size_t j = 0; j < points.size(); j++) {
    GVertex *gv = points[j];
    for(std::size_t i = 0; i < gv->points.size(); i++) {
      m->points.node[index] = v2c[gv->points[i]->getVertex(0)];
      m->points.color[index] = gv->tag();
      index++;
    }
  }

  m->lines.num = m->lines.size = nedg;
  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint32_t)));
  index = 0;
  for(std::size_t j = 0; j < curves.size(); j++) {
    GEdge *ge = curves[j];
    for(std::size_t i = 0; i < ge->lines.size(); i++) {
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
  for(std::size_t j = 0; j < surfaces.size(); j++) {
    GFace *gf = surfaces[j];
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.color[index] = gf->tag();
      index++;
    }
  }
  return HXT_STATUS_OK;
}

static HXTStatus _meshGRegionHxt(std::vector<GRegion *> &regions)
{
  HXT_CHECK(hxtSetMessageCallback(messageCallback));

  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));

  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  Gmsh2Hxt(regions, mesh, v2c, c2v);

  int nthreads = getNumThreads();

  HXTTetMeshOptions options = {
    nthreads, // int defaultThreads;
    nthreads, // int delaunayThreads;
    nthreads, // int improveThreads;
    CTX::instance()->mesh.reproducible, // int reproducible;
    (Msg::GetVerbosity() > 5) ? 2 : 1, // int verbosity;
    1, // int stat;
    1, // int refine;
    CTX::instance()->mesh.optimize, // int optimize;
    CTX::instance()->mesh.toleranceInitialDelaunay, // tolerance for tetgen
    {
      // quality
      nullptr, // double (*callback)(.., userData)
      nullptr, // void* userData;
      CTX::instance()->mesh.optimizeThreshold // double qualityMin;
    },
    {// nodalSize

     // FIXME: put NULL when the callback is not needed (when we use the
     // interpolated point size anyway)
     nodalSizesCallBack, // HXTStatus (*callback)(double*, size_t, void*
                         // userData)
     &regions, // void* meshSizeData;
     CTX::instance()->mesh.lcMin, CTX::instance()->mesh.lcMax,
     CTX::instance()->mesh.lcFactor * regions[0]->getMeshSizeFactor()}};

  HXT_CHECK(hxtTetMesh(mesh, &options));

  HXT_CHECK(Hxt2Gmsh(regions, mesh, v2c, c2v));
  HXT_CHECK(hxtMeshDelete(&mesh));
  return HXT_STATUS_OK;
}

int meshGRegionHxt(std::vector<GRegion *> &regions)
{
  HXTStatus status = _meshGRegionHxt(regions);
  if(status == HXT_STATUS_OK) return 0;
  return 1;
}

static HXTStatus _delaunayMeshIn3DHxt(std::vector<MVertex *> &verts,
                                      std::vector<MTetrahedron *> &tets,
                                      const std::vector<MTriangle> &triangles)
{
  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));

  size_t nvert = verts.size();
  HXT_CHECK(
    hxtAlignedMalloc(&mesh->vertices.coord, nvert * 4 * sizeof(double)));
  for(size_t i = 0; i < nvert; i++) {
    mesh->vertices.coord[4 * i + 0] = verts[i]->x();
    mesh->vertices.coord[4 * i + 1] = verts[i]->y();
    mesh->vertices.coord[4 * i + 2] = verts[i]->z();
    mesh->vertices.coord[4 * i + 3] = 0.;
  }
  mesh->vertices.num = nvert;
  mesh->vertices.size = nvert;

  int nthreads = getNumThreads();

  HXTDelaunayOptions delOptions = {
    nullptr, // bbox
    nullptr, // nodalSizes
    0, // numVertcesInMesh
    0, // insertionFirst
    0, // partitionability
    1, // perfectDelaunay
    0, // allowOuterInsertion
    0, // verbosity
    0, // reproducible
    nthreads // delaunayThreads (0 = omp_get_max_threads)
  };

  // HXT_CHECK(hxtDelaunay(mesh, &delOptions));
  HXTNodeInfo *nodeInfo;
  HXT_CHECK(
    hxtAlignedMalloc(&nodeInfo, sizeof(HXTNodeInfo) * mesh->vertices.num));
  for(uint32_t i = 0; i < mesh->vertices.num; i++) {
    nodeInfo[i].node = i;
    nodeInfo[i].status = HXT_STATUS_TRYAGAIN;
  }
  HXT_CHECK(
    hxtDelaunaySteadyVertices(mesh, &delOptions, nodeInfo, mesh->vertices.num));
  HXT_CHECK(hxtAlignedFree(&nodeInfo));

  size_t nTriangles = triangles.size();

  if(nTriangles > 0) {
    HXT_CHECK(hxtAlignedMalloc(&mesh->triangles.node,
                               3 * nTriangles * sizeof(uint32_t)));
    HXT_CHECK(
      hxtAlignedMalloc(&mesh->triangles.color, nTriangles * sizeof(uint32_t)));
    for(size_t i = 0; i < nTriangles; i++) {
      mesh->triangles.node[3 * i + 0] = triangles[i].getVertex(0)->getIndex();
      mesh->triangles.node[3 * i + 1] = triangles[i].getVertex(1)->getIndex();
      mesh->triangles.node[3 * i + 2] = triangles[i].getVertex(2)->getIndex();
      mesh->triangles.color[i] = 0;
    }
    mesh->triangles.num = nTriangles;
    mesh->triangles.size = nTriangles;

    hxt_boundary_recovery(mesh, 0.0);

    if(nvert < mesh->vertices.num) {
      // Steiner points!
      std::size_t j = nvert;
      for(size_t i = nvert; i < mesh->vertices.num; ++i) {
        MVertex *sterinerPoint = new MVertex(mesh->vertices.coord[4 * i + 0],
                                             mesh->vertices.coord[4 * i + 1],
                                             mesh->vertices.coord[4 * i + 2]);
        sterinerPoint->setIndex(j);
        verts.push_back(sterinerPoint);
        j++;
      }
    }
  }

  for(size_t i = 0; i < mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.node[i * 4 + 3] != UINT32_MAX) {
      uint32_t myColor = mesh->tetrahedra.color ? mesh->tetrahedra.color[i] : 0;
      if(myColor != HXT_COLOR_OUT) {
        uint32_t *n = &mesh->tetrahedra.node[4 * i];
        tets.push_back(
          new MTetrahedron(verts[n[0]], verts[n[1]], verts[n[2]], verts[n[3]]));
      }
    }
  }

  HXT_CHECK(hxtMeshDelete(&mesh));
  return HXT_STATUS_OK;
}

void delaunayMeshIn3DHxt(std::vector<MVertex *> &v,
                         std::vector<MTetrahedron *> &tets,
                         const std::vector<MTriangle> &triangles)
{
  Msg::Info("Tetrahedrizing %d nodes...", v.size());
  double t1 = Cpu(), w1 = TimeOfDay();
  _delaunayMeshIn3DHxt(v, tets, triangles);
  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::Info("Done tetrahedrizing %d nodes (Wall %gs, CPU %gs)", v.size(),
            w2 - w1, t2 - t1);
}

void optimizeMeshHXT(GModel *pModel, double quality, bool flipOnly)
{
  auto pRegions = pModel->getRegions();
  for(auto pRegion : pRegions) {
    if(!pRegion->hexahedra.empty() || !pRegion->polyhedra.empty() ||
       !pRegion->trihedra.empty() || !pRegion->prisms.empty() ||
       !pRegion->pyramids.empty()) {
      Msg::Error("HXT can only optimize a tetrahedral mesh!");
      return;
    }

    if(pRegion->tetrahedra.size() == 0) {
      Msg::Info("No tetrahedron to optimize");
      continue;
    }

    for(auto tet : pRegion->tetrahedra) {
      if(tet->getNumVertices() != 4) {
        Msg::Error("HXT can only optimize linear tetrehedra!");
        return;
      }
    }

    HXTMesh *pMesh = nullptr;
    HXTStatus ret = hxtMeshCreate(&pMesh);
    if(ret != HXT_STATUS_OK) {
      Msg::Error("Something went wrong when creating HXT mesh");
      return;
    }

    std::vector<MVertex *> pVertices(4 * pRegion->tetrahedra.size());
    for(std::size_t t = 0; t < pRegion->tetrahedra.size(); ++t) {
      auto tet = pRegion->tetrahedra[t];
      pVertices[4 * t + 0] = (tet->getVertex(0));
      pVertices[4 * t + 1] = (tet->getVertex(1));
      pVertices[4 * t + 2] = (tet->getVertex(2));
      pVertices[4 * t + 3] = (tet->getVertex(3));
    }

    std::sort(pVertices.begin(), pVertices.end());
    pVertices.erase(std::unique(pVertices.begin(), pVertices.end()),
                    pVertices.end());

    std::map<std::size_t, std::size_t> vertexNumToHxtVertex;
    std::size_t counter = 0;
    for(auto pVertex : pVertices) {
      vertexNumToHxtVertex[pVertex->getNum()] = counter;
      counter++;
    }

    ret = hxtAlignedMalloc(&pMesh->vertices.coord,
                           4 * pVertices.size() * sizeof(double));
    if(ret != HXT_STATUS_OK) {
      Msg::Error("Something went wrong when allocating memory for HXT verices");
      hxtMeshDelete(&pMesh);
      return;
    }

    pMesh->vertices.num = pVertices.size();
    pMesh->vertices.size = pVertices.size();

#pragma omp parallel for schedule(static)
    for(std::size_t v = 0; v < pVertices.size(); ++v) {
      pMesh->vertices.coord[4 * v + 0] = pVertices[v]->x();
      pMesh->vertices.coord[4 * v + 1] = pVertices[v]->y();
      pMesh->vertices.coord[4 * v + 2] = pVertices[v]->z();
      pMesh->vertices.coord[4 * v + 3] = 0.0;
    }

    ret = hxtAlignedMalloc(&pMesh->tetrahedra.node,
                           4 * pRegion->tetrahedra.size() * sizeof(uint32_t));
    if(ret != HXT_STATUS_OK) {
      Msg::Error(
        "Something went wrong when allocating memory for HXT tetrahedra");
      hxtMeshDelete(&pMesh);
      return;
    }

    ret = hxtAlignedMalloc(&pMesh->tetrahedra.color,
                           pRegion->tetrahedra.size() * sizeof(uint32_t));
    if(ret != HXT_STATUS_OK) {
      Msg::Error("Something went wrong when allocating memory for HXT "
                 "tetrahedron colors");
      hxtMeshDelete(&pMesh);
      return;
    }

    ret = hxtAlignedMalloc(&pMesh->tetrahedra.flag,
                           pRegion->tetrahedra.size() * sizeof(uint16_t));
    if(ret != HXT_STATUS_OK) {
      Msg::Error("Something went wrong when allocating memory for HXT "
                 "tetrahedron falgs");
      hxtMeshDelete(&pMesh);
      return;
    }

    pMesh->tetrahedra.num = pRegion->tetrahedra.size();
    pMesh->tetrahedra.size = pRegion->tetrahedra.size();

#pragma omp parallel for schedule(static)
    for(std::size_t t = 0; t < pRegion->tetrahedra.size(); ++t) {
      auto tet = pRegion->tetrahedra[t];
      pMesh->tetrahedra.node[4 * t + 0] =
        vertexNumToHxtVertex[tet->getVertex(0)->getNum()];
      pMesh->tetrahedra.node[4 * t + 1] =
        vertexNumToHxtVertex[tet->getVertex(1)->getNum()];
      pMesh->tetrahedra.node[4 * t + 2] =
        vertexNumToHxtVertex[tet->getVertex(2)->getNum()];
      pMesh->tetrahedra.node[4 * t + 3] =
        vertexNumToHxtVertex[tet->getVertex(3)->getNum()];
      pMesh->tetrahedra.color[t] = 0;
      pMesh->tetrahedra.flag[t] = 0;
    }

    ret = hxtTetAdjacencies(pMesh);
    if(ret != HXT_STATUS_OK) {
      Msg::Error(
        "Something went wrong when computing adjacencies for HXT tetrahedra");
      hxtMeshDelete(&pMesh);
      return;
    }

#pragma omp parallel for schedule(static)
    for(std::size_t t = 0; t < pRegion->tetrahedra.size(); ++t) {
      for(uint8_t i = 0; i < 4; ++i) {
        if(pMesh->tetrahedra.neigh[4 * t + i] == HXT_NO_ADJACENT)
          setFacetConstraint(pMesh, t, i);
        else {
          uint64_t neighElm = pMesh->tetrahedra.neigh[4 * t + i] / 4;
          unsigned short neighFace = pMesh->tetrahedra.neigh[4 * t + i] % 4;

          if(pMesh->tetrahedra.color[t] != pMesh->tetrahedra.color[neighElm]) {
            setFacetConstraint(pMesh, t, i);
            setFacetConstraint(pMesh, neighElm, neighFace);
          }
        }
      }
    }

    HXTOptimizeOptions options;
    options.bbox = nullptr;
    options.numThreads = getNumThreads();
    if(flipOnly)
      options.numVerticesConstrained = pMesh->vertices.num;
    else
      options.numVerticesConstrained = 0;
    options.qualityData = nullptr;
    options.qualityFun = nullptr;
    options.qualityMin = quality;
    options.reproducible = 0;
    options.verbosity = 2;

    ret = hxtOptimizeTetrahedra(pMesh, &options);
    if(ret != HXT_STATUS_OK) {
      Msg::Error("Something went wrong when optimizing tetrahedra using HXT");
      hxtMeshDelete(&pMesh);
      return;
    }

    for(uint32_t v = 0; v < pMesh->vertices.num; ++v)
      pVertices[v]->setXYZ(pMesh->vertices.coord[4 * v + 0],
                           pMesh->vertices.coord[4 * v + 1],
                           pMesh->vertices.coord[4 * v + 2]);

    for(auto tet : pRegion->tetrahedra) delete tet;

    pRegion->tetrahedra.clear();

    uint64_t goodTetCount = 0;
    for(uint64_t i = 0; i < pMesh->tetrahedra.num; i++) {
      if(pMesh->tetrahedra.color[i] == HXT_COLOR_OUT ||
         pMesh->tetrahedra.node[4 * i + 3] == HXT_GHOST_VERTEX)
        continue;

      goodTetCount++;
    }

    pRegion->tetrahedra.resize(goodTetCount);
    goodTetCount = 0;
    for(uint64_t i = 0; i < pMesh->tetrahedra.num; i++) {
      if(pMesh->tetrahedra.color[i] == HXT_COLOR_OUT ||
         pMesh->tetrahedra.node[4 * i + 3] == HXT_GHOST_VERTEX)
        continue;

      auto t = &pMesh->tetrahedra.node[4 * i];
      auto tet = new MTetrahedron(pVertices[t[0]], pVertices[t[1]],
                                  pVertices[t[2]], pVertices[t[3]]);
      pRegion->tetrahedra[goodTetCount] = tet;
      goodTetCount++;
    }

    hxtMeshDelete(&pMesh);
  }
}

#else

int meshGRegionHxt(std::vector<GRegion *> &regions)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
  return -1;
}

void delaunayMeshIn3DHxt(std::vector<MVertex *> &v,
                         std::vector<MTetrahedron *> &tets,
                         const std::vector<MTriangle> &triangles)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
}

void optimizeMeshHXT(GModel *pModel, double quality)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
}

#endif
