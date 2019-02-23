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

int MMG_cassar(pMesh mesh,pSol sol,int ipa,int ipb,float t);
int MMG_analar(pMesh ,pSol ,pBucket ,int *,int *,int *,int *);
int MMG_boulep(pMesh ,int ,int ,pList );
int MMG_bouleg(pMesh ,int ,int ,pList );
int MMG_coquil(pMesh ,int ,int ,pList );
int MMG_cendel(pMesh ,pSol ,float ,int );
int MMG_spledg(pMesh ,pSol ,pQueue ,pList ,int ,float ,float );

/* delaunay */
int MMG_correction(pMesh ,int ,pList ,int ,int ,char );
int MMG_delone(pMesh ,pSol ,int ,pList ,int );
int MMG_delons(pMesh ,pSol ,pQueue ,int ,pList ,int ,float );
int MMG_cenrad_ani(pMesh ,pSol ,int ,double *,double *,double *); 
int MMG_cenrad_iso(pMesh ,pSol ,int ,double *,double *); 

int MMG_colpoi(pMesh ,pSol ,int ,int ,int ,float );

/* hash */
int  MMG_hashTetra(pMesh );
int  MMG_hashEdge(pMesh ,pHedge ,int ,int ,int *);
int  MMG_inEdge(pHedge ,int *,int *,int *);
int  MMG_markBdry(pMesh );

/* inout */
int  MMG_loadMesh(pMesh ,char *);
int  MMG_loadSol(pSol ,char *,int );
int  MMG_loadVect(pMesh ,char *,int );
int  MMG_saveMesh(pMesh ,char *);
int  MMG_saveSol(pMesh ,pSol ,char *);
int  MMG_saveVect(pMesh ,char *);

int  MMG_loctet(pMesh ,int ,int ,double *,double *);
int  MMG_computeMetric(pMesh ,pSol ,int ,double * );

/* scale */
int  MMG_doSol(pMesh ,pSol );
int  MMG_scaleMesh(pMesh ,pSol );
int  MMG_unscaleMesh(pMesh ,pSol );

int  MMG_mmg3d1(pMesh ,pSol ,int *);
int  MMG_mmg3d9(pMesh ,pSol ,int *);


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
int  MMG_opttyp(pMesh ,pSol ,float ,int *);
int  MMG_optbdry(pMesh ,pSol ,int );
int  MMG_opt2peau(pMesh ,pSol ,pQueue ,int ,float );
int  MMG_optlap(pMesh ,pSol );

/* swapar */
typedef int (*MMG_Swap)(pMesh ,pSol ,pList );
//MMG_Swap MMG_swpptr;

int  MMG_swapar(pMesh ,pSol ,pQueue ,List *,int ,float ,float );

int  MMG_simu23(pMesh ,pSol ,int ,int ,float );
int  MMG_simu32(pMesh ,pSol ,pList ,float );
int  MMG_swap32(pMesh ,pSol ,pList );
int  MMG_swap23(pMesh ,pSol ,pQueue ,int ,int ,float );

int  MMG_simu44(pMesh ,pSol ,pList ,float );
int  MMG_swap44_1(pMesh ,pSol ,pList );
int  MMG_swap44_2(pMesh ,pSol ,pList );

int  MMG_simu56(pMesh ,pSol ,pList ,float );
int  MMG_swap56_1(pMesh ,pSol ,pList );
int  MMG_swap56_2(pMesh ,pSol ,pList );
int  MMG_swap56_3(pMesh ,pSol ,pList );
int  MMG_swap56_4(pMesh ,pSol ,pList );
int  MMG_swap56_5(pMesh ,pSol ,pList );

int MMG_simu68(pMesh ,pSol ,pList ,float );
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

int MMG_simu710(pMesh ,pSol ,pList ,float );
int MMG_swap710_1(pMesh ,pSol ,pList );
int MMG_swap710_2(pMesh ,pSol ,pList );
int MMG_swap710_3(pMesh ,pSol ,pList );
int MMG_swap710_4(pMesh ,pSol ,pList );
int MMG_swap710_5(pMesh ,pSol ,pList );
int MMG_swap710_6(pMesh ,pSol ,pList );
int MMG_swap710_7(pMesh ,pSol ,pList );
int MMG_swap710_8(pMesh ,pSol ,pList );
int MMG_swap710_9(pMesh ,pSol ,pList );
int MMG_swap710_10(pMesh ,pSol sol,pList list);
int MMG_swap710_11(pMesh ,pSol sol,pList list);
int MMG_swap710_12(pMesh ,pSol sol,pList list);
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

/* function pointers */
extern double (*MMG_length)(pMesh ,pSol ,int ,int );
extern double (*MMG_caltet)(pMesh ,pSol ,int );
extern double (*MMG_calte1)(pMesh ,pSol ,int );
extern int    (*MMG_caltet2)(pMesh ,pSol ,int ,int ,double ,double *);
extern int    (*MMG_cavity)(pMesh ,pSol ,int ,int ,pList ,int );
extern int    (*MMG_buckin)(pMesh ,pSol ,pBucket ,int );
extern int    (*MMG_optlen)(pMesh ,pSol ,float ,int );
extern int    (*MMG_interp)(double *,double *,double *,float );
extern int    (*MMG_optlentet)(pMesh ,pSol ,pQueue ,float ,int ,int );
extern int    (*MMG_movevertex)(pMesh ,pSol ,int ,int );

/* quality */
double MMG_voltet(pMesh ,int );
double MMG_quickvol(double *,double *,double *,double *);
int    MMG_prilen(pMesh ,pSol );
void   MMG_outqua(pMesh ,pSol );
double MMG_priworst(pMesh , pSol );

int  MMG_chkmsh(pMesh ,int ,int );

/* bucket */
pBucket MMG_newBucket(pMesh ,int );
int     MMG_addBucket(pMesh ,pBucket ,int );
int     MMG_delBucket(pMesh ,pBucket ,int );
void    MMG_freeBucket(pBucket );

/* heap */
Heap *MMG_hipini(pMesh ,int ,short ,float ,int );
void  MMG_hipfree(Heap *);
int   MMG_hipput(pMesh ,Heap *,int );
int   MMG_hippop(pMesh ,Heap *);
void  MMG_hiprep(pMesh ,Heap *,int );
void  MMG_hipdel(pMesh ,Heap *,int );

/* queue */
pQueue MMG_kiuini(pMesh ,int ,float ,int );
int    MMG_kiupop(pQueue );
int    MMG_kiudel(pQueue ,int );
int    MMG_kiuput(pQueue ,int );
void   MMG_kiufree(pQueue );

/* matrices */
int MMG_invmat(double *,double *);

double MMG_calte3_ani(pMesh mesh,pSol sol,int iel);

