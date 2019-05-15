// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMODEL_PARAMETRIZE_H
#define GMODEL_PARAMETRIZE_H

int isTriangulationParametrizable(const std::vector<MTriangle *> &t, int Nmax,
                                  double ar);
int isTriangulationParametrizable(const std::vector<MTriangle *> &t);
void computeEdgeCut(GModel *gm, std::vector<MLine *> &cut,
                    int max_elems_per_cut);
void computeNonManifoldEdges(GModel *gm, std::vector<MLine *> &cut,
                             bool addBoundary);
int parametrizeAllGFace(
  GModel *gm, std::map<MVertex *, std::pair<SVector3, SVector3> > *C = NULL);
void parametrizeAllGEdge(GModel *gm);
int parametrizeGFace(
  discreteFace *gf,
  std::map<MVertex *, std::pair<SVector3, SVector3> > *C = NULL);
HXTStatus computeDiscreteCurvatures(
  GModel *gm, std::map<MVertex *, std::pair<SVector3, SVector3> > &C);

#endif
