// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "Geo.h"
#include "OpenFile.h"
#include "Numeric.h"
#include "ListUtils.h"
#include "gmshVertex.h"
#include "gmshFace.h"
#include "GFaceCompound.h"
#include "GEdgeCompound.h"
#include "gmshEdge.h"
#include "gmshRegion.h"
#include "Field.h"

#if !defined(HAVE_NO_PARSER)
#include "Parser.h"
#endif

void GModel::_createGEOInternals()
{
  _geo_internals = new GEO_Internals;
}

void GModel::_deleteGEOInternals()
{
  delete _geo_internals;
  _geo_internals = 0;
}

int GModel::readGEO(const std::string &name)
{
  ParseFile(name, true);
  return importGEOInternals();
}

int GModel::importGEOInternals()
{
  if(Tree_Nbr(_geo_internals->Points)) {
    List_T *points = Tree2List(_geo_internals->Points);
    for(int i = 0; i < List_Nbr(points); i++){
      Vertex *p;
      List_Read(points, i, &p);
      GVertex *v = getVertexByTag(p->Num);
      if(!v){
        v = new gmshVertex(this, p);
        add(v);
      }
      if(!p->Visible) v->setVisibility(0);
    }
    List_Delete(points);
  }
  if(Tree_Nbr(_geo_internals->Curves)) {
    List_T *curves = Tree2List(_geo_internals->Curves);
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0 && c->beg && c->end){
        GEdge *e = getEdgeByTag(c->Num);
        if(!e){
          e = new gmshEdge(this, c,
                           getVertexByTag(c->beg->Num),
                           getVertexByTag(c->end->Num));
         add(e);
        }
        else
          e->resetMeshAttributes();
        if(!c->Visible) e->setVisibility(0);
        if(c->Color.type) e->setColor(c->Color.mesh);
      }
    }
    List_Delete(curves);
  }
  if(Tree_Nbr(_geo_internals->Surfaces)) {
    List_T *surfaces = Tree2List(_geo_internals->Surfaces);
    for(int i = 0; i < List_Nbr(surfaces); i++){
      Surface *s;
      List_Read(surfaces, i, &s);
      GFace *f = getFaceByTag(s->Num);
      if(!f){
        f = new gmshFace(this, s);
        add(f);
      }
      else
        f->resetMeshAttributes();
      if(!s->Visible) f->setVisibility(0);
      if(s->Color.type) f->setColor(s->Color.mesh);
    }
    List_Delete(surfaces);
  } 
  if(Tree_Nbr(_geo_internals->Volumes)) {
    List_T *volumes = Tree2List(_geo_internals->Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++){
      Volume *v;
      List_Read(volumes, i, &v);
      GRegion *r = getRegionByTag(v->Num);
      if(!r){
        r = new gmshRegion(this, v);
        add(r);
      }
      else
        r->resetMeshAttributes();       
      if(!v->Visible) r->setVisibility(0);
      if(v->Color.type) r->setColor(v->Color.mesh);
    }
    List_Delete(volumes);
  }
  for(int i = 0; i < List_Nbr(_geo_internals->PhysicalGroups); i++){
    PhysicalGroup *p;
    List_Read(_geo_internals->PhysicalGroups, i, &p);
    std::list<GFace*>f_compound;
    std::vector<GEdge*>e_compound;
    for(int j = 0; j < List_Nbr(p->Entities); j++){
      int num;
      List_Read(p->Entities, j, &num);
      GEntity *ge = 0;
      switch(p->Typ){
      case MSH_PHYSICAL_POINT:   ge = getVertexByTag(abs(num)); break;
      case MSH_PHYSICAL_LINE: 
	ge = getEdgeByTag(abs(num));
	e_compound.push_back(getEdgeByTag(abs(num)));
	break; 
     case MSH_PHYSICAL_SURFACE: 
	ge = getFaceByTag(abs(num));
	f_compound.push_back(getFaceByTag(abs(num))); 
	break;
      case MSH_PHYSICAL_VOLUME:  ge = getRegionByTag(abs(num)); break;
      }
      int pnum = sign(num) * p->Num;
      if(ge && std::find(ge->physicals.begin(), ge->physicals.end(), pnum) == 
         ge->physicals.end())
        ge->physicals.push_back(pnum);
    }
    // the physical is a compound i.e. we allow the meshes
    // not to conform internal MEdges of the compound
    // the physical is a compound i.e. we allow the meshes
    // not to conform internal MEdges of the compound

    if (p->Typ == MSH_PHYSICAL_LINE && p->Boundaries[0]){
      GEdge *ge = getEdgeByTag(abs(p->Num));
      if (!ge){
	GEdgeCompound *ge = new GEdgeCompound(this, p->Num, e_compound);
	add(ge);
      }
      else
        ge->resetMeshAttributes();
    }      
    if (p->Typ == MSH_PHYSICAL_SURFACE && p->Boundaries[0]){
      int i = 0;
      List_T *bnd;
      std::list<GEdge*> b[4];
      while((bnd = p->Boundaries[i])){
	if (i > 3)break;
	for(int j = 0; j < List_Nbr(bnd); j++){
	  int ie;
	  List_Read(bnd, j, &ie);
	  b[i].push_back(getEdgeByTag(abs(ie)));
	}
	i++;
      }
      GFace *gf = getFaceByTag(abs(p->Num));
      if (!gf){
	GFaceCompound *gf = new GFaceCompound(this, p->Num, f_compound, 
                                              b[0], b[1], b[2], b[3]);
	add(gf);
      }
      else
        gf->resetMeshAttributes();
    }      
  }

  Msg::Debug("Gmsh model imported:");
  Msg::Debug("%d Vertices", vertices.size());
  Msg::Debug("%d Edges", edges.size());
  Msg::Debug("%d Faces", faces.size());
  Msg::Debug("%d Regions", regions.size());

  return 1;
}

