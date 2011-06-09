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

#define EPS4  1.e-04

extern int MMG_npuiss,MMG_nvol,MMG_npres;
extern int MMG_nlen,MMG_ncal,MMG_ntopo,MMG_nex;
extern int MMG_npuisstot,MMG_nvoltot,MMG_nprestot;
extern int MMG_npdtot;
       int MMG_nplen,MMG_npref,MMG_bouffe;

int MMG_interp_ani(double *ma,double *mb,double *mp,double t) {
  double	dma[6],dmb[6],mai[6],mbi[6],mi[6];
  int		i;

  for (i=0; i<6; i++) {
    dma[i] = ma[i];
    dmb[i] = mb[i];
  }
  if ( !MMG_invmat(dma,mai) || !MMG_invmat(dmb,mbi) ) {
    fprintf(stderr,"  ## INTERP INVALID METRIC.\n");
    return(0);
  }
  for (i=0; i<6; i++)
    mi[i] = (1.0-t)*mai[i] + t*mbi[i];
    
  if ( !MMG_invmat(mi,mai) ) {
    fprintf(stderr,"  ## INTERP INVALID METRIC.\n");
    return(0);
  } 
  
  for (i=0; i<6; i++)  mp[i] = mai[i];

  return(1);
}

int MMG_interplog(double *ma,double *mb,double *mp,double *mplog,double t) {
  double	dma[6],dmb[6],mai[6],mi[6];
  int		i,ii,jj,kk;
  double	lambda[3],v[3][3];

  for (i=0; i<6; i++) {
    dma[i] = ma[i];
    dmb[i] = mb[i];
  }
  
  for (i=0; i<6; i++)
    mi[i] = (1.0-t)*dma[i] + t*dmb[i];
  
  /*pour metrique log : extraction vp et exponentielle*/
  if ( !eigenv(1,mi,lambda,v) ) {
	     puts("pbs eigen interp"); 
	     return(0);
   }
   for (i=0; i<3; i++) lambda[i] = exp(lambda[i]);
   kk = 0;
   for (ii=0; ii<3; ii++) {
     for (jj=ii; jj<3; jj++) {
       mai[kk] = lambda[0]*v[0][ii]*v[0][jj] + 
	             lambda[1]*v[1][ii]*v[1][jj] +
                 lambda[2]*v[2][ii]*v[2][jj]; 
       kk = kk+1;
    }                     
  }
  
  /*if ( !MMG_invmat(mi,mai) ) {
    fprintf(stderr,"  ## INTERP INVALID METRIC.\n");
    return(0);
  } */
  
  for (i=0; i<6; i++)  mplog[i] = mi[i];  
  for (i=0; i<6; i++)  mp[i] = mai[i];

  return(1);
}
int MMG_interp_iso(double *ma,double *mb,double *mp,double t) {

  *mp = (1.0-t)*(*ma) + t*(*mb);
  return(1);
}
//#define LLONG 1.1
//#define LSHORT 0.9                          
/* optimisation based on edge lengths */
int MMG_analar(pMesh mesh,pSol sol,pBucket bucket,int *na,int *nd,int *nf,int *alert) {
  pTetra	pt;
  pPoint	pa,pb;
  List		list;
  double	len,coef,siz,t1,declic,*ma,*mb,*mip,*ca,*cb,mp[6],c[3]; 
  //double  *malog,*mblog,mplog[6];
  int		  i,k,lon,nad,ndd,npp,npd,ia,ib,ip,ipa,ipb,nedep,base,ifilt;
  int		  *adja,adj,ret,vois[4],ref,tag,iadr,j,imax;
  char		tabar,tagedg;
  int     MMG_ncavity;
    
  /* for Delaunay cavity */
  if ( !MMG_zaldy4(&list.hedg,3*LONMAX) ) {
    fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM.\n");
    return(0);
  }

MMG_npuiss=0;
MMG_npres=0;
MMG_nvol=0;    
MMG_ncavity=0;
MMG_nplen=0;
MMG_npref=0;
MMG_nlen = 0;
MMG_ncal = 0;
MMG_ntopo = 0;
MMG_nex = 0;
MMG_bouffe = 0;

  npp = 0;
  nad = 0;
  ndd = 0;
  npd = 0;
  coef  = QDEGRAD;//1.;//QDEGRAD;
  ifilt = 0;
  nedep = mesh->ne;
  base  = ++mesh->flag;

  declic = 1.5/ALPHAD;// 60.*LLONG;
  
  for (k=1; k<=nedep; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    else if ( pt->flag != base-1 )  continue; 
    if ( pt->qual < declic ) continue;
    pt->flag = base-2;                
        
    /* mark internal edges */
    tabar  = 0;
    tagedg = 0;
    iadr  = 4*(k-1) + 1;
    adja  = &mesh->adja[iadr];
    vois[0]  = adja[0] >> 2;
    vois[1]  = adja[1] >> 2;
    vois[2]  = adja[2] >> 2;
    vois[3]  = adja[3] >> 2;
    for (i=0; i<4; i++) {
      adj    = vois[i];
      ref    = mesh->tetra[adj].ref;
      tag    = mesh->tetra[adj].flag;
      if ( !adj || pt->ref != ref ) {
        tabar |= 1 << MMG_iarf[i][0];
        tabar |= 1 << MMG_iarf[i][1];
        tabar |= 1 << MMG_iarf[i][2];
      }
      if ( adj && tag == base - 2 ) {
        tagedg |= 1 << MMG_iarf[i][0];
        tagedg |= 1 << MMG_iarf[i][1];
        tagedg |= 1 << MMG_iarf[i][2];
      }
      
    }
    if ( (tabar == ALL_BDRY) || (tagedg == ALL_BDRY) )  continue;
    
    //imax = ((int) pt->qual)%6;
    imax = 0;
    
    for (j=imax; j<imax+6; j++) {
      i = j;
      if ( (tabar & 1<<i) || (tagedg & 1<<i) )  continue;
        
        /* edge length */
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
        
        if ( len > LLONG && *alert != 1 ) {
          npp++;
        
          siz=0.5;

          /* metric interpolation */
          if ( sol->offset==1 ) {   
            if(!MMG_interp(ma,mb,mp,siz) ) continue;
          }    
          else {
            iadr = (ipa-1)*sol->offset + 1;
            //malog  = &sol->metold[iadr];
          
            iadr = (ipb-1)*sol->offset + 1;
            //mblog  = &sol->metold[iadr];
            //if ( !MMG_interplog(malog,mblog,mp,mplog,siz) ) continue; 
            if ( !MMG_interp_ani(ma,mb,mp,siz) ) continue;      
          }
          
          t1   = 1.0 - siz;
          c[0] = t1*ca[0] +  siz*cb[0];
          c[1] = t1*ca[1] +  siz*cb[1];
          c[2] = t1*ca[2] +  siz*cb[2]; 
          //printf("siz %e new len %e - %e (%e) %d %d\n", siz,MMG_length(ca,c,ma,mb),MMG_length(cb,c,ma,mb),len,(int)(len+0.5),nbp);
          ip   = MMG_newPt(mesh,c);
          if ( ip < 1 )  {
    	    *alert = 1;
            break;
          }
    	    else {
            iadr = (ip-1)*sol->offset + 1;
            //mipold  = &sol->metold[iadr];	  
    	      //memcpy(mipold,mplog,sol->offset*sizeof(double));
            mip  = &sol->met[iadr];	  
    	      memcpy(mip,mp,sol->offset*sizeof(double));
            
            /* bucket filter */
            if (!MMG_buckin(mesh,sol,bucket,ip) ) {
              MMG_delPt(mesh,ip);
              ifilt++;
              continue;
            }
            
    	      /* Delaunay kernel */
            lon = MMG_coquil(mesh,k,i,&list);    
            lon = MMG_cavity(mesh,sol,k,ip,&list,lon);
            if ( lon < 1 ) {
              MMG_delPt(mesh,ip);    
    	        npd++;
              if ( lon == -1 ) {  
                MMG_ncavity++;                
    				    //printf("cavity pete\n");
                *alert = 2;
              } else if ( lon < 0 ) {
    	          *alert = 1;
    	          break;
    	        }
              else {  	      
    	          continue;
    	        }
    	      }
    	      else {
    	        ret = MMG_delone(mesh,sol,ip,&list,lon);
    	        if ( ret > 0 ) {
                MMG_addBucket(mesh,bucket,ip);
                nad++;
    	          *alert = 0;
              }
              else if ( ret == 0 ) {
    	          MMG_delPt(mesh,ip);
    	          npd++;
                *alert = 1;
                break;
              }
    	        else {
    	          MMG_delPt(mesh,ip);
    	          npd++;
    	          MMG_bouffe++;
    	        }
    	      } 
          }
    	    break;
        }

        else if ( len < LSHORT ) {
          npp++;
    	    pa = &mesh->point[ipa];
    	    pb = &mesh->point[ipb];
    	    if ( MMG_colpoi(mesh,sol,k,ia,ib,coef) ) {
    	      MMG_delBucket(mesh,bucket,ipb);
            MMG_delPt(mesh,ipb);
            ndd++; 
    	      break;
    	    }
    	    else if ( MMG_colpoi(mesh,sol,k,ib,ia,coef) ) {
    	      MMG_delBucket(mesh,bucket,ipa);
            MMG_delPt(mesh,ipa);
    	      ndd++;            
    	      break;
    	    } 
        } 
      }
      if ( *alert == 1 )  break;
    }

  *na  = nad;
  *nd  = ndd;
  *nf += ifilt;
  if ( abs(mesh->info.imprim) > 5 || mesh->info.ddebug ) {  
    printf("analyzed %d \n",npp);
    printf("rejected colpoi : cal %d  , len %d , topo %d , ex %d\n",MMG_ncal,MMG_nlen,MMG_ntopo,MMG_nex);
    MMG_npdtot+=npd;
    MMG_nvoltot+=MMG_nvol;
    MMG_npuisstot+=MMG_npuiss;
    MMG_nprestot+=MMG_npres;
    if (npd>0) {
      printf("rejected %d : cavity %d vol %d  , puiss %d , pres %d  bouffe %d\n",npd,MMG_ncavity,MMG_nvol,MMG_npuiss,MMG_npres,MMG_bouffe);
    }
  }

  if ( *alert == 1 ) {
    fprintf(stdout,"  ## UNABLE TO CREATE NEW ELEMENT %d , %d\n",
            mesh->np,mesh->ne);
  } else *alert = 0;
  M_free(list.hedg.item);
  return(1);
}


