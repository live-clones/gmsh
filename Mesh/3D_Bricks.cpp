/* $Id: 3D_Bricks.cpp,v 1.2 2000-11-23 14:11:34 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Mesh.h"

Brick LaBrique (Grid_T * pGrid, double X, double Y, double Z){
  int Ix, Iy, Iz, index;
  Brick B;

  B.N = -1;
  if (X > pGrid->max.X || X < pGrid->min.X || Y > pGrid->max.Y ||
      Y < pGrid->min.Y || Z > pGrid->max.Z || Z < pGrid->min.Z){
    return (B);
  }

  Ix = (int) ((double) pGrid->Nx * (X - pGrid->min.X) / (pGrid->max.X - pGrid->min.X));
  Iy = (int) ((double) pGrid->Ny * (Y - pGrid->min.Y) / (pGrid->max.Y - pGrid->min.Y));
  Iz = (int) ((double) pGrid->Nz * (Z - pGrid->min.Z) / (pGrid->max.Z - pGrid->min.Z));
  Ix = IMIN (Ix, pGrid->Nx - 1);
  Iy = IMIN (Iy, pGrid->Ny - 1);
  Iz = IMIN (Iz, pGrid->Nz - 1);

  if (Ix < 0)
    Ix = 0;
  if (Iy < 0)
    Iy = 0;
  if (Iz < 0)
    Iz = 0;

  index = Ix + Iy * pGrid->Nx + Iz * pGrid->Nx * pGrid->Ny;
  List_Read (pGrid->Bricks, index, &B);
  return (B);
}


int DEBUT = 0;
Coord MINIM, MAXIM;

void getminmax (double *xmin, double *ymin, double *zmin,
		double *xmax, double *ymax, double *zmax){

  double dx, dy, dz, f;

  dx = MAXIM.X - MINIM.X;
  dy = MAXIM.Y - MINIM.Y;
  dz = MAXIM.Z - MINIM.Z;
  f = .1;

  *xmin = MINIM.X - f * dx;
  *ymin = MINIM.Y - f * dy;
  *zmin = MINIM.Z - f * dz;
  *xmax = MAXIM.X + f * dx;
  *ymax = MAXIM.Y + f * dy;
  *zmax = MAXIM.Z + f * dz;
}

void findminmax (void *a, void *b){

  Vertex *v;
  v = *(Vertex **) a;

  if (!DEBUT){
    MINIM.X = DMIN (MINIM.X, v->Pos.X);
    MAXIM.X = DMAX (MAXIM.X, v->Pos.X);
    MINIM.Y = DMIN (MINIM.Y, v->Pos.Y);
    MAXIM.Y = DMAX (MAXIM.Y, v->Pos.Y);
    MINIM.Z = DMIN (MINIM.Z, v->Pos.Z);
    MAXIM.Z = DMAX (MAXIM.Z, v->Pos.Z);
  }
  else{
    DEBUT = 0;
    MINIM.X = v->Pos.X;
    MAXIM.X = v->Pos.X;
    MINIM.Y = v->Pos.Y;
    MAXIM.Y = v->Pos.Y;
    MINIM.Z = v->Pos.Z;
    MAXIM.Z = v->Pos.Z;
  }
}


void AddSimplexInGrid (Mesh * m, Simplex * s, int boule_boite){

  double XminBox, XmaxBox, YminBox, YmaxBox, ZmaxBox, ZminBox;
  int Ix1, Ix2, Iy1, Iy2, Iz1, Iz2;
  int i, j, k, index;
  Brick Br, *pBrick;

  if (!m->Grid.init){
    m->Grid.Bricks = List_Create (m->Grid.Nx * m->Grid.Ny * m->Grid.Nz, 10, sizeof (Brick));
    for (i = 0; i < m->Grid.Nx * m->Grid.Ny * m->Grid.Nz; i++){
      Br.pT = List_Create (2, 2, sizeof (Simplex *));
      Br.N = i + 1;
      List_Add (m->Grid.Bricks, &Br);
    }
    m->Grid.init = 1;
  }
  
  if (boule_boite == BOITE){
    XminBox = XmaxBox = s->V[0]->Pos.X;
    YminBox = YmaxBox = s->V[0]->Pos.Y;
    ZminBox = ZmaxBox = s->V[0]->Pos.Z;
    for (i = 1; i < 4; i++){
      XminBox = DMIN (XminBox, s->V[i]->Pos.X);
      XmaxBox = DMAX (XmaxBox, s->V[i]->Pos.X);
      YminBox = DMIN (YminBox, s->V[i]->Pos.Y);
      YmaxBox = DMAX (YmaxBox, s->V[i]->Pos.Y);
      ZminBox = DMIN (ZminBox, s->V[i]->Pos.Z);
      ZmaxBox = DMAX (ZmaxBox, s->V[i]->Pos.Z);
    }
  }
  else if ((boule_boite = BOULE)){
    XminBox = s->Center.X - s->Radius;
    XmaxBox = s->Center.X + s->Radius;
    YminBox = s->Center.Y - s->Radius;
    YmaxBox = s->Center.Y + s->Radius;
    ZminBox = s->Center.Z - s->Radius;
    ZmaxBox = s->Center.Z + s->Radius;
  }
  

  Ix1 = (int) ((double) m->Grid.Nx * (XminBox - m->Grid.min.X) /
	       (m->Grid.max.X - m->Grid.min.X));
  Ix2 = (int) ((double) m->Grid.Nx * (XmaxBox - m->Grid.min.X) /
	       (m->Grid.max.X - m->Grid.min.X));
  Iy1 = (int) ((double) m->Grid.Ny * (YminBox - m->Grid.min.Y) /
	       (m->Grid.max.Y - m->Grid.min.Y));
  Iy2 = (int) ((double) m->Grid.Ny * (YmaxBox - m->Grid.min.Y) /
	       (m->Grid.max.Y - m->Grid.min.Y));
  Iz1 = (int) ((double) m->Grid.Nz * (ZminBox - m->Grid.min.Z) /
	       (m->Grid.max.Z - m->Grid.min.Z));
  Iz2 = (int) ((double) m->Grid.Nz * (ZmaxBox - m->Grid.min.Z) /
	       (m->Grid.max.Z - m->Grid.min.Z));

  Ix1 = IMAX (Ix1, 0);
  Ix2 = IMIN (Ix2, m->Grid.Nx - 1);
  Iy1 = IMAX (Iy1, 0);
  Iy2 = IMIN (Iy2, m->Grid.Ny - 1);
  Iz1 = IMAX (Iz1, 0);
  Iz2 = IMIN (Iz2, m->Grid.Nz - 1);

  for (i = Ix1; i <= Ix2; i++){
    for (j = Iy1; j <= Iy2; j++){
      for (k = Iz1; k <= Iz2; k++){
	index = i + j * m->Grid.Nx + k * m->Grid.Nx * m->Grid.Ny;
	pBrick = (Brick *) List_Pointer (m->Grid.Bricks, index);
	List_Add (pBrick->pT, &s);
      }
    }
  }

}
