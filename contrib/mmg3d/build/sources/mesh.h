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
#ifndef _MMG3D_H
#define _MMG3D_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>


#include "chrono.h"
#include "memory.h"

#include "libmmg3d.h"
#include "libmmg3d_internal.h"
#include "mmg3dConfig.h"
#include "eigenv.h"

#define M_VER "4.0 c"
#define M_REL "July 20, 2010"
#define M_STR "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"

#define EPS      1.e-06
#define EPS1     1.e-9
#define EPS2     1.e-12
#define EPSOK    1.e-18
#define EPS30    1.e-30

#define ALPHAC   0.20412415      /* sqrt(6)/12 */  
#define ALPHAD   0.04811252      /* 1.0/(12*sqrt(3)) */
#define BETAC    0.03928371      /* sqrt(2)/36 */   
#define CALLIM   1.E+35    	    /*valeur de la qual pire*/


#define LLONG    1.41
#define LSHORT   0.68
#define LFILT    0.7
#define QDEGRAD  2.45

#define LONMAX     4096//512
#define NPMAX    500000
#define NTMAX   1000000
#define NEMAX   3000000

#define PRECI       1
#define BUCKSIZ    64

#define M_MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define M_MAX(a,b) ( (a) < (b) ? (b) : (a) )

#define M_NOTAG     (0)
#define M_UNUSED    (1 << 0)
#define M_BDRY      (1 << 1)
#define M_MOVE      (1 << 2)
#define M_CAVITY    (1 << 3)
#define M_CORNER    (1 << 4)
#define M_REQUIRED  (1 << 5)
#define M_RIDGE_GEO (1 << 6)
#define M_RIDGE_REF (1 << 7)
#define ALL_BDRY   63

/*#ifdef INT_MAX
#undef INT_MAX
#undef SHORT_MAX
#endif
*/
#ifndef INT_MAX
#define INT_MAX      0x7fffffff
#endif
#define SHORT_MAX    0x7fff


extern unsigned char MMG_idir[4][3];
extern unsigned char MMG_inxt[7];
extern unsigned char MMG_iarf[4][3];
extern unsigned char MMG_iare[6][2];
extern unsigned char MMG_ifar[6][2];
extern unsigned char MMG_isar[6][2];
extern unsigned char MMG_arpt[4][3];
                             

typedef struct {
  int      min,max,iel,nxt;
} hedge;
typedef struct {
  int      size,nhmax,hnxt;
  hedge   *item;  
} Hedge;
typedef Hedge * pHedge;

typedef struct {
  int     *blay,*blref,nblay;
} Blayer;


typedef struct slist {
  Hedge    hedg;
  double    qual[LONMAX+1];
  int      tetra[LONMAX+1];
} List;
typedef List * pList;

typedef struct squeue {
  int    *stack,cur;
} Queue;
typedef Queue * pQueue;

typedef struct {
  int     size,curc;
  int    *cell;
  int    *link;
} Heap;
typedef Heap * pHeap;

typedef struct {
  int     size;
  int    *head;
  int    *link;
} Bucket;
typedef Bucket * pBucket;

/*basic*/
int MMG_setfunc(int );

int MMG_cutprism(pMesh mesh,pHedge hed,int k,int p0,int p1,int p2,int p3,int p4,int p5,int ref);
int MMG_cuthex(pMesh mesh,pHedge hed,int k,int p0,int p1,int p2,int p3,int p4,int p5,int p6,int p7, int ref);

int MMG_analar(pMesh ,pSol ,pBucket ,int *,int *,int *,int *);
int MMG_analarcutting(pMesh ,pSol ,pHedge ,int *,double* ,double );
int MMG_boulep(pMesh ,int ,int ,pList );
int MMG_bouleg(pMesh ,int ,int ,pList );
int MMG_coquil(pMesh ,int ,int ,pList );
int MMG_cendel(pMesh ,pSol ,double ,int );
int MMG_spledg(pMesh ,pSol ,pQueue ,pList ,int ,double ,double );

int MMG_interp_ani(double *,double *,double *,double );
int MMG_interplog(double *,double *,double *,double *,double );
int MMG_interp_iso(double *,double *,double *,double );

