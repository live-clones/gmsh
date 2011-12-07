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

extern int MMG_nlen,MMG_ncal,MMG_ntopo,MMG_nex;

/*essaie d'enlever les tets ayant plus d'une face de peau pour faciliter le bouger*/
int MMG_optfacespeau(pMesh mesh,pSol sol) {
  double  	declic;
  pTetra	pt;
  pQueue    queue;
  int      	it,maxtou,i,iadr,*adja,npeau,nwtot,nw,k;
  
  declic = 1.7 / ALPHAD;
  maxtou = 10;
  it     = 0;

  do {
    queue = MMG_kiuini(mesh,mesh->nemax,declic,-1);
    assert(queue);
    nw    = 0;
    nwtot = 0;
    do {
      k = MMG_kiupop(queue);
      pt = &mesh->tetra[k];
      if ( !k )  break;
      if ( !pt->v[0] )  continue;
      iadr = 4*(k-1) + 1;
      adja = &mesh->adja[iadr];
      /*optim bdry tetra*/
      npeau = 0;
      for(i=0 ; i<4 ; i++) {
        if(!adja[i])npeau++;	 
      }
      if(npeau>1 ) {
        nwtot++;
        //if(mesh->info.imprim<0) printf("%d faces de peau!!!! %d %e\n",npeau,k,mesh->tetra[k].qual * ALPHAD);
	    nw += MMG_opt2peau(mesh,sol,queue,k,declic);
        continue;
      }    
    } 
    while (k);
    fprintf(stdout,"      %7d / %7d BDRY TETS\n",nw,nwtot);
    MMG_kiufree(queue);
  }
  while ( nw && ++it < maxtou );
 
 return(1);
}

/*collapse*/
int MMG_colps(pMesh mesh,pSol sol,int *nd) {
  pTetra    pt,pt1;
  pPoint    pa,pb;
  double    len,*ca,*cb,*ma,*mb;
  float     coef;
  int       i,k,l,jel,num,lon,ndd,npp,ia,ib,ipa,ipb,nedep,base;
  int      *adja,adj,iadr;
  List      list;
  char      tabar;

MMG_nlen = 0;
MMG_ncal = 0;
MMG_ntopo = 0;
MMG_nex = 0;

  npp = 0;
  ndd = 0;
  coef  = QDEGRAD;
  nedep = mesh->ne;
  base  = ++mesh->flag;
  /*Try collapse*/
  for (k=1; k<=nedep; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    else if ( pt->flag != base-1 )  continue;

    /* mark internal edges */
    tabar = 0;
    iadr  = 4*(k-1) + 1;
    adja  = &mesh->adja[iadr];
    for (i=0; i<4; i++) {
      adj = adja[i] >> 2;
      if ( !adj || pt->ref != mesh->tetra[adj].ref ) {
  	tabar |= 1 << MMG_iarf[i][0];
  	tabar |= 1 << MMG_iarf[i][1];
  	tabar |= 1 << MMG_iarf[i][2];
     }
    }
    if ( tabar == ALL_BDRY )  continue;

    /* internal edge */
    for (i=0; i<6; i++) {
      if ( tabar & 1<<i )  continue;
      else if ( pt->edge & 1 << i )  continue;

      /* edge length */
      ia  = MMG_iare[i][0];
      ib  = MMG_iare[i][1];
      ipa = pt->v[ia];
      ipb = pt->v[ib];
      pa  = &mesh->point[ipa];
      pb  = &mesh->point[ipb];
      ca  = &pa->c[0];
      cb  = &pb->c[0];
      iadr = (ipa-1)*sol->offset + 1;
      ma  = &sol->met[iadr];

      iadr = (ipb-1)*sol->offset + 1;
      mb  = &sol->met[iadr];
      
      /* coquille */
      lon = MMG_coquil(mesh,k,i,&list);
      for (l=1; l<=lon; l++) {
  	    jel = list.tetra[l] / 6;
  	    num = list.tetra[l] % 6;
  	    pt1 = &mesh->tetra[jel];
  	    pt1->edge |= 1 << num;
      }
      if ( lon < 3 )  continue;
      len = MMG_length(ca,cb,ma,mb);
  
      if ( len < LSHORT ) {
  	    npp++;
  	    pa = &mesh->point[ipa];
  	    pb = &mesh->point[ipb];
  	    if ( MMG_colpoi(mesh,sol,k,ia,ib,coef) ) {
  	      MMG_delPt(mesh,ipb);
  	      ndd++;
  	      break;
  	    }
  	    else if ( MMG_colpoi(mesh,sol,k,ib,ia,coef) ) {
  	      MMG_delPt(mesh,ipa);
  	      ndd++;
  	      break;
  	    }
      }
    }
  }

        *nd = ndd;
printf("analyzed %d \n",npp);
printf("rejected colpoi : cal %d  , len %d , topo %d , ex %d\n",MMG_ncal,MMG_nlen,MMG_ntopo,MMG_nex);

  if ( *nd > 0 && abs(mesh->info.imprim) > 2 )
    fprintf(stdout,"	%8d REMOVED  \n",*nd);

  return(1);

}


