// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GEO_STRING_INTERFACE_H
#define GEO_STRING_INTERFACE_H

#include <string>
#include <vector>
#include "ListUtils.h"

void add_infile(const std::string &text, const std::string &fileName);
void add_charlength(const std::string &fileName, const std::vector<int> &l,
                    const std::string &lc);
void add_recosurf(const std::string &fileName, const std::vector<int> &l);
void add_trsfline(std::vector<int> &l, const std::string &fileName,
                  const std::string &type, const std::string &typearg,
                  const std::string &pts);
void add_trsfsurf(std::vector<int> &l, const std::string &fileName,
                  const std::string &dir);
void add_trsfvol(std::vector<int> &l, const std::string &fileName);
void add_embedded(const std::string &fileName, const std::string &what,
                  std::vector<int> &l, int dim, int tag);
void add_param(const std::string &par, const std::string &value,
               const std::string &label, const std::string &path,
               const std::string &fileName);
void add_point(const std::string &fileName, const std::string &x,
               const std::string &y, const std::string &z,
               const std::string &lc);
void add_multline(const std::string &type, std::vector<int> &p,
                  const std::string &fileName);
void add_circle_arc(int p1, int p2, int p3, const std::string &fileName);
void add_ellipse_arc(int p1, int p2, int p3, int p4,
                     const std::string &fileName);
void add_field_option(int field_id, const std::string &option_name,
                      const std::string &option_value,
                      const std::string &fileName);
void add_field(int field_id, const std::string &type_name,
               const std::string &fileName);
void delete_field(int field_id, const std::string &fileName);
void set_background_field(int field_id, const std::string &fileName);
void add_lineloop(List_T *list, const std::string &fileName, int *numloop);
void add_surf(const std::string &type, List_T *list,
              const std::string &fileName);
void add_surfloop(List_T *list, const std::string &fileName, int *numvol);
void add_vol(List_T *list, const std::string &fileName);
void add_remove_physical(const std::string &fileName, const std::string &what,
                         const std::vector<int> &l, const std::string &name,
                         int forceTag, bool append, const std::string &mode);
void add_compound(const std::string &fileName, const std::string &type,
                  const std::vector<int> &l);
void add_circle(const std::string &fileName, const std::string &x,
                const std::string &y, const std::string &z,
                const std::string &r, const std::string &alpha1,
                const std::string &alpha2);
void add_ellipse(const std::string &fileName, const std::string &x,
                 const std::string &y, const std::string &z,
                 const std::string &rx, const std::string &ry,
                 const std::string &alpha1, const std::string &alpha2);
void add_disk(const std::string &fileName, const std::string &x,
              const std::string &y, const std::string &z, const std::string &rx,
              const std::string &ry);
void add_rectangle(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &dx, const std::string &dy,
                   const std::string &roundedRadius);
void add_sphere(const std::string &fileName, const std::string &x,
                const std::string &y, const std::string &z,
                const std::string &r, const std::string &alpha1,
                const std::string &alpha2, const std::string &alpha3);
void add_cylinder(const std::string &fileName, const std::string &x,
                  const std::string &y, const std::string &z,
                  const std::string &dx, const std::string &dy,
                  const std::string &dz, const std::string &r,
                  const std::string &alpha);
void add_box(const std::string &fileName, const std::string &x,
             const std::string &y, const std::string &z, const std::string &dx,
             const std::string &dy, const std::string &dz);
void add_torus(const std::string &fileName, const std::string &x,
               const std::string &y, const std::string &z,
               const std::string &r1, const std::string &r2,
               const std::string &alpha);
void add_cone(const std::string &fileName, const std::string &x,
              const std::string &y, const std::string &z, const std::string &dx,
              const std::string &dy, const std::string &dz,
              const std::string &r1, const std::string &r2,
              const std::string &alpha);
void add_wedge(const std::string &fileName, const std::string &x,
               const std::string &y, const std::string &z,
               const std::string &dx, const std::string &dy,
               const std::string &dz, const std::string &ltx);
void translate(const std::string &fileName,
               const std::vector<std::pair<int, int> > &l,
               const std::string &tx, const std::string &ty,
               const std::string &tz, bool duplicata);
void rotate(const std::string &fileName,
            const std::vector<std::pair<int, int> > &l, const std::string &ax,
            const std::string &ay, const std::string &az, const std::string &px,
            const std::string &py, const std::string &pz,
            const std::string &angle, bool duplicata);
void dilate(const std::string &fileName,
            const std::vector<std::pair<int, int> > &l, const std::string &cx,
            const std::string &cy, const std::string &cz, const std::string &sx,
            const std::string &sy, const std::string &sz, bool duplicata);
void symmetry(const std::string &fileName,
              const std::vector<std::pair<int, int> > &l, const std::string &sa,
              const std::string &sb, const std::string &sc,
              const std::string &sd, bool duplicata);
void extrude(const std::string &fileName,
             const std::vector<std::pair<int, int> > &l, const std::string &tx,
             const std::string &ty, const std::string &tz, bool extrudeMesh,
             const std::string &layers, bool recombineMesh);
void protude(const std::string &fileName,
             const std::vector<std::pair<int, int> > &l, const std::string &ax,
             const std::string &ay, const std::string &az,
             const std::string &px, const std::string &py,
             const std::string &pz, const std::string &angle, bool extrudeMesh,
             const std::string &layers, bool recombineMesh);
void add_pipe(const std::string &fileName,
              const std::vector<std::pair<int, int> > &l,
              const std::vector<int> &l2);
void split_edge(int edge_id, List_T *vertices, const std::string &fileName);
void apply_boolean(const std::string &fileName, const std::string &op,
                   const std::vector<std::pair<int, int> > &object,
                   const std::vector<std::pair<int, int> > &tool,
                   int deleteObject, int deleteTool);
void apply_fillet(const std::string &fileName, const std::vector<int> &regions,
                  const std::vector<int> &edges, const std::string &radius);
void coherence(const std::string &fileName);
void delete_entities(const std::string &fileName,
                     const std::vector<std::pair<int, int> > &l,
                     bool recursive);

#endif
