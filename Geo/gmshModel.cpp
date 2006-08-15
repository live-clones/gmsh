#include "gmshModel.h"
#include "Mesh.h"
#include "Geo.h"
#include "Tools.h"
#include "Message.h"
#include "gmshVertex.h"
#include "gmshFace.h"
#include "gmshEdge.h"
#include "gmshRegion.h"

extern Mesh *THEM;

void gmshModel::import()
{
  // When en entity that already exists is reimported, we don't do
  // anything (except making it invisible if we are asked to)

  if(Tree_Nbr(THEM->Points)) {
    List_T *points = Tree2List(THEM->Points);
    for(int i = 0; i < List_Nbr(points); i++){
      Vertex *p;
      List_Read(points, i, &p);
      GVertex *v = vertexByTag(p->Num);
      if(!v){
	v = new gmshVertex(this, p);
	add(v);
      }
      if(!p->Visible) v->setVisibility(0);
    }
    List_Delete(points);
  }
  if(Tree_Nbr(THEM->Curves)) {
    List_T *curves = Tree2List(THEM->Curves);
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0 && c->beg && c->end){
	GEdge *e = edgeByTag(c->Num);
	if(!e){
	  e = new gmshEdge(this, c,
			   vertexByTag(c->beg->Num),
			   vertexByTag(c->end->Num));
	  add(e);
	}
	if(!c->Visible) e->setVisibility(0);
	if(c->Color.type) e->setColor(c->Color.mesh);
      }
    }
    List_Delete(curves);
  }
  if(Tree_Nbr(THEM->Surfaces)) {
    List_T *surfaces = Tree2List(THEM->Surfaces);
    for(int i = 0; i < List_Nbr(surfaces); i++){
      Surface *s;
      List_Read(surfaces, i, &s);
      GFace *f = faceByTag(s->Num);
      if(!f){
	f = new gmshFace(this, s);
	add(f);
      }
      if(!s->Visible) f->setVisibility(0);
      if(s->Color.type) f->setColor(s->Color.mesh);
    }
    List_Delete(surfaces);
  } 
  if(Tree_Nbr(THEM->Volumes)) {
    List_T *volumes = Tree2List(THEM->Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++){
      Volume *v;
      List_Read(volumes, i, &v);
      GRegion *r = regionByTag(v->Num);
      if(!r){
	r = new gmshRegion(this, v);
	add(r);
      }
      if(!v->Visible) r->setVisibility(0);
      if(v->Color.type) r->setColor(v->Color.mesh);
    }
    List_Delete(volumes);
  }
  for(int i = 0; i < List_Nbr(THEM->PhysicalGroups); i++){
    PhysicalGroup *p;
    List_Read(THEM->PhysicalGroups, i, &p);
    for(int j = 0; j < List_Nbr(p->Entities); j++){
      int num;
      List_Read(p->Entities, j, &num);
      GEntity *ge = 0;
      switch(p->Typ){
      case MSH_PHYSICAL_POINT:   ge = vertexByTag(num); break;
      case MSH_PHYSICAL_LINE:    ge = edgeByTag(num); break;
      case MSH_PHYSICAL_SURFACE: ge = faceByTag(num); break;
      case MSH_PHYSICAL_VOLUME:  ge = regionByTag(num); break;
      }
      if(ge && std::find(ge->physicals.begin(), ge->physicals.end(), p->Num) == 
	 ge->physicals.end())
	ge->physicals.push_back(p->Num);
    }
  }
  
  Msg(DEBUG, "gmshModel:");
  Msg(DEBUG, "%d Vertices", vertices.size());
  Msg(DEBUG, "%d Edges", edges.size());
  Msg(DEBUG, "%d Faces", faces.size());
  Msg(DEBUG, "%d Regions", regions.size());
}
