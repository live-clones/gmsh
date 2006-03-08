#include "gmshModel.h"
#include "OpenFile.h"
#include "Tools.h"
#include "Message.h"

extern Mesh *THEM;
GFace * gmshModel::faceByTag(int n) const
{
  std::list<GFace*>:: const_iterator it = faces.begin();
  std::list<GFace*>:: const_iterator end = faces.end();
  while (it != end)
    {
      gmshFace *ff = (gmshFace*) (*it);
      if ( ff->s->Num == n)return *it;
      ++it;
    }
  return 0;
}

GEdge * gmshModel::edgeByTag(int n) const
{
  std::list<GEdge*>:: const_iterator it = edges.begin();
  std::list<GEdge*>:: const_iterator end = edges.end();
  while (it != end)
    {
      gmshEdge *ee = (gmshEdge*) (*it);
      if ( ee->c->Num == n)return *it;
      ++it;
    }
  return 0;
}
GVertex * gmshModel::vertexByTag(int n) const
{
  std::list<GVertex*>:: const_iterator it = vertices.begin();
  std::list<GVertex*>:: const_iterator end = vertices.end();
  while (it != end)
    {
      gmshVertex *vv = (gmshVertex*) (*it);
      if ( vv->v->Num == n)return *it;
      ++it;
    }
  return 0;
}
gmshModel::gmshModel(char *geofile)
  : SGModel ( "toto" )
{
  if (geofile)
    {
      OpenProblem ( geofile );
    }
  
  std::set<Vertex*> points;

  if(Tree_Nbr(THEM->Curves)) {
    List_T *curves = Tree2List(THEM->Curves);
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if (c->Num >=0)
	{
	  if (points.find(c->beg) == points.end())
	    {
	      points.insert(c->beg);
	      gmshVertex *v = new gmshVertex ( this, c->beg );
	      vertices.push_back(v); 
	      add(v);
	    }
	  if (points.find(c->end) == points.end())
	    {
	      points.insert(c->end);
	      gmshVertex *v = new gmshVertex ( this , c->end );
	      vertices.push_back(v); 
	      add(v);
	    }
	  gmshEdge *e = new gmshEdge ( this, c ,
				       vertexByTag(c->beg->Num),
				       vertexByTag(c->end->Num) );
	  edges.push_back(e);     	  
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
      faces.push_back(f); 
      add ( f);
    }
    List_Delete(surfaces);
  } 
  if(Tree_Nbr(THEM->Volumes)) {
    List_T *volumes = Tree2List(THEM->Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++){
      Volume *v;
      List_Read(volumes, i, &v);
      gmshRegion *r = new gmshRegion ( this, v );
      regions.push_back(r); 
      add ( r);
    }
    List_Delete(volumes);
  }

  //Msg (INFO,"gmshModel Created\n");
  //Msg (INFO,"%d Vertices\n",vertices.size());
  //Msg (INFO,"%d Edges   \n",edges.size());
  //Msg (INFO,"%d Faces\n",faces.size());
  //Msg (INFO,"%d Regions\n" ,regions.size());

}

SGModel *createGmshModel (char *f )
{
  return new gmshModel (f);
}
