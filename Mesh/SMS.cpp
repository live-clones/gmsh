#include <iostream.h>
#include <assert.h>
#include "Gmsh.h"
#include "Geo.h"
#include "Mesh.h"
#include "Create.h"
#include "MinMax.h"
#include "Vertex.h"
#include "CAD.h"
#include "Context.h"
#include "Message.h"

extern Context_T CTX;

/*
  Reads a SMS mesh file format.
  Fills the Mesh structure and says
  the interface that the state of the current
  mesh is 3.

*/

#define ENTITY_VERTEX 0
#define ENTITY_EDGE   1
#define ENTITY_FACE   2
#define ENTITY_REGION 3
#define ENTITY_NONE   4
extern int FACE_DIMENSION;
void TRIE_MON_GARS2 (void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  s->Fourre_Simplexe (s->V[0], s->V[1], s->V[2], s->V[3]);
}

void Read_VTK_File (char *file, Mesh *m)
{
  
  FILE *in = fopen (file,"r");
  if(!in)return;
  char line[256],dumline1[256],dumline2[256];
  int i;
  int NbFaces,NbVertices,Vertex1,Vertex2,Vertex3,NbVerticesOnFace;
  double x,y,z;
  Vertex *v1,*v2,*v3,*v4;

  fgets(line,255,in);
  fgets(line,255,in);
  fgets(line,255,in);
  fgets(line,255,in);
  fgets(line,255,in);
  sscanf(line,"%s %d %s",dumline1,&NbVertices,dumline2);

  Surface *surf = Create_Surface(1,MSH_SURF_DISCRETE,1);
  surf->Generatrices = List_Create(1,1,sizeof(Curve*));
  Tree_Add(m->Surfaces,&surf);
  
  for(i=0;i<NbVertices;i++)
    {
      fscanf(in,"%le %le %le",&x,&y,&z);
      Vertex *v = Create_Vertex(i,x,y,z,1.0,1.0);
      Tree_Add(m->Vertices,&v);
      Tree_Add(surf->Vertices,&v);
      v->ListSurf = List_Create(1,1,sizeof(Surface*));
      List_Add(v->ListSurf,&surf);
    }
  fscanf(in,"%s %d %d",dumline1,&NbFaces,&i);
  for(int i=0;i<NbFaces;i++)
    {
      fscanf(in,"%d",&NbVerticesOnFace); 
      if(NbVerticesOnFace == 3)
	{
	  fscanf(in,"%d %d %d", &Vertex1,&Vertex2,&Vertex3);
	  v1 = FindVertex(Vertex1,m);
	  v2 = FindVertex(Vertex2,m);
	  v3 = FindVertex(Vertex3,m);
	  v4 = NULL;
	}
      else
	{
	  printf("no quads man !\n");
	  exit(-1);
	}
      Simplex *s = Create_Simplex (v1,v2,v3,v4);
      s->V[0] = v1;
      s->V[1] = v2;
      s->V[2] = v3;
      s->Num = i;
      s->iEnt = 1;
      if((surf = FindSurface(1,m)))
	{
	}
      else
	{
	  surf = Create_Surface(1,MSH_SURF_DISCRETE,1);
	  surf->Generatrices = List_Create(1,1,sizeof(Curve*));
	  Tree_Add(m->Surfaces,&surf);
	}
      Tree_Add(surf->Simplexes,&s);
    }  
  FACE_DIMENSION = 2;
  Tree_Action (surf->Simplexes, TRIE_MON_GARS2);
  if(NbFaces)m->status = 2;

  Volume *vol = Create_Volume(1,MSH_VOLUME,1);
  vol->Surfaces = List_Create(1,1,sizeof(Surface*));
  List_Add(vol->Surfaces,&surf);
  Tree_Add(m->Volumes,&vol);

  fclose (in);
}

