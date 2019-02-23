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

#define KA     31
#define KB     57
#define KC     79

#define KTA     7
#define KTB    11
#define KTC    13



/* local data structures */
typedef struct {
  int      min,max,sum,iel,nxt;
} hface;

typedef struct {
  int      size,hnxt,nhmax;
  hface   *item;
} Hface;


int MMG_hashTetra(pMesh mesh) {
  pTetra    pt,pt1;
  int       k,kk,pp,l,ll,mins,mins1,maxs,maxs1,sum,sum1,iadr;
  int      *hcode,*link,hsize;  
  long int  inival;
  unsigned char  i,ii,i1,i2,i3;
  unsigned int    key;

  /* default */
  if ( abs(mesh->info.imprim) > 5 ) {
    fprintf(stdout,"  ** SETTING ADJACENCIES\n");
    fflush(stdout);
  }
  /* memory alloc */
  hcode = (int*)M_calloc(mesh->nemax+1,sizeof(int),"hash");
  assert(hcode);
  link  = mesh->adja;
  hsize = mesh->ne;

  /* init */
  inival = 2147483647;
  for (k=0; k<=mesh->ne; k++)
    hcode[k] = -inival;
  /* build hash table */
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    for (i=0; i<4; i++) {
      i1 = MMG_idir[i][0];
      i2 = MMG_idir[i][1];
      i3 = MMG_idir[i][2];
      mins = M_MIN(pt->v[i1],pt->v[i2]);
      mins = M_MIN(mins,pt->v[i3]);
      maxs = M_MAX(pt->v[i1],pt->v[i2]);
      maxs = M_MAX(maxs,pt->v[i3]);

      /* compute key */
      sum = pt->v[i1] + pt->v[i2] + pt->v[i3];
      key = KA*mins + KB*maxs + KC*sum;
      key = key % hsize + 1;

      /* insert */
      iadr = 4*(k-1) + i+1;      
      link[iadr] = hcode[key];
      hcode[key] = -iadr;
    }
  }

  /* set adjacency */
  for (l=4*mesh->ne; l>0; l--) {  
    if ( link[l] >= 0 )  continue;
    k = ((l-1) >> 2) + 1;
    i = (l-1) % 4;
    i1 = MMG_idir[i][0];
    i2 = MMG_idir[i][1];
    i3 = MMG_idir[i][2];
    pt = &mesh->tetra[k];

    sum  = pt->v[i1] + pt->v[i2] + pt->v[i3];
    mins = M_MIN(pt->v[i1],pt->v[i2]);
    mins = M_MIN(mins,pt->v[i3]);
    maxs = M_MAX(pt->v[i1],pt->v[i2]);
    maxs = M_MAX(maxs,pt->v[i3]);

    /* accross link */
    ll = -link[l];
    pp = 0;
    link[l] = 0;
    while ( ll != inival ) {
      kk = ((ll-1) >> 2) + 1;
      ii = (ll-1) % 4;
      i1 = MMG_idir[ii][0];
      i2 = MMG_idir[ii][1];
      i3 = MMG_idir[ii][2];
      pt1  = &mesh->tetra[kk];   
      sum1 = pt1->v[i1] + pt1->v[i2] + pt1->v[i3];
      if ( sum1 == sum ) {
        mins1 = M_MIN(pt1->v[i1],pt1->v[i2]);
        mins1 = M_MIN(mins1,pt1->v[i3]);
        if ( mins1 == mins ) {
          maxs1 = M_MAX(pt1->v[i1],pt1->v[i2]);
          maxs1 = M_MAX(maxs1,pt1->v[i3]);
          if ( maxs1 == maxs ) {
            /* adjacent found */
            if ( pp != 0 )  link[pp] = link[ll];
            link[l] = 4*kk + ii;
            link[ll]= 4*k + i;
            break;
          }
        }
      }
      pp = ll;
      ll = -link[ll];
    }
  }

  M_free(hcode);
  return(1);
}



