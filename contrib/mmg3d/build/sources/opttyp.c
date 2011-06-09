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

#define OCRIT    0.99
#undef  QDEGRAD
#define QDEGRAD 2.

int MMG_colpoi2(pMesh mesh,pSol sol,int iel,int ia,int ib,double coef);

/* optimize mesh quality based on element type */
int MMG_opttyp(pMesh mesh,pSol sol,double declic,int *alert) {
  pTetra     pt,pt1;
  pPoint     pa,pb;
  List       list;
  pQueue     queue;
  double      crit;
  double     len,*ca,*cb,*ma,*mb;
  int       *adja,i,k,l,iar,ia,ib,iel,iadr,ier,item[2],nd,base,ityp,np;
  int        npeau,cs[10],ds[10],dsb[3],lon,sombdry,dpeau;
  int        ipa,ipb,iarmin,iarmax,ndd,nbt,j;
double LLONG2;

  /*classification des mauvais : 0 si pas sur la peau*/
  /*				 1 si au moins une face de peau */
  /*				 2 si au moins une arete sur la peau */
  if(mesh->info.imprim < -5 ) {
    puts("  ");
 
    nd = 0;
    memset(cs,0,10*sizeof(int)); 
    memset(ds,0,10*sizeof(int));
    nbt = 0;
    for(k=1 ; k<=mesh->ne ; k++) {
      pt = &mesh->tetra[k];
//if(k== 40117) printf("tetra %d %e : %d %d %d %d\n",k,pt->qual*ALPHAD,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
      if(!pt->v[0] || pt->qual < declic) continue;
      nbt++;
//if(k== 40117) printf("tetra %d %e : %d %d %d %d\n",k,pt->qual*ALPHAD,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
   
      iadr = 4*(k-1) + 1;
      adja = &mesh->adja[iadr];
      for(i=0 ; i<4 ; i++) {
        if(!adja[i])break;     
      }
      if(i==4) {
         for(i = 0 ; i<6 ; i++) 
           if(!MMG_coquil(mesh,k,i,&list)) break;

         if ( i==6 )  cs[0]++;
         else cs[2]++;
      } else cs[1]++;
    }

    printf("  tetra interne        = %5d / %5d  %6.2f %%\n",cs[0],nbt,100.0*cs[0]/nbt);
    printf("  tetra face peau      = %5d / %5d  %6.2f %%\n",cs[1],nbt,100.0*cs[1]/nbt);
    printf("  tetra arete peau     = %5d / %5d  %6.2f %%\n",cs[2],nbt,100.0*cs[2]/nbt);
  
    printf("\n");
  
  }
  
  
  /*traitement des mauvais*/
  base  = mesh->flag;
  ier   = 0;
  queue = MMG_kiuini(mesh,mesh->nemax,declic,base - 1);
  assert(queue);

  memset(cs,0,10*sizeof(int)); 
  memset(ds,0,10*sizeof(int));
  memset(dsb,0,3*sizeof(int));
  nd   = 0;

  if ( !MMG_zaldy4(&list.hedg,3*LONMAX) ) {
    fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM MMG_OPTTYP.\n");
    MMG_kiufree(queue);
    return(0);
  }

  np = 0;
  do {
    k = MMG_kiupop(queue);
    if ( !k )  break;
    np++;
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    else if ( pt->qual < declic )  continue;
	  else if ( pt->flag != base - 1 ) continue;
	
    LLONG2 = 0.1;

    crit = pt->qual * OCRIT;
    ityp = MMG_typelt(mesh,k,item);
cs[ityp]++;
//if(k==175494) printf("tetra %d (%d) %e : %d %d %d %d\n",k,ityp,pt->qual*ALPHAD,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
    iadr = 4*(k-1) + 1;
    adja = &mesh->adja[iadr];
    /*optim bdry tetra*/
    npeau = 0;
    for(i=0 ; i<4 ; i++) {
      if(!adja[i])npeau++;     
    }
      
    if(npeau>1 && !mesh->info.noswap) {
      if(mesh->info.imprim<-4) printf("%d faces de peau!!!! %d (typ %d) %e\n",npeau,k,ityp,pt->qual * ALPHAD);
      dsb[0]++;
      if(MMG_opt2peau(mesh,sol,queue,k,declic)){ 
        nd++; 
        continue;
      }
    }  
    if(npeau) {       
      dpeau = MMG_optbdry(mesh,sol,k);
      dsb[dpeau]++;
      if(dpeau) { 
        nd++;
        ds[ityp]++;
	    continue;
      }
    } 
    if(mesh->info.noswap) continue;
    switch(ityp) {
    case 1:  /* sliver */
      iar = item[0];
      lon = MMG_coquil(mesh,k,iar,&list);
      if ( lon > 2 ) {
        crit = pt->qual;
        for (l=2; l<=lon; l++) {
          iel = list.tetra[l] / 6;
          pt1 = &mesh->tetra[iel];
          if ( pt1->qual > crit )  crit = pt1->qual;
        }
        /*impossible de dégrader à cause des swap 4-4*/
        crit *= OCRIT;
	    ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,declic);
        if ( ier == 0 && !mesh->info.noinsert) {
		  if ( MMG_voltet(mesh,k) < 5.e-9 ) {
		    crit *= 2.;
		    crit = M_MIN(crit,8e+8);
		  } 
          ia  = MMG_iare[iar][0];
          ib  = MMG_iare[iar][1];
          ipa = pt->v[ia];
          ipb = pt->v[ib];
          ca  = &mesh->point[ipa].c[0];
          cb  = &mesh->point[ipb].c[0];
          
	      iadr = (ipa-1)*sol->offset + 1;
          ma   = &sol->met[iadr];
          iadr = (ipb-1)*sol->offset + 1;
          mb   = &sol->met[iadr];
	  
	      len = MMG_length(ca,cb,ma,mb);
	      if(len > LLONG2)
	        ier = MMG_spledg(mesh,sol,queue,&list,lon,crit,declic);
	      
	      if ( ier ) {
   	        pt1  = &mesh->tetra[mesh->point[ier].tmp];  
		    for(j=0 ; j<4 ; j++) {
		      if(pt1->v[j] == ier) break;	
		    }
		    assert(j<4);
            ier = MMG_movevertex(mesh,sol,mesh->point[ier].tmp,j);
		    if ( ier==1 ) {
		    } else {
		      ier = 1;
		    }
	      }
	    }
	    if ( ier > 0 ) {
           nd++;
          ds[1]++;
          break;
        }
	    else if ( ier < 0 ) {
	      *alert = 1;
	      break;
	    }
      }
      for(i=0 ; i<6 ; i++) {
      	if(i==item[0]) continue;
        lon = MMG_coquil(mesh,k,i,&list);
        if ( lon > 2 ) {
          crit = pt->qual;
          for (l=2; l<=lon; l++) {
            iel = list.tetra[l] / 6;
            pt1 = &mesh->tetra[iel];
            if ( pt1->qual > crit )  crit = pt1->qual;
          }
          crit *= OCRIT;
          
          ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,declic);

	      if ( ier == 0 && !mesh->info.noinsert) {
           	/*if ( MMG_voltet(mesh,k) < 5.e-9 ) {     //degrade trop les maillages!!!
			  crit *= 2.;
			  crit = M_MIN(crit,8e+8);
			} */
		    ia  = MMG_iare[i][0];
            ib  = MMG_iare[i][1];
            ipa = pt->v[ia];
            ipb = pt->v[ib];
            ca  = &mesh->point[ipa].c[0];
            cb  = &mesh->point[ipb].c[0];
          
	        iadr = (ipa-1)*sol->offset + 1;
            ma   = &sol->met[iadr];
            iadr = (ipb-1)*sol->offset + 1;
            mb   = &sol->met[iadr];
	  
	        len = MMG_length(ca,cb,ma,mb);
	        if(len > LLONG2)
	          ier = MMG_spledg(mesh,sol,queue,&list,lon,crit,declic);	  
	        
	        if ( ier ) {
		      pt1  = &mesh->tetra[mesh->point[ier].tmp];
		      for(j=0 ; j<4 ; j++) {
		        if(pt1->v[j] == ier) break;	
		      }
		      assert(j<4);
			  ier = MMG_movevertex(mesh,sol,mesh->point[ier].tmp,j);
		      if ( ier==1 ) {
		      } else {
				ier = 1;
		      }
		    } /*end if ier for movevertex*/         
          } /*end if ier == 0 */
	  
	      if ( ier > 0 ) {
            nd++;
            ds[1]++;
	        break;
          }
	      else if ( ier < 0 )
	        *alert = 1; 
        } /*end if lon==2*/
      } /*end for i*/
      if(i<6) break;
      /*move vertex*/
      for(i=0 ; i<4 ; i++) {
        if(MMG_movevertex(mesh,sol,k,i)) {
          nd++;
	      ds[ityp]++;
	      break;
        }	  
      }
      break;

    case 2:  /* chapeau */
      /*on essaie de decoller le point de l'arete*/
      iar = item[0];
      if((sol->offset!=1) && MMG_movevertex(mesh,sol,k,iar)) {
        nd++;
	ds[ityp]++;
      } else {
        for(i=0 ; i<4 ; i++) {
	  if(iar==i) continue;
          if((sol->offset!=1) && MMG_movevertex(mesh,sol,k,i)) {
            nd++;
	    ds[ityp]++;
	    break;
          }	  
	}
      }
      break;

    case 3:  /* aileron */
      iar = item[1];
      ier = MMG_simu23(mesh,sol,k,iar,crit);
      if ( ier > 0 ) {
       	MMG_swap23(mesh,sol,queue,k,iar,crit);
	nd++;
        ds[ityp]++;
	break;
      }
      else if ( ier < 0 ) {
	*alert = 1;
	break;
      }

      iar = item[0];
      lon = MMG_coquil(mesh,k,iar,&list);
//if(!lon) printf("arete de bord!!!!!!!!!!!!!\n");
      if ( lon > 2 ) {
        crit = pt->qual;
        for (l=2; l<=lon; l++) {
          iel = list.tetra[l] / 6;
          pt1 = &mesh->tetra[iel];
          if ( pt1->qual > crit )  crit = pt1->qual;
        }
        crit *= OCRIT;
        ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,declic);
	if ( ier == 0 && !mesh->info.noinsert) {
          ia  = MMG_iare[iar][0];
          ib  = MMG_iare[iar][1];
          ipa = pt->v[ia];
          ipb = pt->v[ib];
          ca  = &mesh->point[ipa].c[0];
          cb  = &mesh->point[ipb].c[0];
          
	  iadr = (ipa-1)*sol->offset + 1;
          ma   = &sol->met[iadr];
          iadr = (ipb-1)*sol->offset + 1;
          mb   = &sol->met[iadr];
	  
	  len = MMG_length(ca,cb,ma,mb);
	  if(len > LLONG2)
	    ier = MMG_spledg(mesh,sol,queue,&list,lon,crit,declic);
	  
	}
 	if ( ier > 0 ) {
          nd++;
          ds[3]++;
        }
	else if ( ier < 0 )
	  *alert = 1;
      }
      
      if(ier) break;
      
