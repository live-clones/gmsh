// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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

extern "C" {
#include "hxt_omp.h"
#include "hxt_tetMesh.h"
#include "hxt_tetDelaunay.h"
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

  HXT_INFO("Computing %smesh sizes...", useInterpolatedSize ? "interpolated " : "");

  int nthreads = getNumThreads();
  bool exceptions = false;
#pragma omp parallel for schedule(dynamic) num_threads(nthreads)
  for(size_t i = 0; i < numPts; i++) {
    if(exceptions) continue;
    if(volume[i] < 0 || volume[i] >= allGR->size()) {
      Msg::Error("Invalid volume tag %d in mesh size calculation", volume[i]);
      continue;
    }
    GRegion *gr = (*allGR)[volume[i]];
    try{ // OpenMP forbids leaving block via exception
      double lc = BGM_MeshSizeWithoutScaling(gr, 0, 0, pts[4 * i + 0],
                                             pts[4 * i + 1], pts[4 * i + 2]);
      if(useInterpolatedSize && pts[4 * i + 3] > 0.0)
        pts[4 * i + 3] = std::min(pts[4 * i + 3], std::min(lcGlob, lc));
      else
        pts[4 * i + 3] = std::min(lcGlob, lc);
    }
    catch(...) {
      exceptions = true;
    }
  }

  if(exceptions) throw std::runtime_error(Msg::GetLastError());

  HXT_INFO("Done computing %smesh sizes", useInterpolatedSize ? "interpolated " : "");

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
  for (auto const &gf: allSurfacesSet) {
    if (gf->quadrangles.size() != 0 || gf->polygons.size() != 0) {
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

  HXT_CHECK( hxtAlignedFree(&m->tetrahedra.neigh) );
  HXT_CHECK( hxtAlignedFree(&m->tetrahedra.flag) );
  HXT_CHECK( hxtAlignedFree(&m->points.node) );
  HXT_CHECK( hxtAlignedFree(&m->points.color) );

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
      for(std::size_t i = 0; i < ge->lines.size(); i++)
        delete ge->lines[i];
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
      double *x = &m->vertices.coord[4 * i0];
      // FIXME compute true coordinates
      c2v[i0] = new MEdgeVertex(x[0], x[1], x[2], ge->second, 0);
    }
    if(!c2v[i1]) {
      // FIXME compute true coordinates
      double *x = &m->vertices.coord[4 * i1];
      c2v[i1] = new MEdgeVertex(x[0], x[1], x[2], ge->second, 0);
    }
    ge->second->lines.push_back(new MLine(c2v[i0], c2v[i1]));
  }
  HXT_CHECK( hxtAlignedFree(&m->lines.node) );
  HXT_CHECK( hxtAlignedFree(&m->lines.color) );

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
      double *x = &m->vertices.coord[4 * i0];
      c2v[i0] = new MFaceVertex(x[0], x[1], x[2], gf->second, 0, 0);
    }
    if(!c2v[i1]) {
      // FIXME compute true coordinates
      double *x = &m->vertices.coord[4 * i1];
      c2v[i1] = new MFaceVertex(x[0], x[1], x[2], gf->second, 0, 0);
    }
    if(!c2v[i2]) {
      // FIXME compute true coordinates
      double *x = &m->vertices.coord[4 * i2];
      c2v[i2] = new MFaceVertex(x[0], x[1], x[2], gf->second, 0, 0);
    }
    gf->second->triangles.push_back(new MTriangle(c2v[i0], c2v[i1], c2v[i2]));
  }
  HXT_CHECK( hxtAlignedFree(&m->triangles.node) );
  HXT_CHECK( hxtAlignedFree(&m->triangles.color) );

