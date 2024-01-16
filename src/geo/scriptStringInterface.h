// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCRIPT_STRING_INTERFACE_H
#define SCRIPT_STRING_INTERFACE_H

#include <string>
#include <vector>
#include "ListUtils.h"

void scriptRemoveLastCommand(const std::string &fileName);

void scriptSetFactory(const std::string &factory, const std::string &fileName);
void scriptSetMeshSize(const std::string &fileName, const std::vector<int> &l,
                       const std::string &lc);
void scriptRecombineSurface(const std::string &fileName,
                            const std::vector<int> &l);
void scriptSetTransfiniteLine(std::vector<int> &l, const std::string &fileName,
                              const std::string &type,
                              const std::string &typearg,
                              const std::string &pts);
void scriptSetTransfiniteSurface(std::vector<int> &l,
                                 const std::string &fileName,
                                 const std::string &dir);
void scriptSetTransfiniteVolume(std::vector<int> &l,
                                const std::string &fileName);
void scriptEmbed(const std::string &fileName, const std::string &what,
                 std::vector<int> &l, int dim, int tag);
void scriptAddParameter(const std::string &par, const std::string &value,
                        const std::string &label, const std::string &path,
                        const std::string &fileName);
void scriptAddPoint(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &lc);
void scriptAddCurve(const std::string &type, std::vector<int> &p,
                    const std::string &fileName);
void scriptAddCircleArc(int p1, int p2, int p3, const std::string &fileName);
void scriptAddEllipseArc(int p1, int p2, int p3, int p4,
                         const std::string &fileName);
void scriptAddFieldOption(int field_id, const std::string &option_name,
                          const std::string &option_value, int option_type,
                          const std::string &fileName);
void scriptAddField(int field_id, const std::string &type_name,
                    const std::string &fileName);
void scriptDeleteField(int field_id, const std::string &fileName);
void scriptSetBackgroundField(int field_id, const std::string &fileName);
void scriptAddCurveLoop(List_T *list, const std::string &fileName,
                        int *numloop);
void scriptAddSurface(const std::string &type, List_T *list,
                      const std::string &fileName);
void scriptAddSurfaceLoop(List_T *list, const std::string &fileName,
                          int *numvol);
void scriptAddVolume(List_T *list, const std::string &fileName);
void scriptAddRemovePhysicalGroup(const std::string &fileName,
                                  const std::string &what,
                                  const std::vector<int> &l,
                                  const std::string &name, int forceTag,
                                  bool append, const std::string &mode);
void scriptSetCompound(const std::string &fileName, const std::string &type,
                       const std::vector<int> &l);
void scriptAddCircle(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2);
void scriptAddEllipse(const std::string &fileName, const std::string &x,
                      const std::string &y, const std::string &z,
                      const std::string &rx, const std::string &ry,
                      const std::string &alpha1, const std::string &alpha2);
void scriptAddDisk(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &rx, const std::string &ry);
void scriptAddRectangle(const std::string &fileName, const std::string &x,
                        const std::string &y, const std::string &z,
                        const std::string &dx, const std::string &dy,
                        const std::string &roundedRadius);
void scriptAddSphere(const std::string &fileName, const std::string &x,
                     const std::string &y, const std::string &z,
                     const std::string &r, const std::string &alpha1,
                     const std::string &alpha2, const std::string &alpha3);
void scriptAddCylinder(const std::string &fileName, const std::string &x,
                       const std::string &y, const std::string &z,
                       const std::string &dx, const std::string &dy,
                       const std::string &dz, const std::string &r,
                       const std::string &alpha);
void scriptAddBox(const std::string &fileName, const std::string &x,
                  const std::string &y, const std::string &z,
                  const std::string &dx, const std::string &dy,
                  const std::string &dz);
void scriptAddTorus(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &r1, const std::string &r2,
                    const std::string &alpha);
void scriptAddCone(const std::string &fileName, const std::string &x,
                   const std::string &y, const std::string &z,
                   const std::string &dx, const std::string &dy,
                   const std::string &dz, const std::string &r1,
                   const std::string &r2, const std::string &alpha);
void scriptAddWedge(const std::string &fileName, const std::string &x,
                    const std::string &y, const std::string &z,
                    const std::string &dx, const std::string &dy,
                    const std::string &dz, const std::string &ltx);
void scriptTranslate(const std::string &fileName,
                     const std::vector<std::pair<int, int> > &l,
                     const std::string &tx, const std::string &ty,
                     const std::string &tz, bool duplicata);
void scriptRotate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &ax, const std::string &ay,
                  const std::string &az, const std::string &px,
                  const std::string &py, const std::string &pz,
                  const std::string &angle, bool duplicata);
void scriptDilate(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &cx, const std::string &cy,
                  const std::string &cz, const std::string &sx,
                  const std::string &sy, const std::string &sz, bool duplicata);
void scriptMirror(const std::string &fileName,
                  const std::vector<std::pair<int, int> > &l,
                  const std::string &sa, const std::string &sb,
                  const std::string &sc, const std::string &sd, bool duplicata);
void scriptExtrude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &tx, const std::string &ty,
                   const std::string &tz, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh);
void scriptProtude(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::string &ax, const std::string &ay,
                   const std::string &az, const std::string &px,
                   const std::string &py, const std::string &pz,
                   const std::string &angle, bool extrudeMesh,
                   const std::string &layers, bool recombineMesh);
void scriptAddPipe(const std::string &fileName,
                   const std::vector<std::pair<int, int> > &l,
                   const std::vector<int> &l2);
void scriptSplitCurve(int edge_id, List_T *vertices,
                      const std::string &fileName);
void scriptBoolean(const std::string &fileName, const std::string &op,
                   const std::vector<std::pair<int, int> > &object,
                   const std::vector<std::pair<int, int> > &tool,
                   int deleteObject, int deleteTool);
void scriptFillet(const std::string &fileName, const std::vector<int> &regions,
                  const std::vector<int> &edges, const std::string &radius);
void scriptCoherence(const std::string &fileName);
void scriptDeleteEntities(const std::string &fileName,
                          const std::vector<std::pair<int, int> > &l,
                          bool recursive);
void scriptSetVisibilityAll(int mode, const std::string &fileName);
void scriptSetVisibility(int mode, const std::vector<std::pair<int, int> > &l,
                         const std::string &fileName);

#endif