/* dichotomy: check if nodes can move */
int MMG_dikomv(pMesh mesh,pSol sol,short t) {
  pTetra    pt;
  pPoint    ppt;
  pDispl    pd;
  double    vol,c[4][3];
  double    alpha,coor[3];
  int       k,i,nm;
/*double hmax,*mp,h1,lambda[3],dd;  
int iadr;  
Info     *info;
*/
  pd = mesh->disp;

  alpha = (double)t / SHORT_MAX;
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    for (i=0; i<4; i++) {
      ppt      = &mesh->point[ pt->v[i] ];
      ppt->tmp = k;
      if ( ppt->tag & M_MOVE ) {
        c[i][0] = ppt->c[0] + alpha * pd->mv[3*(pt->v[i]-1) + 1 + 0];
        c[i][1] = ppt->c[1] + alpha * pd->mv[3*(pt->v[i]-1) + 1 + 1];
        c[i][2] = ppt->c[2] + alpha * pd->mv[3*(pt->v[i]-1) + 1 + 2];
      }
      else
        memcpy(c[i],ppt->c,3*sizeof(double));
    }

    vol = MMG_quickvol(c[0],c[1],c[2],c[3]);
    if ( vol < 1e-24/*EPS2*/ )  {
      if(mesh->info.imprim < 0) printf("vol reject %d %e %e\n",k,vol,pt->qual * ALPHAD);
      return(0);
    }
  }
  /* update metrics */
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if(ppt->tag & M_UNUSED) continue;
//#warning a mettre ou pas?    
    if(ppt->tag & M_BDRY) continue;
    if ( ppt->tag & M_MOVE ) {
      coor[0] = ppt->c[0] + alpha * pd->mv[3*(k-1) + 1 + 0];
      coor[1] = ppt->c[1] + alpha * pd->mv[3*(k-1) + 1 + 1];
      coor[2] = ppt->c[2] + alpha * pd->mv[3*(k-1) + 1 + 2];
if(MMG_computeMetric(mesh,sol,k,coor) == -1) ;//printf("point %d not found\n",k);
// /*pour mettre une metrique analytique*/
//       iadr = (k-1)*sol->offset + 1;
//       mp   = &sol->met[iadr];
//             
//       info = &mesh->info;
// 
//     /* normalize metrics */
//     dd = (double)PRECI / info->delta;
// 
//       hmax = 0.5;
//       h1 = hmax * fabs(1-exp(-fabs((coor[2] * 1./dd + info->min[2])+4))) + 0.008;
//       lambda[2]=1./(h1*h1);
//       lambda[1]=1./(hmax*hmax);
//       lambda[0]=1./(hmax*hmax);
//      dd = 1.0 / (dd*dd);
// 
//       mp[0]=dd*lambda[0];
//       mp[1]=0;
//       mp[3]=dd*lambda[1];
//       mp[2]=0;
//       mp[4]=0;
//       mp[5]=dd*lambda[2];
// /*fin metrique analytique*/      
   }
  }

  /* update point coords */
  nm = 0;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_MOVE ) {
      ppt->c[0] += alpha * pd->mv[3*(k-1) + 1 + 0];
      ppt->c[1] += alpha * pd->mv[3*(k-1) + 1 + 1];
      ppt->c[2] += alpha * pd->mv[3*(k-1) + 1 + 2];
      pd->alpha[k]  = t;
      if ( t == SHORT_MAX )  ppt->tag &= ~M_MOVE;
      nm++;
    }
  }

  if ( mesh->info.imprim < 0 )  fprintf(stdout,"     %7d NODES UPDATED\n",nm);
  return(nm);
}


