// $Id: 2D_InitMesh.cpp,v 1.14 2002-05-20 02:15:36 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

/*
 
   Generation du maillage initial 2D

   Dans l'algorithme de maillage, on doit creer un maillage initial a l'aide
   de contours orientes aire a doite. Deux types de problemes peuvent se presenter :

       1) probleme courant : un triangle se trouve a l'exterieur du contour, il faut
       que sa variable de localisation soit declaree externe.  

       2) probleme rare : une arete du contour n'a pas ete creee

       On procede comme suit :
       trouve le triangle, on procede de la facon suivante :
          - on trie les aretes de tous les triangles ;
          - Pour chaque contour on prend chaque arete orientee ;
          - Si cette arete n'existe pas (bsearch return false) alors on cherche
          les 2 triangles reliant cette arete et on les modifie
          - Si cette arete possede 2 triangles adjacents, on declare externe 
          le triangle dont le troisieme noeud se trouve a gauche de l'arete.

          illustration
          ------------

          probleme 1) + = point du contour
          

                                        3
                        - -  + --------+     +
                   + - -     1 \      /                +
                                \    /                       +
                                 \  /                                   +
             +                     +
                                   2       3 a gauche de 1-2 -> tr externe


           probleme 2) arete inexistante 1-2
           
                       +,*,@ contours
           
                     +1                      +            
                    / \                     /|\
                   /   \                   / | \
                  /     \                 /  |  \
                 /       \               /   |   \
                *         @   --->      *----+----@ 
                 \       /               \   |   /
                  \     /                 \  |  /
                   \   /                   \ | /
                    \ /                     \|/
                     +2                      +

*/

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"
#include "2D_Mesh.h"

extern PointRecord   *gPointArray;

static Tree_T  *ETree=NULL,*EDToSwap=NULL;
static int      pointA,pointB,Counter,Stagnant,StopNow;
static int     *permut;

typedef struct {
  int from;
  int to;
  int NbOccur;
  Delaunay *Liste[2];
}ED;


void makepermut (int numpoints){  
  int i, ip ;  
  permut = (int *) Malloc (numpoints * sizeof (int)); //Memory leak! this is never freed...
  for ( i=0 ; i<numpoints ; i++ ){    
    ip = gPointArray[i].permu;
    permut[ip] = i;    
  }
}  

int crossED ( ED * e ){  
  double Xma,Xmb,Yma,Ymb,det,t,q;
  double XMa,XMb,YMa,YMb;
  double xa1,xa2,ya1,ya2;
  double xb1,xb2,yb1,yb2;
  
  xa1 = gPointArray[pointA].where.h;
  xa2 = gPointArray[pointB].where.h;
  ya1 = gPointArray[pointA].where.v;
  ya2 = gPointArray[pointB].where.v;
  
  xb1 = gPointArray[e->from].where.h;
  xb2 = gPointArray[e->to].where.h;
  yb1 = gPointArray[e->from].where.v;
  yb2 = gPointArray[e->to].where.v;

  Xma = DMIN(xa1,xa2);
  Xmb = DMIN(xb1,xb2);

  XMa = DMAX(xa1,xa2);
  XMb = DMAX(xb1,xb2);

  if(XMa < Xmb || XMb < Xma)return(0);

  Yma = DMIN(ya1,ya2);
  Ymb = DMIN(yb1,yb2);

  YMa = DMAX(ya1,ya2);
  YMb = DMAX(yb1,yb2);

  if(YMa < Ymb || YMb < Yma)return(0);

  det = (xa2 - xa1)*(yb1-yb2) - (xb1 - xb2)*(ya2-ya1); 

  if(det == 0.0){
    return(0);
  }

  t = ((xb1 - xa1)*(yb1-yb2) - (xb1 - xb2)*(yb1-ya1))/det; 
  q = ((xa2 - xa1)*(yb1-ya1) - (ya2 - ya1)*(xb1-xa1))/det; 

  if(t>1. || t<0.)return(0);
  if(q>1. || q<0.)return(0);

  //printf("t=%g  q=%g  det=%g\n", t, q, det);

  return(1);
}
 
int compareED2 (const void *a, const void *b){
  ED *q,*w;
  q=(ED*)a;
  w=(ED*)b;
  if(q->NbOccur > w->NbOccur)return(-1);
  if(q->NbOccur < w->NbOccur)return(1);
  if(q->from > w->from)return(1);
  if(q->from < w->from)return(-1);
  if(q->to > w->to)return(1);
  if(q->to < w->to)return(-1);
  return(0);
}

int compareED (const void *a, const void *b){
  ED *q,*w;
  q=(ED*)a;
  w=(ED*)b;
  if(q->from > w->from)return(1);
  if(q->from < w->from)return(-1);
  if(q->to > w->to)return(1);
  if(q->to < w->to)return(-1);
  return(0);
}