void Read_Mesh_SMS (Mesh *m, FILE *in)
{
  char line[1023];
  int i,patch,nbPts;
  int NbRegions,NbFaces,NbEdges,NbVertices,NbPoints,
    GEntityType,GEntityId,EntityNbConnections,Dummy,
    Edge1,Edge2,Edge3,Edge4,Face1,Face2,Face3,Face4;
  int VertexId1,VertexId2,NbEdgesOnFace,NbFacesOnRegion;
  double x,y,z,u,v;
  List_T *AllEdges,*AllFaces;
  Vertex *v1,*v2,*v3,*v4;


  fscanf(in,"%s %d",line,&Dummy);
  fscanf(in,"%d %d %d %d %d",&NbRegions,&NbFaces,&NbEdges,&NbVertices,&NbPoints);

  Msg(INFO,"reading a mesh in scorec format");
  Msg(INFO,"%d Vertices",NbVertices);
    
  for(i=0;i<NbVertices;i++)
    {
      fscanf(in,"%d",&GEntityId);       
      if(GEntityId)
	{
	  fscanf(in,"%d %d %lf %lf %lf",&GEntityType,&EntityNbConnections,&x,&y,&z); 
	  Vertex *vert = Create_Vertex(i,x,y,z,1.0,1.0);
	  Tree_Add(m->Vertices,&vert);
	  switch(GEntityType)
	    {
	    case 0:
	      Tree_Add(m->Points,&vert);
	      break;
	    case 1:
	      fscanf(in,"%le",&u);
	      break;
	    case 2:
	      fscanf(in,"%le %le %d",&u,&v,&patch);
	      break;
	    case 3:
	      break;
	    }  
	}
    }
  
  Msg(INFO,"%d Edges",NbEdges);
  AllEdges = List_Create(NbEdges,1,sizeof(Edge));
  Edge e;

  for(int i=0;i<NbEdges;i++)
    {
      fscanf(in,"%d",&GEntityId);

      if(GEntityId)
	{
	  fscanf(in,"%d %d %d %d %d",&GEntityType, &VertexId1,&VertexId2,&EntityNbConnections,&nbPts); 
	  for(int j=0;j<nbPts;j++)
	    {
	      switch(GEntityType)
		{
		case 0:
		  break;
		case 1:
		  fscanf(in,"%le",&u);
		  break;
		case 2:
		  fscanf(in,"%le %le %d",&u,&v,&patch);
		  break;
		case 3:
		  break;
		}
	    }
	  e.Points = NULL;
	  Vertex *v1 = FindVertex(VertexId1-1,m);
	  Vertex *v2 = FindVertex(VertexId2-1,m);
	  e.V[0] = v1;
	  e.V[1] = v2;
	  List_Add(AllEdges,&e);
	  switch(GEntityType)
	   {
	     case ENTITY_EDGE :
	      Simplex *s = Create_Simplex(v1,v2,NULL,NULL);
	      Curve *c;
	      if((c = FindCurve(GEntityId,m)))
	      	{
	      	}
	      else
	      	{
		  c = Create_Curve(GEntityId,MSH_SEGM_DISCRETE,1,NULL,NULL,-1,-1,0,1);
		  c->beg = v1;
		  c->end = v2;
		  Tree_Add(m->Curves,&c);
	      }
	      s->iEnt = GEntityId;
	      //	      List_Add(v1->ListCurves,&c);
	      // List_Add(v2->ListCurves,&c);
	      Tree_Add(c->Simplexes,&s);
	      s->Num = i;
	   }
	}  
    }
  
  AllFaces = List_Create(NbFaces,1,sizeof(Simplex*));

  Volume *vol = Create_Volume(1,MSH_VOLUME,1);
  vol->Surfaces = List_Create(1,1,sizeof(Surface*));
  Tree_Add(m->Volumes,&vol);
  FACE_DIMENSION = 2;

  Msg(INFO,"%d Faces",NbFaces);
  for(int i=0;i<NbFaces;i++)
    {
      fscanf(in,"%d",&GEntityId);
      if(GEntityId)
	{
	  fscanf(in,"%d %d",&GEntityType, &NbEdgesOnFace);
	  

	  List_T *Lists[4] = {0,0,0,0};

	  if(NbEdgesOnFace == 3)
	    {
	      fscanf(in,"%d %d %d %d",&Edge1,&Edge2,&Edge3,&nbPts);
	      List_Read(AllEdges,abs(Edge1)-1,&e);
	      Lists[0] = e.Points;
	      if(Edge1 > 0)v1 = e.V[0];
	      else v1 = e.V[1];
	      List_Read(AllEdges,abs(Edge2)-1,&e);
	      Lists[1] = e.Points;
	      if(Edge2 > 0)v2 = e.V[0];
	      else v2 = e.V[1];
	      List_Read(AllEdges,abs(Edge3)-1,&e);
	      Lists[2] = e.Points;
	      if(Edge3 > 0)v3 = e.V[0];
	      else v3 = e.V[1];
	      v4 = NULL;
	    }
	  else if(NbEdgesOnFace == 4)
	    {
	      fscanf(in,"%d %d %d %d %d",&Edge1,&Edge2,&Edge3,&Edge4,&nbPts);
	      List_Read(AllEdges,abs(Edge1)-1,&e);
	      if(Edge1 > 0)v1 = e.V[0];
	      else v1 = e.V[1];
	      List_Read(AllEdges,abs(Edge2)-1,&e);
	      if(Edge2 > 0)v2 = e.V[0];
	      else v2 = e.V[1];
	      List_Read(AllEdges,abs(Edge3)-1,&e);
	      if(Edge3 > 0)v3 = e.V[0];
	      else v3 = e.V[1];
	      List_Read(AllEdges,abs(Edge4)-1,&e);
	      if(Edge4 > 0)v4 = e.V[0];
	      else v4 = e.V[1];
	    }
	  else
	    {
	      cout << "exiting" << endl;
	      exit(-1);
	    }
	  for(int j=0;j<nbPts;j++)
	    {
	      switch(GEntityType)
		{
		case 0:
		  break;
		case 1:
		  fscanf(in,"%le",&u);
		  break;
		case 2:
		  fscanf(in,"%le %le %d",&u,&v,&patch);
		  break;
		case 3:
		  break;
		}
	    }

	  Simplex *s = Create_Simplex (v1,v2,v3,v4);
	  //	  s->curvedBounds(Edge1,Edge2,Edge3,Edge4,Lists,m->VertexEdges);
	  s->Num = i+1;
	  s->iEnt = GEntityId+10000;
	  Surface *surf;
	  List_Add(AllFaces,&s);
	  
	  switch(GEntityType)
	    {
	    case ENTITY_REGION :
	      break;
	    case ENTITY_FACE :
	      if((surf = FindSurface(GEntityId+10000,m)))
		{
		}
	      else
		{
		  surf = Create_Surface(GEntityId+10000,MSH_SURF_DISCRETE,1);
		  if(!NbRegions)List_Add(vol->Surfaces,&surf);
		  surf->Generatrices = List_Create(1,1,sizeof(Curve*));
		  Tree_Add(m->Surfaces,&surf);
		}
	      Tree_Add(surf->Vertices,&s->V[0]);
	      Tree_Add(surf->Vertices,&s->V[1]);
	      Tree_Add(surf->Vertices,&s->V[2]);
	      Tree_Add(surf->Simplexes,&s);
	    }	  
	}  
    }
  

  Msg(INFO,"%d Region",NbRegions);

  for(int i=0;i<NbRegions;i++)
    {
      fscanf(in,"%d",&GEntityId);
      if(GEntityId)
	{
	  fscanf(in,"%d",&NbFacesOnRegion);
	  Simplex *myS1,*myS2;
	  if(NbFacesOnRegion == 4)
	    {
	      fscanf(in,"%d %d %d %d %d",&Face1,&Face2,&Face3,&Face4,&Dummy);
	      List_Read(AllFaces,abs(Face1)-1,&myS1);
	      List_Read(AllFaces,abs(Face2)-1,&myS2);
	      v1 = myS1->V[0];
	      v2 = myS1->V[1];
	      v3 = myS1->V[2];
	      for(int hh =0;hh<3;hh++)if(compareVertex(&v1,&myS2->V[hh]) &&
					 compareVertex(&v2,&myS2->V[hh]) &&
					 compareVertex(&v3,&myS2->V[hh]))v4=myS2->V[hh];
	    }
	  if(!v1 || !v2 || !v3 || !v4)
	    {
	      printf("%d\n",NbFacesOnRegion);
	      printf("%p %p %p %p\n",v1,v2,v3,v4);
	      printf("%p %p %p \n",myS1->V[0],myS1->V[1],myS1->V[2]);
	      printf("%p %p %p \n",myS2->V[0],myS2->V[1],myS2->V[2]);
	      assert(1==0);
	    }
	  Simplex *s = Create_Simplex (v1,v2,v3,v4);

	  if((vol = FindVolume(GEntityId,m)))
	    {
	    }
	  else
	    {
	      vol = Create_Volume(GEntityId,MSH_VOLUME,GEntityId);
	      Tree_Add(m->Volumes,&vol);
	    }
	  s->iEnt = GEntityId;
	  Tree_Insert(vol->Simplexes,&s);
	  Tree_Insert(m->Simplexes,&s);
	}
    }  

  List_Delete(AllFaces);


  if(NbRegions)m->status = 3;
  else if(NbFaces)m->status = 2;
  else if(NbEdges)m->status = 1; 
  Msg(INFO,"Done.");
}
/*
void Write_SMS_FILE (Mesh *m, char *filename)
{
  FILE *f = fopen (filename,"w");
  // write first the global infos 
  int i,j;
//  Edge e;

  List_T *l;
  List_T *AllFaces = List_Create(100,100,sizeof(Simplex*));
  Surface *surf;
  Simplex *s;
  Vertex *v;
  Curve *c;


  l = Tree2List(m->Surfaces);
  EdgesContainer AllEdges(l);


  for(i=0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&surf);
      List_T *all = Tree2List(surf->Simplexes);
      for(j=0;j<List_Nbr(all);j++)List_Add(AllFaces,List_Pointer(all,j));
      List_Delete(all);
    }
  List_Delete(l);

  fprintf(f,"gmsh 2\n");
  fprintf(f,"0 %d %d %d %d\n"
	  ,List_Nbr(AllFaces) 
	  ,Tree_Nbr(AllEdges.AllEdges)
	  ,Tree_Nbr(m->Vertices)
	  ,Tree_Nbr(m->Vertices));



  l = Tree2List(m->Vertices);
  int MaxFrozen;
  for(i = 0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&v);
      MaxFrozen = (MaxFrozen>=v->Frozen)?MaxFrozen:v->Frozen;
    }

  for(i = 0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&v);
      int mtype = ((v->ListCurves)?((List_Nbr(v->ListCurves)== 1)?ENTITY_EDGE:ENTITY_VERTEX):ENTITY_FACE);
      int gent;
      switch(mtype)
	{
	case ENTITY_VERTEX : gent = i+1;break;
	case ENTITY_EDGE   : List_Read(v->ListCurves,0,&c);gent = c->ipar[3]+1;break;
	case ENTITY_FACE   : List_Read(v->ListSurf,0,&surf);gent = surf->ipar[3]+1;break;
	}
      v->Frozen = i+1;
      int nn = 7; // arbitrary 
      fprintf(f,"%d %d %d\n",gent,mtype,nn);      
      switch(mtype)
	{
	case ENTITY_VERTEX : fprintf(f,"%12.5E %12.5E %12.5E\n",v->Pos.X,v->Pos.Y,v->Pos.Z)      ;break;
	case ENTITY_EDGE   : fprintf(f,"%12.5E %12.5E %12.5E 0 \n",v->Pos.X,v->Pos.Y,v->Pos.Z)      ;break;
	case ENTITY_FACE   : fprintf(f,"%12.5E %12.5E %12.5E 0 0 1\n",v->Pos.X,v->Pos.Y,v->Pos.Z)      ;break;
	}
    }

  //  extern int DEGRE2;

  printf("%d edges\n",Tree_Nbr(AllEdges.AllEdges));
  l = Tree2List(m->Curves);
  for(i=0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&c);
      AllEdges.AddTree(c->Simplexes,false);
      //      if(c->Num > 0 && c->Typ != MSH_SEGM_LINE)AllEdges.AddPoints(c,DEGRE2-1);
    }
  List_Delete(l);
  printf("%d edges\n",Tree_Nbr(AllEdges.AllEdges));
  

  l = Tree2List(AllEdges.AllEdges);
  int compareEdgeNum (const void *a, const void *b);

  List_Sort(l,compareEdgeNum);
  
  for(i = 0;i<List_Nbr(l);i++)
    {
      int mtype = ENTITY_FACE;
      Edge *pe = (Edge*)List_Pointer(l,i);
      int nn = 0,gent;
      for(j=0;j<List_Nbr(pe->Simplexes);j++)
	{
	  List_Read(pe->Simplexes,j,&s);
	  if(!s->V[2]){
	    mtype = ENTITY_EDGE;
	    gent = s->iEnt;
	  }
	  if(mtype == ENTITY_FACE)
	    {
	      nn ++;
	      gent = s->iEnt;
	    }
	}  
      if(!pe->Points)
	fprintf(f,"%d %d %d %d %d 0\n",gent,mtype,pe->V[0]->Frozen,pe->V[1]->Frozen,nn);      
      else
	{
	  fprintf(f,"%d %d %d %d %d %d\n",gent,mtype,pe->V[0]->Frozen,pe->V[1]->Frozen,nn,
		  List_Nbr(pe->Points));      
	  for(int k=0;k<List_Nbr(pe->Points);k++)
	    {
	      Coord cr;
	      List_Read(pe->Points,k,&cr);
	      fprintf(f,"%12.5E %12.5E %12.5E %12.5E ",cr.X,cr.Y,cr.Z,0.0);
	    }
	  fprintf(f,"\n");
	}
    }

  Edge *ed[4];
  int ori[4];
  int *edids = new int[List_Nbr(l)+1];
  for(i=0;i<List_Nbr(l)+1;i++)edids[i] = 0;
  List_Delete(l);
  for(i = 0;i<List_Nbr(AllFaces);i++)
    {
      List_Read(AllFaces,i,&s);
      AllEdges.GetEdges(s,false,ed,ori);
      if(!ed[3])
	{
	  for(int k=0;k<3;k++)
	    {
	      if(edids[ed[k]->Num] == ori[k])
		{
		  Simplex *s1,*s2;
		  List_Read(ed[k]->Simplexes,0,&s1);
		  List_Read(ed[k]->Simplexes,1,&s2);
		  printf("Edge %d %d\n",ed[k]->V[0]->Num,ed[k]->V[1]->Num);
		  printf("s1 = %d %d %d\n",s1->V[0]->Num,s1->V[1]->Num,s1->V[2]->Num);
		  printf("s2 = %d %d %d\n",s2->V[0]->Num,s2->V[1]->Num,s2->V[2]->Num);
		} 
	      else
		{
		  edids[ed[k]->Num] = ori[k];
		}
	    }

	  fprintf(f,"%d %d 3 %d %d %d 0\n",s->iEnt,ENTITY_FACE,ori[0] * ed[0]->Num,
		  ori[1]*ed[1]->Num,ori[2]*ed[2]->Num);      
	}
      else fprintf(f,"%d %d 4 %d %d %d %d 0\n",s->iEnt,ENTITY_FACE,ori[0]*ed[0]->Num,
		   ori[1]*ed[1]->Num,ori[2]*ed[2]->Num,ori[3]*ed[3]->Num);      
    }
  delete edids;
  List_Delete(AllFaces);
  fclose (f);
  
}
*/
int isTopologic (Vertex *v, List_T *curves)
{
  Curve *c;
  for(int i=0;i<List_Nbr(curves);i++)
    {
      List_Read(curves,i,&c);
      if(!compareVertex(&v,&c->beg))return 1;
    }
  return 0;
}

