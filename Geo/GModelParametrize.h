// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMODEL_PARAMETRIZE_H
#define GMODEL_PARAMETRIZE_H

void classifyFaces(GModel *gm, double angleThreshold, bool includeBoundary,
                   bool forParametrization, double curveAngleThreshold);
void classifyFaces(GModel *gm, double curveAngleThreshold);
void computeEdgeCut(GModel *gm, std::vector<MLine *> &cut,
                    int max_elems_per_cut);
void computeNonManifoldEdges(GModel *gm, std::vector<MLine *> &cut,
                             bool addBoundary);
int computeDiscreteCurvatures(GModel *gm);
bool computeParametrization(const std::vector<MTriangle *> &triangles,
                            std::vector<MVertex *> &nodes,
                            std::vector<SPoint2> &stl_vertices_uv,
                            std::vector<SPoint3> &stl_vertices_xyz,
                            std::vector<int> &stl_triangles);

#endif
