// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "gmsh.h"
#include "GmshGlobal.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"

// gmsh

int gmshInitialize(int argc, char **argv)
{
  return !GmshInitialize(argc, argv);
}

int gmshFinalize()
{
  return !GmshFinalize();
}

int gmshOpen(const std::string &fileName)
{
  return !GmshOpenProject(fileName);
}

int gmshMerge(const std::string &fileName)
{
  return !GmshMergeFile(fileName);
}

int gmshExport(const std::string &fileName)
{
  return !GmshWriteFile(fileName);
}

int gmshClear()
{
  return !GmshClearProject();
}

// gmshOption

static void splitOptionName(const std::string &fullName, std::string &category,
                            std::string &name, int &index)
{
  std::string::size_type d = fullName.find_first_of('.');
  if(d == std::string::npos){
    name = fullName;
    return;
  }
  category = fullName.substr(0, d);
  std::string::size_type b1 = fullName.find_first_of('[');
  std::string::size_type b2 = fullName.find_last_of(']');
  if(b1 != std::string::npos && b2 != std::string::npos){
    std::string id = fullName.substr(b1 + 1, b2 - b1 - 1);
    index = atoi(id.c_str());
    category = fullName.substr(0, b1);
    name = fullName.substr(d + 1, b1 - d);
  }
  else{
    index = 0;
    name = fullName.substr(d + 1);
  }
  Msg::Debug("Decoded option name '%s' . '%s' (index %d)", category.c_str(),
             name.c_str(), index);
}

int gmshOptionSetNumber(const std::string &name, double value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetNumber(const std::string &name, double &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

int gmshOptionSetString(const std::string &name, const std::string &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshSetOption(c, n, value, i);
}

int gmshOptionGetString(const std::string &name, std::string &value)
{
  std::string c, n;
  int i;
  splitOptionName(name, c, n, i);
  return !GmshGetOption(c, n, value, i);
}

// gmshModel

int gmshModelCreate(const std::string &name)
{
  GModel *m = new GModel(name);
  return m ? 0 : 1;
}

int gmshModelSetCurrent(const std::string &name)
{
  GModel *m = GModel::findByName(name);
  if(m){
    GModel::setCurrent(m);
    return 0;
  }
  return 1;
}

int gmshModelDestroy()
{
  GModel *m = GModel::current();
  if(m){
    delete m;
    return 0;
  }
  return 1;
}

int gmshModelGetElementaryTags(int dim, std::vector<int> &tags)
{
  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  tags.clear();
  for(unsigned int i = 0; i < entities.size(); i++)
    tags.push_back(entities[i]->tag());
  return 0;
}

int gmshModelGetPhysicalTags(int dim, std::vector<int> &tags)
{
  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  tags.clear();
  for(std::map<int, std::vector<GEntity*> >::iterator it = groups.begin();
      it != groups.end(); it++)
    tags.push_back(it->first);
  return 0;
}

int gmshModelAddPhysicalGroup(int dim, int tag, const std::vector<int> &tags)
{
  bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
    (dim, tag, 0, tags);
  if(r){
    GModel::current()->getGEOInternals()->synchronize(GModel::current());
    return 0;
  }
  return 1;
}

int gmshModelGetElementaryTagsForPhysicalGroup(int dim, int tag,
                                               std::vector<int> &tags)
{
  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  std::map<int, std::vector<GEntity*> >::iterator it = groups.find(tag);
  tags.clear();
  if(it != groups.end()){
    for(unsigned j = 0; j < it->second.size(); j++)
      tags.push_back(it->second[j]->tag());
  }
  return 0;
}

int gmshModelSetPhysicalName(int dim, int tag, const std::string &name)
{
  GModel::current()->setPhysicalName(name, dim, tag);
  return 0;
}

int gmshModelGetPhysicalName(int dim, int tag, std::string &name)
{
  name = GModel::current()->getPhysicalName(dim, tag);
  return 0;
}

int gmshModelGetVertexCoordinates(int tag, double &x, double &y, double &z)
{
  GVertex *gv = GModel::current()->getVertexByTag(tag);
  if(gv){
    x = gv->x();
    y = gv->y();
    z = gv->z();
    return 0;
  }
  return 1;
}

int gmshModelGetBoundaryTags(const std::vector<std::pair<int, int> > &inDimTags,
                             std::vector<std::pair<int, int> > &outDimTags,
                             bool combined, bool oriented, bool recursive)
{
  bool r = GModel::current()->getBoundaryTags(inDimTags, outDimTags, combined,
                                              oriented, recursive);
  if(r) return 0;
  return 1;
}

int gmshModelGetElementaryTagsInBoundingBox(int dim,
                                            double x1, double y1, double z1,
                                            double x2, double y2, double z2,
                                            std::vector<int> &tags)
{
  SBoundingBox3d box(x1, y1, z1, x2, y2, z2);
  std::vector<GEntity*> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  tags.clear();
  for(unsigned int i = 0; i < entities.size(); i++)
    tags.push_back(entities[i]->tag());
  return 0;
}

int gmshModelGetBoundingBox(int dim, int tag, double &x1, double &y1, double &z1,
                            double &x2, double &y2, double &z2)
{
  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  if(!ge) return 1;
  SBoundingBox3d box = ge->bounds();
  if(box.empty()) return 2;
  x1 = box.min().x();
  y1 = box.min().y();
  z1 = box.min().z();
  x2 = box.max().x();
  y2 = box.max().y();
  z2 = box.max().z();
  return 0;
}

int gmshModelRemove(const std::vector<std::pair<int, int> > &dimTags,
                    bool recursive)
{
  GModel::current()->remove(dimTags, recursive);
  return 0;
}

int gmshModelMesh(int dim)
{
  GModel *m = GModel::current();
  if(m){
    m->mesh(dim);
    return 0;
  }
  return 1;
}

int gmshModelGetMeshVertices(int dim, int tag, std::vector<int> &vertexTags,
                             std::vector<double> &coords,
                             std::vector<double> &parametricCoords)
{
  return 0;
}

int gmshModelGetMeshElements(int dim, int tag, std::vector<int> &types,
                             std::vector<std::vector<int> > &elementTags,
                             std::vector<std::vector<int> > &vertexTags)
{
  return 0;
}

int gmshModelSetMeshSize(int dim, int tag, double size)
{
  return 0;
}

int gmshModelSetCompound(int dim, const std::vector<int> &tags)
{
  return 0;
}

int gmshModelSetTransfiniteLine(int tag, int nPoints, int type, double coef)
{
  return 0;
}

int gmshModelSetTransfiniteSurface(int tag, int arrangement,
                                   const std::vector<int> &cornerTags)
{
  return 0;
}

int gmshModelSetTransfiniteVolume(int tag, const std::vector<int> &cornerTags)
{
  return 0;
}

int gmshModelSetRecombine(int dim, int tag, double angle)
{
  return 0;
}

int gmshModelSetSmoothing(int tag, int val)
{
  return 0;
}

int gmshModelSetReverseMesh(int dim, int tag)
{
  return 0;
}

int gmshModelAddEmbeddedVertex(int tag, int inDim, int inTag)
{
  return 0;
}

// gmshModelGeo