//       /*try collapse one edge*/
//       iar = item[0];
//       for(i=0 ; i<6 ; i++) {
// 	ia = MMG_iare[i][0];
// 	ib = MMG_iare[i][1];
// 	ipa = pt->v[ia];
// 	ipb = pt->v[ib];
//         if(MMG_colpoi2(mesh,sol,k,ia,ib,QDEGRAD)) {
//          MMG_delPt(mesh,ipb);
// 	  //printf("1 : on a reussi a supprimer le tetra mauvais \n");
//           break;
//         } else if(MMG_colpoi2(mesh,sol,k,ib,ia,QDEGRAD)) {
//           MMG_delPt(mesh,ipa);
// 	  //printf("2 : on a reussi a supprimer le tetra mauvais\n");
//           break;
//         }
// 	
//       }

      /*move vertex*/
      for(i=0 ; i<4 ; i++) {
        if(MMG_movevertex(mesh,sol,k,i)) {
          nd++;
	  ds[ityp]++;
	  break;
        }	  
      }

      break;

    case 4:  /* berlingot */
      iar = item[0];
      ia  = MMG_iare[iar][0];
      ib  = MMG_iare[iar][1];
      ipa = pt->v[ia];
      ipb = pt->v[ib];
      pa  = &mesh->point[ipa];
      pb  = &mesh->point[ipb];
      if ( !mesh->info.noinsert && !(pb->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ia,ib,QDEGRAD) ) {
        nd++;
        MMG_delPt(mesh,ipb);
        ds[ityp]++;
        break;
      } 
      else if( !mesh->info.noinsert && !(pa->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ib,ia,QDEGRAD) ) {
        nd++;
        MMG_delPt(mesh,ipa);
        ds[ityp]++;
        break; 
      }
      if( (sol->offset!=1) && !(pb->tag & M_BDRY)) {
        if(MMG_movevertex(mesh,sol,k,ib)) {
	  nd++;
	  ds[ityp]++;
	  break;
	}
      }	
      if( (sol->offset!=1) && !(pa->tag & M_BDRY)) {
        if(MMG_movevertex(mesh,sol,k,ia)) {
	  nd++;
	  ds[ityp]++;
	  break;
	}
      }	

      break;

    case 5:  /* 0 good face: split largest edge + node move */
      break;

    case 6:  /* O good face: move away closest vertices */
      /*collapse item[0]*/
      ier = 0;
      iar = item[0];
      ia  = MMG_iare[iar][0];
      ib  = MMG_iare[iar][1];
      ipa = pt->v[ia];
      ipb = pt->v[ib];
      ca  = &mesh->point[ipa].c[0];
      cb  = &mesh->point[ipb].c[0];
      iadr = (ipa-1)*sol->offset + 1;
      ma  = &sol->met[iadr];
      iadr = (ipb-1)*sol->offset + 1;
      mb  = &sol->met[iadr];
      if ( (MMG_length(ca,cb,ma,mb) < LSHORT) ) {
        pa  = &mesh->point[ipa];
        pb  = &mesh->point[ipb];
        if ( !mesh->info.noinsert && !(pb->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ia,ib,QDEGRAD) ) {
          ier = 2;
	  nd++;
          MMG_delPt(mesh,ipb);
          ds[ityp]++;
          break;
        } 
        else if( !mesh->info.noinsert && !(pa->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ib,ia,QDEGRAD) ) {
          ier = 2;
	  nd++;
          MMG_delPt(mesh,ipa);
          ds[ityp]++;
          break; 
        }
      }
       
      /*split item[1]*/
      iar = item[1];
      lon = MMG_coquil(mesh,k,iar,&list);
      if ( lon <= 2 ) break;
      
      crit = pt->qual;
      for (l=2; l<=lon; l++) {
        iel = list.tetra[l] / 6;
        pt1 = &mesh->tetra[iel];
        if ( pt1->qual > crit )  crit = pt1->qual;
      }  
      crit *= OCRIT;
      ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,declic);
      if ( ier == 0 && !mesh->info.noinsert) {
          ia  = MMG_iare[iar][0];
          ib  = MMG_iare[iar][1];
          ipa = pt->v[ia];
          ipb = pt->v[ib];
          ca  = &mesh->point[ipa].c[0];
          cb  = &mesh->point[ipb].c[0];
          
	  iadr = (ipa-1)*sol->offset + 1;
          ma   = &sol->met[iadr];
          iadr = (ipb-1)*sol->offset + 1;
          mb   = &sol->met[iadr];
	  
	  len = MMG_length(ca,cb,ma,mb);
	  if(len > LLONG2)
	    ier = MMG_spledg(mesh,sol,queue,&list,lon,crit,declic);
      }
      if ( ier > 0 ) {
        nd++;
        ds[ityp]++;
        break;
      }
      else if ( ier < 0 ) {
        *alert = 1;
        break;
      }        
      break;
    
    case 7:
      /*collapse d'une des 2 petites aretes*/
      ier    = 0;
      iarmin = item[0];
      iarmax = item[1];
      ia  = MMG_iare[iarmin][0];
      ib  = MMG_iare[iarmin][1];
      ipa = pt->v[ia];
      ipb = pt->v[ib];
      ca  = &mesh->point[ipa].c[0];
      cb  = &mesh->point[ipb].c[0];
      iadr = (ipa-1)*sol->offset + 1;
      ma  = &sol->met[iadr];
      iadr = (ipb-1)*sol->offset + 1;
      mb  = &sol->met[iadr];

      i = 6;
      if(!mesh->info.noinsert && (MMG_length(ca,cb,ma,mb) < LSHORT)) {
        pa  = &mesh->point[ipa];
        pb  = &mesh->point[ipb];
        if ( !(pb->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ia,ib,QDEGRAD) ) {
         ier = 2;
	  nd++;
          MMG_delPt(mesh,ipb);
          ds[ityp]++;
	  i = 0;
          break;
        } 
        else if( !(pa->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ib,ia,QDEGRAD) ) {
          ier = 2;
	  nd++;
          MMG_delPt(mesh,ipa);
          ds[ityp]++;
	  i = 0;
          break; 
        }
      }
      if(ier) break;
           
      lon = MMG_coquil(mesh,k,iarmax,&list);
      if ( lon <= 2 ) break;
      if (!mesh->info.noinsert) {
        lon = MMG_coquil(mesh,k,iarmax,&list);
        if ( lon <= 2 ) break;
        crit = pt->qual;
        for (l=2; l<=lon; l++) {
          iel = list.tetra[l] / 6;
          pt1 = &mesh->tetra[iel];
          if ( pt1->qual > crit )  crit = pt1->qual;
        }  
        crit *= OCRIT;

        ia  = MMG_iare[iarmax][0];
        ib  = MMG_iare[iarmax][1];
        ipa = pt->v[ia];
        ipb = pt->v[ib];
        ca  = &mesh->point[ipa].c[0];
        cb  = &mesh->point[ipb].c[0];
        
	iadr = (ipa-1)*sol->offset + 1;
        ma   = &sol->met[iadr];
        iadr = (ipb-1)*sol->offset + 1;
        mb   = &sol->met[iadr];
	
	len = MMG_length(ca,cb,ma,mb);
	if(len > LLONG2)
	  ier = MMG_spledg(mesh,sol,queue,&list,lon,crit,declic);
	
	if ( ier > 0 ) {
           nd++;
          ds[ityp]++;
          break;
        }
      }

      /*boucle sur les autres aretes != de iarmax et de iarmin*/
      for(i=0 ; i<6 ; i++) {
        if(i==iarmin) continue;
	if(i==iarmax) continue;
        ia  = MMG_iare[i][0];
        ib  = MMG_iare[i][1];
        ipa = pt->v[ia];
        ipb = pt->v[ib];
	ca  = &mesh->point[ipa].c[0];
        cb  = &mesh->point[ipb].c[0];
        iadr = (ipa-1)*sol->offset + 1;
        ma  = &sol->met[iadr];
        iadr = (ipb-1)*sol->offset + 1;
        mb  = &sol->met[iadr];

        len = MMG_length(ca,cb,ma,mb);
        if(!mesh->info.noinsert && (len < LSHORT)) {
          pa  = &mesh->point[ipa];
          pb  = &mesh->point[ipb];
          if ( !(pb->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ia,ib,QDEGRAD) ) {
            ier = 3;
	    nd++;
            MMG_delPt(mesh,ipb);
            ds[ityp]++;
            break;
          } 
          else if( !(pa->tag & M_BDRY) && MMG_colpoi2(mesh,sol,k,ib,ia,QDEGRAD) ) {
            ier = 3;
	    nd++;
            MMG_delPt(mesh,ipa);
            ds[ityp]++;
            break; 
          }
        } else if(!mesh->info.noinsert && (len > LLONG)) {
          lon = MMG_coquil(mesh,k,i,&list);
          if ( lon <= 2 ) break;
          crit = pt->qual;
          for (l=2; l<=lon; l++) {
            iel = list.tetra[l] / 6;
            pt1 = &mesh->tetra[iel];
            if ( pt1->qual > crit )  crit = pt1->qual;
          }  
          crit *= OCRIT;
          if (!mesh->info.noinsert)
            ier = MMG_spledg(mesh,sol,queue,&list,lon,crit,declic);
          if ( ier > 0 ) {
             nd++;
            ds[ityp]++;
            break;
          }
	}
      }
      
      if(i<6) break;
      if(ier) break;
      /*MMG_swap arete*/
      for(i=0 ; i<6 ; i++) {
	lon = MMG_coquil(mesh,k,i,&list);
        if ( lon > 2 ) {
	  crit = pt->qual;
          for (l=2; l<=lon; l++) {
            iel = list.tetra[l] / 6;
            pt1 = &mesh->tetra[iel];
            if ( pt1->qual > crit )  crit = pt1->qual;
          }
          crit *= OCRIT;
          ier = MMG_swapar(mesh,sol,queue,&list,lon,crit,declic);
	  if(ier) {	    
            nd++;
            ds[ityp]++;
	    break;
	  }  
        }
      }
            
      break;
    default:
