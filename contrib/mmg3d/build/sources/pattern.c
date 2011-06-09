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


unsigned char MMG_arfa[3][4] = { {2,0,1,3}, {1,2,0,3}, {0,1,2,3} }; 
extern int MMG_permar[10][4];
extern int MMG_pointar[64][2];
extern int ddebug;
//insert ip on ia-ib
int MMG_pattern1(pMesh mesh,pSol sol,pHedge hash,int jel) {
  pTetra     pt,pt1;
  int        iel,ia,ib,ic,id,ip,tabref[4],i; 
  if(ddebug) printf("on cut 1\n");

  pt = &mesh->tetra[jel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 
  
  if(pt->tabedg != 1) {    
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  ip = MMG_edgePoint(hash,ia,ib);
  assert(ip);
  if(ddebug) printf("ia %d %d %d %d\n",ia,ib,ic,id);
  pt->v[0] = ia;
  pt->v[1] = ip;
  pt->v[2] = ic;
  pt->v[3] = id;
  pt->qual = MMG_caltet(mesh,sol,jel); 
  pt->tabedg = 0;
  pt->flag = mesh->flag;  
  pt->bdryref[0] = -1;
  pt->bdryref[1] = tabref[1];
  pt->bdryref[2] = tabref[2];
  pt->bdryref[3] = tabref[3];
  if(ddebug) printf("creationi %d : %d %d %d %d\n",jel,ia,ip,ic,id); 
  
  iel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[iel];
  pt1->v[0] = ip;
  pt1->v[1] = ib;
  pt1->v[2] = ic;
  pt1->v[3] = id;
  pt1->qual = MMG_caltet(mesh,sol,iel);
  pt1->ref  = pt->ref;
  pt1->flag = mesh->flag; 
  if(ddebug) printf("tabref %d %d %d %d\n",tabref[0],tabref[1],tabref[2],tabref[3]);
  pt1->bdryref[0] = tabref[0];
  pt1->bdryref[1] = -1;
  pt1->bdryref[2] = tabref[2];
  pt1->bdryref[3] = tabref[3];
  if(ddebug) printf("creationi %d : %d %d %d %d\n",iel,ip,ib,ic,id); 
  //if(ddebug) exit(1); 
  return(1);
}

int MMG_pattern2(pMesh mesh,pSol sol,pHedge hash, int iel) { 
  pTetra     pt,pt1;
  int        jel,ia,ib,ic,id,iad,ibc,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 

  if(pt->tabedg != 12) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  iad = MMG_edgePoint(hash,ia,id); 
  assert(iad>0);
  ibc = MMG_edgePoint(hash,ib,ic); 
  assert(ibc>0);
  
  pt->v[0] = ibc;
  pt->v[1] = ic;
  pt->v[2] = iad;
  pt->v[3] = id;
  pt->qual = MMG_caltet(mesh,sol,iel); 
  pt->tabedg = 0;
  pt->flag = mesh->flag; 
  pt->bdryref[0] = tabref[1];
  pt->bdryref[1] = -1;
  pt->bdryref[2] = tabref[0];
  pt->bdryref[3] = -1;
  
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ib;
  pt1->v[1] = ibc;
  pt1->v[2] = iad;
  pt1->v[3] = id;
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->ref  = pt->ref;
  pt1->flag = mesh->flag;
  pt1->bdryref[0] = -1;
  pt1->bdryref[1] = tabref[2];
  pt1->bdryref[2] = tabref[0];
  pt1->bdryref[3] = -1;

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = ibc;
  pt1->v[2] = ic;
  pt1->v[3] = iad;
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->ref  = pt->ref;
  pt1->flag = mesh->flag;
  pt1->bdryref[0] = -1;
  pt1->bdryref[1] = tabref[1];
  pt1->bdryref[2] = -1;
  pt1->bdryref[3] = tabref[3];
   
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = ib;
  pt1->v[2] = ibc;
  pt1->v[3] = iad;
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->ref  = pt->ref;
  pt1->flag = mesh->flag;
  pt1->bdryref[0] = -1;
  pt1->bdryref[1] = -1;
  pt1->bdryref[2] = tabref[2];
  pt1->bdryref[3] = tabref[3];
  return(1); 
}

int MMG_pattern22(pMesh mesh,pSol sol,pHedge hash, int iel) { 
  pTetra     pt,pt1;
  int        jel,ia,ib,ic,id,iab,ibd,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 

  if(pt->tabedg != 17) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  iab = MMG_edgePoint(hash,ia,ib); 
  assert(iab>0);
  ibd = MMG_edgePoint(hash,ib,id); 
  assert(ibd>0);
  pt->v[0] = iab;
  pt->v[1] = ib;
  pt->v[2] = ic;
  pt->v[3] = ibd;
  pt->qual = MMG_caltet(mesh,sol,iel); 
  //if(pt->qual==CALLIM) puts("ahhhhhhhhh1");
  pt->tabedg = 0;
  pt->flag = mesh->flag;
  pt->bdryref[0] = tabref[0];
  pt->bdryref[1] = -1;
  pt->bdryref[2] = tabref[2];
  pt->bdryref[3] = tabref[3];
  
  if ( ia > id ) {
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iab;
    pt1->v[1] = ibd;
    pt1->v[2] = ic;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("bbahhhhhhhhh1");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = iab;
    pt1->v[2] = ic;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh11");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];
  } else {
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = iab;
    pt1->v[2] = ic;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) printf("ahhhvhhhhhh11 %d %d %d %d\n",ia,iab,ib,ibd);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ic;
    pt1->v[2] = id;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahvvhhhhhhhh11");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];
    
  }
   
  return(1); 
}

int MMG_pattern3(pMesh mesh,pSol sol,pHedge hash,int iel) {
  pTetra     pt,pt1;
  int        ia,ib,ic,id,iad,iab,ibd,jel,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]];
     
  if(pt->tabedg != 21) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  
  iad = MMG_edgePoint(hash,ia,id);
  assert(iad>0);
  iab = MMG_edgePoint(hash,ia,ib);
  assert(iab>0);
  ibd = MMG_edgePoint(hash,ib,id);
  assert(ibd>0);
  
  pt->v[0] = iab;
  pt->v[1] = ib;
  pt->v[2] = ic;
  pt->v[3] = ibd;
  pt->qual = MMG_caltet(mesh,sol,iel); 
  pt->tabedg = 0;
  pt->flag = mesh->flag;
  pt->bdryref[0] = tabref[0];
  pt->bdryref[1] = -1;
  pt->bdryref[2] = tabref[2];
  pt->bdryref[3] = tabref[3];
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = ia;
  pt1->v[1] = iab;
  pt1->v[2] = ic;
  pt1->v[3] = iad;
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->ref  = pt->ref;
  pt1->flag = mesh->flag;
  pt1->bdryref[0] = -1;
  pt1->bdryref[1] = tabref[1];
  pt1->bdryref[2] = tabref[2];
  pt1->bdryref[3] = tabref[3];

  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = iad;
  pt1->v[1] = ibd;
  pt1->v[2] = ic;
  pt1->v[3] = id;
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->ref  = pt->ref;   
  pt1->flag = mesh->flag;
  pt1->bdryref[0] = tabref[0];
  pt1->bdryref[1] = tabref[1];
  pt1->bdryref[2] = tabref[2];
  pt1->bdryref[3] = -1;
  
  jel = MMG_newElt(mesh);
  pt1 = &mesh->tetra[jel];
  pt1->v[0] = iab;
  pt1->v[1] = iad;
  pt1->v[2] = ibd;
  pt1->v[3] = ic;
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->ref  = pt->ref;
  pt1->flag = mesh->flag;
  pt1->bdryref[0] = -1;
  pt1->bdryref[1] = -1;
  pt1->bdryref[2] = -1;
  pt1->bdryref[3] = tabref[2];
  
  return(1);
  
}