class writeFieldOptionGEO {
 private :
  FILE *geo;
  Field *field;
 public :
  writeFieldOptionGEO(FILE *fp,Field *_field) { geo = fp ? fp : stdout; field=_field; }
  void operator() (std::pair<std::string, FieldOption *> it)
  {
    std::string v;
    it.second->getTextRepresentation(v);
    fprintf(geo, "Field[%i].%s = %s;\n", field->id, it.first.c_str(), v.c_str());
  }
};

class writeFieldGEO {
 private :
  FILE *geo;
 public :
  writeFieldGEO(FILE *fp) { geo = fp ? fp : stdout; }
  void operator() (std::pair<const int, Field *> it)
  {
    fprintf(geo, "Field[%i] = %s;\n", it.first, it.second->getName());
    std::for_each(it.second->options.begin(), it.second->options.end(),
                  writeFieldOptionGEO(geo, it.second));
  }
};

class writePhysicalGroupGEO {
 private :
  FILE *geo;
  int dim;
  bool printLabels;
  std::map<int, std::string> &oldLabels;
  std::map<std::pair<int, int>, std::string> &newLabels;
 public :
  writePhysicalGroupGEO(FILE *fp, int i, bool labels,
                        std::map<int, std::string> &o,
                        std::map<std::pair<int, int>, std::string> &n)
    : dim(i), printLabels(labels), oldLabels(o), newLabels(n)
  { 
    geo = fp ? fp : stdout; 
  }
  void operator () (std::pair<const int, std::vector<GEntity *> > &g)
  {
    std::string oldName, newName;
    if(printLabels){
      if(oldLabels.count(g.first)) {
        oldName = oldLabels[g.first];
        fprintf(geo, "%s = %d;\n", oldName.c_str(), g.first);
      }
      else if(newLabels.count(std::pair<int, int>(dim, g.first))) {
        newName = newLabels[std::pair<int, int>(dim, g.first)];
      }
    }

    switch (dim) {
    case 0: fprintf(geo, "Physical Point"); break;
    case 1: fprintf(geo, "Physical Line"); break;
    case 2: fprintf(geo, "Physical Surface"); break;
    case 3: fprintf(geo, "Physical Volume"); break;
    }

    if(oldName.size())
      fprintf(geo, "(%s) = {", oldName.c_str());
    else if(newName.size())
      fprintf(geo, "(\"%s\") = {", newName.c_str());
    else
      fprintf(geo, "(%d) = {", g.first);
    for(unsigned int i = 0; i < g.second.size(); i++) {
      if(i) fprintf(geo, ", ");
      fprintf(geo, "%d", g.second[i]->tag());
    }
    fprintf(geo, "};\n");
  }
};

int GModel::writeGEO(const std::string &name, bool printLabels)
{
  FILE *fp = fopen(name.c_str(), "w");

  for(viter it = firstVertex(); it != lastVertex(); it++)
    (*it)->writeGEO(fp);
  for(eiter it = firstEdge(); it != lastEdge(); it++)
    (*it)->writeGEO(fp);
  for(fiter it = firstFace(); it != lastFace(); it++)
    (*it)->writeGEO(fp);
  for(riter it = firstRegion(); it != lastRegion(); it++)
    (*it)->writeGEO(fp);

  std::map<int, std::string> labels;
#if !defined(HAVE_NO_PARSER)
  // get "old-style" labels from parser
  for(std::map<std::string, std::vector<double> >::iterator it = gmsh_yysymbols.begin();
      it != gmsh_yysymbols.end(); ++it)
    for(unsigned int i = 0; i < it->second.size(); i++)
      labels[(int)it->second[i]] = it->first;
#endif
  
  std::map<int, std::vector<GEntity*> > groups[4];
  getPhysicalGroups(groups);
  for(int i = 0; i < 4; i++)
    std::for_each(groups[i].begin(), groups[i].end(), 
                  writePhysicalGroupGEO(fp, i, printLabels, labels, physicalNames));
  
  std::for_each(getFields()->begin(), getFields()->end(), writeFieldGEO(fp));
  if(getFields()->background_field > 0)
    fprintf(fp, "Background Field = %i;\n", getFields()->background_field);

  if(fp) fclose(fp);
  return 1;
}
