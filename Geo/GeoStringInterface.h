#ifndef _GEO_STRING_INTERFACE_H_
#define _GEO_STRING_INTERFACE_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "List.h"

double evaluate_scalarfunction(char *var, double val, char *funct);

void coherence(char *fich);
void delet(List_T *list, char *fich, char *what);
void add_infile(char *text, char *fich, bool deleted_something=false);
void add_trsfline(int N, int *l, char *fich, char *type, char *typearg, char *pts);
void add_trsfsurf(int N, int *l, char *fich, char *dir);
void add_trsfvol(int N, int *l, char *fich);
void add_charlength(List_T *list, char *fich, char *lc);
void add_recosurf(List_T *list, char *fich);
void add_param(char *par, char *value, char *fich);
void add_point(char *fich, char *x, char *y, char *z, char *lc);
void add_attractor(char *fich, int ip, int typ);
void add_line(int p1, int p2, char *fich);
void add_circ(int p1, int p2, int p3, char *fich);
void add_ell(int p1, int p2, int p3, int p4, char *fich);
void add_spline(int N, int *p, char *fich);
void add_bezier(int N, int *p, char *fich);
void add_bspline(int N, int *p, char *fich);
void add_multline(int N, int *p, char *fich);
void add_lineloop(List_T *list, char *fich, int *numloop);
void add_surf(List_T *list, char *fich, int support, int typ);
void add_surfloop(List_T *list, char *fich, int *numvol);
void add_vol(List_T *list, char *fich);
int add_physical(List_T *list, char *fich, int type);
void translate(int add, List_T *list, char *fich, char *what,
	       char *tx, char *ty, char *tz);
void rotate(int add, List_T *list, char *fich, char *what, 
	    char *ax, char *ay, char *az,
	    char *px, char *py, char *pz, char *angle);
void dilate(int add, List_T *list, char *fich, char *what,
	    char *dx, char *dy, char *dz, char *df);
void symmetry(int add, List_T *list, char *fich, char *what, 
	      char *sa, char *sb, char *sc, char *sd);
void extrude(List_T *list, char *fich, char *what, char *tx, char *ty, char *tz);
void protude(List_T *list, char *fich, char *what, char *ax, char *ay, char *az,
	     char *px, char *py, char *pz, char *angle);

#endif