int MMG_pattern31(pMesh mesh,pSol sol,pHedge hash,int iel) {
  pTetra     pt,pt1;
  int        ia,ib,ic,id,iad,icd,ibd,jel,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 
  if(pt->tabedg != 52) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  
  iad = MMG_edgePoint(hash,ia,id);
  assert(iad>0);
  icd = MMG_edgePoint(hash,ic,id);
  assert(icd>0);
  ibd = MMG_edgePoint(hash,ib,id);
  assert(ibd>0);

  pt->v[0] = iad;
  pt->v[1] = ibd;
  pt->v[2] = icd;
  pt->v[3] = id;
  pt->qual = MMG_caltet(mesh,sol,iel); 
  pt->tabedg = 0;
  pt->flag = mesh->flag;
  pt->bdryref[0] = tabref[0];
  pt->bdryref[1] = tabref[1];
  pt->bdryref[2] = tabref[2];
  pt->bdryref[3] = pt->ref;
  
  if ( (ia > ib) && (ib > ic) ) {
    assert(ia > ic);  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ib;
    pt1->v[2] = ic;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ic;
    pt1->v[2] = iad;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = pt->ref;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = iad;
    pt1->v[2] = ibd;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = pt->ref;
  } 
  else if ( (ia > ib) && (ic > ib) && (ic > ia)) {  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = icd;
    pt1->v[2] = iad;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = pt->ref;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = ia;
    pt1->v[2] = ib;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = tabref[3];
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ib;
    pt1->v[2] = icd;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = pt->ref;
  }
  else if ( (ia > ib) && (ic > ib) && (ia > ic)) {  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ib;
    pt1->v[2] = ic;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = icd;
    pt1->v[2] = iad;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = pt->ref;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ic;
    pt1->v[2] = iad;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = pt->ref;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = pt->ref;
  }
  else if ( (ib > ia) && (ib > ic) && (ic > ia)) {  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ia;
    pt1->v[2] = ibd;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[3];
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = ia;
    pt1->v[2] = ibd;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = pt->ref;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ibd;
    pt1->v[2] = icd;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = pt->ref;
  }
  else if ( (ib > ia) && (ib > ic) && (ia > ic)) {  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ia;
    pt1->v[2] = ibd;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[3];
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ic;
    pt1->v[2] = ibd;
    pt1->v[3] = ia;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = pt->ref;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = iad;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = pt->ref;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = pt->ref;
  }
  else if ( (ib > ia) && (ic > ib) ) { 
    assert(ic > ia); 
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ic;
    pt1->v[2] = ia;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = pt->ref;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ibd;
    pt1->v[2] = icd;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = pt->ref;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = pt->ref;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ib;
    pt1->v[2] = icd;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = pt->ref;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = pt->ref;
  }
  
  return(1);
  
}

