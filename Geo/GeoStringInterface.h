// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GEO_STRING_INTERFACE_H_
#define _GEO_STRING_INTERFACE_H_

#include "ListUtils.h"

double evaluate_scalarfunction(const char *var, double val, const char *funct);

void coherence(const char *fich);
void delet(List_T *list, const char *fich, const char *what);
void add_infile(const char *text, const char *fich, bool deleted_something=false);
void add_trsfline(int N, int *l, const char *fich, const char *type, 
                  const char *typearg, const char *pts);
void add_trsfsurf(int N, int *l, const char *fich, const char *dir);
void add_trsfvol(int N, int *l, const char *fich);
void add_charlength(List_T *list, const char *fich, const char *lc);
void add_recosurf(List_T *list, const char *fich);
void add_param(const char *par, const char *value, const char *fich);
void add_point(const char *fich, const char *x, const char *y, const char *z, 
               const char *lc);
void add_line(int p1, int p2, const char *fich);
void add_circ(int p1, int p2, int p3, const char *fich);
void add_ell(int p1, int p2, int p3, int p4, const char *fich);
void add_spline(int N, int *p, const char *fich);
void add_bezier(int N, int *p, const char *fich);
void add_bspline(int N, int *p, const char *fich);
void add_field_option(int field_id, const char *option_name, const char *option_value, const char *fich);
void add_field(int field_id, const char *type_name, const char *fich);
void delete_field(int field_id, const char *fich);
void set_background_field(int field_id,const char *fich);
void add_multline(int N, int *p, const char *fich);
void add_lineloop(List_T *list, const char *fich, int *numloop);
void add_surf(List_T *list, const char *fich, int support, int typ);
void add_surfloop(List_T *list, const char *fich, int *numvol);
void add_vol(List_T *list, const char *fich);
int add_physical(List_T *list, const char *fich, int type);
void translate(int add, List_T *list, const char *fich, const char *what,
               const char *tx, const char *ty, const char *tz);
void rotate(int add, List_T *list, const char *fich, const char *what, 
            const char *ax, const char *ay, const char *az,
            const char *px, const char *py, const char *pz, const char *angle);
void dilate(int add, List_T *list, const char *fich, const char *what,
            const char *dx, const char *dy, const char *dz, const char *df);
void symmetry(int add, List_T *list, const char *fich, const char *what, 
              const char *sa, const char *sb, const char *sc, const char *sd);
void extrude(List_T *list, const char *fich, const char *what, const char *tx, 
             const char *ty, const char *tz);
void protude(List_T *list, const char *fich, const char *what, 
             const char *ax, const char *ay, const char *az, 
             const char *px, const char *py, const char *pz, const char *angle);

#endif
