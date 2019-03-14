// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
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

void discreteRegion::setBoundFaces(const std::set<int> &tagFaces)
{
  for(std::set<int>::const_iterator it = tagFaces.begin(); it != tagFaces.end();
      ++it) {
    GFace *face = model()->getFaceByTag(*it);
    if(face) {
      l_faces.push_back(face);
      face->addRegion(this);
    }
    else {
      Msg::Error("Unknown model face %d", *it);
    }
  }
}

void discreteRegion::setBoundFaces(const std::vector<int> &tagFaces,
                                   const std::vector<int> &signFaces)
{
  if(tagFaces.size() != signFaces.size()) {
    Msg::Error("Wrong number of face signs in setBoundFaces");
    std::set<int> tags;
    tags.insert(tagFaces.begin(), tagFaces.end());
    setBoundFaces(tags);
  }
  for(std::size_t i = 0; i != tagFaces.size(); i++) {
    GFace *face = model()->getFaceByTag(tagFaces[i]);
    if(face) {
      l_faces.push_back(face);
      face->addRegion(this);
      l_dirs.push_back(signFaces[i]);
    }
    else {
      Msg::Error("Unknown model face %d", tagFaces[i]);
    }
  }
}

void discreteRegion::findFaces(
  std::map<MFace, std::vector<int>, Less_Face> &map_faces)
{
  std::set<MFace, Less_Face> bound_faces;
  for(std::size_t elem = 0; elem < getNumMeshElements(); elem++) {
    MElement *e = getMeshElement(elem);
    for(int iFace = 0; iFace < e->getNumFaces(); iFace++) {
      MFace tmp_face = e->getFace(iFace);
      std::set<MFace, Less_Face>::iterator itset = bound_faces.find(tmp_face);
      if(itset == bound_faces.end())
        bound_faces.insert(tmp_face);
      else
        bound_faces.erase(itset);
    }
  }

  // for the boundary faces, associate the tag of the discrete face
  for(std::set<MFace, Less_Face>::iterator itv = bound_faces.begin();
      itv != bound_faces.end(); ++itv) {
    std::map<MFace, std::vector<int>, Less_Face>::iterator itmap =
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
  insertVerticesInRegion(this, 2000000000, classify);

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