/* check if displacement ok */
int MMG_chkmov(pMesh mesh,char level) {
  pTetra     pt;
  pPoint     ppt;
  pDispl     pd;
  double     vol;
  int        k,nc;

  pd  = mesh->disp;

  nc = 0;
  for (k=1; k<=mesh->np; k++) {
    ppt = &mesh->point[k];
    if ( ppt->tag & M_MOVE ) {
      if ( pd->alpha[k] < SHORT_MAX )  return(0);
      ppt->tag &= ~M_MOVE;
      nc++;
    }
  }

  /* check element validity */
  if ( level > 0 ) {
    for (k=1 ; k<=mesh->ne; k++) {
      pt = &mesh->tetra[k];
      if ( !pt->v[0] )  continue;
      vol = MMG_voltet(mesh,k);
      if ( vol < 0.0 )  return(0);
    }
  }

  return(1);
}

int MMG_optra9(pMesh mesh,pSol sol) {
  double	declicw;
  double	declic;
  int		base,nm,ns,it,maxtou,alert,nw,k;
  
  /* optim coquil */
  alert  = 0;
  maxtou = 10;
  it     = 0;
    
  for (k=1; k<=mesh->ne; k++) mesh->tetra[k].flag = mesh->flag;
  for (k=1; k<=mesh->np; k++) mesh->point[k].flag = mesh->flag;
 
  declicw = 5./ALPHAD;
  declic  = 1.1 / ALPHAD;//1.1 pour mmg3d

  do {
    for (k=1; k<=mesh->ne; k++) mesh->tetra[k].flag = mesh->flag;
    for (k=1; k<=mesh->np; k++) mesh->point[k].flag = mesh->flag;
    base = ++mesh->flag;
    
    ns = 0;
    if ( !alert && !mesh->info.noswap ) {
      ns = MMG_cendel(mesh,sol,declic,base);
      if ( ns < 0 ) {
        alert = 1;
    	ns    = -ns;
      }
    }
    nw = 0;
    /*if (!mesh->info.noinsert)  nw = MMG_pretreat(mesh,sol,declicw,&alert);
    */
    /*sur des surfaces courbes, il existe des tetras ayant  4 points de peau avec Q=3*/  
    if (1/*!mesh->info.noswap*/ /*&& (it < 10)*/ )  {
	  nw += MMG_opttyp(mesh,sol,declicw,&alert);   
    }

    nm = MMG_optlen(mesh,sol,declic,base);  
//    if(abs(mesh->info.option)!=9 || !mesh->disp) if(it<2) MMG_optlap(mesh,sol);
    
    if ( mesh->info.imprim< -4 && nw+ns+nm )
      fprintf(stdout,"     %8d IMPROVED  %8d SWAPPED  %8d MOVED\n",nw,ns,nm);
  }
  while ( ns+nm/*(ns && (ns > 0.005*mesh->ne || it < 5))*/ && ++it < maxtou );
 
  return(1);
}


