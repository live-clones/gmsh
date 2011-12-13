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
/*
mmg3dlib(int option, ): to use mmg3d via a library

option = 
  fprintf(stdout,"  1      adaptation\n");
  fprintf(stdout,"  9      moving mesh\n");
  fprintf(stdout," -n      turn off optimisation\n");

*/
#include "compil.date"
#include "mesh.h"
#include "eigenv.h"

TIM_mytime         MMG_ctim[TIMEMAX];
short	       MMG_imprim;

static void MMG_excfun(int sigid) {
  switch (sigid) {
  case SIGFPE:
    fprintf(stderr,"  ## FP EXCEPTION. STOP\n");
    break;
  case SIGILL:
    fprintf(stderr,"  ## ILLEGAL INSTRUCTION. STOP\n");
    break;
  case SIGSEGV:
    fprintf(stderr,"  ## SEGMENTATION FAULT. STOP\n");
    break;
  case SIGABRT:
  case SIGTERM:
  case SIGINT:
    fprintf(stderr,"  ## ABNORMAL END. STOP\n");
    break;
  }
  exit(1);
}

void MMG_endcod() {
  double   ttot,ttim[TIMEMAX];
  int      k,call[TIMEMAX];

  TIM_chrono(OFF,&MMG_ctim[0]);
  
  for (k=0; k<TIMEMAX; k++) {
    call[k] = MMG_ctim[k].call;
    ttim[k] = MMG_ctim[k].call ? TIM_gttime(MMG_ctim[k]) : 0.0;
  }
  ttot    = ttim[1]+ttim[2]+ttim[3]+ttim[4];
  ttim[0] = M_MAX(ttim[0],ttot);

  if ( abs(MMG_imprim) > 5 ) {
    fprintf(stdout,"\n  -- CPU REQUIREMENTS\n");
    fprintf(stdout,"  in/out    %8.2f %%    %3d. calls,   %7.2f sec/call\n",
	    100.*ttim[1]/ttim[0],call[1],ttim[1]/(float)call[1]);
    fprintf(stdout,"  analysis  %8.2f %%    %3d. calls,   %7.2f sec/call\n",
	    100.*ttim[2]/ttim[0],call[2],ttim[2]/(float)call[2]);
    fprintf(stdout,"  optim     %8.2f %%    %3d. calls,   %7.2f sec/call\n",
	    100.*ttim[3]/ttim[0],call[3],ttim[3]/(float)call[3]);
    fprintf(stdout,"  total     %8.2f %%    %3d. calls,   %7.2f sec/call\n",
	    100.*ttot/ttim[0],call[0],ttot/(float)call[0]);
  }
  fprintf(stdout,"\n   ELAPSED TIME  %.2f SEC.  (%.2f)\n",ttim[0],ttot);
}


int MMG_inputdata(pMesh mesh,pSol sol) {
  pPoint 	ppt;
  int		k;
  
  
  mesh->npfixe = mesh->np;
  mesh->ntfixe = mesh->nt;
  mesh->nefixe = mesh->ne;
  
  /* keep track of empty links */
  mesh->npnil = mesh->np + 1;
  mesh->nenil = mesh->ne + 1;
  for (k=mesh->npnil; k<mesh->npmax-1; k++)
    mesh->point[k].tmp  = k+1;
  for (k=mesh->nenil; k<mesh->nemax-1; k++)
    mesh->tetra[k].v[3] = k+1;
  if ( mesh->nt ) {
    mesh->ntnil = mesh->nt + 1;
    for (k=mesh->ntnil; k<mesh->ntmax-1; k++)
      mesh->tria[k].v[2] = k+1;
  }
  /*tag points*/
  for (k=1; k<=mesh->np; k++) {
      ppt = &mesh->point[k];
      ppt->tag  = M_UNUSED;
  }
 return(1);
}