int MMG_pattern32(pMesh mesh,pSol sol,pHedge hash,int iel) {
  pTetra     pt,pt1;
  int        ia,ib,ic,id,iad,ibc,ibd,jel,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 
  if(pt->tabedg != 28) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  
  iad = MMG_edgePoint(hash,ia,id);
  assert(iad>0);
  ibc = MMG_edgePoint(hash,ib,ic); 
  assert(ibc>0);
  ibd = MMG_edgePoint(hash,ib,id);
  assert(ibd>0);

  if ( (ia > ib) && (ic > id) ) {
    pt->v[0] = iad;
    pt->v[1] = ib;
    pt->v[2] = ia;
    pt->v[3] = ibc;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    //if(pt->qual==CALLIM) puts("ahhhhhhhhh1");
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = tabref[3];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = tabref[2];
    pt->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ibc;
    pt1->v[2] = iad;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("bahhhhhhhhh2");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = ibc;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("bahhhhhhhhh3");
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = -1;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibc;
    pt1->v[1] = iad;
    pt1->v[2] = id;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("bahhhhhhhhh4");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = ia;
    pt1->v[2] = ibc;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("bahhhhhhhhh5");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = tabref[3];
  } 
  else if ( (ia > ib) && (id > ic) ) {  
    pt->v[0] = iad;
    pt->v[1] = ib;
    pt->v[2] = ia;
    pt->v[3] = ibc;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    //if(pt->qual==CALLIM) puts("ahhhhhhhhh1");
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = tabref[3];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = -1;
    pt->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ibc;
    pt1->v[2] = iad;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh2");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ibc;
    pt1->v[2] = iad;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh3");
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = iad;
    pt1->v[2] = id;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh4");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = ia;
    pt1->v[2] = ibc;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh5");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = tabref[3];
  }
  else if ( (ib > ia) && (ic > id) ) {  
    pt->v[0] = ia;
    pt->v[1] = iad;
    pt->v[2] = ibc;
    pt->v[3] = ic;
    pt->qual = MMG_caltet(mesh,sol,iel); 
   // if(pt->qual==CALLIM) puts("ahhhhhhhhh6");
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = -1;
    pt->bdryref[1] = tabref[3];
    pt->bdryref[2] = tabref[1];
    pt->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibc;
    pt1->v[1] = ic;
    pt1->v[2] = iad;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh7");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = ia;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh8");
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ib;
    pt1->v[2] = ibc;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh9");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibc;
    pt1->v[1] = iad;
    pt1->v[2] = ibd;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh10");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[2];
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;
  }
  else if ( (ib > ia) && (id > ic) ) {  
    pt->v[0] = iad;
    pt->v[1] = ibd;
    pt->v[2] = ia;
    pt->v[3] = ic;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    //if(pt->qual==CALLIM) puts("ahhhhhhhhh11");
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = -1;
    pt->bdryref[1] = tabref[1];
    pt->bdryref[2] = -1;
    pt->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ib;
    pt1->v[2] = ibc;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh12");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = iad;
    pt1->v[2] = ibd;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh13");
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[2];
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = -1;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibc;
    pt1->v[1] = ic;
    pt1->v[2] = ia;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    //if(pt1->qual==CALLIM) puts("ahhhhhhhhh14");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag; 
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = tabref[3];
       
  }
  
  return(1);
  
} 

