// $Id: DiscreteSurface.cpp,v 1.26 2005-09-21 15:03:46 remacle Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "CAD.h"
#include "Geo.h"
#include "Create.h"
#include "Interpolation.h"
#include "Context.h"
#include "BDS.h"
#include "PartitionMesh.h"

extern Mesh *THEM;
extern Context_T CTX;
extern void Move_SimplexBaseToSimplex(Mesh * M, int dimension);
void Mesh_To_BDS(Mesh *m)
{

  Msg(STATUS2, "Moving the mesh in the new gmsh structure\n");
  Move_SimplexBaseToSimplex(m, 3);
  // create the structure
  if (m->bds)delete m->bds;
  m->bds = new BDS_Mesh;
  PhysicalGroup *p;

  m->bds->Min[0] = m->bds->Min[1] = m->bds->Min[2] = 1.e12;
  m->bds->Max[0] = m->bds->Max[1] =m->bds-> Max[2] = -1.e12;

  Msg(STATUS2, "Moving the nodes\n");
  // copy the nodes
  List_T *vertices = Tree2List ( m->Vertices ) ;
  for (int i=0;i<List_Nbr ( vertices ) ;++i)
    {
      Vertex *v;
      List_Read ( vertices, i, &v);
      if ( v->Pos.X < m->bds->Min [0]) m->bds->Min[0] = v->Pos.X;
      if ( v->Pos.Y < m->bds->Min [1]) m->bds->Min[1] = v->Pos.Y;
      if ( v->Pos.Z < m->bds->Min [2]) m->bds->Min[2] = v->Pos.Z;
      if ( v->Pos.X > m->bds->Max [0]) m->bds->Max[0] = v->Pos.X;
      if ( v->Pos.Y > m->bds->Max [1]) m->bds->Max[1] = v->Pos.Y;
      if ( v->Pos.Z > m->bds->Max [2]) m->bds->Max[2] = v->Pos.Z;
      m->bds->add_point (v->Num,v->Pos.X,v->Pos.Y,v->Pos.Z); 
    }
  m->bds->LC = sqrt ((m->bds->Min[0]-m->bds->Max[0])*(m->bds->Min[0]-m->bds->Max[0])+
	     (m->bds->Min[1]-m->bds->Max[1])*(m->bds->Min[1]-m->bds->Max[1])+
	     (m->bds->Min[2]-m->bds->Max[2])*(m->bds->Min[2]-m->bds->Max[2]));
  List_Delete (vertices);

  for(int i = 0; i < List_Nbr(m->PhysicalGroups); i++) {
    List_Read(m->PhysicalGroups, i, &p);
    if(p->Typ == MSH_PHYSICAL_POINT) {
      m->bds->add_geom  (p->Num,0); 
      BDS_GeomEntity *g = m->bds->get_geom  (p->Num,0);
      for(int j = 0; j < List_Nbr(p->Entities); j++) {
	int Num;
        List_Read(p->Entities, j, &Num); 
	BDS_Point *ppp = m->bds->find_point (Num);
	ppp->g = g;
	g->p = ppp;
      }
    }
  }

  Msg(STATUS2, "Moving the curves\n");
  List_T *curves = Tree2List ( m->Curves ) ;
  for (int i=0;i<List_Nbr ( curves ) ;++i)
    {
      Curve *c;
      List_Read ( curves, i, &c);
      m->bds->add_geom  ( c->Num, 1);
      BDS_GeomEntity *g = m->bds->get_geom  (c->Num,1);
      List_T *simplices = Tree2List ( c->Simplexes ) ;
      Simplex *simp;
      for (int j=0;j<List_Nbr ( simplices) ;++j)
	{
	  List_Read(simplices,j,&simp);
	  BDS_Edge *edge = m->bds->add_edge (simp->V[0]->Num,simp->V[1]->Num); 
	  edge->g = g;
	  if (!edge->p1->g)edge->p1->g = g;
	  if (!edge->p2->g)edge->p2->g = g;
	}
      List_Delete(simplices);
    }
  List_Delete (curves);
  Msg(STATUS2, "Moving the surfaces\n");
  List_T *surfaces = Tree2List ( m->Surfaces ) ;
  for (int i=0;i<List_Nbr ( surfaces ) ;++i)
    {
      Surface *s;
      List_Read ( surfaces, i, &s);
      m->bds->add_geom  ( s->Num, 2);
      BDS_GeomEntity *g = m->bds->get_geom  (s->Num,2);

      printf("a new surface %d %d is created\n",g->classif_tag,g->classif_degree);

      List_T *simplices = Tree2List ( s->Simplexes ) ;
      Simplex *simp;
      for (int j=0;j<List_Nbr ( simplices) ;++j)
	{
	  List_Read(simplices,j,&simp);
	  BDS_Triangle *t = m->bds->add_triangle (simp->V[0]->Num,simp->V[1]->Num,simp->V[2]->Num); 
	  t->g = g;	
	  BDS_Point *n[3];
	  t->getNodes (n);
	  for (int K=0;K<3;K++)
	    if (!n[K]->g) n[K]->g = g;
	  if (!t->e1->g)t->e1->g = g;
	  if (!t->e2->g)t->e2->g = g;
	  if (!t->e3->g)t->e3->g = g;
	}
      List_Delete(simplices);
    }
  List_Delete (surfaces);
  
  Msg(STATUS2, "Moving the %d volumes\n",Tree_Nbr(m->Volumes));
  List_T *volumes = Tree2List ( m->Volumes ) ;
  for (int i=0;i<List_Nbr ( volumes ) ;++i)
    {
      Volume *v;
      List_Read ( volumes, i, &v);
      m->bds->add_geom  ( v->Num, 3);
      BDS_GeomEntity *g = m->bds->get_geom  (v->Num,3);
      List_T *simplices = Tree2List ( v->Simplexes ) ;
      Simplex *simp;
      printf("%d tets\n",List_Nbr ( simplices));
      for (int j=0;j<List_Nbr ( simplices) ;++j)
	{
	  List_Read(simplices,j,&simp);
	  BDS_Tet *t = m->bds->add_tet (simp->V[0]->Num,simp->V[1]->Num,simp->V[2]->Num,simp->V[3]->Num); 
	  t->g = g;
	  BDS_Point *n[4];
	  t->getNodes (n);
	  for (int K=0;K<4;K++)
	    if (!n[K]->g) n[K]->g = g;
	  if (!t->f1->g) t->f1->g  = g;
	  if (!t->f2->g) t->f2->g  = g;
	  if (!t->f3->g) t->f3->g  = g;
	  if (!t->f4->g) t->f4->g  = g;
	  if (!t->f1->e1->g) t->f1->e1->g  = g;
	  if (!t->f2->e1->g) t->f2->e1->g  = g;
	  if (!t->f3->e1->g) t->f3->e1->g  = g;
	  if (!t->f4->e1->g) t->f4->e1->g  = g;
	  if (!t->f1->e2->g) t->f1->e2->g  = g;
	  if (!t->f2->e2->g) t->f2->e2->g  = g;
	  if (!t->f3->e2->g) t->f3->e2->g  = g;
	  if (!t->f4->e2->g) t->f4->e2->g  = g;
	  if (!t->f1->e3->g) t->f1->e3->g  = g;
	  if (!t->f2->e3->g) t->f2->e3->g  = g;
	  if (!t->f3->e3->g) t->f3->e3->g  = g;
	  if (!t->f4->e3->g) t->f4->e3->g  = g;

	}
      List_Delete(simplices);
    }
  List_Delete (volumes);
  
}
extern int addMeshPartition(int Num, Mesh * M);

