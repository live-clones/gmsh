// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GEO_STRING_INTERFACE_H_
#define _GEO_STRING_INTERFACE_H_

#include <string>
#include <vector>
#include "ListUtils.h"

double evaluate_scalarfunction(std::string var, double val, std::string funct);

void coherence(std::string filename);
void delet(List_T *list, std::string filename, std::string what);
void add_infile(std::string text, std::string filename, bool deleted_something=false);
void add_charlength(List_T *list, std::string filename, std::string lc);
void add_recosurf(List_T *list, std::string filename);
void add_trsfline(std::vector<int> &l, std::string filename, std::string type, 
                  std::string typearg, std::string pts);
void add_trsfsurf(std::vector<int> &l, std::string filename, std::string dir);
void add_trsfvol(std::vector<int> &l, std::string filename);
void add_param(std::string par, std::string value, std::string filename);
void add_point(std::string filename, std::string x, std::string y, std::string z, 
               std::string lc);
void add_multline(std::string type, std::vector<int> &p, std::string filename);
void add_circ(int p1, int p2, int p3, std::string filename);
void add_ell(int p1, int p2, int p3, int p4, std::string filename);
void add_field_option(int field_id, std::string option_name, std::string option_value,
		      std::string filename);
void add_field(int field_id, std::string type_name, std::string filename);
void delete_field(int field_id, std::string filename);
void set_background_field(int field_id,std::string filename);
void add_lineloop(List_T *list, std::string filename, int *numloop);
void add_surf(std::string type, List_T *list, std::string filename);
void add_surfloop(List_T *list, std::string filename, int *numvol);
void add_vol(List_T *list, std::string filename);
void add_physical(std::string type, List_T *list, std::string filename);
void translate(int add, List_T *list, std::string filename, std::string what,
               std::string tx, std::string ty, std::string tz);
void rotate(int add, List_T *list, std::string filename, std::string what, 
            std::string ax, std::string ay, std::string az,
            std::string px, std::string py, std::string pz, std::string angle);
void dilate(int add, List_T *list, std::string filename, std::string what,
            std::string dx, std::string dy, std::string dz, std::string df);
void symmetry(int add, List_T *list, std::string filename, std::string what, 
              std::string sa, std::string sb, std::string sc, std::string sd);
void extrude(List_T *list, std::string filename, std::string what, std::string tx, 
             std::string ty, std::string tz);
void protude(List_T *list, std::string filename, std::string what, 
             std::string ax, std::string ay, std::string az, 
             std::string px, std::string py, std::string pz, std::string angle);
void split_edge(int edge_id, List_T *vertices, std::string filename);

#endif
