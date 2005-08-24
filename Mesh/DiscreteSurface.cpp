// $Id: DiscreteSurface.cpp,v 1.22 2005-08-24 14:32:56 remacle Exp $
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

extern Mesh *THEM;
extern Context_T CTX;

void Mesh_To_BDS(Surface *s, BDS_Mesh *m)
{
  List_T *vertices = Tree2List ( s->Vertices ) ;
  for (int i=0;i<List_Nbr ( vertices ) ;++i)
    {
      Vertex *v;
      List_Read ( vertices, i, &v);
      m->add_point (v->Num,v->Pos.X,v->Pos.Y,v->Pos.Z); 
    }
  List_Delete (vertices);
  List_T *triangles = Tree2List ( s->Simplexes) ;
  for (int i=0;i<List_Nbr ( triangles ) ;++i)
    {
      Simplex *simp;
      List_Read ( triangles, i, &simp);
      Vertex *v1 = simp->V[0];
      Vertex *v2 = simp->V[1];
      Vertex *v3 = simp->V[2];
      double n[3];
      normal3points ( v1->Pos.X , v1->Pos.Y , v1->Pos.Z,
		      v2->Pos.X , v2->Pos.Y , v2->Pos.Z,
		      v3->Pos.X , v3->Pos.Y , v3->Pos.Z,
		      n);
      m->add_triangle (v1->Num,v2->Num,v3->Num); 
    }
  List_Delete (triangles);

}

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
		Tree_Insert(c->SimplexesBase, &simp);
	    }
	    ++it;
	}
    }
    {
	std::list<BDS_Triangle*>::iterator it  = m->bds_mesh->triangles.begin();
	std::list<BDS_Triangle*>::iterator ite = m->bds_mesh->triangles.end();
	while (it!=ite){
	    BDS_Point *nod[3];
	    (*it)->getNodes (nod);
	    Vertex *v1 = FindVertex(nod[0]->iD, m);
	    Vertex *v2 = FindVertex(nod[1]->iD, m);
	    Vertex *v3 = FindVertex(nod[2]->iD, m);
	    SimplexBase *simp = Create_SimplexBase(v1,v2,v3, NULL);
	    BDS_GeomEntity *g = (*it)->g;
	    Surface *s = FindSurface (g->classif_tag,m);
	    if(s)
		simp->iEnt = g->classif_tag;
	    else
		printf("argh\n");
	    Tree_Add(s->SimplexesBase, &simp);
	    ++it;
	}
    }
    Msg(STATUS2, "Ready");
}
void BDS_To_Mesh(Mesh *m)
{
    Tree_Action(m->Points, Free_Vertex);  
    Tree_Delete(m->Points);
    Tree_Action(m->Surfaces, Free_Surface);
    Tree_Action(m->Curves, Free_Curve);
    Tree_Delete(m->Surfaces);
    Tree_Delete(m->Curves);
    m->Points = Tree_Create(sizeof(Vertex *), compareVertex);
    m->Curves = Tree_Create(sizeof(Curve *), compareCurve);
    m->Surfaces = Tree_Create(sizeof(Surface *), compareSurface);

    std::set<BDS_GeomEntity*,GeomLessThan>::iterator it  = m->bds->geom.begin(); 
    std::set<BDS_GeomEntity*,GeomLessThan>::iterator ite = m->bds->geom.end(); 
    
    while (it != ite)
    {
	if ((*it)->classif_degree ==2 )
	{
	    Surface *_Surf = 0; 
	    _Surf = FindSurface((*it)->classif_tag, m);
	    if (!_Surf) 
		_Surf = Create_Surface((*it)->classif_tag, MSH_SURF_DISCRETE);	
	    _Surf->bds = m->bds;
	    End_Surface(_Surf);
	    Tree_Add(m->Surfaces, &_Surf);
	    
	   

	}
	else if ((*it)->classif_degree ==1  )
	{
	    Curve *_c = 0; 
	    _c = FindCurve((*it)->classif_tag, m);
	    if (!_c) 
		_c = Create_Curve((*it)->classif_tag, MSH_SEGM_DISCRETE, 1, NULL, NULL, -1, -1, 0., 1.);	
	    _c->bds = m->bds;
	    End_Curve(_c);
	    Tree_Add(m->Curves, &_c);
	}
	else if ((*it)->classif_degree == 0 )
	{
	    BDS_Point *p = (*it)->p;
	    Vertex *_v = Create_Vertex(p->iD, p->X,p->Y,p->Z,1,0);	
	    Tree_Add(m->Points, &_v);
	}
	++it;
    }

    CTX.mesh.changed = 1;

}

// Public interface for discrete surface/curve mesh algo

int MeshDiscreteSurface(Surface *s)
{ 

  const int NITER = 10;
  if(s->bds){
    Msg(STATUS2, "Discrete Surface Mesh Generator...");
    // s->bds is the discrete surface that defines the geometry
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
  else if(s->Typ == MSH_SURF_DISCRETE){
    // nothing to do: we suppose that the surface is represented by
    // a mesh that will not be modified
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
