#ifndef _VISIBILITY_H_
#define _VISIBILITY_H_

int EntiteEstElleVisible(int iEnt);
void ToutesLesEntitesRelatives(int iEnt, Tree_T *Tree, int add_rem);
void RemplirEntitesVisibles (int add_rem);

extern Tree_T *EntitesVisibles;
extern int     SHOW_ALL_ENTITIES;

#endif