void DoWeSwapED ( void *data , void *dummy){
  ED *e;

  e = (ED*)data;
  
  if(e->from == pointA || e->from == pointB || 
     e->to   == pointA || e->to   == pointB){
    return;
  }
  else if ( Tree_PQuery ( EDToSwap,e) ){
  }    
  else if ( crossED ( e ) ) {    
    Tree_Add ( EDToSwap ,e);
  }
}

void Print ( void *data , void *dummy){
  ED *e;

  e = (ED*)data;
  Msg(INFO,"%d %d",e->from,e->to); 
}

void SwapED ( void *data , void *dummy){
  ED *e,E;
  int from,to;

  e = (ED*)data;

  if(Stagnant && Counter <= StopNow)return;
  else if(Stagnant)Counter++;

  if(!e->Liste[0] || !e->Liste[1]){
    Msg(GERROR, "Initial mesh is wrong. Try the new isotropic algorithm.");
    return;
  }

  if(e->from != e->Liste[0]->t.a && e->from != e->Liste[0]->t.b &&
     e->from != e->Liste[0]->t.c )
    return;
  if(e->from != e->Liste[1]->t.a && e->from != e->Liste[1]->t.b &&
     e->from != e->Liste[1]->t.c )
    return;
  if(e->to != e->Liste[0]->t.a && e->to != e->Liste[0]->t.b &&
     e->to != e->Liste[0]->t.c )
    return;
  if(e->to != e->Liste[1]->t.a && e->to != e->Liste[1]->t.b &&
     e->to != e->Liste[1]->t.c )
    return;
  

  if(e->from != e->Liste[0]->t.a && e->to != e->Liste[0]->t.a) 
    from = e->Liste[0]->t.a;
  else if(e->from != e->Liste[0]->t.b && e->to != e->Liste[0]->t.b) 
    from = e->Liste[0]->t.b;
  else if(e->from != e->Liste[0]->t.c && e->to != e->Liste[0]->t.c) 
    from = e->Liste[0]->t.c;

  if(e->from != e->Liste[1]->t.a && e->to != e->Liste[1]->t.a) 
    to = e->Liste[1]->t.a;
  else if(e->from != e->Liste[1]->t.b && e->to != e->Liste[1]->t.b) 
    to = e->Liste[1]->t.b;
  else if(e->from != e->Liste[1]->t.c && e->to != e->Liste[1]->t.c) 
    to = e->Liste[1]->t.c;

  pointA = e->from;
  pointB = e->to;
  E.from = from;
  E.to   = to;
  if(!crossED(&E))return;

  e->Liste[0]->t.a = from;
  e->Liste[0]->t.b = to;
  e->Liste[0]->t.c = e->from;
  
  e->Liste[1]->t.a = from;
  e->Liste[1]->t.b = to;
  e->Liste[1]->t.c = e->to;

  e->from = IMAX(from,to);
  e->to =   IMIN(from,to);
}
  
void SuppressInETree( void *data , void *dummy){
  if(!Tree_Suppress(ETree,data))
    Msg(WARNING, "Cannot suppress in ETree"); 
}

void AddInETree( void *data , void *dummy){
  Tree_Add(ETree,data);
}

int verifie_cas_scabreux (int pa, int pb, ContourRecord **ListContours, int Nc){
  ED Edge;
  int i,k,a,b;
  ContourRecord *contour;
    

  Edge.from = IMAX(pa,pb);
  Edge.to   = IMIN(pa,pb);
  for(k=0;k<Nc;k++){
    contour = ListContours[k];
    for ( i = -1 ; i < (contour->numpoints - 1) ; i++) {      
      if(i == -1){
        a = permut [ contour->oriented_points[0].permu ];
        b = permut [ contour->oriented_points[contour->numpoints - 1].permu ];
      }
      else{
        a = permut [ contour->oriented_points[i].permu ];
        b = permut [ contour->oriented_points[i+1].permu ];
      }
      
      pointA = IMAX(a,b);
      pointB = IMIN(a,b);
      if(a != pa && b != pa && a != pb && b != pb)
        if(crossED(&Edge)) return (1);
    }
  }  
  return (0);
}

