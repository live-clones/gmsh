/****************************************************************************
Logiciel initial: MMG3D Version 4.0
Co-auteurs : Cecile Dobrzynski et Pascal Frey.
Propriétaires :IPB - UPMC -INRIA.

Copyright © 2004-2005-2006-2007-2008-2009-2010-2011, 
diffusé sous les termes et conditions de la licence publique générale de GNU
Version 3 ou toute version ultérieure.  

Ce fichier est une partie de MMG3D.
MMG3D est un logiciel libre ; vous pouvez le redistribuer et/ou le modifier
suivant les termes de la licence publique générale de GNU
Version 3 ou toute version ultérieure.
MMG3D est distribué dans l'espoir qu'il sera utile, mais SANS 
AUCUNE GARANTIE ; sans même garantie de valeur marchande.  
Voir la licence publique générale de GNU pour plus de détails.
MMG3D est diffusé en espérant qu’il sera utile, 
mais SANS AUCUNE GARANTIE, ni explicite ni implicite, 
y compris les garanties de commercialisation ou 
d’adaptation dans un but spécifique. 
Reportez-vous à la licence publique générale de GNU pour plus de détails.
Vous devez avoir reçu une copie de la licence publique générale de GNU 
en même temps que ce document. 
Si ce n’est pas le cas, aller voir <http://www.gnu.org/licenses/>.
/****************************************************************************
Initial software: MMG3D Version 4.0
Co-authors: Cecile Dobrzynski et Pascal Frey.
Owners: IPB - UPMC -INRIA.

Copyright © 2004-2005-2006-2007-2008-2009-2010-2011, 
spread under the terms and conditions of the license GNU General Public License 
as published Version 3, or (at your option) any later version.

This file is part of MMG3D
MMG3D is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
MMG3D is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with MMG3D. If not, see <http://www.gnu.org/licenses/>.  
****************************************************************************/
#include "mesh.h"


//#define LLLONG   3.//2.5

int MMG_permar[12][4] = {{0,1,2,3},{0,2,3,1},{2,0,1,3},{0,3,1,2},{1,0,3,2},{3,2,1,0},
                         {3,0,2,1},{1,2,0,3},
                         {3,1,0,2},{2,3,0,1},{2,1,3,0},{1,3,2,0}};

int MMG_pointar[64][2]  = {{-1,-1},
  {0,1},
  {2,1},
  {4,22},
  {6,1},
  {6,22},
  {2,22},
  {10,31},
  {7,1},  
  {10,22},
  {1,22},
  {10,3},
  {0,2},
  {11,33},
  {4,32},
  {4,4},
  {8,1},
  {0,22},
  {7,2},
  {10,32},
  {11,22},
  {0,3},
  {0,33},
  {6,4},
  {8,22},
  {9,31},
  {4,33},
  {10,4},
  {0,32},
  {0,4},
  {2,41},
  {9,5}, 
  {9,1},
  {2,2},
  {5,22},
  {10,33},
  {3,22},
  {2,32},
  {2,3},
  {2,4},
  {7,22},
  {1,32},
  {3,31},
  {1,4},
  {2,33},
  {7,41},
  {5,4},
  {11,5},
  {9,22},
  {6,33},
  {7,32},
  {0,41},
  {0,31},
  {11,4},
  {3,4},
  {7,5},
  {7,3},
  {8,4},
  {7,4},
  {3,5},
  {9,4},
  {1,5},
  {0,5},
  {0,6}
 };
   
int MMG_createPoint(pMesh mesh, pSol sol, int ipa, int ipb) { 
  double    *ca,*cb,*ma,*mb,*mip,mp[6],*mipold,mplog[6],c[3];
  //double    *malog,*mblog;
  int       iadr,ip;

  ca  = &mesh->point[ipa].c[0];
  cb  = &mesh->point[ipb].c[0];

  iadr = (ipa-1)*sol->offset + 1;
  ma  = &sol->met[iadr];
  iadr = (ipb-1)*sol->offset + 1;
  mb  = &sol->met[iadr];        

  c[0] = 0.5*(ca[0] + cb[0]);
  c[1] = 0.5*(ca[1] + cb[1]);   
  c[2] = 0.5*(ca[2] + cb[2]);   
  
  
  ip = MMG_newPt(mesh,c);  

  /* metric interpolation */
  if ( sol->offset==1 ) {   
    if ( !MMG_interp(ma,mb,mp,0.5) )  return(0);
  }    
  else { 
    iadr = (ipa-1)*sol->offset + 1;
    //malog  = &sol->metold[iadr];

    iadr = (ipb-1)*sol->offset + 1;
    //mblog  = &sol->metold[iadr];
    //if ( !MMG_interplog(malog,mblog,mp,mplog,0.5) ) return(0);      
    if ( !MMG_interp_ani(ma,mb,mp,0.5) ) return(0);      
  }
  iadr = (ip-1)*sol->offset + 1;
  mipold  = &sol->metold[iadr];   
  memcpy(mipold,mplog,sol->offset*sizeof(double));
  mip  = &sol->met[iadr];   
  memcpy(mip,mp,sol->offset*sizeof(double));

  return(ip);  
}