int MMG_tassage(pMesh mesh,pSol sol) {
  pTetra	pt,ptnew;
  pTria		pt1;
  pPoint	ppt,pptnew;
  int 		np,k,ne,nbl,isol,isolnew,i;
  
  /*rebuild triangles*/
	MMG_markBdry(mesh);

  /* compact vertices */
  np=0;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;
    ppt->tmp = ++np;
  }
  
 
  /* compact triangles */
  for (k=1; k<=mesh->nt; k++) {
    pt1  = &mesh->tria[k];
    pt1->v[0] = mesh->point[pt1->v[0]].tmp;
    pt1->v[1] = mesh->point[pt1->v[1]].tmp;
    pt1->v[2] = mesh->point[pt1->v[2]].tmp;
  }
 
  /* compact tetrahedra */
  ne  = 0;
  nbl = 1;
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  {
      continue;
    }
		for(i=0 ; i<4 ; i++)
		  pt->bdryref[i] = -1;
    pt->v[0] = mesh->point[pt->v[0]].tmp;
    pt->v[1] = mesh->point[pt->v[1]].tmp;
    pt->v[2] = mesh->point[pt->v[2]].tmp;
    pt->v[3] = mesh->point[pt->v[3]].tmp; 
		ne++; 
			//     if(k!=nbl) {
			// printf("on voudrait tasser\n");
			//       ptnew = &mesh->tetra[nbl];
			//       memcpy(ptnew,pt,sizeof(Tetra));
			//       nbl++;
			//     }               
			// 
		// for(i=0 ; i<4 ; i++)
		//   ptnew->bdryref[i] = 0;
		//     if(k != nbl) {
		//       memset(pt,0,sizeof(Tetra));
		//       pt->qual = 0.0;
		//       pt->edge = 0; 
		//     }
		//     nbl++;
  }
  // mesh->ne = ne;
  
  /* compact metric */
  nbl = 1;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_UNUSED )  continue;
    isol    = (k-1) * sol->offset + 1;    
    isolnew = (nbl-1) * sol->offset + 1;
    
    for (i=0; i<sol->offset; i++)
      sol->met[isolnew + i] = sol->met[isol + i];
    ++nbl;
  }
  
   
  /*compact vertices*/
   np  = 0;
   nbl = 1;
   for (k=1; k<=mesh->np; k++) {
     ppt = &mesh->point[k];
     if ( ppt->tag & M_UNUSED )  continue;
     pptnew = &mesh->point[nbl];
     memcpy(pptnew,ppt,sizeof(Point));
     ppt->tag   &= ~M_UNUSED;
     assert(ppt->tmp == nbl);
     np++;
     if(k != nbl) {
       ppt = &mesh->point[k];
       memset(ppt,0,sizeof(Point));
       ppt->tag    = M_UNUSED;
     }
     nbl++;
   }
   mesh->np = np;
   sol->np  = np;
   
  for(k=1 ; k<=mesh->np ; k++)
    mesh->point[k].tmp = 0;
    
  mesh->npnil = mesh->np + 1;
  for (k=mesh->npnil; k<mesh->npmax-1; k++)
    mesh->point[k].tmp  = k+1;
  
  mesh->nenil = mesh->ne + 1;
  for (k=mesh->nenil; k<mesh->nemax-1; k++)
    mesh->tetra[k].v[3] = k+1;
 
  mesh->ntnil = mesh->nt + 1;
  for (k=mesh->ntnil; k<mesh->ntmax-1; k++)
    mesh->tria[k].v[2] = k+1;
  

  
 return(1);
}

