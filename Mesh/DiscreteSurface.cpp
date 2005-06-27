// $Id: DiscreteSurface.cpp,v 1.16 2005-06-27 15:03:46 remacle Exp $
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

void BDS_To_Mesh(Mesh *m)
{
    Tree_Action(m->Surfaces, Free_Surface);
    Tree_Action(m->Curves, Free_Curve);
    Tree_Delete(m->Surfaces);
    Tree_Delete(m->Curves);
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
	++it;
    }

    CTX.mesh.changed = 1;

    printf ("%d surfaces %d curves\n",Tree_Nbr(m->Surfaces), Tree_Nbr(m->Curves) );

}

// Public interface for discrete surface/curve mesh algo

int MeshDiscreteSurface(Surface *s)
{
  if(s->bds){
    // s->bds is the discrete surface that defines the geometry
    if(!THEM->bds_mesh){
      THEM->bds_mesh = new BDS_Mesh (*(THEM->bds));
      int iter = 0;
      while(iter < 20 && THEM->bds_mesh->adapt_mesh(CTX.mesh.lc_factor * THEM->bds->LC, 
						    true, THEM->bds)){
	printf("iter %d done\n",iter);
	iter ++;
      }
      THEM->bds_mesh->save_gmsh_format ( "3.msh" );
    }
    return 1;
  }
  else if(s->Typ == MSH_SURF_DISCRETE){
    // nothing to do: we suppose that the surface is represented by
    // a mesh that will not be modified
    return 1;
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
