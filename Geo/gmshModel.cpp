#include "gmshModel.h"
#include "Mesh.h"
#include "Geo.h"
#include "GPoint.h"
#include "SPoint2.h"
#include "SPoint3.h"
#include "SBoundingBox3d.h"
#include "OpenFile.h"
#include "Tools.h"
#include "Message.h"
#include "gmshVertex.h"
#include "gmshFace.h"
#include "gmshEdge.h"
#include "gmshRegion.h"

extern Mesh *THEM;

gmshModel::gmshModel()
  : GModel("noname")
{
  convertFromUglyOldDataStructuresgmshModel();
}

gmshModel::gmshModel(char *geofile)
  : GModel(geofile)
{
  OpenProblem(geofile);
  convertFromUglyOldDataStructuresgmshModel();
}

void gmshModel::convertFromUglyOldDataStructuresgmshModel()
{
  std::set<Vertex*> points;

  if(Tree_Nbr(THEM->Curves)) {
    List_T *curves = Tree2List(THEM->Curves);
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0 && c->beg && c->end){
	if(points.find(c->beg) == points.end()){
	  points.insert(c->beg);
	  gmshVertex *v = new gmshVertex(this, c->beg);
	  add(v);
	}
	if(points.find(c->end) == points.end()){
	  points.insert(c->end);
	  gmshVertex *v = new gmshVertex(this, c->end);
	  add(v);
	}
	gmshEdge *e = new gmshEdge (this, c,
				    vertexByTag(c->beg->Num),
				    vertexByTag(c->end->Num) );
	add(e);
      }
    }
    List_Delete(curves);
  }
  if(Tree_Nbr(THEM->Surfaces)) {
    List_T *surfaces = Tree2List(THEM->Surfaces);
    for(int i = 0; i < List_Nbr(surfaces); i++){
      Surface *s;
      List_Read(surfaces, i, &s);
      gmshFace *f = new gmshFace ( this, s );
      add(f);
    }
    List_Delete(surfaces);
  } 
  if(Tree_Nbr(THEM->Volumes)) {
    List_T *volumes = Tree2List(THEM->Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++){
      Volume *v;
      List_Read(volumes, i, &v);
      gmshRegion *r = new gmshRegion(this, v);
      add(r);
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
      if(ge) ge->physicals.push_back(p->Num);
    }
  }
  
  Msg(DEBUG, "gmshModel Created");
  Msg(DEBUG, "%d Vertices", vertices.size());
  Msg(DEBUG, "%d Edges", edges.size());
  Msg(DEBUG, "%d Faces", faces.size());
  Msg(DEBUG, "%d Regions", regions.size());
}

GModel *createGmshModel(char *f)
{
  return new gmshModel(f);
}
