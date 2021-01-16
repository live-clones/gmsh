// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <set>

#if defined(_OPENMP)
#include <omp.h>
#endif

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

extern "C" {
#include "hxt_tools.h"
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
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
  int useInterpolatedSize = CTX::instance()->mesh.lcExtendFromBoundary;

  HXT_INFO("Mesh size callback %suse interpolated size",
           useInterpolatedSize ? "" : "does not ");

  for(size_t i = 0; i < numPts; i++) {
    GRegion *gr = (*allGR)[volume[i]];
    double lc = std::min(
      lcGlob, BGM_MeshSizeWithoutScaling(gr, 0, 0, pts[4 * i + 0],
                                         pts[4 * i + 1], pts[4 * i + 2]));
    if(useInterpolatedSize && pts[4 * i + 3] > 0.0)
      pts[4 * i + 3] = std::min(pts[4 * i + 3], lc);
    else
      pts[4 * i + 3] = lc;
  }

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
  allSurfaces.insert(allSurfaces.begin(), allSurfacesSet.begin(),
                     allSurfacesSet.end());

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
  allCurves.insert(allCurves.begin(), allCurvesSet.begin(), allCurvesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.curvesPerSurface, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < surfaces.size(); i++) {
    std::vector<GEdge *> const &f = surfaces[i]->edges();
    std::vector<GEdge *> const &f_e = surfaces[i]->embeddedEdges();
    for(size_t j = 0; j < f.size(); j++)
      m->brep.curvesPerSurface[counter++] = f[j]->tag();
    for(size_t j = 0; j < f_e.size(); j++)
      m->brep.curvesPerSurface[counter++] = f_e[j]->tag();
  }

  return HXT_STATUS_OK;
}

static HXTStatus Hxt2Gmsh(std::vector<GRegion *> &regions, HXTMesh *m,
                          std::map<MVertex *, uint32_t> &v2c,
                          std::vector<MVertex *> &c2v)
{
  Msg::Debug("Start Hxt2Gmsh");
  std::vector<GFace *> allSurfaces;
  std::vector<GEdge *> allCurves;
  HXT_CHECK(getAllSurfaces(regions, nullptr, allSurfaces));
  HXT_CHECK(getAllCurves(regions, allSurfaces, nullptr, allCurves));
  std::map<uint32_t, GEdge *> i2e;
  std::map<uint32_t, GFace *> i2f;
  for(size_t i = 0; i < allSurfaces.size(); i++)
    i2f[allSurfaces[i]->tag()] = allSurfaces[i];
  for(size_t i = 0; i < allCurves.size(); i++)
    i2e[allCurves[i]->tag()] = allCurves[i];

  c2v.resize(m->vertices.num);
  for(size_t i = c2v.size(); i < m->vertices.num; i++) { c2v[i] = nullptr; }

  for(size_t j = 0; j < allCurves.size(); j++) {
    GEdge *ge = allCurves[j];
    for(size_t i = 0; i < ge->lines.size(); i++) { delete ge->lines[i]; }
    ge->lines.clear();
  }

  for(size_t j = 0; j < allSurfaces.size(); j++) {
    GFace *gf = allSurfaces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      delete gf->triangles[i];
    }
    gf->triangles.clear();
  }

  uint32_t warning = 0;

  for(size_t i = 0; i < m->lines.num; i++) {
    uint32_t i0 = m->lines.node[2 * i + 0];
    uint32_t i1 = m->lines.node[2 * i + 1];
    uint32_t c = m->lines.color[i];
    MVertex *v0 = c2v[i0];
    MVertex *v1 = c2v[i1];
    auto ge = i2e.find(c);
    if(ge == i2e.end()) {
      if(warning != c) {
        warning = c;
        Msg::Warning("Could not find curve for HXT color %d", c);
      }
      continue;
    }
    if(!v0) {
      double *x = &m->vertices.coord[4 * i0];
      // FIXME compute true coordinates
      v0 = new MEdgeVertex(x[0], x[1], x[2], ge->second, 0);
    }
    if(!v1) {
      // FIXME compute true coordinates
      double *x = &m->vertices.coord[4 * i1];
      v1 = new MEdgeVertex(x[0], x[1], x[2], ge->second, 0);
    }
    ge->second->lines.push_back(new MLine(v0, v1));
  }

  for(size_t i = 0; i < m->triangles.num; i++) {
    uint32_t i0 = m->triangles.node[3 * i + 0];
    uint32_t i1 = m->triangles.node[3 * i + 1];
    uint32_t i2 = m->triangles.node[3 * i + 2];
    uint32_t c = m->triangles.color[i];
    MVertex *v0 = c2v[i0];
    MVertex *v1 = c2v[i1];
    MVertex *v2 = c2v[i2];
    auto gf = i2f.find(c);
    if(gf == i2f.end()) {
      if(warning != c) {
        warning = c;
        Msg::Warning("Could not find surface for HXT color %d", c);
      }
      continue;
    }
    if(!v0) {
      // FIXME compute true coordinates
      double *x = &m->vertices.coord[4 * i0];
      v0 = new MFaceVertex(x[0], x[1], x[2], gf->second, 0, 0);
    }
    if(!v1) {
      // FIXME compute true coordinates
      double *x = &m->vertices.coord[4 * i1];
      v1 = new MFaceVertex(x[0], x[1], x[2], gf->second, 0, 0);
    }
    if(!v2) {
      // FIXME compute true coordinates
      double *x = &m->vertices.coord[4 * i2];
      v2 = new MFaceVertex(x[0], x[1], x[2], gf->second, 0, 0);
    }
    gf->second->triangles.push_back(new MTriangle(v0, v1, v2));
  }