int MMG_mmg3dlib(int opt[9],MMG_pMesh mesh,MMG_pSol sol) {
  int           alert;
  Info     	*info;
  short		imprim;
  int k,iadr,i,jj,kk,ii,im;
  double	lambda[3],v[3][3],*mold,*m;
  //fprintf(stdout,"  %s \n", M_STR);
  fprintf(stdout,"  -- START MMG3d (%d ELEMS)\n", mesh->ne) ;
  if (opt[6] < 0) fprintf(stdout,"  -- MMG3d, Release %s (%s) \n",M_VER,M_REL);
  if (opt[6] < -10) fprintf(stdout,"     Copyright (c) LJLL/IMB, 2010\n");
  if (opt[6] < -10) fprintf(stdout,"    %s\n",COMPIL);
  
  
  signal(SIGABRT,MMG_excfun);
  signal(SIGFPE,MMG_excfun);
  signal(SIGILL,MMG_excfun);
  signal(SIGSEGV,MMG_excfun);
  signal(SIGTERM,MMG_excfun);
  signal(SIGINT,MMG_excfun);
 /* atexit(MMG_endcod);
*/

  TIM_tminit(MMG_ctim,TIMEMAX);
  TIM_chrono(ON,&MMG_ctim[0]);
  TIM_chrono(OFF,&MMG_ctim[0]);
  /* default values */
  info = &mesh->info;

  info->imprim   = opt[6];
  info->memory   = 0;
  info->ddebug   = opt[1];
  info->option   = opt[0];
  info->bucksiz  = opt[2];
  info->noswap   = opt[3];
  info->nomove   = opt[5];
  info->noinsert = opt[4];
  info->rn2      = opt[7];//3;
  info->rn       = opt[8];//500;
  alert          = 0;
  info->dt       = 1.;
  info->bdry     = 0;

  imprim         = info->imprim;
  MMG_imprim   = imprim;
 
  if ( imprim )   fprintf(stdout,"\n  -- INPUT DATA\n");
  TIM_chrono(ON,&MMG_ctim[1]);
  MMG_inputdata(mesh,sol);
  if ( sol->np && sol->np != mesh->np ) {
    fprintf(stdout,"  ## WARNING: WRONG SOLUTION NUMBER. IGNORED\n");
    sol->np = 0;
  }
  /*read displacement*/
  if ( abs(info->option) == 9 && !mesh->disp)  {
    //M_free(mesh->adja);
    fprintf(stdout,"  ## WARNING: NO DISPLACEMENT. IGNORED\n");
    return(0);
  }  
  if ( !MMG_setfunc(sol->offset) ) return(1);
  if ( !MMG_scaleMesh(mesh,sol) )  return(1);
  TIM_chrono(OFF,&MMG_ctim[1]);
  if ( imprim < -10)
    fprintf(stdout,"  -- DATA READING COMPLETED.     %.2f sec.\n",
            TIM_gttime(MMG_ctim[1]));

  alert = MMG_outqua(mesh,sol);
  if(alert) {
    fprintf(stdout,"\n \n    ## INVALID MESH. STOP\n");
    exit(1);  
  }
  if(MMG_imprim < 0) MMG_outquacubic(mesh,sol);

  if (info->imprim  < -10){
    fprintf(stdout,"\n  %s\n   MODULE MMG3D-LJLL/IMB : %s (%s)  %s\n  \n",
	    M_STR,M_VER,M_REL,sol->offset == 1 ? "ISO" : "ANISO");
    fprintf(stdout,"  MAXIMUM NUMBER OF POINTS    (NPMAX) : %8d\n",mesh->npmax);
    fprintf(stdout,"  MAXIMUM NUMBER OF TRIANGLES (NTMAX) : %8d\n",mesh->ntmax);
    fprintf(stdout,"  MAXIMUM NUMBER OF ELEMENTS  (NEMAX) : %8d\n",mesh->nemax);
  }

  /* mesh analysis */
  TIM_chrono(ON,&MMG_ctim[2]);
  if ( MMG_imprim < 0 )   fprintf(stdout,"\n  -- PHASE 1 : ANALYSIS\n");
  if ( !MMG_hashTetra(mesh) )    return(1);
  if ( !MMG_markBdry(mesh) )     return(1);
  if (abs(mesh->info.option)==10) {
    MMG_saveMesh(mesh,"tetra.mesh");
    return(0);
  }           
  if ( !sol->np) {
    fprintf(stdout,"  WARNING NO METRIC FOUND %d\n",sol->np);    
    im = 1;
    if(!MMG_doSol(mesh,sol) ) return(1);
  } else
    im = 0;
    
  TIM_chrono(OFF,&MMG_ctim[2]);
  if ( MMG_imprim < 0 )
    fprintf(stdout,"  -- PHASE 1 COMPLETED.     %.2f sec.\n",
            TIM_gttime(MMG_ctim[2]));
  if ( info->ddebug )  MMG_chkmsh(mesh,1,1);
  
  if ( abs(MMG_imprim) > 4 )  {
	  MMG_prilen(mesh,sol);
    MMG_ratio(mesh,sol,NULL);        
  }                       

#ifdef USE_SCOTCH
  /* renumbering begin */
   if ( info->rn2 & 1 )  { 
     TIM_chrono(ON,&MMG_ctim[5]); 
     if ( MMG_imprim < -6)
       fprintf(stdout,"renumbering");
     renumbering(info->rn, mesh, sol);  
    
     if ( !MMG_hashTetra(mesh) )    return(1);    
     TIM_chrono(OFF,&MMG_ctim[5]); 
     if ( MMG_imprim < -6)
       fprintf(stdout,"  -- PHASE RENUMBERING COMPLETED.     %.2f sec.\n",
               TIM_gttime(MMG_ctim[5]));
     if ( info->ddebug ) MMG_chkmsh(mesh,1,0);
   }
   /* renumbering end */
#endif 

  /* mesh optimization */
  if ( info->option ) {
    TIM_chrono(ON,&MMG_ctim[3]);
    if ( MMG_imprim < 0 )   fprintf(stdout,"\n  -- PHASE 2 : UNIT MESH\n");
    if ( abs(info->option) == 9 ) {  
      if(!MMG_mmg3d9(mesh,sol,&alert)) {
        if ( !MMG_unscaleMesh(mesh,sol) )  return(1);
        MMG_saveMesh(mesh,"errormoving.mesh");
	      //MMG_saveSol(mesh,sol,mesh->outf);
	      return(1);
      }
      /*puts("appel 1");
      MMG_mmg3d1(mesh,sol,&alert);*/ 
      for (k=1; k<=mesh->np; k++) {
        iadr = (k-1)*sol->offset + 1;
        m    = &sol->met[iadr];      
        /*calcul du log de M*/
        if ( !eigenv(1,m,lambda,v) ) {
             puts("pbs eigen"); 
         return(0);
        }
        for (i=0; i<3; i++) lambda[i] = log(lambda[i]);
        mold    = &sol->metold[iadr]; 
        kk = 0;
      for (ii=0; ii<3; ii++) {
           for (jj=ii; jj<3; jj++) {
              mold[kk] = lambda[0]*v[0][ii]*v[0][jj] + 
                         lambda[1]*v[1][ii]*v[1][jj] +
                         lambda[2]*v[2][ii]*v[2][jj]; 
              kk = kk+1;
           }                     
         }
      }
    } 
    
    if(!info->noinsert) {
      if(abs(info->option) == 4){ 
        MMG_mmg3d4(mesh,sol,&alert);
      } else {
        MMG_mmg3d1(mesh,sol,&alert);
      }
    }
      
    TIM_chrono(OFF,&MMG_ctim[3]);
    if ( MMG_imprim < 0 )
      fprintf(stdout,"  -- PHASE 2 COMPLETED.     %.2f sec.\n",
              TIM_gttime(MMG_ctim[3]));
  }

  /* mesh regularisation */
  if ( info->option > -1 ) {
#ifdef USE_SCOTCH
    /* renumbering begin */
    /*MMG_chkmsh(mesh,0,-1); 
    puts("3er chk ok");
    */
    if ( info->rn2 & 2 )  { 
      TIM_chrono(ON,&MMG_ctim[6]); 
      if ( MMG_imprim < -6)
        fprintf(stdout,"renumbering"); 
			renumbering(info->rn, mesh, sol);
      if ( !MMG_hashTetra(mesh) )    return(1);    
      TIM_chrono(OFF,&MMG_ctim[6]); 
      if ( MMG_imprim < -6)
        fprintf(stdout,"  -- PHASE RENUMBERING COMPLETED.     %.2f sec.\n",
              TIM_gttime(MMG_ctim[6]));
      if ( info->ddebug ) MMG_chkmsh(mesh,1,0);
    } 
    /* renumbering end */   
#endif
    TIM_chrono(ON,&MMG_ctim[4]);
    if ( MMG_imprim < 0)  fprintf(stdout,"\n  -- PHASE 3 : OPTIMIZATION\n");
    if ( !alert )  {
      if ( info->option == 9 ) { 
         MMG_optra4(mesh,sol); 
      } else {
         MMG_optra4(mesh,sol); 
      }
    }
    
    if ( info->ddebug )  MMG_chkmsh(mesh,1,1);
    TIM_chrono(OFF,&MMG_ctim[4]);
    if ( MMG_imprim <  0)
      fprintf(stdout,"  -- PHASE 3 COMPLETED.     %.2f sec.\n",
              TIM_gttime(MMG_ctim[4]));
  }


  if ( info->option > -1 || abs(MMG_imprim) > 3 ) {
    MMG_outqua(mesh,sol);
    if(MMG_imprim < 0) MMG_outquacubic(mesh,sol);
    MMG_prilen(mesh,sol);
    MMG_ratio(mesh,sol,NULL);
  }
  fprintf(stdout,"  -- END MMG3D (%d ELEMS)\n", mesh->ne);
  if ( alert )
    fprintf(stdout,"\n  ## WARNING: INCOMPLETE MESH  %d , %d\n",
            mesh->np,mesh->ne);

  if ( MMG_imprim )  fprintf(stdout,"\n  -- SAVING DATA FILE \n");
  TIM_chrono(ON,&MMG_ctim[1]);
  if ( !MMG_unscaleMesh(mesh,sol) )  return(1);
  MMG_tassage(mesh,sol);
  
  TIM_chrono(OFF,&MMG_ctim[1]);
  if ( MMG_imprim ) {
    fprintf(stdout,"     NUMBER OF GIVEN VERTICES   %8d\n",mesh->npfixe);
    if ( mesh->ntfixe )
      fprintf(stdout,"     NUMBER OF GIVEN TRIANGLES  %8d\n",mesh->ntfixe);
    fprintf(stdout,"     NUMBER OF GIVEN ELEMENTS   %8d\n",mesh->nefixe);
    fprintf(stdout,"     TOTAL NUMBER OF VERTICES   %8d\n",mesh->np);
    fprintf(stdout,"     TOTAL NUMBER OF TRIANGLES  %8d\n",mesh->nt);
  }

  if ( MMG_imprim )  fprintf(stdout,"  -- SAVING COMPLETED\n");

  if ( MMG_imprim < -4 || info->ddebug )  M_memDump();

  return(alert);
}