/* hash mesh edge v[0],v[1] (face i of iel) */
int MMG_hashEdge(pMesh mesh,pHedge hash,int iel,int i,int *v) {
  int       *adja,iadr,jel,j,key,mins,maxs;
  hedge     *ha;

  /* compute key */
  if ( v[0] < v[1] ) {
    mins = v[0];
    maxs = v[1];
  }
  else {
    mins = v[1];
    maxs = v[0];
  }
  key = KTA*mins + KTB*maxs;
  key = key % hash->size;
  ha  = &hash->item[key];

  if ( ha->min ) {
    /* identical face */
    if ( ha->min == mins && ha->max == maxs ) {
      iadr = (iel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[i] = ha->iel;

      jel  = ha->iel >> 2;
      j    = ha->iel % 4;
      iadr = (jel-1)*4 + 1;
      adja = &mesh->adja[iadr];
      adja[j] = iel*4 + i;
      return(1);
    }
    else
      while ( ha->nxt && ha->nxt < hash->nhmax ) {
        ha = &hash->item[ha->nxt];
	    if ( ha->min == mins && ha->max == maxs ) {
          iadr = (iel-1)*4 + 1;
          adja = &mesh->adja[iadr];
          adja[i] = ha->iel;

          jel  = ha->iel >> 2;
          j    = ha->iel % 4;
          iadr = (jel-1)*4 + 1;
          adja = &mesh->adja[iadr];
          adja[j] = iel*4 + i;
	      return(1);
	    }
      }
    ha->nxt = hash->hnxt;
    ha      = &hash->item[hash->hnxt];
    ++hash->hnxt;
    if ( hash->hnxt == hash->nhmax ) {
      fprintf(stdout,"  ## Memory alloc problem (edge): %d\n",hash->nhmax);
      return(0);
    }
  }

  /* insert */
  ha->min = mins;
  ha->max = maxs;
  ha->iel = iel*4 + i;
  ha->nxt = 0;

  return(1);
}


int MMG_inEdge(pHedge hash,int *v,int *iel,int *ia) {
  int        key,mins,maxs;
  hedge     *ha;

  /* compute key */
  if ( v[0] < v[1] ) {
    mins = v[0];
    maxs = v[1];
  }
  else {
    mins = v[1];
    maxs = v[0];
  }
  key = KA*mins + KB*maxs;
  key = key % hash->size;

  ha = &hash->item[key];

  if ( !ha->min )  return(0);
  else if ( ha->min == mins && ha->max == maxs ) {
    *iel = ha->iel / 6;
    *ia  = ha->iel % 6;
    return(1);
  }
  else if ( ha->nxt ) {
    do {
      ha = &hash->item[ha->nxt];
      if ( ha->min == mins && ha->max == maxs ) {
        *iel = ha->iel / 6;
        *ia  = ha->iel % 6;
        return(1);
      }
    }
    while ( ha->nxt && ha->nxt < hash->nhmax );
  }

  return(0);
}


/* hash triangles and return
   iel: face stored, 0 problem */
int MMG_hashFace(Hface *hash,int iel,int *v) {
  int        key,mins,maxs,sum;
  hface     *ht;

  mins = M_MIN(v[0],v[1]);
  mins = M_MIN(mins,v[2]);
  maxs = M_MAX(v[0],v[1]);
  maxs = M_MAX(maxs,v[2]);

  /* compute key */
  sum = v[0] + v[1] + v[2];
  key = KTA*mins + KTB*maxs + KTC*sum;
  key = key % hash->size;

  ht = &hash->item[key];

  if ( ht->min ) {
    if ( ht->min == mins && ht->max == maxs && ht->sum == sum )
      return(ht->iel);
    else
      while ( ht->nxt && ht->nxt < hash->nhmax ) {
        ht = &hash->item[ht->nxt];
	if ( ht->min == mins && ht->max == maxs && ht->sum == sum )
	  return(ht->iel);
      }
    ht->nxt = hash->hnxt;
    ht      = &hash->item[hash->hnxt];
    ++hash->hnxt;
    if ( hash->hnxt == hash->nhmax ) {
      fprintf(stdout,"  ## memory alloc problem (hash)\n");
      return(0);
    }
  }

  ht->min = mins;
  ht->max = maxs;
  ht->sum = sum;
  ht->iel = iel;
  ht->nxt = 0;

  return(iel);
}


/* hash triangles : put bdryref and assign a tet per triangle*/
int MMG_seedTria(pMesh mesh) {
  pTetra    pt,pt1;
  pTria     ptt;
  Hface     htri;
  int      *adja,v[3],i,k,iel,adj,iadr;
  int ncompt = 0;
  
  /* mem alloc */
  htri.size  = mesh->nt;
  htri.hnxt  = htri.size;
  htri.nhmax = (int)(2*htri.size);
  htri.item  = (hface*)M_calloc(htri.nhmax+1,sizeof(hface),"markTria"); 
  assert(htri.item);

  for (k=htri.size; k<htri.nhmax; k++)
    htri.item[k].nxt = k+1;  

  /* store triangles */
  for (k=1; k<=mesh->nt; k++) {
    ptt = &mesh->tria[k];
    iel = MMG_hashFace(&htri,k,ptt->v);
    if ( !iel )  return(0);
  }

  /* init seeds */
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    iadr = 4*(k-1) + 1;
    adja = &mesh->adja[iadr];
    for (i=0; i<4; i++) {
      adj = adja[i] >> 2;
      pt1 = &mesh->tetra[adj];
      if ( !adj || ((pt->ref != pt1->ref) ) ) { /*&& (k < adj) IL FAUT TRAITER LES 2 TETS POUR LES SD*/ 
        v[0] = pt->v[ MMG_idir[i][0] ];
        v[1] = pt->v[ MMG_idir[i][1] ];
        v[2] = pt->v[ MMG_idir[i][2] ];
        iel  = MMG_hashFace(&htri,0,v);
        if ( !iel )  { /*SD BDRY*/
          if(mesh->info.imprim > 5) printf("on trouve un tr de SD %d : %d %d %d (between %d et %d)\n",++ncompt,v[0],v[1],v[2],
                    k,adj);
          pt->bdryref[i] = 10;
          //return(0);
        } else { 
          /*ref bdry or sd bdry*/
          ptt = &mesh->tria[iel];
          pt->bdryref[i] = ptt->ref;
          if ( !ptt->splx )  ptt->splx = k;
        }
      } /*else {
        pt->bdryref[i] = pt->ref;
      }*/
    }
  }
  M_free(htri.item);
  return(1);
}