#if defined(_OPENMP)
#pragma omp parallel
#endif
  {
    std::vector<std::vector<MVertex *> > thread_local_vertex_vector(
      regions.size());
    std::vector<std::vector<MTetrahedron *> > thread_local_tetrahedron_vector(
      regions.size());
#if defined(_OPENMP)
#pragma omp for nowait
#endif
    for(size_t i = 0; i < m->tetrahedra.num; i++) {
      uint32_t *i0 = &m->tetrahedra.node[4 * i + 0];
      uint32_t c = m->tetrahedra.color[i];
      if(c < regions.size()) {
        MVertex *vv[4];
        GRegion *gr = regions[c];
        for(int j = 0; j < 4; j++) {
          MVertex *v0 = c2v[i0[j]];
          if(!v0) {
            double *x = &m->vertices.coord[4 * i0[j]];
            v0 = new MVertex(x[0], x[1], x[2], gr);
            // Insert the points into the thread-local vector first and then
            // summarize at the end
            thread_local_vertex_vector[c].push_back(v0);
            c2v[i0[j]] = v0;
          }
          vv[j] = v0;
        }
        // same as the MVertex object
        thread_local_tetrahedron_vector[c].push_back(
          new MTetrahedron(vv[0], vv[1], vv[2], vv[3]));
      }
    }
// insert thread local vector into the global vector
#if defined(_OPENMP)
#pragma omp critical
#endif
    {
      for(size_t i = 0; i < regions.size(); i++) {
        GRegion *gr = regions[i];
        gr->mesh_vertices.insert(gr->mesh_vertices.end(),
                                 thread_local_vertex_vector[i].begin(),
                                 thread_local_vertex_vector[i].end());
        gr->tetrahedra.insert(gr->tetrahedra.end(),
                              thread_local_tetrahedron_vector[i].begin(),
                              thread_local_tetrahedron_vector[i].end());
      }
    }
  }
  Msg::Debug("End Hxt2Gmsh");
  return HXT_STATUS_OK;
}

HXTStatus Gmsh2Hxt(std::vector<GRegion *> &regions, HXTMesh *m,
                   std::map<MVertex *, uint32_t> &v2c,
                   std::vector<MVertex *> &c2v)
{
  std::set<MVertex *> all;
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
      for(size_t i = 0; i < gv->points.size(); i++) {
        MVertex *v = gv->points[i]->getVertex(0);
        all.insert(v);
        if(gv->prescribedMeshSizeAtVertex() != MAX_LC)
          vlc[v] = gv->prescribedMeshSizeAtVertex();
      }
    }
  }

  for(size_t j = 0; j < curves.size(); j++) {
    GEdge *ge = curves[j];
    nedg += ge->lines.size();
    for(size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(size_t j = 0; j < surfaces.size(); j++) {
    GFace *gf = surfaces[j];
    ntri += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
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
  for(size_t j = 0; j < points.size(); j++) {
    GVertex *gv = points[j];
    for(size_t i = 0; i < gv->points.size(); i++) {
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
  for(size_t j = 0; j < curves.size(); j++) {
    GEdge *ge = curves[j];
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
  for(size_t j = 0; j < surfaces.size(); j++) {
    GFace *gf = surfaces[j];
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

static HXTStatus _meshGRegionHxt(std::vector<GRegion *> &regions)
{
  HXT_CHECK(hxtSetMessageCallback(messageCallback));

  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));

  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  Gmsh2Hxt(regions, mesh, v2c, c2v);

  HXTTetMeshOptions options = {
    0, // int defaultThreads;
    0, // int delaunayThreads;
    0, // int improveThreads;
    1, // int reproducible;
    (Msg::GetVerbosity() > 5) ? 2 : 1, // int verbosity;
    1, // int stat;
    1, // int refine;
    CTX::instance()->mesh.optimize, // int optimize;
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
                                      std::vector<MTetrahedron *> &tets)
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

  HXTDelaunayOptions delOptions = {
    nullptr, // bbox
    nullptr, // nodalSizes
    0, // numVertcesInMesh
    0, // insertionFirst
    0, // partitionability
    1, // perfectDelaunay
    0, // verbosity
    0, // reproducible
    0 // delaunayThreads (0 = omp_get_max_threads)
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
                         std::vector<MTetrahedron *> &tets)
{
  Msg::Info("Tetrahedrizing %d nodes...", v.size());
  double t1 = Cpu(), w1 = TimeOfDay();
  _delaunayMeshIn3DHxt(v, tets);
  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::Info("Done tetrahedrizing %d nodes (Wall %gs, CPU %gs)", v.size(),
            w2 - w1, t2 - t1);
}

#else

int meshGRegionHxt(std::vector<GRegion *> &regions)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
  return -1;
}

void delaunayMeshIn3DHxt(std::vector<MVertex *> &v,
                         std::vector<MTetrahedron *> &tets)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
}

#endif
