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

extern TIM_mytime         MMG_ctim[TIMEMAX];

int MMG_npdtot,MMG_npuisstot,MMG_nvoltot,MMG_nprestot;
int MMG_npuiss,MMG_nvol,MMG_npres,MMG_npd;

int MMG_cendellong(pMesh mesh,pSol sol,double declic,int base);

int MMG_mmg3d1(pMesh mesh,pSol sol,int *alert) {
  pBucket	bucket;
  int		base,na,nd,nf,nna,nnd,dd,it,maxtou;
  int   naold,ndold;
//double q,declicw;
//pTetra pt;      
//int  nw;

  if ( abs(mesh->info.imprim) > 3 )
    fprintf(stdout,"  ** SIZE OPTIMIZATION\n");
  if ( mesh->info.imprim < 0 ) {
    MMG_outqua(mesh,sol);
    MMG_prilen(mesh,sol);
  }

  base   = mesh->flag;
  *alert = 0;

  nna = 0;
  nnd = 0;
  nf  = 0;
  it  = 0;
  maxtou = 100;
MMG_npdtot=0;
MMG_npuisstot=0;
MMG_nprestot=0;
MMG_nvoltot=0;

  /* 2. field points */
  if ( mesh->info.imprim < -4 ) {
    MMG_prilen(mesh,sol);
    fprintf(stdout,"  -- FIELD POINTS\n");
  }
  /* create filter */
  bucket = MMG_newBucket(mesh,M_MAX(mesh->info.bucksiz,BUCKSIZ));
  if ( !bucket )  return(0);
  
  naold = ndold = 0;
  do {
    base = mesh->flag;
    nf   = 0;
        
    MMG_analar(mesh,sol,bucket,&na,&nd,&nf,alert);    
    nna += na;
    nnd += nd;

    if ( *alert ) {
      if ( nd < 1000 )  break;
      else  *alert = 0;
    }
    
    /*test avec comme critere de qualite les longueurs*/
    /*if( it < 7 && !(it%3) ) {
      ns = 0; 
      declic = 120.; //attention c'est 60*len  
      if ( !*alert && !mesh->info.noswap ) {
          declicw = 180.;  
          nw += MMG_opttyp(mesh,sol,declicw,&alert);
          ns = MMG_cendellong(mesh,sol,declic,-1);
        if ( ns < 0 ) {
          *alert = 1;
      	  ns    = -ns;
        }
      }
      if ( mesh->info.imprim && ns )
        fprintf(stdout,"     %8d SWAPPED\n",ns);    
      //puts("on arrete la");exit(0); 
    }
    
    if( it > 5 ) {
      
      
      //printf("on traite moins 1%% : %d %d %e\n",na,nd,(na+nd)/(double)mesh->np); 
      //printf("delold/ins %e %e\n",ndold / (double) (na+1),naold / (double) (nd+1));
      
      if( it > 10 ) {
        q = ndold / (double) (na+1);
        if( q < 1.7 && q > 0.57) {
          break;
        }
        q = naold / (double) (nd+1);
        if( q < 1.7 && q > 0.57) {
          break;
        }        
      }
      q = ndold / (double) (na+1);
      if( q < 1.1 && q > 0.9) {
        break;
      }
      q = naold / (double) (nd+1);
      if( q < 1.1 && q > 0.9) {
        break;
      }
    }
    naold = na;
    ndold = nd;
    */
    
    if ( it > 5 ) {
      dd = abs(nd-na);
      if ( dd < 5 || dd < 0.05*nd )   break;
      else if ( it > 12 && nd >= na )  break;
    }
    if ( na + nd > 0 && abs(mesh->info.imprim) > 2 )
      fprintf(stdout,"     %8d INSERTED   %8d REMOVED   %8d FILTERED\n",
              na,nd,nf);
    }
    while ( na+nd > 0 && ++it < maxtou );


  if ( nna+nnd && abs(mesh->info.imprim) < 3 ) {
    fprintf(stdout,"     %7d INSERTED  %7d REMOVED  %7d FILTERED\n",nna,nnd,nf);
  }

if(MMG_npdtot>0) { 
fprintf(stdout,"    REJECTED : %5d\n",MMG_npdtot);
fprintf(stdout,"          VOL      : %6.2f %%    %5d \n",
	100*(MMG_nvoltot/(float)
MMG_npdtot),MMG_nvoltot); 
fprintf(stdout,"          PUISS    : %6.2f %%    %5d \n",
	100*(MMG_npuisstot/(float) MMG_npdtot),MMG_npuisstot);
fprintf(stdout,"         PROCHE    : %6.2f %%    %5d \n",
	100*(MMG_nprestot/(float) MMG_npuisstot),MMG_nprestot);	
MMG_npdtot=0;
MMG_npuisstot=0;
MMG_nvoltot=0;  
} 
  if ( mesh->info.imprim < 0 ) {
    MMG_outqua(mesh,sol);
    MMG_prilen(mesh,sol);
  }

  M_free(bucket->head);
  M_free(bucket->link);
  M_free(bucket);

  return(1);
}
