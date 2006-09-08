// $Id: meshGFaceTransfinite.cpp,v 1.4 2006-09-08 02:39:43 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "meshGFace.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "Context.h"
#include "Message.h"

#define TRAN_QUA(c1,c2,c3,c4,s1,s2,s3,s4,u,v) \
   (1.-u)*c4+u*c2+(1.-v)*c1+v*c3-((1.-u)*(1.-v)*s1+u*(1.-v)*s2+u*v*s3+(1.-u)*v*s4)

int MeshTransfiniteSurface( GFace *gf)
{
  if(gf->meshAttributes.Method != TRANSFINI)
    return 0;
  std::vector <MVertex *> corners;
  std::vector <MVertex *> d_vertices;
  std::vector <int> indices;

  for (unsigned int i=0;i<gf->meshAttributes.corners.size();i++)
    corners.push_back(gf->meshAttributes.corners[i]->mesh_vertices[0]);

  computeEdgeLoops (gf,d_vertices, indices);

  if (corners.size () != 3 && corners.size () != 4)
    Msg (GERROR,"Surface %d is transfinite but has %d corners",gf->tag(),corners.size());
  if (indices.size () != 2)
    Msg (GERROR,"Surface %d is transfinite but has %d holes",gf->tag(),indices.size()-2);

  std::vector <MVertex *> m_vertices;
  unsigned int I;
  for (I=0;I<d_vertices.size();I++)
    if(d_vertices[I] == corners[0])break;
  for (unsigned int j=0;j<d_vertices.size();j++)
    m_vertices.push_back(d_vertices[(I+j)%d_vertices.size()]);
  
  int iCorner = 0;
  int N[4];
  std::vector<double> U;
  std::vector<double> V;

  std::map<std::pair<int,int> , MVertex*> tab;

  for (unsigned int i=0;i<m_vertices.size();i++)
    {
      MVertex *v = m_vertices[i];
      if (v==corners[0]||v==corners[1]||v==corners[2]|| (corners.size()==4 && v==corners[3]))
	{
	  N[iCorner++] = i;	  
	  if (iCorner > 4)
	    Msg (GERROR,"Surface %d transfinite parameters are incoherent",gf->tag());	  
	}
      SPoint2 param =  gf->parFromPoint (SPoint3(v->x(),v->y(),v->z()));      
      U.push_back(param.x());
      V.push_back(param.y());
    }

  int N1 = N[0];
  int N2 = N[1];
  int N3 = N[2];
  int N4 = N[3];
  
  int L = N2-N1;
  int H = N3-N2;

  int Lb = N4-N3;
  int Hb = m_vertices.size()-N4;

  if (Lb != L || Hb != H)
    {
      Msg(GERROR,"Surface %d cannot be meshed using the transfinite algo",gf->tag());
      return 0;
    }

  std::vector<double> lengths_i;
  std::vector<double> lengths_j;

  double L_i=0;
  double L_j=0;

  lengths_i.push_back( 0. );
  lengths_j.push_back( 0. );
  for (int i=0;i<L;i++)
    {
      MVertex *v1 = m_vertices[i];
      MVertex *v2 = m_vertices[i+1];
      double l = sqrt ((v1->x()-v2->x())*(v1->x()-v2->x())+
		       (v1->y()-v2->y())*(v1->y()-v2->y())+
		       (v1->z()-v2->z())*(v1->z()-v2->z()));
      L_i+= l;
      lengths_i.push_back( L_i );
    }
  for (int i=L;i<L+H;i++)
    {
      MVertex *v1 = m_vertices[i];
      MVertex *v2 = m_vertices[i+1];
      double l = sqrt ((v1->x()-v2->x())*(v1->x()-v2->x())+
		       (v1->y()-v2->y())*(v1->y()-v2->y())+
		       (v1->z()-v2->z())*(v1->z()-v2->z()));
      L_j+= l;
      lengths_j.push_back( L_j );
    }


  //Msg (INFO,"L %d H %d -- %d -- %d %d %d %d",L,H,m_vertices.size(),N1,N2,N3,N4);

  /*
       2L+H
         +------------+ L+H
         |            |
         |            |
         |            |
2L+2H+2  |            |
         +------------+
         0             L
 
  */

  tab[std::make_pair(0,0)] = m_vertices[0];
  tab[std::make_pair(L,0)] = m_vertices[L];
  tab[std::make_pair(L,H)] = m_vertices[L+H];
  tab[std::make_pair(0,H)] = m_vertices[2*L+H];

  for (int i=1;i<L;i++)
    {
      tab[std::make_pair(i,0)] = m_vertices[i];
      tab[std::make_pair(i,H)] = m_vertices[2*L+H-i];
    }
  for (int i=1;i<H;i++)
    {
      tab[std::make_pair(L,i)] = m_vertices[L+i];
      tab[std::make_pair(0,i)] = m_vertices[2*L+2*H-i];
    }

  double UC1 = U[N1];
  double UC2 = U[N2];
  double UC3 = U[N3];
  double UC4 = U[N4];
  double VC1 = V[N1];
  double VC2 = V[N2];
  double VC3 = V[N3];
  double VC4 = V[N4];


  //create points using transfinite interpolation
  for(int i = 1; i<L; i++) 
    {
      double u = lengths_i[i]/L_i;
      for(int j = 1; j < H; j++) 
	{
	  double v = lengths_j[j]/L_j;
	  int iP1 = N1+i;
	  int iP2 = N2+j;
	  int iP3 = N4-i;
	  int iP4 = (N4+(N3-N2)-j)%m_vertices.size();
	  
	  double Up = TRAN_QUA ( U[iP1], U[iP2], U[iP3], U[iP4] , UC1, UC2, UC3, UC4, u, v ); 
	  double Vp = TRAN_QUA ( V[iP1], V[iP2], V[iP3], V[iP4] , VC1, VC2, VC3, VC4, u, v ); 
	  
	  GPoint gp = gf->point (SPoint2(Up,Vp));
	  MFaceVertex *newv  = new MFaceVertex ( gp.x(),gp.y(),gp.z(), gf, Up, Vp );
	  gf->mesh_vertices.push_back (newv);	  	  
	  tab[std::make_pair(i,j)] = newv;
	}
    }

  if (gf->geomType() == GEntity::Plane) // some work 2 be done to smooth the stuff in parametric coords
                                        // parametric coords are available (MFaceVertex) !
    {
      // elliptic smoother
      for (int IT = 0;IT< 10;IT++)
	{
	  for(int i = 1; i<L; i++) 
	    {
	      for(int j = 1; j < H; j++) 
		{
		  MVertex *v11 = tab[std::make_pair(i-1,j-1)];
		  MVertex *v12 = tab[std::make_pair(i-1,j)];
		  MVertex *v13 = tab[std::make_pair(i-1,j+1)];	      
		  MVertex *v21 = tab[std::make_pair(i,j-1)];
		  MVertex *v22 = tab[std::make_pair(i,j)];
		  MVertex *v23 = tab[std::make_pair(i,j+1)];
		  MVertex *v31 = tab[std::make_pair(i+1,j-1)];
		  MVertex *v32 = tab[std::make_pair(i+1,j)];
		  MVertex *v33 = tab[std::make_pair(i+1,j+1)];
		  
		  double alpha = 0.25 * (DSQR(v23->x() - v21->x()) +
					 DSQR(v23->y() - v21->y()) +
					 DSQR(v23->z() - v21->z()) 
					 );
		  double gamma = 0.25 * (DSQR(v32->x() - v12->x()) +
					 DSQR(v32->y() - v12->y()) +
					 DSQR(v32->z() - v12->z())
					 );
		  double beta = 0.0625 * ((v32->x() - v12->x()) *
					  (v23->x() - v21->x()) +
					  (v32->y() - v12->y()) *
					  (v23->y() - v21->y()) +
					  (v32->z() - v12->z()) *
					  (v23->z() - v21->z())
					  );
		  
		  v22->x() = 0.5 * (alpha * (v32->x() + v12->x()) +
				    gamma * (v23->x() + v21->x()) -
				    2. * beta * (v33->x() - v13->x() -
						 v31->x() + v11->x()))
		    / (alpha + gamma);
		  v22->y() = 0.5 * (alpha * (v32->y() + v12->y()) +
				    gamma * (v23->y() + v21->y()) -
				    2. * beta * (v33->y() - v13->y() -
						 v31->y() + v11->y()))
		    / (alpha + gamma);
		  v22->z() = 0.5 * (alpha * (v32->z() + v12->z()) +
				    gamma * (v23->z() + v21->z()) -
				    2. * beta * (v33->z() - v13->z() -
						 v31->z() + v11->z()))
		    / (alpha + gamma);
		}
	    }
	}
    }
  // create elements
  for(int i = 0; i < L ; i++) 
    {
      for(int j = 0; j < H; j++) 
	{
	  MVertex *v1 = tab[std::make_pair(i,j)];
	  MVertex *v2 = tab[std::make_pair(i+1,j)];
	  MVertex *v3 = tab[std::make_pair(i+1,j+1)];
	  MVertex *v4 = tab[std::make_pair(i,j+1)];
	  if (gf->meshAttributes.recombine)
	    gf->quadrangles.push_back(new MQuadrangle (v1,v2,v3,v4));
	  else if (  gf->meshAttributes.transfiniteArrangement == 1 ||
		     (gf->meshAttributes.transfiniteArrangement == 0 && 
		      (( i % 2 == 0 && j % 2 == 1 ) ||
		       ( i % 2 == 1 && j % 2 == 0 ) ) ) )
	    {
	      gf->triangles.push_back(new MTriangle (v1,v2,v3));
	      gf->triangles.push_back(new MTriangle (v3,v4,v1));
	    }	  
	  else 
	    {
	      gf->triangles.push_back(new MTriangle (v1,v2,v4));
	      gf->triangles.push_back(new MTriangle (v4,v2,v3));
	    }	  
	}
    }
  return 1;
}
  