void BDS_To_Mesh_2(Mesh *m)
{
  Msg(STATUS2, "Moving the surface mesh in the old gmsh structure\n");
  
  Tree_Action(m->Vertices, Free_Vertex);  
  Tree_Delete(m->Vertices);
  m->Vertices = Tree_Create(sizeof(Vertex *), compareVertex);
  
  {
    std::set<BDS_Point*, PointLessThan>::iterator it   = m->bds_mesh->points.begin();
    std::set<BDS_Point*, PointLessThan>::iterator ite  = m->bds_mesh->points.end();
    while (it != ite)
      {
	Vertex *vert = Create_Vertex((*it)->iD, (*it)->X,(*it)->Y,(*it)->Z, 1.0, 0.0);
	Tree_Add (m->Vertices,&vert);
	++it;
      }
  }
  
  
  {
    std::list<BDS_Edge*>::iterator it  = m->bds_mesh->edges.begin();
    std::list<BDS_Edge*>::iterator ite = m->bds_mesh->edges.end();
    while(it!=ite)
      {
	BDS_GeomEntity *g = (*it)->g;
	if (g && g->classif_degree == 1)
	  {
	    Vertex *v1 = FindVertex((*it)->p1->iD, m);
	    Vertex *v2 = FindVertex((*it)->p2->iD, m);
	    SimplexBase *simp = Create_SimplexBase(v1,v2,NULL, NULL);
	    Curve *c = FindCurve (g->classif_tag,m);
	    if (c)
	      simp->iEnt = g->classif_tag;
	    Tree_Insert(c->Simplexes, &simp);
	  }
	++it;
      }
  }
  {
    std::list<BDS_Triangle*>::iterator it  = m->bds_mesh->triangles.begin();
    std::list<BDS_Triangle*>::iterator ite = m->bds_mesh->triangles.end();
    while (it!=ite){
      BDS_GeomEntity *g = (*it)->g;
      if (g && g->classif_degree == 2)
	  {
	    BDS_Point *nod[3];
	    (*it)->getNodes (nod);
	    Vertex *v1 = FindVertex(nod[0]->iD, m);
	    Vertex *v2 = FindVertex(nod[1]->iD, m);
	    Vertex *v3 = FindVertex(nod[2]->iD, m);
	    SimplexBase *simp = Create_SimplexBase(v1,v2,v3, NULL);
	    BDS_GeomEntity *g = (*it)->g;
	    Surface *s = FindSurface (g->classif_tag,m);
	    if(s)
	      {
		simp->iEnt = g->classif_tag;
		simp->iPart = addMeshPartition((*it)->partition, m);
	      }
	    else
	      printf("impossible to find surface %d\n",g->classif_tag);
	    Tree_Add(s->Simplexes, &simp);
	  }
      ++it;
    }
  }
  {
    std::list<BDS_Tet*>::iterator it  = m->bds_mesh->tets.begin();
    std::list<BDS_Tet*>::iterator ite = m->bds_mesh->tets.end();
    while (it!=ite){
      BDS_Point *nod[4];
      (*it)->getNodes (nod);
      Vertex *v1 = FindVertex(nod[0]->iD, m);
      Vertex *v2 = FindVertex(nod[1]->iD, m);
      Vertex *v3 = FindVertex(nod[2]->iD, m);
      Vertex *v4 = FindVertex(nod[3]->iD, m);
      SimplexBase *simp = Create_SimplexBase(v1,v2,v3, v4);
      BDS_GeomEntity *g = (*it)->g;
      Volume *v = FindVolume (g->classif_tag,m);
      if(v)
	{
	  simp->iEnt = g->classif_tag;
	  simp->iPart = addMeshPartition((*it)->partition, m);
	}
      else
	printf("argh\n");
      Tree_Add(v->Simplexes, &simp);
      ++it;
    }
  }
    Msg(STATUS2, "Ready");
}