/* delaunay */
int MMG_correction(pMesh ,int ,pList ,int ,int ,char );
int MMG_delone(pMesh ,pSol ,int ,pList ,int );
int MMG_delons(pMesh ,pSol ,pQueue ,int ,pList ,int ,double );
int MMG_cenrad_ani(pMesh ,double * ,double *,double *,double *); 
int MMG_cenrad_iso(pMesh ,double * ,double *,double *); 

/*pattern*/
int MMG_pattern1(pMesh ,pSol ,pHedge ,int );
int MMG_pattern2(pMesh ,pSol ,pHedge ,int );
int MMG_pattern3(pMesh ,pSol ,pHedge ,int );
int MMG_pattern4(pMesh ,pSol ,pHedge ,int );
int MMG_pattern5(pMesh ,pSol ,pHedge ,int );
int MMG_pattern6(pMesh ,pSol ,int ,int* );
int MMG_pattern22(pMesh ,pSol ,pHedge ,int );
int MMG_pattern31(pMesh ,pSol ,pHedge ,int );
int MMG_pattern32(pMesh ,pSol ,pHedge ,int );
int MMG_pattern33(pMesh ,pSol ,pHedge ,int );
int MMG_pattern41(pMesh ,pSol ,pHedge ,int );

int MMG_colpoi(pMesh ,pSol ,int ,int ,int ,double );

/* hash */
int  MMG_hashTetra(pMesh );
int  MMG_hashEdge(pMesh ,pHedge ,int ,int ,int *);
int  MMG_inEdge(pHedge ,int *,int *,int *);
int  MMG_markBdry(pMesh );
int  MMG_edgePoint(pHedge ,int ,int );
int  MMG_edgePut(pHedge ,int ,int ,int );


int  MMG_loctet(pMesh ,int ,int ,double *,double *);
int  MMG_computeMetric(pMesh ,pSol ,int ,double * );

/* scale */
int  MMG_doSol(pMesh ,pSol );
int  MMG_scaleMesh(pMesh ,pSol );
int  MMG_unscaleMesh(pMesh ,pSol );

int  MMG_mmg3d1(pMesh ,pSol ,int *);
int  MMG_mmg3d9(pMesh ,pSol ,int *);
int  MMG_mmg3d4(pMesh ,pSol ,int *);

/* zaldy */
int  MMG_newPt(pMesh ,double *c);
int  MMG_newElt(pMesh );
int  MMG_getnElt(pMesh ,int );
int  MMG_newTria(pMesh );
void MMG_delPt(pMesh ,int );
void MMG_delElt(pMesh ,int );
void MMG_delTria(pMesh ,int );
int  MMG_zaldy(pMesh );
int  MMG_zaldy3(pSol );
int  MMG_zaldy4(pHedge ,int );

int  MMG_optra4(pMesh ,pSol );
int  MMG_optcoq(pMesh ,pSol);
int  MMG_opttet(pMesh ,pSol);
int  MMG_opttyp(pMesh ,pSol ,double ,int *);
int  MMG_optbdry(pMesh ,pSol ,int );
int  MMG_opt2peau(pMesh ,pSol ,pQueue ,int ,double );
int  MMG_optlap(pMesh ,pSol );

/* swapar */
int  MMG_swapar(pMesh ,pSol ,pQueue ,List *,int ,double ,double );

int  MMG_simu23(pMesh ,pSol ,int ,int ,double );
int  MMG_simu32(pMesh ,pSol ,pList ,double );
int  MMG_swap32(pMesh ,pSol ,pList );
int  MMG_swap23(pMesh ,pSol ,pQueue ,int ,int ,double );

int  MMG_simu44(pMesh ,pSol ,pList ,double );
int  MMG_swap44_1(pMesh ,pSol ,pList );
int  MMG_swap44_2(pMesh ,pSol ,pList );

int  MMG_simu56(pMesh ,pSol ,pList ,double );
int  MMG_swap56_1(pMesh ,pSol ,pList );
int  MMG_swap56_2(pMesh ,pSol ,pList );
int  MMG_swap56_3(pMesh ,pSol ,pList );
int  MMG_swap56_4(pMesh ,pSol ,pList );
int  MMG_swap56_5(pMesh ,pSol ,pList );