int MMG_pattern33(pMesh mesh,pSol sol,pHedge hash,int iel) {
  pTetra     pt,pt1;
  int        ia,ib,ic,id,iad,iac,ibd,jel,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 
  if(pt->tabedg != 22) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  
  iad = MMG_edgePoint(hash,ia,id);
  assert(iad>0);
  iac = MMG_edgePoint(hash,ia,ic);
  assert(iac>0);
  ibd = MMG_edgePoint(hash,ib,id);
  assert(ibd>0);

  if ( (ia > ib) && (ic > id) ) { 
    pt->v[0] = ia;
    pt->v[1] = ib;
    pt->v[2] = iac;
    pt->v[3] = iad;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    if(pt->qual==CALLIM) printf("tet 1\n");
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = -1;
    pt->bdryref[1] = tabref[1];
    pt->bdryref[2] = tabref[2];
    pt->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ic;
    pt1->v[2] = id;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("tet 2\n");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = ib;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("tet 3\n");
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[0];
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = iac;
    pt1->v[2] = ibd;
    pt1->v[3] = ib;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("tet 4\n");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = iac;
    pt1->v[2] = id;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("tet 5\n");
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];
  } 
  else if ( (ia > ib) && (id > ic) ) {  
    pt->v[0] = ia;
    pt->v[1] = ib;
    pt->v[2] = iac;
    pt->v[3] = iad;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = -1;
    pt->bdryref[1] = tabref[1];
    pt->bdryref[2] = tabref[2];
    pt->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = ib;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[0];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = iac;
    pt1->v[2] = ibd;
    pt1->v[3] = ib;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = iac;
    pt1->v[2] = ic;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ic;
    pt1->v[2] = id;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];
  }
  else if ( (ib > ia) && (ic > id) ) {  
    pt->v[0] = iac;
    pt->v[1] = ic;
    pt->v[2] = id;
    pt->v[3] = ibd;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = tabref[0];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = -1;
    pt->bdryref[3] = tabref[1];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = ib;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[0];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = iac;
    pt1->v[2] = id;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = ia;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ibd;
    pt1->v[2] = ia;
    pt1->v[3] = ib;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[2];
    pt1->bdryref[1] = tabref[3];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;
  }
  else if ( (ib > ia) && (id > ic) ) {  
    pt->v[0] = ibd;
    pt->v[1] = ic;
    pt->v[2] = ib;
    pt->v[3] = iac;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag;
    pt->bdryref[0] = tabref[3];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = -1;
    pt->bdryref[3] = tabref[0];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = ia;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ibd;
    pt1->v[2] = ia;
    pt1->v[3] = ib;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;   
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[2];
    pt1->bdryref[1] = tabref[3];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;
  
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = iad;
    pt1->v[2] = ic;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;    
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = iad;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;    
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;

  }
  
  return(1);
  
}

