/* $Id: CrossData.cpp,v 1.2 2000-11-23 14:11:35 geuzaine Exp $ */


#include "Gmsh.h"
#include "Mesh.h"

Tree_T *TreeTemp;

void AddTable (void *data, void *dummy){
  Simplex *s;
  NXE nxe, *pnxe;
  int i;

  s = *(Simplex **) data;

  for (i = 0; i < 4; i++){
    if (s->V[i]){
      nxe.v = s->V[i];
      if ((pnxe = (NXE *) Tree_PQuery (TreeTemp, &nxe))){
	List_Add (pnxe->Liste, &s);
      }
      else{
	nxe.Liste = List_Create (1, 1, sizeof (Simplex *));
	List_Add (nxe.Liste, &s);
	Tree_Add (TreeTemp, &nxe);
      }
    }
  }
}

void create_NXE (Tree_T * TreeAllNod, Tree_T * TreeAllElg,
		 Tree_T * TreeAllNXE){
  TreeTemp = TreeAllNXE;
  Tree_Action (TreeAllElg, AddTable);
}
