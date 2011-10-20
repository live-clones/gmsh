// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
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
#include "GRegionCompound.h"
#include "gmshEdge.h"
#include "gmshRegion.h"
#include "Field.h"
#include "Context.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

void GModel::_createGEOInternals()
{
  _geo_internals = new GEO_Internals;
}

void GModel::_deleteGEOInternals()
{
  if(_geo_internals) delete _geo_internals;
  _geo_internals = 0;
}

int GModel::readGEO(const std::string &name)
{
  ParseFile(name, true);
  return GModel::current()->importGEOInternals();
}

int GModel::exportDiscreteGEOInternals()
{

  if(_geo_internals) delete _geo_internals;
  _geo_internals = new GEO_Internals;

  for(viter it = firstVertex(); it != lastVertex(); it++){
    Vertex *v = Create_Vertex((*it)->tag(), (*it)->x(), (*it)->y(), (*it)->z(),
                              (*it)->prescribedMeshSizeAtVertex(), 1.0);
    Tree_Add(GModel::current()->getGEOInternals()->Points, &v);
  }

  for(eiter it = firstEdge(); it != lastEdge(); it++){
    if((*it)->geomType() == GEntity::DiscreteCurve){
      Curve *c = Create_Curve((*it)->tag(), MSH_SEGM_DISCRETE, 1,
                              NULL, NULL, -1, -1, 0., 1.);
      List_T *points = Tree2List(_geo_internals->Points);
      GVertex *gvb = (*it)->getBeginVertex();
      GVertex *gve = (*it)->getEndVertex();
      int nb = 2 ;
      c->Control_Points = List_Create(nb, 1, sizeof(Vertex *));
      for(int i = 0; i < List_Nbr(points); i++) {
        Vertex *v;
        List_Read(points, i, &v);
        if (v->Num == gvb->tag()) {
          List_Add(c->Control_Points, &v);
          c->beg = v;
        }
        if (v->Num == gve->tag()) {
          List_Add(c->Control_Points, &v);
          c->end = v;
        }       
      }
      End_Curve(c);
      Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
      CreateReversedCurve(c);
    }
  }

  for(fiter it = firstFace(); it != lastFace(); it++){
    if((*it)->geomType() == GEntity::DiscreteSurface){
      Surface *s = Create_Surface((*it)->tag(), MSH_SURF_DISCRETE);
      std::list<GEdge*> edges = (*it)->edges();
      s->Generatrices = List_Create(edges.size(), 1, sizeof(Curve *));
      List_T *curves = Tree2List(_geo_internals->Curves);
      Curve *c;
      for(std::list<GEdge*>::iterator ite = edges.begin(); ite != edges.end(); ite++){
        for(int i = 0; i < List_Nbr(curves); i++) {
          List_Read(curves, i, &c);
          if (c->Num == (*ite)->tag()) {
            List_Add(s->Generatrices, &c);
          }
        }
      }
      Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
    }
  }

  // TODO: create Volumes from discreteRegions

  Msg::Debug("Geo internal model has:");
  List_T *points = Tree2List(_geo_internals->Points);
  List_T *curves = Tree2List(_geo_internals->Curves);
  List_T *surfaces = Tree2List(_geo_internals->Surfaces);  
  Msg::Debug("%d Vertices", List_Nbr(points));
  Msg::Debug("%d Edges", List_Nbr(curves));
  Msg::Debug("%d Faces", List_Nbr(surfaces));

  return 1;
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
      if(c->Num >= 0){
        GEdge *e = getEdgeByTag(c->Num);
        if(!e && c->Typ == MSH_SEGM_COMPOUND){
          std::vector<GEdge*> comp;
          for(unsigned int j = 0; j < c->compound.size(); j++){
            GEdge *ge = getEdgeByTag(c->compound[j]);
            if(ge) comp.push_back(ge);
          }
          e = new GEdgeCompound(this, c->Num, comp);
          add(e);
        }
        else if(!e && c->beg && c->end){
          e = new gmshEdge(this, c,
                           getVertexByTag(c->beg->Num),
                           getVertexByTag(c->end->Num));
          add(e);
        }
        else if(!e){
          e = new gmshEdge(this, c, 0, 0);
          add(e);
        }
        else
          e->resetMeshAttributes();
        if(!c->Visible) e->setVisibility(0);
        if(c->Color.type) e->setColor(c->Color.mesh);
        if(c->degenerated) {
          e->setTooSmall(true);
        }
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
      if(!f && s->Typ == MSH_SURF_COMPOUND){
        std::list<GFace*> comp;
        for(unsigned int j = 0; j < s->compound.size(); j++){
          GFace *gf = getFaceByTag(s->compound[j]);
          if(gf)
            comp.push_back(gf);
        }
        std::list<GEdge*> U0;
        for(int j = 0; j < 4; j++){
          for(unsigned int k = 0; k < s->compoundBoundary[j].size(); k++){
            GEdge *ge = getEdgeByTag(s->compoundBoundary[j][k]);
            if(ge) U0.push_back(ge);
          }
        }
        int param = CTX::instance()->mesh.remeshParam;
        GFaceCompound::typeOfMapping typ = GFaceCompound::HARMONIC;
        if (param == 1) typ =  GFaceCompound::CONFORMAL;
        if (param == 2) typ =  GFaceCompound::RBF;
        int algo = CTX::instance()->mesh.remeshAlgo;
	f = new GFaceCompound(this, s->Num, comp, U0, typ, algo);

        f->meshAttributes.recombine = s->Recombine;
        f->meshAttributes.recombineAngle = s->RecombineAngle;
        f->meshAttributes.Method = s->Method;
        f->meshAttributes.extrude = s->Extrude;
        add(f);
        if (CTX::instance()->compoundOnly)
          for (std::list<GFace*>::iterator it = comp.begin(); it != comp.end(); ++it)
            (*it)->setVisibility(0,true);
        if(s->EmbeddedCurves){
          for(int i = 0; i < List_Nbr(s->EmbeddedCurves); i++){
            Curve *c;
            List_Read(s->EmbeddedCurves, i, &c);
            GEdge *e = getEdgeByTag(abs(c->Num));
            if(e)
              f->addEmbeddedEdge(e);
            else
              Msg::Error("Unknown curve %d", c->Num);
          }
        }
        if(s->EmbeddedPoints){
          for(int i = 0; i < List_Nbr(s->EmbeddedPoints); i++){
            Vertex *v;
            List_Read(s->EmbeddedPoints, i, &v);
            GVertex *gv = getVertexByTag(v->Num);
            if(gv)
              f->addEmbeddedVertex(gv);
            else
              Msg::Error("Unknown point %d", v->Num);
          }
        }
      }
      else if(!f){
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
      if(!r && v->Typ == MSH_VOLUME_COMPOUND){
        std::vector<GRegion*> comp;
        for(unsigned int j = 0; j < v->compound.size(); j++){
          GRegion *gr = getRegionByTag(v->compound[j]);
          if(gr) comp.push_back(gr);
        }
        r = new GRegionCompound(this, v->Num, comp);
        add(r);
      }
      else if(!r){
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
    for(int j = 0; j < List_Nbr(p->Entities); j++){
      int num;
      List_Read(p->Entities, j, &num);
      GEntity *ge = 0;
      switch(p->Typ){
      case MSH_PHYSICAL_POINT:   ge = getVertexByTag(abs(num)); break;
      case MSH_PHYSICAL_LINE:    ge = getEdgeByTag(abs(num)); break; 
      case MSH_PHYSICAL_SURFACE: ge = getFaceByTag(abs(num)); break;
      case MSH_PHYSICAL_VOLUME:  ge = getRegionByTag(abs(num)); break;
      }
      int pnum = sign(num) * p->Num;
      if(ge && std::find(ge->physicals.begin(), ge->physicals.end(), pnum) == 
         ge->physicals.end())
        ge->physicals.push_back(pnum);
    }
  }

  updateUpperTopology();

  Msg::Debug("Gmsh model (GModel) imported:");
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

  std::map<double, std::string> meshSizeParameters;
  int cpt = 0;
  for(viter it = firstVertex(); it != lastVertex(); it++){
    double val = (*it)->prescribedMeshSizeAtVertex();
    if(meshSizeParameters.find(val) == meshSizeParameters.end()){
      std::ostringstream paramName;
      paramName << "cl" << ++cpt;
      fprintf(fp, "%s = %.16g;\n", paramName.str().c_str(),val);
      meshSizeParameters.insert(std::make_pair(val, paramName.str()));
    }
  }
  for(viter it = firstVertex(); it != lastVertex(); it++){
    double val = (*it)->prescribedMeshSizeAtVertex();
    (*it)->writeGEO(fp, meshSizeParameters[val]);
  }
  for(eiter it = firstEdge(); it != lastEdge(); it++)
    (*it)->writeGEO(fp);
  for(fiter it = firstFace(); it != lastFace(); it++)
    (*it)->writeGEO(fp);
  for(riter it = firstRegion(); it != lastRegion(); it++)
    (*it)->writeGEO(fp);

  std::map<int, std::string> labels;
#if defined(HAVE_PARSER)
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