int MMG_simu68(pMesh ,pSol ,pList ,double );
int MMG_swap68_1(pMesh ,pSol ,pList );
int MMG_swap68_2(pMesh ,pSol ,pList );
int MMG_swap68_3(pMesh ,pSol ,pList );
int MMG_swap68_4(pMesh ,pSol ,pList );
int MMG_swap68_5(pMesh ,pSol ,pList );
int MMG_swap68_6(pMesh ,pSol ,pList );
int MMG_swap68_7(pMesh ,pSol ,pList );
int MMG_swap68_8(pMesh ,pSol ,pList );
int MMG_swap68_9(pMesh ,pSol ,pList );
int MMG_swap68_10(pMesh ,pSol ,pList );
int MMG_swap68_11(pMesh ,pSol ,pList );
int MMG_swap68_12(pMesh ,pSol ,pList );
int MMG_swap68_13(pMesh ,pSol ,pList );
int MMG_swap68_14(pMesh ,pSol ,pList );

int MMG_simu710(pMesh ,pSol ,pList ,double );
int MMG_swap710_1(pMesh ,pSol ,pList );
int MMG_swap710_2(pMesh ,pSol ,pList );
int MMG_swap710_3(pMesh ,pSol ,pList );
int MMG_swap710_4(pMesh ,pSol ,pList );
int MMG_swap710_5(pMesh ,pSol ,pList );
int MMG_swap710_6(pMesh ,pSol ,pList );
int MMG_swap710_7(pMesh ,pSol ,pList );
int MMG_swap710_8(pMesh ,pSol ,pList );
int MMG_swap710_9(pMesh ,pSol ,pList );
int MMG_swap710_10(pMesh ,pSol ,pList );
int MMG_swap710_11(pMesh ,pSol ,pList );
int MMG_swap710_12(pMesh ,pSol ,pList );
int MMG_swap710_13(pMesh ,pSol ,pList );
int MMG_swap710_14(pMesh ,pSol ,pList );
int MMG_swap710_15(pMesh ,pSol ,pList );
int MMG_swap710_16(pMesh ,pSol ,pList );
int MMG_swap710_17(pMesh ,pSol ,pList );
int MMG_swap710_18(pMesh ,pSol ,pList );
int MMG_swap710_19(pMesh ,pSol ,pList );
int MMG_swap710_20(pMesh ,pSol ,pList );
int MMG_swap710_21(pMesh ,pSol ,pList );
int MMG_swap710_22(pMesh ,pSol ,pList );
int MMG_swap710_23(pMesh ,pSol ,pList );
int MMG_swap710_24(pMesh ,pSol ,pList );
int MMG_swap710_25(pMesh ,pSol ,pList );
int MMG_swap710_26(pMesh ,pSol ,pList );
int MMG_swap710_27(pMesh ,pSol ,pList );
int MMG_swap710_28(pMesh ,pSol ,pList );
int MMG_swap710_29(pMesh ,pSol ,pList );
int MMG_swap710_30(pMesh ,pSol ,pList );
int MMG_swap710_31(pMesh ,pSol ,pList );
int MMG_swap710_32(pMesh ,pSol ,pList );
int MMG_swap710_33(pMesh ,pSol ,pList );
int MMG_swap710_34(pMesh ,pSol ,pList );
int MMG_swap710_35(pMesh ,pSol ,pList );
int MMG_swap710_36(pMesh ,pSol ,pList );
int MMG_swap710_37(pMesh ,pSol ,pList );
int MMG_swap710_38(pMesh ,pSol ,pList );
int MMG_swap710_39(pMesh ,pSol ,pList );
int MMG_swap710_40(pMesh ,pSol ,pList );
int MMG_swap710_41(pMesh ,pSol ,pList );
int MMG_swap710_42(pMesh ,pSol ,pList );

int  MMG_typelt(pMesh ,int ,int *);

/* quality */
double MMG_voltet(pMesh ,int );
double MMG_quickvol(double *,double *,double *,double *);
int    MMG_prilen(pMesh ,pSol );
int    MMG_outqua(pMesh ,pSol );
int    MMG_outquacubic(pMesh ,pSol );
double MMG_priworst(pMesh , pSol );
int MMG_ratio(pMesh mesh, pSol sol,char* filename);

int  MMG_chkmsh(pMesh ,int ,int );