int MMG_pattern4(pMesh mesh,pSol sol,pHedge hash, int iel) { 
  pTetra     pt,pt1;
  int        jel,ia,ib,ic,id,iab,ibd,ibc,iad,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 

  if(pt->tabedg != 29) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  iab = MMG_edgePoint(hash,ia,ib); 
  assert(iab>0);
  ibd = MMG_edgePoint(hash,ib,id); 
  assert(ibd>0);
  iad = MMG_edgePoint(hash,ia,id); 
  assert(iad>0);
  ibc = MMG_edgePoint(hash,ib,ic); 
  assert(ibc>0);
  
  if ( ( ic > id ) && ( ia > ic ) ) {  
    pt->v[0] = iab;
    pt->v[1] = ibc;
    pt->v[2] = ic;
    pt->v[3] = iad;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = -1;
    pt->bdryref[1] = -1;
    pt->bdryref[2] = -1;
    pt->bdryref[3] = tabref[3];
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = id;
    pt1->v[1] = ibd;
    pt1->v[2] = iad;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = iab;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = iab;
    pt1->v[2] = ibc;
    pt1->v[3] = ib;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ia;
    pt1->v[2] = ic;
    pt1->v[3] = iab;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[1];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ic;
    pt1->v[2] = id;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];
  } 
  else if ( ( ic > id ) && ( ic > ia ) ) { 
    pt->v[0] = iad;
    pt->v[1] = ia;
    pt->v[2] = ibc;
    pt->v[3] = iab;
    pt->qual = MMG_caltet(mesh,sol,iel);  
    if(pt->qual==CALLIM) printf("biel %d\n",iel);
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = tabref[3];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = tabref[2];
    pt->bdryref[3] = -1;
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = iab;
    pt1->v[2] = ibc;
    pt1->v[3] = ib;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("ciel %d\n",iel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[2];
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = -1;
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = iab;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("diel %d\n",iel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = iad;
    pt1->v[2] = ibc;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("eiel %d\n",iel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[3];
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = -1;
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = id;
    pt1->v[1] = ibd;
    pt1->v[2] = iad;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("fiel %d\n",iel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = tabref[2];
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ic;
    pt1->v[2] = id;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    if(pt1->qual==CALLIM) printf("giel %d\n",iel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];
  }
  else if ( ia > ic ) {
    assert(id > ic); 
    pt->v[0] = iab;
    pt->v[1] = ibc;
    pt->v[2] = ic;
    pt->v[3] = iad;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = -1;
    pt->bdryref[1] = -1;
    pt->bdryref[2] = -1;
    pt->bdryref[3] = tabref[3];
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = ibc;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = iab;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iab;
    pt1->v[1] = ib;
    pt1->v[2] = ibc;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = ic;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = iab;
    pt1->v[2] = ic;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];
  }
  else {
    assert(id > ic);
    assert(ic > ia); 
    pt->v[0] = ibd;
    pt->v[1] = ic;
    pt->v[2] = ibc;
    pt->v[3] = iad;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = -1;
    pt->bdryref[1] = -1;
    pt->bdryref[2] = -1;
    pt->bdryref[3] = tabref[0];
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = iad;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ibc;
    pt1->v[2] = ic;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = iab;
    pt1->v[2] = ibc;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iab;
    pt1->v[1] = ib;
    pt1->v[2] = ibc;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iad;
    pt1->v[1] = ibd;
    pt1->v[2] = iab;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[2];
  }
   
  return(1); 
}


int MMG_pattern41(pMesh mesh,pSol sol,pHedge hash, int iel) { 
  pTetra     pt,pt1;
  int        jel,ia,ib,ic,id,iab,icd,iac,ibd,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]]; 
  if(pt->tabedg != 51) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  iab = MMG_edgePoint(hash,ia,ib); 
  assert(iab>0);
  icd = MMG_edgePoint(hash,ic,id); 
  assert(icd>0);
  iac = MMG_edgePoint(hash,ia,ic); 
  assert(iac>0);
  ibd = MMG_edgePoint(hash,ib,id); 
  assert(ibd>0);
  
  if ( ( ib > ic ) && ( ia > id ) ) { /*tetrap43.mesh*/
    pt->v[0] = id;
    pt->v[1] = iab;
    pt->v[2] = iac;
    pt->v[3] = ibd;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = -1;
    pt->bdryref[1] = -1;
    pt->bdryref[2] = tabref[2];
    pt->bdryref[3] = -1;
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = id;
    pt1->v[1] = ia;
    pt1->v[2] = iac;
    pt1->v[3] = iab;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[1];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ic;
    pt1->v[2] = ibd;
    pt1->v[3] = iab;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[3];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = icd;
    pt1->v[2] = iac;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ib;
    pt1->v[2] = iab;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = iac;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
  }
  else if ( ( ib > ic ) && ( id > ia ) ) { /*tetra45.mesh*/ 
    pt->v[0] = ia;
    pt->v[1] = id;
    pt->v[2] = ibd;
    pt->v[3] = icd;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = tabref[0];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = tabref[1];
    pt->bdryref[3] = tabref[2];
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = icd;
    pt1->v[1] = iac;
    pt1->v[2] = ibd;
    pt1->v[3] = ia;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ic;
    pt1->v[2] = ibd;
    pt1->v[3] = iab;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[3];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = iab;
    pt1->v[2] = iac;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ib;
    pt1->v[2] = iab;
    pt1->v[3] = ic;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = tabref[2];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = ic;
    pt1->v[2] = iac;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
  }
  else if ( ( ic > ib ) && ( ia > id ) ) { /*tetrap52.mesh*/ 
    pt->v[0] = ib;
    pt->v[1] = icd;
    pt->v[2] = iab;
    pt->v[3] = ibd;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = -1;
    pt->bdryref[1] = tabref[2];
    pt->bdryref[2] = tabref[0];
    pt->bdryref[3] = -1;
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = iab;
    pt1->v[2] = icd;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = id;
    pt1->v[1] = iab;
    pt1->v[2] = icd;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ia;
    pt1->v[2] = iab;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[2];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[1];
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = icd;
    pt1->v[2] = iab;
    pt1->v[3] = ib;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[3];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = ib;
    pt1->v[2] = icd;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[3];
    pt1->bdryref[3] = tabref[0];
  }
  else { /*tetrap54.mesh*/ 
    assert(( ic > ib ) && ( id > ia ) );
    pt->v[0] = ib;
    pt->v[1] = icd;
    pt->v[2] = iab;
    pt->v[3] = ibd;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = -1;
    pt->bdryref[1] = tabref[2];
    pt->bdryref[2] = tabref[0];
    pt->bdryref[3] = -1;
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = icd;
    pt1->v[1] = ia;
    pt1->v[2] = iac;
    pt1->v[3] = iab;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[3];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[1];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = icd;
    pt1->v[2] = iab;
    pt1->v[3] = ia;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = id;
    pt1->v[1] = ia;
    pt1->v[2] = icd;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[0];
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[1];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = iab;
    pt1->v[2] = ib;
    pt1->v[3] = icd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = tabref[3];

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ic;
    pt1->v[1] = ib;
    pt1->v[2] = icd;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = tabref[3];
    pt1->bdryref[3] = tabref[0];
  }
   
  return(1); 
}

