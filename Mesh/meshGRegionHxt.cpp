// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <map>
#include <set>
#include "GmshConfig.h"
#include "meshGRegionHxt.h"
#include "Context.h"
#include "MVertex.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTriangle.h"
#include "GmshMessage.h"

#ifdef HAVE_HXT
extern "C" {
#include "hxt_mesh3d_main.h"
#include "hxt_boundary_recovery.h"
#include "hxt_opt.h"
}


// This is a list of regions that are simply connected

static HXTStatus getAllFacesOfAllRegions (std::vector<GRegion *> &regions, HXTMesh *m, std::vector<GFace *> &allFaces){
  std::set<GFace *, GEntityLessThan> allFacesSet;
  m->brep.numVolumes = regions.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.numSurfacesPerVolume, m->brep.numVolumes
		     * sizeof(uint32_t)));
  uint32_t to_alloc = 0;
  for(unsigned int i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    m->brep.numSurfacesPerVolume[i] = f.size() + f_e.size();
    to_alloc += m->brep.numSurfacesPerVolume[i];
    allFacesSet.insert(f.begin(), f.end());
    allFacesSet.insert(f_e.begin(), f_e.end());
  }
  allFaces.insert (allFaces.begin(), allFacesSet.begin(), allFacesSet.end());
  HXT_CHECK(hxtAlignedMalloc(&m->brep.surfacesPerVolume, to_alloc* sizeof(uint32_t)));
  
  uint32_t counter = 0;
  for(unsigned int i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    for (size_t j=0;j<f.size();j++)m->brep.surfacesPerVolume[counter++]=f[i]->tag();
    for (size_t j=0;j<f_e.size();j++)m->brep.surfacesPerVolume[counter++]=f_e[i]->tag();
  }
  return HXT_STATUS_OK;
}
				    


static HXTStatus Gmsh2Hxt(std::vector<GRegion *> &regions, HXTMesh *m,
                          std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  std::set<MVertex *> all;
  std::vector<GFace *> faces;
  
  HXT_CHECK(getAllFacesOfAllRegions (regions, m, faces));
  
  uint64_t ntri = 0;

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

  m->triangles.num = m->triangles.size = ntri;
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.colors,
                             (m->triangles.num) * sizeof(uint16_t)));

  uint64_t index = 0;
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.colors[index] = gf->tag();
      index++;
    }
  }

  m->lines.num = m->lines.size = 0;

  return HXT_STATUS_OK;
}

static HXTStatus _meshGRegionHxt(std::vector<GRegion *> &regions)
{
  int nthreads = CTX::instance()->mesh.maxNumThreads3D;
  int optimize = 1;
  int refine = 1;
  int stat = 0;
  int verbosity = 100;
  int reproducible = 0;
  double threshold = 0.3;
  /*******************  ^ all argument were processed *********************/
  HXTMesh *mesh;
  HXTContext *context;
  HXT_CHECK(hxtContextCreate(&context));
  HXT_CHECK(hxtMeshCreate(context, &mesh));

  std::map<MVertex *, int> v2c;
  std::vector<MVertex *> c2v;
  Gmsh2Hxt(regions, mesh, v2c, c2v);

  HXT_CHECK(hxtTetMesh3d(mesh, nthreads, reproducible, verbosity, stat, refine,
                         optimize, threshold, hxt_boundary_recovery));
  HXT_CHECK(hxtMeshWriteGmsh(mesh, "hxt.msh"));
  HXT_CHECK(hxtMeshDelete(&mesh));
  HXT_CHECK(hxtContextDelete(&context));
  return HXT_STATUS_OK;
}

int meshGRegionHxt(std::vector<GRegion *> &regions)
{
  HXTStatus status = _meshGRegionHxt(regions);
  if(status == HXT_STATUS_OK) return 0;
  return 1;
}

#else

int meshGRegionHxt(std::vector<GRegion *> &regions)
{
  Msg::Error("Gmsh should be compile with Hxt to enable that option");
  return -1;
}

#endif
