// $Id: CrossData.cpp,v 1.5 2001-06-06 21:29:58 remacle Exp $


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

void Delete_NXE (void *data, void *dummy)
{
  NXE *pnxe = (NXE*)data;
  if(pnxe->Liste)List_Delete(pnxe->Liste);
}

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

void delete_NXE (Tree_T * TreeAllNXE){
  Tree_Action (TreeAllNXE, Delete_NXE);
  Tree_Delete (TreeAllNXE);
}