void BDS_To_Mesh(Mesh *m)
{
    Tree_Action(m->Points, Free_Vertex);  
    Tree_Delete(m->Points);
    Tree_Action(m->Volumes, Free_Volume);
    Tree_Action(m->Surfaces, Free_Surface);
    Tree_Action(m->Curves, Free_Curve);
    Tree_Delete(m->Surfaces);
    Tree_Delete(m->Curves);
    Tree_Delete(m->Volumes);
    m->Points = Tree_Create(sizeof(Vertex *), compareVertex);
    m->Curves = Tree_Create(sizeof(Curve *), compareCurve);
    m->Surfaces = Tree_Create(sizeof(Surface *), compareSurface);
    m->Volumes = Tree_Create(sizeof(Volume *), compareVolume);

    std::set<BDS_GeomEntity*,GeomLessThan>::iterator it  = m->bds->geom.begin(); 
    std::set<BDS_GeomEntity*,GeomLessThan>::iterator ite = m->bds->geom.end(); 
    
    while (it != ite)
    {
	if ((*it)->classif_degree ==3 )
	{
	    Volume *_Vol = 0; 
	    _Vol = FindVolume((*it)->classif_tag, m);
	    if (!_Vol) 
		_Vol = Create_Volume((*it)->classif_tag,MSH_VOLUME_DISCRETE);	
	    Tree_Add(m->Volumes, &_Vol);	    	   
	}
	else if ((*it)->classif_degree ==2 )
	{
	    Surface *_Surf = 0; 
	    _Surf = FindSurface((*it)->classif_tag, m);
	    if (!_Surf) 
		_Surf = Create_Surface((*it)->classif_tag, MSH_SURF_DISCRETE);	
	    //	    _Surf->bds = m->bds;
	    End_Surface(_Surf);
	    Tree_Add(m->Surfaces, &_Surf);	    	   
	}
	else if ((*it)->classif_degree ==1  )
	{ 
	    Curve *_c = 0; 
	    _c = FindCurve((*it)->classif_tag, m);
	    if (!_c) 
		_c = Create_Curve((*it)->classif_tag, MSH_SEGM_DISCRETE, 1, NULL, NULL, -1, -1, 0., 1.);	
	    //	    _c->bds = m->bds;
	    End_Curve(_c);
	    Tree_Add(m->Curves, &_c);
	}
	else if ((*it)->classif_degree == 0 )
	{
	  BDS_Point *p = (*it)->p;
	  if (p)
	    {
	      Vertex *_v = Create_Vertex(p->iD, p->X,p->Y,p->Z,1,0);	
	      Tree_Add(m->Points, &_v);
	    }
	}
	++it;
    }

    CTX.mesh.changed = 1;

}


