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
 *  simulation of a chronograph
 *  in : tim
 *  out: tim.dtim = elapsed time in micro-secs
 *       tim.ptim = elapsed time in secs
 *       tim.call = number of calls
 *
 *  Written by Pascal J. Frey
 *  email: Pascal.Frey@inria.fr, 1999
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdlib.h>
#include "chrono.h"


/* return elapsed time in secs. */
static double diftim(time_t t2,time_t t1) {
  struct  tm  *ptm;
  double  tim;
  int     hh1,mm1,ss1,hh2,mm2,ss2;

  ptm = localtime(&t1);
  hh1 = ptm->tm_hour;
  mm1 = ptm->tm_min;
  ss1 = ptm->tm_sec;

  ptm = localtime(&t2);
  hh2 = ptm->tm_hour;
  mm2 = ptm->tm_min;
  ss2 = ptm->tm_sec;
  if ( hh2 < hh1 )  hh2 += 24;
  
  tim  = 3600.0*(hh2-hh1);
  tim += 60.0*(mm2-mm1);
  tim += ss2-ss1;

  return(tim);
}


/* get system and user times in micro-seconds */
void  TIM_chrono(int cmode,TIM_mytime *ptt) {
  time_t tt;

  if ( cmode == RESET ) {
    ptt->dtim  = clock();
    ptt->ctim  = 0.0f;
    ptt->ptim  = 0;
    ptt->call  = 0;
  }
  else {
    ptt->dtim = difftime(clock(),ptt->dtim);  /* in secs */
    if ( cmode == ON ) {
      ptt->ptim = time(NULL);
      ptt->call++;
    }
    else if ( cmode == OFF ) {
      tt = time(NULL);
      ptt->ctim += diftim(tt,ptt->ptim);
      ptt->ptim  = 0;
    }
  }
}


/* return time (converted in secs */
double TIM_gttime(TIM_mytime t) {

  if ( t.ctim < MAXCLK )
    return(t.dtim / (double)CLOCKS_PER_SEC);
  else
    return(t.ctim);
}


/* initialize time table */
void  TIM_tminit(TIM_mytime *t,int maxtim) {
  int     k;

  for (k=0; k<maxtim; k++) {
    t[k].dtim = clock();
    t[k].ptim = 0;
    t[k].ctim = 0.0;
    t[k].call = 0;
  }
}


#ifdef __cplusplus
}
#endif

