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

int MMG_npuiss,MMG_nvol,MMG_npres;
int MMG_nlen,MMG_ncal,MMG_ntopo,MMG_nex;
int MMG_npuisstot,MMG_nvoltot,MMG_nprestot;
int MMG_npdtot;
int MMG_nplen,MMG_npref,MMG_bouffe;

int ddebug;

int MMG_mmg3d4(pMesh mesh,pSol sol,int *alert) {
  Hedge    hash;
  pBucket	 bucket; 
  double   declic;
  int		   base,na,nd,ns,nna,nnd,nns,dd,it,nf,maxtou; 
  double   lmoy,LLLONG;
  if ( abs(mesh->info.imprim) > 3 )
    fprintf(stdout,"  ** SIZE OPTIMIZATION\n");
  if ( mesh->info.imprim < 0 ) {
    MMG_outqua(mesh,sol);
    MMG_prilen(mesh,sol);
  }

  base   = mesh->flag;
  *alert = 0;
  maxtou = 10;
  nna = nns = nnd = 0;
  it  = 0;
  declic = 3. / ALPHAD;  
  lmoy = 10.;
  LLLONG = 1.5;
  
  nna = 10;
  do { 
    na  = nd  = ns  = 0; 
    if(0) ddebug = 1;
    else ddebug = 0;
    
    if(!(it%2) ) {
      bucket = MMG_newBucket(mesh,M_MAX(mesh->info.bucksiz,BUCKSIZ));
      if ( !bucket )  return(0);
      
      MMG_analar(mesh,sol,bucket,&na,&nd,&nf,alert);      
      if ( abs(mesh->info.imprim) > 5 ) 
        fprintf(stdout,"     %7d INSERTED  %7d REMOVED   %7d FILTERED\n",na,nd,nf);  

	    M_free(bucket->head);
	    M_free(bucket->link);
	    M_free(bucket);
        
    } else {
        ++mesh->flag;
    }
    //printf("IT %d $$$$$$$$$$$ LLLONG  %9.3f\n",it,LLLONG); 
    nna = nns = nnd = 0; 
      
    /*splitting*/
    if ( !mesh->info.noinsert && (!*alert)  ) {
      /* store points on edges */
      if ( !MMG_zaldy4(&hash,mesh->np) ) {
        if ( mesh->info.ddebug )  fprintf(stdout,"  ## MEMORY ALLOCATION PROBLEM.\n"); 
        *alert = 2;
        break;
      }
          
      nna = MMG_analarcutting(mesh,sol,&hash,alert,&lmoy,LLLONG); 
      if ( abs(mesh->info.imprim) > 5 ) { printf("lmoy %9.5f\n",lmoy); }
      /*puts("--------------------------------------");
      puts("--------------------------------------");
      puts("--------------------------------------");
      */
      if ( *alert ) {
        fprintf(stdout," \n\n ** UNABLE TO CUT (analarcutting)\n");
        fprintf(stdout," ** RETRY WITH -m > %6d \n\n",mesh->info.memory);
        MMG_saveMesh(mesh,"crash.meshb");
        MMG_saveSol(mesh,sol,"crash.solb"); 
        exit(0);
      }
      M_free(hash.item);        
    }
    else if ( *alert )  nna = 0;  
    /* adjacencies */ 
    if ( nna /*|| it == (maxtou-1)*/ ) {
      mesh->nt = 0;
      if ( !MMG_hashTetra(mesh) )  return(0);
      if ( !MMG_markBdry(mesh) )   return(0);
    }
    // printf("chkmsh\n");
    // MMG_saveMesh(mesh,"chk.mesh");
    //MMG_chkmsh(mesh,1,-1);
		//if(it==1)exit(0);		
     /* delaunization */
    if ( !mesh->info.noswap && (nna || na) ) {  
      nns   =  MMG_cendel(mesh,sol,declic,base);
    }

    /* deletion */
    /*if ( 0 && nna ) {
      nnd   = MMG_colvert(mesh,sol,base);
    } */
    if ( nna+nnd+nns && abs(mesh->info.imprim) > 3 )
      fprintf(stdout,"     %7d INSERTED  %7d REMOVED   %7d FLIPPED\n",nna+na,nnd+nd,nns);
    
  }
  while ( na+nd+nns+nna+nnd > 0 && ++it < maxtou && lmoy > 1.3);

  if ( nna+nnd+nns && abs(mesh->info.imprim) < 4 ) {
    fprintf(stdout,"     %7d INSERTED  %7d REMOVED %7d FLIPPED\n",nna,nnd,nns);
  }

  if ( mesh->info.imprim < 0 ) {
    MMG_outqua(mesh,sol);
    MMG_prilen(mesh,sol);
  }

	//return(1);
	//MMG_saveMesh(mesh,"aprescut.mesh");
	fprintf(stdout,"    ---\n");
  
  /*analyze standard*/
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

    do {
      MMG_analar(mesh,sol,bucket,&na,&nd,&nf,alert);    
      nna += na;
      nnd += nd;
      if ( *alert ) {
        if ( nd < 1000 )  break;
        else  *alert = 0;
      }
      if ( it > 5 ) {
        dd = abs(nd-na);
        if ( dd < 5 || dd < 0.05*nd )   break;
        else if ( it > 12 && nd >= na )  break;
      }
      if ( na+nd && abs(mesh->info.imprim) > 3 )
        fprintf(stdout,"     %7d INSERTED  %7d REMOVED   %7d FILTERED\n",na,nd,nf);    
			// MMG_saveMesh(mesh,"chk.mesh");
			// //if(it==1) exit(0);
    }
    while ( na+nd > 0 && ++it < maxtou );

    if ( nna+nnd && abs(mesh->info.imprim) < 3 ) {
      fprintf(stdout,"     %7d INSERTED  %7d REMOVED  %7d FILTERED\n",na,nd,nf);
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
