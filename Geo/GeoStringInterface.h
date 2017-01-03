// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GEO_STRING_INTERFACE_H_
#define _GEO_STRING_INTERFACE_H_

#include <string>
#include <vector>
#include "ListUtils.h"

void coherence(const std::string &fileName);
void delet(List_T *list, const std::string &fileName, const std::string &what);
void add_infile(const std::string &text, const std::string &fileName,
                bool deleted_something=false);
void add_charlength(List_T *list, const std::string &fileName, const std::string &lc);
void add_recosurf(List_T *list, const std::string &fileName);
void add_trsfline(std::vector<int> &l, const std::string &fileName,
                  const std::string &type, const std::string &typearg,
                  const std::string &pts);
void add_trsfsurf(std::vector<int> &l, const std::string &fileName,
                  const std::string &dir);
void add_trsfvol(std::vector<int> &l, const std::string &fileName);
void add_embedded(const std::string &what, std::vector<int> &l,
                  const std::string &fileName);
void add_param(const std::string &par, const std::string &value,
               const std::string &label, const std::string &path,
               const std::string &fileName);
void add_point(const std::string &fileName, const std::string &x,
               const std::string &y, const std::string &z, const std::string &lc);
void add_multline(const std::string &type, std::vector<int> &p,
                  const std::string &fileName);
void add_circ(int p1, int p2, int p3, const std::string &fileName);
void add_ell(int p1, int p2, int p3, int p4, const std::string &fileName);
void add_field_option(int field_id, const std::string &option_name,
                      const std::string &option_value, const std::string &fileName);
void add_field(int field_id, const std::string &type_name,
               const std::string &fileName);
void delete_field(int field_id, const std::string &fileName);
void set_background_field(int field_id,const std::string &fileName);
void add_lineloop(List_T *list, const std::string &fileName, int *numloop);
void add_surf(const std::string &type, List_T *list, const std::string &fileName);
void add_surfloop(List_T *list, const std::string &fileName, int *numvol);
void add_vol(List_T *list, const std::string &fileName);
void add_physical(const std::string &type, List_T *list, const std::string &fileName,
                  const std::string &name, int forceTag, bool append,
                  const std::string &mode);
void add_compound(const std::string &type, List_T *list, const std::string &fileName);
void translate(int add, List_T *list, const std::string &fileName,
               const std::string &what, const std::string &tx, const std::string &ty,
               const std::string &tz);
void rotate(int add, List_T *list, const std::string &fileName,
            const std::string &what, const std::string &ax, const std::string &ay,
            const std::string &az, const std::string &px, const std::string &py,
            const std::string &pz,
            const std::string &angle);
void dilate(int add, List_T *list, const std::string &fileName,
            const std::string &what, const std::string &dx, const std::string &dy,
            const std::string &dz, const std::string &df);
void symmetry(int add, List_T *list, const std::string &fileName,
              const std::string &what, const std::string &sa, const std::string &sb,
              const std::string &sc, const std::string &sd);
void extrude(List_T *list, const std::string &fileName, const std::string &what,
             const std::string &tx,
             const std::string &ty, const std::string &tz);
void protude(List_T *list, const std::string &fileName, const std::string &what,
             const std::string &ax, const std::string &ay, const std::string &az,
             const std::string &px, const std::string &py, const std::string &pz,
             const std::string &angle);
void split_edge(int edge_id, List_T *vertices, const std::string &fileName);

#endif
