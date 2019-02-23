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

#define LLONG1  1.41//1.9//1.41

int MMG_nlen,MMG_ncal,MMG_ntopo,MMG_nex;


/* collapse edge b->a (i.e. remove b) */
int MMG_colpoi(pMesh mesh,pSol sol,int iel,int ia,int ib,double coef) {
  pTetra        pt,pt1;
  pPoint        pa,pb,ppt;
  double        coor[3],crit,cal;
  double        solu[6],len,*ca,*cb,*ma,*mb;
  int          *adja,*adja1,base,i,j,l,kk,nk,adj,voy,iadr,ik,ielv,lon,na,nb;
  int           adj1,voy1,s1,iadb,iada,ipb,vois[4],vois1[4],ii,jj,iare1,iare2;
  static List   list;

  pt  = &mesh->tetra[iel];
  lon = MMG_boulep(mesh,iel,ib,&list);
  if ( lon < 1 )  return(0);
  /* topological-geometric checks */
  base = ++mesh->mark;
  na = pt->v[ia];
  nb = pt->v[ib];        
  pa = &mesh->point[na];
  pb = &mesh->point[nb];
  ca = &pa->c[0];
  
  crit =  pt->qual;
  for (l=2; l<=lon; l++) {
    kk   = list.tetra[l] >> 2;
    cal  = mesh->tetra[kk].qual;//(sol->offset==6) ? MMG_caltet_ani(mesh,sol,kk) : MMG_caltet_iso(mesh,sol,kk);
    if ( cal > crit )  crit = cal;
  }
  crit *= coef; 
  //assert(crit < 1e20);
        
  /* change coords of pb */
  iada = (na-1)*sol->offset + 1;
  ma   = &sol->met[iada];
  iadb = (nb-1)*sol->offset + 1;
  memcpy(coor, pb->c,3*sizeof(double));
  memcpy(pb->c,pa->c,3*sizeof(double));
  memcpy(solu,&sol->met[iadb],sol->offset*sizeof(double));
  memcpy(&sol->met[iadb],&sol->met[iada],sol->offset*sizeof(double));

  /* avoid recreating existing elt */
  for (l=1; l<=lon; l++) {
    if ( list.tetra[l] < 0 )  continue;
    kk = list.tetra[l] >> 2;
    nk = list.tetra[l] % 4;

    pt1 = &mesh->tetra[kk];
    s1  = pt1->v[0];

    iadr = (kk-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adj  = adja[nk] >> 2;
    if ( !adj )  continue;
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    vois[0]  = adja[0] >> 2;
    vois[1]  = adja[1] >> 2;
    vois[2]  = adja[2] >> 2;
    vois[3]  = adja[3] >> 2;
    for (j=0; j<4; j++) 
      if ( vois[j] == kk ) {
        pt1 = &mesh->tetra[adj];
	      s1  = pt1->v[j];
	      break;
      }
    if ( s1 == na ) {
      MMG_nex++;
      memcpy(pb->c,coor,3*sizeof(double));
      memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));
      return(0);
    }
  }

  /* topological check */
  for (l=1; l<=lon; l++) {
    kk = list.tetra[l] >> 2;
    nk = list.tetra[l] % 4;
    /* mark elts of shell a-b */
    pt1 = &mesh->tetra[kk];
    for (i=0; i<4; i++) {
      if ( pt1->v[i] == na ) {
        list.tetra[l] = -list.tetra[l];
	    pt1->mark     = base;
	    break;
      }
    }
    

    if ( pt1->mark == base )   continue;
    /* check lengths */
    for (i=0; i<3; i++) {
      ipb  = pt1->v[ MMG_idir[nk][i] ];
      ppt  = &mesh->point[ipb];
      cb   = &ppt->c[0];
      iadr = (ipb-1)*sol->offset + 1;
      mb   = &sol->met[iadr];   
      // if(cal < 1e-10) printf("(%e) long %d : %e\n",cal,i,MMG_length(ca,cb,ma,mb),crit/60.);
      if ( ppt->mark < base ) {
        len = MMG_length(ca,cb,ma,mb);   
        if ( len > crit/60. ) {
          MMG_nlen++;
          memcpy(pb->c,coor,3*sizeof(double));
          memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));
          //printf("len reject %e %e\n",len,LLONG1);
          return(0);
        }
        ppt->mark = base;
      }
    }

    /* check volume of remaining elt */
    cal =  MMG_voltet(mesh,kk);//(sol->offset==6) ? MMG_caltet_ani(mesh,sol,iel) : MMG_caltet_iso(mesh,sol,iel); 
    list.qual[l] = MMG_caltet(mesh,sol,kk); 
    //if( cal < 1e-10 && cal >= 1e-15) printf("cal : %e %e\n",cal,MMG_caltet_ani(mesh,sol,kk));
    if ( cal < 1e-10/*crit*/ ) {
      MMG_ncal++;
      memcpy(pb->c,coor,3*sizeof(double));
      memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));  
