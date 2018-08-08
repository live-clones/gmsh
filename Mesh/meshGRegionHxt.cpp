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

static HXTStatus Gmsh2Hxt(GRegion *gr, HXTMesh *m,
                          std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  std::set<MVertex *> all;
  std::vector<GFace *> faces = gr->faces();

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

static HXTStatus _meshGRegionHxt(GRegion *gr)
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
  Gmsh2Hxt(gr, mesh, v2c, c2v);

  HXT_CHECK(hxtTetMesh3d(mesh, nthreads, reproducible, verbosity, stat, refine,
                         optimize, threshold, hxt_boundary_recovery));
  HXT_CHECK(hxtMeshWriteGmsh(mesh, "hxt.msh"));
  HXT_CHECK(hxtMeshDelete(&mesh));
  HXT_CHECK(hxtContextDelete(&context));
  return HXT_STATUS_OK;
}

int meshGRegionHxt(GRegion *gr)
{
  HXTStatus status = _meshGRegionHxt(gr);
  if(status == HXT_STATUS_OK) return 0;
  return 1;
}

#else

int meshGRegionHxt(GRegion *gr)
{
  Msg::Error("Gmsh should be compile with Hxt to enable that option");
  return -1;
}

#endif
