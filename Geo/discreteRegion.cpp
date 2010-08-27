// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "discreteRegion.h"
#include "MVertex.h"
#include "Geo.h"

discreteRegion::discreteRegion(GModel *model, int num) : GRegion(model, num)
{
  ::Volume *v = Create_Volume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(model->getGEOInternals()->Volumes, &v);
}

void discreteRegion::setBoundFaces(std::set<int> tagFaces)
{

  for (std::set<int>::iterator it = tagFaces.begin() ; it != tagFaces.end();++it){
    GFace *face = model()->getFaceByTag(*it);
    l_faces.push_back(face);
    face->addRegion(this);
  }

  // in case discrete region already exist
  // to modify to take into account appropriate faces
  // for(GModel::fiter face = model()->firstFace(); face != model()->lastFace(); face++){
  //   l_faces.push_back(*face);
  //   (*face)->addRegion(this);
  // }
}

void discreteRegion::findFaces(std::map<MFace, std::vector<int>, Less_Face> &map_faces)
{

  std::set<MFace, Less_Face> bound_faces;
  for (unsigned int elem = 0; elem  < getNumMeshElements() ; elem++) {
    MElement *e = getMeshElement(elem);
    for (int iFace = 0; iFace < e->getNumFaces(); iFace++) {
      MFace tmp_face =  e->getFace(iFace);
      std::set<MFace, Less_Face >::iterator itset = bound_faces.find(tmp_face);
      if (itset == bound_faces.end())   bound_faces.insert(tmp_face);
      else bound_faces.erase(itset);
    }
  }

  // for the boundary faces, associate the tag of the current discrete face
  for (std::set<MFace, Less_Face>::iterator itv = bound_faces.begin();
       itv != bound_faces.end(); ++itv){
    std::map<MFace, std::vector<int>, Less_Face >::iterator itmap = map_faces.find(*itv);
    if (itmap == map_faces.end()){
      std::vector<int> tagRegions;
      tagRegions.push_back(tag());
      map_faces.insert(std::make_pair(*itv, tagRegions));
    }
    else{
      std::vector<int> tagRegions = itmap->second;
      tagRegions.push_back(tag());
      itmap->second = tagRegions;
    }
  }

}