//printf("cal reject\n");
      return(0);
    }
    
  }
  /* verif topo */ 
  for (l=1; l<=lon; l++) {
    ik  = abs(list.tetra[l]);
    kk  = ik >> 2;
    nk  = ik % 4;
    pt1 = &mesh->tetra[kk];
    if ( pt1->mark != base )  continue;

    iadr = (kk-1)*4 + 1;
    adja = &mesh->adja[iadr];
    ielv = adja[nk] >> 2;
    vois[0]  = adja[0] >> 2;
    vois[1]  = adja[1] >> 2;
    vois[2]  = adja[2] >> 2;
    vois[3]  = adja[3] >> 2;

    for (i=0; i<4; i++) {
      if ( i == nk )  continue;
      adj = vois[i];
      pt1 = &mesh->tetra[adj];
      if ( pt1->mark == base )  continue;
      adja1 = &mesh->adja[ (adj-1)*4 + 1 ];
      vois1[0]  = adja1[0] >> 2;
      vois1[1]  = adja1[1] >> 2;
      vois1[2]  = adja1[2] >> 2;
      vois1[3]  = adja1[3] >> 2;
      for (j=0; j<4; j++) {
        adj1 = vois1[j];
        if ( pt1->v[j] == nb && adj1 == ielv ) {
	        MMG_ntopo++;
          memcpy(pb->c,coor,3*sizeof(double));
          memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));
	        return(0);
	      }
      }
    }
  }
   
  /* update topo: shell */
  for (l=1; l<=lon; l++) {
    if ( list.tetra[l] > 0 )  continue;

    kk = -list.tetra[l] >> 2;
    nk = -list.tetra[l] % 4;

    pt1 = &mesh->tetra[kk];
    pt1->qual = list.qual[l];
    iadr = (kk-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adj  = adja[nk] >> 2;
    voy  = adja[nk] % 4;
    adj1 = 0;
    voy1 = 0;
    for (j=0; j<4; j++) {
      if ( pt1->v[j] == na ) {
        adj1 = adja[j] >> 2;
	      voy1 = adja[j] % 4;
        if ( adj1 ) {
	        iadr = (adj1-1)*4 + 1;
          adja = &mesh->adja[iadr];
          adja[voy1] = 4*adj + voy;
          mesh->tetra[adj1].bdryref[voy1] = pt1->bdryref[nk]; 
          for(ii=0 ; ii<3 ; ii++) {
						if(!pt1->bdryinfo[MMG_iarf[nk][ii]]) continue;    
						iare1 = pt1->v[MMG_iare[MMG_iarf[nk][ii]][0]];
						iare2 = pt1->v[MMG_iare[MMG_iarf[nk][ii]][1]]; 
						if(iare1==na) {
							iare1=nb;  
						} else if(iare2==na) {
							iare2=nb;         
						}
						else {
						  continue;
						}
						for(jj=0 ; jj<3 ; jj++) {  
							// printf("iare %d %d -- %d %d\n",iare1,iare2,mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][0]],
							// 	mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][1]]);
							if((iare1==mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][0]] &&
								  iare2==mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][1]]) ||
								 (iare2==mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][0]] &&
									iare1==mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][1]])) {
										mesh->tetra[adj1].bdryinfo[MMG_iarf[voy1][jj]] = pt1->bdryinfo[MMG_iarf[nk][ii]];     
										break; 		
							}
						}
						assert(jj<3);
					}
					
	      }
	      break;
      }
    }
    if ( adj ) {
      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[voy] = 4*adj1 + voy1;
      if(!adj1) { 
        mesh->tetra[adj].bdryref[voy] = pt1->bdryref[j];
        for(ii=0 ; ii<3 ; ii++) {
			  	if(!pt1->bdryinfo[MMG_iarf[j][ii]]) continue;
			  	iare1 = pt1->v[MMG_iare[MMG_iarf[j][ii]][0]];
			  	iare2 = pt1->v[MMG_iare[MMG_iarf[j][ii]][1]]; 
			  	if(iare1==na) {
			  		iare1=nb;  
			  	} else if(iare2==na)
			  		iare2=nb;
			  	else
			  	  continue; 
			  	for(jj=0 ; jj<3 ; jj++) {  
			  		// printf("iare %d %d -- %d %d\n",iare1,iare2,mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][0]],
			  		// 	mesh->tetra[adj1].v[MMG_iare[MMG_iarf[voy1][jj]][1]]);
			  		if((iare1==mesh->tetra[adj].v[MMG_iare[MMG_iarf[voy][jj]][0]] &&
			  			  iare2==mesh->tetra[adj].v[MMG_iare[MMG_iarf[voy][jj]][1]]) ||
			  			 (iare2==mesh->tetra[adj].v[MMG_iare[MMG_iarf[voy][jj]][0]] &&
			  				iare1==mesh->tetra[adj].v[MMG_iare[MMG_iarf[voy][jj]][1]])) {
			  					mesh->tetra[adj1].bdryinfo[MMG_iarf[voy1][jj]] = pt1->bdryinfo[j];    
			  					break; 		
			  		}
			  	}
			  	assert(jj<3);
			  }  
			}  
		}
    MMG_delElt(mesh,kk);
  }

  /* update topo: ball */
  for (l=1; l<=lon; l++) {
    if ( list.tetra[l] < 0 )  continue;
    kk  = list.tetra[l] >> 2;
    nk  = list.tetra[l] % 4;
    pt1 = &mesh->tetra[kk];  
    pt1->v[nk] = na;
    pt1->flag  = mesh->flag;
    pt1->qual  = list.qual[l];
    pt1->edge &= ~(1 << MMG_arpt[nk][0]);
    pt1->edge &= ~(1 << MMG_arpt[nk][1]);
    pt1->edge &= ~(1 << MMG_arpt[nk][2]);
  }

  /* delete vertex */
  memcpy(pb->c,coor,3*sizeof(double));
  pa->mark = mesh->flag;

  return(1);
}
/* collapse edge b->a (i.e. remove b) */
int MMG_colpoi2(pMesh mesh,pSol sol,int iel,int ia,int ib,double coef) {
  pTetra        pt,pt1;
  pPoint        pa,pb,ppt;
  double        coor[3],crit,cal,len;
  double         solu[6],*ca,*cb,*ma,*mb;
  int          *adja,*adja1,base,i,j,l,kk,nk,adj,voy,iadr,ik,ielv,lon,na,nb;
  int           adj1,voy1,s1,ipb,iadb,iada;
  static List   list;

  pt  = &mesh->tetra[iel];
  lon = MMG_boulep(mesh,iel,ib,&list);
  if ( lon < 1 )  return(0);

  /* topological-geometric checks */
  base = ++mesh->mark;
  na = pt->v[ia];
  nb = pt->v[ib];
  pa = &mesh->point[na];
  pb = &mesh->point[nb];
  ca = &pa->c[0];

  crit = pt->qual;
  for (l=2; l<=lon; l++) {
    kk   = list.tetra[l] >> 2;
    cal  = MMG_caltet(mesh,sol,kk);
    if ( cal > crit )  crit = cal;
  }
  crit *= coef;

  /* change coords of pb */
  iada = (na-1)*sol->offset + 1;
  ma   = &sol->met[iada];
  iadb = (nb-1)*sol->offset + 1;
  memcpy(coor, pb->c,3*sizeof(double));
  memcpy(pb->c,pa->c,3*sizeof(double));
  memcpy(solu,&sol->met[iadb],sol->offset*sizeof(double));
  memcpy(&sol->met[iadb],&sol->met[iada],sol->offset*sizeof(double));

  /* avoid recreating existing elt */
  for (l=1; l<=lon; l++) {
    if ( list.tetra[l] < 0 )  continue;
    kk = list.tetra[l] >> 2;
    nk = list.tetra[l] % 4;

    pt1 = &mesh->tetra[kk];
    s1  = pt1->v[0];

    iadr = (kk-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adj  = adja[nk] >> 2;
    if ( !adj )  continue;
    iadr = (adj-1)*4 + 1;
    adja = &mesh->adja[iadr];
    for (j=0; j<4; j++) 
      if ( adja[j]/4 == kk ) {
        pt1 = &mesh->tetra[adj];
	      s1  = pt1->v[j];
	      break;
      }
    if ( s1 == na ) {
      MMG_nex++;
      memcpy(pb->c,coor,3*sizeof(double));
      memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));
      return(0);
    }
  }

  /* topological check */
  for (l=1; l<=lon; l++) {
    kk = list.tetra[l] >> 2;
    nk = list.tetra[l] % 4;

    /* mark elts of shell a-b */
    pt1 = &mesh->tetra[kk];
    for (i=0; i<4; i++) {
      if ( pt1->v[i] == na ) {
        list.tetra[l] = -list.tetra[l];
	      pt1->mark     = base;
	      break;
      }
    }
    /* check volume of remaining elt */
    if ( pt1->mark == base )   continue;
    cal = MMG_caltet(mesh,sol,kk);
    list.qual[l] = cal;
    if ( cal > crit ) {
      MMG_ncal++;
      memcpy(pb->c,coor,3*sizeof(double));
      memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));
