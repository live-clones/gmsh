/* $Id: 2D_SMesh.cpp,v 1.4 2000-11-26 15:43:46 geuzaine Exp $ */
/*  
  Maillage transfini surfacique                                                 
                                            *s2
       s3     c2    s2                     /|  
        *-----------*                     / |
        |           |                  c2/  |c1   
      c3|           |c1                 /   |  
        |           |                  /    |
  v     *-----------*                 *-----*
  |    s0     c0    s1               s0  c0  s1
  *--u

  Decoupages :  |
                *--*
                |\ |
                | \|   
                *--*-- 
               s0    -> s1
*/

#include "Gmsh.h"
#include "Geo.h"
#include "Mesh.h"
#include "Numeric.h"
#include "Interpolation.h"

extern Mesh  *THEM;
extern int    CurrentNodeNumber;

int index1d (int flag, int N, int n){
  switch(flag){    
  case 0 : return(n);
  case 1 : return(N-n-1);
  default : return -1;
  }
}

int MeshTransfiniteSurface (Surface *sur) {  
  int       i,j,k,flag,nb,N1,N2,issphere;
  int       nbquad=0,nbtri=0;
  Curve    *G[4],*GG[4];
  Vertex    V,**vexist,*pV,*c1,*c2,**list,*CP[2];
  Simplex  *simp;
  double    u,v;
  int       C_flag[4];
  Vertex   *C[4],*S[4];

  static int tab1qua[] = {0,1, 1,2, 3,2, 0,3};
  static int tab1tri[] = {0,1, 1,2, 0,2};
  static int tab2[] = {0,1, 1,0};

  if (sur->Method != TRANSFINI) return(0);

  switch(sur->Typ){

  case MSH_SURF_REGL:
  case MSH_SURF_PLAN:
  case MSH_SURF_TRIC:
  case MSH_SURF_NURBS:

    nb = List_Nbr(sur->s.Generatrices);
    if(nb != 3 && nb != 4) return(0);

    for(i=0;i<4;i++) G[i] = NULL ;

    for(i=0;i<nb;i++){
      V.Num = sur->ipar[i];
      pV = &V;
      if((vexist = (Vertex**)Tree_PQuery(THEM->Vertices,&pV)) == NULL) {
        Msg(WARNING, "Unknown Control Point %d in Transfinite Surface %d",
            V.Num,sur->Num); 
        return(0);
      }
      else{
        S[i]=*vexist;
      }
    }       

    for(i=0;i<nb;i++) List_Read(sur->s.Generatrices,i,&GG[i]);

    for(i=0;i<nb;i++){      
      List_Read(GG[i]->Control_Points,0,&CP[0]);
      List_Read(GG[i]->Control_Points,List_Nbr(GG[i]->Control_Points)-1,&CP[1]);

      for(flag=0;flag<2;flag++){
        for(k=0;k<nb;k++){
          if(nb == 4){
            if(S[tab1qua[2*k  ]]->Num == CP[tab2[2*flag  ]]->Num && 
               S[tab1qua[2*k+1]]->Num == CP[tab2[2*flag+1]]->Num){ 
              G[k]=GG[i];
              C_flag[k]=flag;
            }
          }
          else{
            if(S[tab1tri[2*k  ]]->Num == CP[tab2[2*flag  ]]->Num && 
               S[tab1tri[2*k+1]]->Num == CP[tab2[2*flag+1]]->Num){ 
              G[k]=GG[i];
              C_flag[k]=flag;
            }
          }
        }       
      }
    }

    for(i=0;i<nb;i++)
      if(G[i] == NULL) {
        Msg(WARNING, "Wrong definition of Transfinite Surface %d", 
            sur->Num); 
        return(0);
      }

    if(nb == 4) {
      if((N1 = List_Nbr(G[0]->Vertices)) != List_Nbr(G[2]->Vertices)) return(0); 
      if((N2 = List_Nbr(G[1]->Vertices)) != List_Nbr(G[3]->Vertices)) return(0); 
    }
    else {
      if((N1 = List_Nbr(G[0]->Vertices)) != List_Nbr(G[2]->Vertices)) return(0); 
      N2 = List_Nbr(G[1]->Vertices);      
    }

    sur->Nu = N1;
    sur->Nv = N2;
    list = (Vertex**)Malloc(N1*N2*sizeof(Vertex*));

    issphere = 1;
    for(i=0;i<nb;i++){
      if(G[i]->Typ != MSH_SEGM_CIRC && G[i]->Typ != MSH_SEGM_CIRC_INV){
        issphere = 0;
      }
      else if (issphere){
        if(!i){
          List_Read(G[i]->Control_Points, 1, &c1);
        }
        else{
          List_Read(G[i]->Control_Points, 1, &c2);
          if(compareVertex(&c1,&c2))issphere = 0;
        }
      }
    }
    
    for(i=0;i<N1;i++){
      List_Read(G[0]->Vertices, index1d(C_flag[0],N1,i), &C[0]);
      List_Read(G[2]->Vertices, index1d(C_flag[2],N1,i), &C[2]);        

      if( (G[0]->Num>0 && C_flag[0]) || (G[0]->Num<0 && !C_flag[0]) ) 
        u = 1.-C[0]->u; 
      else
        u = C[0]->u;

      for(j=0;j<N2;j++){
        List_Read(G[1]->Vertices, index1d(C_flag[1],N2,j), &C[1]);
        if(nb == 4) 
          List_Read(G[3]->Vertices, index1d(C_flag[3],N2,j), &C[3]);

        if( (G[1]->Num>0 && C_flag[1]) || (G[1]->Num<0 && !C_flag[1]) ) 
          v = 1.-C[1]->u;
        else
          v = C[1]->u;

        if(i && j && i != N1-1 && j != N2-1){
          if (sur->Typ == MSH_SURF_NURBS)
            V = InterpolateSurface (sur, u, v, 0, 0);
          else if(nb == 4) 
            V = TransfiniteQua(*C[0],*C[1],*C[2],*C[3],*S[0],*S[1],*S[2],*S[3],u,v);
          else
            V = TransfiniteTri(*C[0],*C[1],*C[2],*S[0],*S[1],*S[2],u,v);
          if(issphere) 
            TransfiniteSph(*C[0],*c1,&V);
          list[i+N1*j] = Create_Vertex(++CurrentNodeNumber,V.Pos.X,V.Pos.Y,V.Pos.Z,V.lc,0.0);
        }
        else if(!i) 
          list[i+N1*j] = (nb == 4)?C[3]:C[2];
        else if(!j) 
          list[i+N1*j] = C[0];
        else if(i == N1-1) 
          list[i+N1*j] = C[1];
        else if(j == N2-1) 
          list[i+N1*j] = C[2];
        
        list[i + N1 * j]->us[0] = u;
        list[i + N1 * j]->us[1] = v;
      }
    }


    for(i=0;i<N1;i++){
      for(j=0;j<N2;j++){
        List_Add(sur->TrsfVertices,&list[i+N1*j]);
      }
    }

    if(nb == 4){      
      for(i=0;i<N1;i++){
        for(j=0;j<N2;j++){
          Tree_Replace(sur->Vertices,&list[i+N1*j]);
        }
      }      
      for(i=0;i<N1-1;i++){
        for(j=0;j<N2-1;j++){
          if(sur->Recombine){
            simp = Create_Quadrangle(list[(i) + N1*(j)], list[(i+1)+ N1*(j)],
                                     list[(i+1)+ N1*(j+1)], list[(i)+ N1*(j+1)]);
            simp->iEnt = sur->Num;
            Tree_Add(sur->Simplexes,&simp);
            List_Add(sur->TrsfSimplexes,&simp);

            nbquad++;
          }
          else{
            simp = Create_Simplex(list[(i) + N1*(j)], list[(i+1) + N1*(j)], 
                                  list[(i) + N1*(j+1)], NULL);
            simp->iEnt = sur->Num;
            Tree_Add(sur->Simplexes,&simp);
            List_Add(sur->TrsfSimplexes,&simp);

            simp = Create_Simplex(list[(i+1) + N1*(j+1)], list[(i) + N1*(j+1)],
                                  list[(i+1) + N1*(j)], NULL);
            simp->iEnt = sur->Num;
            Tree_Add(sur->Simplexes,&simp);
            List_Add(sur->TrsfSimplexes,&simp);

            nbtri += 2;
          }
        }
      }                  
    }
    else if(nb == 3) {
      Tree_Replace(sur->Vertices,&list[0]);
      for(i=1;i<N1;i++){
        for(j=0;j<N2;j++){
          Tree_Replace(sur->Vertices,&list[i+N1*j]);
        }
      }      
      for(j=0;j<N2-1;j++){
        simp = Create_Simplex(list[1 + N1*(j+1)], list[N1*(j+1)],list[1 + N1*(j)],NULL);
        simp->iEnt = sur->Num;
        Tree_Add(sur->Simplexes,&simp);
        List_Add(sur->TrsfSimplexes,&simp);

        nbtri++;
      }      
      for(i=1;i<N1-1;i++){
        for(j=0;j<N2-1;j++){
          if(sur->Recombine){
            simp = Create_Quadrangle(list[(i) + N1*(j)],list[(i+1) + N1*(j)],
                                     list[(i+1) + N1*(j+1)],list[i+N1*(j+1)]);
            simp->iEnt = sur->Num;
            Tree_Add(sur->Simplexes,&simp);
            List_Add(sur->TrsfSimplexes,&simp);

            nbquad++;
          }
          else{
            simp = Create_Simplex(list[(i) + N1*(j)], list[(i+1) + N1*(j)], 
                                  list[(i) + N1*(j+1)],NULL);
            simp->iEnt = sur->Num;
            Tree_Add(sur->Simplexes,&simp);
            List_Add(sur->TrsfSimplexes,&simp);

            simp = Create_Simplex(list[(i+1) + N1*(j+1)], list[(i) + N1*(j+1)],
                                  list[(i+1) + N1*(j)], NULL);
            simp->iEnt = sur->Num;
            Tree_Add(sur->Simplexes,&simp);
            List_Add(sur->TrsfSimplexes,&simp);

            nbtri += 2;
          }
        }
      }                         
      
    }
    break;
    
  default:
    return(0);
  }  

  free(list);

  // We count this here, to be able to distinguish very quickly
  // between triangles and quadrangles later
  THEM->Statistics[8] += nbquad;

  return(1);
}