void Write_DMG_FILE (Mesh *m, char *filename)
{
  FILE *f = fopen (filename,"w");
  int i,j;
  List_T *ll,*l;
  Vertex *v;
  Curve *c;
  Surface *s;
  //Volume *vol;
  int k;

  l = Tree2List(m->Points);
  ll = Tree2List(m->Curves);

  k = 0;
  for(i = 0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&v);
      if(isTopologic(v,ll))
	{
	  k++;
	}
    }

  // write first the global infos 

  fprintf(f,"%d %d %d %d \n"
	  ,Tree_Nbr(m->Volumes)
	  ,Tree_Nbr(m->Surfaces) 
	  ,Tree_Nbr(m->Curves)/2 // the 2 is for the reverse curves
	  ,k);

  // then write the bounding box

  m->Grid.min.X = CTX.min[0];
  m->Grid.min.Y = CTX.min[1];
  m->Grid.min.Z = CTX.min[2];
  m->Grid.max.X = CTX.max[0];
  m->Grid.max.Y = CTX.max[1];
  m->Grid.max.Z = CTX.max[2];

  fprintf(f,"%12.5E %12.5E %12.5E \n",m->Grid.min.X,m->Grid.min.Y,m->Grid.min.Z);
  fprintf(f,"%12.5E %12.5E %12.5E \n",m->Grid.max.X,m->Grid.max.Y,m->Grid.max.Z);

  // write the points
  k = 0;
  for(i = 0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&v);
      if(isTopologic(v,ll))
	 {
	   v->Frozen = k++;
	   fprintf(f,"%d %12.5E %12.5E %12.5E \n",v->Frozen,v->Pos.X,v->Pos.Y,v->Pos.Z);    
	 }
    }
  List_Delete(l);
  // write the curves
  l = ll;
  k = 0;
  for(i = 0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&c);
      if(c->Num > 0){
	c->ipar[3] = k;
	Curve *cinv = FindCurve(-c->Num,m);
	cinv->ipar[3] = k++;	
	fprintf(f,"%d %d %d \n",c->ipar[3],c->beg->Frozen,c->end->Frozen);    
      }
    }

  List_Delete(l);

  // write the surfaces
  l = Tree2List(m->Surfaces);
  
  for(i = 0;i<List_Nbr(l);i++)
    {
      List_Read(l,i,&s);
      
      int numEdgeLoop[2000],iLoop=0;
      Vertex *beg = NULL;
      numEdgeLoop[iLoop] = 0;
      int deb = 1;
      for(j=0;j<List_Nbr(s->Generatrices);j++)
	{
	  List_Read(s->Generatrices,j,&c);
	  if(deb)
	    {
	      beg = c->beg;
	      deb = 0;
	    }
	  cout << "beg-> " << c->beg->Num << " end-> " << c->end->Num << endl;
	  (numEdgeLoop[iLoop]) ++ ;
	  if(c->end == beg)
	    {
	      iLoop++;
	      numEdgeLoop[iLoop] = 0;
	      deb = 1;
	    }
	}
      s->ipar[3] = i;
      fprintf(f,"%d %d\n",i,iLoop);
      fprintf(stdout,"%d %d\n",i,iLoop);
      int iEdge = 0;
      for(k=0;k<iLoop;k++)
	{
	  fprintf(f,"%d ",numEdgeLoop[k]);    
	  fprintf(stdout,"%d ",numEdgeLoop[k]);    
	  for(j=0;j<numEdgeLoop[k];j++)
	    {
	      List_Read(s->Generatrices,iEdge++,&c);
	      fprintf(f,"%d %d ",abs(c->ipar[3]),(c->Num>0)?1:-1);    
	      fprintf(stdout,"%d %d ",abs(c->ipar[3]),(c->Num>0)?1:-1);    
	    }
	  fprintf(f,"\n");
	  fprintf(stdout,"\n");
	}    
    }
  List_Delete(l);

  // write the volumes (2 b continued)

  // close the file

  fclose(f);

}
