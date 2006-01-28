// $Id: 3D_Bricks.cpp,v 1.18 2006-01-28 18:44:19 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "Gmsh.h"
#include "Numeric.h"
#include "Mesh.h"

void AddSimplexInGrid(Mesh * m, Simplex * s, int boule_boite)
{
  double XminBox = 0., XmaxBox = 0., YminBox = 0., YmaxBox = 0., ZmaxBox = 0., ZminBox = 0.;
  int Ix1, Ix2, Iy1, Iy2, Iz1, Iz2;
  int i, j, k, index;
  Brick Br, *pBrick;

  if(!m->Grid.init) {
    m->Grid.Bricks =
      List_Create(m->Grid.Nx * m->Grid.Ny * m->Grid.Nz, 10, sizeof(Brick));
    for(i = 0; i < m->Grid.Nx * m->Grid.Ny * m->Grid.Nz; i++) {
      Br.pT = List_Create(2, 2, sizeof(Simplex *));
      Br.N = i + 1;
      List_Add(m->Grid.Bricks, &Br);
    }
    m->Grid.init = 1;
  }

  if(boule_boite == BOITE) {
    XminBox = XmaxBox = s->V[0]->Pos.X;
    YminBox = YmaxBox = s->V[0]->Pos.Y;
    ZminBox = ZmaxBox = s->V[0]->Pos.Z;
    for(i = 1; i < 4; i++) {
      XminBox = DMIN(XminBox, s->V[i]->Pos.X);
      XmaxBox = DMAX(XmaxBox, s->V[i]->Pos.X);
      YminBox = DMIN(YminBox, s->V[i]->Pos.Y);
      YmaxBox = DMAX(YmaxBox, s->V[i]->Pos.Y);
      ZminBox = DMIN(ZminBox, s->V[i]->Pos.Z);
      ZmaxBox = DMAX(ZmaxBox, s->V[i]->Pos.Z);
    }
  }
  else if(boule_boite == BOULE) {
    XminBox = s->Center.X - s->Radius;
    XmaxBox = s->Center.X + s->Radius;
    YminBox = s->Center.Y - s->Radius;
    YmaxBox = s->Center.Y + s->Radius;
    ZminBox = s->Center.Z - s->Radius;
    ZmaxBox = s->Center.Z + s->Radius;
  }


  Ix1 = (int)((double)m->Grid.Nx * (XminBox - m->Grid.min.X) /
              (m->Grid.max.X - m->Grid.min.X));
  Ix2 = (int)((double)m->Grid.Nx * (XmaxBox - m->Grid.min.X) /
              (m->Grid.max.X - m->Grid.min.X));
  Iy1 = (int)((double)m->Grid.Ny * (YminBox - m->Grid.min.Y) /
              (m->Grid.max.Y - m->Grid.min.Y));
  Iy2 = (int)((double)m->Grid.Ny * (YmaxBox - m->Grid.min.Y) /
              (m->Grid.max.Y - m->Grid.min.Y));
  Iz1 = (int)((double)m->Grid.Nz * (ZminBox - m->Grid.min.Z) /
              (m->Grid.max.Z - m->Grid.min.Z));
  Iz2 = (int)((double)m->Grid.Nz * (ZmaxBox - m->Grid.min.Z) /
              (m->Grid.max.Z - m->Grid.min.Z));

  Ix1 = IMAX(Ix1, 0);
  Ix2 = IMIN(Ix2, m->Grid.Nx - 1);
  Iy1 = IMAX(Iy1, 0);
  Iy2 = IMIN(Iy2, m->Grid.Ny - 1);
  Iz1 = IMAX(Iz1, 0);
  Iz2 = IMIN(Iz2, m->Grid.Nz - 1);

  for(i = Ix1; i <= Ix2; i++) {
    for(j = Iy1; j <= Iy2; j++) {
      for(k = Iz1; k <= Iz2; k++) {
        index = i + j * m->Grid.Nx + k * m->Grid.Nx * m->Grid.Ny;
        pBrick = (Brick *) List_Pointer(m->Grid.Bricks, index);
        List_Add(pBrick->pT, &s);
      }
    }
  }

}