void verify_edges (List_T *ListDelaunay, ContourRecord **ListContour, 
                   int NumContours){

  ED   *pEdge;
  ED   Edge; 
  int  ok,max,i,k,c,a,b; 
  ContourRecord *contour;
  Delaunay *del_P;

  max = 100;

  c = 0;
  do {
    c++;
    if(c>max)break;
    ETree = Tree_Create ( sizeof (Edge) , compareED );
    for (i=0;i< List_Nbr(ListDelaunay);i++) {

      del_P = *(Delaunay**)List_Pointer(ListDelaunay, i);

      Edge.from = IMAX ( del_P->t.a, del_P->t.b );
      Edge.to   = IMIN ( del_P->t.a, del_P->t.b );
      Edge.NbOccur = 1;

      if((pEdge = (ED*)Tree_PQuery(ETree,&Edge))){ 
        pEdge->Liste[1] = del_P;
      }
      else {
        Edge.Liste[0] = del_P;
        Edge.Liste[1] = NULL;
        Tree_Add (ETree,&Edge);
      }
      
      Edge.from = IMAX ( del_P->t.a, del_P->t.c );
      Edge.to   = IMIN ( del_P->t.a, del_P->t.c );
      
      if((pEdge = (ED*)Tree_PQuery(ETree,&Edge))){ 
        pEdge->Liste[1] = del_P;
      }
      else {
        Edge.Liste[0] = del_P;
        Edge.Liste[1] = NULL;
        Tree_Add (ETree,&Edge);
      }
      
      Edge.from = IMAX ( del_P->t.c, del_P->t.b );
      Edge.to   = IMIN ( del_P->t.c, del_P->t.b );
      
      if((pEdge = (ED*)Tree_PQuery(ETree,&Edge))){ 
        pEdge->Liste[1] = del_P;
      }
      else {
        Edge.Liste[0] = del_P;
        Edge.Liste[1] = NULL;
        Tree_Add (ETree,&Edge);
      }
    }
    
    ok = 0;
    for(k=0;k<NumContours;k++){
      contour = ListContour[k];
      for ( i = -1 ; i < contour->numpoints - 1 ; i++){      
        
        if(i == -1){
          a   = permut [ contour->oriented_points[0].permu ];
          b   = permut [ contour->oriented_points[contour->numpoints - 1].permu ];
        }
        else{
          a   = permut [ contour->oriented_points[i].permu ];
          b   = permut [ contour->oriented_points[i+1].permu ];
        }
        
        Edge.from = IMAX(a,b);
        Edge.to   = IMIN(a,b);
        
        if(!Tree_Search( ETree , &Edge ))ok++;; 
      }
    }

    if(!ok){
      return;
    }
    
    Msg(INFO, "Swapping (%d missing edges)", ok); 
    
    //EDToSwap = NULL;
    if(EDToSwap)Tree_Delete(EDToSwap);
    EDToSwap = Tree_Create (sizeof(ED),compareED2);
    for(k=0;k<NumContours;k++){
      contour = ListContour[k];
      for ( i = -1 ; i < contour->numpoints - 1 ; i++){      
        
        if(i == -1){
          a   = permut [ contour->oriented_points[0].permu ];
          b   = permut [ contour->oriented_points[contour->numpoints - 1].permu ];
        }
        else{
          a   = permut [ contour->oriented_points[i].permu ];
          b   = permut [ contour->oriented_points[i+1].permu ];
        }
        
        pointA = IMAX(a,b);
        pointB = IMIN(a,b);
        
        Tree_Action ( ETree , DoWeSwapED ); 
        
      }
    }
    Msg(INFO, "Elimination (%d swaps)", Tree_Nbr(EDToSwap)); 

    Tree_Action (EDToSwap , SuppressInETree);
    Tree_Action (EDToSwap , SwapED);
    Tree_Action (EDToSwap , AddInETree);
  }while(Tree_Nbr(EDToSwap));

  Tree_Delete(EDToSwap);
  Tree_Delete(ETree);

}



int comparepermu(const void *i, const void *j){
  return ( gPointArray[*(PointNumero *)i].permu - gPointArray[*(PointNumero *)j].permu);
}

void verify_inside (Delaunay * ListDelaunay ,  int NumDelaunay ){

  PointNumero pt[3], compare, a, b;
  int         i, inside, cont[3];

  for ( i=0 ; i < NumDelaunay  ; i++){
    
    pt[0] = ListDelaunay[i].t.a;
    pt[1] = ListDelaunay[i].t.b;
    pt[2] = ListDelaunay[i].t.c;
    qsort(pt,3,sizeof(PointNumero),comparepermu);

    cont[0] = gPointArray[pt[0]].numcontour;
    cont[1] = gPointArray[pt[1]].numcontour;
    cont[2] = gPointArray[pt[2]].numcontour;


    if((cont[1] != cont[2])||(cont[0]!=cont[1])||(cont[0]!=cont[2]))
      inside = 1;
    else
      inside = 0;


    a = pt[0];
    b = pt[1];
    compare = pt[2];
    
    if ((Is_left_of ( a,b,compare  ) && (inside == 0))){
      ListDelaunay[i].t.position = EXTERN ;
    }

  }
  return;
  
}      

