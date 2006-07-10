#include "gmshModel.h"
#include "Mesh.h"
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
  : GModel ( "noname" )
{
  convertFromUglyOldDataStructuresgmshModel();
}

gmshModel::gmshModel(char *geofile)
  : GModel ( geofile )
{
      OpenProblem ( geofile );
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
      if (c->Num >=0)
	{
	  if (points.find(c->beg) == points.end())
	    {
	      points.insert(c->beg);
	      gmshVertex *v = new gmshVertex ( this, c->beg );
	      //vertices.push_back(v); 
	      add(v);
	    }
	  if (points.find(c->end) == points.end())
	    {
	      points.insert(c->end);
	      gmshVertex *v = new gmshVertex ( this , c->end );
	      //vertices.push_back(v); 
	      add(v);
	    }
	  gmshEdge *e = new gmshEdge ( this, c ,
				       vertexByTag(c->beg->Num),
				       vertexByTag(c->end->Num) );
	  //	  edges.push_back(e);     	  
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
      //      faces.push_back(f); 
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
      //      regions.push_back(r); 
      add ( r);
    }
    List_Delete(volumes);
  }

  Msg (INFO,"gmshModel Created\n");
  Msg (INFO,"%d Vertices\n",vertices.size());
  Msg (INFO,"%d Edges   \n",edges.size());
  Msg (INFO,"%d Faces\n",faces.size());
  Msg (INFO,"%d Regions\n" ,regions.size());

}

GModel *createGmshModel (char *f )
{
  return new gmshModel (f);
}
