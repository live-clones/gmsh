// $Id: CrossData.cpp,v 1.10 2003-03-01 22:36:42 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Gmsh.h"
#include "Mesh.h"

Tree_T *TreeTemp;

NXE::NXE()
{
  v = NULL;
  Liste = NULL;
}

NXE::~NXE()
{
  //  if(Liste)List_Delete(Liste);
}

void Delete_NXE(void *data, void *dummy)
{
  NXE *pnxe = (NXE *) data;
  if(pnxe->Liste)
    List_Delete(pnxe->Liste);
}

void AddTable(void *data, void *dummy)
{
  Simplex *s;
  NXE nxe, *pnxe;
  int i;

  s = *(Simplex **) data;

  for(i = 0; i < 4; i++) {
    if(s->V[i]) {
      nxe.v = s->V[i];
      if((pnxe = (NXE *) Tree_PQuery(TreeTemp, &nxe))) {
        List_Add(pnxe->Liste, &s);
      }
      else {
        nxe.Liste = List_Create(1, 1, sizeof(Simplex *));
        List_Add(nxe.Liste, &s);
        Tree_Add(TreeTemp, &nxe);
      }
    }
  }
}

void create_NXE(Tree_T * TreeAllNod, Tree_T * TreeAllElg, Tree_T * TreeAllNXE)
{
  TreeTemp = TreeAllNXE;
  Tree_Action(TreeAllElg, AddTable);
}

void delete_NXE(Tree_T * TreeAllNXE)
{
  Tree_Action(TreeAllNXE, Delete_NXE);
  Tree_Delete(TreeAllNXE);
}