/* bucket */
pBucket MMG_newBucket(pMesh ,int );
int     MMG_addBucket(pMesh ,pBucket ,int );
int     MMG_delBucket(pMesh ,pBucket ,int );
void    MMG_freeBucket(pBucket );

/* heap */
Heap *MMG_hipini(pMesh ,int ,short ,double ,int );
void  MMG_hipfree(Heap *);
int   MMG_hipput(pMesh ,Heap *,int );
int   MMG_hippop(pMesh ,Heap *);
void  MMG_hiprep(pMesh ,Heap *,int );
void  MMG_hipdel(pMesh ,Heap *,int );

/* queue */
pQueue MMG_kiuini(pMesh ,int ,double ,int );
int    MMG_kiupop(pQueue );
int    MMG_kiudel(pQueue ,int );
int    MMG_kiuput(pQueue ,int );
void   MMG_kiufree(pQueue );

/* matrices */
int MMG_invmat(double *,double *);

double MMG_calte3_ani(pMesh mesh,pSol sol,int iel);

/* function pointers */
double MMG_long_ani(double *,double *,double *,double *);
double MMG_long_iso(double *,double *,double *,double *);
double MMG_caltetcubic(pMesh mesh,pSol sol,int iel);
double MMG_caltetrao(pMesh mesh,pSol sol,int iel);
double MMG_caltet_ani(pMesh mesh,pSol sol,int iel);
double MMG_caltet_iso(pMesh mesh,pSol sol,int iel);
double MMG_calte1_iso(pMesh mesh,pSol sol,int iel);
double MMG_calte1_ani(pMesh mesh,pSol sol,int iel);
double MMG_callong(pMesh mesh,pSol sol,int iel);
int    MMG_caltet2_iso(pMesh mesh,pSol sol,int iel,int ie,double ,double * caltab);
int    MMG_caltet2_ani(pMesh mesh,pSol sol,int iel,int ie,double ,double * caltab);
int    MMG_caltet2long_ani(pMesh mesh,pSol sol,int iel,int ie,double crit, double * caltab);
int    MMG_caltet2long_iso(pMesh mesh,pSol sol,int iel,int ie,double crit, double * caltab);
int    MMG_buckin_ani(pMesh mesh,pSol sol,pBucket bucket,int ip);
int    MMG_buckin_iso(pMesh mesh,pSol sol,pBucket bucket,int ip);
int    MMG_cavity_ani(pMesh mesh,pSol sol,int iel,int ip,pList list,int lon);
int    MMG_cavity_iso(pMesh mesh,pSol sol,int iel,int ip,pList list,int lon);
int    MMG_optlen_ani(pMesh mesh,pSol sol,double declic,int base);
int    MMG_optlen_iso(pMesh mesh,pSol sol,double declic,int base);
int    MMG_optlen_iso_new(pMesh mesh,pSol sol,double declic,int base);
int    MMG_optlen_iso2(pMesh mesh,pSol sol,double declic);
int    MMG_interp_ani(double *,double *,double * ,double );
int    MMG_interp_iso(double *,double *,double * ,double );
int    MMG_optlentet_ani(pMesh ,pSol ,pQueue ,double ,int ,int );
int    MMG_optlentet_iso(pMesh ,pSol ,pQueue ,double ,int ,int );
int    MMG_movevertex_ani(pMesh ,pSol ,int ,int );
int    MMG_movevertex_iso(pMesh ,pSol ,int ,int );


/* function pointers */
typedef int (*MMG_Swap)(pMesh ,pSol ,pList );
MMG_Swap MMG_swpptr;
double (*MMG_length)(double *,double *,double *,double *);
double (*MMG_caltet)(pMesh ,pSol ,int );
double (*MMG_calte1)(pMesh ,pSol ,int );
int    (*MMG_caltet2)(pMesh ,pSol ,int ,int ,double ,double *);
int    (*MMG_cavity)(pMesh ,pSol ,int ,int ,pList ,int );
int    (*MMG_buckin)(pMesh ,pSol ,pBucket ,int );
int    (*MMG_optlen)(pMesh ,pSol ,double ,int );
int    (*MMG_interp)(double *,double *,double *,double );
int    (*MMG_optlentet)(pMesh ,pSol ,pQueue ,double ,int ,int );
int    (*MMG_movevertex)(pMesh ,pSol ,int ,int );


#endif