extern int ddebug;
int MMG_analarcutting(pMesh mesh,pSol sol,pHedge hash,int *alert,double* lmoy,double LLLONG) {
  pTetra    pt;
  int       k,i,ia,ib,ip,ipa,ipb,iadr,na,ncut;
  double    *ca,*cb,len,*ma,*mb;  
  int       nb[7],ne,base;
  int       ned;
  int       n1,n2,n3,n4,n5,n6,n22,n31,n32,n33,n41;
  
  n1 = n2 = n3 = n4 = n5 = n6 = n22 = n31 = n32 = n33 = n41 = 0;   
  na     = 0;
	*alert = 0; 
  ne     = mesh->ne; 
  base   = ++mesh->flag;  
  
  ned   = 0;
  *lmoy = 0;
  for (k=1; k<=ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue; 
    else if ( pt->flag == base ) continue; //attention si Delaunay avant on peut avoir des trous dans le tab des tets...
    //normalement on devrait pouvoir juste traiter les tets à base-1... non ?    
    pt->tabedg = 0; //because used by cendel
    assert(!pt->tabedg);
    
    ncut  = 0;    
    for (i=0; i<6; i++) {
      ia  = MMG_iare[i][0];
      ib  = MMG_iare[i][1];
      ipa = pt->v[ia];
      ipb = pt->v[ib];
      /* already cutted ? */
      nb[i] = MMG_edgePoint(hash,ipa,ipb);
      if ( nb[i] ) {
        //if(nb[i]==6992) printf("already cut %d %d : %d -- %d\n",ipa,ipb,nb[i],k); 
        pt->tabedg |= 1 << i;
        ncut++;
        continue;
      }
      ca  = &mesh->point[ipa].c[0];
      cb  = &mesh->point[ipb].c[0];
  
      iadr = (ipa-1)*sol->offset + 1;
      ma  = &sol->met[iadr];
      iadr = (ipb-1)*sol->offset + 1;
      mb  = &sol->met[iadr];        

      /* edge length */  
      len = MMG_length(ca,cb,ma,mb); 
      *lmoy += len;
      ned++;
      if ( len > LLLONG ) { 
        ip = MMG_createPoint(mesh,sol,ipa,ipb);
        //if(ip==6992) printf("on cree %d : %d -- %d %d %d %d\n",ip,k,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
        if ( !ip ) {
          *alert = 1;
          return(0);
        }        
        /*hash insertion*/ 
        if ( !MMG_edgePut(hash,ipa,ipb,ip) ) {
          printf("ahhhhhhhhhhhhhhhhh %d %d\n",ipa,ipb); 
          exit(0);
        }
        nb[i] = ip;
        pt->tabedg |= 1 << i;
        na++; 
        ncut++;                   
      } 
    }
    //if(if(mesh->info.ddebug)) printf("tet %d ncut %d : %d %d\n",k,ncut,pt->tabedg,MMG_pointar[pt->tabedg][1]); 
    //if(ddebug && ncut) printf("tet %d %d %d %d\n",pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
    if (!ncut) continue;
    else if ( MMG_pointar[pt->tabedg][1] > -1 ) {
			if(mesh->info.ddebug){
				printf("tet %d : %d\n",k,MMG_pointar[pt->tabedg][1]);
			  printf("pour ce tet ref : %d %d %d %d\n",pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
      }
      switch(MMG_pointar[pt->tabedg][1]) {
        case 1: 
          n1++;
          MMG_pattern1(mesh,sol,hash,k);
          break;
        case 2:
          n2++;
          MMG_pattern2(mesh,sol,hash,k);
          break;
        case 3:
          n3++;
          MMG_pattern3(mesh,sol,hash,k);
          break;
        case 4:
          MMG_pattern4(mesh,sol,hash,k);
          n4++;
          break; 
        case 5:
          MMG_pattern5(mesh,sol,hash,k);
          n5++;
          break;
        case -1:
          puts("MMG_analar case -1");
          exit(0);
        case 6:
          MMG_pattern6(mesh,sol,k,nb); 
          n6++; 
          break; 
        case 22:
          MMG_pattern22(mesh,sol,hash,k); 
          n22++;
          break;
        case 31:
          MMG_pattern31(mesh,sol,hash,k);  
          n31++;
          break;
        case 32:
          MMG_pattern32(mesh,sol,hash,k);  
          n32++;
          break;
        case 33:
          MMG_pattern33(mesh,sol,hash,k);   
          n33++;
          break;
        case 41:
          MMG_pattern41(mesh,sol,hash,k);   
          n41++;
          break;
          
      } 
			//       if ( 1 ){printf("pointar tet 6545 : %d %d %d %d %d\n",
			//                       MMG_pointar[pt->tabedg][1],mesh->tetra[6545].v[0],mesh->tetra[6545].v[1]
			//                                         ,mesh->tetra[6545].v[2],mesh->tetra[6545].v[3]);
			//        printf("bdry ref : %d %d %d %d\n",mesh->tetra[6545].bdryref[0],mesh->tetra[6545].bdryref[1]
			//                                          ,mesh->tetra[6545].bdryref[2],mesh->tetra[6545].bdryref[3]);}
  		//if(mesh->ne>=41495) {exit(0);  }
    
    }/*end if pointar > -1*/   
  } 
  *lmoy /= ned;
  
  /*puts("stats cut -------------------"); 
  printf("1 cut : %8d\n",n1);
  printf("2 cut : %8d %8d\n",n2,n22);
  printf("3 cut : %8d %8d %8d %8d\n",n3,n31,n32,n33);
  printf("4 cut : %8d %8d\n",n4,n41);
  printf("5 cut : %8d\n",n5);
  printf("6 cut : %8d\n",n6);
  printf("---------------------------\n"); */  
	if ( !na )  return(na);
#warning check memory allocation
  
  //printf("%d cut init --- nb tet %d\n",na,mesh->ne);
  return(na);
}





