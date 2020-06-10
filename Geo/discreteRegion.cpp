// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "discreteRegion.h"
#include "MVertex.h"
#include "GModelIO_GEO.h"
#include "Geo.h"
#include "Context.h"

#if defined(HAVE_MESH)
#include "meshGRegion.h"
#include "meshGRegionDelaunayInsertion.h"
#endif

discreteRegion::discreteRegion(GModel *model, int num) : GRegion(model, num)
{
  ::Volume *v = CreateVolume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(model->getGEOInternals()->Volumes, &v);
}

discreteRegion::discreteRegion(GModel *model) : GRegion(model, 0)
{
}

void discreteRegion::findFaces(
  std::map<MFace, std::vector<int>, MFaceLessThan> &map_faces)
{
  std::set<MFace, MFaceLessThan> bound_faces;
  for(std::size_t elem = 0; elem < getNumMeshElements(); elem++) {
    MElement *e = getMeshElement(elem);
    for(int iFace = 0; iFace < e->getNumFaces(); iFace++) {
      MFace tmp_face = e->getFace(iFace);
      std::set<MFace, MFaceLessThan>::iterator itset = bound_faces.find(tmp_face);
      if(itset == bound_faces.end())
        bound_faces.insert(tmp_face);
      else
        bound_faces.erase(itset);
    }
  }

  // for the boundary faces, associate the tag of the discrete face
  for(std::set<MFace, MFaceLessThan>::iterator itv = bound_faces.begin();
      itv != bound_faces.end(); ++itv) {
    std::map<MFace, std::vector<int>, MFaceLessThan>::iterator itmap =
      map_faces.find(*itv);
    if(itmap == map_faces.end()) {
      std::vector<int> tagRegions;
      tagRegions.push_back(tag());
      map_faces.insert(std::make_pair(*itv, tagRegions));
    }
    else {
      std::vector<int> tagRegions = itmap->second;
      tagRegions.push_back(tag());
      itmap->second = tagRegions;
    }
  }
}

void discreteRegion::remesh()
{
#if defined(HAVE_MESH)

  bool classify = false;
  insertVerticesInRegion(this, CTX::instance()->mesh.maxIterDelaunay3D,
                         1., classify);

  // not functional yet: need boundaries
  for(int i = 0; i < std::max(CTX::instance()->mesh.optimize,
                              CTX::instance()->mesh.optimizeNetgen); i++) {
    if(CTX::instance()->mesh.optimize >= i) {
      optimizeMeshGRegion opt;
      opt(this, true);
    }
    if(CTX::instance()->mesh.optimizeNetgen >= i) {
      optimizeMeshGRegionNetgen opt;
      opt(this, true);
    }
  }

#endif
}