int ReMesh(Mesh *M)
{

  if(M->status != 2) return 0;

  DeleteMesh (M);
  
  delete M->bds_mesh;
  M->bds_mesh = 0;
  
  MeshDiscreteSurface ((Surface*)0);

  CTX.mesh.changed = 1;
  return 1;
}

// Public interface for discrete surface/curve mesh algo

int MeshDiscreteSurface(Surface *s)
{ 

  const int NITER = 10;
  if(THEM->bds){
    Msg(STATUS2, "Discrete Surface Mesh Generator...");
    if(!THEM->bds_mesh){
      THEM->bds_mesh = new BDS_Mesh (*(THEM->bds));
      int iter = 0;
      while(iter < NITER && THEM->bds_mesh->adapt_mesh(CTX.mesh.lc_factor * THEM->bds->LC, 
						    true, THEM->bds)){
	Msg(STATUS2, "Iteration %2d/%d done (%d triangles)\n",iter, NITER,THEM->bds_mesh->triangles.size());
	iter ++;
      }
      BDS_To_Mesh_2(THEM);
      Msg(STATUS2, "Mesh has %d vertices (%d)\n",Tree_Nbr(THEM->Vertices),THEM->bds->points.size());
      //	    THEM->bds_mesh->save_gmsh_format ( "3.msh" ); 
      return 1;
    }
    return 2;
  }
  else
    return 0;
}

int MeshDiscreteCurve(Curve *c)
{
  if(c->Typ == MSH_SEGM_DISCRETE){
    // nothing else to do: we assume that the curve is represented by
    // a mesh that will not be modified
    return 1;
  }
  else
    return 0;
}