#if 0 // this seems to be buggy (cf. e.g. #2575)
// #if defined(_OPENMP)
  int nthreads = getNumThreads();
  if(nthreads > 1) {
    const uint32_t nR = regions.size();
    const uint32_t nV = m->vertices.num;

    size_t* ht_all, *ht_tot; // histograms for tets
    HXT_CHECK( hxtCalloc(&ht_all, nR * (nthreads + 1), sizeof(size_t)) );
    uint32_t* hp_all, *hp_tot; // histograms for points
    HXT_CHECK( hxtCalloc(&hp_all, nR * (nthreads + 1) * 3 + (size_t) nV * nthreads,
                         sizeof(uint32_t)) );
    uint32_t* vR_all = hp_all + nR * (nthreads + 1); // color per point and per thread

    #pragma omp parallel num_threads(nthreads)
    {
      #pragma omp single
      {
        nthreads = omp_get_num_threads(); /* the real number of threads */
        ht_tot = ht_all + nR * nthreads;
        hp_tot = hp_all + nR * nthreads;
      }

      int threadID = omp_get_thread_num();
      size_t* ht_this = ht_all + nR * threadID;
      uint32_t* hp_this = hp_all + nR * threadID;
      uint32_t* vR_this = vR_all + nV * threadID;

      // count the number of tetrahedra in each region in parallel
      #pragma omp for schedule(static)
      for(size_t i = 0; i < m->tetrahedra.num; i++) {
        uint32_t c = m->tetrahedra.color[i];
        if(c >= nR) continue;

        ht_this[c]++;
        uint32_t *nodes = &m->tetrahedra.node[4 * i];
        for(int j = 0; j < 4; j++) {
          uint32_t pt = nodes[j];
          if(!c2v[pt])
            vR_this[pt] = c + 1;
        }
      }

      #pragma omp for schedule(static)
      for(uint32_t pt = 0; pt < nV; pt++) {
        if(c2v[pt]) continue;

        uint32_t color = 0;
        for(int thrd = 0; thrd < nthreads; thrd++) {
          if(vR_all[thrd * nV + pt]) {
            color = vR_all[thrd * nV + pt];
            break;
          }
        }
        color--;
  #ifdef DEBUG
        if(color >= nR)
          exit(HXT_ERROR_MSG(HXT_STATUS_ERROR, "no volume or color for pt %u", pt));
  #endif
        vR_all[pt] = color;
        hp_this[color]++;
      }

      #pragma omp for
      for(uint32_t c2 = 0; c2 < 2 * nR; c2++) { // parallelism x 2 :p
        uint32_t c = c2 >> 1;
        if(c2 & 1) {
          size_t sumt = 0;
          for(int j = 0; j < nthreads + 1; j++) {
            size_t tsumt = ht_all[j * nR + c] + sumt;
            ht_all[j * nR + c] = sumt;
            sumt = tsumt;
          }
          regions[c]->tetrahedra.resize(ht_tot[c], nullptr);
        }
        else {
          uint32_t sump = 0;
          for(int j = 0; j < nthreads + 1; j++) {
            uint32_t tsump = hp_all[j * nR + c] + sump;
            hp_all[j * nR + c] = sump;
            sump = tsump;
          }
          regions[c]->mesh_vertices.resize(hp_tot[c], nullptr);
        }
      }

      #pragma omp for schedule(static)
      for(uint32_t pt = 0; pt < nV; pt++) {
        if(c2v[pt]) continue;

        uint32_t c = vR_all[pt];
        GRegion *gr = regions[c];
        double *x = &m->vertices.coord[4 * pt];
        c2v[pt] = new MVertex(x[0], x[1], x[2], gr);
        gr->mesh_vertices[hp_this[c]++] = c2v[pt];
      }


      #pragma omp for schedule(static)
      for(size_t i = 0; i < m->tetrahedra.num; i++) {
        uint32_t c = m->tetrahedra.color[i];
        if(c >= nR) continue;

        uint32_t *nodes = &m->tetrahedra.node[4 * i];
        regions[c]->tetrahedra[ht_this[c]++] = new MTetrahedron
          (c2v[nodes[0]], c2v[nodes[1]], c2v[nodes[2]], c2v[nodes[3]]);
      }
    }

    HXT_CHECK( hxtFree(&ht_all) );
    HXT_CHECK( hxtFree(&hp_all) );
  }
  else
#endif
  {
    std::vector<std::size_t> numtet(regions.size(), 0);
    for(std::size_t i = 0; i < m->tetrahedra.num; i++) {
      uint16_t c = m->tetrahedra.color[i];
      if(c >= numtet.size())
        continue;
      numtet[c]++;
    }
    for(std::size_t i = 0; i < numtet.size(); i++) {
      regions[i]->tetrahedra.reserve(numtet[i]);
      regions[i]->mesh_vertices.reserve(numtet[i] / 6);
    }

    for(std::size_t i = 0; i < m->tetrahedra.num; i++) {
      uint16_t c = m->tetrahedra.color[i];
      if(c >= regions.size())
        continue;

      GRegion *gr = regions[c];
      MVertex *vv[4];
      uint32_t *nodes = &m->tetrahedra.node[4 * i];
      for(int j = 0; j < 4; j++) {
        if(c2v[nodes[j]]){
          vv[j] = c2v[nodes[j]];
          continue;
        }
        double *x = &m->vertices.coord[4 * nodes[j]];
        vv[j] = new MVertex(x[0], x[1], x[2], gr);
        gr->mesh_vertices.push_back(vv[j]);
        c2v[nodes[j]] = vv[j];
      }

      gr->tetrahedra.push_back(new MTetrahedron(vv[0], vv[1], vv[2], vv[3]));
    }
  }

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
    1, // int reproducible;
    (Msg::GetVerbosity() > 5) ? 2 : 1, // int verbosity;
    1, // int stat;
    1, // int refine;
    CTX::instance()->mesh.optimize, // int optimize;
    CTX::instance()->mesh.toleranceInitialDelaunay,// tolerance for tetgen
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

  int nthreads = getNumThreads();

  HXTDelaunayOptions delOptions = {
    nullptr, // bbox
    nullptr, // nodalSizes
    0, // numVertcesInMesh
    0, // insertionFirst
    0, // partitionability
    1, // perfectDelaunay
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
