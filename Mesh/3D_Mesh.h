#ifndef _3D_MESH_H_
#define _3D_MESH_H_

Brick LaBrique (Grid_T * pGrid, double X, double Y, double Z);
void AddSimplexInGrid (Mesh * m, Simplex * s, int boule_boite);
int Coherence (Volume * v, Mesh * m);
void Gamma_Maillage (Volume * v, double *gamma, double *gammamax, double *gammamin);
void Eta_Maillage (Volume * v, double *gamma, double *gammamax, double *gammamin);
void R_Maillage (Volume * v, double *gamma, double *gammamax, double *gammamin);
int Pt_In_Volume (double X, double Y, double Z, Mesh * m,
		  double *l, double tol);
void findminmax (void *a, void *b);
void getminmax (double *xmin, double *ymin, double *zmin,
		double *xmax, double *ymax, double *zmax);
void cut_tetraedre (Intersection * pI, Tree_T * AddedTet, Tree_T * TetDel,
		    Tree_T * newpoints);
void Impression_Resultats (void);
void Restore_Volume (Volume * v);
void Remise_A_Zero (void);

#endif