int MMG_pattern5(pMesh mesh,pSol sol,pHedge hash, int iel) { 
  pTetra     pt,pt1;
  int        jel,ia,ib,ic,id,iac,icd,ibd,ibc,iad,i,tabref[4];
  
  pt = &mesh->tetra[iel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt->bdryref[MMG_permar[MMG_pointar[pt->tabedg][0]][i]];   

  if(pt->tabedg != 62) {
    ia = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][0]];
    ib = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][1]];
    ic = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][2]];
    id = pt->v[MMG_permar[MMG_pointar[pt->tabedg][0]][3]];
  } else {
    ia = pt->v[0];
    ib = pt->v[1];
    ic = pt->v[2];
    id = pt->v[3];
  } 
  iac = MMG_edgePoint(hash,ia,ic); 
  assert(iac>0);
  ibc = MMG_edgePoint(hash,ib,ic); 
  assert(ibc>0);
  ibd = MMG_edgePoint(hash,ib,id); 
  assert(ibd>0);
  icd = MMG_edgePoint(hash,ic,id); 
  assert(icd>0);
  iad = MMG_edgePoint(hash,ia,id); 
  assert(iad>0); 
	if(0 && (iel==8778 || iel==6508 )) ddebug = 1;   
	if(iel==6512) ddebug=1;
  if(ddebug) printf("tet %d : %d %d %d %d\n",iel,ia,ib,ic,id);    
	if(ddebug) printf("cas %d : %d %d %d %d\n",pt->tabedg,pt->v[0],pt->v[1],pt->v[2],pt->v[3]);
  if(ddebug) printf("bdyref      %d %d %d %d\n",pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
  if(ddebug) printf("tabref      %d %d %d %d\n",tabref[0],tabref[1],tabref[2],tabref[3]);
  if ( ( ia > ib ) ) { /*tetra_p51.mesh*/
    pt->v[0] = ibc;
    pt->v[1] = ic;
    pt->v[2] = iac;
    pt->v[3] = icd;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = tabref[1];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = tabref[0];
    pt->bdryref[3] = tabref[3];
		if(ddebug) printf("1 : on change %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibc;
    pt1->v[1] = icd;
    pt1->v[2] = iad;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = icd;
    pt1->v[2] = iad;
    pt1->v[3] = id;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibc;
    pt1->v[1] = icd;
    pt1->v[2] = iac;
    pt1->v[3] = iad;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ibc;
    pt1->v[2] = iad;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ib;
    pt1->v[1] = ia;
    pt1->v[2] = iad;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
		pt1->bdryref[0] = tabref[1];
		pt1->bdryref[1] = -1;//tabref[2];
    pt1->bdryref[2] = tabref[3];//tabref[3];
    pt1->bdryref[3] = tabref[2];//-1;
		if(ddebug) printf("--on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibc;
    pt1->v[1] = ib;
    pt1->v[2] = iad;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[3];
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);
  }
  else { /*tetra_p54.mesh*/  
    pt->v[0] = ibc;
    pt->v[1] = ic;
    pt->v[2] = iac;
    pt->v[3] = icd;
    pt->qual = MMG_caltet(mesh,sol,iel); 
    pt->tabedg = 0;
    pt->flag = mesh->flag; 
    pt->bdryref[0] = tabref[1];
    pt->bdryref[1] = -1;
    pt->bdryref[2] = tabref[0];
    pt->bdryref[3] = tabref[3];
		if(ddebug) printf("2 : on change %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
    
    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = icd;
    pt1->v[2] = iad;
    pt1->v[3] = id;    
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = tabref[2];
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ibd;
    pt1->v[2] = iad;
    pt1->v[3] = ia;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[2];
    pt1->bdryref[1] = tabref[1];
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = iac;
    pt1->v[1] = ia;
    pt1->v[2] = ibc;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;//tabref[3];
    pt1->bdryref[3] = tabref[3];//-1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ia;
    pt1->v[1] = ib;
    pt1->v[2] = ibc;
    pt1->v[3] = ibd;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[0];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[2];
    pt1->bdryref[3] = tabref[3];
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = ibd;
    pt1->v[1] = iad;
    pt1->v[2] = icd;
    pt1->v[3] = iac;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;
    pt1->bdryref[0] = tabref[1];
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = -1;
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);

    jel = MMG_newElt(mesh);
    pt1 = &mesh->tetra[jel];
    pt1->v[0] = icd;
    pt1->v[1] = ibd;
    pt1->v[2] = iac;
    pt1->v[3] = ibc;
    pt1->qual = MMG_caltet(mesh,sol,jel);
    pt1->ref  = pt->ref;
    pt1->flag = mesh->flag;  
    pt1->bdryref[0] = -1;
    pt1->bdryref[1] = -1;
    pt1->bdryref[2] = tabref[0];
    pt1->bdryref[3] = -1;
		if(ddebug) printf("on cree %d : %d %d %d %d\n",jel,pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);
  }
	ddebug = 0; 
  return(1); 
}

//insert ip02 on ip0ip2 etc...

/*create 8 tets
ip02 ip0 ip01 ip03
ip01 ip1 ip12 ip13
ip12 ip2 ip02 ip23
ip23 ip3 ip03 ip13
ip02 i12 ip03 ip01
ip01 ip03 ip13 ip12
ip12 ip03 ip23 ip02
ip23 ip12 ip13 ip03
*/
int MMG_pattern6(pMesh mesh,pSol sol,int jel,int *ipa) {
  pTetra     pt,pt1;
  int        iel,ip0,ip1,ip2,ip3,i,tabref[4]; 

  pt1 = &mesh->tetra[jel];
  for (i=0 ; i<4 ; i++) 
    tabref[i] = pt1->bdryref[i]; 


  ip0 = pt1->v[0];
  ip1 = pt1->v[1];
  ip2 = pt1->v[2];
  ip3 = pt1->v[3];
	ddebug = 0;
  if(ddebug) printf("tet %d : %d %d %d %d\n",jel,ip0,ip1,ip2,ip3);
  if(ddebug) printf("bdyref      %d %d %d %d\n",pt1->bdryref[0],pt1->bdryref[1],pt1->bdryref[2],pt1->bdryref[3]);
  if(ddebug) printf("tabref      %d %d %d %d\n",tabref[0],tabref[1],tabref[2],tabref[3]);
	ddebug = 0;
  
  pt1->v[0] = ipa[1];
  pt1->v[1] = ip0;
  pt1->v[2] = ipa[0];
  pt1->v[3] = ipa[2];
  pt1->qual = MMG_caltet(mesh,sol,jel);
  pt1->tabedg = 0;
  pt1->flag = mesh->flag;
  pt1->bdryref[0] = tabref[2];
  pt1->bdryref[1] = -1;
  pt1->bdryref[2] = tabref[1];
  pt1->bdryref[3] = tabref[3];

  iel = MMG_newElt(mesh);
  pt = &mesh->tetra[iel];
  pt->v[0] = ipa[0];
  pt->v[1] = ip1;
  pt->v[2] = ipa[3];
  pt->v[3] = ipa[4];
  pt->qual = MMG_caltet(mesh,sol,iel);
  pt->ref  = pt1->ref;
  pt->flag = mesh->flag;
  pt->bdryref[0] = tabref[0];
  pt->bdryref[1] = -1;
  pt->bdryref[2] = tabref[2];
  pt->bdryref[3] = tabref[3];
	// printf("on cree %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
  iel = MMG_newElt(mesh);
  pt = &mesh->tetra[iel];
  pt->v[0] = ipa[3];
  pt->v[1] = ip2;
  pt->v[2] = ipa[1];
  pt->v[3] = ipa[5];
  pt->qual = MMG_caltet(mesh,sol,iel);
  pt->ref  = pt1->ref;
  pt->flag = mesh->flag;
  pt->bdryref[0] = tabref[1];
  pt->bdryref[1] = -1;
  pt->bdryref[2] = tabref[0];
  pt->bdryref[3] = tabref[3];
	// printf("on cree %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);

  iel = MMG_newElt(mesh);
  pt = &mesh->tetra[iel];
  pt->v[0] = ipa[5];
  pt->v[1] = ip3;
  pt->v[2] = ipa[2];
  pt->v[3] = ipa[4];
  pt->qual = MMG_caltet(mesh,sol,iel);
  pt->ref  = pt1->ref;
  pt->flag = mesh->flag;
  pt->bdryref[0] = tabref[2];
  pt->bdryref[1] = -1;
  pt->bdryref[2] = tabref[0];
  pt->bdryref[3] = tabref[1];
	// printf("on cree %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
 
  iel = MMG_newElt(mesh);
  pt = &mesh->tetra[iel];
  pt->v[0] = ipa[1];
  pt->v[1] = ipa[3];
  pt->v[2] = ipa[2];
  pt->v[3] = ipa[0];
  pt->qual = MMG_caltet(mesh,sol,iel);
  pt->ref  = pt1->ref;
  pt->flag = mesh->flag;
  pt->bdryref[0] = -1;
  pt->bdryref[1] = -1;
  pt->bdryref[2] = tabref[3];
  pt->bdryref[3] = -1;
	// printf("on cree %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);

  iel = MMG_newElt(mesh);
  pt = &mesh->tetra[iel];
  pt->v[0] = ipa[0];
  pt->v[1] = ipa[2];
  pt->v[2] = ipa[4];
  pt->v[3] = ipa[3];
  pt->qual = MMG_caltet(mesh,sol,iel);
  pt->ref  = pt1->ref;
  pt->flag = mesh->flag;
  pt->bdryref[0] = -1;
  pt->bdryref[1] = -1;
  pt->bdryref[2] = -1;
  pt->bdryref[3] = tabref[2];
	// printf("on cree %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);

  iel = MMG_newElt(mesh);
  pt = &mesh->tetra[iel];
  pt->v[0] = ipa[3];
  pt->v[1] = ipa[2];
  pt->v[2] = ipa[5];
  pt->v[3] = ipa[1];
  pt->qual = MMG_caltet(mesh,sol,iel);
  pt->ref  = pt1->ref;
  pt->flag = mesh->flag;
  pt->bdryref[0] = tabref[1];
  pt->bdryref[1] = -1;
  pt->bdryref[2] = -1;
  pt->bdryref[3] = -1;
	// printf("on cree %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);

  iel = MMG_newElt(mesh);
  pt = &mesh->tetra[iel];
  pt->v[0] = ipa[5];
  pt->v[1] = ipa[3];
  pt->v[2] = ipa[4];
  pt->v[3] = ipa[2];
  pt->qual = MMG_caltet(mesh,sol,iel);
  pt->ref  = pt1->ref;
  pt->flag = mesh->flag;
  pt->bdryref[0] = -1;
  pt->bdryref[1] = -1;
  pt->bdryref[2] = -1;
  pt->bdryref[3] = tabref[0];
	// printf("on cree %d : %d %d %d %d\n",iel,pt->bdryref[0],pt->bdryref[1],pt->bdryref[2],pt->bdryref[3]);
  //printf("on cut 6\n");
  //exit(1);              
  return(1);
}