/*
      for (i=0; i<4; i++) {
        adj  = adja[i] >> 2;
        if ( adj && pt->ref == mesh->tetra[adj].ref ) {
          lon  = MMG_coquil(mesh,k,i,list);
          if ( MMG_swapar(mesh,sol,queue,k,i,list,lon,declic) ) {
            nsw++;
ds[ityp]++;
            break;
          }
        }
      }
*/
      break;
    }
     
  }
  while ( k && *alert == 0 );

  if(mesh->info.imprim<0) { 
	
    for (k=0; k<=7; k++)
      if ( cs[k] )
        printf("  optim [%d]      = %5d   %5d  %6.2f %%\n",k,cs[k],ds[k],100.0*ds[k]/cs[k]);

    sombdry = dsb[0]+dsb[1]+dsb[2];
    for (k=1; k<=2; k++)
      if ( dsb[k] )
        printf("\n  optim bdry [%d] = %5d   %5d  %6.2f %%\n",k,dsb[k],sombdry,100.0*dsb[k]/sombdry);
    
    printf(" PROP %d  TREATED %d\n",np,ds[0]+ds[1]+ds[2]+ds[3]+ds[4]+ds[5]+ds[6]+ds[7]);

  }

   M_free(list.hedg.item);
   MMG_kiufree(queue);
   
   if (!mesh->info.noswap) {
     base   = -1;
     *alert = 0;
     ndd     = MMG_cendel(mesh,sol,declic,base);
     if ( mesh->info.imprim < 0 && ndd > 0 )
       fprintf(stdout,"      %7d SWAPPED\n",ndd);
     else if ( ndd < 0 )
       *alert = 1;     
   }



 /* base  = -1;
  ier   = 0;
  queue = MMG_kiuini(mesh,mesh->nemax,declic,base);
  assert(queue);

  do {
    k = MMG_kiupop(queue);
    if ( !k )  break;
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    else if ( pt->qual < declic )  continue;
    
    crit = M_MIN(2.*pt->qual,8e+8);
    
    for (i=0; i<4; i++) {
      if(MMG_simu23(mesh,sol,k,i,crit)) {
      printf("je swap\n");
        MMG_swap23(mesh,sol,queue,k,i,1e+9);
        break;
      }
    }

  }
  while ( k && *alert == 0 );
  MMG_kiufree(queue);*/


  return(nd);
}