int MMG_mmg3d9(pMesh mesh,pSol sol,int *alert) {   
  pPoint    ppt;
  pTetra   pt;
  double   declic;
  double    *m,*mold,qworst;
  int      k,nm,iter,maxiter;
  int      base,nnd,nns,sit,maxtou,ns,iadr,iold;
  short    t,i,it,alpha;
  
  if ( abs(mesh->info.imprim) > 3 )
    fprintf(stdout,"  ** MOVING MESH\n");
  
  /*alloc et init metold*/
  sol->metold = (double*)M_calloc(sol->npmax+1,sol->offset*sizeof(double),"MMG_mmg3d9");
  assert(sol->metold);
  mesh->disp->cold = (double*)M_calloc(3*(mesh->npmax + 1),sizeof(double),"MMG_mmg3d9");
  assert(mesh->disp->cold);
  for (k=1; k<=mesh->np; k++) {
     ppt = &mesh->point[k];
	 if ( ppt->tag & M_UNUSED ) continue;
     mesh->disp->cold[3*(k-1) + 1 + 0] = ppt->c[0];
     mesh->disp->cold[3*(k-1) + 1 + 1] = ppt->c[1];
     mesh->disp->cold[3*(k-1) + 1 + 2] = ppt->c[2];
   }
  
  switch (sol->offset) {
  case 1:
    for (k=1; k<=sol->np; k++)  {
      sol->metold[k] = sol->met[k];
    }
    break;

  case 6:
    for (k=1; k<=mesh->np; k++) {
      iadr = (k-1)*sol->offset + 1;
      m    = &sol->met[iadr];
      mold = &sol->metold[iadr];
      for (i=0; i<sol->offset; i++)  mold[i] = m[i];
    }
    break;
  default:
    fprintf(stderr,"  ## SPECIFIC DATA NOT USED.\n");
    exit(2);
  }

  
  /* move grid nodes */
  t       = SHORT_MAX;
  alpha   = 0;
  iter    = 0;
  maxiter = 200;
  declic  = 1.1/ALPHAD;
  iold    = 1;
  
  /* move grid nodes */
  t = SHORT_MAX;
  if (  MMG_dikomv(mesh,sol,t) ) {
    if ( mesh->info.imprim )  fprintf(stdout,"     %7d NODES MOVED\n",mesh->np);
  }
  else {
    fprintf(stdout,"     TRYING DICHO\n");
    while (alpha < SHORT_MAX && iter < maxiter) {
      t = SHORT_MAX - alpha;
      i = 0;
      do {
        nm = MMG_dikomv(mesh,sol,t);
        if ( nm )  {
	      alpha += t;
	      break;
	    } 
	    t = t >> 1;     
      } while (i++ < 10);
  
      /*si pas de mouvement 2 iter de suite stop*/
      if ( (i==11) && (iold==11)) {
        fprintf(stdout,"  NO MOVEMENT ## UNCOMPLETE DISPLACEMENT\n");
        return(0);
       }
       iold = i;
       /* update quality */
	   qworst = 0.;
       for (k=1; k<=mesh->ne; k++) {
         pt = &mesh->tetra[k];
		 if ( !pt->v[0] ) continue;
         pt->qual = MMG_caltet(mesh,sol,k);
		 qworst = M_MAX(qworst,pt->qual);
       }
      
     
      if ( mesh->info.imprim && nm )
        fprintf(stdout,"     %7d NODES MOVED\n",nm);

      printf("%%%% ITER %d alpha (%d) %d < %d\n",iter,i,alpha,SHORT_MAX);
            
      if ( i>1 ) {
        fprintf(stdout,"     CAN'T MOVED\n");
        if(!mesh->info.noswap) MMG_optfacespeau(mesh,sol);
        nnd = 0;
        nns = 0;
        sit = 0;
        maxtou = 10;
        do {
          it   = 0;
          base = mesh->flag;
		  ns   = 0;//MMG_cendel(mesh,sol,declic,base);
          if(!mesh->info.noswap) MMG_optfacespeau(mesh,sol);
          if ( ns < 0 ) {
            *alert = 1;
            ns     = -ns;
          }
          nns += ns;
          if ( ns && abs(mesh->info.imprim) > 4 )
            fprintf(stdout,"      %7d SWAPPED\n",ns);
        }
        while ( ns && ++sit < maxtou );

        if ( nnd+nns && abs(mesh->info.imprim) < 3 ) {
          fprintf(stdout,"     %7d REMOVED  %7d SWAPPED\n",nnd,nns);
        }
      }
      
      if ( qworst < 10./ALPHAD ) { 
        MMG_optra4(mesh,sol);
      } else {
		MMG_optra9(mesh,sol);
      }
      if(!mesh->info.noswap) MMG_optfacespeau(mesh,sol);
      MMG_outqua(mesh,sol);
      iter++;

    }

    /* check mesh */
    if ( iter==maxiter && !MMG_chkmov(mesh,1) ) {
      fprintf(stdout,"  ## UNCOMPLETE DISPLACEMENT\n");
      return(0);
    }
  }
  
  if(!mesh->info.noswap) MMG_optfacespeau(mesh,sol);

  /* update quality */
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( pt->v[0] )
      pt->qual = MMG_caltet(mesh,sol,k);
  }

  if ( mesh->info.imprim < 0 ) {
    MMG_outqua(mesh,sol);
    MMG_prilen(mesh,sol);
  }
  
 // M_free(sol->metold);
/*  M_free(mesh->disp);
  mesh->disp = 0;
  */return(1);
}