/* mark boundary vertices */
int MMG_markBdry(pMesh mesh) {
  pTetra    pt,pt1;
  pTria     ptt;
  pPoint    ppt;
  int      *adja,adj,iadr,k,i,ii,i1,nt;

  //printf("on arrive avec %d\n",mesh->nt);
  nt = 0;
  for (k=1; k<=mesh->ne; k++) {
    pt = &mesh->tetra[k];
    if ( !pt->v[0] )  continue;
    iadr = 4*(k-1) + 1;
    adja = &mesh->adja[iadr];
    for (i=0; i<4; i++) {
      adj = adja[i] >> 2;
      pt1 = &mesh->tetra[adj];
      if ( !adj || ((pt->ref != pt1->ref) && (k < adj)) ) { 
        for (ii=0; ii<3; ii++) {
          i1  = MMG_idir[i][ii];
          ppt = &mesh->point[pt->v[i1]];
          ppt->tag |= M_BDRY;
        }
        ++nt;
        if ( !mesh->nt ) {
          if ( (nt < mesh->ntmax-1) ) {  
            ptt = &mesh->tria[nt];
            ptt->v[0] = pt->v[ MMG_idir[i][0] ];
            ptt->v[1] = pt->v[ MMG_idir[i][1] ];
            ptt->v[2] = pt->v[ MMG_idir[i][2] ];   
            if (pt->bdryref[i]!=-1) {  
 							//if(k==13) printf("pour %d (%d) on met %d : %d %d %d\n",k,i,pt->bdryref[i],pt->v[ MMG_idir[i][0] ]
							//		,pt->v[ MMG_idir[i][1] ],pt->v[ MMG_idir[i][2] ]);
             ptt->ref = pt->bdryref[i];
            } else {
	            if(mesh->info.imprim < -3 )    
							printf("on a un tr qui n''a pas de ref : %d %d %d of %d %d \n",ptt->v[0],ptt->v[1],ptt->v[2],k,adj);
							// if(k==10252) {
							// 	printf("ses ref : %d %d %d %d\n",pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
							// 	printf("face %d : %d %d %d %d\n",i,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
							//   exit(0);
							// }
							ptt->ref  = (adj)?M_MIN(pt->ref,pt1->ref):10; 
							pt->bdryref[i] = (adj)?M_MIN(pt->ref,pt1->ref):10;
            }
            if ( !ptt->splx )  ptt->splx = k; 
          } 
          else {
            mesh->nt = nt;
          }
        }
      } else if ( (pt->ref != pt1->ref) ) {  
        if (pt->bdryref[i]==-1) pt->bdryref[i] = (adj)?M_MIN(pt->ref,pt1->ref):10; 
			}
    }
  }

  if ( !mesh->nt ) {
    mesh->nt    = nt;
    mesh->ntnil = mesh->nt + 1;
    for (k=mesh->ntnil; k<mesh->ntmax-1; k++)
      mesh->tria[k].v[2] = k+1;
  }
  else {
    //printf("passe-t-on la ?\n");
    if ( mesh->nt != nt )
    fprintf(stdout,"  ** WARNING: %d NON-BOUNDARY TRIANGLES : SEVERAL SD CONSIDERED\n",
            /*abs*/(mesh->nt-nt),nt,mesh->nt);

    MMG_seedTria(mesh); 
    /*erase triangles*/ 
    for (k=1; k<=mesh->nt; k++)
      mesh->tria[k].v[0] = 0;
     
  }
/*printf("on teste\n");
pTria ptria;  
for (k=1; k<=mesh->nt; k++) {
   ptria = &mesh->tria[k];
if(!(mesh->point[ptria->v[0]].tag & M_BDRY)) printf("pbs0 (%d) %d\n",k,ptria->v[0]); 
mesh->point[ptria->v[0]].tag |= M_BDRY; 
mesh->point[ptria->v[1]].tag |= M_BDRY; 
mesh->point[ptria->v[2]].tag |= M_BDRY; 
if(!(mesh->point[ptria->v[1]].tag & M_BDRY)) printf("pbs1 (%d) %d\n",k,ptria->v[1]);
if(!(mesh->point[ptria->v[2]].tag & M_BDRY)) printf("pbs2 (%d) %d\n",k,ptria->v[2]);
}   */
  return(1);
}

