#ifndef _ISOSIMPLEX_H_
#define _ISOSIMPLEX_H_

struct Post_View;
void IsoSimplex (Post_View *View, 
		 int preproNormals,
		 double *X, double *Y, double *Z, double *Val,
                 double V, double Vmin, double Vmax,
                 double *Offset, double Raise[3][5], int shade);
#endif