//printf("bad quality : %f > %f\n",cal,crit);
      return(0);
    }
    
    /* check lengths */
    for (i=0; i<3; i++) {
      ipb = pt1->v[ MMG_idir[nk][i] ];
      ppt = &mesh->point[ipb];
      cb   = &ppt->c[0];
      iadr = (ipb-1)*sol->offset + 1;
      mb   = &sol->met[iadr];
       if ( ppt->mark < base ) {
        len = MMG_length(ca,cb,ma,mb);
	      if ( len > 1.51 ) {
	        MMG_nlen++;
          memcpy(pb->c,coor,3*sizeof(double));
          memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));
//printf("bad MMG_length : %f > %f\n",len,1.51);
          return(0);
        }
        ppt->mark = base;
      }
    }
  }

  /* verif topo */
  for (l=1; l<=lon; l++) {
    ik  = abs(list.tetra[l]);
    kk  = ik >> 2;
    nk  = ik % 4;
    pt1 = &mesh->tetra[kk];
    if ( pt1->mark != base )  continue;

    iadr = (kk-1)*4 + 1;
    adja = &mesh->adja[iadr];
    ielv = adja[nk] >> 2;

    for (i=0; i<4; i++) {
      if ( i == nk )  continue;
      adj = adja[i] >> 2;
      pt1 = &mesh->tetra[adj];
      if ( pt1->mark == base )  continue;
      adja1 = &mesh->adja[ (adj-1)*4 + 1 ];
      for (j=0; j<4; j++) {
        adj1 = adja1[j] >> 2;
        if ( pt1->v[j] == nb && adj1 == ielv ) {
	        MMG_ntopo++;
          memcpy(pb->c,coor,3*sizeof(double));
          memcpy(&sol->met[iadb],solu,sol->offset*sizeof(double));
	        return(0);
	      }
      }
    }
  }

  /* update topo: shell */
  for (l=1; l<=lon; l++) {
    if ( list.tetra[l] > 0 )  continue;

    kk = -list.tetra[l] >> 2;
    nk = -list.tetra[l] % 4;

    pt1 = &mesh->tetra[kk];
    pt1->qual = list.qual[l];
    iadr = (kk-1)*4 + 1;
    adja = &mesh->adja[iadr];
    adj  = adja[nk] >> 2;
    voy  = adja[nk] % 4;
    adj1 = 0;
    voy1 = 0;
    for (j=0; j<4; j++) {
      if ( pt1->v[j] == na ) {
        adj1 = adja[j] >> 2;
	      voy1 = adja[j] % 4;
        if ( adj1 ) {
	        iadr = (adj1-1)*4 + 1;
          adja = &mesh->adja[iadr];
          adja[voy1] = 4*adj + voy;  
          mesh->tetra[adj1].bdryref[voy1] = pt1->bdryref[nk];
	      }
	      break;
      }
    }
    if ( adj ) {
      iadr = (adj-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[voy] = 4*adj1 + voy1;
      if(!adj1)  
        mesh->tetra[adj].bdryref[voy] = pt1->bdryref[j];
    }
    MMG_delElt(mesh,kk);
  }

  /* update topo: ball */
  for (l=1; l<=lon; l++) {
    if ( list.tetra[l] < 0 )  continue;
    kk  = list.tetra[l] >> 2;
    nk  = list.tetra[l] % 4;
    pt1 = &mesh->tetra[kk];
    pt1->v[nk] = na;
    pt1->flag  = mesh->flag;
    pt1->qual  = list.qual[l];
    pt1->edge &= ~(1 << MMG_arpt[nk][0]);
    pt1->edge &= ~(1 << MMG_arpt[nk][1]);
    pt1->edge &= ~(1 << MMG_arpt[nk][2]);
  }

  /* delete vertex */
  memcpy(pb->c,coor,3*sizeof(double));
  pa->mark = mesh->flag;

  return(1);
}