/* return 0: no point, np: point stored */ 
/* edge a-b*/
int MMG_edgePoint(pHedge hash,int a,int b) {
  int        key,mins,maxs;
  hedge     *ha;

  /* compute key */
  mins = a;
  maxs = b;
  if ( a > b ) {
    mins = b;
    maxs = a;
  }
  key = KA*mins + KB*maxs;
  key = key % hash->size;
  ha  = &hash->item[key];
  //printf("cherche %d %d\n",mins,maxs);
  if ( !ha->min )  return(0);
  else if ( ha->min == mins && ha->max == maxs ) {
    return(ha->iel);
  }
  else if ( ha->nxt ) {
    do {
      ha = &hash->item[ha->nxt];
      if ( ha->min == mins && ha->max == maxs ) {
        return(ha->iel);
      }
    }
    while ( ha->nxt && ha->nxt < hash->nhmax );
  }
  return(0);
}

/*put np on edge a-b*/
int MMG_edgePut(pHedge hash,int a,int b,int np) {
  int        key,mins,maxs;
  hedge     *ha;

  mins = a;
  maxs = b;
  if ( a > b ) {
    mins = b;
    maxs = a;
  }                    
  key = KA*mins + KB*maxs;
  key = key % hash->size;    
  ha  = &hash->item[key];

  if ( ha->min ) {
    /* identical edge */
    if ( ha->min == mins && ha->max == maxs ) {
      return(ha->iel);
    }
    else {
      while ( ha->nxt && ha->nxt < hash->nhmax ) {
        ha = &hash->item[ha->nxt];
	      if ( ha->min == mins && ha->max == maxs ) {
	        return(ha->iel);
	      }
      }             
    }
    ha->nxt = hash->hnxt;
    ha      = &hash->item[hash->hnxt];
    ++hash->hnxt;
    if ( hash->hnxt >= hash->nhmax ) {
      fprintf(stdout,"  ## Memory alloc problem (edge): %d\n",hash->nhmax);
      return(0);
    }
  }
  //printf("insert %d %d\n",mins,maxs);
  /* insert */
  ha->min = mins;
  ha->max = maxs;
  ha->iel = np;
  ha->nxt = 0;

  return(1);
}

