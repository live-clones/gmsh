#ifndef _GMODEL_PARAMETRIZE_
#define _GMODEL_PARAMETRIZE_

int isTriangulationParametrizable(const std::vector<MTriangle*> &t, int Nmax, double ar);
int  isTriangulationParametrizable  (const std::vector<MTriangle*> &t);
void computeEdgeCut (GModel *gm, std::vector<MLine*> &cut, int max_elems_per_cut);
void computeNonManifoldEdges(GModel *gm, std::vector<MLine*> &cut, bool addBoundary);
int parametrizeAllGFace (GModel *gm);
int parametrizeGFace (discreteFace *gf);


#endif
