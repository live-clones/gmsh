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
typedef struct {
  double        c[3];
  int           mark,tmp;
  int           ref;
  unsigned char flag,tag,tmp2;
	unsigned char geom;
} MMG_Point;
typedef MMG_Point * MMG_pPoint;

typedef struct {
  int           v[4];
  int           mark;
  double        qual;
  int           ref,bdryref[4];
  unsigned char flag,edge,tabedg;  
	unsigned char bdryinfo[6];
} MMG_Tetra;
typedef MMG_Tetra * MMG_pTetra;

typedef struct {
  int           v[3],splx;
  int           ref;
} MMG_Tria;
typedef MMG_Tria * MMG_pTria;

typedef struct {
  int      np,ver;
  double   *mv,*cold;
  short    *alpha;  
} MMG_Displ;
typedef MMG_Displ * MMG_pDispl;

typedef struct {
  unsigned char  ddebug;
  unsigned char  noswap,noinsert,nomove,bdry;
  short          imprim,option,memory,rn,rn2;
  int            bucksiz;
  double   	     delta,dt;
  double   	     min[3],max[3];  

} MMG_Info;

typedef struct {
  int      np,ne,nt,ncor,ned,npmax,nemax,ntmax;
  int      npfixe,nefixe,ntfixe,mark;
  int      npnil,nenil,ntnil;
  int     *adja,ver;
  char    *name,*outf,*move;
  unsigned char flag,booleen;

  MMG_pPoint   point;
  MMG_pTetra   tetra;
  MMG_pTria    tria;
  MMG_pDispl   disp;
  MMG_Info     info;
} MMG_Mesh;
typedef MMG_Mesh * MMG_pMesh;

typedef struct {
  int      np,npfixe,npmax,ver;
  double   *met,hmin,hmax;
  char     *name;  
  double   *metold;
  unsigned char offset;
} MMG_Sol;
typedef MMG_Sol * MMG_pSol;

/* inout */
int  MMG_loadMesh(MMG_pMesh ,char *);
int  MMG_loadSol(MMG_pSol ,char *,int );
int  MMG_loadVect(MMG_pMesh ,char *,int );
int  MMG_saveMesh(MMG_pMesh ,char *);
int  MMG_saveSol(MMG_pMesh ,MMG_pSol ,char *);
int  MMG_saveVect(MMG_pMesh ,char *);

#ifdef  __cplusplus
namespace mmg3d{
extern "C" {
#endif
int MMG_mmg3dlib(int opt[9],MMG_pMesh mesh,MMG_pSol sol);
#ifdef  __cplusplus
}}
#endif
