#ifndef _VERIF_H_
#define _VERIF_H_

int alledgeslinked (int ed, List_T * Liste, List_T * old);
int allfaceslinked (int iz, List_T * Liste, List_T * old);

int EntiteEstElleVisible(int iEnt);
void RemplirEntitesVisibles (int add_rem);
void ToutesLesEntitesRelatives(int iEnt, Tree_T *Tree, int add_rem);

#endif