/* insert point in bad tetra */
int MMG_pretreat(pMesh mesh,pSol sol,double declic,int *alert) {
  pTetra     pt,pt1;
  List       list;
  pQueue     queue;
  double      crit;
  double     len,*ca,*cb,*ma,*mb;
  int        i,k,l,ia,ib,iel,ier,nd,base,wqual;
  int        lon,iadr,ipa,ipb;

  wqual = 30. / ALPHAD;

  /*queue*/
  base  = -1;
  queue = MMG_kiuini(mesh,mesh->nemax,declic,base);
  assert(queue);

  nd   = 0;

  if ( !MMG_zaldy4(&list.hedg,3*LONMAX) ) {
    fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM MMG_OPTTYP.\n");
    MMG_kiufree(queue);
    return(0);
  }

  do {
    k = MMG_kiupop(queue);
    if ( !k )  break;
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    else if ( pt->qual < declic )  continue;

    crit = pt->qual * OCRIT;

    for(i=0 ; i<6 ; i++) {
      ia   = MMG_iare[i][0];
      ib   = MMG_iare[i][1];
      ipa  = pt->v[ia];
      ipb  = pt->v[ib];
      ca   = &mesh->point[ipa].c[0];
      cb   = &mesh->point[ipb].c[0];
      iadr = (ipa-1)*sol->offset + 1;
      ma   = &sol->met[iadr];
      iadr = (ipb-1)*sol->offset + 1;
      mb   = &sol->met[iadr];

      len = MMG_length(ca,cb,ma,mb);
      
      if(!mesh->info.noinsert && (len > LLONG)) {
        lon = MMG_coquil(mesh,k,i,&list);
        if ( lon <= 2 ) break;
        crit = pt->qual;
        for (l=2; l<=lon; l++) {
          iel = list.tetra[l] / 6;
          pt1 = &mesh->tetra[iel];
          if ( pt1->qual > crit )  crit = pt1->qual;
        }
	/*if(crit > wqual) {  
          crit *= 2.;
	} else {
	  crit *= 1.05;
	}                          */
	crit = M_MIN(crit,8.e+8);  
	ier = 0;
        if (!mesh->info.noinsert)
          ier = MMG_spledg(mesh,sol,queue,&list,lon,crit,declic);
        if ( ier > 0 ) {
          nd++;
          break;
        }
      }
    }
  }  
  while ( k && *alert == 0 );

   M_free(list.hedg.item);
   MMG_kiufree(queue);

  return(nd);
}

